# `7e7c:0b9c` (`constrct_buildInfoText`) — leaf-by-leaf working spec

Status: **body not written**. Call census complete (27 pairs / 185 sites, 5 unnameable). This file
records the structure and the full leaf inventory so the body can be transcribed in batches without
re-deriving anything.

## Shape

    2,938 instructions, 8,096 bytes, 96 distinct jump targets.
    42 blocks leave through 0x1f1a, 13 through 0x2b38  ->  two halves.
    79 text leaves, each of the identical form

        if (<guard>) {
          res = fmVsprintf("<literal>", <varargs...>);   /* lcall 0x170,0x4d  */
          strcpy(outBuf, res);                           /* lcall 0,0x2d31, dst = bp-0x2c8 */
          goto end;                                      /* 0x1f1a or 0x2b38 */
        }

The first `fmVsprintf` argument is the **format**; the function formats into its own ring buffer and
returns the far pointer (see the recovered body of `474a:0953` and `stSave` 49fd:090f, where the
return is passed straight to `creat`). `dst=bp-0x00` in the table below simply means "no destination
argument" - the walker found no `lea` before the call.

Line rendering before the format uses `ovc45_compute9(dst, Font03, x, y, text)` (`lcall 0x250,0x39`,
5 sites) with the sheet names from `GLeaderSheets[...]`, and `className()` for the unit class.

## Data model (fully determined)

    GUnits         stride 9    at DGROUP 0x8995 (far pointer), fields bldType/level/unitType/x/y
    Entities       stride 0x37 at DGROUP 0x908e, byte +0x1a = the owner/party index
    BuildingTypes  stride 0x27, base 0x10e of the module data segment:
                   +0 name, +4 description, +0x0c kind, +0x0d size, +0x10 flags,
                   +0x13 flags2, +0x17 cost, +0x22 durability, +0x25 unitType, +0x26 flags3
    GLeaderSheets  far pointer table at segment 0x70 (char_sheet_t, stride 0xae)

## Call map (27 pairs, 185 sites)

Resolved: `170,004d` fmVsprintf x44, `160,0025` usesStshRealloc x41, `000,2d31` strcpy x32,
`0f8,003e` say x8, `0f8,004d` inputUpdate x7, `140,0020` play_sfx x4, `000,2cc2` strcat x3,
`198,003e` ovc22_className x3 (same-module vote from `land_info`, 27 uses), `1c8,0025`
ovc28_compute2 x3, `1a0,002a` createConstructionRecordFar x2, `1a0,003e` createConstructionRecord x2,
`170,007a` stsprintf x1, and the `250,*` ovc45 accessors: compute6 x9, costOrIncomeLabel x5,
compute9 x5, compute8 x2, compute3 x2, usesGPopulationLo x2, getUnitIndex, compute7,
textChoosePartyBuild, rankPercent, usesGfxRndSeed2.

**Unresolved (5 sites)**: `198,0057` x1, `198,005c` x1, `1a8,002a` x1 (co-residency maps it to
`ovc24_checkStrongholds`, a 3-byte stub of the wrong module for text), `1f8,002a` x2.

## Leaf inventory

The table below is produced by `tmp/leaves_0b9c.py` from `tmp/o47_0b9c.txt`; each row is one
`fmVsprintf`/`strcpy` pair with the literal at its DGROUP address.

