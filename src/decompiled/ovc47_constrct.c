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
  uint16_t unaff_SS;
  uint8_t outFlag;
  byte bStack_3;
  
  outFlag = 0x0;
  for (bStack_3 = 0; bStack_3 < GLeaderCount; bStack_3 = bStack_3 + 1) {
    for (iVar1 = 0; iVar1 < 10; iVar1 = iVar1 + 1) {
      ovr_ovc22_usesRandBelow2(bStack_3,(uint16_t)&outFlag,unaff_SS);
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
  far_t entries;
  far_t entries_00;
  far_t entries_01;
  char cVar1;
  uint uVar2;
  uint16_t uVar3;
  char *pcVar4;
  uint8_t *puVar5;
  undefined2 *puVar6;
  undefined2 uVar7;
  uint8_t *unaff_SS;
  undefined1 uVar8;
  undefined1 uVar9;
  int16_t type;
  far_t hint;
  far_t hint_00;
  far_t hint_01;
  uint8_t text2;
  uint8_t text1;
  uint8_t menuItems;
  undefined2 auStack_24c [19];
  uint8_t msg;
  char cStack_25;
  byte bStack_24;
  char cStack_23;
  uint8_t foundFlag;
  byte bStack_21;
  uint8_t entityIndex;
  uint8_t outFlag;
  byte bStack_1d;
  char cStack_1c;
  char cStack_1b;
  uint8_t tileX;
  uint8_t gfxOfs;
  undefined2 uStack_16;
  undefined1 auStack_14 [10];
  uint8_t menuLabel;
  undefined2 uStack_8;
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  uStack_16 = far_t_2410_78e4.seg;
  _gfxOfs = far_t_2410_78e4.ofs;
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
  bStack_24 = 0xff;
  _tileX = (GfxRndSeed + (int)(char)tileOffset) - 2;
  uVar2 = ovr_ovc45_usesGfxRndSeed2((int *)&tileX);
  bStack_1d = (byte)uVar2;
  uVar2 = ovr_ovc45_getUnitIndex(_tileX,GfxRndSeed2);
  uVar7 = (undefined2)((ulong)GUnits >> 0x10);
  if (((unit_t *)GUnits)[uVar2].unitType != 0xff) {
    bStack_24 = ((unit_t *)GUnits)[uVar2].unitType;
  }
  if (*(int *)((char)tileOffset * 2 + -0x6e29) != -1) {
    if (*(char *)(*(int *)((char)tileOffset * 2 + -0x6e29) * 0x12 + 0xc) == '\0') {
      *(undefined1 *)(*(int *)((char)tileOffset * 2 + -0x6e29) * 0x12 + 0xc) = 1;
    }
    bStack_21 = tileOffset;
    bStack_24 = *(byte *)(*(int *)((uint)tileOffset * 2 + -0x6e29) * 0x12 + 9);
  }
  if (((*(uint *)((uint)bStack_1d * 0x27 + 0x121) & 0x80) == 0) &&
     (((unit_t *)GUnits)[uVar2].level < 3)) {
    type = 0;
    uVar3 = ovr_randBelow(2);
    ovr_play_sfx(CONCAT11((char)(uVar3 >> 8),(char)uVar3 + '?'),type);
  }
  uVar8 = SUB21(unaff_SS,0);
  uVar9 = (undefined1)((uint)unaff_SS >> 8);
  pcVar4 = ovr_ovc45_findEntityAt
                     (GfxRndSeed,GfxRndSeed2,(uint *)&entityIndex,unaff_SS,(char)&foundFlag);
  cStack_1c = (char)pcVar4;
  if (cStack_1c == -1) {
    ovr_ovc41_enterLeaderView();
  }
  else {
    if (cStack_1c == '\0') {
      if (bStack_21 == 0xff) {
        uVar7 = (undefined2)((ulong)GUnits >> 0x10);
        if (((unit_t *)GUnits)[uVar2].unitType == 0xff) {
          if (bStack_1d == 0) {
            uVar7 = ovr_ovc45_usesGMapFlags4(_tileX,GfxRndSeed2);
            cStack_25 = (char)uVar7;
          }
          else {
            cStack_25 = '\0';
          }
          if (cStack_25 == '\x02') {
            strcpy((char *)&msg,(char *)unaff_SS);
          }
          else if (cStack_25 == '\x01') {
            strcpy((char *)&msg,(char *)unaff_SS);
          }
          else {
            ovr_ovc15_usesStshRealloc
                      ((char *)CONCAT22(*(undefined2 *)((uint)bStack_1d * 0x27 + 0x110),
                                        (char *)*(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e)));
            ovr_fmVsprintf((char *)"%s:",(char *)"puppetmaker" + 3);
            strcpy((char *)&msg,(char *)unaff_SS);
          }
        }
        else if (*(char *)((uint)bStack_1d * 0x27 + 0x130) == 'd') {
          uVar7 = *(undefined2 *)((uint)bStack_1d * 0x27 + 0x110);
          ovr_ovc15_usesStshRealloc
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),
                                      CONCAT12((char)uVar7,
                                               *(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e))));
          ovr_fmVsprintf((char *)"%s: Held by %s.",(char *)"puppetmaker" + 3);
          strcpy((char *)&msg,(char *)unaff_SS);
        }
        else {
          ovr_ovc45_compute7(((unit_t *)GUnits)[uVar2].level,
                             *(byte *)((uint)bStack_1d * 0x27 + 0x130));
          uVar7 = *(undefined2 *)((uint)bStack_1d * 0x27 + 0x110);
          ovr_ovc15_usesStshRealloc
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),
                                      CONCAT12((char)uVar7,
                                               *(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e))));
          ovr_fmVsprintf((char *)"%s (%u/%u): Held by %s.",(char *)"puppetmaker" + 3);
          strcpy((char *)&msg,(char *)unaff_SS);
          cVar1 = func_0x0007164e(0x1000);
          if (cVar1 != '\0') {
            strcat((char *)&msg,(char *)unaff_SS);
          }
        }
      }
      else {
        bStack_1d = *(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 8);
        puVar6 = (undefined2 *)
                 ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 9) * 4);
        uVar7 = puVar6[1];
        ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text1),
                           (char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,*puVar6)),
                           (char *)CONCAT13((char)(Font03.seg >> 8),
                                            CONCAT12((char)Font03.seg,Font03.ofs)),0xb9,'\x02');
        uVar7 = *(undefined2 *)((uint)bStack_1d * 0x27 + 0x110);
        ovr_ovc15_usesStshRealloc
                  ((char *)CONCAT13((char)((uint)uVar7 >> 8),
                                    CONCAT12((char)uVar7,
                                             *(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e))));
        ovr_fmVsprintf((char *)"%s: %d%% complete. Owned by %s.",(char *)"puppetmaker" + 3);
        strcpy((char *)&msg,(char *)unaff_SS);
      }
      hint.seg = (uint16_t)unaff_SS;
      hint.ofs = (uint16_t)&msg;
      puVar5 = &gfxOfs;
      (*(uint8_t *)((uint8_t *)&(entries.seg))) = uVar8;
      entries.ofs = (uint16_t)puVar5;
      (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar9;
      ovr_ovc28_compute2(entries,1,hint);
      cStack_1b = (char)puVar5;
    }
    else if (bStack_21 == 0xff) {
      if (((*(uint *)((uint)bStack_1d * 0x27 + 0x121) & 2) == 0) || (0xf7 < uVar2)) {
        if (((*(uint *)((uint)bStack_1d * 0x27 + 0x121) & 0x20) == 0) || (0xf7 < uVar2)) {
          if (bStack_1d == 0) {
            ovr_ovc45_buildPlacementMessage
                      ((char)(GfxRndSeed + (int)(char)tileOffset + -2),(char)GfxRndSeed2,
                       (char)_entityIndex,(uint)pcVar4 & 0xff,foundFlag);
          }
          else {
            constrct_buildInfoText
                      (0x23f1,CONCAT11((char)((uint)&outFlag >> 8),tileOffset),(char)&outFlag);
          }
        }
        else {
          ovr_ovc45_textDone2(foundFlag,bStack_1d,_entityIndex,_tileX,(uint16_t)&outFlag,
                              (uint16_t)unaff_SS);
        }
      }
      else {
        ovr_ovc45_textDone(foundFlag,bStack_1d,_entityIndex,_tileX,(uint16_t)&outFlag,
                           (uint16_t)unaff_SS);
      }
    }
    else {
      bStack_1d = *(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 8);
      if (bStack_1d != 0) {
        auStack_24c[0] = 0x2410;
        _menuItems = 0x7969;
        auStack_14[0] = 1;
      }
      uVar2 = (uint)(bStack_1d != 0);
      if (foundFlag != 0x0) {
        auStack_24c[uVar2 * 2] = (char *)"puppetmaker" + 3;
        *(char **)(&menuItems + uVar2 * 4) = (char *)"Change party";
        auStack_14[uVar2] = 2;
        uVar2 = uVar2 + 1;
      }
      auStack_24c[uVar2 * 2] = (char *)"puppetmaker" + 3;
      *(char **)(&menuItems + uVar2 * 4) = (char *)"Done";
      auStack_14[uVar2] = 3;
      cStack_23 = '\0';
      do {
        uVar7 = (undefined2)((ulong)Entities >> 0x10);
        if (bStack_1d == 0) {
          ovr_ovc22_className(*(byte *)((int)&((entity_t *)Entities)[_entityIndex].base.entity + 3))
          ;
          puVar6 = (undefined2 *)
                   ((uint)*(byte *)((int)&((entity_t *)Entities)[_entityIndex].base.entity + 3) * 4)
          ;
          ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text2),
                             (char *)CONCAT22(puVar6[1],(char *)*puVar6),
                             (char *)CONCAT13((char)(Font03.seg >> 8),
                                              CONCAT12((char)Font03.seg,Font03.ofs)),0x4a,'\x03');
          puVar6 = (undefined2 *)
                   ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 9) * 4);
          ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text1),
                             (char *)CONCAT22(puVar6[1],(char *)*puVar6),
                             (char *)CONCAT22(Font03.seg,Font03.ofs),0x4a,'\x02');
          ovr_fmVsprintf((char *)
                         "Clearing of land: %d%% complete. Owned by %s. Active party is %s the %s.",
                         (char *)"puppetmaker" + 3);
          strcpy((char *)&msg,(char *)unaff_SS);
        }
        else {
          ovr_ovc22_className(*(byte *)((int)&((entity_t *)Entities)[_entityIndex].base.entity + 3))
          ;
          puVar6 = (undefined2 *)
                   ((uint)*(byte *)((int)&((entity_t *)Entities)[_entityIndex].base.entity + 3) * 4)
          ;
          ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text2),
                             (char *)CONCAT22(puVar6[1],(char *)*puVar6),
                             (char *)CONCAT13((char)(Font03.seg >> 8),
                                              CONCAT12((char)Font03.seg,Font03.ofs)),0x5f,'\x03');
          puVar6 = (undefined2 *)
                   ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 9) * 4);
          ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text1),
                             (char *)CONCAT22(puVar6[1],(char *)*puVar6),
                             (char *)CONCAT22(Font03.seg,Font03.ofs),0x5f,'\x02');
          ovr_ovc15_usesStshRealloc
                    ((char *)CONCAT22(*(undefined2 *)((uint)bStack_1d * 0x27 + 0x110),
                                      (char *)*(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e)));
          ovr_fmVsprintf((char *)"%s: %d%% complete. Owned by %s. Active party is %s the %s.",
                         (char *)"puppetmaker" + 3);
          strcpy((char *)&msg,(char *)unaff_SS);
        }
        goldPartyIndex = *(undefined1 *)((int)&((entity_t *)Entities)[_entityIndex].base.entity + 3)
        ;
        hint_00.seg = (uint16_t)unaff_SS;
        hint_00.ofs = (uint16_t)&msg;
        puVar5 = &menuItems;
        (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = uVar8;
        entries_00.ofs = (uint16_t)puVar5;
        (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = uVar9;
        ovr_ovc28_compute2(entries_00,uVar2 + 1,hint_00);
        cStack_1b = (char)puVar5;
        goldPartyIndex = 0xff;
        if (cStack_1b != '\0') {
          cStack_1b = auStack_14[((uint)puVar5 & 0xff) - 1];
        }
        if (cStack_1b == '\x01') {
          uStack_8 = auStack_24c[0];
          _menuLabel = _menuItems;
          uStack_4 = 0x2410;
          uStack_6 = 0x7a02;
          uVar3 = 0x195d;
          ovr_ovc15_usesStshRealloc
                    ((char *)CONCAT22(*(undefined2 *)((uint)bStack_1d * 0x27 + 0x110),
                                      (char *)*(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e)));
          pcVar4 = ovr_fmVsprintf((char *)
                                  "Construction of %s will be permanently suspended. Are you sure?",
                                  (char *)"puppetmaker" + 3);
          hint_01.seg = uVar3;
          hint_01.ofs = (uint16_t)pcVar4;
          puVar5 = &menuLabel;
          (*(uint8_t *)((uint8_t *)&(entries_01.seg))) = uVar8;
          entries_01.ofs = (uint16_t)puVar5;
          (*(uint8_t *)((uint8_t *)&(entries_01.seg) + 1)) = uVar9;
          ovr_ovc28_compute2(entries_01,2,hint_01);
          cStack_1b = (char)puVar5;
          if (cStack_1b == '\x01') {
            ovr_ovc23_removeRecord(*(int *)((uint)bStack_21 * 2 + -0x6e29));
          }
          cStack_23 = '\x01';
        }
        else if (cStack_1b == '\x02') {
          uVar7 = ovr_ovc45_textChoosePartyBuild
                            ((GfxRndSeed + (int)(char)tileOffset) - 2,GfxRndSeed2,
                             (int *)&entityIndex);
          cStack_1c = (char)uVar7;
          if (cStack_1c == -1) {
            cStack_23 = '\x01';
          }
        }
        else if ((cStack_1b == '\x03') || (cStack_1b == '\0')) {
          cStack_23 = '\x01';
        }
      } while (cStack_23 == '\0');
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
  else if (*(byte *)((int)*(undefined4 *)((uint)bVar1 << 2) + 0x86) < 5) {
    iVar2 = 0x14;
  }
  else {
    iVar2 = (uint)*(byte *)((int)*(undefined4 *)((uint)bVar1 << 2) + 0x86) * 4 + 0x14;
  }
  return iVar2;
}



