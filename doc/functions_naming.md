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

### Fourteenth batch (two bulk passes over short bodies)

| old | new | evidence |
|---|---|---|
| `ovc41_usesIndexPermD` | `ovc41_initIndexPerms` | four 12-byte `memcpy`s from
`0x2410:6e08/6e14/6e20/6e2c` into `IndexPermD/C/B/A` |
| `attact_compute1` | `attact_decrementCounter` | decrements the byte pointed at while non-zero |
| `ovc28_compute1` | `ovc28_blitMenuEntry` | `blitLabel(0xeb, index*0xe + 0x3c, entries[index])`
for `index < 0xfa`; parameters named `entries`, `index` |
| `ovc15_usesSelectedAgent` | `ovc15_positionCrosshair` | sets `CrossBlitX = agent.screenX`,
`CrossBlitY = agent.screenY - 0x10` for the selected agent |
| `agnt_compute2` | `agnt_clampX` | clamps its argument to `0..0xd2` and returns it |
| `audio_compute2` | `audio_panFromX` | `0x7f - min(x*0x7f/0xd2, 0x7f)`, a pan value from the
agent's x |
| `ovc43_usesStshSeek` | `ovc43_playArchiveFli` | seeks `strong.dat` to the offset at `gfx+3` and
runs the frame player `ovc43_playFliFrames` |
| `ovc07_compute1` | `ovc07_swapWords` | swaps the two 16-bit values (second pointer arrives
packed on the stack; its own `param_2` is unused) |

Refused in the same pass: `ovc25_compute1` (its three reads land on `AgntGs+0x41/0x42/0x43`, which
mix the high byte of the `+0x40` word with `rank`, so the intent is not clear), `ovc22_compute1`
(halves a value when the sheet class is 4), `ovc22_compute3` (`if (v < 0) v += 6`), `ovc45_compute3`
(`sheet+0x56` plus an unresolved callee), `bldng_usesRandBelow` / `bldng_usesGStrangeTable` (table
lookups), `saveui_usesBlitLoadRleGfx4` (font blit at a fixed address), `ovc15_usesToupper`,
`agnt_compute1` and `ovc23_usesGfxRndSeed2`.

### Fifteenth batch: 19 names from the bulk short-body read

Both passes came from the same enumeration (`read_short3.py`): the 114 mechanical-named
functions whose decompiled body is 10-20 lines, read 12 at a time.

| old | new | evidence |
|---|---|---|
| `saveui_usesBlitGfxRect` | `saveui_blitPanel` | blits the panel asset `nwpanel2Cut1` at
(0,0) against `BlitRects+1`; every caller is a save/UI screen (`uiMainMenuLoop`,
`saveui_text...`, `init_copyProt...`) |
| `ovc18_usesBlitLoadRleGfx` | `ovc18_blitTriangles` | blits `trianglsCut4` to
`0xa000:c306` and sets the `byte_2000_BSS_077A` loaded flag |
| `ovc18_usesBlitLoadRleGfx2` | `ovc18_blitPanelIfNotRunning` | blits `nwpanel1Cut4` to the
same screen address, but only while `GameRunning` is 0 |
| `ovc41_usesAnimFrame` | `ovc41_advanceAnimFrame` | increments `entity->base.animFrame`
(`+0x1b`) through the agent's entity pointer |
| `init_usesGUnits` | `init_initGUnits` | initialises all 0xf8 `GUnits` records:
`bldType = index`, `level = 0xff`, `unitType = 0xff` |
| `agnt_compute6` | `agnt_advanceAnimFrame` | calls `agnt_usesAnimFrame` only when bit 2 of the
agent type record's first word (`agntG_t+0`) is clear |
| `ovc31_usesClose` | `ovc31_fileExists` | opens the named file read-only, closes it again and
returns whether the open succeeded |
| `ovc28_usesBlitGfxRect` | `ovc28_blitButton` | blits `button1Cut3` at (223,8) against
`BlitRects+1`, ticks the daily-time counter by 3, then blits the follow-up graphic |
| `agnt_usesAgntCount` | `agnt_isAnimating` | returns true when `AgntCount`, `byte_2000_BSS_08A2`
or `GAnimPlaying` is non-zero -- whether anything is still animating |
| `save_textSsave` | `saveui_saveGame` | builds `"save.%03d"`, opens it, writes the save through
`save_textLoading` and closes it |
| `manage_usesBlitGfxRect2` | `manage_blitTalkWindow` | copies `panelClipRect` into a local rect
and blits `talkwin9Cut1` at (0,0) clipped to it |
| `ovc41_compute1` | `ovc41_pluralSuffix` | returns the DGROUP address of `""` for an argument of
1 and of `"s"` (`0x2410:6e75`) otherwise |
| `ovc41_compute5` | `ovc41_isAre` | returns `"is"` for 1 and `"are"` otherwise |
| `ovc45_usesGUnits` | `ovc45_getUnitType` | returns `GUnits[GUnitGrid[x][y]].bldType` inside the
map bounds, else 0 |
| `ovc45_usesGUnitGrid` | `ovc45_getUnitIndex` | returns `GUnitGrid[x][y]` inside the map bounds |
| `ovc45_textMaintenanceCost` | `ovc45_costOrIncomeLabel` | returns `"Maintenance cost is"` for a
non-positive argument and `"Income created is"` otherwise |
| `init2_usesMiceButton0PressStates` | `init2_updateMouseButtons` | latches the secondary mouse
buttons into two BSS flags and returns bit 0 (primary) |
| `init_usesGMapCells2` | `init_getMapCell` | returns `GMapCells[y][x]` inside the map bounds |
| `constr_usesBlitRaw` | `constr_blitRawToScreen` | retargets the rect segment to 0xa000, restores
the mouse area, blits the rect raw, blits the mouse back and restores the segment |

Refused in the same two passes, with reasons: `ovc41_compute2` (byte-identical twin of
`ovc41_compute1`; left unnamed rather than forced into a suffix), `driver_compute3`/`driver_compute4`
(they write two colours into a 3x2 pixel block at `(ofs, y*0x140)`, but which of the two is the
upper/lower diagonal is not stated), `ovc45_compute2` (`min(sheet+0x87*10, 100)`, a percentage of
an unidentified field), `ovc23_compute2` (`alignUp44(x,y)`, falling back to `x`), `agnt_compute8/9/10/11`
(`(dir % 6)` or `((dir/6) % 6)`, folded to -2..3 -- a direction component whose encoding is not
stated), `agnt_compute14` (an index remap of a value above 8), and `constr_usesGOngoingBattle` (a
two-way choice between two draw paths whose names are themselves mechanical).

### Sixteenth batch

| old | new | evidence |
|---|---|---|
| `video_compute1` | `video_pointInButton` | returns 1 when `(x,y)` falls inside the region
recorded for column `x`: the y range is the word at `(x-0xc)*2 + 0x34c`, with `8 < x < 0xc9`.
Callers pass `MouseX`/`MouseY`, so it is the button hit test |
| `constr_usesGfxRndSeed` | `constr_getCellAtOffset` | reads
`GMapCells[GfxRndSeed2 - dy][GfxRndSeed + dx]` with the map bounds check -- the cell at the
drawing cursor offset by `(dx,dy)` |
| `init_usesGMapFlags2` | `init_getMapFlags` | returns the flag bits of `GMapFlags[y][x]` inside
the map bounds |
| `manage_usesRandBelow` | `manage_rollDice` | rolls `count` dice of `sides` faces, summing
`randBelow(sides) + 1` |
| `ovc25_usesEntityCount2` | `ovc25_clearEntityFlags` | clears the byte at
`Entities[i].base.entity+2` for every entity, then rebuilds the derived table
(`ovc25_usesAlignUp47`) when entities exist |
| `stats_usesBlitGfx10` | `stats_drawStatsPanel` | blits the full-screen stats background at the
origin, then the `nwpanel1Cut3` panel to `0xa000:0adf` |
| `stats_compute6` | `stats_selectAgentAt` | hit-tests the point with `video_findAgentAt` and, on
a hit, opens that agent's stats page (`stats_usesAlignUp42`) |

Refused in the same batch: `ovc49_compute1` (bounds `0..0xd2` then
`*(int *)(param_1 * 2) == 0` with the base segment lost) and `ovc13_usesSeedD1102` (already carries
`x`,`y`, but the `Seed_2000_d110`/`d10e` offset pair it applies to `GMapFlags` has no stated
meaning).

### Seventeenth batch: sheet fields named by the literals that consume them

| old | new | evidence |
|---|---|---|
| `ovc22_textMonster` | `ovc22_className` | reads `char_sheet_t.cls` (+0x2f = 47): for `cls < 7` it
returns the class-name far pointer from the table at `DGROUP:0x123`, otherwise the literal
`"monster"` |
| `ovc39_textLord` | `ovc39_lordOrLady` | first leader with `level` (+0x86 = 134) non-zero, then
`"lord"` when that sheet's `gender` (+0x34 = 52) is 0 and `"lady"` otherwise |
| `manage_usesGLeaderCount2` | `manage_findFirstLeader` | returns the first party-sheet index whose
`level` is non-zero, or `0xff` |
| `bldng_compute1` | `bldng_getClass` | returns the sheet's `cls` byte (0 when it is -1) |
| `ovc07_compute2` | `ovc07_signum` | `-1`, `0` or `1` for a negative, zero or positive argument |
| `init_compute1` | `init_sumMapCells2x2` | sums the four `GMapCells` bytes of the 2x2 block at
(x,y) |
| `ovc23_usesGRecordCount` | `ovc23_removeRecord` | memmoves the 0x12-stride table at 0x21f2 down
over `recordIndex`, decrements `GRecordCount`, refills the view |
| `audio_compute1` | `audio_parseHexDigit` | stores one character as a hex digit
(`c-0x30` for digits, `c-0x37` otherwise) in the driver parameter at `+0x108`, clears `+0x109` |
| `ovc23_usesAlignUp42` | `ovc23_isCursorAt` | 1 when `alignUp4(x) == alignUp4(GfxRndSeed)` and
`y == GfxRndSeed2` |
| `ovc45_usesClose` | `ovc45_buildPlacementMessage` | a 665-instruction body with 10 `strcat` and
8 `stsprintf` calls whose pushed strings are the placement verdicts: `" It will cost %s the %s %d
gp. "`, `"Buildings cannot be placed over water."`, `" Location is too narrow for %s."`,
`" Requires a rank of %s."`, `" Next outpost available at rank %s."`, `" No more outposts are
available."`, `" Walls must be near land."`, `" You can only place a single arena."`, `"
Bridges must be near water's edge."`, `"This location is unsuitable for buildings."` |

The last one was in the decompiler-failure list, so it was read with `DumpAsmNamed` plus the pushed
DGROUP offsets, exactly the recipe used for `constrct_body1`.
Its prototype stays empty because the decompiler never recovered one; the entry code reads
`[BP+6]` (a coordinate, passed through `alignUp4`), `[BP+8]` (a far pointer, kept in `DI`) and
`[BP+0xa]` (an entity index, multiplied by `0x37`).

Refused in the same pass, with reasons: `agnt_usesAgntCount6` (sets `moveState = 1` when it is
below 2 and clears `+4`, but the vocabulary of both fields is unstated), `ovc30_compute1` (buckets
at 5 and 9), `stats_usesEntityCount` (clears `flags32` bit 2 for a party's entities; the bit has no
stated meaning), `season_textMainCastle` (needs `+0x3d` and `+0x3f` both non-zero, which contradicts
the current `active`/`excluded` reading of those bytes -- recorded, not renamed), and
`constr_compute1/2` (choose between `driver_compute1/2` and the constant `0xe2` on a flags bit).

### Eighteenth batch: the save module read end to end, plus 11 more names

Reading `save_textLoading` settled the direction of the whole save module:

```c
uint save_textLoading(int handle) {
  ovr_stop_audio();
  ovr_drawTextAt("Loading...", 0x2410);
  SaveAuto = 0; AgntFlag1 = false; ovr_freeGameResources();
  save_usesRead(handle, local_2a, ..., 0x28);          /* header + magic */
  save_usesRead(handle, GUnitGrid,  ..., 0x4560);
  save_usesRead(handle, GMapFlags,  ..., 0x4560);
  save_usesRead(handle, GMapCells,  ..., 0x22b0);
  save_usesRead(handle, &GfxRndSeed, ..., 2); ...
}
```

It prints `"Loading..."`, frees the resources and **reads** the header, `GUnitGrid`, `GMapFlags`,
`GMapCells`, the RNG seeds and `Entities`.  Its counterpart is the existing `stSave`, which writes
the same block through `save_usesWrite`.

| old | new | evidence |
|---|---|---|
| `save_textLoading` | `stLoad` | the loader described above |
| `saveui_saveGame` (**wrong**) | `save_loadGameFile` | it builds `"save.%03d"`, opens it and calls
`save_textLoading` -- the loader.  The earlier name came from assuming that callee was the writer;
it is not.  Recorded as a correction |
| `save_usesClose` | `save_loadArchiveGame` | opens `StshNames[0]` when its handle is not cached,
seeks to the offset stored at `cred03Cut3Ofs + 3` and runs `stLoad`, closing only if it opened |
| `save_textDeleting` | `save_deleteGameFile` | shows `"Deleting..."`, `unlink`s the `save.NNN`
file and shows `"Delete complete."` |
| `ovc23_usesGUnits` | `ovc23_isLargeBuilding` | maps the cell to `GUnits[...].bldType`, multiplies
by 0x27 and tests `bldtp_t.size` (+0xd = 0x11b from the table base): 1 when `size >= 2` |
| `manage_usesMenuItemEnabled` | `manage_mapPartySlots` | fills `MenuItemEnabled[0..4]` with 0xff,
then for every active leader (`sheet+0x3d`) stores the leader index at
`MenuItemEnabled[sheet+0x89]` -- and +0x89 = 137 = `char_sheet_t.partySlot` |
| `ovc25_compute2` | `ovc25_tickCountdown` | decrements the sheet word at +0x5e while +0x3f and the
counter are non-zero; at 0 it reloads 10 and clears bit 0 of `flags5d` |
| `ovc45_usesGMapFlags3` | `ovc45_cellBelowBlocked` | tests `GMapFlags[y+1][x]` (row stride 0x94
words), i.e. the cell directly below |
| `ovc23_usesAlignUp44` | `ovc23_findClearColumn` | scans `GMapFlags[y][alignUp4(x)+i]`, i = 0..3,
for a cell with clear low flag bits and returns `alignUp4(x)+i-2`, else -1 |
| `ovc13_usesBlitLoadRleGfx` | `ovc13_blitAnimFrame` | while `GMenuFlag` is clear, latches the BDA
tick, cycles `BlitFrame` 0..5 and blits `word_2000_BSS_06E7/06E9[BlitFrame]` to `0xa000:db93` |
| `ovc23_usesGRecordCount2` | `ovc23_findRecordAt` | scans the 0x12-stride records at 0x21f2 and
returns the index whose +4 word is `y` and whose `[+2, +2+byte(+7)-1]` span contains `x` |
| `stats_usesAgntCount` | `stats_nextAgentByOwner` | the agent with the smallest `owner`
(`agnt_t+0x1b`) greater than the given agent's |
| `stats_usesAgntCount2` | `stats_prevAgentByOwner` | the mirror image: the largest `owner` smaller |
| `ovc49_usesBothFactions` | `ovc49_agentIsActive` | a predicate over `moveState < 2` and
`flags & 4`, `moveState == 1`, or `field_0x2a == 2 && BothFactions` |

`ovc49_agentIsActive`'s parameter is now typed and named `agnt_t *agnt` (the exact-path **4-byte**
form, `/st.h/agnt_t *32`, so the far pointer keeps its width).  The decompiled body now reads
`agnt->moveState`, `agnt->flags` and `agnt->field_0x2a` by name, and the audit's struct-argument
count goes 143 -> 144 while the auto-parameter count goes 300 -> 299.

Refused in the same pass: `ovc41_compute8` (compares `param_1 + 4` with
`agnt_compute16_4(param_2) + 1`), `draw_compute1` (a scaled menu-highlight offset), `ovc25_compute1`,
`attact_usesBDADailyTimeCounter`, `season_usesGPromotableCount2` and `constrct_compute1` (both depend
on unresolved `GPromotableCount`/BSS counters).

### Nineteenth batch: rank-scaled helpers and three more UI/audio names

`char_sheet_t` offsets are decimal in `ListFieldNames`, so `+0x87` = 135 = `rank`.  Two functions
read it as a number and state what it is for:

| old | new | evidence |
|---|---|---|
| `ovc45_compute2` | `ovc45_rankPercent` | returns `rank*10` while `rank < 0xb`, else 100 -- the
rank as a percentage (this was refused in the fifteenth batch for want of the offset) |
| `ovc22_compute2` | `ovc22_applyRankBonus` | scales its value by `(rank+10)/10` while `rank < 10`,
doubles it at `rank >= 10`, then takes 96% when `cls` (+0x2f) is 6 |
| `draw_usesFillRect` | `draw_menuRowBar` | for `menuItem < 5` and
`MenuItemEnabled[menuItem] != -1`, fills a proportional bar at `y = menuItem*0xd + 0x91`:
`SpecialColors[6]` up to `attact_usesLDIV_at_(menuItem) * 0x17 / 0x51`, `SpecialColors[7]` beyond |
| `audio_usesDigSoundPlaying` | `audio_isPlaying` | true when the dig SFX is running
(`SfxRunning` + `digSoundPlaying`) or the music sequence is (`MusRunning` +
`midGetSequenceStatus() == 1`) |
| `agnt_usesBlitLoadRleGfx` | `agnt_blitCrossFrame` | blits cross-hair frame `CrossBlitCount` 1..4
from the table at `-0x748d` into `GSavedBlitSeg` at `(CrossBlitX, CrossBlitY*0x140)` and wraps the
counter at 5 |

Refused in the same pass: `constrct_compute1` (`0x14` below level 5, then `level*4 + 0x14` -- a
level-scaled limit with no stated unit), `season_usesGPromotableCount2` (depends on unresolved
`GPromotableCount` and `byte_2000_BSS_0998`), `driver_compute1/2` (the two corner-shade
arithmetics), and `attact_usesBDADailyTimeCounter` (a wrapped tick difference).

### Twentieth batch: stat generation, formatting and input

| old | new | evidence |
|---|---|---|
| `manage_usesRandBelow2` | `manage_rollStats` | rolls all six stats as `3d6 + randBelow(4)`,
clamps each to 0x12 and sets bit 5 of `statMask` |
| `ovc30_usesDifficulty` | `ovc30_difficultyFactor` | 10 when the `Difficulty` byte is 0, otherwise
`0x3c / difficulty` clamped to 1..10 |
| `stats_usesLDIV_at_` | `stats_formatThousands` | `litoa10` for small values, otherwise divides by
1000 and appends `'K'` |
| `ovc39_compute1` | `ovc39_findBuildingAt` | walks up to four columns left looking for a unit whose
`bldtp_t.size` covers the original column, then returns that `GUnitGrid` index |
| `ovc40_usesBiosKeyAvail` | `ovc40_flushInput` | drains `biosKeyAvail`/`gameProcessKey` and the
mouse until neither reports anything, then clears the two mouse-button flags |
| `ovc41_compute7` | `ovc41_rollStatDice` | rolls 2d6, 3d6 or 4d6 depending on how far the value is
from the target |

Refused in the same pass: `ovc41_usesMiceBlitRect` (restores the mouse area and draws the menu item,
but the body is cut off in the export), `ovc41_compute8` and `draw_compute1`.

### Twenty-first batch: 19 names from the 30-45-line tier

| old | new | evidence |
|---|---|---|
| `manage_compute5` | `manage_abilityModifier` | maps a score to a modifier with the thresholds
4/6/9/13/16/18 and the outputs -3..+3 |
| `agnt_compute7` | `agnt_abilityModifier` | the identical table applied to
`sheet->stats[abilityIndex]` (+0x29 base) |
| `ovc41_compute10` | `ovc41_growthForLevel` | indexes the table copied from `growthTable` by
`agnt->level` (`level*0xfa - 0xabe` above level 0x15), or takes the type value from `AgntGs` |
| `constr_usesBlitRect2` | `constr_flushDirtyRects` | saves the mouse over both `BlitRects` entries,
blits each dirty rect and frees the `0xfa0f` staging block |
| `ovc15_textArena2` | `ovc15_selectLeftmostAgent` | keeps the agent with the smallest
`screenX`/`screenY` and stores it in `SelectedAgent` |
| `ovc15_textArena3` | `ovc15_selectRightmostAgent` | keeps the largest |
| `constr_usesBlitGfxRect` | `constr_blitRowObjects` | walks `rowMapSquareFirst..End` and blits the
building graphic when `bldtp_t.flags` (+0x10) has bit 0 or 2 set |
| `attact_usesMenuItemEnabled` | `attact_countPartyUnits` | counts a party's entities that are off
the cursor cell and whose `flags32+1` bit 1 is clear, capped at 0x50 |
| `ovc23_usesAlignUp4` | `ovc23_tickRecordsAt` | stamps `GameTick` into every 0x12-stride record
overlapping the column, decrements `+0xb` and sets `+0xe` at zero |
| `ovc27_textTakesHalfDamage` | `ovc27_spellHalfDamage` | notifies
`"%s takes half damage from spells."` for type 4 above level 15 or type 6 above level 8 |
| `ovc27_textTakesHalfDamage2` | `ovc27_breathHalfDamage` | the same for
`"%s takes half damage from dragon breath."` |
| `driver_loop2` | `driver_fillSpan` | clips x1..x2 to `rect[0]`/`rect[2]` and y to
`rect[1]`/`rect[3]`, then fills the span |
| `ovc42_usesBlitGfx10` | `ovc42_drawTextRow` | sets `TextBlitX/Y` (`row*0xd + 0x9e`), blits the
background for row 0 and the label in `demfont1` |
| `ovc41_usesAgntCount2` | `ovc41_paralyzeNearbyAgents` | when the type record has bit 4 of +0x3e
set, rolls against every agent within 0x32 pixels and calls `ovc41_textParalyzed` |
| `manage_usesBlitGfxRect` | `manage_openTalkWindow` | sets `ScreenMode`, installs the `talkwin9`
palette, fills `0xc,7..0xde,0x96` and blits `talkwin9Cut1/2/3` |
| `manage_usesRandBelow3` | `manage_rollHitPoints` | sums `randBelow(classLimits[cls]) +
abilityModifier(stats[4]) + 1` per race point into `hp[0]`/`hp[1]`, sets `statMask` bit 4 |
| `ovc27_usesRandBelow2` | `ovc27_rollAgainstStat` | rolls 1..40 and succeeds when it does not
exceed the owner's stat at `[mode]` (6 when unowned) |
| `season_usesAlignUp4` | `season_countPromotable` | recomputes `GPromotableCount` by counting units
whose four map-flag words OR to exactly 0x1000 |
| `ovc38_textShighTxt` | `ovc38_loadHighScores` | builds `"%shigh.txt"`, opens it and reads six
far pointers, zeroing them when the file is missing |

