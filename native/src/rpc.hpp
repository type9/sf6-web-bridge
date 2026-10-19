#pragma once

#include <deque>
#include <mutex>
#include <set>
#include <string>

#include <nlohmann/json.hpp>

#include "handles.hpp"
#include "server.hpp"

namespace bridge {

/**
 * The reflection RPC. Requests arrive on the socket thread and are queued;
 * `drain` runs on the game thread (REFramework's UpdateBehavior entry) and
 * is the only place that touches the SDK.
 *
 * Wire shape: `{"id": n, "op": "...", ...params}` →
 * `{"id": n, "ok": true, "result": ...}` or `{"id": n, "ok": false, "error": "..."}`.
 *
 * Every op except `ping` and `hello` requires the connection to have
 * paired with the code the plugin prints at startup.
 */
class Rpc {
public:
    void init(const std::string& data_dir);

    void enqueue(Request r);
    void on_close(const std::string& conn);

    /** Game thread. Handles up to `budget` requests. */
    void drain(Server& server, size_t budget = 64);

    const std::string& pairing_code() const { return m_code; }

private:
    nlohmann::json handle(const Request& r);
    nlohmann::json dispatch(const std::string& op, const nlohmann::json& p);

    // ops
    nlohmann::json op_ping();
    nlohmann::json op_singleton_get(const nlohmann::json& p);
    nlohmann::json op_singletons_list();
    nlohmann::json op_type_find(const nlohmann::json& p);
    nlohmann::json op_type_search(const nlohmann::json& p);
    nlohmann::json op_object_describe(const nlohmann::json& p);
    nlohmann::json op_field_get(const nlohmann::json& p);
    nlohmann::json op_field_set(const nlohmann::json& p);
    nlohmann::json op_method_call(const nlohmann::json& p);
    nlohmann::json op_array_len(const nlohmann::json& p);
    nlohmann::json op_array_get(const nlohmann::json& p);
    nlohmann::json op_array_set(const nlohmann::json& p);
    nlohmann::json op_array_create(const nlohmann::json& p);
    nlohmann::json op_mem_peek(const nlohmann::json& p);
    nlohmann::json op_handle_release(const nlohmann::json& p);
    nlohmann::json op_training_summary();

    // helpers
    const Handle& need_handle(const nlohmann::json& p, const char* key = "h");
    reframework::API::TypeDefinition* type_of(const Handle& h) const;
    nlohmann::json ref(void* obj);
    nlohmann::json ref_valuetype(void* storage, reframework::API::TypeDefinition* t);
    nlohmann::json read_slot(const void* p, reframework::API::TypeDefinition* t);
    nlohmann::json field_get(const Handle& h, const std::string& name);
    reframework::InvokeRet invoke(const Handle& h, const std::string& method, const nlohmann::json& args,
        reframework::API::Method** out_method);
    nlohmann::json array_element_type(const Handle& h, reframework::API::TypeDefinition** out);

    std::mutex m_mtx{};
    std::deque<Request> m_queue{};
    std::set<std::string> m_paired{};
    std::string m_current_conn{};
    HandleTable m_handles{};
    std::string m_code{};
    std::string m_data_dir{};
};

} // namespace bridge
