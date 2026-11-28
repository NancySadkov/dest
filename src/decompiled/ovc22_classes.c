/*
 * ovc22_classes.c - recovered from STRONG.EXE
 * memory block: OVC22_classes.c
 * range: 5087:0000 - 5087:576f
 * functions: 31
 */
#include "recovered.h"


/* 5087:0000 */

/* [R2] string "arena" */

bool __cdecl16far ovc22_textArena(int x,int y)

{
  bool result;
  int cellB;
  int cellMin;
  int cellA;
  
  if ((((x < 0) || (y < 0)) || (0x93 < x + 1)) || (0x3b < y + 1)) {
    placementStatus = 2;
    result = false;
  }
  else {
    if ((((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) == 0) &&
       (((*(short (*) [60] [148])GMapFlags)[y + 1][x] & 3U) == 0)) {
      cellA = (int)(char)(*(byte (*) [59] [148])GMapCells)[y + 1][x];
      cellB = (int)(char)(*(byte (*) [59] [148])GMapCells)[y + 1][x + 1];
      cellMin = cellA;
      if (cellB < cellA) {
        cellMin = cellB;
      }
      if (cellA < cellB) {
        cellA = cellB;
      }
      if (cellA - cellMin < 9) {
        placementStatus = 3;
        result = true;
      }
      else {
        result = false;
      }
    }
    else {
      placementStatus = 1;
      result = false;
    }
  }
  return result;
}



/* 5087:0119 */

/* Returns the class name of a party slot (cls < 7 from the table at 0x123) or "monster". */

char * __cdecl16far ovc22_className(byte partyIndex,uint16_t arg2)

{
  byte bVar1;
  char *pcVar2;
  
  bVar1 = *((byte far *)GLeaderSheets[partyIndex] + 0x2f);
  if (bVar1 < 7) {
    pcVar2 = (char *)*(uint16_t *)((uint)bVar1 * 4 + 0x123);
  }
  else {
    pcVar2 = (char *)"monster";
  }
  return pcVar2;
}



/* 5087:015c */

/* [R7] body shape: compute */

uint __cdecl16far ovc22_compute1(byte partyIndex,uint value)

{
  if (*((char far *)GLeaderSheets[partyIndex] + 0x2f) == '\x04') {
    value = value >> 1;
  }
  return value;
}



/* 5087:018f */

/* Scales a value by the leader's rank (rank+10)/10, doubles it at rank >= 10 and applies 96% for
   class 6. */

int __cdecl16far ovc22_applyRankBonus(byte partyIndex,int cost)

{
  if ((GLeaderSheets[partyIndex])->rank < 10) {
    if ((GLeaderSheets[partyIndex])->rank != 0) {
      cost = (int)(((long)cost *
                    (long)((GLeaderSheets[partyIndex])->rank + 10) &
                   0xffffU) / 10);
    }
  }
  else {
    cost = cost << 1;
  }
  if (*((char far *)GLeaderSheets[partyIndex] + 0x2f) == '\x06') {
    cost = (int)(((long)cost * 0x96 & 0xffffU) / 100);
  }
  return cost;
}



/* 5087:0234 */

/* Population a building type contributes: the base production, adjusted by the type's rank
   bonus, halved or quartered for type 0x19 by the season and time, scaled by the per-agent code
   for flagged types, and finally season-adjusted.  Re-derived from the image; the former body
   had an unrelated entity scan merged into its tail. */

char * __cdecl16far ovc22_textPOPULATION(byte bldType,byte partyIndex,agnt_t far *agnt)

{
  uint16_t value;
  uint8_t code;

  if (BuildingTypes[bldType].unitType == '\x16') {
    return (char *)0x0;
  }
  if (BuildingTypes[bldType].production == '\0') {
    return (char *)0x0;
  }
  if ((BuildingTypes[bldType].flags2 & 0x20) != 0) {
    value = (uint16_t)ovc22_compute1((int)(uint)partyIndex,
                                    (uint)BuildingTypes[bldType].production);
  }
  else if ((BuildingTypes[bldType].flags2 & 0x80) != 0) {
    value = (uint16_t)ovc22_applyRankBonus((int)(uint)partyIndex,
                                          (uint)BuildingTypes[bldType].production);
  }
  else {
    value = (uint16_t)BuildingTypes[bldType].production;
  }
  if (value == 0) {
    return (char *)0x0;
  }
  if (BuildingTypes[bldType].unitType == '\x19') {
    if (GSeason == '\0') {
      if (GTimeLo < 0xf) {
        value = (uint16_t)(value >> 2);
      }
      else {
        value = (uint16_t)(value >> 1);
      }
    }
    else if (GSeason == '\x02') {
      value = (uint16_t)(value + (value >> 2));
    }
    return (char *)(uint)value;
  }
  if ((BuildingTypes[bldType].flags2 & 0x80) != 0) {
    code = (uint8_t)ovr_constr_usesGMapFlags2(agnt);
    switch ((uint16_t)(code - 1)) {
    case 0:
      value = (uint16_t)(value << 1);
      break;
    case 1:
      value = (uint16_t)((value * 3) >> 1);
      break;
    case 2:
      value = (uint16_t)((value * 3) >> 2);
      break;
    case 3:
      value = (uint16_t)((value * 3) >> 3);
      break;
    }
  }
  if (GSeason == '\x01') {
    value = (uint16_t)(value + (value >> 2));
  }
  else if (GSeason == '\x02') {
    value = (uint16_t)(value >> 2);
  }
  return (char *)(uint)value;
}



/* 5087:0411 */

/* Returns a building's income adjusted for the current season and time of day. */

uint __cdecl16far ovc22_seasonalIncome(byte bldType,uint8_t partyIndex,agnt_t far *agnt)

{
  uint income;
  
  if (BuildingTypes[bldType].income == 0) {
    income = 0;
  }
  else if (BuildingTypes[bldType].unitType == '\x19') {
    income = BuildingTypes[bldType].income;
    if (GSeason == '\0') {
      if (GTimeLo < 0xf) {
        income = income >> 2;
      }
      else {
        income = income >> 1;
      }
    }
    else if (GSeason == '\x02') {
      income = income + (income >> 2);
    }
  }
  else if ((BuildingTypes[bldType].flags2 & 0x20) == 0) {
    if ((BuildingTypes[bldType].flags2 & 0x80) == 0) {
      income = BuildingTypes[bldType].income;
    }
    else {
      income = ovc22_applyRankBonus(partyIndex,BuildingTypes[bldType].income);
      if (GSeason == '\x01') {
        income = income + ((int)income >> 2);
      }
      else if (GSeason == '\x02') {
        income = (int)income >> 2;
      }
    }
  }
  else {
    income = ovc22_compute1(partyIndex,BuildingTypes[bldType].income);
  }
  return income;
}



/* 5087:056e */

/* Ring-of-protection / per-party production recompute.  Image: 3,842 bytes (0x056e..0x1443 plus the
   twenty-two entry switch jump table at cs:0x1444), eleven calls.

   The 2,294-line body that stood here was another function's (140 call sites, none of the image's
   eleven helpers), the same class of mis-attribution as 77eb:0d61 and 2e25:025a.

   Frame: `sub sp,0x46`, si/di saved, one byte parameter at [bp+6], no return value (the image's
   epilogue is `pop di / pop si / leave / retf` with DX:AX untouched).

   Decoded from tmp/o22_056e.txt (1,349 instructions).  Offsets 0x056e..0x1443 plus the 22-entry
   switch table at cs:0x1444; `bldtp_t` base is segment 0x60 offset 0x10e, `GLeaderSheets` segment
   0x70, `GUnits` stride 9, `entity_t` stride 0x37.

   Prologue / per-call setup:
     - `if (partyIndex == 0xff) return;`
     - popular = 0xa; housing = income = rows = ringTotal = 0; cap = 0;
     - memset(&dir[1], 0, 6); memset(&ring[1], 0, 6);      (bp-0x28 / bp-0x2e, the two 4-word arrays)
     - memset(sheet + 0x9a, 0, 3); memset(&resCount, 0, 8); memset(sheet + 0xaa, 0, 3);
     - partyMask = 0x1000 << sheet->faction;               (0x1000 or 0x2000, the two GMapFlags bits)
     - sheet->tailAD = 0;
     - if (sheet->faction != 0) sheet->flags5d &= 0xf9; else sheet->flags5d |= 4;
     - sheet->flags5d &= 0xf7; sheet->maxTrade = 0;
     - sheet->tailA6 = sheet->tailA5 = sheet->tailA9 = 0;
     - for (i = 0xf8; i < GUnitCount; i++) GUnits[i].flags &= 0xfd;

   Per-unit pass, `for (si = 0xf8; si < GUnitCount; si++)`, skipping units whose `unitType`
   (+2) differs from partyIndex:
     - bldType = GUnits[si].bldType (+0); alignX = ovr_alignUp4(GUnits[si].x (+4));
       y = GUnits[si].y (+6);
     - bitsA = OR over k = 0..3 of word[ GMapFlags + y*0x128 + 2*(alignX+k) - 4 ] & 0x3000;
     - bitsB = 0; if ((bt->flags & 3) == 1) bitsB = OR over k = 0..3 of
       word[ map2 + y*0x128 + 2*(alignX+k) + 0x124 ] & 0x3000;   (map2 = the far pair at 8a09/8a0b)
     - if (!(bitsA & partyMask) && !(bitsB & partyMask)) continue;
     - GUnits[si].flags |= 3;
     - switch (bt->unitType) - 7, 22 cases (bt = BuildingTypes[bldType], stride 0x27):
         14: ((uint16_t *)((uint8_t *)&partyMask))[bt->resource] += 5;   (local 4-word array whose
             element 0 is partyMask itself)
         15: ((uint8_t *)sheet)[0x99 + bt->resource] += 3;
         17: sheet->tailA6++; sheet->flags5d |= 8;
         18: sheet->tailA8++;
         20: sheet->flags5d &= ~4;
         21: sheet->tailA5++;
         22: sheet->maxTrade += bt->production;            (byte at +0x1a, zero-extended)
         23: if (sheet->faction == 0) g_90e8 = 1;
         26: ((uint8_t *)sheet)[0xa9 + bt->resource]++;
         28: sheet->tailA9 += 3 * bt->resource; if (sheet->tailA9 > 100) sheet->tailA9 = 100;
          7: sheet->tailAD++;
         types 8,9,10,11,12,13,16,19,24,25,27 have no case body and fall straight through;
     - shared switch tail (0x0c40), reached by every case:
         if (bt->unitType == 0x13) totalA += bt->storage;  else totalB += bt->storage;
         if (bt->unitType == 0x1d)      { if ([bp-2] != 0) goto unitDone;
                                          ring[bt->resource] += bt->output; }
         else if (bt->unitType == 0x10) { if ([bp-2] == 0) goto unitDone;
                                          ring[bt->resource] += bt->output; }
         else if (bt->output != 0) {
             if (bt->unitType == 0x0d) { if ([bp-1] != 0) dir2[bt->resource] += bt->output; }
             else dir2[bt->resource] += bt->output; }
         (storage = +0x1c word, output = +0x1b byte; ring[] at bp-0x30, dir2[] at bp-0x2a, both
          4-word arrays whose element 0 doubles as the high/low half of a 32-bit total)
     - unitDone (0x0e2a): housing += bt->housing (+0x19);
         population += ovc22_textPOPULATION(bldType, partyIndex, GUnits[si].x, GUnits[si].y);
         income     += ovc22_seasonalIncome(bldType, partyIndex, GUnits[si].x, GUnits[si].y);
         if (bt->flags2 & 1) {
             if (sheet->cls == 0xff || ((1 << sheet->cls) & bt->type))
                 if (bt->resource <= 3) resCount[bt->resource]++; }
         if (bt->flags2 & 0x200) ringTotal += bt->resource;
       (both textPOPULATION and seasonalIncome push four words: bldType, partyIndex, x, y)

   Post-loop:
     - for (e = 0; e < EntityCount; e++)
         if (Entities[e].+0x1a == partyIndex) sum1c += Entities[e].+0x0e;
     - spare = sheet->tailAD;
       for (di = 2; di >= 0; di--)
           if (sheet->tailAA[di] > spare) { sheet->tailAA[di] = spare; spare = 0; }
           else spare -= sheet->tailAA[di];
     - sum = 0; for (di = 0; di <= 2; di++) sum += sheet->tailAA[di] * (di + 1) * 3;
       sheet->tailAA[0] = (sum >= 0x32) ? 0x32 : sum;
     - sheet->tail94 = [bp-0xa]; sheet->tail96 = [bp-8]; sheet->tail98 = [bp-6];
     - cap = [bp-0x40]; if (cap > 5) cap = 5;
       if ([bp-0x3e] + cap > 0xa) cap = 0xa; else cap += [bp-0x3e];
       cap += [bp-0x3c];
     - sheet->levelLimit = [bp-0x3c] > 0 ? 0xff : [bp-0x3e] > 0 ? 0xc : [bp-0x40] > 0 ? 8 : 4;

   Tail stores (0x1220..0x1443), all into sheet:
     - sheet->reserved_82 (+0x82) = [bp-0x38];
     - foodStorage (+0x7e long) = totalB, except that a *positive* totalB is replaced by 0xffff:
       the image tests the high word and stores 0xffff/0 else, which is `totalB > 0 ? 0xffff : totalB`;
     - housing (+0x5b) = housing; population (+0x4d) = entityUnits;
       foodProd (+0x4f) = population; income (+0x54) = income;
     - vaultStorage (+0x8a long) = totalA;
     - dirBudgetIn[0..2] (+0x64/+0x66/+0x68) = dirBudget[1..3];
     - ringBudgetIn[0..2] (+0x70/+0x72/+0x74) = ringBudget[1..3];
     - rank (+0x87) = resourceTotal;
     - level (+0x52) = levelCap > 0xff ? 0xff : levelCap;
     - popularity (+0x84) = the one-argument overlay call `lcall 0x208,0x20` (see below);
     - finally ovc22_usesPlayerCount(partyIndex) (5087:143a).

   Stack-alias inventory.  The image seats several locals so that one word is shared, which the body
   must reproduce explicitly (all offsets are bp-relative, and every pair below is the *same address*):

     bp-0x0c  partyMask                      == word 0 of a 4-word array; case 14 adds 5 to
                                                ((uint16_t *)&partyMask)[bt->resource]
     bp-0x0a,-8,-6  extra[0..2]              the other three words of that array ->
                                                stored to tail94/tail96/tail98
     bp-0x36/-0x34  totalA low/high          -> vaultStorage
     bp-0x32/-0x30  totalB low/high          totalB's HIGH word == ringBudget[0]
     bp-0x2e,-0x2c  ringBudget[1..2]         -> ringBudgetIn[0..1]
     bp-0x2a        ringBudget[3] == dirBudget[0]   (shared word)
     bp-0x28,-0x26,-0x24  dirBudget[1..3]    -> dirBudgetIn[0..2]
     bp-0x42        resCount[0]              per-resource building counts
     bp-0x40,-0x3e,-0x3c  resCount[1..3]     the level-cap ladder's three words

   So the cap is: levelCap = min(resCount[1],5); if (resCount[2]+levelCap > 10) levelCap = 10 else
   levelCap += resCount[2]; levelCap += resCount[3]; and levelLimit (+0x53) = resCount[3] ? 0xff :
   resCount[2] ? 0xc : resCount[1] ? 8 : 4.

   Difficulty (0x909d, byte) picks totalA: 1 -> 0xfa0, 2 -> 0xbb8, otherwise 0x7d0.

   `lcall 0x208,0x20` occurs once in the whole image, so no cross-reference can name it; a body must
   use a documented placeholder for that one call (argument partyIndex, result -> sheet->popularity).

   Body below. */


void __cdecl16far ovc22_textRingProt(byte partyIndex)

{
  char_sheet_t far *sheet;
  bldtp_t far *bt;
  uint8_t far *raw;
  uint16_t i;
  uint16_t bldType;
  uint16_t alignX;
  uint16_t y;
  uint16_t k;
  uint16_t bitsA;
  uint16_t bitsB;
  uint16_t partyMask;
  uint16_t extra[3];
  uint32_t totalA;
  uint32_t totalB;
  /* The frame seats the two 4-word budget arrays so that ringBudget[3] and dirBudget[0] are the
     same word (bp-0x2a) and ringBudget[0] is the high half of totalB (bp-0x30).  One array keeps
     the shared word shared: budget[1..3] = ringBudget[1..3], budget[3] is also dirBudget[0],
     budget[4..6] = dirBudget[1..3]. */
  uint16_t budget[7];
  uint16_t resCount[4];
  uint16_t population;
  uint16_t housing;
  uint16_t income;
  uint16_t entityUnits;
  uint16_t resourceTotal;
  uint16_t levelCap;
  uint16_t gindex;
  uint8_t gval;
  uint8_t g1;
  uint8_t g2;
  uint16_t spare;
  uint16_t sum;
  uint16_t e;
  uint16_t di;

  if (partyIndex == 0xff) {
    return;
  }
  sheet = GLeaderSheets[partyIndex];
  raw = (uint8_t far *)sheet;

  entityUnits = 0;
  population = 10;
  income = 0;
  housing = 0;
  levelCap = 0;

  /* 0x059d..0x05f1: the image clears these with _fmemset, in this order. */
  _fmemset(&budget[4],0,6);         /* dirBudget[1..3] */
  _fmemset(&budget[1],0,6);         /* ringBudget[1..3], whose last word is dirBudget[0] */
  _fmemset(raw + 0x9a,0,3);         /* the three per-resource bytes at +0x9a */
  _fmemset(&extra[0],0,6);          /* the three extra words stored to tail94/96/98 */
  totalB = 0;

  switch (Difficulty) {
  case 1:
    totalA = 0xfa0;
    break;
  case 2:
    totalA = 0xbb8;
    break;
  default:
    totalA = 0x7d0;
    break;
  }
  resourceTotal = 0;
  _fmemset(&resCount[0],0,8);       /* 0x0646 */

  for (i = 0xf8; i < GUnitCount; i++) {
    GUnits[i].flags &= 0xfd;
  }

  partyMask = (uint16_t)(0x1000 << (sheet->faction & 0x1f));

  sheet->tailAD = 0;
  _fmemset(raw + 0xaa,0,3);         /* 0x06c2, the three per-resource bytes at +0xaa */
  if (sheet->faction != 0) {
    sheet->flags5d &= 0xf9;
  }
  else {
    sheet->flags5d |= 4;
  }
  sheet->flags5d &= 0xf7;
  sheet->maxTrade = 0;
  sheet->tailA6 = 0;
  sheet->tailA5 = 0;
  sheet->tailA9 = 0;

  /* The image reads AgntGs[sheet->classStr] byte +0x46 (0060:0x271c) twice; the generic-agent
     record has no named field at that offset in our model yet. */
  gindex = sheet->classStr;
  gval = ((uint8_t far *)&AgntGs[gindex])[0x46];
  g1 = (uint8_t)(gval == 1);
  g2 = (uint8_t)(gval == 0 || gval == 5);

  for (i = 0xf8; i < GUnitCount; i++) {
    if (GUnits[i].unitType != partyIndex) {
      continue;
    }
    bldType = GUnits[i].bldType;
    bt = &BuildingTypes[bldType];
    alignX = (uint16_t)ovr_alignUp4(GUnits[i].x);
    y = GUnits[i].y;

    bitsA = 0;
    for (k = 0; k < 4; k++) {
      bitsA |= (uint16_t)(GMapFlags[y][alignX + k - 2] & 0x3000);
    }
    bitsB = 0;
    if ((bt->flags & 3) == 1) {
      for (k = 0; k < 4; k++) {
        bitsB |= (uint16_t)(GMapFlags[y + 1][alignX + k - 2] & 0x3000);
      }
    }
    if ((bitsA & partyMask) == 0 && (bitsB & partyMask) == 0) {
      continue;
    }
    GUnits[i].flags |= 3;

    switch (bt->unitType) {
    case 7:
      sheet->tailAD++;
      break;
    case 14:
      if (bt->resource == 0) {
        partyMask += 5;
      }
      else if (bt->resource <= 3) {
        extra[bt->resource - 1] += 5;
      }
      break;
    case 15:
      raw[0x99 + bt->resource] += 3;
      break;
    case 17:
      sheet->tailA6++;
      sheet->flags5d |= 8;
      break;
    case 18:
      sheet->tailA8++;
      break;
    case 20:
      sheet->flags5d &= 0xfb;
      break;
    case 21:
      sheet->tailA5++;
      break;
    case 22:
      sheet->maxTrade += bt->production;
      break;
    case 23:
      if (sheet->faction == 0) {
        GCanPromote = 1;
      }
      break;
    case 26:
      raw[0xa9 + bt->resource]++;
      break;
    case 28:
      sheet->tailA9 = (uint8_t)(sheet->tailA9 + 3 * bt->resource);
      if (sheet->tailA9 > 100) {
        sheet->tailA9 = 100;
      }
      break;
    default:
      break;
    }

    if (bt->unitType == 0x13) {
      totalA += bt->storage;
    }
    else {
      totalB += bt->storage;
    }

    if (bt->unitType == 0x1d || bt->unitType == 0x10) {
      if (bt->unitType == 0x1d) {
        if (g1 != 0) {
          goto unitDone;
        }
      }
      else if (g1 == 0) {
        goto unitDone;
      }
      switch (bt->resource) {
      case 0:
        totalB += (uint32_t)bt->output << 16;
        break;
      case 1:
        budget[1] += bt->output;
        break;
      case 2:
        budget[2] += bt->output;
        break;
      case 3:
        budget[3] += bt->output;
        break;
      default:
        break;
      }
      goto unitDone;
    }
    if (bt->output == 0) {
      goto unitDone;
    }
    if (bt->unitType == 0x0d && g2 == 0) {
      goto unitDone;
    }
    switch (bt->resource) {
    case 0:
      budget[3] += bt->output;
      break;
    case 1:
      budget[4] += bt->output;
      break;
    case 2:
      budget[5] += bt->output;
      break;
    case 3:
      budget[6] += bt->output;
      break;
    default:
      break;
    }

  unitDone:
    housing += bt->housing;
    if (i >= 0xf8) {
      population += (uint16_t)ovc22_textPOPULATION((byte)bldType,partyIndex,
                                                   (agnt_t far *)MK_FP(y,GUnits[i].x));
      income += (uint16_t)ovc22_seasonalIncome((byte)bldType,partyIndex,
                                               (agnt_t far *)MK_FP(y,GUnits[i].x));
    }
    if ((bt->flags2 & 1) != 0) {
      if (sheet->cls == 0xff || (((uint16_t)(1 << (sheet->cls & 0x1f))) & bt->type) != 0) {
        if (bt->resource <= 3) {
          resCount[bt->resource]++;
        }
      }
    }
    if ((bt->flags2 & 0x200) != 0) {
      resourceTotal += bt->resource;
    }
  }

  for (e = 0; e < EntityCount; e++) {
    if (((uint8_t far *)&Entities[e])[0x1a] == partyIndex) {
      entityUnits += Entities[e].base.animFrame;
    }
  }

  spare = sheet->tailAD;
  di = 2;
  for (;;) {
    if (sheet->tailAA[di] > spare) {
      sheet->tailAA[di] = (uint8_t)spare;
      spare = 0;
    }
    else {
      spare -= sheet->tailAA[di];
    }
    if (di == 0) {
      break;
    }
    di--;
  }

  sum = 0;
  for (di = 0; di <= 2; di++) {
    sum += (uint16_t)(sheet->tailAA[di] * (di + 1) * 3);
  }
  sheet->tailAA[0] = (uint8_t)((sum >= 0x32) ? 0x32 : sum);

  sheet->tail94 = extra[0];
  sheet->tail96 = extra[1];
  sheet->tail98 = extra[2];

  levelCap = resCount[1];
  if (levelCap > 5) {
    levelCap = 5;
  }
  if ((uint16_t)(resCount[2] + levelCap) > 0xa) {
    levelCap = 0xa;
  }
  else {
    levelCap += resCount[2];
  }
  levelCap += resCount[3];

  sheet->reserved_82 = 0;
  if ((int32_t)totalB > 0) {
    sheet->foodStorage = 0xffffL;
  }
  else {
    sheet->foodStorage = (long)totalB;
  }
  sheet->housing = (short)housing;
  sheet->population = (short)entityUnits;
  sheet->foodProd = (short)population;
  sheet->income = (short)income;
  sheet->vaultStorage = (long)totalA;
  sheet->dirBudgetIn[0] = budget[4];
  sheet->dirBudgetIn[1] = budget[5];
  sheet->dirBudgetIn[2] = budget[6];
  sheet->ringBudgetIn[0] = budget[1];
  sheet->ringBudgetIn[1] = budget[2];
  sheet->ringBudgetIn[2] = budget[3];
  sheet->rank = (short)resourceTotal;
  sheet->level = (uint8_t)((levelCap > 0xff) ? 0xff : levelCap);
  sheet->levelLimit = (resCount[3] > 0) ? 0xff : (resCount[2] > 0) ? 0xc : (resCount[1] > 0) ? 8 : 4;

  /* GAP: the image stores AL from `lcall 0x208,0x20` into sheet->popularity (5087:1413).
     Segment 0x208 is a VROOMM overlay *window*, not a module: it appears in neither
     audit/functions_real.tsv (whose 106 segments contain nothing below 0x1000) nor
     audit/overlay_segments.csv, so the target has no static name and the call cannot be emitted
     without inventing one.  The store is left out rather than guessed. */

  ovc22_usesPlayerCount(partyIndex);
}



/* 5087:1470 */

/* [R6] touches PlayerCount */

uint16_t __cdecl16far ovc22_usesPlayerCount(byte partyIndex)

{
  /* Re-derived: the party's allowed unit count.  For the human party (leader-sheet byte +0x3f
     clear) it is unitCount/10 + 2, raised to + 4 when foodProd covers 1.5x the sheet's +0x4d;
     for the computer party it is PlayerCount/2 + 1.  Capped at 10 and stored at sheet +0xa4. */
  byte count;
  char baseCount;
  int sheetOfs;

  if (*((char far *)GLeaderSheets[partyIndex] + 0x3f) == '\0') {
    baseCount = (char)((ulong)(GLeaderSheets[partyIndex])->unitCount / 10);
    count = baseCount + 2;
    sheetOfs = (int)(uint32_t)GLeaderSheets[partyIndex];
    if ((uint)(*(int *)(sheetOfs + 0x4d) * 2 + *(int *)(sheetOfs + 0x4d)) >> 1 <=
        (GLeaderSheets[partyIndex])->foodProd) {
      count = baseCount + 4;
    }
  }
  else {
    count = PlayerCount / 2 + 1;
  }
  if (10 < count) {
    count = 10;
  }
  *((byte far *)GLeaderSheets[partyIndex] + 0xa4) = count;
  return count;
}



/* 5087:1532 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches Entities, animFrame */

uint __cdecl16far ovc22_usesEntities(int entityIndex)

{
  /* 5087:1532 (file 0x43BA2), re-derived from the original:

       si = [bp+6]
       if (AGNT_FIELD(&Entities[si], base.entity, 3) == 0xff) return 0;
       if (*(uint *)(BuildingTypes + gindex * 0x95 + 0x2716) & 0x800) return 0;
       animBase = sheet[field][0xa4]
       if (sheet[field][0x3f] == 0 && sheet[field][0x5b] < sheet[field][0x4d])
           return 0;
       for (n = 3; n >= 1 && sheet[field][0x8c + n*2] == 0; n--) ;
       animBase += n
       if (Entities[si].base.animFrame < animBase) {
           Entities[si].base.animFrame++; return 1;
       }
       return 0;

     The original only ever sets AL (`mov al,0` / `mov al,1`), so the exported
     `entityIndex * 0x37 & 0xff00` returns were Ghidra modelling a stale AH left by the
     `imul dx` that computes the record offset; every caller tests `& 0xff`. */
  entity_t *e;
  byte field;
  byte animBase;
  byte n;

  e = &(Entities)[entityIndex];
  field = AGNT_FIELD(e, base.entity, 3);
  if (field == 0xff) {
    return 0;
  }
  if ((AgntGs[(uint)e->base.gindex].flags3 & 0x800) != 0) {
    return 0;
  }
  animBase = *(char *)((int)*(uint32_t *)((uint)field << 2) + 0xa4);
  if ((*(char *)((int)*(uint32_t *)((uint)field << 2) + 0x3f) == '\0') &&
      ((GLeaderSheets[field])->housing < (GLeaderSheets[field])->population)) {
    return 0;
  }
  n = 3;
  while ((n != 0) &&
         (*(int *)((int)*(uint32_t *)((uint)field << 2) + (uint)n * 2 + 0x8c) == 0)) {
    n = n - 1;
  }
  animBase = animBase + n;
  if (e->base.animFrame < animBase) {
    e->base.animFrame = e->base.animFrame + 1;
    return 1;
  }
  return 0;
}



/* 5087:1674 */

/* [R6] touches GUnits, GRecordCount */

void __cdecl16far ovc22_usesGUnits(int unitIndex,uint8_t *outFlag)

{
  /* 5087:1674 (file 0x43CE4), re-derived from the original:

       si = [bp+6] ; di = 0
       while (di < GRecordCount)
           if (GRecords[di] matches GUnits[si] in both coordinates) return;
           else di++;
       bldType = GUnits[si].bldType
       if (BuildingTypes[bldType].flags2 & 4) return
       if (ovc22_usesGOngoingBattle(x, y)) *outFlag = 1
       create(0, x,   y, ...)
       if (BuildingTypes[bldType].size >= 2) {
           create(0, x+1, y, ...)
           if (BuildingTypes[bldType].size >= 4) { create(0, x+2, y, ...);
                                                   create(0, x+3, y, ...); }
       }

     Corrections to the exported form: the unit record is fetched once instead of
     re-loading GUnits and recomputing si*9 for every field, and the `!= 0` test on the
     +1 create's return value is gone - the original has no `or al,al` after that call
     (0x43E17) and tests only the building size, so the exported condition skipped the
     +2/+3 records whenever the call returned zero.

     Remaining defect, deliberately not changed here: the original takes `outFlag` as a
     FAR pointer (offset at [bp+8], segment at [bp+0xa]) and a fourth argument at
     [bp+0xc], then stores through ES:BX.  Our 2-argument prototype reads the caller's
     stack for both, which is what `outFlagSeg` and `diArg` below really are. */
  uint16_t outFlagSeg;     /* segment half of the out pointer: [bp+0xa] in the image */
  uint16_t diArg;          /* the fourth argument at [bp+0xc], passed through DI */
  unit_t *u;
  uint16_t bldType;
  int i;

  u = GUnits + unitIndex;
  for (i = 0; i < (int)GRecordCount; i++) {
    if ((GRecords[i].x == u->x) && (GRecords[i].y == u->y)) {
      return;
    }
  }
  bldType = u->bldType;
  if ((BuildingTypes[bldType].flags2 & 4) == 0) {
    if ((char)ovc22_usesGOngoingBattle(*(byte *)&u->x,*(byte *)&u->y) != '\0') {
      *(uint8_t *)CONCAT22((uint8_t *)outFlag,outFlagSeg) = 0x1;
    }
    ovr_createConstructionRecordFar
              (0,u->x,u->y,(uint8_t *)CONCAT22((uint8_t *)outFlag,outFlagSeg),(*(uint8_t *)((uint8_t *)&(outFlag) + 2)),diArg,0,0,0)
    ;
    if (1 < BuildingTypes[bldType].size) {
      ovr_createConstructionRecordFar
                (0,u->x + 1,u->y,(uint8_t *)CONCAT22((uint8_t *)outFlag,outFlagSeg),(*(uint8_t *)((uint8_t *)&(outFlag) + 2)),diArg,0,0,0);
      if (3 < BuildingTypes[bldType].size) {
        ovr_createConstructionRecordFar
                  (0,u->x + 2,u->y,(uint8_t *)CONCAT22((uint8_t *)outFlag,outFlagSeg),(*(uint8_t *)((uint8_t *)&(outFlag) + 2)),diArg,0,0,0);
        ovr_createConstructionRecordFar
                  (0,u->x + 3,u->y,(uint8_t *)CONCAT22((uint8_t *)outFlag,outFlagSeg),(*(uint8_t *)((uint8_t *)&(outFlag) + 2)),diArg,0,0,0);
      }
    }
  }
  return;
}



/* 5087:18b6 */

/* [R4] calls LUDIV_at_ */

void __cdecl16far ovc22_usesLUDIV_at_(entity_t *entity)

{
  char_sheet_t far *sheet;
  uint partySlot;
  uint lvlIdx;
  int *divPair;            /* (low, high) word pair at classId*0x94 + lvlIdx*4 */
  byte classId;

  /* 0008-001D: the leader sheet for this slot.  The original loads it from a far-pointer array at
     DGROUP-relative segment 0x70 - `mov ax,0x70 / mov es,ax / les bx,ptr es:[bx]` with
     bx = partySlot*4 - which is GLeaderSheets.  The export read DS:partySlot*4 instead. */
  partySlot = (uint)*(byte *)((int)&(entity->base).entity + 3);
  sheet = GLeaderSheets[partySlot];
  lvlIdx = *((uint8_t far *)sheet + 0x52) + 1;
  if ((entity->base).level < lvlIdx) {
    lvlIdx = (uint)(entity->base).level;
  }
  if (0x24 < lvlIdx) {
    lvlIdx = 0x24;
  }
  /* 004B-005A: char_sheet_t.cls at +0x2f, with 0xff meaning "no class". */
  classId = sheet->cls;
  if (classId == 0xff) {
    classId = 0;
  }
  /* The per-class table these two indices walk lives at segment 0x80 and stays a near read: no symbol
     in the tree or in audit/symbols.tsv identifies that segment. */
  for (; (divPair = (int *)((uint)classId * 0x94 + lvlIdx * 4), *divPair == 0 && divPair[1] == 0 &&
         (lvlIdx != 0)); lvlIdx = lvlIdx - 1) {
  }
  divPair = (int *)((uint)classId * 0x94 + lvlIdx * 4);
  LUDIV_at_(*divPair,divPair[1],0x1e,0);
  return;
}



/* 5087:197d */

/* [R7] body shape: compute */

char __cdecl16far ovc22_compute3(char direction)

{
  if (direction < '\0') {
    direction = direction + '\x06';
  }
  return direction;
}



/* 5087:1991 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches Entities */

void __cdecl16far ovc22_usesEntities2(int entityIndex)

{
  int *budgetPtr;
  byte partyId;
  uint32_t gdataPtr;
  byte dirLevel;
  char ringBase;
  char innerDir;
  uint16_t entSeg;
  char budgetIdx;
  
  entSeg = (uint16_t)((ulong)Entities >> 0x10);
  if (*(char *)((int)&(Entities)[entityIndex].base.entity + 3) != -1) {
    dirLevel = ovr_agnt_compute8((agnt_t far *)((uint8_t *)&(Entities)[entityIndex]),entSeg);
    partyId = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
    for (budgetIdx = '\0'; budgetIdx < '\x03'; budgetIdx = budgetIdx + '\x01') {
      gdataPtr = *(uint32_t *)((uint)partyId << 2);
      if ((*(int *)((int)gdataPtr + budgetIdx * 2 + 0x6a) != 0) && ((char)dirLevel < budgetIdx)) {
        gdataPtr = *(uint32_t *)((uint)partyId << 2);
        budgetPtr = (int *)((int)gdataPtr + budgetIdx * 2 + 0x6a);
        *budgetPtr = *budgetPtr + -1;
        entSeg = (uint16_t)((ulong)Entities >> 0x10);
        ringBase = (Entities)[entityIndex].dir -
                (Entities)[entityIndex].dir % 6;
        innerDir = ovc22_compute3(budgetIdx);
        (Entities)[entityIndex].dir = ringBase + innerDir;
        return;
      }
    }
  }
  return;
}



/* 5087:1ac1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches Entities */

void __cdecl16far ovc22_usesEntities3(int entityIndex)

{
  int far *budgetPtr;
  char_sheet_t far *sheet;
  byte slot;
  byte gidx;
  byte dirLevel;
  char innerDir;
  uint16_t entSeg;
  char chosenIdx;
  char budgetIdx;
  
  entSeg = (uint16_t)((ulong)Entities >> 0x10);
  if (*(char *)((int)&(Entities)[entityIndex].base.entity + 3) != -1) {
    dirLevel = ovr_agnt_compute10((agnt_t far *)((uint8_t *)&(Entities)[entityIndex]),entSeg);
    slot = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
    for (budgetIdx = '\0'; budgetIdx < '\x04'; budgetIdx = budgetIdx + '\x01') {
      sheet = GLeaderSheets[slot];
      if (((int)sheet->ringBudget[(uint)budgetIdx] != 0) && ((int)(char)dirLevel < budgetIdx + 1)) {
        chosenIdx = budgetIdx;
        budgetPtr = (int far *)&sheet->ringBudget[(uint)budgetIdx];
        *budgetPtr = *budgetPtr + -1;
        entSeg = (uint16_t)((ulong)Entities >> 0x10);
        (Entities)[entityIndex].dir =
             (Entities)[entityIndex].dir +
             (char)(((ulong)(Entities)[entityIndex].dir / 6) % 6) * -6;
        gidx = (Entities)[entityIndex].base.gindex;
        if ((AgntGs[(uint)gidx].shortName[3] == '\x03') &&
           ('\x01' < budgetIdx)) {
          chosenIdx = '\x01';
        }
        if ((AgntGs[(uint)gidx].shortName[3] == '\x01') &&
           ('\x02' < chosenIdx)) {
          chosenIdx = '\x02';
        }
        innerDir = ovc22_compute3(chosenIdx + '\x01');
        entSeg = (uint16_t)((ulong)Entities >> 0x10);
        (Entities)[entityIndex].dir =
             (Entities)[entityIndex].dir + innerDir * '\x06';
        return;
      }
    }
  }
  return;
}



/* 5087:1ca4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches Entities */

void __cdecl16far ovc22_usesEntities4(int entityIndex)

{
  /* Re-derived: while the entity has a party and its frames word has no bit 2, decrements
     that party's +0xa7 counter and sets bit 2 of the entity's +0x14 word.  The export's iVar5
     (an unused Entities offset) and uVar6 (a segment half) were dead. */
  char *counterPtr;
  uint *flagsPtr;
  byte partyIdx;
  uint32_t sheetRef;

  if (((AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3) != -1) &&
      ((AGNT_WORD(&(Entities)[entityIndex], base.frames, 1) & 2) == 0)) &&
     (partyIdx = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3),
     sheetRef = *(uint32_t *)((uint)partyIdx << 2), *(char *)((int)sheetRef + 0xa7) != '\0')) {
    sheetRef = *(uint32_t *)((uint)partyIdx << 2);
    counterPtr = (char *)((int)sheetRef + 0xa7);
    *counterPtr = *counterPtr + -1;
    flagsPtr = (uint *)((uint8_t *)&(Entities)[entityIndex] + 0x14);
    *flagsPtr = *flagsPtr | 2;
  }
  return;
}