`season_countPromotable` also explains the earlier refusals that depended on `GPromotableCount`:
the counter is recomputed here, not maintained incrementally.

Refused in the same batch: `draw_textArena` (debug/slot gates plus a 3-cell flag scan, no stated
meaning), `draw_compute4` (a whitelist of type ids 9/0xe/0x1c/0x1e/0x1f/0x20/0x37-0x39/0x44/0x45/
0x55 with no vocabulary), `ovc41_compute6` (returns 13/11/9/7/2 from a margin), `agnt_compute16`
(a predicate over the two types' flags), `ovc41_usesXOfs` and `ovc22_usesLUDIV_at_`.

### Twenty-second batch: 10 names from the 45-70-line tier

| old | new | evidence |
|---|---|---|
| `constr_usesGfxRndSeed3` | `constr_setHighlightAtOffset` | reads
`GUnitGrid[GfxRndSeed + dx][GfxRndSeed2 - dy]`, stores that unit's `level` into `HighlightLevel`
and returns its `bldType`; parameters renamed `dx`/`dy` (same roles as `constr_getCellAtOffset`) |
| `attact_usesGMapCells` | `attact_isTerrainFlat` | takes max and min of the four `GMapCells` of the
2x2 block at (x,y) and returns 1 when `max-min < 0x3c` |
| `ovc39_usesStshAlloc` | `ovc39_loadArchiveEntry` | loads archive entry `param_1` (table at
-0x6c70), reads the size words at +5/+7 of the record, allocates and `memcpy`s it |
| `constrct_usesAlignUp4` | `constrct_unitFlagsClear` | ORs the four `GMapFlags` words covering the
unit footprint and returns 1 when the OR is zero |
| `ovc41_usesAgntCount` | `ovc41_removeAgent` | calls `agnt_usesAgntCount4(agntIndex+1)`, rewrites
every agent's +0xc reference (decrement above, 0xff for the removed one) and memmoves the tail |
| `ovc41_usesIndexPermD2` | `ovc41_removeIndexPerm` | rewrites all four `IndexPermA..D` tables of 12
entries so references to the removed index are replaced |
| `attact_textCannotAttractUnits` | `attact_updateAttractEntry` | caches the value at -0x6f7e, resets
the text cycle, shows `"You cannot attract units to this location."` when
`ovc23_findClearColumn` returns -1, else recomputes the count |
| `saveui_usesBlitLoadRleGfx` | `saveui_startCrossBlit` | sets `CrossBlitFlag = 0`, `CrossBlitCount2
= 0`, `CrossBlitCount = 1` and `CrossBlitX/Y` from `GMenuItem` |
| `ovc42_usesBlitGfxRect` | `ovc42_endDemo` | prints `"Demo cancelled."` for exit codes other than
0/3, restores palette and mouse, sets `GameRunning = false` and blits the menu panels |
| `init_usesGMapFlags` | `init_rebuildMapFlags` | rebuilds the whole `GMapFlags` array (0x3b x 0x93)
from `GMapCells`, setting bits 0/1/2 per cell triple |

Refused in the same batch: `attact_usesGMapFlags`/`constr_usesGMapFlags` (they set the BSS cell
state 2/3 from neighbouring triples, but the vocabulary of those states is unstated),
`ovc22_usesEntities` (a capacity test comparing `sheet+0x5b` with `sheet+0x4d` mixed with type
flags), `ovc41_compute3`, and `ovc39_compute1`-style helpers whose callee is still unresolved.

### Twenty-third batch: 6 names from the 70-110-line tier

| old | new | evidence |
|---|---|---|
| `ovc13_usesScreenX` | `ovc13_drawPanelEntities` | walks every entity inside the panel grid
(`PanelGridX..+0x22`, `PanelGridY..+0xf`), maps it with `(x-PanelGridX)*2+0xef`,
`(y-PanelGridY)*3+7`, reads that pixel with `ovc13_readPixel` and blits the sprite |
| `ovc13_usesScreenY3` | `ovc13_drawWindowEntities` | the same pass over the
`Seed_2000_d110/d10e` window (0x69 x 0x2f), filtered by `ovc13_usesEntities` |
| `ovc45_textArena` | `ovc45_findEntityAt` | scans `Entities` for the record at `(alignUp4(x), y)`
and writes its index through `foundIndex` and a flag through `foundFlag` (`param_4` is never used) |
| `ovc18_textView` | `ovc18_showLeaderView` | with the game stopped, counts the active leaders per
side and for the leader on the cursor cell says `"View %s."` and blits the view graphics |
| `ovc24_textIntelligenceReportsUnit` | `ovc24_removeOtherEntities` | clears every entity's +2 byte,
then kills (`ovc24_textKill`) and reports every entity except the one under the cursor, then sets
`GGameState = 0x20` |
| `ovc30_usesFmFreeAudio` | `ovc30_createLeader` | finds a leader slot whose `sheet+0x28` is zero,
otherwise allocates a new **0xae-byte** record (the size of `char_sheet_t`) into the leader table,
exiting with 0x21 when full |

`ovc24_removeOtherEntities`'s parameter is now `reportedOut`: its only caller passes the address of
its local `reported` flag and tests it immediately afterwards.  Parameters: 297 -> 296.

Refused in the same batch: `ovc15_usesRandBelow2` (picks a random entity for the side with the
larger `sheet+0x45`, which lands inside the unnamed `pad_40` region), `draw_usesGameProcessKey`,
and `ovc49_usesStExit`.

### Twenty-fourth batch: 9 names, driven by the string literals each body carries

A new scan (`tmp/mech_strings.py`) lists every mechanical-named function whose body contains a
string literal other than the `"puppetmaker"+3` filler: 89 candidates.  Each name below comes from
the literal plus the code around it.

| old | new | evidence |
|---|---|---|
| `agnt_textHeld` | `agnt_statusText` | tests the agent flags in order and builds the matching status
text; the literals are `"charmed %s"`, `"diseased %s"`, `"held %s"`, `"paralyzed %s"` |
| `ovc18_textFortressCannotPlaced` | `ovc18_checkFortressPlacement` | carries the verdicts
`"A fortress cannot be placed among enemy units."`, `"Cannot place another fortress here."`,
`"This location is unsuitable for a main stronghold.  %s"` |
| `saveui_textSsavesTxt` | `saveui_readSavesList` | opens `"%ssaves.txt"` and reads each entry |
| `saveui_textSsavesTxt2` | `saveui_writeSavesList` | creates `"%ssaves.txt"`, writes the count line
and one line per entry with `saveui_writeLine` |
| `draw_textMovement` | `draw_toolbarLabels` | blits `"Build"` at (0x104,0x5b), `"Recruit"` at
(0xe6,0x3e), `"Train"` at (0x11e,0x3e) and `"Movement"` |
| `manage_textLawful` | `manage_playerTitle` | copies `GPlayerTitles` and returns
`titlesMap[gender*2 + cls*4]`, the empty string when `cls == 0xff` or unset |
| `saveui_textCancel` | `saveui_drawCancel` | blits `"Cancel"` at (0x1d,0xb7) in Font03 |
| `saveui_textMessageDelayNow` | `saveui_configureMessageDelay` | `"Change message delay:"`,
`"Message delay is now %d."` and `"cflow4.txt"` |
| `saveui_textWhichNewWorld` | `saveui_configureNewWorld` | `"Which new world:"`,
`"Hostility level:"`, `"Low/Medium/High intelligence enemies:"`, `"Size of second wave:"`,
`"Too many enemies. 60 enemies maximum."`, `"Resetting game..."`, `"New world complete."` |

Two parameter scans were run first and both came back nearly empty, which is the evidence that the
automated levers are exhausted: auto params multiplied by a known record stride (0x34/0x37/0x95/
0x27/0x1e/0x12/9) yields **one** hit, in `OVC22_5087_056e` -- the function already documented as
self-contradictory and deliberately untouched.

Refused in the same batch: `ovc15_textError` and `ovc18_textTypeLen` (complex panel renderers whose
literals name only some of their sections), `draw_textProvidesMoreHousing` (an input-wait loop that
uses the housing string only as an address for a return code), and `draw_textGoldProvidesHousing`.

### Twenty-fifth batch: 7 message emitters named from their format strings

`tmp/mech_strings2.py` was fixed to take the *current* name by address from `tmp/funcs35.tsv`
instead of the stale signature line in the export, so renamed functions drop out of the candidate
list (73 remained).  The literals can also be read as evidence of a function's purpose:

| old | new | evidence |
|---|---|---|
| `ovc38_textShighTxt2` | `ovc38_saveHighScores` | creates `"%shigh.txt"` and writes the six far
pointers, skipping empty entries -- the writer paired with `ovc38_loadHighScores` |
| `stats_textReadied` | `stats_readyStatusText` | formats `"  %s is not readied."` /
`"  %s is ready."` from `flags32` bit 0 |
| `ovc41_usesDrawTextAt` | `ovc41_unitStatusText` | formats `"The %d unit%s loyal to %s %s %d%%
recruiting, %d%% training, and %d%% building."` |
| `stats_textNowCalledAway` | `stats_calledAwayNotice` | formats `"%s can now be called away from
home."` |
| `ovc25_textAttacking` | `ovc25_attackingNotice` | formats `"%s is attacking."` |
| `ovc41_textBuilding` | `ovc41_buildingNotice` | formats `"Building %d %s."` |
| `ovc41_textCannotSeeTerrain` | `ovc41_cannotSeeTerrainNotice` | prints `"You cannot see the terrain
here."` |

Also checked and dismissed this pass: the 164 non-thunk functions absent from the decompiled tree
are the DOS interrupt stubs (`DOS21::*`, size 1), not real bodies, so nothing is missing that can be
recovered by decompiling on demand.

The parameter and local axes were re-scanned on the refreshed export and returned nothing new: auto
params stored into a named struct field: 0; auto locals assigned from a named global: 0; auto params
multiplied by a known record stride: 1, in the deliberately-untouched `OVC22_5087_056e`.

### Twenty-sixth batch: 10 more names from the string-literal candidates

| old | new | evidence |
|---|---|---|
| `ovc23_textUnitDrowns` | `ovc23_drownUnitsAt` | marks the cell flags with 3, then kills every
entity at (x,y) reporting `"%s unit drowns.  (%d, %d)"` |
| `stats_usesDrawAgntStats` | `stats_setAgentBase` | moves the agent's entity to the cursor and
reports `"%s is now based at (%d, %d). This unit will remain home when attracted."` |
| `manage_textAllUnitsDisplayed` | `manage_applyUnitFilter` | sets `unitTypeFilter = unitType` and
`partyFilter = partyIndex`, redraws and prints which filter is active |
| `season_textBuildingRepaired` | `season_repairBuildings` | runs the repair pass and reports
`"%d building%s repaired."` |
| `ovc25_textIntelligenceReportsAttacking` | `ovc25_intelAttackingNotice` | emits
`"Intelligence reports %s attacking."` |
| `ovc38_textGreatAchievements` | `ovc38_showAchievements` | loads the high-score table, blits the
save panel and runs the menu -- the "Great Achievements" screen |
| `ovc22_textDecreaseMessageDelay` | `ovc22_spawnForLeaders` | the literal is only an address base;
the body loops the leaders, applies the per-class chance against `sheet+0x2e` and spawns through
`ovc22_usesRandBelow2` |
| `ovc27_textCastsSpell` | `ovc27_spellNotice` | formats `"%s casts a %s spell %s %s."` |
| `ovc24_textIntelligenceReportsUnit2` | `ovc24_intelUnitReport` | formats the per-unit intelligence
report (cured of disease/poison, blast spore variants) |
| `ovc27_textIntelligenceReportsAttacking` | `ovc27_intelAttackingNotice` | emits
`"Intelligence reports %s attacking."` |

Two of these are worth flagging as near-misses caught by reading the body rather than the literal:
`ovc22_textDecreaseMessageDelay`'s string is `"Decrease message delay" + 5`, an address, not a
message it prints -- the body is a spawn pass; and `draw_textProvidesMoreHousing` / `ovc42_text`
`ProvidesMoreHousing` are modal input loops that use their strings the same way, so they stay
unnamed.

Refused in the same batch: `ovc27_textCharmed` (its prototype has locked storage and the body is
flagged as having moved the stack pointer -- a fragment, not a clean function), `ovc18_textArena`
and the five `*_textArena*` helpers (the string is used only as a non-zero return value),
`stats_textShortSword`/`ovc28_textHalflingCastle` (plain name lookups), and
`draw_textGoldProvidesHousing`.

### Twenty-seventh batch: 5 names, and the string lever starts to thin

| old | new | evidence |
|---|---|---|
| `ovc30_textAllEnemiesDestroyed` | `ovc30_nextWave` | advances `PlayerIndex`, spawns the next wave
from `lowIntelEnemies`/`Difficulty` and prints `"Next wave of enemies appear."` /
`"All enemies destroyed."` |
| `ovc23_textConstructionAbandoned2` | `ovc23_abandonConstruction` | when the site is unreachable it
removes the 0x12-stride record, saying `"Construction abandoned."` if the cursor is on it |
| `bldng_textBuildingNowSelect` | `bldng_selectBuildingType` | formats `"Building is now %s.  Select
type of building."`, runs the list and stores the pick into `char_sheet_t.buildType` |
| `stats_textLongerReady` | `stats_unreadyNotice` | formats `"%s is no longer ready."` and the
ready-list hint |
| `ovc25_textSpiesReportHeading` | `ovc25_spyReportNotice` | emits `"Spies report %s heading towards
stronghold. (%d, %d)"` |

The remaining 56 string-bearing mechanical functions are mostly *not* describable from their
literals: 13 of them use a string purely as a non-zero return value (`"arena"`, `"main castle"`,
`"halfling castle"`, `"short sword"`, `"Level 2"`), and the rest are large multi-message
dispatchers (`draw_textTalkwin9Lbm`, `ovc22_textRingProt`, `ovc15_textError`) whose bodies need the
overlay mapping to read.

### Four more parameters from the single-slot scan

| function | parameter | name | evidence |
|---|---|---|---|
| `alignUp4` | `param_1` | `value` | the body is `return (value + 2) & 0xfffc` |
| `ovc26_usesStExit` | `param_1` | `entityIndex` | indexes `Entities` with it |
| `ovc25_usesEntityCount` | `param_1` | `partyIndex` | the loop compares the party byte
(`&Entities[i].base.entity + 3`) against it |
| `stats_usesEntityCount` | `param_1` | `partyIndex` | same comparison |

Parameters: 296 -> 292.

Refused in the same pass: `midPlaySequence`'s only parameter (the body is a `swi(0x66)` trampoline
that never reads it) and the `*_textArena*` family.

### Twenty-eighth batch: 2 names, and why the rest of the string list is refused

| old | new | evidence |
|---|---|---|
| `ovc24_textStrongholdDestroyed` | `ovc24_checkStrongholds` | loops the sides with `outFlag` and
`excludedFlags[2]` and reports `"%s stronghold destroyed. (%d, %d)"`,
`"Your main stronghold has been destroyed. Game over."` and `"You have defeated all enemies."` |
| `manage_textBelongingAllLeaders` | `manage_highlightStructures` | sets the highlight filter from
`(partyIndex, structType)`, redraws and prints `"The damaged structures belonging to %s the %s are
highlighted in red."` |

The 51 remaining string-bearing candidate are now blocked for one of two reasons, both recorded:

* **literal used as a value, not a message** (13): `"arena"`, `"main castle"`, `"halfling
  castle"`, `"short sword"`, `"Level 2"`/`"Level 3"` and the `*_textArena*` family appear as
  `"<string>" + k` address arithmetic returning small non-zero codes, so the literal says nothing
  about the function;
* **locked-storage fragments** (3): `ovc27_textTakesHalfDamage3/4` and `ovc27_textCharmed` carry
  "parameter storage is locked" and (for the last) a stack-pointer warning.  Ghidra's model of
  their arguments is unreliable, so naming them would attach names to slots that are not the real
  arguments.

The rest are large multi-message dispatchers (`draw_textTalkwin9Lbm`, `ovc22_textRingProt`,
`ovc15_textError`, `ovc23_textAdlibNone`) that need the overlay mapping to read.

### Five more parameters from the single-slot scan

| function | parameter | name | evidence |
|---|---|---|---|
| `bldng_usesGStrangeTable` | `param_1` | `typeIndex` | indexes `((far_t *)GStrangeTable)[i]` |
| `bldng_usesRandBelow` | `param_1` | `typeIndex` | same table, then `randBelow(GStrangeTable[i])` |
| `ovc39_loadArchiveEntry` | `param_1` | `fileId` | indexes the archive far-pointer table at -0x6c70
with `i*4` under `i < 0x22` |
| `ovc38_loadHighScores` | `param_1` | `entries` | the six-entry far-pointer table written by the loop |
| `ovc38_saveHighScores` | `param_1` | `entries` | the same table, read by the writer |

Parameters: 292 -> 287.

Refused in the same pass: `driver_zeroWords`' second parameter and
`attact_usesEntityCount2`'s second parameter (both unused -- the bodies read the value from the
stack slot instead), and `midPlaySequence`'s only parameter (a `swi(0x66)` trampoline).

### Twenty-ninth batch

| old | new | evidence |
|---|---|---|
| `ovc41_textFailsTurn` | `ovc41_turnUndeadNotice` | rolls the turn-undead attempt and reports
`"%s fails to turn."`, `"%s cannot turn."` or `"%s turns %d undead."` |

The remaining string-bearing candidates are all in the two refused classes recorded in the previous
batch (literal-as-return-value, locked-storage fragments) or are the multi-message dispatchers.

### Thirtieth batch: the 170-260-line tier (only six candidates, two named)

| old | new | evidence |
|---|---|---|
| `init_textNEWMAXSQUARE` | `init_computeMaxSquares` | computes `GMaxSquare`/`GSMaxSquare` from the
scale table and prints `"NEW MAXSQUARE %d"` / `"NEW SMAXSQUARE %d"` whenever the result differs
from 0x1b0 / 0x24 |
| `ovc41_textPoisons` | `ovc41_specialAttack` | resolves the special attacks: the literals it emits
are `"%s poisons %s."`, `"%s infects %s with blast spore disease."` and `"%s drains all energy from
%s."` |

Refused: `ovc30_textDivideError` (spawn helper whose role is unclear from the body) and the large
multi-message dispatchers.

### Three parameters

| function | parameter | name | evidence |
|---|---|---|---|
| `fputc` | `param_1` | `ch` | stored into `_fputc_c`, the character |
| `audio_textMidiError` | `param_2` | `status` | compared against 1 and 2, an event code for the
track |
| `ovc41_specialAttack` | `param` | `targetIndex` | `targetIndex < AgntCount`, scaled by 0x34 to reach
the agent record |

Parameters: 282 -> 280.

### Thirty-first batch: two names from call profiles

