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

### Overlay callee identification: intersect per-offset candidates

`attact_usesGMapFlags3` cannot be finished without naming its 14 missing overlay calls, and
Ghidra's segment numbers (`22a6`) are the MZ module's, not the runtime ones (`0xe0`).  The
mapping is derivable: for a runtime segment S, every `lcall S,ofs` proves S's overlay has a
function at `ofs`, so S's overlay must be in the **intersection**, over all observed offsets, of
the overlays that have a function at that offset.  `tmp/overlay_segments3.py` does this and
writes `audit/overlay_segments.csv`.

Segments seen at many offsets resolve uniquely:

```
runtime  offsets  overlay
0x00e0      42    22a6    <- driver_clearMapFlagsRect at 22a6:0093
0x0148      20    22ff
0x0158      18    2315
0x0160      15    2322    <- ovc15_usesAlignUp42 at 2322:0057
0x0170      21    2337    <- stsprintf at 2337:007a
0x0188      11    234c
```

The two independently known callees from this function's own surviving body land on the right
overlays, which is what validates the method.

Then the callee is chosen among the candidates at that overlay by **argument shape and use**,
not by name similarity.  For `attact_usesGMapFlags3` (3f0b:0c2a, 1112 bytes) the ten `lcall`
sites that can be named with certainty are:

| site | call | evidence |
|---|---|---|
| `0xe0,0x93` | `driver_clearMapFlagsRect` | 7 words pushed, `add sp,0xe`; already in the surviving body |
| `0x160,0x57` | `ovc15_usesAlignUp42` | already in the surviving body |
| `0x1a8,0x43` | `alignUp4` | one word in, result used as a grid index |
| `0x170,0x7a` | `stsprintf` | buffer `[bp-0x5c]`, format at `DS:0x8a1`, `add sp,0x10` |
| `0x1a0,0x34` | `ovc23_isCursorAt` | two words (y,x), result tested with `or al,al` |
| `0,0x2747` | `printf` | `push word ptr es:[0x898e] / push ds / push fmt`, `add sp,6` |

Still unresolved, and left unnamed rather than guessed: `0xf8,0x39`, `0x140,0x20`,
`0x140,0x2a`, `0x1a0,0x4d`.  The argument shapes are known - `0xf8,0x39` takes 3 words and
returns nothing, `0x140,0x20` takes 2 words and returns nothing, `0x140,0x2a` takes none, and
`0x1a0,0x4d` takes none - but no candidate overlay has a matching prototype at the matching
offset, so the intersection for `0x140` and `0xf8` is still several overlays wide.  Two
plausible-looking answers were rejected on shape: `play_sfx` is at `22f8:0020` but takes three
arguments where the code passes two, and `ovc23_textBuildThfres01Lbm` at `236f:0020` is a
one-far-pointer call while that overlay's `0x2a` entry (`createConstructionRecordFar`) takes
nine arguments where the code passes none.

So finishing this function needs four more resolved callees, not more reading of its own code.
The cheapest next move is to widen the observed-offset set for `0x140` and `0xf8` by scanning
**every** `lcall` in the image rather than only those in the tree, which multiplies the
constraints.

  grep_checks 45,332 -> 45,304; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### Overlay map resolved, including all four calls that blocked `attact_usesGMapFlags3`

`tmp/overlay_segments5.py` fixes two flaws in the earlier passes and then closes the map by
bijection:

* **Do not scan every recorded function start.**  `functions.tsv` sizes are unreliable, so
  disassembling from a wrong start turns data bytes into bogus `lcall`s.  The symptom was
  decisive: segment `0x00e0`'s intersection became **empty**, which cannot be true of a real
  segment, so that run was contamination rather than evidence.  Only functions present in the
  recovered tree are scanned.
* **An overlay is loaded at one runtime segment**, so once a segment resolves uniquely its
  overlay is unavailable to the others.  Propagating that to a fixed point (6 rounds) resolves
  more than the raw intersection.

Result: **18 of 58 runtime segments resolved**, including every one this function needed:

```
runtime  offsets  overlay  what it settles
0x00e0      42    22a6     driver_clearMapFlagsRect (22a6:0093)
0x00f0      13    22bb
0x00f8      11    22c4     uiNotify (22c4:0039)
0x0138      10    22ef
0x0140      10    22f8     play_sfx (22f8:0020), stop_audio (22f8:002a)
0x0148      20    22ff
0x0158      18    2315
0x0160      15    2322     ovc15_usesAlignUp42 (2322:0057)
0x0170      21    2337     stsprintf (2337:007a)
0x0188      11    234c
0x0190      12    2356
0x01a0      12    236f     ovc23_isCursorAt (236f:0034), OVC23_55fe_29a2_entry (236f:004d)
0x01c8       9    2391
0x0230      20    23d5
```

`0x1a8` stays at seven candidates, but its call site pushes one word (the entity x) and uses the
result as a grid column, which is `alignUp4` (`2379:0043`).

### The complete call list for `attact_usesGMapFlags3` (3f0b:0c2a)

| ip | call | arguments the code actually pushes |
|---|---|---|
| 0C4D | `driver_clearMapFlagsRect` | 7 words, `add sp,0xe` |
| 0CFA | `ovc15_usesAlignUp42` | none, result into a byte local |
| 0D1D | `alignUp4` | 1 word (entity x), `add sp,2` |
| 0D21/0E17 | `alignUp4` | same |
| 0E58 | `stsprintf` | buf `[bp-0x5c]`, fmt `DS:0x8a1`, 4 vararg words, `add sp,0x10` |
| 0E62 | `uiNotify` | 3 words: the returned far string + `0xa000`, `add sp,6` |
| 0EAF/0F46 | `ovc23_isCursorAt` | 2 words (entity y, x), `add sp,4`, result tested with `or al,al` |
| 0F83/0F8D/101A/102E/1042 | `play_sfx` | 2 words: an id (0x24, 0x26, 0x5a, 0x23, 0x25) and 0, `add sp,4` |
| 1006 | `stop_audio` | none |
| 0,0x2747 | `printf` | `es:[0x898e]`, `DS:0x8da` format, `add sp,6` |
| 1079 | `OVC23_55fe_29a2_entry` | none |

**A prototype defect this exposed.**  `st_functions.h` declares
`play_sfx(int16_t track,int16_t type,uint16_t arg3)` and
`uiNotify(char *msg,uint16_t dst,uint16_t arg3)`, i.e. 3 and 4 words of arguments.  But at every
call site here the code pushes **2 words** for `play_sfx` and **3 words** for `uiNotify`
(far string + `0xa000`).  Stack accounting at `0x0DE7..0x0E67` confirms it: 9 words pushed before
`stsprintf`, `add sp,0x10` leaves exactly one (`0xa000`), and `add sp,6` after `uiNotify` clears
`dx:ax` plus it.  So the recovered prototypes over-count by one word.  Calls therefore have to
pass a trailing 0 to satisfy the declarations; the callee reads the same first arguments either
way.  This is recorded rather than silently "fixed", because the extra parameter may be
referenced by other recovered bodies.

### What the surviving body gets wrong

The tail currently calls `draw_textGoldProvidesHousing()`, but the final `lcall` is
`0x1a0,0x4d`, i.e. `OVC23_55fe_29a2_entry` (236f:004d).  `draw_textGoldProvidesHousing` is not an
overlay entry at all - it does not appear in `ovr_stubs.c` - so it cannot be reached by an
inter-segment `lcall`.  The replacement body should call `ovr_OVC23_55fe_29a2_entry()`.

  grep_checks 45,304; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### `attact_usesGMapFlags3`: every global resolved; the body now needs only transcription

The absolute offsets in the disassembly map to named DGROUP globals
(`audit/dgroup_data.csv`), and the two format strings are in the DGROUP string table:

| offset | symbol | role in this function |
|---|---|---|
| `0x7144` | `GameRunning` (bool) | if set, skip building the message (0x0DA2) |
| `0x0438` | `DebugVerbose` (bool) | gates the final `printf` (0x105B) |
| `0x07a7` | `CurSfxType3` (uint8_t) | set to 0xff just before the `0x5a` sound (0x1010) |
| `0x898e` | `GGameState` (undefined2) | set to 0x3d before the final report (0x104F) |
| `0x9097` | `EntityCount` | both loops |
| `0x908e` | `Entities` | both loops |
| `0x08a1` | `s_intelligence_reports_...` | `"Intelligence reports %s unit engaged in combat. (%d, %d)"` |
| `0x08da` | `s_d` | `"%d \r"` |

The `%s` argument at 0x0E45/0x0E4A is `AgntGs[gindex].name` (the far pointer stored at
`+0x24`), and the two `%d`s are `alignUp4(entX)` and `entY` - which is why four vararg words are
pushed and `add sp,0x10` clears them.

**One thing must be settled before writing it.**  The overlay wrappers are declared
`undefined ovr_xxx()` - unprototyped - in `st_functions.h`.  That is fine for the void calls,
and for `play_sfx`/`uiNotify` it is actually *more* faithful than the typed prototypes (an
unprototyped call passes exactly the words written, i.e. 2 and 3).  But `ovr_stsprintf` returns
a far `char *`, and an unprototyped call returns only `AX`, so on a large-model build the
segment half is lost.  Either the wrapper needs a real prototype, or the body must take the
returned pointer from an explicitly typed call.  Existing code that assigns
`ovr_stsprintf(...)` to a `char *` (e.g. `ovc13_usesAlignUp4`) has the same latent defect.

So the next attempt should first pick one of those two routes and check that the chosen one
still leaves every other caller compiling - that is the last open question, and it is a
declaration question, not a decoding one.

  grep_checks 45,304; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### Why the runtime instrument cannot simply call the rewritten routines

The existing dump harness is small and reusable: `tmp/dump_dgroup_stdout.py` patches an entry
point with

```
mov bx,1 / mov cx,0FFFFh / mov dx,0 / mov ah,40h / int 21h / exit
```

so 64 KB at `DS:0` goes to stdout, which the batch redirects to `DGR.BIN`; `scripts/run_original.py`
and `scripts/run_rebuilt.py` drive the two images through headless DOSBox-X.  Two facts make the
"invoke the function and diff the fields" plan harder than it looks:

* **our build is linked resident** (overlays are off by default), so in the rebuild any function is
  present at main entry and could be called by a probe;
* **in the original the two targets live in overlays that are not resident at the existing
  checkpoints** - `ovc15_textError` is in overlay segment 4207 and `ovc23_usesAlignUp43` in 55fe -
  so a main-entry probe in `game/STRONG.EXE` has nothing to call.  The overlay manager has to have
  loaded those segments first.

So the instrument splits into two halves of very different cost:

1. **Cheap half, available now:** because the rebuild is resident, a probe can call our compiled
   routine over an input matrix and compare the results with a reference implementation written
   from the same disassembly.  That catches *transcription* slips - the realistic failure mode, and
   exactly what the `ovc23_usesAlignUp43` cases-2-and-3 oddity would show up as - but it cannot
   catch a misreading of the original.
2. **Expensive half:** a third checkpoint deep enough into the game that overlays 15 and 23 are
   resident, driven with DOSBox-X `AUTOTYPE` to reach gameplay, dumping `DGROUP` plus the overlay
   data segments at the same instruction point in both binaries.  That is what would verify the
   decode itself, and it is a harness project rather than a single turn's addition.

Recording this so the next attempt starts from the constraint rather than rediscovering it.  The
six rewritten routines with real logic (`ovc15_textError`, `ovc23_usesAlignUp43`, `driver_compute5`,
`driver_drawLine`, `driver_fillRect`, `ovc18_usesAlignUp4`) remain verified only by decoding plus
compilation until at least half 2 exists.

  grep_checks 42,615; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### Measured: none of the state these routines read is observable at the checkpoints

`scripts/probe_fields.py` answers the question the checkpoints cannot: for each table that
`ovc15_textError` and `ovc23_usesAlignUp43` consume, is it visible in a DGROUP dump at all?
Reading the two `DGR.BIN` dumps by symbol (original offsets from `audit/dgroup_data.csv`, rebuilt
from `REBUILT.MAP`), at the main-entry checkpoint:

```
field              orig   ours   state at this checkpoint
AgntGs             -      -      not in DGROUP  (original)
Agnts              -      -      not in DGROUP  (original)
GLeaderSheets      -      077c   not in DGROUP  (original)
BuildingTypes      -      -      not in DGROUP  (original)
GUnitGrid          8a0d   8788   unpopulated: pointer slot 0000:0000 (both)
GUnits             8995   872c   unpopulated: pointer slot 0000:0000 (both)
GMapFlags          8a09   8784   unpopulated: pointer slot 0000:0000 (both)
GMapCells          8a05   8780   unpopulated: pointer slot 0000:0000 (both)
EntityCount        9097   8bdd   identical
GUnitCount         8999   8730   identical
GRecordCount       91df   8c46   identical
PlayerCount        91e6   8c4b   identical
GLeaderCount       90e6   8c1f   identical

not in DGROUP 4 | unpopulated 4 | populated 5
```

Three things follow, and they change the shape of the instrument:

* **Four of the eight tables are not in DGROUP at all.**  `AgntGs`, `Agnts`, `BuildingTypes` and
  (in the original) `GLeaderSheets` live in other segments, so **no DGROUP dump can ever see
  them**, no matter when it is taken.  In particular the leader-sheet ability bytes
  `+0x29..+0x2c` that `ovc15_textError` scores, and `BuildingTypes[..].byte_0x11e` that
  `ovc23_usesAlignUp43` tests, are outside DS.
* **The other four are far-pointer slots, and all four are `0000:0000` here.**  `GMapCells`,
  `GMapFlags`, `GUnitGrid` and `GUnits` are reached as `les bx, ptr es:[0x8a0d]`, so the DGROUP
  word is a pointer, not the table; at this checkpoint neither image has populated it.  A dump
  taken earlier than initialisation therefore shows nothing even for the ones that *are* in DS.
  (An earlier version of this script compared those offsets as if they held the table and reported
  thousands of "differences" - that was reading unpopulated BSS, not data.  Fixed.)
* **The five scalars are identical**, which is what `compare_state` already says.

So the instrument needs three things, in order: a checkpoint after the tables are built; the
pointer targets resolved out of the dump (since the table is not at the slot); and segments beyond
DS captured for the four that never appear in DGROUP.  The existing stub writes only `DS:0..#FFFF`,
which is why none of this was visible.

  grep_checks 42,505; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### The multi-segment dump works, and a DGROUP dump is not byte-stable

`scripts/dump_extra_segment.py` builds a stub that dumps **two** segments: first `DS:0..#FFFF`,
then - after `pop ds` restores DGROUP - the segment named by a 4-byte far pointer at a chosen
DGROUP slot:

```
  push ds
  mov bx,1 / mov cx,0xFFFF / mov dx,0 / mov ah,0x40 / int 21h     ; DS dump
  pop ds
  mov ax,[slot]                                                    ; offset
  mov ds,[slot+2]                                                  ; segment
  mov dx,ax / mov bx,1 / mov cx,0xFFFF / mov ah,0x40 / int 21h     ; target dump
```

39 bytes.  Tested with slot `0x033e`, which holds `1C33:0352` in the original's DGROUP - a pointer
back into DGROUP, chosen because no *non-DGROUP* pointer is populated at the main-entry checkpoint.
The run produced **131,070 bytes = 2 x 0xFFFF**, so the second write path works.  Both images get
the same stub shape with their own slot offsets, which is what makes the two dumps comparable.

Two things the test measured that the instrument has to account for:

* **The two blocks are not identical even when they name the same segment** - 7 bytes differ
  (first at `0x7001`).  That is not a stub bug: `int 21h` is issued twice and the bytes at the tail
  of the first write are re-read after DOS has touched the user's segment.
* **More importantly, the dump is not byte-stable between runs of the same binary.**  Two runs of
  the original differed in **26 bytes**: `0x0081..0x0083` (`_StartTime`) and a cluster at
  `0xa86e..0xa881`.  So a differential checkpoint cannot compare raw dumps; it needs an ignore set
  for these volatile bytes, the same way `compare_runtime` already tolerates its 12 CRT
  differences.

That settles why the existing checkpoints report "5 boundaries identical, 12 different": a handful
of CRT/start-up bytes move on every run regardless of the code under test.

Next for the instrument, in order: (a) choose a trigger function that both binaries reach after
initialisation - the natural choice is the function under test itself, patched at its entry, so
the dump is taken at its first call in the original; (b) drive the game there with
`AUTOTYPE` lines in the batch, which needs no runner change because DOSBox-X executes them from
`GO.BAT`; (c) compare with the volatile-byte ignore set above.

  grep_checks 42,463; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### CORRECTION: the stLoad/stSave stale-AH fix is shape-only, not a behaviour fix

Commit 4d904931 said "the two error paths were not benign" and implied that `return readOk & 0xff00`
misreported failure.  That is wrong, and the evidence is in the callers:

```
264  uVar1 = stLoad(handle);
266  return (char)uVar1;

288  uVar1 = stLoad(handle);
292  return (char)uVar1;
```

Both callers take the **low byte**, and in both cases the low byte was already correct before the
fix: the success exit was `CONCAT11(uVar4,1)` (low byte 1) and the failure exit `readOk & 0xff00`
(low byte 0).  `stSave` is the same - `CONCAT11(uVar4,1)` on success and `(uint)bVar5 << 8` on
failure, both with a correct low byte, and it has no in-tree callers at all.

So replacing those four returns with 1/0 changes only the **high byte**, which no caller reads.
The change is still right - the function returns 0/1 and the disassembly says so (`mov al,1` /
`mov al,0` at each exit) - but it is a shape and clarity fix, worth -9 on `grep_checks`, not a
correction of a live bug.  The dead `uVar4 = ...` stores that fed the old high byte are gone, which
is what makes the success path read `return 1;`.

The general lesson is the one already recorded for `ovc45_compute1` and `attact_isTerrainFlat`:
a stale-AH return is only a *behaviour* defect when some caller reads the high byte.  The
stale-AH scanner should therefore be paired with a caller check before the fix is described as
behavioural.

  grep_checks 42,341; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### MEASURED: this build passes data pointers as near - `-mm` is Turbo C's MEDIUM model

Trying to give the far-returning overlay wrappers real declarations exposed something larger.  A
one-module probe settles the pointer model:

```c
char *gp;
void probe_far(void) { *gp = 1; }
```

compiles with the tree's own flags to

```
_probe_far proc far
  push bp / mov bp,sp
  mov  bx, word ptr DGROUP:_gp        ; one word
  mov  byte ptr [bx],1
  pop bp / ret
```

A one-word load.  So `char *` is a **near** pointer, which means `-mm` in Turbo C 3.0 is **medium
model** (near data, far code) - not large, as the comment in `scripts/build_standalone.py` states
("large model (all pointers far, matching the original)").  That comment is wrong.

What follows:

* a far-returning declaration cannot help.  I changed `undefined ovr_stsprintf();` and
  `undefined ovr_stash_usesStExit();` to `char *` / `stg_tmp_t *` returning and rebuilt: the
  generated code was unchanged, storing only AX after the call, because a `char *` return is one
  word here.  The `ovr_*` symbols are far-jump thunks, so DX *does* carry the segment - the C type
  is what discards it.  Those declaration changes were reverted rather than left in as decoration.
* `(char *)CONCAT22(seg,ofs)` truncates to the offset.  This idiom is used throughout the tree for
  far strings and tables; under medium model the segment half is discarded and DS is assumed to be
  DGROUP.  That works for things inside DGROUP and cannot work for anything else.
* pointer **parameters** are one word where the original passes two.  `agnt_drawSpriteFrame`'s
  `brect_t *rect` is illustrative: the original pushes `[bp+8]` and `[bp+0xa]` for it, while a
  medium-model `brect_t *` is a single word.  The rebuild is internally consistent - every module
  is compiled the same way - but its pointer ABI differs from the original's.

This is a build-configuration question, not a per-function one, and it plausibly contributes to
`diff_dgroup` sitting at 972/1,868 while `compare_state` passes: symbol *values* match because the
comparison resolves them by name, but their *widths* need not.

Not changed here.  Switching the model is a large, measurable experiment (rebuild everything,
then compare `diff_dgroup`, `compare_state` and the runtime checkpoints) and should be done
deliberately rather than as a side effect of one function.

One fix did survive from that attempt, because it does not depend on the pointer model:
`agnt_drawSpriteFrame` now passes the constant `0x10` for the blitter type, as the original does
(the third parameter `type` is never pushed), instead of forwarding `(uint8_t)type`.

  grep_checks 42,261; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### The large-model experiment: 60/65 modules compile, the image does not link

The original's pointer model is confirmed from the callee side rather than inferred.  In
`agnt_drawSpriteFrame` (3b1d:1035) the parameters sit at

```
[bp+6]  byte  index
[bp+8]  word  rect.offset
[bp+0xa] word rect.segment      <- a 4-byte pointer argument
[bp+0xc] word type
```

and the function pushes `[bp+8]`/`[bp+0xa]` when forwarding `rect` to `blitGfxRect`.  So the
original passes pointer arguments as **two words** - far data, i.e. large model (code is far in both
medium and large, so the data width is the discriminator).

The one-flag experiment (`-mm` -> `-ml`), run on the whole tree:

```
compiled 60/65 modules, 61 errors in 5 modules
  o22.c    19   Nonportable pointer conversion in ovc22_textPOPULATION
  o23.c    10   Nonportable pointer conversion in ovc23_usesAlignUp43
  o48.c     2   Invalid combination of opcode and operands in init_assets2
  o49.c    28   Nonportable pointer conversion in ovc49_body1
  stubs.c   2   Invalid combination of opcode and operands in stsh_store
```

So 57 of the 61 are the **same class**, and it is the class the recovered code is saturated with:
`(T *)(integer)` conversions, which are near-pointer constructions under medium model and illegal
under large.  `ovc23_usesAlignUp43` is my own code - `(char *)(dir + 0x885)` is a DGROUP offset
turned into a pointer, exactly the idiom that has to become `MK_FP(_DS, ...)` for far data.  The
other four errors are inline-asm cases.

**The experiment is therefore inconclusive about `diff_dgroup`**: the image cannot link, so there is
nothing to compare.  It was reverted and `CFLAGS` is `-mm` again, now with a comment that states
what `-mm` actually is.  The earlier comment claiming `-mm` was "large model (all pointers far,
matching the original)" was wrong and is corrected.

What the experiment does establish: the switch is **bounded** - five modules, one dominant error
class, mechanically fixable by making those conversions explicit - and it is worth doing because
under medium model every `(T *)(integer)` silently truncates to a 16-bit offset, which is precisely
the kind of width defect that would keep `diff_dgroup` at 972/1,868 while `compare_state` passes.

  grep_checks 42,261 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### The `-ml` error inventory, and what is still needed to measure the switch

Collected the complete error list for the five modules that fail under `-ml`.  It is smaller in
kind than the 61 count suggests: 57 conversions, but concentrated in a handful of constructs.

```
o22.c   18   (12 in ovc22_textPOPULATION, 6 in ovc22_textRingProt)
o23.c    9   (4 in ovc23_usesAlignUp43, 5 in ovc23_textConstructionAbandoned)
o48.c    1   Invalid combination of opcode and operands  (init_assets2, inline asm)
o49.c   26   ovc49_body1
stubs.c  1   Invalid combination of opcode and operands  (stsh_store, inline asm)
```

The conversion sites are not the generic `(T *)(integer)` idiom as first assumed.  Spot-checking the
reported lines shows three distinct shapes:

```
((unit_t *)GUnits + idx)->bldType                       o23:968, 975, 982, 989
((entity_t *)Entities)[pcVar6].base.x                   o22:233, 236, 239
(byte *)(uint)bVar22                                    o23:1090
```

while nearby `(char *)(dir + 0x885)` (o23:961) does *not* error.  So the failing class is narrower
than "integer to pointer": `GUnits` and `Entities` are declared `T far *` in `st_globals.h`, and
casting a far pointer to `T *` plus array arithmetic is what the compiler rejects under large model,
not the integer casts.  Pinning down the exact rule needs a probe compile of one construct in
isolation - the same technique that settled the pointer model - rather than 52 blind edits.

That is where the conversion stands: inventory done, mechanism not yet identified, and the build was
returned to `-mm` (green) rather than left half-switched.  The next attempt should probe
`((unit_t *)GUnits + idx)->bldType` alone under `-ml`, decide the fix from the compiler's actual
message, then apply it uniformly.

  grep_checks 42,261; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### MEASURED: the `-ml` fix is the explicit dereference, not the `far` qualifier

The one-construct probe under `-ml` that settles the 57 conversions:

```c
byte p1(int x,int y){ return ((short (*) [148] [60])GUnitGrid)[x][y]; }          /* ERROR  */
byte p2(int x,int y){ short (*g)[148][60] = (short (*)[148][60])GUnitGrid;
                      return g[x][y]; }                                          /* ERROR  */
byte p3(int x,int y){ return GUnitGrid[x][y]; }                                   /* ok     */
byte p4(int x,int y){ return (*(short far (*) [148] [60])GUnitGrid)[x][y]; }      /* ok     */
```

`p1` is exactly what the recovered tree writes, and it is rejected.  `p3` (no cast at all) and `p4`
compile, and `p4` differs from `p1` in *two* ways, so the rule had to be narrowed by experiment:

* **adding `far` to the cast alone does nothing.**  `tmp/fix_far_casts.py` rewrote 7 of `o23`'s 9
  error lines to `(short far (*) [148] [60])` and the error set stayed identical - same 9 lines.
* **the explicit dereference is what works.**  Rewriting the four `GUnitGrid` reads to
  `(*(short (*) [148] [60])GUnitGrid)[x][y]` took `o23` from **9 errors to 5**, and the module
  compiles those four clean.

So the conversion rule is: a far pointer-to-array index must be written as an explicit dereference
of the cast, `(*(T (*) [..] [..])ptr)[i][j]`, rather than indexing the cast directly,
`((T (*) [..] [..])ptr)[i][j]`.  That is the form the compiler accepts when data is far.

The five errors left in `o23` are all real `(T *)(integer)` constructions and are *not* fixed by
this rule, because they are the thing the rule cannot express - a segment has to be supplied:

