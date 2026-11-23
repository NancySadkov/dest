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
  uint uVar1;
  short *psVar2;
  byte bVar3;
  uint16_t uVar4;
  
  if (((((int)x < 0) || (y < 0)) || (in_AX = x + 1, 0x93 < (int)in_AX)) ||
     (in_AX = y + 1, 0x3b < (int)in_AX)) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar4 = (uint16_t)((ulong)GMapFlags >> 0x10);
    if (((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) == 0) {
      psVar2 = (*(short (*) [60] [148])GMapFlags)[y] + x;
      bVar3 = (byte)((uint)psVar2 >> 8);
      if ((psVar2[0x94] & 3U) == 0) {
        uVar1 = CONCAT11(bVar3,1);
      }
      else {
        uVar1 = (uint)bVar3 << 8;
      }
    }
    else {
      uVar1 = ((x & 0x7fff) >> 7) << 8;
    }
  }
  return uVar1;
}



/* 3f0b:007e */

/* [R6] touches GMapFlags */

uint __cdecl16far attact_usesGMapFlags2(int x,int y)

{
  uint in_AX;
  uint uVar1;
  short *psVar2;
  byte bVar3;
  
  if ((((x < 0) || (y < 0)) || (in_AX = x + 1, 0x93 < (int)in_AX)) ||
     (in_AX = y + 1, 0x3b < (int)in_AX)) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    psVar2 = (*(short (*) [60] [148])GMapFlags)[y] + x;
    bVar3 = (byte)((uint)psVar2 >> 8);
    if ((psVar2[0x94] & 3U) == 0) {
      uVar1 = CONCAT11(bVar3,1);
    }
    else {
      uVar1 = (uint)bVar3 << 8;
    }
  }
  return uVar1;
}



/* 3f0b:00d8 */

/* Returns whether the 2x2 block of GMapCells at (x,y) varies by less than 0x3c. */

uint __cdecl16far attact_isTerrainFlat(int x,int y)

{
  uint in_AX;
  uint uVar1;
  byte bVar2;
  byte (*paabVar3) [59] [148];
  int iVar4;
  int iVar5;
  uint16_t uVar6;
  uint8_t cornerHeights;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  if ((((x < 0) || (y < 0)) || (in_AX = x + 1, 0x93 < (int)in_AX)) ||
     (in_AX = y + 1, 0x3b < (int)in_AX)) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar6 = (uint16_t)((ulong)GMapCells >> 0x10);
    paabVar3 = (byte (*) [59] [148])GMapCells;
    cornerHeights = (int)(char)(*paabVar3)[y][x];
    iStack_8 = (int)(char)(*paabVar3)[y][x + 1];
    iStack_6 = (int)(char)(*paabVar3)[y + 1][x];
    iStack_4 = (int)(char)(*paabVar3)[y + 1][x + 1];
    iVar5 = cornerHeights;
    for (iVar4 = 1; iVar4 < 4; iVar4 = iVar4 + 1) {
      if (*(int *)(&cornerHeights + iVar4 * 2) < iVar5) {
        iVar5 = *(int *)(&cornerHeights + iVar4 * 2);
      }
      if (cornerHeights < *(int *)(&cornerHeights + iVar4 * 2)) {
        cornerHeights = *(int *)(&cornerHeights + iVar4 * 2);
      }
    }
    bVar2 = (byte)((uint)(cornerHeights - iVar5) >> 8);
    if (cornerHeights - iVar5 < 0x3c) {
      uVar1 = CONCAT11(bVar2,1);
    }
    else {
      uVar1 = (uint)bVar2 << 8;
    }
  }
  return uVar1;
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
    else if ((*(byte *)((uint)((unit_t *)GUnits + (*(short (*) [148] [60])GUnitGrid)[x][y])->bldType
                        * 0x27 + 0x11e) & 3) == 3) {
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
  int iVar1;
  uint uVar2;
  uint16_t uVar3;
  
  iVar1 = (int)*(char *)(dir + 0x885);
  if ((((x + iVar1 < 2) || (iVar1 = (int)*(char *)(dir + 0x889), SCARRY2(y,iVar1) != y + iVar1 < 0))
      || (iVar1 = (int)*(char *)(dir + 0x885), 0x91 < x + iVar1)) ||
     (iVar1 = (int)*(char *)(dir + 0x889), 0x39 < y + iVar1)) {
    uVar2 = CONCAT11((char)((uint)iVar1 >> 8),1);
  }
  else {
    uVar3 = (uint16_t)((ulong)GMapFlags >> 0x10);
    uVar2 = (uint)(*(short (*) [60] [148])GMapFlags)[y][x] >> (dir + 4 & 0x1f);
    if (((uVar2 & 1) == 0) || (ignoreBlocked != '\0')) {
      uVar2 = (uint)((byte)uVar2 & 1);
    }
    else {
      uVar2 = (uint)(*(short (*) [60] [148])GMapFlags)[y][x] >> (dir + 8 & 0x1f) & 0xff01 ^ 1;
    }
  }
  return uVar2;
}



/* 3f0b:0362 */

/* [R6] touches SCARRY2, GMapFlags */

uint __cdecl16far attact_usesSCARRY22(int x,int y,byte dir,char ignoreBlocked,char directionOnly)

