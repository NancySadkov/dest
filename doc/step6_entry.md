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
