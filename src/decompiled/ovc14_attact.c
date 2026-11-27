/*
 * ovc14_attact.c - recovered from STRONG.EXE
 * memory block: OVC14_attact.c
 * range: 3f0b:0000 - 3f0b:2fbf
 * functions: 35
 */
#include "recovered.h"


/* 3f0b:0000 */

/* [R6] touches GMapFlags */

uint __cdecl16far attact_usesGMapFlags(uint x,int y,uint16_t arg3)

{
  uint in_AX;
  uint result;
  short *rowPtr;
  byte ptrHi;
  
  if (((((int)x < 0) || (y < 0)) || (in_AX = x + 1, 0x93 < (int)in_AX)) ||
     (in_AX = y + 1, 0x3b < (int)in_AX)) {
    result = in_AX & 0xff00;
  }
  else {
    if (((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) == 0) {
      rowPtr = (*(short (*) [60] [148])GMapFlags)[y] + x;
      ptrHi = (byte)((uint)rowPtr >> 8);
      if ((rowPtr[0x94] & 3U) == 0) {
        result = CONCAT11(ptrHi,1);
      }
      else {
        result = (uint)ptrHi << 8;
      }
    }
    else {
      result = ((x & 0x7fff) >> 7) << 8;
    }
  }
  return result;
}



/* 3f0b:007e */

/* [R6] touches GMapFlags */

uint __cdecl16far attact_usesGMapFlags2(int x,int y)

{
  uint in_AX;
  uint result;
  short *rowPtr;
  byte ptrHi;
  
  if ((((x < 0) || (y < 0)) || (in_AX = x + 1, 0x93 < (int)in_AX)) ||
     (in_AX = y + 1, 0x3b < (int)in_AX)) {
    result = in_AX & 0xff00;
  }
  else {
    rowPtr = (*(short (*) [60] [148])GMapFlags)[y] + x;
    ptrHi = (byte)((uint)rowPtr >> 8);
    if ((rowPtr[0x94] & 3U) == 0) {
      result = CONCAT11(ptrHi,1);
    }
    else {
      result = (uint)ptrHi << 8;
    }
  }
  return result;
}



/* 3f0b:00d8 */

/* Returns whether the 2x2 block of GMapCells at (x,y) varies by less than 0x3c. */

uint __cdecl16far attact_isTerrainFlat(int x,int y)

{
  /* Re-derived: 1 when the four corner heights of the cell differ by less than 0x3c, 0 when
     out of bounds or steeper.  The sole caller tests (result & 0xff), so the exported
     `in_AX & 0xff00` and `(uint)bVar2 << 8` high bytes were never observed and the tail is
     0/1.  The heights are addressed as an int array by the original, so the aliasing
     expression is preserved. */
  byte (*cells) [59] [148];
  int minHeight;
  int k;
  uint8_t maxHeight;

  if ((((x < 0) || (y < 0)) || (0x93 < x + 1)) || (0x3b < y + 1)) {
    return 0;
  }
  cells = (byte (*) [59] [148])GMapCells;
  maxHeight = (int)(char)(*cells)[y][x];
  minHeight = maxHeight;
  for (k = 1; k < 4; k = k + 1) {
    if (*(int *)(&maxHeight + k * 2) < minHeight) {
      minHeight = *(int *)(&maxHeight + k * 2);
    }
    if (maxHeight < *(int *)(&maxHeight + k * 2)) {
      maxHeight = *(int *)(&maxHeight + k * 2);
    }
  }
  if (maxHeight - minHeight < 0x3c) {
    return 1;
  }
  return 0;
}



/* 3f0b:01ec */

/* [R6] touches GUnits, GUnitGrid */

uint16_t __cdecl16far attact_usesGUnits(int x,int y)

{
  uint uVar1;
  uint16_t uVar2;
  
  uVar1 = attact_usesGMapFlags2(x,y);
  if ((uVar1 & 0xff) == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = attact_isTerrainFlat(x,y);
    if ((uVar1 & 0xff) == 0) {
      uVar2 = 0;
    }
    else if ((BuildingTypes[(uint)(GUnits + (*(short (*) [148] [60])GUnitGrid)[x][y])->bldType].flags & 3) == 3) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* 3f0b:027d */

/* [R6] touches SCARRY2, GMapFlags */

uint __cdecl16far attact_usesSCARRY2(int x,int y,byte dir,char ignoreBlocked,uint16_t arg5,uint16_t arg6)

{
  /* Re-derived: bounds-checks the cell reached through the direction tables at +0x885 (dx)
     and +0x889 (dy), then reads the two map-flag bits selected by the direction; 1 when the
     cell is out of bounds or blocked and blocking is honoured.  The SCARRY2 idiom is Ghidra's
     rendering of a signed comparison and is kept verbatim; the stale-AH out-of-bounds return
     is 1. */
  int step;
  uint result;

  step = (int)*(char *)(dir + 0x885);
  if ((((x + step < 2) ||
       (step = (int)*(char *)(dir + 0x889), SCARRY2(y,step) != y + step < 0)) ||
      (step = (int)*(char *)(dir + 0x885), 0x91 < x + step)) ||
     (step = (int)*(char *)(dir + 0x889), 0x39 < y + step)) {
    result = 1;
  }
  else {
    result = (uint)(*(short (*) [60] [148])GMapFlags)[y][x] >> (dir + 4 & 0x1f);
    if (((result & 1) == 0) || (ignoreBlocked != '\0')) {
      result = (uint)((byte)result & 1);
    }
    else {
      result = (uint)(*(short (*) [60] [148])GMapFlags)[y][x] >> (dir + 8 & 0x1f) & 0xff01 ^ 1;
    }
  }
  return result;
}



/* 3f0b:0362 */

/* [R6] touches SCARRY2, GMapFlags */

uint __cdecl16far attact_usesSCARRY22(int x,int y,byte dir,char ignoreBlocked,char directionOnly)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (int)*(char *)(dir + 0x885);
  if (((1 < x + iVar1) && (iVar1 = (int)*(char *)(dir + 0x889), SCARRY2(y,iVar1) == y + iVar1 < 0))
     && (iVar1 = (int)*(char *)(dir + 0x885), x + iVar1 < 0x92)) {
    iVar1 = (int)*(char *)(dir + 0x889);
    if (y + iVar1 < 0x3a) {
      if (directionOnly != '\0') {
        return (uint)(byte)(*(char *)(dir + 0x889) >> 7) << 8;
      }
      uVar2 = (uint)(*(short (*) [60] [148])GMapFlags)[y][x] >> (dir + 4 & 0x1f);
      if (((uVar2 & 1) != 0) && (ignoreBlocked == '\0')) {
        return (uint)(*(short (*) [60] [148])GMapFlags)[y][x] >> (dir + 8 & 0x1f) & 0xff01 ^ 1;
      }
      return (uint)((byte)uVar2 & 1);
    }
  }
  return CONCAT11((char)((uint)iVar1 >> 8),1);
}



/* 3f0b:0451 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Counts a party's entities that are off the cursor cell and unflagged, capped at 0x50. */

int __cdecl16far attact_countPartyUnits(byte menuIndex)

{
  uint uVar2;
  int count;
  
  count = 0;
  if (((uint8_t *)MenuItemEnabled)[menuIndex] == 0xff) {
    count = 0;
  }
  else {
    for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
      if (((AGNT_FIELD(&(Entities)[uVar2], base.entity, 3) == ((uint8_t *)MenuItemEnabled)[menuIndex]) &&
          (((*(uint *)(Entities + uVar2) < GfxRndSeed - 2U ||
            (GfxRndSeed + 1U < *(uint *)(Entities + uVar2))) ||
           ((Entities)[uVar2].base.y != GfxRndSeed2)))) &&
         ((AGNT_FIELD(&(Entities)[uVar2], base.flags32, 1) & 2) == 0)) {
        count = count + 1;
      }
    }
    if (0x50 < count) {
      count = 0x50;
    }
  }
  return count;
}



/* 3f0b:0540 */

/* [R2] string "Abnormal program termination\r\n" */

uint16_t __cdecl16far attact_textAbnormalProgramTermination(uint16_t value,uint8_t partyIndex)

{
  long *plVar1;
  uint16_t uVar2;
  uint16_t unaff_BP;
  long lVar3;
  uint16_t in_stack_00000000;
  uint16_t uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  uint in_stack_0000fffc;
  
  callResultTemp = attact_countPartyUnits(partyIndex);
  uVar5 = 0;
  uVar6 = 0;
  uVar4 = 0x51;
  uVar2 = 0;
  plVar1 = LXMUL_at_((long *)((char *)0x24151),
                     (ulong)in_stack_0000fffc << 0x10,CONCAT22(in_stack_00000000,unaff_BP));
  lVar3 = LDIV_at_((long)CONCAT22(uVar2,plVar1),CONCAT13(uVar6,CONCAT12(uVar5,uVar4)));
  return (uint16_t)lVar3;
}



/* 3f0b:057a */

/* resets SquareRecCount to 0 */

void __cdecl16far clearSquareRecords(void)

{
  SquareRecCount = 0;
  return;
}



/* 3f0b:0585 */

/* [R6] touches SquareRecCount */

int __cdecl16far attact_usesSquareRecCount(int x,int y)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (SquareRecCount <= uVar1) {
      return 0x86e;
    }
    if ((*(int *)(uVar1 * 0x13) == x) && (*(int *)((uint8_t *)&SquareRecs[uVar1] + 2) == y)) break;
    uVar1 = uVar1 + 1;
  }
  return uVar1 * 0x13;
}



