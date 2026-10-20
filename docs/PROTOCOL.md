# Wire protocol (v1)

Text WebSocket on `ws://127.0.0.1:47821`. Each message is one JSON object.

Request: `{"id": <number>, "op": "<name>", ...params}`
Response: `{"id": <number>, "ok": true, "result": ...}` or `{"id": <number>, "ok": false, "error": "<message>"}`

Responses are sent from the game thread, normally within one frame. Requests are answered in order per connection.

## Values

| slot type | JSON |
|---|---|
| bool | `true` / `false` |
| integers, floats, enums | number |
| `System.String` | string or `null` |
| object reference | `{"h": n, "type": "app.Foo"}` or `null` |
| inline value type (struct field) | `{"h": n, "type": "System.Guid", "vt": true}` |
| value-type method result | `{"vt": "via.vec3", "bytes": "<hex>"}` |

Handles (`h`) are numbers valid for the life of the plugin or until `handle.release`. Managed-object handles hold a reference on the object.

## Ops

### `ping` (no pairing)
→ `{plugin, version, protocol, paired, handles, tdb: {types, methods}, training}`

### `hello` `{code}` (no pairing)
Pairs the connection. → `{paired: true}`. Every other op fails with `not paired` until this succeeds.

### `singleton.get` `{name}`
Managed singleton by full type name, e.g. `app.training.TrainingManager`. → ref or `null`.

### `singletons.list`
→ array of full type names of every managed singleton.

### `type.find` `{name}`
→ `{h, type, static: true}` or `null`. A type-only handle: `field.get` / `method.call` work for static members.

### `type.search` `{q}`
Case-insensitive substring search over all type names (≥ 3 characters). → `{q, scanned, truncated, types: [...]}`, capped at 500 names. Slow-ish on first use (the whole type database is walked).

### `object.describe` `{h}`
→ `{type, parent, valuetype, size, fields: [{name, type, static, offset}], methods: [{name, returns, static, params: [{name, type}]}]}`

### `field.get` `{h, name}`
→ value (see table).

### `field.set` `{h, name, value}`
Primitives and enums → the value read back. `System.String` fields (experimental) accept `null` or a string; a fresh managed string is created and referenced. Reference fields (experimental) accept `null` or `{h}` of a managed object; the new referent gets a reference added, the old one is left alone.

### `method.call` `{h, name, args?: []}`
Arguments by position: numbers / booleans for primitives, strings for `System.String`, `null` or `{h}` for references and value types. → return value, `null` for `void`. Fails if the game throws.

### `array.len` `{h}`
→ `{array, element, length}`

### `array.get` `{h, from?: 0, count?}`
→ `{from, length, values: [...]}`. Elements read through the array type's `Get`. Capped at 100000 elements.

### `array.set` `{h, from, values: [...]}`
Primitive element types only; never grows the array. → `{from, written, length}`

### `array.create` `{element, length}` — experimental
Allocates a managed array through `System.Array.CreateInstance(Type, int)` and pins it for the process lifetime. → ref with `pinned: true`.

### `object.create` `{type}` — experimental
Instantiates a managed class by full name through REFramework's `create_instance` (parameterless constructor) and pins it for the process lifetime. Refuses value types and arrays. → ref with `pinned: true`. Meant for the small parameter objects the game's UI flows take.

### `mem.peek` `{h, size?: 64}`
→ `{bytes: "<hex>"}` of the handle's memory, up to 4096 bytes. For checking layouts.

### `handle.release` `{h}`
→ `{handles}` remaining.

### `training.summary`
Convenience walk of `app.training.TrainingManager._tData`. → `{inTraining, p1FighterId, p2FighterId, recordFighterCount, trainingData: ref, recordSetting: ref}`. Fields that could not be read are `null` or `{error}` rather than failing the whole call.

## Tracing (experimental)

A method-call tracer for watching which game methods run, with which arguments, while the player drives a menu flow by hand. Hooks are installed through REFramework's `add_hook` (pre + post) on one of 16 fixed slots. Recording never throws into the game: anything that cannot be read becomes an `error` slot.

### `hook.add` `{type, method, params?}`
`type` is a full type name, `method` a method name on it (own methods first, then parents). With several overloads, `params` (parameter count) picks one; without it the error lists the candidates' parameter counts. → `{id, type, method, slot}`. Fails when all 16 slots are in use or the method is already hooked.

### `hook.remove` `{id}`
→ `{removed: true}`. Frees the slot.

### `hook.list`
→ `[{id, type, method, slot}]`

### `hook.drain`
Returns and clears the recorded calls, oldest first. The buffer keeps the last 512 calls; older ones are dropped. →
`[{seq, t, id, type, method, args: [slot...], ret?: slot}]` where `t` is milliseconds since the plugin started and a slot is `{i?, type, value? | str? | h? + rtype + ptr | ptr? | error?}`.

Argument convention (as implemented; REFramework's hook passes the raw native argument list): `args[i].i` is the argv index —
- `0`: the thread context (recorded as `ptr`, type `ctx` unless the SDK reports one)
- `1`: `this` for instance methods (recorded as an object: `ptr`, runtime `rtype`, and a handle `h`); for static methods the slot is recorded as `ptr` with type `this(static)`
- `2..`: the declared parameters in order

`type` is the type REFramework reports in `arg_tys[i]`, falling back to the declared parameter type (or the declaring type for `this`) when it reports none. Values: primitives and enums are read inline from the slot (`value`); `System.String` is decoded (`str`, capped at 256 characters, `null` for a null reference); other references are recorded as `ptr` plus, when the pointer looks like a live managed object, its runtime type `rtype` and a handle `h` that `object.describe` / `field.get` accept (the object is referenced for the life of the handle). Anything else (inline value types, unknown types) is `ptr`: the raw 8-byte slot. `ret` is the return value recorded the same way by the post hook (absent for `void`); it is paired with the newest unfinished call of the same hook on the same thread.

## Safety

- Binds `127.0.0.1` only.
- Browser connections must send an allowed `Origin`; connections with no `Origin` (command-line tools) are accepted.
- Nothing but `ping` works before `hello` with the pairing code, which changes every launch.
- Writes: primitive fields and array elements, plus (experimental) reference fields and array allocation. No native-pointer writes.
