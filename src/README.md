# Recovered source

This is the active reversed source tree for `STRONG.EXE`.

| Path | Contents |
|---|---|
| `main.c` | recovered `main` (`1301:000C`) |
| `ov_<seg>.c` | one file per original overlay code segment (`ov_2d63.c`, ...) |
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

Accepted functions are listed in `doc/vroomm_accepted.md`.  The early 2024
partial rewrite is quarantined in `reference/legacy_src/` and is not built.
