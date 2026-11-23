# Segment `195D` — 706 hard-coded segment literals that point at the original layout

## What `195D` is

`doc/fbov_segments.csv` lists it explicitly:

```
index  seg    static_seg  minoff  maxoff  flags  class
12     095D   195D        0000    5970    0      DATA
```

`audit/symbols.tsv` has **459 symbols** under `195D:` — it is the game's data
segment:

```
195d:0000  ProjectileAnms
195d:0000  EntityTypeSeg
195d:010e  BuildingTypes
195d:0133  BuildingTypes[0].unitType
...
```

## How it is used in the recovered C

The literal appears **706 times** across the game modules:

```
ovc15_sprite.c 28   ovc18_leaderview.c 1   ovc19_save.c 1    ovc20_stash.c 17
ovc21_manage.c 1    ovc22_classes.c 6      ovc23_bldrec.c 1  ovc24_entities.c 8
ovc25_intel.c 1     ovc35_bldng.c 1        ovc41_main.c 6    ovc44_strong_dat.c 195
ovc45_unitinfo.c 202 ovc46_assets.c 179    ovc47_constrct.c 6 ovc48_assets2.c 51
ovc49_agents.c 2
```

always as a segment half, e.g.

```c
uVar7 = 0x195d;
BldGfxRuin[0x4f] = far_from_u32((uint32_t)(func_0x0007ffe0(uVar14)));
...
BldGfxNormal[i].seg = uVar7;
```

## Why it is wrong in our rebuild

`195D` is the segment value of the **original** image.  In the rebuilt image the
same objects live elsewhere:

```c
extern anm_t far far EntityTypeSeg[9];      /* st_globals2.c */
extern bldtp_t far far BuildingTypes[248];  /* st_globals3.c */
```

`far far` means each array sits in its own FAR_DATA segment, and the linker
assigns those paragraphs at link time (the map lists `GLOB3_DATA`, `GLOB4_DATA`,
...).  So a hard-coded `0x195d` addresses whatever happens to be at that
paragraph in *our* image, not the tables.

This is the same class of bug that `Entities`, `GLeaderSheets` and `GRecords`
had — except those were DGROUP-relative and could be fixed by declaring the
object correctly, while these are literals inside code.

## What the fix has to be

Each site needs the segment of the object it actually points at, which differs by
call site (sometimes `BuildingTypes`, sometimes `EntityTypeSeg`).  A blanket
`0x195d → startxDseg` would be wrong because these arrays are not in DGROUP.

The tractable approach, in order:

1. For the two hot files (`ovc44_strong_dat.c` 195, `ovc45_unitinfo.c` 202,
   `ovc46_assets.c` 179, `ovc48_assets2.c` 51) identify the table each store
   targets and replace the literal with `FP_SEG(&Table[0])`.
2. Then re-check `diff_dgroup` and the runtime comparison, since these sites also
   feed the 14 differing runtime symbols.

Recorded here so the next session does not mistake `0x195d` for a magic constant.

## Status of the CRT

Per the project owner: the CRT and the VROOMM/overlay runtime are supplied by
Turbo C and `OVERLAY.LIB`.  `scripts/model/unresolved.tsv` now marks the
remaining entries accordingly (CRT, floating-point runtime, overlay trampoline),
so no recovery time goes into them.

## Correction: the literal is Ghidra constant-folding, not original code

Searching the original image for the immediate:

```
mov ax,195Dh   0 occurrences
mov ax,095Dh   0 occurrences
push 195Dh     0 occurrences
```

**The original code never loads 0x195D.**  Ghidra substituted the known segment
of the *data* (segment `195D` holds `BldGfxRuin` at `4230`, `BldGfxNormal`,
`BuildingTypes`, `EntityTypeSeg`, `ProjectileAnms`) wherever it could prove the
pointer's segment, and the recovered C therefore shows a constant where the
original computes or loads the value at run time.

That changes the fix:

* it is **not** a "stale copy of the original literal" that can be swapped for a
  symbol — there is no literal to swap;
* the correct code is whatever the original executed at that site, which is
  either `mov ax,es` (the current data segment), the return of
  `ovr_stshStoreFile`/`ovr_stshAlloc`, or a value read from a variable.

Consequences for the plan:

1. Each of the 706 sites needs its own disassembly check.  A first attempt to
   locate the store for `BldGfxNormal[0xc].seg` by its absolute displacement
   (`26 A3 62 42` / `26 89 06 62 42`) found nothing, so the original store goes
   through a computed register — the addressing has to be followed from the
   surrounding code rather than pattern-matched.
2. A blanket `0x195d -> startxDseg` replacement would be wrong twice over: the
   tables are not in DGROUP, and some sites do not store a constant at all.

Priority should therefore go to the sites that are provably constant (a run of
`BldGfxNormal[i].seg = <same var>` after `uVar = 0x195d`), and the rest left until
their disassembly is read.

## Resolved: the store is `stshStoreFile`'s returned segment; 0x195d is dead code

