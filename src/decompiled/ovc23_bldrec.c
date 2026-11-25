/*
 * ovc23_bldrec.c - recovered from STRONG.EXE
 * memory block: OVC23_bldrec.c
 * range: 55fe:0000 - 55fe:345d
 * functions: 26
 */
#include "recovered.h"


/* 55fe:0000 */
byte * __cdecl16far ovc23_textAdlibNone(uint partyIndex,uint16_t outFlag,agnt_t *agnt)

{
  undefined1 stk_02c2;   /* stack slot 02c2 */
  undefined1 stk_bac4;   /* stack slot bac4 */
  undefined1 stk_ffdc;   /* stack slot ffdc */
  undefined1 stk_ffde;   /* stack slot ffde */
  uint *puVar1;
  int *piVar2;
  uint8_t *puVar3;
  bool bVar4;
  uint32_t sheetPtr;
  uint32_t uVar6;
  far_t entries;
  ulong uVar7;
  ulong uVar8;
  byte bVar9;
  char cVar10;
  byte bVar11;
  int iVar12;
  uint32_t *puVar13;
  byte *pbVar14;
  uint uVar15;
  uint16_t uVar16;
  uint16_t randPick;
  uint uVar18;
  char *pcVar19;
  char in_CL;
  uint in_DX;
  uint uVar20;
  uint uVar21;
  entity_t *peVar22;
  unit_t *puVar23;
  int iVar24;
  int iVar25;
  uint16_t unaff_DI;
  uint16_t uVar26;
  uint16_t in_stack_0000000a;
  char acStackY_13e [36];
  uint16_t auStackY_11a [66];
  uint16_t auStackY_96 [23];
  char acStackY_68 [2];
  undefined1 auStackY_66 [56];
  byte bStackY_2e;
  byte bStackY_2d;
  uint16_t uStackY_2c;
  uint16_t uStackY_2a;
  uint16_t in_stack_0000ffd8;
  undefined1 uVar27;
  undefined1 uVar28;
  undefined1 uVar29;
  undefined1 uVar30;
  undefined1 uVar31;
  undefined1 uVar32;
  undefined1 uVar33;
  undefined1 uVar34;
  uint uStack_10;
  byte bldType;
  uint uStack_c;
  uint16_t uStack_a;
  uint16_t uStack_8;
  byte far *uStack_6;   /* was uint32_t: assigned byte * values */
  
  uStack_10 = 0;
  uStack_a = ovr_alignUp4(GfxRndSeed,0,0);
  for (iVar24 = 0; iVar24 < 4; iVar24 = iVar24 + 1) {
    in_DX = 0x2410;
    uStack_10 = uStack_10 |
                ((short (*) [60] [148])GMapFlags)[-1][GfxRndSeed2 + 0x3b][uStack_a + iVar24 + 0x92]
                & 0x3000U;
  }
  cursorRecordFound = '\0';
  _fmemset(MK_FP(_DS, 0x91d7), 0xFF, 8);
  uVar29 = 0;
  uVar30 = 0x10;
  uVar27 = 0x5e;
  uVar28 = 0x60;
  _fmemset(MK_FP(_DS, 0x90ea), 0, 4);
  for (uStack_c = 0; uStack_c < GRecordCount; uStack_c = uStack_c + 1) {
    in_DX = 0x2410;
    if ((GRecords[uStack_c].y == GfxRndSeed2) &&
       (in_DX = _DS, (GRecords[uStack_c].kind & 1) != 0)) {
      bVar9 = GRecords[uStack_c].width;
      uStack_6 = (byte *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),bVar9);
      iVar24 = GRecords[uStack_c].x - (GfxRndSeed + -2);
      in_DX = (iVar24 + (uint)bVar9) - 1;
      if ((0 < (int)(iVar24 + (uint)bVar9)) && (iVar24 < 4)) {
        if (20000 < GRecords[uStack_c].buildTimer) {
          GRecords[uStack_c].buildTimer = 3;
        }
        in_DX = _DS;
        for (iVar25 = 0; iVar25 < (int)(uint)bVar9; iVar25 = iVar25 + 1) {
          if (((SCARRY2(iVar25,iVar24) == iVar25 + iVar24 < 0) && (iVar25 + iVar24 < 4)) &&
             (*(uint *)((iVar25 + iVar24) * 2 + -0x6e29) = uStack_c, in_DX = uStack_c, 0 < iVar25))
          {
            *(undefined1 *)(iVar24 + iVar25 + -0x6f16) = 1;
          }
        }
        cursorRecordFound = '\x01';
      }
    }
  }
  CurSfxType3 = 0xff;
  if (((byte *)(uint)GOngoingBattle != (byte *)0x0) || (uStack_10 == 0x3000)) {
    return (byte *)(uint)GOngoingBattle;
  }
  if (cursorRecordFound != '\0') {
    CurSfxType3 = 0x70;
    return (byte *)((char *)0x2410);
  }
  uStack_6 = (byte *)((ulong)uStack_6 & 0xffffff);
  iVar24 = 0;
  (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)(unsigned long)(byte *)CONCAT11(0xff,(char)uStack_6);
  uStack_8 =(uint16_t)(unsigned long)(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) << 8);
  for (iVar25 = -2; cVar10 = (char)unaff_DI, iVar25 < 2; iVar25 = iVar25 + 1) {
    uVar15 = ovr_ovc45_getUnitIndex(GfxRndSeed + iVar25);
    bVar11 = ovr_ovc45_getUnitType(GfxRndSeed + iVar25);
    uVar7 = (ulong)uStack_6;
    uStack_8 =(uint16_t)(unsigned long)(byte *)CONCAT11(bVar11,(byte)(uint16_t)(unsigned long)(uStack_8));
    uVar26 = (uint16_t)((ulong)GUnits >> 0x10);
    puVar23 = (unit_t *)GUnits;
    bVar9 = puVar23[uVar15].unitType;
    (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(bVar9,(byte *)uStack_6);
    uStack_6 = (byte *)(ulong)(uint3)uStack_6;
    uVar8 = (ulong)uStack_6;
    uStack_6 = (byte *)uVar8;
    if (((0xf7 < uVar15) && (bVar9 != 0xff)) &&
       ((*(char *)((int)*(uint32_t *)((uint)bVar9 << 2) + 0x3f) == '\0' &&
        ((*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) = SUB41(uVar7,1), bVar4 = puVar23[uVar15].level <= (*(uint8_t *)((uint8_t *)&(uStack_6) + 1)), bVar4))))
    {
      (*(uint8_t *)((uint8_t *)&(uStack_6))) = (char)uVar7;
      (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)(unsigned long)(byte *)CONCAT11(puVar23[uVar15].level,(char)uStack_6);
      uStack_6 = (byte *)(ulong)CONCAT12(bVar9,(byte *)uStack_6);
    }
    uVar7 = (ulong)uStack_6;
    if ((*(char *)((int)*(uint32_t *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 2)) << 2) + 0x3f) == '\0') &&
       (puVar23[uVar15].unitType != 0xff)) {
      iVar24 = iVar24 + (uint)BuildingTypes[bVar11].size;
    }
    cVar10 = BuildingTypes[bVar11].sfxType;
    uStack_6 = (byte *)CONCAT13(cVar10,(uint3)uStack_6);
    in_DX = 0x2410;
    if (((5 < puVar23[uVar15].level) && (cVar10 == -0x7a)) &&
       ((*(uint8_t *)((uint8_t *)&(uStack_8))) = (byte)(uint16_t)(unsigned long)(uStack_8) + 1, uStack_8 = (uint16_t)(unsigned long)(byte *)CONCAT11(bVar11,(byte)(uint16_t)(unsigned long)(uStack_8)),
       (byte)(uint16_t)(unsigned long)(uStack_8) < 2)) {
      uStack_6 = (byte *)uVar7;
    }
    if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) != 0x0) {
      if (CurSfxType3 == 0xff) {
        in_DX = CONCAT11(0x24,(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)));
        CurSfxType3 = (*(uint8_t *)((uint8_t *)&(uStack_6) + 3));
      }
      else {
        uVar16 = ovr_randBelow(2,0);
        if ((uVar16 & 0xff) == 0) {
          in_DX = CONCAT11((char)(in_DX >> 8),(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)));
          CurSfxType3 = (*(uint8_t *)((uint8_t *)&(uStack_6) + 3));
        }
      }
    }
  }
  if (((uStack_10 == 0x1000) && (CurSfxType3 == 0xff)) && ((*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) != 0xff)) {
    if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) < 5) {
      CurSfxType3 = 0x61;
    }
    else if (2 < iVar24) {
      CurSfxType3 = 0x5e;
    }
  }
  if (CurSfxType3 != 0xff) {
    return (byte *)((char *)0x2410);
  }
  uVar31 = 0xca;
  uVar32 = 99;
  uVar15 = ovr_constr_usesGMapFlags2(GfxRndSeed);
  pbVar14 = (byte *)(uVar15 & 0xff);
  if ((byte *)__C0_ASM_CopyRight < pbVar14) {
    return pbVar14;
  }
  switch((uint16_t)pbVar14)   /* hand fix: case values are ints */ {
  case (uint16_t)0x0:
    *(char *)((int)pbVar14 * 2) = *(char *)((int)pbVar14 * 2) + (char)(in_DX >> 8);
    uStack_c = (uint)(byte)((byte)uVar15 & (byte)*(uint16_t *)(&stk_02c2 + iVar24));
    uVar16 = ovr_randBelow(in_stack_0000ffd8,0);
    randPick = ovr_randBelow(uStackY_2c,0);
    uStack_6 = (byte *)(CONCAT22(randPick,(byte *)uStack_6) & 0xffffff);
    uVar33 = 0x83;
    uVar34 = 0x9a;
    randPick = ovr_randBelow(in_stack_0000ffd8,0);
    uStack_6 = (byte *)(CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),randPick) & 0xffff00ff);
    if ((uVar16 & 0xff) < uStack_c) {
      uVar15 = (uint)(*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) / (uint)((byte *)uStack_6 + 1);
      uStack_10 = 1;
    }
    else {
      if ((byte *)uStack_6 <= (*(uint16_t *)((uint8_t *)&(uStack_6) + 2))) {
        return (*(uint16_t *)((uint8_t *)&(uStack_6) + 2));
      }
      uVar15 = (uint)(byte *)uStack_6 / (uint)((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) + 1);
      uStack_10 = 0;
    }
    pbVar14 = (byte *)(uVar15 + 1);
    uStack_8 =(uint16_t) pbVar14;
    if ((byte *)((int)(uint32_t *)&_DATA + 2) < pbVar14) {
      uStack_8 =(uint16_t)(unsigned long)(byte *)((int)(uint32_t *)&_DATA + 2);
    }
    bStackY_2d = 0xff;
    bStackY_2e = 0;
    iVar25 = -1;
    uStack_a = -1;
    iVar24 = CONCAT11(uVar34,uVar33);
    break;
  case (uint16_t)0x1:
    TextBlitX = in_DX - (int)pbVar14;
    ovr_blitLabel((char *)"UNITS");
    iVar25 = ovr_font_textWidth((char *)"POPULATION",0,0,0,0);
    uVar16 = 0xd4 - iVar25;
    TextBlitX = uVar16;
    ovr_blitLabel((char *)"POPULATION");
    for (iVar25 = 0; TextBlitY = TextBlitY + 0xc, iVar25 < (int)(uStack_c >> 8); iVar25 = iVar25 + 1
        ) {
      TextBlitX = 0x11;
      if ((iVar25 < 5) || ((char)uStack_c == '\0')) {
        ovr_blitLabel((char *)auStackY_96[iVar25 * 2]);
      }
      else {
        sheetPtr = *(uint32_t *)((partyIndex & 0xff) << 2);
        ovr_blitLabel((char *)auStackY_11a[iVar25 * 2 + (uint)*(byte *)((int)sheetPtr + 0x2f) * 8]);
      }
      ovc27_textCharmed();
      ovr_stsprintf(acStackY_13e);
      iVar12 = ovr_font_textWidth(acStackY_13e,0,0,0,0);
      TextBlitX = 0x89 - iVar12;
      ovr_blitLabel(acStackY_13e);
      ovr_stsprintf(acStackY_13e);
      iVar12 = ovr_font_textWidth(acStackY_13e,0,0,0,0);
      uVar16 = 0xd4 - iVar12;
      TextBlitX = uVar16;
      ovr_blitLabel(acStackY_13e);
    }
    CurSfxType3 = 0x3c;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = (char)_SS;
    entries.ofs = (uint16_t)auStackY_66;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = (char)((uint)_SS >> 8);
    uVar26 = ovr_ovc28_usesUiInputText(entries,0,0,0,0,0);
    cVar10 = (char)uVar26;
    keyboardInputMode = 0;
    if (((cVar10 != '\0') && (cVar10 != '\x01')) && (cVar10 != -2)) {
      (&stk_bac4)[iVar24] = (&stk_bac4)[iVar24] + in_CL;
      iVar24 = 0x2410;
      do {
        iVar12 = iVar24 * uVar16;
        iVar24 = iVar25;
        if (Agnts[iVar25].strengthMax < *(byte *)(iVar12 + 0x21)) {
          Agnts[iVar25].strength = Agnts[iVar25].strengthMax;
        }
        do {
          iVar24 = iVar24 + 1;
          if ((int)(uint)AgntCount <= iVar24) {
            iVar24 = ovr_audio_panFromX(agnt,0);
            uVar27 = (undefined1)((uint)iVar24 >> 8);
            ovr_play_sfxU(0x1c,0,0,0,0);
            return (byte *)CONCAT11(uVar27,1);
          }
        } while (Agnts[iVar24].owner != agnt->owner);
        uVar26 = (uint16_t)((ulong)uStack_6 >> 0x10);
        if (*(byte *)((int)uStack_6 + 0x32) < Agnts[iVar24].strengthMax) {
          Agnts[iVar24].strengthMax = *(undefined1 *)((int)uStack_6 + 0x32);
        }
        uVar16 = 0x34;
        iVar25 = iVar24;
      } while( true );
    }
    if (cVar10 == -2) {
      Cancelled = 1;
    }
    return (byte *)((char *)0x2410);
  case (byte *)0x2:
    pbVar14 = (byte *)(partyIndex * 0x37);
    if (*(char *)((int)&((entity_t *)Entities)[partyIndex].base.entity + 3) != -1) {
      bVar9 = ovr_agnt_compute10(&((entity_t *)Entities)[partyIndex].base,0);
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = (uint3)bVar9 << 8;
      uVar27 = *(undefined1 *)((int)&((entity_t *)Entities)[partyIndex].base.entity + 3);
      pbVar14 = (byte *)CONCAT11((char)(partyIndex * 0x37 >> 8),uVar27);
      uStack_6 = (byte *)CONCAT13(uVar27,(uint3)uStack_6);
      while (cVar10 = (char)uStack_6, (char)uStack_6 < '\x04') {
        pbVar14 = (byte *)((char)uStack_6 * 2);
        if (*(int *)(pbVar14 + (int)*(uint32_t *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) << 2) + 0x76) != 0) {
          pbVar14 = (byte *)(int)(char)(*(uint8_t *)((uint8_t *)&(uStack_6) + 1));
          if ((int)pbVar14 < (char)uStack_6 + 1) {
            (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = (char)uStack_6;
            piVar2 = (int *)((int)*(uint32_t *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) << 2) + (char)uStack_6 * 2 +
                            0x76);
            *piVar2 = *piVar2 + -1;
            uVar26 = (uint16_t)((ulong)Entities >> 0x10);
            peVar22 = (entity_t *)Entities;
            peVar22[partyIndex].dir =
                 peVar22[partyIndex].dir + (char)(((ulong)peVar22[partyIndex].dir / 6) % 6) * -6;
            bVar9 = ((entity_t *)Entities)[partyIndex].base.gindex;
            (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(bVar9,(byte *)uStack_6);
            if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar9 * 0x95) == '\x03') &&
               ('\x01' < cVar10)) {
              (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = '\x01';
            }
            if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar9 * 0x95) == '\x01') &&
               ('\x02' < (char)(*(uint8_t *)((uint8_t *)&(uStack_8) + 1)))) {
              (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = '\x02';
            }
            cVar10 = ovc22_compute3((*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) + '\x01');
            uVar26 = (uint16_t)((ulong)Entities >> 0x10);
            bVar9 = ((entity_t *)Entities)[partyIndex].dir + cVar10 * '\x06';
            ((entity_t *)Entities)[partyIndex].dir = bVar9;
            return (byte *)CONCAT11((char)(partyIndex * 0x37 >> 8),bVar9);
          }
        }
        uStack_6 = (byte *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),(char)uStack_6 + '\x01');
      }
    }
    return pbVar14;
  case (byte *)0x3:
    do {
      if ((GLeaderSheets[uStack_a])->unitsOnTile < 10) {
        ovc25_usesAlignUp43((byte)uStack_a,10,
                            (GLeaderSheets[uStack_a])->x,
                            (GLeaderSheets[uStack_a])->y,'\0');
        (GLeaderSheets[uStack_a])->reportState = 0;
      }
      else {
        (GLeaderSheets[uStack_a])->reportState = 0;
        iVar25 = ovc25_compute1((GLeaderSheets[uStack_a])->classStr);
        uStack_6 = (byte *)CONCAT22(iVar25,(byte *)uStack_6);
        if ((int)(uint)PlayerCount < iVar25) {
          uVar16 = ovr_randBelow(0x28,0);
          iVar25 = (GLeaderSheets[uStack_a])->x + -0x14 + (uVar16 & 0xff);
          (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)(unsigned long)(byte *)iVar25;
          if (iVar25 < 4) {
            (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)(unsigned long)(byte *)0x4;
          }
          if (0x8c < (int)(byte *)uStack_6) {
            uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),0x8b);
          }
          uVar16 = ovr_randBelow(0x14,0);
          uStack_8 =(uint16_t)( (byte *)((GLeaderSheets[uStack_a])->y + -10 +
                             (uVar16 & 0xff)));
          if ((int)uStack_8 < 1) {
            uStack_8 =(uint16_t)(unsigned long)(byte *)0x1;
          }
          if (0x3a < (int)uStack_8) {
            uStack_8 =(uint16_t)(unsigned long)(byte *)0x3a;
          }
          ovr_ovc25_usesAlignUp44((char)uStack_a,1);
        }
      }
      while( true ) {
        while( true ) {
          do {
            uStack_a = uStack_a + 1;
            pbVar14 = (byte *)(uint)GLeaderCount;
            if ((int)pbVar14 <= (int)uStack_a) {
              ovc25_clearEntityFlags();
              return pbVar14;
            }
          } while ((*(char *)((int)*(uint32_t *)(uStack_a * 4) + 0x40) == '\0') ||
                  (((char_sheet_t *)((uStack_a * 4)))->active == '\0'));
          ovc25_intelAttackingNotice((byte)uStack_a);
          if ((GLeaderSheets[uStack_a])->nearestEnemy == -1) {
            uVar15 = 0xffff;
          }
          else {
            iVar24 = (GLeaderSheets[uStack_a])->nearestEnemy;
            uVar26 = (uint16_t)((ulong)Entities >> 0x10);
            uVar15 = (GLeaderSheets[uStack_a])->x -
                     (((entity_t *)Entities + iVar24)->base).x;
            uVar20 = (int)uVar15 >> 0xf;
            uVar18 = (GLeaderSheets[uStack_a])->y -
                     ((entity_t *)Entities)[iVar24].base.y;
            uVar21 = (int)uVar18 >> 0xf;
            uVar15 = (int)((uVar15 ^ uVar20) - uVar20) / 2 + ((uVar18 ^ uVar21) - uVar21);
          }
          if (((GLeaderSheets[uStack_a])->enemiesNear == 0) || (9 < uVar15)) break;
          ovc25_usesEntityCount((byte)uStack_a);
          if (9 < (GLeaderSheets[uStack_a])->unitsOnTile) {
            uVar26 = (uint16_t)((ulong)Entities >> 0x10);
            ovc25_usesAlignUp43((byte)uStack_a,5,(((entity_t *)Entities + iVar24)->base).x,
                                ((entity_t *)Entities)[iVar24].base.y,'\x01');
          }
          ovc25_usesAlignUp43((byte)uStack_a,10,
                              (GLeaderSheets[uStack_a])->x,
                              (GLeaderSheets[uStack_a])->y,'\0');
          (GLeaderSheets[uStack_a])->reportState = 1;
        }
        if ((*(char *)((int)*(uint32_t *)(uStack_a << 2) + 0x49) == -1) ||
           (((GLeaderSheets[uStack_a])->flags5d & 1) == 0)) break;
        ovc25_usesEntityCount((byte)uStack_a);
        bVar9 = *(byte *)((int)*(uint32_t *)(uStack_a << 2) + 0x49);
        if (0xe < (GLeaderSheets[uStack_a])->unitsOnTile) {
          ovc25_usesAlignUp42((byte)uStack_a,10,
                              (GLeaderSheets[bVar9])->x,
                              (GLeaderSheets[bVar9])->y,
                              (GLeaderSheets[uStack_a])->x,
                              (GLeaderSheets[uStack_a])->y);
          if ((GLeaderSheets[uStack_a])->reportState != '\x02') {
            ovr_alignUp4((GLeaderSheets[bVar9])->x,0,0);
            uStackY_2a = 0x2379;
            uStackY_2c = 0xc5d4;
            pcVar19 = ovr_stsprintf(acStackY_68,(char *)CONCAT22(0x58c0,_SS));
            ovr_uiNotify(pcVar19,0,0);
          }
        }
        ovc25_usesAlignUp43((byte)uStack_a,0xf,
                            (GLeaderSheets[uStack_a])->x,
                            (GLeaderSheets[uStack_a])->y,'\0');
        (GLeaderSheets[uStack_a])->reportState = 2;
      }
    } while( true );
  case (byte *)0x4:
    if ((byte)uStack_8 < ListCount) {
      uVar26 = (uint16_t)((ulong)GUnits >> 0x10);
      uStack_a = ((unit_t *)GUnits)[*(int *)(((uint)uStack_8 & 0xff) * 2 + -0x6d44)].x;
      uStack_c = ((unit_t *)GUnits)[*(int *)(((uint)uStack_8 & 0xff) * 2 + -0x6d44)].y;
    }
    else {
      sheetPtr = *(uint32_t *)((partyIndex & 0xff) << 2);
      uStack_a = *(uint16_t *)((int)sheetPtr + 0x39);
      sheetPtr = *(uint32_t *)((partyIndex & 0xff) << 2);
      uStack_c = *(uint16_t *)((int)sheetPtr + 0x3b);
    }
    sheetPtr = *(uint32_t *)((partyIndex & 0xff) << 2);
    uVar26 = (uint16_t)((ulong)sheetPtr >> 0x10);
    iVar25 = (int)sheetPtr;
    iVar24 = *(int *)(iVar25 + 0x58);
    if ((iVar24 < 1) && ((iVar24 < 0 || (*(uint *)(iVar25 + 0x56) < 10)))) {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(byte *)uStack_6);
    }
    else {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((byte *)uStack_6);
    }
    sheetPtr = *(uint32_t *)((partyIndex & 0xff) << 2);
    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)*(byte *)((int)sheetPtr + 0x3e) * 0x95) &
        0x80) == 0) {
      uStack_6 = (byte *)(ulong)(uint3)uStack_6;
    }
    else {
      uStack_6 = (byte *)CONCAT13(3,(uint3)uStack_6);
    }
    sheetPtr = *(uint32_t *)((partyIndex & 0xff) << 2);
    if ((*(byte *)((int)sheetPtr + 0x5d) & 2) != 0) {
      uStack_6 = (byte *)((ulong)uStack_6 | 0x1000000);
    }
    puVar13 = (uint32_t *)((partyIndex & 0xff) << 2);
    sheetPtr = *puVar13;
    if ((*(byte *)((int)sheetPtr + 0x5d) & 4) != 0) {
      uStack_6 = (byte *)((ulong)uStack_6 | 0x2000000);
    }
    uVar15 = ovc22_searchCellsAround
                       ((uint *)CONCAT13((char)((uint)&uStack_c >> 8),
                                         CONCAT12((char)&uStack_c,_SS)),
                        (uint *)CONCAT13((char)((uint)puVar13 >> 8),
                                         CONCAT12((byte)partyIndex,_SS)),(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)),
                        (*(uint8_t *)((uint8_t *)&(uStack_6) + 2)),cVar10);
    pbVar14 = (byte *)(uVar15 & 0xff);
    if (pbVar14 != (byte *)0x0) {
      if (pbVar14 != (byte *)((int)(uint32_t *)&_DATA + 1U)) {
        return pbVar14;
      }
      uVar15 = ovc22_usesRandBelow((byte)partyIndex,uStack_a,uStack_c);
      if (uVar15 == 0) {
        sheetPtr = *(uint32_t *)((partyIndex & 0xff) << 2);
        uStack_a = *(uint16_t *)((int)sheetPtr + 0x39);
        sheetPtr = *(uint32_t *)((partyIndex & 0xff) << 2);
        uStack_c = *(uint16_t *)((int)sheetPtr + 0x3b);
      }
      else {
        if ((*(uint *)((uint8_t *)&BuildingTypes[uVar15] + 19) & 0x60) == 0) {
          sheetPtr = *(uint32_t *)((partyIndex & 0xff) << 2);
          uVar26 = (uint16_t)((ulong)sheetPtr >> 0x10);
          iVar25 = (int)sheetPtr;
          iVar24 = *(int *)(iVar25 + 0x58);
          if ((iVar24 < 0) ||
             ((iVar24 == 0 && (*(uint *)(iVar25 + 0x56) < *(uint *)((uint8_t *)&BuildingTypes[uVar15] + 23))))) {
            sheetPtr = *(uint32_t *)((partyIndex & 0xff) << 2);
            uVar26 = (uint16_t)((ulong)sheetPtr >> 0x10);
            iVar24 = (int)sheetPtr;
            *(uint16_t *)(iVar24 + 0x58) = 0;
            *(uint16_t *)(iVar24 + 0x56) = 0;
          }
          else {
            uVar20 = *(uint *)((uint8_t *)&BuildingTypes[uVar15] + 23);
            sheetPtr = *(uint32_t *)((partyIndex & 0xff) << 2);
            uVar26 = (uint16_t)((ulong)sheetPtr >> 0x10);
            iVar24 = (int)sheetPtr;
            puVar1 = (uint *)(iVar24 + 0x56);
            uVar18 = *puVar1;
            *puVar1 = *puVar1 - uVar20;
            piVar2 = (int *)(iVar24 + 0x58);
            *piVar2 = *piVar2 - (uint)(uVar18 < uVar20);
          }
        }
        bldType = (byte)uVar15;
        ovr_createConstructionRecordFar(bldType,0,0,0,0,0,0,0,0);
      }
    }
    sheetPtr = *(uint32_t *)((partyIndex & 0xff) << 2);
    if (*(char *)((int)sheetPtr + 0x3f) == '\0') {
      sheetPtr = *(uint32_t *)((partyIndex & 0xff) << 2);
      uVar6 = *(uint32_t *)((partyIndex & 0xff) << 2);
      if (*(uint *)((int)sheetPtr + 0x5b) < *(uint *)((int)uVar6 + 0x4d)) {
        pbVar14 = (byte *)ovr_ovc18_textTypeLen((byte)partyIndex,0,0,0,0,0);
      }
      else {
        pbVar14 = (byte *)ovr_ovc18_textTypeLen((byte)partyIndex,0,0,0,0,0);
      }
    }
    else {
      pbVar14 = (byte *)ovr_ovc18_textTypeLen((byte)partyIndex,0,0,0,0,0);
    }
    return pbVar14;
  }
  do {
    if (CONCAT11(uVar32,uVar31) < iVar24) {
      if (uStack_a != -1) {
        if (iVar25 == -1) {
          ovr_attact_usesRandBelow(&Entities[uStack_a].base,(byte)((ulong)Entities >> 0x10),0,0);
          ovr_attact_usesEntities(uStack_a,0,0,0,0,0,0,0,0);
          uVar26 = (uint16_t)((ulong)Entities >> 0x10);
          bVar9 = ((entity_t *)Entities)[uStack_a].base.gindex;
          pbVar14 = (byte *)(uint)AgntGs[(uint)bVar9].ai;
          if (pbVar14 == (byte *)0x0) {
            alignUp4((((entity_t *)Entities + iVar24)->base).x,0,0);
            uVar26 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + (uint)bVar9 * 0x95);
            pbVar14 = (byte *)ovr_fmVsprintf("Intelligence reports %s unit fleeing from battle. (%d, %d)"
                                             ,(char *)CONCAT13((char)((uint)uVar26 >> 8),
                                                               CONCAT12((char)uVar26,
                                                                        *(uint16_t *)
                                                                         ((int)&worldMenuLabels[0].
                                                                                seg + 1 +
                                                                         (uint)bVar9 * 0x95))));
            ovr_uiNotify((char *)pbVar14,0,0);
          }
        }
        else {
          if ((byte *)(uint)Entities[iVar25].base.animFrame <= uStack_8) {
            uStack_8 =(uint16_t)(unsigned long)(byte *)(uint)Entities[iVar25].base.animFrame;
          }
          Entities[iVar25].base.animFrame = Entities[iVar25].base.animFrame - (byte)uStack_8;
          ovr_ovc41_compute4(&Entities[iVar25].base,(byte)((ulong)Entities >> 0x10),0,0,0,0,0,0);
          ovr_ovc25_attackingNotice
                    (*(byte *)((int)&((entity_t *)Entities)[iVar25].base.entity + 3));
          pbVar14 = (byte *)(iVar25 * 0x37);
          if (((entity_t *)Entities)[iVar25].base.animFrame != 0x0) {
            ovc24_usesLDIV_at_(iVar25);
            uVar26 = (uint16_t)((ulong)Entities >> 0x10);
            peVar22 = (entity_t *)Entities;
            if ((((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                            (uint)peVar22[uStack_a].base.gindex * 0x95) & 4) != 0) &&
                ((*(uint *)((int)&peVar22[iVar25].base.frames + 1) & 1) == 0)) &&
               (uVar15 = ovr_ovc27_rollToHitAgent
                                   (CONCAT13((char)((ulong)Entities >> 0x18),
                                             CONCAT12((char)((ulong)Entities >> 0x10),
                                                      peVar22 + iVar25)),0), (uVar15 & 0xff) == 0))
            {
              puVar1 = (uint *)((int)&((entity_t *)Entities)[iVar25].base.frames + 1);
              *puVar1 = *puVar1 | 1;
              alignUp4((((entity_t *)Entities + iVar24)->base).x,0,0);
              iVar12 = (uint)((entity_t *)Entities)[iVar25].base.gindex * 0x95;
              uVar26 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar12);
              pcVar19 = ovr_fmVsprintf("Intelligence reports %s unit infected with disease. (%d, %d)"
                                       ,(char *)CONCAT13((char)((uint)uVar26 >> 8),
                                                         CONCAT12((char)uVar26,
                                                                  *(uint16_t *)
                                                                   ((int)&worldMenuLabels[0].seg + 1
                                                                   + iVar12))));
              ovr_uiNotify(pcVar19,0,0);
            }
            pbVar14 = (byte *)((uint)((entity_t *)Entities)[uStack_a].base.gindex * 0x95);
            if ((*(uint *)(pbVar14 + 0x2714) & 0xc00) != 0) {
              uVar15 = ovr_ovc27_rollToHitAgent
                                 (CONCAT13((char)((ulong)Entities >> 0x18),
                                           CONCAT12((char)((ulong)Entities >> 0x10),
                                                    (entity_t *)Entities + iVar25)),3);
              pbVar14 = (byte *)(uVar15 & 0xff);
              if (pbVar14 == (byte *)0x0) {
                if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                              (uint)((entity_t *)Entities)[uStack_a].base.gindex * 0x95) & 0x800)
                    == 0) {
                  cVar10 = '\x01';
                }
                else {
                  cVar10 = '\x02';
                }
                uVar26 = ovr_ovc27_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                                     CONCAT12((char)((ulong)Entities >> 0x10),
                                                              (entity_t *)Entities + iVar25)),
                                            cVar10);
                if ((char)uVar26 != '\0') {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  uVar26 = (uint16_t)((ulong)Entities >> 0x10);
                  if (((entity_t *)Entities)[iVar25].base.animFrame != 0x0) {
                    puVar3 = &((entity_t *)Entities)[iVar25].base.animFrame;
                    *puVar3 = *puVar3 + 0xff;
                  }
                }
                alignUp4((((entity_t *)Entities + iVar24)->base).x,0,0);
                iVar24 = (uint)((entity_t *)Entities)[iVar25].base.gindex * 0x95;
                uVar26 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar24);
                pbVar14 = (byte *)ovr_fmVsprintf("Intelligence reports %s unit drained of energy. (%d, %d)"
                                                 ,(char *)CONCAT13((char)((uint)uVar26 >> 8),
                                                                   CONCAT12((char)uVar26,
                                                                            *(uint16_t *)
                                                                             ((int)&worldMenuLabels
                                                                                    [0].seg + 1 +
                                                                             iVar24))));
                ovr_uiNotify((char *)pbVar14,0,0);
              }
            }
          }
        }
      }
      return pbVar14;
    }
    pbVar14 = (byte *)Entities[iVar24].base.y;
    if ((pbVar14 != (byte *)CONCAT11(uVar28,uVar27)) ||
       (pbVar14 = (byte *)alignUp4(((Entities + iVar24)->base).x,0,0),
       pbVar14 != (byte *)CONCAT11(uVar30,uVar29))) goto L_OVC24_5943_026e_08A7;
    uVar26 = (uint16_t)((ulong)Entities >> 0x10);
    peVar22 = (entity_t *)Entities;
    if (AgntGs[(uint)peVar22[iVar24].base.gindex].ai ==
        (char)uStack_10) {
      if (peVar22[iVar24].base.level < bStackY_2d) {
L_OVC24_5943_026e_0772:
        uVar26 = (uint16_t)((ulong)Entities >> 0x10);
        bVar9 = ((entity_t *)Entities)[iVar24].base.gindex;
        if ((((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)bVar9 * 0x95) & 0x40) == 0) ||
            (pbVar14 = &stk_ffde + (uStack_10 ^ 1), '\x01' < (char)*pbVar14)) &&
           ((((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar9 * 0x95) & 8) == 0 ||
             (pbVar14 = &stk_ffde + (uStack_10 ^ 1), '\0' < (char)*pbVar14)) &&
            (((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar9 * 0x95) & 0x10) == 0 ||
             (pbVar14 = &stk_ffdc + (uStack_10 ^ 1), -1 < (char)*pbVar14)))))) {
          bStackY_2d = ((entity_t *)Entities)[iVar24].base.level;
          pbVar14 = (byte *)CONCAT11((char)((uint)(iVar24 * 0x37) >> 8),bStackY_2d);
          iVar25 = iVar24;
        }
      }
      else {
        bVar9 = peVar22[iVar24].base.level;
        pbVar14 = (byte *)CONCAT11((char)((uint)(iVar24 * 0x37) >> 8),bVar9);
        if (bVar9 == bStackY_2d) {
          uVar16 = ovr_randBelow(3,0);
          pbVar14 = (byte *)(uVar16 & 0xff);
          if (pbVar14 == (byte *)0x0) goto L_OVC24_5943_026e_0772;
        }
      }
    }
    else if (bStackY_2e < peVar22[iVar24].base.level) {
L_OVC24_5943_026e_088A:
      bStackY_2e = ((entity_t *)Entities)[iVar24].base.level;
      pbVar14 = (byte *)CONCAT11((char)((uint)(iVar24 * 0x37) >> 8),bStackY_2e);
      uStack_a = iVar24;
    }
    else {
      bVar9 = peVar22[iVar24].base.level;
      pbVar14 = (byte *)CONCAT11((char)((uint)(iVar24 * 0x37) >> 8),bVar9);
      if (bVar9 == bStackY_2e) {
        uVar16 = ovr_randBelow(3,0);
        pbVar14 = (byte *)(uVar16 & 0xff);
        if (pbVar14 == (byte *)0x0) goto L_OVC24_5943_026e_088A;
      }
    }
