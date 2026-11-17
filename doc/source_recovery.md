# Source tree recovery status

_Measured by `python scripts/fbov/recovery_progress.py`._

## What is in `src/`

`src/` is the rebuildable tree.  Each overlay module is one or more C/asm
files (e.g. `src/c50872.c`, `src/ov_6190.c`, `src/a77eb0.asm`); `src/dgroup.c`
holds the exact DGROUP image and `src/st_types.h` the recovered structs.

A function that has been converted to C is plain C.  A function that has not
is kept as an inline byte dump:

```c
void __cdecl16far f_6190_0039(void)
{
  unsigned char pad[0x2];
  asm db 056h,08Bh,076h,006h, ...
  (void)pad;
}
```

`asm db` is a placeholder: it reproduces the original instructions, but it is
not recovered source.  The long-term goal is to remove every one of them.

## Conversion standard: behavioural C

The recovered tree is now converted to **behavioural C**: the C must produce the
same data state and I/O effects as the original, but it does not have to be
instruction-identical.  The original `STRONG.EXE` is the oracle — the rebuild is
booted under the deterministic harness and its memory is compared with the
original at the same point.

Consequences:

- `src/behaviour/` holds the behavioural C for a module.  When a file exists
  there it is used instead of the byte-dump module in `src/`.
- `python scripts/fbov/build_overlays.py --behaviour` compiles the whole tree
  with those overrides, skips the patch table and the size check, and reports
  every module whose linked size changed.
- The byte-exact build (`build_overlays.py --verify`, `build_standalone.py`)
  remains available for the modules that have not been converted yet; it is
  the reference image generator, not the conversion gate.

A behavioural body may be smaller or larger than its original slot.  Sizes that
grow need the overlay re-layout/loader work described below; sizes that shrink
already compile and are reported by the behavioural build.

## Current numbers

| Metric | Value |
|---|---|
| overlay modules | 50 |
| functions | 967 |
| functions still byte dumps | 851 |
| functions in C | 116 (12%) |
| bytes still emitted by `asm db` | 409,873 |
| `src/ov_patch.csv` byte patches | 38,616 |

`recovery_progress.py --detail` prints the same per module.

## Completed modules

| Module | Size | Notes |
|---|---|---|
| `0x6190` | 173 B | 2/2 functions in C, verified byte-identical |
| `0x3168` | 288 B (C: 264) | 1/1 function in behavioural C (`src/behaviour/ov_3168.c`) |

Overlay `4D05` has 24 of its 34 functions in C (`src/game/ui.c`), verified
against the original overlay by `scripts/fbov/verify_ui_bytes.py`; the
remaining bodies (`0000`, `056E`, `0DBE`, `1296`, `1835`, `1BEE`, `23FC`,
`26F6`, `2D79`) are the large sheet renderer, its dialogs and the management
loop.

## The `ov_patch.csv` layer

`src/ov_patch.csv` overwrites individual bytes of the linked overlay output.
It exists because Borland VROOMM encodes cross-overlay calls as
`lcall <trampoline slot>:<loader-patched segment>`; a normal C link produces a
direct far call instead.  The patch table restores the original operands, so
C and byte dumps can coexist and the standalone build stays byte-identical.

Retiring the table means either (a) converting modules together with a linker
that emits the trampoline form, or (b) accepting a rebuild that links against
the real overlay manager rather than reproducing the original image.

## How a function is converted

1. Disassemble the original slot.
2. Write C in the module's file (`src/behaviour/ov_XXXX.c` for new work),
   replacing the dump.
3. Compile with `python scripts/fbov/build_overlays.py --behaviour`; the whole
   tree must compile and link, and the module's size delta is reported.
4. For the byte-exact subset, compare the linked segment with the original
   (`--verify`), masking relative operands and OMF relocations.
5. Validate behaviour against the original with the deterministic harness
   (`boot_game_det.py`) once the rebuild can run the module.

The behavioural build now finishes in roughly a minute: `run_dosbox.py
--until <sentinel>` stops the emulator as soon as the batch writes its done
marker instead of waiting out the timeout.

## Why full conversion is a long job

851 functions remain, most in the 1–8 KB range, and each needs the
decompiler output to be re-typed and re-shaped until TCC reproduces the exact
instruction stream.  Small functions take one or two compile/test cycles;
the large renderers (`5087:056E` is 2,061 bytes, `6FFE` has 1,877 dump lines)
take many more.
