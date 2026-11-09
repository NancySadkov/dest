# Stronghold Decompilation Plan

This document defines how the Stronghold (`STRONG.EXE`, 1993, Borland C++ 3.0,
large model, VROOMM overlays) decompilation will be done. It replaces the
earlier "mass decompiler export" approach.

The goal is not "a tree that compiles". The goal is a source tree that:

1. models the original program's segments, data and overlays correctly;
2. can be compiled with Turbo C++ 3.0 into code that matches the original
   function for function;
3. can be linked and run, with behaviour verified against the original.

Progress is measured against those criteria, not against module compile counts.

---

## Current status (2026-11-08)

The project now has a **source-only build** that reproduces the original EXE
byte-for-byte, and an oracle build for verification.

```text
python scripts/fbov/build_standalone.py
```

The build compiles every overlay module from `src/`, restores call/jump
operands from `src/ov_patch.csv`, and fills the committed static/FBOV base
blobs.  It does not read `game/STRONG.EXE`.  The output hash is verified
against the original (`aebde62f...`).

- Source tree: active recovered source is in `src/` (no `src/recovered/`,
  no `src/chunks/`).  Layout and conventions: `src/README.md`.
- Overlay code: 51 modules, 757 functions. **All 757 byte-accepted**:
  **125 are real C** (22,850 bytes) and **632 are byte-exact manual-frame
  `asm db`/pad dumps or TASM byte blocks** (332,939 bytes).  True C coverage
  is 125/757 functions.  Details: `doc/recovery_status.md`.
- Function layout is preserved: every overlay is rebuilt at its original
  offsets.  Modules with non-standard prologues/epilogues are split into
  ordered C chunks plus TASM byte blocks (`src/c<seg><n>.c`,
  `src/a<seg><n>.asm`, shared prototype header `src/k<seg>.h`); segment
  parts are linked in original order.
- Static code: `main` (`0x1301`, 2,246 bytes) is compiled from `src/main.c`
  in the build.  The other static segments (`0x1000` 12,317 bytes -
  startup, VROOMM manager, utilities; `0x138E` 458; `0x13AA` 1,416; `0x1403`
  4,692) are labeled TASM byte blocks in `src/static/`; converting them to C
  is the next recovery target.
- Data: DGROUP (`0x2410`, 38,043 bytes) is recovered byte-exact.  The sixteen
  other non-BSS static data segments (~55 KB) are also byte blocks in
  `src/static/`.
- Overlay metadata: fixup tables are generated from `doc/fbov_fixups.csv`;
  the remaining non-code bytes are embedded in `src/fbov_other.json`.
  Overlay header/thunk segments are already in `src/static/`, and every
  overlay code region is rebuilt from `src/`.
- Runtime: still the original VROOMM manager and startup bytes.
  `tools/devroomm/src/ovrman.c` is the reversed manager reference.
- Init recovery: the `main` -> `f_3381_0579` call graph and the 768-operation
  `f_6ffe_02f7` sprite loader are mapped in `doc/init_recovery.md`; the
  ordered operation table is `doc/init_assets_ops.csv`.  Functional C for
  `init_assets`, `init_assets1` and `init_assets2` is in `src/init/` and
  compiles via `scripts/fbov/build_init.py`.
- Oracle build: `scripts/fbov/vroomm_baseline.py` stages the original EXE and
  `vroomm_verify_linked.py` patches verified functions into it.  It boots to
  320x400 and stays byte-identical for accepted functions.

Detailed current plan: `doc/standalone_build_plan.md`.
Recovery quirks: `doc/quirks.md`.
Accepted functions: `doc/vroomm_accepted.md`.

### Route to a standalone build

1. **Layout-preserving** — recover static `0x1000`, generate the overlay
   headers/thunks/FBOV, rebuild the VROOMM manager, link in the original
   segment order, and target a byte-identical source-built EXE.  Strongest
   parity; hardest.
2. **Functional** — link recovered code into a conventional EXE with direct
   thunk calls or a custom overlay loader, accepting a non-identical memory
   layout.  Faster to a runnable build; requires a memory strategy and runtime
   parity tests.

Recommended: use route 1 as the correctness oracle and route 2 as the
practical deliverable, or finish route 1 if exact parity is the priority.

