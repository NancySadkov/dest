/*
 * ovc45_unitinfo.c - recovered from STRONG.EXE
 * memory block: OVC45_unitinfo.c
 * range: 77eb:0000 - 77eb:26bf
 * functions: 29
 */
#include "recovered.h"


/* 77eb:0121 */

/* Returns the bldType of the unit in GUnitGrid[x][y], or 0 outside the map. */

byte __cdecl16far ovc45_getUnitType(int x,int y)

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

short __cdecl16far ovc45_getUnitIndex(int x,int y)

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
  uint16_t uVar4;
  uint *in_stack_0000000a;
  byte bStack_3;
  
  bStack_3 = 0xff;
  for (uVar3 = 0; uVar3 < EntityCount; uVar3 = uVar3 + 1) {
    uVar1 = ovr_alignUp4(*(int *)((int)Entities + uVar3 * 0x37),0,0);
    if (uVar1 == x) {
      uVar4 = (uint16_t)((ulong)Entities >> 0x10);
      iVar2 = (int)Entities;
      if ((((((entity_t *)iVar2)[uVar3].base.y == y) &&
           (*(char *)((int)(char **)GMenuStrings +
                     (uint)((entity_t *)iVar2)[uVar3].base.gindex * 0x95 + 0x1f) == '\0')) &&
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
ovc45_findEntityAt(uint16_t x,uint16_t y,uint *foundIndex,uint8_t *foundFlagOut,char foundFlag)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint16_t uVar6;
  undefined1 uStack000f;
  char in_stack_00000010;
  uint uStack_6;
  uint uStack_4;
  
  *(undefined1 *)CONCAT13(uStack000f,CONCAT12(foundFlag,(*(uint16_t *)((uint8_t *)&(foundFlagOut) + 2)))) = 0;
  uVar1 = ovr_alignUp4(x,0,0);
  *(uint *)CONCAT22((uint8_t *)foundFlagOut,foundIndex) = 0xffff;
  uStack_6 = 0xffff;
  uVar5 = 0xffff;
  uStack_4 = 0xffff;
  for (uVar4 = 0; uVar4 < EntityCount; uVar4 = uVar4 + 1) {
    uVar2 = ovr_alignUp4(*(int *)((int)Entities + uVar4 * 0x37),0,0);
    if (uVar2 == uVar1) {
      uVar6 = (uint16_t)((ulong)Entities >> 0x10);
      iVar3 = (int)Entities;
      if (((entity_t *)iVar3)[uVar4].base.y == y) {
        uVar2 = (uint)((entity_t *)iVar3)[uVar4].base.gindex * 0x95;
        if (*(char *)((int)(char **)GMenuStrings + uVar2 + 0x1f) != '\0') {
          return (char *)(uVar2 & 0xff00);
        }
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 +
                      (uint)((entity_t *)iVar3)[uVar4].base.gindex * 0x95) != -1) &&
           (*(char *)(iVar3 + uVar4 * 0x37 + 0x1a) != -1)) {
          if (*(char *)(iVar3 + uVar4 * 0x37 + 0x1a) == in_stack_00000010) {
            *(uint *)CONCAT22((uint8_t *)foundFlagOut,foundIndex) = uVar4;
          }
          else if (*(char *)(iVar3 + uVar4 * 0x37 + 0x1a) == selectedPartyIndex) {
            uStack_6 = uVar4;
          }
          if ((uStack_4 != 0xffff) && (*(byte *)((int)Entities + uVar4 * 0x37 + 0x1a) != uStack_4))
          {
            *(undefined1 *)CONCAT13(uStack000f,CONCAT12(foundFlag,(*(uint16_t *)((uint8_t *)&(foundFlagOut) + 2)))) = 1;
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
        return (char *)0x2400;
      }
      *(uint *)CONCAT22((uint8_t *)foundFlagOut,foundIndex) = uVar5;
    }
    else {
      *(uint *)CONCAT22((uint8_t *)foundFlagOut,foundIndex) = uStack_6;
    }
  }
  uVar6 = (uint16_t)((ulong)Entities >> 0x10);
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

uint16_t __cdecl16far ovc45_textChoosePartyBuild(uint16_t x,uint16_t y,int *entityIndexPtr,uint16_t arg4)

{
  far_t entries;
  far_t hint;
  uint x_00;
  int iVar1;
  uint16_t *puVar2;
  char *pcVar3;
  uint8_t *puVar4;
  uint16_t uVar5;
  uint16_t count;
  uint16_t unaff_DI;
  uint slotMin;
  uint *unaff_SS;
  uint16_t in_stack_0000000a;
  uint8_t foundEntities;
  uint8_t menuItems;
  int aiStack_2c [19];
  uint8_t entityIndex;
  char cStack_3;
  
  x_00 = ovr_alignUp4(x,0,0);
  entityIndex = *entityIndexPtr;
  slotMin = 0xffff;
  for (count = 0; (int)count < 10; count = count + 1) {
    slotMin = ovc45_usesAlignUp4(slotMin,x_00,y,(uint *)CONCAT22(unaff_DI,unaff_SS));
    if (slotMin == 0xffff) break;
    *(int *)(&foundEntities + count * 2) = entityIndex;
    uVar5 = *(uint16_t *)(slotMin * 4);
    aiStack_2c[count * 2] = ((uint16_t *)(slotMin * 4))[1];
    *(uint16_t *)(&menuItems + count * 4) = uVar5;
  }
  if ((int)count < 2) {
    *entityIndexPtr = entityIndex;
    iVar1 = (uint)*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0xd) * 0x95;
    uVar5 = CONCAT11((char)((uint)iVar1 >> 8),
                     '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 + iVar1) & 0x1f));
  }
  else {
    ovr_ovc22_className(*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0x1a),0);
    puVar2 = (uint16_t *)((uint)*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0x1a) * 4);
    uVar5 = 0x217a;
    pcVar3 = ovr_fmVsprintf("Choose party to build for.  Now building for %s the %s.",
                            (char *)CONCAT22(puVar2[1],(char *)*puVar2));
    puVar4 = &menuItems;
    entries.seg = (uint16_t)unaff_SS;
    entries.ofs = (uint16_t)puVar4;
    (*(uint8_t *)((uint8_t *)&(hint.seg))) = (char)uVar5;
    hint.ofs = (uint16_t)pcVar3;
    (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = (char)((uint)uVar5 >> 8);
    ovr_ovc28_compute2(entries,count,hint,0,0);
    cStack_3 = (char)puVar4;
    if ((char)puVar4 == '\0') {
      uVar5 = 0xff;
    }
    else {
      *entityIndexPtr = aiStack_2c[((uint)puVar4 & 0xff) - 0xc];
      uVar5 = (uint16_t)((ulong)Entities >> 0x10);
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
    bVar1 = ovc45_usesGMapFlags2(x,y);
    if (((bVar1) && (bVar1 = ovc45_usesGMapFlags2(x + -1,y), bVar1)) &&
       (bVar1 = ovc45_usesGMapFlags2(x + 1,y), bVar1)) {
      return (uint)extraout_AH_00 << 8;
    }
    uVar2 = ovc45_cellBelowBlocked(x,y);
    uVar2 = uVar2 & 0xff;
    if (uVar2 == 0) {
      uVar2 = ovc45_cellBelowBlocked(x + -1,y);
      uVar2 = uVar2 & 0xff;
      if (uVar2 == 0) {
        uVar2 = ovc45_cellBelowBlocked(x + 1,y);
        uVar2 = uVar2 & 0xff;
        if (uVar2 == 0) {
          return 0;
        }
      }
    }
  }
  return CONCAT11((char)(uVar2 >> 8),1);
}



/* 77eb:0904 */

/* [R4] calls LDIV_at_ */

uint16_t __cdecl16far ovc45_usesLDIV_at_(uint8_t partyIndex,uint16_t arg2,uint16_t arg3)

{
  long *plVar1;
  uint16_t uVar2;
  uint unaff_SI;
  long lVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  long in_stack_0000fffa;
  
  uVar5 = 0;
  uVar4 = 10;
  uVar2 = GPopulationHi;
  plVar1 = LXMUL_at_((long *)((byte *)__C0_ASM_CopyRight + 6),(ulong)unaff_SI << 0x10,
                     in_stack_0000fffa);
  lVar3 = LDIV_at_((long)CONCAT22(uVar2,plVar1),CONCAT22(uVar5,uVar4));
  return (int)lVar3;
}



/* 77eb:0976 */

/* Returns the leader's rank as a percentage (rank*10, capped at 100). */

int __cdecl16far ovc45_rankPercent(byte partyIndex)

{
  int iVar1;
  
  if (((char_sheet_t *)(((uint)partyIndex << 2)))->rank < 0xb) {
    iVar1 = ((char_sheet_t *)(((uint)partyIndex << 2)))->rank * 10;
  }
  else {
    iVar1 = 100;
  }
  return iVar1;
}



/* 77eb:09c1 */

/* [R7] body shape: compute */

int __cdecl16far ovc45_compute3(byte partyIndex)

{
  int iVar1;
  uint16_t uVar2;
  int iVar3;
  
  uVar2 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
  iVar1 = (int)*(uint32_t *)((uint)partyIndex << 2);
  iVar3 = *(int *)(iVar1 + 0x56);
  iVar1 = ovc45_usesLDIV_at_(partyIndex,iVar3,*(uint16_t *)(iVar1 + 0x58));
  return iVar3 + iVar1;
}



/* 77eb:0a02 */

/* [R6] touches GPopulationLo, GPopulationHi */

void __cdecl16far ovc45_usesGPopulationLo(byte partyIndex,uint goldLo,int goldHi)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint16_t uVar8;
  bool bVar9;
  
  uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
  iVar5 = (int)*(uint32_t *)((uint)partyIndex << 2);
  iVar6 = *(int *)(iVar5 + 0x58);
  if ((iVar6 < goldHi) || ((iVar6 == goldHi && (*(uint *)(iVar5 + 0x56) < goldLo)))) {
    uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
    iVar6 = (int)*(uint32_t *)((uint)partyIndex << 2);
    uVar4 = *(uint *)(iVar6 + 0x56);
    uVar3 = goldLo - uVar4;
    iVar6 = (goldHi - *(int *)(iVar6 + 0x58)) - (uint)(goldLo < uVar4);
    iVar5 = 0x217a;
    uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
    iVar7 = (int)*(uint32_t *)((uint)partyIndex << 2);
    *(uint16_t *)(iVar7 + 0x58) = 0;
    *(uint16_t *)(iVar7 + 0x56) = 0;
    uVar4 = ovc45_usesLDIV_at_(partyIndex,0,0);
    if ((iVar6 < iVar5) || ((iVar6 == iVar5 && (uVar3 < uVar4)))) {
      bVar9 = GPopulationLo < uVar3;
      GPopulationLo = GPopulationLo - uVar3;
      GPopulationHi = (GPopulationHi - iVar6) - (uint)bVar9;
    }
    else {
      bVar9 = GPopulationLo < uVar4;
      GPopulationLo = GPopulationLo - uVar4;
      GPopulationHi = (GPopulationHi - iVar5) - (uint)bVar9;
    }
  }
  else {
    uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
    iVar6 = (int)*(uint32_t *)((uint)partyIndex << 2);
    puVar1 = (uint *)(iVar6 + 0x56);
    uVar3 = *puVar1;
    *puVar1 = *puVar1 - goldLo;
    piVar2 = (int *)(iVar6 + 0x58);
    *piVar2 = (*piVar2 - goldHi) - (uint)(uVar3 < goldLo);
  }
  return;
}



/* 77eb:0aea */

/* [R7] body shape: compute */

uint __cdecl16far ovc45_compute4(int x,uint16_t y,uint16_t arg3)

{
  byte bVar1;
  uint uVar2;
  byte extraout_AH;
  byte bVar3;
  
  uVar2 = ovr_constr_usesGMapFlags(x,y,0);
  if ((uVar2 & 0xff) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ovr_ovc23_findRecordAt(x,y,0);
    if (uVar2 == 0xffff) {
      bVar1 = ovc45_getUnitType(x,y);
      if (CONCAT11(extraout_AH,bVar1) == 0) {
        bVar1 = ovc45_getUnitType(x + -1,y);
        if (*(byte *)((uint)bVar1 * 0x27 + 0x11b) < 2) {
          bVar1 = ovc45_getUnitType(x + -2,y);
          if (*(byte *)((uint)bVar1 * 0x27 + 0x11b) < 3) {
            bVar1 = ovc45_getUnitType(x + -3,y);
            bVar3 = (byte)((uint)bVar1 * 0x27 >> 8);
            if (*(byte *)((uint)bVar1 * 0x27 + 0x11b) < 4) {
              uVar2 = CONCAT11(bVar3,1);
            }
            else {
              uVar2 = (uint)bVar3 << 8;
            }
          }
          else {
            uVar2 = (uint)bVar1 * 0x27 & 0xff00;
          }
        }
        else {
          uVar2 = (uint)bVar1 * 0x27 & 0xff00;
        }
      }
      else {
        uVar2 = (uint)extraout_AH << 8;
      }
    }
    else {
      uVar2 = uVar2 & 0xff00;
    }
  }
  return uVar2;
}



/* 77eb:0bc1 */

/* [R7] body shape: compute */

uint __cdecl16far ovc45_compute5(void)

{
  uint32_t uVar1;
  byte bVar2;
  byte extraout_AH;
  uint uVar3;
  
  bVar2 = ovr_manage_findFirstLeader();
  if (bVar2 == 0xff) {
    uVar3 = (uint)extraout_AH << 8;
  }
  else {
    uVar1 = *(uint32_t *)((uint)bVar2 << 2);
    if (*(byte *)((int)uVar1 + 0x86) < 4) {
      uVar3 = CONCAT11((char)(((uint)bVar2 << 2) >> 8),4);
    }
    else if (((char_sheet_t *)(((uint)bVar2 << 2)))->titleIndex < 9) {
      uVar1 = *(uint32_t *)((uint)bVar2 << 2);
      uVar3 = CONCAT11((char)(((uint)bVar2 << 2) >> 8),*(char *)((int)uVar1 + 0x86) + '\x01');
    }
    else {
      uVar3 = (uint)(bVar2 >> 6) << 8;
    }
  }
  return uVar3;
}



/* 77eb:0c36 */

/* [R2] string "arena" */

bool __cdecl16far ovc45_textArena2(byte bldType)

{
  byte bVar1;
  uint32_t uVar2;
  uint uVar3;
  uint16_t uVar4;
  
  if (*(char *)((uint)bldType * 0x27 + 0x133) == '\x17') {
    for (uVar3 = 0xf8; uVar3 < GUnitCount; uVar3 = uVar3 + 1) {
      uVar4 = (uint16_t)((ulong)GUnits >> 0x10);
      bVar1 = ((unit_t *)GUnits)[uVar3].unitType;
      if (((*(char *)((uint)((unit_t *)GUnits + uVar3)->bldType * 0x27 + 0x133) == '\x17') &&
          (bVar1 != 0xff)) &&
         (uVar2 = *(uint32_t *)((uint)bVar1 << 2), *(char *)((int)uVar2 + 0x3f) == '\0')) {
        return true;
      }
    }
    for (uVar3 = 0; uVar3 < GRecordCount; uVar3 = uVar3 + 1) {
      bVar1 = *(byte *)(uVar3 * 0x12 + 9);
      if (((*(char *)((uint)*(byte *)(uVar3 * 0x12 + 8) * 0x27 + 0x133) == '\x17') &&
          (bVar1 != 0xff)) &&
         (uVar2 = *(uint32_t *)((uint)bVar1 << 2), *(char *)((int)uVar2 + 0x3f) == '\0')) {
        return true;
      }
    }
  }
  return false;
}



/* 77eb:0d61 */
uint __cdecl16far
ovc45_buildPlacementMessage
          (uint x,uint16_t y,int entityIndex,uint16_t reserved,char flag)

{
  undefined1 stk_fc0c;   /* stack slot fc0c */
  undefined1 stk_fc0e;   /* stack slot fc0e */
  undefined1 stk_fff5;   /* stack slot fff5 */
  undefined1 stk_fffe;   /* stack slot fffe */
  long lVar1;
  far_t entries;
  far_t pixels;
  far_t pixels_00;
  far_t pixels_01;
  far_t pixels_02;
  far_t pixels_03;
  far_t pixels_04;
  far_t pixels_05;
  far_t pixels_06;
  far_t pixels_07;
  far_t pixels_08;
  far_t pixels_09;
  far_t pixels_10;
  far_t pixels_11;
  far_t pixels_12;
  far_t pixels_13;
  far_t pixels_14;
  far_t pixels_15;
  far_t pixels_16;
  far_t pixels_17;
  far_t pixels_18;
  far_t pixels_19;
  far_t pixels_20;
  far_t pixels_21;
  far_t pixels_22;
  far_t pixels_23;
  far_t pixels_24;
  far_t pixels_25;
  far_t pixels_26;
  far_t pixels_27;
  far_t pixels_28;
  far_t pixels_29;
  far_t pixels_30;
  far_t pixels_31;
  far_t pixels_32;
  far_t pixels_33;
  far_t pixels_34;
  far_t pixels_35;
  far_t pixels_36;
  far_t pixels_37;
  far_t pixels_38;
  far_t pixels_39;
  far_t pixels_40;
  far_t pixels_41;
  far_t pixels_42;
  far_t pixels_43;
  far_t pixels_44;
  far_t pixels_45;
  far_t pixels_46;
  far_t pixels_47;
  far_t pixels_48;
  far_t pixels_49;
  far_t pixels_50;
  far_t pixels_51;
  far_t pixels_52;
  far_t pixels_53;
  far_t pixels_54;
  far_t pixels_55;
  far_t pixels_56;
  far_t pixels_57;
  far_t pixels_58;
  far_t pixels_59;
  far_t pixels_60;
  far_t pixels_61;
  far_t pixels_62;
  far_t pixels_63;
  far_t pixels_64;
  far_t pixels_65;
  far_t pixels_66;
  far_t pixels_67;
  far_t pixels_68;
  far_t pixels_69;
  far_t pixels_70;
  far_t pixels_71;
  far_t pixels_72;
  far_t pixels_73;
  far_t pixels_74;
  far_t pixels_75;
  far_t pixels_76;
  far_t pixels_77;
  far_t pixels_78;
  far_t pixels_79;
  far_t pixels_80;
  far_t pixels_81;
  far_t pixels_82;
  far_t pixels_83;
  far_t pixels_84;
  far_t pixels_85;
  far_t pixels_86;
  far_t pixels_87;
  far_t pixels_88;
  far_t pixels_89;
  far_t pixels_90;
  far_t pixels_91;
  far_t pixels_92;
  far_t pixels_93;
  far_t pixels_94;
  far_t pixels_95;
  far_t pixels_96;
  far_t pixels_97;
  far_t pixels_98;
  far_t pixels_99;
  far_t pixels_x00100;
  far_t pixels_x00101;
  far_t pixels_x00102;
  far_t pixels_x00103;
  far_t pixels_x00104;
  far_t pixels_x00105;
  far_t pixels_x00106;
  far_t pixels_x00107;
  far_t pixels_x00108;
  far_t pixels_x00109;
  far_t pixels_x00110;
  far_t pixels_x00111;
  far_t pixels_x00112;
  far_t pixels_x00113;
  far_t pixels_x00114;
  far_t pixels_x00115;
  far_t pixels_x00116;
  far_t pixels_x00117;
  far_t pixels_x00118;
  far_t pixels_x00119;
  far_t pixels_x00120;
  far_t pixels_x00121;
  far_t pixels_x00122;
  far_t pixels_x00123;
  far_t pixels_x00124;
  far_t pixels_x00125;
  far_t pixels_x00126;
  far_t pixels_x00127;
  far_t pixels_x00128;
  far_t pixels_x00129;
  far_t pixels_x00130;
  far_t pixels_x00131;
  far_t pixels_x00132;
  far_t pixels_x00133;
  far_t pixels_x00134;
  far_t pixels_x00135;
  far_t pixels_x00136;
  far_t pixels_x00137;
  far_t pixels_x00138;
  far_t pixels_x00139;
  far_t pixels_x00140;
  far_t pixels_x00141;
  far_t pixels_x00142;
  far_t pixels_x00143;
  far_t pixels_x00144;
  far_t pixels_x00145;
  far_t pixels_x00146;
  far_t pixels_x00147;
  far_t pixels_x00148;
  far_t pixels_x00149;
  far_t pixels_x00150;
  far_t pixels_x00151;
  far_t pixels_x00152;
  far_t pixels_x00153;
  far_t pixels_x00154;
  far_t pixels_x00155;
  far_t pixels_x00156;
  far_t pixels_x00157;
  far_t pixels_x00158;
  far_t pixels_x00159;
  far_t pixels_x00160;
  far_t pixels_x00161;
  far_t pixels_x00162;
  far_t pixels_x00163;
  far_t pixels_x00164;
  far_t pixels_x00165;
  far_t pixels_x00166;
  far_t pixels_x00167;
  far_t pixels_x00168;
  far_t pixels_x00169;
  far_t pixels_x00170;
  far_t pixels_x00171;
  far_t pixels_x00172;
  far_t pixels_x00173;
  far_t pixels_x00174;
  far_t pixels_x00175;
  far_t pixels_x00176;
  far_t pixels_x00177;
  far_t pixels_x00178;
  far_t pixels_x00179;
  far_t pixels_x00180;
  far_t pixels_x00181;
  far_t pixels_x00182;
  far_t pixels_x00183;
  far_t pixels_x00184;
  far_t pixels_x00185;
  far_t pixels_x00186;
  far_t pixels_x00187;
  far_t pixels_x00188;
  far_t pixels_x00189;
  far_t pixels_x00190;
  far_t pixels_x00191;
  far_t pixels_x00192;
  far_t pixels_x00193;
  far_t pixels_x00194;
  far_t pixels_x00195;
  far_t pixels_x00196;
  far_t pixels_x00197;
  far_t pixels_x00198;
  far_t pixels_x00199;
  far_t src;
  far_t src_00;
  far_t src_01;
  far_t src_02;
  far_t src_03;
  far_t src_04;
  far_t src_05;
  far_t src_06;
  far_t src_07;
  far_t src_08;
  far_t src_09;
  far_t src_10;
  far_t src_11;
  far_t src_12;
  far_t src_13;
  far_t src_14;
  far_t src_15;
  far_t src_16;
  far_t src_17;
  far_t src_18;
  far_t src_19;
  far_t src_20;
  far_t src_21;
  far_t src_22;
  far_t src_23;
  far_t src_24;
  far_t src_25;
  far_t hint;
  far_t pixels_x00200;
  far_t buf;
  DW sz;
  far_t fVar2;
  bool bVar3;
  stg_tmp_t *psVar4;
  far_t far *pfVar5;
  cte_t *pcVar6;
  int iVar7;
  long *plVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  size_t sVar12;
  undefined1 *puVar13;
  uint16_t uVar14;
  uint8_t *puVar15;
  uint16_t uVar16;
  uint16_t *puVar17;
  uint16_t unaff_SI;
  int iVar18;
  uint16_t uVar19;
  int unaff_DI;
  uint16_t uVar20;
  uint16_t uVar21;
  char *unaff_SS;
  uint32_t uVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  undefined1 uVar25;
  undefined1 uVar26;
  undefined1 uVar27;
  bool grab;
  undefined1 uVar28;
  undefined1 uVar29;
  undefined1 uVar30;
  undefined1 uVar31;
  undefined1 in_stack_0000fc0c;
  undefined1 in_stack_0000fc0d;
  long *in_stack_0000fc0e;
  long in_stack_0000fc10;
  long in_stack_0000fc14;
  uint8_t msg;
  uint8_t text;
  uint8_t reqMsg;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  byte bStack_10;
  undefined1 uStack_f;
  char cStack_e;
  uint8_t unusedFlag;
  stg_tmp_t *stgTmp;   /* hand fix: assigned (stg_tmp_t *) and used as stgTmp->aptr */
  uint8_t *puStack_a;
  int iStack_4;
  
  uVar25 = (undefined1)unaff_SI;
  uVar31 = (undefined1)((uint)unaff_SI >> 8);
  grab = SUB21(x,0);
  uVar9 = ovr_alignUp4(x,0,0);
  bStack_13 = grab - ((char)uVar9 + -2);
  do {
    uStack_f = 0;
    bStack_11 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
    uVar9 = ovr_bldng_usesGStrangeTable
                      (((char_sheet_t *)(((uint)bStack_11 << 2)))->buildType[0]);
    bStack_12 = (byte)uVar9;
    iVar10 = (uVar9 & 0xff) * 0x27;
    uVar23 = SUB21(unaff_SS,0);
    uVar24 = (undefined1)((uint)unaff_SS >> 8);
    if (*(int *)(iVar10 + 0x112) == 0 && *(int *)(iVar10 + 0x114) == 0) {
      iVar10 = (uVar9 & 0xff) * 0x27;
      uVar26 = 0x19;
      ovr_ovc15_usesStshRealloc
                ((char *)*(uint16_t *)(iVar10 + 0x10e),(char)*(uint16_t *)(iVar10 + 0x110),0,0,0,0,0,0);
      ovr_stsprintf((char *)&msg);
    }
    else {
      iVar10 = (uVar9 & 0xff) * 0x27;
      ovr_ovc15_usesStshRealloc
                ((char *)*(uint16_t *)(iVar10 + 0x10e),(char)*(uint16_t *)(iVar10 + 0x110),0,0,0,0,0,0);
      uVar26 = 0x19;
      ovr_stsprintf((char *)&msg);
    }
    iVar10 = 0;
    cStack_e = '\0';
    bVar3 = ovc45_textArena2(bStack_12);
    uVar28 = (undefined1)y;
    if (bVar3) {
      strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg))," You can only place a single arena.");
      cStack_e = '\x01';
    }
    else {
      uVar9 = ovc45_compute1(bStack_12,x,y);
      if ((uVar9 & 0xff) == 0) {
        strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg))," Bridges must be near water\'s edge."
              );
        cStack_e = '\x01';
      }
      else {
        bVar3 = ovr_bldng_textArena(bStack_12,bStack_11);
        if (bVar3) {
          if ((*(char *)((uint)bStack_12 * 0x27 + 0x11b) == '\x04') &&
             ((((uVar9 = ovc45_compute4(x - bStack_13,y,uVar28), (uVar9 & 0xff) == 0 ||
                (uVar9 = ovc45_compute4((x - bStack_13) + 1,y,uVar28),
                (uVar9 & 0xff) == 0)) ||
               (uVar9 = ovc45_compute4((x - bStack_13) + 2,y,uVar28),
               (uVar9 & 0xff) == 0)) ||
              (uVar9 = ovc45_compute4((x - bStack_13) + 3,y,uVar28), (uVar9 & 0xff) == 0
              )))) {
            uVar16 = 0x195d;
            pcVar11 = ovr_stsprintf((char *)&reqMsg);
            strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                   (char *)CONCAT13((char)((uint)uVar16 >> 8),CONCAT12((char)uVar16,pcVar11)));
            uVar26 = (undefined1)((uint)uVar16 >> 8);
            cStack_e = '\x01';
          }
          else if (((*(char *)((uint)bStack_12 * 0x27 + 0x11b) == '\x02') &&
                   ((bStack_13 == 3 ||
                    (uVar9 = ovc45_compute4(x + 1,y,uVar28), (char)uVar9 == '\0')))) &&
                  ((bStack_13 == 0 ||
                   (uVar9 = ovc45_compute4(x - 1,y,uVar28), (char)uVar9 == '\0')))) {
            uVar16 = 0x195d;
            pcVar11 = ovr_stsprintf((char *)&reqMsg);
            strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                   (char *)CONCAT13((char)((uint)uVar16 >> 8),CONCAT12((char)uVar16,pcVar11)));
            uVar26 = (undefined1)((uint)uVar16 >> 8);
            cStack_e = '\x01';
          }
          else {
            uVar26 = 0x19;
            uVar9 = ovc45_usesGMapFlags5(*(char *)((uint)bStack_12 * 0x27 + 0x11e),x,y);
            if ((char)uVar9 == '\0') {
              if (((*(char *)((uint)bStack_12 * 0x27 + 0x11a) == '\x02') ||
                  (*(char *)((uint)bStack_12 * 0x27 + 0x11e) == '\x01')) ||
                 ((uVar26 = 0x19, *(char *)((uint)bStack_12 * 0x27 + 0x11e) == '\x02' ||
                  (uVar9 = ovr_attact_usesGMapFlags(x,y,uVar28), (uVar9 & 0xff) != 0))))
              {
                uVar9 = ovr_constr_usesGMapFlags(x,y,uVar28);
                if ((((char)uVar9 == '\0') &&
                    ((*(uint *)((uint)bStack_12 * 0x27 + 0x121) & 0x20) == 0)) &&
                   (uVar26 = 0x19, *(char *)((uint)bStack_12 * 0x27 + 0x11e) == '\0')) {
                  strcpy((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                         "This location is unsuitable for buildings.");
                  cStack_e = '\x01';
                }
                else {
                  uVar26 = 0x10;
                  pcVar11 = ovr_ovc22_className(*(byte *)((int)Entities + entityIndex * 0x37 + 0x1a),
                                                (char)*(uint16_t *)
                                                       ((uint)bStack_12 * 0x27 + 0x125));
                  uVar16 = 0x217a;
                  iVar18 = ovc45_compute9((char *)&text,
                                          (char *)CONCAT22(*(uint16_t *)((uint)bStack_11 * 4),
                                                           unaff_SS),
                                          (char *)CONCAT22(Font03.ofs,
                                                           (char *)((uint16_t *)
                                                                   ((uint)bStack_11 * 4))[1]),
                                          Font03.seg,'U',0x55,3,(char)pcVar11,uVar26);
                  pcVar11 = ovr_stsprintf((char *)&reqMsg,(char *)CONCAT22(0x7665,unaff_SS),
                                          (char *)CONCAT13((char)((uint)iVar18 >> 8),
                                                           CONCAT12((char)iVar18,0x2410)),
                                          (char)iVar18,uVar16);
                  uVar29 = (undefined1)uVar16;
                  uVar30 = (undefined1)((uint)uVar16 >> 8);
                  uVar26 = SUB21(pcVar11,0);
                  uVar27 = (undefined1)((uint)pcVar11 >> 8);
                  sVar12 = strlen((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)));
                  puVar15 = &msg;
                  strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,puVar15 + sVar12)),
                         (char *)CONCAT13(uVar30,CONCAT12(uVar29,CONCAT11(uVar27,uVar26))));
                  uVar26 = (undefined1)((uint)puVar15 >> 8);
                }
              }
              else {
                strcpy((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                       "Buildings cannot be placed over water.");
                cStack_e = '\x01';
              }
            }
            else {
              strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg))," Walls must be near land.");
              cStack_e = '\x01';
            }
          }
        }
        else {
          uVar26 = 0x19;
          if (*(char *)((uint)bStack_12 * 0x27 + 0x133) == '\x12') {
            uVar9 = ovc45_compute5();
            if ((char)uVar9 == '\0') {
              strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                     " No more outposts are available.");
            }
            else {
              ovc45_compute5();
              uVar16 = 0x2410;
              pcVar11 = ovr_stsprintf((char *)&reqMsg);
              strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                     (char *)CONCAT13((char)((uint)uVar16 >> 8),CONCAT12((char)uVar16,pcVar11)));
              uVar26 = (undefined1)((uint)uVar16 >> 8);
            }
          }
          else if ((*(byte *)((uint)bStack_12 * 0x27 + 0x134) & 0x80) == 0) {
            uVar16 = 0x195d;
            pcVar11 = ovr_stsprintf((char *)&reqMsg,(char *)CONCAT13(0x75,CONCAT12(0x99,unaff_SS)),
                                    (char *)(ulong)CONCAT12(*(undefined1 *)
                                                             ((uint)bStack_12 * 0x27 + 0x134),0x2410
                                                           ),0x99,0x10);
            strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                   (char *)CONCAT13((char)((uint)uVar16 >> 8),CONCAT12((char)uVar16,pcVar11)));
            uVar26 = (undefined1)((uint)uVar16 >> 8);
          }
          else {
            uVar16 = 0x2410;
            pcVar11 = ovr_stsprintf((char *)&reqMsg);
            strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                   (char *)CONCAT13((char)((uint)uVar16 >> 8),CONCAT12((char)uVar16,pcVar11)));
            uVar26 = (undefined1)((uint)uVar16 >> 8);
          }
          cStack_e = '\x01';
        }
      }
    }
    if (cStack_e == '\0') {
      uVar9 = ovr_constr_usesGMapFlags(x,y,uVar28);
      uVar28 = uVar26;
      if (((char)uVar9 == '\0') &&
         (uVar28 = 0x19, (*(uint *)((uint)bStack_12 * 0x27 + 0x121) & 0x20) == 0)) {
        uVar26 = 0x19;
        uVar28 = 0x19;
        if (*(char *)((uint)bStack_12 * 0x27 + 0x11e) == '\0') goto L_OVC45_77eb_0d61_1379;
      }
      uVar26 = uVar28;
      in_stack_0000fc0e = (long *)((char *)0x2410);
      in_stack_0000fc0c = 0x85;
      in_stack_0000fc0d = 0x76;
      stgTmp = (stg_tmp_t *)CONCAT31(stk_fff5,1);
      iVar10 = 1;
    }
