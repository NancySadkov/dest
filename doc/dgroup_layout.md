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

## Second pass: the 148-byte gap before TextBlitX is closed

`diff_dgroup.py` matched only 185 labels because TLINK writes data publics with
an extra column (`1646:0C05 idle  _S_ERROR_4__D_2410_02F5`); the pattern now
skips that column and matches **1,012 of 1,868** labels.

The tool then localised the -148 bytes to the block before `GErrorStrings`
(0x33e).  The image shows five string literals the export dropped, all already
referenced by `GErrorStrings[5]`:

```
0352 41  "Bad 'game.cfg' file. Please reconfigure."
037b 24  "Cannot find sound card."
0393 24  "Cannot find music card."
03e2 13  "Mouse error."
03ff 45  "Error %d %d.  (Give Cathryn BOTH numbers.)\n" + padding NUL
```

and one declaration that was a byte short: `s_Filename__d__s_2410_032b` is 19
bytes in the image ("Filename %d %s  \r" = 18 with a padding NUL), not 18.
Both padding NULs are explicit in the declarations, so the bytes match.
`scripts/fix_error_strings.py` does the insertion in address order.

After the fix no layout run starts between `s_fighter_unit` (0x1fa) and
`BlitRects` (0x440): the constant delta covers `BlitLetterType`, the `Id*`
tables, `GErrorStrings` and `TextBlitX`, i.e. the -148 and the following -1 are
gone.  The next candidates are the string-ordering swings around the class
names (s_mage/s_thief/s_dwarf, -100/+88/-88) and -1 at `BlitRects` (0x440).

## Third pass: 0x43f, 0x472 and s_y1_d_yn_d_y3_d_yx_d

After the error-string fix the next runs started at `BlitRects` (-1) and
`MiceFlag` (-33).  Reading the image gave three separate causes:

```
43d  00 14                     __stklen = 0x1400
43f        00                  one unnamed padding byte (BlitRects is word aligned)
440  50 bytes                  BlitRects[5]  (already byte exact)
472  32 bytes                  a 16-word table with NO references (RefsToAddrs)
492  "error(27) \r"           12 bytes
49e  "y1 %d yn %d y3 %d yx %d " 26 bytes (two terminating NULs)
```

Fixes (`scripts/fix_dgroup_0440.py` plus one declaration):

* `__stklenPad` (GUESS: unnamed byte at 0x43f),
* `lineMaskTable[16]` (GUESS name; dead data in the original, emitted only so the
  addresses after 0x472 stay exact - bytes from the image),
* `s_y1_d_yn_d_y3_d_yx_d[26]` - the image carries two NULs, not one.

Result: layout runs **181 -> 178**, and no run starts at `BlitRects`,
`s_error_27` or `MiceFlag` any more.  The next divergences are `-1` around
`GCharLevelsInc` (0x163) and `-10` at `MouseX` (0xe4), then the string-ordering
swings at `s_mage`/`s_thief`/`s_dwarf` (-100/+88/-88), which look like a
different order of the class-name table rather than lost bytes.

## Fourth pass: 0x0da and 0x161

`-10` at `MouseX` (0xe4) and `-1` at `GCharLevelsInc` (0x163).  The image:

```
0d8  00                                 bigcompFrame
0d9  00                                 TextBlitFlag
0da  86 00 93 00 A0 00 AD 00 BA 00      a 5-word table, ZERO references
0e4  02 00                              MouseX
...
161  00 00                              timePassing - a word, not a byte
163  00                                 GCharLevelsInc
```

`RefsToAddrs` on 2410:00da reports **0 references** (dead data), and on 2410:0161
reports **3** (main, draw_usesPrintf, attact_usesUpdSeason), so `timePassing` is
a word while the export had it as `undefined1`.

Fixes (`scripts/fix_dgroup_00da.py`): `textBlitTable[5]` (GUESS name, dead data,
emitted only to keep `MouseX` and everything after at the original addresses)
and `timePassing` as `uint16_t` (its uses store/compare 0 and 1, so behaviour is
unchanged).

Result: layout runs **178 -> 177**, with no run at `MouseX` or `GCharLevelsInc`.

## Fifth pass: duplicate class names and duplicate-name matching

The `-100/+88/-88` swings at `s_mage`/`s_thief`/`s_dwarf` were not lost bytes.
The original has two singular class-name tables, and Ghidra named the lower-case
one with the same symbols as the capitalised one, so the export kept only the
first of each pair:

```
0169 "Fighter" 0171 "Mage" 0176 "Cleric" 017d "Thief" 0183 "Dwarf" 0189 "Elf"
018d "Halfling" ...                                     (capitalised table)
01cd "fighter" 01d5 "mage" 01da "cleric" 01e1 "thief" 01e7 "dwarf"
01ed "elf" 01f1 "halfling"                              (lower-case table)
```

`scripts/fix_class_names.py` re-adds the five dropped lower-case strings under
address-suffixed names (the convention `s_Fighter_2410_0169` already uses).
Verified by offset, not by name: every symbol in both tables now has the same
delta (+2362).

The `diff_dgroup.py` matcher now consumes publics in address order, so duplicate
original names map to successive publics instead of all pointing at the first
one.  That removed the remaining duplicate-name noise:

    layout runs 177 -> 139, matched 977 of 1,868

The next real divergences are `-20` at `MiceOfsX` (0x4ce), `-1` at
`StshStrongDatHnd` (0x4e4), `-9` at `edgeMaskTable` (0x4f2) and `-15` at
`neighbourOfsTable` (0x502).

## Sixth pass: 0x4b8, 0x6b1 and 0x732

Three more blocks, all found by reading `PeekBytes` at the address the tool
named and comparing with the declarations:

```
04b8 22  MiceFlag (word 0) + ten unnamed words 0,0,10,16,13,12,15,16,7,10
04e1  3  s__2410_04e1 "\r" + two NULs
04e8 10  scaleTable       {10,12,6,4,2,1,1,1,1,1}
04f2 16  edgeMaskTable    {3,6,0,1,5,3,1,0,0,2,3,5,2,0,6,3}
0502  8  neighbourOfsTable{0,1,1,2,2,3,3,0}
06b1 28  "Stronghold copy protection."
06cd 32  "Turn to page #%d of the manual."      (both were missing entirely)
0732 10  an unnamed shade ramp {10,12,6,4,2,1,1,1,1,1}
0745  6  shadeTable        {10,12,6,4,2,1}
```

Note `s_ng` at 0x6ae is not a string: it labels offset 10 inside
"constructing", so adding it would have been wrong.

Layout runs **139 -> 134 -> 133 -> 132**, and the constant delta now spans 122
symbols from `bigcompFrame` (0xd8) to `cornerShadeBias`.

Remaining first divergences: `-10` at `GCharLevelsInc` was fixed; the next are
`-5` around `rowBandOrigin` (0x74b), `+32` at `MUSHandle` (0x7a2) and `-36` at
`CurMusicType` (0x7a6).

## On `grep 'char [name][N] = "'`

Measured: **885** declarations still match.  The call sites, however, already
use immediate string literals - 877 of the 885 arrays are referenced only by
their declaration and `extern` (e.g. `ovl.c` writes through
`((char *)"Divide error\r\n")[9]` while `char s_divide_error[] = "Divide
error\r\n";` sits unused in `st_globals5.c`).  So the *source* fold is done,
but the named arrays remain because they are part of the original DGROUP image.
Removing them would drop data bytes; the byte-exact representation is one
anonymous data image, not one array plus one literal (which is why each string
currently exists twice in our DGROUP).
