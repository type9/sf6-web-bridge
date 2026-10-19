#pragma once

#include <cstdint>
#include <unordered_map>

#include <reframework/API.hpp>

namespace bridge {

/**
 * A client-visible reference to something inside the game. Two kinds:
 *   - a managed object (heap object with a runtime type); we hold a
 *     reference on it so the GC cannot free it while a client has the
 *     handle
 *   - inline value-type storage (a struct living inside another object,
 *     e.g. a System.Guid field); no reference to hold, the pointer stays
 *     valid as long as its owner does
 */
struct Handle {
    void* ptr{};
    reframework::API::TypeDefinition* type{};
    bool managed{};
};

class HandleTable {
public:
    uint32_t put(void* ptr, reframework::API::TypeDefinition* type, bool managed) {
        if (managed) {
            static_cast<reframework::API::ManagedObject*>(ptr)->add_ref();
        }
        const auto id = m_next++;
        m_handles.emplace(id, Handle{ptr, type, managed});
        return id;
    }

    const Handle* get(uint32_t id) const {
        const auto it = m_handles.find(id);
        return it == m_handles.end() ? nullptr : &it->second;
    }

    void release(uint32_t id) {
        const auto it = m_handles.find(id);
        if (it == m_handles.end()) {
            return;
        }
        if (it->second.managed) {
            static_cast<reframework::API::ManagedObject*>(it->second.ptr)->release();
        }
        m_handles.erase(it);
    }

    void clear() {
        for (auto& [id, h] : m_handles) {
            if (h.managed) {
                static_cast<reframework::API::ManagedObject*>(h.ptr)->release();
            }
        }
        m_handles.clear();
    }

    size_t size() const { return m_handles.size(); }

private:
    std::unordered_map<uint32_t, Handle> m_handles{};
    uint32_t m_next{1};
};

} // namespace bridge
