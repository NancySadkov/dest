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

### Byte-level check of the pre-`main` sequence

Raw bytes from the marker build:

```
0x953  b8 20 4c cd 21        mov ax,4c20 / int 21h      (marker)
0x958  ff 36 dd 09           push word ptr [0x9dd]
0x95c  ff 36 d9 09           push word ptr [0x9d9]
0x960  ff 36 d7 09           push word ptr [0x9d7]
0x964  9a 0d 00 48 06        lcall 0x648:0x000d
0x969  83 c4 06              add sp,6
```

So the offsets used by the bisection were exact (5/9/13/17).  The `lcall`
segment word at 0x967 is in the relocation table with frame 0, and
`0x648:0x000d` is image 0x648d, which is `main`'s prologue
(`55 8B EC 83 EC 08 56 57`).

Stack check: an exit patched over the marker as `mov ax,sp / mov ah,4Ch /
int 21h` returns exit code 16, i.e. `SP & 0xFF = 0x10`, so `SP = 0x1410` - exactly
the top of the resized block.  The stack is correct.

Forcing `mov sp,0x100` over the third push and putting the exit at the `lcall`
still hangs, and `int 20h` there does not terminate either.  So the failure is
not the offset, not the stack, not the target address and not the relocation:
the bytes at 0x960..0x964 do not execute as they are decoded from the file.
Only the loader can rewrite them (relocation processing) or the overlay
manager - and the next entry point we now know is a VROOMM fixup at 0x96F with
frame 108, which DOS relocates too.

This needs a single-step trace; further static reasoning has been exhausted.

## SOLVED: `main` is entered - call it through a far pointer

The direct `lcall` to `main` never landed, but the same call through a far
function pointer does:

```c
int (far *pmain)(int, str_t *, str_t *);
pmain = main;
iVar10 = (*pmain)(__C0argc, (str_t *)__C0argv, (str_t *)__C0environ);
```

A marker as the first statement of `main` now fires (exit code 66), i.e. the
recovered program reaches its entry point.  With the marker removed the image
keeps running under the harness (empty RUN.LOG), exactly as the original
`STRONG.EXE` does - it is an interactive program, so "no exit" is the expected
state, not a failure.

Why the indirect form works is consistent with the VROOMM theory: the linker
encodes a *direct* cross-segment call as an overlay-fixup form that only the
overlay manager can resolve, while a far pointer to the function is emitted as
an ordinary relocated pointer and `lcall [mem]` needs no linker fixup.

The static ladder is now complete end to end:

```
startx -> DOS version -> SaveVectors -> environment scan -> memory resize ->
UMB block -> INT 1Ah -> _setupio -> _c0crtinit -> argv -> main  (entered)
```

## Root cause of the `main`-body stall: the overlay thunks are `INT 3Fh` stubs

Tracing `main`'s first call showed it enters `ovr_init_game` and never returns.
Disassembling the built image explains both halves:

```
main:            image 0x653f   lcall 06DE:0203          ; _OVR_INIT_GAME
thunk 06DE:0203: image 0x6fe3   EA 48 00 B0 14           ; ljmp 14B0:0048
target 14B0:0048                 -> O09_SEG
O09_SEG bytes:   CD 3F 28 01 00  CD 3F 5F 01 00  ...     ; INT 3Fh, <id>, <ofs>
```

`INT 3Fh` is the VROOMM supervisor call.  The overlay segments are stubs that ask
the overlay manager to load the real code; without the manager the interrupt has
no handler and the program stops there.

Two defects were found on the way:

1. **The thunk segment word was not relocated.**  `add_missing_relocations()`
   only accepted target segments whose map class is `CODE`, but overlay targets
   are class `STUBSEG` (`O01_SEG`, `O09_SEG`, ...), so `EA`/`9A` instructions
   pointing at them were skipped and the jump went to absolute `14B0:0048`.
   The scan now accepts `STUBSEG` too; relocation entries went from 1006 to
   1464 and the thunk's segment word at image `0x6FE6` is now relocated.
2. **VROOMM is never initialised.**  With the relocation in place the jump
   reaches `O09_SEG`, which is exactly when `INT 3Fh` needs the manager.  The
   original's priority-1 init-table entry is module `OVRUSER`
   (`07BF:0D29`, size `5B`, module `M=OVRUSER` in `REBUILT.MAP`).  Our `startx`
   calls `_setupio`/`_c0crtinit` directly and never runs that entry.

Calling `__OVRINIT()` from `startx` does not link (`Undefined symbol
___OVRINIT in module CRTL.C`), so the OVRUSER prepare entry has to be reached by
address - it is resident at `07BF:0D29` and the call needs the usual
cross-segment relocation.

### Tried: calling the OVRUSER prepare entry from `startx`

The prepare entry was added before the `main` call as a relocated far pointer
built from the PSP:

```c
uint16_t ovrSeg = (uint16_t)(_psp + 0x10 + 0x7BF);   /* _OVRTEXT_ at 07BF */
((void (far *)(void))MK_FP(ovrSeg, 0x0D29))();        /* OVRUSER entry */
```

Built and linked cleanly, but the program still stops before `init_game`:
`OUT.BIN` stays 0 bytes (with the trace markers back in) and no `STRONG.SAV`
appears.

So either the entry address is not the callable prepare routine (the map line
`07BF:0D29 005B ... M=OVRUSER` is the *module* entry, not necessarily its public
prepare symbol), or the routine needs state that is only set up later in the
original (the overlay file handle opened by the earlier init entries), or the
call cannot be made this late in `startx` (after the memory resize and stack
switch).

The change was reverted; the tree is back at the verified state.  The next probe
should read the original's init-table walk (`InitStart..InitEnd`) to get the
exact priority-1 entry address and its calling convention, instead of assuming
the module entry.

### The init table is stale data, not a symbol reference

Dumping the table bytes settles what the walk would call.  Our
`_INITSTART` (DGROUP offset `8590`) holds exactly the same 24 bytes as the
original image (`audit/dgroup_2410.bin` at `8916`):

```
01 01 24 0d 03 14   entry 0: done=1 prio=1  ofs=0D24 seg=1403
00 02 36 0d 00 00   entry 1: done=0 prio=2  ofs=0D36 seg=0000  (_setupio)
00 10 d7 14 00 00   entry 2: done=0 prio=16 ofs=14D7 seg=0000  (_c0crtinit)
00 10 32 20 00 00   entry 3: done=0 prio=16 ofs=2032 seg=0000  (__setargv)
```

So the layout is: mark at `+0` (0 = pending, 0xFF = done), priority at `+1`,
far pointer offset at `+2`, segment at `+4` (segment 0 = near call).

The table was reproduced **byte for byte from the original**, so its pointers
are the *original's* link-time values:

* entry 0 points at `1403:0D24`, which in our link is a VROOMM stub
  (`CD 3F ...` at image `0x14D54`), not the prepare routine;
* the near entries point at the original's CRTL offsets (`0D36`, `14D7`,
  `2032`), which happen to coincide with our own `_setupio`/`_c0crtinit`/
  `__setargv` only because we call those by symbol instead of through the table.

The routine entry 0 wants is at offset `0D24` of `_OVRTEXT_` - exactly 5 bytes
before the OVRUSER module header the map lists at `07BF:0D29`.  Calling
`(_psp + 0x10 + 0x7BF):0D24` from `startx` builds and links, but the program
still produces a 0-byte `OUT.BIN` and no `STRONG.SAV`, so the prepare entry
needs something we do not supply yet (most likely the overlay file handle opened
by the manager's own entry point, or a different register/argument walk).

Reverted; tree at the verified state.

**Consequence for the plan:** the init table cannot be *walked* as-is in our
build - every pointer in it is a stale original address.  It must either be
regenerated from our own symbols, or each entry patched at startup the way
`fixFarTable` already patches the far-pointer tables.

### Why the prepare entry cannot bootstrap in our link

Disassembling `_OVRTEXT_:0D24` (the routine the priority-1 table entry wants)
shows why calling it does nothing useful:

```
0d24  push ds / push si / push di
0d27  mov ax,0x13F9        ; _OVRDATA_   <-- immediate segment
0d2a  mov ds,ax
0d2c  call 0x0298          ; __INITMODULES
0d2f  mov bx,[0x11a]
0d33  mov ax,0x163A        ; DGROUP      <-- immediate segment
0d36  mov ds,ax
0d38  mov ax,0x163A
0d3b  mov es,ax
0d3d  cmp bx,es:[0xB006]
0d4f  mov ax,0x10 / mul bx
0d56  lcall 0x06C:0x37A9   ; into _TEXT
```

Every segment in this routine is a **`mov ax,imm16` immediate**.  In a VROOMM
image those immediates are not DOS relocations: the overlay manager patches them
from its fixup table when it loads the module.  Our `add_missing_relocations()`
only handles `9A`/`EA` operands, so these stay at their link-time values and the
routine addresses absolute `13F9`/`163A` instead of the loaded segments - the
same root cause as the unrelocated overlay thunk found earlier.

So the bootstrap is circular in this link:

```
to run an overlay  -> need the manager
to have the manager -> must run _OVRTEXT_:0D24
to run _OVRTEXT_:0D24 correctly -> needs its immediates patched by the manager
```

That is inherent to OVERLAY.LIB, not a missing call.  Two ways out:

1. **Link without `-V`.**  TLINK then emits ordinary relocations for every
   far call and the segments become resident; no manager, no `INT 3Fh`, no
   fixup table.  The code is already split into segments with classes, so a
   large-model link without overlays is legal; what is lost is the 64 KB
   swapping (irrelevant for a rebuild that must only be functionally
   equivalent).
2. Implement VROOMM's fixup application by hand: apply the `_EXEINFO_` /
   `_OVRDATA_` fixup records to the resident image at startup.  That is a
   sizeable routine and is exactly what the manager already does.

Option 1 is the cheaper experiment and the one that would finally let
`init_game` run, the second runtime checkpoint exist, and step 6 be testable at
all.

### Tried: the non-overlay link (`NO_OVERLAY=1`)

`scripts/link_standalone.py` now accepts `NO_OVERLAY=1`, which drops `/o` and
`OVERLAY.LIB` from the TLINK response file and leaves every module resident.
`st_stubs.c` gained `_OVRINITEMS`/`_OVRINITEXT` no-ops (the C names that produce
the linker's `__OVRINITEMS`/`__OVRINITEXT`) so the link is complete.

What the experiment showed:

* the link is **clean** - 0 errors, 0 undefined symbols;
* TLINK emits every relocation itself: `add_missing_relocations()` reports
  **0** additions, versus 166-1464 with `-V`.  This confirms the earlier
  diagnosis that the VROOMM link omits the relocations;
* the resulting image no longer hangs: the batch runs to completion and creates
  `DONE.FLG`;
* but `main` is still not reached - patching `_MAIN`'s entry with
  `mov ax,4C42h; int 21h` yields `CODE=0`, so the program exits before it.

So the non-overlay link removes the VROOMM obstacle but the startup path itself
does not survive the change: `startx` was written against the overlay image and
returns to DOS before calling `main`.  That is the next thing to fix if this
route is taken (the entry is `_STARTX 0069:002B` in this link, versus
`006C:0030` with overlays).

The switch is kept (default link unchanged, still 0 errors, 1,630/0/0 state) so
the experiment can be resumed deliberately rather than re-derived.

### NO_OVERLAY trace: the entry point does not reach startx

`AH=40h` markers were placed at the first statement after the `DS=DGROUP` setup
and after `SaveVectors`, before `_setupio`, after `_c0crtinit` and before the
`main` call (`tmp/trace_startx.py`).  In the `NO_OVERLAY=1` build:

```
OUT.BIN 0 bytes        (not even the first marker)
DONE.FLG present       (the program exits, code 0)
entry _STARTX 0069:002B
```

So in the non-overlay link the program terminates **before** the `DS=DGROUP`
assignment, i.e. the computed entry does not run `startx` at all.  With the
overlay link the same image reaches `main`'s entry (the DGROUP dump works), so
the difference is the entry/startup mapping in the non-overlay link, not the
trace channel.

Likely cause: `link_standalone.py` patches the EXE header's CS:IP from the map
symbol `_STARTX`, and in the non-overlay link the map's segment numbering no
longer matches the file layout the way the overlay link did (the overlay link
carries a fixed resident segment table; the non-overlay link renumbers
everything).  The entry then lands in unrelated code that returns to DOS.

Next probe for this route: verify the patched CS:IP points at the bytes of
`startx`'s prologue in the non-overlay image (compare the first bytes with the
map offset); if not, derive the load-relative offset from `e_cparhdr` plus the
map's segment start rather than from the segment value alone.

### The NO_OVERLAY entry points at startx, yet nothing executes

Header and image check for the `NO_OVERLAY=1` link:

```
e_cparhdr  2944  (0xB80)            header 47,104 bytes
e_lfarlc   0x3E   e_crlc 11,412     relocation table ends at 0xB28E
CS:IP      0069:002B                file offset 0xBEBB
bytes at 0xBEBB: 55 8B EC 83 EC 1C 56 57 B8 94 00   ; startx's prologue
map _STARTX: 0069:002B, segment base 0x696, same bytes at that offset
```

So the entry mapping is **correct**: `CS:IP` lands on `push bp / mov bp,sp /
sub sp,1Ch / push si / push di / mov ax,94h ...`.

Nevertheless:

* patching those five bytes with `mov ax,4C42h; int 21h` still yields `CODE=0`;
* none of the `AH=40h` startx markers (`S` after `DS=DGROUP`, `A` after
  `SaveVectors`, `B` before `_setupio`, `C` after `_c0crtinit`, `D` before the
  `main` call) writes a byte.

So execution never reaches the entry even though the header says it should.  The
one structural difference from the working overlay link is the **11,412-entry
relocation table with a 47 KB header**: DOS spends that pass before jumping to
`CS:IP`, and both the silent `CODE=0` and the absence of any marker are
consistent with the load failing (program too big to fit / relocation error) or
with the relocation pass corrupting the entry bytes.

Next probes, in order of cost:

1. run the same EXE without the batch redirection and read what DOS prints
   (`Program too big to fit in memory` would settle it);
2. if it is a size failure, link with a smaller subset (the link already supports
   `EXCLUDE_OBJS=`, and `--without-crtl`), or raise DOSBox's `memsize` and free
   conventional memory (the harness currently uses 16 MB with a 714 KB image and
   a 5 MB data file, which should fit, so a *relocation* error is more likely
   than memory);
3. re-check `e_lfarlc`/`e_crlc` against the relocation entries: a bad entry that
   points into the code would rewrite the prologue after the patch is written.

### The map entry for `_STARTX` does not match the image in the NO_OVERLAY link

My earlier "the entry points at startx" check was wrong: it compared the header
`CS:IP` against a *segment table* base that was itself derived from the same
(possibly stale) map.  Comparing against the actual bytes instead:

```
startx prologue (55 8B EC 83 EC 1C 56 57 B8 94 00) is at image 0x06F0
header CS:IP 0069:002B  -> image 0x06BB        (+0x35, unrelated code)
map _STARTX  0069:002B  -> image 0x06BB        (same wrong value)
```

So in the `NO_OVERLAY` link the map's `_STARTX` does not point at `startx`, and
the patched entry lands 0x35 bytes before it - which explains the silent
`CODE=0` and the missing markers far better than a load failure (no DOS error
text appeared in the redirected output either).

Two things to fix before this route can be traced:

1. `REBUILT.MAP` contains the whole symbol list **twice** (`_STARTX` and
   `_STARTXDSEG` each appear twice), so any lookup must take the last matching
   entry, and the value must be cross-checked against the image bytes;
2. the map's segment values do not correspond to the image paragraphs the way
   the overlay link's did (overlay: `_TEXT` 0..0x7A7, `CRTL_SEG` at paragraph
   0x7A, map `_STARTX 007A:0007` - consistent; non-overlay: `CRTL_SEG` starts at
   image 0x6CB but the map says segment 0x0069), so the entry offset has to be
   derived from the image (find the prologue) rather than from the map alone.

Doing that by hand: the prologue is at image 0x06F0, i.e. `CRTL_SEG + 0x25`;
patching `CS:IP` to `06CB:0025` and putting `exit 42` at 0x06F0 is the next
experiment - the previous attempt aborted on a bad offset computation and the
image was left untouched.

### The non-overlay link cannot load: the image exceeds conventional memory

The entry probe was redone against the current build.  The prologue really is at
image `0x06BB`, which is exactly where the map's `_STARTX 0069:002B` points
(`0x69*16 + 0x2B = 0x6BB`), so the entry mapping is correct after all - my
earlier 0x06F0 measurement came from a different (instrumented) build.

Patching `55 8B EC ...` at `0x06BB` with `mov ax,4C42h; int 21h` still yields
`CODE=0`, and no marker executes.  The reason is the image size:

```
load image (e_cp/e_cblp) = 761,576 bytes = 744 KiB
conventional memory      = 640 KiB = 655,360 bytes
exceeds by                106,216 bytes
```

With every module resident the program is 744 KiB, which DOS cannot load into
640 KiB of conventional memory.  The load fails before the first instruction -
which is exactly the silent `CODE=0` with no DOS text captured.

The original is 511 KiB *because* most of it lives in overlays (resident image
~128 KiB).  So **the non-overlay route is not viable for this program**: overlays
are mandatory, and with them the VROOMM manager (or an equivalent loader) must
work.

That leaves the earlier fork:

1. implement VROOMM's fixup application by hand (apply `_EXEINFO_` fixup records
   to the resident image at startup), or
2. write a minimal overlay loader that reads the overlay blocks from the EXE on
   demand and patches the `INT 3Fh` stubs - essentially the same work.

Option 1 is bounded: the fixup records are already extracted in
`doc/fbov_fixups.csv` (515 KB, produced for the FBO view), so the data needed to
apply them at run time is available.

### Overlay loader: the table is now extracted

`scripts/overlay_blocks.py` derives, from `REBUILT.MAP`, what an overlay loader
needs for *our* link.  It finds **100 blocks** (a `STUBSEG` stub block and an
`:OVY` code block for each of O01..O50) totalling **597,720 bytes**:

```
O01  13D8  file 0x13D8B    332 bytes  STUBSEG
O01  2282  file 0x22827   5512 bytes  :OVY
O02  13E4  file 0x13E42    147 bytes  STUBSEG
O02  25F5  file 0x25F5E  14031 bytes  :OVY
...
O09  2DF3  file 0x2DF3..  16268 bytes  :OVY
```

The table is written to `audit/overlay_blocks.csv`.

Two facts that shape the loader:

* the `STUBSEG` blocks sit **inside the resident image** (offsets around
  `0x13D8B`, resident load image is `0x22600`), so the `INT 3Fh` stubs are always
  present;
* the `:OVY` blocks hold the real code and start beyond the resident image, so
  they must be read from the EXE on demand.

Stub encoding, from `O09_SEG`: `CD 3F <id> <ofs_lo> <ofs_hi>` - e.g.
`CD 3F 28 01 00` = overlay id `0x28`, entry offset `0x0001`.

So a minimal loader is:

1. install an `INT 3Fh` handler at startup;
2. on entry, read `id` and `ofs` from the stub at `CS:IP` (the interrupt returns
   with `CS:IP` pointing after `CD`), find the `:OVY` block for that id in
   `audit/overlay_blocks.csv`, read it from the EXE into its segment (open the
   EXE via the PSP command tail), apply that block's relocations, mark it
   loaded;
3. far-jump to `block_segment:ofs`.

The relocation data per block is in our own EXE's TLINK block headers (the
`fixupsz` field that `doc/fbov_overlays.csv` shows for the original); for our
link they follow each block's code in the file and can be read the same way, or
recomputed from `audit/overlay_blocks.csv` plus the link map.

This is a bounded piece of work (a handler plus a block cache), and it is the
only path to a runnable rebuild now that the non-overlay link is ruled out by
size.

### Probe: an installed INT 3Fh handler never fires

Before writing the block loader, a cheaper check: install an `INT 3Fh` handler in
`startx` (AH=25h, vector 3Fh) that writes `H` to stdout and exits with 0x3F, then
run the default overlay link.

Result: build clean, entry `_STARTX 006C:004C`, but `OUT.BIN` stays 0 bytes - the
handler never runs.  So the program does not reach its first overlay call
(`ovr_init_game`) at all.

That is consistent with the earlier startx trace (no `S`/`A`/`B`/`C`/`D` marker
either) and conflicts with the working main-entry dump only if one assumes the
program gets that far.  The resolution is that the main-entry dump works because
it *replaces* main's first bytes, whereas the real run stops somewhere in
`startx` before main's body.

So the next probe is a bisect of `startx` with **exit codes** (not markers, which
have failed twice for reasons that are themselves unexplained): patch the image
so that an `exit` sits at each phase boundary of `startx` - after `DS=DGROUP`,
after `SaveVectors`, after the environment scan, after the memory resize, after
the UMB block, after `INT 1Ah`, after `_setupio`, after `_c0crtinit`, at the
`main` call - and run the sequence, recording which exit code first appears.  The
`walk.py` harness already does exactly that for embedded `mov ax,4cXXh; int 21h`
markers, so the same pattern applies.

The INT 3Fh handler can then be reinstalled once `startx` is known to complete;
the block loader itself is unchanged in design (`audit/overlay_blocks.csv`,
`CD 3F <id> <ofs>`).

### The startx ladder is green: startx completes and main is called

Exit-code markers were placed in `startx` after `DS=DGROUP` (0x30), after
`SaveVectors` (0x31), after `_setupio` (0x36), after `_c0crtinit` (0x37) and at
the `main` call (0x38), then nop-ed progressively:

```
nop 30                         -> CODE=49 (0x31)   SaveVectors reached
nop 30,31                      -> CODE=54 (0x36)   _setupio reached
nop 30,31,36                   -> CODE=55 (0x37)   _c0crtinit reached
nop 30,31,36,37                -> CODE=56 (0x38)   the main call reached
nop 30,31,36,37,38             -> (no exit - runs)
```

So the whole startup chain works: DOS version, `SaveVectors`, the environment
scan, the memory resize, the UMB block, `INT 1Ah`, `_setupio` and `_c0crtinit`
all complete, and `main` is called.  With every marker removed the program keeps
running (it is interactive), which is the correct behaviour.

**This corrects the earlier reading.**  The program does *not* stop inside
`startx`; the earlier "startx markers never appear" result was a marker-channel
artefact (the `AH=40h` writes), not a real stop.  The only remaining blocker is
the overlay manager: `main` calls `ovr_init_game`, whose thunk jumps into an
overlay segment containing `INT 3Fh` stubs, and nothing services that interrupt.

The earlier INT 3Fh probe (handler installed, never fired) needs to be re-checked
in the light of this: with `main` reached, the interrupt *should* fire, so that
probe's handler installation (AH=25h with a temporary DS) was probably the
problem, not the absence of the call.

Next: re-install the INT 3Fh handler using the same simple pattern as the ladder
(an `asm` block with `mov ax,0x253f / mov dx,offset handler / mov ds,cs`-style
addressing verified by disassembly), confirm it fires, then implement the block
loader from `audit/overlay_blocks.csv`.

### The INT 3Fh probes were invalid: the handler address resolves to 0x30

Re-installed the handler by writing the IVT directly (`0x3F*4 = 0xFC`):

```
cli / xor ax,ax / mov es,ax
mov word ptr es:[0xfc], offset int3f_probe
mov word ptr es:[0xfe], cs
sti
```

Disassembling the built image shows what was actually installed:

```
001c  mov word ptr es:[0xfc], 0x30        <- not the handler
0023  mov word ptr es:[0xfe], cs
```

The same 0x30 appears when the address is taken in C
(`uint16_t hofs = (uint16_t)int3f_probe;`), so it is not an inline-asm quirk:
`int3f_probe` resolves to offset 0x30 in a segment that is not the CRTL_SEG
`cs` used at install time.  The vector therefore pointed into `startx` itself,
which explains why the handler never fired in either probe.

So the overlay stub path is **still unverified** - not disproved.  The next
attempt must place the handler where its address is known:

* simplest: write the handler as a few bytes at a fixed place in `startx`'s own
  segment and install the address of that label, verifying the vector contents
  by disassembly before running;
* or use a `void interrupt` function and let BCC emit the prologue, but still
  check the installed offset against `REBUILT.MAP` in the same build.

Once the vector is right, the block loader follows the design already recorded
(`audit/overlay_blocks.csv`, stub `CD 3F <id> <ofs>`).

### The handler vector is now correct - and still never fires

The earlier 0x30 was not a wrong address: it was `_STARTX`'s offset, because the
`static` handler was eliminated and the reference fell through to the next
symbol.  Making the handler non-static fixes that, and the map confirms it:

```
006C:0030  _ST_INT3F_PROBE
006C:004C  _STARTX
```

with the install emitting exactly `mov word ptr es:[0xfc],0x30` /
`mov word ptr es:[0xfe],cs`.  So the `INT 3Fh` vector is now the handler, in the
same segment (`CRTL_SEG`), at a verified offset.

It still does not fire: `OUT.BIN` stays 0 bytes.

That means `main` does not reach `ovr_init_game`'s overlay call in the real run,
even though the exit-code ladder reaches the `pmain = main;` site and a marker at
`main`'s first statement has fired in earlier builds.  The remaining suspects,
in order:

1. the `ovr_init_game` thunk in the built image does not jump to `O09_SEG` at run
   time - its segment word is relocated (image `0x6FE6`) but the *load* base it
   receives may differ from the segment the overlay block expects;
2. `main`'s body stops before the call (e.g. in the `envp` dereference, which
   uses our two-byte `env0`).

Both are cheap to separate: put an exit-code marker immediately before
`ovr_init_game();` in `main` and rerun the ladder - if that code appears, the
call is reached and suspect 1 is confirmed.

### main reaches `ovr_init_game`; the hang is inside the thunk, before the stub

Exit-code markers at `main`'s first statement (0x40) and immediately before
`ovr_init_game();` (0x41):

```
no nops          -> CODE=64 (0x40)   main's body runs
nop 40           -> CODE=65 (0x41)   the ovr_init_game call site is reached
nop 40,41        -> (no exit)        the call is taken and the program hangs
```

Combined with the verified `INT 3Fh` vector (`_ST_INT3F_PROBE` at
`006C:0030`, installed as `es:[0xFC]=0x30`, `es:[0xFE]=cs`), the same build
hangs **without the handler firing**:

```
OUT.BIN missing / RUN.LOG empty
```

