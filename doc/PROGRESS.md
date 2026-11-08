# Progress

Updated: 2026-11-06

Plan: [`../plan.md`](../plan.md)

## Gate status

| Gate | Status | Evidence |
|---|---|---|
| G0 ? quarantine old baseline | **PASS** | `src/decompiled` moved to `reference/decompiled_baseline`; old `gpr/` marked reference-only |
| G1 ? independent FBOV manifest | **PASS** | `scripts/fbov/model.py` produced `doc/fbov_manifest.json` and CSVs; 0 validation errors |
| G2 ? fresh Ghidra model | **PASS** | `gpr_fresh`: 133 blocks, 756 trampolines, 13,367 fixups, 1,814 MZ relocations |
| G3 ? reference audit | **PASS** | `scripts/fbov/audit_refs.py`: 0 errors; 18 null-target relocations documented |
| G4 ? data/global model | **PASS** | DGROUP byte-identical under TC30 (0/38,042 differences); 1,205 symbols/types applied |
| G5 - startup/`main` byte-exact | **PASS for `main` and all 51 overlays** | `mkp` byte-exact; `main` 2246 bytes byte-exact; all 51 overlay code regions whole-region byte-exact (call operands masked) |
| G6 ? link | **PARTIAL** | flat development EXE links and boots to the game's startup configuration screen; see `doc/flat_build.md`. Not yet fully runnable past sound setup. |
| G7 ? runtime equivalence | NOT STARTED | |

## Source layout

The active reversed tree lives directly in `src/`: one `ov_<seg>.c` per
original overlay module, `main.c`, `dgroup.c`/`dgroup.h`, `st_types.h`,
`st_compat.h`, and chunked sources under `src/chunks/<seg>/`.  The early 2024
partial rewrite (old `src/init.c`, `src/util.c`, `src/build.BAT`, ...) is
quarantined in `reference/legacy_src/` and is not built.

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

This is the model the fresh Ghidra program will be built from ? not the
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

### Phase 4 results

DGROUP `0x2410:0000..0x9499` is recovered completely:

- 1,205 named symbols with recovered types and exact initialisers;
- 257 gap byte-arrays covering every remaining byte;
- 38,042 / 38,042 bytes accounted for exactly once;
- `src/dgroup.c` and `dgroup.h` generated reproducibly by
  `scripts/fbov/gen_dgroup.py`.

TC30 verification (`DGROUP.OBJ`):

- 1,160 exported symbols matched against `doc/dgroup_map.csv`;
- **0 symbol-offset mismatches**;
- **0 byte differences** in the full `0x949A` DGROUP segment.

The Ghidra map (`ApplyDgroupMap.java`) applied all 1,205 names/types to
`gpr_fresh`. The decompiler now uses `GMenuItem`, `CrossBlitPtr`, `GWorkDir`,
etc. instead of raw `DAT_2410_*` offsets.

The source file keeps the original file's relative segment values (`0x1410`)
so the object is byte-identical to `STRONG.EXE`; the Ghidra view deliberately
uses the static `0x2410` values by applying the MZ relocations. See
`doc/dgroup_verify.md`.

Remaining artifacts such as `s__magic_mill_2410_68f7 + 9` are overlay segment
constants stored into pointer-typed fields in the consuming function, not
missing DGROUP data. They belong to the function/struct recovery phase.

### Phase 5 results (started)

Byte-match harness: `scripts/fbov/byte_match.py`.
Headless runner: `scripts/fbov/run_dosbox.py` (SDL dummy, `-noconsole`, hidden
window; no focus stealing).

First function verified byte-for-byte:

```
mkp   2D63:0000  22 bytes   MATCH
```

The original `mkp` is an assembly helper that normalizes `ofs:seg` into
`far_t` (`seg += ofs >> 4; ofs &= 0x0f`). The two register-register encodings
that TC30 chooses differently were emitted explicitly to match the original:

```
8B D8   mov bx,ax
03 D3   add dx,bx
```

