# Far-segment bases: the biggest correctness gap in the rebuild

## Symptom

The exported C addresses far data with **bare offsets**, e.g.

```c
*(byte *)(rec * 0x69 + ofs + 0x8fa)          /* AgntArrayA */
*(uint *)(iVar4 * 0x34 + 0x2b)               /* Agnts[i].flags */
```

Those offsets are only meaningful inside the original's data segment.  In the
rebuild they compile to **DS-relative** loads, i.e. they read DGROUP at that
offset instead of the agent data.  Nothing in the current gates catches it:
`compare_state` and `compare_runtime` only look at DGROUP, and the agent data
lives in its own far segment.

## Evidence

Original symbol table (`audit/symbols.tsv`):

```
1726:0000  Agnts
1726:04e0  AgntArrayB
1726:08fa  AgntArrayA
```

Original disassembly of `agnt_usesAgntCount5` (`3b1d:16cd`):

```
3b1d:16e6  MOV DX,0x1726                  ; the Agnts segment
3b1d:16ed  MOV AL,byte ptr ES:[BX + SI + 0x8fa]
```

so the code really is `ES:[row*0x69+col+0x8fa]` with `ES = 0x1726`.  The export
kept the offset and dropped the segment.

Rebuild map before the fix:

```
099E:0000  (unnamed)        0x1a6 bytes
099E:0000  columnScreenY    0x1a6 bytes
099E:01a6  AudioHandles     0x230 bytes
099E:03d6  Agnts            <- should be offset 0
099E:08b6  AgntArrayB
099E:0cd0  AgntArrayA
```

## Fixed in this pass

1. **Agent grids → named 2-D arrays** (101 sites).  `AgntArrayA`/`AgntArrayB`
   are now `uint8_t far far [10][0x69]` (same bytes) and
   `row*0x69+col+0x8fa` / `+0x4e0` became `AgntArrayA[row][col]` /
   `AgntArrayB[row][col]`; the five `_fmemset(MK_FP(0x1726, ...))` rows became
   `&AgntArrayX[row + k][colStart]`.

2. **Agnts back at offset 0.**  BCC gives each module its own far data segment,
   and `columnScreenY` + `AudioHandles` preceded `Agnts`, pushing it to
   `099E:03d6`.  Moving those two into `st_globals9.c` (they are only referenced
   by name) restores the original relative layout exactly:

   ```
   _AGNTS       099E:0000
   _AGNTARRAYB  099E:04e0
   _AGNTARRAYA  099E:08fa
   ```

