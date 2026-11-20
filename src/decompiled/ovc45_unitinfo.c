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
  int in_stack_00000004;
  
  if ((((in_stack_00000004 < 0x94) && (-1 < in_stack_00000004)) && (x < 0x3c)) && (-1 < x)) {
    bVar1 = ((unit_t *)GUnits + (*(short (*) [148] [60])GUnitGrid)[in_stack_00000004][x])->bldType;
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
  int in_stack_00000004;
  
  if ((((in_stack_00000004 < 0x94) && (-1 < in_stack_00000004)) && (x < 0x3c)) && (-1 < x)) {
    sVar1 = (*(short (*) [148] [60])GUnitGrid)[in_stack_00000004][x];
  }
  else {
    sVar1 = 0;
  }
  return sVar1;
}



/* 77eb:01bb */

/* [R4] calls ovr_alignUp4 */

uint __cdecl16far ovc45_usesAlignUp4(int slotMin,int x,uint16_t y,uint *entityIndexOut)

{
  uint uVar1;
  entity_t *peVar2;
  uint uVar3;
  int unaff_DI;
  undefined2 uVar4;
  uint *in_stack_0000000a;
  byte bStack_3;
  
  bStack_3 = 0xff;
  for (uVar3 = 0; uVar3 < EntityCount; uVar3 = uVar3 + 1) {
    uVar1 = ovr_alignUp4(unaff_DI,(((entity_t *)Entities + uVar3)->base).x);
    if (uVar1 == x) {
      uVar4 = (undefined2)((ulong)Entities >> 0x10);
      peVar2 = (entity_t *)Entities;
      if ((((peVar2[uVar3].base.y == y) &&
           (*(char *)((int)(char **)GMenuStrings + (uint)peVar2[uVar3].base.gindex * 0x95 + 0x1f) ==
            '\0')) && (slotMin < (int)(uint)*(byte *)((int)&peVar2[uVar3].base.entity + 3))) &&
         (*(byte *)((int)&peVar2[uVar3].base.entity + 3) < bStack_3)) {
        bStack_3 = *(byte *)((int)&peVar2[uVar3].base.entity + 3);
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

/* Finds the entity at (x,y) and writes its index and a found flag through the out pointers. */

char * __cdecl16far
ovc45_findEntityAt(uint16_t x,uint16_t y,uint *foundIndex,uint8_t *foundFlagOut,char foundFlag,...)

{
  uint uVar1;
  int iVar2;
  entity_t *peVar3;
  uint uVar4;
  int unaff_DI;
  uint uVar5;
  undefined2 uVar6;
  uint in_stack_00000004;
  uint uStack_6;
  uint uStack_4;
  
  *(undefined1 *)CONCAT22((uint8_t *)foundFlagOut,(*(uint16_t *)((uint8_t *)&(foundIndex) + 2))) = 0;
  in_stack_00000004 = ovr_alignUp4(unaff_DI,in_stack_00000004);
  *(undefined2 *)CONCAT22((uint *)foundIndex,y) = 0xffff;
  uStack_6 = 0xffff;
  uVar5 = 0xffff;
  uStack_4 = 0xffff;
  for (uVar4 = 0; uVar4 < EntityCount; uVar4 = uVar4 + 1) {
    uVar1 = ovr_alignUp4(unaff_DI,(((entity_t *)Entities + uVar4)->base).x);
    if (uVar1 == in_stack_00000004) {
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      peVar3 = (entity_t *)Entities;
      if (peVar3[uVar4].base.y == x) {
        uVar1 = (uint)peVar3[uVar4].base.gindex * 0x95;
        if (*(char *)((int)(char **)GMenuStrings + uVar1 + 0x1f) != '\0') {
          return (char *)(uVar1 & 0xff00);
        }
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)peVar3[uVar4].base.gindex * 0x95) !=
             -1) && (*(char *)((int)&peVar3[uVar4].base.entity + 3) != -1)) {
          if (*(char *)((int)&peVar3[uVar4].base.entity + 3) == (*(uint8_t *)((uint8_t *)&(foundFlagOut) + 2))) {
            *(uint *)CONCAT22((uint *)foundIndex,y) = uVar4;
          }
          else if (*(char *)((int)&peVar3[uVar4].base.entity + 3) == selectedPartyIndex) {
            uStack_6 = uVar4;
          }
          if ((uStack_4 != 0xffff) &&
             (*(byte *)((int)&((entity_t *)Entities)[uVar4].base.entity + 3) != uStack_4)) {
            *(undefined1 *)CONCAT22((uint8_t *)foundFlagOut,(*(uint16_t *)((uint8_t *)&(foundIndex) + 2))) = 1;
          }
          uStack_4 = (uint)*(byte *)((int)&((entity_t *)Entities)[uVar4].base.entity + 3);
          uVar5 = uVar4;
        }
      }
    }
  }
  if (*(int *)CONCAT22((uint *)foundIndex,y) == -1) {
    if (uStack_6 == 0xffff) {
      if (uVar5 == 0xffff) {
        return (char *)"arena" + 4;
      }
      *(uint *)CONCAT22((uint *)foundIndex,y) = uVar5;
    }
    else {
      *(uint *)CONCAT22((uint *)foundIndex,y) = uStack_6;
    }
  }
  uVar6 = (undefined2)((ulong)Entities >> 0x10);
  iVar2 = (uint)((entity_t *)Entities)[*(int *)CONCAT22((uint *)foundIndex,y)].base.gindex * 0x95;
  selectedPartyIndex =
       *(undefined1 *)
        ((int)&((entity_t *)Entities)[*(int *)CONCAT22((uint *)foundIndex,y)].base.entity + 3);
  return (char *)CONCAT11((char)((uint)iVar2 >> 8),
                          '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 + iVar2) & 0x1f));
}



/* 77eb:04d8 */

/* [R2] string "Choose party to build for.  Now building" */

undefined2 __cdecl16far ovc45_textChoosePartyBuild(uint16_t x,uint16_t y,int *entityIndexPtr,...)

{
  far_t entries;
  int iVar1;
  char *pcVar2;
  undefined2 *puVar3;
  uint8_t *puVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  undefined2 unaff_DI;
  uint slotMin;
  undefined2 uVar7;
  uint *unaff_SS;
  uint *in_stack_00000004;
  uint *entityIndexOut;
  uint16_t uVar8;
  far_t hint;
  uint8_t foundEntities;
  uint8_t menuItems;
  undefined2 auStack_2c [19];
  uint8_t entityIndex;
  char cStack_3;
  
  entityIndexOut = (uint *)CONCAT22(unaff_DI,in_stack_00000004);
  in_stack_00000004 = (uint *)ovr_alignUp4();
  _entityIndex = *(undefined2 *)CONCAT22((int *)entityIndexPtr,y);
  slotMin = 0xffff;
  for (uVar6 = 0; uVar8 = (uint16_t)((ulong)entityIndexOut >> 0x10), (int)uVar6 < 10;
      uVar6 = uVar6 + 1) {
    entityIndexOut = (uint *)CONCAT22(uVar8,unaff_SS);
    slotMin = ovc45_usesAlignUp4(slotMin,(int)in_stack_00000004,x,entityIndexOut);
    uVar8 = (uint16_t)((ulong)entityIndexOut >> 0x10);
    if (slotMin == 0xffff) break;
    *(undefined2 *)(&foundEntities + uVar6 * 2) = _entityIndex;
    uVar7 = *(undefined2 *)(slotMin * 4);
    auStack_2c[uVar6 * 2] = ((undefined2 *)(slotMin * 4))[1];
    *(undefined2 *)(&menuItems + uVar6 * 4) = uVar7;
  }
  if ((int)uVar6 < 2) {
    *(undefined2 *)CONCAT22((int *)entityIndexPtr,y) = _entityIndex;
    iVar1 = (uint)((entity_t *)Entities)[*(int *)CONCAT22((int *)entityIndexPtr,y)].base.gindex *
            0x95;
    uVar7 = CONCAT11((char)((uint)iVar1 >> 8),
                     '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 + iVar1) & 0x1f));
  }
  else {
    pcVar2 = ovr_ovc22_className((byte)uVar8,
                                 CONCAT11((char)((uint)(*(int *)CONCAT22((int *)entityIndexPtr,y) *
                                                       0x37) >> 8),
                                          *(undefined1 *)
                                           ((int)&((entity_t *)Entities)
                                                  [*(int *)CONCAT22((int *)entityIndexPtr,y)].base.
                                                  entity + 3)));
    puVar3 = (undefined2 *)
             ((uint)*(byte *)((int)&((entity_t *)Entities)
                                    [*(int *)CONCAT22((int *)entityIndexPtr,y)].base.entity + 3) * 4
             );
    uVar5 = 0x217a;
    pcVar2 = ovr_fmVsprintf((char *)CONCAT22(*puVar3,(char *)"puppetmaker" + 3),
                            (char *)CONCAT22(pcVar2,(char *)puVar3[1]));
    hint.seg = uVar8;
    hint.ofs = uVar5;
    puVar4 = &menuItems;
    entries.seg = uVar6;
    entries.ofs = (uint16_t)unaff_SS;
    ovr_ovc28_compute2(entries,(uint16_t)pcVar2,hint,puVar4);
    cStack_3 = (char)puVar4;
    if ((char)puVar4 == '\0') {
      uVar7 = 0xff;
    }
    else {
      *(undefined2 *)CONCAT22((int *)entityIndexPtr,y) = auStack_2c[((uint)puVar4 & 0xff) - 0xc];
      uVar7 = (undefined2)((ulong)Entities >> 0x10);
      selectedPartyIndex =
           *(undefined1 *)
            ((int)&((entity_t *)Entities)[*(int *)CONCAT22((int *)entityIndexPtr,y)].base.entity + 3
            );
      iVar1 = (uint)((entity_t *)Entities)[*(int *)CONCAT22((int *)entityIndexPtr,y)].base.gindex *
              0x95;
      uVar7 = CONCAT11((char)((uint)iVar1 >> 8),
                       '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 + iVar1) & 0x1f));
    }
  }
  return uVar7;
}



/* 77eb:0683 */

/* [R6] touches GMapFlags, GUnits */

int __cdecl16far ovc45_usesGMapFlags(int x,int y)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  byte bVar4;
  int unaff_DI;
  
  psVar1 = (*(short (*) [60] [148])GMapFlags)[y] + x;
  if ((psVar1[0x94] & 3U) == 0) {
    sVar2 = ovc45_getUnitIndex(y,unaff_DI,x);
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

undefined2 __cdecl16far ovc45_usesLDIV_at_(uint8_t partyIndex,...)

{
  long *plVar1;
  undefined2 uVar2;
  undefined2 unaff_BP;
  undefined2 unaff_SI;
  long lVar3;
  undefined1 in_stack_00000004;
  undefined4 in_stack_0000fff8;
  undefined2 in_stack_0000fffc;
  
  lVar3 = 10;
  uVar2 = GPopulationHi;
  plVar1 = LXMUL_at_((long *)0x0,CONCAT22((int)((ulong)in_stack_0000fff8 >> 0x10),unaff_SI),
                     CONCAT22(unaff_BP,in_stack_0000fffc));
  lVar3 = LDIV_at_((long)CONCAT22(uVar2,plVar1),lVar3);
  return (int)lVar3;
}



/* 77eb:0976 */

/* Returns the leader's rank as a percentage (rank*10, capped at 100). */

int __cdecl16far ovc45_rankPercent(byte partyIndex,...)

{
  int iVar1;
  byte in_stack_00000004;
  
  if (*(uint *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x87) < 0xb) {
    iVar1 = *(int *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x87) * 10;
  }
  else {
    iVar1 = 100;
  }
  return iVar1;
}



/* 77eb:09c1 */

/* [R7] body shape: compute */

int __cdecl16far ovc45_compute3(byte partyIndex,...)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  byte in_stack_00000004;
  
  uVar4 = (undefined2)((ulong)*(undefined4 *)((uint)in_stack_00000004 << 2) >> 0x10);
  iVar3 = (int)*(undefined4 *)((uint)in_stack_00000004 << 2);
  uVar1 = *(undefined2 *)(iVar3 + 0x58);
  iVar3 = *(int *)(iVar3 + 0x56);
  iVar2 = ovc45_usesLDIV_at_((uint8_t)iVar3,CONCAT11((char)((uint)uVar1 >> 8),in_stack_00000004),
                             uVar1);
  return iVar3 + iVar2;
}



/* 77eb:0a02 */

/* [R6] touches GPopulationLo, GPopulationHi */

void __cdecl16far ovc45_usesGPopulationLo(byte partyIndex,uint goldLo,int goldHi,...)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  bool bVar10;
  byte in_stack_00000004;
  uint8_t in_stack_0000fffa;
  
  uVar9 = (undefined2)((ulong)*(undefined4 *)((uint)in_stack_00000004 << 2) >> 0x10);
  iVar7 = (int)*(undefined4 *)((uint)in_stack_00000004 << 2);
  uVar3 = *(uint *)(iVar7 + 0x58);
  if (((int)uVar3 < (int)goldLo) || ((uVar3 == goldLo && (*(uint *)(iVar7 + 0x56) < _partyIndex))))
  {
    uVar9 = (undefined2)((ulong)*(undefined4 *)((uint)in_stack_00000004 << 2) >> 0x10);
    iVar7 = (int)*(undefined4 *)((uint)in_stack_00000004 << 2);
    uVar5 = *(uint *)(iVar7 + 0x56);
    uVar3 = _partyIndex - uVar5;
    iVar7 = (goldLo - *(int *)(iVar7 + 0x58)) - (uint)(_partyIndex < uVar5);
    iVar6 = 0x217a;
    uVar4 = *(undefined4 *)((uint)in_stack_00000004 << 2);
    uVar9 = (undefined2)((ulong)uVar4 >> 0x10);
    iVar8 = (int)uVar4;
    *(undefined2 *)(iVar8 + 0x58) = 0;
    *(undefined2 *)(iVar8 + 0x56) = 0;
    uVar5 = ovc45_usesLDIV_at_(in_stack_0000fffa,
                               CONCAT11((char)(((uint)in_stack_00000004 << 2) >> 8),
                                        in_stack_00000004));
    if ((iVar7 < iVar6) || ((iVar7 == iVar6 && (uVar3 < uVar5)))) {
      bVar10 = GPopulationLo < uVar3;
      GPopulationLo = GPopulationLo - uVar3;
      GPopulationHi = (GPopulationHi - iVar7) - (uint)bVar10;
    }
    else {
      bVar10 = GPopulationLo < uVar5;
      GPopulationLo = GPopulationLo - uVar5;
      GPopulationHi = (GPopulationHi - iVar6) - (uint)bVar10;
    }
  }
  else {
    uVar9 = (undefined2)((ulong)*(undefined4 *)((uint)in_stack_00000004 << 2) >> 0x10);
    iVar7 = (int)*(undefined4 *)((uint)in_stack_00000004 << 2);
    puVar1 = (uint *)(iVar7 + 0x56);
    uVar3 = *puVar1;
    *puVar1 = *puVar1 - _partyIndex;
    piVar2 = (int *)(iVar7 + 0x58);
    *piVar2 = (*piVar2 - goldLo) - (uint)(uVar3 < _partyIndex);
  }
  return;
}



/* 77eb:0aea */

/* [R7] body shape: compute */

uint __cdecl16far ovc45_compute4(int x,uint16_t y,...)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  byte extraout_AH;
  byte bVar4;
  int unaff_DI;
  int in_stack_00000004;
  
  iVar1 = in_stack_00000004;
  uVar3 = ovr_constr_usesGMapFlags(x,unaff_DI,in_stack_00000004);
  if ((uVar3 & 0xff) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = ovr_ovc23_findRecordAt(x,unaff_DI,iVar1);
    if (uVar3 == 0xffff) {
      bVar2 = ovc45_getUnitType(x,unaff_DI,iVar1);
      if (CONCAT11(extraout_AH,bVar2) == 0) {
        bVar2 = ovc45_getUnitType(x,unaff_DI,iVar1 + -1);
        if (*(byte *)((uint)bVar2 * 0x27 + 0x11b) < 2) {
          bVar2 = ovc45_getUnitType(x,unaff_DI,iVar1 + -2);
          if (*(byte *)((uint)bVar2 * 0x27 + 0x11b) < 3) {
            bVar2 = ovc45_getUnitType(x,unaff_DI,iVar1 + -3);
            bVar4 = (byte)((uint)bVar2 * 0x27 >> 8);
            if (*(byte *)((uint)bVar2 * 0x27 + 0x11b) < 4) {
              uVar3 = CONCAT11(bVar4,1);
            }
            else {
              uVar3 = (uint)bVar4 << 8;
            }
          }
          else {
            uVar3 = (uint)bVar2 * 0x27 & 0xff00;
          }
        }
        else {
          uVar3 = (uint)bVar2 * 0x27 & 0xff00;
        }
      }
      else {
        uVar3 = (uint)extraout_AH << 8;
      }
    }
    else {
      uVar3 = uVar3 & 0xff00;
    }
  }
  return uVar3;
}



/* 77eb:0bc1 */

/* [R7] body shape: compute */

uint __cdecl16far ovc45_compute5(void)

{
  undefined4 uVar1;
  byte bVar2;
  byte extraout_AH;
  uint uVar3;
  
  bVar2 = ovr_manage_findFirstLeader();
  if (bVar2 == 0xff) {
    uVar3 = (uint)extraout_AH << 8;
  }
  else {
    uVar1 = *(undefined4 *)((uint)bVar2 << 2);
    if (*(byte *)((int)uVar1 + 0x86) < 4) {
      uVar3 = CONCAT11((char)(((uint)bVar2 << 2) >> 8),4);
    }
    else if (*(byte *)((int)*(undefined4 *)((uint)bVar2 << 2) + 0x86) < 9) {
      uVar1 = *(undefined4 *)((uint)bVar2 << 2);
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
  undefined4 uVar2;
  uint uVar3;
  undefined2 uVar4;
  
  if (*(char *)((uint)bldType * 0x27 + 0x133) == '\x17') {
    for (uVar3 = 0xf8; uVar3 < GUnitCount; uVar3 = uVar3 + 1) {
      uVar4 = (undefined2)((ulong)GUnits >> 0x10);
      bVar1 = ((unit_t *)GUnits)[uVar3].unitType;
      if (((*(char *)((uint)((unit_t *)GUnits + uVar3)->bldType * 0x27 + 0x133) == '\x17') &&
          (bVar1 != 0xff)) &&
         (uVar2 = *(undefined4 *)((uint)bVar1 << 2), *(char *)((int)uVar2 + 0x3f) == '\0')) {
        return true;
      }
    }
    for (uVar3 = 0; uVar3 < GRecordCount; uVar3 = uVar3 + 1) {
      bVar1 = *(byte *)(uVar3 * 0x12 + 9);
      if (((*(char *)((uint)*(byte *)(uVar3 * 0x12 + 8) * 0x27 + 0x133) == '\x17') &&
          (bVar1 != 0xff)) &&
         (uVar2 = *(undefined4 *)((uint)bVar1 << 2), *(char *)((int)uVar2 + 0x3f) == '\0')) {
        return true;
      }
    }
  }
  return false;
}



/* 77eb:0d61 */

/* WARNING: Removing unreachable block (ram,0x00079554) */
/* Builds the building-placement verdict for a site: the 'It will cost ... gp.' line or the reason
   it cannot be placed (water, narrow, rank, outpost limit, walls, arena). */

uint __cdecl16far
ovc45_buildPlacementMessage
          (uint param_1,uint param_2,int param_3,undefined2 param_4,char param_5,...)

{
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
  far_t src;
  far_t src_00;
  far_t pixels_24;
  far_t buf;
  far_t fVar2;
  bool bVar3;
  stg_tmp_t *psVar4;
  far_t *pfVar5;
  cte_t *pcVar6;
  int sx;
  long *plVar7;
  uint uVar8;
  int iVar9;
  uint8_t *puVar10;
  char *pcVar11;
  size_t sVar12;
  undefined1 *puVar13;
  uint16_t uVar14;
  char *arg1;
  undefined2 uVar15;
  undefined2 uVar16;
  undefined2 *puVar17;
  int iVar18;
  undefined2 unaff_SI;
  int iVar19;
  int unaff_DI;
  uint16_t uVar20;
  uint16_t uVar21;
  char *unaff_SS;
  undefined4 uVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  char cVar25;
  undefined1 uVar26;
  undefined1 uVar27;
  byte typeIndex;
  undefined1 uVar28;
  undefined1 in_stack_0000fc0c;
  undefined1 in_stack_0000fc0d;
  undefined1 in_stack_0000fc0e;
  undefined1 in_stack_0000fc0f;
  long *in_stack_0000fc10;
  long in_stack_0000fc12;
  long in_stack_0000fc16;
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
  undefined2 uStack_c;
  uint8_t *puStack_a;
  int iStack_4;
  
  typeIndex = (byte)unaff_DI;
  uVar28 = (undefined1)((uint)unaff_DI >> 8);
  cVar25 = (char)param_1;
  uVar8 = ovr_alignUp4(unaff_DI,cVar25);
  bStack_13 = cVar25 - ((char)uVar8 + -2);
  do {
    uStack_f = 0;
    bStack_11 = *(byte *)((int)&((entity_t *)Entities)[param_3].base.entity + 3);
    uVar8 = ovr_bldng_usesGStrangeTable
                      (typeIndex,*(undefined1 *)((int)*(undefined4 *)((uint)bStack_11 << 2) + 0x85))
    ;
    bStack_12 = (byte)uVar8;
    iVar9 = (uVar8 & 0xff) * 0x27;
    if (*(int *)(iVar9 + 0x112) == 0 && *(int *)(iVar9 + 0x114) == 0) {
      iVar9 = (uVar8 & 0xff) * 0x27;
      pcVar11 = (char *)&AgntAnms[0x88].missileDy;
      puVar10 = ovr_ovc15_usesStshRealloc
                          ((char *)CONCAT13(uVar28,CONCAT12(typeIndex,*(undefined2 *)(iVar9 + 0x110)
                                                           )),*(undefined2 *)(iVar9 + 0x10e));
      ovr_stsprintf((char *)CONCAT22(0x74f0,unaff_SS),
                    (char *)CONCAT22(puVar10,(char *)"puppetmaker" + 3),pcVar11,&msg,0x10,
                    (char)pcVar11);
      uVar26 = (undefined1)((uint)pcVar11 >> 8);
    }
    else {
      iVar9 = (uVar8 & 0xff) * 0x27;
      arg1 = (char *)&AgntAnms[0x88].missileDy;
      puVar10 = ovr_ovc15_usesStshRealloc
                          ((char *)CONCAT13(uVar28,CONCAT12(typeIndex,*(undefined2 *)(iVar9 + 0x110)
                                                           )),*(undefined2 *)(iVar9 + 0x10e));
      uVar26 = 0x19;
      pcVar11 = (char *)*(undefined2 *)((uint)bStack_12 * 0x27 + 0x114);
      ovr_stsprintf((char *)CONCAT22(*(undefined2 *)((uint)bStack_12 * 0x27 + 0x112),unaff_SS),
                    (char *)CONCAT22(puVar10,pcVar11),arg1,&msg,(char)pcVar11,(char)arg1);
    }
    iVar9 = 0;
    cStack_e = '\0';
    bVar3 = ovc45_textArena2(bStack_12);
    uVar23 = SUB21(unaff_SS,0);
    uVar24 = (undefined1)((uint)unaff_SS >> 8);
    if (bVar3) {
      strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg))," You can only place a single arena.");
      cStack_e = '\x01';
    }
    else {
      uVar8 = ovc45_compute1(bStack_12,param_1,param_2);
      if ((uVar8 & 0xff) == 0) {
        strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg))," Bridges must be near water\'s edge."
              );
        cStack_e = '\x01';
      }
      else {
        bVar3 = ovr_bldng_textArena(bStack_11,typeIndex,(uint)bStack_12);
        if (bVar3) {
          if ((*(char *)((uint)bStack_12 * 0x27 + 0x11b) == '\x04') &&
             ((((uVar8 = ovc45_compute4(param_2,param_1 - bStack_13), (uVar8 & 0xff) == 0 ||
                (uVar8 = ovc45_compute4(param_2,(param_1 - bStack_13) + 1), (uVar8 & 0xff) == 0)) ||
               (uVar8 = ovc45_compute4(param_2,(param_1 - bStack_13) + 2), (uVar8 & 0xff) == 0)) ||
              (uVar8 = ovc45_compute4(param_2,(param_1 - bStack_13) + 3), (uVar8 & 0xff) == 0)))) {
            uVar15 = 0x195d;
            pcVar11 = (char *)*(undefined2 *)((uint)bStack_12 * 0x27 + 0x110);
            pcVar11 = ovr_stsprintf((char *)CONCAT22(0x75b7,unaff_SS),
                                    (char *)CONCAT22(*(undefined2 *)((uint)bStack_12 * 0x27 + 0x10e)
                                                     ,(char *)"puppetmaker" + 3),pcVar11,&reqMsg,
                                    0x10,(char)pcVar11);
            strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                   (char *)CONCAT13((char)((uint)uVar15 >> 8),CONCAT12((char)uVar15,pcVar11)));
            uVar26 = (undefined1)((uint)uVar15 >> 8);
            cStack_e = '\x01';
          }
          else if (((*(char *)((uint)bStack_12 * 0x27 + 0x11b) == '\x02') &&
                   ((bStack_13 == 3 ||
                    (uVar8 = ovc45_compute4(param_2,param_1 + 1), (char)uVar8 == '\0')))) &&
                  ((bStack_13 == 0 ||
                   (uVar8 = ovc45_compute4(param_2,param_1 - 1), (char)uVar8 == '\0')))) {
            uVar15 = 0x195d;
            pcVar11 = (char *)*(undefined2 *)((uint)bStack_12 * 0x27 + 0x110);
            pcVar11 = ovr_stsprintf((char *)CONCAT22(0x75d7,unaff_SS),
                                    (char *)CONCAT22(*(undefined2 *)((uint)bStack_12 * 0x27 + 0x10e)
                                                     ,(char *)"puppetmaker" + 3),pcVar11,&reqMsg,
                                    0x10,(char)pcVar11);
            strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                   (char *)CONCAT13((char)((uint)uVar15 >> 8),CONCAT12((char)uVar15,pcVar11)));
            uVar26 = (undefined1)((uint)uVar15 >> 8);
            cStack_e = '\x01';
          }
          else {
            uVar26 = 0x19;
            uVar8 = ovc45_usesGMapFlags5(*(char *)((uint)bStack_12 * 0x27 + 0x11e),param_1,param_2);
            if ((char)uVar8 == '\0') {
              if (((*(char *)((uint)bStack_12 * 0x27 + 0x11a) == '\x02') ||
                  (*(char *)((uint)bStack_12 * 0x27 + 0x11e) == '\x01')) ||
                 ((uVar26 = 0x19, *(char *)((uint)bStack_12 * 0x27 + 0x11e) == '\x02' ||
                  (uVar8 = ovr_attact_usesGMapFlags(param_2,param_1), (uVar8 & 0xff) != 0)))) {
                uVar8 = ovr_constr_usesGMapFlags(param_2,param_1);
                if ((((char)uVar8 == '\0') &&
                    ((*(uint *)((uint)bStack_12 * 0x27 + 0x121) & 0x20) == 0)) &&
                   (uVar26 = 0x19, *(char *)((uint)bStack_12 * 0x27 + 0x11e) == '\0')) {
                  strcpy((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                         "This location is unsuitable for buildings.");
                  cStack_e = '\x01';
                }
                else {
                  uVar15 = 0x2410;
                  pcVar11 = ovr_ovc22_className((byte)*(undefined2 *)
                                                       ((uint)bStack_12 * 0x27 + 0x125),
                                                CONCAT11((char)((uint)(param_3 * 0x37) >> 8),
                                                         *(undefined1 *)
                                                          ((int)&((entity_t *)Entities)[param_3].
                                                                 base.entity + 3)));
                  uVar16 = 0x217a;
                  ovc45_compute9((char *)CONCAT22(*(undefined2 *)((uint)bStack_11 * 4),unaff_SS),
                                 (char *)CONCAT22(Font03.ofs,
                                                  (char *)((undefined2 *)((uint)bStack_11 * 4))[1]),
                                 (char *)CONCAT22(0x55,Font03.seg),3,(char)pcVar11,&text,
                                 (char)pcVar11,uVar15);
                  pcVar11 = ovr_stsprintf();
                  uVar26 = (undefined1)uVar16;
                  uVar27 = (undefined1)((uint)uVar16 >> 8);
                  sVar12 = strlen((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)));
                  puVar10 = &msg;
                  strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,puVar10 + sVar12)),
                         (char *)CONCAT13(uVar27,CONCAT12(uVar26,pcVar11)));
                  uVar26 = (undefined1)((uint)puVar10 >> 8);
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
            uVar8 = ovc45_compute5();
            if ((char)uVar8 == '\0') {
              strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                     " No more outposts are available.");
            }
            else {
              uVar8 = ovc45_compute5();
              uVar15 = 0x2410;
              pcVar11 = (char *)*(undefined2 *)((int)&GStatsLabels[4].seg + (uVar8 & 0xff) * 8);
              pcVar11 = ovr_stsprintf((char *)CONCAT22(0x753c,unaff_SS),
                                      (char *)CONCAT22(((far_t *)(GStatsLabels + 4) +
                                                       (uVar8 & 0xff) * 2)->ofs,
                                                       (char *)"puppetmaker" + 3),pcVar11,&reqMsg,
                                      0x10,(char)pcVar11);
              strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                     (char *)CONCAT13((char)((uint)uVar15 >> 8),CONCAT12((char)uVar15,pcVar11)));
              uVar26 = (undefined1)((uint)uVar15 >> 8);
            }
          }
          else if ((*(byte *)((uint)bStack_12 * 0x27 + 0x134) & 0x80) == 0) {
            uVar15 = 0x195d;
            pcVar11 = ovr_stsprintf((char *)CONCAT13(0x75,CONCAT12(0x99,unaff_SS)),
                                    (char *)(ulong)CONCAT12(*(undefined1 *)
                                                             ((uint)bStack_12 * 0x27 + 0x134),0x2410
                                                           ),(char *)&reqMsg);
            strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                   (char *)CONCAT13((char)((uint)uVar15 >> 8),CONCAT12((char)uVar15,pcVar11)));
            uVar26 = (undefined1)((uint)uVar15 >> 8);
          }
          else {
            uVar8 = *(byte *)((uint)bStack_12 * 0x27 + 0x134) & 0x7f;
            uVar15 = 0x2410;
            pcVar11 = (char *)*(undefined2 *)((int)&GStatsLabels[4].seg + uVar8 * 8);
            pcVar11 = ovr_stsprintf((char *)CONCAT22(0x7581,unaff_SS),
                                    (char *)CONCAT22(((far_t *)(GStatsLabels + 4) + uVar8 * 2)->ofs,
                                                     (char *)"puppetmaker" + 3),pcVar11,&reqMsg,0x10
                                    ,(char)pcVar11);
            strcat((char *)CONCAT13(uVar24,CONCAT12(uVar23,&msg)),
                   (char *)CONCAT13((char)((uint)uVar15 >> 8),CONCAT12((char)uVar15,pcVar11)));
            uVar26 = (undefined1)((uint)uVar15 >> 8);
          }
          cStack_e = '\x01';
        }
      }
    }
    if (cStack_e == '\0') {
      uVar8 = ovr_constr_usesGMapFlags(param_2,param_1);
      uVar23 = uVar26;
      if (((char)uVar8 == '\0') &&
         (uVar23 = 0x19, (*(uint *)((uint)bStack_12 * 0x27 + 0x121) & 0x20) == 0)) {
        uVar26 = 0x19;
        uVar23 = 0x19;
        if (*(char *)((uint)bStack_12 * 0x27 + 0x11e) == '\0') goto L_OVC45_77eb_0d61_1379;
      }
      uVar26 = uVar23;
      in_stack_0000fc0e = 0x10;
      in_stack_0000fc0f = 0x24;
      in_stack_0000fc0c = 0x85;
      in_stack_0000fc0d = 0x76;
      _uStack_c = (stg_tmp_t *)CONCAT31(stack0xfff5,1);
      iVar9 = 1;
    }