/* 5087:1d4a */

/* [R4] calls LUDIV_at_ */

uint16_t __cdecl16far ovc22_usesLUDIV_at_2(uint16_t valueLo,uint16_t valueHi,int applyPercent)

{
  long *dividendLo;
  uint16_t unaff_BP;
  uint unaff_SI;
  uint32_t uVar1;
  uint16_t in_stack_00000000;
  uint divisorLo;
  long a;
  
  if (applyPercent != 0) {
    a = (ulong)unaff_SI << 0x10;
    divisorLo = 100;
    dividendLo = LXMUL_at_((long *)((int)&_Int0Vector[2].ofs + 1),a,
                           CONCAT22(in_stack_00000000,unaff_BP));
    uVar1 = LUDIV_at_((int)dividendLo,valueHi,divisorLo,(uint)a);
    valueLo = (uint16_t)uVar1;
  }
  return valueLo;
}



/* 5087:1d7d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

void __cdecl16far upd_usesAlignUp4(void)

{
  byte *flagsPtr;          /* &GUnits[idx].flags */
  uint far *accLo;
  /* GUESS-free: GMapFlags is a 16-bit array, so its view is uint16_t * while accLo stays
     uint * for the sheet gold/trade counters at +0x56/+0x60/+0x7e. */
  uint16_t *flagWord;
  int far *accHi;
  uint8_t *framePtr;       /* &Entities[i].base.animFrame */
  byte leaderIdx;
  short unitY;             /* GUnits[unitIdx].y */
  uint32_t typeRecPtr;     /* AgntAnms[unitType] read as a 32-bit pointer */
  far_t pctOut;
  far_t remainderOut;
  far_t partOut;
  bool foodShort;           /* foodProd lags population */
  bool totalFail;           /* the attack roll fell outside both bands */
  bool unitLost;            /* the unit is removed from its leader */
  char sheetFaction;
  uint16_t randVal;
  uint popLoss;             /* food surplus taken out of the gold word */
  uint foodGain;            /* the surplus added back when foodProd leads */
  uint borrowBit;           /* (uint)(foodLo23 < *accLo) */
  uint foodLow;             /* the sheet's +0x8a food word */
  uint oldAccLo2;           /* a second accumulator's previous low word */
  uint unitXAligned;        /* alignUp4 of the unit's x, for the message */
  uint damage;              /* ovc22_usesLUDIV_at_2's result */
  char *msg;
  uint16_t index;
  uint16_t tableOfs;
  long *plVar15;
  agnt_t far *valueLo;
  unit_t *units;
  int sheetFood62;         /* the sheet's +0x62 counter, tested < 1 */
  uint lidx;                /* the 0..GLeaderCount loop over GLeaderSheets */
  int goldHi58;             /* the sheet's +0x58 gold high word, tested < 1 */
  int goldDiff;             /* the +0x8c minus +0x58 difference */
  int leaderSheetOfs;       /* far_ofs of the leader's sheet (stored, never read) */
  int sheetSegInt;          /* the segment half of GLeaderSheets[idx] */
  int classOfs;             /* gindex * 0x95, the class record offset */
  int sheetOfs;
  entity_t *peVar20;
  int lSheetOfs;           /* another leader's sheet offset (the loops) */
  int otherWord;            /* that leader's +0x80 / +0x8c word */
  int addHi;                /* the high half of the transferAmount amount */
  entity_t *peVar22;
  uint16_t unaff_SI;
  uint16_t unaff_DI;
  uint oldAccLo;           /* an accumulator's previous low word (12 sites) */
  uint sheetWord62;         /* the sheet's +0x62 counter word (3 sites) */
  uint goldWord58;          /* the sheet's +0x58 gold high word (2 sites) */
  uint entIdx;              /* the two 0..EntityCount scans over Entities */
  uint foodLo23;            /* the sheet's +0x60 food word (3 sites) */
  uint scanPos;             /* the descending EntityCount..0 scan cursor */
  uint goldLo;              /* the sheet's gold, low word (1224..1227) */
  int goldHi;              /* its high word, tested against < 1 (1226..1239) */
  int incomeVal;           /* a building's signed income (1235..1238) */
  uint bldByteOfs;         /* bldType * 0x27 (1251..1255) */
  uint accLo2;             /* the accumulator's low word (1274..1277) */
  byte entStatus;           /* ovc22_usesEntities(idx)'s status byte (1773) */
  byte carryBit;            /* the carry out of the LXMUL result (1788/1792) */
  uint healthWord;          /* the entity's health word (1797..1801) */
  uint leaderIdxB;   /* the 0..GLeaderCount loop at 3529 only */
  uint unitIdx;   /* the 0xf8..GUnitCount loops only */
  uint16_t unitsSeg;
  uint16_t sheetSeg;
  uint16_t sheetSeg2;       /* segment half of GLeaderSheets[idx] */
  bool popCarry;            /* carry out of the GPopulation add */
  bool successFlag;         /* the attack roll succeeded */
  far_t table;
  uint8_t *bldTypePtr;      /* &bldType, handed out as a far pointer */
  uint16_t pctSeg;
  uint8_t *partialPtr;      /* &partialWeight */
  uint16_t remainderSeg;
  uint8_t *successPtr;      /* &successWeight */
  undefined1 packHi;         /* the high byte of a packed 32-bit argument */
  undefined1 sayPause;       /* 0x10, ovr_say's duration */
  undefined1 packLo;        /* the low byte of a packed 32-bit argument */
  undefined1 ptrSegHi;
  long a;
  uint income32;            /* BuildingTypes[].income widened to 32 bits */
  int foodDiff;             /* the +0x62 minus +0x80 food difference */
  uint amountLo;            /* the low half of the transferred amount */
  ulong transferAmount;     /* the food amount moved between sheets */
  int budget;              /* 0..3, decremented from the leader's budget */
  uint8_t bldType;
  uint8_t partialWeight;
  uint8_t successWeight;
  char unitDied;            /* set when a unit we killed reached frame 0 */
  uint8_t found;
  byte partySlot;
  uint16_t entY;
  uint entX;
  uint idx;
  uint sendable;            /* how much of popAcc this sheet can take */
  uint popAcc;
  uint popGain;             /* gold / 10, added to GPopulation */
  int waitTicks;           /* 0..199 idle counter */
  int promoteValue;        /* 0, 0x28 or titleIndex * 4 + 0x14 */
  uint tradeAmount;
  uint16_t randRange;       /* 0x96 or 0x5dc, the ovr_randBelow bound */
  byte gindex;
  byte firstLeader;
  uint sheetAA;
  
  a = CONCAT22(unaff_SI,unaff_DI);
  if (!GameRunning) {
    unitDied = '\0';
    found = 0x0;
    for (idx = 0xf8; idx < GUnitCount; idx = idx + 1) {
      flagsPtr = &(GUnits)[idx].flags;
      *flagsPtr = *flagsPtr & 0xfc;
    }
    for (idx = 0; (int)idx < (int)(uint)GLeaderCount; idx = idx + 1) {
      if ((GLeaderSheets[idx])->active != '\0') {
        ovc22_textRingProt((byte)idx);
      }
    }
    GGameState = 0x3e;
    if (DebugVerbose != false) {
      printf("%d \r",GGameState);
    }
    for (unitIdx = 0xf8; unitIdx < GUnitCount; unitIdx = unitIdx + 1) {
      unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
      units = GUnits;
      if ((units[unitIdx].flags & 3) == 0) {
        if ((units[unitIdx].unitType == 0xff) ||
           (typeRecPtr = *(uint32_t *)((uint)units[unitIdx].unitType << 2),
           *(char *)((int)typeRecPtr + 0x3f) == '\0')) {
          randRange = 0x96;
        }
        else {
          randRange = 0x5dc;
        }
        if (units[unitIdx].level != 0) {
          randVal = ovr_randBelow(randRange,0);
          unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
          units = GUnits;
          if ((int)(randVal & 0xff) <
              (int)(100 - (uint)BuildingTypes[(uint)(units + unitIdx)->bldType].durability)) {
            bldType = (units + unitIdx)->bldType;
            units[unitIdx].level = units[unitIdx].level - 1;
            units = GUnits;
            unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
            if (((BuildingTypes[bldType].flags2 & 4) == 0) &&
               ((units[unitIdx].level == 0 ||
                ((BuildingTypes[bldType].flags2 & 0x200) != 0)))) {
              ovc22_usesGUnits(unitIdx,(uint8_t *)
                                      CONCAT13((char)(unitIdx * 9 >> 8),
                                               CONCAT12(units[unitIdx].unitType,_SS)));
            }
            else if (((((bld_inst_t *)BldInstances + bldType)->ofs != 0 ||
                       *(int *)((int)&BldInstances[0].seg + (uint)bldType * 0xc) != 0) ||
                     (BuildingTypes[bldType].flags == '\x10')) &&
                    (unitsSeg = ovc22_usesGOngoingBattle2
                                        (*(byte *)&units[unitIdx].x,*(byte *)&units[unitIdx].y),
                    (char)unitsSeg != '\0')) {
              found = 0x1;
            }
          }
        }
      }
    }
    GGameState = 0x43;
    if (DebugVerbose != false) {
      printf("%d \r",GGameState);
    }
    for (idx = 0; (int)idx < (int)(uint)GLeaderCount; idx = idx + 1) {
      if ((GLeaderSheets[idx])->active != '\0') {
        (GLeaderSheets[idx])->foodSold = 0;
        sheetFaction = *((char far *)GLeaderSheets[idx] + 0x3f);
        if ((sheetFaction == '\0') &&
           ((GLeaderSheets[idx])->foodProd <
            (GLeaderSheets[idx])->population >> 1)) {
          foodShort = true;
        }
        else {
          foodShort = false;
        }
        goldLo = *((uint far *)GLeaderSheets[idx] + 0x54);
        unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        goldHi = *(int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58) + ((int)goldLo >> 0xf) +
                 (uint)CARRY2(*(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56),goldLo);
        if ((goldHi < 1) && (goldHi < 0)) {
          for (unitIdx = 0xf8; unitIdx < GUnitCount; unitIdx = unitIdx + 1) {
            unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
            units = GUnits;
            bldType = (units + unitIdx)->bldType;
            if ((units[unitIdx].unitType == idx) &&
               (BuildingTypes[bldType].income < 0)) {
              incomeVal = BuildingTypes[bldType].income;
              sheetSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              goldHi = *(int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58) + ((int)incomeVal >> 0xf) +
                       (uint)CARRY2(*(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56),incomeVal);
              if ((goldHi < 1) && (goldHi < 0)) {
                if ((sheetFaction == '\0') && (units[unitIdx].level != 0)) {
                  randVal = ovr_randBelow(100,0);
                  unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
                  units = GUnits;
                  if (BuildingTypes[(uint)(units + unitIdx)->bldType].durability <= (byte)randVal) {
                    if (units[unitIdx].level != 0) {
                      units[unitIdx].level = units[unitIdx].level - 1;
                    }
                    units = GUnits;
                    unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
                    if (((BuildingTypes[bldType].flags2 & 4) == 0) &&
                       ((bldByteOfs = 0, units[unitIdx].level == 0 ||
                        (bldByteOfs = (uint)bldType * 0x27, (BuildingTypes[bldType].flags2 & 0x200) != 0))))
                    {
                      ovc22_usesGUnits(unitIdx,(uint8_t *)
                                              CONCAT13((char)((uint)bldByteOfs >> 8),
                                                       CONCAT12((byte)idx,_SS)));
                    }
                    else if (((((bld_inst_t *)BldInstances + bldType)->ofs != 0 ||
                               *(int *)((int)&BldInstances[0].seg + (uint)bldType * 0xc) != 0) ||
                             (BuildingTypes[bldType].flags == '\x10')) &&
                            (unitsSeg = ovc22_usesGOngoingBattle2
                                                (*(byte *)&units[unitIdx].x,
                                                 *(byte *)&units[unitIdx].y), (char)unitsSeg != '\0')
                            ) {
                      found = 0x1;
                    }
                  }
                }
              }
              else {
                income32 = BuildingTypes[bldType].income;
                unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
                accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56);
                accLo2 = *accLo;
                *accLo = *accLo + income32;
                accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58);
                *accHi = *accHi + ((int)income32 >> 0xf) + (uint)CARRY2(accLo2,income32);
              }
            }
          }
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x58) = 0;
          *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x56) = 0;
        }
        else {
          if ((sheetFaction == '\0') && (0 < *((int far *)GLeaderSheets[idx] + 0x54))) {
            popGain = *((int far *)GLeaderSheets[idx] + 0x54) / 10;
          }
          else {
            popGain = 0;
          }
          popCarry = CARRY2(GPopulationLo,popGain);
          GPopulationLo = GPopulationLo + popGain;
          GPopulationHi = GPopulationHi + ((int)popGain >> 0xf) + (uint)popCarry;
          popLoss = *((int far *)GLeaderSheets[idx] + 0x54) - popGain;
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56);
          oldAccLo = *accLo;
          *accLo = *accLo + popLoss;
          accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58);
          *accHi = *accHi + ((int)popLoss >> 0xf) + (uint)CARRY2(oldAccLo,popLoss);
        }
        if ((AgntGs[(uint)(GLeaderSheets[idx])->classStr].flags & 0x100)
            == 0) {
          if ((GLeaderSheets[idx])->foodProd <
              (GLeaderSheets[idx])->population) {
            popAcc = (GLeaderSheets[idx])->population -
                        (GLeaderSheets[idx])->foodProd;
            unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
            sheetFood62 = *(int *)(sheetOfs + 0x62);
            if ((-1 < sheetFood62) && ((0 < sheetFood62 || (*(int *)(sheetOfs + 0x60) != 0)))) {
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              sheetWord62 = *(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x62);
              if ((0x7fff < sheetWord62) ||
                 ((sendable = popAcc, (int)sheetWord62 < 1 && (*(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x60) <= popAcc)
                  ))) {
                sendable = *((uint far *)GLeaderSheets[idx] + 0x60);
              }
              popAcc = popAcc - sendable;
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x60);
              oldAccLo = *accLo;
              *accLo = *accLo - sendable;
              accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x62);
              *accHi = *accHi - (uint)(oldAccLo < sendable);
            }
            if (popAcc != 0) {
              tradeAmount = popAcc;
              if ((GLeaderSheets[idx])->maxTrade < popAcc) {
                tradeAmount = (GLeaderSheets[idx])->maxTrade;
              }
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              goldWord58 = *(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x58);
              if (((int)goldWord58 < 1) && ((0x7fff < goldWord58 || (*(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56) < tradeAmount))))
              {
                tradeAmount = *((uint far *)GLeaderSheets[idx] + 0x56);
              }
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56);
              oldAccLo = *accLo;
              *accLo = *accLo - tradeAmount;
              accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58);
              *accHi = *accHi - (uint)(oldAccLo < tradeAmount);
              popAcc = popAcc - tradeAmount;
              (GLeaderSheets[idx])->foodSold = tradeAmount;
            }
            if (sheetFaction == '\0') {
              for (lidx = 0; (popAcc != 0 && (lidx < (int)(uint)GLeaderCount));
                  lidx = lidx + 1) {
                if (((GLeaderSheets[lidx])->active != '\0') &&
                   ((*((char far *)GLeaderSheets[lidx] + 0x3f) == '\0' &&
                    (unitsSeg = (uint16_t)SEG_OF(GLeaderSheets[lidx]),
                    lSheetOfs = (int)far_ofs_u32(GLeaderSheets[lidx]),
                    *(int *)(lSheetOfs + 0x60) != 0 || *(int *)(lSheetOfs + 0x62) != 0)))) {
                  unitsSeg = (uint16_t)SEG_OF(GLeaderSheets[lidx]);
                  lSheetOfs = (int)far_ofs_u32(GLeaderSheets[lidx]);
                  sheetWord62 = *(uint *)(lSheetOfs + 0x62);
                  if ((sheetWord62 < 0x8000) &&
                     ((0 < (int)sheetWord62 || (popAcc < *(uint *)(lSheetOfs + 0x60))))) {
                    sendable = popAcc;
                  }
                  else {
                    sendable = *((uint far *)GLeaderSheets[lidx] + 0x60);
                  }
                  popAcc = popAcc - sendable;
                  unitsSeg = (uint16_t)SEG_OF(GLeaderSheets[lidx]);
                  lSheetOfs = (int)far_ofs_u32(GLeaderSheets[lidx]);
                  accLo = (uint *)(lSheetOfs + 0x60);
                  oldAccLo = *accLo;
                  *accLo = *accLo - sendable;
                  accHi = (int *)(lSheetOfs + 0x62);
                  *accHi = *accHi - (uint)(oldAccLo < sendable);
                }
              }
            }
            entIdx = 0;
            while ((entIdx < EntityCount && (popAcc != 0))) {
              unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
              peVar20 = Entities;
              if (((*(char *)((int)&peVar20[entIdx].base.entity + 1) == '\0') &&
                  (*(byte *)((int)&peVar20[entIdx].base.entity + 3) == idx)) &&
                 ((foodShort || (1 < peVar20[entIdx].base.animFrame)))) {
                if (peVar20[entIdx].base.animFrame != 0x0) {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  framePtr = &(Entities)[entIdx].base.animFrame;
                  *framePtr = *framePtr + 0xff;
                  if ((Entities)[entIdx].base.animFrame == 0x0) {
                    unitDied = '\x01';
                  }
                }
                popAcc = popAcc - 1;
              }
              entIdx = entIdx + 1;
            }
          }
          else {
            foodGain = (GLeaderSheets[idx])->foodProd -
                     (GLeaderSheets[idx])->population;
            unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x60);
            oldAccLo = *accLo;
            *accLo = *accLo + foodGain;
            accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x62);
            *accHi = *accHi + (uint)CARRY2(oldAccLo,foodGain);
          }
        }
        unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
        sheetFood62 = *(int *)(sheetOfs + 0x62);
        sheetSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
        otherWord = *(int *)(sheetOfs + 0x80);
        if ((otherWord <= sheetFood62) &&
           ((otherWord < sheetFood62 || (*(uint *)(sheetOfs + 0x7e) < *(uint *)(sheetOfs + 0x60))))) {
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          foodLo23 = *(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x60);
          sheetSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
          accLo = (uint *)(sheetOfs + 0x7e);
          borrowBit = (uint)(foodLo23 < *accLo);
          foodDiff = *(int far *)((uint8_t far *)GLeaderSheets[idx] + 0x62) - *(int *)(sheetOfs + 0x80);
          if (((int)(foodDiff - borrowBit) < 0) ||
             ((foodDiff == borrowBit &&
              (foodLo23 - *accLo <= (GLeaderSheets[idx])->maxTrade)))) {
            tradeAmount = *((int far *)GLeaderSheets[idx] + 0x60) -
                       *((int far *)GLeaderSheets[idx] + 0x7e);
          }
          else {
            tradeAmount = (GLeaderSheets[idx])->maxTrade;
          }
          (GLeaderSheets[idx])->foodSold = -tradeAmount;
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56);
          oldAccLo = *accLo;
          *accLo = *accLo + tradeAmount;
          accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58);
          *accHi = *accHi + (uint)CARRY2(oldAccLo,tradeAmount);
          sheetSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          unitsSeg = *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x7e);
          sheetSeg2 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
          *(uint16_t *)(sheetOfs + 0x62) = *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x80);
          *(uint16_t *)(sheetOfs + 0x60) = unitsSeg;
        }
        if (((GLeaderSheets[idx])->housing <
             (GLeaderSheets[idx])->population) &&
           ((AgntGs[(uint)(GLeaderSheets[idx])->classStr].flags & 0x80)
            == 0)) {
          popAcc = (GLeaderSheets[idx])->population -
                      (GLeaderSheets[idx])->housing;
          entIdx = 0;
          while ((entIdx < EntityCount && (popAcc != 0))) {
            unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
            peVar20 = Entities;
            if ((*(byte *)((int)&peVar20[entIdx].base.entity + 3) == idx) &&
               ((((*(char *)((int)&peVar20[entIdx].base.entity + 1) == '\0' &&
                  (peVar20[entIdx].base.destX == 0)) && (peVar20[entIdx].base.destY == 0)) &&
                (3 < peVar20[entIdx].base.animFrame)))) {
              if (DebugVerbose != false) {
                printf("kill 2 \r");
              }
              framePtr = &(Entities)[entIdx].base.animFrame;
              *framePtr = *framePtr + 0xff;
              popAcc = popAcc - 1;
            }
            entIdx = entIdx + 1;
          }
        }
        ovr_ovc25_tickCountdown(idx);
        _fmemset((char far *)GLeaderSheets[idx] + 0x6a, 0, 6);
        _fmemset((char far *)GLeaderSheets[idx] + 0x76, 0, 6);
        randVal = ovr_randBelow(100,0);
        if ((byte)randVal < *((byte far *)GLeaderSheets[idx] + 0xa9)) {
          *((uint16_t far *)GLeaderSheets[idx] + 0x6c) =
               *((uint16_t far *)GLeaderSheets[idx] + 100);
        }
        else {
          (GLeaderSheets[idx])->dirBudget[0] =
               *((uint16_t far *)GLeaderSheets[idx] + 100);
        }
        randVal = ovr_randBelow(100,0);
        if ((byte)randVal < *((byte far *)GLeaderSheets[idx] + 0xa9)) {
          *((uint16_t far *)GLeaderSheets[idx] + 0x6e) =
               *((uint16_t far *)GLeaderSheets[idx] + 0x66);
        }
        else {
          accHi = (int *)((int)(uint32_t)GLeaderSheets[idx] + 0x6c);
          *accHi = *accHi + *((int far *)GLeaderSheets[idx] + 0x66);
        }
        accHi = (int *)((int)(uint32_t)GLeaderSheets[idx] + 0x6e);
        *accHi = *accHi + *((int far *)GLeaderSheets[idx] + 0x68);
        randVal = ovr_randBelow(100,0);
        if ((byte)randVal < *((byte far *)GLeaderSheets[idx] + 0xa9)) {
          *((uint16_t far *)GLeaderSheets[idx] + 0x78) =
               (GLeaderSheets[idx])->ringBudgetIn[0];
        }
        else {
          (GLeaderSheets[idx])->ringBudget[0] =
               (GLeaderSheets[idx])->ringBudgetIn[0];
        }
        randVal = ovr_randBelow(100,0);
        if ((byte)randVal < *((byte far *)GLeaderSheets[idx] + 0xa9)) {
          *((uint16_t far *)GLeaderSheets[idx] + 0x7a) =
               *((uint16_t far *)GLeaderSheets[idx] + 0x72);
        }
        else {
          accHi = (int *)((int)(uint32_t)GLeaderSheets[idx] + 0x78);
          *accHi = *accHi + *((int far *)GLeaderSheets[idx] + 0x72);
        }
        randVal = ovr_randBelow(100,0);
        if ((byte)randVal < *((byte far *)GLeaderSheets[idx] + 0xa9)) {
          *((uint16_t far *)GLeaderSheets[idx] + 0x7c) =
               *((uint16_t far *)GLeaderSheets[idx] + 0x74);
        }
        else {
          accHi = (int *)((int)(uint32_t)GLeaderSheets[idx] + 0x7a);
          *accHi = *accHi + *((int far *)GLeaderSheets[idx] + 0x74);
        }
        *((undefined1 far *)GLeaderSheets[idx] + 0xa7) =
             *((undefined1 far *)GLeaderSheets[idx] + 0xa6);
        if (*((char far *)GLeaderSheets[idx] + 0x3f) != '\0') {
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
          goldHi58 = *(int *)(sheetOfs + 0x58);
          if ((goldHi58 < 1) && ((goldHi58 != 0 || (*(int *)(sheetOfs + 0x56) == 0)))) {
            unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x58) = 0;
            *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x56) = 0x32;
          }
        }
        if (*((char far *)GLeaderSheets[idx] + 0xaa) != '\0') {
          sheetAA = (uint)*((byte far *)GLeaderSheets[idx] + 0xaa);
          for (leaderIdxB = 0; (int)leaderIdxB < (int)(uint)GLeaderCount; leaderIdxB = leaderIdxB + 1) {
            unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
            goldHi58 = *(int *)(sheetOfs + 0x58);
            sheetSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
            otherWord = *(int *)(sheetOfs + 0x8c);
            if ((otherWord <= goldHi58) &&
               ((goldHi58 != otherWord || (*(uint *)(sheetOfs + 0x8a) <= *(uint *)(sheetOfs + 0x56)))))
            break;
            if (((GLeaderSheets[leaderIdxB])->active != '\0') &&
               (((0 < *((int far *)GLeaderSheets[leaderIdxB] + 0x54) &&
                 (*((char far *)GLeaderSheets[leaderIdxB] + 0x3f) == '\0')) &&
                (leaderIdxB != idx)))) {
              transferAmount =
                   ((long)*((int far *)GLeaderSheets[leaderIdxB] + 0x54) * (long)(int)sheetAA &
                   0xffffU) / 100;
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              foodLow = *(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x8a);
              sheetSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
              accLo = (uint *)(sheetOfs + 0x56);
              goldDiff = (*(int far *)((uint8_t far *)GLeaderSheets[idx] + 0x8c) - *(int *)(sheetOfs + 0x58)) -
                       (uint)(foodLow < *accLo);
              if ((goldDiff < 1) && ((goldDiff < 0 || (foodLow - *accLo < (uint)transferAmount)))) {
                unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
                foodLow = *(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x8a);
                sheetSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
                sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
                accLo = (uint *)(sheetOfs + 0x56);
                transferAmount =
                     CONCAT22((*(int far *)((uint8_t far *)GLeaderSheets[idx] + 0x8c) - *(int *)(sheetOfs + 0x58)) -
                              (uint)(foodLow < *accLo),foodLow - *accLo);
              }
              unitsSeg = (uint16_t)SEG_OF(GLeaderSheets[leaderIdxB]);
              lSheetOfs = (int)far_ofs_u32(GLeaderSheets[leaderIdxB]);
              goldHi58 = *(int *)(lSheetOfs + 0x58);
              addHi = (int)(transferAmount >> 0x10);
              if ((goldHi58 <= addHi) &&
                 ((goldHi58 < addHi || (*(uint *)(lSheetOfs + 0x56) < (uint)transferAmount)))) {
                unitsSeg = (uint16_t)SEG_OF(GLeaderSheets[leaderIdxB]);
                leaderSheetOfs = (int)far_ofs_u32(GLeaderSheets[leaderIdxB]);
                transferAmount =
                     CONCAT22(*(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x58),*(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x56));
              }
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              addHi = (int)(transferAmount >> 0x10);
              amountLo = (uint)transferAmount;
              accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56);
              oldAccLo2 = *accLo;
              *accLo = *accLo + amountLo;
              accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58);
              *accHi = *accHi + addHi + (uint)CARRY2(oldAccLo2,amountLo);
              unitsSeg = (uint16_t)SEG_OF(GLeaderSheets[leaderIdxB]);
              leaderSheetOfs = (int)far_ofs_u32(GLeaderSheets[leaderIdxB]);
              accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56);
              oldAccLo2 = *accLo;
              *accLo = *accLo - amountLo;
              accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58);
              *accHi = (*accHi - addHi) - (uint)(oldAccLo2 < amountLo);
            }
          }
        }
        goldHi58 = *((int far *)GLeaderSheets[idx] + 0x58);
        if ((goldHi58 < 1) && (goldHi58 < 0)) {
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x58) = 0;
          *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x56) = 0;
        }
        unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
        goldHi58 = *(int *)(sheetOfs + 0x58);
        sheetSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
        otherWord = *(int *)(sheetOfs + 0x8c);
        if ((otherWord <= goldHi58) &&
           ((otherWord < goldHi58 || (*(uint *)(sheetOfs + 0x8a) < *(uint *)(sheetOfs + 0x56))))) {
          sheetSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          unitsSeg = *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x8a);
          sheetSeg2 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
          *(uint16_t *)(sheetOfs + 0x58) = *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x8c);
          *(uint16_t *)(sheetOfs + 0x56) = unitsSeg;
        }
      }
    }
    GGameState = 0x40;
    if (DebugVerbose != false) {
      printf("%d \r",GGameState);
    }
    for (unitIdx = 0xf8; unitIdx < GUnitCount; unitIdx = unitIdx + 1) {
      unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
      units = GUnits;
      if ((BuildingTypes[(uint)(units + unitIdx)->bldType].flags2 & 0x40) != 0) {
        if (units[unitIdx].timer != 0) {
          units[unitIdx].timer = units[unitIdx].timer - 1;
        }
        unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
        if ((GUnits)[unitIdx].timer == 0) {
          typeRecPtr = *(uint32_t *)((uint)(GUnits)[unitIdx].unitType << 2);
          if (*(char *)((int)typeRecPtr + 0x3f) == '\0') {
            ovr_play_sfx(81,0,0);
            unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
            unitY = (GUnits)[unitIdx].y;
            packHi = (undefined1)unitY;
            ptrSegHi = (undefined1)((uint)unitY >> 8);
            sayPause = 0x10;
            unitXAligned = ovr_alignUp4((GUnits)[unitIdx].x,0,0);
            msg = ovr_fmVsprintf("Mine exhausted at (%d, %d).",
                                     (char *)CONCAT13(ptrSegHi,CONCAT12(packHi,unitXAligned)));
            ovr_say(msg,sayPause);
            ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
          }
          ovc22_usesGUnits(unitIdx,(uint8_t *)
                                  CONCAT13((char)(unitIdx * 9 >> 8),
                                           CONCAT12((GUnits)[unitIdx].unitType,_SS)));
        }
      }
    }
    GGameState = 0x42;
    if (DebugVerbose != false) {
      printf("%d \r",GGameState);
    }
    ovr_driver_clearMapFlagsRect((uint32_t)GMapFlags,0,0,0x93,0x3b,0xfff7,0x3b,0xf7);
    for (idx = 0; idx < SquareRecCount; idx = idx + 1) {
      flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[*(int *)((uint8_t *)&SquareRecs[idx] + 2)]
                             + *(int *)(idx * 0x13));
      *flagWord = *flagWord | 8;
    }
    if (EntityCount <= EntityScanPos) {
      EntityScanPos = 0;
      for (idx = 0; (int)idx < (int)(uint)GLeaderCount; idx = idx + 1) {
        if ((GLeaderSheets[idx])->active != '\0') {
          sheetSegInt = ((int *)(idx * 4))[1];
          memcpy((char *)CONCAT22(((int *)(idx * 4))[1],
                                  (char *)(*(int *)(idx * 4) + 0x8e)),
                 (char *)CONCAT13((char)((uint)sheetSegInt >> 8),
                                  CONCAT12((char)sheetSegInt,*(int *)(idx * 4) + 0x94)),3);
        }
      }
    }
    waitTicks = 0;
    firstLeader = ovr_manage_findFirstLeader();
    if ((firstLeader == 0xff) || (GCanPromote == '\0')) {
      promoteValue = 0;
    }
    else if ((GLeaderSheets[firstLeader])->titleIndex < 5) {
      promoteValue = 0x28;
    }
    else {
      promoteValue = (uint)(GLeaderSheets[firstLeader])->titleIndex * 4 + 0x14;
    }
    for (idx = EntityScanPos; idx < EntityCount; idx = idx + 1) {
      unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
      peVar20 = Entities;
      if (((*(char *)((int)&peVar20[idx].base.entity + 1) == '\0') &&
          (peVar20[idx].base.destX == 0)) && (peVar20[idx].base.destY == 0)) {
        gindex = peVar20[idx].base.gindex;
        sheetFaction = AgntGs[(uint)gindex].ai;
        leaderIdx = *(byte *)((int)&peVar20[idx].base.entity + 3);
        successFlag = false;
        unitLost = false;
        totalFail = false;
        if (AgntGs[(uint)gindex].shortName[3] == -1) {
          successFlag = true;
        }
        else {
          partySlot = (GLeaderSheets[leaderIdx])->partySlot;
          if (partySlot < 5) {
            entY = peVar20[idx].base.y;
            entX = ovr_alignUp4(((peVar20 + idx)->base).x,0,0);
            randVal = 0x2410;
            if (((*(short (*) [60] [148])GMapFlags)[entY][entX] & 8U) == 0) {
              successWeight = 0x22;
              partialWeight = 0x21;
              bldType = 0x22;
            }
            else {
              packLo = (undefined1)_SS;
              packHi = (undefined1)(_SS >> 8);
              successPtr = &successWeight;
              partialPtr = &partialWeight;
              bldTypePtr = &bldType;
              index = CONCAT11((char)((uint)bldTypePtr >> 8),partySlot);
              pctSeg = _SS;
              remainderSeg = _SS;
              tableOfs = ovr_attact_usesSquareRecCount(entX,entY);
              table.seg = randVal;
              table.ofs = tableOfs;
              pctOut.seg = pctSeg;
              pctOut.ofs = (uint16_t)bldTypePtr;
              remainderOut.seg = remainderSeg;
              remainderOut.ofs = (uint16_t)partialPtr;
              (*(uint8_t *)((uint8_t *)&(partOut.seg))) = packLo;
              partOut.ofs = (uint16_t)successPtr;
              (*(uint8_t *)((uint8_t *)&(partOut.seg) + 1)) = packHi;
              ovr_attact_compute3(table,index,pctOut,remainderOut,partOut);
            }
          }
          else {
            successWeight = 0x22;
            partialWeight = 0x21;
            bldType = 0x22;
          }
          randVal = ovr_randBelow(100,0);
          if ((byte)randVal < successWeight) {
            successFlag = true;
          }
          else if ((randVal & 0xff) < (uint)partialWeight + (uint)successWeight) {
            unitLost = true;
          }
          else {
            totalFail = true;
          }
        }
        if ((totalFail) &&
           (unitsSeg = (uint16_t)((ulong)Entities >> 0x10),
           randVal = (Entities)[idx].base.y,
           sheetFaction = ovr_ovc23_tickRecordsAt
                              (((Entities + idx)->base).x,randVal,sheetFaction,
                               (char)randVal), sheetFaction == '\0')) {
          if ((partialWeight == 0x0) && (successWeight == 0x0)) {
            randVal = ovr_randBelow(2,0);
            if ((randVal & 0xff) == 0) {
              successFlag = true;
            }
            else {
              unitLost = true;
            }
          }
          else {
            randVal = ovr_randBelow((uint)partialWeight + (uint)successWeight,0);
            if ((byte)randVal < successWeight) {
              successFlag = true;
            }
            else {
              unitLost = true;
            }
          }
        }
        if ((successFlag) && (entStatus = ovc22_usesEntities(idx), (entStatus & 0xff) == 0)) {
          unitLost = true;
        }
        if (unitLost) {
          if ((AgntGs[(uint)gindex].shortName[3] != -1) &&
             (leaderIdx != 0xff)) {
            if ((*(char *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x3f) != '\0') ||
               (Entities[idx].base.level <
                *(byte *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x53))) {
              packLo = (undefined1)promoteValue;
              packHi = (undefined1)((uint)promoteValue >> 8);
              ovc22_usesLUDIV_at_((entity_t *)
                                  CONCAT13((char)((ulong)Entities >> 0x18),
                                           CONCAT12((char)((ulong)Entities >> 0x10),
                                                    Entities + idx)));
              carryBit = 0;
              plVar15 = LXMUL_at_((long *)CONCAT11(packHi,packLo),a,transferAmount);
              peVar20 = Entities + idx;
              valueLo = ovr_ovc15_textError((entity_t *)CONCAT22(DAT_2000_d190,peVar20),
                                            (agnt_t far *)(CONCAT12((carryBit & 1) != 0,plVar15) >> 1));
              damage = ovc22_usesLUDIV_at_2
                                 ((uint16_t)valueLo,(uint16_t)peVar20,CONCAT11(packHi,packLo));
              unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
              peVar22 = Entities;
              healthWord = *(uint *)&peVar22[idx].base.health;
              *(uint *)&peVar22[idx].base.frameIndex =
                   (int)&(peVar20->base).x +
                   (uint)CARRY2(healthWord,damage) + *(int *)&peVar22[idx].base.frameIndex;
              *(uint *)&peVar22[idx].base.health = healthWord + damage;
              ovr_ovc41_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                          CONCAT12((char)((ulong)Entities >> 0x10),
                                                   Entities + idx)));
            }
          }
          ovc22_usesEntities2(idx);
          ovc22_usesEntities3(idx);
          ovc22_usesEntities4(idx);
        }
        budget = (uint)(Entities)[idx].base.animFrame -
                    (uint)*(byte *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0xa4);
        if (0 < budget) {
          if (3 < budget) {
            budget = 3;
          }
          if (budget == 3) {
            if (*(int *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x92) == 0) {
              budget = 2;
            }
            else {
              accHi = (int *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x92);
              *accHi = *accHi + -1;
            }
          }
          if (budget == 2) {
            if (*(int *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x90) == 0) {
              budget = 1;
            }
            else {
              accHi = (int *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x90);
              *accHi = *accHi + -1;
            }
          }
          if (budget == 1) {
            if (*(int *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x8e) == 0) {
              budget = 0;
            }
            else {
              accHi = (int *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x8e);
              *accHi = *accHi + -1;
            }
          }
          (Entities)[idx].base.animFrame =
               *(char *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0xa4) + (char)budget;
        }
        waitTicks = waitTicks + 1;
        if (199 < waitTicks) break;
      }
    }
    EntityScanPos = idx;
    mapDirty = 1;
    ovr_unit_usesAlignUp4();
    GGameState = 0x44;
    if (DebugVerbose != false) {
      printf("%d \r",GGameState);
    }
    scanPos = EntityCount;
    if (unitDied != '\0') {
      while (idx = scanPos - 1, -1 < (int)idx) {
        unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
        peVar20 = Entities;
        scanPos = idx;
        if (peVar20[idx].base.animFrame == 0x0) {
          if (AgntGs[(uint)peVar20[idx].base.gindex].ai == '\0') {
            ovr_alignUp4(((peVar20 + idx)->base).x,(char)peVar20[idx].base.y,0);
            classOfs = (uint)(Entities)[idx].base.gindex * 0x95;
            msg = ovr_fmVsprintf("Intelligence reports %s unit died of starvation. (%d, %d)",
                                     (char *)CONCAT22(*(uint16_t *)
                                                       ((int)&worldMenuLabels[1].ofs + 1 + classOfs),
                                                      (char *)*(uint16_t *)
                                                               ((int)&worldMenuLabels[0].seg + 1 +
                                                               classOfs)));
            asm { mov randVal,dx };
            ovr_uiNotify(msg,randVal,(char)randVal);
          }
          ovr_ovc15_removeEntity(idx);
          scanPos = idx;
        }
      }
    }
    if (found != 0x0) {
      ovr_constr_flushDirtyRects();
    }
  }
  return;
}



