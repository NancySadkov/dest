# DeSt status and recovery plan

_Last updated: 2026-11-05_

## 1. What this project is

DeSt is a clean-room source recovery of **Stronghold** (1993, Stormfront Studios),
the 16-bit MS-DOS strategy game. The original executable, `STRONG.EXE`, was
built with Borland/Turbo C++ 3.0 in the **large** memory model, with Borland
VROOMM (`FBOV`/`INT 3Fh`) overlays.

The long-term goal is original-looking C that can be rebuilt with Turbo C++ 3.0.

## 2. Environment / tooling

| Tool | Location | Purpose |
|---|---|---|
| Ghidra 12.1.3 | `C:\soft\ghidra_12.1.3_PUBLIC` | static analysis + decompiler |
| Ghidra project | `gpr/` (`st.exe`) | analysed program |
| dosbox-x-mod.exe | `emulator/` | modded DOSBox-X with RE harness (TCP 127.0.0.1:23946) |
| TC++ 3.0 | `tools/TC30/` | target compiler (most likely the original) |
| BC++ 3.0 | `tools/BC30/` | reference runtime, TASM |
| mzap | `tools/mzap/` | FBOV → plain MZ, segment/overlay tables |
| ungrab | `tools/ungrab/` | recover assets from `STRONG.DAT` |
| devroomm docs | `tools/devroomm/doc/` | Borland overlay manager format |

`unfbov/st.exe` is the merged plain-MZ image loaded into Ghidra. The Ghidra
project already contains the DOS `int 21h` imaginary address space, FID-matched
Borland runtime functions, named MZ segments, and a substantial recovered type
library under `/st.h` (agent, entity, sprite, animation, building, stash, ...).

## 3. State at the start of this pass

* The executable and asset pipeline were in good shape.
* Ghidra project: **1590 functions**, 460 Borland overlay thunks, 1020 symbols
  with meaningful names, 2493 defined data items, 91 image segments.
* Only the early init code existed as C in `src/`:
  `main.c`, `init.c`, `util.c`, `misc.asm`, plus headers. Everything else was
  still only in Ghidra.
* README TODO: fix skyline palettes/frame rects/RLE, decompile the rest,
  beginning with the huge asset-init routines.

## 4. Work done in this pass

### 4.1 Pipeline

New, reproducible Ghidra headless scripts in `scripts/ghidra/`:

| Script | Purpose |
|---|---|
| `DumpStats.java` | inventory of blocks/functions/symbols |
| `Inventory.java` | dump data types, globals, prototypes |
| `SanitizeSymbols.java` | stable C-valid names for functions, thunks, globals |
| `ExportRecovered.java` | export all functions, grouped by source module |
| `ExportTypes.java` | export Ghidra's recovered types via `DataTypeWriter` |
| `ExportCpp.java` | whole-program single-file Ghidra C/C++ export |
| `ExportOne.java` | retry a single hard function with relaxed limits |
| `ExportAll.java` | earlier per-function exporter (kept for reference) |

`SanitizeSymbols` performed these project improvements:

* 570 unnamed game functions renamed from `FUN_ssss_oooo` to
  `<module>_ssss_oooo` (e.g. `draw_2e25_0d35`).
* 460 overlay thunks renamed to `ovr_<target>` (e.g.
  `ovr_draw_2e25_046b`), making overlay call sites self-describing.
* 130 globals sanitized (Borland `@` names and C/function collisions).

### 4.2 Recovered source tree

`src/decompiled/` now contains the whole program:

* **55 modules**, **1021 functions** (1020 decompiled successfully, 1 pending).
* One `.c` per original code segment/module, e.g. `ovc02_draw.c`,
  `ovc09_init.c`, `ovc33_stats.c`, `ovc44_strong_dat.c`.
* `st_types.h` — recovered structs/enums/typedefs, degraded to types that
  Turbo C++ 3.0 can parse (no 64-bit integers).
* `st_globals.h` / `st_globals.c` — global data declarations/definitions.
* `st_functions.h` — prototypes for all recovered functions and thunks.
* `st_compat.h` — Ghidra calling-convention/type/bit-operation shims.
* `st_artifacts.h` — declarations for Ghidra RAM/register pseudo-variables.
* `index.tsv` — address/name/size/status of every recovered function.
* `MODULES.md` — what each segment is, with string/function evidence.
* `MANIFEST.md` — module/function counts and failed decompilations.

`scripts/fix_recovered.py` post-processes the export: it rewrites invalid
namespace-qualified `switchD_...::caseD_*` names and generates
`st_artifacts.h`.

The tree is a **complete decompiler baseline**, not yet a rebuildable program:
it is intended to be refined module by module into compilable C.

### 4.3 Stubborn functions

Six functions defeated the default decompiler settings. All but one are now
recovered and integrated through `src/decompiled/hard/`:

| module | function | resolution |
|---|---|---|
| `ovc17_stash` | `stshRead` | reset variables/signature; stack args rewritten |
| `ovc21_manage` | `manage_4d05_1bee` | 256 MB payload / 2M-instruction limit |
| `ovc44_strong_dat` | `init_assets` | 1800 s timeout (28 KB function) |
| `ovc45` | `OVC45_77eb_0d61` | 256 MB payload / larger timeout |
| `ovc47_constrct` | `constrct_7e7c_0b9c` | 1800 s timeout (6 KB function) |
| `ovc23` | `OVC23_55fe_0000` | **still open** (see below) |

`OVC23_55fe_0000` fails with `Cannot marshal address space: NO ADDRESS`,
independently of the decompiler options. Its body contains far branches with
segment `0x5000`, i.e. linker-generated function references whose **offset**
part was never rebased. `mzap` explicitly leaves this case as
`FIXME: merge function reference reloc!!!` (the `FIXUP_FUNREF` path in
`tools/mzap/mzap.c`). The proper fix is to implement that relocation in mzap
and re-merge the executable; the source tree currently keeps a stub for this
one function.

## 5. Module map (recovered segment names)

Named by the original linker / prior analysis:

`crtl`, `main`, `mouse`, `video`, `ovl` (overlay manager), `ovc01_driver`,
`ovc02_draw`, `ovc03_font`, `ovc05_error`, `ovc06_blit`, `ovc08_init2`,
`ovc09_init`, `ovc10_constr`, `ovc11_audio`, `ovc12_agnt`, `ovc14_attact`,
`ovc16_saveui`, `ovc17_stash`, `ovc19_save`, `ovc21_manage`, `ovc29_anim`,
`ovc32_heap`, `ovc33_stats`, `ovc34_unit`, `ovc35_bldng`, `ovc37_season`,
`ovc44_strong_dat`, `ovc47_constrct`.

Unknown modules are still numbered (`ovc04`, `ovc07`, `ovc13`, `ovc15`,
`ovc18`, `ovc20`, `ovc22`-`ovc28`, `ovc30`, `ovc31`, `ovc36`, `ovc38`-`ovc43`,
`ovc45`, `ovc46`, `ovc48`-`ovc50`). Their string evidence suggests:

| segment | likely content |
|---|---|
| `ovc15`, `ovc22`, `ovc42` | town/building UI, population, construction lists |
| `ovc18`, `ovc45` | placement/build-mode UI |
| `ovc20` | MIDI/XMI playback (`cmidpak.com`, `.xmi`, `midpak.ad`) |
| `ovc23`, `ovc39` | character creation / party |
| `ovc24`, `ovc25`, `ovc27` | combat reports, spells, intelligence |
| `ovc28` | pause/menu handling |
| `ovc30` | wave/battle progression |
| `ovc31` | save path/config bootstrap |
| `ovc38` | high-score / achievements screen |
| `ovc41` | combat / undead turning |
| `ovc48` | intro/endgame (`bolt12.fli`, `save.999`) |
| `ovc49` | unit actions, demolish, endgame |
| `ovc04`, `ovc07`, `ovc26`, `ovc36`, `ovc40`, `ovc43`, `ovc46`, `ovc50` | still unidentified |

## 6. Plan

### Phase A — make the baseline trustworthy (largely done)
1. ~~Re-run naming/export after runtime-name and symbol-collision fixes.~~
2. ~~Drop synthetic Ghidra blocks (`DOS21`, fake-vdisk) from the source tree.~~
3. ~~Recover the stubborn functions with relaxed limits / repairs.~~
   Remaining: `OVC23_55fe_0000` (needs the mzap `FIXUP_FUNREF` relocation).
4. Export data with initialisers so the image can be rebuilt bit-accurately.
   `scripts/ghidra/ExportData.java` exists and produces a full report; it still
   needs a Ghidra-literal-to-C converter (segmented addresses, `Ah`/`BB8h`
   suffixes, ASCII-rendered constants) before it can replace `st_globals.c`.

### Phase B — make modules compile
1. Generate a Borland-C++-3.0-compatible compat header (done in `st_compat.h`;
   no `long long`, `far`/`near`/calling-convention shims).
2. Replace Ghidra's `swi(0x21)` pseudo-calls with real `int86`/inline-asm
   helpers (or the original `dos.h` wrappers where known).
3. Split `crtl.c` out: the rebuild must use TC++ 3.0's own `CL.LIB`, not the
   decompiled runtime.
4. Compile module by module under DOSBox + TC30, fixing types and prototypes.
   `main.c` and `mouse.c` already pass a host `gcc -fsyntax-only` check; the
   remaining modules expose the usual Ghidra type/field overlay issues.
5. Link the game modules against the original runtime/overlay manager.

### Phase C — verify
1. Build the reconstruction via DOSBox/TC30.
2. Run it in `dosbox-x-mod.exe` and use the harness to compare:
   * startup path and `game.cfg`,
   * asset loading and STRONG.DAT parsing,
   * screen output / palettes,
   * input and game-state transitions.
