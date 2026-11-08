# Flat development build

The flat build is a development-only EXE.  It keeps the Borland overlay code
on disk (`OVL.BIN`) and loads each overlay into a resident slot when a header
stub is called, so the game keeps most of the 640 KiB conventional memory for
its own heap.  This is the runnable scaffold used to compare behaviour with
the original `STRONG.EXE`.

## Image contents

| Part | Source |
|---|---|
| DGROUP (`_DATA`, 38,042 bytes) | `dglink.asm` from `tmp/linkbuild` |
| `main` | `src/recovered/main.c`, TC30 `-ml -1 -G -O` |
| Resident runtime | original bytes of segments `0x1000`, `0x138E`, `0x13AA`, `0x1403` |
| Far data | original static DATA segments except DGROUP |
| Overlay headers | generated entries `CD 3F <ov> <ofs>` (INT 3F) |
| Overlay code | not linked; pre-relocated blobs in `OVL.BIN` |
| Slot pool | 8 x 32 KiB resident segments `OVSLOT0..7` |
| Loader | `OVLTRAP_TEXT` (`scripts/fbov/flat_ovltrap.py`) |

## Build sequence

```powershell
python scripts/fbov/flat_stage_sources.py   # main.c, header symbol renames
python scripts/fbov/flat_mkfp.py            # MK_FP(0x1410/0x280) -> MK_FP(_DS)
python scripts/fbov/flat_origsegs.py        # runtime/data/header/slot segments
python scripts/fbov/flat_ovltrap.py         # resident loader
python scripts/fbov/flat_stubs.py           # drop stubs supplied by origsegs
python scripts/fbov/flat_link.py            # link6.rsp + build12.bat
```

In DOSBox (`C:` = `tmp/flat`, `D:` = `tools/TC30`, `E:` = `tools/BC30`):

```text
call build12.bat        (assemble origsegs + ovltrap, compile stubs, link)
```

Then force paragraph alignment (Turbo C emits byte-aligned code segments) and
relink:

```powershell
python scripts/fbov/flat_align.py
```

```text
D:\BIN\TLINK.EXE @link6.rsp
```

Finally build `OVL.BIN`, write the loader tables, point the C0 init record at
`_ovl_init`, move `SS:SP` past the image and apply the MZ relocations:

```powershell
python scripts/fbov/flat_patch_ovl.py
```

## Loader model

- A header stub executes `INT 3F`; the 3 inline bytes hold the overlay id and
  the target offset.
- The handler picks a free 32 KiB slot, reads the overlay code from `OVL.BIN`,
  adds the load base to every FBOV fixup target, and far-jumps to the target.
- The caller's return address is replaced with a resident trampoline.  When
  the overlay function returns, the trampoline frees the slot and resumes the
  caller, so nested calls keep their callers resident.
- The register file (including AX and flags) is preserved across both paths.

## Current state

The build runs through the real startup screen:

```text
ENTER: use previous configuration, SPACE: reconfigure, ESC: quit
```

on her ENTER the game switches to 320x400 and starts loading its data.  It
then still stops in the game's own fatal handler with `Error 0 20`: the
sample/memory allocator (`overlay 0x474A`) requests about 74 KiB, the C far
heap fails, and the game's fallback free list at `DGROUP:0x47FA` is empty.
In the original, at the same point that free list contains a block at
`0x478E:0x0008` and the game continues.

The loader itself is working: the trace shows the startup prompt, at least
six nested overlay calls, and the switch to 320x400 with `STRONG.DAT` being
read.  The remaining task is the game's sample/memory-pool initialisation
(and/or pinning overlay code used by the sound driver).

## Notes

- The old static patcher `flat_patch.py` and the all-resident overlay build
  remain available as a comparison point, but the current runnable build uses
  `flat_patch_ovl.py` and `OVL.BIN`.
- Slot count lives in `flat_origsegs.py` / `flat_ovltrap.py`.  Six slots was
  not enough for the deepest startup call chain; eight reaches 320x400.