`
text leaves: 79
7e7c:0d75   fmVsprintf  fmt=0x7a45 '%s (%d/%d): Owned by %s. Active party is %s the %s.'  dst=bp-0x00
7e7c:0d85   strcpy      fmt=0x7a45 '%s (%d/%d): Owned by %s. Active party is %s the %s.'  dst=bp-0x2c8
7e7c:0e68   fmVsprintf  fmt=0x7a79 '%s: Owned by %s. Active party is %s the %s.'          dst=bp-0x00
7e7c:0e78   strcpy      fmt=0x7a79 '%s: Owned by %s. Active party is %s the %s.'          dst=bp-0x2c8
7e7c:0ef8   fmVsprintf  fmt=0x7aa5 '%s: Active party is %s the %s.'                       dst=bp-0x00
7e7c:0f08   strcpy      fmt=0x7aa5 '%s: Active party is %s the %s.'                       dst=bp-0x2c8
7e7c:114a   fmVsprintf  fmt=0x7af9 '%s: Costs %d gold of income. Replaces broken weapons' dst=bp-0x00
7e7c:115a   strcpy      fmt=0x7af9 '%s: Costs %d gold of income. Replaces broken weapons' dst=bp-0x2c8
7e7c:11ad   fmVsprintf  fmt=0x7b2f '%s: Costs %d gold of income. Forges +%d weapons.'     dst=bp-0x00
7e7c:11bd   strcpy      fmt=0x7b2f '%s: Costs %d gold of income. Forges +%d weapons.'     dst=bp-0x2c8
7e7c:1247   fmVsprintf  fmt=0x7b60 '%s: Costs %d gold of income. Improves armor.'         dst=bp-0x00
7e7c:1257   strcpy      fmt=0x7b60 '%s: Costs %d gold of income. Improves armor.'         dst=bp-0x2c8
7e7c:12c5   fmVsprintf  fmt=0x7b8d '%s: Costs %d gold of income. Improves armor class by' dst=bp-0x00
7e7c:12d5   strcpy      fmt=0x7b8d '%s: Costs %d gold of income. Improves armor class by' dst=bp-0x2c8
7e7c:1360   fmVsprintf  fmt=0x7bc7 '%s: Costs %d gold of income. Replaces broken bows.'   dst=bp-0x00
7e7c:1370   strcpy      fmt=0x7bc7 '%s: Costs %d gold of income. Replaces broken bows.'   dst=bp-0x2c8
7e7c:13c3   fmVsprintf  fmt=0x7bfa '%s: Costs %d gold of income. Creates +%d bow and arr' dst=bp-0x00
7e7c:13d3   strcpy      fmt=0x7bfa '%s: Costs %d gold of income. Creates +%d bow and arr' dst=bp-0x2c8
7e7c:1441   fmVsprintf  fmt=0x7c33 '%s: Costs %d gold. Increases unit size of five units' dst=bp-0x00
7e7c:1451   strcpy      fmt=0x7c33 '%s: Costs %d gold. Increases unit size of five units' dst=bp-0x2c8
7e7c:14bc   fmVsprintf  fmt=0x7c6f '%s: Costs %d gold. Increases building speed by %d0%%' dst=bp-0x00
7e7c:14cc   strcpy      fmt=0x7c6f '%s: Costs %d gold. Increases building speed by %d0%%' dst=bp-0x2c8
7e7c:1523   fmVsprintf  fmt=0x7ca5 '%s: Costs %d gold. Enhances training by %d%%.'        dst=bp-0x00
7e7c:1533   strcpy      fmt=0x7ca5 '%s: Costs %d gold. Enhances training by %d%%.'        dst=bp-0x2c8
7e7c:159e   fmVsprintf  fmt=0x7cd3 '%s: Costs %d gold. Produces +%d rings of protection.' dst=bp-0x00
7e7c:15ae   strcpy      fmt=0x7cd3 '%s: Costs %d gold. Produces +%d rings of protection.' dst=bp-0x2c8
7e7c:1600   fmVsprintf  fmt=0x7d08 '%s: Costs %d gold. Produces mirrors for medusae comb' dst=bp-0x00
7e7c:1610   strcpy      fmt=0x7d08 '%s: Costs %d gold. Produces mirrors for medusae comb' dst=bp-0x2c8
7e7c:1662   fmVsprintf  fmt=0x7d5c '%s: Costs %d gold. Attracts new units to this locati' dst=bp-0x00
7e7c:1672   strcpy      fmt=0x7d5c '%s: Costs %d gold. Attracts new units to this locati' dst=bp-0x2c8
7e7c:16da   fmVsprintf  fmt=0x7d94 '%s: Costs %d gold. Provides %u units of gold storage' dst=bp-0x00
7e7c:16ea   strcpy      fmt=0x7d94 '%s: Costs %d gold. Provides %u units of gold storage' dst=bp-0x2c8
7e7c:173c   fmVsprintf  fmt=0x7dca '%s: Costs %d gold. Claim trees automatically.'        dst=bp-0x00
7e7c:174c   strcpy      fmt=0x7dca '%s: Costs %d gold. Claim trees automatically.'        dst=bp-0x2c8
7e7c:179e   fmVsprintf  fmt=0x7df8 '%s: Costs %d gold. Repairs buildings at season chang' dst=bp-0x00
7e7c:17ae   strcpy      fmt=0x7df8 '%s: Costs %d gold. Repairs buildings at season chang' dst=bp-0x2c8
7e7c:182d   fmVsprintf  fmt=0x7e30 '%s: Trades %d food for gold. Total trade is %d food.' dst=bp-0x00
7e7c:183d   strcpy      fmt=0x7e30 '%s: Trades %d food for gold. Total trade is %d food.' dst=bp-0x2c8
7e7c:18ad   fmVsprintf  fmt=0x7e65 '%s: Creates %d gold of income, and accesses %d%% of ' dst=bp-0x00
7e7c:18bd   strcpy      fmt=0x7e65 '%s: Creates %d gold of income, and accesses %d%% of ' dst=bp-0x2c8
7e7c:1929   fmVsprintf  fmt=0x7eaa '%s: Costs %d gold of income and provides visibility ' dst=bp-0x00
7e7c:1939   strcpy      fmt=0x7eaa '%s: Costs %d gold of income and provides visibility ' dst=bp-0x2c8
7e7c:19a1   fmVsprintf  fmt=0x7f01 '%s: Costs %d gold of income and provides storage for' dst=bp-0x00
7e7c:19b1   strcpy      fmt=0x7f01 '%s: Costs %d gold of income and provides storage for' dst=bp-0x2c8
7e7c:1a19   fmVsprintf  fmt=0x7f3f '%s: Costs %d gold of income and provides storage for' dst=bp-0x00
7e7c:1a29   strcpy      fmt=0x7f3f '%s: Costs %d gold of income and provides storage for' dst=bp-0x2c8
7e7c:1acc   fmVsprintf  fmt=0x7f7d '%s: Provides housing for %d %s and storage for %d fo' dst=bp-0x00
7e7c:1adc   strcpy      fmt=0x7f7d '%s: Provides housing for %d %s and storage for %d fo' dst=bp-0x2c8
7e7c:1b34   fmVsprintf  fmt=0x7fb5 '%s: Provides housing for %d %s.'                      dst=bp-0x00
7e7c:1b44   strcpy      fmt=0x7fb5 '%s: Provides housing for %d %s.'                      dst=bp-0x2c8
7e7c:1bea   fmVsprintf  fmt=0x7f7d '%s: Provides housing for %d %s and storage for %d fo' dst=bp-0x00
7e7c:1bfa   strcpy      fmt=0x7f7d '%s: Provides housing for %d %s and storage for %d fo' dst=bp-0x2c8
7e7c:1c52   fmVsprintf  fmt=0x7fb5 '%s: Provides housing for %d %s.'                      dst=bp-0x00
7e7c:1c62   strcpy      fmt=0x7fb5 '%s: Provides housing for %d %s.'                      dst=bp-0x2c8
7e7c:1ce9   fmVsprintf  fmt=0x7fd5 '%s: %s %d gold. Feeds %d %s.'                         dst=bp-0x00
7e7c:1cf9   strcpy      fmt=0x7fd5 '%s: %s %d gold. Feeds %d %s.'                         dst=bp-0x2c8
7e7c:1dad   fmVsprintf  fmt=0x7ff2 '%s: %s %d gold. provides housing for %d %s and feeds' dst=bp-0x00
7e7c:1dbd   strcpy      fmt=0x7ff2 '%s: %s %d gold. provides housing for %d %s and feeds' dst=bp-0x2c8
7e7c:1e28   fmVsprintf  fmt=0x7fd5 '%s: %s %d gold. Feeds %d %s.'                         dst=bp-0x00
7e7c:1e38   strcpy      fmt=0x7fd5 '%s: %s %d gold. Feeds %d %s.'                         dst=bp-0x2c8
7e7c:1eac   fmVsprintf  fmt=0x802e '%s: %s %d gold. Provides housing for %d %s.'          dst=bp-0x00
7e7c:1ebc   strcpy      fmt=0x802e '%s: %s %d gold. Provides housing for %d %s.'          dst=bp-0x2c8
7e7c:1f02   fmVsprintf  fmt=0x805a '%s: %s %d gold.'                                      dst=bp-0x00
7e7c:1f12   strcpy      fmt=0x805a '%s: %s %d gold.'                                      dst=bp-0x2c8
7e7c:200e   fmVsprintf  fmt=0x8072 ' Salvage value %d gold.'                              dst=bp-0x2f0
7e7c:201e   strcat      fmt=0x8072 ' Salvage value %d gold.'                              dst=bp-0x2c8
7e7c:213e   fmVsprintf  fmt=0x809a ' Repair costs %d gp.'                                 dst=bp-0x00
7e7c:214e   strcat      fmt=0x809a ' Repair costs %d gp.'                                 dst=bp-0x2c8
7e7c:21ff   fmVsprintf  fmt=0x80b7 ' Upgrade costs %d gp.'                                dst=bp-0x00
7e7c:220f   strcat      fmt=0x80b7 ' Upgrade costs %d gp.'                                dst=bp-0x2c8
7e7c:23c8   fmVsprintf  fmt=0x80f0 '%s will be salvaged for %d gold. Are you sure?'       dst=bp-0x00
7e7c:2425   fmVsprintf  fmt=0x811f 'Get rid of %s permanently. Are you sure?'             dst=bp-0x00
7e7c:25ce   fmVsprintf  fmt=0x8148 '%s is being filled.'                                  dst=bp-0x00
7e7c:2630   fmVsprintf  fmt=0x815c '%s salvaged for %d gold.'                             dst=bp-0x00
7e7c:2739   fmVsprintf  fmt=0x8175 '%s is demolished.'                                    dst=bp-0x00
7e7c:27f3   fmVsprintf  fmt=0x8187 '%s does not have enough gold.'                        dst=bp-0x00
7e7c:2858   fmVsprintf  fmt=0x81a5 '%s repaired.'                                         dst=bp-0x00
7e7c:2986   fmVsprintf  fmt=0x8187 '%s does not have enough gold.'                        dst=bp-0x00
7e7c:2a07   fmVsprintf  fmt=0x81cf '%s upgraded.'                                         dst=bp-0x00
`

