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
## Correction: 80 leaves, not 79

The inventory above counts the three *output* call types (`fmVsprintf` 44, `strcpy` 32, `strcat` 3 =
79 sites). There is one further leaf that writes straight into `outBuf` with **`stsprintf`**
(`lcall 0x170,0x7a`, 1 site) and needs no `strcpy` - leaf 4 below. So the function has **80 leaves**:
40 `fmVsprintf`+`strcpy` pairs, 3 `strcat` sites, 1 `stsprintf`, and the rest are the companion
`strcpy`/`strcat` halves of pairs already counted.

## Leaf 4 — `7e7c:0f16..0x10e4`, format `0x7ac4`, `stsprintf` into `outBuf`

Preamble that is shared by the type-specific chain (it is *not* a leaf: it computes three values used
later, then falls through to the type dispatch at `0x100c`):

    if (GUnits[unitIdx].unitType != 0xff) {
      v16 = GAP_198_0057(bld, GUnits[unitIdx].unitType, GUnits[unitIdx].x, GUnits[unitIdx].y);
      di  = GAP_198_005c(bld, GUnits[unitIdx].unitType, GUnits[unitIdx].x, GUnits[unitIdx].y);
      v18 = BuildingTypes[bld].housing;              /* +0x119? no: +0x127 = base 0x10e + 0x19 */
    } else { v16 = 0; di = 0; v18 = 0; }

  The two `GAP_*` calls are exactly the two unnameable pairs from the call map (`198,0057` and
  `198,005c`, one site each); both take four words (`push y, x, unitType, bld`) and return a word.
  `[bp-0x16]` = v16, `di` = v18's companion, `[bp-0x18]` = v18.

Leaf 4 itself, entered when `BuildingTypes[bld].unitType == 6` (base 0x10e + 0x25):

    clamp = resourceTable[BuildingTypes[bld].resource];   /* kind -> byte table at DGROUP 0x74b4 */
    switch (GLeaderSheets[owner]->cls) {
      case 4: if (clamp > 0x0c) clamp = 0x0c; break;
      case 5: if (clamp > 0x0a) clamp = 0x0a; break;
      case 6: if (clamp > 0x08) clamp = 0x08; break;
    }
    stsprintf(outBuf, "<0x7ac4>", usesStshRealloc(BuildingTypes[bld].name), -di, clamp);
    goto end;   /* 0x1f1a */

  (`add sp,0x10` = 16 = dst 4 + fmt 4 + name 4 + (-di) 2 + clamp 2.) Note the argument is `-di`
  (`mov ax,di; neg ax`), and that the y offset differs from leaves 1-3.

## Updated batch status

    leaves 1-3   transcribed (0c0f, 0d90, 0e86)
    leaf  4      transcribed (0f16 preamble + 1028 body)
    leaves 5-80  pending: the type dispatch at 0x100c walks BuildingTypes[bld].unitType through
                 1, 6, ... and each arm builds its own message; the literal for every arm is in the
                 inventory above.

## Leaves 5-45: recorded guards, formats and argument shapes

Produced by `tmp/leaf_table.py`, which simulates the stack forward from `7e7c:0b9c` (every `push`
appends, every `add sp,N`/`pop` removes) and dumps the exact frame at each `fmVsprintf`/`stsprintf`
site. The prologue's `push bp / push si / push di` are excluded from the argument list.

Reading the columns:

* **guard** - the nearest `cmp byte ptr es:[bx + 0x133]` (that is `BuildingTypes[bld].unitType`) and
  the branch that follows it. It identifies the dispatch *value* for the arm; the branch polarity
  (`je` to the body or `je` to the next arm) must be confirmed against the target when the body is
  written, because the dispatch is a chain of `cmp`/`je` pairs rather than a `switch`.
