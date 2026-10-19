"use client"

import { createContext, createElement, useCallback, useContext, useEffect, useMemo, useRef, useState, type ReactNode } from "react"

import { DEFAULT_URL } from "./constants"
import { BridgeError, Sf6Bridge, type PingResult } from "./index"

/**
 * UI pairing standard. One hook owns the socket and the pairing code:
 *
 *   idle → connecting → connected (ping answered, not paired)
 *        → paired (hello accepted) | error (refused / wrong code / closed)
 *
 * The code is remembered in localStorage (`storageKey`) so a page that
 * was paired once reconnects silently on the next visit while the game
 * is running; the plugin rotates the code every launch, so a stale code
 * drops the hook to `connected` with `error` set and the page asks again.
 */
export type BridgeStatus = "idle" | "connecting" | "connected" | "paired" | "error"

export interface UseSf6BridgeOptions {
	url?: string
	/** localStorage key for the remembered pairing code. */
	storageKey?: string
	/** Try to connect (and pair with the remembered code) on mount. Default true. */
	autoConnect?: boolean
	/** Re-ping interval while connected, ms; 0 disables. Default 5000. */
	pingEveryMs?: number
}

export interface Sf6BridgeState {
	status: BridgeStatus
	bridge: Sf6Bridge | null
	ping: PingResult | null
	error: string | null
	/** Remembered pairing code, if any. */
	code: string | null
	connect: () => Promise<void>
	pair: (code: string) => Promise<void>
	disconnect: () => void
	forget: () => void
}

const DEFAULT_STORAGE_KEY = "sf6-web-bridge:code"

function readStored(key: string): string | null {
	try {
		return typeof localStorage === "undefined" ? null : localStorage.getItem(key)
	} catch {
		return null
	}
}

function writeStored(key: string, value: string | null): void {
	try {
		if (typeof localStorage === "undefined") return
		if (value === null) localStorage.removeItem(key)
		else localStorage.setItem(key, value)
	} catch {
		// private mode etc.
	}
}

export function useSf6Bridge(opts: UseSf6BridgeOptions = {}): Sf6BridgeState {
	const url = opts.url ?? DEFAULT_URL
	const storageKey = opts.storageKey ?? DEFAULT_STORAGE_KEY
	const autoConnect = opts.autoConnect ?? true
	const pingEveryMs = opts.pingEveryMs ?? 5000

	const [status, setStatus] = useState<BridgeStatus>("idle")
	const [bridge, setBridge] = useState<Sf6Bridge | null>(null)
	const [ping, setPing] = useState<PingResult | null>(null)
	const [error, setError] = useState<string | null>(null)
	const [code, setCode] = useState<string | null>(() => readStored(storageKey))
	const bridgeRef = useRef<Sf6Bridge | null>(null)
	const codeRef = useRef<string | null>(code)
	codeRef.current = code

	const disconnect = useCallback(() => {
		bridgeRef.current?.close()
		bridgeRef.current = null
		setBridge(null)
		setPing(null)
		setStatus("idle")
	}, [])

	const connect = useCallback(async () => {
		if (bridgeRef.current?.connected) return
		setStatus("connecting")
		setError(null)
		try {
			const b = await Sf6Bridge.connect({
				url,
				onClose: () => {
					if (bridgeRef.current === b) {
						bridgeRef.current = null
						setBridge(null)
						setPing(null)
						setStatus((s) => (s === "error" ? s : "idle"))
					}
				},
			})
			bridgeRef.current = b
			setBridge(b)
			const p = await b.ping()
			setPing(p)
			setStatus("connected")
			const remembered = codeRef.current
			if (remembered) {
				try {
					await b.hello(remembered)
					setStatus("paired")
				} catch (e) {
					setError(e instanceof BridgeError ? e.message : String(e))
				}
			}
		} catch (e) {
			setStatus("error")
			setError(e instanceof Error ? e.message : String(e))
		}
	}, [url])

	const pair = useCallback(
		async (next: string) => {
			const trimmed = next.trim().toUpperCase()
			if (!bridgeRef.current?.connected) await connect()
			const b = bridgeRef.current
			if (!b) throw new BridgeError("not connected", "hello")
			setError(null)
			try {
				await b.hello(trimmed)
				writeStored(storageKey, trimmed)
				setCode(trimmed)
				setStatus("paired")
			} catch (e) {
				const msg = e instanceof Error ? e.message : String(e)
				setError(msg)
				throw e
			}
		},
		[connect, storageKey],
	)

	const forget = useCallback(() => {
		writeStored(storageKey, null)
		setCode(null)
	}, [storageKey])

	useEffect(() => {
		if (!autoConnect) return
		void connect()
		return () => {
			bridgeRef.current?.close()
			bridgeRef.current = null
		}
	}, [autoConnect, connect])

	useEffect(() => {
		if (!bridge || pingEveryMs <= 0) return
		const t = setInterval(() => {
			bridge.ping().then(setPing).catch(() => undefined)
		}, pingEveryMs)
		return () => clearInterval(t)
	}, [bridge, pingEveryMs])

	return useMemo(
		() => ({ status, bridge, ping, error, code, connect, pair, disconnect, forget }),
		[status, bridge, ping, error, code, connect, pair, disconnect, forget],
	)
}

const Ctx = createContext<Sf6BridgeState | null>(null)

/** Share one bridge connection across a page tree. */
export function Sf6BridgeProvider({ children, ...opts }: UseSf6BridgeOptions & { children?: ReactNode }) {
	const value = useSf6Bridge(opts)
	return createElement(Ctx.Provider, { value }, children)
}

export function useSf6BridgeContext(): Sf6BridgeState {
	const v = useContext(Ctx)
	if (!v) throw new Error("useSf6BridgeContext must be used inside <Sf6BridgeProvider>")
	return v
}