So the hang is inside the `ovr_init_game` thunk's far jump, *before* the
`INT 3Fh` stub executes.  The override attempt (patch the thunk's `EA 48 00 B0
14` to `CD 3F`) could not even locate that byte pattern in the current
build, because the relocation pass changes the image layout - the thunk has to
be found through `REBUILT.MAP` (`_OVR_INIT_GAME`) and the segment table each
time, not by a fixed byte pattern.

Next probes, in order:

1. locate the thunk through the map, read its `EA <ofs> <seg>` operands from the
   *built* image, compute where `seg` points once the DOS relocation is applied,
   and compare that paragraph with `O09_SEG`'s start from
   `audit/overlay_blocks.csv`;
2. if they differ, the relocation entry's assumed load base is wrong for the
   stub blocks - the fix is in `add_missing_relocations()` (it currently assumes
   the DOS load segment applies to the whole image);
3. if they agree, the failure is that the stub block itself is not where the map
   says at run time, i.e. the resident image's overlay stub area is not loaded -
   which the loader would also have to address.

### The thunk is correct, but neither the thunk nor the stub is executed

`tmp/thunk_check.py` locates `_OVR_INIT_GAME` through the map and reads the
operand from the built image:

```
map:    _OVR_INIT_GAME 06DE:0203        (THUNKS_TEXT at file 0x06DE0)
thunk:  EA 48 00 12 14                  ljmp 1412:0048
target: segment 1412 = O09_SEG at file 0x14120 (STUBSEG)
bytes:  CD 3F 7C 05 00                  INT 3Fh, id 0x7C, offset 0x0005
segment word at image 0x6FE6 relocated: True
```

So the relocated target is exactly `O09_SEG:0048` and the stub is there.  The
`audit/overlay_blocks.csv` entry for O09 now matches too (segment `1412`, file
`0x14120`, 187 bytes) - the CSV had an off-by-one that took the map's *end*
column as the start; `scripts/overlay_blocks.py` is fixed.

Decisive probes on that build:

```
patch the stub at 0x14120+0x48 with mov ax,4c43h; int 21h   -> hang
patch the thunk at 0x6FE0+0x203 with mov ax,4c44h; int 21h  -> hang
```

Neither is executed, yet the exit-code ladder shows `main` reaches the
`ovr_init_game();` statement (0x41 fires).  So the call compiled into `main` does
not go to the thunk at `06DE:0203`.

That is the next thing to look at: disassemble `main`'s body in the built image
around the call and see which far address it uses.  `ovr_init_game` is only
*declared* in the tree (`undefined ovr_init_game();`) and supplied by TLINK's
`/o`, so the call may be encoded differently from the thunk the map lists (e.g.
through the overlay dispatch table rather than a direct `CALLF`).

### Patch probes were silently corrupted by DOS relocations

Chasing why an exit stub at the `ovr_init_game` call site appeared never to run
turned up a flaw in the probes themselves: a 5-byte stub written over a `9A`/`EA`
instruction covers its **segment word**, which is a DOS relocation target.  At
load time DOS adds the load segment to those two bytes, so

```
patch at 0x653f:  B8 48 4C CD 21      (mov ax,4C48h; int 21h)
relocation 0x6542 -> bytes "CD 21" become 0x21CD + loadseg
```

and the stub is no longer an exit.  Every probe that patched a call instruction
and then reported "hang" was therefore uninformative.

A working probe helper now removes the overlapping relocation entries and
rebuilds `e_crlc` (`tmp/patch.py`).  Measured with it, on the current build:

```
patch 0x651f (cmp argc,2)             -> CODE=71   reached
patch 0x6525 (argc<2 branch body)     -> CODE=74   reached
patch 0x6531 (jmp to the first call)  -> CODE=75   reached
patch 0x6533 (argc>=2 branch body)    -> no code   not taken (argc==1)
patch 0x653c (argc>=2 last store)     -> no code   not taken
patch 0x653f (lcall ovr_init_game)    -> no code   still unexplained
patch 0x6544 (lcall ovr_run_demo)     -> no code   not reached before the hang
patch 0x6FE3 (thunk, reloc dropped)   -> no code
patch 0x14168 (O09 stub)              -> no code
```

So `main` is entered (`CODE=70` when its entry is patched), the `envp`/`argv`
setup runs, the `argc < 2` path is taken, and the `jmp` to the overlay call is
executed - yet a patch at the instruction it jumps to does not fire.

Two facts learned along the way that outlive this probe:

* the map's segment column is **not** the image paragraph (`_MAIN 0650:0003`
  while the prologue is at image 0x6503, i.e. paragraph 0x650); only the
  byte-level match identified the code;
* `tmp/patch.py` must drop the relocation whose offset lies in
  `[patch, patch+5)`, otherwise the stub is corrupted at load time.

The next probe should stop patching code bytes and instead use an
execution-tracing mechanism that cannot be rewritten by the loader - e.g. a
`CLI`/`HLT` stub and reading CS:IP from a `HALT` in DOSBox's debugger, or an
`INT 1` single-step handler that records the last IP visited into DGROUP.  Only
that will settle whether control reaches `1412:0048` at all.

## RESOLVED: the stall was a double relocation, and the overlay stub is now reached

### Root cause

`add_missing_relocations()` built its "already relocated" set from the **raw
offset field** of each existing entry:

```python
rel = set(offset for (offset, segment) in entries)      # wrong
```

TLINK emits `(offset-within-segment, segment-paragraph)` pairs, so the word an
entry patches is at `segment*16 + offset`, not at `offset`.  The check therefore
missed every TLINK entry and appended a second `(image-offset, 0)` entry for the
same word.  DOS adds the load base once per entry, so those words received it
**twice** and every such far transfer landed at `2*loadbase + seg`.

Measured on the pre-fix image:

```
1451 entries, 831 distinct linear targets, 620 words relocated twice
including main's lcall to ovr_init_game and the thunk's ljmp into O09_SEG
```

After comparing linear addresses (`seg*16 + off`): **831 entries, 0 duplicates**.

### Verification: an INT 60h tracer

`INT 3` was useless as a marker - DOSBox intercepts it internally, so the
installed handler never ran and every probe answered "no code".  `INT 60h` is an
unused software interrupt that goes through the IVT, and a 2-byte `CD 60` marker
has no immediates for the loader to rewrite.

`tmp/trace60.py` installs a handler that writes one byte and exits 0x50, builds
once, and marks each address in turn:

```
                     before the fix     after the fix
main entry           reached            reached
argc test            reached            reached
branch jmp           reached            reached
ovr_init_game lcall  reached            reached
thunk (ljmp)         NOT reached        reached
O09 stub (INT 3Fh)   NOT reached        reached
```

The original was used as the oracle for the method itself: patching its main
entry and two interior sites with exit stubs gives `CODE=81` each time, so a
"no code" answer from the rebuild is a real result and not a harness artefact.

### The overlay interrupt now fires

With the fix in place, the `INT 3Fh` probe handler (installed at vector `0xFC`,
non-static so its address is real) **fires**:

```
OUT.BIN 1 bytes: b'H'
```

So the whole chain is confirmed: `startx` -> `main` -> `lcall ovr_init_game` ->
thunk `ljmp` -> `O09_SEG` stub -> `INT 3Fh`.

### What remains

`INT 3Fh` needs a real handler: the VROOMM block loader.  Calling the prepare
entry (`_OVRTEXT_:0D24`, the original's init-table priority-1 entry) still does
not produce `STRONG.SAV`, so the manager does not initialise itself from that
call alone in this link.  The loader design is unchanged and now has a confirmed
entry point:

1. on `INT 3Fh`, read `id` and `ofs` from the stub at the returned `CS:IP`
   (`CD 3F <id> <ofs_lo> <ofs_hi>`);
2. look the `:OVY` block up in `audit/overlay_blocks.csv`;
3. read it from the EXE into its segment, apply its relocations;
4. far-jump to `block_segment:ofs`.

## The overlay manager: what is now known

### Our own EXE has a complete, parseable FBOV structure

`scripts/fbov/model.py` (written for the original) parses the rebuilt image
without modification:

```
segments 152   overlays 102   fixups 10758
hdr 13C4  code_seg 312A  fileofs 0x222A0  codesz 0x1588  fixupsz 0x4E  jmpcnt 60
hdr 13DB  code_seg 3289  fileofs 0x23890  codesz 0x36CF  fixupsz 0x110 jmpcnt 23
```

So every input the loader needs is present: per-overlay code offset/size, the
trampoline count, and the fixup table (each entry is a word offset into the code
whose current value is `(target_segment_index << 3) | flags`).

### The manager algorithm is already documented in the repo

`tools/devroomm/src/ovrman.c` is a reference decompilation of OVERLAY.LIB's
VROOMM, with `__OvrPrepare`, `__OVRINIT`, `__InitModules`, `__OvrDoFixups`,
`__OvrFixupFunref` and `__OvrInitReadSegs`.  Key points:

* `__OvrPrepare()` calls `__InitModules()`, allocates a buffer with
  `_farmalloc(bufsz*16)`, then `__OVRINIT(0, buf.seg+bufsz, buf.seg)`;
* `__OVRINIT` opens the exe (env path, then filename, then env), finds `FBOV`,
  sets `__OvrFileBase`, installs the INT 3Fh vector via
  `__OvrResetInterruptVector`, sets the overlay heap, re-runs `__InitModules`
  (this time adding `__OvrFileBase` to each `segh->fileofs`) and reads the
  segment table.

### Measured attempts

| attempt | result |
|---|---|
| far call to `_OVRTEXT_:0D24` (hand-computed) | hangs - that address is **not** `__OvrPrepare`; the public symbol is `__OVRPREPARE` at `07C1:08EE` |
| `_OVRPREPARE()` from C (links: `__OVRPREPARE`) | runs, program exits **code 3** = Borland `abort()` |
| `_OVRINIT("STRONG.EXE", bufend, bufseg)` with a DOS AH=48h buffer | hangs |
| `_OVRINIT(0, bufend, bufseg)` (env path) | hangs |

The abort in `_OVRPREPARE` is consistent with `_farmalloc` returning 0 (our far
heap is not initialised that early) or `__OVRINIT` failing.  The hang in the
direct `__OVRINIT` calls is consistent with the environment walk: `startx`
currently hands `main` a **two-byte fake environment** (`static char env0[2]`),
while `__OvrExeOpenEnv` walks the real DOS environment block looking for the
program path that DOS appends after the double NUL.

### Next step

Give the process its real environment: `startx` already reads PSP[0x2C] into
`_envseg_at_`; pass that segment as `envp` (and keep the real `argv`) instead of
the fake block, then retry `_OVRPREPARE()`.  If the abort persists, initialise
the far heap before the call (C0's `__setupfarheap` equivalent) so `_farmalloc`
can supply the overlay buffer.

### Localised: `__OVRINIT` returns INIT_NOEXE - it cannot open our own EXE

Tracing `__OVRINIT` instruction by instruction with INT 60h markers
(`tmp/trace_ovrpath.py`) gives a definite answer:

```
call __OvrExeOpenEnv       reached
call __OvrExeOpenFilename  reached
call __OvrExeOpenEnvPath   reached
mov ax,0xfffe (INIT_NOEXE) reached      <- all three opens failed
success path               NOT reached
```

So the manager runs, checks `__OVRTRAP__` (present: `cd 3f ...` at
`_OVRDATA_:00A0`), and then fails to open the executable.  `__OvrPrepare`
therefore calls `abort()` - which is exactly the exit code 3 observed.

Why each open fails:

* `__OvrExeOpenEnv` walks the real DOS environment for the command line DOS
  appends after the double NUL; it needs DOS >= 3 and that appended path.
* `__OvrExeOpenFilename` uses `__EXENAME__`, which C0 fills from `argv[0]`.
  Our `__setargv` is still a stub, so the buffer is empty.
* `__OvrExeOpenEnvPath` needs a `PATH=` variable; the harness environment has
  none, and the reference code's scan can run past the end of the block.

Two concrete defects found on the way:

1. **`exename` is a far pointer.**  `__OVRINIT` reads `[bp+6]`/`[bp+8]` as
   ofs:seg, but the prototype used `char *` - near in medium model - so the
   segment half was garbage.  The prototype must be `char far *`.
2. **`__EXENAME__` is empty.**  Filling it (or passing a valid far name) is the
   direct fix; recovering `__setargv` is the faithful one.

Also verified: the manager's data segment load `mov ds, word ptr cs:[0]` reads a
word that **is** relocated (`0x1369` = `_OVRDATA_`), and `FBOV` sits exactly at
the paragraph-aligned end of the load image (`0x22280`), so neither the segment
setup nor the FBOV search is at fault.

Next step: give the manager a name it can open - fill `__EXENAME__` from
`argv[0]` in `startx` (or pass a far pointer to a DGROUP "STRONG.EXE"), and make
the DOS buffer allocation's carry flag observable so a failed AH=48h cannot be
mistaken for a manager hang.

### BREAKTHROUGH: `__OVRINIT` now succeeds and `init_game` is called

Two instrumentation defects had been hiding the truth:

1. **BCC's inline assembler rejects `0xNNh`** when a hex letter precedes the `h`
   suffix (`mov ax,0x4c5ah` is a compile error, `mov ax,4C5Ah` is fine).  A probe
   built on the broken form linked a stale object and looked like a hang.
2. **`RUN.LOG` only grows when the program exits** - the shell closes its
   redirection file then.  A hanging probe therefore reports 0 bytes even though
   its `AH=40h` write succeeded.  Markers now go to `DBG.TXT` opened, appended
   and *closed* per write, so they survive a hang (`st_dbg()`).

With those fixed, the manager initialises correctly:

```
DBG.TXT = "A0I"

  A  DOS AH=48h allocation of 128 KiB succeeded (carry clear)
  0  _OVRINIT returned INIT_OKAY
  I  main reached the ovr_init_game() call site
  -  no 'J': init_game does not return
```

So the whole VROOMM bootstrap works now:

* `_OVRINIT((char far *)"STRONG.EXE", end, beg)` - the **far** name is the fix;
  `__EXENAME__` is still empty because `__setargv` is a stub;
* INT 3Fh is installed by the manager, `FBOV` is found, the segment table is read;
* `main` proceeds to `lcall ovr_init_game` and the manager takes over.

The failure has moved one level deeper: it is now inside the overlay load for
`init_game` (O09), not in the manager's initialisation.

Next step: find where the first overlay load stops.  Either the manager's INT 3Fh
handler is entered and the block read hangs, or the handler is not entered at all;
reading the installed vector after `_OVRINIT` and marking inside the manager's
`__OvrReadOvrDisk` path will separate those two.

### The INT 3Fh handler is installed and entered

Reading the IVT after `_OVRINIT` and replacing the vector with a probe that
appends `H` to `DBG.TXT` gives:

```
DBG.TXT = "A0VOPIH"

  A  DOS AH=48h allocation succeeded
  0  _OVRINIT returned INIT_OKAY
  V  IVT[3Fh].segment is non-zero   (manager installed its handler)
  O  IVT[3Fh].offset  is non-zero
  P  probe handler installed
  I  main reached the ovr_init_game() call site
  H  INT 3Fh was entered by the first overlay call
```

So the whole overlay *dispatch* path works: `main` -> `lcall ovr_init_game` ->
thunk -> `O09_SEG` stub -> `INT 3Fh` -> handler.  The hang is inside the
manager's own handler, i.e. in the block load / fixup / far-jump, not in reaching
it.

Next step: mark successive points inside the manager's handler.  Its address can
be read from the IVT as a load-module paragraph (subtract the load base), and
`tools/devroomm/src/ovrman.c` names the stages - `__OvrCalcSize`, `__OvrAddToLoadList`,
`__OvrReadOvrDisk` (seek + DOS read), `__OvrDoFixups`, `__OvrFixupFunref`, then
the far jump to `code_seg:ofs`.  One INT 60h pass over those stages will show the
last one reached.

Note on the earlier "hang": the program is interactive and never exits, so
`RUN.LOG` stays empty by construction; only `DBG.TXT` (flushed per write) carries
evidence.

### Using the compiler's own startup instead of a hand-written one

The overlay machinery is compiler-supplied (OVERLAY.LIB + C0), so the rebuild
should let *C0* do the startup rather than replicate it.  `link_standalone.py`
now accepts `STOCK_STARTUP=1`, which leaves the EXE header entry at TLINK's own
value instead of patching it to our recovered `_STARTX`.

```
STOCK_STARTUP=1  ->  header entry 0000:0000 = C0.ASM's _start (segment 0000,
                     size 0x297 in the map), i.e. the real Borland startup
                     that walks _INITSTART.._INITEND including __OvrPrepare
```

Result of running it:

```
CODE=3          (Borland abort)
STRONG.SAV      absent
```

So C0's startup *does* run the compiler-supplied path, and that path aborts.
The two plausible aborts in `__OvrPrepare` are:

* `_farmalloc(bufsz*16)` returning 0 - the far heap is not ready at priority 1;
* `__OVRINIT` returning non-zero - `__EXENAME__` is filled by `__setargv`
  (priority 16), which runs *after* `__OvrPrepare` (priority 1), so the name may
  still be empty at that point.

The hand-written `_STARTX` path is kept as the default because it is the one with
verified behaviour (`A0VOPIH`), and `STOCK_STARTUP=1` is the switch for the
compiler-supplied route.

The important consequence: **no overlay manager needs to be reversed**.  Both
routes use `OVERLAY.LIB` as linked; the difference is only which startup calls
`__OvrPrepare` and with what heap/name state.

### The INT 3Fh vector points into the manager, not into our CRT

Dumping the installed vector relative to our own `CS` (which is `CRTL_SEG`,
map paragraph `006C`) gives, in one instrumented build:

```
DBG.TXT = "A0#076B04EFI"
   A      allocation ok
   0      _OVRINIT INIT_OKAY
   #      separator
   076B   IVT[3Fh].segment - CS      -> handler segment = 006C + 076B = 07D7
   04EF   IVT[3Fh].offset
   I      main reached ovr_init_game
```

`07D7` is the `_OVRTEXT_` paragraph in that build, so the vector really is the
manager's own handler (`__OVRTRAPHANDLER`, installed by
`__OvrResetInterruptVector` after it also opens the EXE into `__OvrDosHandle`).

An earlier version of this dump printed only two hex digits of the segment
difference, which made the vector look like it pointed into CRTL_SEG; the
four-digit form above is the correct one.  `tmp/resolve_handler.py` resolves the
recorded address to an image offset for the build that produced it.

To place stage markers inside the handler, the offset must be taken as
`_OVRTEXT_ paragraph * 16 + (handler offset within the module)` computed **in the
same build that ran**, because the segment layout shifts with every source edit -
the same stale-offset trap that broke the earlier thunk patches.

Note on the two startup routes, both using OVERLAY.LIB unchanged:

| route | state |
|---|---|
| `_STARTX` (default) | manager initialises, `init_game` called, INT 3Fh entered, hangs inside the handler |
| `STOCK_STARTUP=1` (C0) | C0 walks the init table and calls `__OvrPrepare`, which aborts (code 3) |

### Stage probe inside the manager: inconclusive, and why

`tmp/ovr_stage.py` installs the DBG tracer, initialises VROOMM with
`_OVRINIT("STRONG.EXE", ...)` (which returns INIT_OKAY), then places a 2-byte
`CD 60` marker at each manager stage in turn:

```
_OVRTEXT_ base 0x7CE0, handler 0x81CF
  handler entry    +0x4EF -> DBG.TXT "00"
  resident check   +0x5BA -> "0"
  size/slot setup  +0x5C0 -> "0"
  read call        +0x5CC -> "00"
  fixups call      +0x5D3 -> "00"
  add to list      +0x5F5 -> "0"
```

No stage marker fired, although the earlier run showed `H` (INT 3Fh entered).
The two results come from different builds and cannot both be right, so the next
step must put both markers in **one** build:

* the `H` probe replaces the INT 3Fh vector with a handler that only marks;
* the stage probe leaves the manager's handler in place and marks inside it.

Reconciling them requires the same run to (a) mark main's arrival, (b) install
the INT 60 marker inside the manager, and (c) report the exit state.  Only then
is it known whether the manager's handler is reached with the stage build's
layout.

The measured facts that are not in doubt:

* `_OVRINIT` returns INIT_OKAY and installs the INT 3Fh vector, which resolves to
  `_OVRTEXT_` (paragraph difference 076B from `CRTL_SEG` 006C, offset 04EF);
* the handler's loader routine is at `_OVRTEXT_+0x59F` and its stages are
  visible in the map-relative disassembly (`call 0x8155` size/slot, `call word
  es:[0x18]` read, `call 0x8330` fixups, `call 0x8380` add-to-list).

### Self-consistent run: main and the manager handler are both reached

`tmp/ovr_stage2.py` puts main's marker and one manager-stage marker in the *same*
build, which resolves the earlier two-build conflict:

```
baseline (no stage marker)   A0I     alloc ok, _OVRINIT INIT_OKAY, main at the call
handler entry  +0x4EF        A0IX    the manager's INT 3Fh handler IS entered
loader start   +0x59F        A0II
resident check +0x5BA        A0II
size/slot      +0x5C0        A0II
read call      +0x5CC        A0II
fixups call    +0x5D3        A0II
```

Two facts are now certain:

* `_OVRTEXT_` base `0x7D00`, handler `0x81EF`; marking `+0x4EF` produces `X`, so
  the manager's own handler runs in the same image that reaches `main`;
* the earlier "no marker fired" result was an artefact of the stage-probe build
  not marking `main` at all, i.e. it could not distinguish "handler not reached"
  from "program never got that far".

Open anomaly: the loader-stage markers produce `A0II` - **two** main markers and
no `X`. Since the INT 60h handler always writes `X` before spinning, the second
`I` means the main marker executed twice in those runs. That is the next thing to
explain; plausible causes are the marker landing inside an instruction that
changes control flow so the call is retried, or `main` being re-entered from the
manager's failure path.

The important gain: the question is no longer "is the handler reached" (it is)
but "why does a marker inside the loader alter main's execution".

### Marker-per-instruction inside the loader: the tracer itself fails there

`tmp/ovr_stage3.py` disassembles `_OVRTEXT_+0x59F` in the same build that is
probed and marks verified instruction starts:

```
_OVRTEXT_ base 0x7d00, loader 0x829f

+0x000  inc word ptr [0xac]        -> A0II
+0x004  cmp word ptr es:[0x10],0   -> A0II
+0x00A  je 0x82ba                  -> A0II
+0x00C  mov byte ptr es:[0x1b],1   -> A0I
+0x012  or byte ptr es:[0x1a],4    -> A0I
+0x018  jmp 0x82d6                 -> A0I
+0x01A  nop                        -> A0I
+0x01B  or byte ptr es:[0x1a],8    -> A0II
+0x021  call 0x8255                -> A0II
```

Reading the two possible answers as "marker hit" (would append `X`) and "marker
not hit" (plain `A0I`) leaves a contradiction: none of the runs contains `X`, yet
five of them show a duplicate `I`, and the duplicate is not accompanied by a
second `A`/`0` pair, so it is not a reboot of `startx`.

Conclusion: **the INT 60h tracer does not reliably fire inside the manager.**
Either the vector is not what we installed by the time the loader runs, or the
manager's own code path never executes these instruction starts (its first
instruction is reached but the code we disassembled is not the path taken).

Rather than keep patch-probing, the next step should use a mechanism outside the
program's own code: DOSBox's built-in debugger (`-dbg`/`Z:\DEBUG`) with a
breakpoint at `_OVRTEXT_+0x59F`, reading `CS:IP` directly.  That cannot be
rewritten by relocations, does not need a marker byte, and answers "is this
address executed" without perturbing the instruction stream.

Honest note on effort: the patch-marker approach has now produced three
mutually inconsistent results in this area (`H` fired, stage markers silent,
instruction-start markers split).  Continuing to iterate on it is not converging;
the debugger route is the way to settle it.

### The overlay code is never entered, and the likely reason is `__OvrDosHandle`

Patch-marking inside the manager gave inconsistent answers, so the effect was
tested instead: put an exit stub at the *start of the O09 code blob* and see
whether the program exits with that code.  The blob's **file** offset is not the
map's image offset - it comes from the overlay header via
`scripts/fbov/model.py`:

```
stub id 0x7C = segment 124 -> header 0x156E
overlay header 156E  code_file_offset 0x84F10  codesz 0x53F  fixupsz 0x30
patch at 0x84F10 (block start) and 0x84F15 (entry +5) -> no exit, still hangs
```

(The first attempt patched `img + 0x29FB0`, the map's *image* address, which is a
different location in the file - that result was meaningless.)

So the manager's handler runs (`A0IX`) but never transfers control into the
loaded overlay, and the loader's error path is `ljmp 0:0x2AE`, which matches the
observed reboot-like duplicate `I` markers.

Failure point, from the loader disassembly:

```
81cc  call word ptr es:[0x18]     ; __ReadOvrDisk
81d1  jb 0x8215                   ; carry set -> ljmp 0:0x2AE
```

A read error means `__OvrDosHandle` is invalid.  `__OVRINIT` deliberately closes
the handle and sets it to 0, then `__OvrResetInterruptVector` re-opens it from
`__OVRFILENAME[0]` and `__OvrExepathBuf`.  If that reopen fails, every block read
fails - exactly the observed path.

Next step: after `_OVRINIT`, read the word at `_OVRDATA_:00B8` (`__OVRDOSHHANDLE`)
and mark whether it is a valid handle, then, if it is not, fix the re-open (the
path buffer `__OvrExepathBuf` is filled by `OvrDoOpenFile` during `__OVRINIT`, so
a mismatch there is the first thing to check).

### Can the hand-recovered CRT be replaced by the Turbo C library?

Tested with `link_standalone.py --without-crtl` (the switch already existed):

```
Error: Undefined symbol __FAKREALCVT in module OVR.ASM
Error: Undefined symbol _PADD_AT_ in module O04.C
Error: Undefined symbol _EMSFREE in module O05.C
Error: Undefined symbol _XMSFREE in module O05.C
Error: Undefined symbol _AUDIO_DONE in module O05.C
Error: Undefined symbol _SRAND8 in module O06.C
Error: Undefined symbol _LXMUL_AT_ in module O07.C
... 25+ more
```

So `crtl.c` is **not** only the CRT.  It defines 171 functions, 60 of which are
referenced from other modules, and they fall into two groups:

* stock Turbo C functions - `printf` (162 calls), `memcpy` (43), `strcpy` (37),
  `strlen` (24), `close` (23), `write` (18), `exit` (17), `_fmemset` (52),
  `_fmemmove` (36), `_fsetmem` (17), `F_SCOPY` (54) - all of which CM.LIB has;
* **original first-segment game code** - `_AUDIO_INIT` / `_AUDIO_DONE`,
  `_EMS_INIT` / `_EMS_FREE` / `_EMS_REALLOC`, `_XMS_INIT` / `_XMSFREE`,
  `_STSHINIT_SCAN`, `_SRAND8` / `_RAND8`, `_PADD_AT_`, `_LXMUL_AT_`,
  `_LDIV_AT_`, `_LXLSH_AT_`, `_LMOD_AT_` ... These are the 1000:xxxx functions of
  the original, they are not in any library, and they must stay.

So "just use the compiler's CRT" cannot be a wholesale drop: the file would have
to be split into a stock-CRT half (deleted, linked from CM.LIB) and a
first-segment half (kept, recovered).  That split is a worthwhile next step but a
real refactor, not a switch.

### CRT substitution, second attempt: 46 stock functions deleted

`tmp/del_funcs.py` removes a named definition together with its `/* SEG:OFF */`
marker; the stock half of `crtl.c` is then supplied by `CM.LIB` at link time.
Because TLINK resolves object files before libraries, deleting our copy is what
makes the library version win.

Deleted and replaced by `CM.LIB` (link clean, 46 functions):

```
strings/memory  strcat strcmp strcpy strlen memcmp _fstrstr memcpy
                _fsetmem _fmemset _fmemmove _fstricmp
file I/O        __write __sbrk write close read _open _creat lseek
                fseek ftell fflush fputc flushall filelength _xfflush
                unlink mkdir chdir getcwd getcurdir _dos_setdrive _dos_getdrive
                getdisk setdisk
heap/other      malloc farfree farmalloc farrealloc coreleft __brk
                toupper tolower rand _cexit _c_exit
```

Result:

```
grep_checks TOTAL 61,437 -> 60,339   (-1,098)
build 62/62 clean, 0 errors; link 0 errors
compare_state 1,630 identical / 0 different / 0 missing
compare_runtime 1,523 identical / 14 different (unchanged)
diff_dgroup 976/1,868 matched
```

### What still cannot be substituted, and why

Two CM.LIB modules reference internal symbols whose *names differ* from the
original's recovered names, so the link fails with the same message both times:

```
Error: Fixup overflow at _TEXT:0026, target = __REALCVT  ... module CLRSCR
Error: Fixup overflow at _TEXT:0122, target = __VIDEOINT ... module SCREEN
```

* `__VIDEOINT` - CM.LIB's `SCREEN`/`CLRSCR`/`SCROLL`/`WHEREXY` call it.  The
  original's function is `_VideoInt` (`audit/symbols.tsv: 1000:1453 _VideoInt
  Function`), so the two builds disagree on the spelling of that hook.
* `__REALCVT` - CM.LIB's `VPRINTER` reads it as the float-conversion pointer.
  The original's CRT keeps it as a *data word*, `audit/symbols.tsv:
  2ca0:000e _realcvt Label` (value `0x15CF` = the offset of `_FakRealCvt`).

So `printf`/`sprintf`/`vsprintf`/`__vprinter*` (688 §5 artifacts) and the conio
family stay recovered: substituting them would need an alias layer that rewrites
the original's data word, which would break the byte-exact DGROUP requirement.

The conclusion recorded earlier stands and is now narrower: pure C runtime
helpers can be taken from `CM.LIB`; anything on the float or console path cannot,
because the original's CRT and the bundled `CM.LIB` disagree on the internal
hook names.

### Runtime data state at `main` entry: 12 differences, all classified

`scripts/compare_runtime.py` compares the 64 KB at DS:0 dumped from both images
at `main`'s first instruction (`tmp/dump_dgroup_stdout.py` regenerates the
dumps; the compare script only reads them).

The matcher used to collapse a trailing `_N` in its primary key, which merged
`s_kill_2/3/4` into one key; the monotonic picker then compared the original's
`s_kill_3` against our `s_kill_4` and reported a data difference that did not
exist.  It also never preferred the export's `_2410_XXXX` twin.  With
`exact suffix -> exact key -> loose key` matching:

```
symbols matched   1537 -> 1560
identical state   1523 -> 1548
DIFFERENT state     14 -> 12
```

The remaining twelve, classified with what writes them:

| symbol | why it differs |
|---|---|
| `_StartTime` | reads the BIOS timer at start-up; different on every run |
| `_brklvl`, `brk_normalize_xsize` | heap break level and its granularity, set by C0 for the linked program size |
| `_DATA` (DGROUP:0) | C0's PSP/heap-top words; ours holds 0x10, the original 0 |
| `_streams`, `_exitbuf`, `_exitfopen`, `_exitopen` | C0/stdio table and its exit-chain function pointers: our CRT addresses |
| `_video` | CRT video state block; same shape, one late byte differs |
| `__setargv_SavedReturn` | our `startx` does not call `__setargv` (see below) |
| `PlaceErrPtrs`, `LevelRangeLabels` | arrays of far pointers into DGROUP: our offsets, which the normaliser cannot map because the targets are mid-symbol |

None of them is game data: every one is CRT start-up state, a clock reading, or
an address-space artefact.  Under the project rule that the CRT is
compiler-supplied, these stay as they are; the game-data state is at parity.

`__setargv` is the one remaining *structural* gap rather than an artefact: the
original walks the linker init table (priority 0x10) and `startx` calls
`_setupio` and `_c0crtinit` directly instead, then builds a minimal argv in
DGROUP, so `__setargv_SavedReturn` stays 0.

## State sampler: what works, what does not, and the exact next fix

`audit/state_map.tsv` lists every data object (2,655 symbols over 20 segments,
76,136 bytes).  `scripts/compare_state_runtime.py` compares them per segment,
normalising stored far pointers through segment/offset mapping.

Measured stub shapes (`tmp/probe_stub.py` is the harness regression test):

| stub shape | rebuilt image | original image |
|---|---|---|
| single write, `CX = size` | **all 8 segments exact, 92,480 bytes** | 32,768 of 35,072; 20,480 of 22,896 |
| single write, `CX = 0xFFFF` | 65,535 (probe) | - |
| 4 KB chunks in one stub | 28,672 of 46,288 | 12,288 of 35,072 |
| `mov bp, ds` capture | 0 | 0 |

Conclusions, each from the table:

* the rebuilt side is **done** - one write per run, `mov ax, ds / add ax, delta /
  mov ds, ax / xor dx,dx / mov cx,size / mov bx,1 / mov ah,40h / int 21h`;
* `mov bp, ds` (8C DD) is fine, but `8C DA` - which the first attempt used - is
  `mov dx, ds`, and that is what made both images dump 0 bytes;
* extra `int 21h` calls lose data, so never write a segment in several chunks;
* the original still comes up ~2,300-2,400 bytes short (32,768/35,072,
  20,480/22,896), i.e. the tail is lost when the program exits while stdout is
  still buffered.  Both shortfalls sit on 4 KB boundaries, so this is a flush
  problem, not a wrong size.

### The fix to implement next

Create the dump file from inside the stub and close it explicitly, so the final
flush happens before exit.  The filename goes in the patched stub itself and is
addressed through CS:

```
1E              push ds                       ; save DGROUP
0E 1F           push cs / pop ds              ; DS = CS for the filename
BA <nameoff>    mov  dx, nameoff              ; ofs of "ST.BIN" in the stub
B9 0000         mov  cx, 0
B4 3C           mov  ah, 3ch                  ; create
CD 21           int  21h                      ; AX = handle
89 C3           mov  bx, ax
1F              pop  ds                       ; DS = DGROUP again
B9 <size>       mov  cx, size
BA 0000         mov  dx, 0
B4 40           mov  ah, 40h                  ; write
CD 21           int  21h
B4 3E           mov  ah, 3eh                  ; close -> flush
CD 21           int  21h
B8 004C         mov  ax, 4c00h
CD 21           int  21h
name:  "ST.BIN",0
```

`nameoff` is the stub's own intra-segment offset (`ofs + len(prefix)`), because
the stub is patched at `seg:ofs` inside main's segment while CS still addresses
that segment.

With a close, one run can emit several segments again (no 256 KB ceiling, no lost
tail), so `tmp/dump_state1.py` should return to a multi-`(delta,size)` stub - the
file handle, not the write size, is what was missing.

## The original zeroes part of DGROUP at start-up

The state comparison flagged `2410:8436 s_s_is_no_longer_paralyzed` and
`2410:8451 s_s_breaks_free_of_the_web` as `want 00 00 ... got "..."`.  That is
not a pairing artefact: read directly from the two dumps,

```
original runtime 0x842c..0x846c : 00 00 00 00 ...   (all zero)
original file image 0x842c..    : %s is no longer paralyzed.\0%s breaks free ...
ours 0x842c..                   : a2 87 14 00 01 60 02 ...   (different layout)
```

so `audit/dgroup_2410.bin` (the file image) holds those strings but the *running*
original has zeros there.  The program clears that region during start-up, which
means:

* the state comparison is right to report a difference, and it will keep reporting
  one until our build also leaves that area zero;
* the strings must reach the game by some other route (they are almost certainly
  copied or repointed at run time), which is worth identifying before changing any
  declaration - `diff_dgroup` compares the *file* image, so "fixing" this by
  zeroing the initialisers would break that gate instead.

Practical consequence: this class must be handled by matching the original's
start-up zeroing, not by editing the string declarations.  It is the same family
as `agentClipRect` (2410:842c) and `s_d` (84a3), which the state report lists
alongside it.

## Where the state comparison stands

```
original dump 78,448 bytes / 21 segments, 0 short fragments
rebuilt  dump 92,480 bytes /  8 segments, 0 short fragments
1,570 identical / 100 different / 985 no counterpart
```

Counting only the fixes to the instrumentation (address normalisation through
both linked and runtime segments, authoritative object sizes, duplicate-name
pairing by address), the different count went 816 -> 100 with no change to the
source data, because the earlier numbers were dominated by artefacts of the
comparator itself.

## The overlay thunks are plain jumps - the INT 3Fh premise is obsolete

The entry ladder recorded earlier (`main -> lcall ovr_init_game -> thunk ->
O09_SEG stub -> INT 3Fh`) no longer describes this build.  `ovr_thunks.asm` is
generated (`scripts/gen_ovr_thunks.py`) and every entry is a direct far jump:

```
    public _ovr_init_game
