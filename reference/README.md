# Reference tree (quarantined)

This directory contains the abandoned **mass-decompiler baseline**.

It is kept only as a function/address inventory. It is **not** part of the
build, is **not** a source of truth, and must not be used for symbol names,
types, data references or C code.

The correct model and recovery process are described in `/plan.md`.

- `decompiled_baseline/` — the old `src/decompiled` tree exported from the
  mzap-merged image.
- The old Ghidra project remains under `gpr/` and is likewise quarantined.

New work goes to:

- `scripts/fbov/` — independent FBOV parser and validation tools.
- `tools/ghidra_fbov/` — the fresh Ghidra loader/model builder.
- `src/recovered/` — hand-recovered source, function by function.
- `doc/` — segment/fixup/function ledgers and progress.
