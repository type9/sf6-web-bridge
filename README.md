# sf6-web-bridge

A [REFramework](https://github.com/praydog/REFramework) plugin that lets a web page talk to a running copy of Street Fighter 6 on the same PC. It opens a WebSocket on `127.0.0.1` and forwards a small set of REFramework's reflection calls (find a singleton, read or write a field, call a method, read or write an array) so the game-specific logic can live in the browser and change without rebuilding the plugin.

Built to share training-mode drills and read frame data from a web app, and generic enough for any RE Engine game REFramework runs on. The plugin itself has no idea who is on the other end: any site you allow can use it.

```
browser ──ws://127.0.0.1:47821──▶ sf6-web-bridge.dll ──REFramework SDK──▶ game objects
```

## Install (player)

1. Install REFramework for SF6 if you have not: the `dinput8.dll` from its [releases](https://github.com/praydog/REFramework/releases) goes in the Street Fighter 6 folder.
2. Download `sf6-web-bridge.dll` from this repo's [releases](https://github.com/type9/sf6-web-bridge/releases) and put it in `Street Fighter 6/reframework/plugins/` (create the folder if needed).
3. Start the game. REFramework's log (`reframework_log.txt` in the game folder, also visible in the REFramework overlay) shows:

   ```
   [sf6-web-bridge] v0.1.8 listening on ws://127.0.0.1:47821
   [sf6-web-bridge] pairing code: XXXXXX (also in reframework/data/sf6-web-bridge/pairing.txt)
   ```

   The code is also copied to the Windows clipboard at launch, so pairing is a paste (`"clipboard": false` in `config.json` turns that off).

4. A site that supports the bridge asks for that code once. Nothing else runs on your machine, nothing listens outside loopback, and uninstalling is deleting the one file.

Any site can open the socket; the pairing code is what gates it, and a site cannot do anything but `ping` without the code. If you would rather pin the bridge to specific sites, list them in `reframework/data/sf6-web-bridge/config.json` and every other origin is refused:

```json
{ "port": 47821, "origins": ["https://example.com"] }
```

Every operation except `ping` requires the pairing code, so a page that is allowed to connect still cannot touch the game until you type the code into it.

## Troubleshooting

**`[PluginLoader] Failed to load ...sf6-web-bridge.dll` on every launch, no `[sf6-web-bridge]` lines.** On Windows 11 with Smart App Control enforcing, Code Integrity refuses unsigned DLLs that Microsoft's cloud has no reputation for, and every new release is a new hash with no reputation. Confirm with PowerShell:

```powershell
(Get-ItemProperty "HKLM:\SYSTEM\CurrentControlSet\Control\CI\Policy" -Name VerifiedAndReputablePolicyState).VerifiedAndReputablePolicyState
Get-WinEvent -LogName "Microsoft-Windows-CodeIntegrity/Operational" -MaxEvents 10 | Select-Object TimeCreated, Id, Message | Format-List
```

A policy state of `1` plus event `3077` naming the DLL is the block. The fix is either turning Smart App Control off (Windows Security, App & browser control; Windows makes this one-way) or a release signed with a Microsoft-trusted certificate, which is on the roadmap. `LoadLibrary` reports this as error 203, which is misleading.

**`Failed to load` once, loads on the next launch.** Defender's first-run cloud scan. Nothing to do.

**`requires a newer minor version`.** The plugin was built against a newer REFramework API than the installed `dinput8.dll`. Update REFramework or use the plugin release that matches.

## Status

Verified on 2026-10-19 against the Steam build with REFramework v1.5.9.1: the plugin loads, a browser reaches it from an https page, and Training Mode record slots can be read and written in place. The input mask and the object paths are in [docs/FINDINGS.md](docs/FINDINGS.md); what comes next is in [docs/ROADMAP.md](docs/ROADMAP.md).

## Smoke test

Two pasteable scripts for a browser DevTools console live in [`tools/`](tools/):

- `console-smoke.js` runs the gate sequence (ping, pair, training summary, slot walk, array read, optional in-place write with restore) and prints a markdown table for `docs/FINDINGS.md`. Run it after every game patch.
- `console-rpc.js` defines `rpc`, `describe`, `path` and `peek` on `window` for exploring new objects.

Both need the game in Training Mode and the pairing code pasted into the `CODE` line. The same checks are available to a bundler as `runSmoke` in the client package.

## Protocol

See [docs/PROTOCOL.md](docs/PROTOCOL.md). JSON over a text WebSocket, one request → one response, correlated by `id`. The TypeScript client in [`client/`](client/) wraps every op (`@type9/sf6-web-bridge`).

## Build

GitHub Actions builds the DLL on every push (`build` workflow, `windows-latest`); download it from the run's artifacts, or from a release when a `v*` tag is pushed. Locally on Windows:

```
cmake -S native -B build -A x64
cmake --build build --config Release
```

Dependencies are fetched by CMake: [IXWebSocket](https://github.com/machinezone/IXWebSocket) (no TLS, no zlib) and [nlohmann/json](https://github.com/nlohmann/json). The REFramework plugin API headers are vendored under `native/third_party/reframework` (MIT, praydog) from the v1.5.9.1 release, plugin API 1.10, which is what the shipped REFramework reports. Headers from REFramework's master branch declare a newer API and make the loader refuse the plugin on a release build.

## Design notes

- **Game thread.** The socket thread only queues requests. `UpdateBehavior` drains them each frame, so every SDK call happens where REFramework expects it.
- **Handles.** Objects are returned as `{h, type}`; the plugin holds a reference on managed objects until `handle.release`. Value types inline in another object are `{h, type, vt: true}` and stay valid as long as their owner does.
- **Assumed layouts.** Only one: `System.String` (length at `0x10`, UTF-16 at `0x14`). Arrays go through the type's own `get_Length` / `Get` / `Set` methods rather than raw offsets. `mem.peek` exists to check layouts on a new build.
- **Writes.** `field.set` and `array.set` accept primitives and enums; `field.set` on a reference field and `array.create` exist as experimental ops for filling empty record slots (see FINDINGS). Pointers are never written raw.

## License

MIT. REFramework API headers © praydog, MIT.
