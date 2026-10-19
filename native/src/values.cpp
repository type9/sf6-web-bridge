#include "values.hpp"

#include <cstring>
#include <string_view>

#ifdef _WIN32
#include <Windows.h>
#endif

namespace bridge::values {

Kind kind_of(API::TypeDefinition* t) {
    if (t == nullptr) {
        return Kind::Void;
    }
    if (t->is_enum()) {
        if (const auto u = t->get_underlying_type(); u != nullptr) {
            t = u;
        }
    }
    const auto name = t->get_full_name();
    const std::string_view n{name};
    if (n == "System.Void") return Kind::Void;
    if (n == "System.Boolean") return Kind::Bool;
    if (n == "System.SByte") return Kind::I8;
    if (n == "System.Byte") return Kind::U8;
    if (n == "System.Int16") return Kind::I16;
    if (n == "System.UInt16") return Kind::U16;
    if (n == "System.Int32") return Kind::I32;
    if (n == "System.UInt32") return Kind::U32;
    if (n == "System.Int64") return Kind::I64;
    if (n == "System.UInt64") return Kind::U64;
    if (n == "System.Single") return Kind::F32;
    if (n == "System.Double") return Kind::F64;
    if (n == "System.Char") return Kind::Char;
    if (n == "System.String") return Kind::String;
    if (t->is_valuetype()) return Kind::ValueType;
    return Kind::Object;
}

uint32_t slot_size(Kind k, API::TypeDefinition* t) {
    switch (k) {
    case Kind::Void: return 0;
    case Kind::Bool: case Kind::I8: case Kind::U8: return 1;
    case Kind::I16: case Kind::U16: case Kind::Char: return 2;
    case Kind::I32: case Kind::U32: case Kind::F32: return 4;
    case Kind::I64: case Kind::U64: case Kind::F64: return 8;
    case Kind::ValueType: return t != nullptr ? t->get_valuetype_size() : 0;
    case Kind::String: case Kind::Object: return sizeof(void*);
    }
    return 0;
}

bool is_primitive(Kind k) {
    switch (k) {
    case Kind::Bool: case Kind::I8: case Kind::U8: case Kind::I16: case Kind::U16:
    case Kind::I32: case Kind::U32: case Kind::I64: case Kind::U64:
    case Kind::F32: case Kind::F64: case Kind::Char:
        return true;
    default:
        return false;
    }
}

template <typename T> static T load(const void* p) {
    T v{};
    std::memcpy(&v, p, sizeof(T));
    return v;
}

json read_at(const void* p, Kind k) {
    switch (k) {
    case Kind::Bool: return load<uint8_t>(p) != 0;
    case Kind::I8: return load<int8_t>(p);
    case Kind::U8: return load<uint8_t>(p);
    case Kind::I16: return load<int16_t>(p);
    case Kind::U16: return load<uint16_t>(p);
    case Kind::Char: return load<uint16_t>(p);
    case Kind::I32: return load<int32_t>(p);
    case Kind::U32: return load<uint32_t>(p);
    case Kind::I64: return load<int64_t>(p);
    case Kind::U64: return load<uint64_t>(p);
    case Kind::F32: return load<float>(p);
    case Kind::F64: return load<double>(p);
    default: return nullptr;
    }
}

template <typename T> static bool store_num(void* p, const json& v) {
    if (v.is_boolean()) {
        const T t = v.get<bool>() ? T{1} : T{0};
        std::memcpy(p, &t, sizeof(T));
        return true;
    }
    if (!v.is_number()) {
        return false;
    }
    const T t = static_cast<T>(v.get<double>());
    std::memcpy(p, &t, sizeof(T));
    return true;
}

bool write_at(void* p, Kind k, const json& v) {
    switch (k) {
    case Kind::Bool: {
        if (!v.is_boolean() && !v.is_number()) return false;
        const uint8_t b = v.is_boolean() ? (v.get<bool>() ? 1 : 0) : (v.get<double>() != 0 ? 1 : 0);
        std::memcpy(p, &b, 1);
        return true;
    }
    case Kind::I8: return store_num<int8_t>(p, v);
    case Kind::U8: return store_num<uint8_t>(p, v);
    case Kind::I16: return store_num<int16_t>(p, v);
    case Kind::U16: case Kind::Char: return store_num<uint16_t>(p, v);
    case Kind::I32: return store_num<int32_t>(p, v);
    case Kind::U32: return store_num<uint32_t>(p, v);
    case Kind::I64: {
        if (!v.is_number()) return false;
        const int64_t t = v.is_number_integer() ? v.get<int64_t>() : static_cast<int64_t>(v.get<double>());
        std::memcpy(p, &t, 8);
        return true;
    }
    case Kind::U64: {
        if (!v.is_number()) return false;
        const uint64_t t = v.is_number_unsigned() ? v.get<uint64_t>() : static_cast<uint64_t>(v.get<double>());
        std::memcpy(p, &t, 8);
        return true;
    }
    case Kind::F32: return store_num<float>(p, v);
    case Kind::F64: return store_num<double>(p, v);
    default: return false;
    }
}

json read_ret(const reframework::InvokeRet& r, Kind k) {
    // Small values land in the first bytes of the result slot.
    return read_at(r.bytes.data(), k);
}

bool pack_arg(void*& slot, Kind k, const json& v) {
    uint64_t bits = 0;
    if (!write_at(&bits, k, v)) {
        return false;
    }
    std::memcpy(&slot, &bits, sizeof(slot));
    return true;
}

std::string read_managed_string(const void* s) {
    if (s == nullptr) {
        return {};
    }
    const auto base = static_cast<const uint8_t*>(s);
    const auto len = load<int32_t>(base + 0x10);
    if (len <= 0 || len > 1 << 20) {
        return {};
    }
    const auto chars = reinterpret_cast<const char16_t*>(base + 0x14);
#ifdef _WIN32
    const auto wide = reinterpret_cast<const wchar_t*>(chars);
    const int need = WideCharToMultiByte(CP_UTF8, 0, wide, len, nullptr, 0, nullptr, nullptr);
    std::string out(static_cast<size_t>(need), '\0');
    WideCharToMultiByte(CP_UTF8, 0, wide, len, out.data(), need, nullptr, nullptr);
    return out;
#else
    std::string out;
    for (int i = 0; i < len; i++) {
        out.push_back(static_cast<char>(chars[i] & 0x7f));
    }
    return out;
#endif
}

std::string hex(const void* p, size_t n) {
    static constexpr char digits[] = "0123456789abcdef";
    const auto b = static_cast<const uint8_t*>(p);
    std::string out;
    out.reserve(n * 2);
    for (size_t i = 0; i < n; i++) {
        out.push_back(digits[b[i] >> 4]);
        out.push_back(digits[b[i] & 0xf]);
    }
    return out;
}

} // namespace bridge::values