Dumping `init_assets` (6FFE:02F7) from the Ghidra project and reading the store to
`BldGfxNormal[0xc]` (`195d:4DD0`, `.seg` at `4DD2`) gives the whole sequence:

```
6ffe:09d5  PUSH DX / PUSH AX
6ffe:09d7  CALLF ovr_stshStoreFile
6ffe:09dc  ADD SP,4
6ffe:09df  PUSH AX                 ; save the returned OFFSET
6ffe:09e0  MOV AX,SI
6ffe:09e2  MOV BX,0xc
6ffe:09e5  PUSH DX                 ; save the returned SEGMENT
6ffe:09e6  IMUL BX                 ; BX = index * 12
6ffe:09e8  MOV DX,0x195d           ; <-- dead
6ffe:09eb  MOV BX,AX
6ffe:09ed  MOV DX,ES               ; <-- dead as well
6ffe:09ef  POP AX                 ; AX = returned SEGMENT
6ffe:09f0  MOV ES:[BX+0x4dd2],AX   ; .seg = returned segment
6ffe:09f5  POP AX                 ; AX = returned OFFSET
6ffe:09f6  MOV ES:[BX+0x4dd0],AX   ; .ofs = returned offset
```

So:

* `0x195d` is a **dead link-time constant** - it is loaded and then overwritten
  before any use, which is why it never appears as a store operand;
* the value actually stored into `.seg` is the **segment `stshStoreFile` returns in
  DX**;
* our tree lost that because the prototypes dropped DX:

```c
cte_t * __cdecl16far stshStoreFile(uint8_t *data,uint16_t arg2);   /* near */
undefined ovr_stshStoreFile();
```

## Why it is not a one-line fix

Changing the prototypes to `far_t` is correct but breaks the build immediately:
all **890** `ovr_stshStoreFile(...)` call sites cast the result to `uint16_t`,
which is an illegal struct cast (167 compile errors, measured).

The fix therefore has to merge each pair

```c
X[i].ofs = (uint16_t)ovr_stshStoreFile(...);
uVar = 0x195d;
...
X[i].seg = uVar;
```

into a single far-pointer result, file by file (ovc44 233, ovc45 228, ovc46 158,
ovc48 149, ovc49 117, ovc15 5).  That is mechanical but must be done per site;
the prototype change alone is not shippable.

Status: 0x195d sites unchanged (706); the cause and the exact edit shape are now
known and recorded here.

## The ovc46 shape is different - do not apply the ovc15 transform blindly

`ovc15_sprite.c` (fixed) has

```c
pcVar4 = ovr_stshStoreFile(data, arg);
uVar6  = 0x195d;
*(... + iVar10)     = (uint16_t)pcVar4;   /* .ofs */
*(... + 2 + iVar10) = uVar6;              /* .seg  <- dead constant, must be the call's DX */
```

`ovc46_assets.c` does **not** have that shape. There the call result goes straight
into the field and the segment comes from the *argument*:

```c
uVar3 = in_DX;
BldGfxNormal[0x201].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar2,uVar3);
uVar4 = 0x195d;
...
BldGfxNormal[0x201].seg = uVar3;      /* <- the argument, not uVar4 */
BldGfxNormal[0x202].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar2,uVar4);
uVar3 = 0x195d;
...
BldGfxNormal[0x202].seg = uVar4;
```

The segment is carried in a rolling variable that is *also* passed as the
argument, so the constant is the chain's seed rather than dead code in every
case.  Applying the `stsh_store` rewrite here would change which value ends up in
`.seg` and could corrupt the tables.

Measured with the scripted transform in dry-run mode:

```
ovc46_assets.c    rewritten 0,   skipped 0    (the call form does not match)
ovc48_assets2.c   rewritten 17,  skipped 116  (mixed shapes)
ovc20_stash.c     rewritten 0,   skipped 0    (no such calls)
```

So `ovc46`/`ovc48` need per-site reading of the rolling-segment chain before any
edit.  Only the three `ovc15` sites have been converted (and only those).

## Answer: `.seg` comes from `stshStoreFile`'s returned DX, and `ovc46` is the same as `ovc44`

Dumping `init_assets1` (`7A57:0000`, `OVC_46_7A57`) at its first store gives the
identical sequence seen in `init_assets`:

```
7a57:003e  CALLF ovr_stshRleType2        ; DX:AX = pfVar2
7a57:0046  PUSH DX / PUSH AX             ; the whole far pointer is the argument
7a57:0048  CALLF ovr_stshStoreFile
7a57:0050  PUSH AX                       ; returned OFFSET
7a57:0056  PUSH DX                       ; returned SEGMENT
7a57:0059  MOV DX,0x195d                 ; dead
7a57:005e  MOV DX,ES                     ; dead
7a57:0060  POP AX
7a57:0061  MOV ES:[BX+0x4DD2],AX         ; .seg = returned SEGMENT
7a57:0066  POP AX
7a57:0067  MOV ES:[BX+0x4DD0],AX         ; .ofs = returned OFFSET
```

So for `ovc46` the answer is the same as for `ovc44`: **the field takes the
function's returned `DX`**, and `0x195d` is dead.

