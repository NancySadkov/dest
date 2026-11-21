/*
 * ovc23_bldrec.c - recovered from STRONG.EXE
 * memory block: OVC23_bldrec.c
 * range: 55fe:0000 - 55fe:345d
 * functions: 26
 */
#include "recovered.h"


/* 55fe:0000 */
byte * __cdecl16far ovc23_textAdlibNone(uint partyIndex,uint16_t outFlag,agnt_t *agnt,...)

{
  uint *puVar1;
  int *piVar2;
  uint8_t *puVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  far_t entries;
  ulong uVar7;
  ulong uVar8;
  byte bVar9;
  char cVar10;
  byte bVar11;
  int iVar12;
  undefined4 *puVar13;
  byte *pbVar14;
  uint uVar15;
  uint16_t uVar16;
  uint16_t uVar17;
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
  undefined2 uVar26;
  char *unaff_SS;
  undefined2 in_stack_0000000a;
  char acStackY_13e [36];
  undefined2 auStackY_11a [66];
  undefined2 auStackY_96 [23];
  char acStackY_68 [2];
  undefined1 auStackY_66 [56];
  byte bStackY_2e;
  byte bStackY_2d;
  uint16_t uStackY_2c;
  undefined2 uStackY_2a;
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
  byte bStack_e;
  uint uStack_c;
  uint16_t uStack_a;
  undefined2 uStack_8;
  undefined4 uStack_6;
  
  uStack_10 = 0;
  uStack_a = ovr_alignUp4(GfxRndSeed);
  for (iVar24 = 0; iVar24 < 4; iVar24 = iVar24 + 1) {
    in_DX = 0x2410;
    uStack_10 = uStack_10 |
                ((short (*) [60] [148])GMapFlags)[-1][GfxRndSeed2 + 0x3b][uStack_a + iVar24 + 0x92]
                & 0x3000U;
  }
  cursorRecordFound = '\0';
  _fmemset((void *)0xff2410,8,unaff_DI);
  uVar29 = 0;
  uVar30 = 0x10;
  uVar27 = 0x5e;
  uVar28 = 0x60;
  _fmemset((void *)0x2410,4,unaff_DI);
  for (uStack_c = 0; uStack_c < GRecordCount; uStack_c = uStack_c + 1) {
    in_DX = 0x2410;
    if ((*(int *)(uStack_c * 0x12 + 4) == GfxRndSeed2) &&
       (in_DX = 0x21f2, (*(byte *)(uStack_c * 0x12 + 0xd) & 1) != 0)) {
      bVar9 = *(byte *)(uStack_c * 0x12 + 7);
      uStack_6 = (byte *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),bVar9);
      iVar24 = *(int *)(uStack_c * 0x12 + 2) - (GfxRndSeed + -2);
      in_DX = (iVar24 + (uint)bVar9) - 1;
      if ((0 < (int)(iVar24 + (uint)bVar9)) && (iVar24 < 4)) {
        if (20000 < *(uint *)(uStack_c * 0x12)) {
          *(undefined2 *)(uStack_c * 0x12) = 3;
        }
        in_DX = 0x21f2;
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
  (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t) (byte *)CONCAT11(0xff,(char)uStack_6);
  uStack_8 =(uint16_t) (byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) << 8);
  for (iVar25 = -2; cVar10 = (char)unaff_DI, iVar25 < 2; iVar25 = iVar25 + 1) {
    uVar15 = ovr_ovc45_getUnitIndex(GfxRndSeed + iVar25);
    bVar11 = ovr_ovc45_getUnitType(GfxRndSeed + iVar25);
    uVar7 = (ulong)uStack_6;
    uStack_8 =(uint16_t) (byte *)CONCAT11(bVar11,(byte)uStack_8);
    uVar26 = (undefined2)((ulong)GUnits >> 0x10);
    puVar23 = (unit_t *)GUnits;
    bVar9 = puVar23[uVar15].unitType;
    (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(bVar9,(byte *)uStack_6);
    uStack_6 = (byte *)(ulong)(uint3)uStack_6;
    uVar8 = (ulong)uStack_6;
    uStack_6 = (byte *)uVar8;
    if (((0xf7 < uVar15) && (bVar9 != 0xff)) &&
       ((*(char *)((int)*(undefined4 *)((uint)bVar9 << 2) + 0x3f) == '\0' &&
        ((*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) = SUB41(uVar7,1), bVar4 = puVar23[uVar15].level <= (*(uint8_t *)((uint8_t *)&(uStack_6) + 1)), bVar4))))
    {
      (*(uint8_t *)((uint8_t *)&(uStack_6))) = (char)uVar7;
      (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t) (byte *)CONCAT11(puVar23[uVar15].level,(char)uStack_6);
      uStack_6 = (byte *)(ulong)CONCAT12(bVar9,(byte *)uStack_6);
    }
    uVar7 = (ulong)uStack_6;
    if ((*(char *)((int)*(undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 2)) << 2) + 0x3f) == '\0') &&
       (puVar23[uVar15].unitType != 0xff)) {
      iVar24 = iVar24 + (uint)*(byte *)((uint)bVar11 * 0x27 + 0x11b);
    }
    cVar10 = *(char *)((uint)bVar11 * 0x27 + 0x132);
    uStack_6 = (byte *)CONCAT13(cVar10,(uint3)uStack_6);
    in_DX = 0x2410;
    if (((5 < puVar23[uVar15].level) && (cVar10 == -0x7a)) &&
       ((*(uint8_t *)((uint8_t *)&(uStack_8))) = (byte)uStack_8 + 1, uStack_8 = (byte *)CONCAT11(bVar11,(byte)uStack_8),
       (byte)uStack_8 < 2)) {
      uStack_6 = (byte *)uVar7;
    }
    if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) != 0x0) {
      if (CurSfxType3 == 0xff) {
        in_DX = CONCAT11(0x24,(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)));
        CurSfxType3 = (*(uint8_t *)((uint8_t *)&(uStack_6) + 3));
      }
      else {
        uVar16 = ovr_randBelow(2);
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
  switch(pbVar14) {
  case (byte *)0x0:
    *(char *)((int)pbVar14 * 2) = *(char *)((int)pbVar14 * 2) + (char)(in_DX >> 8);
    uStack_c = (uint)(byte)((byte)uVar15 & (byte)*(undefined2 *)(&stack0x02c2 + iVar24));
    uVar16 = ovr_randBelow(in_stack_0000ffd8);
    uVar17 = ovr_randBelow(uStackY_2c);
    uStack_6 = (byte *)(CONCAT22(uVar17,(byte *)uStack_6) & 0xffffff);
    uVar33 = 0x83;
    uVar34 = 0x9a;
    uVar17 = ovr_randBelow(in_stack_0000ffd8);
    uStack_6 = (byte *)(CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),uVar17) & 0xffff00ff);
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
    if ((byte *)((int)(undefined4 *)&_DATA + 2) < pbVar14) {
      uStack_8 =(uint16_t) (byte *)((int)(undefined4 *)&_DATA + 2);
    }
    bStackY_2d = 0xff;
    bStackY_2e = 0;
    iVar25 = -1;
    uStack_a = -1;
    iVar24 = CONCAT11(uVar34,uVar33);
    break;
  case (byte *)0x1:
    TextBlitX = in_DX - (int)pbVar14;
    ovr_blitLabel((char *)"UNITS");
    iVar25 = ovr_font_textWidth((char *)"POPULATION");
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
        uVar5 = *(undefined4 *)((partyIndex & 0xff) << 2);
        ovr_blitLabel((char *)auStackY_11a[iVar25 * 2 + (uint)*(byte *)((int)uVar5 + 0x2f) * 8]);
      }
      func_0x0005f303();
      ovr_stsprintf(acStackY_13e);
      iVar12 = ovr_font_textWidth(acStackY_13e);
      TextBlitX = 0x89 - iVar12;
      ovr_blitLabel(acStackY_13e);
      ovr_stsprintf(acStackY_13e);
      iVar12 = ovr_font_textWidth(acStackY_13e);
      uVar16 = 0xd4 - iVar12;
      TextBlitX = uVar16;
      ovr_blitLabel(acStackY_13e);
    }
    CurSfxType3 = 0x3c;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = (char)unaff_SS;
    entries.ofs = (uint16_t)auStackY_66;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = (char)((uint)unaff_SS >> 8);
    uVar26 = ovr_ovc28_usesUiInputText(entries);
    cVar10 = (char)uVar26;
    keyboardInputMode = 0;
    if (((cVar10 != '\0') && (cVar10 != '\x01')) && (cVar10 != -2)) {
      (&stack0xbac4)[iVar24] = (&stack0xbac4)[iVar24] + in_CL;
      iVar24 = 0x2410;
      do {
        iVar12 = iVar24 * uVar16;
        iVar24 = iVar25;
        if (*(byte *)(iVar25 * 0x34 + 0x22) < *(byte *)(iVar12 + 0x21)) {
          *(undefined1 *)(iVar25 * 0x34 + 0x21) = *(undefined1 *)(iVar25 * 0x34 + 0x22);
        }
        do {
          iVar24 = iVar24 + 1;
          if ((int)(uint)AgntCount <= iVar24) {
            iVar24 = ovr_audio_panFromX(agnt);
            uVar27 = (undefined1)((uint)iVar24 >> 8);
            ovr_play_sfxU(0x1c);
            return (byte *)CONCAT11(uVar27,1);
          }
        } while (*(uint16_t *)(iVar24 * 0x34 + 0x1b) != agnt->owner);
        uVar26 = (undefined2)((ulong)uStack_6 >> 0x10);
        if (*(byte *)((int)uStack_6 + 0x32) < *(byte *)(iVar24 * 0x34 + 0x22)) {
          *(undefined1 *)(iVar24 * 0x34 + 0x22) = *(undefined1 *)((int)uStack_6 + 0x32);
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
      bVar9 = ovr_agnt_compute10(&((entity_t *)Entities)[partyIndex].base);
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = (uint3)bVar9 << 8;
      uVar27 = *(undefined1 *)((int)&((entity_t *)Entities)[partyIndex].base.entity + 3);
      pbVar14 = (byte *)CONCAT11((char)(partyIndex * 0x37 >> 8),uVar27);
      uStack_6 = (byte *)CONCAT13(uVar27,(uint3)uStack_6);
      while (cVar10 = (char)uStack_6, (char)uStack_6 < '\x04') {
        pbVar14 = (byte *)((char)uStack_6 * 2);
        if (*(int *)(pbVar14 + (int)*(undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) << 2) + 0x76) != 0) {
          pbVar14 = (byte *)(int)(char)(*(uint8_t *)((uint8_t *)&(uStack_6) + 1));
          if ((int)pbVar14 < (char)uStack_6 + 1) {
            (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = (char)uStack_6;
            piVar2 = (int *)((int)*(undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) << 2) + (char)uStack_6 * 2 +
                            0x76);
            *piVar2 = *piVar2 + -1;
            uVar26 = (undefined2)((ulong)Entities >> 0x10);
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
            uVar26 = (undefined2)((ulong)Entities >> 0x10);
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
      if (*(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x47) < 10) {
        ovc25_usesAlignUp43((byte)uStack_a,10,
                            *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                            *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b),'\0');
        *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 0;
      }
      else {
        *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 0;
        iVar25 = ovc25_compute1(*(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x3e));
        uStack_6 = (byte *)CONCAT22(iVar25,(byte *)uStack_6);
        if ((int)(uint)PlayerCount < iVar25) {
          uVar16 = ovr_randBelow(0x28);
          iVar25 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) + -0x14 + (uVar16 & 0xff);
          (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t) (byte *)iVar25;
          if (iVar25 < 4) {
            (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t) (byte *)0x4;
          }
          if (0x8c < (int)(byte *)uStack_6) {
            uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),0x8b);
          }
          uVar16 = ovr_randBelow(0x14);
          uStack_8 = (byte *)(*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) + -10 +
                             (uVar16 & 0xff));
          if ((int)uStack_8 < 1) {
            uStack_8 =(uint16_t) (byte *)0x1;
          }
          if (0x3a < (int)uStack_8) {
            uStack_8 =(uint16_t) (byte *)0x3a;
          }
          ovc25_usesAlignUp44((char)uStack_a,1);
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
          } while ((*(char *)((int)*(undefined4 *)(uStack_a * 4) + 0x40) == '\0') ||
                  (*(char *)((int)*(undefined4 *)(uStack_a * 4) + 0x3d) == '\0'));
          ovc25_intelAttackingNotice((byte)uStack_a);
          if (*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x4b) == -1) {
            uVar15 = 0xffff;
          }
          else {
            iVar24 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x4b);
            uVar26 = (undefined2)((ulong)Entities >> 0x10);
            uVar15 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                     (((entity_t *)Entities + iVar24)->base).x;
            uVar20 = (int)uVar15 >> 0xf;
            uVar18 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) -
                     ((entity_t *)Entities)[iVar24].base.y;
            uVar21 = (int)uVar18 >> 0xf;
            uVar15 = (int)((uVar15 ^ uVar20) - uVar20) / 2 + ((uVar18 ^ uVar21) - uVar21);
          }
          if ((*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x43) == 0) || (9 < uVar15)) break;
          ovc25_usesEntityCount((byte)uStack_a);
          if (9 < *(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x47)) {
            uVar26 = (undefined2)((ulong)Entities >> 0x10);
            ovc25_usesAlignUp43((byte)uStack_a,5,(((entity_t *)Entities + iVar24)->base).x,
                                ((entity_t *)Entities)[iVar24].base.y,'\x01');
          }
          ovc25_usesAlignUp43((byte)uStack_a,10,
                              *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                              *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b),'\0');
          *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 1;
        }
        if ((*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x49) == -1) ||
           ((*(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x5d) & 1) == 0)) break;
        ovc25_usesEntityCount((byte)uStack_a);
        bVar9 = *(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x49);
        if (0xe < *(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x47)) {
          ovc25_usesAlignUp42((byte)uStack_a,10,
                              *(uint16_t *)((int)*(undefined4 *)((uint)bVar9 << 2) + 0x39),
                              *(uint16_t *)((int)*(undefined4 *)((uint)bVar9 << 2) + 0x3b),
                              *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                              *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b));
          if (*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) != '\x02') {
            ovr_alignUp4(*(int *)((int)*(undefined4 *)((uint)bVar9 << 2) + 0x39));
            uStackY_2a = 0x2379;
            uStackY_2c = 0xc5d4;
            pcVar19 = ovr_stsprintf(acStackY_68,(char *)CONCAT22(0x58c0,unaff_SS));
            ovr_uiNotify(pcVar19);
          }
        }
        ovc25_usesAlignUp43((byte)uStack_a,0xf,
                            *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                            *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b),'\0');
        *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 2;
      }
    } while( true );
  case (byte *)0x4:
    if ((byte)uStack_8 < ListCount) {
      uVar26 = (undefined2)((ulong)GUnits >> 0x10);
      uStack_a = ((unit_t *)GUnits)[*(int *)(((uint)uStack_8 & 0xff) * 2 + -0x6d44)].x;
      uStack_c = ((unit_t *)GUnits)[*(int *)(((uint)uStack_8 & 0xff) * 2 + -0x6d44)].y;
    }
    else {
      uVar5 = *(undefined4 *)((partyIndex & 0xff) << 2);
      uStack_a = *(uint16_t *)((int)uVar5 + 0x39);
      uVar5 = *(undefined4 *)((partyIndex & 0xff) << 2);
      uStack_c = *(uint16_t *)((int)uVar5 + 0x3b);
    }
    uVar5 = *(undefined4 *)((partyIndex & 0xff) << 2);
    uVar26 = (undefined2)((ulong)uVar5 >> 0x10);
    iVar25 = (int)uVar5;
    iVar24 = *(int *)(iVar25 + 0x58);
    if ((iVar24 < 1) && ((iVar24 < 0 || (*(uint *)(iVar25 + 0x56) < 10)))) {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(byte *)uStack_6);
    }
    else {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((byte *)uStack_6);
    }
    uVar5 = *(undefined4 *)((partyIndex & 0xff) << 2);
    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)*(byte *)((int)uVar5 + 0x3e) * 0x95) &
        0x80) == 0) {
      uStack_6 = (byte *)(ulong)(uint3)uStack_6;
    }
    else {
      uStack_6 = (byte *)CONCAT13(3,(uint3)uStack_6);
    }
    uVar5 = *(undefined4 *)((partyIndex & 0xff) << 2);
    if ((*(byte *)((int)uVar5 + 0x5d) & 2) != 0) {
      uStack_6 = (byte *)((ulong)uStack_6 | 0x1000000);
    }
    puVar13 = (undefined4 *)((partyIndex & 0xff) << 2);
    uVar5 = *puVar13;
    if ((*(byte *)((int)uVar5 + 0x5d) & 4) != 0) {
      uStack_6 = (byte *)((ulong)uStack_6 | 0x2000000);
    }
    uVar15 = ovc22_searchCellsAround
                       ((uint *)CONCAT13((char)((uint)&uStack_c >> 8),
                                         CONCAT12((char)&uStack_c,unaff_SS)),
                        (uint *)CONCAT13((char)((uint)puVar13 >> 8),
                                         CONCAT12((byte)partyIndex,unaff_SS)),(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)),
                        (*(uint8_t *)((uint8_t *)&(uStack_6) + 2)),cVar10);
    pbVar14 = (byte *)(uVar15 & 0xff);
    if (pbVar14 != (byte *)0x0) {
      if (pbVar14 != (byte *)((int)(undefined4 *)&_DATA + 1U)) {
        return pbVar14;
      }
      uVar15 = ovc22_usesRandBelow((byte)partyIndex,uStack_a,uStack_c);
      if (uVar15 == 0) {
        uVar5 = *(undefined4 *)((partyIndex & 0xff) << 2);
        uStack_a = *(uint16_t *)((int)uVar5 + 0x39);
        uVar5 = *(undefined4 *)((partyIndex & 0xff) << 2);
        uStack_c = *(uint16_t *)((int)uVar5 + 0x3b);
      }
      else {
        if ((*(uint *)((uint8_t *)&BuildingTypes[uVar15] + 19) & 0x60) == 0) {
          uVar5 = *(undefined4 *)((partyIndex & 0xff) << 2);
          uVar26 = (undefined2)((ulong)uVar5 >> 0x10);
          iVar25 = (int)uVar5;
          iVar24 = *(int *)(iVar25 + 0x58);
          if ((iVar24 < 0) ||
             ((iVar24 == 0 && (*(uint *)(iVar25 + 0x56) < *(uint *)((uint8_t *)&BuildingTypes[uVar15] + 23))))) {
            uVar5 = *(undefined4 *)((partyIndex & 0xff) << 2);
            uVar26 = (undefined2)((ulong)uVar5 >> 0x10);
            iVar24 = (int)uVar5;
            *(undefined2 *)(iVar24 + 0x58) = 0;
            *(undefined2 *)(iVar24 + 0x56) = 0;
          }
          else {
            uVar20 = *(uint *)((uint8_t *)&BuildingTypes[uVar15] + 23);
            uVar5 = *(undefined4 *)((partyIndex & 0xff) << 2);
            uVar26 = (undefined2)((ulong)uVar5 >> 0x10);
            iVar24 = (int)uVar5;
            puVar1 = (uint *)(iVar24 + 0x56);
            uVar18 = *puVar1;
            *puVar1 = *puVar1 - uVar20;
            piVar2 = (int *)(iVar24 + 0x58);
            *piVar2 = *piVar2 - (uint)(uVar18 < uVar20);
          }
        }
        bStack_e = (byte)uVar15;
        ovr_createConstructionRecordFar(bStack_e);
      }
    }
    uVar5 = *(undefined4 *)((partyIndex & 0xff) << 2);
    if (*(char *)((int)uVar5 + 0x3f) == '\0') {
      uVar5 = *(undefined4 *)((partyIndex & 0xff) << 2);
      uVar6 = *(undefined4 *)((partyIndex & 0xff) << 2);
      if (*(uint *)((int)uVar5 + 0x5b) < *(uint *)((int)uVar6 + 0x4d)) {
        pbVar14 = (byte *)ovr_ovc18_textTypeLen((byte)partyIndex);
      }
      else {
        pbVar14 = (byte *)ovr_ovc18_textTypeLen((byte)partyIndex);
      }
    }
    else {
      pbVar14 = (byte *)ovr_ovc18_textTypeLen((byte)partyIndex);
    }
    return pbVar14;
  }
  do {
    if (CONCAT11(uVar32,uVar31) < iVar24) {
      if (uStack_a != -1) {
        if (iVar25 == -1) {
          ovr_attact_usesRandBelow(&Entities[uStack_a].base,(byte)((ulong)Entities >> 0x10));
          ovr_attact_usesEntities(uStack_a);
          uVar26 = (undefined2)((ulong)Entities >> 0x10);
          bVar9 = ((entity_t *)Entities)[uStack_a].base.gindex;
          pbVar14 = (byte *)(uint)*(byte *)((int)(char **)GMenuStrings + (uint)bVar9 * 0x95 + 0x1f);
          if (pbVar14 == (byte *)0x0) {
            alignUp4((((entity_t *)Entities + iVar24)->base).x);
            uVar26 = *(undefined2 *)((int)&worldMenuLabels[1].ofs + 1 + (uint)bVar9 * 0x95);
            pbVar14 = (byte *)ovr_fmVsprintf("Intelligence reports %s unit fleeing from battle. (%d, %d)"
                                             ,(char *)CONCAT13((char)((uint)uVar26 >> 8),
                                                               CONCAT12((char)uVar26,
                                                                        *(undefined2 *)
                                                                         ((int)&worldMenuLabels[0].
                                                                                seg + 1 +
                                                                         (uint)bVar9 * 0x95))));
            ovr_uiNotify((char *)pbVar14);
          }
        }
        else {
          if ((byte *)(uint)Entities[iVar25].base.animFrame <= uStack_8) {
            uStack_8 =(uint16_t) (byte *)(uint)Entities[iVar25].base.animFrame;
          }
          Entities[iVar25].base.animFrame = Entities[iVar25].base.animFrame - (byte)uStack_8;
          ovr_ovc41_compute4(&Entities[iVar25].base,(byte)((ulong)Entities >> 0x10));
          ovr_ovc25_attackingNotice
                    (*(byte *)((int)&((entity_t *)Entities)[iVar25].base.entity + 3));
          pbVar14 = (byte *)(iVar25 * 0x37);
          if (((entity_t *)Entities)[iVar25].base.animFrame != 0x0) {
            ovc24_usesLDIV_at_(iVar25);
            uVar26 = (undefined2)((ulong)Entities >> 0x10);
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
              alignUp4((((entity_t *)Entities + iVar24)->base).x);
              iVar12 = (uint)((entity_t *)Entities)[iVar25].base.gindex * 0x95;
              uVar26 = *(undefined2 *)((int)&worldMenuLabels[1].ofs + 1 + iVar12);
              pcVar19 = ovr_fmVsprintf("Intelligence reports %s unit infected with disease. (%d, %d)"
                                       ,(char *)CONCAT13((char)((uint)uVar26 >> 8),
                                                         CONCAT12((char)uVar26,
                                                                  *(undefined2 *)
                                                                   ((int)&worldMenuLabels[0].seg + 1
                                                                   + iVar12))));
              ovr_uiNotify(pcVar19);
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
                  uVar26 = (undefined2)((ulong)Entities >> 0x10);
                  if (((entity_t *)Entities)[iVar25].base.animFrame != 0x0) {
                    puVar3 = &((entity_t *)Entities)[iVar25].base.animFrame;
                    *puVar3 = *puVar3 + 0xff;
                  }
                }
                alignUp4((((entity_t *)Entities + iVar24)->base).x);
                iVar24 = (uint)((entity_t *)Entities)[iVar25].base.gindex * 0x95;
                uVar26 = *(undefined2 *)((int)&worldMenuLabels[1].ofs + 1 + iVar24);
                pbVar14 = (byte *)ovr_fmVsprintf("Intelligence reports %s unit drained of energy. (%d, %d)"
                                                 ,(char *)CONCAT13((char)((uint)uVar26 >> 8),
                                                                   CONCAT12((char)uVar26,
                                                                            *(undefined2 *)
                                                                             ((int)&worldMenuLabels
                                                                                    [0].seg + 1 +
                                                                             iVar24))));
                ovr_uiNotify((char *)pbVar14);
              }
            }
          }
        }
      }
      return pbVar14;
    }
    pbVar14 = (byte *)Entities[iVar24].base.y;
    if ((pbVar14 != (byte *)CONCAT11(uVar28,uVar27)) ||
       (pbVar14 = (byte *)alignUp4(((Entities + iVar24)->base).x),
       pbVar14 != (byte *)CONCAT11(uVar30,uVar29))) goto L_OVC24_5943_026e_08A7;
    uVar26 = (undefined2)((ulong)Entities >> 0x10);
    peVar22 = (entity_t *)Entities;
    if (*(char *)((int)(char **)GMenuStrings + (uint)peVar22[iVar24].base.gindex * 0x95 + 0x1f) ==
        (char)uStack_10) {
      if (peVar22[iVar24].base.level < bStackY_2d) {
L_OVC24_5943_026e_0772:
        uVar26 = (undefined2)((ulong)Entities >> 0x10);
        bVar9 = ((entity_t *)Entities)[iVar24].base.gindex;
        if ((((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)bVar9 * 0x95) & 0x40) == 0) ||
            (pbVar14 = &stack0xffde + (uStack_10 ^ 1), '\x01' < (char)*pbVar14)) &&
           ((((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar9 * 0x95) & 8) == 0 ||
             (pbVar14 = &stack0xffde + (uStack_10 ^ 1), '\0' < (char)*pbVar14)) &&
            (((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar9 * 0x95) & 0x10) == 0 ||
             (pbVar14 = &stack0xffdc + (uStack_10 ^ 1), -1 < (char)*pbVar14)))))) {
          bStackY_2d = ((entity_t *)Entities)[iVar24].base.level;
          pbVar14 = (byte *)CONCAT11((char)((uint)(iVar24 * 0x37) >> 8),bStackY_2d);
          iVar25 = iVar24;
        }
      }
      else {
        bVar9 = peVar22[iVar24].base.level;
        pbVar14 = (byte *)CONCAT11((char)((uint)(iVar24 * 0x37) >> 8),bVar9);
        if (bVar9 == bStackY_2d) {
          uVar16 = ovr_randBelow(3);
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
        uVar16 = ovr_randBelow(3);
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

undefined1 __cdecl16far ovc23_tickRecordsAt(uint16_t x,int y,char excluded,...)

{
  char *pcVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 uStack_3;
  
  uVar4 = ovr_alignUp4(x);
  uStack_3 = 0;
  for (uVar5 = 0; uVar5 < GRecordCount; uVar5 = uVar5 + 1) {
    if ((((*(int *)(uVar5 * 0x12 + 4) == y) && (*(uint *)(uVar5 * 0x12 + 2) <= uVar4 + 1)) &&
        (uVar4 - 2 <= (*(int *)(uVar5 * 0x12 + 2) + (uint)*(byte *)(uVar5 * 0x12 + 7)) - 1)) &&
       ((bVar2 = *(byte *)(uVar5 * 0x12 + 9), bVar2 != 0xff &&
        (uVar3 = *(undefined4 *)((uint)bVar2 << 2), *(char *)((int)uVar3 + 0x3f) == excluded)))) {
      *(undefined2 *)(uVar5 * 0x12 + 0xf) = GameTick;
      if (*(char *)(uVar5 * 0x12 + 0xb) != '\0') {
        pcVar1 = (char *)(uVar5 * 0x12 + 0xb);
        *pcVar1 = *pcVar1 + -1;
      }
      if (*(char *)(uVar5 * 0x12 + 0xb) == '\0') {
        *(undefined1 *)(uVar5 * 0x12 + 0xe) = 1;
      }
      uStack_3 = 1;
    }
  }
  return uStack_3;
}



/* 55fe:05db */

/* Returns whether the point matches the cell in GfxRndSeed/GfxRndSeed2. */

uint __cdecl16far ovc23_isCursorAt(uint16_t x,int y,...)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = ovr_alignUp4(x);
  uVar2 = ovr_alignUp4(GfxRndSeed);
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
  int iStack_14;
  int iStack_12;
  uint8_t cornerBR;
  uint8_t cornerBL;
  uint8_t cornerTR;
  uint8_t cornerTL;
  int iStack_4;
  
  iVar1 = ovr_constr_usesSmoothPrev(x,-1,(int *)&cornerTL);
  iVar2 = ovr_constr_usesSmoothPrev(x,0,(int *)&cornerBL);
  if (*(byte *)((uint8_t *)&BuildingTypes[bldType] + 13) < 2) {
    iStack_12 = ovr_constr_usesSmoothPrev(x + 1,-1,(int *)&cornerTR);
    iStack_14 = ovr_constr_usesSmoothPrev(x + 1,0,(int *)&cornerBR);
  }
  else if (*(byte *)((uint8_t *)&BuildingTypes[bldType] + 13) < 3) {
    iStack_12 = ovr_constr_usesSmoothPrev(x + 2,-1,(int *)&cornerTR);
    iStack_14 = ovr_constr_usesSmoothPrev(x + 2,0,(int *)&cornerBR);
  }
  else {
    iStack_12 = ovr_constr_usesSmoothPrev(x + 4,-1,(int *)&cornerTR);
    iStack_14 = ovr_constr_usesSmoothPrev(x + 4,0,(int *)&cornerBR);
  }
  uVar3 = (uint)cornerShadeBias[0];
  iStack_4 = iVar2 + iVar1 + iStack_12 + iStack_14 >> 2;
  if ((int)(iVar1 - uVar3) < (int)(iStack_12 - uVar3)) {
    iVar2 = iVar1 - uVar3;
  }
  else {
    iVar2 = iStack_12 - uVar3;
  }
  if (iStack_4 < iVar2) {
    if ((int)(iVar1 - uVar3) < (int)(iStack_12 - uVar3)) {
      iStack_4 = iVar1 - uVar3;
    }
    else {
      iStack_4 = iStack_12 - uVar3;
    }
  }
  return iStack_4;
}



/* 55fe:0768 */

/* [R6] touches cornerBR, cornerBL */

int __cdecl16far ovc23_usesCornerBR2(int x,int step)

{
  int iVar1;
  int iVar2;
  int iStack_12;
  uint8_t cornerBR;
  uint8_t cornerBL;
  uint8_t cornerTR;
  uint8_t cornerTL;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  if (step == 4) {
    iVar1 = ovr_constr_usesSmoothPrev(x + 1,-1,(int *)&cornerTL);
    iStack_4 = ovr_constr_usesSmoothPrev(x + 1,0,(int *)&cornerBL);
    iStack_6 = ovr_constr_usesSmoothPrev(x + 2,-1,(int *)&cornerTR);
    iStack_8 = ovr_constr_usesSmoothPrev(x + 2,0,(int *)&cornerBR);
  }
  else {
    iVar1 = ovr_constr_usesSmoothPrev(x,-1,(int *)&cornerTL);
    iStack_4 = ovr_constr_usesSmoothPrev(x,0,(int *)&cornerBL);
    iStack_6 = ovr_constr_usesSmoothPrev(x + step,-1,(int *)&cornerTR);
    iStack_8 = ovr_constr_usesSmoothPrev(x + step,0,(int *)&cornerBR);
  }
  iStack_12 = iStack_4 + iVar1 + iStack_6 + iStack_8 >> 2;
  iVar2 = iStack_6;
  if (iVar1 < iStack_6) {
    iVar2 = iVar1;
  }
  if ((iStack_12 < iVar2) && (iStack_12 = iStack_6, iVar1 < iStack_6)) {
    iStack_12 = iVar1;
  }
  return iStack_12;
}



/* 55fe:0863 */

/* [R2] string "build\\thfres01.lbm" */

void __cdecl16far ovc23_textBuildThfres01Lbm(far_t dst,...)

{
  uint16_t play_id;
  bool bVar1;
  byte bVar2;
  undefined1 extraout_AH;
  int iVar4;
  uint16_t unaff_SI;
  undefined2 unaff_DI;
  uint16_t uVar5;
  int iVar3;
  
  bVar1 = false;
  GAnimPlaying = 0;
  uVar5 = rowMapSquareFirst[0];
  while( true ) {
    if (rowMapSquareEnd[0] <= uVar5) break;
    play_id = *(uint16_t *)(&mapSquareColumn[uVar5]);
    if ((-3 < (int)play_id) && ((int)play_id < 2)) {
      bVar2 = ovr_constr_setHighlightAtOffset(play_id,0);
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
          iVar4 = ovc23_usesCornerBR2(play_id,(uint)*(byte *)(iVar3 * 0x12 + 7));
          ovc23_usesBlitGfxRect2
                    ((uint)bandOrigin[0] - iVar4,iVar3,dst.ofs,(brect_t *)CONCAT22(unaff_DI,dst.seg)
                     ,unaff_SI);
          bVar1 = true;
        }
        else if (play_id == 0xfffe) {
          iVar4 = ovc23_usesCornerBR2(-2,(uint)*(byte *)(iRam0002d2d7 * 0x12 + 7));
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
    ovr_constr_usesScreenOriginY(dst.ofs,dst.seg);
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

uint * __cdecl16far ovc23_usesAlignUp43(int16_t x,uint16_t unitIndex,byte dir,...)

{
  uint8_t *puVar1;
  int *piVar2;
  uint *puVar3;
  byte *pbVar4;
  byte bVar5;
  short sVar6;
  undefined4 uVar7;
  far_t pctOut;
  far_t remainderOut;
  far_t partOut;
  bool bVar8;
  bool bVar9;
  byte bVar10;
  char cVar11;
  char *pcVar12;
  byte *pbVar13;
  undefined1 uVar16;
  uint16_t uVar14;
  uint *msg;
  uint uVar15;
  int in_CX;
  undefined2 uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  entity_t *peVar22;
  entity_t *peVar23;
  unit_t *puVar24;
  undefined2 unaff_BP;
  uint uVar25;
  undefined2 unaff_SI;
  uint uVar26;
  char *unaff_DI;
  undefined2 uVar27;
  undefined2 uVar28;
  uint16_t unaff_SS;
  bool bVar29;
  uint uStackY_2e;
  int iStackY_2c;
  int iStackY_2a;
  byte bStackY_20;
  byte bStackY_1f;
  undefined2 uStackY_1e;
  undefined2 uStackY_1c;
  far_t table;
  undefined1 uVar30;
  undefined1 in_stack_0000ffea;
  uint *entityIndex;
  undefined1 in_stack_0000ffeb;
  uint uVar31;
  byte *pbVar32;
  uint16_t uVar33;
  uint16_t uVar34;
  uint16_t uVar35;
  undefined2 *puVar36;
  undefined1 uVar37;
  undefined1 uVar38;
  char *fmt;
  long a;
  undefined2 in_stack_0000fffc;
  long b;
  
  b = CONCAT22(unaff_BP,in_stack_0000fffc);
  fmt = (char *)CONCAT22(unaff_SI,unaff_DI);
  uVar17 = 0x2410;
  iVar18 = x + *(char *)(dir + 0x885);
  uVar15 = ovr_attact_usesGUnits(iVar18);
  uVar26 = CONCAT11(in_stack_0000ffeb,in_stack_0000ffea);
  if ((uVar15 & 0xff) == 0) {
    return (uint *)((int)(undefined4 *)&_DATA + 1);
  }
  uVar15 = (uint)dir;
  if (3 < uVar15) {
    return (uint *)0x0;
  }
  puVar24 = (unit_t *)(uVar15 * 2);
  switch(uVar15) {
  case 0:
    return (uint *)unitIndex;
  case 1:
    while( true ) {
      if (((&puVar24->flags)[uVar15] & 3) == 0) {
        uVar17 = (undefined2)((ulong)GUnits >> 0x10);
        bVar10 = ((unit_t *)GUnits)[unitIndex].unitType;
        if ((bVar10 == 0xff) ||
           (uVar7 = *(undefined4 *)((uint)bVar10 << 2), *(char *)((int)uVar7 + 0x3f) == '\0')) {
          pcVar12 = (char *)0x24d;
        }
        else {
          pcVar12 = (char *)0x246dc;
        }
        fmt = (char *)CONCAT22((int)((ulong)fmt >> 0x10),pcVar12);
        if (((unit_t *)GUnits)[unitIndex].level != 0) {
          uVar34 = ovr_randBelow((uint16_t)pcVar12);
          uVar17 = (undefined2)((ulong)GUnits >> 0x10);
          puVar24 = (unit_t *)GUnits;
          if ((int)(uVar34 & 0xff) <
              (int)(100 - (uint)*(byte *)((uint)(puVar24 + unitIndex)->bldType * 0x27 + 0x130))) {
            bStackY_20 = (puVar24 + unitIndex)->bldType;
            puVar24[unitIndex].level = puVar24[unitIndex].level - 1;
            puVar24 = (unit_t *)GUnits;
            uVar17 = (undefined2)((ulong)GUnits >> 0x10);
            if (((*(uint *)((uint)bStackY_20 * 0x27 + 0x121) & 4) == 0) &&
               ((puVar24[unitIndex].level == 0 ||
                ((*(uint *)((uint)bStackY_20 * 0x27 + 0x121) & 0x200) != 0)))) {
              ovc22_usesGUnits(unitIndex,
                               (uint8_t *)
                               CONCAT13((char)(unitIndex * 9 >> 8),
                                        CONCAT12(puVar24[unitIndex].unitType,unaff_SS)));
            }
            else if (((((bld_inst_t *)BldInstances + bStackY_20)->ofs != 0 ||
                       *(int *)((int)&BldInstances[0].seg + (uint)bStackY_20 * 0xc) != 0) ||
                     (*(char *)((uint)bStackY_20 * 0x27 + 0x11e) == '\x10')) &&
                    (uVar17 = ovc22_usesGOngoingBattle2
                                        (*(byte *)&puVar24[unitIndex].x,
                                         *(byte *)&puVar24[unitIndex].y), (char)uVar17 != '\0')) {
              uStackY_1c = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1c) + 1)),1);
            }
          }
        }
      }
      unitIndex = unitIndex + 1;
      if (GUnitCount <= unitIndex) break;
      uVar15 = unitIndex * 9;
      uVar17 = (undefined2)((ulong)GUnits >> 0x10);
      puVar24 = (unit_t *)GUnits;
    }
    GGameState = 0x43;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (uVar26 = 0; (int)uVar26 < (int)(uint)GLeaderCount; uVar26 = uVar26 + 1) {
      if (*(char *)((int)*(undefined4 *)(uVar26 << 2) + 0x3d) != '\0') {
        *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0xa2) = 0;
        cVar11 = *(char *)((int)*(undefined4 *)(uVar26 << 2) + 0x3f);
        if ((cVar11 == '\0') &&
           (*(uint *)((int)*(undefined4 *)(uVar26 << 2) + 0x4f) <
            *(uint *)((int)*(undefined4 *)(uVar26 << 2) + 0x4d) >> 1)) {
          bVar8 = true;
        }
        else {
          bVar8 = false;
        }
        uVar15 = *(uint *)((int)*(undefined4 *)(uVar26 << 2) + 0x54);
        uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
        iVar18 = (int)*(undefined4 *)(uVar26 << 2);
        iVar18 = *(int *)(iVar18 + 0x58) + ((int)uVar15 >> 0xf) +
                 (uint)CARRY2(*(uint *)(iVar18 + 0x56),uVar15);
        if ((iVar18 < 1) && (iVar18 < 0)) {
          for (uVar15 = 0xf8; uVar15 < GUnitCount; uVar15 = uVar15 + 1) {
            uVar17 = (undefined2)((ulong)GUnits >> 0x10);
            puVar24 = (unit_t *)GUnits;
            bStackY_20 = (puVar24 + uVar15)->bldType;
            if ((puVar24[uVar15].unitType == uVar26) &&
               (*(int *)((uint)bStackY_20 * 0x27 + 0x123) < 0)) {
              uVar25 = *(uint *)((uint)bStackY_20 * 0x27 + 0x123);
              uVar28 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uVar26 << 2);
              iVar18 = *(int *)(iVar18 + 0x58) + ((int)uVar25 >> 0xf) +
                       (uint)CARRY2(*(uint *)(iVar18 + 0x56),uVar25);
              if ((iVar18 < 1) && (iVar18 < 0)) {
                if ((cVar11 == '\0') && (puVar24[uVar15].level != 0)) {
                  uVar34 = ovr_randBelow(100);
                  uVar17 = (undefined2)((ulong)GUnits >> 0x10);
                  puVar24 = (unit_t *)GUnits;
                  if (*(byte *)((uint)(puVar24 + uVar15)->bldType * 0x27 + 0x130) <= (byte)uVar34) {
                    if (puVar24[uVar15].level != 0) {
                      puVar24[uVar15].level = puVar24[uVar15].level - 1;
                    }
                    puVar24 = (unit_t *)GUnits;
                    uVar17 = (undefined2)((ulong)GUnits >> 0x10);
                    if (((*(uint *)((uint)bStackY_20 * 0x27 + 0x121) & 4) == 0) &&
                       ((iVar18 = 0, puVar24[uVar15].level == 0 ||
                        (iVar18 = (uint)bStackY_20 * 0x27, (*(uint *)(iVar18 + 0x121) & 0x200) != 0)
                        ))) {
                      ovc22_usesGUnits(uVar15,(uint8_t *)
                                              CONCAT13((char)((uint)iVar18 >> 8),
                                                       CONCAT12((char)uVar26,unaff_SS)));
                    }
                    else if (((((bld_inst_t *)BldInstances + bStackY_20)->ofs != 0 ||
                               *(int *)((int)&BldInstances[0].seg + (uint)bStackY_20 * 0xc) != 0) ||
                             (*(char *)((uint)bStackY_20 * 0x27 + 0x11e) == '\x10')) &&
                            (uVar17 = ovc22_usesGOngoingBattle2
                                                (*(byte *)&puVar24[uVar15].x,
                                                 *(byte *)&puVar24[uVar15].y), (char)uVar17 != '\0')
                            ) {
                      uStackY_1c = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1c) + 1)),1);
                    }
                  }
                }
              }
              else {
                uVar31 = *(uint *)((uint)bStackY_20 * 0x27 + 0x123);
                uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
                iVar18 = (int)*(undefined4 *)(uVar26 << 2);
                puVar3 = (uint *)(iVar18 + 0x56);
                uVar25 = *puVar3;
                *puVar3 = *puVar3 + uVar31;
                piVar2 = (int *)(iVar18 + 0x58);
                *piVar2 = *piVar2 + ((int)uVar31 >> 0xf) + (uint)CARRY2(uVar25,uVar31);
              }
            }
          }
          uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
          iVar18 = (int)*(undefined4 *)(uVar26 << 2);
          *(undefined2 *)(iVar18 + 0x58) = 0;
          *(undefined2 *)(iVar18 + 0x56) = 0;
        }
        else {
          if ((cVar11 == '\0') && (0 < *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x54))) {
            uVar15 = *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x54) / 10;
          }
          else {
            uVar15 = 0;
          }
          bVar29 = CARRY2(GPopulationLo,uVar15);
          GPopulationLo = GPopulationLo + uVar15;
          GPopulationHi = GPopulationHi + ((int)uVar15 >> 0xf) + (uint)bVar29;
          uVar15 = *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x54) - uVar15;
          uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
          iVar18 = (int)*(undefined4 *)(uVar26 << 2);
          puVar3 = (uint *)(iVar18 + 0x56);
          uVar25 = *puVar3;
          *puVar3 = *puVar3 + uVar15;
          piVar2 = (int *)(iVar18 + 0x58);
          *piVar2 = *piVar2 + ((int)uVar15 >> 0xf) + (uint)CARRY2(uVar25,uVar15);
        }
        if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uVar26 << 2) + 0x3e) * 0x95) & 0x100) ==
            0) {
          if (*(uint *)((int)*(undefined4 *)(uVar26 << 2) + 0x4f) <
              *(uint *)((int)*(undefined4 *)(uVar26 << 2) + 0x4d)) {
            uVar15 = *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x4d) -
                     *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x4f);
            uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
            iVar21 = (int)*(undefined4 *)(uVar26 << 2);
            iVar18 = *(int *)(iVar21 + 0x62);
            if ((-1 < iVar18) && ((0 < iVar18 || (*(int *)(iVar21 + 0x60) != 0)))) {
              uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uVar26 << 2);
              uVar25 = *(uint *)(iVar18 + 0x62);
              if ((0x7fff < uVar25) ||
                 ((uVar31 = uVar15, (int)uVar25 < 1 && (*(uint *)(iVar18 + 0x60) <= uVar15)))) {
                uVar31 = *(uint *)((int)*(undefined4 *)(uVar26 << 2) + 0x60);
              }
              uVar15 = uVar15 - uVar31;
              uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uVar26 << 2);
              puVar3 = (uint *)(iVar18 + 0x60);
              uVar25 = *puVar3;
              *puVar3 = *puVar3 - uVar31;
              piVar2 = (int *)(iVar18 + 0x62);
              *piVar2 = *piVar2 - (uint)(uVar25 < uVar31);
            }
            if (uVar15 == 0) {
              uVar15 = 0;
            }
            else {
              uVar30 = (undefined1)uVar15;
              uVar16 = (undefined1)(uVar15 >> 8);
              if (*(uint *)((int)*(undefined4 *)(uVar26 << 2) + 0xa0) < uVar15) {
                uVar17 = *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0xa0);
                uVar30 = (undefined1)uVar17;
                uVar16 = (undefined1)((uint)uVar17 >> 8);
              }
              uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uVar26 << 2);
              uVar25 = *(uint *)(iVar18 + 0x58);
              if (((int)uVar25 < 1) &&
                 ((0x7fff < uVar25 || (*(uint *)(iVar18 + 0x56) < CONCAT11(uVar16,uVar30))))) {
                uVar17 = *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0x56);
                uVar30 = (undefined1)uVar17;
                uVar16 = (undefined1)((uint)uVar17 >> 8);
              }
              uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uVar26 << 2);
              puVar3 = (uint *)(iVar18 + 0x56);
              uVar25 = *puVar3;
              *puVar3 = *puVar3 - CONCAT11(uVar16,uVar30);
              piVar2 = (int *)(iVar18 + 0x58);
              *piVar2 = *piVar2 - (uint)(uVar25 < CONCAT11(uVar16,uVar30));
              uVar15 = uVar15 - CONCAT11(uVar16,uVar30);
              *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0xa2) = CONCAT11(uVar16,uVar30);
            }
            if (cVar11 == '\0') {
              for (iVar18 = 0; (uVar15 != 0 && (iVar18 < (int)(uint)GLeaderCount));
                  iVar18 = iVar18 + 1) {
                if ((*(char *)((int)*(undefined4 *)(iVar18 << 2) + 0x3d) != '\0') &&
                   ((*(char *)((int)*(undefined4 *)(iVar18 << 2) + 0x3f) == '\0' &&
                    (uVar17 = (undefined2)((ulong)*(undefined4 *)(iVar18 << 2) >> 0x10),
                    iVar21 = (int)*(undefined4 *)(iVar18 << 2),
                    *(int *)(iVar21 + 0x60) != 0 || *(int *)(iVar21 + 0x62) != 0)))) {
                  uVar17 = (undefined2)((ulong)*(undefined4 *)(iVar18 << 2) >> 0x10);
                  iVar21 = (int)*(undefined4 *)(iVar18 << 2);
                  uVar25 = *(uint *)(iVar21 + 0x62);
                  if ((0x7fff < uVar25) ||
                     ((uVar31 = uVar15, (int)uVar25 < 1 && (*(uint *)(iVar21 + 0x60) <= uVar15)))) {
                    uVar31 = *(uint *)((int)*(undefined4 *)(iVar18 << 2) + 0x60);
                  }
                  uVar15 = uVar15 - uVar31;
                  uVar17 = (undefined2)((ulong)*(undefined4 *)(iVar18 << 2) >> 0x10);
                  iVar21 = (int)*(undefined4 *)(iVar18 << 2);
                  puVar3 = (uint *)(iVar21 + 0x60);
                  uVar25 = *puVar3;
                  *puVar3 = *puVar3 - uVar31;
                  piVar2 = (int *)(iVar21 + 0x62);
                  *piVar2 = *piVar2 - (uint)(uVar25 < uVar31);
                }
              }
            }
            uVar25 = 0;
            while ((uVar25 < EntityCount && (uVar15 != 0))) {
              uVar17 = (undefined2)((ulong)Entities >> 0x10);
              peVar22 = (entity_t *)Entities;
              if (((*(char *)((int)&peVar22[uVar25].base.entity + 1) == '\0') &&
                  (*(byte *)((int)&peVar22[uVar25].base.entity + 3) == uVar26)) &&
                 ((bVar8 || (1 < peVar22[uVar25].base.animFrame)))) {
                if (peVar22[uVar25].base.animFrame != 0x0) {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  puVar1 = &((entity_t *)Entities)[uVar25].base.animFrame;
                  *puVar1 = *puVar1 + 0xff;
                  if (((entity_t *)Entities)[uVar25].base.animFrame == 0x0) {
                    uStackY_1e = CONCAT11(1,(byte)uStackY_1e);
                  }
                }
                uVar15 = uVar15 - 1;
              }
              uVar25 = uVar25 + 1;
            }
          }
          else {
            uVar25 = *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x4f) -
                     *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x4d);
            uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
            iVar18 = (int)*(undefined4 *)(uVar26 << 2);
            puVar3 = (uint *)(iVar18 + 0x60);
            uVar15 = *puVar3;
            *puVar3 = *puVar3 + uVar25;
            piVar2 = (int *)(iVar18 + 0x62);
            *piVar2 = *piVar2 + (uint)CARRY2(uVar15,uVar25);
          }
        }
        uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
        iVar19 = (int)*(undefined4 *)(uVar26 << 2);
        iVar18 = *(int *)(iVar19 + 0x62);
        uVar28 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
        iVar20 = (int)*(undefined4 *)(uVar26 << 2);
        iVar21 = *(int *)(iVar20 + 0x80);
        if ((iVar21 <= iVar18) &&
           ((iVar21 < iVar18 || (*(uint *)(iVar20 + 0x7e) < *(uint *)(iVar19 + 0x60))))) {
          uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
          iVar18 = (int)*(undefined4 *)(uVar26 << 2);
          uVar15 = *(uint *)(iVar18 + 0x60);
          uVar28 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
          iVar21 = (int)*(undefined4 *)(uVar26 << 2);
          puVar3 = (uint *)(iVar21 + 0x7e);
          uVar25 = (uint)(uVar15 < *puVar3);
          uVar31 = *(int *)(iVar18 + 0x62) - *(int *)(iVar21 + 0x80);
          if (((int)(uVar31 - uVar25) < 0) ||
             ((uVar31 == uVar25 &&
              (uVar15 - *puVar3 <= *(uint *)((int)*(undefined4 *)(uVar26 << 2) + 0xa0))))) {
            uVar15 = *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x60) -
                     *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x7e);
          }
          else {
            uVar15 = *(uint *)((int)*(undefined4 *)(uVar26 << 2) + 0xa0);
          }
          *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0xa2) = -uVar15;
          uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
          iVar18 = (int)*(undefined4 *)(uVar26 << 2);
          puVar3 = (uint *)(iVar18 + 0x56);
          uVar25 = *puVar3;
          *puVar3 = *puVar3 + uVar15;
          piVar2 = (int *)(iVar18 + 0x58);
          *piVar2 = *piVar2 + (uint)CARRY2(uVar25,uVar15);
          uVar28 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
          iVar18 = (int)*(undefined4 *)(uVar26 << 2);
          uVar17 = *(undefined2 *)(iVar18 + 0x7e);
          uVar27 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
          iVar21 = (int)*(undefined4 *)(uVar26 << 2);
          *(undefined2 *)(iVar21 + 0x62) = *(undefined2 *)(iVar18 + 0x80);
          *(undefined2 *)(iVar21 + 0x60) = uVar17;
        }
        if ((*(uint *)((int)*(undefined4 *)(uVar26 << 2) + 0x5b) <
             *(uint *)((int)*(undefined4 *)(uVar26 << 2) + 0x4d)) &&
           ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uVar26 << 2) + 0x3e) * 0x95) & 0x80) == 0
           )) {
          iVar18 = *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x4d) -
                   *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x5b);
          uVar15 = 0;
          while ((uVar15 < EntityCount && (iVar18 != 0))) {
            uVar17 = (undefined2)((ulong)Entities >> 0x10);
            peVar22 = (entity_t *)Entities;
            if ((*(byte *)((int)&peVar22[uVar15].base.entity + 3) == uVar26) &&
               ((((*(char *)((int)&peVar22[uVar15].base.entity + 1) == '\0' &&
                  (peVar22[uVar15].base.destX == 0)) && (peVar22[uVar15].base.destY == 0)) &&
                (3 < peVar22[uVar15].base.animFrame)))) {
              if (DebugVerbose != false) {
                printf("kill 2 \r");
              }
              puVar1 = &((entity_t *)Entities)[uVar15].base.animFrame;
              *puVar1 = *puVar1 + 0xff;
              iVar18 = iVar18 + -1;
            }
            uVar15 = uVar15 + 1;
          }
        }
        ovr_ovc25_tickCountdown(uVar26);
        _fmemset((void *)(ulong)*(uint *)(uVar26 * 4 + 2),6,(uint16_t)(char *)fmt);
        _fmemset((void *)(ulong)*(uint *)(uVar26 * 4 + 2),6,(uint16_t)(char *)fmt);
        uVar34 = ovr_randBelow(100);
        if ((byte)uVar34 < *(byte *)((int)*(undefined4 *)(uVar26 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0x6c) =
               *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 100);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0x6a) =
               *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 100);
        }
        uVar34 = ovr_randBelow(100);
        if ((byte)uVar34 < *(byte *)((int)*(undefined4 *)(uVar26 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0x6e) =
               *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0x66);
        }
        else {
          piVar2 = (int *)((int)*(undefined4 *)(uVar26 << 2) + 0x6c);
          *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x66);
        }
        piVar2 = (int *)((int)*(undefined4 *)(uVar26 << 2) + 0x6e);
        *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x68);
        uVar34 = ovr_randBelow(100);
        if ((byte)uVar34 < *(byte *)((int)*(undefined4 *)(uVar26 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0x78) =
               *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0x70);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0x76) =
               *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0x70);
        }
        uVar34 = ovr_randBelow(100);
        if ((byte)uVar34 < *(byte *)((int)*(undefined4 *)(uVar26 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0x7a) =
               *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0x72);
        }
        else {
          piVar2 = (int *)((int)*(undefined4 *)(uVar26 << 2) + 0x78);
          *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x72);
        }
        uVar34 = ovr_randBelow(100);
        if ((byte)uVar34 < *(byte *)((int)*(undefined4 *)(uVar26 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0x7c) =
               *(undefined2 *)((int)*(undefined4 *)(uVar26 << 2) + 0x74);
        }
        else {
          piVar2 = (int *)((int)*(undefined4 *)(uVar26 << 2) + 0x7a);
          *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x74);
        }
        *(undefined1 *)((int)*(undefined4 *)(uVar26 << 2) + 0xa7) =
             *(undefined1 *)((int)*(undefined4 *)(uVar26 << 2) + 0xa6);
        if (*(char *)((int)*(undefined4 *)(uVar26 << 2) + 0x3f) != '\0') {
          uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
          iVar21 = (int)*(undefined4 *)(uVar26 << 2);
          iVar18 = *(int *)(iVar21 + 0x58);
          if ((iVar18 < 1) && ((iVar18 != 0 || (*(int *)(iVar21 + 0x56) == 0)))) {
            uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
            iVar18 = (int)*(undefined4 *)(uVar26 << 2);
            *(undefined2 *)(iVar18 + 0x58) = 0;
            *(undefined2 *)(iVar18 + 0x56) = 0x32;
          }
        }
        if (*(char *)((int)*(undefined4 *)(uVar26 << 2) + 0xaa) != '\0') {
          uVar15 = (uint)*(byte *)((int)*(undefined4 *)(uVar26 << 2) + 0xaa);
          b = CONCAT22((int)((ulong)b >> 0x10),uVar15);
          for (uVar25 = 0; (int)uVar25 < (int)(uint)GLeaderCount; uVar25 = uVar25 + 1) {
            uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
            iVar19 = (int)*(undefined4 *)(uVar26 << 2);
            iVar18 = *(int *)(iVar19 + 0x58);
            uVar28 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
            iVar20 = (int)*(undefined4 *)(uVar26 << 2);
            iVar21 = *(int *)(iVar20 + 0x8c);
            if ((iVar21 <= iVar18) &&
               ((iVar18 != iVar21 || (*(uint *)(iVar20 + 0x8a) <= *(uint *)(iVar19 + 0x56)))))
            break;
            if ((*(char *)((int)*(undefined4 *)(uVar25 << 2) + 0x3d) != '\0') &&
               (((0 < *(int *)((int)*(undefined4 *)(uVar25 << 2) + 0x54) &&
                 (*(char *)((int)*(undefined4 *)(uVar25 << 2) + 0x3f) == '\0')) &&
                (uVar25 != uVar26)))) {
              uStackY_2e = (uint)(((long)*(int *)((int)*(undefined4 *)(uVar25 << 2) + 0x54) *
                                   (long)(int)uVar15 & 0xffffU) / 100);
              iStackY_2c = 0;
              uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uVar26 << 2);
              uVar31 = *(uint *)(iVar18 + 0x8a);
              uVar28 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
              iVar21 = (int)*(undefined4 *)(uVar26 << 2);
              puVar3 = (uint *)(iVar21 + 0x56);
              iVar18 = (*(int *)(iVar18 + 0x8c) - *(int *)(iVar21 + 0x58)) -
                       (uint)(uVar31 < *puVar3);
              if ((iVar18 < 1) && ((iVar18 < 0 || (uVar31 - *puVar3 < uStackY_2e)))) {
                uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
                iVar18 = (int)*(undefined4 *)(uVar26 << 2);
                uVar31 = *(uint *)(iVar18 + 0x8a);
                uVar28 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
                iVar21 = (int)*(undefined4 *)(uVar26 << 2);
                puVar3 = (uint *)(iVar21 + 0x56);
                uStackY_2e = uVar31 - *puVar3;
                iStackY_2c = (*(int *)(iVar18 + 0x8c) - *(int *)(iVar21 + 0x58)) -
                             (uint)(uVar31 < *puVar3);
              }
              uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar25 << 2) >> 0x10);
              iVar21 = (int)*(undefined4 *)(uVar25 << 2);
              iVar18 = *(int *)(iVar21 + 0x58);
              if ((iVar18 <= iStackY_2c) &&
                 ((iVar18 < iStackY_2c || (*(uint *)(iVar21 + 0x56) < uStackY_2e)))) {
                uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar25 << 2) >> 0x10);
                iVar18 = (int)*(undefined4 *)(uVar25 << 2);
                iStackY_2c = *(int *)(iVar18 + 0x58);
                uStackY_2e = *(uint *)(iVar18 + 0x56);
              }
              uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uVar26 << 2);
              puVar3 = (uint *)(iVar18 + 0x56);
              uVar31 = *puVar3;
              *puVar3 = *puVar3 + uStackY_2e;
              piVar2 = (int *)(iVar18 + 0x58);
              *piVar2 = *piVar2 + iStackY_2c + (uint)CARRY2(uVar31,uStackY_2e);
              uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar25 << 2) >> 0x10);
              iVar18 = (int)*(undefined4 *)(uVar25 << 2);
              puVar3 = (uint *)(iVar18 + 0x56);
              uVar31 = *puVar3;
              *puVar3 = *puVar3 - uStackY_2e;
              piVar2 = (int *)(iVar18 + 0x58);
              *piVar2 = (*piVar2 - iStackY_2c) - (uint)(uVar31 < uStackY_2e);
            }
          }
        }
        iVar18 = *(int *)((int)*(undefined4 *)(uVar26 << 2) + 0x58);
        if ((iVar18 < 1) && (iVar18 < 0)) {
          uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
          iVar18 = (int)*(undefined4 *)(uVar26 << 2);
          *(undefined2 *)(iVar18 + 0x58) = 0;
          *(undefined2 *)(iVar18 + 0x56) = 0;
        }
        uVar17 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
        iVar19 = (int)*(undefined4 *)(uVar26 << 2);
        iVar18 = *(int *)(iVar19 + 0x58);
        uVar28 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
        iVar20 = (int)*(undefined4 *)(uVar26 << 2);
        iVar21 = *(int *)(iVar20 + 0x8c);
        if ((iVar21 <= iVar18) &&
           ((iVar21 < iVar18 || (*(uint *)(iVar20 + 0x8a) < *(uint *)(iVar19 + 0x56))))) {
          uVar28 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
          iVar18 = (int)*(undefined4 *)(uVar26 << 2);
          uVar17 = *(undefined2 *)(iVar18 + 0x8a);
          uVar27 = (undefined2)((ulong)*(undefined4 *)(uVar26 << 2) >> 0x10);
          iVar21 = (int)*(undefined4 *)(uVar26 << 2);
          *(undefined2 *)(iVar21 + 0x58) = *(undefined2 *)(iVar18 + 0x8c);
          *(undefined2 *)(iVar21 + 0x56) = uVar17;
        }
      }
    }
    GGameState = 0x40;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (uVar26 = 0xf8; uVar26 < GUnitCount; uVar26 = uVar26 + 1) {
      uVar17 = (undefined2)((ulong)GUnits >> 0x10);
      puVar24 = (unit_t *)GUnits;
      if ((*(uint *)((uint)(puVar24 + uVar26)->bldType * 0x27 + 0x121) & 0x40) != 0) {
        if (puVar24[uVar26].timer != 0) {
          puVar24[uVar26].timer = puVar24[uVar26].timer - 1;
        }
        uVar17 = (undefined2)((ulong)GUnits >> 0x10);
        if (((unit_t *)GUnits)[uVar26].timer == 0) {
          uVar7 = *(undefined4 *)((uint)((unit_t *)GUnits)[uVar26].unitType << 2);
          if (*(char *)((int)uVar7 + 0x3f) == '\0') {
            ovr_play_sfx(81);
            uVar17 = (undefined2)((ulong)GUnits >> 0x10);
            sVar6 = ((unit_t *)GUnits)[uVar26].y;
            uVar30 = (undefined1)sVar6;
            uVar16 = (undefined1)((uint)sVar6 >> 8);
            uVar15 = ovr_alignUp4(((unit_t *)GUnits)[uVar26].x);
            pcVar12 = ovr_fmVsprintf("Mine exhausted at (%d, %d).",
                                     (char *)CONCAT13(uVar16,CONCAT12(uVar30,uVar15)));
            ovr_say(pcVar12);
            ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
          }
          ovc22_usesGUnits(uVar26,(uint8_t *)
                                  CONCAT13((char)(uVar26 * 9 >> 8),
                                           CONCAT12(((unit_t *)GUnits)[uVar26].unitType,unaff_SS)));
        }
      }
    }
    GGameState = 0x42;
    if (DebugVerbose == false) goto L_upd_units_5087_1d7d_323A;
    break;
  case 2:
    if (in_CX != 1 && uVar15 != 0) goto code_r0x00053afb;
    break;
  case 3:
    puVar3 = (uint *)(&puVar24->bldType + unitIndex);
    *puVar3 = *puVar3 >> 7 | *puVar3 << 9;
    *(uint *)(&puVar24->timer +
             (int)((char *)0x7f01 + x)) =
         *(uint *)(&puVar24->timer +
                  (int)((char *)0x7f01 + x)
                  ) | (uint)&stack0xfff8;
    *(uint *)(&puVar24[1].bldType + x) = *(uint *)(&puVar24[1].bldType + x) | (uint)&stack0xfffe;
    AgntAnms[0x7d].x = AgntAnms[0x7d].x | (uint)&stack0xfff8;
    *(uint *)unitIndex = *(uint *)unitIndex | uVar15;
    (&stack0x8d06)[unitIndex] = (&stack0x8d06)[unitIndex];
    *(byte *)(x + 8) = *(byte *)(x + 8) | (byte)((uint)iVar18 >> 8);
    (&stack0xfffe)[x] = (&stack0xfffe)[x] | (byte)((uint)&puVar24->level >> 8);
    pbVar4 = &puVar24->level + unitIndex;
    *pbVar4 = *pbVar4 | (byte)in_CX | (byte)x;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  printf(fmt);
