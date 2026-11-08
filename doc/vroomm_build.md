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

Verified: `main` compiled from `src/recovered/main.c` differs from the
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
