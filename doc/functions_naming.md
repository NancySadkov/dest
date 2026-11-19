# Function naming

All 1590 functions now carry a unique, address-free name.  The address is still available in
every exported C file (`// <name> @ <addr>  [<module>]`) and in `doc/functions_renamed.tsv`,
which records the old name, the new name and the evidence for each rename.

## Rules used

Names are derived only from evidence in the function itself, in this priority order:

| tier | condition | name shape | count |
|---|---|---|---|
| R1 | tiny body whose only call forwards the arguments | `<target>_entry` | 6 |
| R2 | the body references a string literal | `<module>_text<Slug>` | 105 |
| R3 | tiny body that stores one constant into a named global | `<module>_<verb><Global>` | 0 |
| R4 | calls a semantically named function | `<module>_uses<Callee>` | 198 |
| R5 | exactly one semantically named caller, small body | `<caller>_<mechanic>` | 2 |
| R6 | touches named global state | `<module>_uses<State>` | 149 |
| R7 | none of the above | `<module>_<mechanic><n>` | 111 |

`<mechanic>` is the body shape: `copy`, `fill`, `scan`, `loop`, `dispatch`, `compute`, `test`,
`body` (no statement left after the prologue).  `R7` names are **provisional**: they say what the
function mechanically does and which module it belongs to, and make no claim about game meaning.
They are the correct next target for a second pass now that every function is addressable by
name.

The verbs used by R4/R6 (`uses`) are deliberately relational: `draw_usesFillRect` states that the
function calls `fillRect`, not that it is a rectangle filler.  The earlier draft used
`draw_fillRect`, which read as a semantic claim and was rejected for that reason.

## Naming the overlay gates

460 functions are Ghidra thunks.  `RenameFunctions` renames every thunk called
`ovr_<oldTarget>` to `ovr_<newTarget>` whenever a target is renamed, so the gates always name
their target.  Twenty-one duplicate names were produced by that (ten gates pointing at the same
target) and were disambiguated with an address-order suffix (`ovr_agnt_compute16_2` ... `_10`).

## What this buys

- Every call site in the export now reads as a name: `draw_usesFillRect`, `xms_usesXmsHandle`,
  `driver_unrleSprite`, `createConstructionRecord`.
- Searching for a behaviour is possible: `grep _uses_`, `grep text`, `grep unrle`.
- The mapping ledger keeps the old names, so earlier analysis notes stay traceable.

## Verification

```
ListFuncs.java  -> functions 1590, thunks 460, duplicates 0, address-shaped names 0
AuditNaming     -> parameters 1642/937, locals 692/152, fields 313/27, globals 2533/572
verify_param_names.py -> checked 71 failures 0
ExportAll       -> 1124 ok, 6 batch failures (all decompile on demand, see below)
```

Batch-export failures are a decompiler-batch limitation, not damage: `rle_line`,
`manage_body1`, `constrct_body1`, `ovc49_body1` and `ovc45_usesClose` were already failing
before the rename, and the two new ones (`ovc41_textFailsTurn`, `init_assets`) decompile on
demand to 152 and 2854 lines respectively.

## Second pass: functional names for the generated class

The R4/R7 names above are mechanical by construction (`<module>_uses<Callee>N`,
`<module>_<shape>N`).  They are still 839 of the 1590 functions: `uses*` 519, `text*` 158,
`compute*` 131, `scan*` 11, `loop*` 10, `body*` 6, `fill*` 2, `copy*` 2.  The second pass replaces
them only where the body states the functionality, starting with the two that were flagged.

| old | new | evidence |
|---|---|---|
| `ovc43_textToymaker` | `ovc43_playFli` | it opens archive entry `0x184`, and `StshNames[388]`
is `strong.fli`; it then hands the handle to the frame loop below with a palette and closes it.
`run_demo` calls it once, right after the panel graphics and palette are set up, i.e. the intro
movie |
| `agnt_usesAgntCount3` | `agnt_remapGridRefs` | the caller memcpy's `Agnts[agntIndex]` into
`Agnts[iVar6]` and memmoves the block between them down; this function then rewrites both
`10 x 0x69` index grids (bases `Agnts+0x8fa` and `Agnts+0x4e0`, entries are agentIndex+1): every
value in `(from, to]` decrements and `from+1` becomes `to+1` |

