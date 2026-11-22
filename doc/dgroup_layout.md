# Recovered DGROUP layout: measured against the original's addresses

`audit/symbols.tsv` gives the original's DGROUP offsets.  A probe linked from the
recovered `GLOB*.OBJ` (`tmp/probe_layout.py`) prints the distances the rebuilt
image actually has:

| from | to | original | before fix | after fix |
|---|---|---|---|---|
| `AnimSeqCounts` (0x5dc8) | `lowIntelEnemies` (0x5dcf) | 7 | **3** | 7 |
| `lowIntelEnemies` | `medIntelEnemies` (0x5dd7) | 8 | **1** | 8 |
| `medIntelEnemies` | `highIntelEnemies` (0x5ddf) | 8 | **1** | 8 |
| `highIntelEnemies` | `secondWaveSize` (0x5de7) | 8 | **1** | 8 |

The rebuilt DGROUP was dense: the export declares

```c
uint8_t AnimSeqCounts[3] = { 0x5, 0x7, 0x7 };   /* 0x5dc8 */
undefined1 lowIntelEnemies = 0x05;              /* should be 4 bytes at 0x5dcf */
undefined1 medIntelEnemies = 0x03;
undefined1 highIntelEnemies = 0x02;
undefined1 secondWaveSize = 0x04;
```

but `ovc30_nextWave` indexes each of them with `Difficulty` (0..3) and the image
bytes show four 4-byte tables separated by four more 4-byte tables:

```
0x5dcb: 00 02 03 05   base counts, band 1   (no symbol in the original)
0x5dcf: 05 01 03 04   lowIntelEnemies
0x5dd3: 00 01 02 04   base counts, band 2   (no symbol)
0x5dd7: 03 00 02 02   medIntelEnemies
0x5ddb: 00 00 01 02   base counts, band 3   (no symbol)
0x5ddf: 02 00 01 02   highIntelEnemies
0x5de3: 00 01 03 04   base counts, band 4   (no symbol)
0x5de7: 04 03 05 07   secondWaveSize
0x5deb: 07            unnamed byte
0x5dec: 00 05 09 00   LevelBandMin
```

So the exported tree was 4 bytes short per band (16 bytes total), which also
shifted `LevelBandMin`, `LevelBandMax`, `demoCenterX`, `demoCenterY` and the
strings after them, and made every raw DGROUP offset in that region read the
wrong byte in our build.

Fix (in `src/decompiled/st_globals5.c`, bytes from `2410:5dcb` via
`scripts/ghidra/PeekBytes.java`): the four spreads are now `uint8_t [4]`, the
four unnamed base tables are emitted as `enemyBaseLow/Med/High/Wave[4]`
(`GUESS:` names, marked in the file), and the byte at 0x5deb is
`secondWaveExtra`.  `ovc16_saveui` stores into element 0 of each band, matching
the original's single-byte `MOV ES:[0x5dcf],DL`.

Verified by re-running the probe: `7 8 8 8`.

## Consequence for step 6

This is the first measured *data-state* divergence from `game/STRONG.EXE`, and
it is the class of bug the plan's step 6 is meant to find: the export preserves
symbols, not the addresses between them.  Any other gap in DGROUP (padding,
unnamed tables, alignment) is lost the same way, so a full address-exact export
check is required before a data-state comparison can pass.