`main` (`1301:000C`, 2,215 bytes) was missing from the fresh analysis; it is
now created and decompiled as a baseline (`tmp/main_dec.c`). It uses the
recovered DGROUP names (`GGameExe`, `GExeArg`, `GMenuItem`, ...). The next
work is its byte-matched recovery.

The first `main` prologue comparison exposed a harness requirement: an
unlinked OBJ still contains relocations for DGROUP globals (`GGameExe`,
`GExeArg`), so raw OBJ bytes legitimately differ from the linked original.

Linked harness (new):

- `scripts/fbov/link_harness.py` stages `start.asm`, `main.c`, `stubs.c` and
  the link-time DGROUP object; `scripts/fbov/link_compare.py` extracts the
  function from `OUT.MAP`/`OUT.EXE` and compares it with the original bytes.
- `scripts/fbov/gen_link_dgroup.py` emits `dglink.asm` from the verified
  DGROUP bytes. It deliberately **omits the recovered `_DATA` symbol**: when
  a TC-compiled object is linked, Turbo Link reserves the first eight DGROUP
  bytes for the C0 startup and shifts the recovered blob by 8. With the
  assembly blob first in the link and no `__DATA` definition, every DGROUP
  symbol resolves to its original offset, while the authoritative
  `dgroup.c`/`DGROUP.OBJ` remains untouched for G4.

`main` prologue is now byte-exact:

```
main  1301:000C  0x50 bytes  MATCH
```

The accepted region covers `PUSH BP` through the `argc < 2` branch and its
`JMP` (`0x000C..0x005B`). It includes the 4-byte local (`SUB SP,4`), the two
far stores through `ES = 0x1410`, and the default `_DS:0x94` argument. The
default is the empty string at DGROUP offset `0x94` (`s__2410_0094`).

### Original compiler flags (new, important)

Comparing candidate codegen against the original established the build flags:

```
-ml -1 -G
```

- `-ml` large model (far code, far data pointers);
- `-1` 80186/286 instructions: the original uses `6A xx` (`push imm8`) for
  constant arguments; without `-1` TC30 emits `xor ax,ax; push ax`;
- `-G` generate for speed: without `-G`, TC30 with `-1` emits `ENTER` for
  functions with locals; the original uses `PUSH BP; MOV BP,SP; SUB SP,N`.

With `-ml -1 -G`, the `main` initialisation sequence is also byte-exact:

```
main  1301:000C  0x150 bytes  MATCH
```

That covers the prologue, the argument setup, the startup calls, the initial
DGROUP stores (`GGameExe`, `GExeArg`, `GMenuItem`, `GGameState`, ...), the
`unsigned char` busy-wait loop (`while (!f())`), the debug `"%d \r"` calls,
and the first `0xFFFF` check. Only direct call operands are masked (their
target segments are recovered later). The `switch (key)` follows at `0x150`.

The 4-byte local is `unsigned char sel; volatile unsigned key;`: `sel` lands
at `[bp-1]`, `key` at `[bp-4]`. `key` is volatile so TC keeps it in memory.

### `main` switch (in progress)

The switch at `0x150` is a TC binary-search dispatch tree over **59 case
values** with **28 bodies**. The case values and target bodies were extracted
from the original tree; a standalone `switch` with the same cases reproduces
the tree's comparison order exactly. Key detail: `key` must be **unsigned**
(the original uses `jbe`/`ja`, not `jle`/`jg`).

**`main` is now fully matched:**

```
main  1301:000C  2246 bytes  MATCH
```

Every instruction byte and every internal jump (short and near) matches the
original. The only masked bytes are the 240 operand bytes of direct
`CALLF` instructions whose target segments are not recovered yet. The
recovered source is `src/main.c`. It covers the whole function:
argument setup, startup calls, the `for(;;)` loop, the entire 59-case/28-body
switch, the `0x3920` battle/pause body, the menu-selection bodies, and the
loop tail.

Notes on code shape (all required for the match):

