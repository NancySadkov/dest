# Step 6: runtime DGROUP comparison at `main`

## How the state is captured

Both images are patched at `main`'s entry with an 18-byte stub:

```asm
mov bx,1 / mov cx,0FFFFh / mov dx,0 / mov ah,40h / int 21h / mov ax,4C00h / int 21h
```

i.e. "write all 64 KB at DS:0 to stdout and exit".  The batch redirects
`STRONG.EXE` to `DGR.BIN`, so the dump needs no file-creation call (an earlier
version that used `INT 21h AH=3Ch` hung: headless DOS raised its critical-error
dialog on the first bad path).

`tmp/dump_dgroup_stdout.py` patches both images and runs them;
`scripts/compare_runtime.py` maps each original DGROUP symbol (name + length
from `audit/dgroup_data.csv`) to its matching address in `REBUILT.MAP` (the same
matching rules as `diff_dgroup.py`) and compares the runtime bytes.

## Result

```
original dump: 61440 bytes, rebuilt dump: 65535 bytes
symbols matched: 976
identical state: 933
DIFFERENT state:  43
```

## The 43 differences classify into three groups

1. **Far pointers whose segment is the literal `0x2410`.**  Example:

   ```
   00eb GUnitDescriptions  want ...6901331c7101331c   got ...6901102471011024
   26d7 GYesNo             want 4a28331c4e28331c      got 4a2810244e281024
   ```

   The original's tables hold the load-time DGROUP segment (`0x1c33`); ours hold
   `0x2410`, the segment written in the original image file.  These initialisers
   are literals such as `(char far *)(0x24100000UL + 0x27ebUL)`, so the linker
   never relocates them - the static byte comparison passed because the *file*
   bytes match, and only the runtime state exposes the defect.

   Fix: declare those tables as `char far *` arrays initialised with the address
   of the string (`char far *GYesNo[2] = { s_yes, s_no };`), which makes BCC emit
   a normal relocation for the segment half.

2. **Startup state that legitimately differs per run**: `_StartTime` (system
   clock), `_brklvl` (heap break after the resize), `_DATA` (the CRT's own
   word).

3. A handful of remaining items still to classify (they are listed by the tool).

## Why this matters

This is the first *runtime* data-state comparison, and it shows a class of
defect the static comparison cannot see: data that is byte-identical in the file
but wrong in memory because it should have been relocated.

## First fixes and the improved comparison

`tmp/fix_far_literals.py` rewrote the ten `(char far *)(0x24100000UL + ofs)`
initialisers to `(char far *)&symbol[0]`, so the compiler now emits a real
relocation.  Verified in the runtime dump: `GMenuStrings` and `GYesNo` hold the
run's DGROUP segment (`0x1e51`) instead of the literal `0x2410`.

`scripts/compare_runtime.py` now normalises the two things that legitimately
differ between runs and layouts:

* the DGROUP segment of each run (read from `GYesNo[0].seg` in each dump);
* any word that is a symbol offset, mapped through the original-to-rebuilt
  symbol table (interior offsets included), compared word-aligned.

Result after the conversion:

```
symbols matched 976
identical        935   (2 of them only after normalisation)
DIFFERENT         41
```

The remaining 41 are dominated by tables still declared as `far_t` (not
`char far *`), e.g. `GUnitDescriptions` (`{ 0x169, 0x2410 }`), `GErrorStrings`,
`CPKeys`, `GSPEmpty`, `SaveHeader`, `worldMenuLabels`, `GStatsLabels`,
`GPlayerTitles`, `menuHighlightTable`, `PlaceErrPtrs`, `GAlignmentsNames`.  They
need a type change to `char far *` plus the users of `.ofs`/`.seg` updated
(`GUnitDescriptions` alone has users in `ovc02_draw.c` and `ovc06_blit.c`).

## Driving the runtime diff down: 43 -> 14

Two changes did most of the work:

* `scripts/compare_runtime.py` now keys symbols by their `_2410_XXXX` address
  suffix when present.  The export spells long names differently from the
  original (quotes, truncation), so name matching had only paired 976 symbols;
  the suffix pairing covers **1537**.  Pointer targets inside strings can then
  be mapped, which is what made `GErrorStrings` and friends comparable.