L_OVC45_77eb_0d61_1379:
    *(char **)(&stack0xfc0e + iVar9 * 4) = (char *)"puppetmaker" + 3;
    *(char **)(&stack0xfc0c + iVar9 * 4) = (char *)"Change Building";
    *(undefined1 *)((int)&uStack_c + iVar9) = 2;
    iVar19 = iVar9 + 1;
    if (param_5 != '\0') {
      *(char **)(&stack0xfc0e + iVar19 * 4) = (char *)"puppetmaker" + 3;
      *(char **)(&stack0xfc0c + iVar19 * 4) = (char *)"Change Party";
      *(undefined1 *)((int)&uStack_c + iVar9 + 1) = 3;
      iVar19 = iVar9 + 2;
    }
    *(char **)(&stack0xfc0e + iVar19 * 4) = (char *)"puppetmaker" + 3;
    *(char **)(&stack0xfc0c + iVar19 * 4) = (char *)"Done";
    *(undefined1 *)((int)&uStack_c + iVar19) = 4;
    iVar9 = iVar19 + 1;
    puVar10 = (uint8_t *)CONCAT11(uVar26,bStack_11);
    goldPartyIndex = bStack_11;
    puVar13 = &stack0xfc0c;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = (char)iVar9;
    entries.ofs = (uint16_t)unaff_SS;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = 0;
    ovr_ovc28_compute2(entries,(uint16_t)&msg,puVar13);
    fVar2.seg = BldGfxNormal[100].seg;
    fVar2.ofs = BldGfxNormal[100].ofs;
    bStack_10 = (byte)puVar13;
    goldPartyIndex = 0xff;
    if (bStack_10 != 0) {
      puVar10 = &unusedFlag;
      bStack_10 = puVar10[(uint)puVar13 & 0xff];
    }
    uStack_f = 0;
    uVar8 = (uint)bStack_10;
  } while (4 < uVar8);
  iVar18 = uVar8 * 2;
  uVar15 = 0x7000;
  switch(uVar8) {
  case 0:
code_r0x00074dd2:
    BldGfxNormal[100] = fVar2;
    *(undefined2 *)((int)&BldGfxNormal[0].seg + uVar8) = CONCAT11(uVar28,typeIndex);
    *(undefined2 *)((int)&((far_t *)BldGfxNormal)->ofs + uVar8) = unaff_SI;
    uVar22 = func_0x0007ffe0(uVar15);
    *(undefined2 *)((int)&BldGfxNormal[1].seg + iVar9 * 0xc) = (int)((ulong)uVar22 >> 0x10);
    ((far_t *)(BldGfxNormal + 1) + iVar9 * 3)->ofs = (uint16_t)uVar22;
    uVar22 = func_0x0007ffe0(uVar15);
    *(undefined2 *)((int)&BldGfxNormal[2].seg + iVar9 * 0xc) = (int)((ulong)uVar22 >> 0x10);
    ((far_t *)(BldGfxNormal + 2) + iVar9 * 3)->ofs = (uint16_t)uVar22;
    uVar22 = func_0x0007ffe0(uVar15);
    *(undefined2 *)((int)&BldGfxRuin[0].seg + iVar9 * 0xc) = (int)((ulong)uVar22 >> 0x10);
    ((far_t *)BldGfxRuin + iVar9 * 3)->ofs = (uint16_t)uVar22;
    uVar22 = func_0x0007ffe0(uVar15);
    *(undefined2 *)((int)&BldGfxRuin[1].seg + iVar9 * 0xc) = (int)((ulong)uVar22 >> 0x10);
    ((far_t *)(BldGfxRuin + 1) + iVar9 * 3)->ofs = (uint16_t)uVar22;
    uVar22 = func_0x0007ffe0(uVar15);
    uVar14 = 0x195d;
    *(undefined2 *)((int)&BldGfxRuin[2].seg + iVar9 * 0xc) = (int)((ulong)uVar22 >> 0x10);
    ((far_t *)(BldGfxRuin + 2) + iVar9 * 3)->ofs = (uint16_t)uVar22;
    goto L_init_assets_4EA5;
  case 1:
code_r0x00072658:
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(puVar10,psVar4);
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x820064)),199,194,26,
                              (&psVar4->aptr)->ofs,100,199,0xc2);
    pcVar6 = ovr_stshStoreFile((uint8_t *)
                               CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puVar10)),
                               pfVar5);
    uVar15 = 0x195d;
    *(uint16_t *)((int)&BldInstances[0].seg + iVar9 * 0xc) = (uint16_t)puVar10;
    ((bld_inst_t *)BldInstances + iVar9)->ofs = (short)pcVar6;
    uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x410064)),199,129,
                              26,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,100,199,0x81);
    pcVar6 = ovr_stshStoreFile((uint8_t *)
                               CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),pfVar5
                              );
    uVar16 = 0x195d;
    *(undefined2 *)((int)&BldInstances[0].seg + (iVar9 + 1) * 0xc) = uVar15;
    ((bld_inst_t *)BldInstances + iVar9 + 1)->ofs = (short)pcVar6;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x64)),199,64,26,
                              (&((stg_tmp_t *)_uStack_c)->aptr)->ofs,100,199,0x40);
    pcVar6 = ovr_stshStoreFile((uint8_t *)
                               CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar16)),pfVar5
                              );
    uVar14 = 0x195d;
    *(undefined2 *)((int)&BldInstances[0].seg + (iVar9 + 2) * 0xc) = uVar16;
    ((bld_inst_t *)BldInstances + iVar9 + 2)->ofs = (short)pcVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    break;
  case 2:
    uVar8 = ovc45_cellBelowBlocked(uVar8 - 1,CONCAT11(uVar28,typeIndex));
    if (((uVar8 & 0xff) == 0) &&
       (uVar8 = ovc45_cellBelowBlocked(iVar19 + 2,param_2), (uVar8 & 0xff) == 0)) {
      uVar8 = 0;
    }
    else {
      uVar8 = 1;
    }
    return uVar8;
  case 3:
    goto code_r0x00074dd0;
  case 4:
    LOCK();
    *(undefined1 *)(iVar18 + iVar9) = (char)((uint)iVar18 >> 8);
    UNLOCK();
    strcpy((char *)CONCAT13(uVar28,CONCAT12(typeIndex,(uint)bStack_10)),
           (char *)CONCAT13(in_stack_0000fc0d,CONCAT12(in_stack_0000fc0c,unaff_SI)));
    LOCK();
    *(int *)(&stack0xfffe + param_2) = iVar9;
    UNLOCK();
    while (iStack_4 = iStack_4 + 1, iStack_4 < 0xc) {
      if (cVar25 == '\0') {
        uVar22 = func_0x0007ffe0();
        puVar10 = (uint8_t *)((ulong)uVar22 >> 0x10);
        *(uint16_t *)((int)&timeOfDayGfx[0].seg + iStack_4 * 4) = (uint16_t)puVar10;
        ((far_t *)timeOfDayGfx + iStack_4)->ofs = (uint16_t)uVar22;
      }
      else {
        puVar10 = (uint8_t *)((ulong)((long)iStack_4 * 0x17) >> 0x10);
        iVar9 = (int)((long)iStack_4 * 0x17) + 6;
        uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
        (*(uint8_t *)((uint8_t *)&(src.seg))) = 0x15;
        src.ofs = iVar9;
        (*(uint8_t *)((uint8_t *)&(src.seg) + 1)) = 0;
        pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,src,
                                iStack_4 * 0x17 + 0x1b,(char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,
                                (char)iVar9,0x15);
        pcVar6 = ovr_stshStoreFile((uint8_t *)
                                   CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puVar10)),
                                   pfVar5);
        *(uint16_t *)((int)&timeOfDayGfx[0].seg + iStack_4 * 4) = (uint16_t)puVar10;
        ((far_t *)timeOfDayGfx + iStack_4)->ofs = (uint16_t)pcVar6;
      }
    }
    iStack_4 = 0;
    while( true ) {
      if (5 < iStack_4) break;
      if (cVar25 == '\0') {
        uVar22 = func_0x0007ffe0();
        puVar10 = (uint8_t *)((ulong)uVar22 >> 0x10);
        ((undefined2 *)&blitFrameSeg)[iStack_4 * 2] = puVar10;
        ((undefined2 *)&blitFrameOfs)[iStack_4 * 2] = (int)uVar22;
      }
      else {
        puVar10 = (uint8_t *)((ulong)((long)iStack_4 * 0x17) >> 0x10);
        iVar9 = (int)((long)iStack_4 * 0x17) + 9;
        (*(uint8_t *)((uint8_t *)&(src_00.seg))) = 0x48;
        src_00.ofs = iVar9;
        (*(uint8_t *)((uint8_t *)&(src_00.seg) + 1)) = 0;
        pfVar5 = ovr_stshRleCut((far_t *)(uStack_c->aptr).seg,src_00,iStack_4 * 0x17 + 0x16,
                                (char)(&uStack_c->aptr)->ofs,(char)iVar9,0x48);
        pcVar6 = ovr_stshStoreFile((uint8_t *)
                                   CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puVar10)),
                                   pfVar5);
        ((undefined2 *)&blitFrameSeg)[iStack_4 * 2] = puVar10;
        ((undefined2 *)&blitFrameOfs)[iStack_4 * 2] = pcVar6;
      }
      iStack_4 = iStack_4 + 1;
    }
    if (cVar25 == '\0') {
      BldGfxNormal[4] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxNormal[7] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxNormal[10] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxRuin[4] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxRuin[7] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxRuin[10] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      stshStubifyBld();
      stshStubifyBld();
      stshStubifyBld();
      stshStubifyBld();
      stshStubifyBld();
      stshStubifyBld();
      stshStubifyBld();
      BldGfxNormal[0x4c] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxNormal[0x4f] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxNormal[0x52] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxRuin[0x4c] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxRuin[0x4f] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      BldGfxRuin[0x52] = far_from_u32((uint32_t)(func_0x0007ffe0()));
      uVar14 = 0x195d;
    }
    else {
      ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                     uStack_c);
      uStack_c = ovr_grabLbmTR();
      puStack_a = puVar10;
      pfVar5 = ovr_stshRleCut((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0xad0028)),50,
                              (char)(&uStack_c->aptr)->ofs,0x28,0xad);
      BldGfxNormal[4].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puVar10)),pfVar5)
      ;
      BldGfxNormal[4].seg = (uint16_t)puVar10;
      pfVar5 = ovr_stshRleCut((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x6c008c)),150,
                              (char)(&uStack_c->aptr)->ofs,0x8c,0x6c);
      BldGfxNormal[7].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puVar10)),pfVar5)
      ;
      BldGfxNormal[7].seg = (uint16_t)puVar10;
      pfVar5 = ovr_stshRleCut((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x2b00f0)),252,
                              (char)(&uStack_c->aptr)->ofs,0xf0,0x2b);
      BldGfxNormal[10].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puVar10)),pfVar5)
      ;
      BldGfxNormal[10].seg = (uint16_t)puVar10;
      pfVar5 = ovr_stshRleCut((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x6c0028)),50,
                              (char)(&uStack_c->aptr)->ofs,0x28,0x6c);
      BldGfxRuin[4].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puVar10)),pfVar5)
      ;
      BldGfxRuin[4].seg = (uint16_t)puVar10;
      pfVar5 = ovr_stshRleCut((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0xad008c)),150,
                              (char)(&uStack_c->aptr)->ofs,0x8c,0xad);
      BldGfxRuin[7].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puVar10)),pfVar5)
      ;
      BldGfxRuin[7].seg = (uint16_t)puVar10;
      pfVar5 = ovr_stshRleCut((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x6c00f0)),252,
                              (char)(&uStack_c->aptr)->ofs,0xf0,0x6c);
      BldGfxRuin[10].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puVar10)),pfVar5)
      ;
      BldGfxRuin[10].seg = (uint16_t)puVar10;
      ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                     uStack_c);
      uStack_c = ovr_grabLbmTR();
      puStack_a = puVar10;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x820009)),97,194,11,
                                (&uStack_c->aptr)->ofs,9,0x61,0xc2);
      BldGfxNormal[0xc].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puVar10)),pfVar5)
      ;
      uVar14 = 0x195d;
      BldGfxNormal[0xc].seg = (uint16_t)puVar10;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x820064)),199,194,11,
                                (&uStack_c->aptr)->ofs,100,199,0xc2);
      BldGfxNormal[0xd].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0xd].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x8200cc)),292,194,11,
                                (&uStack_c->aptr)->ofs,0xcc,0x24,0xc2);
      BldGfxNormal[0xe].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0xe].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x410009)),97,129,11,
                                (&uStack_c->aptr)->ofs,9,0x61,0x81);
      BldGfxNormal[0xf].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0xf].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x410064)),199,129,11,
                                (&uStack_c->aptr)->ofs,100,199,0x81);
      BldGfxNormal[0x10].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x10].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4100cc)),292,129,11,
                                (&uStack_c->aptr)->ofs,0xcc,0x24,0x81);
      BldGfxNormal[0x11].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x11].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x9)),97,64,11,
                                (&uStack_c->aptr)->ofs,9,0x61,0x40);
      BldGfxNormal[0x12].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x12].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x6c)),191,64,11,
                                (&uStack_c->aptr)->ofs,0x6c,0xbf,0x40);
      BldGfxNormal[0x13].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x13].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0xcc)),292,64,11,
                                (&uStack_c->aptr)->ofs,0xcc,0x24,0x40);
      BldGfxNormal[0x14].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x14].seg = uVar20;
      ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                     uStack_c);
      uStack_c = ovr_grabLbmTR();
      puStack_a = (uint8_t *)uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x820009)),97,194,11,
                                (&uStack_c->aptr)->ofs,9,0x61,0xc2);
      BldGfxRuin[0xc].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0xc].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x820064)),199,194,11,
                                (&uStack_c->aptr)->ofs,100,199,0xc2);
      BldGfxRuin[0xd].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0xd].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x8200cc)),292,194,11,
                                (&uStack_c->aptr)->ofs,0xcc,0x24,0xc2);
      BldGfxRuin[0xe].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0xe].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x410009)),97,129,11,
                                (&uStack_c->aptr)->ofs,9,0x61,0x81);
      BldGfxRuin[0xf].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0xf].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x410064)),199,129,11,
                                (&uStack_c->aptr)->ofs,100,199,0x81);
      BldGfxRuin[0x10].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x10].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4100cc)),292,129,11,
                                (&uStack_c->aptr)->ofs,0xcc,0x24,0x81);
      BldGfxRuin[0x11].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x11].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x9)),97,64,11,
                                (&uStack_c->aptr)->ofs,9,0x61,0x40);
      BldGfxRuin[0x12].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x12].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x6c)),191,64,11,
                                (&uStack_c->aptr)->ofs,0x6c,0xbf,0x40);
      BldGfxRuin[0x13].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x13].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0xcc)),292,64,11,
                                (&uStack_c->aptr)->ofs,0xcc,0x24,0x40);
      BldGfxRuin[0x14].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x14].seg = uVar14;
      ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                     uStack_c);
      uStack_c = ovr_grabLbmTR();
      puStack_a = (uint8_t *)uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x820000)),99,194,26,
                                (&uStack_c->aptr)->ofs,0,99,0xc2);
      BldGfxNormal[0x15].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x15].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x820064)),199,194,26,
                                (&uStack_c->aptr)->ofs,100,199,0xc2);
      BldGfxNormal[0x16].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x16].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x8200c8)),299,194,26,
                                (&uStack_c->aptr)->ofs,200,0x2b,0xc2);
      BldGfxNormal[0x17].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x17].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x410000)),99,129,26,
                                (&uStack_c->aptr)->ofs,0,99,0x81);
      BldGfxNormal[0x18].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x18].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x410064)),199,129,26,
                                (&uStack_c->aptr)->ofs,100,199,0x81);
      BldGfxNormal[0x19].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x19].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4100c8)),299,129,26,
                                (&uStack_c->aptr)->ofs,200,0x2b,0x81);
      BldGfxNormal[0x1a].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x1a].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x0)),99,64,26,
                                (&uStack_c->aptr)->ofs,0,99,0x40);
      BldGfxNormal[0x1b].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x1b].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x64)),199,64,26,
                                (&uStack_c->aptr)->ofs,100,199,0x40);
      BldGfxNormal[0x1c].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x1c].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0xc8)),299,64,26,
                                (&uStack_c->aptr)->ofs,200,0x2b,0x40);
      BldGfxNormal[0x1d].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x1d].seg = uVar20;
      ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                     uStack_c);
      uStack_c = ovr_grabLbmTR();
      puStack_a = (uint8_t *)uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x820000)),99,194,26,
                                (&uStack_c->aptr)->ofs,0,99,0xc2);
      BldGfxRuin[0x15].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x15].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x820064)),199,194,26,
                                (&uStack_c->aptr)->ofs,100,199,0xc2);
      BldGfxRuin[0x16].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x16].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x8200c8)),299,194,26,
                                (&uStack_c->aptr)->ofs,200,0x2b,0xc2);
      BldGfxRuin[0x17].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x17].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x410000)),99,129,26,
                                (&uStack_c->aptr)->ofs,0,99,0x81);
      BldGfxRuin[0x18].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x18].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x410064)),199,129,26,
                                (&uStack_c->aptr)->ofs,100,199,0x81);
      BldGfxRuin[0x19].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x19].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4100c8)),299,129,26,
                                (&uStack_c->aptr)->ofs,200,0x2b,0x81);
      BldGfxRuin[0x1a].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x1a].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x0)),99,64,26,
                                (&uStack_c->aptr)->ofs,0,99,0x40);
      BldGfxRuin[0x1b].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x1b].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x64)),199,64,26,
                                (&uStack_c->aptr)->ofs,100,199,0x40);
      BldGfxRuin[0x1c].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x1c].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0xc8)),299,64,26,
                                (&uStack_c->aptr)->ofs,200,0x2b,0x40);
      BldGfxRuin[0x1d].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x1d].seg = uVar14;
      ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                     uStack_c);
      uStack_c = ovr_grabLbmTR();
      puStack_a = (uint8_t *)uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x970006)),91,180,0,
                                (&uStack_c->aptr)->ofs,6,0x5b,0xb4);
      BldGfxNormal[0x1e].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x1e].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x97006e)),185,180,0,
                                (&uStack_c->aptr)->ofs,0x6e,0xb9,0xb4);
      BldGfxNormal[0x1f].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x1f].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x9700d8)),299,180,0,
                                (&uStack_c->aptr)->ofs,0xd8,0x2b,0xb4);
      BldGfxNormal[0x20].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x20].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x480006)),91,115,0,
                                (&uStack_c->aptr)->ofs,6,0x5b,0x73);
      BldGfxNormal[0x21].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x21].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x48006e)),185,115,0,
                                (&uStack_c->aptr)->ofs,0x6e,0xb9,0x73);
      BldGfxNormal[0x22].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x22].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4800d8)),299,115,0,
                                (&uStack_c->aptr)->ofs,0xd8,0x2b,0x73);
      BldGfxNormal[0x23].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x23].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x60006)),91,59,0,
                                (&uStack_c->aptr)->ofs,6,0x5b,0x3b);
      BldGfxNormal[0x24].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x24].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x6006e)),185,59,0,
                                (&uStack_c->aptr)->ofs,0x6e,0xb9,0x3b);
      BldGfxNormal[0x25].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x25].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x600d8)),299,59,0,
                                (&uStack_c->aptr)->ofs,0xd8,0x2b,0x3b);
      BldGfxNormal[0x26].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x26].seg = uVar20;
      ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                     uStack_c);
      uStack_c = ovr_grabLbmTR();
      puStack_a = (uint8_t *)uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x970006)),91,180,0,
                                (&uStack_c->aptr)->ofs,6,0x5b,0xb4);
      BldGfxRuin[0x1e].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x1e].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x97006e)),185,180,0,
                                (&uStack_c->aptr)->ofs,0x6e,0xb9,0xb4);
      BldGfxRuin[0x1f].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x1f].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x9700d8)),299,180,0,
                                (&uStack_c->aptr)->ofs,0xd8,0x2b,0xb4);
      BldGfxRuin[0x20].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x20].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x480006)),91,115,0,
                                (&uStack_c->aptr)->ofs,6,0x5b,0x73);
      BldGfxRuin[0x21].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x21].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x48006e)),185,115,0,
                                (&uStack_c->aptr)->ofs,0x6e,0xb9,0x73);
      BldGfxRuin[0x22].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x22].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4800d8)),299,115,0,
                                (&uStack_c->aptr)->ofs,0xd8,0x2b,0x73);
      BldGfxRuin[0x23].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x23].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x60006)),91,59,0,
                                (&uStack_c->aptr)->ofs,6,0x5b,0x3b);
      BldGfxRuin[0x24].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x24].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x6006e)),185,59,0,
                                (&uStack_c->aptr)->ofs,0x6e,0xb9,0x3b);
      BldGfxRuin[0x25].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x25].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x600d8)),299,59,0,
                                (&uStack_c->aptr)->ofs,0xd8,0x2b,0x3b);
      BldGfxRuin[0x26].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x26].seg = uVar14;
      ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                     uStack_c);
      uStack_c = ovr_grabLbmTR();
      puStack_a = (uint8_t *)uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x820002)),89,180,0,
                                (&uStack_c->aptr)->ofs,2,0x59,0xb4);
      BldGfxNormal[0x27].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x27].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x82006c)),191,180,0,
                                (&uStack_c->aptr)->ofs,0x6c,0xbf,0xb4);
      BldGfxNormal[0x28].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x28].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x8200d4)),298,180,0,
                                (&uStack_c->aptr)->ofs,0xd4,0x2a,0xb4);
      BldGfxNormal[0x29].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x29].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x410002)),89,115,0,
                                (&uStack_c->aptr)->ofs,2,0x59,0x73);
      BldGfxNormal[0x2a].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x2a].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x41006c)),191,115,0,
                                (&uStack_c->aptr)->ofs,0x6c,0xbf,0x73);
      BldGfxNormal[0x2b].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x2b].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4100d4)),298,115,0,
                                (&uStack_c->aptr)->ofs,0xd4,0x2a,0x73);
      BldGfxNormal[0x2c].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x2c].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x90002)),89,59,0,
                                (&uStack_c->aptr)->ofs,2,0x59,0x3b);
      BldGfxNormal[0x2d].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x2d].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x9006c)),191,59,0,
                                (&uStack_c->aptr)->ofs,0x6c,0xbf,0x3b);
      BldGfxNormal[0x2e].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x2e].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x900d4)),298,59,0,
                                (&uStack_c->aptr)->ofs,0xd4,0x2a,0x3b);
      BldGfxNormal[0x2f].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x2f].seg = uVar20;
      ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                     uStack_c);
      uStack_c = ovr_grabLbmTR();
      puStack_a = (uint8_t *)uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x820002)),89,180,0,
                                (&uStack_c->aptr)->ofs,2,0x59,0xb4);
      BldGfxRuin[0x27].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x27].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x82006c)),191,180,0,
                                (&uStack_c->aptr)->ofs,0x6c,0xbf,0xb4);
      BldGfxRuin[0x28].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x28].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x8200d4)),298,180,0,
                                (&uStack_c->aptr)->ofs,0xd4,0x2a,0xb4);
      BldGfxRuin[0x29].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x29].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x410002)),89,115,0,
                                (&uStack_c->aptr)->ofs,2,0x59,0x73);
      BldGfxRuin[0x2a].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x2a].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x41006c)),191,115,0,
                                (&uStack_c->aptr)->ofs,0x6c,0xbf,0x73);
      BldGfxRuin[0x2b].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x2b].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4100d4)),298,115,0,
                                (&uStack_c->aptr)->ofs,0xd4,0x2a,0x73);
      BldGfxRuin[0x2c].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x2c].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x90002)),89,59,0,
                                (&uStack_c->aptr)->ofs,2,0x59,0x3b);
      BldGfxRuin[0x2d].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x2d].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x9006c)),191,59,0,
                                (&uStack_c->aptr)->ofs,0x6c,0xbf,0x3b);
      BldGfxRuin[0x2e].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x2e].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x900d4)),298,59,0,
                                (&uStack_c->aptr)->ofs,0xd4,0x2a,0x3b);
      BldGfxRuin[0x2f].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxRuin[0x2f].seg = uVar14;
      ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                     uStack_c);
      ovr_grabBldLbm(116,0x73);
      ovr_grabBldLbm(446,0xa7);
      ovr_grabBldLbm(313,0x38);
      uStack_c = ovr_grabLbmTR();
      puStack_a = (uint8_t *)uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x440009)),92,182,-4,
                                (&uStack_c->aptr)->ofs,9,0x5c,0xb6);
      BldGfxNormal[0x4c].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x4c].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x44006c)),191,182,-3,
                                (&uStack_c->aptr)->ofs,0x6c,0xbf,0xb6);
      BldGfxNormal[0x4f].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      BldGfxNormal[0x4f].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4400d0)),291,182,-1,
                                (&uStack_c->aptr)->ofs,0xd0,0x23,0xb6);
      BldGfxNormal[0x52].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      BldGfxNormal[0x52].seg = uVar20;
      ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                     uStack_c);
      psVar4 = ovr_grabLbmTR();
      _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
      pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x440009)),92,182,-4,
                                (&psVar4->aptr)->ofs,9,0x5c,0xb6);
      BldGfxRuin[0x4c].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
      BldGfxRuin[0x4c].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x44006c)),191,
                                182,-3,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x6c,0xbf,0xb6);
      BldGfxRuin[0x4f].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar21 = 0x195d;
      uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
      BldGfxRuin[0x4f].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x4400d0)),291,
                                182,-1,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0xd0,0x23,0xb6);
      BldGfxRuin[0x52].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar21)),pfVar5);
      uVar14 = 0x195d;
      BldGfxRuin[0x52].seg = uVar21;
      ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                     uStack_c);
    }
    ovr_stshStubifyCopy1to0();
    if (cVar25 != '\0') {
      psVar4 = ovr_grabLbmTR();
      _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    }
    iStack_4 = 0;
    while( true ) {
      if (2 < iStack_4) break;
      if (cVar25 == '\0') {
        uVar22 = func_0x0007ffe0();
        *(undefined2 *)((int)&BldGfxNormal[1].seg + (iStack_4 + 0x1c) * 0xc) =
             (int)((ulong)uVar22 >> 0x10);
        ((far_t *)(BldGfxNormal + 1) + (iStack_4 + 0x1c) * 3)->ofs = (uint16_t)uVar22;
      }
      else {
        iVar9 = iStack_4 * 100 + 99;
        uVar15 = (undefined2)((ulong)((long)iStack_4 * 100) >> 0x10);
        uVar14 = (int)((long)iStack_4 * 100) + 0x14;
        pixels.seg = 0x21;
        pixels.ofs = uVar14;
        pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,pixels,iVar9,116,8,
                                  (&uStack_c->aptr)->ofs,(char)uVar14,(char)iVar9,0x74);
        pcVar6 = ovr_stshStoreFile((uint8_t *)
                                   CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                   pfVar5);
        *(undefined2 *)((int)&BldGfxNormal[1].seg + (iStack_4 + 0x1c) * 0xc) = uVar15;
        ((far_t *)(BldGfxNormal + 1) + (iStack_4 + 0x1c) * 3)->ofs = (uint16_t)pcVar6;
      }
      uVar14 = ((far_t *)(BldGfxNormal + 1) + (iStack_4 + 0x1c) * 3)->ofs;
      *(undefined2 *)((int)&BldGfxNormal[0].seg + (iStack_4 + 0x1c) * 0xc) =
           *(undefined2 *)((int)&BldGfxNormal[1].seg + (iStack_4 + 0x1c) * 0xc);
      ((far_t *)BldGfxNormal + (iStack_4 + 0x1c) * 3)->ofs = uVar14;
      uVar14 = *(uint16_t *)((int)&BldGfxNormal[1].seg + (iStack_4 + 0x1c) * 0xc);
      uVar20 = ((far_t *)(BldGfxNormal + 1) + (iStack_4 + 0x1c) * 3)->ofs;
      *(uint16_t *)((int)&BldGfxNormal[2].seg + (iStack_4 + 0x1c) * 0xc) = uVar14;
      ((far_t *)(BldGfxNormal + 2) + (iStack_4 + 0x1c) * 3)->ofs = uVar20;
      iStack_4 = iStack_4 + 1;
    }
    if (cVar25 != '\0') {
      ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                     uStack_c);
      psVar4 = ovr_grabLbmTR();
      _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    }
    iStack_4 = 0;
    while( true ) {
      if (2 < iStack_4) break;
      if (cVar25 == '\0') {
        uVar22 = func_0x0007ffe0();
        *(undefined2 *)((int)&BldGfxRuin[1].seg + (iStack_4 + 0x1c) * 0xc) =
             (int)((ulong)uVar22 >> 0x10);
        ((far_t *)(BldGfxRuin + 1) + (iStack_4 + 0x1c) * 3)->ofs = (uint16_t)uVar22;
      }
      else {
        iVar9 = iStack_4 * 100 + 99;
        uVar15 = (undefined2)((ulong)((long)iStack_4 * 100) >> 0x10);
        uVar14 = (int)((long)iStack_4 * 100) + 0x14;
        pixels_00.seg = 0x21;
        pixels_00.ofs = uVar14;
        pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,pixels_00,iVar9,116,8,
                                  (&uStack_c->aptr)->ofs,(char)uVar14,(char)iVar9,0x74);
        pcVar6 = ovr_stshStoreFile((uint8_t *)
                                   CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                   pfVar5);
        *(undefined2 *)((int)&BldGfxRuin[1].seg + (iStack_4 + 0x1c) * 0xc) = uVar15;
        ((far_t *)(BldGfxRuin + 1) + (iStack_4 + 0x1c) * 3)->ofs = (uint16_t)pcVar6;
      }
      uVar14 = ((far_t *)(BldGfxRuin + 1) + (iStack_4 + 0x1c) * 3)->ofs;
      *(undefined2 *)((int)&BldGfxRuin[0].seg + (iStack_4 + 0x1c) * 0xc) =
           *(undefined2 *)((int)&BldGfxRuin[1].seg + (iStack_4 + 0x1c) * 0xc);
      ((far_t *)BldGfxRuin + (iStack_4 + 0x1c) * 3)->ofs = uVar14;
      uVar14 = *(uint16_t *)((int)&BldGfxRuin[1].seg + (iStack_4 + 0x1c) * 0xc);
      uVar20 = ((far_t *)(BldGfxRuin + 1) + (iStack_4 + 0x1c) * 3)->ofs;
      *(uint16_t *)((int)&BldGfxRuin[2].seg + (iStack_4 + 0x1c) * 0xc) = uVar14;
      ((far_t *)(BldGfxRuin + 2) + (iStack_4 + 0x1c) * 3)->ofs = uVar20;
      iStack_4 = iStack_4 + 1;
    }
    if (cVar25 != '\0') {
      ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                     uStack_c);
    }
    iVar9 = 0x1f;
    if (cVar25 != '\0') {
      psVar4 = ovr_grabLbmTR();
      _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
      pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x820064)),199,194,26,
                                (&psVar4->aptr)->ofs,100,199,0xc2);
      BldGfxNormal[0x5e].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      uVar20 = 0x195d;
      uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
      BldGfxNormal[0x5e].seg = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x410064)),199,
                                129,26,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,100,199,0x81);
      BldGfxNormal[0x61].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),pfVar5);
      uVar14 = 0x195d;
      uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
      BldGfxNormal[0x61].seg = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x64)),199,64,26,
                                (&((stg_tmp_t *)_uStack_c)->aptr)->ofs,100,199,0x40);
      BldGfxNormal[100].ofs =
           (uint16_t)
           ovr_stshStoreFile((uint8_t *)
                             CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5);
      puVar10 = (uint8_t *)&AgntAnms[0x88].missileDy;
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
  ovr_stshStubifyCopy1to0();
  if (cVar25 == '\0') {
    stshStubifyBld();
    stshStubifyBld();
    stshStubifyBld();
    stshStubifyBld();
    BldGfxNormal[0x8b] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x8e] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x91] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x94] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x97] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x9a] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar14 = 0x195d;
  }
  else {
    ovr_grabBldLbm(450,0xc1);
    ovr_grabBldLbm(391,0x86);
    ovr_grabBldLbm(442,0x85);
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x970006)),91,180,-10,
                              (&uStack_c->aptr)->ofs,6,0x5b,0xb4);
    BldGfxNormal[0x81].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x81].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x97006e)),185,180,-10,
                              (&uStack_c->aptr)->ofs,0x6e,0xb9,0xb4);
    BldGfxNormal[0x82].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxNormal[0x82].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x9700d8)),299,180,-10,
                              (&uStack_c->aptr)->ofs,0xd8,0x2b,0xb4);
    BldGfxNormal[0x83].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x83].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x480006)),91,115,-10,
                              (&uStack_c->aptr)->ofs,6,0x5b,0x73);
    BldGfxNormal[0x84].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxNormal[0x84].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x48006e)),185,115,-10,
                              (&uStack_c->aptr)->ofs,0x6e,0xb9,0x73);
    BldGfxNormal[0x85].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x85].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4800d8)),299,115,-10,
                              (&uStack_c->aptr)->ofs,0xd8,0x2b,0x73);
    BldGfxNormal[0x86].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxNormal[0x86].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x60006)),91,59,-10,
                              (&uStack_c->aptr)->ofs,6,0x5b,0x3b);
    BldGfxNormal[0x87].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x87].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x6006e)),185,59,-10,
                              (&uStack_c->aptr)->ofs,0x6e,0xb9,0x3b);
    BldGfxNormal[0x88].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxNormal[0x88].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x600d8)),299,59,-10,
                              (&uStack_c->aptr)->ofs,0xd8,0x2b,0x3b);
    BldGfxNormal[0x89].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x89].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x970006)),91,180,-10,
                              (&uStack_c->aptr)->ofs,6,0x5b,0xb4);
    BldGfxRuin[0x81].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[0x81].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x97006e)),185,180,-10,
                              (&uStack_c->aptr)->ofs,0x6e,0xb9,0xb4);
    BldGfxRuin[0x82].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxRuin[0x82].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x9700d8)),299,180,-10,
                              (&uStack_c->aptr)->ofs,0xd8,0x2b,0xb4);
    BldGfxRuin[0x83].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[0x83].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x480006)),91,115,-10,
                              (&uStack_c->aptr)->ofs,6,0x5b,0x73);
    BldGfxRuin[0x84].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxRuin[0x84].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x48006e)),185,115,-10,
                              (&uStack_c->aptr)->ofs,0x6e,0xb9,0x73);
    BldGfxRuin[0x85].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[0x85].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4800d8)),299,115,-10,
                              (&uStack_c->aptr)->ofs,0xd8,0x2b,0x73);
    BldGfxRuin[0x86].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxRuin[0x86].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x60006)),91,59,-10,
                              (&uStack_c->aptr)->ofs,6,0x5b,0x3b);
    BldGfxRuin[0x87].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[0x87].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x6006e)),185,59,-10,
                              (&uStack_c->aptr)->ofs,0x6e,0xb9,0x3b);
    BldGfxRuin[0x88].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxRuin[0x88].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x600d8)),299,59,-10,
                              (&uStack_c->aptr)->ofs,0xd8,0x2b,0x3b);
    BldGfxRuin[0x89].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[0x89].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x820000)),99,194,26,
                              (&psVar4->aptr)->ofs,0,99,0xc2);
    BldGfxNormal[0x8b].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x8b].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x820064)),199,194,
                              26,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,100,199,0xc2);
    BldGfxNormal[0x8e].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x8e].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x8200c8)),299,194,
                              26,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,200,0x2b,0xc2);
    BldGfxNormal[0x91].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x91].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x410000)),99,129,
                              26,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0,99,0x81);
    BldGfxNormal[0x94].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x94].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x410064)),199,129,
                              26,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,100,199,0x81);
    BldGfxNormal[0x97].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x97].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x4100c8)),299,129,
                              26,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,200,0x2b,0x81);
    BldGfxNormal[0x9a].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxNormal[0x9a].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  ovr_stshStubifyCopy1to0();
  ovr_stshStubifyCopy1to0();
  if (cVar25 == '\0') {
    stshStubifyBld();
    stshStubifyBld();
    BldGfxNormal[0xaf] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0xb2] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0xb5] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0xaf] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0xb2] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0xb5] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar14 = 0x195d;
  }
  else {
    ovr_grabBldLbm(315,0x3a);
    ovr_grabBldLbm(317,0x3c);
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x8d003a)),134,199,-4,
                              (&uStack_c->aptr)->ofs,0x3a,0x86,199);
    BldGfxNormal[0xaf].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0xaf].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x54003a)),134,142,-4,
                              (&uStack_c->aptr)->ofs,0x3a,0x86,0x8e);
    BldGfxNormal[0xb2].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxNormal[0xb2].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x19003a)),134,83,-4,
                              (&uStack_c->aptr)->ofs,0x3a,0x86,0x53);
    BldGfxNormal[0xb5].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0xb5].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar20,psVar4);
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x8d003a)),134,199,-4,
                              (&psVar4->aptr)->ofs,0x3a,0x86,199);
    BldGfxRuin[0xaf].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxRuin[0xaf].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x54003a)),134,142,
                              -4,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x3a,0x86,0x8e);
    BldGfxRuin[0xb2].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxRuin[0xb2].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x19003a)),134,83,
                              -4,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x3a,0x86,0x53);
    BldGfxRuin[0xb5].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[0xb5].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  ovr_stshStubifyCopy1to0();
  if (cVar25 != '\0') {
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
  }
  iVar9 = 0;
  while( true ) {
    if (3 < iVar9) break;
    if (cVar25 == '\0') {
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xb7].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb7) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xb8].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb8) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xb9].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb9) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
    }
    else {
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar8 = (int)((long)iVar9 * 0x30) + 3;
      pixels_01.seg = 0;
      pixels_01.ofs = uVar8;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,pixels_01,iVar19,54,0,
                                (&uStack_c->aptr)->ofs,(char)uVar8,(char)iVar19,0x36);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xb7].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xb7) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar14 = (int)((long)iVar9 * 0x30) + 3;
      uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
      pixels_02.seg = 0x3e;
      pixels_02.ofs = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_02,iVar19,116,0
                                ,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,(char)uVar14,(char)iVar19,
                                0x74);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xb8].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xb8) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar14 = (int)((long)iVar9 * 0x30) + 3;
      uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
      pixels_03.seg = 0x3e;
      pixels_03.ofs = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_03,iVar19,116,0
                                ,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,(char)uVar14,(char)iVar19,
                                0x74);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xb9].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xb9) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
    }
    uVar14 = 0x195d;
    iVar9 = iVar9 + 1;
  }
  if (cVar25 != '\0') {
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
  }
  iVar9 = 0;
  while( true ) {
    if (3 < iVar9) break;
    if (cVar25 == '\0') {
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xba].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xba) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xbb].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbb) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xbc].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbc) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
    }
    else {
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar8 = (int)((long)iVar9 * 0x30) + 3;
      pixels_04.seg = 0;
      pixels_04.ofs = uVar8;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,pixels_04,iVar19,54,0,
                                (&uStack_c->aptr)->ofs,(char)uVar8,(char)iVar19,0x36);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xba].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xba) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar14 = (int)((long)iVar9 * 0x30) + 3;
      uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
      pixels_05.seg = 0x3e;
      pixels_05.ofs = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_05,iVar19,116,0
                                ,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,(char)uVar14,(char)iVar19,
                                0x74);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xbb].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xbb) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar14 = (int)((long)iVar9 * 0x30) + 3;
      uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
      pixels_06.seg = 0x3e;
      pixels_06.ofs = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_06,iVar19,116,0
                                ,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,(char)uVar14,(char)iVar19,
                                0x74);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xbc].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xbc) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
    }
    uVar14 = 0x195d;
    iVar9 = iVar9 + 1;
  }
  if (cVar25 != '\0') {
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
  }
  iVar9 = 0;
  while( true ) {
    if (3 < iVar9) break;
    if (cVar25 == '\0') {
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xbd].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbd) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xbe].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbe) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xbf].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbf) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
    }
    else {
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar8 = (int)((long)iVar9 * 0x30) + 3;
      pixels_07.seg = 0;
      pixels_07.ofs = uVar8;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,pixels_07,iVar19,54,0,
                                (&uStack_c->aptr)->ofs,(char)uVar8,(char)iVar19,0x36);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xbd].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xbd) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar14 = (int)((long)iVar9 * 0x30) + 3;
      uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
      pixels_08.seg = 0x3e;
      pixels_08.ofs = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_08,iVar19,116,0
                                ,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,(char)uVar14,(char)iVar19,
                                0x74);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xbe].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xbe) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar14 = (int)((long)iVar9 * 0x30) + 3;
      uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
      pixels_09.seg = 0x3e;
      pixels_09.ofs = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_09,iVar19,116,0
                                ,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,(char)uVar14,(char)iVar19,
                                0x74);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xbf].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xbf) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
    }
    uVar14 = 0x195d;
    iVar9 = iVar9 + 1;
  }
  if (cVar25 != '\0') {
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
  }
  iVar9 = 0;
  while( true ) {
    if (3 < iVar9) break;
    if (cVar25 == '\0') {
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xc0].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc0) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xc1].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc1) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xc2].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc2) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
    }
    else {
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar8 = (int)((long)iVar9 * 0x30) + 3;
      pixels_10.seg = 0;
      pixels_10.ofs = uVar8;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,pixels_10,iVar19,54,0,
                                (&uStack_c->aptr)->ofs,(char)uVar8,(char)iVar19,0x36);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xc0].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xc0) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar14 = (int)((long)iVar9 * 0x30) + 3;
      uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
      pixels_11.seg = 0x3e;
      pixels_11.ofs = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_11,iVar19,116,0
                                ,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,(char)uVar14,(char)iVar19,
                                0x74);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xc1].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xc1) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar14 = (int)((long)iVar9 * 0x30) + 3;
      uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
      pixels_12.seg = 0x3e;
      pixels_12.ofs = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_12,iVar19,116,0
                                ,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,(char)uVar14,(char)iVar19,
                                0x74);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xc2].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xc2) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
    }
    uVar14 = 0x195d;
    iVar9 = iVar9 + 1;
  }
  if (cVar25 != '\0') {
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
  }
  iVar9 = 0;
  while( true ) {
    if (3 < iVar9) break;
    if (cVar25 == '\0') {
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xc3].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc3) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xc4].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc4) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xc5].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc5) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
    }
    else {
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar8 = (int)((long)iVar9 * 0x30) + 3;
      pixels_13.seg = 0;
      pixels_13.ofs = uVar8;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,pixels_13,iVar19,54,0,
                                (&uStack_c->aptr)->ofs,(char)uVar8,(char)iVar19,0x36);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xc3].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xc3) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar14 = (int)((long)iVar9 * 0x30) + 3;
      uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
      pixels_14.seg = 0x3e;
      pixels_14.ofs = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_14,iVar19,116,0
                                ,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,(char)uVar14,(char)iVar19,
                                0x74);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xc4].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xc4) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar14 = (int)((long)iVar9 * 0x30) + 3;
      uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
      pixels_15.seg = 0x3e;
      pixels_15.ofs = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_15,iVar19,116,0
                                ,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,(char)uVar14,(char)iVar19,
                                0x74);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xc5].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xc5) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
    }
    uVar14 = 0x195d;
    iVar9 = iVar9 + 1;
  }
  if (cVar25 != '\0') {
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
  }
  iVar9 = 0;
  while( true ) {
    if (3 < iVar9) break;
    if (cVar25 == '\0') {
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xc6].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc6) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[199].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 199) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
      uVar22 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[200].seg + iVar9 * 0x48) = (int)((ulong)uVar22 >> 0x10);
      ((far_t *)(BldGfxNormal + 200) + iVar9 * 0x12)->ofs = (uint16_t)uVar22;
    }
    else {
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar8 = (int)((long)iVar9 * 0x30) + 3;
      pixels_16.seg = 0;
      pixels_16.ofs = uVar8;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,pixels_16,iVar19,54,0,
                                (&uStack_c->aptr)->ofs,(char)uVar8,(char)iVar19,0x36);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[0xc6].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 0xc6) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar14 = (int)((long)iVar9 * 0x30) + 3;
      uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
      pixels_17.seg = 0x3e;
      pixels_17.ofs = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_17,iVar19,116,0
                                ,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,(char)uVar14,(char)iVar19,
                                0x74);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[199].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 199) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
      iVar19 = iVar9 * 0x30 + 0x32;
      uVar15 = (undefined2)((ulong)((long)iVar9 * 0x30) >> 0x10);
      uVar14 = (int)((long)iVar9 * 0x30) + 3;
      uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
      pixels_18.seg = 0x3e;
      pixels_18.ofs = uVar14;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_18,iVar19,116,0
                                ,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,(char)uVar14,(char)iVar19,
                                0x74);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                 pfVar5);
      *(undefined2 *)((int)&BldGfxNormal[200].seg + iVar9 * 0x48) = uVar15;
      ((far_t *)(BldGfxNormal + 200) + iVar9 * 0x12)->ofs = (uint16_t)pcVar6;
    }
    uVar14 = 0x195d;
    iVar9 = iVar9 + 1;
  }
  if (cVar25 != '\0') {
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  for (iStack_4 = 0; iStack_4 < 0x12; iStack_4 = iStack_4 + 1) {
    ovr_stshStubifyFromSrc(iStack_4 + 0x55,iStack_4 + 0x43);
  }
  if (cVar25 != '\0') {
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
  }
  for (iVar9 = 0; iVar9 < 3; iVar9 = iVar9 + 1) {
    for (iStack_4 = 0; iStack_4 < 3; iStack_4 = iStack_4 + 1) {
      if (cVar25 == '\0') {
        uVar22 = func_0x0007ffe0();
        iVar19 = iVar9 * 3 + iStack_4;
        *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar19 * 0xc) = (int)((ulong)uVar22 >> 0x10)
        ;
        ((far_t *)(BldGfxNormal + 0x135) + iVar19 * 3)->ofs = (uint16_t)uVar22;
      }
      else {
        iVar19 = iVar9 * 0x41 + 0x40;
        iVar18 = iStack_4 * 100 + 99;
        lVar1 = (long)iStack_4 * 100;
        uVar15 = (undefined2)((ulong)lVar1 >> 0x10);
        uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
        pixels_19.seg = iVar9 * 0x41;
        pixels_19.ofs = (uint16_t)lVar1;
        pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_19,iVar18,
                                  iVar19,30,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,(char)lVar1,
                                  (char)iVar18,(char)iVar19);
        pcVar6 = ovr_stshStoreFile((uint8_t *)
                                   CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                   pfVar5);
        iVar19 = iVar9 * 3 + iStack_4;
        *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar19 * 0xc) = uVar15;
        ((far_t *)(BldGfxNormal + 0x135) + iVar19 * 3)->ofs = (uint16_t)pcVar6;
      }
      iVar19 = iVar9 * 3 + iStack_4;
      uVar14 = ((far_t *)(BldGfxNormal + 0x135) + iVar19 * 3)->ofs;
      iVar18 = iVar9 * 3 + iStack_4;
      *(undefined2 *)((int)&BldGfxNormal[0x136].seg + iVar18 * 0xc) =
           *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar19 * 0xc);
      ((far_t *)(BldGfxNormal + 0x136) + iVar18 * 3)->ofs = uVar14;
      iVar19 = iVar9 * 3 + iStack_4;
      uVar14 = *(uint16_t *)((int)&BldGfxNormal[0x135].seg + iVar19 * 0xc);
      uVar20 = ((far_t *)(BldGfxNormal + 0x135) + iVar19 * 3)->ofs;
      iVar19 = iVar9 * 3 + iStack_4;
      *(uint16_t *)((int)&BldGfxNormal[0x137].seg + iVar19 * 0xc) = uVar14;
      ((far_t *)(BldGfxNormal + 0x137) + iVar19 * 3)->ofs = uVar20;
    }
  }
  if (cVar25 == '\0') {
    BldGfxNormal[0x151] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0xc00a7)),206,32,-4,
                              (&psVar4->aptr)->ofs,0xa7,0xce,0x20);
    pcVar6 = ovr_stshStoreFile((uint8_t *)
                               CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5
                              );
    BldGfxNormal[0x151].seg = uVar14;
    BldGfxNormal[0x151].ofs = (uint16_t)pcVar6;
  }
  uVar14 = BldGfxNormal[0x151].seg;
  ovr_StubifyCopy1to0_alt();
  if (cVar25 == '\0') {
    BldGfxNormal[0x154] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x2d00a7)),206,65,
                              -4,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0xa7,0xce,0x41);
    pcVar6 = ovr_stshStoreFile((uint8_t *)
                               CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5
                              );
    BldGfxNormal[0x154].seg = uVar14;
    BldGfxNormal[0x154].ofs = (uint16_t)pcVar6;
  }
  uVar14 = BldGfxNormal[0x154].seg;
  ovr_StubifyCopy1to0_alt();
  if (cVar25 == '\0') {
    BldGfxNormal[0x157] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x4e00a7)),206,98,
                              -4,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0xa7,0xce,0x62);
    pcVar6 = ovr_stshStoreFile((uint8_t *)
                               CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5
                              );
    BldGfxNormal[0x157].seg = uVar14;
    BldGfxNormal[0x157].ofs = (uint16_t)pcVar6;
  }
  uVar14 = BldGfxNormal[0x157].seg;
  ovr_StubifyCopy1to0_alt();
  if (cVar25 == '\0') {
    for (iStack_4 = 0; iStack_4 < 6; iStack_4 = iStack_4 + 1) {
      uVar22 = func_0x0007ffe0();
      uVar14 = AnimSeqPtr[1].seg;
      puVar17 = (undefined2 *)(AnimSeqPtr[1].ofs + iStack_4 * 4);
      puVar17[1] = (int)((ulong)uVar22 >> 0x10);
      *puVar17 = (int)uVar22;
      uVar22 = func_0x0007ffe0();
      uVar14 = AnimSeqPtr[2].seg;
      puVar17 = (undefined2 *)(AnimSeqPtr[2].ofs + iStack_4 * 4);
      puVar17[1] = (int)((ulong)uVar22 >> 0x10);
      *puVar17 = (int)uVar22;
    }
    uVar22 = func_0x0007ffe0();
    uVar20 = AnimSeqPtr[1].seg;
    uVar14 = AnimSeqPtr[1].ofs;
    *(undefined2 *)(uVar14 + 0x1a) = (int)((ulong)uVar22 >> 0x10);
    *(undefined2 *)(uVar14 + 0x18) = (int)uVar22;
    uVar22 = func_0x0007ffe0();
    uVar14 = (uint16_t)((ulong)uVar22 >> 0x10);
    uVar21 = AnimSeqPtr[2].seg;
    uVar20 = AnimSeqPtr[2].ofs;
    *(uint16_t *)(uVar20 + 0x1a) = uVar14;
    *(undefined2 *)(uVar20 + 0x18) = (int)uVar22;
  }
  else {
    iStack_4 = 0;
    while( true ) {
      psVar4 = (stg_tmp_t *)_uStack_c;
      uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
      if (5 < iStack_4) break;
      iVar9 = iStack_4 * 0x21 + 0x20;
      uVar16 = (undefined2)((ulong)((long)iStack_4 * 0x21) >> 0x10);
      pixels_20.seg = (int)((long)iStack_4 * 0x21) + 0x14;
      pixels_20.ofs = 0xd;
      pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,pixels_20,16,iVar9,-22,
                                (&psVar4->aptr)->ofs,0xd,0x10,(char)iVar9);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar16)),
                                 pfVar5);
      uVar14 = AnimSeqPtr[1].seg;
      puVar17 = (undefined2 *)(AnimSeqPtr[1].ofs + iStack_4 * 4);
      puVar17[1] = uVar16;
      *puVar17 = pcVar6;
      iVar9 = iStack_4 * 0x21 + 0x20;
      uVar14 = (uint16_t)((ulong)((long)iStack_4 * 0x21) >> 0x10);
      uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
      pixels_21.seg = (int)((long)iStack_4 * 0x21) + 0x14;
      pixels_21.ofs = 0x5f;
      pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_21,98,iVar9,-22
                                ,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x5f,0x62,(char)iVar9);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),
                                 pfVar5);
      uVar20 = AnimSeqPtr[2].seg;
      puVar17 = (undefined2 *)(AnimSeqPtr[2].ofs + iStack_4 * 4);
      puVar17[1] = uVar14;
      *puVar17 = pcVar6;
      iStack_4 = iStack_4 + 1;
    }
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x14002b)),46,32,-22,
                              (&psVar4->aptr)->ofs,0x2b,0x2e,0x20);
    pcVar6 = ovr_stshStoreFile((uint8_t *)
                               CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5
                              );
    uVar21 = AnimSeqPtr[1].seg;
    uVar20 = AnimSeqPtr[1].ofs;
    *(uint16_t *)(uVar20 + 0x1a) = uVar14;
    *(undefined2 *)(uVar20 + 0x18) = pcVar6;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x14007d)),128,32,
                              -22,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x7d,0x80,0x20);
    pcVar6 = ovr_stshStoreFile((uint8_t *)
                               CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5
                              );
    uVar21 = AnimSeqPtr[2].seg;
    uVar20 = AnimSeqPtr[2].ofs;
    *(uint16_t *)(uVar20 + 0x1a) = uVar14;
    *(undefined2 *)(uVar20 + 0x18) = pcVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  builtin_memcpy(&ram0x0000d528 + 0x153,"\x02\x02\x02\x03\x03\x03",6);
  if (cVar25 == '\0') {
    BldGfxNormal[0x15a] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x15d] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x160] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x15a] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x15d] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x160] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar14 = 0x195d;
  }
  else {
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x560002)),85,180,-2,
                              (&uStack_c->aptr)->ofs,2,0x55,0xb4);
    BldGfxNormal[0x15a].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x15a].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x56006c)),191,180,-2,
                              (&uStack_c->aptr)->ofs,0x6c,0xbf,0xb4);
    BldGfxNormal[0x15d].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxNormal[0x15d].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x5600d0)),298,180,0,
                              (&uStack_c->aptr)->ofs,0xd0,0x2a,0xb4);
    BldGfxNormal[0x160].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x160].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar20,psVar4);
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x560002)),85,180,-2,
                              (&psVar4->aptr)->ofs,2,0x55,0xb4);
    BldGfxRuin[0x15a].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxRuin[0x15a].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x56006c)),191,180,
                              -2,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x6c,0xbf,0xb4);
    BldGfxRuin[0x15d].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxRuin[0x15d].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x5600d0)),298,180,
                              0,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0xd0,0x2a,0xb4);
    BldGfxRuin[0x160].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[0x160].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  ovr_stshStubifyCopy1to0();
  if (cVar25 == '\0') {
    BldGfxNormal[0x163] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x166] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x169] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x163] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x166] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x169] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar14 = 0x195d;
  }
  else {
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4a0004)),91,180,-3,
                              (&uStack_c->aptr)->ofs,4,0x5b,0xb4);
    BldGfxNormal[0x163].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x163].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4a006e)),195,180,-3,
                              (&uStack_c->aptr)->ofs,0x6e,0xc3,0xb4);
    BldGfxNormal[0x166].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxNormal[0x166].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4a00cc)),299,180,3,
                              (&uStack_c->aptr)->ofs,0xcc,0x2b,0xb4);
    BldGfxNormal[0x169].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x169].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar20,psVar4);
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x4a0004)),91,180,-3,
                              (&psVar4->aptr)->ofs,4,0x5b,0xb4);
    BldGfxRuin[0x163].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxRuin[0x163].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x4a006e)),195,180,
                              -3,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x6e,0xc3,0xb4);
    BldGfxRuin[0x166].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxRuin[0x166].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x4a00cc)),299,180,
                              3,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0xcc,0x2b,0xb4);
    BldGfxRuin[0x169].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[0x169].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  ovr_stshStubifyCopy1to0();
  ovr_stubyBufSrcToDst(0x79,0x76);
  ovr_stubyBufSrcToDst(0x7c,0x73);
  ovr_stubyBufSrcToDst(0x7f,0x76);
  if (cVar25 == '\0') {
    BldGfxNormal[0x186] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x187] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x188] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x186] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x187] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x188] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar14 = 0x195d;
  }
  else {
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x460002)),86,180,0,
                              (&uStack_c->aptr)->ofs,2,0x56,0xb4);
    BldGfxNormal[0x186].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x186].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x46006c)),191,180,0,
                              (&uStack_c->aptr)->ofs,0x6c,0xbf,0xb4);
    BldGfxNormal[0x187].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxNormal[0x187].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4600d7)),298,180,0,
                              (&uStack_c->aptr)->ofs,0xd7,0x2a,0xb4);
    BldGfxNormal[0x188].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x188].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar20,psVar4);
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x460002)),86,180,0,
                              (&psVar4->aptr)->ofs,2,0x56,0xb4);
    BldGfxRuin[0x186].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxRuin[0x186].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x46006c)),191,180,
                              0,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x6c,0xbf,0xb4);
    BldGfxRuin[0x187].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxRuin[0x187].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x4600d7)),298,180,
                              0,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0xd7,0x2a,0xb4);
    BldGfxRuin[0x188].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[0x188].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  uVar15 = 0x234c;
  iVar9 = 0x83;
  if (cVar25 == '\0') {
    uVar22 = func_0x0007ffe0();
    unaff_SI = (undefined2)uVar22;
    uVar8 = 0x83;
    iVar18 = 0xc;
    typeIndex = (byte)((ulong)uVar22 >> 0x10);
    uVar28 = (undefined1)((ulong)uVar22 >> 0x18);
    fVar2 = BldGfxNormal[100];
code_r0x00074dd0:
    uVar8 = uVar8 * iVar18;
    goto code_r0x00074dd2;
  }
  uStack_c = ovr_grabLbmTR();
  puStack_a = (uint8_t *)uVar14;
  pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x460002)),86,180,0,
                            (&uStack_c->aptr)->ofs,2,0x56,0xb4);
  BldGfxNormal[0x189].ofs =
       (uint16_t)
       ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),
                         pfVar5);
  uVar20 = 0x195d;
  BldGfxNormal[0x189].seg = uVar14;
  pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x46006c)),191,180,0,
                            (&uStack_c->aptr)->ofs,0x6c,0xbf,0xb4);
  BldGfxNormal[0x18a].ofs =
       (uint16_t)
       ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),
                         pfVar5);
  uVar14 = 0x195d;
  BldGfxNormal[0x18a].seg = uVar20;
  pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4600d7)),298,180,0,
                            (&uStack_c->aptr)->ofs,0xd7,0x2a,0xb4);
  BldGfxNormal[0x18b].ofs =
       (uint16_t)
       ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),
                         pfVar5);
  uVar20 = 0x195d;
  BldGfxNormal[0x18b].seg = uVar14;
  ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                 uStack_c);
  psVar4 = ovr_grabLbmTR();
  _uStack_c = (stg_tmp_t *)CONCAT22(uVar20,psVar4);
  pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x460002)),86,180,0,
                            (&psVar4->aptr)->ofs,2,0x56,0xb4);
  BldGfxRuin[0x189].ofs =
       (uint16_t)
       ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),
                         pfVar5);
  uVar14 = 0x195d;
  uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
  BldGfxRuin[0x189].seg = uVar20;
  pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x46006c)),191,180,0,
                            (&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x6c,0xbf,0xb4);
  BldGfxRuin[0x18a].ofs =
       (uint16_t)
       ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),
                         pfVar5);
  uVar20 = 0x195d;
  uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
  BldGfxRuin[0x18a].seg = uVar14;
  pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x4600d7)),298,180,0,
                            (&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0xd7,0x2a,0xb4);
  BldGfxRuin[0x18b].ofs =
       (uint16_t)
       ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20)),
                         pfVar5);
  uVar14 = 0x195d;
  BldGfxRuin[0x18b].seg = uVar20;
  ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                 uStack_c);
