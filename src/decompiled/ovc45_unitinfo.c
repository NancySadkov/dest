/*
 * ovc45_unitinfo.c - recovered from STRONG.EXE
 * memory block: OVC45_unitinfo.c
 * range: 77eb:0000 - 77eb:26bf
 * functions: 29
 */
#include "recovered.h"


/* 77eb:0121 */

/* Returns the bldType of the unit in GUnitGrid[x][y], or 0 outside the map. */

byte __cdecl16far ovc45_getUnitType(int x,int y,...)

{
  byte bVar1;
  
  if ((((x < 0x94) && (-1 < x)) && (y < 0x3c)) && (-1 < y)) {
    bVar1 = ((unit_t *)GUnits + (*(short (*) [148] [60])GUnitGrid)[x][y])->bldType;
  }
  else {
    bVar1 = 0;
  }
  return bVar1;
}



/* 77eb:0179 */

/* Returns GUnitGrid[x][y] (the unit index) inside the map bounds, else 0. */

short __cdecl16far ovc45_getUnitIndex(int x,int y,...)

{
  short sVar1;
  
  if ((((x < 0x94) && (-1 < x)) && (y < 0x3c)) && (-1 < y)) {
    sVar1 = (*(short (*) [148] [60])GUnitGrid)[x][y];
  }
  else {
    sVar1 = 0;
  }
  return sVar1;
}



/* 77eb:01bb */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

uint __cdecl16far ovc45_usesAlignUp4(int slotMin,int x,uint16_t y,uint *entityIndexOut)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  uint *in_stack_0000000a;
  byte bStack_3;
  
  bStack_3 = 0xff;
  for (uVar3 = 0; uVar3 < EntityCount; uVar3 = uVar3 + 1) {
    uVar1 = ovr_alignUp4(*(int *)((int)Entities + uVar3 * 0x37));
    if (uVar1 == x) {
      uVar4 = (undefined2)((ulong)Entities >> 0x10);
      iVar2 = (int)Entities;
      if ((((*(uint16_t *)(iVar2 + uVar3 * 0x37 + 2) == y) &&
           (*(char *)((int)(char **)GMenuStrings +
                     (uint)*(byte *)(iVar2 + uVar3 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0')) &&
          (slotMin < (int)(uint)*(byte *)(iVar2 + uVar3 * 0x37 + 0x1a))) &&
         (*(byte *)(iVar2 + uVar3 * 0x37 + 0x1a) < bStack_3)) {
        bStack_3 = *(byte *)(iVar2 + uVar3 * 0x37 + 0x1a);
        *(uint *)CONCAT22((uint *)entityIndexOut,in_stack_0000000a) = uVar3;
      }
    }
  }
  if (bStack_3 == 0xff) {
    uVar3 = 0xffff;
  }
  else {
    uVar3 = (uint)bStack_3;
  }
  return uVar3;
}



/* 77eb:02c1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Finds the entity at (x,y) and writes its index and a found flag through the out pointers. */

char * __cdecl16far
ovc45_findEntityAt(uint16_t x,uint16_t y,uint *foundIndex,uint8_t *foundFlagOut,char foundFlag,...)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined1 uStack000f;
  char in_stack_00000010;
  uint uStack_6;
  uint uStack_4;
  
  *(undefined1 *)CONCAT13(uStack000f,CONCAT12(foundFlag,foundFlagOut._2_2_)) = 0;
  uVar1 = ovr_alignUp4(x);
  *(uint *)CONCAT22((uint8_t *)foundFlagOut,foundIndex) = 0xffff;
  uStack_6 = 0xffff;
  uVar5 = 0xffff;
  uStack_4 = 0xffff;
  for (uVar4 = 0; uVar4 < EntityCount; uVar4 = uVar4 + 1) {
    uVar2 = ovr_alignUp4(*(int *)((int)Entities + uVar4 * 0x37));
    if (uVar2 == uVar1) {
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      iVar3 = (int)Entities;
      if (*(uint16_t *)(iVar3 + uVar4 * 0x37 + 2) == y) {
        uVar2 = (uint)*(byte *)(iVar3 + uVar4 * 0x37 + 0xd) * 0x95;
        if (*(char *)((int)(char **)GMenuStrings + uVar2 + 0x1f) != '\0') {
          return (char *)(uVar2 & 0xff00);
        }
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 +
                      (uint)*(byte *)(iVar3 + uVar4 * 0x37 + 0xd) * 0x95) != -1) &&
           (*(char *)(iVar3 + uVar4 * 0x37 + 0x1a) != -1)) {
          if (*(char *)(iVar3 + uVar4 * 0x37 + 0x1a) == in_stack_00000010) {
            *(uint *)CONCAT22((uint8_t *)foundFlagOut,foundIndex) = uVar4;
          }
          else if (*(char *)(iVar3 + uVar4 * 0x37 + 0x1a) == selectedPartyIndex) {
            uStack_6 = uVar4;
          }
          if ((uStack_4 != 0xffff) && (*(byte *)((int)Entities + uVar4 * 0x37 + 0x1a) != uStack_4))
          {
            *(undefined1 *)CONCAT13(uStack000f,CONCAT12(foundFlag,foundFlagOut._2_2_)) = 1;
          }
          uStack_4 = (uint)*(byte *)((int)Entities + uVar4 * 0x37 + 0x1a);
          uVar5 = uVar4;
        }
      }
    }
  }
  if (*(uint *)CONCAT22((uint8_t *)foundFlagOut,foundIndex) == 0xffff) {
    if (uStack_6 == 0xffff) {
      if (uVar5 == 0xffff) {
        return (char *)"arena" + 4;
      }
      *(uint *)CONCAT22((uint8_t *)foundFlagOut,foundIndex) = uVar5;
    }
    else {
      *(uint *)CONCAT22((uint8_t *)foundFlagOut,foundIndex) = uStack_6;
    }
  }
  uVar6 = (undefined2)((ulong)Entities >> 0x10);
  iVar3 = (uint)*(byte *)((int)Entities +
                          *(uint *)CONCAT22((uint8_t *)foundFlagOut,foundIndex) * 0x37 + 0xd) * 0x95
  ;
  selectedPartyIndex =
       *(undefined1 *)
        ((int)Entities + *(uint *)CONCAT22((uint8_t *)foundFlagOut,foundIndex) * 0x37 + 0x1a);
  return (char *)CONCAT11((char)((uint)iVar3 >> 8),
                          '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 + iVar3) & 0x1f));
}



