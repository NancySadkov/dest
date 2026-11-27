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
  bool bVar1;
  int cellB;
  int cellMin;
  int cellA;
  
  if ((((x < 0) || (y < 0)) || (0x93 < x + 1)) || (0x3b < y + 1)) {
    placementStatus = 2;
    bVar1 = false;
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
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      placementStatus = 1;
      bVar1 = false;
    }
  }
  return bVar1;
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

char * __cdecl16far ovc22_textPOPULATION(byte bldType,byte partyIndex,agnt_t far *agnt,uint16_t arg4,uint16_t arg5)

{
  uint16_t value;
  uint8_t code;

  (void)arg4;
  (void)arg5;
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

uint __cdecl16far ovc22_seasonalIncome(byte bldType,uint8_t partyIndex,uint16_t arg3,uint16_t arg4,uint16_t arg5)

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

   Body not derived yet; see doc/step6_entry.md. */


void __cdecl16far ovc22_textRingProt(byte partyIndex)

{
  /* Not derived yet - see the comment above. */
  (void)partyIndex;
  return;
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
     stack for both, which is what `in_stack_00000006` and `unaff_DI` below really are. */
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
      *(uint8_t *)CONCAT22((uint8_t *)outFlag,in_stack_00000006) = 0x1;
    }
    ovr_createConstructionRecordFar
              (0,u->x,u->y,(uint8_t *)CONCAT22((uint8_t *)outFlag,in_stack_00000006),(*(uint8_t *)((uint8_t *)&(outFlag) + 2)),unaff_DI,0,0,0)
    ;
    if (1 < BuildingTypes[bldType].size) {
      ovr_createConstructionRecordFar
                (0,u->x + 1,u->y,(uint8_t *)CONCAT22((uint8_t *)outFlag,in_stack_00000006),(*(uint8_t *)((uint8_t *)&(outFlag) + 2)),unaff_DI,0,0,0);
      if (3 < BuildingTypes[bldType].size) {
        ovr_createConstructionRecordFar
                  (0,u->x + 2,u->y,(uint8_t *)CONCAT22((uint8_t *)outFlag,in_stack_00000006),(*(uint8_t *)((uint8_t *)&(outFlag) + 2)),unaff_DI,0,0,0);
        ovr_createConstructionRecordFar
                  (0,u->x + 3,u->y,(uint8_t *)CONCAT22((uint8_t *)outFlag,in_stack_00000006),(*(uint8_t *)((uint8_t *)&(outFlag) + 2)),unaff_DI,0,0,0);
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
  int *piVar4;
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
  for (; (piVar4 = (int *)((uint)classId * 0x94 + lvlIdx * 4), *piVar4 == 0 && piVar4[1] == 0 &&
         (lvlIdx != 0)); lvlIdx = lvlIdx - 1) {
  }
  piVar4 = (int *)((uint)classId * 0x94 + lvlIdx * 4);
  LUDIV_at_(*piVar4,piVar4[1],0x1e,0);
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
  byte *pbVar1;
  uint far *accLo;
  /* GUESS-free: GMapFlags is a 16-bit array, so its view is uint16_t * while accLo stays
     uint * for the sheet gold/trade counters at +0x56/+0x60/+0x7e. */
  uint16_t *flagWord;
  int far *accHi;
  uint8_t *puVar4;
  byte leaderIdx;
  short sVar6;
  uint32_t uVar7;
  far_t pctOut;
  far_t remainderOut;
  far_t partOut;
  bool bVar8;
  bool bVar9;
  char sheetFaction;
  uint16_t randVal;
  uint uVar12;
  char *msg;
  uint16_t index;
  uint16_t tableOfs;
  long *plVar15;
  agnt_t far *valueLo;
  unit_t *units;
  int iVar17;
  int iVar18;
  int sheetOfs;
  entity_t *peVar20;
  int iVar21;
  entity_t *peVar22;
  uint16_t unaff_SI;
  uint16_t unaff_DI;
  uint uVar23;
  uint leaderIdxB;   /* the 0..GLeaderCount loop at 3529 only */
  uint unitIdx;   /* the 0xf8..GUnitCount loops only */
  uint16_t unitsSeg;
  uint16_t uVar25;
  uint16_t uVar26;
  bool bVar27;
  far_t table;
  uint8_t *puVar28;
  uint16_t pctSeg;
  uint8_t *puVar30;
  uint16_t remainderSeg;
  uint8_t *puVar32;
  undefined1 uVar33;
  undefined1 uVar34;
  undefined1 ptrSegHi;
  long a;
  uint uVar36;
  ulong in_stack_0000ffd2;
  int iStack_2a;
  uint8_t bldType;
  uint8_t partialWeight;
  uint8_t successWeight;
  char cStack_1d;
  uint8_t found;
  byte partySlot;
  uint16_t entY;
  uint entX;
  uint idx;
  uint uStack_14;
  uint popAcc;
  uint uStack_10;
  int iStack_e;
  int iStack_c;
  uint uStack_a;
  uint16_t uStack_8;
  byte gindex;
  byte firstLeader;
  uint sheetAA;
  
  a = CONCAT22(unaff_SI,unaff_DI);
  if (!GameRunning) {
    cStack_1d = '\0';
    found = 0x0;
    for (idx = 0xf8; idx < GUnitCount; idx = idx + 1) {
      pbVar1 = &(GUnits)[idx].flags;
      *pbVar1 = *pbVar1 & 0xfc;
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
           (uVar7 = *(uint32_t *)((uint)units[unitIdx].unitType << 2),
           *(char *)((int)uVar7 + 0x3f) == '\0')) {
          uStack_8 = 0x96;
        }
        else {
          uStack_8 = 0x5dc;
        }
        if (units[unitIdx].level != 0) {
          randVal = ovr_randBelow(uStack_8,0);
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
          bVar8 = true;
        }
        else {
          bVar8 = false;
        }
        uVar23 = *((uint far *)GLeaderSheets[idx] + 0x54);
        unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        iVar17 = *(int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58) + ((int)uVar23 >> 0xf) +
                 (uint)CARRY2(*(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56),uVar23);
        if ((iVar17 < 1) && (iVar17 < 0)) {
          for (unitIdx = 0xf8; unitIdx < GUnitCount; unitIdx = unitIdx + 1) {
            unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
            units = GUnits;
            bldType = (units + unitIdx)->bldType;
            if ((units[unitIdx].unitType == idx) &&
               (BuildingTypes[bldType].income < 0)) {
              uVar12 = BuildingTypes[bldType].income;
              uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              iVar17 = *(int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58) + ((int)uVar12 >> 0xf) +
                       (uint)CARRY2(*(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56),uVar12);
              if ((iVar17 < 1) && (iVar17 < 0)) {
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
                       ((iVar17 = 0, units[unitIdx].level == 0 ||
                        (iVar17 = (uint)bldType * 0x27, (*(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x121) & 0x200) != 0))))
                    {
                      ovc22_usesGUnits(unitIdx,(uint8_t *)
                                              CONCAT13((char)((uint)iVar17 >> 8),
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
                uVar36 = BuildingTypes[bldType].income;
                unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
                accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56);
                uVar12 = *accLo;
                *accLo = *accLo + uVar36;
                accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58);
                *accHi = *accHi + ((int)uVar36 >> 0xf) + (uint)CARRY2(uVar12,uVar36);
              }
            }
          }
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x58) = 0;
          *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x56) = 0;
        }
        else {
          if ((sheetFaction == '\0') && (0 < *((int far *)GLeaderSheets[idx] + 0x54))) {
            uStack_10 = *((int far *)GLeaderSheets[idx] + 0x54) / 10;
          }
          else {
            uStack_10 = 0;
          }
          bVar27 = CARRY2(GPopulationLo,uStack_10);
          GPopulationLo = GPopulationLo + uStack_10;
          GPopulationHi = GPopulationHi + ((int)uStack_10 >> 0xf) + (uint)bVar27;
          uVar12 = *((int far *)GLeaderSheets[idx] + 0x54) - uStack_10;
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56);
          uVar23 = *accLo;
          *accLo = *accLo + uVar12;
          accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58);
          *accHi = *accHi + ((int)uVar12 >> 0xf) + (uint)CARRY2(uVar23,uVar12);
        }
        if ((AgntGs[(uint)(GLeaderSheets[idx])->classStr].flags & 0x100)
            == 0) {
          if ((GLeaderSheets[idx])->foodProd <
              (GLeaderSheets[idx])->population) {
            popAcc = (GLeaderSheets[idx])->population -
                        (GLeaderSheets[idx])->foodProd;
            unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            iVar21 = (int)(uint32_t)GLeaderSheets[idx];
            iVar17 = *(int *)(iVar21 + 0x62);
            if ((-1 < iVar17) && ((0 < iVar17 || (*(int *)(iVar21 + 0x60) != 0)))) {
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              uVar23 = *(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x62);
              if ((0x7fff < uVar23) ||
                 ((uStack_14 = popAcc, (int)uVar23 < 1 && (*(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x60) <= popAcc)
                  ))) {
                uStack_14 = *((uint far *)GLeaderSheets[idx] + 0x60);
              }
              popAcc = popAcc - uStack_14;
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x60);
              uVar23 = *accLo;
              *accLo = *accLo - uStack_14;
              accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x62);
              *accHi = *accHi - (uint)(uVar23 < uStack_14);
            }
            if (popAcc != 0) {
              uStack_a = popAcc;
              if ((GLeaderSheets[idx])->maxTrade < popAcc) {
                uStack_a = (GLeaderSheets[idx])->maxTrade;
              }
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              uVar23 = *(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x58);
              if (((int)uVar23 < 1) && ((0x7fff < uVar23 || (*(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56) < uStack_a))))
              {
                uStack_a = *((uint far *)GLeaderSheets[idx] + 0x56);
              }
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56);
              uVar23 = *accLo;
              *accLo = *accLo - uStack_a;
              accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58);
              *accHi = *accHi - (uint)(uVar23 < uStack_a);
              popAcc = popAcc - uStack_a;
              (GLeaderSheets[idx])->foodSold = uStack_a;
            }
            if (sheetFaction == '\0') {
              for (iVar17 = 0; (popAcc != 0 && (iVar17 < (int)(uint)GLeaderCount));
                  iVar17 = iVar17 + 1) {
                if (((GLeaderSheets[iVar17])->active != '\0') &&
                   ((*((char far *)GLeaderSheets[iVar17] + 0x3f) == '\0' &&
                    (unitsSeg = (uint16_t)SEG_OF(GLeaderSheets[iVar17]),
                    iVar21 = (int)far_ofs_u32(GLeaderSheets[iVar17]),
                    *(int *)(iVar21 + 0x60) != 0 || *(int *)(iVar21 + 0x62) != 0)))) {
                  unitsSeg = (uint16_t)SEG_OF(GLeaderSheets[iVar17]);
                  iVar21 = (int)far_ofs_u32(GLeaderSheets[iVar17]);
                  uVar23 = *(uint *)(iVar21 + 0x62);
                  if ((uVar23 < 0x8000) &&
                     ((0 < (int)uVar23 || (popAcc < *(uint *)(iVar21 + 0x60))))) {
                    uStack_14 = popAcc;
                  }
                  else {
                    uStack_14 = *((uint far *)GLeaderSheets[iVar17] + 0x60);
                  }
                  popAcc = popAcc - uStack_14;
                  unitsSeg = (uint16_t)SEG_OF(GLeaderSheets[iVar17]);
                  iVar21 = (int)far_ofs_u32(GLeaderSheets[iVar17]);
                  accLo = (uint *)(iVar21 + 0x60);
                  uVar23 = *accLo;
                  *accLo = *accLo - uStack_14;
                  accHi = (int *)(iVar21 + 0x62);
                  *accHi = *accHi - (uint)(uVar23 < uStack_14);
                }
              }
            }
            uVar23 = 0;
            while ((uVar23 < EntityCount && (popAcc != 0))) {
              unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
              peVar20 = Entities;
              if (((*(char *)((int)&peVar20[uVar23].base.entity + 1) == '\0') &&
                  (*(byte *)((int)&peVar20[uVar23].base.entity + 3) == idx)) &&
                 ((bVar8 || (1 < peVar20[uVar23].base.animFrame)))) {
                if (peVar20[uVar23].base.animFrame != 0x0) {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  puVar4 = &(Entities)[uVar23].base.animFrame;
                  *puVar4 = *puVar4 + 0xff;
                  if ((Entities)[uVar23].base.animFrame == 0x0) {
                    cStack_1d = '\x01';
                  }
                }
                popAcc = popAcc - 1;
              }
              uVar23 = uVar23 + 1;
            }
          }
          else {
            uVar12 = (GLeaderSheets[idx])->foodProd -
                     (GLeaderSheets[idx])->population;
            unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x60);
            uVar23 = *accLo;
            *accLo = *accLo + uVar12;
            accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x62);
            *accHi = *accHi + (uint)CARRY2(uVar23,uVar12);
          }
        }
        unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        iVar18 = (int)(uint32_t)GLeaderSheets[idx];
        iVar17 = *(int *)(iVar18 + 0x62);
        uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
        iVar21 = *(int *)(sheetOfs + 0x80);
        if ((iVar21 <= iVar17) &&
           ((iVar21 < iVar17 || (*(uint *)(sheetOfs + 0x7e) < *(uint *)(iVar18 + 0x60))))) {
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          uVar23 = *(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x60);
          uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          iVar21 = (int)(uint32_t)GLeaderSheets[idx];
          accLo = (uint *)(iVar21 + 0x7e);
          uVar12 = (uint)(uVar23 < *accLo);
          uVar36 = *(int far *)((uint8_t far *)GLeaderSheets[idx] + 0x62) - *(int *)(iVar21 + 0x80);
          if (((int)(uVar36 - uVar12) < 0) ||
             ((uVar36 == uVar12 &&
              (uVar23 - *accLo <= (GLeaderSheets[idx])->maxTrade)))) {
            uStack_a = *((int far *)GLeaderSheets[idx] + 0x60) -
                       *((int far *)GLeaderSheets[idx] + 0x7e);
          }
          else {
            uStack_a = (GLeaderSheets[idx])->maxTrade;
          }
          (GLeaderSheets[idx])->foodSold = -uStack_a;
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56);
          uVar23 = *accLo;
          *accLo = *accLo + uStack_a;
          accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58);
          *accHi = *accHi + (uint)CARRY2(uVar23,uStack_a);
          uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          unitsSeg = *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x7e);
          uVar26 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          iVar21 = (int)(uint32_t)GLeaderSheets[idx];
          *(uint16_t *)(iVar21 + 0x62) = *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x80);
          *(uint16_t *)(iVar21 + 0x60) = unitsSeg;
        }
        if (((GLeaderSheets[idx])->housing <
             (GLeaderSheets[idx])->population) &&
           ((AgntGs[(uint)(GLeaderSheets[idx])->classStr].flags & 0x80)
            == 0)) {
          popAcc = (GLeaderSheets[idx])->population -
                      (GLeaderSheets[idx])->housing;
          uVar23 = 0;
          while ((uVar23 < EntityCount && (popAcc != 0))) {
            unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
            peVar20 = Entities;
            if ((*(byte *)((int)&peVar20[uVar23].base.entity + 3) == idx) &&
               ((((*(char *)((int)&peVar20[uVar23].base.entity + 1) == '\0' &&
                  (peVar20[uVar23].base.destX == 0)) && (peVar20[uVar23].base.destY == 0)) &&
                (3 < peVar20[uVar23].base.animFrame)))) {
              if (DebugVerbose != false) {
                printf("kill 2 \r");
              }
              puVar4 = &(Entities)[uVar23].base.animFrame;
              *puVar4 = *puVar4 + 0xff;
              popAcc = popAcc - 1;
            }
            uVar23 = uVar23 + 1;
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
          iVar21 = (int)(uint32_t)GLeaderSheets[idx];
          iVar17 = *(int *)(iVar21 + 0x58);
          if ((iVar17 < 1) && ((iVar17 != 0 || (*(int *)(iVar21 + 0x56) == 0)))) {
            unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x58) = 0;
            *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x56) = 0x32;
          }
        }
        if (*((char far *)GLeaderSheets[idx] + 0xaa) != '\0') {
          sheetAA = (uint)*((byte far *)GLeaderSheets[idx] + 0xaa);
          for (leaderIdxB = 0; (int)leaderIdxB < (int)(uint)GLeaderCount; leaderIdxB = leaderIdxB + 1) {
            unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            iVar18 = (int)(uint32_t)GLeaderSheets[idx];
            iVar17 = *(int *)(iVar18 + 0x58);
            uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
            sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
            iVar21 = *(int *)(sheetOfs + 0x8c);
            if ((iVar21 <= iVar17) &&
               ((iVar17 != iVar21 || (*(uint *)(sheetOfs + 0x8a) <= *(uint *)(iVar18 + 0x56)))))
            break;
            if (((GLeaderSheets[leaderIdxB])->active != '\0') &&
               (((0 < *((int far *)GLeaderSheets[leaderIdxB] + 0x54) &&
                 (*((char far *)GLeaderSheets[leaderIdxB] + 0x3f) == '\0')) &&
                (leaderIdxB != idx)))) {
              in_stack_0000ffd2 =
                   ((long)*((int far *)GLeaderSheets[leaderIdxB] + 0x54) * (long)(int)sheetAA &
                   0xffffU) / 100;
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              uVar12 = *(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x8a);
              uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              iVar21 = (int)(uint32_t)GLeaderSheets[idx];
              accLo = (uint *)(iVar21 + 0x56);
              iVar17 = (*(int far *)((uint8_t far *)GLeaderSheets[idx] + 0x8c) - *(int *)(iVar21 + 0x58)) -
                       (uint)(uVar12 < *accLo);
              if ((iVar17 < 1) && ((iVar17 < 0 || (uVar12 - *accLo < (uint)in_stack_0000ffd2)))) {
                unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
                uVar12 = *(uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x8a);
                uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
                iVar21 = (int)(uint32_t)GLeaderSheets[idx];
                accLo = (uint *)(iVar21 + 0x56);
                in_stack_0000ffd2 =
                     CONCAT22((*(int far *)((uint8_t far *)GLeaderSheets[idx] + 0x8c) - *(int *)(iVar21 + 0x58)) -
                              (uint)(uVar12 < *accLo),uVar12 - *accLo);
              }
              unitsSeg = (uint16_t)SEG_OF(GLeaderSheets[leaderIdxB]);
              iVar21 = (int)far_ofs_u32(GLeaderSheets[leaderIdxB]);
              iVar17 = *(int *)(iVar21 + 0x58);
              iVar18 = (int)(in_stack_0000ffd2 >> 0x10);
              if ((iVar17 <= iVar18) &&
                 ((iVar17 < iVar18 || (*(uint *)(iVar21 + 0x56) < (uint)in_stack_0000ffd2)))) {
                unitsSeg = (uint16_t)SEG_OF(GLeaderSheets[leaderIdxB]);
                iVar17 = (int)far_ofs_u32(GLeaderSheets[leaderIdxB]);
                in_stack_0000ffd2 =
                     CONCAT22(*(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x58),*(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x56));
              }
              unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
              iVar21 = (int)(in_stack_0000ffd2 >> 0x10);
              uVar36 = (uint)in_stack_0000ffd2;
              accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56);
              uVar12 = *accLo;
              *accLo = *accLo + uVar36;
              accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58);
              *accHi = *accHi + iVar21 + (uint)CARRY2(uVar12,uVar36);
              unitsSeg = (uint16_t)SEG_OF(GLeaderSheets[leaderIdxB]);
              iVar17 = (int)far_ofs_u32(GLeaderSheets[leaderIdxB]);
              accLo = (uint far *)((uint8_t far *)GLeaderSheets[idx] + 0x56);
              uVar12 = *accLo;
              *accLo = *accLo - uVar36;
              accHi = (int far *)((uint8_t far *)GLeaderSheets[idx] + 0x58);
              *accHi = (*accHi - iVar21) - (uint)(uVar12 < uVar36);
            }
          }
        }
        iVar17 = *((int far *)GLeaderSheets[idx] + 0x58);
        if ((iVar17 < 1) && (iVar17 < 0)) {
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x58) = 0;
          *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x56) = 0;
        }
        unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        iVar18 = (int)(uint32_t)GLeaderSheets[idx];
        iVar17 = *(int *)(iVar18 + 0x58);
        uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
        sheetOfs = (int)(uint32_t)GLeaderSheets[idx];
        iVar21 = *(int *)(sheetOfs + 0x8c);
        if ((iVar21 <= iVar17) &&
           ((iVar21 < iVar17 || (*(uint *)(sheetOfs + 0x8a) < *(uint *)(iVar18 + 0x56))))) {
          uVar25 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          unitsSeg = *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x8a);
          uVar26 = (uint16_t)((ulong)(uint32_t)GLeaderSheets[idx] >> 0x10);
          iVar21 = (int)(uint32_t)GLeaderSheets[idx];
          *(uint16_t *)(iVar21 + 0x58) = *(uint16_t far *)((uint8_t far *)GLeaderSheets[idx] + 0x8c);
          *(uint16_t *)(iVar21 + 0x56) = unitsSeg;
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
          uVar7 = *(uint32_t *)((uint)(GUnits)[unitIdx].unitType << 2);
          if (*(char *)((int)uVar7 + 0x3f) == '\0') {
            ovr_play_sfx(81,0,0);
            unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
            sVar6 = (GUnits)[unitIdx].y;
            uVar33 = (undefined1)sVar6;
            ptrSegHi = (undefined1)((uint)sVar6 >> 8);
            uVar34 = 0x10;
            uVar12 = ovr_alignUp4((GUnits)[unitIdx].x,0,0);
            msg = ovr_fmVsprintf("Mine exhausted at (%d, %d).",
                                     (char *)CONCAT13(ptrSegHi,CONCAT12(uVar33,uVar12)));
            ovr_say(msg,uVar34);
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
          iVar17 = ((int *)(idx * 4))[1];
          memcpy((char *)CONCAT22(((int *)(idx * 4))[1],
                                  (char *)(*(int *)(idx * 4) + 0x8e)),
                 (char *)CONCAT13((char)((uint)iVar17 >> 8),
                                  CONCAT12((char)iVar17,*(int *)(idx * 4) + 0x94)),3);
        }
      }
    }
    iStack_e = 0;
    firstLeader = ovr_manage_findFirstLeader();
    if ((firstLeader == 0xff) || (GCanPromote == '\0')) {
      iStack_c = 0;
    }
    else if ((GLeaderSheets[firstLeader])->titleIndex < 5) {
      iStack_c = 0x28;
    }
    else {
      iStack_c = (uint)(GLeaderSheets[firstLeader])->titleIndex * 4 + 0x14;
    }
    for (idx = EntityScanPos; idx < EntityCount; idx = idx + 1) {
      unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
      peVar20 = Entities;
      if (((*(char *)((int)&peVar20[idx].base.entity + 1) == '\0') &&
          (peVar20[idx].base.destX == 0)) && (peVar20[idx].base.destY == 0)) {
        gindex = peVar20[idx].base.gindex;
        sheetFaction = AgntGs[(uint)gindex].ai;
        leaderIdx = *(byte *)((int)&peVar20[idx].base.entity + 3);
        bVar27 = false;
        bVar9 = false;
        bVar8 = false;
        if (AgntGs[(uint)gindex].shortName[3] == -1) {
          bVar27 = true;
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
              uVar34 = (undefined1)_SS;
              uVar33 = (undefined1)(_SS >> 8);
              puVar32 = &successWeight;
              puVar30 = &partialWeight;
              puVar28 = &bldType;
              index = CONCAT11((char)((uint)puVar28 >> 8),partySlot);
              pctSeg = _SS;
              remainderSeg = _SS;
              tableOfs = ovr_attact_usesSquareRecCount(entX,entY);
              table.seg = randVal;
              table.ofs = tableOfs;
              pctOut.seg = pctSeg;
              pctOut.ofs = (uint16_t)puVar28;
              remainderOut.seg = remainderSeg;
              remainderOut.ofs = (uint16_t)puVar30;
              (*(uint8_t *)((uint8_t *)&(partOut.seg))) = uVar34;
              partOut.ofs = (uint16_t)puVar32;
              (*(uint8_t *)((uint8_t *)&(partOut.seg) + 1)) = uVar33;
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
            bVar27 = true;
          }
          else if ((randVal & 0xff) < (uint)partialWeight + (uint)successWeight) {
            bVar9 = true;
          }
          else {
            bVar8 = true;
          }
        }
        if ((bVar8) &&
           (unitsSeg = (uint16_t)((ulong)Entities >> 0x10),
           randVal = (Entities)[idx].base.y,
           sheetFaction = ovr_ovc23_tickRecordsAt
                              (((Entities + idx)->base).x,randVal,sheetFaction,
                               (char)randVal), sheetFaction == '\0')) {
          if ((partialWeight == 0x0) && (successWeight == 0x0)) {
            randVal = ovr_randBelow(2,0);
            if ((randVal & 0xff) == 0) {
              bVar27 = true;
            }
            else {
              bVar9 = true;
            }
          }
          else {
            randVal = ovr_randBelow((uint)partialWeight + (uint)successWeight,0);
            if ((byte)randVal < successWeight) {
              bVar27 = true;
            }
            else {
              bVar9 = true;
            }
          }
        }
        if ((bVar27) && (uVar23 = ovc22_usesEntities(idx), (uVar23 & 0xff) == 0)) {
          bVar9 = true;
        }
        if (bVar9) {
          if ((AgntGs[(uint)gindex].shortName[3] != -1) &&
             (leaderIdx != 0xff)) {
            if ((*(char *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x3f) != '\0') ||
               (Entities[idx].base.level <
                *(byte *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x53))) {
              uVar34 = (undefined1)iStack_c;
              uVar33 = (undefined1)((uint)iStack_c >> 8);
              ovc22_usesLUDIV_at_((entity_t *)
                                  CONCAT13((char)((ulong)Entities >> 0x18),
                                           CONCAT12((char)((ulong)Entities >> 0x10),
                                                    Entities + idx)));
              uVar23 = 0;
              plVar15 = LXMUL_at_((long *)CONCAT11(uVar33,uVar34),a,in_stack_0000ffd2);
              peVar20 = Entities + idx;
              valueLo = ovr_ovc15_textError((entity_t *)CONCAT22(DAT_2000_d190,peVar20),
                                            (agnt_t far *)(CONCAT12((uVar23 & 1) != 0,plVar15) >> 1));
              uVar12 = ovc22_usesLUDIV_at_2
                                 ((uint16_t)valueLo,(uint16_t)peVar20,CONCAT11(uVar33,uVar34));
              unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
              peVar22 = Entities;
              uVar23 = *(uint *)&peVar22[idx].base.health;
              *(uint *)&peVar22[idx].base.frameIndex =
                   (int)&(peVar20->base).x +
                   (uint)CARRY2(uVar23,uVar12) + *(int *)&peVar22[idx].base.frameIndex;
              *(uint *)&peVar22[idx].base.health = uVar23 + uVar12;
              ovr_ovc41_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                          CONCAT12((char)((ulong)Entities >> 0x10),
                                                   Entities + idx)));
            }
          }
          ovc22_usesEntities2(idx);
          ovc22_usesEntities3(idx);
          ovc22_usesEntities4(idx);
        }
        iStack_2a = (uint)(Entities)[idx].base.animFrame -
                    (uint)*(byte *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0xa4);
        if (0 < iStack_2a) {
          if (3 < iStack_2a) {
            iStack_2a = 3;
          }
          if (iStack_2a == 3) {
            if (*(int *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x92) == 0) {
              iStack_2a = 2;
            }
            else {
              accHi = (int *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x92);
              *accHi = *accHi + -1;
            }
          }
          if (iStack_2a == 2) {
            if (*(int *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x90) == 0) {
              iStack_2a = 1;
            }
            else {
              accHi = (int *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x90);
              *accHi = *accHi + -1;
            }
          }
          if (iStack_2a == 1) {
            if (*(int *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x8e) == 0) {
              iStack_2a = 0;
            }
            else {
              accHi = (int *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x8e);
              *accHi = *accHi + -1;
            }
          }
          (Entities)[idx].base.animFrame =
               *(char *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0xa4) + (char)iStack_2a;
        }
        iStack_e = iStack_e + 1;
        if (199 < iStack_e) break;
      }
    }
    EntityScanPos = idx;
    mapDirty = 1;
    ovr_unit_usesAlignUp4();
    GGameState = 0x44;
    if (DebugVerbose != false) {
      printf("%d \r",GGameState);
    }
    uVar23 = EntityCount;
    if (cStack_1d != '\0') {
      while (idx = uVar23 - 1, -1 < (int)idx) {
        unitsSeg = (uint16_t)((ulong)Entities >> 0x10);
        peVar20 = Entities;
        uVar23 = idx;
        if (peVar20[idx].base.animFrame == 0x0) {
          if (AgntGs[(uint)peVar20[idx].base.gindex].ai == '\0') {
            ovr_alignUp4(((peVar20 + idx)->base).x,(char)peVar20[idx].base.y,0);
            iVar17 = (uint)(Entities)[idx].base.gindex * 0x95;
            msg = ovr_fmVsprintf("Intelligence reports %s unit died of starvation. (%d, %d)",
                                     (char *)CONCAT22(*(uint16_t *)
                                                       ((int)&worldMenuLabels[1].ofs + 1 + iVar17),
                                                      (char *)*(uint16_t *)
                                                               ((int)&worldMenuLabels[0].seg + 1 +
                                                               iVar17)));
            asm { mov randVal,dx };
            ovr_uiNotify(msg,randVal,(char)randVal);
          }
          ovr_ovc15_removeEntity(idx);
          uVar23 = idx;
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
  uint16_t in_AX;
  uint16_t uVar1;
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
        uVar1 = (uint16_t)((ulong)GMapFlags >> 0x10);
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
    uVar1 = 1;
  }
  else {
    uVar1 = CONCAT11((char)((uint)in_AX >> 8),1);
  }
  return uVar1;
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
  bool bVar2;
  uint16_t mask;
  uint uVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  uint32_t *puVar6;
  uint *in_stack_00000004;
  char cStack_8;
  char cStack_7;
  int iStack_6;
  int iStack_4;
  
  x1 = *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004);
  y1 = *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)));
  skipCheck = *(byte *)((int)*(uint32_t *)((uint)(*(uint8_t *)((uint8_t *)&(yPtr) + 2)) << 2) + 0x3f);
  mask = 0x1000 << (skipCheck & 0x1f);
  uVar3 = ovc22_usesAlignUp4(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                             *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2)),mask);
  if ((char)uVar3 == '\0') {
    uVar4 = ovc22_usesAlignUp42((uint16_t *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                (uint16_t *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2)),mask);
    if ((char)uVar4 == '\0') {
      for (iStack_4 = 1; iStack_4 < 0x94; iStack_4 = iStack_4 + 1) {
        for (iStack_6 = 0; iStack_6 <= iStack_4; iStack_6 = iStack_6 + 1) {
          for (cStack_7 = -1; cStack_7 < '\x02'; cStack_7 = cStack_7 + '\x02') {
            for (cStack_8 = -1; cStack_8 < '\x02'; cStack_8 = cStack_8 + '\x02') {
              *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) = x1 + cStack_7 * iStack_6;
              if (cStack_7 < '\0') {
                *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) =
                     *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) - 1;
              }
              *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) = y1 + cStack_8 * iStack_4;
              if ((((3 < *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004)) &&
                   (*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) < 0x90)) &&
                  (*(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) != 0)) &&
                 (*(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) < 0x3b)) {
                uVar3 = ovc22_usesAlignUp4(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                           *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2)),
                                           mask);
                if ((char)uVar3 != '\0') {
                  return uVar3 & 0xff00;
                }
                if ((skipCheck != 0) &&
                   (uVar3 = ovc22_usesGUnitGrid(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                                *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))),
                   uVar3 != 0)) {
                  return CONCAT11((char)(uVar3 >> 8),1);
                }
                if (((yOutOfs == 3) &&
                    (uVar5 = ovc22_testMapFlags(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                                *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),mask),
                    (char)uVar5 != '\0')) &&
                   (uVar3 = ovc22_usesGMapFlags2
                                      (skipCheck,x1,y1,
                                       *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                       *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))),
                   (char)uVar3 != '\0')) {
                  return uVar3 & 0xff00;
                }
                if ((((yOutOfs & 1) == 0) && (yOutSeg == 0)) &&
                   (bVar2 = ovc22_textArena2(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                             *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))), bVar2)) {
                  uVar5 = ovc22_usesGMapFlags2
                                    (skipCheck,x1,y1,
                                     *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                     *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))));
                  if ((char)uVar5 != '\0') {
                    return 1;
                  }
                }
                if (((yOutOfs & 2) == 0) &&
                   (uVar3 = ovc22_usesGUnitGrid2
                                      (*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                       *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2))),
                   uVar3 != 0)) {
                  uVar5 = ovc22_usesGMapFlags2
                                    (skipCheck,x1,y1,
                                     *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                     *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))));
                  if ((char)uVar5 != '\0') {
                    return 1;
                  }
                }
              }
              *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) = x1 + cStack_7 * iStack_4;
              if (cStack_7 < '\0') {
                *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) =
                     *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) - 1;
              }
              *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) = y1 + cStack_8 * iStack_6;
              if (((3 < *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004)) &&
                  (*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) < 0x90)) &&
                 ((*(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) != 0 &&
                  (*(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) < 0x3b)))) {
                uVar3 = ovc22_usesAlignUp4(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                           *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2)),
                                           mask);
                if ((char)uVar3 != '\0') {
                  return uVar3 & 0xff00;
                }
                if ((skipCheck != 0) &&
                   (uVar3 = ovc22_usesGUnitGrid(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                                *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))),
                   uVar3 != 0)) {
                  return CONCAT11((char)(uVar3 >> 8),1);
                }
                if ((((yOutOfs & 3) == 3) &&
                    (uVar5 = ovc22_testMapFlags(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                                *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),mask),
                    (char)uVar5 != '\0')) &&
                   (uVar3 = ovc22_usesGMapFlags2
                                      (skipCheck,x1,y1,
                                       *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                       *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))),
                   (char)uVar3 != '\0')) {
                  return uVar3 & 0xff00;
                }
                if ((((yOutOfs & 1) == 0) && (yOutSeg == 0)) &&
                   (bVar2 = ovc22_textArena2(*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                             *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2)))), bVar2)) {
                  uVar5 = ovc22_usesGMapFlags2
                                    (skipCheck,x1,y1,
                                     *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                     *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))));
                  if ((char)uVar5 != '\0') {
                    return 1;
                  }
                }
                if (((yOutOfs & 2) == 0) &&
                   (uVar3 = ovc22_usesGUnitGrid2
                                      (*(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                       *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))),(*(uint8_t *)((uint8_t *)&(yPtr) + 2))),
                   uVar3 != 0)) {
                  uVar5 = ovc22_usesGMapFlags2
                                    (skipCheck,x1,y1,
                                     *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004),
                                     *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))));
                  if ((char)uVar5 != '\0') {
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
      *(uint *)CONCAT22((uint *)xPtr,in_stack_00000004) = x1;
      *(uint *)CONCAT22((uint *)yPtr,(*(uint16_t *)((uint8_t *)&(xPtr) + 2))) = y1;
      uVar3 = (uint)puVar6 & 0xff00;
    }
    else {
      uVar3 = uVar4 & 0xff00;
    }
  }
  else {
    uVar3 = uVar3 & 0xff00;
  }
  return uVar3;
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
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint bldWord23;
  uint32_t sheetPtr;
  uint16_t randPick;
  uint uVar7;
  int sheetOfs;
  int unitCount;
  char unaff_SI;
  uint16_t unitsSeg;
  byte bldType;
  uint16_t y;
  uint16_t x;
  byte listIndex;
  undefined1 roll;
  char matchIdx;
  char targetIdx;
  byte hasUnits;
  byte bStack_3;
  
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
    bStack_3 = 0;
  }
  else {
    bStack_3 = 3;
  }
  if (((GLeaderSheets[partyIndex])->flags5d & 2) != 0) {
    bStack_3 = bStack_3 | 1;
  }
  sheetPtr = (uint32_t)GLeaderSheets[partyIndex];
  if ((*(byte *)((int)sheetPtr + 0x5d) & 4) != 0) {
    bStack_3 = bStack_3 | 2;
  }
  uVar7 = ovc22_searchCellsAround
                    ((uint *)CONCAT22(&y,_SS),
                     (uint *)CONCAT13((char)(((uint)partyIndex << 2) >> 8),
                                      CONCAT12(partyIndex,_SS)),bStack_3,hasUnits,unaff_SI);
  if ((uVar7 & 0xff) != 0) {
    if ((uVar7 & 0xff) != 1) {
      return;
    }
    uVar7 = ovc22_usesRandBelow(partyIndex,x,y);
    if (uVar7 == 0) {
      x = (GLeaderSheets[partyIndex])->x;
      y = (GLeaderSheets[partyIndex])->y;
    }
    else {
      if ((*(uint *)((uint8_t *)&BuildingTypes[uVar7] + 19) & 0x60) == 0) {
        unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[partyIndex] >> 0x10);
        sheetOfs = (int)(uint32_t)GLeaderSheets[partyIndex];
        unitCount = *(int *)(sheetOfs + 0x58);
        if ((unitCount < 0) ||
           ((unitCount == 0 && (*(uint *)(sheetOfs + 0x56) < *(uint *)((uint8_t *)&BuildingTypes[uVar7] + 23))))) {
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[partyIndex] >> 0x10);
          unitCount = (int)(uint32_t)GLeaderSheets[partyIndex];
          *(uint16_t *)(unitCount + 0x58) = 0;
          *(uint16_t *)(unitCount + 0x56) = 0;
        }
        else {
          bldWord23 = *(uint *)((uint8_t *)&BuildingTypes[uVar7] + 23);
          unitsSeg = (uint16_t)((ulong)(uint32_t)GLeaderSheets[partyIndex] >> 0x10);
          unitCount = (int)(uint32_t)GLeaderSheets[partyIndex];
          puVar1 = (uint *)(unitCount + 0x56);
          uVar3 = *puVar1;
          *puVar1 = *puVar1 - bldWord23;
          piVar2 = (int *)(unitCount + 0x58);
          *piVar2 = *piVar2 - (uint)(uVar3 < bldWord23);
        }
      }
      bldType = (byte)uVar7;
      ovr_createConstructionRecordFar
                (bldType,x,y,
                 (uint8_t *)CONCAT13((char)(outFlagSeg >> 8),CONCAT12((char)outFlagSeg,outFlag)),
                 partyIndex,unaff_SI,(char)y,(char)outFlag,(char)outFlagSeg);
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