{
  int iVar1;
  uint uVar2;
  uint16_t uVar3;
  
  iVar1 = (int)*(char *)(dir + 0x885);
  if (((1 < x + iVar1) && (iVar1 = (int)*(char *)(dir + 0x889), SCARRY2(y,iVar1) == y + iVar1 < 0))
     && (iVar1 = (int)*(char *)(dir + 0x885), x + iVar1 < 0x92)) {
    iVar1 = (int)*(char *)(dir + 0x889);
    if (y + iVar1 < 0x3a) {
      if (directionOnly != '\0') {
        return (uint)(byte)(*(char *)(dir + 0x889) >> 7) << 8;
      }
      uVar3 = (uint16_t)((ulong)GMapFlags >> 0x10);
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
  int iVar1;
  uint uVar2;
  int iVar3;
  uint16_t uVar4;
  
  iVar3 = 0;
  if (((uint8_t *)MenuItemEnabled)[menuIndex] == 0xff) {
    iVar3 = 0;
  }
  else {
    for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
      uVar4 = (uint16_t)((ulong)Entities >> 0x10);
      iVar1 = (int)Entities;
      if (((AGNT_FIELD(&((entity_t *)Entities)[uVar2], base.entity, 3) == ((uint8_t *)MenuItemEnabled)[menuIndex]) &&
          (((*(uint *)((entity_t *)iVar1 + uVar2) < GfxRndSeed - 2U ||
            (GfxRndSeed + 1U < *(uint *)((entity_t *)iVar1 + uVar2))) ||
           (((entity_t *)iVar1)[uVar2].base.y != GfxRndSeed2)))) &&
         ((AGNT_FIELD(&((entity_t *)Entities)[uVar2], base.flags32, 1) & 2) == 0)) {
        iVar3 = iVar3 + 1;
      }
    }
    if (0x50 < iVar3) {
      iVar3 = 0x50;
    }
  }
  return iVar3;
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
      memcpy((char *)0x24109074,(char *)&SquareRecX,0x13);
      SquareRecIndex = SquareRecCount;
      return;
    }
    if ((*(int *)(uVar1 * 0x13) == GfxRndSeed) && (*(int *)((uint8_t *)&SquareRecs[uVar1] + 2) == GfxRndSeed2))
    break;
    uVar1 = uVar1 + 1;
  }
  memcpy((char *)0x24109074,(char *)CONCAT22(0x17f8,(char *)(uVar1 * 0x13)),0x13);
  SquareRecIndex = uVar1;
  return;
}



/* 3f0b:0685 */

/* [R6] touches AgntFlag1, AgntCount */

void __cdecl16far attact_usesAgntFlag1(void)

