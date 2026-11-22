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

### Done: the DOS calls in startx are real now

The four interactions in `startx` now follow the disassembly (explicit `AH`,
`BX`, `ES`) instead of the `(*swi(n))()` idiom:

| original | call |
|---|---|
| `MOV AH,0x30 / INT 21h` | DOS version -> `DosVersion` |
| `MOV AH,0x4A / ES=psp / BX=paras` | resize memory block |
| `AX=0x5801, BX=2` / `AH=0x67` / `AH=0x48,BX=1` / `AH=0x49` / `AX=0x5801,BX=0` | UMB + handle count |
| `MOV AH,0, INT 1Ah` | system time -> `_StartTime`, BDA midnight flag |

They are now issued through `int86`/`int86x` (with the minimal `union st_regs` /
`struct st_sregs` in `st_compat.h`, because `<dos.h>` conflicts with the recovered
prototypes).  The PSP reads were also wrong (`DGROUP:0x2c` / `DGROUP:2` instead of
`PSP:0x2c` / `PSP:2`), and the stack/heap setup used the original image's
segment constants (`0x2d5b`, `0xd2a6`) and switched `SS` to `DS`; it now follows the
disassembly (`DX = SS`, `SP = ((__stklen>>4)+1) << 4`, resize with `ES = PSP`).

Outcome: the image no longer exits 115; it **stays running** under the
harness, which is what the original does (it is interactive).  `main` entry
is still not independently confirmed for the committed layout - the marker
ladder has to be re-measured now that the interrupts really happen.

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

## Why the image still hangs: cross-segment calls are not relocated

`startx`'s first DOS call is compiled as a far call to the runtime's `int86`:

```
004c push 0x21
004e lcall 0, 0x523          ; _INT86, which the map places at 0000:0523
```

The segment word (image offset `base+0x51`) is **not** in the EXE relocation
table, so DOS never adds the load segment.  At run time the call goes to
absolute `0000:0523` - the interrupt vector table - and the program hangs.

Proof: adding that single relocation by hand (append `(offset, 0)` to the
relocation table, bump `e_crlc`) changes the behaviour immediately - the hang
becomes an `exit` with code 4.

### Cause

The link uses `-V` (VROOMM).  For calls that cross segments, TLINK emits
VROOMM fixups instead of DOS relocations; the overlay manager patches them at
startup.  Our startup never initialises the overlay manager - the original's
priority-1 init-table entry is `__OVRPREPARE` (`OVRUSER` in `_OVRTEXT_`), which
we replaced with direct calls to `_setupio`/`_c0crtinit`.  So every
cross-segment call in the image (library routines, overlay thunks, `main`) still
points at segment 0.

This also explains why earlier milestone ladders were layout-dependent: which
call happened to be reached first determined whether the stray jump landed in
code, in data, or in the IVT.

### Options (next step)

1. Link without `-V` so TLINK emits normal relocations.  Risk: the load image
   grows because overlays become resident.
2. Patch the resident segment words after linking: scan the code segments for
   `9A` (far call) whose operand word equals a segment start from the map and
   has no relocation, and append the relocation entry.  Mechanical, and the
   experiment above shows it works.
3. Initialise VROOMM: call `__OVRPREPARE` before anything else.  It has the
   same relocation problem, so this needs option 2 for at least that one call.

### Implemented: post-link relocation patch

`scripts/link_standalone.py` now calls `add_missing_relocations()` after TLINK
runs.  It reads the segment table from `REBUILT.MAP`, keeps the ranges of the
`CODE` segments, and scans the image for `9A` (far call) / `EA` (far jump)
instructions whose operand word is the paragraph of a code segment and whose
offset lies inside it.  When capstone is importable the byte offset must also be
a real instruction start (linear sweep per segment), which keeps data bytes out
of the set.  Every such word that has no relocation entry gets one appended, and
`e_crlc` is bumped.  When the spare gap between the relocation table and the
image is too small the header is grown by whole paragraphs.

Current result: **194 entries** added, and the image still links with 0 errors.

One pitfall found and fixed: `e_cp`/`e_cblp` describe the **resident load
image** (140,800 bytes here), not the file size - the tail of the file holds the
overlay segments.  Writing the file size into them made DOS refuse to load the
EXE (it printed an error and the batch saw exit code 0, which looked like a
successful run).

With the header fixed the image loads and runs (an entry-point `exit 7` probe
reports 7), but `startx` still hangs before the first milestone marker (right
after `SaveVectors`), so `main` is still not reached.  The next step is to
instrument `startx` again *with* the relocations in place, since the earlier
ladder was measured on unrelocated code.

Second absolute pointer found: \swi()\ returned \(code *)st_swi_target\ where the
target was a *near* static function, so BCC emitted \mov dx,0779 / mov ax,0084with the link-time segment as an immediate.  Every \pc = swi(n); (*pc)()\ then
called absolute 0779:0084.  \st_swi_target\ is now a \ar\ function (whose
address is relocated normally) and \swi()\ performs the interrupt itself, since
the callers only call the returned pointer to make the INT happen.