L_upd_units_5087_1d7d_323A:
  ovr_driver_clearMapFlagsRect((uint32_t)GMapFlags,0,0,0x93);
  uVar15 = 0;
  while (uVar15 < SquareRecCount) {
    uVar17 = (undefined2)((ulong)GMapFlags >> 0x10);
    puVar24 = (unit_t *)(*(short (*) [60] [148])GMapFlags + *(int *)((uint8_t *)&SquareRecs[uVar15] + 2));
    uVar26 = uVar15;
code_r0x00053afb:
    *(uint *)(&puVar24->bldType + *(int *)(uVar15 * 0x13) * 2) =
         *(uint *)(&puVar24->bldType + *(int *)(uVar15 * 0x13) * 2) | 8;
    uVar15 = uVar26 + 1;
  }
  if (EntityCount <= EntityScanPos) {
    EntityScanPos = 0;
    for (iVar18 = 0; iVar18 < (int)(uint)GLeaderCount; iVar18 = iVar18 + 1) {
      if (*(char *)((int)*(undefined4 *)(iVar18 << 2) + 0x3d) != '\0') {
        iVar21 = ((int *)(iVar18 * 4))[1];
        uVar30 = 0x95;
        uVar16 = 0x3b;
        memcpy((char *)CONCAT22(((int *)(iVar18 * 4))[1],(char *)(*(int *)(iVar18 * 4) + 0x8e)),
               (char *)CONCAT13((char)((uint)iVar21 >> 8),
                                CONCAT12((char)iVar21,*(int *)(iVar18 * 4) + 0x94)),3);
        iVar18 = CONCAT11(uVar16,uVar30);
      }
    }
  }
  uVar34 = 0;
  uVar17 = 0x2356;
  bVar10 = ovr_manage_findFirstLeader();
  a = CONCAT13(bVar10,(int3)fmt);
  uVar26 = EntityScanPos;
  if ((bVar10 == 0xff) || (GCanPromote == '\0')) {
    pbVar13 = (byte *)0x0;
  }
  else if (*(byte *)((int)*(undefined4 *)((uint)bVar10 << 2) + 0x86) < 5) {
    pbVar13 = (byte *)__C0_ASM_CopyRight + 0x24;
  }
  else {
    pbVar13 = (byte *)((uint)*(byte *)((int)*(undefined4 *)((uint)bVar10 << 2) + 0x86) * 4 + 0x14);
  }
  for (; uVar26 < EntityCount; uVar26 = uVar26 + 1) {
    uVar28 = (undefined2)((ulong)Entities >> 0x10);
    peVar22 = (entity_t *)Entities;
    if (((*(char *)((int)&peVar22[uVar26].base.entity + 1) == '\0') &&
        (peVar22[uVar26].base.destX == 0)) && (peVar22[uVar26].base.destY == 0)) {
      bVar10 = peVar22[uVar26].base.gindex;
      a = CONCAT13((char)((ulong)a >> 0x18),CONCAT12(bVar10,(int)a));
      bVar5 = *(byte *)((int)&peVar22[uVar26].base.entity + 3);
      bVar29 = false;
      bVar9 = false;
      bVar8 = false;
      if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar10 * 0x95) == -1) {
        bVar29 = true;
      }
      else {
        bVar10 = *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x89);
        uStackY_1c = CONCAT11(bVar10,(char)uStackY_1c);
        if (bVar10 < 5) {
          uVar34 = peVar22[uVar26].base.y;
          uVar17 = 0x2379;
          uVar15 = ovr_alignUp4(((peVar22 + uVar26)->base).x);
          uVar14 = 0x2410;
          if (((*(short (*) [60] [148])GMapFlags)[uVar34][uVar15] & 8U) == 0) {
            uStackY_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1e) + 1)),0x22);
            bStackY_1f = 0x21;
            bStackY_20 = 0x22;
          }
          else {
            uVar37 = (undefined1)unaff_SS;
            uVar38 = (undefined1)(unaff_SS >> 8);
            puVar36 = &uStackY_1e;
            pbVar13 = &bStackY_1f;
            pbVar32 = &bStackY_20;
            uVar30 = (*(uint8_t *)((uint8_t *)&(uStackY_1c) + 1));
            uVar16 = (undefined1)((uint)pbVar32 >> 8);
            uStackY_1c = 0x2379;
            uStackY_1e = 0x3d98;
            uVar33 = unaff_SS;
            uVar35 = unaff_SS;
            uVar34 = ovr_attact_usesSquareRecCount(uVar34,uVar34);
            table.seg = uVar14;
            table.ofs = uVar34;
            uStackY_1c = 0x2315;
            uVar17 = 0x2315;
            uStackY_1e = 0x3da2;
            pctOut.seg = uVar33;
            pctOut.ofs = (uint16_t)pbVar32;
            remainderOut.seg = uVar35;
            remainderOut.ofs = (uint16_t)pbVar13;
            (*(uint8_t *)((uint8_t *)&(partOut.seg))) = uVar37;
            partOut.ofs = (uint16_t)puVar36;
            (*(uint8_t *)((uint8_t *)&(partOut.seg) + 1)) = uVar38;
            ovr_attact_compute3(table,CONCAT11(uVar16,uVar30),pctOut,remainderOut,partOut);
            uVar26 = CONCAT11(uVar16,uVar30);
          }
        }
        else {
          uStackY_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1e) + 1)),0x22);
          bStackY_1f = 0x21;
          bStackY_20 = 0x22;
        }
        uVar30 = (undefined1)uVar17;
        uVar16 = (undefined1)((uint)uVar17 >> 8);
        uVar17 = 0x2337;
        uVar34 = 0x3dca;
        uVar14 = ovr_randBelow(100);
        pbVar13 = (byte *)CONCAT11(uVar16,uVar30);
        if ((byte)uVar14 < (byte)uStackY_1e) {
          bVar29 = true;
          pbVar13 = (byte *)CONCAT11(uVar16,uVar30);
        }
        else if ((uVar14 & 0xff) < (uint)bStackY_1f + (uStackY_1e & 0xff)) {
          bVar9 = true;
          pbVar13 = (byte *)CONCAT11(uVar16,uVar30);
        }
        else {
          bVar8 = true;
        }
      }
      if (bVar8) {
        uVar17 = (undefined2)((ulong)Entities >> 0x10);
        uVar34 = ((entity_t *)Entities)[uVar26].base.y;
        uVar30 = (undefined1)uVar34;
        uVar16 = (undefined1)(uVar34 >> 8);
        uVar34 = (((entity_t *)Entities + uVar26)->base).x;
        uVar17 = 0x236f;
        cVar11 = ovr_ovc23_tickRecordsAt(uVar34);
        pbVar13 = (byte *)CONCAT11(uVar16,uVar30);
        if (cVar11 == '\0') {
          if ((bStackY_1f == 0) && ((byte)uStackY_1e == '\0')) {
            uVar30 = 0x6f;
            uVar16 = 0x23;
            uVar17 = 0x2337;
            uVar34 = 0x3e5d;
            uVar14 = ovr_randBelow(2);
            if ((uVar14 & 0xff) == 0) {
              bVar29 = true;
              pbVar13 = (byte *)CONCAT11(uVar16,uVar30);
            }
            else {
              bVar9 = true;
              pbVar13 = (byte *)CONCAT11(uVar16,uVar30);
            }
          }
          else {
            uVar30 = 0x6f;
            uVar16 = 0x23;
            uVar17 = 0x2337;
            uVar34 = 0x3e86;
            uVar14 = ovr_randBelow((uint)bStackY_1f + (uStackY_1e & 0xff));
            pbVar13 = (byte *)CONCAT11(uVar16,uVar30);
            if ((byte)uVar14 < (byte)uStackY_1e) {
              bVar29 = true;
              pbVar13 = (byte *)CONCAT11(uVar16,uVar30);
            }
            else {
              bVar9 = true;
            }
          }
        }
      }
      uVar30 = (undefined1)uVar17;
      uVar16 = (undefined1)((uint)uVar17 >> 8);
      if (bVar29) {
        uVar34 = 0x3ea5;
        uVar15 = ovc22_usesEntities(uVar26);
        pbVar13 = (byte *)CONCAT11(uVar16,uVar30);
        if ((uVar15 & 0xff) == 0) {
          bVar9 = true;
          pbVar13 = (byte *)CONCAT11(uVar16,uVar30);
        }
      }
      if (bVar9) {
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(byte)((ulong)a >> 0x10) * 0x95) !=
             -1) && (bVar5 != 0xff)) {
          if ((*(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x3f) != '\0') ||
             (Entities[uVar26].base.level < *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x53)
             )) {
            ovc22_usesLUDIV_at_((entity_t *)
                                CONCAT13((char)((ulong)Entities >> 0x18),
                                         CONCAT12((char)((ulong)Entities >> 0x10),Entities + uVar26
                                                 )));
            LXMUL_at_((long *)pbVar13,a,b);
            peVar22 = Entities + uVar26;
            uVar30 = 0x89;
            uVar16 = 0x3f;
            uVar34 = ovr_ovc15_textError();
            uVar15 = ovc22_usesLUDIV_at_2(uVar34,(uint16_t)peVar22,(int)pbVar13);
            uVar17 = (undefined2)((ulong)Entities >> 0x10);
            peVar23 = (entity_t *)Entities;
            uVar26 = *(uint *)&peVar23[CONCAT11(uVar16,uVar30)].base.health;
            *(uint *)&peVar23[CONCAT11(uVar16,uVar30)].base.frameIndex =
                 (int)&(peVar22->base).x +
                 (uint)CARRY2(uVar26,uVar15) +
                 *(int *)&peVar23[CONCAT11(uVar16,uVar30)].base.frameIndex;
            *(uint *)&peVar23[CONCAT11(uVar16,uVar30)].base.health = uVar26 + uVar15;
            uVar17 = 0x23d5;
            ovr_ovc41_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                        CONCAT12((char)((ulong)Entities >> 0x10),
                                                 Entities + CONCAT11(uVar16,uVar30))));
            uVar26 = CONCAT11(uVar16,uVar30);
          }
        }
        ovc22_usesEntities2(uVar26);
        ovc22_usesEntities3(uVar26);
        uVar30 = (undefined1)uVar17;
        uVar16 = (undefined1)((uint)uVar17 >> 8);
        uVar34 = 0x4016;
        ovc22_usesEntities4(uVar26);
        pbVar13 = (byte *)CONCAT11(uVar16,uVar30);
      }
      iStackY_2a = (uint)((entity_t *)Entities)[uVar26].base.animFrame -
                   (uint)*(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0xa4);
      if (0 < iStackY_2a) {
        if (3 < iStackY_2a) {
          iStackY_2a = 3;
        }
        if (iStackY_2a == 3) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x92) == 0) {
            iStackY_2a = 2;
          }
          else {
            piVar2 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x92);
            *piVar2 = *piVar2 + -1;
          }
        }
        if (iStackY_2a == 2) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x90) == 0) {
            iStackY_2a = 1;
          }
          else {
            piVar2 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x90);
            *piVar2 = *piVar2 + -1;
          }
        }
        if (iStackY_2a == 1) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x8e) == 0) {
            iStackY_2a = 0;
          }
          else {
            piVar2 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x8e);
            *piVar2 = *piVar2 + -1;
          }
        }
        ((entity_t *)Entities)[uVar26].base.animFrame =
             *(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0xa4) + (char)iStackY_2a;
      }
      uVar34 = uVar34 + 1;
      if (199 < (int)uVar34) break;
    }
  }
  EntityScanPos = uVar26;
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
      uVar17 = (undefined2)((ulong)Entities >> 0x10);
      peVar22 = (entity_t *)Entities;
      msg = (uint *)(uint)peVar22[(int)entityIndex].base.animFrame;
      if (msg == (uint *)0x0) {
        msg = (uint *)(uint)*(byte *)((int)(char **)GMenuStrings +
                                     (uint)peVar22[(int)entityIndex].base.gindex * 0x95 + 0x1f);
        if (msg == (uint *)0x0) {
          ovr_alignUp4(((peVar22 + (int)entityIndex)->base).x);
          iVar18 = (uint)((entity_t *)Entities)[(int)entityIndex].base.gindex * 0x95;
          uVar30 = 0x12;
          uVar16 = 0x56;
          msg = (uint *)ovr_fmVsprintf("Intelligence reports %s unit died of starvation. (%d, %d)",
                                       (char *)CONCAT22(*(undefined2 *)
                                                         ((int)&worldMenuLabels[1].ofs + 1 + iVar18)
                                                        ,(char *)*(undefined2 *)
                                                                  ((int)&worldMenuLabels[0].seg + 1
                                                                  + iVar18)));
          ovr_uiNotify((char *)msg);
          entityIndex = (uint *)CONCAT11(uVar16,uVar30);
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

/* WARNING: Instruction at (ram,0x00056a00) overlaps instruction at (ram,0x000569fe)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* [R2] string "Construction abandoned." */

bool __cdecl16far ovc23_textConstructionAbandoned(char *ofs,uint8_t *seg,byte dir)

{
  int *piVar1;
  uint *puVar2;
  byte *pbVar3;
  byte bVar4;
  uint8_t *puVar6;
  uint8_t uVar7;
  uint16_t play_id;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined2 uVar11;
  char *pcVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  undefined1 uVar16;
  byte bVar21;
  undefined1 extraout_AH;
  int iVar17;
  uint uVar18;
  undefined4 *puVar19;
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
  undefined2 *puVar31;
  undefined2 *puVar32;
  char *unaff_BP;
  uint uVar33;
  uint unaff_SI;
  uint uVar34;
  uint8_t *puVar35;
  undefined2 unaff_SS;
  undefined2 uVar36;
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
     (puVar19 = (undefined4 *)(uint)dir, puVar19 <= (undefined4 *)((int)(undefined4 *)&_DATA + 3)))
  {
    iVar28 = (int)puVar19 * 2;
    switch(puVar19) {
    case (undefined4 *)0x0:
      (**(code **)(pcVar12 + iVar28 + -0x70))();
      break;
    case (undefined4 *)0x2:
      uVar18 = 0x1000 << (*(byte *)((int)*puVar19 + 0x3f) & 0x1f);
      uVar10 = *(undefined4 *)((uint)(byte)(uVar43 >> 0x10) << 2);
      uVar33 = 0x1000 << ((*(byte *)((int)uVar10 + 0x3f) ^ 1) & 0x1f);
      uVar34 = 0;
      for (uVar43 = uVar43 & 0xffffff; bVar22 = (byte)(uVar43 >> 0x18), bVar22 < 4;
          uVar43 = CONCAT13(bVar22 + 1,(int3)uVar43)) {
        iVar28 = (int)&in_stack_0000fffc->x + (uint)bVar22;
        uVar33 = iVar28 * 2;
        uVar34 = uVar34 | ((short (*) [60] [148])GMapFlags)[-1][unaff_SI + 0x3b][iVar28 + 0x92] &
                          0x3000U;
      }
      if ((((*(byte *)((int)pcVar12 * 0x12 + 0xd) & 3) != 1) || (uVar34 != uVar33)) ||
         (uVar10 = *(undefined4 *)((uint)(byte)(uVar43 >> 0x10) << 2),
         bVar37 = ovr_ovc24_textArena((uint16_t)in_stack_0000fffc,unaff_SI,
                                      *(char *)((int)uVar10 + 0x3f)), bVar37)) {
        bVar22 = *(byte *)((int)pcVar12 * 0x12 + 0xd);
        pbVar20 = (byte *)(uint)bVar22;
        if (((bVar22 & 1) == 0) && ((uVar18 & uVar34) != 0)) {
          pbVar20 = (byte *)((int)pcVar12 * 0x12);
          pbVar20[0xd] = pbVar20[0xd] | 1;
        }
      }
      else {
        uVar36 = ovc23_isCursorAt((uint16_t)in_stack_0000fffc,unaff_SI);
        if ((char)uVar36 != '\0') {
          ovr_say((char *)"Construction abandoned.");
        }
        if (pcVar12 + 1 < GRecordCount) {
          _fmemmove((char *)CONCAT22(0x21f2,(char *)((int)pcVar12 * 0x12)),
                    (char *)CONCAT22(0x21f2,(char *)((int)pcVar12 * 0x12 + 0x12)),
                    (int)(GRecordCount + (-1 - (int)pcVar12)) * 0x12);
        }
        GRecordCount = GRecordCount + -1;
        pbVar20 = ovc23_textAdlibNone(uVar18,unaff_SI,in_stack_0000fffc);
      }
      return SUB21(pbVar20,0);
    case (undefined4 *)0x3:
      pcVar24 = pcVar24 + -1;
      bVar23 = (byte)iVar28;
      bVar15 = bVar23 - AgntAnms[0xf].frmid;
      bVar13 = (byte)((uint)iVar28 >> 8);
      bVar22 = bVar13 - dir;
      bVar29 = bVar22 - (bVar23 < AgntAnms[0xf].frmid);
      puVar26 = (uint *)CONCAT11(bVar29,bVar15);
      puVar8 = (undefined1 *)(uint)(bVar13 < dir || bVar22 < (bVar23 < AgntAnms[0xf].frmid));
      puVar31 = (undefined2 *)(&stack0xfffe + -(int)in_CX + -(int)puVar8);
      puVar2 = (uint *)(puVar35 + -0x57e7);
      uVar33 = (uint)(&stack0xfffe < in_CX || &stack0xfffe + -(int)in_CX < puVar8);
      puVar32 = (undefined2 *)*puVar2;
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
      (*(uint16_t *)((uint8_t *)&(s_Peaceful_2410_2915) + 4)) = (0x6665U - (int)puVar35) - uVar18;
      uVar18 = (uint)((uint)0x6665 < puVar35 || (uint)(0x6665U - (int)puVar35) < uVar18);
      bVar37 = (uint)AgntAnms[6].y < pcVar24;
      uVar33 = AgntAnms[6].y - (int)pcVar24;
      AgntAnms[6].y = uVar33 - uVar18;
      puVar8 = (undefined1 *)(uint)(bVar37 || uVar33 < uVar18);
      puVar9 = &stack0xfff6 + -(int)puVar35;
      bVar37 = &stack0xfff6 < puVar35 || puVar9 < puVar8;
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
        puVar32 = (undefined2 *)*puVar31;
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
                  ovr_constr_usesScreenOriginY((uint16_t)ofs,(uint16_t)seg);
                }
                return (bool)uVar16;
              }
              play_id = *(uint16_t *)((int)puVar35 * 2 + 0x360);
            } while (((int)play_id < -2) || (1 < (int)play_id));
            in_stack_00000000 = (brect_t *)((ulong)in_stack_00000000 & 0xffff0000);
            bVar22 = ovr_constr_setHighlightAtOffset(play_id,0);
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
          uVar36 = (undefined2)((ulong)in_stack_00000000 >> 0x10);
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
      ovc23_usesCornerBR2(-2,(uint)*(byte *)(iRam0002d2d7 * 0x12 + 7));
      in_stack_00000000 = (brect_t *)CONCAT22(uVar36,seg);
      unaff_SI = (uint)bandOrigin[0] - (int)in_stack_0000fffc;
      unaff_BP = ofs;
    } while( true );
  }
  return false;
}