L_OVC45_77eb_0d61_1379:
    *(char **)(&stk_fc0e + iVar10 * 4) = (char *)0x2410;
    *(char **)(&stk_fc0c + iVar10 * 4) = (char *)"Change Building";
    *(undefined1 *)((int)&stgTmp + iVar10) = 2;
    iVar18 = iVar10 + 1;
    if (flag != '\0') {
      *(char **)(&stk_fc0e + iVar18 * 4) = (char *)0x2410;
      *(char **)(&stk_fc0c + iVar18 * 4) = (char *)"Change Party";
      *(undefined1 *)((int)&stgTmp + iVar10 + 1) = 3;
      iVar18 = iVar10 + 2;
    }
    *(char **)(&stk_fc0e + iVar18 * 4) = (char *)0x2410;
    *(char **)(&stk_fc0c + iVar18 * 4) = (char *)"Done";
    *(undefined1 *)((int)&stgTmp + iVar18) = 4;
    uVar19 = iVar18 + 1;
    puVar15 = (uint8_t *)CONCAT11(uVar26,bStack_11);
    goldPartyIndex = bStack_11;
    puVar13 = &stk_fc0c;
    entries.seg = (uint16_t)unaff_SS;
    entries.ofs = (uint16_t)puVar13;
    (*(uint8_t *)((uint8_t *)&(hint.seg))) = uVar23;
    hint.ofs = (uint16_t)&msg;
    (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = uVar24;
    ovr_ovc28_compute2(entries,uVar19,hint,(char)uVar19,(char)&msg);
    fVar2.seg = BldGfxNormal[100].seg;
    fVar2.ofs = BldGfxNormal[100].ofs;
    bStack_10 = (byte)puVar13;
    goldPartyIndex = 0xff;
    if (bStack_10 != 0) {
      puVar15 = &unusedFlag;
      bStack_10 = puVar15[(uint)puVar13 & 0xff];
    }
    uStack_f = 0;
    uVar9 = (uint)bStack_10;
  } while (4 < uVar9);
  iVar10 = uVar9 * 2;
  uVar23 = 0;
  uVar24 = 0;
  switch(uVar9) {
  case 0:
code_r0x00074dd2:
    BldGfxNormal[100] = fVar2;
    *(int *)((int)&BldGfxNormal[0].seg + uVar9) = unaff_DI;
    *(uint16_t *)((int)&((far_t far *)BldGfxNormal)->ofs + uVar9) = CONCAT11(uVar31,uVar25);
    uVar22 = func_0x0007ffe0(uVar23);
    *(uint16_t *)((int)&BldGfxNormal[1].seg + uVar19 * 0xc) = (int)((ulong)uVar22 >> 0x10);
    ((far_t far *)(BldGfxNormal + 1) + uVar19 * 3)->ofs = (uint16_t)uVar22;
    uVar22 = func_0x0007ffe0(uVar23);
    *(uint16_t *)((int)&BldGfxNormal[2].seg + uVar19 * 0xc) = (int)((ulong)uVar22 >> 0x10);
    ((far_t far *)(BldGfxNormal + 2) + uVar19 * 3)->ofs = (uint16_t)uVar22;
    uVar22 = func_0x0007ffe0(uVar23);
    *(uint16_t *)((int)&BldGfxRuin[0].seg + uVar19 * 0xc) = (int)((ulong)uVar22 >> 0x10);
    ((far_t far *)BldGfxRuin + uVar19 * 3)->ofs = (uint16_t)uVar22;
    uVar22 = func_0x0007ffe0(uVar23);
    *(uint16_t *)((int)&BldGfxRuin[1].seg + uVar19 * 0xc) = (int)((ulong)uVar22 >> 0x10);
    ((far_t far *)(BldGfxRuin + 1) + uVar19 * 3)->ofs = (uint16_t)uVar22;
    uVar22 = func_0x0007ffe0(uVar23);
    uVar14 = 0x195d;
    *(uint16_t *)((int)&BldGfxRuin[2].seg + uVar19 * 0xc) = (int)((ulong)uVar22 >> 0x10);
    ((far_t far *)(BldGfxRuin + 2) + uVar19 * 3)->ofs = (uint16_t)uVar22;
    goto L_init_assets_4EA5;
  case 1:
code_r0x00072658:
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(176);
    stgTmp = (stg_tmp_t *)CONCAT22(puVar15,psVar4);
    (*(uint8_t *)((uint8_t *)&(pixels_82.seg))) = 100;
    pixels_82.ofs = (psVar4->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_82.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_82,130,199,194,26,100,0x82,199,
                              0x1a);
    pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar16 = 0x195d;
    *(uint16_t *)((int)&BldInstances[0].seg + uVar19 * 0xc) = (uint16_t)puVar15;
    ((bld_inst_t *)BldInstances + uVar19)->ofs = (short)pcVar6;
    uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_83.seg))) = 100;
    pixels_83.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_83.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_83,65,199,129,
                              26,100,0x41,199,0x1a);
    pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar20 = 0x195d;
    *(uint16_t *)((int)&BldInstances[0].seg + (uVar19 + 1) * 0xc) = uVar16;
    ((bld_inst_t *)BldInstances + uVar19 + 1)->ofs = (short)pcVar6;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_84.seg))) = 100;
    pixels_84.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_84.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_84,0,199,64,26
                              ,100,0,199,0x1a);
    pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    *(uint16_t *)((int)&BldInstances[0].seg + (uVar19 + 2) * 0xc) = uVar20;
    ((bld_inst_t *)BldInstances + uVar19 + 2)->ofs = (short)pcVar6;
    ovr_stgFreeTmp(stgTmp,0);
    break;
  case 2:
    uVar9 = ovc45_cellBelowBlocked(uVar9 - 1,unaff_DI);
    if (((uVar9 & 0xff) == 0) &&
       (uVar9 = ovc45_cellBelowBlocked(iVar18 + 2,y), (uVar9 & 0xff) == 0)) {
      uVar9 = 0;
    }
    else {
      uVar9 = 1;
    }
    return uVar9;
  case 3:
    goto code_r0x00074dd0;
  case 4:
    LOCK();
    *(undefined1 *)(iVar10 + uVar19) = (char)((uint)iVar10 >> 8);
    UNLOCK();
    strcpy((char *)CONCAT22(unaff_DI,(char *)(uint)bStack_10),
           (char *)CONCAT13(in_stack_0000fc0d,CONCAT12(in_stack_0000fc0c,CONCAT11(uVar31,uVar25))));
    LOCK();
    *(uint16_t *)(&stk_fffe + y) = uVar19;
    UNLOCK();
    while (iStack_4 = iStack_4 + 1, iStack_4 < 0xc) {
      if (grab == false) {
        uVar22 = func_0x0007ffe0();
        puVar15 = (uint8_t *)((ulong)uVar22 >> 0x10);
        *(uint16_t *)((int)&timeOfDayGfx[0].seg + iStack_4 * 4) = (uint16_t)puVar15;
        ((far_t far *)timeOfDayGfx + iStack_4)->ofs = (uint16_t)uVar22;
      }
      else {
        iVar10 = iStack_4 * 0x17 + 0x1b;
        puVar15 = (uint8_t *)((ulong)((long)iStack_4 * 0x17) >> 0x10);
        iVar18 = (int)((long)iStack_4 * 0x17) + 6;
        uVar25 = (undefined1)iVar18;
        uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
        uVar16 = *(uint16_t *)((int)stgTmp + 0x302);
        (*(uint8_t *)((uint8_t *)&(src.seg))) = uVar25;
        src.ofs = uVar16;
        (*(uint8_t *)((uint8_t *)&(src.seg) + 1)) = (char)((uint)iVar18 >> 8);
        pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src,21,iVar10,(char)uVar16,uVar25,(char)iVar10,0,0);
        pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
        *(uint16_t *)((int)&timeOfDayGfx[0].seg + iStack_4 * 4) = (uint16_t)puVar15;
        ((far_t far *)timeOfDayGfx + iStack_4)->ofs = (uint16_t)pcVar6;
      }
    }
    iStack_4 = 0;
    while( true ) {
      if (5 < iStack_4) break;
      if (grab == false) {
        uVar22 = func_0x0007ffe0();
        puVar15 = (uint8_t *)((ulong)uVar22 >> 0x10);
        ((uint16_t *)&blitFrameSeg)[iStack_4 * 2] = (uint16_t)puVar15;   /* hand fix: 2-byte segment/offset half */
        ((uint16_t *)&blitFrameOfs)[iStack_4 * 2] = (int)uVar22;
      }
      else {
        iVar10 = iStack_4 * 0x17 + 0x16;
        puVar15 = (uint8_t *)((ulong)((long)iStack_4 * 0x17) >> 0x10);
        iVar18 = (int)((long)iStack_4 * 0x17) + 9;
        uVar25 = (undefined1)iVar18;
        uVar19 = (stgTmp->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(src_00.seg))) = uVar25;
        src_00.ofs = uVar19;
        (*(uint8_t *)((uint8_t *)&(src_00.seg) + 1)) = (char)((uint)iVar18 >> 8);
        pfVar5 = ovr_stshRleCut((far_t far *)(&stgTmp->aptr)->ofs,src_00,72,iVar10,(char)uVar19,uVar25,(char)iVar10,0,0);
        pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
        ((uint16_t *)&blitFrameSeg)[iStack_4 * 2] = (uint16_t)puVar15;   /* hand fix: 2-byte segment/offset half */
        ((uint16_t *)&blitFrameOfs)[iStack_4 * 2] = (uint16_t)pcVar6;   /* hand fix: 2-byte segment/offset half */
      }
      iStack_4 = iStack_4 + 1;
    }
    if (grab == false) {
      BldGfxNormal[4] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxNormal[7] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxNormal[10] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxRuin[4] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxRuin[7] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxRuin[10] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      stshStubifyBld(4);
      stshStubifyBld(7);
      stshStubifyBld(10);
      stshStubifyBld(0xd);
      stshStubifyBld(0x10);
      stshStubifyBld(0x13);
      stshStubifyBld(0x16);
      BldGfxNormal[0x4c] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxNormal[0x4f] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxNormal[0x52] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxRuin[0x4c] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxRuin[0x4f] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxRuin[0x52] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      uVar14 = 0x195d;
    }
    else {
      ovr_stgFreeTmp(stgTmp,0);
      stgTmp = ovr_grabLbmTR(80);
      uVar19 = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(src_01.seg))) = 0x28;
      src_01.ofs = uVar19;
      (*(uint8_t *)((uint8_t *)&(src_01.seg) + 1)) = 0;
      puStack_a = puVar15;
      pfVar5 = ovr_stshRleCut((far_t far *)(&stgTmp->aptr)->ofs,src_01,173,50,(char)uVar19,0x28,0x32,0,0);
      BldGfxNormal[4].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(src_02.seg))) = 0x8c;
      src_02.ofs = uVar19;
      (*(uint8_t *)((uint8_t *)&(src_02.seg) + 1)) = 0;
      BldGfxNormal[4].seg = (uint16_t)puVar15;
      pfVar5 = ovr_stshRleCut((far_t far *)(&stgTmp->aptr)->ofs,src_02,108,150,(char)uVar19,0x8c,0x96,0,0)
      ;
      BldGfxNormal[7].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(src_03.seg))) = 0xf0;
      src_03.ofs = uVar19;
      (*(uint8_t *)((uint8_t *)&(src_03.seg) + 1)) = 0;
      BldGfxNormal[7].seg = (uint16_t)puVar15;
      pfVar5 = ovr_stshRleCut((far_t far *)(&stgTmp->aptr)->ofs,src_03,43,252,(char)uVar19,0xf0,0xfc,0,0);
      BldGfxNormal[10].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(src_04.seg))) = 0x28;
      src_04.ofs = uVar19;
      (*(uint8_t *)((uint8_t *)&(src_04.seg) + 1)) = 0;
      BldGfxNormal[10].seg = (uint16_t)puVar15;
      pfVar5 = ovr_stshRleCut((far_t far *)(&stgTmp->aptr)->ofs,src_04,108,50,(char)uVar19,0x28,0x32,0,0);
      BldGfxRuin[4].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(src_05.seg))) = 0x8c;
      src_05.ofs = uVar19;
      (*(uint8_t *)((uint8_t *)&(src_05.seg) + 1)) = 0;
      BldGfxRuin[4].seg = (uint16_t)puVar15;
      pfVar5 = ovr_stshRleCut((far_t far *)(&stgTmp->aptr)->ofs,src_05,173,150,(char)uVar19,0x8c,0x96,0,0)
      ;
      BldGfxRuin[7].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(src_06.seg))) = 0xf0;
      src_06.ofs = uVar19;
      (*(uint8_t *)((uint8_t *)&(src_06.seg) + 1)) = 0;
      BldGfxRuin[7].seg = (uint16_t)puVar15;
      pfVar5 = ovr_stshRleCut((far_t far *)(&stgTmp->aptr)->ofs,src_06,108,252,(char)uVar19,0xf0,0xfc,0,0)
      ;
      BldGfxRuin[10].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      BldGfxRuin[10].seg = (uint16_t)puVar15;
      ovr_stgFreeTmp(stgTmp,0);
      stgTmp = ovr_grabLbmTR(387);
      (*(uint8_t *)((uint8_t *)&(pixels.seg))) = 9;
      pixels.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels.seg) + 1)) = 0;
      puStack_a = puVar15;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels,130,97,194,11,9,0x82,0x61,0xb
                               );
      BldGfxNormal[0xc].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_00.seg))) = 100;
      pixels_00.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_00.seg) + 1)) = 0;
      BldGfxNormal[0xc].seg = (uint16_t)puVar15;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_00,130,199,194,11,100,0x82,
                                199,0xb);
      BldGfxNormal[0xd].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_01.seg))) = 0xcc;
      pixels_01.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_01.seg) + 1)) = 0;
      BldGfxNormal[0xd].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_01,130,292,194,11,0xcc,0x82,
                                0x24,0xb);
      BldGfxNormal[0xe].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_02.seg))) = 9;
      pixels_02.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_02.seg) + 1)) = 0;
      BldGfxNormal[0xe].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_02,65,97,129,11,9,0x41,0x61,
                                0xb);
      BldGfxNormal[0xf].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_03.seg))) = 100;
      pixels_03.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_03.seg) + 1)) = 0;
      BldGfxNormal[0xf].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_03,65,199,129,11,100,0x41,199
                                ,0xb);
      BldGfxNormal[0x10].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_04.seg))) = 0xcc;
      pixels_04.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_04.seg) + 1)) = 0;
      BldGfxNormal[0x10].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_04,65,292,129,11,0xcc,0x41,
                                0x24,0xb);
      BldGfxNormal[0x11].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_05.seg))) = 9;
      pixels_05.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_05.seg) + 1)) = 0;
      BldGfxNormal[0x11].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_05,0,97,64,11,9,0,0x61,0xb);
      BldGfxNormal[0x12].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_06.seg))) = 0x6c;
      pixels_06.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_06.seg) + 1)) = 0;
      BldGfxNormal[0x12].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_06,0,191,64,11,0x6c,0,0xbf,
                                0xb);
      BldGfxNormal[0x13].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_07.seg))) = 0xcc;
      pixels_07.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_07.seg) + 1)) = 0;
      BldGfxNormal[0x13].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_07,0,292,64,11,0xcc,0,0x24,
                                0xb);
      BldGfxNormal[0x14].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      BldGfxNormal[0x14].seg = uVar14;
      ovr_stgFreeTmp(stgTmp,0);
      stgTmp = ovr_grabLbmTR(485);
      (*(uint8_t *)((uint8_t *)&(pixels_08.seg))) = 9;
      pixels_08.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_08.seg) + 1)) = 0;
      puStack_a = (uint8_t *)uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_08,130,97,194,11,9,0x82,0x61,
                                0xb);
      BldGfxRuin[0xc].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_09.seg))) = 100;
      pixels_09.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_09.seg) + 1)) = 0;
      BldGfxRuin[0xc].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_09,130,199,194,11,100,0x82,
                                199,0xb);
      BldGfxRuin[0xd].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_10.seg))) = 0xcc;
      pixels_10.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_10.seg) + 1)) = 0;
      BldGfxRuin[0xd].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_10,130,292,194,11,0xcc,0x82,
                                0x24,0xb);
      BldGfxRuin[0xe].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_11.seg))) = 9;
      pixels_11.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_11.seg) + 1)) = 0;
      BldGfxRuin[0xe].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_11,65,97,129,11,9,0x41,0x61,
                                0xb);
      BldGfxRuin[0xf].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_12.seg))) = 100;
      pixels_12.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_12.seg) + 1)) = 0;
      BldGfxRuin[0xf].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_12,65,199,129,11,100,0x41,199
                                ,0xb);
      BldGfxRuin[0x10].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_13.seg))) = 0xcc;
      pixels_13.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_13.seg) + 1)) = 0;
      BldGfxRuin[0x10].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_13,65,292,129,11,0xcc,0x41,
                                0x24,0xb);
      BldGfxRuin[0x11].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_14.seg))) = 9;
      pixels_14.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_14.seg) + 1)) = 0;
      BldGfxRuin[0x11].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_14,0,97,64,11,9,0,0x61,0xb);
      BldGfxRuin[0x12].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_15.seg))) = 0x6c;
      pixels_15.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_15.seg) + 1)) = 0;
      BldGfxRuin[0x12].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_15,0,191,64,11,0x6c,0,0xbf,
                                0xb);
      BldGfxRuin[0x13].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_16.seg))) = 0xcc;
      pixels_16.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_16.seg) + 1)) = 0;
      BldGfxRuin[0x13].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_16,0,292,64,11,0xcc,0,0x24,
                                0xb);
      BldGfxRuin[0x14].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      BldGfxRuin[0x14].seg = uVar19;
      ovr_stgFreeTmp(stgTmp,0);
      stgTmp = ovr_grabLbmTR(392);
      pixels_17.seg = 0;
      pixels_17.ofs = (stgTmp->aptr).seg;
      puStack_a = (uint8_t *)uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_17,130,99,194,26,0,0x82,99,
                                0x1a);
      BldGfxNormal[0x15].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_18.seg))) = 100;
      pixels_18.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_18.seg) + 1)) = 0;
      BldGfxNormal[0x15].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_18,130,199,194,26,100,0x82,
                                199,0x1a);
      BldGfxNormal[0x16].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_19.seg))) = 200;
      pixels_19.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_19.seg) + 1)) = 0;
      BldGfxNormal[0x16].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_19,130,299,194,26,200,0x82,
                                0x2b,0x1a);
      BldGfxNormal[0x17].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      pixels_20.seg = 0;
      pixels_20.ofs = (stgTmp->aptr).seg;
      BldGfxNormal[0x17].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_20,65,99,129,26,0,0x41,99,
                                0x1a);
      BldGfxNormal[0x18].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_21.seg))) = 100;
      pixels_21.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_21.seg) + 1)) = 0;
      BldGfxNormal[0x18].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_21,65,199,129,26,100,0x41,199
                                ,0x1a);
      BldGfxNormal[0x19].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_22.seg))) = 200;
      pixels_22.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_22.seg) + 1)) = 0;
      BldGfxNormal[0x19].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_22,65,299,129,26,200,0x41,
                                0x2b,0x1a);
      BldGfxNormal[0x1a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      pixels_23.seg = 0;
      pixels_23.ofs = (stgTmp->aptr).seg;
      BldGfxNormal[0x1a].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_23,0,99,64,26,0,0,99,0x1a);
      BldGfxNormal[0x1b].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_24.seg))) = 100;
      pixels_24.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_24.seg) + 1)) = 0;
      BldGfxNormal[0x1b].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_24,0,199,64,26,100,0,199,0x1a
                               );
      BldGfxNormal[0x1c].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_25.seg))) = 200;
      pixels_25.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_25.seg) + 1)) = 0;
      BldGfxNormal[0x1c].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_25,0,299,64,26,200,0,0x2b,
                                0x1a);
      BldGfxNormal[0x1d].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      BldGfxNormal[0x1d].seg = uVar14;
      ovr_stgFreeTmp(stgTmp,0);
      stgTmp = ovr_grabLbmTR(393);
      pixels_26.seg = 0;
      pixels_26.ofs = (stgTmp->aptr).seg;
      puStack_a = (uint8_t *)uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_26,130,99,194,26,0,0x82,99,
                                0x1a);
      BldGfxRuin[0x15].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_27.seg))) = 100;
      pixels_27.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_27.seg) + 1)) = 0;
      BldGfxRuin[0x15].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_27,130,199,194,26,100,0x82,
                                199,0x1a);
      BldGfxRuin[0x16].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_28.seg))) = 200;
      pixels_28.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_28.seg) + 1)) = 0;
      BldGfxRuin[0x16].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_28,130,299,194,26,200,0x82,
                                0x2b,0x1a);
      BldGfxRuin[0x17].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      pixels_29.seg = 0;
      pixels_29.ofs = (stgTmp->aptr).seg;
      BldGfxRuin[0x17].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_29,65,99,129,26,0,0x41,99,
                                0x1a);
      BldGfxRuin[0x18].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_30.seg))) = 100;
      pixels_30.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_30.seg) + 1)) = 0;
      BldGfxRuin[0x18].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_30,65,199,129,26,100,0x41,199
                                ,0x1a);
      BldGfxRuin[0x19].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_31.seg))) = 200;
      pixels_31.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_31.seg) + 1)) = 0;
      BldGfxRuin[0x19].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_31,65,299,129,26,200,0x41,
                                0x2b,0x1a);
      BldGfxRuin[0x1a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      pixels_32.seg = 0;
      pixels_32.ofs = (stgTmp->aptr).seg;
      BldGfxRuin[0x1a].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_32,0,99,64,26,0,0,99,0x1a);
      BldGfxRuin[0x1b].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_33.seg))) = 100;
      pixels_33.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_33.seg) + 1)) = 0;
      BldGfxRuin[0x1b].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_33,0,199,64,26,100,0,199,0x1a
                               );
      BldGfxRuin[0x1c].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_34.seg))) = 200;
      pixels_34.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_34.seg) + 1)) = 0;
      BldGfxRuin[0x1c].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_34,0,299,64,26,200,0,0x2b,
                                0x1a);
      BldGfxRuin[0x1d].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      BldGfxRuin[0x1d].seg = uVar19;
      ovr_stgFreeTmp(stgTmp,0);
      stgTmp = ovr_grabLbmTR(56);
      (*(uint8_t *)((uint8_t *)&(pixels_35.seg))) = 6;
      pixels_35.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_35.seg) + 1)) = 0;
      puStack_a = (uint8_t *)uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_35,151,91,180,0,6,0x97,0x5b,0
                               );
      BldGfxNormal[0x1e].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_36.seg))) = 0x6e;
      pixels_36.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_36.seg) + 1)) = 0;
      BldGfxNormal[0x1e].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_36,151,185,180,0,0x6e,0x97,
                                0xb9,0);
      BldGfxNormal[0x1f].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_37.seg))) = 0xd8;
      pixels_37.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_37.seg) + 1)) = 0;
      BldGfxNormal[0x1f].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_37,151,299,180,0,0xd8,0x97,
                                0x2b,0);
      BldGfxNormal[0x20].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_38.seg))) = 6;
      pixels_38.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_38.seg) + 1)) = 0;
      BldGfxNormal[0x20].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_38,72,91,115,0,6,0x48,0x5b,0)
      ;
      BldGfxNormal[0x21].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_39.seg))) = 0x6e;
      pixels_39.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_39.seg) + 1)) = 0;
      BldGfxNormal[0x21].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_39,72,185,115,0,0x6e,0x48,
                                0xb9,0);
      BldGfxNormal[0x22].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_40.seg))) = 0xd8;
      pixels_40.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_40.seg) + 1)) = 0;
      BldGfxNormal[0x22].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_40,72,299,115,0,0xd8,0x48,
                                0x2b,0);
      BldGfxNormal[0x23].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_41.seg))) = 6;
      pixels_41.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_41.seg) + 1)) = 0;
      BldGfxNormal[0x23].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_41,6,91,59,0,6,6,0x5b,0);
      BldGfxNormal[0x24].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_42.seg))) = 0x6e;
      pixels_42.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_42.seg) + 1)) = 0;
      BldGfxNormal[0x24].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_42,6,185,59,0,0x6e,6,0xb9,0);
      BldGfxNormal[0x25].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_43.seg))) = 0xd8;
      pixels_43.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_43.seg) + 1)) = 0;
      BldGfxNormal[0x25].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_43,6,299,59,0,0xd8,6,0x2b,0);
      BldGfxNormal[0x26].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      BldGfxNormal[0x26].seg = uVar14;
      ovr_stgFreeTmp(stgTmp,0);
      stgTmp = ovr_grabLbmTR(444);
      (*(uint8_t *)((uint8_t *)&(pixels_44.seg))) = 6;
      pixels_44.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_44.seg) + 1)) = 0;
      puStack_a = (uint8_t *)uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_44,151,91,180,0,6,0x97,0x5b,0
                               );
      BldGfxRuin[0x1e].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_45.seg))) = 0x6e;
      pixels_45.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_45.seg) + 1)) = 0;
      BldGfxRuin[0x1e].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_45,151,185,180,0,0x6e,0x97,
                                0xb9,0);
      BldGfxRuin[0x1f].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_46.seg))) = 0xd8;
      pixels_46.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_46.seg) + 1)) = 0;
      BldGfxRuin[0x1f].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_46,151,299,180,0,0xd8,0x97,
                                0x2b,0);
      BldGfxRuin[0x20].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_47.seg))) = 6;
      pixels_47.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_47.seg) + 1)) = 0;
      BldGfxRuin[0x20].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_47,72,91,115,0,6,0x48,0x5b,0)
      ;
      BldGfxRuin[0x21].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_48.seg))) = 0x6e;
      pixels_48.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_48.seg) + 1)) = 0;
      BldGfxRuin[0x21].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_48,72,185,115,0,0x6e,0x48,
                                0xb9,0);
      BldGfxRuin[0x22].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_49.seg))) = 0xd8;
      pixels_49.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_49.seg) + 1)) = 0;
      BldGfxRuin[0x22].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_49,72,299,115,0,0xd8,0x48,
                                0x2b,0);
      BldGfxRuin[0x23].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_50.seg))) = 6;
      pixels_50.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_50.seg) + 1)) = 0;
      BldGfxRuin[0x23].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_50,6,91,59,0,6,6,0x5b,0);
      BldGfxRuin[0x24].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_51.seg))) = 0x6e;
      pixels_51.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_51.seg) + 1)) = 0;
      BldGfxRuin[0x24].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_51,6,185,59,0,0x6e,6,0xb9,0);
      BldGfxRuin[0x25].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_52.seg))) = 0xd8;
      pixels_52.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_52.seg) + 1)) = 0;
      BldGfxRuin[0x25].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_52,6,299,59,0,0xd8,6,0x2b,0);
      BldGfxRuin[0x26].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      BldGfxRuin[0x26].seg = uVar19;
      ovr_stgFreeTmp(stgTmp,0);
      stgTmp = ovr_grabLbmTR(447);
      (*(uint8_t *)((uint8_t *)&(pixels_53.seg))) = 2;
      pixels_53.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_53.seg) + 1)) = 0;
      puStack_a = (uint8_t *)uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_53,130,89,180,0,2,0x82,0x59,0
                               );
      BldGfxNormal[0x27].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_54.seg))) = 0x6c;
      pixels_54.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_54.seg) + 1)) = 0;
      BldGfxNormal[0x27].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_54,130,191,180,0,0x6c,0x82,
                                0xbf,0);
      BldGfxNormal[0x28].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_55.seg))) = 0xd4;
      pixels_55.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_55.seg) + 1)) = 0;
      BldGfxNormal[0x28].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_55,130,298,180,0,0xd4,0x82,
                                0x2a,0);
      BldGfxNormal[0x29].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_56.seg))) = 2;
      pixels_56.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_56.seg) + 1)) = 0;
      BldGfxNormal[0x29].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_56,65,89,115,0,2,0x41,0x59,0)
      ;
      BldGfxNormal[0x2a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_57.seg))) = 0x6c;
      pixels_57.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_57.seg) + 1)) = 0;
      BldGfxNormal[0x2a].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_57,65,191,115,0,0x6c,0x41,
                                0xbf,0);
      BldGfxNormal[0x2b].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_58.seg))) = 0xd4;
      pixels_58.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_58.seg) + 1)) = 0;
      BldGfxNormal[0x2b].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_58,65,298,115,0,0xd4,0x41,
                                0x2a,0);
      BldGfxNormal[0x2c].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_59.seg))) = 2;
      pixels_59.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_59.seg) + 1)) = 0;
      BldGfxNormal[0x2c].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_59,9,89,59,0,2,9,0x59,0);
      BldGfxNormal[0x2d].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_60.seg))) = 0x6c;
      pixels_60.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_60.seg) + 1)) = 0;
      BldGfxNormal[0x2d].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_60,9,191,59,0,0x6c,9,0xbf,0);
      BldGfxNormal[0x2e].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_61.seg))) = 0xd4;
      pixels_61.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_61.seg) + 1)) = 0;
      BldGfxNormal[0x2e].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_61,9,298,59,0,0xd4,9,0x2a,0);
      BldGfxNormal[0x2f].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      BldGfxNormal[0x2f].seg = uVar14;
      ovr_stgFreeTmp(stgTmp,0);
      stgTmp = ovr_grabLbmTR(448);
      (*(uint8_t *)((uint8_t *)&(pixels_62.seg))) = 2;
      pixels_62.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_62.seg) + 1)) = 0;
      puStack_a = (uint8_t *)uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_62,130,89,180,0,2,0x82,0x59,0
                               );
      BldGfxRuin[0x27].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_63.seg))) = 0x6c;
      pixels_63.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_63.seg) + 1)) = 0;
      BldGfxRuin[0x27].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_63,130,191,180,0,0x6c,0x82,
                                0xbf,0);
      BldGfxRuin[0x28].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_64.seg))) = 0xd4;
      pixels_64.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_64.seg) + 1)) = 0;
      BldGfxRuin[0x28].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_64,130,298,180,0,0xd4,0x82,
                                0x2a,0);
      BldGfxRuin[0x29].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_65.seg))) = 2;
      pixels_65.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_65.seg) + 1)) = 0;
      BldGfxRuin[0x29].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_65,65,89,115,0,2,0x41,0x59,0)
      ;
      BldGfxRuin[0x2a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_66.seg))) = 0x6c;
      pixels_66.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_66.seg) + 1)) = 0;
      BldGfxRuin[0x2a].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_66,65,191,115,0,0x6c,0x41,
                                0xbf,0);
      BldGfxRuin[0x2b].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_67.seg))) = 0xd4;
      pixels_67.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_67.seg) + 1)) = 0;
      BldGfxRuin[0x2b].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_67,65,298,115,0,0xd4,0x41,
                                0x2a,0);
      BldGfxRuin[0x2c].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_68.seg))) = 2;
      pixels_68.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_68.seg) + 1)) = 0;
      BldGfxRuin[0x2c].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_68,9,89,59,0,2,9,0x59,0);
      BldGfxRuin[0x2d].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_69.seg))) = 0x6c;
      pixels_69.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_69.seg) + 1)) = 0;
      BldGfxRuin[0x2d].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_69,9,191,59,0,0x6c,9,0xbf,0);
      BldGfxRuin[0x2e].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_70.seg))) = 0xd4;
      pixels_70.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_70.seg) + 1)) = 0;
      BldGfxRuin[0x2e].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_70,9,298,59,0,0xd4,9,0x2a,0);
      BldGfxRuin[0x2f].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      BldGfxRuin[0x2f].seg = uVar19;
      ovr_stgFreeTmp(stgTmp,0);
      ovr_grabBldLbm(115,116,0x74,0,0);
      ovr_grabBldLbm(423,446,0xbe,0,0);
      ovr_grabBldLbm(312,313,0x39,0,0);
      stgTmp = ovr_grabLbmTR(459);
      (*(uint8_t *)((uint8_t *)&(pixels_71.seg))) = 9;
      pixels_71.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_71.seg) + 1)) = 0;
      puStack_a = (uint8_t *)uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_71,68,92,182,-4,9,0x44,0x5c,
                                0xfc);
      BldGfxNormal[0x4c].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_72.seg))) = 0x6c;
      pixels_72.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_72.seg) + 1)) = 0;
      BldGfxNormal[0x4c].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_72,68,191,182,-3,0x6c,0x44,
                                0xbf,0xfd);
      BldGfxNormal[0x4f].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      (*(uint8_t *)((uint8_t *)&(pixels_73.seg))) = 0xd0;
      pixels_73.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_73.seg) + 1)) = 0;
      BldGfxNormal[0x4f].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_73,68,291,182,-1,0xd0,0x44,
                                0x23,0xff);
      BldGfxNormal[0x52].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      BldGfxNormal[0x52].seg = uVar14;
      ovr_stgFreeTmp(stgTmp,0);
      psVar4 = ovr_grabLbmTR(460);
      stgTmp = (stg_tmp_t *)CONCAT22(uVar19,psVar4);
      (*(uint8_t *)((uint8_t *)&(pixels_74.seg))) = 9;
      pixels_74.ofs = (psVar4->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_74.seg) + 1)) = 0;
      pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_74,68,92,182,-4,9,0x44,0x5c,
                                0xfc);
      BldGfxRuin[0x4c].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_75.seg))) = 0x6c;
      pixels_75.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_75.seg) + 1)) = 0;
      BldGfxRuin[0x4c].seg = uVar19;
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_75,68,191,
                                182,-3,0x6c,0x44,0xbf,0xfd);
      BldGfxRuin[0x4f].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = 0x195d;
      uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_76.seg))) = 0xd0;
      pixels_76.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_76.seg) + 1)) = 0;
      BldGfxRuin[0x4f].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_76,68,291,
                                182,-1,0xd0,0x44,0x23,0xff);
      BldGfxRuin[0x52].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      BldGfxRuin[0x52].seg = uVar19;
      ovr_stgFreeTmp(stgTmp,0);
    }
    ovr_stshStubifyCopy1to0(0x19);
    if (grab != false) {
      psVar4 = ovr_grabLbmTR(172);
      stgTmp = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    }
    iStack_4 = 0;
    while( true ) {
      if (2 < iStack_4) break;
      if (grab == false) {
        uVar22 = func_0x0007ffe0();
        *(uint16_t *)((int)&BldGfxNormal[1].seg + (iStack_4 + 0x1c) * 0xc) =
             (int)((ulong)uVar22 >> 0x10);
        ((far_t far *)(BldGfxNormal + 1) + (iStack_4 + 0x1c) * 3)->ofs = (uint16_t)uVar22;
      }
      else {
        iVar10 = iStack_4 * 100 + 99;
        uVar16 = (uint16_t)((ulong)((long)iStack_4 * 100) >> 0x10);
        iVar18 = (int)((long)iStack_4 * 100) + 0x14;
        uVar25 = (undefined1)iVar18;
        (*(uint8_t *)((uint8_t *)&(pixels_77.seg))) = uVar25;
        pixels_77.ofs = (stgTmp->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(pixels_77.seg) + 1)) = (char)((uint)iVar18 >> 8);
        pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_77,33,iVar10,116,8,uVar25,
                                  0x21,(char)iVar10,8);
        pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
        *(uint16_t *)((int)&BldGfxNormal[1].seg + (iStack_4 + 0x1c) * 0xc) = uVar16;
        ((far_t far *)(BldGfxNormal + 1) + (iStack_4 + 0x1c) * 3)->ofs = (uint16_t)pcVar6;
      }
      uVar19 = ((far_t far *)(BldGfxNormal + 1) + (iStack_4 + 0x1c) * 3)->ofs;
      *(uint16_t *)((int)&BldGfxNormal[0].seg + (iStack_4 + 0x1c) * 0xc) =
           *(uint16_t *)((int)&BldGfxNormal[1].seg + (iStack_4 + 0x1c) * 0xc);
      ((far_t far *)BldGfxNormal + (iStack_4 + 0x1c) * 3)->ofs = uVar19;
      uVar14 = *(uint16_t *)((int)&BldGfxNormal[1].seg + (iStack_4 + 0x1c) * 0xc);
      uVar19 = ((far_t far *)(BldGfxNormal + 1) + (iStack_4 + 0x1c) * 3)->ofs;
      *(uint16_t *)((int)&BldGfxNormal[2].seg + (iStack_4 + 0x1c) * 0xc) = uVar14;
      ((far_t far *)(BldGfxNormal + 2) + (iStack_4 + 0x1c) * 3)->ofs = uVar19;
      iStack_4 = iStack_4 + 1;
    }
    if (grab != false) {
      ovr_stgFreeTmp(stgTmp,0);
      psVar4 = ovr_grabLbmTR(175);
      stgTmp = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    }
    iStack_4 = 0;
    while( true ) {
      if (2 < iStack_4) break;
      if (grab == false) {
        uVar22 = func_0x0007ffe0();
        *(uint16_t *)((int)&BldGfxRuin[1].seg + (iStack_4 + 0x1c) * 0xc) =
             (int)((ulong)uVar22 >> 0x10);
        ((far_t far *)(BldGfxRuin + 1) + (iStack_4 + 0x1c) * 3)->ofs = (uint16_t)uVar22;
      }
      else {
        iVar10 = iStack_4 * 100 + 99;
        uVar16 = (uint16_t)((ulong)((long)iStack_4 * 100) >> 0x10);
        iVar18 = (int)((long)iStack_4 * 100) + 0x14;
        uVar25 = (undefined1)iVar18;
        (*(uint8_t *)((uint8_t *)&(pixels_78.seg))) = uVar25;
        pixels_78.ofs = (stgTmp->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(pixels_78.seg) + 1)) = (char)((uint)iVar18 >> 8);
        pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_78,33,iVar10,116,8,uVar25,
                                  0x21,(char)iVar10,8);
        pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
        *(uint16_t *)((int)&BldGfxRuin[1].seg + (iStack_4 + 0x1c) * 0xc) = uVar16;
        ((far_t far *)(BldGfxRuin + 1) + (iStack_4 + 0x1c) * 3)->ofs = (uint16_t)pcVar6;
      }
      uVar19 = ((far_t far *)(BldGfxRuin + 1) + (iStack_4 + 0x1c) * 3)->ofs;
      *(uint16_t *)((int)&BldGfxRuin[0].seg + (iStack_4 + 0x1c) * 0xc) =
           *(uint16_t *)((int)&BldGfxRuin[1].seg + (iStack_4 + 0x1c) * 0xc);
      ((far_t far *)BldGfxRuin + (iStack_4 + 0x1c) * 3)->ofs = uVar19;
      uVar14 = *(uint16_t *)((int)&BldGfxRuin[1].seg + (iStack_4 + 0x1c) * 0xc);
      uVar19 = ((far_t far *)(BldGfxRuin + 1) + (iStack_4 + 0x1c) * 3)->ofs;
      *(uint16_t *)((int)&BldGfxRuin[2].seg + (iStack_4 + 0x1c) * 0xc) = uVar14;
      ((far_t far *)(BldGfxRuin + 2) + (iStack_4 + 0x1c) * 3)->ofs = uVar19;
      iStack_4 = iStack_4 + 1;
    }
    if (grab != false) {
      ovr_stgFreeTmp(stgTmp,0);
    }
    uVar19 = 0x1f;
    if (grab != false) {
      psVar4 = ovr_grabLbmTR(174);
      stgTmp = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
      (*(uint8_t *)((uint8_t *)&(pixels_79.seg))) = 100;
      pixels_79.ofs = (psVar4->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_79.seg) + 1)) = 0;
      pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_79,130,199,194,26,100,0x82,199,
                                0x1a);
      BldGfxNormal[0x5e].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar21 = 0x195d;
      uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_80.seg))) = 100;
      pixels_80.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_80.seg) + 1)) = 0;
      BldGfxNormal[0x5e].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_80,65,199,
                                129,26,100,0x41,199,0x1a);
      BldGfxNormal[0x61].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = 0x195d;
      uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_81.seg))) = 100;
      pixels_81.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_81.seg) + 1)) = 0;
      BldGfxNormal[0x61].seg = uVar21;
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_81,0,199,64,
                                26,100,0,199,0x1a);
      BldGfxNormal[100].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
      puVar15 = (uint8_t *)&AgntAnms[0x88].missileDy;
      BldGfxNormal[100].seg = uVar14;
      goto code_r0x00072658;
    }
    BldGfxNormal[0x5e] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x61] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[100] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x5e] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x61] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[100] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar14 = 0x195d;
  }
  ovr_stshStubifyCopy1to0(uVar19);
  if (grab == false) {
    stshStubifyBld(0x22);
    stshStubifyBld(0x25);
    stshStubifyBld(0x28);
    stshStubifyBld(0x2b);
    BldGfxNormal[0x8b] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x8e] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x91] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x94] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x97] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x9a] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar19 = 0x195d;
  }
  else {
    ovr_grabBldLbm(449,450,0xc2,0,0);
    ovr_grabBldLbm(390,391,0x87,0,0);
    ovr_grabBldLbm(389,442,0xba,0,0);
    stgTmp = ovr_grabLbmTR(394);
    (*(uint8_t *)((uint8_t *)&(pixels_85.seg))) = 6;
    pixels_85.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_85.seg) + 1)) = 0;
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_85,151,91,180,-10,6,0x97,0x5b,
                              0xf6);
    BldGfxNormal[0x81].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_86.seg))) = 0x6e;
    pixels_86.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_86.seg) + 1)) = 0;
    BldGfxNormal[0x81].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_86,151,185,180,-10,0x6e,0x97,
                              0xb9,0xf6);
    BldGfxNormal[0x82].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_87.seg))) = 0xd8;
    pixels_87.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_87.seg) + 1)) = 0;
    BldGfxNormal[0x82].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_87,151,299,180,-10,0xd8,0x97,
                              0x2b,0xf6);
    BldGfxNormal[0x83].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_88.seg))) = 6;
    pixels_88.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_88.seg) + 1)) = 0;
    BldGfxNormal[0x83].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_88,72,91,115,-10,6,0x48,0x5b,
                              0xf6);
    BldGfxNormal[0x84].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_89.seg))) = 0x6e;
    pixels_89.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_89.seg) + 1)) = 0;
    BldGfxNormal[0x84].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_89,72,185,115,-10,0x6e,0x48,
                              0xb9,0xf6);
    BldGfxNormal[0x85].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_90.seg))) = 0xd8;
    pixels_90.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_90.seg) + 1)) = 0;
    BldGfxNormal[0x85].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_90,72,299,115,-10,0xd8,0x48,
                              0x2b,0xf6);
    BldGfxNormal[0x86].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_91.seg))) = 6;
    pixels_91.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_91.seg) + 1)) = 0;
    BldGfxNormal[0x86].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_91,6,91,59,-10,6,6,0x5b,0xf6);
    BldGfxNormal[0x87].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_92.seg))) = 0x6e;
    pixels_92.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_92.seg) + 1)) = 0;
    BldGfxNormal[0x87].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_92,6,185,59,-10,0x6e,6,0xb9,
                              0xf6);
    BldGfxNormal[0x88].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_93.seg))) = 0xd8;
    pixels_93.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_93.seg) + 1)) = 0;
    BldGfxNormal[0x88].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_93,6,299,59,-10,0xd8,6,0x2b,
                              0xf6);
    BldGfxNormal[0x89].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    BldGfxNormal[0x89].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
    stgTmp = ovr_grabLbmTR(443);
    (*(uint8_t *)((uint8_t *)&(pixels_94.seg))) = 6;
    pixels_94.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_94.seg) + 1)) = 0;
    puStack_a = (uint8_t *)uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_94,151,91,180,-10,6,0x97,0x5b,
                              0xf6);
    BldGfxRuin[0x81].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_95.seg))) = 0x6e;
    pixels_95.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_95.seg) + 1)) = 0;
    BldGfxRuin[0x81].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_95,151,185,180,-10,0x6e,0x97,
                              0xb9,0xf6);
    BldGfxRuin[0x82].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_96.seg))) = 0xd8;
    pixels_96.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_96.seg) + 1)) = 0;
    BldGfxRuin[0x82].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_96,151,299,180,-10,0xd8,0x97,
                              0x2b,0xf6);
    BldGfxRuin[0x83].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_97.seg))) = 6;
    pixels_97.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_97.seg) + 1)) = 0;
    BldGfxRuin[0x83].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_97,72,91,115,-10,6,0x48,0x5b,
                              0xf6);
    BldGfxRuin[0x84].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_98.seg))) = 0x6e;
    pixels_98.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_98.seg) + 1)) = 0;
    BldGfxRuin[0x84].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_98,72,185,115,-10,0x6e,0x48,
                              0xb9,0xf6);
    BldGfxRuin[0x85].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_99.seg))) = 0xd8;
    pixels_99.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_99.seg) + 1)) = 0;
    BldGfxRuin[0x85].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_99,72,299,115,-10,0xd8,0x48,
                              0x2b,0xf6);
    BldGfxRuin[0x86].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00100.seg))) = 6;
    pixels_x00100.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00100.seg) + 1)) = 0;
    BldGfxRuin[0x86].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00100,6,91,59,-10,6,6,0x5b,
                              0xf6);
    BldGfxRuin[0x87].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00101.seg))) = 0x6e;
    pixels_x00101.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00101.seg) + 1)) = 0;
    BldGfxRuin[0x87].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00101,6,185,59,-10,0x6e,6,0xb9
                              ,0xf6);
    BldGfxRuin[0x88].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00102.seg))) = 0xd8;
    pixels_x00102.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00102.seg) + 1)) = 0;
    BldGfxRuin[0x88].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00102,6,299,59,-10,0xd8,6,0x2b
                              ,0xf6);
    BldGfxRuin[0x89].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    BldGfxRuin[0x89].seg = uVar19;
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(173);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    pixels_x00103.seg = 0;
    pixels_x00103.ofs = (psVar4->aptr).seg;
    pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_x00103,130,99,194,26,0,0x82,99,
                              0x1a);
    BldGfxNormal[0x8b].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00104.seg))) = 100;
    pixels_x00104.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00104.seg) + 1)) = 0;
    BldGfxNormal[0x8b].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00104,130,199
                              ,194,26,100,0x82,199,0x1a);
    BldGfxNormal[0x8e].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00105.seg))) = 200;
    pixels_x00105.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00105.seg) + 1)) = 0;
    BldGfxNormal[0x8e].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00105,130,299
                              ,194,26,200,0x82,0x2b,0x1a);
    BldGfxNormal[0x91].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    pixels_x00106.seg = 0;
    pixels_x00106.ofs = *(uint *)((int)stgTmp + 0x302);
    BldGfxNormal[0x91].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00106,65,99,
                              129,26,0,0x41,99,0x1a);
    BldGfxNormal[0x94].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00107.seg))) = 100;
    pixels_x00107.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00107.seg) + 1)) = 0;
    BldGfxNormal[0x94].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00107,65,199,
                              129,26,100,0x41,199,0x1a);
    BldGfxNormal[0x97].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar21 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00108.seg))) = 200;
    pixels_x00108.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00108.seg) + 1)) = 0;
    BldGfxNormal[0x97].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00108,65,299,
                              129,26,200,0x41,0x2b,0x1a);
    BldGfxNormal[0x9a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    BldGfxNormal[0x9a].seg = uVar21;
    ovr_stgFreeTmp(stgTmp,0);
  }
  ovr_stshStubifyCopy1to0(0x2e);
  ovr_stshStubifyCopy1to0(0x31);
  if (grab == false) {
    stshStubifyBld(0x34);
    stshStubifyBld(0x37);
    BldGfxNormal[0xaf] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0xb2] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0xb5] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0xaf] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0xb2] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0xb5] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar19 = 0x195d;
  }
  else {
    ovr_grabBldLbm(314,315,0x3b,0,0);
    ovr_grabBldLbm(316,317,0x3d,0,0);
    stgTmp = ovr_grabLbmTR(320);
    (*(uint8_t *)((uint8_t *)&(pixels_x00109.seg))) = 0x3a;
    pixels_x00109.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00109.seg) + 1)) = 0;
    puStack_a = (uint8_t *)uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00109,141,134,199,-4,0x3a,0x8d
                              ,0x86,0xfc);
    BldGfxNormal[0xaf].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00110.seg))) = 0x3a;
    pixels_x00110.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00110.seg) + 1)) = 0;
    BldGfxNormal[0xaf].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00110,84,134,142,-4,0x3a,0x54,
                              0x86,0xfc);
    BldGfxNormal[0xb2].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00111.seg))) = 0x3a;
    pixels_x00111.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00111.seg) + 1)) = 0;
    BldGfxNormal[0xb2].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00111,25,134,83,-4,0x3a,0x19,
                              0x86,0xfc);
    BldGfxNormal[0xb5].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    BldGfxNormal[0xb5].seg = uVar19;
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(321);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    (*(uint8_t *)((uint8_t *)&(pixels_x00112.seg))) = 0x3a;
    pixels_x00112.ofs = (psVar4->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00112.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_x00112,141,134,199,-4,0x3a,0x8d,
                              0x86,0xfc);
    BldGfxRuin[0xaf].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00113.seg))) = 0x3a;
    pixels_x00113.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00113.seg) + 1)) = 0;
    BldGfxRuin[0xaf].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00113,84,134,
                              142,-4,0x3a,0x54,0x86,0xfc);
    BldGfxRuin[0xb2].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00114.seg))) = 0x3a;
    pixels_x00114.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00114.seg) + 1)) = 0;
    BldGfxRuin[0xb2].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00114,25,134,
                              83,-4,0x3a,0x19,0x86,0xfc);
    BldGfxRuin[0xb5].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    BldGfxRuin[0xb5].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
  }
  ovr_stshStubifyCopy1to0(0x3a);
  if (grab != false) {
    psVar4 = ovr_grabLbmTR(500);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar19,psVar4);
  }
  iVar10 = 0;
  while( true ) {
    if (3 < iVar10) break;
    if (grab == false) {
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xb7].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xb7) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xb8].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xb8) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xb9].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xb9) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
    }
    else {
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      (*(uint8_t *)((uint8_t *)&(pixels_x00115.seg))) = uVar25;
      pixels_x00115.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_x00115.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00115,0,iVar18,54,0,uVar25,0
                                ,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xb7].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xb7) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_x00116.seg))) = uVar25;
      pixels_x00116.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_x00116.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00116,62,
                                iVar18,116,0,uVar25,0x3e,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xb8].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xb8) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_x00117.seg))) = uVar25;
      pixels_x00117.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_x00117.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00117,62,
                                iVar18,116,0,uVar25,0x3e,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xb9].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xb9) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
    }
    uVar19 = 0x195d;
    iVar10 = iVar10 + 1;
  }
  if (grab != false) {
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(501);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar19,psVar4);
  }
  iVar10 = 0;
  while( true ) {
    if (3 < iVar10) break;
    if (grab == false) {
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xba].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xba) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xbb].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xbb) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xbc].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xbc) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
    }
    else {
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      (*(uint8_t *)((uint8_t *)&(pixels_x00118.seg))) = uVar25;
      pixels_x00118.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_x00118.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00118,0,iVar18,54,0,uVar25,0
                                ,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xba].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xba) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_x00119.seg))) = uVar25;
      pixels_x00119.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_x00119.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00119,62,
                                iVar18,116,0,uVar25,0x3e,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xbb].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xbb) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_x00120.seg))) = uVar25;
      pixels_x00120.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_x00120.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00120,62,
                                iVar18,116,0,uVar25,0x3e,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xbc].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xbc) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
    }
    uVar19 = 0x195d;
    iVar10 = iVar10 + 1;
  }
  if (grab != false) {
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(502);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar19,psVar4);
  }
  iVar10 = 0;
  while( true ) {
    if (3 < iVar10) break;
    if (grab == false) {
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xbd].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xbd) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xbe].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xbe) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xbf].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xbf) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
    }
    else {
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      (*(uint8_t *)((uint8_t *)&(pixels_x00121.seg))) = uVar25;
      pixels_x00121.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_x00121.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00121,0,iVar18,54,0,uVar25,0
                                ,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xbd].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xbd) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_x00122.seg))) = uVar25;
      pixels_x00122.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_x00122.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00122,62,
                                iVar18,116,0,uVar25,0x3e,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xbe].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xbe) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_x00123.seg))) = uVar25;
      pixels_x00123.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_x00123.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00123,62,
                                iVar18,116,0,uVar25,0x3e,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xbf].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xbf) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
    }
    uVar19 = 0x195d;
    iVar10 = iVar10 + 1;
  }
  if (grab != false) {
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(503);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar19,psVar4);
  }
  iVar10 = 0;
  while( true ) {
    if (3 < iVar10) break;
    if (grab == false) {
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xc0].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xc0) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xc1].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xc1) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xc2].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xc2) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
    }
    else {
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      (*(uint8_t *)((uint8_t *)&(pixels_x00124.seg))) = uVar25;
      pixels_x00124.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_x00124.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00124,0,iVar18,54,0,uVar25,0
                                ,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xc0].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xc0) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_x00125.seg))) = uVar25;
      pixels_x00125.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_x00125.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00125,62,
                                iVar18,116,0,uVar25,0x3e,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xc1].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xc1) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_x00126.seg))) = uVar25;
      pixels_x00126.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_x00126.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00126,62,
                                iVar18,116,0,uVar25,0x3e,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xc2].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xc2) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
    }
    uVar19 = 0x195d;
    iVar10 = iVar10 + 1;
  }
  if (grab != false) {
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(504);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar19,psVar4);
  }
  iVar10 = 0;
  while( true ) {
    if (3 < iVar10) break;
    if (grab == false) {
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xc3].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xc3) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xc4].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xc4) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xc5].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xc5) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
    }
    else {
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      (*(uint8_t *)((uint8_t *)&(pixels_x00127.seg))) = uVar25;
      pixels_x00127.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_x00127.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00127,0,iVar18,54,0,uVar25,0
                                ,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xc3].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xc3) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_x00128.seg))) = uVar25;
      pixels_x00128.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_x00128.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00128,62,
                                iVar18,116,0,uVar25,0x3e,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xc4].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xc4) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_x00129.seg))) = uVar25;
      pixels_x00129.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_x00129.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00129,62,
                                iVar18,116,0,uVar25,0x3e,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xc5].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xc5) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
    }
    uVar19 = 0x195d;
    iVar10 = iVar10 + 1;
  }
  if (grab != false) {
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(505);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar19,psVar4);
  }
  iVar10 = 0;
  while( true ) {
    if (3 < iVar10) break;
    if (grab == false) {
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[0xc6].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xc6) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[199].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 199) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(uint16_t *)((int)&BldGfxNormal[200].seg + iVar10 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t far *)(BldGfxNormal + 200) + iVar10 * 0x12)->ofs = (uint16_t)uVar22;
    }
    else {
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      (*(uint8_t *)((uint8_t *)&(pixels_x00130.seg))) = uVar25;
      pixels_x00130.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_x00130.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00130,0,iVar18,54,0,uVar25,0
                                ,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[0xc6].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 0xc6) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_x00131.seg))) = uVar25;
      pixels_x00131.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_x00131.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00131,62,
                                iVar18,116,0,uVar25,0x3e,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[199].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 199) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar18 = iVar10 * 0x30 + 0x32;
      uVar16 = (uint16_t)((ulong)((long)iVar10 * 0x30) >> 0x10);
      iVar7 = (int)((long)iVar10 * 0x30) + 3;
      uVar25 = (undefined1)iVar7;
      uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_x00132.seg))) = uVar25;
      pixels_x00132.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_x00132.seg) + 1)) = (char)((uint)iVar7 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00132,62,
                                iVar18,116,0,uVar25,0x3e,(char)iVar18,0);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      *(uint16_t *)((int)&BldGfxNormal[200].seg + iVar10 * 0x48) = uVar16;
      ((far_t far *)(BldGfxNormal + 200) + iVar10 * 0x12)->ofs = (uint16_t)pcVar6;
    }
    uVar19 = 0x195d;
    iVar10 = iVar10 + 1;
  }
  if (grab != false) {
    ovr_stgFreeTmp(stgTmp,0);
  }
  for (iStack_4 = 0; iStack_4 < 0x12; iStack_4 = iStack_4 + 1) {
    ovr_stshStubifyFromSrc(iStack_4 + 0x43,0,0);
  }
  if (grab != false) {
    psVar4 = ovr_grabLbmTR(11);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar19,psVar4);
  }
  for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
    for (iStack_4 = 0; iStack_4 < 3; iStack_4 = iStack_4 + 1) {
      if (grab == false) {
        uVar22 = func_0x0007ffe0();
        iVar18 = iVar10 * 3 + iStack_4;
        *(uint16_t *)((int)&BldGfxNormal[0x135].seg + iVar18 * 0xc) = (int)((ulong)uVar22 >> 0x10)
        ;
        ((far_t far *)(BldGfxNormal + 0x135) + iVar18 * 3)->ofs = (uint16_t)uVar22;
      }
      else {
        iVar18 = iStack_4 * 100 + 99;
        lVar1 = (long)iStack_4 * 100;
        uVar16 = (uint16_t)((ulong)lVar1 >> 0x10);
        uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
        (*(uint8_t *)((uint8_t *)&(pixels_x00133.seg))) = (char)lVar1;
        pixels_x00133.ofs = *(uint16_t *)((int)stgTmp + 0x302);
        (*(uint8_t *)((uint8_t *)&(pixels_x00133.seg) + 1)) = (char)((ulong)lVar1 >> 8);
        pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00133,
                                  iVar10 * 0x41,iVar18,iVar10 * 0x41 + 0x40,30,(char)lVar1,
                                  (char)(iVar10 * 0x41),(char)iVar18,0x1e);
        pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
        iVar18 = iVar10 * 3 + iStack_4;
        *(uint16_t *)((int)&BldGfxNormal[0x135].seg + iVar18 * 0xc) = uVar16;
        ((far_t far *)(BldGfxNormal + 0x135) + iVar18 * 3)->ofs = (uint16_t)pcVar6;
      }
      iVar18 = iVar10 * 3 + iStack_4;
      uVar19 = ((far_t far *)(BldGfxNormal + 0x135) + iVar18 * 3)->ofs;
      iVar7 = iVar10 * 3 + iStack_4;
      *(uint16_t *)((int)&BldGfxNormal[0x136].seg + iVar7 * 0xc) =
           *(uint16_t *)((int)&BldGfxNormal[0x135].seg + iVar18 * 0xc);
      ((far_t far *)(BldGfxNormal + 0x136) + iVar7 * 3)->ofs = uVar19;
      iVar18 = iVar10 * 3 + iStack_4;
      uVar19 = *(uint16_t *)((int)&BldGfxNormal[0x135].seg + iVar18 * 0xc);
      uVar14 = ((far_t far *)(BldGfxNormal + 0x135) + iVar18 * 3)->ofs;
      iVar18 = iVar10 * 3 + iStack_4;
      *(uint16_t *)((int)&BldGfxNormal[0x137].seg + iVar18 * 0xc) = uVar19;
      ((far_t far *)(BldGfxNormal + 0x137) + iVar18 * 3)->ofs = uVar14;
    }
  }
  if (grab == false) {
    BldGfxNormal[0x151] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(52);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar19,psVar4);
    (*(uint8_t *)((uint8_t *)&(pixels_x00134.seg))) = 0xa7;
    pixels_x00134.ofs = (psVar4->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00134.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_x00134,12,206,32,-4,0xa7,0xc,0xce
                              ,0xfc);
    pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
    BldGfxNormal[0x151].seg = uVar19;
    BldGfxNormal[0x151].ofs = (uint16_t)pcVar6;
  }
  uVar19 = BldGfxNormal[0x151].seg;
  ovr_StubifyCopy1to0_alt(0x70);
  if (grab == false) {
    BldGfxNormal[0x154] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00135.seg))) = 0xa7;
    pixels_x00135.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00135.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00135,45,206,
                              65,-4,0xa7,0x2d,0xce,0xfc);
    pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
    BldGfxNormal[0x154].seg = uVar19;
    BldGfxNormal[0x154].ofs = (uint16_t)pcVar6;
  }
  uVar19 = BldGfxNormal[0x154].seg;
  ovr_StubifyCopy1to0_alt(0x71);
  if (grab == false) {
    BldGfxNormal[0x157] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00136.seg))) = 0xa7;
    pixels_x00136.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00136.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00136,78,206,
                              98,-4,0xa7,0x4e,0xce,0xfc);
    pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
    BldGfxNormal[0x157].seg = uVar19;
    BldGfxNormal[0x157].ofs = (uint16_t)pcVar6;
  }
  uVar19 = BldGfxNormal[0x157].seg;
  ovr_StubifyCopy1to0_alt(0x72);
  if (grab == false) {
    for (iStack_4 = 0; iStack_4 < 6; iStack_4 = iStack_4 + 1) {
      uVar22 = func_0x0007ffe0();
      uVar19 = AnimSeqPtr[1].seg;
      puVar17 = (uint16_t *)(AnimSeqPtr[1].ofs + iStack_4 * 4);
      puVar17[1] = (int)((ulong)uVar22 >> 0x10);
      *puVar17 = (int)uVar22;
      uVar22 = func_0x0007ffe0();
      uVar19 = AnimSeqPtr[2].seg;
      puVar17 = (uint16_t *)(AnimSeqPtr[2].ofs + iStack_4 * 4);
      puVar17[1] = (int)((ulong)uVar22 >> 0x10);
      *puVar17 = (int)uVar22;
    }
    uVar22 = func_0x0007ffe0();
    uVar14 = AnimSeqPtr[1].seg;
    uVar19 = AnimSeqPtr[1].ofs;
    *(uint16_t *)(uVar19 + 0x1a) = (int)((ulong)uVar22 >> 0x10);
    *(uint16_t *)(uVar19 + 0x18) = (int)uVar22;
    uVar22 = func_0x0007ffe0();
    uVar19 = (uint16_t)((ulong)uVar22 >> 0x10);
    uVar21 = AnimSeqPtr[2].seg;
    uVar14 = AnimSeqPtr[2].ofs;
    *(uint16_t *)(uVar14 + 0x1a) = uVar19;
    *(uint16_t *)(uVar14 + 0x18) = (int)uVar22;
  }
  else {
    iStack_4 = 0;
    while( true ) {
      iVar10 = (int)stgTmp;
      uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
      if (5 < iStack_4) break;
      uVar20 = (uint16_t)((ulong)((long)iStack_4 * 0x21) >> 0x10);
      iVar18 = (int)((long)iStack_4 * 0x21) + 0x14;
      (*(uint8_t *)((uint8_t *)&(pixels_x00137.seg))) = 0xd;
      pixels_x00137.ofs = *(uint16_t *)(iVar10 + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_x00137.seg) + 1)) = 0;
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)(iVar10 + 0x300),pixels_x00137,iVar18,16,
                                iStack_4 * 0x21 + 0x20,-22,0xd,(char)iVar18,0x10,0xea);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar19 = AnimSeqPtr[1].seg;
      puVar17 = (uint16_t *)(AnimSeqPtr[1].ofs + iStack_4 * 4);
      puVar17[1] = uVar20;
      *puVar17 = (uint16_t)pcVar6;   /* hand fix: 2-byte slot */
      uVar19 = (uint16_t)((ulong)((long)iStack_4 * 0x21) >> 0x10);
      iVar10 = (int)((long)iStack_4 * 0x21) + 0x14;
      uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
      (*(uint8_t *)((uint8_t *)&(pixels_x00138.seg))) = 0x5f;
      pixels_x00138.ofs = *(uint16_t *)((int)stgTmp + 0x302);
      (*(uint8_t *)((uint8_t *)&(pixels_x00138.seg) + 1)) = 0;
      pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00138,
                                iVar10,98,iStack_4 * 0x21 + 0x20,-22,0x5f,(char)iVar10,0x62,0xea);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = AnimSeqPtr[2].seg;
      puVar17 = (uint16_t *)(AnimSeqPtr[2].ofs + iStack_4 * 4);
      puVar17[1] = uVar19;
      *puVar17 = (uint16_t)pcVar6;   /* hand fix: 2-byte slot */
      iStack_4 = iStack_4 + 1;
    }
    (*(uint8_t *)((uint8_t *)&(pixels_x00139.seg))) = 0x2b;
    pixels_x00139.ofs = *(uint16_t *)(iVar10 + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00139.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)(iVar10 + 0x300),pixels_x00139,20,46,32,-22,
                              0x2b,0x14,0x2e,0xea);
    pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar21 = AnimSeqPtr[1].seg;
    uVar14 = AnimSeqPtr[1].ofs;
    *(uint16_t *)(uVar14 + 0x1a) = uVar19;
    *(uint16_t *)(uVar14 + 0x18) = (uint16_t)pcVar6;   /* hand fix */
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00140.seg))) = 0x7d;
    pixels_x00140.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00140.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00140,20,128,
                              32,-22,0x7d,0x14,0x80,0xea);
    pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar21 = AnimSeqPtr[2].seg;
    uVar14 = AnimSeqPtr[2].ofs;
    *(uint16_t *)(uVar14 + 0x1a) = uVar19;
    *(uint16_t *)(uVar14 + 0x18) = (uint16_t)pcVar6;   /* hand fix */
    ovr_stgFreeTmp(stgTmp,0);
  }
  builtin_memcpy(&ram0x0000d528 + 0x153,"\x02\x02\x02\x03\x03\x03",6);
  if (grab == false) {
    BldGfxNormal[0x15a] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x15d] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x160] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x15a] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x15d] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x160] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar19 = 0x195d;
  }
  else {
    stgTmp = ovr_grabLbmTR(308);
    (*(uint8_t *)((uint8_t *)&(pixels_x00141.seg))) = 2;
    pixels_x00141.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00141.seg) + 1)) = 0;
    puStack_a = (uint8_t *)uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00141,86,85,180,-2,2,0x56,0x55
                              ,0xfe);
    BldGfxNormal[0x15a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00142.seg))) = 0x6c;
    pixels_x00142.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00142.seg) + 1)) = 0;
    BldGfxNormal[0x15a].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00142,86,191,180,-2,0x6c,0x56,
                              0xbf,0xfe);
    BldGfxNormal[0x15d].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00143.seg))) = 0xd0;
    pixels_x00143.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00143.seg) + 1)) = 0;
    BldGfxNormal[0x15d].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00143,86,298,180,0,0xd0,0x56,
                              0x2a,0);
    BldGfxNormal[0x160].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    BldGfxNormal[0x160].seg = uVar19;
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(309);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    (*(uint8_t *)((uint8_t *)&(pixels_x00144.seg))) = 2;
    pixels_x00144.ofs = (psVar4->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00144.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_x00144,86,85,180,-2,2,0x56,0x55,
                              0xfe);
    BldGfxRuin[0x15a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00145.seg))) = 0x6c;
    pixels_x00145.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00145.seg) + 1)) = 0;
    BldGfxRuin[0x15a].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00145,86,191,
                              180,-2,0x6c,0x56,0xbf,0xfe);
    BldGfxRuin[0x15d].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00146.seg))) = 0xd0;
    pixels_x00146.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00146.seg) + 1)) = 0;
    BldGfxRuin[0x15d].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00146,86,298,
                              180,0,0xd0,0x56,0x2a,0);
    BldGfxRuin[0x160].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    BldGfxRuin[0x160].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
  }
  ovr_stshStubifyCopy1to0(0x73);
  if (grab == false) {
    BldGfxNormal[0x163] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x166] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x169] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x163] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x166] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x169] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar19 = 0x195d;
  }
  else {
    stgTmp = ovr_grabLbmTR(467);
    (*(uint8_t *)((uint8_t *)&(pixels_x00147.seg))) = 4;
    pixels_x00147.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00147.seg) + 1)) = 0;
    puStack_a = (uint8_t *)uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00147,74,91,180,-3,4,0x4a,0x5b
                              ,0xfd);
    BldGfxNormal[0x163].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00148.seg))) = 0x6e;
    pixels_x00148.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00148.seg) + 1)) = 0;
    BldGfxNormal[0x163].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00148,74,195,180,-3,0x6e,0x4a,
                              0xc3,0xfd);
    BldGfxNormal[0x166].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00149.seg))) = 0xcc;
    pixels_x00149.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00149.seg) + 1)) = 0;
    BldGfxNormal[0x166].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00149,74,299,180,3,0xcc,0x4a,
                              0x2b,3);
    BldGfxNormal[0x169].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    BldGfxNormal[0x169].seg = uVar19;
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(468);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    (*(uint8_t *)((uint8_t *)&(pixels_x00150.seg))) = 4;
    pixels_x00150.ofs = (psVar4->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00150.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_x00150,74,91,180,-3,4,0x4a,0x5b,
                              0xfd);
    BldGfxRuin[0x163].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00151.seg))) = 0x6e;
    pixels_x00151.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00151.seg) + 1)) = 0;
    BldGfxRuin[0x163].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00151,74,195,
                              180,-3,0x6e,0x4a,0xc3,0xfd);
    BldGfxRuin[0x166].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00152.seg))) = 0xcc;
    pixels_x00152.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00152.seg) + 1)) = 0;
    BldGfxRuin[0x166].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00152,74,299,
                              180,3,0xcc,0x4a,0x2b,3);
    BldGfxRuin[0x169].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    BldGfxRuin[0x169].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
  }
  ovr_stshStubifyCopy1to0(0x76);
  ovr_stubyBufSrcToDst(0x76,0,0);
  ovr_stubyBufSrcToDst(0x73,0,0);
  ovr_stubyBufSrcToDst(0x76,0,0);
  if (grab == false) {
    BldGfxNormal[0x186] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x187] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x188] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x186] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x187] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x188] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar21 = 0x195d;
  }
  else {
    stgTmp = ovr_grabLbmTR(513);
    (*(uint8_t *)((uint8_t *)&(pixels_x00153.seg))) = 2;
    pixels_x00153.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00153.seg) + 1)) = 0;
    puStack_a = (uint8_t *)uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00153,70,86,180,0,2,0x46,0x56,
                              0);
    BldGfxNormal[0x186].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00154.seg))) = 0x6c;
    pixels_x00154.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00154.seg) + 1)) = 0;
    BldGfxNormal[0x186].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00154,70,191,180,0,0x6c,0x46,
                              0xbf,0);
    BldGfxNormal[0x187].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00155.seg))) = 0xd7;
    pixels_x00155.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00155.seg) + 1)) = 0;
    BldGfxNormal[0x187].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00155,70,298,180,0,0xd7,0x46,
                              0x2a,0);
    BldGfxNormal[0x188].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    BldGfxNormal[0x188].seg = uVar19;
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(514);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    (*(uint8_t *)((uint8_t *)&(pixels_x00156.seg))) = 2;
    pixels_x00156.ofs = (psVar4->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00156.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_x00156,70,86,180,0,2,0x46,0x56,0)
    ;
    BldGfxRuin[0x186].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00157.seg))) = 0x6c;
    pixels_x00157.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00157.seg) + 1)) = 0;
    BldGfxRuin[0x186].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00157,70,191,
                              180,0,0x6c,0x46,0xbf,0);
    BldGfxRuin[0x187].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00158.seg))) = 0xd7;
    pixels_x00158.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00158.seg) + 1)) = 0;
    BldGfxRuin[0x187].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00158,70,298,
                              180,0,0xd7,0x46,0x2a,0);
    BldGfxRuin[0x188].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar21 = 0x195d;
    BldGfxRuin[0x188].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
  }
  uVar19 = 0x83;
  if (grab == false) {
    uVar22 = func_0x0007ffe0();
    unaff_DI = (int)((ulong)uVar22 >> 0x10);
    uVar25 = (undefined1)uVar22;
    uVar31 = (undefined1)((ulong)uVar22 >> 8);
    uVar9 = 0x83;
    iVar10 = 0xc;
    uVar24 = 0x4c;
    fVar2 = BldGfxNormal[100];
code_r0x00074dd0:
    uVar23 = uVar24;
    uVar9 = uVar9 * iVar10;
    goto code_r0x00074dd2;
  }
  stgTmp = ovr_grabLbmTR(517);
  (*(uint8_t *)((uint8_t *)&(pixels_x00159.seg))) = 2;
  pixels_x00159.ofs = (stgTmp->aptr).seg;
  (*(uint8_t *)((uint8_t *)&(pixels_x00159.seg) + 1)) = 0;
  puStack_a = (uint8_t *)uVar21;
  pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00159,70,86,180,0,2,0x46,0x56,0)
  ;
  BldGfxNormal[0x189].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
  uVar19 = 0x195d;
  (*(uint8_t *)((uint8_t *)&(pixels_x00160.seg))) = 0x6c;
  pixels_x00160.ofs = (stgTmp->aptr).seg;
  (*(uint8_t *)((uint8_t *)&(pixels_x00160.seg) + 1)) = 0;
  BldGfxNormal[0x189].seg = uVar21;
  pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00160,70,191,180,0,0x6c,0x46,
                            0xbf,0);
  BldGfxNormal[0x18a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
  uVar14 = 0x195d;
  (*(uint8_t *)((uint8_t *)&(pixels_x00161.seg))) = 0xd7;
  pixels_x00161.ofs = (stgTmp->aptr).seg;
  (*(uint8_t *)((uint8_t *)&(pixels_x00161.seg) + 1)) = 0;
  BldGfxNormal[0x18a].seg = uVar19;
  pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00161,70,298,180,0,0xd7,0x46,
                            0x2a,0);
  BldGfxNormal[0x18b].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
  uVar19 = 0x195d;
  BldGfxNormal[0x18b].seg = uVar14;
  ovr_stgFreeTmp(stgTmp,0);
  psVar4 = ovr_grabLbmTR(518);
  stgTmp = (stg_tmp_t *)CONCAT22(uVar19,psVar4);
  (*(uint8_t *)((uint8_t *)&(pixels_x00162.seg))) = 2;
  pixels_x00162.ofs = (psVar4->aptr).seg;
  (*(uint8_t *)((uint8_t *)&(pixels_x00162.seg) + 1)) = 0;
  pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_x00162,70,86,180,0,2,0x46,0x56,0);
  BldGfxRuin[0x189].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
  uVar14 = 0x195d;
  uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
  (*(uint8_t *)((uint8_t *)&(pixels_x00163.seg))) = 0x6c;
  pixels_x00163.ofs = *(uint16_t *)((int)stgTmp + 0x302);
  (*(uint8_t *)((uint8_t *)&(pixels_x00163.seg) + 1)) = 0;
  BldGfxRuin[0x189].seg = uVar19;
  pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00163,70,191,
                            180,0,0x6c,0x46,0xbf,0);
  BldGfxRuin[0x18a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
  uVar19 = 0x195d;
  uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
  (*(uint8_t *)((uint8_t *)&(pixels_x00164.seg))) = 0xd7;
  pixels_x00164.ofs = *(uint16_t *)((int)stgTmp + 0x302);
  (*(uint8_t *)((uint8_t *)&(pixels_x00164.seg) + 1)) = 0;
  BldGfxRuin[0x18a].seg = uVar14;
  pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00164,70,298,
                            180,0,0xd7,0x46,0x2a,0);
  BldGfxRuin[0x18b].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
  uVar14 = 0x195d;
  BldGfxRuin[0x18b].seg = uVar19;
  ovr_stgFreeTmp(stgTmp,0);
