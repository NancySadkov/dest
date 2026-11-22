undefined2 __cdecl16far abilitiesDlg(char_sheet_t *sheet)

{
  uint16_t uVar1;
  far_t dst;
  far_t dst_00;
  byte bVar2;
  undefined1 extraout_AH;
  uint8_t *puVar3;
  char *pcVar4;
  uint uVar5;
  uint16_t unaff_SS;
  far_t entries;
  far_t entries_00;
  undefined1 uVar6;
  undefined1 uVar7;
  uint8_t menuItems;
  undefined2 auStack_28 [7];
  char cStack_1a;
  byte bStack_19;
  uint8_t statIndex;
  byte abStack_17 [5];
  uint8_t classStatMap2;
  uint8_t classStatMap1;
  
  uVar6 = (undefined1)unaff_SS;
  uVar7 = (undefined1)(unaff_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = uVar6;
  dst.ofs = (uint16_t)&classStatMap1;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar7;
  F_SCOPY(far_from_u32((uint32_t)(0x241049dd)),dst);
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = uVar6;
  dst_00.ofs = (uint16_t)&classStatMap2;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = uVar7;
  F_SCOPY(far_from_u32((uint32_t)(0x241049e4)),dst_00);
  while( true ) {
    _fsetmem((void *)CONCAT13(uVar7,CONCAT12(uVar6,&menuItems)),0x10,0);
    auStack_28[0] = 0x2410;
    menuItems = 0x4d9b;
    bStack_19 = 1;
    bVar2 = manage_statSelectable
                      ((&classStatMap1)[((char_sheet_t *)sheet)->cls],
                       (char_sheet_t *)CONCAT22(0x4d9b,(*(uint16_t *)((uint8_t *)&(sheet) + 2))));
    if (bVar2 != 0) {
      abStack_17[bStack_19] = (&classStatMap1)[((char_sheet_t *)sheet)->cls];
      uVar1 = ((far_t far *)GStatsLabels + (&classStatMap1)[((char_sheet_t *)sheet)->cls])->ofs;
      uVar5 = (uint)bStack_19;
      auStack_28[uVar5 * 2] =
           *(undefined2 *)
            ((int)&GStatsLabels[0].seg + (uint)(&classStatMap1)[((char_sheet_t *)sheet)->cls] * 4);
      *(uint16_t *)(&menuItems + uVar5 * 4) = uVar1;
      bStack_19 = bStack_19 + 1;
    }
    puVar3 = &classStatMap2 + ((char_sheet_t *)sheet)->cls;
    if (*puVar3 != 0xff) {
      bVar2 = manage_statSelectable
                        ((&classStatMap2)[((char_sheet_t *)sheet)->cls],
                         (char_sheet_t *)CONCAT22(menuItems,(*(uint16_t *)((uint8_t *)&(sheet) + 2))));
      puVar3 = (uint8_t *)CONCAT11(extraout_AH,bVar2);
      if (bVar2 != 0) {
        abStack_17[bStack_19] = (&classStatMap2)[((char_sheet_t *)sheet)->cls];
        puVar3 = (uint8_t *)
                 *(undefined2 *)
                  ((int)&GStatsLabels[0].seg +
                  (uint)(&classStatMap2)[((char_sheet_t *)sheet)->cls] * 4);
        uVar1 = ((far_t far *)GStatsLabels + (&classStatMap2)[((char_sheet_t *)sheet)->cls])->ofs;
        uVar5 = (uint)bStack_19;
        auStack_28[uVar5 * 2] =(uint16_t)( puVar3);
        *(uint16_t *)(&menuItems + uVar5 * 4) = uVar1;
        bStack_19 = bStack_19 + 1;
      }
    }
    if (bStack_19 == 1) {
      return CONCAT11((char)((uint)puVar3 >> 8),1);
    }
    ovr_drawString((char *)
                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                   ,0x2410,0x10);
    entries.seg = unaff_SS;
    entries.ofs = (uint16_t)&menuItems;
    pcVar4 = ovr_uiInputText(entries,(uint)bStack_19,far_from_u32((uint32_t)(0x0)),0x0,0);
    cStack_1a = (char)pcVar4;
    if (cStack_1a == '\0') {
      return 0;
    }
    if (cStack_1a == '\x01') break;
    abStack_17[0] = abStack_17[((uint)pcVar4 & 0xff) - 1];
    ovr_drawString((char *)"Select ability to adjust downwards by two points.",0x2410,0x10);
    _fsetmem((void *)CONCAT13(uVar7,CONCAT12(uVar6,&menuItems)),0x10,0);
    auStack_28[0] = 0x2410;
    menuItems = 0x4e3a;
    bStack_19 = 1;
    for (statIndex = 0x0; statIndex < 3; statIndex = statIndex + 0x1) {
      if ((10 < ((char_sheet_t *)sheet)->stats[statIndex]) && (abStack_17[0] != statIndex)) {
        abStack_17[bStack_19] = statIndex;
        uVar1 = ((far_t far *)GStatsLabels + statIndex)->ofs;
        uVar5 = (uint)bStack_19;
        auStack_28[uVar5 * 2] = *(undefined2 *)((int)&GStatsLabels[0].seg + (uint)statIndex * 4);
        *(uint16_t *)(&menuItems + uVar5 * 4) = uVar1;
        bStack_19 = bStack_19 + 1;
      }
    }
    entries_00.seg = unaff_SS;
    entries_00.ofs = (uint16_t)&menuItems;
    pcVar4 = ovr_uiInputText(entries_00,(uint)bStack_19,far_from_u32((uint32_t)(0x0)),0x0,0);
    cStack_1a = (char)pcVar4;
    if (cStack_1a == '\0') {
      return 0;
    }
    if (cStack_1a != '\x01') {
      ((char_sheet_t *)sheet)->stats[abStack_17[0]] =
           ((char_sheet_t *)sheet)->stats[abStack_17[0]] + 1;
      ((char_sheet_t *)sheet)->stats[abStack_17[((uint)pcVar4 & 0xff) - 1]] =
           ((char_sheet_t *)sheet)->stats[abStack_17[((uint)pcVar4 & 0xff) - 1]] - 2;
      manage_openTalkWindow();
      manage_usesLitoa10(sheet);
    }
  }
  return 1;
}
