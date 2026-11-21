void manage_textAllProperty2(void)

{
  long lVar1;
  far_t gfx;
  far_t entries;
  undefined2 *puVar2;
  void *pvVar3;
  int iVar4;
  char *pcVar5;
  uint8_t *puVar6;
  undefined2 uVar7;
  int unaff_BP;
  int iVar8;
  int iVar9;
  char *unaff_SS;
  uint16_t uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  uint8_t term;
  
  if (((*(char *)(unaff_BP + -0x15) != '\x02') && (*(char *)(unaff_BP + -0x15) != '\x03')) &&
     (*(char *)(unaff_BP + -0x15) != '\x04')) {
    manage_usesCurSfxType3();
    return;
  }
  if (ScreenMode == '\0') {
    manage_openTalkWindow();
  }
  else {
    gfx.seg = talkwin9Cut1Seg;
    gfx.ofs = talkwin9Cut1Ofs;
    ovr_blitGfxRect(gfx,0,0,(brect_t *)(BlitRects + 1),0x10,true,0,0x10,0x10,0);
  }
  TextBlitY = 0xc;
  TextBlitX = 0x11;
  if (*(char *)(unaff_BP + 6) == -1) {
    ovr_blitLabel((char *)"All property.",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,(char)Font02.seg,0xde,0x50);
  }
  else {
    puVar2 = (undefined2 *)((uint)*(byte *)(unaff_BP + 6) * 4);
    puVar6 = (uint8_t *)*puVar2;
    *(undefined2 *)(unaff_BP + -2) = puVar2[1];
    *(undefined2 *)(unaff_BP + -4) =(uint16_t)( puVar6);
    uVar7 = 0x50;
    term = 0xde;
    uVar11 = (undefined1)Font02.seg;
    uVar12 = (undefined1)(Font02.seg >> 8);
    uVar10 = Font02.ofs;
    iVar9 = ovr_ovc45_compute9((char *)(unaff_BP + -0x66),
                               (char *)CONCAT22(*(undefined2 *)(unaff_BP + -4),unaff_SS),
                               (char *)CONCAT22(Font02.ofs,(char *)*(undefined2 *)(unaff_BP + -2)),
                               Font02.seg,'i',0x69,3);
    pvVar3 = manage_playerTitle((char_sheet_t *)*(undefined2 *)(unaff_BP + -4),
                                *(undefined2 *)(unaff_BP + -2),(char)iVar9,puVar6);
    pcVar5 = ovr_stsprintf((char *)(unaff_BP + -0xb6),(char *)CONCAT22(0x52a1,unaff_SS),
                           (char *)CONCAT22(pvVar3,(char *)0x26510),puVar6);
    ovr_blitLabel(pcVar5,(uint8_t *)CONCAT22(uVar10,puVar6),CONCAT11(uVar12,uVar11),term,uVar11,term
                  ,uVar7);
  }
  TextBlitY = TextBlitY + 0xc;
  TextBlitX = 0x11;
  ovr_blitLabel((char *)"Buildings",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                Font02.seg,0xde,(char)Font02.seg,0xde,0xe0);
  manage_usesBlitLabel2("Total",100);
  manage_usesBlitLabel2("Level 1",0x8c);
  manage_usesBlitLabel2("Level 2",0xb4);
  manage_usesBlitLabel2("Level 3",0xdc);
  TextBlitY = TextBlitY + 0xc;
  if (*(char *)(unaff_BP + -0x15) == '\x04') {
    iVar9 = 0x1a;
  }
  else if (*(char *)(unaff_BP + -0x15) == '\x03') {
    iVar9 = 0xd;
  }
  else {
    iVar9 = 0;
  }
  iVar8 = 0;
  while( true ) {
    if (0xc < iVar8) break;
    if (iVar8 + iVar9 < 0x1e) {
      TextBlitX = 0x11;
      iVar4 = (iVar8 + iVar9) * 6;
      ovr_blitLabel((char *)*(undefined2 *)((int)&GStructures[0].name + iVar4),
                    (uint8_t *)
                    CONCAT22(Font02.ofs,
                             (uint8_t *)*(undefined2 *)((int)&GStructures[0].name + 2 + iVar4)),
                    Font02.seg,0xde,(char)Font02.seg,0xde,0xe0);
      lVar1 = (long)(iVar8 + iVar9) * 6;
      uVar7 = (undefined2)((ulong)lVar1 >> 0x10);
      iVar4 = manage_usesGUnitCount
                        (*(char *)(unaff_BP + 6),(&((unk01_t *)GStructures)->type)[(int)lVar1],
                         (int *)CONCAT22(unaff_SS,(int *)(unaff_BP + -6)),
                         (int *)CONCAT22(unaff_SS,(int *)(unaff_BP + -8)),
                         (int *)CONCAT22(unaff_SS,(int *)(unaff_BP + -10)),
                         (int *)CONCAT22(unaff_SS,(int *)(unaff_BP + -0xc)));
      *(int *)((char *)init_textFilename + unaff_BP) = iVar4;
      if (*(int *)(unaff_BP + -0xc) == 0) {
        iVar4 = 100;
        uVar11 = (undefined1)*(undefined2 *)((char *)init_textFilename + unaff_BP);
        pcVar5 = litoa10((char *)(unaff_BP + -0x66),
                         CONCAT13((char)((uint)*(undefined2 *)((char *)init_textFilename + unaff_BP)
                                        >> 8),CONCAT12(uVar11,unaff_SS)),uVar11,0);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
      }
      else {
        iVar4 = 100;
        pcVar5 = ovr_stsprintf((char *)(unaff_BP + -0xb6));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
      }
      lVar1 = (long)(iVar8 + iVar9) * 6;
      uVar7 = (undefined2)((ulong)lVar1 >> 0x10);
      if (*(char *)((int)&GStructures[0].pad + (int)lVar1) != '\0') {
        if (*(int *)(unaff_BP + -0xe) == 0) {
          iVar4 = 0x8c;
          uVar11 = (undefined1)*(undefined2 *)(unaff_BP + -6);
          pcVar5 = litoa10((char *)(unaff_BP + -0x66),
                           CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -6) >> 8),
                                    CONCAT12(uVar11,unaff_SS)),uVar11,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
        }
        else {
          iVar4 = 0x8c;
          pcVar5 = ovr_stsprintf((char *)(unaff_BP + -0xb6));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
        }
        if (*(int *)(unaff_BP + -0x10) == 0) {
          iVar4 = 0xb4;
          uVar11 = (undefined1)*(undefined2 *)(unaff_BP + -8);
          pcVar5 = litoa10((char *)(unaff_BP + -0x66),
                           CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -8) >> 8),
                                    CONCAT12(uVar11,unaff_SS)),uVar11,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
        }
        else {
          iVar4 = 0xb4;
          pcVar5 = ovr_stsprintf((char *)(unaff_BP + -0xb6));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
        }
        if (*(int *)(unaff_BP + -0x12) == 0) {
          iVar4 = 0xdc;
          uVar11 = (undefined1)*(undefined2 *)(unaff_BP + -10);
          pcVar5 = litoa10((char *)(unaff_BP + -0x66),
                           CONCAT13((char)((uint)*(undefined2 *)(unaff_BP + -10) >> 8),
                                    CONCAT12(uVar11,unaff_SS)),uVar11,0);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
        }
        else {
          iVar4 = 0xdc;
          pcVar5 = ovr_stsprintf((char *)(unaff_BP + -0xb6));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,pcVar5)),iVar4);
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
    iVar8 = iVar8 + 1;
  }
  CurSfxType3 = 0x3c;
  (*(uint8_t *)((uint8_t *)&(entries.seg))) = (char)unaff_SS;
  entries.ofs = unaff_BP + -0x142;
  (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = (char)((uint)unaff_SS >> 8);
  uVar7 = ovr_ovc28_usesUiInputText
                    (entries,0x23,far_from_u32((uint32_t)(0x0)),(uint8_t *)(unaff_BP + -0x16),0,
                     (char)(uint8_t *)(unaff_BP + -0x16));
  *(undefined1 *)(unaff_BP + -0x15) = (char)uVar7;
  keyboardInputMode = 0;
  if (((*(char *)(unaff_BP + -0x15) != '\0') && (*(char *)(unaff_BP + -0x15) != '\x01')) &&
     (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_textAllProperty2();
    return;
  }
  if ((ScreenMode == '\0') && (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_openTalkWindow();
  }
  if (*(char *)(unaff_BP + -0x15) == -2) {
    Cancelled = 1;
  }
  return;
}