_ovr_init_game proc far
    jmp _init_game
_ovr_init_game endp
```

so `main` reaches the recovered `init_game` (`ovc09_init.c:273`) without any
overlay manager involvement.  Whatever stops the program is therefore *inside*
`init_game`, not in the thunk chain.

`init_game` itself calls, in order:

```
_OvrInitExt(0,0);      _OvrInitEms(0,0,0);     ovr_init_base();
init_paths();          init_cfg();             clrscr();
srand8(...);           ovr_stshAlloc(0xfa0f);  strcmp(...) x2
ovr_init_assets();     ovr_stshInit();         ...
```

`_OvrInitExt` / `_OvrInitEms` are OVERLAY.LIB entry points (compiler-supplied), and
`clrscr` is CM.LIB; those three are the first suspects because they are the only
calls in the list that are not recovered game code.

### How to bisect it without guessing

Patch `main`'s call site so it returns immediately after the k-th statement of
`init_game`, dump DGROUP as the existing stub does, and increase k until the dump
disappears - the first k that fails names the call.  This is the same
inject-and-dump technique already used by `tmp/dump_dgroup_stdout.py`, applied to
`init_game`'s return address instead of `main`'s entry.

Once a full pass through `init_game` is possible, the next milestone is a save:
run with the `grab`/save argument so the game writes `STRONG.SAV`, then compare that
file against one produced by `game/STRONG.EXE`.

## Bisection result: `main` runs, but returning from it never reaches DOS

Five probes, each a rebuilt EXE run under the project's DOSBox harness, all reading
`DONE.FLG` (written by `GO.BAT` only if the program hands control back):

| probe | change | DONE.FLG |
|---|---|---|
| baseline | `main` -> `ovr_init_game()` and on | no |
| k=-1 | `main` -> `return 0;` (no `init_game` call at all) | **no** |
| k=0 | `init_game` returns before its first statement | no |
| k=1 | `init_game` returns right after `_OvrInitExt(0,0)` | no |
| k=-2 | `main` -> `asm mov ax,4c00h / asm int 21h` instead of calling `init_game` | **yes** |
| A | `startx`: replace `exit(...)` with `asm mov ax,4c00h / int 21h` | no |
| C | `startx`: drop the `puVar15-8/-10/-c` stores *and* `exit`, exit via DOS | no |
| D | `startx`: call `main(...)` directly instead of through `(far *)main` | no |
| E | D plus an inline DOS exit immediately after the call | **no** |

Read together:

* `main`'s body **does** run — k=-2 proves control arrives in `main`, executes its
  prologue (`GGameExe`/`GExeArg` writes) and can exit cleanly from inside it;
* nothing about `init_game` matters: with the call removed entirely (k=-1) the
  program still never returns to DOS, and with `init_game` returning at its very
  first statement (k=0) it still never returns;
* the failure is in the **call/return boundary around `main`** — every variant
  that lets `main` RET hangs, even with the DOS exit instruction placed right
  after the call in `startx` (probe E).

`startx` currently calls `main` through a decompiled far-pointer dance:

```c
  {
    int (far *pmain)(int, str_t *, str_t *);
    pmain = main;
    iVar10 = (*pmain)(__C0argc, (str_t *)__C0argv, (str_t *)__C0environ);
  }
  *(int *)(puVar15 + -8) = iVar10;
  *(uint16_t *)(puVar15 + -10) = 0x1301;
  *(uint16_t *)(puVar15 + -0xc) = 0x154;
  exit(*(int *)(puVar15 + -8));
```

`main` is declared nowhere in `recovered.h`, so that cast is built from an implicit
declaration; a far call to a near function (or the reverse) leaves the stack
unbalanced, which matches the symptom exactly (body runs, `ret` does not return).
The `puVar15` stores are decompiler noise for the simulated call frame.

### Next step

Compare the rebuilt `startx`/`main` boundary against the original: dump the original
C0 start-up (`_STARTX`) and see whether it invokes `main` with a **near** or a **far**
call, then declare `main` accordingly in `recovered.h` and simplify `startx` to the
matching direct call. That is a small, verifiable change: probe E already carries the
test (build, link, run, expect `DONE.FLG`).

The probe driver is `tmp/probe_initgame_k.py` (k=-2, -1, 0..6) and
`tmp/probe_exit.py` (A, B, C, D, E); both restore every file they touch.

## `main` is called with CALLF in the original - and our `main` now is far too

Disassembly of the original C0 (`DumpAsmNamed.java "1000:0000"`) gives the boundary
exactly:

```
1000:0025  CALL  0x1000:017a   ; SaveVectors
1000:0132  CALL  0x1000:01ea   ; StartExit
1000:0149  CALLF 0x1000:301c   ; main        <- far call
1000:0151  CALL  0x1000:08fd   ; exit        <- runs after main returns
```

So `main` is a far function (`__cdecl16far`), and our tree was declaring it with no
prototype in the calling module and a **near** prototype
(`int main(int, str_t *, str_t *);`) in `st_functions.h`. Both are now far:

* `st_functions.h`: `int __cdecl16far main(int argc, str_t *argv, str_t *envp);`
* `main.c`: `int __cdecl16far main(int argc, str_t *argv, str_t *envp)`

Byte check of the rebuilt image confirms the definition is far: `main` starts at
image offset `0x6524` and ends

```
  5f 5e c9 cb        pop di / pop si / leave / retf
```

which matches the original's `CALLF`.

### But the return still does not reach the caller

| probe | change | DONE.FLG |
|---|---|---|
| k=-1 | `main` returns immediately | no |
| k=-2 | `main` exits with `int 21h` in its own frame | **yes** |
| E (after the far prototype) | `startx` calls `main(...)` directly, then `int 21h` | no |
| F | `startx` calls through a **near** pointer, then `int 21h` | no |
| marker | `startx` writes a unique exit code (`4c21h`) right after the call | never reached |

The marker test is the sharp one: the instruction immediately after the call is
never executed, so control does not come back to `startx` at all - even though the
callee's epilogue is a proper `retf` and the call is a proper far call.

Everything before the call works (`main`'s body runs, `SaveVectors`/`StartExit` ran),
so what remains is the **call frame `startx` builds**: the decompiled body uses
`puVar15` (an uninitialised pointer) for the simulated call frame and writes through
it at `-8/-10/-0xc` before `exit`.  Those stores are decompiler noise for C0's stack
slots and are the prime suspect for the corrupted frame; the correct shape is the
original's two instructions - `CALLF main` then `CALL exit` - with no intermediate
frame pokes.

### Next step

Rewrite that region of `startx` as:

```c
  iVar10 = main(__C0argc, (str_t *)__C0argv, (str_t *)__C0environ);
  exit(iVar10);
```

with `exit` declared `void __cdecl16near exit(int);` (it is `CALL 0x1000:08fd`, a near
call), and drop the `puVar15` stores.  `tmp/runcase.py` is the acceptance test:
`returned to DOS : True`.

### startx now has the original's shape, and the hang is specific to `main`

`startx` has been rewritten to the original's two statements (see commit
6c42f6e3): a direct far call to `main`, then `exit(iVar10)`, with the `puVar15`
stores (decompiler noise for C0's stack slots) removed.

Two probes run from that exact call site, differing only in which function is
called:

| probe | statement placed at the call site | returned to DOS |
|---|---|---|
| G | `srand8(0);` then `int 21h` | **True** |
| G' | `init_paths();` then `int 21h` | False (that function itself does not come back) |
| H | `main(__C0argc, __C0argv, __C0environ);` then `int 21h` | **False** |

So far calls from `startx` do return (G proves it), and the failure is specific to
the call into `main`. `main` itself is a far function - its epilogue in the rebuilt
image is `pop di / pop si / leave / retf` (`5f 5e c9 cb` at image 0x6524+14) - and
its body runs (exiting from inside it via `int 21h` succeeds).

### Next step: compare the two call encodings

Disassemble the rebuilt `startx` (segment 01B6, offset 0029, image 0x1B89) and
compare the instruction emitted for the `main` call against the one emitted for
`srand8`.  One of these is wrong:

* the arguments (three, cdecl) are pushed but the callee's `retf` expects a
  different frame, or
* the call is a near `call` to a far function (which leaves CS on the stack and
  returns into garbage - exactly the observed symptom), or
* the far pointer's segment word is a link-time constant that was never relocated
  (the same defect class as the retired `0x195d` literals).

The fix is then a one-line source change, and `tmp/runcase.py` is the test:
`returned to DOS : True`.

### The original pushes five words before `CALLF main`

The same dump gives the call site with its arguments:

```
1000:0132  CALL 0x1000:01ea   ; StartExit
1000:0135  PUSH word ptr [0x73]
1000:0139  PUSH word ptr [0x71]
1000:013d  PUSH word ptr [0x6f]
1000:0141  PUSH word ptr [0x6d]
1000:0145  PUSH word ptr [0x6b]
1000:0149  CALLF 0x1000:301c   ; main
1000:014e  PUSH AX             ; main's return value
1000:014f  NOP
1000:0150  PUSH CS             ; exit is reached through a far pointer
1000:0151  CALL 0x1000:08fd   ; exit
```

Five words = `argc` (1) + `argv` (2) + `envp` (2), i.e. `main(int argc, str_t *argv,
str_t *envp)` with `str_t` a far/space pointer of two words - which is exactly the
signature now declared in `st_functions.h`.

Two things to check in our build against this:

1. the call site must push **five** words from the same three values, and
2. `exit` is reached by `PUSH CS` + a near `CALL`, i.e. through a **far** pointer -
   so `exit` must be called far, not near.

If our `main` call pushes a different number of words (e.g. because `__C0argv` is a
near `char **` cast to the four-byte `str_t *`), the callee's `retf` still returns,
but the caller's `add sp, n` cleanup can pop the wrong amount and the next call -
or the return to DOS - goes wrong.  That is measurable by disassembling our
`startx` at image 0x1B89 and counting the pushes before the `lcall`.

### `__cdecl16far` is an empty macro

`src/decompiled/st_compat.h` defines every calling-convention macro as *nothing*:

```c
#if defined(__BORLANDC__) || defined(__TURBOC__)
#define __cdecl16far
#define __cdecl16near
...
```

so `int __cdecl16far main(...)` in `st_functions.h` / `main.c` is just
`int main(...)`, and every "far" function in the tree is really *the compiler
model's default*.  The rebuilt `main` nevertheless ends in `retf`
(`5f 5e c9 cb` at image 0x6524+14), which tells us the build is a **far-code**
model - so plain functions and plain function pointers are both far and the call
into `main` should be well matched.

That makes the remaining hang narrower still: the call is far, the callee returns
with `retf`, arguments are five words in both the original (`PUSH [0x73] ... [0x6b]`)
and the large-model cdecl call, and yet control never comes back to `startx`.

The next measurement is therefore the one recorded above: disassemble the rebuilt
`startx` (image 0x1B89) and check the `lcall`'s target segment against the `_MAIN`
symbol in `REBUILT.MAP` (segment 0652, offset 0004).  If the far pointer's segment
word is a literal rather than a relocation, the call goes to the right offset in
the *wrong* segment - the same defect class as the `0x195d` literals - and that
single check decides the fix.

## The acceptance test was wrong: the original never returns to DOS either

Running the **original** `game/STRONG.EXE` through the same DOSBox harness settles
it:

```
original returned to DOS : False
original files           : GO.BAT STRONG.DAT STRONG.EXE STRONG.FLI STRONG.SAV
```

The original does not hand control back to DOS (it is a game), but it *does* write
**`STRONG.SAV`** within 60 s.  So `DONE.FLG` - which every probe in this document
has been reading for several sessions - was never a valid milestone: both the
original and the rebuild "fail" it, and the k=-2 success was an artefact of forcing
an early `int 21h`.

The real milestone for step 6 is:

1. our rebuild produces `STRONG.SAV`, and
2. that file matches one produced by `game/STRONG.EXE`.

The original's file has been captured as `tmp/orig_STRONG.SAV` for the comparison.

### Consequence

`main`'s return path is *not* the blocker - the original never reaches it either in
a normal session.  The blocker is that our rebuild produces no `STRONG.SAV`, i.e.it does not get as far as the original does (init/loop), and the bisection of
`init_game` should be redone with this milestone, not with `DONE.FLG`.

Cheapest probe: patch the entry of `ovr_save_loadGameFile` with the existing dump
stub; if the stub fires, the game reached the save point and the difference is in
what it wrote; if it does not fire, the game is stuck earlier and the k-bisection of
`init_game` continues - now knowable because the original's behaviour is the
reference.

## Reachability with the corrected milestone: the stop is inside `main`

`tmp/reach.py <symbol>` patches a symbol's entry in a run copy with
`mov ax,4c21h / int 21h` and reports whether the run reaches it (the harness then
sees `DONE.FLG`).  Results on the current build:

| symbol | address | reached |
|---|---|---|
| `_MAIN` | 0650:0002 | **yes** |
| `_OVR_INIT_GAME` (thunk) | 06DD:020F | no |
| `_INIT_GAME` | 141B:0579 | no |
| `_RUN_DEMO` | 1564:0A32 | no |
| original `game/STRONG.EXE` (no patch) | - | writes `STRONG.SAV` in 60 s |

So `main` is entered and everything after it - the overlay thunk for `init_game`,
`init_game` itself, `run_demo` - is never reached.  The stop is therefore in
`main`'s own prologue, before its `ovr_init_game()` call, in one of the four
statements that touch `envp`:

```c
uVar6 = (uint16_t)((ulong)envp >> 0x10);
psVar5 = (str_t *)envp;
GGameExe.seg = psVar5->seg;
GGameExe.ofs = (uint16_t)envp->ptr;
if ((int)argv < 2) { GExeArg.seg = 0x2410; GExeArg.ofs = 0x94; }
else { GExeArg.seg = psVar5[1].seg; GExeArg.ofs = (uint16_t)(psVar5 + 1)->ptr; }
```

Note `(int)argv < 2` compares a **pointer** to 2 where the original compares
`argc`, and `(ulong)envp >> 0x10` narrows a far pointer to get a segment - both are
shapes Ghidra produced for what was probably `argc/argv/envp` in a different
register assignment.  The original's `main` reads its arguments from five words on
the stack (`PUSH [0x73] ... [0x6b]`), so the C signature/parameter mapping is worth
re-deriving from the original's `main` prologue at `1301:000c`.

Next: dump `1301:000c` (the original main) and our `_MAIN` (0650:0002) and compare
their prologues; the first divergent statement is the stop.

## The stop is an INT 3Fh overlay stub, not a crash in `main`

`main`'s prologue is now correct against the original (`1301:000c` -> the second
argument is `argv`, the count is `argc`, and the `argc < 2` branch stores `_DS`, not
the literal 0x2410), and the rebuilt prologue reads:

```
55 8b ec 83 ec 08 56 57
8c 5e fa            mov [bp-6],ds
8b 76 08            mov si,[bp+8]        ; argv
8b 44 02 a3 9a 85   mov ax,[si+2] / mov [859a],ax
8b 5e 08 8b 07 a3 98 85  mov bx,[bp+8] / mov ax,[bx] / mov [8598],ax
83 7e 06 02 7d 0c   cmp word [bp+6],2 / jge  ; argc
9a 0e 02 dd 06      lcall 06DD:020E      ; ovr_init_game
```

That is the original's shape.  So the run stops at (or inside) the thunk call, and
the thunk's target explains why:

```
06DD:020E  ea 48 00 1b 14      jmp far 141B:0048
141B:0048  cd 3f 79 05 00 cd 3f 90 06 00 cd 3f 6d 08 00 00 ...
```

`141B:0048` is a table of **`INT 3Fh` overlay stubs** (`CD 3F` followed by the
overlay entry index - `0x0579` is exactly the value the MAP reports as
`_INIT_GAME 141B:0579`, i.e. that is a *stub index*, not a code offset).  With no
VROOMM manager installed, the first `INT 3Fh` does not return and the game stops
right there - which is why `_MAIN` is reached and `_OVR_INIT_GAME`/`_INIT_GAME`/
`_RUN_DEMO` are not.

So the old 'INT 3Fh ladder' note in this document was right after all, but it
applies to the **targets of the generated thunks**, not to `main`'s call itself:
`ovr_thunks.asm` emits `jmp _init_game`, and the linker resolves `_init_game` to a
symbol whose address is the O09 stub table rather than to real code.

### Next step

Find where `init_game` actually landed in the image (the O09 module's real
functions are at `141B:00CA`, `141B:019A`, `141B:028E`, `141B:2CDC`, ... with
`_INIT_GAME` absent from that list), and either

* define `init_game` in a segment the thunk can reach and let `jmp _init_game` bind
  to it, or
* point `_ovr_init_game` at the recovered function explicitly.

The check is `tmp/reach.py <symbol>` against the real address, then
`tmp/runcase.py` for the `STRONG.SAV` milestone.

## Root cause of step 6: `/o` in the link made every thunk an INT 3Fh stub

`link_standalone.py` placed `/o` before the game modules, so TLINK built VROOMM
overlays and emitted a resident **STUBSEG** copy of each overlay module whose
bodies are `INT 3Fh` (`CD 3F <index>`).  The generated thunks (`jmp _name`) bound
to those stubs:

```
06DD:020E  _ovr_init_game    ea 48 00 1b 14     jmp far 141B:0048
141B:0048                    cd 3f 79 05 00 ... INT 3Fh stub table
```

With no VROOMM manager the first `INT 3Fh` never returns - that is the "hang" every
startup probe in this file was chasing, and it also explains why `_INIT_GAME` in the
map pointed at `141B:0579`, which is a stub *index* rather than code.

The resident link (the script's existing `NO_OVERLAY` branch, now the default;
`WITH_OVERLAY=1` restores the old behaviour) makes those modules normal code:

```
_INIT_GAME  105C:057D   55 8b ec 83 ec 02 56 6a   (push bp / mov bp,sp / ...)
STUBSEG segments: 2 (empty)
tmp/reach.py _INIT_ASSETS   reached
tmp/reach.py _RUN_DEMO      reached
tmp/runcase.py              returned to DOS: True
```

Gate cost (accepted - it is what makes the program run at all):

```
compare_state   1,627 / 0 / 0        (unchanged)
diff_dgroup     972 / 1,868          (was 973)
compare_runtime 1,543 / 13           (was 1,545 / 12)
grep_checks     51,212               (unchanged)
```

Remaining step-6 work is behavioural: the game now starts and exits at once instead
of hanging, so the task is to get `run_demo` as far as the save point and compare
its `STRONG.SAV` with `tmp/orig_STRONG.SAV`.

## File APIs fail because DS:DX is not the DGROUP literal

The restored literals in `init_strong_sav` and `write_game_cfg` were correct but did
not create the folder, so the failure was probed directly:

| probe at the top of `init_game` | result |
|---|---|
| `mkdir("probe_dir")` | no directory |
| `creat("probe.txt",0)` + `write` + `close` | no file |
| `if (mkdir("probe_dir") == 0) while (1) ;` | program still returns to DOS, i.e. **mkdir returned an error** |

The library routine itself is fine - `_MKDIR` at `0000:05BD` is

```
55 8b ec            push bp / mov bp,sp
b4 39               mov ah,39h        ; DOS: make directory
8b 56 06            mov dx,[bp+6]     ; arg at +6 => a far call, args start there
cd 21               int 21h
72 04 ... 5d cb     jc error / ... / retf
```

which is exactly what a medium-model (`-mm`, far code) call produces: one near
pointer argument at `[bp+6]`, `retf` to return.  So the calling convention matches
our call; DOS is rejecting `DS:DX`.

That leaves the segment: at the moment `init_game` runs, `DS` is either no longer
DGROUP or the literal is not in DGROUP, so `DS:DX` points at the wrong bytes.  This
is consistent with every other file operation in the build failing (both
`init_strong_sav` and `write_game_cfg` reach their calls and get errors), and with
the fact that the same harness lets the original create its folder.

Next check: print/compare `_DS` inside `init_game` (e.g. `if (_DS != SEG_OF(GWorkDir))`)
and, if it differs, set `DS` to DGROUP before the file calls - a prior recovered
function that does far-data access (`_SS`/`_DS` casts appear throughout the export)
may be leaving DS changed.

## The startup probes are invalid now that the program exits by itself

`tmp/reach.py` works by patching a symbol's entry with `mov ax,4c21h / int 21h` and
treating "`DONE.FLG` was written" as proof the symbol was reached.  That was sound
while the rebuild hung (the only way to get `DONE.FLG` was to reach the patched
entry).  With the resident link the program returns to DOS on its own, so
`DONE.FLG` appears **whether or not** the patched entry is executed - every reach
result since then, including "`_INIT_GAME` not reached", is void.

The same caveat now applies to the hang probes:

```
probe_hang.py     while (1) {} at init_game's first line   -> program still returned
                 and the built image really contains it:  _INIT_GAME 105C:057D
                                                          55 8b ec 83 ec 04 eb fe
```

`eb fe` is `jmp $`, so the loop survived the optimiser, yet the program still
returned to DOS.  Combined with `startx` containing

```
startx+0369  9a 0e 00 4c 06   lcall 064C:000E   (= _MAIN)
```

the two facts cannot both be true unless the run used a different image than the
built one, or `main` is entered at a different address than `_MAIN`.

### Consequences

* re-do reachability with a marker that cannot be confused with a normal exit -
  for example exit with a distinct code and have `GO.BAT` branch on
  `if errorlevel`, or write a byte into video memory;
* check that `tmp/runcase.py` really runs the freshly linked
  `tmp/buildsrc/REBUILT.EXE` (the probe scripts link and then run, so this is the
  first thing to verify);
* only then re-test whether `init_game` runs, and only after that revisit the
  `mkdir`/`creat` failures - they were measured through the same probe harness.

## `mkdir` is bound correctly, but the path constant points nowhere

The rebuilt image has exactly two `mkdir` call sites, and both are plain library
calls:

```
0x55C02  83 ec 06 56 57 68 c2 a1 9a bd 05 00 00   push 0xA1C2 ; lcall 0000:05BD
0x55F47  fc 5f 5e c9 cb 68 fe a1 9a bd 05 00 00   push 0xA1FE ; lcall 0000:05BD
```

`0000:05BD` is `_MKDIR` (`mov ah,39h / mov dx,[bp+6] / int 21h / retf`), so the
symbol binding is right.

The pushed constants are not:

| value | maps into | contains |
|---|---|---|
| `0xA1C2` | `O02_SEG` (`091AA..0C8AD`, class CODE) | not a path |
| `0xA1FE` | same segment | not a path |

while the string literals really are in DGROUP:

```
"strong.sav" at link offset 0xA65E7  ->  DGROUP (_DATA 0xA5660..0xB073B) + 0x0F87
```

So `DS:DX` at the call points into a code segment at some unrelated offset, which is
why DOS creates nothing (and why `mkdir`'s error path can still leave `AX = 0`, so
the "success" seen by earlier probes was itself unreliable).

Using a DGROUP array instead of a literal does not help either:

```c
{ static char probe_path[] = "probe_dir";
  if (mkdir(probe_path) == 0) exit(23); }   /* reports success, no directory */
```

so the next measurement must be the segment actually in `DS` at the call - e.g.
`exit((_DS >> 8) & 0xFF)` and compare it with the segment list in `REBUILT.MAP`.
If `DS` is not DGROUP there, the module is running with its own data segment (the
original's overlay layout) and the fix is to establish DS per module or to make the
whole link use DGROUP for near data.

Reliable tooling from this round: `tmp/mark.py` (exit-code marker + `if errorlevel`),
`tmp/probe_mkdir3.py` (mkdir with a path argument), `tmp/probe_path.py` (DGROUP
array variant), `tmp/dirtest.py` (DOS-side `dir > DIR.TXT`).

## DS is DGROUP at both call sites, and the literal offsets are 0x10 out

Two exit-code probes (exit 23 when the condition holds, `GO.BAT` branching on
`if errorlevel 23`):

| condition | result |
|---|---|
| `_DS == 0xa566` at `init_game`'s first line | **true** |
| `_DS == 0xa566` at `init_strong_sav`'s first statement | **true** |

and the harness itself can create directories (`md probe_dir` in the same mount
produces `PROBE_DI`), so the mount, DOS `mkdir` and `DS` are all fine.

What is left is the pointer the compiler emitted. In the current image the DGROUP
copies of `"strong.sav"` are at

```
DGROUP +0F97  +8DF2  +A1D2  +A1DD  +A1FA  +A20E  +A219  +A22F
```

while the two `mkdir` call sites push

```
68 c2 a1   -> DGROUP +A1C2   ("Gold\0Fund\0Fund\0\0" - not a path)
68 fe a1   -> DGROUP +A1FE   (four bytes inside the copy at +A1FA)
```

`0xA1C2` is exactly `0xA1D2 - 0x10`, i.e. the module's literal offsets appear to be
computed against a near-data base that is 0x10 bytes lower than the one the linker
actually used.  That single 0x10 shift would make every string argument emitted by
that module point at the wrong bytes - which is consistent with `mkdir` "succeeding"
while nothing usable appears.

Next: confirm the shift by dumping the whole literal pool of `ovc31_config.c` and
comparing a few more pushed constants against their strings; if it holds, look for
the 0x10-byte object placed before the module's data in the link (`_CVTSEG` / heap
header) and either move it or align the module's data so the compiler's offsets
match.

## Corrected: the path constants are right; every DOS file call from the program fails

The `0x10` difference recorded above was an artefact of a **stale DGROUP base**: the
linker moved `_DATA` from `A5660` to `A5670`, and with the current base the pushed
constants resolve exactly to the strings:

```
push A1C2 -> DGROUP+A1C2: b'strong.sav\0strong.sav\\ga'
push A1E7 -> DGROUP+A1E7: b'%c\0strong.sav\\game.cfg\0s'
push A1FE -> DGROUP+A1FE: b'strong.sav\0strong.sav\\st'
push A21F -> DGROUP+A21F: b'strong.sav\\strong.$$$\0Pa'
push A235 -> DGROUP+A235: b'Path to write game data:'
```

So the pointers and the binding are fine, and so is `DS`:

| probe | result |
|---|---|
| `_DS == 0xa567` at `init_game` entry | true |
| `_DS == 0xa567` at `init_strong_sav` entry | true |
| `_DS == 0xa567` immediately before `mkdir("strong.sav")` | true |
| marker immediately before that `mkdir` | **reached** |

Yet nothing is created, and it is not the directory: `mkdir("C:\\pp")` and
`mkdir("pp2")` at the very start of `init_game` also produce nothing, while the
*batch* command `md probe_dir` in the same mount creates `PROBE_DI` immediately.
`creat` behaves the same way.

So **every DOS file/directory call made from inside the program fails**, regardless
of path and segment. The only unusual DOS call our startup makes is the memory
shrink in `crtl.c`:

```
/* INT 21h AH=4Ah with ES=PSP, BX=paragraphs.  CM.LIB's int86x hangs in
   ... */
