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
            .buff                                 UInt16[3600] once recorded; an UNTOUCHED slot holds a UInt16[0], not null
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
| 6 | 64 | HP |
| 7 | 128 | LK |
| 8 | 256 | MK |
| 9 | 512 | HK |

All ten bits verified. Diagonals are ORed directions (`up+back` = 5). Drive Impact, Drive Parry and throw are stored as their two buttons ORed (`hp+hk`, `mp+mk`, `lp+lk`); no bits above 9 appeared. The community mod's table (`LP = 1 … PARRY = 0x80`) is wrong for this build.

Evidence (second session, same day): HP/LK/MK taps read `hp ×4, lk ×5, mk ×6`; the four diagonals read `up+back, down+back, down+forward, up+forward` with one-frame single-direction edges on entry; DI/parry/throw read `hp+hk ×4, mp+mk ×9, lp+lk ×6`. First session: a recording of "hold forward, tap LP, MP, HK" read `8×50, 0×12, 16×7, 0×20, 32×8, 0×30, 512×7`; a recording of "up, down, back, forward" read `1×32, 0×48, 2×25, 0×74, 4×31, 0×48, 8×28, 0×44`. Swapping 1↔2 and 4↔8 in place made the dummy play the mirrored sequence.

### Dummy settings (verified 2026-10-19 by changing one menu row at a time and diffing)

All under `app.training.TrainingManager._tData`. Each line is the field that moved when the named menu row was changed by one step, with the label the menu showed at the new value.

| menu row (Dummy Settings) | field | type | observed |
|---|---|---|---|
| Dummy Behavior | `DummyStatus.DummyData.DummyActionType` | `app.training.TM_DS_DUMMYTYPE` | 0 → 1, shown "Standing" |
| Counter | `CounterSetting.DummyData.NC_TYPE` | `app.training.TM_COMMON_TYPE` | 0 → 1, "Always Counter" |
| Block | `GuardSetting.DummyData.GuardType` | `app.training.TM_GS_GUARD_TYPE` | 3 → 5 on one step, "Block Count" (the enum has values the menu skips) |
| Block Count | `GuardSetting.DummyData.GuardCount` | `System.Int32` | 2 → 3, menu shows 4 (display = stored + 1) |
| Switch Block | `GuardSetting.DummyData.GuardOnlyType` | `app.training.TM_GS_ONLY_TYPE` | 0 → 1, "Standing Block Only" |
| Block Type | not found in these four objects | | no diff; may live elsewhere or was unchanged |
| Drive Reversal | `DefenseSystem.DummyData.DR_Type` | `app.training.DRIVE_REVERSAL_TYPE` | 0 → 1, "On Block" |
| Drive Reversal Activation Delay | `DefenseSystem.DummyData.DR_DelayFrame` | `System.UInt32` | 0 → 1, "1F" |
| Drive Reversal Activation Count | `DefenseSystem.DummyData.DR_DelayCount` | `System.UInt32` | 0 → 1, menu shows 2 (display = stored + 1) |
| Throw Escape | `DefenseSystem.DummyData.GD_Type` | `app.training.TM_COMMON_TYPE` | 0 → 1, "Active" |
| Recovery | `DefenseSystem.DummyData.QS_Type` | `app.training.TM_DS_QS_TYPE` | 1 → 2, "Random" |

Corrections to the community mod: Switch Block is `GuardOnlyType` (the mod used `IsGuardSwitching` for it and `GuardOnlyType` for Block Type); Throw Escape "Active" is 1, not 0; Dummy Behavior "Standing" reads 1 where the mod has Stand = 0. Full label lists come from the enums' static members (dev page: "Enum values"); record them here when dumped.

## Inferred from the community drill mod — NOT verified by us

The "SF6 Drill Share" REFramework Lua mod (`sf6_training_share.lua`, `sf6-training-drill-share/action_record_io.lua`) fills record slots, including empty ones, like this. Its authors mark several of their own field names as unverified; treat every line below as a hypothesis to smoke-test, one write at a time, and move each line up into the verified section with a date once it has been seen working.