/* 3f0b:05df */

/* [R6] touches SquareRecCount, SquareRecX */

void __cdecl16far attact_usesSquareRecCount2(void)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (SquareRecCount <= uVar1) {
      SquareRecX = GfxRndSeed;
      SquareRecY = GfxRndSeed2;
      _fmemmove((char far *)MK_FP(0x2410,0x9074),(char *)&SquareRecX,0x13);
      SquareRecIndex = SquareRecCount;
      return;
    }
    if ((*(int *)(uVar1 * 0x13) == GfxRndSeed) && (*(int *)((uint8_t *)&SquareRecs[uVar1] + 2) == GfxRndSeed2))
    break;
    uVar1 = uVar1 + 1;
  }
  _fmemmove((char far *)MK_FP(0x2410,0x9074),(char far *)MK_FP(0x17f8,(char *)(uVar1 * 0x13)),0x13);
  SquareRecIndex = uVar1;
  return;
}



/* 3f0b:0685 */

/* [R6] touches AgntFlag1, AgntCount */

void __cdecl16far attact_usesAgntFlag1(void)

{
  bool recomputed;
  int16_t cmpResult;
  int agntIdx;
  int recOfs;
  
  if (AgntFlag1) {
    recomputed = ovr_ovc15_usesAlignUp42();
    if (recomputed) {
      for (agntIdx = 0; agntIdx < (int)(uint)AgntCount; agntIdx = agntIdx + 1) {
        *(uint8_t far *)((uint8_t far *)&Agnts[agntIdx].entity->base.state + 1) =
             Agnts[agntIdx].strength;
      }
    }
    else {
      for (agntIdx = 0; agntIdx < (int)(uint)AgntCount; agntIdx = agntIdx + 1) {
        *(uint8_t far *)((uint8_t far *)&Agnts[agntIdx].entity->base.state + 1) =
             *(uint8_t far *)&Agnts[agntIdx].entity->base.flags32;
      }
    }
  }
  if (SquareRecIndex < SquareRecCount) {
    if (SquareRecIndex + 1 < SquareRecCount) {
      _fmemmove((char *)CONCAT22(0x17f8,(char *)(SquareRecIndex * 0x13)),
                (char *)CONCAT22(0x17f8,(char *)((SquareRecIndex + 1) * 0x13)),
                ((SquareRecCount - SquareRecIndex) + -1) * 0x13);
    }
    SquareRecCount = SquareRecCount - 1;
    cmpResult = memcmp((char *)&SquareRecX,(char *)0x24109074,0x13);
    if (cmpResult == 0) {
      sub_OVC04_0001(0x1000,0x9074,0x2410);
      return;
    }
  }
  else {
    cmpResult = memcmp((char *)&SquareRecX,(char *)0x24109074,0x13);
    if (cmpResult == 0) {
      sub_OVC04_0001(0x1000,0x9074,0x2410);
      return;
    }
    if (299 < SquareRecCount) {
      _fmemmove((char far *)SquareRecs,(char *)(SquareRecs + 1),0x1631);
      SquareRecCount = 299;
    }
  }
  _fmemmove((char far *)MK_FP(0x17f8,(char *)(SquareRecCount * 0x13)),(char far *)MK_FP(0x2410,0x9074),0x13);
  recOfs = SquareRecCount * 0x13;
  SquareRecCount = SquareRecCount + 1;
  sub_OVC04_0001(0x1000,recOfs,0x17f8);
  return;
}



/* 3f0b:082f */
ulong * __cdecl16far
attact_usesBDADailyTimeCounter(ulong *retStorage,ulong prevTick,uint16_t arg3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  if (((uint)prevTick < uVar1) ||
     (((uint)prevTick == uVar1 && (retStorage <= *(ulong * far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs))))) {
    iVar2 = -(int)retStorage;
  }
  else {
    iVar2 = 0xb0 - (int)retStorage;
  }
  return (ulong *)((int)*(ulong * far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) + iVar2);
}


/* 3f0b:0880 */

/* Decrements the byte pointed at by its argument when it is non-zero. */

void __cdecl16far attact_decrementCounter(char far *counter)

{
  if (*counter != '\0') {
    *counter = *counter + -1;
  }
  return;
}



/* 3f0b:0894 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches AgntCount, Entities */

int __cdecl16far attact_usesAgntCount(int ownerIndex)

{
  /* Re-derived: how many spare unit slots the owner has left - the entity's animation frame
     divided by 0x10, minus the agents already assigned to it that are not in move state 2 and
     have none of 0xae4 set, floored at 0. */
  uint frameSlots;
  int spare;
  byte agntIdx;
  uint8_t assigned;

  assigned = 0;
  for (agntIdx = 0; agntIdx < AgntCount; agntIdx = agntIdx + 1) {
    if (((Agnts[agntIdx].owner == ownerIndex) &&
        (Agnts[agntIdx].moveState != '\x02')) &&
       ((Agnts[agntIdx].flags & 0xae4) == 0)) {
      assigned = assigned + 1;
    }
  }
  frameSlots = ((Entities)[ownerIndex].base.animFrame + 0xf) / 0x10;
  if (frameSlots < assigned) {
    spare = 0;
  }
  else {
    spare = frameSlots - assigned;
  }
  return spare;
}



/* 3f0b:0941 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

void __cdecl16far attact_usesAlignUp4(uint16_t x,uint16_t y,char partyIndex,uint32_t flags,uint16_t arg5)

{
  /* Re-derived: for the menu slot matching the party, finds the square record at the cell,
     counts the entities of that party whose destination is the cell, and updates the stored
     count when it differs; if the cursor sits on the cell it either highlights the slot or
     sets a byte in the caller's flag array. */
  uint alignedX;
  uint entAlignedX;
  uint foundAligned;
  uint recIdx;
  uint entIdx;
  uint16_t count;
  uint seedAligned;
  byte slot;

  if (partyIndex != -1) {
    alignedX = ovr_alignUp4(x,0,0);
    for (slot = 0; slot < 5; slot = slot + 1) {
      if (((uint8_t *)MenuItemEnabled)[slot] == partyIndex) {
        recIdx = 0;
        while ((recIdx < SquareRecCount &&
               ((foundAligned = ovr_alignUp4(*(int *)(recIdx * 0x13),0,0),
                 foundAligned != alignedX ||
                 (*(uint16_t *)((uint8_t *)&SquareRecs[recIdx] + 2) != y))))) {
          recIdx = recIdx + 1;
        }
        if (SquareRecCount <= recIdx) {
          return;
        }
        count = 0;
        for (entIdx = 0; entIdx < EntityCount; entIdx = entIdx + 1) {
          entAlignedX = ovr_alignUp4((Entities)[entIdx].base.destX,0,0);
          if (entAlignedX == alignedX) {
            if (((Entities)[entIdx].base.destY == y) &&
               (*(char *)((int)&(Entities)[entIdx].base.entity + 3) ==
                partyIndex)) {
              count = count + 1;
            }
          }
        }
        if (*(byte *)(recIdx * 0x13 + (uint)slot + 0xe) != count) {
          *(undefined1 *)(recIdx * 0x13 + (uint)slot + 0xe) = (undefined1)count;
          seedAligned = ovr_alignUp4(GfxRndSeed,0,0);
          if ((seedAligned == alignedX) && (GfxRndSeed2 == y)) {
            if (flags == 0) {
              ovr_ovc41_usesMiceBlitRect((uint)slot);
            }
            else {
              *(undefined1 *)((int)flags + (uint)slot) = 1;
            }
          }
        }
      }
    }
  }
  return;
}



