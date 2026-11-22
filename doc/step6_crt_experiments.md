# Step 6: what stops the rebuilt image from reaching main

Measured facts, all reproducible with the scripts in `scripts/` and `tmp/`.

## 1. Conventional memory is 540 KB, not ~600

`scripts/measure_free_memory.py` asks DOS for the largest free block
(`INT 21h AH=48h`, `BX=FFFF`; the size comes back in **BX** — AX is the error code,
which is why the first version reported 0 KB):

```
largest free block: 34,592 paragraphs = 540 KB
```

Our flat (non-overlay) image is 639 KB, so a flat build cannot load.  The game's
far-data tables (`GLOB*_DATA`) are only ~50 KB and are the game's own data, so
excluding them would not be enough.

Note: padding the original EXE and rewriting its `cp`/`cblp` is **not** a valid
ceiling test — that makes DOS load the overlay area as part of the image, and even a
512 KB padded build "returns".  Only the INT 21h probe measures the limit.

## 2. Our recovered globals are not the startup blocker

A tiny overlay control (`C0M` + tiny main + `OVERLAY.LIB` + `CM.LIB`) prints `K` and
returns 9.  Adding all five `GLOB*.OBJ` to it still prints `K` and returns 9.  So the
recovered global data can live under VROOMM without breaking the startup.

## 3. Our recovered CRT overlaps the library CRT — but only in isolation

Adding `CRTL.OBJ` to that tiny control fails at *link* with

```
Error: __XFFLUSH defined in module CRTL.C is duplicated ...
```

because the tiny program pulls a different set of `CM.LIB` members than the full
build does.  In the **full** build `CRTL.OBJ` + `CM.LIB` link with zero duplicates.

## 4. Without CM.LIB the program hangs instead of exiting — but still before main

Dropping `CM.LIB` and using only our recovered CRT reduces the undefined list to 8:

```
F_LDIV@ F_LUDIV@ F_LUMOD@ F_LXLSH@ F_LXMUL@ F_LXURSH@ _LOCK _UNLOCK
```

`F_L*` are Borland's 80-bit long arithmetic helpers and live in `CM.LIB` itself;
`lock`/`unlock` and the startup's `_stklen`/`_heapLen`/`_exit` can be supplied.
With that configuration the image no longer exits 3 — it **hangs** (RUN.LOG 0 bytes),
which superficially matches the original.  But the INT 21h markers in `main` still
print nothing, so it is a *startup* hang, not a reached config screen.

## Conclusion

Every configuration tried (TC++ and BC++ compilers, flat and overlay links, with and
without `CM.LIB`, with the recovered CRT and with the library CRT) fails in the same
place: **before `main`**, inside the compiler's startup/overlay runtime.  A tiny
overlay program built with the same toolchain works, so the runtime itself is sound;
what differs is our image's runtime data and object mix.

That is the boundary the user pointed at: the overlay manager is compiler machinery.
The remaining options are therefore not "more recovery" but either

  * reproducing the original's *link layout* exactly (the original's resident image is
    110 KB with ~400 KB of overlays — our split is 130 KB / 589 KB, and its overlay
    units are per-module, ours may not match what VROOMM expects), or
  * accepting a flat build and shrinking the image by ~100 KB, which the data tables
    alone cannot deliver.
