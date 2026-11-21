void __cdecl16far manage_textHalflingCastle(void)

{
  uint *puVar1;
  int *piVar2;
  far_t gfx;
  far_t dst;
  far_t handle;
  uint uVar3;
  char *pcVar4;
  char_sheet_t *widths;
  int iVar5;
  undefined2 uVar6;
  uint16_t unaff_SS;
  far_t entries;
  char_sheet_t *pcStack_12;
  int iStack_10;
  uint8_t inputBuf;
  uint uStack_6;
  int iStack_4;
  
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)unaff_SS;
  dst.ofs = (uint16_t)&inputBuf;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)(unaff_SS >> 8);
  F_SCOPY(far_from_u32((uint32_t)(0x24104a1e)),dst);
  gfx.seg = FontHandle.seg;
  gfx.ofs = FontHandle.ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)));
  ovr_attact_usesAgntFlag1();
  ovr_draw_freeRingBuffers();
  ovr_stop_audio();
  CurMusicType = 0xff;
  savedMenuItem = GMenuItem;
  MenuModeSaved = MenuMode;
  TextBlitDstSeg = 0xa000;
  for (iStack_4 = 0; iStack_10 = 0x2410, iStack_4 < (int)(uint)GLeaderCount; iStack_4 = iStack_4 + 1
      ) {
    if (((((char_sheet_t *)((iStack_4 << 2)))->active != '\0') &&
        (((char_sheet_t *)((iStack_4 << 2)))->x == GfxRndSeed)) &&
       (((char_sheet_t *)((iStack_4 << 2)))->y == GfxRndSeed2)) {
      if (GCharLevelsInc != '\0') {
        uVar6 = (undefined2)((ulong)*(undefined4 *)(iStack_4 << 2) >> 0x10);
        iVar5 = (int)*(undefined4 *)(iStack_4 << 2);
        puVar1 = (uint *)(iVar5 + 0x56);
        uVar3 = *puVar1;
        *puVar1 = *puVar1 + 10000;
        piVar2 = (int *)(iVar5 + 0x58);
        *piVar2 = *piVar2 + (uint)(0xd8ef < uVar3);
        GCharLevelsInc = '\0';
      }
      manage_settlementScreen((byte)iStack_4);
      ovr_stats_openCastlePanel();
      ovr_ovc41_usesGMenuItem();
      return;
    }
  }
  ovr_stats_drawStatsPanel();
  if (PartyCount == 0) {
    if (PartySize <= CurPartySlot) {
      ovr_ovc41_usesGMenuItem();
      return;
    }
    pcStack_12 = chargen();
    if (pcStack_12 == (char_sheet_t *)0x0 && iStack_10 == 0) {
      ovr_stats_openCastlePanel();
      ovr_ovc41_usesGMenuItem();
      return;
    }
    iStack_4 = 0;
    while ((iStack_4 < (int)(uint)GLeaderCount &&
           (((char_sheet_t *)((iStack_4 << 2)))->statMask != '\0'))) {
      iStack_4 = iStack_4 + 1;
    }
    if (iStack_4 < (int)(uint)GLeaderCount) {
      PartyCount = (byte)iStack_4 + 1;
      uVar6 = *(undefined2 *)((uint)PartyCount * 4 + -2);
      (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)uVar6;
      handle.ofs = *(undefined2 *)((uint)PartyCount * 4 + -4);
      (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)uVar6 >> 8);
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
    pcStack_12->statMask = pcStack_12->statMask | 0x40;
    pcStack_12->charIndex = PartyCount - 1;
    uVar3 = (uint)PartyCount;
    widths = (char_sheet_t *)((char *)0x2627a);
    *(int *)(uVar3 * 4 + -2) = iStack_10;
    *(undefined2 *)(uVar3 * 4 + -4) =(uint16_t)( pcStack_12);
    if (CurPartySlot == 0) {
      pcStack_12->titleIndex = 1;
    }
    CurPartySlot = CurPartySlot + 1;
  }
  else {
    manage_openTalkWindow();
    iStack_10 = *(int *)((uint)PartyCount * 4 + -2);
    pcStack_12 = (char_sheet_t *)*(undefined2 *)((uint)PartyCount * 4 + -4);
    widths = pcStack_12;
    manage_usesLitoa10((char_sheet_t *)
                       CONCAT13((char)((uint)iStack_10 >> 8),CONCAT12((char)iStack_10,pcStack_12)));
  }
  pcVar4 = ovr_fmVsprintf("Place %s here.",
                          (char *)CONCAT13((char)((uint)iStack_10 >> 8),
                                           CONCAT12((char)iStack_10,pcStack_12)));
  ovr_drawString(pcVar4,(uint16_t)widths,(char)widths);
  entries.seg = unaff_SS;
  entries.ofs = (uint16_t)&inputBuf;
  pcVar4 = ovr_uiInputText(entries,2,far_from_u32((uint32_t)(0x0)),0x0);
  uStack_6 = (uint)pcVar4 & 0xff;
  if (uStack_6 == 1) {
    iStack_4 = PartyCount - 1;
    if (CurPartySlot == 1) {
      ovr_ovc18_checkFortressPla_7e6f('\x02');
    }
    else {
      ovr_ovc18_checkFortressPla_7e6f('\x01');
    }
    ovr_ovc41_usesGMenuItem();
  }
  else {
    ovr_stats_openCastlePanel();
    ovr_ovc41_usesGMenuItem();
  }
  return;
}