/* 3f0b:0ade */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches Entities, destX */

void __cdecl16far
attact_usesEntities(int entityIndex,uint16_t destX,uint16_t destY,uint16_t flagsOfs,uint16_t flagsSeg,uint16_t arg6,uint16_t arg7,uint16_t arg8,uint16_t arg9)

{
  uint16_t x;
  uint16_t y;
  int iVar1;
  
  (Entities)[entityIndex].base.faction = 0;
  (Entities)[entityIndex].base.state = 0;
  iVar1 = (int)Entities;
  x = ((entity_t *)iVar1)[entityIndex].base.destX;
  y = ((entity_t *)iVar1)[entityIndex].base.destY;
  if ((*(uint16_t *)((entity_t *)iVar1 + entityIndex) == destX) &&
     (((entity_t *)iVar1)[entityIndex].base.y == destY)) {
    destX = 0;
    destY = 0;
  }
  ((entity_t *)iVar1)[entityIndex].base.destX = destX;
  (Entities)[entityIndex].base.destY = destY;
  if ((x != 0) || (y != 0)) {
    attact_usesAlignUp4(x,y,*(char *)((int)&(Entities)[entityIndex].base.entity + 3),CONCAT22(flagsSeg,flagsOfs),0);
  }
  if ((destX != 0) || (destY != 0)) {
    attact_usesAlignUp4(destX,destY,*(char *)((int)&(Entities)[entityIndex].base.entity + 3),CONCAT22(flagsSeg,flagsOfs),0);
  }
  return;
}



/* 3f0b:0c2a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches GMapFlags, EntityCount */

void __stdcall16far attact_usesGMapFlags3(void)

{
  /* Re-derived from 3f0b:0c2a (1112 bytes, sub sp,0x5c).  Clears the 0x3000 bits, stamps
     0x1000<<AgntGs[gindex].ai on every entity's cell, then walks the entities: one whose four
     surrounding flag words are all 0x3000 either reports itself - building
     "Intelligence reports %s unit engaged in combat. (%d, %d)" with stsprintf and showing it
     through uiNotify - or just marks its entity byte, depending on GameRunning and the agent
     type; one whose cell is not 0x3000 has its mark cleared and its state high byte replaced
     by the flags32 low byte, with a sound when the cursor is on it.  Finally the game state is
     set to 0x3d, DebugVerbose prints it, and the OVC23 entry runs. */
  uint16_t *flagWord;
  int entX;
  int entY;
  int alignedX;
  int entIdx;
  int k;
  byte soundChoice;
  uint16_t flagAcc;
  byte sawGdataZero;
  byte sawGdataOther;
  byte gdataAi;
  char msg[80];

  ovr_driver_clearMapFlagsRect((uint32_t)GMapFlags,0,0,0x93,0x3b,0xcfff,0,0);
  for (entIdx = 0; entIdx < (int)(uint)EntityCount; entIdx = entIdx + 1) {
    flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[
                                ((entity_t far *)Entities)[entIdx].base.y]
                            + *(int *)((entity_t far *)Entities + entIdx));
    *flagWord = *flagWord |
                0x1000 << (AgntGs[(uint)((entity_t far *)Entities)[entIdx].base.gindex].ai &
                           0x1f);
  }
  soundChoice = ovr_ovc15_usesAlignUp42();
  sawGdataZero = 0;
  sawGdataOther = 0;
  for (entIdx = 0; entIdx < (int)(uint)EntityCount; entIdx = entIdx + 1) {
    entX = *(int *)((entity_t far *)Entities + entIdx);
    entY = ((entity_t far *)Entities)[entIdx].base.y;
    alignedX = ovr_alignUp4(entX,0,0);
    flagAcc = 0;
    for (k = 0; k < 4; k = k + 1) {
      flagAcc = flagAcc |
                (((*(short (*) [60] [148])GMapFlags)[entY][alignedX + k + -2]) & 0x3000U);
    }
    gdataAi = AgntGs[(uint)(Entities)[entIdx].base.gindex].ai;
    if (flagAcc == 0x3000) {
      if (AGNT_FIELD(&(Entities)[entIdx], base.entity, 1) != 0) {
        continue;
      }
      if ((GameRunning != false) || (gdataAi != 0)) {
        AGNT_FIELD(&(Entities)[entIdx], base.entity, 1) = 1;
      }
      else {
        ovr_uiNotify(stsprintf(msg,s_intelligence_rep_2410_5700,
                               AgntGs[(uint)(Entities)[entIdx].base.gindex].name,
                               alignedX,entY),0xa000);
        AGNT_FIELD(&(Entities)[entIdx], base.entity, 1) = 1;
      }
      if ((char)ovr_ovc23_isCursorAt(entX,entY) == '\0') {
        continue;
      }
      if (gdataAi == 0) {
        sawGdataZero = 1;
      }
      else {
        sawGdataOther = 1;
      }
      continue;
    }
    if (AGNT_FIELD(&(Entities)[entIdx], base.entity, 1) == 0) {
      continue;
    }
    if ((char)ovr_ovc23_isCursorAt(entX,entY) != '\0') {
      if (gdataAi != 0) {
        ovr_play_sfx(0x24,0);
      }
      else {
        ovr_play_sfx(0x26,0);
      }
    }
    AGNT_FIELD(&(Entities)[entIdx], base.entity, 1) = 0;
    AGNT_FIELD(&(Entities)[entIdx], base.state, 1) =
        AGNT_FIELD(&(Entities)[entIdx], base.flags32, 0);
  }
  if (sawGdataZero != 0 || sawGdataOther != 0) {
    if (soundChoice != 0) {
      if (sawGdataZero != 0) {
        ovr_play_sfx(0x23,0);
      }
      else if (sawGdataOther != 0) {
        ovr_play_sfx(0x25,0);
      }
    }
    else {
      ovr_stop_audio();
      CurSfxType3 = 0xff;
      ovr_play_sfx(0x5a,0);
    }
  }
  GGameState = 0x3d;
  if (DebugVerbose != false) {
    printf(s_d,GGameState);
  }
  ovr_OVC23_55fe_29a2_entry();
  return;
}



/* 3f0b:1082 */
void __cdecl16far attact_usesAlignUp42(void)