- DGROUP accesses use the original `ES = 0x1410` convention; `DB`/`DW`/
  `A90DE`/`A9082` macros expand to the original far accesses.
- The 4-byte frame is `unsigned char sel; volatile unsigned key;`
  (`sel` at `[bp-1]`, `key` at `[bp-4]`).
- Menu validity tables are indexed as far arrays (`A90DE[...]`,
  `A9082[...]`), which makes TC fold the base into the displacement
  (`es:[bx-0x6f22]` / `es:[bx-0x6f7e]`).
- Guard-clause shapes (`if (GMenuItem > 4) break;`) reproduce the original
  out-of-line bodies; several case tails carry an extra unreachable
  `break;`, matching the original's extra `jmp`.
- The loop tail uses an explicit `L_loop:` label and `goto` so `continue`
  jumps directly to `0x00C8` instead of through an intermediate label.

The link-time DGROUP object takes its labels directly from `DGROUP.OBJ`'s
PUBDEFs (1,461 symbols) instead of `dgroup_map.csv`, because the CSV omits
some gap arrays used by `main` (`gap_2410_009A`).





### Overlay recovery (started)

The first overlay module recovered is **OVC_09**, code segment `0x3381`,
file offset `0x25610`. Its header trampolines map `main`'s calls, e.g.
`main`'s `0x12E3:0x0025` -> `0x3381:0x0579`.

Overlay code requires an extra **`-O`** flag (the `main` module matches
without it). Two comparison paths are used:

- `scripts/fbov/ov_compare.py` for standalone objects (no near DGROUP symbol
  relocations);
- the linked harness (`tmp/ov_link.py` / `link_compare.py`) for functions such
  as `f_3381_01c8` whose near string pointers are link-time relocations.

Byte-exact overlay functions in `src/ov_3381.c`:

```
0000  154 bytes      016c   92 bytes      23f9   89 bytes
009a  100 bytes      023c   17 bytes      2e9a   72 bytes
00fe   52 bytes      1fa9   17 bytes      0579  282 bytes
0132   58 bytes      20ee   19 bytes      16ef  249 bytes
01c8  116 bytes      233e   60 bytes      237a   59 bytes
1697   88 bytes      23b5   68 bytes      2452  113 bytes
1f1d  140 bytes      1fba  308 bytes      2d36  104 bytes
2d9e  252 bytes      024d  812 bytes      0693  585 bytes
08dc 3507 bytes      24c3  398 bytes      2651  562 bytes
2ee2  581 bytes      2883 1631 bytes      2101  573 bytes
17e8 1845 bytes
```

All are matched with call operands (and, for `01c8`/`0579`, near call
operands) masked. `0579` is the overlay startup function `main` calls
first; two same-segment far calls are preceded by a literal `90` (`nop`)
in the original, reproduced with `asm nop`.

The four table/entity accessors (`233e`, `237a`, `23b5`, `1697`) are
byte-exact with **no masking**. TC30 was forced to keep the index in `AX`
by using `register int x, register int y` parameters (so `x`->SI,
`y`->DI) and explicit register encodings in inline asm. `1697`'s loop
uses an assembly body so the counter stays in `CX` exactly as in the
original.



## Next

1. Finish OVC_09 (`3381`): recover the remaining trampoline targets
   (`024d`, `2d9e`, `1fba`, `17e8`, `0693`, `08dc`, `2101`, `24c3`,
   `2651`, `2883`, `2ee2`, ...).
2. Continue with the other overlay headers used by `main` (`0x23E3`,
   `0x2347`, `0x23D5`, ...), then the resident startup/init chain.
3. Repair `OVC23` (`55FE:0000`) alongside the function queue.
4. G6: link the recovered modules against the original runtime/overlay
   manager.
5. G7: runtime equivalence under the DOSBox harness.


### OVC_09

31/31 trampoline targets byte-exact (13,003 bytes). Source: `src/ov_3381.c`.

