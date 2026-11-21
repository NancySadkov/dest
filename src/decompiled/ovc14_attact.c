/*
 * ovc14_attact.c - recovered from STRONG.EXE
 * memory block: OVC14_attact.c
 * range: 3f0b:0000 - 3f0b:2fbf
 * functions: 35
 */
#include "recovered.h"


/* 3f0b:0000 */

/* [R6] touches GMapFlags */

uint __cdecl16far attact_usesGMapFlags(uint x,int y,...)

{
  uint in_AX;
  uint uVar1;
  short *psVar2;
  byte bVar3;
  undefined2 uVar4;
  uint in_stack_00000004;
  
  if (((((int)in_stack_00000004 < 0) || ((int)x < 0)) ||
      (in_AX = in_stack_00000004 + 1, 0x93 < (int)in_AX)) || (in_AX = x + 1, 0x3b < (int)in_AX)) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar4 = (undefined2)((ulong)GMapFlags >> 0x10);
    if (((*(short (*) [60] [148])GMapFlags)[x][in_stack_00000004] & 3U) == 0) {
      psVar2 = (*(short (*) [60] [148])GMapFlags)[x] + in_stack_00000004;
      bVar3 = (byte)((uint)psVar2 >> 8);
      if ((psVar2[0x94] & 3U) == 0) {
        uVar1 = CONCAT11(bVar3,1);
      }
      else {
        uVar1 = (uint)bVar3 << 8;
      }
    }
    else {
      uVar1 = ((in_stack_00000004 & 0x7fff) >> 7) << 8;
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

undefined2 __cdecl16far attact_usesGUnits(int x,int y,...)

{
  int x_00;
  uint uVar1;
  undefined2 uVar2;
  int in_stack_00000004;
  
  x_00 = in_stack_00000004;
  uVar1 = attact_usesGMapFlags2(in_stack_00000004,x);
  if ((uVar1 & 0xff) == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = attact_isTerrainFlat(x_00,x);
    if ((uVar1 & 0xff) == 0) {
      uVar2 = 0;
    }
    else if ((*(byte *)((uint)((unit_t *)GUnits + (*(short (*) [148] [60])GUnitGrid)[x_00][x])->
                              bldType * 0x27 + 0x11e) & 3) == 3) {
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

uint __cdecl16far attact_usesSCARRY2(int x,int y,byte dir,char ignoreBlocked,...)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  int in_stack_00000004;
  
  iVar1 = (int)*(char *)((y & 0xffU) + 0x885);
  if ((((in_stack_00000004 + iVar1 < 2) ||
       (iVar1 = (int)*(char *)((y & 0xffU) + 0x889), SCARRY2(x,iVar1) != x + iVar1 < 0)) ||
      (iVar1 = (int)*(char *)((y & 0xffU) + 0x885), 0x91 < in_stack_00000004 + iVar1)) ||
     (iVar1 = (int)*(char *)((y & 0xffU) + 0x889), 0x39 < x + iVar1)) {
    uVar2 = CONCAT11((char)((uint)iVar1 >> 8),1);
  }
  else {
    uVar3 = (undefined2)((ulong)GMapFlags >> 0x10);
    uVar2 = (uint)(*(short (*) [60] [148])GMapFlags)[x][in_stack_00000004] >> ((char)y + 4U & 0x1f);
    if (((uVar2 & 1) == 0) || (dir != 0)) {
      uVar2 = (uint)((byte)uVar2 & 1);
    }
    else {
      uVar2 = (uint)(*(short (*) [60] [148])GMapFlags)[x][in_stack_00000004] >>
              ((char)y + 8U & 0x1f) & 0xff01 ^ 1;
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

int __cdecl16far attact_countPartyUnits(byte menuIndex,...)

{
  entity_t *peVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  byte in_stack_00000004;
  
  iVar3 = 0;
  if (((uint8_t *)MenuItemEnabled)[in_stack_00000004] == 0xff) {
    iVar3 = 0;
  }
  else {
    for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
      uVar4 = (undefined2)((ulong)Entities >> 0x10);
      peVar1 = (entity_t *)Entities;
      if (((*(uint8_t *)((int)&peVar1[uVar2].base.entity + 3) ==
            ((uint8_t *)MenuItemEnabled)[in_stack_00000004]) &&
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

uint16_t __cdecl16far attact_textAbnormalProgramTermination(uint16_t value,uint8_t partyIndex,...)

{
  long *plVar1;
  undefined2 uVar2;
  undefined2 unaff_BP;
  long lVar3;
  long in_stack_00000000;
  undefined2 in_stack_00000004;
  undefined2 in_stack_0000fffc;
  long a;
  
  a = CONCAT22(unaff_BP,in_stack_0000fffc);
  callResultTemp = attact_countPartyUnits();
  lVar3 = 0x51;
  uVar2 = 0;
  plVar1 = LXMUL_at_((long *)0x0,a,in_stack_00000000);
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

int __cdecl16far attact_usesSquareRecCount(int x,int y,...)

{
  uint uVar1;
  int in_stack_00000004;
  
  uVar1 = 0;
  while( true ) {
    if (SquareRecCount <= uVar1) {
      return 0x86e;
    }
    if ((*(int *)(uVar1 * 0x13) == in_stack_00000004) && (*(int *)(uVar1 * 0x13 + 2) == x)) break;
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
      alignToSeg();
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

ulong * __cdecl16far
attact_usesBDADailyTimeCounter(ulong *__return_storage_ptr__,ulong prevTick,...)

{
  uint uVar1;
  ulong *puVar2;
  uint in_stack_00000004;
  
  puVar2 = (ulong *)*(uint *)(BDA_DailyTimeCounter.ofs + 2);
  uVar1 = *(uint *)BDA_DailyTimeCounter;
  if ((__return_storage_ptr__ < puVar2) ||
     ((__return_storage_ptr__ == puVar2 && (in_stack_00000004 <= uVar1)))) {
    puVar2 = (ulong *)(uVar1 - in_stack_00000004);
  }
  else {
    puVar2 = (ulong *)((uVar1 + 0xb0) - in_stack_00000004);
  }
  return puVar2;
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

void __cdecl16far attact_usesAlignUp4(uint16_t x,uint16_t y,char partyIndex,uint32_t flags,...)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_DI;
  uint uVar4;
  undefined2 uVar5;
  undefined2 in_stack_00000004;
  undefined1 uStack000b;
  uint uStack_8;
  byte bStack_3;
  
  if ((uint8_t)y != 0xff) {
    uVar1 = ovr_alignUp4(unaff_DI,in_stack_00000004);
    for (bStack_3 = 0; bStack_3 < 5; bStack_3 = bStack_3 + 1) {
      if (((uint8_t *)MenuItemEnabled)[bStack_3] == (uint8_t)y) {
        uVar3 = 0;
        while ((uVar3 < SquareRecCount &&
               ((uVar4 = ovr_alignUp4(unaff_DI,*(undefined2 *)(uVar3 * 0x13)), uVar4 != uVar1 ||
                (*(uint16_t *)(uVar3 * 0x13 + 2) != x))))) {
          uVar3 = uVar3 + 1;
        }
        if (SquareRecCount <= uVar3) {
          return;
        }
        uStack_8 = 0;
        for (uVar4 = 0; uVar4 < EntityCount; uVar4 = uVar4 + 1) {
          uVar2 = ovr_alignUp4(unaff_DI,((entity_t *)Entities)[uVar4].base.destX);
          if (uVar2 == uVar1) {
            uVar5 = (undefined2)((ulong)Entities >> 0x10);
            if ((((entity_t *)Entities)[uVar4].base.destY == x) &&
               (*(uint8_t *)((int)&((entity_t *)Entities)[uVar4].base.entity + 3) == (uint8_t)y)) {
              uStack_8 = uStack_8 + 1;
            }
          }
        }
        if (*(byte *)(uVar3 * 0x13 + (uint)bStack_3 + 0xe) != uStack_8) {
          *(undefined1 *)(uVar3 * 0x13 + (uint)bStack_3 + 0xe) = (undefined1)uStack_8;
          uVar3 = ovr_alignUp4(unaff_DI,GfxRndSeed);
          if ((uVar3 == uVar1) && (GfxRndSeed2 == x)) {
            if (CONCAT11(uStack000b,partyIndex) == 0 && (int)flags == 0) {
              ovr_ovc41_usesMiceBlitRect(unaff_DI,(uint)bStack_3);
            }
            else {
              *(undefined1 *)(CONCAT11(uStack000b,partyIndex) + (uint)bStack_3) = 1;
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
                   uint16_t flagsSeg,...)

{
  uint16_t uVar1;
  uint16_t x;
  int iVar2;
  entity_t *peVar3;
  undefined2 unaff_DI;
  undefined2 uVar4;
  int in_stack_00000004;
  uint32_t flags;
  
  iVar2 = in_stack_00000004;
  ((entity_t *)Entities)[in_stack_00000004].base.faction = 0x0;
  *(undefined1 *)&((entity_t *)Entities)[in_stack_00000004].base.state = 0;
  uVar4 = (undefined2)((ulong)Entities >> 0x10);
  peVar3 = (entity_t *)Entities;
  uVar1 = peVar3[in_stack_00000004].base.destX;
  x = peVar3[in_stack_00000004].base.destY;
  if ((((peVar3 + in_stack_00000004)->base).x == entityIndex) &&
     (peVar3[in_stack_00000004].base.y == destX)) {
    entityIndex = 0;
    destX = 0;
  }
  peVar3[in_stack_00000004].base.destX = entityIndex;
  ((entity_t *)Entities)[in_stack_00000004].base.destY = destX;
  if ((uVar1 != 0) || (x != 0)) {
    flags = CONCAT22(unaff_DI,flagsOfs);
    attact_usesAlignUp4(x,CONCAT11((char)((uint)(in_stack_00000004 * 0x37) >> 8),
                                   *(undefined1 *)
                                    ((int)&((entity_t *)Entities)[in_stack_00000004].base.entity + 3
                                    )),(char)destY,flags,uVar1);
    unaff_DI = (undefined2)(flags >> 0x10);
  }
  if ((entityIndex != 0) || (destX != 0)) {
    attact_usesAlignUp4(destX,CONCAT11((char)((uint)(iVar2 * 0x37) >> 8),
                                       *(undefined1 *)
                                        ((int)&((entity_t *)Entities)[iVar2].base.entity + 3)),
                        (char)destY,CONCAT22(unaff_DI,flagsOfs),entityIndex);
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
  uint unaff_DI;
  undefined2 uVar4;
  
  ovr_driver_clearMapFlagsRect
            ((ulong)GMapFlags >> 0x10,0,0x93,0x3b,-0x3001,unaff_DI,(short (*) [60] [148])GMapFlags);
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
  undefined1 uVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined2 uVar6;
  char cVar7;
  bool bVar8;
  bool bVar9;
  uint uVar10;
  uint uVar11;
  undefined1 uVar17;
  int iVar12;
  int iVar13;
  uint16_t uVar14;
  uint uVar15;
  char *pcVar16;
  entity_t *peVar18;
  uint16_t unaff_DI;
  uint16_t index;
  undefined2 uVar19;
  uint unaff_SS;
  undefined4 uStack_1e;
  char cStack_1a;
  uint8_t reported;
  char cStack_14;
  char cStack_12;
  uint8_t reportedUnits;
  uint16_t uStack_8;
  uint16_t uStack_6;
  byte bStack_4;
  undefined1 uStack_3;
  
  func_0x0004f735(0x3f0b);
  bVar5 = false;
  _fmemset((void *)(ulong)unaff_SS,5,unaff_DI);
  GGameState = 0x3f;
  if (DebugVerbose != false) {
    printf("%d %d %d \r");
  }
  uVar19 = 0x1000;
  debugStaleTickCount = 0;
  debugEmptyCellCount = 0;
  index = 0;
  do {
    uVar6 = (*(uint16_t *)((uint8_t *)&(Entities) + 2));
    if (EntityCount <= index) {
      GGameState = 0x3c;
      if (DebugVerbose != false) {
        uVar19 = 0x1000;
        printf("%d %d %d  \r");
      }
      func_0x0004fcda(uVar19);
      GGameState = 0x3d;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r");
      }
      ovr_OVC23_55fe_29a2_entry();
      GGameState = 0xc;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r");
      }
      uVar19 = 0x2379;
      ovr_ovc24_removeOtherEntities();
      GGameState = 0x1f;
      if (bVar5) {
        uVar19 = 0x22ef;
        ovr_constr_usesBlitRect();
        GGameState = 0x13;
      }
      func_0x0004f68f(uVar19);
      GGameState = 0x1d;
      for (iVar12 = 0; iVar12 < 5; iVar12 = iVar12 + 1) {
        if ((&reportedUnits)[iVar12] != 0x0) {
          ovr_ovc41_usesMiceBlitRect();
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
    peVar18 = (entity_t *)Entities + index;
    uStack_1e = (entity_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(Entities) + 2)),peVar18);
    uVar10 = ovr_alignUp4();
    uVar19 = 0x2379;
    uVar11 = ovr_alignUp4();
    if ((uVar10 == uVar11) && ((peVar18->base).destY == (peVar18->base).y)) {
      func_0x0004fb8e(0x2379,index,(peVar18->base).destX,(peVar18->base).destY);
    }
    if (((peVar18->base).destX != 0 || (peVar18->base).destY != 0) &&
       (*(char *)((int)&(peVar18->base).entity + 1) == '\0')) {
      uStack_3 = (*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)(peVar18->base).gindex * 0x95)
                 & 0x4000) != 0;
      uStack_6 = (uStack_1e->base).x;
      uStack_8 = (peVar18->base).y;
      uVar3 = *(undefined1 *)
               ((int)(char **)GMenuStrings + (uint)(peVar18->base).gindex * 0x95 + 0x1f);
      if ((peVar18->base).faction < (byte)(peVar18->base).state) {
        uVar10 = (int)(uint)*(byte *)((int)&(peVar18->base).owner +
                                     ((int)(uint)(peVar18->base).faction >> 2)) >>
                 (((peVar18->base).faction & 3) << 1) & 0xff03;
        (peVar18->base).target = (uint8_t)uVar10;
        uVar17 = (undefined1)(uVar10 >> 8);
        cVar7 = func_0x0004f32d(0x2379,(uStack_1e->base).x,(peVar18->base).y,
                                CONCAT11(uVar17,(peVar18->base).target),CONCAT11(uVar17,uVar3));
        if (cVar7 == '\0') {
          (uStack_1e->base).x = (uStack_1e->base).x + (int)*(char *)((peVar18->base).target + 0x885)
          ;
          puVar1 = &(peVar18->base).y;
          *puVar1 = *puVar1 + (int)*(char *)((peVar18->base).target + 0x889);
          puVar2 = &(peVar18->base).faction;
          *puVar2 = *puVar2 + 0x1;
        }
        else {
          (peVar18->base).faction = 0x0;
          *(undefined1 *)&(peVar18->base).state = 0;
        }
      }
      else {
        iVar12 = ovr_ovc07_signum();
        uVar19 = 0x22da;
        iVar13 = ovr_ovc07_signum();
        cStack_12 = (char)iVar12;
        if (iVar12 != 0) {
          uVar19 = 0x2337;
          uVar14 = ovr_randBelow();
          if (((char)uVar14 != '\0') &&
             (cVar7 = func_0x0004f412(0x2337,uStack_6,uStack_8,'\x02' - cStack_12,uVar3,uStack_3),
             cVar7 == '\0')) {
            (uStack_1e->base).x = (uStack_1e->base).x + iVar12;
            (peVar18->base).target = 0x2 - cStack_12;
            goto L_attact_3f0b_1082_1477;
          }
        }
        if (iVar13 != 0) {
          cStack_14 = (char)iVar13;
          cVar7 = func_0x0004f412(uVar19,uStack_6,uStack_8,cStack_14 + '\x01',uVar3,uStack_3);
          if (cVar7 == '\0') {
            puVar1 = &(peVar18->base).y;
            *puVar1 = *puVar1 + iVar13;
            (peVar18->base).target = cStack_14 + 0x1;
            goto L_attact_3f0b_1082_1477;
          }
        }
        if ((iVar12 == 0) ||
           (cVar7 = func_0x0004f412(uVar19,uStack_6,uStack_8,'\x02' - cStack_12,uVar3,uStack_3),
           cVar7 != '\0')) {
          uVar10 = ovr_ovc26_usesStExit();
          if ((char)uVar10 == '\0') {
            uVar10 = ovr_ovc26_usesRandBelow();
            if (((uVar10 & 0xff) == 0) &&
               (*(char *)((int)(char **)GMenuStrings + (uint)(peVar18->base).gindex * 0x95 + 0x1f)
                == '\0')) {
              func_0x0004fb8e(0x2386,index,(peVar18->base).targetX,(peVar18->base).targetY);
            }
          }
          else {
            uVar10 = (int)(uint)*(byte *)((int)&(peVar18->base).owner +
                                         ((int)(uint)(peVar18->base).faction >> 2)) >>
                     (((peVar18->base).faction & 3) << 1) & 0xff03;
            (peVar18->base).target = (uint8_t)uVar10;
            uVar17 = (undefined1)(uVar10 >> 8);
            cVar7 = func_0x0004f32d(0x2386,uStack_6,uStack_8,CONCAT11(uVar17,(peVar18->base).target)
                                    ,CONCAT11(uVar17,uVar3));
            if (cVar7 == '\0') {
              (uStack_1e->base).x =
                   (uStack_1e->base).x + (int)*(char *)((peVar18->base).target + 0x885);
              puVar1 = &(peVar18->base).y;
              *puVar1 = *puVar1 + (int)*(char *)((peVar18->base).target + 0x889);
              puVar2 = &(peVar18->base).faction;
              *puVar2 = *puVar2 + 0x1;
            }
          }
        }
        else {
          (uStack_1e->base).x = (uStack_1e->base).x + iVar12;
          (peVar18->base).target = 0x2 - cStack_12;
        }
      }
L_attact_3f0b_1082_1477:
      bVar5 = true;
      uVar10 = ovr_alignUp4();
      uVar11 = ovr_alignUp4();
      if ((uVar10 == uVar11) && ((peVar18->base).destY == (peVar18->base).y)) {
        (peVar18->base).destX = 0;
        (peVar18->base).destY = 0;
        if (*(char *)((int)&(peVar18->base).entity + 3) == -1) {
          bStack_4 = 0xff;
        }
        else {
          uVar4 = *(undefined4 *)((uint)*(byte *)((int)&(peVar18->base).entity + 3) << 2);
          bStack_4 = *(byte *)((int)uVar4 + 0x89);
        }
        if (bStack_4 != 0xff) {
          for (uVar10 = 0; uVar10 < SquareRecCount; uVar10 = uVar10 + 1) {
            uVar11 = ovr_alignUp4();
            uVar15 = ovr_alignUp4();
            if ((uVar11 == uVar15) && (*(uint16_t *)(uVar10 * 0x13 + 2) == (peVar18->base).y)) {
              func_0x0004f930(0x2379,uVar10 * 0x13 + (uint)bStack_4 + 0xe,0x17f8);
              if (*(uint16_t *)(uVar10 * 0x13 + 2) == GfxRndSeed2) {
                uVar10 = ovr_alignUp4();
                uVar11 = ovr_alignUp4();
                if (uVar10 == uVar11) {
                  (&reportedUnits)[bStack_4] = 0x1;
                }
              }
              break;
            }
          }
        }
      }
      uVar19 = 0x2379;
      if (AgntFlag1 != false) {
        if ((((uStack_1e->base).x < GfxRndSeed - 2U) || (GfxRndSeed + 1U < (uStack_1e->base).x)) ||
           ((peVar18->base).y != GfxRndSeed2)) {
          bVar8 = false;
        }
        else {
          bVar8 = true;
        }
        if (((uStack_6 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uStack_6)) ||
           (GfxRndSeed2 != uStack_8)) {
          bVar9 = false;
        }
        else {
          bVar9 = true;
        }
        if (bVar9 || bVar8) {
          if (bVar9) {
            if (bVar8) {
              for (cStack_1a = func_0x0004f944(); cStack_1a != '\0'; cStack_1a = cStack_1a + -1) {
                uVar19 = 0x2322;
                pcVar16 = ovr_ovc15_textArena();
                if (((uint)pcVar16 & 0xff) == 0) break;
              }
            }
            else {
              cStack_1a = (char)((ulong)((peVar18->base).animFrame + 0xf) / 0x10);
              while (cStack_1a != '\0') {
                uVar19 = 0x22ff;
                ovr_agnt_usesAgntCount6();
                cStack_1a = cStack_1a + -1;
              }
            }
          }
          else {
            ovr_ovc15_clearVisited();
            cStack_1a = (char)((ulong)((peVar18->base).animFrame + 0xf) / 0x10);
            while( true ) {
              uVar19 = 0x2322;
              if (cStack_1a == '\0') break;
              ovr_ovc15_textArena();
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

/* WARNING: Variable defined which should be unmapped: msg */
/* Updates one attract-menu entry: caches its value, shows the 'cannot attract' message or
   recomputes its count. */

void __cdecl16far attact_updateAttractEntry(int itemIndex,int force,...)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  char *pcVar4;
  undefined2 uVar5;
  char *pcVar6;
  char *unaff_SS;
  int in_stack_00000004;
  undefined2 uVar7;
  uint8_t msg;
  uint uStack_6;
  byte bStack_4;
  byte bStack_3;
  
  if ((in_stack_00000004 < 5) &&
     ((uStack_6 = (uint)((uint8_t *)menuItemRow)[in_stack_00000004], itemIndex != 0 ||
      (PrevMenuValue != uStack_6)))) {
    PrevMenuValue = uStack_6;
    ovr_resetTextBlitCycle();
    bStack_4 = ((uint8_t *)MenuItemEnabled)[in_stack_00000004];
    if (bStack_4 != 0xff) {
      iVar1 = ovr_ovc23_findClearColumn();
      if (iVar1 < 0) {
        ovr_drawTextAt((char *)0xa0002410,_msg,0x8f6);
        ((uint8_t *)menuItemRow)[in_stack_00000004] = 0x0;
      }
      else {
        uVar2 = func_0x0004f501(0x236f);
        callResultTemp = uVar2;
        if (uVar2 < uStack_6) {
          (*(uint8_t *)((uint8_t *)&(uStack_6))) = (uint8_t)uVar2;
          ((uint8_t *)menuItemRow)[in_stack_00000004] = (uint8_t)uStack_6;
          uStack_6 = uVar2;
        }
        uVar5 = 0x217a;
        bStack_3 = *(byte *)((int)*(undefined4 *)((uint)bStack_4 << 2) + 0x2f);
        if (bStack_3 != 0xff) {
          uVar7 = 0xa000;
          uVar3 = ovr_ovc41_pluralSuffix();
          pcVar6 = (char *)"puppetmaker" + 3;
          pcVar4 = ovr_stsprintf((char *)CONCAT22(0x921,unaff_SS),
                                 (char *)CONCAT22(uStack_6,(char *)"puppetmaker" + 3),
                                 (char *)callResultTemp,&msg,
                                 *(undefined2 *)((uint)bStack_3 * 4 + 0x13f),
                                 *(undefined2 *)((uint)bStack_3 * 4 + 0x141),uVar3,uVar5);
          ovr_drawTextAt((char *)CONCAT22(uVar7,pcVar6),_msg,pcVar4);
        }
      }
    }
  }
  return;
}



/* 3f0b:1a2f */

/* [R2] string "arena" */

bool __cdecl16far
attact_textArena(uint16_t *foundIndexOut,int mode,uint8_t partyIndex,uint16_t x,uint16_t y)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  entity_t *peVar6;
  uint uVar7;
  int unaff_DI;
  undefined2 uVar8;
  uint uStack_4;
  
  uStack_4 = 0xffff;
  uVar1 = ovr_alignUp4(unaff_DI,x);
  for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    if (*(uint8_t *)((int)&((entity_t *)Entities)[uVar7].base.entity + 3) == partyIndex) {
      uVar2 = ovr_alignUp4(unaff_DI,(((entity_t *)Entities + uVar7)->base).x);
      uVar4 = (int)(uVar2 - uVar1) >> 0xf;
      uVar8 = (undefined2)((ulong)Entities >> 0x10);
      uVar3 = ((entity_t *)Entities)[uVar7].base.y - y;
      uVar5 = (int)uVar3 >> 0xf;
      uVar2 = ((uVar2 - uVar1 ^ uVar4) - uVar4) + ((uVar3 ^ uVar5) - uVar5) * 2;
      if ((uVar2 != 0) && (uVar2 < uStack_4)) {
        uVar3 = ovr_alignUp4(unaff_DI,((entity_t *)Entities)[uVar7].base.destX);
        peVar6 = (entity_t *)Entities;
        uVar8 = (undefined2)((ulong)Entities >> 0x10);
        if (((uVar3 != uVar1) || (peVar6[uVar7].base.destY != y)) &&
           ((((mode == 0 && ((*(byte *)((int)&peVar6[uVar7].base.flags32 + 1) & 2) == 0)) ||
             ((mode == 1 &&
              (((peVar6[uVar7].base.destX == 0 && (peVar6[uVar7].base.destY == 0)) &&
               ((*(byte *)((int)&peVar6[uVar7].base.flags32 + 1) & 2) == 0)))))) ||
            (((mode == 2 && ((*(byte *)((int)&peVar6[uVar7].base.flags32 + 1) & 1) != 0)) ||
             ((mode == 3 && ((*(byte *)((int)&peVar6[uVar7].base.flags32 + 1) & 4) != 0)))))))) {
          *foundIndexOut = uVar7;
          uStack_4 = uVar2;
        }
      }
    }
  }
  return uStack_4 != 0xffff;
}



/* 3f0b:1bfc */

/* [R2] string "arena" */

bool __cdecl16far attact_textArena2(uint *foundIndexOut,uint16_t partyIndex,uint16_t x)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int unaff_DI;
  undefined2 uVar7;
  uint16_t in_stack_0000000c;
  uint uStack_4;
  
  uStack_4 = 0;
  uVar1 = ovr_alignUp4(unaff_DI,x);
  for (uVar6 = 0; uVar6 < EntityCount; uVar6 = uVar6 + 1) {
    uVar7 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)&((entity_t *)Entities)[uVar6].base.entity + 3) == (char)partyIndex) {
      uVar2 = ovr_alignUp4(unaff_DI,(((entity_t *)Entities + uVar6)->base).x);
      uVar4 = (int)(uVar2 - uVar1) >> 0xf;
      uVar7 = (undefined2)((ulong)Entities >> 0x10);
      uVar3 = ((entity_t *)Entities)[uVar6].base.y - in_stack_0000000c;
      uVar5 = (int)uVar3 >> 0xf;
      uVar2 = ((uVar2 - uVar1 ^ uVar4) - uVar4) + ((uVar3 ^ uVar5) - uVar5) * 2;
      if (((uStack_4 < uVar2) &&
          (uVar3 = ovr_alignUp4(unaff_DI,((entity_t *)Entities)[uVar6].base.destX), uVar3 == uVar1))
         && (((entity_t *)Entities)[uVar6].base.destY == in_stack_0000000c)) {
        *foundIndexOut = uVar6;
        uStack_4 = uVar2;
      }
    }
  }
  return uStack_4 != 0;
}



/* 3f0b:1cfb */

/* [R2] string "arena" */

bool __cdecl16far attact_textArena3(uint *foundIndexOut,uint16_t partyIndex,int x)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int unaff_DI;
  undefined2 uVar7;
  int in_stack_0000000c;
  uint uStack_4;
  
  uStack_4 = 0;
  uVar1 = ovr_alignUp4(unaff_DI,x);
  for (uVar6 = 0; uVar6 < EntityCount; uVar6 = uVar6 + 1) {
    uVar7 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)&((entity_t *)Entities)[uVar6].base.entity + 3) == (char)partyIndex) {
      uVar2 = ovr_alignUp4(unaff_DI,(((entity_t *)Entities + uVar6)->base).x);
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
  int unaff_DI;
  uint uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 unaff_SS;
  uint16_t uStack_8;
  uint16_t uStack_6;
  byte bStack_3;
  
  uVar4 = ovr_alignUp4(unaff_DI,*value);
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
          (uVar5 = ovr_alignUp4(unaff_DI,((entity_t *)Entities)[uStack_6].base.destX),
          uVar5 == uVar4)) && (((entity_t *)Entities)[uStack_6].base.destY == puVar6[1])) {
        uVar7 = uVar7 + 1;
      }
    }
    bStack_3 = ((uint8_t *)MenuItemEnabled)[uVar8];
    if (*(byte *)((int)puVar6 + uVar8 + 0xe) != uVar7) {
      while (((int)uVar7 < (int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) &&
             (bVar3 = attact_textArena((uint16_t *)CONCAT22(unaff_SS,&uStack_6),3,bStack_3,*value,
                                       puVar6[1]), bVar3))) {
        *(undefined1 *)&((entity_t *)Entities)[uStack_6].base.state = 0;
        ((entity_t *)Entities)[uStack_6].base.destX = uStack_8;
        ((entity_t *)Entities)[uStack_6].base.destY = puVar6[1];
        pbVar1 = (byte *)((int)&((entity_t *)Entities)[uStack_6].base.flags32 + 1);
        *pbVar1 = *pbVar1 & 0xfb;
        uVar7 = uVar7 + 1;
      }
      while (((int)uVar7 < (int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) &&
             (bVar3 = attact_textArena((uint16_t *)CONCAT22(unaff_SS,&uStack_6),2,bStack_3,*value,
                                       puVar6[1]), bVar3))) {
        *(undefined1 *)&((entity_t *)Entities)[uStack_6].base.state = 0;
        ((entity_t *)Entities)[uStack_6].base.destX = uStack_8;
        ((entity_t *)Entities)[uStack_6].base.destY = puVar6[1];
        uVar7 = uVar7 + 1;
      }
      while (((int)uVar7 < (int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) &&
             (bVar3 = attact_textArena((uint16_t *)CONCAT22(unaff_SS,&uStack_6),1,bStack_3,*value,
                                       puVar6[1]), bVar3))) {
        *(undefined1 *)&((entity_t *)Entities)[uStack_6].base.state = 0;
        ((entity_t *)Entities)[uStack_6].base.destX = uStack_8;
        ((entity_t *)Entities)[uStack_6].base.destY = puVar6[1];
        uVar7 = uVar7 + 1;
      }
      while (((int)uVar7 < (int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) &&
             (bVar3 = attact_textArena((uint16_t *)CONCAT22(unaff_SS,&uStack_6),0,bStack_3,*value,
                                       puVar6[1]), bVar3))) {
        *(undefined1 *)&((entity_t *)Entities)[uStack_6].base.state = 0;
        ((entity_t *)Entities)[uStack_6].base.destX = uStack_8;
        ((entity_t *)Entities)[uStack_6].base.destY = puVar6[1];
        uVar7 = uVar7 + 1;
      }
      while (((int)(uint)*(byte *)((int)puVar6 + uVar8 + 0xe) < (int)uVar7 &&
             (bVar3 = attact_textArena2((uint *)CONCAT22(unaff_SS,&uStack_6),(uint)bStack_3,*value),
             bVar3))) {
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

undefined2 __cdecl16far attact_usesLDIV_at_(uint8_t menuIndex,...)

{
  long *plVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 unaff_BP;
  ulong uVar4;
  long in_stack_00000000;
  undefined1 in_stack_00000004;
  undefined2 in_stack_0000fffc;
  long a;
  
  a = CONCAT22(unaff_BP,in_stack_0000fffc);
  callResultTemp = func_0x0004f501(0x3f0b);
  if (callResultTemp == 0) {
    uVar4 = 0;
    uVar2 = 0;
  }
  else {
    uVar4 = (ulong)callResultTemp;
    uVar3 = 0;
    plVar1 = LXMUL_at_((long *)0x0,a,in_stack_00000000);
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

void __cdecl16far
attact_compute2(uint16_t menuIndex,far_t pctOut,far_t remainderOut,far_t partOut,...)

{
  int iVar1;
  byte in_stack_00000004;
  
  *(char *)CONCAT22(pctOut.ofs,menuIndex) =
       (char)(((0x1c - (char)((undefined *)&menuCursorY)[in_stack_00000004]) * 100) / 0x1c);
  iVar1 = (int)(char)((undefined *)&menuCursorY)[in_stack_00000004] << 1;
  if (iVar1 == 0) {
    *(undefined1 *)CONCAT22(partOut.ofs,remainderOut.seg) = 0;
    *(undefined1 *)CONCAT22(remainderOut.ofs,pctOut.seg) = 0;
  }
  else {
    *(char *)CONCAT22(partOut.ofs,remainderOut.seg) =
         (char)((int)((100 - (uint)*(byte *)CONCAT22(pctOut.ofs,menuIndex)) *
                     ((int)(char)((undefined *)&menuCursorX)[in_stack_00000004] + iVar1 / 2 + -0x1c)
                     ) / iVar1);
    *(char *)CONCAT22(remainderOut.ofs,pctOut.seg) =
         ('d' - *(char *)CONCAT22(pctOut.ofs,menuIndex)) -
         *(char *)CONCAT22(partOut.ofs,remainderOut.seg);
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
  undefined2 uVar2;
  uint value;
  int iVar3;
  int unaff_DI;
  undefined1 in_stack_0000000c;
  
  uVar2 = 0x3f0b;
  if ((dir & 1) == 0) {
    uVar1 = func_0x0004f32d(0x3f0b,*xPtr,y,dir,in_stack_0000000c);
  }
  else {
    iVar3 = *xPtr;
    do {
      uVar2 = func_0x0004f32d(uVar2,*xPtr,y,dir,in_stack_0000000c);
      if ((char)uVar2 != '\0') {
        return CONCAT11((char)((uint)uVar2 >> 8),1);
      }
      iVar3 = iVar3 + *(char *)(dir + 0x885);
      value = ovr_alignUp4(unaff_DI,*xPtr);
      uVar2 = 0x2379;
      uVar1 = ovr_alignUp4(value,iVar3);
    } while (value == uVar1);
    *xPtr = iVar3;
    uVar1 = uVar1 & 0xff00;
  }
  return uVar1;
}



/* 3f0b:2430 */

/* [R4] calls ovr_randBelow */

void __cdecl16far attact_usesRandBelow(agnt_t *agnt,byte dir,...)

{
  uint16_t uVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_SS;
  int *in_stack_00000004;
  undefined2 in_stack_0000fff6;
  uint16_t n;
  uint8_t agntX;
  int iStack_6;
  int iStack_4;
  
  n = CONCAT11((char)((uint)in_stack_0000fff6 >> 8),
               *(undefined1 *)
                ((int)(char **)GMenuStrings +
                (uint)*(byte *)((int)in_stack_00000004 + 0xd) * 0x95 + 0x1f));
  if ((*(uint8_t *)((uint8_t *)&(agnt) + 2)) == 0xff) {
    uVar1 = ovr_randBelow(n,4);
    (*(uint8_t *)((uint8_t *)&(agnt) + 2)) = (byte)uVar1;
    n = CONCAT11((*(uint8_t *)((uint8_t *)&(agnt) + 2)),(char)n);
    do {
      _agntX = *(int *)CONCAT22((agnt_t *)agnt,in_stack_00000004);
      uVar2 = attact_usesAlignUp44((int *)CONCAT22(unaff_SS,&agntX),in_stack_00000004[1],(*(uint8_t *)((uint8_t *)&(agnt) + 2)))
      ;
      if ((uVar2 & 0xff) == 0) goto L_attact_3f0b_2430_24BF;
      (*(uint8_t *)((uint8_t *)&(agnt) + 2)) = (*(uint8_t *)((uint8_t *)&(agnt) + 2)) + 1 & 3;
    } while ((*(uint8_t *)((uint8_t *)&(agnt) + 2)) != (byte)(n >> 8));
  }
  else {
    _agntX = *(int *)CONCAT22((agnt_t *)agnt,in_stack_00000004);
    (*(uint8_t *)((uint8_t *)&(agnt) + 2)) = (*(uint8_t *)((uint8_t *)&(agnt) + 2)) ^ 2;
L_attact_3f0b_2430_24BF:
    iStack_4 = *(int *)CONCAT22((agnt_t *)agnt,in_stack_00000004);
    iStack_6 = in_stack_00000004[1];
    in_stack_00000004[1] = in_stack_00000004[1] + (int)*(char *)((*(uint8_t *)((uint8_t *)&(agnt) + 2)) + 0x889);
    iVar3 = ovr_ovc23_compute2(in_stack_00000004[1],n,_agntX + *(char *)((*(uint8_t *)((uint8_t *)&(agnt) + 2)) + 0x885));
    *(int *)CONCAT22((agnt_t *)agnt,in_stack_00000004) = iVar3;
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
  uint uVar3;
  int unaff_DI;
  undefined2 uVar4;
  byte bStack_3;
  
  uVar3 = 0;
  do {
    if (EntityCount <= uVar3) {
      return;
    }
    uVar4 = (undefined2)((ulong)Entities >> 0x10);
    uVar4 = ovr_ovc23_isCursorAt
                      (((entity_t *)Entities)[uVar3].base.y,unaff_DI,
                       (((entity_t *)Entities + uVar3)->base).x);
    if ((char)uVar4 != '\0') {
      for (iVar1 = func_0x0004f944(0x236f,uVar3); iVar1 != 0; iVar1 = iVar1 + -1) {
        uVar4 = (undefined2)((ulong)Entities >> 0x10);
        if ((((entity_t *)Entities)[uVar3].base.target & 1) == 0) {
          bStack_3 = 0;
        }
        else {
          bStack_3 = ((entity_t *)Entities)[uVar3].base.target - 2;
        }
        pcVar2 = ovr_ovc15_textArena((uint)bStack_3,uVar3,0);
        if (((uint)pcVar2 & 0xff) == 0) break;
      }
    }
    uVar3 = uVar3 + 1;
  } while( true );
}



/* 3f0b:277b */

/* [R6] touches EntityCount, Entities */

void __cdecl16far attact_usesEntityCount2(uint16_t *sum,uint16_t *enemySum)

{
  uint16_t *puVar1;
  uint uVar2;
  uint uVar3;
  entity_t *peVar4;
  int unaff_SI;
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
                      (((entity_t *)Entities)[uVar5].base.y,unaff_SI,
                       (((entity_t *)Entities + uVar5)->base).x);
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
  uint16_t unaff_SI;
  uint uVar2;
  far_t gfx;
  far_t dst;
  
  mapViewActive = 1;
  uVar2 = GTimeLo;
  if (0xe < GTimeLo) {
    uVar2 = GTimeLo - 0xf;
  }
  if (0xe < uVar2) {
    uVar2 = 0xe;
  }
  iVar1 = (int)(((long)(int)uVar2 * 0xc & 0xffffU) / 0xf);
  dst.seg = unaff_SI;
  dst.ofs = 0xa000;
  gfx.seg = 0xc510;
  gfx.ofs = *(uint16_t *)((int)&timeOfDayGfx[0].seg + iVar1 * 4);
  ovr_blitLoadRleGfx(gfx,dst,((far_t *)timeOfDayGfx + iVar1)->ofs);
  ovr_ovc13_blitAnimFrame();
  return;
}



/* 3f0b:2a09 */

/* [R4] calls LDIV_at_ */

void __cdecl16far attact_usesLDIV_at_2(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  far_t dst_02;
  bool bVar1;
  long *plVar2;
  long *plVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_SI;
  uint uVar6;
  uint16_t unaff_DI;
  int iVar7;
  brect_t *unaff_SS;
  long lVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  uint uVar11;
  long in_stack_0000ffe0;
  uint32_t sum;
  char cStack_17;
  uint8_t rect;
  uint8_t rect2;
  
  uVar9 = SUB21(unaff_SS,0);
  uVar10 = (undefined1)((uint)unaff_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = uVar9;
  dst.ofs = (uint16_t)&rect2;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar10;
  F_SCOPY(far_from_u32((uint32_t)(0x2410088d)),dst);
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = uVar9;
  dst_00.ofs = (uint16_t)&rect;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = uVar10;
  F_SCOPY(far_from_u32((uint32_t)(0x24100897)),dst_00);
  if (GameRunning == false) {
    cStack_17 = MiceNeedsUpdate == '\0';
    bVar1 = ovr_draw_textArena();
    if (bVar1) {
      attact_usesEntityCount2
                ((uint16_t *)CONCAT22(unaff_SS,&sum),
                 (uint16_t *)CONCAT13(uVar10,CONCAT12(uVar9,&stack0xffe0)));
      if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) ||
         ((int)in_stack_0000ffe0 == 0 && (int)((ulong)in_stack_0000ffe0 >> 0x10) == 0)) {
        if (cStack_17 != '\0') {
          ovr_miceRestoreArea((brect_t *)CONCAT22(unaff_DI,unaff_SS),&rect);
        }
        attact_usesBlitLoadRleGfx();
        if (cStack_17 != '\0') {
          ovr_miceBlitRect((brect_t *)CONCAT22(unaff_DI,unaff_SS),&rect);
        }
      }
      else {
        if (mapViewActive != '\0') {
          if (cStack_17 != '\0') {
            ovr_miceRestoreArea((brect_t *)CONCAT22(unaff_DI,unaff_SS),&rect);
          }
          gfx.seg = 0xc510;
          gfx.ofs = nwpanel1Cut5Seg;
          dst_01.seg = unaff_DI;
          dst_01.ofs = 0xa000;
          ovr_blitLoadRleGfx(gfx,dst_01,nwpanel1Cut5Ofs,0);
          gfx_00.seg = 0xc51d;
          gfx_00.ofs = panel01Cut3Seg;
          dst_02.seg = unaff_DI;
          dst_02.ofs = 0xa000;
          ovr_blitLoadRleGfx(gfx_00,dst_02,panel01Cut3Ofs,0);
          if (cStack_17 != '\0') {
            ovr_miceBlitRect((brect_t *)CONCAT22(unaff_DI,unaff_SS),&rect);
          }
        }
        if (cStack_17 != '\0') {
          ovr_miceRestoreArea((brect_t *)CONCAT22(unaff_DI,unaff_SS),&rect2);
        }
        mapViewActive = '\0';
        uVar6 = (uint)in_stack_0000ffe0;
        iVar7 = (int)((ulong)in_stack_0000ffe0 >> 0x10);
        if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) && (uVar6 != 0 || iVar7 != 0)) {
          uVar6 = 0;
        }
        else if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) || (uVar6 != 0 || iVar7 != 0)) {
          iVar4 = uVar6 + (uint)sum;
          plVar2 = (long *)(iVar7 + (*(uint16_t *)((uint8_t *)&(sum) + 2)) + (uint)CARRY2(uVar6,(uint)sum));
          uVar5 = 0;
          plVar3 = LXMUL_at_(plVar2,CONCAT22(unaff_SI,unaff_DI),in_stack_0000ffe0);
          lVar8 = LDIV_at_((long)CONCAT22(uVar5,plVar3),
                           CONCAT13((char)((uint)plVar2 >> 8),CONCAT12((char)plVar2,iVar4)));
          uVar6 = (int)lVar8 + 1;
        }
        else {
          uVar6 = 0x26;
        }
        if (AgntFlag1 != false) {
          attact_usesAgntCount2
                    ((uint16_t *)CONCAT22(unaff_SS,&sum),
                     (uint16_t *)CONCAT13(uVar10,CONCAT12(uVar9,&stack0xffe0)));
          uVar11 = (uint)in_stack_0000ffe0;
          iVar7 = (int)((ulong)in_stack_0000ffe0 >> 0x10);
          if (((uint)sum != 0 || (*(uint16_t *)((uint8_t *)&(sum) + 2)) != 0) || (uVar11 != 0 || iVar7 != 0)) {
            if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) && (uVar11 != 0 || iVar7 != 0)) {
              iVar7 = 0;
            }
            else if (((uint)sum == 0 && (*(uint16_t *)((uint8_t *)&(sum) + 2)) == 0) || (uVar11 != 0 || iVar7 != 0)) {
              iVar4 = uVar11 + (uint)sum;
              plVar2 = (long *)(iVar7 + (*(uint16_t *)((uint8_t *)&(sum) + 2)) + (uint)CARRY2(uVar11,(uint)sum));
              uVar5 = 0;
              plVar3 = LXMUL_at_(plVar2,CONCAT22(unaff_SI,unaff_DI),in_stack_0000ffe0);
              lVar8 = LDIV_at_((long)CONCAT22(uVar5,plVar3),
                               CONCAT13((char)((uint)plVar2 >> 8),CONCAT12((char)plVar2,iVar4)));
              iVar7 = (int)lVar8 + 1;
            }
            else {
              iVar7 = 0x26;
            }
            uVar6 = uVar6 + iVar7 >> 1;
          }
        }
        if (0x9e < 0xc4 - uVar6) {
          ovr_driver_fillRect(0x9f,0xe2,0xc4 - uVar6,0x24,0x0,unaff_DI,0xdf,0);
        }
        if (uVar6 != 0) {
          ovr_driver_fillRect(0xc5 - uVar6,0xe2,0xc4,7,0x0,unaff_DI,0xdf,0);
        }
        if (cStack_17 != '\0') {
          ovr_miceBlitRect((brect_t *)CONCAT22(unaff_DI,unaff_SS),&rect2);
        }
      }
    }
    else {
      if (cStack_17 != '\0') {
        ovr_miceRestoreArea((brect_t *)CONCAT22(unaff_DI,unaff_SS),&rect);
      }
      attact_usesBlitLoadRleGfx();
      if (cStack_17 != '\0') {
        ovr_miceBlitRect((brect_t *)CONCAT22(unaff_DI,unaff_SS),&rect);
      }
    }
  }
  return;
}