L_OVC24_5943_026e_08A7:
    iVar24 = iVar24 + 1;
  } while( true );
}


/* 55fe:0487 */

/* Stamps GameTick on the records overlapping a column and counts down their timers. */

undefined1 __cdecl16far ovc23_tickRecordsAt(uint16_t x,int y,char excluded,uint16_t arg4)

{
  char *pcVar1;
  byte bVar2;
  uint32_t uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 uStack_3;
  
  uVar4 = ovr_alignUp4(x,0,0);
  uStack_3 = 0;
  for (uVar5 = 0; uVar5 < GRecordCount; uVar5 = uVar5 + 1) {
    if ((((GRecords[uVar5].y == y) && (GRecords[uVar5].x <= uVar4 + 1)) &&
        (uVar4 - 2 <= (GRecords[uVar5].x + (uint)GRecords[uVar5].width) - 1)) &&
       ((bVar2 = GRecords[uVar5].party, bVar2 != 0xff &&
        (uVar3 = *(uint32_t *)((uint)bVar2 << 2), *(char *)((int)uVar3 + 0x3f) == excluded)))) {
      GRecords[uVar5].tick = GameTick;
      if (GRecords[uVar5].countdown != '\0') {
        pcVar1 = (char *)&GRecords[uVar5].countdown;
        *pcVar1 = *pcVar1 + -1;
      }
      if (GRecords[uVar5].countdown == '\0') {
        GRecords[uVar5].state = 1;
      }
      uStack_3 = 1;
    }
  }
  return uStack_3;
}



/* 55fe:05db */

/* Returns whether the point matches the cell in GfxRndSeed/GfxRndSeed2. */

bool __cdecl16far ovc23_isCursorAt(uint16_t x,int y)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = ovr_alignUp4(x,0,0);
  uVar2 = ovr_alignUp4(GfxRndSeed,0,0);
  if ((uVar1 == uVar2) && (uVar2 = GfxRndSeed2, GfxRndSeed2 == y)) {
    uVar2 = CONCAT11((char)(GfxRndSeed2 >> 8),1);
  }
  else {
    uVar2 = uVar2 & 0xff00;
  }
  return uVar2;
}



/* 55fe:0617 */

/* [R6] touches cornerBR, cornerBL */

