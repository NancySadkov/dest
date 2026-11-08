# Flat development build

The flat build is a development-only EXE.  It keeps the Borland overlay code
on disk (`OVL.BIN`) and loads overlays into a small resident slot pool when a
header stub is called, so the game keeps conventional memory for its own heap.

## Image contents

| Part | Source |
|---|---|
| DGROUP (`_DATA`, 38,042 bytes) | `dglink.asm` from `tmp/linkbuild` |
| `main` | `src/recovered/main.c`, TC30 `-ml -1 -G -O` |
| Resident runtime | original bytes of segments `0x1000`, `0x138E`, `0x13AA`, `0x1403` |
| Far data | original static DATA segments except DGROUP |
| Overlay headers | generated entries `CD 3F <ov> <ofs>` (INT 3F) |
| Overlay code | not linked; blobs in `OVL.BIN` |
| Slot pool | 6 x 32 KiB resident segments `OVSLOT0..5` |
| Loader | `OVLTRAP_TEXT` (`scripts/fbov/flat_ovltrap.py`) |

## Build sequence

```powershell
python scripts/fbov/flat_stage_sources.py
python scripts/fbov/flat_mkfp.py
python scripts/fbov/flat_origsegs.py
python scripts/fbov/flat_ovltrap.py
python scripts/fbov/flat_stubs.py
python scripts/fbov/flat_link.py            # link6.rsp + build12.bat
```

In DOSBox (`C:` = `tmp/flat`, `D:` = `tools/TC30`, `E:` = `tools/BC30`):

```text
call build12.bat
```

Then force paragraph alignment and relink:

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

- Header stubs execute `INT 3F`; the 3 inline bytes are the overlay id and
  target offset.
- The handler looks up a pinned copy in the six slots.  On a miss it loads
  the blob from `OVL.BIN`, adds the load base to every FBOV fixup target, and
  far-jumps to the target.  Each slot has a refcount and an overlay id, so a
  resident copy is reused until all its callers have returned.
- The caller's return address is replaced by a resident trampoline; on return
  the trampoline decrements the refcount and resumes the caller.
- AX, the other registers and the flags are preserved across both paths.

## Current state / memory comparison

The rebuild reaches the real startup screen:

```text
ENTER: use previous configuration, SPACE: reconfigure, ESC: quit
```

ENTER switches to 320x400 and initialises the game cache.  After a longer
wait the free-list head at `DGROUP:0x47FA` is initialised exactly like the
original, but with a different block address because the rebuild has less
free memory:

| Quantity | Original | Rebuild (6 slots) |
|---|---|---|
| `DGROUP:0x47FA` (free-list head) | `0x478E:0x0008` | `0x6CC2:0x0008` |
| heap bookkeeping `[0x8D]` / `[0x91]` | `0x9FFE` / `0x9FFF` | `0x9C76` / `0x9FFF` |
| free conventional memory (approx.) | ~500 KiB | ~300 KiB |

At the black 320x400 screen the original accepts a key and starts drawing
(16-colour frame).  The rebuild accepts the key and then requests a 73,999
byte (`0x11D0F`) block through the far-heap wrapper in overlay `0x474A`; both
`farmalloc` and the game pool fail, and the game's own fatal handler prints
`Error 0 20`.

The remaining gap is the 192 KiB slot pool.  The next step is a variable-size
packed pool (or real VROOMM-style swapping) so the rebuild's free-memory
profile matches the original's; the relocation/loader logic itself is
validated by the startup prompt, the cache init and the 320x400 transition.
