# Step 6: from "exit 3 before main" to "startx runs"

## Status correction (latest measurement)

The entry-point fix is real and repeatable: the rebuilt image now starts at
`startx`, runs the PSP/environment/memory setup, and no longer aborts in C0's
`_startup`.  What is **not** yet reproducible is `main` itself.

An instrumented build (distinct exit codes planted in `startx`, NOP-ed in the
image) reached the pre-`main` milestone and a marker inside `main` fired.  With
the same source but without those marker instructions the committed image exits
**115**, and re-running the milestone probe on later layouts changes the reported
stage (5, 121, 115).  The startup is therefore *register- and layout-dependent*,
and the "main entered" result must be treated as measured-once, not parity.

## Root cause of the instability: `swi()` is a no-op

`st_compat.h` declares `code *swi(int vector);`, and `src/decompiled/st_stubs.c`
implements it as a GUESS stub:

```c
static unsigned short st_swi_target(void) { return 0; }
code *swi(int vector) { (void)vector; return (code *)st_swi_target; }
```

Every recovered `pcVar3 = (code *)swi(0x21); (*pcVar3)();` therefore calls a
function that does nothing.  Verified in the built image: `swi` returns the far
pointer `0779:0084`, and that address is

```
7814 push bp / mov bp,sp / xor ax,ax / pop bp / retf
```

So in `startx` the DOS version call, the `INT 21h AH=4Ah` memory resize, the
DOS 4+ handle-count / UMB block and the `INT 1Ah` time call **never execute**.
Their "results" (and the carry-flag tests that decide whether `_abort` runs) are
whatever the registers happen to hold at that point, which is exactly why the
observed exit code changes with code layout.

This also applies to `SaveVectors`, `__restorezero` and `ErrorDisplay`, which
use the same idiom.

### Next step (concrete)

Rewrite the DOS calls in `startx` (and the three small routines above) from the
disassembly using `int86x` / `geninterrupt` with explicit `AH`, `BX`, `ES`,
instead of the `(*swi(n))()` idiom:

| original | call |
|---|---|
| `MOV AH,0x30 / INT 21h` | DOS version -> `DosVersion` |
| `MOV AH,0x4A / ES=psp / BX=paras` | resize memory block |
| `AX=0x5801, BX=2` / `AH=0x67` / `AH=0x48,BX=1` / `AH=0x49` / `AX=0x5801,BX=0` | UMB + handle count |
| `MOV AH,0, INT 1Ah` | system time -> `_StartTime`, BDA midnight flag |

Once those are real interrupts, the startup flow stops depending on leftover
registers and the milestone ladder can be re-measured reliably.

## Summary

The image used to exit with code 3 without ever reaching `main`.  The cause was
not the game code: **TLINK's entry point was Borland's `C0M.OBJ` startup
(`_startup`), not the program's own `startx`**, and that startup aborts with
`__exit(3)`.

`startx` (CRTL) is now the entry.  With it, the PSP/environment scan, the memory
resize and the rest of the startup sequence run, and the committed image exits
**115** instead of 3.  Whether that 115 is `main` returning or the startup
falling through is not settled - see "Status correction" above, and the
`swi()` finding that makes the flow register-dependent.

## How the entry was identified

The original image's first instruction at `CS:IP = 0000:0000` is

```
1000:0000  MOV DX,DGROUP
1000:0003  MOV word ptr CS:[0x260],DX     ; VROOMM startup, not C0.ASM
1000:0008  MOV AH,0x30 / INT 21h          ; DOS version
1000:000c  MOV BP,word ptr [2]            ; PSP: top of memory
1000:0010  MOV BX,word ptr [0x2c]         ; PSP: environment segment
```

Our recovered `startx` compiles to the same sequence, but it was placed in
`CRTL_SEG` (every module gets its own `#pragma codeseg`), while `C0M.OBJ`
occupied the front of `_TEXT`.  `scripts/link_standalone.py` now reads
`_STARTX` from `REBUILT.MAP` and writes it into the EXE header, so the rebuilt
image starts where the original does.