/* 5087:3a6b */

/* [R2] string "arena" */

bool __cdecl16far ovc22_textArena2(uint x,int y)

{
  /* Re-derived: requires ovc22_textArena(x, y); the unit on GUnitGrid[x][y] must have a non-zero
     bldType and no 0x1000 bit in BuildingTypes[..].word_0x121; x must be at least 4 with the three
     cells to its left holding byte_0x11b below 2, 3 and 4; and no construction record may cover
     the cell.  The export's `[-1]` row trick becomes GUnitGrid[x-1] etc. */
  short (*grid) [148] [60];
  unit_t *units;
  uint recIdx;

  if (ovc22_textArena(x,y) == false) {
    return false;
  }
  grid = (short (*) [148] [60])GUnitGrid;
  units = GUnits;
  if ((units[(*grid)[x][y]].bldType != 0) &&
     ((BuildingTypes[(uint)units[(*grid)[x][y]].bldType].flags2 & 0x1000) == 0)) {
    return false;
  }
  if ((int)x < 4) {
    return false;
  }
  if (BuildingTypes[(uint)units[(*grid)[x + -1][y]].bldType].size >= 2) {
    return false;
  }
  if (BuildingTypes[(uint)units[(*grid)[x + -2][y]].bldType].size >= 3) {
    return false;
  }
  if (BuildingTypes[(uint)units[(*grid)[x + -3][y]].bldType].size >= 4) {
    return false;
  }
  for (recIdx = 0; recIdx < (int)(uint)GRecordCount; recIdx = recIdx + 1) {
    if (((GRecords[recIdx].y == y) && (GRecords[recIdx].x <= x)) &&
       (x < GRecords[recIdx].x + (uint)BuildingTypes[GRecords[recIdx].reserved08].size)) {
      return false;
    }
  }
  return true;
}



