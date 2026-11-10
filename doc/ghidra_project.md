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


## Naming coverage (final)

```text
functions=1590 default=0
symbols=13348 default=0
definedData=2493 noSymbol=0 defaultSymbol=0
equates=26
```

All functions, symbols and defined data items now have names.  The semantic
names for the in-game state are recorded in `doc/bss_globals.md`; the rest use
the deterministic type/address scheme from the bulk pass below.  The old
`LAB_`/`DAT_`/`UNK_` prefixes are gone.

## Next project work

1. The string-offset sweep is complete: every remaining expression is mapped
   by `scripts/fbov/map_string_offsets.py`; the report
   `tmp/string_offset_targets2.csv` has **0 unresolved** values.  The common
   targets are real data, e.g. `0x4234 -> gap_2410_2A7C + 6072`
   (`BLD_RECORDS`), `0x69E4 -> s_Your_may_continue_p_2410_69db + 9`.
2. Fix function prototypes for the functions where segment values were
   typed as pointers so the clean export stays clean without the sweep.
3. Refine the type/address names for individual subsystems into semantic
   names; every item already has a unique name, but only the in-game state and
   BSS globals are semantically named so far.
4. Replace `unaff_`/`in_`/`extraout_` locals by fixing signatures and
   register/return types.


## Bulk naming pass

After the semantic names above, the remaining default symbols were given
deterministic, type-based names by `scripts/ghidra/BulkNameRemaining.java`:

```text
LAB_*   -> L_<function>_<offset>
DAT_*   -> <type>_<block>_<offset>
SUB_*   -> sub_<block>_<offset>
UNK_*   -> unk_<block>_<offset>
unsymbolized data -> data_<block>_<offset>_<type>
```

`scripts/ghidra/RefineBulkNames.java` then turns `undefined1/2/4_` prefixes into
`byte_/word_/dword_`.  Every function, data item and symbol now has a name; the
semantic names for the in-game state and BSS continue to take precedence.
Project backup before the bulk pass: `gpr_bak_before_bulk`.


## Prototype tooling

`scripts/ghidra/DumpProtos.java` prints signatures, parameter storage and
return storage for a list of addresses.  `scripts/ghidra/SetProtoSimple.java`
copies a return type and a parameter type from donor functions.

Caution: for a `__cdecl16far` function that returns a far pointer, Ghidra may
insert a hidden `__return_storage_ptr__` parameter instead of using `DX:AX`.
`manage_4d05_03a4` needs its return type modeled as a scalar (`uint32_t`) or
with explicit custom storage before its callers lose the `in_DX` artifact.
