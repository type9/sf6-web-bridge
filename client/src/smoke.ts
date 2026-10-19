import { isRef, Sf6Bridge, type Ref, type Value } from "./index"

/**
 * The gate sequence from docs/FINDINGS.md as a reusable check. Runs
 * read-only unless `write` is set, in which case it edits the dummy's
 * slot 1 in place and restores it afterwards. Returns one row per gate;
 * paste the table into FINDINGS.md after every game patch.
 */
export interface SmokeRow {
	gate: string
	ok: boolean
	detail: string
}

export interface SmokeOptions {
	/** Perform the in-place write test on slot 1 (restored afterwards). */
	write?: boolean
	/** 0-based record slot of the dummy to read. */
	slot?: number
}

export async function runSmoke(bridge: Sf6Bridge, opts: SmokeOptions = {}): Promise<SmokeRow[]> {
	const rows: SmokeRow[] = []
	const gate = async (name: string, fn: () => Promise<string>) => {
		try {
			rows.push({ gate: name, ok: true, detail: await fn() })
		} catch (e) {
			rows.push({ gate: name, ok: false, detail: e instanceof Error ? e.message : String(e) })
			throw e
		}
	}
	const need = (v: Value, what: string): Ref => {
		if (!isRef(v)) throw new Error(`${what} is not an object: ${JSON.stringify(v)}`)
		return v
	}
	try {
		await gate("ping", async () => {
			const p = await bridge.ping()
			return `${p.plugin} ${p.version} protocol ${p.protocol} paired=${p.paired} training=${p.training}`
		})
		let summary = await bridge.trainingSummary()
		await gate("training.summary", async () => {
			summary = await bridge.trainingSummary()
			if (!summary.inTraining) throw new Error("not in Training Mode")
			return `p1=${JSON.stringify(summary.p1FighterId)} p2=${JSON.stringify(summary.p2FighterId)} fighters=${JSON.stringify(summary.recordFighterCount)}`
		})
		const dummy = summary.p2FighterId
		if (typeof dummy !== "number") throw new Error("no dummy fighter id")
		const rec = need(summary.recordSetting ?? null, "recordSetting")
		let slot!: Ref
		await gate("slot walk", async () => {
			const list = need(await bridge.get(rec, "FighterDataList"), "FighterDataList")
			const fd = need(await bridge.call(list, "get_Item", [dummy]), "FighterData")
			const fid = await bridge.get(fd, "FighterID")
			if (fid !== dummy) throw new Error(`FighterID ${JSON.stringify(fid)} != ${dummy}`)
			const slots = need(await bridge.get(fd, "RecordSlots"), "RecordSlots")
			const got = await bridge.arrayGet(slots, opts.slot ?? 0, 1)
			slot = need(got.values[0] ?? null, "slot")
			return `${list.type} → ${slots.type}[${got.length}]`
		})
		let buff!: Ref
		let num = 0
		await gate("slot read", async () => {
			const frame = await bridge.get(slot, "Frame")
			const input = need(await bridge.get(slot, "InputData"), "InputData")
			const n = await bridge.get(input, "Num")
			if (typeof n !== "number") throw new Error("Num not a number")
			num = n
			buff = need(await bridge.get(input, "buff"), "buff")
			const len = await bridge.arrayLen(buff)
			const v = await bridge.arrayGet(buff, 0, Math.min(num, 64))
			return `Frame=${JSON.stringify(frame)} Num=${num} buff=${len.element}[${len.length}] first=${JSON.stringify(v.values.slice(0, 16))}`
		})
		if (opts.write) {
			await gate("slot write (in place, restored)", async () => {
				if (num === 0) throw new Error("slot is empty; record something first")
				const original = (await bridge.arrayGet(buff, 0, num)).values as number[]
				const swap: Record<number, number> = { 1: 2, 2: 1, 4: 8, 8: 4 }
				const edited = original.map((x) => swap[x] ?? x)
				await bridge.arraySet(buff, 0, edited)
				const back = (await bridge.arrayGet(buff, 0, num)).values as number[]
				const ok = back.every((x, i) => x === edited[i])
				await bridge.arraySet(buff, 0, original)
				if (!ok) throw new Error("read-back differs from what was written")
				return `${num} frames written and restored`
			})
		}
	} catch {
		// the failing gate is already recorded; later gates are skipped
	}
	return rows
}

/** Render rows as a markdown table for FINDINGS.md. */
export function smokeTable(rows: SmokeRow[]): string {
	return ["| gate | ok | detail |", "|---|---|---|", ...rows.map((r) => `| ${r.gate} | ${r.ok ? "pass" : "FAIL"} | ${r.detail.replace(/\|/g, "\\|")} |`)].join("\n")
}