int __cdecl16far ovc23_usesCornerBR(int x,int bldType)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int cornerSampleBR;
  int cornerSample;
  uint8_t cornerBR;
  uint8_t cornerBL;
  uint8_t cornerTR;
  uint8_t cornerTL;
  int iStack_4;
  
  iVar1 = ovr_constr_usesSmoothPrev(x,-1,(int *)&cornerTL,0,0);
  iVar2 = ovr_constr_usesSmoothPrev(x,0,(int *)&cornerBL,0,0);
  if (*(byte *)((uint8_t *)&BuildingTypes[bldType] + 13) < 2) {
    cornerSample = ovr_constr_usesSmoothPrev(x + 1,-1,(int *)&cornerTR,0,0);
    cornerSampleBR = ovr_constr_usesSmoothPrev(x + 1,0,(int *)&cornerBR,0,0);
  }
  else if (*(byte *)((uint8_t *)&BuildingTypes[bldType] + 13) < 3) {
    cornerSample = ovr_constr_usesSmoothPrev(x + 2,-1,(int *)&cornerTR,0,0);
    cornerSampleBR = ovr_constr_usesSmoothPrev(x + 2,0,(int *)&cornerBR,0,0);
  }
  else {
    cornerSample = ovr_constr_usesSmoothPrev(x + 4,-1,(int *)&cornerTR,0,0);
    cornerSampleBR = ovr_constr_usesSmoothPrev(x + 4,0,(int *)&cornerBR,0,0);
  }
  uVar3 = (uint)cornerShadeBias[0];
  iStack_4 = iVar2 + iVar1 + cornerSample + cornerSampleBR >> 2;
  if ((int)(iVar1 - uVar3) < (int)(cornerSample - uVar3)) {
    iVar2 = iVar1 - uVar3;
  }
  else {
    iVar2 = cornerSample - uVar3;
  }
  if (iStack_4 < iVar2) {
    if ((int)(iVar1 - uVar3) < (int)(cornerSample - uVar3)) {
      iStack_4 = iVar1 - uVar3;
    }
    else {
      iStack_4 = cornerSample - uVar3;
    }
  }
  return iStack_4;
}



/* 55fe:0768 */

/* [R6] touches cornerBR, cornerBL */

int __cdecl16far ovc23_usesCornerBR2(int x,int step)

{
  int cornerSampleTL;
  int iVar2;
  int iStack_12;
  uint8_t cornerBR;
  uint8_t cornerBL;
  uint8_t cornerTR;
  uint8_t cornerTL;
  int cornerSampleBR;
  int cornerSampleTR;
  int cornerSampleBL;
  
  if (step == 4) {
    cornerSampleTL = ovr_constr_usesSmoothPrev(x + 1,-1,(int *)&cornerTL,0,0);
    cornerSampleBL = ovr_constr_usesSmoothPrev(x + 1,0,(int *)&cornerBL,0,0);
    cornerSampleTR = ovr_constr_usesSmoothPrev(x + 2,-1,(int *)&cornerTR,0,0);
    cornerSampleBR = ovr_constr_usesSmoothPrev(x + 2,0,(int *)&cornerBR,0,0);
  }
  else {
    cornerSampleTL = ovr_constr_usesSmoothPrev(x,-1,(int *)&cornerTL,0,0);
    cornerSampleBL = ovr_constr_usesSmoothPrev(x,0,(int *)&cornerBL,0,0);
    cornerSampleTR = ovr_constr_usesSmoothPrev(x + step,-1,(int *)&cornerTR,0,0);
    cornerSampleBR = ovr_constr_usesSmoothPrev(x + step,0,(int *)&cornerBR,0,0);
  }
  iStack_12 = cornerSampleBL + cornerSampleTL + cornerSampleTR + cornerSampleBR >> 2;
  iVar2 = cornerSampleTR;
  if (cornerSampleTL < cornerSampleTR) {
    iVar2 = cornerSampleTL;
  }
  if ((iStack_12 < iVar2) && (iStack_12 = cornerSampleTR, cornerSampleTL < cornerSampleTR)) {
    iStack_12 = cornerSampleTL;
  }
  return iStack_12;
}



/* 55fe:0863 */

/* [R2] string "build\\thfres01.lbm" */

void __cdecl16far ovc23_textBuildThfres01Lbm(far_t dst)

{
  uint16_t play_id;
  bool bVar1;
  byte bVar2;
  undefined1 extraout_AH;
  int iVar4;
  uint16_t unaff_SI;
  uint16_t unaff_DI;
  uint16_t uVar5;
  int iVar3;
  
  bVar1 = false;
  GAnimPlaying = 0;
  uVar5 = rowMapSquareFirst[0];
  while( true ) {
    if (rowMapSquareEnd[0] <= uVar5) break;
    play_id = *(uint16_t *)(&mapSquareColumn[uVar5]);
    if ((-3 < (int)play_id) && ((int)play_id < 2)) {
      bVar2 = ovr_constr_setHighlightAtOffset(play_id,0,0);
      iVar3 = CONCAT11(extraout_AH,bVar2);
      if (((char *)0x28048)[iVar3 * 3 + *(int *)(uVar5 * 2)] != '\0') {
        iVar4 = ovc23_usesCornerBR(play_id,iVar3);
        ovr_animAdvance(play_id,((char *)0x28048)
                                [iVar3 * 3 + *(int *)(uVar5 * 2)],*(uint16_t *)(&mapSquareLeftX[uVar5]),
                        (uint)bandOrigin[0] - iVar4,dst);
        bVar1 = true;
      }
      iVar3 = iRam0002d2d7;
      if (*(int *)(play_id * 2 + -0x6e25) != -1) {
        if (*(char *)(play_id + 0x90ec) == '\0') {
          iVar3 = *(int *)(play_id * 2 + -0x6e25);
          iVar4 = ovc23_usesCornerBR2(play_id,(uint)GRecords[iVar3].width);
          ovc23_usesBlitGfxRect2
                    ((uint)bandOrigin[0] - iVar4,iVar3,dst.ofs,(brect_t *)CONCAT22(unaff_DI,dst.seg)
                     ,unaff_SI);
          bVar1 = true;
        }
        else if (play_id == 0xfffe) {
          iVar4 = ovc23_usesCornerBR2(-2,(uint)GRecords[iRam0002d2d7].width);
          ovc23_usesBlitGfxRect2
                    ((uint)bandOrigin[0] - iVar4,iVar3,dst.ofs,(brect_t *)CONCAT22(unaff_DI,dst.seg)
                     ,unaff_SI);
          bVar1 = true;
        }
      }
    }
    uVar5 = uVar5 + 1;
  }
  if (bVar1) {
    ovr_constr_usesScreenOriginY(dst.ofs,dst.seg,0);
  }
  return;
}



/* 55fe:0a56 */

/* Returns whether the building at the cell has bldtp_t.size >= 2. */

int __cdecl16far ovc23_isLargeBuilding(int x,int y)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = (uint)((unit_t *)GUnits + ((short (*) [148] [60])GUnitGrid)[-1][x + 0x93][y])->bldType *
          0x27;
  bVar2 = (byte)((uint)iVar1 >> 8);
  if (*(byte *)(iVar1 + 0x11b) < 2) {
    iVar1 = (uint)bVar2 << 8;
  }
  else {
    iVar1 = CONCAT11(bVar2,1);
  }
  return iVar1;
}



/* 55fe:0aba */

/* [R6] touches GfxRndSeed2, GfxRndSeed */

void __cdecl16far ovc23_usesGfxRndSeed2(int x,int y)

{
  if (((GfxRndSeed2 == y) && (GfxRndSeed + -2 <= x)) && (x <= GfxRndSeed + 1)) {
    AgntClearFlag = true;
  }
  return;
}



