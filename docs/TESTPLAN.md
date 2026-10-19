# Test plan

Run from the dev page (`/dev/sf6-bridge` on a dev deploy of the web app) with the latest plugin release installed. Each test says what to do, what should happen, and what to paste back. Do them in order; later ones use what earlier ones proved. Paste the log entries as text, newest first is fine.

Setup, once:

1. Install the plugin DLL into `Street Fighter 6\reframework\plugins\`.
2. Launch the game, go to Training Mode. Pick any character; the dummy can be anyone.
3. Open the dev page. The chip should read **Connected, not paired** within a few seconds.
4. Click the code field and paste: the plugin put the pairing code on the clipboard at launch. Click Pair. Chip reads **Paired**.

If the chip reads **Unreachable**: the plugin did not load. Check `reframework_log.txt` for `[sf6-web-bridge]` lines and send them.

---

## T1 — Pairing flow

Do: reload the page.
Expect: chip goes straight to **Paired** without retyping.

Do: click **Forget code**, then enter `ZZZZZZ` and Pair.
Expect: an error line "wrong pairing code"; chip stays **Connected, not paired**. Paste the real code again to re-pair.

Do: quit the game.
Expect: chip goes to **Not connected** or **Unreachable** within a few seconds. Relaunch the game, click Connect, paste the new code (it changes every launch).

Paste back: just "T1 ok" or what differed.

## T2 — Remaining input bits

Do: in Training Mode, Record into slot 1: tap HP, wait a beat, tap LK, wait, tap MK. Stop recording. On the page click **Read slot 1**.
Expect: three short runs separated by `neutral`. HP should read `hp`, LK `lk`, MK `mk`. If any shows as `bitN` or as another name, the inferred bits were wrong.

Do: Record into slot 2: hold up-forward about half a second, then up-back, down-forward, down-back. **Read slot 2**.
Expect: `up+forward`, `up+back`, `down+forward`, `down+back` runs.

Do: Record into slot 3: Drive Impact (HP+HK), wait, Drive Parry (MP+MK), wait, throw (LP+LK), wait, LP+MP together. **Read slot 3**.
Expect: either the two buttons named together (`hp+hk`) or an extra `bit10`, `bit11`… if the game stores macros as their own bits.

Paste back: the three "slot N:" blocks from the panel.

## T3 — Fill an empty slot (the drill-sharing write path)

Do: make sure slot 1 has a recording (any of the above) and slot 5 is empty (never recorded this session; if unsure, pick a fresh character for the dummy). Click **Clone slot 1 → slot 5**.
Expect, in the log, in this order:
- `clone: source` with the slot 1 inputs
- `clone: target before` with `buff: null` (if it shows a buffer handle instead, the game pre-allocates; still fine)
- `array.create` then `field.set buff`, or `clone: buffer` reusing the game's
- `array.set` with "frames written and read back"
- `clone: fields` with every field echoing its new value
- `clone: done`

Then in the game: open the Record menu, select slot 5, play it.
Expect: the dummy performs slot 1's recording. If slot 5 shows as empty in the menu, note whether it is greyed out, has a blank name, or is missing entirely; that tells us which of the mod's extra steps (`Title` GUID, `SaveCount`) matter.

Also do: reset training (Select) and play slot 5 again.
Expect: still plays, no crash. This is the case that crashed the community mod before they pinned the buffer.

Paste back: the clone log entries and what the game did on both plays.

## T4 — Dummy settings, which field is which

Do: click **Snapshot dummy settings**. Then in the training menu change **Block** (e.g. to All Guard) and click **Diff dummy settings**.
Expect: one line like `GuardSetting.GuardType:Int32: 0 → 1`. Note the name and both values.

Repeat for: Block Count, Switch Block, Recovery, Throw Escape, Drive Reversal, Counter Hit, Dummy Behavior (stance). One change, one diff each time.
Expect: each produces one or two changed lines. "no field changed" means the setting lives somewhere else than the mod said.

Paste back: every diff line with the menu setting it came from.

## T5 — Types for the docs

Do: click **Describe training types**.
Expect: six log entries (TrainingData, RecordSetting, FighterDataList, FighterData, SlotData, RecordData) listing fields and methods.

Paste back: all six, whole. They go into `docs/dumps/`.

## T6 — Where replays and friends live

Do: from Training Mode, click **Snapshot singletons**. Back out to the main menu, open the replay browser, search any replay code, and leave the result on screen. Click **Diff singletons**.
Expect: a short "added" list; those are the replay-related managers.

Do: snapshot again, then open the friend / player search, search a user ID, and diff.
Expect: another short "added" list.

Paste back: both diff entries, whole. That is the starting point for replay-by-code and add-by-user-ID.

---

What to send for anything that fails: the log entry text (it names the op and the object), and what the game showed. If the page itself errors, the browser console's first red line.