---

## 1. What went wrong

The previous attempt started from a merged image produced by `mzap -mb` and
exported whole modules from Ghidra's decompiler. That produced a large tree
(`src/decompiled/`) and a compile count, but the code is not trustworthy.

Symptoms:

- thousands of expressions such as `"puppetmaker" + 3`, `"arena" + 5`,
  `"glassworks" + 9`, `"public baths" + 6`;
- `ram0x...`, `UNK_...`, `MK_FP(0, small)` and pointer/word conversions;
- calls with missing or extra arguments;
- absolute addresses resolved to whatever string or data label happened to be
  nearest, not to the intended segment.

These are not isolated bugs. They are the same bug: **the original Borland
FBOV segment/fixup model was never represented in Ghidra**. The merged image
placed bytes in blocks, but it did not carry the information that tells a
disassembler/decompiler which segment an offset belongs to. Without that,
Ghidra symbolized unresolved offsets against nearby labels and the decompiler
invented plausible-looking C.

Compile counts hid the problem because wrong code often compiles.

Two concrete causes were found while rebuilding the model:

1. `mzap -mb` writes `_SEGTABLE_[i].seg` (load-module-relative) into the
   overlay fixups, while the merged blocks are at `0x1000 + seg`. Every
   overlay data reference is therefore off by `0x1000` (`0x1410` instead of
   `0x2410` for DGROUP).
2. Ghidra's `InferConstantPointers` decompiler option turns 16-bit segment
   constants (`0x2410`, `0x2337`, ...) into data pointers into DGROUP, which
   produces expressions such as `"puppetmaker" + 3` and `"glassworks" + 9`.
   With `setInferConstantPointers(false)` those constants stay scalars.

The old tree is therefore quarantined under `reference/` for its function
inventory only. It is not built, not edited, and not used as a source of truth.

---

## 2. Ground truth

The only authoritative inputs are:

| Input | Role |
|---|---|
| `game/STRONG.EXE` | the original overlayed executable |
| `tools/devroomm/doc/bcpp_overlays.txt` | FBOV/segment-table/overlay-header description |
| `tools/devroomm/doc/dgroup.txt` | DGROUP semantics |
| `tools/devroomm/src/ovrman.c` | reversed overlay manager (`__OvrFixup`, `__OvrFixupFunref`, `__OvrDoFixups`, `__OvrUntrapJmps`, `__OvrLoad`) |
| `tools/devroomm/specimen/ida_loader/` | an existing loader implementation for cross-checking |
| `tools/TC30` | the target compiler |
| `emulator/dosbox-x-mod.exe` + harness | the running original, used to verify addresses and data |

`tools/mzap` may still be used as a *diagnostic* or to cross-check a manual
parse. It is not allowed to define the model.

No symbol, type or address is accepted because Ghidra suggested it. Every one
must be backed by the file format, the relocation/fixup tables, the reversed
overlay manager, or a live read from the original program.

---

## 3. The original program model

### 3.1 MZ load module

The standard MZ header gives:

- `cparhdr` — size of the header in paragraphs;
- `lfarlc`, `crlc` — relocation table;
- `ss:sp`, `cs:ip` — entry state;
- the load image begins at `cparhdr * 16`.

The Borland extension (when present) sits between the MZ header and the
relocation table.

### 3.2 FBOV

After the load image, aligned to 16 bytes, is the Borland FBOV section:

```c
struct bofh_t {          /* 16 bytes */
    uint16_t id[2];      /* "FB", "OV" */
    uint32_t size;       /* FBOV size excluding this header */
    uint32_t stofs;      /* file offset of _SEGTABLE_ from MZ start */
    int32_t  nsegs;
};

struct boseg_t {         /* 8 bytes, _SEGTABLE_ entry */
    uint16_t seg;
    uint16_t maxoff;
    uint16_t flags;      /* 1=CODE, 2=OVR, 4=DATA */
    uint16_t minoff;
};

struct bosh_t {          /* 32 bytes, overlay header */
    uint8_t  code[2];    /* CD 3F (INT 3Fh) */
    uint16_t saveret;
    int32_t  fileofs;    /* offset into FBOV (from end of bofh_t) */
    uint16_t codesz;
    uint16_t fixupsz;
    uint16_t jmpcnt;
    uint16_t link;
    uint16_t bufseg;     /* runtime: 0 = not loaded */
    uint16_t retrycnt;
    uint16_t next;
    uint16_t ems_page;
    uint16_t ems_ofs;
    uint8_t  user[6];
};

struct botrp_t {         /* 5 bytes, trampoline stub */
    uint8_t  code[2];    /* CD 3F */
    uint16_t ofs;        /* offset inside overlay code */
    uint8_t  pad;
};

struct bojmp_t {         /* 5 bytes, untrapped trampoline */
    uint8_t  code;       /* EA */
    far_t    dst;
};
```

