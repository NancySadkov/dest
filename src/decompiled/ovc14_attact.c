/*
 * ovc14_attact.c - recovered from STRONG.EXE
 * memory block: OVC14_attact.c
 * range: 3f0b:0000 - 3f0b:2fbf
 * functions: 35
 */
#include "recovered.h"


/* 3f0b:0000 */

/* [R6] touches GMapFlags */

uint __cdecl16far attact_usesGMapFlags(uint x,int y)

{
  uint in_AX;
  uint uVar1;
  short *psVar2;
  byte bVar3;
  undefined2 uVar4;
  
  if (((((int)x < 0) || (y < 0)) || (in_AX = x + 1, 0x93 < (int)in_AX)) ||
     (in_AX = y + 1, 0x3b < (int)in_AX)) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar4 = (undefined2)((ulong)GMapFlags >> 0x10);
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
  undefined2 uVar6;
  undefined2 unaff_SS;
  uint8_t cornerHeights;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  if ((((x < 0) || (y < 0)) || (in_AX = x + 1, 0x93 < (int)in_AX)) ||
     (in_AX = y + 1, 0x3b < (int)in_AX)) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar6 = (undefined2)((ulong)GMapCells >> 0x10);
    paabVar3 = (byte (*) [59] [148])GMapCells;
    _cornerHeights = (int)(char)(*paabVar3)[y][x];
    iStack_8 = (int)(char)(*paabVar3)[y][x + 1];
    iStack_6 = (int)(char)(*paabVar3)[y + 1][x];
    iStack_4 = (int)(char)(*paabVar3)[y + 1][x + 1];
    iVar5 = _cornerHeights;
    for (iVar4 = 1; iVar4 < 4; iVar4 = iVar4 + 1) {
      if (*(int *)(&cornerHeights + iVar4 * 2) < iVar5) {
        iVar5 = *(int *)(&cornerHeights + iVar4 * 2);
      }
      if (_cornerHeights < *(int *)(&cornerHeights + iVar4 * 2)) {
        _cornerHeights = *(int *)(&cornerHeights + iVar4 * 2);
      }
    }
    bVar2 = (byte)((uint)(_cornerHeights - iVar5) >> 8);
    if (_cornerHeights - iVar5 < 0x3c) {
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

undefined2 __cdecl16far attact_usesGUnits(int x,int y)

{
  uint uVar1;
  undefined2 uVar2;
  
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

uint __cdecl16far attact_usesSCARRY2(int x,int y,byte dir,char ignoreBlocked)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  
  iVar1 = (int)*(char *)(dir + 0x885);
  if ((((x + iVar1 < 2) || (iVar1 = (int)*(char *)(dir + 0x889), SCARRY2(y,iVar1) != y + iVar1 < 0))
      || (iVar1 = (int)*(char *)(dir + 0x885), 0x91 < x + iVar1)) ||
     (iVar1 = (int)*(char *)(dir + 0x889), 0x39 < y + iVar1)) {
    uVar2 = CONCAT11((char)((uint)iVar1 >> 8),1);
  }
  else {
    uVar3 = (undefined2)((ulong)GMapFlags >> 0x10);
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
  undefined2 uVar3;
  
  iVar1 = (int)*(char *)(dir + 0x885);
  if (((1 < x + iVar1) && (iVar1 = (int)*(char *)(dir + 0x889), SCARRY2(y,iVar1) == y + iVar1 < 0))
     && (iVar1 = (int)*(char *)(dir + 0x885), x + iVar1 < 0x92)) {
    iVar1 = (int)*(char *)(dir + 0x889);
    if (y + iVar1 < 0x3a) {
      if (directionOnly != '\0') {
        return (uint)(byte)(*(char *)(dir + 0x889) >> 7) << 8;
      }
      uVar3 = (undefined2)((ulong)GMapFlags >> 0x10);
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

/* Counts a party's entities that are off the cursor cell and unflagged, capped at 0x50. */

int __cdecl16far attact_countPartyUnits(byte menuIndex)

{
  entity_t *peVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  
  iVar3 = 0;
  if (((uint8_t *)MenuItemEnabled)[menuIndex] == 0xff) {
    iVar3 = 0;
  }
  else {
    for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
      uVar4 = (undefined2)((ulong)Entities >> 0x10);
      peVar1 = (entity_t *)Entities;
      if (((*(uint8_t *)((int)&peVar1[uVar2].base.entity + 3) ==
            ((uint8_t *)MenuItemEnabled)[menuIndex]) &&
          (((((peVar1 + uVar2)->base).x < GfxRndSeed - 2U ||
            (GfxRndSeed + 1U < ((peVar1 + uVar2)->base).x)) || (peVar1[uVar2].base.y != GfxRndSeed2)
           ))) && ((*(byte *)((int)&peVar1[uVar2].base.flags32 + 1) & 2) == 0)) {
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
  undefined2 uVar2;
  undefined2 unaff_BP;
  long lVar3;
  long in_stack_00000000;
  undefined2 in_stack_0000fffc;
  long a;
  
  a = CONCAT22(unaff_BP,in_stack_0000fffc);
  callResultTemp = attact_countPartyUnits(partyIndex);
  lVar3 = 0x51;
  uVar2 = 0;
  plVar1 = LXMUL_at_((long *)((char *)"Abnormal program termination\r\n" + 0x14),a,in_stack_00000000
                    );
  lVar3 = LDIV_at_((long)CONCAT22(uVar2,plVar1),lVar3);
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
    if ((*(int *)(uVar1 * 0x13) == x) && (*(int *)(uVar1 * 0x13 + 2) == y)) break;
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
    if ((*(int *)(uVar1 * 0x13) == GfxRndSeed) && (*(int *)(uVar1 * 0x13 + 2) == GfxRndSeed2))
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
  undefined4 uVar1;
  undefined4 uVar2;
  bool bVar3;
  int16_t iVar4;
  int iVar5;
  
  if (AgntFlag1) {
    bVar3 = ovr_ovc15_usesAlignUp42();
    if (bVar3) {
      for (iVar5 = 0; iVar5 < (int)(uint)AgntCount; iVar5 = iVar5 + 1) {
        uVar1 = *(undefined4 *)(iVar5 * 0x34 + 0x17);
        *(undefined1 *)((int)uVar1 + 0x31) = *(undefined1 *)(iVar5 * 0x34 + 0x21);
      }
    }
    else {
      for (iVar5 = 0; iVar5 < (int)(uint)AgntCount; iVar5 = iVar5 + 1) {
        uVar1 = *(undefined4 *)(iVar5 * 0x34 + 0x17);
        uVar2 = *(undefined4 *)(iVar5 * 0x34 + 0x17);
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
      func_0x00030e61(0x1000,0x9074,0x2410);
      return;
    }
  }
  else {
    iVar4 = memcmp((char *)&SquareRecX,(char *)0x24109074,0x13);
    if (iVar4 == 0) {
      alignToSeg(far_from_u32((uint32_t)(0x24109074)));
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
  func_0x00030e61(0x1000,iVar5,0x17f8);
  return;
}



/* 3f0b:082f */

/* [R6] touches BDA_DailyTimeCounter */

ulong * __cdecl16far attact_usesBDADailyTimeCounter(ulong *__return_storage_ptr__,ulong prevTick)

{
  uint uVar1;
  int iVar2;
  uint in_stack_00000006;
  
  uVar1 = *(uint *)(BDA_DailyTimeCounter.ofs + 2);
  if ((in_stack_00000006 < uVar1) ||
     ((in_stack_00000006 == uVar1 && (__return_storage_ptr__ <= *(ulong **)BDA_DailyTimeCounter))))
  {
    iVar2 = -(int)__return_storage_ptr__;
  }
  else {
    iVar2 = 0xb0 - (int)__return_storage_ptr__;
  }
  return (ulong *)((int)*(ulong **)BDA_DailyTimeCounter + iVar2);
}



/* 3f0b:0880 */

/* Decrements the byte pointed at by its argument when it is non-zero. */

void __cdecl16far attact_decrementCounter(char *counter)

{
  undefined2 in_stack_00000006;
  
  if (*_counter != '\0') {
    *_counter = *_counter + -1;
  }
  return;
}



/* 3f0b:0894 */

/* [R6] touches AgntCount, Entities */

int __cdecl16far attact_usesAgntCount(int ownerIndex)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  byte bStack_3;
  
  bStack_3 = 0;
  for (bVar3 = 0; bVar3 < AgntCount; bVar3 = bVar3 + 1) {
    if (((*(int *)((uint)bVar3 * 0x34 + 0x1b) == ownerIndex) &&
        (*(char *)((uint)bVar3 * 0x34 + 0x25) != '\x02')) &&
       ((*(uint *)((uint)bVar3 * 0x34 + 0x2b) & 0xae4) == 0)) {
      bStack_3 = bStack_3 + 1;
    }
  }
  uVar1 = (((entity_t *)Entities)[ownerIndex].base.animFrame + 0xf) / 0x10;
  if (uVar1 < bStack_3) {
    iVar2 = 0;
  }
  else {
    iVar2 = uVar1 - bStack_3;
  }
  return iVar2;
}



/* 3f0b:0941 */

/* [R4] calls ovr_alignUp4 */

void __cdecl16far attact_usesAlignUp4(uint16_t x,uint16_t y,char partyIndex,uint32_t flags)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  int in_stack_0000000a;
  uint uStack_8;
  byte bStack_3;
  
  if (partyIndex != -1) {
    uVar1 = ovr_alignUp4(x);
    for (bStack_3 = 0; bStack_3 < 5; bStack_3 = bStack_3 + 1) {
      if (((uint8_t *)MenuItemEnabled)[bStack_3] == partyIndex) {
        uVar3 = 0;
        while ((uVar3 < SquareRecCount &&
               ((uVar4 = ovr_alignUp4(*(int *)(uVar3 * 0x13)), uVar4 != uVar1 ||
                (*(uint16_t *)(uVar3 * 0x13 + 2) != y))))) {
          uVar3 = uVar3 + 1;
        }
        if (SquareRecCount <= uVar3) {
          return;
        }
        uStack_8 = 0;
        for (uVar4 = 0; uVar4 < EntityCount; uVar4 = uVar4 + 1) {
          uVar2 = ovr_alignUp4(((entity_t *)Entities)[uVar4].base.destX);
          if (uVar2 == uVar1) {
            uVar5 = (undefined2)((ulong)Entities >> 0x10);
            if ((((entity_t *)Entities)[uVar4].base.destY == y) &&
               (*(char *)((int)&((entity_t *)Entities)[uVar4].base.entity + 3) == partyIndex)) {
              uStack_8 = uStack_8 + 1;
            }
          }
        }
        if (*(byte *)(uVar3 * 0x13 + (uint)bStack_3 + 0xe) != uStack_8) {
          *(undefined1 *)(uVar3 * 0x13 + (uint)bStack_3 + 0xe) = (undefined1)uStack_8;
          uVar3 = ovr_alignUp4(GfxRndSeed);
          if ((uVar3 == uVar1) && (GfxRndSeed2 == y)) {
            if (in_stack_0000000a == 0 && (int)flags == 0) {
              ovr_ovc41_usesMiceBlitRect((uint)bStack_3);
            }
            else {
              *(undefined1 *)(in_stack_0000000a + (uint)bStack_3) = 1;
            }
          }
        }
      }
    }
  }
  return;
}



/* 3f0b:0ade */

/* [R6] touches Entities, destX */

void __cdecl16far
attact_usesEntities(int entityIndex,uint16_t destX,uint16_t destY,uint16_t flagsOfs,
                   uint16_t flagsSeg)

{
  uint16_t x;
  uint16_t y;
  entity_t *peVar1;
  undefined2 unaff_DI;
  undefined2 uVar2;
  uint32_t flags;
  
  ((entity_t *)Entities)[entityIndex].base.faction = 0x0;
  *(undefined1 *)&((entity_t *)Entities)[entityIndex].base.state = 0;
  uVar2 = (undefined2)((ulong)Entities >> 0x10);
  peVar1 = (entity_t *)Entities;
  x = peVar1[entityIndex].base.destX;
  y = peVar1[entityIndex].base.destY;
  if ((((peVar1 + entityIndex)->base).x == destX) && (peVar1[entityIndex].base.y == destY)) {
    destX = 0;
    destY = 0;
  }
  peVar1[entityIndex].base.destX = destX;
  ((entity_t *)Entities)[entityIndex].base.destY = destY;
  if ((x != 0) || (y != 0)) {
    flags = CONCAT22(unaff_DI,flagsSeg);
    attact_usesAlignUp4(x,y,*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3),
                        flags);
    unaff_DI = (undefined2)(flags >> 0x10);
  }
  if ((destX != 0) || (destY != 0)) {
    attact_usesAlignUp4(destX,destY,
                        *(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3),
                        CONCAT22(unaff_DI,flagsSeg));
  }
  return;
}



/* 3f0b:0c2a */

/* [R6] touches GMapFlags, EntityCount */

void __stdcall16far attact_usesGMapFlags3(void)

{
  uint *puVar1;
  entity_t *peVar2;
  uint uVar3;
  undefined2 uVar4;
  
  ovr_driver_clearMapFlagsRect((uint32_t)GMapFlags,0,0,0x93,0x3b,0xcfff);
  for (uVar3 = 0; uVar3 < EntityCount; uVar3 = uVar3 + 1) {
    uVar4 = (undefined2)((ulong)Entities >> 0x10);
    peVar2 = (entity_t *)Entities;
    puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[peVar2[uVar3].base.y] +
                     ((peVar2 + uVar3)->base).x);
    *puVar1 = *puVar1 | 0x1000 << (*(byte *)((int)(char **)GMenuStrings +
                                            (uint)peVar2[uVar3].base.gindex * 0x95 + 0x1f) & 0x1f);
  }
  ovr_ovc15_usesAlignUp42();
  draw_textGoldProvidesHousing();
  return;
}



/* 3f0b:1082 */

/* [R4] calls ovr_alignUp4 */

void __cdecl16far attact_usesAlignUp42(void)

{
  uint16_t *puVar1;
  uint8_t *puVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  char cVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  uint uVar9;
  uint16_t uVar10;
  uint uVar11;
  char *pcVar12;
  entity_t *peVar13;
  uint16_t index;
  undefined2 uVar14;
  uint16_t unaff_SS;
  undefined4 uStack_1e;
  char cStack_1a;
  uint8_t reported;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  undefined1 uStack_f;
  uint8_t reportedUnits;
  uint16_t uStack_8;
  uint16_t uStack_6;
  byte bStack_4;
  undefined1 uStack_3;
  
  func_0x0004f735();
  reported = 0x0;
  _fmemset(&reportedUnits,unaff_SS,0);
  GGameState = 0x3f;
  if (DebugVerbose != false) {
    printf("%d %d %d \r");
  }
  debugStaleTickCount = 0;
  debugEmptyCellCount = 0;
  index = 0;
  do {
    uVar4 = (*(uint16_t *)((uint8_t *)&(Entities) + 2));
    if (EntityCount <= index) {
      GGameState = 0x3c;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r");
      }
      func_0x0004fcda();
      GGameState = 0x3d;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r");
      }
      ovr_OVC23_55fe_29a2_entry();
      GGameState = 0xc;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r");
      }
      ovr_ovc24_removeOtherEntities(&reported);
      GGameState = 0x1f;
      if (reported != 0x0) {
        ovr_constr_usesBlitRect();
        GGameState = 0x13;
      }
      func_0x0004f68f();
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
    peVar13 = (entity_t *)Entities + index;
    uStack_1e = (entity_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(Entities) + 2)),peVar13);
    uVar8 = ovr_alignUp4((peVar13->base).destX);
    uVar9 = ovr_alignUp4((uStack_1e->base).x);
    if ((uVar8 == uVar9) && ((peVar13->base).destY == (peVar13->base).y)) {
      func_0x0004fb8e(0x2379,index,(peVar13->base).destX,(peVar13->base).destY,&reportedUnits);
    }
    if (((peVar13->base).destX != 0 || (peVar13->base).destY != 0) &&
       (*(char *)((int)&(peVar13->base).entity + 1) == '\0')) {
      uStack_3 = (*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)(peVar13->base).gindex * 0x95)
                 & 0x4000) != 0;
      uStack_6 = (uStack_1e->base).x;
      uStack_8 = (peVar13->base).y;
      uStack_f = *(undefined1 *)
                  ((int)(char **)GMenuStrings + (uint)(peVar13->base).gindex * 0x95 + 0x1f);
      if ((peVar13->base).faction < (byte)(peVar13->base).state) {
        uVar8 = (int)(uint)*(byte *)((int)&(peVar13->base).owner +
                                    ((int)(uint)(peVar13->base).faction >> 2)) >>
                (((peVar13->base).faction & 3) << 1) & 0xff03;
        (peVar13->base).target = (uint8_t)uVar8;
        cVar5 = func_0x0004f32d(0x2379,(uStack_1e->base).x,(peVar13->base).y,
                                CONCAT11((char)(uVar8 >> 8),(peVar13->base).target));
        if (cVar5 == '\0') {
          (uStack_1e->base).x = (uStack_1e->base).x + (int)*(char *)((peVar13->base).target + 0x885)
          ;
          puVar1 = &(peVar13->base).y;
          *puVar1 = *puVar1 + (int)*(char *)((peVar13->base).target + 0x889);
          puVar2 = &(peVar13->base).faction;
          *puVar2 = *puVar2 + 0x1;
        }
        else {
          (peVar13->base).faction = 0x0;
          *(undefined1 *)&(peVar13->base).state = 0;
        }
      }
      else {
        iStack_12 = ovr_ovc07_signum((peVar13->base).destX - (uStack_1e->base).x);
        uVar14 = 0x22da;
        iStack_14 = ovr_ovc07_signum((peVar13->base).destY - (peVar13->base).y);
        if (iStack_12 != 0) {
          uVar14 = 0x2337;
          uVar10 = ovr_randBelow(2);
          if ((char)uVar10 != '\0') {
            cVar5 = func_0x0004f412(0x2337,uStack_6,uStack_8,'\x02' - (char)iStack_12,uStack_f);
            if (cVar5 == '\0') {
              (uStack_1e->base).x = (uStack_1e->base).x + iStack_12;
              (peVar13->base).target = 0x2 - (char)iStack_12;
              goto L_attact_3f0b_1082_1477;
            }
          }
        }
        if (iStack_14 != 0) {
          cVar5 = func_0x0004f412(uVar14,uStack_6,uStack_8,(char)iStack_14 + '\x01',uStack_f);
          if (cVar5 == '\0') {
            puVar1 = &(peVar13->base).y;
            *puVar1 = *puVar1 + iStack_14;
            (peVar13->base).target = (char)iStack_14 + 0x1;
            goto L_attact_3f0b_1082_1477;
          }
        }
        if (iStack_12 != 0) {
          cVar5 = func_0x0004f412(uVar14,uStack_6,uStack_8,'\x02' - (char)iStack_12,uStack_f);
          if (cVar5 == '\0') {
            (uStack_1e->base).x = (uStack_1e->base).x + iStack_12;
            (peVar13->base).target = 0x2 - (char)iStack_12;
            goto L_attact_3f0b_1082_1477;
          }
        }
        uVar8 = ovr_ovc26_usesStExit(index);
        if ((char)uVar8 == '\0') {
          uVar8 = ovr_ovc26_usesRandBelow
                            (index,(uint16_t)&reported,unaff_SS,(uint16_t)&reportedUnits,unaff_SS);
          if (((uVar8 & 0xff) == 0) &&
             (*(char *)((int)(char **)GMenuStrings + (uint)(peVar13->base).gindex * 0x95 + 0x1f) ==
              '\0')) {
            func_0x0004fb8e(0x2386,index,(peVar13->base).targetX,(peVar13->base).targetY,
                            &reportedUnits);
          }
        }
        else {
          uVar8 = (int)(uint)*(byte *)((int)&(peVar13->base).owner +
                                      ((int)(uint)(peVar13->base).faction >> 2)) >>
                  (((peVar13->base).faction & 3) << 1) & 0xff03;
          (peVar13->base).target = (uint8_t)uVar8;
          cVar5 = func_0x0004f32d(0x2386,uStack_6,uStack_8,
                                  CONCAT11((char)(uVar8 >> 8),(peVar13->base).target));
          if (cVar5 == '\0') {
            (uStack_1e->base).x =
                 (uStack_1e->base).x + (int)*(char *)((peVar13->base).target + 0x885);
            puVar1 = &(peVar13->base).y;
            *puVar1 = *puVar1 + (int)*(char *)((peVar13->base).target + 0x889);
            puVar2 = &(peVar13->base).faction;
            *puVar2 = *puVar2 + 0x1;
          }
        }
      }
L_attact_3f0b_1082_1477:
      reported = 0x1;
      uVar8 = ovr_alignUp4((peVar13->base).destX);
      uVar9 = ovr_alignUp4((uStack_1e->base).x);
      if ((uVar8 == uVar9) && ((peVar13->base).destY == (peVar13->base).y)) {
        (peVar13->base).destX = 0;
        (peVar13->base).destY = 0;
        if (*(char *)((int)&(peVar13->base).entity + 3) == -1) {
          bStack_4 = 0xff;
        }
        else {
          uVar3 = *(undefined4 *)((uint)*(byte *)((int)&(peVar13->base).entity + 3) << 2);
          bStack_4 = *(byte *)((int)uVar3 + 0x89);
        }
        if (bStack_4 != 0xff) {
          for (uVar8 = 0; uVar8 < SquareRecCount; uVar8 = uVar8 + 1) {
            uVar9 = ovr_alignUp4(*(int *)(uVar8 * 0x13));
            uVar11 = ovr_alignUp4((uStack_1e->base).x);
            if ((uVar9 == uVar11) && (*(uint16_t *)(uVar8 * 0x13 + 2) == (peVar13->base).y)) {
              func_0x0004f930(0x2379,uVar8 * 0x13 + (uint)bStack_4 + 0xe);
              if (*(uint16_t *)(uVar8 * 0x13 + 2) == GfxRndSeed2) {
                uVar8 = ovr_alignUp4(*(int *)(uVar8 * 0x13));
                uVar9 = ovr_alignUp4(GfxRndSeed);
                if (uVar8 == uVar9) {
                  (&reportedUnits)[bStack_4] = 0x1;
                }
              }
              break;
            }
          }
        }
      }
      if (AgntFlag1 != false) {
        if ((((uStack_1e->base).x < GfxRndSeed - 2U) || (GfxRndSeed + 1U < (uStack_1e->base).x)) ||
           ((peVar13->base).y != GfxRndSeed2)) {
          bVar6 = false;
        }
        else {
          bVar6 = true;
        }
        if (((uStack_6 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uStack_6)) ||
           (GfxRndSeed2 != uStack_8)) {
          bVar7 = false;
        }
        else {
          bVar7 = true;
        }
        if (bVar7 || bVar6) {
          if (bVar7) {
            if (bVar6) {
              for (cStack_1a = func_0x0004f944(0x2379); cStack_1a != '\0';
                  cStack_1a = cStack_1a + -1) {
                if (((peVar13->base).target & 1) == 0) {
                  iStack_16 = 0;
                }
                else {
                  iStack_16 = (peVar13->base).target - 2;
                }
                pcVar12 = ovr_ovc15_textArena(index);
                if (((uint)pcVar12 & 0xff) == 0) break;
              }
            }
            else {
              cStack_1a = (char)((ulong)((peVar13->base).animFrame + 0xf) / 0x10);
              while (cStack_1a != '\0') {
                ovr_agnt_usesAgntCount6
                          ((entity_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(Entities) + 2)),(entity_t *)Entities + index));
                cStack_1a = cStack_1a + -1;
              }
            }
          }
          else {
            ovr_ovc15_clearVisited();
            cStack_1a = (char)((ulong)((peVar13->base).animFrame + 0xf) / 0x10);
            if (((peVar13->base).target & 1) == 0) {
              iStack_16 = 0;
            }
            else {
              iStack_16 = (peVar13->base).target - 2;
            }
            while (cStack_1a != '\0') {
              ovr_ovc15_textArena(index);
              cStack_1a = cStack_1a + -1;
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
  char *txt;
  uint16_t dst;
  char *unaff_SS;
  uint8_t msg;
  uint uStack_6;
  byte bStack_4;
  char cStack_3;
  
  if ((itemIndex < 5) &&
     ((uStack_6 = (uint)((uint8_t *)menuItemRow)[itemIndex], force != 0 ||
      (PrevMenuValue != uStack_6)))) {
    PrevMenuValue = uStack_6;
    ovr_resetTextBlitCycle();
    bStack_4 = ((uint8_t *)MenuItemEnabled)[itemIndex];
    if (bStack_4 != 0xff) {
      iVar1 = ovr_ovc23_findClearColumn(GfxRndSeed,GfxRndSeed2);
      if (iVar1 < 0) {
        ovr_drawTextAt((char *)"You cannot attract units to this location.",0x2410);
        ((uint8_t *)menuItemRow)[itemIndex] = 0x0;
      }
      else {
        uVar2 = func_0x0004f501(0x236f,itemIndex & 0xff);
        callResultTemp = uVar2;
        if (uVar2 < uStack_6) {
          (*(uint8_t *)((uint8_t *)&(uStack_6))) = (uint8_t)uVar2;
          ((uint8_t *)menuItemRow)[itemIndex] = (uint8_t)uStack_6;
          uStack_6 = uVar2;
        }
        cStack_3 = *(char *)((int)*(undefined4 *)((uint)bStack_4 << 2) + 0x2f);
        if (cStack_3 != -1) {
          ovr_ovc41_pluralSuffix(uStack_6);
          dst = 0x2410;
          txt = ovr_stsprintf((char *)&msg,unaff_SS,
                              (char *)"Attracting %d of a possible %d %s%s to this location.");
          ovr_drawTextAt(txt,dst);
        }
      }
    }
  }
  return;
}



/* 3f0b:1a2f */

/* [R2] string "arena" */

char * __cdecl16far
attact_textArena(uint16_t *foundIndexOut,char mode,uint8_t partyIndex,uint16_t x,uint16_t y)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  entity_t *peVar7;
  uint uVar8;
  undefined2 uVar9;
  undefined1 in_stack_00000009;
  uint uStack_4;
  
  uStack_4 = 0xffff;
  uVar1 = ovr_alignUp4(x);
  for (uVar8 = 0; uVar8 < EntityCount; uVar8 = uVar8 + 1) {
    uVar9 = (undefined2)((ulong)Entities >> 0x10);
    if (*(uint8_t *)((int)&((entity_t *)Entities)[uVar8].base.entity + 3) == partyIndex) {
      uVar2 = ovr_alignUp4((((entity_t *)Entities + uVar8)->base).x);
      uVar5 = (int)(uVar2 - uVar1) >> 0xf;
      uVar9 = (undefined2)((ulong)Entities >> 0x10);
      uVar3 = ((entity_t *)Entities)[uVar8].base.y - y;
      uVar6 = (int)uVar3 >> 0xf;
      uVar2 = ((uVar2 - uVar1 ^ uVar5) - uVar5) + ((uVar3 ^ uVar6) - uVar6) * 2;
      if ((uVar2 != 0) && (uVar2 < uStack_4)) {
        uVar3 = ovr_alignUp4(((entity_t *)Entities)[uVar8].base.destX);
        peVar7 = (entity_t *)Entities;
        uVar9 = (undefined2)((ulong)Entities >> 0x10);
        if (((uVar3 != uVar1) || (peVar7[uVar8].base.destY != y)) &&
           ((((_mode == 0 && ((*(byte *)((int)&peVar7[uVar8].base.flags32 + 1) & 2) == 0)) ||
             ((_mode == 1 &&
              (((peVar7[uVar8].base.destX == 0 && (peVar7[uVar8].base.destY == 0)) &&
               ((*(byte *)((int)&peVar7[uVar8].base.flags32 + 1) & 2) == 0)))))) ||
            (((_mode == 2 && ((*(byte *)((int)&peVar7[uVar8].base.flags32 + 1) & 1) != 0)) ||
             ((_mode == 3 && ((*(byte *)((int)&peVar7[uVar8].base.flags32 + 1) & 4) != 0)))))))) {
          *foundIndexOut = uVar8;
          uStack_4 = uVar2;
        }
      }
    }
  }
  if (uStack_4 == 0xffff) {
    pcVar4 = (char *)"arena" + 4;
  }
  else {
    pcVar4 = (char *)"arena" + 5;
  }
  return pcVar4;
}



/* 3f0b:1bfc */

/* [R2] string "arena" */

char * __cdecl16far
attact_textArena2(uint *foundIndexOut,char foundIndexSeg,uint16_t partyIndex,uint16_t x)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  undefined1 in_stack_00000007;
  uint16_t in_stack_0000000c;
  uint uStack_4;
  
  _foundIndexOut = (uint *)CONCAT13(in_stack_00000007,CONCAT12(foundIndexSeg,foundIndexOut));
  uStack_4 = 0;
  uVar1 = ovr_alignUp4(x);
  for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)&((entity_t *)Entities)[uVar7].base.entity + 3) == (char)partyIndex) {
      uVar2 = ovr_alignUp4((((entity_t *)Entities + uVar7)->base).x);
      uVar5 = (int)(uVar2 - uVar1) >> 0xf;
      uVar8 = (undefined2)((ulong)Entities >> 0x10);
      uVar3 = ((entity_t *)Entities)[uVar7].base.y - in_stack_0000000c;
      uVar6 = (int)uVar3 >> 0xf;
      uVar2 = ((uVar2 - uVar1 ^ uVar5) - uVar5) + ((uVar3 ^ uVar6) - uVar6) * 2;
      if (((uStack_4 < uVar2) &&
          (uVar3 = ovr_alignUp4(((entity_t *)Entities)[uVar7].base.destX), uVar3 == uVar1)) &&
         (((entity_t *)Entities)[uVar7].base.destY == in_stack_0000000c)) {
        *_foundIndexOut = uVar7;
        uStack_4 = uVar2;
      }
    }
  }
  if (uStack_4 == 0) {
    pcVar4 = (char *)"arena" + 4;
  }
  else {
    pcVar4 = (char *)"arena" + 5;
  }
  return pcVar4;
}