L_init_assets_4EA5:
  if (cVar25 == '\0') {
    BldGfxNormal[0x18d] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x18d] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x46006c)),191,180,0,
                              (&uStack_c->aptr)->ofs,0x6c,0xbf,0xb4);
    BldGfxNormal[0x18d].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x18d].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar20,psVar4);
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x46006c)),191,180,0,
                              (&psVar4->aptr)->ofs,0x6c,0xbf,0xb4);
    BldGfxRuin[0x18d].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    BldGfxRuin[0x18d].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  BldGfxNormal[0x18c].seg = BldGfxNormal[0x18d].seg;
  BldGfxNormal[0x18c].ofs = BldGfxNormal[0x18d].ofs;
  BldGfxNormal[0x18e].seg = BldGfxNormal[0x18d].seg;
  BldGfxNormal[0x18e].ofs = BldGfxNormal[0x18d].ofs;
  BldGfxRuin[0x18c].seg = BldGfxRuin[0x18d].seg;
  BldGfxRuin[0x18c].ofs = BldGfxRuin[0x18d].ofs;
  BldGfxRuin[0x18e].seg = BldGfxRuin[0x18d].seg;
  BldGfxRuin[0x18e].ofs = BldGfxRuin[0x18d].ofs;
  if (cVar25 == '\0') {
    BldGfxNormal[399] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[400] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x191] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[399] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[400] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x191] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x193] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x193] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar14 = BldGfxRuin[0x18d].seg;
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x460002)),86,180,0,
                              (&uStack_c->aptr)->ofs,2,0x56,0xb4);
    BldGfxNormal[399].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[399].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x46006c)),191,180,0,
                              (&uStack_c->aptr)->ofs,0x6c,0xbf,0xb4);
    BldGfxNormal[400].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxNormal[400].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4600d7)),298,180,0,
                              (&uStack_c->aptr)->ofs,0xd7,0x2a,0xb4);
    BldGfxNormal[0x191].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x191].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x460002)),86,180,0,
                              (&uStack_c->aptr)->ofs,2,0x56,0xb4);
    BldGfxRuin[399].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[399].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x46006c)),191,180,0,
                              (&uStack_c->aptr)->ofs,0x6c,0xbf,0xb4);
    BldGfxRuin[400].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxRuin[400].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x4600d7)),298,180,0,
                              (&uStack_c->aptr)->ofs,0xd7,0x2a,0xb4);
    BldGfxRuin[0x191].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[0x191].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x46006c)),191,180,0,
                              (&uStack_c->aptr)->ofs,0x6c,0xbf,0xb4);
    BldGfxNormal[0x193].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x193].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar20,psVar4);
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x46006c)),191,180,0,
                              (&psVar4->aptr)->ofs,0x6c,0xbf,0xb4);
    BldGfxRuin[0x193].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    BldGfxRuin[0x193].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  BldGfxNormal[0x192].seg = BldGfxNormal[0x193].seg;
  BldGfxNormal[0x192].ofs = BldGfxNormal[0x193].ofs;
  BldGfxNormal[0x194].seg = BldGfxNormal[0x193].seg;
  BldGfxNormal[0x194].ofs = BldGfxNormal[0x193].ofs;
  BldGfxRuin[0x192].seg = BldGfxRuin[0x193].seg;
  BldGfxRuin[0x192].ofs = BldGfxRuin[0x193].ofs;
  BldGfxRuin[0x194].seg = BldGfxRuin[0x193].seg;
  BldGfxRuin[0x194].ofs = BldGfxRuin[0x193].ofs;
  if (cVar25 == '\0') {
    BldGfxNormal[0x196] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x196] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar14 = BldGfxRuin[0x193].seg;
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x46006c)),191,180,0,
                              (&uStack_c->aptr)->ofs,0x6c,0xbf,0xb4);
    BldGfxNormal[0x196].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x196].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar20,psVar4);
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x46006c)),191,180,0,
                              (&psVar4->aptr)->ofs,0x6c,0xbf,0xb4);
    BldGfxRuin[0x196].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    BldGfxRuin[0x196].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  BldGfxNormal[0x195].seg = BldGfxNormal[0x196].seg;
  BldGfxNormal[0x195].ofs = BldGfxNormal[0x196].ofs;
  BldGfxNormal[0x197].seg = BldGfxNormal[0x196].seg;
  BldGfxNormal[0x197].ofs = BldGfxNormal[0x196].ofs;
  BldGfxRuin[0x195].seg = BldGfxRuin[0x196].seg;
  BldGfxRuin[0x195].ofs = BldGfxRuin[0x196].ofs;
  BldGfxRuin[0x197].seg = BldGfxRuin[0x196].seg;
  BldGfxRuin[0x197].ofs = BldGfxRuin[0x196].ofs;
  if (cVar25 == '\0') {
    for (iStack_4 = 0; iStack_4 < 5; iStack_4 = iStack_4 + 1) {
      uVar22 = func_0x0007ffe0();
      uVar14 = AnimSeqPtr[0].seg;
      puVar17 = (undefined2 *)(AnimSeqPtr[0].ofs + iStack_4 * 4);
      puVar17[1] = (int)((ulong)uVar22 >> 0x10);
      *puVar17 = (int)uVar22;
    }
    BldGfxNormal[0x199] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x199] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar14 = 0x195d;
  }
  else {
    uVar14 = BldGfxRuin[0x196].seg;
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    for (iStack_4 = 0; iStack_4 < 5; iStack_4 = iStack_4 + 1) {
      iVar9 = iStack_4 * 0x22 + 0x68;
      uVar14 = (uint16_t)((ulong)((long)iStack_4 * 0x22) >> 0x10);
      uVar20 = (int)((long)iStack_4 * 0x22) + 0x50;
      pixels_22.seg = 0x27;
      pixels_22.ofs = uVar20;
      pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,pixels_22,iVar9,58,-68,
                                (&uStack_c->aptr)->ofs,(char)uVar20,(char)iVar9,0x3a);
      pcVar6 = ovr_stshStoreFile((uint8_t *)
                                 CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),
                                 pfVar5);
      uVar20 = AnimSeqPtr[0].seg;
      puVar17 = (undefined2 *)(AnimSeqPtr[0].ofs + iStack_4 * 4);
      puVar17[1] = uVar14;
      *puVar17 = pcVar6;
    }
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x570052)),222,181,22,
                              (&uStack_c->aptr)->ofs,0x52,0xde,0xb5);
    BldGfxNormal[0x199].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x199].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar20,psVar4);
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x570052)),222,181,22,
                              (&psVar4->aptr)->ofs,0x52,0xde,0xb5);
    BldGfxRuin[0x199].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[0x199].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  ovr_StubifyCopy1to0_alt();
  BldFlags[0x198] = 0x1;
  BldFlags[0x199] = 0x1;
  BldFlags[0x19a] = 0x1;
  if (cVar25 == '\0') {
    BldGfxNormal[0x19c] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x19f] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x19c] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x19f] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1a2] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x1a2] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar14 = 0x195d;
  }
  else {
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x650000)),319,199,60,
                              (&uStack_c->aptr)->ofs,0,0x3f,199);
    BldGfxNormal[0x19c].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x19c].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x0)),319,100,60,
                              (&uStack_c->aptr)->ofs,0,0x3f,100);
    BldGfxNormal[0x19f].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxNormal[0x19f].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x650000)),319,199,60,
                              (&uStack_c->aptr)->ofs,0,0x3f,199);
    BldGfxRuin[0x19c].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxRuin[0x19c].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x0)),319,100,60,
                              (&uStack_c->aptr)->ofs,0,0x3f,100);
    BldGfxRuin[0x19f].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[0x19f].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x460000)),319,193,60,
                              (&uStack_c->aptr)->ofs,0,0x3f,0xc1);
    BldGfxNormal[0x1a2].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x1a2].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar20,psVar4);
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x460000)),319,193,60,
                              (&psVar4->aptr)->ofs,0,0x3f,0xc1);
    BldGfxRuin[0x1a2].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[0x1a2].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  ovr_stshStubifyCopy1to0();
  ovr_stubyBufSrcToDst(0x8c,0x73);
  if (cVar25 == '\0') {
    BldGfxNormal[0x1ae] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1b1] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1b4] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x1ae] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x1b1] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x1b4] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    uVar14 = 0x195d;
  }
  else {
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x320008)),110,154,-4,
                              (&uStack_c->aptr)->ofs,8,0x6e,0x9a);
    BldGfxNormal[0x1ae].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x1ae].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x32006f)),212,154,-4,
                              (&uStack_c->aptr)->ofs,0x6f,0xd4,0x9a);
    BldGfxNormal[0x1b1].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxNormal[0x1b1].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x3200d5)),313,154,-4,
                              (&uStack_c->aptr)->ofs,0xd5,0x39,0x9a);
    BldGfxNormal[0x1b4].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x1b4].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar20,psVar4);
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x320008)),110,154,-4,
                              (&psVar4->aptr)->ofs,8,0x6e,0x9a);
    BldGfxRuin[0x1ae].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxRuin[0x1ae].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x32006f)),212,154,
                              -4,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x6f,0xd4,0x9a);
    BldGfxRuin[0x1b1].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxRuin[0x1b1].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x3200d5)),313,154,
                              -4,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0xd5,0x39,0x9a);
    BldGfxRuin[0x1b4].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxRuin[0x1b4].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  ovr_stshStubifyCopy1to0();
  iVar9 = 0x92;
  if (cVar25 != '\0') {
    psVar4 = ovr_grabLbm(0,0x11);
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    pixels_24.seg = 0xff;
    pixels_24.ofs = (psVar4->aptr).seg;
    ovr_grabRemap(pixels_24,0x0,(uint8_t)(&psVar4->aptr)->ofs);
  }
  for (iVar19 = 0; iVar19 < 3; iVar19 = iVar19 + 1) {
    for (iStack_4 = 0; iStack_4 < 2; iStack_4 = iStack_4 + 1) {
      if ((iStack_4 != 0) || (iVar19 != 0)) {
        if (cVar25 == '\0') {
          uVar22 = func_0x0007ffe0();
          *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar9 * 0xc) = (int)((ulong)uVar22 >> 0x10);
          ((far_t *)BldGfxNormal + iVar9 * 3)->ofs = (uint16_t)uVar22;
        }
        else {
          iVar18 = iVar19 * 0x41 + 0x40;
          sx = iStack_4 * 0x87 + 0x86;
          lVar1 = (long)iStack_4 * 0x87;
          uVar15 = (undefined2)((ulong)lVar1 >> 0x10);
          uVar16 = (undefined2)((ulong)_uStack_c >> 0x10);
          pixels_23.seg = iVar19 * 0x41;
          pixels_23.ofs = (uint16_t)lVar1;
          pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,pixels_23,sx,
                                    iVar18,30,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,(char)lVar1,
                                    (char)sx,(char)iVar18);
          pcVar6 = ovr_stshStoreFile((uint8_t *)
                                     CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar15)),
                                     pfVar5);
          *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar9 * 0xc) = uVar15;
          ((far_t *)BldGfxNormal + iVar9 * 3)->ofs = (uint16_t)pcVar6;
        }
        uVar14 = ((far_t *)BldGfxNormal + iVar9 * 3)->ofs;
        *(undefined2 *)((int)&BldGfxNormal[1].seg + iVar9 * 0xc) =
             *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar9 * 0xc);
        ((far_t *)(BldGfxNormal + 1) + iVar9 * 3)->ofs = uVar14;
        uVar14 = *(uint16_t *)((int)&BldGfxNormal[0].seg + iVar9 * 0xc);
        uVar20 = ((far_t *)BldGfxNormal + iVar9 * 3)->ofs;
        *(uint16_t *)((int)&BldGfxNormal[2].seg + iVar9 * 0xc) = uVar14;
        ((far_t *)(BldGfxNormal + 2) + iVar9 * 3)->ofs = uVar20;
        iVar9 = iVar9 + 1;
      }
    }
  }
  if (cVar25 == '\0') {
    BldGfxNormal[0x1c5] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1c6] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1c7] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    pfVar5 = ovr_stshRleCut((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x120000)),200,
                            (char)(&psVar4->aptr)->ofs,0,0x12);
    BldGfxNormal[0x1c5].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x1c5].seg = uVar14;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x4a0083)),179,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x83,0x4a);
    BldGfxNormal[0x1c6].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x1c6].seg = uVar20;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x31001f)),79,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x1f,0x31);
    pcVar6 = ovr_stshStoreFile((uint8_t *)
                               CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5
                              );
    BldGfxNormal[0x1c7].seg = uVar14;
    BldGfxNormal[0x1c7].ofs = (uint16_t)pcVar6;
  }
  BldGfxNormal[0x1ca] = BldGfxNormal[0x1c7];
  BldGfxNormal[0x1c8] = BldGfxNormal[0x1c5];
  BldGfxNormal[0x1c9] = BldGfxNormal[0x1c6];
  BldGfxNormal[0x1cd] = BldGfxNormal[0x1c7];
  BldGfxNormal[0x1cb] = BldGfxNormal[0x1c5];
  BldGfxNormal[0x1cc] = BldGfxNormal[0x1c6];
  if (cVar25 == '\0') {
    BldGfxNormal[0x1ce] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1cf] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1d0] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    uVar14 = BldGfxNormal[0x1c7].ofs;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x310000)),200,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0,0x31);
    BldGfxNormal[0x1ce].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x1ce].seg = uVar14;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x4a001f)),79,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x1f,0x4a);
    BldGfxNormal[0x1cf].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x1cf].seg = uVar20;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x310083)),179,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x83,0x31);
    pcVar6 = ovr_stshStoreFile((uint8_t *)
                               CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5
                              );
    BldGfxNormal[0x1d0].seg = uVar14;
    BldGfxNormal[0x1d0].ofs = (uint16_t)pcVar6;
  }
  BldGfxNormal[0x1d3] = BldGfxNormal[0x1d0];
  BldGfxNormal[0x1d1] = BldGfxNormal[0x1ce];
  BldGfxNormal[0x1d2] = BldGfxNormal[0x1cf];
  BldGfxNormal[0x1d6] = BldGfxNormal[0x1d0];
  BldGfxNormal[0x1d4] = BldGfxNormal[0x1ce];
  BldGfxNormal[0x1d5] = BldGfxNormal[0x1cf];
  if (cVar25 == '\0') {
    BldGfxNormal[0x1d7] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    uVar14 = BldGfxNormal[0x1d0].ofs;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x10000)),200,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0,1);
    pcVar6 = ovr_stshStoreFile((uint8_t *)
                               CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5
                              );
    BldGfxNormal[0x1d7].seg = uVar14;
    BldGfxNormal[0x1d7].ofs = (uint16_t)pcVar6;
  }
  BldGfxNormal[0x1d8].seg = BldGfxNormal[0x1d2].seg;
  BldGfxNormal[0x1d8].ofs = BldGfxNormal[0x1d2].ofs;
  if (cVar25 == '\0') {
    BldGfxNormal[0x1d9] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    uVar14 = BldGfxNormal[0x1d2].seg;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x3100e7)),279,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0xe7,0x31);
    pcVar6 = ovr_stshStoreFile((uint8_t *)
                               CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14)),pfVar5
                              );
    BldGfxNormal[0x1d9].seg = uVar14;
    BldGfxNormal[0x1d9].ofs = (uint16_t)pcVar6;
  }
  BldGfxNormal[0x1db].seg = BldGfxNormal[0x1d8].seg;
  BldGfxNormal[0x1db].ofs = BldGfxNormal[0x1d8].ofs;
  BldGfxNormal[0x1de].seg = BldGfxNormal[0x1d8].seg;
  BldGfxNormal[0x1de].ofs = BldGfxNormal[0x1d8].ofs;
  BldGfxNormal[0x1dc] = BldGfxNormal[0x1d9];
  BldGfxNormal[0x1da] = BldGfxNormal[0x1d7];
  BldGfxNormal[0x1df] = BldGfxNormal[0x1d9];
  BldGfxNormal[0x1dd] = BldGfxNormal[0x1d7];
  if (cVar25 == '\0') {
    BldGfxNormal[0x1e0] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1e1] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1e2] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar14 = BldGfxNormal[0x1d9].ofs;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    pfVar5 = ovr_stshRleCut((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x310083)),219,
                            (char)(&psVar4->aptr)->ofs,0x83,0x31);
    BldGfxNormal[0x1e0].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x1e0].seg = uVar14;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x4a0083)),179,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x83,0x4a);
    BldGfxNormal[0x1e1].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x1e1].seg = uVar20;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x3b0083)),179,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x83,0x3b);
    BldGfxNormal[0x1e2].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    BldGfxNormal[0x1e2].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  BldGfxNormal[0x1e3].seg = BldGfxNormal[0x1e0].seg;
  BldGfxNormal[0x1e3].ofs = BldGfxNormal[0x1e0].ofs;
  BldGfxNormal[0x1e4].seg = BldGfxNormal[0x1e1].seg;
  BldGfxNormal[0x1e4].ofs = BldGfxNormal[0x1e1].ofs;
  BldGfxNormal[0x1e5].seg = BldGfxNormal[0x1e2].seg;
  BldGfxNormal[0x1e5].ofs = BldGfxNormal[0x1e2].ofs;
  if (cVar25 == '\0') {
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
    uVar14 = BldGfxNormal[0x1e2].seg;
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar14,psVar4);
    pfVar5 = ovr_stshRleCut((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x330000)),200,
                            (char)(&psVar4->aptr)->ofs,0,0x33);
    BldGfxNormal[0x1e6].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x1e6].seg = uVar14;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x4a001f)),79,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x1f,0x4a);
    BldGfxNormal[0x1e7].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x1e7].seg = uVar20;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x330000)),48,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0,0x33);
    BldGfxNormal[0x1e8].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x1e8].seg = uVar14;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0xe0000)),200,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0,0xe);
    BldGfxNormal[0x1ec].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x1ec].seg = uVar20;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x4a0083)),179,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x83,0x4a);
    BldGfxNormal[0x1ed].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x1ed].seg = uVar14;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0xe0000)),48,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0,0xe);
    BldGfxNormal[0x1ee].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x1ee].seg = uVar20;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0xa80000)),200,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0,0xa8);
    BldGfxNormal[0x1f2].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[0x1f2].seg = uVar14;
    pfVar5 = ovr_stshRleCut((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x4a00e7)),279,
                            (char)(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0xe7,0x4a);
    BldGfxNormal[499].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxNormal[499].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0xa80000)),48,187,0
                              ,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0,0x30,0xbb);
    BldGfxNormal[500].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    BldGfxNormal[500].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  BldGfxNormal[0x1ef].seg = BldGfxNormal[0x1ec].seg;
  BldGfxNormal[0x1ef].ofs = BldGfxNormal[0x1ec].ofs;
  BldGfxNormal[0x1f0].seg = BldGfxNormal[0x1ed].seg;
  BldGfxNormal[0x1f0].ofs = BldGfxNormal[0x1ed].ofs;
  BldGfxNormal[0x1f1].seg = BldGfxNormal[0x1ee].seg;
  BldGfxNormal[0x1f1].ofs = BldGfxNormal[0x1ee].ofs;
  BldGfxNormal[0x1f5].seg = BldGfxNormal[0x1ec].seg;
  BldGfxNormal[0x1f5].ofs = BldGfxNormal[0x1ec].ofs;
  BldGfxNormal[0x1f6].seg = BldGfxNormal[0x1ed].seg;
  BldGfxNormal[0x1f6].ofs = BldGfxNormal[0x1ed].ofs;
  BldGfxNormal[0x1f7].seg = BldGfxNormal[0x1ee].seg;
  BldGfxNormal[0x1f7].ofs = BldGfxNormal[0x1ee].ofs;
  BldGfxNormal[0x1e9] = BldGfxNormal[0x1e6];
  BldGfxNormal[0x1ea] = BldGfxNormal[0x1e7];
  BldGfxNormal[0x1eb] = BldGfxNormal[0x1e8];
  if (cVar25 == '\0') {
    BldGfxNormal[0x1f9] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1fc] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxNormal[0x1ff] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x1f9] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x1fc] = far_from_u32((uint32_t)(func_0x0007ffe0()));
    BldGfxRuin[0x1ff] = far_from_u32((uint32_t)(func_0x0007ffe0()));
  }
  else {
    uVar14 = BldGfxNormal[0x1ee].seg;
    uStack_c = ovr_grabLbmTR();
    puStack_a = (uint8_t *)uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x1c000d)),96,119,0,
                              (&uStack_c->aptr)->ofs,0xd,0x60,0x77);
    BldGfxNormal[0x1f9].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x1f9].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x1c0077)),202,119,0,
                              (&uStack_c->aptr)->ofs,0x77,0xca,0x77);
    BldGfxNormal[0x1fc].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    BldGfxNormal[0x1fc].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(uStack_c->aptr).seg,far_from_u32((uint32_t)(0x1c00e2)),309,119,0,
                              (&uStack_c->aptr)->ofs,0xe2,0x35,0x77);
    BldGfxNormal[0x1ff].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    BldGfxNormal[0x1ff].seg = uVar14;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
    psVar4 = ovr_grabLbmTR();
    _uStack_c = (stg_tmp_t *)CONCAT22(uVar20,psVar4);
    pfVar5 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x1c000d)),96,119,0,
                              (&psVar4->aptr)->ofs,0xd,0x60,0x77);
    BldGfxRuin[0x1f9].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    uVar14 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxRuin[0x1f9].seg = uVar20;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x1c0077)),202,119,
                              0,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0x77,0xca,0x77);
    BldGfxRuin[0x1fc].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar14))
                           ,pfVar5);
    uVar20 = 0x195d;
    uVar15 = (undefined2)((ulong)_uStack_c >> 0x10);
    BldGfxRuin[0x1fc].seg = uVar14;
    pfVar5 = ovr_stshRleType2((far_t *)(((stg_tmp_t *)_uStack_c)->aptr).seg,far_from_u32((uint32_t)(0x1c00e2)),309,119,
                              0,(&((stg_tmp_t *)_uStack_c)->aptr)->ofs,0xe2,0x35,0x77);
    BldGfxRuin[0x1ff].ofs =
         (uint16_t)
         ovr_stshStoreFile((uint8_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,uVar20))
                           ,pfVar5);
    BldGfxRuin[0x1ff].seg = uVar20;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(in_stack_0000fc0f,CONCAT12(in_stack_0000fc0e,puStack_a)),
                   uStack_c);
  }
  ovr_stshStubifyCopy1to0();
  ovr_init_assets1();
  param_1 = param_1 & 0xff;
  ovr_init_assets2();
  if (cVar25 != '\0') {
    plVar7 = LXMUL_at_(in_stack_0000fc10,in_stack_0000fc12,in_stack_0000fc16);
    buf.seg = (uint16_t)plVar7;
    buf.ofs = StshCtPtr.seg;
    ovr_stshWriteFile(StshCtPtr.ofs,buf,StshFile,(char)StshCtPtr.seg);
    lseek(StshFile,0,CONCAT11(in_stack_0000fc0f,in_stack_0000fc0e));
    write(StshFile,&StshCtOfs,4);
    close(StshFile);
    param_1 = 0x2410;
    if (StshCount != 0xd93) {
      printf("getcache %d  SIZESTASH %d  \r");
      param_1 = ovr_biosReadKey();
    }
  }
  stshInitPtrs();
  return param_1;
}



