#pragma once

#include <cstdint>
#include <string>

#include <nlohmann/json.hpp>
#include <reframework/API.hpp>

namespace bridge::values {

using json = nlohmann::json;
using API = reframework::API;

/** How a typed slot (field, parameter, return value, array element) is read. */
enum class Kind {
    Void,
    Bool,
    I8,
    U8,
    I16,
    U16,
    I32,
    U32,
    I64,
    U64,
    F32,
    F64,
    Char,
    String,    // System.String reference
    ValueType, // inline struct (not a primitive)
    Object,    // reference to a managed object
};

/** Resolve a type to its slot kind; enums resolve to their underlying type. */
Kind kind_of(API::TypeDefinition* t);

/** Size in bytes of an inline slot of this kind (0 for Void). References are pointer-sized. */
uint32_t slot_size(Kind k, API::TypeDefinition* t);

bool is_primitive(Kind k);

/** Read a primitive stored at `p`. */
json read_at(const void* p, Kind k);

/** Write a primitive to `p`. False when the JSON value does not fit the kind. */
bool write_at(void* p, Kind k, const json& v);

/** Read a primitive out of an invoke result slot. */
json read_ret(const reframework::InvokeRet& r, Kind k);

/** Pack a primitive as the 8-byte argument slot REFramework's invoke expects. */
bool pack_arg(void*& slot, Kind k, const json& v);

/**
 * Decode a System.String. Layout assumed: 4-byte length at 0x10, UTF-16
 * characters from 0x14 (the RE Engine SystemString). Verify with mem.peek
 * on the first real run; this is the one layout the plugin assumes.
 */
std::string read_managed_string(const void* s);

std::string hex(const void* p, size_t n);

/** UTF-8 → UTF-16 for the SDK's managed-string constructor. */
std::wstring to_wide(const std::string& utf8);

} // namespace bridge::values