/* 3f0b:1cfb */

/* [R2] string "arena" */

char * __cdecl16far
attact_textArena3(uint *foundIndexOut,char foundIndexSeg,uint16_t partyIndex,int x)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  undefined1 in_stack_00000007;
  int in_stack_0000000c;
  uint uStack_4;
  
  _foundIndexOut = (uint *)CONCAT13(in_stack_00000007,CONCAT12(foundIndexSeg,foundIndexOut));
  uStack_4 = 0;
  uVar1 = ovr_alignUp4(x);
  for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)&((entity_t *)Entities)[uVar7].base.entity + 3) == (char)partyIndex) {
      uVar2 = ovr_alignUp4((((entity_t *)Entities + uVar7)->base).x);
      uVar5 = (int)(uVar2 - uVar1) >> 0xf;
      uVar3 = ((entity_t *)Entities)[uVar7].base.y - in_stack_0000000c;
      uVar6 = (int)uVar3 >> 0xf;
      uVar2 = ((uVar2 - uVar1 ^ uVar5) - uVar5) + ((uVar3 ^ uVar6) - uVar6) * 2;
      if (uStack_4 < uVar2) {
        *_foundIndexOut = uVar7;
        uStack_4 = uVar2;
      }
    }
  }
  if (uStack_4 == 0) {
    pcVar4 = (char *)"arena" + 4;
  }
  else {
    pcVar4 = (char *)"arena" + 5;
  }
  return pcVar4;
}



