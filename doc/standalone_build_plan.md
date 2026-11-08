# Standalone build plan

Goal: a build that produces a runnable `STRONG.EXE` from `src/` plus committed
data/metadata, **without reading `game/STRONG.EXE`**.  The original EXE remains
only as a test oracle.

## Current build (2026-11-08)

```text
python scripts/fbov/build_standalone.py
```

This compiles all 51 overlay modules from `src/`, applies the committed
operand/table patches in `src/ov_patch.csv`, and combines them with:

| Part | File | Status |
|---|---|---|
| MZ header | `src/mz_header.bin` | data blob |
| Static load module | `src/static/*.asm` + `src/static_index.json` | labeled asm blocks |
| FBOV fixup/trailer metadata | `src/fbov_metadata.bin` + `src/fbov_index.json` | data blob with explicit ranges |
| Overlay code | `src/` + `src/ov_patch.csv` | rebuilt from source |

The result is byte-identical to the original EXE (SHA-256 `aebde62f...`), and
the build does not read `game/STRONG.EXE`.

`scripts/fbov/vroomm_baseline.py` and `vroomm_verify_linked.py` remain as the
oracle/verification path.

## Current gap

### Overlay code

- 51 overlay modules, 757 functions.
- **All 757 byte-accepted** (call/jump operands masked), at their original
  offsets.  Byte acceptance is not C recovery: **125 are real C**
  (22,850 bytes); **632 are byte-exact manual-frame `asm db`/pad dumps or
  TASM byte blocks** (332,939 bytes).
- True C coverage: 125/757 functions.  Per-function status:
  `doc/recovery_status.md`; per-function inventory: `tmp/fn_inventory.csv`
  (regenerate with `tmp/inventory.py`).
- Modules whose functions have non-standard prologues/epilogues are split
  into ordered C chunks and TASM byte blocks.  The source tree carries the
  chunks (`src/c<seg><n>.c`), byte blocks (`src/a<seg><n>.asm`) and a shared
  prototype header (`src/k<seg>.h`); no original EXE is read to build them.

### Static/resident code

From `doc/fbov_segments.csv`:

| Static segment | Size | Current source status |
|---|---:|---|
| `0x1000` | 12,317 | missing (startup, VROOMM manager, utilities) |
| `0x1301` | 2,247 | recovered as `src/main.c` (`main` verified) |
| `0x138E` | 458 | missing |
| `0x13AA` | 1,416 | missing |
| `0x1403` | 4,692 | missing |
| `0x22BB` | 1 | placeholder |

So of ~21 KB of static code, only `main` (2,247 bytes) is recovered as C.
The rest is represented as labeled TASM byte blocks in `src/static/`.  The
`0x1000` segment is the critical dependency: it owns startup, the overlay
manager and resident utility code.

### Static data

- DGROUP (`0x2410`, 38,043 bytes) is recovered byte-exact in
  `src/dgroup.c` / `src/dgroup.h`.
- There are **16 other non-BSS static data segments**, together about 55 KB
  (`0x1529`, `0x1539`, `0x16B3`, `0x1703`, `0x1726`, `0x17F8`, `0x195D`,
  `0x1EF4`, `0x217A`, `0x218E`, `0x21B1`, `0x21F2`, `0x222B`, `0x224A`,
  `0x225D`, `0x2D5A`).  They are byte blocks in `src/static/`.
- The 64 KiB `flags=4` segment entries are segment-table/BSS placeholders, not
  file data; they belong in the generated segment table.

### Overlay metadata

- The original FBOV trailer, fixup tables and non-code overlay bytes are
  carried in `src/fbov_metadata.bin`; `src/fbov_index.json` records where each
  chunk belongs and where overlay code must be inserted.  Overlay header and
  thunk segments are part of the static load module in `src/static/`.
- We have the data to generate them: `doc/fbov_manifest.json`,
  `doc/fbov_segments.csv`, `doc/fbov_overlays.csv`, and the trampoline
  information in the manifest.
- `tools/devroomm/src/ovrman.c` is a reversed C implementation of the VROOMM
  manager (`__OvrFixup`, `__OvrDoFixups`, `__OvrUntrapJmps`, `__OvrLoad`).
  It is a guide/reference, not yet part of the build.

## Definition of done

1. A single build command compiles all static and overlay modules with
   TC30/TASM and links/packages the EXE **without opening
   `game/STRONG.EXE`**.
2. Every function is either recovered C accepted by the verifier or an
   accepted `asm db` block (no unrecovered placeholders).
3. All static data is either symbolized in source or generated from committed
   data files; DGROUP remains the canonical `dgroup.c`.
4. Overlay headers, thunk tables, segment/fixup tables and overlay blob
   offsets are generated from committed metadata.
5. The produced EXE boots and passes runtime parity tests: startup prompt,
   menus, gameplay, save/load, audio/video paths.
6. Ideally the output is byte-identical to the original; if not, deviations
   are documented and justified.

## Two possible routes

### Route A — layout-preserving source build (strongest)

Keep the original segment order, overlay layout and VROOMM semantics, but
generate every byte from source/metadata.

