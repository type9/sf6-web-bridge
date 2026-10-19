// Pasteable smoke test for a browser console on any https page.
// Prerequisites: the game in Training Mode with the plugin loaded, and a
// recording in the dummy's slot 1. Set CODE and WRITE, paste the whole
// file. Prints one line per gate; copy the final table into docs/FINDINGS.md.
//
// Mirrors client/src/smoke.ts without needing the package.
(() => {
	const CODE = "XXXXXX"
	const WRITE = false // true = edit slot 1 in place (restored afterwards)
	const SLOT = 0

	const ws = new WebSocket("ws://127.0.0.1:47821")
	const pending = new Map()
	let n = 1
	ws.onmessage = (e) => {
		const m = JSON.parse(e.data)
		const p = pending.get(m.id)
		if (!p) return
		pending.delete(m.id)
		m.ok ? p.res(m.result) : p.rej(new Error(p.op + ": " + m.error))
	}
	ws.onerror = () => console.error("could not reach the bridge")
	const rpc = (op, params = {}) =>
		new Promise((res, rej) => {
			const id = n++
			pending.set(id, { res, rej, op })
			ws.send(JSON.stringify({ id, op, ...params }))
		})
	const isRef = (v) => v && typeof v === "object" && "h" in v
	const rows = []
	const gate = async (name, fn) => {
		try {
			rows.push([name, "pass", await fn()])
		} catch (e) {
			rows.push([name, "FAIL", e.message])
			throw e
		}
	}
	ws.onopen = async () => {
		try {
			await gate("ping", async () => JSON.stringify(await rpc("ping")))
			await gate("hello", async () => JSON.stringify(await rpc("hello", { code: CODE })))
			const s = await rpc("training.summary")
			await gate("training.summary", async () => {
				if (!s.inTraining) throw new Error("not in Training Mode")
				return JSON.stringify({ p1: s.p1FighterId, p2: s.p2FighterId, fighters: s.recordFighterCount })
			})
			let slot, buff, num
			await gate("slot walk", async () => {
				const list = await rpc("field.get", { h: s.recordSetting.h, name: "FighterDataList" })
				const fd = await rpc("method.call", { h: list.h, name: "get_Item", args: [s.p2FighterId] })
				const fid = await rpc("field.get", { h: fd.h, name: "FighterID" })
				if (fid !== s.p2FighterId) throw new Error("FighterID mismatch " + fid)
				const slots = await rpc("field.get", { h: fd.h, name: "RecordSlots" })
				const got = await rpc("array.get", { h: slots.h, from: SLOT, count: 1 })
				slot = got.values[0]
				if (!isRef(slot)) throw new Error("slot is not an object")
				return list.type + " -> " + slots.type + "[" + got.length + "]"
			})
			await gate("slot read", async () => {
				const frame = await rpc("field.get", { h: slot.h, name: "Frame" })
				const input = await rpc("field.get", { h: slot.h, name: "InputData" })
				num = await rpc("field.get", { h: input.h, name: "Num" })
				buff = await rpc("field.get", { h: input.h, name: "buff" })
				const len = await rpc("array.len", { h: buff.h })
				const v = await rpc("array.get", { h: buff.h, from: 0, count: Math.min(num, 64) })
				return "Frame=" + frame + " Num=" + num + " buff=" + len.element + "[" + len.length + "] first=" + JSON.stringify(v.values.slice(0, 16))
			})
			if (WRITE) {
				await gate("slot write (in place, restored)", async () => {
					if (!num) throw new Error("slot is empty; record something first")
					const original = (await rpc("array.get", { h: buff.h, from: 0, count: num })).values
					const swap = { 1: 2, 2: 1, 4: 8, 8: 4 }
					const edited = original.map((x) => swap[x] ?? x)
					await rpc("array.set", { h: buff.h, from: 0, values: edited })
					const back = (await rpc("array.get", { h: buff.h, from: 0, count: num })).values
					const ok = back.every((x, i) => x === edited[i])
					await rpc("array.set", { h: buff.h, from: 0, values: original })
					if (!ok) throw new Error("read-back differs")
					return num + " frames written and restored"
				})
			}
		} catch (e) {
			// recorded in rows
		}
		console.log(["| gate | ok | detail |", "|---|---|---|", ...rows.map((r) => "| " + r.join(" | ") + " |")].join("\n"))
		window.rpc = rpc
	}
})()
