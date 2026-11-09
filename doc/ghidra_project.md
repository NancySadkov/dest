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
| plus `sweep_string_offsets.py` | 196 | 0 |

The sweep resolved every expression whose value is a segment constant and
replaced it with `DGROUP_SEG` or `SEG_xxxx` (`tmp/export_swept2`).  It also
renamed 530 raw segment scalars, so the key debug call now reads:

```c
ovr_OVC40_69c8_04c6(0,0x251,DGROUP_SEG,0x27a,DGROUP_SEG,0);
```

The remaining 196 expressions are in two groups:

- 91 strings that live outside DGROUP (`__C0`/OVRTEXT segments), so the
  literal-to-segment map needs those blocks;
- 68 DGROUP data offsets which point at a real substring or table entry and
  must be resolved against `doc/dgroup_map.csv`/the Ghidra data item, not
  renamed as a segment.


## Naming audit (`tmp/ghidra_audit`)

```text
functions=1590 default=0
symbols=12812 default=8688
definedData=2493 noSymbol=536 defaultSymbol=543
equates=25
```

- All 1,590 functions already have names.
- The 8,688 default symbols are almost entirely `LAB_` branch labels
  (`LAB_` 8,093, `DAT_` 591, `SUB_` 4).
- DGROUP (`2410`) has 506 symbols, 383 named plus 123 strings.
- The BSS block `2000_BSS` has 435 `DAT_` globals still to name.

## Next project work

1. Sweep the remaining `"string" + offset` constants:
   - resolve each to its numeric value;
   - replace segment values with `DGROUP_SEG`/`SEG_xxxx`;
   - replace real data offsets with their DGROUP symbol;
   - leave scan codes/IDs as scalars.
2. Fix function prototypes for the 30 functions above so segment values are
   not typed as pointers.
3. Name the `2000_BSS` globals and the remaining `DAT_` data items.
4. Replace `unaff_`/`in_`/`extraout_` locals by fixing signatures and
   register/return types.