### 3.3 Overlay code and fixups

For every overlay segment:

- the header and its trampolines live at `seg:0` in the normal load module;
- the code lives in the FBOV area at `fbovofs + 16 + fileofs`;
- the fixup table follows the code at `code + codesz`;
- it contains `fixupsz / 2` 16-bit offsets;
- at `code + offset` is a 16-bit fixup word `sf`;
- `target_index = sf >> 3`, `flags = sf & 7`;
- the word at the fixup site is replaced by `_SEGTABLE_[target_index].seg`;
- if `flags & FIXUP_FUNREF` (`0x1`), the offset part of the far pointer is
  rewritten to the matching trampoline offset by `__OvrFixupFunref`.

`__OvrDoFixups` and `__OvrFixupFunref` in `tools/devroomm/src/ovrman.c` are the
reference implementation.

### 3.4 DGROUP and data

From the reversed overlay manager:

- `_DATA` (first segment of DGROUP) = `0x2410`;
- `_OVRDATA_` (overlay manager data) = `0x225d`;
- `_VDISKSEG_` is another segment of the overlay group.

At startup `DS` and `ES` are set to DGROUP. Code that does
`MOV AX, 0x2410; MOV ES, AX` relies on that static segment value. In Ghidra we
place DGROUP at `0x2410` and set the default `DS`/`ES` context to it. This is
what makes ordinary `[offset]` references resolve into DGROUP instead of into
the nearest string.

### 3.5 Static vs runtime addresses

The original EXE is loaded at a runtime base. Overlay code is copied into a
runtime buffer. For static analysis we use the static segments from
`_SEGTABLE_`/FBOV, exactly as the linker emitted them. Runtime addresses are
only used by the harness for verification.

---

## 4. Target pipeline

```
 original EXE
      |
      v
 [P1] FBOV manifest  (segments, overlays, fixups, relocations)
      |
      v
 [P2] fresh Ghidra program (blocks, relocations, DS/ES/SS context)
      |
      v
 [P3] reference audit (no unresolved segment/data references)
      |
      v
 [P4] data + symbols (DGROUP, structs, strings)
      |
      v
 [P5] function-by-function recovery (main outward)
      |
      v
 [P6] TC30 byte-identical verification per function
      |
      v
 [P7] link + runtime validation
      |
      v
 [P8] cleanup / finish
```

Each phase has a hard gate. No later phase starts until the gate passes.

---

## 5. Phase 0 — quarantine and workspace

Actions:

1. Move the old tree to `reference/decompiled_baseline/`.
   - Keep it for the function inventory and address list.
   - Do not compile it, import it, or copy symbols from it.
2. Keep the old Ghidra project under `reference/gpr_baseline/` (or leave the
   existing `gpr/` untracked and create a new project).
3. Create the new workspace:

```
plan.md
reference/
  decompiled_baseline/
doc/
  STATUS.md
  fbov_segments.csv
  fbov_fixups.csv
  functions.csv
  PROGRESS.md
tools/
  devroomm/            # authoritative overlay documentation
  ghidra_fbov/         # new loader / model builder
  TC30/
scripts/
  fbov/
    model.py           # independent parser -> manifest
    audit_refs.py      # reference validation gate
    byte_diff.py       # compiled vs original function bytes
  ghidra/
src/
  recovered/           # new hand-recovered source
  harness/             # compile/link/compare harness
```

Gate G0: old tree is no longer in the build path, and the new directories
exist.

---

## 6. Phase 1 — FBOV manifest

Write `scripts/fbov/model.py`. It must parse the original `STRONG.EXE`
*without using mzap* and emit:

- `doc/fbov_segments.csv`
  - segment, minoff, maxoff, flags, class, file offset, size;
- `doc/fbov_overlays.csv`
  - header segment, code segment, code file offset, code size, fixup count,
    trampoline count;
- `doc/fbov_fixups.csv`
  - source segment/offset, fixup word, flags, target index, target segment,
    whether it is FUNREF;
- `doc/fbov_relocs.csv`
  - MZ relocation table entries.

The parser must also compute:

- the normal load module bounds;
- the FBOV offset;
- the DGROUP segment and `_OVRDATA_`;
- the overlay code-segment assignment.

Cross-checks (required):

1. Re-parse with `tools/devroomm/specimen/ida_loader/` logic where applicable.
2. Compare against `mzap -lb`/`-lbh` output as a *diagnostic only*.
3. Verify every segment range against the file bounds.
4. Verify every fixup target index is in `_SEGTABLE_`.
5. Verify the DGROUP segment is `0x2410` and that `_SEGTABLE_` marks it DATA.
6. Verify the total fixup count matches the overlay headers.

Gate G1: the manifest is complete, internally consistent, and every address is
justified. Any ambiguity is recorded, not guessed.

---

## 7. Phase 2 — fresh Ghidra model

### 7.1 Program

Create a new Ghidra project `gpr_fresh` and a program imported from
`game/STRONG.EXE`.

Start with a model-builder script on a raw/blank program, then promote the
same code to a Ghidra loader extension under `tools/ghidra_fbov/`.

The reason for the staged approach: the block/relocation/context model can be
validated quickly with a script, and then moved behind a proper `Loader`
without changing the model.

### 7.2 Blocks

For each `_SEGTABLE_` entry:

- non-overlay CODE/DATA:
  - block at `seg:minoff .. seg:maxoff`;
  - source bytes at `start_ofs + seg*16 + minoff`;
  - BSS/uninitialized blocks marked uninitialized.
- overlay header/stub:
  - block at `seg:0 .. 32 + jmpcnt*5 - 1`;
  - source bytes from the normal load module.
- overlay code:
  - block at the overlay code segment and displacement derived from
    `fbovofs + 16 + fileofs`;
  - source bytes from the FBOV area;
  - the code segment assignment is recorded in the manifest.

Each block gets a comment stating its origin and class. No block is placed
"because mzap did".

### 7.3 Relocations and references

- MZ relocation entries: create a reference/relocation at `seg:ofs` to the
  segment value stored there.
- FBOV fixups: create a reference/relocation at the fixup site to
  `_SEGTABLE_[target].seg`.
- FUNREF fixups: rewrite the offset to the matching trampoline and create a
  reference to the trampoline entry.
- Trampolines: lay them out as `JMP FAR code_seg:offset` so the call graph
  reaches the overlay code.

Ghidra may not have a relocation kind that expresses every Borland fixup. In
that case create:
- an operand reference for the segment immediate;
- an operand reference for the offset immediate;
- a comment on the instruction naming the target.
The audit (Phase 3) defines what is acceptable; a missing relocation is a
failure, not a warning.

All decompilation must use:

```java
DecompileOptions o = new DecompileOptions();
o.setProtoEvalModel("__cdecl16far");
o.setInferConstantPointers(false);   // segment constants are not pointers
```

Everything is written with the **static** segment (`0x1000 + table_seg`).
The loader never writes a load-module-relative segment into a fixup.

### 7.4 Segment context

Set program context:

- `DS = 0x2410` (DGROUP `_DATA`);
- `ES = 0x2410` where the code expects the data group;
- `SS =` the stack segment from the MZ/segment map;
- overlay code runs with the same `DS` as its caller.

This is the single most important fix for the `"string"+offset` class.

### 7.5 Analysis

Run full analysis on the fresh program. Do not use `-noanalysis`, and do not
reuse the old analysis database.

Gate G2: the new program contains every segment and overlay, with the expected
bounds and permissions.

---

## 8. Phase 3 — reference audit

Write `scripts/fbov/audit_refs.py` (or a Ghidra script) that inspects the
fresh program and the exported C and fails on:

- unresolved or invented symbols;
- `"<literal>" + n` expressions that are not genuine substrings;
- `ram0x...`, `UNK_...`, `stack0x...` used as data addresses;
- `MK_FP(0, small)` / small-integer far pointers;
- data references outside known blocks;
- overlay calls that do not go through a trampoline;
- DGROUP offsets that do not match the live program.

The audit produces `doc/PROGRESS.md` counters and a per-reference report.

Gate G3: zero unexplained references. This is the gate that the previous
approach never had.

---

## 9. Phase 4 — data and symbols

Before recovering large functions:

1. Lay out DGROUP from the segment table and the code's access patterns.
2. Recover the main structures (`entity`, `building`, `stash`, `sprite`,
   `agent`, `menu`, etc.) from field offsets and use sites.
3. Recover the string table and confirm each string's address in the running
   program.
4. Name globals only from evidence: relocation targets, debug strings,
   overlay-manager tables, or runtime reads.
5. Record each symbol in `doc/globals.csv` with its address, type, evidence,
   and verification status.

No symbol is copied from the old decompiled tree.

Gate G4: the DGROUP/global model is consistent with the runtime harness for a
representative set of variables.

---

## 10. Phase 5 — function recovery

Start at the real entry point from the MZ header, then follow the Borland
startup into `main`, then the call graph. Recover in dependency order:
data/structs first, then functions.

For each function:

1. Determine its exact bounds from the new analysis/relocations.
2. Read the assembly and pcode. The decompiler is a hint, never the answer.
3. Recover the signature, calling convention, locals, and segment assumptions.
4. Write clean C in `src/ov_<seg>.c` (or `src/main.c` for the static main).
5. Compile with TC30 using the project's fixed flags.
6. Compare the generated function code with the original bytes.
7. Fix until the comparison passes.
8. Add the function to the accepted manifest (`doc/vroomm_accepted.md`) by
   running the verifier; do not hand-edit that file.

### Byte-match rules

The comparison is done on the function's instruction stream, with relocation
operands normalized to the same static values. A function is:

- `exact` — bytes match after relocation normalization;
- `equivalent` — instruction encodings differ only in a documented,
  compiler-unavoidable way;
- `different` — must not be accepted.

Register allocation, instruction scheduling, and stack layout must match the
original compiler. If they do not, the C is not equivalent enough; rewrite it.

### Call-graph order

Prefer callees before callers once the data types are known, so signatures are
stable. `main`/startup is the anchor, not the first function written.

Gate G5: `main` and the startup path are recovered and `exact`.

---

## 11. Phase 6 - build and link

- Use TC++ 3.0 (`tools/TC30`), large model, overlays.
- Fixed compiler flags, established empirically against `main`:
  `-ml -1 -G` (large model, 80186 instructions, generate for speed).
  `-1` is required for the original `push imm8` encodings; `-G` is required
  for the original `PUSH BP / MOV BP,SP / SUB SP,N` prologue instead of
  `ENTER`.
- Reconstruct the original project/module boundaries from the segment table and
  the linker's segment classes.
- Link against the original Borland runtime and overlay manager where possible;
  do not re-implement CRT/overlay code unless necessary.
- Compare the linked image's segment map and entry state with the original.

The current oracle build (`vroomm_baseline.py` + `vroomm_subst.py`) is a
verification aid, not this phase: it patches the original EXE.  The standalone
build must compile, link and package the image without reading
`game/STRONG.EXE`.  See `doc/standalone_build_plan.md` for the two routes
(layout-preserving vs functional) and the gap list.

Gate G6: the reconstruction links and its segment map matches the original.

---

## 12. Phase 7 — runtime validation

Use the modded DOSBox and harness:

- `bplog` — call/entry traces;
- `peek`/`poked` — live memory values;
- `regs`, `backtrace`;
- `find` — locate data/strings;
- screenshots and palette checks.

Compare:

- startup path and `game.cfg`;
- asset loading and `STRONG.DAT` parsing;
- hashes of loaded data and screen output;
- input/game-state transitions.

Gate G7: the reconstruction reaches the same states as the original with the
same observable behaviour.

---

## 13. Progress tracking

### Ledgers