/* 55fe:0af5 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00053af7) overlaps instruction at (ram,0x00053af6)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

uint * __cdecl16far ovc23_usesAlignUp43(int16_t x,uint16_t unitIndex,byte dir)

{
  undefined1 stk_8d06;   /* stack slot 8d06 */
  undefined1 stk_fff8;   /* stack slot fff8 */
  undefined1 stk_fffe;   /* stack slot fffe */
  uint8_t *puVar1;
  int *piVar2;
  uint *puVar3;
  byte *pbVar4;
  byte bVar5;
  short sVar6;
  uint32_t uVar7;
  far_t pctOut;
  far_t remainderOut;
  far_t partOut;
  bool bVar8;
  bool bVar9;
  byte bVar10;
  char cVar11;
  char *pcVar12;
  byte *pbVar13;
  undefined1 uVar17;
  uint16_t uVar14;
  long *plVar15;
  agnt_t *valueLo;
  uint *msg;
  uint uVar16;
  int in_CX;
  uint16_t uVar18;
  int iVar19;
  int leaderPtr;
  int leaderPtr2;
  int iVar22;
  entity_t *peVar23;
  entity_t *peVar24;
  unit_t *puVar25;
  uint16_t unaff_BP;
  uint uVar26;
  uint16_t unaff_SI;
  uint uVar27;
  char *unaff_DI;
  uint16_t uVar28;
  uint16_t uVar29;
  bool bVar30;
  uint uStackY_2e;
  int iStackY_2c;
  int iStackY_2a;
  byte bStackY_20;
  byte bStackY_1f;
  uint16_t uStackY_1e;
  uint16_t uStackY_1c;
  far_t table;
  undefined1 uVar31;
  undefined1 in_stack_0000ffea;
  uint *entityIndex;
  undefined1 in_stack_0000ffeb;
  uint uVar32;
  byte *pbVar33;
  uint16_t uVar34;
  uint16_t uVar35;
  uint16_t uVar36;
  uint16_t *puVar37;
  undefined1 uVar38;
  undefined1 uVar39;
  char *fmt;
  long a;
  uint16_t in_stack_0000fffc;
  long b;
  
  b = CONCAT22(unaff_BP,in_stack_0000fffc);
  fmt = (char *)CONCAT22(unaff_SI,unaff_DI);
  uVar18 = 0x2410;
  iVar19 = x + *(char *)(dir + 0x885);
  uVar16 = ovr_attact_usesGUnits(iVar19);
  uVar27 = CONCAT11(in_stack_0000ffeb,in_stack_0000ffea);
  if ((uVar16 & 0xff) == 0) {
    return (uint *)((int)(uint32_t *)&_DATA + 1);
  }
  uVar16 = (uint)dir;
  if (3 < uVar16) {
    return (uint *)0x0;
  }
  puVar25 = (unit_t *)(uVar16 * 2);
  switch(uVar16) {
  case 0:
    return (uint *)unitIndex;
  case 1:
    while( true ) {
      if (((&puVar25->flags)[uVar16] & 3) == 0) {
        uVar18 = (uint16_t)((ulong)GUnits >> 0x10);
        bVar10 = ((unit_t *)GUnits)[unitIndex].unitType;
        if ((bVar10 == 0xff) ||
           (uVar7 = *(uint32_t *)((uint)bVar10 << 2), *(char *)((int)uVar7 + 0x3f) == '\0')) {
          pcVar12 = (char *)0x24d;
        }
        else {
          pcVar12 = (char *)0x246dc;
        }
        fmt = (char *)CONCAT22((int)((ulong)fmt >> 0x10),pcVar12);
        if (((unit_t *)GUnits)[unitIndex].level != 0) {
          uVar35 = ovr_randBelow((uint16_t)pcVar12,0);
          uVar18 = (uint16_t)((ulong)GUnits >> 0x10);
          puVar25 = (unit_t *)GUnits;
          if ((int)(uVar35 & 0xff) <
              (int)(100 - (uint)*(byte *)((uint)(puVar25 + unitIndex)->bldType * 0x27 + 0x130))) {
            bStackY_20 = (puVar25 + unitIndex)->bldType;
            puVar25[unitIndex].level = puVar25[unitIndex].level - 1;
            puVar25 = (unit_t *)GUnits;
            uVar18 = (uint16_t)((ulong)GUnits >> 0x10);
            if (((BuildingTypes[bStackY_20].flags2 & 4) == 0) &&
               ((puVar25[unitIndex].level == 0 ||
                ((BuildingTypes[bStackY_20].flags2 & 0x200) != 0)))) {
              ovc22_usesGUnits(unitIndex,
                               (uint8_t *)
                               CONCAT13((char)(unitIndex * 9 >> 8),
                                        CONCAT12(puVar25[unitIndex].unitType,_SS)));
            }
            else if (((((bld_inst_t *)BldInstances + bStackY_20)->ofs != 0 ||
                       *(int *)((int)&BldInstances[0].seg + (uint)bStackY_20 * 0xc) != 0) ||
                     (BuildingTypes[bStackY_20].flags == '\x10')) &&
                    (uVar18 = ovc22_usesGOngoingBattle2
                                        (*(byte *)&puVar25[unitIndex].x,
                                         *(byte *)&puVar25[unitIndex].y), (char)uVar18 != '\0')) {
              uStackY_1c = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1c) + 1)),1);
            }
          }
        }
      }
      unitIndex = unitIndex + 1;
      if (GUnitCount <= unitIndex) break;
      uVar16 = unitIndex * 9;
      uVar18 = (uint16_t)((ulong)GUnits >> 0x10);
      puVar25 = (unit_t *)GUnits;
    }
    GGameState = 0x43;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (uVar27 = 0; (int)uVar27 < (int)(uint)GLeaderCount; uVar27 = uVar27 + 1) {
      if ((GLeaderSheets[uVar27])->active != '\0') {
        (GLeaderSheets[uVar27])->foodSold = 0;
        cVar11 = *(char *)((int)*(uint32_t *)(uVar27 << 2) + 0x3f);
        if ((cVar11 == '\0') &&
           ((GLeaderSheets[uVar27])->foodProd <
            (GLeaderSheets[uVar27])->population >> 1)) {
          bVar8 = true;
        }
        else {
          bVar8 = false;
        }
        uVar16 = *(uint *)((int)*(uint32_t *)(uVar27 << 2) + 0x54);
        uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
        iVar19 = (int)*(uint32_t *)(uVar27 << 2);
        iVar19 = *(int *)(iVar19 + 0x58) + ((int)uVar16 >> 0xf) +
                 (uint)CARRY2(*(uint *)(iVar19 + 0x56),uVar16);
        if ((iVar19 < 1) && (iVar19 < 0)) {
          for (uVar16 = 0xf8; uVar16 < GUnitCount; uVar16 = uVar16 + 1) {
            uVar18 = (uint16_t)((ulong)GUnits >> 0x10);
            puVar25 = (unit_t *)GUnits;
            bStackY_20 = (puVar25 + uVar16)->bldType;
            if ((puVar25[uVar16].unitType == uVar27) &&
               (BuildingTypes[bStackY_20].income < 0)) {
              uVar26 = BuildingTypes[bStackY_20].income;
              uVar29 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
              iVar19 = (int)*(uint32_t *)(uVar27 << 2);
              iVar19 = *(int *)(iVar19 + 0x58) + ((int)uVar26 >> 0xf) +
                       (uint)CARRY2(*(uint *)(iVar19 + 0x56),uVar26);
              if ((iVar19 < 1) && (iVar19 < 0)) {
                if ((cVar11 == '\0') && (puVar25[uVar16].level != 0)) {
                  uVar35 = ovr_randBelow(100,0);
                  uVar18 = (uint16_t)((ulong)GUnits >> 0x10);
                  puVar25 = (unit_t *)GUnits;
                  if (*(byte *)((uint)(puVar25 + uVar16)->bldType * 0x27 + 0x130) <= (byte)uVar35) {
                    if (puVar25[uVar16].level != 0) {
                      puVar25[uVar16].level = puVar25[uVar16].level - 1;
                    }
                    puVar25 = (unit_t *)GUnits;
                    uVar18 = (uint16_t)((ulong)GUnits >> 0x10);
                    if (((BuildingTypes[bStackY_20].flags2 & 4) == 0) &&
                       ((iVar19 = 0, puVar25[uVar16].level == 0 ||
                        (iVar19 = (uint)bStackY_20 * 0x27, (*(uint *)(iVar19 + 0x121) & 0x200) != 0)
                        ))) {
                      ovc22_usesGUnits(uVar16,(uint8_t *)
                                              CONCAT13((char)((uint)iVar19 >> 8),
                                                       CONCAT12((char)uVar27,_SS)));
                    }
                    else if (((((bld_inst_t *)BldInstances + bStackY_20)->ofs != 0 ||
                               *(int *)((int)&BldInstances[0].seg + (uint)bStackY_20 * 0xc) != 0) ||
                             (BuildingTypes[bStackY_20].flags == '\x10')) &&
                            (uVar18 = ovc22_usesGOngoingBattle2
                                                (*(byte *)&puVar25[uVar16].x,
                                                 *(byte *)&puVar25[uVar16].y), (char)uVar18 != '\0')
                            ) {
                      uStackY_1c = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1c) + 1)),1);
                    }
                  }
                }
              }
              else {
                uVar32 = BuildingTypes[bStackY_20].income;
                uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
                iVar19 = (int)*(uint32_t *)(uVar27 << 2);
                puVar3 = (uint *)(iVar19 + 0x56);
                uVar26 = *puVar3;
                *puVar3 = *puVar3 + uVar32;
                piVar2 = (int *)(iVar19 + 0x58);
                *piVar2 = *piVar2 + ((int)uVar32 >> 0xf) + (uint)CARRY2(uVar26,uVar32);
              }
            }
          }
          uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
          iVar19 = (int)*(uint32_t *)(uVar27 << 2);
          *(uint16_t *)(iVar19 + 0x58) = 0;
          *(uint16_t *)(iVar19 + 0x56) = 0;
        }
        else {
          if ((cVar11 == '\0') && (0 < *(int *)((int)*(uint32_t *)(uVar27 << 2) + 0x54))) {
            uVar16 = *(int *)((int)*(uint32_t *)(uVar27 << 2) + 0x54) / 10;
          }
          else {
            uVar16 = 0;
          }
          bVar30 = CARRY2(GPopulationLo,uVar16);
          GPopulationLo = GPopulationLo + uVar16;
          GPopulationHi = GPopulationHi + ((int)uVar16 >> 0xf) + (uint)bVar30;
          uVar16 = *(int *)((int)*(uint32_t *)(uVar27 << 2) + 0x54) - uVar16;
          uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
          iVar19 = (int)*(uint32_t *)(uVar27 << 2);
          puVar3 = (uint *)(iVar19 + 0x56);
          uVar26 = *puVar3;
          *puVar3 = *puVar3 + uVar16;
          piVar2 = (int *)(iVar19 + 0x58);
          *piVar2 = *piVar2 + ((int)uVar16 >> 0xf) + (uint)CARRY2(uVar26,uVar16);
        }
        if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                      (uint)(GLeaderSheets[uVar27])->classStr * 0x95) & 0x100) ==
            0) {
          if ((GLeaderSheets[uVar27])->foodProd <
              (GLeaderSheets[uVar27])->population) {
            uVar16 = (GLeaderSheets[uVar27])->population -
                     (GLeaderSheets[uVar27])->foodProd;
            uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
            iVar22 = (int)*(uint32_t *)(uVar27 << 2);
            iVar19 = *(int *)(iVar22 + 0x62);
            if ((-1 < iVar19) && ((0 < iVar19 || (*(int *)(iVar22 + 0x60) != 0)))) {
              uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
              iVar19 = (int)*(uint32_t *)(uVar27 << 2);
              uVar26 = *(uint *)(iVar19 + 0x62);
              if ((0x7fff < uVar26) ||
                 ((uVar32 = uVar16, (int)uVar26 < 1 && (*(uint *)(iVar19 + 0x60) <= uVar16)))) {
                uVar32 = *(uint *)((int)*(uint32_t *)(uVar27 << 2) + 0x60);
              }
              uVar16 = uVar16 - uVar32;
              uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
              iVar19 = (int)*(uint32_t *)(uVar27 << 2);
              puVar3 = (uint *)(iVar19 + 0x60);
              uVar26 = *puVar3;
              *puVar3 = *puVar3 - uVar32;
              piVar2 = (int *)(iVar19 + 0x62);
              *piVar2 = *piVar2 - (uint)(uVar26 < uVar32);
            }
            if (uVar16 == 0) {
              uVar16 = 0;
            }
            else {
              uVar31 = (undefined1)uVar16;
              uVar17 = (undefined1)(uVar16 >> 8);
              if ((GLeaderSheets[uVar27])->maxTrade < uVar16) {
                uVar18 = (GLeaderSheets[uVar27])->maxTrade;
                uVar31 = (undefined1)uVar18;
                uVar17 = (undefined1)((uint)uVar18 >> 8);
              }
              uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
              iVar19 = (int)*(uint32_t *)(uVar27 << 2);
              uVar26 = *(uint *)(iVar19 + 0x58);
              if (((int)uVar26 < 1) &&
                 ((0x7fff < uVar26 || (*(uint *)(iVar19 + 0x56) < CONCAT11(uVar17,uVar31))))) {
                uVar18 = *(uint16_t *)((int)*(uint32_t *)(uVar27 << 2) + 0x56);
                uVar31 = (undefined1)uVar18;
                uVar17 = (undefined1)((uint)uVar18 >> 8);
              }
              uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
              iVar19 = (int)*(uint32_t *)(uVar27 << 2);
              puVar3 = (uint *)(iVar19 + 0x56);
              uVar26 = *puVar3;
              *puVar3 = *puVar3 - CONCAT11(uVar17,uVar31);
              piVar2 = (int *)(iVar19 + 0x58);
              *piVar2 = *piVar2 - (uint)(uVar26 < CONCAT11(uVar17,uVar31));
              uVar16 = uVar16 - CONCAT11(uVar17,uVar31);
              (GLeaderSheets[uVar27])->foodSold = CONCAT11(uVar17,uVar31);
            }
            if (cVar11 == '\0') {
              for (iVar19 = 0; (uVar16 != 0 && (iVar19 < (int)(uint)GLeaderCount));
                  iVar19 = iVar19 + 1) {
                if (((GLeaderSheets[iVar19])->active != '\0') &&
                   ((*(char *)((int)*(uint32_t *)(iVar19 << 2) + 0x3f) == '\0' &&
                    (uVar18 = (uint16_t)((ulong)*(uint32_t *)(iVar19 << 2) >> 0x10),
                    iVar22 = (int)*(uint32_t *)(iVar19 << 2),
                    *(int *)(iVar22 + 0x60) != 0 || *(int *)(iVar22 + 0x62) != 0)))) {
                  uVar18 = (uint16_t)((ulong)*(uint32_t *)(iVar19 << 2) >> 0x10);
                  iVar22 = (int)*(uint32_t *)(iVar19 << 2);
                  uVar26 = *(uint *)(iVar22 + 0x62);
                  if ((0x7fff < uVar26) ||
                     ((uVar32 = uVar16, (int)uVar26 < 1 && (*(uint *)(iVar22 + 0x60) <= uVar16)))) {
                    uVar32 = *(uint *)((int)*(uint32_t *)(iVar19 << 2) + 0x60);
                  }
                  uVar16 = uVar16 - uVar32;
                  uVar18 = (uint16_t)((ulong)*(uint32_t *)(iVar19 << 2) >> 0x10);
                  iVar22 = (int)*(uint32_t *)(iVar19 << 2);
                  puVar3 = (uint *)(iVar22 + 0x60);
                  uVar26 = *puVar3;
                  *puVar3 = *puVar3 - uVar32;
                  piVar2 = (int *)(iVar22 + 0x62);
                  *piVar2 = *piVar2 - (uint)(uVar26 < uVar32);
                }
              }
            }
            uVar26 = 0;
            while ((uVar26 < EntityCount && (uVar16 != 0))) {
              uVar18 = (uint16_t)((ulong)Entities >> 0x10);
              peVar23 = (entity_t *)Entities;
              if (((*(char *)((int)&peVar23[uVar26].base.entity + 1) == '\0') &&
                  (*(byte *)((int)&peVar23[uVar26].base.entity + 3) == uVar27)) &&
                 ((bVar8 || (1 < peVar23[uVar26].base.animFrame)))) {
                if (peVar23[uVar26].base.animFrame != 0x0) {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  puVar1 = &((entity_t *)Entities)[uVar26].base.animFrame;
                  *puVar1 = *puVar1 + 0xff;
                  if (((entity_t *)Entities)[uVar26].base.animFrame == 0x0) {
                    uStackY_1e = CONCAT11(1,(byte)uStackY_1e);
                  }
                }
                uVar16 = uVar16 - 1;
              }
              uVar26 = uVar26 + 1;
            }
          }
          else {
            uVar26 = (GLeaderSheets[uVar27])->foodProd -
                     (GLeaderSheets[uVar27])->population;
            uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
            iVar19 = (int)*(uint32_t *)(uVar27 << 2);
            puVar3 = (uint *)(iVar19 + 0x60);
            uVar16 = *puVar3;
            *puVar3 = *puVar3 + uVar26;
            piVar2 = (int *)(iVar19 + 0x62);
            *piVar2 = *piVar2 + (uint)CARRY2(uVar16,uVar26);
          }
        }
        uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
        leaderPtr = (int)*(uint32_t *)(uVar27 << 2);
        iVar19 = *(int *)(leaderPtr + 0x62);
        uVar29 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
        leaderPtr2 = (int)*(uint32_t *)(uVar27 << 2);
        iVar22 = *(int *)(leaderPtr2 + 0x80);
        if ((iVar22 <= iVar19) &&
           ((iVar22 < iVar19 || (*(uint *)(leaderPtr2 + 0x7e) < *(uint *)(leaderPtr + 0x60))))) {
          uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
          iVar19 = (int)*(uint32_t *)(uVar27 << 2);
          uVar16 = *(uint *)(iVar19 + 0x60);
          uVar29 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
          iVar22 = (int)*(uint32_t *)(uVar27 << 2);
          puVar3 = (uint *)(iVar22 + 0x7e);
          uVar26 = (uint)(uVar16 < *puVar3);
          uVar32 = *(int *)(iVar19 + 0x62) - *(int *)(iVar22 + 0x80);
          if (((int)(uVar32 - uVar26) < 0) ||
             ((uVar32 == uVar26 &&
              (uVar16 - *puVar3 <= (GLeaderSheets[uVar27])->maxTrade)))) {
            uVar16 = *(int *)((int)*(uint32_t *)(uVar27 << 2) + 0x60) -
                     *(int *)((int)*(uint32_t *)(uVar27 << 2) + 0x7e);
          }
          else {
            uVar16 = (GLeaderSheets[uVar27])->maxTrade;
          }
          (GLeaderSheets[uVar27])->foodSold = -uVar16;
          uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
          iVar19 = (int)*(uint32_t *)(uVar27 << 2);
          puVar3 = (uint *)(iVar19 + 0x56);
          uVar26 = *puVar3;
          *puVar3 = *puVar3 + uVar16;
          piVar2 = (int *)(iVar19 + 0x58);
          *piVar2 = *piVar2 + (uint)CARRY2(uVar26,uVar16);
          uVar29 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
          iVar19 = (int)*(uint32_t *)(uVar27 << 2);
          uVar18 = *(uint16_t *)(iVar19 + 0x7e);
          uVar28 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
          iVar22 = (int)*(uint32_t *)(uVar27 << 2);
          *(uint16_t *)(iVar22 + 0x62) = *(uint16_t *)(iVar19 + 0x80);
          *(uint16_t *)(iVar22 + 0x60) = uVar18;
        }
        if (((GLeaderSheets[uVar27])->housing <
             (GLeaderSheets[uVar27])->population) &&
           ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                      (uint)(GLeaderSheets[uVar27])->classStr * 0x95) & 0x80) == 0
           )) {
          iVar19 = (GLeaderSheets[uVar27])->population -
                   (GLeaderSheets[uVar27])->housing;
          uVar16 = 0;
          while ((uVar16 < EntityCount && (iVar19 != 0))) {
            uVar18 = (uint16_t)((ulong)Entities >> 0x10);
            peVar23 = (entity_t *)Entities;
            if ((*(byte *)((int)&peVar23[uVar16].base.entity + 3) == uVar27) &&
               ((((*(char *)((int)&peVar23[uVar16].base.entity + 1) == '\0' &&
                  (peVar23[uVar16].base.destX == 0)) && (peVar23[uVar16].base.destY == 0)) &&
                (3 < peVar23[uVar16].base.animFrame)))) {
              if (DebugVerbose != false) {
                printf("kill 2 \r");
              }
              puVar1 = &((entity_t *)Entities)[uVar16].base.animFrame;
              *puVar1 = *puVar1 + 0xff;
              iVar19 = iVar19 + -1;
            }
            uVar16 = uVar16 + 1;
          }
        }
        ovr_ovc25_tickCountdown(uVar27);
        _fmemset((char far *)GLeaderSheets[uVar27] + 0x6a, 0, 6);
        _fmemset((char far *)GLeaderSheets[uVar27] + 0x76, 0, 6);
        uVar35 = ovr_randBelow(100,0);
        if ((byte)uVar35 < *(byte *)((int)*(uint32_t *)(uVar27 << 2) + 0xa9)) {
          *(uint16_t *)((int)*(uint32_t *)(uVar27 << 2) + 0x6c) =
               *(uint16_t *)((int)*(uint32_t *)(uVar27 << 2) + 100);
        }
        else {
          (GLeaderSheets[uVar27])->dirBudget[0] =
               *(uint16_t *)((int)*(uint32_t *)(uVar27 << 2) + 100);
        }
        uVar35 = ovr_randBelow(100,0);
        if ((byte)uVar35 < *(byte *)((int)*(uint32_t *)(uVar27 << 2) + 0xa9)) {
          *(uint16_t *)((int)*(uint32_t *)(uVar27 << 2) + 0x6e) =
               *(uint16_t *)((int)*(uint32_t *)(uVar27 << 2) + 0x66);
        }
        else {
          piVar2 = (int *)((int)*(uint32_t *)(uVar27 << 2) + 0x6c);
          *piVar2 = *piVar2 + *(int *)((int)*(uint32_t *)(uVar27 << 2) + 0x66);
        }
        piVar2 = (int *)((int)*(uint32_t *)(uVar27 << 2) + 0x6e);
        *piVar2 = *piVar2 + *(int *)((int)*(uint32_t *)(uVar27 << 2) + 0x68);
        uVar35 = ovr_randBelow(100,0);
        if ((byte)uVar35 < *(byte *)((int)*(uint32_t *)(uVar27 << 2) + 0xa9)) {
          *(uint16_t *)((int)*(uint32_t *)(uVar27 << 2) + 0x78) =
               (GLeaderSheets[uVar27])->ringBudgetIn[0];
        }
        else {
          (GLeaderSheets[uVar27])->ringBudget[0] =
               (GLeaderSheets[uVar27])->ringBudgetIn[0];
        }
        uVar35 = ovr_randBelow(100,0);
        if ((byte)uVar35 < *(byte *)((int)*(uint32_t *)(uVar27 << 2) + 0xa9)) {
          *(uint16_t *)((int)*(uint32_t *)(uVar27 << 2) + 0x7a) =
               *(uint16_t *)((int)*(uint32_t *)(uVar27 << 2) + 0x72);
        }
        else {
          piVar2 = (int *)((int)*(uint32_t *)(uVar27 << 2) + 0x78);
          *piVar2 = *piVar2 + *(int *)((int)*(uint32_t *)(uVar27 << 2) + 0x72);
        }
        uVar35 = ovr_randBelow(100,0);
        if ((byte)uVar35 < *(byte *)((int)*(uint32_t *)(uVar27 << 2) + 0xa9)) {
          *(uint16_t *)((int)*(uint32_t *)(uVar27 << 2) + 0x7c) =
               *(uint16_t *)((int)*(uint32_t *)(uVar27 << 2) + 0x74);
        }
        else {
          piVar2 = (int *)((int)*(uint32_t *)(uVar27 << 2) + 0x7a);
          *piVar2 = *piVar2 + *(int *)((int)*(uint32_t *)(uVar27 << 2) + 0x74);
        }
        *(undefined1 *)((int)*(uint32_t *)(uVar27 << 2) + 0xa7) =
             *(undefined1 *)((int)*(uint32_t *)(uVar27 << 2) + 0xa6);
        if (*(char *)((int)*(uint32_t *)(uVar27 << 2) + 0x3f) != '\0') {
          uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
          iVar22 = (int)*(uint32_t *)(uVar27 << 2);
          iVar19 = *(int *)(iVar22 + 0x58);
          if ((iVar19 < 1) && ((iVar19 != 0 || (*(int *)(iVar22 + 0x56) == 0)))) {
            uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
            iVar19 = (int)*(uint32_t *)(uVar27 << 2);
            *(uint16_t *)(iVar19 + 0x58) = 0;
            *(uint16_t *)(iVar19 + 0x56) = 0x32;
          }
        }
        if (*(char *)((int)*(uint32_t *)(uVar27 << 2) + 0xaa) != '\0') {
          uVar16 = (uint)*(byte *)((int)*(uint32_t *)(uVar27 << 2) + 0xaa);
          b = CONCAT22((int)((ulong)b >> 0x10),uVar16);
          for (uVar26 = 0; (int)uVar26 < (int)(uint)GLeaderCount; uVar26 = uVar26 + 1) {
            uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
            leaderPtr = (int)*(uint32_t *)(uVar27 << 2);
            iVar19 = *(int *)(leaderPtr + 0x58);
            uVar29 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
            leaderPtr2 = (int)*(uint32_t *)(uVar27 << 2);
            iVar22 = *(int *)(leaderPtr2 + 0x8c);
            if ((iVar22 <= iVar19) &&
               ((iVar19 != iVar22 || (*(uint *)(leaderPtr2 + 0x8a) <= *(uint *)(leaderPtr + 0x56)))))
            break;
            if (((GLeaderSheets[uVar26])->active != '\0') &&
               (((0 < *(int *)((int)*(uint32_t *)(uVar26 << 2) + 0x54) &&
                 (*(char *)((int)*(uint32_t *)(uVar26 << 2) + 0x3f) == '\0')) &&
                (uVar26 != uVar27)))) {
              uStackY_2e = (uint)(((long)*(int *)((int)*(uint32_t *)(uVar26 << 2) + 0x54) *
                                   (long)(int)uVar16 & 0xffffU) / 100);
              iStackY_2c = 0;
              uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
              iVar19 = (int)*(uint32_t *)(uVar27 << 2);
              uVar32 = *(uint *)(iVar19 + 0x8a);
              uVar29 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
              iVar22 = (int)*(uint32_t *)(uVar27 << 2);
              puVar3 = (uint *)(iVar22 + 0x56);
              iVar19 = (*(int *)(iVar19 + 0x8c) - *(int *)(iVar22 + 0x58)) -
                       (uint)(uVar32 < *puVar3);
              if ((iVar19 < 1) && ((iVar19 < 0 || (uVar32 - *puVar3 < uStackY_2e)))) {
                uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
                iVar19 = (int)*(uint32_t *)(uVar27 << 2);
                uVar32 = *(uint *)(iVar19 + 0x8a);
                uVar29 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
                iVar22 = (int)*(uint32_t *)(uVar27 << 2);
                puVar3 = (uint *)(iVar22 + 0x56);
                uStackY_2e = uVar32 - *puVar3;
                iStackY_2c = (*(int *)(iVar19 + 0x8c) - *(int *)(iVar22 + 0x58)) -
                             (uint)(uVar32 < *puVar3);
              }
              uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar26 << 2) >> 0x10);
              iVar22 = (int)*(uint32_t *)(uVar26 << 2);
              iVar19 = *(int *)(iVar22 + 0x58);
              if ((iVar19 <= iStackY_2c) &&
                 ((iVar19 < iStackY_2c || (*(uint *)(iVar22 + 0x56) < uStackY_2e)))) {
                uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar26 << 2) >> 0x10);
                iVar19 = (int)*(uint32_t *)(uVar26 << 2);
                iStackY_2c = *(int *)(iVar19 + 0x58);
                uStackY_2e = *(uint *)(iVar19 + 0x56);
              }
              uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
              iVar19 = (int)*(uint32_t *)(uVar27 << 2);
              puVar3 = (uint *)(iVar19 + 0x56);
              uVar32 = *puVar3;
              *puVar3 = *puVar3 + uStackY_2e;
              piVar2 = (int *)(iVar19 + 0x58);
              *piVar2 = *piVar2 + iStackY_2c + (uint)CARRY2(uVar32,uStackY_2e);
              uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar26 << 2) >> 0x10);
              iVar19 = (int)*(uint32_t *)(uVar26 << 2);
              puVar3 = (uint *)(iVar19 + 0x56);
              uVar32 = *puVar3;
              *puVar3 = *puVar3 - uStackY_2e;
              piVar2 = (int *)(iVar19 + 0x58);
              *piVar2 = (*piVar2 - iStackY_2c) - (uint)(uVar32 < uStackY_2e);
            }
          }
        }
        iVar19 = *(int *)((int)*(uint32_t *)(uVar27 << 2) + 0x58);
        if ((iVar19 < 1) && (iVar19 < 0)) {
          uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
          iVar19 = (int)*(uint32_t *)(uVar27 << 2);
          *(uint16_t *)(iVar19 + 0x58) = 0;
          *(uint16_t *)(iVar19 + 0x56) = 0;
        }
        uVar18 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
        leaderPtr = (int)*(uint32_t *)(uVar27 << 2);
        iVar19 = *(int *)(leaderPtr + 0x58);
        uVar29 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
        leaderPtr2 = (int)*(uint32_t *)(uVar27 << 2);
        iVar22 = *(int *)(leaderPtr2 + 0x8c);
        if ((iVar22 <= iVar19) &&
           ((iVar22 < iVar19 || (*(uint *)(leaderPtr2 + 0x8a) < *(uint *)(leaderPtr + 0x56))))) {
          uVar29 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
          iVar19 = (int)*(uint32_t *)(uVar27 << 2);
          uVar18 = *(uint16_t *)(iVar19 + 0x8a);
          uVar28 = (uint16_t)((ulong)*(uint32_t *)(uVar27 << 2) >> 0x10);
          iVar22 = (int)*(uint32_t *)(uVar27 << 2);
          *(uint16_t *)(iVar22 + 0x58) = *(uint16_t *)(iVar19 + 0x8c);
          *(uint16_t *)(iVar22 + 0x56) = uVar18;
        }
      }
    }
    GGameState = 0x40;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (uVar27 = 0xf8; uVar27 < GUnitCount; uVar27 = uVar27 + 1) {
      uVar18 = (uint16_t)((ulong)GUnits >> 0x10);
      puVar25 = (unit_t *)GUnits;
      if ((*(uint *)((uint)(puVar25 + uVar27)->bldType * 0x27 + 0x121) & 0x40) != 0) {
        if (puVar25[uVar27].timer != 0) {
          puVar25[uVar27].timer = puVar25[uVar27].timer - 1;
        }
        uVar18 = (uint16_t)((ulong)GUnits >> 0x10);
        if (((unit_t *)GUnits)[uVar27].timer == 0) {
          uVar7 = *(uint32_t *)((uint)((unit_t *)GUnits)[uVar27].unitType << 2);
          if (*(char *)((int)uVar7 + 0x3f) == '\0') {
            ovr_play_sfx(81,0,0);
            uVar18 = (uint16_t)((ulong)GUnits >> 0x10);
            sVar6 = ((unit_t *)GUnits)[uVar27].y;
            uVar31 = (undefined1)sVar6;
            uVar17 = (undefined1)((uint)sVar6 >> 8);
            uVar16 = ovr_alignUp4(((unit_t *)GUnits)[uVar27].x,0,0);
            pcVar12 = ovr_fmVsprintf("Mine exhausted at (%d, %d).",
                                     (char *)CONCAT13(uVar17,CONCAT12(uVar31,uVar16)));
            ovr_say(pcVar12,0);
            ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
          }
          ovc22_usesGUnits(uVar27,(uint8_t *)
                                  CONCAT13((char)(uVar27 * 9 >> 8),
                                           CONCAT12(((unit_t *)GUnits)[uVar27].unitType,_SS)));
        }
      }
    }
    GGameState = 0x42;
    if (DebugVerbose == false) goto L_upd_units_5087_1d7d_323A;
    break;
  case 2:
    if (in_CX != 1 && uVar16 != 0) goto code_r0x00053afb;
    break;
  case 3:
    puVar3 = (uint *)(&puVar25->bldType + unitIndex);
    *puVar3 = *puVar3 >> 7 | *puVar3 << 9;
    *(uint *)(&puVar25->timer +
             (int)((char *)0x7f01 + x)) =
         *(uint *)(&puVar25->timer +
                  (int)((char *)0x7f01 + x)
                  ) | (uint)&stk_fff8;
    *(uint *)(&puVar25[1].bldType + x) = *(uint *)(&puVar25[1].bldType + x) | (uint)&stk_fffe;
    AgntAnms[0x7d].x = AgntAnms[0x7d].x | (uint)&stk_fff8;
    *(uint *)unitIndex = *(uint *)unitIndex | uVar16;
    (&stk_8d06)[unitIndex] = (&stk_8d06)[unitIndex];
    *(byte *)(x + 8) = *(byte *)(x + 8) | (byte)((uint)iVar19 >> 8);
    (&stk_fffe)[x] = (&stk_fffe)[x] | (byte)((uint)&puVar25->level >> 8);
    pbVar4 = &puVar25->level + unitIndex;
    *pbVar4 = *pbVar4 | (byte)in_CX | (byte)x;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  printf(fmt);
