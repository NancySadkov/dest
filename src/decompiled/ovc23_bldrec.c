/*
 * ovc23_bldrec.c - recovered from STRONG.EXE
 * memory block: OVC23_bldrec.c
 * range: 55fe:0000 - 55fe:345d
 * functions: 26
 */
#include "recovered.h"


/* 55fe:0000 */
byte * __cdecl16far ovc23_textAdlibNone(uint partyIndex,uint16_t outFlag,agnt_t far *agnt)

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
  byte unitTypeVal;
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
  uint dySign;
  entity_t *peVar22;
  unit_t *puVar23;
  int iVar24;
  int iVar25;
  uint16_t unaff_DI;
  uint16_t uVar26;
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
  undefined1 boundYHi;
  undefined1 boundXLo;
  undefined1 boundXHi;
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
  boundXLo = 0;
  boundXHi = 0x10;
  uVar27 = 0x5e;
  boundYHi = 0x60;
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
    unitTypeVal = ovr_ovc45_getUnitType(GfxRndSeed + iVar25);
    uVar7 = (ulong)uStack_6;
    uStack_8 =(uint16_t)(unsigned long)(byte *)CONCAT11(unitTypeVal,(byte)(uint16_t)(unsigned long)(uStack_8));
    uVar26 = (uint16_t)((ulong)GUnits >> 0x10);
    puVar23 = GUnits;
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
      iVar24 = iVar24 + (uint)BuildingTypes[unitTypeVal].size;
    }
    cVar10 = BuildingTypes[unitTypeVal].sfxType;
    uStack_6 = (byte *)CONCAT13(cVar10,(uint3)uStack_6);
    in_DX = 0x2410;
    if (((5 < puVar23[uVar15].level) && (cVar10 == -0x7a)) &&
       ((*(uint8_t *)((uint8_t *)&(uStack_8))) = (byte)(uint16_t)(unsigned long)(uStack_8) + 1, uStack_8 = (uint16_t)(unsigned long)(byte *)CONCAT11(unitTypeVal,(byte)(uint16_t)(unsigned long)(uStack_8)),
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
    if (*(char *)((int)&(Entities)[partyIndex].base.entity + 3) != -1) {
      bVar9 = ovr_agnt_compute10(&(Entities)[partyIndex].base,0);
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = (uint3)bVar9 << 8;
      uVar27 = *(undefined1 *)((int)&(Entities)[partyIndex].base.entity + 3);
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
            peVar22 = Entities;
            peVar22[partyIndex].dir =
                 peVar22[partyIndex].dir + (char)(((ulong)peVar22[partyIndex].dir / 6) % 6) * -6;
            bVar9 = (Entities)[partyIndex].base.gindex;
            (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(bVar9,(byte *)uStack_6);
            if ((AgntGs[(uint)bVar9].shortName[3] == '\x03') &&
               ('\x01' < cVar10)) {
              (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = '\x01';
            }
            if ((AgntGs[(uint)bVar9].shortName[3] == '\x01') &&
               ('\x02' < (char)(*(uint8_t *)((uint8_t *)&(uStack_8) + 1)))) {
              (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = '\x02';
            }
            cVar10 = ovc22_compute3((*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) + '\x01');
            uVar26 = (uint16_t)((ulong)Entities >> 0x10);
            bVar9 = (Entities)[partyIndex].dir + cVar10 * '\x06';
            (Entities)[partyIndex].dir = bVar9;
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
                     ((Entities + iVar24)->base).x;
            uVar20 = (int)uVar15 >> 0xf;
            uVar18 = (GLeaderSheets[uStack_a])->y -
                     (Entities)[iVar24].base.y;
            dySign = (int)uVar18 >> 0xf;
            uVar15 = (int)((uVar15 ^ uVar20) - uVar20) / 2 + ((uVar18 ^ dySign) - dySign);
          }
          if (((GLeaderSheets[uStack_a])->enemiesNear == 0) || (9 < uVar15)) break;
          ovc25_usesEntityCount((byte)uStack_a);
          if (9 < (GLeaderSheets[uStack_a])->unitsOnTile) {
            uVar26 = (uint16_t)((ulong)Entities >> 0x10);
            ovc25_usesAlignUp43((byte)uStack_a,5,((Entities + iVar24)->base).x,
                                (Entities)[iVar24].base.y,'\x01');
          }
          ovc25_usesAlignUp43((byte)uStack_a,10,
                              (GLeaderSheets[uStack_a])->x,
                              (GLeaderSheets[uStack_a])->y,'\0');
          (GLeaderSheets[uStack_a])->reportState = 1;
        }
        if ((*((char far *)GLeaderSheets[uStack_a] + 0x49) == -1) ||
           (((GLeaderSheets[uStack_a])->flags5d & 1) == 0)) break;
        ovc25_usesEntityCount((byte)uStack_a);
        bVar9 = *((byte far *)GLeaderSheets[uStack_a] + 0x49);
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
      uStack_a = (GUnits)[*(int *)(((uint)uStack_8 & 0xff) * 2 + -0x6d44)].x;
      uStack_c = (GUnits)[*(int *)(((uint)uStack_8 & 0xff) * 2 + -0x6d44)].y;
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
    if ((AgntGs[(uint)*(byte *)((int)sheetPtr + 0x3e)].flags &
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
          bVar9 = (Entities)[uStack_a].base.gindex;
          pbVar14 = (byte *)(uint)AgntGs[(uint)bVar9].ai;
          if (pbVar14 == (byte *)0x0) {
            alignUp4(((Entities + iVar24)->base).x,0,0);
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
                    (*(byte *)((int)&(Entities)[iVar25].base.entity + 3));
          pbVar14 = (byte *)(iVar25 * 0x37);
          if ((Entities)[iVar25].base.animFrame != 0x0) {
            ovc24_usesLDIV_at_(iVar25);
            uVar26 = (uint16_t)((ulong)Entities >> 0x10);
            peVar22 = Entities;
            if ((((AgntGs[(uint)peVar22[uStack_a].base.gindex].flags2 & 4) != 0) &&
                ((*(uint *)((int)&peVar22[iVar25].base.frames + 1) & 1) == 0)) &&
               (uVar15 = ovr_ovc27_rollToHitAgent
                                   (CONCAT13((char)((ulong)Entities >> 0x18),
                                             CONCAT12((char)((ulong)Entities >> 0x10),
                                                      peVar22 + iVar25)),0), (uVar15 & 0xff) == 0))
            {
              puVar1 = (uint *)((int)&(Entities)[iVar25].base.frames + 1);
              *puVar1 = *puVar1 | 1;
              alignUp4(((Entities + iVar24)->base).x,0,0);
              iVar12 = (uint)(Entities)[iVar25].base.gindex * 0x95;
              uVar26 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar12);
              pcVar19 = ovr_fmVsprintf("Intelligence reports %s unit infected with disease. (%d, %d)"
                                       ,(char *)CONCAT13((char)((uint)uVar26 >> 8),
                                                         CONCAT12((char)uVar26,
                                                                  *(uint16_t *)
                                                                   ((int)&worldMenuLabels[0].seg + 1
                                                                   + iVar12))));
              ovr_uiNotify(pcVar19,0,0);
            }
            pbVar14 = (byte *)((uint)(Entities)[uStack_a].base.gindex * 0x95);
            if ((*(uint *)(pbVar14 + 0x2714) & 0xc00) != 0) {
              uVar15 = ovr_ovc27_rollToHitAgent
                                 (CONCAT13((char)((ulong)Entities >> 0x18),
                                           CONCAT12((char)((ulong)Entities >> 0x10),
                                                    Entities + iVar25)),3);
              pbVar14 = (byte *)(uVar15 & 0xff);
              if (pbVar14 == (byte *)0x0) {
                if ((AgntGs[(uint)(Entities)[uStack_a].base.gindex].flags2 & 0x800)
                    == 0) {
                  cVar10 = '\x01';
                }
                else {
                  cVar10 = '\x02';
                }
                uVar26 = ovr_ovc27_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                                     CONCAT12((char)((ulong)Entities >> 0x10),
                                                              Entities + iVar25)),
                                            cVar10);
                if ((char)uVar26 != '\0') {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  uVar26 = (uint16_t)((ulong)Entities >> 0x10);
                  if ((Entities)[iVar25].base.animFrame != 0x0) {
                    puVar3 = &(Entities)[iVar25].base.animFrame;
                    *puVar3 = *puVar3 + 0xff;
                  }
                }
                alignUp4(((Entities + iVar24)->base).x,0,0);
                iVar24 = (uint)(Entities)[iVar25].base.gindex * 0x95;
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
    pbVar14 = (byte far *)Entities[iVar24].base.y;
    if ((pbVar14 != (byte *)CONCAT11(boundYHi,uVar27)) ||
       (pbVar14 = (byte *)alignUp4(((Entities + iVar24)->base).x,0,0),
       pbVar14 != (byte *)CONCAT11(boundXHi,boundXLo))) goto L_OVC24_5943_026e_08A7;
    uVar26 = (uint16_t)((ulong)Entities >> 0x10);
    peVar22 = Entities;
    if (AgntGs[(uint)peVar22[iVar24].base.gindex].ai ==
        (char)uStack_10) {
      if (peVar22[iVar24].base.level < bStackY_2d) {
L_OVC24_5943_026e_0772:
        uVar26 = (uint16_t)((ulong)Entities >> 0x10);
        bVar9 = (Entities)[iVar24].base.gindex;
        if ((((AgntGs[(uint)bVar9].flags3 & 0x40) == 0) ||
            (pbVar14 = &stk_ffde + (uStack_10 ^ 1), '\x01' < (char)*pbVar14)) &&
           ((((AgntGs[(uint)bVar9].flags2 & 8) == 0 ||
             (pbVar14 = &stk_ffde + (uStack_10 ^ 1), '\0' < (char)*pbVar14)) &&
            (((AgntGs[(uint)bVar9].flags2 & 0x10) == 0 ||
             (pbVar14 = &stk_ffdc + (uStack_10 ^ 1), -1 < (char)*pbVar14)))))) {
          bStackY_2d = (Entities)[iVar24].base.level;
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
      bStackY_2e = (Entities)[iVar24].base.level;
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

bool __cdecl16far ovc23_tickRecordsAt(uint16_t x,int y,char excluded,uint16_t arg4)

{
  byte party;
  uint32_t sheetRef;
  uint alignedX;
  uint i;
  bool found;
  
  alignedX = ovr_alignUp4(x,0,0);
  found = 0;
  for (i = 0; i < GRecordCount; i = i + 1) {
    if ((((GRecords[i].y == y) && (GRecords[i].x <= alignedX + 1)) &&
        (alignedX - 2 <= (GRecords[i].x + (uint)GRecords[i].width) - 1)) &&
       ((party = GRecords[i].party, party != 0xff &&
        (sheetRef = *(uint32_t *)((uint)party << 2), *(char *)((int)sheetRef + 0x3f) == excluded)))) {
      GRecords[i].tick = GameTick;
      if (GRecords[i].countdown != '\0') {
        GRecords[i].countdown = GRecords[i].countdown - 1;
      }
      if (GRecords[i].countdown == '\0') {
        GRecords[i].state = 1;
      }
      found = 1;
    }
  }
  return found;
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
  int smoothTL;
  int smoothBL;
  int minEdge;
  uint shadeBias;
  int cornerSampleBR;
  int cornerSample;
  static char cornerBR[64];
  static char cornerBL[64];
  static char cornerTR[64];
  static char cornerTL[64];
  int minShade;
  
  smoothTL = ovr_constr_usesSmoothPrev(x,-1,(int *)&cornerTL,0,0);
  smoothBL = ovr_constr_usesSmoothPrev(x,0,(int *)&cornerBL,0,0);
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
  shadeBias = (uint)cornerShadeBias[0];
  minShade = smoothBL + smoothTL + cornerSample + cornerSampleBR >> 2;
  if ((int)(smoothTL - shadeBias) < (int)(cornerSample - shadeBias)) {
    minEdge = smoothTL - shadeBias;
  }
  else {
    minEdge = cornerSample - shadeBias;
  }
  if (minShade < minEdge) {
    if ((int)(smoothTL - shadeBias) < (int)(cornerSample - shadeBias)) {
      minShade = smoothTL - shadeBias;
    }
    else {
      minShade = cornerSample - shadeBias;
    }
  }
  return minShade;
}



/* 55fe:0768 */

/* [R6] touches cornerBR, cornerBL */

int __cdecl16far ovc23_usesCornerBR2(int x,int step)

{
  int cornerSampleTL;
  int iVar2;
  int iStack_12;
  static char cornerBR[64];
  static char cornerBL[64];
  static char cornerTR[64];
  static char cornerTL[64];
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
  
  iVar1 = (uint)(GUnits + ((short (*) [148] [60])GUnitGrid)[-1][x + 0x93][y])->bldType *
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

uint __cdecl16far ovc23_usesAlignUp43(int x,int y,byte dir)

{
  /* Re-derived from 55fe:0af5 (482 bytes; retf at 0x0cd6, 4-entry table at 0x0cd7).  Returns 1
     when the neighbouring unit cell in `dir` holds a placed building whose BuildingTypes flag
     byte at +0x11e has that direction's bit, 0 otherwise; the opening attact_usesGUnits test
     returns 1 immediately when the stepped cell is empty.  Cases 2 and 3 address the same cell
     (GUnitGrid[x][y]); that is what the instructions do, so it is kept as decoded. */
  uint idx;
  byte bldType;

  if ((char)ovr_attact_usesGUnits(x + *(char *)(dir + 0x885),
                                  y + *(char *)(dir + 0x889)) == '\0') {
    return 1;
  }
  switch(dir) {
  case 0:
    idx = (*(short (*) [148] [60])GUnitGrid)[x][y + -1];
    bldType = (GUnits + idx)->bldType;
    if ((bldType < 0xf8) && ((BuildingTypes[(uint)bldType].flags & 1) != 0)) {
      return 1;
    }
    break;
  case 1:
    idx = (*(short (*) [148] [60])GUnitGrid)[x + 1][y];
    bldType = (GUnits + idx)->bldType;
    if ((bldType < 0xf8) && ((BuildingTypes[(uint)bldType].flags & 2) != 0)) {
      return 1;
    }
    break;
  case 2:
    idx = (*(short (*) [148] [60])GUnitGrid)[x][y];
    bldType = (GUnits + idx)->bldType;
    if ((bldType < 0xf8) && ((BuildingTypes[(uint)bldType].flags & 1) != 0)) {
      return 1;
    }
    break;
  case 3:
    idx = (*(short (*) [148] [60])GUnitGrid)[x][y];
    bldType = (GUnits + idx)->bldType;
    if ((bldType < 0xf8) && ((BuildingTypes[(uint)bldType].flags & 2) != 0)) {
      return 1;
    }
    break;
  }
  return 0;
}



/* 55fe:0cdf */
bool __cdecl16far ovc23_textConstructionAbandoned(int x,int y,byte dir)

{
  /* Re-derived from 55fe:0cdf (594 bytes; retf at 0x251, jump table at ip 0xf31 -> 0x65, 0xe2,
     0x166, 0x1dd).  Returns true when the neighbouring cell in `dir` holds a placed building that
     still has construction going on: the direction's own bit (1 for 0 and 2, 2 for 1 and 3) and
     the shared 0x20 bit must both be set in BuildingTypes[bldType].flags.  Cases 2 and 3 read the
     same cell (GUnitGrid[x][y]), which is what the instructions do. */
  byte bldType;
  uint idx;

  if ((char)ovr_attact_usesGUnits(x + *(char *)(dir + 0x885),
                                 y + *(char *)(dir + 0x889)) == '\0') {
    return false;
  }
  switch(dir) {
  case 0:
    idx = (*(short (*) [148] [60])GUnitGrid)[x][y + -1];
    break;
  case 1:
    idx = (*(short (*) [148] [60])GUnitGrid)[x + 1][y];
    break;
  case 2:
    idx = (*(short (*) [148] [60])GUnitGrid)[x][y];
    break;
  case 3:
    idx = (*(short (*) [148] [60])GUnitGrid)[x][y];
    break;
  default:
    return false;
  }
  bldType = (GUnits + idx)->bldType;
  if (0xf8 <= bldType) {
    return false;
  }
  if ((dir == 0) || (dir == 2)) {
    if ((BuildingTypes[bldType].flags & 1) == 0) {
      return false;
    }
  }
  else if ((BuildingTypes[bldType].flags & 2) == 0) {
    return false;
  }
  if ((BuildingTypes[bldType].flags & 0x20) == 0) {
    return false;
  }
  return true;
}


/* 55fe:0f39 */

/* Rebuilds the four direction bits of a map cell from its neighbour tests. */

void __cdecl16far ovc23_rebuildDirectionFlags(int x,int y)

{
  /* Re-derived: clears the four direction bits in the cell's flag word (& 0xff0f), then for
     each of the four directions sets 0x10<<d when ovc23_usesAlignUp43 reports the direction is
     usable and 0x100<<d when the construction there is abandoned. */
  uint16_t *flagWord;
  bool abandoned;
  uint dirResult;
  byte dir;

  if ((((x < 0x94) && (-1 < x)) && (y < 0x3c)) && (-1 < y)) {
    flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
    *flagWord = *flagWord & 0xff0f;
    for (dir = 0; dir < 4; dir = dir + 1) {
      dirResult = ovc23_usesAlignUp43(x,y,dir);
      if ((char)dirResult != '\0') {
        flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
        *flagWord = *flagWord | 0x10 << (dir & 0x1f);
      }
      abandoned = ovc23_textConstructionAbandoned(x,y,dir);
      if (abandoned) {
        flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
        *flagWord = *flagWord | 0x100 << (dir & 0x1f);
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
  uint16_t *flagPtr;
  byte cellBldType;
  int unitIdx;
  uint16_t cellType;
  uint newUnitIdx;
  
  unitIdx = (*(short (*) [148] [60])GUnitGrid)[x][y];
  cellBldType = (GUnits + unitIdx)->bldType;
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
      unitFlagsPtr = &(GUnits)[newUnitIdx].flags;
      *unitFlagsPtr = *unitFlagsPtr | 4;
      flagPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x);
      *flagPtr = *flagPtr & 0xfffc;
    }
    if ((BuildingTypes[bldType].flags & 4) != 0) {
      if (((*(short (*) [60] [148])GMapFlags)[y][x + 0x93] & 3U) != 0) {
        unitFlagsPtr = &(GUnits)[newUnitIdx].flags;
        *unitFlagsPtr = *unitFlagsPtr | 8;
        flagPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x + 0x93);
        *flagPtr = *flagPtr & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -2,y);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
      }
      if (((*(short (*) [60] [148])GMapFlags)[y + 1][x + 1] & 3U) != 0) {
        unitFlagsPtr = &(GUnits)[newUnitIdx].flags;
        *unitFlagsPtr = *unitFlagsPtr | 0x10;
        flagPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x + 1);
        *flagPtr = *flagPtr & 0xfffc;
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x + 2,y);
      }
    }
    if ((BuildingTypes[bldType].flags & 8) != 0) {
      if (((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) != 0) {
        unitFlagsPtr = &(GUnits)[newUnitIdx].flags;
        *unitFlagsPtr = *unitFlagsPtr | 8;
        flagPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
        *flagPtr = *flagPtr & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x,y + -2);
      }
      if (((*(short (*) [60] [148])GMapFlags)[y + 2][x] & 3U) != 0) {
        unitFlagsPtr = &(GUnits)[newUnitIdx].flags;
        *unitFlagsPtr = *unitFlagsPtr | 0x10;
        flagPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y + 2] + x);
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
    if (((GUnits)[unitIdx].flags & 4) != 0) {
      ovc23_drownUnitsAt(x,y);
    }
    if (BuildingTypes[cellBldType].flags == '\x04') {
      cellType = ovr_ovc45_getUnitType(x + -1,y);
      if ((cellType == 0) && (((GUnits)[unitIdx].flags & 8) != 0)) {
        ovc23_usesGfxRndSeed2(x + -1,y);
        ovc23_drownUnitsAt(x - 1,y);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
        ovc23_rebuildDirectionFlags(x + -2,y);
      }
      cellType = ovr_ovc45_getUnitType(x + 1,y);
      if ((cellType == 0) && (((GUnits)[unitIdx].flags & 0x10) != 0))
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
      if ((cellType == 0) && (((GUnits)[unitIdx].flags & 8) != 0)) {
        ovc23_usesGfxRndSeed2(x,y + -1);
        ovc23_drownUnitsAt(x,y - 1);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x,y + -2);
      }
      cellType = ovr_ovc45_getUnitType(x,y + 1);
      if ((cellType == 0) && (((GUnits)[unitIdx].flags & 0x10) != 0))
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
  agnt_t far *in_stack_00000000;
  
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
  undefined1 uStack000d;
  byte in_stack_0000000e;
  char in_stack_00000010;
  agnt_t far *in_stack_0000fff6;
  uint uStack_8;
  byte bStack_5;
  byte bStack_3;
  
  outFlag = (undefined1 *)CONCAT13(uStack000d,CONCAT12(partyIndex,outFlag));
  for (uStack_8 = 0; (int)uStack_8 < (int)(uint)BuildingTypes[bldType].size;
      uStack_8 = uStack_8 + 1) {
    in_stack_0000fff6 = (agnt_t far *)ovc23_findRecordAt(x + uStack_8,y,0);
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
    if ((char)iVar4 == '\0') {
      bStack_5 = (GUnits + (*(short (*) [148] [60])GUnitGrid)[x][y])->bldType;
    }
    else {
      bStack_5 = (GUnits + ((short (*) [148] [60])GUnitGrid)[-1][x + 0x93][y])->bldType;
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
  byte state;
  byte frame;
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
  uint8_t typeByte;
  uint spanCount;
  uint spanLeft;
  int curY;
  uint16_t gfxOfs;
  uint16_t gfxSeg;
  
  spanCount = (uint)GRecords[y].frameCount;
  buildTimer = GRecords[y].buildTimer;
  state = GRecords[y].state;
  frame = GRecords[y].frame;
  if (frame < spanCount) {
    spanCount = frame + 1;
  }
  x_00 = in_stack_00000004 + -1;
  curY = x + spanCount * -0x26 + -0x32;
  spanLeft = spanCount;
  while (spanLeft = spanLeft - 1, -1 < (int)spanLeft) {
    y_00 = curY + 0x26;
    typeByte = (uint8_t)rect;
    if ((state == 2) || (0x13 < buildTimer)) {
      if (state < 2) {
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
          ovr_blitGfxRect(gfx_01,in_stack_00000004 + 0xe,curY + 0x8b,(brect_t *)recordIndex,typeByte,true,1,0,0,0,0,0);
        }
        gfx_02.seg = gfxSeg;
        gfx_02.ofs = gfxOfs;
        ovr_blitGfxRect(gfx_02,x_00,y_00,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        if ((buildTimer + spanLeft + GfxRndSeed2 + x_00 & 0x1f) < 0x11) {
          animPhase = buildTimer + spanLeft + GfxRndSeed2 + x_00 & 0x1f;
          gfx_03.seg = ((uint16_t *)&tmstrsSprites5Seg)[animPhase * 2];
          gfx_03.ofs = ((uint16_t *)&tmstrsSprites5Ofs)[animPhase * 2];
          ovr_blitGfxRect(gfx_03,x_00 + ((uint)*(byte *)((buildTimer + spanLeft + GfxRndSeed2 + x_00 >> 5
                                                         ) + spanLeft + GfxRndSeed2 & 0xff) * 0x50)
                                        / 0x100,curY + 0x66,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        }
        if ((((buildTimer + spanLeft) - GfxRndSeed2) - x_00 & 0xf) < 7) {
          animPhase = ((buildTimer + spanLeft) - GfxRndSeed2) - x_00 & 0xf;
          gfx_04.seg = ((uint16_t *)&tmstrsSprites4Seg)[animPhase * 2];
          gfx_04.ofs = ((uint16_t *)&tmstrsSprites4Ofs)[animPhase * 2];
          ovr_blitGfxRect(gfx_04,x_00 + ((uint)*(byte *)((((((buildTimer + spanLeft) - GfxRndSeed2) -
                                                            x_00 >> 4) + spanLeft) - GfxRndSeed2) +
                                                         0xe & 0xff) * 0x50) / 0x100,curY + 0x66,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        }
        animPhase = (buildTimer + 5) % 7;
        gfx_05.seg = ((uint16_t *)&tmstrsSprites3Seg)[animPhase * 2];
        gfx_05.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[animPhase * 2];
        ovr_blitGfxRect(gfx_05,in_stack_00000004 + 9,curY + 0x62,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        gfx_06.seg = ((uint16_t *)&tmstrsSprites3Seg)[(buildTimer % 7) * 2];
        gfx_06.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[(buildTimer % 7) * 2];
        ovr_blitGfxRect(gfx_06,in_stack_00000004 + 0xd,curY + 0x62,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        animPhase = (buildTimer + 2) % 7;
        gfx_07.seg = ((uint16_t *)&tmstrsSprites3Seg)[animPhase * 2];
        gfx_07.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[animPhase * 2];
        ovr_blitGfxRect(gfx_07,in_stack_00000004 + 0x31,curY + 0x62,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        animPhase = buildTimer + 3 & 7;
        gfx_08.seg = ((uint16_t *)&tmstrsSprites2Seg)[animPhase * 2];
        gfx_08.ofs = ((uint16_t *)&tmstrsSprites2Ofs)[animPhase * 2];
        ovr_blitGfxRect(gfx_08,in_stack_00000004 + 0x45,curY + 0x62,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        gfx_09.seg = ((uint16_t *)&tmstrsSprites2Seg)[(buildTimer & 7) * 2];
        gfx_09.ofs = ((uint16_t *)&tmstrsSprites2Ofs)[(buildTimer & 7) * 2];
        ovr_blitGfxRect(gfx_09,in_stack_00000004 + 0x3b,curY + 0x62,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        gfx_10.seg = ((uint16_t *)&tmstrsSprites1Seg)[(buildTimer % 5) * 2];
        gfx_10.ofs = ((uint16_t *)&tmstrsSprites1Ofs)[(buildTimer % 5) * 2];
        ovr_blitGfxRect(gfx_10,in_stack_00000004 + 0x27,curY + 0x62,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        gfx_11.seg = ((uint16_t *)&tmstrsSprites1Seg)[(buildTimer % 5) * 2];
        gfx_11.ofs = ((uint16_t *)&tmstrsSprites1Ofs)[(buildTimer % 5) * 2];
        ovr_blitGfxRect(gfx_11,in_stack_00000004 + 0x3f,curY + 0x62,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        curY = y_00;
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
        ovr_blitGfxRect(gfx_00,x_00,y_00,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        curY = y_00;
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
      ovr_blitGfxRect(gfx,x_00,y_00,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
      curY = y_00;
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
  char bldFlags;
  byte neighbourType;
  int recOfs;
  int stepCoord;
  uint result;
  
  bldFlags = BuildingTypes[bldType].flags;
  if (bldFlags == '\0') {
    result = 0;
  }
  else if (bldFlags == '\x01') {
    neighbourType = ovr_ovc45_getUnitType(x,y + -1);
    if (BuildingTypes[neighbourType].flags == '\x02') {
      ovc23_placeBuilding(x,y,bldType + 2,unitType);
    }
    else {
      ovc23_placeBuilding(x,y,bldType,unitType);
    }
    neighbourType = ovr_ovc45_getUnitType(x + -1,y);
    recOfs = (uint)neighbourType * 0x27;
    if (*(char *)(recOfs + 0x11e) == '\x02') {
      stepCoord = x + -1;
      ovc23_placeBuilding(stepCoord,y,neighbourType + 1,unitType);
    }
    result = CONCAT11((char)((uint)stepCoord >> 8),1);
  }
  else if (bldFlags == '\x02') {
    neighbourType = ovr_ovc45_getUnitType(x + 1,y);
    if (BuildingTypes[neighbourType].flags == '\x01') {
      ovc23_placeBuilding(x,y,bldType + 1,unitType);
    }
    else {
      ovc23_placeBuilding(x,y,bldType,unitType);
    }
    neighbourType = ovr_ovc45_getUnitType(x,y + 1);
    recOfs = (uint)neighbourType * 0x27;
    if (*(char *)(recOfs + 0x11e) == '\x01') {
      stepCoord = y + 1;
      ovc23_placeBuilding(x,stepCoord,neighbourType + 2,unitType);
    }
    result = CONCAT11((char)((uint)stepCoord >> 8),1);
  }
  else if (bldFlags == '!') {
    neighbourType = ovr_ovc45_getUnitType(x + -1,y);
    result = (uint)neighbourType * 0x27;
    if (*(char *)(result + 0x11e) == '\x02') {
      result = x - 1;
      ovc23_placeBuilding(result,y,neighbourType + 1,unitType);
    }
    result = result & 0xff00;
  }
  else if (bldFlags == '\"') {
    neighbourType = ovr_ovc45_getUnitType(x,y + 1);
    result = (uint)neighbourType * 0x27;
    if (*(char *)(result + 0x11e) == '\x01') {
      result = y + 1;
      ovc23_placeBuilding(x,result,neighbourType + 2,unitType);
    }
    result = result & 0xff00;
  }
  else {
    result = 0;
  }
  return result;
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
  uint16_t *flagPtr;
  char *entName;
  char *message;
  uint16_t dst;
  uint entityIndex;
  uint16_t notifySeg;
  uint16_t msgX;
  uint16_t msgY;
  static char text2[64];   /* DGROUP-backed formatting buffer */
  static char text[64];   /* DGROUP-backed formatting buffer */
  int clearCol;
  byte gindex;
  
  flagPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x);
  *flagPtr = *flagPtr | 3;
  entityIndex = EntityCount;
  while (entityIndex = entityIndex - 1, -1 < (int)entityIndex) {
    notifySeg = (uint16_t)((ulong)Entities >> 0x10);
    if (((Entities)[entityIndex].base.x == x) &&
       ((Entities)[entityIndex].base.y == y)) {
      clearCol = ovc23_findClearColumn(x,y);
      notifySeg = (uint16_t)((ulong)Entities >> 0x10);
      if (clearCol < 0) {
        gindex = (Entities)[entityIndex].base.gindex;
        if (AgntGs[(uint)gindex].ai == '\0') {
          notifySeg = 0xa000;
          dst = 0x195d;
          msgX = x;
          msgY = y;
          entName = ovr_ovc15_capitalize(text2);
          message = ovr_stsprintf(text,(char *)CONCAT22(0x5665,_SS),
                                 (char *)CONCAT22(entName,(char *)0x26510),dst,msgX,msgY,
                                 notifySeg);
          ovr_uiNotify(message,dst,0);
        }
        ovr_ovc15_removeEntity(entityIndex);
      }
      else {
        (Entities)[entityIndex].base.x = clearCol;
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
     `(uint32_t)GLeaderSheets[partyIndex]` reads collapse to one local. */
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
  sheetRef = (uint32_t)GLeaderSheets[partyIndex];
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


