// Pasteable exploration helper: defines window.rpc and a few shortcuts
// for poking at the game from a browser console. Set CODE, paste, then:
//
//   await rpc("singletons.list")
//   const tm = await rpc("singleton.get", { name: "app.training.TrainingManager" })
//   await describe(tm)              // fields and methods, compact
//   await path(tm, "_tData.SelectMenu.PlayerDatas")
//   await peek(tm, 64)
//
// Every handle you receive stays valid until the game closes or you call
// rpc("handle.release", { h }).
(() => {
	const CODE = "XXXXXX"
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
	window.rpc = rpc
	window.isRef = (v) => v && typeof v === "object" && "h" in v
	window.describe = async (ref, { methods = true } = {}) => {
		const d = await rpc("object.describe", { h: ref.h })
		console.log(d.type + (d.parent ? " : " + d.parent : "") + (d.valuetype ? " (value type)" : "") + " size " + d.size)
		console.log("fields\n  " + d.fields.map((f) => (f.static ? "static " : "") + f.type + " " + f.name + " @" + f.offset).join("\n  "))
		if (methods) console.log("methods\n  " + d.methods.map((m) => (m.static ? "static " : "") + m.returns + " " + m.name + "(" + m.params.map((p) => p.type + " " + p.name).join(", ") + ")").join("\n  "))
		return d
	}
	window.path = async (ref, dotted) => {
		let cur = ref
		for (const part of dotted.split(".")) {
			if (!window.isRef(cur)) throw new Error('"' + part + '" reached a non-object: ' + JSON.stringify(cur))
			cur = await rpc("field.get", { h: cur.h, name: part })
		}
		return cur
	}
	window.peek = async (ref, size = 64) => {
		const { bytes } = await rpc("mem.peek", { h: ref.h, size })
		console.log(bytes.match(/.{1,32}/g).map((row, i) => (i * 16).toString(16).padStart(4, "0") + "  " + row.match(/.{2}/g).join(" ")).join("\n"))
		return bytes
	}
	ws.onopen = async () => {
		console.log("hello", await rpc("hello", { code: CODE }))
		console.log("rpc, describe, path, peek, isRef are on window")
	}
})()