/* 5087:3c93 */

/* [R4] calls ovr_alignUp4 */

uint __cdecl16far ovc22_usesAlignUp4(int x,int y,byte unitType,uint mask)

{
  /* 5087:3c93 (file 0x46371 tail), re-derived: the original ends with `mov al,1`
     (0x4638B) and `mov al,0` (0x4638F), so the result is a boolean - the exported
     `return CONCAT11((char)(uVar3 >> 8),1);` / `return uVar3 & 0xff00;` were modelling
     the stale AH that a preceding `imul` left behind, and `uVar3` was simultaneously used
     as the loop's `(uVar2 + iVar4) * 2`, i.e. two roles in one slot. */
  int unitIdx;
  byte cellUnitType;
  uint alignedX;
  uint acc;
  int k;

  unitIdx = (*(short (*) [148] [60])GUnitGrid)[x][y];
  cellUnitType = (GUnits)[unitIdx].unitType;
  if (cellUnitType == unitType) {
    alignedX = ovr_alignUp4(x,0,0);
    acc = 0;
    for (k = -2; k < 2; k = k + 1) {
      acc = acc | (*(short (*) [60] [148])GMapFlags)[y][alignedX + k];
    }
    if ((mask & acc) == 0) {
      return 1;
    }
  }
  return 0;
}



