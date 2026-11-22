char * __cdecl16far chargen_switch(uint16_t index)

{
  uint16_t *puVar1;
  uint8_t *puVar2;
  uint *puVar3;
  int *piVar4;
  byte *pbVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  far_t entries;
  far_t entries_00;
  far_t handle;
  char cVar8;
  char cVar9;
  bool bVar10;
  bool bVar11;
  undefined2 uVar12;
  uint16_t uVar13;
  uint uVar14;
  uint uVar15;
  char *pcVar16;
  uint32_t *puVar17;
  far_t far *pfVar18;
  uint32_t *puVar19;
  far_t far *pfVar20;
  char_sheet_t *pcVar21;
  char *pcVar22;
  int iVar23;
  int iVar24;
  undefined1 uVar25;
  undefined2 in_CX;
  uint16_t uVar26;
  undefined2 in_DX;
  entity_t *peVar27;
  far_t far *unaff_BP;
  char *unaff_SI;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  uint32_t uVar28;
  uint16_t uVar29;
  char *in_stack_00000000;
  agnt_t *paStack0008;
  undefined2 uStack000a;
  char acStack_1b6 [120];
  char acStack_13e [36];
  undefined2 auStack_11a [66];
  undefined2 auStack_96 [24];
  undefined1 auStack_66 [16];
  char acStack_56 [52];
  undefined2 uStack_22;
  undefined2 uStack_20;
  entity_t *in_stack_0000ffe2;
  undefined2 in_stack_0000ffe4;
  char cVar30;
  uint8_t uVar31;
  undefined1 uVar32;
  undefined1 uVar33;
  undefined1 uVar34;
  char in_stack_0000fff3;
  byte bVar35;
  undefined1 *puVar36;
  undefined1 uVar37;
  byte bVar38;
  undefined1 uVar39;
  
  uVar13 = CONCAT11((char)((uint)in_DX >> 8),(byte)index);
  uVar14 = index & 0xff;
  if (6 < uVar14) {
    return (char *)0x0;
  }
  peVar27 = (entity_t *)(uVar14 * 2);
  cVar9 = (char)unaff_SS;
  bVar38 = (byte)((uint)unaff_SS >> 8);
  switch(uVar14) {
  case 0:
    cVar9 = in(uVar13);
    *unaff_DI = cVar9;
    midpakAd.ofs = (uint16_t)stshStoreFile_2(unaff_BP,in_stack_00000000,index);
    midpakAd.seg = uVar13;
    cmidpakComOfs =(uint16_t)( stshStoreFile_2((far_t *)"cmidpak.com",(char *)MK_FP(0x2410, 0x1),index));
    cmidpakComSeg = uVar13;
    ibmsndComOfs =(uint16_t)( stshStoreFile_2((far_t *)"ibmsnd.com",(char *)MK_FP(0x2410, 0x1),index));
    ibmsndComSeg = uVar13;
    sblasterComOfs =(uint16_t)( stshStoreFile_2((far_t *)"sblaster.com",(char *)MK_FP(0x2410, 0x1),index));
    audioPlaceholder2.seg = 0;
    audioPlaceholder2.ofs = 0;
    sblasterComSeg = uVar13;
    fibmbakComOfs =(uint16_t)( stshStoreFile_2((far_t *)"fibmbak.com",(char *)MK_FP(0x2410, 0x1),index));
    fibmbakComSeg = uVar13;
    pfVar20 = stshStoreFile_2((far_t *)"sbpro.com",(char *)MK_FP(0x2410, 0x1),index);
    sbproComOfs =(uint16_t)( pfVar20);
    sbproComSeg = uVar13;
    sbproComCopyOfs =(uint16_t)( pfVar20);
    sbproComCopySeg = uVar13;
    paudioComOfs =(uint16_t)( stshStoreFile_2((far_t *)"paudio.com",(char *)MK_FP(0x2410, 0x1),index));
    sblasterComCopySeg = sblasterComSeg;
    sblasterComCopyOfs = sblasterComOfs;
    pfVar18 = sblasterComOfs;
    paudioComSeg =(uint16_t)( pfVar20);
    adlibComOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlib.com",(char *)MK_FP(0x2410, 0x1),index));
    adlibComSeg =(uint16_t)( pfVar18);
    adlibgComOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlibg.com",(char *)MK_FP(0x2410, 0x1),index));
    audioPlaceholder3.seg = 0;
    audioPlaceholder3.ofs = 0;
    musDriver0Seg = 0;
    musDriver0Ofs = 0;
    adlibgComSeg =(uint16_t)( pfVar18);
    sbfmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"sbfm.adv",(char *)MK_FP(0x2410, 0x1),index));
    audioPlaceholder0.seg = 0;
    audioPlaceholder0.ofs = 0;
    audioPlaceholder1.seg = 0;
    audioPlaceholder1.ofs = 0;
    sbfmAdvSeg =(uint16_t)( pfVar18);
    sbp2fmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"sbp2fm.adv",(char *)MK_FP(0x2410, 0x1),index));
    sbp2fmAdvSeg =(uint16_t)( pfVar18);
    sbp1fmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"sbp1fm.adv",(char *)MK_FP(0x2410, 0x1),index));
    sbp1fmAdvSeg =(uint16_t)( pfVar18);
    pasfmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"pasfm.adv",(char *)MK_FP(0x2410, 0x1),index));
    pasfmAdvSeg =(uint16_t)( pfVar18);
    pasoplAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"pasopl.adv",(char *)MK_FP(0x2410, 0x1),index));
    pasoplAdvSeg =(uint16_t)( pfVar18);
    adlibAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlib.adv",(char *)MK_FP(0x2410, 0x1),index));
    adlibAdvSeg =(uint16_t)( pfVar18);
    adlibgAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlibg.adv",(char *)MK_FP(0x2410, 0x1),index));
    adlibgAdvSeg =(uint16_t)( pfVar18);
    mt32mpuAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"mt32mpu.adv",(char *)MK_FP(0x2410, 0x1),index));
    mt32mpuAdvSeg =(uint16_t)( pfVar18);
    return (char *)mt32mpuAdvOfs;
  case 1:
    iVar23 = ovr_ovc23_findClearColumn(GfxRndSeed);
    if (iVar23 < 0) {
      ovr_drawTextAt((char *)"You cannot attract units to this location.");
      pcVar16 = (char *)0x26510;
      ((uint8_t *)menuItemRow)[index] = 0x0;
    }
    else {
      uVar31 = 0x6f;
      uVar25 = 0x23;
      bVar38 = (byte)index;
      callResultTemp = func_0x0004f501();
      if (callResultTemp < CONCAT11(uVar25,uVar31)) {
        uVar31 = (uint8_t)callResultTemp;
        uVar25 = (undefined1)(callResultTemp >> 8);
        ((uint8_t *)menuItemRow)[index] = uVar31;
      }
      uVar7 = *(undefined4 *)((uint)bVar38 << 2);
      cVar9 = *(char *)((int)uVar7 + 0x2f);
      pcVar16 = (char *)CONCAT11((char)(((uint)bVar38 << 2) >> 8),cVar9);
      if (cVar9 != -1) {
        ovr_ovc41_pluralSuffix(CONCAT11(uVar25,uVar31));
        pcVar16 = ovr_stsprintf(acStack_56,(char *)CONCAT13(9,CONCAT12(0x21,unaff_SS)));
        ovr_drawTextAt(pcVar16);
      }
    }
    return pcVar16;
  case 2:
    ((int *)StshHandles)[(int)unaff_SI] = uVar14;
    *(undefined2 *)((int)(long *)StshPtrs + (int)unaff_SI * 4 + 2) = 0;
    *(undefined2 *)((long *)StshPtrs + (int)unaff_SI) = 0;
    return unaff_SI;
  case 3:
    for (iVar23 = 0; iVar23 < (int)(uint)GLeaderCount; iVar23 = iVar23 + 1) {
      if (((((char_sheet_t *)((iVar23 << 2)))->active != '\0') &&
          (uVar13 = 0x2410, ((char_sheet_t *)((iVar23 << 2)))->x == GfxRndSeed)) &&
         (uVar13 = 0x2410, ((char_sheet_t *)((iVar23 << 2)))->y == GfxRndSeed2))
      {
        if (GCharLevelsInc != '\0') {
          uVar12 = (undefined2)((ulong)*(undefined4 *)(iVar23 << 2) >> 0x10);
          iVar24 = (int)*(undefined4 *)(iVar23 << 2);
          puVar3 = (uint *)(iVar24 + 0x56);
          uVar14 = *puVar3;
          *puVar3 = *puVar3 + 10000;
          piVar4 = (int *)(iVar24 + 0x58);
          *piVar4 = *piVar4 + (uint)(0xd8ef < uVar14);
          GCharLevelsInc = '\0';
        }
        pfVar18 = manage_settlementScreen((byte)iVar23);
        ovr_stats_openCastlePanel();
        ovr_ovc41_usesGMenuItem();
        return (char *)pfVar18;
      }
    }
    ovr_stats_drawStatsPanel();
    if (PartyCount == 0) {
      pcVar16 = (char *)(uint)CurPartySlot;
      if (PartySize <= CurPartySlot) {
        ovr_ovc41_usesGMenuItem();
        return pcVar16;
      }
      pcVar21 = chargen();
      uVar33 = (undefined1)uVar13;
      uVar34 = (undefined1)(uVar13 >> 8);
      uVar25 = SUB21(pcVar21,0);
      uVar32 = (undefined1)((uint)pcVar21 >> 8);
      pcVar16 = (char *)((uint)pcVar21 | uVar13);
      if (pcVar16 == (char *)0x0) {
        ovr_stats_openCastlePanel();
        ovr_ovc41_usesGMenuItem();
        return pcVar16;
      }
      iVar23 = 0;
      while ((iVar23 < (int)(uint)GLeaderCount &&
             (((char_sheet_t *)((iVar23 << 2)))->statMask != '\0'))) {
        iVar23 = iVar23 + 1;
      }
      if (iVar23 < (int)(uint)GLeaderCount) {
        PartyCount = (char)iVar23 + 1;
        uVar12 = *(undefined2 *)((uint)PartyCount * 4 + -2);
        (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)uVar12;
        handle.ofs = *(undefined2 *)((uint)PartyCount * 4 + -4);
        (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)uVar12 >> 8);
        ovr_stshFree(handle);
      }
      else {
        if (0x4f < GLeaderCount) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x1d);
        }
        PartyCount = GLeaderCount + 1;
        GLeaderCount = PartyCount;
      }
      pbVar5 = (byte *)(CONCAT11(uVar32,uVar25) + 0x28);
      *pbVar5 = *pbVar5 | 0x40;
      *(char *)(CONCAT11(uVar32,uVar25) + 0x51) = PartyCount - 1;
      uVar14 = (uint)PartyCount;
      *(undefined2 *)(uVar14 * 4 + -2) = CONCAT11(uVar34,uVar33);
      *(undefined2 *)(uVar14 * 4 + -4) = CONCAT11(uVar32,uVar25);
      if (CurPartySlot == 0) {
        *(undefined1 *)(CONCAT11(uVar32,uVar25) + 0x86) = 1;
      }
      CurPartySlot = CurPartySlot + 1;
    }
    else {
      manage_openTalkWindow();
      uVar12 = *(undefined2 *)((uint)PartyCount * 4 + -2);
      uVar6 = *(undefined2 *)((uint)PartyCount * 4 + -4);
      uVar33 = (undefined1)uVar12;
      uVar34 = (undefined1)((uint)uVar12 >> 8);
      uVar25 = (undefined1)uVar6;
      uVar32 = (undefined1)((uint)uVar6 >> 8);
      manage_usesLitoa10((char_sheet_t *)CONCAT13(uVar34,CONCAT12(uVar33,uVar6)));
    }
    pcVar16 = ovr_fmVsprintf("Place %s here.",
                             (char *)CONCAT13(uVar34,CONCAT12(uVar33,CONCAT11(uVar32,uVar25))));
    ovr_drawString(pcVar16);
    (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = cVar9;
    entries_00.ofs = (uint16_t)&stack0xfff2;
    (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = bVar38;
    pcVar16 = ovr_uiInputText(entries_00,2);
    pcVar22 = (char *)((uint)pcVar16 & 0xff);
    if (((uint)pcVar16 & 0xff) == 1) {
      pcVar22 = (char *)(PartyCount - 1);
      if (CurPartySlot == 1) {
        ovr_ovc18_checkFortressPlacement('\x02');
      }
      else {
        ovr_ovc18_checkFortressPlacement('\x01');
      }
      ovr_ovc41_usesGMenuItem();
    }
    else {
      ovr_stats_openCastlePanel();
      ovr_ovc41_usesGMenuItem();
    }
    return pcVar22;
  case 5:
    puVar17 = ovr_mkp((uint32_t *)unaff_BP,(uint16_t)(char *)in_stack_00000000,
                      (uint16_t)((ulong)in_stack_00000000 >> 0x10));
    index = (uint16_t)CONCAT22(uVar13,puVar17);   /* hand fix: 16-bit slot keeps the offset */
    if ((char)*(uint8_t *)(uint)index == '\0') {   /* hand fix: deref the offset */
      uVar28 = CONCAT22((int)((ulong)in_stack_00000000 >> 0x10),*(undefined2 *)((int)puVar17 + 7));
      uVar26 = uVar13;
      pfVar18 = fmMalloc((far_t *)*(undefined2 *)((int)puVar17 + 5),uVar28);
      uVar25 = SUB21(pfVar18,0);
      uVar32 = (undefined1)((uint)pfVar18 >> 8);
      if (pfVar18 == (far_t far *)0x0 && uVar26 == 0) {
        puVar17 = (uint32_t *)0x0;
      }
      else {
        uVar29 = (uint16_t)(uVar28 >> 0x10);
        if (*(int *)((int)puVar17 + 0x11) == 0 && *(int *)((int)puVar17 + 0x13) == 0) {
          stshSeek(StshStrongDatHnd,
                   CONCAT22(*(undefined2 *)((int)puVar17 + 3),*(undefined2 *)((int)puVar17 + 1)));
          uVar33 = 0xfd;
          uVar34 = 0x83;
          stshRead();
          uVar28 = CONCAT22(uVar29,*(undefined2 *)((int)puVar17 + 7));
          pfVar18 = ovr_heapMalloc((far_t far *)*(undefined2 *)((int)puVar17 + 5),uVar28);
          uVar29 = (uint16_t)(uVar28 >> 0x10);
          *(uint16_t *)((int)puVar17 + 0x13) = uVar26;
          *(undefined2 *)((int)puVar17 + 0x11) =(uint16_t)( pfVar18);
          if (*(int *)((int)puVar17 + 0x11) == 0 && *(int *)((int)puVar17 + 0x13) == 0) {
            bVar10 = false;
          }
          else {
            memcpy((char *)CONCAT13((char)((uint)*(undefined2 *)((int)puVar17 + 0x13) >> 8),
                                    CONCAT12((char)*(undefined2 *)((int)puVar17 + 0x13),
                                             *(undefined2 *)((int)puVar17 + 0x11))),
                   (char *)CONCAT22(CONCAT11(uVar34,uVar33),(char *)CONCAT11(uVar32,uVar25)),
                   *(word *)((int)puVar17 + 5));
            bVar10 = true;
          }
        }
        else {
          memcpy((char *)CONCAT13((char)(uVar26 >> 8),CONCAT12((char)uVar26,pfVar18)),
                 (char *)CONCAT22(*(undefined2 *)((int)puVar17 + 0x13),
                                  (char *)*(undefined2 *)((int)puVar17 + 0x11)),
                 *(word *)((int)puVar17 + 5));
          bVar10 = true;
        }
        if (bVar10) {
          puVar19 = ovr_mkp((uint32_t *)Stsh_2410_47f6.ofs,Stsh_2410_47f6.seg,uVar29);
          if ((uVar26 != uVar13) || (puVar19 != puVar17)) {
            iVar23 = *(int *)((int)puVar17 + 0xf);
            iVar24 = *(int *)((int)puVar17 + 0xd);
            uVar26 = *(uint16_t *)((int)puVar17 + 0xb);
            uVar29 = *(uint16_t *)((int)puVar17 + 9);
            if (uVar29 != 0 || uVar26 != 0) {
              uVar12 = (undefined2)
                       (CONCAT13((char)(uVar26 >> 8),CONCAT12((char)uVar26,uVar29)) >> 0x10);
              *(int *)(uVar29 + 0xf) = iVar23;
              *(int *)(uVar29 + 0xd) = iVar24;
            }
            if (iVar24 != 0 || iVar23 != 0) {
              uVar12 = (undefined2)
                       (CONCAT13((char)((uint)iVar23 >> 8),CONCAT12((char)iVar23,iVar24)) >> 0x10);
              *(uint16_t *)(iVar24 + 0xb) = uVar26;
              *(uint16_t *)(iVar24 + 9) = uVar29;
              uVar29 = StshCtPtr2.ofs;
              uVar26 = StshCtPtr2.seg;
            }
            StshCtPtr2.seg = uVar26;
            StshCtPtr2.ofs = uVar29;
            uVar26 = Stsh_2410_47f6.ofs;
            *(uint16_t *)((int)puVar17 + 0xf) = Stsh_2410_47f6.seg;
            *(uint16_t *)((int)puVar17 + 0xd) = uVar26;
            *(undefined2 *)((int)puVar17 + 0xb) = 0;
            *(undefined2 *)((int)puVar17 + 9) = 0;
            *(uint16_t far *)((uint8_t far *)MK_FP(Stsh_2410_47f6.seg, Stsh_2410_47f6.ofs) +  0xb) = uVar13;
            *(undefined2 far *)((uint8_t far *)MK_FP(Stsh_2410_47f6.seg, Stsh_2410_47f6.ofs) +  9) =(uint16_t)( puVar17);
            Stsh_2410_47f6.seg = uVar13;
            Stsh_2410_47f6.ofs = (uint16_t)puVar17;
          }
        }
        puVar17 = (uint32_t *)CONCAT11(uVar32,uVar25);
      }
    }
    return (char *)puVar17;
  case 6:
    goto switchD_4000_e2bf_caseD_6;
  }
  if ((uVar14 == 0) && (manage_openTalkWindow(), in_stack_0000fff3 == '\x02')) {
    if (ScreenMode == '\0') {
      manage_openTalkWindow();
    }
    TextBlitY = 0xc;
    TextBlitX = 0x11;
    if ((byte)index == 0xff) {
      cVar9 = -8;
      cVar30 = 'T';
      uVar14 = ovr_blitLabel((char *)"Total population.");
      *unaff_SI = *unaff_SI + (char)(uVar14 >> 8) + ((undefined1 *)0xfff3 < &stack0xfff2);
      *(undefined1 *)((int)*(undefined4 *)(entity_t **)&Entities + uVar14 + 0x18) = 0;
      uVar12 = (undefined2)((ulong)Entities >> 0x10);
      *(undefined1 *)((int)&((entity_t *)Entities)[(int)unaff_SI].base.state + 1) =
           (char)((entity_t *)Entities)[(int)unaff_SI].base.flags32;
      if (unaff_SI + 1 < EntityCount) {
        pcVar16 = (char *)0x1e6;
        ovr_say((char *)"The damaged structures belonging to all leaders are highlighted in red.");
        return pcVar16;
      }
      if ((cVar9 != '\0') || (cVar30 != '\0')) {
        if ((char)((uint)((int)unaff_SI * 0x37) >> 8) == '\0') {
          ovr_stop_audio();
          CurSfxType3 = 0xff;
          ovr_play_sfx(90);
        }
        else if (cVar30 == '\0') {
          if (cVar9 != '\0') {
            ovr_play_sfx(37);
          }
        }
        else {
          ovr_play_sfx(35);
        }
      }
      GGameState = 0x3d;
      pcVar16 = (char *)0x26510;
      if (DebugVerbose != false) {
        pcVar16 = (char *)0x26510;
        printf("%d \r");
      }
      ovr_OVC23_55fe_29a2_entry();
      return pcVar16;
    }
    ovr_ovc45_compute9(acStack_1b6);
    func_0x0005d3f4();
    uStack_20 = 0x23f1;
    uStack_22 = 0x44;
    pcVar16 = ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x55,CONCAT12(10,unaff_SS)));
    ovr_blitLabel(pcVar16);
    TextBlitY = TextBlitY + 0xc;
    iVar23 = ovr_font_textWidth((char *)"UNITS");
    TextBlitX = 0x89 - iVar23;
    ovr_blitLabel((char *)"UNITS");
    iVar23 = ovr_font_textWidth((char *)"POPULATION");
    uVar13 = 0xd4 - iVar23;
    cVar30 = '\x10';
    bVar35 = 0x24;
    TextBlitX = uVar13;
    ovr_blitLabel((char *)"POPULATION");
    iVar23 = 0;
    while( true ) {
      TextBlitY = TextBlitY + 0xc;
      cVar8 = (char)in_CX;
      if ((int)(uint)bVar35 <= iVar23) break;
      TextBlitX = 0x11;
      if ((iVar23 < 5) || (cVar30 == '\0')) {
        ovr_blitLabel((char *)auStack_96[iVar23 * 2]);
      }
      else {
        uVar7 = *(undefined4 *)((index & 0xff) << 2);
        ovr_blitLabel((char *)auStack_11a[iVar23 * 2 + (uint)*(byte *)((int)uVar7 + 0x2f) * 8]);
      }
      func_0x0005f303();
      ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x4c,CONCAT12(0xd1,unaff_SS)));
      iVar24 = ovr_font_textWidth(acStack_13e);
      TextBlitX = 0x89 - iVar24;
      ovr_blitLabel(acStack_13e);
      ovr_stsprintf(acStack_13e,(char *)CONCAT13(0x4c,CONCAT12(0xd1,unaff_SS)));
      iVar24 = ovr_font_textWidth(acStack_13e);
      uVar13 = 0xd4 - iVar24;
      TextBlitX = uVar13;
      cVar30 = cVar9;
      bVar35 = bVar38;
      ovr_blitLabel(acStack_13e);
      iVar23 = iVar23 + 1;
    }
    CurSfxType3 = 0x3c;
    puVar36 = &stack0xfff2;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = cVar9;
    entries.ofs = (uint16_t)auStack_66;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = bVar38;
    uVar12 = ovr_ovc28_usesUiInputText(entries);
    cVar9 = (char)uVar12;
    keyboardInputMode = 0;
    if (((cVar9 != '\0') && (cVar9 != '\x01')) && (cVar9 != -2)) {
      (&stack0xbac4)[(int)unaff_DI] = (&stack0xbac4)[(int)unaff_DI] + cVar8;
      iVar24 = 0x2410;
      do {
        bVar38 = *(byte *)(iVar24 * uVar13 + 0x21);
        uVar25 = (undefined1)(iVar24 * uVar13 >> 8);
        iVar24 = iVar23;
        if (*(byte *)(iVar23 * 0x34 + 0x22) < bVar38) {
          bVar38 = *(byte *)(iVar23 * 0x34 + 0x22);
          uVar25 = (undefined1)((uint)(iVar23 * 0x34) >> 8);
          *(byte *)(iVar23 * 0x34 + 0x21) = bVar38;
        }
        do {
          iVar24 = iVar24 + 1;
          if ((int)(uint)AgntCount <= iVar24) {
            iVar23 = ovr_audio_panFromX(paStack0008);
            uVar25 = (undefined1)((uint)iVar23 >> 8);
            ovr_play_sfxU(0x1c);
            return (char *)CONCAT11(uVar25,1);
          }
        } while (*(uint16_t *)(iVar24 * 0x34 + 0x1b) != paStack0008->owner);
        if ((byte)puVar36[0x32] < *(byte *)(iVar24 * 0x34 + 0x22)) {
          *(undefined1 *)(iVar24 * 0x34 + 0x22) = puVar36[0x32];
        }
        uVar13 = 0x34;
        iVar23 = iVar24;
      } while( true );
    }
    if (cVar9 == -2) {
      Cancelled = 1;
    }
    return (char *)0x26510;
  }
  do {
    (in_stack_0000ffe2->base).target =
         (byte)((int)(uint)*(byte *)((int)&(in_stack_0000ffe2->base).owner +
                                    ((int)(uint)(peVar27->base).faction >> 2)) >>
               (((in_stack_0000ffe2->base).faction & 3) << 1)) & 3;
    cVar9 = func_0x0004f32d();
    if (cVar9 == '\0') {
      (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x =
           (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x +
           (int)*(char *)((in_stack_0000ffe2->base).target + 0x885);
      puVar1 = &(in_stack_0000ffe2->base).y;
      *puVar1 = *puVar1 + (int)*(char *)((in_stack_0000ffe2->base).target + 0x889);
      puVar2 = &(in_stack_0000ffe2->base).faction;
      *puVar2 = *puVar2 + 0x1;
    }
    else {
      (in_stack_0000ffe2->base).faction = 0x0;
      *(undefined1 *)&(in_stack_0000ffe2->base).state = 0;
    }
L_attact_3f0b_1082_1477:
    uVar31 = 0x1;
    uVar14 = ovr_alignUp4((in_stack_0000ffe2->base).destX);
    uVar37 = (undefined1)uVar14;
    uVar39 = (undefined1)(uVar14 >> 8);
    uVar13 = (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x;
    uVar33 = (undefined1)uVar13;
    uVar34 = (undefined1)(uVar13 >> 8);
    uVar25 = 0x79;
    uVar32 = 0x23;
    uVar15 = ovr_alignUp4(uVar13);
    uVar14 = CONCAT11(uVar34,uVar33);
    if ((CONCAT11(uVar39,uVar37) == uVar15) &&
       (uVar14 = CONCAT11(uVar34,uVar33),
       (in_stack_0000ffe2->base).destY == (in_stack_0000ffe2->base).y)) {
      (in_stack_0000ffe2->base).destX = 0;
      (in_stack_0000ffe2->base).destY = 0;
      if (*(char *)((int)&(in_stack_0000ffe2->base).entity + 3) == -1) {
        cVar9 = -1;
      }
      else {
        uVar7 = *(undefined4 *)((uint)*(byte *)((int)&(in_stack_0000ffe2->base).entity + 3) << 2);
        cVar9 = *(char *)((int)uVar7 + 0x89);
      }
      uVar14 = CONCAT11(uVar34,uVar33);
      if (cVar9 != -1) {
        for (uVar15 = 0; uVar14 = CONCAT11(uVar34,uVar33), uVar15 < SquareRecCount;
            uVar15 = uVar15 + 1) {
          uVar14 = ovr_alignUp4(*(int *)(uVar15 * 0x13));
          bVar38 = (byte)uVar14;
          uVar37 = (undefined1)(uVar14 >> 8);
          uVar13 = (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x;
          uVar33 = (undefined1)uVar13;
          uVar34 = (undefined1)(uVar13 >> 8);
          uVar25 = 0x79;
          uVar32 = 0x23;
          uVar14 = ovr_alignUp4(uVar13);
          if ((CONCAT11(uVar37,bVar38) == uVar14) &&
             (*(uint16_t *)((uint8_t *)&SquareRecs[uVar15] + 2) == (in_stack_0000ffe2->base).y)) {
            uVar14 = uVar15 * 0x13 + (uint)bVar38 + 0xe;
            uVar25 = 0x79;
            uVar32 = 0x23;
            func_0x0004f930();
            if (*(uint16_t *)((uint8_t *)&SquareRecs[uVar15] + 2) == GfxRndSeed2) {
              uVar14 = ovr_alignUp4(*(int *)(uVar15 * 0x13));
              bVar38 = (byte)uVar14;
              uVar37 = (undefined1)(uVar14 >> 8);
              uVar33 = (undefined1)GfxRndSeed;
              uVar34 = (undefined1)((uint)GfxRndSeed >> 8);
              uVar25 = 0x79;
              uVar32 = 0x23;
              uVar15 = ovr_alignUp4(GfxRndSeed);
              uVar14 = CONCAT11(uVar34,uVar33);
              if (CONCAT11(uVar37,bVar38) == uVar15) {
                (&stack0xfff2)[bVar38] = 1;
                uVar14 = CONCAT11(uVar34,uVar33);
              }
            }
            break;
          }
        }
      }
    }
    if (AgntFlag1 != false) {
      if ((((((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x < GfxRndSeed - 2U)
          || (GfxRndSeed + 1U <
              (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x)) ||
         ((in_stack_0000ffe2->base).y != GfxRndSeed2)) {
        bVar10 = false;
      }
      else {
        bVar10 = true;
      }
      if (((uVar14 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uVar14)) ||
         (GfxRndSeed2 != CONCAT11(uVar32,uVar25))) {
        bVar11 = false;
      }
      else {
        bVar11 = true;
      }
      if (bVar11 || bVar10) {
        if (bVar11) {
          if (bVar10) {
            cVar9 = func_0x0004f944();
            while ((cVar9 != '\0' &&
                   (pcVar16 = ovr_ovc15_textArena((int)unaff_DI), ((uint)pcVar16 & 0xff) != 0))) {
              cVar9 = cVar9 + -1;
            }
          }
          else {
            cVar9 = (char)((ulong)((in_stack_0000ffe2->base).animFrame + 0xf) / 0x10);
            while (cVar30 = cVar9 + -1, cVar9 != '\0') {
              ovr_agnt_usesAgntCount6(Entities + (int)unaff_DI);
              cVar9 = cVar30;
            }
          }
        }
        else {
          ovr_ovc15_clearVisited();
          cVar9 = (char)((ulong)((in_stack_0000ffe2->base).animFrame + 0xf) / 0x10);
          while (cVar30 = cVar9 + -1, cVar9 != '\0') {
            ovr_ovc15_textArena((int)unaff_DI);
            cVar9 = cVar30;
          }
        }
      }
    }
    do {
      unaff_DI = unaff_DI + 1;
      if (EntityCount <= unaff_DI) {
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
        ovr_ovc24_removeOtherEntities(&stack0xffe9);
        GGameState = 0x1f;
        if (uVar31 != 0x0) {
          ovr_constr_usesBlitRect();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (uVar14 = 0; (int)uVar14 < 5; uVar14 = uVar14 + 1) {
          if ((&stack0xfff2)[uVar14] != '\0') {
            ovr_ovc41_usesMiceBlitRect(uVar14);
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
      peVar27 = Entities + (int)unaff_DI;
      unaff_ES = DAT_2000_d190;
      uVar14 = ovr_alignUp4((peVar27->base).destX);
      uVar25 = (undefined1)uVar14;
      uVar32 = (undefined1)(uVar14 >> 8);
      uVar14 = ovr_alignUp4((((entity_t *)CONCAT22(unaff_ES,peVar27))->base).x);
      if ((CONCAT11(uVar32,uVar25) == uVar14) && ((peVar27->base).destY == (peVar27->base).y)) {
        func_0x0004fb8e();
      }
    } while (((peVar27->base).destX == 0 && (peVar27->base).destY == 0) ||
            (*(char *)((int)&(peVar27->base).entity + 1) != '\0'));
    in_stack_0000ffe2 = peVar27;
    in_stack_0000ffe4 = unaff_ES;
  } while ((peVar27->base).faction < (byte)(peVar27->base).state);
  uVar12 = ovr_ovc07_signum((peVar27->base).destX -
                            (((entity_t *)CONCAT22(unaff_ES,peVar27))->base).x);
  cVar30 = (char)uVar12;
  uVar32 = (undefined1)((uint)uVar12 >> 8);
  uVar12 = ovr_ovc07_signum((peVar27->base).destY - (peVar27->base).y);
  cVar9 = (char)uVar12;
  uVar25 = (undefined1)((uint)uVar12 >> 8);
  in_stack_0000ffe2 = peVar27;
  in_stack_0000ffe4 = unaff_ES;
  if (((CONCAT11(uVar32,cVar30) == 0) ||
      (uVar13 = ovr_randBelow(2), in_stack_0000ffe2 = peVar27, in_stack_0000ffe4 = unaff_ES,
      (char)uVar13 == '\0')) ||
     (cVar8 = func_0x0004f412(), in_stack_0000ffe2 = peVar27, in_stack_0000ffe4 = unaff_ES,
     cVar8 != '\0')) {
    if ((CONCAT11(uVar25,cVar9) == 0) || (cVar8 = func_0x0004f412(), cVar8 != '\0')) {
      if ((CONCAT11(uVar32,cVar30) == 0) || (cVar9 = func_0x0004f412(), cVar9 != '\0')) {
        uVar14 = ovr_ovc26_usesStExit((int)unaff_DI);
        if ((char)uVar14 == '\0') {
          uVar14 = ovr_ovc26_usesRandBelow((int)unaff_DI,(uint16_t)&stack0xffe9);
          if ((uVar14 & 0xff) == 0) {
            peVar27 = (entity_t *)((uint)(in_stack_0000ffe2->base).gindex * 0x95);
            uVar13 = 0x195d;
switchD_4000_e2bf_caseD_6:
            if (peVar27[0xb4].base.teamCode == 0x0) {
              func_0x0004fb8e();
            }
          }
        }
        else {
          (in_stack_0000ffe2->base).target =
               (byte)((int)(uint)*(byte *)((int)&(in_stack_0000ffe2->base).owner +
                                          ((int)(uint)(in_stack_0000ffe2->base).faction >> 2)) >>
                     (((in_stack_0000ffe2->base).faction & 3) << 1)) & 3;
          cVar9 = func_0x0004f32d();
          if (cVar9 == '\0') {
            (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x =
                 (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x +
                 (int)*(char *)((in_stack_0000ffe2->base).target + 0x885);
            puVar1 = &(in_stack_0000ffe2->base).y;
            *puVar1 = *puVar1 + (int)*(char *)((in_stack_0000ffe2->base).target + 0x889);
            puVar2 = &(in_stack_0000ffe2->base).faction;
            *puVar2 = *puVar2 + 0x1;
          }
        }
      }
      else {
        (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x =
             (((entity_t *)CONCAT22(in_stack_0000ffe4,in_stack_0000ffe2))->base).x +
             CONCAT11(uVar32,cVar30);
        (in_stack_0000ffe2->base).target = 0x2 - cVar30;
      }
    }
    else {
      puVar1 = &(in_stack_0000ffe2->base).y;
      *puVar1 = *puVar1 + CONCAT11(uVar25,cVar9);
      (in_stack_0000ffe2->base).target = cVar9 + 0x1;
    }
  }
  else {
    (((entity_t *)CONCAT22(unaff_ES,peVar27))->base).x =
         (((entity_t *)CONCAT22(unaff_ES,peVar27))->base).x + CONCAT11(uVar32,cVar30);
    (peVar27->base).target = 0x2 - cVar30;
  }
  goto L_attact_3f0b_1082_1477;
}