A new scan (`tmp/mech_callees3.py`) lists mechanical functions by the distinct callees in their body
(the function's own name excluded).  Most of its 122 hits are trivial wrappers, but two are clean:

| old | new | evidence |
|---|---|---|
| `draw_usesRing_buffer` | `draw_freeRingBuffers` | frees the `audioSaveCut1` and `audioSaveCut2`
blocks when present, clears their offset/segment and calls `clean_ring_buffer` |
| `bldng_usesBldng` | `bldng_buildMenuEntries` | called as `(buildTypes, menuEntries, count,
partyIndex)` and fills the far-pointer menu entries with the names and prices of the candidate
building types |

Refused from the same scan: `draw_usesPrintf` (a game-state step, not a printer), `attact_usesUpdSeason`
and `draw_usesGameProcessKey` (debug/input helpers whose purpose is the state transition, not the
call), and `agnt_usesAgntSaved` (an insertion pass whose ordering key is not stated).

### Thirty-second batch

| old | new | evidence |
|---|---|---|
| `draw_usesDrawLine` | `draw_menuCursor` | clamps a menu cursor offset to (0..0x38, 0..0x1c), stores
it back into `data_2000_BSS_0744/0749[GMenuItem]`, then draws the three indicator lines and the dot
from `(x+0xf3, y+0x3b)` in `SpecialColors[3..5]` |

Its two parameters are the clamped offsets (`x` within 0..0x38, `y` within 0..0x1c before the
0xf3/0x3b origin is added).  Parameters: 275 -> 273.

Two other scans were run this pass and both confirm the tail:

* a constant-store scan (`tmp/mech_global_store.py`, 114 hits) found no R3-style setter -- every hit
  assigns into a local (`uVar`, `iVar`) rather than a named global;
* the remaining entries of the call-profile scan are large multi-purpose routines
  (`agnt_usesStExit`, `constr_usesBlitGfxRect2`, `blit_usesBlitGfxN`) whose purpose needs the overlay
  mapping, so they stay unnamed.

### Thirty-third batch: three string helpers

| old | new | evidence |
|---|---|---|
| `init_usesTolower` | `init_normalizeName` | lowercases the string in place **and drops every
space** (the write index only advances for non-space characters) -- a name canonicaliser |
| `ovc22_usesGSeason` | `ovc22_seasonalIncome` | takes a building's income (`bldtp_t+0x15`) and
scales it by season: `GSeason == 0` picks `>>2` or `>>1` from `GTimeLo`, `GSeason == 2` adds 25% |
| `ovc15_usesToupper` | `ovc15_capitalize` | copies the string and uppercases only its first
character |

### Thirty-fourth batch: three UI helpers

| old | new | evidence |
|---|---|---|
| `ovc28_textGold` | `ovc28_drawGold` | draws the label `"Gold"` centred at (0x10e,0x9c) in Font03
and then formats the party sheet's 32-bit gold value (words at +0x56/+0x58 = `char_sheet_t.gold`)
into that position |
| `ovc41_usesAgnt_clear2` | `ovc41_enterLeaderView` | resets the RNG and text cycle, clears the
agents and square records, redraws the five menu bars, calls `ovc18_showLeaderView`, then restores
`GMenuItem` |
| `ovc28_usesBlitLabel` | `ovc28_drawButton(x, y, label)` | blits `butt01Cut6` at `(x,y)`, positions
the text at `(x+6, y+2)` and draws `label`; the parameter is renamed from `param_3` |

Parameters: 273 -> 272.

### Thirty-fifth batch: the save I/O wrappers and two screen helpers

| old | new | evidence |
|---|---|---|
| `save_usesRead` | `save_readBlock` | wraps `read()` and returns 1 only when `read() == count` |
| `save_usesWrite` | `save_writeBlock` | the mirror image around `write()` |
| `saveui_usesStshAlloc` | `saveui_readLine` | reads one line (up to 0x4f bytes, stopping at newline
or `^Z`) and returns a heap copy; 0/empty for `^Z` or an empty line |
| `ovc42_usesBlitGfxRect2` | `ovc42_showAgentStats` | fills a temporary agent record (`agntTmp`) and
hands it with the palette to `drawAgntStats` |

### Globals: the single-store candidates dumped and refused

The six globals named in the brief were each dumped in full:

| global | uses | why it stays a refusal |
|---|---|---|
| `2000:ca36` | 1 | write-only: `= *(u16 *)(BDA tick + 2)` in `draw_usesPlay_sfx`; no reader |
| `2000:ca7a` | 1 | write-only: `= 1` in main after the load; no reader |
| `2410:073c` | 1 | read as a bias in the terrain smoothing compare, no writer anywhere |
| `2410:0845` | 1 | read in the animation gate (`0845 == 0 && GPaused == 0 && 06E2 == 1`), no writer |
| `2410:074b` | 2 | read as the y origin of a 6x0x27 strip blit in two draw paths, no writer |
| `2410:5dee` / `5df2` | 1 / 2 | read next to `bandMin = LevelBandMin` / `bandMax = LevelBandMax` in
`ovc30_usesRandBelow`, but one use builds `CONCAT11(hi(5df2), 0x29)`, so the pair is not a clean
offset/segment split -- refused rather than guessed |

Globals stay at 190; mechanical names: 585 -> 580.

### Thirty-sixth batch: five more from call profiles

| old | new | evidence |
|---|---|---|
| `saveui_usesStshFree` | `saveui_freeLines` | frees each non-null far-pointer entry (guarded by an
`ofs != seg` strcmp) and zeroes it -- the partner of `saveui_readLine` |
| `stats_usesAlignToSeg` | `stats_openCastlePanel` | allocates a `0xfa0f` screen buffer, fills
(8,7,0xe2,0xc2), blits the full-screen background and `nwpanel2Cut1`, installs the `Lbm_nwpanel1`
season palette, draws the castle panel text and the five menu bars, then sets `mapViewActive = 0xff` |
| `season_compute1` | `season_checkEndGame` | takes the leader's type band (`ovc30_compute1`) and,
once per band (flag array `2000:0999`), runs the end-of-game score screen
`season_textHalflingCastle(0)` |
| `stats_usesBlitGfxRect` | `stats_drawPortrait` | loads `talkwin9Cut5`, builds the season palette and
uses `gdata->prts[portraitIndex]` -- the agent type's portrait |
| `stash_usesFmMalloc` | `stash_loadFromStrongDat` | seeks `StshStrongDatHnd` to the entry offset,
reads it, allocates a heap block, `memcpy`s the data and caches the handle in the record |

Mechanical names: 580 -> 572.

### Thirty-seventh batch: the ovc13 panel family + one allocator

The six remaining `ovc13_uses*` functions all draw the on-map panel, and their bodies differ only in
which globals they filter on.  That filter set is the evidence for each name:

| function | filters on | new name |
|---|---|---|
| `3d16:06a2` | `PanelGridX/Y` + `GLeaderCount` | `ovc13_drawPanelLeaders` |
| `3d16:135d` | `Highlight1` + `GLeaderCount` | `ovc13_drawPanelHighlight` |
| `3d16:1b3b` | `Highlight1` + `unitType` | `ovc13_drawHighlightedUnits` |
| `3d16:0255` | `PanelGridX/Y` + `EntityCount` | `ovc13_drawPanelEntitiesAll` (the type-filtered one
is the already-named `ovc13_drawPanelEntities`) |
| `3d16:0c22` | `(x,y)` parameters, `y*3` and `x*2` | `ovc13_drawPanelCell` |

Also named: `4b0a:08ee ovc20_usesPADD_at_` -> `ovc20_allocBlock` (guards on `StshCount < 0xd93`,
rounds the size with `LXMUL_at_`, returns the padded block).

Refused: `5d45:06f0 ovc26_usesRandBelow` (a spawn routine whose out-flag semantics are not stated).

Mechanical names: 572 -> 566.

### Thirty-eighth batch: five more from call profiles and grid accessors

| old | new | evidence |
|---|---|---|
| `ovc22_usesGMapFlags` | `ovc22_testMapFlags(x,y,mask)` | validates the cell (via `ovc22_textArena`)
then returns whether `GMapFlags[y][x] & mask` is non-zero |
| `ovc28_usesBlitLoadRleGfx2` | `ovc28_startCrossBlit` | the same preamble as `saveui_startCrossBlit`:
`CrossBlitFlag = 0`, `CrossBlitCount2 = 0`, `CrossBlitCount = 1`, `CrossBlitX/Y` from `GMenuItem` |
| `ovc41_textKill` | `ovc41_markAgentDead` | prints the `"kill 4"` debug line, decrements the entity
`animFrame` and sets `AgentsChanged` |
| `ovc42_usesAlignUp4` | `ovc42_populateArea(partyIndex)` | fills the cells around the cursor with
`unitTypeMap[randBelow(0xe)]` and spawns from `spawnGindexMap[randBelow(8)]` via `ovc15_usesLDIV_at_` |
| `ovc22_usesGUnitGrid3` | `ovc22_buildingTypeAt(x,y)` | returns `GUnits[GUnitGrid[x][y]].bldType` when
the type's `bldtp_t` flags (+0x121) have bit 0x20 and no construction record overlaps the cell |

Refused: `ovc22_usesGUnitGrid` / `ovc22_usesGUnitGrid2` (same shape but their extra filters --
`& 2 | & 0x20`, and `flags5d` bit 2 plus the class-5 `+0x18` adjustment -- have no stated vocabulary),
and `ovc22_usesAlignUp4`.

Mechanical names: 566 -> 561.

### Thirty-ninth batch: combat resolution and two to-hit rolls

| old | new | evidence |
|---|---|---|
| `ovc41_usesAnimFrame2` | `ovc41_settleAgentCombat(a, b)` | applies the combat outcome to agent `b`:
returns when it is already dead, otherwise (after optionally running the AI via `ovc41_compute4`) it
either zeroes `strength`, sets `timer = 0xa` and `combatState = 2`, or restores `strength` from the
type record with `timer = 6` |
| `ovc27_usesRandBelow6` | `ovc27_rollToHitEntity(agnt, column)` | walks `RampTables[faction]` while
the ramp value is below the level byte, reads `[column+1]`, subtracts the ability modifier for
column 3, and succeeds when `randBelow(0x14)+1` is below that value; the level comes from the entity
(`+0x17 -> +0xf`) |
| `ovc27_usesRandBelow7` | `ovc27_rollToHitAgent(agnt, column)` | the same roll, with the level taken
from the agent itself (`+0xf`) and the faction from its `+0xd` type record |

The `agnt`/`column` parameter names are evidence-pinned: `param_1` is the agent record in both, and
`param_2` indexes the ramp entry (`[param_2 + 1]`) and is compared with 3 for the ability column.
Parameters: 272 -> 268.

Mechanical names: 561 -> 555.

### Fortieth batch: two UI/combat wrappers

| old | new | evidence |
|---|---|---|
| `stats_textShortSword` | `stats_openAgentDetail` | switches `ScreenMode` to 2, calls
`drawAgntStats(Agnts[i], 0)` and then draws the detail string, setting `CurMusicType` from the type
record's byte |
| `ovc41_compute9` | `ovc41_resolveSpecialAttack` | a two-call wrapper: `ovc41_specialAttack(agnt,param)`
followed by `agnt_compute16_9(agnt)` on the same agent |

Refused in the same pass, with evidence:

* `ovc41_compute4` -- it adds a computed amount into the 32-bit field at sheet `+0x10/+0x12` with carry
and then calls `ovc41_compute3`, but the field has no established vocabulary and the amount arrives
from `ovc15_textError`'s return (the string-pointer-as-value idiom);
* `ovc41_compute6` / `ovc41_compute8` -- margin-to-threshold functions returning 13/11/9/7/2 and a
single 0/1, with no stated target;
* `stats_compute4` -- subtracts two modifiers from a type-record byte, but which stat is not stated;
* `6fbe:0000 ovc43_usesFmFreeAudio` -- a bytecode-style `switch` loop over a data script (length from
`*(int *)(gindex+6)`); the opcode vocabulary is not in the export;
* `unit_usesAlignUp42` -- scans `SquareRec` and copies `SquareRecX` (0x13 bytes), but the record's role
is not stated.

Mechanical names: 555 -> 552.

### Forty-first batch: four map-grid operations

| old | new | evidence |
|---|---|---|
| `ovc23_usesGMapFlags` | `ovc23_rebuildDirectionFlags(x, y)` | clears the four direction bits
(`&= 0xff0f`) then sets `0x10 << dir` for each direction whose neighbour test
(`ovc23_usesAlignUp43`) succeeds |
| `ovc23_usesGUnitGrid` | `ovc23_placeBuilding(x, y, bldType, unitType)` | reads the building at the
cell; when its `bldtp_t` flags have bit 4 it sets `strongholdCheckPending`, then places the new type
through `ovc18_usesRandBelow(x,y,bldType,unitType)` |
| `ovc24_usesGUnitGrid` | `ovc24_unitAtLeader(leaderIndex)` | reads the leader's position
(`+0x39`/`+0x3b`) and returns the `GUnitGrid` entry there, one column over for leaders other than the
first |
| `ovc25_usesAlignUp45` | `ovc25_hasBuildingNear(x, y)` | scans four columns around `alignUp4(x)` and
returns 1 when a cell holds a building whose `bldtp_t.kind` (+0xc = 0x11a) is non-zero |

One parameter was renamed by the same evidence: `ovc23_rebuildDirectionFlags`'s second slot is the row
(`GMapFlags[y][x]`), not an index.  Parameters: 268 -> 267.

Mechanical names: 552 -> 546.

### Forty-second batch: three agent-drawing helpers

| old | new | evidence |
|---|---|---|
| `agnt_usesFrameIndex` | `agnt_computeFrameExtents` | resolves `frames[frameIndex]` into (ofs,seg),
reads the type's extents table and the frame width, clamps `y>>1` to 0..9 and branches on
`level == 0` -- the pixel extents of the current animation frame |
| `agnt_usesPlay_sfxU` | `agnt_acquireTarget` | scans `Agnts` for a live agent of another faction with
no `0xae4` flags, sets `flags |= 3`, writes its index+1 through the out pointer and plays sfx 0x3b
panned by `audio_panFromX` |
| `agnt_usesBlitGfxRect` | `agnt_drawSpriteFrame` | resolves the sprite frame, picks `y` from `state`
(0xd -> `screenY`, 0xc -> `screenY - height`, else `screenY - height/2`), blits with `blitGfxRect`,
advances the frame counter and wraps to `startFrame` at `nframes` |

Refused in the same pass: `blit_usesDrawGfx` (its only calls are `unrle` and `memcpy` -- it decodes
rows but no blit target is visible, so "draws" would be an assumption).

Mechanical names: 546 -> 540.

### Parameters batch: seven small bodies

All nineteen slots below had an all-auto signature.  Names come from the body plus the call sites.

| function | old | new | evidence |
|---|---|---|---|
| ovc07_swapWords | param_1, param_2 | wordA, wordB | body loads *a, stores *b into it and *a into *b |
| constr_usesGMapFlags2 | param_1, param_2 | x, y | indexes GMapFlags[y][x], GMapCells[y][x]; caller passes (x,y) |
| ovc30_usesRandBelow2 | param_1, param_2 | centerX, centerY | indexes GUnitGrid[param_1+i][param_2+j]; caller passes (GfxRndSeed,GfxRndSeed2) |
| ovc30_usesRandBelow | param_1 | and | indexes LevelBandMin[band]/LevelBandMax[band]; callers pass 0..4 |
| ovc25_findUnitCell | param_1, param_2 | x, y | reads *x/*y as the start cell and writes the found cell back |
| ovc28_usesBDADailyTimeCounter | param_1 | 	icks | decrements it while waiting on the BIOS timer; callers pass 3 or 6 |
| init2_usesCFGMice | param_1, param_2 | mouseX, mouseY | writes MiceX/MiceY through them; callers pass &MouseX, &MouseY |
| ovc13_usesBlitLoadRleGfx2 | param_1..3 | x, y, orce | adds x to a scroll origin, clamps x 4..0x93 and y 0..0x39, stores them into GfxRndSeed/GfxRndSeed2; callers pass (MouseX-0xc>>1, MouseY-7, 0) |
| ovc13_usesBlitLoadRleGfx3 | param_1..3 | x, y, orce | same body with PanelGridX/Y; callers pass (MouseX-0xef>>1, MouseY-7, 0) |
| ovc30_compute1 | param_1 | level | returns band 0/1/2 at level thresholds 5 and 9; season_compute1 passes the AgntGs level byte |

Parameters: 266 -> 247 (15.0%).  Gate: checked 71 failures 0.

### Parameters batch 3: coordinates, rank and build type

| function | old | new | evidence |
|---|---|---|---|
| `init_usesGMapFlags3` | `param_1`, `param_2` | `x`, `y` | indexes `GMapFlags[y][x]`/`GMapCells[y][x]`; callers pass `(x,y)`, `(x-1,y)`, `(x,y+1)` |
| `init_compute2` | `param_1..3` | `x`, `y`, `direction` | calls `init_getMapFlags(x+dx, y+dy)`; `param_3` selects one of four neighbours via `param_3 ^ 2` |
| `ovc41_rollStatDice` | `param_1`, `param_2` | `rank`, `level` | caller passes `agntG_t+0x42` (rank) and `entity.level`; body rolls 2d6/3d6/4d6 from the margin `level-helper - rank` |
| `bldng_compute2` | `param_1`, `param_2` | `buildType`, `leader` | indexes the 0x27-stride `BuildingTypes` table with `param_1`; compares `param_2` with `manage_findFirstLeader()` |

Parameters: 247 -> 238 (14.5%).  Gate: checked 71 failures 0.

### Parameters batch 4: direction and thresholds

| function | old | new | evidence |
|---|---|---|---|
| `ovc22_compute3` | `param_1` | `direction` | adds 6 to negative values; callers pass `dir`, `dir+1`, `dir-1` and add the result to `dir - dir % 6` |
| `ovc27_usesRandBelow4` | `param_1`, `param_2` | `level`, `threshold` | called as `(entity.level, 4/10)` and `(entity.level, 1)`; returns 0 below, 1 above, 1/8 at equality |
| `ovc41_usesAgnt_clear` | `param_1` | `playSound` | the flag only gates `play_sfx(6,0)` |

Parameters: 238 -> 234 (14.2%).  Gate: checked 71 failures 0.

### Parameters batch 5: agent, rank, building delta

| function | old | new | evidence |
|---|---|---|---|
| `ovc49_usesStExit` | `param_1` | `agnt` | the body reads `->frames`, `->frameIndex`, `->x`, `->y`, `->animVariant` |
| `season_repairBuildings` | `param_1` | `rank` | indexes `PromoteThreshold[rank]` and compares it with `leader+0xa5` |
| `ovc41_buildingNotice` | `param_1` | `delta` | adds the argument to `unit.bldType` and wraps at 0xf7 (the debug building-type change) |

Parameters: 234 -> 231 (14.1%).  Gate: checked 71 failures 0.

### Parameters batch 6: map x, level, rank

| function | old | new | evidence |
|---|---|---|---|
| `ovc49_compute1` | `param_1` | `x` | called with `agnt->x`; range-checked to `0..0xd2`, then indexes a word table at `DS:[x*2]` |
| `agnt_compute14` | `param_1` | `level` | its only caller is `agnt_compute15`, which passes `entity.level`; thresholds 9 and 0x10 |
| `agnt_compute15` | `param_1`, `param_2` | `rank`, `level` | caller passes `agntG_t+0x42` (rank) and `entity.level`; compares `agnt_compute14(level)+2` with the rank |

Parameters: 231 -> 227 (13.8%).  Gate: checked 71 failures 0.

### Parameters/locals batch 7: body-evidence renames

| function | old | new | evidence |
|---|---|---|---|
| `audio_parseHexDigit` | `param_1` | `driverData` | byte stores at `+0x108`/`+0x109` of the audio driver data block |
| `audio_parseHexDigit` | `param_3` | `ch` | tested against `'0'`, indexed into `_ctype`, converted with `-0x37` (A-F) or `-0x30` (digits) |
| `ovc13_compute2` | `param_3` | `upperMask` | its bits set the pixels in rows `y` and `y+1` |
| `ovc13_compute2` | `param_4` | `lowerMask` | its bits set the pixels in rows `y+1` and `y+2` |
| `attact_usesSCARRY22` | `param_5` | `directionOnly` | nonzero returns only the y-direction sign, skipping the `GMapFlags` probe |
| `ovc22_applyRankBonus` | `param_2` | `cost` | scaled by `(rank+10)/10`, doubled at rank >= 10, 96% for class 6; the only caller passes `*(int *)(bldType*0x27 + 0x123)` |
| `ovc40_usesCalcSeasonPalette` | `param_1` | `useVgaPalette` | 0 calls `ovc40_usesVgaSetPalette8bit`, nonzero calls `setSeasonPalette` |
| `ovc41_usesMenuItemEnabled` | `param_1` | `menuIndex` | indexes `MenuItemEnabled[5]` |
| `ovc41_usesMenuItemEnabled` | `param_2` | `gfxVariant` | `== 1` reads the word table 0x1c further along (the second `GUnitDescriptions` graphic set) |
| `ovc41_compute6` | `param_1`, `param_2` | `rank`, `level` | caller passes `agntG_t+0x42` (rank) and `entity.base.level`; compares `agnt_compute16_4(level)+2/+1/+0` with the rank |
| `ovc43_playArchiveFli` | `param_4` | `delayTicks` | forwarded as `playFliFrames`' documented delay-in-ticks argument |
| `attact_textArena3` | `param_2` | `foundIndexSeg` | segment half of the `foundIndex` far pointer: `CONCAT13(in_stack_00000007,CONCAT12(param_2,foundIndexOut))` |

Four locals in `ovc26_usesFillGrid` are the flood-fill ring queues: `fillQueueX`/`fillQueueY` hold the
current ring (`*_piStack_1a = x; *_piStack_1e = y;`), `nextQueueX`/`nextQueueY` receive the next one and
are swapped in at the end of each ring (`piStack_e = piStack_1a;`).

Parameters: 227 -> 214 (13.0%).  Locals: 90 -> 86 (12.4%).  Gate: checked 71 failures 0.

### Parameters batch 8: 17 renames from quoted reader bodies

Every remaining auto parameter was re-checked against a **fresh** decompilation of its function
(`ExportMany.java` exports a whole list in one headless run, so the body is current, not the
stale `tmp/decompiled67` copy).  The renames that survived review:

| function | old | new | evidence |
|---|---|---|---|
| `__VPTR` | `param_1`, `param_2` | `row`, `col` | returns `displayptr + (screenwidth*(param_1-1) + param_2-1)*2`, the text-cell pointer, so `param_1` is the 1-based row |
| `ovc45_costOrIncomeLabel` | `param_1` | `amount` | `< 1` returns `"Maintenance cost is"`, otherwise `"Income created is"` |
| `attact_usesBDADailyTimeCounter` | `param_1` | `prevTick` | compared with the BDA daily counter's high and low words and subtracted from it; callers pass `recordUpdateTick` |
| `ovc43_playFliFrames` | `param_4` | `delayTicks` | the function's own contract ("delays param_4 ticks") and `puVar4 < (uint)param_4` in the wait loop |
| `ovc25_textArena` | `param_2` | `foundIndexSeg` | segment byte of the `foundIndex` far pointer: `CONCAT13(in_stack_00000007,CONCAT12(param_2,foundIndexOut))` |
| `ovc41_removeIndexPerm` | `param_1` | `removedIndex` | drops one index from the four 12-entry permutation tables; every test is `IndexPermX[uVar2] == param_1` |
| `ovc22_usesGMapFlags2` | `param_1` | `skipCheck` | `if (param_1 == 0)` runs the map-flag line walk, any other value returns success at once |
| `ovc23_usesGRecordCount3` | `param_1` | `amount` | scaled into the record flags: `(param_1*7)/10`, `(param_1*8)/100`, `(param_1*9)/10` |
| `ovc50_usesStshLoadGfx` | `param_1` | `gfxIndex` | indexes the far-pointer table at `DS:0x9390` (`param_1*4 - 0x6c70`), then loads and blits it |
| `ovc25_usesAlignUp43` | `param_2` | `count` | `while (iVar5 < (uint)param_2 ...)` with `iVar5` counting placed entities |
| `ovc27_compute3` | `param_1`, `param_2` | `view`, `frames` | `param_1` is passed to `ovc15_textView` and read at `+0xd/+0xf`; `param_2` counts down next to the frame counter at `+0xf` |
| `ovc41_compute3` | `param_1` | `view` | same text-view state: `ovc15_textView(param_1)`, reads `+0xd/+0xf/+0x31/+0x32` |
| `_zapline` | `param_1`, `param_2`, `param_3` | `endCol`, `startCol`, `dst` | `for (; param_2 <= param_1; param_2++) *param_3 = 0x20|attribute` |

### Parameters batch 9: the outFlag segment byte (6 renames)

`createConstructionRecord` splits its `outFlag` far pointer across two stack slots:
`_outFlag = CONCAT13(in_stack_0000000d, CONCAT12(param_5, outFlag))`, so the byte after `outFlag`
is that pointer's segment byte.  The caller `ovc26_usesRandBelow` already names the same argument
`outFlagSeg`, which confirms the identification, so the three functions that forward it now use
the same name (`createConstructionRecord`, `createConstructionRecordFar`, `ovc22_usesRandBelow2`).
`ovc27_textTakesHalfDamage3`'s `param_2` is the same split-far-pointer pattern for an agent
(`CONCAT22(param_2, param_1._2_2_)`) and became `agntSeg`.

Parameters: 227 -> 191 (11.6%).  Gate: checked 71 failures 0.

### Parameters/locals batch 10: out-pointer and copy evidence (8 renames)

| function | old | new | evidence |
|---|---|---|---|
| `ovc45_findEntityAt` | `param_4` | `foundFlagOut` | `*_foundFlag = 0` at entry and `*_foundFlag = 1` when several parties are in the tile; the function comment already says "writes its index and a found flag through the out pointers" |
| `land_info` | `local_22` | `foundFlag` | receives that out flag (`ovc45_findEntityAt(...,(char)&local_22)`) and is then passed as `textDone`'s first boolean argument |
| `land_info` | `local_1e` | `outFlag` | passed as `ovc45_textDone2`'s `undefined1 *outFlag` argument |
| `land_info` | `param_1` | `tileOffset` | clamped to `0..3` and used as `tileX = GfxRndSeed + param_1 - 2`, an x offset of `-2..+1` from the cursor tile |
| `uiReadString` | `local_8` | `cursorX` | cleared, then passed as `saveui_usesBlitGfx10`'s `uint *cursorX`, which ends with `*_cursorX = TextBlitX` |
| `saveui_usesBlitText` | `local_8` | `cursorX` | same argument and same callee |
| `unit_usesAlignUp42` | `local_12` | `savedCursorX` | `savedCursorX[menuIndex] = menuCursorX[menuIndex]` |
| `unit_usesAlignUp42` | `local_d` | `savedCursorY` | `savedCursorY[menuIndex] = menuCursorY[menuIndex]` |

Parameters: 191 -> 189 (11.5%).  Locals: 86 -> 80 (11.6%).  Gate: checked 71 failures 0.

### Parameters batch 11: the found flag handed to the message builders

`land_info` passes the byte it receives from `ovc45_findEntityAt` as the first argument of
`ovc45_textDone` / `ovc45_textDone2`, whose parameter is only tested with `if (param_1 != 0)`
before choosing between the "nothing here" and the normal message.  That byte is the found
flag produced by `ovc45_findEntityAt` (`*_foundFlag = 0/1`), so both `param_1`s became
`foundFlag`.  Parameters: 189 -> 187.

### Parameters batch 12: CRT helpers, with datatype corrections

| function | old | new | type | evidence |
|---|---|---|---|---|
| `memcmp` | `param_1`, `param_3` | `s1`, `s2` | `char *` | the loop advances two byte pointers and compares `*pcVar1 == *pcVar2`; the length arrives as `in_stack_0000000c` |
| `__fstrncpy` | `param_1`, `param_3` | `dst`, `src` | `char *` | `pcVar5 = (char *)param_3` is walked to its terminator first, then `pcVar5 = param_1` is filled |
| `__fputn` | `param_3` | `n` | `uint16_t` | used as `(word)param_3` for `memcpy`, `param_3 + *_stream` for the position and `param_3 <= pbVar6` for the short-write test |
| `sprintf_strputn` | `param_1`, `param_3` | `dest`, `n` | `int *`, `uint16_t` | `*_param_1 = param_3 + *_param_1` advances the far-pointer cursor, and `param_3` is the `memcpy` length |
| `farfree` | `param_2` | `ofs` | - | the offset half of the far pointer, compared with `malloc__last` |
| `fseek` | `param_3`, `param_4` | `offsetHi`, `offsetLo` | `uint16_t` | `CONCAT22(in_stack_0000000c, param_4)` is passed to `lseek` and `param_3` is subtracted from its high word |

The four `int`/`uint8_t *` declarations that Ghidra gave those arguments were replaced with the
real types using the new `SetVarType.java` (address + variable name + type path); parameters now
read `memcmp(char *s1,char *param_2,char *s2)`, `__fstrncpy(char *dst,char *param_2,char *src)`
and `sprintf_strputn(int *dest,uint16_t param_2,uint16_t n)`.

Parameters: 187 -> 177 (10.8%).  Gate: checked 71 failures 0.

### Parameters batch 13: `__VRAM`

`__VRAM` is Borland's snow-safe video copy: `param_1` counts down in every copy loop, `param_2` is
the source that is read (`*puVar1 = *param_2`), and `param_3` is compared with the destination
segment that arrived on the stack (`if (puVar8 == param_3)`) to choose the non-snow path.  They
became `count`, `src`, `dstSeg`; the signature now reads
`__VRAM(int count,uint *src,uint *dstSeg)`.  Parameters: 177 -> 174 (10.6%).

### Parameters batches 14-16: split far pointers, table indices, directions (25 renames)

| function | old | new | evidence |
|---|---|---|---|
| `manage_usesGUnitCount` | `param_4`, `param_6`, `param_8` | `resource1Seg`, `resource2Seg`, `resource3Seg` | the disassembly loads each output as a far pointer (`LES BX,[BP+0xa]`, `[BP+0xe]`, `[BP+0x12]`), so Ghidra's extra `int *` parameters are the segment halves of `resource1Count`/`resource2Count`/`resource3Count` |
| `ovc22_usesGUnits` | `param_3` | `outFlagSeg` | `_outFlag = CONCAT13(in_stack_00000009,CONCAT12(param_3,outFlag))` |
| `ovc40_usesAlignToSeg` | `param_2`, `param_3` | `capTextOfs`, `capTextSeg` | `[BP+0x8]`/`[BP+0xa]` are pushed as one far pointer straight into `CALLF 2000:324a` (`ovr_ovc15_capitalize`) |
| `stats_usesAlignUp42` | `param_2` | `gfxIndex` | indexes `GfxFramePtrs` at `param_2 * 4` and reads both the offset and the segment |
| `ovc18_spawnClassAgent` | `param_5` | `classStr` | compared with 6 and 0x0b to pick gindex 6 / 0x19 / 0x13 before the spawn call |
| `ovc41_compute8` | `param_1`, `param_2` | `rank`, `level` | the caller passes `agntG_t+0x42` (rank) and `entity.base.level`, as for `ovc41_compute6`/`ovc41_rollStatDice` |
| `unit_usesEntities` | `param_3`, `param_4` | `unitFlags`, `unitFlagsSeg` | its callers pass `unit_usesEntities(input,uVar10,unitFlags,unaff_SS)` |
| `attact_textArena2` | `param_2` | `foundIndexSeg` | `CONCAT13(in_stack_00000007,CONCAT12(param_2,foundIndexOut))` |
| `ovc23_textConstructionAbandoned` | `param_3` | `dir` | indexes the step tables at `+0x885`/`+0x889`, the same shape as `attact_usesSCARRY22`'s `dir` |
| `ovc23_usesAlignUp43` | `param_3` | `dir` | same `+0x885`/`+0x889` indexing |
| `ovc15_usesRandBelow` | `param_2`, `param_4` | `xSide`, `randomY` | `if (param_2 < 0) agnt->x = 0 ... else agnt->x = 0xd2` selects left/middle/right, and `param_4` nonzero makes y random instead of the fixed `0x20` |
| `stats_textRingProt` | `param_1`, `param_2` | `dst`, `src` | `strcpy(param_1,(char *)param_2)` and `ovr_stsprintf(param_1,(char *)param_2,"+%d ring of prot.")` |

Parameters: 174 -> 155 (9.4%).  Gate: checked 71 failures 0.

### Parameters batch 17: long-math helpers and the paralysis pair (15 renames)

| function | old | new | evidence |
|---|---|---|---|
| `N_LDIV_at_` | `param_1`, `param_2`, `param_3` | `dividendLo`, `dividendHi`, `divisorLo` | the fast path evaluates `CONCAT22(param_2,param_1) / (ulong)param_3`; the divisor's high word arrives as `in_stack_00000008` |
| `N_LUDIV_at_` | same | same | `CONCAT22(param_2,param_1) / (ulong)param_3` |
| `N_LMOD_at_` | same | same | `CONCAT22(param_2,param_1) % (ulong)param_3` |
| `LMOD_at_` | `param_1`, `param_2` | `dividend`, `divisor` | the function is `param_1 % param_2` |
| `ovc41_textParalyzed` | `param_1`, `param_2` | `source`, `victim` | `paVar5 = (agnt_t *)param_2` is the agent whose `strength`/`combatState`/`targetY` are cleared, and the two status strings name the pair: `agnt_statusText(param_1,victimName)` / `agnt_statusText(param_2,sourceName)` |
| `ovc25_usesAlignUp44` | `param_1`, `param_2` | `partyIndex`, `count` | `param_1` is compared with the entity party byte and `iVar4 < (uint)param_2` bounds the placement loop, the same pair as `ovc25_usesAlignUp43` |

Parameters: 155 -> 140 (8.5%).  Gate: checked 71 failures 0.

### Parameters batch 18: a tick deadline, a direction base, a ring amount (3 renames)

| function | old | new | evidence |
|---|---|---|---|
| `ovc42_usesMiceBlitRect` | `param_1` | `timeoutTicks` | the wait loop breaks when the elapsed ticks from `attact_usesBDADailyTimeCounter` reach it: `if ((uVar4 != 0) || ((ulong *)(uint)param_1 <= puVar2)) break;` |
| `init_usesRandBelow` | `param_3` | `dir` | subtracted from the candidate direction and masked to two bits (`bStack_3 - param_3 & 3`); the only caller passes `randBelow(4)` |
| `stats_textRingProt` | `param_4` | `ringValue` | the two words are used separately: `ringValue.seg` carries the sign (`== 0`, `0 <`), `ringValue.ofs` feeds the arithmetic (`(byte)ringValue.ofs - (char)ringValue.seg`) and the `"+%d ring of prot."` format |

`stats_textRingProt`'s argument was first retyped to `int32_t`, but that made Ghidra render the
sign test against byte 0 instead of the high word, so the original two-word `far_t` typing was
restored and only the name changed (the type is a placeholder for a value passed as two words).

Parameters: 140 -> 137 (8.3%).  Gate: checked 71 failures 0.

### Batches 19-21: remaining used parameters and readable locals (19 renames)

| function | old | new | evidence |
|---|---|---|---|
| `ovc42_textProvidesMoreHousing` | `param_1` | `timeoutTicks` | every caller passes the timeout first (`(0x48,0)`, `(0x10,0)`, `(0x30,0)`) and the loop exits once the elapsed ticks reach it |
| `ovc27_usesPlay_sfxU` | `param_4` | `frames` | forwarded as `ovc27_compute3`'s second argument, which counts frames down next to the counter at `+0xf`; callers pass 1 and 2 |
| `ovc22_usesLUDIV_at_2` | `param_3` | `applyPercent` | the whole body is `if (param_3 != 0)` and only then divides by 100 |
| `ovc18_checkFortressPlacement` | `param_1` | `strongholdKind` | its only caller passes 1 and 2, and the `== 2` branch is the fortress path (bldType `0x89`, five-tile width check), whose value it also stores at sheet `+0x5a` |
| `attact_usesEntities` | `param_4`, `param_5` | `flagsOfs`, `flagsSeg` | the prologue keeps them at `[BP+0xc]`/`[BP+0xe]` and the calls push `[BP+0xe]` then `[BP+0xc]`, i.e. segment then offset; all five call sites pass a 6-byte buffer and `unaff_SS` |
| `constrct_usesGLeaderCount`, `ovc22_spawnForLeaders` | `local_4`, `local_5` | `outFlag` | passed as `ovc22_usesRandBelow2(partyIndex, undefined1 *outFlag, outFlagSeg)`'s out pointer |
| `stats_setAgentBase`, `stats_calledAwayNotice`, `stats_unreadyNotice` | `local_8`, `local_8`, `local_a` | `unitFlags` | each is passed as `attact_usesEntities(entityIndex,0,0,<local>,unaff_SS)` |
| `ovc45_textDone2` | `local_292`, `local_d` | `menuLabels`, `menuActions` | `local_292` holds the item far pointers ("Claim", "Chop down", "Done"), `local_d` their action codes 1/2/3/4 with `local_d[0]` taking the selection |
| `ovc45_textDone`, `saveui_configureMessageDelay` | `local_14`, `local_20` | `menuLabel` | a single label pointer whose address is taken for the menu |
| `attact_isTerrainFlat` | `local_a` | `cornerHeights` | filled from the 2x2 cells around the cursor and then min/max compared |
| `ovc18_showLeaderView` | `local_8` | `partyCounts` | cleared, then `local_8[sheet->0x3f]++` per leader; `+0x3f` is the party index the other per-party arrays use |
| `ovc50_usesUiInputText` | `local_2a` | `tabPtrs` | filled with `F_SCOPY(&StatsTabPtrs,...)` and handed to `ovr_uiInputText` |
| `land_info` | `local_a` | `menuLabel` | `local_a = menuItems[0]` and its address is taken for the menu call |

Parameters: 137 -> 131 (8.0%).  Locals: 80 -> 67 (9.7%).  Gate: checked 71 failures 0.

### Batch 22: scanline buffers and an agent index list (3 locals)

| function | old | new | evidence |
|---|---|---|---|
| `blitGfx10` | `local_164` | `rowBuf` | the 320-byte buffer is passed to the row callback and then used as a source row: `src.ofs = (uint16_t)(local_164 + iStack_10)` |
| `blit_usesStExit` | `local_168` | `rowBuf` | same 320-byte buffer passed to the row callback |
| `ovc15_usesAgntIndex` | `local_4ba` | `agentIndices` | filled with agent indices and dereferenced as `peVar1[local_4ba[i]].base.gindex` |

Locals: 67 -> 64 (9.7% -> 9.2%).  Gate: checked 71 failures 0.

## Typing pass: listing types that contradicted the decompiler's own inference

Method: export every function that still owns an auto variable, parse the decompiler's declaration
line for that variable, and compare it with the datatype stored in the listing.  A variable the
listing calls `undefined1` but the decompiler renders as `uint`, `int`, `char *` or `byte[N]` is a
provable mistyping, because both views come from the same code.

### The accumulator case from the goal: `attact_usesLDIV_at_2`

```
before:  undefined1 local_1c      (1 byte)   + int iStack_1a
         attact_usesEntityCount2(&local_1c,unaff_SS);
         if ((local_1c == 0 && iStack_1a == 0) || ...)
         CONCAT22(iVar5 + iStack_1a + CARRY2(uVar4,local_1c), uVar4 + local_1c)
after:   uint32_t sum;
         attact_usesEntityCount2((uint *)&sum,unaff_SS);
         if (((uint)sum == 0 && sum._2_2_ == 0) || ...)
         CONCAT22(iVar5 + sum._2_2_ + CARRY2(uVar4,(uint)sum), uVar4 + (uint)sum)
```

`attact_usesEntityCount2`/`attact_usesAgntCount2` take `uint *sum` and write `sum[0]`/`sum[1]`, so
the local is one 32-bit accumulator; declaring it `uint32_t` also merged away the decompiler's
split high word `iStack_1a` and dropped one auto local.

### Ten more local/parameter types from the same comparison

| function | variable | new type | decompiler declaration |
|---|---|---|---|
| `__LONGTOA` | `local_24` | `uint8_t[34]` | `byte local_24 [34]` |
| `__INITEXT` | `local_1f` | `uint8_t[8]` | `byte local_1f [8]` |
| `ovc26_usesStExit` | `local_6e` | `uint8_t[80]` | `byte local_6e [80]` |
| `init_usesRandBelow2` | `local_e` | `uint8_t` | `byte local_e` |
| `ovc41_unitStatusText` | `local_3` | `uint8_t` | `byte local_3` |
| `ovc45_buildPlacementMessage` | `local_d` | `uint8_t` | `byte local_d` |
| `ovc22_textRingProt` | `local_2a` | `int16_t` | `int local_2a` |
| `ovc43_usesStExit` | `local_12` | `uint16_t` | `uint local_12` |
| `ovc49_textLongerParalyzed` | `local_4` | `uint16_t` | `uint local_4` |
| `ovc42_textProvidesMoreHousing` | `param_2` | `uint16_t` | `uint param_2` |

### Blocked by storage conflicts

`ovc22_textRingProt`'s `local_32` (`int local_32 [4]`) and `ovc24_textKill`'s `local_24`
(`byte local_24 [4]`) could not be widened: Ghidra rejects the change with
`VariableSizeException: Variable storage conflict between local_32{Stack[-0x32]:8} and
local_2c{Stack[-0x2c]:1}, local_30{Stack[-0x30]:1}` (and `local_24` vs `local_22`) — the
decompiler had carved 1-byte locals out of the same stack slots, so widening needs those removed
first.  Left as recorded rather than force-fitted.

Locals: 64 -> 63 (9.1%).  Gate: checked 71 failures 0.

### Finishing the typing sweep (locals 63 -> 60)

The two retypes that had failed with `VariableSizeException` are now applied.  The conflicting
1-byte locals the decompiler had carved out of the same stack slots were deleted first with the
new `RemoveVars.java` (it removes the *variable*, not just its symbol):

```
removed local_2c from ovc22_textRingProt
removed local_30 from ovc22_textRingProt
removed local_22 from ovc24_textKill
typed 5087:056e local_32 int16_t[4]
typed 5943:026e local_24 uint8_t[4]
```

`ovc24_textKill` now declares `uint8_t local_24 [4];` and indexes it directly.

One more parameter came out of the widened-accessor scan (`param._1_1_` proves a 16-bit value
behind an `undefined2` listing): `ovc22_textRingProt`'s `param_3` -> `uint16_t`.

The sweep is now exhausted: re-running the two comparisons over all remaining `undefined1`/
`undefined2`/`undefined4` variables yields no further mismatch — the survivors really are
16-bit unknown words or 1-byte unknowns, and typing them further would be a guess about
signedness rather than a reading of the code.

Locals: 63 -> 60 (8.7%).  Gate: checked 71 failures 0.

## Repairing the `decompiler-broken` bodies: the premise was mostly wrong

New tool `FnGaps.java` walks a function's body instruction by instruction and reports the byte
ranges that hold neither an instruction nor defined data.  Measured against the three bodies the
plan named:

| function | body bytes | gap ranges | gap bytes |
|---|---|---|---|
| `ovc49_body1` (`8699:18c4`) | **150** | 0 | 0 |
| `ovc22_textRingProt` (`5087:056e`) | 3248 | 0 | 0 |
| `ovc18_textTypeLen` (`48ac:0382`) | 373 | 0 | 0 |
| `constrct_buildInfoText` (`7e7c:0b9c`) | 6071 | 3 | 10 |

So the thousand-line decompiles are **decompiler output**, not a disassembly problem: those three
functions have no undecoded bytes at all, and `ovc49_body1` is a 150-byte, 52-instruction routine
whose 3023-line C listing is produced entirely by bad control flow inside the callee it calls
(`2000:3029`) plus hundreds of `pixels_*` spills.  Only `constrct_buildInfoText` had real gaps.

### Reading `ovc49_body1` from its 52 instructions

```
8699:18cc  LES BX,[BP + 0x6]         ; param_1 is a far pointer
8699:18cf  MOV AX,ES:[BX + 0x15]     ; high word of the far pointer at +0x13  (agnt_t.frames)
8699:18d3  MOV DX,ES:[BX + 0x13]     ; low word
8699:18fc  CMP byte ptr ES:[BX + 0x24],0x1     ; agnt_t.combatState
8699:1909  LES BX,ES:[BX + 0x1d]     ; agnt_t.gdata
8699:190d  TEST word ptr ES:[BX + 0x40],0x2    ; agntG_t.flags bit 2
8699:191f  MOV AL,byte ptr ES:[BX + 0x11]      ; agnt_t.animVariant
```

That identifies `param_1` exactly: `agnt_t *`, which Ghidra had typed `int *`.  Renamed to `agnt`
and retyped `/st.h/agnt_t *32`.  The same 52 instructions contain **no reference to** `[BP+0x8]`,
`[BP+0xa]`, `[BP+0xc]` or `[BP+0xe]`, so `param_2`..`param_5` are provably unused.

### `ovc22_textRingProt`: one live parameter out of seven

Counting every `[BP+0x..]` access in the 3248-byte body gives **only `[BP+6]`, 56 times** —
`param_2`..`param_7` are never read.  `param_1` is the leader index: it is guarded with
`if (param_1 != 0xff)` and indexes the far-pointer table with `param_1 * 4`, then reads
`+0x3f`, `+0x5d`, `+0x9a`, `+0xa0`, `+0xa6`, `+0xaa`, `+0xad` of the resulting `char_sheet_t`.
That is the same `partyIndex` convention as `ovc22_applyRankBonus`, so it is now `partyIndex`.

`ovc18_textTypeLen` behaves the same way: accesses reach only `[BP+6]`, `[BP+8]`, `[BP+0xa]`,
`[BP+0xc]` — the first two far-pointer arguments — so its remaining seven parameters are dead.

### `constrct_buildInfoText` gaps

```
7e7c:0bba ADD DX,-0x2                 (3 bytes, clean)
7e7c:0c99 LEA AX,[BP + 0xff38]        (4 bytes, clean)
7e7c:181f CALLF 0x2000:3245           (5 bytes; the earlier decode started mid-instruction)
```

All three ranges decoded with zero holes, but the function still reports "Control flow encountered
bad instruction data" with an overlap at `ram:0x85000` — a jump to an address outside the
program, so the remaining breakage is a bad control-flow target rather than undecoded bytes.

Parameters: 131 -> 129 (7.9%).  Structures typed as arguments: 144 -> 145.  Gate: checked 71 failures 0.

### Removing fabricated parameters when the call sites prove the real arity

`ovc22_textRingProt` declared seven parameters but its 3248-byte body reads only `[BP+6]`.
Checking the call sites settles it: all four push **one word** and clean up 2 bytes.

```
5087:1dec  MOV AL,byte ptr [BP - 0x14]      ; a leader index
5087:1def  PUSH AX
5087:1df1  CALL 0x5000:0dde                 ; ovc22_textRingProt
5087:1df4  ADD SP,0x2                       ; exactly one argument
```

The three callers through the overlay thunk (`ovc18_checkFortressPlacement`
`48ac:0ba9`, `manage_usesLitoa10` `4d05:07ce`, `ovc30_createLeader` `619c:0598`) are identical:
one `PUSH AX` then `ADD SP,0x2`.  So the six extra parameters were invented by parameter
inference; `TrimParams.java` removes them (highest ordinal first, then marks the signature
user-defined):

```
trimmed ovc22_textRingProt 7 -> 1
far_t * __cdecl16far ovc22_textRingProt(byte partyIndex)
```

This is safe with `__cdecl16far`: the caller performs the stack cleanup, so the callee's declared
arity never changes call-site code, and the callee now matches what the callers actually push.

Parameters: 129 -> 123 (7.5%).  Gate: checked 71 failures 0.

### Screening tool for unused parameters, and its limits

`UnusedParams.java` computes each parameter's stack offset and reports the trailing ones never
touched as `[BP+off]` in the body.  Getting the offset base right matters: a **near** function has
`[BP+0]` saved BP / `[BP+2]` return offset and its first argument at `[BP+4]`, while a **far**
function adds the return segment and starts at `[BP+6]`.  The tool decides from the function's own
return instruction.

That distinction was visible directly in `__VPTR`:

```
1000:1352  MOV DX,word ptr [BP + 0x4]   ; row  (first argument)
1000:135f  MOV DX,word ptr [BP + 0x6]   ; col  (second argument)
1000:136c  RET 0x4                      ; the callee pops both words
```

so `__VPTR` is a near, callee-cleanup routine and the earlier `row`/`col` names sit on the right
slots.

The screen has 395 hits, but they are **not** all trimmable, and two classes must be discarded:

* **register-based helpers** — `N_LDIV_at_`, `LXMUL_at_`, `LMOD_at_`, `PADD_at_`, `ovr_mkp` and
  the other Borland long-math/pointer helpers take their operands in `DX:AX:BX:CX`, so nothing is
  ever read via `[BP+off]`; their declared parameters document register usage, not stack slots.
* **huge-model indirect thunks** — `miceHandler` and the `ovr_*` stubs read their arguments through
  registers or a frame the heuristic does not model.

A trim is only justified when a **call site** proves the arity, which is how `ovc22_textRingProt` was
settled (one `PUSH`, `ADD SP,0x2` at all four call sites).  The tool is therefore a screening aid,
with `TrimParams.java` applied only after that check.

## The arity loop, and the typing defect it exposed

I ran the screening loop (`UnusedParams.java` -> call-site check -> `TrimParams.java`) and fixed
three modelling bugs it had:

* byte parameters still occupy a **full word** on the 8086 stack, so a `char` argument advances the
  offset by 2, not 1 (without this, `agnt_compute15`'s `level` looked unused although the body does
  `MOV AL,byte ptr [BP + 0x8]`);
* `[BP+off]` displacements are not exposed through `getOpObjects` in this program, so the offsets are
  now parsed from the rendered instruction text;
* the near/far base comes from the declared calling convention, not from scanning for `RET`/`RETF`
  (for `ovc49_body1` the return sits outside the body ranges).

### Why the loop still cannot be applied in bulk

The screen keeps reporting parameters that *are* used, and one case shows why:

```
6257:0221  MOV AL,byte ptr [BP + 0xa]    ; is_printable's second argument
```

`is_printable` is declared `(char *buf, char c)`, both two-byte slots, which puts `c` at `[BP+8]`.
The body reads `[BP+0xa]`, i.e. the first argument really occupies four bytes.  A parameter that is
truly a far pointer but never loaded with `LES`/`LDS` cannot be told apart from a near one by this
method, and it shifts every later offset, so "unused" verdicts built on that offset are unsound.
`strcat` is the same story: `LES DI,[BP + 0x6]` proves `dst` is far, so `src` sits at `0xa`, not `8`.

So trimming stays restricted to cases where a **call site** proves the arity (the
`ovc22_textRingProt` case), and the screen is used only to suggest where to look.

### What the investigation did fix: 74 near pointers that are really far

`FarPtrParams.java` widens a parameter when the body loads it with `LES`/`LDS` from its own stack
slot — direct machine-code proof that the argument is four bytes:

```
FAR strcat   #0 dst      : char * -> char *32     (LES DI,[BP+0x6])
FAR memcmp   #0 s1       : char * -> char *32
FAR read     #1 buf      : void * -> void *32
FAR _zapline #2 dst      : undefined2 * -> undefined2 *32
FAR __VRAM   #1 src      : uint * -> uint *32
FAR driver_loop3 #1 param_2 : char * -> char *32
...
widened=74  (54 functions, 22 of them game code)
```

This corrects the argument widths and therefore the offsets of every following parameter, which is
the precondition for any further name/type work on those signatures.  The C rendering often looks
unchanged (`char *` either way) because Ghidra prints the `*32` size only in its type name.

Parameters: unchanged at 123 (this batch retypes rather than renames).  Gate: checked 71 failures 0.

## Arity loop, batch 1: call sites give the true argument widths

For each candidate the call site is disassembled and the pushed word count is read off the
`ADD SP,0xN` that follows.  Three functions turned out not to have unused parameters at all —
their parameters were declared as two-byte pointers while the callers push far pointers, so every
later offset was shifted and the screen called them unused.

**`attact_usesEntityCount2` / `attact_usesAgntCount2`** (`3f0b:277b`, `3f0b:28eb`)

```
3f0b:2a9a  PUSH SS
3f0b:2a9b  LEA AX,[BP - 0x1e] / PUSH AX       ; far pointer #1
3f0b:2a9f  PUSH SS
3f0b:2aa0  LEA AX,[BP - 0x1a] / PUSH AX       ; far pointer #2
3f0b:2aa5  CALL 0x4000:182b
3f0b:2aa8  ADD SP,0x8                          ; two 4-byte pointers
```

so both out-parameters are far pointers (`uint16_t *32`).  The body then decompiles through both
instead of the previous `in_stack_00000008` garble:

```
((uint16_t *)param_2)[1] = 0;  *param_2 = 0;
((uint16_t *)sum)[1]     = 0;  *sum     = 0;      /* the 32-bit accumulators */
```

**`copyGrayscalePalette`** (`317e:08ba`)

```
317e:0b7f  PUSH AX                     ; count
317e:0b89  PUSH SS / PUSH DX           ; far destination
317e:0b8c  CALL 0x3000:209a
317e:0b8f  ADD SP,0x6                  ; 4-byte pointer + one word
```

so `dst` is a far pointer (`uint8_t *32`), not the two-byte pointer the listing had.

`SetVarType.java` gained a ` *32` suffix for four-byte pointers so these could be applied directly.
After the retypes all three functions disappear from the `UnusedParams` screen (378 -> 375), which
confirms the diagnosis: the "unused" verdict was a width error, not a dead argument.

Nothing was trimmed in this batch.  Gate: checked 71 failures 0.

**`fontChWidth`** (`302d:04eb`) — same story:

```
302d:0551  LES BX,[BP + 0x6]        ; widths is a far pointer
302d:0559  PUSH AX                  ; one more word
302d:055a  PUSH [BP + 0xc]
302d:055d  PUSH [BP + 0xa]          ; the character
302d:0564  ADD SP,0x6               ; 4 + 2 bytes
```

`widths` retyped `uint8_t *32`, so `ch` sits at `[BP+0xa]` where the body actually reads it; the
function then leaves the screen as well (375 -> 374).

Screen total across batch 1: **378 -> 374**, i.e. four of the ten examined "unused" parameters were
width errors.  No parameter was trimmed in this batch.

## Arity loop, batch 2: `blitGfx10`

Call site `317e:0c4a` inside `blitGfxRect`:

```
317e:0c37  MOV AL,byte ptr [BP + 0x14]   ; type
317e:0c3a  PUSH AX
317e:0c3b  PUSH word ptr [BP + 0x10]     ; dst segment
317e:0c3e  PUSH word ptr [BP + 0x0e]     ; dst offset
317e:0c41  PUSH DI                       ; y
317e:0c42  PUSH SI                       ; x
317e:0c43  PUSH word ptr [BP + 0x08]     ; gfx segment
317e:0c46  PUSH word ptr [BP + 0x06]     ; gfx offset
317e:0c4d  ADD SP,0x0e                   ; 14 bytes
```

14 bytes decompose as `gfx` 4 + `x` 2 + `y` 2 + `dst` 4 + `type` 2, so `dst` is a far pointer
(`brect_t *32`) and `type` sits at `[BP+0x12]`, not `[BP+0x10]` where the two-byte declaration put
it.  With `dst` widened, `blitGfx10` leaves the `UnusedParams` screen (374 -> 373).

Running totals for the arity loop: **378 -> 373** on the screen, and every resolved case has been a
width error rather than a dead parameter.

## The two reachable-but-unapplied cases (params 123 -> 122)

### `init_textFilename` (`3381:08dc`): zero arguments

Its whole body contains **no `[BP+off]` access at or above `[BP+4]` at all**:

```
3381:08dc  PUSH BP
3381:08dd  MOV BP,SP
3381:08df  SUB SP,0xa2
3381:08e3  PUSH SI / PUSH DI
3381:08e5  MOV byte ptr [BP - 0xd],0x0
```

and its only caller passes nothing:

```
3381:21e6  PUSH CS
3381:21e7  CALL 0x3000:40ec          ; no ADD SP afterwards
```

The overlay thunk `22e3:002a` has **zero references**, so that call is the only one.  The
`(undefined4 param_1, int16_t w)` declaration was pure inference and both are gone:
`trimmed init_textFilename 2 -> 0`.

### `alignToSeg` (`30e6:0000`): one far pointer, not a hidden return buffer

The 0x24-byte body reads exactly two words at the start of the first slot:

```
30e6:0005  MOV SI,word ptr [BP + 0x8]   ; segment
30e6:0008  MOV DI,word ptr [BP + 0x6]   ; offset
30e6:000b  TEST DI,0xf
30e6:000f  JZ ...
30e6:0011  INC SI
30e6:0012  AND DI,0xfff0
30e6:0017  SHR AX,0x4
30e6:001a  ADD SI,AX                    ; segment += offset >> 4
30e6:001d  MOV DX,SI / XOR AX,AX        ; returns the aligned segment
30e6:0023  RETF
```

That is one far pointer passed by value (its offset at `[BP+6]`, its segment at `[BP+8]`), and the
caller `lbm_decode_body` pushes exactly two words (`PUSH [BX+0x306]` / `PUSH [BX+0x304]`,
`ADD SP,0x4`).  The declared `(far_t *__return_storage_ptr__, far_t ptr)` described 8 bytes of
arguments, so the hidden return-storage parameter was removed: `trimmed alignToSeg 2 -> 1`.

Two tool limits were hit and are recorded rather than worked around:

* the remaining parameter is Ghidra's auto **hidden return-storage pointer**, and
  `Variable.setDataType` rejects it with `Auto-parameter may not be modified`, so it cannot be
  renamed or retyped in place;
* `SetReturn.java` fails with `NullPointerException: storage is null` because Ghidra's
  `setReturn(DataType, VariableStorage, SourceType)` needs a real storage location when the current
  return type is `far_t *` and goes through hidden storage.  Getting `uint16_t alignToSeg(far_t)`
  needs a full `FunctionDefinitionDataType` rewrite, which is the next step for this function.

Parameters: 1637 -> 1634 total, auto 123 -> 122 (7.5%).  Gate: checked 71 failures 0.

## `ApplySig.java`: full-signature replacement, and the body it resets

`SetReturn` could not change a far-pointer return (`NullPointerException: storage is null`) and
`Variable.setDataType` refuses Ghidra's auto hidden return-storage parameter (`Auto-parameter may
not be modified`).  `ApplySig.java` builds a `FunctionDefinitionDataType` and applies it with
`ApplyFunctionSignatureCmd`, which replaces the whole prototype in one step:

```
ok alignToSeg : uint16_t alignToSeg(far_t ptr)
applied=1 failed=0
```

That is the signature the body and the call site both require (`[BP+6]` offset, `[BP+8]` segment,
caller `lbm_decode_body` pushes exactly two words with `ADD SP,0x4`).

**Caveat discovered by measurement:** `ApplyFunctionSignatureCmd` also **resets the function body**
to the single entry instruction.  `FnGaps` reported `alignToSeg bytes=1` immediately afterwards, so
the body had to be restored explicitly:

```
SetBody 30e6:0000 30e6:0000 30e6:0023
ok bytes=36 ranges=1
```

Any future use of `ApplySig` must capture the body ranges first and re-apply them after.  For
`alignToSeg` the restored 36 bytes end in `RETF` at `0x0023` and cover the whole function, so nothing
was lost.  The decompiler still prints `return 0;` because the `JZ` at `0x000f` carries a flow
reference to `0x3000:0e75`, an address outside the function — a pre-existing flow defect, not a
consequence of the signature change.

`__return_storage_ptr__` never appears in the audit's auto-parameter count (it does not match the
`param_\d+`/`in_stack_*` patterns), so this fix does not move the metric; it corrects the prototype.

## The EMS helpers build a documented EMM 4.0 request block (12 parameters)

`ems_memmove1` (`1000:05c5`) and `ems_memmove2` (`1000:0632`) both fill the same request
block and then issue `INT 67h`.  The block layout is EMM function 57h (Move/Exchange Memory
Region):

```
+0  DWORD length
+4  BYTE  source memory type (0 = conventional, 1 = expanded)
+5  WORD  source handle
+7  WORD  source offset
+9  WORD  source page
+B  BYTE  destination memory type
+C  WORD  destination handle
+E  WORD  destination offset
+10 WORD  destination segment/page
```

`ems_memmove1` writes it as

```
emms_var05b7 = 1;                                  /* source type: expanded */
emms_var05b8 = EMS_Handle;                         /* source handle        */
emms_var05ba = param_3 & 0x3fff;                   /* source offset        */
emms_var05bc = (param_4<<1 | (param_3<0))<<1 | ((param_3<<1)<0);  /* source page */
emms_var05be = 0; emms_var05bf = 0;                /* dest: conventional   */
emms_var05c1 = param_1; emms_var05c3 = param_2;    /* dest offset/segment  */
emms_var05b3 = param_5; emms_var05b5 = param_6;    /* length low/high      */
```

so `param_1/param_2` are the conventional destination (`dstOfs`/`dstSeg`),
`param_3/param_4` the expanded source offset (`srcEmsOfs`/`srcEmsOfsHi`), and
`param_5/param_6` the 32-bit length (`lenLo`/`lenHi`).  `ems_memmove2` writes the mirror
image (source conventional at `+4..+8`, destination expanded at `+B..+10`), giving
`dstEmsOfs`, `dstEmsOfsHi`, `srcOfs`, `srcSeg`, `lenLo`, `lenHi`.  All twelve were retyped
`uint16_t` after the rename.

## Call-site arity for two more functions (9 parameters removed)

### `ovc49_body1` (`8699:18c4`): one argument

All four call sites in `ovc49_drawAgents` push exactly one far pointer:

```
8699:1fec  PUSH 0x1726          ; segment
8699:1fef  PUSH AX              ; offset
8699:1ff1  CALL 0x8000:8254
8699:1ff4  ADD SP,0x4          ; 4 bytes
```

and the 150-byte body reads only `[BP+6]` as `agnt_t *`.  `TrimParams` 5 -> 1; the body was
untouched (`FnGaps` still reports 150 bytes, 0 gaps).

### `ovc18_textTypeLen` (`48ac:0382`): four word arguments

Its own body reads `[BP+6]` (byte), `[BP+8]`, `[BP+0xa]` and `[BP+0xc]`, and all four call
sites push four words and clean 8 bytes:

```
48ac:0a88  PUSH 0x0
48ac:0a8f  PUSH ES:[0x899d]     ; GfxRndSeed2
48ac:0a99  PUSH ES:[0x899f]     ; GfxRndSeed
48ac:0aa3  MOV AL,ES:[0x90e4]   ; PartyCount
48ac:0aa7  ADD AL,0xff
48ac:0aa9  PUSH AX
48ac:0aab  CALL ovc18_textTypeLen
48ac:0aae  ADD SP,0x8
```

(the thunk `2342:002a JMPF 0x4000:8e42` lands on the same entry, and its three callers in
`ovc22_usesRandBelow2` plus the one in `ovc30_textDivideError` also push four words).  The
old 9-parameter prototype was fabricated: `ApplySig` replaced it with
`char *ovc18_textTypeLen(uint8_t partyIndex, uint16_t destX, uint16_t destY, uint16_t
param_4)`.  `partyIndex` is proved by the prologue (`SHL AX,2` then `LES BX,ES:[BX+0]` on the
`217a` far-pointer table) and by the record scan `*(record+9) != partyIndex`; `destX`/`destY`
are the words it forwards into positions 3 and 4 of
`ovc15_usesLDIV_at_(x,y,destX,destY,gindex,animFrame,partyIndex)`.  The 4th word is left as
`param_4` because its only use is a branch selector.  `FnGaps` confirms the body kept its 373
bytes.

Parameters: 1634 -> 1625 total, auto 122 -> 101 (6.2%).  Gate: checked 71 failures 0.

## CRT prototypes: far pointers determined from `LES`/`LDS` prologues (11 parameters)

The earlier batch named these arguments but left their *widths* as two-byte pointers, which
put every later argument at the wrong stack offset.  Each is now settled by the load in the
prologue, and replaced with `ApplySig` (which also removes the auto names that were really
segment halves):

| function | machine-code proof | corrected prototype |
|---|---|---|
| `memcmp` | `LDS SI,[BP+6]`, `LES DI,[BP+0xa]`, count `[BP+0xe]` | `int16_t memcmp(char *32 s1, char *32 s2, uint16_t n)` |
| `__fstrncpy` | `LES DI,[BP+0xa]` (src), `LES DI,[BP+6]` (dst), `[BP+0xe]` (count) | `__fstrncpy(char *32 dst, char *32 src, uint16_t n)` |
| `_fstrstr` | `LES BX,[BP+0xa]` (needle); haystack at `[BP+6]`/`[BP+8]` | `_fstrstr(char *32 haystack, char *32 needle)` |
| `printf` | pushes `[BP+8]` then `[BP+6]` as one format pointer, `LEA AX,[BP+0xa]` is the vararg area | `void printf(char *32 fmt)` |
| `_sprintf` | `LES BX,[BP+6]` (dest), `[BP+0xa]`/`[BP+0xc]` (fmt), `LEA [BP+0xe]` varargs | `void _sprintf(char *32 buf, char *32 fmt)` |
| `vsprintf` | `LES BX,[BP+6]` (buf), `[BP+0xa]`/`[BP+0xc]` (fmt), `[BP+0xe]` third word | `int16_t vsprintf(char *32 buf, char *32 fmt, uint16_t ap)` |
| `_atoi`, `_atol` | `_atoi` pushes `[BP+8]`+`[BP+6]` into `_atol`, and `_atol` does `LES SI,[BP+6]` | `_atoi(char *32 s)`, `_atol(char *32 s)` |
| `sprintf_strputn` | near function: `LES BX,[BP+4]` (dest), src `[BP+0xa]`/`[BP+8]`, `n` at `[BP+0xc]` | `uint16_t sprintf_strputn(char *32 dest, char *32 src, uint16_t n)` |

The former `param_2` of `printf`, `_atoi` and `__fstrncpy` were the **segment halves** of
those far arguments, not separate parameters.  For example `printf`'s old
`(char *fmt, undefined2 param_2)` described 4 bytes while the body uses `[BP+6]` and
`[BP+8]` as a single 32-bit format pointer.

### A tool caveat worth recording

Giving `_atol` a 32-bit return type made Ghidra insert a hidden
`int32_t *__return_storage_ptr__` parameter and push `s` to `[BP+8]`, so the prototype was
reverted to a 16-bit return with the far parameter kept.  `__cdecl16far` handles 32-bit
returns through hidden storage in this Ghidra processor module, the same quirk that made
`SetReturn` fail for `alignToSeg`.

`ovc26_usesRandBelow`'s last two arguments were also named `flagsOfs`/`flagsSeg`, because the
body forwards them straight into `attact_usesEntities(entityIndex,x,y,flagsOfs,flagsSeg)`.

Parameters: 1625 -> 1622 total, auto 101 -> 88 (5.4%).  Gate: checked 71 failures 0.

### `fmReadIntoHimem`: the file name is a far pointer split across two slots

Its prologue pushes `[BP+8]` then `[BP+6]` as one far argument to
`open_wait_unlock_and_disk`:

```
474a:0bb0  PUSH word ptr [BP + 0x8]
474a:0bb3  PUSH word ptr [BP + 0x6]
474a:0bb7  CALL 0x4000:8010
474a:0bba  ADD SP,0x4
```

so `param_2` is the segment half of `filename`, not a separate argument.  Because the
existing slots already sit at the right offsets (`skipLo` is `[BP+0xa]`, `skipHi`
`[BP+0xc]`, `useEms` `[BP+0xe]`, `limitLo` `[BP+0x10]`, `limitHi` `[BP+0x12]`), only the name
was corrected to `filenameSeg` rather than re-typing the pair into one pointer.

Parameters: auto 88 -> 87 (5.4%).  Gate: checked 71 failures 0.

## DOS/CRT wrappers and the drawing helpers (15 parameters)

| function | machine-code proof | corrected prototype |
|---|---|---|
| `_creattemp`, `_creatnew` | `PUSH [BP+8]; PUSH [BP+6]` (far path) then `PUSH [BP+0xa]` (attrib), `MOV AL,0x5a`/`0x5b` | `int16_t _creattemp(char *32 path, uint16_t attrib)` (same for `_creatnew`) |
| `_setblock` | `MOV AH,0x4a; MOV BX,[BP+8]; MOV ES,[BP+6]; INT 21h` = DOS Resize Memory Block | `_setblock(uint16_t seg, uint16_t size)` |
| `farfree` | callers push segment then offset; body compares only `[BP+8]` with `malloc__last`, and `malloc_FreeLastBlock` stores `brkSeg` there | `ofs` (unused) + `seg` |
| `fseek` | `PUSH [BP+8]`/`PUSH [BP+6]` into `fflush` and `LES BX,[BP+6]` = far FILE; `MOV SI,[BP+0xe]` is checked against 1 (`SEEK_CUR`); `SUB [BP+0xa],AX; SBB [BP+0xc],DX` adjusts the 32-bit offset | `fseek(uint16_t *32 stream, uint16_t offsetLo, uint16_t offsetHi, uint16_t whence)` |
| `drawLine2` | `LDS SI,[BP+6]` (RLE source), `LES DX,[BP+0xa]` (destination), `MOV DI,[BP+0xe]` = count; the single caller pushes 5 words and `ADD SP,0xa` | `int16_t drawLine2(char *32 src, char *32 dst, uint16_t count)` |
| `countRunLength` | `LDS SI,[BP+6]` (far source), then `[BP+0xa]` vs `[BP+0xc]` choose the smaller as the scan bound | `int16_t countRunLength(char *32 src, uint16_t avail, uint16_t maxRun)` |
| `driver_loop1` | `MOV ES,[BP+0xe]` sets the destination segment; `MOV AX,[BP+0xa]; XCHG AH,AL` computes `y*256 + y*64 = y*0x140` for `y < 256` | `(x1, x2, uint16_t y, colour, uint16_t dstSeg)` |
| `stats_formatThousands` | `PUSH [BP+8]`/`PUSH [BP+6]` as one far text pointer; `[BP+0xa]`/`[BP+0xc]` is the 32-bit value passed to `litoa10`/`LDIV_at_` | `char * stats_formatThousands(char *32 text, uint32_t value)` |

Two corrections are worth noting.  `fseek`'s previous `offsetHi`/`offsetLo` names sat one word
too high: the 32-bit offset is adjusted at `[BP+0xa]`/`[BP+0xc]`, and `[BP+0xe]` (read into
`SI`) is `whence`, tested against `1`.  `farfree`'s previous `ofs` was really the **segment**:
the callers push segment first, and the value compared with `malloc__last` is the paragraph
(`brkSeg`), while the offset half is never touched.

### Refused with the model defect recorded

* `blit_compute1`: the caller uses a **near** `CALL`, yet Ghidra stores the parameters with the
  far layout, and the body's `LES BX,[BP+0xc]` does not line up with the 4-byte `param_4` at
  `Stack[0xc]` (= `[BP+0xe]`).  Renaming from those offsets would shift every later argument.
* `init_usesRandBelow`: its `param_4`/`param_5` are the offset/segment of one far out-pointer
  (`&local_e` + `SS` at the caller), but the decompiler renders `[BP+0xe]` as a separate
  `undefined1 in_stack_0000000e`, so the two slots cannot be merged safely.
* `__INITEMSPAGE`: three words are genuinely pushed (`_OvrInitEms` at `1403:0963-096f`), but
  the body only shows them being copied to the Borland EMS state (`[0x34]`/`[0x36]`) and used
  as the `INT 67h AH=43h/47h/48h` argument; no name beyond the EMM call sequence is provable.

Parameters: 1622 -> 1619 total, auto 87 -> 72 (4.4%).  Gate: checked 71 failures 0.

## Two more far-pointer fixes, and a Ghidra alignment trap that had to be reverted

### `moveto` (`1000:1d25`): two far pointers, not two near ones

The prologue loads both arguments with `LES` and the function returns with `RET 0x8`:

```
1000:1d28  LES BX,[BP + 0x8]      ; *nextPos
1000:1d2b  MOV DX,word ptr ES:[BX]
1000:1d2e  LES BX,[BP + 0x4]      ; *curPos
1000:1d31  CMP DX,word ptr ES:[BX]
1000:1d34  JZ  ...
1000:1d36  MOV BH,0x0 / MOV AH,0x2 / CALL VideoInt   ; set cursor
1000:1d40  MOV word ptr ES:[BX],DX                   ; *curPos = new position
1000:1d43  INC DL                                     ; advance column, wrap by [0x88b4]
1000:1d52  MOV word ptr ES:[BX],DX                   ; *nextPos = following position
```

so `curPos` is the value already sent to the BIOS cursor and `nextPos` the position the next
character will use.  Both are far pointers, replaced with
`void moveto(uint16_t *32 curPos, uint16_t *32 nextPos)`.

### `_crtinit_system` (`1000:1418`): two far string pointers

```
1000:141d  LES BX,[BP + 0x4] ; INC [BP+4] ; MOV AL,ES:[BX]
1000:1426  LES BX,[BP + 0x8] ; INC [BP+8] ; CMP AL,ES:[BX]
```

each argument is advanced by one **word** between fetches, which is the signature of a far
pointer, not a near one.  Corrected to
`int16_t _crtinit_system(char *32 s1, char *32 s2)`; storage `Stack[2]:4, Stack[6]:4`
matches `[BP+4]`/`[BP+8]`.

### The alignment trap: `ApplySig` with 4-byte parameters

Ghidra lays out stack parameters with alignment relative to the **start of the argument list**:
a 4-byte pointer is placed at a relative offset that is a multiple of 4, inserting padding on
the 8086 stack where none exists.  Two signatures exposed it and had to be reverted:

* `attact_compute2(byte menuIndex, byte *32 pctOut, ...)`: the real `pctOut` is at `[BP+8]`
  (`3f0b:227f LES BX,[BP+8]`), but because the byte occupies relative offset 0 the pointer was
  placed at `Stack[0x8]` = `[BP+0xa]`, so the decompiler rendered
  `CONCAT22((char *)pctOut,in_stack_00000006)`;
* `__LONGTOA(char alphaBase, char signed, uint radix, char *32 buf, ...)`: the real `buf` is
  at `[BP+0xa]` (`1000:0bbe LES DI,[BP+0xa]`), but after the two chars and the word radix the
  pointer was moved to `Stack[0xa]` = `[BP+0xc]`, and the decompiler started doing arithmetic
  on `buf._2_2_`.

Both were restored to the coherent two-byte-pointer prototypes (`char *buf` + `param_5` as the
segment half, `byte *pctOut` + `param_3`/`param_4`), which keep the existing body model and the
auto names.  `ApplySig` with `*32` is only used where the 4-byte argument lands on a
relative offset divisible by four — as in `memcmp` (`0,4,8`), `_sprintf` (`0,4`),
`sprintf_strputn` (`0,4,8`), `fseek` (`0,4,8,12`) and `moveto` (`0,4`).

Parameters: auto 72 -> 68 (4.2%).  Gate: checked 71 failures 0.

### ttact_usesAlignUp43: a far function that Ghidra modelled as near

The callers use the small-model far-call idiom: PUSH CS followed by a near CALL, and the
callee returns with RETF (so the pushed CS supplies the return segment):

`
3f0b:0749  PUSH 0x2410            ; argument segment
3f0b:074c  PUSH -0x6f8c           ; argument offset  (2410:9074)
3f0b:0750  PUSH CS                ; return segment for RETF
3f0b:0751  CALL 0x3000:0e61
3f0b:0754  ADD SP,0x4             ; callers pop the 4 argument bytes
`

and the body starts 3f0b:1db9 LES BX,[BP+0x6], i.e. it reads a 4-byte far pointer at
[BP+6].  Ghidra had the function as near, so param_1 was stored at Stack[0x2] ([BP+4])
and the decompiler read in_stack_00000004 instead.  Applying
oid attact_usesAlignUp43(uint16_t *32 value) with __cdecl16far puts the parameter at
Stack[0x4]:4 and the body now decompiles as ovr_alignUp4(*value).

### Convention audit: no remaining near/far mismatches

scripts/ghidra/ConvCheck.java, ConvCheck2.java and ConvCheck3.java scan every function for a
disagreement between its declared convention and its own return instruction (RETF vs RET),
and for parameters still stored on the near base Stack[0x2] inside a RETF function:

`
ConvCheck  : SUMMARY nearButFar=0 farButNear=0 noReturn=627
ConvCheck2 : SUMMARY nearLayoutFarFuncs=0
ConvCheck3 : SUMMARY hits=0
`

The only such function was ttact_usesAlignUp43, fixed above; every other function with
parameters is on the base its return instruction implies.  (The 627 no-return functions are
the ovr_* thunks and jump-table stubs.)

## Final parameter names from the remaining stack-passed bodies

| function | old | new | evidence |
|---|---|---|---|
| `ovc45_usesGfxRndSeed2` | `param_1` | `x` | `ovc45_getUnitType(*x - i, GfxRndSeed2)` for i = 0..3, then `*x -= i` when the found unit type's height exceeds i; the parameter is an in/out x coordinate |
| `attact_usesEntityCount2`, `attact_usesAgntCount2` | `param_2` | `enemySum` | the second 32-bit accumulator: `sum` receives the faction-0 total and `param_2` the faction-!=0 total (entity: `animFrame*level*level`; agent: `strength`, both gated by `flags & 0xae4 == 0`) |
| `ovc45_compute7` | `param_1`, `param_2` | `a`, `b` | the body is exactly `CONCAT11(product>>0xb, product>>3)`, i.e. `(a*b) >> 3`; the two factors are symmetric, so the names record the only structure the code has |

Parameters: auto 67 -> 62 (3.8%).  Gate: checked 71 failures 0.

### Two more parameters from their callees (62 -> 60)

**manage_applyUnitFilter**: the callers push **four** words (`4d05:329c` pushes
`SS:[BX+2]`, `4d05:32a0` pushes `SS:[BX]`, then the computed unit type and the party byte;
`ADD SP,0x8`), and the body pushes `[BP+0xc]` then `[BP+0xa]` as one far pointer into
`stsprintf` with the format "Only units of %s loyal to %s the %s are displayed."
(`2410:557d`).  So the third word is the offset half of a far name pointer and the fourth
its segment.  The prototype became `void manage_applyUnitFilter(uint8_t partyIndex,
uint16_t unitType, char *32 unitName)`; storage `Stack[4]:1, Stack[6]:2, Stack[8]:4`
matches `[BP+6]/[BP+8]/[BP+0xa..0xd]`.

**ovc40_usesBlitLabel**: `[BP+0x10]` is loaded at `69c8:00ec` and pushed last among
`[BP+0x10]`, `0x13f`, the `[0x8a27]/[0x8a25]` far pointer and the `[BP+8]/[BP+6]` text
pointer, then `CALLF 2000:2c97` (`ovr_blitLabel(char *text, uint8_t *widths,
int16_t max_width, uint8_t term)`).  Cdecl order makes it the `term` argument, so
`param_4` became `term`.

Parameters: auto 62 -> 60 (3.7%).  Gate: checked 71 failures 0.

## Four more parameters from their readers (60 -> 56)

| function | change | evidence |
|---|---|---|
| `saveui_readSavesList` | `param_2` -> `entriesSeg` | `4528:11e2 MOV ES,[BP+0x8]` then `4528:11e8 MOV BX,[BP+0x6]` loads the first argument as one far pointer; the second word is its segment |
| `ovc42_textProvidesMoreHousing` | two words -> one `uint32_t timeoutTicks` | the wait loop compares the 32-bit elapsed counter against the two words: `6d7a:0086 CMP DX,[BP+0x8]` / `6d7a:008d CMP AX,[BP+0x6]`; the callers pass `(0x48,0)`, `(0x10,0)`, `(0x30,0)` |
| `manage_textAllProperty` | `param_1` byte -> `uint16_t partyIndex` | the body checks the word at `[BP+4]` against `0xff` and indexes the `GLeaderSheets` far-pointer table with it: `if (in_stack_00000004 == 0xff)` then `GLeaderSheets[index]` |
| `gfxRlePrepare` | `param_7` -> `flip` | zero selects the normal extent and draw routine (`scale * *(gfx+1) >> 4`, table `GUnitDescriptions+0x12`); nonzero selects the flipped extent and routine (`scale * ((*(gfx+10)-1) - *(gfx+1)) >> 4`, table `&GUnitDescriptions[0xf].seg`) |

Parameters: auto 60 -> 56 (3.5%).  Gate: checked 71 failures 0.

### `attact_usesAlignUp4`'s fourth argument is the flags buffer (55 auto)

Both call sites in `attact_usesEntities` push the callee's own `flagsOfs`/`flagsSeg` parameters first:

```
3f0b:0bc8  PUSH word ptr [BP + 0xe]   ; flagsSeg
3f0b:0bcb  PUSH word ptr [BP + 0xc]   ; flagsOfs
3f0b:0be5  PUSH AX                   ; entity party byte at +0x1a
3f0b:0be6  PUSH word ptr [BP - 0x4]
3f0b:0be9  PUSH word ptr [BP - 0x2]
3f0b:0bed  CALL attact_usesAlignUp4
```

so the 4-byte `param_4` is that far flags pointer (the body's `in_stack_0000000a == 0 && (int)param_4 == 0` is the both-words-zero test).  Renamed `flags`; the widths were left alone because a 4-byte parameter at relative offset 6 would be re-aligned by Ghidra and shift `x`/`y`.

Parameters: auto 56 -> 55 (3.4%).  Gate: checked 71 failures 0.

## Far out-pointers done with `far_t` (alignment 2), and the sixth arena argument (55 -> 53)

### `attact_textArena`: the prototype omitted `[BP+0x10]`

The body reads four words after the first two: `[BP+0xa]` (mode, loaded into `DI`), `[BP+0xc]`
(party byte compared with the entity), `[BP+0xe]` (the `ovr_alignUp4` argument and the `dx`
subtrahend at `3f0b:1a8f`) and `[BP+0x10]` (the `dy` subtrahend at `3f0b:1aaf`).  The old
prototype ended at `x`, so the `dy` computation read a phantom `in_stack_0000000e`.  Corrected
to `attact_textArena(uint16_t *foundIndexOut, uint16_t param_2, char mode, uint8_t partyIndex,
uint16_t x, uint16_t y)`; storage `Stack[4]:2, [6]:2, [8]:1, [a]:1, [c]:2, [e]:2` matches
`[BP+6..0x11]`, and the body now reads `entity.y - y`.

### `attact_compute2/3`: `far_t` keeps the exact offsets

The earlier attempt to type the far out-pointers as `*32` moved them: Ghidra aligns 4-byte
*pointers* to a relative offset divisible by four.  `far_t` is a two-word structure, so its
alignment is 2 and the layout is exact:

```
attact_compute2(uint16_t menuIndex, far_t pctOut, far_t remainderOut, far_t partOut)
  Stack[4]:2, Stack[6]:4, Stack[a]:4, Stack[e]:4   = [BP+6],[BP+8..b],[BP+c..f],[BP+10..13]
attact_compute3(far_t table, uint16_t index, far_t pctOut, far_t remainderOut, far_t partOut)
  Stack[4]:4, Stack[8]:2, Stack[a]:4, Stack[e]:4, Stack[12]:4 = [BP+6..9],[BP+a],[BP+c..f],...
```

These offsets are exactly the `LES BX,[BP+8/0xc/0x10]` (compute2) and
`LES BX,[BP+6/0xc/0x10/0x14]` (compute3) operands, and the decompiler renders the dereferences
as `*(char *)pctOut`, `*(char *)partOut`, `*(char *)remainderOut` and (compute3) `table.ofs` /
`table.seg`.  Body sizes stayed 177/168 bytes.

This is the same 2-byte-alignment trick needed for any future 4-byte argument that does not
start on a multiple of four.

Parameters: auto 55 -> 53 (3.3%).  Gate: checked 71 failures 0.

### `saveui_usesBlitGfx10`'s last argument is the row (53 -> 52)

`param_5` is stored at `Stack[0xe]` (= `[BP+0x10]`), which is exactly the word the body uses as
`in_stack_00000010`: the drawn row's y is `row * 0xf + 0x1d` and the rectangle is
`rect.y = ...`, `rect.h = ... + 0x28` in the same expression.  Renamed `row`.

Parameters: auto 53 -> 52 (3.2%).  Gate: checked 71 failures 0.

## `F_SCOPY`: length in CX, `RETF 8` — and the phantom locals it was creating

`F_SCOPY` (`1000:094f`) was modelled with three 2-byte parameters, but its body is

```
1000:0955  LDS SI,[BP + 0x6]      ; far source
1000:0958  LES DI,[BP + 0xa]      ; far destination
1000:095c  SHR CX,0x1 / REP MOVSW ; count arrives in CX
1000:0962  REP MOVSB
1000:0968  RETF 0x8               ; the callee pops four argument words
```

so the correct prototype is `void F_SCOPY(far_t src, far_t dst)`, with the byte count in
`CX` (a `__fastcall`-style helper, not a C argument).  The old three-word model left a
two-byte stack drift after every call, which is why several functions carried stack
variables at offsets no instruction touched.

## Driver string/memory helpers: the far pointers were split in two

| function | machine code | corrected prototype |
|---|---|---|
| `driver_unrleScreen` | `LDS SI,[BP+6]`, `LES DI,[BP+0xa]` | `(far_t src, far_t dst)` |
| `driver_copyWords` | `LDS SI,[BP+6]`, `LES DI,[BP+0xa]`, `MOV CX,[BP+0xe]` | `(far_t src, far_t dst, uint16_t count)` |
| `driver_zeroWords` | `LES DI,[BP+6]`, `MOV CX,[BP+0xa]` | `(far_t dst, uint16_t count)` |
| `driver_loop3` | `LDS SI,[BP+6]`, `LES DI,[BP+0xa]` | `(far_t src, far_t dst)` |
| `stash_loadFromStrongDat` | body uses `param_1._2_2_` as the segment | `(far_t entry)` |

`stash_loadFromStrongDat` previously read the pointer as an `undefined4`, which made the
segment arithmetic `param_1._2_2_`; with `far_t` it decompiles as
`ovr_mkp((uint32_t *)entry.ofs, entry.seg, ...)`.

### `__LONGTOA` keeps its split layout on purpose

Typing `buf` as `far_t` puts it at `Stack[8]:4` (= `[BP+0xa..0xd]`), which matches
`1000:0bbe LES DI,[BP+0xa]`.  The following 32-bit argument, however, is re-aligned by
Ghidra to `Stack[0xe]:4` (`[BP+0x10]`), two bytes past its real slot `[BP+0xe]`, because a
4-byte integer aligns to 4 relative to the argument-list start.  The exact model is the
split one:

```
__LONGTOA(char alphaBase, char signFlag, uint16_t radix, char *buf, uint16_t bufSeg,
         uint16_t valueLo)
```

with `buf`/`bufSeg` being the two halves of the far pointer and `valueLo` the low half of
the 32-bit value (the high half is consumed by the compiler's own 32-bit sequence).

Parameters: 52 -> 46 (2.8%).  Gate: checked 71 failures 0.

### `ovc42_showAgentStats`'s second argument is the party byte (46 -> 45)

After typing the temporary record as `agnt_t`, the store reads
`agntRec.entity._3_1_ = param_2`, i.e. the byte at `agnt_t+0x1a`.  That is the same slot the
entity code reads as the owning party (`*(byte *)((int)&entity + 3)`), so the argument is
`partyIndex`.

Parameters: auto 46 -> 45 (2.8%).  Gate: checked 71 failures 0.

## Two callees with far out-parameter blocks (45 -> 43)

### `agnt_usesAgntCount2` (`3b1d:093e`): three far out-pointers

The caller pushes `agnt` plus three `SS:offset` pairs and does `ADD SP,0x10`
(`8699:0d6b-0d85`), i.e. 4 + 3*4 bytes.  Mapping the callee's accesses:

```
*distance = 0xffff;                       /* the word at [BP+0x12] */
... if (|dx|+|dy| < *distance) {
      *distance = |dx|+|dy|;
      *xDir = signum(dx);                /* [BP+0xa]  */
      *yDir = signum(dy);                /* [BP+0xe]  */
}
return *distance != 0xffff;
```

so the signature is
`bool agnt_usesAgntCount2(agnt_t *agnt, uint16_t *32 xDir, uint16_t *32 yDir, uint16_t *32 distance)`.
The relative offsets 4/8/12 are all divisible by four, so `*32` keeps the exact layout; the
caller's `local_4` is the distance and became `distance`.

### `init_usesRandBelow` (`3381:24c3`): two far in/out bytes

`init_usesRandBelow2` calls it with two `SS:offset` pairs (`3381:2ae6-2af7`, `ADD SP,0xe`):

```
3381:2ae6  PUSH SS / LEA AX,[BP-0xd] / PUSH AX   ; far ptr A
3381:2aeb  PUSH SS / LEA AX,[BP-0xc] / PUSH AX   ; far ptr B
3381:2af0  PUSH [BP-0x11] / PUSH DI / PUSH SI
3381:2af7  CALL 3000:5cd3                        (= 3381:24c3, delta 0x3810)
```

and the callee reads `LES BX,[BP+0xc]` and `LES BX,[BP+0x10]`.  Its tail is the proof of
meaning:

```
if (*lastDir == dirDelta) (*sameDirCount)++;
else { *sameDirCount = 0; *lastDir = dirDelta; }
```

Modelled as seven two-byte slots (the two far pointers kept split, since a four-byte pointer
at relative offset 6 would be re-aligned):
`uint16_t init_usesRandBelow(int16_t x, int16_t y, uint8_t dir, uint8_t *lastDir,
uint16_t lastDirSeg, uint8_t *sameDirCount, uint16_t sameDirCountSeg)`.
The body now dereferences `*_lastDir` / `*_sameDirCount` and the caller passes
`&lastDir, SS, &sameDirCount, SS`.

Parameters: auto 45 -> 43 (2.7%).  Gate: checked 71 failures 0.

## Driver helpers recovered from their own prologues (43 -> 39)

### `driver_scan1` (`2d63:044e`)

The whole 105-byte prologue fixes every argument:

```
2d63:0456  MOV CX,[BP + 0xa]       ; count
2d63:0459  LES DI,[BP + 0x6]       ; far buffer
2d63:045c  MOV DH,[BP + 0xe]       ; threshold
2d63:045f  LDS SI,[BP + 0x10]      ; far pattern
2d63:0464  MOV BL,[BP + 0xc]       ; fill byte
2d63:0467  MOV BP,[BP + 0x14]      ; ring index (BP is reused as an index register)
```

with DS:`[BP+SI]` and the `INC BP / AND BP,0xff` wrap proving the index role, and
`CMP DL,DH / JNC` proving the threshold role.  Corrected to
`void driver_scan1(far_t buf, uint16_t count, uint8_t fill, uint8_t threshold, far_t pattern,
uint16_t index)`; storage `Stack[4]:4, [8]:2, [a]:1, [c]:1, [e]:4, [12]:2` matches
`[BP+6]`, `[BP+0xa]`, `[BP+0xc]`, `[BP+0xe]`, `[BP+0x10]`, `[BP+0x14]`.

### `driver_compute3` / `driver_compute4` (`2d63:0652`, `2d63:0687`)

Both start `MOV AX,[BP+0xe] / MOV ES,AX`, so the fifth argument is the destination segment.
Renamed `dstSeg` and typed `uint16_t`; `driver_compute3` now decompiles as

```
puVar1 = (undefined2 *)(ofs + (uint)y * 0x140);
*puVar1 = CONCAT11(colour1,colour1);
*(undefined1 *)(puVar1 + 0xa0) = colour1;
```

Parameters: auto 43 -> 39 (2.4%).  Gate: checked 71 failures 0.

### `ovc38_scan1` (`68ac:0339`): two far strings, not two near pointers

The prologue tests both halves of the second argument and loads both with `LES`:

```
68ac:0340  MOV AX,[BP + 0xa] / OR AX,[BP + 0xc]   ; second far pointer null test
68ac:034d  LES BX,[BP + 0x6]                      ; first far pointer
68ac:0355  LES BX,[BP + 0xa]                      ; second far pointer
```

and its only caller pushes two far pointers and cleans 8 bytes
(`68ac:04e0-04f2`: `PUSH ES:[BX-2]`, `PUSH ES:[BX-4]`, `PUSH SS`, `LEA AX,[BP+0xff32]`,
`ADD SP,0x8`).  The body compares the two first bytes, then walks to `'@'` and parses decimal
digits with `_ctype`, i.e. it compares two version strings.  Prototype:
`int16_t ovc38_scan1(char *32 s1, char *32 s2)`; storage `Stack[4]:4, Stack[8]:4` matches
`[BP+6..9]` and `[BP+0xa..0xd]`, and the body now reads `*s1` / `*s2`.

Parameters: auto 39 -> 37 (2.3%).  Gate: checked 71 failures 0.

## CRT helpers: what the bodies prove, and where Ghidra cannot express the ABI (37 -> 35)

### `__fputn` (`1000:2925`) is a **near** function with two far pointers

```
1000:292d  MOV DI,[BP + 0x8]      ; count (saved to [BP-2])
1000:2933  LES BX,[BP + 0x4]      ; far FILE stream  -> params start at BP+4
1000:2946  LES BX,[BP + 0xa]      ; far source buffer
1000:2949  INC word ptr [BP + 0xa] ; the buffer offset is advanced
```

`LES BX,[BP+4]` can only be a parameter if the function is `__cdecl16near` (under the far
convention the first argument starts at `BP+6` and `BP+4` is the return segment).  Corrected to
`uint16_t __fputn(far_t stream, uint16_t count, far_t buf)`; storage `Stack[2]:4, [6]:2, [8]:4`
matches `[BP+4]`, `[BP+8]`, `[BP+0xa]`.  The body now reads
`_fputc(*(char *)buf, stream_00)` and `__write(fd, buf.ofs, buf.seg, count)`.

### `__CHECKOVERLAY` (`1403:0890`): the second argument is the header segment

```
1403:0899  MOV ES,[BP + 0x8]      ; the segment argument
1403:08a0  CMP CX,ES:[0x0]        ; OVR header signature
1403:08a7  CMP word ptr ES:[0x10],0x0
1403:08af  CMP byte ptr ES:[0x20],0xcd
```

so `param_2` -> `hdrSeg` (typed `uint16_t`).  The first argument is loaded into `BX`
(`1403:08c3`) immediately before `CALLF [0x86]` and is not otherwise read, so it is a register
argument of that indirect callee and stays `param_1`.

### `N_LUMOD_at_` (`1000:09d8`): the ABI is real, but Ghidra rejects its offsets

The stub pops the near return address and re-pushes it with `CS`, then reads four words:

```
1000:09d8  POP CX / PUSH CS / PUSH CX     ; make the near call return far
1000:09e5  MOV AX,[BP + 0xa]              ; dividend low
1000:09e8  MOV DX,[BP + 0xc]              ; dividend high
1000:09eb  MOV BX,[BP + 0xe]              ; divisor low
1000:09ee  MOV CX,[BP + 0x10]             ; divisor high
```

i.e. `uint32 N_LUMOD_at_(uint32 dividend, uint32 divisor)` with the arguments at
`BP+0xa..0x10`.  Two Ghidra limits block an exact model, both reproduced:

* placing the parameters on the decompiler's own base (`Stack[2]`) is rejected with
  `InvalidInputException: Variable contains invalid stack parameter offset: dividendLo
  offset 2` — parameters may not sit below the return address;
* a 32-bit return under `__cdecl16far` inserts a phantom `__return_storage_ptr__` parameter
  (verified with `ApplySig /undefined4`).

Keeping the 16-bit-return form of the prototype (with the true storage set explicitly to
`DX:AX` by `SetProtoOffsets`) preserves the original three-parameter model and the `DX:AX`
return without the phantom parameter, so the function stays honestly at three auto parameters.
The exact ABI is recorded here instead of being guessed onto the wrong slots.

### New tool: `scripts/ghidra/SetProtoOffsets.java`

Sets parameters at explicit stack offsets and an explicit register return storage, e.g.
`1000:09d8 <TAB> /undefined4@DX:AX <TAB> __cdecl16far <TAB> param_1:/stdint.h/uint16_t:0x6 ...`.
It derives the stack address space from an existing variable (the factory does not list it) and
is what showed the `offset 2` rejection at first hand.

Parameters: auto 37 -> 35 (2.2%).  Gate: checked 71 failures 0.

### `ovc13_readPixel`'s third argument is a far `brect_t` (35 -> 34)

The whole body is five instructions of indexing after loading a segment from the argument:

```
3d16:018a  MOV AX,[BP + 0x8]        ; screenY
3d16:018d  MOV DX,0x140 / IMUL DX   ; y * 320
3d16:0192  MOV BX,[BP + 0x6]        ; screenX
3d16:0197  LES SI,[BP + 0xa]        ; far pointer
3d16:019a  MOV ES,word ptr ES:[SI + 0x8]   ; the segment comes from field +8
3d16:019e  MOV AL,byte ptr ES:[BX]  ; read the pixel
```

`brect_t` is exactly `{x, y, w, h, seg}` with `seg` at +8 (`ListFieldNames /stdint.h/brect_t`),
and the only in-overlay caller pushes `2410:045e`, i.e. `BlitRects + 3*10` (`BlitRects` is a
`brect_t[5]` at `2410:0440`), so the pointer is a blit rectangle whose `seg` field is the video
segment being read.  Corrected to
`undefined2 ovc13_readPixel(int16_t screenX, int16_t screenY, brect_t *32 surface)`.
`FnGaps` keeps the 30-byte body; note the decompiler does not model `MOV ES,mem`, so the body
still renders the read through the default segment.

Parameters: auto 35 -> 34 (2.1%).  Gate: checked 71 failures 0.

## `long` aligns to 2, not 4: the 32-bit parameter fix (34 -> 28)

`/stdint.h/uint32_t` has alignment 4 in this program's data organisation, which is what
shifted `__LONGTOA`'s value and `blit_compute1`'s source pointer.  Ghidra's builtin `long`
has alignment 2, which matches the 8086 argument layout.  Verified with
`SetProtoOffsets`: `long` at `Stack[0xa]` and `Stack[0xe]` stays at 0xa/0xe.

### `N_LUMOD_at_` now carries the proven ABI

```
1000:09d8  POP CX / PUSH CS / PUSH CX     ; near call turned into a far return
1000:09e5  MOV AX,[BP+0xa]  / MOV DX,[BP+0xc]   ; dividend (32-bit)
1000:09eb  MOV BX,[BP+0xe]  / MOV CX,[BP+0x10]  ; divisor  (32-bit)
```

`N_LUMOD_at_(long dividend, long divisor)` with the return storage set to `DX:AX`
(`SetProtoOffsets` `@DX:AX`) models both 32-bit values at their real offsets without the
phantom `__return_storage_ptr__`.  The decompiler still renders the four operand reads as
`in_stack_00000002..08` because its frame maps `BP+0xa` to `Stack[2]` (below the return
address, which Ghidra refuses to accept as a parameter) — the prototype storage is exact,
the body rendering is the documented stub limitation.

`__LONGTOA` profits directly: `long value` at `Stack[0xc]:4` (=`[BP+0xe..0x11]`) replaces the
old `valueLo` + implicit high word, and the body now computes `if (value < 0)` and
`value = CONCAT22(...)` on one 32-bit parameter.

### `uiInputText` / `ovc28_usesUiInputText`: shifted by one parameter

Both read pairs of words at `BP+6/8`, `BP+0xc/0xe`, so the old two-byte `entries`/`hint`
model was one parameter off.  The caller of `ovc28_usesUiInputText`
(`6018:1531-1549`) pushes seven words and cleans `0xe`:

```
PUSH SS / LEA AX,[BP-0x1] / PUSH AX   ; far page-index pointer, seeded 0
PUSH [BP+0xe] / PUSH [BP+0xc]         ; hint  (far)
PUSH [BP+0xa]                         ; count
PUSH [BP+0x8] / PUSH [BP+0x6]         ; entries (far)
```

so the signatures are

```
char * uiInputText(far_t entries, uint16_t count, far_t hint, uint8_t flags)
undefined2 ovc28_usesUiInputText(far_t entries, uint16_t count, far_t hint,
                                 uint8_t *pageOut, uint16_t pageOutSeg)
```

with `pageOut` the paging index (`*pageOut == 0`, `*pageOut * 8 + 8 < hint`,
`--*pageOut`).  The call now renders exactly as the machine code: `uiInputText(entries,count,
hint,0x0)`.

### `blit_compute1`: far source, and the clip bounds were off by one slot

`MOV BX,[BP+0xc]` + `MOV ES,[BP+0xe]` make the fourth argument a far pointer; `far_t`
(alignment 2) places it at `Stack[0xa]:4` = `[BP+0xc..0xf]`, which restores every later
offset.  With exact offsets the old names turned out to be shifted: `BP+0x1e` is added to y
when the slope accumulator crosses (`ADD SI,[BP+0x1e]`), while `BP+0x20`/`BP+0x22` are the
store guard bounds (`CMP SI,[BP+0x20]; JL`, `CMP SI,[BP+0x22]; JG`).  So
`clipTop` on 0x1e became `yJump`, `clipBottom` on 0x20 became `clipTop`, and `param_14` on
0x22 became `clipBottom`.  The body now reads
`if (src[...] != 0 && clipTop <= y && y <= clipBottom)` and `y += yJump`.

Parameters: auto 34 -> 28 (1.7%).  Gate: checked 71 failures 0.

### `ovc22_usesLUDIV_at_` takes an `entity_t` (28 -> 27)

Its only caller (`upd_usesAlignUp4`, `5087:36c8`) builds the argument from the entity array:

```
5087:36c8  MOV DX,0x37 / IMUL DX     ; entity_t is 55 = 0x37 bytes
5087:36d2  MOV DX,ES:[0x908e]        ; Entities.ofs
5087:36d7  ADD DX,AX
5087:36d9  PUSH ES:[0x9090]          ; Entities.seg
5087:36de  PUSH DX                   ; &Entities[index]
5087:36e0  CALL 0x5000:2126
```

and the callee reads `+0xf` (base.level) and `+0x1a` (the party byte at entity+3):
`entity_t *32 entity`.  The body now reads
`*(byte *)((int)&(peVar5->base).entity + 3)` and `(peVar5->base).level` by name.

Parameters: auto 28 -> 27 (1.7%).  Gate: checked 71 failures 0.

## Five more body-proven signatures (27 -> 19)

### `ovc27_textTakesHalfDamage3`: far agent + index

`LES BX,[BP+0x6]` / `LES BX,[BP+0xa]` / `LES BX,[BP+0xe]` are not all used, but the split
`CONCAT22(agntSeg, param_1._2_2_)` showed the first argument is a far pointer at `BP+6`, and
`BP+0xa` is multiplied by `0x34` (`agnt_t` stride) as an array index.  The function is far
(params at `BP+6`), so:
`void ovc27_textTakesHalfDamage3(agnt_t *32 agnt, uint16_t agntIndex)`; the body now reads
`paVar7->variant`, `paVar7->gdata`, and `agntIndex * 0x34`.

### `keyprocessor_usesBiosKeyAvail`: three far pointers

`LES BX,[BP+6]`, `LES BX,[BP+0xa]`, `LES BX,[BP+0xe]` prove the arguments are far pointers,
not near ones.  The only caller passes `&cursorX`, `&cursorY`, `&input`
(`6616:0842-0852`), and the body adjusts `*cursorY` in the 3-wide grid (`(v-7)%3+7`, `-0x18`),
`*cursorX` in 0..0xde, and writes `*input` = 1/2/3/4 (the caller then treats 0 as "poll the
mouse").  Signature:
`uint16_t keyprocessor_usesBiosKeyAvail(uint16_t *32 cursorX, uint16_t *32 cursorY,
uint8_t *32 input)`.

### `ovc28_compute2` is a wrapper

It forwards five words to `ovc28_usesUiInputText` plus a fresh page byte:
`ovc28_usesUiInputText(entries,count,hint,&uStack_3,unaff_SS)`, so its signature is
`void ovc28_compute2(far_t entries, uint16_t count, far_t hint)`.

### `ovc18_spawnClassAgent`: x/y/destX/destY/class/party/mode

The prologue loads `[BP+6]` into SI and `[BP+8]` into DI, and the spawn call does
`PUSH DI / PUSH SI` as the `x,y` arguments of `ovc15_usesLDIV_at_`; `[BP+0xa]`/`[BP+0xc]` are
pushed as its `destX/destY`; `[BP+0xe]` is compared with 5 (class), `[BP+0x10]` indexes the
`217a` leader-sheet table (`SHL 2`, `+0x3e`), and `[BP+0x12]` selects the spawn path
(`CMP ...,2`).  The only caller (`ovc18_textTypeLen`, `48ac:05cd-05e3`) pushes exactly these
seven words and does `ADD SP,0xe`:

```
void ovc18_spawnClassAgent(uint16_t x, uint16_t y, uint16_t destX, uint16_t destY,
                           uint8_t classStr, uint8_t partyIndex, uint16_t mode)
```

The old `fileId`/`anims` names were the x/y words (their storage is `Stack[4]:2`/`[6]:2`, and
the body never dereferences them).

### `__INITEMSPAGE`: the EMM AH=43h sequence names the three words

```
1403:0e59  OR byte ptr [0x38],0x2
1403:0e5e  MOV AX,[BP+0x8] / MOV [0x34],AX    ; frame segment slot
1403:0e64  MOV BX,[BP+0x6] / MOV [0x36],BX    ; page count slot
1403:0e6b  MOV DX,[BP+0xa] / OR DX,DX         ; pre-set handle?
1403:0e72  MOV AH,0x43 / INT 0x67             ; EMM allocate pages: BX = pages, DX = handle
1403:0e7f  MOV [0x32],DX                      ; handle slot
```

so `uint16_t __INITEMSPAGE(uint16_t pageCount, uint16_t frameSeg, uint16_t handle)`; the body
now stores `frameSeg` at +0x34, `pageCount` at +0x36 and allocates a handle when `handle==0`.

Parameters: auto 27 -> 19 (1.2%).  Gate: checked 71 failures 0.

### `ovc43_usesStExit`: a 32-bit gindex plus two far-pointer words (19 -> 16)

The prologue and tail:

```
6fbe:0141  MOV SI,[BP+0xa]                  ; forwarded to stshRead, unchanged
6fbe:0144  PUSH 0 / PUSH 0x10 / PUSH SS / LEA AX,[BP-0x10] / PUSH AX / PUSH SI
6fbe:018e  PUSH [BP+0x8] / PUSH [BP+0x6]    ; first pair of the final call
6fbe:0191  PUSH [BP+0xe] / PUSH [BP+0xc]    ; the sheet far pointer
6fbe:019a  PUSH SS / LEA AX,[BP-0x10] / PUSH AX ; the 32-bit remaining count
6fbe:01a0  CALL ovc43_usesFmFreeAudio
```

`ovc43_usesFmFreeAudio` is declared `(uint32_t gindex, char_sheet_t *sheet, uint16_t
sheetSeg)`, so its first argument consumes the **two** words `[BP+6]/[BP+8]` as one 32-bit
value.  That gives

```
void ovc43_usesStExit(uint32_t gindex, uint16_t hnd, uint16_t sheetOfs, uint16_t sheetSeg)
```

with `hnd` the word carried in SI and pushed as the only non-buffer argument of `stshRead`
(the reader has no prototype, so the handle role is proven by position, not by callee types).
Offsets: `Stack[4]:4, [8]:2, [a]:2, [c]:2` = `BP+6..9`, `BP+0xa`, `BP+0xc`, `BP+0xe`.

Parameters: auto 19 -> 16 (1.0%).  Gate: checked 71 failures 0.

## Three more from their operand maps (16 -> 13)

### `ovc22_usesAlignUp42`: two far outputs, a class and a flag mask

```
5087:413e  LES BX,[BP + 0x6]     ; first output pointer (ofs/seg 0x6/0x8)
5087:4147  LES BX,[BP + 0xa]     ; second output pointer (ofs/seg 0xa/0xc)
5087:40d1  CMP AL,byte ptr [BP + 0xe]   ; compared with record+9
5087:4139  TEST word ptr [BP + 0x10],DI ; mask test
```

with `*xOut = alignUp4(record+2)`, `*yOut = record+4`, `record[+9] == classIndex`,
and `(blockedFlags & OR(GMapFlags[y][x-2..x+1])) == 0`.  Signature:
`uint16_t ovc22_usesAlignUp42(uint16_t *32 xOut, uint16_t *32 yOut, uint8_t classIndex,
uint16_t blockedFlags)`; the old `yOutOfs`/`yOutSeg` pair was the second pointer split.

### `ovc23_usesAlignUp43`: the first argument is the x base

`MOV SI,[BP+6]` / `MOV DI,[BP+8]` / `MOV AL,[BP+0xa]`, and the body computes
`x + *(char *)(dir + 0x885)` and `unitIndex + *(char *)(dir + 0x889)` — the two half-step
tables.  So `param_1` -> `x` (`int16_t`).  Note: after that first use the compiler reuses the
same slot for a `GUnits` loop index (`puVar23[unitIndex]`), which is why one variable shows
both roles.

### `ovc18_textTypeLen`: the fourth word selects the label pair

`if ((uint8_t)param_4 == 0)` takes `puStackY_22 = 0x906a`, otherwise `0x904a`; the value is
then forwarded as `ovc18_spawnClassAgent`'s `mode` argument (`48ac:05cd-05e3`).  Renamed
`textVariant` (`uint8_t`).

Parameters: auto 16 -> 13 (0.8%).  Gate: checked 71 failures 0.

## Split far pointers and a missing argument (13 -> 9)

### `audio_parseHexDigit`: driver block far pointer

`MOV AX,[BP+8] / MOV DX,[BP+6] / LES BX,[BP-4]` is one far pointer, not an offset plus a
separate word.  The body writes `driverData[0x108]` and clears `[0x109]`, so:
`void audio_parseHexDigit(char *32 driverData, char ch)`.

### `init_special_graphics` / `ovc20_compute1`: the block pointer

Both load the same far pointer from `[BP+6]/[BP+8]` and touch `+0x11`/`+0x13` (a far handle):
one checks it and frees it (`handle.ofs/seg`, `ovr_stshFree`), the other zeroes it.  Both are
now `(char *32 gfxBlock)`; the old `gfxBlock`/`param_2` pair was the split pointer.

### `attact_textAbnormalProgramTermination`: two arguments, not one

The prologue reads `[BP+6]` (the value scaled by `LXMUL`) **and** `[BP+8]` (passed to
`attact_countPartyUnits`).  The old prototype had only `param_1`.  Corrected to
`uint16_t attact_textAbnormalProgramTermination(uint16_t value, uint8_t partyIndex)`; the body
now calls `attact_countPartyUnits(partyIndex)`.

Parameters: auto 13 -> 9 (0.6%).  Gate: checked 71 failures 0.

## `___exit`'s protocol, and two table-index parameters (9 -> 4)

### `___exit`: status + two word flags

The four small wrappers around it give the meaning matrix directly:

```
1000:08fd exit(status):   PUSH 0; PUSH 0; PUSH [BP+6]; CALL   ; (status, 0, 0)
1000:090c __exit(status): PUSH 1; PUSH 0; PUSH [BP+6]; CALL   ; (status, 0, 1)
1000:091e _cexit():       PUSH 0; PUSH 1; PUSH 0;       CALL   ; (0, 1, 0)
1000:092c (4th):          PUSH 1; PUSH 1; PUSH 0;       CALL   ; (0, 1, 1)
```

and the callee tests them as **words**: `MOV SI,[BP+8]` (skip the atexit loop and the stream
flushes), `CMP word ptr [BP+6],0` (return instead of terminating), `PUSH [BP+4]` (the status
handed to `_terminate`).  Typing the flags as bytes split each word into a byte parameter plus
an `in_stack` leftover; as words the body binds:

```
void ___exit(uint16_t status, uint16_t noTerminate, uint16_t skipCleanup)
```

### `attact_usesLDIV_at_`: a menu-item index

`MOV AL,[BP+6]; MOV BX,AX; MOV AL,ES:[BX+0x9082]` — the byte table at `0x9082` is the one
`main` indexes with `GMenuItem` (`1301:07fb`, `1301:0858`) and `draw_usesFillRect2` writes
(`2e25:0116`).  The only caller pushes `[0x8980]` = `GMenuItem`.  So `param_1` -> `menuIndex`.

### `ovc45_usesLDIV_at_`: a party index

`MOV AL,[BP+6]; SHL AX,2; LES BX,ES:[AX+0x217a]; CMP word ptr ES:[BX+0x87],0xa` — `0x217a` is
`GLeaderSheets`, so `param_1` -> `partyIndex`.  Both direct callers forward their own incoming
byte (`77eb:09e9`, `77eb:0a97`).

Parameters: auto 9 -> 4 (0.2%).  Gate: checked 71 failures 0.

## A truncated body hid a parameter: `attact_textArena` (4 -> 3)

The function was 170 bytes long, but the instructions continue past `1ad9` and the next
function starts at `1bfc`.  Re-applying the real body (`SetBody 3f0b:1a2f 3f0b:1bfb`, 461
bytes) exposed `3f0b:1bd6 LES BX,[BP + 0x6]`, i.e. the first argument is a **far** output
pointer, and its segment is the former `param_2`:

```
char * attact_textArena(uint16_t *32 foundIndexOut, char mode, uint8_t partyIndex,
                        uint16_t x, uint16_t y)
```

The body now binds `*foundIndexOut = uVar8;` (before the fix it printed `_foundIndexOut` and
declared the pointer as a near one).  The callers push `SS:&local` for it, matching the far
pointer.

### Body-boundary audit (`scripts/ghidra/BodyEnds.java`)

The truncation was not unique, so every function was checked for a body that does not end in
a return/jump:

```
bodies not ending in return/jump: 141 / 1590
```

Breakdown: 108 are the `DOS21::` pseudo-functions (no instructions by construction), 9 end in
a call to a noreturn routine (`startx`, `_terminate`, `_abort`, `__OverlayHalt`, `exit`,
`__exit`, `_cexit`, `__OvrUntrapJmpsAndStack`, `stExit`), 7 are the `N_*_at_` POP/PUSH
far-call stubs whose body intentionally ends at the `PUSH`, leaving **17 genuine boundary
defects**: `__vprinter_1000_0e74/0e7b/0eb3`, `malloc_JoinFreeBlocks`, `init_textFilename`,
`saveui_configureMessageDelay`, `caseD_0`, `caseD_0_2`, `ovc23_usesAlignUp43`,
`manage_textAllProperty`, `manage_textAllProperty2`, `manage_usesLitoa102`,
`manage_usesCurSfxType3`, `manage_textTotalPopulation`, `bldng_selectBuildingType`,
`ovc27_textTakesHalfDamage3`.

`BadBodies.java` additionally reports **173 non-contiguous bodies**, of which **9 span two
segments** (impossible for an overlay function):

| function | foreign ranges |
|---|---|
| `init_textFilename` | `3d16:1e08-1e11` |
| `saveui_configureMessageDelay` | `49fd:103c-1079` |
| `4528:14b1` | `3f0b:0f59-1081` |
| `ovc22_textPOPULATION` | `4d05:2fb2`, `4d05:3067-3249`, `4d05:32b8-330b` |
| `ovc22_textRingProt` | `4d05:3290-32b7`, `5943:1fd6-1ffd` |
| `55fe:0000` | `4d05:302a-3066` |
| `ovc23_usesAlignUp43` | `5943:2039-205b` |
| `55fe:0cdf` | `4d05:35f6-365a`, `4d05:3667-36b8` |
| `6a8f:2084` | `67e7:0b9a-0be3` |

These are overlay-resolution artifacts (two overlays share a runtime segment), and they are
recorded rather than silently trimmed because the correct range set needs the overlay map.

Parameters: auto 4 -> 3 (0.2%).  Gate: checked 71 failures 0.

## Body map: cross-segment ranges dropped, and the truncation classes (3 -> 2)

### The 9 cross-segment bodies

`scripts/ghidra/BodyCheck.java` (new) prints every range of a function whose body spans more
than one segmented address, the last instruction of each range, and whether the home segment
contains a return.  Before the fix it reported **9** functions; in all 9 `homeHasRet=true`, so
the foreign ranges were dead overlay-resolution artifacts and safe to drop with `SetBody`:

```
init_textFilename, saveui_configureMessageDelay, uiMainMenuLoop, ovc22_textPOPULATION,
ovc22_textRingProt, ovc23_textAdlibNone, ovc23_usesAlignUp43, ovc23_textConstructionAbandoned,
ovc41_textOnlyPlaceSingle
```

After the rebuild `BodyCheck` reports **multi-segment functions: 0**, and `AuditNaming` is
unchanged (parameters 1617, locals 657), so no variable was hidden in those ranges.

### `bldng_selectBuildingType` was genuinely truncated

`ExtendToRet` found a real `RET` at `676c:05ab` with the next function entry at `676c:05ac`
and no interior entry, so the body was extended `676c:03dd-676c:05ab` (was ending at `054b`).
The body now decompiles with named locals (`far_t entries`, `far_t hint`, `uint8_t
buildTypes`, `uint8_t menuEntries`, `uint16_t count`) instead of stopping mid-setup.

### The classes that remain (BodyEnds 141 -> 137)

```
CALL 8, INT 1, CALLF 1      -> noreturn tails (startx, _terminate, _abort, exit, stExit, ...)
PUSH 12                     -> 7 N_*_at_ POP/PUSH far-call stubs + 5 shared-entry helpers
NOINSN 108                  -> DOS21:: pseudo-functions
MOV 3, XCHG 1, JNZ 1, AND 1, SBB 1 -> shared-entry / shared-tail fragments
```

Two of them are *not* truncation and cannot be expressed by Ghidra at all:

**Overlapping entry points (`__vprinter_1000_0e74/0e7b/0eb3`).**  The bytes are

```
1000:0e74  MOV AL,DH
1000:0e76  CALL 0x1000:0e7b      ; a CALL into the middle of the next entry
1000:0e79  MOV AL,DL
1000:0e7b  AAM 0x10              ; entry point, also the CALL target
1000:0e7f  CALL 0x1000:0e84
1000:0e84  ADD AL,0x90           ; entry point, also the CALL target
1000:0e8b  RET
```

Three overlapping entry points share one 24-byte hexadecimal-print helper and its single
`RET`.  Assigning all of them the full range is rejected:

```
OverlappingFunctionException: Unable to create function at 1000:0e7b due to overlap with
range [1000:0e84,1000:0e8b]
```

so they stay at their current one-fragment bodies (no locals, no parameters).

**A shared tail (`malloc_JoinFreeBlocks`).**  `malloc_FreeInnerBlock` is 91 bytes
(`1000:165d-1000:16b7`) and ends exactly at the `RET` at `16b7`, but its last branch is
`1000:16b5 JZ 0x1000:16b8` — a tail jump into `malloc_JoinFreeBlocks`, whose code then falls
through into `malloc_PullFreeBlock` (`1000:16ce-1000:16f6`).  Both entries are real:

```
1000:16ce  refs: 1000:18a8 farmalloc, 1000:1629 malloc_FreeLastBlock   (2 CALL sites)
1000:16b8  refs: 1000:16b5 malloc_FreeInnerBlock                        (tail JZ)
```

Extending `malloc_JoinFreeBlocks` over `malloc_PullFreeBlock` is the same overlap refusal, so
the two-function split is kept.  **Integrity note:** an earlier attempt in this pass deleted
`malloc_PullFreeBlock` on the strength of a fall-through alone; the reference scan then showed
its two `CALL` sites, so the function, its body (`16ce-16f6`) and its `void (void)` prototype
were restored.  Deletions are only made when the reference scan shows no `CALL`.

### `ovc45_compute6.param_1` -> `value` (3 -> 2)

The whole body is `CMP word ptr [BP+0x6],1` followed by a 0/1 return, so the only thing the
binary states about the argument is that it is the word tested against 1.  Named `value`
(typed `uint16_t`), matching the same convention used for
`attact_textAbnormalProgramTermination(uint16_t value, ...)`.

Parameters: auto 3 -> 2 (0.1%).  Gate: checked 71 failures 0.

## Residual body fragments: tested one by one (BodyEnds 137 -> 133)

New instrument `scripts/ghidra/RefsIn.java` lists every reference **to** an address with its
reference type and containing function, which is what separates a real entry from a
jump-table label or an overlay-alias artifact.

### Three entries were false and are gone

| address | references | verdict |
|---|---|---|
| `3f0b:2da0` `caseD_0` | **0 refs** | the bytes are a jump table: `0D 8A 0D 54 0D 30 0D 20 0D ...` = descending word offsets; deleted |
| `4d05:35c9` `caseD_0_2` | 1 **COMPUTED_JUMP** (no CALL) | jump table from its second byte: `4C 16 09 16 8F 15 63 15 FE 14 ...`; deleted |
| `5ded:1433` `ovc27_textCharmed` | 1 CALL from `4d05:3164` (different overlay = alias) | starts mid-push-sequence: `1430 PUSH [BP-8]`, `1433 PUSH [BP-0xa]`, `1436 CALLF`; deleted and the parent extended |

`ovc27_textTakesHalfDamage3` body: `5ded:10ea-5ded:1432` -> `5ded:10ea-5ded:14a5` (956 bytes).
The result is clean - **no `WARNING`, no `in_stack_*`, no `unaff_BP`** - where the split version
had `WARNING: Unknown calling convention` and `in_stack_00000008`.  Its two parameters stay
`agnt_t *32 agnt, uint16_t agntIndex`; the locals stay `msg`, `text2`, `text1`.

### One body was cut into undefined bytes

`manage_textTotalPopulation` ended at `4d05:2fae`, and `2faf` was undefined.  The bytes are
code, continuing in the same `BP` frame:

```
4d05:2faf  9A 39 00 F1 23   CALLF 0x23f1:0x0039
4d05:2fb4  83 C4 10         ADD SP,0x10
```

`ForceDisasm 4d05:2faf-4d05:330c` decoded **298 instructions, 0 holes**, and the tail shows the
real epilogue:

```
4d05:3308  5F        POP DI
4d05:3309  5E        POP SI
4d05:330a  C9        LEAVE
4d05:330b  CB        RETF
4d05:330c  55        PUSH BP      <- manage_applyUnitFilter starts clean
```

Body extended to `4d05:2d79-4d05:330b` (**1427 bytes**).  The recovered tail binds the named
locals `bandLabels` / `bandLabels2` (far-table bases passed to `ovr_blitLabel`) and a typed
set of buffers (`char[120]`, `char[36]`, `undefined2[42]`, `entity_t *32`).

### Side effect of `ForceDisasm` that had to be undone

`DisassembleCommand` follows flow, so it re-created two functions at **cross-overlay** call
targets:

```
5ded:1433  <- CALLF 0x23f1:0x0039 from 4d05:2faf   (re-split ovc27)
5b66:1d94  <- CALL from 4d05:2fc0 (inside the new body)
```

A call from one overlay segment to another cannot execute (only one overlay is resident),
so these are alias resolutions, not calls.  Both were deleted and the `ovc27` body re-set.
Rule applied from here on: **a reference whose source and target lie in different overlay
segments is alias noise, not evidence.**

### The 8 residual fragments, with their evidence

| function | ends at | next entry | evidence | why it stays split |
|---|---|---|---|---|
| `__vprinter_1000_0e74` | `MOV 0e7a` | `0e7b` | `0e76 CALL 0x1000:0e7b` (same segment) | shared-entry helper; body overlap refused |
| `__vprinter_1000_0e7b` | `XCHG 0e83` | `0e84` | `0e7f CALL 0x1000:0e84` (same segment) | same |
| `__vprinter_1000_0eb3` | `JNZ 0ebb` | `0ebc` | 3 CALLs from `__vprinter_func_start` (same segment) | same |
| `malloc_JoinFreeBlocks` | `MOV 16cd` | `16ce` | 2 CALLs (`farmalloc`, `malloc_FreeLastBlock`) | shared tail; overlap refused |
| `manage_textAllProperty` | `MOV 2779` | `277a` | `4d05:2b99 CALL` (same segment) | local subroutine sharing the parent frame |
| `manage_textAllProperty2` | `PUSH 28de` | `28e0` | next entry `28f4` ends in a real `RET` | fragment across a complete function; overlap refused |
| `manage_usesLitoa102` | `PUSH 28f3` | `28f4` | `28f4` itself is complete (`RET`) | same |
| `manage_usesCurSfxType3` | `PUSH 2b3d` | `2b3e` | `2b3e` itself is complete (`RET`) | same |

Each of the 4 `manage_*` fragments sits between two functions that do end in `RET`/`RETF`
(`28f4`, `2b3e`, `2bc3`, `2d78`), so extending any of them to its own `RET` would overlap a
complete neighbour - the same `OverlappingFunctionException` reproduced earlier.

BodyEnds: 137 -> 133.  BadBodies: 173 -> 171.  Multi-segment: 0.

## Runtime trace of INT 66h: `midPlaySequence`'s argument is a sequence index (2 -> 1)

The harness (`emulator/dosbox-x-mod.exe` with its socket instrumentation) was used as asked.
The IVT entry for `INT 66h` reads `5DBC:1B7A` (linear `0x5F73A`), and the driver dispatches on
`AX` through a jump table:

```
5DBC:1B7A  CMP AX,0x0700 / JB ...
5DBC:1B82  CMP AX,0x0715 / JA ...
5DBC:1B8A  SUB AX,0x0700
5DBC:1B8B  SHL AX,1
5DBC:1B8D  ADD AX,0x1B3A        ; table base
5DBC:1B91  MOV BX,CS:[BX]
5DBC:1B94  JMP word ptr CS:[0x1B6A]
```

Live table dump (22 entries) gives `AX=0702 -> CS:1C38`:

```
5DBC:1C38  PUSH DS / PUSH CS / POP DS
5DBC:1C3B  PUSH BX              ; <- the caller's parameter
5DBC:1C3C  CALL 0x150D
5DBC:1C42  POP DS / IRET
```

`0x150D` builds an eight-word call, and in cdecl order the pushed `BX` is **argument 3**
(`push ax=0, dx=0, [0x2E7F], [0x2E7D], [bp+4]=BX, [0x2E71], [0x2E6F], [0x2E77]`).  The chain
then resolves by runtime values, not by assumption:

```
0x0232  near->far thunk -> 0x0A4C: MOV AX,0x97 / JMP 0x0470
0x0470  MOV BX,SS:[BX+4]        ; argument 0 = driver slot (live value 0)
0x0470  CALL 0x0438            ; per-driver operation-table lookup
0x0438  table at CS:0x3AA, slot*4 -> 610F:002D
610F:002D  ... code=0x0097 -> handler 610F:3206
```

The handler for operation `0x97` pushes its own arguments 3, 2, 1 into `610F:244D`, and the
parser there consumes the value as `cx`:

```
610F:2456  MOV CX,[BP+0xa]      ; = the INT BX value
610F:2459  INC CX               ; 1-based sequence counter
610F:245D  CMP word ptr [SI],0x4143   ; 'CA'   \  IFF chunk walk
610F:2463  CMP word ptr [SI+2],0x2054 ; 'T '
610F:247D  CMP word ptr [SI+8],0x4D58 ; 'XM'  } FORM/XMID
610F:2484  CMP word ptr [SI+0xa],0x4449 ; 'ID'
610F:24F8  CMP CX,1 / JE success
610F:2562  LOOP 0x2510          ; skip one more CAT sub-chunk
```

So `BX+1` is a **loop counter over the file's XMID sequences**: `BX=0` takes the first, `BX=1`
the second, and so on.  The game's only caller passes `0`.  Renamed and typed:

```
void midPlaySequence(uint16_t sequence)
```

Parameters: auto 2 -> 1 (0.1%).

## `__CHECKOVERLAY`: the hook is an empty stub and the routine is never called

The emulator trace also settles the last parameter, negatively and with evidence.  The static
overlay header gives the indirection:

```
1403:0002   5D 22        ; the word restored into DS
1403:08d4   MOV DS,CS:[2]  -> DS = 0x225D
1403:08d9   CALLF [0x86]  -> far pointer at 225D:0086
```

and `225D` is the Borland overlay runtime group:

```
225d:0000  __OVRGROUP (label)
225d:0086  __OVRHOOK__ (label)
```

Reads under the harness segment map (`225D-0x7DD`), linear `0x1A886`, give the live pointer:

```
0x1A886: 37 08 23 08     -> 0823:0837  (linear 0x08A67)
0x08A67: CB              -> RETF
```

The hook points at a one-byte `RETF` stub, so the call consumes nothing.  Consistently,
`RefsIn 1403:0890` reports **refs=0** (the routine is dead code in the overlay), and a
breakpoint attempt at its resident address failed to ever fire:

```
bp CAF0 -> OK bp 0000CAF0
run     -> RESUMED
14 key events over ~12 s, ping polled each time -> halted=0 throughout
```

(`0xCAF0` was confirmed to be the routine before arming: `55 8B EC 1E 2E 8E 1E 02 00 8E 46 08`
= `push bp; mov bp,sp; push ds; mov ds,cs:[2]; mov es,[bp+8]`.)

So the parameter has no reader, no caller and no callee behaviour to derive a name from.
Parameters: auto 1 (0.1%).  Gate: checked 71 failures 0.

## Three false entries inside misaligned code (BodyEnds 133 -> 130)

`manage_usesLitoa102` (`4d05:28e0`), `manage_usesLitoa103` (`28f4`) and
`manage_usesCurSfxType32` (`2b3e`) were entries **inside instructions**.  The bytes show why:

```
4d05:28d8  68 E0 00      PUSH 0x00e0
4d05:28db  68 8C 00      PUSH 0x008c
4d05:28de  1E            PUSH DS
4d05:28df  68 CD 52      PUSH 0x52cd      <- Ghidra had left this undefined
4d05:28e2  0E            PUSH CS
4d05:28e3  E8 33 DC      CALL 0x4000:d569
```

`0x28e0` is the middle of `PUSH 0x52cd`, which is why it decoded as the nonsense `INT 52h`.
`ForceDisasm 4d05:28df-4d05:2bc4` decoded **305 instructions, 0 holes**, and none of the three
entries had a same-segment `CALL` (their only references came from other overlay segments,
i.e. alias noise).  They were deleted and the enclosing bodies extended to their real
terminators:

```
4d05:277a  manage_textAllProperty2   911 bytes   277a-2b08  (ends JMP)
4d05:2b09  manage_usesCurSfxType3   187 bytes   2b09-2bc3  (ends RETF)
```

### `manage_textAllProperty` is a real entry with a shared tail

`4d05:26f6` stays flagged, but it is not false: `4d05:26f5` is a `RETF`, and the entry begins
with a clean prologue (`PUSH BP; MOV BP,SP; SUB SP,0x156; PUSH SI; PUSH DI`).  Its exit path
falls through into `277a`, which is itself a real entry (called from `2b99`), so the two share
a tail - the overlap case Ghidra cannot express.

BodyEnds: 133 -> 130.  Functions: 1127 -> 1124.  No spurious function was created by the
force-disassembly (verified by diffing the function list).

## `__CHECKOVERLAY` removed: unreachable Borland overlay helper (auto params 1 -> 0)

The routine is Borland's overlay-runtime check: it validates a header at `ES = [BP+8]`
(`CMP CX,ES:[0]`, `CMP word ES:[0x10],0`, `CMP byte ES:[0x20],0xCD`), calls
`__OvrFixupTrap` (`1403:05a1`, a named Borland routine), then transfers to `__OVRHOOK__`:

```
1403:0894  MOV DS,CS:[2]
1403:0899  MOV ES,[BP+0x8]      ; header segment
1403:08be  CALL 0x1000:45d1     ; __OvrFixupTrap
1403:08c3  MOV BX,[BP+0x6]
1403:08d9  CALLF [0x86]         ; __OVRHOOK__
```

Every fact needed to decide whether it is live was collected:

| test | result |
|---|---|
| static references (`RefsIn 1403:0890`) | **0** |
| `__OVRHOOK__` target | `0823:0837`, and the byte there is `CB` (`RETF`) - an uninstalled hook |
| live breakpoint at `0xCAF0` (its resident address) | never fired over 30 s of play (45 key events: space/enter/arrows/esc) |

So the routine cannot be reached, and its only consumer is an empty stub - no argument
semantics exist in this binary.  The function was removed from the model (the code bytes stay in
the overlay), which leaves **no auto-named parameter anywhere**:

```
parameters  1615  auto 0  (0.0%)
```

## Body coverage: 9 bodies coalesced, 146 gaps are genuinely undefined

`scripts/ghidra/CoalesceBodies.java` merges a body's ranges when every gap is small and every
gap byte is **already part of a decoded instruction**:

```
coalesced=9  skipped=162  undecodedGaps=146
```

So 9 functions had ranges split by instruction bytes that were excluded from the body; the
remaining 146 have gap bytes the listing never decoded.  Force-disassembling those would be a
guess (a 3-byte gap such as `83 C4 02` is a valid `ADD SP,2`, but `EB 48` in the same position
could equally be table data), so they were left untouched.

`BadBodies`: 171 -> **162** non-contiguous bodies.  `BodyEnds` stays 130/1583, of which 108 are
`DOS21::` pseudo-functions, 9 noreturn tails, 10 `PUSH` stubs/shared-entry helpers and the
remaining handful are the overlap cases already documented.

## Class-record loader: `agnt->gdata` is never stored directly

`agnt->gdata` lives at `agnt_t+0x1d`.  A raw-byte scan for every base-register encoding of a
store/load at that offset gives:

```
26 89 47 1D   ES:[BX+1d] <- AX      0 hits
26 C7 47 1D   ES:[BX+1d] <- imm     0 hits
26 88 47 1D   ES:[BX+1d] <- AL      0 hits
89 47 1D      [BX+1d] <- AX         0 hits
47 1D / 44 1D / 45 1D / 46 1D / 40 1D / 41 1D  (BX/SI/DI/BP/BX+SI/BX+DI)
              the only real hit is 3b1d:0910