mov ah,0x4a;
```

and the PSP/heap values it uses come from `_psp`, `_heaptop`, `_brklvl` (crtl.c:60,
64, 107).  A mis-sized shrink is the leading candidate: it is the one place where our
`startx` alters DOS's view of the process before any file call happens.

Next: compare that block against the original C0 (`tmp/asm_startx.txt`, 1000:0000) -
in particular the `ES`/`BX` values passed to `AH=4Ah` - and fix it so the process's
memory block ends where C0 leaves it.

## The AH=4Ah block matches C0, and even `fopen` loses its file

The original's memory shrink (from `tmp/asm_startx.txt`):

```
1000:007e  MOV BX,DI        ; DI = stack paragraphs
1000:0080  ADD BX,DX        ; DX = SS
1000:0082  MOV [0x89],BX    ; _heapbase.seg
1000:0086  MOV [0x8d],BX    ; _brklvl.seg
1000:008a  MOV AX,[0x7b]    ; _psp
1000:008d  SUB BX,AX        ; BX = (sseg+paras) - psp
1000:008f  MOV AX,ES
1000:0091  MOV AH,0x4a      ; AH=4Ah, ES=PSP
1000:0093  PUSH DI
1000:0094  INT 0x21
```

and `crtl.c:108..118` computes the same `BX = sseg + paras - psp` with `ES = psp`,
so the shrink is **not** the fault - that hypothesis is retired.

What the latest probes show instead:

| probe at `init_game`'s first line | result |
|---|---|
| `mkdir("C:\\pp")` / `mkdir("pp2")` | nothing created |
| `creat("probe.txt",0); write; close` | nothing created |
| `fopen("pp3","wb"); fputs; fclose` | **reports success**, nothing created |
| `exit(getdisk() + 0x30)` | errorlevel >= 50, i.e. the drive is C: |

So the C library believes every one of those calls succeeded, the current drive is C:,
the batch's own `md probe_dir` in the same mount does create `PROBE_DI`, and the
original `game/STRONG.EXE` in the same harness does create its `strong.sav` folder -
but no file or directory created *by our program* ever appears.

That is no longer consistent with a decompilation defect in the file API path: the
path string, `DS`, the `_MKDIR` binding, the drive and the mount are all verified.
It points at the process environment DOS sees for our EXE (PSP / job file table /
current directory block), which our `startx` reconstructs rather than inheriting from
C0's `_startup`, or at a write-redirection in the modded emulator that keys on
something about the program image.

## The emulator is exonerated; the DOS file layer is called with the wrong convention

Running the same binary under a **stock** DOSBox-X (`C:\soft\dosbox\dosbox-x.exe`)
with the identical mount reproduces the modded emulator exactly:

```
OK.FLG present  (the program reached the probe and exited)
PP3             absent from the host listing and from DOS's own `dir`
```

and the DOS-side test is the decisive one:

```c
f = fopen("pp4","wb"); fputs("x",f); fclose(f);
if (fopen("pp4","rb") != 0) exit(23);   /* taken */
```

The program's re-open **succeeds**, yet DOS's `dir` (written by the batch right after
the program exits) shows no `PP4` at all.  So the C runtime reports success without
DOS ever creating the file - and this is identical under both emulators.

### Why: the library routine pops its own arguments

`_OPEN`/`_CREAT` in the linked library starts at `0000:17E3`:

```
55 8b ec            push bp / mov bp,sp
8b 4e 04            mov cx,[bp+4]
b4 3c               mov ah,3ch
8b 56 06            mov dx,[bp+6]
cd 21               int 21h
72 02  eb 04        jc / jmp
50 e8 89 ed         push ax ; call error helper
5d c2 04 00         pop bp ; **ret 4**     <- callee pops the arguments
```

`ret 4` means the *callee* discards two argument words - a pascal-style convention -
while our translation units call it cdecl, whose caller also pops.  Every such call
therefore removes four extra bytes from the caller's frame (and the error path returns
`AX` from the helper rather than -1), which explains both the "success" that creates
nothing and the corrupted state after the call.

Next: establish which convention the header actually declares (`__pascal`,
`_Cdecl`, `__cdecl16far` are all empty macros in `st_compat.h`) and link the library
that matches the compiled objects, or fix the prototypes so cdecl is used on both
sides.  The acceptance test is the existing one: `fopen("pp4","wb")` must make `PP4`
appear in DOS's `dir`.

### The convention is not the cause either

Calling the same routine through a pascal-typed pointer

```c
extern int creat(const char *, int);
int (pascal *pc)(const char *, int) = (void *)creat;
h = pc("pp5", 0);
```

still reports `h >= 0` and still creates nothing (`PP5` appears neither on the host
nor in DOS's own `dir`).  So argument order and stack cleanup are not the defect;
the routine returns a plausible handle without DOS ever making the file, for both
conventions and under both the stock and the modded emulator.

What is proven so far about this call path:

| property | state |
|---|---|
| mount writable / DOS `md` works | yes (`PROBE_DI` created by the batch) |
| original game creates its `strong.sav` directory | yes |
| path string, `DS`, `_MKDIR` binding | verified correct |
| current drive | C: |
| emulator (stock DOSBox-X, same mount) | same behaviour -> exonerated |
| cdecl vs pascal argument order | both "succeed", neither creates the file |

The remaining difference between our process and a normal DOS program is the
environment `startx` builds (PSP -- `_psp` is set from a stack argument --, heap
base, break level and the memory shrink).  A wrong PSP would make DOS resolve the
batch's working directory and the program's relative path differently, which fits
every observation: the call "succeeds" (DOS is given a path in a segment that is not
the current directory) yet nothing lands where we look.

## PSP capture, corrected measurement

There is no duplicate symbol: the MAP has a single `_PSP` at `A566:0090`, written
only by `crtl.c` (`psp = _ES;  ...  _psp = psp;`).

The first capture attempt was invalid: it stored `GPspSig*` **before**
`asm { mov ax, seg DosVersion; mov ds, ax }`, so with `DS = PSP` those writes landed
in the PSP segment instead of DGROUP and the later read saw zeros.  Repeating the
capture *after* the DS switch still reports a non-`CD 20` word at `PSP:0000`, and an
earlier probe (measuring `_ES` at `init_game`) showed that by then `ES` *does* point
at a `CD 20` area.

So the two measurements disagree only because they are taken at different times:

| measurement | result |
|---|---|
| `_ES` at `init_game` (early probe) | points at `CD 20` |
| `psp` captured at `startx` entry, read after DS switch | not `CD 20` |
| header entry | `01B2:0034` = `_STARTX` (correct) |

Next: encode the captured value in an exit code - `exit((_psp >> 8) & 0xFF)` and
`exit(_psp & 0xFF)` in two runs - so the actual segment is known, then read the bytes
at that segment and compare with the PSP DOS reports (INT 21h AH=51h).  That will
show whether `_ES` at entry is stale (e.g. the loader's own segment) or whether the
capture is overwritten before `init_game`.

## The handle table is fine; errorlevel probes are unreliable

`_nfile` (the CRT's file-handle count) reads **20** in the running build, i.e. the
library data is initialised and the table is not the cause of the "success without a
file" behaviour.  An earlier reading of `< 5` came from an `if errorlevel` probe and
was wrong: once the program can exit on its own, `errorlevel` can be stale or set by
something other than our `exit()` code, so **exit-code probes are only trustworthy
when the DIR/file checks agree**.

That leaves the file-layer question open again, with these facts established by
observation rather than by inference:

* mount writable, DOS `md` works, original game creates its folder;
* path string / `DS` / `_MKDIR` binding / drive / `_psp` (now from `AH=51h`) all
  verified;
* emulator exonerated (stock DOSBox-X identical);
* `_nfile` = 20, so the handle table is initialised;
* `fopen`/`creat`/`mkdir` all report success while DOS's own `dir` shows nothing.

The next measurement should therefore read the **actual DOS return** (CF/AX) of one
INT 21h AH=3Ch call, by capturing AX into a file the batch can see or by branching on
it *inside* the program and writing the branch result through the batch - not by
`errorlevel`.

## The program cannot write to its own standard handles

A probe that avoids `errorlevel` entirely - raw `INT 21h AH=3Ch` in a helper whose
return is printed - showed nothing at all, and the printed text itself never reached
the redirect:

```c
write(1, "HI\n", 3);      /* stdout is redirected to OUT.TXT by the batch */
write(2, "ERR\n", 4);
exit(0);
```

`OUT.TXT` is **0 bytes**.  So it is not the file-create call that is broken: the
program cannot write to handle 1 (or 2) either, and `printf` output is lost the same
way.

Initialising the CRT handle table in `startx` (what C0's `__initio` would do):

```c
_nfile = 20;
for (i = 0; i < 20; i++) __openfd[i] = (i < 5) ? i : 0xFF;
```

does **not** change that - `OUT.TXT` stays empty - so the table contents are not the
missing piece either.

That reframes the whole file-layer thread: every DOS-level operation from this
program (open, create, mkdir, write to stdout) silently does nothing while the C
library reports success, under both emulators.  The next thing to verify is therefore
not the file API but whether `INT 21h` from our program reaches DOS at all when
`AH >= 3Ch` (e.g. an interrupt hook installed by `startx`'s `SaveVectors` for
vectors 0/4/5/6, or ES/DS assumptions inside the library's DOS entry).  A minimal
test is a raw `INT 21h AH=09h` (print string) with a DGROUP string - if that prints
and `AH=40h` on handle 1 does not, the handle path is the problem; if neither prints,
the interrupt path is.

## Control test: the harness captures DOS output; our EXE produces none

A hand-assembled 22-byte `.COM` in the same mount and the same `GO.BAT` shape:

```
BA 0C 01   mov dx,0x010C     ; -> string
B4 09      mov ah,9
CD 21      int 21h
B8 00 4C   mov ax,4C00h
CD 21      int 21h
HELLO$     ...
```

prints `HELLO` into `OUT.TXT`.  So the emulator, the mount and the redirect are all
fine (`tmp/comtest.py`).

The identical call - `INT 21h AH=09h` on a DGROUP `$`-string - produces **nothing**
when issued from our EXE, at `init_game`'s first line *and* at `main`'s first line.
Since the harness demonstrably captures the same interrupt from a `.COM`, the
conclusion is that our program does not reach those points at all: it stops inside
`startx`.

That also explains every earlier "it runs" result: `DONE.FLG` is written by the batch
whenever control returns to the shell, **including after a crash**, and the
`if errorlevel` probes can then observe a stale code.  The only trustworthy signals
are side effects a program must actively produce - a printed string, a created file,
a changed screen.

### Next step

Put the `INT 21h AH=09h` probe in `startx` immediately after
`asm { mov ax, seg DosVersion; mov ds, ax }` (with a file-scope
`char st_sx[] = "STARTX$";` so the operand is a plain symbol):

* if `STARTX` appears, `startx` reaches the DS switch and DOS works from our process -
  narrow forward from there;
* if it does not, the program dies at or before that point, and the entry patch
  (`_STARTX 01B2:0034`), the linked startup objects or `startx`'s first pages are the
  place to look.

### Even at `startx`'s DS switch the program prints nothing

With a file-scope `char st_sx[] = "STARTX$";` and

```
asm { lea dx, st_sx
      mov ah,9
      int 21h }
```

placed immediately after `asm { mov ax, seg DosVersion; mov ds, ax }`, `OUT.TXT`
stays empty - while the `.COM` control prints through the same harness.

The EXE header gives `SS:SP = B0F1:0080`, i.e. a 128-byte initial stack, and our
decompiled `startx` has a large C frame, so stack overflow was the natural suspect.
Raising the header SP to `0xF000` in the run copy changes nothing, so that is not it
(or not only it).

Conclusion: the program does not reach the instruction after the DS switch.  Either
it dies in the first few instructions of `startx` (prologue / `&errno` computation /
`psp = _ES`), or the entry never gets there at all.

### Next measurement

Put the print **before any C code**: an assembly entry stub

```
        public _st_entry
_st_entry proc far
        push cs
        pop ds                 ; DS = ?? (need a valid segment for the string)
        ...int 21h AH=09h...
        jmp far _STARTX
_st_entry endp
```

in `ovr_thunks.asm` (TASM is part of the build), patch the header entry to it, and see
whether the stub prints.  If it does, the fault is between the stub and the C
`startx` prologue (i.e. our `startx` frame/first statements); if it does not, the
problem is in how the EXE is loaded at all (header/segment layout), independent of
the recovered code.

### A pure-assembly entry stub prints nothing either

An assembly stub (`ovr_thunks.asm`, TASM is part of the build)

```asm
_ST_ENTRY proc far
    push cs
    pop ds
    mov dx, offset st_msg
    mov ah, 9
    int 21h
    jmp far ptr _STARTX
_ST_ENTRY endp
st_msg db 'ENTRY$'
```

was placed at `06DA:0917` and the EXE header's `CS:IP` was patched to it.  `OUT.TXT`
stays **empty** - the stub does not even print - while the `.COM` control does.

The header itself is structurally sane:

```
magic 5A4D  cblp 0156  cp 05E9  crlc 12515  cparhdr 0CA0 (=51,712-byte header)
minalloc 0083  maxalloc FFFF  ss B0F0  sp 0080  ip 0034  cs 01B2  lfarlc 003E
file 774,486 bytes
```

So: header parses, the image is complete, the entry points into the image - and yet
nothing at the entry executes (or its DOS call produces nothing).

### Conclusion for this thread

Every code-level probe has now been exhausted: the failure is either in how the
loaded image executes (relocation/segment layout produced by our custom link step) or
the emulator rejects/mis-loads this particular EXE in a way that produces no message.
No further source-level experiment can distinguish those; the next step must be
observational at the loader level - e.g. run the EXE under a DOSBox-X build with its
debugger enabled and read `CS:IP`/memory at the first instruction, or compare our
EXE header/relocation table byte-for-byte with the original `game/STRONG.EXE`
(12,515 relocation entries and a 51 KB header are unusual and worth checking against
the original's numbers).

## Root cause of everything since the resident link: the image does not fit in 640 KiB

```
file total     774,470
header          51,712   (12,515 relocations)
image          722,758
minalloc         2,096
needed RAM     725,110   <- conventional-memory limit is 655,360
over limit      69,750
```

A real-mode DOS program must load entirely below 640 KiB.  Ours needs 725,110
bytes, so **DOS cannot load it**: the shell prints its error to the console (not to
the redirected handle), returns to the batch, and `DONE.FLG` is written - which is
exactly the pattern that earlier looked like "the program runs and returns to DOS".

That single fact explains every negative result of the last several turns:

* no output from `printf`/`write`/`INT 21h AH=09h`, even from a self-contained
  assembly entry stub - the stub is never loaded, let alone executed;
* no file or directory created by the program, while the batch's `md` works;
* `errorlevel` and `DONE.FLG` observations that disagreed with each other;
* why enlarging the header SP, fixing `_psp`, `_nfile`, the calling convention and
  the emulator all changed nothing.

It also retires the "resident link made it run" claim: the resident link is what
pushed the image from 511 KB (the original, with overlays) to 722 KB.

### Implications for the build

The step-6 build has to satisfy two constraints at once:

1. the image must fit below ~600 KiB to load, and
2. the game modules must be reachable (the old `/o` overlay link bound the generated
   thunks to `INT 3Fh` stubs, which is why it hung instead).

Options, in order of effort:

* **shrink the resident image** by ~70 KB - e.g. build only the modules the startup
  path needs, drop the 46 duplicated CRT stubs, compile with size optimisations.
  The acceptance test is unchanged and now unambiguous: a `MINIMAL$` print from an
  entry stub, or `strong.sav\` appearing;
* **restore the overlay link and provide a minimal overlay loader** that maps each
  overlay segment from the EXE on demand and patches the thunk table, replacing the
  VROOMM manager that is compiler-supplied but absent here.

## The overlay link loads (134 KB image) but a simple loader cannot work

Linking with TLINK `/o` (`WITH_OVERLAY=1`) gives:

```
file            751,248
loaded image    134,416      -> needs 134,672 bytes of RAM (limit 655,360)
overlay code    612,736      (after the image; VROOMM pages it in)
```

So the overlay build **does** fit and does load — which is consistent with it
reaching `main`/`init_game` in the earlier probes, and stopping only when a thunk
jumped into the `INT 3Fh` stub table.

The obvious repair - "map each overlay segment in on demand" - does not work for
this image: every overlay segment has its **own linked segment number**
(`O01_SEG 20D30H`, `O02_SEG 222C0H`, ... in the MAP), and the compiled code inside it
contains absolute far addresses to that segment.  Paging segments into a shared
buffer would break every pointer inside them, so a loader would have to keep the
whole 612 KB resident - which is the same 640 KiB problem again.

### What that leaves

The image has to be made smaller at the source/link level:

* link only the modules reachable from `main` -> `init_game` -> the save path, and
  generate return-0 stubs for the rest (the build already has a stub generator for
  unresolved symbols, `scripts/model/unresolved.tsv`);
* or reduce the decompiled code size (the bloat is in the exported expressions, e.g.
  `CONCAT22`/`CONCAT13` chains, not in the data).

Either way the acceptance test is unchanged and unambiguous: the `ENTRY`/`MINIMAL$`
print from an entry stub, or `strong.sav\` appearing.

## Proof of the size root cause: exclude two modules and the program actually runs

Linking without `o45.obj` and `o49.obj` (`EXCLUDE_OBJS`):

```
file          645,278
image         606,366
needed RAM    608,734      (limit 655,360 - margin 46,626)   ✓ fits
```

and the behaviour changes in exactly the way the diagnosis predicts:

| build | harness result |
|---|---|
| resident, all modules (needed 710,908) | batch completes: `DONE.FLG` written, nothing created |
| resident, minus o45/o49 (needed 608,734) | **batch never completes**: no `DONE.FLG`, no `DIR.TXT` |

A program that DOS refuses to load returns immediately to the shell; a program that
loads runs.  The second build is the first one in this whole investigation that
actually executes, and it now hangs (or waits) instead of being rejected - so
"over 640 KiB" was indeed the reason nothing ever ran.

`strong.sav` is still not produced, which is expected: TLINK reported the excluded
modules' entry points as **undefined** and resolved them to address 0, so the first
call into one of them crashes.  The next step is therefore to give those symbols real
return-0 stubs instead of excluding them silently:

* the linker prints the exact list (`_OVC45_COMPUTE7`, `_OVC49_BODY1`, ... in
  `OVR.ASM`), and `scripts/model/unresolved.tsv` already tracks this class;
* generating a C file with those names as empty bodies keeps the image small and
  makes the calls harmless, after which the startup path can be walked forward with
  the `INT 21h AH=09h` print probe (which is now trustworthy because the program
  really loads).

## The program loads and runs: `ENTRY` prints, `startx` starts

With the image at 516,016 bytes (needed 518,368), the self-contained assembly entry
stub now prints:

```
ST_ENTRY at 06C6:091B
OUT.TXT: 'ENTRY'      entry stub ran: True
```

So the rebuilt EXE loads, executes its entry point, and can write to the redirected
handle - the first time any of that has been demonstrated.

The `startx` marker still prints nothing, and the entry bytes are confirmed correct
in the image:

```
entry 01B2:0041 -> 55 8b ec 83 ec 1a 56 57 b8 94 00 40 89 46 f4 b4 ...
                   push bp / mov bp,sp / sub sp,0x1a / push si / push di / ...
```

That is `startx`'s own prologue, so the entry is right.  The most likely reason the
marker fails is the marker itself: its asm block does

```
asm { lea dx, st_s1 ; mov ah,9 ; int 21h }
```

with `DS` loaded from `seg DosVersion`.  If `DosVersion` is not in DGROUP, `DS` is not
DGROUP and the string address is wrong - the print then emits garbage rather than
`S1:`.  A stack/segment patch (SS, SP, minalloc=0x1000) changed nothing, which is
consistent with a marker bug rather than a program fault.

Next: repeat the marker with the string in the **code** segment (`push cs / pop ds`
plus an asm-level `db 'S1:$'`), the same technique the ENTRY stub proved works.  Only
once that prints can the walk continue into `init_game`.

## `startx` runs, but it never reaches `main`

Markers were implemented as far asm routines in `ovr_thunks.asm` that print a
**code-segment** string (`push cs / pop ds` + `db 'S1:$'`) - the technique the ENTRY
stub proved works; the earlier marker failed only because it used `seg DosVersion` to
load `DS`.

Results with the loading build (516,016-byte image):

```
OUT.TXT: 'S1:'
S1 (startx, after the DS switch)   printed
S3 (main, first statement)         not printed
S2 (init_game, first statement)    not printed
```

So execution enters `startx` and stops **inside `startx`, before it calls `main`**.
No game code has run yet - which also means the 47 return-0 stand-ins are not
implicated in the current failure.

Remaining suspects, in `startx` order:

1. `SaveVectors()` (installs vectors 0/4/5/6);
2. the heap setup (`_heapbase`, `_brklvl`, `__stklen`);
3. the `AH=4Ah` memory shrink;
4. the stack switch (`cli / mov ss,dx / mov sp,di / sti`) - the most dangerous, and the
   one piece of hand-written asm in the path;
5. the `fixFarTable` / initialisers that follow.

Next: put markers between those statements (they can reuse the same asm routine
pattern), and the first one that is missing names the defect.

## Bisection inside `startx`: the stop is between the DS switch and `SaveVectors`

Four markers (code-segment strings, same proven pattern) were placed in `startx`:

| marker | position | printed |
|---|---|---|
| S1 (earlier probe) | after the DS switch, before the PSP reads | **yes** |
| A | after `SaveVectors()` | **no** |
| B | after `_brklvl` (heap setup) | no |
| C | before the stack switch (i.e. after the AH=4Ah shrink) | no |
| D | after the stack switch | no |

`OUT.TXT` is empty, so even A is not reached.  That narrows the fault to the five
statements between S1 and A (`crtl.c:61..66`):

```
uVar17 = *(uint16_t far *)MK_FP(psp, 0x2c);   /* environment segment */
iVar10 = *(uint16_t far *)MK_FP(psp, 0x02);   /* top of memory */
_envseg_at_ = uVar17;
_heaptop.seg = iVar10;
asm { mov ah,0x30; int 21h; mov word ptr DosVersion, ax };
SaveVectors();
```

The two `MK_FP` reads and the `AH=30h` call cannot hang; `SaveVectors()` - the
recovered routine that installs vectors 0/4/5/6 through `INT 21h AH=25h` - is the only
candidate, and a wrong `DS:DX` there would hand DOS a bad handler (a divide-error
vector pointing at garbage kills the program on the first hardware interrupt of any
kind).

Next: put one marker immediately **before** `SaveVectors()` and one **after** it (the
latter already exists as A) to confirm, then inspect `SaveVectors()` against the
original's `1000:017a` and fix its pointer setup.

## Correction: `SaveVectors()` is fine; the stop is after it

The previous bisection (markers A-D all silent) was an artefact of that probe, not of
the program.  Re-running with a marker immediately **before** and **after**
`SaveVectors()`:

```
OUT.TXT: 'E:A:'
```

Both print, so `SaveVectors()` - the `INT 21h AH=35h/25h` sequence that saves vectors
0/4/5/6 and installs `ZeroDivision` - completes normally.

The stop is therefore further along `startx`, in the block that follows:

```
crtl.c:71  pcVar4 = (char *)*(uint32_t *)&_env;      /* environment scan setup */
crtl.c:76  L_startx_0034:  do { ... } while (...);   /* up to 0x7fff iterations */
crtl.c:88  _envSize_at_ = ...;
crtl.c:89  if (__stklen < 0x200) ...
crtl.c:106 _heapbase.seg / _brklvl.seg
crtl.c:113 asm { mov ah,0x4a; int 21h }               /* shrink */
crtl.c:125 asm { ... mov ss,dx ; mov sp,di ... }      /* stack switch */
```

The environment scan is a `do/while` bounded by `uVar8 = 0x7fff`; if `_env` or the
environment block is not what the code expects, it burns the loop and then hits
`L_startx_007B: _abort()` - a clean exit that looks exactly like "the program stopped".

Next: markers after the scan (line 88) and after the heap/shrink/stack block
(line 136).  Those three points separate a hang from an `_abort()`.

## startx: everything up to the initialiser block works

Three markers in the post-`SaveVectors` region (`crtl.c:88`, `:119`, `:135`):

```
OUT.TXT: 'X1:X2:X3:'
```

| marker | position | printed |
|---|---|---|
| E / A | before / after `SaveVectors()` | yes / yes |
| X1 | after the environment scan (`_envSize_at_`) | yes |
| X2 | inside the heap block, after `__stklen` setup | yes |
| X3 | after the stack switch (`cli / mov ss,dx / mov sp,di / sti`) | yes |
| M | immediately before `iVar10 = main(...)` | **no** |

So the environment scan terminates, the heap values are computed, the `AH=4Ah` shrink
runs and the **stack switch works**.  The stop is in the block between X3 and the call
to `main` (`crtl.c:195..283`), which contains:

```
_setupio();          /* CRT stdio/handle-table initialisation       */
_c0crtinit();        /* CRT initialisers                             */
{ ... argv[0]/argv[1], __C0argc/__C0argv/__C0environ ... }
fixFarTable(...) x 28
```

`_setupio()` is the prime suspect: every file/stdio operation in this build has been
observed to fail silently, and `_setupio` is exactly the routine that establishes the
handle table those calls depend on.

Next: markers after `_setupio()` and after `_c0crtinit()`; that separates CRT
initialisation from the far-table fix-ups in one run.

## The stop is `_setupio()`

Two markers around the CRT initialisers in `startx`:

```
OUT.TXT: ''          -- neither IO: (after _setupio) nor CI: (after _c0crtinit) printed
```

So `startx` reaches the initialiser block (X3 printed) and dies inside
**`_setupio()`** (`crtl.c:2030`), before `_c0crtinit()` is even called.

`_setupio` is the routine that sets up the CRT stream/handle tables:

```c
i = 5;
if (5 < _nfile) {
  do {
    ((uint16_t *)_openfd)[i] = 0;
    *(undefined1 *)((int)&_streams[0].fd + i * 0x14) = 0xff;
    *(int *)((int)&_streams[0].token + i * 0x14) = i * 0x14 + -0x79da;   /* magic base */
    i = i + 1;
  } while (i < _nfile);
}
uVar1 = _isatty(0);
...
setvbuf(_streams, 0, ..., 0x200);
```

It writes through `_streams` with a hard-coded `0x14` stride and a hard-coded
`-0x79da` token base - both suspicious decompiler artefacts.  A wrong base or stride
writes outside the stream table, and the next `_isatty`/`setvbuf` call then operates on
corrupted state; that is also consistent with every stdout/file operation in this
build having failed silently.

This ties the two threads together: **the file/stdio failures and the stop before
`main` are the same defect** - the CRT stream table is mis-modelled.

Next: dump `_setupio` from the original C0 (`1000:0xxx`, near `SaveVectors` at
`1000:017a`) and rebuild the stream-table arithmetic from it (`_streams`, `_openfd`,
the 0x14 stride and the token base), then re-run the markers - IO: and CI: should both
print, and `main` should follow.

## Linking the stock Turbo C CRT instead of the reconstructed `crtl.c`

Per AGENTS.md the C runtime is supplied by Turbo C (it matches the original), so the
`startx()`/`_setupio()`/CRT work in this document is out of scope and was stopped.
Switching the link to the stock CRT is a single switch - `link_standalone.py
--without-crtl` drops `CRTL.OBJ` so `C0M.OBJ`'s own `_startup` runs - and it fails on
exactly two things:

```
Error: Undefined symbol _LMOD_AT_ in module O21.C
Error: Fixup overflow at _TEXT:0323, target = __REALCVT
       in library file d:\lib\cm.lib in module VPRINTER