L_init_assets_4EA5:
  if (grab == false) {
    BldGfxNormal[0x18d] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x18e] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x18e] = BldGfxNormal[0x18d];
    BldGfxNormal[0x18c] = BldGfxNormal[0x18d];
    BldGfxRuin[0x18c] = BldGfxRuin[0x18e];
    BldGfxRuin[0x18d] = BldGfxRuin[0x18e];
    BldGfxNormal[399] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[400] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x191] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[399] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[400] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x191] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x193] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x194] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x194] = BldGfxNormal[0x193];
    BldGfxNormal[0x192] = BldGfxNormal[0x193];
    BldGfxRuin[0x192] = BldGfxRuin[0x194];
    BldGfxRuin[0x193] = BldGfxRuin[0x194];
    BldGfxNormal[0x196] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x197] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x197] = BldGfxNormal[0x196];
    BldGfxNormal[0x195] = BldGfxNormal[0x196];
    BldGfxRuin[0x195] = BldGfxRuin[0x197];
    BldGfxRuin[0x196] = BldGfxRuin[0x197];
    for (iStack_4 = 0; iStack_4 < 5; iStack_4 = iStack_4 + 1) {
      uVar22 = func_0x0007ffe0();
      uVar19 = AnimSeqPtr[0].seg;
      puVar17 = (uint16_t *)(AnimSeqPtr[0].ofs + iStack_4 * 4);
      puVar17[1] = (int)((ulong)uVar22 >> 0x10);
      *puVar17 = (int)uVar22;
    }
    BldGfxNormal[0x199] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x199] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar19 = 0x195d;
  }
  else {
    stgTmp = ovr_grabLbmTR(525);
    (*(uint8_t *)((uint8_t *)&(pixels_x00165.seg))) = 0x6c;
    pixels_x00165.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00165.seg) + 1)) = 0;
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00165,70,191,180,0,0x6c,0x46,
                              0xbf,0);
    BldGfxNormal[0x18d].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    BldGfxNormal[0x18d].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(526);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar19,psVar4);
    (*(uint8_t *)((uint8_t *)&(pixels_x00166.seg))) = 0x6c;
    pixels_x00166.ofs = (psVar4->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00166.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_x00166,70,191,180,0,0x6c,0x46,
                              0xbf,0);
    BldGfxRuin[0x18d].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    BldGfxRuin[0x18d].seg = uVar19;
    ovr_stgFreeTmp(stgTmp,0);
    uVar19 = BldGfxRuin[0x18d].seg;
    BldGfxRuin[0x18c].ofs = BldGfxRuin[0x18d].ofs;
    BldGfxRuin[0x18c].seg = BldGfxRuin[0x18d].seg;
    BldGfxRuin[0x18e].ofs = BldGfxRuin[0x18d].ofs;
    BldGfxRuin[0x18e].seg = BldGfxRuin[0x18d].seg;
    BldGfxNormal[0x18c].ofs = BldGfxNormal[0x18d].ofs;
    BldGfxNormal[0x18c].seg = BldGfxNormal[0x18d].seg;
    BldGfxNormal[0x18e].ofs = BldGfxNormal[0x18d].ofs;
    BldGfxNormal[0x18e].seg = BldGfxNormal[0x18d].seg;
    stgTmp = ovr_grabLbmTR(515);
    (*(uint8_t *)((uint8_t *)&(pixels_x00167.seg))) = 2;
    pixels_x00167.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00167.seg) + 1)) = 0;
    puStack_a = (uint8_t *)uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00167,70,86,180,0,2,0x46,0x56,
                              0);
    BldGfxNormal[399].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00168.seg))) = 0x6c;
    pixels_x00168.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00168.seg) + 1)) = 0;
    BldGfxNormal[399].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00168,70,191,180,0,0x6c,0x46,
                              0xbf,0);
    BldGfxNormal[400].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00169.seg))) = 0xd7;
    pixels_x00169.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00169.seg) + 1)) = 0;
    BldGfxNormal[400].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00169,70,298,180,0,0xd7,0x46,
                              0x2a,0);
    BldGfxNormal[0x191].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    BldGfxNormal[0x191].seg = uVar19;
    ovr_stgFreeTmp(stgTmp,0);
    stgTmp = ovr_grabLbmTR(516);
    (*(uint8_t *)((uint8_t *)&(pixels_x00170.seg))) = 2;
    pixels_x00170.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00170.seg) + 1)) = 0;
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00170,70,86,180,0,2,0x46,0x56,
                              0);
    BldGfxRuin[399].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00171.seg))) = 0x6c;
    pixels_x00171.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00171.seg) + 1)) = 0;
    BldGfxRuin[399].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00171,70,191,180,0,0x6c,0x46,
                              0xbf,0);
    BldGfxRuin[400].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00172.seg))) = 0xd7;
    pixels_x00172.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00172.seg) + 1)) = 0;
    BldGfxRuin[400].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00172,70,298,180,0,0xd7,0x46,
                              0x2a,0);
    BldGfxRuin[0x191].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    BldGfxRuin[0x191].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
    stgTmp = ovr_grabLbmTR(519);
    (*(uint8_t *)((uint8_t *)&(pixels_x00173.seg))) = 0x6c;
    pixels_x00173.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00173.seg) + 1)) = 0;
    puStack_a = (uint8_t *)uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00173,70,191,180,0,0x6c,0x46,
                              0xbf,0);
    BldGfxNormal[0x193].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    BldGfxNormal[0x193].seg = uVar19;
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(520);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    (*(uint8_t *)((uint8_t *)&(pixels_x00174.seg))) = 0x6c;
    pixels_x00174.ofs = (psVar4->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00174.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_x00174,70,191,180,0,0x6c,0x46,
                              0xbf,0);
    BldGfxRuin[0x193].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    BldGfxRuin[0x193].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
    uVar19 = BldGfxRuin[0x193].seg;
    BldGfxRuin[0x192].ofs = BldGfxRuin[0x193].ofs;
    BldGfxRuin[0x192].seg = BldGfxRuin[0x193].seg;
    BldGfxRuin[0x194].ofs = BldGfxRuin[0x193].ofs;
    BldGfxRuin[0x194].seg = BldGfxRuin[0x193].seg;
    BldGfxNormal[0x192].ofs = BldGfxNormal[0x193].ofs;
    BldGfxNormal[0x192].seg = BldGfxNormal[0x193].seg;
    BldGfxNormal[0x194].ofs = BldGfxNormal[0x193].ofs;
    BldGfxNormal[0x194].seg = BldGfxNormal[0x193].seg;
    stgTmp = ovr_grabLbmTR(521);
    (*(uint8_t *)((uint8_t *)&(pixels_x00175.seg))) = 0x6c;
    pixels_x00175.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00175.seg) + 1)) = 0;
    puStack_a = (uint8_t *)uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00175,70,191,180,0,0x6c,0x46,
                              0xbf,0);
    BldGfxNormal[0x196].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    BldGfxNormal[0x196].seg = uVar19;
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(522);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    (*(uint8_t *)((uint8_t *)&(pixels_x00176.seg))) = 0x6c;
    pixels_x00176.ofs = (psVar4->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00176.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_x00176,70,191,180,0,0x6c,0x46,
                              0xbf,0);
    BldGfxRuin[0x196].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    BldGfxRuin[0x196].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
    uVar19 = BldGfxRuin[0x196].seg;
    BldGfxRuin[0x195].ofs = BldGfxRuin[0x196].ofs;
    BldGfxRuin[0x195].seg = BldGfxRuin[0x196].seg;
    BldGfxRuin[0x197].ofs = BldGfxRuin[0x196].ofs;
    BldGfxRuin[0x197].seg = BldGfxRuin[0x196].seg;
    BldGfxNormal[0x195].ofs = BldGfxNormal[0x196].ofs;
    BldGfxNormal[0x195].seg = BldGfxNormal[0x196].seg;
    BldGfxNormal[0x197].ofs = BldGfxNormal[0x196].ofs;
    BldGfxNormal[0x197].seg = BldGfxNormal[0x196].seg;
    stgTmp = ovr_grabLbmTR(523);
    puStack_a = (uint8_t *)uVar19;
    for (iStack_4 = 0; iStack_4 < 5; iStack_4 = iStack_4 + 1) {
      iVar10 = iStack_4 * 0x22 + 0x68;
      uVar19 = (uint16_t)((ulong)((long)iStack_4 * 0x22) >> 0x10);
      iVar18 = (int)((long)iStack_4 * 0x22) + 0x50;
      uVar25 = (undefined1)iVar18;
      (*(uint8_t *)((uint8_t *)&(pixels_x00177.seg))) = uVar25;
      pixels_x00177.ofs = (stgTmp->aptr).seg;
      (*(uint8_t *)((uint8_t *)&(pixels_x00177.seg) + 1)) = (char)((uint)iVar18 >> 8);
      pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00177,39,iVar10,58,-68,
                                uVar25,0x27,(char)iVar10,0xbc);
      pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
      uVar14 = AnimSeqPtr[0].seg;
      puVar17 = (uint16_t *)(AnimSeqPtr[0].ofs + iStack_4 * 4);
      puVar17[1] = uVar19;
      *puVar17 = (uint16_t)pcVar6;   /* hand fix: 2-byte slot */
    }
    (*(uint8_t *)((uint8_t *)&(pixels_x00178.seg))) = 0x52;
    pixels_x00178.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00178.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00178,87,222,181,22,0x52,0x57,
                              0xde,0x16);
    BldGfxNormal[0x199].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    BldGfxNormal[0x199].seg = uVar19;
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(524);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    (*(uint8_t *)((uint8_t *)&(pixels_x00179.seg))) = 0x52;
    pixels_x00179.ofs = (psVar4->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00179.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_x00179,87,222,181,22,0x52,0x57,
                              0xde,0x16);
    BldGfxRuin[0x199].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    BldGfxRuin[0x199].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
  }
  ovr_StubifyCopy1to0_alt(0x88);
  BldFlags[0x198] = 0x1;
  BldFlags[0x199] = 0x1;
  BldFlags[0x19a] = 0x1;
  if (grab == false) {
    BldGfxNormal[0x19c] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x19f] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x19c] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x19f] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1a2] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x1a2] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar19 = 0x195d;
  }
  else {
    stgTmp = ovr_grabLbmTR(156);
    pixels_x00180.seg = 0;
    pixels_x00180.ofs = (stgTmp->aptr).seg;
    puStack_a = (uint8_t *)uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00180,101,319,199,60,0,0x65,
                              0x3f,0x3c);
    BldGfxNormal[0x19c].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    pixels_x00181.seg = 0;
    pixels_x00181.ofs = (stgTmp->aptr).seg;
    BldGfxNormal[0x19c].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00181,0,319,100,60,0,0,0x3f,
                              0x3c);
    BldGfxNormal[0x19f].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    BldGfxNormal[0x19f].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
    stgTmp = ovr_grabLbmTR(441);
    pixels_x00182.seg = 0;
    pixels_x00182.ofs = (stgTmp->aptr).seg;
    puStack_a = (uint8_t *)uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00182,101,319,199,60,0,0x65,
                              0x3f,0x3c);
    BldGfxRuin[0x19c].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    pixels_x00183.seg = 0;
    pixels_x00183.ofs = (stgTmp->aptr).seg;
    BldGfxRuin[0x19c].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00183,0,319,100,60,0,0,0x3f,
                              0x3c);
    BldGfxRuin[0x19f].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    BldGfxRuin[0x19f].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
    stgTmp = ovr_grabLbmTR(157);
    pixels_x00184.seg = 0;
    pixels_x00184.ofs = (stgTmp->aptr).seg;
    puStack_a = (uint8_t *)uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00184,70,319,193,60,0,0x46,
                              0x3f,0x3c);
    BldGfxNormal[0x1a2].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    BldGfxNormal[0x1a2].seg = uVar19;
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(440);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    pixels_x00185.seg = 0;
    pixels_x00185.ofs = (psVar4->aptr).seg;
    pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_x00185,70,319,193,60,0,0x46,0x3f,
                              0x3c);
    BldGfxRuin[0x1a2].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    BldGfxRuin[0x1a2].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
  }
  ovr_stshStubifyCopy1to0(0x89);
  ovr_stubyBufSrcToDst(0x73,0,0);
  if (grab == false) {
    BldGfxNormal[0x1ae] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1b1] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1b4] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x1ae] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x1b1] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x1b4] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar19 = 0x195d;
  }
  else {
    stgTmp = ovr_grabLbmTR(318);
    (*(uint8_t *)((uint8_t *)&(pixels_x00186.seg))) = 8;
    pixels_x00186.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00186.seg) + 1)) = 0;
    puStack_a = (uint8_t *)uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00186,50,110,154,-4,8,0x32,
                              0x6e,0xfc);
    BldGfxNormal[0x1ae].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00187.seg))) = 0x6f;
    pixels_x00187.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00187.seg) + 1)) = 0;
    BldGfxNormal[0x1ae].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00187,50,212,154,-4,0x6f,0x32,
                              0xd4,0xfc);
    BldGfxNormal[0x1b1].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00188.seg))) = 0xd5;
    pixels_x00188.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00188.seg) + 1)) = 0;
    BldGfxNormal[0x1b1].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00188,50,313,154,-4,0xd5,0x32,
                              0x39,0xfc);
    BldGfxNormal[0x1b4].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    BldGfxNormal[0x1b4].seg = uVar19;
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(319);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    (*(uint8_t *)((uint8_t *)&(pixels_x00189.seg))) = 8;
    pixels_x00189.ofs = (psVar4->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00189.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_x00189,50,110,154,-4,8,0x32,0x6e,
                              0xfc);
    BldGfxRuin[0x1ae].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00190.seg))) = 0x6f;
    pixels_x00190.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00190.seg) + 1)) = 0;
    BldGfxRuin[0x1ae].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00190,50,212,
                              154,-4,0x6f,0x32,0xd4,0xfc);
    BldGfxRuin[0x1b1].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00191.seg))) = 0xd5;
    pixels_x00191.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00191.seg) + 1)) = 0;
    BldGfxRuin[0x1b1].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00191,50,313,
                              154,-4,0xd5,0x32,0x39,0xfc);
    BldGfxRuin[0x1b4].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    BldGfxRuin[0x1b4].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
  }
  ovr_stshStubifyCopy1to0(0x8f);
  iVar10 = 0x92;
  if (grab != false) {
    psVar4 = ovr_grabLbm(17,0,0,0,0);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar19,psVar4);
    pixels_x00200.seg = (psVar4->aptr).seg;
    pixels_x00200.ofs = (&psVar4->aptr)->ofs;
    ovr_grabRemap(pixels_x00200,0xff,0x0,0xff);
  }
  for (iVar18 = 0; iVar18 < 3; iVar18 = iVar18 + 1) {
    for (iStack_4 = 0; iStack_4 < 2; iStack_4 = iStack_4 + 1) {
      if ((iStack_4 != 0) || (iVar18 != 0)) {
        if (grab == false) {
          uVar22 = func_0x0007ffe0();
          *(uint16_t *)((int)&BldGfxNormal[0].seg + iVar10 * 0xc) = (int)((ulong)uVar22 >> 0x10);
          ((far_t far *)BldGfxNormal + iVar10 * 3)->ofs = (uint16_t)uVar22;
        }
        else {
          iVar7 = iStack_4 * 0x87 + 0x86;
          lVar1 = (long)iStack_4 * 0x87;
          uVar16 = (uint16_t)((ulong)lVar1 >> 0x10);
          uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
          (*(uint8_t *)((uint8_t *)&(pixels_x00192.seg))) = (char)lVar1;
          pixels_x00192.ofs = *(uint16_t *)((int)stgTmp + 0x302);
          (*(uint8_t *)((uint8_t *)&(pixels_x00192.seg) + 1)) = (char)((ulong)lVar1 >> 8);
          pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00192,
                                    iVar18 * 0x41,iVar7,iVar18 * 0x41 + 0x40,30,(char)lVar1,
                                    (char)(iVar18 * 0x41),(char)iVar7,0x1e);
          pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
          *(uint16_t *)((int)&BldGfxNormal[0].seg + iVar10 * 0xc) = uVar16;
          ((far_t far *)BldGfxNormal + iVar10 * 3)->ofs = (uint16_t)pcVar6;
        }
        uVar19 = ((far_t far *)BldGfxNormal + iVar10 * 3)->ofs;
        *(uint16_t *)((int)&BldGfxNormal[1].seg + iVar10 * 0xc) =
             *(uint16_t *)((int)&BldGfxNormal[0].seg + iVar10 * 0xc);
        ((far_t far *)(BldGfxNormal + 1) + iVar10 * 3)->ofs = uVar19;
        uVar19 = *(uint16_t *)((int)&BldGfxNormal[0].seg + iVar10 * 0xc);
        uVar14 = ((far_t far *)BldGfxNormal + iVar10 * 3)->ofs;
        *(uint16_t *)((int)&BldGfxNormal[2].seg + iVar10 * 0xc) = uVar19;
        ((far_t far *)(BldGfxNormal + 2) + iVar10 * 3)->ofs = uVar14;
        iVar10 = iVar10 + 1;
      }
    }
  }
  if (grab == false) {
    BldGfxNormal[0x1c5] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1c6] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1c7] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(31);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar19,psVar4);
    uVar9 = (psVar4->aptr).seg;
    src_07.seg = 0;
    src_07.ofs = uVar9;
    pfVar5 = ovr_stshRleCut((far_t far *)(&psVar4->aptr)->ofs,src_07,18,200,(char)uVar9,0,200,0,0);
    BldGfxNormal[0x1c5].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
    uVar16 = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(src_08.seg))) = 0x83;
    src_08.ofs = uVar16;
    (*(uint8_t *)((uint8_t *)&(src_08.seg) + 1)) = 0;
    BldGfxNormal[0x1c5].seg = uVar19;
    pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src_08,74,179,(char)uVar16,0x83,0xb3,0,0);
    BldGfxNormal[0x1c6].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
    uVar16 = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(src_09.seg))) = 0x1f;
    src_09.ofs = uVar16;
    (*(uint8_t *)((uint8_t *)&(src_09.seg) + 1)) = 0;
    BldGfxNormal[0x1c6].seg = uVar14;
    pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src_09,49,79,(char)uVar16,0x1f,0x4f,0,0);
    pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
    BldGfxNormal[0x1c7].seg = uVar19;
    BldGfxNormal[0x1c7].ofs = (uint16_t)pcVar6;
  }
  BldGfxNormal[0x1ca] = BldGfxNormal[0x1c7];
  BldGfxNormal[0x1c8] = BldGfxNormal[0x1c5];
  BldGfxNormal[0x1c9] = BldGfxNormal[0x1c6];
  BldGfxNormal[0x1cd] = BldGfxNormal[0x1c7];
  BldGfxNormal[0x1cb] = BldGfxNormal[0x1c5];
  BldGfxNormal[0x1cc] = BldGfxNormal[0x1c6];
  if (grab == false) {
    BldGfxNormal[0x1ce] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1cf] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1d0] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    uVar9 = *(uint *)((int)stgTmp + 0x302);
    src_10.seg = 0;
    src_10.ofs = uVar9;
    uVar19 = BldGfxNormal[0x1c7].ofs;
    pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src_10,49,200,(char)uVar9,0,200,0,0);
    BldGfxNormal[0x1ce].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
    uVar16 = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(src_11.seg))) = 0x1f;
    src_11.ofs = uVar16;
    (*(uint8_t *)((uint8_t *)&(src_11.seg) + 1)) = 0;
    BldGfxNormal[0x1ce].seg = uVar19;
    pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src_11,74,79,(char)uVar16,0x1f,0x4f,0,0);
    BldGfxNormal[0x1cf].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
    uVar16 = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(src_12.seg))) = 0x83;
    src_12.ofs = uVar16;
    (*(uint8_t *)((uint8_t *)&(src_12.seg) + 1)) = 0;
    BldGfxNormal[0x1cf].seg = uVar14;
    pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src_12,49,179,(char)uVar16,0x83,0xb3,0,0);
    pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
    BldGfxNormal[0x1d0].seg = uVar19;
    BldGfxNormal[0x1d0].ofs = (uint16_t)pcVar6;
  }
  BldGfxNormal[0x1d3] = BldGfxNormal[0x1d0];
  BldGfxNormal[0x1d1] = BldGfxNormal[0x1ce];
  BldGfxNormal[0x1d2] = BldGfxNormal[0x1cf];
  BldGfxNormal[0x1d6] = BldGfxNormal[0x1d0];
  BldGfxNormal[0x1d4] = BldGfxNormal[0x1ce];
  BldGfxNormal[0x1d5] = BldGfxNormal[0x1cf];
  if (grab == false) {
    BldGfxNormal[0x1d7] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1d8] = BldGfxNormal[0x1d2];
    BldGfxNormal[0x1d9] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    uVar9 = *(uint *)((int)stgTmp + 0x302);
    src_13.seg = 0;
    src_13.ofs = uVar9;
    uVar19 = BldGfxNormal[0x1d0].ofs;
    pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src_13,1,200,(char)uVar9,0,200,0,0);
    BldGfxNormal[0x1d7].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
    uVar16 = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(src_14.seg))) = 0xe7;
    src_14.ofs = uVar16;
    (*(uint8_t *)((uint8_t *)&(src_14.seg) + 1)) = 0;
    uVar14 = BldGfxNormal[0x1d2].seg;
    BldGfxNormal[0x1d7].seg = uVar19;
    BldGfxNormal[0x1d8] = BldGfxNormal[0x1d2];
    pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src_14,49,279,(char)uVar16,0xe7,0x17,0,0);
    pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5,0);
    BldGfxNormal[0x1d9].seg = uVar14;
    BldGfxNormal[0x1d9].ofs = (uint16_t)pcVar6;
  }
  BldGfxNormal[0x1dc] = BldGfxNormal[0x1d9];
  BldGfxNormal[0x1da] = BldGfxNormal[0x1d7];
  BldGfxNormal[0x1df] = BldGfxNormal[0x1d9];
  BldGfxNormal[0x1dd] = BldGfxNormal[0x1d7];
  BldGfxNormal[0x1db] = BldGfxNormal[0x1d8];
  BldGfxNormal[0x1de] = BldGfxNormal[0x1d8];
  if (grab == false) {
    BldGfxNormal[0x1e0] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1e1] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1e5] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1e3] = BldGfxNormal[0x1e0];
    BldGfxNormal[0x1e4] = BldGfxNormal[0x1e1];
    BldGfxNormal[0x1e2] = BldGfxNormal[0x1e5];
    BldGfxNormal[0x1e6] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1e7] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1e8] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1ec] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1ed] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1ee] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1f2] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[499] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[500] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar14 = BldGfxNormal[0x1d9].ofs;
    ovr_stgFreeTmp(stgTmp,0);
    stgTmp = ovr_grabLbmTR(51);
    uVar19 = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(src_15.seg))) = 0x83;
    src_15.ofs = uVar19;
    (*(uint8_t *)((uint8_t *)&(src_15.seg) + 1)) = 0;
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleCut((far_t far *)(&stgTmp->aptr)->ofs,src_15,49,219,(char)uVar19,0x83,0xdb,0,0);
    BldGfxNormal[0x1e0].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar21 = 0x195d;
    uVar19 = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(src_16.seg))) = 0x83;
    src_16.ofs = uVar19;
    (*(uint8_t *)((uint8_t *)&(src_16.seg) + 1)) = 0;
    BldGfxNormal[0x1e0].seg = uVar14;
    pfVar5 = ovr_stshRleCut((far_t far *)(&stgTmp->aptr)->ofs,src_16,74,179,(char)uVar19,0x83,0xb3,0,0);
    BldGfxNormal[0x1e1].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar19 = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(src_17.seg))) = 0x83;
    src_17.ofs = uVar19;
    (*(uint8_t *)((uint8_t *)&(src_17.seg) + 1)) = 0;
    BldGfxNormal[0x1e1].seg = uVar21;
    pfVar5 = ovr_stshRleCut((far_t far *)(&stgTmp->aptr)->ofs,src_17,59,179,(char)uVar19,0x83,0xb3,0,0);
    BldGfxNormal[0x1e2].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    BldGfxNormal[0x1e2].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
    uVar19 = BldGfxNormal[0x1e2].seg;
    BldGfxNormal[0x1e3].ofs = BldGfxNormal[0x1e0].ofs;
    BldGfxNormal[0x1e3].seg = BldGfxNormal[0x1e0].seg;
    BldGfxNormal[0x1e4].ofs = BldGfxNormal[0x1e1].ofs;
    BldGfxNormal[0x1e4].seg = BldGfxNormal[0x1e1].seg;
    BldGfxNormal[0x1e5].ofs = BldGfxNormal[0x1e2].ofs;
    BldGfxNormal[0x1e5].seg = BldGfxNormal[0x1e2].seg;
    psVar4 = ovr_grabLbmTR(288);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar19,psVar4);
    uVar9 = (psVar4->aptr).seg;
    src_18.seg = 0;
    src_18.ofs = uVar9;
    pfVar5 = ovr_stshRleCut((far_t far *)(&psVar4->aptr)->ofs,src_18,51,200,(char)uVar9,0,200,0,0);
    BldGfxNormal[0x1e6].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
    uVar16 = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(src_19.seg))) = 0x1f;
    src_19.ofs = uVar16;
    (*(uint8_t *)((uint8_t *)&(src_19.seg) + 1)) = 0;
    BldGfxNormal[0x1e6].seg = uVar19;
    pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src_19,74,79,(char)uVar16,0x1f,0x4f,0,0);
    BldGfxNormal[0x1e7].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    uVar9 = *(uint *)((int)stgTmp + 0x302);
    src_20.seg = 0;
    src_20.ofs = uVar9;
    BldGfxNormal[0x1e7].seg = uVar14;
    pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src_20,51,48,(char)uVar9,0,0x30,0,0);
    BldGfxNormal[0x1e8].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    uVar9 = *(uint *)((int)stgTmp + 0x302);
    src_21.seg = 0;
    src_21.ofs = uVar9;
    BldGfxNormal[0x1e8].seg = uVar19;
    pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src_21,14,200,(char)uVar9,0,200,0,0);
    BldGfxNormal[0x1ec].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
    uVar16 = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(src_22.seg))) = 0x83;
    src_22.ofs = uVar16;
    (*(uint8_t *)((uint8_t *)&(src_22.seg) + 1)) = 0;
    BldGfxNormal[0x1ec].seg = uVar14;
    pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src_22,74,179,(char)uVar16,0x83,0xb3,0,0);
    BldGfxNormal[0x1ed].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    uVar9 = *(uint *)((int)stgTmp + 0x302);
    src_23.seg = 0;
    src_23.ofs = uVar9;
    BldGfxNormal[0x1ed].seg = uVar19;
    pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src_23,14,48,(char)uVar9,0,0x30,0,0);
    BldGfxNormal[0x1ee].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    uVar9 = *(uint *)((int)stgTmp + 0x302);
    src_24.seg = 0;
    src_24.ofs = uVar9;
    BldGfxNormal[0x1ee].seg = uVar14;
    pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src_24,168,200,(char)uVar9,0,200,0,0);
    BldGfxNormal[0x1f2].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar20 = (uint16_t)((ulong)stgTmp >> 0x10);
    uVar16 = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(src_25.seg))) = 0xe7;
    src_25.ofs = uVar16;
    (*(uint8_t *)((uint8_t *)&(src_25.seg) + 1)) = 0;
    BldGfxNormal[0x1f2].seg = uVar19;
    pfVar5 = ovr_stshRleCut((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),src_25,74,279,(char)uVar16,0xe7,0x17,0,0);
    BldGfxNormal[499].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    pixels_x00193.seg = 0;
    pixels_x00193.ofs = *(uint *)((int)stgTmp + 0x302);
    BldGfxNormal[499].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00193,168,48,
                              187,0,0,0xa8,0x30,0);
    BldGfxNormal[500].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    BldGfxNormal[500].seg = uVar19;
    ovr_stgFreeTmp(stgTmp,0);
  }
  BldGfxNormal[0x1ef].ofs = BldGfxNormal[0x1ec].ofs;
  BldGfxNormal[0x1ef].seg = BldGfxNormal[0x1ec].seg;
  BldGfxNormal[0x1f0].ofs = BldGfxNormal[0x1ed].ofs;
  BldGfxNormal[0x1f0].seg = BldGfxNormal[0x1ed].seg;
  BldGfxNormal[0x1f1].ofs = BldGfxNormal[0x1ee].ofs;
  BldGfxNormal[0x1f1].seg = BldGfxNormal[0x1ee].seg;
  BldGfxNormal[0x1f5].ofs = BldGfxNormal[0x1ec].ofs;
  BldGfxNormal[0x1f5].seg = BldGfxNormal[0x1ec].seg;
  BldGfxNormal[0x1f6].ofs = BldGfxNormal[0x1ed].ofs;
  BldGfxNormal[0x1f6].seg = BldGfxNormal[0x1ed].seg;
  BldGfxNormal[0x1f7].ofs = BldGfxNormal[0x1ee].ofs;
  BldGfxNormal[0x1f7].seg = BldGfxNormal[0x1ee].seg;
  BldGfxNormal[0x1e9] = BldGfxNormal[0x1e6];
  BldGfxNormal[0x1ea] = BldGfxNormal[0x1e7];
  BldGfxNormal[0x1eb] = BldGfxNormal[0x1e8];
  if (grab == false) {
    BldGfxNormal[0x1f9] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1fc] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1ff] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x1f9] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x1fc] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x1ff] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar19 = BldGfxNormal[0x1ee].seg;
    stgTmp = ovr_grabLbmTR(462);
    (*(uint8_t *)((uint8_t *)&(pixels_x00194.seg))) = 0xd;
    pixels_x00194.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00194.seg) + 1)) = 0;
    puStack_a = (uint8_t *)uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00194,28,96,119,0,0xd,0x1c,
                              0x60,0);
    BldGfxNormal[0x1f9].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00195.seg))) = 0x77;
    pixels_x00195.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00195.seg) + 1)) = 0;
    BldGfxNormal[0x1f9].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00195,28,202,119,0,0x77,0x1c,
                              0xca,0);
    BldGfxNormal[0x1fc].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    (*(uint8_t *)((uint8_t *)&(pixels_x00196.seg))) = 0xe2;
    pixels_x00196.ofs = (stgTmp->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00196.seg) + 1)) = 0;
    BldGfxNormal[0x1fc].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)(&stgTmp->aptr)->ofs,pixels_x00196,28,309,119,0,0xe2,0x1c,
                              0x35,0);
    BldGfxNormal[0x1ff].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    BldGfxNormal[0x1ff].seg = uVar19;
    ovr_stgFreeTmp(stgTmp,0);
    psVar4 = ovr_grabLbmTR(463);
    stgTmp = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    (*(uint8_t *)((uint8_t *)&(pixels_x00197.seg))) = 0xd;
    pixels_x00197.ofs = (psVar4->aptr).seg;
    (*(uint8_t *)((uint8_t *)&(pixels_x00197.seg) + 1)) = 0;
    pfVar5 = ovr_stshRleType2((far_t far *)(&psVar4->aptr)->ofs,pixels_x00197,28,96,119,0,0xd,0x1c,0x60,
                              0);
    BldGfxRuin[0x1f9].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar19 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00198.seg))) = 0x77;
    pixels_x00198.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00198.seg) + 1)) = 0;
    BldGfxRuin[0x1f9].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00198,28,202,
                              119,0,0x77,0x1c,0xca,0);
    BldGfxRuin[0x1fc].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    uVar14 = 0x195d;
    uVar16 = (uint16_t)((ulong)stgTmp >> 0x10);
    (*(uint8_t *)((uint8_t *)&(pixels_x00199.seg))) = 0xe2;
    pixels_x00199.ofs = *(uint16_t *)((int)stgTmp + 0x302);
    (*(uint8_t *)((uint8_t *)&(pixels_x00199.seg) + 1)) = 0;
    BldGfxRuin[0x1fc].seg = uVar19;
    pfVar5 = ovr_stshRleType2((far_t far *)*(uint16_t *)((int)stgTmp + 0x300),pixels_x00199,28,309,
                              119,0,0xe2,0x1c,0x35,0);
    BldGfxRuin[0x1ff].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar5,0);
    BldGfxRuin[0x1ff].seg = uVar14;
    ovr_stgFreeTmp(stgTmp,0);
  }
  ovr_stshStubifyCopy1to0(0xa8);
  ovr_init_assets1(grab);
  x = x & 0xff;
  ovr_init_assets2(grab);
  if (grab != false) {
    uVar16 = 0;
    plVar8 = LXMUL_at_(in_stack_0000fc0e,in_stack_0000fc10,in_stack_0000fc14);
    buf.seg = StshCtPtr.seg;
    buf.ofs = StshCtPtr.ofs;
    (*(uint8_t *)((uint8_t *)&(sz.hi))) = (char)uVar16;
    sz.lo = (uint16_t)plVar8;
    (*(uint8_t *)((uint8_t *)&(sz.hi) + 1)) = (char)((uint)uVar16 >> 8);
    ovr_stshWriteFile(StshFile,buf,sz,(char)StshCtPtr.ofs,(char)plVar8);
    lseek(StshFile,0,(int)in_stack_0000fc0e);
    write(StshFile,&StshCtOfs,4);
    close(StshFile);
    x = 0x2410;
    if (StshCount != 0xd93) {
      printf("getcache %d  SIZESTASH %d  \r");
      x = ovr_biosReadKey();
    }
  }
  stshInitPtrs();
  return x;
}