- `doc/fbov_segments.csv` — the segment map.
- `doc/fbov_fixups.csv` — fixups and targets.
- `doc/functions.csv` — per-function status.
- `doc/globals.csv` — per-global status.
- `doc/PROGRESS.md` — generated summary.

`functions.csv` columns:

```
segment,offset,size,name,module,signature,source_file,compiles,byte_match,refs_ok,runtime_ok,notes
```

### Metrics

- segments modelled / total;
- fixups resolved / total;
- globals verified / total;
- functions recovered / total;
- functions `exact` / recovered;
- bogus references (must be zero).

Compile counts are not a progress metric.

### Report

`doc/PROGRESS.md` is generated after each phase and lists:

- current gate;
- what passed;
- what is blocked;
- the next function in the queue.

---

## 14. Risks and mitigations

| Risk | Mitigation |
|---|---|
| Ghidra loader API is heavy | Start with a script-based model builder; promote to a loader once the model is validated |
| Overlay code-segment assignment is ambiguous | Derive from FBOV/segment table; cross-check with the runtime harness and the IDA loader |
| Ghidra can't express a Borland fixup | Create operand references + comments; fail the audit until the target is explicit |
| TC30 flags/version differ from the original | Identify the original compiler from CRT signatures; pin flags; compare known functions first |
| Data structures unknown | Recover from access patterns and live reads; never guess silently |
| The old tree contaminates new names | Quarantine it; no copying without independent evidence |

---

## 15. Immediate next steps

Completed:

1. ~~Create `plan.md`.~~
2. ~~Quarantine `src/decompiled/` under `reference/`.~~
3. ~~Implement `scripts/fbov/model.py`.~~
4. ~~Produce and validate the FBOV manifest.~~
5. ~~Implement the fresh Ghidra model builder and `gpr_fresh`.~~
6. ~~Run the reference audit (G3): 0 errors.~~

Next:

9. Finish overlay recovery: 631 non-C functions remain (378 byte-accepted
   asm/pad dumps + 253 unaccepted raw asm/pad; no failing C bodies).
10. Recover the static code, starting with `0x1000` (startup, VROOMM manager,
    utilities), then `0x138E`, `0x13AA`, `0x1403`.
11. Extract and commit the 16 non-DGROUP static data segments.
12. Generate the overlay metadata (`bosh_t` headers, `botrp_t` thunks,
    `_SEGTABLE_`, FBOV fixups) from committed metadata.
13. Build the static core first, then add overlays; make the build script stop
    reading `game/STRONG.EXE`.
14. Run runtime parity tests against the original oracle.

All emulator runs use `scripts/fbov/run_dosbox.py` or `-noconsole` +
`SDL_VIDEODRIVER=dummy` + a hidden window, so they do not steal focus.

---

## 16. Definition of done

- The build script compiles, links and packages the game from `src/` and
  committed metadata **without reading `game/STRONG.EXE`**.  The original EXE
  remains only as a test oracle.
- Every function in the original is either recovered or identified as part of
  the Borland runtime/overlay manager.
- Every recovered function compiles with TC30 and matches the original bytes
  (or has a documented, reviewed equivalent).
- Every data reference resolves to a verified segment/symbol; all static data
  is represented in source or in committed generated data.
- Overlay headers, thunks, segment/fixup tables and overlay layout are
  generated from committed metadata, not copied from the original image.
- The reconstruction links and runs with the recovered/rebuilt runtime, or a
  documented replacement loader with verified behaviour.
- Behaviour matches the original under the harness.
- `doc/PROGRESS.md` reports zero bogus references and zero unverified symbols.

---

## 17. Glossary

- **DGROUP** — Borland's data group; `_DATA` starts at `0x2410`.
- **FBOV** — Borland's overlay section appended to the MZ file.
- **`_SEGTABLE_`** — the linker's segment table (`boseg_t[]`).
- **Overlay header** — `bosh_t`; lives at the overlay stub segment.
- **Trampoline** — `botrp_t`/`bojmp_t` entry that the manager patches to a far
  jump into the loaded overlay.
- **FUNREF** — a fixup that points at an overlay function and must be
  redirected through the trampoline.
- **Static segment** — the segment value emitted by the linker (what we model).
- **Runtime segment** — the value after the DOS loader/overlay manager
  relocation (what the harness sees).