## Transcription rules (derived from leaves 1-3, valid for the whole function)

Argument order is plain `cdecl`: the **last push is the first argument**, and the `add sp,N` after each
call confirms how many bytes that call consumed, which is what makes a leaf unambiguous when several
calls are nested in one expression. The idioms, all confirmed against the image:

    className(idx)                  push idx; lcall 0x198,0x3e; add sp,2      -> far char * in DX:AX
    ovc45_compute9(dst,font,x,y,s)  push s(4) x(2) y(2) font(4) dst(4); lcall 0x250,0x39; add sp,0x10
    ovc45_compute7(level,durab)     push durab(2) level(2); lcall 0x250,0x98; add sp,4  -> word in AX
    usesStshRealloc(name)           push far name(4); lcall 0x160,0x25; add sp,4 -> far char * in DX:AX
    fmVsprintf(fmt,...)             push args..., fmt(4); lcall 0x170,0x4d; add sp,N -> far char * ring buf
    strcpy(outBuf,res)              res(4), then outBuf(4); lcall 0,0x2d31; add sp,8

Locals: `[bp-0x24]` unitIdx (`getUnitIndex(GfxRndSeed2, x)`), `[bp-0x1f]` bldType
(`usesGfxRndSeed2(&x)`), `[bp-0x20]` owner party index (`Entities[arg4].byte_0x1a`),
`[bp-0x27]` done flag, `[bp-0x14]` x, and the text buffers `[bp-0xc8]`, `[bp-0x78]`, `[bp-0xb2]`.
`outBuf` is always `[bp-0x2c8]`.

