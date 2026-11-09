# BSS globals (`2000_BSS`)

The Ghidra project names the BSS block `2000_BSS`.  The ten globals used by the
recovered in-game code are named; the rest are still `DAT_2000_xxxx`.

## Named in Ghidra

| offset | name | evidence |
|---|---|---|
| `CA95` | `GUnits` | `stshAlloc(0x2A30)`, stride-9 unit records |
| `CA99` | `GUnitCount` | starts at `0xF8`, grows when units are added |
| `D1E6` | `GLeaderCount` | loop bound for leaders/entities |
| `D19F` | `GMenuGfxOfs` | offset of menu/title RLE bitmap |
| `D1A1` | `GMenuGfxSeg` | segment of menu/title RLE bitmap |
| `CA91` | `GPopulationLo` | low word of the 32-bit population counter |
| `CA93` | `GPopulationHi` | high word of the population counter |
| `CB0D` | `GUnitGrid` | `0x4560` bytes, rows `0x78`, 2-byte entries |
| `CB09` | `GMapFlags` | `0x4560` bytes, rows `0x128`, 2-byte entries |
| `CA90` | `GGameInProgress` | set to 0 by init; menu uses it for Begin Play |
| `D3CA` | `GPromotableCount` | reset/counted each season; printed as "to promote" |
| `D1E8` | `GCanPromote` | gates the promotion UI/actions |
| `D2DF` | `GRecordCount` | count of `0x12`-byte records saved from `SEG_21F2` |
| `D0F7` | `GSavedBlitSeg` | saved `BlitRects[0].seg` |
| `D020` | `GMaxSquare` | maximum map square, `0x1B0` |
| `CFD6` | `GSMaxSquare` | secondary maximum square, `0x24` |
| `CB05` | `GMapCells` | byte per map cell, `0x3B x 0x93`, stride `0x94` |

## Highest-use remaining globals

Counts are references in the clean export (`tmp/export_swept6`).

| refs | offset | observed use |
|---:|---|---|
| 97 | `D2DF` | count of `0x12`-byte records; save/load copies `count*0x12` from `SEG_21F2`; incremented/decremented on add/remove |
| 39 | `CB05` | byte array indexed `row*0x94 + col`; checked during init |
| 38 | `D0F7` | assigned `BlitRects[0].seg`; restored around blits |
| 37 | `D1E4` | draw-mode byte, used together with `D1E5` |
| 32 | `CA6F` | `main` sets it to 1 early |
| 30 | `CEB6` | 16-bit array indexed by sprite/file id, passed to `blitGfxRect` |
| 29 | `D020` | init/debug counter, printed as "NEW MAXSQUARE" |
| 29 | `CFD6` | init/debug counter, printed as "NEW SMAXSQUARE" |
| 24 | `D19D` | compared against 2 during init |
| 23 | `D10A` | lower bound in a `[D10A, D10A+0xF]` range test |
| 22 | `CCAF` | font initialization sets it to 0 |
| 20 | `D1E5` | draw-mode byte, `0/1/2` selector with `D1E4` |
| 20 | `CE6E` | 16-bit array indexed by file id, compared to `0xEF` |
| 18 | `CFFC` | 16-bit array filled by init |
| 18 | `D167` | zeroed by init |
| 15 | `D310` | zeroed by init |
| 15 | `D2E6` | set to 2 by init |
| 15 | `CA6E` | compared with `AgntCount` |
| 14 | `D2E8` | `stshAlloc(0x6541)` handle |
| 11 | `CF8E` | 16-bit array filled by init |
| 11 | `CEFE` | 16-bit array filled by init |
| 11 | `D3C6` | zeroed by init |
| 11 | `D090` | set to 2 by `constr_36ce_306b` |
| 11 | `D224` | 16-bit array indexed in `manage_4d05_056e` |

These need semantic names derived from the owning subsystem, not guesses.
The next pass should start with `D2DF` (record count) and the `CE6E`/`CFFC`/
`CF8E`/`CEFE` init arrays, because they are used by save/load and init and can
be cross-checked against the file layout.