{
  uint16_t *yPtr;
  uint8_t *factionPtr;
  uint32_t sheetPtr;
  char ok;
  bool destNearSeed;
  bool startNearSeed;
  uint reportIdx;
  uint alignedDest;
  uint ownerByte;
  uint stExitResult;
  uint randResult;
  uint recIdx;
  uint alignedRec;
  uint alignedX;
  undefined1 valHi;
  uint16_t coinFlip;
  uint alignedEntX;
  char *pcVar12;
  entity_t *peVar14;
  uint16_t index;
  uint16_t segArg;
  entity_t *destEnt;   /* hand fix: dereferenced as destEnt->base */
  char rowsLeft;
  uint8_t reported;
  int targetSrc;
  int dySign;
  uint16_t zeroScratch;   /* [BP-0xc], cleared by _fmemset at 3f0b:1092 */
  int dxSign;
  undefined1 animByte;
  uint8_t reportedUnits;
  uint16_t startY;
  uint16_t startX;
  byte defByte;
  undefined1 flag4000;
  
  func_0x0004f735(0x3f0b);
  reported = 0x0;
  _fmemset(MK_FP(_SS, &zeroScratch), 0, 5);
  GGameState = 0x3f;
  if (DebugVerbose != false) {
    printf("%d %d %d \r");
  }
  segArg = 0x1000;
  debugStaleTickCount = 0;
  debugEmptyCellCount = 0;
  index = 0;
  do {
    if (EntityCount <= index) {
      GGameState = 0x3c;
      if (DebugVerbose != false) {
        segArg = 0x1000;
        printf("%d %d %d  \r");
      }
      func_0x0004fcda(segArg);
      GGameState = 0x3d;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r");
      }
      ovr_OVC23_55fe_29a2_entry();
      GGameState = 0xc;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r");
      }
      segArg = 0x2379;
      ovr_ovc24_removeOtherEntities(&reported);
      GGameState = 0x1f;
      if (reported != 0x0) {
        segArg = 0x22ef;
        ovr_constr_usesBlitRect();
        GGameState = 0x13;
      }
      func_0x0004f68f(segArg);
      GGameState = 0x1d;
      for (reportIdx = 0; (int)reportIdx < 5; reportIdx = reportIdx + 1) {
        if ((&reportedUnits)[reportIdx] != 0x0) {
          ovr_ovc41_usesMiceBlitRect(reportIdx);
        }
      }
      GGameState = 0xd;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r");
      }
      ovr_ovc24_checkStrongholds();
      GGameState = 0xe;
      mapDirty = 1;
      return;
    }
    peVar14 = Entities + index;
    destEnt = (entity_t *)CONCAT22(DAT_2000_d190,peVar14);
    alignedDest = ovr_alignUp4((peVar14->base).destX,0,0);
    segArg = 0x2379;
    alignedX = ovr_alignUp4((destEnt->base).x,0,0);
    if ((alignedDest == alignedX) && ((peVar14->base).destY == (peVar14->base).y)) {
      manage_usesCurSfxType32(0x2379,index,(peVar14->base).destX,(peVar14->base).destY);
    }
    if (((peVar14->base).destX != 0 || (peVar14->base).destY != 0) &&
       (*(char *)((int)&(peVar14->base).entity + 1) == '\0')) {
      flag4000 = (AgntGs[(uint)(peVar14->base).gindex].flags2
                 & 0x4000) != 0;
      startX = (destEnt->base).x;
      startY = (peVar14->base).y;
      animByte = AgntGs[(uint)(peVar14->base).gindex].ai;
      if ((peVar14->base).faction < (byte)(peVar14->base).state) {
        ownerByte = (int)(uint)*(byte *)((int)&(peVar14->base).owner +
                                    ((int)(uint)(peVar14->base).faction >> 2)) >>
                (((peVar14->base).faction & 3) << 1) & 0xff03;
        (peVar14->base).target = (uint8_t)ownerByte;
        valHi = (undefined1)(ownerByte >> 8);
        ok = func_0x0004f32d(0x2379,(destEnt->base).x,(peVar14->base).y,
                                CONCAT11(valHi,(peVar14->base).target),CONCAT11(valHi,animByte));
        if (ok == '\0') {
          (destEnt->base).x = (destEnt->base).x + (int)*(char *)((peVar14->base).target + 0x885)
          ;
          yPtr = &(peVar14->base).y;
          *yPtr = *yPtr + (int)*(char *)((peVar14->base).target + 0x889);
          factionPtr = &(peVar14->base).faction;
          *factionPtr = *factionPtr + 0x1;
        }
        else {
          (peVar14->base).faction = 0x0;
          *(undefined1 *)&(peVar14->base).state = 0;
        }
      }
      else {
        dxSign = ovr_ovc07_signum((peVar14->base).destX - (destEnt->base).x);
        segArg = 0x22da;
        dySign = ovr_ovc07_signum((peVar14->base).destY - (peVar14->base).y);
        if (dxSign != 0) {
          segArg = 0x2337;
          coinFlip = ovr_randBelow(2,0);
          if ((char)coinFlip != '\0') {
            ok = sub_OVC21_manage_c_23C2(0x2337,startX,startY,'\x02' - (char)dxSign,animByte,
                                    flag4000);
            if (ok == '\0') {
              (destEnt->base).x = (destEnt->base).x + dxSign;
              (peVar14->base).target = 0x2 - (char)dxSign;
              goto L_attact_3f0b_1082_1477;
            }
          }
        }
        if (dySign != 0) {
          ok = sub_OVC21_manage_c_23C2(segArg,startX,startY,(char)dySign + '\x01',animByte,
                                  flag4000);
          if (ok == '\0') {
            yPtr = &(peVar14->base).y;
            *yPtr = *yPtr + dySign;
            (peVar14->base).target = (char)dySign + 0x1;
            goto L_attact_3f0b_1082_1477;
          }
        }
        if (dxSign != 0) {
          ok = sub_OVC21_manage_c_23C2(segArg,startX,startY,'\x02' - (char)dxSign,animByte,
                                  flag4000);
          if (ok == '\0') {
            (destEnt->base).x = (destEnt->base).x + dxSign;
            (peVar14->base).target = 0x2 - (char)dxSign;
            goto L_attact_3f0b_1082_1477;
          }
        }
        stExitResult = ovr_ovc26_usesStExit(index);
        if ((char)stExitResult == '\0') {
          randResult = ovr_ovc26_usesRandBelow
                            (index,(uint16_t)&reported,_SS,(uint16_t)&reportedUnits,_SS);
          if (((randResult & 0xff) == 0) &&
             (AgntGs[(uint)(peVar14->base).gindex].ai ==
              '\0')) {
            manage_usesCurSfxType32(0x2386,index,(peVar14->base).targetX,(peVar14->base).targetY);
          }
        }
        else {
          ownerByte = (int)(uint)*(byte *)((int)&(peVar14->base).owner +
                                      ((int)(uint)(peVar14->base).faction >> 2)) >>
                  (((peVar14->base).faction & 3) << 1) & 0xff03;
          (peVar14->base).target = (uint8_t)ownerByte;
          valHi = (undefined1)(ownerByte >> 8);
          ok = func_0x0004f32d(0x2386,startX,startY,CONCAT11(valHi,(peVar14->base).target),
                                  CONCAT11(valHi,animByte));
          if (ok == '\0') {
            (destEnt->base).x =
                 (destEnt->base).x + (int)*(char *)((peVar14->base).target + 0x885);
            yPtr = &(peVar14->base).y;
            *yPtr = *yPtr + (int)*(char *)((peVar14->base).target + 0x889);
            factionPtr = &(peVar14->base).faction;
            *factionPtr = *factionPtr + 0x1;
          }
        }
      }
L_attact_3f0b_1082_1477:
      reported = 0x1;
      alignedDest = ovr_alignUp4((peVar14->base).destX,0,0);
      alignedX = ovr_alignUp4((destEnt->base).x,0,0);
      if ((alignedDest == alignedX) && ((peVar14->base).destY == (peVar14->base).y)) {
        (peVar14->base).destX = 0;
        (peVar14->base).destY = 0;
        if (*(char *)((int)&(peVar14->base).entity + 3) == -1) {
          defByte = 0xff;
        }
        else {
          sheetPtr = (uint32_t)GLeaderSheets[*(byte *)((int)&(peVar14->base).entity + 3)];
          defByte = *(byte *)((int)sheetPtr + 0x89);
        }
        if (defByte != 0xff) {
          for (recIdx = 0; recIdx < SquareRecCount; recIdx = recIdx + 1) {
            alignedX = ovr_alignUp4(*(int *)(recIdx * 0x13),0,0);
            alignedEntX = ovr_alignUp4((destEnt->base).x,0,0);
            if ((alignedX == alignedEntX) && (*(uint16_t *)((uint8_t *)&SquareRecs[recIdx] + 2) == (peVar14->base).y)) {
              func_0x0004f930(0x2379,recIdx * 0x13 + (uint)defByte + 0xe,0x17f8);
              if (*(uint16_t *)((uint8_t *)&SquareRecs[recIdx] + 2) == GfxRndSeed2) {
                alignedRec = ovr_alignUp4(*(int *)(recIdx * 0x13),0,0);
                alignedX = ovr_alignUp4(GfxRndSeed,0,0);
                if (alignedRec == alignedX) {
                  (&reportedUnits)[defByte] = 0x1;
                }
              }
              break;
            }
          }
        }
      }
      segArg = 0x2379;
      if (AgntFlag1 != false) {
        if ((((destEnt->base).x < GfxRndSeed - 2U) || (GfxRndSeed + 1U < (destEnt->base).x)) ||
           ((peVar14->base).y != GfxRndSeed2)) {
          destNearSeed = false;
        }
        else {
          destNearSeed = true;
        }
        if (((startX < GfxRndSeed - 2U) || (GfxRndSeed + 1U < startX)) ||
           (GfxRndSeed2 != startY)) {
          startNearSeed = false;
        }
        else {
          startNearSeed = true;
        }
        if (startNearSeed || destNearSeed) {
          if (startNearSeed) {
            if (destNearSeed) {
              for (rowsLeft = manage_usesLitoa103(); rowsLeft != '\0'; rowsLeft = rowsLeft + -1) {
                if (((peVar14->base).target & 1) == 0) {
                  targetSrc = 0;
                }
                else {
                  targetSrc = (peVar14->base).target - 2;
                }
                segArg = 0x2322;
                pcVar12 = ovr_ovc15_textArena(index,0,0);
                if (((uint)pcVar12 & 0xff) == 0) break;
              }
            }
            else {
              rowsLeft = (char)((ulong)((peVar14->base).animFrame + 0xf) / 0x10);
              while (rowsLeft != '\0') {
                segArg = 0x22ff;
                ovr_agnt_usesAgntCount6(Entities + index,DAT_2000_d190);
                rowsLeft = rowsLeft + -1;
              }
            }
          }
          else {
            ovr_ovc15_clearVisited();
            rowsLeft = (char)((ulong)((peVar14->base).animFrame + 0xf) / 0x10);
            if (((peVar14->base).target & 1) == 0) {
              targetSrc = 0;
            }
            else {
              targetSrc = (peVar14->base).target - 2;
            }
            while( true ) {
              segArg = 0x2322;
              if (rowsLeft == '\0') break;
              ovr_ovc15_textArena(index,0,0);
              rowsLeft = rowsLeft + -1;
            }
          }
        }
      }
    }
    index = index + 1;
  } while( true );
}


