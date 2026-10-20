import {
	DEFAULT_TIMEOUT_MS,
	DEFAULT_URL,
	PAIRING_FILE,
	PROTOCOL_VERSION,
} from "./constants"

export { DEFAULT_PORT, DEFAULT_URL, PAIRING_FILE, PROTOCOL_VERSION } from "./constants"
export { INPUT_BITS, decodeInputMask, encodeInputMask, runLengths, expandRunLengths, type InputName } from "./input-mask"
export { runSmoke, smokeTable, type SmokeRow, type SmokeOptions } from "./smoke"

/** A reference to an object inside the game. `vt` marks inline value-type storage. */
export interface Ref {
	h: number
	type: string
	vt?: boolean
	static?: boolean
}

/** What a typed slot reads as: primitives come back as JSON scalars, references as `Ref`. */
export type Value = number | boolean | string | null | Ref | { vt: string; bytes: string }

export interface PingResult {
	plugin: string
	version: string
	protocol: number
	paired: boolean
	handles: number
	tdb: { types: number; methods: number }
	training: boolean
}

export interface FieldInfo {
	name: string
	type: string
	static: boolean
	offset: number
}

export interface MethodInfo {
	name: string
	returns: string
	static: boolean
	params: Array<{ name: string; type: string }>
}

export interface TypeDescription {
	type: string
	parent: string | null
	valuetype: boolean
	size: number
	fields: FieldInfo[]
	methods: MethodInfo[]
}

export interface ArrayInfo {
	array: string
	element: string
	length: number
}

export interface TrainingSummary {
	inTraining: boolean
	p1FighterId: number | null | { error: string }
	p2FighterId: number | null | { error: string }
	recordFighterCount: number | null | { error: string }
	trainingData?: Ref | null
	recordSetting?: Ref | null
}

/** An installed method hook (`hook.add` / `hook.list`). */
export interface HookInfo {
	id: number
	type: string
	method: string
	slot: number
}

/**
 * One recorded argument or return value. Exactly one of `value`, `str`,
 * `h` (+ `rtype`, `ptr`), `ptr` or `error` is present. For arguments `i`
 * is the argv index: 0 = thread context, 1 = `this`, 2.. = parameters.
 */
export interface TraceSlot {
	i?: number
	type: string
	value?: number | boolean | null
	str?: string | null
	h?: number
	rtype?: string
	ptr?: string
	error?: string
}

export interface TraceCall {
	seq: number
	/** Milliseconds since the plugin started. */
	t: number
	id: number
	type: string
	method: string
	args: TraceSlot[]
	ret?: TraceSlot
}

export class BridgeError extends Error {
	constructor(
		message: string,
		readonly op: string,
	) {
		super(message)
		this.name = "BridgeError"
	}
}

export interface ConnectOptions {
	/** Defaults to `ws://127.0.0.1:47821`. */
	url?: string
	/** Pairing code shown in REFramework's log and `pairing.txt`. Sent as `hello` right after connecting. */
	code?: string
	timeoutMs?: number
	onClose?: (ev: CloseEvent) => void
}

interface Pending {
	op: string
	resolve: (v: unknown) => void
	reject: (e: Error) => void
	timer: ReturnType<typeof setTimeout>
}

/**
 * One socket to the plugin. Every method is a thin typed wrapper over the
 * reflection ops; see docs/PROTOCOL.md for the wire shape.
 */
export class Sf6Bridge {
	private next = 1
	private pending = new Map<number, Pending>()

	private constructor(
		private readonly ws: WebSocket,
		private readonly timeoutMs: number,
	) {}

	static connect(opts: ConnectOptions = {}): Promise<Sf6Bridge> {
		const url = opts.url ?? DEFAULT_URL
		const timeoutMs = opts.timeoutMs ?? DEFAULT_TIMEOUT_MS
		return new Promise((resolve, reject) => {
			const ws = new WebSocket(url)
			const bridge = new Sf6Bridge(ws, timeoutMs)
			ws.onmessage = (ev) => bridge.onMessage(ev)
			ws.onerror = () => reject(new BridgeError(`could not reach ${url}`, "connect"))
			ws.onclose = (ev) => {
				bridge.failAll(new BridgeError(`socket closed (${ev.code})`, "connect"))
				opts.onClose?.(ev)
			}
			ws.onopen = async () => {
				try {
					if (opts.code) await bridge.hello(opts.code)
					resolve(bridge)
				} catch (e) {
					ws.close()
					reject(e)
				}
			}
		})
	}

	close(): void {
		this.ws.close()
	}

	get connected(): boolean {
		return this.ws.readyState === WebSocket.OPEN
	}

	/** Raw op. Prefer the typed wrappers below. */
	request<T = unknown>(op: string, params: Record<string, unknown> = {}): Promise<T> {
		const id = this.next++
		return new Promise<T>((resolve, reject) => {
			const timer = setTimeout(() => {
				this.pending.delete(id)
				reject(new BridgeError(`timed out after ${this.timeoutMs} ms`, op))
			}, this.timeoutMs)
			this.pending.set(id, { op, resolve: resolve as (v: unknown) => void, reject, timer })
			this.ws.send(JSON.stringify({ id, op, ...params }))
		})
	}