{
  uint32_t uVar1;
  uint32_t uVar2;
  bool bVar3;
  int16_t iVar4;
  int iVar5;
  
  if (AgntFlag1) {
    bVar3 = ovr_ovc15_usesAlignUp42();
    if (bVar3) {
      for (iVar5 = 0; iVar5 < (int)(uint)AgntCount; iVar5 = iVar5 + 1) {
        uVar1 = *(uint32_t far *)&Agnts[iVar5].entity;
        *(undefined1 *)((int)uVar1 + 0x31) = Agnts[iVar5].strength;
      }
    }
    else {
      for (iVar5 = 0; iVar5 < (int)(uint)AgntCount; iVar5 = iVar5 + 1) {
        uVar1 = *(uint32_t far *)&Agnts[iVar5].entity;
        uVar2 = *(uint32_t far *)&Agnts[iVar5].entity;
        *(undefined1 *)((int)uVar2 + 0x31) = *(undefined1 *)((int)uVar1 + 0x32);
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
    iVar4 = memcmp((char *)&SquareRecX,(char *)0x24109074,0x13);
    if (iVar4 == 0) {
      sub_OVC04_0001(0x1000,0x9074,0x2410);
      return;
    }
  }
  else {
    iVar4 = memcmp((char *)&SquareRecX,(char *)0x24109074,0x13);
    if (iVar4 == 0) {
      sub_OVC04_0001(0x1000,0x9074,0x2410);
      return;
    }
    if (299 < SquareRecCount) {
      _fmemmove((char *)SquareRecs,(char *)(SquareRecs + 1),0x1631);
      SquareRecCount = 299;
    }
  }
  memcpy((char *)CONCAT22(0x17f8,(char *)(SquareRecCount * 0x13)),(char *)0x24109074,0x13);
  iVar5 = SquareRecCount * 0x13;
  SquareRecCount = SquareRecCount + 1;
  sub_OVC04_0001(0x1000,iVar5,0x17f8);
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

void __cdecl16far attact_decrementCounter(char *counter)

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
  uint uVar1;
  int iVar2;
  byte bVar3;
  undefined1 uStack_3;
  
  uStack_3 = 0;
  for (bVar3 = 0; bVar3 < AgntCount; bVar3 = bVar3 + 1) {
    if (((Agnts[bVar3].owner == ownerIndex) &&
        (Agnts[bVar3].moveState != '\x02')) &&
       ((Agnts[bVar3].flags & 0xae4) == 0)) {
      uStack_3 = uStack_3 + 1;
    }
  }
  uVar1 = (((entity_t *)Entities)[ownerIndex].base.animFrame + 0xf) / 0x10;
  if (uVar1 < uStack_3) {
    iVar2 = 0;
  }
  else {
    iVar2 = uVar1 - uStack_3;
  }
  return iVar2;
}



/* 3f0b:0941 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

void __cdecl16far attact_usesAlignUp4(uint16_t x,uint16_t y,char partyIndex,uint32_t flags,uint16_t arg5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint16_t uVar5;
  uint uStack_8;
  byte bStack_3;
  
  if (partyIndex != -1) {
    uVar1 = ovr_alignUp4(x,0,0);
    for (bStack_3 = 0; bStack_3 < 5; bStack_3 = bStack_3 + 1) {
      if (((uint8_t *)MenuItemEnabled)[bStack_3] == partyIndex) {
        uVar3 = 0;
        while ((uVar3 < SquareRecCount &&
               ((uVar4 = ovr_alignUp4(*(int *)(uVar3 * 0x13),0,0), uVar4 != uVar1 ||
                (*(uint16_t *)((uint8_t *)&SquareRecs[uVar3] + 2) != y))))) {
          uVar3 = uVar3 + 1;
        }
        if (SquareRecCount <= uVar3) {
          return;
        }
        uStack_8 = 0;
        for (uVar4 = 0; uVar4 < EntityCount; uVar4 = uVar4 + 1) {
          uVar2 = ovr_alignUp4(((entity_t *)Entities)[uVar4].base.destX,0,0);
          if (uVar2 == uVar1) {
            uVar5 = (uint16_t)((ulong)Entities >> 0x10);
            if ((((entity_t *)Entities)[uVar4].base.destY == y) &&
               (*(char *)((int)&((entity_t *)Entities)[uVar4].base.entity + 3) == partyIndex)) {
              uStack_8 = uStack_8 + 1;
            }
          }
        }
        if (*(byte *)(uVar3 * 0x13 + (uint)bStack_3 + 0xe) != uStack_8) {
          *(undefined1 *)(uVar3 * 0x13 + (uint)bStack_3 + 0xe) = (undefined1)uStack_8;
          uVar3 = ovr_alignUp4(GfxRndSeed,0,0);
          if ((uVar3 == uVar1) && (GfxRndSeed2 == y)) {
            if (flags == 0) {
              ovr_ovc41_usesMiceBlitRect((uint)bStack_3);
            }
            else {
              *(undefined1 *)((int)flags + (uint)bStack_3) = 1;
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
  uint16_t uVar2;
  
  ((entity_t *)Entities)[entityIndex].base.faction = 0;
  ((entity_t *)Entities)[entityIndex].base.state = 0;
  uVar2 = (uint16_t)((ulong)Entities >> 0x10);
  iVar1 = (int)Entities;
  x = ((entity_t *)iVar1)[entityIndex].base.destX;
  y = ((entity_t *)iVar1)[entityIndex].base.destY;
  if ((*(uint16_t *)((entity_t *)iVar1 + entityIndex) == destX) &&
     (((entity_t *)iVar1)[entityIndex].base.y == destY)) {
    destX = 0;
    destY = 0;
  }
  ((entity_t *)iVar1)[entityIndex].base.destX = destX;
  ((entity_t *)Entities)[entityIndex].base.destY = destY;
  if ((x != 0) || (y != 0)) {
    attact_usesAlignUp4(x,y,*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3),CONCAT22(flagsSeg,flagsOfs),0);
  }
  if ((destX != 0) || (destY != 0)) {
    attact_usesAlignUp4(destX,destY,*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3),CONCAT22(flagsSeg,flagsOfs),0);
  }
  return;
}



/* 3f0b:0c2a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches GMapFlags, EntityCount */

void __stdcall16far attact_usesGMapFlags3(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint16_t uVar4;
  
  ovr_driver_clearMapFlagsRect((uint32_t)GMapFlags,0,0,0x93,0x3b,0xcfff,0,0);
  for (uVar3 = 0; uVar3 < EntityCount; uVar3 = uVar3 + 1) {
    uVar4 = (uint16_t)((ulong)Entities >> 0x10);
    iVar2 = (int)Entities;
    puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[((entity_t *)iVar2)[uVar3].base.y] +
                     *(int *)((entity_t *)iVar2 + uVar3));
    *puVar1 = *puVar1 | 0x1000 << (*(byte *)((int)(char **)GMenuStrings +
                                            (uint)((entity_t *)iVar2)[uVar3].base.gindex * 0x95 +
                                            0x1f) & 0x1f);
  }
  ovr_ovc15_usesAlignUp42();
  draw_textGoldProvidesHousing();
  return;
}



/* 3f0b:1082 */
void __cdecl16far attact_usesAlignUp42(void)

{
  uint16_t *puVar1;
  uint8_t *puVar2;
  uint32_t uVar3;
  uint16_t uVar4;
  char cVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  uint uVar9;
  undefined1 uVar13;
  uint16_t uVar10;
  uint uVar11;
  char *pcVar12;
  entity_t *peVar14;
  uint16_t unaff_DI;
  uint16_t index;
  uint16_t uVar15;
  entity_t *destEnt;   /* hand fix: dereferenced as destEnt->base */
  char rowsLeft;
  uint8_t reported;
  int targetSrc;
  int dySign;
  uint16_t uStack_c;   /* [BP-0xc], cleared by _fmemset at 3f0b:1092 */
  int dxSign;
  undefined1 animByte;
  uint8_t reportedUnits;
  uint16_t startY;
  uint16_t startX;
  byte defByte;
  undefined1 flag4000;
  
  func_0x0004f735(0x3f0b);
  reported = 0x0;
  _fmemset(MK_FP(_SS, &uStack_c), 0, 5);
  GGameState = 0x3f;
  if (DebugVerbose != false) {
    printf("%d %d %d \r");
  }
  uVar15 = 0x1000;
  debugStaleTickCount = 0;
  debugEmptyCellCount = 0;
  index = 0;
  do {
    uVar4 = DAT_2000_d190;
    if (EntityCount <= index) {
      GGameState = 0x3c;
      if (DebugVerbose != false) {
        uVar15 = 0x1000;
        printf("%d %d %d  \r");
      }
      func_0x0004fcda(uVar15);
      GGameState = 0x3d;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r");
      }
      ovr_OVC23_55fe_29a2_entry();
      GGameState = 0xc;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r");
      }
      uVar15 = 0x2379;
      ovr_ovc24_removeOtherEntities(&reported);
      GGameState = 0x1f;
      if (reported != 0x0) {
        uVar15 = 0x22ef;
        ovr_constr_usesBlitRect();
        GGameState = 0x13;
      }
      func_0x0004f68f(uVar15);
      GGameState = 0x1d;
      for (uVar8 = 0; (int)uVar8 < 5; uVar8 = uVar8 + 1) {
        if ((&reportedUnits)[uVar8] != 0x0) {
          ovr_ovc41_usesMiceBlitRect(uVar8);
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
    uVar8 = ovr_alignUp4((peVar14->base).destX,0,0);
    uVar15 = 0x2379;
    uVar9 = ovr_alignUp4((destEnt->base).x,0,0);
    if ((uVar8 == uVar9) && ((peVar14->base).destY == (peVar14->base).y)) {
      manage_usesCurSfxType32(0x2379,index,(peVar14->base).destX,(peVar14->base).destY);
    }
    if (((peVar14->base).destX != 0 || (peVar14->base).destY != 0) &&
       (*(char *)((int)&(peVar14->base).entity + 1) == '\0')) {
      flag4000 = (*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)(peVar14->base).gindex * 0x95)
                 & 0x4000) != 0;
      startX = (destEnt->base).x;
      startY = (peVar14->base).y;
      animByte = *(undefined1 *)
                  ((int)(char **)GMenuStrings + (uint)(peVar14->base).gindex * 0x95 + 0x1f);
      if ((peVar14->base).faction < (byte)(peVar14->base).state) {
        uVar8 = (int)(uint)*(byte *)((int)&(peVar14->base).owner +
                                    ((int)(uint)(peVar14->base).faction >> 2)) >>
                (((peVar14->base).faction & 3) << 1) & 0xff03;
        (peVar14->base).target = (uint8_t)uVar8;
        uVar13 = (undefined1)(uVar8 >> 8);
        cVar5 = func_0x0004f32d(0x2379,(destEnt->base).x,(peVar14->base).y,
                                CONCAT11(uVar13,(peVar14->base).target),CONCAT11(uVar13,animByte));
        if (cVar5 == '\0') {
          (destEnt->base).x = (destEnt->base).x + (int)*(char *)((peVar14->base).target + 0x885)
          ;
          puVar1 = &(peVar14->base).y;
          *puVar1 = *puVar1 + (int)*(char *)((peVar14->base).target + 0x889);
          puVar2 = &(peVar14->base).faction;
          *puVar2 = *puVar2 + 0x1;
        }
        else {
          (peVar14->base).faction = 0x0;
          *(undefined1 *)&(peVar14->base).state = 0;
        }
      }
      else {
        dxSign = ovr_ovc07_signum((peVar14->base).destX - (destEnt->base).x);
        uVar15 = 0x22da;
        dySign = ovr_ovc07_signum((peVar14->base).destY - (peVar14->base).y);
        if (dxSign != 0) {
          uVar15 = 0x2337;
          uVar10 = ovr_randBelow(2,0);
          if ((char)uVar10 != '\0') {
            cVar5 = sub_OVC21_manage_c_23C2(0x2337,startX,startY,'\x02' - (char)dxSign,animByte,
                                    flag4000);
            if (cVar5 == '\0') {
              (destEnt->base).x = (destEnt->base).x + dxSign;
              (peVar14->base).target = 0x2 - (char)dxSign;
              goto L_attact_3f0b_1082_1477;
            }
          }
        }
        if (dySign != 0) {
          cVar5 = sub_OVC21_manage_c_23C2(uVar15,startX,startY,(char)dySign + '\x01',animByte,
                                  flag4000);
          if (cVar5 == '\0') {
            puVar1 = &(peVar14->base).y;
            *puVar1 = *puVar1 + dySign;
            (peVar14->base).target = (char)dySign + 0x1;
            goto L_attact_3f0b_1082_1477;
          }
        }
        if (dxSign != 0) {
          cVar5 = sub_OVC21_manage_c_23C2(uVar15,startX,startY,'\x02' - (char)dxSign,animByte,
                                  flag4000);
          if (cVar5 == '\0') {
            (destEnt->base).x = (destEnt->base).x + dxSign;
            (peVar14->base).target = 0x2 - (char)dxSign;
            goto L_attact_3f0b_1082_1477;
          }
        }
        uVar8 = ovr_ovc26_usesStExit(index);
        if ((char)uVar8 == '\0') {
          uVar8 = ovr_ovc26_usesRandBelow
                            (index,(uint16_t)&reported,_SS,(uint16_t)&reportedUnits,_SS);
          if (((uVar8 & 0xff) == 0) &&
             (*(char *)((int)(char **)GMenuStrings + (uint)(peVar14->base).gindex * 0x95 + 0x1f) ==
              '\0')) {
            manage_usesCurSfxType32(0x2386,index,(peVar14->base).targetX,(peVar14->base).targetY);
          }
        }
        else {
          uVar8 = (int)(uint)*(byte *)((int)&(peVar14->base).owner +
                                      ((int)(uint)(peVar14->base).faction >> 2)) >>
                  (((peVar14->base).faction & 3) << 1) & 0xff03;
          (peVar14->base).target = (uint8_t)uVar8;
          uVar13 = (undefined1)(uVar8 >> 8);
          cVar5 = func_0x0004f32d(0x2386,startX,startY,CONCAT11(uVar13,(peVar14->base).target),
                                  CONCAT11(uVar13,animByte));
          if (cVar5 == '\0') {
            (destEnt->base).x =
                 (destEnt->base).x + (int)*(char *)((peVar14->base).target + 0x885);
            puVar1 = &(peVar14->base).y;
            *puVar1 = *puVar1 + (int)*(char *)((peVar14->base).target + 0x889);
            puVar2 = &(peVar14->base).faction;
            *puVar2 = *puVar2 + 0x1;
          }
        }
      }
L_attact_3f0b_1082_1477:
      reported = 0x1;
      uVar8 = ovr_alignUp4((peVar14->base).destX,0,0);
      uVar9 = ovr_alignUp4((destEnt->base).x,0,0);
      if ((uVar8 == uVar9) && ((peVar14->base).destY == (peVar14->base).y)) {
        (peVar14->base).destX = 0;
        (peVar14->base).destY = 0;
        if (*(char *)((int)&(peVar14->base).entity + 3) == -1) {
          defByte = 0xff;
        }
        else {
          uVar3 = *(uint32_t *)((uint)*(byte *)((int)&(peVar14->base).entity + 3) << 2);
          defByte = *(byte *)((int)uVar3 + 0x89);
        }
        if (defByte != 0xff) {
          for (uVar8 = 0; uVar8 < SquareRecCount; uVar8 = uVar8 + 1) {
            uVar9 = ovr_alignUp4(*(int *)(uVar8 * 0x13),0,0);
            uVar11 = ovr_alignUp4((destEnt->base).x,0,0);
            if ((uVar9 == uVar11) && (*(uint16_t *)((uint8_t *)&SquareRecs[uVar8] + 2) == (peVar14->base).y)) {
              func_0x0004f930(0x2379,uVar8 * 0x13 + (uint)defByte + 0xe,0x17f8);
              if (*(uint16_t *)((uint8_t *)&SquareRecs[uVar8] + 2) == GfxRndSeed2) {
                uVar8 = ovr_alignUp4(*(int *)(uVar8 * 0x13),0,0);
                uVar9 = ovr_alignUp4(GfxRndSeed,0,0);
                if (uVar8 == uVar9) {
                  (&reportedUnits)[defByte] = 0x1;
                }
              }
              break;
            }
          }
        }
      }
      uVar15 = 0x2379;
      if (AgntFlag1 != false) {
        if ((((destEnt->base).x < GfxRndSeed - 2U) || (GfxRndSeed + 1U < (destEnt->base).x)) ||
           ((peVar14->base).y != GfxRndSeed2)) {
          bVar6 = false;
        }
        else {
          bVar6 = true;
        }
        if (((startX < GfxRndSeed - 2U) || (GfxRndSeed + 1U < startX)) ||
           (GfxRndSeed2 != startY)) {
          bVar7 = false;
        }
        else {
          bVar7 = true;
        }
        if (bVar7 || bVar6) {
          if (bVar7) {
            if (bVar6) {
              for (rowsLeft = manage_usesLitoa103(); rowsLeft != '\0'; rowsLeft = rowsLeft + -1) {
                if (((peVar14->base).target & 1) == 0) {
                  targetSrc = 0;
                }
                else {
                  targetSrc = (peVar14->base).target - 2;
                }
                uVar15 = 0x2322;
                pcVar12 = ovr_ovc15_textArena(index,0,0);
                if (((uint)pcVar12 & 0xff) == 0) break;
              }
            }
            else {
              rowsLeft = (char)((ulong)((peVar14->base).animFrame + 0xf) / 0x10);
              while (rowsLeft != '\0') {
                uVar15 = 0x22ff;
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
              uVar15 = 0x2322;
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
  int iVar1;
  uint uVar2;
  uint16_t uVar3;
  char *txt;
  uint16_t uVar4;
  uint16_t dst;
  uint8_t msg;
  uint uStack_6;
  byte bStack_4;
  byte bStack_3;
  
  if ((itemIndex < 5) &&
     ((uStack_6 = (uint)((uint8_t *)menuItemRow)[itemIndex], force != 0 ||
      (PrevMenuValue != uStack_6)))) {
    PrevMenuValue = uStack_6;
    ovr_resetTextBlitCycle();
    bStack_4 = ((uint8_t *)MenuItemEnabled)[itemIndex];
    if (bStack_4 != 0xff) {
      iVar1 = ovr_ovc23_findClearColumn(GfxRndSeed,GfxRndSeed2);
      if (iVar1 < 0) {
        ovr_drawTextAt((char *)"You cannot attract units to this location.",0x2410,0xa000);
        ((uint8_t *)menuItemRow)[itemIndex] = 0x0;
      }
      else {
        uVar2 = sub_OVC21_manage_c_24B1(0x236f,itemIndex & 0xff);
        callResultTemp = uVar2;
        if (uVar2 < uStack_6) {
          (*(uint8_t *)((uint8_t *)&(uStack_6))) = (uint8_t)uVar2;
          ((uint8_t *)menuItemRow)[itemIndex] = (uint8_t)uStack_6;
          uStack_6 = uVar2;
        }
        uVar4 = 0x217a;
        bStack_3 = *(byte *)((int)*(uint32_t *)((uint)bStack_4 << 2) + 0x2f);
        if (bStack_3 != 0xff) {
          uVar3 = ovr_ovc41_pluralSuffix(uStack_6,0xa000);
          dst = 0x2410;
          txt = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x921,_SS),
                              (char *)CONCAT22(uStack_6,(char *)0x26510),callResultTemp,
                              *(uint16_t *)((uint)bStack_3 * 4 + 0x13f),
                              *(uint16_t *)((uint)bStack_3 * 4 + 0x141),uVar3,uVar4);
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
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint16_t uVar8;
  uint uStack_4;
  
  uStack_4 = 0xffff;
  uVar1 = ovr_alignUp4(x,0,0);
  for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    if (*(char *)((int)&((entity_t *)Entities)[uVar7].base.entity + 3) == partyIndex) {
      uVar2 = ovr_alignUp4(((entity_t *)Entities)[uVar7].base.x,0,0);
      uVar4 = (int)(uVar2 - uVar1) >> 0xf;
      uVar8 = (uint16_t)((ulong)Entities >> 0x10);
      uVar3 = ((entity_t *)Entities)[uVar7].base.y - y;
      uVar5 = (int)uVar3 >> 0xf;
      uVar2 = ((uVar2 - uVar1 ^ uVar4) - uVar4) + ((uVar3 ^ uVar5) - uVar5) * 2;
      if ((uVar2 != 0) && (uVar2 < uStack_4)) {
        uVar3 = ovr_alignUp4(((entity_t *)Entities)[uVar7].base.destX,0,0);
        iVar6 = (int)Entities;
        uVar8 = (uint16_t)((ulong)Entities >> 0x10);
        if (((uVar3 != uVar1) || (((entity_t *)iVar6)[uVar7].base.destY != y)) &&
           ((((mode == 0 && ((AGNT_FIELD(&((entity_t *)Entities)[uVar7], base.flags32, 1) & 2) == 0)) ||
             ((mode == 1 &&
              (((((entity_t *)iVar6)[uVar7].base.destX == 0 &&
                (((entity_t *)iVar6)[uVar7].base.destY == 0)) &&
               ((AGNT_FIELD(&((entity_t *)Entities)[uVar7], base.flags32, 1) & 2) == 0)))))) ||
            (((mode == 2 && ((AGNT_FIELD(&((entity_t *)Entities)[uVar7], base.flags32, 1) & 1) != 0)) ||
             ((mode == 3 && ((AGNT_FIELD(&((entity_t *)Entities)[uVar7], base.flags32, 1) & 4) != 0)))))))) {
          *foundIndexOut = uVar7;
          uStack_4 = uVar2;
        }
      }
    }
  }
  return uStack_4 != 0xffff;
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
    if (*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3) == (char)partyIndex) {
      dist = ovr_alignUp4(((entity_t *)Entities)[entityIndex].base.x,0,0);
      signMaskX = (int)(dist - targetX) >> 0xf;
      uVar3 = ((entity_t *)Entities)[entityIndex].base.y - targetY;
      signMaskY = (int)uVar3 >> 0xf;
      dist = ((dist - targetX ^ signMaskX) - signMaskX) + ((uVar3 ^ signMaskY) - signMaskY) * 2;
      if (((bestDist < dist) &&
          (uVar3 = ovr_alignUp4(((entity_t *)Entities)[entityIndex].base.destX,0,0), uVar3 == targetX)) &&
         (((entity_t *)Entities)[entityIndex].base.destY == targetY)) {
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

bool __cdecl16far attact_textArena3(uint *foundIndexOut,uint16_t partyIndex,int x)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint16_t uVar7;
  int in_stack_0000000c;
  uint uStack_4;
  
  uStack_4 = 0;
  uVar1 = ovr_alignUp4(x,0,0);
  for (uVar6 = 0; uVar6 < EntityCount; uVar6 = uVar6 + 1) {
    uVar7 = (uint16_t)((ulong)Entities >> 0x10);
    if (*(char *)((int)&((entity_t *)Entities)[uVar6].base.entity + 3) == (char)partyIndex) {
      uVar2 = ovr_alignUp4(((entity_t *)Entities)[uVar6].base.x,0,0);
      uVar4 = (int)(uVar2 - uVar1) >> 0xf;
      uVar3 = ((entity_t *)Entities)[uVar6].base.y - in_stack_0000000c;
      uVar5 = (int)uVar3 >> 0xf;
      uVar2 = ((uVar2 - uVar1 ^ uVar4) - uVar4) + ((uVar3 ^ uVar5) - uVar5) * 2;
      if (uStack_4 < uVar2) {
        *foundIndexOut = uVar6;
        uStack_4 = uVar2;
      }
    }
  }
  return uStack_4 != 0;
}



/* 3f0b:1db1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

void __cdecl16far attact_usesAlignUp43(uint16_t *value)

{
  byte *pbVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint16_t *puVar6;
  uint uVar7;
  uint uVar8;
  uint16_t uVar9;
  uint16_t uVar10;
  uint16_t uStack_8;
  uint16_t ent;
  byte bStack_3;
  
  uVar4 = ovr_alignUp4(*value,0,0);
  uStack_8 = *value;
  uVar9 = (uint16_t)((ulong)value >> 0x10);
  puVar6 = (uint16_t *)value;
  cVar2 = func_0x0004f29c(0x2379,uStack_8,puVar6[1]);
  if (cVar2 == '\0') {
    ent = 0xfffe;
    while (((int)ent < 2 &&
           (cVar2 = func_0x0004f29c(0x2379,uStack_8 + ent,puVar6[1]), cVar2 == '\0'))) {
      ent = ent + 1;
    }
    if ((int)ent < 2) {
      uStack_8 = uStack_8 + ent;
    }
  }
  for (uVar8 = 0; (int)uVar8 < 5; uVar8 = uVar8 + 1) {
    uVar7 = 0;
    for (ent = 0; ent < EntityCount; ent = ent + 1) {
      uVar10 = (uint16_t)((ulong)Entities >> 0x10);
      bStack_3 = AGNT_FIELD(&((entity_t *)Entities)[ent], base.entity, 3);
      if ((((bStack_3 != 0xff) &&
           (((char_sheet_t *)(((uint)bStack_3 << 2)))->partySlot == uVar8)) &&
          (uVar5 = ovr_alignUp4(((entity_t *)Entities)[ent].base.destX,0,0), uVar5 == uVar4)) &&
         (((entity_t *)Entities)[ent].base.destY == puVar6[1])) {
        uVar7 = uVar7 + 1;
      }
    }
    bStack_3 = ((uint8_t *)MenuItemEnabled)[uVar8];
    if (*(byte *)((int)puVar6 + uVar8 + 0xe) != uVar7) {
      while (((int)uVar7 < (int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) &&
             (bVar3 = attact_textArena((uint16_t *)CONCAT22(_SS,&ent),3,bStack_3,*value,
                                       puVar6[1]), bVar3))) {
        ((entity_t *)Entities)[ent].base.state = 0;
        ((entity_t *)Entities)[ent].base.destX = uStack_8;
        ((entity_t *)Entities)[ent].base.destY = puVar6[1];
        pbVar1 = (byte *)((uint8_t *)&((entity_t *)Entities)[ent] + 0x33);
        *pbVar1 = *pbVar1 & 0xfb;
        uVar7 = uVar7 + 1;
      }
      while (((int)uVar7 < (int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) &&
             (bVar3 = attact_textArena((uint16_t *)CONCAT22(_SS,&ent),2,bStack_3,*value,
                                       puVar6[1]), bVar3))) {
        ((entity_t *)Entities)[ent].base.state = 0;
        ((entity_t *)Entities)[ent].base.destX = uStack_8;
        ((entity_t *)Entities)[ent].base.destY = puVar6[1];
        uVar7 = uVar7 + 1;
      }
      while (((int)uVar7 < (int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) &&
             (bVar3 = attact_textArena((uint16_t *)CONCAT22(_SS,&ent),1,bStack_3,*value,
                                       puVar6[1]), bVar3))) {
        ((entity_t *)Entities)[ent].base.state = 0;
        ((entity_t *)Entities)[ent].base.destX = uStack_8;
        ((entity_t *)Entities)[ent].base.destY = puVar6[1];
        uVar7 = uVar7 + 1;
      }
      while (((int)uVar7 < (int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) &&
             (bVar3 = attact_textArena((uint16_t *)CONCAT22(_SS,&ent),0,bStack_3,*value,
                                       puVar6[1]), bVar3))) {
        ((entity_t *)Entities)[ent].base.state = 0;
        ((entity_t *)Entities)[ent].base.destX = uStack_8;
        ((entity_t *)Entities)[ent].base.destY = puVar6[1];
        uVar7 = uVar7 + 1;
      }
      while (((int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) < (int)uVar7 &&
             (bVar3 = attact_textArena2((uint *)CONCAT22(_SS,&ent),(uint)bStack_3,*value),
             bVar3))) {
        ((entity_t *)Entities)[ent].base.state = 0;
        uVar10 = (uint16_t)((ulong)Entities >> 0x10);
        ((entity_t *)Entities)[ent].base.destX =
             ((entity_t *)Entities)[ent].base.targetX;
        uVar10 = (uint16_t)((ulong)Entities >> 0x10);
        ((entity_t *)Entities)[ent].base.destY =
             ((entity_t *)Entities)[ent].base.targetY;
        uVar7 = uVar7 - 1;
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
        return CONCAT11((char)((uint)uVar2 >> 8),1);
      }
      value = value + *(char *)(dir + 0x885);
      uVar3 = ovr_alignUp4(*xPtr,0,0);
      uVar2 = 0x2379;
      uVar1 = ovr_alignUp4(value,0,0);
    } while (uVar3 == uVar1);
    *xPtr = value;
    uVar1 = uVar1 & 0xff00;
  }
  return uVar1;
}



/* 3f0b:2430 */
void __cdecl16far attact_usesRandBelow(agnt_t *agnt,byte dir,uint16_t arg3,uint16_t arg4)

{
  uint16_t uVar1;
  uint uVar2;
  int iVar3;
  uint16_t uVar4;
  undefined1 uStack0007;
  byte in_stack_00000008;
  uint16_t agntX;   /* hand fix: [BP-6] is a WORD copy of agnt->x (3f0b:246f) */
  uint16_t uStack_6;
  int iStack_4;
  
  agnt = (int *)CONCAT13(uStack0007,CONCAT12(dir,agnt));
  uVar4 = (uint16_t)((ulong)agnt >> 0x10);
  if (in_stack_00000008 == 0xff) {
    uVar1 = ovr_randBelow(4,*(undefined1 *)
                             ((int)(char **)GMenuStrings + (uint)agnt->gindex * 0x95 + 0x1f));
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
  int iVar1;
  char *pcVar2;
  uint owner;
  uint16_t uVar3;
  undefined1 uStack_3;
  
  owner = 0;
  do {
    if (EntityCount <= owner) {
      return;
    }
    uVar3 = (uint16_t)((ulong)Entities >> 0x10);
    uVar3 = ovr_ovc23_isCursorAt
                      (((entity_t *)Entities)[owner].base.x,((entity_t *)Entities)[owner].base.y,0);
    if ((char)uVar3 != '\0') {
      for (iVar1 = manage_usesLitoa103(0x236f,owner); iVar1 != 0; iVar1 = iVar1 + -1) {
        uVar3 = (uint16_t)((ulong)Entities >> 0x10);
        if ((((entity_t *)Entities)[owner].base.target & 1) == 0) {
          uStack_3 = 0;
        }
        else {
          uStack_3 = ((entity_t *)Entities)[owner].base.target - 2;
        }
        pcVar2 = ovr_ovc15_textArena(owner,(uint)uStack_3,0);
        if (((uint)pcVar2 & 0xff) == 0) break;
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
  uint16_t *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint16_t uVar6;
  uint16_t uVar7;
  uint16_t uVar8;
  
  uVar6 = (uint16_t)((ulong)enemySum >> 0x10);
  ((uint16_t *)enemySum)[1] = 0;
  *enemySum = 0;
  uVar7 = (uint16_t)((ulong)sum >> 0x10);
  ((uint16_t *)sum)[1] = 0;
  *sum = 0;
  for (uVar5 = 0; uVar5 < EntityCount; uVar5 = uVar5 + 1) {
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    uVar8 = ovr_ovc23_isCursorAt
                      (((entity_t *)Entities)[uVar5].base.x,((entity_t *)Entities)[uVar5].base.y,0);
    if ((char)uVar8 != '\0') {
      uVar8 = (uint16_t)((ulong)Entities >> 0x10);
      iVar4 = (int)Entities;
      if (*(char *)((int)(char **)GMenuStrings +
                   (uint)((entity_t *)iVar4)[uVar5].base.gindex * 0x95 + 0x1f) == '\0') {
        uVar3 = (uint)((entity_t *)iVar4)[uVar5].base.animFrame *
                (uint)((entity_t *)iVar4)[uVar5].base.level *
                (uint)((entity_t *)iVar4)[uVar5].base.level;
        uVar2 = *sum;
        *sum = *sum + uVar3;
        puVar1 = (uint16_t *)sum + 1;
        *puVar1 = *puVar1 + ((int)uVar3 >> 0xf) + (uint)CARRY2(uVar2,uVar3);
      }
      else {
        uVar3 = (uint)((entity_t *)iVar4)[uVar5].base.animFrame *
                (uint)((entity_t *)iVar4)[uVar5].base.level *
                (uint)((entity_t *)iVar4)[uVar5].base.level;
        uVar2 = *enemySum;
        *enemySum = *enemySum + uVar3;
        puVar1 = (uint16_t *)enemySum + 1;
        *puVar1 = *puVar1 + ((int)uVar3 >> 0xf) + (uint)CARRY2(uVar2,uVar3);
      }
    }
  }
  return;
}



/* 3f0b:28eb */

/* [R6] touches AgntCount */

void __cdecl16far attact_usesAgntCount2(uint16_t *sum,uint16_t *enemySum)

{
  uint16_t *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  
  uVar5 = (uint16_t)((ulong)enemySum >> 0x10);
  ((uint16_t *)enemySum)[1] = 0;
  *enemySum = 0;
  uVar6 = (uint16_t)((ulong)sum >> 0x10);
  ((uint16_t *)sum)[1] = 0;
  *sum = 0;
  for (iVar4 = 0; iVar4 < (int)(uint)AgntCount; iVar4 = iVar4 + 1) {
    if ((Agnts[iVar4].flags & 0xae4) == 0) {
      if (Agnts[iVar4].faction == '\0') {
        uVar3 = (uint)Agnts[iVar4].strength;
        uVar2 = *sum;
        *sum = *sum + uVar3;
        puVar1 = (uint16_t *)sum + 1;
        *puVar1 = *puVar1 + (uint)CARRY2(uVar2,uVar3);
      }
      else {
        uVar3 = (uint)Agnts[iVar4].strength;
        uVar2 = *enemySum;
        *enemySum = *enemySum + uVar3;
        puVar1 = (uint16_t *)enemySum + 1;
        *puVar1 = *puVar1 + (uint)CARRY2(uVar2,uVar3);
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
  char cStack_17;
  uint8_t rect;
  uint8_t rect2;
  
  lVar8 = CONCAT22((uint16_t)((ulong)in_stack_0000ffde >> 0x10),unaff_SI);
  dst.seg = _SS;
  dst.ofs = (uint16_t)&rect2;
  F_SCOPY(far_from_u32((uint32_t)(0x2410088d)),dst);
  dst_00.seg = _SS;
  dst_00.ofs = (uint16_t)&rect;
  F_SCOPY(far_from_u32((uint32_t)(0x24100897)),dst_00);
  if (GameRunning == false) {
    cStack_17 = MiceNeedsUpdate == '\0';
    bVar1 = ovr_draw_textArena();
    if (bVar1) {
      attact_usesEntityCount2
                ((uint16_t *)CONCAT22(_SS,&sum),(uint16_t *)CONCAT22(_SS,&stk_ffe0));
      if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) ||
         ((uint16_t)((ulong)lVar8 >> 0x10) == 0 && iStack_1e == 0)) {
        if (cStack_17 != '\0') {
          ovr_miceRestoreArea((brect_t *)&rect,0);
        }
        attact_usesBlitLoadRleGfx();
        if (cStack_17 != '\0') {
          ovr_miceBlitRect((brect_t *)&rect,0);
        }
      }
      else {
        if (mapViewActive != '\0') {
          if (cStack_17 != '\0') {
            ovr_miceRestoreArea((brect_t *)&rect,0);
          }
          gfx.seg = nwpanel1Cut5Seg;
          gfx.ofs = nwpanel1Cut5Ofs;
          ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c510)),0x10);
          gfx_00.seg = panel01Cut3Seg;
          gfx_00.ofs = panel01Cut3Ofs;
          ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa000c51d)),0x1d);
          if (cStack_17 != '\0') {
            ovr_miceBlitRect((brect_t *)&rect,0);
          }
        }
        if (cStack_17 != '\0') {
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
        if (cStack_17 != '\0') {
          ovr_miceBlitRect((brect_t *)&rect2,0);
        }
      }
    }
    else {
      if (cStack_17 != '\0') {
        ovr_miceRestoreArea((brect_t *)&rect,0);
      }
      attact_usesBlitLoadRleGfx();
      if (cStack_17 != '\0') {
        ovr_miceBlitRect((brect_t *)&rect,0);
      }
    }
  }
  return;
}


