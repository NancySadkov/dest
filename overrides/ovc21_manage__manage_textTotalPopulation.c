char * __cdecl16far manage_textTotalPopulation(byte charIndex,short arg6,char_sheet_t *sheet)

{
  undefined1 stk_bac4;   /* stack slot bac4 */
  undefined1 stk_fe3a;   /* stack slot fe3a */
  uint16_t *puVar1;
  uint8_t *puVar2;
  uint32_t uVar3;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  char cVar4;
  uint16_t uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined1 uVar12;
  byte *pbVar13;
  uint16_t in_DX;
  uint8_t *puVar14;
  entity_t *peVar15;
  entity_t *peVar16;
  char *pcVar17;
  char *count;
  uint16_t uVar18;
  uint16_t unaff_ES;
  uint8_t *unaff_SS;
  bool bVar19;
  uint16_t in_stack_0000000a;
  far_t entries;
  char acStack_1b6 [120];
  char acStack_13e [36];
  uint16_t auStack_11a [42];
  uint8_t bandLabels2;
  uint8_t bandLabels;
  uint16_t auStack_94 [23];
  undefined1 auStack_66 [10];
  uint16_t uStack_5c;
  entity_t *peStack_1e;
  char cStack_1a;
  char cStack_19;
  char cStack_18;
  uint8_t uStack_17;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  uint16_t uStack_10;
  char acStack_e [6];
  uint16_t uStack_8;
  uint32_t auStack_6;   /* hand fix: CONCAT12/13/22 target, read as uint3 */
  uint16_t uStack_4;
  
  dst.seg = (uint16_t)unaff_SS;
  dst.ofs = (uint16_t)&bandLabels;
  F_SCOPY(far_from_u32((uint32_t)(0x24104b06)),dst);
  dst_00.seg = (uint16_t)unaff_SS;
  dst_00.ofs = (uint16_t)&bandLabels2;
  F_SCOPY(far_from_u32((uint32_t)(0x24104b36)),dst_00);
  pbVar13 = (byte *)__C0_ASM_CopyRight + 3;
  dst_01.seg = (uint16_t)unaff_SS;
  dst_01.ofs = (uint16_t)(acStack_e + 4);
  F_SCOPY(far_from_u32((uint32_t)(0x24104b66)),dst_01);
  acStack_e[2] = '\0';
  if (charIndex == 0xff) {
    acStack_e[3] = 0xc;
  }
  else {
    in_DX = 0x217a;
    unaff_ES = (uint16_t)((ulong)*(uint32_t *)((uint)charIndex << 2) >> 0x10);
    if (*(char *)((int)*(uint32_t *)((uint)charIndex << 2) + 0x2f) == -1) {
      acStack_e[3] = 0xc;
    }
    else {
      acStack_e[3] = acStack_e[*(byte *)((int)*(uint32_t *)((uint)charIndex << 2) + 0x2f) + 4];
      in_DX = 0x217a;
      unaff_ES = (uint16_t)((ulong)*(uint32_t *)((uint)charIndex << 2) >> 0x10);
      if (3 < *(byte *)((int)*(uint32_t *)((uint)charIndex << 2) + 0x2f)) {
        acStack_e[2] = '\x01';
      }
    }
  }
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 2)) = 0x2410;
  (*(uint16_t *)((uint8_t *)&(auStack_66))) = 0x50fb;
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 6)) = 0x2410;
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 4)) = 0x54e5;
  peVar15 = (entity_t *)(auStack_66 + 8);
  uStack_5c = 0x2410;
  (*(uint16_t *)((uint8_t *)&(auStack_66) + 8)) = 0x54ed;
  count = (char *)((int)(uint32_t *)&_DATA + 3);
  for (pcVar17 = (char *)0x0; (int)pcVar17 < (int)(uint)(byte)acStack_e[3]; pcVar17 = pcVar17 + 1) {
    if (((int)pcVar17 < 5) || (acStack_e[2] == '\0')) {
      in_DX = *(uint16_t *)(&bandLabels + (int)pcVar17 * 4);
      peVar15 = (entity_t *)(auStack_66 + (int)count * 4);
      *(uint16_t *)(auStack_66 + (int)count * 4 + 2) = auStack_94[(int)pcVar17 * 2];
      (peVar15->base).x = in_DX;
    }
    else {
      unaff_ES = (uint16_t)((ulong)*(uint32_t *)((uint)charIndex << 2) >> 0x10);
      uVar6 = (uint)*(byte *)((int)*(uint32_t *)((uint)charIndex << 2) + 0x2f);
      in_DX = auStack_11a[(int)pcVar17 * 2 + uVar6 * 8];
      peVar15 = (entity_t *)(auStack_66 + (int)count * 4);
      *(uint16_t *)(auStack_66 + (int)count * 4 + 2) = auStack_11a[(int)pcVar17 * 2 + uVar6 * 8 + 1]
      ;
      (peVar15->base).x = in_DX;
    }
    pbVar13 = auStack_66;
    count = count + 1;
  }
  acStack_e[1] = '\x02';
  manage_openTalkWindow();
  acStack_e[0] = '\0';
  if (acStack_e[1] == '\x02') {
    if (ScreenMode == '\0') {
      manage_openTalkWindow();
    }
    TextBlitY = 0xc;
    TextBlitX = 0x11;
    if (charIndex == 0xff) {
      uVar6 = ovr_blitLabel((char *)"Total population.",
                            (uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510));
      *pcVar17 = *pcVar17 + (char)(uVar6 >> 8) + ((undefined1 *)0xfff3 < &stk_fe3a);
      ((dos_psp_t *)((entity_t **)&Entities + uVar6))->jft[0] = 0;
      uVar18 = (uint16_t)((ulong)Entities >> 0x10);
      *(undefined1 *)((int)&((entity_t *)Entities)[(int)pcVar17].base.state + 1) =
           (char)((entity_t *)Entities)[(int)pcVar17].base.flags32;
      if (EntityCount <= pcVar17 + 1) {
        if ((acStack_e[0] != '\0') || (acStack_e[1] != '\0')) {
          if ((*(uint8_t *)((uint8_t *)&(uStack_4) + 1)) == '\0') {
            ovr_stop_audio();
            CurSfxType3 = 0xff;
            ovr_play_sfx(90,0);
          }
          else if (acStack_e[1] == '\0') {
            if (acStack_e[0] != '\0') {
              ovr_play_sfx(37,0);
            }
          }
          else {
            ovr_play_sfx(35,0);
          }
        }
        GGameState = 0x3d;
        pcVar17 = (char *)0x26510;
        if (DebugVerbose != false) {
          pcVar17 = (char *)0x26510;
          printf("%d \r");
        }
        ovr_OVC23_55fe_29a2_entry();
        return pcVar17;
      }
      pcVar17 = (char *)0x1e6;
      ovr_say((char *)"The damaged structures belonging to all leaders are highlighted in red.");
      return pcVar17;
    }
    uStack_10 =(uint16_t)( (char *)((int *)((uint)charIndex * 4))[1]);
    iStack_12 = *(int *)((uint)charIndex * 4);
    uVar5 = Font02.ofs;
    ovr_ovc45_compute9(acStack_1b6,(char *)CONCAT22(iStack_12,unaff_SS),
                       (char *)CONCAT22(Font02.ofs,uStack_10),Font02.seg,'K');
    SUB_5b66_1d94();
    puVar14 = (uint8_t *)((char *)0x26510);
    pcVar17 = ovr_stsprintf(acStack_13e,(char *)CONCAT22(0x550a,unaff_SS),
                            (char *)CONCAT22(*(uint16_t *)
                                              ((uint)*(byte *)(iStack_12 + 0x2f) * 4 + 0xeb),
                                             (char *)0x26510));
    ovr_blitLabel(pcVar17,(uint8_t *)CONCAT22(uVar5,puVar14));
    TextBlitY = TextBlitY + 0xc;
    iVar9 = ovr_font_textWidth((char *)"UNITS");
    TextBlitX = 0x89 - iVar9;
    ovr_blitLabel((char *)"UNITS",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510));
    iVar9 = ovr_font_textWidth((char *)"POPULATION");
    uVar5 = 0xd4 - iVar9;
    TextBlitX = uVar5;
    ovr_blitLabel((char *)"POPULATION",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510));
    iVar9 = 0;
    while( true ) {
      TextBlitY = TextBlitY + 0xc;
      cVar4 = (char)pbVar13;
      if ((int)(uint)(byte)acStack_e[3] <= iVar9) break;
      TextBlitX = 0x11;
      if ((iVar9 < 5) || (acStack_e[2] == '\0')) {
        ovr_blitLabel(*(char **)(&bandLabels + iVar9 * 4),
                      (uint8_t *)CONCAT22(Font02.ofs,(uint8_t *)auStack_94[iVar9 * 2]));
      }
      else {
        uVar6 = (uint)*(byte *)((int)*(uint32_t *)((uint)charIndex << 2) + 0x2f);
        ovr_blitLabel((char *)auStack_11a[iVar9 * 2 + uVar6 * 8],
                      (uint8_t *)
                      CONCAT22(Font02.ofs,(uint8_t *)auStack_11a[iVar9 * 2 + uVar6 * 8 + 1]));
      }
      ovc27_textCharmed();
      ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x4c,CONCAT12(0xd1,unaff_SS)));
      iVar10 = ovr_font_textWidth(acStack_13e);
      TextBlitX = 0x89 - iVar10;
      ovr_blitLabel(acStack_13e,(uint8_t *)CONCAT22(Font02.ofs,unaff_SS));
      ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x4c,CONCAT12(0xd1,unaff_SS)));
      iVar10 = ovr_font_textWidth(acStack_13e);
      uVar5 = 0xd4 - iVar10;
      TextBlitX = uVar5;
      ovr_blitLabel(acStack_13e,(uint8_t *)CONCAT22(Font02.ofs,unaff_SS));
      iVar9 = iVar9 + 1;
    }
    CurSfxType3 = 0x3c;
    entries.seg = (uint16_t)unaff_SS;
    entries.ofs = (uint16_t)auStack_66;
    uVar18 = ovr_ovc28_usesUiInputText(entries,(uint16_t)count,far_from_u32((uint32_t)(0x0)));
    acStack_e[1] = (char)uVar18;
    keyboardInputMode = 0;
    if (((acStack_e[1] != '\0') && (acStack_e[1] != '\x01')) && (acStack_e[1] != -2)) {
      (&stk_bac4)[(int)count] = (&stk_bac4)[(int)count] + cVar4;
      iVar10 = 0x2410;
      do {
        iVar11 = iVar10 * uVar5;
        iVar10 = iVar9;
        if (*(byte *)(iVar9 * 0x34 + 0x22) < *(byte *)(iVar11 + 0x21)) {
          *(undefined1 *)(iVar9 * 0x34 + 0x21) = *(undefined1 *)(iVar9 * 0x34 + 0x22);
        }
        do {
          iVar10 = iVar10 + 1;
          if ((int)(uint)AgntCount <= iVar10) {
            iVar9 = ovr_audio_panFromX((agnt_t *)sheet);
            uVar12 = (undefined1)((uint)iVar9 >> 8);
            ovr_play_sfxU(0x1c);
            return (char *)CONCAT11(uVar12,1);
          }
        } while (*(int *)(iVar10 * 0x34 + 0x1b) != *(int *)(sheet->nameText + 0x1b));
        uVar18 = (uint16_t)((ulong)auStack_6 >> 0x10);
        if (*(byte *)((int)auStack_6 + 0x32) < *(byte *)(iVar10 * 0x34 + 0x22)) {
          *(undefined1 *)(iVar10 * 0x34 + 0x22) = *(undefined1 *)((int)auStack_6 + 0x32);
        }
        uVar5 = 0x34;
        iVar9 = iVar10;
      } while( true );
    }
    if (acStack_e[1] == -2) {
      Cancelled = 1;
    }
    return (char *)0x26510;
  }
  do {
    uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
    peVar16 = (entity_t *)peStack_1e;
    (peVar16->base).target =
         (byte)((int)(uint)*(byte *)((int)&(peVar16->base).owner +
                                    ((int)(uint)(peVar15->base).faction >> 2)) >>
               (((peVar16->base).faction & 3) << 1)) & 3;
    cVar4 = func_0x0004f32d();
    peVar15 = (entity_t *)peStack_1e;
    uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
    if (cVar4 == '\0') {
      (peStack_1e->base).x = (peStack_1e->base).x + (int)*(char *)((peVar15->base).target + 0x885);
      puVar1 = &(peVar15->base).y;
      *puVar1 = *puVar1 + (int)*(char *)((peVar15->base).target + 0x889);
      puVar2 = &(peVar15->base).faction;
      *puVar2 = *puVar2 + 0x1;
    }
    else {
      (peVar15->base).faction = 0x0;
      *(undefined1 *)&(peVar15->base).state = 0;
    }
L_attact_3f0b_1082_1477:
    uStack_17 = 0x1;
    uVar6 = ovr_alignUp4((((entity_t *)peStack_1e)->base).destX);
    uVar7 = ovr_alignUp4((peStack_1e->base).x);
    if (uVar6 == uVar7) {
      uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
      peVar15 = (entity_t *)peStack_1e;
      if ((peVar15->base).destY == (peVar15->base).y) {
        (peVar15->base).destX = 0;
        (peVar15->base).destY = 0;
        if (*(char *)((int)&(peVar15->base).entity + 3) == -1) {
          auStack_6 = CONCAT12(0xff,auStack_6);
        }
        else {
          uVar3 = *(uint32_t *)((uint)*(byte *)((int)&(peVar15->base).entity + 3) << 2);
          auStack_6 = CONCAT12(*(undefined1 *)((int)uVar3 + 0x89),auStack_6);
        }
        uVar3 = auStack_6;
        (*(uint8_t *)((uint8_t *)&(uStack_4))) = (byte)((uint3)auStack_6 >> 0x10);
        bVar19 = (byte)uStack_4 != -1;
        auStack_6 = uVar3;
        if (bVar19) {
          for (uVar6 = 0; uVar6 < SquareRecCount; uVar6 = uVar6 + 1) {
            uVar7 = ovr_alignUp4(*(int *)(uVar6 * 0x13));
            uVar8 = ovr_alignUp4((peStack_1e->base).x);
            if ((uVar7 == uVar8) &&
               (*(uint16_t *)((uint8_t *)&SquareRecs[uVar6] + 2) == (((entity_t *)peStack_1e)->base).y)) {
              func_0x0004f930();
              if (*(uint16_t *)((uint8_t *)&SquareRecs[uVar6] + 2) == GfxRndSeed2) {
                uVar6 = ovr_alignUp4(*(int *)(uVar6 * 0x13));
                uVar7 = ovr_alignUp4(GfxRndSeed);
                if (uVar6 == uVar7) {
                  acStack_e[(byte)uStack_4] = '\x01';
                }
              }
              break;
            }
          }
        }
      }
    }
    if (AgntFlag1 != false) {
      uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
      if ((((peStack_1e->base).x < GfxRndSeed - 2U) || (GfxRndSeed + 1U < (peStack_1e->base).x)) ||
         ((((entity_t *)peStack_1e)->base).y != GfxRndSeed2)) {
        cStack_19 = '\0';
      }
      else {
        cStack_19 = '\x01';
      }
      if ((((uint)auStack_6 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < (uint)auStack_6)) ||
         (GfxRndSeed2 != uStack_8)) {
        cStack_18 = '\0';
      }
      else {
        cStack_18 = '\x01';
      }
      if (cStack_18 != '\0' || cStack_19 != '\0') {
        if (cStack_18 == '\0') {
          ovr_ovc15_clearVisited();
          uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
          peVar15 = (entity_t *)peStack_1e;
          cStack_1a = (char)((ulong)((peVar15->base).animFrame + 0xf) / 0x10);
          if (((peVar15->base).target & 1) == 0) {
            iStack_16 = 0;
          }
          else {
            iStack_16 = (peVar15->base).target - 2;
          }
          while (cStack_1a != '\0') {
            cStack_1a = cStack_1a + -1;
            ovr_ovc15_textArena((int)count);
          }
          cStack_1a = -1;
        }
        else if (cStack_19 == '\0') {
          cStack_1a = (char)((ulong)((((entity_t *)peStack_1e)->base).animFrame + 0xf) / 0x10);
          while (cStack_1a != '\0') {
            cStack_1a = cStack_1a + -1;
            ovr_agnt_usesAgntCount6(Entities + (int)count);
          }
          cStack_1a = -1;
        }
        else if ((cStack_18 != '\0') && (cStack_19 != '\0')) {
          for (cStack_1a = manage_usesLitoa103(); cStack_1a != '\0'; cStack_1a = cStack_1a + -1) {
            uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
            if (((((entity_t *)peStack_1e)->base).target & 1) == 0) {
              iStack_16 = 0;
            }
            else {
              iStack_16 = (((entity_t *)peStack_1e)->base).target - 2;
            }
            pcVar17 = ovr_ovc15_textArena((int)count);
            if (((uint)pcVar17 & 0xff) == 0) break;
          }
        }
      }
    }
    do {
      count = count + 1;
      if (EntityCount <= count) {
        GGameState = 0x3c;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        func_0x0004fcda();
        GGameState = 0x3d;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        ovr_OVC23_55fe_29a2_entry();
        GGameState = 0xc;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        ovr_ovc24_removeOtherEntities(&uStack_17);
        GGameState = 0x1f;
        if (uStack_17 != 0x0) {
          ovr_constr_usesBlitRect();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (uVar6 = 0; (int)uVar6 < 5; uVar6 = uVar6 + 1) {
          if (acStack_e[uVar6] != '\0') {
            ovr_ovc41_usesMiceBlitRect(uVar6);
          }
        }
        GGameState = 0xd;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        ovr_ovc24_checkStrongholds();
        GGameState = 0xe;
        mapDirty = 1;
        return (char *)0x26510;
      }
      uVar18 = (uint16_t)((ulong)Entities >> 0x10);
      peStack_1e = (entity_t *)CONCAT22(uVar18,Entities + (int)count);
      uVar6 = ovr_alignUp4(Entities[(int)count].base.destX);
      uVar7 = ovr_alignUp4((peStack_1e->base).x);
      if ((uVar6 == uVar7) &&
         (uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10),
         (((entity_t *)peStack_1e)->base).destY == (((entity_t *)peStack_1e)->base).y)) {
        manage_usesCurSfxType32();
      }
      unaff_ES = (uint16_t)((ulong)peStack_1e >> 0x10);
      peVar15 = (entity_t *)peStack_1e;
    } while (((peVar15->base).destX == 0 && (peVar15->base).destY == 0) ||
            (*(char *)((int)&(peVar15->base).entity + 1) != '\0'));
    if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)(peVar15->base).gindex * 0x95) & 0x4000)
        == 0) {
      uStack_4 = (uint)((ulong)auStack_6 >> 0x10) & 0xff;
    }
    else {
      auStack_6 = CONCAT13(1,auStack_6);
    }
    auStack_6 = CONCAT22(uStack_4,(peStack_1e->base).x);
    uStack_8 = (peVar15->base).y;
    iStack_12 = CONCAT13(*(undefined1 *)
                           ((int)(char **)GMenuStrings + (uint)(peVar15->base).gindex * 0x95 + 0x1f)
                          ,iStack_12);
  } while ((peVar15->base).faction < (byte)(peVar15->base).state);
  uVar18 = ovr_ovc07_signum((peVar15->base).destX - (peStack_1e->base).x);
  iStack_12 = CONCAT22(uStack_10,uVar18);
  uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
  iStack_14 = ovr_ovc07_signum((((entity_t *)peStack_1e)->base).destY -
                               (((entity_t *)peStack_1e)->base).y);
  if (((iStack_12 == 0) || (uVar5 = ovr_randBelow(2), (char)uVar5 == '\0')) ||
     (cVar4 = sub_OVC21_manage_c_23C2(), cVar4 != '\0')) {
    if ((iStack_14 == 0) || (cVar4 = sub_OVC21_manage_c_23C2(), cVar4 != '\0')) {
      if ((iStack_12 == 0) || (cVar4 = sub_OVC21_manage_c_23C2(), cVar4 != '\0')) {
        uVar6 = ovr_ovc26_usesStExit((int)count);
        if ((char)uVar6 == '\0') {
          uVar6 = ovr_ovc26_usesRandBelow((int)count,(uint16_t)&uStack_17);
          if (((uVar6 & 0xff) == 0) &&
             (*(char *)((int)(char **)GMenuStrings +
                       (uint)(((entity_t *)peStack_1e)->base).gindex * 0x95 + 0x1f) == '\0')) {
            manage_usesCurSfxType32();
          }
        }
        else {
          uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
          peVar15 = (entity_t *)peStack_1e;
          (peVar15->base).target =
               (byte)((int)(uint)*(byte *)((int)&(peVar15->base).owner +
                                          ((int)(uint)(peVar15->base).faction >> 2)) >>
                     (((peVar15->base).faction & 3) << 1)) & 3;
          cVar4 = func_0x0004f32d();
          if (cVar4 == '\0') {
            uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
            peVar15 = (entity_t *)peStack_1e;
            (peStack_1e->base).x =
                 (peStack_1e->base).x + (int)*(char *)((peVar15->base).target + 0x885);
            puVar1 = &(peVar15->base).y;
            *puVar1 = *puVar1 + (int)*(char *)((peVar15->base).target + 0x889);
            puVar2 = &(peVar15->base).faction;
            *puVar2 = *puVar2 + 0x1;
          }
        }
      }
      else {
        (peStack_1e->base).x = (peStack_1e->base).x + iStack_12;
        (((entity_t *)peStack_1e)->base).target = 0x2 - (char)iStack_12;
      }
    }
    else {
      uVar18 = (uint16_t)((ulong)peStack_1e >> 0x10);
      puVar1 = &(((entity_t *)peStack_1e)->base).y;
      *puVar1 = *puVar1 + iStack_14;
      (((entity_t *)peStack_1e)->base).target = (char)iStack_14 + 0x1;
    }
  }
  else {
    (peStack_1e->base).x = (peStack_1e->base).x + iStack_12;
    (((entity_t *)peStack_1e)->base).target = 0x2 - (char)iStack_12;
  }
  goto L_attact_3f0b_1082_1477;
}