```
1086  (uint32_t *)((uint)(byte)(uVar43 >> 0x10) << 2)
1090  (byte *)(uint)bVar22
1093  pbVar20[0xd]                       (via 1090)
1103  (char *)CONCAT22(_DS, (char *)&GREC_FIELD(...))
1104  ...
```

These need `MK_FP(_DS, ofs)` (or a pointer taken from the object itself) instead of an integer cast.
That is the remaining work for the switch, and it is now a well-defined mechanical pass rather than
an open question.

The four dereference forms that do compile were applied to `ovc23_bldrec.c` and kept: they are
semantically identical to the cast form under `-mm` (which is why `grep_checks` does not move) and
are a prerequisite for the switch.

  grep_checks 42,261; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 972/1,868

### diff_dgroup 972 -> 1444: the pairing rule was comparing two different namespaces

`diff_dgroup --why` reports **`text absent from our data: 0`**.  Every string the original's DGROUP
holds is present in the rebuilt data.  So the 896 "unmatched" symbols were never a data gap, and the
question was why they were unmatched.

The answer is that the original's DGROUP contains labels that are **not legal C identifiers**:

```
2410:2a93  s_bighous1.lbm
2410:03e2  s_Mouse_error.
2410:2ad3  s_anim\2rdrag0.lbm
2410:0352  s_Bad_'game.cfg'_file._Please_reco_2410_0352
```

The build necessarily emits them with `_` in place of each illegal character
(`_S_BIGHOUS1_LBM_2410_2A93`), and `key()` compared the two names verbatim.  It was therefore
pairing a C-invalid name against its own sanitised form and reporting a miss.

Fix: apply the same sanitiser to both sides in `scripts/diff_dgroup.py`'s `key()`:

```python
k = re.sub(r"[^A-Z0-9_]", "_", k)
```

Measured effect: **matched 972 -> 1444 of 1868 (+472)**, while `distinct layout deltas` stays at 83.

That last number is the honest part of this entry: **the delta structure did not improve**, so no
layout gap was closed.  What changed is pairing accuracy - 472 symbols that were always the right
object in the right place are now correctly paired.

Bucket breakdown of the remaining 424, measured by `tmp/classify_unmatched.py`:

```
name > 30 chars (Turbo C public limit)   217
interior label (+N)                       63
C0 record field (.seg/.hi/...)            25
group/segment name (DATASEG/DGROUP)        2
other                                    117
```

Two of those are hard limits, not gaps:

* **Turbo C truncates publics at 31 significant characters**, so a 48-character original name such as
  `s_sorry_you_may_not_pass_time_during_a_battle` cannot be emitted at all.  Our build has
  `_S_SORRY_YOU_MAY_NOT_PASS_T_059E` - same string, truncated plus a discriminator.
* **Interior labels** (`s_divide_error+1`, `_DATA+2`) and **C0 record fields**
  (`_brklvl.seg`) are the original's debug record, not variables, and can never be publics.

### What the residual delta actually is: CRT link order, not missing data

The largest delta jump is at the very start of DGROUP, and the two layouts show why:

```
original : __C0_ASM_CopyRight 0004   s_divide_error 002f   _StartTime 0081
rebuilt  : __STARTTIME        0096   ___C0_ASM_COPYRIGHT 09f0   _S_DIVIDE_ERROR 0a1b
```

The original places the CRT's copyright string and the divide-error string *before* `_StartTime`;
our build places them ~2500 bytes *after* it.  Same objects, same bytes, different **order within
DGROUP**.  That ordering comes from the link order of the CO* modules, so it is a link-line
property, not a decompilation result - and it is harmless: every reference is symbolic, which is
why `compare_state` is 1627/0/0 and the runtime DGROUP checkpoints agree on every game symbol.

So `diff_dgroup`'s residual is now understood as: ~332 structurally unpairable symbols, plus a CRT
module-ordering difference, and no evidence of missing or wrong data.

  grep_checks 42,181; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1444/1,868 (83 distinct deltas, unchanged)

#### The rest of the diff_dgroup gap cannot be closed by tuning the pairing rule

The obvious follow-up is to strip the build's duplicate-discriminator suffixes too, since a
duplicate is emitted as `<name>_<address>` (e.g. `_DIGHANDLE_07BA` for the original's second
`DIGHandle` at 0x07ba).  `tmp/key_variants.py` scores five rules on both measures - matched count,
and the number of distinct deltas, which is the criterion the script exists for (a layout gap changes
the delta; a name gap does not):

```
pairing rule                  matched   deltas  in top delta
current (sanitiser only)         1444       82          606
+ strip _2410_XXXX               1467       83          607
+ strip _XXXX                    1448       86          606
+ strip both                     1471       86          607
+ strip _XXXX (any case)         1448       86          606
```

The best variant gains 27 pairs and **adds four distinct deltas** - i.e. it manufactures pairings
that do not hold, which is worse than not matching them.  So the pairing rule stays as committed
(sanitiser only), and the remaining gap is not a naming problem at all.

What it is, measured: **at most 606 of 1868** symbols sit in the largest constant-delta run, and
there are ~82 deltas.  That is a genuine layout difference spread through DGROUP, of which the CRT
module ordering shown above is one clear instance, not a gap that better keying can close.

  grep_checks 42,181; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### BuildingTypes was being read from DGROUP: 75 sites fixed, and the -ml block cleared

Investigating `ovc23_textConstructionAbandoned`'s `-ml` errors exposed a much larger defect.

Its residual errors were not the `(T *)(integer)` class at all.  They were `GRecords[pcVar12]` with
`pcVar12` declared `char *`, plus reads written as

```c
*(byte *)((uint)bldType * 0x27 + 0x11e)
```

which look like pointer arithmetic but are the export's **flattened absolute address** for
`BuildingTypes[bldType].flags`.  The proof is the original's own symbol table:

```
195d:010e   BuildingTypes
195d:0134   BuildingTypes[0].flags3      -> 0x134 - 0x10e = 0x26  = flags3
0x11e - 0x10e = 0x10 = flags
0x121 - 0x10e = 0x13 = flags2
0x133 - 0x10e = 0x25 = unitType
```

So Ghidra folded the array base (0x10e, in segment 195d) into every field offset.  In the original
that is harmless - the code says `mov dx,0x60 / mov es,dx / test es:[bx+0x11e]`.  In this rebuild
BuildingTypes lives in its own group (`6822:0000`), so `*(byte *)(idx*0x27 + 0x11e)` reads
**DGROUP+0x11e+idx*0x27**, an unrelated variable.  Every one of those reads was wrong.

`tmp/fix_bldg_fields.py` rewrites `*(T *)(<index> * 0x27 + 0x1XX)` to `BuildingTypes[<index>].<field>`
over a field table derived from the offsets above.  It refuses anything it cannot parse or whose
width disagrees: **75 sites rewritten across 14 modules, 5 left alone** (the high word of the
`action` far pointer at 0x116/0x118, and the high byte of `halfWidth` at 0x12d - all need an
explicit split rather than a field name).

Verified, not assumed: **all 248 records' non-pointer tails are byte-present in REBUILT.EXE**
(`tmp/verify_buildingtypes.py`), and the spot values cross-check against another function - buildings
1..3 have `flags3 == 1`, which is exactly the `flags3 == 1 -> allowed` case newly written into
`bldng_textArena`.  BuildingTypes is outside DGROUP, which is why `compare_state` never noticed.

### ovc23_textConstructionAbandoned (55fe:0cdf, 594 bytes) re-derived

315 lines -> 48.  Decoded from the listing with the jump table at ip 0x0f31 (targets 0x65, 0xe2,
0x166, 0x1dd):

```
if (attact_usesGUnits(x + dirX[dir], y + dirY[dir]) == 0) return 0;
switch (dir):
   0: GUnitGrid[x][y-1]   1: GUnitGrid[x+1][y]   2: GUnitGrid[x][y]   3: GUnitGrid[x][y]
   >3: return 0                                   ; cmp bx,3 / jbe
bldType = GUnits[idx].bldType;  if (>= 0xf8) return 0
if (dir is 0 or 2) require flags & 1  else require flags & 2;  then require flags & 0x20
```

Cases 2 and 3 read the same cell and share their direction bit, exactly as in the adjacent
`ovc23_usesAlignUp43` - two independently decoded functions agreeing on both quirks.  The signature
was wrong too: both parameters are words, not pointers (the caller already cast ints into them, and
the callee reads `mov si,[bp+6]` / `mov di,[bp+8]`), so it is now `(int x,int y,byte dir)`.

**This clears the `-ml` block for o23**: a full `-ml` build now reports
**61/65 modules, 51 errors** (was 60/65, 61), with o22 19, o49 28 and the two inline-asm sites
(o48 `init_assets2`, stubs `stsh_store`) remaining.  Still not linkable, so still no `-ml`
measurement.

  grep_checks 42,098 -> 41,307; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### The same flattening for AgntGs: 53 sites fixed, 32 documented as blocked

BuildingTypes had a second twin.  `AgntGs` lives at `195d:26d6` with a record stride of 0x95, and the
export reads it through a **surrogate base**:

```c
*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)gindex * 0x95)
```

`worldMenuLabels` is only there because Ghidra needed *some* expression with that numeric value; it
lives in DGROUP at 0x26f7 while `AgntGs` is in segment 195d, so the read goes to a completely
different variable.  Using the original's `AgntGs` label as the base, each surrogate computes to a
record offset:

```
[6].seg        0x2711 -> 0x3b  strength   (byte)
[6].seg + 1    0x2712 -> 0x3c  flags      (word)
[7].ofs + 1    0x2714 -> 0x3e  flags2     (word)
[7].seg + 1    0x2716 -> 0x40  flags3     (word)
[8].ofs + 1    0x2718 -> 0x42  rank       (byte)
[8].seg        0x2719 -> 0x43  shortName region
[9].ofs + 1    0x271c -> 0x46  shortName region   (30 sites - the largest single base)
```

Three of these are corroborated independently by the struct's own comments, which quote the
original's instructions: `flags2` at +0x3e ("TEST word ptr ES:[BX+0x3e],0x40") and `flags3` at
+0x40 ("TEST ...,0x100").  `tmp/fix_agntg_fields.py` converted the five documented bases - **53
sites across 12 modules, 0 refused** - and verified with `tmp/verify_agntgs.py`: **all 42 records'
non-pointer tails are byte-present in REBUILT.EXE**, so the table being indexed is the original one.

**The remaining 32 sites are deliberately not converted.**  They read offsets 0x43..0x48, which
`struct agntG_t` currently *names* `shortName[13]` with a GUESS comment saying no code reads it - yet
these sites compare those bytes to -1, 1, 0x12 and 0x0d, i.e. small enum values, not characters of a
name string.  So the field name is wrong, and rewriting 32 reads to `AgntGs[i].shortName[3]` would
bake the guess into code.  The offsets are known and recorded here; the field must be identified
first.

As with BuildingTypes, `grep_checks` does not move - these patterns are not among the section-5
greps - but every one of the 53 sites was reading DGROUP garbage.

  grep_checks 41,263 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### The `shortName` field was mis-documented, not mis-named: 49 more AgntGs sites fixed

The 32 sites left blocked last time read record offsets 0x43..0x48, which `struct agntG_t` named
`shortName[13]` with the comment "no code reader or writer exists".  The objective was to identify
the field.  The answer is that **the name was right and the comment was wrong**.

Two independent sources agree:

* the original's own symbols: `AgntGs[0].shortName[3]` at `195d:271c` (= base 0x26d6 + 0x46) and
  `AgntGs[0].shortName[4]` at `195d:271d`;
* the disassembly at `4207:25dd`:

```
les  bx,[bp+6] / mov al,es:[bx+0x0d]     ; entity->gindex
mov  dx,0x95 / imul dx                   ; record stride
mov  dx,0x60 / mov es,dx                 ; the 195d data segment
mov  al,es:[bx+0x271c]                   ; AgntGs[gindex] + 0x46
cmp  al,0xff / jne ...                   ; 0xff -> 0
dec  ax / cmp bx,5 / ja ...              ; switch (al - 1) case 0..5
```

So it is read as a small 0..6 code that selects a width/height pair, and `ovc15_sprite` also uses it
as `shortName[3] * 0x94 + level*4`, i.e. an animation-set index.  The field is an animation-set
selector that the original's debug info happened to name `shortName`; it is not text.

With that settled, `tmp/fix_agntg_fields.py` was extended with the five remaining bases:

```
[8].seg     0x2719 -> 0x43 shortName[0]     [8].seg + 1 0x271a -> 0x44 shortName[1]
[9].ofs + 1 0x271c -> 0x46 shortName[3]     [9].seg     0x271d -> 0x47 shortName[4]
[9].seg + 1 0x271e -> 0x48 shortName[5]
```

Result: **46 sites rewritten, 0 refused**, plus 3 sites that read a *word* at 0x48 (i.e.
shortName[5..6]) converted by hand to `AGNT_WORD(&AgntGs[i], shortName, 5)`.  The converter now
reports `rewritten: 0, refused: 0` and doubles as a regression guard.

Still unconverted, and recorded rather than guessed: about 20 sites that read the **`name` far-pointer
halves** (`[0].seg + 1` -> 0x24, `[1].ofs + 1` -> 0x26).  They become `SEG_OF(AgntGs[i].name)` and
`far_ofs_u32(AgntGs[i].name)`, but most of them use a pre-multiplied index (`iVar30`, `gOfs`,
`probeOfs`) rather than an explicit `idx * 0x95`, so the index has to be traced back to the agent
number first.  Those are a separate pass.

  grep_checks 41,263 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### A third flattening class: Agnts is at offset 0 of its own segment

`ovc27_usesBlitGfxRect` shows the next one:

```c
targetOfs = (uint)agnt->target * 0x34;
... *(uint *)(targetOfs + 0x26) ...      /* Agnts[target].screenX */
```

`0x26` is `agnt_t.screenX`, `0x28` is `screenY`, `0x17` is `entity`, `0x1d` is `gdata` - all correct
*field* offsets on a base of `index * 0x34`.

What makes this class different from BuildingTypes and AgntGs is that the offset is genuinely right
relative to the original's segment: the original's `Agnts` is at **`1726:0000`**, and ours is at
**`652A:0000`** - offset 0 of its own segment in both images.  So the arithmetic is not wrong; what is
lost is the **segment**.  `*(uint *)(index*0x34 + 0x26)` under this build forms a DS-relative near
pointer, and DS is DGROUP (6EFB...), not 652A, so it reads an unrelated variable.

64 lines across the tree use the `* 0x34` form, in several shapes:

* plain reads: `*(uint32_t *)(*cursor * 0x34 + 0x17)`
* pointer constructions handed to callees: `(agnt_t *)((x & 0xff) * 0x34 - 0x34)`
* offset values stored for later use: `CrossBlitX = (uint)crossAgentIndex * 0x34 + 0x26`

so the fix is not a single text substitution: the two latter shapes need the segment carried
(`MK_FP(SEG_OF(Agnts), ...)` or a real `&Agnts[i]`), and the first needs `Agnts[i].field`.  That is a
dedicated pass, recorded here rather than started.

### ovc27_usesBlitGfxRect: locals named, expressions untouched

Because the body is dominated by that class, re-deriving it properly means resolving `Agnts` first.
This commit only names the locals - `targetOfs`, `framesOfs`, `framesSeg`, `stateOfs`, `stateSeg`,
`xPos`, `spritePtr`, `spriteSeg`, `spriteLo`, `stash`, `agnt`, and `aimX` split out of the export's
two-role `iVar6` - with every expression kept byte-for-byte, so only register allocation differs.

  grep_checks 41,263 -> 41,190; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### Agnts/0x34, part 1: the hardcoded segment 0x1726 is replaced, and the rest is model-gated

Working the class turned up a shape that makes the `-ml` question concrete.

19 of the sites build the far pointer **by hand**:

```c
CONCAT13(0x17, CONCAT12(0x26, index * 0x34))
```

Since `CONCAT13(a,b) = a<<24|b` and `CONCAT12(a,b) = a<<16|b`, that value is `0x1726_XXXX` - segment
**0x1726**, which is exactly where `symbols.tsv` puts `Agnts` (`1726:0000`).  So the export embedded
the original image's segment as a literal.  Replacing it with `MK_FP(SEG_OF(Agnts), index * 0x34)`
gives the same pointer with this build's segment; because `Agnts` is at offset 0 of its segment, that
is also exactly `&Agnts[index]`.  **19 sites fixed** (1 in ovc27_combat, 18 in ovc49_agents), with one
explicit `(uint32_t)` added where the callee is declared `ovc27_rollToHitEntity(uint32_t agnt, ...)`.

The rest of the class **cannot** be fixed by rewriting text, and the reason is the pointer model:

```c
uint16_t __cdecl16far ovc49_agentIsActive(agnt_t *agnt);      /* near under -mm */
int      __cdecl16far ovc27_rollToHitEntity(uint32_t agnt, ...);  /* wants the far value */
```

Callees declared with a near `agnt_t *` cannot receive a far pointer at all under this build: the cast
`(agnt_t *)MK_FP(...)` truncates to 16 bits and the callee then dereferences through DS.  Under `-ml`
those same declarations become far and the calls are correct **with no source change**.

That reverses the direction of the `-ml` argument.  It is not only a theory about data layout: there
are 45 remaining `* 0x34` sites, and the ones that pass an agent to a near-`agnt_t *` callee are
broken now and fixed by the switch.  The switch is still blocked on the three type-mangled bodies
(o22, o49, and the two inline-asm sites), so the two problems are the same problem.

  grep_checks 41,190 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### Agent pointers are far now: 507 conversions, and the Agnts class mostly dissolves

The previous entry concluded that the remaining Agnts/0x34 sites could not be fixed under the medium
model because callees were declared with a near `agnt_t *`.  The remedy is the prototypes, not the
call sites: `agnt_t *` -> `agnt_t far *` everywhere (prototypes, definitions, locals, casts - 507
occurrences across 18 files).  Agents live in their own segment (original `1726:0000`, ours
`652A:0000`) while DS is DGROUP, so a near pointer could never reach them; far is also what the
original uses.

**It compiles and links clean on the first try**: 65/65 modules, LINK.LOG 65 bytes / 0 problems, and
every gate unchanged (grep_checks 41,119; compare_state 1,627/0/0; diff_dgroup 1,444/1,868;
compare_runtime 1,545/12).  The image grew 534,422 -> 536,822 bytes, which is the expected cost of
far accesses.

Verified at the instruction level rather than by the gates, since the gates cannot see pointer widths.
`agnt_usesStrengthMax` now begins:

```
les  bx, dword ptr [bp+6]      ; a 4-byte far pointer parameter
mov  al, byte ptr es:[bx+33]   ; +0x21 strength
cmp  al, byte ptr es:[bx+34]   ; +0x22 strengthMax
test word ptr es:[bx+43],2080  ; +0x2b flags
mov  bx, word ptr es:[bx+29]   ; +0x1d gdata (far pointer)
test word ptr [bx+60],32       ; agntG_t + 0x3c = flags
```

That is the original's whole chain - far agent, far `gdata`, into `agntG_t.flags` - and it was
previously four truncations.

What it fixes, by count:

* **52** functions taking an agent now declare and receive a far pointer;
* **79** call sites that cast `(agnt_t *)&Agnts[i]` no longer truncate to the offset;
* **2** sites that pass `MK_FP(SEG_OF(Agnts), index * 0x34)` now reach a callee that can accept it.

One side effect to note: `build_standalone.py --asm` now fails on `o49` with "Compiler table limit
exceeded in function ovc49_body1".  That is a listing-mode limit only - the `-c` build is clean - but
it means `ovc49_body1` can no longer be inspected through `--asm` and needs Ghost/Ghidra instead.

  grep_checks 41,119 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### agntG_t: 136 safe conversions, and one blanket change that would have been a regression

`agnt->gdata` is already `struct agntG_t far *` and `AgntGs` lives in its own segment, yet ~150 sites
cast it back down with `(agntG_t *)` - the same truncation just fixed for `agnt_t`.  A blanket
`agntG_t *` -> `agntG_t far *` compiled clean (65/65) and left every gate unchanged, so the gates said
"fine".  They were wrong, and the generated code showed it: about 18 sites cast an *integer* to the
pointer type, e.g.

```c
(agntG_t *)((targetOfs + 0x1d))->rank
```

and Turbo C compiles an int-to-**far** cast as

```
xor  ax,ax
mov  es,ax            ; segment 0
test word ptr es:[bx+89],4
```

i.e. it would read the **interrupt vector table**.  The previous near form at least read DS.  So the
blanket change was reverted and only the safe subset applied: casts whose operand is already a far
pointer (`(agntG_t *)agnt->gdata`), where far-to-far is exact - **136 lines across 7 files**, 65/65
clean, LINK.LOG 65 bytes / 0 problems, all gates unchanged.

The 16 integer-operand sites are listed by `tmp/far_agntg_safe.py` and left in their previous form:
each needs the agent index recovered (`Agnts[i].gdata`), and the base expressions are the
pre-multiplied `in_AX`, `uVar2` and `targetOfs`.

This is the second time in two turns that a mechanical pointer-width change compiled without error
and was still wrong; the check that caught it was reading the emitted instructions, not the gates.

  grep_checks 41,119 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### 12 of the 16 integer-operand agntG_t casts, and a bigger class found on the way

Fixed the twelve sites whose agent index is explicit in the C (a named local holding `index * 0x34`):

```
ovc27_usesRandBelow3    uVar2 = agntIndex * 0x34              -> Agnts[agntIndex].gdata
ovc27_spellNotice       targetOfs = paStack_6->target * 0x34   -> Agnts[paStack_6->target].gdata
ovc41_turnUndeadNotice  targetOfs = agnt_00->target * 0x34     -> Agnts[agnt_00->target].gdata
```

(One trap: replacing `->flags` first also matched the `->flags` prefix of `->flags2`/`->flags3`.  It is
harmless here because the trailing digit survives, but it means the later two patterns report "not
found" while the code is correct - checked by reading the result, not by trusting the counts.)

The four sites in `ovc27_compute1` and `ovc27_compute2` are still open because their index comes from
a local named `in_stack_00000008`, and that turned out to be the more interesting problem.

**`in_stack_00000008` is a phantom parameter - a local that is never assigned.**  In
`ovc27_compute1` the body declares `int in_stack_00000008;`, reads it four times as an agent index,
and never writes it, while the declared parameter `param` is never used.  The original reads
`[bp+0x0a]`, which is the second parameter, so the two are the same object and Ghidra failed to link
them.  Every read is uninitialised - the same class as the `AgntGs[iStack_c]` and `iVar6` defects
found earlier.

A scanner for it (`tmp/find_phantom_inparams.py`) reports **147 never-assigned positive-offset
`in_stack_` locals in 126 functions**, 136 of them outside the CRT.  That is the largest single
correctness class found so far, and the fix for each is mechanical but needs the parameter mapping
settled per function:

* for most functions the mapping is 1:1 - `agnt_usesStrengthMax` uses `in_stack_0000000a`/`_0000000c`
  and the disassembly reads `[bp+0x0a]`/`[bp+0x0b]`, `agnt_usesStExit` uses `_0000000e` and reads
  `[bp+0x0e]`;
* but `ovc27_compute1` uses `in_stack_00000008` where the original reads `[bp+0x0a]`, and
  `ovc27_compute2` uses the same name for what must be its *third* parameter (it is passed as the
  `agntIndex` argument of `ovc27_usesRandBelow3` while `param` is separately used as `mode`).

So the name is not a fixed offset, and the four remaining sites wait on per-function disassembly
rather than on a text substitution.

  grep_checks 41,119 -> 41,113; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### Four phantom parameters fixed, and a segment-0 regression from the agnt_t change reverted

`in_stack_00000008` was settled for all four functions by reading their prologues, not by assuming a
fixed offset:

```
ovc27_compute1             5ded:0404  les bx,[bp+6] and mov si,[bp+0xa]; bp+8 never read
ovc27_compute2             5ded:07d0  same two; the only bp+8 uses are `push [bp+8]/push [bp+6]`,
                                      i.e. re-pushing agnt, not a separate value
ovc27_rollAgainstStat      5ded:04cd  [bp+6] and [bp+0x0a] only
ovc27_textTakesHalfDamage3 5ded:10ea  [bp+6] and [bp+0x0a]; bp+8 only in the pointer re-push
```

So in all four the phantom local is a declared parameter - `param` in the two compute functions,
`mode` in rollAgainstStat, `agntIndex` in textTakesHalfDamage3 - and **14 reads** that were
uninitialised now read the real argument.  The two agntG_t sites in compute1/compute2 became
`Agnts[param].gdata->flags`, closing the last of the sixteen integer-operand casts.

The same investigation turned up a regression of my own.  The blanket `agnt_t *` -> `agnt_t far *`
change also rewrote casts whose operand is an **integer**, and Turbo C compiles int-to-far as
`xor ax,ax / mov es,ax` - segment 0, the interrupt vector table.  I had checked that trap for
`agntG_t` and not for `agnt_t`.  Nine sites were affected, all in `ovc41_main.c` except one double
cast in `ovc27_combat.c`; they are reverted to the near form, which is no better in substance (the
expressions are nonsense decompiler output such as `(int)&paStack_20[-1].flags / 3 + Seed_2000_d10e`)
but does not read the IVT.

`tmp/find_bad_agnt_casts.py` now reports **0**, so the check is a standing guard, and
`tmp/where_instack08.py` reports no `in_stack_00000008` left in ovc27_combat.c.

  grep_checks 41,113 -> 41,090; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### The phantom in_stack_ class splits: 40 dead declarations and 97 real uninitialised reads

The earlier count treated the declaration line as a use, so a local that is declared and never
referenced looked identical to one that is read.  Splitting on that (`tmp/split_phantom.py`) changes
the picture:

```
dead declarations (declared, never referenced)   40   -> deleted
real uninitialised reads                        100   -> 97 after three fixes
```

All 40 dead declarations are gone - pure leftovers with no behaviour - and three real ones are fixed
from their use plus the original's own slots:

```
drawTextAt  302d:08ef  mov di,[bp+0xa]; cmp di,0xa000   txt is far at bp+6..9, so bp+0xa = dst
uiNotify    302d:0a41  bp slots 06,08,0a                msg near at 06, dst at 08
say         302d:0a1b  bp slots 06,08                   msg at 06
```

so `in_stack_00000008` -> `dst` in drawTextAt and uiNotify, `in_stack_00000006` -> `msg` in say.
`drawAnimTextAt` is deliberately left: its single use passes the value as drawTextAt's *txt* while the
declared `text` is passed as *dst*, so the two names appear swapped and it needs its own analysis.

### Why this class cannot be scripted with one rule

Tested whether Ghidra's `in_stack_XXXX` is simply `[bp + XXXX + 2]` (it names slots as if the return
address were 2 bytes, while these are far functions with 4).  `tmp/test_shift2.py`:

```
+2 shift lands on a real bp slot : 70 functions
does not                         : 52 functions
```

so no constant rule exists - and the failures are informative.  `vgaSetPalette8bit` reads `[bp+6]`
where the shift predicts `[bp+8]`, `driver_fillSpan` reads `[bp+0x0e]` where it predicts `[bp+0x10]`,
`font_textWidth` reads `[bp+0x0a]` where it predicts `[bp+0x0c]` - i.e. those three are unshifted.
Each function therefore needs its own prologue read, which is what the earlier turns concluded and
this measurement now quantifies.

  grep_checks 41,090 -> 41,047; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### The three ovc01_driver rle functions: a segment-for-offset bug, not just a phantom local

All three prologues read the same way, and each hides two errors:

```
rle_blit_decode 2d63:0241  lds si,[bp+6]  les di,[bp+0xa]  mov dx,[bp+0xe]  add dx,di
rle_line        2d63:032d  lds si,[bp+6]  mov dx,[bp+0xe]  add dx,si
unrle_mirror    2d63:03b6  lds si,[bp+6]  les dx,[bp+0xa]  mov di,[bp+0xe]  add di,dx
```

1. the phantom `in_stack_0000000c` is the **third parameter**, which sits at bp+0xe because the first
   two are far pointers (`lds`/`les`), not at bp+0x0c;
2. where the export wrote `(int)(*(uint16_t *)((uint8_t *)&(dst) + 2))` - **dst's segment** - the
   original adds **dst's offset**.  So the end pointers were computed from a segment value, which is
   not a pointer at all.

Corrected:

```
end  = sz + (int)dst;              rle_blit_decode
end  = npixels + (int)src;         rle_line
pdst = (int)dst + len + -1;        unrle_mirror
```

The rebuilt `rle_blit_decode` now emits `mov di,[bp+8]; mov ax,[bp+10]; add ax,di`, which is the
original's shape (`sz + dst_offset`).

My earlier turn recorded wrong addresses for two of these (`2d63:0292` and `2d63:02cb`), which is why
its disassembly looked like `xlatb` garbage and a byte-pair read.  The source comments give
`2d63:032d` and `2d63:03b6`; using those, both functions decode cleanly.  The lesson is to take the
address from the comment above the function rather than from a remembered offset.

Still wrong in these functions, and out of scope here: `dst` is declared `byte *` (near) while the
original uses `les`/`lds`, and `pd` is assigned dst's segment and then written through as a near
pointer.  Fixing that needs the far-pointer treatment, not an expression edit.

  grep_checks 41,047 -> 41,041; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### ovc27_rollAgainstStat re-derived: it was corrupting its own parameter

`5ded:04cd`, 96 bytes, 37 instructions.  The whole listing:

```
les  bx,[bp+6]              ; agnt far pointer
les  bx,es:[bx+0x17]        ; agnt->entity
al = es:[bx+0x1a]           ; entity + 0x1a = base.entity + 3, the leader index
if (al == 0xff) target = 6
else {
  ax = al << 2
  es = 0x70                 ; the leader-sheet table segment
  les bx, es:[bx]           ; GLeaderSheets[index]
  bx += mode                ; mode is the second parameter at bp+0xa
  target = es:[bx + 0x29]
}
randBelow(0x28); ax = (rand & 0xff) + 1; ah = 0
if (ax > target) al = 0 else al = 1
```

Three defects, all visible in that listing:

1. **`agnt = CONCAT13(uStack0007,CONCAT12(mode,agnt));`** - the export rebuilds the agent pointer out
   of an undefined stack byte and `mode`, i.e. it corrupts the parameter it is supposed to read.
   There is no such code in the original.  This is the most damaging kind of export artefact: not a
   naming problem but a self-inflicted pointer corruption on the first line of the body.
2. `*(uint32_t *)((uint)bVar5 << 2)` read the leader table DS-relative, losing the segment-0x70 base;
   it is `GLeaderSheets[index]`, the same table `ovc15_textError` uses.
3. the return went through a fabricated high byte (`bVar5 << 8`, `CONCAT11`) although every exit
   writes only AL - a plain 0/1.

The stat target is `GLeaderSheets[idx]` byte `+0x29+mode`, with 0xff meaning a target of 6, and the
function returns 1 when `randBelow(0x28)+1 <= target`.  The rebuilt code emits `les bx,[bp+6]` ->
entity -> `[bx+26]` exactly as the original does.

One caveat stated rather than hidden: `agnt->entity` is reached through a near cast
(`((entity_t *)agnt->entity)`), so the entity access is DS-relative rather than `les`.  That is the
same convention as the rest of the tree and happens to be sound because `Entities` lives in DGROUP -
but it is not what the original does, and it would break if Entities ever moved.

  grep_checks 41,039 -> 41,014; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### Resolving the ambiguous phantom parameters by parameter width

The three functions blocked last turn were blocked because the export's declaration could not say
whether a slot held a near or a far pointer.  The original's load form says it directly, and that in
turn fixes which declared parameter sits at the `in_stack_` slot.  `tmp/classify_params.py` reports it
per slot:

```
les/lds [bp+N]            -> far pointer, 4 bytes, occupying N..N+3
mov X, byte ptr [bp+N]    -> a byte
mov X, word ptr [bp+N]    -> a near word
```

**blitGfx10** `317e:02a9`

```
bp+0x0e  les bx, ptr [bp+0xe]      -> dst is a FAR brect_t*, 0xe..0x11
bp+0x10  never read                -> covered by that far pointer
bp+0x12  mov al, byte ptr [bp+0x12]  -> a byte = the `type` parameter
```

so `in_stack_00000010` == `type`.  It is now used in all three places (`CONCAT12(type,dst)` and the
`type == false` test), where before the parameter and the phantom were separate objects.

**gfxRlePrepare** `317e:08ed` - same reading: `bp+0x0e` is loaded with `les` (so `rectOfs` is far,
0xe..0x11), `bp+0x10` is never read, and `bp+0x12`/`bp+0x14` are single bytes.  So
`in_stack_00000012 == scale` and `in_stack_00000014 == flip`.  The resulting code is coherent -
`if (scale == '\0')` and `(byte)flip * frac` treating flip as a fraction - which is what confirms the
mapping rather than just permitting it.

Its `in_stack_00000016`/`_18` are deliberately left: the declared `arg7`/`arg8` are `uint16_t` while
the original reads single bytes at those slots, so declaration and use disagree.

`miceBlitRect` is also left, and for a different reason: it does `les bx,[bp+6]` on a parameter
declared `brect_t *br`, so `br` is far and occupies 6..9, leaving no slot for the phantom - the
declaration and the code cannot both be right, and settling it is a re-derivation rather than a
substitution.

  grep_checks 41,014 -> 41,005; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### Three path helpers: the phantom is the path segment, and it is `arg2`

`chpath`, `path_strip_tail_slash` and `ensure_tail_slash` are short and share one shape:

```c
chdir((char *)CONCAT22(in_stack_00000006,path));
l = strlen((char *)CONCAT22(in_stack_00000006,s));
```

`CONCAT22(hi,lo)` is `hi<<16|lo`, so the phantom is the **high word = the segment** and `path`/`s` is
the offset.  In all three bodies the declared second parameter `arg2` appears nowhere else, and it is
the only `uint16_t` that could carry a segment, so `in_stack_00000006` is `arg2`.

The rebuilt `chpath` confirms it: `mov si,[bp+6]; mov ax,[bp+8]; shl ax,16` - i.e. `MK_FP(arg2, path)`
built from the two parameters, which is what the original does.

The other `ovc09_init` cases in this family are *not* the same and are left alone:
`append_name_to_path` has `CONCAT22((char *)path,in_stack_00000004)`, i.e. the phantom in the **low**
word and `path` in the high one - the roles are swapped relative to these three, so its parameter
naming has to be settled before the phantom is touched.  `init_textFilename` is a 770-line body for a
`(void)` function, i.e. another merged blob, so its `in_stack_` reads are not parameters at all.

Implementation: the three bodies are edited in memory and the file written once, which avoids the
delete-then-reread defect that broke two earlier helpers.

  grep_checks 41,005 -> 40,999; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### driver_fillSpan: the span was being written into DGROUP, not the framebuffer

`2d63:09c9`, 79 bytes, 40 instructions, no calls - so the body was complete and this is a decode, not
a search.  The listing:

```
di = x1; cx = x2
if (di > cx) xchg(di, cx)
lds bx, ptr [bp+0xe]                 ; rect is a FAR pointer parameter
if (di < [bx])   di = [bx]           ; rect[0]
if (cx > [bx+4]) cx = [bx+4]         ; rect[2]
if (cx - di < 0) return
if (y < [bx+2]) return;  if (y > [bx+6]) return
cx++                                 ; count
di += y*0x100; di += y*0x40          ; y*0x140, done as two adds
es = [bx+8]                          ; rect[4] is the DESTINATION SEGMENT
rep stosb es:[di], colour
```

The geometry in the export was right - the clip to `rect[0]`/`rect[2]`, the y test against the rect
bytes at +2/+6, the `y*0x140` offset.  The defect was the destination: the export wrote the span
through a *near* pointer (`*(uint8_t *)(x1 + y*0x140)`), so every byte went into DGROUP instead of the
segment `rect[4]` names.  On a VGA game that is the difference between drawing and corrupting memory.

The rewrite builds `dst = MK_FP(rect[4], lo + y*0x140)` and fills through it; the rebuilt code loads
it with `les bx, dword ptr [bp-6]`, which is the original's access form.

  grep_checks 40,999 -> 40,970; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### append_name_to_path: semantics clear, call form not yet

The body is only 13 lines and its intent is unmistakable - copy the path, strip back to the last
separator, append the name:

```c
strcpy(&GStaticBuffer, path);
for (l = strlen(&GStaticBuffer); (0 < l && ((undefined1 *)&randomFeatureCount)[l] != 0x5c); l--);
((undefined *)&GStaticBuffer)[l] = 0;
strcat(&GStaticBuffer, name);
```

but both calls are written with mangled far-pointer builds:

```c
strcpy(&GStaticBuffer,(char *)CONCAT22((char *)path,in_stack_00000004));
strcat(&GStaticBuffer,(char *)CONCAT22((char *)name,(*(uint16_t *)((uint8_t *)&(path) + 2))));
```

In the first, `path` is the high word (segment) and the phantom the low one; in the second `name` is
the high word and the segment half of `path` the low one.  That is Ghidra splitting a far `char *`
parameter into halves and reassembling them in the wrong order, not code the original contains.

The prologue pushes `[bp+8], [bp+6], 0x280, 0x8bb1` before `lcall 0,0x2d31`, i.e. four words for the
first call, so the exact seg/ofs push order has to be established before the two calls can be
rewritten.  Left unchanged for that reason: the semantic guess (`strcpy(dst, path)`) is very likely
right, and "very likely" is what produced the segment-0 regression earlier in this session.

  grep_checks 40,970; build 65/65 clean; LINK.LOG 65 bytes / 0 problems

### The mis-declared pointer widths, swept as a class: 25 functions and 5 locals

The last four hand-decoded functions all had the same root cause, and it was not the phantom local: a
parameter declared as a **near** pointer that the original loads with `les`/`lds`, i.e. a far pointer
of 4 bytes.  The phantom `in_stack_` local was a symptom - Ghidra needed somewhere to hold the second
half.

`tmp/find_near_params.py` finds them directly.  For each function it computes every parameter's
declared bp offset from this build's widths (near pointer 2, far pointer 4, char/byte 1, short/word 2,
long 4) and checks whether the disassembly performs `les`/`lds` at exactly that offset.  Two filters
keep the change safe:

* bodies containing `in_stack_` or `unaff_` are skipped, because changing a parameter's width shifts
  every later slot and those references are pinned to the old layout (named parameters are recomputed
  by the compiler and are fine);
* only functions with **no callers** are converted in this pass, so no caller has to be recompiled
  against the new signature.

**56 functions** show the mismatch; **25** are uncalled and were converted.  The header prototypes were
updated to match, and the whole tree still compiles 65/65.

One follow-on was needed and is easy to miss: the bodies route the parameter through a near local

```c
char_sheet_t *pcVar2;
pcVar2 = (char_sheet_t *)sheet;      /* truncates straight back */
```

so the declaration change alone emits identical code.  Five such locals were made far and their casts
dropped (`tmp/fix_far_locals.py`).

Verified at the instruction level, `manage_compute2` now emits

```
les  bx, dword ptr [bp-4]
cmp  byte ptr es:[bx+47], 4
```

where the original has `les bx, ptr [bp+6]` / `cmp byte ptr es:[bx+0x2f],4`.  Offset 0x2f and the `les`
form both match.

`grep_checks` does not move - a correct far declaration carries the same identifiers as the wrong near
one - but 25 functions stop truncating their arguments, which is the same defect that produced
`driver_fillSpan`'s DGROUP writes.

  grep_checks 40,962 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### Five more far parameters, and an operational trap with `--asm`

`tmp/analyse_callers.py` lists each remaining near->far candidate next to its call sites, because
the prototype change is only safe where the callers convert cleanly.  That immediately separated six
functions with **no call sites at all** - `rle_blit_decode`, `rle_line`, `unrle_mirror`, `drawLine2`,
`copyGrayscalePalette`, `font_textWidth` - since the game calls them through `ovr_*` thunks, never by
name.  Five were converted (the sixth did not match the pattern); each far width is from the `les`/`lds`
load form.

The effect is layout, not code shape: `rle_blit_decode` now receives `dst` as a far pointer of 4 bytes,
so `sz` lands at bp+0xe exactly as in the original (`mov dx,[bp+0xe]`) instead of bp+0x0c.  The body
still dereferences through near casts, so no `les` appears in the emitted code and the writes are
unchanged - this is a correctness-of-declaration fix, not a behaviour fix, and `grep_checks` does not
move.

`font_textWidth` was checked specifically because its slot was not obvious: the original opens with
`mov ax,[bp+6] / or ax,[bp+8]` (a null test on the 4-byte pointer at 6..9) and `les bx,ptr [bp+6]`, so
`text` occupies 6..9 and `font` really is at bp+0xa.

**Operational trap, worth recording.** After `build_standalone.py --only o01 --asm` the module
directory holds `O01.ASM` but no `o01.obj`, and `link_standalone.py` then fails with 462 undefined
symbols starting `Undefined symbol _MAIN` - which reads like a catastrophic source error but is only
the missing object.  Always run a full `-c` build before linking; `--asm` is a listing tool, not a
build.

  grep_checks 40,962 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### ovc49_usesStExit: the AH byte in the return is deliberate, and two loads were dead

`8699:06dc`, 365 bytes, 141 instructions, **1 call** - verified against the extent before rewriting, so
the body was complete.  The decoded shape:

```
row      = (agnt->y >> 1) clamped 0..7
colStart = (agnt->x - frameWidth) >> 1        frameWidth = *(int *)(frameOfs + 0x17)
colEnd   = (agnt->x + frameWidth) >> 1        both clamped 0..0x68
if (colEnd < colStart) ovr_stExit(0x1e)
variant == 0 -> scan AgntArrayA[row][col] plus the table at +0x963
variant != 0 -> scan AgntArrayB[row][col] plus the tables at +0x549 and +0x5b2
all tables use the 0x69 row stride
return 1 | (rowOfs & 0xff00), or (rowOfs & 0xff00) alone when nothing is found
```

**The high byte is real, not stale AH.** Every success exit in the listing is `mov ax,di` followed by
`mov al,1`, with `di` holding `row * 0x69`, so AX deliberately keeps di's high byte.  That is why the
exported `CONCAT11(...,1)` and `(uint)bVar6 << 8` were kept rather than "corrected" - a reminder that
the stale-AH rule needs checking per function, and here it would have introduced a bug.

Two loads were dead and are removed: `uVar1` (the frames *segment*, read into a local and clamped to
0..7 but never used) and the frame segment load `piVar7[1]`, whose value never reaches a read.

76 -> 72 lines and **grep_checks 40,962 -> 40,885 (-77)**, mostly from the typed locals replacing
`iVar2`..`iVar4`, `iStack_4`/`_6`, `piVar7`, `bVar6` and the dual-role `uVar5`.

`--asm` on o49 remains unusable (compiler table limit in `ovc49_body1`), so the emitted listing could
not be inspected for this function; the evidence here is the decode plus a clean build and unchanged
gates.  The full `-c` build was rerun before linking, per the trap recorded last turn.

  grep_checks 40,962 -> 40,885; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### ovc30_textDivideError renamed by line range; ovc49 listing closed via an isolated probe

`619c:05a5`, 1209 bytes, 441 instructions, **19 calls** - and the C body has exactly 19 real calls once
three type casts (`short`) and the signature line are excluded.

The exported body reuses locals for unrelated roles (`iVar4` is `baseDist`, then `scanIdx`, then
`twiceFactor`; `uVar6` is `dx`, then `mapOk`, then `newLeader`; `uVar8` is `spawnX`, then `roll`), so
the rename is assigned **by line range**:

```
iVar4  <=271 baseDist | <=372 scanIdx | else twiceFactor
uVar6  <=339 dx       | <=349 mapOk   | else newLeader
uVar7  <=339 dy       | else factor
uVar8  <=393 spawnX   | else roll
bVar3  <=342 rejected | else inArena
uVar2 sheet   uVar5 yRoll   uVar9 dxSign   uVar10 dySign   pbVar1 flagsByte
```

A first attempt used an explicit per-line map and failed with 13 errors: continuation lines such as
321 use four temps at once (`uVar6 ^ uVar9) - uVar9) / 2 + ((uVar7 ^ uVar10) - uVar10)`) and were not
in the map.  Range assignment cannot miss a line, and the script now reports
`lines still holding an exported temp: none`.

**Verified against the emitted listing**, which o30 supports:

```
instructions: 572 (original 441)
call instructions: 19 (original 19)
  ovr_randBelow x5          ovr_ovc15_usesLDIV_at_ x3   ovr_constr_usesGMapFlags x2
  ovc30_difficultyFactor x2 ovr_ovc23_placeBuilding x2   five others x1
```

The call distribution matches the original's lcall profile exactly (0x170,0x5c x5; 0x160,0x20 x3;
0x138,0x2a x2; two near calls; 0x1a0,0x52 x2; five singles).  572 against 441 instructions is the
expected cost of C over hand-written assembly, not extra logic.

### ovc49_usesStExit: the missed listing check, now done

Last turn's `ovc49_usesStExit` shipped without the emitted-code check because `--asm` on `o49` hits the
compiler table limit.  Compiling the function alone fixes that: `tmp/make_fn_probe.py` copies it into
`probe.c`, which lists fine - 1 call (`_ovr_stExit`, matching the original's single lcall) and the
fallthrough exit emits `mov al,[bp-9] / mov ah,0 / shl ax,8`, i.e. the `retHi << 8` shape.  The debt is
closed.

  grep_checks 40,885 -> 40,771; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### ovc41_removeAgent: the entity pointer was rebuilt into segment 0

`6a8f:0256`, 460 bytes, 174 instructions, **3 calls** - the body makes exactly three
(`ovr_agnt_usesAgntCount4`, `_fmemmove`, `ovr_attact_usesRandBelow`), so it was complete.

The defect is in the first three lines:

```c
uVar2   = AGNT_WORD(&Agnts[agntIndex], entity, 2);                  /* the segment half  */
agnt    = (agnt_t far *)AGNT_WORD(&Agnts[agntIndex], entity, 0);     /* the OFFSET, cast  */
agntPtr = (agnt_t far *)CONCAT22(uVar2,agnt);                       /* into a near local */
```

An int cast to a far pointer compiles to **segment 0** under Turbo C, and `agntPtr` is declared
`entity_t *` - near - so the base truncated anyway.  Everything the function then does goes through
that pointer: `y` at +2, `x` at +0, `targetX` at +4, `targetY` at +6, `destX` at +8, `destY` at +0xa,
`target` at +0xc, all reached with `les bx,[bp-6]` in the original.  It is simply `Agnts[i].entity`,
held in an `entity_t far *`.

Verified against a listing of the function alone (o41 cannot list as a module):

```
instructions: 187 (original 174)
calls: 3 (original 3)
les  bx, dword ptr [bp-6]
```

One `les` rather than the original's repeated reloads, because our compiler keeps ES live across the
field reads; the pointer is far in both.

  grep_checks 40,771 -> 40,736; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### Scanning the two-half far-pointer pattern: one instance left, and a different class behind it

`tmp/find_half_ptr.py` looks for the three shapes that produced the last several defects.  Restricting
to the exact one from `ovc41_removeAgent` - a `AGNT_WORD`/`GREC_WORD` half cast straight to a pointer
type - finds **exactly one** remaining site, in `agnt_usesAgntCount6`:

```c
if ((AGNT_WORD(&Agnts[i], entity, 2) == in_stack_00000006) &&
   ((entity_t *)AGNT_WORD(&Agnts[i], entity, 0) == ptr)) {
```

The disassembly settles it: `cmp ax,[bp+8]` on the entity's segment and `cmp dx,[bp+6]` on its offset,
i.e. the second parameter is the pointer's segment half and the local `in_stack_00000006` was a phantom
standing in for it.  Replaced with `arg2` and the declaration dropped; the offset-versus-`ptr`
comparison on the next line is consistent (both are 16-bit offsets there), so it is left.

So that shape is closed.  What the same scan surfaced instead is a *different* class, 21 sites, of the
form

```c
CONCAT22(0xad0,   (uint8_t *)uStackY_24)      ovc18_showLeaderView
CONCAT22(0x277c,  (entity_t *)uStack_1e)      saveui_configureMessageDelay
CONCAT22(0x638d,  (char *)text)               stats_readyStatusText
CONCAT22(0x222b,  (uint)bStack_4 * 0x21)      ovc27_usesRandBelow5
```

a far pointer built from a **hardcoded segment** plus a near offset.  Those segments are the original
image's, like the `0x1726` that had to be replaced with `SEG_OF(Agnts)` earlier, so each needs the
owning symbol identified before it can be corrected - the same per-site reasoning as the near->far
parameters, not a sweep.  It is recorded here as the next class rather than started.

  grep_checks 40,736 -> 40,734; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### The hardcoded-segment class, first site: `0x222b` was not a segment at all

Taking `ovc27_usesRandBelow5`'s `CONCAT22(0x222b,(uint)bStack_4 * 0x21)` and reading both ends of the
call settled it:

* the caller (`5ded:0960`) pushes the high word as a **literal `0x90`**:
  `mov dx,0x21 / imul dx / add ax,0 / push 0x90 / push ax / push [bp+8] / push [bp+6] / push cs / call`
  - i.e. `f(agnt_far, 0x0090:row*0x21, target)`;
* the callee (`5ded:052d`, `ovc27_usesRandBelow3`) dereferences that argument **21 times** with
  `les bx, ptr [bp+0xa]`, so the parameter is a far pointer, not the `uint32_t` the tree declares;
* `0x222b` is not a segment anywhere in the image - not DGROUP (`0x2410`), not Agnts (`0x1726`), not
  AgntGs (`0x195d`), and not in `audit/overlay_blocks.csv` - so the export's literal is fabricated.

So the literal is corrected to `0x90`, matching the binary.  `0x90` is a load-time data segment in the
same family as the `0x60` used for `BuildingTypes` and `0x70` for `GLeaderSheets`; what *lives* there
(a 0x21-byte record table) is still unidentified, so this is a literal correction, not yet a symbol.

Verified by listing the function alone: 95 instructions against 66, and the same three calls
(`_fmemset`, `_ovc27_usesRandBelow3`, `_ovr_randBelow`).

**Left undone, and why:** `ovc27_usesRandBelow3`'s second parameter should become a far pointer type,
since its body is `les` throughout.  That changes a prototype with callers in both `usesRandBelow5`
and `spellNotice`, and `spellNotice`'s own call could not be located in its disassembly - the export
claims `ovc27_usesRandBelow3(...,0x222b0108,...)` but no `call` to `5ded:052d` appears in that
function's listing.  Until that is explained, changing the prototype would be acting on text that may
itself be wrong.

  grep_checks 40,734 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### spellNotice is not mis-attributed, and every `0x222b` was really `0x90`

The question was whether `ovc27_spellNotice` (`5ded:0a05`, 701 bytes) is a merged body, because the
export appeared to call `ovc27_usesRandBelow3` with `0x222b0108` while no call to `5ded:052d` exists in
its listing.  Its full call list settles it:

```
lcall 0x108,0x20   lcall 0x140,0x2f x2   lcall 0x140,0x48 x2   lcall 0x148,0x34
lcall 0x148,0x43   lcall 0x160,0x25      lcall 0x170,0x5c x2   lcall 0x170,0x7a
lcall 0xf8,0x39    near 5ded:0960
```

Thirteen calls, and the near one goes to `5ded:0960` = `ovc27_usesRandBelow5`, which is exactly what
the body calls.  So `spellNotice` is **not** mis-attributed - the `0x222b0108` call is in
`ovc27_compute2`, and I had attributed it to the wrong function two turns ago.

That misattribution is what the wider check then corrected.  Every remaining `0x222b` in the tree was
in fact `0x90`:

```
ovc27_compute2     5ded:07d0   push 0x90 / push 0x108   -> CONCAT22(0x90,0x108)
                               push 0x90 / push 0x14a   -> CONCAT22(0x90,0x14a)
ovc27_usesAgntCount 5ded:1beb  push 0x90 / push ax
ovc27_spellNotice  5ded:0a05   mov dx,0x90  (five times)
```

All four sites corrected, and `0x222b` no longer appears in the tree.  Verified by listing
`spellNotice` alone: 353 instructions against 238, with the same **13 calls**.

So the "hardcoded segment" framing was wrong twice over: `0x222b` was never a segment, and it was not a
per-site puzzle either - Ghidra had substituted one bogus constant consistently, and one disassembly
read resolved all four occurrences.

`ovc27_usesRandBelow3`'s second parameter is still declared `uint32_t` although its body is `les`
throughout; changing it now would touch `usesRandBelow5`, `usesAgntCount` and `compute2`, and
`compute2`'s body uses that same parameter as `mode`, so the split-parameter question there has to be
settled first.

  grep_checks 40,734 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### Ranking by section-5 matches, not by `mass`: the `char [N] = ""` class is data

`grep_checks` counts matches, so the useful queue is "which function holds the most matches", not
"which has the largest per-line ratio".  `tmp/rank_by_grep.py` reports:

```
clean functions (no in_stack_/unaff_/LAB_): 358, total matches 6929
dirty functions:                            169, total matches 21988
```

and the top clean entries are functions the previous queue had buried:

```
237  329  ovc16_saveui.c    uiMainMenuLoop
200  324  ovc47_constrct.c  land_info
143  163  ovc41_main.c      ovc41_turnUndeadNotice
129  343  ovc39_archive.c   ovc39_textHalflingCastle
129  163  ovc27_combat.c    ovc27_textTakesHalfDamage3
```

The 1,405 matches for `char [N] = ""` are **not** a decompilation defect and are not worth chasing:
1,294 are in `st_globals5.c`, 110 in `st_globals4.c`, 1 in `crtl.c` - i.e. **zero in any game code
module**.  Of the 1,294, `tmp/check_str_use.py` finds **1,249 are referenced by nothing at all**: they
exist only because the original's DGROUP holds those bytes, and `compare_state` checks them there.
Rewriting them as byte lists would preserve the data and move the gate by 1,294 while making the data
less readable, so it is left alone.  The class's *code* portion is already zero.

### ovc41_turnUndeadNotice re-derived (40,734 -> 40,591, -143)

`6a8f:0b39`, 1160 bytes, 432 instructions, 163 lines and the largest section-5 match count of any
function that has no `in_stack_`/`unaff_`/`LAB_` blocker.

The listing shows the field chain as three far loads:

```
0051  les bx, ptr [bp-8]          ; Agnts[idx]
0054  les bx, ptr es:[bx + 0x1d]  ; agnt->gdata
0058  mov al, byte ptr es:[bx+0x42]   ; gdata->rank
007D  les bx, ptr es:[bx + 0x17]  ; agnt->entity
0081  mov al, byte ptr es:[bx+0x0f]   ; entity->base.level
```

so `Agnts[i].gdata->rank`, `..entity->base.level` and `..entity->base.animFrame` are exact.  The
export instead did `agntPtr2 = *(uint32_t far *)&Agnts[i].gdata` and then
`*(byte *)((int)agntPtr2 + 0x42)`, which drops the segment before dereferencing - and `AgntGs` lives
in its own segment, so every one of those reads was addressing the wrong memory.

The returns: every exit writes only AL (`mov al,0` at 0x14/0x33/0x68, `mov al,1` at 0xF1/0x482).  The
exported `CONCAT11(savedSeg,1)` and `(uint)bVar7 << 8` build fabricated high bytes from `savedSeg` and
an unassigned `in_AX`; the single caller reads `(char)uVar5`, so they are stale AH and become plain
`return 0` / `return 1`.

Dead and removed: `in_AX` (never assigned - the fourth instance of that class), `extraout_AH`,
`targetOfs` (assigned, never read), `uStack_8` (same), `savedSeg` (fed only the fabricated returns).

Verified by listing the function alone, since o41 cannot list as a module:

```
instructions: 620   (original 432)
call instructions: 27   (original 27)
  agnt_statusText x4   ovc15_usesStshRealloc x4   stsprintf x4   uiNotify x4
  agnt_usesAnimFrame x3   + eight singles
les sites: 23
final return: mov ax,1
```

That call distribution is the original's exactly (lcall 0x148,0x2f x4 / 0x160,0x25 x4 / 0x170,0x7a x4
/ 0xf8,0x39 x4 / 0x148,0x34 x3 / four singles, plus five near calls).  620 against 432 is the usual
cost of C over hand-written assembly.