1. Recover the static segments, especially `0x1000` (startup + manager).
2. Generate `bosh_t` overlay headers, `botrp_t` thunks, `_SEGTABLE_` and
   FBOV fixups from `doc/fbov_manifest.json`.
3. Compile the recovered manager (`ovrman.c` or a direct recovery of `0x1000`)
   and link it with the game code.
4. Build overlays from source modules plus generated table/gap bytes.
5. Link in the original segment order and append the overlay data.
6. Target: a source-built EXE that is byte-identical (or very close) to the
   original and runs under the same overlay semantics.

Pros: strongest parity, reuses all 504 verified functions, preserves the
original memory profile and overlay behavior.

Cons: the hardest route; exact linker layout, headers, fixup tables and
startup code are all required.

### Route B — functional standalone build

Link the recovered code into a conventional large-model EXE, with a simple
overlay loader or no overlays at all.

1. Compile all modules; replace overlay thunk calls with direct calls (or
   generate a small thunk table that jumps to resident/loaded code).
2. If all code + data fits in 640 KiB, link one image and drop overlays.
   Otherwise use a custom loader that swaps overlay blobs from files; the flat
   loader is the prototype but needs a real memory strategy (the current slot
   pool failed a 74 KiB allocation).
3. Use a standard TC30 startup or a recovered startup.
4. Target: a normal EXE that runs without VROOMM or the original FBOV.

Pros: no need to reproduce the original overlay metadata; reaches a runnable
standalone build sooner.

Cons: memory pressure, thunk replacement, possible behavior differences; not
byte-identical.

**Recommended:** use Route A as the correctness reference and Route B as the
practical deliverable, or complete A first if exact parity is the priority.

## Phases and milestones

### Phase 1 — finish overlay function recovery

- Convert the 631 remaining non-C functions: 378 byte-accepted manual-frame
  `asm db`/pad dumps plus 253 raw asm/pad functions that are not yet
  byte-accepted.  There are no failing C bodies; the former "mismatches" were
  pad dumps.
- Keep using `vroomm_verify_linked.py` / `vroomm_sweep.py`; refresh
  `doc/vroomm_accepted.md` and `doc/recovery_status.md`.
- Exit: 757/757 overlay functions are C, with byte acceptance tracked
  separately.

### Phase 2 — static code

- Build a static-function inventory for `0x1000`, `0x138E`, `0x13AA`, `0x1403`
  (same seg:offset naming, but not part of the overlay CSV).
- Recover in offset order, starting with `0x1000` (startup/manager/utility).
- Use a static harness (`DGROUP` + stubs) analogous to the overlay harness.
- Exit: static segments compile and link into a core EXE that reaches `main`.

### Phase 3 — static data

- Generate `src/data_<seg>.c` byte arrays for the 16 non-BSS data segments and
  commit them.  These are often opaque tables; byte blobs are a pragmatic
  first step and can be symbolized later.
- Keep DGROUP symbolic and byte-exact.
- Exit: no build-time read of the original EXE for data.

### Phase 4 — overlay metadata generation

- Write a generator that emits `bosh_t` headers, `botrp_t` thunk entries,
  `_SEGTABLE_` entries and FBOV fixups from committed metadata / source maps.
- Use `tools/devroomm/doc/bcpp_overlays.txt` and `ovrman.c` as the format
  reference.
- Exit: generated headers/tables match the original bytes for the current
  overlay set.

### Phase 5 — standalone link prototype

- Link the static core + DGROUP + generated static data first; boot to `main`.
- Add overlays: either generated headers + recovered manager (Route A) or the
  custom loader/direct-call scheme (Route B).
- Exit: a source-only EXE boots to the startup prompt without the original
  EXE.

### Phase 6 — runtime parity

- Automate startup, menu, gameplay, save/load, audio and video checks with the
  DOSBox debug server (registers, memory, screenshots, allocation sizes).
- Compare against the original oracle.
- Exit: the standalone build passes the same scenarios; document any accepted
  deviations.

## Immediate next steps

1. Start the static `0x1000` inventory and recovery now; it is the strategic
   dependency for both routes.
2. In parallel, continue clearing the 242 overlay `asm db` functions.
3. Generate and commit the 16 static data blobs (Phase 3) so the build stops
   depending on the original EXE for data.
4. Write `scripts/build_standalone.py` as a skeleton that compiles and links
   the static core only; grow it into the full build.
5. Decide Route A vs Route B after the static core boots and we know how much
   resident/overlay memory the game needs.

## Risks

- `0x1000` contains Borland startup and the VROOMM manager; it is the largest
  reverse-engineering unknown.
- Exact overlay headers/fixups are linker-generated; reproducing them may
  require careful metadata work.
- The 16 static data segments are largely opaque; byte blobs are a fallback,
  not clean recovered C.
- All-resident code likely exceeds 640 KiB, so a loader/swapper or the
  original overlay metadata is probably still needed.
- Some hand-optimized functions will remain `asm db` because the compiler will
  not reproduce their exact bytes (disp8/disp16, `mov al`, pop-cleanup, etc.).
- Runtime parity is nondeterministic around audio/video; the test harness must
  allow for that.