### OVC_12 (code segment 2E25)

22/22 trampoline targets byte-exact. Source: `src/ov_2e25.c`.
Covers all six `main` calls through header `0x12BB` (`0x43`, `0x52`, `0x57`, `0x5C`, `0x61`, `0x84`).

### OVC 12C4 (code segment 302D)

15 functions covering the full 2,799-byte code region, byte-exact.

### OVC 13B6 (code segment 6616)

6 functions covering the full 5,091-byte code region, byte-exact.

### OVC 13E3 (code segment 6D7A)

12 functions covering the full 8,297-byte code region, byte-exact.

### OVC 1391 (code segment 6018)

16 functions covering the full 5,454-byte code region, byte-exact.

### OVC 1315 (code segment 3F0B)

35 functions covering the full 11,419-byte code region, byte-exact.

### OVC 12F8 (code segment 3A5B)

13 functions covering the full 2,859-byte code region, byte-exact.

### OVC 1347 (code segment 49FD)

8 functions covering the full 3,947-byte code region, byte-exact.

### Full code-region recovery (13 overlays)

The sequential generator now emits every function in address order, and
switch jump tables are reproduced with real C `switch` statements (raw case
bodies plus `default:`/`goto` shapes as needed). Verified whole-region
byte equality with call operands masked:

| Header | Code segment | Bytes | Source |
|---|---|---|---|
| 12BB | 2E25 | 7,628 | `ov_2e25.c` |
| 12E3 | 3381 | 12,583 | `ov_3381.c` |
| 12C4 | 302D | 2,799 | `ov_302d.c` |
| 12F8 | 3A5B | 2,859 | `ov_3a5b.c` |
| 1315 | 3F0B | 11,419 | `ov_3f0b.c` |
| 1322 | 4207 | 12,152 | `ov_4207.c` |
| 1347 | 49FD | 3,947 | `ov_49fd.c` |
| 1356 | 4D05 | 13,414 | `ov_4d05.c` |
| 1391 | 6018 | 5,454 | `ov_6018.c` |
| 13B6 | 6616 | 5,091 | `ov_6616.c` |
| 13D5 | 6A8F | 10,867 | `ov_6a8f.c` |
| 13E3 | 6D7A | 8,297 | `ov_6d7a.c` |
| 1400 | 7E7C | 12,142 | `ov_7e7c.c` |

`ov_2e25.c` and `ov_3381.c` use DGROUP symbols, so they are verified through
the linked harness (padded `_DATA` so code-segment group offset is zero).
The remaining overlay headers are next.

### Additional fully recovered overlays (26)

Whole code region byte-exact (call operands masked):

```
30e6 1972   3168  288    317e 5191   32c9 1736
3338 1102   36ce 13282  3b1d 7684   3d16 7476
474a 5310   5943 8063   5b66 7145   5d45 2583
5ded 8454   6190  173   619c 2787   6316 1735
676c 1534   67d1  311   67e7 2919   68ac 1423
690b 2834   69c8 2939   6ffe 30021  7a57 15626
81b9 17997  8adb  352
```

`317d` is an empty code segment (0 bytes).

### Remaining overlays complete

All 51 overlay code regions are now byte-exact. The last group uses
per-table TASM data modules interleaved with C function chunks:

| Header | Code segment | Bytes |
|---|---|---|
| 12A6 | 2D63 | 3,094 |
| 132E | 4528 | 8,097 |
| 1342 | 48AC | 4,889 |
| 134C | 4B0A | 7,553 |
| 1363 | 5087 | 20,957 |
| 136F | 55FE | 12,536 |
| 13A0 | 6257 | 2,812 |
| 13AC | 6386 | 9,673 |
| 13E9 | 6FBE | 938 |
| 13F1 | 77EB | 9,319 |
| 1408 | 8699 | 16,332 |