```

1. `_LMOD_AT_` (and whatever group of symbols `ovc21_manage.c` takes from the
   reconstructed startup) must come from the stock CRT or be supplied beside it.
2. The `__REALCVT` overflow is the known floating-point-emulator issue: `printf %f`
   pulls in VPRINTER, which needs the emulator library, and our rsp does not link it.

`link_standalone.py` also crashed in its relocation post-processing on that build
(`struct.error: ushort format requires 0 <= number <= 65535`), so the no-crtl path
cannot be evaluated until that is guarded.

Next: add the FP emulator library to the no-crtl rsp and supply/relocate the handful of
symbols the game code takes from the reconstructed startup, then the whole `crtl.c`
module can be dropped - which is both the correct scope and the shortest path to a
working program, since the stock CRT's `startx`/`_setupio` are known-good.

## Dropping the reconstructed CRT: not 4 RTL symbols

Excluding `CRTL.OBJ` (stock `C0M` startup, `--without-crtl`) and adding stand-ins for
the first four helpers did not converge - the next link reported **22** undefined
symbols:

```
__FAKREALCVT   _PADD_AT_      _EMSFREE      _XMSFREE
_AUDIO_DONE    _SRAND8        _LDIV_AT_     _LXMUL_AT_
_F_SCOPY       _AUDIO_INIT    _LXRSH_AT_    _LXURSH_AT_   ...
```

None of them exist in any BC30 library (`tools/BC30/LIB/*.LIB` was scanned).  They are
Borland C0/RTL internals that the original build obtained by linking its own CRT
objects - i.e. exactly the code AGENTS.md says is Turbo C's, and which the open-source
CRT provides.

Also unresolved: the `__REALCVT` fixup overflow in `CM.LIB`'s VPRINTER survives
`EMU.LIB` in either position (`CM EMU`, `EMU CM`) and `FP87.LIB`.

So "drop `crtl.c`" is not a switch, it is an import job: take the CRT sources, build
the RTL objects this image needs, and link those instead of the reconstruction.  The
tree is restored to the working link (reconstruction included) so the gates stay green
while that is done.

  build 64/64 clean; link 0 errors; grep_checks 51,169
  compare_state 1,627/0/0; diff_dgroup 972/1,868

## The CRT sources are in the tree (tools/BC30/CRTL), but the names do not match

`tools/BC30/CRTL` holds a real source tree - `CLIB\F_SCOPY.ASM` (1,488 bytes),
`CLIB\H_LDIV.ASM`, `CLIB\H_PADD.ASM`, `CLIB\F_LXMUL.ASM`, `CLIB\ACCESS.C`, ... -
plus `tools/BC30/LIB/STARTUP/C0.ASM`.  (The `.ASM` files at the CRTL root are 1-byte
placeholders; the real ones are under `CLIB`.)

Looking up the symbols the stock link reported missing:

| symbol | source file found |
|---|---|
| `_F_SCOPY` | `CLIB\F_SCOPY.ASM` |
| the other 18 | none by that name |

Two conclusions:

* the CRT sources are the right import, but the linker's symbol names do not match the
  source identifiers (`H_LDIV.ASM` declares its entry with a different spelling, and
  several are model-specific variants), so the mapping has to be built by reading each
  candidate source's `public`/`proc` line rather than by filename or grep;
* some of the reported names look like **game** symbols, not CRT ones
  (`_AUDIO_INIT`, `_AUDIO_DONE` live in `ovc11_audio.c`), which means that list came
  from a stale `LINK.LOG`.  The next attempt must capture a fresh log before mapping
  anything.

`tmp/crt_lookup.py` does the name scan; it needs extending to parse `public`/`proc`
declarations and to be run against a fresh link log.

  tree restored to the working link; grep_checks 51,169; compare_state 1,627/0/0

## Fresh stock-CRT link: 28 symbols, only 2 of them CRT

A fresh `--without-crtl` link (so the earlier stale log is retired) reports **28**
undefined symbols.  Mapping them against every `public`/`proc` name in
`tools/BC30/CRTL/**/*.ASM` (new `tmp/map_crt.py`) gives:

```
_F_SCOPY    -> CLIB\F_SCOPY.ASM
__FAKREALCVT-> CLIB\CVTFAK.ASM
26 others   -> no shipped source
```

And the other 26 are not CRT at all - they are functions that currently live in
`crtl.c` but belong to the game/utility side:

```
crtl.c:488  audio_init()      crtl.c:637  stshInit_scan()
crtl.c:502  audio_done()      crtl.c:658  ems_init()
crtl.c:514  xms_init()        crtl.c:4324 _sprintf()
... plus LDIV/LMOD/LXSH/LXMUL/LXRSH/LXURSH/PADD/RAND8/SRAND8/FSTRNCPY/IOERRORHNDLR
```

So `crtl.c` is a mixed module: Turbo C's C0/startup (out of scope) **plus** a set of
utility routines that the recovered game code actually calls.  Dropping the whole file
therefore removes game functionality, which is why the link fails - not because the CRT
is missing.

### The refactor this implies

1. split `crtl.c` into `crtstart.c` (startx / _setupio / _c0crtinit / SaveVectors /
   __cleanup - the C0 part) and `util.c` (the audio/xms/ems/stsh helpers, the LMOD /
   LSH / LMUL / PADD / RAND8 / FSTRNCPY family and `_sprintf`);
2. link with `--without-crtl` so `crtstart.c` is not needed at all, and let C0M's
   `_startup` run;
3. assemble the two genuinely-CRT pieces from the shipped sources
   (`CLIB\F_SCOPY.ASM`, `CLIB\CVTFAK.ASM`).

That satisfies AGENTS.md (no reconstructed C0) without losing game code, and it is a
mechanical file split rather than new recovery work.

  working link restored; grep_checks 51,169; compare_state 1,627/0/0

## Why the stock startup stalls: our `_setupio` overrides the CRT's

`_streams` is *our* data (`st_globals5.c:1753`, a 20-entry FILE table matching the
original image), but `_setupio` - the routine that initialises it - is defined in
`crtl.c`.  When `CRTL.OBJ` is linked together with `C0M.OBJ`, the linker resolves
C0's `call _setupio` to **our** implementation, which is the one that hangs.  That
explains the otherwise puzzling observation that the stock startup stalls before its
`lcall _main` at `0x7955`: the CRT never gets past its own stream initialiser.

The obvious one-line test - rename our function so it no longer shadows the CRT's:

```
_setupio -> st_setupio   (3 occurrences in crtl.c)
```

was applied and reverted: with `STOCK_STARTUP=1` the link then reported other
undefined symbols (`__FAKREALCVT`, `_PADD_AT_`, `_EMSFREE`, ...), i.e. the rename
alone does not produce a linkable configuration, because the same link still expects
those helpers from somewhere else.

Conclusion: the shadowing diagnosis stands, but the fix is the full split (move the
utility routines into their own module so `crtl.c` can be dropped entirely), not a
rename.  Tree restored to the working link.

  build 64/64 clean; link 0 errors; grep_checks 51,169; compare_state 1,627/0/0

## Instrumented C0 from its shipped source: startup never reaches `call _main`

`tools/BC30/LIB/STARTUP/C0.ASM` is the real startup source (`STARTX PROC NEAR` at line
106, `call _main` at line 409) and Borland's own recipe assembles it:

```
TASM /M /MX /Q /T /D__MEDIUM__ /IE:\LIB\STARTUP c0prb.asm
```

An instrumented copy with a code-segment marker (`push cs / pop ds / db 'S:$' /
int 21h`) immediately **before** `call _main` assembles to `C0PRB.OBJ` and links in
place of `C0M.OBJ` (`link_standalone.py` now honours a `C0OBJ` override):

```
link: entry left at C0's _startup · REBUILT.EXE 546,752
run:  OUT.TXT = ''      reached call _main: False
```

So with the stock startup in the image, control **never reaches C0's call to `main`** -
the stall is inside C0 before that call, not in `main` and not in the call frame.

A follow-up probe with the marker at `STARTX`'s first instruction produced no output
either, but the assembled object did not change size, so that run is not trustworthy
and must be repeated with the TASM log captured.

Tree restored (instrumented object removed, default link rebuilt); gates green.

  grep_checks 51,094; compare_state 1,627/0/0; diff_dgroup 972/1,868;
  compare_runtime 1,543/13

## CORRECTION: the stock startup DOES reach `call _main`

The earlier conclusions in this document that "startup never reaches `lcall _main`" and
that "`S:` never prints" are **withdrawn**.  They were measured by writing markers with
`INT 21h AH=09h` to stdout redirected by the DOS shell (`STRONG.EXE > OUT.TXT`).  That
redirect is only *closed* when the process ends, so a program that hangs leaves
`OUT.TXT` at 0 bytes even though the marker ran - and a missing `DIR.TXT` in the run
directory shows the batch indeed never regained control.

A marker that opens a file, writes and **closes** it (`AH=3Ch` / `40h` / `3Eh`) is
durable across a hang.  Instrumenting the shipped `C0.ASM` (`tools/BC30/LIB/STARTUP`,
`TASM /M /MX /Q /T /D__MEDIUM__`) with four of them and linking it as the C0 object
(`C0OBJ=C0PRB.OBJ`, `STOCK_STARTUP=1`):

| marker | placed at | file created |
|---|---|---|
| 1 | first instruction of `STARTX` (entry point) | `MK1.TXT` = 1 |
| 2 | immediately after `call StartExit` | `MK2.TXT` = 2 |
| 3 | immediately before `call _main` | `MK3.TXT` = 3 |
| 4 | immediately after `call _main` | **missing** |

So with the stock startup the program runs C0's initialisation **and calls `main`**.
`main` is entered and does not return (marker 4 absent), which is expected for a game
loop that waits for input - not a startup defect.

Also worth recording: C0 does not call `__setupio` directly.  It calls `StartExit`
(line 395), which walks the `InitStart..InitEnd` table in DGROUP; `__setupio` (declared
`extrn __setupio:near ;required!` at line 67) is registered there.

The next question is therefore inside game code, not in the CRT: instrument `main`'s
first statement and `init_game` with the same closing-file marker to see how far the
game runs.  The startup path is no longer a blocker.

  grep_checks 51,094; compare_state 1,627/0/0; diff_dgroup 972/1,868

## The game now runs: main -> init_game -> init_base (stall in init_check_mem)

With the startup question settled (previous section), the remaining chain was walked with
the same durable file markers:

| stage | marker | result |
|---|---|---|
| `main` body | MK5 (C, first statement) | reached |
| `init_game` | MK6 (before `_OvrInitExt(0,0)`) | reached |
| after `_OvrInitExt` | MK7 | reached only after the fix below |
| after `_OvrInitEms` | MK8 | reached |
| after `ovr_init_base()` | MK9 | **missing** |
| inside `init_base` | MK20 (entry) | reached |
| after `init_check_mem()` | MK21 | **missing** |

Two real defects were found and fixed on the way:

1. **`_OvrInitExt` must do nothing in a resident link.**  Its decompiled body reads the
   overlay image at fixed addresses (`*(uint *)0x3c`, `0x40`, `0x69e2`...) that only
   exist when linking with `/o`.  That code is the compiler-supplied overlay runtime
   (AGENTS.md), so for the resident build it now returns 0 immediately, with the reason
   recorded at the call site.  Before: the program never got past `_OvrInitExt`.
   After: `_OvrInitExt` and `_OvrInitEms` both return.

2. **`biosKeyAvail`/`biosReadKey` did not set `AH`.**  The `swi(0x16)` form calls the
   BIOS vector with whatever is in the registers, and the availability test returned an
   uninitialised `in_ZF`.  `init_base` starts with
   `while (biosKeyAvail()) biosReadKey();` - a drain loop that can never end with a
   random flag.  They now go through two code-segment stubs (`INT 16h AH=01h` /
   `AH=00h`) in `ovr_thunks.asm`, the same place and technique as the other register
   level helpers.

Also established, and important for the next step: **the original game runs in this
harness**.  `game/STRONG.EXE` copied to a fresh directory and driven by the same
`AUTOTYPE -w 6 -p 1.5 6 ENTER ENTER ENTER ENTER` produces a **`STRONG.SAV`** (kept at
`tmp/origrun/STRONG.SAV`).  That is the reference artifact step 6 needs; the rebuild
does not produce one yet because it stops earlier.

Current stall: `init_check_mem()` is entered and never returns.  Its decompiled body
feeds an uninitialised `buf` to `LXLSH_at_`, so the "largest executable program size"
comparison is garbage and can take the abort path
(`"Stronghold requires 585,000 bytes."` / `exit(0x84)`).  This needs the original
instruction sequence - the decompiled form has no usable evidence for the real
computation, so it must be recovered from the disassembly rather than guessed.

  grep_checks 51,070; compare_state 1,627/0/0; diff_dgroup 972/1,868;
  compare_runtime 1,543/13; build 64/64 clean; link 0 errors

### The reference artifact is a directory, not a file

`tmp/origrun/STRONG.SAV` is a **directory** created by the original game; it contains
`GAME.CFG`, 12 bytes:

```
33 0d 0a 33 0d 0a 30 0d 0a 31 0d 0a     "3\r\n3\r\n0\r\n1\r\n"
```

So step 6's comparison target is the text configuration the original writes (and any
save files beside it), not a binary blob.  The rebuild must produce the same directory
and contents from the same key sequence.

## init_check_mem recovered from the original; the game now reaches config file I/O

### Locating original code without an overlay table

`audit/functions.tsv` gives `6257:0a81 OVC31 init_check_mem 123`.  Overlay blocks have
no exported file-offset table, but the two message strings it prints live in DGROUP at
`audit/dgroup_2410.bin` offsets `0x6158` and `0x618b`, and the EXE contains exactly one
reference to each - `0x54e47` and `0x54e54`, both past the resident image.  That fixes
the function, and with it the segment base for OVC31:

```
file offset = 0x54370 + offset_in_6257
```

### The real check

```
54DF1  push bp / mov bp,sp / sub sp,0x56
54DF7  mov es,[0x7b]        ; ES = PSP segment (DGROUP:0x007b)
54DFB  mov ax,es:[2]        ; top-of-memory paragraph
54E05  sub ax,[0x7b] / inc ax
54E0A  xor dx,dx / mov cl,4 / lcall LXSH      ; (top - psp + 1) << 4
54E13  add ax,0x100 / adc dx,0
54E1F  cmp dx,8 / jl fail / jne ok / cmp ax,0xED28 / jb fail
```

so the requirement is `(top - psp + 1) * 16 + 0x100 >= 0x8ED28` = **585,000 bytes**.
`init_check_mem` now implements exactly that; the decompiled form had fed an
uninitialised local to `LXLSH_at_`, so the test compared garbage.

### Config file routines recovered from the same block

`file_open_rdonly` built its path with `CONCAT22(filename, in_stack_...)` and
`read_cfg` read into `SS:0001`; both were unusable.  Recovered from
`6257:0000` / `6257:003b` / `6257:01cc` in the EXE:

* `creat_wait_unlock(path)` -> `ioErrorHndlrInstall(); _creat(path, 0); ...` retry on
  deferred error `0x20`;
* `file_open_rdonly(path)` -> `_open(path, 0x41)` in the same retry loop;
* `read_cfg(handle)` -> read one byte, then one byte at a time up to the newline,
  return the first byte (0 on short read).

Also: Borland's `IO.H` declares `_open`, `_creat`, `mkdir`, `unlink` with `char _FAR *`
paths, so the prototypes in `st_functions.h` were changed to match and the call sites
pass far pointers.  Before that, the segment came off the wrong stack slot.

### Measured effect

```
before: MK6 reached, MK10.. missing, init_base stalls in init_check_mem
after : init_check_mem returns, init_strong_sav runs, and the game OPENS
        strong.sav\game.cfg   (no temp file is created any more)
```

With a fresh directory it also creates `STRONG.SAV` (the observed directory and its
`strong.$$$` temp), i.e. the rebuild now performs real game file I/O.

### New stall: the first `read()` inside read_cfg

Markers 40/42 fire (entry, just before the first `read`), 41 (`return b`) never does.
So the program dies or hangs inside the CRT's `read()` when handed a far pointer to a
**stack** buffer, `MK_FP(_SS, &b)`.  That is the next defect to isolate - it is a
runtime/ABI question, not a recovered-body question.

  grep_checks 51,070 -> 51,028; build 64/64 clean; link 0 errors
  compare_state 1,627/0/0; diff_dgroup 972/1,868; compare_runtime 1,543/13

## read_cfg works: the library's read() takes a NEAR buffer

Measured directly: calling `read(handle, far_buffer, 1)` on a file returned **12** (the
whole file) instead of 1, i.e. the callee took the length from the segment word of the
far pointer.  `tools/BC30/INCLUDE/_defs.h` explains it - `_FAR` expands to nothing
unless the RTL DLL is being built:

```
#    if defined(__DLL__) ... #define _FAR far
#    else
#      define _FAR            <- medium model
```

so `io.h`'s `read`/`write` take `void *`, not `void far *`.  With a near buffer the
same call returned 1.

`read_cfg` therefore keeps its two bytes in **DGROUP** (`static char b, tmp`) and passes
plain near pointers; the original read into its stack frame through a far pointer,
which is not expressible against this library.

Result, measured with markers on unique anchors:

```
MK50 read_cfg start                reached
MK51 read_cfg return b             reached
MK52 init_strong_sav success path  reached   ("Found previous game_cfg")
MK53 after init_strong_sav         reached
```

So `init_strong_sav` now reads `strong.sav\game.cfg` correctly and returns 1.  The
program then blocks where the original does: the
`ENTER: use previous configuration, SPACE: reconfigure, ESC: quit` prompt.

### Where the prompt blocks

Markers around it show `MK55` (entered the `haveConfig` branch) is reached but `MK61`
(just before `clrscr`, i.e. after the key-drain loop) is not, so the drain
`while (key = ovr_biosKeyAvail(), (char)key != '\0') ovr_biosReadKey();` never ends.
`INT 16h AH=01h` itself is fine - a probe stub placed early in `init_game` ran it and
reported "no key" correctly - and a blocking `INT 16h AH=00h` did not return with
`AUTOTYPE` keys pending, so the next suspect is the drain loop's use of the thunked
`ovr_biosKeyAvail` after `init_base`'s `getcwd((char *)MK_FP(0x2410, 0x50), ...)`,
which writes the CWD to a hard-coded original-DGROUP address and can corrupt the
rebuild's image.

  grep_checks 51,028; build 64/64 clean; link 0 errors
  compare_state 1,627/0/0; diff_dgroup 972/1,868; compare_runtime 1,543/13

## The key-drain loop is fixed; the blocking read is the remaining blocker

Measured at the drain point: the BIOS keyboard buffer is **empty**
(`40:1A == 40:1C == 0x30`), yet the loop
`while (key = ovr_biosKeyAvail(), (char)key != '\0') ovr_biosReadKey();` never ended.
So the thunked `ovr_biosKeyAvail` call was not reporting "no key".  `biosKeyAvail` now
performs the buffer test itself:

```c
return *(uint16_t far *)MK_FP(0x40,0x1a) != *(uint16_t far *)MK_FP(0x40,0x1c);
```

which is exactly `INT 16h AH=01h`'s condition.  Markers confirm the drain now exits
(`P1` entered the branch, `P2` is after the drain).

### The emulator's AUTOTYPE key names are lowercase

`AUTOTYPE ... ENTER` types nothing (`KP_ENTER` neither) - the parser table in the
emulator binary (`Err bad key %s`) lists `down up left right return enter escape esc
space tab backspace f1 ...`, i.e. **lowercase**.  With `A` a key is delivered
(`40:1A` stays `0x30`, `40:1C` advances to `0x32`), and `return` is the valid name for
the Enter key.

### Still blocked: the blocking read

With the drain fixed and `return` typed by AUTOTYPE, the next marker (`P3`, placed
before `if ((key & 0xff) == 0xd)`, i.e. after `ovr_biosReadKey()`) is still missing, so
the blocking read never returns even though keys do reach the buffer.  Reading the ring
buffer directly in `biosReadKey` was tried and stopped the run *earlier* (even `P1`
vanished), so it was reverted.  The `ovr_biosReadKey -> _biosReadKey ->
_biosReadKeyRaw` call chain needs the same treatment the availability test got, but
without the busy-wait version's regression.

  grep_checks 51,019; build 64/64 clean; link 0 errors
  compare_state 1,627/0/0; diff_dgroup 972/1,868; compare_runtime 1,543/13

## printf was our own copy - the library's now returns

A minimal `printf` program built with C0M + CM.LIB (no recovered data) works, so the
toolchain and the emulator were never the problem.  The culprits were two name
collisions with the library:

1. **`crtl.c` defined `printf`/`vsprintf` itself** (`crtl.c:4131`, `:4340`), so every
   `printf` in the game called the reconstruction.  They are now `st_printf` /
   `st_vsprintf`, and `CM.LIB`'s `printf` is used.
2. **`st_globals5.c` defined `_realcvt`**, and TLINK is case-insensitive, so it
   collided with the library's `__REALCVT` - VPRINTER's *near* fixup then pointed at a
   DGROUP variable and overflowed.  The data is now `realcvtReserved`, and a resident
   `_REALCVT` stub keeps the (unused) floating-point path in range.

Measured with the bracket around `printf("EARLY\n")` early in `init_game`:

```
before: marker before printf reached, marker after printf MISSING  (hang)
after : marker before printf reached, marker after printf reached
```

`biosReadKeyRaw()` was also measured directly at a reached point and returned
`0x1E41` ('A', scan 0x1E), so the INT 16h stub and AUTOTYPE delivery both work.

Remaining puzzle: the marker placed immediately **after the prompt's** `printf(...)`
inside `init_base` still does not fire even though the identical early `printf` does, so
something about that call site (it follows `clrscr()` in the prompt loop) still blocks.

  grep_checks 51,043; build 64/64 clean; LINK ERRORS 0
  compare_state 1,627/0/0; diff_dgroup 972/1,868; compare_runtime 1,543/13

## The rebuild now writes STRONG.SAV\GAME.CFG (3 of the reference's 4 lines)

Driving `init_base`'s sound menu with the single key **`6`** (Off) is enough: the
`do ... while ((key & 0xff) != 0x36)` loop exits to `sfx = '3'; mus = '3'`, and
`pick_irq` is skipped because `irq` is still `'0'`, so `write_game_cfg(sfx,mus,irq)`
runs immediately.

Measured on a clean run directory (asserted before launch):

```
R1 write_game_cfg called   : True
R3 after ovr_init_base     : True      (init_base returns)
STRONG.SAV contents        : ['GAME.CFG']
GAME.CFG (rebuilt)         : 33 0d 0a 33 0d 0a 30 0d 0a          "3\r\n3\r\n0\r\n"
GAME.CFG (original)        : 33 0d 0a 33 0d 0a 30 0d 0a 31 0d 0a "3\r\n3\r\n0\r\n1\r\n"
```

So the first three lines are **byte-identical** to the original; the fourth (`mice`,
`'1'`) is missing.  It is produced by `init_cfg` (`ovc09_init.c:159`), the four-value
writer, which runs later in `init_game` (line 285) when an existing config is read.

### Why the fourth line is not written

`init_cfg` builds its path with hard-coded original-DGROUP addresses:

```c
cfgPath = (uint16_t)ovr_stsprintf(lbuf,(char *)CONCAT22(0x5bc,_SS),
                                  (char *)MK_FP(0x2410, 0x8c6c),0x2410);
```

`0x5bc` is the format `"%sgame.cfg"` (verified in `audit/dgroup_2410.bin`), and
`0x8c6c` is a buffer that is empty at startup and has no symbol in `audit/symbols.tsv`
- i.e. a runtime-filled data-path prefix.  `MK_FP(0x2410, ...)` is the original image's
DGROUP, so in the rebuild the path is wrong and the open fails.  A second run with the
three-line file present leaves it unchanged, confirming `init_cfg` does not complete.

  grep_checks 51,018; build 64/64 clean; LINK ERRORS 0
  compare_state 1,627/0/0; diff_dgroup 972/1,868; compare_runtime 1,543/13

## STEP 6 DATA PARITY DEMONSTRATED: GAME.CFG is byte-identical to the original

Same procedure on both sides (fresh run directory, one key `6` = sound Off):

```
original game/STRONG.EXE   -> STRONG.SAV\GAME.CFG = 33 0d 0a 33 0d 0a 30 0d 0a 31 0d 0a
rebuilt REBUILT.EXE        -> STRONG.SAV\GAME.CFG = 33 0d 0a 33 0d 0a 30 0d 0a 31 0d 0a
IDENTICAL: True
```

The last three defects were all the same class - functions whose recovered form uses a
phantom stack parameter or the original image's data segment as a pointer:

* `init_paths` (`ovc09_init.c`) called `getcwd(MK_FP(0x2410,0x44), unaff_BP)`; the
  buffer it fills is copied into `GWorkDir` immediately afterwards, so it is
  `GOriginalDir`.  It now uses the real DGROUP buffers, and `GWorkDir` holds
  `<cwd>\strong.sav\`;
* `init_cfg` built its path twice with `MK_FP(0x2410,0x8c6c)` and the format at
  DGROUP:0x5BC (`"%sgame.cfg"`, verified in `audit/dgroup_2410.bin`); both now use
  `sprintf(lbuf,"%sgame.cfg",&GWorkDir)`;
* `creat_wait_unlock_and_disk`/`open_wait_unlock_and_disk` (`ovc17_stash.c`) used a
  phantom stack parameter as the path and an uninitialised register as the create
  attribute; they now use the near path and attribute 0, like the already verified
  `creat_wait_unlock`/`file_open_rdonly`.

Marker sequence on the fresh path: `T1` init_cfg entry, `T2` config opened, `T3` mice
read, `T4` rewrite create - all reached, and the four-value writer then rewrites
`3 3 0` into `3 3 0 1`.

  grep_checks 51,018 -> 51,009; build 64/64 clean; LINK ERRORS 0
  compare_state 1,627/0/0; diff_dgroup 972/1,868; compare_runtime 1,543/13

## Second runtime checkpoint: state after init_cfg (both sides)

`compare_runtime.py` now takes its two dumps from `RUNTIME_ORIG` / `RUNTIME_OURS`
(defaults unchanged, so the main-entry gate is untouched: 1,543 / 13).

### Sampling the original after init_cfg

`init_cfg` is `3381:024d`.  Its two `"%sgame.cfg"` constructions were found in the file
at `0x25877` and `0x25a3e`; walking back to the enclosing prologues and checking which
base makes `init_game` (`3381:0579`) start with `push bp / mov bp,sp` gives the segment
base `0x25610` (0x25610 + 0x579 = 0x25b89, which is `55 8b ec ...`).  So
`init_cfg = 0x2585d`, and `init_game`'s `call 0x2585d` at `0x25bb4` is followed by the
sampling point `0x25bb7`.

A fragment-writer stub (the existing `dump_state3.py` shape) patched at that address
dumps DGROUP and exits.  Run with the same `'6'` key, the original produced 36,864 bytes
and the buffer at DGROUP `0x8c6c` contains `C:\\strong.sav\\` - the work directory built by
`init_paths` and used by `init_cfg`, i.e. the patch is at the right place.

### Sampling the rebuild

A probe build with a `dumpdg` stub called immediately after `init_cfg();` in
`init_game` writes the same 36,864 bytes to stdout.

### Comparison

```
runtime DGROUP comparison (post-init_cfg)
  original dump: 36864 bytes, rebuilt dump: 36864 bytes
  symbols matched: 1556
  identical state: 1519
  DIFFERENT state: 36
```

The 36 differences are dominated by pointer tables whose second word is a *segment*
(`...331c` in the original vs `...1024` in the rebuild), i.e. stored addresses across
segments that the current normaliser only maps for DGROUP-resident targets.  That is
the next thing to extend in the comparator, and it is now measurable because the
checkpoint exists.

  build 64/64 clean; LINK ERRORS 0; grep_checks 50,869
  compare_state 1,627/0/0; diff_dgroup 972/1,868; compare_runtime 1,543/13 (main entry)

### Normalising the cross-segment pointer words

The rebuild's DGROUP is reached through two different spellings of the segment:

* the run-time DGROUP segment (e.g. `0x7c0b`), which the relocated far pointers in
  tables such as `GYesNo`, `GMenuStrings` or `LevelBandLabels` carry - the same thing
  the original's loader writes into its own tables (`0x1c33`);
* **`0x2410`**, the original image's *link-time* DGROUP, which appears in 187 pointer
  words of the rebuild and in **none** of the original's - the original's loader
  relocates those initialisers, while our recovered tables carry the constant
  literally.  Such a pointer is wrong at run time: it dereferences the original's
  segment instead of our data.

`compare_runtime.py` now accepts both spellings (so layout bookkeeping does not mask
data differences) and prints how many words used the link-time constant:

```
runtime DGROUP comparison (post-init_cfg)
  pointer words also encode DGROUP as 2410 (187 words; the runtime segment is 7c0b)
  original DGROUP segment 1c33, rebuilt 7c0b
  symbols matched: 1556
  identical state: 1543
  DIFFERENT state: 12
  skipped (outside a dump): 1
  words using the original link-time segment 0x2410: 187
```

so the checkpoint went from 1,519/36 to **1,543/12**, and the remaining 12 are genuine
state differences.  The main-entry gate is unchanged (1,543/13).

  build 64/64 clean; LINK ERRORS 0; grep_checks 50,869
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### The 187 link-time-segment words are repaired (offsets still to do)

The repair for the far-pointer tables already existed (`fixFarTable(...)` plus explicit
`.seg = startxDseg` assignments), but it lived inside our reconstructed `startx`, which
does not run when the stock C0 startup is the entry - so under the step-6 configuration
the tables kept the original image's link-time DGROUP.

It is now a function of its own, `st_fix_far_tables()`, called from `main()` (and still
from `startx`), and `fixFarTable` derives the data segment from the table's own far
address instead of `startxDseg`.

Measured on the post-init_cfg checkpoint after re-sampling:

```
before: words using the original link-time segment 0x2410: 187
after : words using the original link-time segment 0x2410:   0
        identical state 1542 / DIFFERENT 13
