void __cdecl16far manage_4d05_056e(undefined4 param_1)

{
  byte bVar1;
  char *pcVar2;
  undefined1 extraout_AH;
  undefined2 in_DX;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint16_t uVar6;
  undefined2 uVar7;
  char *pcVar8;
  uint8_t *puVar9;
  int16_t iVar10;
  uint8_t uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  char local_f6 [120];
  char local_7e [120];
  byte bStack_6;
  byte bStack_5;
  undefined2 uStack_4;
  
  uVar7 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  bStack_6 = *(byte *)(iVar4 + 0x28);
  if ((bStack_6 & 0x20) != 0) {
    uVar6 = 0x1b;
    for (iVar5 = 0; iVar5 < 6; iVar5 = iVar5 + 1) {
      TextBlitX = 0x15;
      TextBlitY = uVar6;
      ovr_blitLabel((char *)CONCAT22(*(undefined2 *)((int)&GStatsLabels[0].seg + iVar5 * 4),
                                     (char *)((far_t *)GStatsLabels + iVar5)->ofs),
                    (uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
      pcVar8 = ovr_stsprintf(local_7e,"%d",(char *)(uint)*(byte *)(iVar4 + iVar5 + 0x29));
      in_DX = (undefined2)((ulong)pcVar8 >> 0x10);
      manage_4d05_04c6(local_7e);
      uVar6 = uVar6 + 10;
    }
  }
  TextBlitY = 0xc;
  if ((bStack_6 & 2) != 0) {
    TextBlitX = 0x15;
    uVar13 = manage_4d05_03a4(iVar4,uVar7,Font02.ofs,Font02.seg);
    uStack_4 = ovr_font_302d_06ea(uVar13,in_DX);
    uVar11 = 0x50;
    iVar10 = 222;
    puVar9 = (uint8_t *)Font02.ofs;
    uVar6 = Font02.seg;
    uVar13 = ovr_OVC45_77eb_226e(local_7e);
    pcVar2 = (char *)manage_4d05_03a4(iVar4,uVar7,uVar13);
    pcVar8 = ovr_stsprintf(local_f6,"%s%s, ",pcVar2);
    in_DX = (undefined2)((ulong)pcVar8 >> 0x10);
    ovr_blitLabel(pcVar8,(uint8_t *)CONCAT22(uVar6,puVar9),iVar10,uVar11);
  }
  if ((bStack_6 & 4) != 0) {
    uVar11 = 0x50;
    iVar10 = 222;
    puVar9 = (uint8_t *)Font02.ofs;
    uVar6 = Font02.seg;
    pcVar2 = ovr_fmVsprintf((char *)"%s ",
                            (char *)((far_t *)GAlignmentsNames + *(byte *)(iVar4 + 0x33))->ofs);
    ovr_blitLabel((char *)CONCAT22(in_DX,pcVar2),(uint8_t *)CONCAT22(uVar6,puVar9),iVar10,uVar11);
  }
  if ((bStack_6 & 1) != 0) {
    uVar11 = 0x50;
    iVar10 = 222;
    pcVar3 = (char *)"puppetmaker" + 3;
    puVar9 = (uint8_t *)Font02.ofs;
    uVar6 = Font02.seg;
    pcVar2 = ovr_fmVsprintf((char *)"%s",
                            (char *)*(undefined2 *)((uint)*(byte *)(iVar4 + 0x2f) * 4 + 0xeb));
    ovr_blitLabel((char *)CONCAT22(pcVar3,pcVar2),(uint8_t *)CONCAT22(uVar6,puVar9),iVar10,uVar11);
  }
  TextBlitY = TextBlitY + 10;
  if (((bStack_6 & 0x40) != 0) || (DebugVerbose != false)) {
    TextBlitX = 0x37;
    ovr_blitLabel("Population",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
    uVar12 = 0x7d;
    pcVar8 = ovr_stsprintf(local_7e,"%d",(char *)*(undefined2 *)(iVar4 + 0x4d));
    uVar13 = (undefined2)((ulong)pcVar8 >> 0x10);
    manage_4d05_04c6(pcVar8,uVar12);
    TextBlitX = 0x82;
    ovr_OVC22_5087_056e(CONCAT11(0x24,*(undefined1 *)(iVar4 + 0x51)));
    ovr_blitLabel("Food prod.",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
    uVar12 = 0xdc;
    pcVar2 = litoa10(local_f6,(ulong)*(uint *)(iVar4 + 0x4f));
    manage_4d05_04c6(pcVar2,uVar13,uVar12);
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x82;
    ovr_blitLabel("Food stored",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
    uVar12 = 0xdc;
    pcVar2 = litoa10(local_f6,CONCAT22(*(undefined2 *)(iVar4 + 0x62),*(undefined2 *)(iVar4 + 0x60)))
    ;
    manage_4d05_04c6(pcVar2,uVar13,uVar12);
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel("Housing",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
    uVar12 = 0x7d;
    pcVar8 = ovr_stsprintf(local_7e,"%d",(char *)*(undefined2 *)(iVar4 + 0x5b));
    uVar13 = (undefined2)((ulong)pcVar8 >> 0x10);
    manage_4d05_04c6(pcVar8,uVar12);
    TextBlitX = 0x82;
    ovr_blitLabel("Food storage",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
    uVar12 = 0xdc;
    pcVar2 = litoa10(local_f6,CONCAT22(*(undefined2 *)(iVar4 + 0x80),*(undefined2 *)(iVar4 + 0x7e)))
    ;
    manage_4d05_04c6(pcVar2,uVar13,uVar12);
    TextBlitY = TextBlitY + 0xf;
    if (*(int *)(iVar4 + 0xa0) != 0) {
      TextBlitX = 0x37;
      if (*(int *)(iVar4 + 0xa2) < 0) {
        ovr_blitLabel("Food sold",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
        uVar13 = 0x7d;
        iVar5 = -*(int *)(iVar4 + 0xa2) >> 0xf;
        pcVar2 = litoa10(local_f6,(long)-*(int *)(iVar4 + 0xa2));
        manage_4d05_04c6(pcVar2,iVar5,uVar13);
      }
      else {
        ovr_blitLabel("Food bought",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
        uVar13 = 0x7d;
        iVar5 = *(int *)(iVar4 + 0xa2) >> 0xf;
        pcVar2 = litoa10(local_f6,(long)*(int *)(iVar4 + 0xa2));
        manage_4d05_04c6(pcVar2,iVar5,uVar13);
      }
      TextBlitX = 0x82;
      ovr_blitLabel("Max. trade",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
      uVar13 = 0xdc;
      pcVar2 = litoa10(local_f6,(ulong)*(uint *)(iVar4 + 0xa0));
      manage_4d05_04c6(pcVar2,iVar5,uVar13);
    }
    TextBlitY = TextBlitY + 0xf;
    TextBlitX = 0x37;
    ovr_blitLabel("Income",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
    uVar13 = 0xdc;
    iVar5 = *(int *)(iVar4 + 0x54) >> 0xf;
    pcVar2 = litoa10(local_7e,(long)*(int *)(iVar4 + 0x54));
    manage_4d05_04c6(pcVar2,iVar5,uVar13);
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel("Gold",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
    uVar13 = 0xdc;
    pcVar2 = litoa10(local_7e,CONCAT22(*(undefined2 *)(iVar4 + 0x58),*(undefined2 *)(iVar4 + 0x56)))
    ;
    manage_4d05_04c6(pcVar2,iVar5,uVar13);
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel("Vault storage",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
    uVar13 = 0xdc;
    pcVar2 = litoa10(local_7e,CONCAT22(*(undefined2 *)(iVar4 + 0x8c),*(undefined2 *)(iVar4 + 0x8a)))
    ;
    manage_4d05_04c6(pcVar2,iVar5,uVar13);
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel("Fund Access",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
    uVar13 = ovr_OVC45_77eb_0904(CONCAT11(extraout_AH,*(undefined1 *)(iVar4 + 0x51)),0xdc);
    pcVar2 = litoa10(local_f6,CONCAT22(iVar5,uVar13));
    manage_4d05_04c6(pcVar2,iVar5);
    TextBlitY = TextBlitY + 10;
    TextBlitX = 0x37;
    ovr_blitLabel("Common fund",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
    uVar13 = 0xdc;
    pcVar2 = litoa10(local_f6,CONCAT22(DAT_2000_ca93,DAT_2000_ca91));
    manage_4d05_04c6(pcVar2,iVar5,uVar13);
    bStack_5 = manage_4d05_1b1d();
    TextBlitY = TextBlitY + 0xf;
    if (((*(char *)(iVar4 + 0x86) != '\0') && (bStack_5 != 0xff)) &&
       (*(byte *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x86) < 9)) {
      manage_4d05_0519((char *)"popularity",(char *)"puppetmaker" + 3,0x7d,0xe0);
      manage_4d05_0519((char *)"city blocks",(char *)"puppetmaker" + 3,0xdc,0xe0);
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x11;
      ovr_blitLabel("Current",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
      pcVar2 = (char *)manage_4d05_044e(0x7d);
      pcVar8 = ovr_stsprintf(local_7e,"%d%%",pcVar2);
      manage_4d05_04c6(pcVar8);
      uVar7 = 0xdc;
      pcVar8 = ovr_stsprintf(local_7e,"%d",DAT_2000_d3ca);
      manage_4d05_04c6(pcVar8,uVar7);
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x11;
      ovr_blitLabel("to promote",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
      bVar1 = ovr_season_67e7_04e5(0x7d);
      pcVar8 = ovr_stsprintf(local_7e,"%d%%",(char *)(uint)bVar1);
      manage_4d05_04c6(pcVar8);
      pcVar2 = (char *)ovr_season_67e7_048f(0xdc);
      pcVar8 = ovr_stsprintf(local_7e,"%d",pcVar2);
      manage_4d05_04c6(pcVar8);
    }
  }
  return;
}