/* 3f0b:1db1 */

/* [R4] calls ovr_alignUp4 */

void __cdecl16far attact_usesAlignUp43(uint16_t *value)

{
  byte *pbVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  uint16_t *puVar6;
  uint uVar7;
  uint uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 unaff_SS;
  uint16_t uStack_8;
  uint16_t uStack_6;
  byte bStack_3;
  
  uVar3 = ovr_alignUp4(*value);
  uStack_8 = *value;
  uVar9 = (undefined2)((ulong)value >> 0x10);
  puVar6 = (uint16_t *)value;
  cVar2 = func_0x0004f29c(0x2379,uStack_8,puVar6[1]);
  if (cVar2 == '\0') {
    uStack_6 = 0xfffe;
    while (((int)uStack_6 < 2 &&
           (cVar2 = func_0x0004f29c(0x2379,uStack_8 + uStack_6,puVar6[1]), cVar2 == '\0'))) {
      uStack_6 = uStack_6 + 1;
    }
    if ((int)uStack_6 < 2) {
      uStack_8 = uStack_8 + uStack_6;
    }
  }
  for (uVar8 = 0; (int)uVar8 < 5; uVar8 = uVar8 + 1) {
    uVar7 = 0;
    for (uStack_6 = 0; uStack_6 < EntityCount; uStack_6 = uStack_6 + 1) {
      uVar10 = (undefined2)((ulong)Entities >> 0x10);
      bStack_3 = *(byte *)((int)&((entity_t *)Entities)[uStack_6].base.entity + 3);
      if ((((bStack_3 != 0xff) &&
           (*(byte *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x89) == uVar8)) &&
          (uVar4 = ovr_alignUp4(((entity_t *)Entities)[uStack_6].base.destX), uVar4 == uVar3)) &&
         (((entity_t *)Entities)[uStack_6].base.destY == puVar6[1])) {
        uVar7 = uVar7 + 1;
      }
    }
    bStack_3 = ((uint8_t *)MenuItemEnabled)[uVar8];
    if (*(byte *)((int)puVar6 + uVar8 + 0xe) != uVar7) {
      while (((int)uVar7 < (int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) &&
             (pcVar5 = attact_textArena((uint16_t *)CONCAT22(unaff_SS,&uStack_6),'\x03',bStack_3,
                                        *value,puVar6[1]), (char)pcVar5 != '\0'))) {
        *(undefined1 *)&((entity_t *)Entities)[uStack_6].base.state = 0;
        ((entity_t *)Entities)[uStack_6].base.destX = uStack_8;
        ((entity_t *)Entities)[uStack_6].base.destY = puVar6[1];
        pbVar1 = (byte *)((int)&((entity_t *)Entities)[uStack_6].base.flags32 + 1);
        *pbVar1 = *pbVar1 & 0xfb;
        uVar7 = uVar7 + 1;
      }
      while (((int)uVar7 < (int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) &&
             (pcVar5 = attact_textArena((uint16_t *)CONCAT22(unaff_SS,&uStack_6),'\x02',bStack_3,
                                        *value,puVar6[1]), (char)pcVar5 != '\0'))) {
        *(undefined1 *)&((entity_t *)Entities)[uStack_6].base.state = 0;
        ((entity_t *)Entities)[uStack_6].base.destX = uStack_8;
        ((entity_t *)Entities)[uStack_6].base.destY = puVar6[1];
        uVar7 = uVar7 + 1;
      }
      while (((int)uVar7 < (int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) &&
             (pcVar5 = attact_textArena((uint16_t *)CONCAT22(unaff_SS,&uStack_6),'\x01',bStack_3,
                                        *value,puVar6[1]), (char)pcVar5 != '\0'))) {
        *(undefined1 *)&((entity_t *)Entities)[uStack_6].base.state = 0;
        ((entity_t *)Entities)[uStack_6].base.destX = uStack_8;
        ((entity_t *)Entities)[uStack_6].base.destY = puVar6[1];
        uVar7 = uVar7 + 1;
      }
      while (((int)uVar7 < (int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) &&
             (pcVar5 = attact_textArena((uint16_t *)CONCAT22(unaff_SS,&uStack_6),'\0',bStack_3,
                                        *value,puVar6[1]), (char)pcVar5 != '\0'))) {
        *(undefined1 *)&((entity_t *)Entities)[uStack_6].base.state = 0;
        ((entity_t *)Entities)[uStack_6].base.destX = uStack_8;
        ((entity_t *)Entities)[uStack_6].base.destY = puVar6[1];
        uVar7 = uVar7 + 1;
      }
      while (((int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) < (int)uVar7 &&
             (pcVar5 = attact_textArena2(&uStack_6,(char)unaff_SS,(uint)bStack_3,*value),
             (char)pcVar5 != '\0'))) {
        *(undefined1 *)&((entity_t *)Entities)[uStack_6].base.state = 0;
        uVar10 = (undefined2)((ulong)Entities >> 0x10);
        ((entity_t *)Entities)[uStack_6].base.destX = ((entity_t *)Entities)[uStack_6].base.targetX;
        uVar10 = (undefined2)((ulong)Entities >> 0x10);
        ((entity_t *)Entities)[uStack_6].base.destY = ((entity_t *)Entities)[uStack_6].base.targetY;
        uVar7 = uVar7 - 1;
      }
    }
  }
  return;
}



