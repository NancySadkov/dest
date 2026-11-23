/*
 * ovc47_constrct.c - recovered from STRONG.EXE
 * memory block: OVC47_constrct.c
 * range: 7e7c:0000 - 7e7c:33cf
 * functions: 6
 */
#include "recovered.h"


/* 7e7c:0000 */

/* [R6] touches GLeaderCount */

void __cdecl16far constrct_usesGLeaderCount(void)

{
  int iVar1;
  uint8_t outFlag;
  byte bStack_3;
  
  outFlag = 0x0;
  for (bStack_3 = 0; bStack_3 < GLeaderCount; bStack_3 = bStack_3 + 1) {
    for (iVar1 = 0; iVar1 < 10; iVar1 = iVar1 + 1) {
      ovr_ovc22_usesRandBelow2(bStack_3,(uint16_t)&outFlag,_SS);
    }
  }
  if (outFlag != 0x0) {
    ovr_constr_flushDirtyRects();
  }
  return;
}



/* 7e7c:004b */
void __cdecl16far land_info(byte tileOffset)

{
  byte b;
  far_t entries;
  far_t entries_00;
  far_t entries_01;
  char cVar1;
  uint uVar2;
  uint16_t uVar3;
  char *textMsg;
  uint16_t *puVar5;
  int iVar6;
  uint8_t *stashOfs;
  uint16_t uVar8;
  int iVar9;
  unit_t *puVar10;
  uint16_t uVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  int16_t type;
  far_t hint;
  far_t hint_00;
  far_t hint_01;
  uint8_t text2;
  uint8_t text1;
  uint8_t menuItems;
  uint16_t segTable [19];
  uint8_t msg;
  char tileClass;
  byte unitType;
  char again;
  uint8_t foundFlag;
  byte bStack_21;
  uint8_t entityIndex;
  uint8_t outFlag;
  byte bStack_1d;
  char cStack_1c;
  char itemCode;
  uint8_t tileX;
  uint8_t gfxOfs;
  uint16_t uStack_16;
  undefined1 auStack_14 [10];
  uint8_t menuLabel;
  uint16_t uStack_8;
  uint16_t uStack_6;
  uint16_t uStack_4;
  
  uStack_16 = far_t_2410_78e4.seg;
  gfxOfs = far_t_2410_78e4.ofs;
  ovr_attact_usesAgntFlag1();
  savedMenuItem = GMenuItem;
  outFlag = 0x0;
  ovr_ovc18_blitPanelIfNotRunning();
  if ('\x02' < (char)tileOffset) {
    tileOffset = 3;
  }
  if ((char)tileOffset < '\0') {
    tileOffset = 0;
  }
  bStack_21 = 0xff;
  unitType = 0xff;
  tileX = (GfxRndSeed + (int)(char)tileOffset) - 2;
  uVar2 = ovr_ovc45_usesGfxRndSeed2((int *)&tileX);
  bStack_1d = (byte)uVar2;
  uVar2 = ovr_ovc45_getUnitIndex(tileX,GfxRndSeed2);
  uVar11 = (uint16_t)((ulong)GUnits >> 0x10);
  if (((unit_t *)GUnits)[uVar2].unitType != 0xff) {
    unitType = ((unit_t *)GUnits)[uVar2].unitType;
  }
  if (*(int *)((char)tileOffset * 2 + -0x6e29) != -1) {
    if (*(char *)(*(int *)((char)tileOffset * 2 + -0x6e29) * 0x12 + 0xc) == '\0') {
      *(undefined1 *)(*(int *)((char)tileOffset * 2 + -0x6e29) * 0x12 + 0xc) = 1;
    }
    bStack_21 = tileOffset;
    unitType = *(byte *)(*(int *)((uint)tileOffset * 2 + -0x6e29) * 0x12 + 9);
  }
  if (((BuildingTypes[bStack_1d].flags2 & 0x80) == 0) &&
     (((unit_t *)GUnits)[uVar2].level < 3)) {
    type = 0;
    uVar3 = ovr_randBelow(2,0);
    ovr_play_sfx(CONCAT11((char)(uVar3 >> 8),(char)uVar3 + '?'),type,0);
  }
  uVar13 = SUB21(_SS,0);
  uVar14 = (undefined1)((uint)_SS >> 8);
  textMsg = ovr_ovc45_findEntityAt
                     (GfxRndSeed,GfxRndSeed2,(uint *)&entityIndex,(char)GfxRndSeed2,
                      (char)&entityIndex);
  cStack_1c = (char)textMsg;
  if (cStack_1c == -1) {
    ovr_ovc41_enterLeaderView();
  }
  else {
    if (cStack_1c == '\0') {
      if (bStack_21 == 0xff) {
        uVar11 = (uint16_t)((ulong)GUnits >> 0x10);
        puVar10 = (unit_t *)GUnits;
        if (puVar10[uVar2].unitType == 0xff) {
          if (bStack_1d == 0) {
            uVar11 = ovr_ovc45_usesGMapFlags4(tileX,GfxRndSeed2);
            tileClass = (char)uVar11;
          }
          else {
            tileClass = '\0';
          }
          if (tileClass == '\x02') {
            strcpy((char *)CONCAT22(_SS,&msg),"Water:");
          }
          else if (tileClass == '\x01') {
            strcpy((char *)CONCAT22(_SS,&msg),"Shore:");
          }
          else {
            uVar11 = 0x195d;
            stashOfs = ovr_ovc15_usesStshRealloc
                               ((char *)BLD_WORD(&BuildingTypes[bStack_1d], name, 0),0,0,0,0,0,0,0);
            textMsg = ovr_fmVsprintf("%s:",(char *)CONCAT22(uVar11,stashOfs));
            strcpy((char *)CONCAT22(_SS,&msg),(char *)CONCAT22(uVar11,textMsg));
          }
        }
        else if (BuildingTypes[bStack_1d].durability == 'd') {
          uVar8 = 0x195d;
          stashOfs = ovr_ovc15_usesStshRealloc
                             ((char *)BLD_WORD(&BuildingTypes[bStack_1d], name, 0),BLD_WORD(&BuildingTypes[bStack_1d], name, 2),*(uint16_t *)((uint)puVar10[uVar2].unitType * 4),0,0,0,0,0);
          textMsg = ovr_fmVsprintf("%s: Held by %s.",(char *)CONCAT22(uVar8,stashOfs));
          strcpy((char *)CONCAT22(_SS,&msg),(char *)CONCAT22(uVar8,textMsg));
        }
        else {
          b = BuildingTypes[bStack_1d].durability;
          uVar11 = ovr_ovc45_compute7(puVar10[uVar2].level,b,b,
                                      (uint)BuildingTypes[bStack_1d].durability,
                                      *(uint16_t *)((uint)puVar10[uVar2].unitType * 4));
          uVar8 = 0x195d;
          stashOfs = ovr_ovc15_usesStshRealloc
                             ((char *)BLD_WORD(&BuildingTypes[bStack_1d], name, 0),(char)BLD_WORD(&BuildingTypes[bStack_1d], name, 2),(char)uVar11,0,0,0,0,0);
          textMsg = ovr_fmVsprintf("%s (%u/%u): Held by %s.",
                                  (char *)CONCAT13((char)((uint)uVar8 >> 8),
                                                   CONCAT12((char)uVar8,stashOfs)));
          strcpy((char *)CONCAT22(_SS,&msg),(char *)CONCAT22(uVar8,textMsg));
          cVar1 = func_0x0007164e(0x1000);
          if (cVar1 != '\0') {
            strcat((char *)CONCAT22(_SS,&msg)," Home a unit here to halt damage.");
          }
        }
      }
      else {
        bStack_1d = *(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 8);
        puVar5 = (uint16_t *)
                 ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 9) * 4);
        uVar11 = puVar5[1];
        uVar8 = *puVar5;
        uVar12 = (undefined1)uVar8;
        iVar6 = ovr_ovc45_compute9((char *)&text1,
                                   (char *)CONCAT13((char)((uint)uVar8 >> 8),
                                                    CONCAT12(uVar12,_SS)),
                                   (char *)CONCAT13((char)(Font03.ofs >> 8),
                                                    CONCAT12((char)Font03.ofs,uVar11)),Font03.seg,
                                   -0x47,uVar12,(char)uVar11,(char)Font03.ofs);
        uVar11 = 0x195d;
        stashOfs = ovr_ovc15_usesStshRealloc
                           ((char *)BLD_WORD(&BuildingTypes[bStack_1d], name, 0),(char)BLD_WORD(&BuildingTypes[bStack_1d], name, 2),100 - ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 +
                                                  0xb) * 100) /
                                  (uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 +
                                                 0xc),iVar6,0,0,0,0);
        textMsg = ovr_fmVsprintf("%s: %d%% complete. Owned by %s.",
                                (char *)CONCAT13((char)((uint)uVar11 >> 8),
                                                 CONCAT12((char)uVar11,stashOfs)));
        strcpy((char *)CONCAT22(_SS,&msg),(char *)CONCAT22(uVar11,textMsg));
      }
      hint.seg = (uint16_t)_SS;
      hint.ofs = (uint16_t)&msg;
      stashOfs = &gfxOfs;
      (*(uint8_t *)((uint8_t *)&(entries.seg))) = uVar13;
      entries.ofs = (uint16_t)stashOfs;
      (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar14;
      ovr_ovc28_compute2(entries,1,hint,0,0);
      itemCode = (char)stashOfs;
    }
    else if (bStack_21 == 0xff) {
      if (((BuildingTypes[bStack_1d].flags2 & 2) == 0) || (0xf7 < uVar2)) {
        if (((BuildingTypes[bStack_1d].flags2 & 0x20) == 0) || (0xf7 < uVar2)) {
          if (bStack_1d == 0) {
            ovr_ovc45_buildPlacementMessage
                      ((char)(GfxRndSeed + (int)(char)tileOffset + -2),(char)GfxRndSeed2,
                       entityIndex,(uint)textMsg & 0xff,foundFlag);
          }
          else {
            constrct_buildInfoText
                      (0x23f1,CONCAT11((char)((uint)&outFlag >> 8),tileOffset),(char)&outFlag);
          }
        }
        else {
          ovr_ovc45_textDone2(foundFlag,bStack_1d,entityIndex,tileX,(uint16_t)&outFlag,
                              (uint16_t)_SS,bStack_1d,(char)entityIndex);
        }
      }
      else {
        ovr_ovc45_textDone(foundFlag,bStack_1d,entityIndex,tileX,(uint16_t)&outFlag,
                           (uint16_t)_SS,bStack_1d,(char)entityIndex);
      }
    }
    else {
      bStack_1d = *(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 8);
      if (bStack_1d != 0) {
        segTable[0] = 0x2410;
        menuItems = 0x7969;
        auStack_14[0] = 1;
      }
      uVar2 = (uint)(bStack_1d != 0);
      if (foundFlag != 0x0) {
        segTable[uVar2 * 2] = 0x2410;   /* hand fix: this slot holds the DGROUP segment half, exactly as segTable[0] = 0x2410 above; the literal offset Ghidra printed is that same value */
        *(char **)(&menuItems + uVar2 * 4) = (char *)"Change party";
        auStack_14[uVar2] = 2;
        uVar2 = uVar2 + 1;
      }
      segTable[uVar2 * 2] = 0x2410;   /* hand fix: this slot holds the DGROUP segment half, exactly as segTable[0] = 0x2410 above; the literal offset Ghidra printed is that same value */
      *(char **)(&menuItems + uVar2 * 4) = (char *)"Done";
      auStack_14[uVar2] = 3;
      again = '\0';
      do {
        uVar11 = (uint16_t)((ulong)Entities >> 0x10);
        if (bStack_1d == 0) {
          textMsg = ovr_ovc22_className(AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 3),0);
          puVar5 = (uint16_t *)((uint)AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 3) * 4);
          uVar11 = 0x217a;
          iVar6 = ovr_ovc45_compute9((char *)&text2,(char *)CONCAT22(*puVar5,_SS),
                                     (char *)CONCAT13((char)(Font03.ofs >> 8),
                                                      CONCAT12((char)Font03.ofs,puVar5[1])),
                                     Font03.seg,'J',(char)Font03.ofs,(char)Font03.seg,0x4a,3,textMsg)
          ;
          puVar5 = (uint16_t *)
                   ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 9) * 4);
          iVar6 = ovr_ovc45_compute9((char *)&text1,(char *)CONCAT22(*puVar5,_SS),
                                     (char *)CONCAT22(Font03.ofs,(char *)puVar5[1]),Font03.seg,'J',
                                     0x4a,2,(char)iVar6,uVar11);
          iVar9 = 100 - ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 0xb) * 100
                        ) / (uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 0xc);
          textMsg = ovr_fmVsprintf("Clearing of land: %d%% complete. Owned by %s. Active party is %s the %s."
                                  ,(char *)CONCAT13((char)((uint)iVar6 >> 8),
                                                    CONCAT12((char)iVar6,iVar9)));
          strcpy((char *)CONCAT22(_SS,&msg),(char *)CONCAT22(iVar9,textMsg));
        }
        else {
          textMsg = ovr_ovc22_className(AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 3),0);
          puVar5 = (uint16_t *)((uint)AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 3) * 4);
          uVar11 = 0x217a;
          iVar6 = ovr_ovc45_compute9((char *)&text2,(char *)CONCAT22(*puVar5,_SS),
                                     (char *)CONCAT13((char)(Font03.ofs >> 8),
                                                      CONCAT12((char)Font03.ofs,puVar5[1])),
                                     Font03.seg,'_',(char)Font03.ofs,(char)Font03.seg,0x5f,3,textMsg)
          ;
          puVar5 = (uint16_t *)
                   ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 9) * 4);
          uVar12 = 0x7a;
          iVar6 = ovr_ovc45_compute9((char *)&text1,(char *)CONCAT22(*puVar5,_SS),
                                     (char *)CONCAT22(Font03.ofs,(char *)puVar5[1]),Font03.seg,'_',
                                     0x5f,2,(char)iVar6,uVar11);
          uVar11 = 0x195d;
          stashOfs = ovr_ovc15_usesStshRealloc
                             ((char *)BLD_WORD(&BuildingTypes[bStack_1d], name, 0),BLD_WORD(&BuildingTypes[bStack_1d], name, 2),100 - ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12
                                                    + 0xb) * 100) /
                                    (uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 +
                                                   0xc),(char)iVar6,uVar12,0,0,0);
          textMsg = ovr_fmVsprintf("%s: %d%% complete. Owned by %s. Active party is %s the %s.",
                                  (char *)CONCAT22(uVar11,stashOfs));
          strcpy((char *)CONCAT22(_SS,&msg),(char *)CONCAT22(uVar11,textMsg));
        }
        goldPartyIndex = AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 3);
        hint_00.seg = (uint16_t)_SS;
        hint_00.ofs = (uint16_t)&msg;
        stashOfs = &menuItems;
        (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = uVar13;
        entries_00.ofs = (uint16_t)stashOfs;
        (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = uVar14;
        ovr_ovc28_compute2(entries_00,uVar2 + 1,hint_00,0,0);
        itemCode = (char)stashOfs;
        goldPartyIndex = 0xff;
        if (itemCode != '\0') {
          itemCode = auStack_14[((uint)stashOfs & 0xff) - 1];
        }
        if (itemCode == '\x01') {
          uStack_8 = segTable[0];
          menuLabel = menuItems;
          uStack_4 = 0x2410;
          uStack_6 = 0x7a02;
          uVar3 = 0x195d;
          stashOfs = ovr_ovc15_usesStshRealloc
                             ((char *)BLD_WORD(&BuildingTypes[bStack_1d], name, 0),0,0,0,0,0,0,0);
          textMsg = ovr_fmVsprintf("Construction of %s will be permanently suspended. Are you sure?",
                                  (char *)CONCAT22(uVar3,stashOfs));
          hint_01.seg = uVar3;
          hint_01.ofs = (uint16_t)textMsg;
          stashOfs = &menuLabel;
          (*(uint8_t *)((uint8_t *)&(entries_01.seg))) = uVar13;
          entries_01.ofs = (uint16_t)stashOfs;
          (*(uint8_t *)((uint8_t *)&(entries_01.seg) + 1)) = uVar14;
          ovr_ovc28_compute2(entries_01,2,hint_01,0,0);
          itemCode = (char)stashOfs;
          if (itemCode == '\x01') {
            ovr_ovc23_removeRecord(*(int *)((uint)bStack_21 * 2 + -0x6e29));
          }
          again = '\x01';
        }
        else if (itemCode == '\x02') {
          uVar11 = ovr_ovc45_textChoosePartyBuild
                             ((GfxRndSeed + (int)(char)tileOffset) - 2,GfxRndSeed2,(int *)&entityIndex,0);
          cStack_1c = (char)uVar11;
          if (cStack_1c == -1) {
            again = '\x01';
          }
        }
        else if ((itemCode == '\x03') || (itemCode == '\0')) {
          again = '\x01';
        }
      } while (again == '\0');
    }
    if (outFlag != 0x0) {
      ovr_constr_flushDirtyRects();
    }
    ovr_ovc28_textHalflingCastle();
    ovr_ovc41_enterLeaderView();
  }
  return;
}


