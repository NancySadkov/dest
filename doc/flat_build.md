# Flat development build

The flat build is a development-only EXE with **all Borland overlays resident**.
It exists so the recovered code can be run and compared without the VROOMM
overlay manager.  It is not the final overlayed target; it is the runnable
oracle for the C recovery loop.

## What is in the image

| Part | Source |
|---|---|
| DGROUP (`_DATA`, 38,042 bytes) | `dglink.asm` from `tmp/linkbuild` (byte-exact) |
| `main` | `src/recovered/main.c`, compiled with TC30 `-ml -1 -G -O` |
| Overlay code | **original bytes** of every overlay code region, one PARA-aligned segment each |
| Resident runtime | original bytes of segments `0x1000`, `0x138E`, `0x13AA`, `0x1403` (CRT + C0 + VROOMM) |
| Far data segments | original bytes of the static DATA segments other than DGROUP |
| Overlay header segments | generated trampolines: each header entry is `jmp far` to the real code offset |
| `F_LDIV@` | copied original runtime helper (`runtime.asm`) |
| Stubs | only symbols that are still unrecovered |

Overlay code is currently the original byte image (via `flat_ovsegs.py`), not
the partially converted C.  This is deliberate: the game stores absolute code
offsets in jump tables and function pointers, so the byte layout of each
overlay region has to stay identical.  Converted C functions can be swapped in
individually once they are verified to be byte-identical to the original at the
original offset.

## Build sequence

All commands run from the repository root.  `tmp/flat/` is the build tree.

```powershell
python scripts/fbov/flat_stage_sources.py   # copy main.c, rename header symbols
python scripts/fbov/flat_mkfp.py            # MK_FP(0x1410/0x280) -> MK_FP(_DS)
python scripts/fbov/flat_stubs.py           # drop stubs now supplied by origsegs.asm
python scripts/fbov/flat_origsegs.py        # runtime + data + header trampoline segments
python scripts/fbov/flat_ovsegs.py          # one original-byte asm segment per overlay
python scripts/fbov/flat_link.py            # writes link5.rsp + build11.bat
```

Then, in DOSBox (mount `C:` = `tmp/flat`, `D:` = `tools/TC30`, `E:` = `tools/BC30`):

```text
call build11.bat        (assemble origsegs + 51 overlays, compile main + stubs, link)
```

Turbo C emits byte-aligned code segments, which makes Turbo Link pack them and
introduce a one-byte bias in every segment.  That breaks the absolute offsets
used by the original code.  Force paragraph alignment and relink:

```powershell
python scripts/fbov/flat_align.py
```

```text
D:\BIN\TLINK.EXE @link5.rsp
```

Finally apply the original program's relocations:

```powershell
python scripts/fbov/flat_patch.py
```

`flat_patch.py` writes every MZ relocation and FBOV fixup into the flat image
using the flat segment paragraphs, and appends matching MZ relocation entries
so DOS adds the load segment at run time.  It also:

- maps `raw 0` MZ targets to the resident segment,
- leaves `main`'s Turbo-Link-resolved far calls alone (they already target the
  flat code segments directly),
- rewrites every overlay-header trampoline to `EA <offset> <segment>`,
- disables the C0 init-table entry that calls `__OvrInit` (there is no FBOV in
  the flat EXE).

## Current state

`FLAT.EXE` (about 560 KiB) links and runs.  It reaches the game's real startup
screen:

```text
ENTER: use previous configuration, SPACE: reconfigure, ESC: quit
```

and `SPACE` opens the sound configuration prompts.  After the questions are
answered the game prints its own fatal message:

```text
Error 0 20.  (Give Cathryn BOTH numbers.)
```

and exits.  The message comes from the game's fatal handler (overlay code
`0x3168`); the call site is overlay `0x474A` at offset `0x1482`, which reports
the failure of its block allocator (DGROUP free-list head `0x47FA` is still
zero).  The immediate cause is lack of conventional memory: keeping every
overlay resident leaves roughly 100 KiB, while the original 128 KiB load
module leaves about 500 KiB.  The original program shows the same screens and
continues into a 320x400 mode, so this is a flat-build limitation rather than
a relocation bug.

Two relocator details matter here:

- Turbo C's code segments are byte aligned.  `flat_align.py` rewrites every
  object's SEGDEF to paragraph alignment before the final link, otherwise all
  original absolute code offsets acquire a per-segment byte bias.
- Turbo Link puts `_STACK` before the code segments.  `flat_patch.py` moves
  the MZ `SS:SP` past the whole image, otherwise the C0 startup grows its
  stack over game code (this caused the earlier wild jumps to `CS=0000`).

The remaining path to a fully runnable binary is the overlayed link (the real
VROOMM target).  The flat build remains useful as a harness for code that
fits in the space, and as the reference for the relocation/segment model.

## Why original bytes for overlays

The recovered C tree is the maintainable target, but a converted function that
is even one byte longer than the original shifts every following function and
invalidates the game's absolute offsets.  The flat build therefore keeps the
original overlay bytes until a converted function has passed a
whole-segment byte comparison at its original offset.