/* 77eb:04d8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R2] string "Choose party to build for.  Now building" */

undefined2 __cdecl16far ovc45_textChoosePartyBuild(uint16_t x,uint16_t y,int *entityIndexPtr,...)

{
  far_t entries;
  far_t hint;
  uint x_00;
  int iVar1;
  undefined2 *puVar2;
  char *pcVar3;
  uint8_t *puVar4;
  undefined2 uVar5;
  uint16_t count;
  undefined2 unaff_DI;
  uint slotMin;
  uint *unaff_SS;
  undefined2 in_stack_0000000a;
  uint8_t foundEntities;
  uint8_t menuItems;
  int aiStack_2c [19];
  uint8_t entityIndex;
  char cStack_3;
  
  x_00 = ovr_alignUp4(x);
  entityIndex = *entityIndexPtr;
  slotMin = 0xffff;
  for (count = 0; (int)count < 10; count = count + 1) {
    slotMin = ovc45_usesAlignUp4(slotMin,x_00,y,(uint *)CONCAT22(unaff_DI,unaff_SS));
    if (slotMin == 0xffff) break;
    *(int *)(&foundEntities + count * 2) = entityIndex;
    uVar5 = *(undefined2 *)(slotMin * 4);
    aiStack_2c[count * 2] = ((undefined2 *)(slotMin * 4))[1];
    *(undefined2 *)(&menuItems + count * 4) = uVar5;
  }
  if ((int)count < 2) {
    *entityIndexPtr = entityIndex;
    iVar1 = (uint)*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0xd) * 0x95;
    uVar5 = CONCAT11((char)((uint)iVar1 >> 8),
                     '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 + iVar1) & 0x1f));
  }
  else {
    ovr_ovc22_className(*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0x1a));
    puVar2 = (undefined2 *)((uint)*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0x1a) * 4);
    uVar5 = 0x217a;
    pcVar3 = ovr_fmVsprintf("Choose party to build for.  Now building for %s the %s.",
                            (char *)CONCAT22(puVar2[1],(char *)*puVar2));
    puVar4 = &menuItems;
    entries.seg = (uint16_t)unaff_SS;
    entries.ofs = (uint16_t)puVar4;
    hint.seg._0_1_ = (char)uVar5;
    hint.ofs = (uint16_t)pcVar3;
    hint.seg._1_1_ = (char)((uint)uVar5 >> 8);
    ovr_ovc28_compute2(entries,count,hint);
    cStack_3 = (char)puVar4;
    if ((char)puVar4 == '\0') {
      uVar5 = 0xff;
    }
    else {
      *entityIndexPtr = aiStack_2c[((uint)puVar4 & 0xff) - 0xc];
      uVar5 = (undefined2)((ulong)Entities >> 0x10);
      selectedPartyIndex = *(undefined1 *)((int)Entities + *entityIndexPtr * 0x37 + 0x1a);
      iVar1 = (uint)*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0xd) * 0x95;
      uVar5 = CONCAT11((char)((uint)iVar1 >> 8),
                       '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 + iVar1) & 0x1f));
    }
  }
  return uVar5;
}



