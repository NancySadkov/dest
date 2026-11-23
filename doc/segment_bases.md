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