* `startx` patches the segment half of every remaining `far_t` table to this
  run's DGROUP (a struct field cannot hold a relocatable address).  Tables
  covered now: GUnitDescriptions, CPKeys, worldMenuLabels, GStatsLabels,
  GPlayerTitles, menuHighlightTable, GAlignmentsNames, ManageResultPtrs,
  LevelBandLabels, LevelRangeLabels, RampTables, GStrangeTable, GSeasonNames,
  RankMsgPtrs, CureSpellPtrs, PersonWordPtrs, GTxtFiles, StatsTabPtrs, and the
  embedded far pointers of `GStructures`, plus the scalars GSPEmpty,
  SaveHeader, GDoneStrPtr, msgFormat, far_t_2410_78e4.

Result:

```
matched 1537
identical 1523
different   14
29 of the identical ones match only after segment/offset normalisation
```

## The last 14

* **startup state**: `_DATA`, `_StartTime`, `_brklvl`, `brk_normalize_xsize`
  (the original sets 0xC000 at run time, the file has 0), `__setargv_SavedReturn`;
* **CRT / stdio state**: `_exitbuf`, `_exitfopen`, `_exitopen`, `_streams`,
  `_video` - the original sets these in `_c0crtinit`/`setvbuf`, which we still
  skip (setvbuf was disabled because its recovered body calls malloc/fseek);
* **comparator artefacts**: `s_kill_3`, `s_and_grow` are duplicate-name strings
  the pairing assigns to the wrong twin;
* **normalisation gap**: `PlaceErrPtrs`, `LevelRangeLabels` show the right
  segment but an offset the mapper still does not resolve.

## Second checkpoint attempt: after `ovr_init_game`

`tmp/checkpoint2.py` patches the `lcall ovr_run_demo` in `main` with the same
18-byte "write 64 KB of DS:0 to stdout and exit" stub used for the entry
checkpoint, so the captured state is what exists after initialisation and before
the first demo frame.

The call sites were derived from the resident code block, not from overlay
segment arithmetic:

```
original  1301:0061  -> file 0x4E71   bytes 9A 20 00 E3 13   (lcall 13e3:0020)
rebuilt   image 0x6544                bytes 9A 34 08 DE 06   (lcall 06de:0834)
```

Result of running both:

```
orig  DGR.BIN 0 bytes   STRONG.SAV created (1 byte)   DONE.FLG absent
ours  DGR.BIN 0 bytes   STRONG.SAV absent            DONE.FLG absent
```

Neither binary reaches the patched call, so no second-checkpoint DGROUP dump is
available yet.  Two observations:

* the original *does* run far enough during `ovr_init_game` to create
  `STRONG.SAV`, while the rebuild does not - the first concrete init-stage
  behavioural difference found;
* the rebuild's earlier probe work showed that file creation through
  `INT 21h AH=3Ch` hangs under the headless harness (critical-error dialog) for
  our image, so the missing save file may be the same environmental symptom
  rather than a logic difference.  Both hypotheses are testable: patch the
  1-byte creation out of the original and see whether it also stops, or trace
  the rebuild's open call.

So checkpoint 2 stays open.  The probe itself is kept in `tmp/checkpoint2.py`
for the next session.

### Tracing attempt: AH=02 markers are not captured

To find where the rebuild stops inside `ovr_init_game`, letters were printed with
`INT 21h AH=02` after each step of `init_game` (`_OvrInitExt`, `_OvrInitEm
s`,
`ovr_init_base`, `init_paths`, `init_cfg`, `clrscr`, `ovr_stshAlloc`,
`ovr_init_assets`) and at `main`'s first statement and after `ovr_init_game`.

Result: `OUT.BIN` stayed **0 bytes for the original as well**, although the
original still created `STRONG.SAV`.  So `AH=02` output is not captured by the
batch's `>` redirection in this harness - only an explicit
`AH=40h` write to **handle 1** (what the DGROUP dump stubs use) reaches the
file.

Consequences for the next attempt:

* any progress trace must use `mov bx,1 / mov ah,40h / int 21h` with the text in
  DS:DX, not `AH=02`;
* `tmp/checkpoint2.py`'s rebuilt-image offset (`0x7544`) is a hard-coded file
  offset and shifts whenever the build changes - it must be located by searching
  the image for `9A ?? ?? ?? ??` targeting `_OVR_RUN_DEMO`'s offset each run.

Both instrumented files were reverted; the tree is back at the committed state.