/* 7e7c:0b40 */

/* [R7] body shape: compute */

int __cdecl16far constrct_compute1(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = ovr_manage_findFirstLeader();
  if (bVar1 == 0xff) {
    iVar2 = 0;
  }
  else if ((GLeaderSheets[bVar1])->titleIndex < 5) {
    iVar2 = 0x14;
  }
  else {
    iVar2 = (uint)(GLeaderSheets[bVar1])->titleIndex * 4 + 0x14;
  }
  return iVar2;
}



/* 7e7c:0b9c */
/* DECOMPILATION FAILED: Exception while decompiling 7e7c:0b9c: process: timeout
 */
undefined constrct_buildInfoText() { return 0; }

/* 7e7c:2b4c */
void __cdecl16far constrct_usesLDIV_at_(byte partyIndex,int entityIndex)

{
  undefined1 stk_ff60;   /* stack slot ff60 */
  uint *puVar1;
  int *piVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  long *plVar6;
  char *msg;
  uint16_t uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint16_t unaff_SI;
  uint uVar12;
  long *unaff_DI;
  int iVar13;
  uint16_t uVar14;
  uint16_t uVar15;
  long lVar16;
  long lVar17;
  uint32_t in_stack_0000ff5e;
  long in_stack_0000ff62;
  uint16_t uStack_12;
  
  lVar17 = CONCAT22((int)((ulong)in_stack_0000ff5e >> 0x10),unaff_SI);
  bVar3 = AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 3);
  if ((partyIndex != 0xff) && (bVar3 != 0xff)) {
    bVar4 = (GLeaderSheets[partyIndex])->classStr;
    iVar9 = *(int *)((int)&worldMenuLabels[9].seg + 1 + (uint)bVar4 * 0x95);
    uVar5 = *(int *)((int)&worldMenuLabels[9].seg + 1 + (uint)bVar4 * 0x95) * 0xf;
    iVar13 = 0;
    for (uVar12 = 0; uVar12 < EntityCount; uVar12 = uVar12 + 1) {
      uVar14 = (uint16_t)((ulong)Entities >> 0x10);
      uVar14 = ovr_ovc23_isCursorAt
                         (((entity_t *)Entities)[uVar12].base.x,((entity_t *)Entities)[uVar12].base.y,0);
      if (((char)uVar14 != '\0') &&
         (AgntGs[(uint)((entity_t *)Entities)[uVar12].base.gindex].ai == '\0')) {
        iVar13 = iVar13 + 1;
      }
    }
    lVar16 = LDIV_at_((ulong)(uint)(iVar9 * 0xf),(long)iVar13);
    uVar7 = (uint16_t)((ulong)(lVar16 + 1) >> 0x10);
    uVar14 = uVar7;
    plVar6 = LXMUL_at_(unaff_DI,lVar17,in_stack_0000ff62);
    uStack_12 = (uint16_t)(lVar16 + 1);
    msg = ovr_stsprintf(&stk_ff60,(char *)CONCAT22(0x81dc,_SS),
                        (char *)CONCAT22(plVar6,(char *)0x2410),uVar14,uStack_12,uVar7,
                        uVar5);
    ovr_say(msg,0);
    lVar17 = LDIV_at_((ulong)uVar5,10);
    uVar14 = (uint16_t)((ulong)*(uint32_t *)((uint)bVar3 << 2) >> 0x10);
    iVar9 = (int)*(uint32_t *)((uint)bVar3 << 2);
    uVar8 = uVar5 - (uint)lVar17;
    puVar1 = (uint *)(iVar9 + 0x56);
    uVar12 = *puVar1;
    *puVar1 = *puVar1 + uVar8;
    piVar2 = (int *)(iVar9 + 0x58);
    *piVar2 = *piVar2 + (-(uint)(uVar5 < (uint)lVar17) - (int)((ulong)lVar17 >> 0x10)) +
              (uint)CARRY2(uVar12,uVar8);
    lVar17 = lVar17 + CONCAT22(GPopulationHi,GPopulationLo);
    GPopulationLo = (uint16_t)lVar17;
    GPopulationHi = (uint16_t)((ulong)lVar17 >> 0x10);
    uVar14 = (uint16_t)((ulong)*(uint32_t *)((uint)bVar3 << 2) >> 0x10);
    iVar10 = (int)*(uint32_t *)((uint)bVar3 << 2);
    iVar9 = *(int *)(iVar10 + 0x58);
    uVar7 = (uint16_t)((ulong)*(uint32_t *)((uint)bVar3 << 2) >> 0x10);
    iVar11 = (int)*(uint32_t *)((uint)bVar3 << 2);
    iVar13 = *(int *)(iVar11 + 0x8c);
    if ((iVar13 <= iVar9) &&
       ((iVar13 < iVar9 || (*(uint *)(iVar11 + 0x8a) < *(uint *)(iVar10 + 0x56))))) {
      uVar7 = (uint16_t)((ulong)*(uint32_t *)((uint)bVar3 << 2) >> 0x10);
      iVar9 = (int)*(uint32_t *)((uint)bVar3 << 2);
      uVar14 = *(uint16_t *)(iVar9 + 0x8a);
      uVar15 = (uint16_t)((ulong)*(uint32_t *)((uint)bVar3 << 2) >> 0x10);
      iVar13 = (int)*(uint32_t *)((uint)bVar3 << 2);
      *(uint16_t *)(iVar13 + 0x58) = *(uint16_t *)(iVar9 + 0x8c);
      *(uint16_t *)(iVar13 + 0x56) = uVar14;
      lVar17 = CONCAT22(GPopulationHi,GPopulationLo);
    }
    GPopulationHi = (uint16_t)((ulong)lVar17 >> 0x10);
    GPopulationLo = (uint16_t)lVar17;
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);   /* hand fix: the offset half is the address, not the far_t struct */
    ovr_inputUpdate(0x36);
  }
  return;
}