```

The one symbol that moved from identical to different is the *second half* of the same
defect, now visible: `LevelRangeLabels` and `PlaceErrPtrs` carry the **original's
offsets** (`0x54bf...`, `0x461f...`), so even with the right segment they point at the
wrong data in our layout unless the offsets are remapped too.  That remapping is the
next step (initialise each table entry from the rebuild's own symbol rather than from the
original DGROUP offset).

  build 64/64 clean; LINK ERRORS 0; grep_checks 50,869
  compare_state 1,627/0/0; diff_dgroup 972/1,868
  compare_runtime 1,543/13 (main entry), 1,542/13 (post-init_cfg)

### Far-pointer tables: offsets repaired, and null terminators left null

Two more repairs on the far-pointer tables:

1. `fixFarTable` set a segment on **every** entry, including `{ 0, 0 }` terminators, so
   `LevelRangeLabels[3]` became `0000:7C0D` while the original keeps `0000:0000`.  Null
   entries are now skipped.
2. `LevelRangeLabels`' three real entries were addressed by symbol (see above) rather
   than by the original image's offsets.

A third defect surfaced in the checker: our copy of the string at original `0x466f` is
named `s_The_ground_is_too_ste_2410_466f`, whose public name TLINK truncates to
`_S_THE_GROUND_IS_TOO_STE_2410_466` - the last hex digit is lost, so the `_2410_XXXX`
identity used for pairing becomes unreadable and `PlaceErrPtrs` could not match.  The
symbol is now `s_tooSteep_2410_466f`, short enough that the suffix survives
(`_S_TOOSTEEP_2410_466F`).

Measured:

```
post-init_cfg : 1,542 identical / 13 different  ->  1,545 / 11
main entry    : 1,543 identical / 13 different  ->  1,545 / 12
symbols matched: 1556 -> 1557
words using the original link-time segment 0x2410: 0
```

  build 64/64 clean; LINK ERRORS 0; grep_checks 50,869
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### CPKeys offsets repaired; the remaining checkpoint differences are CRT bookkeeping

`CPKeys` (25 entries) was fully resolvable from `st_globals.h` (every offset has an
`extern char s_..._2410_XXXX[]`), so `st_fix_far_tables()` now assigns all 25 `.ofs`
from the rebuild's own symbols (verified: `_CPKEYS` at `73F5:0F23` and the first target
`_S_CHOOSE_2410_05F9` at `0x0FD0`).  The gate count does not change, because the
comparator already mapped the original offsets; the repair is about what the *program*
dereferences, not about the number.

The post-init_cfg checkpoint now reports 1,545 identical / 11 different, and every one
of the 11 is CRT or start-up bookkeeping rather than game data:

```
0000 _DATA                 header word
005b GSTARTX_SavedVectors  original saved the interrupt vectors, ours run under the
                           stock C0 startup and leave them zero
0081 _StartTime            BIOS tick count at start - depends on when the run happened
008b _brklvl               heap break - depends on image size
861a _exitbuf / _exitfopen / _exitopen / _streams   CRT file bookkeeping
88ac _video                video state left by the CRT
88f6 brk_normalize_xsize / 88fe __setargv_SavedReturn   start-up bookkeeping
```

None of these is game state; the game tables that used to dominate the difference list
(`LevelRangeLabels`, `PlaceErrPtrs`, `CPKeys`, `GLevelbandLabels`, the string tables)
now compare clean.

  build 64/64 clean; LINK ERRORS 0; grep_checks 50,869
  compare_state 1,627/0/0; diff_dgroup 972/1,868
  compare_runtime 1,545/12 (main entry), 1,545/11 (post-init_cfg)

### The remaining far-pointer tables, resolved by string content

Name-based resolution only worked for `CPKeys` (25/25) and part of
`GUnitDescriptions` (13/28), because many of our copies of the strings carry names
without the `_2410_XXXX` suffix (`s_mage`, `s_dwarf`, `s_fighters`, ...).  The reliable
key is the **content**: for each entry offset, take the original string from
`audit/dgroup.csv` and find the rebuilt symbol whose bytes in the post-init_cfg dump are
exactly that string followed by NUL.

```
GUnitDescriptions  28/28
GStatsLabels        6/6
GPlayerTitles      32/32
GTxtFiles           1/34   (the 33 missing are file names such as "help0.txt", which
                            are not DGROUP string symbols in our build)
```

66 `.ofs` assignments were added to `st_fix_far_tables()`.  The checkpoint stays at
1,545/11 because the comparator already mapped the original offsets; the change is what
the program dereferences at run time.

  build 64/64 clean; LINK ERRORS 0; grep_checks 50,869 -> 50,827
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### GTxtFiles: the 34 file names recovered from the original DGROUP

`GTxtFiles` was the last table not resolved (1/34).  Its entries are plain file names
(`help0.txt`, `help1.txt`, ... `cflow5.txt`) that our rebuild did not contain at all: the
text was absent from the rebuilt DGROUP dump and from the sources.  They were recovered
from `audit/dgroup_2410.bin` at `0x82B4..0x8417` (the original stores them in 10- or
11-byte slots) into

```c
char s_txtFileNames[34][11] = { "help0.txt", "help1.txt", ... "cflow5.txt" };
```

and `st_fix_far_tables()` points each `GTxtFiles[i].ofs` at its row.  Verified: both
`help0.txt` and `cflow5.txt` now appear in the rebuilt DGROUP dump.

### Comparing anonymous string pointers

The container then reported `GTxtFiles` as different, because its entries point at
strings that have **no symbol** in the original's symbol table, so no offset mapping
exists.  `word_matches` now falls back to the semantic check: when both offsets reach
the same NUL-terminated text, the pair matches.  `GTxtFiles` compares clean again.

Both runtime checkpoints are now 11 differences, all CRT/start-up bookkeeping:

```
main entry   : 1,546 identical / 11 different
post-init_cfg: 1,545 identical / 11 different
```

  build 64/64 clean; LINK ERRORS 0; grep_checks 50,827
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### `diff_dgroup --why`: the 972/1,868 gap as a worklist

`scripts/diff_dgroup.py` matched 972 of 1,868 original DGROUP labels and silently
skipped the rest.  `--why` now classifies every unmatched label with the same matching
rules the tool already uses:

```
unmatched: 896
  string literal whose name we do not have        754
  interior label (+N) - not a symbol               63
  duplicate name, all twins consumed               35
  no counterpart at all                            25
  C0 record field label - not a variable           17
  group/segment name - not a variable               2
```

So the gate's ceiling is not 1,868: 82 of the 896 can never match (interior labels,
group/segment names, C0 record fields), and 35 are duplicate spellings of names we do
have.  The addressable remainder is **779**, of which **754 are string literals** -
i.e. `diff_dgroup` is now, above all, a question of giving our string data the original
names (the same content-based pairing that resolved `GTxtFiles`, applied to the symbol
table rather than to a far-pointer table).

Examples from each bucket:

```
009a s_sorry_you_may_not_pass_time_during_a_battle        string
0002 _DATA+2                                              interior
01d5 s_mage                                               duplicate
002c PSPEnv                                               no counterpart
0304 IdFORM.hi                                            C0 record field
0000 DATASEG                                              group name
```

  build 64/64 clean; LINK ERRORS 0; grep_checks 50,768
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### String-label renames: the worklist exists, blind renaming does not work

`diff_dgroup.py --list PATH` now writes the unmatched labels (`off`, `name`, `reason`).
Pairing those labels with our symbols by string content (the `GTxtFiles` method) gives:

```
string labels with known text         789
of those, a rebuilt symbol holds it   496
renames proposed                      489
```

but only **12** survive the three practical constraints (target name <= 31 characters so
TLINK does not truncate it, name is a valid C identifier, and the pairing is
unambiguous), and **all 12 collide with identifiers we already use**: our `s_mage` is a
different variable from the string the original calls `s_mage`, and renaming
`s_mage_2410_01d5` to `s_mage` is rejected by the compiler as a duplicate initialiser.
References also live outside the data modules (e.g. `crtl.c`), so a rename must touch
every file.

The experiment was reverted; the tree is back to build 64/64 and LINK ERRORS 0.

Conclusion: closing `diff_dgroup`'s string gap is not a bulk rename.  It needs, per
symbol, (a) a collision check against every existing identifier, (b) updates in every
referencing module, and (c) a decision where two different strings share one original
name (`s_mage` appears twice).  A safer route is to make the *comparator* aware of
content: match an original label to a rebuilt symbol when the rebuilt string at that
symbol equals the original's text for that offset, which needs no source churn and
still reports genuinely missing strings.

  build 64/64 clean; LINK ERRORS 0; grep_checks 50,768
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### Content-aware matching: 494 of the 754 string labels are present, just unnamed

`diff_dgroup --why` now applies a second, independent rule after the name rule: for an
unmatched original label whose audit type is `string`, look for the same text in the
rebuilt DGROUP.  Three outcomes, reported separately so the headline stays honest:

```
matched by content, names differ   494
text present but not at a symbol    40
text absent from our data          248
```

* **494** are fully present in our data under another name - no recovery needed, only
  naming (and, as the previous turn showed, renaming is not a bulk operation);
* **40** are present inside larger blobs rather than at a symbol start;
* **248** are genuinely missing from our DGROUP and are the real recovery worklist
  (recover the text from `audit/dgroup_2410.bin`, as was done for `GTxtFiles`).

The headline `972/1,868` is unchanged by design: the content rule does not claim a name
match.  What it does is prove that 534 of the 754 "missing" string labels are not
missing data at all.

  build 64/64 clean; LINK ERRORS 0; grep_checks 50,768
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### The 248 "absent" strings are recovered: none of the original's string data is missing

`diff_dgroup --list-absent PATH` writes the strings the content rule could not find.
All 248 were recovered from `audit/dgroup_2410.bin` into `src/decompiled/stmiss.c`,
packed as one blob with an offset table (5,650 bytes; a plain array-per-string form was
tried first and pushed DGROUP past 64 KB, and also inflated the section-5
`char X[] = "..."` count by 248).

Also fixed in the content rule itself: `audit/dgroup.csv`'s `repr` column escapes control
characters (`%d \r`), so the text is decoded with `unicode_escape` before comparing.
That alone moved 248 labels from "absent" to "present": many strings were in our data
all along and had looked missing only because of the escaping.

Result of `diff_dgroup --why` after the recovery:

```
matched by content, names differ : 742 -> 675 (individual arrays -> blob)
text present but not at a symbol :  40 -> 107
text absent from our data        : 248 ->   0
```

Every string label with known text is now accounted for: 675 at a rebuilt symbol and
107 inside the blob.  The headline `972/1,868` is unchanged, because that counts **name**
matches and the recovered strings carry `s_absentStrings` positions rather than the
original labels.

Note: the main-entry dump reported one extra difference (`s_n_d_w_u_s_u`, `%u s` vs
`%k_s`) while the post-init_cfg dump holds the correct text at the same offset - the
main-entry dump came from a different binary than the current build, so that number
(1,545/12) should be re-sampled before it is trusted.

  build 65/65 clean; LINK ERRORS 0; grep_checks 50,741
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### Main-entry sampler offset fixed

`tmp/dump_dgroup_stdout.py` computed the patch offset as `seg*16 + ofs` from the map.
The map's segments are absolute paragraphs, so with DGROUP at `0x740f` the offset landed
at `0x740f0`, far outside the 555 KB file - the EXE was never patched and the dump came
from an unpatched image (which is why it showed `s_n_d_w_u_s_u` as `%k_s` while the
post-init_cfg dump held the correct text at the same offset).

The offset is now `(seg - load_base)*16 + ofs`, with `load_base` derived from the header's
entry `CS:IP` and the map's `_STARTX` (falling back to the lowest map segment).  Re-sampled
both dumps; `compare_runtime` at main entry is **1,546 / 11** from a genuinely patched
build again.

  build 65/65 clean; LINK ERRORS 0; grep_checks 50,741 -> 50,727
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### Where the remaining section-5 hits are (measured)

`tmp/class_totals.py` and `tmp/hits_by_file.py` break the 29,828 matching lines down by
class and by file:

```
[iusbc]Var         21,729   ovc22_classes 1859, ovc49_agents 1622, ovc23_bldrec 1524
p[iusbc]Var         5,873   ovc49_agents 855, ovc22_classes 464, crtl.c 419
[iusc]Stack_        3,967   ovc22_classes 651, ovc21_manage 319
char [N] = ""       1,405   st_globals5 1294, st_globals4 110
in_stack_           1,392   ovc49_agents 278, ovc15_sprite 131
unaff_DI            1,117   ovc48_assets2 284, ovc44_strong_dat 238
bStack_             1,005   ovc09_init 107, ovc34_unit 91
in_REG                837   crtl.c 128, ovl.c 91
unaff_SI              778   ovc46_assets 191, ovc19_save 108
```

Two scoping facts follow, and they matter for how the target is read:

* **`crtl.c` carries 1,530 hits and `ovl.c` 880** - 2,410 of the 29,828 (8%) sit in the
  reconstructed C runtime and the VROOMM/overlay manager, both of which AGENTS.md treats
  as compiler-supplied and out of scope to reverse.  They are counted by the gate but are
  not game-code recovery work.
* **1,405 hits are the `char [N] = ""` class and 1,294 of them are `st_globals5.c`'s
  named string objects** - i.e. recovered *data*, not decompiler temporaries.  The same
  packed-blob treatment used for `s_absentStrings` would remove that class wholesale, at
  the cost of replacing every symbolic reference with a blob + offset.

  build 65/65 clean; LINK ERRORS 0; grep_checks 50,691 -> 50,685
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### Why the `char [N] = ""` class cannot be removed mechanically (measured)

The plan was to convert the 1,404 named string objects (1,294 of them in
`st_globals5.c`) into packed blobs plus offsets, the pattern used for
`s_absentStrings`.  Two measurements stop it:

1. **DGROUP headroom.**  `REBUILT.MAP` shows DGROUP (`740d`) using **51,374 of 65,536
   bytes** - 14,090 free - while the string literals total **22,560 bytes**.  Keeping the
   named arrays *and* adding a blob therefore overflows by ~8,470 bytes
   (`Segment _DATA exceeds 64K`, which is exactly what the first attempt produced for
   `s_absentStrings` when it was written as an array of rows).
2. **Static initialisers need the address as a constant.**  Converting one string,
   `s_vdisk_fake`, to a macro into a blob built and linked cleanly and left
   `compare_state` at 1,627/0/0 - but converting `st_globals4.c`'s 110 objects failed
   with

   ```
   glob4.c Error glob4.c 338: Illegal initialization
   ```

   because `GErrorStrings[5]` is initialised as
   `{ (char far *)s_Bad_game_cfg_2410_0352[0], ... }`: a macro into a blob is not a
   constant expression, so the table can no longer be initialised.  Such tables exist
   throughout the data modules (`GYesNo`, `GMenuStrings`, `PlaceErrPtrs`, ...).

So the class is structural, not cosmetic: those objects must remain named arrays because
their addresses are used in constant initialisers, and the blob cannot be added beside
them for lack of DGROUP space.  Removing the class would require moving the data out of
DGROUP entirely (a different data model), not a source rewrite.

Stage 1 was reverted; all gates are back to their previous values.

  build 65/65 clean; LINK ERRORS 0; grep_checks 50,685
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### The `unaff_` family is a code problem, not a naming problem

Looking at the largest `unaff_SI` user, `ovc46_assets.c` (191 uses), the pattern is
uniform and revealing:

```c
far_t *unaff_SI;                       /* line 21, file scope */
rleRec = ovr_stshRleType2(..., -6, (int16_t)unaff_SI, 0, ...);   /* and 4 more calls */
```

The decompiler invented a file-scope variable because the original threaded a value
through the SI register; every call passes it identically, so it *is* a single role - but
nothing in these uses says **what** it holds.  Naming it would be a guess, and giving it
a name would not fix the code: the original must have set SI in the caller, which is
where the evidence is (the calling function's disassembly, not this callee).

The same shape holds for `unaff_DI`.  So this family (1,895 lines) cannot be reduced by
the rename ratchet at all; each case needs the original instruction sequence that set
the register, i.e. a per-function recovery.  That is why the ratchet batches never
produced a candidate from it - `tmp/cand2.py` only reports slots that are *assigned*,
and pseudo-registers never are.

  build 65/65 clean; LINK ERRORS 0; grep_checks 50,116 -> 50,070
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### A general map from original segment to file offset

Two independent derivations earlier in the project agree on one linear rule:

```
file_offset = seg*16 - 0xE200
```

Check: `init_cfg` at 0x3381 -> 0x3381*16 - 0xE200 = 0x25610 (which is where its
prologue, `55 8b ec`, was found); OVC31 at 0x6257 -> 0x54370 (init_check_mem's base).
The resident image start fits too: segment 0x1000 -> 0x1E00, the EXE's `e_cparhdr*16`.

That makes any recovered `/* seg:ofs */` comment directly addressable, so no
string-reference anchor is needed to disassemble a function in the original.

### `unaff_SI` in init_assets1 resolved: SI is set to 0xAB

`ovc46_assets.c` holds 191 of the 1,895 `unaff_` hits, all in `init_assets1`
(`7A57:0000`).  With the rule above its prologue is at file `0x6C370`:

```
06C370  push bp / mov bp,sp / sub sp,4
06C376  push si
06C377  mov  si, 0xab          ; <-- SI is the constant 0xAB
06C37A  cmp  byte ptr [bp+6],0 ; grab
```

So the pseudo-register was never an unknown pointer: the body threads the constant
`0xAB` through every `(int16_t)unaff_SI` and `stshAllocStub(unaff_SI)` call.  The
declaration `far_t *unaff_SI;` is now `uint16_t siArg = 0xAB;` with the instruction
cited in the comment, and all 190 remaining occurrences were replaced.

Result: **grep_checks 49,988 -> 49,797 (-191)** in one change, with every gate unchanged.
This is the first member of the `unaff_` family fixed by recovering the register's value
instead of renaming, and it shows the family is tractable one function at a time now that
the file-offset rule exists.

  build 65/65 clean; LINK ERRORS 0; compare_state 1,627/0/0
  diff_dgroup 972/1,868; compare_runtime 1,546/11 main entry, 1,545/11 post-init_cfg

### `stLoad` / `stSave` (the next `unaff_` users): SI is not one constant

`ovc19_save.c` has 108 `unaff_` uses, split evenly between two functions:

```
save_readBlock        49fd:0000   SI 2
stLoad                49fd:01da   SI 52 DI 52
save_loadArchiveGame  49fd:0863   SI 2
stSave                49fd:090f   SI 52 DI 52
```

Disassembling their prologues (file = seg*16-0xE200):

```
stLoad 03BFB0  push si
       03BFB2  mov  si, word ptr [bp + 6]     ; SI = first argument (handle)
       03BFB5  lcall ...
stSave 03C71A  mov  si, ax                     ; SI = the result of the preceding call
       03C71C  or   si, si
```

and `stLoad`'s DI is a counter (`03C154 xor di,di`, `03C1A1 inc di`), while SI is
**rewritten** later in the same function (`03C617 mov si,ax`).

So unlike `init_assets1` - where SI was the fixed constant 0xAB - these two need flow
analysis: `unaff_SI` is `handle` only up to the point where SI is reloaded from AX, and
`unaff_DI` is a running count.  A blanket replacement would be wrong on those paths, so
the change was not made; the addresses above are the evidence the next attempt needs.

  build 65/65 clean; LINK ERRORS 0; grep_checks 49,797 -> 49,777
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### The other `unaff_` holders are not prologue constants

Three more functions were disassembled with the `seg*16-0xE200` rule; none is a repeat of
`init_assets1`:

```
manage_usesEntities   4d05:22cf   starts at cmp cl,0xff - a mid-function fragment
manage_usesEntities2  4d05:2371   same shape
ovc15_textError       4207:26bc   push si but no initial mov si; SI is later set to
                                  0, 5 and 0xa in different branches
```

* the two `manage_usesEntities` bodies take **no arguments** and read SI (entity index),
  CL (entity type) and BP (outer frame) - a register-based convention.  Our recovery split
  one original function into two fragments, so fixing them means restructuring (adding
  parameters and merging the call sites), not renaming;
* `ovc15_textError` assigns SI several different constants per branch, so it is a scratch
  variable whose assignments the decompiler lost - again a code change, not a rename.

So of the `unaff_` family only the "single constant set in the prologue and never
reloaded" case (init_assets1, -191 hits) is mechanical.  The rest need the original's
control flow, which the addresses above now make easy to obtain.

  build 65/65 clean; LINK ERRORS 0; grep_checks 49,777 -> 49,756
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### All 114 `unaff_` holders classified: none repeats the init_assets1 pattern

`tmp/unaff_classify.py` walks every module, maps each holder with the `seg*16-0xE200`
rule, disassembles its prologue and counts later writes to the same register.  Result:

* **114 holders** use a pseudo-register; none is a single prologue constant that is never
  reloaded.  The categories are:
  - *register-convention fragments* with no arguments and no write at all -
    `draw_textTalkwin9Lbm` (`2e25:025a`, 22 uses, zero SI writes in 0x300 bytes),
    `manage_usesEntities`, `manage_usesEntities2`, `grabLbm`;
  - *scratch values set per branch* - `ovc15_textError` (SI := 0, 5, 0xa),
    `__setargv` (`mov si,0x80` but 13 later writes);
  - *parameters used before any assignment* - `stExit` (`mov si,[bp+6]`) but reloaded
    later in the body.

So `init_assets1` (SI = 0xAB, -191 hits) was the family's one mechanical case, and the
remaining ~1,700 hits need control flow: either merging register-convention fragments back
into their callers or giving each scratch value a local with the assignments the
decompiler dropped.  The file offsets in the table above make that work addressable.

  build 65/65 clean; LINK ERRORS 0; grep_checks 49,756 -> 49,731
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### `unaff_` holders whose register is never set at all

`tmp/unaff_classify.py` also reports holders where the register is never written in the
first 0x300 bytes.  Two were checked:

* `ovc22_textRingProt` (`5087:056e`, 98 `unaff_DI`): the function pushes DI and never
  sets it early, but the whole body does write it - `0436A7 mov di,2`, `043712 xor di,di`,
  `04373F inc di` - i.e. it is a loop counter the decompiler uses before its assignment.
  Binding it means restructuring the loop, not deleting a local;
* `saveui_configureMessageDelay` (`4528:1303`, 16 SI + 17 DI): same shape.

So the "prologue never writes it" list is not the `init_assets1`/`stExit` pattern; those
two were cases where the register *was* written once, from a constant or a parameter.
This closes the mechanical part of the family: what remains needs the original's control
flow per function.

  build 65/65 clean; LINK ERRORS 0; grep_checks 49,708 -> 49,687
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### `ovc22_textRingProt`: `unaff_DI` is a loop counter, not a pointer

The largest remaining slot (98 uses, `5087:056e`) looked like a pointer in the export
(`uint *unaff_DI`, used as `*unaff_DI` and `+ (int)unaff_DI`).  The original says
otherwise - both loops are ordinary counted loops with DI as the index:

```
loop 1  bf 02 00      mov di, 2
        0b ff / 4f    or di,di / dec di      ; 2, 1, 0
        7d ..         jge body
loop 2  33 ff         xor di, di
        26 8a 81 aa 00  mov al, es:[bx + di + 0xaa]   ; index into the record
        47 / 83 ff 02 / 7e ..  inc di / cmp di,2 / jle body   ; 0, 1, 2
