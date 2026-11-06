# Progress

Updated: 2026-11-06

Plan: [`../plan.md`](../plan.md)

## Gate status

| Gate | Status | Evidence |
|---|---|---|
| G0 — quarantine old baseline | **PASS** | `src/decompiled` moved to `reference/decompiled_baseline`; old `gpr/` marked reference-only |
| G1 — independent FBOV manifest | **PASS** | `scripts/fbov/model.py` produced `doc/fbov_manifest.json` and CSVs; 0 validation errors |
| G2 — fresh Ghidra model | NOT STARTED | next |
| G3 — reference audit | NOT STARTED | |
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

## Next

1. Implement the fresh Ghidra model builder (`tools/ghidra_fbov/`).
2. Create `gpr_fresh` from `game/STRONG.EXE`.
3. Create blocks from `fbov_segments.csv` and overlay code from
   `fbov_overlays.csv`.
4. Add relocations/references from `fbov_fixups.csv` and `fbov_relocs.csv`.
5. Set `DS`/`ES` to DGROUP `0x2410`; set `SS` to the stack segment.
6. Run the reference audit (G3) before any C is exported.
