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