Filling a slot (`RecordSlots[n]`), in the mod's order:

1. If `InputData.buff` is null or shorter than the recording, allocate a new `System.UInt16[]` of `max(frames, 3600)`, pin it (`add_ref_permanent` in Lua), and store it into `InputData.buff`. The mod notes that an unpinned buffer was freed by the GC and crashed the game on the next training reset. Our equivalent: `array.create {element: "System.UInt16", length: 3600}` (pinned) followed by `field.set {h: inputData, name: "buff", value: {h: newArray}}`.
2. Write the slot: `IsActive` (bool), `IsValid` (bool, true when frames > 0), `Weight` (int, 1 if 0), `Frame` (int, frame count).
3. Write `Title` (`System.Guid`, inline). An all-zero GUID shows an empty name in the menu; the mod writes a constant GUID for every active slot: `mData1 = 231974219, mData2 = 56247, mData3 = 18493, mData4_0..7 = 138, 211, 88, 121, 158, 17, 216, 197`.
4. Write `InputData`: `Num` (int, == Frame), `isLoop` (bool), `State` (int; 1 when active or frames > 0), `cmd_type` (int, 0), `negativeEdge` (bool), `Cursor` (int, 0), `IsForceStop` (bool, false), then the masks into `buff[0..Num)`.
5. Bump `TrainingData.SaveCount` by one "to notify the engine". Unclear whether the game needs it.

Other paths the mod uses, all unverified here:

- Dummy settings: see the verified table above; still unverified from the mod's list are `GuardSetting.DummyData.IsGuardSwitching` and `CounterSetting.DummyData.PC_TYPE`.
- Record settings on `RecordSetting`: `RecordType, RecordStartType, RecordCountDown, PlayType, InfoType, LoopType`.
- Reversal lists on `_tData.ReversalSetting.FighterDataList[fid].{DownReversalDatas, GuardReversalDatas, DamageReversalDatas}[0..9]` with fields `Count, Delay, Frame, IsActive, IsFrame, IsValid, Level, SkillIndex, Type`.
- Gauges from the static `gBattle` type: `Player.mcPlayer[i].focus_new` (drive), `Team.mcTeam[i].mSuperGauge` (super).
- Roster: 1 Ryu, 2 Luke, 3 Kimberly, 4 Chun-Li, 5 Manon, 6 Zangief, 7 JP, 8 Dhalsim, 9 Cammy, 10 Ken, 11 Dee Jay, 12 Lily, 13 A.K.I., 14 Rashid, 15 Blanka, 16 Juri, 17 Marisa, 18 Guile, 19 Ed, 20 E. Honda, 21 Jamie, 22 Akuma, 25 Sagat, 26 M. Bison, 27 Terry, 28 Mai, 29 Elena, 30 C. Viper, 31 Alex, 32 Ingrid, 33 Yasmin, 34 Arjun. Our one data point (10 = the operator's dummy, 19 = the operator's character) is consistent with it.

## Open questions

- Whether `FighterID` values match the community roster table.
- Whether a slot needs more than `Num`, `Frame`, `IsActive`, `IsValid` to become playable when written from empty; the in-place edit kept the game's own metadata. An untouched slot's `buff` is a zero-length array (seen 2026-10-19), so filling one always means replacing the buffer.
- Array allocation: plugin API 1.10 has no `create_managed_array`; v0.1.3 adds `array.create` through the game's `System.Array.CreateInstance`, untested.
- Reversal settings and gauges: the community mod's field names are unverified here (dummy settings are now verified, see above). Block Type's field is still unlocated.
- Replay lookup by code and friend requests by user ID: singletons not yet identified (candidates from the mod: `app.BattleReplayDataManager`, `app.BattleWatchManager`; network side unknown).
- `System.String` layout (length at `0x10`, UTF-16 at `0x14`) has not been exercised yet; no string field was read.