Deliberately kept byte-for-byte: the argument lists of `agnt_statusText`, `ovc15_usesStshRealloc`,
`stsprintf`, `uiNotify` and `play_sfxU`.  The frame is `sub sp,0xa8` and one argument is
`SS:[bp-0xa8]`, and the push sequences interleave buffer setup I have not established, so those
arguments are not reinterpreted - only the locals inside them are renamed.  `notifyValue` in
particular keeps the export's `SEG_OF(Agnts)` assignment, which is very likely wrong but which I
cannot replace without decoding that region.

  grep_checks 40,734 -> 40,591; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### stats_unreadyNotice re-derived (40,591 -> 40,526, -65)

`6386:13a1`, 465 bytes, 183 instructions, and the same defect shape as the previous entry - two
chained far dereferences truncated through `uint32_t` locals:

```
0018  les bx, ptr es:[bx + 0x17]     ; Agnts[id].entity
001D  mov al, byte ptr es:[bx+0x33]  ; the flag byte
0021  xor al, 1
003D  mov byte ptr es:[bx+0x33], al  ; written back through another les chain
0074  mov al, byte ptr es:[bx+0x1a]  ; entity->base.entity byte 3 (= 0x17 + 3)
```

`entity+0x33` is the last byte of the 0x34-byte `agnt_t` inside `entity_t`, i.e. the high byte of
`base.flags32` (struct tail: flags 0x2b, visited 0x2d, variant 0x2e, faction 0x2f, state 0x30,
flags32 0x32; `entity_t.tick` is at 0x34 per its comment and per symbols.tsv).  It may really be a
one-byte field the struct folds into `flags32` - either way the code touches that one byte, so it is
expressed as `(uint8_t far *)&...flags32 + 1`.

`gdata->name` is at 0x24 (agntG_t: sprs[6] 0x03..0x1a, extents[3][3] 0x1b..0x23), so the export's
`*(uint16_t *)(iVar7 + 0x24)` and `+ 0x26` are the offset and segment halves of `gdata->name`.

**One real arity defect found and fixed.**  The export called

```c
drawAgntStats((agnt_t far *)&Agnts[agnt_id].x, far_from_u32((uint32_t)(SEG_OF(Agnts))), 0);
```

`SEG_OF(Agnts)` is `0x50`, so `far_from_u32` produced `{ofs:0x50, seg:0}` - segment 0.  The original
pushes two literal zeros:

```
011F  push 0          ; cmap.ofs
0121  push 0          ; cmap.seg
0130  push 0x50       ; agnt segment
0133  push ax         ; agnt offset
0134  push cs         ; far call within the segment
0135  call near
```

so the argument is an all-zero `far_t`, now built explicitly in a local.  That also removed the
`far_from_u32` call the export inserted and took the function from 10 emitted calls to **9, matching
the original**.

Dead and removed: `uVar8` (a junk round-trip of the uninitialised `text` - saved at 1667, restored at
1679, re-assigned and never read at 1698), and two `CONCAT22(text,agntSeg)` stores whose value no
following statement reads.

Verified by listing the function alone:

```
instructions: 184   (original 183)
call instructions: 9   (original 9)
```

**Recorded, not fixed:** the original pushes 4 argument words for this call, but the declared
prototype `drawAgntStats(agnt_t far *, far_t, uint16_t)` needs 5 (2 + 2 + 1).  So `arg3` appears to be
spurious - the callee only ever receives a far agent and a `far_t`.  Settling it means reading
`drawAgntStats` itself at `ovc33_stats.c:1129` and its three other call sites, so it is left as the
next lead rather than changed here.  Our extra word is harmless for this call (cdecl, agent and cmap
still land at the right offsets) but the prototype should not stay wrong.

  grep_checks 40,591 -> 40,526; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### `far_t` was written in Ghidra's member order, not ours: 7 swaps fixed

`uiMainMenuLoop` (the top entry of the new ranking) turned out to need more than one pass, but
reading it exposed a class that is cheap to prove and was silently wrong.

Our `struct far_t` is `{ofs, seg}`.  The export writes it as `{seg, ofs}`:

```c
items.seg = pmenu;        /* pmenu = (uint16_t)&menu, an offset */
items.ofs = 0x2410;       /* the original image's DGROUP segment */
```

Two independent proofs:

* `ovc16_saveui.c:105-106` writes `0xa000` into `src.ofs`, while line 110 writes the **same constant**
  into `dst.seg`.  `0xa000` can only be a segment (the VGA framebuffer), so the pair at 105 is
  reversed.
* `ovc16_saveui.c:1712-1713` writes `dst_01.seg = _SS; dst_01.ofs = (uint16_t)&hostilityItems;` in the
  **right** order for the same stack buffer that 1719-1720 mangle into
  `items.seg = (uint16_t)puVar1; items.ofs = 0x2410;`.

The correct segment per site is decided by where the table lives, and `uiMenu`'s third argument says
it: `_SS` for a stack array, the heap block's segment for the saves list.  So each site is provable
from the call itself, not guessed.

**`0x2410` is never a pushed constant.**  Searching `uiMainMenuLoop`'s whole 1573 bytes for it finds
nothing; the original pushes `ds` (`0x002A push ds / push 0x2851 / lcall 0xf8,0x3e` is the
`ovr_say` call).  So `0x2410` is a Ghidra rendering of the DGROUP segment, and every use of it as a
segment is wrong in this build, whose DGROUP is elsewhere.  That is a separate class from the swap.

`tmp/classify_fart_swap.py` finds **32** `x.seg = <expr>; x.ofs = <const>` pairs: 10 provably swapped
(a known segment constant in `.ofs`), 0 in the correct order with a constant, and 22 that need
per-site reading.  **7 are fixed here** - the ones that need no other change:

```
ovc16_saveui.c 105   src.seg = 0xa000;          src.ofs = CrossBlitX;
ovc28_ui.c     534   src.seg = 0xa000;          src.ofs = CrossBlitX;
ovc16_saveui.c 1437  items.seg = _SS;           items.ofs = pmenu;
ovc16_saveui.c 1454  items_00.seg = _SS;        items_00.ofs = (uint16_t)pcVar9;
ovc16_saveui.c 1588  items_03.seg = _SS;        items_03.ofs = (uint16_t)pcVar9;
ovc16_saveui.c 1719  items.seg = _SS;           items.ofs = (uint16_t)puVar1;
ovc16_saveui.c 1740  items_00.seg = _SS;        items_00.ofs = (uint16_t)puVar1;
```

Verified in the emitted code - the first `uiMenu` call now reads

```
lea  ax, word ptr [bp-114]      ; &menu
mov  word ptr [bp-6], ss        ; items.seg = _SS
mov  word ptr [bp-8], ax        ; items.ofs = pmenu
push 8 / push ss / push [bp-6] / push ax / push offset DGROUP:s@+18
call far ptr _uiMenu
```

where before it pushed `0x2410` as the offset and `&menu` as the segment.

### Why `uiMainMenuLoop` itself is not a single-pass job

Four distinct blockers, each needing its own evidence:

1. **`in_DX` is a fifth phantom.**  `entries_05 = ovr_stshAlloc(400)` returns `void far *`, so DX
   carries the segment; Ghidra rendered it as `in_DX`, which in C is an unassigned variable.  Its 5
   uses are all garbage.  The fix is to declare `entries_05` as `void far *` and use
   `SEG_OF(entries_05)`.
2. **`entries_05` is declared `void *` (near)** and then indexed as `(int)entries_05 + i * 4`, so about
   30 expressions dereference DS-relative instead of through the heap block's segment.  Widening it is
   a prerequisite for blocker 1 and for the three remaining `items_0N` swaps (they need
   `SEG_OF(entries_05)`).
3. **35 uses of `0x2410`** as the DGROUP segment, all of which must become `_DS` - and each has to be
   classified, because some `0x2410` occurrences in the tree are data values, not segments
   (`miceInitDriver` stores it, `miceButton0PressStates` passes it as an argument).
4. **About 20 exported temporaries** and a switch on a hardcoded string-table offset (`0x25bd6`).

That is a turn of its own.  Recording it here so the next pass starts from the diagnosis instead of
re-discovering it.

  grep_checks 40,526 (unchanged - none of this is a section-5 pattern); build 65/65 clean
  LINK.LOG 65 bytes / 0 problems; compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### uiMainMenuLoop, part 1: the saves table is a far object again

`4528:14b1`, 1573 bytes, 584 instructions, 69 calls.  The function reads and writes a 400-byte table
of 100 far pointers (`{ofs, seg}` pairs) returned by `ovr_stshAlloc`.  Four coupled defects, all
evidenced from the listing:

1. **`entries_05` was `void *`** while `ovr_stshAlloc` is declared `void far *`, so the segment was
   dropped at the assignment.
2. **`in_DX` was a never-assigned local** - 15 uses, all uninitialised.  The original keeps the
   segment in DX across the call and stores it immediately:

   ```
   005A lcall 0x170,0x43     ; stshAlloc(400)
   0062 mov word ptr [bp-4], dx     ; segment
   0065 mov word ptr [bp-6], ax     ; offset
   ```

   so it is the return's segment, not a register the export could observe separately.
3. **About 30 dereferences went through `(int)entries_05 + i*4`** - the offset only - so every read and
   write of the table addressed DS instead of the heap block.
4. **Three `items_0N` far_t locals** still carried the seg/ofs swap.

The fix keeps every offset expression exactly as exported and routes access through the segment:
`savesSeg` is set once from `SEG_OF(entries_05)`, the four pointer temporaries become far pointers
into a `far_t far *saves` view, and the field accesses become `saves[i].ofs` / `saves[i].seg`.  The
export's `(uint)bVar5 * 4 + -4` / `-2` offsets on a 1-based menu index are entry `bVar5 - 1`'s offset
and segment, which is what the new form says.

**Measured:** `grep_checks` 40,526 -> 40,510 (-16, exactly the 16 `in_DX` matches); build 65/65;
LINK.LOG 65 bytes / 0 problems; compare_state 1,627/0/0; diff_dgroup 1,444/1,868; compare_runtime
1,545/12.

**Emitted-code check** (function alone, since the module cannot list as a whole): 859 instructions
against the original's 584, 13 `les`/`lds` against 7, and **72 call instructions against 69**.  The
three extra are `_far_from_u32` - one for each of the three remaining

```c
F_SCOPY(far_from_u32((uint32_t)(0x241026b7)),dst);
```

lines.  `far_from_u32` is a reconstruction helper (a `far_t` cannot be built from a `uint32_t` without
one), not a call the original makes, and this change introduced no calls of its own.  More `les` than
the original is expected: the original holds ES across accesses while our compiler reloads the far
pointer after each call.

### What is left in uiMainMenuLoop

8 uses of `0x2410` remain, and they need more than a `_DS` substitution: `0x26b7`, `0x26d7`, `0x26e3`,
`0x26f7`, `0x270b`, `0x27f4`, `0x283f` are **offsets into the original's DGROUP layout**, and our
layout differs (diff_dgroup still reports 83 constant-delta runs), so `MK_FP(_DS, 0x26b7)` would point
at different bytes.  Each needs the owning symbol resolved from `audit/dgroup_data.csv` before it can
be written.  The `ovr_say(...,0x2410)` and `uiReadString(...,0x2410,...)` arguments do become `_DS`
directly, since those point at our own literals.

Also recorded: `_fsetmem` is declared `void __cdecl16far _fsetmem(void *dest, ...)` - a **near**
destination - while all 17 call sites pass far pointers (either a far global or `CONCAT22(seg,ofs)`
cast).  The original's call at `0x0068..0x0073` pushes four words (0, 400, seg, ofs), i.e. a far
fill with the `(dest, len, val)` order.  So the first parameter must become `void far *` and the eight
`(void *)CONCAT22(...)` sites must become `(void far *)`.  Left alone here because it is a 17-site
class of its own and changing the prototype without all of them would be worse than leaving it.

### MEASURED: `CONCAT22(seg, ofs)` cannot build a far pointer - it yields segment 0

`st_compat.h` defines

```c
#define CONCAT22(a,b) ((uint32_t)(((uint16_t)(a) << 16) | (uint16_t)(b)))
```

The `<< 16` is applied to a **16-bit `uint16_t`**, promoted to a 16-bit `int`, so the shift is a no-op
and the result is just `b`.  The high word is discarded.  A one-construct probe shows it:

```c
void far *p_concat(void) { return (void far *)CONCAT22(0x1234, 0x5678); }
void far *p_mkfp(void)   { return MK_FP(0x1234, 0x5678); }
```

```
p_concat:   xor dx,dx / mov ax,22136     -> DX:AX = 0x0000:0x5678    SEGMENT LOST
p_mkfp:     mov dx,4660 / mov ax,22136   -> DX:AX = 0x1234:0x5678    correct
```

`MK_FP` escapes the problem because it casts *before* shifting: `((uint32_t)(seg) << 16) | (uint16_t)(ofs)`.

**Consequence:** every `(T far *)CONCAT22(seg, ofs)` in the tree is a far pointer into **segment 0** -
the interrupt vector table.  `tmp/find_concat_far.py` counts **47** such casts (against 1,051 casts to
*near* pointers, which truncate to the offset deliberately and are a different question).  They cluster
in the functions already known to be dirty:

```
ovc41_main.c 9   ovc12_agnt.c 7   ovc18_leaderview.c 7   ovc22_classes.c 7
ovc27_combat.c 6  ovc15_sprite.c 5   ovc33_stats.c 3   ovc03_font.c 2   ovc06_blit.c 1
```

This also **retracts a fix attempted in this same turn**: changing `_fsetmem`'s destination to
`void far *` and its call-site casts to `(void far *)CONCAT22(seg,ofs)` compiled clean and looked
right, but the emitted code was

```
push 0
push 400
shl  ax,16              ; a no-op on a 16-bit register
or   ax,word ptr [bp-88]
push 0                  ; <-- segment 0
push ax
call far ptr __fsetmem
```

which is *worse* than the near declaration it replaced (that at least stayed in DS).  It was reverted.
The lesson is the one this session keeps re-teaching: for pointer width and provenance, the build and
the gates say nothing - only the emitted instructions do.  The `_fsetmem` class (a far destination with
the `(dest, len, val)` order, 17 call sites) still needs doing, but each site must become
`MK_FP(seg, ofs)` and not `CONCAT22`.

Two sub-classes need different treatment when that is done:

* the clean ones, where both arguments are plain words - `(byte far *)CONCAT22(Font03.seg,Font03.ofs)`,
  `(agnt_t far *)CONCAT22(_SS,&agntCopy)` - convert directly to `MK_FP(a,b)`;
* the already-garbled ones, where an argument is itself a pointer cast -
  `(agnt_t far *)CONCAT22((agnt_t far *)b,a)` - cannot, because `MK_FP` would shift the whole 32-bit
  pointer left by 16.  Those are upstream type errors and need the real field, not a macro swap.

  grep_checks 40,510 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### The first 9 of the 47 segment-0 far pointers, converted to MK_FP

`tmp/fix_concat_far.py` parses each `(T far *)CONCAT22(...)` with balanced-paren argument splitting and
classifies it.  Of the 47, only a subset can be converted safely, because "the two arguments are plain
words" is not the same as "the first argument is a segment": `CONCAT22(cmap.ofs,agnt)` and
`CONCAT22(pcVar21,pfVar20)` are syntactically clean and semantically wrong (a `.ofs` member and a
pointer used as segments).

The nine converted were each read in context and the segment argument is unambiguous:

```
ovc03_font.c   532  CONCAT22(dst,txt)                      dst is the destination SEGMENT - it is also
                                                            passed to ovr_blitRaw(...,0xa000,dst)
ovc03_font.c   533  CONCAT22(Font03.seg,Font03.ofs)
ovc15_sprite.c 1376 CONCAT22(_SS,&agntCopy)
ovc15_sprite.c 1447 CONCAT22(_SS,&agntCopy)
ovc27_combat.c  619 CONCAT22(agntSeg,paStack_6)             agntSeg = SEG_OF(Agnts)
ovc27_combat.c  781 CONCAT22(SEG_OF(Agnts),agnt)
ovc41_main.c    480 CONCAT22(SEG_OF(Agnts),agntBase)
ovc41_main.c    492 CONCAT22(SEG_OF(Agnts),agntBase)
ovc41_main.c   2680 CONCAT22(SEG_OF(Agnts),targetAgnt)
```

Verified in the emitted code rather than by the gates, since this changes no identifier.  `drawTextAt`'s
`blitText` call now pushes

```
push 237 / push 207                       ; the two colour arguments
push word ptr DGROUP:_Font03+2            ; Font03.seg
push word ptr DGROUP:_Font03              ; Font03.ofs
push di                                   ; dst  <- the segment
push si                                   ; txt  <- the offset
call far ptr _blitText
```

where before the first far argument was `push 0; push txt`, i.e. segment 0.

**36 remain.**  They fall into two groups, both needing type work rather than a macro swap:

* an argument is itself a pointer cast - `(agnt_t far *)CONCAT22((uint8_t *)result,agnt)`,
  `(far_t far *)CONCAT22(pcVar21,pfVar20)`, `(agnt_t far *)CONCAT22(cmap.ofs,agnt)`.  `MK_FP` would
  shift the whole 32-bit pointer left by 16, so the real field has to be recovered first.
* the function still contains `in_stack_`/`unaff_` phantoms, so the argument is an uninitialised local
  and converting the macro would only change one wrong value into another.

  grep_checks 40,510 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### The uiMainMenuLoop 0x2410 offsets resolve to real symbols

`tmp/resolve_dgroup_offsets.py` looks each literal up in `audit/symbols.tsv` (the original's own
DGROUP labels) and `audit/dgroup_data.csv` (its bytes):

```
offset     symbol at/below              next symbol              data
0x26b7     GMenuStrings +0              GYesNo -32               char *GMenuStrings[8]
0x26d7     GYesNo +0                   GSeed -8                 char *GYesNo[2]
0x26e3     SeedHi +2                   worldMenuLabels -20      (inside a 4-byte seed)
0x26f7     worldMenuLabels +0          s__Empty__2410_272b -52  far_t worldMenuLabels[13]
0x270b     worldMenuLabels +20         s__Empty__2410_272b -32
0x27f4     s_Save_Game_2410_27f4 +0    s_Load_Game_2410_27fe -10
0x283f     s_Begin_Play_2410_283f +0  s_Yes_2410_284a -11
```

So they are all namable.  But **naming them is not enough on its own**, because `F_SCOPY`'s prototype
is wrong (below), and because `uiMainMenuLoop` uses `pmenu = (uint16_t)&menu; pmenuIdx = (byte)pmenu;`
- the *address* of the buffer rather than its contents - which cannot be right whatever the source
literal is.  Both have to be settled before the literals can be replaced.

### `F_SCOPY` is declared without its length parameter

The tree declares

```c
void __cdecl16far F_SCOPY(far_t src,far_t dst);
```

i.e. two `far_t` and nothing else, so a call copies 4 bytes.  The original passes a **length in CX**:

```
lea  ax,[bp-0xa]
push ss / push ax           ; dst  = SS:<buffer>
push ds / push 0x59aa       ; src  = DS:0x59aa
mov  cx, 0xa                ; length in CX, not on the stack
lcall 0, 0x94f
```

That is `memcpy(dst, src, cx)` with the count in a register - a non-standard convention the export
dropped.  Until it is corrected, every `F_SCOPY` call in the tree copies the wrong number of bytes, and
the `uiMainMenuLoop` menu-table copies (`GMenuStrings`, 8 pointers = 16 bytes) are copying 4.  This is
a distinct class from the pointer-width work and is not attempted here.

  grep_checks 40,507; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### MEASURED: `F_SCOPY` - 55 sites, no `_CX` support, and the compiler inlines struct copies

Three measurements, all cheap and all needed before touching the class.

**1. Scale.** 55 call sites in `src/decompiled`, every one with exactly two arguments, concentrated in
`ovc21_manage.c` (12), `ovc16_saveui.c` (6), `ovc27_combat.c` (6), `ovc37_season.c` (5), `ovc09_init.c` (4).
`crtl.c:1292` is the definition.

**2. The body already reads the count from CX.**  `crtl.c` implements it as

```c
puVar4 = (uint16_t *)src.ofs;
puVar5 = (uint16_t *)dst.ofs;
for (uVar3 = in_CX >> 1; uVar3 != 0; uVar3 = uVar3 - 1) { ... }
```

so the implementation is correct and only the *prototype* is missing the argument.  That is why the
original sets CX at each call (`lea ax,[bp-0xa] / push ss / push ax / push ds / push 0x59aa /
mov cx,0xa / lcall 0,0x94f`).

**3. Turbo C 3.0 cannot express a register parameter.**

```c
void t_reg(far_t dst, uint16_t _CX n);      /* Error probe.c 5: ) expected */
```

so the count has to go on the stack, which deviates from the original's convention.

**4. But that deviation is safe, because this compiler never calls the helper.**  A plain struct
assignment is inlined:

```c
far_t a, b;                  void t_struct_assign(void) { a = b; }
struct big_t { char x[20]; } big1, big2;    void t_big_assign(void) { big1 = big2; }
```

```
t_struct_assign:  mov ax,[_b+2] / mov dx,[_b] / mov [_a+2],ax / mov [_a],dx
t_big_assign:     mov si,offset _big2 / mov di,offset _big1 / push ds / pop es
                  mov cx,10 / rep movsw
```

No helper call in either case, so nothing in our build depends on `F_SCOPY` reading CX.  Giving it a
stack parameter therefore breaks no compiler-generated call - which was the hazard worth checking
before changing it.

