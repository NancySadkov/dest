# DGROUP verification

Target: `game/STRONG.EXE`, DGROUP `0x2410:0000..0x9499`.

| Item | Value |
|---|---|
| File offset | `0x15F00` |
| Size | `0x949A` (38,042 bytes) |
| Recovered symbols | 1,205 |
| Gap byte-arrays | 257 |
| Bytes accounted for | 38,042 / 38,042 |
| Map | `doc/dgroup_map.csv` |
| Source | `src/recovered/dgroup.c`, `dgroup.h` |
| Compiler | Turbo C++ 3.0, `-ml` |
| Object | `DGROUP.OBJ` |

## Symbol layout

The TC30 object was parsed as OMF. Every exported symbol was compared with
`dgroup_map.csv`:

```
matched 1160   mismatch 0
```

## Byte comparison

The object's DGROUP segment (segment 2, length `0x949A`) was compared with the
original bytes:

```
differences: 0
```

The recovered C file therefore reproduces the original DGROUP byte for byte
when compiled with TC30.

## Static Ghidra model

The Ghidra model uses the *post-relocation* view: MZ relocation words are
rewritten to the static `0x1000 + value` form (`0x2410` instead of the file's
`0x1410`). The source file keeps the original relative values so the object
matches the original EXE. The two views are intentional and separate:

- `src/recovered/dgroup.c` — original/linker view, byte-identical to the file.
- `gpr_fresh` — static analysis view, `DS = 0x2410`, all MZ relocations applied.

`ApplyDgroupMap.java` applied 1,205 names/types to `gpr_fresh`. The decompiler
now renders `GMenuItem`, `CrossBlitPtr`, `GWorkDir`, etc. instead of raw
`DAT_2410_*` offsets.

## Remaining code-level artifacts

A few expressions such as `s__magic_mill_2410_68f7 + 9` remain. These are
segment constants stored into pointer-typed *fields* in the consuming
functions (`0x6900` is an overlay code segment, not DGROUP data). They are
fixed by typing those function-local fields/structs, not by changing the
DGROUP image.