/* 5087:3d25 */

/* [R6] touches GUnitGrid, GUnits */

uint __cdecl16far ovc22_usesGUnitGrid(int x,int y)

{
  uint gridVal;
  uint btype;
  uint result;
  uint recIdx;
  
  gridVal = (*(short (*) [148] [60])GUnitGrid)[x][y];
  if (gridVal < 0xf8) {
    recIdx = ovr_ovc23_findRecordAt(x,y,0);
    if (recIdx == 0xffff) {
      btype = (uint)(GUnits + btype)->bldType;
      if (((*(uint *)((uint8_t *)&BuildingTypes[btype] + 19) & 2) == 0) &&
         ((*(uint *)((uint8_t *)&BuildingTypes[btype] + 19) & 0x20) == 0)) {
        result = 0;
      }
    }
    else {
      result = 0;
    }
  }
  else {
    result = 0;
  }
  return result;
}



/* 5087:3dc7 */

/* [R6] touches GUnitGrid, GUnits */

uint __cdecl16far ovc22_usesGUnitGrid2(int x,int y,byte partyIndex)

{
  uint gridVal;
  uint btype;
  uint result;
  uint recIdx;
  
  if (((GLeaderSheets[partyIndex])->flags5d & 4) == 0) {
    gridVal = (*(short (*) [148] [60])GUnitGrid)[x][y];
    if (gridVal < 0xf8) {
      recIdx = ovr_ovc23_findRecordAt(x,y,0);
      if (recIdx == 0xffff) {
        btype = (uint)(GUnits + btype)->bldType;
        if ((*(uint *)((uint8_t *)&BuildingTypes[btype] + 19) & 0x20) == 0) {
          result = 0;
        }
        else if (*(char *)((uint8_t *)&BuildingTypes[btype] + 35) == '\0') {
          if (*((char far *)GLeaderSheets[partyIndex] + 0x2f) == '\x05') {
            result = result + 0x18;
          }
          else {
            result = result + 6;
          }
        }
      }
      else {
        result = 0;
      }
    }
    else {
      result = 0;
    }
  }
  else {
    result = 0;
  }
  return result;
}



