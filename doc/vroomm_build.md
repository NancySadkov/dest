# VROOMM build

This is the runnable target.  It keeps the original resident VROOMM manager,
the original FBOV trailer, the original overlay headers and the original
overlay blobs, so overlay buffers, load/retry behaviour and the conventional
memory profile are the original ones.

## Baseline

`scripts/fbov/vroomm_baseline.py` stages `tmp/vroomm/` with `STRONG.EXE` and
the game data.  Because every recovered code region and DGROUP are byte-exact
against the original, this first build is the byte-exact recovered scaffold:
the load module, FBOV and overlay blobs are the original ones.

Verification: under DOSBox with the saved SB configuration the staged EXE
passes the startup prompt, switches to 320x400 and renders the intro
(122-colour frame captured from the running baseline).

## Function substitution

For each recovered function:

1. Compile it with TC30 (`-ml -1 -G -O`) in its original module context.
2. Compare against the original function bytes.  Call operands are allowed to
   differ; every other byte must match.
3. Relocate the call operands to the original segment addresses.  The original
   operand words are the authoritative values; alternatively use the
   manifest's trampoline/fixup targets.
4. Patch the function into the matching overlay blob in the staged EXE.  The
   blob size and file offset must not change, and the FBOV fixup table stays
   valid, so VROOMM continues to load it unchanged.
5. Re-run the baseline and compare startup, assets and state with the original.

Functions that are not yet byte-exact stay as the original scaffold bytes;
they can be replaced when the C body passes step 2.

## Chunked modules

Most modules compile as one C translation unit in their original segment.
Modules containing functions with non-standard prologues/epilogues cannot be
reproduced by a single TC30 function body.  Those modules are split in source
order:

- `src/c<seg><n>.c` - a C chunk containing the next run of compiler-reproduced
  functions;
- `src/a<seg><n>.asm` - a TASM byte block holding one non-standard function,
  including its prologue and epilogue;
- `src/k<seg>.h` - prototypes for every function in the module.

The build compiles the chunks and assembles the byte blocks, then links the
segment parts in source order (`c<seg>0`, `a<seg>0`, `c<seg>1`, ...).  TLINK
concatenates the `OV_<seg>_TEXT` contributions, so every symbol lands at its
original offset.  The byte blocks are committed source; no original EXE is
read at build time.

## Source-only build

`scripts/fbov/build_standalone.py` builds a byte-identical `STRONG.EXE`
without opening `game/STRONG.EXE`:

1. `build_overlays.py` compiles all overlay modules and chunks in one link,
   extracts every `OV_<seg>_TEXT` segment, and applies `src/ov_patch.csv`
   (original call/jump operand and switch-table bytes).
2. The overlay code is written into the zeroed regions of
   `src/base_fbov.bin`.
3. The result is concatenated with `src/base_static.bin` and checked against
   the original SHA-256 (`aebde62f...`).

The two base blobs are transitional: they hold the static load module and the
FBOV metadata until those parts are generated from recovered source.  Overlay
code is already built from source.

## Relationship to the flat build

The flat build (`doc/flat_build.md`) is a diagnostic loader that runs the
overlay code without VROOMM.  It reached the 320x400 screen but its fixed
overlay pool leaves too little conventional memory for the game's 74 KiB
allocation.  The VROOMM build does not have this limitation because VROOMM
manages the original overlay buffer and swap policy.

## Substitution tool

`scripts/fbov/vroomm_subst.py` verifies a compiled function against the
original at its original segment:offset.  It allows differences only in
direct call/jump operands, takes those operands from the original image
(original segment addresses), writes the patched function back to the staged
EXE and rejects any unmasked difference.

Example for `main`:

```text
python scripts/fbov/vroomm_subst.py --seg 1301 --ofs 000C --len 2246 \
    --compiled tmp/linkbuild/OUT.EXE --compiled-ofs 94AB
```

Verified: `main` compiled from `src/main.c` differs from the
original only in 230 call/jump operand bytes; after relocation the staged
image is byte-identical, as expected for a byte-exact recovered function.

Overlay functions use the same verifier with an OMF object:

```text
python scripts/fbov/vroomm_subst.py --obj tmp/ovbuild/OV_3381.OBJ \
    --name f_3381_0132 --overlay-seg 3381 --ofs 0x132 --len 58
```

`f_3381_0132` (58 bytes) has 2 call-operand differences; `f_3381_233e`
(60 bytes) is exact.  Both produce a byte-identical staged image, which is the
acceptance condition for a converted function.

## Module batches

`scripts/fbov/vroomm_verify_module.py` walks every pure-C function in a
recovered module and accepts the ones whose standalone object matches:

```text
python scripts/fbov/vroomm_verify_module.py --obj tmp/ovbuild/OV_3381.OBJ \
    --seg 3381 --src src/ov_3381.c
```

A function counts as recovered when its body is more than a raw `asm db` byte
dump.  Small `asm db` encodings may still appear inside recovered code where
the compiler chooses a different but equivalent encoding (for example
`mov bx, ax` assembled as `8B D8` instead of `89 C3`).

Functions that reference `_DATA` by offset cannot be resolved in a standalone
object.  `scripts/fbov/vroomm_verify_linked.py` builds a linked harness per
module (against the recovered DGROUP), verifies those functions, and patches
them in; it prefers the standalone object when that already matches:

```text
python scripts/fbov/vroomm_verify_linked.py 3381:ov_3381 48ac:ov_48ac \
    4207:ov_4207 4b0a:ov_4b0a 4d05:ov_4d05 6a8f:ov_6a8f 77eb:ov_77eb \
    7e7c:ov_7e7c
```

Result: 504 byte-accepted overlay bodies across 51 modules, of which 126 are
real C and 378 are byte-exact manual-frame `asm db`/pad dumps.  See
`doc/recovery_status.md` for the C-versus-asm split.  After every accepted
substitution the staged image remains byte-identical to the original, which is
the expected parity result for a byte-exact function.

Note: a linked harness can shift a module's internal layout, which perturbs
segment-relative switch jump tables.  For that reason the linked bytes are
used only for functions that the layout-preserving standalone object cannot
verify.

## Full sweep

`scripts/fbov/vroomm_sweep.py` discovers every `src/ov_<seg>.c`, runs the
linked verifier for each module, writes `tmp/verify_all.log`, and refreshes
`doc/vroomm_accepted.md`:

```text
python scripts/fbov/vroomm_sweep.py --wait 20
```

A single module can still be checked directly with `vroomm_verify_linked.py`
(as shown above).  `scripts/fbov/vroomm_manifest.py` can rebuild only the
manifest from an existing log.

If the linked harness cannot be built (for example `ov_6ffe`, whose harness
DGROUP exceeds 64 KiB), the verifier falls back to the standalone OMF object
and accepts the functions that do not need DGROUP relocation.
