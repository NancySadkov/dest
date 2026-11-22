# Why REBUILT.EXE does not run: it cannot be loaded

Status: measured, controlled, and reproducible.  Not a code-generation or link defect.

## The measurement

| image | file | header | relocations | load image |
|---|---|---|---|---|
| `game/STRONG.EXE` (original) | 511,280 | 7,680 | 1,832 (7,328 B) | **110.4 KB** |
| `tmp/buildsrc/REBUILT.EXE` | 747,954 | 47,616 | 11,477 (45,908 B) | **639.1 KB** |

The original is a Borland VROOMM executable: its MZ header describes a small *resident*
image (110 KB) and the remaining ~400 KB of the file are overlay segments that the
overlay manager reads on demand.  DOS only loads the resident image.

Our link puts every recovered module in the resident image, because each module gets
its own code segment but nothing is overlaid.  The result needs 639 KB of conventional
memory; a DOS machine with a shell and drivers has roughly 500-580 KB free, so DOS
refuses to load it.

## The control

A program that fails to load and a program that terminates normally are
indistinguishable from inside the harness, which is what misled the earlier
"EXIT_ZERO means it ran" reading:

| run | `RUN.LOG` |
|---|---|
| garbage file named `STRONG.EXE` | `EXIT_ZERO` + `BATCH_DONE` |
| **the original, padded to 747,954 bytes** | `EXIT_ZERO` + `BATCH_DONE` |
| original, unmodified | empty (hangs at the config screen) |
| REBUILT.EXE | `EXIT_ZERO` + `BATCH_DONE` |

The padded original reproduces the rebuilt image's behaviour exactly.  Enlarging the
header (`cp`/`cblp` at offsets 4 and 2) is the only change, so the cause is size.

This also explains why the INT 21h markers in `main`, in `startx` and in a
marker-only `main` wrapper printed nothing, and why the CRT entry points
(`__exit`, `__cleanup`, `_abort`, `__restorezero`, `___exit`) were never entered:
no code runs at all.

## What it would take

The resident image must drop below roughly 500 KB, and ideally close to the
original's 110 KB.  The recovered code is ~600 KB, so this is not a matter of
trimming: the modules have to become overlays.

Options, in increasing fidelity:

1. **Borland overlays (`-V`/VROOMM).**  Mark the overlay modules and let the Borland
   overlay manager link them into the file after the resident image, exactly as the
   original did.  The recovered `ovl.c` (the overlay loader) and the 463 `ovr_*`
   thunks already exist in the tree, so the machinery is modelled; what is missing is
   the link-time division into resident and overlay segments.
2. **Split the image.**  Link several executables that chain-load each other.  Cheap,
   but does not reproduce the original's memory layout.
3. **Drop modules.**  Not acceptable - the point is functional parity.

Option 1 is the faithful one and reuses what is already recovered.

## Until then

The link is clean (0 undefined, 0 fixups, 0 duplicates, 0 overflows, 63/63 modules),
so every other check is meaningful, but `REBUILT.EXE` cannot be executed and no
data-state diff can be attempted.