The image still hangs before the first milestone.  The next diagnostic is the
AH values: the decompiled call sites pass no register setup to \swi()\, so the
interrupt that now really executes may be doing something unintended.

## Done: startx now runs up to `_setupio`

Setting the registers at the `swi()` sites (as the original disassembly shows)
plus three bugs found on the way moved the startup past the environment scan,
the memory resize, the UMB block and the system-time call.  The milestone ladder
(exit-code markers, NOP-ed in the image) now reads:

```
0x30 after the DOS version      fires
0x31 inside SaveVectors         fires  (after the four AH=35h calls)
0x0A after SaveVectors          fires
0x32/0x33/0x34 stack block      fire
0x0C before _setupio            fires
0x0D after _setupio             does not fire  <- next blocker
```

What was fixed, and why:

* **`DS` was never set to DGROUP.**  DOS enters with `DS = ES = PSP`, and the
  original startup does `MOV DX,DGROUP / MOV DS,DX` before touching anything.
  Our version wrote every global through `DS` = PSP - the PSP was being
  overwritten at offset 0x90 and every recovered global read garbage.  One
  inline `mov ax, seg DosVersion / mov ds, ax` fixes it.
* **CM.LIB's `int86`/`int86x` hang in this link.**  They are far calls into a
  VROOMM-encoded segment and never return here (`crtl.c` now issues the
  interrupts directly).  This was also what made the ladder stop at SaveVectors.
* **`SaveVectors` / `__restorezero` / `ErrorDisplay`** are rewritten from the
  disassembly: `AH=35h` for vectors 0,4,5,6 into `GSTARTX_SavedVectors`, vector 0
  := `CS:ZeroDivision` via `AH=25h`; the restore does `LDS DX,saved` + `AH=25h`;
  the error display is `AH=40h, BX=2`.
* **The UMB block and `INT 1Ah`** now set `AX/BX/ES` explicitly and capture the
  carry with `mov ax,0 / adc ax,0` into a local; the midnight flag is written to
  `0040:0070` as the original does instead of to a DGROUP byte.
* **The SS:SP switch is deferred.**  After `mov ss,dx; mov sp,di` every
  BP-relative local in the C function resolves in the new stack segment, so the
  code after the switch read the wrong frame.  The DOS stack is still inside the
  block that was just resized, so the switch can wait until `startx` is rewritten
  as a naked assembly routine.

Next blocker: `_setupio()` calls `_isatty()` and `setvbuf()` from CM.LIB - the
same class of far call that made `int86` hang - so it never returns.

## Done: `_setupio()` returns; `_c0crtinit` is the next stop

Two things kept `_setupio` from returning:

* `_isatty` was recovered as `swi(0x21); return extraout_DX & 0x80` - a bare
  interrupt with garbage `AX/BX`.  It is now `INT 21h AX=4400h, BX=fd` with the
  carry captured, and takes the fd the disassembly passes (`_isatty(0)`,
  `_isatty(1)` in `_setupio`).
* `setvbuf` (recovered at 1000:2b24) calls `malloc`, `fseek` and `farfree` -
  the same unrelocated far-call class - and `_setupio` was calling it with three
  arguments while the recovered body reads a fourth (the size at
  `in_stack_0000000e`).  Both calls in `_setupio` are skipped for now: the
  streams keep the DGROUP-initialised unbuffered state (`buffer = &hold`,
  `bsize = 0`), which is functionally equivalent, only slower.

Ladder after the change:

```
0x0C before _setupio   fires
0x0D after _setupio    fires      <- _setupio returns
0x0E after _c0crtinit  does not   <- next blocker
```

`_c0crtinit` (1000:14d7) is `INT 10h AH=0Fh` -> `__crtinit` -> `INT 10h AH=08h`
through `_VideoInt`, whose recovered body issues nine `swi(0x10)` calls with no
register setup.  That is the next set of call sites to give registers to.

## Done: _c0crtinit returns; the call to main is the next stop

`_VideoInt` (1000:1453) is a register-convention wrapper: the caller puts AH
(function) and AL (argument) in AX.  The recovered C read an uninitialised
`in_AX` and issued `swi(0x10)` with whatever registers happened to hold.  It now
takes `uint16_t axval`, does `mov ax,axval; int 10h`, and returns AX through a
scratch word (BCC will not resolve a local variable inside an inline `asm`
block, so the result is stored in the file-scope `videoIntResult`).

The callers were fixed with it, from the disassembly:

* `_c0crtinit`: `_VideoInt(0x0f00)` -> `__crtinit(AL)` -> `_VideoInt(0x0800)`,
  with `normattr`/`attribute` taken from AH.
* `egainstalled`: `_VideoInt(0x1200)` (AH=12h, BL=10h) then `AL + 0xF0`.
* `__crtinit`: the mode query/compare part was decompiled with the wrong
  operands (`if (videoMode != _video.currmode)` could never be true); it now
  compares the BIOS mode in AL with the requested mode and re-reads AX after a
  mode set.
* `clrscr`, `moveto` and `bios` still pass `0x0200` (set cursor) because their
  DX/BX operands are not modelled yet - they are outside the startup path.

