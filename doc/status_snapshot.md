# Recovery status snapshot

Measured by `scripts/ghidra/AuditNaming.java`; the raw output of the run quoted
here is `tmp/auditn56/naming_summary.txt`.

## Where the model stands

```
functions                1130
  no prototype            115
  weak return type        990
  has struct-typed arg     97
parameters               1659   auto-named 1229   (74.1%)
locals                    692   auto-named  317   (45.8%)
structs                    35
  struct fields           313   generated    48   (15.3%)
globals                  2533   auto-named  634   (25.0%)
```

## What is done

| area | result |
|---|---|
| string labels | 433 named from their own bytes (`doc/strings_renamed.tsv`) |
| globals | 1096 -> 634 auto-named; every rename has its quoted use in `doc/globals_naming.md` |
| structures | `spr_t` fully recovered (2 fields), `agntG_t`/`bldtp_t`/`entity_t` rebuilt from allocation sizes, strides and access widths |
| struct fields | 266 -> 48 generated |
| typing | struct-typed arguments 80 -> 97; four split-far-pointer prototypes repaired |
| corrections | six wrong names/types found by later evidence and reverted |

## What remains, and why it is not done

1. **634 globals.** Each needs its consumer read; the successful ones this
   session came from a routine that *computes* with the value
   (`strength` from `attact`'s faction totals, `rank` from the rank ladder,
   `MsgShown` from the `say()` call site, six XMS cells from the carry
   propagation). Where only a comparison exists the result has been a
   documented refusal, not a name.
2. **1229 parameters / 317 locals.** `scripts/fbov/propagate_params.py` finds
   exactly one candidate, because the callee names that would seed propagation
   are themselves `param_N`.
3. **48 struct fields.** `anm_t` 0x10-0x19/0x1d and most remaining `bldtp_t`
   bytes have **no reader in any export** (they are asset-file bytes); the four
   `agnt_t` fields inside 0x13..0x1a sit in a word/pointer overlap that Ghidra's
   structure types cannot express; the rest have a single comparison each.

## Method rules that produced this state

- Name only from a consumer that computes with the value, or from a width the
  disassembly proves.
- Check the disassembly before believing the decompiled C: six corrections came
  from doing so (`dir`->`target`, `entBase_t`, four `entity_t *` typings, the
  bare `0x33` byte, the "no split" diff, the `GMenuStrings` symbol-relative
  coincidence).
- Re-run `AuditNaming` after every batch and quote the delta.
