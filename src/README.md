# Recovered source

This is the active reversed source tree for `STRONG.EXE`.

| Path | Contents |
|---|---|
| `main.c` | recovered `main` (`1301:000C`) |
| `ov_<seg>.c` | one file per original overlay code segment (`ov_2d63.c`, ...) |
| `c<seg><n>.c` | ordered C chunk for a module that needs non-standard byte blocks |
| `a<seg><n>.asm` | TASM byte block holding one non-standard function |
| `k<seg>.h` | prototypes shared by that module's chunks |
| `ov_patch.csv` | original call/jump operand and switch-table bytes restored at build time |
| `static/` | labeled TASM blocks for the static code/data/header segments |
| `static_index.json` | original file offset, size and segment name for each static block |
| `main_patch.csv` | call/jump operand bytes for the compiled `main` |
| `mz_header.json` | MZ header fields and prefix; relocations come from `doc/fbov_relocs.csv` |
| `fbov_other.json` | small remaining FBOV byte ranges as hex; fixup tables come from `doc/fbov_fixups.csv` |
| `dgroup.c`, `dgroup.h` | recovered DGROUP (`_DATA`), byte-identical to the original |
| `st_types.h` | recovered structs/enums/typedefs |
| `st_compat.h` | decompiler/calling-convention shims |

Function names encode the original location: `f_<seg>_<offset>`.

## Verification

The VROOMM verification tools compile these files with Turbo C++ 3.0 and
accept a function only when its bytes match the original image except for
call/jump operands:

```text
python scripts/fbov/vroomm_verify_linked.py 2d63:ov_2d63
python scripts/fbov/vroomm_sweep.py
```

The source-only build is:

```text
python scripts/fbov/build_standalone.py
```

It compiles the overlays from this tree, applies `ov_patch.csv`, fills the
committed static/FBOV base blobs, and verifies the output hash against the
original.  It does not read `game/STRONG.EXE`.

Accepted functions are listed in `doc/vroomm_accepted.md`.  Byte acceptance
is tracked separately from true C recovery in `doc/recovery_status.md`
(`scripts/fbov/recovery_status.py`).  The early 2024 partial rewrite is
quarantined in `reference/legacy_src/` and is not built.

See `../doc/quirks.md` for the compiler/tooling quirks and the full recovery
checklist.  The path from the current oracle build to a source-only EXE is in
`../doc/standalone_build_plan.md`.