**What remains before the fix can be written:** the length at each of the 54 sites.  They are not
uniform - `uiMainMenuLoop` copies `GMenuStrings` (which occupies 0x26d7-0x26b7 = 32 bytes in the
original) and `GYesNo` (4 bytes), while the destinations are a `uint32_t menu` (4 bytes) and
`char yesno[9]`.  So some destinations are under-declared as well, and the length cannot be inferred
from the source declaration.  Reading the `mov cx,N` before each `lcall 0,0x94f` is the way to get them,
one site at a time.

  grep_checks 40,507; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### uiMainMenuLoop's `pmenuIdx` is uiMenu's return - but uiMenu is mis-recovered, so the fix must wait

The instructions after the menu call settle what feeds `pmenuIdx`:

```
00D2  push 8                          ; arg4
00D4  push ss                         ; arg3 = _SS
00D5  lea  ax,[bp-0x32]               ; &menu (the 32-byte table)
00D8  push ax                        ; arg2
00D9  push ds / push 0x2863           ; arg1, a FAR pointer
00DD  push cs
00DE  call uiMenu
00E1  add  sp,0xa                     ; 10 bytes = 2 + 2 + 2 + 4
00E4  mov  byte ptr [bp-0x11], al     ; pmenuIdx = the RETURN value
00F3  mov  al,[bp-0x11] / mov bx,ax / cmp bx,8 / jbe ...
```

So `pmenuIdx` is `(byte)uiMenu(...)` - the AL return - and `&menu` is only ever the items pointer.
The tree has `pmenuIdx = (byte)pmenu` with `pmenu = (uint16_t)&menu`, i.e. it reads the *address* of
the buffer, and it discards the call's return because `uiMenu` is declared `void`.

Two further facts from the same listing:

* **the declared signature has the argument widths the wrong way round.**  `add sp,0xa` accounts for
  arg4 (2) + arg3 (2) + arg2 (2) + arg1 (4), i.e. **arg1 is far and arg2 is near**; the declaration is
  `uiMenu(char *title, far_t items, int nitems, uint16_t arg4)` - near title, far items - which is the
  reverse.  That is why the export had to split a far_t into `items.seg/_ofs` around a near pointer.
* **`uiMenu` itself is mis-recovered.**  Its whole body is a thin wrapper:

  ```c
  void __cdecl16far uiMenu(char *title,far_t items,int nitems,uint16_t arg4)
  {
    uint16_t unaff_BP;
    uint16_t in_stack_0000000c;
    far_t items_00;
    items_00.seg = in_stack_0000000c;
    items_00.ofs = nitems;
    uiMenuSub((char *)MK_FP(items.seg, items.ofs),items_00,1,unaff_BP);
    return;
  }
  ```

  The stack slots confirm the conflation: with `title` at bp+6, `items` at bp+8..0xb, and `nitems` at
  bp+0xc, `in_stack_0000000c` *is* bp+0xc - the same slot as `nitems`.  So the export names one
  parameter twice and uses it as both the segment and the offset of `items_00`, which cannot be what
  the instruction stream does.

Fixing `pmenuIdx` therefore means changing `uiMenu`'s return type **and** recovering `uiMenu`'s own
body and signature first - three coupled changes, not one line.  Doing the `pmenuIdx` edit alone would
mean reading a return value from a function whose body we know is wrong.

The other item named in this step, `notifyValue = SEG_OF(Agnts)` inside the loop, has no corresponding
instruction at all: the loop tail is `mov al,byte ptr es:[0x8ffe]` (AgntCount) then the counter compare.
So that assignment is an artefact - but it feeds two variadic call arguments whose push sequences are
already recorded as unresolved, so it cannot be replaced independently either.

  grep_checks 40,500 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### uiMenuSub's heading pair verified after the item-table fix

Emitted code for the heading far pointer, from `tmp/make_fn_probe.py`:

```
cmp  word ptr [bp+14],8        ; nitems (bp+0xe) against 8
jle  ...
mov  word ptr [bp-46],ds       ; titleSeg = _DS
mov  word ptr [bp-44],offset DGROUP:_s_more    ; titleOfs = &s_more
```

The original at the same place is

```
00A8  cmp si, 8
00AD  mov word ptr [bp-8], ds
00B0  mov word ptr [bp-0xa], 0x2733
```