/* 3f0b:18fe */

/* Updates one attract-menu entry: caches its value, shows the 'cannot attract' message or
   recomputes its count. */

void __cdecl16far attact_updateAttractEntry(int itemIndex,int force)

{
  int column;
  uint subResult;
  uint16_t plural;
  char *txt;
  uint16_t textSeg;
  uint16_t dst;
  static char msg[64];   /* DGROUP so the near buffer is valid */
  uint rowValue;
  byte itemId;
  byte entryClass;
  
  if ((itemIndex < 5) &&
     ((rowValue = (uint)((uint8_t *)menuItemRow)[itemIndex], force != 0 ||
      (PrevMenuValue != rowValue)))) {
    PrevMenuValue = rowValue;
    ovr_resetTextBlitCycle();
    itemId = ((uint8_t *)MenuItemEnabled)[itemIndex];
    if (itemId != 0xff) {
      column = ovr_ovc23_findClearColumn(GfxRndSeed,GfxRndSeed2);
      if (column < 0) {
        ovr_drawTextAt((char *)"You cannot attract units to this location.",0x2410,0xa000);
        ((uint8_t *)menuItemRow)[itemIndex] = 0x0;
      }
      else {
        subResult = sub_OVC21_manage_c_24B1(0x236f,itemIndex & 0xff);
        callResultTemp = subResult;
        if (subResult < rowValue) {
          (*(uint8_t *)((uint8_t *)&(rowValue))) = (uint8_t)subResult;
          ((uint8_t *)menuItemRow)[itemIndex] = (uint8_t)rowValue;
          rowValue = subResult;
        }
        textSeg = _DS;
        entryClass = *(byte *)((int)*(uint32_t *)((uint)itemId << 2) + 0x2f);
        if (entryClass != 0xff) {
          plural = ovr_ovc41_pluralSuffix(rowValue,0xa000);
          dst = 0x2410;
          txt = ovr_stsprintf(msg,(char *)CONCAT22(0x921,_SS),
                              (char *)CONCAT22(rowValue,(char *)0x26510),callResultTemp,
                              *(uint16_t *)((uint)entryClass * 4 + 0x13f),
                              *(uint16_t *)((uint)entryClass * 4 + 0x141),plural,textSeg);
          ovr_drawTextAt(txt,dst,0);
        }
      }
    }
  }
  return;
}



/* 3f0b:1a2f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R2] string "arena" */

bool __cdecl16far
attact_textArena(uint16_t *foundIndexOut,int mode,uint8_t partyIndex,uint16_t x,uint16_t y)

{
  /* Re-derived: nearest entity of the given party, by |dx| + 2*|dy| in aligned columns.
     `mode` selects which candidates qualify (0: destination not set, 1: destination still
     at the origin, 2: flag bit 1, 3: flag bit 4).  Returns whether a candidate was found
     and stores its index. */
  uint targetAlignedX;
  uint bestDist;
  uint dx;
  uint dxSign;
  uint dy;
  uint dySign;
  uint dist;
  uint destAlignedX;
  int entitiesOfs;
  uint entIdx;
  bool qualifies;

  bestDist = 0xffff;
  targetAlignedX = ovr_alignUp4(x,0,0);
  for (entIdx = 0; entIdx < EntityCount; entIdx = entIdx + 1) {
    if (*(char *)((int)&(Entities)[entIdx].base.entity + 3) == partyIndex) {
      dx = ovr_alignUp4((Entities)[entIdx].base.x,0,0) - targetAlignedX;
      dxSign = (int)dx >> 0xf;
      dy = (Entities)[entIdx].base.y - y;
      dySign = (int)dy >> 0xf;
      dist = ((dx ^ dxSign) - dxSign) + ((dy ^ dySign) - dySign) * 2;
      if ((dist != 0) && (dist < bestDist)) {
        destAlignedX = ovr_alignUp4((Entities)[entIdx].base.destX,0,0);
        entitiesOfs = (int)Entities;
        qualifies =
            (mode == 0 &&
             ((AGNT_FIELD(&(Entities)[entIdx], base.flags32, 1) & 2) == 0)) ||
            (mode == 1 &&
             ((entity_t *)entitiesOfs)[entIdx].base.destX == 0 &&
             ((entity_t *)entitiesOfs)[entIdx].base.destY == 0 &&
             ((AGNT_FIELD(&(Entities)[entIdx], base.flags32, 1) & 2) == 0)) ||
            (mode == 2 &&
             ((AGNT_FIELD(&(Entities)[entIdx], base.flags32, 1) & 1) != 0)) ||
            (mode == 3 &&
             ((AGNT_FIELD(&(Entities)[entIdx], base.flags32, 1) & 4) != 0));
        if (((destAlignedX != targetAlignedX) ||
            (((entity_t *)entitiesOfs)[entIdx].base.destY != y)) && qualifies) {
          *foundIndexOut = entIdx;
          bestDist = dist;
        }
      }
    }
  }
  return bestDist != 0xffff;
}



/* 3f0b:1bfc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R2] string "arena" */

bool __cdecl16far attact_textArena2(uint *foundIndexOut,uint16_t partyIndex,uint16_t x)

{
  uint targetX;
  uint dist;
  uint uVar3;
  uint signMaskX;
  uint signMaskY;
  uint entityIndex;
  int targetY;
  uint bestDist;
  
  bestDist = 0;
  targetX = ovr_alignUp4(x,0,0);
  for (entityIndex = 0; entityIndex < EntityCount; entityIndex = entityIndex + 1) {
    if (*(char *)((int)&(Entities)[entityIndex].base.entity + 3) == (char)partyIndex) {
      dist = ovr_alignUp4((Entities)[entityIndex].base.x,0,0);
      signMaskX = (int)(dist - targetX) >> 0xf;
      uVar3 = (Entities)[entityIndex].base.y - targetY;
      signMaskY = (int)uVar3 >> 0xf;
      dist = ((dist - targetX ^ signMaskX) - signMaskX) + ((uVar3 ^ signMaskY) - signMaskY) * 2;
      if (((bestDist < dist) &&
          (uVar3 = ovr_alignUp4((Entities)[entityIndex].base.destX,0,0), uVar3 == targetX)) &&
         ((Entities)[entityIndex].base.destY == targetY)) {
        *foundIndexOut = entityIndex;
        bestDist = dist;
      }
    }
  }
  return bestDist != 0;
}



/* 3f0b:1cfb */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R2] string "arena" */

bool __cdecl16far attact_textArena3(uint far *foundIndexOut, uint16_t partyIndex, int x, int y)

{
  /* Re-derived: the FARTHEST entity of the party by |dx| + 2*|dy| in aligned columns -
     attact_textArena picks the nearest with the same metric.  `y` is the 4th stack argument
     ([bp+0xc]) the export never named; the function has no callers in the tree. */
  uint bestDist;
  uint alignedX;
  uint dx;
  uint dy;
  uint dxSign;
  uint dySign;
  uint dist;
  uint entIdx;

  bestDist = 0;
  alignedX = ovr_alignUp4(x,0,0);
  for (entIdx = 0; entIdx < EntityCount; entIdx = entIdx + 1) {
    if (*(char *)((int)&(Entities)[entIdx].base.entity + 3) ==
        (char)partyIndex) {
      dx = ovr_alignUp4((Entities)[entIdx].base.x,0,0) - alignedX;
      dxSign = (int)dx >> 0xf;
      dy = (Entities)[entIdx].base.y - y;
      dySign = (int)dy >> 0xf;
      dist = ((dx ^ dxSign) - dxSign) + ((dy ^ dySign) - dySign) * 2;
      if (bestDist < dist) {
        *foundIndexOut = entIdx;
        bestDist = dist;
      }
    }
  }
  return bestDist != 0;
}