/* 3f0b:21ef */

/* [R4] calls LDIV_at_ */

undefined2 __cdecl16far attact_usesLDIV_at_(uint8_t menuIndex)

{
  long *plVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 unaff_BP;
  ulong uVar4;
  long in_stack_00000000;
  undefined2 in_stack_0000fffc;
  long a;
  
  a = CONCAT22(unaff_BP,in_stack_0000fffc);
  callResultTemp = func_0x0004f501(0x3f0b);
  if ((long *)callResultTemp == (long *)0x0) {
    uVar4 = 0;
    uVar2 = 0;
  }
  else {
    uVar4 = (ulong)callResultTemp;
    uVar3 = 0;
    plVar1 = LXMUL_at_((long *)callResultTemp,a,in_stack_00000000);
    uVar4 = LDIV_at_((long)CONCAT22(uVar3,plVar1),uVar4);
    uVar2 = (undefined1)(uVar4 >> 8);
    uVar4 = uVar4 & 0xffff;
  }
  if (0x50 < (uint)uVar4) {
    uVar4 = 0x50;
  }
  return CONCAT11(uVar2,(char)uVar4);
}



/* 3f0b:2252 */

/* [R7] body shape: compute */

void __cdecl16far attact_compute2(uint16_t menuIndex,far_t pctOut,far_t remainderOut,far_t partOut)

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