/* 5087:3eb1 */

/* Returns the type of the completed building at (x,y), or 0. */

uint __cdecl16far ovc22_buildingTypeAt(int x,int y)

{
  uint gridVal;
  uint btype;
  uint result;
  uint recIdx;
  
  gridVal = (*(short (*) [148] [60])GUnitGrid)[x][y];
  if (gridVal < 0xf8) {
    recIdx = ovr_ovc23_findRecordAt(x,y,0);
    if (recIdx == 0xffff) {
      btype = (uint)(GUnits + btype)->bldType;
      if ((*(uint *)((uint8_t *)&BuildingTypes[btype] + 19) & 0x20) == 0) {
        result = 0;
      }
    }
    else {
      result = 0;
    }
  }
  else {
    result = 0;
  }
  return result;
}



/* 5087:3f3b */

/* Returns whether the map flags at (x,y) have any bit of the mask set (0 outside the map). */

int __cdecl16far ovc22_testMapFlags(int x,int y,uint mask)

{
  bool isArena;
  int result;
  byte maskHi;
  
  isArena = ovc22_textArena(x,y);
  if (isArena) {
    maskHi = (byte)(mask >> 8);
    if (((*(short (*) [60] [148])GMapFlags)[y][x] & mask) == 0) {
      result = CONCAT11(maskHi,1);
    }
    else {
      result = (uint)maskHi << 8;
    }
  }
  else {
    result = 0;
  }
  return result;
}