Verified live: `ovc43_playFli(uint16_t fileId, undefined2 paletteOfs, undefined2 paletteSeg)` and
`agnt_remapGridRefs(uint fromIndex, int toIndex)`; ListFuncs still reports 1590 functions, 0
duplicates, 0 address-shaped names, and the thunk `ovr_ovc43_textToymaker` was renamed with its
target by `RenameFunctions`.

### `ovc49_body1` is a 150-byte dispatcher, not an insanely large function

The batch export fails on it with a 60 s decompile timeout, and a forced decompile produced 3020
lines that include the whole `init_assets2` sprite builder.  That looked like a monster function;
it is not.  `BodySegs.java` shows the body is a **single 150-byte range**
`8699:18c4 - 8699:1959`, and every path in it ends with a tail jump to an **unmapped** segment:

```
8699:18fc  CMP byte ptr ES:[BX + 0x24],0x1     ; agnt_t+0x24 combatState
8699:1901  JZ  0x8000:8296
8699:1903  JMP 0x8000:83c2
...
8699:1942  JMP 0x8000:830f
8699:1958  JMP 0x8000:830f                    ; SI = 0 / 1 / 2 per branch
```

0x8000 is not a memory block in the program (`Could not follow disassembly flow into non-existing
memory at 8000:f633`), so the decompiler follows those jumps into whatever it maps them to and
pulls unrelated overlay code into the result.  The 150-byte body is a **state dispatcher**: it
loads the agent's frame table (`+0x13`), computes a table index through `agnt_compute2(x)`, and
selects a tail-jump target (and SI = 0/1/2) from `combatState`, `flags & 2`, `animVariant` and
the movement bytes.  Naming it needs the 0x8000 overlay segment mapped, not a bigger timeout.
`TrimSeg.java` (keep only the entry segment) and `BodySegs.java` (print body composition) are the
tools for that pass; `SliceDecompile.java` restricts the body to a byte range when a real monster
turns up.

### Second batch of functional names (5 total in this pass)

| old | new | evidence |
|---|---|---|
| `video_copy1` | `video_copyScreenTile` | copies a tile of at most `0x11 x 0x11` pixels from
segment `srcSeg` at `x + y*0x140` into the staging segment `0x224a`, clamping
`w = min(0x140-x, 0x11)` and `h = min(200-y, 0x11)` |
| `font_loop1` | `font_textWidth` | sums `font[ch + 0xa1]` over every character of the string
(0 for a null string), i.e. the pixel width of the text in that font |
| `ovc43_usesBiosKeyAvail` | `ovc43_playFliFrames` | the frame loop behind `ovc43_playFli`: it
allocates a `0xfa0f`-byte (320x200 + header) buffer, presents one frame per iteration through
`ovc43_usesStExit` with the palette, waits `param_4` timer ticks, and returns 1 on ENTER/mouse or
2 on ESC |

So `ovc43_playFli` (open + close) now calls `ovc43_playFliFrames` (the loop), which reads the way
the code does.  Refused in the same pass: `ovc15_loop1` (writes 0xff down a 10-row column of the
`+0x8fa` grid, but what 0xff means for that grid is not stated), `ovc42_copy1` (a palette move
plus a screen-index remap whose base segment the decompiler lost), `ovc25_scan1`,
`saveui_scan1`, `manage_loop1`.

ListFuncs after the batch: 1590 functions, 0 duplicates, 0 address-shaped names, 460 thunks.

### Third batch: one more functional name

| old | new | evidence |
|---|---|---|
| `video_usesAgntCount` | `video_findAgentAt` | walks `Agnts` and returns the first agent whose
sprite bounds contain a screen point (`screenX +/- sprite width - 0xc`, `screenY +/- sprite
height - 7`), or -1.  Parameters `x`, `y` |

### Fourth batch: the settlement screen

| old | new | evidence |
|---|---|---|
| `manage_body1` | `manage_settlementScreen` | the body draws `Housing`, `jeweler`,
`money dealer's shop` and lists buildings with `"%s: %s %d gold. Feeds %d %s."`,
`"Buildings belonging to %s%s"`, plus the `Census`/`Property`/`Auto-build`/`Next Leader` options;
its parameter is the party-slot byte used to index the party-sheet pointer table |

### Fifth batch

| old | new | evidence |
|---|---|---|
| `ovc22_loop1` | `ovc22_searchCellsAround` | expanding-ring search (radius 1..0x94, four sign
combinations) that returns the first cell passing the requested occupancy/flag/arena checks and
writes its coordinates through the out pointers; sets bit 2 at `sheet+0x5d` when none is found |