uint __cdecl16far attact_usesAlignUp44(int *xPtr,uint16_t xSeg,byte y,uint8_t dir)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  int value;
  undefined1 in_stack_00000009;
  undefined1 in_stack_0000000c;
  
  uVar2 = 0x3f0b;
  if ((dir & 1) == 0) {
    uVar1 = func_0x0004f32d(0x3f0b,*_xPtr,_y,dir,in_stack_0000000c);
  }
  else {
    value = *_xPtr;
    do {
      uVar2 = func_0x0004f32d(uVar2,*_xPtr,_y,dir,in_stack_0000000c);
      if ((char)uVar2 != '\0') {
        return CONCAT11((char)((uint)uVar2 >> 8),1);
      }
      value = value + *(char *)(dir + 0x885);
      uVar3 = ovr_alignUp4(*_xPtr);
      uVar2 = 0x2379;
      uVar1 = ovr_alignUp4(value);
    } while (uVar3 == uVar1);
    *_xPtr = value;
    uVar1 = uVar1 & 0xff00;
  }
  return uVar1;
}



/* 3f0b:2430 */

/* [R4] calls ovr_randBelow */

void __cdecl16far attact_usesRandBelow(agnt_t *agnt,byte dir)

{
  uint16_t uVar1;
  uint uVar2;
  agnt_t *paVar3;
  undefined2 uVar4;
  uint16_t unaff_SS;
  undefined1 uVar5;
  uint8_t agntX;
  uint16_t uStack_6;
  uint16_t uStack_4;
  
  uVar4 = (undefined2)((ulong)agnt >> 0x10);
  paVar3 = (agnt_t *)agnt;
  uVar5 = *(undefined1 *)((int)(char **)GMenuStrings + (uint)paVar3->gindex * 0x95 + 0x1f);
  if (dir == 0xff) {
    uVar1 = ovr_randBelow(4);
    dir = (byte)uVar1;
    do {
      _agntX = agnt->x;
      uVar2 = attact_usesAlignUp44((int *)&agntX,unaff_SS,(byte)paVar3->y,dir);
      if ((uVar2 & 0xff) == 0) goto L_attact_3f0b_2430_24BF;
      dir = dir + 1 & 3;
    } while (dir != (byte)uVar1);
  }
  else {
    _agntX = agnt->x;
    dir = dir ^ 2;
L_attact_3f0b_2430_24BF:
    uStack_4 = agnt->x;
    uStack_6 = paVar3->y;
    paVar3->y = paVar3->y + (int)*(char *)(dir + 0x889);
    uVar1 = ovr_ovc23_compute2(_agntX + (int)*(char *)(dir + 0x885),paVar3->y);
    agnt->x = uVar1;
    func_0x0004fcda(0x236f,uVar5);
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
    (*(uint16_t *)((uint8_t *)&(GDailyTimeCounter) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    (*(uint16_t *)((uint8_t *)&(GDailyTimeCounter))) = *(undefined2 *)BDA_DailyTimeCounter;
  }
  return;
}



/* 3f0b:26bd */

/* [R6] touches EntityCount, Entities */

void __cdecl16far attact_usesEntityCount(void)

{
  int iVar1;
  char *pcVar2;
  uint owner;
  undefined2 uVar3;
  
  for (owner = 0; owner < EntityCount; owner = owner + 1) {
    uVar3 = (undefined2)((ulong)Entities >> 0x10);
    uVar3 = ovr_ovc23_isCursorAt
                      ((((entity_t *)Entities + owner)->base).x,((entity_t *)Entities)[owner].base.y
                      );
    if ((char)uVar3 != '\0') {
      iVar1 = func_0x0004f944(0x236f,owner);
      while ((iVar1 != 0 && (pcVar2 = ovr_ovc15_textArena(owner), ((uint)pcVar2 & 0xff) != 0))) {
        iVar1 = iVar1 + -1;
      }
    }
  }
  return;
}



/* 3f0b:277b */

/* [R6] touches EntityCount, Entities */

void __cdecl16far attact_usesEntityCount2(uint16_t *sum,uint16_t *enemySum)

{
  uint16_t *puVar1;
  uint uVar2;
  uint uVar3;
  entity_t *peVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  
  uVar6 = (undefined2)((ulong)enemySum >> 0x10);
  ((uint16_t *)enemySum)[1] = 0;
  *enemySum = 0;
  uVar7 = (undefined2)((ulong)sum >> 0x10);
  ((uint16_t *)sum)[1] = 0;
  *sum = 0;
  for (uVar5 = 0; uVar5 < EntityCount; uVar5 = uVar5 + 1) {
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    uVar8 = ovr_ovc23_isCursorAt
                      ((((entity_t *)Entities + uVar5)->base).x,((entity_t *)Entities)[uVar5].base.y
                      );
    if ((char)uVar8 != '\0') {
      uVar8 = (undefined2)((ulong)Entities >> 0x10);
      peVar4 = (entity_t *)Entities;
      if (*(char *)((int)(char **)GMenuStrings + (uint)peVar4[uVar5].base.gindex * 0x95 + 0x1f) ==
          '\0') {
        uVar3 = (uint)peVar4[uVar5].base.animFrame * (uint)peVar4[uVar5].base.level *
                (uint)peVar4[uVar5].base.level;
        uVar2 = *sum;
        *sum = *sum + uVar3;
        puVar1 = (uint16_t *)sum + 1;
        *puVar1 = *puVar1 + ((int)uVar3 >> 0xf) + (uint)CARRY2(uVar2,uVar3);
      }
      else {
        uVar3 = (uint)peVar4[uVar5].base.animFrame * (uint)peVar4[uVar5].base.level *
                (uint)peVar4[uVar5].base.level;
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
  undefined2 uVar5;
  undefined2 uVar6;
  
  uVar5 = (undefined2)((ulong)enemySum >> 0x10);
  ((uint16_t *)enemySum)[1] = 0;
  *enemySum = 0;
  uVar6 = (undefined2)((ulong)sum >> 0x10);
  ((uint16_t *)sum)[1] = 0;
  *sum = 0;
  for (iVar4 = 0; iVar4 < (int)(uint)AgntCount; iVar4 = iVar4 + 1) {
    if ((*(uint *)(iVar4 * 0x34 + 0x2b) & 0xae4) == 0) {
      if (*(char *)(iVar4 * 0x34 + 0x2f) == '\0') {
        uVar3 = (uint)*(byte *)(iVar4 * 0x34 + 0x21);
        uVar2 = *sum;
        *sum = *sum + uVar3;
        puVar1 = (uint16_t *)sum + 1;
        *puVar1 = *puVar1 + (uint)CARRY2(uVar2,uVar3);
      }
      else {
        uVar3 = (uint)*(byte *)(iVar4 * 0x34 + 0x21);
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
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c510)));
  ovr_ovc13_blitAnimFrame();
  return;
}



/* 3f0b:2a09 */

/* [R4] calls LDIV_at_ */

void __cdecl16far attact_usesLDIV_at_2(void)

{
  char *pcVar1;
  long *plVar2;
  undefined2 uVar3;
  undefined2 unaff_SI;
  uint uVar4;
  undefined2 unaff_DI;
  int iVar5;
  uint16_t unaff_SS;
  long lVar6;
  long lVar7;
  far_t gfx;
  far_t gfx_00;
  far_t dst;
  far_t dst_00;
  long *plVar8;
  uint uVar9;
  long in_stack_0000ffe0;
  uint32_t sum;
  char cStack_17;
  uint8_t rect;
  uint8_t rect2;
  
  lVar7 = CONCAT22(unaff_SI,unaff_DI);
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&rect2;
  F_SCOPY(far_from_u32((uint32_t)(0x2410088d)),dst);
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&rect;
  F_SCOPY(far_from_u32((uint32_t)(0x24100897)),dst_00);
  if (GameRunning == false) {
    cStack_17 = MiceNeedsUpdate == '\0';
    pcVar1 = ovr_draw_textArena();
    if (((uint)pcVar1 & 0xff) == 0) {
      if (cStack_17 != '\0') {
        ovr_miceRestoreArea((brect_t *)&rect);
      }
      attact_usesBlitLoadRleGfx();
      if (cStack_17 != '\0') {
        ovr_miceBlitRect((brect_t *)&rect);
      }
    }
    else {
      attact_usesEntityCount2
                ((uint16_t *)CONCAT22(unaff_SS,&sum),(uint16_t *)CONCAT22(unaff_SS,&stack0xffe0));
      if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) ||
         ((uint16_t)in_stack_0000ffe0 == 0 && (int)((ulong)in_stack_0000ffe0 >> 0x10) == 0)) {
        if (cStack_17 != '\0') {
          ovr_miceRestoreArea((brect_t *)&rect);
        }
        attact_usesBlitLoadRleGfx();
        if (cStack_17 != '\0') {
          ovr_miceBlitRect((brect_t *)&rect);
        }
      }
      else {
        if (mapViewActive != '\0') {
          if (cStack_17 != '\0') {
            ovr_miceRestoreArea((brect_t *)&rect);
          }
          gfx.seg = nwpanel1Cut5Seg;
          gfx.ofs = nwpanel1Cut5Ofs;
          ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c510)));
          gfx_00.seg = panel01Cut3Seg;
          gfx_00.ofs = panel01Cut3Ofs;
          ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa000c51d)));
          if (cStack_17 != '\0') {
            ovr_miceBlitRect((brect_t *)&rect);
          }
        }
        if (cStack_17 != '\0') {
          ovr_miceRestoreArea((brect_t *)&rect2);
        }
        mapViewActive = '\0';
        uVar4 = (uint)in_stack_0000ffe0;
        iVar5 = (int)((ulong)in_stack_0000ffe0 >> 0x10);
        if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) && (uVar4 != 0 || iVar5 != 0)) {
          uVar4 = 0;
        }
        else if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) || (uVar4 != 0 || iVar5 != 0)) {
          plVar8 = (long *)CONCAT22(iVar5 + (*(uint16_t *)((uint8_t *)&(sum) + 2)) + (uint)CARRY2(uVar4,(uint)sum),
                                    (long *)(uVar4 + (uint)sum));
          uVar3 = 0;
          plVar2 = LXMUL_at_((long *)(uVar4 + (uint)sum),lVar7,in_stack_0000ffe0);
          lVar6 = LDIV_at_((long)CONCAT22(uVar3,plVar2),(long)plVar8);
          uVar4 = (int)lVar6 + 1;
        }
        else {
          uVar4 = 0x26;
        }
        if (AgntFlag1 != false) {
          attact_usesAgntCount2
                    ((uint16_t *)CONCAT22(unaff_SS,&sum),(uint16_t *)CONCAT22(unaff_SS,&stack0xffe0)
                    );
          uVar9 = (uint)in_stack_0000ffe0;
          iVar5 = (int)((ulong)in_stack_0000ffe0 >> 0x10);
          if (((uint)sum != 0 || (*(uint16_t *)((uint8_t *)&(sum) + 2)) != 0) || (uVar9 != 0 || iVar5 != 0)) {
            if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) && (uVar9 != 0 || iVar5 != 0)) {
              iVar5 = 0;
            }
            else if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) || (uVar9 != 0 || iVar5 != 0)) {
              plVar8 = (long *)CONCAT22(iVar5 + (*(uint16_t *)((uint8_t *)&(sum) + 2)) + (uint)CARRY2(uVar9,(uint)sum),
                                        (long *)(uVar9 + (uint)sum));
              uVar3 = 0;
              plVar2 = LXMUL_at_((long *)(uVar9 + (uint)sum),lVar7,in_stack_0000ffe0);
              lVar7 = LDIV_at_((long)CONCAT22(uVar3,plVar2),(long)plVar8);
              iVar5 = (int)lVar7 + 1;
            }
            else {
              iVar5 = 0x26;
            }
            uVar4 = uVar4 + iVar5 >> 1;
          }
        }
        if (0x9e < 0xc4 - uVar4) {
          ovr_driver_fillRect(0xdf,0x9f,0xe2,0xc4 - uVar4,0x24,0xa000);
        }
        if (uVar4 != 0) {
          ovr_driver_fillRect(0xdf,0xc5 - uVar4,0xe2,0xc4,0x7,0xa000);
        }
        if (cStack_17 != '\0') {
          ovr_miceBlitRect((brect_t *)&rect2);
        }
      }
    }
  }
  return;
}