so both halves are right: the segment is the runtime DGROUP (not the original image's `0x2410`) and the
offset is `s_more`'s address under *our* layout rather than the original's literal `0x2733`.  The
`mov [bp-8],ds` is also the proof that `0x2410` was a segment literal in the export and not data.

Also visible in the same window: `cmp word ptr [bp+14],8`, confirming that the count is `nitems` at
bp+0xe - the read this turn's parent commit corrected.

  grep_checks 40,389 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### land_info's tile table: base and stride proven, but the table has no symbol

Call count verified first: `7e7c:004b` is 2805 bytes, 1022 instructions and **52 calls**, matching
`audit/functions_real.tsv`, so the body is complete.

The tile read decodes exactly:

```
00C3  mov al, byte ptr [bp + 6]     ; tileOffset
00C6  cwde / shl ax, 1              ; tileOffset * 2
00C9  mov dx, 0x280 / mov bx, ax / mov es, dx
00D0  cmp word ptr es:[bx - 0x6e29], -1
00D8  ... same again ...
00E5  mov ax, word ptr es:[bx - 0x6e29]
00EA  mov dx, 0x12 / imul dx        ; record stride 0x12  <- confirmed
```

so the table is at **DGROUP + 0x91d7** (`-0x6e29` is the signed 16-bit form of 0x91d7), holds a **word
per tile** (the record index), uses **-1 as "no record"**, and the record stride is **0x12**,
independently confirmed by the `imul dx` with `dx = 0x12`.

**The base has no symbol, in either image.** `audit/dgroup_data.csv` has `0x91d6 = cursorRecordFound`
(a `undefined1`, one byte) and **nothing at 0x91d7**; `audit/symbols.tsv` has no label at or before it
either (the nearest below is `__setargv_SavedReturn + 2265`).  So the array is raw DGROUP data that the
original's own debug record did not name, and our tree does not declare it.

That blocks the conversion: writing `((uint16_t *)&X)[tileOffset]` needs an `X`, and worst-case
`MK_FP(_DS, 0x91d7)` would be wrong because our DGROUP layout differs from the original's in 83
constant-delta runs.  Doing it properly means

1. extracting the table's bytes from the original DGROUP starting at 0x91d7,
2. sizing it (max tileOffset * 2 + 2),
3. declaring it in our tree so that its bytes match, and only then
4. rewriting the ~15 `*(int *)((uint)tileIdx * 2 + -0x6e29)` sites to index it.

That is a self-contained piece of work, and it is the last outstanding item in `land_info` - the
function no longer contains any `0x2410` literal, any `(T far *)CONCAT22` build, or any
`in_stack_`/`unaff_` reference.

  grep_checks 40,248 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

#### The tile table is a zero-initialised BSS buffer, not static data

Reading the original's DGROUP at the derived base settles what the "missing symbol" is:

```
DGROUP link segment 0x2410, file offset = 0x2410*16 - 0xE200 + ofs
0x91d7 -> file 0x1f0d7
bytes: 00 00 00 00 ... (64 of them, all zero)
```

So the region is **uninitialised BSS**, zeroed by the loader and filled at runtime - which is exactly
why neither the original's symbol table nor ours has a label there, and why `dgroup_data.csv` jumps
from `cursorRecordFound` at 0x91d6 to nothing.

That makes the fix straightforward rather than blocked: a plain zero-initialised array reproduces the
bytes exactly, because they are all zero. So

```c
uint16_t GTileRecords[256];      /* BSS: zero-filled at load, populated at runtime */
```

and the ~15 sites become `GTileRecords[tileOffset]` instead of
`*(int *)((uint)tileOffset * 2 + -0x6e29)`.

The one thing to verify before committing that is **DGROUP layout**: adding 512 bytes of BSS must not
shift any symbol that `diff_dgroup` pairs, since our layout still differs from the original's in 83
constant-delta runs.  The check is mechanical - add the array, rebuild, and confirm `diff_dgroup` stays
83 deltas and `compare_state` stays 1,627/0/0; if either moves, the array has to be placed more
carefully (or the change abandoned).

  grep_checks 40,248 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### The `+2` batch rule for phantom `in_stack_` reads yields zero trustworthy sites

`tmp/phantom_fixed.py` applies three checks together:

1. the slot `XXXX + 2` must actually be read by the function's disassembly;
2. the parameter covering that slot must have a **meaningful** name - `arg2`/`arg3` carry no
   information, and the export's own naming is what the substitution is meant to improve;
3. the substitution must not collide: if the parameter's name already appears anywhere in the body, C
   forbids it being both a parameter and a local, so the mapping chose the wrong slot.

Measured result: **0 functions pass all three.**

The intermediate numbers show why. Checking only (1) accepts 54 phantoms, but of those the ones with a
meaningful parameter name all fail (3):

```
ovc11_audio      audio_usesAlignToSeg   in_stack_00000004 -> ofs              collides
ovc41_main       ovc41_specialAttack    in_stack_00000008 -> targetIndex      collides
ovc45_unitinfo   ovc45_usesAlignUp4     in_stack_0000000a -> entityIndexOut   collides
ovc15_sprite     stshRleAnims           in_stack_00000004 -> src              collides
ovc16_saveui     saveui_usesBlitGfx10   in_stack_00000004 -> gfx              collides
```

A collision is *positive evidence the slot is wrong*: a parameter and a local cannot share a name, so if
the name is already in scope the +2 rule landed on something else. That is consistent with the earlier
measurement (the shift held in only 70 of 122 functions), and it means the rule cannot be used as a
batch heuristic at all - the informative cases are exactly the ones where it fails.

Two further defects found while building the tool, both worth keeping in the script:
* a per-declaration regex misses multi-declarator lines (`char *src, *dst;`), so the collision test has
  to match the identifier anywhere in the body;
* the ADDR-to-function attribution was producing false candidates (`ovc25_findUnitCell` was listed as
  having `in_stack_00000004` while its body - already re-derived - contains none), so the phantom's
  declaration and uses must both be inside the function's own extent.

**Consequence for the in_stack_ class (1,303 occurrences, ~84 after earlier passes):** it cannot be
reduced by a batch rule. Each function needs its prologue read and the parameter at each slot
established from the load widths, which is what the earlier per-function turns did
(`chpath`, `path_strip_tail_slash`, `ensure_tail_slash`, the two path segments, `drawTextAt`,
`uiNotify`, `say`, `rle_blit_decode`/`rle_line`/`unrle_mirror`, `drawLine2`).  At 3-5 per turn that class
is ~20 turns of work and cannot be accelerated by tooling.

  grep_checks 40,248 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868

### ovc15_usesLDIV_at_2: the two far chains are struct reads again (40,240 -> 40,190)

The source comment says `4207:16a5` (the `60bc:0f5e` in my earlier notes was the wrong function), 1033
bytes, 378 instructions.

**Chain 1 - the sprite-stash pick.** One `les` plus a byte-add plus two word loads, once per level band:

```
0229  les bx, ptr es:[bx + 0x1d]      ; Agnts[agnt].gdata
022E  add bx, ax                      ; ax = bVar14 * 0xc  (imul dx, dx=0xc at 0215)
0231  mov ax, word ptr es:[bx + 0xd]  ; level >= 0xa : segment half
0235  mov dx, word ptr es:[bx + 0xb]  ;                offset half
0283  mov ax, word ptr es:[bx + 9]    ; 4 <= level < 0xa
0287  mov dx, word ptr es:[bx + 7]
02CA  mov ax, word ptr es:[bx + 5]    ; level < 4
02CE  mov dx, word ptr es:[bx + 3]
02E4  mov word ptr es:[bx + 0x15], dx ; -> Agnts[agnt].frames.seg
02E9  mov word ptr es:[bx + 0x13], ax ; -> Agnts[agnt].frames.ofs
```

The byte offsets are 3 / 7 / 0xb plus `bVar14*0xc`, which is `gdata->sprs[bVar14*3 + band]` - `sprs` is
six 4-byte far pointers starting at agntG_t offset 3. The export had

```c
uVar4  = *(uint32_t far *)&Agnts[agnt].gdata;
iVar10 = (int)uVar4 + (uint)bVar14 * 0xc;
uVar12 = *(uint16_t *)(iVar10 + 3);
```

i.e. the far pointer folded into a `uint32_t`, then truncated to `(int)` and dereferenced
DS-relative. `AgntGs` lives in its own segment, so every read addressed the wrong memory. Note the
`+ bVar14*0xc` arithmetic was *faithful* - the defect was only the dropped segment, which is why the
read offsets in the listing were always right.

**Chain 2 - the animation-variant test.**

```
033B  les bx, ptr es:[bx + 0x13]                          ; Agnts[agnt].frames
0340  mov ax, es:[bx + 0x68] / or ax, es:[bx + 0x6a]      ; frames[26] null test
0358  les bx, ptr es:[bx + 0x13]
035D  mov ax, es:[bx + 0x58] / or ax, es:[bx + 0x5a]      ; frames[22] null test
```

so `frames` is a `far_t` array and the tests are `frames[26]` / `frames[22]` as null pairs. The export
reused the same `uint32_t`/`(int)` shape, giving `*(int *)(iVar10 + 0x68)`.

**Also fixed from the same listing:** `faction` was
`*(undefined1 *)*(uint32_t far *)&Agnts[agnt].gdata`; the original is `0310 les bx, ptr es:[bx+0x1d]`
then `mov al, byte ptr es:[bx]` - `gdata->ai` at offset 0.

**Dead removed:** `uVar4`, `uVar12`, `uVar13`, `iVar10` were only the truncated temporaries, and with
them went `uVar12 = (uint16_t)((ulong)Entities >> 0x10)`, which was assigned and never read.

**Verification is the listing, not the gates.** The `es:[bx+N]` offsets now present in the rebuilt
function are exactly

```
3, 5, 7, 9, 11          the five sprs byte offsets (3 bands x bVar14)
88, 90, 104, 106        frames[22] = 0x58/0x5a and frames[26] = 0x68/0x6a
```

all through ES, with `les bx,dword ptr es:_Agnts[bx+29]` (gdata at 0x1d), `add bx,ax`, then
`mov ax,es:[bx+13] / mov dx,es:[bx+11]` for the level-10 band - the original's
`les bx,ptr es:[bx+0x1d] / add bx,ax / mov ax,es:[bx+0xd] / mov dx,es:[bx+0xb]`. Before the fix those
offsets appeared with **no `es:` prefix at all**, i.e. DS-relative - the segment was not even involved,
which is worse than the segment-0 `CONCAT22` class because it silently reads our own DGROUP.

  grep_checks 40,240 -> 40,190; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### Three more truncated record reads, and a count of the whole class

`tmp/find_truncfar.py` enumerates the shape that has now been fixed six times: a far pointer folded
into a `uint32_t` and then truncated with `(int)`, so the dereference is DS-relative even though the
record lives in its own segment. It found **31 reads in 9 functions**. Three were unambiguous and are
fixed here.

**ovc42_usesAgntCount** - three reads of `agntG_t.type` (offset 1):

```c
uVar1 = *(uint32_t far *)&Agnts[iVar3].gdata;
if (*(char *)((int)uVar1 + 1) == '\x02') {
```

becomes `Agnts[iVar3].gdata->type == '\x02'` (and `\x01`, `\v`). Emitted:

```
les  bx,dword ptr es:_Agnts[bx+29]     ; gdata at 0x1d
cmp  byte ptr es:[bx+1],2
```

and the module now has **zero** DS-relative `[bx+1]`.

**ovc27_compute1** - one read of `agntG_t.flags2` (0x3e). Emitted `test word ptr es:[bx+62],16`. This
function already used `((agntG_t far *)agnt->gdata)->flags` correctly on its next line, so the one site
was simply inconsistent with its own neighbours.

**ovc27_compute2** - not a truncated pointer but the same consequence: the record *offset* used as a DS
pointer.

```c
(in_AX = param * 0x34, (*(uint *)(in_AX + 0x2b) & 0x7e0) == 0)
```

`param * 0x34` indexes the Agnts segment, so `*(uint *)(in_AX + 0x2b)` read DGROUP. 0x2b is
`Agnts[].flags` (audit/symbols.tsv). Emitted `test word ptr es:_Agnts[bx+43],2016`.

**Queue after this:** 27 reads in 7 functions - `stats_usesAlignUp42` (14), `stats_readyStatusText` (3),
`attact_usesAgntFlag1` (3), `ovc49_drawAgents` (3), `ovc49_body1` (2), `ovc41_unitStatusText` (1).
`stats_usesAlignUp42` (6386:1c9f) is the single biggest remaining target: 14 reads, 26 locals, and its
`gdata`/`entity` chains are the same shape already decoded twice.

**Deliberately not touched:** the three remaining
`far_from_u32((uint32_t)(SEG_OF(Agnts)))` arguments to `drawAgntStats` (ovc33_stats.c:1803, 1848, 1932).
`SEG_OF(Agnts)` is 0x50, so each builds `{ofs:0x50, seg:0}` - a colormap pointer into segment 0, which
is certainly wrong. But the call sites do not agree on arity, so the correct replacement is not the same
at all three:

```
stats_setAgentBase     6386:16a2   push 0 / push 0x50 / push ax            (3 words)
stats_calledAwayNotice 6386:1837   push 0 / push 0x50 / push ax            (3 words)
stats_openAgentDetail  6386:1abe   push 0 / push 0 / push 0x50 / push ax   (4 words)
```

Only the third matches the 4-word shape fixed earlier in `stats_unreadyNotice` (`far agnt` + a zero
`far_t`). The first two push a single extra word, which means the declared
`drawAgntStats(agnt_t far *, far_t cmap, uint16_t arg3)` splits those two call sites wrongly - either the
`far_t` is really one word there, or a word belongs to a different argument. Settling it means reading
`drawAgntStats`'s own prologue at 6386:06cd and its `add sp` accounting, which is a turn of its own, so
these are recorded rather than guessed.

  grep_checks 40,190 -> 40,180; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### stats_usesAlignUp42: 11 chained far reads restored (40,180 -> 40,160)

`6386:1c9f`, 1618 bytes, 581 instructions, 340 lines - the largest single target left in the
truncated-far class (14 of the 27 remaining reads).  Every chain was confirmed from the listing first:

```
0096  les bx, ptr es:[bx + 0x1d] / mov al, byte ptr es:[bx + 0x46]      gdata->shortName[3]
00CA  les bx, ptr es:[bx + 0x17] / mov al, byte ptr es:[bx + 0xf]       entity->base.level
010D  same                                                             entity->base.level
021C  les bx, ptr es:[bx + 0x17] / mov al, byte ptr es:[bx + 0x1a]      base.entity byte 3
02CB  les bx, ptr es:[bx + 0x17] / cmp byte ptr es:[bx + 0x1a], 0xff    base.entity byte 3
0344  les bx, ptr es:[bx + 0x1d] / mov al, byte ptr es:[bx]             gdata->ai
0402  les bx, ptr es:[bx + 0x17] / mov al, byte ptr es:[bx + 0x33]      flags32 high byte
046E  les bx, ptr es:[bx + 0x17] / test byte ptr es:[bx + 0x33], 1      flags32 high byte
0507  les bx, ptr es:[bx + 0x17] / cmp byte ptr es:[bx + 0x1a], 0xff    base.entity byte 3
0537  les bx, ptr es:[bx + 0x17] / mov al, byte ptr es:[bx + 0x1a]      base.entity byte 3
05EB  les bx, ptr es:[bx + 0x17] / mov al, byte ptr es:[bx + 0x1a]      base.entity byte 3
```

Eleven blocks became struct reads.  Verified in the emitted listing - the `es:[bx+N]` offsets in the
rebuilt function are now exactly

```
0     gdata->ai              les bx,es:_Agnts[bx+29] / cmp byte ptr es:[bx],0
15    entity->base.level     x2
26    base.entity byte 3     x5
51    flags32 high byte      x2
70    gdata->shortName[3]    x1
```

against the original's 0x0 / 0xf / 0x1a / 0x33 / 0x46.

#### A swapped pair of stores, found and left

The block at lines 2056-2060 reads two words from a table and writes them into the entity record.  The
original stores them the opposite way round from the export:

```
0123  mov ax, word ptr es:[bx + 2]      ; table word 1
0128  mov dx, word ptr es:[bx]          ; table word 0
0149  mov word ptr es:[bx + 0x12], dx   ; entity + 0x12 <- table[0]
014D  mov word ptr es:[bx + 0x10], ax   ; entity + 0x10 <- table[1]
```

```c
*(uint16_t *)(iVar14 + 0x12) = puVar13[1];   /* export: table[1] */
*(uint16_t *)(iVar14 + 0x10) = uVar16;       /* export: table[0] */
```

Two reasons not to guess the correction: the table is reached with `mov ax,0x80 / mov es,ax` - segment
**0x80** - which the export turned into a NEAR pointer, so both the reads and the store targets need that
segment identified first; and a word store at `entity+0x12` spans `frameIndex` and the low byte of
`frames`, so the field pair has to be named from the record layout rather than invented.

**Queue after this:** 17 reads in 7 functions - `stats_openAgentDetail` 4, `attact_usesAgntFlag1` 3,
`stats_readyStatusText` 3, `ovc49_drawAgents` 3, `ovc49_body1` 2, `ovc41_unitStatusText` 1,
`ovc27_compute2` 1.  `stats_readyStatusText` sits behind `in_stack_00000004`, so it belongs with the
phantom work rather than here.

  grep_checks 40,180 -> 40,160; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### Four more functions freed of truncated far reads (40,160 -> 40,145)

**attact_usesAgntFlag1** (`3f0b:0685`):

```
0043  les bx, ptr es:[bx + 0x17] / pop ax / mov byte ptr es:[bx + 0x31], al
0071  les bx, ptr es:[bx + 0x17] / mov al, byte ptr es:[bx + 0x32] / push ax
0089  les bx, ptr es:[bx + 0x17] / pop ax / mov byte ptr es:[bx + 0x31], al
```

Both stores write the entity record's byte `0x31` (`base.state + 1`) and the second reads `0x32`
(`base.flags32`).  The export went through `uVar1`/`uVar2 = *(uint32_t far *)&Agnts[i].entity` and
`(int)uVar1 + 0x31`; both temporaries are now gone and the emitted code is

```
les  bx,dword ptr es:_Agnts[bx+23]     ; entity at 0x17
pop  ax
mov  byte ptr es:[bx+49],al            ; 0x31
```

with the function's `es:[bx+N]` set exactly `{49, 50}` = `{0x31, 0x32}`.

**ovc41_unitStatusText** (`6a8f:04c0`) - `les bx,ptr es:[bx+0x17] / cmp al, byte ptr es:[bx+0x1a]`,
which is `base.entity` byte 3, the same field `stats_unreadyNotice` already reads with `AGNT_FIELD`.
Emitted `les bx,dword ptr es:_Agnts[bx+23] / cmp al,byte ptr es:[bx+26]`.

**ovc49_agents.c** - eight inline reads of `*(T *)*(uint32_t far *)&Agnts[i].gdata`, written by the
export without even a temporary:

```
ovc49_textLongerParalyzed  3393/3394/3398   gdata->ai
ovc49_drawAgents           4154/4155/4159   gdata->ai
ovc49_textLongerParalyzed   501/502         gdata->flags2 & 0x80
ovc49_textLongerParalyzed   522/523         gdata->flags  & 4
```

Verified by listing `ovc49_textLongerParalyzed` alone (o49 still cannot list as a module - "Compiler
table limit exceeded in ovc49_body1"): `es:[bx]` x14, `es:[bx+60]` x6, `[bx+62]` x6, `[bx+64]` x7, and
the flags2 chain reads `les bx,dword ptr es:[bx+29] / test word ptr es:[bx+62],1`.  `uVar1` existed
only for the two comma-expression copies, so its declaration is removed.

#### Note on the queue metric

`tmp/find_truncfar.py` still reports 13 reads in 5 functions because its `TRUNC` regex only matches the
*assignment* form (`x = *(uint32_t far *)&...`).  The inline forms (`*(char *)*(uint32_t far *)&...`)
are invisible to it, so the queue undercounts.  The gate itself moved by 5 for eight fixed sites, which
is a better indicator of the actual remaining work than the scanner's total.  Remaining known sites:
`stats_openAgentDetail` 4, `stats_readyStatusText` 3 (behind `in_stack_00000004`), plus the `uVar31`
group in `ovc49_body1` (2944/2979/3184) and `ovc49_drawAgents` (3955/3971) which the scanner does see.

  grep_checks 40,160 -> 40,145; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### Three more ovc49 gdata reads, and the queue scanner corrected (40,145 -> 40,139)

Chain evidence:

```
8699:1e09 (ovc49_drawAgents)
  0D77  les bx, ptr es:[bx + 0x1d] / mov al, byte ptr es:[bx + 0x52]   agntG_t.yOffset
  0F64  les bx, ptr es:[bx + 0x1d] / test word ptr es:[bx + 0x40], 2   agntG_t.flags3
8699:18c4 (ovc49_body1)
  0045  les bx, ptr es:[bx + 0x1d] / test word ptr es:[bx + 0x40], 2   agntG_t.flags3
  04A4  les bx, ptr es:[bx + 0x1d] / test word ptr es:[bx + 0x40], 4   agntG_t.flags3
```

```c
2941/2943  ... + (int)*(char *)((int)uVar31 + 0x52) + -0x16;
       ->  ... + (int)Agnts[uStackY_22].gdata->yOffset + -0x16;
2976/2977  if ((*(uint *)((int)uVar31 + 0x40) & 2) == 0)
       ->  if ((Agnts[uStackY_22].gdata->flags3 & 2) == 0)
3181/3182  (uVar31 = ..., (*(uint *)((int)uVar31 + 0x3c) & 8) == 0)
       ->  ((Agnts[uStackY_22].gdata->flags & 8) == 0)
```

`uVar31` is a genuine multi-role temporary (12 uses in this file, including a different
`*(uint32_t *)((in_stack_0000ffe4 & 0xff) * 0x34 + -0x1d)` at 3195), so only the three dereferences are
replaced and its declaration stays.

#### Verification without a listing

`ovc49_body1` cannot be listed - `Compiler table limit exceeded in function ovc49_body1` - so the
emitted offsets for that function cannot be read directly.  The three field offsets were pinned by a
four-line probe compiled through the same build:

```
probe_yoffset: les bx,dword ptr [bp+6] / mov al, byte ptr es:[bx+82]   = 0x52
probe_flags3 : les bx,dword ptr [bp+6] / mov ax, word ptr es:[bx+64]   = 0x40
probe_flags  : les bx,dword ptr [bp+6] / mov ax, word ptr es:[bx+60]   = 0x3c
```

exactly the original's `0x52` / `0x40` / `0x3c`.  The far-ness is implied by the field types
(`agntG_t far *`), so each read emits `les` + `es:` instead of the previous DS-relative access.  That is
weaker than reading the function's own listing and is recorded as such.

#### The queue scanner was undercounting

`tmp/find_truncfar.py`'s `TRUNC` regex matched only the assignment form (`x = *(uint32_t far *)&...`),
so the inline form `*(char *)*(uint32_t far *)&...` - the shape most remaining sites use - was invisible.
It now matches `(uint32_t far *)&FIELD` in every shape.  Recounted:

```
agnt_usesStrengthMax   4   ovc12_agnt.c      AgntArrayA/B[i][colA] - 1
stats_openAgentDetail  4   ovc33_stats.c     1 is the segment-0x80 table block
ovc49_drawAgents       4   ovc49_agents.c
stats_readyStatusText  3   ovc33_stats.c     behind in_stack_00000004
agnt_acquireTarget     1   ovc12_agnt.c
ovc27_compute2         1   ovc27_combat.c
```

Two of those functions (`agnt_usesStrengthMax`, `agnt_acquireTarget`) had never appeared in the queue,
which is why the previous three turns kept reporting the class as nearly empty.

  grep_checks 40,145 -> 40,139; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### agnt_usesStrengthMax and two singles: six more far reads restored (40,139 -> 40,135)

**agnt_usesStrengthMax** (`3b1d:0426`) indexes two column tables and reads the record at
`Agnts[AgntArrayX[i][colA] - 1]`.  The chain uses a **negative displacement**, which is why it was easy to
misread:

```
028F  les bx, ptr es:[bx - 0x17] / mov al, byte ptr es:[bx]             agntG_t.ai
02C0  les bx, ptr es:[bx - 0x17] / test word ptr es:[bx + 0x3c], 0x20   agntG_t.flags
0488  same pair again for the AgntArrayB side
```

`bx` already holds `idx*0x34` at that point, so `[bx-0x17]` is `(idx-1)*0x34 + 0x1d` -
`Agnts[idx-1].gdata`.  The export had

```c
*(uint8_t *)*(uint32_t far *)&Agnts[AgntArrayA[iVar7][colA] - 1].gdata == factionId
(gdataFar = *(uint32_t far *)&Agnts[...].gdata, (*(uint *)((int)gdataFar + 0x3c) & 0x20) == 0)
```

now `...gdata->ai == factionId` and `(...gdata->flags & 0x20) == 0`, and `uint32_t gdataFar` is gone.
Emitted, matching the original:

```
261  les  bx,dword ptr es:_Agnts[bx-23]
262  mov  al,byte ptr es:[bx]
263  cmp  al,byte ptr [bp-1]
284  les  bx,dword ptr es:[bx]
285  test word ptr es:[bx+60],32
```

**agnt_acquireTarget** - `*(byte *)((int)uVar1 + 0x42)` is `agntG_t.rank`, emitted as
`les bx,dword ptr es:_Agnts[bx+29] / mov al,byte ptr es:[bx+66]` (0x42).

**ovc27_compute2** - `*(uint *)((int)uVar1 + 0x3e) & 0x10` is `agntG_t.flags2`, emitted as
`les bx,dword ptr es:_Agnts[bx+29] / test word ptr es:[bx+62],16` (0x3e).

#### A self-inflicted error, caught

The `AgntArrayB` substitution lost its opening parenthesis: the original wrapped the cast in a group
(`(*(uint8_t *) ... == factionId)`), and my replacement dropped the `(` while keeping both `)`.  The
compiler reported `Expression syntax` immediately, and the paren was restored before anything was
committed.  The `AgntArrayA` form was fine because that one really had two opening parens.

**Queue after this:** 11 reads in 3 functions - `stats_openAgentDetail` 4 (one is the segment-0x80 table
block whose store order is also swapped), `ovc49_drawAgents` 4 (one is a word at `entity+0x14`, spanning
`frames`' second byte), `stats_readyStatusText` 3 (behind `in_stack_00000004`).

  grep_checks 40,139 -> 40,135; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### The truncated-far class is down to 4 reads (40,135 -> 40,129)

**ovc49_drawAgents** (`8699:1e09`) held four, each confirmed from the listing:

```
1859  les bx, ptr es:[bx] / test word ptr es:[bx + 0x14], 2            word inside base.frames
0D7C  les bx, ptr es:[bx + 0x1d] / mov al, byte ptr es:[bx + 0x52]    agntG_t.yOffset
0F69  les bx, ptr es:[bx + 0x1d] / test word ptr es:[bx + 0x40], 2    agntG_t.flags3
      (plus a 0x3c flags test, offset pinned by probe)
```

The `+0x14` one is **not** a named field: `0x13` is `frames`, a 4-byte `far_t`, so `0x14` is a two-byte
read one byte into it.  Written with an explicit byte offset so the operand comes out right:

```c
*(uint16_t far *)((uint8_t far *)&Agnts[agntIndex - 1].entity->base.frames + 1)
```

pinned by probe: `les bx,dword ptr es:[bx+23] / mov ax,word ptr es:[bx+20]` — 0x17 then 0x14.  The other
three became `gdata->yOffset`, `gdata->flags3 & 2`, `gdata->flags & 8`, and `uint32_t unitPtr` is gone.
**`ovc49_agents.c` now contains no `uint32_t far *` at all.**

**ovc33_stats.c** - three `gdata + 1` reads became `gdata->type`:

```
les  bx,dword ptr es:_Agnts[bx+29]
cmp  byte ptr es:[bx+1],2
```

These three lines sit in a region the export merged into `stats_openAgentDetail`, but that function's
581 instructions contain **no** `es:[bx + 1]` access at all - the `switchD_6000_58bf` label in the same
body says the merge came from segment 0x6000.  So their original home is unknown; the construct is
unambiguous anyway (`gdata` truncated to `(int)` then read at +1 is `agntG_t.type`), and the surrounding
constants `0x3d/0x12`, `0x56/0x14`, `0x6e/0xb` are exactly `ovc42_usesAgntCount`'s, which already reads
`gdata->type`.  The change that matters is the **segment**: `AgntGs` is not in DGROUP.

#### What is left, and why each is blocked

```
stats_readyStatusText  3   all through in_stack_00000004  -> belongs with the phantom work
stats_openAgentDetail  1   the segment-0x80 table block   -> table unnamed in either image,
                                                            and its two stores are swapped
```

The `+0x10`/`+0x12` block at `0149`/`014D` stores `table[0]` to `entity+0x12` and `table[1]` to
`entity+0x10`; the export has them the other way round.  Finishing it needs segment **0x80** identified -
`audit/symbols.tsv` has no such segment at all (its segments are 0x0ff0, 0x1000, 0x1301, 0x1726, 0x195d,
0x2000, ...), so it is runtime data, most likely a `stshAlloc` block.  That is a separate investigation.

  grep_checks 40,135 -> 40,129; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

#### The swapped stores in stats_usesAlignUp42 are fixed (40,129 -> 40,122)

```
0123  mov ax, word ptr es:[bx + 2]      ; table word 1
0128  mov dx, word ptr es:[bx]          ; table word 0
0135  push ax / 0138 push dx
0142  les bx, ptr es:[bx + 0x17]        ; Agnts[agntIndex].entity
0147  pop ax / 0148 pop dx
0149  mov word ptr es:[bx + 0x12], dx   ; entity + 0x12 <- table[0]
014D  mov word ptr es:[bx + 0x10], ax   ; entity + 0x10 <- table[1]
```

The export had **both** the order and the segment wrong: `*(uint16_t *)(iVar14 + 0x12) = puVar13[1]`
and `*(uint16_t *)(iVar14 + 0x10) = uVar16` with `iVar14 = (int)uVar1`, so the two words were swapped
*and* the stores went to DS instead of the entity's segment.  Now

```c
*(uint16_t far *)((uint8_t far *)&Agnts[agntIndex].entity->base.frameIndex) = uVar16;
*(uint16_t far *)((uint8_t far *)&Agnts[agntIndex].entity->base.health) = puVar13[1];
```

(0x10 = `health`, 0x12 = `frameIndex`; both stay word-sized because the original stores words - a word
at 0x12 spans `frameIndex` and the low byte of `frames`, which is what the machine does.)

Emitted, matching the original:

```
113  les bx,dword ptr es:_Agnts[bx+23]
114  mov ax,word ptr [bp-52]          ; table[0]
115  mov word ptr es:[bx+18],ax       ; entity + 0x12
123  les bx,dword ptr es:_Agnts[bx+23]
125  mov ax,word ptr [si+2]           ; table[1]
126  mov word ptr es:[bx+16],ax       ; entity + 0x10
```

**The table itself is still unnamed.**  The original reaches it with `mov ax,0x80 / mov es,ax`, and
segment 0x80 appears nowhere in `audit/symbols.tsv` - the segments it does list are 0x0ff0, 0x1000,
0x1301, 0x1726, 0x195d, 0x2000, 0x217a, 0x218e, 0x21b1, 0x21f2 ...  So it is runtime data, most likely
a `stshAlloc` block, and naming it needs the allocation site rather than the read site.  The two reads
keep the export's near pointer; fixing the stores is strictly closer to the original and does not depend
on identifying it.

**Truncated-far class: 4 -> 3**, all in `stats_readyStatusText` and all through `in_stack_00000004`,
so the last of that class belongs with the phantom work.

  grep_checks 40,129 -> 40,122; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

#### stats_readyStatusText: the phantom is the parameter, and the truncated-far class closes (40,122 -> 40,099)

The prologue of `6386:12b7` settles it in three instructions:

```
0003  mov al, byte ptr [bp + 6]
0008  mov dx, 0x34 / imul dx        ; agntIndex * sizeof(agnt_t)
```

`bp+6` is used as the agent index before anything else, and it is the declared first parameter
(`byte agntIndex`).  So `in_stack_00000004` is `agntIndex` - the `+2` shift holds *here*, and unlike the
batch attempts earlier the substituted name is meaningful and appears nowhere else in the body, so the
mapping is proved rather than guessed.

With the phantom gone, the last three truncated reads became struct accesses:

```c
if ((*(uint8_t far *)((uint8_t far *)&Agnts[agntIndex].entity->base.flags32 + 1) & 1) == 0) {
  ...
  puVar2 = ovr_ovc15_usesStshRealloc
                     ((char *)far_ofs_u32(Agnts[agntIndex].gdata->name),
                      (uint16_t)SEG_OF(Agnts[agntIndex].gdata->name),0,0,0,0,0,0);
```

Emitted:

```
les  bx,dword ptr es:_Agnts[bx+23]     ; entity 0x17
test byte ptr es:[bx+51],1             ; 0x33 - flags32 high byte
les  bx,dword ptr es:_Agnts[bx+29]     ; gdata 0x1d
push word ptr es:[bx+36]               ; 0x24 - name.ofs
```

against `les bx,ptr es:[bx+0x17] / mov al, byte ptr es:[bx+0x33] / test ax,1`.
`uint32_t uVar1`, `uint16_t uVar6` and `int iVar5` existed only for the removed copies.

#### The truncated-far class is empty

`tmp/find_truncfar.py` now reports **0 reads in 0 functions**, down from 31 in 9 at the start of this run.
The whole class, across nine turns, was:

| turn | function | reads | delta |
|---|---|---|---|
| 1 | ovc41_turnUndeadNotice | 5 | -143 (with other work) |
| 2-3 | ovc33_stats drawAgntStats sites | 6 | -3 |
| 4 | ovc41 SEG_OF(CONCAT22) sites | 3 | 0 |
| 5 | ovc15_usesLDIV_at_2 | 2 chains | -50 |
| 6 | ovc42/ovc27_compute1/compute2 | 5 | -10 |
| 7 | stats_usesAlignUp42 | 11 | -20 |
| 8 | attact_usesAgntFlag1, ovc41_unitStatusText, ovc49 x8 | 14 | -15 |
| 9 | ovc49_body1 x3 | 3 | -6 |
| 10 | agnt_usesStrengthMax, agnt_acquireTarget, ovc27_compute2 | 6 | -4 |
| 11 | ovc49_drawAgents x4, ovc33 type x3 | 7 | -6 |
| 12 | stats_usesAlignUp42 stores (swapped) | 1 | -7 |
| 13 | stats_readyStatusText | 3 | -23 |

Every site had the same root cause: a far pointer folded into a `uint32_t` (or a record offset used
directly as a DS pointer), so the read or write went to DGROUP instead of the record's own segment.
`Agnts`, `AgntGs` and `Entities` all live outside DGROUP, which is why none of these were harmless.

  grep_checks 40,122 -> 40,099; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### MEASURED: the `in_stack_` phantom class does not batch, with four verified examples

`stats_readyStatusText` worked because its phantom happened to be a declared byte parameter at exactly
bp+6.  Scanning every phantom (`tmp/phantom_clean.py`, 99 phantom locals in 75 functions) and checking
four of them by hand shows that is the exception:

| function | phantom -> slot | what the slot really is |
|---|---|---|
| `agnt_advanceAnimFrame(agnt_t far *agnt, uint16_t arg2)` | `in_stack_00000006` -> bp+8 | **the segment word of `agnt`** (bp+6..9); `arg2` is at bp+0xa, so the real shift is **+4** |
| `attact_usesAlignUp44(int *xPtr, int y, uint8_t dir)` | `in_stack_0000000c` -> bp+0xe | **past the last parameter** (dir ends at bp+0xa) - a fifth argument the caller passes and the prototype omits |
| `ovc15_capitalize(char *text)` | bp+8, bp+0xa, bp+0xc | the body is `strcpy(CONCAT22(in_stack_00000006,text), CONCAT22(in_stack_0000000a,in_stack_00000008))`, i.e. **two far pointers** the export split into halves around a near `text` |
| `miceBlitRect(brect_t *br, uint16_t arg2)` | `in_stack_00000006` -> bp+8 | the prologue is `les bx, ptr [bp + 6]`, so `br` is **far** (bp+6..9) and `arg2` is at bp+0xa - the declared *near* `brect_t *` is itself wrong |

So the `+2` shift is not a rule, the signature is often what is wrong rather than the name, and the
"collision" rejection used earlier was detecting exactly this.  Every phantom needs its own prologue
read, and in two of the four cases the fix is a **signature** change (near/far or a missing argument),
which needs the callers too.

### ovc22_usesLUDIV_at_ (40,099 -> 40,097)

Opened with

```c
uVar6 = (uint16_t)((ulong)entity >> 0x10);
peVar5 = (entity_t *)entity;
```

`uVar6` (the segment half of `entity`) is never read again - dead.  `peVar5` is a straight alias for the
`entity` parameter, used three times.  Both removed.

**Found and not fixed:** `uVar1 = *(uint32_t *)(uVar2 << 2)` reads a 32-bit value from the **near**
address `uVar2 << 2` - DS offset partySlot*4 - which cannot be right; it needs the table base from
`5087:197d`.  Note this is *not* the truncated-far class (that scanner looks for `(uint32_t far *)`), so
it is a separate bug of the same family and worth a pass of its own:
`grep 'uint32_t \*)([a-zA-Z_]* << 2)' *.c` should find the rest.

  grep_checks 40,099 -> 40,097; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### The near-table class: `*(uint32_t *)(X << 2)` is an array index, not an address (40,097 -> 40,071)

`ovc22_usesLUDIV_at_` (`5087:18b6`) was the example.  The original:

```
0008  les bx, ptr [bp + 6]              ; the entity record
000B  mov al, byte ptr es:[bx + 0x1a]   ; base.entity byte 3 = the party slot
0013  mov bx, di / shl bx, 2            ; partySlot * 4
0018  mov ax, 0x70 / mov es, ax         ; segment 0x70
001D  les bx, ptr es:[bx]               ; far pointer at table[partySlot]
0022  mov al, byte ptr es:[bx + 0x52]
004B  mov bx, di / shl bx, 2            ; same slot again
0050  mov ax, 0x70 / mov es, ax
0055  les bx, ptr es:[bx]
005A  mov al, byte ptr es:[bx + 0x2f]
```

The table is a far-pointer array at DGROUP-relative segment **0x70**, indexed by party slot, which is
`extern char_sheet_t far *GLeaderSheets[80]`.  The export emitted `*(uint32_t *)(uVar2 << 2)` - a *near*
read at DS offset `partySlot*4` - and then dereferenced the value it found there.  Now:

```c
partySlot = (uint)*(byte *)((int)&(entity->base).entity + 3);
sheet = GLeaderSheets[partySlot];
lvlIdx = *((uint8_t far *)sheet + 0x52) + 1;
...
classId = sheet->cls;                  /* char_sheet_t.cls at +0x2f, 0xff = none */
```

`+0x2f` is `char_sheet_t.cls`, playing exactly the role `agntG_t.shortName[3]` plays in
`stats_usesAlignUp42`: a class index with a 0xff sentinel that indexes the 0x94-stride table.  `+0x52`
sits inside `char_sheet_t.income` (a short at 0x52), so it stays an explicit byte offset rather than a
field name.

Emitted, matching the original's shape:

```
mov  al,byte ptr [bx+26]                        ; partySlot
shl  bx,2
mov  ax,word ptr DGROUP:_GLeaderSheets[bx+2]
mov  dx,word ptr DGROUP:_GLeaderSheets[bx]
les  bx,dword ptr [bp-4]
mov  al,byte ptr es:[bx+82]                     ; 0x52
```

**The same shape elsewhere:** `grep '*(uint32_t *)(X << 2)' *.c` finds
`ovc18_leaderview.c:72,73,898,1166` and `ovc20_stash.c:613,614,615,618`.  Those are the queue for this
class.

**Found, not changed:** the parameter is declared `entity_t *entity` (near) while the original does
`les bx, ptr [bp + 6]` - `entity` is far.  That is a signature change and needs the callers read.

  grep_checks 40,097 -> 40,071; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### ovc18_leaderview: four near-table reads are GLeaderSheets

Four `*(byte *)((int)*(uint32_t *)(idx << 2) + 0x3f)` reads - the defect proved for
`ovc22_usesLUDIV_at_` last turn.  Here the table needs no investigation, because the correct form sits in
the same expression:

```
71  if ((((GLeaderSheets[iVar5])->active != '\0') &&
72      ((&partyCounts)[*(byte *)((int)*(uint32_t *)(iVar5 << 2) + 0x3f)] = ...
74      (GLeaderSheets[iVar5])->x == GfxRndSeed)) &&
```

so `*(uint32_t *)(iVar5 << 2)` is `GLeaderSheets[iVar5]`, and 0x3f is a single byte:

```c
*((uint8_t far *)GLeaderSheets[iVar5] + 0x3f)
```

Four sites: `ovc18_showLeaderView` (line 72, both occurrences of the increment),
`ovc18_checkFortressPlacement` (898), `ovc18_usesAlignUp4` (1166).  Emitted for the second of those:

```
mov  bx,di / shl bx,2
mov  bx,word ptr DGROUP:_GLeaderSheets[bx]
cmp  byte ptr es:[bx+63],0            ; 0x3f
```

with ES carrying the segment from the preceding `les ... _GLeaderSheets[bx]` for the same index.

### ovc20_stash.c: the table's segment is 0x48, its symbol is not known

The four sites at 613/614/615/618 reference a far-pointer table, and the disassembly names its segment:

```
4b0a:0b9c, at 0146:
  0146  mov bx, si / 0148 shl bx, 2      ; i * 4
  014B  mov ax, 0x48 / 014E mov es, ax   ; segment 0x48
  0150  les bx, ptr es:[bx]              ; far pointer at table[i]
  0155  mov word ptr es:[bx + 3], 0
  015B  mov word ptr es:[bx + 1], 0
  0173  mov word ptr es:[bx + 5], ax
```

The freshly allocated pointer is stored back into the same table (the export's
`((uint16_t *)(i * 4))[1]` / `*(uint16_t *)(i * 4)` pair), so it is one array of far pointers in
**segment 0x48**, not at DS offset 0.  Segment 0x48 appears in neither `audit/symbols.tsv` nor the tree,
so the base symbol is unidentified - the same blocker as segment 0x80 in `stats_usesAlignUp42`.  Left
unchanged rather than pointed at a guessed symbol.

  grep_checks 40,071 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### Segment 0x48 is `AudioHandles` - and the retry was reverted unverified

**The identification stands.**  `st_globals.h:63` declares

```c
extern DW far far AudioHandles[140];
```

the only `far far` dword array in this module's neighbourhood, and `far far` is exactly what places an
array in its own segment - the same mechanism that puts `Agnts` and `AgntGs` there.  With the
disassembly (`0146 mov bx,si / 0148 shl bx,2 / 014B mov ax,0x48 / 014E mov es,ax / 0150 les bx,ptr
es:[bx]`) and line 605's existing `&AudioHandles[i]` test, segment 0x48 is `AudioHandles`.

**The rewrite was reverted.**  I rewrote lines 611-618 as

```c
((uint16_t far *)((uint8_t far *)&AudioHandles[0] + i * 4))[1] = iVar10;
handle = (uint8_t far *)*(uint32_t far *)&AudioHandles[i];
*handle = 3;
*(uint16_t far *)(handle + 3) = 0;
...
```

It compiled clean and passed every gate, but the emitted listing for `stshInitAudioAssets` contains **no**
`es:[bx+2]` store, and other accesses to the table appear as `mov word ptr _AudioHandles[bx]` -
DS-relative.  The far store I intended did not materialise, so there is no evidence the fix changes the
addressing.  Committing it would be the same failure mode as the `_fsetmem` `CONCAT22` attempt and the
blanket `agntG_t` cast earlier in this session.

**Open question to settle before retrying:** why `&AudioHandles[0]` does not produce a far pointer here.
`Agnts` is declared identically (`agnt_t far far Agnts[24]`) and its accesses *do* emit
`mov dx,seg _Agnts / mov es,dx`, so the qualifier works.  The difference is either that `DW` is a struct
typedef rather than a scalar, or that the `(uint8_t far *)` cast in between discards the segment.

  grep_checks 40,071 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

#### Correction: the ovc20_stash rewrite works - my revert was a grep artifact

Last turn's revert was based on "the listing contains no `es:[bx+2]`".  That was a mistake: I searched
for one register form.  A three-line probe settles the underlying question, because `DW` is
`struct DW { uint16_t lo, hi; }` and it was not obvious that a struct-typed `far far` array still gets
its own segment:

```c
DW far far probeDW[4];
```

```
probeDW[i].lo                  -> mov ax,seg _probeDW / mov es,ax / mov ax,word ptr es:_probeDW[bx]
&probeDW[0] + i*4              -> mov dx,seg _probeDW / add ax,offset _probeDW
*(uint32_t far *)&probeDW[i]   -> mov dx,word ptr es:_probeDW[bx+2] / mov ax,word ptr es:_probeDW[bx]
((uint16_t far *)((char far *)&probeDW[0] + i*4))[1] = v
                               -> mov ax,seg _probeDW / mov es,ax / mov word ptr es:_probeDW[bx+2],dx
```

So the construct emits exactly the far addressing the original uses, and the re-applied rewrite verifies
in `stshInitAudioAssets`:

```
mov  bx,si / shl bx,2
mov  ax,seg _AudioHandles
mov  es,ax
mov  word ptr es:_AudioHandles[bx+2],dx
...
mov  ax,word ptr es:_AudioHandles[bx+2]
mov  dx,word ptr es:_AudioHandles[bx]
les  bx,dword ptr [bp-50]
mov  byte ptr es:[bx],3
mov  word ptr es:[bx+3],0
```

against the original's `mov ax,0x48 / mov es,ax / les bx,ptr es:[bx] / mov byte ptr es:[bx],3 /
mov word ptr es:[bx+3],0 / ...`.  `seg _AudioHandles` replaces the original's link-time literal `0x48`.

**Lesson worth keeping:** "the listing does not contain X" only means that when the search covers every
form X could take.  Three times this session I have drawn a conclusion from a pattern that was too
specific (pointer-in-offset vs pointer-in-segment, function-level vs argument-level phantom checks, and
now a register-specific operand search).  A one-function probe is cheaper than a revert.

  grep_checks 40,071 -> 40,067; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### Segment 0x80: the stride decodes, the declaration is missing

MEASURED: segment 0x80 is a [class][37] far-pointer table that our tree does not declare

Chasing segment 0x80 (the per-class table `stats_usesAlignUp42` indexes) produced two concrete results.

1. THE STRIDE DECODES AS 37 FAR POINTERS.  The index is

     piVar12 = (int *)((uint)classId * 0x94 + level * 4);

   0x94 = 148 = 37 * 4, and the level index is clamped to 0x24 (36) inclusive just before the walk, so
   the second dimension is exactly levels 0..36 = 37 entries.  Each entry is a far pointer: the null test
   is `*piVar12 == 0 && piVar12[1] == 0` and LUDIV_at_ is handed `*piVar4, piVar4[1]`.  So the table is

     far_t <something>[nClasses][37]

   read through `mov ax,0x80 / mov es,ax`.

2. THAT DECLARATION IS ABSENT FROM THE TREE.  `grep '\[37\]' st_globals*.h` finds nothing, and the
   `far far` list (mapSquare*, columnScreenY, AudioHandles, Agnts, AgntArrayA/B, SquareRecs,
   EntityTypeSeg, BuildingTypes, AgntGs, BldFlags, BldGfxRuins/Normal, Stsh*, AudioSeg, expThresholds,
   miceTileTail) contains no such array.  That is why the export fell back to a near read at DS offset
   `classId*0x94 + level*4` instead of a segment-relative one - the base symbol it should have used does
   not exist in our tree.

   Adding it needs **nClasses**, which nothing in the body gives.  Declaring
   `far_t far far X[8][37]` and hoping would fix the addressing but invent the size, and a `far far`
   array's own segment is exactly the thing being modelled, so the wrong size is not a harmless guess.

NOT FIXED, and not guessed.  The two near reads in stats_usesAlignUp42 stay as they are; they are already
commented in the body as blocked on this.

SEPARATE BUG FOUND WHILE LOOKING.  ovc09_init.c has a dozen sites of the form

  psVar9 = (stg_tmp_t *)(row * 0x94);

but `stg_tmp_t` is `{ uint8_t cmap[768]; far_t aptr; far_t bptr; }` = 0x308, not 0x94.  So either the
record type is wrong or the stride is - either way those sites have the same near-pointer shape and are
worth their own pass: `grep '(stg_tmp_t \*)(row \* 0x94)' *.c`.

  grep_checks 40,067 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### Five dead in_* locals; segment 0x80 has no writer
remove five dead in_* register locals; segment 0x80 is read-only in static code (40,067 -> 40,064)

DEAD in_* LOCALS.  Ghidra declares e.g. `uint16_t in_AX;` for a register it could not attribute, and
sometimes never uses it.  `tmp/dead_inreg.py` finds declarations of `in_XX` with no other reference in the
same function body.  Five exist tree-wide, all removed (behaviour-neutral by construction):

  ovc02_draw.c    in_FS (205), in_GS (1641)
  ovc09_init.c    in_DX (1189)
  ovc15_sprite.c  in_DX (184)
  ovc48_assets2.c in_DX (1902)

in_REG 838 -> 835.  (crtl.c and ovl.c are excluded as CRT/overlay.)

SEGMENT 0x80 IS READ-ONLY.  `mov ax,0x80 / mov es,ax` occurs exactly three times in the whole image, and
all three sites only READ the table:

  0x35420  (in a function that reads es:[bx-2] and es:[bx-4])
  0x573da  es:[bx] / es:[bx+2]  null test
  0x5741d  es:[bx] / es:[bx+2]  -> the stats_usesAlignUp42 read

There is no writer anywhere in static code.  So the array cannot be sized by reading the loop that fills
it - it is populated at runtime (BSS, or a loader copy of an unknown segment), which means nClasses is not
derivable from the image and declaring `far_t far far X[nClasses][37]` would invent it.

Also note the two index conventions in use: 0x573da/0x5741d reach `classId*0x94 + level*4` and read at
+0 and +2, while 0x35420 reaches the same table and reads at -2 and -4.  That is consistent with two
different base pointers into one table, and is worth keeping in mind when the array is finally named.

  grep_checks 40,067 -> 40,064; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### 83 near table reads are GLeaderSheets (40,064 -> 40,045)
ovc22_classes: 83 near table reads are GLeaderSheets; rename seasonalIncome (40,064 -> 40,045)

THE TABLE.  `ovc22_usesRandBelow` (5087:4576) turned out to contain the same near-table defect already
fixed in ovc22_usesLUDIV_at_, repeated: 83 sites of

  *(uint32_t *)((uint)partyIndex << 2)

i.e. a reading of DS offset partyIndex*4 where the original reads a far-pointer array.  The function's
own disassembly proves which array:

  014D  mov bx, 0x70 / mov es, bx        ; segment 0x70 = GLeaderSheets
  0018  mov bx,ax / mov es,dx / les bx, ptr es:[bx]

and the same expression at line 4429 already reads `(GLeaderSheets[partyIndex])->flags5d` correctly, two
lines before the first broken one.

All 83 sites in ovc22_classes.c became `(uint32_t)GLeaderSheets[partyIndex]`.  Verified in the emitted
listing for ovc22_usesRandBelow:

  mov  al,byte ptr [bp+6] / mov ah,0 / shl ax,2 / mov bx,ax
  les  bx,dword ptr DGROUP:_GLeaderSheets[bx]
  test byte ptr es:[bx+93],2            ; 0x5d = flags5d

20 references to the symbol in that function.

WHAT THIS DOES NOT FIX: the surrounding `(int)` truncations (`(int)*(uint32_t *)...` then
`*(int *)(iVar4 + 0x56)`) still drop the segment, so those reads remain DS-relative.  The table base is
now right, which is a strict improvement, but the per-field far reads in this function are a separate
pass.

RENAME.  ovc22_seasonalIncome had exactly one exported temporary, `uVar1` (18 occurrences), which is the
function's accumulated return value - it is the income figure at every use.  Renamed to `income`.

STILL OUTSTANDING, same shape, verified by count only (not yet by disassembly):
  ovc15_sprite.c 1, ovc21_manage.c 1, ovc23_bldrec.c 2, ovc25_intel.c 10, ovc28_ui.c 2,
  ovc35_bldng.c 2, ovc37_season.c 1, ovc39_archive.c 24, ovc45_unitinfo.c 7
  -> still `*(uint32_t *)((uint)partyIndex << 2)`.  Each module needs the same 0x70 check before the
     sweep; ovc39_archive.c (24) is the next largest.

  grep_checks 40,064 -> 40,045; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### 91 GLeaderSheets field reads become far
ovc22_classes/ovc25_intel/ovc39_archive: 91 GLeaderSheets field reads become far

Continued the near-table sweep.  A source-level check (`tmp/check70b.py`) grouped the remaining 49
`*(uint32_t *)((uint)partyIndex << 2)` sites by function and found that 36 of them sit in functions which
ALREADY use `GLeaderSheets[...]`, so the table needs no disassembly to confirm:

  ovc39_archive.c  ovc39_textHalflingCastle   24   (uses GLeaderSheets)
  ovc25_intel.c    ovc25_intelAttackingNotice  6   (uses GLeaderSheets)
  ovc25_intel.c    ovc25_attackingNotice       4   (uses GLeaderSheets)
  ovc23_bldrec.c   ovc23_usesGRecordCount3     2   (uses GLeaderSheets)

Those 36 were swept (36 sites, three files).  Then the field dereferences were fixed too, because fixing
only the base leaves the read DS-relative:

  before   *(char *)((int)(uint32_t)GLeaderSheets[partyIndex] + 0x3f)
  after    *((char far *)GLeaderSheets[partyIndex] + 0x3f)

77 sites in ovc22_classes.c were converted this way (the earlier 83-site base sweep had already fixed the
base there, so its remaining truncations were the field reads).

Verified in ovc22_usesRandBelow:

  mov  al,byte ptr [bp+6] / mov ah,0 / shl ax,2 / mov bx,ax
  les  bx,dword ptr DGROUP:_GLeaderSheets[bx]
  test byte ptr es:[bx+93],2            ; 0x5d = flags5d, now through ES

`les` sites in that function went 0 -> 6 and `es:[bx+93]` appears 3 times, where before the field reads
were `cmp byte ptr [bx+63],0` with no segment at all.

NOT DONE, and deliberately: the 13 sites in functions that do NOT mention GLeaderSheets
(ovc45_unitinfo.c 7, ovc28_ui.c 2, ovc35_bldng.c 2, ovc21_manage.c 1, ovc37_season.c 1).  Each needs the
`mov es,0x70` check against its own disassembly first; the source-level grouping cannot settle it.

  grep_checks 40,045 (unchanged - `*(uint32_t *)` and `(int)(uint32_t)` are not section-5 patterns)
  build 65/65 clean; LINK.LOG 65 bytes / 0 problems; compare_state 1,627/0/0
  diff_dgroup 1,444/1,868; compare_runtime 1,545/12 main entry

### GLeaderSheets sweep finished: 14 more near tables
finish the GLeaderSheets sweep: 14 more near tables fixed in six modules

The 13 remaining `*(uint32_t *)((uint)partyIndex << 2)` sites were confirmed against their disassembly
before conversion.  Two of them, in full because they are short:

  ovc45_compute3 (77eb:09c1)          bldng_getClass (676c:0000)
    000B shl ax,2                       000A shl ax,2
    000E mov dx,0x70                    000D mov dx,0x70
    0011 mov bx,ax                      0010 mov bx,ax
    0013 mov es,dx                      0012 mov es,dx
    0015 les bx,ptr es:[bx]             0014 les bx,ptr es:[bx]
    001A mov ax,es:[bx+0x58]            0019 cmp byte ptr es:[bx+0x2f],0xff
    001E mov dx,es:[bx+0x56]            0037 mov al,es:[bx+0x2f]

i.e. the same `mov dx,0x70 / mov es,dx / les` chain as GLeaderSheets, with the field offsets
(0x56/0x58, 0x2f) that char_sheet_t defines.  `manage_usesGLeaderCount3` (4d05:1b51) likewise loads
0x70 into ES.

Converted, base and far field dereference both:

  ovc15_sprite.c    1 base, 1 deref
  ovc21_manage.c    1 base, 1 deref
  ovc28_ui.c        2 base, 0 deref
  ovc35_bldng.c     2 base, 1 deref
  ovc37_season.c    1 base, 1 deref
  ovc45_unitinfo.c  7 base, 0 deref

Verified in the emitted listing for ovc45_compute3:

  mov  al,byte ptr [bp+6] / mov ah,0 / shl ax,2 / mov bx,ax
  mov  ax,word ptr DGROUP:_GLeaderSheets[bx+2]
  ...

where the export previously read DS:partyIndex*4.

Two modules (ovc28_ui.c, ovc45_unitinfo.c) got the base fix but no field-deref conversion: their reads
use a different cast shape (`*(uint *)`), which the regex did not match.  The base is right; the field
reads remain DS-relative there and are a follow-up.

Still outstanding by the same grep: 34 lines tree-wide, but with index expressions other than
`partyIndex` (which is why they were not in this queue).

  grep_checks 40,045 (unchanged - these are not section-5 patterns)
  build 65/65 clean; LINK.LOG 65 bytes / 0 problems; compare_state 1,627/0/0
  diff_dgroup 1,444/1,868; compare_runtime 1,545/12 main entry

### Nine more GLeaderSheets sites (panelIdx, leaderIdx, partySlot)
nine more GLeaderSheets sites: panelIdx, leaderIdx and the partySlot expression

The 34 remaining `uint32_t *)(... << 2)` lines were grouped by index expression.  Twelve are party-slot
lookups in one of three spellings, and five of those files already use `GLeaderSheets` nearby:

  panelIdx     2  ovc13_panel.c      (line 310-312 already read (GLeaderSheets[panelIdx])->active/x/y)
  leaderIdx    6  ovc15_sprite.c 2, ovc21_manage.c 2, ovc24_entities.c 2
  partySlot    2  ovc14_attact.c 1, ovc16_saveui.c 1
                 *(uint32_t *)((uint)*(byte *)((int)&(peVar14->base).entity + 3) << 2)

Converted, base and far field dereference:

  ovc13_panel.c    2 base, 2 deref
  ovc15_sprite.c   2 base, 2 deref
  ovc21_manage.c   2 base, 1 deref
  ovc24_entities.c 2 base, 2 deref
  ovc14_attact.c   1 base, 0 deref        (the partySlot spelling)

ovc16_saveui.c's partySlot site was NOT touched: that file contains no reference to GLeaderSheets at all,
so the table there is not confirmed and would need its own disassembly check.

Result in ovc13_panel.c, where the surrounding lines make it self-evident:

  310  if ((GLeaderSheets[panelIdx])->active != '\0') {
  311    leaderX = (GLeaderSheets[panelIdx])->x;
  313    if ((((*((char far *)GLeaderSheets[panelIdx] + 0x3f) == '\0') ||

i.e. line 313 now reads the same sheet the two lines above it use, instead of DS offset panelIdx*4.

Not converted for lack of confirmation: `menuEnabled` (ovc14_attact.c 1) and `unitType`
(ovc13_panel.c 1) index different tables, and the ~500 remaining `uint32_t *)(` expressions in the tree
use other index expressions entirely - a much larger family than the party-slot one, and each needs its
own base identified.

  grep_checks 40,045 (unchanged - not section-5 patterns)
  build 65/65 clean; LINK.LOG 65 bytes / 0 problems; compare_state 1,627/0/0
  diff_dgroup 1,444/1,868; compare_runtime 1,545/12 main entry

### MEASURED: the 504 *(uint32_t *)(EXPR) sites, grouped
MEASURED: the 504 `*(uint32_t *)(EXPR)` sites group into 113 index expressions

`tmp/group_u32.py` extracts each `*(uint32_t *)(EXPR)` cast with balanced-paren matching and groups by the
inner expression, because one disassembly per EXPRESSION settles a whole group:

  distinct index expressions: 113, total sites: 504

  sites  expression                              files
  98     (int)uStack_16 << 2                     ovc22_classes.c
  38     ((uint)_backdropIndex & 0xff) << 2      ovc41_main.c
  34     (uint)partyIndex << 2                   ovc25_intel.c, ovc39_archive.c
  14     (partyIndex & 0xff) << 2                ovc23_bldrec.c
  13     unaff_BP + -10                          ovc27_combat.c
  11     leaderIdx << 2                          ovc25_intel.c
  10     (uint8_t *)&(uStack_6)                  ovc22_classes.c, ovc23_bldrec.c
  10     (uint)bVar16 << 2                       ovc22_classes.c
  10     (uint)bVar5 << 2                        ovc22_classes.c
  10     (uint)bStack_10 << 2                    ovc45_unitinfo.c
  10     (uint)bVar3 << 2                        ovc47_constrct.c
   9     leaderIdxB << 2                         ovc22_classes.c
   8     (uint)PartyCount * 4 + -4               ovc15_sprite.c, ovc18_leaderview.c
   8     (uint)charIndex << 2                    ovc21_manage.c

So the party-slot family is NOT finished: `(uint)partyIndex << 2` still has 34 sites in the two modules
already swept, and `(partyIndex & 0xff) << 2` adds 14 more in ovc23_bldrec.c.  The earlier exact-string
replace matched only the spelling I had before me; these are different spellings of the same read.

`(int)uStack_16 << 2` (98 sites, ovc22_classes.c) is the same table: line 1036 of that file already casts
it to `char_sheet_t *`, and lines 1966/1967/1970/1971 do the same via
`((char_sheet_t *)(((int)uStack_16 << 2)))->{active,foodSold,foodProd,population}` - i.e. `uStack_16` is a
party slot and the table is GLeaderSheets.

ATTEMPTED AND REVERTED.  Sweeping all 98 `uStack_16` sites plus 30 far field-dereferences compiled to 28
errors ("Nonportable pointer conversion"), because the same file also contains the near-pointer form
`(char_sheet_t *)(((int)uStack_16 << 2))` which my regexes did not rewrite - so the file is left in a
mixed state where some reads are far and its siblings are still near casts of an int.  Those two forms
have to be converted together, which is more than one mechanical pass; reverted to HEAD, tree green.

  grep_checks 40,045 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### DIAGNOSED: the 129 uStack_16 sites are a dual-role temporary
DIAGNOSED: the 129 uStack_16 sites are one mis-typed loop counter, not a table problem

Third attempt on this group, and the cause is finally identified precisely.  In ovc22_classes.c:

  539   far_t far *uStack_16;                 /* declaration - in the file's first merged function */
  630   uStack_16 =(uint16_t)( (far_t far *)ovr_alignUp4(units[(int)puVar49].x,0,0));
  639   [(int)uStack_16 + (uStack_1a & 0xff) + 0x92] & 0x3000U);
  ...
  1964  for (uStack_16 = (far_t far *)0x0; (int)uStack_16 < (int)(uint)GLeaderCount;
  1965      uStack_16 = (far_t far *)((int)uStack_16 + 1)) {
  1966    if ((GLeaderSheets[uStack_16])->active != '\0') {

So `uStack_16` is a DUAL-ROLE temporary in one merged function: at 630-648 it holds a computed pointer,
and at 1964-1972 it is an integer loop counter over GLeaderCount.  The 129 `uStack_16` sites are therefore
not one table lookup with a bad base - they are two different variables that Ghidra merged under one name.

That is why the sweep failed three times:

* attempt 1 replaced only `*(uint32_t *)((int)uStack_16 << 2)` and left the 31 near casts
  `(char_sheet_t *)(((int)uStack_16 << 2))` -> 28 "Nonportable pointer conversion" errors;
* attempt 2 added those 31 and still failed, because the remaining near casts of the same pointer were
  then invalid;
* attempt 3 (this turn) replaced all 129 in one pass and failed for the same reason: `GLeaderSheets[x]`
  demands an integer, and `uStack_16` is declared a far pointer.

The correct fix is therefore a *split*, exactly like the dual-role locals handled in land_info:

  1. declare a new integer loop variable (say `leaderSlot`) and use it at 1964-1972;
  2. leave `uStack_16` as the pointer it is at 630-648;
  3. then the 129 sites in the loop become `GLeaderSheets[leaderSlot]` with far field reads.

Reverted to HEAD; tree green.  Recorded so the next attempt starts from the split rather than repeating
the sweep.

  grep_checks 40,045 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### MEASURED: uStack_16 has four roles
MEASURED: uStack_16 has FOUR roles in one merged function; splitting it is not mechanical

The split attempt (retype `uStack_16` to int, fix its 3 non-loop uses) got the error count from 28 to 8
and then stopped, because the name is used in four distinct ways inside the single merged function
`ovc22_textRingProt` (which spans roughly lines 500-2900 of ovc22_classes.c):

  539   far_t far *uStack_16;                       declaration
  630   uStack_16 = (uint16_t)((far_t far *)ovr_alignUp4(...));   integer (cast through a pointer)
  639   [(int)uStack_16 + (uStack_1a & 0xff) + 0x92]              integer index into GMapFlags
  648   same                                                       integer index
  1964  for (uStack_16 = (far_t far *)0x0; ... < GLeaderCount;     integer LOOP COUNTER
         uStack_16 = (far_t far *)((int)uStack_16 + 1))
  1966  (GLeaderSheets[uStack_16])->active                        integer index into GLeaderSheets
  2442  uStack_16 = (far_t far *)((int)uStack_16 + 1)             pointer increment
  2658  uStack_16[-1].seg                                         POINTER CURSOR into a far_t array

So it is not one mis-typed variable: it is at least three (an integer index, an integer loop counter, and
a far_t cursor), all emitted under one name by the decompiler because they occupy the same stack slot in
different scopes of the merged body.  Retyping it as int fixed the 639/648/1964 uses and broke 2442/2658;
the reverse would break the others.

That is why four attempts have failed.  Splitting it correctly means, per region:
  * give 630/639/648 their own integer local,
  * give 1964-1972 its own integer loop variable,
  * leave 2442/2658 as the far_t cursor,
and each region has to be read against its own disassembly because the merged function's scopes are not
visible in the C.  That is a multi-turn job on one function, not a sweep, and I am not going to guess at
which regions belong together.

Reverted; tree green.  The uStack_16 group (129 sites) is therefore parked with this diagnosis rather
than attempted again blind.

  grep_checks 40,045 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### ovc25_intel: 18 table reads + 12 far derefs
ovc25_intel: 18 leaderIdx/partyIndex table reads and 12 far dereferences fixed

Moved off ovc22_classes.c (whose merged body reuses one temporary name for four variables) to a small,
unmerged module, and applied the two-step that has worked: check the index's declaration, then sweep.

  ovc25_intel.c:  uint idx;  uint leaderIdx;      <- both integers, so indexing an array of far
                                                    pointers is well-typed

18 sites converted:

  *(uint32_t *)((leaderIdx << 2))   ->  (uint32_t)GLeaderSheets[leaderIdx]
  *(uint32_t *)(leaderIdx << 2)     ->  (uint32_t)GLeaderSheets[leaderIdx]
  ... same for partyIndex and idx

plus 12 far field dereferences:

  *(char *)((int)(uint32_t)GLeaderSheets[leaderIdx] + 0x3f)
     ->  *((char far *)GLeaderSheets[leaderIdx] + 0x3f)

which is the same shape already verified in ovc22_usesRandBelow (les + es:[bx+93]) and in ovc13_panel.c.

The remaining `*(uint32_t *)(leaderIdx << 2)` forms in ovc39_archive.c and ovc23_bldrec.c were NOT swept:
ovc23_bldrec.c's occurrences now use `uStack_a` (2 sites) and ovc39_archive.c has none left in this
spelling, so there is nothing of this shape there to convert.

  grep_checks 40,045 (unchanged - not section-5 patterns)
  build 65/65 clean; LINK.LOG 65 bytes / 0 problems; compare_state 1,627/0/0
  diff_dgroup 1,444/1,868; compare_runtime 1,545/12 main entry

### MEASURED: the _backdropIndex group is DGROUP-relative
MEASURED: the `_backdropIndex` group is DGROUP-relative, not a separate segment

Checked the enclosing function of the 38 `((uint)_backdropIndex & 0xff) << 2` sites in ovc41_main.c
(6a8f:15a0, 201 instructions).  Every `mov es,` in it is `mov ax,0x280 / mov es,ax` - DGROUP - and there
is no `mov dx,0x70` / `les ... es:[bx]` far-array chain anywhere:

  0009  b8 80 02   mov ax, 0x280
  000C  8e c0      mov es, ax
  000E  26 ff 36 03 8a push word ptr es:[0x8a03]     ; a DGROUP global
  0020  80 7e 08 00 cmp byte ptr [bp + 8], 0
  0029  8a 46 06   mov al, byte ptr [bp + 6]
  0030  83 fb 03   cmp bx, 3
  0038  d1 e3      shl bx, 1
  003A  2e ff a7 3f 18 jmp word ptr cs:[bx + 0x183f] ; jump table over the argument

So this group is NOT the GLeaderSheets class: the original reads a DGROUP table, which means the export's
`*(uint32_t *)(backdropIndex << 2)` is already in the right segment.  What it lacks is the array's base
symbol - the same situation as segment 0x80 and as `(char_sheet_t *)((int)i << 2)` in the uStack_16 group.

Converting it to a `far` array read would therefore be wrong: it would move a correct DGROUP access into a
symbol we do not have.  The honest state is that the base symbol must be identified first (which DGROUP
array of far pointers is indexed by `_backdropIndex`), and `_backdropIndex` itself is not even declared in
the tree's headers - it only appears as a use.

Consequence for the remaining queue: the `(uint)bStack_10`, `(uint)bVar3`, `(uint)bVar5`, `(uint)bVar16`
groups are each ~10 sites and each needs this same first question answered - "is the table in DGROUP or in
its own segment?" - before any conversion.  Only the latter needs a `far` rewrite; the former needs a base
symbol, which is data work rather than an addressing fix.

  grep_checks 40,045 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### ovc27_spellNotice rename, and a correction about the Stack_ patterns
ovc27_spellNotice: rename the agent pointer (32 uses); and a correction about the pattern

`paStack_6` is `(agnt_t far *)&Agnts[agntIndex].x` - the agent this notice is about - and it is a
single-role local used 32 times.  Renamed to `agnt`.  No name collision in the function (its only
parameter is `agntIndex`).

CORRECTION: I expected this to reduce a section-5 class and it does not.  The patterns are
`p[iusc]Stack_` and `[iusc]Stack_`, i.e. `p` followed by one of i/u/s/c, or one of i/u/s/c followed by
`Stack_`.  `paStack_6` is `p`+`a`+`Stack_`, and `a` is in neither character class, so this name was never
counted.  grep_checks stayed at 40,045, which is the correct outcome and confirms the reading.

That also means the `paStack_*` / `pbStack_*` / `pcStack_*` family throughout the tree is NOT part of the
`Stack_` classes at all - only `p[iusc]Stack_*` (single character between `p` and `Stack_`) is.  Worth
knowing before treating those names as gate-bearing.

  grep_checks 40,045 (unchanged, as explained above); build 65/65 clean
  LINK.LOG 65 bytes / 0 problems; compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### ovc27_textTakesHalfDamage3: two renames (40,045 -> 40,000)
ovc27_textTakesHalfDamage3: rename two single-role locals (40,045 -> 40,000)

ovc27_textTakesHalfDamage3 (5ded:10ea, 163 lines, 129 section-5 matches, no in_stack_/unaff_ blockers)
carries two locals whose roles are unambiguous from their use:

  uVar8  = (uint16_t)((ulong)((long)agntIndex * 0x34) >> 0x10);
       -> the HIGH WORD of the agent record address, i.e. its segment.  It is paired with
          paStack_c (the low word) in every CONCAT13/CONCAT12 construction in the function.
       -> agntSeg                                                        (27 uses)

  uVar2  = (uint)roll;  ...  uVar2 = (int)uVar2 >> 1;
       -> the damage figure: assigned from the rolled dice (or from agnt->strength on the breath path)
          and halved when the half-damage roll succeeds.
       -> damage                                                          (18 uses)

Both names were checked for collision in the function first (its parameters are agnt/agntIndex/arg3/arg4
and no local is called agntSeg or damage).  Renaming only: no expression changed.

  grep_checks 40,045 -> 40,000; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

Remaining in this function: uVar9/uVar10/uVar11 (undefined1 temporaries, 7 uses each), uVar3 (the
half-damage roll result, 7), iVar5 (5), uVar4 (3).  The body is still structurally garbled around
`paStack_c = (agnt_t *)((long)agntIndex * 0x34)` - a near pointer built from an offset - and the
`CONCAT13((char)((uint)ptrSeg >> 8), CONCAT12((char)ptrSeg, paStack_c))` shuffles, so the rest needs a
re-derivation against the disassembly rather than more renaming.

### DECODED: ovc27_textTakesHalfDamage3's near/far confusion
DECODED: ovc27_textTakesHalfDamage3's near/far confusion, precisely

The prologue settles what `agntSeg` / `paStack_c` / `ptrSeg` are:

  0009  mov di, word ptr [bp + 0xa]        ; agntIndex (the 2nd parameter)
  000C  mov ax, di
  000E  mov dx, 0x34 / imul dx             ; agntIndex * sizeof(agnt_t)
  0013  add ax, 0
  0016  mov word ptr [bp - 8], 0x50        ; SEGMENT = Agnts' link-time segment literal
  001B  mov word ptr [bp - 0xa], ax        ; OFFSET  = agntIndex * 0x34
  001E  les bx, ptr [bp + 6]               ; the `agnt` parameter is a FAR pointer
  ...
  0045  push word ptr [bp - 8]             ; push the constructed far pointer
  0048  push word ptr [bp - 0xa]           ;   seg then ofs
  004B  push cs
  004C  call ovc27_spellHalfDamage

So `agntSeg` + `paStack_c` are the two halves of ONE far pointer: `&Agnts[agntIndex]`, whose segment the
original writes as the literal 0x50 (the Agnts link-time segment, like 0x70 for GLeaderSheets and 0x48 for
AudioHandles).  It should be:

  agnt_t far *agntRec = (agnt_t far *)MK_FP(SEG_OF(Agnts), (uint16_t)(agntIndex * 0x34));

and every `CONCAT13((char)((uint)ptrSeg >> 8),CONCAT12((char)ptrSeg,paStack_c))` (5 sites) is just
`agntRec`.  `ptrSeg` - initialised as `(char *)((int)&AgntAnms[0x75].halfWidth + 1)` - is a fabricated
segment value that never corresponded to anything; the disassembly never loads a segment from that
expression.  That is the same `CONCAT13`-loses-the-segment defect measured earlier in this session, now
with the correct target identified.

NOT ATTEMPTED THIS TURN: the rewrite touches 35 `paStack_c` uses, 27 `ptrSeg` uses and 30 `agntSeg` uses
in a 163-line function, and it has to be verified by call count plus es:[bx+N] offsets.  I did not have
the budget left to do that safely and check it, and shipping it unverified is the failure mode I have hit
three times already (the _fsetmem CONCAT22 attempt, the blanket agntG_t cast, the ovc20 stash revert).
The structure is now decoded; the edit is a full turn's work.

  grep_checks 40,000 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### ovc27_textTakesHalfDamage3: agntRec applied; call count exposes an incomplete body
ovc27_textTakesHalfDamage3: the five fabricated far pointers are now real - and the call count exposes a bigger problem

Applied the decoded structure in the contained part:

  agnt_t far *agntRec;
  ...
  /* 0016-001B: the original builds {seg: 0x50, ofs: agntIndex*0x34}. */
  agntRec = (agnt_t far *)MK_FP(SEG_OF(Agnts),(uint16_t)(agntIndex * 0x34));

and the five sites of

  (agnt_t far *)CONCAT13((char)((uint)ptrSeg >> 8),CONCAT12((char)ptrSeg,paStack_c))

became `agntRec`.  `ptrSeg` was `(char *)((int)&AgntAnms[0x75].halfWidth + 1)` - a fabricated segment the
original never loads; the disassembly writes 0x50 (Agnts' link-time segment) at [bp-8].

One call needed a cast: `ovc27_rollToHitEntity(uint32_t agnt, byte column)` takes a uint32_t, so that
site is `(uint32_t)agntRec`.

BUILD CLEAN, but the probe shows:

  instructions: 646
  call instructions: 51        (original 5ded:10ea: 104)

That gap is not explainable by compiler variance - it means our exported function contains roughly half
the calls the original makes.  So `ovc27_textTakesHalfDamage3` as it stands in the tree is NOT a faithful
rendering of the original body: a large part of it is missing or was folded into neighbours during the
export.  Renaming inside it further would be polishing an incomplete function.

That is a materially different conclusion from "the names are wrong", and it explains why this function
read as garbled: it is not merely mis-typed, it is incomplete.  The correct next step is to establish the
function's true extent and whether the missing calls sit in a neighbouring exported function (the file has
several `ovc27_text*` entries) - a boundary problem, not a naming one.

  grep_checks 40,000 (unchanged - this is an addressing fix, not a naming one)
  build 65/65 clean; LINK.LOG 65 bytes / 0 problems; compare_state 1,627/0/0
  diff_dgroup 1,444/1,868; compare_runtime 1,545/12 main entry

### CORRECTION: ovc27_textTakesHalfDamage3 is complete
CORRECTION: ovc27_textTakesHalfDamage3 is COMPLETE; my "104 calls" was a bad extent

Last turn I reported that our C function emits 51 call instructions against the original's 104 and
concluded the exported body was missing about half its calls.  That conclusion was wrong, and the error
was mine.

audit/functions_real.tsv gives the function's real extent:

  5ded:10ea  ovc27_textTakesHalfDamage3  956 bytes
  signature summary: 0x148,0x2f*7; near*6; 0x160,0x25*4; 0x170,0x7a*4

Disassembling exactly 956 bytes:

  instructions: 345
  call instructions: 36
     lcall 0x140,0x2f  x2      lcall 0x140,0x48  x2
     lcall 0x148,0x2f  x7      lcall 0x160,0x25  x4
     lcall 0x170,0x5c  x1      lcall 0x170,0x7a  x4
     lcall 0x190,0x57  x2      lcall 0x230,0xa2  x2
     lcall 0x230,0xc5  x2      lcall 0xf8,0x39   x4
     near              x6

The "104" came from my early profiling script, which disassembled until the first `retf` in a large
window.  That `retf` is at +0xB00 - a NEIGHBOUR's - so it counted 997 instructions spanning several
functions.  The real function is 345 instructions with 36 calls.

So our function emits 51 calls where the original makes 36: MORE, not fewer.  That is the normal
direction for decompiled C (helpers the original inlined become explicit calls), and it means the body is
complete and this function IS finishable by editing - the opposite of what I recorded last turn.

The remaining work in it is therefore the ordinary kind: the 35 paStack_c / 27 ptrSeg / 30 agntSeg
references (of which the five far-pointer constructions and agntRec are already done) plus the remaining
uVar3/uVar4/iVar5/uVar9/uVar10/uVar11 renames.

Lesson, and it is the same one as three turns ago in a different guise: a "count mismatch" is only
evidence once the EXTENT is right.  I compared our function against a window that spanned four functions
and drew a structural conclusion from it.

  grep_checks 40,000 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### ovc27_textTakesHalfDamage3: paStack_c now far (28 refs)
ovc27_textTakesHalfDamage3: paStack_c was a NEAR copy of the agent record; now far (28 refs)

`paStack_c` was declared `agnt_t *` - a NEAR pointer - and initialised from the integer
`agntIndex * 0x34`:

  agnt_t far *paStack_c;
  paStack_c = (agnt_t *)((long)agntIndex * 0x34);

so every `paStack_c->field` read went to DS offset `agntIndex*0x34`, while the record lives in the Agnts
segment.  The prologue decodes as {seg: 0x50, ofs: agntIndex*0x34} (0016/001B), and last commit's
`agntRec` already carries exactly that:

  agntRec = (agnt_t far *)MK_FP(SEG_OF(Agnts),(uint16_t)(agntIndex * 0x34));

All 28 remaining `paStack_c` references became `agntRec` and the near declaration/assignment are gone.
That fixes, among others:

  paStack_c->gdata / ->state / ->flags / ->faction
  ovc27_breathHalfDamage(paStack_c,...)         now passes the far record
  ovc27_rollToHitEntity((uint32_t)MK_FP(SEG_OF(Agnts), paStack_c), 3)
                                                MK_FP's offset argument is the record's offset either way

Verified in the emitted listing (extent 956 bytes / 36 calls from audit/functions_real.tsv - see last
turn's correction; the earlier "104" was a window that spanned four functions):

  instructions:      639   (original 345 - the usual C-vs-hand-assembly overhead)
  call instructions:  50   (original 36 - extra because helpers the original inlined become calls)
  les sites:          17   (was 13 before this change: the record's field reads are far now)
  seg _Agnts refs:     2

  grep_checks 40,000 (unchanged - `paStack_c` is not a section-5 pattern: the classes are
  `p[iusc]Stack_` with one of i/u/s/c, and this name has `a` there)
  build 65/65 clean; LINK.LOG 65 bytes / 0 problems; compare_state 1,627/0/0
  diff_dgroup 1,444/1,868; compare_runtime 1,545/12 main entry

### ovc27_textTakesHalfDamage3: six renames (40,000 -> 39,962)
ovc27_textTakesHalfDamage3: name the six remaining temporaries (40,000 -> 39,962)

Each of the six had a single role visible from its assignment:

  uVar3  = ovc27_spellHalfDamage(...) / ovc27_breathHalfDamage(...)   -> halfRoll   (9)
  uVar4  = ovr_randBelow(3,0)                                          -> randRoll   (3)
  iVar5  = ovc27_rollToHitEntity(...)                                  -> hitRoll    (5)
  uVar9  = SUB21(pcVar6,0)                                             -> ptrLo      (9)
  uVar10 = (undefined1)agntSeg                                         -> segLo      (7)
  uVar11 = (undefined1)GSavedBlitSeg                                   -> blitSegLo  (7)

38 occurrences.  Names checked for collision in the function first.  Renaming only.

Emitted shape is unchanged by a rename, and re-measured to confirm nothing drifted:

  instructions: 639   calls: 50   les: 17      (original extent 956 bytes / 345 instrs / 36 calls)

Not done, and why:

* `agntSeg` = `(uint16_t)((ulong)((long)agntIndex * 0x34) >> 0x10)` is provably always 0, and `ptrSeg` =
  `(char *)((int)&AgntAnms[0x75].halfWidth + 1)` is a fabricated pointer.  Deleting them means rewriting
  the argument lists they feed - `ovr_agnt_statusText`, `ovr_ovc15_usesStshRealloc`, `ovr_uiNotify` - and
  the fact that `segLo` is literally `(undefined1)agntSeg` (i.e. a byte of a value that is always 0) shows
  those argument lists are split far pointers the export never reconstructed.  Rebuilding them requires
  the .ASM push sequences for three variadic calls, which is a separate pass, not a rename.

  grep_checks 40,000 -> 39,962; build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### DECODED: the variadic argument lists in ovc27_textTakesHalfDamage3
DECODED: the variadic argument lists in ovc27_textTakesHalfDamage3

Read the push sequences for `lcall 0x148,0x2f` (ovc27_agnt_statusText) inside the 956-byte extent:

  00A4  16          push ss
  00A5  8d 86 2e ff lea  ax,[bp - 0xd2]
  00A9  50          push ax
  00AA  ff 76 f8    push word ptr [bp - 8]      ; agntRec.seg
  00AD  ff 76 f6    push word ptr [bp - 0xa]    ; agntRec.ofs
  00B0  9a 2f 00 48 01 lcall 0x148, 0x2f
  preceded by: 26 ff 36 f7 8f  push word ptr es:[0x8ff7]

  0201  ff 76 f8    push word ptr [bp - 8]
  0204  ff 76 f6    push word ptr [bp - 0xa]
  0207  9a 2f 00 48 01 lcall 0x148, 0x2f
  preceded by: push dx / push ax  (a returned far pointer), push ss / lea ax,[bp-0xd2] / push ax

cdecl pushes right-to-left, so the parameters are:

  arg1 = [bp-8]/[bp-0xa]  = agntRec            (far agent)
  arg2 = ss:[bp-0xd2] or the returned far ptr  (far TEXT BUFFER, built as MK_FP(_SS, &text))
  arg3 = es:[0x8ff7]                           (a single WORD - this is GSavedBlitSeg; 0x8ff7 sits
                                                just below AgntCount at 0x8ffe in DGROUP)

So the real signature is `agnt_statusText(agnt_t far *agnt, char far *buf, uint16_t blitSeg)` and the
export's

  ovr_agnt_statusText(agntRec,(char *)CONCAT13((char)((uint)&text2 >> 8),
                                               CONCAT12((char)&text2,ptrSeg)),0)

is wrong in two ways: the second argument is a far pointer built from `(char *)&text2` and the fabricated
`ptrSeg` instead of `MK_FP(_SS,&text2)`, and the third is the literal `0` instead of `GSavedBlitSeg`.
That also explains `blitSegLo = (undefined1)GSavedBlitSeg` and `segLo = (undefined1)agntSeg` - the export
split the same values in some places and passed them whole in others.

The same reading has to be done for `lcall 0x140,0x2f` and `lcall 0x140,0x48` (seven and two sites), and
then the seven `agnt_statusText` sites each need their own buffer (`[bp-0xd2]` vs `[bp-0x122]` vs a
returned far pointer) - which is why this is a pass rather than a substitution.

NOT APPLIED: I had budget to decode but not to rewrite seven call sites, re-verify the emitted call count
and offsets, and run the five gates. Recording it so the next attempt starts from the signature rather
than re-deriving it.

  grep_checks 39,962 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### ovc27_textTakesHalfDamage3: seven statusText argument lists fixed
ovc27_textTakesHalfDamage3: the seven agnt_statusText argument lists are correct now

Applied the decoded signature.  The original at 5ded:10ea pushes, right-to-left:

  26 ff 36 f7 8f   push word ptr es:[0x8ff7]     ; GSavedBlitSeg  -> arg3
  16               push ss
  8d 86 2e ff      lea  ax,[bp - 0xd2]           ; far text buffer -> arg2
  50               push ax
  ff 76 f8         push word ptr [bp - 8]        ; agntRec.seg    -> arg1
  ff 76 f6         push word ptr [bp - 0xa]      ; agntRec.ofs
  9a 2f 00 48 01   lcall 0x148, 0x2f

so it is `agnt_statusText(agnt_t far *agnt, char far *buf, uint16_t blitSeg)`.  The export had arg2 as a
hand-built far pointer over the fabricated `ptrSeg` and arg3 as the literal 0.

Rewritten (4 argument expressions + 5 third arguments, at all 7 sites):

  (char *)CONCAT13((char)((uint)&textN >> 8),CONCAT12((char)&textN,ptrSeg))
  (char *)CONCAT22(&textN,ptrSeg)
      ->  (char far *)MK_FP(_SS,&textN)
  ...,0)  ->  ...,(uint16_t)GSavedBlitSeg)

Verified in the emitted listing - the rebuilt call now has the original's shape:

  push  word ptr DGROUP:_GSavedBlitSeg
  lea   ax,word ptr [bp-19]
  push  ss
  push  ax
  push  word ptr [bp-22]
  push  word ptr [bp-24]
  call  far ptr _ovr_agnt_statusText

  instructions 623  calls 50  les 17  _GSavedBlitSeg refs 9   (extent: 345 / 36)

NOT done: `agntSeg` and `ptrSeg` still exist because they also feed `lcall 0x140,0x2f` (7 sites) and
`lcall 0x140,0x48` (2), which I have not decoded; those remain `(char)agntSeg` / `(char)ptrSeg` in the
argument lists.  Deleting them now would break the build.

  grep_checks 39,962 (unchanged - this is an argument-list fix, not a naming one)
  build 65/65 clean; LINK.LOG 65 bytes / 0 problems; compare_state 1,627/0/0
  diff_dgroup 1,444/1,868; compare_runtime 1,545/12 main entry

### ovc27_textTakesHalfDamage3: the last two call shapes decoded
ovc27_textTakesHalfDamage3: the last two call sites decoded - panFromX takes one pointer, play_sfxU three words

Decoded both remaining call shapes from 5ded:10ea:

  lcall 0x140,0x48   (2 sites)

    025B  ff 76 f8      push word ptr [bp - 8]     ; agntRec.seg
    025E  ff 76 f6      push word ptr [bp - 0xa]   ; agntRec.ofs
    0261  9a 48 00 40 01 lcall 0x140, 0x48
    0266  83 c4 04      add sp, 4

    Four bytes pushed and four popped = ONE far-pointer argument.  The export had
    `ovr_audio_panFromX(agntRec,(char)ptrSeg)` - an invented second argument, whose only purpose was to
    consume the fabricated `ptrSeg`.

  lcall 0x140,0x2f   (2 sites)

    0269  50        push ax                     ; the result of the call above
    026A  6a 00     push 0
    026C  6a 1b     push 0x1b
    026E  9a 2f 00 40 01 lcall 0x140, 0x2f
    0273  83 c4 06  add sp, 6

    Three words = `play_sfxU(0x1b, 0, <pan>)`.  The export had five arguments,
    `ovr_play_sfxU(0x1b,0,agntSeg,0,(char)agntSeg)`, again padded with fabricated values.

Now:

  agntSeg = ovr_audio_panFromX(agntRec);
  ovr_play_sfxU(0x1b,0,agntSeg);

Verified in the emitted listing - identical to the original's shape:

  add  sp,4
  mov  word ptr [bp-14],ax
  push ax
  push 0
  push 27
  call far ptr _ovr_play_sfxU

  instructions 609 (was 623)  calls 50  les 17        (extent: 345 / 36 / -)

`agntSeg` and `ptrSeg` still cannot be deleted: `ptrSeg` survives in the `usesStshRealloc` argument lists
and `agntSeg` in `usesStshRealloc` / `uiNotify` / `stsprintf` - the `lcall 0x160,0x25` (x4) and
`lcall 0x170,0x7a` (x4) sites, which are the next thing to decode.

  grep_checks 39,962 (unchanged - argument lists, not names)
  build 65/65 clean; LINK.LOG 65 bytes / 0 problems; compare_state 1,627/0/0
  diff_dgroup 1,444/1,868; compare_runtime 1,545/12 main entry

### DECODED: the last two call shapes in ovc27_textTakesHalfDamage3
DECODED: the last two call shapes in ovc27_textTakesHalfDamage3

  lcall 0x160,0x25   (4 sites)

    00B0  9a 2f 00 48 01 lcall 0x148, 0x2f   ; ovr_agnt_statusText
    00B5  83 c4 08      add sp, 8
    00B8  52            push dx               ; the far result's segment
    00B9  50            push ax               ; ... and offset
    00BA  9a 25 00 60 01 lcall 0x160, 0x25
    00BF  83 c4 04      add sp, 4

    Four bytes in, four out = ONE far-pointer argument, namely whatever `agnt_statusText` returned in
    DX:AX.  So `agnt_statusText` returns a `char far *`, and the export's `char *pcVar6` truncates it -
    which is why `(char)agntSeg` had to be invented as a second argument.

  lcall 0x170,0x7a   (4 sites)

    00C4  1e          push ds
    00C5  68 0a 5c    push 0x5c0a           ; a DGROUP string constant, DS:0x5c0a
    00C8  16          push ss
    00C9  8d 86 7e ff lea  ax,[bp - 0x82]   ; the output buffer, SS:[bp-0x82]
    00CD  50          push ax
    00CE  9a 7a 00 70 01 lcall 0x170, 0x7a
    00D3  83 c4 0c    add sp, 0xc           ; 12 bytes = 6 words

    Three far-pointer arguments: `stsprintf(MK_FP(_SS,&buf), MK_FP(_DS,0x5c0a), <far vararg>)`, the
    vararg being the far pointer pushed at 00C2/00C3.  The export's

      ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x5ba4,_SS),
                    (char *)CONCAT22(bufPtr,(char *)0x26510),agntSeg)

    has the buffer and format in the wrong order and pads the tail with the fabricated `agntSeg`.

Together with the four shapes decoded in earlier turns, that accounts for every `agntSeg` / `ptrSeg` use:
each was invented to fill out an argument list for a call whose return value the export had truncated to a
near pointer.

WHY NOT APPLIED: the fix is not a substitution.  It requires retyping three locals to far pointers -
`pcVar6` (char far *), `bufPtr` (char far *), `msg` - and rewriting three argument lists at 4 sites each,
then re-verifying the emitted call count and offsets.  With a small budget left I would be shipping an
unverified type change across four call sites, which is exactly the kind of edit that has had to be
reverted three times this session.  The shape is now fully known, so the next pass is mechanical.

  grep_checks 39,962 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### BLOCKER: agnt_statusText must return char far * (52 call sites)
BLOCKER: finishing ovc27_textTakesHalfDamage3 needs a prototype change with 52 call sites

Applying the decoded shapes requires `pcVar6` to hold a FAR pointer, because `lcall 0x160,0x25` pushes
four bytes - the whole DX:AX return of `ovc27_agnt_statusText`:

  00B0  9a 2f 00 48 01 lcall 0x148, 0x2f     ; ovr_agnt_statusText
  00B5  83 c4 08      add sp, 8
  00B8  52            push dx                ; segment
  00B9  50            push ax                ; offset

but the tree declares it near:

  char * __cdecl16far agnt_statusText(agnt_t far *agnt,char *text,uint16_t arg3);
  undefined ovr_agnt_statusText();

and it is called from 52 places across src/decompiled.  So:

  char far *pcVar6;  ... = ovr_agnt_statusText(...)

does not compile without either changing the prototype (and every caller's expectations) or casting at
each site.  Changing the prototype is the correct fix - the callee demonstrably returns DX:AX - but it is
a cross-cutting change: 52 call sites, most of which assign the result to `char *` locals and pass it on
to other functions, so each needs checking for its own downstream truncation.

That is why the three remaining temporaries (`agntSeg`, `ptrSeg` and, for the same reason, the fabricated
`0x26510` in the CONCAT22) cannot be deleted yet: they exist to reconstruct the segment that the near
prototype discards.

What this turn established, concretely:

  lcall 0x160,0x25 -> usesStshRealloc(far statusText-result)          one far argument
  lcall 0x170,0x7a -> stsprintf(MK_FP(_SS,&msg), MK_FP(_DS,0x5c0a), far-result)
                                                                      three far arguments
  and therefore: agnt_statusText RETURNS A FAR POINTER, contrary to its declaration.

The next step is a prototype change plus its 52 call sites, done as one deliberate pass with the build and
gates run at the end - not a per-function edit.

  grep_checks 39,962 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### agnt_statusText returns char far * - prototype fixed
agnt_statusText returns char far * - prototype fixed, and the far result now survives

The overlay thunk was the real problem.  `lcall 0x160,0x25` pushes DX:AX (the whole return of
`ovr_agnt_statusText`), but the tree declared

  undefined ovr_agnt_statusText();
  char * __cdecl16far agnt_statusText(agnt_t far *agnt,char *text,uint16_t arg3);

Both were unprototyped/near, so the compiler kept only AX and every caller rebuilt the segment by hand -
which is what `agntSeg`, `ptrSeg` and the `CONCAT22(...,0x26510)` tails were for.

Changed:

  st_functions.h   char far * __cdecl16far agnt_statusText(...)
  st_functions.h   char far * ovr_agnt_statusText();
  ovc12_agnt.c     char far * __cdecl16far agnt_statusText(...)     (the definition)

All 52 call sites still compile: Turbo C accepts a far-to-near assignment as a nonportable conversion, so
the change is additive - callers that want the segment now get it, callers that truncate still do.

Then in ovc27_textTakesHalfDamage3:

  char *pcVar6          -> char far *pcVar6
  uint8_t *bufPtr       -> uint8_t far *bufPtr
  ovr_ovc15_usesStshRealloc(pcVar6,(char)agntSeg,ptrLo,0,0,0,0,0)          -> (pcVar6)   x1
  ovr_ovc15_usesStshRealloc(pcVar6,agntSeg,ptrLo,segLo,blitSegLo,0,0,0)    -> (pcVar6)   x3
  one ovr_stsprintf(...) rebuilt as
    ovr_stsprintf((char far *)MK_FP(_SS,&msg),(char far *)MK_FP(_DS,0x5c44),bufPtr)

Verified in the emitted listing - the near truncation is gone:

  call  far ptr _ovr_agnt_statusText
  add   sp,10
  mov   word ptr [bp-12],dx          ; the SEGMENT the export used to invent
  mov   word ptr [bp-14],ax
  push  word ptr [bp-12]
  push  ax
  call  far ptr _ovr_ovc15_usesStshRealloc

against the original's `push dx / push ax / lcall 0x160,0x25`.  instructions 554 (was 609), calls 50,
les 17.

Still to do in this function: two of the three `stsprintf` sites have a different line layout and were not
matched by the regex, and `agntSeg`/`ptrSeg` remain (20 and 8 uses) feeding `ovr_uiNotify` and those two
`stsprintf` calls.

  grep_checks 39,962 (unchanged); build 65/65 clean; LINK.LOG 65 bytes / 0 problems
  compare_state 1,627/0/0; diff_dgroup 1,444/1,868
  compare_runtime 1,545/12 main entry

### ovc27_textTakesHalfDamage3: all four stsprintf sites correct
ovc27_textTakesHalfDamage3: all four stsprintf sites now have the original's argument shape

The two sites the earlier regex missed had a different line layout:

  pcVar6 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x5c2f,_SS),
                         (char *)CONCAT22(bufPtr,(char *)0x26510),agntSeg);

`CONCAT22(0x5c2f,_SS)` puts the offset in the HIGH word, i.e. it is segment 0x5c2f / offset _SS - the
argument is reversed as well as fabricated.  Both now read

  ovr_stsprintf((char far *)MK_FP(_SS,&msg),(char far *)MK_FP(_DS,0x5c2f),bufPtr);

(and 0x5c44 at the other site), matching the decoded `lcall 0x170,0x7a`:

  push dx / push ax            ; the far vararg (the usesStshRealloc result)
  push ds / push 0x5c0a        ; the format string in DGROUP
  push ss / lea ax,[bp-0x82] / push ax   ; the output buffer

Verified in the emitted listing for all four calls:

  push word ptr [bp-16]
  push ax
  xor  ax,ax / or ax,23562      ; 0x5c0a
  push ds
  push ax
  lea  ax,word ptr [bp-26]
  push ss
  push ax
  call far ptr _ovr_stsprintf

  instructions 560  calls 50  les 17

`agntSeg` and `ptrSeg` are now used only by `ovr_uiNotify`, whose push sequence has not been decoded (it is
one of `0x230,0xa2` / `0x230,0xc5` / `0x190,0x57` / `0xf8,0x39`); deleting them still needs that reading.

The `undefined ovr_*();` class turned out to be 459 declarations, so sweeping it needs a per-call
detector (push DX:AX before the lcall) rather than a blind prototype change - noted for the next pass.

  grep_checks 39,962 (unchanged - argument lists, not names)
  build 65/65 clean; LINK.LOG 65 bytes / 0 problems; compare_state 1,627/0/0
  diff_dgroup 1,444/1,868; compare_runtime 1,545/12 main entry