### Sixth batch

| old | new | evidence |
|---|---|---|
| `constrct_body1` | `constrct_buildInfoText` | 35 `fmVsprintf` + 33 `stshRealloc` + 32 `strcpy`
and the building-description format strings it pushes (`"%s: Costs %d gold. Enhances training by
%d%%."`, `"... Provides housing for %d %s."`, `"... Owned by %s. ..."`); no drawing calls, and it
indexes the unit table with stride 0x37 |

### Seventh batch (disassembly-based)

Three short bodies read directly from `DumpAsmNamed`, all with unambiguous logic:

| old | new | evidence |
|---|---|---|
| `manage_loop1` | `manage_statSelectable` | `if (sheet->stats[statIndex] < 0x12) { for i in 0..2
if (sheet->stats[i] > 0xa && i != statIndex) return 1; } return 0;` and its only caller
(`abilitiesDlg`) appends the stat to `menuItems` only when the result is non-zero |
| `saveui_scan1` | `saveui_parseNumber` | walks the string, skips non-digits through the CRT
`_ctype` table (`ES:[BX+0x8519] & 2`), and accumulates `value*10 + (ch - '0')` until the NUL |
| `ovc15_loop1` | `ovc15_fillGridColumn` | clamps `arg >> 1 < 0x69` and writes `0xff` to all ten
rows of that column in the agent grid at `Agnts+0x8fa` (stride 0x69) |

### Eighth batch

| old | new | evidence |
|---|---|---|
| `ovc49_fill1` | `ovc49_fillGridCells` | computes `row = clamp(agnt->y >> 1, 0, 7)` and
`col = clamp(agnt->x - spriteWidth/2, 0, 0x68)`, then memsets `count` bytes at `Agnts+0x8fa` and
`+0x963` when `animVariant == 0`, or at `+0x4e0`, `+0x549` and `+0x5b2` otherwise -- the same
agent-index grids `agnt_remapGridRefs` rewrites |

Its second parameter is now typed and named `agnt_t *agnt`: the body reads `x` (+0), `y` (+2),
`frameIndex` (+0x12), `frames` (+0x13) and `animVariant` (+0x11), and the callers pass `&Agnts[i]`.

### Ninth batch

| old | new | evidence |
|---|---|---|
| `driver_scan3` | `driver_setMapFlagsRect` | every caller passes `GMapFlags` and a rect
(`0,0,0x93,0x3b` = the whole 148x60 map); the address is `buf + x1*2 + y1*0x128` (0x128 = 296 =
148 words, the map-flag row stride) and the loop ORs every word with the mask |
| `driver_scan4` | `driver_clearMapFlagsRect` | same body with `&= mask` |
| `ovc25_scan1` | `ovc25_findUnitCell` | expands square rings from the start cell (radius 0..99,
offsets 0..radius, both signs), tests each candidate with `attact_usesGUnits`, and on a hit writes
the coordinates back through the two pointers and returns 1 |

Refused in the same pass: `ovc38_scan1` (parses a decimal after an `@` marker in a message and
compares it against `strongholdsDestroyed`, but the message format is not stated anywhere in the
export) and `driver_scan1` (its remaining slots are CRT register values and a `pattern._2_2_`
artifact).

### Tenth batch

| old | new | evidence |
|---|---|---|
| `ovc45_usesLand_info` | `ovc45_showLandInfo` | hit-tests the point with
`video_compute1(screenX, y)`; inside, it maps `x` to a tile column with `(x - 9) / 0x30` and calls
`land_info(column)`, returning 1 -- the hover handler for the land-info popup |
| `ovc15_usesAgntFlag1` | `ovc15_removeEntity` | kills the entity's agents (`combatState = 2`,
`targetY = 0`) when `AgntFlag1` is set, memmoves the `Entities` tail down over the record,
decrements every agent `owner` above it and re-points those agents' entity pointer, then
`EntityCount--` |

### Eleventh batch

| old | new | evidence |
|---|---|---|
| `ovc49_usesBlitGfxRect` | `ovc49_drawAgents` | the body has three loops over `AgntCount`; per
agent it fills the grid cells (`ovc49_fillGridCells`), runs the paralysis/AI check
(`ovc49_textLongerParalyzed`), calls the state dispatcher (`ovc49_body1`) for the animation index,
resolves the animation record and sprite, and draws it with `blitGfxRect`; it also derives
`BothFactions` from the per-faction presence table and sets `GGameState = 0x2d` |