3. Diff control/data flow against the original with the harness's breakpoint,
   trace, call-trace, memory-watch and screenshot commands.

The modded emulator has been smoke-tested against the original game: mounting
`game/` and running `STRONG.EXE debug` reaches the intro screen, and the harness
TCP server answers `ping`/`regs`/`dump`/`fbdump`/`shot`. A host window capture
of the running intro is in `tmp/emu_print.png`.

### Phase D — finish
1. Refine every module to readable, original-like C/C++.
2. Eliminate address-based names in favour of recovered semantic names.
3. Recover data initialisers and overlay thunk tables exactly.
4. Validate a byte-for-byte or behaviour-for-behaviour rebuild.

## 7. Progress on the four follow-up steps

### Step 1 — mzap `FIXUP_FUNREF`
Implemented `mzap`'s missing function-reference relocation (`mz_fixup_funref`)
and reordered the FBOV fixup pass before trampoline untrapping, because the
trampoline table's original `ofs` fields are destroyed by untrapping. The tool
was rebuilt and tested against `STRONG.EXE` (merge and `-r 0x10000` paths). The
game contains **zero** `FIXUP_FUNREF` fixups, so the last decompiler failure is
not an mzap bug: `OVC23_55fe_0000` trips a Ghidra tracked-register/overlay
address canonicalization bug. This is documented in `hard/README.md`.

### Step 2 — exact global initialisers
`ExportData.java` now converts Ghidra literals to C (Borland `h` suffixes,
segmented addresses, ASCII-annotated bytes, `FALSE`) and emits recursive
initialisers. The resulting `st_globals.c` is valid C (`gcc -fsyntax-only`
passes) and replaces the zero-initialised file. `scripts/recover.bat` now runs
`ExportData` after the main export.

### Step 3 — TC30 refinement
Created a DOS/TC30 build harness (`scripts/stage_build.py`,
`src/decompiled/build_tc30.bat`) and a short-name staging tree. Automated
rewrites for Ghidra artifacts were added to `scripts/fix_recovered.py`:
`. _offset_size_` overlays, `(far_t)` casts, far-pointer comparisons and
allocator assignments, pointer-to-word stores, and `MK_FP` construction.

TC30 compile baseline (58 staged modules): **31 compile**. This includes all
requested targets:

| module | source | status |
|---|---|---|
| OVC04 | LBM decode / grab | **compiles** |
| OVC17 | stash read (`stshRead`) | **compiles** |
| OVC20 | stash files/audio (`stshStoreFile`) | **compiles** |
| OVC29 | animation init | **compiles** |
| OVC44 | `init_assets` | **compiles** |
| OVC46 | `init_assets1` | **compiles** |
| OVC48 | `init_assets2` | **compiles** |

Also compiling: `glob.c` (the exact data image), `main.c`, `mouse.c`, `ovc01`,
`ovc03`, `ovc05`, `ovc06`, `ovc07`, `ovc08`, `ovc24`, `ovc26`, `ovc28`,
`ovc30`, `ovc31`, `ovc32`, `ovc35`, `ovc36`, `ovc37`, `ovc38`, `ovc39`,
`ovc43`, `ovc50`, `ovr_stubs`, `support.c`.

Notable remaining blockers: `ovc02` hits a Turbo C++ compiler table limit in
the very large decompiled `draw_2e25_025a`; `crtl.c`, `ovl.c` and `video.c`
are runtime/overlay infrastructure that will be replaced or rewritten. The
rest still expose lost call arguments and pointer/word type artifacts.

### Step 4 — dynamic validation
Using the harness `bplog` (log-only execute breakpoints), with the runtime load
base derived from the INT 3Fh vector (`static - 0x7DE`):

* normal boot: `init_assets` ×2, `init_assets1` ×2, `init_assets2` ×2,
  `stshRead` ×31
* `grab` mode: `init_assets` ×2, `grabLbm` ×2 (grab then stops on a missing
  input asset in the copied save folder)

This confirms the refined asset-init and stash paths are the real runtime
paths.

## 8. Reproduce the recovery

```bat
C:\soft\ghidra_12.1.3_PUBLIC\support\analyzeHeadless.bat ^
  C:\Users\nangl\d\code\dest\gpr st -process st.exe -noanalysis ^
  -scriptPath C:\Users\nangl\d\code\dest\scripts\ghidra ^
  -postScript SanitizeSymbols.java
```

```bat
C:\soft\ghidra_12.1.3_PUBLIC\support\analyzeHeadless.bat ^
  C:\Users\nangl\d\code\dest\gpr st -process st.exe -noanalysis ^
  -scriptPath C:\Users\nangl\d\code\dest\scripts\ghidra ^
  -postScript ExportRecovered.java C:\Users\nangl\d\code\dest\src\decompiled
```

Then post-process the generated names/artifacts:

```bat
python C:\Users\nangl\d\code\dest\scripts\fix_recovered.py
```

Or simply run `scripts\recover.bat`.
