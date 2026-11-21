/*
 * ovc23_bldrec.c - recovered from STRONG.EXE
 * memory block: OVC23_bldrec.c
 * range: 55fe:0000 - 55fe:345d
 * functions: 26
 */
#include "recovered.h"


/* 55fe:0000 */

/* WARNING: Instruction at (ram,0x0005c484) overlaps instruction at (ram,0x0005c483)
    */
/* [R2] string "               4. Adlib       5. None):" */

byte * __cdecl16far ovc23_textAdlibNone(uint partyIndex,uint16_t outFlag,agnt_t *agnt,...)

{
  uint *puVar1;
  int *piVar2;
  uint8_t *puVar3;
  char cVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  ulong uVar8;
  ulong uVar9;
  byte bVar10;
  char cVar11;
  byte bVar12;
  int iVar13;
  undefined4 *puVar14;
  byte *pbVar15;
  uint uVar16;
  uint16_t uVar17;
  uint uVar18;
  uint16_t uVar19;
  char in_CL;
  uint in_DX;
  uint uVar20;
  uint uVar21;
  entity_t *peVar22;
  unit_t *puVar23;
  int iVar24;
  int iVar25;
  undefined2 unaff_DI;
  undefined2 uVar26;
  undefined2 unaff_SS;
  undefined1 uStack0004;
  undefined1 auStackY_68 [58];
  byte bStackY_2e;
  byte bStackY_2d;
  undefined2 uStackY_2c;
  undefined2 uStackY_2a;
  undefined1 *puStackY_28;
  undefined1 uVar27;
  undefined1 uVar28;
  undefined1 uVar29;
  undefined1 uVar30;
  undefined1 uVar31;
  undefined1 uVar32;
  undefined1 uVar33;
  undefined1 uVar34;
  uint uStack_10;
  uint uStack_c;
  uint16_t uStack_a;
  undefined2 uStack_8;
  undefined4 uStack_6;
  
  cVar11 = (char)unaff_DI;
  uVar31 = (undefined1)((uint)unaff_DI >> 8);
  uStack_10 = 0;
  uStack_a = ovr_alignUp4();
  for (iVar24 = 0; iVar24 < 4; iVar24 = iVar24 + 1) {
    in_DX = 0x2410;
    uStack_10 = uStack_10 |
                ((short (*) [60] [148])GMapFlags)[-1][GfxRndSeed2 + 0x3b][uStack_a + iVar24 + 0x92]
                & 0x3000U;
  }
  cursorRecordFound = '\0';
  _fmemset((void *)0xff2410,8,CONCAT11(uVar31,cVar11));
  uVar29 = 0;
  uVar30 = 0x10;
  uVar27 = 0x5e;
  uVar28 = 0x60;
  _fmemset((void *)0x2410,4,CONCAT11(uVar31,cVar11));
  for (uStack_c = 0; uStack_c < GRecordCount; uStack_c = uStack_c + 1) {
    in_DX = 0x2410;
    if ((*(int *)(uStack_c * 0x12 + 4) == GfxRndSeed2) &&
       (in_DX = 0x21f2, (*(byte *)(uStack_c * 0x12 + 0xd) & 1) != 0)) {
      bVar10 = *(byte *)(uStack_c * 0x12 + 7);
      uStack_6 = (byte *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),bVar10);
      iVar24 = *(int *)(uStack_c * 0x12 + 2) - (GfxRndSeed + -2);
      in_DX = (iVar24 + (uint)bVar10) - 1;
      if ((0 < (int)(iVar24 + (uint)bVar10)) && (iVar24 < 4)) {
        if (20000 < *(uint *)(uStack_c * 0x12)) {
          *(undefined2 *)(uStack_c * 0x12) = 3;
        }
        in_DX = 0x21f2;
        for (iVar25 = 0; iVar25 < (int)(uint)bVar10; iVar25 = iVar25 + 1) {
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
    return (byte *)((char *)"puppetmaker" + 3);
  }
  uStack_6 = (byte *)((ulong)uStack_6 & 0xffffff);
  iVar24 = 0;
  (*(uint16_t *)((uint8_t *)&(uStack_6))) = (byte *)CONCAT11(0xff,(char)uStack_6);
  uStack_8 = (byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) << 8);
  for (iVar25 = -2; iVar25 < 2; iVar25 = iVar25 + 1) {
    uVar16 = ovr_ovc45_getUnitIndex();
    bVar12 = ovr_ovc45_getUnitType();
    uVar8 = (ulong)uStack_6;
    uStack_8 = (byte *)CONCAT11(bVar12,(byte)uStack_8);
    uVar26 = (undefined2)((ulong)GUnits >> 0x10);
    puVar23 = (unit_t *)GUnits;
    bVar10 = puVar23[uVar16].unitType;
    (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(bVar10,(byte *)uStack_6);
    uStack_6 = (byte *)(ulong)(uint3)uStack_6;
    uVar9 = (ulong)uStack_6;
    uStack_6 = (byte *)uVar9;
    if (((0xf7 < uVar16) && (bVar10 != 0xff)) &&
       ((*(char *)((int)*(undefined4 *)((uint)bVar10 << 2) + 0x3f) == '\0' &&
        ((*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) = SUB41(uVar8,1), bVar5 = puVar23[uVar16].level <= (*(uint8_t *)((uint8_t *)&(uStack_6) + 1)), bVar5))))
    {
      (*(uint8_t *)((uint8_t *)&(uStack_6))) = (char)uVar8;
      (*(uint16_t *)((uint8_t *)&(uStack_6))) = (byte *)CONCAT11(puVar23[uVar16].level,(char)uStack_6);
      uStack_6 = (byte *)(ulong)CONCAT12(bVar10,(byte *)uStack_6);
    }
    uVar8 = (ulong)uStack_6;
    if ((*(char *)((int)*(undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 2)) << 2) + 0x3f) == '\0') &&
       (puVar23[uVar16].unitType != 0xff)) {
      iVar24 = iVar24 + (uint)*(byte *)((uint)bVar12 * 0x27 + 0x11b);
    }
    cVar4 = *(char *)((uint)bVar12 * 0x27 + 0x132);
    uStack_6 = (byte *)CONCAT13(cVar4,(uint3)uStack_6);
    in_DX = 0x2410;
    if (((5 < puVar23[uVar16].level) && (cVar4 == -0x7a)) &&
       ((*(uint8_t *)((uint8_t *)&(uStack_8))) = (byte)uStack_8 + 1, uStack_8 = (byte *)CONCAT11(bVar12,(byte)uStack_8),
       (byte)uStack_8 < 2)) {
      uStack_6 = (byte *)uVar8;
    }
    if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) != 0x0) {
      if (CurSfxType3 == 0xff) {
        in_DX = CONCAT11(0x24,(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)));
        CurSfxType3 = (*(uint8_t *)((uint8_t *)&(uStack_6) + 3));
      }
      else {
        uVar17 = ovr_randBelow();
        if ((uVar17 & 0xff) == 0) {
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
    return (byte *)((char *)"puppetmaker" + 3);
  }
  uVar31 = 0xca;
  uVar32 = 99;
  uVar18 = ovr_constr_usesGMapFlags2();
  uVar16 = uStack0004;
  pbVar15 = (byte *)(uVar18 & 0xff);
  if ((byte *)__C0_ASM_CopyRight < pbVar15) {
    return pbVar15;
  }
  switch(pbVar15) {
  case (byte *)0x0:
    *(char *)((int)pbVar15 * 2) = *(char *)((int)pbVar15 * 2) + (char)(in_DX >> 8);
    uStack_c = (uint)(byte)((byte)uVar18 & (byte)*(undefined2 *)(&stack0x02c2 + iVar24));
    uVar17 = ovr_randBelow();
    uVar19 = ovr_randBelow();
    uStack_6 = (byte *)(CONCAT22(uVar19,(byte *)uStack_6) & 0xffffff);
    uVar33 = 0x83;
    uVar34 = 0x9a;
    uVar19 = ovr_randBelow();
    uStack_6 = (byte *)(CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),uVar19) & 0xffff00ff);
    if ((uVar17 & 0xff) < uStack_c) {
      uVar16 = (uint)(*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) / (uint)((byte *)uStack_6 + 1);
      uStack_10 = 1;
    }
    else {
      if ((byte *)uStack_6 <= (*(uint16_t *)((uint8_t *)&(uStack_6) + 2))) {
        return (*(uint16_t *)((uint8_t *)&(uStack_6) + 2));
      }
      uVar16 = (uint)(byte *)uStack_6 / (uint)((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) + 1);
      uStack_10 = 0;
    }
    pbVar15 = (byte *)(uVar16 + 1);
    uStack_8 = pbVar15;
    if ((byte *)((int)(undefined4 *)&_DATA + 2) < pbVar15) {
      uStack_8 = (byte *)((int)(undefined4 *)&_DATA + 2);
    }
    bStackY_2d = 0xff;
    bStackY_2e = 0;
    iVar25 = -1;
    uStack_a = -1;
    iVar24 = CONCAT11(uVar34,uVar33);
    break;
  case (byte *)0x1:
    TextBlitX = in_DX - (int)pbVar15;
    ovr_blitLabel();
    iVar25 = ovr_font_textWidth();
    uVar17 = 0xd4 - iVar25;
    TextBlitX = uVar17;
    ovr_blitLabel();
    for (iVar25 = 0; TextBlitY = TextBlitY + 0xc, iVar25 < (int)(uStack_c >> 8); iVar25 = iVar25 + 1
        ) {
      TextBlitX = 0x11;
      if ((iVar25 < 5) || ((char)uStack_c == '\0')) {
        ovr_blitLabel();
      }
      else {
        ovr_blitLabel();
      }
      func_0x0005f303();
      ovr_stsprintf();
      iVar13 = ovr_font_textWidth();
      TextBlitX = 0x89 - iVar13;
      ovr_blitLabel();
      ovr_stsprintf();
      iVar13 = ovr_font_textWidth();
      uVar17 = 0xd4 - iVar13;
      TextBlitX = uVar17;
      ovr_blitLabel();
    }
    CurSfxType3 = 0x3c;
    uVar26 = ovr_ovc28_usesUiInputText();
    cVar11 = (char)uVar26;
    keyboardInputMode = 0;
    if (((cVar11 != '\0') && (cVar11 != '\x01')) && (cVar11 != -2)) {
      (&stack0xbac4)[iVar24] = (&stack0xbac4)[iVar24] + in_CL;
      iVar24 = 0x2410;
      do {
        iVar13 = iVar24 * uVar17;
        iVar24 = iVar25;
        if (*(byte *)(iVar25 * 0x34 + 0x22) < *(byte *)(iVar13 + 0x21)) {
          *(undefined1 *)(iVar25 * 0x34 + 0x21) = *(undefined1 *)(iVar25 * 0x34 + 0x22);
        }
        do {
          iVar24 = iVar24 + 1;
          if ((int)(uint)AgntCount <= iVar24) {
            iVar24 = ovr_audio_panFromX();
            uVar31 = (undefined1)((uint)iVar24 >> 8);
            ovr_play_sfxU();
            return (byte *)CONCAT11(uVar31,1);
          }
        } while (*(int *)(iVar24 * 0x34 + 0x1b) != *(int *)(outFlag + 0x1b));
        uVar26 = (undefined2)((ulong)uStack_6 >> 0x10);
        if (*(byte *)((int)uStack_6 + 0x32) < *(byte *)(iVar24 * 0x34 + 0x22)) {
          *(undefined1 *)(iVar24 * 0x34 + 0x22) = *(undefined1 *)((int)uStack_6 + 0x32);
        }
        uVar17 = 0x34;
        iVar25 = iVar24;
      } while( true );
    }
    if (cVar11 == -2) {
      Cancelled = 1;
    }
    return (byte *)((char *)"puppetmaker" + 3);
  case (byte *)0x2:
    pbVar15 = (byte *)(uStack0004 * 0x37);
    if (*(char *)((int)&((entity_t *)Entities)[uStack0004].base.entity + 3) != -1) {
      bVar10 = ovr_agnt_compute10();
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = (uint3)bVar10 << 8;
      uVar31 = *(undefined1 *)((int)&((entity_t *)Entities)[uVar16].base.entity + 3);
      pbVar15 = (byte *)CONCAT11((char)(uVar16 * 0x37 >> 8),uVar31);
      uStack_6 = (byte *)CONCAT13(uVar31,(uint3)uStack_6);
      while (cVar11 = (char)uStack_6, (char)uStack_6 < '\x04') {
        pbVar15 = (byte *)((char)uStack_6 * 2);
        if (*(int *)(pbVar15 + (int)*(undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) << 2) + 0x76) != 0) {
          pbVar15 = (byte *)(int)(char)(*(uint8_t *)((uint8_t *)&(uStack_6) + 1));
          if ((int)pbVar15 < (char)uStack_6 + 1) {
            (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = (char)uStack_6;
            piVar2 = (int *)((int)*(undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) << 2) + (char)uStack_6 * 2 +
                            0x76);
            *piVar2 = *piVar2 + -1;
            uVar26 = (undefined2)((ulong)Entities >> 0x10);
            peVar22 = (entity_t *)Entities;
            peVar22[uVar16].dir =
                 peVar22[uVar16].dir + (char)(((ulong)peVar22[uVar16].dir / 6) % 6) * -6;
            bVar10 = ((entity_t *)Entities)[uVar16].base.gindex;
            (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(bVar10,(byte *)uStack_6);
            if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar10 * 0x95) == '\x03') &&
               ('\x01' < cVar11)) {
              (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = '\x01';
            }
            if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar10 * 0x95) == '\x01') &&
               ('\x02' < (char)(*(uint8_t *)((uint8_t *)&(uStack_8) + 1)))) {
              (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = '\x02';
            }
            cVar11 = ovc22_compute3();
            uVar26 = (undefined2)((ulong)Entities >> 0x10);
            bVar10 = ((entity_t *)Entities)[uVar16].dir + cVar11 * '\x06';
            ((entity_t *)Entities)[uVar16].dir = bVar10;
            return (byte *)CONCAT11((char)(uVar16 * 0x37 >> 8),bVar10);
          }
        }
        uStack_6 = (byte *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),(char)uStack_6 + '\x01');
      }
    }
    return pbVar15;
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
        iVar25 = ovc25_compute1();
        uStack_6 = (byte *)CONCAT22(iVar25,(byte *)uStack_6);
        if ((int)(uint)PlayerCount < iVar25) {
          uVar17 = ovr_randBelow();
          iVar25 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) + -0x14 + (uVar17 & 0xff);
          (*(uint16_t *)((uint8_t *)&(uStack_6))) = (byte *)iVar25;
          if (iVar25 < 4) {
            (*(uint16_t *)((uint8_t *)&(uStack_6))) = (byte *)0x4;
          }
          if (0x8c < (int)(byte *)uStack_6) {
            uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),0x8b);
          }
          uVar17 = ovr_randBelow();
          uStack_8 = (byte *)(*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) + -10 +
                             (uVar17 & 0xff));
          if ((int)uStack_8 < 1) {
            uStack_8 = (byte *)0x1;
          }
          if (0x3a < (int)uStack_8) {
            uStack_8 = (byte *)0x3a;
          }
          ovc25_usesAlignUp44();
        }
      }
      while( true ) {
        while( true ) {
          do {
            uStack_a = uStack_a + 1;
            pbVar15 = (byte *)(uint)GLeaderCount;
            if ((int)pbVar15 <= (int)uStack_a) {
              ovc25_clearEntityFlags();
              return pbVar15;
            }
          } while ((*(char *)((int)*(undefined4 *)(uStack_a * 4) + 0x40) == '\0') ||
                  (*(char *)((int)*(undefined4 *)(uStack_a * 4) + 0x3d) == '\0'));
          ovc25_intelAttackingNotice((byte)uStack_a);
          if (*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x4b) == -1) {
            uVar16 = 0xffff;
          }
          else {
            iVar24 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x4b);
            uVar26 = (undefined2)((ulong)Entities >> 0x10);
            uVar16 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                     (((entity_t *)Entities + iVar24)->base).x;
            uVar20 = (int)uVar16 >> 0xf;
            uVar18 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) -
                     ((entity_t *)Entities)[iVar24].base.y;
            uVar21 = (int)uVar18 >> 0xf;
            uVar16 = (int)((uVar16 ^ uVar20) - uVar20) / 2 + ((uVar18 ^ uVar21) - uVar21);
          }
          if ((*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x43) == 0) || (9 < uVar16)) break;
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
        bVar10 = *(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x49);
        if (0xe < *(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x47)) {
          uVar6 = *(undefined4 *)((uint)bVar10 << 2);
          uVar7 = *(undefined4 *)((uint)bVar10 << 2);
          ovc25_usesAlignUp42((byte)uStack_a,10,*(uint16_t *)((int)uVar7 + 0x39),
                              *(uint16_t *)((int)uVar6 + 0x3b),
                              *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                              *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b));
          if (*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) != '\x02') {
            ovr_alignUp4();
            puStackY_28 = auStackY_68;
            uStackY_2a = 0x2379;
            uStackY_2c = 0xc5d4;
            ovr_stsprintf();
            ovr_uiNotify();
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
      uVar6 = *(undefined4 *)((uStack0004 & 0xff) << 2);
      uStack_a = *(uint16_t *)((int)uVar6 + 0x39);
      uVar6 = *(undefined4 *)((uStack0004 & 0xff) << 2);
      uStack_c = *(uint16_t *)((int)uVar6 + 0x3b);
    }
    uVar6 = *(undefined4 *)((uStack0004 & 0xff) << 2);
    uVar26 = (undefined2)((ulong)uVar6 >> 0x10);
    iVar25 = (int)uVar6;
    iVar24 = *(int *)(iVar25 + 0x58);
    if ((iVar24 < 1) && ((iVar24 < 0 || (*(uint *)(iVar25 + 0x56) < 10)))) {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(byte *)uStack_6);
    }
    else {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((byte *)uStack_6);
    }
    uVar6 = *(undefined4 *)((uStack0004 & 0xff) << 2);
    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)*(byte *)((int)uVar6 + 0x3e) * 0x95) &
        0x80) == 0) {
      uStack_6 = (byte *)(ulong)(uint3)uStack_6;
    }
    else {
      uStack_6 = (byte *)CONCAT13(3,(uint3)uStack_6);
    }
    uVar6 = *(undefined4 *)((uStack0004 & 0xff) << 2);
    if ((*(byte *)((int)uVar6 + 0x5d) & 2) != 0) {
      uStack_6 = (byte *)((ulong)uStack_6 | 0x1000000);
    }
    puVar14 = (undefined4 *)((uStack0004 & 0xff) << 2);
    uVar6 = *puVar14;
    if ((*(byte *)((int)uVar6 + 0x5d) & 4) != 0) {
      uStack_6 = (byte *)((ulong)uStack_6 | 0x2000000);
    }
    uVar16 = ovc22_searchCellsAround
                       ((uint *)CONCAT13((char)((uint)&uStack_c >> 8),
                                         CONCAT12((char)&uStack_c,unaff_SS)),
                        (uint *)CONCAT13((char)((uint)puVar14 >> 8),CONCAT12(uStack0004,unaff_SS)),
                        (*(uint8_t *)((uint8_t *)&(uStack_6) + 3)),(*(uint8_t *)((uint8_t *)&(uStack_6) + 2)),cVar11);
    pbVar15 = (byte *)(uVar16 & 0xff);
    if (pbVar15 != (byte *)0x0) {
      if (pbVar15 != (byte *)((int)(undefined4 *)&_DATA + 1U)) {
        return pbVar15;
      }
      uVar16 = ovc22_usesRandBelow((byte)uStack0004,uStack_a,uStack_c);
      if (uVar16 == 0) {
        uVar6 = *(undefined4 *)((uStack0004 & 0xff) << 2);
        uStack_a = *(uint16_t *)((int)uVar6 + 0x39);
        uVar6 = *(undefined4 *)((uStack0004 & 0xff) << 2);
        uStack_c = *(uint16_t *)((int)uVar6 + 0x3b);
      }
      else {
        if ((*(uint *)(uVar16 * 0x27 + 0x121) & 0x60) == 0) {
          uVar6 = *(undefined4 *)((uStack0004 & 0xff) << 2);
          uVar26 = (undefined2)((ulong)uVar6 >> 0x10);
          iVar25 = (int)uVar6;
          iVar24 = *(int *)(iVar25 + 0x58);
          if ((iVar24 < 0) ||
             ((iVar24 == 0 && (*(uint *)(iVar25 + 0x56) < *(uint *)(uVar16 * 0x27 + 0x125))))) {
            uVar6 = *(undefined4 *)((uStack0004 & 0xff) << 2);
            uVar26 = (undefined2)((ulong)uVar6 >> 0x10);
            iVar24 = (int)uVar6;
            *(undefined2 *)(iVar24 + 0x58) = 0;
            *(undefined2 *)(iVar24 + 0x56) = 0;
          }
          else {
            uVar18 = *(uint *)(uVar16 * 0x27 + 0x125);
            uVar6 = *(undefined4 *)((uStack0004 & 0xff) << 2);
            uVar26 = (undefined2)((ulong)uVar6 >> 0x10);
            iVar24 = (int)uVar6;
            puVar1 = (uint *)(iVar24 + 0x56);
            uVar16 = *puVar1;
            *puVar1 = *puVar1 - uVar18;
            piVar2 = (int *)(iVar24 + 0x58);
            *piVar2 = *piVar2 - (uint)(uVar16 < uVar18);
          }
        }
        ovr_createConstructionRecordFar();
      }
    }
    uVar6 = *(undefined4 *)((uStack0004 & 0xff) << 2);
    if (*(char *)((int)uVar6 + 0x3f) == '\0') {
      uVar6 = *(undefined4 *)((uStack0004 & 0xff) << 2);
      uVar7 = *(undefined4 *)((uStack0004 & 0xff) << 2);
      if (*(uint *)((int)uVar6 + 0x5b) < *(uint *)((int)uVar7 + 0x4d)) {
        pbVar15 = (byte *)ovr_ovc18_textTypeLen();
      }
      else {
        pbVar15 = (byte *)ovr_ovc18_textTypeLen();
      }
    }
    else {
      pbVar15 = (byte *)ovr_ovc18_textTypeLen();
    }
    return pbVar15;
  }
  do {
    if (CONCAT11(uVar32,uVar31) < iVar24) {
      if (uStack_a != -1) {
        if (iVar25 == -1) {
          ovr_attact_usesRandBelow();
          ovr_attact_usesEntities();
          bVar10 = ((entity_t *)Entities)[uStack_a].base.gindex;
          pbVar15 = (byte *)(uint)*(byte *)((int)(char **)GMenuStrings + (uint)bVar10 * 0x95 + 0x1f)
          ;
          if (pbVar15 == (byte *)0x0) {
            uVar16 = alignUp4();
            uVar26 = *(undefined2 *)((int)&worldMenuLabels[0].seg + 1 + (uint)bVar10 * 0x95);
            pbVar15 = (byte *)ovr_fmVsprintf((char *)CONCAT13((char)((uint)uVar26 >> 8),
                                                              CONCAT12((char)uVar26,0x2410)),
                                             (char *)CONCAT13((char)(uVar16 >> 8),
                                                              CONCAT12((char)uVar16,
                                                                       *(undefined2 *)
                                                                        ((int)&worldMenuLabels[1].
                                                                               ofs + 1 +
                                                                        (uint)bVar10 * 0x95))));
            ovr_uiNotify();
          }
        }
        else {
          if ((byte *)(uint)((entity_t *)Entities)[iVar25].base.animFrame <= uStack_8) {
            uStack_8 = (byte *)(uint)((entity_t *)Entities)[iVar25].base.animFrame;
          }
          ((entity_t *)Entities)[iVar25].base.animFrame =
               ((entity_t *)Entities)[iVar25].base.animFrame - (byte)uStack_8;
          ovr_ovc41_compute4();
          ovr_ovc25_attackingNotice();
          pbVar15 = (byte *)(iVar25 * 0x37);
          if (((entity_t *)Entities)[iVar25].base.animFrame != 0x0) {
            ovc24_usesLDIV_at_(iVar25);
            uVar26 = (undefined2)((ulong)Entities >> 0x10);
            if ((((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                            (uint)((entity_t *)Entities)[uStack_a].base.gindex * 0x95) & 4) != 0) &&
                ((*(uint *)((int)&((entity_t *)Entities)[iVar25].base.frames + 1) & 1) == 0)) &&
               (uVar16 = ovr_ovc27_rollToHitAgent(), (uVar16 & 0xff) == 0)) {
              puVar1 = (uint *)((int)&((entity_t *)Entities)[iVar25].base.frames + 1);
              *puVar1 = *puVar1 | 1;
              uVar16 = alignUp4();
              iVar24 = (uint)((entity_t *)Entities)[iVar25].base.gindex * 0x95;
              uVar26 = *(undefined2 *)((int)&worldMenuLabels[0].seg + 1 + iVar24);
              ovr_fmVsprintf((char *)CONCAT13((char)((uint)uVar26 >> 8),
                                              CONCAT12((char)uVar26,0x2410)),
                             (char *)CONCAT13((char)(uVar16 >> 8),
                                              CONCAT12((char)uVar16,
                                                       *(undefined2 *)
                                                        ((int)&worldMenuLabels[1].ofs + 1 + iVar24))
                                             ));
              ovr_uiNotify();
            }
            pbVar15 = (byte *)((uint)((entity_t *)Entities)[uStack_a].base.gindex * 0x95);
            if ((*(uint *)(pbVar15 + 0x2714) & 0xc00) != 0) {
              uVar16 = ovr_ovc27_rollToHitAgent();
              pbVar15 = (byte *)(uVar16 & 0xff);
              if (pbVar15 == (byte *)0x0) {
                uVar26 = ovr_ovc27_compute3();
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
                uVar16 = alignUp4();
                iVar24 = (uint)((entity_t *)Entities)[iVar25].base.gindex * 0x95;
                uVar26 = *(undefined2 *)((int)&worldMenuLabels[0].seg + 1 + iVar24);
                pbVar15 = (byte *)ovr_fmVsprintf((char *)CONCAT13((char)((uint)uVar26 >> 8),
                                                                  CONCAT12((char)uVar26,0x2410)),
                                                 (char *)CONCAT13((char)(uVar16 >> 8),
                                                                  CONCAT12((char)uVar16,
                                                                           *(undefined2 *)
                                                                            ((int)&worldMenuLabels
                                                                                   [1].ofs + 1 +
                                                                            iVar24))));
                ovr_uiNotify();
              }
            }
          }
        }
      }
      return pbVar15;
    }
    pbVar15 = (byte *)((entity_t *)Entities)[iVar24].base.y;
    if ((pbVar15 != (byte *)CONCAT11(uVar28,uVar27)) ||
       (pbVar15 = (byte *)alignUp4(), pbVar15 != (byte *)CONCAT11(uVar30,uVar29)))
    goto L_OVC24_5943_026e_08A7;
    uVar26 = (undefined2)((ulong)Entities >> 0x10);
    peVar22 = (entity_t *)Entities;
    if (*(char *)((int)(char **)GMenuStrings + (uint)peVar22[iVar24].base.gindex * 0x95 + 0x1f) ==
        (char)uStack_10) {
      if (peVar22[iVar24].base.level < bStackY_2d) {
L_OVC24_5943_026e_0772:
        uVar26 = (undefined2)((ulong)Entities >> 0x10);
        bVar10 = ((entity_t *)Entities)[iVar24].base.gindex;
        if ((((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)bVar10 * 0x95) & 0x40) == 0) ||
            (pbVar15 = &stack0xffde + (uStack_10 ^ 1), '\x01' < (char)*pbVar15)) &&
           ((((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar10 * 0x95) & 8) == 0 ||
             (pbVar15 = &stack0xffde + (uStack_10 ^ 1), '\0' < (char)*pbVar15)) &&
            (((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar10 * 0x95) & 0x10) == 0 ||
             (pbVar15 = &stack0xffdc + (uStack_10 ^ 1), -1 < (char)*pbVar15)))))) {
          bStackY_2d = ((entity_t *)Entities)[iVar24].base.level;
          pbVar15 = (byte *)CONCAT11((char)((uint)(iVar24 * 0x37) >> 8),bStackY_2d);
          iVar25 = iVar24;
        }
      }
      else {
        bVar10 = peVar22[iVar24].base.level;
        pbVar15 = (byte *)CONCAT11((char)((uint)(iVar24 * 0x37) >> 8),bVar10);
        if (bVar10 == bStackY_2d) {
          uVar17 = ovr_randBelow();
          pbVar15 = (byte *)(uVar17 & 0xff);
          if (pbVar15 == (byte *)0x0) goto L_OVC24_5943_026e_0772;
        }
      }
    }
    else if (bStackY_2e < peVar22[iVar24].base.level) {
L_OVC24_5943_026e_088A:
      bStackY_2e = ((entity_t *)Entities)[iVar24].base.level;
      pbVar15 = (byte *)CONCAT11((char)((uint)(iVar24 * 0x37) >> 8),bStackY_2e);
      uStack_a = iVar24;
    }
    else {
      bVar10 = peVar22[iVar24].base.level;
      pbVar15 = (byte *)CONCAT11((char)((uint)(iVar24 * 0x37) >> 8),bVar10);
      if (bVar10 == bStackY_2e) {
        uVar17 = ovr_randBelow();
        pbVar15 = (byte *)(uVar17 & 0xff);
        if (pbVar15 == (byte *)0x0) goto L_OVC24_5943_026e_088A;
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
  int unaff_DI;
  undefined2 in_stack_00000004;
  undefined1 uStack_3;
  
  uVar4 = ovr_alignUp4(unaff_DI,in_stack_00000004);
  uStack_3 = 0;
  for (uVar5 = 0; uVar5 < GRecordCount; uVar5 = uVar5 + 1) {
    if ((((*(uint16_t *)(uVar5 * 0x12 + 4) == x) && (*(uint *)(uVar5 * 0x12 + 2) <= uVar4 + 1)) &&
        (uVar4 - 2 <= (*(int *)(uVar5 * 0x12 + 2) + (uint)*(byte *)(uVar5 * 0x12 + 7)) - 1)) &&
       ((bVar2 = *(byte *)(uVar5 * 0x12 + 9), bVar2 != 0xff &&
        (uVar3 = *(undefined4 *)((uint)bVar2 << 2), *(char *)((int)uVar3 + 0x3f) == (char)y)))) {
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
  uint value;
  uint uVar1;
  int unaff_BP;
  undefined2 in_stack_00000004;
  
  value = ovr_alignUp4(unaff_BP,in_stack_00000004);
  uVar1 = ovr_alignUp4(value,GfxRndSeed);
  if ((value == uVar1) && (uVar1 = GfxRndSeed2, GfxRndSeed2 == x)) {
    uVar1 = CONCAT11((char)(GfxRndSeed2 >> 8),1);
  }
  else {
    uVar1 = uVar1 & 0xff00;
  }
  return uVar1;
}



/* 55fe:0617 */

/* [R6] touches cornerBR, cornerBL */

int __cdecl16far ovc23_usesCornerBR(int x,int bldType)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 unaff_DI;
  int *unaff_SS;
  int *piVar4;
  undefined2 uVar5;
  int iStack_14;
  int iStack_12;
  uint8_t cornerBR;
  uint8_t cornerBL;
  uint8_t cornerTR;
  uint8_t cornerTL;
  int iStack_4;
  
  piVar4 = (int *)CONCAT22(unaff_DI,unaff_SS);
  iVar1 = ovr_constr_usesSmoothPrev(0xffff,(int)&cornerTL,piVar4,x);
  piVar4 = (int *)CONCAT22((int)((ulong)piVar4 >> 0x10),unaff_SS);
  iVar2 = ovr_constr_usesSmoothPrev(0,(int)&cornerBL,piVar4,x);
  uVar5 = (undefined2)((ulong)piVar4 >> 0x10);
  if (*(byte *)(bldType * 0x27 + 0x11b) < 2) {
    piVar4 = (int *)CONCAT22(uVar5,unaff_SS);
    iStack_12 = ovr_constr_usesSmoothPrev(0xffff,(int)&cornerTR,piVar4,x + 1);
    iStack_14 = ovr_constr_usesSmoothPrev
                          (0,(int)&cornerBR,(int *)CONCAT22((int)((ulong)piVar4 >> 0x10),unaff_SS),
                           x + 1);
  }
  else if (*(byte *)(bldType * 0x27 + 0x11b) < 3) {
    piVar4 = (int *)CONCAT22(uVar5,unaff_SS);
    iStack_12 = ovr_constr_usesSmoothPrev(0xffff,(int)&cornerTR,piVar4,x + 2);
    iStack_14 = ovr_constr_usesSmoothPrev
                          (0,(int)&cornerBR,(int *)CONCAT22((int)((ulong)piVar4 >> 0x10),unaff_SS),
                           x + 2);
  }
  else {
    piVar4 = (int *)CONCAT22(uVar5,unaff_SS);
    iStack_12 = ovr_constr_usesSmoothPrev(0xffff,(int)&cornerTR,piVar4,x + 4);
    iStack_14 = ovr_constr_usesSmoothPrev
                          (0,(int)&cornerBR,(int *)CONCAT22((int)((ulong)piVar4 >> 0x10),unaff_SS),
                           x + 4);
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
  undefined2 unaff_DI;
  int *unaff_SS;
  int *piVar3;
  int iStack_12;
  uint8_t cornerBR;
  uint8_t cornerBL;
  uint8_t cornerTR;
  uint8_t cornerTL;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  if (step == 4) {
    piVar3 = (int *)CONCAT22(unaff_DI,unaff_SS);
    iVar1 = ovr_constr_usesSmoothPrev(0xffff,(int)&cornerTL,piVar3,x + 1);
    piVar3 = (int *)CONCAT22((int)((ulong)piVar3 >> 0x10),unaff_SS);
    iStack_4 = ovr_constr_usesSmoothPrev(0,(int)&cornerBL,piVar3,x + 1);
    piVar3 = (int *)CONCAT22((int)((ulong)piVar3 >> 0x10),unaff_SS);
    iStack_6 = ovr_constr_usesSmoothPrev(0xffff,(int)&cornerTR,piVar3,x + 2);
    iStack_8 = ovr_constr_usesSmoothPrev
                         (0,(int)&cornerBR,(int *)CONCAT22((int)((ulong)piVar3 >> 0x10),unaff_SS),
                          x + 2);
  }
  else {
    piVar3 = (int *)CONCAT22(unaff_DI,unaff_SS);
    iVar1 = ovr_constr_usesSmoothPrev(0xffff,(int)&cornerTL,piVar3,x);
    piVar3 = (int *)CONCAT22((int)((ulong)piVar3 >> 0x10),unaff_SS);
    iStack_4 = ovr_constr_usesSmoothPrev(0,(int)&cornerBL,piVar3,x);
    piVar3 = (int *)CONCAT22((int)((ulong)piVar3 >> 0x10),unaff_SS);
    iStack_6 = ovr_constr_usesSmoothPrev(0xffff,(int)&cornerTR,piVar3,x + step);
    iStack_8 = ovr_constr_usesSmoothPrev
                         (0,(int)&cornerBR,(int *)CONCAT22((int)((ulong)piVar3 >> 0x10),unaff_SS),
                          x + step);
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
  bool bVar1;
  byte bVar2;
  undefined1 extraout_AH;
  int iVar4;
  int iVar5;
  uint16_t unaff_SI;
  uint unaff_DI;
  uint16_t uVar6;
  uint16_t in_stack_00000004;
  far_t dst_00;
  uint16_t uVar7;
  uint type;
  int iVar3;
  
  dst_00 = far_from_u32((uint32_t)((ulong)unaff_DI << 0x10));
  bVar1 = false;
  GAnimPlaying = 0;
  uVar6 = rowMapSquareFirst[0];
  while( true ) {
    type = dst_00.seg;
    if (rowMapSquareEnd[0] <= uVar6) break;
    iVar5 = *(int *)(uVar6 * 2 + 0x360);
    if ((-3 < iVar5) && (iVar5 < 2)) {
      dst_00 = far_from_u32((uint32_t)((ulong)type << 0x10));
      bVar2 = ovr_constr_setHighlightAtOffset(0,type,iVar5);
      iVar3 = CONCAT11(extraout_AH,bVar2);
      if (((char *)"build\\thfres01.lbm" + 0x10)[iVar3 * 3 + *(int *)(uVar6 * 2)] != '\0') {
        uVar7 = dst_00.seg;
        iVar4 = ovc23_usesCornerBR(iVar5,iVar3);
        dst_00.seg = uVar7;
        dst_00.ofs = dst.ofs;
        ovr_animAdvance(CONCAT11(0x19,((char *)"build\\thfres01.lbm" + 0x10)
                                      [iVar3 * 3 + *(int *)(uVar6 * 2)]),
                        (byte)*(undefined2 *)(uVar6 * 2 + 0xa20),(uint)bandOrigin[0] - iVar4,
                        in_stack_00000004,dst_00,iVar5);
        bVar1 = true;
      }
      iVar3 = iRam0002d2d7;
      if (*(int *)(iVar5 * 2 + -0x6e25) != -1) {
        uVar7 = dst_00.seg;
        if (*(char *)(iVar5 + -0x6f14) == '\0') {
          iVar3 = *(int *)(iVar5 * 2 + -0x6e25);
          iVar5 = ovc23_usesCornerBR2(iVar5,(uint)*(byte *)(iVar3 * 0x12 + 7));
          dst_00.seg = uVar7;
          dst_00.ofs = dst.ofs;
          ovc23_usesBlitGfxRect2
                    ((uint)bandOrigin[0] - iVar5,iVar3,in_stack_00000004,(brect_t *)MK_FP(dst_00.seg, dst_00.ofs),unaff_SI)
          ;
          bVar1 = true;
        }
        else if (iVar5 == -2) {
          iVar5 = ovc23_usesCornerBR2(-2,(uint)*(byte *)(iRam0002d2d7 * 0x12 + 7));
          dst_00.seg = uVar7;
          dst_00.ofs = dst.ofs;
          ovc23_usesBlitGfxRect2
                    ((uint)bandOrigin[0] - iVar5,iVar3,in_stack_00000004,(brect_t *)MK_FP(dst_00.seg, dst_00.ofs),unaff_SI)
          ;
          bVar1 = true;
        }
      }
    }
    uVar6 = uVar6 + 1;
  }
  if (bVar1) {
    ovr_constr_usesScreenOriginY(dst.ofs,type,in_stack_00000004);
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
/* [R4] calls ovr_alignUp4 */

uint * __cdecl16far ovc23_usesAlignUp43(int16_t x,uint16_t unitIndex,byte dir,...)

{
  uint8_t *puVar1;
  int *piVar2;
  uint *puVar3;
  byte *pbVar4;
  byte bVar5;
  byte bVar6;
  short sVar7;
  undefined4 uVar8;
  far_t pctOut;
  far_t remainderOut;
  far_t partOut;
  bool bVar9;
  bool bVar10;
  byte bVar11;
  char cVar12;
  uint16_t uVar13;
  uint16_t uVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  uint uVar18;
  int in_CX;
  undefined2 uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int *piVar23;
  int *piVar24;
  entity_t *peVar25;
  entity_t *peVar26;
  unit_t *puVar27;
  undefined2 unaff_BP;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  undefined2 uVar28;
  undefined2 uVar29;
  uint16_t unaff_SS;
  bool bVar30;
  undefined2 in_stack_00000000;
  int in_stack_00000004;
  uint uStackY_2e;
  int iStackY_2c;
  int iStackY_2a;
  byte bStackY_20;
  byte bStackY_1f;
  undefined2 uStackY_1e;
  undefined2 uStackY_1c;
  far_t table;
  int iVar31;
  uint *puVar32;
  uint in_stack_0000ffea;
  uint uVar33;
  byte *pbVar34;
  byte *pbVar35;
  uint16_t uVar36;
  uint16_t uVar37;
  undefined1 uVar38;
  undefined2 *puVar39;
  undefined1 uVar40;
  undefined1 uVar41;
  undefined1 uVar42;
  undefined1 uVar43;
  undefined1 uVar44;
  byte bVar45;
  uint in_stack_0000fffc;
  
  iVar31 = in_stack_00000004;
  uVar38 = (undefined1)unaff_SI;
  uVar40 = (undefined1)((uint)unaff_SI >> 8);
  uVar43 = (undefined1)unaff_DI;
  uVar44 = (undefined1)((uint)unaff_DI >> 8);
  uVar19 = 0x2410;
  bVar11 = (byte)((uint)(in_stack_00000004 + *(char *)((unitIndex & 0xff) + 0x885)) >> 8);
  uVar18 = ovr_attact_usesGUnits();
  if ((uVar18 & 0xff) == 0) {
    return (uint *)((int)(undefined4 *)&_DATA + 1);
  }
  uVar18 = unitIndex & 0xff;
  if (3 < uVar18) {
    return (uint *)0x0;
  }
  puVar27 = (unit_t *)(uVar18 * 2);
  switch(uVar18) {
  case 0:
    return (uint *)x;
  case 1:
    while( true ) {
      if (((&puVar27->flags)[uVar18] & 3) == 0) {
        uVar19 = (undefined2)((ulong)GUnits >> 0x10);
        bVar11 = ((unit_t *)GUnits)[x].unitType;
        if ((bVar11 == 0xff) ||
           (uVar8 = *(undefined4 *)((uint)bVar11 << 2), *(char *)((int)uVar8 + 0x3f) == '\0')) {
          uVar43 = 0x96;
          uVar44 = 0;
        }
        else {
          uVar43 = 0xdc;
          uVar44 = 5;
        }
        if (((unit_t *)GUnits)[x].level != 0) {
          uVar36 = ovr_randBelow();
          uVar19 = (undefined2)((ulong)GUnits >> 0x10);
          puVar27 = (unit_t *)GUnits;
          if ((int)(uVar36 & 0xff) <
              (int)(100 - (uint)*(byte *)((uint)(puVar27 + x)->bldType * 0x27 + 0x130))) {
            bStackY_20 = (puVar27 + x)->bldType;
            puVar27[x].level = puVar27[x].level - 1;
            puVar27 = (unit_t *)GUnits;
            uVar19 = (undefined2)((ulong)GUnits >> 0x10);
            if (((*(uint *)((uint)bStackY_20 * 0x27 + 0x121) & 4) == 0) &&
               ((puVar27[x].level == 0 ||
                ((*(uint *)((uint)bStackY_20 * 0x27 + 0x121) & 0x200) != 0)))) {
              ovc22_usesGUnits(x,(uint8_t *)
                                 CONCAT13((char)((uint)(x * 9) >> 8),
                                          CONCAT12(puVar27[x].unitType,unaff_SS)));
            }
            else if (((((bld_inst_t *)BldInstances + bStackY_20)->ofs != 0 ||
                       *(int *)((int)&BldInstances[0].seg + (uint)bStackY_20 * 0xc) != 0) ||
                     (*(char *)((uint)bStackY_20 * 0x27 + 0x11e) == '\x10')) &&
                    (uVar19 = ovc22_usesGOngoingBattle2
                                        (*(byte *)&puVar27[x].x,*(byte *)&puVar27[x].y),
                    (char)uVar19 != '\0')) {
              uStackY_1c = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1c) + 1)),1);
            }
          }
        }
      }
      x = x + 1;
      if (GUnitCount <= (uint)x) break;
      uVar18 = x * 9;
      uVar19 = (undefined2)((ulong)GUnits >> 0x10);
      puVar27 = (unit_t *)GUnits;
    }
    GGameState = 0x43;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (uVar18 = 0; (int)uVar18 < (int)(uint)GLeaderCount; uVar18 = uVar18 + 1) {
      if (*(char *)((int)*(undefined4 *)(uVar18 << 2) + 0x3d) != '\0') {
        *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0xa2) = 0;
        cVar12 = *(char *)((int)*(undefined4 *)(uVar18 << 2) + 0x3f);
        if ((cVar12 == '\0') &&
           (*(uint *)((int)*(undefined4 *)(uVar18 << 2) + 0x4f) <
            *(uint *)((int)*(undefined4 *)(uVar18 << 2) + 0x4d) >> 1)) {
          bVar9 = true;
        }
        else {
          bVar9 = false;
        }
        uVar15 = *(uint *)((int)*(undefined4 *)(uVar18 << 2) + 0x54);
        uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
        iVar31 = (int)*(undefined4 *)(uVar18 << 2);
        iVar31 = *(int *)(iVar31 + 0x58) + ((int)uVar15 >> 0xf) +
                 (uint)CARRY2(*(uint *)(iVar31 + 0x56),uVar15);
        if ((iVar31 < 1) && (iVar31 < 0)) {
          for (uVar15 = 0xf8; uVar15 < GUnitCount; uVar15 = uVar15 + 1) {
            uVar19 = (undefined2)((ulong)GUnits >> 0x10);
            puVar27 = (unit_t *)GUnits;
            bStackY_20 = (puVar27 + uVar15)->bldType;
            if ((puVar27[uVar15].unitType == uVar18) &&
               (*(int *)((uint)bStackY_20 * 0x27 + 0x123) < 0)) {
              uVar16 = *(uint *)((uint)bStackY_20 * 0x27 + 0x123);
              uVar29 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
              iVar31 = (int)*(undefined4 *)(uVar18 << 2);
              iVar31 = *(int *)(iVar31 + 0x58) + ((int)uVar16 >> 0xf) +
                       (uint)CARRY2(*(uint *)(iVar31 + 0x56),uVar16);
              if ((iVar31 < 1) && (iVar31 < 0)) {
                if ((cVar12 == '\0') && (puVar27[uVar15].level != 0)) {
                  uVar36 = ovr_randBelow();
                  uVar19 = (undefined2)((ulong)GUnits >> 0x10);
                  puVar27 = (unit_t *)GUnits;
                  if (*(byte *)((uint)(puVar27 + uVar15)->bldType * 0x27 + 0x130) <= (byte)uVar36) {
                    if (puVar27[uVar15].level != 0) {
                      puVar27[uVar15].level = puVar27[uVar15].level - 1;
                    }
                    puVar27 = (unit_t *)GUnits;
                    uVar19 = (undefined2)((ulong)GUnits >> 0x10);
                    if (((*(uint *)((uint)bStackY_20 * 0x27 + 0x121) & 4) == 0) &&
                       ((iVar31 = 0, puVar27[uVar15].level == 0 ||
                        (iVar31 = (uint)bStackY_20 * 0x27, (*(uint *)(iVar31 + 0x121) & 0x200) != 0)
                        ))) {
                      ovc22_usesGUnits(uVar15,(uint8_t *)
                                              CONCAT13((char)((uint)iVar31 >> 8),
                                                       CONCAT12((char)uVar18,unaff_SS)));
                    }
                    else if (((((bld_inst_t *)BldInstances + bStackY_20)->ofs != 0 ||
                               *(int *)((int)&BldInstances[0].seg + (uint)bStackY_20 * 0xc) != 0) ||
                             (*(char *)((uint)bStackY_20 * 0x27 + 0x11e) == '\x10')) &&
                            (uVar19 = ovc22_usesGOngoingBattle2
                                                (*(byte *)&puVar27[uVar15].x,
                                                 *(byte *)&puVar27[uVar15].y), (char)uVar19 != '\0')
                            ) {
                      uStackY_1c = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1c) + 1)),1);
                    }
                  }
                }
              }
              else {
                uVar33 = *(uint *)((uint)bStackY_20 * 0x27 + 0x123);
                uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
                iVar31 = (int)*(undefined4 *)(uVar18 << 2);
                puVar3 = (uint *)(iVar31 + 0x56);
                uVar16 = *puVar3;
                *puVar3 = *puVar3 + uVar33;
                piVar2 = (int *)(iVar31 + 0x58);
                *piVar2 = *piVar2 + ((int)uVar33 >> 0xf) + (uint)CARRY2(uVar16,uVar33);
              }
            }
          }
          uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
          iVar31 = (int)*(undefined4 *)(uVar18 << 2);
          *(undefined2 *)(iVar31 + 0x58) = 0;
          *(undefined2 *)(iVar31 + 0x56) = 0;
        }
        else {
          if ((cVar12 == '\0') && (0 < *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x54))) {
            uVar15 = *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x54) / 10;
          }
          else {
            uVar15 = 0;
          }
          bVar30 = CARRY2(GPopulationLo,uVar15);
          GPopulationLo = GPopulationLo + uVar15;
          GPopulationHi = GPopulationHi + ((int)uVar15 >> 0xf) + (uint)bVar30;
          uVar15 = *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x54) - uVar15;
          uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
          iVar31 = (int)*(undefined4 *)(uVar18 << 2);
          puVar3 = (uint *)(iVar31 + 0x56);
          uVar16 = *puVar3;
          *puVar3 = *puVar3 + uVar15;
          piVar2 = (int *)(iVar31 + 0x58);
          *piVar2 = *piVar2 + ((int)uVar15 >> 0xf) + (uint)CARRY2(uVar16,uVar15);
        }
        if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uVar18 << 2) + 0x3e) * 0x95) & 0x100) ==
            0) {
          if (*(uint *)((int)*(undefined4 *)(uVar18 << 2) + 0x4f) <
              *(uint *)((int)*(undefined4 *)(uVar18 << 2) + 0x4d)) {
            uVar15 = *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x4d) -
                     *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x4f);
            uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
            iVar22 = (int)*(undefined4 *)(uVar18 << 2);
            iVar31 = *(int *)(iVar22 + 0x62);
            if ((-1 < iVar31) && ((0 < iVar31 || (*(int *)(iVar22 + 0x60) != 0)))) {
              uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
              iVar31 = (int)*(undefined4 *)(uVar18 << 2);
              uVar16 = *(uint *)(iVar31 + 0x62);
              if ((0x7fff < uVar16) ||
                 ((uVar33 = uVar15, (int)uVar16 < 1 && (*(uint *)(iVar31 + 0x60) <= uVar15)))) {
                uVar33 = *(uint *)((int)*(undefined4 *)(uVar18 << 2) + 0x60);
              }
              uVar15 = uVar15 - uVar33;
              uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
              iVar31 = (int)*(undefined4 *)(uVar18 << 2);
              puVar3 = (uint *)(iVar31 + 0x60);
              uVar16 = *puVar3;
              *puVar3 = *puVar3 - uVar33;
              piVar2 = (int *)(iVar31 + 0x62);
              *piVar2 = *piVar2 - (uint)(uVar16 < uVar33);
            }
            if (uVar15 == 0) {
              uVar15 = 0;
            }
            else {
              uVar41 = (undefined1)uVar15;
              uVar42 = (undefined1)(uVar15 >> 8);
              if (*(uint *)((int)*(undefined4 *)(uVar18 << 2) + 0xa0) < uVar15) {
                uVar19 = *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0xa0);
                uVar41 = (undefined1)uVar19;
                uVar42 = (undefined1)((uint)uVar19 >> 8);
              }
              uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
              iVar31 = (int)*(undefined4 *)(uVar18 << 2);
              uVar16 = *(uint *)(iVar31 + 0x58);
              if (((int)uVar16 < 1) &&
                 ((0x7fff < uVar16 || (*(uint *)(iVar31 + 0x56) < CONCAT11(uVar42,uVar41))))) {
                uVar19 = *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0x56);
                uVar41 = (undefined1)uVar19;
                uVar42 = (undefined1)((uint)uVar19 >> 8);
              }
              uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
              iVar31 = (int)*(undefined4 *)(uVar18 << 2);
              puVar3 = (uint *)(iVar31 + 0x56);
              uVar16 = *puVar3;
              *puVar3 = *puVar3 - CONCAT11(uVar42,uVar41);
              piVar2 = (int *)(iVar31 + 0x58);
              *piVar2 = *piVar2 - (uint)(uVar16 < CONCAT11(uVar42,uVar41));
              uVar15 = uVar15 - CONCAT11(uVar42,uVar41);
              *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0xa2) = CONCAT11(uVar42,uVar41);
            }
            if (cVar12 == '\0') {
              for (iVar31 = 0; (uVar15 != 0 && (iVar31 < (int)(uint)GLeaderCount));
                  iVar31 = iVar31 + 1) {
                if ((*(char *)((int)*(undefined4 *)(iVar31 << 2) + 0x3d) != '\0') &&
                   ((*(char *)((int)*(undefined4 *)(iVar31 << 2) + 0x3f) == '\0' &&
                    (uVar19 = (undefined2)((ulong)*(undefined4 *)(iVar31 << 2) >> 0x10),
                    iVar22 = (int)*(undefined4 *)(iVar31 << 2),
                    *(int *)(iVar22 + 0x60) != 0 || *(int *)(iVar22 + 0x62) != 0)))) {
                  uVar19 = (undefined2)((ulong)*(undefined4 *)(iVar31 << 2) >> 0x10);
                  iVar22 = (int)*(undefined4 *)(iVar31 << 2);
                  uVar16 = *(uint *)(iVar22 + 0x62);
                  if ((0x7fff < uVar16) ||
                     ((uVar33 = uVar15, (int)uVar16 < 1 && (*(uint *)(iVar22 + 0x60) <= uVar15)))) {
                    uVar33 = *(uint *)((int)*(undefined4 *)(iVar31 << 2) + 0x60);
                  }
                  uVar15 = uVar15 - uVar33;
                  uVar19 = (undefined2)((ulong)*(undefined4 *)(iVar31 << 2) >> 0x10);
                  iVar22 = (int)*(undefined4 *)(iVar31 << 2);
                  puVar3 = (uint *)(iVar22 + 0x60);
                  uVar16 = *puVar3;
                  *puVar3 = *puVar3 - uVar33;
                  piVar2 = (int *)(iVar22 + 0x62);
                  *piVar2 = *piVar2 - (uint)(uVar16 < uVar33);
                }
              }
            }
            uVar16 = 0;
            while ((uVar16 < EntityCount && (uVar15 != 0))) {
              uVar19 = (undefined2)((ulong)Entities >> 0x10);
              peVar25 = (entity_t *)Entities;
              if (((*(char *)((int)&peVar25[uVar16].base.entity + 1) == '\0') &&
                  (*(byte *)((int)&peVar25[uVar16].base.entity + 3) == uVar18)) &&
                 ((bVar9 || (1 < peVar25[uVar16].base.animFrame)))) {
                if (peVar25[uVar16].base.animFrame != 0x0) {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  puVar1 = &((entity_t *)Entities)[uVar16].base.animFrame;
                  *puVar1 = *puVar1 + 0xff;
                  if (((entity_t *)Entities)[uVar16].base.animFrame == 0x0) {
                    uStackY_1e = CONCAT11(1,(byte)uStackY_1e);
                  }
                }
                uVar15 = uVar15 - 1;
              }
              uVar16 = uVar16 + 1;
            }
          }
          else {
            uVar16 = *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x4f) -
                     *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x4d);
            uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
            iVar31 = (int)*(undefined4 *)(uVar18 << 2);
            puVar3 = (uint *)(iVar31 + 0x60);
            uVar15 = *puVar3;
            *puVar3 = *puVar3 + uVar16;
            piVar2 = (int *)(iVar31 + 0x62);
            *piVar2 = *piVar2 + (uint)CARRY2(uVar15,uVar16);
          }
        }
        uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
        iVar20 = (int)*(undefined4 *)(uVar18 << 2);
        iVar31 = *(int *)(iVar20 + 0x62);
        uVar29 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
        iVar21 = (int)*(undefined4 *)(uVar18 << 2);
        iVar22 = *(int *)(iVar21 + 0x80);
        if ((iVar22 <= iVar31) &&
           ((iVar22 < iVar31 || (*(uint *)(iVar21 + 0x7e) < *(uint *)(iVar20 + 0x60))))) {
          uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
          iVar31 = (int)*(undefined4 *)(uVar18 << 2);
          uVar15 = *(uint *)(iVar31 + 0x60);
          uVar29 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
          iVar22 = (int)*(undefined4 *)(uVar18 << 2);
          puVar3 = (uint *)(iVar22 + 0x7e);
          uVar16 = (uint)(uVar15 < *puVar3);
          uVar33 = *(int *)(iVar31 + 0x62) - *(int *)(iVar22 + 0x80);
          if (((int)(uVar33 - uVar16) < 0) ||
             ((uVar33 == uVar16 &&
              (uVar15 - *puVar3 <= *(uint *)((int)*(undefined4 *)(uVar18 << 2) + 0xa0))))) {
            uVar15 = *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x60) -
                     *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x7e);
          }
          else {
            uVar15 = *(uint *)((int)*(undefined4 *)(uVar18 << 2) + 0xa0);
          }
          *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0xa2) = -uVar15;
          uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
          iVar31 = (int)*(undefined4 *)(uVar18 << 2);
          puVar3 = (uint *)(iVar31 + 0x56);
          uVar16 = *puVar3;
          *puVar3 = *puVar3 + uVar15;
          piVar2 = (int *)(iVar31 + 0x58);
          *piVar2 = *piVar2 + (uint)CARRY2(uVar16,uVar15);
          uVar29 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
          iVar31 = (int)*(undefined4 *)(uVar18 << 2);
          uVar19 = *(undefined2 *)(iVar31 + 0x7e);
          uVar28 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
          iVar22 = (int)*(undefined4 *)(uVar18 << 2);
          *(undefined2 *)(iVar22 + 0x62) = *(undefined2 *)(iVar31 + 0x80);
          *(undefined2 *)(iVar22 + 0x60) = uVar19;
        }
        if ((*(uint *)((int)*(undefined4 *)(uVar18 << 2) + 0x5b) <
             *(uint *)((int)*(undefined4 *)(uVar18 << 2) + 0x4d)) &&
           ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uVar18 << 2) + 0x3e) * 0x95) & 0x80) == 0
           )) {
          iVar31 = *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x4d) -
                   *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x5b);
          uVar15 = 0;
          while ((uVar15 < EntityCount && (iVar31 != 0))) {
            uVar19 = (undefined2)((ulong)Entities >> 0x10);
            peVar25 = (entity_t *)Entities;
            if ((*(byte *)((int)&peVar25[uVar15].base.entity + 3) == uVar18) &&
               ((((*(char *)((int)&peVar25[uVar15].base.entity + 1) == '\0' &&
                  (peVar25[uVar15].base.destX == 0)) && (peVar25[uVar15].base.destY == 0)) &&
                (3 < peVar25[uVar15].base.animFrame)))) {
              if (DebugVerbose != false) {
                printf("kill 2 \r");
              }
              puVar1 = &((entity_t *)Entities)[uVar15].base.animFrame;
              *puVar1 = *puVar1 + 0xff;
              iVar31 = iVar31 + -1;
            }
            uVar15 = uVar15 + 1;
          }
        }
        ovr_ovc25_tickCountdown();
        _fmemset((void *)(ulong)*(uint *)(uVar18 * 4 + 2),6,CONCAT11(uVar44,uVar43));
        _fmemset((void *)(ulong)*(uint *)(uVar18 * 4 + 2),6,CONCAT11(uVar44,uVar43));
        uVar36 = ovr_randBelow();
        if ((byte)uVar36 < *(byte *)((int)*(undefined4 *)(uVar18 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0x6c) =
               *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 100);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0x6a) =
               *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 100);
        }
        uVar36 = ovr_randBelow();
        if ((byte)uVar36 < *(byte *)((int)*(undefined4 *)(uVar18 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0x6e) =
               *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0x66);
        }
        else {
          piVar2 = (int *)((int)*(undefined4 *)(uVar18 << 2) + 0x6c);
          *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x66);
        }
        piVar2 = (int *)((int)*(undefined4 *)(uVar18 << 2) + 0x6e);
        *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x68);
        uVar36 = ovr_randBelow();
        if ((byte)uVar36 < *(byte *)((int)*(undefined4 *)(uVar18 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0x78) =
               *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0x70);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0x76) =
               *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0x70);
        }
        uVar36 = ovr_randBelow();
        if ((byte)uVar36 < *(byte *)((int)*(undefined4 *)(uVar18 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0x7a) =
               *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0x72);
        }
        else {
          piVar2 = (int *)((int)*(undefined4 *)(uVar18 << 2) + 0x78);
          *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x72);
        }
        uVar36 = ovr_randBelow();
        if ((byte)uVar36 < *(byte *)((int)*(undefined4 *)(uVar18 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0x7c) =
               *(undefined2 *)((int)*(undefined4 *)(uVar18 << 2) + 0x74);
        }
        else {
          piVar2 = (int *)((int)*(undefined4 *)(uVar18 << 2) + 0x7a);
          *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x74);
        }
        *(undefined1 *)((int)*(undefined4 *)(uVar18 << 2) + 0xa7) =
             *(undefined1 *)((int)*(undefined4 *)(uVar18 << 2) + 0xa6);
        if (*(char *)((int)*(undefined4 *)(uVar18 << 2) + 0x3f) != '\0') {
          uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
          iVar22 = (int)*(undefined4 *)(uVar18 << 2);
          iVar31 = *(int *)(iVar22 + 0x58);
          if ((iVar31 < 1) && ((iVar31 != 0 || (*(int *)(iVar22 + 0x56) == 0)))) {
            uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
            iVar31 = (int)*(undefined4 *)(uVar18 << 2);
            *(undefined2 *)(iVar31 + 0x58) = 0;
            *(undefined2 *)(iVar31 + 0x56) = 0x32;
          }
        }
        if (*(char *)((int)*(undefined4 *)(uVar18 << 2) + 0xaa) != '\0') {
          in_stack_0000fffc = (uint)*(byte *)((int)*(undefined4 *)(uVar18 << 2) + 0xaa);
          for (uVar15 = 0; (int)uVar15 < (int)(uint)GLeaderCount; uVar15 = uVar15 + 1) {
            uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
            iVar20 = (int)*(undefined4 *)(uVar18 << 2);
            iVar31 = *(int *)(iVar20 + 0x58);
            uVar29 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
            iVar21 = (int)*(undefined4 *)(uVar18 << 2);
            iVar22 = *(int *)(iVar21 + 0x8c);
            if ((iVar22 <= iVar31) &&
               ((iVar31 != iVar22 || (*(uint *)(iVar21 + 0x8a) <= *(uint *)(iVar20 + 0x56)))))
            break;
            if ((*(char *)((int)*(undefined4 *)(uVar15 << 2) + 0x3d) != '\0') &&
               (((0 < *(int *)((int)*(undefined4 *)(uVar15 << 2) + 0x54) &&
                 (*(char *)((int)*(undefined4 *)(uVar15 << 2) + 0x3f) == '\0')) &&
                (uVar15 != uVar18)))) {
              uStackY_2e = (uint)(((long)*(int *)((int)*(undefined4 *)(uVar15 << 2) + 0x54) *
                                   (long)(int)in_stack_0000fffc & 0xffffU) / 100);
              iStackY_2c = 0;
              uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
              iVar31 = (int)*(undefined4 *)(uVar18 << 2);
              uVar16 = *(uint *)(iVar31 + 0x8a);
              uVar29 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
              iVar22 = (int)*(undefined4 *)(uVar18 << 2);
              puVar3 = (uint *)(iVar22 + 0x56);
              iVar31 = (*(int *)(iVar31 + 0x8c) - *(int *)(iVar22 + 0x58)) -
                       (uint)(uVar16 < *puVar3);
              if ((iVar31 < 1) && ((iVar31 < 0 || (uVar16 - *puVar3 < uStackY_2e)))) {
                uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
                iVar31 = (int)*(undefined4 *)(uVar18 << 2);
                uVar16 = *(uint *)(iVar31 + 0x8a);
                uVar29 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
                iVar22 = (int)*(undefined4 *)(uVar18 << 2);
                puVar3 = (uint *)(iVar22 + 0x56);
                uStackY_2e = uVar16 - *puVar3;
                iStackY_2c = (*(int *)(iVar31 + 0x8c) - *(int *)(iVar22 + 0x58)) -
                             (uint)(uVar16 < *puVar3);
              }
              uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar15 << 2) >> 0x10);
              iVar22 = (int)*(undefined4 *)(uVar15 << 2);
              iVar31 = *(int *)(iVar22 + 0x58);
              if ((iVar31 <= iStackY_2c) &&
                 ((iVar31 < iStackY_2c || (*(uint *)(iVar22 + 0x56) < uStackY_2e)))) {
                uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar15 << 2) >> 0x10);
                iVar31 = (int)*(undefined4 *)(uVar15 << 2);
                iStackY_2c = *(int *)(iVar31 + 0x58);
                uStackY_2e = *(uint *)(iVar31 + 0x56);
              }
              uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
              iVar31 = (int)*(undefined4 *)(uVar18 << 2);
              puVar3 = (uint *)(iVar31 + 0x56);
              uVar16 = *puVar3;
              *puVar3 = *puVar3 + uStackY_2e;
              piVar2 = (int *)(iVar31 + 0x58);
              *piVar2 = *piVar2 + iStackY_2c + (uint)CARRY2(uVar16,uStackY_2e);
              uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar15 << 2) >> 0x10);
              iVar31 = (int)*(undefined4 *)(uVar15 << 2);
              puVar3 = (uint *)(iVar31 + 0x56);
              uVar16 = *puVar3;
              *puVar3 = *puVar3 - uStackY_2e;
              piVar2 = (int *)(iVar31 + 0x58);
              *piVar2 = (*piVar2 - iStackY_2c) - (uint)(uVar16 < uStackY_2e);
            }
          }
        }
        iVar31 = *(int *)((int)*(undefined4 *)(uVar18 << 2) + 0x58);
        if ((iVar31 < 1) && (iVar31 < 0)) {
          uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
          iVar31 = (int)*(undefined4 *)(uVar18 << 2);
          *(undefined2 *)(iVar31 + 0x58) = 0;
          *(undefined2 *)(iVar31 + 0x56) = 0;
        }
        uVar19 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
        iVar20 = (int)*(undefined4 *)(uVar18 << 2);
        iVar31 = *(int *)(iVar20 + 0x58);
        uVar29 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
        iVar21 = (int)*(undefined4 *)(uVar18 << 2);
        iVar22 = *(int *)(iVar21 + 0x8c);
        if ((iVar22 <= iVar31) &&
           ((iVar22 < iVar31 || (*(uint *)(iVar21 + 0x8a) < *(uint *)(iVar20 + 0x56))))) {
          uVar29 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
          iVar31 = (int)*(undefined4 *)(uVar18 << 2);
          uVar19 = *(undefined2 *)(iVar31 + 0x8a);
          uVar28 = (undefined2)((ulong)*(undefined4 *)(uVar18 << 2) >> 0x10);
          iVar22 = (int)*(undefined4 *)(uVar18 << 2);
          *(undefined2 *)(iVar22 + 0x58) = *(undefined2 *)(iVar31 + 0x8c);
          *(undefined2 *)(iVar22 + 0x56) = uVar19;
        }
      }
    }
    GGameState = 0x40;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (uVar18 = 0xf8; uVar18 < GUnitCount; uVar18 = uVar18 + 1) {
      uVar19 = (undefined2)((ulong)GUnits >> 0x10);
      puVar27 = (unit_t *)GUnits;
      if ((*(uint *)((uint)(puVar27 + uVar18)->bldType * 0x27 + 0x121) & 0x40) != 0) {
        if (puVar27[uVar18].timer != 0) {
          puVar27[uVar18].timer = puVar27[uVar18].timer - 1;
        }
        uVar19 = (undefined2)((ulong)GUnits >> 0x10);
        if (((unit_t *)GUnits)[uVar18].timer == 0) {
          uVar8 = *(undefined4 *)((uint)((unit_t *)GUnits)[uVar18].unitType << 2);
          if (*(char *)((int)uVar8 + 0x3f) == '\0') {
            ovr_play_sfx();
            sVar7 = ((unit_t *)GUnits)[uVar18].y;
            uVar41 = (undefined1)sVar7;
            uVar42 = (undefined1)((uint)sVar7 >> 8);
            uVar15 = ovr_alignUp4();
            ovr_fmVsprintf((char *)CONCAT13((char)(uVar15 >> 8),CONCAT12((char)uVar15,0x2410)),
                           (char *)CONCAT13(uVar44,CONCAT12(uVar43,CONCAT11(uVar42,uVar41))));
            ovr_say();
            ovr_inputUpdate();
          }
          ovc22_usesGUnits(uVar18,(uint8_t *)
                                  CONCAT13((char)(uVar18 * 9 >> 8),
                                           CONCAT12(((unit_t *)GUnits)[uVar18].unitType,unaff_SS)));
        }
      }
    }
    GGameState = 0x42;
    if (DebugVerbose == false) goto L_upd_units_5087_1d7d_323A;
    break;
  case 2:
    if (in_CX != 1 && uVar18 != 0) goto code_r0x00053afb;
    break;
  case 3:
    puVar3 = (uint *)(&puVar27->bldType + x);
    *puVar3 = *puVar3 >> 7 | *puVar3 << 9;
    *(uint *)(&puVar27->timer +
             (int)((char *)"%s: Costs %d gold of income and provides storage for %u food." + iVar31)
             ) = *(uint *)(&puVar27->timer +
                          (int)((char *)
                                "%s: Costs %d gold of income and provides storage for %u food." +
                               iVar31)) | (uint)&stack0xfff8;
    *(uint *)(&puVar27[1].bldType + iVar31) =
         *(uint *)(&puVar27[1].bldType + iVar31) | (uint)&stack0xfffe;
    AgntAnms[0x7d].x = AgntAnms[0x7d].x | (uint)&stack0xfff8;
    *(uint *)x = *(uint *)x | uVar18;
    (&stack0x8d06)[x] = (&stack0x8d06)[x];
    *(byte *)(iVar31 + 8) = *(byte *)(iVar31 + 8) | bVar11;
    (&stack0xfffe)[iVar31] = (&stack0xfffe)[iVar31] | (byte)((uint)&puVar27->level >> 8);
    pbVar4 = &puVar27->level + x;
    *pbVar4 = *pbVar4 | (byte)in_CX | (byte)iVar31;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  printf((char *)CONCAT13(uVar40,CONCAT12(uVar38,CONCAT11(uVar44,uVar43))));
