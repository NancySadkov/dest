/* manage_usesLitoa10 - draws the stats panel for one character sheet.
   Stack locals named from their assignments: statMask (sheet->statMask),
   textWidth (ovr_font_textWidth result) and firstLeader
   (manage_findFirstLeader result).  The rest of the body is still
   register-temporary heavy and keeps its decompiler names. */
void __cdecl16far manage_usesLitoa10(char_sheet_t *sheet)

{
  char cVar1;
  void *pvVar2;
  char *pcVar3;
  uint16_t uVar4;
  uint uVar5;
  uint8_t *in_DX;
  int iVar6;
  char_sheet_t *sheet_00;
  int iVar7;
  uint16_t uVar8;
  char *pcVar9;
  char *unaff_SS;
  uint16_t uVar10;
  undefined1 uVar11;
  uint8_t uVar12;
  undefined1 uVar13;
  char textBuf [120];
  uint8_t msg;
  byte statMask;
  byte firstLeader;
  int textWidth;
  
  pcVar9 = (char *)((ulong)sheet >> 0x10);
  sheet_00 = (char_sheet_t *)sheet;
  statMask = sheet_00->statMask;
  if ((statMask & 0x20) != 0) {
    uVar8 = 0x1b;
    for (iVar7 = 0; iVar7 < 6; iVar7 = iVar7 + 1) {
      TextBlitX = 0x15;
      TextBlitY = uVar8;
      ovr_blitLabel((char *)((far_t *)GStatsLabels + iVar7)->ofs,
                    (uint8_t *)
                    CONCAT22(Font02.ofs,
                             (uint8_t *)*(uint16_t *)((int)&GStatsLabels[0].seg + iVar7 * 4)),
                    Font02.seg,0xde,0xde,0xe0);
      ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,unaff_SS),
                    (char *)(ulong)CONCAT12(sheet_00->stats[iVar7],0x2410),0x10);
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)unaff_SS >> 8),CONCAT12((char)unaff_SS,&msg)),0x31);
      uVar8 = uVar8 + 10;
    }
  }
  TextBlitY = 0xc;
  if ((statMask & 2) != 0) {
    TextBlitX = 0x15;
    uVar11 = (undefined1)Font02.ofs;
    uVar13 = (undefined1)(Font02.ofs >> 8);
    pcVar3 = manage_playerTitle(sheet_00,pcVar9,uVar11,(char)Font02.seg);
    textWidth = ovr_font_textWidth(pcVar3,(char *)CONCAT13(uVar13,CONCAT12(uVar11,in_DX)));
    uVar11 = 0x50;
    uVar12 = 0xde;
    cVar1 = (char)(0x7d - textWidth);
    uVar8 = Font02.ofs;
    uVar10 = Font02.seg;
    iVar7 = ovr_ovc45_compute9((char *)&msg,(char *)CONCAT22(sheet_00,unaff_SS),
                               (char *)CONCAT22(Font02.ofs,pcVar9),Font02.seg,cVar1,cVar1,3);
    pvVar2 = manage_playerTitle(sheet_00,pcVar9,(char)iVar7,in_DX);
    pcVar3 = ovr_stsprintf(textBuf,(char *)CONCAT22(0x4cd4,unaff_SS),
                           (char *)CONCAT22(pvVar2,(char *)0x26510),in_DX);
    ovr_blitLabel(pcVar3,(uint8_t *)CONCAT22(uVar8,in_DX),uVar10,uVar12,uVar12,uVar11);
  }
  if ((statMask & 4) != 0) {
    uVar11 = 0x50;
    uVar12 = 0xde;
    uVar8 = Font02.ofs;
    uVar10 = Font02.seg;
    pcVar3 = ovr_fmVsprintf("%s ",(char *)CONCAT22(*(uint16_t *)
                                                    ((int)&GAlignmentsNames[0].seg +
                                                    (uint)sheet_00->alignment * 4),
                                                   (char *)((far_t *)GAlignmentsNames +
                                                           sheet_00->alignment)->ofs));
    ovr_blitLabel(pcVar3,(uint8_t *)CONCAT22(uVar8,in_DX),uVar10,uVar12,uVar12,uVar11);
  }
  if ((statMask & 1) != 0) {
    uVar11 = 0x50;
    uVar12 = 0xde;
    iVar7 = (uint)sheet_00->cls * 4;
    in_DX = (uint8_t *)((char *)0x26510);
    uVar8 = Font02.ofs;
    uVar10 = Font02.seg;
    pcVar3 = ovr_fmVsprintf("%s",(char *)CONCAT22(*(uint16_t *)(iVar7 + 0xed),
                                                  (char *)*(uint16_t *)(iVar7 + 0xeb)));
    ovr_blitLabel(pcVar3,(uint8_t *)CONCAT22(uVar8,in_DX),uVar10,uVar12,uVar12,uVar11);
  }
  TextBlitY = TextBlitY + 10;
  if (((statMask & 0x40) != 0) || (DebugVerbose != false)) {
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Population",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0x7d;
    uVar13 = 0;
    pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,unaff_SS),
                           (char *)CONCAT13((char)((uint)sheet_00->population >> 8),
                                            CONCAT12((char)sheet_00->population,0x2410)));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitX = 0x82;
    ovr_ovc22_textRingProt(sheet_00->charIndex);
    ovr_blitLabel((char *)"Food prod.",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    pcVar3 = litoa10(textBuf,(long)CONCAT22(sheet_00->foodProd,unaff_SS),0);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x82;
    ovr_blitLabel((char *)"Food stored",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    pcVar3 = litoa10(textBuf,(long)CONCAT22((int)sheet_00->foodStored,unaff_SS),
                     (char)*(uint16_t *)((int)&sheet_00->foodStored + 2));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Housing",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0x7d;
    uVar13 = 0;
    pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,unaff_SS),
                           (char *)CONCAT13((char)((uint)sheet_00->housing >> 8),
                                            CONCAT12((char)sheet_00->housing,0x2410)));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitX = 0x82;
    ovr_blitLabel((char *)"Food storage",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    pcVar3 = litoa10(textBuf,(long)CONCAT22((int)sheet_00->foodStorage,unaff_SS),
                     (char)*(uint16_t *)((int)&sheet_00->foodStorage + 2));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitY = TextBlitY + 0xf;
    if (sheet_00->maxTrade != 0) {
      TextBlitX = 0x37;
      if (sheet_00->foodSold < 0) {
        ovr_blitLabel((char *)"Food sold",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                      Font02.seg,0xde,0xde,0xe0);
        uVar11 = 0x7d;
        uVar13 = 0;
        iVar7 = -sheet_00->foodSold;
        iVar6 = iVar7 >> 0xf;
        pcVar3 = litoa10(textBuf,(long)CONCAT22(iVar7,unaff_SS),(char)(iVar7 >> 0xf));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
                   CONCAT11(uVar13,uVar11));
      }
      else {
        ovr_blitLabel((char *)"Food bought",
                      (uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),Font02.seg,0xde,0xde
                      ,0xe0);
        uVar11 = 0x7d;
        uVar13 = 0;
        iVar7 = sheet_00->foodSold;
        iVar6 = iVar7 >> 0xf;
        pcVar3 = litoa10(textBuf,(long)CONCAT22(iVar7,unaff_SS),(char)(iVar7 >> 0xf));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
                   CONCAT11(uVar13,uVar11));
      }
      TextBlitX = 0x82;
      ovr_blitLabel((char *)"Max. trade",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                    Font02.seg,0xde,0xde,0xe0);
      uVar11 = 0xdc;
      uVar13 = 0;
      pcVar3 = litoa10(textBuf,(long)CONCAT22(sheet_00->maxTrade,unaff_SS),0);
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
                 CONCAT11(uVar13,uVar11));
    }
    TextBlitY = TextBlitY + 0xf;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Income",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    iVar7 = sheet_00->income;
    iVar6 = iVar7 >> 0xf;
    pcVar3 = litoa10((char *)&msg,(long)CONCAT22(iVar7,unaff_SS),(char)(iVar7 >> 0xf));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Gold",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    pcVar3 = litoa10((char *)&msg,(long)CONCAT22((int)sheet_00->gold,unaff_SS),
                     (char)*(uint16_t *)((int)&sheet_00->gold + 2));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Vault storage",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    pcVar3 = litoa10((char *)&msg,(long)CONCAT22((int)sheet_00->vaultStorage,unaff_SS),
                     (char)*(uint16_t *)((int)&sheet_00->vaultStorage + 2));
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Fund Access",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    uVar4 = ovr_ovc45_usesLDIV_at_(sheet_00->charIndex);
    pcVar3 = litoa10(textBuf,(long)CONCAT22(uVar4,unaff_SS),(char)iVar6);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
               CONCAT11(uVar13,uVar11));
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel((char *)"Common fund",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,0xde,0xe0);
    uVar11 = 0xdc;
    uVar13 = 0;
    pcVar3 = litoa10(textBuf,(long)CONCAT22(GPopulationLo,unaff_SS),(char)GPopulationHi);
    manage_blitLabelRight
              ((char *)CONCAT13((char)((uint)iVar6 >> 8),CONCAT12((char)iVar6,pcVar3)),
               CONCAT11(uVar13,uVar11));
    firstLeader = manage_findFirstLeader();
    TextBlitY = TextBlitY + 0xf;
    if (((sheet_00->titleIndex != 0) && (firstLeader != 0xff)) &&
       (uVar4 = 0x217a, ((char_sheet_t *)(((uint)firstLeader << 2)))->titleIndex < 9)) {
      manage_usesBlitLabel2("popularity",0x7d);
      manage_usesBlitLabel2("city blocks",0xdc);
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x11;
      ovr_blitLabel((char *)"Current",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                    Font02.seg,0xde,0xde,0xe0);
      uVar11 = 0x7d;
      uVar13 = 0;
      uVar5 = manage_usesGLeaderCount();
      pcVar9 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4d8b,unaff_SS),
                             (char *)CONCAT13((char)(uVar5 >> 8),CONCAT12((char)uVar5,0x2410)));
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar9)),
                 CONCAT11(uVar13,uVar11));
      uVar11 = 0xdc;
      uVar13 = 0;
      pcVar9 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,unaff_SS),
                             (char *)CONCAT13((char)((uint)GPromotableCount >> 8),
                                              CONCAT12((char)GPromotableCount,0x2410)));
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar9)),
                 CONCAT11(uVar13,uVar11));
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x11;
      ovr_blitLabel((char *)"to promote",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                    Font02.seg,0xde,0xde,0xe0);
      uVar11 = 0x7d;
      uVar13 = 0;
      cVar1 = ovr_season_usesDifficulty();
      pcVar9 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4d8b,unaff_SS),
                             (char *)(ulong)CONCAT12(cVar1,0x2410));
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar9)),
                 CONCAT11(uVar13,uVar11));
      uVar11 = 0xdc;
      uVar13 = 0;
      iVar7 = ovr_season_usesGPromotableCount2();
      pcVar9 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x4cd1,unaff_SS),
                             (char *)CONCAT13((char)((uint)iVar7 >> 8),CONCAT12((char)iVar7,0x2410))
                            );
      manage_blitLabelRight
                ((char *)CONCAT13((char)((uint)uVar4 >> 8),CONCAT12((char)uVar4,pcVar9)),
                 CONCAT11(uVar13,uVar11));
    }
  }
  return;
}