/* 55fe:0f39 */

/* Rebuilds the four direction bits of a map cell from its neighbour tests. */

void __cdecl16far ovc23_rebuildDirectionFlags(int x,int y,...)

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

void __cdecl16far ovc23_placeBuilding(int x,int y,byte bldType,uint8_t unitType,...)

{
  byte *pbVar1;
  uint *puVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  
  iVar4 = (*(short (*) [148] [60])GUnitGrid)[x][y];
  bVar3 = ((unit_t *)GUnits + iVar4)->bldType;
  if ((*(uint *)((uint)bVar3 * 0x27 + 0x121) & 4) != 0) {
    strongholdCheckPending = 1;
  }
  uVar6 = ovr_ovc18_usesRandBelow(x,y,bldType,unitType);
  if ((*(byte *)((uint)bldType * 0x27 + 0x11e) & 2) == 2) {
    ovc23_usesGfxRndSeed2(x,y);
  }
  if (((*(byte *)((uint)bldType * 0x27 + 0x11e) & 0xf) != 0) ||
     ((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 0xf) != 0)) {
    ovc23_rebuildDirectionFlags(x,y);
  }
  if (((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 1) != 0) ||
     ((*(byte *)((uint)bldType * 0x27 + 0x11e) & 1) != 0)) {
    ovc23_rebuildDirectionFlags(x,y + 1);
  }
  if (((*(byte *)((uint)bldType * 0x27 + 0x11e) & 2) != 0) ||
     ((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 2) != 0)) {
    ovc23_rebuildDirectionFlags(x + -1,y);
  }
  if (((*(byte *)((uint)bldType * 0x27 + 0x11e) & 3) == 3) ||
     ((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 3) == 3)) {
    ovc23_rebuildDirectionFlags(x + 1,y);
    ovc23_rebuildDirectionFlags(x,y + 1);
  }
  if (*(char *)((uint)bldType * 0x27 + 0x11a) == '\x02') {
    if (((*(short (*) [60] [148])GMapFlags)[y + 1][x] & 3U) != 0) {
      pbVar1 = &((unit_t *)GUnits)[uVar6].flags;
      *pbVar1 = *pbVar1 | 4;
      puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x);
      *puVar2 = *puVar2 & 0xfffc;
    }
    if ((*(byte *)((uint)bldType * 0x27 + 0x11e) & 4) != 0) {
      if (((*(short (*) [60] [148])GMapFlags)[y][x + 0x93] & 3U) != 0) {
        pbVar1 = &((unit_t *)GUnits)[uVar6].flags;
        *pbVar1 = *pbVar1 | 8;
        puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x + 0x93);
        *puVar2 = *puVar2 & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -2,y);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
      }
      if (((*(short (*) [60] [148])GMapFlags)[y + 1][x + 1] & 3U) != 0) {
        pbVar1 = &((unit_t *)GUnits)[uVar6].flags;
        *pbVar1 = *pbVar1 | 0x10;
        puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x + 1);
        *puVar2 = *puVar2 & 0xfffc;
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x + 2,y);
      }
    }
    if ((*(byte *)((uint)bldType * 0x27 + 0x11e) & 8) != 0) {
      if (((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) != 0) {
        pbVar1 = &((unit_t *)GUnits)[uVar6].flags;
        *pbVar1 = *pbVar1 | 8;
        puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
        *puVar2 = *puVar2 & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x,y + -2);
      }
      if (((*(short (*) [60] [148])GMapFlags)[y + 2][x] & 3U) != 0) {
        pbVar1 = &((unit_t *)GUnits)[uVar6].flags;
        *pbVar1 = *pbVar1 | 0x10;
        puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[y + 2] + x);
        *puVar2 = *puVar2 & 0xfffc;
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
  if (*(char *)((uint)bVar3 * 0x27 + 0x11a) == '\x02') {
    ovc23_usesGfxRndSeed2(x,y);
    if ((((unit_t *)GUnits)[iVar4].flags & 4) != 0) {
      ovc23_drownUnitsAt(x,y);
    }
    if (*(char *)((uint)bVar3 * 0x27 + 0x11e) == '\x04') {
      bVar5 = ovr_ovc45_getUnitType(x + -1,y);
      if ((CONCAT11(extraout_AH,bVar5) == 0) && ((((unit_t *)GUnits)[iVar4].flags & 8) != 0)) {
        ovc23_usesGfxRndSeed2(x + -1,y);
        ovc23_drownUnitsAt(x - 1,y);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
        ovc23_rebuildDirectionFlags(x + -2,y);
      }
      bVar5 = ovr_ovc45_getUnitType(x + 1,y);
      if ((CONCAT11(extraout_AH_00,bVar5) == 0) && ((((unit_t *)GUnits)[iVar4].flags & 0x10) != 0))
      {
        ovc23_usesGfxRndSeed2(x + 1,y);
        ovc23_drownUnitsAt(x + 1,y);
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x + 2,y);
      }
    }
    else if (*(char *)((uint)bVar3 * 0x27 + 0x11e) == '\b') {
      bVar5 = ovr_ovc45_getUnitType(x,y + -1);
      if ((CONCAT11(extraout_AH_01,bVar5) == 0) && ((((unit_t *)GUnits)[iVar4].flags & 8) != 0)) {
        ovc23_usesGfxRndSeed2(x,y + -1);
        ovc23_drownUnitsAt(x,y - 1);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x,y + -2);
      }
      bVar5 = ovr_ovc45_getUnitType(x,y + 1);
      if ((CONCAT11(extraout_AH_02,bVar5) == 0) && ((((unit_t *)GUnits)[iVar4].flags & 0x10) != 0))
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
  if ((*(char *)((uint)bldType * 0x27 + 0x133) == '\x12') && (ListCount < 5)) {
    *(uint *)((uint)ListCount * 2 + -0x6d44) = uVar6;
    ListCount = ListCount + 1;
  }
  if ((*(int *)((uint)bldType * 0x27 + 0x12e) != 0) || (*(int *)((uint)bVar3 * 0x27 + 0x12e) != 0))
  {
    ovr_unit_usesAlignUp4();
  }
  return;
}



