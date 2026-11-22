# Step 6: isolating the startup abort

> Superseded in part by `doc/step6_entry.md`: the exit-3 abort came from
> `C0M.OBJ`'s `_startup` being the entry point.  With `_startx` as the entry the
> recovered CRT reaches `main`.  The isolation results below still hold.

## Why

The rebuilt image exits with code 3 before `main` (an `exit(7)` probe in `main`
never prints).  A tiny overlay control (`C0M` + tiny main + `OVERLAY.LIB` +
`CM.LIB`) prints `K` and returns 9, and adding our five `GLOB*.OBJ` keeps that
working.  The question this experiment answers: is the **recovered CRT**
(`crtl.c`) the cause, or is it one of the game objects?

## Setup

`tmp/crt_iso.py` links the tiny main against `CRTL.OBJ`, `STUBS.OBJ`,
`INTRINS.OBJ` and the `GLOB*.OBJ` files, stubbing whatever the CRT still
references from the game tree.  Two symbols were needed:

```
_INIT_TEXTFILENAME    (crtl.c calls the game's init_textFilename)
_OVR__FAKREALCVT      (OVR.ASM's float trap)
```

Both stubs return 0 ("GUESS: stub for the isolation experiment").  The link then
reports no undefined symbols and produces `TU.EXE` (108,136 bytes).

## Result

`TU.EXE` produces **no output at all and does not exit** — `TU.OUT` stays 0
bytes, so the batch never reaches its `DONE` line.  It hangs during startup,
before `main`, with the CRT in the image but without any game object.

Contrast with the full image, which *exits* with code 3.  So the CRT alone is
enough to break the startup, and the exit code then depends on what else is
linked.  That is the first time the CRT has been tested without the whole tree
(it previously failed to link on `_INIT_TEXTFILENAME`).

## What this means

The failure is inside the compiler's startup/CRT with our recovered `crtl.c`
present, not in the game objects.  Two readings are possible:

* our `crtl.c` defines one of the startup's own objects (`__psp`, `_stklen`,
  `_DGROUP`, the heap variables ...) with a value or placement that the
  toolchain's `C0M`/`OVERLAY.LIB` then trips over; or
* the overlay manager needs an initialisation step that only the real
  `CRTL` library performs.

Either way the next experiment is the same: link the same isolation image with
**`CM.LIB`'s runtime instead of `crtl.c`** (stubbing the recovered helper names
that our tree uses), and see whether the hang disappears.
