#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

namespace ix {
class WebSocketServer;
class WebSocket;
} // namespace ix

namespace bridge {

/** One parsed client message, queued for the game thread. */
struct Request {
    std::string conn;   // connection id (stable for the socket's life)
    ix::WebSocket* ws;  // identity only; never dereferenced off the server thread
    nlohmann::json body;
};

/**
 * Loopback WebSocket server. Accepts only connections whose Origin header
 * is on the allowlist (or absent, for command-line tools), hands every
 * text frame to `on_message` as a parsed JSON Request, and lets the game
 * thread answer later through `send`.
 */
class Server {
public:
    using OnMessage = std::function<void(Request)>;
    using OnClose = std::function<void(const std::string& conn)>;

    Server(int port, std::vector<std::string> allowed_origins, OnMessage on_message, OnClose on_close);
    ~Server();

    bool start();
    void stop();

    /** Thread-safe. Drops the message if the socket is gone. */
    void send(ix::WebSocket* ws, const std::string& text);

    int port() const { return m_port; }

private:
    bool origin_allowed(const std::string& origin) const;

    int m_port;
    std::vector<std::string> m_origins;
    OnMessage m_on_message;
    OnClose m_on_close;
    std::unique_ptr<ix::WebSocketServer> m_server;
};

} // namespace bridge