/* 77eb:16b2 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc45_usesRandBelow(int entityIndex)

{
  char cVar1;
  uint32_t uVar2;
  uint uVar3;
  byte bVar5;
  uint16_t uVar4;
  uint16_t uVar6;
  
  uVar6 = (uint16_t)((ulong)Entities >> 0x10);
  if (*(char *)((int)Entities + entityIndex * 0x37 + 0x1a) == -1) {
    uVar3 = entityIndex * 0x37 & 0xff00;
  }
  else {
    uVar2 = *(uint32_t *)((uint)*(byte *)((int)Entities + entityIndex * 0x37 + 0x1a) << 2);
    cVar1 = *(char *)((int)uVar2 + 0x2f);
    if (cVar1 == '\x04') {
      uVar4 = ovr_randBelow(5,0);
      bVar5 = (byte)(uVar4 >> 8);
      if ((byte)uVar4 < 4) {
        uVar3 = CONCAT11(bVar5,1);
      }
      else {
        uVar3 = (uint)bVar5 << 8;
      }
    }
    else if (cVar1 == '\x05') {
      uVar4 = ovr_randBelow(3,0);
      bVar5 = (byte)(uVar4 >> 8);
      if ((char)uVar4 == '\0') {
        uVar3 = CONCAT11(bVar5,1);
      }
      else {
        uVar3 = (uint)bVar5 << 8;
      }
    }
    else {
      uVar4 = ovr_randBelow(4,0);
      bVar5 = (byte)(uVar4 >> 8);
      if ((byte)uVar4 < 2) {
        uVar3 = CONCAT11(bVar5,1);
      }
      else {
        uVar3 = (uint)bVar5 << 8;
      }
    }
  }
  return uVar3;
}



/* 77eb:1754 */
void __cdecl16far
ovc45_textDone(char foundFlag,byte bldType,int entityIndex,uint16_t x,uint16_t outFlag,uint16_t outFlagSeg,uint16_t arg7,uint16_t arg8)

