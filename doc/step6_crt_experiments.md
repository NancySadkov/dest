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

## 5. Bisecting the object mix (measured)

	mp/bisect_crt2.py links the tiny resident main against growing groups of our
objects, using an uppercase 8.3 response file (a long TLINK command line is
truncated by DOS: the first attempt failed with Unable to open file 'cm.li',
which is a *link* failure, not a program result).

`
XA  globs only                 run='KCODE9'      -> prints K, returns 9
XB  + CRTL/STUBS/INTRINS       LINKFAIL: Undefined symbol _INIT_TEXTFILENAME in CRTL.C
XC  + OVR.OBJ                  not linked (same reason)
`

So our five GLOB objects are harmless under VROOMM (confirmed again), but
CRTL.OBJ cannot be isolated: it needs swi() (st_stubs.c), ar_from_u32()
(st_intrinsics.c), init_textFilename (a game global) and, from the earlier
list, 29 more recovered names.  The CRT and the game tree are mutually
dependent, so the CRT cannot be added to a minimal control without dragging in
the tree - and the tree + tiny main is the known exit-2 case.

That leaves two honest options for step 6:

  A. give every recovered helper name its real definition (so CRTL.OBJ can be
     dropped in favour of CM.LIB), which is a type/library mapping job, or
  B. keep both CRTs and find the offending *runtime data* by bisecting inside
     the tree itself (the tree links, so this needs removals that still link).

Both are larger than a bisect; neither is overlay-manager re-engineering.

## 6. The CRT split, measured and planned

Linking the current tree without CRTL.OBJ leaves exactly 29 symbols.  Every
one of them is defined in crtl.c, so the split is mechanical (no reimplementation):

`
audio_done audio_init emsFree ems_init ems_memmove1 ems_memmove2 ems_realloc
f_scopy ioErrorHndlrInstall ioErrorHndlrUninstall rand8 srand8 stshInit_scan
xmsFree xms_init xms_usesXmsHandle xms_usesXmsHandle2
LDIV_at_ LMOD_at_ LUDIV_at_ LXLSH_at_ LXMUL_at_ LXRSH_at_ LXURSH_at_ PADD_at_
_atol _sprintf __fstrncpy _FakRealCvt
`

Their definitions in crtl.c (current line numbers):

`
audio_init 330   audio_done 344      xms_init 356     xmsFree 464
stshInit_scan 479  ems_init 500      emsFree 706      ems_realloc 723
ems_memmove1 653   ems_memmove2 680   rand8 737        srand8 765
ioErrorHndlrInstall 788             ioErrorHndlrUninstall 841
LXMUL_at_ 1041     F_SCOPY 1057      N_LDIV_at_ 1158  LDIV_at_ 1220
N_LUDIV_at_ 1288   LUDIV_at_ 1338   N_LMOD_at_ 1382  LMOD_at_ 1447
N_LXLSH_at_ 1567   LXLSH_at_ 1583   N_LXRSH_at_ 1602 LXRSH_at_ 1621
N_LXURSH_at_ 1641  LXURSH_at_ 1658  N_PADD_at_ 1677  PADD_at_ 1699
N_LXMUL_at_ 1959  _FakRealCvt 3054  _atol 4266       _sprintf 5165
__fstrncpy 5399
`

Note what these are: the EMS/XMS/audio/sound-driver helpers, the *8 random
generator and the I/O-error handler are *game* support code that the original
linked into its CRT segment (1000:026c ... 1000:07e7 in udit/functions.tsv),
not Borland runtime.  Only the long-math, _atol, _sprintf, _FakRealCvt
and __fstrncpy entries are genuine RTL, and CM.LIB provides equivalents
under its own names - which is why dropping CRTL.OBJ needs a name mapping for
those few (LDIV_at_ <> F_LDIV@, ...) and a real home for the game helpers.

Next step, in order:
  1. move the game helpers (lines above) into a resident module of their own;
  2. map the remaining RTL names onto CM.LIB;
  3. drop crtl.c from uild_skip/the link and re-measure the exit code.