L_upd_units_5087_1d7d_323A:
  ovr_driver_clearMapFlagsRect((uint32_t)GMapFlags,0,0,0x93,0,0,0,0);
  uVar16 = 0;
  while (uVar16 < SquareRecCount) {
    uVar18 = (uint16_t)((ulong)GMapFlags >> 0x10);
    puVar25 = (unit_t *)(*(short (*) [60] [148])GMapFlags + *(int *)((uint8_t *)&SquareRecs[uVar16] + 2));
    uVar27 = uVar16;
code_r0x00053afb:
    *(uint *)(&puVar25->bldType + *(int *)(uVar16 * 0x13) * 2) =
         *(uint *)(&puVar25->bldType + *(int *)(uVar16 * 0x13) * 2) | 8;
    uVar16 = uVar27 + 1;
  }
  if (EntityCount <= EntityScanPos) {
    EntityScanPos = 0;
    for (iVar19 = 0; iVar19 < (int)(uint)GLeaderCount; iVar19 = iVar19 + 1) {
      if ((GLeaderSheets[iVar19])->active != '\0') {
        iVar22 = ((int *)(iVar19 * 4))[1];
        uVar31 = 0x95;
        uVar17 = 0x3b;
        memcpy((char *)CONCAT22(((int *)(iVar19 * 4))[1],(char *)(*(int *)(iVar19 * 4) + 0x8e)),
               (char *)CONCAT13((char)((uint)iVar22 >> 8),
                                CONCAT12((char)iVar22,*(int *)(iVar19 * 4) + 0x94)),3);
        iVar19 = CONCAT11(uVar17,uVar31);
      }
    }
  }
  uVar35 = 0;
  uVar18 = 0x2356;
  bVar10 = ovr_manage_findFirstLeader();
  a = CONCAT13(bVar10,(int3)fmt);
  uVar27 = EntityScanPos;
  if ((bVar10 == 0xff) || (GCanPromote == '\0')) {
    pbVar13 = (byte *)0x0;
  }
  else if ((GLeaderSheets[bVar10])->titleIndex < 5) {
    pbVar13 = (byte *)__C0_ASM_CopyRight + 0x24;
  }
  else {
    pbVar13 = (byte *)((uint)(GLeaderSheets[bVar10])->titleIndex * 4 + 0x14);
  }
  for (; uVar27 < EntityCount; uVar27 = uVar27 + 1) {
    uVar29 = (uint16_t)((ulong)Entities >> 0x10);
    peVar23 = (entity_t *)Entities;
    if (((*(char *)((int)&peVar23[uVar27].base.entity + 1) == '\0') &&
        (peVar23[uVar27].base.destX == 0)) && (peVar23[uVar27].base.destY == 0)) {
      bVar10 = peVar23[uVar27].base.gindex;
      a = CONCAT13((char)((ulong)a >> 0x18),CONCAT12(bVar10,(int)a));
      bVar5 = *(byte *)((int)&peVar23[uVar27].base.entity + 3);
      bVar30 = false;
      bVar9 = false;
      bVar8 = false;
      if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar10 * 0x95) == -1) {
        bVar30 = true;
      }
      else {
        bVar10 = (GLeaderSheets[bVar5])->partySlot;
        uStackY_1c = CONCAT11(bVar10,(char)uStackY_1c);
        if (bVar10 < 5) {
          uVar35 = peVar23[uVar27].base.y;
          uVar18 = 0x2379;
          uVar16 = ovr_alignUp4(((peVar23 + uVar27)->base).x,0,0);
          uVar14 = 0x2410;
          if (((*(short (*) [60] [148])GMapFlags)[uVar35][uVar16] & 8U) == 0) {
            uStackY_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1e) + 1)),0x22);
            bStackY_1f = 0x21;
            bStackY_20 = 0x22;
          }
          else {
            uVar38 = (undefined1)_SS;
            uVar39 = (undefined1)(_SS >> 8);
            puVar37 = &uStackY_1e;
            pbVar13 = &bStackY_1f;
            pbVar33 = &bStackY_20;
            uVar31 = (*(uint8_t *)((uint8_t *)&(uStackY_1c) + 1));
            uVar17 = (undefined1)((uint)pbVar33 >> 8);
            uStackY_1c = 0x2379;
            uStackY_1e = 0x3d98;
            uVar34 = _SS;
            uVar36 = _SS;
            uVar35 = ovr_attact_usesSquareRecCount(uVar35,uVar35);
            table.seg = uVar14;
            table.ofs = uVar35;
            uStackY_1c = 0x2315;
            uVar18 = 0x2315;
            uStackY_1e = 0x3da2;
            pctOut.seg = uVar34;
            pctOut.ofs = (uint16_t)pbVar33;
            remainderOut.seg = uVar36;
            remainderOut.ofs = (uint16_t)pbVar13;
            (*(uint8_t *)((uint8_t *)&(partOut.seg))) = uVar38;
            partOut.ofs = (uint16_t)puVar37;
            (*(uint8_t *)((uint8_t *)&(partOut.seg) + 1)) = uVar39;
            ovr_attact_compute3(table,CONCAT11(uVar17,uVar31),pctOut,remainderOut,partOut);
            uVar27 = CONCAT11(uVar17,uVar31);
          }
        }
        else {
          uStackY_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1e) + 1)),0x22);
          bStackY_1f = 0x21;
          bStackY_20 = 0x22;
        }
        uVar31 = (undefined1)uVar18;
        uVar17 = (undefined1)((uint)uVar18 >> 8);
        uVar18 = 0x2337;
        uVar35 = 0x3dca;
        uVar14 = ovr_randBelow(100,0);
        pbVar13 = (byte *)CONCAT11(uVar17,uVar31);
        if ((byte)uVar14 < (byte)uStackY_1e) {
          bVar30 = true;
          pbVar13 = (byte *)CONCAT11(uVar17,uVar31);
        }
        else if ((uVar14 & 0xff) < (uint)bStackY_1f + (uStackY_1e & 0xff)) {
          bVar9 = true;
          pbVar13 = (byte *)CONCAT11(uVar17,uVar31);
        }
        else {
          bVar8 = true;
        }
      }
      if (bVar8) {
        uVar18 = (uint16_t)((ulong)Entities >> 0x10);
        uVar35 = ((entity_t *)Entities)[uVar27].base.y;
        uVar31 = (undefined1)uVar35;
        uVar17 = (undefined1)(uVar35 >> 8);
        uVar35 = (((entity_t *)Entities + uVar27)->base).x;
        uVar18 = 0x236f;
        cVar11 = ovr_ovc23_tickRecordsAt(uVar35,0,0,0);
        pbVar13 = (byte *)CONCAT11(uVar17,uVar31);
        if (cVar11 == '\0') {
          if ((bStackY_1f == 0) && ((byte)uStackY_1e == '\0')) {
            uVar31 = 0x6f;
            uVar17 = 0x23;
            uVar18 = 0x2337;
            uVar35 = 0x3e5d;
            uVar14 = ovr_randBelow(2,0);
            if ((uVar14 & 0xff) == 0) {
              bVar30 = true;
              pbVar13 = (byte *)CONCAT11(uVar17,uVar31);
            }
            else {
              bVar9 = true;
              pbVar13 = (byte *)CONCAT11(uVar17,uVar31);
            }
          }
          else {
            uVar31 = 0x6f;
            uVar17 = 0x23;
            uVar18 = 0x2337;
            uVar35 = 0x3e86;
            uVar14 = ovr_randBelow((uint)bStackY_1f + (uStackY_1e & 0xff),0);
            pbVar13 = (byte *)CONCAT11(uVar17,uVar31);
            if ((byte)uVar14 < (byte)uStackY_1e) {
              bVar30 = true;
              pbVar13 = (byte *)CONCAT11(uVar17,uVar31);
            }
            else {
              bVar9 = true;
            }
          }
        }
      }
      uVar31 = (undefined1)uVar18;
      uVar17 = (undefined1)((uint)uVar18 >> 8);
      if (bVar30) {
        uVar35 = 0x3ea5;
        uVar16 = ovc22_usesEntities(uVar27);
        pbVar13 = (byte *)CONCAT11(uVar17,uVar31);
        if ((uVar16 & 0xff) == 0) {
          bVar9 = true;
          pbVar13 = (byte *)CONCAT11(uVar17,uVar31);
        }
      }
      if (bVar9) {
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(byte)((ulong)a >> 0x10) * 0x95) !=
             -1) && (bVar5 != 0xff)) {
          if ((*(char *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x3f) != '\0') ||
             (Entities[uVar27].base.level < *(byte *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x53)
             )) {
            ovc22_usesLUDIV_at_((entity_t *)
                                CONCAT13((char)((ulong)Entities >> 0x18),
                                         CONCAT12((char)((ulong)Entities >> 0x10),Entities + uVar27
                                                 )));
            uVar16 = 0;
            plVar15 = LXMUL_at_((long *)pbVar13,a,b);
            peVar23 = Entities + uVar27;
            uVar31 = 0x89;
            uVar17 = 0x3f;
            valueLo = ovr_ovc15_textError((entity_t *)CONCAT22(DAT_2000_d190,peVar23),
                                          (agnt_t *)(CONCAT12((uVar16 & 1) != 0,plVar15) >> 1));
            uVar16 = ovc22_usesLUDIV_at_2((uint16_t)valueLo,(uint16_t)peVar23,(int)pbVar13);
            uVar18 = (uint16_t)((ulong)Entities >> 0x10);
            peVar24 = (entity_t *)Entities;
            uVar27 = *(uint *)&peVar24[CONCAT11(uVar17,uVar31)].base.health;
            *(uint *)&peVar24[CONCAT11(uVar17,uVar31)].base.frameIndex =
                 (int)&(peVar23->base).x +
                 (uint)CARRY2(uVar27,uVar16) +
                 *(int *)&peVar24[CONCAT11(uVar17,uVar31)].base.frameIndex;
            *(uint *)&peVar24[CONCAT11(uVar17,uVar31)].base.health = uVar27 + uVar16;
            uVar18 = 0x23d5;
            ovr_ovc41_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                        CONCAT12((char)((ulong)Entities >> 0x10),
                                                 Entities + CONCAT11(uVar17,uVar31))));
            uVar27 = CONCAT11(uVar17,uVar31);
          }
        }
        ovc22_usesEntities2(uVar27);
        ovc22_usesEntities3(uVar27);
        uVar31 = (undefined1)uVar18;
        uVar17 = (undefined1)((uint)uVar18 >> 8);
        uVar35 = 0x4016;
        ovc22_usesEntities4(uVar27);
        pbVar13 = (byte *)CONCAT11(uVar17,uVar31);
      }
      iStackY_2a = (uint)((entity_t *)Entities)[uVar27].base.animFrame -
                   (uint)*(byte *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0xa4);
      if (0 < iStackY_2a) {
        if (3 < iStackY_2a) {
          iStackY_2a = 3;
        }
        if (iStackY_2a == 3) {
          if (*(int *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x92) == 0) {
            iStackY_2a = 2;
          }
          else {
            piVar2 = (int *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x92);
            *piVar2 = *piVar2 + -1;
          }
        }
        if (iStackY_2a == 2) {
          if (*(int *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x90) == 0) {
            iStackY_2a = 1;
          }
          else {
            piVar2 = (int *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x90);
            *piVar2 = *piVar2 + -1;
          }
        }
        if (iStackY_2a == 1) {
          if (*(int *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x8e) == 0) {
            iStackY_2a = 0;
          }
          else {
            piVar2 = (int *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0x8e);
            *piVar2 = *piVar2 + -1;
          }
        }
        ((entity_t *)Entities)[uVar27].base.animFrame =
             *(char *)((int)*(uint32_t *)((uint)bVar5 << 2) + 0xa4) + (char)iStackY_2a;
      }
      uVar35 = uVar35 + 1;
      if (199 < (int)uVar35) break;
    }
  }
  EntityScanPos = uVar27;
  mapDirty = 1;
  ovr_unit_usesAlignUp4();
  GGameState = 0x44;
  msg = (uint *)((char *)0x26510);
  if (DebugVerbose != false) {
    msg = (uint *)((char *)0x26510);
    printf("%d \r");
  }
  if ((*(uint8_t *)((uint8_t *)&(uStackY_1e) + 1)) != '\0') {
    msg = (uint *)(EntityCount - 1);
    for (entityIndex = msg; -1 < (int)entityIndex; entityIndex = (uint *)((int)entityIndex - 1)) {
      uVar18 = (uint16_t)((ulong)Entities >> 0x10);
      peVar23 = (entity_t *)Entities;
      msg = (uint *)(uint)peVar23[(int)entityIndex].base.animFrame;
      if (msg == (uint *)0x0) {
        msg = (uint *)(uint)AgntGs[(uint)peVar23[(int)entityIndex].base.gindex].ai;
        if (msg == (uint *)0x0) {
          ovr_alignUp4(((peVar23 + (int)entityIndex)->base).x,0,0);
          iVar19 = (uint)((entity_t *)Entities)[(int)entityIndex].base.gindex * 0x95;
          uVar31 = 0x12;
          uVar17 = 0x56;
          msg = (uint *)ovr_fmVsprintf("Intelligence reports %s unit died of starvation. (%d, %d)",
                                       (char *)CONCAT22(*(uint16_t *)
                                                         ((int)&worldMenuLabels[1].ofs + 1 + iVar19)
                                                        ,(char *)*(uint16_t *)
                                                                  ((int)&worldMenuLabels[0].seg + 1
                                                                  + iVar19)));
          ovr_uiNotify((char *)msg,0,0);
          entityIndex = (uint *)CONCAT11(uVar17,uVar31);
        }
        ovr_ovc15_removeEntity((uint)entityIndex);
      }
    }
  }
  if ((char)uStackY_1c != '\0') {
    ovr_constr_flushDirtyRects();
  }
  return msg;
}



/* 55fe:0cdf */
bool __cdecl16far ovc23_textConstructionAbandoned(char *ofs,uint8_t *seg,byte dir)