```

and that hit is a **reader**:

```
3b1d:0910  26 C4 5F 1D   LES BX,ES:[BX + 0x1d]      ; BX = agnt->gdata
3b1d:0914  26 8A 47 1D   MOV AL,byte ptr ES:[BX+0x1d] ; AL = gdata->+0x1d
3b1d:0918  98            CBW
3b1d:0919  D1 F8         SAR AX,1                   ; halved, then compared
```

The `push 0x95` sites turned out to be `printf` calls: `0x1000:2747` is `printf`, and the
pushed words are the format far pointer and `GGameState` (`DS:0x898e`), not an allocation size.

Combined with the live `REP MOVSW` hit, the picture is that agent records (including the `gdata`
pointer) are **copied from a template**; there is no per-agent store.  That means `agntG_t`
fields are never written by name either, which is why `+0x3a`, `+0x46` and `+0x94` have no
writer to observe and no reader in the listing.

## Coverage: 340 gaps validated and filled, 148 bodies coalesced (BadBodies 162 -> 14)

The 344 intra-function gaps were dumped with their bytes (`scripts/ghidra/DumpGaps.java`) and
each was decoded with an independent disassembler before anything was committed:

```
gaps total: 344
validated: 340   rejected: {'ascii/zero': 3, 'inexact': 0, 'invalid': 1}
```

The acceptance test was **exact consumption**: the decoded instruction stream had to end
precisely on the gap's last byte, with no invalid opcode, and the bytes had to be less than 75%
printable/zero (so table data and strings are rejected).  `inexact: 0` means every gap that was
not data-like decoded as a whole number of instructions that filled it exactly.

`scripts/ghidra/FillGaps.java` then decoded those ranges with `followFlow=false` (no function
side effects), and `CoalesceBodies.java` re-applied the body ranges, skipping any new range that
would overlap another function:

```
filled=340 failed=0
coalesced=148 skipped=14 undecodedGaps=0
BadBodies: 162 -> 14
```

### Regression caught: 35 `DAT_0000_*` globals

The first audit after the fill reported `globals 2469 auto 35`.  All 35 were `DAT_0000_xxxx`
labels in segment `0000` - the interrupt-vector/BIOS area - created because some newly decoded
bytes held far pointers into that segment.  Removing the symbols alone did not help: Ghidra
regenerated them from the references (`symsRemoved=0`).  `ClearRefsTo.java` deleted the 147
references instead, which cleared the labels for good:

```
refsRemoved=147 symsRemoved=0
globals 2434 auto 0 (0.0%)
```

## Workflow defect: `git checkout -- gpr` was reverting the project index

`gpr/st.gpr` and 15 files under `gpr/st.rep/idata/` are tracked in git, while the rest of the
Ghidra repository is not.  Running `git checkout -- gpr` after each doc commit therefore restored
the old `st.gpr` index while the `.rep` kept newer data, and previously deleted functions
(`caseD_0`, `caseD_0_2`, `ovc27_textCharmed`, `manage_usesLitoa102/103`,
`manage_usesCurSfxType32`) reappeared in `ListFuncs` (1584 -> 1590 rows).  The revert is no
longer performed; the project working tree is left in place between batches.