/* 3f0b:1db1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

void __cdecl16far attact_usesAlignUp43(uint16_t far *value)

{
  /* Re-derived.  alignUp4(*value) is the target column; if that cell is blocked the free
     offset in -2..1 nearest to it is used instead.  For each of the five party slots the
     function counts the entities already heading there, then moves further entities in by
     decreasing priority flag (3 down to 0) and finally sends the surplus back to their own
     targets. */
  byte *flagsPtr;
  char blitOk;
  bool movedOk;
  uint targetAligned;
  uint entityAligned;
  uint16_t far *valuePtr;
  uint placedCount;
  uint slot;
  int entIdx;
  uint16_t destX;
  byte partyIdx;
  byte menuState;

  targetAligned = ovr_alignUp4(*value,0,0);
  destX = *value;
  valuePtr = value;
  blitOk = func_0x0004f29c(0x2379,destX,valuePtr[1]);
  if (blitOk == '\0') {
    entIdx = -2;
    while ((entIdx < 2 &&
           (blitOk = func_0x0004f29c(0x2379,destX + entIdx,valuePtr[1]),
           blitOk == '\0'))) {
      entIdx = entIdx + 1;
    }
    if (entIdx < 2) {
      destX = destX + entIdx;
    }
  }
  for (slot = 0; (int)slot < 5; slot = slot + 1) {
    placedCount = 0;
    for (entIdx = 0; entIdx < EntityCount; entIdx = entIdx + 1) {
      partyIdx = AGNT_FIELD(&(Entities)[entIdx], base.entity, 3);
      if ((((partyIdx != 0xff) &&
           ((GLeaderSheets[partyIdx])->partySlot == slot)) &&
          (entityAligned = ovr_alignUp4((Entities)[entIdx].base.destX,0,0),
           entityAligned == targetAligned)) &&
         ((Entities)[entIdx].base.destY == valuePtr[1])) {
        placedCount = placedCount + 1;
      }
    }
    menuState = ((uint8_t *)MenuItemEnabled)[slot];
    if (*(byte *)((int)valuePtr + slot + 0xe) != placedCount) {
    while (((int)placedCount < (int)(uint)*(byte *)((int)valuePtr + slot + 0xe) &&
           (movedOk = attact_textArena((uint16_t *)CONCAT22(_SS,&entIdx),3,menuState,
                                      *value,valuePtr[1]), movedOk))) {
      (Entities)[entIdx].base.state = 0;
      (Entities)[entIdx].base.destX = destX;
      (Entities)[entIdx].base.destY = valuePtr[1];
      flagsPtr = (byte *)((uint8_t *)&(Entities)[entIdx] + 0x33);
      *flagsPtr = *flagsPtr & 0xfb;
      placedCount = placedCount + 1;
    }
    while (((int)placedCount < (int)(uint)*(byte *)((int)valuePtr + slot + 0xe) &&
           (movedOk = attact_textArena((uint16_t *)CONCAT22(_SS,&entIdx),2,menuState,
                                      *value,valuePtr[1]), movedOk))) {
      (Entities)[entIdx].base.state = 0;
      (Entities)[entIdx].base.destX = destX;
      (Entities)[entIdx].base.destY = valuePtr[1];
      placedCount = placedCount + 1;
    }
    while (((int)placedCount < (int)(uint)*(byte *)((int)valuePtr + slot + 0xe) &&
           (movedOk = attact_textArena((uint16_t *)CONCAT22(_SS,&entIdx),1,menuState,
                                      *value,valuePtr[1]), movedOk))) {
      (Entities)[entIdx].base.state = 0;
      (Entities)[entIdx].base.destX = destX;
      (Entities)[entIdx].base.destY = valuePtr[1];
      placedCount = placedCount + 1;
    }
    while (((int)placedCount < (int)(uint)*(byte *)((int)valuePtr + slot + 0xe) &&
           (movedOk = attact_textArena((uint16_t *)CONCAT22(_SS,&entIdx),0,menuState,
                                      *value,valuePtr[1]), movedOk))) {
      (Entities)[entIdx].base.state = 0;
      (Entities)[entIdx].base.destX = destX;
      (Entities)[entIdx].base.destY = valuePtr[1];
      placedCount = placedCount + 1;
    }
while (((int)(uint)*(byte *)((int)valuePtr + slot + 0xe) < (int)placedCount &&
           (movedOk = attact_textArena2((uint *)CONCAT22(_SS,&entIdx),(uint)menuState,
                                       *value), movedOk))) {
      (Entities)[entIdx].base.state = 0;
        (Entities)[entIdx].base.destX =
             (Entities)[entIdx].base.targetX;
        (Entities)[entIdx].base.destY =
             (Entities)[entIdx].base.targetY;
        placedCount = placedCount - 1;
    }
    }
  }
  return;
}



/* 3f0b:21ef */

/* [R4] calls LDIV_at_ */

uint16_t __cdecl16far attact_usesLDIV_at_(uint8_t menuIndex)

{
  long *plVar1;
  undefined1 uVar2;
  uint16_t uVar3;
  uint16_t unaff_BP;
  long lVar4;
  uint16_t in_stack_00000000;
  long *plVar5;
  uint16_t uVar6;
  undefined1 in_stack_0000fffc;
  undefined1 uVar7;
  undefined1 in_stack_0000fffd;
  
  callResultTemp = sub_OVC21_manage_c_24B1(0x3f0b,menuIndex);
  if ((long *)callResultTemp == (long *)0x0) {
    uVar7 = 0;
    uVar2 = 0;
  }
  else {
    uVar6 = 0;
    uVar3 = 0;
    plVar5 = (long *)callResultTemp;
    plVar1 = LXMUL_at_((long *)callResultTemp,
                       (ulong)CONCAT11(in_stack_0000fffd,in_stack_0000fffc) << 0x10,
                       CONCAT22(in_stack_00000000,unaff_BP));
    lVar4 = LDIV_at_((long)CONCAT22(uVar3,plVar1),(long)CONCAT22(uVar6,plVar5));
    uVar2 = (undefined1)((ulong)lVar4 >> 8);
    uVar7 = (undefined1)lVar4;
  }
  if (0x50 < CONCAT11(uVar2,uVar7)) {
    uVar7 = 0x50;
  }
  return CONCAT11(uVar2,uVar7);
}



/* 3f0b:2252 */

/* [R7] body shape: compute */

void __cdecl16far
attact_compute2(uint16_t menuIndex,far_t pctOut,far_t remainderOut,far_t partOut)

{
  int iVar1;
  
  *(char *)MK_FP(pctOut.seg, pctOut.ofs) =
       (char)(((0x1c - (char)((undefined *)&menuCursorY)[menuIndex & 0xff]) * 100) / 0x1c);
  iVar1 = (int)(char)((undefined *)&menuCursorY)[menuIndex & 0xff] << 1;
  if (iVar1 == 0) {
    *(undefined1 *)MK_FP(partOut.seg, partOut.ofs) = 0;
    *(undefined1 *)MK_FP(remainderOut.seg, remainderOut.ofs) = 0;
  }
  else {
    *(char *)MK_FP(partOut.seg, partOut.ofs) =
         (char)((int)((100 - (uint)*(byte *)MK_FP(pctOut.seg, pctOut.ofs)) *
                     ((int)(char)((undefined *)&menuCursorX)[menuIndex & 0xff] + iVar1 / 2 + -0x1c))
               / iVar1);
    *(char *)MK_FP(remainderOut.seg, remainderOut.ofs) = ('d' - *(char *)MK_FP(pctOut.seg, pctOut.ofs)) - *(char *)MK_FP(partOut.seg, partOut.ofs);
  }
  return;
}



/* 3f0b:2303 */

/* [R7] body shape: compute */

void __cdecl16far
attact_compute3(far_t table,uint16_t index,far_t pctOut,far_t remainderOut,far_t partOut)

