#pragma once

#include <chrono>
#include <cstdint>
#include <deque>
#include <mutex>
#include <optional>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>
#include <reframework/API.hpp>

namespace bridge::trace {

using json = nlohmann::json;
using API = reframework::API;

/** Fixed number of hookable methods: the SDK hook callbacks carry no user data, so each slot has its own static trampoline. */
constexpr int MAX_SLOTS = 16;
/** Recorded calls kept between drains; oldest dropped first. */
constexpr size_t RING_CAPACITY = 512;
/** Managed strings are truncated to this many UTF-16 units when recorded. */
constexpr size_t MAX_STRING_CHARS = 256;

/**
 * One recorded argument (or return value). `Obj` carries one reference
 * taken inside the hook so the object survives until `hook.drain` turns
 * it into a client handle; `Ptr` is a raw pointer-sized slot we could not
 * (or chose not to) interpret.
 */
struct Slot {
    enum class What { None, Value, Str, Obj, Ptr, Err };
    int i{-1}; // argv index; -1 for the return value
    std::string type{}; // declared type (from arg_tys when present)
    What what{What::None};
    json value{}; // Value: primitive; Str: string or null
    std::string text{}; // Err: message
    uint64_t ptr{}; // Obj / Ptr: raw slot bits
    void* obj{}; // Obj: referenced managed object
    API::TypeDefinition* obj_type{}; // Obj: runtime type
    std::string obj_type_name{};
};

struct Call {
    uint64_t seq{};
    double t{}; // ms since plugin start
    uint32_t id{};
    uint32_t thread{};
    std::string type{};
    std::string method{};
    std::vector<Slot> args{};
    std::optional<Slot> ret{};
};

/**
 * Method-call tracer. `hook.add` installs a pre + post hook through the
 * SDK on a free slot; the hooks record argv / the return value into a ring
 * buffer that `hook.drain` empties on the game thread. Hooks may fire on
 * any thread, so every member is guarded by one mutex. Nothing in here
 * throws from a hook: errors become `Err` slots.
 */
class Tracer {
public:
    struct Added {
        uint32_t id{};
        int slot{};
    };

    void init();

    Added add(API::TypeDefinition* t, API::Method* m, const std::string& type_name);
    void remove(uint32_t id);
    json list();

    /** Returns and clears the recorded calls (oldest first, at most RING_CAPACITY). */
    std::vector<Call> drain();

    /** Referenced objects that fell out of the ring before a drain; the caller releases them on the game thread. */
    std::vector<void*> take_orphans();

    // Called from the static trampolines.
    int on_pre(int slot, int argc, void** argv, REFrameworkTypeDefinitionHandle* arg_tys);
    void on_post(int slot, void** ret_val, REFrameworkTypeDefinitionHandle ret_ty);

private:
    struct HookSlot {
        bool used{};
        uint32_t id{};
        API::Method* method{};
        unsigned int hook_id{};
        bool is_static{};
        std::string type_name{};
        std::string method_name{};
        API::TypeDefinition* declaring_type{};
        API::TypeDefinition* return_type{};
        std::vector<API::TypeDefinition*> param_types{};
    };

    Slot record(int i, const void* storage, API::TypeDefinition* t, bool as_object);
    void push(Call&& c);
    double now_ms() const;

    std::mutex m_mtx{};
    HookSlot m_slots[MAX_SLOTS]{};
    std::deque<Call> m_ring{};
    std::vector<void*> m_orphans{};
    uint64_t m_seq{};
    uint32_t m_next_id{1};
    std::chrono::steady_clock::time_point m_start{};
};

Tracer& tracer();

} // namespace bridge::trace