Chunked sources and table modules are under `src/chunks/<seg>/`.
`scripts/fbov/chunk_build.py` splits the generated C at each data gap and
emits a TASM module for the gap bytes; TLINK then concatenates
`chunk, table, chunk, ...` in order. Functions with a manual frame and a
`pop bp` epilogue are emitted frameless with the `sub sp` bytes inline.

### Refactoring (started)

Raw-asm bodies are being replaced with C one function at a time, with the
whole overlay region re-verified after each change. First conversions in
`ov_4207.c`:

- `f_4207_0462` -> `StshSprites = f_170_0043(0x3650, 0);`
- `f_4207_0b55` -> unsigned loop over a far `0x50:0` array
- `f_4207_1c79` -> `strcpy` + `tolower` wrapper

Full `4528` code region still matches 0 diffs.

`doc/resident_functions.md` maps the resident `0x1000` offsets to their
Borland runtime symbols (`_printf`, `_strcpy`, `_strlen`, `_memset`,
`LDIV@`, `SCOPY@`, ...). The resident segments are runtime/overlay-manager
code and will be linked from the original TC30 libraries during G6.

Refactoring batch 2 (`ov_4d05.c`):

- `f_4d05_01a3` -> `while (n--) sum += f_170_005c(max) + 1;`
- `f_4d05_118b` -> threshold mapping returning `0xfd..3`

Whole `4D05` region still matches (0 diffs). `4207` remains 0 diffs
through the linked harness after adding the `StshSprites` initialiser.

Refactoring batch 3 (`ov_6a8f.c`):

- `f_6a8f_0246` -> nested far-pointer byte increment
- `f_6a8f_0000`, `f_6a8f_0017` -> pointer selectors into `gap_2410_6DCE`
- `f_6a8f_04a9` -> flipped pointer selector

Whole `6A8F` region still matches (0 diffs) through the linked harness.
Duplicate stubs now defined by the recovered source were removed.

Refactoring batch 4 (`ov_6a8f.c`):

- `f_6a8f_0229` -> guarded nested call
- `f_6a8f_0b0a` -> compare helper with `f_148_004d`
- `f_6a8f_297d` -> two-call wrapper
- `f_6a8f_01e7`/`22cb` signatures adjusted to their real arguments

Whole `6A8F` region still matches (0 diffs) through the linked harness.

Refactoring batch 5 (`ov_6a8f.c`):

- `f_6a8f_1a4c` -> four `memcpy` calls into DGROUP tables, using
  `gap_2410_6DCE` for the near source strings

Whole `6A8F` region still matches (0 diffs) through the linked harness.

Refactoring batch 6 (`ov_7e7c.c`):

- `f_7e7c_0000` -> nested `.6e`-style scan loop calling
  `f_198_0039(i, &a)`, with the DGROUP count read through `ES = 0x280`

Whole `7E7C` region still matches (0 diffs) through the linked harness.
Duplicate `f_7e7c_004b` stub removed.

Refactoring batch 7 (`ov_6a8f.c`):

- `f_6a8f_01e7` -> guarded `printf` + nested counter decrement

Whole `6A8F` region still matches (0 diffs) through the linked harness.

Refactoring batch 8 (`ov_6a8f.c`):

- `f_6a8f_0a45` -> threshold selector returning `0x0d/0x0b/0x09/0x07/0x02`
- `f_6a8f_0aa7` -> guard-clause dispatch calling `f_190_0057(2..4, 6)`

Whole `6A8F` region still matches (0 diffs) through the linked harness.

Refactoring batch 9 (`ov_77eb.c`):

- `f_77eb_1ba2` -> `x == 1 ? 0 : 1`
- `f_77eb_2257` -> pointer selector for `x <= 0`

Whole `77EB` region still matches (0 diffs) through the chunked link.
Chunk sources under `src/chunks/77eb` regenerated.

Refactoring batch 10:

- `48ac:0000` -> `f_118_002a` with an ES-relative far pointer + flag set
- `48ac:0027` -> guarded `f_118_002a` with a DS-relative far pointer
- `4b0a:024e` -> two `f_170_0070` calls, one through a stored far pointer
- `4b0a:112d` -> local far pointer + single 32-bit zero store