{
  int iVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  
  uVar3 = table.seg;
  uVar2 = table.ofs;
  *(char *)MK_FP(pctOut.seg, pctOut.ofs) = (char)(((0x1c - *(char *)(uVar2 + (index & 0xff) + 9)) * 100) / 0x1c);
  iVar1 = (int)*(char *)(uVar2 + (index & 0xff) + 9) << 1;
  if (iVar1 == 0) {
    *(undefined1 *)MK_FP(partOut.seg, partOut.ofs) = 0;
    *(undefined1 *)MK_FP(remainderOut.seg, remainderOut.ofs) = 0;
  }
  else {
    *(char *)MK_FP(partOut.seg, partOut.ofs) =
         (char)((int)((100 - (uint)*(byte *)MK_FP(pctOut.seg, pctOut.ofs)) *
                     ((int)*(char *)(uVar2 + (index & 0xff) + 4) + iVar1 / 2 + -0x1c)) / iVar1);
    *(char *)MK_FP(remainderOut.seg, remainderOut.ofs) = ('d' - *(char *)MK_FP(pctOut.seg, pctOut.ofs)) - *(char *)MK_FP(partOut.seg, partOut.ofs);
  }
  return;
}



/* 3f0b:23ab */

/* [R4] calls ovr_alignUp4 */

uint __cdecl16far attact_usesAlignUp44(int *xPtr,int y,uint8_t dir)

{
  uint uVar1;
  uint16_t uVar2;
  uint uVar3;
  int value;
  undefined1 in_stack_0000000c;
  
  uVar2 = 0x3f0b;
  if ((dir & 1) == 0) {
    uVar1 = ovr_EXT_FUN_8000_f2fa(0x3f0b,*xPtr,y,dir,in_stack_0000000c);
  }
  else {
    value = *xPtr;
    do {
      uVar2 = ovr_EXT_FUN_8000_f2fa(uVar2,*xPtr,y,dir,in_stack_0000000c);
      if ((char)uVar2 != '\0') {
        return 1;
      }
      value = value + *(char *)(dir + 0x885);
      uVar3 = ovr_alignUp4(*xPtr,0,0);
      uVar2 = 0x2379;
      uVar1 = ovr_alignUp4(value,0,0);
    } while (uVar3 == uVar1);
    *xPtr = value;
    /* 0x332DA mov al,0: this path returns zero; the exported mask kept a stale AH. */
    uVar1 = 0;
  }
  return uVar1;
}



/* 3f0b:2430 */
void __cdecl16far attact_usesRandBelow(agnt_t far *agnt,byte dir,uint16_t arg3,uint16_t arg4)

{
  uint16_t uVar1;
  uint uVar2;
  int iVar3;
  undefined1 uStack0007;
  byte in_stack_00000008;
  uint16_t agntX;   /* hand fix: [BP-6] is a WORD copy of agnt->x (3f0b:246f) */
  uint16_t uStack_6;
  int iStack_4;
  
  agnt = (int *)CONCAT13(uStack0007,CONCAT12(dir,agnt));
  if (in_stack_00000008 == 0xff) {
    uVar1 = ovr_randBelow(4,AgntGs[(uint)agnt->gindex].ai);
    in_stack_00000008 = (byte)uVar1;
    do {
      agntX = agnt->x;
      uVar2 = attact_usesAlignUp44((int *)CONCAT22(_SS,&agntX),agnt->y,in_stack_00000008);
      if ((uVar2 & 0xff) == 0) goto L_attact_3f0b_2430_24BF;
      in_stack_00000008 = in_stack_00000008 + 1 & 3;
    } while (in_stack_00000008 != (byte)uVar1);
  }
  else {
    agntX = agnt->x;
    in_stack_00000008 = in_stack_00000008 ^ 2;
L_attact_3f0b_2430_24BF:
    iStack_4 = agnt->x;
    uStack_6 = agnt->y;
    agnt->y = agnt->y + (int)*(char *)(in_stack_00000008 + 0x889);
    iVar3 = ovr_ovc23_compute2(agntX + *(char *)(in_stack_00000008 + 0x885),agnt->y);
    agnt->x = iVar3;
    func_0x0004fcda(0x236f);
    constructionDirty = 1;
  }
  return;
}


/* 3f0b:251d */

/* [R4] calls ovr_updSeason */

void __cdecl16far attact_usesUpdSeason(void)

{
  bool bVar1;
  
  GWantsExit2 = 1;
  GameTick = GameTick + 1;
  GGameState = 3;
  if (DebugVerbose) {
    printf("%d \r");
  }
  timePassing = 0;
  attact_usesAlignUp42();
  if (GGameInProgress == '\0') {
    spyReportTimer = spyReportTimer + 1;
    if (9 < spyReportTimer) {
      spyReportTimer = 0;
      GGameState = 7;
      if (DebugVerbose != false) {
        printf("%d \r");
      }
      ovr_ovc25_spyReportNotice();
    }
    seasonTimer = seasonTimer + 1;
    if (0xe < seasonTimer) {
      seasonTimer = 0;
      GGameState = 5;
      if (DebugVerbose != false) {
        printf("%d \r");
      }
      ovr_ovc22_spawnForLeaders();
      ovr_season_usesGPromotableCount();
      ovr_unit_usesAlignUp4();
      ovr_updSeason();
    }
    if (GTimeHi != '\0') {
      ovr_updSeason();
    }
    unitUpdateTimer = unitUpdateTimer + 1;
    if (4 < unitUpdateTimer) {
      unitUpdateTimer = 0;
      GGameState = 0x20;
      if (DebugVerbose != false) {
        printf("%d \r");
      }
      ovr_upd_usesAlignUp4();
      GGameState = 0x3c;
      if (DebugVerbose != false) {
        printf("%d \r");
      }
    }
    bVar1 = 0xfffe < tickCountLo;
    tickCountLo = tickCountLo + 1;
    tickCountHi = tickCountHi + (uint)bVar1;
    (*(uint16_t *)((uint8_t *)&(GDailyTimeCounter) + 2)) = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    (*(uint16_t *)((uint8_t *)&(GDailyTimeCounter))) = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
  }
  return;
}



/* 3f0b:26bd */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches EntityCount, Entities */

void __cdecl16far attact_usesEntityCount(void)

{
  int remaining;
  char *arenaText;
  uint owner;
  uint16_t cursorHit;
  undefined1 targetCode;
  
  owner = 0;
  do {
    if (EntityCount <= owner) {
      return;
    }
    cursorHit = ovr_ovc23_isCursorAt
                      ((Entities)[owner].base.x,(Entities)[owner].base.y,0);
    if ((char)cursorHit != '\0') {
      for (remaining = manage_usesLitoa103(0x236f,owner); remaining != 0; remaining = remaining + -1) {
        if (((Entities)[owner].base.target & 1) == 0) {
          targetCode = 0;
        }
        else {
          targetCode = (Entities)[owner].base.target - 2;
        }
        arenaText = ovr_ovc15_textArena(owner,(uint)targetCode,0);
        if (((uint)arenaText & 0xff) == 0) break;
      }
    }
    owner = owner + 1;
  } while( true );
}



/* 3f0b:277b */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches EntityCount, Entities */

void __cdecl16far attact_usesEntityCount2(uint16_t *sum,uint16_t *enemySum)

{
  /* Re-derived: accumulates animFrame*level*level per entity into two 32-bit sums, split
     by whether AgntGs[gindex].ai is zero (own units vs enemies).  Only entities under the
     cursor are counted. */
  uint16_t *hiPtr;
  uint oldLo;
  uint addend;
  uint entIdx;
  uint16_t hit;

  enemySum[1] = 0;
  *enemySum = 0;
  sum[1] = 0;
  *sum = 0;
  for (entIdx = 0; entIdx < EntityCount; entIdx = entIdx + 1) {
    hit = ovr_ovc23_isCursorAt((Entities)[entIdx].base.x,
                               (Entities)[entIdx].base.y);
    if ((char)hit != '\0') {
      if (AgntGs[(uint)(Entities)[entIdx].base.gindex].ai == '\0') {
        addend = (uint)(Entities)[entIdx].base.animFrame *
                 (uint)(Entities)[entIdx].base.level *
                 (uint)(Entities)[entIdx].base.level;
        oldLo = *sum;
        *sum = *sum + addend;
        hiPtr = (uint16_t *)sum + 1;
        *hiPtr = *hiPtr + ((int)addend >> 0xf) + (uint)CARRY2(oldLo,addend);
      }
      else {
        addend = (uint)(Entities)[entIdx].base.animFrame *
                 (uint)(Entities)[entIdx].base.level *
                 (uint)(Entities)[entIdx].base.level;
        oldLo = *enemySum;
        *enemySum = *enemySum + addend;
        hiPtr = (uint16_t *)enemySum + 1;
        *hiPtr = *hiPtr + ((int)addend >> 0xf) + (uint)CARRY2(oldLo,addend);
      }
    }
  }
  return;
}



