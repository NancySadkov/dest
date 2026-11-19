# Recovery status snapshot

Measured by `scripts/ghidra/AuditNaming.java`; the raw output quoted here is
`tmp/auditn385/naming_summary.txt`.

## Where the model stands

```
functions                1130
  no prototype            114
  weak return type        986
  has struct-typed arg    144
parameters               1643   auto-named  273   (16.6%)
locals                    692   auto-named  90   (13.0%)
structs                    35
  struct fields           308   generated    10   (3.2%)
globals                  2559   auto-named  222   (8.7%)
```

Function names are complete: 1590 functions (including 460 thunks), 0 duplicates,
0 address-shaped names (`ListFuncs.java` -> `tmp/funcs11.tsv`).  The address stays in
every exported header (`// name @ addr [module]`) and in `doc/functions_renamed.tsv`.

## What is done

| area | result |
|---|---|
| function names | 1590/1590 unique and address-free; 591 renames recorded with evidence tier |
| string labels | 1516 `s_*` labels from their own bytes (`doc/strings_renamed.tsv`) |
| globals | 1096 -> 222 auto-named (26 previously unnamed DGROUP tables labelled, 74 sprite-array symbols named from the asset table); every rename quotes its writer/consumer in `doc/globals_naming.md` |
| structures | `spr_t`, `unit_t` and `entity_t` complete; `agnt_t` rebuilt as `agnt_t[52]` + `tick` + `dir`; `bld_inst_t` and most of `char_sheet_t` recovered |
| struct fields | 266 -> 10 generated |
| typing | struct-typed arguments 80 -> 144; `_fmemmove`/`__fmovmem`/`memcpy` re-typed to `(far dst, far src, count)`; `blit_usesDrawGfx`'s rectangle parameter retyped `brect_t *`, which resolves its fields by name |
| corrections | wrong names/types found by later evidence reverted (three pointer widenings, `OVC22_5087_056e`, `anm_t` block) |

## What remains, and why it is not done

1. **222 globals.** The remainder splits three ways: no writer appears anywhere in
   the export (so the value can only be characterised from unexported code), only
   zeroing writers exist, or the value is a `stshAllocStub` block with no source
   asset.  Every rename in this session came from a writer or a gate that pins the
   meaning (`flashTickLo/Hi`, `destroyLatchSide0/1`, the audio-driver block pairs,
   the `StshNames` cut graphics); where only an equality or a lone write exists the
   result is a documented refusal.
2. **273 parameters / 90 locals.** Call-site scanning is exhausted: the unanimous
   call-role rule yields 6 multi-site candidates, all inside the two functions whose
   decompilation Ghidra flags as unstable, and 10 single-site ones that the bodies
   contradict.  The locals axe is smaller still: the same rule finds 8 candidates in
   total across 145 locals.  What remains needs per-body reading, and this session
   did 461 parameters that way (blit argument order, party-sheet indices, x/y pairs).
3. **10 struct fields.** Each group has been re-examined at least three times.  The
   two that are provably meaningful have irreducible conflicts the image cannot
   settle: `char_sheet_t+0x1b` is a word comparison widened to a dword, and
   `bldtp_t+0x0c` is a second lower bound beside the already-named `minBuildTime`.
   The rest are equality-only (`agnt_t+0x11/+0x24/+0x25/+0x2a`,
   `agntG_t+0x52/+0x94`, `agnt_t+0x13`), unread, or the `anm_t` block that
   `stshRleAnims` never touches.

## Blocked on information the binary does not carry

- `anm_t 0x13..0x18`: three signed/unsigned words with readers, no name; `0x0f`/`0x11` are now `maxDx`/`maxDy`.
- The `07xx`/`08xx` far-pointer tables in `5087:056e`: no writer, and the index
  expressions are register artifacts (`unaff_DI`, `(uint)&unaff_DI->seg % 7`) in a
  function flagged for untracked spacebase and bad instruction data.
- `OVC22_5087_056e` as a whole: self-contradictory decompilation; its parameters and
  locals are deliberately untouched.

## Verification each batch

Every batch is gated by `scripts/fbov/verify_param_names.py` (71 per-function checks,
currently `checked 71 failures 0`) and followed by a fresh `AuditNaming.java` run whose
delta is quoted in the commit message.

## Runtime instrumentation now available

The patched DOSBox-X in `emulator/` runs the original `game/STRONG.EXE` and exposes
guest memory over `127.0.0.1:23946`.  See `doc/emulator_findings.md` for the run recipe,
the `peek`/`dump`/`find` command set, and the way the runtime DGROUP is recovered
(`find "undeveloped"` -> `DGROUP = 0x1C33`, `delta = 0x7DD`; the delta changes when the
game reloads after the setup screen, so it is located per process).

What it has already settled: `AgntGs` decodes end to end (42 unit types with names and
weapons through the far pointers at `+0x24`/`+0x90`); `Agnts` is live with `gdata`
pointing into `AgntGs` (an archer record with 6/6 strength); `AgntAnms` holds the same
word values as the static image.  It has also recorded `agntG_t+0x94`'s full value
distribution (5/10/20/30/40 across the 42 types) and `agnt_t+0x11`'s writer predicate
(animation-table shape, then `randBelow(2)`).  Neither is named yet: no exported reader
exists for the first, and the second's vocabulary is still unstated.
