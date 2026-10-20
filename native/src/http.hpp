#pragma once

#include <cstddef>
#include <cstdint>
#include <string>

namespace bridge::http {

struct Response {
    uint32_t status{};
    std::string body{};
};

/**
 * Blocking GET through WinHTTP: HTTPS, redirects (never https → http),
 * 60 s resolve/connect/send/receive timeouts. Runs on the calling thread,
 * so the game is frozen for the whole download when called from the RPC.
 *
 * Throws on transport failures (DNS, TLS, timeouts) and when a 2xx body
 * would exceed `max_bytes`. Non-2xx statuses come back as a Response with
 * the body truncated to a few KB so the caller can quote it.
 */
Response get(const std::string& url, size_t max_bytes);

} // namespace bridge::http
