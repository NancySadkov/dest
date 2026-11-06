# DeSt
WIP decompilation of the 1993 AD&D Stronghold game for DOS.

The project's goal is recovering original code in a form compilable by Borland C++ 3.0.

![Dragon Image](https://github.com/NancyAurum/dest/blob/main/dragon.png)


# Milestones
* Decompiled small part of the init code and mapped most of the asseta init code.
* Recovered the raw asset files (LBMs, VOCs, etc), which can be assembled back into the STRONG.DAT stash file by going to assets/ folder and typing `st.exe grab`. The LBM files can be edited with [Deluxe Paint](https://winworldpc.com/product/deluxepaint/2x). These are PBM LBMs, so not many programs support them.
* **Recovered the full executable into `src/decompiled/`**: every code segment is
  exported as a C module (55 modules, 1021 functions), together with recovered
  types, globals (with original initialisers), prototypes and a function index.
  See `doc/STATUS.md` for the current state and the plan for turning the
  decompiler baseline into a rebuildable, original-like source tree.
* Added a TC30/DOSBox build harness. **31 of 58** staged modules now compile
  with Turbo C++ 3.0, including the asset-init chain (`ovc44/46/48`), the stash
  layer (`ovc17/20`), the LBM decoder (`ovc04`), `main` and `mouse`.
* Implemented mzap's missing Borland `FIXUP_FUNREF` relocation and verified the
  merge/relocation paths against `STRONG.EXE`.
* Validated the refined asset-init/stash paths dynamically with the DOSBox
  harness (`init_assets`, `init_assets1/2`, `stshRead`, `grabLbm`).


# TODO

* Refine the recovered modules into compilable, original-like C (Phase B in
  `doc/STATUS.md`), starting with the init/asset-loading modules.
* Recover the 6 functions that currently defeat the Ghidra decompiler
  (`init_assets`, `manage_4d05_1bee`, `stshRead`, ...).
* Fix skylines palettes and and entity frame rect markers, which are used to determine sprite centering.
* Fix RLE encoding for PBM LBM files.
* Decompile the rest of the game, starting with these huge assets init routines.


# Development

gpr - the Ghidra project file

tools/ungrab - utility which recovers files from the English STRONG.DAT.

tools/mzap - utility which converts the Borland FBOV overlayed STRONG.EXE into a plain MZ format loadable by Ghidra and IDA.

scripts/ghidra - reproducible headless-Ghidra naming/export pipeline.

See doc/STATUS.md for the current recovery state and roadmap.

See doc/journey.txt for the explanation on how to prepare Ghidra.

See doc/switchfix.txt on how to fix Ghidra's switch decompilation.