The recovered C conflates two different values in one rolling variable:

```c
uVar3 = in_DX;                                              /* segment of pfVar2 - the ARG */
BldGfxNormal[0x201].ofs = ovr_stshStoreFile(pfVar2, uVar3);
uVar4 = 0x195d;                                             /* seed for the next ARG */
BldGfxNormal[0x201].seg = uVar3;                            /* <- should be the CALL's DX */
```

`.seg` is currently assigned the **argument**, while the hardware stores the
**result**.  Both the argument seed (`0x195d`) and the field assignment are wrong
in the same way, which is why a naive replacement of only one of them would leave
the tables inconsistent.

Correct transform per chain element (one scratch local is enough, because `.seg`
is assigned before the next call):

```c
BldGfxNormal[N].ofs = stsh_store(pfVar2, (uint16_t)arg, &stshSegTmp);
...
BldGfxNormal[N].seg = stshSegTmp;          /* delete the  uVar = 0x195d  seed */
```

and the next element's argument becomes the segment of the *new* `pfVar2` (the
high word of `ovr_stshRleType2`'s return), not `0x195d`.

Status: three `ovc15` sites converted; `ovc44`/`ovc46`/`ovc48`/`ovc49` still to do
with the two-part transform above.

## Second transform (argument seed): proven on one chain, not yet scaled

Per the same disassembly, the **argument** to `stshStoreFile` is the whole far
pointer returned by `ovr_stshRleType2`:

```
003e CALLF ovr_stshRleType2
0046 PUSH DX / PUSH AX        ; the far pointer is the 2nd argument
0048 CALLF ovr_stshStoreFile
```

Ghidra lost that segment as well, seeding a rolling variable with the dead
`0x195d` (or reading `in_DX`) *before* the call.  Inline asm can capture it
correctly right after the call:

```c
pfVar2 = ovr_stshRleType2(...);
asm { mov uVar3,dx };          /* segment of pfVar2 */
BldGfxNormal[0x201].ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)uVar3, &stshSegTmp);
...
BldGfxNormal[0x201].seg = stshSegTmp;
```

That form was applied to the first two elements of the `ovc46` chain, compiled
clean and reduced the gate by 2 - then **reverted**: the rest of the chain still
used the previous element's variable, so a two-element change leaves the chain
inconsistent.  A partial conversion is worse than none.

Why the scripted pass does not scale as written (`tmp/fix_seed_file.py`):

```
ovc46_assets.c   captured 2, no RLE match 0, 0x195d left 177
```

Most `ovr_stshRleType2(...)` calls wrap over two source lines, so the
single-line matcher only sees the first chain.  The next attempt needs a
multi-line call matcher (match up to the closing `);`) before it can be applied
file-wide.

Status: the `.seg` half is fixed for 543 results; the argument seed is unchanged
(704 literals) and needs this multi-line-aware pass.

## The remaining ovc45 sites are inside an unmarked merged body

`ovc45_unitinfo.c` contains **zero** function markers (`/* XXXX:XXXX */`).  The
202 remaining `0x195d` sites all sit after line 618, in a region with no function
boundary at all - attributing them to `ovc45_textArena2` happens only because it
is the nearest *definition*, and that function itself ends at line 618.

Consequence: the third shape

```c
pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
uVar20 = 0x195d;
*(uint16_t *)((int)&BldInstances[0].seg + (uVar19 + 1) * 0xc) = uVar16;  /* other var */
((bld_inst_t *)BldInstances + uVar19 + 1)->ofs = (short)pcVar6;
```

cannot be paired safely, because the variable that lands in `.seg` is not the one
seeded next to the call - and the code it belongs to is not a single function we
can disassemble and check.

Fixing these needs the function boundaries restored in the model (the same
merged-body problem already noted for `ovc22_textRingProt`, `ovc49_body1`,
`ovc23_usesAlignUp43`), not another per-file rewrite.

Status of `0x195d`: 706 -> 321 (ovc46 cleared; ovc44 11, ovc48 31, ovc45 202 in
the unmarked region, the rest spread over smaller files).

## Correction: ovc45_unitinfo.c did have markers - the merged body is `ovc45_buildPlacementMessage`

My earlier "zero function markers" came from a regex that only accepted
upper-case hex (`[0-9A-F]`); the file's markers are lower-case.  After restoring
the 25 missing ones there are 54, and every remaining `0x195d` site is inside a
marked segment:

```
/* 77eb:0d61 */   199 sites
/* 77eb:1754 */     2 sites
/* 77eb:1bb3 */     1 site
```

`77eb:0d61` is `ovc45_buildPlacementMessage`, recorded as **1752 bytes**, but its
C body spans **3354 lines** (lines 652-4005) - about 1900 lines/KB, far past the
900 lines/KB plausibility limit used elsewhere.  So it is a merged body after
all: the code of several original functions was spliced into one C body, which is
why the store/`.seg` pairs cannot be matched to a single disassembled function.

That keeps the merged-body blocker, but now it has an exact address and a name
instead of "an unmarked region".
