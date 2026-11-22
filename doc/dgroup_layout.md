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

## Systematic check: scripts/diff_dgroup.py

link_standalone.py now links with TLINK /m /s, so REBUILT.MAP lists every
public with its segment:offset.  scripts/diff_dgroup.py joins those against
udit/symbols.tsv by name and prints ours - original as a run-length list:
as long as the recovered data keeps the original's order and padding, the delta
is one constant; every change is a lost or invented gap of that many bytes.
Element labels (LevelBandMin[2]), the startup's own data (__C0argc, _psp,
rrno, ...) and duplicate names are excluded - the startup's DGROUP belongs to
C0M, not to the recovered tree.

First run: **185 matched pairs, 67 layout runs**.  The enemy-band block from
AnimSeqCounts to secondWaveSize no longer starts a new run, i.e. the fix
above holds.  The next mismatches, in file order (negative = our layout is that
many bytes short before the symbol):

`
  -1  GCharLevelsInc   0163     -31  BlitLetterType  02f2
  -148 TextBlitX       042c     -33  MiceFlag        04b8
  -20  MiceOfsX        04ce     -31  GrayscalePalette 050a
  -60  bandOrigin      0728     -10  cornerShadeBias 073c
  -5   rowBandOrigin   074b     -5   DIGHandle       079e
  +32  MUSHandle       07a2     -36  CurMusicType    07a6
  -24  DIGHandle       07ba     +20  MidGfxOfs       07be
`

The repeating -31 and -1 values point at single symbols declared too small
(an array or struct dimension), not at missing tables; -148 before TextBlitX
is the largest single loss and the first place to audit next.

Caveat: only 185 of 1,868 original labels match by name, because the recovery
renamed many symbols (s_*, G*, _uses*).  Matching by *address order*
instead of name would raise coverage; the current run already localises the
divergences to a handful of blocks.
