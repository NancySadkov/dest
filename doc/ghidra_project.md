# Ghidra project mapping

The decompiler output is only trustworthy after the Ghidra program model is
correct.  This document tracks the project-level fixes.

## Root cause of `"string" + offset`

The baseline export (`reference/decompiled_baseline/`) was produced without
disabling the decompiler's constant-pointer inference.  Ghidra therefore
rendered every scalar that fell inside a string as a pointer into that string:

```c
else if ((char *)key == (char *)"mason's hall" + 7) { ... }   /* == 0x2300 */
DGROUP_at__at_ = (uint16_t)("puppetmaker" + 3);               /* == 0x2410 */
```

`"puppetmaker"` is at DGROUP `0x240D`, so `+ 3` is `0x2410`, the **DGROUP
segment**.  `"mason's hall"` is at `0x22F9`, so `+ 7` is the scan code
`0x2300`.

## Project fixes applied

1. `scripts/ghidra/ExportAll.java` now calls
   `opts.setInferConstantPointers(false);`.  This removes the inferred
   pointers from the whole export.
2. `2410:0004` (`__C0_ASM_CopyRight`) was retyped from `string` to a 43-byte
   array.  Small integer constants such as `0x0006`/`0x0008` no longer
   resolve to `"Borland C++ - Copyright 1991 Borland Intl." + n`.
3. A `DGROUP_SEG = 0x2410` equate was created and applied to the 4,621
   scalar operands with that value.
4. `scripts/ghidra/AuditProject.java` reports naming coverage.
   `scripts/ghidra/RetypeCopyright.java` performs step 2.
   `scripts/ghidra/CreateEquate.java` performs step 3.

## Effect on the export

Counts of `"string" + offset` expressions:

| export | expressions | `"puppetmaker"` |
|---|---|---|
| old baseline | 2,224 | 633 |
| `InferConstantPointers(false)` | 386 | 34 |
| plus copyright retype | 252 | 37 |
| plus `sweep_string_offsets.py` | **106** | **0** |

The sweep resolved every expression whose value is a segment constant and
replaced it with `DGROUP_SEG` or `SEG_xxxx` (`tmp/export_swept6`).  It also
renamed 561 raw segment scalars and replaced 89 small-integer collisions with
their integers, so the key debug call now reads:

```c
ovr_OVC40_69c8_04c6(0,0x251,DGROUP_SEG,0x27a,DGROUP_SEG,0);
```

The remaining 106 expressions all resolve to **real DGROUP data offsets**, not
segment values or integer constants.  The most common bases are:

```text
0x4234/0x4236  building record base (units)
0x3F48         build\thfres01.lbm follow-on table
0x69E4/0x69E2  substring pointers inside the save warning text
0x20A8/0x20AF  substring pointers inside "cleric castle"
```

Those need the DGROUP symbol/gap name (e.g. `BLD_RECORDS`) rather than a
segment name.


## Naming audit (`tmp/ghidra_audit`)

```text
functions=1590 default=0
symbols=12812 default=8668
definedData=2493 noSymbol=536 defaultSymbol=526
equates=26
```

- All 1,590 functions already have names.
- The 8,688 default symbols are almost entirely `LAB_` branch labels
  (`LAB_` 8,093, `DAT_` 591, `SUB_` 4).
- DGROUP (`2410`) has 506 symbols, 383 named plus 123 strings.
- The BSS block `2000_BSS` has 435 `DAT_` globals; the ten used by the
  recovered in-game code are now named in Ghidra by
  `scripts/ghidra/AnnotateBss.java`:

  ```text
  CA95 GUnits          CA99 GUnitCount     D1E6 GLeaderCount
  D19F GMenuGfxOfs     D1A1 GMenuGfxSeg    CA91 GPopulationLo
  CA93 GPopulationHi   CB0D GUnitGrid      CB09 GMapFlags
  CA90 GGameInProgress
  ```

  `src/game/bss.h` exposes the same names as aliases while the recovered C
  still carries the `DAT_2000_` identifiers.

## Next project work

1. The string-offset sweep is complete: every remaining expression is mapped
   by `scripts/fbov/map_string_offsets.py`; the report
   `tmp/string_offset_targets2.csv` has **0 unresolved** values.  The common
   targets are real data, e.g. `0x4234 -> gap_2410_2A7C + 6072`
   (`BLD_RECORDS`), `0x69E4 -> s_Your_may_continue_p_2410_69db + 9`.
2. Fix function prototypes for the functions where segment values were
   typed as pointers so the clean export stays clean without the sweep.
3. Name the remaining `2000_BSS` globals and `DAT_` data items.
4. Replace `unaff_`/`in_`/`extraout_` locals by fixing signatures and
   register/return types.