/* 77eb:16b2 */

/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc45_usesRandBelow(int entityIndex)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar5;
  uint16_t uVar4;
  uint16_t unaff_SI;
  undefined2 uVar6;
  
  uVar6 = (undefined2)((ulong)Entities >> 0x10);
  if (*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3) == -1) {
    uVar3 = entityIndex * 0x37 & 0xff00;
  }
  else {
    uVar2 = *(undefined4 *)
             ((uint)*(byte *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3) << 2);
    cVar1 = *(char *)((int)uVar2 + 0x2f);
    if (cVar1 == '\x04') {
      uVar4 = ovr_randBelow(unaff_SI,5);
      bVar5 = (byte)(uVar4 >> 8);
      if ((byte)uVar4 < 4) {
        uVar3 = CONCAT11(bVar5,1);
      }
      else {
        uVar3 = (uint)bVar5 << 8;
      }
    }
    else if (cVar1 == '\x05') {
      uVar4 = ovr_randBelow(unaff_SI,3);
      bVar5 = (byte)(uVar4 >> 8);
      if ((char)uVar4 == '\0') {
        uVar3 = CONCAT11(bVar5,1);
      }
      else {
        uVar3 = (uint)bVar5 << 8;
      }
    }
    else {
      uVar4 = ovr_randBelow(unaff_SI,4);
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

/* [R2] string "Done" */

void __cdecl16far
ovc45_textDone(char foundFlag,byte bldType,int entityIndex,uint16_t x,uint16_t outFlag,
              uint16_t outFlagSeg,...)

{
  far_t entries;
  far_t entries_00;
  far_t hint;
  far_t hint_00;
  int iVar1;
  char cVar2;
  char *pcVar3;
  undefined2 *puVar4;
  int iVar5;
  uint8_t *puVar6;
  uint uVar7;
  uint16_t uVar8;
  undefined2 uVar9;
  char *pcVar10;
  undefined2 uVar11;
  int iVar12;
  undefined2 unaff_DI;
  char *unaff_SS;
  char in_stack_00000004;
  byte partyIndex;
  undefined1 uVar13;
  uint8_t menuItems;
  undefined2 auStack_28e [19];
  uint8_t msg;
  uint8_t text;
  char cStack_17;
  char cStack_16;
  char cStack_15;
  uint8_t menuLabel;
  undefined2 uStack_12;
  undefined2 uStack_10;
  char cStack_e;
  char acStack_d [11];
  
  iVar1 = entityIndex;
  partyIndex = (byte)unaff_DI;
  uVar13 = (undefined1)((uint)unaff_DI >> 8);
  auStack_28e[0] = 0x2410;
  _menuItems = 0x7706;
  acStack_d[1] = 1;
  if (*(int *)((uint)(byte)foundFlag * 0x27 + 0x116) == 0 &&
      *(int *)((uint)(byte)foundFlag * 0x27 + 0x118) == 0) {
    auStack_28e[2] = 0x2410;
    auStack_28e[1] = 0x770f;
  }
  else {
    auStack_28e[2] = *(undefined2 *)((uint)(byte)foundFlag * 0x27 + 0x118);
    auStack_28e[1] = *(undefined2 *)((uint)(byte)foundFlag * 0x27 + 0x116);
  }
  acStack_d[2] = 2;
  iVar12 = 2;
  if (in_stack_00000004 != '\0') {
    auStack_28e[4] = 0x2410;
    auStack_28e[3] = 0x7716;
    acStack_d[3] = 3;
    iVar12 = 3;
  }
  auStack_28e[iVar12 * 2] = (char *)"puppetmaker" + 3;
  *(char **)(&menuItems + iVar12 * 4) = (char *)"Done";
  acStack_d[iVar12 + 1] = '\x04';
  cStack_16 = '\0';
  do {
    uVar9 = 0x2410;
    pcVar3 = ovr_ovc22_className(partyIndex,
                                 CONCAT11((char)((uint)(_bldType * 0x37) >> 8),
                                          *(undefined1 *)
                                           ((int)&((entity_t *)Entities)[_bldType].base.entity + 3))
                                );
    puVar4 = (undefined2 *)
             ((uint)*(byte *)((int)&((entity_t *)Entities)[_bldType].base.entity + 3) * 4);
    iVar5 = ovc45_compute9((char *)CONCAT22(*puVar4,unaff_SS),
                           (char *)CONCAT22(Font03.ofs,(char *)puVar4[1]),
                           (char *)CONCAT22(0x55,Font03.seg),3,(char)pcVar3,&text,(char)Font03.seg,
                           (char)pcVar3,uVar9);
    pcVar10 = (char *)&AgntAnms[0x88].missileDy;
    puVar6 = ovr_ovc15_usesStshRealloc();
    pcVar3 = ovr_fmVsprintf((char *)CONCAT22(puVar6,(char *)"puppetmaker" + 3),
                            (char *)CONCAT22(iVar5,pcVar10));
    strcpy((char *)CONCAT22(unaff_SS,&msg),(char *)CONCAT22(pcVar10,pcVar3));
    goldPartyIndex = *(undefined1 *)((int)&((entity_t *)Entities)[_bldType].base.entity + 3);
    puVar6 = &menuItems;
    entries.seg = iVar12 + 1;
    entries.ofs = (uint16_t)unaff_SS;
    (*(uint8_t *)((uint8_t *)&(hint.seg))) = partyIndex;
    hint.ofs = (uint16_t)unaff_SS;
    (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = uVar13;
    ovr_ovc28_compute2(entries,(uint16_t)&msg,hint,(char)puVar6,(char)&msg);
    cStack_15 = (char)puVar6;
    goldPartyIndex = 0xff;
    if (cStack_15 != '\0') {
      cStack_15 = acStack_d[(uint)puVar6 & 0xff];
    }
    if (cStack_15 == '\x01') {
      uVar7 = ovc45_usesRandBelow(_bldType);
      if ((uVar7 & 0xff) == 0) {
        ovr_play_sfx(0,0x2f);
        ovr_say((char *)CONCAT13(uVar13,CONCAT12(partyIndex,0x2410)),0x66);
        ovr_createConstructionRecordFar();
      }
      else {
        uVar8 = ovr_randBelow(CONCAT11(uVar13,partyIndex),0x10);
        if ((uVar8 & 0xff) == 0) {
          ovr_play_sfx(0,0x2a);
          ovr_say((char *)CONCAT13(uVar13,CONCAT12(partyIndex,0x2410)),0x7e);
          ovr_createConstructionRecordFar();
        }
        else {
          uVar8 = ovr_randBelow(CONCAT11(uVar13,partyIndex),4);
          if ((char)uVar8 == '\0') {
            ovr_play_sfx(0,0x2b);
            ovr_say((char *)CONCAT13(uVar13,CONCAT12(partyIndex,0x2410)),0xa9);
            ovr_createConstructionRecordFar();
          }
          else {
            ovr_play_sfx(0,0x2a);
            ovr_say((char *)CONCAT13(uVar13,CONCAT12(partyIndex,0x2410)),0x8f);
            ovr_createConstructionRecordFar();
          }
        }
      }
      ovr_inputUpdate((ulong)CONCAT11(uVar13,partyIndex) << 0x10,MessageDelay * '\x02' + '\x12');
      cStack_16 = '\x01';
    }
    else if (cStack_15 == '\x02') {
      uStack_12 = 0x2410;
      _menuLabel = 0x770f;
      cStack_e = '\x10';
      acStack_d[0] = '$';
      uStack_10 = 0x77ba;
      uVar11 = 0x195d;
      uVar9 = *(undefined2 *)((uint)(byte)foundFlag * 0x27 + 0x10e);
      pcVar3 = ovr_fmVsprintf((char *)CONCAT13((char)((uint)uVar9 >> 8),CONCAT12((char)uVar9,0x2410)
                                              ),
                              (char *)CONCAT13(uVar13,CONCAT12(partyIndex,
                                                               *(undefined2 *)
                                                                ((uint)(byte)foundFlag * 0x27 +
                                                                0x110))));
      entries_00.seg = 2;
      entries_00.ofs = (uint16_t)unaff_SS;
      (*(uint8_t *)((uint8_t *)&(hint_00.seg))) = partyIndex;
      hint_00.ofs = uVar11;
      (*(uint8_t *)((uint8_t *)&(hint_00.seg) + 1)) = uVar13;
      cVar2 = (char)&menuLabel;
      ovr_ovc28_compute2(entries_00,(uint16_t)pcVar3,hint_00,(char)&menuLabel,(char)pcVar3);
      cStack_15 = cVar2;
      if (cStack_15 == '\x01') {
        ovr_createConstructionRecordFar();
      }
      cStack_16 = '\x01';
    }
    else if (cStack_15 == '\x03') {
      uVar9 = ovc45_textChoosePartyBuild
                        (GfxRndSeed2,(uint16_t)&bldType,
                         (int *)CONCAT13(uVar13,CONCAT12(partyIndex,unaff_SS)),iVar1,(char)&bldType)
      ;
      cStack_17 = (char)uVar9;
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

bool __cdecl16far ovc45_compute6(uint16_t value,...)

{
  int in_stack_00000004;
  
  return in_stack_00000004 != 1;
}



/* 77eb:1bb3 */

/* [R2] string "Done" */

void __cdecl16far
ovc45_textDone2(char foundFlag,byte bldType,int entityIndex,uint16_t x,uint16_t outFlag,
               uint16_t outFlagSeg,...)

{
  uint *puVar1;
  int *piVar2;
  uint16_t uVar3;
  far_t entries;
  int iVar4;
  bool bVar5;
  char *pcVar6;
  undefined2 *puVar7;
  int iVar8;
  uint8_t *puVar9;
  undefined1 uVar10;
  undefined2 uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined2 unaff_DI;
  undefined2 uVar16;
  char *unaff_SS;
  char in_stack_00000004;
  undefined1 uVar17;
  undefined1 uVar18;
  byte bldType_00;
  byte partyIndex;
  undefined1 uVar19;
  uint8_t menuLabels;
  undefined2 auStack_290 [19];
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
  
  iVar4 = entityIndex;
  partyIndex = (byte)unaff_DI;
  uVar19 = (undefined1)((uint)unaff_DI >> 8);
  uStack_1a = *(uint *)((uint)(byte)foundFlag * 0x27 + 0x125) / 10;
  auStack_290[0] = 0x2410;
  _menuLabels = 0x77f0;
  auStack_c[0] = 1;
  if (*(int *)((uint)(byte)foundFlag * 0x27 + 0x116) == 0 &&
      *(int *)((uint)(byte)foundFlag * 0x27 + 0x118) == 0) {
    auStack_290[2] = 0x2410;
    auStack_290[1] = 0x77f6;
  }
  else {
    auStack_290[2] = *(undefined2 *)((uint)(byte)foundFlag * 0x27 + 0x118);
    auStack_290[1] = *(undefined2 *)((uint)(byte)foundFlag * 0x27 + 0x116);
  }
  auStack_c[1] = 2;
  iVar15 = 2;
  if (in_stack_00000004 != '\0') {
    auStack_290[4] = 0x2410;
    auStack_290[3] = 0x7716;
    auStack_c[2] = 3;
    iVar15 = 3;
  }
  auStack_290[iVar15 * 2] = (char *)"puppetmaker" + 3;
  *(char **)(&menuLabels + iVar15 * 4) = (char *)"Done";
  auStack_c[iVar15] = 4;
  cStack_e = '\0';
  do {
    uVar17 = 0x10;
    pcVar6 = ovr_ovc22_className(partyIndex,
                                 *(undefined1 *)
                                  ((int)&((entity_t *)Entities)[_bldType].base.entity + 3));
    puVar7 = (undefined2 *)
             ((uint)*(byte *)((int)&((entity_t *)Entities)[_bldType].base.entity + 3) * 4);
    uVar10 = 0x7a;
    iVar8 = ovc45_compute9((char *)CONCAT22(*puVar7,unaff_SS),
                           (char *)CONCAT13((char)(Font03.ofs >> 8),
                                            CONCAT12((char)Font03.ofs,puVar7[1])),
                           (char *)CONCAT22(0x55,Font03.seg),3,(char)pcVar6,&text,(char)Font03.ofs,
                           (char)Font03.seg,3,(char)pcVar6,uVar17);
    uVar17 = (undefined1)uStack_1a;
    uVar18 = (undefined1)(uStack_1a >> 8);
    uVar11 = 0x195d;
    puVar9 = ovr_ovc15_usesStshRealloc
                       ((char *)CONCAT13(uVar18,CONCAT12(uVar17,*(undefined2 *)
                                                                 ((uint)(byte)foundFlag * 0x27 +
                                                                 0x110))),
                        *(undefined2 *)((uint)(byte)foundFlag * 0x27 + 0x10e),iVar8,uVar10);
    pcVar6 = ovr_fmVsprintf((char *)CONCAT22(puVar9,(char *)"puppetmaker" + 3),
                            (char *)CONCAT13(uVar18,CONCAT12(uVar17,uVar11)));
    strcpy((char *)CONCAT13((char)((uint)unaff_SS >> 8),CONCAT12((char)unaff_SS,&msg)),
           (char *)CONCAT13((char)((uint)uVar11 >> 8),CONCAT12((char)uVar11,pcVar6)));
    goldPartyIndex = *(undefined1 *)((int)&((entity_t *)Entities)[_bldType].base.entity + 3);
    puVar9 = &menuLabels;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = (char)(iVar15 + 1);
    entries.ofs = (uint16_t)unaff_SS;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = 0;
    ovr_ovc28_compute2(entries,(uint16_t)&msg,(char)puVar9,(char)&msg);
    menuActions = (uint8_t)puVar9;
    goldPartyIndex = 0xff;
    if ((uint8_t)puVar9 != 0x0) {
      menuActions = auStack_c[((uint)puVar9 & 0xff) - 1];
    }
    bldType_00 = (byte)iVar4;
    if (menuActions == 0x1) {
      ovr_play_sfx(0,0x56);
      if (*(char *)((uint)(byte)foundFlag * 0x27 + 0x131) == '\0') {
        if (*(char *)((int)&worldMenuLabels[9].ofs + 1 +
                     (uint)((entity_t *)Entities)[_bldType].base.gindex * 0x95) == '\x05') {
          bStack_11 = foundFlag + 0x18;
        }
        else {
          bStack_11 = foundFlag + 6;
        }
      }
      else {
        bStack_11 = foundFlag;
      }
      uStack_14 = (uint)*(byte *)((uint)bStack_11 * 0x27 + 0x120);
      *(undefined1 *)((uint)bStack_11 * 0x27 + 0x120) = 1;
      uVar17 = *(undefined1 *)((int)&((entity_t *)Entities)[_bldType].base.entity + 3);
      ovr_createConstructionRecord
                (bldType_00,GfxRndSeed2,x,
                 (uint8_t *)CONCAT13((char)((uint)(_bldType * 0x37) >> 8),CONCAT12(uVar17,outFlag)),
                 '\0',CONCAT11(0x24,bStack_11),(char)GfxRndSeed2,(char)outFlag,uVar17);
      *(undefined1 *)((uint)bStack_11 * 0x27 + 0x120) = (undefined1)uStack_14;
      pcStack_16 = ovr_ovc22_textPOPULATION
                             (*(byte *)((int)&((entity_t *)Entities)[_bldType].base.entity + 3),
                              bldType_00,(agnt_t *)CONCAT13(uVar19,CONCAT12(partyIndex,GfxRndSeed2))
                              ,CONCAT11((char)((uint)(_bldType * 0x37) >> 8),bStack_11),bldType_00,
                              (char)GfxRndSeed2);
      uVar11 = 0x2410;
      uStack_18 = ovr_ovc22_seasonalIncome
                            (*(byte *)((int)&((entity_t *)Entities)[_bldType].base.entity + 3),
                             bldType_00,CONCAT11((char)((uint)(_bldType * 0x37) >> 8),bStack_11),
                             bldType_00,(char)GfxRndSeed2);
      bVar5 = ovc45_compute6(CONCAT11(uVar19,partyIndex),(char)pcStack_16);
      uVar3 = ((far_t *)PersonWordPtrs + bVar5)->ofs;
      pcVar6 = ovr_fmVsprintf((char *)CONCAT22(uStack_18,(char *)"puppetmaker" + 3),
                              (char *)CONCAT13((char)(uVar3 >> 8),CONCAT12((char)uVar3,pcStack_16)))
      ;
      ovr_say((char *)CONCAT13(uVar19,CONCAT12(partyIndex,uVar11)),(char)pcVar6);
      ovr_inputUpdate((ulong)CONCAT11(uVar19,partyIndex) << 0x10,MessageDelay << 1);
      cStack_e = '\x01';
    }
    else if (menuActions == 0x2) {
      ovr_play_sfx(0,0x30);
      uVar17 = *(undefined1 *)((int)&((entity_t *)Entities)[_bldType].base.entity + 3);
      ovr_createConstructionRecordFar
                (bldType_00,GfxRndSeed2,x,
                 (uint8_t *)CONCAT13((char)((uint)(_bldType * 0x37) >> 8),CONCAT12(uVar17,outFlag)),
                 partyIndex,'\0',(char)x,(char)outFlag,uVar17);
      cStack_e = '\x01';
      bStack_10 = *(byte *)((int)&((entity_t *)Entities)[_bldType].base.entity + 3);
      uVar11 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_10 << 2) >> 0x10);
      iVar8 = (int)*(undefined4 *)((uint)bStack_10 << 2);
      puVar1 = (uint *)(iVar8 + 0x56);
      uVar12 = *puVar1;
      *puVar1 = *puVar1 + uStack_1a;
      piVar2 = (int *)(iVar8 + 0x58);
      *piVar2 = *piVar2 + (uint)CARRY2(uVar12,uStack_1a);
      uVar11 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_10 << 2) >> 0x10);
      iVar13 = (int)*(undefined4 *)((uint)bStack_10 << 2);
      iVar8 = *(int *)(iVar13 + 0x58);
      uVar12 = *(uint *)(iVar13 + 0x56);
      uVar11 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_10 << 2) >> 0x10);
      iVar14 = (int)*(undefined4 *)((uint)bStack_10 << 2);
      iVar13 = *(int *)(iVar14 + 0x8c);
      if ((iVar13 <= iVar8) && ((iVar13 < iVar8 || (*(uint *)(iVar14 + 0x8a) < uVar12)))) {
        uVar11 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_10 << 2) >> 0x10);
        iVar8 = (int)*(undefined4 *)((uint)bStack_10 << 2);
        uVar12 = *(uint *)(iVar8 + 0x8a);
        uVar16 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_10 << 2) >> 0x10);
        iVar13 = (int)*(undefined4 *)((uint)bStack_10 << 2);
        *(undefined2 *)(iVar13 + 0x58) = *(undefined2 *)(iVar8 + 0x8c);
        *(uint *)(iVar13 + 0x56) = uVar12;
      }
      pcVar6 = ovr_stsprintf((char *)CONCAT13(0x78,CONCAT12(0x91,unaff_SS)),
                             (char *)CONCAT13((char)(uStack_1a >> 8),
                                              CONCAT12((char)uStack_1a,0x2410)),(char)&text,0x10);
      ovr_say((char *)CONCAT13(uVar19,CONCAT12(partyIndex,uVar12)),(char)pcVar6);
      ovr_inputUpdate((ulong)CONCAT11(uVar19,partyIndex) << 0x10,MessageDelay << 1);
    }
    else if (menuActions == 0x3) {
      uVar11 = ovc45_textChoosePartyBuild(GfxRndSeed2,(uint16_t)&bldType,iVar4,(char)&bldType);
      cStack_f = (char)uVar11;
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

uint __cdecl16far ovc45_usesGfxRndSeed2(int *x,...)

{
  byte bVar1;
  byte bVar2;
  uint in_AX;
  undefined1 extraout_AH;
  uint uVar3;
  int *in_stack_00000004;
  uint in_stack_0000fffc;
  uint y;
  
  y = in_stack_0000fffc & 0xff00;
  while( true ) {
    if (3 < (byte)y) {
      return in_AX & 0xff00;
    }
    bVar2 = ovc45_getUnitType(GfxRndSeed2,y,
                              *(int *)CONCAT22((int *)x,in_stack_00000004) - (y & 0xff));
    in_AX = CONCAT11(extraout_AH,bVar2);
    if (bVar2 != 0) break;
    y = (uint)(byte)((byte)y + 1);
  }
  bVar1 = *(byte *)((uint)bVar2 * 0x27 + 0x11b);
  uVar3 = CONCAT11((char)((uint)bVar2 * 0x27 >> 8),bVar1);
  if ((byte)y < bVar1) {
    uVar3 = y & 0xff;
    *(int *)CONCAT22((int *)x,in_stack_00000004) =
         *(int *)CONCAT22((int *)x,in_stack_00000004) - uVar3;
  }
  else {
    bVar2 = 0;
  }
  return CONCAT11((char)(uVar3 >> 8),bVar2);
}



/* 77eb:215a */

/* [R6] touches GMapFlags */

int __cdecl16far ovc45_usesGMapFlags4(int x,int y,...)

{
  int in_AX;
  int iVar1;
  byte bVar2;
  undefined2 uVar3;
  int in_stack_00000004;
  
  if ((((in_stack_00000004 < 0) || (x < 0)) || (in_AX = in_stack_00000004 + 1, 0x93 < in_AX)) ||
     (in_AX = x + 1, 0x3b < in_AX)) {
    iVar1 = CONCAT11((char)((uint)in_AX >> 8),2);
  }
  else {
    uVar3 = (undefined2)((ulong)GMapFlags >> 0x10);
    if (((*(short (*) [60] [148])GMapFlags)[x][in_stack_00000004] & 3U) == 3) {
      iVar1 = 2;
    }
    else {
      bVar2 = (byte)((uint)(in_stack_00000004 * 2) >> 8);
      if (((*(short (*) [60] [148])GMapFlags)[x][in_stack_00000004] & 3U) == 0) {
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

undefined2 __cdecl16far ovc45_compute7(byte a,byte b,...)

{
  byte in_stack_00000004;
  
  return CONCAT11((byte)((uint)in_stack_00000004 * (uint)a >> 0xb),
                  (char)((uint)in_stack_00000004 * (uint)a >> 3));
}



/* 77eb:21f1 */

/* Shows the land info for the tile under a screen point: hit-tests with video_compute1, maps x to a
   tile column via (x-9)/0x30, and calls land_info. */

bool __cdecl16far ovc45_showLandInfo(int screenX,uint16_t y,...)

{
  int iVar1;
  undefined2 uVar2;
  byte unaff_SI;
  bool bVar3;
  int in_stack_00000004;
  
  iVar1 = in_stack_00000004;
  uVar2 = video_pointInButton(in_stack_00000004,screenX);
  bVar3 = (char)uVar2 != '\0';
  if (bVar3) {
    ovr_land_info(unaff_SI,(iVar1 - 9U) / 0x30);
  }
  return bVar3;
}



/* 77eb:2226 */

/* [R7] body shape: compute */

uint __cdecl16far ovc45_compute8(byte partyIndex,...)

{
  undefined4 uVar1;
  uint in_AX;
  uint uVar2;
  byte bVar3;
  byte in_stack_00000004;
  
  if (in_stack_00000004 == 0xff) {
    uVar2 = in_AX & 0xff00;
  }
  else {
    uVar1 = *(undefined4 *)((uint)in_stack_00000004 << 2);
    bVar3 = (byte)(((uint)in_stack_00000004 << 2) >> 8);
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

char * __cdecl16far ovc45_costOrIncomeLabel(int amount,...)

{
  char *pcVar1;
  int in_stack_00000004;
  
  if (in_stack_00000004 < 1) {
    pcVar1 = (char *)"Maintenance cost is";
  }
  else {
    pcVar1 = (char *)"Income created is";
  }
  return pcVar1;
}



/* 77eb:226e */

/* [R7] body shape: compute */

int __cdecl16far ovc45_compute9(char *dest,char *src,char *font,uint maxWidth,char mode,...)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_DI;
  int iVar4;
  int in_stack_00000004;
  char *font_00;
  undefined2 uVar5;
  int iStack_4;
  
  font_00 = (char *)CONCAT22(unaff_DI,(char *)font);
  uVar2 = ovr_font_textWidth(src,font_00,(*(uint16_t *)((uint8_t *)&(dest) + 2)));
  if ((*(uint16_t *)((uint8_t *)&(font) + 2)) < uVar2) {
    uVar5 = (undefined2)((ulong)font_00 >> 0x10);
    if ((char)maxWidth == '\x02') {
      iStack_4 = ovr_font_textWidth((char *)CONCAT22((*(uint16_t *)((uint8_t *)&(src) + 2)),(char *)"puppetmaker" + 3),
                                    (char *)CONCAT22(uVar5,(char *)font),0x78d8);
    }
    else {
      iStack_4 = ovr_font_textWidth((char *)CONCAT22((*(uint16_t *)((uint8_t *)&(src) + 2)),(char *)"puppetmaker" + 3),
                                    (char *)CONCAT22(uVar5,(char *)font),0x78db);
    }
    iVar3 = 0;
    for (iVar4 = 0;
        (*(char *)((*(uint16_t *)((uint8_t *)&(dest) + 2)) + iVar3) != '\0' &&
        ((int)(iStack_4 + iVar4 + (uint)*(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + *(char *)((*(uint16_t *)((uint8_t *)&(dest) + 2)) + iVar3) + 0xa1))
         <= (int)(*(uint16_t *)((uint8_t *)&(font) + 2)))); iVar4 = iVar4 + (uint)bVar1) {
      bVar1 = *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + *(char *)((*(uint16_t *)((uint8_t *)&(dest) + 2)) + iVar3) + 0xa1);
      *(undefined1 *)(in_stack_00000004 + iVar3) = *(undefined1 *)((*(uint16_t *)((uint8_t *)&(dest) + 2)) + iVar3);
      iVar3 = iVar3 + 1;
    }
    *(undefined1 *)(in_stack_00000004 + iVar3) = 0x2e;
    *(undefined1 *)(in_stack_00000004 + iVar3 + 1) = 0x2e;
    iVar4 = iVar3 + 2;
    if ((char)maxWidth != '\x02') {
      *(undefined1 *)(in_stack_00000004 + iVar4) = 0x2e;
      iVar4 = iVar3 + 3;
    }
    *(undefined1 *)(in_stack_00000004 + iVar4) = 0;
    (*(uint16_t *)((uint8_t *)&(dest) + 2)) = in_stack_00000004;
  }
  return (*(uint16_t *)((uint8_t *)&(dest) + 2));
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