* **format** - the literal passed to `fmVsprintf`/`stsprintf` (first argument).
* **args** - the argument frame in push order, i.e. **reverse** of the C argument order. A `<dx> <ax>`
  pair is one far pointer: it is always the DX:AX return of the call immediately before it
  (`className`, a `compute9` line render, `usesStshRealloc`, `costOrIncomeLabel`, ...). `<ax>` alone
  is the AX return of the preceding call or a loaded byte (`bld.durability`, `bld.cost`,
  `GUnits[unitIdx].level`, ...), and `bld.*` entries are direct `es:[bx+...]` field loads.

| # | address | guard | format | args (push order) |
|---|---------|-------|--------|-------------------|
| 1 | 0d75 | ? | "%s (%d/%d): Owned by %s. Active party is %" | <dx> <ax> <dx> <ax> <dx> <ax> <ax> <ax> <dx> <ax> _DS "%s (%d/%d): Owned by %s. Active party is %" |
| 2 | 0e68 | ? | "%s: Owned by %s. Active party is %s the %s" | <dx> <ax> <dx> <ax> <dx> <ax> <dx> <ax> _DS "%s: Owned by %s. Active party is %s the %s" |
| 3 | 0ef8 | ? | "%s: Active party is %s the %s." | <dx> <ax> <dx> <ax> <dx> <ax> _DS "%s: Active party is %s the %s." |
| 4 | 10dc | cmp [bld.unitType],6 ; je 0x1028 | "%s: Costs %d gold and provides training to" | <ax> <ax> <dx> <ax> _DS "%s: Costs %d gold and provides training to" _SS <ax> |
| 5 | 114a | cmp [bld.unitType],1 ; je 0x1103 | "%s: Costs %d gold of income. Replaces brok" | <ax> <dx> <ax> _DS "%s: Costs %d gold of income. Replaces brok" |
| 6 | 11ad | cmp [bld.unitType],1 ; je 0x1103 | "%s: Costs %d gold of income. Forges +%d we" | <ax> <ax> <dx> <ax> _DS "%s: Costs %d gold of income. Forges +%d we" |
| 7 | 1247 | cmp [bld.unitType],0x1d ; je 0x11e7 | "%s: Costs %d gold of income. Improves armo" | <ax> <ax> <dx> <ax> _DS "%s: Costs %d gold of income. Improves armo" |
| 8 | 12c5 | cmp [bld.unitType],0x1d ; je 0x11e7 | "%s: Costs %d gold of income. Improves armo" | <ax> <ax> <dx> <ax> _DS "%s: Costs %d gold of income. Improves armo" |
| 9 | 1360 | cmp [bld.unitType],0xd ; je 0x12ff | "%s: Costs %d gold of income. Replaces brok" | <ax> <ax> <dx> <ax> _DS "%s: Costs %d gold of income. Replaces brok" |
| 10 | 13c3 | cmp [bld.unitType],0xd ; je 0x12ff | "%s: Costs %d gold of income. Creates +%d b" | <ax> <ax> <dx> <ax> _DS "%s: Costs %d gold of income. Creates +%d b" |
| 11 | 1441 | cmp [bld.unitType],0xe ; jne 0x145c | "%s: Costs %d gold. Increases unit size of " | <ax> <ax> <dx> <ax> _DS "%s: Costs %d gold. Increases unit size of " |
| 12 | 14bc | cmp [bld.unitType],0xf ; jne 0x14d7 | "%s: Costs %d gold. Increases building spee" | <ax> <ax> <dx> <ax> _DS "%s: Costs %d gold. Increases building spee" |
| 13 | 1523 | cmp [bld.unitType],0x17 ; jne 0x153e | "%s: Costs %d gold. Enhances training by %d" | <cs> <ax> <ax> <dx> <ax> _DS "%s: Costs %d gold. Enhances training by %d" |
| 14 | 159e | cmp [bld.unitType],0x10 ; jne 0x15b9 | "%s: Costs %d gold. Produces +%d rings of p" | <cs> <ax> <ax> <dx> <ax> _DS "%s: Costs %d gold. Produces +%d rings of p" |
| 15 | 1600 | cmp [bld.unitType],0x11 ; jne 0x161b | "%s: Costs %d gold. Produces mirrors for me" | <cs> <ax> <dx> <ax> _DS "%s: Costs %d gold. Produces mirrors for me" |
| 16 | 1662 | cmp [bld.unitType],0x12 ; jne 0x167d | "%s: Costs %d gold. Attracts new units to t" | <cs> <ax> <dx> <ax> _DS "%s: Costs %d gold. Attracts new units to t" |
| 17 | 16da | cmp [bld.unitType],0x13 ; jne 0x16f5 | "%s: Costs %d gold. Provides %u units of go" | <cs> bld.w12a <ax> <dx> <ax> _DS "%s: Costs %d gold. Provides %u units of go" |
| 18 | 173c | cmp [bld.unitType],0x14 ; jne 0x1757 | "%s: Costs %d gold. Claim trees automatical" | <cs> <ax> <dx> <ax> _DS "%s: Costs %d gold. Claim trees automatical" |
| 19 | 179e | cmp [bld.unitType],0x15 ; jne 0x17b9 | "%s: Costs %d gold. Repairs buildings at se" | <cs> <ax> <dx> <ax> _DS "%s: Costs %d gold. Repairs buildings at se" |
| 20 | 182d | cmp [bld.unitType],0x16 ; jne 0x1848 | "%s: Trades %d food for gold. Total trade i" | <cs> bld.b0a0 <ax> <dx> <ax> _DS "%s: Trades %d food for gold. Total trade i" |
| 21 | 18ad | cmp [bld.unitType],4 ; jne 0x18c8 | "%s: Creates %d gold of income, and accesse" | <cs> <ax> <di> <dx> <ax> _DS "%s: Creates %d gold of income, and accesse" |
| 22 | 1929 | cmp [bld.unitType],2 ; jne 0x1944 | "%s: Costs %d gold of income and provides v" | <cs> <ax> <ax> <ax> <dx> <ax> _DS "%s: Costs %d gold of income and provides v" |
| 23 | 19a1 | cmp [bld.unitType],5 ; jne 0x19bc | "%s: Costs %d gold of income and provides s" | <cs> bld.w12a <ax> <dx> <ax> _DS "%s: Costs %d gold of income and provides s" |
| 24 | 1a19 | cmp [bld.unitType],0x13 ; jne 0x1a34 | "%s: Costs %d gold of income and provides s" | <cs> bld.w12a <ax> <dx> <ax> _DS "%s: Costs %d gold of income and provides s" |
| 25 | 1acc | cmp [bld.unitType],0 ; je 0x1a50 | "%s: Provides housing for %d %s and storage" | <cs> bld.w12a bld.b74af bld.b74ad <word ptr [bp - 0x18]> <dx> <ax> _DS "%s: Provides housing for %d %s and storage" |
| 26 | 1b34 | cmp [bld.unitType],0 ; je 0x1a50 | "%s: Provides housing for %d %s." | <cs> bld.b74af bld.b74ad <word ptr [bp - 0x18]> <dx> <ax> _DS "%s: Provides housing for %d %s." |
| 27 | 1bea | cmp [bld.unitType],8 ; je 0x1b6e | "%s: Provides housing for %d %s and storage" | <cs> bld.w12a bld.b74af bld.b74ad <word ptr [bp - 0x18]> <dx> <ax> _DS "%s: Provides housing for %d %s and storage" |
| 28 | 1c52 | cmp [bld.unitType],8 ; je 0x1b6e | "%s: Provides housing for %d %s." | <cs> bld.b74af bld.b74ad <word ptr [bp - 0x18]> <dx> <ax> _DS "%s: Provides housing for %d %s." |
| 29 | 1ce9 | cmp [bld.unitType],9 ; jne 0x1d04 | "%s: %s %d gold. Feeds %d %s." | <cs> bld.b74af bld.b74ad <word ptr [bp - 0x16]> <ax> <dx> <ax> <dx> <ax> _DS "%s: %s %d gold. Feeds %d %s." |
| 30 | 1dad | ? | "%s: %s %d gold. provides housing for %d %s" | <cs> bld.b74af bld.b74ad <word ptr [bp - 0x16]> bld.b74af bld.b74ad <word ptr [bp - 0x18]> <ax> <dx> <ax> <dx> <ax> _DS "%s: %s %d gold. provides housing for %d %s" |
| 31 | 1e28 | ? | "%s: %s %d gold. Feeds %d %s." | <cs> bld.b74af bld.b74ad <word ptr [bp - 0x16]> <ax> <dx> <ax> <dx> <ax> _DS "%s: %s %d gold. Feeds %d %s." |
| 32 | 1eac | ? | "%s: %s %d gold. Provides housing for %d %s" | <cs> bld.b74af bld.b74ad <word ptr [bp - 0x18]> <ax> <dx> <ax> <dx> <ax> _DS "%s: %s %d gold. Provides housing for %d %s" |
| 33 | 1f02 | ? | "%s: %s %d gold." | <cs> <ax> <dx> <ax> <dx> <ax> _DS "%s: %s %d gold." |
| 34 | 200e | ? | " Salvage value %d gold." | <cs> <word ptr [bp - 0x1e]> _DS " Salvage value %d gold." |
| 35 | 213e | ? | " Repair costs %d gp." | <cs> <word ptr [bp - 0x1c]> _DS " Repair costs %d gp." |
| 36 | 21ff | ? | " Upgrade costs %d gp." | <cs> <word ptr [bp - 0x1c]> _DS " Upgrade costs %d gp." |
| 37 | 23c8 | ? | "%s will be salvaged for %d gold. Are you s" | <cs> <word ptr [bp - 0x1e]> <dx> <ax> _DS "%s will be salvaged for %d gold. Are you s" |
| 38 | 2425 | ? | "Get rid of %s permanently. Are you sure?" | <cs> bld.name.seg bld.name.ofs _DS "Get rid of %s permanently. Are you sure?" |
| 39 | 25ce | ? | "%s is being filled." | <cs> <word ptr [bp + 0xc]> <dx> <ax> _DS "%s is being filled." |
| 40 | 2630 | ? | "%s salvaged for %d gold." | <cs> <word ptr [bp + 0xc]> <word ptr [bp - 0x1e]> <dx> <ax> _DS "%s salvaged for %d gold." |
| 41 | 2739 | ? | "%s is demolished." | <cs> <word ptr [bp + 0xc]> <dx> <ax> _DS "%s is demolished." |
| 42 | 27f3 | ? | "%s does not have enough gold." | <cs> <word ptr [bp + 0xc]> <dx> <ax> _DS "%s does not have enough gold." |
| 43 | 2858 | ? | "%s repaired." | <cs> <word ptr [bp + 0xc]> <dx> <ax> _DS "%s repaired." |
| 44 | 2986 | ? | "%s does not have enough gold." | <cs> <word ptr [bp + 0xc]> <dx> <ax> _DS "%s does not have enough gold." |
| 45 | 2a07 | ? | "%s upgraded." | <cs> <word ptr [bp + 0xc]> <dx> <ax> _DS "%s upgraded." |

## Remaining work for the body

* resolve the `<ax>`/`<dx>` placeholders to the expressions just before them (2-6 instructions each);
* fix each arm's branch polarity;
* the 5 unnameable call sites (`198,0057`, `198,005c`, `1a8,002a`, `1f8,002a` x2) - the first two are
  the leaf-4 preamble pair, already documented.

With the frame shapes above, that is mechanical per leaf: the pattern is always
`bld.name` + 0-4 scalar fields + 0-2 rendered lines + the class name.
