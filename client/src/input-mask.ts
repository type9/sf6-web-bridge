/**
 * The per-frame input mask stored in Training Mode record slots
 * (`UInt16`, one per frame). Verified 2026-10-19 from the P2 side; see
 * docs/FINDINGS.md. Directions are relative to the recording player's
 * facing: `forward` is toward the opponent.
 */
export const INPUT_BITS = {
	up: 1 << 0,
	down: 1 << 1,
	back: 1 << 2,
	forward: 1 << 3,
	lp: 1 << 4,
	mp: 1 << 5,
	/** inferred from the pattern, not yet recorded */
	hp: 1 << 6,
	/** inferred from the pattern, not yet recorded */
	lk: 1 << 7,
	/** inferred from the pattern, not yet recorded */
	mk: 1 << 8,
	hk: 1 << 9,
} as const

export type InputName = keyof typeof INPUT_BITS

/** Names of the bits set in a mask, in table order; unknown high bits are reported as `bitN`. */
export function decodeInputMask(mask: number): string[] {
	const out: string[] = []
	for (const [name, bit] of Object.entries(INPUT_BITS)) {
		if (mask & bit) out.push(name)
	}
	for (let b = 10; b < 16; b++) {
		if (mask & (1 << b)) out.push(`bit${b}`)
	}
	return out
}

export function encodeInputMask(names: readonly InputName[]): number {
	let mask = 0
	for (const n of names) mask |= INPUT_BITS[n]
	return mask
}

/** Run-length encode a frame array as `[mask, frames]` pairs — the compact form used in findings and drill codes. */
export function runLengths(masks: readonly number[]): Array<[number, number]> {
	const runs: Array<[number, number]> = []
	for (const m of masks) {
		const last = runs[runs.length - 1]
		if (last && last[0] === m) last[1]++
		else runs.push([m, 1])
	}
	return runs
}

export function expandRunLengths(runs: ReadonlyArray<readonly [number, number]>): number[] {
	const out: number[] = []
	for (const [m, n] of runs) for (let i = 0; i < n; i++) out.push(m)
	return out
}
