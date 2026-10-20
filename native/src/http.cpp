#include "http.hpp"

#include <stdexcept>
#include <string>

#include "values.hpp"

#ifdef _WIN32
#include <Windows.h>
#include <winhttp.h>
#endif

namespace bridge::http {

namespace {

#ifdef _WIN32

constexpr int TIMEOUT_MS = 60000;
/** How much of an error (non-2xx) body is kept for the error message. */
constexpr size_t ERROR_BODY_CAP = 4096;

/** Closes a WinHTTP handle on scope exit. */
struct HInternet {
    HINTERNET h{};
    HInternet() = default;
    explicit HInternet(HINTERNET handle) : h{handle} {}
    HInternet(const HInternet&) = delete;
    HInternet& operator=(const HInternet&) = delete;
    ~HInternet() {
        if (h != nullptr) {
            WinHttpCloseHandle(h);
        }
    }
};

[[noreturn]] void fail(const char* what) {
    throw std::runtime_error(std::string{what} + " failed (WinHTTP error " + std::to_string(GetLastError()) + ")");
}

#endif

} // namespace

#ifdef _WIN32

Response get(const std::string& url, size_t max_bytes) {
    const auto wurl = values::to_wide(url);

    // Pointer-into-string mode: NULL pointer + non-zero length makes
    // WinHttpCrackUrl point each component at the URL buffer.
    URL_COMPONENTS uc{};
    uc.dwStructSize = sizeof(uc);
    uc.dwSchemeLength = static_cast<DWORD>(-1);
    uc.dwHostNameLength = static_cast<DWORD>(-1);
    uc.dwUrlPathLength = static_cast<DWORD>(-1);
    uc.dwExtraInfoLength = static_cast<DWORD>(-1);
    if (!WinHttpCrackUrl(wurl.c_str(), static_cast<DWORD>(wurl.size()), 0, &uc)) {
        fail("WinHttpCrackUrl");
    }
    if (uc.nScheme != INTERNET_SCHEME_HTTP && uc.nScheme != INTERNET_SCHEME_HTTPS) {
        throw std::runtime_error("only http and https URLs are supported");
    }
    if (uc.lpszHostName == nullptr || uc.dwHostNameLength == 0) {
        throw std::runtime_error("URL has no host");
    }
    const bool secure = uc.nScheme == INTERNET_SCHEME_HTTPS;
    const std::wstring host{uc.lpszHostName, uc.dwHostNameLength};
    std::wstring path;
    if (uc.lpszUrlPath != nullptr && uc.dwUrlPathLength > 0) {
        path.assign(uc.lpszUrlPath, uc.dwUrlPathLength);
    }
    if (uc.lpszExtraInfo != nullptr && uc.dwExtraInfoLength > 0) {
        path.append(uc.lpszExtraInfo, uc.dwExtraInfoLength);
    }
    if (path.empty()) {
        path = L"/";
    }

    HInternet session{WinHttpOpen(L"sf6-web-bridge", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0)};
    if (session.h == nullptr) {
        fail("WinHttpOpen");
    }
    WinHttpSetTimeouts(session.h, TIMEOUT_MS, TIMEOUT_MS, TIMEOUT_MS, TIMEOUT_MS);
    // WinHTTP follows redirects by default; make the policy explicit and
    // keep it from downgrading an https URL to http on the way.
    DWORD redirect = WINHTTP_OPTION_REDIRECT_POLICY_DISALLOW_HTTPS_TO_HTTP;
    WinHttpSetOption(session.h, WINHTTP_OPTION_REDIRECT_POLICY, &redirect, sizeof(redirect));

    HInternet conn{WinHttpConnect(session.h, host.c_str(), uc.nPort, 0)};
    if (conn.h == nullptr) {
        fail("WinHttpConnect");
    }
    HInternet req{WinHttpOpenRequest(conn.h, L"GET", path.c_str(), nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES,
        secure ? WINHTTP_FLAG_SECURE : 0)};
    if (req.h == nullptr) {
        fail("WinHttpOpenRequest");
    }
    if (!WinHttpSendRequest(req.h, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
        fail("WinHttpSendRequest");
    }
    if (!WinHttpReceiveResponse(req.h, nullptr)) {
        fail("WinHttpReceiveResponse");
    }

    DWORD status = 0;
    DWORD status_size = sizeof(status);
    if (!WinHttpQueryHeaders(req.h, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER, WINHTTP_HEADER_NAME_BY_INDEX, &status,
            &status_size, WINHTTP_NO_HEADER_INDEX)) {
        fail("WinHttpQueryHeaders");
    }

    Response out;
    out.status = status;
    const bool ok = status >= 200 && status < 300;
    const size_t cap = ok ? max_bytes : ERROR_BODY_CAP;
    for (;;) {
        DWORD avail = 0;
        if (!WinHttpQueryDataAvailable(req.h, &avail)) {
            fail("WinHttpQueryDataAvailable");
        }
        if (avail == 0) {
            break;
        }
        if (out.body.size() + avail > cap) {
            if (ok) {
                throw std::runtime_error("response body exceeds maxBytes (" + std::to_string(max_bytes) + ")");
            }
            break; // error bodies are only quoted, not stored
        }
        const auto at = out.body.size();
        out.body.resize(at + avail);
        DWORD got = 0;
        if (!WinHttpReadData(req.h, out.body.data() + at, avail, &got)) {
            fail("WinHttpReadData");
        }
        out.body.resize(at + got);
        if (got == 0) {
            break;
        }
    }
    return out;
}

#else

Response get(const std::string&, size_t) {
    throw std::runtime_error("http.get is only available on Windows");
}

#endif

} // namespace bridge::http