	private onMessage(ev: MessageEvent): void {
		let msg: { id?: number; ok?: boolean; result?: unknown; error?: string }
		try {
			msg = JSON.parse(String(ev.data))
		} catch {
			return
		}
		if (typeof msg.id !== "number") return
		const p = this.pending.get(msg.id)
		if (!p) return
		this.pending.delete(msg.id)
		clearTimeout(p.timer)
		if (msg.ok) p.resolve(msg.result)
		else p.reject(new BridgeError(msg.error ?? "unknown error", p.op))
	}

	private failAll(err: Error): void {
		for (const [, p] of this.pending) {
			clearTimeout(p.timer)
			p.reject(err)
		}
		this.pending.clear()
	}

	// ── ops ──────────────────────────────────────────────────────────

	hello(code: string): Promise<{ paired: boolean }> {
		return this.request("hello", { code })
	}

	ping(): Promise<PingResult> {
		return this.request("ping")
	}

	singleton(name: string): Promise<Ref | null> {
		return this.request("singleton.get", { name })
	}

	singletons(): Promise<string[]> {
		return this.request("singletons.list")
	}

	/** A type-only handle: static fields and static methods work on it. */
	type(name: string): Promise<Ref | null> {
		return this.request("type.find", { name })
	}

	/** Substring search over every type name in the game (≥ 3 chars); capped at 500. */
	searchTypes(q: string): Promise<{ q: string; scanned: number; truncated: boolean; types: string[] }> {
		return this.request("type.search", { q })
	}

	describe(ref: Ref): Promise<TypeDescription> {
		return this.request("object.describe", { h: ref.h })
	}

	get(ref: Ref, name: string): Promise<Value> {
		return this.request("field.get", { h: ref.h, name })
	}

	/** Primitives and enums only. Returns the value read back. */
	/** Primitives and enums; strings and object references (`{h}` or null) are experimental (plugin ≥ 0.1.6). */
	set(ref: Ref, name: string, value: number | boolean | string | Ref | null): Promise<Value> {
		return this.request("field.set", { h: ref.h, name, value: isRef(value) ? { h: value.h } : value })
	}

	call(ref: Ref, name: string, args: Array<number | boolean | string | Ref | null> = []): Promise<Value> {
		return this.request("method.call", { h: ref.h, name, args })
	}

	arrayLen(ref: Ref): Promise<ArrayInfo> {
		return this.request("array.len", { h: ref.h })
	}

	arrayGet(ref: Ref, from = 0, count?: number): Promise<{ from: number; length: number; values: Value[] }> {
		return this.request("array.get", { h: ref.h, from, ...(count !== undefined ? { count } : {}) })
	}

	/** Primitive elements only. */
	arraySet(ref: Ref, from: number, values: Array<number | boolean>): Promise<{ from: number; written: number; length: number }> {
		return this.request("array.set", { h: ref.h, from, values })
	}

	/** Experimental. Instantiate a managed class by full name (parameterless ctor); pinned for the process lifetime. */
	createObject(type: string): Promise<Ref & { pinned: true }> {
		return this.request("object.create", { type })
	}

	/** Experimental. Allocate a managed array of a primitive element type; pinned for the process lifetime. */
	createArray(element: string, length: number): Promise<Ref & { pinned: true }> {
		return this.request("array.create", { element, length })
	}

	/** Raw bytes at the handle, hex-encoded. For checking layouts, not for production reads. */
	peek(ref: Ref, size = 64): Promise<{ bytes: string }> {
		return this.request("mem.peek", { h: ref.h, size })
	}

	release(ref: Ref): Promise<{ handles: number }> {
		return this.request("handle.release", { h: ref.h })
	}

	trainingSummary(): Promise<TrainingSummary> {
		return this.request("training.summary")
	}

	// ── tracing (experimental) ───────────────────────────────────────

	/** Experimental. Hook `type.method` so its calls are recorded; `params` picks an overload by parameter count. At most 16 hooks. */
	hookAdd(type: string, method: string, params?: number): Promise<HookInfo> {
		return this.request("hook.add", { type, method, ...(params !== undefined ? { params } : {}) })
	}

	hookRemove(id: number): Promise<{ removed: true }> {
		return this.request("hook.remove", { id })
	}

	hookList(): Promise<HookInfo[]> {
		return this.request("hook.list")
	}

	/** Returns and clears the recorded calls (oldest first, at most 512). Object arguments come back as handles. */
	hookDrain(): Promise<TraceCall[]> {
		return this.request("hook.drain")
	}

	/** Walk a dotted field path from a ref: `get(tm, "_tData.SelectMenu.PlayerDatas")`. */
	async path(ref: Ref, dotted: string): Promise<Value> {
		let cur: Value = ref
		for (const part of dotted.split(".")) {
			if (!isRef(cur)) throw new BridgeError(`"${part}" reached a non-object`, "field.get")
			cur = await this.get(cur, part)
		}
		return cur
	}
}

export function isRef(v: Value | undefined): v is Ref {
	return typeof v === "object" && v !== null && "h" in v
}