Ladder:

```
0x0C before _setupio   fires
0x0D after _setupio    fires
0x0E after _c0crtinit  fires    <- _c0crtinit returns
main marker (0x42)     does not <- next stop: the call to main
```

## Blocked on the transfer into `main`

The argument vector is solved: a minimal DGROUP argv (`arg0 = "STRONG.EXE"`,
`arg0` far pointer, terminator) assigned to `__C0argc/__C0argv/__C0environ`
before the call makes the marker placed immediately before `main(...)` fire
(`walk {0x0A,0x0C,0x0D,0x0E} -> CODE=32`).  So everything up to the call works,
including the argv setup.

What does not work is the transfer itself:

* the call is `9A 05 00 44 06` = `lcall 0x644:0005`;
* `MAIN_SEG` starts at image offset 0x6445 (frame 0x644), so `0x644:5` is
  exactly `main`'s entry, and the disassembly there is `push bp / mov bp,sp /
  sub sp,8 / push si / push di / <marker>`;
* the segment word at image offset 0x91F **is** in the relocation table
  (`relocated True`), so the DOS loader does add the load segment;
* nevertheless, patching `main`'s first five bytes with `mov ax,4c21; int 21h`
  and NOP-ing every earlier marker still hangs - the caller never arrives.

So TLINK encoded this particular cross-segment call in the VROOMM form (the
`-V` overlay mechanism rewrites calls into overlay-capable segments at startup),
and the plain DOS relocation we add is not sufficient for it.  All the other
cross-segment calls that now work (`_TEXT`, `STUBS_SEG`, `_OVRTEXT_`) are
resident-to-resident; this one targets a segment TLINK treats as overlay-capable
under `-V`.

Options for the next session:

1. Initialise VROOMM (`__OVRPREPARE`, `OVRUSER` in `_OVRTEXT_`) before `main` so
   the manager patches the call.  It is itself a cross-segment far call, so it
   needs the same treatment - but a first call can be hand-patched in the image.
2. Force `MAIN_SEG` out of the overlay-capable set (e.g. link main.c without
   `#pragma codeseg` so it lands in `_TEXT`, which is known to work).
3. Call `main` through a far function pointer built at runtime from the map's
   segment/offset, bypassing the linker's call encoding.

The rest of the ladder is green: `startx` -> DOS version -> `SaveVectors` ->
environment scan -> resize -> UMB block -> `INT 1Ah` -> `_setupio` ->
`_c0crtinit` -> argv -> the `main` call.

## Tried: main in `_TEXT` instead of its own code segment

`scripts/stage_build.py` gained `NO_CODESEG_MODULES` (comma-separated module
names) which stages those modules with `#pragma codeseg _TEXT` instead of
`<MOD>_SEG`.  With `NO_CODESEG_MODULES=main.c` the map moves `_MAIN` from
`0644:0005` to `0000:0297`, and the call becomes `lcall 0:0x297` with the
segment word relocated - i.e. exactly the resident-to-resident form that works
elsewhere.

It did not help.  The ladder still stops the same way:

* marker 0x20 (immediately before `main(...)`) fires;
* replacing the `lcall` instruction itself at image 0x10A3 with
  `mov ax,4c21; int 21h`, with every earlier marker NOP-ed, still hangs;
* patching `main`'s entry (image 0x297) to `mov ax,4c21; int 21h` also hangs.

So execution does not reach the call site at all, despite the marker 0x20 eleven
bytes earlier firing.  That contradicts the static picture and means blind
rebuilds are no longer productive: the next step needs a real trace (DOSBox
breakpoints on the marker address and on the call site, or a small TSR logger),
not another layout experiment.

## Bisected the last four instructions before `main`

No debugger needed: with the marker immediately before `main(...)` in place, the
binary was patched one instruction at a time so that an `exit` sits exactly where
that instruction starts.

```
marker+05  push word ptr [0x9d1]  -> CODE=49   reached
marker+09  push word ptr [0x9cd]  -> CODE=50   reached
marker+13  push word ptr [0x9cb]  -> CODE=51   reached
marker+17  lcall 0:main           -> hang      never reached
```

So the three argument pushes execute, and the hang is at the third push / the
`lcall` boundary.  Replacing the `lcall` with `int 20h` (which needs no stack)
also hangs, so the instruction after the third push is never executed.

The obvious suspect was the stack: the EXE header sets `SS=0x2131, SP=0x0080`,
i.e. 128 bytes, and the startup had been running all initialisers on it because
the `SS:SP` switch had been deferred.  The switch is restored (it is a no-op for
`SS`, since the original loads `DX` from `SS`; only `SP` moves to
`((__stklen>>4)+1)*16`, above the current frame, so BP-relative locals stay
valid).  The ladder still stops at the same place, so the stack size was not the
cause.

Also kept from this round: the minimal DGROUP argv (`arg0 = "STRONG.EXE"` plus a
terminator) assigned to `__C0argc/__C0argv/__C0environ`, which makes the
pre-`main` marker fire with a real vector.