L_upd_units_5087_1d7d_323A:
  ovr_driver_clearMapFlagsRect();
  uVar18 = 0;
  while (uVar18 < SquareRecCount) {
    uVar19 = (undefined2)((ulong)GMapFlags >> 0x10);
    puVar27 = (unit_t *)(*(short (*) [60] [148])GMapFlags + *(int *)(uVar18 * 0x13 + 2));
    in_stack_0000ffea = uVar18;
code_r0x00053afb:
    *(uint *)(&puVar27->bldType + *(int *)(uVar18 * 0x13) * 2) =
         *(uint *)(&puVar27->bldType + *(int *)(uVar18 * 0x13) * 2) | 8;
    uVar18 = in_stack_0000ffea + 1;
  }
  if (EntityCount <= EntityScanPos) {
    EntityScanPos = 0;
    for (iVar31 = 0; iVar31 < (int)(uint)GLeaderCount; iVar31 = iVar31 + 1) {
      if (*(char *)((int)*(undefined4 *)(iVar31 << 2) + 0x3d) != '\0') {
        piVar23 = (int *)(iVar31 * 4);
        iVar22 = piVar23[1];
        piVar24 = (int *)(iVar31 * 4);
        iVar31 = 0x3b95;
        memcpy((char *)CONCAT22(piVar24[1],(char *)(*piVar24 + 0x8e)),
               (char *)CONCAT13((char)((uint)iVar22 >> 8),CONCAT12((char)iVar22,*piVar23 + 0x94)),3)
        ;
      }
    }
  }
  uVar36 = 0;
  uVar19 = 0x2356;
  bVar11 = ovr_manage_findFirstLeader();
  uVar18 = EntityScanPos;
  if ((bVar11 == 0xff) || (GCanPromote == '\0')) {
    iVar31 = 0;
  }
  else if (*(byte *)((int)*(undefined4 *)((uint)bVar11 << 2) + 0x86) < 5) {
    iVar31 = 0x28;
  }
  else {
    iVar31 = (uint)*(byte *)((int)*(undefined4 *)((uint)bVar11 << 2) + 0x86) * 4 + 0x14;
  }
  for (; uVar18 < EntityCount; uVar18 = uVar18 + 1) {
    uVar29 = (undefined2)((ulong)Entities >> 0x10);
    peVar25 = (entity_t *)Entities;
    if (((*(char *)((int)&peVar25[uVar18].base.entity + 1) == '\0') &&
        (peVar25[uVar18].base.destX == 0)) && (peVar25[uVar18].base.destY == 0)) {
      bVar45 = peVar25[uVar18].base.gindex;
      bVar5 = *(byte *)((int)&peVar25[uVar18].base.entity + 3);
      bVar30 = false;
      bVar10 = false;
      bVar9 = false;
      if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar45 * 0x95) == -1) {
        bVar30 = true;
      }
      else {
        bVar6 = *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x89);
        uStackY_1c = CONCAT11(bVar6,(char)uStackY_1c);
        if (bVar6 < 5) {
          uVar36 = peVar25[uVar18].base.y;
          uVar19 = 0x2379;
          uVar15 = ovr_alignUp4();
          uVar14 = 0x2410;
          if (((*(short (*) [60] [148])GMapFlags)[uVar36][uVar15] & 8U) == 0) {
            uStackY_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1e) + 1)),0x22);
            bStackY_1f = 0x21;
            bStackY_20 = 0x22;
          }
          else {
            uVar38 = (undefined1)unaff_SS;
            uVar40 = (undefined1)(unaff_SS >> 8);
            puVar39 = &uStackY_1e;
            pbVar35 = &bStackY_1f;
            pbVar34 = &bStackY_20;
            uVar18 = CONCAT11((char)((uint)pbVar34 >> 8),(*(uint8_t *)((uint8_t *)&(uStackY_1c) + 1)));
            uStackY_1c = 0x2379;
            uStackY_1e = 0x3d98;
            uVar36 = unaff_SS;
            uVar37 = unaff_SS;
            uVar13 = ovr_attact_usesSquareRecCount();
            table.seg = uVar14;
            table.ofs = uVar13;
            uStackY_1c = 0x2315;
            uVar19 = 0x2315;
            uStackY_1e = 0x3da2;
            pctOut.seg = uVar36;
            pctOut.ofs = (uint16_t)pbVar34;
            remainderOut.seg = uVar37;
            remainderOut.ofs = (uint16_t)pbVar35;
            (*(uint8_t *)((uint8_t *)&(partOut.seg))) = uVar38;
            partOut.ofs = (uint16_t)puVar39;
            (*(uint8_t *)((uint8_t *)&(partOut.seg) + 1)) = uVar40;
            ovr_attact_compute3(table,uVar18,pctOut,remainderOut,partOut);
          }
        }
        else {
          uStackY_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1e) + 1)),0x22);
          bStackY_1f = 0x21;
          bStackY_20 = 0x22;
        }
        uVar38 = (undefined1)uVar19;
        uVar40 = (undefined1)((uint)uVar19 >> 8);
        uVar19 = 0x2337;
        uVar36 = 0x3dca;
        uVar14 = ovr_randBelow();
        iVar31 = CONCAT11(uVar40,uVar38);
        if ((byte)uVar14 < (byte)uStackY_1e) {
          bVar30 = true;
          iVar31 = CONCAT11(uVar40,uVar38);
        }
        else if ((uVar14 & 0xff) < (uint)bStackY_1f + (uStackY_1e & 0xff)) {
          bVar10 = true;
          iVar31 = CONCAT11(uVar40,uVar38);
        }
        else {
          bVar9 = true;
        }
      }
      if (bVar9) {
        uVar19 = (undefined2)((ulong)Entities >> 0x10);
        uVar36 = ((entity_t *)Entities)[uVar18].base.y;
        uVar38 = (undefined1)uVar36;
        uVar40 = (undefined1)(uVar36 >> 8);
        uVar36 = (((entity_t *)Entities + uVar18)->base).x;
        uVar19 = 0x236f;
        cVar12 = ovr_ovc23_tickRecordsAt();
        iVar31 = CONCAT11(uVar40,uVar38);
        if (cVar12 == '\0') {
          if ((bStackY_1f == 0) && ((byte)uStackY_1e == '\0')) {
            uVar38 = 0x6f;
            uVar40 = 0x23;
            uVar19 = 0x2337;
            uVar36 = 0x3e5d;
            uVar14 = ovr_randBelow();
            if ((uVar14 & 0xff) == 0) {
              bVar30 = true;
              iVar31 = CONCAT11(uVar40,uVar38);
            }
            else {
              bVar10 = true;
              iVar31 = CONCAT11(uVar40,uVar38);
            }
          }
          else {
            uVar38 = 0x6f;
            uVar40 = 0x23;
            uVar19 = 0x2337;
            uVar36 = 0x3e86;
            uVar14 = ovr_randBelow();
            iVar31 = CONCAT11(uVar40,uVar38);
            if ((byte)uVar14 < (byte)uStackY_1e) {
              bVar30 = true;
              iVar31 = CONCAT11(uVar40,uVar38);
            }
            else {
              bVar10 = true;
            }
          }
        }
      }
      uVar38 = (undefined1)uVar19;
      uVar40 = (undefined1)((uint)uVar19 >> 8);
      if (bVar30) {
        uVar36 = 0x3ea5;
        uVar15 = ovc22_usesEntities(uVar18);
        iVar31 = CONCAT11(uVar40,uVar38);
        if ((uVar15 & 0xff) == 0) {
          bVar10 = true;
          iVar31 = CONCAT11(uVar40,uVar38);
        }
      }
      if (bVar10) {
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar45 * 0x95) != -1) &&
           (bVar5 != 0xff)) {
          if ((*(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x3f) != '\0') ||
             (((entity_t *)Entities)[uVar18].base.level <
              *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x53))) {
            ovc22_usesLUDIV_at_((entity_t *)
                                CONCAT13((char)((ulong)Entities >> 0x18),
                                         CONCAT12((char)((ulong)Entities >> 0x10),
                                                  (entity_t *)Entities + uVar18)));
            LXMUL_at_((long *)CONCAT11(uVar44,uVar43),
                      CONCAT22(in_stack_0000fffc,CONCAT11(bVar11,bVar45)),
                      CONCAT22(in_stack_00000000,unaff_BP));
            peVar25 = (entity_t *)Entities + uVar18;
            uVar18 = 0x3f89;
            uVar36 = ovr_ovc15_textError();
            uVar16 = ovc22_usesLUDIV_at_2(uVar36,(uint16_t)peVar25,iVar31);
            uVar19 = (undefined2)((ulong)Entities >> 0x10);
            peVar26 = (entity_t *)Entities;
            uVar15 = *(uint *)&peVar26[uVar18].base.health;
            *(uint *)&peVar26[uVar18].base.frameIndex =
                 (int)&(peVar25->base).x +
                 (uint)CARRY2(uVar15,uVar16) + *(int *)&peVar26[uVar18].base.frameIndex;
            *(uint *)&peVar26[uVar18].base.health = uVar15 + uVar16;
            uVar19 = 0x23d5;
            ovr_ovc41_compute3();
          }
        }
        ovc22_usesEntities2(uVar18);
        ovc22_usesEntities3(uVar18);
        uVar38 = (undefined1)uVar19;
        uVar40 = (undefined1)((uint)uVar19 >> 8);
        uVar36 = 0x4016;
        ovc22_usesEntities4(uVar18);
        iVar31 = CONCAT11(uVar40,uVar38);
      }
      iStackY_2a = (uint)((entity_t *)Entities)[uVar18].base.animFrame -
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
        ((entity_t *)Entities)[uVar18].base.animFrame =
             *(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0xa4) + (char)iStackY_2a;
      }
      uVar36 = uVar36 + 1;
      if (199 < (int)uVar36) break;
    }
  }
  EntityScanPos = uVar18;
  mapDirty = 1;
  ovr_unit_usesAlignUp4();
  GGameState = 0x44;
  puVar17 = (uint *)((char *)"puppetmaker" + 3);
  if (DebugVerbose != false) {
    puVar17 = (uint *)((char *)"puppetmaker" + 3);
    printf("%d \r");
  }
  if ((*(uint8_t *)((uint8_t *)&(uStackY_1e) + 1)) != '\0') {
    puVar17 = (uint *)(EntityCount - 1);
    for (puVar32 = puVar17; -1 < (int)puVar32; puVar32 = (uint *)((int)puVar32 + -1)) {
      uVar19 = (undefined2)((ulong)Entities >> 0x10);
      puVar17 = (uint *)(uint)((entity_t *)Entities)[(int)puVar32].base.animFrame;
      if (puVar17 == (uint *)0x0) {
        puVar17 = (uint *)(uint)*(byte *)((int)(char **)GMenuStrings +
                                         (uint)((entity_t *)Entities)[(int)puVar32].base.gindex *
                                         0x95 + 0x1f);
        if (puVar17 == (uint *)0x0) {
          uVar18 = ovr_alignUp4();
          iVar31 = (uint)((entity_t *)Entities)[(int)puVar32].base.gindex * 0x95;
          puVar32 = (uint *)"Intelligence reports %s unit died of starvation. (%d, %d)";
          puVar17 = (uint *)ovr_fmVsprintf((char *)CONCAT22(*(undefined2 *)
                                                             ((int)&worldMenuLabels[0].seg + 1 +
                                                             iVar31),(char *)"puppetmaker" + 3),
                                           (char *)CONCAT22(uVar18,(char *)*(undefined2 *)
                                                                            ((int)&worldMenuLabels
                                                                                   [1].ofs + 1 +
                                                                            iVar31)));
          ovr_uiNotify();
        }
        ovr_ovc15_removeEntity();
      }
    }
  }
  if ((char)uStackY_1c != '\0') {
    ovr_constr_flushDirtyRects();
  }
  return puVar17;
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
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined2 uVar10;
  char *pcVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  undefined1 uVar15;
  byte bVar19;
  undefined1 extraout_AH;
  uint uVar16;
  undefined4 *puVar17;
  byte *pbVar18;
  undefined1 *in_CX;
  byte bVar20;
  byte bVar21;
  byte bVar23;
  char *pcVar22;
  uint *puVar24;
  uint *puVar25;
  int iVar26;
  uint *puVar28;
  undefined2 *puVar29;
  undefined2 *puVar30;
  char *unaff_BP;
  uint uVar31;
  int unaff_SI;
  uint uVar32;
  uint8_t *puVar33;
  undefined2 unaff_SS;
  undefined2 uVar34;
  bool bVar35;
  bool bVar36;
  bool bVar37;
  byte in_AF;
  bool bVar38;
  bool bVar39;
  bool bVar40;
  brect_t *in_stack_00000000;
  undefined4 uVar41;
  int iVar42;
  int in_stack_0000fffc;
  byte bVar5;
  byte bVar27;
  
  puVar33 = seg;
  pcVar11 = ofs;
  pcVar22 = ofs + *(char *)(dir + 0x885);
  bVar20 = (byte)pcVar22;
  uVar16 = ovr_attact_usesGUnits();
  if (((uVar16 & 0xff) != 0) &&
     (puVar17 = (undefined4 *)(uint)dir, puVar17 <= (undefined4 *)((int)(undefined4 *)&_DATA + 3)))
  {
    iVar26 = (int)puVar17 * 2;
    switch(puVar17) {
    case (undefined4 *)0x0:
      (**(code **)(pcVar11 + iVar26 + -0x70))();
      break;
    case (undefined4 *)0x2:
      uVar16 = 0x1000 << (*(byte *)((int)*puVar17 + 0x3f) & 0x1f);
      uVar31 = 0x1000 << ((*(byte *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x3f) ^ 1) & 0x1f);
      uVar32 = 0;
      for (bVar20 = 0; bVar20 < 4; bVar20 = bVar20 + 1) {
        uVar31 = (in_stack_0000fffc + (uint)bVar20) * 2;
        uVar32 = uVar32 | ((short (*) [60] [148])GMapFlags)[-1][unaff_SI + 0x3b]
                          [in_stack_0000fffc + (uint)bVar20 + 0x92] & 0x3000U;
      }
      if ((((*(byte *)((int)pcVar11 * 0x12 + 0xd) & 3) != 1) || (uVar32 != uVar31)) ||
         (bVar35 = ovr_ovc24_textArena(), bVar35)) {
        bVar20 = *(byte *)((int)pcVar11 * 0x12 + 0xd);
        pbVar18 = (byte *)(uint)bVar20;
        if (((bVar20 & 1) == 0) && ((uVar16 & uVar32) != 0)) {
          pbVar18 = (byte *)((int)pcVar11 * 0x12);
          pbVar18[0xd] = pbVar18[0xd] | 1;
        }
      }
      else {
        uVar34 = ovc23_isCursorAt();
        if ((char)uVar34 != '\0') {
          ovr_say();
        }
        if (pcVar11 + 1 < GRecordCount) {
          _fmemmove((char *)CONCAT22(0x21f2,(char *)((int)pcVar11 * 0x12)),
                    (char *)CONCAT22(0x21f2,(char *)((int)pcVar11 * 0x12 + 0x12)),
                    (int)(GRecordCount + (-1 - (int)pcVar11)) * 0x12);
        }
        GRecordCount = GRecordCount + -1;
        pbVar18 = ovc23_textAdlibNone();
      }
      return SUB21(pbVar18,0);
    case (undefined4 *)0x3:
      pcVar22 = pcVar22 + -1;
      bVar21 = (byte)iVar26;
      bVar14 = bVar21 - AgntAnms[0xf].frmid;
      bVar12 = (byte)((uint)iVar26 >> 8);
      bVar20 = bVar12 - dir;
      bVar27 = bVar20 - (bVar21 < AgntAnms[0xf].frmid);
      puVar24 = (uint *)CONCAT11(bVar27,bVar14);
      puVar8 = (undefined1 *)(uint)(bVar12 < dir || bVar20 < (bVar21 < AgntAnms[0xf].frmid));
      puVar29 = (undefined2 *)(&stack0xfffe + -(int)in_CX + -(int)puVar8);
      puVar2 = (uint *)(puVar33 + -0x57e7);
      uVar31 = (uint)(&stack0xfffe < in_CX || &stack0xfffe + -(int)in_CX < puVar8);
      puVar30 = (undefined2 *)*puVar2;
      uVar16 = *puVar2;
      *puVar2 = (uVar16 - (int)puVar29) - uVar31;
      puVar2 = (uint *)((int)puVar29 + 0x7419);
      uVar31 = (uint)(puVar30 < puVar29 || uVar16 - (int)puVar29 < uVar31);
      puVar8 = (undefined1 *)*puVar2;
      uVar16 = *puVar2;
      *puVar2 = (uVar16 - (int)in_CX) - uVar31;
      puVar2 = (uint *)(pcVar11 + 0x19);
      uVar31 = (uint)(puVar8 < in_CX || uVar16 - (int)in_CX < uVar31);
      puVar25 = (uint *)*puVar2;
      uVar16 = *puVar2;
      *puVar2 = (uVar16 - (int)puVar24) - uVar31;
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
      uVar16 = (uint)(puVar25 < puVar24 || uVar16 - (int)puVar24 < uVar31);
      (*(uint16_t *)((uint8_t *)&(s_Peaceful_2410_2915) + 4)) = (0x6665U - (int)puVar33) - uVar16;
      uVar16 = (uint)((uint)0x6665 < puVar33 || (uint)(0x6665U - (int)puVar33) < uVar16);
      bVar35 = (uint)AgntAnms[6].y < pcVar22;
      uVar31 = AgntAnms[6].y - (int)pcVar22;
      AgntAnms[6].y = uVar31 - uVar16;
      puVar8 = (undefined1 *)(uint)(bVar35 || uVar31 < uVar16);
      puVar9 = &stack0xfff6 + -(int)puVar33;
      bVar35 = &stack0xfff6 < puVar33 || puVar9 < puVar8;
      iVar26 = -(int)puVar8;
      puVar28 = (uint *)(puVar9 + iVar26);
      bVar12 = (byte)((uint)in_CX >> 8);
      bVar20 = (byte)pcVar22 - bVar12;
      bVar36 = (byte)pcVar22 < bVar12 || bVar20 < bVar35;
      bVar23 = (byte)((uint)pcVar22 >> 8);
      bVar20 = bVar20 - bVar35;
      bVar35 = bVar14 != 0 || (byte)-bVar14 < bVar36;
      bVar19 = -bVar14 - bVar36;
      bVar21 = bVar20 - dir;
      bVar36 = bVar20 < dir || bVar21 < bVar35;
      bVar21 = bVar21 - bVar35;
      pbVar3 = (byte *)((char *)((int)puVar24 + (int)pcVar11) + -0x60e8);
      bVar35 = *pbVar3 < bVar12 || (byte)(*pbVar3 - bVar12) < bVar36;
      *pbVar3 = (*pbVar3 - bVar12) - bVar36;
      pbVar3 = (byte *)(puVar29 + -0x3974);
      bVar36 = *pbVar3 < bVar21 || (byte)(*pbVar3 - bVar21) < bVar35;
      *pbVar3 = (*pbVar3 - bVar21) - bVar35;
      pbVar3 = (byte *)(pcVar11 + 31000);
      bVar37 = *pbVar3 < dir || (byte)(*pbVar3 - dir) < bVar36;
      *pbVar3 = (*pbVar3 - dir) - bVar36;
      pbVar3 = (byte *)(puVar29 + 0xc);
      bVar20 = *pbVar3;
      bVar12 = *pbVar3 - bVar23;
      bVar36 = bVar20 < bVar23 || bVar12 < bVar37;
      bVar40 = SBORROW1(*pbVar3,bVar23) != SBORROW1(bVar12,bVar37);
      *pbVar3 = bVar12 - bVar37;
      bVar39 = (char)*pbVar3 < '\0';
      bVar38 = *pbVar3 == 0;
      bVar35 = !bVar40;
      bVar13 = (byte)in_CX;
      puVar30 = puVar29;
      if (!bVar35) {
        puVar6 = puVar33;
        puVar33 = puVar33 + 1;
        uVar7 = in(CONCAT11(bVar23,bVar21));
        *puVar6 = uVar7;
        pbVar3 = (byte *)(pcVar11 + 0x18);
        bVar4 = *pbVar3;
        bVar5 = *pbVar3;
        *pbVar3 = (bVar5 - bVar19) - bVar36;
        *(uint **)(puVar9 + iVar26 + -2) = puVar24;
        ((char *)((int)puVar29 + (int)pcVar11))[0x18] =
             (((char *)((int)puVar29 + (int)pcVar11))[0x18] - bVar13) -
             (bVar4 < bVar19 || (byte)(bVar5 - bVar19) < bVar36);
        *(uint *)((int)puVar24 + (int)pcVar11) =
             *(uint *)((int)puVar24 + (int)pcVar11) ^ (uint)puVar24;
        *(uint *)((int)puVar24 + (int)pcVar11) =
             *(uint *)((int)puVar24 + (int)pcVar11) | (uint)puVar24;
        *(char *)((int)puVar24 + (int)pcVar11) = *(char *)((int)puVar24 + (int)pcVar11) + bVar14;
        *puVar24 = ~*puVar24;
        puVar30 = (undefined2 *)*puVar29;
        uVar16 = CONCAT11(bVar19,dir - 0x18) & 0x9e1f;
        bVar39 = (int)uVar16 < 0;
        bVar38 = uVar16 == 0;
        puVar28 = puVar29 + 3;
      }
      bVar36 = bVar35 && bVar36;
      uVar34 = *puVar28;
      if (bVar38 || (bVar35 && bVar40) != bVar39) {
        bVar39 = bVar36;
        if ((!bVar35 || bVar20 >= bVar23 && bVar12 >= bVar37) && !bVar38) {
          *puVar28 = (uint)puVar30;
          uVar34 = *puVar28;
          uVar16 = (int)(char)bVar13 + 0xe299;
          iVar26 = uVar16 - bVar36;
          *puVar28 = iVar26;
          *pcVar11 = -*pcVar11;
          return (bool)(((char)iVar26 + -0x32) -
                       ((uint)(int)(char)bVar13 < 0x1d67 || uVar16 < bVar36));
        }
      }
      else {
        bVar39 = bVar13 < 0x74 || (byte)(bVar13 + 0x8c) < bVar36;
        bVar13 = (bVar13 + 0x8c) - bVar36;
      }
      bVar35 = bVar13 < 100 || (byte)(bVar13 + 0x9c) < bVar39;
      bVar12 = (bVar13 + 0x9c) - bVar39;
      bVar20 = bVar12 - 0x39;
      bVar36 = bVar12 < 0x39 || bVar20 < bVar35;
      bVar20 = bVar20 - bVar35;
      bVar12 = bVar20 - 0x14;
      bVar35 = bVar20 < 0x14 || bVar12 < bVar36;
      bVar12 = bVar12 - bVar36;
      bVar20 = bVar12 - 8;
      bVar36 = bVar12 < 8 || bVar20 < bVar35;
      bVar20 = bVar20 - bVar35;
      bVar12 = bVar20 - 5;
      bVar13 = bVar12 - bVar36;
      iVar26 = -(uint)(bVar13 < 0xfa || (byte)(bVar13 + 6) < (bVar20 < 5 || bVar12 < bVar36)) -
               (int)puVar24;
      uVar31 = (uint)pcVar11 & *(uint *)((char *)((int)puVar24 + (int)pcVar11) + -0x6bdd);
      uVar32 = (uint)puVar33 & *(uint *)((uint8_t *)((int)puVar24 + (int)puVar33) + 0x23);
      *puVar28 = uVar31;
      uVar31 = uVar31 & *(uint *)((int)puVar24 + uVar32);
      uVar16 = CONCAT11(bVar23,bVar21) & *(uint *)((int)puVar30 + uVar31 + iVar26);
      puVar25 = (uint *)CONCAT11(bVar27,bVar14 & bVar27 &
                                        *(byte *)((int)&_streams[0xc].curp +
                                                 CONCAT11(bVar27,bVar14 & bVar27)));
      uVar10 = *puVar28;
      puVar2 = (uint *)((int)puVar30 + uVar31 + iVar26);
      *puVar2 = *puVar2 ^ (uint)(puVar28 + 1);
      piVar1 = (int *)((int)puVar30 + uVar31 + iVar26);
      *piVar1 = *piVar1 - (int)(puVar28 + 1);
      bVar20 = in(uVar16);
      uVar31 = uVar31 & uVar16;
      puVar2 = (uint *)((int)puVar25 + (int)((char *)"+%d ring of prot." + 1 + uVar31));
      *puVar2 = *puVar2 & uVar32;
      *(uint *)(uVar32 + 0x21) = *(uint *)(uVar32 + 0x21) & (uint)puVar25;
      *puVar25 = *puVar25 & uVar32;
      puVar2 = (uint *)&AgntAnms[0x5c].sx;
      *puVar2 = *puVar2 & (uint)(puVar28 + 1);
      puVar2 = (uint *)((int)puVar25 + uVar31);
      *puVar2 = *puVar2 & CONCAT11((char)((uint)uVar10 >> 8),bVar20);
      bVar14 = -(0x99 < bVar20);
      return (bool)(bVar14 + (9 < (bVar14 & 0xf) | 9 < (bVar20 & 0xf) | in_AF) * '\x06' +
                   (0x99 < bVar14 || 0x99 < bVar20) * '`');
    }
    do {
      ovc23_usesBlitGfxRect2
                (unaff_SI,in_stack_0000fffc,(int)unaff_BP,in_stack_00000000,(uint16_t)ofs);
      uVar41 = 0x100;
      do {
        while( true ) {
          do {
            do {
              uVar34 = (undefined2)uVar41;
              puVar33 = puVar33 + 1;
              uVar15 = 0x10;
              if (rowMapSquareEnd[0] <= puVar33) {
                if ((char)((ulong)uVar41 >> 8) != '\0') {
                  uVar15 = 0x10;
                  ovr_constr_usesScreenOriginY();
                }
                return (bool)uVar15;
              }
              iVar26 = *(int *)((int)puVar33 * 2 + 0x360);
            } while ((iVar26 < -2) || (1 < iVar26));
            in_stack_00000000 = (brect_t *)((ulong)in_stack_00000000 & 0xffff0000);
            bVar20 = ovr_constr_setHighlightAtOffset();
            iVar42 = CONCAT11(extraout_AH,bVar20);
            uVar41 = CONCAT22(iVar42,uVar34);
            if (((char *)"build\\thfres01.lbm" + 0x10)[iVar42 * 3 + *(int *)((int)puVar33 * 2)] !=
                '\0') {
              uVar16 = (uint)((ulong)in_stack_00000000 >> 0x10);
              ovc23_usesCornerBR(iVar26,iVar42);
              in_stack_00000000 = (brect_t *)((ulong)uVar16 << 0x10);
              ovr_animAdvance();
              uVar41 = 0x100;
            }
          } while (*(int *)(iVar26 * 2 + -0x6e25) == -1);
          uVar34 = (undefined2)((ulong)in_stack_00000000 >> 0x10);
          if (*(char *)(iVar26 + -0x6f14) != '\0') break;
          iVar42 = 0x6964;
          ovc23_usesCornerBR2(iVar26,(uint)*(byte *)(*(int *)(iVar26 * 2 + -0x6e25) * 0x12 + 7));
          in_stack_00000000 = (brect_t *)CONCAT22(uVar34,seg);
          ovc23_usesBlitGfxRect2
                    ((uint)bandOrigin[0] - iVar42,iVar42,(int)ofs,in_stack_00000000,(uint16_t)ofs);
          uVar41 = 0x100;
        }
      } while (iVar26 != -2);
      in_stack_0000fffc = 0x69d2;
      ovc23_usesCornerBR2(-2,(uint)*(byte *)(iRam0002d2d7 * 0x12 + 7));
      in_stack_00000000 = (brect_t *)CONCAT22(uVar34,seg);
      unaff_SI = (uint)bandOrigin[0] - in_stack_0000fffc;
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
  char *ofs;
  bool bVar2;
  uint uVar3;
  uint *puVar4;
  undefined1 extraout_AH;
  undefined2 unaff_DI;
  char *in_stack_00000004;
  byte bStack_3;
  
  ofs = in_stack_00000004;
  if (((((int)in_stack_00000004 < 0x94) && (-1 < (int)in_stack_00000004)) && (x < 0x3c)) && (-1 < x)
     ) {
    uVar3 = (int)in_stack_00000004 * 2;
    puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[x] + (int)in_stack_00000004);
    *puVar1 = *puVar1 & 0xff0f;
    for (bStack_3 = 0; bStack_3 < 4; bStack_3 = bStack_3 + 1) {
      puVar4 = ovc23_usesAlignUp43(x,CONCAT11((char)(uVar3 >> 8),bStack_3),(byte)unaff_DI,ofs);
      if ((char)puVar4 != '\0') {
        puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[x] + (int)ofs);
        *puVar1 = *puVar1 | 0x10 << (bStack_3 & 0x1f);
      }
      bVar2 = ovc23_textConstructionAbandoned(ofs,(uint8_t *)x,bStack_3);
      uVar3 = CONCAT11(extraout_AH,bVar2);
      if (bVar2) {
        uVar3 = 0x100 << (bStack_3 & 0x1f);
        puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[x] + (int)ofs);
        *puVar1 = *puVar1 | uVar3;
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
  uint16_t x_00;
  byte bVar5;
  int iVar6;
  uint uVar7;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  int unaff_DI;
  uint16_t in_stack_00000004;
  
  x_00 = in_stack_00000004;
  iVar4 = (*(short (*) [148] [60])GUnitGrid)[in_stack_00000004][x];
  bVar3 = ((unit_t *)GUnits + iVar4)->bldType;
  iVar6 = (uint)bVar3 * 0x27;
  if ((*(uint *)(iVar6 + 0x121) & 4) != 0) {
    iVar6 = 0x2410;
    strongholdCheckPending = 1;
  }
  uVar7 = ovr_ovc18_usesRandBelow
                    (x,CONCAT11((char)((uint)iVar6 >> 8),(undefined1)y),bldType,(byte)unaff_DI,
                     in_stack_00000004);
  if ((*(byte *)((y & 0xffU) * 0x27 + 0x11e) & 2) == 2) {
    ovc23_usesGfxRndSeed2(x_00,x);
  }
  if (((*(byte *)((y & 0xffU) * 0x27 + 0x11e) & 0xf) != 0) ||
     ((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 0xf) != 0)) {
    ovc23_rebuildDirectionFlags(x,unaff_DI,x_00);
  }
  if (((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 1) != 0) ||
     ((*(byte *)((y & 0xffU) * 0x27 + 0x11e) & 1) != 0)) {
    ovc23_rebuildDirectionFlags(x + 1,unaff_DI,x_00);
  }
  if (((*(byte *)((y & 0xffU) * 0x27 + 0x11e) & 2) != 0) ||
     ((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 2) != 0)) {
    ovc23_rebuildDirectionFlags(x,unaff_DI,x_00 - 1);
  }
  if (((*(byte *)((y & 0xffU) * 0x27 + 0x11e) & 3) == 3) ||
     ((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 3) == 3)) {
    ovc23_rebuildDirectionFlags(x,unaff_DI,x_00 + 1);
    ovc23_rebuildDirectionFlags(x + 1,unaff_DI,x_00);
  }
  if (*(char *)((y & 0xffU) * 0x27 + 0x11a) == '\x02') {
    if (((*(short (*) [60] [148])GMapFlags)[x + 1][x_00] & 3U) != 0) {
      pbVar1 = &((unit_t *)GUnits)[uVar7].flags;
      *pbVar1 = *pbVar1 | 4;
      puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[x + 1] + x_00);
      *puVar2 = *puVar2 & 0xfffc;
    }
    if ((*(byte *)((y & 0xffU) * 0x27 + 0x11e) & 4) != 0) {
      if (((*(short (*) [60] [148])GMapFlags)[x][x_00 + 0x93] & 3U) != 0) {
        pbVar1 = &((unit_t *)GUnits)[uVar7].flags;
        *pbVar1 = *pbVar1 | 8;
        puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[x] + x_00 + 0x93);
        *puVar2 = *puVar2 & 0xfffc;
        ovc23_rebuildDirectionFlags(x,unaff_DI,x_00 - 2);
        ovc23_rebuildDirectionFlags(x + -1,unaff_DI,x_00 - 1);
        ovc23_rebuildDirectionFlags(x + 1,unaff_DI,x_00 - 1);
      }
      if (((*(short (*) [60] [148])GMapFlags)[x + 1][x_00 + 1] & 3U) != 0) {
        pbVar1 = &((unit_t *)GUnits)[uVar7].flags;
        *pbVar1 = *pbVar1 | 0x10;
        puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[x + 1] + x_00 + 1);
        *puVar2 = *puVar2 & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -1,unaff_DI,x_00 + 1);
        ovc23_rebuildDirectionFlags(x + 1,unaff_DI,x_00 + 1);
        ovc23_rebuildDirectionFlags(x,unaff_DI,x_00 + 2);
      }
    }
    if ((*(byte *)((y & 0xffU) * 0x27 + 0x11e) & 8) != 0) {
      if (((*(short (*) [60] [148])GMapFlags)[x][x_00] & 3U) != 0) {
        pbVar1 = &((unit_t *)GUnits)[uVar7].flags;
        *pbVar1 = *pbVar1 | 8;
        puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[x] + x_00);
        *puVar2 = *puVar2 & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -1,unaff_DI,x_00 - 1);
        ovc23_rebuildDirectionFlags(x + -1,unaff_DI,x_00 + 1);
        ovc23_rebuildDirectionFlags(x + -2,unaff_DI,x_00);
      }
      if (((*(short (*) [60] [148])GMapFlags)[x + 2][x_00] & 3U) != 0) {
        pbVar1 = &((unit_t *)GUnits)[uVar7].flags;
        *pbVar1 = *pbVar1 | 0x10;
        puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[x + 2] + x_00);
        *puVar2 = *puVar2 & 0xfffc;
        ovc23_rebuildDirectionFlags(x + 1,unaff_DI,x_00 - 1);
        ovc23_rebuildDirectionFlags(x + 1,unaff_DI,x_00 + 1);
        ovc23_rebuildDirectionFlags(x + 2,unaff_DI,x_00);
      }
    }
    ovc23_rebuildDirectionFlags(x,unaff_DI,x_00);
    ovc23_rebuildDirectionFlags(x,unaff_DI,x_00 + 1);
    ovc23_rebuildDirectionFlags(x,unaff_DI,x_00 - 1);
    ovc23_rebuildDirectionFlags(x + -1,unaff_DI,x_00);
    ovc23_rebuildDirectionFlags(x + 1,unaff_DI,x_00);
  }
  if (*(char *)((uint)bVar3 * 0x27 + 0x11a) == '\x02') {
    ovc23_usesGfxRndSeed2(x_00,x);
    if ((((unit_t *)GUnits)[iVar4].flags & 4) != 0) {
      ovc23_drownUnitsAt(x_00,x);
    }
    if (*(char *)((uint)bVar3 * 0x27 + 0x11e) == '\x04') {
      bVar5 = ovr_ovc45_getUnitType(x,unaff_DI,x_00 - 1);
      if ((CONCAT11(extraout_AH,bVar5) == 0) && ((((unit_t *)GUnits)[iVar4].flags & 8) != 0)) {
        ovc23_usesGfxRndSeed2(x_00 - 1,x);
        ovc23_drownUnitsAt(x_00 - 1,x);
        ovc23_rebuildDirectionFlags(x + -1,unaff_DI,x_00 - 1);
        ovc23_rebuildDirectionFlags(x + 1,unaff_DI,x_00 - 1);
        ovc23_rebuildDirectionFlags(x,unaff_DI,x_00 - 2);
      }
      bVar5 = ovr_ovc45_getUnitType(x,unaff_DI,x_00 + 1);
      if ((CONCAT11(extraout_AH_00,bVar5) == 0) && ((((unit_t *)GUnits)[iVar4].flags & 0x10) != 0))
      {
        ovc23_usesGfxRndSeed2(x_00 + 1,x);
        ovc23_drownUnitsAt(x_00 + 1,x);
        ovc23_rebuildDirectionFlags(x + -1,unaff_DI,x_00 + 1);
        ovc23_rebuildDirectionFlags(x + 1,unaff_DI,x_00 + 1);
        ovc23_rebuildDirectionFlags(x,unaff_DI,x_00 + 2);
      }
    }
    else if (*(char *)((uint)bVar3 * 0x27 + 0x11e) == '\b') {
      bVar5 = ovr_ovc45_getUnitType(x + -1,unaff_DI,x_00);
      if ((CONCAT11(extraout_AH_01,bVar5) == 0) && ((((unit_t *)GUnits)[iVar4].flags & 8) != 0)) {
        ovc23_usesGfxRndSeed2(x_00,x + -1);
        ovc23_drownUnitsAt(x_00,x - 1);
        ovc23_rebuildDirectionFlags(x + -1,unaff_DI,x_00 - 1);
        ovc23_rebuildDirectionFlags(x + -1,unaff_DI,x_00 + 1);
        ovc23_rebuildDirectionFlags(x + -2,unaff_DI,x_00);
      }
      bVar5 = ovr_ovc45_getUnitType(x + 1,unaff_DI,x_00);
      if ((CONCAT11(extraout_AH_02,bVar5) == 0) && ((((unit_t *)GUnits)[iVar4].flags & 0x10) != 0))
      {
        ovc23_usesGfxRndSeed2(x_00,x + 1);
        ovc23_drownUnitsAt(x_00,x + 1);
        ovc23_rebuildDirectionFlags(x + 1,unaff_DI,x_00 - 1);
        ovc23_rebuildDirectionFlags(x + 1,unaff_DI,x_00 + 1);
        ovc23_rebuildDirectionFlags(x + 2,unaff_DI,x_00);
      }
    }
    ovc23_rebuildDirectionFlags(x,unaff_DI,x_00);
    ovc23_rebuildDirectionFlags(x,unaff_DI,x_00 + 1);
    ovc23_rebuildDirectionFlags(x,unaff_DI,x_00 - 1);
    ovc23_rebuildDirectionFlags(x + -1,unaff_DI,x_00);
    ovc23_rebuildDirectionFlags(x + 1,unaff_DI,x_00);
  }
  if ((*(char *)((y & 0xffU) * 0x27 + 0x133) == '\x12') && (ListCount < 5)) {
    *(uint *)((uint)ListCount * 2 + -0x6d44) = uVar7;
    ListCount = ListCount + 1;
  }
  if ((*(int *)((y & 0xffU) * 0x27 + 0x12e) != 0) || (*(int *)((uint)bVar3 * 0x27 + 0x12e) != 0)) {
    ovr_unit_usesAlignUp4();
  }
  return;
}