/* 7e7c:2e8e */

/* Returns whether none of the four map-flag words covering the unit's footprint is set. */

uint __cdecl16far constrct_unitFlagsClear(int unitIndex)

{
  uint32_t uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  unit_t *puVar6;
  int iVar7;
  uint uVar8;
  uint16_t uVar9;
  
  uVar9 = (uint16_t)((ulong)GUnits >> 0x10);
  puVar6 = (unit_t *)GUnits;
  if (puVar6[unitIndex].unitType == 0xff) {
    uVar2 = unitIndex * 9 & 0xff00;
  }
  else {
    uVar1 = *(uint32_t *)((uint)puVar6[unitIndex].unitType << 2);
    if (*(char *)((int)uVar1 + 0x3f) == '\0') {
      uVar3 = ovr_alignUp4(puVar6[unitIndex].x,0,0);
      uVar2 = ((unit_t *)GUnits)[unitIndex].y;
      uVar8 = 0;
      uVar4 = uVar2;
      for (iVar7 = 0; iVar7 < 4; iVar7 = iVar7 + 1) {
        uVar4 = ((short (*) [60] [148])GMapFlags)[-1][uVar2 + 0x3b][uVar3 + iVar7 + 0x92] & 0x1000;
        uVar8 = uVar8 | uVar4;
      }
      bVar5 = (byte)(uVar4 >> 8);
      if (uVar8 == 0) {
        uVar2 = CONCAT11(bVar5,1);
      }
      else {
        uVar2 = (uint)bVar5 << 8;
      }
    }
    else {
      uVar2 = (uint)(puVar6[unitIndex].unitType >> 6) << 8;
    }
  }
  return uVar2;
}


