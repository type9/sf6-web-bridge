#include "server.hpp"

#include <ixwebsocket/IXConnectionState.h>
#include <ixwebsocket/IXNetSystem.h>
#include <ixwebsocket/IXWebSocket.h>
#include <ixwebsocket/IXWebSocketServer.h>

#include <reframework/API.hpp>

namespace bridge {

Server::Server(int port, std::vector<std::string> allowed_origins, OnMessage on_message, OnClose on_close)
    : m_port{port}
    , m_origins{std::move(allowed_origins)}
    , m_on_message{std::move(on_message)}
    , m_on_close{std::move(on_close)} {
}

Server::~Server() {
    stop();
}

bool Server::origin_allowed(const std::string& origin) const {
    if (m_origins.empty()) {
        return true; // no allowlist configured: the pairing code gates every op
    }
    if (origin.empty()) {
        return true; // not a browser (wscat, scripts)
    }
    for (const auto& o : m_origins) {
        if (o == origin) {
            return true;
        }
    }
    return false;
}

bool Server::start() {
    ix::initNetSystem();

    // Loopback only. Nothing on the LAN can reach this.
    m_server = std::make_unique<ix::WebSocketServer>(m_port, "127.0.0.1");
    m_server->disablePerMessageDeflate();

    m_server->setOnClientMessageCallback(
        [this](std::shared_ptr<ix::ConnectionState> state, ix::WebSocket& ws, const ix::WebSocketMessagePtr& msg) {
            switch (msg->type) {
            case ix::WebSocketMessageType::Open: {
                std::string origin;
                if (const auto it = msg->openInfo.headers.find("Origin"); it != msg->openInfo.headers.end()) {
                    origin = it->second;
                }
                if (!origin_allowed(origin)) {
                    reframework::API::get()->log_warn("[sf6-web-bridge] refused origin %s", origin.c_str());
                    ws.close(1008, "origin not allowed");
                    return;
                }
                reframework::API::get()->log_info("[sf6-web-bridge] client %s connected (origin %s)",
                    state->getId().c_str(), origin.empty() ? "-" : origin.c_str());
                break;
            }
            case ix::WebSocketMessageType::Close:
                m_on_close(state->getId());
                break;
            case ix::WebSocketMessageType::Message: {
                if (msg->binary) {
                    return;
                }
                auto body = nlohmann::json::parse(msg->str, nullptr, false);
                if (body.is_discarded() || !body.is_object()) {
                    ws.send(R"({"ok":false,"error":"expected a JSON object"})");
                    return;
                }
                m_on_message(Request{state->getId(), &ws, std::move(body)});
                break;
            }
            default:
                break;
            }
        });

    if (!m_server->listenAndStart()) {
        reframework::API::get()->log_error("[sf6-web-bridge] could not listen on 127.0.0.1:%d", m_port);
        m_server.reset();
        return false;
    }
    return true;
}

void Server::stop() {
    if (m_server) {
        m_server->stop();
        m_server.reset();
    }
}

void Server::send(ix::WebSocket* ws, const std::string& text) {
    if (!m_server) {
        return;
    }
    for (const auto& client : m_server->getClients()) {
        if (client.get() == ws) {
            client->send(text);
            return;
        }
    }
}

} // namespace bridge
