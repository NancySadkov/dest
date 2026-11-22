/* land_info - the terrain/land information panel.  Stack locals named from
   their assignments: unitType (GUnits[].unitType or the terrain byte),
   tileClass (2/1 select the message branch), again (do/while flag) and
   segTable (the word array holding DGROUP segment halves).  The body is
   333 lines and still register-temporary heavy. */
void __cdecl16far land_info(byte tileOffset,...)

{
  byte b;
  far_t entries;
  far_t entries_00;
  far_t entries_01;
  char cVar1;
  uint uVar2;
  uint16_t uVar3;
  char *pcVar4;
  uint16_t *puVar5;
  int iVar6;
  uint8_t *puVar7;
  uint16_t uVar8;
  int iVar9;
  unit_t *puVar10;
  uint16_t uVar11;
  char *unaff_SS;
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
  char cStack_1b;
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
  if (((*(uint *)((uint)bStack_1d * 0x27 + 0x121) & 0x80) == 0) &&
     (((unit_t *)GUnits)[uVar2].level < 3)) {
    type = 0;
    uVar3 = ovr_randBelow(2);
    ovr_play_sfx(CONCAT11((char)(uVar3 >> 8),(char)uVar3 + '?'),type);
  }
  uVar13 = SUB21(unaff_SS,0);
  uVar14 = (undefined1)((uint)unaff_SS >> 8);
  pcVar4 = ovr_ovc45_findEntityAt
                     (GfxRndSeed,GfxRndSeed2,(uint *)&entityIndex,(char)GfxRndSeed2,
                      (char)&entityIndex);
  cStack_1c = (char)pcVar4;
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
            strcpy((char *)CONCAT22(unaff_SS,&msg),"Water:");
          }
          else if (tileClass == '\x01') {
            strcpy((char *)CONCAT22(unaff_SS,&msg),"Shore:");
          }
          else {
            uVar11 = 0x195d;
            puVar7 = ovr_ovc15_usesStshRealloc
                               ((char *)*(uint16_t *)((uint)bStack_1d * 0x27 + 0x10e));
            pcVar4 = ovr_fmVsprintf("%s:",(char *)CONCAT22(uVar11,puVar7));
            strcpy((char *)CONCAT22(unaff_SS,&msg),(char *)CONCAT22(uVar11,pcVar4));
          }
        }
        else if (*(char *)((uint)bStack_1d * 0x27 + 0x130) == 'd') {
          uVar8 = 0x195d;
          puVar7 = ovr_ovc15_usesStshRealloc
                             ((char *)*(uint16_t *)((uint)bStack_1d * 0x27 + 0x10e),
                              *(uint16_t *)((uint)bStack_1d * 0x27 + 0x110),
                              *(uint16_t *)((uint)puVar10[uVar2].unitType * 4));
          pcVar4 = ovr_fmVsprintf("%s: Held by %s.",(char *)CONCAT22(uVar8,puVar7));
          strcpy((char *)CONCAT22(unaff_SS,&msg),(char *)CONCAT22(uVar8,pcVar4));
        }
        else {
          b = *(byte *)((uint)bStack_1d * 0x27 + 0x130);
          uVar11 = ovr_ovc45_compute7(puVar10[uVar2].level,b,b,
                                      (uint)*(byte *)((uint)bStack_1d * 0x27 + 0x130),
                                      *(uint16_t *)((uint)puVar10[uVar2].unitType * 4));
          uVar8 = 0x195d;
          puVar7 = ovr_ovc15_usesStshRealloc
                             ((char *)*(uint16_t *)((uint)bStack_1d * 0x27 + 0x10e),
                              (char)*(uint16_t *)((uint)bStack_1d * 0x27 + 0x110),(char)uVar11);
          pcVar4 = ovr_fmVsprintf("%s (%u/%u): Held by %s.",
                                  (char *)CONCAT13((char)((uint)uVar8 >> 8),
                                                   CONCAT12((char)uVar8,puVar7)));
          strcpy((char *)CONCAT22(unaff_SS,&msg),(char *)CONCAT22(uVar8,pcVar4));
          cVar1 = func_0x0007164e(0x1000);
          if (cVar1 != '\0') {
            strcat((char *)CONCAT22(unaff_SS,&msg)," Home a unit here to halt damage.");
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
                                                    CONCAT12(uVar12,unaff_SS)),
                                   (char *)CONCAT13((char)(Font03.ofs >> 8),
                                                    CONCAT12((char)Font03.ofs,uVar11)),Font03.seg,
                                   -0x47,uVar12,(char)uVar11,(char)Font03.ofs);
        uVar11 = 0x195d;
        puVar7 = ovr_ovc15_usesStshRealloc
                           ((char *)*(uint16_t *)((uint)bStack_1d * 0x27 + 0x10e),
                            (char)*(uint16_t *)((uint)bStack_1d * 0x27 + 0x110),
                            100 - ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 +
                                                  0xb) * 100) /
                                  (uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 +
                                                 0xc),iVar6);
        pcVar4 = ovr_fmVsprintf("%s: %d%% complete. Owned by %s.",
                                (char *)CONCAT13((char)((uint)uVar11 >> 8),
                                                 CONCAT12((char)uVar11,puVar7)));
        strcpy((char *)CONCAT22(unaff_SS,&msg),(char *)CONCAT22(uVar11,pcVar4));
      }
      hint.seg = (uint16_t)unaff_SS;
      hint.ofs = (uint16_t)&msg;
      puVar7 = &gfxOfs;
      (*(uint8_t *)((uint8_t *)&(entries.seg))) = uVar13;
      entries.ofs = (uint16_t)puVar7;
      (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar14;
      ovr_ovc28_compute2(entries,1,hint);
      cStack_1b = (char)puVar7;
    }
    else if (bStack_21 == 0xff) {
      if (((*(uint *)((uint)bStack_1d * 0x27 + 0x121) & 2) == 0) || (0xf7 < uVar2)) {
        if (((*(uint *)((uint)bStack_1d * 0x27 + 0x121) & 0x20) == 0) || (0xf7 < uVar2)) {
          if (bStack_1d == 0) {
            ovr_ovc45_buildPlacementMessage
                      ((char)(GfxRndSeed + (int)(char)tileOffset + -2),(char)GfxRndSeed2,
                       entityIndex,(uint)pcVar4 & 0xff,foundFlag);
          }
          else {
            constrct_buildInfoText
                      (0x23f1,CONCAT11((char)((uint)&outFlag >> 8),tileOffset),(char)&outFlag);
          }
        }
        else {
          ovr_ovc45_textDone2(foundFlag,bStack_1d,entityIndex,tileX,(uint16_t)&outFlag,
                              (uint16_t)unaff_SS,bStack_1d,(char)entityIndex);
        }
      }
      else {
        ovr_ovc45_textDone(foundFlag,bStack_1d,entityIndex,tileX,(uint16_t)&outFlag,
                           (uint16_t)unaff_SS,bStack_1d,(char)entityIndex);
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
          pcVar4 = ovr_ovc22_className(*(byte *)((int)Entities + entityIndex * 0x37 + 0x1a));
          puVar5 = (uint16_t *)((uint)*(byte *)((int)Entities + entityIndex * 0x37 + 0x1a) * 4);
          uVar11 = 0x217a;
          iVar6 = ovr_ovc45_compute9((char *)&text2,(char *)CONCAT22(*puVar5,unaff_SS),
                                     (char *)CONCAT13((char)(Font03.ofs >> 8),
                                                      CONCAT12((char)Font03.ofs,puVar5[1])),
                                     Font03.seg,'J',(char)Font03.ofs,(char)Font03.seg,0x4a,3,pcVar4)
          ;
          puVar5 = (uint16_t *)
                   ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 9) * 4);
          iVar6 = ovr_ovc45_compute9((char *)&text1,(char *)CONCAT22(*puVar5,unaff_SS),
                                     (char *)CONCAT22(Font03.ofs,(char *)puVar5[1]),Font03.seg,'J',
                                     0x4a,2,(char)iVar6,uVar11);
          iVar9 = 100 - ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 0xb) * 100
                        ) / (uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 0xc);
          pcVar4 = ovr_fmVsprintf("Clearing of land: %d%% complete. Owned by %s. Active party is %s the %s."
                                  ,(char *)CONCAT13((char)((uint)iVar6 >> 8),
                                                    CONCAT12((char)iVar6,iVar9)));
          strcpy((char *)CONCAT22(unaff_SS,&msg),(char *)CONCAT22(iVar9,pcVar4));
        }
        else {
          pcVar4 = ovr_ovc22_className(*(byte *)((int)Entities + entityIndex * 0x37 + 0x1a));
          puVar5 = (uint16_t *)((uint)*(byte *)((int)Entities + entityIndex * 0x37 + 0x1a) * 4);
          uVar11 = 0x217a;
          iVar6 = ovr_ovc45_compute9((char *)&text2,(char *)CONCAT22(*puVar5,unaff_SS),
                                     (char *)CONCAT13((char)(Font03.ofs >> 8),
                                                      CONCAT12((char)Font03.ofs,puVar5[1])),
                                     Font03.seg,'_',(char)Font03.ofs,(char)Font03.seg,0x5f,3,pcVar4)
          ;
          puVar5 = (uint16_t *)
                   ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 + 9) * 4);
          uVar12 = 0x7a;
          iVar6 = ovr_ovc45_compute9((char *)&text1,(char *)CONCAT22(*puVar5,unaff_SS),
                                     (char *)CONCAT22(Font03.ofs,(char *)puVar5[1]),Font03.seg,'_',
                                     0x5f,2,(char)iVar6,uVar11);
          uVar11 = 0x195d;
          puVar7 = ovr_ovc15_usesStshRealloc
                             ((char *)*(uint16_t *)((uint)bStack_1d * 0x27 + 0x10e),
                              *(uint16_t *)((uint)bStack_1d * 0x27 + 0x110),
                              100 - ((uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12
                                                    + 0xb) * 100) /
                                    (uint)*(byte *)(*(int *)((uint)bStack_21 * 2 + -0x6e29) * 0x12 +
                                                   0xc),(char)iVar6,uVar12);
          pcVar4 = ovr_fmVsprintf("%s: %d%% complete. Owned by %s. Active party is %s the %s.",
                                  (char *)CONCAT22(uVar11,puVar7));
          strcpy((char *)CONCAT22(unaff_SS,&msg),(char *)CONCAT22(uVar11,pcVar4));
        }
        goldPartyIndex = *(undefined1 *)((int)Entities + entityIndex * 0x37 + 0x1a);
        hint_00.seg = (uint16_t)unaff_SS;
        hint_00.ofs = (uint16_t)&msg;
        puVar7 = &menuItems;
        (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = uVar13;
        entries_00.ofs = (uint16_t)puVar7;
        (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = uVar14;
        ovr_ovc28_compute2(entries_00,uVar2 + 1,hint_00);
        cStack_1b = (char)puVar7;
        goldPartyIndex = 0xff;
        if (cStack_1b != '\0') {
          cStack_1b = auStack_14[((uint)puVar7 & 0xff) - 1];
        }
        if (cStack_1b == '\x01') {
          uStack_8 = segTable[0];
          menuLabel = menuItems;
          uStack_4 = 0x2410;
          uStack_6 = 0x7a02;
          uVar3 = 0x195d;
          puVar7 = ovr_ovc15_usesStshRealloc
                             ((char *)*(uint16_t *)((uint)bStack_1d * 0x27 + 0x10e));
          pcVar4 = ovr_fmVsprintf("Construction of %s will be permanently suspended. Are you sure?",
                                  (char *)CONCAT22(uVar3,puVar7));
          hint_01.seg = uVar3;
          hint_01.ofs = (uint16_t)pcVar4;
          puVar7 = &menuLabel;
          (*(uint8_t *)((uint8_t *)&(entries_01.seg))) = uVar13;
          entries_01.ofs = (uint16_t)puVar7;
          (*(uint8_t *)((uint8_t *)&(entries_01.seg) + 1)) = uVar14;
          ovr_ovc28_compute2(entries_01,2,hint_01);
          cStack_1b = (char)puVar7;
          if (cStack_1b == '\x01') {
            ovr_ovc23_removeRecord(*(int *)((uint)bStack_21 * 2 + -0x6e29));
          }
          again = '\x01';
        }
        else if (cStack_1b == '\x02') {
          uVar11 = ovr_ovc45_textChoosePartyBuild
                             ((GfxRndSeed + (int)(char)tileOffset) - 2,GfxRndSeed2,
                              (int *)&entityIndex);
          cStack_1c = (char)uVar11;
          if (cStack_1c == -1) {
            again = '\x01';
          }
        }
        else if ((cStack_1b == '\x03') || (cStack_1b == '\0')) {
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