{
  undefined1 stk_fff6;   /* stack slot fff6 */
  undefined1 stk_fffe;   /* stack slot fffe */
  int *piVar1;
  uint *puVar2;
  byte *pbVar3;
  byte bVar4;
  uint8_t *puVar6;
  uint8_t uVar7;
  uint16_t play_id;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint32_t uVar10;
  uint16_t uVar11;
  char *pcVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  undefined1 uVar16;
  byte bVar21;
  undefined1 extraout_AH;
  int iVar17;
  uint uVar18;
  uint32_t *puVar19;
  byte *pbVar20;
  undefined1 *in_CX;
  byte bVar22;
  byte bVar23;
  byte bVar25;
  char *pcVar24;
  uint *puVar26;
  uint *puVar27;
  int iVar28;
  uint *puVar30;
  uint16_t *puVar31;
  uint16_t *puVar32;
  char *unaff_BP;
  uint uVar33;
  uint unaff_SI;
  uint uVar34;
  uint8_t *puVar35;
  uint16_t uVar36;
  bool bVar37;
  bool bVar38;
  bool bVar39;
  byte in_AF;
  bool bVar40;
  bool bVar41;
  bool bVar42;
  far_t dst;
  brect_t *in_stack_00000000;
  ulong uVar43;
  char cVar44;
  agnt_t *in_stack_0000fffc;
  byte bVar5;
  byte bVar29;
  
  puVar35 = seg;
  pcVar12 = ofs;
  pcVar24 = ofs + *(char *)(dir + 0x885);
  uVar43 = CONCAT22(pcVar24,0x55fe);
  uVar18 = ovr_attact_usesGUnits((int)pcVar24,(int)(seg + *(char *)(dir + 0x889)));
  if (((uVar18 & 0xff) != 0) &&
     (puVar19 = (uint32_t *)(uint)dir, puVar19 <= (uint32_t *)((int)(uint32_t *)&_DATA + 3)))
  {
    iVar28 = (int)puVar19 * 2;
    switch((uint16_t)(uint)puVar19)   /* hand fix: int switch */ {
    case (uint16_t)0x0:
      (**(code **)(pcVar12 + iVar28 + -0x70))();
      break;
    case (uint16_t)0x2:
      uVar18 = 0x1000 << (*(byte *)((int)*puVar19 + 0x3f) & 0x1f);
      uVar10 = *(uint32_t *)((uint)(byte)(uVar43 >> 0x10) << 2);
      uVar33 = 0x1000 << ((*(byte *)((int)uVar10 + 0x3f) ^ 1) & 0x1f);
      uVar34 = 0;
      for (uVar43 = uVar43 & 0xffffff; bVar22 = (byte)(uVar43 >> 0x18), bVar22 < 4;
          uVar43 = CONCAT13(bVar22 + 1,(int3)uVar43)) {
        iVar28 = (int)&in_stack_0000fffc->x + (uint)bVar22;
        uVar33 = iVar28 * 2;
        uVar34 = uVar34 | ((short (*) [60] [148])GMapFlags)[-1][unaff_SI + 0x3b][iVar28 + 0x92] &
                          0x3000U;
      }
      if ((((GRecords[pcVar12].kind & 3) != 1) || (uVar34 != uVar33)) ||
         (uVar10 = *(uint32_t *)((uint)(byte)(uVar43 >> 0x10) << 2),
         bVar37 = ovr_ovc24_textArena((uint16_t)in_stack_0000fffc,unaff_SI,
                                      *(char *)((int)uVar10 + 0x3f)), bVar37)) {
        bVar22 = GRecords[pcVar12].kind;
        pbVar20 = (byte *)(uint)bVar22;
        if (((bVar22 & 1) == 0) && ((uVar18 & uVar34) != 0)) {
          pbVar20 = (byte *)&GREC_FIELD(&GRecords[pcVar12], buildTimer, 0);
          pbVar20[0xd] = pbVar20[0xd] | 1;
        }
      }
      else {
        uVar36 = ovc23_isCursorAt((uint16_t)in_stack_0000fffc,unaff_SI);
        if ((char)uVar36 != '\0') {
          ovr_say((char *)"Construction abandoned.",0);
        }
        if (pcVar12 + 1 < GRecordCount) {
          _fmemmove((char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[pcVar12], buildTimer, 0)),
                    (char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[pcVar12 + 1], buildTimer, 0)),
                    (int)(GRecordCount + (-1 - (int)pcVar12)) * 0x12);
        }
        GRecordCount = GRecordCount + -1;
        pbVar20 = ovc23_textAdlibNone(0,0,0);
      }
      return SUB21(pbVar20,0);
    case (uint16_t)0x3:
      pcVar24 = pcVar24 + -1;
      bVar23 = (byte)iVar28;
      bVar15 = bVar23 - AgntAnms[0xf].frmid;
      bVar13 = (byte)((uint)iVar28 >> 8);
      bVar22 = bVar13 - dir;
      bVar29 = bVar22 - (bVar23 < AgntAnms[0xf].frmid);
      puVar26 = (uint *)CONCAT11(bVar29,bVar15);
      puVar8 = (undefined1 *)(uint)(bVar13 < dir || bVar22 < (bVar23 < AgntAnms[0xf].frmid));
      puVar31 = (uint16_t *)(&stk_fffe + -(int)in_CX + -(int)puVar8);
      puVar2 = (uint *)(puVar35 + -0x57e7);
      uVar33 = (uint)(&stk_fffe < in_CX || &stk_fffe + -(int)in_CX < puVar8);
      puVar32 = (uint16_t *)*puVar2;
      uVar18 = *puVar2;
      *puVar2 = (uVar18 - (int)puVar31) - uVar33;
      puVar2 = (uint *)((int)puVar31 + 0x7419);
      uVar33 = (uint)(puVar32 < puVar31 || uVar18 - (int)puVar31 < uVar33);
      puVar8 = (undefined1 *)*puVar2;
      uVar18 = *puVar2;
      *puVar2 = (uVar18 - (int)in_CX) - uVar33;
      puVar2 = (uint *)(pcVar12 + 0x19);
      uVar33 = (uint)(puVar8 < in_CX || uVar18 - (int)in_CX < uVar33);
      puVar27 = (uint *)*puVar2;
      uVar18 = *puVar2;
      *puVar2 = (uVar18 - (int)puVar26) - uVar33;
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
      uVar18 = (uint)(puVar27 < puVar26 || uVar18 - (int)puVar26 < uVar33);
      (*(uint16_t *)((uint8_t *)&("Peaceful") + 4)) = (0x6665U - (int)puVar35) - uVar18;
      uVar18 = (uint)((uint)0x6665 < puVar35 || (uint)(0x6665U - (int)puVar35) < uVar18);
      bVar37 = (uint)AgntAnms[6].y < pcVar24;
      uVar33 = AgntAnms[6].y - (int)pcVar24;
      AgntAnms[6].y = uVar33 - uVar18;
      puVar8 = (undefined1 *)(uint)(bVar37 || uVar33 < uVar18);
      puVar9 = &stk_fff6 + -(int)puVar35;
      bVar37 = &stk_fff6 < puVar35 || puVar9 < puVar8;
      iVar28 = -(int)puVar8;
      puVar30 = (uint *)(puVar9 + iVar28);
      bVar13 = (byte)((uint)in_CX >> 8);
      bVar22 = (byte)pcVar24 - bVar13;
      bVar38 = (byte)pcVar24 < bVar13 || bVar22 < bVar37;
      bVar25 = (byte)((uint)pcVar24 >> 8);
      bVar22 = bVar22 - bVar37;
      bVar37 = bVar15 != 0 || (byte)-bVar15 < bVar38;
      bVar21 = -bVar15 - bVar38;
      bVar23 = bVar22 - dir;
      bVar38 = bVar22 < dir || bVar23 < bVar37;
      bVar23 = bVar23 - bVar37;
      pbVar3 = (byte *)((char *)((int)puVar26 + (int)pcVar12) + -0x60e8);
      bVar37 = *pbVar3 < bVar13 || (byte)(*pbVar3 - bVar13) < bVar38;
      *pbVar3 = (*pbVar3 - bVar13) - bVar38;
      pbVar3 = (byte *)(puVar31 + -0x3974);
      bVar38 = *pbVar3 < bVar23 || (byte)(*pbVar3 - bVar23) < bVar37;
      *pbVar3 = (*pbVar3 - bVar23) - bVar37;
      pbVar3 = (byte *)(pcVar12 + 31000);
      bVar39 = *pbVar3 < dir || (byte)(*pbVar3 - dir) < bVar38;
      *pbVar3 = (*pbVar3 - dir) - bVar38;
      pbVar3 = (byte *)(puVar31 + 0xc);
      bVar22 = *pbVar3;
      bVar13 = *pbVar3 - bVar25;
      bVar38 = bVar22 < bVar25 || bVar13 < bVar39;
      bVar42 = SBORROW1(*pbVar3,bVar25) != SBORROW1(bVar13,bVar39);
      *pbVar3 = bVar13 - bVar39;
      bVar41 = (char)*pbVar3 < '\0';
      bVar40 = *pbVar3 == 0;
      bVar37 = !bVar42;
      bVar14 = (byte)in_CX;
      puVar32 = puVar31;
      if (!bVar37) {
        puVar6 = puVar35;
        puVar35 = puVar35 + 1;
        uVar7 = in(CONCAT11(bVar25,bVar23));
        *puVar6 = uVar7;
        pbVar3 = (byte *)(pcVar12 + 0x18);
        bVar4 = *pbVar3;
        bVar5 = *pbVar3;
        *pbVar3 = (bVar5 - bVar21) - bVar38;
        *(uint **)(puVar9 + iVar28 + -2) = puVar26;
        ((char *)((int)puVar31 + (int)pcVar12))[0x18] =
             (((char *)((int)puVar31 + (int)pcVar12))[0x18] - bVar14) -
             (bVar4 < bVar21 || (byte)(bVar5 - bVar21) < bVar38);
        *(uint *)((int)puVar26 + (int)pcVar12) =
             *(uint *)((int)puVar26 + (int)pcVar12) ^ (uint)puVar26;
        *(uint *)((int)puVar26 + (int)pcVar12) =
             *(uint *)((int)puVar26 + (int)pcVar12) | (uint)puVar26;
        *(char *)((int)puVar26 + (int)pcVar12) = *(char *)((int)puVar26 + (int)pcVar12) + bVar15;
        *puVar26 = ~*puVar26;
        puVar32 = (uint16_t *)*puVar31;
        uVar18 = CONCAT11(bVar21,dir - 0x18) & 0x9e1f;
        bVar41 = (int)uVar18 < 0;
        bVar40 = uVar18 == 0;
        puVar30 = puVar31 + 3;
      }
      bVar38 = bVar37 && bVar38;
      uVar36 = *puVar30;
      if (bVar40 || (bVar37 && bVar42) != bVar41) {
        bVar41 = bVar38;
        if ((!bVar37 || bVar22 >= bVar25 && bVar13 >= bVar39) && !bVar40) {
          *puVar30 = (uint)puVar32;
          uVar36 = *puVar30;
          uVar18 = (int)(char)bVar14 + 0xe299;
          iVar28 = uVar18 - bVar38;
          *puVar30 = iVar28;
          *pcVar12 = -*pcVar12;
          return (bool)(((char)iVar28 + -0x32) -
                       ((uint)(int)(char)bVar14 < 0x1d67 || uVar18 < bVar38));
        }
      }
      else {
        bVar41 = bVar14 < 0x74 || (byte)(bVar14 + 0x8c) < bVar38;
        bVar14 = (bVar14 + 0x8c) - bVar38;
      }
      bVar37 = bVar14 < 100 || (byte)(bVar14 + 0x9c) < bVar41;
      bVar13 = (bVar14 + 0x9c) - bVar41;
      bVar22 = bVar13 - 0x39;
      bVar38 = bVar13 < 0x39 || bVar22 < bVar37;
      bVar22 = bVar22 - bVar37;
      bVar13 = bVar22 - 0x14;
      bVar37 = bVar22 < 0x14 || bVar13 < bVar38;
      bVar13 = bVar13 - bVar38;
      bVar22 = bVar13 - 8;
      bVar38 = bVar13 < 8 || bVar22 < bVar37;
      bVar22 = bVar22 - bVar37;
      bVar13 = bVar22 - 5;
      bVar14 = bVar13 - bVar38;
      iVar28 = -(uint)(bVar14 < 0xfa || (byte)(bVar14 + 6) < (bVar22 < 5 || bVar13 < bVar38)) -
               (int)puVar26;
      uVar33 = (uint)pcVar12 & *(uint *)((char *)((int)puVar26 + (int)pcVar12) + -0x6bdd);
      uVar34 = (uint)puVar35 & *(uint *)((uint8_t *)((int)puVar26 + (int)puVar35) + 0x23);
      *puVar30 = uVar33;
      uVar33 = uVar33 & *(uint *)((int)puVar26 + uVar34);
      uVar18 = CONCAT11(bVar25,bVar23) & *(uint *)((int)puVar32 + uVar33 + iVar28);
      puVar27 = (uint *)CONCAT11(bVar29,bVar15 & bVar29 &
                                        *(byte *)((int)&_streams[0xc].curp +
                                                 CONCAT11(bVar29,bVar15 & bVar29)));
      uVar11 = *puVar30;
      puVar2 = (uint *)((int)puVar32 + uVar33 + iVar28);
      *puVar2 = *puVar2 ^ (uint)(puVar30 + 1);
      piVar1 = (int *)((int)puVar32 + uVar33 + iVar28);
      *piVar1 = *piVar1 - (int)(puVar30 + 1);
      bVar22 = in(uVar18);
      uVar33 = uVar33 & uVar18;
      puVar2 = (uint *)((int)puVar27 + (int)((char *)0x2a321 + uVar33));
      *puVar2 = *puVar2 & uVar34;
      *(uint *)(uVar34 + 0x21) = *(uint *)(uVar34 + 0x21) & (uint)puVar27;
      *puVar27 = *puVar27 & uVar34;
      puVar2 = (uint *)&AgntAnms[0x5c].sx;
      *puVar2 = *puVar2 & (uint)(puVar30 + 1);
      puVar2 = (uint *)((int)puVar27 + uVar33);
      *puVar2 = *puVar2 & CONCAT11((char)((uint)uVar11 >> 8),bVar22);
      bVar15 = -(0x99 < bVar22);
      return (bool)(bVar15 + (9 < (bVar15 & 0xf) | 9 < (bVar22 & 0xf) | in_AF) * '\x06' +
                   (0x99 < bVar15 || 0x99 < bVar22) * '`');
    }
    do {
      ovc23_usesBlitGfxRect2
                (unaff_SI,(int)in_stack_0000fffc,(int)unaff_BP,in_stack_00000000,(uint16_t)ofs);
      cVar44 = '\x01';
      do {
        while( true ) {
          do {
            do {
              puVar35 = puVar35 + 1;
              uVar16 = 0x10;
              if (rowMapSquareEnd[0] <= puVar35) {
                if (cVar44 != '\0') {
                  uVar16 = 0x10;
                  ovr_constr_usesScreenOriginY((uint16_t)ofs,(uint16_t)seg,0);
                }
                return (bool)uVar16;
              }
              play_id = *(uint16_t *)((int)puVar35 * 2 + 0x360);
            } while (((int)play_id < -2) || (1 < (int)play_id));
            in_stack_00000000 = (brect_t *)((ulong)in_stack_00000000 & 0xffff0000);
            bVar22 = ovr_constr_setHighlightAtOffset(play_id,0,0);
            iVar28 = CONCAT11(extraout_AH,bVar22);
            if (((char *)0x28048)[iVar28 * 3 + *(int *)((int)puVar35 * 2)] !=
                '\0') {
              uVar18 = (uint)((ulong)in_stack_00000000 >> 0x10);
              iVar17 = ovc23_usesCornerBR(play_id,iVar28);
              dst.seg = (uint16_t)seg;
              dst.ofs = (uint16_t)ofs;
              in_stack_00000000 = (brect_t *)((ulong)uVar18 << 0x10);
              ovr_animAdvance(play_id,((char *)0x28048)
                                      [iVar28 * 3 + *(int *)((int)puVar35 * 2)],
                              *(uint16_t *)((int)puVar35 * 2 + 0xa20),(uint)bandOrigin[0] - iVar17,
                              dst);
              cVar44 = '\x01';
            }
          } while (*(int *)(play_id * 2 + -0x6e25) == -1);
          uVar36 = (uint16_t)((ulong)in_stack_00000000 >> 0x10);
          if (*(char *)(play_id + 0x90ec) != '\0') break;
          iVar28 = 0x6964;
          ovc23_usesCornerBR2(play_id,(uint)*(byte *)(*(int *)(play_id * 2 + -0x6e25) * 0x12 + 7));
          in_stack_00000000 = (brect_t *)CONCAT22(uVar36,seg);
          ovc23_usesBlitGfxRect2
                    ((uint)bandOrigin[0] - iVar28,iVar28,(int)ofs,in_stack_00000000,(uint16_t)ofs);
          cVar44 = '\x01';
        }
      } while (play_id != 0xfffe);
      in_stack_0000fffc = (agnt_t *)((int)&GSeasonNames[1].seg + 1);
      ovc23_usesCornerBR2(-2,(uint)GRecords[iRam0002d2d7].width);
      in_stack_00000000 = (brect_t *)CONCAT22(uVar36,seg);
      unaff_SI = (uint)bandOrigin[0] - (int)in_stack_0000fffc;
      unaff_BP = ofs;
    } while( true );
  }
  return false;
}


/* 55fe:0f39 */

/* Rebuilds the four direction bits of a map cell from its neighbour tests. */

void __cdecl16far ovc23_rebuildDirectionFlags(int x,int y)

{
  uint *puVar1;
  bool bVar2;
  uint *puVar3;
  byte bStack_3;
  
  if ((((x < 0x94) && (-1 < x)) && (y < 0x3c)) && (-1 < y)) {
    puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
    *puVar1 = *puVar1 & 0xff0f;
    for (bStack_3 = 0; bStack_3 < 4; bStack_3 = bStack_3 + 1) {
      puVar3 = ovc23_usesAlignUp43(x,y,bStack_3);
      if ((char)puVar3 != '\0') {
        puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
        *puVar1 = *puVar1 | 0x10 << (bStack_3 & 0x1f);
      }
      bVar2 = ovc23_textConstructionAbandoned((char *)x,(uint8_t *)y,bStack_3);
      if (bVar2) {
        puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
        *puVar1 = *puVar1 | 0x100 << (bStack_3 & 0x1f);
      }
    }
  }
  return;
}



/* 55fe:1005 */

/* Places a building of the given bldType/unitType at (x,y). */

void __cdecl16far ovc23_placeBuilding(int x,int y,byte bldType,uint8_t unitType)

{
  byte *unitFlagsPtr;
  uint *flagPtr;
  byte cellBldType;
  int unitIdx;
  uint16_t cellType;
  uint newUnitIdx;
  
  unitIdx = (*(short (*) [148] [60])GUnitGrid)[x][y];
  cellBldType = ((unit_t *)GUnits + unitIdx)->bldType;
  if ((BuildingTypes[cellBldType].flags2 & 4) != 0) {
    strongholdCheckPending = 1;
  }
  newUnitIdx = ovr_ovc18_usesRandBelow(x,y,bldType,unitType,0,0);
  if ((BuildingTypes[bldType].flags & 2) == 2) {
    ovc23_usesGfxRndSeed2(x,y);
  }
  if (((BuildingTypes[bldType].flags & 0xf) != 0) ||
     ((BuildingTypes[cellBldType].flags & 0xf) != 0)) {
    ovc23_rebuildDirectionFlags(x,y);
  }
  if (((BuildingTypes[cellBldType].flags & 1) != 0) ||
     ((BuildingTypes[bldType].flags & 1) != 0)) {
    ovc23_rebuildDirectionFlags(x,y + 1);
  }
  if (((BuildingTypes[bldType].flags & 2) != 0) ||
     ((BuildingTypes[cellBldType].flags & 2) != 0)) {
    ovc23_rebuildDirectionFlags(x + -1,y);
  }
  if (((BuildingTypes[bldType].flags & 3) == 3) ||
     ((BuildingTypes[cellBldType].flags & 3) == 3)) {
    ovc23_rebuildDirectionFlags(x + 1,y);
    ovc23_rebuildDirectionFlags(x,y + 1);
  }
  if (BuildingTypes[bldType].kind == '\x02') {
    if (((*(short (*) [60] [148])GMapFlags)[y + 1][x] & 3U) != 0) {
      unitFlagsPtr = &((unit_t *)GUnits)[newUnitIdx].flags;
      *unitFlagsPtr = *unitFlagsPtr | 4;
      flagPtr = (uint *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x);
      *flagPtr = *flagPtr & 0xfffc;
    }
    if ((BuildingTypes[bldType].flags & 4) != 0) {
      if (((*(short (*) [60] [148])GMapFlags)[y][x + 0x93] & 3U) != 0) {
        unitFlagsPtr = &((unit_t *)GUnits)[newUnitIdx].flags;
        *unitFlagsPtr = *unitFlagsPtr | 8;
        flagPtr = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x + 0x93);
        *flagPtr = *flagPtr & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -2,y);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
      }
      if (((*(short (*) [60] [148])GMapFlags)[y + 1][x + 1] & 3U) != 0) {
        unitFlagsPtr = &((unit_t *)GUnits)[newUnitIdx].flags;
        *unitFlagsPtr = *unitFlagsPtr | 0x10;
        flagPtr = (uint *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x + 1);
        *flagPtr = *flagPtr & 0xfffc;
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x + 2,y);
      }
    }
    if ((BuildingTypes[bldType].flags & 8) != 0) {
      if (((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) != 0) {
        unitFlagsPtr = &((unit_t *)GUnits)[newUnitIdx].flags;
        *unitFlagsPtr = *unitFlagsPtr | 8;
        flagPtr = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
        *flagPtr = *flagPtr & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x,y + -2);
      }
      if (((*(short (*) [60] [148])GMapFlags)[y + 2][x] & 3U) != 0) {
        unitFlagsPtr = &((unit_t *)GUnits)[newUnitIdx].flags;
        *unitFlagsPtr = *unitFlagsPtr | 0x10;
        flagPtr = (uint *)((*(short (*) [60] [148])GMapFlags)[y + 2] + x);
        *flagPtr = *flagPtr & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x,y + 2);
      }
    }
    ovc23_rebuildDirectionFlags(x,y);
    ovc23_rebuildDirectionFlags(x + 1,y);
    ovc23_rebuildDirectionFlags(x + -1,y);
    ovc23_rebuildDirectionFlags(x,y + -1);
    ovc23_rebuildDirectionFlags(x,y + 1);
  }
  if (BuildingTypes[cellBldType].kind == '\x02') {
    ovc23_usesGfxRndSeed2(x,y);
    if ((((unit_t *)GUnits)[unitIdx].flags & 4) != 0) {
      ovc23_drownUnitsAt(x,y);
    }
    if (BuildingTypes[cellBldType].flags == '\x04') {
      cellType = ovr_ovc45_getUnitType(x + -1,y);
      if ((cellType == 0) && ((((unit_t *)GUnits)[unitIdx].flags & 8) != 0)) {
        ovc23_usesGfxRndSeed2(x + -1,y);
        ovc23_drownUnitsAt(x - 1,y);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
        ovc23_rebuildDirectionFlags(x + -2,y);
      }
      cellType = ovr_ovc45_getUnitType(x + 1,y);
      if ((cellType == 0) && ((((unit_t *)GUnits)[unitIdx].flags & 0x10) != 0))
      {
        ovc23_usesGfxRndSeed2(x + 1,y);
        ovc23_drownUnitsAt(x + 1,y);
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x + 2,y);
      }
    }
    else if (BuildingTypes[cellBldType].flags == '\b') {
      cellType = ovr_ovc45_getUnitType(x,y + -1);
      if ((cellType == 0) && ((((unit_t *)GUnits)[unitIdx].flags & 8) != 0)) {
        ovc23_usesGfxRndSeed2(x,y + -1);
        ovc23_drownUnitsAt(x,y - 1);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x,y + -2);
      }
      cellType = ovr_ovc45_getUnitType(x,y + 1);
      if ((cellType == 0) && ((((unit_t *)GUnits)[unitIdx].flags & 0x10) != 0))
      {
        ovc23_usesGfxRndSeed2(x,y + 1);
        ovc23_drownUnitsAt(x,y + 1);
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x,y + 2);
      }
    }
    ovc23_rebuildDirectionFlags(x,y);
    ovc23_rebuildDirectionFlags(x + 1,y);
    ovc23_rebuildDirectionFlags(x + -1,y);
    ovc23_rebuildDirectionFlags(x,y + -1);
    ovc23_rebuildDirectionFlags(x,y + 1);
  }
  if ((BuildingTypes[bldType].unitType == '\x12') && (ListCount < 5)) {
    *(uint *)((uint)ListCount * 2 + -0x6d44) = newUnitIdx;
    ListCount = ListCount + 1;
  }
  if ((BuildingTypes[bldType].sight != 0) || (BuildingTypes[cellBldType].sight != 0))
  {
    ovr_unit_usesAlignUp4();
  }
  return;
}



