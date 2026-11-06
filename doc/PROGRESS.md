# Progress

Updated: 2026-11-06

Plan: [`../plan.md`](../plan.md)

## Gate status

| Gate | Status | Evidence |
|---|---|---|
| G0 — quarantine old baseline | **PASS** | `src/decompiled` moved to `reference/decompiled_baseline`; old `gpr/` marked reference-only |
| G1 — independent FBOV manifest | **PASS** | `scripts/fbov/model.py` produced `doc/fbov_manifest.json` and CSVs; 0 validation errors |
| G2 — fresh Ghidra model | **MODEL BUILT / VERIFYING** | `gpr_fresh` built by `BuildFbovModel.java`; analysis run |
| G3 — reference audit | IN PROGRESS | constant-pointer class removed; audit pending |
| G4 — data/global model | NOT STARTED | |
| G5 — startup/`main` byte-exact | NOT STARTED | |
| G6 — link | NOT STARTED | |
| G7 — runtime equivalence | NOT STARTED | |

## Phase 1 results

Source: `game/STRONG.EXE` (511,280 bytes), parsed independently of mzap.

| Item | Value |
|---|---|
| MZ load module start | `0x1E00` |
| MZ load module end | `0x1F420` |
| FBOV offset | `0x1F420` |
| `_SEGTABLE_` entries | 91 |
| CODE segments | 6 |
| DATA segments | 34 |
| Overlay segments | 51 |
| Overlays | 51 |
| FBOV fixups | 13,367 |
| FUNREF fixups | 0 |
| MZ relocation entries | 1,832 |
| DGROUP `_DATA` | `0x2410` (38,042 bytes) |
| `_OVRDATA_` | `0x225D` |

Manifest files:

- `doc/fbov_manifest.json` (generated; not tracked)
- `doc/fbov_segments.csv`
- `doc/fbov_overlays.csv`
- `doc/fbov_fixups.csv`
- `doc/fbov_relocs.csv`

Validation: **0 errors**, 9 warnings.

Known warnings to resolve in the loader:

1. Eight sentinel segment entries with `minoff > maxoff`
   (`0x1CA0`..`0x1D59`). These are Borland marker entries, not byte ranges.
2. Duplicate static segments:
   `0x1529(2)`, `0x225D(3)`, `0x22BB(2)`, `0x2CA1(3)`, `0x2CA2(2)`,
   `0x2CA3(2)`. The segment table contains several sub-entries at the same
   start; the loader must merge or disambiguate them explicitly.

## What this proves

The original FBOV structure is now parsed and internally consistent:

- every fixup target index is in `_SEGTABLE_`;
- every fixup site is inside its overlay's code;
- every non-sentinel segment range is inside the load module;
- DGROUP `0x2410` and `_OVRDATA_` `0x225D` exist at the addresses given by
  the reversed overlay manager.

This is the model the fresh Ghidra program will be built from — not the
mzap-merged image and not the old decompiled tree.

## Phase 2 results (fresh model)

`tools`-side builder: `scripts/ghidra/BuildFbovModel.java`.
Fresh project: `gpr_fresh` (not tracked; regenerate from the original EXE).

| Item | Result |
|---|---|
| Segment blocks | 73 (merged duplicate `_SEGTABLE_` entries) |
| Overlay code blocks | 50 |
| Trampolines untrapped | 756 |
| FBOV fixups applied | 13,367 / 13,367 |
| MZ relocation references | 1,787 / 1,832 |
| DS / ES | `0x2410` |
| SS | `0x2D5A` |

Verification:

- `2E25:0344` (a DGROUP fixup site) now reads `10 24` (`0x2410`).
  The mzap-merged image had `0x1410` here — the off-by-`0x1000` bug.
- `2E25:0380` now reads `15 23` (`0x2315`, an overlay target).
- `OVC01` (`2D63:0000`) decompiles cleanly:
  `return param_1 & 0xf;`.
- `OVC02`/`draw_2e25_025a` is much larger, but the
  `"puppetmaker"+3`, `"glassworks"+9`, `"arena"+n` class is gone after
  setting `DecompileOptions.setInferConstantPointers(false)`.
  Those expressions were segment constants, not strings.
- `OVC23` (`55FE:0000`) still hits Ghidra's `NO ADDRESS` failure. That is a
  separate tracked-register/overlapping-instruction issue, not the segment
  model; it needs a targeted repair.

Known limitations to handle before G3 is complete:

- 45 MZ relocation references were skipped because either the site or target
  block was absent; each must be classified (BSS/stack/sentinel).
- The 8 sentinel segment entries and 6 duplicate static segments still need
  explicit merge rules (currently merged or skipped).
- Function/data symbol recovery (G4) is still required for readable C; the
  difference is that unresolved offsets now remain scalars instead of being
  mis-symbolized as strings.

## Next

1. Finish G3: build `scripts/fbov/audit_refs.py` (or a Ghidra audit) that
   reports every unresolved reference, skipped MZ relocation, sentinel/merged
   segment and segment-constant use.
2. Resolve the 45 skipped MZ relocation references and the sentinel/duplicate
   segment rules.
3. Repair `OVC23` (`55FE:0000`) with a targeted re-disassembly/overlap fix.
4. Begin G4: recover the DGROUP layout and the first structures/globals so
   offsets get names instead of scalars.
5. Then start the function-by-function recovery and byte-match harness.
