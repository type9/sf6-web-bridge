# Findings

Everything verified against a live game goes here, with the date, the game build and how it was checked. Unverified beliefs go under **Open questions** at the bottom, never in the verified sections. When a game patch changes something, keep the old entry and add a dated correction.

Conventions: object paths are written from a managed singleton, `.` for fields, `[]` for list or array access, `()` for methods.

## 2026-10-19 — Street Fighter 6 (Steam), REFramework v1.5.9.1, plugin API 1.10, TDB 71

Checked by the operator from a browser console on the P2 side of Training Mode, using plugin v0.1.2.

### Bridge mechanics

| what | result |
|---|---|
| browser → `ws://127.0.0.1:47821` from an https page | works in Firefox and Chrome; no mixed-content block, no preflight |
| `hello` + pairing code | works |
| `training.summary` | `inTraining: true`, fighter IDs read, 35 fighter entries in the record list |
| `method.call` with an `int` argument (`List.get_Item(10)`) | works, so primitives are passed by value in the argument slot |
| `field.get` on an inline struct (`SlotData.Title: System.Guid`) | returns a value-type handle |
| `array.get` on `System.UInt16[]` via `Get(int)` | works, 226 and 330 elements |
| `array.set` on `System.UInt16[]` via `Set(int, ushort)` | works; the game played the edited recording |
| plugin load | failed once right after download, loaded on the next launch; consistent with an antivirus first-run scan |

### Managed array layout

From `mem.peek` on `SlotData[]` (8 elements of a reference type):

```
0x00  object info pointer
0x08  reference count etc.
0x10  contained type pointer
0x18  1            (dimensions?)
0x1C  8            element count
0x20  elements start (pointers for reference types, inline for value types)
```

So `length` lives at `0x1C` and data at `0x20`. Not yet used by any op; `array.get` goes through `Get` for safety. A raw fast path for the frame stream can use this once it is double-checked on a value-type array.

### Training Mode object paths

```
app.training.TrainingManager                      managed singleton
  ._tData                                         app.training.TrainingData
    .SelectMenu.PlayerDatas[i].FighterID          int; i = 0 player, 1 dummy
    .RecordSetting                                TM_RecordSetting
      .FighterDataList                            List<TM_RecordSetting.FighterData>, index = FighterID
        [fid].FighterID                           int
        [fid].RecordSlots                         TM_RecordSetting.SlotData[8]
          [n].IsActive                            bool
          [n].IsValid                             bool
          [n].Weight                              int
          [n].Frame                               int   frames recorded
          [n].Title                               System.Guid (inline)
          [n].InputData                           TM_RecordSetting.RecordData
            .Num                                  int   frames recorded (== Frame)
            .buff                                 UInt16[3600]  one input mask per frame, 60 s capacity
```

Fighter IDs seen: 19 (player), 10 (dummy). The community mod's roster table says 10 = Ken, 19 = Ed; unconfirmed from our side.

### Input mask (per frame, `UInt16`)

Recorded on the P2 side, so "forward" is toward P1.

| bit | value | input |
|---|---|---|
| 0 | 1 | up |
| 1 | 2 | down |
| 2 | 4 | back |
| 3 | 8 | forward |
| 4 | 16 | LP |
| 5 | 32 | MP |
| 6 | 64 | HP (inferred from the pattern) |
| 7 | 128 | LK (inferred) |
| 8 | 256 | MK (inferred) |
| 9 | 512 | HK |

Diagonals and multi-button presses are presumably ORed; not yet recorded. Bits 10+ unknown (Drive Impact / Parry macros are candidates). The community mod's table (`LP = 1 … PARRY = 0x80`) is wrong for this build.

Evidence: a recording of "hold forward, tap LP, MP, HK" read `8×50, 0×12, 16×7, 0×20, 32×8, 0×30, 512×7`; a recording of "up, down, back, forward" read `1×32, 0×48, 2×25, 0×74, 4×31, 0×48, 8×28, 0×44`. Swapping 1↔2 and 4↔8 in place made the dummy play the mirrored sequence.

## Open questions

- Whether `FighterID` values match the community roster table.
- Bits 10 and up of the input mask (DI, parry, throw macros, taunt).
- Whether a slot needs more than `Num`, `Frame`, `IsActive`, `IsValid` to become playable when written from empty; the in-place edit kept the game's own metadata.
- Array allocation: plugin API 1.10 has no `create_managed_array`, so filling an empty slot whose `buff` is null needs another route (reuse a recorded slot's buffer, or a game method that allocates).
- Reversal settings, dummy settings and gauges: the community mod's field names (`GuardSetting.DummyData.GuardType`, `DefenseSystem.DummyData.QS_Type`, …) are unverified here.
- Replay lookup by code and friend requests by user ID: singletons not yet identified (candidates from the mod: `app.BattleReplayDataManager`, `app.BattleWatchManager`; network side unknown).
- `System.String` layout (length at `0x10`, UTF-16 at `0x14`) has not been exercised yet; no string field was read.