Dropping `C0M.OBJ` entirely was tried and does not link: `CM.LIB`'s
`EXIT`/`SETARGV`/`SETENVP` and `OVERLAY.LIB`'s `OVRMAN` reference the startup
data under C0's names (`__C0ARGC`, `__ENVLNG`, `__ENVSIZE`, `__OSMAJOR`,
`_ABORT`, `__CHECKNULL`, `__RESTOREZERO`, `__CLEANUP`), which our tree does not
define.  Keeping C0 for its symbols and moving the entry is the smaller,
verifiable change; removing C0 remains the cleaner end state.

## What runs now (measured)

Distinct `exit()` codes were planted in `startx` and read back with a batch that
reports the exact `errorlevel`:

| milestone | code (measured once, marker build) |
|---|---|
| entered `startx` | 4 |
| after `SaveVectors` (environment scan) | 5 / 10 |
| after the memory resize and BSS clear | 6 / 11 |
| after the DOS handle-count / UMB block | 6 / 11 |
| after the system-time call | 12 |
| after `_setupio()` | 13 |
| after `_c0crtinit()` | 14 |
| `main` entered | 66 (marker inside `main`) |

The ladder is not stable across layouts (5, 121 and 115 were observed for the
same stage after edits that only move code), because the `INT 21h` calls behind
those milestones are no-ops - see "Root cause" above.

## The one stage that had to be replaced

`startx` calls `StartExit` with `SI = InitStart`, `DI = InitEnd`.  `StartExit`
walks the **linker-generated init table** (`InitStart[4]` plus the `InitEnd`
record): `_setupio` (priority 2), `_c0crtinit` and `__setargv` (0x10), and one
far entry (priority 1, probably the overlay manager's).

Our recovered table is a *byte copy* of the original's entries, so its
addresses still point at the original image's offsets (`0D24:1403`, `0D36`,
`14D7`, `2032`).  Calling through it hangs.  Two of the three near entries map
one-to-one onto functions our tree has:

```
0x0D36 -> _setupio      0x14D7 -> _c0crtinit      0x2032 -> __setargv
```

`_setupio()` and `_c0crtinit()` are now called directly; they return cleanly and
`main` is reached.  `__setargv` is still skipped: it is a hand-written routine
that pops its own return address plus the `ES` word `StartExit` pushes, and its
stack contract has not been recovered yet.  The far priority-1 entry is not
identified.

### TODO

1. Recover `__setargv`'s entry contract (`pop [0x88fe]`, `pop [0x8900]`,
   `pop [0x8902]`, then the argument walk) and call it with `ES = DGROUP`.
2. Identify the far priority-1 initialiser (candidate: the VROOMM manager) and
   call it first.
3. Find where `main` exits with 115.  `main` has no `return` and no `exit()`, so
   the status comes from an overlay call or a corrupted return.

## Reference: what the original does under the harness

Run through the same batch, `game/STRONG.EXE` also leaves `RUN.LOG` empty (it is
interactive and waits).  An empty log therefore means "still running", not
"broken".  `tmp/run_original.py` (`tmp/runorig/`) produces that reference.

## Earlier isolation result (still valid)

`tmp/crt_iso.py` links a tiny `print K; return 7` main against
`CRTL.OBJ + STUBS.OBJ + INTRINS.OBJ + GLOB*.OBJ`, stubbing the two symbols the
CRT references (`_INIT_TEXTFILENAME`, `_OVR__FAKREALCVT`).  That image hangs
before `main`.  The `AB` variants in `tmp/ab_crt.py` show the same objects with
`CM.LIB`'s runtime plus link stubs printing `K` and returning 7.  The recovered
CRT is therefore implicated, but it is not the whole story: with the entry
point moved to `startx`, the same recovered CRT reaches `main`.