Whole `48AC` and `4B0A` regions still match (0 diffs).
`4B0A:112d` also confirmed the 32-bit-zero source shape (`unsigned long` store).

Refactoring batch 11 (`ov_4b0a.c`):

- `f_4b0a_0b75` -> `1000000L / (0x100 - x)`; the compiler emits the
  `LDIV@` helper call with its own cleanup, matching the original

Whole `4B0A` region still matches (0 diffs).

## Flat development build

A resident-overlay-loader development EXE now compiles, links and runs.  It
reaches the real startup screen, ENTER switches to 320x400 and initialises the
game cache/free list (`DGROUP:0x47FA`, original `0x478E:8` vs rebuild
`0x6CC2:8`).  On the next key the game requests a 73,999-byte block and the
rebuild's smaller free-memory window makes both `farmalloc` and the game pool
fail, so it prints `Error 0 20`; the original continues into its 16-colour
intro.  The gap is the 192 KiB fixed slot pool (rebuild ~300 KiB free vs
original ~500 KiB); the next step is a variable-size packed pool or real
VROOMM-style swapping.  See [flat_build.md](flat_build.md).

## Decision: run under the original VROOMM

The flat slot loader is a diagnostic scaffold.  The runnable target keeps the
original VROOMM manager, because it reproduces the original overlay buffer
segments, load/retry policy and conventional-memory profile exactly.

Requirements for the VROOMM-mode build:

1. restore the C0 `__OvrInit` init-table entry (do not replace it);
2. build a layout-preserving image with the original segment table and a valid
   FBOV trailer (the original FBOV while the recovered code is byte-exact);
3. keep the original overlay header stubs (`CD 3F <ov> <entry>`), not the flat
   loader's private encoding;
4. every overlay segment reference must be present in the FBOV fixup tables,
   so raw `asm db` references must become symbolic before compiled C is
   substituted.

Route: byte-exact reconstruction first (all recovered regions are already
verified), then replace functions one at a time, keeping the segment layout
and the FBOV valid.  The flat loader remains available for ad-hoc checks but
is no longer the target runnable build.

## VROOMM substitution milestone

The staged VROOMM build boots (startup prompt, 320x400, intro frames) and the
substitution verifier is in place.  Accepted functions are compiled from
`src/`, checked against the original bytes with only call/jump
operands allowed to differ, relocated to the original segment addresses, and
patched into the staged EXE.

The accepted set (all byte-exact; 156 pure-C overlay functions plus `main`):

```
main          1301:000C  2246  (230 call-operand bytes)
```

| Module | Accepted |
|---|---|
| `ov_2d63` | 26 |
| `ov_302d` | 9 |
| `ov_3338` | 4 |
| `ov_3381` | 12 |
| `ov_3b1d` | 11 |
| `ov_3f0b` | 24 |
| `ov_4207` | 3 |
| `ov_474a` | 16 |
| `ov_48ac` | 2 |
| `ov_4b0a` | 3 |
| `ov_4d05` | 3 |
| `ov_5087` | 20 |
| `ov_5943` | 9 |
| `ov_6a8f` | 11 |
| `ov_77eb` | 2 |
| `ov_7e7c` | 1 |

The per-function offsets and sizes are recorded in `doc/vroomm_accepted.md`.
The staged image remains byte-identical after the accepted substitutions
(as expected for byte-exact functions); the milestone is that the build path
from C source to the running VROOMM EXE is exercised for 157 recovered
functions.  `f_3381_01c8` and the remaining DGROUP-dependent functions are
accepted through the linked harness (`vroomm_verify_linked.py`), which
resolves `_DATA` offsets exactly as the original.

The wider verifier sweep also showed that many earlier converted hybrid
functions (C with small `asm db` encoding fixes) were already byte-exact; the
new recovered-function check accepts them instead of treating any `asm db` as
"not reversed".

