// sf6-web-bridge — REFramework plugin entry.
//
// Opens a loopback WebSocket server when REFramework loads the plugin and
// drains queued RPC requests on the game thread every frame. Nothing here
// knows about drills or frame data: the browser side does, through the
// reflection ops in rpc.cpp.
#include <Windows.h>

#include <filesystem>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>
#include <reframework/API.hpp>

#include "rpc.hpp"
#include "server.hpp"

using namespace reframework;

namespace {

constexpr int DEFAULT_PORT = 47821;

/**
 * Origins allowed to open a socket. Empty = any origin: the per-launch
 * pairing code is the real gate, and a site cannot do anything but `ping`
 * without it. A player who wants to pin the bridge to specific sites lists
 * them in config.json (see load_config).
 */
const std::vector<std::string> DEFAULT_ORIGINS{};

/** Relative to the game's working directory, which is the game folder. */
constexpr const char* DATA_DIR = "reframework/data/sf6-web-bridge";

std::unique_ptr<bridge::Server> g_server;
bridge::Rpc g_rpc;

struct Config {
    int port{DEFAULT_PORT};
    std::vector<std::string> origins{DEFAULT_ORIGINS};
};

/** Optional `config.json` in the data dir: `{"port": 47821, "origins": ["https://example.com"]}`. A non-empty `origins` restricts browsers to those sites. */
Config load_config() {
    Config cfg;
    std::ifstream f{std::string{DATA_DIR} + "/config.json"};
    if (!f) {
        return cfg;
    }
    const auto j = nlohmann::json::parse(f, nullptr, false);
    if (j.is_discarded() || !j.is_object()) {
        return cfg;
    }
    cfg.port = j.value("port", cfg.port);
    if (const auto it = j.find("origins"); it != j.end() && it->is_array()) {
        cfg.origins.clear();
        for (const auto& o : *it) {
            if (o.is_string()) {
                cfg.origins.push_back(o.get<std::string>());
            }
        }
    }
    return cfg;
}

void on_update() {
    // Game thread. Keep the per-frame cost bounded.
    if (g_server) {
        g_rpc.drain(*g_server);
    }
}

} // namespace

extern "C" __declspec(dllexport) void reframework_plugin_required_version(REFrameworkPluginVersion* version) {
    version->major = REFRAMEWORK_PLUGIN_VERSION_MAJOR;
    version->minor = REFRAMEWORK_PLUGIN_VERSION_MINOR;
    version->patch = REFRAMEWORK_PLUGIN_VERSION_PATCH;
    version->game_name = nullptr; // the bridge is generic; the SF6 knowledge lives client-side
}

extern "C" __declspec(dllexport) bool reframework_plugin_initialize(const REFrameworkPluginInitializeParam* param) {
    API::initialize(param);
    const auto& api = API::get();

    const auto cfg = load_config();
    g_rpc.init(DATA_DIR);

    g_server = std::make_unique<bridge::Server>(
        cfg.port, cfg.origins,
        [](bridge::Request r) { g_rpc.enqueue(std::move(r)); },
        [](const std::string& conn) { g_rpc.on_close(conn); });

    if (!g_server->start()) {
        api->log_error("[sf6-web-bridge] server failed to start; the bridge is off");
        g_server.reset();
        return true; // keep the plugin loaded so the log explains itself
    }

    param->functions->on_pre_application_entry("UpdateBehavior", on_update);

    api->log_info("[sf6-web-bridge] v%s listening on ws://127.0.0.1:%d", SF6_WEB_BRIDGE_VERSION, cfg.port);
    api->log_info("[sf6-web-bridge] pairing code: %s (also in %s/pairing.txt)", g_rpc.pairing_code().c_str(), DATA_DIR);
    return true;
}
