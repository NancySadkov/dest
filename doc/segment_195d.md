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