/* 5087:3f8d */

/* [R6] touches GMapFlags */

uint16_t __cdecl16far ovc22_usesGMapFlags2(char skipCheck,int x1,int y1,int x2,int y2)

{
  uint16_t axIn;           /* AX on entry, as the image's caller passed it */
  uint16_t result;
  int iVar2;
  byte bVar3;
  int dy;
  int dx;
  int stepY;
  int stepX;
  char toggle;
  
  if (skipCheck == '\0') {
    stepX = ovr_ovc07_signum(x2 - x1);
    stepY = ovr_ovc07_signum(y2 - y1);
    if ((stepX != 0) || (stepY != 0)) {
      toggle = '\0';
      while( true ) {
        dx = stepX;
        dy = stepY;
        result = (uint16_t)((ulong)GMapFlags >> 0x10);
        iVar2 = stepY;
        if ((stepX != 0) &&
           (iVar2 = (x1 + stepX) * 2,
           ((*(short (*) [60] [148])GMapFlags)[y1][x1 + stepX] & 3U) != 0)) {
          dx = 0;
        }
        bVar3 = (byte)((uint)iVar2 >> 8);
        if ((stepY != 0) &&
           (bVar3 = (byte)((uint)(x1 * 2) >> 8),
           ((*(short (*) [60] [148])GMapFlags)[y1 + stepY][x1] & 3U) != 0)) {
          dy = 0;
        }
        if ((dx == 0) && (dy == 0)) break;
        if ((dy == 0) || ((dx != 0 && (toggle != '\0')))) {
          x1 = x1 + dx;
          if (x1 == x2) {
            if (y1 == y2) {
              return 1;
            }
            stepX = 0;
          }
        }
        else {
          y1 = y1 + dy;
          if (y1 == y2) {
            if (x1 == x2) {
              return 1;
            }
            stepY = 0;
          }
        }
        toggle = '\x01' - (toggle != '\0');
      }
      return (uint)bVar3 << 8;
    }
    result = 1;
  }
  else {
    result = CONCAT11((char)((uint)axIn >> 8),1);
  }
  return result;
}



/* 5087:40ad */

/* [R4] calls ovr_alignUp4 */

uint16_t __cdecl16far
ovc22_usesAlignUp42(uint16_t *xOut,uint16_t *yOut,uint8_t classIndex,uint16_t blockedFlags)

{
  /* Re-derived: the first construction record of the given class whose five map-flag words
     around alignUp4(x) share no bits with blockedFlags, returning its aligned column and row;
     1 when found, 0 otherwise.  The stale-AH success return is simply 1. */
  uint16_t recY;
  uint recX;
  int k;
  uint flagAcc;
  uint recIdx;

  recIdx = 0;
  do {
    if (GRecordCount <= recIdx) {
      return 0;
    }
    if (GRecords[recIdx].party == classIndex) {
      recX = ovr_alignUp4(GRecords[recIdx].x,0,0);
      recY = GRecords[recIdx].y;
      flagAcc = 0;
      for (k = -2; k < 2; k = k + 1) {
        flagAcc = flagAcc | (*(short (*) [60] [148])GMapFlags)[recY][recX + k];
      }
      if ((blockedFlags & flagAcc) == 0) {
        *xOut = recX;
        *yOut = recY;
        return 1;
      }
    }
    recIdx = recIdx + 1;
  } while( true );
}



/* 5087:416e */

/* Scans cells in expanding rings around a start point and returns 1 for the first cell that passes
   the requested occupancy/flag/arena checks, writing its coordinates through the out pointers. */

uint __cdecl16far
ovc22_searchCellsAround(uint *xPtr,uint *yPtr,byte yOutOfs,byte yOutSeg,char partyIndex)

{
  byte *pbVar1;
  byte skipCheck;
  uint x1;
  uint y1;
  bool textArenaRes;
  uint16_t mask;
  uint checkRes;
  uint16_t alignRes;
  uint16_t flagsRes;
  uint32_t *puVar6;
  uint *xSeg;
  char dy;
  char dx;
  int step;
  int radius;
  
  x1 = *(uint *)CONCAT22((uint *)xPtr,xSeg);
  y1 = *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)));
  skipCheck = *(byte *)((int)*(uint32_t *)((uint)(*(uint8_t *)((uint8_t *)&(yPtr) + 2)) << 2) + 0x3f);
  mask = 0x1000 << (skipCheck & 0x1f);
  checkRes = ovc22_usesAlignUp4(*(uint *)CONCAT22((uint *)xPtr,xSeg),
                             *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2)),mask);
  if ((char)checkRes == '\0') {
    alignRes = ovc22_usesAlignUp42((uint16_t *)CONCAT22((uint *)xPtr,xSeg),
                                (uint16_t *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2)),mask);
    if ((char)alignRes == '\0') {
      for (radius = 1; radius < 0x94; radius = radius + 1) {
        for (step = 0; step <= radius; step = step + 1) {
          for (dx = -1; dx < '\x02'; dx = dx + '\x02') {
            for (dy = -1; dy < '\x02'; dy = dy + '\x02') {
              *(uint *)CONCAT22((uint *)xPtr,xSeg) = x1 + dx * step;
              if (dx < '\0') {
                *(uint *)CONCAT22((uint *)xPtr,xSeg) =
                     *(uint *)CONCAT22((uint *)xPtr,xSeg) - 1;
              }
              *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) = y1 + dy * radius;
              if ((((3 < *(uint *)CONCAT22((uint *)xPtr,xSeg)) &&
                   (*(uint *)CONCAT22((uint *)xPtr,xSeg) < 0x90)) &&
                  (*(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) != 0)) &&
                 (*(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) < 0x3b)) {
                checkRes = ovc22_usesAlignUp4(*(uint *)CONCAT22((uint *)xPtr,xSeg),
                                           *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2)),
                                           mask);
                if ((char)checkRes != '\0') {
                  return checkRes & 0xff00;
                }
                if ((skipCheck != 0) &&
                   (checkRes = ovc22_usesGUnitGrid(*(uint *)CONCAT22((uint *)xPtr,xSeg),
                                                *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))),
                   checkRes != 0)) {
                  return CONCAT11((char)(checkRes >> 8),1);
                }
                if (((yOutOfs == 3) &&
                    (flagsRes = ovc22_testMapFlags(*(uint *)CONCAT22((uint *)xPtr,xSeg),
                                                *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),mask),
                    (char)flagsRes != '\0')) &&
                   (checkRes = ovc22_usesGMapFlags2
                                      (skipCheck,x1,y1,
                                       *(uint *)CONCAT22((uint *)xPtr,xSeg),
                                       *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))),
                   (char)checkRes != '\0')) {
                  return checkRes & 0xff00;
                }
                if ((((yOutOfs & 1) == 0) && (yOutSeg == 0)) &&
                   (textArenaRes = ovc22_textArena2(*(uint *)CONCAT22((uint *)xPtr,xSeg),
                                             *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))), textArenaRes)) {
                  flagsRes = ovc22_usesGMapFlags2
                                    (skipCheck,x1,y1,
                                     *(uint *)CONCAT22((uint *)xPtr,xSeg),
                                     *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))));
                  if ((char)flagsRes != '\0') {
                    return 1;
                  }
                }
                if (((yOutOfs & 2) == 0) &&
                   (checkRes = ovc22_usesGUnitGrid2
                                      (*(uint *)CONCAT22((uint *)xPtr,xSeg),
                                       *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2))),
                   checkRes != 0)) {
                  flagsRes = ovc22_usesGMapFlags2
                                    (skipCheck,x1,y1,
                                     *(uint *)CONCAT22((uint *)xPtr,xSeg),
                                     *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))));
                  if ((char)flagsRes != '\0') {
                    return 1;
                  }
                }
              }
              *(uint *)CONCAT22((uint *)xPtr,xSeg) = x1 + dx * radius;
              if (dx < '\0') {
                *(uint *)CONCAT22((uint *)xPtr,xSeg) =
                     *(uint *)CONCAT22((uint *)xPtr,xSeg) - 1;
              }
              *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) = y1 + dy * step;
              if (((3 < *(uint *)CONCAT22((uint *)xPtr,xSeg)) &&
                  (*(uint *)CONCAT22((uint *)xPtr,xSeg) < 0x90)) &&
                 ((*(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) != 0 &&
                  (*(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) < 0x3b)))) {
                checkRes = ovc22_usesAlignUp4(*(uint *)CONCAT22((uint *)xPtr,xSeg),
                                           *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2)),
                                           mask);
                if ((char)checkRes != '\0') {
                  return checkRes & 0xff00;
                }
                if ((skipCheck != 0) &&
                   (checkRes = ovc22_usesGUnitGrid(*(uint *)CONCAT22((uint *)xPtr,xSeg),
                                                *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))),
                   checkRes != 0)) {
                  return CONCAT11((char)(checkRes >> 8),1);
                }
                if ((((yOutOfs & 3) == 3) &&
                    (flagsRes = ovc22_testMapFlags(*(uint *)CONCAT22((uint *)xPtr,xSeg),
                                                *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),mask),
                    (char)flagsRes != '\0')) &&
                   (checkRes = ovc22_usesGMapFlags2
                                      (skipCheck,x1,y1,
                                       *(uint *)CONCAT22((uint *)xPtr,xSeg),
                                       *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))),
                   (char)checkRes != '\0')) {
                  return checkRes & 0xff00;
                }
                if ((((yOutOfs & 1) == 0) && (yOutSeg == 0)) &&
                   (textArenaRes = ovc22_textArena2(*(uint *)CONCAT22((uint *)xPtr,xSeg),
                                             *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))), textArenaRes)) {
                  flagsRes = ovc22_usesGMapFlags2
                                    (skipCheck,x1,y1,
                                     *(uint *)CONCAT22((uint *)xPtr,xSeg),
                                     *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))));
                  if ((char)flagsRes != '\0') {
                    return 1;
                  }
                }
                if (((yOutOfs & 2) == 0) &&
                   (checkRes = ovc22_usesGUnitGrid2
                                      (*(uint *)CONCAT22((uint *)xPtr,xSeg),
                                       *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2))),
                   checkRes != 0)) {
                  flagsRes = ovc22_usesGMapFlags2
                                    (skipCheck,x1,y1,
                                     *(uint *)CONCAT22((uint *)xPtr,xSeg),
                                     *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))));
                  if ((char)flagsRes != '\0') {
                    return 1;
                  }
                }
              }
            }
          }
        }
      }
      puVar6 = (uint32_t *)0x0;
      if ((yOutOfs & 1) == 0) {
        puVar6 = (uint32_t *)((uint)(*(uint8_t *)((uint8_t *)&(yPtr) + 2)) << 2);
        pbVar1 = (byte *)((int)*puVar6 + 0x5d);
        *pbVar1 = *pbVar1 | 2;
      }
      *(uint *)CONCAT22((uint *)xPtr,xSeg) = x1;
      *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) = y1;
      checkRes = (uint)puVar6 & 0xff00;
    }
    else {
      checkRes = alignRes & 0xff00;
    }
  }
  else {
    checkRes = checkRes & 0xff00;
  }
  return checkRes;
}



/* 5087:4576 */

/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc22_usesRandBelow(byte partyIndex,uint16_t x,uint16_t y)