## Leaves 1-3 (transcribed)

**Leaf 1** — `7e7c:0c0f`, format `0x7a45`, ends `jmp 0x1f1a`.

    if (GUnits[unitIdx].unitType == 0xff) goto L_e86;          /* -> leaf 3 */
    if (BuildingTypes[bld].durability == 0x64) goto L_d90;     /* -> leaf 2 */
    t     = className(Entities[arg4].byte_0x1a);
    line1 = ovc45_compute9(&bufC8, Font03, 0x46, 3, (char far *)GLeaderSheets[owner]);
    line2 = ovc45_compute9(&buf78, Font03, 0x46, 2, (char far *)GLeaderSheets[GUnits[unitIdx].unitType]);
    n     = ovc45_compute7(GUnits[unitIdx].level, BuildingTypes[bld].durability);
    res   = fmVsprintf("%s (%d/%d): Owned by %s. Active party is %s the %s.",
                       usesStshRealloc(BuildingTypes[bld].name), n,
                       BuildingTypes[bld].durability, line2, line1, t);
    strcpy(outBuf, res);

  (stack at the call: 4+4+2+4+4+4 = 22 plus fmt 4 = 26? the image's `add sp,0x18` = 24, i.e.
  fmt 4 + name 4 + n 2 + durability 2 + line2 4 + line1 4 + t 4 = 24 - the durability push at
  `0cf8` is the `%d` copy, `n` is the compute7 result.)

