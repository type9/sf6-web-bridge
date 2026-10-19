# sf6-web-bridge

A [REFramework](https://github.com/praydog/REFramework) plugin that lets a web page talk to a running copy of Street Fighter 6 on the same PC. It opens a WebSocket on `127.0.0.1` and forwards a small set of REFramework's reflection calls (find a singleton, read or write a field, call a method, read or write an array) so the game-specific logic can live in the browser and change without rebuilding the plugin.

Built for sharing training-mode drills and reading frame data from [lossless.fm](https://lossless.fm). Generic enough for any RE Engine game REFramework runs on.

```
browser ──ws://127.0.0.1:47821──▶ sf6-web-bridge.dll ──REFramework SDK──▶ game objects
```

## Install (player)

1. Install REFramework for SF6 if you have not: the `dinput8.dll` from its [releases](https://github.com/praydog/REFramework/releases) goes in the Street Fighter 6 folder.
2. Download `sf6-web-bridge.dll` from this repo's [releases](https://github.com/type9/sf6-web-bridge/releases) and put it in `Street Fighter 6/reframework/plugins/` (create the folder if needed).
3. Start the game. REFramework's log (`reframework_log.txt` in the game folder, also visible in the REFramework overlay) shows:

   ```
   [sf6-web-bridge] v0.1.0 listening on ws://127.0.0.1:47821
   [sf6-web-bridge] pairing code: XXXXXX (also in reframework/data/sf6-web-bridge/pairing.txt)
   ```

4. A site that supports the bridge asks for that code once. Nothing else runs on your machine, nothing listens outside loopback, and uninstalling is deleting the one file.

The plugin only accepts browser connections from an allowlist of origins (`lossless.fm`, `dev.lossless.fm`, `localhost:3000`). To add your own, create `reframework/data/sf6-web-bridge/config.json`:

```json
{ "port": 47821, "origins": ["http://localhost:5173"] }
```

Every operation except `ping` requires the pairing code, so a page that is allowed to connect still cannot touch the game until you type the code into it.

## Smoke test (first run)

Each step gates the next. Open the browser DevTools console on `https://dev.lossless.fm` (or any allowed origin) and paste:

```js
const ws = new WebSocket("ws://127.0.0.1:47821")
ws.onmessage = (e) => console.log(JSON.parse(e.data))
ws.onopen = () => ws.send(JSON.stringify({ id: 1, op: "ping" }))
```

1. **Plugin loads.** The two log lines above appear after launch. If not, REFramework's log says why (wrong REFramework version, missing exports).
2. **Browser reaches the socket.** The snippet prints `{id: 1, ok: true, result: {plugin: "sf6-web-bridge", ...}}`. `training` is `true` once you are in Training Mode.
3. **Pair and read a live value.** In Training Mode:

   ```js
   ws.send(JSON.stringify({ id: 2, op: "hello", code: "XXXXXX" }))
   ws.send(JSON.stringify({ id: 3, op: "training.summary" }))
   ```

   Expect `p1FighterId` / `p2FighterId` numbers. Change the dummy character and run the summary again: `p2FighterId` changes. This proves the reflection path and the game-thread handoff.

4. **Read a recording.** Record a known sequence into slot 1 of the dummy (hold forward, then tap LP, MP, HK), then walk to the buffer with the handles the summary returned:

   ```js
   // recordSetting.h from the summary; dummy id from p2FighterId
   ws.send(JSON.stringify({ id: 4, op: "field.get", h: REC, name: "FighterDataList" }))
   ws.send(JSON.stringify({ id: 5, op: "method.call", h: LIST, name: "get_Item", args: [DUMMY_ID] }))
   ws.send(JSON.stringify({ id: 6, op: "field.get", h: FD, name: "RecordSlots" }))
   ws.send(JSON.stringify({ id: 7, op: "array.get", h: SLOTS, from: 0, count: 1 }))
   ws.send(JSON.stringify({ id: 8, op: "field.get", h: SLOT0, name: "InputData" }))
   ws.send(JSON.stringify({ id: 9, op: "field.get", h: INPUT, name: "buff" }))
   ws.send(JSON.stringify({ id: 10, op: "array.get", h: BUFF, from: 0, count: 200 }))
   ```

   The values are the per-frame input bitmasks. This step pins the bit layout.

5. **Write a recording.** `array.set` the same values into slot 2's buffer and set its `Frame` / `Num` fields, then play slot 2 in the game. This is the risky step and the one that decides drill sharing.

The field names come from the community "SF6 Drill Share" REFramework Lua mod and REFramework's Object Explorer; `object.describe` on any handle lists what a build actually has.

## Protocol

See [docs/PROTOCOL.md](docs/PROTOCOL.md). JSON over a text WebSocket, one request → one response, correlated by `id`. The TypeScript client in [`client/`](client/) wraps every op (`@type9/sf6-web-bridge`).

## Build

GitHub Actions builds the DLL on every push (`build` workflow, `windows-latest`); download it from the run's artifacts, or from a release when a `v*` tag is pushed. Locally on Windows:

```
cmake -S native -B build -A x64
cmake --build build --config Release
```

Dependencies are fetched by CMake: [IXWebSocket](https://github.com/machinezone/IXWebSocket) (no TLS, no zlib) and [nlohmann/json](https://github.com/nlohmann/json). The REFramework plugin API headers are vendored under `native/third_party/reframework` (MIT, praydog).

## Design notes

- **Game thread.** The socket thread only queues requests. `UpdateBehavior` drains them each frame, so every SDK call happens where REFramework expects it.
- **Handles.** Objects are returned as `{h, type}`; the plugin holds a reference on managed objects until `handle.release`. Value types inline in another object are `{h, type, vt: true}` and stay valid as long as their owner does.
- **Assumed layouts.** Only one: `System.String` (length at `0x10`, UTF-16 at `0x14`). Arrays go through the type's own `get_Length` / `Get` / `Set` methods rather than raw offsets. `mem.peek` exists to check layouts on a new build.
- **Writes.** `field.set` and `array.set` accept primitives and enums only. Object references and array allocation are deliberately not exposed yet.

## License

MIT. REFramework API headers © praydog, MIT.
