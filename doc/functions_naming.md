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