3. **Stale segment `0x1726` → `SEG_OF(Agnts)`** (60 literals in six modules
   that built far pointers with the original's segment number).

## What is still wrong

### `i * 0x34 + off` (652 sites, the `(D)` grep class)

These are `Agnts[i].field` and still compile to DS-relative loads.  Field table
from `struct agnt_t`:

| off | field | off | field |
|---|---|---|---|
| 0x00 | x | 0x1b | owner |
| 0x02 | y | 0x1d | gdata |
| 0x04 | targetX | 0x21 | strength |
| 0x06 | targetY | 0x22 | strengthMax |
| 0x08 | destX | 0x23 | timer |
| 0x0a | destY | 0x24 | combatState |
| 0x0c | target | 0x25 | moveState |
| 0x0d | gindex | 0x26 | screenX |
| 0x0e | animFrame | 0x28 | screenY |
| 0x0f | level | 0x2a | teamCode |
| 0x10 | health | 0x2b | flags |
| 0x11 | animVariant | 0x2d | visited |
| 0x12 | frameIndex | 0x2e | variant |
| 0x13 | frames | 0x2f | faction |
| 0x17 | entity | 0x30 | state |
| | | 0x32 | flags32 |

Odd offsets are byte halves (`+4`/`+5` = low/high of `targetX`, `+0x33` = high
byte of `flags32`, `+0x1a` = the party byte that shares the top of `entity`).
Rewriting each site as `Agnts[i].field` (or a byte view of it) fixes both the
segment and the `(D)` grep.  This is mechanical but must be done per site
because the pointee type decides whether the access is a word or a byte.

### `MK_FP(0x2410, ...)` (107 sites)

`0x2410` is the original **DGROUP** segment.  These build far pointers to
DGROUP variables with the original's offsets, e.g.

```c
MK_FP(0x2410, row * 0x69 + colStart + 0x8fa)
```

Two separate problems: the segment (ours is `15a4`) and, where the original
DGROUP offset differs from ours, the offset too.  `diff_dgroup` reports
976/1,868 symbols matched, so some offsets are right and some are not.

### Far pointers stored in data

`st_globals3.c` / `st_globals4.c` initialisers embed the original segments:

```c
{ (void far *)(0x24100000UL + 0x1d11UL), ... }
```

Those bytes must stay (the data image is compared byte-exact), but at run time
they point at segment `0x2410`, which does not exist in the rebuild.  Matching
the original's *segment numbers* is not achievable through the linker, so this
needs a start-up relocation pass (patch every stored far pointer by the delta
between the original and rebuilt segments) if it is to run correctly.

## Gate impact

None of this is measured by `scripts/grep_checks.py` except the `(D)`/`(C)`
rows, so the totals did not move for the fixes above:

```
grep_checks TOTAL 58,424 (unchanged)
compare_state 1,630 identical / 0 different / 0 missing
diff_dgroup 976/1,868 matched
compare_runtime 1,523 identical / 14 different
```

A gate that *would* measure it: compare each far segment's contents against the
original image at the same intra-segment offsets.  The agent segment now matches
structurally (`0000`, `04e0`, `08fa`), so that check is feasible for this
segment.

## Status after the field-access passes

Done (verified by build + map + gates):

| object | stride | sites | form |
|---|---|---|---|
| `AgntArrayA`/`AgntArrayB` grids | 1 | 101 | `AgntArrayA[row][col]` (2-D arrays) |
| `Agnts` | 0x34 | 854 | `Agnts[i].field`, `&Agnts[i].field`, `AGNT_FIELD`/`AGNT_WORD` |
| `BuildingTypes` | 0x27 | 194 | `BuildingTypes[i].field`, `BLD_FIELD`/`BLD_WORD` |
| `Entities` (entity records) | 0x37 | 218 | `((entity_t *)Entities)[i].base.field`, `.tick`, `.dir` |
| `GRecords` | 0x12 | 113 | `GRecords[i].field`, `GREC_FIELD`/`GREC_WORD` |
| stale `0x1726` | - | 60 | `SEG_OF(Agnts)` |
| stale `0x21f2` | - | 12 | `_DS` (GRecords lives in DGROUP) |

`Agnts` is back at offset 0 of its far segment (`099E:0000`, with
`AgntArrayB` at `04e0` and `AgntArrayA` at `08fa`), matching the original
`1726:0000 / 04e0 / 08fa` exactly.

Three `grec_t` field names had no reader and are now evidenced from
`draw_usesPlay_sfx` / `ovc23_tickRecordsAt`:

```
reserved06 -> frameCount   frame + 1 < frameCount bounds the frame counter
done       -> state        0/1/2; 1 when the countdown ends, 2 after the last frame
reserved11 -> frame        incrementing animation frame
```

The offset folding used by the passes: a negative offset is the previous record
and an offset >= stride the next one, so `-5` is `Agnts[idx - 1].faction` and
`-0x10` is `Agnts[idx - 1].combatState` - the "grid byte is agentIndex + 1"
convention.

`(C) idx*stride` is now **0**.  `(D) far const` is 83, and the remainder is
mostly *not* fixable by typing:

* `iVar12 * 0x30 + 0x32` (36) and `(long)iVar12 * 0x30` - pixel/offset
  arithmetic for the RLE cut calls, not a record stride;
* `X * 0x50` (4) - an address-range comparison;
* `y + (int)pfVar * 0x1e + off` (11, ovc18_leaderview.c) - a 0x1e-stride record
  whose struct is not identified yet; the base is a local pointer, so it needs
  the type before it can be named;
* `gindex * 0x95 + 0x1f` and `bVar * 0x95 + 0x26d6` - `AgntGs` (stride 0x95).
  The literals appear both with and without the original base `0x26d6`, so the
  two spellings disagree about the base and each site needs its disassembly;
* small remainders: `iStack_4 * 0x17 + 0x1b`, `(uint)bVar1 * 0x27 & 0xff00`.

Note the regex `(D)` also matches plain arithmetic (`x * 0x30 / 0x30`), so this
row cannot reach zero by field typing alone.

## AgntGs resolved: the "unknown base" was the array itself

`doc` previously listed `gindex * 0x95 + 0x1f` as ambiguous because the same
expression appeared both with and without the original base `0x26d6`.  The
disassembly of `ovc13_drawPanelEntitiesAll` (`3d16:0255`) settles it:

```
3d16:02b3  MOV DX,0x95
3d16:02b6  IMUL DX
3d16:02b8  MOV DX,0x195d
3d16:02bf  MOV AL,byte ptr ES:[BX + 0x26d6]
```

`ES = 195d`, offset `0x26d6` is `AgntGs`, and `ai` is offset 0 - so the access is
`AgntGs[gindex].ai`.  The export's `+ 0x1f` is an artefact of resolving the same
offset against **DGROUP**, where `GMenuStrings` sits at `2410:26b7` and
`26b7 + 0x1f = 26d6`; that is why every one of these sites was written as
`(int)(char **)GMenuStrings + ... * 0x95 + 0x1f`.  All 56 sites now read
`AgntGs[idx].ai`.

The neighbouring `+0x2716` access in `ovc18_spawnClassAgent` (`48ac:027f`) is
`AgntGs[i].flags3` (`0x2716 - 0x26d6 = 0x40`), which matches the struct field
that `TEST word ptr ES:[BX+0x40],0x100` masks.

## `y + (int)pfVar * 0x1e + off` is blocked, not unidentified

Eleven sites in `ovc18_leaderview.c` index a 0x1e-stride record through a local
`y`.  Two pieces of evidence say the export there is not trustworthy yet:

1. `Ghidra` calls `48ac:0251` **`ovc18_spawnClassAgent`** (111 instructions),
   while the C marker at that address is `ovc18_showLeaderView` - the name and
   the body disagree.
2. The immediately adjacent access in the same block is
   `*(byte *)(y + (int)pfVar8 * uVar10 + 10)` with `uVar10 = 0x195d`, i.e. a
   **segment value used as a multiplier**, which cannot be real arithmetic.

So the 0x1e arithmetic comes from a mis-modelled body; typing it would invent a
struct.  It needs the overlay half of the function (the C jumps to `4000:8xxx`)
re-exported before anything can be named.

## Param names in ovc15_textView are blocked on the call site

`ovc15_textView` has nine `param_N` arguments, but its only call site is

```c
cVar4 = (uint16_t)( ovr_ovc15_textView()   /* hand fix: args lost by the decompiler */);
```

so neither arity nor meaning can be recovered from the C.  Naming them would be
guesswork; the call's arguments have to be recovered from the disassembly first.

## The leader-sheet table: the same missing base, one struct bigger

`doc` listed `(char_sheet_t *)(idx << 2)` and `*(uint32_t *)(idx << 2)` as
unexplained.  They are the **GLeaderSheets** table, and the disassembly of
`upd_usesAlignUp4` (`5087:1d7d`) shows both the base and the field layout:

```
5087:210d  MOV AX,word ptr ES:[BX + 0x54]   ; income
5087:2111  CWD
5087:2115  SHL BX,0x2                       ; idx * 4
5087:2118  MOV CX,0x217a                    ; GLeaderSheets segment
5087:211d  LES BX,ES:[BX + 0x0]             ; GLeaderSheets[idx], a far pointer
5087:2122  MOV CX,word ptr ES:[BX + 0x58]   ; gold high
5087:2126  MOV BX,word ptr ES:[BX + 0x56]   ; gold low
5087:212a  ADD BX,AX
5087:212c  ADC CX,DX                        ; gold += income
```

`audit/symbols.tsv` has `GLeaderSheets` at **217a:0000**, so the export's bare
`idx << 2` was correct inside that segment; the rebuild has the array in DGROUP
at `15A7:077C`, so every such access read DGROUP instead - the same defect class
as `Agnts`.

Fixed in this pass:

* 193 `(char_sheet_t *)((idx << 2))` casts -> `GLeaderSheets[idx]` (which also
  removes the `idx<<2` arithmetic on a 0xae-byte struct);
* 102 `*(uint32_t *)(idx << 2)` loads in `upd_usesAlignUp4` -> `GLeaderSheets[idx]`
  (there `idx` is the leader loop variable, and the neighbouring `+0x54/0x56/0x58`
  uses confirm the table).

### char_sheet_t layout confirmed at +0x54..+0x62

With `-a-` (byte alignment) the struct offsets are consecutive, and the
disassembly above matches:

| offset | field | evidence |
|---|---|---|
| 0x3f | `faction` | `cVar10 = *(char *)(GLeaderSheets[idx] + 0x3f)` |
| 0x54 | `income` (word) | `MOV AX,ES:[BX+0x54]` then added into gold |
| 0x56 | `gold` low word | `MOV BX,ES:[BX+0x56]` |
| 0x58 | `gold` high word | `MOV CX,ES:[BX+0x58]` |
| 0x60 | `foodStored` low word | added/subtracted as a pair with 0x62 |
| 0x62 | `foodStored` high word | `*(int *)(iVar21 + 0x62)` sign word |
| 0x64/0x6a/0x70/0x76 | `dirBudgetIn`/`dirBudget`/`ringBudgetIn`/`ringBudget` | the 32-bit pairs written at 0x6c/0x6e, 0x78/0x7a |

So the earlier note calling these a "unit-record layout" was wrong: they belong
to the 0xae-byte leader sheet reached through `GLeaderSheets[idx]`, not to
`unit_t` (which is 9 bytes).

### Why `uVar23` and `iVar17` are still not split

Now that the layout is known the split is *possible*, but the two slots are
threaded through unrelated roles, and the census shows no cheap split:

`uVar23` 122 occurrences on 101 lines:

```
  6  = *accLo            (the old low word of a 32-bit field)
  4  loop increment of the second unit loop
  3+3 first/second unit loop headers
  4  *(uint32_t *)(iVar21 << 2)
  4  (int)&peVar20[...].base.entity
  3  >= 0 / = 0                (a value, not an index)
  3  (uint)(units + uVar23)->bldType
  ...  ~10 more shapes
```

`iVar17` 117 occurrences on 104 lines:

```
 21  = (int)*(uint32_t *)(idx << 2)     the leader-sheet offset
  8  = *(int *)(iVar21 + 0x62)          a field value
  6  accLo = (uint *)(iVar17 + 0x56)    gold low
  6  accHi = (int  *)(iVar17 + 0x58)    gold high
  3  = 0                                a flag
  ...  plus bldType * 0x27 and further field addresses
```

Splitting them means roughly ten new locals and a per-occurrence rewrite.
What was done instead is a constrained split with two mechanical safety checks
per block:

  1. the block contains exactly one assignment to the variable (the
     header/init), so the value is the loop counter throughout;
  2. the first use after the block is itself an assignment, so no stale value
     is read across the boundary.

Accepted: the three 0xf8..GUnitCount loops (48 occurrences, unitIdx) and the
0..GLeaderCount loop at 3529 (12, leaderIdxB).
Rejected by check 1 and left alone: iVar17 3336..3362, uVar23 3364..3384,
uVar23 3446..3462, uVar23 3789..3881 (each assigns the variable again inside
the block, so the counter and the other role share the storage).

One consequence worth recording: adding a local grows the frame, which turns
some [BP+disp8] accesses into disp16 encodings, so the linked EXE is *not* byte
identical after a pure rename.  Byte comparison is therefore not a usable
acceptance test here; the gates plus the two checks above are.

## The start-up relocation pass: measured, built, and not yet safe to enable

Per the note above, far pointers stored in data keep the original segment in the
image and need fixing at run time.  This section records what the pass has to do
and the two traps found while implementing it.

### Why the pointers are stale in our build but not in the original

The original EXE carries **1832** DOS relocations; our rebuild carries **846**
(`link_standalone.py` only adds relocations for far *code* transfers, and TLINK
emits none for an integer initialiser).  The loader uses those entries to add the
load segment to each stored far pointer, which is why the original's file value
`GSPEmpty = { 0x272B, 0x2410 }` becomes `0x272B:0x1C33` at run time.

Scanning `audit/dgroup_2410.bin` (the original DGROUP image) for 32-bit words
whose high half is a known original segment gives:

```
segment 0000  3337   relocatable, the loader already patches these
segment 2410   377   hard-coded DGROUP self-pointers (the stale ones)
segment 1000    14   code-segment pointers (callbacks)
segment 1403     2
```

So the runtime work is bounded by the **377** non-zero ones, not by all 3,730.

### The table that can be built today

`tmp/build_reloc_table.py` resolves each candidate through
`audit/symbols.tsv` (which object the stored offset names) and `REBUILT.MAP`
(where that object is now), keeping only entries that pass three filters:

* the stored offset is exactly a symbol start (so it names an object, not the
  middle of one) - rejects 42;
* the target object exists in the rebuilt DGROUP - rejects 69;
* the *location* sits inside a symbol whose declaration mentions `far`, `*` or
  `ptr` - rejects 30.

That yields **236** entries, all of the form
`dgroup[0x0ac2] = 0x0b40; dgroup[0x0ac4] = _DS` (string pointers to
`s_Fighter`, `s_mage`, ... in the sample checked against the linked image).

### Trap 1: the table itself moves DGROUP

Emitting the table as `static const ... dgptr_fixups[]` puts 944 bytes of
initialised data into DGROUP and shifts every offset the table describes
(observed: DGROUP `15a7 -> 15ad`, after which all 236 entries were pointing at
the wrong words and the program failed to reach `main`).  The generator now
emits straight-line code instead, which lives in `_TEXT`, and it takes the
DGROUP segment from `REBUILT.MAP` rather than a constant.

### Trap 2: the enabled pass still breaks startup

With the code-only version, DGROUP stays at `15ad`, 236 entries are emitted and
the build is clean, but:

```
(tmp/dump_dgroup_stdout.py)
  rebuilt dump: none          <- program no longer reaches main
```

Disabling only the call restores a full 65,535-byte dump, so at least one of the
236 writes corrupts DGROUP.  The candidates most likely to be wrong are entries
whose stored offset coincides with a symbol start but which are not actually
pointers (the declaration filter is textual).  The next attempt must validate
per entry: log each write, or enable the entries in small batches and re-run the
dump each time.

### Tooling note

`scripts/compare_runtime.py` only *compares* the stored dumps
`tmp/dgrun2_{orig,ours}/DGR.BIN`; it does not produce them.  Regenerate with
`python tmp/dump_dgroup_stdout.py` (about 40 s per image).  The dumps had been
eight hours stale during this investigation, which briefly made the pass look
successful.

State: the pass is **not** in the tree.  `doc` and `tmp/build_reloc_table.py`
carry the analysis, the filters and the two traps.