/* 7e7c:0b9c */
/* DECOMPILATION FAILED: Exception while decompiling 7e7c:0b9c: process: timeout
 */
void constrct_buildInfoText(void) { /* failed */ }

/* 7e7c:2b4c */

/* WARNING: Removing unreachable block (ram,0x00081559) */
/* WARNING: Removing unreachable block (ram,0x00081610) */
/* WARNING: Removing unreachable block (ram,0x0008155e) */
/* WARNING: Removing unreachable block (ram,0x00081597) */
/* WARNING: Removing unreachable block (ram,0x000815cd) */
/* WARNING: Removing unreachable block (ram,0x0008160f) */
/* [R4] calls LDIV_at_ */

void __cdecl16far constrct_usesLDIV_at_(byte partyIndex,int entityIndex)

{
  uint *puVar1;
  int *piVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  char *msg;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  long *unaff_DI;
  int iVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  char *unaff_SS;
  long lVar15;
  long in_stack_0000ff60;
  long in_stack_0000ff64;
  
  bVar3 = *(byte *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3);
  if ((partyIndex != 0xff) && (bVar3 != 0xff)) {
    bVar4 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3e);
    iVar7 = *(int *)((int)&worldMenuLabels[9].seg + 1 + (uint)bVar4 * 0x95);
    uVar5 = *(int *)((int)&worldMenuLabels[9].seg + 1 + (uint)bVar4 * 0x95) * 0xf;
    iVar11 = 0;
    for (uVar10 = 0; uVar10 < EntityCount; uVar10 = uVar10 + 1) {
      uVar12 = (undefined2)((ulong)Entities >> 0x10);
      uVar12 = ovr_ovc23_isCursorAt
                         ((((entity_t *)Entities + uVar10)->base).x,
                          ((entity_t *)Entities)[uVar10].base.y);
      if (((char)uVar12 != '\0') &&
         (*(char *)((int)(char **)GMenuStrings +
                   (uint)((entity_t *)Entities)[uVar10].base.gindex * 0x95 + 0x1f) == '\0')) {
        iVar11 = iVar11 + 1;
      }
    }
    LDIV_at_((ulong)(uint)(iVar7 * 0xf),(long)iVar11);
    LXMUL_at_(unaff_DI,in_stack_0000ff60,in_stack_0000ff64);
    msg = ovr_stsprintf(&stack0xff60,unaff_SS,
                        (char *)
                        "%ld experience obtained. %ld experience given to each unit. %ld gold recovered."
                       );
    ovr_say(msg);
    lVar15 = LDIV_at_((ulong)uVar5,10);
    uVar12 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
    iVar7 = (int)*(undefined4 *)((uint)bVar3 << 2);
    uVar6 = uVar5 - (uint)lVar15;
    puVar1 = (uint *)(iVar7 + 0x56);
    uVar10 = *puVar1;
    *puVar1 = *puVar1 + uVar6;
    piVar2 = (int *)(iVar7 + 0x58);
    *piVar2 = *piVar2 + (-(uint)(uVar5 < (uint)lVar15) - (int)((ulong)lVar15 >> 0x10)) +
              (uint)CARRY2(uVar10,uVar6);
    lVar15 = lVar15 + CONCAT22(GPopulationHi,GPopulationLo);
    GPopulationLo = (undefined2)lVar15;
    GPopulationHi = (undefined2)((ulong)lVar15 >> 0x10);
    uVar12 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
    iVar8 = (int)*(undefined4 *)((uint)bVar3 << 2);
    iVar7 = *(int *)(iVar8 + 0x58);
    uVar13 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
    iVar9 = (int)*(undefined4 *)((uint)bVar3 << 2);
    iVar11 = *(int *)(iVar9 + 0x8c);
    if ((iVar11 <= iVar7) &&
       ((iVar11 < iVar7 || (*(uint *)(iVar9 + 0x8a) < *(uint *)(iVar8 + 0x56))))) {
      uVar13 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
      iVar7 = (int)*(undefined4 *)((uint)bVar3 << 2);
      uVar12 = *(undefined2 *)(iVar7 + 0x8a);
      uVar14 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
      iVar11 = (int)*(undefined4 *)((uint)bVar3 << 2);
      *(undefined2 *)(iVar11 + 0x58) = *(undefined2 *)(iVar7 + 0x8c);
      *(undefined2 *)(iVar11 + 0x56) = uVar12;
      lVar15 = CONCAT22(GPopulationHi,GPopulationLo);
    }
    GPopulationHi = (undefined2)((ulong)lVar15 >> 0x10);
    GPopulationLo = (undefined2)lVar15;
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
    ovr_inputUpdate(0x36);
  }
  return;
}



/* 7e7c:2e8e */

/* Returns whether none of the four map-flag words covering the unit's footprint is set. */

uint __cdecl16far constrct_unitFlagsClear(int unitIndex)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  unit_t *puVar6;
  int iVar7;
  uint uVar8;
  undefined2 uVar9;
  
  uVar9 = (undefined2)((ulong)GUnits >> 0x10);
  puVar6 = (unit_t *)GUnits;
  if (puVar6[unitIndex].unitType == 0xff) {
    uVar2 = unitIndex * 9 & 0xff00;
  }
  else {
    uVar1 = *(undefined4 *)((uint)puVar6[unitIndex].unitType << 2);
    if (*(char *)((int)uVar1 + 0x3f) == '\0') {
      uVar3 = ovr_alignUp4(puVar6[unitIndex].x);
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