```

So DI is `int i` in two three-iteration loops, and the export's pointer type is a
decompiler artefact.  Fixing it means re-deriving both loop bodies inside a 2,300-line
function - a genuine recovery task, not a slot rename - so it was not attempted in a
batch.  The two loop addresses (`0436A7`, `043712`) are recorded here as the starting
point for that work.

  build 65/65 clean; LINK ERRORS 0; grep_checks 49,708 -> 49,687 -> 49,662
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### `ovc22_textRingProt` rework: scope measured (70 distinct use patterns)

Before touching the 98 `unaff_DI` uses, they were classified:

```
 9  I)[((I)I % #) * #]
 6  I = (I *                     <- an assignment to the pseudo-register
 6  I *)((I)I + I
 3  I + (I)I)->I
 3  I)[(I)I].I.I
 2  I = I;                       <- another assignment
```

70 distinct expression shapes, two of which assign to the pseudo-register itself.  That
rules out a type change or a blanket substitution: the decompiler folded the two DI loops
*and* their index arithmetic into expressions that use DI as if it were a base pointer,
so the loops and every use have to be re-derived together.  The two loop addresses are
`0436A7` (mov di,2 / dec / jge) and `043712` (xor di,di / inc / cmp di,2 / jle, indexing
`es:[bx+di+0xaa]`).

This is a dedicated recovery task for a 2,300-line function; a speculative edit was
rejected because a wrong index would change game logic silently while every gate stayed
green.

  build 65/65 clean; LINK ERRORS 0; grep_checks 49,662 -> 49,642
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### Two more `unaff_` members settled; `stshRead`'s prototype is wrong

`tmp/unaff_classify.py` reports which register writes actually occur. Two holders have
exactly one write, from a parameter:

* **`uiReadString` (`4528:0C98`)**: `mov si, word ptr [bp + 0xa]` and nothing else, so
  `unaff_SI` is the third parameter (`row`).  The local `uint *unaff_SI;` was an
  uninitialised pointer in our build; it is now bound to `row`, so
  `uStack_5e = (uint16_t)CONCAT22(text,row)` uses the argument the caller really passes.
* **`stshRead` (`474a:008F`)**: `mov si, word ptr [bp + 6]` - the first parameter - but
  the prototype in `st_functions.h` is `uint stshRead(void)` and all three call sites call
  it with no arguments.  The original pushes one word before the manual far call:

  ```
  03A11D  mov ax, 0x280
  03A120  mov es, ax
  03A122  push word ptr es:[0x4e4]
  03A127  push cs
  03A128  call 0x3932f            ; stshRead
  ```

  so the callee reads `MK_FP(0x280,0x4e4)`'s word as the **segment** half of
  `srcPtr = CONCAT22(pbuf, arg)`.  Fixing it means giving `stshRead` a `uint16_t`
  parameter and passing that expression at `ovc17_stash.c:796`, `:840` and
  `ovc21_manage.c:1229` - the third site's argument has not been read yet, so the change
  was not made rather than guessed.

  build 65/65 clean; LINK ERRORS 0; grep_checks 49,623 -> 49,621
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### CORRECTION: `ovc22_textRingProt`'s `unaff_DI` is not the loop counter

The earlier entry in this document claimed the 98 `unaff_DI` uses were a loop counter that
had to be re-derived.  That is **wrong**, and the measurements are unambiguous:

* the original prologue (`42BDE`) is `push bp / mov bp,sp / sub sp,0x46 / push si /
  push di` - DI is saved but **never set**;
* a linear sweep of `42BE6..436A7` finds exactly one mention of DI: `push di` itself, i.e.
  **no read** before the loops;
* DI's entire live range is the two loops: `0436A7 mov di,2` … `04370B jge`, then
  `043712 xor di,di` … `043743 jle`;
* after `043745` DI is neither read nor written until the epilogue `pop di`.

And the two loops are **already recovered correctly** by the export, with real indices:

```c
1794  bStack_1b = *(byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0xad);
1795  for (iVar29 = 2; -1 < iVar29; iVar29 = iVar29 + -1) {      /* borrow propagation */
1796    if (bStack_1b < *(byte *)(... + iVar29 + 0xaa)) {
1797      *(byte *)(... + iVar29 + 0xaa) = bStack_1b;
1798      bStack_1b = 0;
1800    } else {
1801      bStack_1b = bStack_1b - *(char *)(... + iVar29 + 0xaa);
1803    }
1804  }
1805  iVar29 = 0;
1806  for (iVar52 = 0; iVar52 < 3; iVar52 = iVar52 + 1) {          /* weighted sum */
1807    iVar29 = iVar29 + *(byte *)(... + iVar52 + 0xaa) * (iVar52 + 1) * 3;
1809  }
```

which matches the original instruction-for-instruction (loop 2 computes
`acc += b[i]*(i+1)*3`, exactly the `imul dx / shl dx,1 / add dx,ax` sequence).  So there is
no loop to re-derive.

Consequently the 98 remaining `unaff_DI` uses (lines 551-552 and 668-698) are **artifacts**
that do not correspond to any DI access in the original; they are expressions where the
decompiler lost the real base (`&puVar38->bldType + (int)unaff_DI`, `*puVar3 = ...`).  They
were left untouched deliberately:

* initialising the pointer to `NULL` would make `*puVar3 = *puVar3 + ...` write into
  DGROUP offset 0 (`_DATA`, the C0 header) if that path is reached - worse than the
  present undefined value;
* pointing it at a scratch word would make the build deterministic but would *hide* the
  real defect, which is that the base of those expressions is unknown.

So this item needs the original's code for that region (the switch at 0x43xxx), not a
rename, and is left open with this correction in place.

### Measured: absolute segment 0x0070 is a runtime far-pointer table

The same function reads the party record through a game-wide idiom that occurs **302**
times in the image:

```
mov  al, byte ptr [bp + 6]      ; partyIndex
shl  ax, 2
mov  dx, 0x70
mov  bx, ax
mov  es, dx
les  bx, ptr es:[bx]            ; far pointer from 0070:partyIndex*4
mov  al, byte ptr es:[bx + di + 0xaa]
```

i.e. the table lives at **absolute segment 00070h**, not in DGROUP.  To find out what that
contains, the original was patched at the post-`init_cfg` point (`0x25BB7`) with a stub
that dumps `DS:0` and then `0x0070:0`.  The dump shows a 28-entry far-pointer table whose
entries are `1c33:018d`, `1c33:0196`, `1c33:019f`, `1c33:01a5`, … followed by the strings

```
Fighter, Mage, Cleric, Thief, Dwarf, Elf, Halfling,
fighters, mages, clerics, thieves, dwarves, elves, halflings,
fighter, mage, cleric, thief, dwarf, elf, halfling,
fighter unit, mage unit, clerical unit, ...
```

`1c33` is the running original's DGROUP segment, and those offsets are the unit-description
strings, so segment `0x0070` holds a *copy of the unit-description far-pointer table*.

Our export never modelled this: it renders the access as `*(uint32_t *)((uint)partyIndex << 2)`,
a **DS-relative** read at DGROUP offset `partyIndex*4` - which lands in `_DATA`'s header, not
in the table.  That is a separate, real defect (the recovered `+0x2f`, `+0xad`, `+0x94` field
reads in this function all go through it), and it is why `+0xaa`-based logic still "works"
in tests: those offsets are read relative to whatever the DS-relative expression points at.
Fixing it means teaching the recovery that `00070h:0` is a base - the probe above is the
evidence, and the same idiom appears 302 times.

  build 65/65 clean; LINK ERRORS 0; grep_checks 49,605
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### CORRECTION: the earlier "segment 0x0070 holds a table" reading was a bad dump

The previous entry claimed a probe had shown absolute segment `00070h` holding a copy of
the unit-description far-pointer table.  **That was wrong.**  The probe wrote three
fragments (DS, `0x0070`, `0x0280`) in one run and the file came back with 6894 bytes
instead of the requested 1280, so the fragment boundaries were unknown; what the hexdump
actually showed was DGROUP's own `GUnitDescriptions` table (`1c33:018d`, `1c33:0196`, …,
followed by `Fighter`, `Mage`, … and later `fighter unit`, `mage unit`), i.e. the
*control* fragment bleeding into the second slice.

Re-measured properly, one fragment per run, patching the EXE header entry (`0000:003e` at
file `0x1E3E`, no keystrokes needed so the run is deterministic):

```
=== entry_ds   seg DS     want 0x0100 -> 256 bytes
   head: 00 00 00 00 42 6f 72 6c 61 6e 64 20 43 2b 2b 20 - 20 43 6f 70 79 72 69 67 ...
   strings: Borland C++ - Copyrigh | Divide error\r\nAbnormal | Sorry, you may not pas
=== entry_70   seg 0070   want 0x0200 -> 512 bytes
   nonzero: 69 / 512      head: all 00, one 01, then ff ff ff ff ...
   strings: none (only 0xff runs and 'NUL     ')
=== entry_280  seg 0280   want 0x0100 -> 256 bytes
   nonzero: 0 / 256
```

So at program start segment `0x0070` is uninitialised low memory and `0x0280` is all
zeros - **neither holds a table**.  What the code does with them is therefore still open,
and there is no measured evidence of a defect in the recovered DS-relative rendering:

* the same `mov ax,0x0280 / mov es,ax` idiom occurs **2398** times and `0x0070` variants
  about 236 times, and the export renders every one of them as a DS-relative access;
* our rebuild works end to end through configuration with that rendering, while a
  resident build has no overlay segment to substitute;
* a linear sweep of `textRingProt`'s range finds **no MZ relocation** covering the
  `mov dx,0x70` immediate, so DOS does not patch it either.

Withdrawing the claim and leaving the code alone is the correct outcome: changing those
302 sites to read a segment that is empty at runtime would be strictly worse.  Settling
what they mean needs a *working* runtime probe at a later point (the post-`init_cfg`
patch is flaky: three attempts returned 0 bytes even when `GAME.CFG` proved the menu had
been answered), so the probe scripts and their negative results are kept in `tmp/`
(`probe_entry70.py` works, `probe_post70.py` does not).

  build 65/65 clean; LINK ERRORS 0; grep_checks 49,570
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### `unaff_DI` in `ovc22_textRingProt`: closed as an artifact (third measurement)

An exhaustive scan of `42BDE..4383E` for **every** instruction whose destination operand is
DI (all mnemonics, not just `mov`/`xor`/`pop` - this catches `les di,...`, which the first
scan missed) returns exactly six instructions:

```
0436A7  mov di, 2        ; loop 1 init
043708  dec di           ; loop 1 step
043712  xor di, di       ; loop 2 init
04373F  inc di           ; loop 2 step
```

(`or di,di` and `cmp di,2` are reads.)  So DI is **never** written or read anywhere except
between `0436A7` and `043743`, and both loops are already correctly recovered with
`iVar29`/`iVar52`.

Conclusion, now supported by three independent scans: the 98 `unaff_DI` uses in the export
do not correspond to any DI access in the original.  They are artifacts of a mis-modelled
value in the region the decompiler rendered as a `switch` (around decompiled line 665,
which maps to roughly `42F90..430xx` by line/byte proportion).  Two further facts show how
far that region is from a usable rendering:

* the literals in those expressions are **data-table values**, not code immediates:
  `0x145d` appears exactly once in the whole image at file `0x22074` and `0x195d` once at
  `0x2C13E`, both inside descending word tables (`... 15 9f 15 86 15 77 15 62 15 ...`),
  and neither value occurs anywhere inside `textRingProt`'s byte range;
* `iStack`/`unaff` values there feed pointer arithmetic of the form
  `&puVar38[-0xd8c].y + (int)unaff_DI`, i.e. the decompiler built the expression from a
  base it could not resolve.

Replacing them therefore requires re-deriving that whole `switch` region from the
original's instructions - a per-expression job, not a rename - and none of the three
measurements above changes what the code should say.  They have been left untouched, which
is why the count stays at 98.

  build 65/65 clean; LINK ERRORS 0; grep_checks 49,533
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### The section-5 distance, quantified by module group

`tmp/s5_split.py` applies `grep_checks.py`'s own regexes with the same counting rule
(`len(rx.findall(text))`, which is what the gate script uses - counting *lines* gives a
misleadingly low 37,706) and splits every class by module group:

```
check              total    game     crt     ovl    data   largest game modules
[iusbc]Var         30602   27772    1865     965       0   ovc22_classes:2861, ovc23_bldrec:2442
p[iusbc]Var         7157    6266     535     356       0   ovc49_agents:931, ovc02_draw:712
[iusc]Stack_        4306    4261      37       8       0   ovc22_classes:791, ovc21_manage:300
char [N] = ""       1405       0       1       0    1404
in_REG               919     659     154     106       0   ovc27_combat:72, ovc33_stats:51
p[iusc]Stack_        485     482       3       0       0   ovc22_classes:140, ovc49_agents:57
ram0x                  7       2       2       3       0
... )                 10       8       2       0       0
---------------------------------------------------------------
TOTAL              49452   43814    2723    1511    1404
game 88.6 %    out-of-scope CRT+VROOMM 8.6 %    data 2.8 %
```

Three facts follow, and they bound what the gate can reach by source work:

* **88.6 % (43,814) is resident/overlay *game* code** - that is the real target, concentrated
  in `ovc22_classes.c` and `ovc23_bldrec.c` for `[iusbc]Var`.
* **8.6 % (4,234) is the reconstructed C runtime (`crtl.c` 2,723) and VROOMM manager
  (`ovl.c` 1,511)**, which AGENTS.md classes as compiler-supplied and out of scope to
  reverse; those rows can only fall by deleting the reconstructions in favour of the shipped
  `CM.LIB`/`OVERLAY.LIB` behaviour, not by decompiling them.
* **2.8 % (1,404) is `char [N] = ""` in the data modules** - recovered *data* objects, not
  temporaries, and measured earlier to be structural (14,090 bytes of DGROUP headroom
  against 22,560 bytes of literals, plus static initialisers such as `GErrorStrings` that
  need those symbols as compile-time addresses).

So the practical target is the 43,814 game-code matches, and the two largest single files
hold 5,303 of the `[iusbc]Var` + `p[iusbc]Var` matches between them.

  build 65/65 clean; LINK.LOG 65 bytes / 0 problems; grep_checks 49,452
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### From renames to whole-function re-derivation (first two functions)

With the per-slot ratchet out of candidates (`stack_scan.py`: 1, the known rejection;
`cand2.py`: 7, of which 2 are `crtl.c`, 1 `ovl.c` and 1 the `in_CX` register), the work
moved to re-deriving whole functions against the original.  Both done so far are in
`ovc22_classes.c`, the heaviest file, and both exposed real defects rather than only
naming.

**`ovc22_usesGUnits`** (`5087:1674`, file `0x43CE4`)

* export: `bVar1`, `uVar2`, `puVar3`, `uVar4` + repeated rebuilds of the `GUnits` far
  pointer (`si*9` recomputed for every field access);
* recovered: one typed `unit_t *u = (unit_t *)GUnits + unitIndex;`, a counted loop over
  `GRecordCount`, and `bldType` in a word;
* **defect fixed**: the export gated the `x+2`/`x+3` construction records on
  `createConstructionRecordFar(...) != 0`.  The original executes no `or al,al` after that
  call (0x43E17) and tests only `BuildingTypes[bldType].size`, so the exported condition
  silently dropped two construction records whenever the call returned zero;
* **documented, not changed**: the original's `outFlag` is a FAR pointer (ofs `[bp+8]`,
  seg `[bp+0xa]`) plus a fourth argument at `[bp+0xc]`, stored through `ES:BX`.  Our
  2-argument prototype makes the callee read the caller's stack, which is exactly what
  `in_stack_00000006` and `unaff_DI` in that function are.  Fixing it needs the same
  treatment at all nine call sites.

**`ovc22_usesEntities`** (`5087:1532`, file `0x43BA2`)

* export: `pcVar1`, `bVar2`, `uVar3`, `bVar4`, `iVar5`, `uVar6`;
* recovered: entity pointer, `field`, `animBase`, `n`, and the early-return chain read
  straight from the instructions (0xff check, `0x800` flag, `0x3f`/`0x5b`/`0x4d` sheet
  fields, the `n = 3..1` walk over `0x8c + n*2`, then `AnimFrame` advance);
* **defect fixed**: the exported returns `entityIndex * 0x37 & 0xff00` /
  `CONCAT11(...,1)` were Ghidra modelling a stale `AH` left by the `imul dx` that computes
  the record offset.  The original only executes `mov al,0` / `mov al,1`
  (0x43BCC, 0x43CDB, 0x43CDF), and every caller tests `& 0xff` - so the function returns
  0 or 1.

  grep_checks 49,387 -> 49,357 -> 49,315 (-72); build 65/65 clean; LINK.LOG 65 bytes /
  0 problems; compare_state 1,627/0/0; diff_dgroup 972/1,868;
  compare_runtime 1,546/11 main entry, 1,545/11 post-init_cfg

### Defect class: stale `AH` in return values (seven functions fixed)

The whole-function re-derivations exposed a systematic decompiler error: after an `imul dx`
(or any call), Ghidra treats the leftover `AH` as part of the function's result and emits

```c
return CONCAT11((char)((uint)X >> 8),1);     /* the "1" result with a fake high byte */
return X & 0xff00;                            /* the "0" result with the high byte kept  */
```

while the original only ever executes `mov al,0` / `mov al,1` before `retf`.  Every caller of
such a function tests `& 0xff` or the truth value, so the high byte is pure noise - and the
pseudo-registers it drags in (`in_AX`, `extraout_AH`, and a recycled `uVar3`) make the body
wrong as well as unreadable.

Two tools make this mechanical:

* `tmp/find_stale_ah.py` - greps the tree for `return CONCAT11(...)` and `return X & 0xff00`
  and prints the enclosing function and its declared return type;
* `tmp/check_ah_tails.py` - maps each candidate through `file = seg*16-0xE200` (size from
  `audit/functions.tsv`) and disassembles the tail, so the tail's final `mov al,` sequence is
  the evidence rather than an assumption.

Confirmed by tail and fixed:

| function | address | tail | fix |
|---|---|---|---|
| `ovc22_usesAlignUp4` | 5087:3c93 | `mov al,1` 0x4638B, `mov al,0` 0x4638F | rewritten (5 temporaries, `uVar3` had two roles) |
| `init_compute2` | 3381:2452 | `mov al,0` 0x27AC0, `mov al,1` 0x27ACD | rewritten |
| `audio_isPlaying` | 3a5b:034e | `mov al,1` 0x2C711/0x2C726, `mov al,0` 0x2C72A | rewritten; the `in_AX == 1` test after the second call was testing a stale value instead of `midGetSequenceStatus()`'s own return (compared in `ax` at 0x2C721) |
| `ovc22_usesGMapFlags2` | 5087:3f8d | `mov al,1` 0x46700 | returns 1/0 |
| `agnt_compute12` | 3b1d:0d4d | `mov al,1` 0x2DD38/0x2DD4A, `mov al,0` 0x2DD4E | returns 1/0 |
| `ovc15_usesAlignUp4` | 4207:0ff0 | `mov al,1` 0x34EFF, `mov al,0` 0x34F0D | `& 0xff00` -> 0 |
| `ovc18_usesAlignUp4` | 48ac:1092 | `mov al,0` 0x3BBCF, `mov al,1` 0x3BBD3 | `& 0xff00` -> 0 |

Deliberately **not** changed, because the high byte is real: `CONCAT11(0x24,...)` in
`inputUpdate` and `saveui_usesMouseMoved` (0x24 is the extended-key prefix), and `be2`'s
byte swap.  The tail check distinguishes them: those functions do set `AH`.

Still open from the same scan (tails not yet read): `attact_usesSCARRY22`,
`attact_usesAlignUp44`, `abilitiesDlg`, `ovc22_usesPlayerCount`, `stLoad`/`stSave`,
`fmMallocRecover`, `ovc15_compute1`.

  grep_checks 49,229 -> 49,186 -> 49,176; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868; compare_runtime 1,546/11, 1,545/11

### `ovc23_textAdlibNone` (55fe:0000, file 0x47DE0): the body is the problem, not the signature

An earlier note said its callers push no arguments (the call at 0x4A925 is `push cs; call
0x47de0`) and inferred that the three-parameter declaration was simply wrong.  Read
properly, the picture is different and the function cannot be fixed by editing its
signature:

* `audit/functions.tsv` gives it **1028 bytes**, so it spans `0x47DE0..0x481E3`; the next
  function (`ovc23_tickRecordsAt`) starts at `55fe:0487` = file `0x48267`, and the switch
  cases at `0x481E0..0x4825x` (the `jmp word ptr cs:[bx + 0x47d]` at 0x481DB dispatches to
  them) fill the gap;
* scanning exactly that extent finds **no** `[bp+6]`, `[bp+8]` or `[bp+0xa]` access - the
  only such reads in the neighbourhood are at `0x4826F`, `0x48299`, `0x4832E`, `0x483BE`,
  all inside `ovc23_tickRecordsAt` or `ovc23_isCursorAt`;
* yet the exported body uses `partyIndex` **33 times and never assigns it**, plus `outFlag`
  once and `agnt` twice.

So all three declared parameters are phantom in the export: they are not read from the
stack, and nothing in the body writes them.  Declaring the function `(void)` would simply
turn those 33 uses into an undeclared identifier, and inventing a local would be worse.  The
real value must come from a register or a frame slot that Ghidra misattributed, which needs
the whole 1028-byte body re-derived - the largest single remaining function (674 decompiled
lines, 985 section-5 hits), and a multi-session job.

What *was* fixed in the same area, with full evidence:

**`ovc23_isCursorAt`** (`55fe:05db`, file `0x483BB`) - the 60-byte body reads only `[bp+6]`
(0x483BE) and `[bp+8]` (0x483EA) and ends `mov al,1` / `mov al,0` (0x483EF / 0x483F3).  The
declaration invented a third parameter that all three call sites passed as a literal 0, and
typed the boolean as `uint`.  Now `bool ovc23_isCursorAt(uint16_t x,int y)` with the call
sites updated.

  build 65/65 clean; LINK.LOG 65 bytes / 0 problems; grep_checks 49,085
  compare_state 1,627/0/0; diff_dgroup 972/1,868; compare_runtime 1,546/11, 1,545/11

### `ovc23_textAdlibNone`: what the phantom `partyIndex` really is (measured)

Following the call site as planned settled it.  Immediately before `push cs; call 0x47de0`
at `0x4A925` the only instruction is `dec word ptr [0x91df]` (GRecordCount--), so **nothing
is set up for the callee**: SI still holds the caller's record index and DI its accumulated
`0x3000` flags.  Those are the values the export passed as `unaff_SI` / `unaff_DI`.

Inside the callee, the value that indexes the `0x70` leader-sheet table is the **byte local
`[bp-2]`**, and its whole life in the 1028-byte body is four instructions:

```
047FEC  mov ax, 0x280 / 047FF1 mov ax, es:[0x899f] / add ax, si     ; GUnits + unitIdx
047FF8  lcall 0x250, 0x25                                            ;  == ovc45_getUnitType? no:
                                                                     ;  this is inside the loop
04800B  mov dx, 0x280 / les bx, es:[0x8995] / add bx, ax             ; GUnits + unitIdx*9
048017  mov al, byte ptr es:[bx + 2]                                 ; the byte at +2
04801B  mov byte ptr [bp - 2], al                                    ; the only write
048025  cmp byte ptr [bp - 2], 0xff                                  ; compared with 0xff
04802B  mov al, byte ptr [bp - 2] / shl ax, 2 / mov dx, 0x70 / les bx ; 0x70 sheet lookup
048081  mov al, byte ptr [bp - 2]                                    ; second lookup
```

Our `unit_t` is `{ byte bldType; byte level; byte unitType; byte flags; short x; short y;
byte timer; }`, so **offset +2 is `unitType`**.  Therefore the exported "parameter"
`partyIndex` is really `GUnits[unitIdx].unitType`, loaded once into a byte local and tested
against `0xff` - it is a *field load*, not an argument, and Ghidra lost the assignment
because it had already decided the slot was a parameter.

That converts the blocker into a concrete re-derivation step: insert
`partyIndex = ((unit_t *)GUnits)[unitIdx].unitType;` at the matching place in the body and
drop the parameter.  It is not done here because the 674-line body must be aligned with the
original first so the assignment lands in the right iteration.

Measured in the same pass: the three remaining call sites that passed pseudo-registers
(`uVar18,unaff_SI,in_stack_0000fffc`; `unaff_SI,unaff_BP,in_stack_00000000`;
`unaff_DI,unaff_SI,in_stack_0000fff6`) now pass `0,0,0`, matching the callee that reads
nothing - the registers they named carry unrelated caller state.

  grep_checks 49,085 -> 49,077; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868; compare_runtime 1,546/11, 1,545/11

### CORRECTION: `in_stack_00000004` is the first argument, not the return CS

Two earlier commits claimed that `ovc23_usesBlitGfxRect` / `ovc23_usesBlitGfxRect2` were
"short by a word" because `in_stack_00000004` was `[bp+4]`, the far return CS, yet used as an
X coordinate.  **That is wrong.**

`ovc23_usesBlitGfxRect2` (`55fe:23d8`, file 0x4A1B8) touches exactly five stack slots:

```
04A1C0  mov si, word ptr [bp + 6]     ; arg 1, used as the blit X
all [bp + N] accesses in its 0x94-byte body: 6, 8, 0xa, 0xc, 0xe
```

which matches its five declared parameters `(int x, int y, int recordIndex, brect_t *rect,
uint16_t type)` one for one, and the callers push five words (`add sp, 0xa`).  So `[bp+6]` is
the first argument, and Ghidra's `in_stack_00000004` **aliases that same argument** - it is a
duplicate stack-parameter name, not a mis-sized frame.

A scanner for the pattern (`tmp/find_cs_slots.py`) shows how widespread the alias is:

```
functions using in_stack_00000004/6: 45 (far: 31  near: 14)
largest: init_assets 48 uses, ovc22_usesGMapFlags2 31, stshRead 24,
         stats_textRingProt 24, ovc18_showLeaderView 15,
         ovc23_usesBlitGfxRect 10, ovc23_usesBlitGfxRect2 10
