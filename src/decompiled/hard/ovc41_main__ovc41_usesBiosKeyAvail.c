char * __cdecl16far ovc41_usesBiosKeyAvail(char backdropIndex,...)

{
  extern undefined1 _backdropIndex;   /* hand fix: no symbol exists */
  undefined4 uVar1;
  undefined4 uVar2;
  bool bVar3;
  far_t text2;
  far_t gfx;
  far_t text2_00;
  far_t text2_01;
  far_t text2_02;
  far_t gfx_00;
  far_t handle;
  far_t palette;
  far_t gfx_01;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  far_t handle_03;
  far_t handle_04;
  far_t handle_05;
  far_t handle_06;
  far_t handle_07;
  far_t entries;
  char cVar4;
  int iVar5;
  char *pcVar6;
  uint16_t uVar7;
  uint uVar8;
  undefined1 extraout_AH;
  undefined1 uVar10;
  byte *pbVar9;
  uint uVar11;
  char *pcVar12;
  undefined2 uVar13;
  undefined2 in_DX;
  int iVar14;
  undefined2 *unaff_SI;
  int iVar15;
  int unaff_DI;
  undefined2 uVar16;
  uint16_t unaff_SS;
  far_t text1;
  far_t text1_00;
  far_t text1_01;
  far_t text1_02;
  undefined1 uStack0005;
  char in_stack_00000006;
  char in_stack_0000000e;
  char acStack_2cc [214];
  undefined1 auStack_1f6 [100];
  char acStack_192 [274];
  undefined1 auStack_80 [56];
  undefined2 uStack_48;
  undefined2 uStack_46;
  uint16_t uStack_38;
  uint16_t uStack_36;
  uint16_t uStack_34;
  uint16_t uStack_32;
  uint16_t uStack_30;
  uint16_t uStack_2e;
  uint16_t uStack_24;
  uint16_t uStack_22;
  char cStack_1f;
  char cStack_1e;
  char cStack_1d;
  stg_tmp_t *psStack_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined1 auStack_14 [2];
  undefined2 uStack_12;
  undefined2 uStack_10;
  byte bVar17;
  undefined1 uVar18;
  byte bVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  byte bVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  undefined1 uVar25;
  undefined1 uVar26;
  
  bVar22 = 0x6a;
  (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = (char)FontHandle.seg;
  gfx_01.ofs = FontHandle.ofs;
  (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = (char)(FontHandle.seg >> 8);
  uVar7 = FontHandle.seg;
  uVar11 = FontHandle.ofs;
  ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa000c31d)));
  if (in_stack_00000006 != '\0') {
    pcVar12 = (char *)((uint)_backdropIndex & 0xff);
    pbVar9 = (byte *)((uint)_backdropIndex & 0xff);
    if (pbVar9 < (byte *)__C0_ASM_CopyRight) {
      switch((int)pbVar9) {
      case (byte *)0x0:
        return (char *)((int)(undefined4 *)&_DATA + 1);
      case (byte *)0x1:
        ovr_ovc15_usesStExit(*(int *)((int)pbVar9 * 2 + 0x1b));
        return (char *)pbVar9;
      case (byte *)0x2:
        return _backdropIndex;
      }
      if (((uint)_backdropIndex & 2) == 0) {
        ovr_constr_usesBlitRect();
      }
      return pcVar12;
    }
  }
  pcVar12 = (char *)((uint)_backdropIndex & 0xff);
  if ((char *)((int)(undefined4 *)&_DATA + 3U) < pcVar12) {
    if (TextBlitFlag != '\0') {
      ovr_say((char *)0x6e74);
    }
    TextBlitFlag = 0;
    AgntFlag1 = false;
    GGameState = 0x33;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    ovc41_usesAgnt_clear('\x01');
    GGameState = 0x35;
    pcVar12 = 0x2410;   /* hand fix: segment-half slot */
    if (DebugVerbose != false) {
      pcVar12 = 0x2410;   /* hand fix: segment-half slot */
      printf("%d \r");
    }
    return pcVar12;
  }
  uVar16 = 0x6000;
  uVar10 = (undefined1)unaff_SS;
  uVar23 = (undefined1)(unaff_SS >> 8);
  switch((int)pcVar12) {
  case (char *)0x1:
    cVar4 = *(char *)((int)pcVar12 * 2 + 0x3f);
    do {
      if (((cVar4 == '\0') && (0xf7 < (int)unaff_SI)) &&
         (in_DX = 0x2410, ((unit_t *)GUnits)[(int)unaff_SI].level < 8)) {
        uVar13 = 0x195d;
        if ((*(uint *)((uVar11 >> 8) * 0x27 + 0x121) & 0x80) == 0) {
          ovc39_loadArchiveEntry(8);
        }
        else {
          ovc39_loadArchiveEntry(9);
        }
        ovc39_lordOrLady();
        uStack_12 = 0x938f;
        uStack_10 = uVar16;
        pcVar6 = ovr_stsprintf(acStack_2cc);
        uVar10 = (undefined1)uVar13;
        uVar23 = (undefined1)((uint)uVar13 >> 8);
        pcVar12 = pcVar6;
        ovr_drawString(pcVar6);
        (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = uVar10;
        handle_00.ofs = (uint16_t)pcVar12;
        (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = uVar23;
        ovr_stshFree(handle_00);
        return pcVar6;
      }
      do {
        bVar19 = (byte)(uVar11 >> 8);
        if (((bVar22 == 1) && ((int)unaff_SI < 0xf8)) &&
           (in_DX = 0x195d, (*(uint *)((uint)bVar19 * 0x27 + 0x121) & 2) != 0)) {
          ovc39_loadArchiveEntry(10);
          ovc39_lordOrLady();
          uStack_12 = 0x93f9;
          uStack_10 = uVar16;
          pcVar6 = ovr_stsprintf(acStack_2cc);
          uVar10 = (undefined1)in_DX;
          uVar23 = (undefined1)((uint)in_DX >> 8);
          pcVar12 = pcVar6;
          ovr_drawString(pcVar6);
          (*(uint8_t *)((uint8_t *)&(handle_01.seg))) = uVar10;
          handle_01.ofs = (uint16_t)pcVar12;
          (*(uint8_t *)((uint8_t *)&(handle_01.seg) + 1)) = uVar23;
          ovr_stshFree(handle_01);
          return pcVar6;
        }
        if (((bVar22 == 2) && ((int)unaff_SI < 0xf8)) &&
           (in_DX = 0x195d, (*(uint *)((uint)bVar19 * 0x27 + 0x121) & 0x20) != 0)) {
          ovc39_loadArchiveEntry(0xb);
          ovc39_lordOrLady();
          uStack_12 = 0x9463;
          uStack_10 = uVar16;
          pcVar6 = ovr_stsprintf(acStack_2cc);
          uVar10 = (undefined1)in_DX;
          uVar23 = (undefined1)((uint)in_DX >> 8);
          pcVar12 = pcVar6;
          ovr_drawString(pcVar6);
          (*(uint8_t *)((uint8_t *)&(handle_02.seg))) = uVar10;
          handle_02.ofs = (uint16_t)pcVar12;
          (*(uint8_t *)((uint8_t *)&(handle_02.seg) + 1)) = uVar23;
          ovr_stshFree(handle_02);
          return pcVar6;
        }
        if (bVar22 == 3) {
          uVar10 = (undefined1)uVar16;
          uVar23 = (undefined1)((uint)uVar16 >> 8);
          uVar16 = 0x23f1;
          bVar19 = 0x94;
          uVar11 = ovr_ovc45_compute4(uVar7 + unaff_DI);
          uVar7 = CONCAT11(uVar23,uVar10);
          if ((char)uVar11 != '\0') {
            ovc39_loadArchiveEntry(0xc);
            ovc39_lordOrLady();
            uStack_10 = 0x23f1;
            uStack_12 = 0x94c9;
            pcVar6 = ovr_stsprintf(acStack_2cc);
            uVar10 = (undefined1)in_DX;
            uVar23 = (undefined1)((uint)in_DX >> 8);
            pcVar12 = pcVar6;
            ovr_drawString(pcVar6);
            (*(uint8_t *)((uint8_t *)&(handle_03.seg))) = uVar10;
            handle_03.ofs = (uint16_t)pcVar12;
            (*(uint8_t *)((uint8_t *)&(handle_03.seg) + 1)) = uVar23;
            ovr_stshFree(handle_03);
            return pcVar6;
          }
        }
        if (((bVar22 == 4) && ((int)unaff_SI < 0xf8)) &&
           (uVar13 = 0x195d, (*(uint *)((uint)bVar19 * 0x27 + 0x121) & 0x400) != 0)) {
          ovc39_loadArchiveEntry(0xd);
          ovc39_lordOrLady();
          uStack_12 = 0x9533;
          uStack_10 = uVar16;
          pcVar6 = ovr_stsprintf(acStack_2cc);
          uVar10 = (undefined1)uVar13;
          uVar23 = (undefined1)((uint)uVar13 >> 8);
          pcVar12 = pcVar6;
          ovr_drawString(pcVar6);
          (*(uint8_t *)((uint8_t *)&(handle_04.seg))) = uVar10;
          handle_04.ofs = (uint16_t)pcVar12;
          (*(uint8_t *)((uint8_t *)&(handle_04.seg) + 1)) = uVar23;
          ovr_stshFree(handle_04);
          return pcVar6;
        }
        do {
          unaff_DI = unaff_DI + 1;
          while( true ) {
            uVar10 = (undefined1)uVar16;
            uVar23 = (undefined1)((uint)uVar16 >> 8);
            if (unaff_DI < 2) break;
            bVar22 = bVar22 + 1;
            if (3 < bVar22) {
              uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
              uVar2 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
              uVar13 = (undefined2)((ulong)uVar2 >> 0x10);
              iVar14 = (int)uVar2;
              if (*(uint *)((int)uVar1 + 0x4f) <
                  (uint)(*(int *)(iVar14 + 0x4d) * 2 + *(int *)(iVar14 + 0x4d)) >> 1) {
                uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                uVar2 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                if (*(uint *)((int)uVar1 + 0x4f) < *(uint *)((int)uVar2 + 0x4d)) {
                  uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                  uVar2 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                  uVar13 = (undefined2)((ulong)uVar2 >> 0x10);
                  iVar14 = (int)uVar2;
                  if (*(uint *)((int)uVar1 + 0x4f) <
                      (uint)(*(int *)(iVar14 + 0x4d) * 2 + *(int *)(iVar14 + 0x4d)) >> 2) {
                    uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                    uVar2 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                    if (*(uint *)((int)uVar1 + 0x4f) < *(uint *)((int)uVar2 + 0x4d) >> 1) {
                      uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                      uVar2 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                      if (*(uint *)((int)uVar1 + 0x4f) < *(uint *)((int)uVar2 + 0x4d) >> 2) {
                        bVar22 = 5;
                      }
                      else {
                        bVar22 = 4;
                      }
                    }
                    else {
                      bVar22 = 3;
                    }
                  }
                  else {
                    bVar22 = 2;
                  }
                }
                else {
                  bVar22 = 1;
                }
              }
              else {
                bVar22 = 0;
              }
              uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
              uVar13 = (undefined2)((ulong)uVar1 >> 0x10);
              iVar15 = (int)uVar1;
              uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
              iVar14 = *(int *)(iVar15 + 0x62);
              if ((iVar14 < 0) ||
                 ((iVar14 == 0 &&
                  (*(uint *)(iVar15 + 0x60) < (uint)(*(int *)((int)uVar1 + 0x4d) * 0x28))))) {
                uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                uVar13 = (undefined2)((ulong)uVar1 >> 0x10);
                iVar15 = (int)uVar1;
                uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                iVar14 = *(int *)(iVar15 + 0x62);
                if ((iVar14 < 0) ||
                   ((iVar14 == 0 &&
                    (*(uint *)(iVar15 + 0x60) < (uint)(*(int *)((int)uVar1 + 0x4d) * 0x14))))) {
                  uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                  uVar13 = (undefined2)((ulong)uVar1 >> 0x10);
                  iVar15 = (int)uVar1;
                  uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                  iVar14 = *(int *)(iVar15 + 0x62);
                  if ((iVar14 < 0) ||
                     ((iVar14 == 0 &&
                      (*(uint *)(iVar15 + 0x60) < (uint)(*(int *)((int)uVar1 + 0x4d) * 0x3c) >> 2)))
                     ) {
                    uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                    uVar13 = (undefined2)((ulong)uVar1 >> 0x10);
                    iVar15 = (int)uVar1;
                    uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                    iVar14 = *(int *)(iVar15 + 0x62);
                    if ((iVar14 < 0) ||
                       ((iVar14 == 0 &&
                        (*(uint *)(iVar15 + 0x60) < (uint)(*(int *)((int)uVar1 + 0x4d) * 0x14) >> 1)
                        ))) {
                      uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                      uVar13 = (undefined2)((ulong)uVar1 >> 0x10);
                      iVar15 = (int)uVar1;
                      uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                      iVar14 = *(int *)(iVar15 + 0x62);
                      if ((iVar14 < 0) ||
                         ((iVar14 == 0 &&
                          (*(uint *)(iVar15 + 0x60) <
                           (uint)(*(int *)((int)uVar1 + 0x4d) * 0x14) >> 2)))) {
                        uStack_10 = CONCAT11(5,(undefined1)uStack_10);
                      }
                      else {
                        uStack_10 = CONCAT11(4,(undefined1)uStack_10);
                      }
                    }
                    else {
                      uStack_10 = CONCAT11(3,(undefined1)uStack_10);
                    }
                  }
                  else {
                    uStack_10 = CONCAT11(2,(undefined1)uStack_10);
                  }
                }
                else {
                  uStack_10 = CONCAT11(1,(undefined1)uStack_10);
                }
              }
              else {
                uStack_10 = uStack_10 & 0xff;
              }
              if ((*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) < bVar22) {
                bVar22 = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
              }
              uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
              uVar2 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
              uVar13 = (undefined2)((ulong)uVar2 >> 0x10);
              iVar14 = (int)uVar2;
              if (*(uint *)((int)uVar1 + 0x5b) <
                  (uint)(*(int *)(iVar14 + 0x4d) * 2 + *(int *)(iVar14 + 0x4d)) >> 1) {
                uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                uVar2 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                if (*(uint *)((int)uVar1 + 0x5b) < *(uint *)((int)uVar2 + 0x4d)) {
                  uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                  uVar2 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                  uVar13 = (undefined2)((ulong)uVar2 >> 0x10);
                  iVar14 = (int)uVar2;
                  if (*(uint *)((int)uVar1 + 0x5b) <
                      (uint)(*(int *)(iVar14 + 0x4d) * 2 + *(int *)(iVar14 + 0x4d)) >> 2) {
                    uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                    uVar2 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                    if (*(uint *)((int)uVar1 + 0x5b) < *(uint *)((int)uVar2 + 0x4d) >> 1) {
                      uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                      uVar2 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                      if (*(uint *)((int)uVar1 + 0x5b) < *(uint *)((int)uVar2 + 0x4d) >> 2) {
                        bVar19 = 5;
                      }
                      else {
                        bVar19 = 4;
                      }
                    }
                    else {
                      bVar19 = 3;
                    }
                  }
                  else {
                    bVar19 = 2;
                  }
                }
                else {
                  bVar19 = 1;
                }
              }
              else {
                bVar19 = 0;
              }
              bVar17 = 0;
              uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
              pcVar12 = (char *)"halfling castle" + 0xc;
              uVar2 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
              if (*(uint *)((int)uVar1 + 0x54) < (uint)(*(int *)((int)uVar2 + 0x4d) << 1)) {
                uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                pcVar12 = (char *)(((uint)_backdropIndex & 0xff) << 2);
                if (*(uint *)((int)uVar1 + 0x54) < *(uint *)((int)*(undefined4 *)pcVar12 + 0x4d)) {
                  uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                  pcVar12 = (char *)"halfling castle" + 0xc;
                  uVar2 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                  if (*(uint *)((int)uVar1 + 0x54) < *(uint *)((int)uVar2 + 0x4d) >> 1) {
                    pcVar12 = (char *)"halfling castle" + 0xc;
                    uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                    if (*(int *)((int)uVar1 + 0x54) < 0) {
                      uVar1 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                      pcVar12 = (char *)"halfling castle" + 0xc;
                      uVar2 = *(undefined4 *)(((uint)_backdropIndex & 0xff) << 2);
                      if (*(uint *)((int)uVar1 + 0x54) < (uint)-*(int *)((int)uVar2 + 0x4d)) {
                        bVar17 = 5;
                      }
                      else {
                        bVar17 = 4;
                      }
                    }
                    else {
                      bVar17 = 3;
                    }
                  }
                  else {
                    bVar17 = 2;
                  }
                }
                else {
                  bVar17 = 1;
                }
              }
              if (((bVar22 != 0) && (bVar19 <= bVar22)) && (bVar17 <= bVar22)) {
                ovc39_loadArchiveEntry(bVar22 + 0x12);
                ovc39_lordOrLady();
                uStack_12 = 0x9ad8;
                uStack_10 = uVar16;
                pcVar6 = ovr_stsprintf(acStack_2cc);
                uVar10 = SUB21(pcVar12,0);
                uVar23 = (undefined1)((uint)pcVar12 >> 8);
                pcVar12 = pcVar6;
                ovr_drawString(pcVar6);
                (*(uint8_t *)((uint8_t *)&(handle_05.seg))) = uVar10;
                handle_05.ofs = (uint16_t)pcVar12;
                (*(uint8_t *)((uint8_t *)&(handle_05.seg) + 1)) = uVar23;
                ovr_stshFree(handle_05);
                return pcVar6;
              }
              if ((bVar19 != 0) && (bVar17 <= bVar19)) {
                ovc39_loadArchiveEntry(bVar19 + 0xd);
                ovc39_lordOrLady();
                uStack_12 = 0x9b2e;
                uStack_10 = uVar16;
                pcVar6 = ovr_stsprintf(acStack_2cc);
                uVar10 = SUB21(pcVar12,0);
                uVar23 = (undefined1)((uint)pcVar12 >> 8);
                pcVar12 = pcVar6;
                ovr_drawString(pcVar6);
                (*(uint8_t *)((uint8_t *)&(handle_06.seg))) = uVar10;
                handle_06.ofs = (uint16_t)pcVar12;
                (*(uint8_t *)((uint8_t *)&(handle_06.seg) + 1)) = uVar23;
                ovr_stshFree(handle_06);
                return pcVar6;
              }
              if (bVar17 != 0) {
                ovc39_loadArchiveEntry(bVar17 + 0x17);
                ovc39_lordOrLady();
                uStack_12 = 0x9b7b;
                uStack_10 = uVar16;
                pcVar6 = ovr_stsprintf(acStack_2cc);
                uVar10 = SUB21(pcVar12,0);
                uVar23 = (undefined1)((uint)pcVar12 >> 8);
                pcVar12 = pcVar6;
                ovr_drawString(pcVar6);
                (*(uint8_t *)((uint8_t *)&(handle_07.seg))) = uVar10;
                handle_07.ofs = (uint16_t)pcVar12;
                (*(uint8_t *)((uint8_t *)&(handle_07.seg) + 1)) = uVar23;
                ovr_stshFree(handle_07);
                return pcVar6;
              }
              ovc39_lordOrLady();
              uStack_12 = 0x9bb1;
              uStack_10 = uVar16;
              pcVar12 = ovr_stsprintf(acStack_2cc);
              ovr_drawString(pcVar12);
              return pcVar12;
            }
            unaff_DI = -2;
          }
          uVar16 = 0x236f;
          uVar11 = ovr_ovc23_findRecordAt(uVar7 + unaff_DI);
          uVar7 = CONCAT11(uVar23,uVar10);
        } while (uVar11 != 0xffff);
        uVar18 = 0x6f;
        uVar20 = 0x23;
        unaff_SI = (undefined2 *)
                   ovc39_findBuildingAt(CONCAT11(uVar23,uVar10) + unaff_DI,GfxRndSeed2);
        uVar7 = CONCAT11(uVar20,uVar18);
        uVar13 = (undefined2)((ulong)GUnits >> 0x10);
        in_DX = 0x2410;
        bVar19 = ((unit_t *)GUnits)[(int)unaff_SI].unitType;
        uVar11 = CONCAT11(((unit_t *)GUnits + (int)unaff_SI)->bldType,bVar19);
      } while (bVar22 != 0);
      in_DX = 0x217a;
      uVar1 = *(undefined4 *)((uint)bVar19 << 2);
      cVar4 = *(char *)((int)uVar1 + 0x3f);
    } while( true );
  case (char *)0x2:
    LOCK();
    iVar14 = *(int *)((char *)"Too many construction sites." + 0x17 + unaff_DI);
    *(undefined1 **)((char *)"Too many construction sites." + 0x17 + unaff_DI) = &stack0xfffe;
    UNLOCK();
    *(int *)(iVar14 + -2) = unaff_DI;
    iVar15 = 0;
    pcVar12 = (char *)(*(uint16_t *)((uint8_t *)&(PromoteThreshold)));
    for (bVar22 = 0; pcVar6 = (char *)CONCAT11(0x24,GLeaderCount), bVar22 < GLeaderCount;
        bVar22 = bVar22 + 1) {
      pcVar12 = (char *)((uint)bVar22 << 2);
      if ((byte)(&stack0xfffa)[(uint)_backdropIndex & 0xff] <=
          *(byte *)((int)*(undefined4 *)pcVar12 + 0xa5)) {
        for (uVar11 = 0xf8; uVar11 < GUnitCount; uVar11 = uVar11 + 1) {
          pcVar12 = 0x2410;   /* hand fix: segment-half slot */
          uVar16 = (undefined2)((ulong)GUnits >> 0x10);
          if (((unit_t *)GUnits)[uVar11].unitType == bVar22) {
            pcVar12 = 0x2410;   /* hand fix: segment-half slot */
            if (((unit_t *)GUnits)[uVar11].level < 8) {
              *(undefined2 *)(iVar14 + -4) = (uint16_t)(CONCAT11((char)(uVar11 * 9 >> 8),bVar22));
              *(uint *)(iVar14 + -6) = uVar11;
              *(undefined2 *)(iVar14 + -8) = (uint16_t)(0x6000);
              *(undefined2 *)(iVar14 + -10) = (uint16_t)(0x8958);
              iVar5 = season_usesAlignUp42(*(int *)(iVar14 + -6),*(byte *)(iVar14 + -4));
              if ((char)iVar5 != '\0') {
                pcVar12 = 0x2410;   /* hand fix: segment-half slot */
                ((unit_t *)GUnits)[uVar11].level = 8;
                iVar15 = iVar15 + 1;
              }
            }
          }
        }
      }
    }
    if (iVar15 != 0) {
      *(undefined2 *)(iVar14 + -4) = (uint16_t)(0);
      *(undefined2 *)(iVar14 + -6) = (uint16_t)(0x24);
      *(undefined2 *)(iVar14 + -8) = (uint16_t)(0x6000);
      *(undefined2 *)(iVar14 + -10) = (uint16_t)((uint8_t *)SpecialColors + 5);
      ovr_inputUpdate(*(ulong *)(iVar14 + -6));
      *(undefined2 *)(iVar14 + -4) = (uint16_t)(0xa000);
      *(int *)(iVar14 + -6) = iVar15;
      *(undefined2 *)(iVar14 + -8) = (uint16_t)(0x2410);   /* hand fix: segment-half slot */
      *(undefined2 *)(iVar14 + -10) = (uint16_t)(0x89b2);
      uVar16 = ovr_ovc41_pluralSuffix(*(int *)(iVar14 + -6));
      *(undefined2 *)(iVar14 + -6) = (uint16_t)(pcVar12);
      *(undefined2 *)(iVar14 + -8) = (uint16_t)(uVar16);
      *(int *)(iVar14 + -10) = iVar15;
      *(undefined2 *)(iVar14 + -0xc) = (uint16_t)(0x2410);   /* hand fix: segment-half slot */
      *(undefined2 *)(iVar14 + -0xe) = (uint16_t)((char *)"%d building%s repaired.");
      *(uint16_t *)(iVar14 + -0x10) = unaff_SS;
      *(int *)(iVar14 + -0x12) = (int)auStack_80;
      *(char **)((char *)init_textFilename + iVar14) = (char *)"builder\'s hall" + 8;
      *(undefined2 *)(iVar14 + -0x16) = (uint16_t)(0x89c6);
      pcVar6 = ovr_stsprintf((char *)*(undefined2 *)(iVar14 + -0x12),
                             (char *)*(undefined4 *)(iVar14 + -0x10),
                             (char *)*(undefined4 *)(iVar14 + -0xc));
      *(undefined2 *)(iVar14 + -6) = (uint16_t)(pcVar12);
      *(undefined2 *)(iVar14 + -8) = (uint16_t)(pcVar6);
      *(undefined2 *)(iVar14 + -10) = (uint16_t)((char *)"glassworks" + 9);
      *(undefined2 *)(iVar14 + -0xc) = (uint16_t)(0x89d0);
      ovr_uiNotify((char *)*(undefined2 *)(iVar14 + -8),*(uint16_t *)(iVar14 + -6));
    }
    return pcVar6;
  case (char *)0x3:
    (*(uint16_t *)((uint8_t *)&(AgntAnms[0x11]) + 18)) = (*(uint16_t *)((uint8_t *)&(AgntAnms[0x11]) + 18)) + (int)pcVar12 * 2;
    uVar11 = (*(uint16_t *)((uint8_t *)&(_streams[5]) + 3)) * -0xcc;
    ovr_stsprintf(pcVar12);
    pcVar12 = acStack_192;
    entries.seg = unaff_SS;
    entries.ofs = (uint16_t)pcVar12;
    ovr_ovc28_compute2(entries,(uint16_t)unaff_SI);
    if ((char)pcVar12 != '\0') {
      uVar10 = auStack_1f6[((uint)pcVar12 & 0xff) * 2];
      pcVar12 = (char *)CONCAT11((char)((uint)(auStack_1f6 + ((uint)pcVar12 & 0xff) * 2) >> 8),
                                 uVar10);
      uVar1 = *(undefined4 *)((uVar11 & 0xff) << 2);
      *(undefined1 *)((int)uVar1 + 0x85) = uVar10;
    }
    return pcVar12;
  }
  out(*unaff_SI,in_DX);
  backdropIndex = (char)uStack_46;
  uStack0005 = (undefined1)((uint)uStack_46 >> 8);
  uVar25 = 0;
  uVar26 = 0x60;
  uVar11 = 0xa329;
  text1.seg = uStack_22;
  text1.ofs = uStack_24;
  (*(uint8_t *)((uint8_t *)&(text2.seg))) = backdropIndex;
  text2.ofs = uStack_48;
  (*(uint8_t *)((uint8_t *)&(text2.seg) + 1)) = uStack0005;
  ovc40_usesBlitLabel(text1,text2,2,0xf2);
  ovc40_flushInput();
  ovr_ovr_miceButton0PressStates_entry();
  uVar16 = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  uVar13 = *(undefined2 *)BDA_DailyTimeCounter.ofs;
  uVar21 = (undefined1)uVar16;
  uVar24 = (undefined1)((uint)uVar16 >> 8);
  uVar18 = (undefined1)uVar13;
  uVar20 = (undefined1)((uint)uVar13 >> 8);
  if (backdropIndex == '\x04') {
    uVar7 = ovr_inputUpdate(0xb4);
    if (1 < (byte)uVar7) {
      cStack_1d = '\x02';
    }
  }
  else {
    if (cStack_1f < '\0') {
      iVar14 = 0xee;
    }
    else {
      iVar14 = 1;
    }
    cStack_1e = 'w';
    while (cVar4 = cStack_1e + -1, bVar3 = cStack_1e != '\0', cStack_1e = cVar4, bVar3) {
      if ((iVar14 == 100) && (in_stack_0000000e == '\x02')) {
        backdropIndex = (char)marbleCut2Seg;
        uStack0005 = (undefined1)((uint)marbleCut2Seg >> 8);
        (*(uint8_t *)((uint8_t *)&(gfx.seg))) = backdropIndex;
        gfx.ofs = marbleCut2Ofs;
        (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = uStack0005;
        ovr_blitLoadRleGfx(gfx);
        backdropIndex = (char)uStack_36;
        uStack0005 = (undefined1)(uStack_36 >> 8);
        text1_00.seg = uStack_36;
        text1_00.ofs = uStack_38;
        (*(uint8_t *)((uint8_t *)&(text2_00.seg))) = backdropIndex;
        text2_00.ofs = uStack_38;
        (*(uint8_t *)((uint8_t *)&(text2_00.seg) + 1)) = uStack0005;
        ovc40_usesBlitLabel(text1_00,text2_00,0,0xf2);
        backdropIndex = (char)uStack_32;
        uStack0005 = (undefined1)(uStack_32 >> 8);
        text1_01.seg = uStack_32;
        text1_01.ofs = uStack_34;
        (*(uint8_t *)((uint8_t *)&(text2_01.seg))) = backdropIndex;
        text2_01.ofs = uStack_34;
        (*(uint8_t *)((uint8_t *)&(text2_01.seg) + 1)) = uStack0005;
        ovc40_usesBlitLabel(text1_01,text2_01,1,0xf2);
        backdropIndex = (char)uStack_2e;
        uStack0005 = (undefined1)(uStack_2e >> 8);
        uVar25 = 0xd3;
        uVar26 = 0x22;
        uVar11 = 0xa5ad;
        text1_02.seg = uStack_2e;
        text1_02.ofs = uStack_30;
        (*(uint8_t *)((uint8_t *)&(text2_02.seg))) = backdropIndex;
        text2_02.ofs = uStack_30;
        (*(uint8_t *)((uint8_t *)&(text2_02.seg) + 1)) = uStack0005;
        ovc40_usesBlitLabel(text1_02,text2_02,2,0xf2);
      }
      backdropIndex = (char)iVar14;
      ovc40_usesBlitGfx10(backdropIndex,iVar14,
                          (brect_t *)CONCAT13(uVar23,CONCAT12(uVar10,auStack_14)));
      uVar7 = ovr_biosKeyAvail();
      if ((char)uVar7 != '\0') {
        uVar7 = ovr_gameProcessKey();
        if (uVar7 == 0x11b) {
          cStack_1d = '\x02';
          break;
        }
        if (uVar7 == 0x1c0d) break;
      }
      uVar8 = ovr_init2_updateMouseButtons();
      if (uVar8 != 0) break;
      if (rightButtonLatch != '\0') {
        cStack_1d = '\x02';
        break;
      }
      do {
        ovr_audio_usesLDIV_at_();
        if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != CONCAT11(uVar24,uVar21)) break;
      } while (*(int *)BDA_DailyTimeCounter.ofs == CONCAT11(uVar20,uVar18));
      uVar16 = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
      uVar13 = *(undefined2 *)BDA_DailyTimeCounter.ofs;
      uVar21 = (undefined1)uVar16;
      uVar24 = (undefined1)((uint)uVar16 >> 8);
      uVar18 = (undefined1)uVar13;
      uVar20 = (undefined1)((uint)uVar13 >> 8);
      iVar14 = iVar14 + cStack_1f;
    }
    if (cStack_1f < '\x01') {
      ovc40_usesBlitGfx10(0,0,(brect_t *)CONCAT13(uVar23,CONCAT12(uVar10,auStack_14)));
    }
    else {
      ovc40_usesBlitGfx10(0xef,0xef,(brect_t *)CONCAT13(uVar23,CONCAT12(uVar10,auStack_14)));
    }
    ovc40_flushInput();
    rightButtonLatch = '\0';
    if ((in_stack_0000000e == '\x02') || (in_stack_0000000e == '\x03')) {
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
      uVar13 = *(undefined2 *)BDA_DailyTimeCounter.ofs;
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = uVar13;
      if (cStack_1d == '\0') {
        uVar7 = ovr_inputUpdate(0x48);
        cStack_1d = (char)uVar7;
      }
    }
    else {
      backdropIndex = (char)far_t_2000_d3e4.seg;
      uStack0005 = (undefined1)(far_t_2000_d3e4.seg >> 8);
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = backdropIndex;
      gfx_00.ofs = far_t_2000_d3e4.ofs;
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = uStack0005;
      ovr_blitLoadRleGfx(gfx_00);
      MiceProcessed = 0;
      ovr_miceBlitRect((brect_t *)(BlitRects + 1));
      do {
        do {
          ovr_audio_usesLDIV_at_();
          bVar22 = ovr_init2_usesCFGMice((uint16_t *)&stack0xfffc);
          if ((((CONCAT11(extraout_AH,bVar22) != 0) && (0x87 < CONCAT11(uVar26,uVar25))) &&
              (0xb9 < uVar11)) && ((CONCAT11(uVar26,uVar25) < 0xd6 && (uVar11 < 0xc6))))
          goto L_OVC40_69c8_04c6_0AF0;
          if (rightButtonLatch != '\0') {
            cStack_1d = '\x02';
            goto L_OVC40_69c8_04c6_0AF0;
          }
          uVar7 = ovr_biosKeyAvail();
        } while ((char)uVar7 == '\0');
        uVar7 = ovr_gameProcessKey();
        if (uVar7 == 0x11b) {
          cStack_1d = '\x02';
          break;
        }
      } while (uVar7 != 0x1c0d);
    }
  }
L_OVC40_69c8_04c6_0AF0:
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
  ovr_clearMiceProcessed();
  (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)uStack_16;
  handle.ofs = uStack_18;
  (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)uStack_16 >> 8);
  ovr_stshFree(handle);
  psStack_1c = ovc40_usesStshLoadGfx(0xde);
  (*(uint8_t *)((uint8_t *)&(palette.seg))) = (char)uVar13;
  palette.ofs = (uint16_t)psStack_1c;
  (*(uint8_t *)((uint8_t *)&(palette.seg) + 1)) = (char)((uint)uVar13 >> 8);
  uStack_1a = uVar13;
  ovc40_usesVgaSetPalette8bit(palette);
  ovr_stop_audio();
  CurMusicType = 0xff;
  ovr_init_usesBlitGfxRect();
  uVar11 = (uint)GameRunning;
  if (uVar11 == 0) {
    ovc40_usesCalcSeasonPalette('\x01');
  }
  uVar10 = (undefined1)(uVar11 >> 8);
  ovr_ovc28_textHalflingCastle();
  ovr_ovc41_usesGMenuItem();
  ovr_miceBlitRect((brect_t *)(BlitRects + 1));
  return (char *)CONCAT11(uVar10,cStack_1d);
}
