#include "trace.hpp"

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <utility>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "values.hpp"

namespace bridge::trace {

using values::Kind;

namespace {

/**
 * Copy `n` bytes from game memory without faulting the game if the
 * pointer is garbage. SEH, so this function holds no C++ objects.
 */
#ifdef _WIN32
bool safe_read(const void* src, void* dst, size_t n) {
    __try {
        std::memcpy(dst, src, n);
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}
#else
bool safe_read(const void* src, void* dst, size_t n) {
    std::memcpy(dst, src, n);
    return true;
}
#endif

uint32_t current_thread() {
#ifdef _WIN32
    return static_cast<uint32_t>(GetCurrentThreadId());
#else
    return 0;
#endif
}

/** A pointer that could be a managed object: aligned, user-space, and its header readable. */
bool plausible_object(uint64_t p) {
    if (p < 0x10000 || p > 0x7fffffffffffull || (p & 7) != 0) {
        return false;
    }
    uint8_t header[16];
    return safe_read(reinterpret_cast<const void*>(static_cast<uintptr_t>(p)), header, sizeof(header));
}

/** System.String with the same layout values::read_managed_string assumes, capped and fault-safe. */
json read_string_capped(uint64_t p) {
    if (!plausible_object(p)) {
        return nullptr;
    }
    const auto base = reinterpret_cast<const uint8_t*>(static_cast<uintptr_t>(p));
    int32_t len = 0;
    if (!safe_read(base + 0x10, &len, sizeof(len))) {
        return nullptr;
    }
    if (len <= 0 || len > (1 << 20)) {
        return len == 0 ? json("") : json(nullptr);
    }
    const auto take = static_cast<size_t>(len) < MAX_STRING_CHARS ? static_cast<size_t>(len) : MAX_STRING_CHARS;
    std::vector<char16_t> buf(take);
    if (!safe_read(base + 0x14, buf.data(), take * sizeof(char16_t))) {
        return nullptr;
    }
    std::string out;
#ifdef _WIN32
    const auto wide = reinterpret_cast<const wchar_t*>(buf.data());
    const int need = WideCharToMultiByte(CP_UTF8, 0, wide, static_cast<int>(take), nullptr, 0, nullptr, nullptr);
    out.assign(static_cast<size_t>(need), '\0');
    WideCharToMultiByte(CP_UTF8, 0, wide, static_cast<int>(take), out.data(), need, nullptr, nullptr);
#else
    for (size_t i = 0; i < take; i++) {
        out.push_back(static_cast<char>(buf[i] & 0x7f));
    }
#endif
    if (static_cast<size_t>(len) > take) {
        out += "...";
    }
    return out;
}

std::string type_name_of(API::TypeDefinition* t) {
    return t != nullptr ? t->get_full_name() : std::string{"?"};
}

// ── per-slot trampolines ─────────────────────────────────────────────────
// The SDK hook callbacks carry no user data, so each slot gets its own
// function that knows its index.

template <int N>
int pre_trampoline(int argc, void** argv, REFrameworkTypeDefinitionHandle* arg_tys, unsigned long long) {
    return tracer().on_pre(N, argc, argv, arg_tys);
}

template <int N>
void post_trampoline(void** ret_val, REFrameworkTypeDefinitionHandle ret_ty, unsigned long long) {
    tracer().on_post(N, ret_val, ret_ty);
}

template <int... I>
constexpr std::array<REFPreHookFn, sizeof...(I)> make_pre_table(std::integer_sequence<int, I...>) {
    return {{&pre_trampoline<I>...}};
}

template <int... I>
constexpr std::array<REFPostHookFn, sizeof...(I)> make_post_table(std::integer_sequence<int, I...>) {
    return {{&post_trampoline<I>...}};
}

const auto PRE_TABLE = make_pre_table(std::make_integer_sequence<int, MAX_SLOTS>{});
const auto POST_TABLE = make_post_table(std::make_integer_sequence<int, MAX_SLOTS>{});

} // namespace

Tracer& tracer() {
    static Tracer t;
    return t;
}

// ── management (game thread, via RPC) ────────────────────────────────────

void Tracer::init() {
    std::lock_guard lock{m_mtx};
    m_start = std::chrono::steady_clock::now();
}

double Tracer::now_ms() const {
    const auto d = std::chrono::steady_clock::now() - m_start;
    return std::chrono::duration<double, std::milli>(d).count();
}

Tracer::Added Tracer::add(API::TypeDefinition* t, API::Method* m, const std::string& type_name) {
    std::lock_guard lock{m_mtx};
    int free = -1;
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (m_slots[i].used && m_slots[i].method == m) {
            throw std::runtime_error("already hooked as id " + std::to_string(m_slots[i].id));
        }
        if (!m_slots[i].used && free < 0) {
            free = i;
        }
    }
    if (free < 0) {
        throw std::runtime_error("all " + std::to_string(MAX_SLOTS) + " hook slots are in use; hook.remove one first");
    }
    auto& s = m_slots[free];
    s = HookSlot{};
    s.id = m_next_id++;
    s.method = m;
    s.is_static = m->is_static();
    s.type_name = type_name;
    s.method_name = m->get_name() != nullptr ? m->get_name() : "?";
    s.declaring_type = m->get_declaring_type() != nullptr ? m->get_declaring_type() : t;
    s.return_type = m->get_return_type();
    for (const auto& prm : m->get_params()) {
        s.param_types.push_back(reinterpret_cast<API::TypeDefinition*>(prm.t));
    }
    // Mark used before installing: the hook can fire as soon as add_hook returns.
    s.used = true;
    s.hook_id = m->add_hook(PRE_TABLE[static_cast<size_t>(free)], POST_TABLE[static_cast<size_t>(free)], false);
    return Added{s.id, free};
}

void Tracer::remove(uint32_t id) {
    std::lock_guard lock{m_mtx};
    for (auto& s : m_slots) {
        if (s.used && s.id == id) {
            s.method->remove_hook(s.hook_id);
            s = HookSlot{};
            return;
        }
    }
    throw std::runtime_error("unknown hook id " + std::to_string(id));
}

json Tracer::list() {
    std::lock_guard lock{m_mtx};
    auto out = json::array();
    for (int i = 0; i < MAX_SLOTS; i++) {
        const auto& s = m_slots[i];
        if (s.used) {
            out.push_back(json{{"id", s.id}, {"type", s.type_name}, {"method", s.method_name}, {"slot", i}});
        }
    }
    return out;
}

std::vector<Call> Tracer::drain() {
    std::lock_guard lock{m_mtx};
    std::vector<Call> out;
    out.reserve(m_ring.size());
    while (!m_ring.empty()) {
        out.push_back(std::move(m_ring.front()));
        m_ring.pop_front();
    }
    return out;
}

std::vector<void*> Tracer::take_orphans() {
    std::lock_guard lock{m_mtx};
    return std::exchange(m_orphans, {});
}

// ── recording (any thread, inside the game's call) ───────────────────────

void Tracer::push(Call&& c) {
    // Caller holds m_mtx.
    while (m_ring.size() >= RING_CAPACITY) {
        auto& old = m_ring.front();
        for (auto& a : old.args) {
            if (a.what == Slot::What::Obj && a.obj != nullptr) {
                m_orphans.push_back(a.obj);
            }
        }
        if (old.ret && old.ret->what == Slot::What::Obj && old.ret->obj != nullptr) {
            m_orphans.push_back(old.ret->obj);
        }
        m_ring.pop_front();
    }
    m_ring.push_back(std::move(c));
}

/**
 * Interpret one pointer-sized slot. `storage` points at the slot itself
 * (the 8 bytes REFramework handed us), never at what it references.
 * Primitives live inline; strings and objects are pointers; anything else
 * is kept as raw bits.
 */
Slot Tracer::record(int i, const void* storage, API::TypeDefinition* t, bool as_object) {
    Slot s;
    s.i = i;
    s.type = type_name_of(t);
    uint64_t bits = 0;
    if (!safe_read(storage, &bits, sizeof(bits))) {
        s.what = Slot::What::Err;
        s.text = "slot unreadable";
        return s;
    }
    s.ptr = bits;
    const auto k = as_object ? Kind::Object : values::kind_of(t);
    if (values::is_primitive(k)) {
        s.what = Slot::What::Value;
        s.value = values::read_at(&bits, k);
        return s;
    }
    switch (k) {
    case Kind::String:
        s.what = Slot::What::Str;
        s.value = bits == 0 ? json(nullptr) : read_string_capped(bits);
        return s;
    case Kind::Object: {
        if (bits == 0) {
            s.what = Slot::What::Value;
            s.value = nullptr;
            return s;
        }
        if (!plausible_object(bits)) {
            s.what = Slot::What::Ptr;
            return s;
        }
        const auto mo = reinterpret_cast<API::ManagedObject*>(static_cast<uintptr_t>(bits));
        const auto rt = mo->get_type_definition();
        if (rt == nullptr) {
            s.what = Slot::What::Ptr;
            return s;
        }
        mo->add_ref();
        s.what = Slot::What::Obj;
        s.obj = mo;
        s.obj_type = rt;
        s.obj_type_name = rt->get_full_name();
        return s;
    }
    default:
        // Void (unknown type), inline value types (possibly passed by pointer), anything else.
        s.what = Slot::What::Ptr;
        return s;
    }
}

int Tracer::on_pre(int slot, int argc, void** argv, REFrameworkTypeDefinitionHandle* arg_tys) {
    try {
        std::lock_guard lock{m_mtx};
        if (slot < 0 || slot >= MAX_SLOTS || !m_slots[slot].used) {
            return REFRAMEWORK_HOOK_CALL_ORIGINAL;
        }
        const auto& hs = m_slots[slot];
        Call c;
        c.seq = m_seq++;
        c.t = now_ms();
        c.id = hs.id;
        c.thread = current_thread();
        c.type = hs.type_name;
        c.method = hs.method_name;
        // REFramework (HookManager.cpp) lays argv out as [thread context,
        // this, declared params..., two hidden scratch slots], but arg_tys
        // holds ONLY the declared parameter types (fn->get_param_types()).
        // So arg_tys is indexed by i - 2, never by i, and the hidden slots
        // past the declared parameters are skipped.
        const auto num_params = static_cast<int>(hs.param_types.size());
        const auto last = std::min(argc, 2 + num_params);
        for (int i = 0; i < last && argv != nullptr; i++) {
            try {
                API::TypeDefinition* t = nullptr;
                if (i >= 2 && arg_tys != nullptr) {
                    t = reinterpret_cast<API::TypeDefinition*>(arg_tys[i - 2]);
                }
                bool as_object = false;
                if (i == 0) {
                    Slot s;
                    s.i = 0;
                    s.type = "ctx";
                    s.what = Slot::What::Ptr;
                    safe_read(&argv[0], &s.ptr, sizeof(s.ptr));
                    c.args.push_back(std::move(s));
                    continue;
                }
                if (i == 1) {
                    if (hs.is_static) {
                        Slot s;
                        s.i = 1;
                        s.type = "this(static)";
                        s.what = Slot::What::Ptr;
                        safe_read(&argv[1], &s.ptr, sizeof(s.ptr));
                        c.args.push_back(std::move(s));
                        continue;
                    }
                    if (t == nullptr) {
                        t = hs.declaring_type;
                    }
                    as_object = true;
                } else if (t == nullptr) {
                    const auto pi = static_cast<size_t>(i - 2);
                    if (pi < hs.param_types.size()) {
                        t = hs.param_types[pi];
                    }
                }
                c.args.push_back(record(i, &argv[i], t, as_object));
            } catch (const std::exception& e) {
                Slot s;
                s.i = i;
                s.what = Slot::What::Err;
                s.text = e.what();
                c.args.push_back(std::move(s));
            } catch (...) {
                Slot s;
                s.i = i;
                s.what = Slot::What::Err;
                s.text = "unknown error";
                c.args.push_back(std::move(s));
            }
        }
        push(std::move(c));
    } catch (...) {
        // Never let the tracer take the game down.
    }
    return REFRAMEWORK_HOOK_CALL_ORIGINAL;
}

void Tracer::on_post(int slot, void** ret_val, REFrameworkTypeDefinitionHandle ret_ty) {
    try {
        std::lock_guard lock{m_mtx};
        if (slot < 0 || slot >= MAX_SLOTS || !m_slots[slot].used || ret_val == nullptr) {
            return;
        }
        const auto& hs = m_slots[slot];
        auto t = reinterpret_cast<API::TypeDefinition*>(ret_ty);
        if (t == nullptr) {
            t = hs.return_type;
        }
        if (values::kind_of(t) == Kind::Void) {
            return;
        }
        // Pair with the newest unfinished call of this hook on this thread.
        const auto thread = current_thread();
        for (auto it = m_ring.rbegin(); it != m_ring.rend(); ++it) {
            if (it->id == hs.id && it->thread == thread && !it->ret) {
                Slot s;
                try {
                    s = record(-1, ret_val, t, false);
                } catch (const std::exception& e) {
                    s.what = Slot::What::Err;
                    s.text = e.what();
                } catch (...) {
                    s.what = Slot::What::Err;
                    s.text = "unknown error";
                }
                it->ret = std::move(s);
                return;
            }
        }
    } catch (...) {
    }
}

} // namespace bridge::trace