/* 55fe:1803 */

/* Removes a record from the 0x12-stride table at GRecords, compacts the tail and decrements
   GRecordCount. */

void __cdecl16far ovc23_removeRecord(int recordIndex)

{
  uint16_t unaff_BP;
  uint unaff_SI;
  agnt_t *in_stack_00000000;
  
  if (recordIndex + 1U < GRecordCount) {
    _fmemmove((char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[recordIndex], buildTimer, 0)),
              (char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[recordIndex + 1], buildTimer, 0)),
              ((GRecordCount - recordIndex) + -1) * 0x12);
  }
  GRecordCount = GRecordCount - 1;
  ovc23_textAdlibNone(0,0,0);
  return;
}



/* 55fe:184e */

/* appends a construction record (bldType, x, y, party, tick) */

void __cdecl16far
createConstructionRecord(byte bldType,int x,int y,uint8_t *outFlag,char partyIndex,uint16_t arg6,uint16_t arg7,uint16_t arg8,uint16_t arg9,uint16_t arg10)

{
  int *piVar1;
  byte *pbVar2;
  undefined1 uVar3;
  int iVar4;
  uint16_t uVar5;
  uint uVar6;
  uint16_t unaff_SI;
  uint uVar7;
  uint16_t unaff_DI;
  uint uVar8;
  uint16_t uVar9;
  undefined1 uStack000d;
  byte in_stack_0000000e;
  char in_stack_00000010;
  agnt_t *in_stack_0000fff6;
  uint uStack_8;
  byte bStack_5;
  byte bStack_3;
  
  outFlag = (undefined1 *)CONCAT13(uStack000d,CONCAT12(partyIndex,outFlag));
  for (uStack_8 = 0; (int)uStack_8 < (int)(uint)BuildingTypes[bldType].size;
      uStack_8 = uStack_8 + 1) {
    in_stack_0000fff6 = (agnt_t *)ovc23_findRecordAt(x + uStack_8,y,0);
    if (-1 < (int)in_stack_0000fff6) {
      ovc23_removeRecord((int)in_stack_0000fff6);
    }
  }
  iVar4 = ovc23_isLargeBuilding(x,y);
  if ((char)iVar4 != '\0') {
    ovc23_placeBuilding(x + -1,y,0,in_stack_0000000e);
    uVar5 = ovr_ovc22_usesGOngoingBattle((byte)x - 1,(byte)y);
    if ((char)uVar5 != '\0') {
      *outFlag = 1;
    }
  }
  for (uStack_8 = 1; (int)uStack_8 < (int)(uint)BuildingTypes[bldType].size;
      uStack_8 = uStack_8 + 1) {
    ovc23_placeBuilding(x + uStack_8,y,0,in_stack_0000000e);
    uVar5 = ovr_ovc22_usesGOngoingBattle((byte)x + (char)uStack_8,(byte)y);
    if ((char)uVar5 != '\0') {
      *outFlag = 1;
    }
  }
  if (*(char *)((int)*(uint32_t *)((uint)in_stack_0000000e << 2) + 0x3f) == '\0') {
    if (0x31 < GRecordCount) {
      uVar7 = 0;
      uVar8 = 0xffff;
      for (uStack_8 = 0; uStack_8 < GRecordCount; uStack_8 = uStack_8 + 1) {
        uVar6 = ovr_ovc22_usesGOngoingBattle
                          (GREC_FIELD(&GRecords[uStack_8], x, 0),GREC_FIELD(&GRecords[uStack_8], y, 0));
        if (((uVar6 & 0xff) == 0) && (uVar7 <= (uint)(GameTick - GRecords[uStack_8].tick)))
        {
          uVar7 = GameTick - GRecords[uStack_8].tick;
          uVar8 = uStack_8;
        }
      }
      if (uVar8 == 0xffff) {
        for (uStack_8 = 0; uStack_8 < GRecordCount; uStack_8 = uStack_8 + 1) {
          if (uVar7 <= (uint)(GameTick - GRecords[uStack_8].tick)) {
            uVar7 = GameTick - GRecords[uStack_8].tick;
            uVar8 = uStack_8;
          }
        }
      }
      if (uVar8 == 0xffff) {
        return;
      }
      if (uVar8 + 1 < GRecordCount) {
        _fmemmove((char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[uVar8], buildTimer, 0)),
                  (char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[uVar8 + 1], buildTimer, 0)),
                  ((GRecordCount - uVar8) + -1) * 0x12);
      }
      GRecordCount = GRecordCount - 1;
    }
    _fmemset(GRecords + GRecordCount, 0, 0x12);
    *(byte *)((uint8_t *)&GRecords[GRecordCount] + 8) = bldType;
    *(int *)((uint8_t *)&GRecords[GRecordCount] + 2) = x;
    *(int *)((uint8_t *)&GRecords[GRecordCount] + 4) = y;
    *(byte *)((uint8_t *)&GRecords[GRecordCount] + 9) = in_stack_0000000e;
    iVar4 = ovc23_isLargeBuilding(x,y);
    uVar5 = (uint16_t)((ulong)GUnitGrid >> 0x10);
    uVar9 = (uint16_t)((ulong)GUnits >> 0x10);
    if ((char)iVar4 == '\0') {
      bStack_5 = ((unit_t *)GUnits + (*(short (*) [148] [60])GUnitGrid)[x][y])->bldType;
    }
    else {
      bStack_5 = ((unit_t *)GUnits + ((short (*) [148] [60])GUnitGrid)[-1][x + 0x93][y])->bldType;
    }
    bStack_3 = BuildingTypes[bStack_5].buildTime;
    uVar3 = BuildingTypes[bStack_5].size;
    if (bStack_3 == 0) {
      bStack_3 = 1;
    }
    if (bStack_3 < BuildingTypes[bldType].minBuildTime) {
      *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 6) = BuildingTypes[bldType].minBuildTime;
    }
    else {
      *(byte *)((uint8_t *)&GRecords[GRecordCount] + 6) = bStack_3;
    }
    *(int *)((uint8_t *)&GRecords[GRecordCount] + 0xf) = GameTick;
    *(uint16_t *)(&GRecords[GRecordCount]) = 0;
    uVar5 = ovc23_usesGRecordCount3
                      (BuildingTypes[bldType].expinc,in_stack_0000000e,GRecordCount);
    *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xc) = (char)uVar5;
    if (*(char *)((uint8_t *)&GRecords[GRecordCount] + 0xc) == '\0') {
      *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xc) = 1;
    }
    if (bldType == 0) {
      iVar4 = ovc23_isLargeBuilding(x,y);
      if ((char)iVar4 != '\0') {
        piVar1 = (int *)((uint8_t *)&GRecords[GRecordCount] + 2);
        *piVar1 = *piVar1 + -1;
      }
      *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 7) = uVar3;
      if (in_stack_00000010 == '\x01') {
        *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xe) = 1;
      }
      else {
        *(char *)((uint8_t *)&GRecords[GRecordCount] + 0xc) = in_stack_00000010;
        *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xe) = 0;
      }
      pbVar2 = (byte *)((uint8_t *)&GRecords[GRecordCount] + 0xd);
      *pbVar2 = *pbVar2 | 3;
    }
    else {
      *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 7) = BuildingTypes[bldType].size;
      if (in_stack_00000010 != '\0') {
        ovc23_placeBuilding(x,y,0,in_stack_0000000e);
        uVar5 = ovr_ovc22_usesGOngoingBattle((byte)x,(byte)y);
        if ((char)uVar5 != '\0') {
          *outFlag = 1;
        }
      }
      *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xe) = 0;
    }
    *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0x11) = 0;
    *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xb) = *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xc);
    uVar8 = GRecordCount;
    GRecordCount = GRecordCount + 1;
    ovc23_abandonConstruction(uVar8);
    ovc23_textAdlibNone(0,0,0);
  }
  else {
    ovc23_placeBuilding(x,y,bldType,in_stack_0000000e);
    uVar5 = ovr_ovc22_usesGOngoingBattle((byte)x,(byte)y);
    if ((char)uVar5 != '\0') {
      *outFlag = 1;
    }
  }
  return;
}



/* 55fe:1e87 */

/* overlay entry that forwards to createConstructionRecord */

void __cdecl16far
createConstructionRecordFar
          (byte bldType,int x,int y,uint8_t *outFlag,byte outFlagSeg,char partyIndex,uint16_t arg7,uint16_t arg8,uint16_t arg9)

{
  uint16_t in_AX;
  
  createConstructionRecord
            (bldType,x,y,(uint8_t *)outFlag,(char)((ulong)outFlag >> 0x10),CONCAT11((char)((uint)in_AX >> 8),outFlagSeg),1,0,0,0);
  return;
}



/* 55fe:1ea9 */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc23_usesBlitGfxRect(int x,int y,int recordIndex,brect_t *rect,uint16_t type)