```

For the 31 `__cdecl16far` entries the slot is the first argument, so those uses are
replaceable by the real parameter name; for the 14 `__cdecl16near` entries the numbering
shifts by two words and `[bp+4]` is a genuine first argument, so they are not aliases of the
same kind.  No substitution was made here: the two interpretations differ only by which
vintage of Ghidra's stack model produced them, and I would rather leave the code as it is
than rename 250 uses on a reading I have already got wrong once.

What the scanner does establish is that the earlier "signature short by a word" note must not
be acted on for these two functions - their five arguments are all read.

  grep_checks 49,020; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868; compare_runtime 1,546/11, 1,545/11

### A selection rule that turned whole-function work from risky into mechanical

Every whole-function re-derivation in this session had been picked by raw section-5 mass
(`tmp/rank_funcs.py`), and the two biggest entries (`ovc22_textRingProt`, 3,955 matches;
`ovc23_textAdlibNone`, 985) are exactly the ones that cannot be rewritten safely: their
bodies carry `unaff_*` register pseudo-variables, `in_stack_*`/`stk_*` bogus stack slots,
`code_r0x...` labels and even a bogus `swi(1)` call, so the *control flow* is still wrong
and naming individual slots leaves the real defects in place.

`tmp/rank_clean.py` splits the ranking on that axis.  For every function it counts the
section-5 mass and separately the "anomaly" identifiers:

```
ANOM = unaff_[A-Z] | in_[A-Z] | extraout_ | in_stack_ | stk_[0-9a-f]
       | code_r0x | L_[A-Z0-9_]+ | swi( | ram0x | param_ | value[0-9] | num[_0-9]
```

Measured over the tree (excluding `crtl.c` / `ovl.c`):

```
clean: 121 functions, 5,716 section-5 matches   <- only the naming is missing
dirty: 148 functions, 21,130 matches            <- control flow needs work first
```

A clean function's body is already faithful; every slot in it holds one value with one
role, so renaming is evidence-based and the rewrite cannot change behaviour.  Five such
rewrites in this session:

| function | module | matches | shape |
|---|---|---|---|
| `bldng_buildMenuEntries` | ovc35_bldng.c | 116 | selection sort of a uint16 array + parallel far-pointer array by `BuildingTypes[..].word_0x125` |
| `driver_unrleScreen` | ovc01_driver.c | 69 | RLE, 200 rows, `count,value` / literal-run chunks |
| `driver_unrleSprite` | ovc01_driver.c | 71 | RLE with per-chunk x-skip, sprite header at spr[0..1] |
| `ovc07_usesBiosReadKey` | ovc07_gfxutil.c | 185 | triangle rasteriser: y-sort + two DDA edge walks |
| `ovc41_compute3` | ovc41_main.c | 59 | menu cursor move over a 0x94-stride table |
| `ovc27_rollToHitEntity` / `...Agent` | ovc27_combat.c | 48+50 | ramp-table lookup by ability, column+1 target |
| `ovc45_usesGPopulationLo` | ovc45_unitinfo.c | 60 | 32-bit gold decrement with population fallback |
| `ovc25_hasBuildingNear`, `season_countPromotable`, `ovc15_selectRightmostAgent` | - | 28+35+26 | small scans/searches |

Yield: 48,982 -> 48,110 (-872) from eleven functions, i.e. ~79 matches per function,
against ~30-60 for the earlier mass-ranked picks - and with control flow untouched, so the
risk is only in transcription, which the gates then check.

The rule also explains the earlier zero-yield turn: `ovc23_textAdlibNone` has 985 matches
but is dirty, so it belongs in the 21,130-match group that needs its body rebuilt, and no
amount of slot naming will move it.

  build 65/65 clean; LINK.LOG 65 bytes / 0 problems; compare_state 1,627/0/0
  diff_dgroup 972/1,868; compare_runtime 1,546/11 main entry, 1,545/11 post-init_cfg

### CORRECTION: two figures in the earlier section-5 split were wrong

The split table recorded earlier in this document lists `in_stack_ 1392` and
`bStack_ 878`.  Recounted with the gate's own patterns directly from git rather than from
the splitter's output, the values at commit `b1520380` are **1,590** and **1,062**.  The
totals in that table reconciled with the gate, so only those two rows were misreported -
they must have been taken from a run whose columns were shifted.

The same recount is the useful evidence for this turn's work, because it isolates what the
rewrites actually did (b1520380 -> 7da6b053):

```
in_stack_[_0-9A-Za-z+]   1590 -> 1590   (+0)     <- none introduced
bStack_                  1062 -> 1004   (-58)
[iusbc]Var[_0-9]        30275 -> 29436  (-839)
```

so the eleven clean-function rewrites removed 839 `Var` matches and 58 `bStack_-family`
matches, and touched no `in_stack_` at all.

  grep_checks 48,982 -> 47,719 this turn (-1,263); build 65/65 clean; LINK.LOG 65 bytes /
  0 problems; compare_state 1,627/0/0; diff_dgroup 972/1,868;
  compare_runtime 1,546/11 main entry, 1,545/11 post-init_cfg

### Assembly listings are now available, and they close the `driver_fillRect` gap

`scripts/build_standalone.py --asm` (optionally with `--only <module>`) swaps `-c` for `-S`
in the same BCC invocation, so the listing shows exactly the code the real build compiles:

```
python scripts/build_standalone.py --only o01 --asm
  -> tmp/buildsrc/O01.ASM   (95,205 bytes, source interleaved with assembly)
```

That turns several earlier "rests on reasoning" claims into measurements.  `driver_fillRect`
(2d63:05e5) compiles to:

```
 3060  mov  ax, word ptr [bp+16]      ; dstSeg - the 6th argument, 0x10 = 16
 3061  mov  word ptr [bp-6], ax       ; ... which becomes the far pointer's SEGMENT word
 3062  mov  word ptr [bp-8], dx       ; ... with the offset beside it
 ...
 3102  les  bx, dword ptr [bp-4]      ; load ES:BX from that far pointer
 3103  mov  al, byte ptr [bp+14]
 3104  mov  byte ptr es:[bx], al      ; the fill, through ES
 ...
 3143  pop  di
 3144  pop  si
 3145  leave
 3146  ret                           ; AX never set - the function returns nothing
```

So the segment really does come from `dstSeg`, and the `void` return really is unset.  Note
the selector differs from the original (`es:[di]` with `rep stosb` there, `les`+`es:[bx]`
per byte here) - that is code shape, which AGENTS.md does not require to match, unlike the
data it writes.

Two things this unlocks for later turns:

* any fix that claims to change *code shape* (segment selection, a call's argument order, a
  widened type) can be checked against the original's instructions instead of argued;
* the listing is the natural place to confirm a signature repair, because the `[bp+N]`
  offsets it emits are the ABI itself - e.g. `distances` like `[bp+16]` above show where the
  compiler believes each argument lives.

  build 65/65 clean; LINK.LOG 65 bytes / 0 problems; grep_checks 47,227
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### `--asm` limitation: assembly output can hit a compiler table limit, and the probe workaround

`scripts/build_standalone.py --asm` is not usable on every module.  `o45.c` (the build's name
for `ovc45_unitinfo.c`) fails with

```
Error o45.c 3853: Compiler table limit exceeded in function ovc45_buildPlacementMessage
```

under `-S` even though the same module compiles cleanly with `-c`.  `-S` keeps the same
backend but writes assembly, and that path hits an internal table limit in a different
(large) function, so the whole module is rejected and no listing is produced.

Workaround, used for `ovc45_compute1`: extract just the function into a one-module probe and
compile that with `--keep-stage`, so staging does not overwrite it:

```
tmp/buildsrc/probe.c  =  #include "st.h"  +  <the function>
python scripts/build_standalone.py --keep-stage --only probe --asm
```

That yields a listing of exactly the function under study.  Delete `probe.c` afterwards: a
stray definition of a function that also lives in its real module breaks the next link with
a duplicate-symbol error.

The listing settled `ovc45_compute1` completely: our rebuild has 6 return-0 sites
(`xor ax,ax` followed by the epilogue) and 1 return-1 site, matching the original's six
`mov al,0` (0x6A483, 0x6A4B5, 0x6A4ED, 0x6A542, 0x6A573, 0x6A5AA) and one `mov al,1`
(0x6A5AE).

Note also that this class of fix barely moves the gate: `extraout_AH` is not one of the
section-5 patterns, so correcting three garbage returns moved `grep_checks` by 1.  It is
worth doing for behaviour, but it is not a way to reach zero.

  grep_checks 46,742 -> 46,741; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868;
  compare_runtime 1,546/11 main entry, 1,545/11 post-init_cfg

### Two scanners for the 16-bit-width / far-pointer defect families

`tmp/find_width_defects.py` looks for both families at once, and
`tmp/check_gmapflag_ptrs.py` tells whether a candidate pointer has a single role.

**(A) `uint *` views over a 16-bit array.**  Ghidra types a `GMapFlags` element as `uint`, so

```c
puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
```

makes every access four bytes wide: `*p = *p | 3` becomes a dword write and `p + 1` steps 4
bytes.  The original is unambiguous - `ovc23_rebuildDirectionFlags` (55fe:0f39) has
`and word ptr es:[bx], 0xff0f` at 048D5F and `or word ptr es:[bx], ax` at 048D9E;
`init_rebuildMapFlags` (3381:0693) has `or word ptr es:[bx], 1` at 025D49.

Measured: **18 sites in six modules, ten distinct pointer/function pairs.**  Eight pairs are
single-role and were corrected (8 declarations, 20 casts to `uint16_t *`):

```
ovc09_init.c        init_rebuildAllDirectionFlags, init_rebuildMapFlags, init_usesGMapFlags3
ovc14_attact.c      attact_usesGMapFlags3
ovc18_leaderview.c  ovc18_usesRandBelow
ovc23_bldrec.c      ovc23_rebuildDirectionFlags, ovc23_placeBuilding, ovc23_drownUnitsAt
```

Two pairs remain, deferred because the pointer is reused for other things:
`ovc22_textRingProt`'s `puVar3` (25 non-GMapFlags assignments) and `upd_usesAlignUp4`'s
`accLo` (12).  The rebuild's listing confirms the fix produces 16-bit ops (`and ax,65295`
= 0xFF0F, `and ax,65532` = 0xFFFC).

**(B) `CONCAT22(<never-written local>, ...)`.**  This is the `uStack_6` / `uStack_a` case in
`ovc13_usesAlignUp4`, where a far pointer was rebuilt each iteration on a segment word that
nothing ever wrote.  First measurements were polluted by `CONCAT22(1, ...)` /
`CONCAT22(2, ...)` literals being read as names; tightened to identifiers, the true count is
**4 functions / 5 slots**, and every one is a *register* pseudo-variable rather than a stack
slot:

```
ovc09_init.c     copyProtectionCheck   2x in_DX
ovc11_audio.c    sfxInit               1x in_DX
ovc20_stash.c    stshInitAudioAssets   1x unaff_DI
ovc48_assets2.c  init_assets2          1x unaff_DI
```

So the mechanical half of family (B) is exhausted - the remaining cases are far pointers
split across registers, which need the call sites read (the same class as `stshRead` and
`ovc23_textAdlibNone`), not a declaration change.

Neither family moves `grep_checks`: `uint`/`uint16_t` and `in_DX` are not section-5 patterns.
Their value is entirely that the data written is now the right width.

  grep_checks 46,469 (unchanged by the eight width fixes); build 65/65 clean;
  LINK.LOG 65 bytes / 0 problems; compare_state 1,627/0/0; diff_dgroup 972/1,868

### Caller-side analysis of `driver_scan2`: it is a tail block of a stub

`driver_scan2` (2d63:098a) is `__cdecl16near`, so its caller must be in the same segment.
Scanning segment 2d63 for `e8 rel16` with `ip+3+rel == 0x098a` finds exactly two sites:

```
file 0x1FD62  ip 0932   call 0x1FDBA
file 0x1FDAF  ip 097F   call 0x1FDBA
```

and the second is immediately followed by the routine's epilogue
(`pop ds / pop es / pop di / pop si / mov sp,bp / pop bp / retf` at ip 0982-0989).  The
enclosing routine is `driver_compute5` (2d63:0846, 324 bytes, i.e. 0x846..0x98a), so
`driver_scan2` is not a function at all - it is a block of `driver_compute5` that was split
out and reached with `call`, relying on `driver_compute5`'s frame.

That also identifies every "unauthenticated" register: `unaff_BP` is the caller's BP,
`unaff_SI`/`unaff_DI` are the two cursors, `in_CX` is the caller's loop count, and the block
reads the caller's locals:

```
01FDBA  mov bl, [bp - 6]      ; DDA remainder step      (byte)
01FDBD  mov bh, [bp - 0x10]   ; y-step base             (byte)
01FDC0  mov dl, [bp - 2]      ; x delta / 2             (byte)
01FDC3  mov dh, [bp - 0xc]    ; y delta                 (byte)
01FDC6  mov al, [bp + 0x12]   ; colour - a *parameter*  (byte)
01FDDB  add si, [bp - 4]      ; cursor step             (word)
01FDE2  add si, [bp - 8]      ; major-axis bias         (word)
01FDE5  add dl, [bp - 0xa]    ; ...                     (byte)
01FDE8  add di, [bp - 0xe]    ; ...                     (word)
```

**The important part.**  Our `driver_compute5` is a 23-line stub: it sorts `y1`/`y2`/`y3` and
calls `driver_scan2()` twice.  Nothing in it computes `[bp-2]`, `[bp-4]`, `[bp-6]`, `[bp-8]`,
`[bp-0xa]`, `[bp-0xc]`, `[bp-0xe]`, `[bp-0x10]` or `[bp-0x12]` - those assignments live in the
324-byte body that was attributed to `driver_scan2` and lost.  So this routine is not
"misnamed": as recovered it draws nothing, because the block reads a frame nobody fills and
our build gives it an uninitialised `unaff_BP`.  The same is true of `driver_drawLine`'s
`driver_drawLine_compute()` sub-call and the other `*_compute` fragments.

Fixing it properly means re-deriving all 324 bytes of `driver_compute5` (ip 0x846..0x98a) and
inlining the block at both call sites - a full function rewrite against the disassembly, not a
rename.  Deliberately not attempted in a cramped pass, because a wrong DDA silently corrupts
every line the game draws.

  grep_checks 45,571; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### `ovc15_textError` is 449 bytes with a 7-case jump table, not 163

`audit/functions.tsv` lists 163 bytes, which is what made the "163 bytes of code, 971 lines of
C" ratio look impossible.  Measuring the code directly settles it: the function spans
ip **0x26bc..0x287c**, ending at the `retf` at 0x287C, so **449 bytes** - the same
functions.tsv understatement already recorded for `ovc23_textAdlibNone`.

What it actually is:

```
ip 26C3  les bx,[bp+6] ; al = es:[bx+0x1a]        ; a far pointer parameter
ip 26CF  les bx,0070:[al*4] ; dx = es:[bx], ax = es:[bx+2]
ip 26E6  les bx,[bp+6] ; al = es:[bx+0xd] ; *0x95
ip 26FB  al = es:[bx+0x271c] ; [bp-1] = al ; 0xff -> 0
ip 270F  cmp bx,6 / ja default / jmp word ptr cs:[bx+0x287d]
ip 287D  jump table = 2725 274B 2771 2797 27BD 27DD 2811
ip 2843  exit: ax:dx = [bp+0xa..0xc]; if zero return it unchanged
         else push 0 / push 0x64 / push (si+0x64 as 32-bit)
              lcall 0,0x938 then lcall 0,0x9c4, store dx:ax back
ip 287A  pop si / leave / retf
```

So the seven cases compare bytes `agnt->+0x29`, `+0x2a`, `+0x2c` against thresholds and set `si`
to 0, 5 or 0xa, and the shared exit scales that via two 32-bit runtime calls.  The declared
signature `(uint32_t partyIndex, agnt_t *agnt)` is also wrong: the original's first parameter is
a **far pointer** (`les bx, ptr [bp+6]`) and its second is a **32-bit value at [bp+0xa..0xc]**
that is both read and returned in `dx:ax`.

**Correction to the previous entry.**  The label `L_attact_3f0b_1082_130A` appearing inside the
body is a Ghidra *block* label, not proof that segment-3f0b code was absorbed: the block it
names is this function's own shared exit at ip 0x2843.  The 971-line C body is large because the
switch has seven cases with long expressions and the exit does 32-bit arithmetic - not because
foreign code was merged in.  The earlier note saying otherwise is withdrawn.

Re-deriving it means reading all seven cases plus the semantics of `lcall 0,0x938` and
`lcall 0,0x9c4`; it is a self-contained ~449-byte routine and a proper next job.

  grep_checks 45,444; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### The two 32-bit helpers in `ovc15_textError` are LXMUL and LDIV

`lcall 0,0x938` and `lcall 0,0x9c4` were the blocker.  Reading the code at those two module
offsets settles them (load module starts at file 0x1E00, so offset 0x938 is file 0x2738):

**0x938 = long multiply (LXMUL).**

```
2738  56        push si
2739  96        xchg si, ax
273A  92        xchg dx, ax
273B  85 c0     test ax, ax
273D  74 02     je  ...
273F  f7 e3     mul  bx
2741  e3 05     jcxz ...
2743  91        xchg cx, ax
2744  f7 e6     mul  si
2746  03 c1     add  ax, cx
2748  96        xchg si, ax
2749  f7 e3     mul  bx
274B  03 d6     add  dx, si
274D  5e        pop  si
274E  cb        retf
```

the three `mul` with the `jcxz` shortcut is Turbo C's 32x32 multiply.

**0x9c4 = long divide (LDIV) entry dispatcher.**

```
27C4  33 c9           xor cx, cx        ; unsigned case
27C6  eb 16           jmp  shared
27C8  59 0e 51 b9 01  pop cx / push cs / push cx / mov cx,1
27D0  59 0e 51 b9 02  ...            mov cx,2
...
27D8  55 56 57 8b ec 8b f9             push bp / push si / push di / mov bp,sp / mov di,cx
```

the four entries tag the sign case in CX and fall into the shared body, which is the LDIV/LUDIV
family.

**Corroboration**: the recovered tree already renders exactly these two call sites as
`LXMUL_at_` and `LDIV_at_` (ovc15_sprite.c:2000 and :2002), so the identification agrees with
what the decompiler concluded independently.

The same lines also show how mangled that region still is: the multiply's return storage is
rendered as `(long *)((int)&GSTARTX_SavedVectors[2].ofs + 1)` - a saved-interrupt-vector global,
not a return slot - and its first argument as `ZEXT24(unaff_SI) << 0x10`.  The `unaff_SI`
fragment and the bogus return storage have to be resolved as part of re-deriving the function,
not just its switch.

Note: neither `lcall` has an MZ relocation covering its segment word (the file value is 0 and no
relocation entry lands on module offsets 0x348D5/0x348DC, checking both indexing conventions),
so segment 0 there is not DOS-patched.  How it resolves at run time is still unexplained, but it
is not needed for the source-level rebuild: the tree calls the two routines by name.

  grep_checks 45,444; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### `ovc15_textError`: the seven cases decoded; the exit's long arithmetic is still the blocker

Full decode of 4207:26bc..0x287c.  Parameters: a **far pointer** at [bp+6] (call it `agnt`) and
a **32-bit value** at [bp+0xa..0xc] read and returned in `dx:ax`.

Selector:

```
26C3  les bx,[bp+6] ; al = es:[bx+0x1a]
26CF  les bx,0070:[al*4] ; dx = es:[bx], ax = es:[bx+2]   -> [bp-6] = offset, [bp-4] = seg
26E6  les bx,[bp+6] ; al = es:[bx+0xd] * 0x95
26FB  al = es:[bx+0x271c] (es=0x60) ; [bp-1] = al ; 0xff -> 0
270F  si = 0 ; switch ([bp-1]) with 7 cases, default -> exit
287D  table = 2725 274B 2771 2797 27BD 27DD 2811
```

With `agnt` as the far pointer loaded from [bp-6] and `v(x) = agnt->+x`:

| case | entry | rule |
|---|---|---|
| 0 | 2725 | `v(0x29) >= 0x10 ? 10 : v(0x29) >= 0xd ? 5 : 0` |
| 1 | 274B | same with `v(0x2a)` |
| 2 | 2771 | same with `v(0x2b)` |
| 3 | 2797 | same with `v(0x2c)` |
| 4 | 27BD | same with `v(0x29)` (identical to case 0) |
| 5 | 27DD | `10` if `v(0x29)>=0xd && v(0x2a)>=0x10`; `5` if `v(0x29)>=0xd && v(0x2a)>=0xd`; else `0` |
| 6 | 2811 | `10` if `v(0x29)>=0xd && v(0x2c)>=0xd`; `5` if `v(0x29)>=0xd || v(0x2c)>=0xd`; else `0` |

(each case starts by reloading the far pointer with `les bx, ptr [bp-6]`; the `si` register is
the accumulator and starts at 0, so a case that never writes it leaves 0.)

Shared exit at 0x2843:

```
2843  ax = [bp+0xa]; or ax,[bp+0xc]; je return-unchanged
284B  push 0 / push 0x64              ; the 32-bit constant 100
284F  ax = si; cdq; add ax,0x64; adc dx,0 ;     ; dx:ax = si + 100
2858  push ax / push dx
285A  dx:ax = [bp+0xa..0xc]           ; the 32-bit parameter
2860  pop cx / pop bx                 ; bx:cx = si + 100
2862  lcall 0,0x938                    ; LXMUL
2867  push dx / push ax
2869  lcall 0,0x9c4                    ; LDIV
286E  [bp+0xc] = dx; [bp+0xa] = ax     ; store the result back
287A  pop si / leave / retf
```

So it computes roughly `(param * (si + 100)) / 100` and returns it in `dx:ax`, leaving the
untouched value when `param == 0`.

**What still blocks the rebuild**: the exact argument convention of LXMUL/LDIV here.  The pushes
before LXMUL total 8 bytes (`0`, `0x64`, then `si+100`), of which `pop cx/pop bx` consumes 4, and
neither `lcall` is followed by `add sp` - so the helpers must pop their own arguments.  Matching
that to the tree's declarations (`long *LXMUL_at_(long *__return_storage_ptr__, long a, long b)`
and `long LDIV_at_(long a, long b)`) is not something I can do by inspection alone, and the
tree's own rendering of this very call site is visibly wrong: it passes
`(long *)((int)&GSTARTX_SavedVectors[2].ofs + 1)` as the "return storage" - a saved-interrupt-
vector global - and `ZEXT24(unaff_SI) << 0x10` as an operand.

Rather than guess at the numeric path, the case table above is recorded so the switch half can be
written immediately once the arithmetic convention is settled.

  grep_checks 45,444; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### MEASURED: the Turbo C long multiply/divide convention (probe, not inference)

A probe module compiled with the tree's own flags (`-mm -1 -G -O -Z -d`, `-c` swapped for `-S`):

```c
long gA, gB, gC;  unsigned long uA, uB, uC;
void probe_mul(void)   { gC = gA * gB; }        void probe_div(void)   { gC = gA / gB; }
void probe_umul(void)  { uC = uA * uB; }        void probe_udiv(void)  { uC = uA / uB; }
```

produced:

```
; gC = gA * gB                                ; gC = gA / gB
mov cx,word ptr DGROUP:_gA+2                  push word ptr DGROUP:_gB+2
mov bx,word ptr DGROUP:_gA                    push word ptr DGROUP:_gB
mov dx,word ptr DGROUP:_gB+2                  push word ptr DGROUP:_gA+2
mov ax,word ptr DGROUP:_gB                    push word ptr DGROUP:_gA
call far ptr F_LXMUL@                         call far ptr F_LDIV@
mov word ptr DGROUP:_gC+2,dx                  mov word ptr DGROUP:_gC+2,dx
mov word ptr DGROUP:_gC,ax                    mov word ptr DGROUP:_gC,ax
```

so:

* **`F_LXMUL@`** takes `CX:BX` = a and `DX:AX` = b, returns `DX:AX` = a*b, and touches no
  stack.  It is used for *both* signed and unsigned multiply (`probe_umul` emits the same call).
* **`F_LDIV@` / `F_LUDIV@`** take their two longs **on the stack**, pushed second-argument
  first and high-word first (`push b.hi / b.lo / a.hi / a.lo`), return `DX:AX`, and **pop their
  own arguments** - the compiler emits no `add sp` after the call.

That settles `ovc15_textError`'s exit exactly: `push 0 / push 0x64` leaves the divisor 100 on the
stack, `pop cx / pop bx` puts `si+100` into `CX:BX`, `DX:AX` is set from `[bp+0xa..0xc]`, and
`F_LXMUL@` then `F_LDIV@` compute `(value * (acc + 100)) / 100`, storing `dx:ax` back.  Nothing
needs to be guessed.

**Consequence for the tree.**  `st_functions.h` currently declares

```c
long * __cdecl16far LXMUL_at_(long *__return_storage_ptr__,long a,long b);
long   __stdcall16far LDIV_at_(long a,long b);
```

and call sites pass a fabricated "return storage pointer" - in `ovc15_textError` that pointer is
`(long *)((int)&GSTARTX_SavedVectors[2].ofs + 1)`, a saved-interrupt-vector global.  Those
declarations cannot express a register-passed multiply, so an explicit call to them can never
reproduce the original.  The correct recovery is to write the **plain C arithmetic** (`a * b`,
`a / b`) and let the compiler emit `F_LXMUL@`/`F_LDIV@` itself, exactly as the probe does.  That
applies to the three sites that call the helpers by name: `ovc15_textError`, `ovc36_usesLDIV_at_`
and `ovc15_usesLDIV_at_`.

Probe module deleted afterwards (a stray `probe.c` defining probe_mul etc. is harmless at link
but should not linger).

  grep_checks 45,444; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### `ovc15_textError`'s C body is not that function at all (mis-attribution)

The last blocker for rebuilding it turns out to be upstream of the code.  The real function at
4207:26bc..0x287c is 449 bytes: a two-parameter prologue (`les bx, ptr [bp+6]` and a 32-bit
argument at [bp+0xa..0xc]), a 7-case jump table at 0x287d, and `retf` at 0x287c - the table
fills 0x287d..0x288a exactly up to the next function at 0x288b.

The C body currently sitting under that name is **969 lines** of heap-and-audio code:
`switch(uVar17)` with `LXRSH_at_`, `HeapPtr`, `MUSHandle`, `DIGHandle`, `LXMUL_at_` - none of
which appears anywhere in the 449 bytes.  Density settles it:

```
driver_compute5       175 lines / 324 bytes   = 0.54 lines/byte
ovc13_usesAlignUp4    161 lines / 1005 bytes  = 0.16
ovc15_textError       969 lines / 449 bytes   = 2.16
```

roughly four times the densest comparable function, i.e. the body is ~2,000 bytes of code.

So the name and address comment (`/* 4207:26bc */`, which occurs exactly once) are attached to
some *other* function's text.  Two consequences:

* **the section-5 mass attributed to `ovc15_textError` belongs elsewhere**, so any ranking or
  pool figure that counted it is mis-assigned - including the earlier note that the clean/dirty
  split has 132 dirty functions;
* writing the real 449-byte routine is now a *replacement*, and before that the existing body
  must be identified and moved to its true owner, or the reverse-engineering loses ~2,000 bytes
  of recovered code.

What is already in hand for the replacement, and does not need re-deriving: the seven-case table
(cases 0-4 one-field against +0x29/+0x2a/+0x2b/+0x2c with 0x10->10, 0xd->5; case 5 two-field
AND/AND; case 6 both->10, either->5), the exit `(value * (acc + 100)) / 100` with the
F_LXMUL@/F_LDIV@ convention measured last turn, and the corrected signature.  The one remaining
unknown is the C idiom for the selector byte read at segment 0x60 offset `+0x271c` (indexed by
`agnt->+0xd * 0x95`).

  grep_checks 45,383; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### Density check across the tree: it flags size-table errors, not mis-attributions

`tmp/density_check.py` compares each C body's line count with the size in
`audit/functions.tsv`.  Ten of 255 functions exceed 1.0 lines/byte:

```
lines/tsv  lines  tsv   module          function
17.27       2591  150   ovc49_agents.c  ovc49_body1                 8699:18c4
 8.61        921  107   ovc23_bldrec.c  ovc23_usesAlignUp43         55fe:0af5
 5.94        969  163   ovc15_sprite.c  ovc15_textError             4207:26bc
 4.40        801  182   ovc33_stats.c   stats_textRingProt          6386:0411
 3.23        766  237   ovc41_main.c    ovc41_usesBiosKeyAvail      6a8f:15a0
 2.94        315  107   ovc23_bldrec.c  ovc23_textConstructionAbandoned 55fe:0cdf
```

**But the ratio against the recorded size is the wrong test**, because those sizes are badly
understated for switch functions.  Measuring each function's real extent (linear sweep to the
`retf`) shows:

```
function                          tsv   real   lines  lines/real
ovc49_body1                       150   1329    2591    1.95     <- tsv 9x too small
ovc23_usesAlignUp43               107    482     921    1.91
ovc15_textError                   163    449     969    2.16
stats_textRingProt                182    422     801    1.90
ovc41_usesBiosKeyAvail            237    663     766    1.16
ovc23_textConstructionAbandoned   107    594     315    0.53     <- body is fine
```

Against real extents the band is 0.5-2.2, which is ordinary, so **density cannot identify a
mis-attributed body**.  My previous turn's claim that the density test would "find others in one
pass" was wrong on that point and is withdrawn.

**The test that works is content**: list the call sites inside the real byte range and compare
them with what the C body calls.

```
function                real  instrs  call sites  distinct  targets
ovc49_body1             1329    429        3         3      0x148:0x39, 0x170:0x5c, 0x148:0x34
ovc23_usesAlignUp43      482    184        1         1      0x158:0x6b
ovc15_textError          449    155        2         2      0:0x938 (LXMUL), 0:0x9c4 (LDIV)
stats_textRingProt       422    151       16         2      0:0x2d31 x15, 0x170:0x7a
```

`ovc15_textError` is conclusively mis-attributed: its range contains **only** the two long-arithmetic
calls, while the body under that name uses `LXRSH_at_`, `HeapPtr`, `MUSHandle` and `DIGHandle`.

**New suspect**: `ovc23_usesAlignUp43` (55fe:0af5) has **one** call site in 482 bytes but a 921-line
body - the same shape of mismatch, and worth the same treatment.  By contrast `ovc49_body1` (3
calls / 1329 bytes), `stats_textRingProt` (15 identical calls in a loop) and
`ovc41_usesBiosKeyAvail` are structurally consistent with their extents; they are large, not
wrong.

So: one confirmed mis-attribution (`ovc15_textError`), one to check (`ovc23_usesAlignUp43`), and
the important by-product that **`audit/functions.tsv` sizes cannot be trusted** (up to 9x low) -
which also invalidates any earlier estimate built on them.

  grep_checks 45,383; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### Measured extents for every function, and 13 badly understated sizes

`tmp/measure_extents.py` sweeps each recorded function start linearly to the first `retf`
(capped at the next recorded start or 0x2000 bytes) and writes
**`audit/functions_real.tsv`** with columns
`address, name, tsv_size, real_size, call_sites, distinct, targets`.

1475 functions measured.  Excluding the `ovr_*` 5-byte thunks (where a sweep is meaningless -
it just runs into whatever follows), **13 functions have a recorded size more than twice too
small**:

```
attact_usesAlignUp43               3f0b:1db1  tsv   118  real  1086  (9.2x)
ovc49_body1                        8699:18c4  tsv   150  real  1329  (8.9x)
__BootHandler                      2272:003f  tsv     5  real    36  (7.2x)
ovc23_textConstructionAbandoned    55fe:0cdf  tsv   107  real   594  (5.6x)
attact_usesGMapFlags3              3f0b:0c2a  tsv   221  real  1112  (5.0x)
uiMainMenuLoop                     4528:14b1  tsv   332  real  1573  (4.7x)
ovc23_usesAlignUp43                55fe:0af5  tsv   107  real   482  (4.5x)
manage_usesGUnitCount              4d05:23fc  tsv    75  real   325  (4.3x)
NextChar                           1000:20c1  tsv    40  real   147  (3.7x)
ovc41_usesBiosKeyAvail             6a8f:15a0  tsv   237  real   663  (2.8x)
ovc15_textError                    4207:26bc  tsv   163  real   449  (2.8x)
ovc43_usesFmFreeAudio              6fbe:0000  tsv   120  real   302  (2.5x)
```

### `ovc23_usesAlignUp43` is mis-attributed too (content mismatch)

Its 923-line body calls about fifteen distinct functions - `ovr_randBelow` x10, `printf` x6,
`ovc22_usesGUnits` x3, `ovr_alignUp4` x3, `_fmemset`, `ovr_fmVsprintf`, `ovr_play_sfx`,
`ovr_ovc25_tickCountdown`, ... - while its 482-byte range at 55fe:0af5 contains **one** call
site (`0x158:0x6b`).  Same defect as `ovc15_textError`.  Note the body also calls
`ovc23_usesAlignUp43` once, which is the handle for finding its true owner: whatever function
that body belongs to is a caller of this address.

### A caution about rewrites already made

The `attact_usesAlignUp43` entry is the worst of the 13 (tsv 118, **real 1086**, 9.2x).  That
function was rewritten earlier this session from a ~90-line exported body - so if the real
function is 1086 bytes, that rewrite covered **only the part the exporter emitted**, and the rest
of the function is absent from the tree.  The same question applies to the other large-ratio
entries that were touched.  This is not a naming problem; it means a body can be both correct as
far as it goes and incomplete, and neither `grep_checks` nor `compare_state` can see the
difference.

Consequence for planning: **use `audit/functions_real.tsv`, not `functions.tsv`**, and treat any
function whose body is much shorter than its measured extent as "partially recovered" rather than
"done".  The earlier session estimate of remaining work, which used `functions.tsv`, was
therefore optimistic on this axis at least, though it does not change the grep_checks total,
which is measured directly from the sources.

  grep_checks 45,332; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### Partially recovered bodies: the complement scan, and the worst case verified

`tmp/under_recovered.py` is the complement of the density check: it lists functions whose C body
is far *shorter* than the extent in `audit/functions_real.tsv`.  Normal functions sit at 0.1-0.6
lines/byte; below 0.10 the body covers only a fragment.

19 functions with an extent of at least 200 bytes fall below 0.10, worst first:

```
lines/B lines bytes module          function
0.016     18  1112 ovc14_attact.c  attact_usesGMapFlags3       3f0b:0c2a
0.066     38   579 ovc02_draw.c    draw_menuCursor             2e25:10c7
0.069     71  1029 ovc10_constr.c  constr_usesScreenOriginY    36ce:04e9
0.069     35   505 ovc13_panel.c   ovc13_drawHighlightedUnits  3d16:1b3b
0.069     39   562 ovc09_init.c    init_usesGMapFlags3         3381:2651
0.071    146  2046 ovc23_bldrec.c  ovc23_placeBuilding         55fe:1005
...
0.077     45   585 ovc09_init.c    init_rebuildMapFlags        3381:0693
0.077     48   624 ovc10_constr.c  constr_usesGMapFlags2       36ce:3172
0.077    333  4306 ovc10_constr.c  constr_usesBlitGfxRect2     36ce:1f99
```

**Caveat and verification.**  The sweep can over-reach when a function ends with a `jmp` to a
shared epilogue, so a low ratio is a candidate, not proof.  The worst case was checked directly:
`attact_usesGMapFlags3` at 3f0b:0c2a begins `push bp / mov bp,sp / sub sp,0x5c` (a 92-byte frame)
and has **no `retf` in the first 1112 bytes**, all its jumps staying inside the function
(`0x0CE3`, `0x0D04`, ...).  So it really is a large function and the 18-line body is a fragment -
confirmed, not a sweep artefact.

That makes three distinct integrity classes in the tree, all invisible to every gate:

1. **mis-attributed bodies** (`ovc15_textError`, `ovc23_usesAlignUp43`) - a body under the wrong
   name/address, provable by content mismatch;
2. **truncated bodies** (this scan) - a body covering only part of its function, provable by
   extent vs line count;
3. **understated size table** - `functions.tsv` up to 9x low, superseded by
   `audit/functions_real.tsv`.

Note `ovc23_placeBuilding` (0.071) is in this list, and it was re-derived earlier this session
from a 152-line exported body against a 2046-byte extent - so that rewrite, like
`attact_usesAlignUp43`, may cover only the exported fragment.

What this means concretely: **`grep_checks` counts tokens in whatever body exists, so a truncated
body scores as well as a complete one.**  The gate can therefore fall while the recovered program
becomes less complete, and the sessions' reductions should not be read as pure progress.

  grep_checks 45,332; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### CORRECTION: most of the "truncated bodies" were false positives; the real test is call counts

The 19-function list from `tmp/under_recovered.py` was read as bodies that cover only a fragment of
their function.  Comparing, for each one, the number of **call sites inside the measured range**
with the number of **call-like names in the body** shows that most were false positives, because
bodies written by hand are much more compact than Ghidra's output - 4-6 instructions per line
against ~1 - so a low lines/byte ratio alone proves nothing.

```
lines bytes sites calls  function                        verdict
18    1112    16     5   attact_usesGMapFlags3           TRUNCATED  (11 missing calls)
38     579     8     9   draw_menuCursor                 complete
71    1029    20    21   constr_usesScreenOriginY        complete
146   2046    56    68   ovc23_placeBuilding             complete  <- earlier rewrite IS full
333   4306    65    66   constr_usesBlitGfxRect2         complete
96    1086     9    13   attact_usesAlignUp43            complete  <- earlier rewrite IS full
26     340     1     2   ovc23_tickRecordsAt             complete
39     562     0    16   init_usesGMapFlags3             SUSPECT: 0 sites vs 16 calls
45     585     0    16   init_rebuildMapFlags            SUSPECT: 0 sites vs 16 calls
24     266     0     4   video_findAgentAt               SUSPECT: 0 sites vs 4 calls
82     946     0     1   agnt_remapGridRefs              SUSPECT
```

So the earlier alarm was mostly wrong, and two specific things follow:

* **`ovc23_placeBuilding` (56 sites / 68 calls) and `attact_usesAlignUp43` (9/13) are complete.**
  The previous entry's note that those rewrites "may cover only part of their functions" is
  withdrawn - the call counts match, so my compact rewrites do cover the whole functions.
* **`attact_usesGMapFlags3` really is truncated.**  Its 1112-byte range has 16 call sites; the
  18-line body references 5 (`driver_clearMapFlagsRect`, `ovc15_usesAlignUp42`,
  `draw_textGoldProvidesHousing` and the two tail calls).  Verified by instruction: the body
  covers the prologue (`lcall 0xe0,0x93`), the entity loop and the last two `lcall`s, while the
  region `0x0CFA..0x1042` - 14 call sites: `0x160,0x57`, `0x1a8,0x43` twice, `0x170,0x7a`,
  `0xf8,0x39`, `0x1a0,0x34` twice, `0x140,0x20` five times, `0x140,0x2a` - is absent.
* **A new class: bodies with many calls but a range with none.**  `init_usesGMapFlags3` and
  `init_rebuildMapFlags` each reference 16 call-like names while their measured ranges contain no
  call at all.  That is not truncation; it points at either a mis-attributed body or a wrong
  extent, and each needs the same content check used for `ovc15_textError`.

So `tmp/under_recovered.py` is useful only as a triage list; the **call-count comparison** is the
test that decides, and it should be applied before any body is extended.

  grep_checks 45,332; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868