/* 55fe:1803 */

/* Removes a record from the 0x12-stride table at 0x21f2, compacts the tail and decrements
   GRecordCount. */

void __cdecl16far ovc23_removeRecord(int recordIndex,...)

{
  int in_stack_00000004;
  
  if (in_stack_00000004 + 1U < GRecordCount) {
    _fmemmove((char *)CONCAT22(0x21f2,(char *)(in_stack_00000004 * 0x12)),
              (char *)CONCAT22(0x21f2,(char *)(in_stack_00000004 * 0x12 + 0x12)),
              ((GRecordCount - in_stack_00000004) + -1) * 0x12);
  }
  GRecordCount = GRecordCount - 1;
  ovc23_textAdlibNone();
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
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  uint16_t unaff_DI;
  uint uVar7;
  undefined2 uVar8;
  byte in_stack_00000004;
  int iVar9;
  uint uVar10;
  byte bStack_5;
  byte bStack_3;
  
  for (iVar9 = 0; iVar9 < (int)(uint)*(byte *)((uint)in_stack_00000004 * 0x27 + 0x11b);
      iVar9 = iVar9 + 1) {
    uVar10 = ovc23_findRecordAt();
    if (-1 < (int)uVar10) {
      ovc23_removeRecord(unaff_DI,uVar10);
    }
  }
  iVar9 = ovc23_isLargeBuilding(bldType,x);
  if ((char)iVar9 != '\0') {
    ovc23_placeBuilding();
    uVar4 = ovr_ovc22_usesGOngoingBattle();
    if ((char)uVar4 != '\0') {
      *(undefined1 *)CONCAT22((uint8_t *)outFlag,y) = 1;
    }
  }
  for (iVar9 = 1; iVar9 < (int)(uint)*(byte *)((uint)in_stack_00000004 * 0x27 + 0x11b);
      iVar9 = iVar9 + 1) {
    ovc23_placeBuilding();
    uVar4 = ovr_ovc22_usesGOngoingBattle();
    if ((char)uVar4 != '\0') {
      *(undefined1 *)CONCAT22((uint8_t *)outFlag,y) = 1;
    }
  }
  if (*(char *)((int)*(undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(outFlag) + 2)) << 2) + 0x3f) == '\0') {
    if (0x31 < GRecordCount) {
      uVar6 = 0;
      uVar7 = 0xffff;
      for (uVar10 = 0; uVar10 < GRecordCount; uVar10 = uVar10 + 1) {
        uVar5 = ovr_ovc22_usesGOngoingBattle();
        if (((uVar5 & 0xff) == 0) && (uVar6 <= (uint)(GameTick - *(int *)(uVar10 * 0x12 + 0xf)))) {
          uVar6 = GameTick - *(int *)(uVar10 * 0x12 + 0xf);
          uVar7 = uVar10;
        }
      }
      if (uVar7 == 0xffff) {
        for (uVar10 = 0; uVar10 < GRecordCount; uVar10 = uVar10 + 1) {
          if (uVar6 <= (uint)(GameTick - *(int *)(uVar10 * 0x12 + 0xf))) {
            uVar6 = GameTick - *(int *)(uVar10 * 0x12 + 0xf);
            uVar7 = uVar10;
          }
        }
      }
      if (uVar7 == 0xffff) {
        return;
      }
      if (uVar7 + 1 < GRecordCount) {
        _fmemmove((char *)CONCAT22(0x21f2,(char *)(uVar7 * 0x12)),
                  (char *)CONCAT22(0x21f2,(char *)(uVar7 * 0x12 + 0x12)),
                  ((GRecordCount - uVar7) + -1) * 0x12);
      }
      GRecordCount = GRecordCount - 1;
    }
    _fmemset((void *)0x21f2,0x12,unaff_DI);
    *(byte *)(GRecordCount * 0x12 + 8) = in_stack_00000004;
    *(int *)(GRecordCount * 0x12 + 2) = bldType;
    *(int *)(GRecordCount * 0x12 + 4) = x;
    *(byte *)(GRecordCount * 0x12 + 9) = (*(uint8_t *)((uint8_t *)&(outFlag) + 2));
    iVar9 = ovc23_isLargeBuilding(bldType,x);
    uVar4 = (undefined2)((ulong)GUnitGrid >> 0x10);
    uVar8 = (undefined2)((ulong)GUnits >> 0x10);
    if ((char)iVar9 == '\0') {
      bStack_5 = ((unit_t *)GUnits + (*(short (*) [148] [60])GUnitGrid)[bldType][x])->bldType;
    }
    else {
      bStack_5 = ((unit_t *)GUnits + ((short (*) [148] [60])GUnitGrid)[-1][bldType + 0x93][x])->
                 bldType;
    }
    bStack_3 = *(byte *)((uint)bStack_5 * 0x27 + 0x11d);
    uVar3 = *(undefined1 *)((uint)bStack_5 * 0x27 + 0x11b);
    if (bStack_3 == 0) {
      bStack_3 = 1;
    }
    if (bStack_3 < *(byte *)((uint)in_stack_00000004 * 0x27 + 0x11c)) {
      *(undefined1 *)(GRecordCount * 0x12 + 6) =
           *(undefined1 *)((uint)in_stack_00000004 * 0x27 + 0x11c);
    }
    else {
      *(byte *)(GRecordCount * 0x12 + 6) = bStack_3;
    }
    *(int *)(GRecordCount * 0x12 + 0xf) = GameTick;
    *(undefined2 *)(GRecordCount * 0x12) = 0;
    uVar4 = ovc23_usesGRecordCount3
                      (*(byte *)((uint)in_stack_00000004 * 0x27 + 0x120),(*(uint8_t *)((uint8_t *)&(outFlag) + 2)),GRecordCount)
    ;
    *(undefined1 *)(GRecordCount * 0x12 + 0xc) = (char)uVar4;
    if (*(char *)(GRecordCount * 0x12 + 0xc) == '\0') {
      *(undefined1 *)(GRecordCount * 0x12 + 0xc) = 1;
    }
    if (in_stack_00000004 == 0) {
      iVar9 = ovc23_isLargeBuilding(bldType,x);
      if ((char)iVar9 != '\0') {
        piVar1 = (int *)(GRecordCount * 0x12 + 2);
        *piVar1 = *piVar1 + -1;
      }
      *(undefined1 *)(GRecordCount * 0x12 + 7) = uVar3;
      if (partyIndex == '\x01') {
        *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 1;
      }
      else {
        *(char *)(GRecordCount * 0x12 + 0xc) = partyIndex;
        *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 0;
      }
      pbVar2 = (byte *)(GRecordCount * 0x12 + 0xd);
      *pbVar2 = *pbVar2 | 3;
    }
    else {
      *(undefined1 *)(GRecordCount * 0x12 + 7) =
           *(undefined1 *)((uint)in_stack_00000004 * 0x27 + 0x11b);
      if (partyIndex != '\0') {
        ovc23_placeBuilding();
        uVar4 = ovr_ovc22_usesGOngoingBattle();
        if ((char)uVar4 != '\0') {
          *(undefined1 *)CONCAT22((uint8_t *)outFlag,y) = 1;
        }
      }
      *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 0;
    }
    *(undefined1 *)(GRecordCount * 0x12 + 0x11) = 0;
    *(undefined1 *)(GRecordCount * 0x12 + 0xb) = *(undefined1 *)(GRecordCount * 0x12 + 0xc);
    uVar10 = GRecordCount;
    GRecordCount = GRecordCount + 1;
    ovc23_abandonConstruction(uVar10);
    ovc23_textAdlibNone();
  }
  else {
    ovc23_placeBuilding();
    uVar4 = ovr_ovc22_usesGOngoingBattle();
    if ((char)uVar4 != '\0') {
      *(undefined1 *)CONCAT22((uint8_t *)outFlag,y) = 1;
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
  undefined1 uVar1;
  undefined1 in_stack_00000004;
  
  uVar1 = (undefined1)((uint)in_AX >> 8);
  createConstructionRecord
            (bldType,x,y,(uint8_t *)CONCAT22(CONCAT11(uVar1,(*(uint8_t *)((uint8_t *)&(outFlag) + 2))),(uint8_t *)outFlag),
             '\x01',CONCAT11(uVar1,in_stack_00000004));
  return;
}



/* 55fe:1ea9 */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc23_usesBlitGfxRect(int x,int y,int recordIndex,brect_t *rect,uint16_t type)

{
  int x_00;
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint16_t uVar4;
  uint uVar5;
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
  bool mirror;
  uint uStack_10;
  uint uStack_e;
  int iStack_c;
  undefined2 uStack_a;
  uint16_t uStack_8;
  
  uStack_10 = (uint)*(byte *)(y * 0x12 + 6);
  uVar3 = *(uint *)(y * 0x12);
  bVar1 = *(byte *)(y * 0x12 + 0xe);
  bVar2 = *(byte *)(y * 0x12 + 0x11);
  if (bVar2 < uStack_10) {
    uStack_10 = bVar2 + 1;
  }
  uVar4 = in_stack_00000004 - 1;
  iStack_c = x + uStack_10 * -0x26 + -0x32;
  uStack_e = uStack_10;
  while (uStack_e = uStack_e - 1, -1 < (int)uStack_e) {
    x_00 = iStack_c + 0x26;
    mirror = SUB21(unaff_DI,0);
    if ((bVar1 == 2) || (0x13 < uVar3)) {
      if (bVar1 < 2) {
        if ((uStack_e == 0) && ((uVar3 - uVar4 & 0x3f) < 0x20)) {
          uVar5 = uVar3 - uVar4 & 0x3f;
          uStack_8 = ((undefined2 *)&csite5Seg)[uVar5 * 2];
          uStack_a = ((undefined2 *)&csite5Ofs)[uVar5 * 2];
        }
        else {
          uStack_8 = csite3_5Seg;
          uStack_a = csite3_5Ofs;
        }
        if (uStack_e == 0) {
          uVar5 = (uVar3 + GfxRndSeed2) % 0xe;
          gfx_01.seg = in_stack_00000004 + 0xe;
          gfx_01.ofs = ((undefined2 *)&tmstrsSprites6Seg)[uVar5 * 2];
          ovr_blitGfxRect(gfx_01,iStack_c + 0x8b,recordIndex,
                          (brect_t *)CONCAT22(0x10,(brect_t *)rect),0x1,mirror,
                          ((undefined2 *)&tmstrsSprites6Ofs)[uVar5 * 2]);
        }
        gfx_02.seg = uVar4;
        gfx_02.ofs = uStack_8;
        ovr_blitGfxRect(gfx_02,x_00,recordIndex,(brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,
                        SUB21(unaff_DI,0),uStack_a);
        if ((uVar3 + uStack_e + GfxRndSeed2 + uVar4 & 0x1f) < 0x11) {
          uVar5 = uVar3 + uStack_e + GfxRndSeed2 + uVar4 & 0x1f;
          gfx_03.seg = uVar4 + ((uint)*(byte *)((uVar3 + uStack_e + GfxRndSeed2 + uVar4 >> 5) +
                                                uStack_e + GfxRndSeed2 & 0xff) * 0x50) / 0x100;
          gfx_03.ofs = ((undefined2 *)&tmstrsSprites5Seg)[uVar5 * 2];
          ovr_blitGfxRect(gfx_03,iStack_c + 0x66,recordIndex,
                          (brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,SUB21(unaff_DI,0),
                          ((undefined2 *)&tmstrsSprites5Ofs)[uVar5 * 2]);
        }
        if ((((uVar3 + uStack_e) - GfxRndSeed2) - uVar4 & 0xf) < 7) {
          uVar5 = ((uVar3 + uStack_e) - GfxRndSeed2) - uVar4 & 0xf;
          gfx_04.seg = uVar4 + ((uint)*(byte *)((((((uVar3 + uStack_e) - GfxRndSeed2) - uVar4 >> 4)
                                                 + uStack_e) - GfxRndSeed2) + 0xe & 0xff) * 0x50) /
                               0x100;
          gfx_04.ofs = ((undefined2 *)&tmstrsSprites4Seg)[uVar5 * 2];
          ovr_blitGfxRect(gfx_04,iStack_c + 0x66,recordIndex,
                          (brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,SUB21(unaff_DI,0),
                          ((undefined2 *)&tmstrsSprites4Ofs)[uVar5 * 2]);
        }
        uVar5 = (uVar3 + 5) % 7;
        gfx_05.seg = in_stack_00000004 + 9;
        gfx_05.ofs = ((undefined2 *)&tmstrsSprites3Seg)[uVar5 * 2];
        ovr_blitGfxRect(gfx_05,iStack_c + 0x62,recordIndex,(brect_t *)CONCAT22(0x10,(brect_t *)rect)
                        ,0x0,SUB21(unaff_DI,0),((undefined2 *)&tmstrsSprites3Ofs)[uVar5 * 2]);
        gfx_06.seg = in_stack_00000004 + 0xd;
        gfx_06.ofs = ((undefined2 *)&tmstrsSprites3Seg)[(uVar3 % 7) * 2];
        ovr_blitGfxRect(gfx_06,iStack_c + 0x62,recordIndex,(brect_t *)CONCAT22(0x10,(brect_t *)rect)
                        ,0x0,SUB21(unaff_DI,0),((undefined2 *)&tmstrsSprites3Ofs)[(uVar3 % 7) * 2]);
        uVar5 = (uVar3 + 2) % 7;
        gfx_07.seg = in_stack_00000004 + 0x31;
        gfx_07.ofs = ((undefined2 *)&tmstrsSprites3Seg)[uVar5 * 2];
        ovr_blitGfxRect(gfx_07,iStack_c + 0x62,recordIndex,(brect_t *)CONCAT22(0x10,(brect_t *)rect)
                        ,0x0,SUB21(unaff_DI,0),((undefined2 *)&tmstrsSprites3Ofs)[uVar5 * 2]);
        uVar5 = uVar3 + 3 & 7;
        gfx_08.seg = in_stack_00000004 + 0x45;
        gfx_08.ofs = ((undefined2 *)&tmstrsSprites2Seg)[uVar5 * 2];
        ovr_blitGfxRect(gfx_08,iStack_c + 0x62,recordIndex,(brect_t *)CONCAT22(0x10,(brect_t *)rect)
                        ,0x0,SUB21(unaff_DI,0),((undefined2 *)&tmstrsSprites2Ofs)[uVar5 * 2]);
        gfx_09.seg = in_stack_00000004 + 0x3b;
        gfx_09.ofs = ((undefined2 *)&tmstrsSprites2Seg)[(uVar3 & 7) * 2];
        ovr_blitGfxRect(gfx_09,iStack_c + 0x62,recordIndex,(brect_t *)CONCAT22(0x10,(brect_t *)rect)
                        ,0x0,SUB21(unaff_DI,0),((undefined2 *)&tmstrsSprites2Ofs)[(uVar3 & 7) * 2]);
        gfx_10.seg = in_stack_00000004 + 0x27;
        gfx_10.ofs = ((undefined2 *)&tmstrsSprites1Seg)[(uVar3 % 5) * 2];
        ovr_blitGfxRect(gfx_10,iStack_c + 0x62,recordIndex,(brect_t *)CONCAT22(0x10,(brect_t *)rect)
                        ,0x0,SUB21(unaff_DI,0),((undefined2 *)&tmstrsSprites1Ofs)[(uVar3 % 5) * 2]);
        gfx_11.seg = in_stack_00000004 + 0x3f;
        gfx_11.ofs = ((undefined2 *)&tmstrsSprites1Seg)[(uVar3 % 5) * 2];
        ovr_blitGfxRect(gfx_11,iStack_c + 0x62,recordIndex,(brect_t *)CONCAT22(0x10,(brect_t *)rect)
                        ,0x0,SUB21(unaff_DI,0),((undefined2 *)&tmstrsSprites1Ofs)[(uVar3 % 5) * 2]);
        iStack_c = x_00;
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
        gfx_00.seg = uVar4;
        gfx_00.ofs = uStack_8;
        ovr_blitGfxRect(gfx_00,x_00,recordIndex,(brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,mirror
                        ,uStack_a);
        iStack_c = x_00;
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
      gfx.seg = uVar4;
      gfx.ofs = uStack_8;
      ovr_blitGfxRect(gfx,x_00,recordIndex,(brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,mirror,
                      uStack_a);
      iStack_c = x_00;
    }
  }
  return;
}



/* 55fe:23d8 */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc23_usesBlitGfxRect2(int x,int y,int recordIndex,brect_t *rect,uint16_t type)

{
  int x_00;
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined2 uVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  uint uVar7;
  uint16_t unaff_SI;
  uint unaff_DI;
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
  bool mirror;
  brect_t *rect_00;
  ulong uVar8;
  ulong uVar9;
  uint uStack_12;
  uint uStack_c;
  int iStack_a;
  undefined2 uStack_8;
  uint16_t uStack_6;
  
  uVar8 = (ulong)unaff_DI << 0x10;
  bVar1 = *(byte *)(y * 0x12 + 7);
  if (bVar1 < 2) {
    uStack_12 = (uint)*(byte *)(y * 0x12 + 6);
    uVar3 = *(uint *)(y * 0x12);
    bVar1 = *(byte *)(y * 0x12 + 0xe);
    bVar2 = *(byte *)(y * 0x12 + 0x11);
    if (bVar2 < uStack_12) {
      uStack_12 = bVar2 + 1;
    }
    uVar6 = in_stack_00000004 - 1;
    iStack_a = x + uStack_12 * -0x13 + 0x2a;
    uStack_c = uStack_12;
    while (uVar5 = csite1_12Seg, uVar4 = csite1_12Ofs, uStack_c = uStack_c - 1, -1 < (int)uStack_c)
    {
      x_00 = iStack_a + 0x13;
      uVar7 = (uint)(uVar8 >> 0x10);
      mirror = SUB41(uVar8 >> 0x10,0);
      if ((bVar1 == 2) || (0x13 < uVar3)) {
        if (bVar1 < 2) {
          if (uStack_c == 0) {
            uVar8 = CONCAT22(uVar7,1);
            uVar7 = (uVar3 + GfxRndSeed2) % 0xe;
            gfx_01.seg = in_stack_00000004 + 0xe;
            gfx_01.ofs = ((undefined2 *)&tmstrsSprites6Seg)[uVar7 * 2];
            ovr_blitGfxRect(gfx_01,iStack_a + 0x22,recordIndex,
                            (brect_t *)CONCAT22(0x10,(brect_t *)rect),0x1,mirror,
                            ((undefined2 *)&tmstrsSprites6Ofs)[uVar7 * 2]);
          }
          uVar9 = uVar8 & 0xffff0000;
          gfx_02.seg = uVar6;
          gfx_02.ofs = uVar5;
          ovr_blitGfxRect(gfx_02,x_00,recordIndex,(brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,
                          SUB41(uVar8 >> 0x10,0),uVar4);
          if ((uVar3 + uStack_c + GfxRndSeed2 + uVar6 & 0x1f) < 0x11) {
            uVar8 = uVar9 >> 0x10;
            uVar9 = uVar9 & 0xffff0000;
            uVar7 = uVar3 + uStack_c + GfxRndSeed2 + uVar6 & 0x1f;
            gfx_03.seg = uVar6 + ((int)((uint)*(byte *)((uVar3 + uStack_c + GfxRndSeed2 + uVar6 >> 5
                                                        ) + uStack_c + GfxRndSeed2 & 0xff) * 0x25)
                                 >> 8) + 3;
            gfx_03.ofs = ((undefined2 *)&tmstrsSprites5Seg)[uVar7 * 2];
            ovr_blitGfxRect(gfx_03,iStack_a + 0x10,recordIndex,
                            (brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,SUB41(uVar8,0),
                            ((undefined2 *)&tmstrsSprites5Ofs)[uVar7 * 2]);
          }
          if ((((uVar3 + uStack_c) - GfxRndSeed2) - uVar6 & 0xf) < 7) {
            uVar8 = uVar9 >> 0x10;
            uVar9 = uVar9 & 0xffff0000;
            uVar7 = ((uVar3 + uStack_c) - GfxRndSeed2) - uVar6 & 0xf;
            gfx_04.seg = uVar6 + ((int)((uint)*(byte *)((((((uVar3 + uStack_c) - GfxRndSeed2) -
                                                           uVar6 >> 4) + uStack_c) - GfxRndSeed2) +
                                                        0xe & 0xff) * 0x25) >> 8) + 3;
            gfx_04.ofs = ((undefined2 *)&tmstrsSprites4Seg)[uVar7 * 2];
            ovr_blitGfxRect(gfx_04,iStack_a + 0x10,recordIndex,
                            (brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,SUB41(uVar8,0),
                            ((undefined2 *)&tmstrsSprites4Ofs)[uVar7 * 2]);
          }
          uVar8 = uVar9 & 0xffff0000;
          uVar7 = (uVar3 + 5) % 7;
          gfx_05.seg = in_stack_00000004 + 4;
          gfx_05.ofs = ((undefined2 *)&tmstrsSprites3Seg)[uVar7 * 2];
          ovr_blitGfxRect(gfx_05,iStack_a + 0xd,recordIndex,
                          (brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,SUB41(uVar9 >> 0x10,0),
                          ((undefined2 *)&tmstrsSprites3Ofs)[uVar7 * 2]);
          uVar9 = uVar8 & 0xffff0000;
          gfx_06.seg = in_stack_00000004 + 6;
          gfx_06.ofs = ((undefined2 *)&tmstrsSprites3Seg)[(uVar3 % 7) * 2];
          ovr_blitGfxRect(gfx_06,iStack_a + 0xd,recordIndex,
                          (brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,SUB41(uVar8 >> 0x10,0),
                          ((undefined2 *)&tmstrsSprites3Ofs)[(uVar3 % 7) * 2]);
          uVar8 = uVar9 & 0xffff0000;
          uVar7 = (uVar3 + 2) % 7;
          gfx_07.seg = in_stack_00000004 + 0x18;
          gfx_07.ofs = ((undefined2 *)&tmstrsSprites3Seg)[uVar7 * 2];
          ovr_blitGfxRect(gfx_07,iStack_a + 0xd,recordIndex,
                          (brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,SUB41(uVar9 >> 0x10,0),
                          ((undefined2 *)&tmstrsSprites3Ofs)[uVar7 * 2]);
          uVar9 = uVar8 & 0xffff0000;
          uVar7 = uVar3 + 3 & 7;
          gfx_08.seg = in_stack_00000004 + 0x22;
          gfx_08.ofs = ((undefined2 *)&tmstrsSprites2Seg)[uVar7 * 2];
          ovr_blitGfxRect(gfx_08,iStack_a + 0xd,recordIndex,
                          (brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,SUB41(uVar8 >> 0x10,0),
                          ((undefined2 *)&tmstrsSprites2Ofs)[uVar7 * 2]);
          uVar8 = uVar9 & 0xffff0000;
          gfx_09.seg = in_stack_00000004 + 0x1d;
          gfx_09.ofs = ((undefined2 *)&tmstrsSprites2Seg)[(uVar3 & 7) * 2];
          ovr_blitGfxRect(gfx_09,iStack_a + 0xd,recordIndex,
                          (brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,SUB41(uVar9 >> 0x10,0),
                          ((undefined2 *)&tmstrsSprites2Ofs)[(uVar3 & 7) * 2]);
          uVar9 = uVar8 & 0xffff0000;
          gfx_10.seg = in_stack_00000004 + 0x13;
          gfx_10.ofs = ((undefined2 *)&tmstrsSprites1Seg)[(uVar3 % 5) * 2];
          ovr_blitGfxRect(gfx_10,iStack_a + 0xd,recordIndex,
                          (brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,SUB41(uVar8 >> 0x10,0),
                          ((undefined2 *)&tmstrsSprites1Ofs)[(uVar3 % 5) * 2]);
          uVar8 = uVar9 & 0xffff0000;
          gfx_11.seg = in_stack_00000004 + 0x1f;
          gfx_11.ofs = ((undefined2 *)&tmstrsSprites1Seg)[(uVar3 % 5) * 2];
          ovr_blitGfxRect(gfx_11,iStack_a + 0xd,recordIndex,
                          (brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,SUB41(uVar9 >> 0x10,0),
                          ((undefined2 *)&tmstrsSprites1Ofs)[(uVar3 % 5) * 2]);
          iStack_a = x_00;
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
          uVar8 = (ulong)uVar7 << 0x10;
          gfx_00.seg = uVar6;
          gfx_00.ofs = uStack_6;
          ovr_blitGfxRect(gfx_00,x_00,recordIndex,(brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,
                          mirror,uStack_8);
          iStack_a = x_00;
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
        uVar8 = (ulong)uVar7 << 0x10;
        gfx.seg = uVar6;
        gfx.ofs = uStack_6;
        ovr_blitGfxRect(gfx,x_00,recordIndex,(brect_t *)CONCAT22(0x10,(brect_t *)rect),0x0,mirror,
                        uStack_8);
        iStack_a = x_00;
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
  int in_stack_00000004;
  
  uVar2 = 0;
  while( true ) {
    if (GRecordCount <= uVar2) {
      return 0xffff;
    }
    if (((*(int *)(uVar2 * 0x12 + 4) == x) &&
        (iVar1 = *(int *)(uVar2 * 0x12 + 2),
        in_stack_00000004 <= (int)(iVar1 + (uint)*(byte *)(uVar2 * 0x12 + 7) + -1))) &&
       (iVar1 <= in_stack_00000004)) break;
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
  byte bVar3;
  undefined4 uVar4;
  bool bVar5;
  uint uVar6;
  undefined2 uVar7;
  uint uVar8;
  
  bVar2 = *(byte *)(recordIndex * 0x12 + 9);
  uVar8 = (uint)bVar2;
  uVar4 = *(undefined4 *)((uint)bVar2 << 2);
  if (*(char *)((int)uVar4 + 0x3f) == '\0') {
    uVar6 = ovr_alignUp4();
    uVar4 = *(undefined4 *)((uVar8 & 0xff) << 2);
    bVar3 = *(byte *)((int)uVar4 + 0x3f);
    uVar4 = *(undefined4 *)((uVar8 & 0xff) << 2);
    uVar8 = 0;
    for (bVar2 = 0; bVar2 < 4; bVar2 = bVar2 + 1) {
      uVar8 = uVar8 | ((short (*) [60] [148])GMapFlags)[-1][*(int *)(recordIndex * 0x12 + 4) + 0x3b]
                      [uVar6 + bVar2 + 0x92] & 0x3000U;
    }
    if ((((*(byte *)(recordIndex * 0x12 + 0xd) & 3) != 1) ||
        (uVar8 != 0x1000 << ((*(byte *)((int)uVar4 + 0x3f) ^ 1) & 0x1f))) ||
       (bVar5 = ovr_ovc24_textArena(), bVar5)) {
      if (((*(byte *)(recordIndex * 0x12 + 0xd) & 1) == 0) &&
         ((0x1000 << (bVar3 & 0x1f) & uVar8) != 0)) {
        pbVar1 = (byte *)(recordIndex * 0x12 + 0xd);
        *pbVar1 = *pbVar1 | 1;
      }
    }
    else {
      uVar7 = ovc23_isCursorAt();
      if ((char)uVar7 != '\0') {
        ovr_say();
      }
      if (recordIndex + 1U < GRecordCount) {
        _fmemmove((char *)CONCAT22(0x21f2,(char *)(recordIndex * 0x12)),
                  (char *)CONCAT22(0x21f2,(char *)(recordIndex * 0x12 + 0x12)),
                  ((GRecordCount - recordIndex) + -1) * 0x12);
      }
      GRecordCount = GRecordCount - 1;
      ovc23_textAdlibNone();
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
  uint uVar2;
  int iVar3;
  byte bVar4;
  undefined1 uVar7;
  int iVar5;
  uint uVar6;
  int unaff_DI;
  int in_stack_00000004;
  
  iVar3 = in_stack_00000004;
  cVar1 = *(char *)((y & 0xffU) * 0x27 + 0x11e);
  if (cVar1 == '\0') {
    uVar6 = 0;
  }
  else if (cVar1 == '\x01') {
    bVar4 = ovr_ovc45_getUnitType(x + -1,unaff_DI,in_stack_00000004);
    uVar7 = (undefined1)((uint)bVar4 * 0x27 >> 8);
    if (*(char *)((uint)bVar4 * 0x27 + 0x11e) == '\x02') {
      ovc23_placeBuilding(x,CONCAT11(uVar7,(char)y + '\x02'),bldType,(uint8_t)unaff_DI,iVar3);
    }
    else {
      ovc23_placeBuilding(x,CONCAT11(uVar7,(char)y),bldType,(uint8_t)unaff_DI,iVar3);
    }
    bVar4 = ovr_ovc45_getUnitType(x,unaff_DI,iVar3 + -1);
    iVar5 = (uint)bVar4 * 0x27;
    if (*(char *)(iVar5 + 0x11e) == '\x02') {
      uVar6 = (uint)iVar5 >> 8;
      iVar5 = iVar3 + -1;
      ovc23_placeBuilding(x,CONCAT11((char)uVar6,bVar4 + 1),bldType,(uint8_t)unaff_DI,iVar5);
    }
    uVar6 = CONCAT11((char)((uint)iVar5 >> 8),1);
  }
  else if (cVar1 == '\x02') {
    bVar4 = ovr_ovc45_getUnitType(x,unaff_DI,in_stack_00000004 + 1);
    uVar7 = (undefined1)((uint)bVar4 * 0x27 >> 8);
    if (*(char *)((uint)bVar4 * 0x27 + 0x11e) == '\x01') {
      ovc23_placeBuilding(x,CONCAT11(uVar7,(char)y + '\x01'),bldType,(uint8_t)unaff_DI,iVar3);
    }
    else {
      ovc23_placeBuilding(x,CONCAT11(uVar7,(char)y),bldType,(uint8_t)unaff_DI,iVar3);
    }
    bVar4 = ovr_ovc45_getUnitType(x + 1,unaff_DI,iVar3);
    iVar5 = (uint)bVar4 * 0x27;
    if (*(char *)(iVar5 + 0x11e) == '\x01') {
      uVar6 = (uint)iVar5 >> 8;
      iVar5 = x + 1;
      ovc23_placeBuilding(iVar5,CONCAT11((char)uVar6,bVar4 + 2),bldType,(uint8_t)unaff_DI,iVar3);
    }
    uVar6 = CONCAT11((char)((uint)iVar5 >> 8),1);
  }
  else if (cVar1 == '!') {
    bVar4 = ovr_ovc45_getUnitType(x,unaff_DI,in_stack_00000004 + -1);
    uVar6 = (uint)bVar4 * 0x27;
    if (*(char *)(uVar6 + 0x11e) == '\x02') {
      uVar2 = uVar6 >> 8;
      uVar6 = iVar3 - 1;
      ovc23_placeBuilding(x,CONCAT11((char)uVar2,bVar4 + 1),bldType,(uint8_t)unaff_DI,uVar6);
    }
    uVar6 = uVar6 & 0xff00;
  }
  else if (cVar1 == '\"') {
    bVar4 = ovr_ovc45_getUnitType(x + 1,unaff_DI,in_stack_00000004);
    uVar6 = (uint)bVar4 * 0x27;
    if (*(char *)(uVar6 + 0x11e) == '\x01') {
      uVar2 = uVar6 >> 8;
      uVar6 = x + 1;
      ovc23_placeBuilding(uVar6,CONCAT11((char)uVar2,bVar4 + 2),bldType,(uint8_t)unaff_DI,iVar3);
    }
    uVar6 = uVar6 & 0xff00;
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}



/* 55fe:2da3 */

/* Scans four columns from alignUp4(x) for a cell with clear low flag bits and returns its x, else
   -1. */

int __cdecl16far ovc23_findClearColumn(int x,int y,...)

{
  uint uVar1;
  int iVar2;
  int unaff_DI;
  int in_stack_00000004;
  
  if (((*(short (*) [60] [148])GMapFlags)[x + 1][in_stack_00000004] & 3U) != 0) {
    uVar1 = ovr_alignUp4(unaff_DI,in_stack_00000004);
    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
      if (((*(short (*) [60] [148])GMapFlags)[x][uVar1 + iVar2 + 0x92] & 3U) == 0) {
        return uVar1 + iVar2 + -2;
      }
    }
    in_stack_00000004 = -1;
  }
  return in_stack_00000004;
}



/* 55fe:2e2b */

/* [R7] body shape: compute */

int __cdecl16far ovc23_compute2(int x,uint16_t y,...)

{
  int iVar1;
  int iVar2;
  int unaff_DI;
  int in_stack_00000004;
  
  iVar1 = in_stack_00000004;
  iVar2 = ovc23_findClearColumn(x,unaff_DI,in_stack_00000004);
  if (iVar2 < 0) {
    iVar2 = iVar1;
  }
  return iVar2;
}



/* 55fe:2e4c */

/* Drowns the units at (x,y): marks the cell and reports each drowning. */

void __cdecl16far ovc23_drownUnitsAt(uint16_t x,uint16_t y)

{
  uint *puVar1;
  char *pcVar2;
  char *arg1;
  int iVar3;
  uint16_t unaff_DI;
  undefined2 uVar4;
  char *unaff_SS;
  uint16_t uVar5;
  undefined4 uVar6;
  uint8_t text2;
  uint8_t text;
  uint16_t uStack_6;
  byte bStack_3;
  
  puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x);
  *puVar1 = *puVar1 | 3;
  iVar3 = EntityCount;
  while (iVar3 = iVar3 + -1, -1 < iVar3) {
    uVar4 = (undefined2)((ulong)Entities >> 0x10);
    if (((((entity_t *)Entities + iVar3)->base).x == x) &&
       (((entity_t *)Entities)[iVar3].base.y == y)) {
      uStack_6 = ovc23_findClearColumn();
      uVar4 = (undefined2)((ulong)Entities >> 0x10);
      if ((int)uStack_6 < 0) {
        bStack_3 = ((entity_t *)Entities)[iVar3].base.gindex;
        if (*(char *)((int)(char **)GMenuStrings + (uint)bStack_3 * 0x95 + 0x1f) == '\0') {
          uVar6 = CONCAT22(0xa000,y);
          arg1 = (char *)&AgntAnms[0x88].missileDy;
          uVar5 = x;
          pcVar2 = ovr_ovc15_capitalize();
          pcVar2 = ovr_stsprintf((char *)CONCAT22(0x5665,unaff_SS),
                                 (char *)CONCAT22(pcVar2,(char *)"puppetmaker" + 3),arg1,&text,uVar5
                                 ,uVar6);
          ovr_uiNotify((char *)CONCAT22((int)((ulong)uVar6 >> 0x10),arg1),unaff_DI,pcVar2);
        }
        ovr_ovc15_removeEntity();
      }
      else {
        (((entity_t *)Entities + iVar3)->base).x = uStack_6;
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
  int in_stack_00000004;
  
  return in_stack_00000004 + 2U & 0xfffc;
}


