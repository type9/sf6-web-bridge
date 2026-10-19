/** Port the plugin listens on unless `reframework/data/sf6-web-bridge/config.json` overrides it. */
export const DEFAULT_PORT = 47821

/** Loopback only: the plugin never binds anything else. */
export const DEFAULT_URL = `ws://127.0.0.1:${DEFAULT_PORT}`

/** Wire protocol version reported by `ping`. */
export const PROTOCOL_VERSION = 1

/** Default request timeout. The game thread answers within a frame when it is running. */
export const DEFAULT_TIMEOUT_MS = 5000

/** Where the plugin writes the pairing code, relative to the game folder. */
export const PAIRING_FILE = "reframework/data/sf6-web-bridge/pairing.txt"