/* 3f0b:28eb */

/* [R6] touches AgntCount */

void __cdecl16far attact_usesAgntCount2(uint16_t *sum,uint16_t *enemySum)

{
  /* Re-derived: accumulates the strength of every agent whose flags has none of 0xae4 set
     into two 32-bit sums, split by faction (faction 0 versus the rest). */
  uint16_t *hiPtr;
  uint oldLo;
  uint addend;
  int agntIdx;

  enemySum[1] = 0;
  *enemySum = 0;
  sum[1] = 0;
  *sum = 0;
  for (agntIdx = 0; agntIdx < (int)(uint)AgntCount; agntIdx = agntIdx + 1) {
    if ((Agnts[agntIdx].flags & 0xae4) == 0) {
      if (Agnts[agntIdx].faction == '\0') {
        addend = (uint)Agnts[agntIdx].strength;
        oldLo = *sum;
        *sum = *sum + addend;
        hiPtr = (uint16_t *)sum + 1;
        *hiPtr = *hiPtr + (uint)CARRY2(oldLo,addend);
      }
      else {
        addend = (uint)Agnts[agntIdx].strength;
        oldLo = *enemySum;
        *enemySum = *enemySum + addend;
        hiPtr = (uint16_t *)enemySum + 1;
        *hiPtr = *hiPtr + (uint)CARRY2(oldLo,addend);
      }
    }
  }
  return;
}



/* 3f0b:2997 */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far attact_usesBlitLoadRleGfx(void)

{
  int iVar1;
  uint uVar2;
  far_t gfx;
  
  mapViewActive = 1;
  uVar2 = GTimeLo;
  if (0xe < GTimeLo) {
    uVar2 = GTimeLo - 0xf;
  }
  if (0xe < uVar2) {
    uVar2 = 0xe;
  }
  iVar1 = (int)(((long)(int)uVar2 * 0xc & 0xffffU) / 0xf);
  gfx.seg = *(uint16_t *)((int)&timeOfDayGfx[0].seg + iVar1 * 4);
  gfx.ofs = ((far_t *)timeOfDayGfx + iVar1)->ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c510)),0);
  ovr_ovc13_blitAnimFrame();
  return;
}



/* 3f0b:2a09 */

/* [R4] calls LDIV_at_ */

void __cdecl16far attact_usesLDIV_at_2(void)

{
  undefined1 stk_ffe0;   /* stack slot ffe0 */
  far_t dst;
  far_t dst_00;
  bool bVar1;
  long *plVar2;
  long *plVar3;
  uint16_t uVar4;
  uint16_t unaff_SI;
  uint uVar5;
  uint16_t unaff_DI;
  int iVar6;
  long lVar7;
  long lVar8;
  far_t gfx;
  far_t gfx_00;
  uint32_t in_stack_0000ffde;
  uint uVar9;
  int iStack_1e;
  uint32_t sum;
  char miceIdle;
  uint8_t rect;
  uint8_t rect2;
  
  lVar8 = CONCAT22((uint16_t)((ulong)in_stack_0000ffde >> 0x10),unaff_SI);
  dst.seg = _SS;
  dst.ofs = (uint16_t)&rect2;
  F_SCOPY(far_from_u32((uint32_t)(0x2410088d)),dst,10);
  dst_00.seg = _SS;
  dst_00.ofs = (uint16_t)&rect;
  F_SCOPY(far_from_u32((uint32_t)(0x24100897)),dst_00,10);
  if (GameRunning == false) {
    miceIdle = MiceNeedsUpdate == '\0';
    bVar1 = ovr_draw_textArena();
    if (bVar1) {
      attact_usesEntityCount2
                ((uint16_t *)CONCAT22(_SS,&sum),(uint16_t *)CONCAT22(_SS,&stk_ffe0));
      if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) ||
         ((uint16_t)((ulong)lVar8 >> 0x10) == 0 && iStack_1e == 0)) {
        if (miceIdle != '\0') {
          ovr_miceRestoreArea((brect_t *)&rect,0);
        }
        attact_usesBlitLoadRleGfx();
        if (miceIdle != '\0') {
          ovr_miceBlitRect((brect_t *)&rect,0);
        }
      }
      else {
        if (mapViewActive != '\0') {
          if (miceIdle != '\0') {
            ovr_miceRestoreArea((brect_t *)&rect,0);
          }
          gfx.seg = nwpanel1Cut5Seg;
          gfx.ofs = nwpanel1Cut5Ofs;
          ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c510)),0x10);
          gfx_00.seg = panel01Cut3Seg;
          gfx_00.ofs = panel01Cut3Ofs;
          ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa000c51d)),0x1d);
          if (miceIdle != '\0') {
            ovr_miceBlitRect((brect_t *)&rect,0);
          }
        }
        if (miceIdle != '\0') {
          ovr_miceRestoreArea((brect_t *)&rect2,0);
        }
        mapViewActive = '\0';
        uVar5 = (uint)((ulong)lVar8 >> 0x10);
        if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) && (uVar5 != 0 || iStack_1e != 0)) {
          uVar5 = 0;
        }
        else if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) || (uVar5 != 0 || iStack_1e != 0)) {
          plVar3 = (long *)(uVar5 + (uint)sum);
          iVar6 = iStack_1e + (*(uint16_t *)((uint8_t *)&(sum) + 2)) + (uint)CARRY2(uVar5,(uint)sum);
          uVar4 = 0;
          plVar2 = LXMUL_at_(plVar3,CONCAT22(unaff_DI,iVar6),lVar8);
          lVar7 = LDIV_at_((long)CONCAT22(uVar4,plVar2),(long)CONCAT22(iVar6,plVar3));
          uVar5 = (int)lVar7 + 1;
        }
        else {
          uVar5 = 0x26;
        }
        if (AgntFlag1 != false) {
          attact_usesAgntCount2
                    ((uint16_t *)CONCAT22(_SS,&sum),(uint16_t *)CONCAT22(_SS,&stk_ffe0)
                    );
          uVar9 = (uint)((ulong)lVar8 >> 0x10);
          if (((uint)sum != 0 || (*(uint16_t *)((uint8_t *)&(sum) + 2)) != 0) || (uVar9 != 0 || iStack_1e != 0)) {
            if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) && (uVar9 != 0 || iStack_1e != 0)) {
              iVar6 = 0;
            }
            else if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) || (uVar9 != 0 || iStack_1e != 0)) {
              plVar3 = (long *)(uVar9 + (uint)sum);
              iVar6 = iStack_1e + (*(uint16_t *)((uint8_t *)&(sum) + 2)) + (uint)CARRY2(uVar9,(uint)sum);
              uVar4 = 0;
              plVar2 = LXMUL_at_(plVar3,CONCAT22(unaff_DI,iVar6),lVar8);
              lVar8 = LDIV_at_((long)CONCAT22(uVar4,plVar2),(long)CONCAT22(iVar6,plVar3));
              iVar6 = (int)lVar8 + 1;
            }
            else {
              iVar6 = 0x26;
            }
            uVar5 = uVar5 + iVar6 >> 1;
          }
        }
        if (0x9e < 0xc4 - uVar5) {
          ovr_driver_fillRect(0xdf,0x9f,0xe2,0xc4 - uVar5,0x24,0xa000,0x24,0,0,0,0);
        }
        if (uVar5 != 0) {
          ovr_driver_fillRect(0xdf,0xc5 - uVar5,0xe2,0xc4,0x7,0xa000,7,0,0,0,0);
        }
        if (miceIdle != '\0') {
          ovr_miceBlitRect((brect_t *)&rect2,0);
        }
      }
    }
    else {
      if (miceIdle != '\0') {
        ovr_miceRestoreArea((brect_t *)&rect,0);
      }
      attact_usesBlitLoadRleGfx();
      if (miceIdle != '\0') {
        ovr_miceBlitRect((brect_t *)&rect,0);
      }
    }
  }
  return;
}