/* 77eb:0683 */

/* [R6] touches GMapFlags, GUnits */

int __cdecl16far ovc45_usesGMapFlags(int x,int y)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  byte bVar4;
  
  psVar1 = (*(short (*) [60] [148])GMapFlags)[y] + x;
  if ((psVar1[0x94] & 3U) == 0) {
    sVar2 = ovc45_getUnitIndex(x,y);
    iVar3 = (uint)((unit_t *)GUnits + sVar2)->bldType * 0x27;
    bVar4 = (byte)((uint)iVar3 >> 8);
    if ((*(uint *)(iVar3 + 0x121) & 0x18) == 0) {
      iVar3 = (uint)bVar4 << 8;
    }
    else {
      iVar3 = CONCAT11(bVar4,1);
    }
  }
  else {
    iVar3 = CONCAT11((char)((uint)psVar1 >> 8),1);
  }
  return iVar3;
}



/* 77eb:0708 */

/* [R6] touches GMapFlags */

bool __cdecl16far ovc45_usesGMapFlags2(int x,int y)

{
  return ((*(short (*) [60] [148])GMapFlags)[y + 1][x] & 3U) == 3;
}



/* 77eb:0742 */

/* Returns whether the map cell directly below (x,y) has either of its low two flag bits set. */

int __cdecl16far ovc45_cellBelowBlocked(int x,int y)

{
  short *psVar1;
  byte bVar3;
  int iVar2;
  
  psVar1 = (*(short (*) [60] [148])GMapFlags)[y] + x;
  bVar3 = (byte)((uint)psVar1 >> 8);
  if ((psVar1[0x94] & 3U) == 0) {
    iVar2 = (uint)bVar3 << 8;
  }
  else {
    iVar2 = CONCAT11(bVar3,1);
  }
  return iVar2;
}



/* 77eb:0778 */

/* [R7] body shape: compute */

uint __cdecl16far ovc45_compute1(byte bldType,int x,int y)

{
  bool bVar1;
  byte extraout_AH;
  uint uVar2;
  byte extraout_AH_00;
  
  if ((*(uint *)((uint)bldType * 0x27 + 0x121) & 0x10) != 0) {
    uVar2 = ovc45_usesGMapFlags(x,y + 1);
    if ((((uVar2 & 0xff) == 0) && (uVar2 = ovc45_usesGMapFlags(x,y), (uVar2 & 0xff) == 0)) &&
       (uVar2 = ovc45_usesGMapFlags(x,y + -1), (uVar2 & 0xff) == 0)) {
      return 0;
    }
    bVar1 = ovc45_usesGMapFlags2(x,y + 1);
    if (((bVar1) && (bVar1 = ovc45_usesGMapFlags2(x,y), bVar1)) &&
       (bVar1 = ovc45_usesGMapFlags2(x,y + -1), bVar1)) {
      return (uint)extraout_AH << 8;
    }
    uVar2 = ovc45_cellBelowBlocked(x,y + 1);
    if ((((uVar2 & 0xff) == 0) && (uVar2 = ovc45_cellBelowBlocked(x,y), (uVar2 & 0xff) == 0)) &&
       (uVar2 = ovc45_cellBelowBlocked(x,y + -1), (uVar2 & 0xff) == 0)) {
      return 0;
    }
  }
  uVar2 = (uint)bldType * 0x27;
  if ((*(uint *)(uVar2 + 0x121) & 8) != 0) {
    uVar2 = ovc45_usesGMapFlags(x,y);
    if ((((uVar2 & 0xff) == 0) && (uVar2 = ovc45_usesGMapFlags(x + -1,y), (uVar2 & 0xff) == 0)) &&
       (uVar2 = ovc45_usesGMapFlags(x + 1,y), (uVar2 & 0xff) == 0)) {
      return 0;
    }
    bVar1 =