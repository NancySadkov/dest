/*
 * ovc47_constrct.c - recovered from STRONG.EXE
 * memory block: OVC47_constrct.c
 * range: 7e7c:0000 - 7e7c:33cf
 * functions: 6
 */
#include "recovered.h"


/* 7e7c:0000 */

/* [R6] touches GLeaderCount */

void __cdecl16far constrct_usesGLeaderCount(void...)

{
  uint16_t unaff_SI;
  int iVar1;
  uint16_t unaff_SS;
  uint8_t outFlag;
  byte bStack_3;
  
  outFlag = 0x0;
  for (bStack_3 = 0; bStack_3 < GLeaderCount; bStack_3 = bStack_3 + 1) {
    for (iVar1 = 0; iVar1 < 10; iVar1 = iVar1 + 1) {
      ovr_ovc22_usesRandBelow2
                ((byte)&outFlag,unaff_SS,unaff_SI,CONCAT11((char)((uint)&outFlag >> 8),bStack_3));
    }
  }
  if (outFlag != 0x0) {
    ovr_constr_flushDirtyRects();
  }
  return;
}



/* 7e7c:004b */

void __cdecl16far land_info(byte tileOffset,...)

{
  byte b;
  far_t entries;
  far_t entries_00;
  far_t entries_01;
  far_t hint;
  far_t hint_00;
  far_t hint_01;
  char cVar1;
  uint uVar2;
  uint16_t uVar3;
  char *pcVar4;
  undefined2 *puVar5;
  int iVar6;
  uint8_t *puVar7;
  char *pcVar8;
  undefined2 uVar9;
  int iVar10;
  unit_t *puVar11;
  undefined2 unaff_DI;
  undefined2 uVar12;
  char *unaff_SS;
  byte in_stack_00000004;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  int16_t track;
  byte bVar17;
  undefined1 uVar18;
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
  
  bVar17 = (byte)unaff_DI;
  uVar18 = (undefined1)((uint)unaff_DI >> 8);
  uStack_16 = far_t_2410_78e4.seg;
  _gfxOfs = far_t_2410_78e4.ofs;
  ovr_attact_usesAgntFlag1();
  savedMenuItem = GMenuItem;
  outFlag = 0x0;
  ovr_ovc18_blitPanelIfNotRunning();
  if ('\x02' < (char)in_stack_00000004) {
    in_stack_00000004 = 3;
  }
  if ((char)in_stack_00000004 < '\0') {
    in_stack_00000004 = 0;
  }
  bStack_21 = 0xff;
  bStack_24 = 0xff;
  _tileX = GfxRndSeed + (char)in_stack_00000004 + -2;
  uVar2 = ovr_ovc45_usesGfxRndSeed2((int *)CONCAT13(uVar18,CONCAT12(bVar17,unaff_SS)),(char)&tileX);
  bStack_1d = (byte)uVar2;
  uVar2 = ovr_ovc45_getUnitIndex(GfxRndSeed2,(char)_tileX);
  uVar12 = (undefined2)((ulong)GUnits >> 0x10);
  if (((unit_t *)GUnits)[uVar2].unitType != 0xff) {
    bStack_24 = ((unit_t *)GUnits)[uVar2].unitType;
  }
  if (*(int *)((char)in_stack_00000004 * 2 + -0x6e29) != -1) {
    if (*(char *)(*(int *)((char)in_stack_00000004 * 2 + -0x6e29) * 0x12 + 0xc) == '\0') {
      *(undefined1 *)(*(int *)((char)in_stack_00000004 * 2 + -0x6e29) * 0x12 + 0xc) = 1;
    }
    bStack_21 = in_stack_00000004;
    bStack_24 = *(byte *)(*(int *)((uint)in_stack_00000004 * 2 + -0x6e29) * 0x12 + 9);
  }
  if (((*(uint *)((uint)bStack_1d * 0x27 + 0x121) & 0x80) == 0) &&
     (((unit_t *)GUnits)[uVar2].level < 3)) {
    track = 0;
    uVar3 = ovr_randBelow(0,2);
    ovr_play_sfx(track,(char)uVar3 + '?');
  }
  uVar13 = SUB21(unaff_SS,0);
  uVar15 = (undefined1)((uint)unaff_SS >> 8);
  pcVar4 = ovr_ovc45_findEntityAt(GfxRndSeed2,(uint16_t)&entityIndex,GfxRndSeed,(char)&entityIndex);
  cStack_1c = (char)pcVar4;
  if (cStack_1c == -1) {
    ovr_ovc41_enterLeaderView();
  }
  else {
    uVar14 = (undefined1)_tileX;
    if (cStack_1c == '\0') {
      if (bStack_21 == 0xff) {
        uVar12 = (undefined2)((ulong)GUnits >> 0x10);
        puVar11 = (unit_t *)GUnits;
        if (puVar11[uVar2].unitType == 0xff) {
          if (bStack_1d == 0) {
            uVar12 = ovr_ovc45_usesGMapFlags4(GfxRndSeed2,uVar14);
            cStack_25 = (char)uVar12;
          }
          else {
            cStack_25 = '\0';
          }
          if (cStack_25 == '\x02') {
            strcpy((char *)CONCAT13(uVar15,CONCAT12(uVar13,&msg)),"Water:");
          }
          else if (cStack_25 == '\x01') {
            strcpy((char *)CONCAT13(uVar15,CONCAT12(uVar13,&msg)),"Shore:");
          }
          else {
            uVar12 = 0x195d;
            puVar7 = ovr_ovc15_usesStshRealloc
                               ((char *)CONCAT13(uVar18,CONCAT12(bVar17,*(undefined2 *)
                                                                         ((uint)bStack_1d * 0x27 +
                                                                         0x110))),
                                (char)*(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e));
            pcVar4 = ovr_fmVsprintf((char *)CONCAT13((char)((uint)puVar7 >> 8),
                                                     CONCAT12((char)puVar7,0x2410)),
                                    (char *)CONCAT13(uVar18,CONCAT12(bVar17,uVar12)));
            strcpy((char *)CONCAT13(uVar15,CONCAT12(uVar13,&msg)),(char *)CONCAT22(uVar12,pcVar4));
          }
        }
        else if (*(char *)((uint)bStack_1d * 0x27 + 0x130) == 'd') {
          puVar5 = (undefined2 *)((uint)puVar11[uVar2].unitType * 4);
          uVar12 = *puVar5;
          uVar14 = (undefined1)uVar12;
          uVar16 = (undefined1)((uint)uVar12 >> 8);
          uVar12 = 0x195d;
          puVar7 = ovr_ovc15_usesStshRealloc
                             ((char *)CONCAT13(uVar16,CONCAT12(uVar14,*(undefined2 *)
                                                                       ((uint)bStack_1d * 0x27 +
                                                                       0x110))),
                              (char)*(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e),puVar5[1]);
          pcVar4 = ovr_fmVsprintf((char *)CONCAT13((char)((uint)puVar7 >> 8),
                                                   CONCAT12((char)puVar7,0x2410)),
                                  (char *)CONCAT13(uVar16,CONCAT12(uVar14,uVar12)));
          strcpy((char *)CONCAT13(uVar15,CONCAT12(uVar13,&msg)),(char *)CONCAT22(uVar12,pcVar4));
        }
        else {
          puVar5 = (undefined2 *)((uint)puVar11[uVar2].unitType * 4);
          b = *(byte *)((uint)bStack_1d * 0x27 + 0x130);
          uVar12 = ovr_ovc45_compute7(*(byte *)((uint)bStack_1d * 0x27 + 0x130),b,
                                      puVar11[uVar2].level,b,(char)*puVar5,puVar5[1]);
          uVar14 = (undefined1)uVar12;
          uVar16 = 0;
          uVar12 = 0x195d;
          puVar7 = ovr_ovc15_usesStshRealloc
                             ((char *)(ulong)CONCAT12(uVar14,*(undefined2 *)
                                                              ((uint)bStack_1d * 0x27 + 0x110)),
                              *(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e));
          pcVar4 = ovr_fmVsprintf((char *)CONCAT22(puVar7,(char *)"puppetmaker" + 3),
                                  (char *)CONCAT13(uVar16,CONCAT12(uVar14,uVar12)));
          strcpy((char *)CONCAT13(uVar15,CONCAT12(uVar13,&msg)),(char *)CONCAT22(uVar12,pcVar4));
          cVar1 = func_0x0007164e(0,uVar2);
          if (cVar1 != '\0') {
            strcat((char *)CONCAT13(uVar15,CONCAT12(uVar13,&msg)),
                   " Home a unit here to halt damage.");
          }
        }
      }
      else {
        bStack_1d = *(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 8);
        puVar5 = (undefined2 *)
                 ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 9) * 4);
        uVar9 = 0x217a;
        uVar12 = puVar5[1];
        iVar6 = ovr_ovc45_compute9((char *)CONCAT22(*puVar5,unaff_SS),
                                   (char *)CONCAT13((char)(Font03.ofs >> 8),
                                                    CONCAT12((char)Font03.ofs,uVar12)),
                                   (char *)(ulong)CONCAT12(0xb9,Font03.seg),2,bVar17,&text1,
                                   (char)uVar12,(char)Font03.ofs,(char)Font03.seg,0xb9);
        iVar10 = 100 - ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 0xb) * 100)
                       / (uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 0xc);
        uVar12 = 0x195d;
        puVar7 = ovr_ovc15_usesStshRealloc
                           ((char *)CONCAT13((char)((uint)iVar10 >> 8),
                                             CONCAT12((char)iVar10,
                                                      *(undefined2 *)
                                                       ((uint)bStack_1d * 0x27 + 0x110))),
                            (char)*(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e),(char)iVar6,uVar9)
        ;
        pcVar4 = ovr_fmVsprintf((char *)CONCAT13((char)((uint)puVar7 >> 8),
                                                 CONCAT12((char)puVar7,0x2410)),
                                (char *)CONCAT13((char)((uint)iVar10 >> 8),
                                                 CONCAT12((char)iVar10,uVar12)));
        strcpy((char *)CONCAT13(uVar15,CONCAT12(uVar13,&msg)),(char *)CONCAT22(uVar12,pcVar4));
      }
      cStack_1b = (char)&gfxOfs;
      (*(uint8_t *)((uint8_t *)&(entries.seg))) = 1;
      entries.ofs = (uint16_t)unaff_SS;
      (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = 0;
      (*(uint8_t *)((uint8_t *)&(hint.seg))) = bVar17;
      hint.ofs = (uint16_t)unaff_SS;
      (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = uVar18;
      ovr_ovc28_compute2(entries,(uint16_t)&msg,hint,cStack_1b,(char)&msg);
    }
    else if (bStack_21 == 0xff) {
      bVar17 = (byte)_entityIndex;
      if (((*(uint *)((uint)bStack_1d * 0x27 + 0x121) & 2) == 0) || (0xf7 < uVar2)) {
        if (((*(uint *)((uint)bStack_1d * 0x27 + 0x121) & 0x20) == 0) || (0xf7 < uVar2)) {
          if (bStack_1d == 0) {
            ovr_ovc45_buildPlacementMessage
                      ((char)(GfxRndSeed + (char)in_stack_00000004 + -2),(char)GfxRndSeed2,bVar17,
                       cStack_1c,foundFlag);
          }
          else {
            constrct_buildInfoText
                      (0x23f1,CONCAT11((char)((uint)&outFlag >> 8),in_stack_00000004),&outFlag);
          }
        }
        else {
          ovr_ovc45_textDone2(bStack_1d,bVar17,_tileX,(uint16_t)&outFlag,(uint16_t)unaff_SS,
                              CONCAT11((char)((uint)&outFlag >> 8),foundFlag),bVar17,uVar14,
                              (char)&outFlag);
        }
      }
      else {
        ovr_ovc45_textDone(bStack_1d,bVar17,_tileX,(uint16_t)&outFlag,(uint16_t)unaff_SS,
                           CONCAT11((char)((uint)&outFlag >> 8),foundFlag),bVar17,uVar14,
                           (char)&outFlag);
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
        uVar12 = (undefined2)((ulong)Entities >> 0x10);
        if (bStack_1d == 0) {
          uVar9 = 0x2410;
          pcVar4 = ovr_ovc22_className(bVar17,CONCAT11((char)((uint)(_entityIndex * 0x37) >> 8),
                                                       *(undefined1 *)
                                                        ((int)&((entity_t *)Entities)[_entityIndex].
                                                               base.entity + 3)));
          puVar5 = (undefined2 *)
                   ((uint)*(byte *)((int)&((entity_t *)Entities)[_entityIndex].base.entity + 3) * 4)
          ;
          uVar14 = 0x7a;
          iVar6 = ovr_ovc45_compute9((char *)CONCAT22(*puVar5,unaff_SS),
                                     (char *)CONCAT22(Font03.ofs,(char *)puVar5[1]),
                                     (char *)(ulong)CONCAT12(0x4a,Font03.seg),3,(char)pcVar4,&text2,
                                     (char)Font03.seg,0x4a,3,(char)pcVar4,uVar9);
          puVar5 = (undefined2 *)
                   ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 9) * 4);
          uVar12 = 0x217a;
          iVar6 = ovr_ovc45_compute9((char *)CONCAT22(*puVar5,unaff_SS),
                                     (char *)CONCAT22(Font03.ofs,(char *)puVar5[1]),
                                     (char *)CONCAT22(0x4a,Font03.seg),2,(char)iVar6,&text1,2,
                                     (char)iVar6,uVar14);
          iVar10 = 100 - ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 0xb) *
                         100) / (uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 0xc
                                               );
          pcVar4 = ovr_fmVsprintf((char *)CONCAT22(iVar10,(char *)"puppetmaker" + 3),
                                  (char *)CONCAT13((char)((uint)uVar12 >> 8),
                                                   CONCAT12((char)uVar12,iVar6)));
          strcpy((char *)CONCAT13(uVar15,CONCAT12(uVar13,&msg)),(char *)CONCAT22(iVar10,pcVar4));
        }
        else {
          uVar9 = 0x2410;
          pcVar4 = ovr_ovc22_className(bVar17,CONCAT11((char)((uint)(_entityIndex * 0x37) >> 8),
                                                       *(undefined1 *)
                                                        ((int)&((entity_t *)Entities)[_entityIndex].
                                                               base.entity + 3)));
          puVar5 = (undefined2 *)
                   ((uint)*(byte *)((int)&((entity_t *)Entities)[_entityIndex].base.entity + 3) * 4)
          ;
          uVar14 = 0x7a;
          iVar6 = ovr_ovc45_compute9((char *)CONCAT22(*puVar5,unaff_SS),
                                     (char *)CONCAT22(Font03.ofs,(char *)puVar5[1]),
                                     (char *)(ulong)CONCAT12(0x5f,Font03.seg),3,(char)pcVar4,&text2,
                                     (char)Font03.seg,0x5f,3,(char)pcVar4,uVar9);
          puVar5 = (undefined2 *)
                   ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 9) * 4);
          uVar16 = 0x7a;
          iVar6 = ovr_ovc45_compute9((char *)CONCAT22(*puVar5,unaff_SS),
                                     (char *)CONCAT22(Font03.ofs,(char *)puVar5[1]),
                                     (char *)CONCAT22(0x5f,Font03.seg),2,(char)iVar6,&text1,2,
                                     (char)iVar6,uVar14);
          iVar10 = 100 - ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 0xb) *
                         100) / (uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 0xc
                                               );
          pcVar8 = (char *)&AgntAnms[0x88].missileDy;
          puVar7 = ovr_ovc15_usesStshRealloc
                             ((char *)CONCAT22(iVar10,(char *)*(undefined2 *)
                                                               ((uint)bStack_1d * 0x27 + 0x110)),
                              *(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e),iVar6,uVar16);
          pcVar4 = ovr_fmVsprintf((char *)CONCAT22(puVar7,(char *)"puppetmaker" + 3),
                                  (char *)CONCAT22(iVar10,pcVar8));
          strcpy((char *)CONCAT13(uVar15,CONCAT12(uVar13,&msg)),(char *)CONCAT22(pcVar8,pcVar4));
        }
        goldPartyIndex = *(undefined1 *)((int)&((entity_t *)Entities)[_entityIndex].base.entity + 3)
        ;
        puVar7 = &menuItems;
        (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = (char)(uVar2 + 1);
        entries_00.ofs = (uint16_t)unaff_SS;
        (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = 0;
        (*(uint8_t *)((uint8_t *)&(hint_00.seg))) = bVar17;
        hint_00.ofs = (uint16_t)unaff_SS;
        (*(uint8_t *)((uint8_t *)&(hint_00.seg) + 1)) = uVar18;
        ovr_ovc28_compute2(entries_00,(uint16_t)&msg,hint_00,(char)puVar7,(char)&msg);
        cStack_1b = (char)puVar7;
        goldPartyIndex = 0xff;
        if (cStack_1b != '\0') {
          cStack_1b = auStack_14[((uint)puVar7 & 0xff) - 1];
        }
        if (cStack_1b == '\x01') {
          uStack_8 = auStack_24c[0];
          _menuLabel = _menuItems;
          uStack_4 = 0x2410;
          uStack_6 = 0x7a02;
          uVar12 = 0x195d;
          puVar7 = ovr_ovc15_usesStshRealloc
                             ((char *)CONCAT13(uVar18,CONCAT12(bVar17,*(undefined2 *)
                                                                       ((uint)bStack_1d * 0x27 +
                                                                       0x110))),
                              (char)*(undefined2 *)((uint)bStack_1d * 0x27 + 0x10e));
          pcVar4 = ovr_fmVsprintf((char *)CONCAT13((char)((uint)puVar7 >> 8),
                                                   CONCAT12((char)puVar7,0x2410)),
                                  (char *)CONCAT13(uVar18,CONCAT12(bVar17,uVar12)));
          (*(uint8_t *)((uint8_t *)&(entries_01.seg))) = 2;
          entries_01.ofs = (uint16_t)unaff_SS;
          (*(uint8_t *)((uint8_t *)&(entries_01.seg) + 1)) = 0;
          (*(uint8_t *)((uint8_t *)&(hint_01.seg))) = bVar17;
          hint_01.ofs = uVar12;
          (*(uint8_t *)((uint8_t *)&(hint_01.seg) + 1)) = uVar18;
          cVar1 = (char)&menuLabel;
          ovr_ovc28_compute2(entries_01,(uint16_t)pcVar4,hint_01,(char)&menuLabel,(char)pcVar4);
          cStack_1b = cVar1;
          if (cStack_1b == '\x01') {
            ovr_ovc23_removeRecord
                      (CONCAT11(uVar18,bVar17),*(undefined2 *)((uint)bStack_21 * 2 + -0x6e29));
          }
          cStack_23 = '\x01';
        }
        else if (cStack_1b == '\x02') {
          uVar12 = ovr_ovc45_textChoosePartyBuild
                             (GfxRndSeed2,(uint16_t)&entityIndex,
                              (int *)CONCAT13(uVar18,CONCAT12(bVar17,unaff_SS)),
                              (char)(GfxRndSeed + (char)in_stack_00000004 + -2),(char)&entityIndex);
          cStack_1c = (char)uVar12;
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
  long *plVar6;
  char *pcVar7;
  char *arg1;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  long *unaff_SI;
  uint uVar12;
  uint unaff_DI;
  int iVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined2 uVar16;
  char *unaff_SS;
  long lVar17;
  long in_stack_0000ff60;
  long in_stack_0000ff64;
  undefined2 uStack_12;
  
  bVar3 = *(byte *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3);
  if ((partyIndex != 0xff) && (bVar3 != 0xff)) {
    bVar4 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3e);
    iVar9 = *(int *)((int)&worldMenuLabels[9].seg + 1 + (uint)bVar4 * 0x95);
    uVar5 = *(int *)((int)&worldMenuLabels[9].seg + 1 + (uint)bVar4 * 0x95) * 0xf;
    iVar13 = 0;
    for (uVar12 = 0; uVar12 < EntityCount; uVar12 = uVar12 + 1) {
      uVar14 = (undefined2)((ulong)Entities >> 0x10);
      uVar14 = ovr_ovc23_isCursorAt
                         (((entity_t *)Entities)[uVar12].base.y,unaff_DI,
                          (((entity_t *)Entities + uVar12)->base).x);
      if (((char)uVar14 != '\0') &&
         (*(char *)((int)(char **)GMenuStrings +
                   (uint)((entity_t *)Entities)[uVar12].base.gindex * 0x95 + 0x1f) == '\0')) {
        iVar13 = iVar13 + 1;
      }
    }
    lVar17 = LDIV_at_((ulong)(uint)(iVar9 * 0xf),(long)iVar13);
    pcVar7 = (char *)((ulong)(lVar17 + 1) >> 0x10);
    arg1 = pcVar7;
    plVar6 = LXMUL_at_(unaff_SI,in_stack_0000ff60,in_stack_0000ff64);
    uStack_12 = (undefined2)(lVar17 + 1);
    pcVar7 = ovr_stsprintf((char *)CONCAT22(0x81dc,unaff_SS),
                           (char *)CONCAT22(plVar6,(char *)"puppetmaker" + 3),arg1,&stack0xff60,
                           uStack_12,pcVar7,uVar5,0);
    ovr_say((char *)CONCAT22(unaff_DI,arg1),pcVar7);
    lVar17 = LDIV_at_((ulong)uVar5,10);
    uVar14 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
    iVar9 = (int)*(undefined4 *)((uint)bVar3 << 2);
    uVar8 = uVar5 - (uint)lVar17;
    puVar1 = (uint *)(iVar9 + 0x56);
    uVar12 = *puVar1;
    *puVar1 = *puVar1 + uVar8;
    piVar2 = (int *)(iVar9 + 0x58);
    *piVar2 = *piVar2 + (-(uint)(uVar5 < (uint)lVar17) - (int)((ulong)lVar17 >> 0x10)) +
              (uint)CARRY2(uVar12,uVar8);
    lVar17 = lVar17 + CONCAT22(GPopulationHi,GPopulationLo);
    GPopulationLo = (undefined2)lVar17;
    GPopulationHi = (undefined2)((ulong)lVar17 >> 0x10);
    uVar14 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
    iVar10 = (int)*(undefined4 *)((uint)bVar3 << 2);
    iVar9 = *(int *)(iVar10 + 0x58);
    uVar15 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
    iVar11 = (int)*(undefined4 *)((uint)bVar3 << 2);
    iVar13 = *(int *)(iVar11 + 0x8c);
    if ((iVar13 <= iVar9) &&
       ((iVar13 < iVar9 || (*(uint *)(iVar11 + 0x8a) < *(uint *)(iVar10 + 0x56))))) {
      uVar15 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
      iVar9 = (int)*(undefined4 *)((uint)bVar3 << 2);
      uVar14 = *(undefined2 *)(iVar9 + 0x8a);
      uVar16 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
      iVar13 = (int)*(undefined4 *)((uint)bVar3 << 2);
      *(undefined2 *)(iVar13 + 0x58) = *(undefined2 *)(iVar9 + 0x8c);
      *(undefined2 *)(iVar13 + 0x56) = uVar14;
      lVar17 = CONCAT22(GPopulationHi,GPopulationLo);
    }
    GPopulationHi = (undefined2)((ulong)lVar17 >> 0x10);
    GPopulationLo = (undefined2)lVar17;
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
    ovr_inputUpdate((ulong)unaff_DI << 0x10,0x36);
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
  int unaff_DI;
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
      uVar3 = ovr_alignUp4(unaff_DI,puVar6[unitIndex].x);
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