{
  int y_00;
  byte bVar1;
  byte bVar2;
  uint buildTimer;
  int x_00;
  uint animPhase;
  int in_stack_00000004;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  far_t gfx_08;
  far_t gfx_09;
  far_t gfx_10;
  far_t gfx_11;
  uint8_t type_00;
  uint spanCount;
  uint spanLeft;
  int iStack_c;
  uint16_t gfxOfs;
  uint16_t gfxSeg;
  
  spanCount = (uint)GRecords[y].frameCount;
  buildTimer = GRecords[y].buildTimer;
  bVar1 = GRecords[y].state;
  bVar2 = GRecords[y].frame;
  if (bVar2 < spanCount) {
    spanCount = bVar2 + 1;
  }
  x_00 = in_stack_00000004 + -1;
  iStack_c = x + spanCount * -0x26 + -0x32;
  spanLeft = spanCount;
  while (spanLeft = spanLeft - 1, -1 < (int)spanLeft) {
    y_00 = iStack_c + 0x26;
    type_00 = (uint8_t)rect;
    if ((bVar1 == 2) || (0x13 < buildTimer)) {
      if (bVar1 < 2) {
        if ((spanLeft == 0) && ((buildTimer - x_00 & 0x3f) < 0x20)) {
          animPhase = buildTimer - x_00 & 0x3f;
          gfxSeg = ((uint16_t *)&csite5Seg)[animPhase * 2];
          gfxOfs = ((uint16_t *)&csite5Ofs)[animPhase * 2];
        }
        else {
          gfxSeg = csite3_5Seg;
          gfxOfs = csite3_5Ofs;
        }
        if (spanLeft == 0) {
          animPhase = (buildTimer + GfxRndSeed2) % 0xe;
          gfx_01.seg = ((uint16_t *)&tmstrsSprites6Seg)[animPhase * 2];
          gfx_01.ofs = ((uint16_t *)&tmstrsSprites6Ofs)[animPhase * 2];
          ovr_blitGfxRect(gfx_01,in_stack_00000004 + 0xe,iStack_c + 0x8b,(brect_t *)recordIndex,type_00,true,1,0,0,0,0,0);
        }
        gfx_02.seg = gfxSeg;
        gfx_02.ofs = gfxOfs;
        ovr_blitGfxRect(gfx_02,x_00,y_00,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
        if ((buildTimer + spanLeft + GfxRndSeed2 + x_00 & 0x1f) < 0x11) {
          animPhase = buildTimer + spanLeft + GfxRndSeed2 + x_00 & 0x1f;
          gfx_03.seg = ((uint16_t *)&tmstrsSprites5Seg)[animPhase * 2];
          gfx_03.ofs = ((uint16_t *)&tmstrsSprites5Ofs)[animPhase * 2];
          ovr_blitGfxRect(gfx_03,x_00 + ((uint)*(byte *)((buildTimer + spanLeft + GfxRndSeed2 + x_00 >> 5
                                                         ) + spanLeft + GfxRndSeed2 & 0xff) * 0x50)
                                        / 0x100,iStack_c + 0x66,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
        }
        if ((((buildTimer + spanLeft) - GfxRndSeed2) - x_00 & 0xf) < 7) {
          animPhase = ((buildTimer + spanLeft) - GfxRndSeed2) - x_00 & 0xf;
          gfx_04.seg = ((uint16_t *)&tmstrsSprites4Seg)[animPhase * 2];
          gfx_04.ofs = ((uint16_t *)&tmstrsSprites4Ofs)[animPhase * 2];
          ovr_blitGfxRect(gfx_04,x_00 + ((uint)*(byte *)((((((buildTimer + spanLeft) - GfxRndSeed2) -
                                                            x_00 >> 4) + spanLeft) - GfxRndSeed2) +
                                                         0xe & 0xff) * 0x50) / 0x100,iStack_c + 0x66,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
        }
        animPhase = (buildTimer + 5) % 7;
        gfx_05.seg = ((uint16_t *)&tmstrsSprites3Seg)[animPhase * 2];
        gfx_05.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[animPhase * 2];
        ovr_blitGfxRect(gfx_05,in_stack_00000004 + 9,iStack_c + 0x62,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
        gfx_06.seg = ((uint16_t *)&tmstrsSprites3Seg)[(buildTimer % 7) * 2];
        gfx_06.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[(buildTimer % 7) * 2];
        ovr_blitGfxRect(gfx_06,in_stack_00000004 + 0xd,iStack_c + 0x62,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
        animPhase = (buildTimer + 2) % 7;
        gfx_07.seg = ((uint16_t *)&tmstrsSprites3Seg)[animPhase * 2];
        gfx_07.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[animPhase * 2];
        ovr_blitGfxRect(gfx_07,in_stack_00000004 + 0x31,iStack_c + 0x62,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
        animPhase = buildTimer + 3 & 7;
        gfx_08.seg = ((uint16_t *)&tmstrsSprites2Seg)[animPhase * 2];
        gfx_08.ofs = ((uint16_t *)&tmstrsSprites2Ofs)[animPhase * 2];
        ovr_blitGfxRect(gfx_08,in_stack_00000004 + 0x45,iStack_c + 0x62,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
        gfx_09.seg = ((uint16_t *)&tmstrsSprites2Seg)[(buildTimer & 7) * 2];
        gfx_09.ofs = ((uint16_t *)&tmstrsSprites2Ofs)[(buildTimer & 7) * 2];
        ovr_blitGfxRect(gfx_09,in_stack_00000004 + 0x3b,iStack_c + 0x62,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
        gfx_10.seg = ((uint16_t *)&tmstrsSprites1Seg)[(buildTimer % 5) * 2];
        gfx_10.ofs = ((uint16_t *)&tmstrsSprites1Ofs)[(buildTimer % 5) * 2];
        ovr_blitGfxRect(gfx_10,in_stack_00000004 + 0x27,iStack_c + 0x62,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
        gfx_11.seg = ((uint16_t *)&tmstrsSprites1Seg)[(buildTimer % 5) * 2];
        gfx_11.ofs = ((uint16_t *)&tmstrsSprites1Ofs)[(buildTimer % 5) * 2];
        ovr_blitGfxRect(gfx_11,in_stack_00000004 + 0x3f,iStack_c + 0x62,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
        iStack_c = y_00;
      }
      else {
        if (buildTimer < 9) {
          gfxSeg = ((uint16_t *)&csite2Seg)[(buildTimer + 0xe) * 2];
          gfxOfs = ((uint16_t *)&csite2Ofs)[(buildTimer + 0xe) * 2];
        }
        else {
          gfxSeg = csite4_8Seg;
          gfxOfs = csite4_8Ofs;
        }
        gfx_00.seg = gfxSeg;
        gfx_00.ofs = gfxOfs;
        ovr_blitGfxRect(gfx_00,x_00,y_00,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
        iStack_c = y_00;
      }
    }
    else {
      if ((spanCount - 1 == spanLeft) && (buildTimer < 0xf)) {
        gfxSeg = ((uint16_t *)&csite2Seg)[buildTimer * 2];
        gfxOfs = ((uint16_t *)&csite2Ofs)[buildTimer * 2];
      }
      else {
        gfxSeg = csite3_5Seg;
        gfxOfs = csite3_5Ofs;
      }
      gfx.seg = gfxSeg;
      gfx.ofs = gfxOfs;
      ovr_blitGfxRect(gfx,x_00,y_00,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
      iStack_c = y_00;
    }
  }
  return;
}



/* 55fe:23d8 */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc23_usesBlitGfxRect2(int x,int y,int recordIndex,brect_t *rect,uint16_t type)

{
  int y_00;
  byte bVar1;
  byte frame;
  uint buildTimer;
  uint16_t spriteOfs;
  uint16_t spriteSeg;
  int x_00;
  uint animPhase;
  uint16_t unaff_SI;
  uint16_t unaff_DI;
  int in_stack_00000004;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  far_t gfx_08;
  far_t gfx_09;
  far_t gfx_10;
  far_t gfx_11;
  uint8_t type_00;
  brect_t *rect_00;
  uint spanCount;
  uint spanLeft;
  int yBase;
  uint16_t gfxOfs;
  uint16_t gfxSeg;
  
  bVar1 = GRecords[y].width;
  if (bVar1 < 2) {
    spanCount = (uint)GRecords[y].frameCount;
    buildTimer = GRecords[y].buildTimer;
    bVar1 = GRecords[y].state;
    frame = GRecords[y].frame;
    if (frame < spanCount) {
      spanCount = frame + 1;
    }
    x_00 = in_stack_00000004 + -1;
    yBase = x + spanCount * -0x13 + 0x2a;
    spanLeft = spanCount;
    while (spriteSeg = csite1_12Seg, spriteOfs = csite1_12Ofs, spanLeft = spanLeft - 1, -1 < (int)spanLeft)
    {
      y_00 = yBase + 0x13;
      type_00 = (uint8_t)rect;
      if ((bVar1 == 2) || (0x13 < buildTimer)) {
        if (bVar1 < 2) {
          if (spanLeft == 0) {
            animPhase = (buildTimer + GfxRndSeed2) % 0xe;
            gfx_01.seg = ((uint16_t *)&tmstrsSprites6Seg)[animPhase * 2];
            gfx_01.ofs = ((uint16_t *)&tmstrsSprites6Ofs)[animPhase * 2];
            ovr_blitGfxRect(gfx_01,in_stack_00000004 + 0xe,yBase + 0x22,(brect_t *)recordIndex,type_00,true,1,0,0,0,0,0);
          }
          gfx_02.seg = spriteSeg;
          gfx_02.ofs = spriteOfs;
          ovr_blitGfxRect(gfx_02,x_00,y_00,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          if ((buildTimer + spanLeft + GfxRndSeed2 + x_00 & 0x1f) < 0x11) {
            animPhase = buildTimer + spanLeft + GfxRndSeed2 + x_00 & 0x1f;
            gfx_03.seg = ((uint16_t *)&tmstrsSprites5Seg)[animPhase * 2];
            gfx_03.ofs = ((uint16_t *)&tmstrsSprites5Ofs)[animPhase * 2];
            ovr_blitGfxRect(gfx_03,x_00 + ((int)((uint)*(byte *)((buildTimer + spanLeft + GfxRndSeed2 +
                                                                  x_00 >> 5) + spanLeft +
                                                                 GfxRndSeed2 & 0xff) * 0x25) >> 8) +
                                   3,yBase + 0x10,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          }
          if ((((buildTimer + spanLeft) - GfxRndSeed2) - x_00 & 0xf) < 7) {
            animPhase = ((buildTimer + spanLeft) - GfxRndSeed2) - x_00 & 0xf;
            gfx_04.seg = ((uint16_t *)&tmstrsSprites4Seg)[animPhase * 2];
            gfx_04.ofs = ((uint16_t *)&tmstrsSprites4Ofs)[animPhase * 2];
            ovr_blitGfxRect(gfx_04,x_00 + ((int)((uint)*(byte *)((((((buildTimer + spanLeft) -
                                                                    GfxRndSeed2) - x_00 >> 4) +
                                                                  spanLeft) - GfxRndSeed2) + 0xe &
                                                                0xff) * 0x25) >> 8) + 3,yBase + 0x10,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          }
          animPhase = (buildTimer + 5) % 7;
          gfx_05.seg = ((uint16_t *)&tmstrsSprites3Seg)[animPhase * 2];
          gfx_05.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[animPhase * 2];
          ovr_blitGfxRect(gfx_05,in_stack_00000004 + 4,yBase + 0xd,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          gfx_06.seg = ((uint16_t *)&tmstrsSprites3Seg)[(buildTimer % 7) * 2];
          gfx_06.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[(buildTimer % 7) * 2];
          ovr_blitGfxRect(gfx_06,in_stack_00000004 + 6,yBase + 0xd,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          animPhase = (buildTimer + 2) % 7;
          gfx_07.seg = ((uint16_t *)&tmstrsSprites3Seg)[animPhase * 2];
          gfx_07.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[animPhase * 2];
          ovr_blitGfxRect(gfx_07,in_stack_00000004 + 0x18,yBase + 0xd,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          animPhase = buildTimer + 3 & 7;
          gfx_08.seg = ((uint16_t *)&tmstrsSprites2Seg)[animPhase * 2];
          gfx_08.ofs = ((uint16_t *)&tmstrsSprites2Ofs)[animPhase * 2];
          ovr_blitGfxRect(gfx_08,in_stack_00000004 + 0x22,yBase + 0xd,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          gfx_09.seg = ((uint16_t *)&tmstrsSprites2Seg)[(buildTimer & 7) * 2];
          gfx_09.ofs = ((uint16_t *)&tmstrsSprites2Ofs)[(buildTimer & 7) * 2];
          ovr_blitGfxRect(gfx_09,in_stack_00000004 + 0x1d,yBase + 0xd,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          gfx_10.seg = ((uint16_t *)&tmstrsSprites1Seg)[(buildTimer % 5) * 2];
          gfx_10.ofs = ((uint16_t *)&tmstrsSprites1Ofs)[(buildTimer % 5) * 2];
          ovr_blitGfxRect(gfx_10,in_stack_00000004 + 0x13,yBase + 0xd,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          gfx_11.seg = ((uint16_t *)&tmstrsSprites1Seg)[(buildTimer % 5) * 2];
          gfx_11.ofs = ((uint16_t *)&tmstrsSprites1Ofs)[(buildTimer % 5) * 2];
          ovr_blitGfxRect(gfx_11,in_stack_00000004 + 0x1f,yBase + 0xd,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          yBase = y_00;
        }
        else {
          if (buildTimer < 10) {
            gfxSeg = ((uint16_t *)&csite1Seg)[(buildTimer + 0xc) * 2];
            gfxOfs = ((uint16_t *)&csite1Ofs)[(buildTimer + 0xc) * 2];
          }
          else {
            gfxSeg = csite1_22Seg;
            gfxOfs = csite1_22Ofs;
          }
          gfx_00.seg = gfxSeg;
          gfx_00.ofs = gfxOfs;
          ovr_blitGfxRect(gfx_00,x_00,y_00,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          yBase = y_00;
        }
      }
      else {
        if ((spanCount - 1 == spanLeft) && (buildTimer < 0xd)) {
          gfxSeg = ((uint16_t *)&csite1Seg)[buildTimer * 2];
          gfxOfs = ((uint16_t *)&csite1Ofs)[buildTimer * 2];
        }
        else {
          gfxSeg = csite1_12Seg;
          gfxOfs = csite1_12Ofs;
        }
        gfx.seg = gfxSeg;
        gfx.ofs = gfxOfs;
        ovr_blitGfxRect(gfx,x_00,y_00,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
        yBase = y_00;
      }
    }
  }
  else {
    rect_00 = (brect_t *)CONCAT22(unaff_DI,(brect_t *)rect);
    ovc23_usesBlitGfxRect(x + 10,y,recordIndex,rect_00,unaff_SI);
    if (2 < bVar1) {
      ovc23_usesBlitGfxRect
                (x + 10,y,recordIndex,
                 (brect_t *)CONCAT22((int)((ulong)rect_00 >> 0x10),(brect_t *)rect),unaff_SI);
    }
  }
  return;
}



/* 55fe:2937 */

/* Returns the index of the 0x12-stride record at 0x21f2 whose row is y and whose x-span contains x,
   or 0xffff. */

uint __cdecl16far ovc23_findRecordAt(int x,int y,uint16_t arg3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (GRecordCount <= uVar2) {
      return 0xffff;
    }
    if (((GRecords[uVar2].y == y) &&
        (iVar1 = GRecords[uVar2].x,
        x <= (int)(iVar1 + (uint)GRecords[uVar2].width + -1))) && (iVar1 <= x)) break;
    uVar2 = uVar2 + 1;
  }
  return uVar2;
}



/* 55fe:29a2 */

/* Removes an unreachable construction record and reports "Construction abandoned." on the cursor
   cell. */

void __cdecl16far ovc23_abandonConstruction(int recordIndex)

{
  /* 55fe:29a2 (file 0x4A782), re-derived from the original:

       party = GRecords[idx].party                      ; +9
       if (GLeaderSheets[party][0x3f] != 0) return       ; 0x70 table, stride 4
       x = alignUp4(GRecords[idx].x)                     ; +2
       y = GRecords[idx].y                               ; +4
       mask1 = 0x1000 << sheet[0x3f]
       mask2 = 0x1000 << (sheet[0x3f] ^ 1)
       for (b = 0; b < 4; b++)                           ; 0x4A840..0x4A874
           acc |= word[GMapFlags + y*0x128 + (x+b)*2 - 4] & 0x3000
       if ((kind & 3) == 1 && acc == mask2 &&
           ovc24_textArena(x, y, sheet[0x3f]) == 0) {     ; 0x4A896..0x4A8C9
           if (ovc23_isCursorAt(x, y)) ovr_say("Construction abandoned.");
           if (idx + 1 < GRecordCount) fmemmove(...);
           GRecordCount--;
           ovc23_textAdlibNone();                        ; push cs / call, no arguments
       }
       else if ((kind & 1) == 0 && (mask1 & acc) != 0) {
           kind |= 1;
       }

     Corrections to the exported form: the loop counter is a plain byte 0..3 (the export
     packed it together with the party index through CONCAT11 and named the result `agnt`,
     then recovered the counter with `(byte)((uint)agnt >> 8)`), and the four repeated reads
     of the 0x70 sheet pointer collapse to one local.

     Recorded defect: the tail call is `push cs; call 0x47de0` (55fe:0000) with no `add sp`
     afterwards, i.e. ovc23_textAdlibNone takes NO arguments, while our declaration gives it
     three - the three pseudo-registers the export passed were never real arguments.  The
     zeros below are the closest expressible form; the declaration needs fixing separately. */
  byte party;
  uint16_t x;
  uint16_t y;
  uint16_t mask1;
  uint16_t mask2;
  uint16_t acc;
  byte b;
  uint32_t sheetRef;

  party = GRecords[recordIndex].party;
  sheetRef = *(uint32_t *)((uint)party << 2);
  if (*(char *)((int)sheetRef + 0x3f) == '\0') {
    x = ovr_alignUp4(GRecords[recordIndex].x,0,0);
    y = GRecords[recordIndex].y;
    mask1 = 0x1000 << (*(byte *)((int)sheetRef + 0x3f) & 0x1f);
    mask2 = 0x1000 << ((*(byte *)((int)sheetRef + 0x3f) ^ 1) & 0x1f);
    acc = 0;
    for (b = 0; b < 4; b++) {
      acc = acc | ((short (*) [60] [148])GMapFlags)[-1][y + 0x3b][x + b + 0x92] & 0x3000U;
    }
    if (((GRecords[recordIndex].kind & 3) == 1) && (acc == mask2) &&
        (ovr_ovc24_textArena(x,y,*(char *)((int)sheetRef + 0x3f)) == 0)) {
      if ((char)ovc23_isCursorAt(x,y) != '\0') {
        ovr_say((char *)"Construction abandoned.",0x2410);
      }
      if (recordIndex + 1U < GRecordCount) {
        _fmemmove((char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[recordIndex], buildTimer, 0)),
                  (char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[recordIndex + 1], buildTimer, 0)),
                  ((GRecordCount - recordIndex) + -1) * 0x12);
      }
      GRecordCount = GRecordCount - 1;
      ovc23_textAdlibNone(0,0,0);
    }
    else if (((GRecords[recordIndex].kind & 1) == 0) && ((mask1 & acc) != 0)) {
      GRecords[recordIndex].kind = GRecords[recordIndex].kind | 1;
    }
  }
  return;
}



/* 55fe:2b82 */

/* [R1] forwards to OVC23_55fe_29a2 */

void __cdecl16far OVC23_55fe_29a2_entry(void)

{
  int recordIndex;
  
  recordIndex = GRecordCount;
  while (recordIndex = recordIndex + -1, -1 < recordIndex) {
    ovc23_abandonConstruction(recordIndex);
  }
  return;
}



/* 55fe:2b9e */

/* [R7] body shape: compute */

uint __cdecl16far ovc23_compute1(int x,int y,byte bldType,uint8_t unitType)

{
  char cVar1;
  byte cellType;
  int iVar3;
  uint uVar4;
  
  cVar1 = BuildingTypes[bldType].flags;
  if (cVar1 == '\0') {
    uVar4 = 0;
  }
  else if (cVar1 == '\x01') {
    cellType = ovr_ovc45_getUnitType(x,y + -1);
    if (BuildingTypes[cellType].flags == '\x02') {
      ovc23_placeBuilding(x,y,bldType + 2,unitType);
    }
    else {
      ovc23_placeBuilding(x,y,bldType,unitType);
    }
    cellType = ovr_ovc45_getUnitType(x + -1,y);
    iVar3 = (uint)cellType * 0x27;
    if (*(char *)(iVar3 + 0x11e) == '\x02') {
      iVar3 = x + -1;
      ovc23_placeBuilding(iVar3,y,cellType + 1,unitType);
    }
    uVar4 = CONCAT11((char)((uint)iVar3 >> 8),1);
  }
  else if (cVar1 == '\x02') {
    cellType = ovr_ovc45_getUnitType(x + 1,y);
    if (BuildingTypes[cellType].flags == '\x01') {
      ovc23_placeBuilding(x,y,bldType + 1,unitType);
    }
    else {
      ovc23_placeBuilding(x,y,bldType,unitType);
    }
    cellType = ovr_ovc45_getUnitType(x,y + 1);
    iVar3 = (uint)cellType * 0x27;
    if (*(char *)(iVar3 + 0x11e) == '\x01') {
      iVar3 = y + 1;
      ovc23_placeBuilding(x,iVar3,cellType + 2,unitType);
    }
    uVar4 = CONCAT11((char)((uint)iVar3 >> 8),1);
  }
  else if (cVar1 == '!') {
    cellType = ovr_ovc45_getUnitType(x + -1,y);
    uVar4 = (uint)cellType * 0x27;
    if (*(char *)(uVar4 + 0x11e) == '\x02') {
      uVar4 = x - 1;
      ovc23_placeBuilding(uVar4,y,cellType + 1,unitType);
    }
    uVar4 = uVar4 & 0xff00;
  }
  else if (cVar1 == '\"') {
    cellType = ovr_ovc45_getUnitType(x,y + 1);
    uVar4 = (uint)cellType * 0x27;
    if (*(char *)(uVar4 + 0x11e) == '\x01') {
      uVar4 = y + 1;
      ovc23_placeBuilding(x,uVar4,cellType + 2,unitType);
    }
    uVar4 = uVar4 & 0xff00;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}



/* 55fe:2da3 */

/* Scans four columns from alignUp4(x) for a cell with clear low flag bits and returns its x, else
   -1. */

int __cdecl16far ovc23_findClearColumn(int x,int y)

{
  uint uVar1;
  int iVar2;
  
  if (((*(short (*) [60] [148])GMapFlags)[y + 1][x] & 3U) != 0) {
    uVar1 = ovr_alignUp4(x,0,0);
    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
      if (((*(short (*) [60] [148])GMapFlags)[y][uVar1 + iVar2 + 0x92] & 3U) == 0) {
        return uVar1 + iVar2 + -2;
      }
    }
    x = -1;
  }
  return x;
}



/* 55fe:2e2b */

/* [R7] body shape: compute */

int __cdecl16far ovc23_compute2(int x,uint16_t y)

{
  int iVar1;
  
  iVar1 = ovc23_findClearColumn(x,y);
  if (iVar1 < 0) {
    iVar1 = x;
  }
  return iVar1;
}



/* 55fe:2e4c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Drowns the units at (x,y): marks the cell and reports each drowning. */

void __cdecl16far ovc23_drownUnitsAt(uint16_t x,uint16_t y)

{
  uint *puVar1;
  char *pcVar2;
  uint16_t dst;
  uint entityIndex;
  uint16_t uVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  uint8_t text2;
  uint8_t text;
  int clearCol;
  byte gindex;
  
  puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x);
  *puVar1 = *puVar1 | 3;
  entityIndex = EntityCount;
  while (entityIndex = entityIndex - 1, -1 < (int)entityIndex) {
    uVar3 = (uint16_t)((ulong)Entities >> 0x10);
    if ((((entity_t *)Entities)[entityIndex].base.x == x) &&
       (((entity_t *)Entities)[entityIndex].base.y == y)) {
      clearCol = ovc23_findClearColumn(x,y);
      uVar3 = (uint16_t)((ulong)Entities >> 0x10);
      if (clearCol < 0) {
        gindex = ((entity_t *)Entities)[entityIndex].base.gindex;
        if (AgntGs[(uint)gindex].ai == '\0') {
          uVar3 = 0xa000;
          dst = 0x195d;
          uVar4 = x;
          uVar5 = y;
          pcVar2 = ovr_ovc15_capitalize((char *)&text2);
          pcVar2 = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x5665,_SS),
                                 (char *)CONCAT22(pcVar2,(char *)0x26510),dst,uVar4,uVar5,
                                 uVar3);
          ovr_uiNotify(pcVar2,dst,0);
        }
        ovr_ovc15_removeEntity(entityIndex);
      }
      else {
        ((entity_t *)Entities)[entityIndex].base.x = clearCol;
      }
    }
  }
  return;
}



/* 55fe:2f90 */

/* [R6] touches GRecordCount */

byte __cdecl16far ovc23_usesGRecordCount3(byte amount,byte partyIndex,int recordIndex)

{
  /* 55fe:2f90 (file 0x4AD70), re-derived from the original:

       [bp-6] = (word)amount
       memset(&[bp-4], 0, 3)                         ; three byte counters
       for (si = 0; si < GRecordCount; si++) {
           if (GRecords[si].party != partyIndex) continue;
           if (GRecords[si].kind & 4)    [bp-4]++;
           if (GRecords[si].kind & 8)    [bp-3]++;
           if (GRecords[si].kind & 0x10) [bp-2]++;
       }
       sheet = GLeaderSheets[partyIndex]
       if (sheet[0x9c] > [bp-2])      { amount = amount*7/10;  kind |= 0x10; }
       else if (sheet[0x9b] > [bp-3]) { amount = amount*8/100; kind |= 8; }
       else if (sheet[0x9a] > [bp-4]) { amount = amount*9/10;  kind |= 4; }
       return amount                  ; only `mov al,[bp-6]` at 0x4AED1

     Corrections: the counters are named for the flag they count and are initialised
     directly instead of relying on a memset over three adjacent stack slots in declaration
     order; the return is a byte because the original sets only AL - the exported
     CONCAT11((char)((uint)iVar4 >> 8), uStack_8) was modelling a stale AH; and the repeated
     `*(uint32_t *)((uint)partyIndex << 2)` reads collapse to one local. */
  byte kind4Count;
  byte kind8Count;
  byte kind10Count;
  byte value;
  uint i;
  uint32_t sheetRef;

  value = amount;
  kind4Count = 0;
  kind8Count = 0;
  kind10Count = 0;
  for (i = 0; i < GRecordCount; i++) {
    if (GRecords[i].party == partyIndex) {
      if ((GRecords[i].kind & 4) != 0) {
        kind4Count = kind4Count + 1;
      }
      if ((GRecords[i].kind & 8) != 0) {
        kind8Count = kind8Count + 1;
      }
      if ((GRecords[i].kind & 0x10) != 0) {
        kind10Count = kind10Count + 1;
      }
    }
  }
  sheetRef = *(uint32_t *)((uint)partyIndex << 2);
  if (*(byte *)((int)sheetRef + 0x9c) > kind10Count) {
    value = (byte)((uint)value * 7 / 10);
    GRecords[recordIndex].kind = GRecords[recordIndex].kind | 0x10;
  }
  else if (*(byte *)((int)sheetRef + 0x9b) > kind8Count) {
    value = (byte)(((uint)value << 3) / 100);
    GRecords[recordIndex].kind = GRecords[recordIndex].kind | 8;
  }
  else if (*(byte *)((int)sheetRef + 0x9a) > kind4Count) {
    value = (byte)((uint)value * 9 / 10);
    GRecords[recordIndex].kind = GRecords[recordIndex].kind | 4;
  }
  return value;
}



/* 55fe:3450 */

/* rounds a byte offset up to the next multiple of four */

uint __cdecl16far alignUp4(int value,uint16_t arg2,uint16_t arg3)

{
  return value + 2U & 0xfffc;
}


