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
