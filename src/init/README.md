# Functional C init tree

This directory holds the recovered C for the asset-init routines:

| File | Original | Function |
|---|---|---|
| `assets.c` | `6ffe:02F7` | `init_assets` (large sprite loader) |
| `assets1.c` | `7a57:0000` | `init_assets1` |
| `assets2.c` | `81b9:0086` | `init_assets2` |

The sources originate from the Ghidra baseline in
`reference/decompiled_baseline/` and are kept here as the working functional
C reconstruction.  They compile with TC30:

```text
python scripts/fbov/build_init.py
```

Current status: **compiles** (`assets.obj`, `assets1.obj`, `assets2.obj`), but
is **not yet byte-exact** and is not linked into the standalone build.  The
byte-exact build still uses the asm blocks in `src/ov_*.c`/`src/static/`.

## Symbol mapping

| Recovered name | Active name |
|---|---|
| `init_assets` | `f_6ffe_02f7` |
| `init_assets1` | `f_7a57_0000` |
| `init_assets2` | `f_81b9_0086` |
| `ovr_stshRleCut` | `f_317e_0148` |
| `ovr_stshRleType2` | `f_317e_0168` |
| `ovr_stshStoreFile` | `f_4b0a_09ce` |
| `ovr_stshReadFile` | `f_4b0a_077a` |
| `ovr_stshWriteFile` | `f_4b0a_0721` |
| `ovr_grabLbm` | `f_30e6_0321` |
| `ovr_grabLbmTR` | `f_4b0a_01f8` |
| `ovr_stgFreeTmp` | `f_4b0a_024e` |
| `ovr_stshAlloc` | `f_474a_075a` |
| `ovr_initStshTables` | `f_474a_0a6a` |
| `ovr_animInitSeqs` | `f_6190_0000` |
| `ovr_allocSprSeqs` | `f_4207_0462` |
| `ovr_stshStubifyCopy1to0` | `f_4b0a_04a7` |
| `ovr_stshInitPtrs` | `f_6ffe_733c` |
| `ovr_stExit` | `f_3168_0000` |
| `ovr_mkp` | `f_2d63_0000` |

The active init sequence itself (`main` and `f_3381_0579`) is already C in
`src/main.c` and `src/ov_3381.c`.
