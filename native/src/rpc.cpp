#include "rpc.hpp"

#include <algorithm>
#include <cctype>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <random>
#include <stdexcept>

#include "values.hpp"

namespace bridge {

using json = nlohmann::json;
using API = reframework::API;
using values::Kind;

namespace {

/** Pairing codes avoid look-alike characters. */
constexpr std::string_view CODE_ALPHABET = "BCDFGHJKMNPQRSTVWXYZ23456789";
constexpr size_t CODE_LENGTH = 6;
constexpr size_t MAX_ARRAY_READ = 100000;
constexpr size_t MAX_PEEK = 4096;
constexpr size_t MAX_TYPE_SEARCH_RESULTS = 500;

std::string make_code() {
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<size_t> pick{0, CODE_ALPHABET.size() - 1};
    std::string code;
    for (size_t i = 0; i < CODE_LENGTH; i++) {
        code.push_back(CODE_ALPHABET[pick(gen)]);
    }
    return code;
}

uint32_t handle_id(const json& p, const char* key) {
    const auto it = p.find(key);
    if (it == p.end() || !it->is_number_unsigned()) {
        throw std::runtime_error(std::string{"missing handle `"} + key + "`");
    }
    return it->get<uint32_t>();
}

std::string need_string(const json& p, const char* key) {
    const auto it = p.find(key);
    if (it == p.end() || !it->is_string()) {
        throw std::runtime_error(std::string{"missing string `"} + key + "`");
    }
    return it->get<std::string>();
}

bool ends_with(const std::string& s, std::string_view suffix) {
    return s.size() >= suffix.size() && s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0;
}

} // namespace

// ── lifecycle ────────────────────────────────────────────────────────────

void Rpc::init(const std::string& data_dir) {
    m_data_dir = data_dir;
    m_code = make_code();

    // The code is also written next to the plugin's data so a launcher or
    // the player can read it without opening the log.
    std::error_code ec;
    std::filesystem::create_directories(m_data_dir, ec);
    if (std::ofstream f{m_data_dir + "/pairing.txt", std::ios::trunc}; f) {
        f << m_code << "\n";
    }
}

void Rpc::enqueue(Request r) {
    std::lock_guard lock{m_mtx};
    m_queue.push_back(std::move(r));
}

void Rpc::on_close(const std::string& conn) {
    std::lock_guard lock{m_mtx};
    m_paired.erase(conn);
}

void Rpc::drain(Server& server, size_t budget) {
    for (size_t n = 0; n < budget; n++) {
        Request r;
        {
            std::lock_guard lock{m_mtx};
            if (m_queue.empty()) {
                return;
            }
            r = std::move(m_queue.front());
            m_queue.pop_front();
        }
        server.send(r.ws, handle(r).dump());
    }
}

json Rpc::handle(const Request& r) {
    json out = json::object();
    if (const auto it = r.body.find("id"); it != r.body.end()) {
        out["id"] = *it;
    }
    try {
        const auto op = need_string(r.body, "op");
        bool paired;
        {
            std::lock_guard lock{m_mtx};
            paired = m_paired.count(r.conn) > 0;
        }
        if (op == "hello") {
            const auto code = need_string(r.body, "code");
            if (code != m_code) {
                throw std::runtime_error("wrong pairing code");
            }
            std::lock_guard lock{m_mtx};
            m_paired.insert(r.conn);
            out["ok"] = true;
            out["result"] = json{{"paired", true}};
            return out;
        }
        if (op != "ping" && !paired) {
            throw std::runtime_error("not paired: send {op:'hello', code} first");
        }
        m_current_conn = r.conn;
        out["ok"] = true;
        out["result"] = dispatch(op, r.body);
    } catch (const std::exception& e) {
        out["ok"] = false;
        out["error"] = e.what();
    }
    return out;
}

json Rpc::dispatch(const std::string& op, const json& p) {
    if (op == "ping") return op_ping();
    if (op == "singleton.get") return op_singleton_get(p);
    if (op == "singletons.list") return op_singletons_list();
    if (op == "type.find") return op_type_find(p);
    if (op == "type.search") return op_type_search(p);
    if (op == "object.describe") return op_object_describe(p);
    if (op == "field.get") return op_field_get(p);
    if (op == "field.set") return op_field_set(p);
    if (op == "method.call") return op_method_call(p);
    if (op == "array.len") return op_array_len(p);
    if (op == "array.get") return op_array_get(p);
    if (op == "array.set") return op_array_set(p);
    if (op == "array.create") return op_array_create(p);
    if (op == "mem.peek") return op_mem_peek(p);
    if (op == "handle.release") return op_handle_release(p);
    if (op == "training.summary") return op_training_summary();
    throw std::runtime_error("unknown op: " + op);
}

// ── helpers ──────────────────────────────────────────────────────────────

const Handle& Rpc::need_handle(const json& p, const char* key) {
    const auto id = handle_id(p, key);
    const auto h = m_handles.get(id);
    if (h == nullptr) {
        throw std::runtime_error("unknown handle " + std::to_string(id));
    }
    return *h;
}

API::TypeDefinition* Rpc::type_of(const Handle& h) const {
    if (h.managed) {
        return static_cast<API::ManagedObject*>(h.ptr)->get_type_definition();
    }
    return h.type;
}

json Rpc::ref(void* obj) {
    if (obj == nullptr) {
        return nullptr;
    }
    const auto mo = static_cast<API::ManagedObject*>(obj);
    const auto t = mo->get_type_definition();
    const auto id = m_handles.put(obj, t, true);
    return json{{"h", id}, {"type", t != nullptr ? t->get_full_name() : "?"}};
}

json Rpc::ref_valuetype(void* storage, API::TypeDefinition* t) {
    const auto id = m_handles.put(storage, t, false);
    return json{{"h", id}, {"type", t != nullptr ? t->get_full_name() : "?"}, {"vt", true}};
}

json Rpc::read_slot(const void* p, API::TypeDefinition* t) {
    const auto k = values::kind_of(t);
    if (values::is_primitive(k)) {
        return values::read_at(p, k);
    }
    switch (k) {
    case Kind::String: {
        void* s{};
        std::memcpy(&s, p, sizeof(s));
        return s == nullptr ? json(nullptr) : json(values::read_managed_string(s));
    }
    case Kind::Object: {
        void* o{};
        std::memcpy(&o, p, sizeof(o));
        return ref(o);
    }
    case Kind::ValueType:
        return ref_valuetype(const_cast<void*>(p), t);
    default:
        return nullptr;
    }
}

json Rpc::field_get(const Handle& h, const std::string& name) {
    const auto t = type_of(h);
    if (t == nullptr) {
        throw std::runtime_error("handle has no type");
    }
    const auto f = t->find_field(name);
    if (f == nullptr) {
        throw std::runtime_error("no field `" + name + "` on " + t->get_full_name());
    }
    const auto owner = f->is_static() ? nullptr : h.ptr;
    if (!f->is_static() && owner == nullptr) {
        throw std::runtime_error("instance field on a type-only handle");
    }
    const auto p = f->get_data_raw(owner, !h.managed && owner != nullptr);
    if (p == nullptr) {
        throw std::runtime_error("field `" + name + "` has no storage");
    }
    return read_slot(p, f->get_type());
}

reframework::InvokeRet Rpc::invoke(const Handle& h, const std::string& method, const json& args, API::Method** out_method) {
    const auto t = type_of(h);
    if (t == nullptr) {
        throw std::runtime_error("handle has no type");
    }
    const auto m = t->find_method(method);
    if (m == nullptr) {
        throw std::runtime_error("no method `" + method + "` on " + t->get_full_name());
    }
    const auto params = m->get_params();
    const auto arg_list = args.is_array() ? args : json::array();
    if (params.size() != arg_list.size()) {
        throw std::runtime_error("`" + method + "` takes " + std::to_string(params.size()) + " argument(s), got " +
            std::to_string(arg_list.size()));
    }
    std::vector<void*> packed(params.size(), nullptr);
    for (size_t i = 0; i < params.size(); i++) {
        const auto pt = reinterpret_cast<API::TypeDefinition*>(params[i].t);
        const auto k = values::kind_of(pt);
        const auto& a = arg_list[i];
        if (values::is_primitive(k)) {
            if (!values::pack_arg(packed[i], k, a)) {
                throw std::runtime_error("argument " + std::to_string(i) + " does not fit " + pt->get_full_name());
            }
        } else if (k == Kind::String) {
            if (a.is_null()) {
                packed[i] = nullptr;
            } else if (a.is_string()) {
                packed[i] = API::get()->sdk()->functions->create_managed_string(values::to_wide(a.get<std::string>()).c_str());
            } else {
                throw std::runtime_error("argument " + std::to_string(i) + " must be a string");
            }
        } else {
            // Object or value type: null or a handle.
            if (a.is_null()) {
                packed[i] = nullptr;
            } else if (a.is_object() && a.contains("h")) {
                packed[i] = need_handle(a, "h").ptr;
            } else {
                throw std::runtime_error("argument " + std::to_string(i) + " must be null or {h}");
            }
        }
    }
    const auto self = m->is_static() ? nullptr : static_cast<API::ManagedObject*>(h.ptr);
    if (out_method != nullptr) {
        *out_method = m;
    }
    auto ret = m->invoke(self, packed);
    if (ret.exception_thrown) {
        throw std::runtime_error("game threw inside `" + method + "`");
    }
    return ret;
}

json Rpc::array_element_type(const Handle& h, API::TypeDefinition** out) {
    const auto t = type_of(h);
    if (t == nullptr) {
        throw std::runtime_error("handle has no type");
    }
    const auto name = t->get_full_name();
    if (!ends_with(name, "[]")) {
        throw std::runtime_error(name + " is not an array");
    }
    const auto elem = API::get()->tdb()->find_type(name.substr(0, name.size() - 2));
    if (elem == nullptr) {
        throw std::runtime_error("element type of " + name + " not found");
    }
    *out = elem;
    return json{{"array", name}, {"element", elem->get_full_name()}};
}

// ── ops ──────────────────────────────────────────────────────────────────

json Rpc::op_ping() {
    const auto& api = API::get();
    bool paired;
    {
        std::lock_guard lock{m_mtx};
        paired = m_paired.count(m_current_conn) > 0;
    }
    return json{
        {"plugin", "sf6-web-bridge"},
        {"version", SF6_WEB_BRIDGE_VERSION},
        {"protocol", 1},
        {"paired", paired},
        {"handles", m_handles.size()},
        {"tdb", json{{"types", api->tdb()->get_num_types()}, {"methods", api->tdb()->get_num_methods()}}},
        {"training", api->get_managed_singleton("app.training.TrainingManager") != nullptr},
    };
}

json Rpc::op_singleton_get(const json& p) {
    const auto name = need_string(p, "name");
    return ref(API::get()->get_managed_singleton(name));
}

json Rpc::op_singletons_list() {
    auto out = json::array();
    for (const auto& s : API::get()->get_managed_singletons()) {
        const auto t = reinterpret_cast<API::TypeDefinition*>(s.t);
        out.push_back(t != nullptr ? t->get_full_name() : "?");
    }
    return out;
}

json Rpc::op_type_find(const json& p) {
    const auto name = need_string(p, "name");
    const auto t = API::get()->tdb()->find_type(name);
    if (t == nullptr) {
        return nullptr;
    }
    // A type-only handle: static fields and static methods work on it.
    const auto id = m_handles.put(nullptr, t, false);
    return json{{"h", id}, {"type", t->get_full_name()}, {"static", true}};
}

/**
 * Case-insensitive substring search over every type name in the type
 * database. The TDB has ~200k types, so the first call takes a moment;
 * results are capped. This is how the UI-flow classes that wrap the CFN
 * endpoints get found.
 */
json Rpc::op_type_search(const json& p) {
    auto needle = need_string(p, "q");
    if (needle.size() < 3) {
        throw std::runtime_error("`q` needs at least 3 characters");
    }
    std::transform(needle.begin(), needle.end(), needle.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    const auto tdb = API::get()->tdb();
    const auto n = tdb->get_num_types();
    auto out = json::array();
    std::string lower;
    for (uint32_t i = 0; i < n && out.size() < MAX_TYPE_SEARCH_RESULTS; i++) {
        const auto t = tdb->get_type(i);
        if (t == nullptr) {
            continue;
        }
        const auto name = t->get_full_name();
        lower.assign(name);
        std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
        if (lower.find(needle) != std::string::npos) {
            out.push_back(name);
        }
    }
    return json{{"q", needle}, {"scanned", n}, {"truncated", out.size() >= MAX_TYPE_SEARCH_RESULTS}, {"types", out}};
}

json Rpc::op_object_describe(const json& p) {
    const auto& h = need_handle(p);
    const auto t = type_of(h);
    if (t == nullptr) {
        throw std::runtime_error("handle has no type");
    }
    auto fields = json::array();
    for (const auto f : t->get_fields()) {
        const auto ft = f->get_type();
        fields.push_back(json{
            {"name", f->get_name()},
            {"type", ft != nullptr ? ft->get_full_name() : "?"},
            {"static", f->is_static()},
            {"offset", f->get_offset_from_base()},
        });
    }
    auto methods = json::array();
    for (const auto m : t->get_methods()) {
        auto params = json::array();
        for (const auto& prm : m->get_params()) {
            const auto pt = reinterpret_cast<API::TypeDefinition*>(prm.t);
            params.push_back(json{{"name", prm.name != nullptr ? prm.name : ""}, {"type", pt != nullptr ? pt->get_full_name() : "?"}});
        }
        const auto rt = m->get_return_type();
        methods.push_back(json{
            {"name", m->get_name()},
            {"returns", rt != nullptr ? rt->get_full_name() : "void"},
            {"static", m->is_static()},
            {"params", params},
        });
    }
    const auto parent = t->get_parent_type();
    return json{
        {"type", t->get_full_name()},
        {"parent", parent != nullptr ? json(parent->get_full_name()) : json(nullptr)},
        {"valuetype", t->is_valuetype()},
        {"size", t->get_size()},
        {"fields", fields},
        {"methods", methods},
    };
}

json Rpc::op_field_get(const json& p) {
    const auto& h = need_handle(p);
    return field_get(h, need_string(p, "name"));
}

json Rpc::op_field_set(const json& p) {
    const auto& h = need_handle(p);
    const auto name = need_string(p, "name");
    const auto t = type_of(h);
    if (t == nullptr) {
        throw std::runtime_error("handle has no type");
    }
    const auto f = t->find_field(name);
    if (f == nullptr) {
        throw std::runtime_error("no field `" + name + "` on " + t->get_full_name());
    }
    const auto k = values::kind_of(f->get_type());
    const auto owner = f->is_static() ? nullptr : h.ptr;
    const auto ptr = f->get_data_raw(owner, !h.managed && owner != nullptr);
    if (ptr == nullptr) {
        throw std::runtime_error("field `" + name + "` has no storage");
    }
    const auto it = p.find("value");
    if (it == p.end()) {
        throw std::runtime_error("missing `value`");
    }
    if (values::is_primitive(k)) {
        if (!values::write_at(ptr, k, *it)) {
            throw std::runtime_error("`value` does not fit " + f->get_type()->get_full_name());
        }
        return values::read_at(ptr, k);
    }
    if (k == Kind::Object) {
        // EXPERIMENTAL. Stores a reference: null or a managed handle. The
        // new referent gets a reference added so the game can keep it;
        // the previous referent is left alone (a leak beats a crash). The
        // drill mod fills empty record slots this way (see FINDINGS).
        void* next = nullptr;
        if (!it->is_null()) {
            if (!(it->is_object() && it->contains("h"))) {
                throw std::runtime_error("`value` must be null or {h} for a reference field");
            }
            const auto& target = need_handle(*it, "h");
            if (!target.managed) {
                throw std::runtime_error("`value` must be a managed object handle");
            }
            next = target.ptr;
            static_cast<API::ManagedObject*>(next)->add_ref();
        }
        std::memcpy(ptr, &next, sizeof(next));
        return it->is_null() ? json(nullptr) : *it;
    }
    throw std::runtime_error("field.set writes primitives, enums and object references only");
}

/**
 * EXPERIMENTAL. Allocate a managed array through the game's own
 * System.Array.CreateInstance(Type, int). The result is pinned with a
 * reference for the life of the process, so it can be stored into a game
 * field and survive the client's handle being released. Plugin API 1.10
 * has no create_managed_array, hence this route.
 */
json Rpc::op_array_create(const json& p) {
    const auto elem = need_string(p, "element");
    const auto length = p.value("length", 0);
    if (length <= 0 || length > (1 << 20)) {
        throw std::runtime_error("`length` must be 1..1048576");
    }
    const auto& api = API::get();
    const auto type_obj = api->sdk()->functions->typeof_(elem.c_str());
    if (type_obj == nullptr) {
        throw std::runtime_error("typeof(" + elem + ") failed");
    }
    const auto array_t = api->tdb()->find_type("System.Array");
    if (array_t == nullptr) {
        throw std::runtime_error("System.Array not found");
    }
    API::Method* m = nullptr;
    for (const auto cand : array_t->get_methods()) {
        if (std::string_view{cand->get_name()} != "CreateInstance" || cand->get_num_params() != 2) {
            continue;
        }
        const auto params = cand->get_params();
        const auto p1 = reinterpret_cast<API::TypeDefinition*>(params[1].t);
        if (p1 != nullptr && p1->get_full_name() == "System.Int32") {
            m = cand;
            break;
        }
    }
    if (m == nullptr) {
        throw std::runtime_error("System.Array.CreateInstance(Type, int) not found");
    }
    std::vector<void*> args{type_obj, nullptr};
    if (!values::pack_arg(args[1], Kind::I32, json(length))) {
        throw std::runtime_error("bad length");
    }
    const auto ret = m->invoke(nullptr, args);
    if (ret.exception_thrown || ret.ptr == nullptr) {
        throw std::runtime_error("CreateInstance threw or returned null");
    }
    const auto arr = static_cast<API::ManagedObject*>(ret.ptr);
    arr->add_ref(); // pinned for the process lifetime
    auto out = ref(arr);
    out["pinned"] = true;
    return out;
}

json Rpc::op_method_call(const json& p) {
    const auto& h = need_handle(p);
    const auto name = need_string(p, "name");
    API::Method* m{};
    const auto ret = invoke(h, name, p.value("args", json::array()), &m);
    const auto rt = m->get_return_type();
    const auto k = values::kind_of(rt);
    if (k == Kind::Void) {
        return nullptr;
    }
    if (values::is_primitive(k)) {
        return values::read_ret(ret, k);
    }
    if (k == Kind::String) {
        return ret.ptr == nullptr ? json(nullptr) : json(values::read_managed_string(ret.ptr));
    }
    if (k == Kind::Object) {
        return ref(ret.ptr);
    }
    // Non-primitive value type: REFramework writes it into the result buffer.
    return json{{"vt", rt->get_full_name()}, {"bytes", values::hex(ret.bytes.data(), std::min<size_t>(rt->get_valuetype_size(), ret.bytes.size()))}};
}

json Rpc::op_array_len(const json& p) {
    const auto& h = need_handle(p);
    API::TypeDefinition* elem{};
    auto info = array_element_type(h, &elem);
    const auto ret = invoke(h, "get_Length", json::array(), nullptr);
    info["length"] = values::read_ret(ret, Kind::I32);
    return info;
}

json Rpc::op_array_get(const json& p) {
    const auto& h = need_handle(p);
    API::TypeDefinition* elem{};
    array_element_type(h, &elem);
    const auto len_ret = invoke(h, "get_Length", json::array(), nullptr);
    const auto length = values::read_ret(len_ret, Kind::I32).get<int32_t>();
    const auto from = p.value("from", 0);
    auto count = p.value("count", length - from);
    if (from < 0 || from > length) {
        throw std::runtime_error("`from` out of range");
    }
    count = std::max(0, std::min(count, length - from));
    if (static_cast<size_t>(count) > MAX_ARRAY_READ) {
        throw std::runtime_error("`count` too large");
    }
    const auto k = values::kind_of(elem);
    auto out = json::array();
    for (int32_t i = from; i < from + count; i++) {
        const auto ret = invoke(h, "Get", json::array({i}), nullptr);
        if (values::is_primitive(k)) {
            out.push_back(values::read_ret(ret, k));
        } else if (k == Kind::String) {
            out.push_back(ret.ptr == nullptr ? json(nullptr) : json(values::read_managed_string(ret.ptr)));
        } else if (k == Kind::Object) {
            out.push_back(ref(ret.ptr));
        } else {
            out.push_back(json{{"bytes", values::hex(ret.bytes.data(), std::min<size_t>(elem->get_valuetype_size(), ret.bytes.size()))}});
        }
    }
    return json{{"from", from}, {"length", length}, {"values", out}};
}

json Rpc::op_array_set(const json& p) {
    const auto& h = need_handle(p);
    API::TypeDefinition* elem{};
    array_element_type(h, &elem);
    const auto k = values::kind_of(elem);
    if (!values::is_primitive(k)) {
        throw std::runtime_error("array.set only writes primitive elements");
    }
    const auto len_ret = invoke(h, "get_Length", json::array(), nullptr);
    const auto length = values::read_ret(len_ret, Kind::I32).get<int32_t>();
    const auto from = p.value("from", 0);
    const auto it = p.find("values");
    if (it == p.end() || !it->is_array()) {
        throw std::runtime_error("missing `values` array");
    }
    if (from < 0 || from + static_cast<int32_t>(it->size()) > length) {
        throw std::runtime_error("write would exceed the array length " + std::to_string(length));
    }
    int32_t i = from;
    for (const auto& v : *it) {
        invoke(h, "Set", json::array({i, v}), nullptr);
        i++;
    }
    return json{{"from", from}, {"written", it->size()}, {"length", length}};
}

json Rpc::op_mem_peek(const json& p) {
    const auto& h = need_handle(p);
    if (h.ptr == nullptr) {
        throw std::runtime_error("type-only handle has no memory");
    }
    const auto size = std::min<size_t>(p.value("size", 64), MAX_PEEK);
    return json{{"bytes", values::hex(h.ptr, size)}};
}

json Rpc::op_handle_release(const json& p) {
    m_handles.release(handle_id(p, "h"));
    return json{{"handles", m_handles.size()}};
}

/**
 * Convenience read of what a drill needs to know up front, using the
 * same field names the community Lua mod uses. Any step that is missing
 * yields null rather than an error so the summary still says how far the
 * walk got on a given game build.
 */
json Rpc::op_training_summary() {
    json out{{"inTraining", false}, {"p1FighterId", nullptr}, {"p2FighterId", nullptr}, {"recordFighterCount", nullptr}};
    const auto tm = API::get()->get_managed_singleton("app.training.TrainingManager");
    if (tm == nullptr) {
        return out;
    }
    out["inTraining"] = true;
    const Handle tm_h{tm, tm->get_type_definition(), true};
    const auto tdata = field_get(tm_h, "_tData");
    if (!tdata.is_object()) {
        return out;
    }
    const auto& td = need_handle(tdata, "h");
    const auto menu = field_get(td, "SelectMenu");
    if (menu.is_object()) {
        const auto& menu_h = need_handle(menu, "h");
        const auto pdatas = field_get(menu_h, "PlayerDatas");
        if (pdatas.is_object()) {
            const auto& pd_h = need_handle(pdatas, "h");
            const char* keys[2] = {"p1FighterId", "p2FighterId"};
            for (int i = 0; i < 2; i++) {
                try {
                    const auto item_ret = invoke(pd_h, "get_Item", json::array({i}), nullptr);
                    if (item_ret.ptr != nullptr) {
                        const Handle item{item_ret.ptr, static_cast<API::ManagedObject*>(item_ret.ptr)->get_type_definition(), true};
                        out[keys[i]] = field_get(item, "FighterID");
                    }
                } catch (const std::exception& e) {
                    out[keys[i]] = json{{"error", e.what()}};
                }
            }
        }
    }
    const auto rec = field_get(td, "RecordSetting");
    if (rec.is_object()) {
        const auto& rec_h = need_handle(rec, "h");
        const auto fdl = field_get(rec_h, "FighterDataList");
        if (fdl.is_object()) {
            const auto& fdl_h = need_handle(fdl, "h");
            try {
                const auto n = invoke(fdl_h, "get_Count", json::array(), nullptr);
                out["recordFighterCount"] = values::read_ret(n, Kind::I32);
            } catch (const std::exception&) {
                try {
                    const auto n = invoke(fdl_h, "get_Length", json::array(), nullptr);
                    out["recordFighterCount"] = values::read_ret(n, Kind::I32);
                } catch (const std::exception& e) {
                    out["recordFighterCount"] = json{{"error", e.what()}};
                }
            }
        }
        out["recordSetting"] = rec;
    }
    out["trainingData"] = tdata;
    return out;
}

} // namespace bridge
