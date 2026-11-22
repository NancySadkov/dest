byte * __cdecl16far ovc23_textAdlibNone(uint partyIndex,uint16_t outFlag,agnt_t *agnt,...)

{
  uint *puVar1;
  int *piVar2;
  uint8_t *puVar3;
  bool bVar4;
  uint32_t uVar5;
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
  uint16_t uVar26;
  char *unaff_SS;
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
  byte bStack_e;
  uint uStack_c;
  uint16_t uStack_a;
  uint16_t uStack_8;
  byte far *uStack_6;   /* was uint32_t: assigned byte * values */
  
  uStack_10 = 0;
  uStack_a = ovr_alignUp4(GfxRndSeed);
  for (iVar24 = 0; iVar24 < 4; iVar24 = iVar24 + 1) {
    in_DX = 0x2410;
    uStack_10 = uStack_10 |
                ((short (*) [60] [148])GMapFlags)[-1][GfxRndSeed2 + 0x3b][uStack_a + iVar24 + 0x92]
                & 0x3000U;
  }
  cursorRecordFound = '\0';
  _fmemset((void *)&GUnitDescriptions[5].ofs,8,unaff_DI);
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
          *(uint16_t *)(uStack_c * 0x12) = 3;
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
      iVar24 = iVar24 + (uint)*(byte *)((uint)bVar11 * 0x27 + 0x11b);
    }
    cVar10 = *(char *)((uint)bVar11 * 0x27 + 0x132);
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
  switch((uint16_t)pbVar14)   /* hand fix: case values are ints */ {
  case (uint16_t)0x0:
    *(char *)((int)pbVar14 * 2) = *(char *)((int)pbVar14 * 2) + (char)(in_DX >> 8);
    uStack_c = (uint)(byte)((byte)uVar15 & (byte)*(uint16_t *)(&stack0x02c2 + iVar24));
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
        uVar5 = *(uint32_t *)((partyIndex & 0xff) << 2);
        ovr_blitLabel((char *)auStackY_11a[iVar25 * 2 + (uint)*(byte *)((int)uVar5 + 0x2f) * 8]);
      }
      ovc27_textCharmed();
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
        uVar26 = (uint16_t)((ulong)uStack_6 >> 0x10);
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
      if (*(uint *)((int)*(uint32_t *)(uStack_a << 2) + 0x47) < 10) {
        ovc25_usesAlignUp43((byte)uStack_a,10,
                            *(uint16_t *)((int)*(uint32_t *)(uStack_a << 2) + 0x39),
                            *(uint16_t *)((int)*(uint32_t *)(uStack_a << 2) + 0x3b),'\0');
        *(undefined1 *)((int)*(uint32_t *)(uStack_a << 2) + 0x4a) = 0;
      }
      else {
        *(undefined1 *)((int)*(uint32_t *)(uStack_a << 2) + 0x4a) = 0;
        iVar25 = ovc25_compute1(*(byte *)((int)*(uint32_t *)(uStack_a << 2) + 0x3e));
        uStack_6 = (byte *)CONCAT22(iVar25,(byte *)uStack_6);
        if ((int)(uint)PlayerCount < iVar25) {
          uVar16 = ovr_randBelow(0x28);
          iVar25 = *(int *)((int)*(uint32_t *)(uStack_a << 2) + 0x39) + -0x14 + (uVar16 & 0xff);
          (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)(unsigned long)(byte *)iVar25;
          if (iVar25 < 4) {
            (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)(unsigned long)(byte *)0x4;
          }
          if (0x8c < (int)(byte *)uStack_6) {
            uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),0x8b);
          }
          uVar16 = ovr_randBelow(0x14);
          uStack_8 =(uint16_t)( (byte *)(*(int *)((int)*(uint32_t *)(uStack_a << 2) + 0x3b) + -10 +
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
                  (*(char *)((int)*(uint32_t *)(uStack_a * 4) + 0x3d) == '\0'));
          ovc25_intelAttackingNotice((byte)uStack_a);
          if (*(int *)((int)*(uint32_t *)(uStack_a << 2) + 0x4b) == -1) {
            uVar15 = 0xffff;
          }
          else {
            iVar24 = *(int *)((int)*(uint32_t *)(uStack_a << 2) + 0x4b);
            uVar26 = (uint16_t)((ulong)Entities >> 0x10);
            uVar15 = *(int *)((int)*(uint32_t *)(uStack_a << 2) + 0x39) -
                     (((entity_t *)Entities + iVar24)->base).x;
            uVar20 = (int)uVar15 >> 0xf;
            uVar18 = *(int *)((int)*(uint32_t *)(uStack_a << 2) + 0x3b) -
                     ((entity_t *)Entities)[iVar24].base.y;
            uVar21 = (int)uVar18 >> 0xf;
            uVar15 = (int)((uVar15 ^ uVar20) - uVar20) / 2 + ((uVar18 ^ uVar21) - uVar21);
          }
          if ((*(int *)((int)*(uint32_t *)(uStack_a << 2) + 0x43) == 0) || (9 < uVar15)) break;
          ovc25_usesEntityCount((byte)uStack_a);
          if (9 < *(uint *)((int)*(uint32_t *)(uStack_a << 2) + 0x47)) {
            uVar26 = (uint16_t)((ulong)Entities >> 0x10);
            ovc25_usesAlignUp43((byte)uStack_a,5,(((entity_t *)Entities + iVar24)->base).x,
                                ((entity_t *)Entities)[iVar24].base.y,'\x01');
          }
          ovc25_usesAlignUp43((byte)uStack_a,10,
                              *(uint16_t *)((int)*(uint32_t *)(uStack_a << 2) + 0x39),
                              *(uint16_t *)((int)*(uint32_t *)(uStack_a << 2) + 0x3b),'\0');
          *(undefined1 *)((int)*(uint32_t *)(uStack_a << 2) + 0x4a) = 1;
        }
        if ((*(char *)((int)*(uint32_t *)(uStack_a << 2) + 0x49) == -1) ||
           ((*(byte *)((int)*(uint32_t *)(uStack_a << 2) + 0x5d) & 1) == 0)) break;
        ovc25_usesEntityCount((byte)uStack_a);
        bVar9 = *(byte *)((int)*(uint32_t *)(uStack_a << 2) + 0x49);
        if (0xe < *(uint *)((int)*(uint32_t *)(uStack_a << 2) + 0x47)) {
          ovc25_usesAlignUp42((byte)uStack_a,10,
                              *(uint16_t *)((int)*(uint32_t *)((uint)bVar9 << 2) + 0x39),
                              *(uint16_t *)((int)*(uint32_t *)((uint)bVar9 << 2) + 0x3b),
                              *(uint16_t *)((int)*(uint32_t *)(uStack_a << 2) + 0x39),
                              *(uint16_t *)((int)*(uint32_t *)(uStack_a << 2) + 0x3b));
          if (*(char *)((int)*(uint32_t *)(uStack_a << 2) + 0x4a) != '\x02') {
            ovr_alignUp4(*(int *)((int)*(uint32_t *)((uint)bVar9 << 2) + 0x39));
            uStackY_2a = 0x2379;
            uStackY_2c = 0xc5d4;
            pcVar19 = ovr_stsprintf(acStackY_68,(char *)CONCAT22(0x58c0,unaff_SS));
            ovr_uiNotify(pcVar19);
          }
        }
        ovc25_usesAlignUp43((byte)uStack_a,0xf,
                            *(uint16_t *)((int)*(uint32_t *)(uStack_a << 2) + 0x39),
                            *(uint16_t *)((int)*(uint32_t *)(uStack_a << 2) + 0x3b),'\0');
        *(undefined1 *)((int)*(uint32_t *)(uStack_a << 2) + 0x4a) = 2;
      }
    } while( true );
  case (byte *)0x4:
    if ((byte)uStack_8 < ListCount) {
      uVar26 = (uint16_t)((ulong)GUnits >> 0x10);
      uStack_a = ((unit_t *)GUnits)[*(int *)(((uint)uStack_8 & 0xff) * 2 + -0x6d44)].x;
      uStack_c = ((unit_t *)GUnits)[*(int *)(((uint)uStack_8 & 0xff) * 2 + -0x6d44)].y;
    }
    else {
      uVar5 = *(uint32_t *)((partyIndex & 0xff) << 2);
      uStack_a = *(uint16_t *)((int)uVar5 + 0x39);
      uVar5 = *(uint32_t *)((partyIndex & 0xff) << 2);
      uStack_c = *(uint16_t *)((int)uVar5 + 0x3b);
    }
    uVar5 = *(uint32_t *)((partyIndex & 0xff) << 2);
    uVar26 = (uint16_t)((ulong)uVar5 >> 0x10);
    iVar25 = (int)uVar5;
    iVar24 = *(int *)(iVar25 + 0x58);
    if ((iVar24 < 1) && ((iVar24 < 0 || (*(uint *)(iVar25 + 0x56) < 10)))) {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(byte *)uStack_6);
    }
    else {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((byte *)uStack_6);
    }
    uVar5 = *(uint32_t *)((partyIndex & 0xff) << 2);
    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)*(byte *)((int)uVar5 + 0x3e) * 0x95) &
        0x80) == 0) {
      uStack_6 = (byte *)(ulong)(uint3)uStack_6;
    }
    else {
      uStack_6 = (byte *)CONCAT13(3,(uint3)uStack_6);
    }
    uVar5 = *(uint32_t *)((partyIndex & 0xff) << 2);
    if ((*(byte *)((int)uVar5 + 0x5d) & 2) != 0) {
      uStack_6 = (byte *)((ulong)uStack_6 | 0x1000000);
    }
    puVar13 = (uint32_t *)((partyIndex & 0xff) << 2);
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
      if (pbVar14 != (byte *)((int)(uint32_t *)&_DATA + 1U)) {
        return pbVar14;
      }
      uVar15 = ovc22_usesRandBelow((byte)partyIndex,uStack_a,uStack_c);
      if (uVar15 == 0) {
        uVar5 = *(uint32_t *)((partyIndex & 0xff) << 2);
        uStack_a = *(uint16_t *)((int)uVar5 + 0x39);
        uVar5 = *(uint32_t *)((partyIndex & 0xff) << 2);
        uStack_c = *(uint16_t *)((int)uVar5 + 0x3b);
      }
      else {
        if ((*(uint *)((uint8_t *)&BuildingTypes[uVar15] + 19) & 0x60) == 0) {
          uVar5 = *(uint32_t *)((partyIndex & 0xff) << 2);
          uVar26 = (uint16_t)((ulong)uVar5 >> 0x10);
          iVar25 = (int)uVar5;
          iVar24 = *(int *)(iVar25 + 0x58);
          if ((iVar24 < 0) ||
             ((iVar24 == 0 && (*(uint *)(iVar25 + 0x56) < *(uint *)((uint8_t *)&BuildingTypes[uVar15] + 23))))) {
            uVar5 = *(uint32_t *)((partyIndex & 0xff) << 2);
            uVar26 = (uint16_t)((ulong)uVar5 >> 0x10);
            iVar24 = (int)uVar5;
            *(uint16_t *)(iVar24 + 0x58) = 0;
            *(uint16_t *)(iVar24 + 0x56) = 0;
          }
          else {
            uVar20 = *(uint *)((uint8_t *)&BuildingTypes[uVar15] + 23);
            uVar5 = *(uint32_t *)((partyIndex & 0xff) << 2);
            uVar26 = (uint16_t)((ulong)uVar5 >> 0x10);
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
    uVar5 = *(uint32_t *)((partyIndex & 0xff) << 2);
    if (*(char *)((int)uVar5 + 0x3f) == '\0') {
      uVar5 = *(uint32_t *)((partyIndex & 0xff) << 2);
      uVar6 = *(uint32_t *)((partyIndex & 0xff) << 2);
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
          uVar26 = (uint16_t)((ulong)Entities >> 0x10);
          bVar9 = ((entity_t *)Entities)[uStack_a].base.gindex;
          pbVar14 = (byte *)(uint)*(byte *)((int)(char **)GMenuStrings + (uint)bVar9 * 0x95 + 0x1f);
          if (pbVar14 == (byte *)0x0) {
            alignUp4((((entity_t *)Entities + iVar24)->base).x);
            uVar26 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + (uint)bVar9 * 0x95);
            pbVar14 = (byte *)ovr_fmVsprintf("Intelligence reports %s unit fleeing from battle. (%d, %d)"
                                             ,(char *)CONCAT13((char)((uint)uVar26 >> 8),
                                                               CONCAT12((char)uVar26,
                                                                        *(uint16_t *)
                                                                         ((int)&worldMenuLabels[0].
                                                                                seg + 1 +
                                                                         (uint)bVar9 * 0x95))));
            ovr_uiNotify((char *)pbVar14);
          }
        }
        else {
          if ((byte *)(uint)Entities[iVar25].base.animFrame <= uStack_8) {
            uStack_8 =(uint16_t)(unsigned long)(byte *)(uint)Entities[iVar25].base.animFrame;
          }
          Entities[iVar25].base.animFrame = Entities[iVar25].base.animFrame - (byte)uStack_8;
          ovr_ovc41_compute4(&Entities[iVar25].base,(byte)((ulong)Entities >> 0x10));
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
              alignUp4((((entity_t *)Entities + iVar24)->base).x);
              iVar12 = (uint)((entity_t *)Entities)[iVar25].base.gindex * 0x95;
              uVar26 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar12);
              pcVar19 = ovr_fmVsprintf("Intelligence reports %s unit infected with disease. (%d, %d)"
                                       ,(char *)CONCAT13((char)((uint)uVar26 >> 8),
                                                         CONCAT12((char)uVar26,
                                                                  *(uint16_t *)
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
                  uVar26 = (uint16_t)((ulong)Entities >> 0x10);
                  if (((entity_t *)Entities)[iVar25].base.animFrame != 0x0) {
                    puVar3 = &((entity_t *)Entities)[iVar25].base.animFrame;
                    *puVar3 = *puVar3 + 0xff;
                  }
                }
                alignUp4((((entity_t *)Entities + iVar24)->base).x);
                iVar24 = (uint)((entity_t *)Entities)[iVar25].base.gindex * 0x95;
                uVar26 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar24);
                pbVar14 = (byte *)ovr_fmVsprintf("Intelligence reports %s unit drained of energy. (%d, %d)"
                                                 ,(char *)CONCAT13((char)((uint)uVar26 >> 8),
                                                                   CONCAT12((char)uVar26,
                                                                            *(uint16_t *)
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
    uVar26 = (uint16_t)((ulong)Entities >> 0x10);
    peVar22 = (entity_t *)Entities;
    if (*(char *)((int)(char **)GMenuStrings + (uint)peVar22[iVar24].base.gindex * 0x95 + 0x1f) ==
        (char)uStack_10) {
      if (peVar22[iVar24].base.level < bStackY_2d) {
L_OVC24_5943_026e_0772:
        uVar26 = (uint16_t)((ulong)Entities >> 0x10);
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