/* 55fe:1803 */

/* Removes a record from the 0x12-stride table at 0x21f2, compacts the tail and decrements
   GRecordCount. */

void __cdecl16far ovc23_removeRecord(int recordIndex,...)

{
  uint16_t unaff_BP;
  uint unaff_SI;
  agnt_t *in_stack_00000000;
  
  if (recordIndex + 1U < GRecordCount) {
    _fmemmove((char *)CONCAT22(0x21f2,(char *)(recordIndex * 0x12)),
              (char *)CONCAT22(0x21f2,(char *)(recordIndex * 0x12 + 0x12)),
              ((GRecordCount - recordIndex) + -1) * 0x12);
  }
  GRecordCount = GRecordCount - 1;
  ovc23_textAdlibNone(unaff_SI,unaff_BP,in_stack_00000000);
  return;
}



/* 55fe:184e */

/* appends a construction record (bldType, x, y, party, tick) */

void __cdecl16far
createConstructionRecord(byte bldType,int x,int y,uint8_t *outFlag,char partyIndex,...)

{
  int *piVar1;
  byte *pbVar2;
  undefined1 uVar3;
  int iVar4;
  undefined2 uVar5;
  uint uVar6;
  uint16_t unaff_SI;
  uint uVar7;
  uint16_t unaff_DI;
  uint uVar8;
  undefined2 uVar9;
  undefined1 uStack000d;
  byte in_stack_0000000e;
  char in_stack_00000010;
  agnt_t *in_stack_0000fff6;
  uint uStack_8;
  byte bStack_5;
  byte bStack_3;
  
  outFlag = (undefined1 *)CONCAT13(uStack000d,CONCAT12(partyIndex,outFlag));
  for (uStack_8 = 0; (int)uStack_8 < (int)(uint)*(byte *)((uint)bldType * 0x27 + 0x11b);
      uStack_8 = uStack_8 + 1) {
    in_stack_0000fff6 = (agnt_t *)ovc23_findRecordAt(x + uStack_8,y);
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
  for (uStack_8 = 1; (int)uStack_8 < (int)(uint)*(byte *)((uint)bldType * 0x27 + 0x11b);
      uStack_8 = uStack_8 + 1) {
    ovc23_placeBuilding(x + uStack_8,y,0,in_stack_0000000e);
    uVar5 = ovr_ovc22_usesGOngoingBattle((byte)x + (char)uStack_8,(byte)y);
    if ((char)uVar5 != '\0') {
      *outFlag = 1;
    }
  }
  if (*(char *)((int)*(undefined4 *)((uint)in_stack_0000000e << 2) + 0x3f) == '\0') {
    if (0x31 < GRecordCount) {
      uVar7 = 0;
      uVar8 = 0xffff;
      for (uStack_8 = 0; uStack_8 < GRecordCount; uStack_8 = uStack_8 + 1) {
        uVar6 = ovr_ovc22_usesGOngoingBattle
                          (*(byte *)(uStack_8 * 0x12 + 2),*(byte *)(uStack_8 * 0x12 + 4));
        if (((uVar6 & 0xff) == 0) && (uVar7 <= (uint)(GameTick - *(int *)(uStack_8 * 0x12 + 0xf))))
        {
          uVar7 = GameTick - *(int *)(uStack_8 * 0x12 + 0xf);
          uVar8 = uStack_8;
        }
      }
      if (uVar8 == 0xffff) {
        for (uStack_8 = 0; uStack_8 < GRecordCount; uStack_8 = uStack_8 + 1) {
          if (uVar7 <= (uint)(GameTick - *(int *)(uStack_8 * 0x12 + 0xf))) {
            uVar7 = GameTick - *(int *)(uStack_8 * 0x12 + 0xf);
            uVar8 = uStack_8;
          }
        }
      }
      if (uVar8 == 0xffff) {
        return;
      }
      if (uVar8 + 1 < GRecordCount) {
        _fmemmove((char *)CONCAT22(0x21f2,(char *)(uVar8 * 0x12)),
                  (char *)CONCAT22(0x21f2,(char *)(uVar8 * 0x12 + 0x12)),
                  ((GRecordCount - uVar8) + -1) * 0x12);
      }
      GRecordCount = GRecordCount - 1;
    }
    _fmemset((void *)0x21f2,0x12,unaff_DI);
    *(byte *)(GRecordCount * 0x12 + 8) = bldType;
    *(int *)(GRecordCount * 0x12 + 2) = x;
    *(int *)(GRecordCount * 0x12 + 4) = y;
    *(byte *)(GRecordCount * 0x12 + 9) = in_stack_0000000e;
    iVar4 = ovc23_isLargeBuilding(x,y);
    uVar5 = (undefined2)((ulong)GUnitGrid >> 0x10);
    uVar9 = (undefined2)((ulong)GUnits >> 0x10);
    if ((char)iVar4 == '\0') {
      bStack_5 = ((unit_t *)GUnits + (*(short (*) [148] [60])GUnitGrid)[x][y])->bldType;
    }
    else {
      bStack_5 = ((unit_t *)GUnits + ((short (*) [148] [60])GUnitGrid)[-1][x + 0x93][y])->bldType;
    }
    bStack_3 = *(byte *)((uint)bStack_5 * 0x27 + 0x11d);
    uVar3 = *(undefined1 *)((uint)bStack_5 * 0x27 + 0x11b);
    if (bStack_3 == 0) {
      bStack_3 = 1;
    }
    if (bStack_3 < *(byte *)((uint)bldType * 0x27 + 0x11c)) {
      *(undefined1 *)(GRecordCount * 0x12 + 6) = *(undefined1 *)((uint)bldType * 0x27 + 0x11c);
    }
    else {
      *(byte *)(GRecordCount * 0x12 + 6) = bStack_3;
    }
    *(int *)(GRecordCount * 0x12 + 0xf) = GameTick;
    *(undefined2 *)(GRecordCount * 0x12) = 0;
    uVar5 = ovc23_usesGRecordCount3
                      (*(byte *)((uint)bldType * 0x27 + 0x120),in_stack_0000000e,GRecordCount);
    *(undefined1 *)(GRecordCount * 0x12 + 0xc) = (char)uVar5;
    if (*(char *)(GRecordCount * 0x12 + 0xc) == '\0') {
      *(undefined1 *)(GRecordCount * 0x12 + 0xc) = 1;
    }
    if (bldType == 0) {
      iVar4 = ovc23_isLargeBuilding(x,y);
      if ((char)iVar4 != '\0') {
        piVar1 = (int *)(GRecordCount * 0x12 + 2);
        *piVar1 = *piVar1 + -1;
      }
      *(undefined1 *)(GRecordCount * 0x12 + 7) = uVar3;
      if (in_stack_00000010 == '\x01') {
        *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 1;
      }
      else {
        *(char *)(GRecordCount * 0x12 + 0xc) = in_stack_00000010;
        *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 0;
      }
      pbVar2 = (byte *)(GRecordCount * 0x12 + 0xd);
      *pbVar2 = *pbVar2 | 3;
    }
    else {
      *(undefined1 *)(GRecordCount * 0x12 + 7) = *(undefined1 *)((uint)bldType * 0x27 + 0x11b);
      if (in_stack_00000010 != '\0') {
        ovc23_placeBuilding(x,y,0,in_stack_0000000e);
        uVar5 = ovr_ovc22_usesGOngoingBattle((byte)x,(byte)y);
        if ((char)uVar5 != '\0') {
          *outFlag = 1;
        }
      }
      *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 0;
    }
    *(undefined1 *)(GRecordCount * 0x12 + 0x11) = 0;
    *(undefined1 *)(GRecordCount * 0x12 + 0xb) = *(undefined1 *)(GRecordCount * 0x12 + 0xc);
    uVar8 = GRecordCount;
    GRecordCount = GRecordCount + 1;
    ovc23_abandonConstruction(uVar8);
    ovc23_textAdlibNone(unaff_DI,unaff_SI,in_stack_0000fff6);
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
          (byte bldType,int x,int y,uint8_t *outFlag,byte outFlagSeg,char partyIndex,...)

{
  undefined2 in_AX;
  
  createConstructionRecord
            (bldType,x,y,(uint8_t *)outFlag,(char)((ulong)outFlag >> 0x10),
             CONCAT11((char)((uint)in_AX >> 8),outFlagSeg),1);
  return;
}



/* 55fe:1ea9 */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc23_usesBlitGfxRect(int x,int y,int recordIndex,brect_t *rect,uint16_t type)

{
  int y_00;
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int x_00;
  uint uVar4;
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
  uint uStack_10;
  uint uStack_e;
  int iStack_c;
  uint16_t uStack_a;
  uint16_t uStack_8;
  
  uStack_10 = (uint)*(byte *)(y * 0x12 + 6);
  uVar3 = *(uint *)(y * 0x12);
  bVar1 = *(byte *)(y * 0x12 + 0xe);
  bVar2 = *(byte *)(y * 0x12 + 0x11);
  if (bVar2 < uStack_10) {
    uStack_10 = bVar2 + 1;
  }
  x_00 = in_stack_00000004 + -1;
  iStack_c = x + uStack_10 * -0x26 + -0x32;
  uStack_e = uStack_10;
  while (uStack_e = uStack_e - 1, -1 < (int)uStack_e) {
    y_00 = iStack_c + 0x26;
    type_00 = (uint8_t)rect;
    if ((bVar1 == 2) || (0x13 < uVar3)) {
      if (bVar1 < 2) {
        if ((uStack_e == 0) && ((uVar3 - x_00 & 0x3f) < 0x20)) {
          uVar4 = uVar3 - x_00 & 0x3f;
          uStack_8 = ((undefined2 *)&csite5Seg)[uVar4 * 2];
          uStack_a = ((undefined2 *)&csite5Ofs)[uVar4 * 2];
        }
        else {
          uStack_8 = csite3_5Seg;
          uStack_a = csite3_5Ofs;
        }
        if (uStack_e == 0) {
          uVar4 = (uVar3 + GfxRndSeed2) % 0xe;
          gfx_01.seg = ((undefined2 *)&tmstrsSprites6Seg)[uVar4 * 2];
          gfx_01.ofs = ((undefined2 *)&tmstrsSprites6Ofs)[uVar4 * 2];
          ovr_blitGfxRect(gfx_01,in_stack_00000004 + 0xe,iStack_c + 0x8b,(brect_t *)recordIndex,
                          type_00,true,1);
        }
        gfx_02.seg = uStack_8;
        gfx_02.ofs = uStack_a;
        ovr_blitGfxRect(gfx_02,x_00,y_00,(brect_t *)recordIndex,type_00,true,0);
        if ((uVar3 + uStack_e + GfxRndSeed2 + x_00 & 0x1f) < 0x11) {
          uVar4 = uVar3 + uStack_e + GfxRndSeed2 + x_00 & 0x1f;
          gfx_03.seg = ((undefined2 *)&tmstrsSprites5Seg)[uVar4 * 2];
          gfx_03.ofs = ((undefined2 *)&tmstrsSprites5Ofs)[uVar4 * 2];
          ovr_blitGfxRect(gfx_03,x_00 + ((uint)*(byte *)((uVar3 + uStack_e + GfxRndSeed2 + x_00 >> 5
                                                         ) + uStack_e + GfxRndSeed2 & 0xff) * 0x50)
                                        / 0x100,iStack_c + 0x66,(brect_t *)recordIndex,type_00,true,
                          0);
        }
        if ((((uVar3 + uStack_e) - GfxRndSeed2) - x_00 & 0xf) < 7) {
          uVar4 = ((uVar3 + uStack_e) - GfxRndSeed2) - x_00 & 0xf;
          gfx_04.seg = ((undefined2 *)&tmstrsSprites4Seg)[uVar4 * 2];
          gfx_04.ofs = ((undefined2 *)&tmstrsSprites4Ofs)[uVar4 * 2];
          ovr_blitGfxRect(gfx_04,x_00 + ((uint)*(byte *)((((((uVar3 + uStack_e) - GfxRndSeed2) -
                                                            x_00 >> 4) + uStack_e) - GfxRndSeed2) +
                                                         0xe & 0xff) * 0x50) / 0x100,iStack_c + 0x66
                          ,(brect_t *)recordIndex,type_00,true,0);
        }
        uVar4 = (uVar3 + 5) % 7;
        gfx_05.seg = ((undefined2 *)&tmstrsSprites3Seg)[uVar4 * 2];
        gfx_05.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[uVar4 * 2];
        ovr_blitGfxRect(gfx_05,in_stack_00000004 + 9,iStack_c + 0x62,(brect_t *)recordIndex,type_00,
                        true,0);
        gfx_06.seg = ((undefined2 *)&tmstrsSprites3Seg)[(uVar3 % 7) * 2];
        gfx_06.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[(uVar3 % 7) * 2];
        ovr_blitGfxRect(gfx_06,in_stack_00000004 + 0xd,iStack_c + 0x62,(brect_t *)recordIndex,
                        type_00,true,0);
        uVar4 = (uVar3 + 2) % 7;
        gfx_07.seg = ((undefined2 *)&tmstrsSprites3Seg)[uVar4 * 2];
        gfx_07.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[uVar4 * 2];
        ovr_blitGfxRect(gfx_07,in_stack_00000004 + 0x31,iStack_c + 0x62,(brect_t *)recordIndex,
                        type_00,true,0);
        uVar4 = uVar3 + 3 & 7;
        gfx_08.seg = ((undefined2 *)&tmstrsSprites2Seg)[uVar4 * 2];
        gfx_08.ofs = ((undefined2 *)&tmstrsSprites2Ofs)[uVar4 * 2];
        ovr_blitGfxRect(gfx_08,in_stack_00000004 + 0x45,iStack_c + 0x62,(brect_t *)recordIndex,
                        type_00,true,0);
        gfx_09.seg = ((undefined2 *)&tmstrsSprites2Seg)[(uVar3 & 7) * 2];
        gfx_09.ofs = ((undefined2 *)&tmstrsSprites2Ofs)[(uVar3 & 7) * 2];
        ovr_blitGfxRect(gfx_09,in_stack_00000004 + 0x3b,iStack_c + 0x62,(brect_t *)recordIndex,
                        type_00,true,0);
        gfx_10.seg = ((undefined2 *)&tmstrsSprites1Seg)[(uVar3 % 5) * 2];
        gfx_10.ofs = ((undefined2 *)&tmstrsSprites1Ofs)[(uVar3 % 5) * 2];
        ovr_blitGfxRect(gfx_10,in_stack_00000004 + 0x27,iStack_c + 0x62,(brect_t *)recordIndex,
                        type_00,true,0);
        gfx_11.seg = ((undefined2 *)&tmstrsSprites1Seg)[(uVar3 % 5) * 2];
        gfx_11.ofs = ((undefined2 *)&tmstrsSprites1Ofs)[(uVar3 % 5) * 2];
        ovr_blitGfxRect(gfx_11,in_stack_00000004 + 0x3f,iStack_c + 0x62,(brect_t *)recordIndex,
                        type_00,true,0);
        iStack_c = y_00;
      }
      else {
        if (uVar3 < 9) {
          uStack_8 = ((undefined2 *)&csite2Seg)[(uVar3 + 0xe) * 2];
          uStack_a = ((undefined2 *)&csite2Ofs)[(uVar3 + 0xe) * 2];
        }
        else {
          uStack_8 = csite4_8Seg;
          uStack_a = csite4_8Ofs;
        }
        gfx_00.seg = uStack_8;
        gfx_00.ofs = uStack_a;
        ovr_blitGfxRect(gfx_00,x_00,y_00,(brect_t *)recordIndex,type_00,true,0);
        iStack_c = y_00;
      }
    }
    else {
      if ((uStack_10 - 1 == uStack_e) && (uVar3 < 0xf)) {
        uStack_8 = ((undefined2 *)&csite2Seg)[uVar3 * 2];
        uStack_a = ((undefined2 *)&csite2Ofs)[uVar3 * 2];
      }
      else {
        uStack_8 = csite3_5Seg;
        uStack_a = csite3_5Ofs;
      }
      gfx.seg = uStack_8;
      gfx.ofs = uStack_a;
      ovr_blitGfxRect(gfx,x_00,y_00,(brect_t *)recordIndex,type_00,true,0);
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
  byte bVar2;
  uint uVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  int x_00;
  uint uVar6;
  uint16_t unaff_SI;
  undefined2 unaff_DI;
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
  uint uStack_12;
  uint uStack_c;
  int iStack_a;
  uint16_t uStack_8;
  uint16_t uStack_6;
  
  bVar1 = *(byte *)(y * 0x12 + 7);
  if (bVar1 < 2) {
    uStack_12 = (uint)*(byte *)(y * 0x12 + 6);
    uVar3 = *(uint *)(y * 0x12);
    bVar1 = *(byte *)(y * 0x12 + 0xe);
    bVar2 = *(byte *)(y * 0x12 + 0x11);
    if (bVar2 < uStack_12) {
      uStack_12 = bVar2 + 1;
    }
    x_00 = in_stack_00000004 + -1;
    iStack_a = x + uStack_12 * -0x13 + 0x2a;
    uStack_c = uStack_12;
    while (uVar5 = csite1_12Seg, uVar4 = csite1_12Ofs, uStack_c = uStack_c - 1, -1 < (int)uStack_c)
    {
      y_00 = iStack_a + 0x13;
      type_00 = (uint8_t)rect;
      if ((bVar1 == 2) || (0x13 < uVar3)) {
        if (bVar1 < 2) {
          if (uStack_c == 0) {
            uVar6 = (uVar3 + GfxRndSeed2) % 0xe;
            gfx_01.seg = ((undefined2 *)&tmstrsSprites6Seg)[uVar6 * 2];
            gfx_01.ofs = ((undefined2 *)&tmstrsSprites6Ofs)[uVar6 * 2];
            ovr_blitGfxRect(gfx_01,in_stack_00000004 + 0xe,iStack_a + 0x22,(brect_t *)recordIndex,
                            type_00,true,1);
          }
          gfx_02.seg = uVar5;
          gfx_02.ofs = uVar4;
          ovr_blitGfxRect(gfx_02,x_00,y_00,(brect_t *)recordIndex,type_00,true,0);
          if ((uVar3 + uStack_c + GfxRndSeed2 + x_00 & 0x1f) < 0x11) {
            uVar6 = uVar3 + uStack_c + GfxRndSeed2 + x_00 & 0x1f;
            gfx_03.seg = ((undefined2 *)&tmstrsSprites5Seg)[uVar6 * 2];
            gfx_03.ofs = ((undefined2 *)&tmstrsSprites5Ofs)[uVar6 * 2];
            ovr_blitGfxRect(gfx_03,x_00 + ((int)((uint)*(byte *)((uVar3 + uStack_c + GfxRndSeed2 +
                                                                  x_00 >> 5) + uStack_c +
                                                                 GfxRndSeed2 & 0xff) * 0x25) >> 8) +
                                   3,iStack_a + 0x10,(brect_t *)recordIndex,type_00,true,0);
          }
          if ((((uVar3 + uStack_c) - GfxRndSeed2) - x_00 & 0xf) < 7) {
            uVar6 = ((uVar3 + uStack_c) - GfxRndSeed2) - x_00 & 0xf;
            gfx_04.seg = ((undefined2 *)&tmstrsSprites4Seg)[uVar6 * 2];
            gfx_04.ofs = ((undefined2 *)&tmstrsSprites4Ofs)[uVar6 * 2];
            ovr_blitGfxRect(gfx_04,x_00 + ((int)((uint)*(byte *)((((((uVar3 + uStack_c) -
                                                                    GfxRndSeed2) - x_00 >> 4) +
                                                                  uStack_c) - GfxRndSeed2) + 0xe &
                                                                0xff) * 0x25) >> 8) + 3,
                            iStack_a + 0x10,(brect_t *)recordIndex,type_00,true,0);
          }
          uVar6 = (uVar3 + 5) % 7;
          gfx_05.seg = ((undefined2 *)&tmstrsSprites3Seg)[uVar6 * 2];
          gfx_05.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[uVar6 * 2];
          ovr_blitGfxRect(gfx_05,in_stack_00000004 + 4,iStack_a + 0xd,(brect_t *)recordIndex,type_00
                          ,true,0);
          gfx_06.seg = ((undefined2 *)&tmstrsSprites3Seg)[(uVar3 % 7) * 2];
          gfx_06.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[(uVar3 % 7) * 2];
          ovr_blitGfxRect(gfx_06,in_stack_00000004 + 6,iStack_a + 0xd,(brect_t *)recordIndex,type_00
                          ,true,0);
          uVar6 = (uVar3 + 2) % 7;
          gfx_07.seg = ((undefined2 *)&tmstrsSprites3Seg)[uVar6 * 2];
          gfx_07.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[uVar6 * 2];
          ovr_blitGfxRect(gfx_07,in_stack_00000004 + 0x18,iStack_a + 0xd,(brect_t *)recordIndex,
                          type_00,true,0);
          uVar6 = uVar3 + 3 & 7;
          gfx_08.seg = ((undefined2 *)&tmstrsSprites2Seg)[uVar6 * 2];
          gfx_08.ofs = ((undefined2 *)&tmstrsSprites2Ofs)[uVar6 * 2];
          ovr_blitGfxRect(gfx_08,in_stack_00000004 + 0x22,iStack_a + 0xd,(brect_t *)recordIndex,
                          type_00,true,0);
          gfx_09.seg = ((undefined2 *)&tmstrsSprites2Seg)[(uVar3 & 7) * 2];
          gfx_09.ofs = ((undefined2 *)&tmstrsSprites2Ofs)[(uVar3 & 7) * 2];
          ovr_blitGfxRect(gfx_09,in_stack_00000004 + 0x1d,iStack_a + 0xd,(brect_t *)recordIndex,
                          type_00,true,0);
          gfx_10.seg = ((undefined2 *)&tmstrsSprites1Seg)[(uVar3 % 5) * 2];
          gfx_10.ofs = ((undefined2 *)&tmstrsSprites1Ofs)[(uVar3 % 5) * 2];
          ovr_blitGfxRect(gfx_10,in_stack_00000004 + 0x13,iStack_a + 0xd,(brect_t *)recordIndex,
                          type_00,true,0);
          gfx_11.seg = ((undefined2 *)&tmstrsSprites1Seg)[(uVar3 % 5) * 2];
          gfx_11.ofs = ((undefined2 *)&tmstrsSprites1Ofs)[(uVar3 % 5) * 2];
          ovr_blitGfxRect(gfx_11,in_stack_00000004 + 0x1f,iStack_a + 0xd,(brect_t *)recordIndex,
                          type_00,true,0);
          iStack_a = y_00;
        }
        else {
          if (uVar3 < 10) {
            uStack_6 = ((undefined2 *)&csite1Seg)[(uVar3 + 0xc) * 2];
            uStack_8 = ((undefined2 *)&csite1Ofs)[(uVar3 + 0xc) * 2];
          }
          else {
            uStack_6 = csite1_22Seg;
            uStack_8 = csite1_22Ofs;
          }
          gfx_00.seg = uStack_6;
          gfx_00.ofs = uStack_8;
          ovr_blitGfxRect(gfx_00,x_00,y_00,(brect_t *)recordIndex,type_00,true,0);
          iStack_a = y_00;
        }
      }
      else {
        if ((uStack_12 - 1 == uStack_c) && (uVar3 < 0xd)) {
          uStack_6 = ((undefined2 *)&csite1Seg)[uVar3 * 2];
          uStack_8 = ((undefined2 *)&csite1Ofs)[uVar3 * 2];
        }
        else {
          uStack_6 = csite1_12Seg;
          uStack_8 = csite1_12Ofs;
        }
        gfx.seg = uStack_6;
        gfx.ofs = uStack_8;
        ovr_blitGfxRect(gfx,x_00,y_00,(brect_t *)recordIndex,type_00,true,0);
        iStack_a = y_00;
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

uint __cdecl16far ovc23_findRecordAt(int x,int y,...)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (GRecordCount <= uVar2) {
      return 0xffff;
    }
    if (((*(int *)(uVar2 * 0x12 + 4) == y) &&
        (iVar1 = *(int *)(uVar2 * 0x12 + 2),
        x <= (int)(iVar1 + (uint)*(byte *)(uVar2 * 0x12 + 7) + -1))) && (iVar1 <= x)) break;
    uVar2 = uVar2 + 1;
  }
  return uVar2;
}



/* 55fe:29a2 */

/* Removes an unreachable construction record and reports "Construction abandoned." on the cursor
   cell. */

void __cdecl16far ovc23_abandonConstruction(int recordIndex)

{
  byte *pbVar1;
  byte bVar2;
  uint y;
  undefined4 uVar3;
  bool bVar4;
  uint x;
  undefined2 uVar5;
  uint16_t unaff_SI;
  uint unaff_DI;
  uint uVar6;
  uint uVar7;
  agnt_t *agnt;
  byte bVar8;
  
  bVar2 = *(byte *)(recordIndex * 0x12 + 9);
  uVar7 = (uint)bVar2;
  uVar3 = *(undefined4 *)((uint)bVar2 << 2);
  if (*(char *)((int)uVar3 + 0x3f) == '\0') {
    x = ovr_alignUp4(*(int *)(recordIndex * 0x12 + 2));
    y = *(uint *)(recordIndex * 0x12 + 4);
    uVar3 = *(undefined4 *)((uVar7 & 0xff) << 2);
    bVar2 = *(byte *)((int)uVar3 + 0x3f);
    uVar3 = *(undefined4 *)((uVar7 & 0xff) << 2);
    uVar6 = 0;
    agnt = (agnt_t *)(uVar7 & 0xff);
    while( true ) {
      bVar8 = (byte)((uint)agnt >> 8);
      if (3 < bVar8) break;
      uVar6 = uVar6 | ((short (*) [60] [148])GMapFlags)[-1][y + 0x3b][x + bVar8 + 0x92] & 0x3000U;
      agnt = (agnt_t *)CONCAT11(bVar8 + 1,(char)agnt);
    }
    if ((((*(byte *)(recordIndex * 0x12 + 0xd) & 3) != 1) ||
        (uVar6 != 0x1000 << ((*(byte *)((int)uVar3 + 0x3f) ^ 1) & 0x1f))) ||
       (uVar3 = *(undefined4 *)(((uint)agnt & 0xff) << 2),
       bVar4 = ovr_ovc24_textArena(x,y,*(char *)((int)uVar3 + 0x3f)), bVar4)) {
      if (((*(byte *)(recordIndex * 0x12 + 0xd) & 1) == 0) &&
         ((0x1000 << (bVar2 & 0x1f) & uVar6) != 0)) {
        pbVar1 = (byte *)(recordIndex * 0x12 + 0xd);
        *pbVar1 = *pbVar1 | 1;
      }
    }
    else {
      uVar5 = ovc23_isCursorAt(x,y);
      if ((char)uVar5 != '\0') {
        ovr_say((char *)"Construction abandoned.",0x2410);
      }
      if (recordIndex + 1U < GRecordCount) {
        _fmemmove((char *)CONCAT22(0x21f2,(char *)(recordIndex * 0x12)),
                  (char *)CONCAT22(0x21f2,(char *)(recordIndex * 0x12 + 0x12)),
                  ((GRecordCount - recordIndex) + -1) * 0x12);
      }
      GRecordCount = GRecordCount - 1;
      ovc23_textAdlibNone(unaff_DI,unaff_SI,agnt);
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

uint __cdecl16far ovc23_compute1(int x,int y,byte bldType,uint8_t unitType,...)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  cVar1 = *(char *)((uint)bldType * 0x27 + 0x11e);
  if (cVar1 == '\0') {
    uVar4 = 0;
  }
  else if (cVar1 == '\x01') {
    bVar2 = ovr_ovc45_getUnitType(x,y + -1);
    if (*(char *)((uint)bVar2 * 0x27 + 0x11e) == '\x02') {
      ovc23_placeBuilding(x,y,bldType + 2,unitType);
    }
    else {
      ovc23_placeBuilding(x,y,bldType,unitType);
    }
    bVar2 = ovr_ovc45_getUnitType(x + -1,y);
    iVar3 = (uint)bVar2 * 0x27;
    if (*(char *)(iVar3 + 0x11e) == '\x02') {
      iVar3 = x + -1;
      ovc23_placeBuilding(iVar3,y,bVar2 + 1,unitType);
    }
    uVar4 = CONCAT11((char)((uint)iVar3 >> 8),1);
  }
  else if (cVar1 == '\x02') {
    bVar2 = ovr_ovc45_getUnitType(x + 1,y);
    if (*(char *)((uint)bVar2 * 0x27 + 0x11e) == '\x01') {
      ovc23_placeBuilding(x,y,bldType + 1,unitType);
    }
    else {
      ovc23_placeBuilding(x,y,bldType,unitType);
    }
    bVar2 = ovr_ovc45_getUnitType(x,y + 1);
    iVar3 = (uint)bVar2 * 0x27;
    if (*(char *)(iVar3 + 0x11e) == '\x01') {
      iVar3 = y + 1;
      ovc23_placeBuilding(x,iVar3,bVar2 + 2,unitType);
    }
    uVar4 = CONCAT11((char)((uint)iVar3 >> 8),1);
  }
  else if (cVar1 == '!') {
    bVar2 = ovr_ovc45_getUnitType(x + -1,y);
    uVar4 = (uint)bVar2 * 0x27;
    if (*(char *)(uVar4 + 0x11e) == '\x02') {
      uVar4 = x - 1;
      ovc23_placeBuilding(uVar4,y,bVar2 + 1,unitType);
    }
    uVar4 = uVar4 & 0xff00;
  }
  else if (cVar1 == '\"') {
    bVar2 = ovr_ovc45_getUnitType(x,y + 1);
    uVar4 = (uint)bVar2 * 0x27;
    if (*(char *)(uVar4 + 0x11e) == '\x01') {
      uVar4 = y + 1;
      ovc23_placeBuilding(x,uVar4,bVar2 + 2,unitType);
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

int __cdecl16far ovc23_findClearColumn(int x,int y,...)

{
  uint uVar1;
  int iVar2;
  
  if (((*(short (*) [60] [148])GMapFlags)[y + 1][x] & 3U) != 0) {
    uVar1 = ovr_alignUp4(x);
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

int __cdecl16far ovc23_compute2(int x,uint16_t y,...)

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
  undefined2 uVar3;
  char *unaff_SS;
  uint16_t uVar4;
  uint16_t uVar5;
  uint8_t text2;
  uint8_t text;
  int iStack_6;
  byte bStack_3;
  
  puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x);
  *puVar1 = *puVar1 | 3;
  entityIndex = EntityCount;
  while (entityIndex = entityIndex - 1, -1 < (int)entityIndex) {
    uVar3 = (undefined2)((ulong)Entities >> 0x10);
    if ((*(uint16_t *)((int)Entities + entityIndex * 0x37) == x) &&
       (*(uint16_t *)((int)Entities + entityIndex * 0x37 + 2) == y)) {
      iStack_6 = ovc23_findClearColumn(x,y);
      uVar3 = (undefined2)((ulong)Entities >> 0x10);
      if (iStack_6 < 0) {
        bStack_3 = *(byte *)((int)Entities + entityIndex * 0x37 + 0xd);
        if (*(char *)((int)(char **)GMenuStrings + (uint)bStack_3 * 0x95 + 0x1f) == '\0') {
          uVar3 = 0xa000;
          dst = 0x195d;
          uVar4 = x;
          uVar5 = y;
          pcVar2 = ovr_ovc15_capitalize((char *)&text2);
          pcVar2 = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x5665,unaff_SS),
                                 (char *)CONCAT22(pcVar2,(char *)0x26510),dst,uVar4,uVar5,
                                 uVar3);
          ovr_uiNotify(pcVar2,dst);
        }
        ovr_ovc15_removeEntity(entityIndex);
      }
      else {
        *(int *)((int)Entities + entityIndex * 0x37) = iStack_6;
      }
    }
  }
  return;
}



/* 55fe:2f90 */

/* [R6] touches GRecordCount */

undefined2 __cdecl16far ovc23_usesGRecordCount3(byte amount,byte partyIndex,int recordIndex)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint16_t unaff_DI;
  uint unaff_SS;
  undefined1 uStack_8;
  uint8_t loopIndex;
  undefined1 uStack_5;
  undefined1 uStack_4;
  
  uVar3 = (uint)amount;
  uStack_8 = amount;
  _fmemset((void *)(ulong)unaff_SS,3,unaff_DI);
  for (uVar5 = 0; uVar5 < GRecordCount; uVar5 = uVar5 + 1) {
    if (*(byte *)(uVar5 * 0x12 + 9) == partyIndex) {
      if ((*(byte *)(uVar5 * 0x12 + 0xd) & 4) != 0) {
        loopIndex = loopIndex + 0x1;
      }
      if ((*(byte *)(uVar5 * 0x12 + 0xd) & 8) != 0) {
        uStack_5 = uStack_5 + 1;
      }
      if ((*(byte *)(uVar5 * 0x12 + 0xd) & 0x10) != 0) {
        uStack_4 = uStack_4 + 1;
      }
    }
  }
  if (uStack_4 < *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x9c)) {
    uStack_8 = (byte)((ulong)((long)(int)uVar3 * 7) / 10);
    iVar4 = recordIndex * 0x12;
    *(byte *)(iVar4 + 0xd) = *(byte *)(iVar4 + 0xd) | 0x10;
  }
  else if (uStack_5 < *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x9b)) {
    uStack_8 = (byte)((uVar3 << 3) / 100);
    iVar4 = recordIndex * 0x12;
    *(byte *)(iVar4 + 0xd) = *(byte *)(iVar4 + 0xd) | 8;
  }
  else {
    uVar2 = *(undefined4 *)((uint)partyIndex << 2);
    bVar1 = *(byte *)((int)uVar2 + 0x9a);
    iVar4 = CONCAT11((char)(((uint)partyIndex << 2) >> 8),bVar1);
    if (loopIndex < bVar1) {
      uStack_8 = (byte)((ulong)((long)(int)uVar3 * 9) / 10);
      iVar4 = recordIndex * 0x12;
      *(byte *)(iVar4 + 0xd) = *(byte *)(iVar4 + 0xd) | 4;
    }
  }
  return CONCAT11((char)((uint)iVar4 >> 8),uStack_8);
}



/* 55fe:3450 */

/* rounds a byte offset up to the next multiple of four */

uint __cdecl16far alignUp4(int value,...)

{
  return value + 2U & 0xfffc;
}


