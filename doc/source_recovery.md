# Source tree recovery status

The rebuild is a **stub-first** reconstruction.  The Ghidra project is the
model of the program; `src/` is a tree of compilable stubs that are replaced by
real code one function at a time, starting at `main()`.

## Method

1. **Refine the Ghidra project** - recover structures, name their fields, apply
   those types, and name arguments, locals and globals.  This is where the
   evidence lives, and it is why every exported signature is trustworthy.
2. **Dump the stubs** - `scripts/fbov/make_stub_tree.py` writes one C module per
   original module into `src/`, every function a stub with its recovered
   signature, plus `funcs.h`, `globals.h`, `types.h`, `compat.h` and `st.h`.
3. **Replace from `main()` outwards** - follow the call graph from `main()`,
   replace one stub with its recovered body, and keep the whole tree compiling
   after every function.  This is the progress ratchet.
4. **Validate** - boot the rebuild and compare its data state with
   `STRONG.EXE`.  The original is the oracle.

No step is done out of order, and nothing is committed that does not compile.

## `src/` does not exist yet

`src/` is the **output of step 2**, not a working area.  It is created by
`scripts/fbov/make_stub_tree.py` from the refined Ghidra project, and only then
filled in, one function at a time.

An earlier attempt exported it before step 1 was finished.  Every signature in
that tree was a placeholder (`undefined f()`, `param_1`), every global had a
generated name (`byte_2000_BSS_007A`), and the structs were full of
`field_0xNN`.  It compiled, and it was worthless: a dump.  It has been
deleted, and the rule is now explicit:

> No function body enters `src/` until its prototype, arguments, locals and
> globals are recovered in the Ghidra project.

The hand-written Ghidra type-library headers live in `types/`; they are input
to the project, not export output.

## The overlay thunks

The original binary calls `ovr_<name>` to load an overlay and jump to `<name>`.
Borland's VROOMM generated those from `#pragma overlay`; the rebuilt tree has no
overlay manager, so each thunk is a C forwarder with the target's recovered
signature.  `scripts/ghidra/TypeThunks.java` gives the thunk functions in the
Ghidra project the target prototype, which is what makes call sites decompile
with real argument types.

## Conversion standard: behavioural C

The C must produce the same state and effects as the original; it does not have
to be instruction-identical.  `STRONG.EXE` is the oracle, exercised with the
deterministic harness (`scripts/fbov/boot_game_det.py`), which boots a build and
snapshots memory at a fixed point for comparison.

Consequences:

- Struct layout and every global's value are part of the contract.
- Code shape, register use, helper names and local names are not.
- A recovered function is written the way the original C plausibly looked, then
  corrected until the rebuild's data state matches.

## What has been done

| Item | State |
|---|---|
| Ghidra structure audit | 35 structures, 497 fields; 261 auto names in 6 structs |
| Structure refinement | `scripts/ghidra/RefineStructs.java` named all 261 fields |
| Stub tree | 55 modules, 1016 stubs; 55/55 compile |
| Function recovery | `main`, `init`-side helpers below |

Recovered so far (in `src/`):

| Function | Module |
|---|---|
| `main` | `main.c` |
| `play_sfx` | `o11.c` |
| `uiMainMenu` | `o41.c` |
| `update_pause_button`, `toggle_pause` | `o28.c` |
| `save_49fd_081e` | `o19.c` |

## Data image

`globals.h` declares all recovered globals; the definitions are added as the
functions that reference them are recovered.  The data image is deliberately
**not** emitted as one blob: it would exceed Turbo C's 64 KB per-object limit and
would be a dump rather than a recovery.

## Notes

- Keyboard values are raw BIOS `INT 16h` results: scan code in the high byte,
  ASCII in the low byte (`0x1c0d` = Enter, `0x4800` = Up, `0x2f56` = `V`).
- The decompiler's constant-pointer heuristic renders those key values as
  expressions such as `(char *)"sword4.voc" + 8`; exports set
  `setInferConstantPointers(false)` so keys stay numeric.
- `scripts/ghidra/TypeThunks.java` must be re-run after new function prototypes
  are recovered, otherwise the thunks keep their old `undefined f()` shape.