{
  byte classStr;
  uint bldType;
  uint16_t roll;
  int goldHi;
  int classId;
  
  if ((((GLeaderSheets[partyIndex])->flags5d & 2) == 0) ||
     (((GLeaderSheets[partyIndex])->flags5d & 4) == 0)) {
    if (*((char far *)GLeaderSheets[partyIndex] + 0x3f) == '\0') {
      bldType = ovc22_usesGUnitGrid2(x,y,partyIndex);
      if ((*(uint *)((uint8_t *)&BuildingTypes[bldType] + 19) & 0x20) == 0) {
        if (((GLeaderSheets[partyIndex])->flags5d & 2) == 0) {
          if ((int)(uint16_t)((GLeaderSheets[partyIndex])->gold) == 0 && (int)((GLeaderSheets[partyIndex])->gold >> 16) == 0) {
            bldType = 0;
          }
          else {
            if ((GLeaderSheets[partyIndex])->foodProd <
                (uint)((int)((GLeaderSheets[partyIndex])->population) * 2 + (int)((GLeaderSheets[partyIndex])->population)) >> 2) {
              bldType = 0;
            }
            else {
              classId = ovr_bldng_getClass(partyIndex);
              bldType = ovr_bldng_usesRandBelow((byte)classId);
              bldType = bldType & 0xff;
              goldHi = (int)((GLeaderSheets[partyIndex])->gold >> 16);
              if ((goldHi < 0) ||
                 ((goldHi == 0 && ((uint16_t)((GLeaderSheets[partyIndex])->gold) < *(uint *)((uint8_t *)&BuildingTypes[bldType] + 23))))) {
                bldType = 0;
              }
            }
          }
        }
        else {
          bldType = 0;
        }
      }
    }
    else {
      bldType = ovc22_usesGUnitGrid(x,y);
      if ((*(uint *)((uint8_t *)&BuildingTypes[bldType] + 19) & 2) == 0) {
        roll = ovr_randBelow(2,0);
        if (((roll & 0xff) == 0) && ((*(uint *)((uint8_t *)&BuildingTypes[bldType] + 19) & 0x20) != 0)) {
          if (*(char *)((uint8_t *)&BuildingTypes[bldType] + 35) == '\0') {
            bldType = bldType + 6;
          }
        }
        else {
          roll = ovr_randBelow(8,0);
          if (((roll & 0xff) == 0) ||
             ((roll = ovr_randBelow(3,0), (roll & 0xff) == 0 &&
              ((GLeaderSheets[partyIndex])->foodProd <
               (GLeaderSheets[partyIndex])->population)))) {
            roll = ovr_randBelow(3,0);
            bldType = (roll & 0xff) + 1;
          }
          else {
            roll = ovr_randBelow(0xc,0);
            if ((roll & 0xff) == 0) {
              roll = ovr_randBelow(3,0);
              bldType = (roll & 0xff) + 0x2b;
              goldHi = (int)((GLeaderSheets[partyIndex])->gold >> 16);
              if (-1 < goldHi) {
                if (goldHi != 0) {
                  return bldType;
                }
                if (*(uint *)((uint8_t *)&BuildingTypes[bldType] + 23) <= (uint16_t)((GLeaderSheets[partyIndex])->gold)) {
                  return bldType;
                }
              }
            }
            roll = ovr_randBelow(0xc,0);
            if ((roll & 0xff) == 0) {
              roll = ovr_randBelow(3,0);
              bldType = (roll & 0xff) + 0xec;
              goldHi = (int)((GLeaderSheets[partyIndex])->gold >> 16);
              if (-1 < goldHi) {
                if (goldHi != 0) {
                  return bldType;
                }
                if (*(uint *)((uint8_t *)&BuildingTypes[bldType] + 23) <= (uint16_t)((GLeaderSheets[partyIndex])->gold)) {
                  return bldType;
                }
              }
            }
            classStr = (GLeaderSheets[partyIndex])->classStr;
            roll = ovr_randBelow(3,0);
            bldType = (roll & 0xff) +
                    (uint)*(byte *)((int)&worldMenuLabels[0xb].ofs + 1 + (uint)classStr * 0x95);
            goldHi = (int)((GLeaderSheets[partyIndex])->gold >> 16);
            if ((goldHi < 0) ||
               ((goldHi == 0 && ((uint16_t)((GLeaderSheets[partyIndex])->gold) < *(uint *)((uint8_t *)&BuildingTypes[bldType] + 23))))) {
              bldType = (uint)*(byte *)((int)&worldMenuLabels[0xb].ofs + 1 + (uint)classStr * 0x95);
            }
          }
        }
      }
      else {
        roll = ovr_randBelow(0x14,0);
        if ((roll & 0xff) == 0) {
          bldType = 0x72;
        }
        else {
          roll = ovr_randBelow(4,0);
          if ((roll & 0xff) == 0) {
            bldType = 0x71;
          }
          else {
            bldType = 0x70;
          }
        }
      }
    }
  }
  else {
    bldType = 0;
  }
  return bldType;
}



/* 5087:4975 */

/* [R4] calls ovr_randBelow */

void __cdecl16far ovc22_usesRandBelow2(byte partyIndex,uint16_t outFlag,uint16_t outFlagSeg)

{
  uint *goldLoPtr;
  int *goldHiPtr;
  uint oldLo;
  uint bldWord23;
  uint32_t sheetPtr;
  uint16_t randPick;
  uint16_t searchStatus;   /* status byte returned by ovc22_searchCellsAround */
  uint16_t bldPick;        /* BuildingTypes index returned by ovc22_usesRandBelow */
  int sheetOfs;
  int unitCount;
  char siArg;              /* value passed in SI; the image's register-passed trailing argument */
  uint16_t unitsSeg;
  byte bldType;
  uint16_t y;
  uint16_t x;
  byte listIndex;
  undefined1 roll;
  char matchIdx;
  char targetIdx;
  byte hasUnits;
  byte blockFlags;
  
  listIndex = ListCount;
  if (*((char far *)GLeaderSheets[partyIndex] + 0xa8) != '\0') {
    randPick = ovr_randBelow(100,0);
    roll = (undefined1)randPick;
    if ((randPick & 0xff) <
        ((uint)*((byte far *)GLeaderSheets[partyIndex] + 0xa8) * 100) /
        (*((byte far *)GLeaderSheets[partyIndex] + 0xa8) + 1)) {
      randPick = ovr_randBelow((uint)*((byte far *)GLeaderSheets[partyIndex] + 0xa8),0);
      targetIdx = (char)randPick;
      matchIdx = '\0';
      for (listIndex = 0; listIndex < ListCount; listIndex = listIndex + 1) {
        unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
        if ((BuildingTypes[(uint)(GUnits + *(int *)((uint)listIndex * 2 + -0x6d44))->bldType].unitType == '\x12') &&
           ((GUnits)[*(int *)((uint)listIndex * 2 + -0x6d44)].unitType == partyIndex)) {
          if (matchIdx == targetIdx) break;
          matchIdx = matchIdx + '\x01';
        }
      }
    }
  }
  if (listIndex < ListCount) {
    unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
    x = (GUnits)[*(int *)((uint)listIndex * 2 + -0x6d44)].x;
    y = (GUnits)[*(int *)((uint)listIndex * 2 + -0x6d44)].y;
  }
  else {
    x = (GLeaderSheets[partyIndex])->x;
    y = (GLeaderSheets[partyIndex])->y;
  }
  unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[partyIndex] >> 0x10);
  sheetOfs = (int)(uint32_t)GLeaderSheets[partyIndex];
  unitCount = *(int *)(sheetOfs + 0x58);
  if ((unitCount < 1) && ((unitCount < 0 || (*(uint *)(sheetOfs + 0x56) < 10)))) {
    hasUnits = 1;
  }
  else {
    hasUnits = 0;
  }
  if ((AgntGs[(uint)(GLeaderSheets[partyIndex])->classStr].flags & 0x80)
      == 0) {
    blockFlags = 0;
  }
  else {
    blockFlags = 3;
  }
  if (((GLeaderSheets[partyIndex])->flags5d & 2) != 0) {
    blockFlags = blockFlags | 1;
  }
  sheetPtr = (uint32_t)GLeaderSheets[partyIndex];
  if ((*(byte *)((int)sheetPtr + 0x5d) & 4) != 0) {
    blockFlags = blockFlags | 2;
  }
  searchStatus = ovc22_searchCellsAround
                    ((uint *)CONCAT22(&y,_SS),
                     (uint *)CONCAT13((char)(((uint)partyIndex << 2) >> 8),
                                      CONCAT12(partyIndex,_SS)),blockFlags,hasUnits,siArg);
  if ((searchStatus & 0xff) != 0) {
    if ((searchStatus & 0xff) != 1) {
      return;
    }
    bldPick = ovc22_usesRandBelow(partyIndex,x,y);
    if (bldPick == 0) {
      x = (GLeaderSheets[partyIndex])->x;
      y = (GLeaderSheets[partyIndex])->y;
    }
    else {
      if ((*(uint *)((uint8_t *)&BuildingTypes[bldPick] + 19) & 0x60) == 0) {
        unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[partyIndex] >> 0x10);
        sheetOfs = (int)(uint32_t)GLeaderSheets[partyIndex];
        unitCount = *(int *)(sheetOfs + 0x58);
        if ((unitCount < 0) ||
           ((unitCount == 0 && (*(uint *)(sheetOfs + 0x56) < *(uint *)((uint8_t *)&BuildingTypes[bldPick] + 23))))) {
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[partyIndex] >> 0x10);
          unitCount = (int)(uint32_t)GLeaderSheets[partyIndex];
          *(uint16_t *)(unitCount + 0x58) = 0;
          *(uint16_t *)(unitCount + 0x56) = 0;
        }
        else {
          bldWord23 = *(uint *)((uint8_t *)&BuildingTypes[bldPick] + 23);
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[partyIndex] >> 0x10);
          unitCount = (int)(uint32_t)GLeaderSheets[partyIndex];
          goldLoPtr = (uint *)(unitCount + 0x56);
          oldLo = *goldLoPtr;
          *goldLoPtr = *goldLoPtr - bldWord23;
          goldHiPtr = (int *)(unitCount + 0x58);
          *goldHiPtr = *goldHiPtr - (uint)(oldLo < bldWord23);
        }
      }
      bldType = (byte)bldPick;
      ovr_createConstructionRecordFar
                (bldType,x,y,
                 (uint8_t *)CONCAT13((char)(outFlagSeg >> 8),CONCAT12((char)outFlagSeg,outFlag)),
                 partyIndex,siArg,(char)y,(char)outFlag,(char)outFlagSeg);
    }
  }
  if (*((char far *)GLeaderSheets[partyIndex] + 0x3f) == '\0') {
    if ((GLeaderSheets[partyIndex])->housing <
        (GLeaderSheets[partyIndex])->population) {
      ovr_ovc18_textTypeLen(partyIndex,x,y,0x1,(char)x,(char)y);
    }
    else {
      ovr_ovc18_textTypeLen(partyIndex,x,y,0x0,(char)x,(char)y);
    }
  }
  else {
    ovr_ovc18_textTypeLen(partyIndex,0,0,0x0,0,0);
  }
  return;
}



/* 5087:4dd9 */

/* Runs the per-leader random spawn chance and spawns through ovc22_usesRandBelow2. */

void __cdecl16far ovc22_spawnForLeaders(void)

{
  uint16_t randPick;
  uint8_t outFlag;
  int leader;
  
  outFlag = 0x0;
  for (leader = 0; leader < (int)(uint)GLeaderCount; leader = leader + 1) {
    if ((((GLeaderSheets[leader])->active != '\0') &&
        (randPick = ovr_randBelow((uint)(byte)((char *)0x2686a)
                                           [(uint)(GLeaderSheets[leader])->classStr * 0x95],0),
        (byte)randPick < ((agnt_t far *)((leader << 2)))->variant)) &&
       ((*((char far *)GLeaderSheets[leader] + 0x3f) != '\0' ||
        ((GLeaderSheets[leader])->population <=
         (GLeaderSheets[leader])->housing)))) {
      if (EntityCount < 0x21c) {
        ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
      }
      else if (*((char far *)GLeaderSheets[leader] + 0x3f) == '\0') {
        if ((GLeaderSheets[leader])->unitCount < 0x23) {
          ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
        }
        else if ((GLeaderSheets[leader])->unitCount < 0x4b) {
          randPick = ovr_randBelow(8,0);
          if ((randPick & 0xff) == 0) {
            ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
          }
        }
        else {
          randPick = ovr_randBelow(0x10,0);
          if ((randPick & 0xff) == 0) {
            ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
          }
        }
      }
      else if ((GLeaderSheets[leader])->unitsOnTile == 0) {
        ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
      }
      else if ((GLeaderSheets[leader])->unitCount < 0x19) {
        ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
      }
      else if ((GLeaderSheets[leader])->unitCount < 0x32) {
        randPick = ovr_randBelow(8,0);
        if ((randPick & 0xff) == 0) {
          ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
        }
      }
      else {
        randPick = ovr_randBelow(0x10,0);
        if ((randPick & 0xff) == 0) {
          ovc22_usesRandBelow2((byte)leader,(uint16_t)&outFlag,_SS);
        }
      }
    }
  }
  if (outFlag == 0x0) {
    ovr_constr_usesBlitRect();
  }
  else {
    ovr_constr_flushDirtyRects();
  }
  return;
}



/* 5087:503d */

/* [R6] touches GOngoingBattle, GfxRndSeed2 */

uint16_t __cdecl16far ovc22_usesGOngoingBattle(byte x,byte y)

{
  uint16_t uVar1;
  
  if (GOngoingBattle == '\0') {
    if (((int)(uint)y < GfxRndSeed2 + -4) || (GfxRndSeed2 < (int)(uint)y)) {
      return 0;
    }
  }
  else if (((int)(uint)y < GfxRndSeed2 + -2) || (GfxRndSeed2 < (int)(uint)y)) {
    return 0;
  }
  if (((int)(uint)x < GfxRndSeed + *(int *)((GfxRndSeed2 - (uint)y) * 2 + -0x73ed)) ||
     (GfxRndSeed + *(int *)((GfxRndSeed2 - (uint)y) * 2 + -0x73ff) < (int)(uint)x)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 5087:510e */

/* [R6] touches GOngoingBattle, GfxRndSeed2 */

uint16_t __cdecl16far ovc22_usesGOngoingBattle2(byte x,byte y)

{
  uint16_t uVar1;
  
  if (GOngoingBattle == '\0') {
    if (((int)(uint)y < GfxRndSeed2 + -2) || (GfxRndSeed2 < (int)(uint)y)) {
      return 0;
    }
  }
  else if (((int)(uint)y < GfxRndSeed2 + -1) || (GfxRndSeed2 < (int)(uint)y)) {
    return 0;
  }
  if (((int)(uint)x < GfxRndSeed + *(int *)((GfxRndSeed2 - (uint)y) * 2 + -0x73ed)) ||
     (GfxRndSeed + *(int *)((GfxRndSeed2 - (uint)y) * 2 + -0x73ff) < (int)(uint)x)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


