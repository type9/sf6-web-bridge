cmake_minimum_required(VERSION 3.21)

# sf6-web-bridge — a REFramework plugin that exposes a small reflection RPC
# over a loopback WebSocket, so a browser page can read and write Street
# Fighter 6 training-mode state. Builds to one DLL that goes in
# <game>/reframework/plugins/.
#
# Static CRT on purpose: players should not need a Visual C++ redistributable
# for a single plugin file.
cmake_policy(SET CMP0091 NEW)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

project(sf6-web-bridge LANGUAGES C CXX VERSION 0.1.9)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# ── WebSocket server (no TLS: loopback only; no zlib: tiny JSON frames) ────
set(USE_TLS OFF CACHE BOOL "" FORCE)
set(USE_ZLIB OFF CACHE BOOL "" FORCE)
set(IXWEBSOCKET_INSTALL OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
  ixwebsocket
  GIT_REPOSITORY https://github.com/machinezone/IXWebSocket.git
  GIT_TAG v12.1.0
  GIT_SHALLOW TRUE
)

# ── JSON ──────────────────────────────────────────────────────────────────
set(JSON_BuildTests OFF CACHE INTERNAL "")
FetchContent_Declare(
  nlohmann_json
  URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
)

FetchContent_MakeAvailable(ixwebsocket nlohmann_json)

add_library(sf6-web-bridge SHARED
  src/plugin.cpp
  src/server.cpp
  src/rpc.cpp
  src/values.cpp
  src/trace.cpp
)

target_include_directories(sf6-web-bridge PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/third_party
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(sf6-web-bridge PRIVATE
  ixwebsocket::ixwebsocket
  nlohmann_json::nlohmann_json
)

target_compile_definitions(sf6-web-bridge PRIVATE
  WIN32_LEAN_AND_MEAN
  NOMINMAX
  SF6_WEB_BRIDGE_VERSION="${PROJECT_VERSION}"
)

if(MSVC)
  target_compile_options(sf6-web-bridge PRIVATE /W4 /EHsc /utf-8)
endif()

set_target_properties(sf6-web-bridge PROPERTIES
  OUTPUT_NAME "sf6-web-bridge"
  PREFIX ""
)