{
  byte bVar1;
  far_t entries;
  far_t entries_00;
  far_t hint;
  far_t hint_00;
  uint16_t x_00;
  char *pcVar2;
  uint16_t *puVar3;
  int iVar4;
  uint8_t *puVar5;
  uint uVar6;
  uint16_t uVar7;
  uint16_t uVar8;
  uint16_t uVar9;
  int iVar10;
  uint16_t unaff_DI;
  char *unaff_SS;
  undefined1 uVar11;
  undefined1 uVar12;
  uint8_t menuItems;
  uint16_t auStack_28e [19];
  uint8_t msg;
  uint8_t text;
  char cStack_17;
  char cStack_16;
  char cStack_15;
  uint8_t menuLabel;
  uint16_t uStack_12;
  uint16_t uStack_10;
  char cStack_e;
  char acStack_d [11];
  
  x_00 = x;
  auStack_28e[0] = 0x2410;
  menuItems = 0x7706;
  acStack_d[1] = 1;
  if (*(int *)((uint)bldType * 0x27 + 0x116) == 0 && *(int *)((uint)bldType * 0x27 + 0x118) == 0) {
    auStack_28e[2] = 0x2410;
    auStack_28e[1] = 0x770f;
  }
  else {
    auStack_28e[2] = *(uint16_t *)((uint)bldType * 0x27 + 0x118);
    auStack_28e[1] = *(uint16_t *)((uint)bldType * 0x27 + 0x116);
  }
  acStack_d[2] = 2;
  iVar10 = 2;
  if (foundFlag != '\0') {
    auStack_28e[4] = 0x2410;
    auStack_28e[3] = 0x7716;
    acStack_d[3] = 3;
    iVar10 = 3;
  }
  auStack_28e[iVar10 * 2] = 0x2410;   /* hand fix: segment-half array; this function already stores 0x2410 in auStack_28e[0],[2],[4] */
  *(char **)(&menuItems + iVar10 * 4) = (char *)"Done";
  acStack_d[iVar10 + 1] = '\x04';
  cStack_16 = '\0';
  do {
    uVar11 = 0x10;
    pcVar2 = ovr_ovc22_className(*(byte *)((int)Entities + entityIndex * 0x37 + 0x1a),0);
    puVar3 = (uint16_t *)((uint)*(byte *)((int)Entities + entityIndex * 0x37 + 0x1a) * 4);
    uVar8 = 0x217a;
    iVar4 = ovc45_compute9((char *)&text,(char *)CONCAT22(*puVar3,unaff_SS),
                           (char *)CONCAT13((char)(Font03.ofs >> 8),
                                            CONCAT12((char)Font03.ofs,puVar3[1])),Font03.seg,'U',
                           (char)Font03.ofs,0x55,3,pcVar2,uVar11);
    uVar9 = 0x195d;
    puVar5 = ovr_ovc15_usesStshRealloc
                       ((char *)*(uint16_t *)((uint)bldType * 0x27 + 0x10e),*(uint16_t *)((uint)bldType * 0x27 + 0x110),(char)iVar4,uVar8,0,0,0,0);
    pcVar2 = ovr_fmVsprintf("%s: Search this location for minerals?  Active party is %s the %s.",
                            (char *)CONCAT22(uVar9,puVar5));
    strcpy((char *)CONCAT22(unaff_SS,&msg),
           (char *)CONCAT13((char)((uint)uVar9 >> 8),CONCAT12((char)uVar9,pcVar2)));
    goldPartyIndex = *(undefined1 *)((int)Entities + entityIndex * 0x37 + 0x1a);
    uVar11 = SUB21(unaff_SS,0);
    uVar12 = (undefined1)((uint)unaff_SS >> 8);
    puVar5 = &menuItems;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = uVar11;
    entries.ofs = (uint16_t)puVar5;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar12;
    (*(uint8_t *)((uint8_t *)&(hint.seg))) = uVar11;
    hint.ofs = (uint16_t)&msg;
    (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = uVar12;
    ovr_ovc28_compute2(entries,iVar10 + 1,hint,0,0);
    cStack_15 = (char)puVar5;
    goldPartyIndex = 0xff;
    if (cStack_15 != '\0') {
      cStack_15 = acStack_d[(uint)puVar5 & 0xff];
    }
    if (cStack_15 == '\x01') {
      uVar6 = ovc45_usesRandBelow(entityIndex);
      if ((uVar6 & 0xff) == 0) {
        ovr_play_sfx(47,0,0);
        ovr_say((char *)"No minerals were found.",0x10);
        bVar1 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
        ovr_createConstructionRecordFar
                  (0,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,(char)unaff_DI,(char)GfxRndSeed2,bVar1,0);
      }
      else {
        uVar7 = ovr_randBelow(0x10,0);
        if ((uVar7 & 0xff) == 0) {
          ovr_play_sfx(42,0,0);
          ovr_say((char *)"Gems discovered.",0x10);
          bVar1 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
          ovr_createConstructionRecordFar
                    (0x72,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,(char)unaff_DI,(char)GfxRndSeed2,bVar1,0);
        }
        else {
          uVar7 = ovr_randBelow(4,0);
          if ((char)uVar7 == '\0') {
            ovr_play_sfx(43,0,0);
            ovr_say((char *)"Gold discovered.",0x10);
            bVar1 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
            ovr_createConstructionRecordFar
                      (0x71,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,(char)unaff_DI,(char)GfxRndSeed2,bVar1,0);
          }
          else {
            ovr_play_sfx(42,0,0);
            ovr_say((char *)"Iron deposits discovered.",0x10);
            bVar1 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
            ovr_createConstructionRecordFar
                      (0x70,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,(char)unaff_DI,(char)GfxRndSeed2,bVar1,0);
          }
        }
      }
      ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x12));
      cStack_16 = '\x01';
    }
    else if (cStack_15 == '\x02') {
      uStack_12 = 0x2410;
      menuLabel = 0x770f;
      cStack_e = '\x10';
      acStack_d[0] = '$';
      uStack_10 = 0x77ba;
      uVar9 = 0x195d;
      uVar8 = *(uint16_t *)((uint)bldType * 0x27 + 0x110);
      pcVar2 = ovr_fmVsprintf("Remove %s permanently. Are you sure?",
                              (char *)CONCAT13((char)((uint)uVar8 >> 8),
                                               CONCAT12((char)uVar8,
                                                        *(uint16_t *)
                                                         ((uint)bldType * 0x27 + 0x10e))));
      puVar5 = &menuLabel;
      (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = uVar11;
      entries_00.ofs = (uint16_t)puVar5;
      (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = uVar12;
      (*(uint8_t *)((uint8_t *)&(hint_00.seg))) = (char)uVar9;
      hint_00.ofs = (uint16_t)pcVar2;
      (*(uint8_t *)((uint8_t *)&(hint_00.seg) + 1)) = (char)((uint)uVar9 >> 8);
      ovr_ovc28_compute2(entries_00,2,hint_00,0,0);
      cStack_15 = (char)puVar5;
      if (cStack_15 == '\x01') {
        bVar1 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
        ovr_createConstructionRecordFar
                  (0,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,(char)unaff_DI,(char)GfxRndSeed2,bVar1,0);
      }
      cStack_16 = '\x01';
    }
    else if (cStack_15 == '\x03') {
      uVar8 = ovc45_textChoosePartyBuild(x_00,GfxRndSeed2,&entityIndex,0);
      cStack_17 = (char)uVar8;
      if (cStack_17 == -1) {
        cStack_16 = '\x01';
      }
    }
    else if ((cStack_15 == '\x04') || (cStack_15 == '\0')) {
      cStack_16 = '\x01';
    }
  } while (cStack_16 == '\0');
  return;
}


/* 77eb:1ba2 */

/* [R7] body shape: compute */

bool __cdecl16far ovc45_compute6(uint16_t value)

{
  return value != 1;
}



/* 77eb:1bb3 */
void __cdecl16far
ovc45_textDone2(char foundFlag,byte bldType,int entityIndex,uint16_t x,uint16_t outFlag,uint16_t outFlagSeg,uint16_t arg7,uint16_t arg8)

{
  uint *puVar1;
  int *piVar2;
  uint8_t partyIndex;
  byte bVar3;
  far_t entries;
  far_t hint;
  uint16_t agnt;
  char *pcVar4;
  uint16_t *puVar5;
  int iVar6;
  uint8_t *puVar7;
  uint16_t uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint16_t unaff_DI;
  uint16_t uVar13;
  char *unaff_SS;
  undefined1 uVar14;
  undefined1 uVar15;
  uint8_t menuLabels;
  uint16_t auStack_290 [19];
  uint8_t msg;
  uint8_t text;
  uint uStack_1a;
  uint uStack_18;
  char *pcStack_16;
  uint uStack_14;
  byte bStack_11;
  byte bStack_10;
  char cStack_f;
  char cStack_e;
  uint8_t menuActions;
  undefined1 auStack_c [10];
  
  agnt = x;
  uStack_1a = *(uint *)((uint)bldType * 0x27 + 0x125) / 10;
  auStack_290[0] = 0x2410;
  menuLabels = 0x77f0;
  auStack_c[0] = 1;
  if (*(int *)((uint)bldType * 0x27 + 0x116) == 0 && *(int *)((uint)bldType * 0x27 + 0x118) == 0) {
    auStack_290[2] = 0x2410;
    auStack_290[1] = 0x77f6;
  }
  else {
    auStack_290[2] = *(uint16_t *)((uint)bldType * 0x27 + 0x118);
    auStack_290[1] = *(uint16_t *)((uint)bldType * 0x27 + 0x116);
  }
  auStack_c[1] = 2;
  iVar12 = 2;
  if (foundFlag != '\0') {
    auStack_290[4] = 0x2410;
    auStack_290[3] = 0x7716;
    auStack_c[2] = 3;
    iVar12 = 3;
  }
  auStack_290[iVar12 * 2] = 0x2410;   /* hand fix: segment-half array, same value as the sibling stores in this function */
  *(char **)(&menuLabels + iVar12 * 4) = (char *)"Done";
  auStack_c[iVar12] = 4;
  cStack_e = '\0';
  do {
    uVar14 = 0x10;
    pcVar4 = ovr_ovc22_className(*(byte *)((int)Entities + entityIndex * 0x37 + 0x1a),0);
    puVar5 = (uint16_t *)((uint)*(byte *)((int)Entities + entityIndex * 0x37 + 0x1a) * 4);
    uVar15 = 0x7a;
    uVar8 = puVar5[1];
    iVar6 = ovc45_compute9((char *)&text,(char *)CONCAT22(*puVar5,unaff_SS),
                           (char *)CONCAT13((char)(Font03.ofs >> 8),CONCAT12((char)Font03.ofs,uVar8)
                                           ),Font03.seg,'U',(char)uVar8,(char)Font03.ofs,0x55,3,
                           pcVar4,uVar14);
    uVar8 = 0x195d;
    puVar7 = ovr_ovc15_usesStshRealloc
                       ((char *)*(uint16_t *)((uint)bldType * 0x27 + 0x10e),(char)*(uint16_t *)((uint)bldType * 0x27 + 0x110),uStack_1a,(char)iVar6,uVar15,0,0,0);
    pcVar4 = ovr_fmVsprintf("%s: Claim this tree? Harvest value is %d gold. Active party is %s the %s."
                            ,(char *)CONCAT13((char)((uint)uVar8 >> 8),CONCAT12((char)uVar8,puVar7))
                           );
    uVar14 = SUB21(unaff_SS,0);
    uVar15 = (undefined1)((uint)unaff_SS >> 8);
    strcpy((char *)CONCAT13(uVar15,CONCAT12(uVar14,&msg)),
           (char *)CONCAT13((char)((uint)uVar8 >> 8),CONCAT12((char)uVar8,pcVar4)));
    goldPartyIndex = *(undefined1 *)((int)Entities + entityIndex * 0x37 + 0x1a);
    puVar7 = &menuLabels;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = uVar14;
    entries.ofs = (uint16_t)puVar7;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar15;
    (*(uint8_t *)((uint8_t *)&(hint.seg))) = uVar14;
    hint.ofs = (uint16_t)&msg;
    (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = uVar15;
    ovr_ovc28_compute2(entries,iVar12 + 1U,hint,(char)(iVar12 + 1U),0);
    menuActions = (uint8_t)puVar7;
    goldPartyIndex = 0xff;
    if ((uint8_t)puVar7 != 0x0) {
      menuActions = auStack_c[((uint)puVar7 & 0xff) - 1];
    }
    if (menuActions == 0x1) {
      ovr_play_sfx(86,0,0);
      if (*(char *)((uint)bldType * 0x27 + 0x131) == '\0') {
        if (*(char *)((int)&worldMenuLabels[9].ofs + 1 +
                     (uint)((entity_t *)Entities)[entityIndex].base.gindex * 0x95) == '\x05') {
          bStack_11 = bldType + 0x18;
        }
        else {
          bStack_11 = bldType + 6;
        }
      }
      else {
        bStack_11 = bldType;
      }
      uStack_14 = (uint)*(byte *)((uint)bStack_11 * 0x27 + 0x120);
      *(undefined1 *)((uint)bStack_11 * 0x27 + 0x120) = 1;
      ovr_createConstructionRecord
                (bStack_11,agnt,GfxRndSeed2,(uint8_t *)outFlag,(char)outFlagSeg,(char)agnt,
                 (char)outFlag,(char)outFlagSeg,
                 CONCAT11((char)((uint)(entityIndex * 0x37) >> 8),
                          *(undefined1 *)((int)Entities + entityIndex * 0x37 + 0x1a)),0);
      *(undefined1 *)((uint)bStack_11 * 0x27 + 0x120) = (undefined1)uStack_14;
      bVar3 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
      pcStack_16 = ovr_ovc22_textPOPULATION(bStack_11,bVar3,(agnt_t *)agnt,bVar3,(char)GfxRndSeed2);
      uVar14 = 0x10;
      partyIndex = *(uint8_t *)((int)Entities + entityIndex * 0x37 + 0x1a);
      uStack_18 = ovr_ovc22_seasonalIncome(bStack_11,partyIndex,partyIndex,agnt,(char)GfxRndSeed2);
      ovc45_compute6((uint16_t)pcStack_16);
      pcVar4 = ovr_fmVsprintf("Forest claimed. This forest creates %d gold of income and feeds %d %s."
                              ,(char *)CONCAT13((char)((uint)pcStack_16 >> 8),
                                                CONCAT12((char)pcStack_16,uStack_18)));
      ovr_say(pcVar4,uVar14);
      ovr_inputUpdate((ulong)MessageDelay << 1);
      cStack_e = '\x01';
    }
    else if (menuActions == 0x2) {
      ovr_play_sfx(48,0,0);
      bVar3 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
      ovr_createConstructionRecordFar
                (0,agnt,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar3,(char)unaff_DI,
                 (char)GfxRndSeed2,(char)outFlag,bVar3);
      cStack_e = '\x01';
      bStack_10 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
      uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
      iVar6 = (int)*(uint32_t *)((uint)bStack_10 << 2);
      puVar1 = (uint *)(iVar6 + 0x56);
      uVar9 = *puVar1;
      *puVar1 = *puVar1 + uStack_1a;
      piVar2 = (int *)(iVar6 + 0x58);
      *piVar2 = *piVar2 + (uint)CARRY2(uVar9,uStack_1a);
      uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
      iVar10 = (int)*(uint32_t *)((uint)bStack_10 << 2);
      iVar6 = *(int *)(iVar10 + 0x58);
      uVar9 = *(uint *)(iVar10 + 0x56);
      uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
      iVar11 = (int)*(uint32_t *)((uint)bStack_10 << 2);
      iVar10 = *(int *)(iVar11 + 0x8c);
      if ((iVar10 <= iVar6) && ((iVar10 < iVar6 || (*(uint *)(iVar11 + 0x8a) < uVar9)))) {
        uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
        iVar6 = (int)*(uint32_t *)((uint)bStack_10 << 2);
        uVar9 = *(uint *)(iVar6 + 0x8a);
        uVar13 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
        iVar10 = (int)*(uint32_t *)((uint)bStack_10 << 2);
        *(uint16_t *)(iVar10 + 0x58) = *(uint16_t *)(iVar6 + 0x8c);
        *(uint *)(iVar10 + 0x56) = uVar9;
      }
      uVar14 = (undefined1)uVar9;
      pcVar4 = ovr_stsprintf((char *)&text);
      ovr_say(pcVar4,uVar14);
      ovr_inputUpdate((ulong)MessageDelay << 1);
    }
    else if (menuActions == 0x3) {
      uVar8 = ovc45_textChoosePartyBuild(agnt,GfxRndSeed2,&entityIndex,(char)GfxRndSeed2);
      cStack_f = (char)uVar8;
      if (cStack_f == -1) {
        cStack_e = '\x01';
      }
    }
    else if ((menuActions == 0x4) || (menuActions == 0x0)) {
      cStack_e = '\x01';
    }
  } while (cStack_e == '\0');
  return;
}


/* 77eb:20e8 */

/* [R6] touches GfxRndSeed2 */

uint __cdecl16far ovc45_usesGfxRndSeed2(int *x)

{
  byte bVar1;
  uint in_AX;
  undefined1 extraout_AH;
  uint uVar2;
  uint16_t in_stack_00000006;
  byte bStack_4;
  byte bStack_3;
  
  bStack_4 = 0;
  while( true ) {
    if (3 < bStack_4) {
      return in_AX & 0xff00;
    }
    bStack_3 = ovc45_getUnitType(*x - (uint)bStack_4,GfxRndSeed2);
    in_AX = CONCAT11(extraout_AH,bStack_3);
    if (bStack_3 != 0) break;
    bStack_4 = bStack_4 + 1;
  }
  bVar1 = *(byte *)((uint)bStack_3 * 0x27 + 0x11b);
  uVar2 = CONCAT11((char)((uint)bStack_3 * 0x27 >> 8),bVar1);
  if (bStack_4 < bVar1) {
    uVar2 = (uint)bStack_4;
    *x = *x - uVar2;
  }
  else {
    bStack_3 = 0;
  }
  return CONCAT11((char)(uVar2 >> 8),bStack_3);
}



/* 77eb:215a */

/* [R6] touches GMapFlags */

int __cdecl16far ovc45_usesGMapFlags4(int x,int y)

{
  int in_AX;
  int iVar1;
  byte bVar2;
  uint16_t uVar3;
  
  if ((((x < 0) || (y < 0)) || (in_AX = x + 1, 0x93 < in_AX)) || (in_AX = y + 1, 0x3b < in_AX)) {
    iVar1 = CONCAT11((char)((uint)in_AX >> 8),2);
  }
  else {
    uVar3 = (uint16_t)((ulong)GMapFlags >> 0x10);
    if (((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) == 3) {
      iVar1 = 2;
    }
    else {
      bVar2 = (byte)((uint)(x * 2) >> 8);
      if (((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) == 0) {
        iVar1 = (uint)bVar2 << 8;
      }
      else {
        iVar1 = CONCAT11(bVar2,1);
      }
    }
  }
  return iVar1;
}



/* 77eb:21d3 */

/* [R7] body shape: compute */

uint16_t __cdecl16far ovc45_compute7(byte a,byte b,uint16_t arg3,uint16_t arg4,uint16_t arg5)

{
  return CONCAT11((byte)((uint)a * (uint)b >> 0xb),(char)((uint)a * (uint)b >> 3));
}



/* 77eb:21f1 */

/* Shows the land info for the tile under a screen point: hit-tests with video_compute1, maps x to a
   tile column via (x-9)/0x30, and calls land_info. */

bool __cdecl16far ovc45_showLandInfo(int screenX,uint16_t y)

{
  uint16_t uVar1;
  bool bVar2;
  
  uVar1 = video_pointInButton(screenX,y);
  bVar2 = (char)uVar1 != '\0';
  if (bVar2) {
    ovr_land_info((byte)((screenX - 9U) / 0x30));
  }
  return bVar2;
}



/* 77eb:2226 */

/* [R7] body shape: compute */

uint __cdecl16far ovc45_compute8(byte partyIndex)

{
  uint32_t uVar1;
  uint in_AX;
  uint uVar2;
  byte bVar3;
  
  if (partyIndex == 0xff) {
    uVar2 = in_AX & 0xff00;
  }
  else {
    uVar1 = *(uint32_t *)((uint)partyIndex << 2);
    bVar3 = (byte)(((uint)partyIndex << 2) >> 8);
    if (*(char *)((int)uVar1 + 0x3f) == '\0') {
      uVar2 = CONCAT11(bVar3,1);
    }
    else {
      uVar2 = (uint)bVar3 << 8;
    }
  }
  return uVar2;
}



/* 77eb:2257 */

/* Returns the "Maintenance cost is" or "Income created is" label for a signed amount. */

char * __cdecl16far ovc45_costOrIncomeLabel(int amount)

{
  char *pcVar1;
  
  if (amount < 1) {
    pcVar1 = (char *)"Maintenance cost is";
  }
  else {
    pcVar1 = (char *)"Income created is";
  }
  return pcVar1;
}



/* 77eb:226e */
int __cdecl16far ovc45_compute9(char *dest,char *src,char *font,uint maxWidth,char mode,...)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char in_stack_00000012;
  int iStack_4;
  
  uVar2 = ovr_font_textWidth((*(uint16_t *)((uint8_t *)&(src) + 2)),font,maxWidth,0,0);
  if (mode < uVar2) {
    if (in_stack_00000012 == '\x02') {
      iStack_4 = ovr_font_textWidth((char *)"..",(char *)CONCAT22((*(uint16_t *)((uint8_t *)&(font) + 2)),(char *)0x2410),maxWidth,0,0)
      ;
    }
    else {
      iStack_4 = ovr_font_textWidth((char *)"...",(char *)CONCAT22((*(uint16_t *)((uint8_t *)&(font) + 2)),(char *)0x2410),maxWidth,0,0)
      ;
    }
    iVar3 = 0;
    for (iVar4 = 0;
        (((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   iVar3] != '\0' &&
        ((int)(iStack_4 + iVar4 + (uint)*(byte *)((*(uint16_t *)((uint8_t *)&(font) + 2)) + ((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   iVar3] + 0xa1)) <=
         (int)mode)); iVar4 = iVar4 + (uint)bVar1) {
      bVar1 = *(byte *)((*(uint16_t *)((uint8_t *)&(font) + 2)) + ((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   iVar3] + 0xa1);
      dest[iVar3] = ((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   iVar3];
      iVar3 = iVar3 + 1;
    }
    dest[iVar3] = '.';
    dest[iVar3 + 1] = '.';
    iVar4 = iVar3 + 2;
    if (in_stack_00000012 != '\x02') {
      dest[iVar4] = '.';
      iVar4 = iVar3 + 3;
    }
    dest[iVar4] = '\0';
    (*(uint16_t *)((uint8_t *)&(src) + 2)) = (uint16_t)dest;   /* hand fix: 2-byte segment half */
  }
  return (int)(*(uint16_t *)((uint8_t *)&(src) + 2));
}


/* 77eb:234a */

/* [R6] touches GMapFlags */

uint __cdecl16far ovc45_usesGMapFlags5(char mode,uint x,int y)

{
  uint uVar1;
  short *in_AX;
  undefined1 uVar3;
  short *psVar2;
  byte bVar4;
  
  if (mode == '\x01') {
    in_AX = (*(short (*) [60] [148])GMapFlags)[y] + x;
    uVar1 = in_AX[0x94];
    uVar3 = (undefined1)((uint)in_AX >> 8);
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 1) != 0) {
        return CONCAT11(uVar3,1);
      }
    }
    else if ((uVar1 & 2) != 0) {
      return CONCAT11(uVar3,1);
    }
  }
  else if (mode == '\x02') {
    psVar2 = (*(short (*) [60] [148])GMapFlags)[y] + x;
    if ((psVar2[0x94] & 1U) == 0) {
      return (uint)psVar2 & 0xff00;
    }
    if (((*(short (*) [60] [148])GMapFlags)[y][x] & 1U) == 0) {
      return ((x & 0x7fff) >> 7) << 8;
    }
    psVar2 = (*(short (*) [60] [148])GMapFlags)[y] + x;
    if ((psVar2[0x93] & 2U) == 0) {
      return (uint)psVar2 & 0xff00;
    }
    bVar4 = (byte)(x * 2 >> 8);
    if ((((short (*) [60] [148])GMapFlags)[-1][y + 0x3b][x + 0x93] & 2U) == 0) {
      return (uint)bVar4 << 8;
    }
    return CONCAT11(bVar4,1);
  }
  return (uint)in_AX & 0xff00;
}


