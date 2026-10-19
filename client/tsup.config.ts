import { defineConfig } from "tsup"

export default defineConfig({
	entry: { index: "src/index.ts", react: "src/react.ts" },
	external: ["react"],
	format: ["esm"],
	target: "es2022",
	platform: "browser",
	dts: true,
	sourcemap: true,
	clean: true,
})