**Leaf 2** — `7e7c:0d90`, reached only when `durability == 0x64`, format `0x7a79`, ends `jmp 0x1f1a`.

    t     = className(Entities[arg4].byte_0x1a);
    line1 = ovc45_compute9(&bufC8, Font03, 0x46, 3, (char far *)GLeaderSheets[owner]);
    line2 = ovc45_compute9(&buf78, Font03, 0x46, 2, (char far *)GLeaderSheets[GUnits[unitIdx].unitType]);
    res   = fmVsprintf("%s: Owned by %s. Active party is %s the %s.",
                       usesStshRealloc(BuildingTypes[bld].name), line2, line1, t);
    strcpy(outBuf, res);

  (`add sp,0x14` = 20 = fmt 4 + name 4 + line2 4 + line1 4 + t 4.)

**Leaf 3** — `7e7c:0e86`, reached only when `GUnits[unitIdx].unitType == 0xff`, format `0x7aa5`,
ends `jmp 0x1f1a`. Note the different line y (`0x55` instead of `0x46`) and that both the render and
the class look-up use the *owner* sheet, not the unit type:

    t    = className(owner);
    line = ovc45_compute9(&buf78, Font03, 0x55, 3, (char far *)GLeaderSheets[owner]);
    res  = fmVsprintf("%s: Active party is %s the %s.",
                      usesStshRealloc(BuildingTypes[bld].name), line, t);
    strcpy(outBuf, res);

  (`add sp,0x10` = 16 = fmt 4 + name 4 + line 4 + t 4.)

## Batch status

    leaves  1-3   transcribed above (7e7c:0c0f, 0d90, 0e86)   dst 0x2c8
    leaves  4-79  pending: the per-building-type chain 7e7c:0f16..2b38; the literal for each is
                  already listed in the inventory above, so each batch needs only its guard and the
                  vararg expressions, resolved with the rules in this section.

Leaves 1-3 are the "head" of the function: a shared preamble that reports ownership when the square is
occupied. Leaves 4+ switch on the building type and emit that type's description - the same three
calls (`className`, one or two `compute9` line renders, `usesStshRealloc(name)`) followed by the
type-specific `fmVsprintf`.

