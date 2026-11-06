# Progress

Updated: 2026-11-06

Plan: [`../plan.md`](../plan.md)

## Gate status

| Gate | Status | Evidence |
|---|---|---|
| G0 — quarantine old baseline | **PASS** | `src/decompiled` moved to `reference/decompiled_baseline`; old `gpr/` marked reference-only |
| G1 — independent FBOV manifest | **PASS** | `scripts/fbov/model.py` produced `doc/fbov_manifest.json` and CSVs; 0 validation errors |
| G2 — fresh Ghidra model | **PASS** | `gpr_fresh`: 133 blocks, 756 trampolines, 13,367 fixups, 1,814 MZ relocations |
| G3 — reference audit | **PASS** | `scripts/fbov/audit_refs.py`: 0 errors; 18 null-target relocations documented |
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
| Segment/BSS blocks | 133 |
| Overlay code blocks | 50 |
| Trampolines untrapped | 756 |
| FBOV fixups applied | 13,367 / 13,367 |
| MZ relocation references | 1,814 / 1,832 (18 null targets) |
| DS / ES | `0x2410` |
| SS | `0x2D5A` |

The block layout is now a shared artifact: `doc/fbov_blocks.csv`.
`BuildFbovModel.java` and `audit_refs.py` consume the same file, so the loader
and the audit cannot disagree.

Verification:

- `1000:0000` reads `BA 10 24` (`MOV DX,0x2410`); the original file stores
  the relative `0x1410`. The loader rewrites every MZ relocation site.
- `2E25:0344` (a DGROUP fixup site) reads `0x2410`.
- `2E25:0380` reads `0x2315` (an overlay target).
- `_OVRDATA_` is `0x225D`, size `0x110`; `_SEGTABLE_` is `0x2277`, size
  `0x2D8`; DGROUP is `0x2410`, size `0x8900`.
- `OVC01` (`2D63:0000`) decompiles cleanly:
  `return param_1 & 0xf;`.
- `OVC02`/`draw_2e25_025a` no longer contains the
  `"puppetmaker"+3` / `"glassworks"+9` / `"arena"+n` class.
  `DecompileOptions.setInferConstantPointers(false)` keeps segment constants
  as scalars.

### Phase 3 results

`scripts/fbov/audit_refs.py` reports:

```
blocks: 133
relocs: ok=1814 null=18 bad_site=0 bad_target=0
fixups: ok=13367 bad_site=0 bad_target=0
errors: 0 notes: 18
```

The 18 notes are MZ relocation sites whose stored word is `0`; they are
genuinely null targets, not unresolved references.

Known G4 work (not loader errors):

- Three remaining `s_...+n` expressions in `draw_2e25_025a` are segment
  constants stored into pointer-typed fields (`0x22D3`, `0x6900`). They will
  become `ptr.seg = ...` once the corresponding struct/field is typed.
- `OVC23` (`55FE:0000`) still hits Ghidra's `NO ADDRESS` failure. It is a
  separate tracked-register/overlapping-instruction issue, not the segment
  model; the function has a targeted repair queue entry.

## Next

1. G4: recover the DGROUP layout, the first structs, and the globals behind
   the remaining word/segment fields.
2. Repair `OVC23` (`55FE:0000`) with a targeted re-disassembly/overlap fix.
3. Build the per-function byte-match harness (`scripts/fbov/byte_diff.py`)
   and begin at the startup/`main` chain.
4. Recover functions in dependency order; each must compile with TC30 and
   match the original instruction stream before it is accepted.
