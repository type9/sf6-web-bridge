# Roadmap

Principle: the DLL stays generic and small; game knowledge lives in the client and in `docs/FINDINGS.md`. Every phase ends with findings written down and a smoke script that re-checks them, so a game patch tells us what broke rather than a user.

## 0. Done (2026-10-19)

- Plugin loads on the release REFramework, loopback WebSocket, pairing code, reflection ops.
- Browser reaches it from an https page.
- Training Mode record slots read and written; input mask decoded.

## 1. Foundations — the boring part

Goal: make the next discoveries cheap and the current ones durable.

- **Smoke script** (`client/src/smoke.ts`, also pasteable as `tools/console-smoke.js`): runs the gate sequence against a live game and prints a pass/fail table — ping, pair, training summary, slot walk, array read, in-place write and read-back. Output is pasted into `docs/FINDINGS.md` on every game patch.
- **Type dumps**: `object.describe` output for every type on the training path saved under `docs/dumps/<game-build>/`, so field renames show up as a diff.
- **Explorer page**: a small static page in `tools/explorer/` that connects, lists singletons, and lets you click through fields, call methods and peek memory. This replaces console pasting for all further reverse engineering.
- **Hardening in the DLL**: wrong-code lockout; refuse writes outside Training Mode; `mode: "dev"` in `config.json` for the open reflection surface, curated allowlist otherwise; per-connection handle scoping.
- **Input mask**: record the remaining buttons (HP, LK, MK), diagonals, button combinations, DI, parry, throw, taunt. Fill the table in FINDINGS.
- **Client SDK**: typed helpers for the verified paths (`training.slots()`, `training.readSlot(n)`, `training.writeSlot(n, masks)`), plus an input-mask encoder/decoder with named bits.

## 2. Drill sharing

Goal: parity with the community drill-share mod, driven from a web page instead of an in-game ImGui window.

- **Capture**: read all 8 slots, dummy settings, reversal settings and gauges into a drill document. Reuse the mod's JSON schema so its `SF6DRILL:v2:` codes and ours interoperate; write the codec in TypeScript.
- **Apply**: write a drill into the game. Open problem: filling an empty slot needs a buffer. Options, in order of preference: find a game method that records or allocates (the Record action itself), reuse a buffer from a slot that already has one, or add `create_managed_array` once we build against a newer REFramework.
- **Verify the write path** for the remaining settings (dummy stance, block, recovery, counter, gauges) one field at a time; the mod's field names are the starting list.
- **Web side**: drill cards with "send to game" and "capture from game", an input-display preview rendered from the masks, and the code export for players without the bridge.

## 3. Meta state

Goal: drive menus the player would otherwise click through.

- **Replay by code**: find the replay search path. Candidates: `app.BattleReplayDataManager`, `app.BattleWatchManager`, whatever the replay menu's search box calls. Approach: open the replay menu, snapshot singleton lists before and after a manual search, diff; then `object.describe` the new objects and look for a method taking a string. Expect an async network call; the client polls a status field.
- **Add by user ID**: same approach on the friend / CFN search flow. This one touches the network layer and account state; it needs the curated-ops mode and an explicit in-game confirmation before shipping to anyone.
- **Live state stream**: per-frame player state (action ID, hit/guard state, position, gauges) as a subscription. This is the exact frame meter; it replaces the pixel reader for bridge users. Needs the raw array fast path and a binary frame format.

## 4. Distribution

- Signed releases with checksums, a one-page install guide with screenshots, an in-game ImGui panel showing the pairing code and connected sites.
- npm publish of the client package once the API settles.

## Risks to keep in view

- Every write is a memory write into a live game; crashes are possible and have happened to the community mod. Writes stay behind Training Mode checks.
- Anything that touches online features (replays, friends) must never run during a match, and should be reviewed against Capcom's terms before it reaches other players.
- Game patches rename fields without notice. The smoke script and dumps are the early warning.