Refused in the same pass: `ovc18_textBathHouse` -- its body derives a gindex from the party
sheet's `classStr`, tests `AgntGs[cls].flags & 0x800`, picks one of 6/19/25 and calls the spawn
routine `ovc15_usesLDIV_at_`, so it is a class-based spawn helper, but the "bath house" string
that named it is not explained by the body and the callers pass six packed arguments whose roles
are not settled.

Two more parameter scans came back empty, which is the evidence that the cheap slots are gone:
auto params used as an index into a named array (`Entities`, `Agnts`, `GUnits`, `AgntGs`,
`AgntAnms`, `GStructures`): 0 hits; auto params stored into a named struct field:
0 hits.

### Twelfth batch

| old | new | evidence |
|---|---|---|
| `manage_usesStop_audio` | `manage_showSettlementScreen` | stops the agents/ring buffer and the
music (`CurMusicType = 0xff`), saves `GMenuItem`/`MenuMode`, sets `TextBlitDstSeg = 0xa000`, calls
`manage_settlementScreen(CONCAT11(0x24, partySlot))`, then restores the menu when `Cancelled` is
clear.  Its parameter is the party slot handed to that screen |
| `ovc18_textBathHouse` | `ovc18_spawnClassAgent` | derives a gindex from the party sheet's
`classStr` (`sheet+0x3e`), tests `AgntGs[cls].flags & 0x800`, selects one of 6/19/25 (or a
`randBelow(5)` case) and calls the spawn routine `ovc15_usesLDIV_at_`.  The `"bath house"` string
does not describe the body |

### A prototype change made and reverted

The entry code uses six stack slots (`[BP+6]`, `+8`, `+0xa`, `+0xc`, `+0xe`, `+0x10`) and the
party-sheet index is the last one, so the stored five-parameter prototype is shifted.  I set
`(int x, int y, int destX, int destY, byte mode, byte partyIndex)` and decompiled: `mode` and
`partyIndex` then read correctly (`mode < 6`, `mode < 0xb`, `partyIndex << 2` + `0x3e`), but the
body also dereferences the second slot as an `anm_t` array (`anims[i].frmid`, `.fw`, `.fh`,
`.nframes`, `anims._2_2_`), which only makes sense if that slot is an `anm_t` far pointer -- and
`DI` is reassigned before the spawn call.  So the mapping is not the simple six-argument order;
the original prototype was restored and the layout recorded as unresolved.

### Thirteenth batch (short bodies read in bulk)

I enumerated the 323 functions whose names are still mechanical and whose decompiled bodies are
short, and read the smallest ones.  Five state their functionality unambiguously:

| old | new | evidence |
|---|---|---|
| `init_usesGMapCells3` | `init_setMapCell` | `(*(byte (*)[59][148])GMapCells)[y][x] = cell`
guarded by `0 <= x < 0x94`, `0 <= y < 0x3c` |
| `ovc13_compute1` | `ovc13_readPixel` | returns `*(byte *)(screenX + screenY*0x140)` packed with
the high byte of the offset; the third argument is unused |
| `ovc15_usesAgntCount` | `ovc15_clearVisited` | loops every agent and writes 0 to `agnt_t+0x2d`
(`visited`) |
| `saveui_usesWrite` | `saveui_writeLine` | writes the text when non-empty, then `write(handle,
"\r\n", ...)` |
| `manage_usesBlitLabel` | `manage_blitLabelRight` | measures the text with `font_textWidth`, sets
`TextBlitX = x - width`, then blits -- right-aligned at `x` |

Refused in the same batch, with the reason: `ovc45_compute6` (`return param_1 != 1;` -- a bare
predicate), `ovc45_compute7` (`(a*b)>>3` fixed-point multiply), `bldng_usesGStrangeTable` and
`bldng_usesRandBelow` (table lookups whose meaning is in the table), `saveui_usesBlitLoadRleGfx4`
(draws the font handle at a fixed address), `ovc15_usesToupper` (uppercases only the first
character), `ovc41_compute9` and `stats_compute5` (their meaning depends on callees that are
themselves unresolved), and `manage_usesBlitLabel2` (an identical twin of the one renamed -- left
unnamed rather than forced into a numeric suffix).
