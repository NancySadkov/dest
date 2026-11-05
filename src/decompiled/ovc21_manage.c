/*
 * ovc21_manage.c - recovered from STRONG.EXE
 * memory block: OVC21_manage.c
 * range: 4d05:0000 - 4d05:381f
 * functions: 43
 */
#include "recovered.h"


/* 4d05:0000 */

void __cdecl16far manage_4d05_0000(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
    ((undefined1 *)&DAT_2000_d1de)[iVar1] = 0xff;
  }
  for (iVar1 = 0; iVar1 < (int)(uint)DAT_2000_d1e6; iVar1 = iVar1 + 1) {
    if ((*(char *)((int)*(undefined4 *)(iVar1 << 2) + 0x3d) != '\0') &&
       (*(char *)((int)*(undefined4 *)(iVar1 << 2) + 0x89) != -1)) {
      ((undefined1 *)&DAT_2000_d1de)[*(byte *)((int)*(undefined4 *)(iVar1 << 2) + 0x89)] =
           (char)iVar1;
    }
  }
  return;
}



/* 4d05:0081 */

void __cdecl16far manage_4d05_0081(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t handle;
  undefined1 local_306 [768];
  stg_tmp_t *psStack_6;
  
  DAT_2000_d116 = 0xff;
  DAT_2410_26a8 = 1;
  handle.seg = DAT_2000_d386;
  handle.ofs = DAT_2000_d384;
  psStack_6 = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette((stg_tmp_t *)psStack_6,(int)((ulong)psStack_6 >> 0x10),local_306);
  ovr_driver_2d63_05e5(0xc,7,0xde,0x96,0xec);
  ovr_vgaSetPalette8bit(local_306);
  gfx.seg = DAT_2000_cc87;
  gfx.ofs = DAT_2000_cc85;
  ovr_blitGfxRect(gfx,0,0,BlitRects + 1,0x10,false);
  gfx_00.seg = DAT_2000_d3a6;
  gfx_00.ofs = DAT_2000_d3a4;
  ovr_blitGfxRect(gfx_00,0,0,BlitRects + 1,0x10,false);
  gfx_01.seg = DAT_2000_d3a2;
  gfx_01.ofs = DAT_2000_d3a0;
  ovr_blitGfxRect(gfx_01,0,0,BlitRects + 1,0x10,false);
  return;
}



/* 4d05:0166 */

void __cdecl16far manage_4d05_0166(void)

{
  undefined2 unaff_SS;
  far_t gfx;
  brect_t local_c;
  
  F_SCOPY((uint8_t *)&local_c,(uint8_t *)0x493b,10);
  gfx.seg = DAT_2000_cc87;
  gfx.ofs = DAT_2000_cc85;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)CONCAT22(unaff_SS,&local_c),0x10,false);
  return;
}



/* 4d05:01a3 */

char __cdecl16far manage_4d05_01a3(char param_1,byte param_2)

{
  uint16_t uVar1;
  undefined1 uStack_3;
  
  uStack_3 = '\0';
  while( true ) {
    if (param_1 == '\0') break;
    uVar1 = ovr_randBelow((uint)param_2);
    uStack_3 = (char)uVar1 + uStack_3 + '\x01';
    param_1 = param_1 + -1;
  }
  return uStack_3;
}



/* 4d05:01d4 */

void __cdecl16far manage_4d05_01d4(undefined4 param_1)

{
  char cVar1;
  uint16_t uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined1 uStack_3;
  
  for (uStack_3 = 0; iVar3 = (int)param_1, uVar4 = (undefined2)((ulong)param_1 >> 0x10),
      uStack_3 < 6; uStack_3 = uStack_3 + 1) {
    cVar1 = manage_4d05_01a3(3,6);
    uVar2 = ovr_randBelow(4);
    *(char *)(iVar3 + (uint)uStack_3 + 0x29) = cVar1 + (char)uVar2;
    if (0x11 < *(byte *)(iVar3 + (uint)uStack_3 + 0x29)) {
      *(undefined1 *)(iVar3 + (uint)uStack_3 + 0x29) = 0x12;
    }
  }
  *(byte *)(iVar3 + 0x28) = *(byte *)(iVar3 + 0x28) | 0x20;
  return;
}



/* 4d05:023a */

char * __cdecl16far manage_4d05_023a(int param_1)

{
  int iVar1;
  char *pcStack_6;
  
  iVar1 = param_1 % 10;
  if ((iVar1 == 1) && (param_1 != 0xb)) {
    pcStack_6 = (char *)"st";
  }
  else if ((iVar1 == 2) && (param_1 != 0xc)) {
    pcStack_6 = (char *)"nd";
  }
  else if ((iVar1 == 3) && (param_1 != 0xd)) {
    pcStack_6 = (char *)"rd";
  }
  else {
    pcStack_6 = (char *)"th";
  }
  return pcStack_6;
}



/* 4d05:029d */

undefined1 __cdecl16far manage_4d05_029d(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(char *)(iVar2 + 0x2f) == '\x04') && (0xc < *(byte *)(iVar2 + 0x30))) {
    uVar1 = 0xc;
  }
  else if ((*(char *)(iVar2 + 0x2f) == '\x05') && (10 < *(byte *)(iVar2 + 0x30))) {
    uVar1 = 10;
  }
  else if ((*(char *)(iVar2 + 0x2f) == '\x06') && (8 < *(byte *)(iVar2 + 0x30))) {
    uVar1 = 8;
  }
  else {
    uVar1 = *(undefined1 *)(iVar2 + 0x30);
  }
  return uVar1;
}



/* 4d05:02f1 */

undefined1 __cdecl16far manage_4d05_02f1(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(char *)(iVar2 + 0x2f) == '\x04') && (0xb < *(byte *)(iVar2 + 0x30))) {
    uVar1 = 1;
  }
  else if ((*(char *)(iVar2 + 0x2f) == '\x05') && (9 < *(byte *)(iVar2 + 0x30))) {
    uVar1 = 1;
  }
  else if ((*(char *)(iVar2 + 0x2f) == '\x06') && (7 < *(byte *)(iVar2 + 0x30))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 4d05:0340 */

char __cdecl16far manage_4d05_0340(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(char *)(iVar2 + 0x2f) == '\x04') && (0xb < *(byte *)(iVar2 + 0x30))) {
    cVar1 = *(char *)(iVar2 + 0x30) + '7';
  }
  else if ((*(char *)(iVar2 + 0x2f) == '\x05') && (9 < *(byte *)(iVar2 + 0x30))) {
    cVar1 = *(char *)(iVar2 + 0x30) + '9';
  }
  else if ((*(char *)(iVar2 + 0x2f) == '\x06') && (7 < *(byte *)(iVar2 + 0x30))) {
    cVar1 = *(char *)(iVar2 + 0x30) + '9';
  }
  else {
    cVar1 = '0';
  }
  return cVar1;
}



/* 4d05:03a4 */

char * __cdecl16far manage_4d05_03a4(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  uint16_t local_3a [28];
  
  F_SCOPY((uint8_t *)local_3a,(uint8_t *)(far_t *)(GPlayerTitles + 0x12),0x38);
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(char *)(iVar2 + 0x2f) == -1) {
    pcVar1 = (char *)"Lawful" + 6;
  }
  else if (*(char *)(iVar2 + 0x86) == '\0') {
    if ((*(byte *)(iVar2 + 0x30) < 9) &&
       ((*(char *)(iVar2 + 0x2f) != '\x06' || (*(byte *)(iVar2 + 0x30) < 8)))) {
      pcVar1 = (char *)"Lawful" + 6;
    }
    else {
      pcVar1 = (char *)local_3a[(uint)*(byte *)(iVar2 + 0x34) * 2 +
                                (uint)*(byte *)(iVar2 + 0x2f) * 4];
    }
  }
  else {
    pcVar1 = (char *)((far_t *)(GStatsLabels + 4) +
                     (uint)*(byte *)(iVar2 + 0x34) + (uint)*(byte *)(iVar2 + 0x86) * 2)->ofs;
  }
  return pcVar1;
}



/* 4d05:044e */

uint __cdecl16far manage_4d05_044e(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar1 = 0;
  for (iVar2 = 0; iVar2 < (int)(uint)DAT_2000_d1e6; iVar2 = iVar2 + 1) {
    if ((*(char *)((int)*(undefined4 *)(iVar2 << 2) + 0x3d) != '\0') &&
       (*(char *)((int)*(undefined4 *)(iVar2 << 2) + 0x3f) == '\0')) {
      uVar3 = uVar3 + *(byte *)((int)*(undefined4 *)(iVar2 << 2) + 0x84);
      bVar1 = bVar1 + 1;
    }
  }
  if (bVar1 != 0) {
    uVar3 = uVar3 / bVar1;
  }
  return uVar3;
}



/* 4d05:04c6 */

void __cdecl16far manage_4d05_04c6(char *param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = ovr_font_302d_06ea(param_1,param_2,Font02.ofs,Font02.seg);
  TextBlitX = param_3 - iVar1;
  ovr_blitLabel((char *)CONCAT22(param_2,param_1),(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,
                0x50);
  return;
}



/* 4d05:0519 */

void __cdecl16far manage_4d05_0519(char *param_1,undefined2 param_2,int param_3,uint8_t param_4)

{
  int iVar1;
  
  iVar1 = ovr_font_302d_06ea(param_1,param_2,Font02.ofs,Font02.seg);
  TextBlitX = param_3 - iVar1;
  ovr_blitLabel((char *)CONCAT22(param_2,param_1),(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,
                param_4);
  return;
}



/* 4d05:056e */

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



/* 4d05:0d7b */

undefined2 __cdecl16far manage_4d05_0d7b(byte param_1,undefined4 param_2)

{
  byte bVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_2 >> 0x10);
  if (*(byte *)((int)param_2 + (uint)param_1 + 0x29) < 0x12) {
    for (bVar1 = 0; bVar1 < 3; bVar1 = bVar1 + 1) {
      if ((10 < *(byte *)((int)param_2 + (uint)bVar1 + 0x29)) && (param_1 != bVar1)) {
        return 1;
      }
    }
  }
  return 0;
}



/* 4d05:0dbe */

undefined2 __cdecl16far abilitiesDlg(undefined4 param_1)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  undefined2 unaff_SS;
  char *local_2a [8];
  byte bStack_1a;
  byte bStack_19;
  byte local_18 [6];
  byte local_12 [8];
  byte local_a [8];
  
  F_SCOPY(local_a,(uint8_t *)0x49dd,7);
  F_SCOPY(local_12,(uint8_t *)0x49e4,7);
  while( true ) {
    _fsetmem((char **)CONCAT22(unaff_SS,local_2a),0x10,0);
    local_2a[1] = (char *)"puppetmaker" + 3;
    local_2a[0] = (char *)"Accept";
    bStack_19 = 1;
    cVar3 = manage_4d05_0d7b();
    if (cVar3 != '\0') {
      local_18[bStack_19 + 1] = local_a[*(byte *)((int)param_1 + 0x2f)];
      pcVar2 = (char *)((far_t *)GStatsLabels + local_a[*(byte *)((int)param_1 + 0x2f)])->ofs;
      uVar4 = (uint)bStack_19;
      local_2a[uVar4 * 2 + 1] =
           (char *)*(undefined2 *)
                    ((int)&GStatsLabels[0].seg + (uint)local_a[*(byte *)((int)param_1 + 0x2f)] * 4);
      local_2a[uVar4 * 2] = pcVar2;
      bStack_19 = bStack_19 + 1;
    }
    if ((local_12[*(byte *)((int)param_1 + 0x2f)] != 0xff) &&
       (cVar3 = manage_4d05_0d7b(), cVar3 != '\0')) {
      local_18[bStack_19 + 1] = local_12[*(byte *)((int)param_1 + 0x2f)];
      pcVar2 = (char *)((far_t *)GStatsLabels + local_12[*(byte *)((int)param_1 + 0x2f)])->ofs;
      uVar4 = (uint)bStack_19;
      local_2a[uVar4 * 2 + 1] =
           (char *)*(undefined2 *)
                    ((int)&GStatsLabels[0].seg + (uint)local_12[*(byte *)((int)param_1 + 0x2f)] * 4)
      ;
      local_2a[uVar4 * 2] = pcVar2;
      bStack_19 = bStack_19 + 1;
    }
    if (bStack_19 == 1) {
      return 1;
    }
    ovr_drawString((char *)
                   "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                   ,(char *)"puppetmaker" + 3);
    bStack_1a = ovr_uiInputText(local_2a);
    if (bStack_1a == 0) {
      return 0;
    }
    if (bStack_1a == 1) break;
    local_18[1] = local_18[bStack_1a];
    ovr_drawString((char *)"Select ability to adjust downwards by two points.",
                   (char *)"puppetmaker" + 3);
    _fsetmem((char **)CONCAT22(unaff_SS,local_2a),0x10,0);
    local_2a[1] = (char *)"puppetmaker" + 3;
    local_2a[0] = (char *)"Cancel";
    bStack_19 = 1;
    for (local_18[0] = 0; local_18[0] < 3; local_18[0] = local_18[0] + 1) {
      if ((10 < *(byte *)((int)param_1 + (uint)local_18[0] + 0x29)) && (local_18[1] != local_18[0]))
      {
        local_18[bStack_19 + 1] = local_18[0];
        pcVar2 = (char *)((far_t *)GStatsLabels + local_18[0])->ofs;
        uVar4 = (uint)bStack_19;
        local_2a[uVar4 * 2 + 1] =
             (char *)*(undefined2 *)((int)&GStatsLabels[0].seg + (uint)local_18[0] * 4);
        local_2a[uVar4 * 2] = pcVar2;
        bStack_19 = bStack_19 + 1;
      }
    }
    bStack_1a = ovr_uiInputText(local_2a);
    if (bStack_1a == 0) {
      return 0;
    }
    if (bStack_1a != 1) {
      pcVar1 = (char *)((int)param_1 + (uint)local_18[1] + 0x29);
      *pcVar1 = *pcVar1 + '\x01';
      *(char *)((int)param_1 + (uint)local_18[bStack_1a] + 0x29) =
           *(char *)((int)param_1 + (uint)local_18[bStack_1a] + 0x29) + -2;
      manage_4d05_0081();
      manage_4d05_056e((int)param_1,(*(uint16_t *)((uint8_t *)&(param_1) + 2)));
    }
  }
  return 1;
}



/* 4d05:1095 */

undefined2 __cdecl16far alignmentDlg(undefined4 param_1)

{
  byte *pbVar1;
  byte bVar2;
  char done;
  uint uVar3;
  undefined2 uVar4;
  uint8_t local_a [8];
  
  F_SCOPY(local_a,(uint8_t *)(far_t *)(far_t_ARRAY_2410_49f7 + 3),8);
  do {
    ovr_drawString((char *)"Select an alignment.",(char *)"puppetmaker" + 3);
    bVar2 = ovr_uiInputText((far_t *)GAlignmentsNames,(char *)"puppetmaker" + 3,3,0,0,0);
    uVar3 = (uint)bVar2;
    if (uVar3 == 0) {
      return 0;
    }
    uVar4 = (undefined2)((ulong)param_1 >> 0x10);
    *(char *)((int)param_1 + 0x33) = bVar2 - 1;
    pbVar1 = (byte *)((int)param_1 + 0x28);
    *pbVar1 = *pbVar1 | 4;
    if (DAT_2000_d1e5 != '\0') {
      return 1;
    }
    ovr_drawString(((far_t *)&GAlignmentString + uVar3)->ofs,
                   *(undefined2 *)((int)&GAlignmentString.seg + uVar3 * 4));
    done = ovr_uiInputText(local_a);
    if (done == '\0') {
      return 0;
    }
  } while (done != '\x01');
  return 1;
}



/* 4d05:1146 */

bool __cdecl16far uiPickGender(undefined4 param_1)

{
  char cVar1;
  
  ovr_drawString((char *)"Male or female?",(char *)"puppetmaker" + 3);
  cVar1 = ovr_uiInputText((far_t *)far_t_ARRAY_2410_4933,(char *)"puppetmaker" + 3,2,0,0,0);
  if (cVar1 != '\0') {
    *(char *)((int)param_1 + 0x34) = cVar1 + -1;
  }
  return cVar1 != '\0';
}



/* 4d05:118b */

undefined1 __cdecl16far manage_4d05_118b(byte param_1)

{
  undefined1 uVar1;
  
  if (param_1 < 4) {
    uVar1 = 0xfd;
  }
  else if (param_1 < 6) {
    uVar1 = 0xfe;
  }
  else if (param_1 < 9) {
    uVar1 = 0xff;
  }
  else if (param_1 < 0xd) {
    uVar1 = 0;
  }
  else if (param_1 < 0x10) {
    uVar1 = 1;
  }
  else if (param_1 < 0x12) {
    uVar1 = 2;
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}



/* 4d05:11cb */

void __cdecl16far manage_4d05_11cb(undefined4 param_1)

{
  char cVar1;
  uint16_t uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  byte local_c [8];
  int iStack_4;
  
  F_SCOPY(local_c,(uint8_t *)&DAT_2410_4a0b,7);
  iStack_4 = 0;
  for (iVar5 = 0; uVar6 = (undefined2)((ulong)param_1 >> 0x10), iVar4 = (int)param_1,
      iVar5 < (int)(uint)*(byte *)(iVar4 + 0x30); iVar5 = iVar5 + 1) {
    uVar2 = ovr_randBelow((uint)local_c[*(byte *)(iVar4 + 0x2f)]);
    uVar3 = uVar2 & 0xff;
    cVar1 = manage_4d05_118b(*(undefined1 *)(iVar4 + 0x2d));
    iVar4 = uVar3 + (int)cVar1 + 1;
    if (iVar4 < 1) {
      iVar4 = 1;
    }
    iStack_4 = iStack_4 + iVar4;
  }
  *(undefined1 *)(iVar4 + 0x31) = (undefined1)iStack_4;
  *(undefined1 *)(iVar4 + 0x32) = (undefined1)iStack_4;
  *(byte *)(iVar4 + 0x28) = *(byte *)(iVar4 + 0x28) | 0x10;
  return;
}



/* 4d05:125c */

/* WARNING: Instruction at (ram,0x0004ff54) overlaps instruction at (ram,0x0004ff53)
    */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * __cdecl16far chargen_switch(uint16_t index)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  far_t handle;
  char cVar7;
  char cVar8;
  bool bVar9;
  bool bVar10;
  undefined1 uVar11;
  uint16_t uVar12;
  undefined2 uVar13;
  int iVar14;
  uint uVar15;
  char cVar16;
  undefined2 in_CX;
  char *pcVar17;
  undefined2 in_DX;
  uint *puVar18;
  uint *puVar19;
  char *unaff_BP;
  uint uVar20;
  char *unaff_SI;
  char *pcVar21;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  far_t fVar22;
  far_t fVar23;
  undefined4 uVar24;
  char *pcVar25;
  undefined4 in_stack_00000000;
  int iStack0008;
  undefined2 uStack000a;
  char acStack_13e [36];
  undefined2 auStack_11a [66];
  undefined2 auStack_96 [32];
  char acStack_56 [52];
  undefined2 uStack_22;
  char *pcStack_20;
  uint *in_stack_0000ffe2;
  ulong uVar26;
  undefined1 uVar27;
  undefined1 uVar28;
  undefined1 uVar29;
  byte bVar30;
  char in_stack_0000fff3;
  undefined1 uVar32;
  undefined1 *puVar31;
  uint8_t term;
  undefined1 uVar33;
  
  pcVar17 = (char *)CONCAT11((char)((uint)in_DX >> 8),(byte)index);
  uVar15 = index & 0xff;
  if (6 < uVar15) {
    return (char *)0x0;
  }
  puVar19 = (uint *)(uVar15 * 2);
  uVar11 = (undefined1)((uint)unaff_SS >> 8);
  switch(uVar15) {
  case 0:
    cVar8 = in(pcVar17);
    *unaff_DI = cVar8;
    far_t_2000_d098 = stshStoreFile(unaff_BP,(uint16_t)((ulong)in_stack_00000000 >> 0x10));
    fVar22 = stshStoreFile((char *)"cmidpak.com",1);
    DAT_2000_d096 = fVar22.seg;
    DAT_2000_d094 = fVar22.ofs;
    fVar22 = stshStoreFile((char *)"ibmsnd.com",1);
    DAT_2000_d0ca = fVar22.seg;
    DAT_2000_d0c8 = fVar22.ofs;
    fVar22 = stshStoreFile((char *)"sblaster.com",1);
    DAT_2000_d0ce = fVar22.seg;
    DAT_2000_d0cc = fVar22.ofs;
    DAT_2000_d0d2 = 0;
    DAT_2000_d0d0 = 0;
    fVar22 = stshStoreFile((char *)"fibmbak.com",1);
    DAT_2000_d0d6 = fVar22.seg;
    DAT_2000_d0d4 = fVar22.ofs;
    fVar22 = stshStoreFile((char *)"sbpro.com",1);
    DAT_2000_d0da = fVar22.seg;
    DAT_2000_d0d8 = fVar22.ofs;
    DAT_2000_d0dc = DAT_2000_d0d8;
    DAT_2000_d0de = DAT_2000_d0da;
    fVar22 = stshStoreFile((char *)"paudio.com",1);
    DAT_2000_d0e2 = fVar22.seg;
    DAT_2000_d0e0 = fVar22.ofs;
    DAT_2000_d0e6 = DAT_2000_d0ce;
    DAT_2000_d0e4 = DAT_2000_d0cc;
    fVar22 = stshStoreFile((char *)"adlib.com",1);
    DAT_2000_d0ea = fVar22.seg;
    DAT_2000_d0e8 = fVar22.ofs;
    fVar22 = stshStoreFile((char *)"adlibg.com",1);
    DAT_2000_d0ee = fVar22.seg;
    DAT_2000_d0ec = fVar22.ofs;
    DAT_2000_d0f2 = 0;
    DAT_2000_d0f0 = 0;
    DAT_2000_d09e = 0;
    DAT_2000_d09c = 0;
    fVar22 = stshStoreFile((char *)"sbfm.adv",1);
    DAT_2000_d0a2 = fVar22.seg;
    DAT_2000_d0a0 = fVar22.ofs;
    DAT_2000_d0a6 = 0;
    DAT_2000_d0a4 = 0;
    DAT_2000_d0aa = 0;
    DAT_2000_d0a8 = 0;
    fVar22 = stshStoreFile((char *)"sbp2fm.adv",1);
    DAT_2000_d0ae = fVar22.seg;
    DAT_2000_d0ac = fVar22.ofs;
    fVar22 = stshStoreFile((char *)"sbp1fm.adv",1);
    DAT_2000_d0b2 = fVar22.seg;
    DAT_2000_d0b0 = fVar22.ofs;
    fVar22 = stshStoreFile((char *)"pasfm.adv",1);
    DAT_2000_d0b6 = fVar22.seg;
    DAT_2000_d0b4 = fVar22.ofs;
    fVar22 = stshStoreFile((char *)"pasopl.adv",1);
    DAT_2000_d0ba = fVar22.seg;
    DAT_2000_d0b8 = fVar22.ofs;
    fVar22 = stshStoreFile((char *)"adlib.adv",1);
    DAT_2000_d0be = fVar22.seg;
    DAT_2000_d0bc = fVar22.ofs;
    fVar22 = stshStoreFile((char *)"adlibg.adv",1);
    DAT_2000_d0c2 = fVar22.seg;
    DAT_2000_d0c0 = fVar22.ofs;
    fVar22 = stshStoreFile((char *)"mt32mpu.adv",1);
    DAT_2000_d0c6 = fVar22.seg;
    DAT_2000_d0c4 = (uint16_t)(fVar22.ofs);
    return (char *)fVar22.ofs;
  case 1:
    iVar14 = ovr_OVC23_55fe_2da3();
    if (iVar14 < 0) {
      ovr_drawTextAt("You cannot attract units to this location.",0xa000);
      pcVar17 = (char *)"puppetmaker" + 3;
      *(undefined1 *)(index + 0x9082) = 0;
    }
    else {
      uVar11 = 0x6f;
      uVar27 = 0x23;
      bVar30 = (byte)index;
      DAT_2000_d114 = func_0x0004f501();
      if (DAT_2000_d114 < CONCAT11(uVar27,uVar11)) {
        *(undefined1 *)(index + 0x9082) = (char)DAT_2000_d114;
      }
      pcVar21 = (char *)"halfling castle" + 0xc;
      bVar30 = *(byte *)((int)*(undefined4 *)((uint)bVar30 << 2) + 0x2f);
      pcVar17 = (char *)(uint)bVar30;
      if (bVar30 != 0xff) {
        uVar11 = 0;
        uVar27 = 0xa0;
        ovr_OVC41_6a8f_0000();
        pcVar25 = ovr_stsprintf(acStack_56,"Attracting %d of a possible %d %s%s to this location.",
                                pcVar21);
        pcVar17 = (char *)ovr_drawTextAt(pcVar25,CONCAT11(uVar27,uVar11));
      }
    }
    return pcVar17;
  case 2:
    ((int *)StshHandles)[(int)unaff_SI] = uVar15;
    *(undefined2 *)((int)(long *)StshPtrs + (int)unaff_SI * 4 + 2) = 0;
    *(undefined2 *)((long *)StshPtrs + (int)unaff_SI) = 0;
    return unaff_SI;
  case 3:
    for (iVar14 = 0; iVar14 < (int)(uint)DAT_2000_d1e6; iVar14 = iVar14 + 1) {
      if (((*(char *)((int)*(undefined4 *)(iVar14 << 2) + 0x3d) != '\0') &&
          (pcVar17 = (char *)"puppetmaker" + 3,
          *(int *)((int)*(undefined4 *)(iVar14 << 2) + 0x39) == GfxRndSeed)) &&
         (pcVar17 = (char *)"puppetmaker" + 3,
         *(uint *)((int)*(undefined4 *)(iVar14 << 2) + 0x3b) == GfxRndSeed2)) {
        if (GCharLevelsInc != '\0') {
          uVar13 = (undefined2)((ulong)*(undefined4 *)(iVar14 << 2) >> 0x10);
          iVar14 = (int)*(undefined4 *)(iVar14 << 2);
          puVar1 = (uint *)(iVar14 + 0x56);
          uVar15 = *puVar1;
          *puVar1 = *puVar1 + 10000;
          piVar2 = (int *)(iVar14 + 0x58);
          *piVar2 = *piVar2 + (uint)(0xd8ef < uVar15);
          GCharLevelsInc = '\0';
        }
        manage_4d05_1bee();
        ovr_stats_6386_232d();
        pcVar17 = (char *)ovr_OVC41_6a8f_18c6();
        return pcVar17;
      }
    }
    ovr_stats_6386_00f8();
    if (DAT_2000_d1e4 == 0) {
      if (DAT_2000_d1e3 <= DAT_2000_d1e5) {
        pcVar17 = (char *)ovr_OVC41_6a8f_18c6();
        return pcVar17;
      }
      iVar14 = chargen();
      uVar28 = SUB21(pcVar17,0);
      uVar29 = (undefined1)((uint)pcVar17 >> 8);
      uVar11 = (undefined1)iVar14;
      uVar27 = (undefined1)((uint)iVar14 >> 8);
      if (iVar14 == 0 && pcVar17 == (char *)0x0) {
        ovr_stats_6386_232d();
        pcVar17 = (char *)ovr_OVC41_6a8f_18c6();
        return pcVar17;
      }
      iVar14 = 0;
      while ((iVar14 < (int)(uint)DAT_2000_d1e6 &&
             (*(char *)((int)*(undefined4 *)(iVar14 << 2) + 0x28) != '\0'))) {
        iVar14 = iVar14 + 1;
      }
      if (iVar14 < (int)(uint)DAT_2000_d1e6) {
        DAT_2000_d1e4 = (char)iVar14 + 1;
        uVar13 = *(undefined2 *)((uint)DAT_2000_d1e4 * 4 + -2);
        (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)uVar13;
        handle.ofs = *(undefined2 *)((uint)DAT_2000_d1e4 * 4 + -4);
        (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)uVar13 >> 8);
        ovr_stshFree(handle);
      }
      else {
        if (0x4f < DAT_2000_d1e6) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x1d);
        }
        DAT_2000_d1e4 = DAT_2000_d1e6 + 1;
        DAT_2000_d1e6 = DAT_2000_d1e4;
      }
      pbVar3 = (byte *)(CONCAT11(uVar27,uVar11) + 0x28);
      *pbVar3 = *pbVar3 | 0x40;
      *(char *)(CONCAT11(uVar27,uVar11) + 0x51) = DAT_2000_d1e4 - 1;
      uVar15 = (uint)DAT_2000_d1e4;
      *(undefined2 *)(uVar15 * 4 + -2) = CONCAT11(uVar29,uVar28);
      *(undefined2 *)(uVar15 * 4 + -4) = CONCAT11(uVar27,uVar11);
      if (DAT_2000_d1e5 == 0) {
        *(undefined1 *)(CONCAT11(uVar27,uVar11) + 0x86) = 1;
      }
      DAT_2000_d1e5 = DAT_2000_d1e5 + 1;
    }
    else {
      manage_4d05_0081();
      uVar13 = *(undefined2 *)((uint)DAT_2000_d1e4 * 4 + -4);
      uVar11 = (undefined1)uVar13;
      uVar27 = (undefined1)((uint)uVar13 >> 8);
      manage_4d05_056e();
    }
    ovr_fmVsprintf((char *)"Place %s here.",(char *)CONCAT11(uVar27,uVar11));
    ovr_drawString();
    cVar8 = ovr_uiInputText();
    if (cVar8 == '\x01') {
      if (DAT_2000_d1e5 == 1) {
        ovr_OVC18_48ac_05f2();
      }
      else {
        ovr_OVC18_48ac_05f2();
      }
      pcVar17 = (char *)ovr_OVC41_6a8f_18c6();
    }
    else {
      ovr_stats_6386_232d();
      pcVar17 = (char *)ovr_OVC41_6a8f_18c6();
    }
    return pcVar17;
  case 5:
    fVar22 = far_from_u32((uint32_t)(ovr_mkp((uint16_t)unaff_BP,(uint16_t)in_stack_00000000)));
    uVar12 = fVar22.seg;
    pcVar17 = (char *)fVar22.ofs;
    if (*(char *)MK_FP(fVar22.seg, fVar22.ofs) == '\0') {
      uVar13 = (undefined2)((ulong)in_stack_00000000 >> 0x10);
      fVar23 = fmMalloc(CONCAT22(*(undefined2 *)(pcVar17 + 7),*(undefined2 *)(pcVar17 + 5)));
      uVar27 = (undefined1)fVar23.seg;
      uVar28 = (*(uint8_t *)((uint8_t *)&(fVar23.seg) + 1));
      bVar30 = (byte)fVar23.ofs;
      uVar11 = (*(uint8_t *)((uint8_t *)&(fVar23.ofs) + 1));
      if (far_to_u32(fVar23) == 0) {
        pcVar17 = (char *)0x0;
      }
      else {
        if (*(int *)(pcVar17 + 0x11) == 0 && *(int *)(pcVar17 + 0x13) == 0) {
          stshSeek(StshStrongDatHnd,CONCAT22(uVar13,*(undefined2 *)(pcVar17 + 3)));
          (*(uint8_t *)((uint8_t *)&(fVar23.ofs) + 1)) = uVar11;
          (*(uint8_t *)((uint8_t *)&(fVar23.ofs))) = bVar30;
          (*(uint8_t *)((uint8_t *)&(fVar23.seg))) = uVar27;
          (*(uint8_t *)((uint8_t *)&(fVar23.seg) + 1)) = uVar28;
          stshRead(StshStrongDatHnd,fVar23,
                   CONCAT22(*(undefined2 *)(pcVar17 + 7),*(undefined2 *)(pcVar17 + 5)));
          fVar23 = ovr_heapMalloc(CONCAT22(*(undefined2 *)(pcVar17 + 7),*(undefined2 *)(pcVar17 + 5)
                                          ));
          *(uint16_t *)(pcVar17 + 0x13) = fVar23.seg;
          *(uint16_t *)(pcVar17 + 0x11) = fVar23.ofs;
          if (*(int *)(pcVar17 + 0x11) == 0 && *(int *)(pcVar17 + 0x13) == 0) {
            bVar9 = false;
          }
          else {
            memcpy(*(uint8_t **)(pcVar17 + 0x11),(uint8_t *)CONCAT11(uVar11,bVar30),
                   *(uint16_t *)(pcVar17 + 5));
            bVar9 = true;
          }
        }
        else {
          memcpy((uint8_t *)fVar23.ofs,*(uint8_t **)(pcVar17 + 0x11),*(uint16_t *)(pcVar17 + 5));
          bVar9 = true;
        }
        if (bVar9) {
          fVar23 = far_from_u32((uint32_t)(ovr_mkp(Stsh_2410_47f6.ofs,Stsh_2410_47f6.seg)));
          if (far_to_u32(fVar23) != far_to_u32(fVar22)) {
            iVar14 = *(int *)(pcVar17 + 0xf);
            iVar4 = *(int *)(pcVar17 + 0xd);
            uVar5 = *(uint16_t *)(pcVar17 + 0xb);
            uVar6 = *(uint16_t *)(pcVar17 + 9);
            if (uVar6 != 0 || uVar5 != 0) {
              uVar13 = (undefined2)
                       (CONCAT13((char)(uVar5 >> 8),CONCAT12((char)uVar5,uVar6)) >> 0x10);
              *(int *)(uVar6 + 0xf) = iVar14;
              *(int *)(uVar6 + 0xd) = iVar4;
            }
            if (iVar4 != 0 || iVar14 != 0) {
              uVar13 = (undefined2)
                       (CONCAT13((char)((uint)iVar14 >> 8),CONCAT12((char)iVar14,iVar4)) >> 0x10);
              *(uint16_t *)(iVar4 + 0xb) = uVar5;
              *(uint16_t *)(iVar4 + 9) = uVar6;
              uVar6 = StshCtPtr2.ofs;
              uVar5 = StshCtPtr2.seg;
            }
            StshCtPtr2.seg = uVar5;
            StshCtPtr2.ofs = uVar6;
            uVar5 = Stsh_2410_47f6.ofs;
            *(uint16_t *)(pcVar17 + 0xf) = Stsh_2410_47f6.seg;
            *(uint16_t *)(pcVar17 + 0xd) = uVar5;
            (pcVar17 + 0xb)[0] = '\0';
            (pcVar17 + 0xb)[1] = '\0';
            (pcVar17 + 9)[0] = '\0';
            (pcVar17 + 9)[1] = '\0';
            *(uint16_t *)(Stsh_2410_47f6.ofs + 0xb) = uVar12;
            *(undefined2 *)(Stsh_2410_47f6.ofs + 9) = pcVar17;
            Stsh_2410_47f6 = fVar22;
          }
        }
        pcVar17 = (char *)(uint)bVar30;
      }
    }
    return pcVar17;
  case 6:
    goto switchD_4000_e2bf_caseD_6;
  }
  if ((uVar15 == 0) && (manage_4d05_0081(), in_stack_0000fff3 == '\x02')) {
    if (DAT_2410_26a8 == '\0') {
      manage_4d05_0081();
    }
    TextBlitY = 0xc;
    TextBlitX = 0x11;
    uVar27 = (undefined1)Font02.seg;
    uVar28 = (undefined1)(Font02.seg >> 8);
    if ((byte)index == 0xff) {
      cVar8 = -8;
      cVar16 = 'T';
      iVar14 = ovr_blitLabel("Total population.",
                             (uint8_t *)CONCAT13(uVar28,CONCAT12(uVar27,Font02.ofs)),222,0x50);
      *unaff_SI = *unaff_SI + (char)((uint)iVar14 >> 8) + ((undefined1 *)0xfff3 < &stack0xfff2);
      *(undefined1 *)((*(far_t *)&Entities).ofs + iVar14 + 0x18) = 0;
      *(undefined1 *)(Entities.ofs + (int)unaff_SI * 0x37 + 0x31) =
           *(undefined1 *)(Entities.ofs + (int)unaff_SI * 0x37 + 0x32);
      if (EntityCount <= unaff_SI + 1) {
        if ((cVar8 != '\0') || (cVar16 != '\0')) {
          if ((char)((uint)((int)unaff_SI * 0x37) >> 8) == '\0') {
            ovr_stop_audio();
            CurSfxType3 = 0xff;
            ovr_play_sfx(90,0);
          }
          else if (cVar16 == '\0') {
            if (cVar8 != '\0') {
              ovr_play_sfx(37,0);
            }
          }
          else {
            ovr_play_sfx(35,0);
          }
        }
        GGameState = 0x3d;
        if (DebugVerbose != false) {
          printf("%d \r",0x3d);
        }
        pcVar17 = (char *)ovr_OVC23_55fe_2b82();
        return pcVar17;
      }
      pcVar17 = (char *)"thief" + 5;
      ovr_say((char *)CONCAT22(unaff_BP,(char *)
                                        "The damaged structures belonging to all leaders are highlighted in red."
                              ));
      return pcVar17;
    }
    term = 0x50;
    uVar29 = 0xde;
    uVar32 = 0;
    uVar12 = Font02.ofs;
    ovr_OVC45_77eb_226e();
    uVar24 = func_0x0005d3f4();
    pcVar17 = (char *)*(undefined2 *)((uint)*(byte *)((int)uVar24 + 0x2f) * 4 + 0xeb);
    pcStack_20 = (char *)"trade faire" + 8;
    uStack_22 = 0x44;
    pcVar25 = ovr_stsprintf(acStack_13e,"%s population, loyal to %s%s",pcVar17);
    ovr_blitLabel(pcVar25,(uint8_t *)CONCAT13(uVar28,CONCAT12(uVar27,uVar12)),
                  CONCAT11(uVar32,uVar29),term);
    TextBlitY = TextBlitY + 0xc;
    iVar14 = ovr_font_302d_06ea();
    TextBlitX = 0x89 - iVar14;
    ovr_blitLabel("UNITS",(uint8_t *)
                          CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs)),
                  222,0xe0);
    iVar14 = ovr_font_302d_06ea();
    uVar12 = 0xd4 - iVar14;
    cVar8 = '\x10';
    bVar30 = 0x24;
    TextBlitX = uVar12;
    ovr_blitLabel("POPULATION",
                  (uint8_t *)CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs))
                  ,222,0xe0);
    pcVar21 = (char *)0x0;
    while( true ) {
      TextBlitY = TextBlitY + 0xc;
      cVar16 = (char)in_CX;
      if ((int)(uint)bVar30 <= (int)pcVar21) break;
      TextBlitX = 0x11;
      uVar27 = (undefined1)(Font02.seg >> 8);
      if (((int)pcVar21 < 5) || (cVar8 == '\0')) {
        ovr_blitLabel((char *)CONCAT13((char)((uint)auStack_96[(int)pcVar21 * 2 + 1] >> 8),
                                       CONCAT12((char)auStack_96[(int)pcVar21 * 2 + 1],
                                                auStack_96[(int)pcVar21 * 2])),
                      (uint8_t *)CONCAT13(uVar27,CONCAT12((char)Font02.seg,Font02.ofs)),319,0xe0);
      }
      else {
        uVar24 = *(undefined4 *)((index & 0xff) << 2);
        uVar15 = (uint)*(byte *)((int)uVar24 + 0x2f);
        ovr_blitLabel((char *)CONCAT13((char)((uint)auStack_11a[(int)pcVar21 * 2 + uVar15 * 8 + 1]
                                             >> 8),
                                       CONCAT12((char)auStack_11a[(int)pcVar21 * 2 + uVar15 * 8 + 1]
                                                ,auStack_11a[(int)pcVar21 * 2 + uVar15 * 8])),
                      (uint8_t *)CONCAT13(uVar27,CONCAT12((char)Font02.seg,Font02.ofs)),319,0xe0);
      }
      uVar27 = 0xb7;
      uVar28 = 1;
      OVC27_5ded_1433();
      ovr_stsprintf(acStack_13e,"%d",(char *)CONCAT11(uVar28,uVar27));
      iVar14 = ovr_font_302d_06ea();
      TextBlitX = 0x89 - iVar14;
      ovr_blitLabel((char *)CONCAT13(uVar11,CONCAT12((char)unaff_SS,acStack_13e)),
                    (uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0x50);
      ovr_stsprintf(acStack_13e,"%d",pcVar17);
      iVar14 = ovr_font_302d_06ea();
      uVar12 = 0xd4 - iVar14;
      cVar8 = (char)Font02.ofs;
      bVar30 = (byte)(Font02.ofs >> 8);
      TextBlitX = uVar12;
      ovr_blitLabel((char *)CONCAT13(uVar11,CONCAT12((char)unaff_SS,acStack_13e)),
                    (uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0x50);
      pcVar21 = pcVar21 + 1;
    }
    CurSfxType3 = 0x3c;
    puVar31 = &stack0xfff2;
    cVar8 = ovr_OVC28_6018_1398();
    DAT_2410_5cf0 = 0;
    if (((cVar8 != '\0') && (cVar8 != '\x01')) && (cVar8 != -2)) {
      (&stack0xbac4)[(int)unaff_DI] = (&stack0xbac4)[(int)unaff_DI] + cVar16;
      pcVar17 = (char *)"puppetmaker" + 3;
      do {
        bVar30 = *(byte *)((int)pcVar17 * uVar12 + 0x21);
        uVar11 = (undefined1)((int)pcVar17 * uVar12 >> 8);
        pcVar17 = pcVar21;
        if (*(byte *)((int)pcVar21 * 0x34 + 0x22) < bVar30) {
          bVar30 = *(byte *)((int)pcVar21 * 0x34 + 0x22);
          uVar11 = (undefined1)((uint)((int)pcVar21 * 0x34) >> 8);
          *(byte *)((int)pcVar21 * 0x34 + 0x21) = bVar30;
        }
        do {
          pcVar17 = pcVar17 + 1;
          if ((int)(uint)AgntCount <= (int)pcVar17) {
            uVar12 = ovr_audio_3a5b_0afd();
            ovr_play_sfxU(0x1c,0,uVar12);
            return (char *)((int)(undefined4 *)&_DATA + 1);
          }
        } while (*(int *)((int)pcVar17 * 0x34 + 0x1b) != *(int *)(iStack0008 + 0x1b));
        if ((byte)puVar31[0x32] < *(byte *)((int)pcVar17 * 0x34 + 0x22)) {
          *(undefined1 *)((int)pcVar17 * 0x34 + 0x22) = puVar31[0x32];
        }
        uVar12 = 0x34;
        pcVar21 = pcVar17;
      } while( true );
    }
    if (cVar8 == -2) {
      DAT_2410_4926 = 1;
    }
    return (char *)"puppetmaker" + 3;
  }
  do {
    uVar13 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
    puVar18 = (uint *)in_stack_0000ffe2;
    *(byte *)(puVar18 + 6) =
         (byte)((int)(uint)*(byte *)((int)puVar18 +
                                    ((int)(uint)*(byte *)((int)puVar19 + 0x2f) >> 2) + 0x1b) >>
               ((*(byte *)((int)puVar18 + 0x2f) & 3) << 1)) & 3;
    cVar8 = func_0x0004f32d();
    puVar19 = (uint *)in_stack_0000ffe2;
    uVar13 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
    if (cVar8 == '\0') {
      *in_stack_0000ffe2 = *in_stack_0000ffe2 + (int)*(char *)((byte)puVar19[6] + 0x885);
      puVar19[1] = puVar19[1] + (int)*(char *)((byte)puVar19[6] + 0x889);
      *(char *)((int)puVar19 + 0x2f) = *(char *)((int)puVar19 + 0x2f) + '\x01';
    }
    else {
      *(undefined1 *)((int)puVar19 + 0x2f) = 0;
      *(undefined1 *)(puVar19 + 0x18) = 0;
    }
LAB_3f0b_1477:
    uVar26 = 0x1000000;
    uVar13 = ovr_OVC23_55fe_3450();
    uVar32 = (undefined1)uVar13;
    uVar33 = (undefined1)((uint)uVar13 >> 8);
    uVar28 = (undefined1)*in_stack_0000ffe2;
    uVar29 = (undefined1)(*in_stack_0000ffe2 >> 8);
    uVar11 = 0x79;
    uVar27 = 0x23;
    iVar14 = ovr_OVC23_55fe_3450();
    uVar15 = CONCAT11(uVar29,uVar28);
    if (CONCAT11(uVar33,uVar32) == iVar14) {
      uVar13 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
      puVar19 = (uint *)in_stack_0000ffe2;
      uVar15 = CONCAT11(uVar29,uVar28);
      if (puVar19[5] == puVar19[1]) {
        puVar19[4] = 0;
        puVar19[5] = 0;
        if ((char)puVar19[0xd] == -1) {
          cVar8 = -1;
        }
        else {
          uVar24 = *(undefined4 *)((uint)(byte)puVar19[0xd] << 2);
          cVar8 = *(char *)((int)uVar24 + 0x89);
        }
        uVar15 = CONCAT11(uVar29,uVar28);
        if (cVar8 != -1) {
          for (uVar20 = 0; uVar15 = CONCAT11(uVar29,uVar28), uVar20 < DAT_2410_0881;
              uVar20 = uVar20 + 1) {
            uVar13 = ovr_OVC23_55fe_3450();
            bVar30 = (byte)uVar13;
            uVar32 = (undefined1)((uint)uVar13 >> 8);
            uVar28 = (undefined1)*in_stack_0000ffe2;
            uVar29 = (undefined1)(*in_stack_0000ffe2 >> 8);
            uVar11 = 0x79;
            uVar27 = 0x23;
            iVar14 = ovr_OVC23_55fe_3450();
            if ((CONCAT11(uVar32,bVar30) == iVar14) &&
               (*(uint *)(uVar20 * 0x13 + 2) == ((uint *)in_stack_0000ffe2)[1])) {
              uVar15 = uVar20 * 0x13 + (uint)bVar30 + 0xe;
              uVar11 = 0x79;
              uVar27 = 0x23;
              manage_4d05_28e0();
              if (*(uint *)(uVar20 * 0x13 + 2) == GfxRndSeed2) {
                uVar13 = ovr_OVC23_55fe_3450();
                bVar30 = (byte)uVar13;
                uVar32 = (undefined1)((uint)uVar13 >> 8);
                uVar28 = (undefined1)GfxRndSeed;
                uVar29 = (undefined1)((uint)GfxRndSeed >> 8);
                uVar11 = 0x79;
                uVar27 = 0x23;
                iVar14 = ovr_OVC23_55fe_3450();
                uVar15 = CONCAT11(uVar29,uVar28);
                if (CONCAT11(uVar32,bVar30) == iVar14) {
                  (&stack0xfff2)[bVar30] = 1;
                  uVar15 = CONCAT11(uVar29,uVar28);
                }
              }
              break;
            }
          }
        }
      }
    }
    if (AgntFlag1 != false) {
      uVar13 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
      if (((*in_stack_0000ffe2 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < *in_stack_0000ffe2)) ||
         (((uint *)in_stack_0000ffe2)[1] != GfxRndSeed2)) {
        bVar9 = false;
      }
      else {
        bVar9 = true;
      }
      if (((uVar15 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uVar15)) ||
         (GfxRndSeed2 != CONCAT11(uVar27,uVar11))) {
        bVar10 = false;
      }
      else {
        bVar10 = true;
      }
      uVar26 = uVar26 & 0xff000000;
      if (bVar10 || bVar9) {
        if (bVar10) {
          if (bVar9) {
            uVar11 = manage_4d05_28f4();
            uVar26 = CONCAT31((int3)(uVar26 >> 8),uVar11);
            while (((char)uVar26 != '\0' && (cVar8 = ovr_OVC15_4207_2301(), cVar8 != '\0'))) {
              uVar26 = CONCAT31((int3)(uVar26 >> 8),(char)uVar26 + -1);
            }
          }
          else {
            uVar26 = CONCAT31((int3)(uVar26 >> 8),
                              (char)((ulong)((byte)((uint *)in_stack_0000ffe2)[7] + 0xf) / 0x10));
            while (cVar8 = (char)uVar26, uVar26 = CONCAT31((int3)(uVar26 >> 8),cVar8 + -1),
                  cVar8 != '\0') {
              (*(uint8_t *)((uint8_t *)&(fVar22.seg))) = (char)Entities.seg;
              fVar22.ofs = Entities.ofs + (int)unaff_DI * 0x37;
              (*(uint8_t *)((uint8_t *)&(fVar22.seg) + 1)) = (*(uint8_t *)((uint8_t *)&(Entities.seg) + 1));
              ovr_agnt_3b1d_196b(fVar22);
            }
          }
        }
        else {
          ovr_OVC15_4207_0b88();
          uVar26 = CONCAT31((int3)(uVar26 >> 8),
                            (char)((ulong)((byte)((uint *)in_stack_0000ffe2)[7] + 0xf) / 0x10));
          while (cVar8 = (char)uVar26, uVar26 = CONCAT31((int3)(uVar26 >> 8),cVar8 + -1),
                cVar8 != '\0') {
            ovr_OVC15_4207_2301();
          }
        }
      }
    }
    do {
      cVar8 = (char)(uVar26 >> 0x18);
      unaff_DI = unaff_DI + 1;
      if (EntityCount <= unaff_DI) {
        GGameState = 0x3c;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r",0x3c);
        }
        func_0x0004fcda();
        GGameState = 0x3d;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r",0x3d);
        }
        ovr_OVC23_55fe_2b82();
        GGameState = 0xc;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r",0xc);
        }
        ovr_OVC24_5943_0d5a();
        GGameState = 0x1f;
        if (cVar8 != '\0') {
          ovr_constr_36ce_03a6();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (iVar14 = 0; iVar14 < 5; iVar14 = iVar14 + 1) {
          if ((&stack0xfff2)[iVar14] != '\0') {
            ovr_OVC41_6a8f_1be0();
          }
        }
        GGameState = 0xd;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r",0xd);
        }
        ovr_OVC24_5943_112e();
        GGameState = 0xe;
        DAT_2410_648e = 1;
        return (char *)"puppetmaker" + 3;
      }
      in_stack_0000ffe2 =
           (uint *)CONCAT22(Entities.seg,(uint *)(Entities.ofs + (int)unaff_DI * 0x37));
      uVar13 = ovr_OVC23_55fe_3450();
      uVar11 = (undefined1)uVar13;
      uVar27 = (undefined1)((uint)uVar13 >> 8);
      iVar14 = ovr_OVC23_55fe_3450();
      if ((CONCAT11(uVar27,uVar11) == iVar14) &&
         (uVar13 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10),
         ((uint *)in_stack_0000ffe2)[5] == ((uint *)in_stack_0000ffe2)[1])) {
        manage_4d05_2b3e();
      }
      unaff_ES = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
      puVar19 = (uint *)in_stack_0000ffe2;
    } while ((puVar19[4] == 0 && puVar19[5] == 0) || ((char)puVar19[0xc] != '\0'));
  } while (*(byte *)((int)puVar19 + 0x2f) < (byte)puVar19[0x18]);
  uVar13 = ovr_OVC07_32c9_0026();
  cVar16 = (char)uVar13;
  uVar27 = (undefined1)((uint)uVar13 >> 8);
  uVar13 = ovr_OVC07_32c9_0026();
  cVar8 = (char)uVar13;
  uVar11 = (undefined1)((uint)uVar13 >> 8);
  if (((CONCAT11(uVar27,cVar16) == 0) || (uVar12 = ovr_randBelow(2), (char)uVar12 == '\0')) ||
     (cVar7 = func_0x0004f412(), cVar7 != '\0')) {
    if ((CONCAT11(uVar11,cVar8) == 0) || (cVar7 = func_0x0004f412(), cVar7 != '\0')) {
      if ((CONCAT11(uVar27,cVar16) == 0) || (cVar8 = func_0x0004f412(), cVar8 != '\0')) {
        cVar8 = ovr_OVC26_5d45_031f();
        if (cVar8 == '\0') {
          cVar8 = ovr_OVC26_5d45_06f0();
          if (cVar8 == '\0') {
            puVar19 = (uint *)((uint)*(byte *)((int)(uint *)in_stack_0000ffe2 + 0xd) * 0x95);
            pcVar17 = (char *)0x195d;
switchD_4000_e2bf_caseD_6:
            if ((char)puVar19[0x136b] == '\0') {
              manage_4d05_2b3e();
            }
          }
        }
        else {
          uVar13 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
          puVar19 = (uint *)in_stack_0000ffe2;
          *(byte *)(puVar19 + 6) =
               (byte)((int)(uint)*(byte *)((int)puVar19 +
                                          ((int)(uint)*(byte *)((int)puVar19 + 0x2f) >> 2) + 0x1b)
                     >> ((*(byte *)((int)puVar19 + 0x2f) & 3) << 1)) & 3;
          cVar8 = func_0x0004f32d();
          if (cVar8 == '\0') {
            uVar13 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
            puVar19 = (uint *)in_stack_0000ffe2;
            *in_stack_0000ffe2 = *in_stack_0000ffe2 + (int)*(char *)((byte)puVar19[6] + 0x885);
            puVar19[1] = puVar19[1] + (int)*(char *)((byte)puVar19[6] + 0x889);
            *(char *)((int)puVar19 + 0x2f) = *(char *)((int)puVar19 + 0x2f) + '\x01';
          }
        }
      }
      else {
        *in_stack_0000ffe2 = *in_stack_0000ffe2 + CONCAT11(uVar27,cVar16);
        *(char *)((uint *)in_stack_0000ffe2 + 6) = '\x02' - cVar16;
      }
    }
    else {
      uVar13 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
      puVar1 = (uint *)in_stack_0000ffe2 + 1;
      *puVar1 = *puVar1 + CONCAT11(uVar11,cVar8);
      *(char *)((uint *)in_stack_0000ffe2 + 6) = cVar8 + '\x01';
    }
  }
  else {
    *in_stack_0000ffe2 = *in_stack_0000ffe2 + CONCAT11(uVar27,cVar16);
    *(char *)((uint *)in_stack_0000ffe2 + 6) = '\x02' - cVar16;
  }
  goto LAB_3f0b_1477;
}



/* 4d05:1296 */

char * __cdecl16far chargen(void)

{
  char *pcVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  uint16_t uVar5;
  int iVar6;
  undefined2 unaff_SS;
  char *pcVar7;
  far_t handle;
  far_t handle_00;
  char acStack_9d [11];
  char *local_92 [22];
  char local_66 [80];
  char *pcStack_16;
  uint16_t uStack_14;
  int iStack_12;
  uint uStack_10;
  uint16_t uStack_e;
  uint16_t uStack_c;
  uint8_t local_a [8];
  
  F_SCOPY(local_a,(uint8_t *)(far_t *)GKeepDiscardStrings,8);
  ovr_fmFreeAudio(1);
  ovr_OVC13_3d16_1abd();
  pcVar7 = ovr_stshAlloc(0xae);
  pcStack_16 = (char *)pcVar7;
  uStack_14 = (uint16_t)((ulong)pcVar7 >> 0x10);
  do {
    while( true ) {
      _fmemset((char *)CONCAT22(uStack_14,pcStack_16),0,0xae);
      pcStack_16[0x51] = -1;
      while( true ) {
        if (TimerSeed.lo == 0 && TimerSeed.hi == 0) {
          TimerSeed.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
          TimerSeed.lo = *(uint16_t *)BDA_DailyTimeCounter;
        }
        srand8(CONCAT22(TimerSeed.hi,TimerSeed.lo));
        manage_4d05_0081();
        manage_4d05_01d4(pcStack_16);
        manage_4d05_056e(pcStack_16);
        local_92[1] = (char *)"puppetmaker" + 3;
        local_92[0] = (char *)"Reroll";
        acStack_9d[0] = '\0';
        local_92[3] = (char *)0x0;
        local_92[2] = (char *)0x0;
        iVar4 = 1;
        for (iStack_12 = 0; iVar6 = iVar4 + 1, iStack_12 < 4; iStack_12 = iStack_12 + 1) {
          acStack_9d[iVar4] = (char)iStack_12 + '\x02';
          pcVar1 = (char *)*(undefined2 *)(iStack_12 * 4 + 0xeb);
          local_92[iVar6 * 2 + 1] = (char *)*(undefined2 *)(iStack_12 * 4 + 0xed);
          local_92[iVar6 * 2] = pcVar1;
          iVar4 = iVar6;
        }
        acStack_9d[iVar4] = '\x06';
        if ((byte)pcStack_16[0x2d] < 9) {
          local_92[iVar6 * 2 + 1] = (char *)0x0;
          local_92[iVar6 * 2] = (char *)0x0;
        }
        else {
          local_92[iVar6 * 2 + 1] = (char *)GUnitDescriptions[4].seg;
          local_92[iVar6 * 2] = (char *)GUnitDescriptions[4].ofs;
        }
        iVar6 = iVar4 + 2;
        acStack_9d[iVar4 + 1] = '\a';
        if ((byte)pcStack_16[0x2a] < 9) {
          local_92[iVar6 * 2 + 1] = (char *)0x0;
          local_92[iVar6 * 2] = (char *)0x0;
        }
        else {
          local_92[iVar6 * 2 + 1] = (char *)GUnitDescriptions[5].seg;
          local_92[iVar6 * 2] = (char *)GUnitDescriptions[5].ofs;
        }
        iVar6 = iVar4 + 3;
        acStack_9d[iVar4 + 2] = '\b';
        if (((byte)pcStack_16[0x2d] < 9) || ((byte)pcStack_16[0x2c] < 9)) {
          local_92[iVar6 * 2 + 1] = (char *)0x0;
          local_92[iVar6 * 2] = (char *)0x0;
        }
        else {
          local_92[iVar6 * 2 + 1] = (char *)GUnitDescriptions[6].seg;
          local_92[iVar6 * 2] = (char *)GUnitDescriptions[6].ofs;
        }
        ovr_drawString((char *)"Reroll ability scores, or select the character\'s class.");
        bVar2 = ovr_uiInputText(local_92);
        uStack_10 = (uint)bVar2;
        if (uStack_10 != 0) {
          uStack_10 = (uint)(char)(&stack0xff61)[uStack_10];
        }
        if (uStack_10 == 0) goto LAB_4d05_17b2;
        if (uStack_10 != 1) break;
        TimerSeed.hi = 0;
        TimerSeed.lo = 0;
      }
      uStack_10 = uStack_10 - 1;
      if (DAT_2000_d19d < 2) {
        pcStack_16[0x5d] = pcStack_16[0x5d] | 4;
      }
      else {
        pcStack_16[0x5d] = pcStack_16[0x5d] | 6;
      }
      pcStack_16[0x2f] = (char)uStack_10 + -1;
      cVar3 = chargen_switch(CONCAT11(0x24,pcStack_16[0x2f]));
      pcStack_16[0x3e] = cVar3;
      pcStack_16[0x30] = '\x06';
      iVar4 = (uint)(byte)pcStack_16[0x2f] * 0x94 + (uint)(byte)pcStack_16[0x30] * 4;
      uVar5 = *(uint16_t *)(iVar4 + -4);
      *(undefined2 *)(pcStack_16 + 0x37) = *(undefined2 *)(iVar4 + -2);
      *(uint16_t *)(pcStack_16 + 0x35) = uVar5;
      pcStack_16[0x28] = pcStack_16[0x28] | 8;
      pcStack_16[0x28] = pcStack_16[0x28] | 1;
      if (DAT_2000_d19d == 1) {
        (pcStack_16 + 0x58)[0] = '\0';
        (pcStack_16 + 0x58)[1] = '\0';
        (pcStack_16 + 0x56)[0] = -0xc;
        (pcStack_16 + 0x56)[1] = '\x01';
      }
      else if (DAT_2000_d19d == 2) {
        (pcStack_16 + 0x58)[0] = '\0';
        (pcStack_16 + 0x58)[1] = '\0';
        (pcStack_16 + 0x56)[0] = ',';
        (pcStack_16 + 0x56)[1] = '\x01';
      }
      else {
        (pcStack_16 + 0x58)[0] = '\0';
        (pcStack_16 + 0x58)[1] = '\0';
        (pcStack_16 + 0x56)[0] = 'd';
        (pcStack_16 + 0x56)[1] = '\0';
      }
      pcStack_16[0x85] = '\a';
      pcStack_16[0x89] = -1;
      manage_4d05_056e(pcStack_16);
      cVar3 = abilitiesDlg(pcStack_16);
      if (cVar3 == '\0') break;
      manage_4d05_11cb(pcStack_16);
      while( true ) {
        manage_4d05_056e(pcStack_16);
        cVar3 = alignmentDlg(pcStack_16);
        if (cVar3 == '\0') break;
LAB_4d05_1661:
        manage_4d05_0081();
        manage_4d05_056e(pcStack_16);
        cVar3 = uiPickGender(pcStack_16);
        if (cVar3 != '\0') {
          do {
            manage_4d05_0166();
            ovr_drawString((char *)"Select the character\'s name.");
            while (uStack_e = ovr_uiReadString(0,0,6,0), uStack_c = uVar5,
                  uStack_e == 0 && uVar5 == 0) {
              if (DAT_2000_d19c != '\0') {
                if (UserWantsExit == '\0') goto LAB_4d05_1661;
                goto LAB_4d05_17b2;
              }
              manage_4d05_0166();
              ovr_drawString((char *)"Please type your character\'s name. Esc go back.");
            }
            ovr_drawString((char *)"Lawful" + 6);
            __fstrncpy(pcStack_16,uStack_14,uStack_e,uStack_c);
            handle.seg = uStack_c;
            handle.ofs = uStack_e;
            ovr_stshFree(handle);
            pcVar7 = ovr_stsprintf(local_66,"Keep %s.",pcStack_16);
            uVar5 = (uint16_t)((ulong)pcVar7 >> 0x10);
            ovr_drawString((char *)pcVar7);
            bVar2 = ovr_uiInputText(local_a);
            uStack_10 = (uint)bVar2;
            if (uStack_10 != 0) {
              if (uStack_10 != 2) {
                pcStack_16[0x28] = pcStack_16[0x28] | 2;
                manage_4d05_0081();
                manage_4d05_056e(pcStack_16,uStack_14);
                TimerSeed.lo = 0;
                TimerSeed.hi = 0;
                return pcStack_16;
              }
              break;
            }
          } while (UserWantsExit == '\0');
          goto LAB_4d05_17b2;
        }
        if (UserWantsExit != '\0') goto LAB_4d05_17b2;
      }
      if (UserWantsExit != '\0') goto LAB_4d05_17b2;
    }
  } while (UserWantsExit == '\0');
LAB_4d05_17b2:
  handle_00.seg = uStack_14;
  handle_00.ofs = (uint16_t)pcStack_16;
  ovr_stshFree(handle_00);
  return (char *)0x0;
}



/* 4d05:17c7 */

void __cdecl16far manage_4d05_17c7(undefined1 param_1)

{
  ovr_attact_3f0b_0685();
  ovr_draw_2e25_1662();
  ovr_stop_audio();
  DAT_2410_07a6 = 0xff;
  DAT_2000_ca71 = GMenuItem;
  DAT_2000_ca70 = DAT_2000_ca6f;
  TextBlitDstSeg = 0xa000;
  manage_4d05_1bee(CONCAT11(0x24,param_1));
  if (DAT_2410_4926 == '\0') {
    ovr_stats_6386_232d();
    ovr_OVC41_6a8f_18c6();
  }
  return;
}



/* 4d05:1835 */

void __cdecl16far manage_4d05_1835(void)

{
  uint *puVar1;
  int *piVar2;
  byte bVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  undefined2 uVar8;
  far_t gfx;
  far_t handle;
  char *pcStack_12;
  uint8_t local_e [8];
  uint uStack_6;
  int iStack_4;
  
  F_SCOPY(local_e,(uint8_t *)(far_t *)(GKeepDiscardStrings + 2),8);
  gfx.seg = FontHandle.seg;
  gfx.ofs = FontHandle.ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)));
  ovr_attact_3f0b_0685();
  ovr_draw_2e25_1662();
  ovr_stop_audio();
  DAT_2410_07a6 = 0xff;
  DAT_2000_ca71 = GMenuItem;
  DAT_2000_ca70 = DAT_2000_ca6f;
  TextBlitDstSeg = 0xa000;
  for (iStack_4 = 0; pcVar5 = (char *)"puppetmaker" + 3, iStack_4 < (int)(uint)DAT_2000_d1e6;
      iStack_4 = iStack_4 + 1) {
    if (((*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3d) != '\0') &&
        (*(int *)((int)*(undefined4 *)(iStack_4 << 2) + 0x39) == GfxRndSeed)) &&
       (*(int *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3b) == GfxRndSeed2)) {
      if (GCharLevelsInc != '\0') {
        uVar8 = (undefined2)((ulong)*(undefined4 *)(iStack_4 << 2) >> 0x10);
        iVar7 = (int)*(undefined4 *)(iStack_4 << 2);
        puVar1 = (uint *)(iVar7 + 0x56);
        uVar4 = *puVar1;
        *puVar1 = *puVar1 + 10000;
        piVar2 = (int *)(iVar7 + 0x58);
        *piVar2 = *piVar2 + (uint)(0xd8ef < uVar4);
        GCharLevelsInc = '\0';
      }
      manage_4d05_1bee();
      ovr_stats_6386_232d();
      ovr_OVC41_6a8f_18c6();
      return;
    }
  }
  ovr_stats_6386_00f8();
  if (DAT_2000_d1e4 == 0) {
    if (DAT_2000_d1e3 <= DAT_2000_d1e5) {
      ovr_OVC41_6a8f_18c6();
      return;
    }
    pcStack_12 = (char *)chargen();
    if (pcStack_12 == (char *)0x0 && pcVar5 == (char *)0x0) {
      ovr_stats_6386_232d();
      ovr_OVC41_6a8f_18c6();
      return;
    }
    iStack_4 = 0;
    while ((iStack_4 < (int)(uint)DAT_2000_d1e6 &&
           (*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x28) != '\0'))) {
      iStack_4 = iStack_4 + 1;
    }
    if (iStack_4 < (int)(uint)DAT_2000_d1e6) {
      DAT_2000_d1e4 = (char)iStack_4 + 1;
      handle.seg = *(uint16_t *)((uint)DAT_2000_d1e4 * 4 + -2);
      handle.ofs = *(uint16_t *)((uint)DAT_2000_d1e4 * 4 + -4);
      ovr_stshFree(handle);
    }
    else {
      if (0x4f < DAT_2000_d1e6) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x1d);
      }
      DAT_2000_d1e4 = DAT_2000_d1e6 + 1;
      DAT_2000_d1e6 = DAT_2000_d1e4;
    }
    pcStack_12[0x28] = pcStack_12[0x28] | 0x40;
    pcStack_12[0x51] = DAT_2000_d1e4 - 1;
    uVar4 = (uint)DAT_2000_d1e4;
    pcVar6 = (char *)"halfling castle" + 0xc;
    *(undefined2 *)(uVar4 * 4 + -2) = pcVar5;
    *(int *)(uVar4 * 4 + -4) = (int)pcStack_12;
    if (DAT_2000_d1e5 == 0) {
      pcStack_12[0x86] = '\x01';
    }
    DAT_2000_d1e5 = DAT_2000_d1e5 + 1;
  }
  else {
    manage_4d05_0081();
    pcStack_12 = (char *)*(undefined2 *)((uint)DAT_2000_d1e4 * 4 + -4);
    pcVar6 = pcStack_12;
    manage_4d05_056e(pcStack_12);
  }
  pcVar5 = ovr_fmVsprintf((char *)"Place %s here.",pcStack_12);
  ovr_drawString(pcVar5,pcVar6);
  bVar3 = ovr_uiInputText(local_e);
  uStack_6 = (uint)bVar3;
  if (uStack_6 == 1) {
    iStack_4 = DAT_2000_d1e4 - 1;
    if (DAT_2000_d1e5 == 1) {
      ovr_OVC18_48ac_05f2();
    }
    else {
      ovr_OVC18_48ac_05f2();
    }
    ovr_OVC41_6a8f_18c6();
  }
  else {
    ovr_stats_6386_232d();
    ovr_OVC41_6a8f_18c6();
  }
  return;
}



/* 4d05:1b1d */

byte __cdecl16far manage_4d05_1b1d(void)

{
  byte bVar1;
  
  bVar1 = 0;
  while( true ) {
    if (DAT_2000_d1e6 <= bVar1) {
      return 0xff;
    }
    if (*(char *)((int)*(undefined4 *)((uint)bVar1 << 2) + 0x86) != '\0') break;
    bVar1 = bVar1 + 1;
  }
  return bVar1;
}



/* 4d05:1b51 */

undefined2 __cdecl16far manage_4d05_1b51(byte param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  undefined1 uVar5;
  undefined4 *puVar4;
  byte bStack_4;
  
  uVar3 = manage_4d05_1b1d();
  uVar5 = (undefined1)((uint)uVar3 >> 8);
  bStack_4 = param_1;
  do {
    puVar4 = (undefined4 *)CONCAT11(uVar5,bStack_4);
    if ((((bStack_4 < DAT_2000_d1e6) &&
         (puVar4 = (undefined4 *)CONCAT11(uVar5,bStack_4), bStack_4 != (byte)uVar3)) &&
        (puVar4 = (undefined4 *)CONCAT11(uVar5,bStack_4), bStack_4 != param_1)) &&
       (puVar4 = (undefined4 *)((uint)bStack_4 << 2), *(char *)((int)*puVar4 + 0x3d) != '\0')) {
      uVar2 = *(undefined4 *)((uint)bStack_4 << 2);
      cVar1 = *(char *)((int)uVar2 + 0x3f);
      uVar5 = (undefined1)(((uint)bStack_4 << 2) >> 8);
      puVar4 = (undefined4 *)CONCAT11(uVar5,cVar1);
      if (cVar1 == *(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3f)) {
        return CONCAT11(uVar5,bStack_4);
      }
    }
    bStack_4 = bStack_4 + 1;
    uVar5 = (undefined1)((uint)puVar4 >> 8);
    if (DAT_2000_d1e6 <= bStack_4) {
      bStack_4 = 0;
    }
  } while (bStack_4 != param_1);
  return CONCAT11(uVar5,0xff);
}



/* 4d05:1bee */
/* recovered by relaxed-limit retry */
/* manage_4d05_1bee @ 4d05:1bee */

/* WARNING: Instruction at (ram,0x0004eaf8) overlaps instruction at (ram,0x0004eaf7)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Stack frame is not setup normally: Input value of stackpointer is not used
    */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: Removing unreachable block (ram,0x00045260) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

far_t * __cdecl16far manage_4d05_1bee(void)

{
  byte *pbVar1;
  uint *puVar2;
  int *piVar3;
  code *pcVar4;
  byte bVar5;
  code *pcVar6;
  undefined2 *puVar7;
  ulong uVar8;
  far_t fVar9;
  uint16_t uVar10;
  uint16_t uVar11;
  undefined2 *puVar12;
  undefined2 *puVar13;
  undefined2 *puVar14;
  byte bVar15;
  char cVar16;
  undefined1 uVar17;
  char cVar18;
  byte bVar19;
  undefined2 uVar20;
  char *pcVar21;
  int *piVar22;
  byte bVar27;
  uint16_t uVar23;
  undefined1 extraout_AH;
  far_t *pfVar24;
  far_t *pfVar25;
  int iVar26;
  char extraout_AH_00;
  uint uVar28;
  uint16_t *in_CX;
  uint uVar30;
  byte bVar31;
  byte bVar38;
  undefined2 *puVar32;
  byte *pbVar33;
  uint uVar34;
  uint16_t *puVar35;
  undefined2 *puVar36;
  far_t *pfVar37;
  undefined2 *puVar40;
  undefined2 *puVar41;
  undefined1 *puVar42;
  undefined1 *puVar43;
  undefined1 *puVar44;
  undefined2 *puVar45;
  int16_t *piVar46;
  int16_t *piVar47;
  undefined2 *puVar48;
  undefined1 *puVar49;
  undefined1 *puVar50;
  undefined1 *puVar51;
  undefined2 *puVar52;
  undefined2 *puVar53;
  undefined2 *puVar54;
  undefined2 *puVar55;
  undefined2 *puVar56;
  undefined1 *puVar57;
  undefined2 *puVar58;
  undefined2 *puVar59;
  undefined2 *puVar60;
  uint16_t *puVar61;
  undefined1 *puVar63;
  undefined1 *puVar64;
  undefined2 *puVar65;
  undefined1 *puVar66;
  undefined2 *puVar67;
  undefined2 *puVar68;
  undefined2 *puVar69;
  undefined2 *puVar70;
  undefined2 *puVar71;
  undefined2 *puVar72;
  undefined2 *puVar73;
  undefined2 *puVar74;
  undefined2 *puVar75;
  undefined2 *puVar76;
  undefined2 *puVar77;
  undefined1 *puVar78;
  undefined1 *puVar79;
  undefined1 *puVar80;
  undefined1 *puVar81;
  undefined1 *puVar82;
  undefined1 *puVar83;
  undefined1 *puVar84;
  undefined1 *puVar85;
  undefined1 *puVar86;
  undefined1 *puVar87;
  undefined2 *puVar88;
  undefined1 *puVar89;
  undefined1 *puVar90;
  undefined1 *puVar91;
  undefined1 *puVar92;
  undefined1 *puVar93;
  undefined1 *puVar94;
  undefined1 *puVar95;
  undefined1 *puVar96;
  undefined4 *puVar97;
  undefined1 *puVar98;
  undefined1 *puVar99;
  undefined1 *puVar100;
  undefined1 *puVar101;
  undefined2 *puVar102;
  undefined2 *puVar103;
  undefined1 *puVar104;
  undefined2 *puVar105;
  undefined1 *puVar106;
  undefined2 *puVar107;
  undefined2 *puVar108;
  undefined1 *puVar109;
  undefined2 *puVar110;
  undefined2 *puVar111;
  undefined2 *puVar112;
  undefined1 *puVar113;
  uint16_t *puVar114;
  undefined1 *puVar115;
  int16_t *piVar116;
  int16_t *piVar117;
  undefined2 *puVar118;
  undefined2 *puVar119;
  undefined1 *puVar120;
  uint16_t *puVar121;
  undefined2 *puVar122;
  undefined2 *puVar123;
  undefined2 *puVar124;
  undefined1 *puVar125;
  undefined2 *puVar126;
  undefined1 *puVar127;
  undefined1 *puVar128;
  undefined1 *puVar129;
  undefined1 *puVar130;
  undefined2 *puVar131;
  undefined2 *puVar132;
  undefined2 *puVar133;
  undefined1 *puVar134;
  undefined1 *puVar135;
  undefined2 *puVar136;
  undefined4 *puVar137;
  undefined1 *puVar138;
  undefined2 *puVar139;
  undefined4 *puVar140;
  undefined4 *puVar141;
  undefined2 *puVar142;
  undefined4 *puVar143;
  undefined1 *puVar144;
  undefined2 *puVar145;
  undefined1 *puVar146;
  undefined2 *puVar147;
  undefined2 *puVar148;
  undefined2 *puVar149;
  undefined2 *puVar150;
  undefined2 *puVar151;
  undefined2 *puVar152;
  uint16_t *puVar153;
  uint16_t *puVar154;
  uint16_t *puVar155;
  uint16_t *puVar156;
  uint16_t *puVar157;
  undefined1 *puVar158;
  undefined1 *puVar159;
  uint16_t *puVar160;
  uint16_t *puVar161;
  uint16_t *puVar162;
  uint16_t *puVar163;
  undefined1 *puVar164;
  undefined1 *puVar165;
  uint16_t *puVar166;
  undefined1 *puVar167;
  uint16_t *puVar168;
  undefined1 *puVar169;
  uint16_t *puVar170;
  uint16_t *puVar171;
  uint16_t *puVar172;
  undefined1 *puVar173;
  undefined1 *puVar174;
  undefined1 *puVar175;
  undefined1 *puVar176;
  undefined2 *puVar177;
  undefined2 *puVar178;
  undefined1 *puVar179;
  undefined1 *puVar180;
  undefined1 *puVar181;
  undefined1 *puVar182;
  undefined1 *puVar183;
  undefined2 *puVar184;
  undefined1 *puVar185;
  undefined1 *puVar187;
  undefined1 *puVar188;
  undefined2 *puVar189;
  undefined1 *puVar190;
  undefined1 *puVar191;
  undefined2 *puVar192;
  undefined2 *puVar193;
  undefined2 *puVar194;
  undefined2 *puVar195;
  undefined2 *puVar196;
  undefined2 *puVar197;
  undefined2 *puVar199;
  undefined2 *puVar200;
  undefined2 *puVar201;
  undefined2 *puVar202;
  uint16_t *puVar203;
  uint16_t *puVar204;
  undefined2 *puVar205;
  undefined2 *puVar206;
  undefined1 *puVar207;
  undefined2 *puVar208;
  undefined2 *puVar209;
  undefined2 *puVar210;
  undefined2 *puVar211;
  undefined1 *puVar212;
  undefined1 *puVar213;
  undefined2 *puVar214;
  undefined1 *puVar215;
  undefined2 *puVar216;
  undefined1 *puVar217;
  undefined1 *puVar218;
  undefined1 *puVar219;
  undefined2 *puVar220;
  undefined2 *puVar221;
  undefined2 *puVar222;
  undefined1 *puVar223;
  undefined1 *puVar224;
  undefined2 *puVar225;
  undefined1 *puVar226;
  undefined1 *puVar227;
  undefined1 *puVar228;
  undefined2 *puVar229;
  undefined2 *puVar230;
  undefined2 *puVar231;
  undefined2 *puVar232;
  undefined2 *puVar233;
  undefined1 *puVar234;
  undefined1 *puVar235;
  undefined1 *puVar236;
  undefined1 *puVar237;
  undefined1 *puVar238;
  undefined4 *puVar239;
  undefined4 *puVar240;
  undefined2 *puVar241;
  undefined1 *puVar242;
  undefined1 *puVar243;
  undefined1 *puVar244;
  undefined1 *puVar245;
  undefined1 *puVar246;
  undefined2 *puVar247;
  int *piVar248;
  uint16_t *puVar250;
  uint16_t *puVar251;
  uint16_t *puVar253;
  uint16_t *puVar254;
  undefined2 *puVar255;
  undefined1 *puVar256;
  undefined1 *puVar257;
  undefined1 *puVar259;
  uint16_t *puVar260;
  undefined2 *puVar261;
  undefined2 *puVar262;
  undefined2 *puVar263;
  undefined2 *puVar264;
  far_t *pfVar265;
  far_t *pfVar266;
  undefined2 *puVar267;
  undefined1 *puVar268;
  undefined2 *puVar269;
  undefined2 *puVar270;
  undefined1 *puVar271;
  undefined2 *puVar272;
  undefined2 *puVar273;
  undefined1 *puVar274;
  undefined2 *puVar275;
  undefined2 *puVar276;
  undefined1 *puVar277;
  undefined1 *puVar278;
  undefined2 *puVar279;
  undefined2 *puVar280;
  undefined2 *puVar281;
  undefined2 *puVar282;
  undefined2 *puVar283;
  undefined2 *puVar284;
  undefined2 *puVar285;
  undefined2 *puVar286;
  undefined1 *puVar287;
  undefined1 *puVar288;
  undefined4 *puVar289;
  undefined4 *puVar290;
  undefined2 *puVar291;
  undefined2 *puVar292;
  undefined1 *puVar293;
  uint16_t *puVar294;
  uint16_t *puVar295;
  undefined1 *puVar296;
  undefined2 *puVar297;
  undefined4 *puVar298;
  undefined4 *puVar299;
  undefined1 *puVar300;
  undefined2 *puVar301;
  undefined2 *puVar302;
  undefined2 *puVar303;
  undefined2 *puVar304;
  undefined1 *puVar305;
  undefined1 *puVar306;
  undefined2 *puVar307;
  undefined1 *puVar308;
  undefined1 *puVar309;
  undefined1 *puVar310;
  undefined1 *puVar311;
  undefined1 *puVar312;
  undefined1 *puVar313;
  undefined1 *puVar314;
  undefined1 *puVar315;
  undefined1 *puVar316;
  undefined1 *puVar317;
  undefined1 *puVar318;
  undefined1 *puVar319;
  undefined1 *puVar320;
  undefined2 *puVar321;
  undefined2 *puVar322;
  undefined1 *puVar323;
  undefined2 *puVar324;
  undefined2 *puVar325;
  undefined1 *puVar326;
  undefined2 *puVar327;
  undefined2 *puVar328;
  undefined2 *puVar329;
  undefined2 *puVar330;
  undefined2 *puVar331;
  undefined2 *puVar332;
  undefined1 *puVar333;
  undefined1 *puVar334;
  undefined2 *puVar335;
  undefined4 *puVar336;
  undefined4 *puVar337;
  undefined2 *puVar338;
  undefined2 *puVar339;
  undefined2 *puVar340;
  undefined2 *puVar341;
  undefined2 *puVar342;
  undefined2 *puVar343;
  undefined2 *puVar344;
  undefined2 *puVar345;
  undefined1 *puVar346;
  undefined2 *puVar347;
  undefined2 *puVar348;
  undefined1 *puVar349;
  undefined2 *puVar350;
  undefined1 *puVar351;
  undefined2 *puVar352;
  undefined1 *puVar353;
  int *piVar354;
  int *piVar355;
  int *piVar356;
  undefined1 *puVar357;
  undefined2 *puVar358;
  undefined2 *puVar359;
  undefined4 *puVar360;
  undefined1 *puVar361;
  undefined1 *puVar362;
  undefined2 *puVar363;
  undefined2 *puVar364;
  undefined2 *puVar365;
  undefined2 *puVar366;
  undefined2 *puVar367;
  undefined2 *puVar368;
  undefined4 *puVar369;
  undefined1 *puVar370;
  undefined4 *puVar371;
  undefined2 *puVar372;
  undefined2 *puVar373;
  undefined1 *puVar374;
  undefined2 *puVar375;
  undefined2 *puVar376;
  undefined1 *puVar377;
  undefined1 *puVar378;
  undefined2 *puVar379;
  undefined2 *puVar380;
  undefined2 *puVar381;
  undefined2 *puVar382;
  undefined4 *puVar383;
  undefined4 *puVar384;
  undefined2 *puVar385;
  undefined2 *puVar387;
  undefined2 *puVar388;
  undefined4 *puVar389;
  undefined2 *puVar390;
  undefined2 *puVar391;
  far_t *pfVar392;
  far_t *pfVar393;
  undefined1 *puVar394;
  far_t *pfVar395;
  undefined2 *puVar396;
  undefined1 *puVar397;
  undefined2 *puVar398;
  undefined2 *puVar399;
  undefined2 *puVar400;
  undefined1 *puVar401;
  undefined1 *puVar402;
  undefined1 *puVar403;
  int iVar404;
  undefined2 *puVar405;
  undefined2 *puVar406;
  undefined2 *puVar407;
  undefined2 *puVar408;
  uint16_t *puVar409;
  uint16_t *puVar410;
  uint16_t *puVar411;
  undefined1 *puVar412;
  undefined1 *puVar413;
  undefined2 *puVar414;
  undefined2 *puVar415;
  uint8_t *puVar416;
  uint8_t *puVar417;
  undefined1 *puVar418;
  undefined1 *puVar419;
  undefined1 *puVar420;
  undefined1 *puVar421;
  undefined4 *puVar422;
  undefined4 *puVar423;
  undefined1 *puVar424;
  undefined1 *puVar425;
  undefined2 *puVar426;
  undefined1 *puVar427;
  int *piVar428;
  int *piVar429;
  undefined1 *puVar430;
  undefined1 *puVar431;
  undefined1 *puVar432;
  undefined1 *puVar433;
  undefined1 *puVar434;
  undefined1 *puVar435;
  undefined1 *puVar436;
  undefined1 *puVar437;
  undefined1 *puVar438;
  undefined1 *puVar439;
  undefined1 *puVar440;
  undefined1 *puVar441;
  undefined1 *puVar442;
  undefined1 *puVar443;
  undefined1 *puVar444;
  undefined1 *puVar445;
  undefined1 *puVar446;
  undefined1 *puVar447;
  undefined1 *puVar448;
  undefined2 *puVar449;
  undefined2 *puVar451;
  undefined2 *puVar452;
  undefined1 *puVar453;
  undefined2 *puVar454;
  undefined2 *puVar455;
  undefined2 *puVar456;
  undefined2 *puVar457;
  undefined2 *puVar458;
  undefined2 *puVar459;
  undefined1 *puVar460;
  undefined2 *puVar461;
  undefined1 *puVar462;
  undefined2 *puVar463;
  undefined2 *puVar464;
  undefined1 *puVar465;
  undefined4 *puVar466;
  undefined4 *puVar467;
  undefined4 *puVar468;
  undefined4 *puVar469;
  undefined1 *puVar470;
  undefined1 *puVar471;
  undefined1 *puVar472;
  undefined1 *puVar473;
  undefined1 *puVar474;
  undefined1 *puVar475;
  int *piVar476;
  int *piVar477;
  undefined1 *puVar478;
  int *piVar479;
  int *piVar480;
  undefined1 *puVar481;
  undefined2 *puVar482;
  undefined1 *puVar483;
  undefined4 in_ESP;
  uint uVar484;
  undefined1 *puVar485;
  undefined1 *puVar486;
  undefined2 unaff_BP;
  uint uVar487;
  undefined2 unaff_SI;
  int iVar488;
  far_t *pfVar489;
  int iVar490;
  double *pdVar491;
  undefined2 unaff_DI;
  uint16_t uVar492;
  undefined2 uVar493;
  char *pcVar494;
  char *pcVar495;
  undefined2 uVar496;
  undefined2 unaff_SS;
  undefined2 uVar497;
  bool bVar498;
  bool bVar499;
  byte in_AF;
  bool bVar500;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  longdouble in_ST0;
  unkbyte10 in_ST1;
  cte_t *pcVar501;
  long lVar502;
  far_t ptr_base;
  uint32_t uVar504;
  stg_tmp_t *psVar505;
  far_t *pfVar506;
  void *pvVar507;
  char *pcVar508;
  undefined4 uVar509;
  far_t ptr_ofs;
  far_t ptr_ofs_00;
  far_t fVar503;
  byte bVar29;
  byte bVar39;
  uint16_t *puVar62;
  undefined1 *puVar186;
  undefined1 *puVar198;
  int *piVar249;
  undefined1 *puVar252;
  undefined1 *puVar258;
  undefined1 *puVar386;
  undefined2 *puVar450;
  
  iVar404 = (int)in_ESP;
  uVar20 = (undefined2)((ulong)in_ESP >> 0x10);
  puVar486 = (undefined1 *)(iVar404 + -2);
  puVar485 = (undefined1 *)(iVar404 + -2);
  *(undefined2 *)(iVar404 + -2) = unaff_BP;
  *(undefined2 *)(iVar404 + -0x220) = unaff_SI;
  *(undefined2 *)(iVar404 + -0x222) = unaff_DI;
  *(undefined2 *)(iVar404 + -0x224) = (char *)"Housing" + 1;
  puVar405 = (undefined2 *)(iVar404 + -0x226);
  *(undefined2 *)(iVar404 + -0x226) = 0xec4c;
  ovr_OVC13_3d16_1abd();
  puVar405[1] = (char *)"jeweler" + 6;
  *puVar405 = 0xec50;
  pfVar24 = (far_t *)manage_4d05_044e();
  puVar405[1] = (char *)"jeweler" + 6;
  pcVar495 = (char *)"money dealer\'s shop" + 0xe;
  *puVar405 = 0xec57;
  ovr_stats_6386_00f8();
  puVar406 = (undefined2 *)((int)puVar405 + 4);
  Seed_2000_d1da = GfxRndSeed;
  Seed_2000_d1d8 = GfxRndSeed2;
  *(undefined1 *)(iVar404 + -0x15) = 0;
  DAT_2410_4926 = 0;
  *(undefined1 *)(iVar404 + -4) = 0;
  do {
    *(undefined2 *)((int)puVar406 + -2) = pcVar495;
    puVar407 = (undefined2 *)((int)puVar406 + -4);
    *(undefined2 *)((int)puVar406 + -4) = 0xec80;
    manage_4d05_0081();
    uVar493 = *(undefined2 *)((uint)*(byte *)(iVar404 + 4) * 4);
    *(undefined2 *)(iVar404 + -6) = ((undefined2 *)((uint)*(byte *)(iVar404 + 4) * 4))[1];
    *(undefined2 *)(iVar404 + -8) = uVar493;
    if (*(char *)((int)*(undefined4 *)(iVar404 + -8) + 0x3f) == '\0') {
      GfxRndSeed = *(int *)((int)*(undefined4 *)(iVar404 + -8) + 0x39);
      GfxRndSeed2 = *(int *)((int)*(undefined4 *)(iVar404 + -8) + 0x3b);
    }
    else {
      GfxRndSeed = Seed_2000_d1da;
      GfxRndSeed2 = Seed_2000_d1d8;
    }
    DAT_2410_4b6e = *(undefined1 *)(iVar404 + 4);
    DAT_2410_4b6d = 0xfe;
    puVar407[1] = pcVar495;
    pcVar495 = (char *)"jeweler" + 6;
    *puVar407 = 0xed07;
    ovr_OVC13_3d16_1abd();
    DAT_2410_4b6e = 0xff;
    DAT_2410_4b6d = 0xff;
    puVar407[1] = *(undefined2 *)(iVar404 + -6);
    *puVar407 = *(undefined2 *)(iVar404 + -8);
    puVar407[-1] = (char *)"jeweler" + 6;
    puVar408 = puVar407 + -2;
    puVar407[-2] = 0xed27;
    manage_4d05_056e();
    *(undefined2 *)((int)puVar408 + 6) = (char *)"jeweler" + 6;
    puVar409 = (uint16_t *)((int)puVar408 + 4);
    *(undefined2 *)((int)puVar408 + 4) = 0xed2e;
    uVar17 = manage_4d05_1b1d();
    puVar114 = puVar409 + 2;
    *(undefined1 *)(iVar404 + -3) = uVar17;
    if (*(char *)(iVar404 + -4) == '\0') {
      if (*(char *)(iVar404 + -3) == *(char *)(iVar404 + 4)) {
        if (DAT_2410_6a88 == '\0') {
          uVar487 = (uint)*(byte *)((int)*(undefined4 *)(iVar404 + -8) + 0x33);
          puVar409[1] = *(undefined2 *)((int)&far_t_ARRAY_2410_49eb[0].seg + uVar487 * 4);
          *puVar409 = ((far_t *)far_t_ARRAY_2410_49eb + uVar487)->ofs;
          puVar409[-1] = DAT_2000_d2e4 + 1;
          puVar409[-2] = (uint16_t)((char *)"puppetmaker" + 3);
          puVar409[-3] = (uint16_t)(char *)"Year %d. %s";
          puVar409[-4] = unaff_SS;
          puVar409[-5] = iVar404 + -0x1f6;
          puVar409[-6] = (uint16_t)((char *)"jeweler" + 6);
          pcVar495 = (char *)"glassworks" + 9;
          puVar410 = puVar409 + -7;
          puVar409[-7] = 0xed84;
          ovr_stsprintf((char *)puVar409[-5],*(char **)(puVar409 + -3),(char *)puVar409[-1]);
          puVar114 = (uint16_t *)((int)puVar410 + 0x12);
        }
        else {
          uVar487 = (uint)*(byte *)((int)*(undefined4 *)(iVar404 + -8) + 0x33);
          puVar409[1] = *(undefined2 *)((int)&far_t_ARRAY_2410_49f7[0].seg + uVar487 * 4);
          *puVar409 = ((far_t *)far_t_ARRAY_2410_49f7 + uVar487)->ofs;
          puVar409[-1] = DAT_2000_d2e4 + 1;
          puVar409[-2] = (uint16_t)((char *)"puppetmaker" + 3);
          puVar409[-3] = (uint16_t)(char *)"Year %d. This leader %s";
          puVar409[-4] = unaff_SS;
          puVar409[-5] = iVar404 + -0x1f6;
          puVar409[-6] = (uint16_t)((char *)"jeweler" + 6);
          pcVar495 = (char *)"glassworks" + 9;
          puVar411 = puVar409 + -7;
          puVar409[-7] = 0xedb9;
          ovr_stsprintf((char *)puVar409[-5],*(char **)(puVar409 + -3),(char *)puVar409[-1]);
          puVar114 = (uint16_t *)((int)puVar411 + 0x12);
        }
      }
      else {
        *(undefined1 *)(iVar404 + -0x1f6) = 0;
        puVar114 = puVar409 + 2;
      }
    }
    if (((*(char *)((int)*(undefined4 *)(iVar404 + -8) + 0x3f) == '\0') &&
        (*(char *)(iVar404 + -3) != -1)) && (*(char *)(iVar404 + -3) != *(char *)(iVar404 + 4))) {
      uVar487 = (uint)*(byte *)((int)*(undefined4 *)((uint)*(byte *)(iVar404 + -3) << 2) + 0x86);
      uVar484 = (uint)*(byte *)((int)*(undefined4 *)((uint)*(byte *)(iVar404 + -3) << 2) + 0x34);
      uVar23 = ((far_t *)(GStatsLabels + 4) + uVar484 + uVar487 * 2)->ofs;
      in_CX = (uint16_t *)(iVar404 + -0x21e);
      *(undefined2 *)(iVar404 + -0x21c) =
           *(undefined2 *)((int)&GStatsLabels[4].seg + uVar487 * 8 + uVar484 * 4);
      *in_CX = uVar23;
      *(undefined1 *)(iVar404 + -0x12) = 2;
    }
    else {
      *(undefined2 *)(iVar404 + -0x21c) = 0;
      *(undefined2 *)(iVar404 + -0x21e) = 0;
      *(undefined1 *)(iVar404 + -0x12) = 2;
    }
    if (*(char *)((int)*(undefined4 *)(iVar404 + -8) + 0x3f) == '\0') {
      *(uint *)((int)puVar114 + -2) = (uint)*(byte *)(iVar404 + 4);
      *(undefined2 *)((int)puVar114 + -4) = pcVar495;
      puVar412 = (undefined1 *)((int)puVar114 + -6);
      *(undefined2 *)((int)puVar114 + -6) = 0xee6f;
      cVar18 = manage_4d05_1b51();
      puVar114 = (uint16_t *)(puVar412 + 6);
      if (cVar18 == -1) goto LAB_4d05_1e3c;
      *(undefined2 *)(iVar404 + -0x218) = (char *)"puppetmaker" + 3;
      *(undefined2 *)(iVar404 + -0x21a) = (char *)"Next Leader";
      puVar114 = (uint16_t *)(puVar412 + 6);
    }
    else {
LAB_4d05_1e3c:
      *(undefined2 *)(iVar404 + -0x218) = 0;
      *(undefined2 *)(iVar404 + -0x21a) = 0;
    }
    *(undefined1 *)(iVar404 + -0x11) = 3;
    iVar488 = 2;
    if (*(char *)((int)*(undefined4 *)(iVar404 + -8) + 0x3f) == '\0') {
      if ((*(byte *)((int)*(undefined4 *)(iVar404 + -8) + 0x5d) & 2) == 0) {
        *(undefined2 *)(iVar404 + -0x214) = (char *)"puppetmaker" + 3;
        *(undefined2 *)(iVar404 + -0x216) = (char *)"Auto-build    \x7f";
      }
      else {
        *(undefined2 *)(iVar404 + -0x214) = (char *)"puppetmaker" + 3;
        *(undefined2 *)(iVar404 + -0x216) = (char *)"Auto-build";
      }
      *(undefined1 *)(iVar404 + -0x10) = 8;
      *(undefined2 *)(iVar404 + -0x210) = (char *)"puppetmaker" + 3;
      *(undefined2 *)(iVar404 + -0x212) = (char *)"Census";
      *(undefined1 *)(iVar404 + -0xf) = 4;
      *(undefined2 *)(iVar404 + -0x20c) = (char *)"puppetmaker" + 3;
      *(undefined2 *)(iVar404 + -0x20e) = (char *)"Property";
      *(undefined1 *)(iVar404 + -0xe) = 5;
      iVar488 = 5;
    }
    if ((*(char *)((int)*(undefined4 *)(iVar404 + -8) + 0x3f) == '\0') &&
       (*(char *)(iVar404 + -3) == *(char *)(iVar404 + 4))) {
      puVar36 = (undefined2 *)(iVar488 * 4 + iVar404 + -0x21e);
      puVar36[1] = (char *)"puppetmaker" + 3;
      *puVar36 = (char *)"Total Census";
      *(undefined1 *)(iVar404 + iVar488 + -0x12) = 6;
      puVar36 = (undefined2 *)((iVar488 + 1) * 4 + iVar404 + -0x21e);
      puVar36[1] = (char *)"puppetmaker" + 3;
      *puVar36 = (char *)"All Property";
      *(undefined1 *)(iVar404 + iVar488 + 1 + -0x12) = 7;
      iVar488 = iVar488 + 2;
    }
    puVar36 = (undefined2 *)(iVar488 * 4 + iVar404 + -0x21e);
    puVar36[1] = (char *)"puppetmaker" + 3;
    *puVar36 = (char *)"Help";
    *(undefined1 *)(iVar404 + iVar488 + -0x12) = 10;
    puVar36 = (undefined2 *)((iVar488 + 1) * 4 + iVar404 + -0x21e);
    puVar36[1] = (char *)"puppetmaker" + 3;
    *puVar36 = (char *)"Done";
    *(undefined1 *)(iVar404 + iVar488 + 1 + -0x12) = 1;
    pfVar489 = (far_t *)(iVar488 + 2);
    pcVar21 = (char *)"halfling castle" + 0xc;
    pcVar494 = (char *)((ulong)*(undefined4 *)((uint)*(byte *)(iVar404 + 4) << 2) >> 0x10);
    if ((*(char *)((int)*(undefined4 *)((uint)*(byte *)(iVar404 + 4) << 2) + 0x3f) == '\0') &&
       (*(char *)(iVar404 + -0x15) == '\0')) {
      *(undefined2 *)((int)puVar114 + -2) = pcVar495;
      pcVar495 = (char *)"forester\'s camp" + 5;
      puVar413 = (undefined1 *)((int)puVar114 + -4);
      *(undefined2 *)((int)puVar114 + -4) = 0xefc8;
      bVar19 = ovr_season_67e7_04e5();
      puVar114 = (uint16_t *)(puVar413 + 4);
      if ((int)pfVar24 < (int)(uint)bVar19) {
        if ((int)pfVar24 < 0x1f) {
          DAT_2410_5cf1 = 0x5b;
        }
        else {
          DAT_2410_5cf1 = 0x3c;
        }
      }
      else {
        DAT_2410_5cf1 = 0x41;
      }
      pcVar494 = (char *)"puppetmaker" + 3;
      CurSfxType3 = 0x3c;
      *(undefined1 *)(iVar404 + -0x15) = 1;
    }
    *(undefined2 *)((int)puVar114 + -2) = 0;
    *(undefined2 *)((int)puVar114 + -4) = unaff_SS;
    *(int *)((int)puVar114 + -6) = iVar404 + -0x1f6;
    *(undefined2 *)((int)puVar114 + -8) = pfVar489;
    *(undefined2 *)((int)puVar114 + -10) = unaff_SS;
    *(int *)((int)puVar114 + -0xc) = iVar404 + -0x21e;
    *(undefined2 *)((int)puVar114 + -0xe) = pcVar495;
    pcVar495 = (char *)"halfling outpost" + 4;
    puVar97 = (undefined4 *)((int)puVar114 + -0x10);
    *(undefined2 *)((int)puVar114 + -0x10) = 0xf01b;
    uVar17 = ovr_uiInputText();
    puVar449 = (undefined2 *)((int)puVar97 + 0x10);
    puVar457 = (undefined2 *)((int)puVar97 + 0x10);
    puVar461 = (undefined2 *)((int)puVar97 + 0x10);
    puVar40 = (undefined2 *)((int)puVar97 + 0x10);
    puVar41 = (undefined2 *)((int)puVar97 + 0x10);
    puVar36 = (undefined2 *)((int)puVar97 + 0x10);
    puVar58 = (undefined2 *)((int)puVar97 + 0x10);
    puVar102 = (undefined2 *)((int)puVar97 + 0x10);
    puVar103 = (undefined2 *)((int)puVar97 + 0x10);
    puVar108 = (undefined2 *)((int)puVar97 + 0x10);
    puVar107 = (undefined2 *)((int)puVar97 + 0x10);
    puVar114 = (uint16_t *)((int)puVar97 + 0x10);
    puVar122 = (undefined2 *)((int)puVar97 + 0x10);
    puVar123 = (undefined2 *)((int)puVar97 + 0x10);
    puVar124 = (undefined2 *)((int)puVar97 + 0x10);
    puVar126 = (undefined2 *)((int)puVar97 + 0x10);
    puVar32 = (undefined2 *)((int)puVar97 + 0x10);
    puVar131 = (undefined2 *)((int)puVar97 + 0x10);
    puVar136 = (undefined2 *)((int)puVar97 + 0x10);
    puVar168 = (uint16_t *)((int)puVar97 + 0x10);
    puVar178 = (undefined2 *)((int)puVar97 + 0x10);
    puVar184 = (undefined2 *)((int)puVar97 + 0x10);
    puVar192 = (undefined2 *)((int)puVar97 + 0x10);
    puVar197 = (undefined2 *)((int)puVar97 + 0x10);
    puVar214 = (undefined2 *)((int)puVar97 + 0x10);
    puVar211 = (undefined2 *)((int)puVar97 + 0x10);
    puVar220 = (undefined2 *)((int)puVar97 + 0x10);
    puVar233 = (undefined2 *)((int)puVar97 + 0x10);
    puVar241 = (undefined2 *)((int)puVar97 + 0x10);
    puVar247 = (undefined2 *)((int)puVar97 + 0x10);
    piVar248 = (int *)((int)puVar97 + 0x10);
    pfVar265 = (far_t *)((int)puVar97 + 0x10);
    puVar289 = (undefined4 *)((int)puVar97 + 0x10);
    puVar352 = (undefined2 *)((int)puVar97 + 0x10);
    puVar365 = (undefined2 *)((int)puVar97 + 0x10);
    puVar385 = (undefined2 *)((int)puVar97 + 0x10);
    pfVar392 = (far_t *)((int)puVar97 + 0x10);
    puVar396 = (undefined2 *)((int)puVar97 + 0x10);
    puVar406 = (undefined2 *)((int)puVar97 + 0x10);
    puVar45 = (undefined2 *)((int)puVar97 + 0x10);
    puVar48 = (undefined2 *)((int)puVar97 + 0x10);
    puVar62 = (uint16_t *)((int)puVar97 + 0x10);
    puVar60 = (undefined2 *)((int)puVar97 + 0x10);
    puVar69 = (undefined2 *)((int)puVar97 + 0x10);
    puVar88 = (undefined2 *)((int)puVar97 + 0x10);
    puVar110 = (undefined2 *)((int)puVar97 + 0x10);
    puVar112 = (undefined2 *)((int)puVar97 + 0x10);
    puVar199 = (undefined2 *)((int)puVar97 + 0x10);
    puVar255 = (undefined2 *)((int)puVar97 + 0x10);
    puVar276 = (undefined2 *)((int)puVar97 + 0x10);
    puVar456 = (undefined2 *)((int)puVar97 + 0x10);
    puVar216 = (undefined2 *)((int)puVar97 + 0x10);
    puVar208 = (undefined2 *)((int)puVar97 + 0x10);
    puVar389 = (undefined4 *)((int)puVar97 + 0x10);
    *(undefined1 *)(iVar404 + -0x13) = uVar17;
    if (*(char *)(iVar404 + -0x13) != '\0') {
      pcVar21 = (char *)(iVar404 + -0x13);
      *(char *)(iVar404 + -0x13) = pcVar21[*(byte *)(iVar404 + -0x13)];
    }
    *(undefined1 *)(iVar404 + -0x14) = 0;
    *(undefined1 *)(iVar404 + -4) = 0;
    uVar23 = StshCount;
    pfVar25 = (far_t *)(*(byte *)(iVar404 + -0x13) - 2);
    pfVar506 = (far_t *)CONCAT22(pcVar21,pfVar25);
    if (pfVar25 < (far_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 5)) {
      bVar499 = (int)pfVar25 < 0;
      pfVar37 = (far_t *)((int)pfVar25 * 2);
      bVar500 = pfVar37 == (far_t *)0x0;
      pcVar495 = "";
      bVar19 = (byte)pfVar25;
      bVar15 = (byte)in_CX;
      switch(pfVar25) {
      case (far_t *)0x0:
        goto LAB_3f0b_1477;
      case (far_t *)0x1:
        goto switchD_4000_4689_switchD;
      case (far_t *)0x2:
        goto switchD_4000_f055_caseD_2;
      case (far_t *)0x3:
        goto switchD_4000_f055_caseD_3;
      case (far_t *)0x4:
        goto switchD_4000_f055_caseD_4;
      case (far_t *)0x5:
        goto switchD_4000_f055_caseD_5;
      case (far_t *)0x6:
        *(undefined2 *)((int)puVar97 + 0xe) = 0xe9f5;
        break;
      case (far_t *)0x7:
        goto switchD_4000_f055_caseD_7;
      case (far_t *)0x8:
        goto switchD_4000_f055_caseD_8;
      }
      goto LAB_4528_0c4d;
    }
    if (*(char *)(iVar404 + -0x14) == '\0') {
      pfVar24 = (far_t *)(uint)DAT_2410_4926;
      if (pfVar24 == (far_t *)0x0) {
        GfxRndSeed = Seed_2000_d1da;
        GfxRndSeed2 = Seed_2000_d1d8;
        *(undefined2 *)((int)puVar97 + 0xe) = (char *)"halfling outpost" + 4;
        puVar414 = (undefined2 *)((int)puVar97 + 0xc);
        *(undefined2 *)((int)puVar97 + 0xc) = 0xf1af;
        ovr_OVC13_3d16_1abd();
        puVar414[1] = (char *)"jeweler" + 6;
        *puVar414 = 0xf1b4;
        pfVar24 = (far_t *)ovr_stop_audio();
      }
      return pfVar24;
    }
  } while( true );
code_r0x00041292:
  do {
    pfVar24 = (far_t *)((int)&pfVar25->ofs + 1);
    if (4 < (int)pfVar24) {
      return pfVar37;
    }
    pfVar489 = (far_t *)0x0;
    (pcVar21 + -4)[0] = '\0';
    (pcVar21 + -4)[1] = '\0';
    while (*(far_t **)(pcVar21 + -4) < EntityCount) {
      pcVar21[-1] = *(char *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 0x1a);
      if ((pcVar21[-1] != -1) &&
         ((far_t *)(uint)*(byte *)((int)*(undefined4 *)((uint)(byte)pcVar21[-1] << 2) + 0x89) ==
          pfVar24)) {
        *(undefined2 *)(puVar485 + -2) =
             *(undefined2 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 8);
        *(char **)(puVar485 + -4) = pcVar495;
        pcVar495 = (char *)"dwarf outpost" + 6;
        puVar95 = puVar485 + -6;
        *(undefined2 *)(puVar485 + -6) = 0xf3e;
        iVar488 = ovr_OVC23_55fe_3450();
        puVar485 = puVar95 + 6;
        if ((iVar488 == *(int *)(pcVar21 + -8)) &&
           (puVar485 = puVar95 + 6,
           *(int *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 10) ==
           *(int *)((int)*(undefined4 *)(pcVar21 + 6) + 2))) {
          pfVar489 = (far_t *)((int)&pfVar489->ofs + 1);
          puVar485 = puVar95 + 6;
        }
      }
      *(int *)(pcVar21 + -4) = *(int *)(pcVar21 + -4) + 1;
    }
    pcVar21[-1] = *(char *)((int)&pfVar25[-0x1bc9].seg + 1);
    pfVar37 = (far_t *)(uint)*(byte *)((int)&pfVar24[3].seg + (int)*(undefined4 *)(pcVar21 + 6));
    pfVar25 = pfVar24;
  } while (pfVar37 == pfVar489);
  for (; (int)pfVar489 <
         (int)(uint)*(byte *)((int)&pfVar24[3].seg + (int)*(undefined4 *)(pcVar21 + 6));
      pfVar489 = (far_t *)((int)&pfVar489->ofs + 1)) {
    *(undefined2 *)(puVar485 + -2) = *(undefined2 *)((int)*(undefined4 *)(pcVar21 + 6) + 2);
    *(undefined2 *)(puVar485 + -4) = **(undefined2 **)(pcVar21 + 6);
    *(uint *)(puVar485 + -6) = (uint)(byte)pcVar21[-1];
    *(undefined2 *)(puVar485 + -8) = 3;
    *(undefined2 *)(puVar485 + -10) = unaff_SS;
    *(char **)(puVar485 + -0xc) = pcVar21 + -4;
    *(char **)(puVar485 + -0xe) = pcVar495;
    puVar96 = puVar485 + -0x10;
    *(undefined2 *)(puVar485 + -0x10) = 0x1033;
    cVar18 = attact_3f0b_1a2f();
    puVar485 = puVar96 + 0x10;
    if (cVar18 == '\0') break;
    *(undefined1 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 0x30) = 0;
    *(undefined2 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 8) =
         *(undefined2 *)(pcVar21 + -6);
    *(undefined2 *)(puVar96 + 0xe) = *(undefined2 *)((int)*(undefined4 *)(pcVar21 + 6) + 2);
    *(undefined2 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 10) =
         *(undefined2 *)(puVar96 + 0xe);
    pbVar1 = (byte *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 0x33);
    *pbVar1 = *pbVar1 & 0xfb;
    puVar485 = puVar96 + 0x10;
  }
  do {
    if ((int)(uint)*(byte *)((int)&pfVar24[3].seg + (int)*(undefined4 *)(pcVar21 + 6)) <=
        (int)pfVar489) goto code_r0x00041120;
    *(undefined2 *)(puVar485 + -2) = *(undefined2 *)((int)*(undefined4 *)(pcVar21 + 6) + 2);
    *(undefined2 *)(puVar485 + -4) = **(undefined2 **)(pcVar21 + 6);
    *(uint *)(puVar485 + -6) = (uint)(byte)pcVar21[-1];
    *(undefined2 *)(puVar485 + -8) = 2;
    *(undefined2 *)(puVar485 + -10) = unaff_SS;
    *(char **)(puVar485 + -0xc) = pcVar21 + -4;
    *(char **)(puVar485 + -0xe) = pcVar495;
    puVar97 = (undefined4 *)(puVar485 + -0x10);
    *(undefined2 *)(puVar485 + -0x10) = 0x10be;
    cVar18 = attact_3f0b_1a2f();
    puVar485 = (undefined1 *)((int)puVar97 + 0x10);
    if (cVar18 == '\0') goto code_r0x000410c8;
    *(undefined1 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 0x30) = 0;
    *(undefined2 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 8) =
         *(undefined2 *)(pcVar21 + -6);
    *(undefined2 *)((int)puVar97 + 0xe) = *(undefined2 *)((int)*(undefined4 *)(pcVar21 + 6) + 2);
    *(undefined2 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 10) =
         *(undefined2 *)((int)puVar97 + 0xe);
    pfVar489 = (far_t *)((int)&pfVar489->ofs + 1);
  } while( true );
LAB_3f0b_1477:
  *(undefined1 *)(iVar404 + -0x17) = 1;
  *(undefined2 *)((int)puVar208 + -2) = *(undefined2 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 8);
  *(undefined2 *)((int)puVar208 + -4) = pcVar495;
  puVar71 = (undefined2 *)((int)puVar208 + -6);
  *(undefined2 *)((int)puVar208 + -6) = 0x537;
  uVar20 = ovr_OVC23_55fe_3450();
  puVar71[2] = uVar20;
  puVar71[1] = *(undefined2 *)*(undefined4 *)(iVar404 + -0x1e);
  *puVar71 = (char *)"dwarf outpost" + 6;
  puVar72 = puVar71 + -1;
  puVar71[-1] = 0x546;
  iVar488 = ovr_OVC23_55fe_3450();
  puVar77 = (undefined2 *)((int)puVar72 + 8);
  puVar36 = (undefined2 *)((int)puVar72 + 8);
  if ((*(int *)((int)puVar72 + 6) == iVar488) &&
     (puVar36 = (undefined2 *)((int)puVar72 + 8),
     *(int *)((int)*(undefined4 *)(iVar404 + -0x1e) + 10) ==
     *(int *)((int)*(undefined4 *)(iVar404 + -0x1e) + 2))) {
    *(undefined2 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 8) = 0;
    *(undefined2 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 10) = 0;
    if (*(char *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0x1a) == -1) {
      *(undefined1 *)(iVar404 + -4) = 0xff;
    }
    else {
      uVar509 = *(undefined4 *)((uint)*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0x1a) << 2);
      *(undefined1 *)(iVar404 + -4) = *(undefined1 *)((int)uVar509 + 0x89);
    }
    puVar36 = (undefined2 *)((int)puVar72 + 8);
    if (*(char *)(iVar404 + -4) != -1) {
      for (uVar487 = 0; puVar36 = puVar77, uVar487 < DAT_2410_0881; uVar487 = uVar487 + 1) {
        *(undefined2 *)((int)puVar77 + -2) = *(undefined2 *)(uVar487 * 0x13);
        *(undefined2 *)((int)puVar77 + -4) = (char *)"dwarf outpost" + 6;
        puVar73 = (undefined2 *)((int)puVar77 + -6);
        *(undefined2 *)((int)puVar77 + -6) = 0x5cc;
        uVar20 = ovr_OVC23_55fe_3450();
        puVar73[2] = uVar20;
        puVar73[1] = *(undefined2 *)*(undefined4 *)(iVar404 + -0x1e);
        *puVar73 = (char *)"dwarf outpost" + 6;
        puVar74 = puVar73 + -1;
        puVar73[-1] = 0x5db;
        iVar488 = ovr_OVC23_55fe_3450();
        puVar77 = puVar74 + 4;
        if ((puVar74[3] == iVar488) &&
           (*(int *)(uVar487 * 0x13 + 2) == *(int *)((int)*(undefined4 *)(iVar404 + -0x1e) + 2))) {
          puVar74[3] = (uint)*(byte *)(iVar404 + -4);
          iVar488 = puVar74[3];
          puVar74[3] = 0x17f8;
          puVar74[2] = uVar487 * 0x13 + iVar488 + 0xe;
          puVar74[1] = (char *)"dwarf outpost" + 6;
          *puVar74 = 0x620;
          manage_4d05_28e0();
          puVar36 = puVar74 + 2;
          if (*(int *)(uVar487 * 0x13 + 2) == GfxRndSeed2) {
            puVar74[1] = *(undefined2 *)(uVar487 * 0x13);
            *puVar74 = (char *)"dwarf outpost" + 6;
            puVar75 = puVar74 + -1;
            puVar74[-1] = 0x65a;
            uVar20 = ovr_OVC23_55fe_3450();
            puVar75[2] = uVar20;
            puVar75[1] = GfxRndSeed;
            *puVar75 = (char *)"dwarf outpost" + 6;
            puVar76 = puVar75 + -1;
            puVar75[-1] = 0x66d;
            iVar488 = ovr_OVC23_55fe_3450();
            puVar36 = (undefined2 *)((int)puVar76 + 8);
            if (*(int *)((int)puVar76 + 6) == iVar488) {
              *(undefined1 *)((uint)*(byte *)(iVar404 + -4) + iVar404 + -0xe) = 1;
              puVar36 = (undefined2 *)((int)puVar76 + 8);
            }
          }
          break;
        }
      }
    }
  }
  pcVar495 = (char *)"dwarf outpost" + 6;
  if (AgntFlag1 != false) {
    if (((*(uint *)*(undefined4 *)(iVar404 + -0x1e) < GfxRndSeed - 2U) ||
        (GfxRndSeed + 1U < *(uint *)*(undefined4 *)(iVar404 + -0x1e))) ||
       (*(int *)((int)*(undefined4 *)(iVar404 + -0x1e) + 2) != GfxRndSeed2)) {
      uVar17 = 0;
    }
    else {
      uVar17 = 1;
    }
    *(undefined1 *)(iVar404 + -0x19) = uVar17;
    if (((*(uint *)(iVar404 + -6) < GfxRndSeed - 2U) || (GfxRndSeed + 1U < *(uint *)(iVar404 + -6)))
       || (GfxRndSeed2 != *(int *)(iVar404 + -8))) {
      uVar17 = 0;
    }
    else {
      uVar17 = 1;
    }
    *(undefined1 *)(iVar404 + -0x18) = uVar17;
    if (*(char *)(iVar404 + -0x18) != '\0' || *(char *)(iVar404 + -0x19) != '\0') {
      if (*(char *)(iVar404 + -0x18) == '\0') {
        *(undefined2 *)((int)puVar36 + -2) = (char *)"dwarf outpost" + 6;
        puVar78 = (undefined1 *)((int)puVar36 + -4);
        *(undefined2 *)((int)puVar36 + -4) = 0x739;
        ovr_OVC15_4207_0b88();
        puVar36 = (undefined2 *)(puVar78 + 4);
        *(undefined1 *)(iVar404 + -0x1a) =
             (char)((ulong)(*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xe) + 0xf) / 0x10);
        if ((*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc) & 1) == 0) {
          *(undefined2 *)(iVar404 + -0x16) = 0;
        }
        else {
          *(int *)(iVar404 + -0x16) = *(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc) - 2;
          puVar36 = (undefined2 *)(puVar78 + 4);
        }
        while( true ) {
          pcVar495 = (char *)"jeweler\'s shop" + 3;
          cVar18 = *(char *)(iVar404 + -0x1a);
          *(char *)(iVar404 + -0x1a) = *(char *)(iVar404 + -0x1a) + -1;
          if (cVar18 == '\0') break;
          *(undefined2 *)((int)puVar36 + -2) = 0;
          *(undefined2 *)((int)puVar36 + -4) = *(undefined2 *)(iVar404 + -0x16);
          *(undefined2 *)((int)puVar36 + -6) = pfVar24;
          *(undefined2 *)((int)puVar36 + -8) = (char *)"jeweler\'s shop" + 3;
          puVar79 = (undefined1 *)((int)puVar36 + -10);
          *(undefined2 *)((int)puVar36 + -10) = 0x77d;
          ovr_OVC15_4207_2301();
          puVar36 = (undefined2 *)(puVar79 + 10);
        }
      }
      else if (*(char *)(iVar404 + -0x19) == '\0') {
        *(undefined1 *)(iVar404 + -0x1a) =
             (char)((ulong)(*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xe) + 0xf) / 0x10);
        while (cVar18 = *(char *)(iVar404 + -0x1a),
              *(char *)(iVar404 + -0x1a) = *(char *)(iVar404 + -0x1a) + -1, cVar18 != '\0') {
          iVar488 = Entities.ofs + (int)pfVar24 * 0x37;
          *(uint16_t *)((int)puVar36 + -2) = Entities.seg;
          *(int *)((int)puVar36 + -4) = iVar488;
          *(undefined2 *)((int)puVar36 + -6) = pcVar495;
          pcVar495 = (char *)"mason\'s hall" + 6;
          puVar80 = (undefined1 *)((int)puVar36 + -8);
          *(undefined2 *)((int)puVar36 + -8) = 1999;
          ovr_agnt_3b1d_196b(*(far_t *)((int)puVar36 + -4));
          puVar36 = (undefined2 *)(puVar80 + 8);
        }
      }
      else if ((*(char *)(iVar404 + -0x18) != '\0') && (*(char *)(iVar404 + -0x19) != '\0')) {
        *(undefined2 *)((int)puVar36 + -2) = pfVar24;
        *(undefined2 *)((int)puVar36 + -4) = (char *)"dwarf outpost" + 6;
        puVar81 = (undefined1 *)((int)puVar36 + -6);
        *(undefined2 *)((int)puVar36 + -6) = 0x7ef;
        uVar17 = manage_4d05_28f4();
        *(undefined1 *)(iVar404 + -0x1a) = uVar17;
        puVar36 = (undefined2 *)(puVar81 + 6);
        while (*(char *)(iVar404 + -0x1a) != '\0') {
          if ((*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc) & 1) == 0) {
            *(undefined2 *)(iVar404 + -0x16) = 0;
          }
          else {
            *(int *)(iVar404 + -0x16) = *(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc) - 2;
          }
          *(undefined2 *)((int)puVar36 + -2) = 0;
          *(undefined2 *)((int)puVar36 + -4) = *(undefined2 *)(iVar404 + -0x16);
          *(undefined2 *)((int)puVar36 + -6) = pfVar24;
          *(undefined2 *)((int)puVar36 + -8) = pcVar495;
          pcVar495 = (char *)"jeweler\'s shop" + 3;
          puVar82 = (undefined1 *)((int)puVar36 + -10);
          *(undefined2 *)((int)puVar36 + -10) = 0x822;
          cVar18 = ovr_OVC15_4207_2301();
          puVar36 = (undefined2 *)(puVar82 + 10);
          if (cVar18 == '\0') break;
          *(char *)(iVar404 + -0x1a) = *(char *)(iVar404 + -0x1a) + -1;
          puVar36 = (undefined2 *)(puVar82 + 10);
        }
      }
    }
  }
  do {
    pfVar24 = (far_t *)((int)&pfVar24->ofs + 1);
LAB_3f0b_1785:
    if (EntityCount <= pfVar24) {
      GGameState = 0x3c;
      if (DebugVerbose != false) {
        *(undefined2 *)((int)puVar36 + -2) = DAT_2000_d165;
        *(undefined2 *)((int)puVar36 + -4) = DAT_2000_d163;
        *(undefined2 *)((int)puVar36 + -6) = GGameState;
        *(undefined2 *)((int)puVar36 + -8) = (char *)"puppetmaker" + 3;
        *(undefined2 *)((int)puVar36 + -10) = 0x8ea;
        *(undefined2 *)((int)puVar36 + -0xc) = pcVar495;
        pcVar495 = (char *)0x1000;
        puVar83 = (undefined1 *)((int)puVar36 + -0xe);
        *(undefined2 *)((int)puVar36 + -0xe) = 0x878;
        printf((char *)*(undefined4 *)((int)puVar36 + -10),*(undefined2 *)((int)puVar36 + -6));
        puVar36 = (undefined2 *)(puVar83 + 0xe);
      }
      *(undefined2 *)((int)puVar36 + -2) = pcVar495;
      puVar85 = (undefined1 *)((int)puVar36 + -4);
                    /* WARNING: Call to offcut address within same function */
      *(undefined2 *)((int)puVar36 + -4) = 0x87f;
      func_0x0004fcda();
      GGameState = 0x3d;
      if (DebugVerbose != false) {
        *(undefined2 *)(puVar85 + -2) = DAT_2000_d165;
        *(undefined2 *)(puVar85 + -4) = DAT_2000_d163;
        *(undefined2 *)(puVar85 + -6) = GGameState;
        *(char **)(puVar85 + -8) = (char *)"puppetmaker" + 3;
        *(undefined2 *)(puVar85 + -10) = 0x8ea;
        *(char **)(puVar85 + -0xc) = pcVar495;
        pcVar495 = (char *)0x1000;
        puVar84 = puVar85 + -0xe;
        *(undefined2 *)(puVar85 + -0xe) = 0x8b3;
        printf(*(char **)(puVar85 + -10),*(undefined2 *)(puVar85 + -6));
        puVar85 = puVar84 + 0xe;
      }
      *(char **)(puVar85 + -2) = pcVar495;
      pcVar495 = (char *)"thief outpost" + 10;
      puVar86 = puVar85 + -4;
      *(undefined2 *)(puVar85 + -4) = 0x8bb;
      ovr_OVC23_55fe_2b82();
      puVar88 = (undefined2 *)(puVar86 + 4);
      GGameState = 0xc;
      pfVar25 = (far_t *)((char *)"puppetmaker" + 3);
      goto code_r0x000408ca;
    }
    iVar488 = Entities.ofs + (int)pfVar24 * 0x37;
    *(uint16_t *)(iVar404 + -0x1c) = Entities.seg;
    *(int *)(iVar404 + -0x1e) = iVar488;
    *(undefined2 *)((int)puVar36 + -2) = *(undefined2 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 8);
    *(undefined2 *)((int)puVar36 + -4) = pcVar495;
    puVar54 = (undefined2 *)((int)puVar36 + -6);
    *(undefined2 *)((int)puVar36 + -6) = 0x1c5;
    uVar20 = ovr_OVC23_55fe_3450();
    puVar54[2] = uVar20;
    puVar54[1] = *(undefined2 *)*(undefined4 *)(iVar404 + -0x1e);
    *puVar54 = (char *)"dwarf outpost" + 6;
    pcVar495 = (char *)"dwarf outpost" + 6;
    puVar55 = puVar54 + -1;
    puVar54[-1] = 0x1d4;
    iVar488 = ovr_OVC23_55fe_3450();
    puVar36 = puVar55 + 4;
    if ((puVar55[3] == iVar488) &&
       (puVar36 = puVar55 + 4,
       *(int *)((int)*(undefined4 *)(iVar404 + -0x1e) + 10) ==
       *(int *)((int)*(undefined4 *)(iVar404 + -0x1e) + 2))) {
      puVar55[3] = unaff_SS;
      puVar55[2] = iVar404 + -0xe;
      puVar55[1] = *(undefined2 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 10);
      *puVar55 = *(undefined2 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 8);
      puVar55[-1] = pfVar24;
      puVar55[-2] = (char *)"dwarf outpost" + 6;
      puVar56 = puVar55 + -3;
      puVar55[-3] = 0x204;
      manage_4d05_2b3e();
      puVar36 = (undefined2 *)((int)puVar56 + 0xe);
    }
  } while ((*(int *)((int)*(undefined4 *)(iVar404 + -0x1e) + 8) == 0 &&
            *(int *)((int)*(undefined4 *)(iVar404 + -0x1e) + 10) == 0) ||
          (*(char *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0x18) != '\0'));
  if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].ofs + 1 +
                (uint)*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xd) * 0x95) & 0x4000) == 0)
  {
    *(undefined1 *)(iVar404 + -3) = 0;
  }
  else {
code_r0x0004024a:
    *(undefined1 *)(iVar404 + -3) = 1;
  }
  *(undefined2 *)(iVar404 + -6) = *(undefined2 *)*(undefined4 *)(iVar404 + -0x1e);
  *(undefined2 *)(iVar404 + -8) = *(undefined2 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 2);
  *(undefined1 *)(iVar404 + -0xf) =
       *(undefined1 *)
        ((int)(char **)GMenuStrings +
        (uint)*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xd) * 0x95 + 0x1f);
  if (*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0x30) <=
      *(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0x2f)) {
    *(int *)((int)puVar36 + -2) =
         *(int *)((int)*(undefined4 *)(iVar404 + -0x1e) + 8) -
         *(int *)*(undefined4 *)(iVar404 + -0x1e);
    *(undefined2 *)((int)puVar36 + -4) = pcVar495;
    puVar59 = (undefined2 *)((int)puVar36 + -6);
    *(undefined2 *)((int)puVar36 + -6) = 0x34d;
    uVar20 = ovr_OVC07_32c9_0026();
    *(undefined2 *)(iVar404 + -0x12) = uVar20;
    puVar59[2] = *(int *)((int)*(undefined4 *)(iVar404 + -0x1e) + 10) -
                 *(int *)((int)*(undefined4 *)(iVar404 + -0x1e) + 2);
    puVar59[1] = (char *)"public baths" + 6;
    pcVar495 = (char *)"public baths" + 6;
    *puVar59 = 0x367;
    pfVar25 = (far_t *)ovr_OVC07_32c9_0026();
    puVar60 = (undefined2 *)((int)puVar59 + 6);
    *(undefined2 *)(iVar404 + -0x14) = pfVar25;
    if (*(int *)(iVar404 + -0x12) != 0) {
      puVar62 = (uint16_t *)((int)puVar59 + 4);
      *(undefined2 *)((int)puVar59 + 4) = 2;
code_r0x00040375:
      puVar62[-1] = (uint16_t)pcVar495;
      pcVar495 = (char *)"glassworks" + 9;
      puVar61 = puVar62 + -2;
      puVar62[-2] = 0x37a;
      pfVar25 = (far_t *)ovr_randBelow(*puVar62);
      puVar60 = (undefined2 *)((int)puVar61 + 6);
      bVar500 = (char)pfVar25 == '\0';
code_r0x0004037f:
      if (!bVar500) {
        uVar17 = (undefined1)((uint)pfVar25 >> 8);
        *(undefined2 *)((int)puVar60 + -2) = CONCAT11(uVar17,*(undefined1 *)(iVar404 + -3));
        *(undefined2 *)((int)puVar60 + -4) = CONCAT11(uVar17,*(undefined1 *)(iVar404 + -0xf));
        *(undefined2 *)((int)puVar60 + -6) = CONCAT11(uVar17,'\x02' - *(char *)(iVar404 + -0x12));
        *(undefined2 *)((int)puVar60 + -8) = *(undefined2 *)(iVar404 + -8);
        *(undefined2 *)((int)puVar60 + -10) = *(undefined2 *)(iVar404 + -6);
        *(undefined2 *)((int)puVar60 + -0xc) = pcVar495;
        puVar63 = (undefined1 *)((int)puVar60 + -0xe);
        *(undefined2 *)((int)puVar60 + -0xe) = 0x399;
        bVar19 = func_0x0004f412();
        puVar60 = (undefined2 *)(puVar63 + 10);
        pfVar25 = (far_t *)(uint)bVar19;
        if (pfVar25 == (far_t *)0x0) {
          *(int *)*(undefined4 *)(iVar404 + -0x1e) =
               *(int *)*(undefined4 *)(iVar404 + -0x1e) + *(int *)(iVar404 + -0x12);
          *(char *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc) =
               '\x02' - *(char *)(iVar404 + -0x12);
          puVar208 = (undefined2 *)(puVar63 + 10);
          goto LAB_3f0b_1477;
        }
      }
    }
    if (*(int *)(iVar404 + -0x14) != 0) {
      uVar17 = (undefined1)((uint)pfVar25 >> 8);
      *(undefined2 *)((int)puVar60 + -2) = CONCAT11(uVar17,*(undefined1 *)(iVar404 + -3));
      *(undefined2 *)((int)puVar60 + -4) = CONCAT11(uVar17,*(undefined1 *)(iVar404 + -0xf));
      *(undefined2 *)((int)puVar60 + -6) = CONCAT11(uVar17,*(char *)(iVar404 + -0x14) + '\x01');
      *(undefined2 *)((int)puVar60 + -8) = *(undefined2 *)(iVar404 + -8);
      *(undefined2 *)((int)puVar60 + -10) = *(undefined2 *)(iVar404 + -6);
      *(undefined2 *)((int)puVar60 + -0xc) = pcVar495;
      puVar64 = (undefined1 *)((int)puVar60 + -0xe);
      *(undefined2 *)((int)puVar60 + -0xe) = 0x3d8;
      bVar19 = func_0x0004f412();
      puVar65 = (undefined2 *)(puVar64 + 10);
      puVar60 = (undefined2 *)(puVar64 + 10);
      pfVar25 = (far_t *)(uint)bVar19;
      if (pfVar25 == (far_t *)0x0) {
code_r0x000403e1:
        piVar3 = (int *)((int)*(undefined4 *)(iVar404 + -0x1e) + 2);
        *piVar3 = *piVar3 + *(int *)(iVar404 + -0x14);
        *(char *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc) = *(char *)(iVar404 + -0x14) + '\x01'
        ;
        puVar208 = puVar65;
        goto LAB_3f0b_1477;
      }
    }
    if (*(int *)(iVar404 + -0x12) != 0) {
      uVar17 = (undefined1)((uint)pfVar25 >> 8);
      *(undefined2 *)((int)puVar60 + -2) = CONCAT11(uVar17,*(undefined1 *)(iVar404 + -3));
      *(undefined2 *)((int)puVar60 + -4) = CONCAT11(uVar17,*(undefined1 *)(iVar404 + -0xf));
      *(undefined2 *)((int)puVar60 + -6) = CONCAT11(uVar17,'\x02' - *(char *)(iVar404 + -0x12));
      *(undefined2 *)((int)puVar60 + -8) = *(undefined2 *)(iVar404 + -8);
      *(undefined2 *)((int)puVar60 + -10) = *(undefined2 *)(iVar404 + -6);
      *(undefined2 *)((int)puVar60 + -0xc) = pcVar495;
      puVar66 = (undefined1 *)((int)puVar60 + -0xe);
      *(undefined2 *)((int)puVar60 + -0xe) = 0x418;
      cVar18 = func_0x0004f412();
      puVar60 = (undefined2 *)(puVar66 + 10);
      if (cVar18 == '\0') {
        *(int *)*(undefined4 *)(iVar404 + -0x1e) =
             *(int *)*(undefined4 *)(iVar404 + -0x1e) + *(int *)(iVar404 + -0x12);
        *(char *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc) = '\x02' - *(char *)(iVar404 + -0x12)
        ;
        puVar208 = (undefined2 *)(puVar66 + 10);
        goto LAB_3f0b_1477;
      }
    }
    *(undefined2 *)((int)puVar60 + -2) = pfVar24;
    *(undefined2 *)((int)puVar60 + -4) = pcVar495;
    pcVar495 = (char *)"elf outpost" + 5;
    puVar67 = (undefined2 *)((int)puVar60 + -6);
    *(undefined2 *)((int)puVar60 + -6) = 0x43f;
    cVar18 = ovr_OVC26_5d45_031f();
    if (cVar18 == '\0') {
      puVar67[2] = unaff_SS;
      puVar67[1] = iVar404 + -0xe;
      *puVar67 = unaff_SS;
      puVar67[-1] = iVar404 + -0x17;
      puVar67[-2] = pfVar24;
      puVar67[-3] = (char *)"elf outpost" + 5;
      pcVar495 = (char *)"elf outpost" + 5;
      puVar70 = puVar67 + -4;
      puVar67[-4] = 0x4e3;
      cVar18 = ovr_OVC26_5d45_06f0();
      puVar208 = puVar70 + 7;
      if ((cVar18 == '\0') &&
         (puVar208 = puVar70 + 7,
         *(char *)((int)(char **)GMenuStrings +
                  (uint)*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xd) * 0x95 + 0x1f) ==
         '\0')) {
        puVar70[6] = unaff_SS;
        puVar70[5] = iVar404 + -0xe;
        puVar70[4] = *(undefined2 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 6);
        puVar70[3] = *(undefined2 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 4);
        puVar70[2] = pfVar24;
        puVar70[1] = (char *)"elf outpost" + 5;
        *puVar70 = 0x524;
        manage_4d05_2b3e();
        puVar208 = (undefined2 *)((int)puVar70 + 0xe);
      }
    }
    else {
      uVar487 = (int)(uint)*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) +
                                     ((int)(uint)*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) +
                                                          0x2f) >> 2) + 0x1b) >>
                ((*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0x2f) & 3) << 1) & 0xff03;
      *(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc) = (char)uVar487;
      uVar17 = (undefined1)(uVar487 >> 8);
      puVar67[2] = CONCAT11(uVar17,*(undefined1 *)(iVar404 + -0xf));
      puVar67[1] = CONCAT11(uVar17,*(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc));
      *puVar67 = *(undefined2 *)(iVar404 + -8);
      puVar67[-1] = *(undefined2 *)(iVar404 + -6);
      puVar67[-2] = (char *)"elf outpost" + 5;
      puVar68 = puVar67 + -3;
      puVar67[-3] = 0x48f;
      cVar18 = func_0x0004f32d();
      puVar69 = (undefined2 *)((int)puVar68 + 8);
      puVar208 = (undefined2 *)((int)puVar68 + 8);
      if (cVar18 == '\0') {
        *(int *)*(undefined4 *)(iVar404 + -0x1e) =
             *(int *)*(undefined4 *)(iVar404 + -0x1e) +
             (int)*(char *)(*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc) + 0x885);
        pfVar25 = (far_t *)(int)*(char *)(*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc) +
                                         0x889);
        pcVar494 = (char *)((ulong)*(undefined4 *)(iVar404 + -0x1e) >> 0x10);
        pfVar37 = (far_t *)(far_t *)*(undefined4 *)(iVar404 + -0x1e);
code_r0x000404c4:
        pfVar37->seg = (uint16_t)((int)&pfVar25->ofs + pfVar37->seg);
        pcVar508 = (char *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0x2f);
        *pcVar508 = *pcVar508 + '\x01';
        puVar208 = puVar69;
      }
    }
    goto LAB_3f0b_1477;
  }
  pcVar494 = (char *)((ulong)*(undefined4 *)(iVar404 + -0x1e) >> 0x10);
  pfVar37 = (far_t *)(far_t *)*(undefined4 *)(iVar404 + -0x1e);
LAB_3f0b_11ea:
  uVar487 = (int)(uint)*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) +
                                 ((int)(uint)*(byte *)((int)&pfVar37[0xb].seg + 1) >> 2) + 0x1b) >>
            ((*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0x2f) & 3) << 1) & 0xff03;
  *(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc) = (char)uVar487;
  uVar17 = (undefined1)(uVar487 >> 8);
  *(undefined2 *)((int)puVar36 + -2) = CONCAT11(uVar17,*(undefined1 *)(iVar404 + -0xf));
  *(undefined2 *)((int)puVar36 + -4) =
       CONCAT11(uVar17,*(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc));
  *(undefined2 *)((int)puVar36 + -6) = *(undefined2 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 2);
  *(undefined2 *)((int)puVar36 + -8) = *(undefined2 *)*(undefined4 *)(iVar404 + -0x1e);
  *(undefined2 *)((int)puVar36 + -10) = pcVar495;
  puVar57 = (undefined1 *)((int)puVar36 + -0xc);
  *(undefined2 *)((int)puVar36 + -0xc) = 0x2e4;
  cVar18 = func_0x0004f32d();
  puVar208 = (undefined2 *)(puVar57 + 8);
  if (cVar18 == '\0') {
    pfVar25 = (far_t *)(int)*(char *)(*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc) + 0x885
                                     );
    pcVar494 = (char *)((ulong)*(undefined4 *)(iVar404 + -0x1e) >> 0x10);
    pfVar37 = (far_t *)(far_t *)*(undefined4 *)(iVar404 + -0x1e);
    puVar58 = (undefined2 *)(puVar57 + 8);
code_r0x00040300:
    pfVar37->ofs = (uint16_t)((int)&pfVar25->ofs + pfVar37->ofs);
    pfVar25 = (far_t *)(uint)*(byte *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0xc);
switchD_4000_f055_caseD_7:
    piVar3 = (int *)((int)*(undefined4 *)(iVar404 + -0x1e) + 2);
    *piVar3 = *piVar3 + (int)*(char *)(((uint)pfVar25 & 0xff) + 0x889);
    pcVar508 = (char *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0x2f);
    *pcVar508 = *pcVar508 + '\x01';
    puVar208 = puVar58;
  }
  else {
    *(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0x2f) = 0;
    *(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x1e) + 0x30) = 0;
  }
  goto LAB_3f0b_1477;
switchD_4000_4689_switchD:
  pcVar495 = "";
  bVar29 = (byte)((uint)pfVar25 >> 8);
  bVar31 = (byte)pfVar37;
  bVar38 = (byte)((uint)pfVar37 >> 8);
  cVar18 = (char)pcVar21;
  bVar27 = (byte)((uint)pcVar21 >> 8);
  bVar39 = (byte)((uint)in_CX >> 8);
  puVar486 = (undefined1 *)(iVar404 + -2);
  puVar208 = (undefined2 *)((int)puVar97 + 0x10);
  puVar111 = (undefined2 *)((int)puVar97 + 0x10);
  puVar35 = (undefined2 *)((int)puVar97 + 0x10);
  puVar12 = (undefined2 *)((int)puVar97 + 0x10);
  puVar13 = (undefined2 *)((int)puVar97 + 0x10);
  puVar14 = (undefined2 *)((int)puVar97 + 0x10);
  puVar58 = (undefined2 *)((int)puVar97 + 0x10);
  puVar220 = (undefined2 *)((int)puVar97 + 0x10);
  switch(*(byte *)(iVar404 + -0x13)) {
  case 0:
    puVar111 = (undefined2 *)((int)puVar97 + 0x10);
    if (in_CX == (uint16_t *)0x0) goto code_r0x0004270b;
  case 0x69:
  case 0x8b:
code_r0x000426e5:
    do {
      *(far_t **)(char *)((int)&pfVar37[0x9b8].ofs + 1) = pfVar25;
      puVar114 = puVar111;
code_r0x000426ec:
      while( true ) {
        for (pfVar24 = (far_t *)0x0; (int)pfVar24 < 3; pfVar24 = (far_t *)((int)&pfVar24->ofs + 1))
        {
          pfVar25 = (far_t *)((int)pfVar489 * 0x95 + (int)pfVar24 * 2);
          uVar23 = (pfVar25 + 0x9c2)->ofs;
code_r0x00042709:
          puVar112 = puVar114;
          if (uVar23 == 0) {
            iVar488 = (int)pfVar489 * 0x95 + (int)pfVar24 * 4;
            uVar20 = *(undefined2 *)((int)AgntGs[0].sprs + iVar488);
            *(undefined2 *)((int)puVar114 + -2) = *(undefined2 *)((int)AgntGs[0].sprs + 2 + iVar488)
            ;
            *(undefined2 *)((int)puVar114 + -4) = uVar20;
            iVar488 = (int)pfVar489 * 0x95 + (int)pfVar24 * 4;
            uVar20 = *(undefined2 *)((int)puVar114 + -4);
            *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar488) =
                 *(undefined2 *)((int)puVar114 + -2);
            *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar488) = uVar20;
          }
          else {
code_r0x0004270b:
            *(undefined2 *)((int)puVar112 + -2) =
                 CONCAT11((char)((uint)pfVar25 >> 8),*(undefined1 *)(iVar404 + 4));
            *(uint *)((int)puVar112 + -4) =
                 (uint)*(byte *)((int)&AgntGs[0].nanims + (int)pfVar489 * 0x95);
            *(undefined2 *)((int)puVar112 + -6) =
                 *(undefined2 *)((int)&AgntGs[0].anms + 2 + (int)pfVar489 * 0x95);
            *(undefined2 *)((int)puVar112 + -8) =
                 *(undefined2 *)((int)&AgntGs[0].anms + (int)pfVar489 * 0x95);
            *(undefined2 *)((int)puVar112 + -10) =
                 *(undefined2 *)
                  ((int)AgntGs[0].sprfls + 6 + (int)pfVar489 * 0x95 + (int)pfVar24 * 2);
            *(undefined2 *)((int)puVar112 + -0xc) = pcVar495;
            puVar113 = (undefined1 *)((int)puVar112 + -0xe);
            *(undefined2 *)((int)puVar112 + -0xe) = (char *)"Message delay is now %d." + 0xe;
            fVar503 = stshSprite(*(int16_t *)((int)puVar112 + -10),
                                 (anm_t *)*(undefined4 *)((int)puVar112 + -8),
                                 *(uint16_t *)((int)puVar112 + -4),
                                 (bool)*(undefined1 *)((int)puVar112 + -2));
            puVar114 = (uint16_t *)(puVar113 + 0xe);
            *(uint16_t *)(puVar113 + 0xc) = fVar503.ofs;
            *(uint16_t *)(puVar113 + 10) = fVar503.seg;
            iVar488 = (int)pfVar489 * 0x95 + (int)pfVar24 * 4;
            *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar488) = *(undefined2 *)(puVar113 + 10);
            *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar488) = *(undefined2 *)(puVar113 + 0xc);
          }
        }
        for (iVar488 = 0; iVar488 < 6; iVar488 = iVar488 + 1) {
          if (*(int *)((int)AgntGs[0].prtfls + (int)pfVar489 * 0x95 + iVar488 * 2) != 0) {
            if (*(char *)(iVar404 + 4) == '\0') {
              *(undefined2 *)((int)puVar114 + -2) = pcVar495;
              puVar121 = (uint16_t *)((int)puVar114 + -4);
              *(undefined2 *)((int)puVar114 + -4) =
                   (char *)"Name for this save:  (Esc to cancel)" + 0xd;
              fVar503 = ovr_stshAllocStub();
              puVar121[1] = fVar503.ofs;
              *puVar121 = fVar503.seg;
              iVar490 = (int)pfVar489 * 0x95 + iVar488 * 4;
              *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar490) = *puVar121;
              *(undefined2 *)((int)AgntGs[0].prts + iVar490) = puVar121[1];
              puVar121[1] = (uint16_t)((char *)"trade faire" + 4);
              pcVar495 = (char *)"trade faire" + 4;
              *puVar121 = (uint16_t)((char *)"Delete Game:" + 5);
              fVar503 = ovr_stshAllocStub();
              puVar114 = puVar121 + 2;
              puVar121[1] = fVar503.ofs;
              *puVar121 = fVar503.seg;
              iVar490 = (int)pfVar489 * 0x95 + iVar488 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar490) = *puVar121;
              *(undefined2 *)((int)AgntGs[0].prtpals + iVar490) = puVar121[1];
            }
            else {
              *(undefined2 *)((int)puVar114 + -2) = 0;
              *(undefined2 *)((int)puVar114 + -4) = 0;
              *(undefined2 *)((int)puVar114 + -6) =
                   *(undefined2 *)((int)AgntGs[0].prtfls + (int)pfVar489 * 0x95 + iVar488 * 2);
              *(undefined2 *)((int)puVar114 + -8) = pcVar495;
              puVar115 = (undefined1 *)((int)puVar114 + -10);
              *(undefined2 *)((int)puVar114 + -10) = (char *)"Quit Game" + 8;
              psVar505 = ovr_grabLbm(*(int16_t *)((int)puVar114 + -6),
                                     *(int16_t *)((int)puVar114 + -4),
                                     *(int16_t *)((int)puVar114 + -2));
              *(undefined2 *)(iVar404 + -4) = (int)((ulong)psVar505 >> 0x10);
              *(undefined2 *)(iVar404 + -6) = (stg_tmp_t *)psVar505;
              *(undefined2 *)(puVar115 + 8) = *(undefined2 *)(iVar404 + -4);
              *(undefined2 *)(puVar115 + 6) = *(undefined2 *)(iVar404 + -6);
              *(char **)(puVar115 + 4) = (char *)"bath house" + 2;
              piVar116 = (int16_t *)(puVar115 + 2);
              *(char **)(puVar115 + 2) = (char *)"Great Achievements" + 4;
              ovr_stshUniqueColorsRemap(*(stg_tmp_t **)(puVar115 + 6));
              piVar116[3] = 0;
              piVar116[2] = 0;
              piVar116[1] = 0x67;
              *piVar116 = 0x72;
              piVar116[-1] = 0;
              piVar116[-2] = 0;
              uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
              iVar490 = (int)*(undefined4 *)(iVar404 + -6);
              piVar116[-3] = *(undefined2 *)(iVar490 + 0x302);
              piVar116[-4] = *(undefined2 *)(iVar490 + 0x300);
              piVar116[-5] = (int16_t)((char *)"mage outpost" + 3);
              piVar117 = piVar116 + -6;
              piVar116[-6] = (int16_t)(char *)"Stronghold V 1.00";
              uVar509 = ovr_stshRleType2(*(far_t *)(piVar116 + -4),piVar116[-2],piVar116[-1],
                                         *piVar116,piVar116[1],piVar116[2],piVar116[3]);
              *(undefined2 *)((int)piVar117 + 0x12) = (int)((ulong)uVar509 >> 0x10);
              *(undefined2 *)((int)piVar117 + 0x10) = (int)uVar509;
              *(undefined2 *)((int)piVar117 + 0xe) = (char *)"bath house" + 10;
              puVar118 = (undefined2 *)((int)piVar117 + 0xc);
              *(undefined2 *)((int)piVar117 + 0xc) = (char *)"Stronghold V 1.00" + 10;
              pcVar501 = ovr_stshStoreFile((uint8_t *)*(undefined4 *)((int)piVar117 + 0x10));
              puVar118[3] = (cte_t *)pcVar501;
              puVar118[2] = (int)((ulong)pcVar501 >> 0x10);
              iVar490 = (int)pfVar489 * 0x95 + iVar488 * 4;
              *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar490) = puVar118[2];
              *(undefined2 *)((int)AgntGs[0].prts + iVar490) = puVar118[3];
              puVar118[3] = 0;
              puVar118[2] = 0x300;
              puVar118[1] = *(undefined2 *)(iVar404 + -4);
              *puVar118 = *(undefined2 *)(iVar404 + -6);
              puVar118[-1] = (char *)"mage outpost" + 3;
              puVar119 = puVar118 + -2;
              puVar118[-2] = (char *)"Game not saved: Are you sure?" + 0x1c;
              uVar504 = ovr_stshWrite((uint8_t *)*puVar118,*(long *)(puVar118 + 2));
              *(undefined2 *)((int)puVar119 + 10) = (int)uVar504;
              *(undefined2 *)((int)puVar119 + 8) = (int)(uVar504 >> 0x10);
              iVar490 = (int)pfVar489 * 0x95 + iVar488 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar490) =
                   *(undefined2 *)((int)puVar119 + 8);
              *(undefined2 *)((int)AgntGs[0].prtpals + iVar490) =
                   *(undefined2 *)((int)puVar119 + 10);
              *(undefined2 *)((int)puVar119 + 10) = *(undefined2 *)(iVar404 + -4);
              *(undefined2 *)((int)puVar119 + 8) = *(undefined2 *)(iVar404 + -6);
              *(undefined2 *)((int)puVar119 + 6) = (char *)"mage outpost" + 3;
              pcVar495 = (char *)"mage outpost" + 3;
              puVar120 = (undefined1 *)((int)puVar119 + 4);
              *(undefined2 *)((int)puVar119 + 4) =
                   (char *)"Name for this save:  (Esc to cancel)" + 3;
              ovr_stgFreeTmp((stg_tmp_t *)*(undefined4 *)((int)puVar119 + 8));
              puVar114 = (uint16_t *)(puVar120 + 8);
            }
          }
        }
        pfVar37 = (far_t *)(*(uint *)((int)AgntGs[0].prts + 4 + (int)pfVar489 * 0x95) |
                           *(uint *)((int)AgntGs[0].prts + 6 + (int)pfVar489 * 0x95));
        if ((pfVar37 == (far_t *)0x0) &&
           (pfVar37 = (far_t *)0x0,
           *(int *)((int)AgntGs[0].prts + (int)pfVar489 * 0x95) != 0 ||
           *(int *)((int)AgntGs[0].prts + 2 + (int)pfVar489 * 0x95) != 0)) {
          uVar20 = *(undefined2 *)((int)AgntGs[0].prts + (int)pfVar489 * 0x95);
          *(undefined2 *)((int)puVar114 + -2) =
               *(undefined2 *)((int)AgntGs[0].prts + 2 + (int)pfVar489 * 0x95);
          *(undefined2 *)((int)puVar114 + -4) = uVar20;
          uVar20 = *(undefined2 *)((int)puVar114 + -4);
          *(undefined2 *)((int)AgntGs[0].prts + 6 + (int)pfVar489 * 0x95) =
               *(undefined2 *)((int)puVar114 + -2);
          *(undefined2 *)((int)AgntGs[0].prts + 4 + (int)pfVar489 * 0x95) = uVar20;
          uVar20 = *(undefined2 *)((int)AgntGs[0].prtpals + (int)pfVar489 * 0x95);
          *(undefined2 *)((int)puVar114 + -2) =
               *(undefined2 *)((int)AgntGs[0].prtpals + 2 + (int)pfVar489 * 0x95);
          *(undefined2 *)((int)puVar114 + -4) = uVar20;
          pfVar37 = (far_t *)*(uint *)((int)puVar114 + -4);
          *(undefined2 *)((int)AgntGs[0].prtpals + 6 + (int)pfVar489 * 0x95) =
               *(undefined2 *)((int)puVar114 + -2);
          *(uint *)((int)AgntGs[0].prtpals + 4 + (int)pfVar489 * 0x95) = (uint)pfVar37;
        }
        pfVar24 = (far_t *)(far_t *)&_DATA;
        pfVar25 = pfVar489;
        puVar122 = puVar114;
        while (pfVar24 = (far_t *)&pfVar24->seg, (int)pfVar24 < 6) {
          iVar488 = (int)pfVar25 * 0x95 + (int)pfVar24 * 4;
          if ((*(int *)((int)AgntGs[0].prts + 4 + iVar488) == 0 &&
               *(int *)((int)AgntGs[0].prts + 6 + iVar488) == 0) &&
             (iVar488 = (int)pfVar25 * 0x95 + (int)pfVar24 * 4,
             *(int *)((int)AgntGs[0].prtfls + 8 + iVar488) != 0 ||
             *(int *)((int)AgntGs[0].prtfls + 10 + iVar488) != 0)) {
            iVar488 = (int)pfVar25 * 0x95 + (int)pfVar24 * 4;
            uVar20 = *(undefined2 *)((int)AgntGs[0].prtfls + 8 + iVar488);
            *(undefined2 *)((int)puVar122 + -2) =
                 *(undefined2 *)((int)AgntGs[0].prtfls + 10 + iVar488);
            *(undefined2 *)((int)puVar122 + -4) = uVar20;
            iVar488 = (int)pfVar25 * 0x95 + (int)pfVar24 * 4;
            uVar20 = *(undefined2 *)((int)puVar122 + -4);
            *(undefined2 *)((int)AgntGs[0].prts + 6 + iVar488) = *(undefined2 *)((int)puVar122 + -2)
            ;
            *(undefined2 *)((int)AgntGs[0].prts + 4 + iVar488) = uVar20;
            iVar488 = (int)pfVar25 * 0x95 + (int)pfVar24 * 4;
            uVar20 = *(undefined2 *)((int)AgntGs[0].prts + 0x14 + iVar488);
            *(undefined2 *)((int)puVar122 + -2) =
                 *(undefined2 *)((int)AgntGs[0].prts + 0x16 + iVar488);
            *(undefined2 *)((int)puVar122 + -4) = uVar20;
            iVar488 = (int)pfVar25 * 0x95 + (int)pfVar24 * 4;
            uVar20 = *(undefined2 *)((int)puVar122 + -4);
            *(undefined2 *)((int)AgntGs[0].prtpals + 6 + iVar488) =
                 *(undefined2 *)((int)puVar122 + -2);
            *(undefined2 *)((int)AgntGs[0].prtpals + 4 + iVar488) = uVar20;
          }
          iVar488 = (int)pfVar25 * 0x95 + (int)pfVar24 * 4;
          pfVar37 = (far_t *)(*(uint *)((int)AgntGs[0].prts + iVar488) |
                             *(uint *)((int)AgntGs[0].prts + 2 + iVar488));
          pfVar489 = pfVar25;
          if (pfVar37 == (far_t *)0x0) {
code_r0x00042ab7:
            pfVar25 = (far_t *)((int)pfVar25 * 0x95);
            pcVar21 = (char *)((int)pfVar24 << 2);
            puVar123 = puVar122;
code_r0x00042ac1:
            pfVar25 = (far_t *)(pcVar21 + (int)&pfVar25->ofs);
            puVar124 = puVar123;
code_r0x00042ac3:
            puVar122 = puVar124;
            if (pfVar25[0x9cb].seg == 0 && (pfVar25 + 0x9cc)->ofs == 0) {
              pfVar37 = (far_t *)0x0;
              pfVar25 = pfVar489;
            }
            else {
              iVar488 = (int)pfVar489 * 0x95 + (int)pfVar24 * 4;
              uVar20 = *(undefined2 *)((int)AgntGs[0].prtfls + 4 + iVar488);
              *(undefined2 *)((int)puVar124 + -2) =
                   *(undefined2 *)((int)AgntGs[0].prtfls + 6 + iVar488);
              *(undefined2 *)((int)puVar124 + -4) = uVar20;
              iVar488 = (int)pfVar489 * 0x95 + (int)pfVar24 * 4;
              uVar20 = *(undefined2 *)((int)puVar124 + -4);
              *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar488) =
                   *(undefined2 *)((int)puVar124 + -2);
              *(undefined2 *)((int)AgntGs[0].prts + iVar488) = uVar20;
              iVar488 = (int)pfVar489 * 0x95 + (int)pfVar24 * 4;
              uVar20 = *(undefined2 *)((int)AgntGs[0].prts + 0x10 + iVar488);
              *(undefined2 *)((int)puVar124 + -2) =
                   *(undefined2 *)((int)AgntGs[0].prts + 0x12 + iVar488);
              *(undefined2 *)((int)puVar124 + -4) = uVar20;
              iVar488 = (int)pfVar489 * 0x95 + (int)pfVar24 * 4;
              pfVar37 = (far_t *)*(uint *)((int)puVar124 + -4);
              *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar488) =
                   *(undefined2 *)((int)puVar124 + -2);
              *(uint *)((int)AgntGs[0].prtpals + iVar488) = (uint)pfVar37;
              pfVar25 = pfVar489;
            }
          }
        }
        pfVar489 = (far_t *)((int)&pfVar25->ofs + 1);
        if (0x29 < (int)pfVar489) {
          return pfVar37;
        }
        *(undefined2 *)((int)puVar122 + -2) =
             CONCAT11((char)((uint)pfVar37 >> 8),*(undefined1 *)(iVar404 + 4));
        *(uint *)((int)puVar122 + -4) =
             (uint)*(byte *)((int)&AgntGs[0].nanims + (int)pfVar489 * 0x95);
        *(undefined2 *)((int)puVar122 + -6) =
             *(undefined2 *)((int)&AgntGs[0].anms + 2 + (int)pfVar489 * 0x95);
        *(undefined2 *)((int)puVar122 + -8) =
             *(undefined2 *)((int)&AgntGs[0].anms + (int)pfVar489 * 0x95);
        *(undefined2 *)((int)puVar122 + -10) =
             *(undefined2 *)((int)AgntGs[0].sprfls + (int)pfVar489 * 0x95);
        *(undefined2 *)((int)puVar122 + -0xc) = pcVar495;
        puVar104 = (undefined1 *)((int)puVar122 + -0xe);
        *(undefined2 *)((int)puVar122 + -0xe) = (char *)"axe,hammer" + 4;
        fVar503 = stshSprite(*(int16_t *)((int)puVar122 + -10),
                             (anm_t *)*(undefined4 *)((int)puVar122 + -8),
                             *(uint16_t *)((int)puVar122 + -4),
                             (bool)*(undefined1 *)((int)puVar122 + -2));
        puVar105 = (undefined2 *)(puVar104 + 0xe);
        *(uint16_t *)(puVar104 + 0xc) = fVar503.ofs;
        *(uint16_t *)(puVar104 + 10) = fVar503.seg;
        *(undefined2 *)((int)AgntGs[0].sprs + 2 + (int)pfVar489 * 0x95) =
             *(undefined2 *)(puVar104 + 10);
        *(undefined2 *)((int)AgntGs[0].sprs + (int)pfVar489 * 0x95) =
             *(undefined2 *)(puVar104 + 0xc);
        if (*(int *)((int)AgntGs[0].sprfls + 2 + (int)pfVar489 * 0x95) == 0) {
          uVar20 = *(undefined2 *)((int)AgntGs[0].sprs + (int)pfVar489 * 0x95);
          *(undefined2 *)(puVar104 + 0xc) =
               *(undefined2 *)((int)AgntGs[0].sprs + 2 + (int)pfVar489 * 0x95);
          puVar108 = (undefined2 *)(puVar104 + 10);
          *(undefined2 *)(puVar104 + 10) = uVar20;
          pfVar25 = (far_t *)((int)pfVar489 * 0x95);
          pcVar21 = (char *)0x195d;
code_r0x00042626:
          uVar20 = *puVar108;
          puVar107 = puVar108 + 2;
          *(undefined2 *)((int)&pfVar25[0x9b7].seg + 1) = puVar108[1];
          *(undefined2 *)(char *)((int)&pfVar25[0x9b7].ofs + 1) = uVar20;
        }
        else {
          pfVar25 = (far_t *)CONCAT11((char)((uint)((int)pfVar489 * 0x95) >> 8),
                                      *(undefined1 *)(iVar404 + 4));
code_r0x0004259b:
          *(undefined2 *)((int)puVar105 + -2) = pfVar25;
          *(uint *)((int)puVar105 + -4) =
               (uint)*(byte *)((int)&AgntGs[0].nanims + (int)pfVar489 * 0x95);
          *(undefined2 *)((int)puVar105 + -6) =
               *(undefined2 *)((int)&AgntGs[0].anms + 2 + (int)pfVar489 * 0x95);
          *(undefined2 *)((int)puVar105 + -8) =
               *(undefined2 *)((int)&AgntGs[0].anms + (int)pfVar489 * 0x95);
          *(undefined2 *)((int)puVar105 + -10) =
               *(undefined2 *)((int)AgntGs[0].sprfls + 2 + (int)pfVar489 * 0x95);
          *(undefined2 *)((int)puVar105 + -0xc) = pcVar495;
          puVar106 = (undefined1 *)((int)puVar105 + -0xe);
          *(undefined2 *)((int)puVar105 + -0xe) = (char *)"manscorpion" + 2;
          fVar503 = stshSprite(*(int16_t *)((int)puVar105 + -10),
                               (anm_t *)*(undefined4 *)((int)puVar105 + -8),
                               *(uint16_t *)((int)puVar105 + -4),
                               (bool)*(undefined1 *)((int)puVar105 + -2));
          puVar107 = (undefined2 *)(puVar106 + 0xe);
          *(uint16_t *)(puVar106 + 0xc) = fVar503.ofs;
          *(uint16_t *)(puVar106 + 10) = fVar503.seg;
          *(undefined2 *)((int)AgntGs[0].sprs + 6 + (int)pfVar489 * 0x95) =
               *(undefined2 *)(puVar106 + 10);
          *(undefined2 *)((int)AgntGs[0].sprs + 4 + (int)pfVar489 * 0x95) =
               *(undefined2 *)(puVar106 + 0xc);
        }
        if (*(int *)((int)AgntGs[0].sprfls + 4 + (int)pfVar489 * 0x95) == 0) break;
        *(undefined2 *)((int)puVar107 + -2) =
             CONCAT11((char)((uint)((int)pfVar489 * 0x95) >> 8),*(undefined1 *)(iVar404 + 4));
        *(uint *)((int)puVar107 + -4) =
             (uint)*(byte *)((int)&AgntGs[0].nanims + (int)pfVar489 * 0x95);
        *(undefined2 *)((int)puVar107 + -6) =
             *(undefined2 *)((int)&AgntGs[0].anms + 2 + (int)pfVar489 * 0x95);
        *(undefined2 *)((int)puVar107 + -8) =
             *(undefined2 *)((int)&AgntGs[0].anms + (int)pfVar489 * 0x95);
        *(undefined2 *)((int)puVar107 + -10) =
             *(undefined2 *)((int)AgntGs[0].sprfls + 4 + (int)pfVar489 * 0x95);
        *(undefined2 *)((int)puVar107 + -0xc) = pcVar495;
        puVar109 = (undefined1 *)((int)puVar107 + -0xe);
        *(undefined2 *)((int)puVar107 + -0xe) = (char *)"cockatrice" + 9;
        fVar503 = stshSprite(*(int16_t *)((int)puVar107 + -10),
                             (anm_t *)*(undefined4 *)((int)puVar107 + -8),
                             *(uint16_t *)((int)puVar107 + -4),
                             (bool)*(undefined1 *)((int)puVar107 + -2));
        *(uint16_t *)(puVar109 + 0xc) = fVar503.ofs;
        *(uint16_t *)(puVar109 + 10) = fVar503.seg;
        *(undefined2 *)((int)AgntGs[0].sprs + 10 + (int)pfVar489 * 0x95) =
             *(undefined2 *)(puVar109 + 10);
        *(undefined2 *)((int)AgntGs[0].sprs + 8 + (int)pfVar489 * 0x95) =
             *(undefined2 *)(puVar109 + 0xc);
        puVar114 = (uint16_t *)(puVar109 + 0xe);
      }
      pfVar37 = (far_t *)((int)pfVar489 * 0x95);
      pcVar21 = (char *)0x195d;
code_r0x000426c2:
      uVar20 = *(undefined2 *)(char *)((int)&pfVar37[0x9b7].ofs + 1);
      *(undefined2 *)((int)puVar107 + -2) = *(undefined2 *)((int)&pfVar37[0x9b7].seg + 1);
      *(undefined2 *)((int)puVar107 + -4) = uVar20;
      pfVar37 = (far_t *)((int)pfVar489 * 0x95);
      pcVar494 = (char *)0x195d;
      pfVar25 = (far_t *)*(undefined2 *)((int)puVar107 + -4);
      puVar110 = (undefined2 *)((int)puVar107 + -2);
code_r0x000426df:
      *(undefined2 *)((int)&pfVar37[0x9b8].seg + 1) = *puVar110;
      puVar111 = puVar110 + 1;
    } while( true );
  case 1:
  case 100:
  case 0x67:
    *(int *)((int)&pfVar24[-0x1c4a].ofs + *(int *)((int)puVar97 + 0x10)) =
         (*(int *)((int)&pfVar24[-0x1c4a].ofs + *(int *)((int)puVar97 + 0x10)) - (int)in_CX) -
         (uint)bVar499;
    return pfVar25;
  case 2:
  case 0x1d:
  case 0x65:
  case 0x68:
  case 0x8a:
    puVar208 = (undefined2 *)((int)puVar97 + 0x10);
    break;
  case 3:
  case 0x1e:
    *(undefined2 *)((int)&pfVar37[0x9b8].seg + 1) = pcVar21;
    puVar111 = (undefined2 *)((int)puVar97 + 0x10);
    goto code_r0x000426e5;
  case 4:
    puVar126 = (undefined2 *)((int)puVar97 + 0x10);
    do {
      iVar488 = Entities.ofs + (int)EntityCount * 0x37;
      *(uint16_t *)((int)puVar126 + -2) = Entities.seg;
      *(int *)((int)puVar126 + -4) = iVar488;
      *(undefined2 *)((int)puVar126 + -6) = 0x4000;
      puVar125 = (undefined1 *)((int)puVar126 + -8);
      *(undefined2 *)((int)puVar126 + -8) = (char *)"cuex1.xmi" + 4;
      bVar19 = OVC15_4207_25dd();
      puVar126 = (undefined2 *)(puVar125 + 8);
      *(uint *)(iVar404 + -6) = (uint)bVar19;
      *(uint *)(puVar125 + 6) =
           CONCAT11((char)((uint)((int)EntityCount * 0x37) >> 8),
                    *(char *)(Entities.ofs + (int)EntityCount * 0x37 + 0x31) +
                    *(char *)(iVar404 + -6));
      *(undefined1 *)(Entities.ofs + (int)EntityCount * 0x37 + 0x31) =
           (char)*(undefined2 *)(puVar125 + 6);
      *(uint *)(puVar125 + 6) =
           CONCAT11((char)((uint)((int)EntityCount * 0x37) >> 8),
                    *(char *)(Entities.ofs + (int)EntityCount * 0x37 + 0x32) +
                    *(char *)(iVar404 + -6));
      *(undefined1 *)(Entities.ofs + (int)EntityCount * 0x37 + 0x32) =
           (char)*(undefined2 *)(puVar125 + 6);
      pcVar508 = (char *)(Entities.ofs + (int)EntityCount * 0x37 + 0xf);
      *pcVar508 = *pcVar508 + '\x01';
LAB_4207_1503:
      puVar32 = puVar126;
    } while (*(byte *)(Entities.ofs + (int)EntityCount * 0x37 + 0xf) < 5);
    goto LAB_4207_151b;
  case 5:
  case 0x59:
  case 0x6b:
  case 0x7b:
  case 0x93:
  case 0xa9:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 6:
  case 0x6c:
  case 0x94:
  case 0xaa:
    puVar233 = (undefined2 *)((int)puVar97 + 0xe);
    *(undefined2 *)((int)puVar97 + 0xe) = unaff_SS;
  case 0x5a:
  case 0x7c:
    *(int *)((int)puVar233 + -2) = iVar404 + -5;
    *(int *)((int)puVar233 + -4) = GfxRndSeed2;
    *(int *)((int)puVar233 + -6) = GfxRndSeed + -1;
    uVar509 = *(undefined4 *)((uint)DAT_2000_d1e4 * 4 + -4);
    iVar488 = (uint)*(byte *)((int)uVar509 + 0x3e) * 0x95;
    *(undefined2 *)((int)puVar233 + -8) =
         CONCAT11((char)((uint)iVar488 >> 8),
                  *(undefined1 *)((int)(far_t *)(far_t_ARRAY_2410_26f7 + 0xb) + iVar488));
    *(undefined2 *)((int)puVar233 + -10) = 0x4000;
    pcVar495 = (char *)"thief outpost" + 10;
    puVar234 = (undefined1 *)((int)puVar233 + -0xc);
    *(undefined2 *)((int)puVar233 + -0xc) = 0x960b;
    ovr_OVC23_55fe_1e87();
    *(undefined2 *)(puVar234 + 0xe) = 0;
    *(int *)(puVar234 + 0xc) = GfxRndSeed2;
    *(int *)(puVar234 + 10) = GfxRndSeed;
    *(uint *)(puVar234 + 8) = CONCAT11(0x24,DAT_2000_d1e4 - 1);
    *(char **)(puVar234 + 6) = (char *)"thief outpost" + 10;
    puVar235 = puVar234 + 4;
    *(undefined2 *)(puVar234 + 4) = 0x9634;
    OVC18_48ac_0382();
    puVar236 = puVar235 + 0xc;
    if (2 < DAT_2000_d19d) {
      *(undefined2 *)(puVar235 + 10) = unaff_SS;
      *(int *)(puVar235 + 8) = iVar404 + -5;
      *(uint *)(puVar235 + 6) = CONCAT11(0x24,DAT_2000_d1e4 - 1);
      *(char **)(puVar235 + 4) = (char *)"thief outpost" + 10;
      pcVar495 = (char *)"cleric outpost" + 0xd;
      puVar237 = puVar235 + 2;
      *(undefined2 *)(puVar235 + 2) = 0x965a;
      ovr_OVC22_5087_4975();
      puVar236 = puVar237 + 10;
    }
    *(uint *)(puVar236 + -2) = CONCAT11(0x24,DAT_2000_d1e4 - 1);
    *(char **)(puVar236 + -4) = pcVar495;
    puVar238 = puVar236 + -6;
    *(undefined2 *)(puVar236 + -6) = 0x966e;
    ovr_OVC22_5087_056e();
    DAT_2000_d1e4 = 0;
    *(char **)(puVar238 + 4) = (char *)"cleric outpost" + 0xd;
    puVar239 = (undefined4 *)(puVar238 + 2);
    *(undefined2 *)(puVar238 + 2) = 0x9681;
    ovr_manage_4d05_0000();
    *(undefined2 *)((int)puVar239 + 2) = (char *)"cleric outpost";
    *(undefined2 *)puVar239 = 0x9686;
    ovr_stats_6386_232d();
    *(undefined2 *)((int)puVar239 + 2) = (char *)"money dealer\'s shop" + 0xe;
    *(undefined2 *)puVar239 = 0x968b;
    ovr_unit_6616_00d8();
    *(undefined2 *)((int)puVar239 + 2) = (char *)"puppetmaker" + 3;
    *(char **)puVar239 = (char *)"View %s." + 8;
    *(undefined2 *)((int)puVar239 + -2) = (char *)"bank" + 4;
    puVar240 = puVar239 + -1;
    *(undefined2 *)(puVar239 + -1) = 0x9694;
    ovr_say((char *)*puVar239);
    pfVar24 = (far_t *)(uint)DAT_2000_d310;
    if (pfVar24 == (far_t *)0x0) {
      *(undefined2 *)((int)puVar240 + 6) = 2;
      *(undefined2 *)((int)puVar240 + 4) = (char *)"steam bath" + 6;
      *(undefined2 *)((int)puVar240 + 2) = 0x96ad;
      pfVar24 = (far_t *)ovr_OVC30_619c_004e();
    }
    return pfVar24;
  case 7:
  case 0x6d:
  case 0x95:
  case 0xab:
    do {
      if (bVar500) {
        *(int *)*(undefined4 *)(iVar404 + 0x20) = *(int *)*(undefined4 *)(iVar404 + 0x20) + 1;
      }
      while( true ) {
        while( true ) {
          do {
            pfVar24 = (far_t *)((int)&pfVar24->ofs + 1);
            if (DAT_2000_d2df <= pfVar24) {
              *(int *)(iVar404 + -4) =
                   *(int *)(iVar404 + -4) -
                   (*(int *)*(undefined4 *)(iVar404 + 0x1c) +
                   *(int *)*(undefined4 *)(iVar404 + 0x20));
              *(int *)*(undefined4 *)(iVar404 + 8) =
                   *(int *)*(undefined4 *)(iVar404 + 8) - *(int *)*(undefined4 *)(iVar404 + 0x1c);
              *(int *)*(undefined4 *)(iVar404 + 0xc) =
                   *(int *)*(undefined4 *)(iVar404 + 0xc) - *(int *)*(undefined4 *)(iVar404 + 0x20);
              return (far_t *)*(undefined2 *)(iVar404 + -4);
            }
          } while ((*(char *)((int)pfVar24 * 0x12 + 9) != *(char *)(iVar404 + 4)) ||
                  (bVar19 = *(byte *)((int)pfVar24 * 0x12 + 8),
                  *(char *)((uint)bVar19 * 0x27 + 0x133) != *(char *)(iVar404 + 6)));
          *(int *)*(undefined4 *)(iVar404 + 0x14) = *(int *)*(undefined4 *)(iVar404 + 0x14) + 1;
          if (*(char *)((uint)bVar19 * 0x27 + 0x131) != '\x01') break;
          *(int *)*(undefined4 *)(iVar404 + 0x18) = *(int *)*(undefined4 *)(iVar404 + 0x18) + 1;
        }
        if (*(char *)((uint)bVar19 * 0x27 + 0x131) != '\x02') break;
        *(int *)*(undefined4 *)(iVar404 + 0x1c) = *(int *)*(undefined4 *)(iVar404 + 0x1c) + 1;
      }
      bVar500 = *(char *)((uint)bVar19 * 0x27 + 0x131) == '\x03';
    } while( true );
  case 8:
    uVar23 = (pfVar37 + 3)->ofs;
    goto code_r0x0004baee;
  case 9:
  case 0x16:
  case 0x61:
  case 0x83:
  case 0x9a:
  case 0xb0:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 10:
  case 0x17:
  case 0x62:
  case 0x84:
  case 0x9b:
  case 0xb1:
                    /* WARNING (jumptable): Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
    s_cue9a_xmi_2410_36fe[1] = -0x58;
    *(uint *)((int)&pfVar489[0x1a07].ofs + iVar404) =
         *(uint *)((int)&pfVar489[0x1a07].ofs + iVar404) & (uint)in_CX;
    puVar298 = (undefined4 *)((int)puVar97 + 0xf);
    goto code_r0x0004d89a;
  case 0xb:
  case 0x18:
  case 99:
  case 0x85:
  case 0x9c:
  case 0xb2:
    goto code_r0x0004c28e;
  case 0xc:
  case 0x48:
  case 0x78:
                    /* WARNING (jumptable): Read-only address (ram,0x00027f80) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
    s_captmg3_lbm_2410_3e7d[3] = '@';
    bVar499 = false;
    goto code_r0x00048b2f;
  case 0xd:
    while( true ) {
      *(undefined2 *)((int)puVar352 + -2) = 0;
      *(uint *)((int)puVar352 + -4) = (uint)*(byte *)(iVar404 + -0x19);
      *(undefined2 *)((int)puVar352 + -6) = unaff_SS;
      *(int *)((int)puVar352 + -8) = iVar404 + -0x2a;
      *(undefined2 *)((int)puVar352 + -10) = pcVar495;
      puVar353 = (undefined1 *)((int)puVar352 + -0xc);
      *(undefined2 *)((int)puVar352 + -0xc) = 0xdf99;
      uVar17 = ovr_uiInputText();
      *(undefined1 *)(iVar404 + -0x1a) = uVar17;
      if (*(char *)(iVar404 + -0x1a) == '\0') {
                    /* WARNING: Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
        return (far_t *)0x0;
      }
      if (*(char *)(iVar404 + -0x1a) == '\x01') break;
      *(undefined1 *)(iVar404 + -0x17) =
           *(undefined1 *)((uint)*(byte *)(iVar404 + -0x1a) + iVar404 + -0x18);
      *(char **)(puVar353 + 0xe) = (char *)"puppetmaker" + 3;
      *(char **)(puVar353 + 0xc) = (char *)"Select ability to adjust downwards by two points.";
      *(char **)(puVar353 + 10) = (char *)"halfling outpost" + 4;
      piVar354 = (int *)(puVar353 + 8);
      *(undefined2 *)(puVar353 + 8) = 0xdfd3;
      ovr_drawString();
      piVar354[3] = 0;
      piVar354[2] = 0x10;
      piVar354[1] = unaff_SS;
      *piVar354 = iVar404 + -0x2a;
      piVar354[-1] = (int)((char *)"money dealer\'s shop" + 0xe);
      piVar355 = piVar354 + -2;
      piVar354[-2] = 0xdfe4;
      _fsetmem(*(void **)piVar354,piVar354[2],piVar354[3]);
      *(undefined2 *)(iVar404 + -0x28) = (char *)"puppetmaker" + 3;
      *(undefined2 *)(iVar404 + -0x2a) = (char *)"Cancel";
      *(undefined1 *)(iVar404 + -0x19) = 1;
      *(undefined1 *)(iVar404 + -0x18) = 0;
      while (*(byte *)(iVar404 + -0x18) < 3) {
        if ((10 < *(byte *)((int)*(undefined4 *)(iVar404 + 4) + (uint)*(byte *)(iVar404 + -0x18) +
                           0x29)) && (*(char *)(iVar404 + -0x17) != *(char *)(iVar404 + -0x18))) {
          *(undefined1 *)((uint)*(byte *)(iVar404 + -0x19) + iVar404 + -0x17) =
               *(undefined1 *)(iVar404 + -0x18);
          uVar23 = ((far_t *)GStatsLabels + *(byte *)(iVar404 + -0x18))->ofs;
          puVar114 = (uint16_t *)((uint)*(byte *)(iVar404 + -0x19) * 4 + iVar404 + -0x2a);
          puVar114[1] = *(uint16_t *)
                         ((int)&GStatsLabels[0].seg + (uint)*(byte *)(iVar404 + -0x18) * 4);
          *puVar114 = uVar23;
          *(char *)(iVar404 + -0x19) = *(char *)(iVar404 + -0x19) + '\x01';
        }
        *(char *)(iVar404 + -0x18) = *(char *)(iVar404 + -0x18) + '\x01';
      }
      piVar355[5] = 0;
      piVar355[4] = 0;
      piVar355[3] = 0;
      piVar355[2] = (uint)*(byte *)(iVar404 + -0x19);
      piVar355[1] = unaff_SS;
      *piVar355 = iVar404 + -0x2a;
      piVar355[-1] = 0x1000;
      piVar356 = piVar355 + -2;
      piVar355[-2] = 0xe06c;
      uVar17 = ovr_uiInputText();
      puVar357 = (undefined1 *)((int)piVar356 + 0x10);
      *(undefined1 *)(iVar404 + -0x1a) = uVar17;
      if (*(char *)(iVar404 + -0x1a) == '\0') {
        return (far_t *)0x0;
      }
      if (*(char *)(iVar404 + -0x1a) != '\x01') {
        pcVar508 = (char *)((int)*(undefined4 *)(iVar404 + 4) + (uint)*(byte *)(iVar404 + -0x17) +
                           0x29);
        *pcVar508 = *pcVar508 + '\x01';
        *(char *)((int)*(undefined4 *)(iVar404 + 4) +
                  (uint)*(byte *)((uint)*(byte *)(iVar404 + -0x1a) + iVar404 + -0x18) + 0x29) =
             *(char *)((int)*(undefined4 *)(iVar404 + 4) +
                       (uint)*(byte *)((uint)*(byte *)(iVar404 + -0x1a) + iVar404 + -0x18) + 0x29) +
             -2;
        *(undefined2 *)((int)piVar356 + 0xe) = (char *)"halfling outpost" + 4;
        puVar358 = (undefined2 *)((int)piVar356 + 0xc);
        *(undefined2 *)((int)piVar356 + 0xc) = 0xe0d0;
        manage_4d05_0081();
        puVar358[1] = *(undefined2 *)(iVar404 + 6);
        *puVar358 = *(undefined2 *)(iVar404 + 4);
        puVar358[-1] = (char *)"halfling outpost" + 4;
        puVar359 = puVar358 + -2;
        puVar358[-2] = 0xe0da;
        manage_4d05_056e();
        puVar357 = (undefined1 *)((int)puVar359 + 8);
      }
      *(undefined2 *)(puVar357 + -2) = 0;
      *(undefined2 *)(puVar357 + -4) = 0x10;
      *(undefined2 *)(puVar357 + -6) = unaff_SS;
      *(int *)(puVar357 + -8) = iVar404 + -0x2a;
      *(char **)(puVar357 + -10) = (char *)"halfling outpost" + 4;
      puVar349 = puVar357 + -0xc;
      *(undefined2 *)(puVar357 + -0xc) = 0xde44;
      _fsetmem(*(void **)(puVar357 + -8),*(uint16_t *)(puVar357 + -4),*(uint16_t *)(puVar357 + -2));
      *(undefined2 *)(iVar404 + -0x28) = (char *)"puppetmaker" + 3;
      *(undefined2 *)(iVar404 + -0x2a) = (char *)"Accept";
      *(undefined1 *)(iVar404 + -0x19) = 1;
      *(undefined2 *)(puVar349 + 10) = *(undefined2 *)(iVar404 + 6);
      *(undefined2 *)(puVar349 + 8) = *(undefined2 *)(iVar404 + 4);
      puVar485 = (undefined1 *)
                 ((uint)*(byte *)((int)*(undefined4 *)(iVar404 + 4) + 0x2f) + iVar404 + -10);
      *(uint *)(puVar349 + 6) = CONCAT11((char)((uint)puVar485 >> 8),*puVar485);
      *(undefined2 *)(puVar349 + 4) = 0x1000;
      puVar350 = (undefined2 *)(puVar349 + 2);
      *(undefined2 *)(puVar349 + 2) = 0xde71;
      cVar18 = manage_4d05_0d7b();
      puVar36 = puVar350 + 5;
      if (cVar18 != '\0') {
        *(undefined1 *)((uint)*(byte *)(iVar404 + -0x19) + iVar404 + -0x17) =
             *(undefined1 *)
              ((uint)*(byte *)((int)*(undefined4 *)(iVar404 + 4) + 0x2f) + iVar404 + -10);
        uVar487 = (uint)*(byte *)((uint)*(byte *)((int)*(undefined4 *)(iVar404 + 4) + 0x2f) +
                                 iVar404 + -10);
        uVar23 = ((far_t *)GStatsLabels + uVar487)->ofs;
        puVar114 = (uint16_t *)((uint)*(byte *)(iVar404 + -0x19) * 4 + iVar404 + -0x2a);
        puVar114[1] = *(uint16_t *)((int)&GStatsLabels[0].seg + uVar487 * 4);
        *puVar114 = uVar23;
        *(char *)(iVar404 + -0x19) = *(char *)(iVar404 + -0x19) + '\x01';
      }
      if (*(char *)((uint)*(byte *)((int)*(undefined4 *)(iVar404 + 4) + 0x2f) + iVar404 + -0x12) !=
          -1) {
        puVar350[4] = *(undefined2 *)(iVar404 + 6);
        puVar350[3] = *(undefined2 *)(iVar404 + 4);
        puVar485 = (undefined1 *)
                   ((uint)*(byte *)((int)*(undefined4 *)(iVar404 + 4) + 0x2f) + iVar404 + -0x12);
        puVar350[2] = CONCAT11((char)((uint)puVar485 >> 8),*puVar485);
        puVar350[1] = 0x1000;
        *puVar350 = 0xdf0a;
        cVar18 = manage_4d05_0d7b();
        puVar36 = (undefined2 *)((int)puVar350 + 10);
        if (cVar18 != '\0') {
          *(undefined1 *)((uint)*(byte *)(iVar404 + -0x19) + iVar404 + -0x17) =
               *(undefined1 *)
                ((uint)*(byte *)((int)*(undefined4 *)(iVar404 + 4) + 0x2f) + iVar404 + -0x12);
          uVar487 = (uint)*(byte *)((uint)*(byte *)((int)*(undefined4 *)(iVar404 + 4) + 0x2f) +
                                   iVar404 + -0x12);
          uVar23 = ((far_t *)GStatsLabels + uVar487)->ofs;
          puVar114 = (uint16_t *)((uint)*(byte *)(iVar404 + -0x19) * 4 + iVar404 + -0x2a);
          puVar114[1] = *(uint16_t *)((int)&GStatsLabels[0].seg + uVar487 * 4);
          *puVar114 = uVar23;
          *(char *)(iVar404 + -0x19) = *(char *)(iVar404 + -0x19) + '\x01';
          puVar36 = (undefined2 *)((int)puVar350 + 10);
        }
      }
      if (*(char *)(iVar404 + -0x19) == '\x01') {
        return (far_t *)((int)(undefined4 *)&_DATA + 1);
      }
      *(undefined2 *)((int)puVar36 + -2) = (char *)"puppetmaker" + 3;
      *(undefined2 *)((int)puVar36 + -4) =
           (char *)
           "You may raise a primary ability by trading two points of another ability. Select ability to increase."
      ;
      *(undefined2 *)((int)puVar36 + -6) = 0x1000;
      pcVar495 = (char *)"money dealer\'s shop" + 0xe;
      puVar351 = (undefined1 *)((int)puVar36 + -8);
      *(undefined2 *)((int)puVar36 + -8) = 0xdf80;
      ovr_drawString();
      *(undefined2 *)(puVar351 + 6) = 0;
      puVar352 = (undefined2 *)(puVar351 + 4);
      *(undefined2 *)(puVar351 + 4) = 0;
    }
    return (far_t *)((int)(undefined4 *)&_DATA + 1);
  case 0xe:
  case 0x1c:
  case 0x89:
    goto code_r0x00042626;
  case 0xf:
    while (((bVar500 && (*(char *)((int)pfVar489 * 0x27 + 0x133) != '\0')) &&
           (*(char *)((int)pfVar489 * 0x27 + 0x133) != '\a'))) {
      pfVar489 = (far_t *)((int)&pfVar489->ofs + 1);
      if ((far_t *)((char *)"y1 %d yn %d y3 %d yx %d " + 0x11) < pfVar489) {
        pfVar489 = (far_t *)((int)&GUnitDescriptions[3].ofs + 1);
      }
      if ((far_t *)*(undefined2 *)(iVar404 + -4) == pfVar489) break;
LAB_48ac_0cb6:
      bVar500 = (*(uint *)((int)pfVar489 * 0x27 + 0x121) & 0xa0) == 0;
    }
    *(undefined2 *)(iVar404 + -6) = 0;
    while (*(uint *)(iVar404 + -6) < 0x94) {
      for (uVar487 = 0; uVar487 < 0x3c; uVar487 = uVar487 + 1) {
        uVar20 = (undefined2)((ulong)DAT_2000_cb0d >> 0x10);
        if ((far_t *)*(undefined2 *)
                      ((int)DAT_2000_cb0d + *(int *)(iVar404 + -6) * 0x78 + uVar487 * 2) == pfVar489
           ) {
          *(undefined2 *)((int)DAT_2000_cb0d + *(int *)(iVar404 + -6) * 0x78 + uVar487 * 2) = 0;
        }
      }
      *(int *)(iVar404 + -6) = *(int *)(iVar404 + -6) + 1;
    }
    *(undefined1 *)((int)DAT_2000_ca95 + (int)pfVar489 * 9) = *(undefined1 *)(iVar404 + 8);
    *(undefined1 *)((int)DAT_2000_ca95 + (int)pfVar489 * 9 + 1) = 8;
    *(undefined1 *)((int)DAT_2000_ca95 + (int)pfVar489 * 9 + 2) = *(undefined1 *)(iVar404 + 10);
    *(undefined2 *)((int)DAT_2000_ca95 + (int)pfVar489 * 9 + 4) = *(undefined2 *)(iVar404 + 4);
    *(undefined2 *)((int)DAT_2000_ca95 + (int)pfVar489 * 9 + 6) = *(undefined2 *)(iVar404 + 6);
    *(undefined2 *)((int)DAT_2000_cb0d + *(int *)(iVar404 + 4) * 0x78 + *(int *)(iVar404 + 6) * 2) =
         pfVar489;
    *(int *)((int)puVar241 + -2) =
         (uint)*(byte *)((uint)*(byte *)(iVar404 + 8) * 0x27 + 0x11e) << 0xe;
    *(uint *)((int)puVar241 + -2) =
         *(uint *)((int)DAT_2000_cb09 + *(int *)(iVar404 + 6) * 0x128 + *(int *)(iVar404 + 4) * 2) &
         0x3fff | *(uint *)((int)puVar241 + -2);
    *(undefined2 *)((int)DAT_2000_cb09 + *(int *)(iVar404 + 6) * 0x128 + *(int *)(iVar404 + 4) * 2)
         = *(undefined2 *)((int)puVar241 + -2);
    if ((*(uint *)((uint)*(byte *)(iVar404 + 8) * 0x27 + 0x121) & 0x40) == 0) {
      *(undefined1 *)((int)DAT_2000_ca95 + (int)pfVar489 * 9 + 8) = 0;
      return pfVar489;
    }
    *(undefined2 *)((int)puVar241 + -2) = *(undefined2 *)(iVar404 + 6);
    *(undefined2 *)((int)puVar241 + -4) = *(undefined2 *)(iVar404 + 4);
    *(undefined2 *)((int)puVar241 + -6) = 0x4000;
    puVar242 = (undefined1 *)((int)puVar241 + -8);
    *(undefined2 *)((int)puVar241 + -8) = 0x9946;
    cVar18 = ovr_constr_36ce_3172();
    if (cVar18 == '\x03') {
      *(undefined2 *)(puVar242 + 6) = 0x28;
      *(char **)(puVar242 + 4) = (char *)"stonemasonry" + 3;
      puVar244 = puVar242 + 2;
      *(undefined2 *)(puVar242 + 2) = 0x9986;
      uVar23 = ovr_randBelow(*(uint16_t *)(puVar242 + 6));
      *(uint *)(puVar244 + 4) = CONCAT11((char)(uVar23 >> 8),(char)uVar23 + '\x1e');
      *(undefined1 *)((int)DAT_2000_ca95 + (int)pfVar489 * 9 + 8) =
           (char)*(undefined2 *)(puVar244 + 4);
      return pfVar489;
    }
    if (cVar18 == '\x04') {
      *(undefined2 *)(puVar242 + 6) = 0x50;
      *(char **)(puVar242 + 4) = (char *)"stonemasonry" + 3;
      puVar245 = puVar242 + 2;
      *(undefined2 *)(puVar242 + 2) = 0x99ae;
      uVar23 = ovr_randBelow(*(uint16_t *)(puVar242 + 6));
      *(uint *)(puVar245 + 4) = CONCAT11((char)(uVar23 >> 8),(char)uVar23 + '<');
      *(undefined1 *)((int)DAT_2000_ca95 + (int)pfVar489 * 9 + 8) =
           (char)*(undefined2 *)(puVar245 + 4);
      return pfVar489;
    }
    *(undefined2 *)(puVar242 + 6) = 0x14;
    *(char **)(puVar242 + 4) = (char *)"stonemasonry" + 3;
    puVar243 = puVar242 + 2;
    *(undefined2 *)(puVar242 + 2) = 0x995e;
    uVar23 = ovr_randBelow(*(uint16_t *)(puVar242 + 6));
    *(uint *)(puVar243 + 4) = CONCAT11((char)(uVar23 >> 8),(char)uVar23 + '\x0f');
    *(undefined1 *)((int)DAT_2000_ca95 + (int)pfVar489 * 9 + 8) =
         (char)*(undefined2 *)(puVar243 + 4);
    return pfVar489;
  case 0x10:
    goto code_r0x000426dd;
  case 0x11:
  case 0x31:
  case 0x3c:
  case 0xd9:
  case 0xf4:
    puVar485 = (undefined1 *)(iVar404 + -2);
    puVar216 = (undefined2 *)((int)puVar97 + 0x10);
    if (in_CX != (uint16_t *)0x0) goto code_r0x00048b54;
    *(undefined2 *)(iVar404 + 0x26be) = 0;
    pfVar37 = (far_t *)(*pfVar37).ofs;
    puVar485 = (undefined1 *)(iVar404 + -2);
    puVar216 = (undefined2 *)((int)puVar97 + 0x10);
    goto code_r0x00048b54;
  case 0x12:
  case 0xda:
  case 0xf5:
    goto code_r0x0004bbbc;
  default:
    goto code_r0x00040095;
  case 0x14:
  case 0xdc:
  case 0xf7:
                    /* WARNING (jumptable): Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
    s_mage_college_2410_1e4b[5] = 'd';
    *(undefined2 *)((int)puVar97 + 0xe) = (far_t *)far_t_ARRAY_2410_4ada;
    *(undefined2 *)((int)puVar97 + 0xc) = 0x4000;
    pcVar495 = (char *)0x1000;
    puVar415 = (undefined2 *)((int)puVar97 + 10);
    *(undefined2 *)((int)puVar97 + 10) = 0xf761;
    F_SCOPY((uint8_t *)*(undefined2 *)((int)puVar97 + 0x12),
            (uint8_t *)*(undefined2 *)((int)puVar97 + 0xe),0x14);
    for (iVar488 = 0; iVar488 < 5; iVar488 = iVar488 + 1) {
      puVar36 = (undefined2 *)(iVar488 * 4 + iVar404 + -0x158);
      uVar20 = *puVar36;
      puVar32 = (undefined2 *)(iVar488 * 4 + iVar404 + -0x144);
      puVar32[1] = puVar36[1];
      *puVar32 = uVar20;
    }
    for (iVar488 = 0; iVar488 < 0x1e; iVar488 = iVar488 + 1) {
      *(int *)((int)puVar415 + 10) = iVar488 * 4 + iVar404 + -0x130;
      uVar20 = *(undefined2 *)((int)&GStructures[0].field2_0x2 + iVar488 * 6);
      puVar36 = (undefined2 *)*(undefined2 *)((int)puVar415 + 10);
      puVar36[1] = *(undefined2 *)((int)&GStructures[0].field2_0x2 + 2 + iVar488 * 6);
      *puVar36 = uVar20;
    }
    *(undefined1 *)(iVar404 + -0x17) = 2;
    *(undefined2 *)((int)puVar415 + 10) = 0x1000;
    puVar416 = (uint8_t *)((int)puVar415 + 8);
    *(undefined2 *)((int)puVar415 + 8) = 0xf7c6;
    manage_4d05_0081();
    *(undefined1 *)(iVar404 + -0x18) = 0;
    if (((*(char *)(iVar404 + -0x17) != '\x02') && (*(char *)(iVar404 + -0x17) != '\x03')) &&
       (*(char *)(iVar404 + -0x17) != '\x04')) {
      pfVar24 = (far_t *)manage_4d05_2b09();
      return pfVar24;
    }
    if (DAT_2410_26a8 == 0) {
      *(undefined2 *)(puVar416 + 2) = 0x1000;
      *(undefined2 *)puVar416 = 0xf7f2;
      manage_4d05_0081();
      puVar418 = puVar416 + 4;
    }
    else {
      *(undefined2 *)(puVar416 + 2) = 0;
      *(undefined2 *)puVar416 = 0x10;
      *(char **)(puVar416 + -2) = (char *)"puppetmaker" + 3;
      *(undefined2 *)(puVar416 + -4) = 0x44a;
      *(undefined2 *)(puVar416 + -6) = 0;
      *(undefined2 *)(puVar416 + -8) = 0;
      *(undefined2 *)(puVar416 + -10) = DAT_2000_cc87;
      *(undefined2 *)(puVar416 + -0xc) = DAT_2000_cc85;
      *(undefined2 *)(puVar416 + -0xe) = 0x1000;
      pcVar495 = (char *)"bath house" + 10;
      puVar417 = puVar416 + -0x10;
      *(undefined2 *)(puVar416 + -0x10) = 0xf816;
      ovr_blitGfxRect(*(far_t *)(puVar416 + -0xc),*(int16_t *)(puVar416 + -8),
                      *(int16_t *)(puVar416 + -6),*(brect_t **)(puVar416 + -4),*puVar416,
                      (bool)puVar416[2]);
      puVar418 = puVar417 + 0x14;
    }
    TextBlitY = 0xc;
    TextBlitX = 0x11;
    if (*(char *)(iVar404 + 4) == -1) {
      *(undefined2 *)(puVar418 + -2) = 0x50;
      *(undefined2 *)(puVar418 + -4) = 0xde;
      *(uint16_t *)(puVar418 + -6) = Font02.seg;
      *(uint16_t *)(puVar418 + -8) = Font02.ofs;
      *(char **)(puVar418 + -10) = (char *)"puppetmaker" + 3;
      *(char **)(puVar418 + -0xc) = (char *)"All property.";
      *(char **)(puVar418 + -0xe) = pcVar495;
      puVar419 = puVar418 + -0x10;
      *(undefined2 *)(puVar418 + -0x10) = 0xf854;
      ovr_blitLabel(*(char **)(puVar418 + -0xc),*(uint8_t **)(puVar418 + -8),
                    *(int16_t *)(puVar418 + -4),puVar418[-2]);
      puVar420 = puVar419 + 0x10;
    }
    else {
      uVar20 = *(undefined2 *)((uint)*(byte *)(iVar404 + 4) * 4);
      *(undefined2 *)(iVar404 + -4) = ((undefined2 *)((uint)*(byte *)(iVar404 + 4) * 4))[1];
      *(undefined2 *)(iVar404 + -6) = uVar20;
      *(undefined2 *)(puVar418 + -2) = 0x50;
      *(undefined2 *)(puVar418 + -4) = 0xde;
      *(uint16_t *)(puVar418 + -6) = Font02.seg;
      *(uint16_t *)(puVar418 + -8) = Font02.ofs;
      *(undefined2 *)(puVar418 + -10) = 3;
      *(undefined2 *)(puVar418 + -0xc) = 0x69;
      *(uint16_t *)(puVar418 + -0xe) = Font02.seg;
      *(uint16_t *)(puVar418 + -0x10) = Font02.ofs;
      *(undefined2 *)(puVar418 + -0x12) = *(undefined2 *)(iVar404 + -4);
      *(undefined2 *)(puVar418 + -0x14) = *(undefined2 *)(iVar404 + -6);
      *(undefined2 *)(puVar418 + -0x16) = unaff_SS;
      *(int *)(puVar418 + -0x18) = iVar404 + -0x68;
      *(char **)(puVar418 + -0x1a) = pcVar495;
      puVar421 = puVar418 + -0x1c;
      *(undefined2 *)(puVar418 + -0x1c) = 0xf8b0;
      uVar493 = ovr_OVC45_77eb_226e();
      *(undefined2 *)(puVar421 + 0x12) = uVar20;
      *(undefined2 *)(puVar421 + 0x10) = uVar493;
      *(undefined2 *)(puVar421 + 0xe) = *(undefined2 *)(iVar404 + -4);
      *(undefined2 *)(puVar421 + 0xc) = *(undefined2 *)(iVar404 + -6);
      *(char **)(puVar421 + 10) = (char *)"trade faire" + 8;
      puVar422 = (undefined4 *)(puVar421 + 8);
      *(undefined2 *)(puVar421 + 8) = 0xf8bf;
      uVar493 = manage_4d05_03a4();
      *(undefined2 *)((int)puVar422 + 6) = uVar20;
      *(undefined2 *)(puVar422 + 1) = uVar493;
      *(undefined2 *)((int)puVar422 + 2) = (char *)"puppetmaker" + 3;
      *(char **)puVar422 = (char *)"Buildings belonging to %s%s";
      *(undefined2 *)((int)puVar422 + -2) = unaff_SS;
      *(int *)(puVar422 + -1) = iVar404 + -0xb8;
      *(undefined2 *)((int)puVar422 + -6) = (char *)"trade faire" + 8;
      puVar423 = puVar422 + -2;
      *(undefined2 *)(puVar422 + -2) = 0xf8d3;
      pcVar508 = ovr_stsprintf(*(char **)(puVar422 + -1),(char *)*puVar422,*(char **)(puVar422 + 1))
      ;
      *(undefined2 *)((int)puVar423 + 0x12) = (int)((ulong)pcVar508 >> 0x10);
      *(undefined2 *)((int)puVar423 + 0x10) = (char *)pcVar508;
      *(undefined2 *)((int)puVar423 + 0xe) = (char *)"glassworks" + 9;
      puVar424 = (undefined1 *)((int)puVar423 + 0xc);
      *(undefined2 *)((int)puVar423 + 0xc) = 0xf8dd;
      ovr_blitLabel((char *)*(undefined4 *)((int)puVar423 + 0x10),
                    (uint8_t *)*(undefined4 *)((int)puVar423 + 0x14),
                    *(int16_t *)((int)puVar423 + 0x18),*(uint8_t *)((int)puVar423 + 0x1a));
      puVar420 = puVar424 + 0x10;
    }
    TextBlitY = TextBlitY + 0xc;
    TextBlitX = 0x11;
    *(undefined2 *)(puVar420 + -2) = 0xe0;
    *(undefined2 *)(puVar420 + -4) = 0xde;
    *(uint16_t *)(puVar420 + -6) = Font02.seg;
    *(uint16_t *)(puVar420 + -8) = Font02.ofs;
    *(char **)(puVar420 + -10) = (char *)"puppetmaker" + 3;
    *(char **)(puVar420 + -0xc) = (char *)"Buildings";
    *(char **)(puVar420 + -0xe) = (char *)"steam bath" + 6;
    pcVar495 = (char *)"steam bath" + 6;
    puVar425 = puVar420 + -0x10;
    *(undefined2 *)(puVar420 + -0x10) = 0xf915;
    ovr_blitLabel(*(char **)(puVar420 + -0xc),*(uint8_t **)(puVar420 + -8),
                  *(int16_t *)(puVar420 + -4),puVar420[-2]);
    *(undefined2 *)(puVar425 + 0xe) = 0xe0;
    *(undefined2 *)(puVar425 + 0xc) = 100;
    *(char **)(puVar425 + 10) = (char *)"puppetmaker" + 3;
    *(char **)(puVar425 + 8) = (char *)"Total";
    *(char **)(puVar425 + 6) = (char *)"steam bath" + 6;
    puVar426 = (undefined2 *)(puVar425 + 4);
    *(undefined2 *)(puVar425 + 4) = 0xf925;
    manage_4d05_0519();
    puVar426[5] = 0xe0;
    puVar426[4] = 0x8c;
    puVar426[3] = (char *)"puppetmaker" + 3;
    puVar426[2] = (char *)"Level 1";
    puVar426[1] = (char *)"steam bath" + 6;
    *puVar426 = 0xf936;
    manage_4d05_0519();
    puVar426[5] = 0xe0;
    puVar426[4] = 0xb4;
    puVar426[3] = (char *)"puppetmaker" + 3;
    puVar426[2] = (char *)"Level 2";
    puVar426[1] = (char *)"steam bath" + 6;
    *puVar426 = 0xf947;
    manage_4d05_0519();
    puVar426[5] = 0xe0;
    puVar426[4] = 0xdc;
    puVar426[3] = (char *)"puppetmaker" + 3;
    puVar426[2] = (char *)"Level 3";
    puVar426[1] = (char *)"steam bath" + 6;
    *puVar426 = 0xf958;
    manage_4d05_0519();
    puVar427 = (undefined1 *)((int)puVar426 + 0xc);
    TextBlitY = TextBlitY + 0xc;
    if (*(char *)(iVar404 + -0x17) == '\x04') {
      iVar488 = 0x1a;
    }
    else if (*(char *)(iVar404 + -0x17) == '\x03') {
      iVar488 = 0xd;
    }
    else {
      iVar488 = 0;
    }
    for (iVar490 = 0; iVar490 < 0xd; iVar490 = iVar490 + 1) {
      if (iVar490 + iVar488 < 0x1e) {
        TextBlitX = 0x11;
        *(undefined2 *)(puVar427 + -2) = 0xe0;
        *(undefined2 *)(puVar427 + -4) = 0xde;
        *(uint16_t *)(puVar427 + -6) = Font02.seg;
        *(uint16_t *)(puVar427 + -8) = Font02.ofs;
        iVar26 = (iVar490 + iVar488) * 6;
        *(undefined2 *)(puVar427 + -10) =
             *(undefined2 *)((int)&GStructures[0].field2_0x2 + 2 + iVar26);
        *(undefined2 *)(puVar427 + -0xc) = *(undefined2 *)((int)&GStructures[0].field2_0x2 + iVar26)
        ;
        *(char **)(puVar427 + -0xe) = pcVar495;
        pcVar495 = (char *)"steam bath" + 6;
        piVar428 = (int *)(puVar427 + -0x10);
        *(undefined2 *)(puVar427 + -0x10) = 0xf9c8;
        ovr_blitLabel(*(char **)(puVar427 + -0xc),*(uint8_t **)(puVar427 + -8),
                      *(int16_t *)(puVar427 + -4),puVar427[-2]);
        piVar428[7] = unaff_SS;
        piVar428[6] = iVar404 + -0x14;
        piVar428[5] = unaff_SS;
        piVar428[4] = iVar404 + -0x12;
        piVar428[3] = unaff_SS;
        piVar428[2] = iVar404 + -0x10;
        piVar428[1] = unaff_SS;
        *piVar428 = iVar404 + -0xe;
        piVar428[-1] = unaff_SS;
        piVar428[-2] = iVar404 + -0xc;
        piVar428[-3] = unaff_SS;
        piVar428[-4] = iVar404 + -10;
        piVar428[-5] = unaff_SS;
        piVar428[-6] = iVar404 + -8;
        lVar502 = (long)(iVar490 + iVar488) * 6;
        uVar493 = (undefined2)((ulong)lVar502 >> 0x10);
        uVar17 = (undefined1)((ulong)lVar502 >> 8);
        piVar428[-7] = CONCAT11(uVar17,(&((unk01_t *)GStructures)->field0_0x0)[(int)lVar502]);
        piVar428[-8] = CONCAT11(uVar17,*(undefined1 *)(iVar404 + 4));
        piVar428[-9] = (int)((char *)"steam bath" + 6);
        piVar429 = piVar428 + -10;
        piVar428[-10] = 0xfa06;
        uVar20 = manage_4d05_23fc();
        *(undefined2 *)(iVar404 + -0x16) = uVar20;
        if (*(int *)(iVar404 + -0xe) == 0) {
          *(undefined2 *)((int)piVar429 + 0x22) = 100;
          *(undefined2 *)((int)piVar429 + 0x20) = 0;
          *(undefined2 *)((int)piVar429 + 0x1e) = *(undefined2 *)(iVar404 + -0x16);
          *(undefined2 *)((int)piVar429 + 0x1c) = unaff_SS;
          *(int *)((int)piVar429 + 0x1a) = iVar404 + -0x68;
          *(undefined2 *)((int)piVar429 + 0x18) = (char *)"steam bath" + 6;
          puVar430 = (undefined1 *)((int)piVar429 + 0x16);
          *(undefined2 *)((int)piVar429 + 0x16) = 0xfa22;
          pcVar21 = litoa10((char *)*(undefined2 *)((int)piVar429 + 0x1a),
                            *(long *)((int)piVar429 + 0x1e));
          *(undefined2 *)(puVar430 + 10) = uVar493;
          *(char **)(puVar430 + 8) = pcVar21;
          *(char **)(puVar430 + 6) = (char *)"steam bath" + 6;
          puVar431 = puVar430 + 4;
          *(undefined2 *)(puVar430 + 4) = 0xfa2b;
          manage_4d05_04c6();
          puVar427 = puVar431 + 10;
        }
        else {
          *(undefined2 *)((int)piVar429 + 0x22) = 100;
          *(undefined2 *)((int)piVar429 + 0x20) = *(undefined2 *)(iVar404 + -0xe);
          *(undefined2 *)((int)piVar429 + 0x1e) = *(undefined2 *)(iVar404 + -0x16);
          *(undefined2 *)((int)piVar429 + 0x1c) = (char *)"puppetmaker" + 3;
          *(undefined2 *)((int)piVar429 + 0x1a) = (char *)"%d (%d)";
          *(undefined2 *)((int)piVar429 + 0x18) = unaff_SS;
          *(int *)((int)piVar429 + 0x16) = iVar404 + -0xb8;
          *(undefined2 *)((int)piVar429 + 0x14) = (char *)"steam bath" + 6;
          pcVar495 = (char *)"glassworks" + 9;
          puVar432 = (undefined1 *)((int)piVar429 + 0x12);
          *(undefined2 *)((int)piVar429 + 0x12) = 0xfa47;
          pcVar508 = ovr_stsprintf((char *)*(undefined2 *)((int)piVar429 + 0x16),
                                   (char *)*(undefined4 *)((int)piVar429 + 0x1a),
                                   (char *)*(undefined2 *)((int)piVar429 + 0x1e));
          *(int *)(puVar432 + 0xe) = (int)((ulong)pcVar508 >> 0x10);
          *(char **)(puVar432 + 0xc) = (char *)pcVar508;
          *(char **)(puVar432 + 10) = (char *)"glassworks" + 9;
          puVar433 = puVar432 + 8;
          *(undefined2 *)(puVar432 + 8) = 0xfa50;
          manage_4d05_04c6();
          puVar427 = puVar433 + 10;
        }
        lVar502 = (long)(iVar490 + iVar488) * 6;
        uVar20 = (undefined2)((ulong)lVar502 >> 0x10);
        if (*(char *)((int)&GStructures[0].field1_0x1 + (int)lVar502) != '\0') {
          if (*(int *)(iVar404 + -0x10) == 0) {
            *(undefined2 *)(puVar427 + -2) = 0x8c;
            *(undefined2 *)(puVar427 + -4) = 0;
            *(undefined2 *)(puVar427 + -6) = *(undefined2 *)(iVar404 + -8);
            *(undefined2 *)(puVar427 + -8) = unaff_SS;
            *(int *)(puVar427 + -10) = iVar404 + -0x68;
            *(char **)(puVar427 + -0xc) = pcVar495;
            puVar434 = puVar427 + -0xe;
            *(undefined2 *)(puVar427 + -0xe) = 0xfa7f;
            pcVar21 = litoa10(*(char **)(puVar427 + -10),*(long *)(puVar427 + -6));
            *(undefined2 *)(puVar434 + 10) = uVar20;
            *(char **)(puVar434 + 8) = pcVar21;
            *(char **)(puVar434 + 6) = pcVar495;
            puVar435 = puVar434 + 4;
            *(undefined2 *)(puVar434 + 4) = 0xfa88;
            manage_4d05_04c6();
            puVar436 = puVar435 + 10;
          }
          else {
            *(undefined2 *)(puVar427 + -2) = 0x8c;
            *(undefined2 *)(puVar427 + -4) = *(undefined2 *)(iVar404 + -0x10);
            *(undefined2 *)(puVar427 + -6) = *(undefined2 *)(iVar404 + -8);
            *(char **)(puVar427 + -8) = (char *)"puppetmaker" + 3;
            *(char **)(puVar427 + -10) = (char *)"%d (%d)";
            *(undefined2 *)(puVar427 + -0xc) = unaff_SS;
            *(int *)(puVar427 + -0xe) = iVar404 + -0xb8;
            *(char **)(puVar427 + -0x10) = pcVar495;
            pcVar495 = (char *)"glassworks" + 9;
            puVar437 = puVar427 + -0x12;
            *(undefined2 *)(puVar427 + -0x12) = 0xfaa5;
            pcVar508 = ovr_stsprintf(*(char **)(puVar427 + -0xe),*(char **)(puVar427 + -10),
                                     *(char **)(puVar427 + -6));
            uVar20 = (undefined2)((ulong)pcVar508 >> 0x10);
            *(undefined2 *)(puVar437 + 0xe) = uVar20;
            *(char **)(puVar437 + 0xc) = (char *)pcVar508;
            *(char **)(puVar437 + 10) = (char *)"glassworks" + 9;
            puVar438 = puVar437 + 8;
            *(undefined2 *)(puVar437 + 8) = 0xfaae;
            manage_4d05_04c6();
            puVar436 = puVar438 + 10;
          }
          if (*(int *)(iVar404 + -0x12) == 0) {
            *(undefined2 *)(puVar436 + -2) = 0xb4;
            *(undefined2 *)(puVar436 + -4) = 0;
            *(undefined2 *)(puVar436 + -6) = *(undefined2 *)(iVar404 + -10);
            *(undefined2 *)(puVar436 + -8) = unaff_SS;
            *(int *)(puVar436 + -10) = iVar404 + -0x68;
            *(char **)(puVar436 + -0xc) = pcVar495;
            puVar439 = puVar436 + -0xe;
            *(undefined2 *)(puVar436 + -0xe) = 0xfac8;
            pcVar21 = litoa10(*(char **)(puVar436 + -10),*(long *)(puVar436 + -6));
            *(undefined2 *)(puVar439 + 10) = uVar20;
            *(char **)(puVar439 + 8) = pcVar21;
            *(char **)(puVar439 + 6) = pcVar495;
            puVar440 = puVar439 + 4;
            *(undefined2 *)(puVar439 + 4) = 0xfad1;
            manage_4d05_04c6();
            puVar441 = puVar440 + 10;
          }
          else {
            *(undefined2 *)(puVar436 + -2) = 0xb4;
            *(undefined2 *)(puVar436 + -4) = *(undefined2 *)(iVar404 + -0x12);
            *(undefined2 *)(puVar436 + -6) = *(undefined2 *)(iVar404 + -10);
            *(char **)(puVar436 + -8) = (char *)"puppetmaker" + 3;
            *(char **)(puVar436 + -10) = (char *)"%d (%d)";
            *(undefined2 *)(puVar436 + -0xc) = unaff_SS;
            *(int *)(puVar436 + -0xe) = iVar404 + -0xb8;
            *(char **)(puVar436 + -0x10) = pcVar495;
            pcVar495 = (char *)"glassworks" + 9;
            puVar442 = puVar436 + -0x12;
            *(undefined2 *)(puVar436 + -0x12) = 0xfaee;
            pcVar508 = ovr_stsprintf(*(char **)(puVar436 + -0xe),*(char **)(puVar436 + -10),
                                     *(char **)(puVar436 + -6));
            uVar20 = (undefined2)((ulong)pcVar508 >> 0x10);
            *(undefined2 *)(puVar442 + 0xe) = uVar20;
            *(char **)(puVar442 + 0xc) = (char *)pcVar508;
            *(char **)(puVar442 + 10) = (char *)"glassworks" + 9;
            puVar443 = puVar442 + 8;
            *(undefined2 *)(puVar442 + 8) = 0xfaf7;
            manage_4d05_04c6();
            puVar441 = puVar443 + 10;
          }
          if (*(int *)(iVar404 + -0x14) == 0) {
            *(undefined2 *)(puVar441 + -2) = 0xdc;
            *(undefined2 *)(puVar441 + -4) = 0;
            *(undefined2 *)(puVar441 + -6) = *(undefined2 *)(iVar404 + -0xc);
            *(undefined2 *)(puVar441 + -8) = unaff_SS;
            *(int *)(puVar441 + -10) = iVar404 + -0x68;
            *(char **)(puVar441 + -0xc) = pcVar495;
            puVar444 = puVar441 + -0xe;
            *(undefined2 *)(puVar441 + -0xe) = 0xfb11;
            pcVar21 = litoa10(*(char **)(puVar441 + -10),*(long *)(puVar441 + -6));
            *(undefined2 *)(puVar444 + 10) = uVar20;
            *(char **)(puVar444 + 8) = pcVar21;
            *(char **)(puVar444 + 6) = pcVar495;
            puVar445 = puVar444 + 4;
            *(undefined2 *)(puVar444 + 4) = 0xfb1a;
            manage_4d05_04c6();
            puVar427 = puVar445 + 10;
          }
          else {
            *(undefined2 *)(puVar441 + -2) = 0xdc;
            *(undefined2 *)(puVar441 + -4) = *(undefined2 *)(iVar404 + -0x14);
            *(undefined2 *)(puVar441 + -6) = *(undefined2 *)(iVar404 + -0xc);
            *(char **)(puVar441 + -8) = (char *)"puppetmaker" + 3;
            *(char **)(puVar441 + -10) = (char *)"%d (%d)";
            *(undefined2 *)(puVar441 + -0xc) = unaff_SS;
            *(int *)(puVar441 + -0xe) = iVar404 + -0xb8;
            *(char **)(puVar441 + -0x10) = pcVar495;
            pcVar495 = (char *)"glassworks" + 9;
            puVar446 = puVar441 + -0x12;
            *(undefined2 *)(puVar441 + -0x12) = 0xfb37;
            pcVar508 = ovr_stsprintf(*(char **)(puVar441 + -0xe),*(char **)(puVar441 + -10),
                                     *(char **)(puVar441 + -6));
            *(int *)(puVar446 + 0xe) = (int)((ulong)pcVar508 >> 0x10);
            *(char **)(puVar446 + 0xc) = (char *)pcVar508;
            *(char **)(puVar446 + 10) = (char *)"glassworks" + 9;
            puVar447 = puVar446 + 8;
            *(undefined2 *)(puVar446 + 8) = 0xfb40;
            manage_4d05_04c6();
            puVar427 = puVar447 + 10;
          }
        }
        TextBlitY = TextBlitY + 0xc;
      }
    }
    CurSfxType3 = 0x3c;
    *(undefined2 *)(puVar427 + -2) = unaff_SS;
    *(int *)(puVar427 + -4) = iVar404 + -0x18;
    *(undefined2 *)(puVar427 + -6) = 0;
    *(undefined2 *)(puVar427 + -8) = 0;
    *(undefined2 *)(puVar427 + -10) = 0x23;
    *(undefined2 *)(puVar427 + -0xc) = unaff_SS;
    *(int *)(puVar427 + -0xe) = iVar404 + -0x144;
    *(char **)(puVar427 + -0x10) = pcVar495;
    puVar448 = puVar427 + -0x12;
    *(undefined2 *)(puVar427 + -0x12) = 0xfbc6;
    uVar17 = ovr_OVC28_6018_1398();
    *(undefined1 *)(iVar404 + -0x17) = uVar17;
    DAT_2410_5cf0 = 0;
    if (((*(char *)(iVar404 + -0x17) != '\0') && (*(char *)(iVar404 + -0x17) != '\x01')) &&
       (*(char *)(iVar404 + -0x17) != -2)) {
      pfVar24 = (far_t *)manage_4d05_277a();
      return pfVar24;
    }
    pfVar24 = (far_t *)(uint)DAT_2410_26a8;
    if ((pfVar24 == (far_t *)0x0) && (*(char *)(iVar404 + -0x17) != -2)) {
      *(char **)(puVar448 + 0x10) = (char *)"halfling outpost" + 4;
      *(undefined2 *)(puVar448 + 0xe) = 0xfc05;
      pfVar24 = (far_t *)manage_4d05_0081();
    }
    if (*(char *)(iVar404 + -0x17) == -2) {
      DAT_2410_4926 = 1;
    }
    return pfVar24;
  case 0x15:
    uVar23 = (pfVar37 + 3)->ofs;
code_r0x0004baee:
    *(undefined2 *)(iVar404 + -8) = (char *)((int)&pfVar25->ofs + (uint)(0xffeb < uVar23));
    *(int *)(iVar404 + -10) = uVar23 + 0x14;
stshStoreFile_case5:
    uVar23 = StshCount;
    if (0xd92 < StshCount) {
      *(undefined2 *)((int)puVar97 + 0xe) = 0x24;
                    /* WARNING: Subroutine does not return */
      *(undefined2 *)((int)puVar97 + 0xc) = 0x4000;
      *(undefined2 *)((int)puVar97 + 10) = 0xbb41;
      ovr_stExit(*(int *)((int)puVar97 + 0xe));
    }
    StshCount = StshCount + 1;
    *(undefined2 *)((int)puVar97 + 0xe) = 0x4000;
    puVar253 = (uint16_t *)((int)puVar97 + 0xc);
    *(undefined2 *)((int)puVar97 + 0xc) = 0xbb18;
    lVar502 = LXMUL_at_(0x15,(ulong)uVar23);
    puVar253[1] = (int)lVar502;
    *puVar253 = (int)((ulong)lVar502 >> 0x10);
    uVar11 = StshCtPtr.seg;
    uVar10 = StshCtPtr.ofs;
    uVar23 = *puVar253;
    uVar492 = puVar253[1];
    puVar253[1] = 0x1000;
    *puVar253 = 0xbb28;
    ptr_base.seg = uVar11;
    ptr_base.ofs = uVar10;
    ptr_ofs.seg = uVar23;
    ptr_ofs.ofs = uVar492;
    fVar503 = PADD_at_(ptr_base,ptr_ofs);
    *puVar253 = fVar503.seg;
    puVar253[-1] = fVar503.ofs;
    puVar253[-2] = 0x1000;
    pcVar495 = (char *)"arrowsmith" + 3;
    puVar254 = puVar253 + -3;
    puVar253[-3] = 0xbb2f;
    uVar504 = ovr_mkp(puVar253[-1],*puVar253);
    puVar255 = (undefined2 *)((int)puVar254 + 8);
    puVar257 = (undefined1 *)((int)puVar254 + 8);
    *(undefined2 *)(iVar404 + -4) = (int)(uVar504 >> 0x10);
    *(undefined2 *)(iVar404 + -6) = (int)uVar504;
    uVar493 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
    iVar488 = (int)*(undefined4 *)(iVar404 + -6);
    uVar20 = *(undefined2 *)(iVar404 + -10);
    *(undefined2 *)(iVar488 + 7) = *(undefined2 *)(iVar404 + -8);
    *(undefined2 *)(iVar488 + 5) = uVar20;
    *(undefined1 *)*(undefined4 *)(iVar404 + -6) = 0;
    uVar23 = StshCtOfs.lo;
    uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
    iVar488 = (int)*(undefined4 *)(iVar404 + -6);
    *(uint16_t *)(iVar488 + 3) = StshCtOfs.hi;
    *(uint16_t *)(iVar488 + 1) = uVar23;
    uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
    iVar488 = (int)*(undefined4 *)(iVar404 + -6);
    *(undefined2 *)(iVar488 + 0x13) = 0;
    *(undefined2 *)(iVar488 + 0x11) = 0;
    bVar499 = CARRY2(StshCtOfs.lo,*(uint *)(iVar404 + -10));
    StshCtOfs.lo = StshCtOfs.lo + *(uint *)(iVar404 + -10);
    StshCtOfs.hi = StshCtOfs.hi + *(int *)(iVar404 + -8) + (uint)bVar499;
    uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
    iVar488 = (int)*(undefined4 *)(iVar404 + -6);
    *(undefined2 *)(iVar488 + 0xb) = 0;
    *(undefined2 *)(iVar488 + 9) = 0;
    uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
    iVar488 = (int)*(undefined4 *)(iVar404 + -6);
    *(undefined2 *)(iVar488 + 0xf) = 0;
    *(undefined2 *)(iVar488 + 0xd) = 0;
    if (DebugVerbose != false) {
code_r0x0004bbbc:
      *(undefined2 *)((int)puVar255 + -2) = *(undefined2 *)(iVar404 + -8);
      *(undefined2 *)((int)puVar255 + -4) = *(undefined2 *)(iVar404 + -10);
      *(uint *)((int)puVar255 + -6) = (uint)*(byte *)*(undefined4 *)(iVar404 + 4);
      *(undefined2 *)((int)puVar255 + -8) = (char *)"puppetmaker" + 3;
      *(undefined2 *)((int)puVar255 + -10) = (char *)"type %d len %ld \r";
      *(undefined2 *)((int)puVar255 + -0xc) = pcVar495;
      puVar256 = (undefined1 *)((int)puVar255 + -0xe);
      *(undefined2 *)((int)puVar255 + -0xe) = 0xbbd4;
      printf((char *)*(undefined4 *)((int)puVar255 + -10),*(undefined2 *)((int)puVar255 + -6));
      *(undefined2 *)(puVar256 + 0xc) = 0x1000;
      puVar258 = puVar256 + 10;
      *(undefined2 *)(puVar256 + 10) = 0xbbdc;
      ovr_biosReadKey();
      puVar257 = puVar258 + 4;
    }
    *(undefined2 *)(puVar257 + -2) = *(undefined2 *)(iVar404 + -8);
    *(undefined2 *)(puVar257 + -4) = *(undefined2 *)(iVar404 + -10);
    *(undefined2 *)(puVar257 + -6) = *(undefined2 *)(iVar404 + 6);
    *(undefined2 *)(puVar257 + -8) = *(undefined2 *)(iVar404 + 4);
    *(undefined2 *)(puVar257 + -10) = StshFile;
    *(char **)(puVar257 + -0xc) = (char *)"arrowsmith" + 3;
    puVar259 = puVar257 + -0xe;
    *(undefined2 *)(puVar257 + -0xe) = 0xbbf0;
    stshWriteFile(*(int *)(puVar257 + -10),*(far_t *)(puVar257 + -8),*(DW *)(puVar257 + -4));
    *(undefined2 *)(puVar259 + 0xc) = *(undefined2 *)(iVar404 + 6);
    *(undefined2 *)(puVar259 + 10) = *(undefined2 *)(iVar404 + 4);
    *(char **)(puVar259 + 8) = (char *)"arrowsmith" + 3;
    *(undefined2 *)(puVar259 + 6) = 0xbbfe;
    ovr_stshFree(*(far_t *)(puVar259 + 10));
    return (far_t *)*(undefined2 *)(iVar404 + -6);
  case 0x19:
  case 0x86:
    while ((*(char *)&GMenuItem = *(char *)&GMenuItem + '\x01',
           (int)(uint)GMenuItem <= *(int *)(iVar404 + -8) &&
           (piVar22 = (int *)((uint)GMenuItem * 4 + iVar404 + -0x2c),
           *piVar22 == 0 && piVar22[1] == 0))) {
      pfVar25 = (far_t *)((char *)"puppetmaker" + 3);
    }
    if (*(int *)(iVar404 + -8) < (int)(uint)GMenuItem) {
      GMenuItem = 0;
    }
    *(undefined2 *)((int)puVar97 + 0xe) = 0x4000;
    puVar152 = (undefined2 *)((int)puVar97 + 0xc);
    *(undefined2 *)((int)puVar97 + 0xc) = 0x5ab0;
    saveui_4528_01b2();
    puVar152[1] = 0x4000;
    pcVar495 = (char *)"builder\'s hall" + 3;
    *puVar152 = 0x5ab5;
    ovr_OVC40_69c8_047f();
    GMenuFlag = 1;
    puVar114 = (uint16_t *)((int)puVar152 + 4);
LAB_4528_0840:
    do {
      while( true ) {
        *(undefined2 *)((int)puVar114 + -2) = pcVar495;
        puVar153 = (uint16_t *)((int)puVar114 + -4);
        *(undefined2 *)((int)puVar114 + -4) = 0x5ac4;
        pcVar21 = (char *)uiReadKey2();
        puVar168 = puVar153 + 2;
        puVar114 = puVar153 + 2;
        if (pcVar21 != (char *)"Reroll ability scores, or select the character\'s class." + 0x2b)
        break;
LAB_4528_0903:
        do {
          GMenuItem = GMenuItem + 1;
          if (*(int *)(iVar404 + -8) < (int)(uint)GMenuItem) {
            GMenuItem = 0;
          }
        } while ((GMenuItem != 0) &&
                (piVar22 = (int *)((uint)GMenuItem * 4 + iVar404 + -0x2c),
                *piVar22 == 0 && piVar22[1] == 0));
        puVar153[1] = (uint16_t)pcVar495;
        *puVar153 = (uint16_t)((char *)"%s takes half damage from spells." + 0x18);
        saveui_4528_01b2();
        puVar114 = (uint16_t *)((int)puVar153 + 4);
      }
      if ((char *)"Reroll ability scores, or select the character\'s class." + 0x2c <= pcVar21) {
        if (pcVar21 != (char *)"%s will no longer build houses automatically." + 0xc) {
          if ((char *)"%s will no longer build houses automatically." + 0xd <= pcVar21) {
            if (pcVar21 == (char *)0xfffe) {
              GMenuFlag = 0;
              return (far_t *)0x0;
            }
            if (pcVar21 == (char *)0xffff) {
              puVar153[1] = 0;
              *puVar153 = *(undefined2 *)(iVar404 + -8);
              puVar153[-1] = unaff_SS;
              puVar153[-2] = iVar404 + -0x28;
              puVar153[-3] = (uint16_t)pcVar495;
              puVar166 = puVar153 + -4;
              puVar153[-4] = (uint16_t)
                             ((char *)"Resume. Game events will now occur normally." + 0x28);
              uVar17 = saveui_4528_0404();
              puVar168 = (uint16_t *)((int)puVar166 + 0xc);
              puVar114 = (uint16_t *)((int)puVar166 + 0xc);
              *(undefined1 *)(iVar404 + -3) = uVar17;
              if (*(char *)(iVar404 + -3) != -1) {
                pfVar25 = (far_t *)((char *)"puppetmaker" + 3);
code_r0x00045dbc:
                *(undefined1 *)&GMenuItem = *(undefined1 *)(iVar404 + -3);
LAB_4528_0b46:
                if (GMenuItem != 0) {
                  *(undefined2 *)((int)puVar168 + -2) = 0;
                  *(int *)((int)puVar168 + -4) = GMenuItem - 1;
                  *(undefined2 *)((int)puVar168 + -6) = unaff_SS;
                  *(int *)((int)puVar168 + -8) = iVar404 + -0x28;
                  *(undefined2 *)((int)puVar168 + -10) = pcVar495;
                  puVar167 = (undefined1 *)((int)puVar168 + -0xc);
                  *(undefined2 *)((int)puVar168 + -0xc) = 0x5deb;
                  saveui_4528_02fb();
                  puVar168 = (uint16_t *)(puVar167 + 0xc);
                }
                if ((pfVar489 <= (far_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4)
                    ) || (GMenuItem != 8)) {
LAB_4528_0c4d:
                  if (GMenuItem == 0) {
                    pfVar24 = (far_t *)0x0;
                  }
                  else {
                    pfVar24 = (far_t *)CONCAT11(0x24,GMenuItem + *(char *)(iVar404 + -6));
                  }
                    /* WARNING: Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
                  GMenuFlag = 0;
                  return pfVar24;
                }
                if (*(int *)(iVar404 + -6) + 7 < (int)pfVar489) {
                  *(int *)(iVar404 + -6) = *(int *)(iVar404 + -6) + 7;
                }
                else {
                  *(undefined2 *)(iVar404 + -6) = 0;
                }
                *(undefined2 *)((int)puVar168 + -2) = 0;
                *(undefined2 *)((int)puVar168 + -4) = 0x1c;
                *(undefined2 *)((int)puVar168 + -6) = unaff_SS;
                *(int *)((int)puVar168 + -8) = iVar404 + -0x28;
                *(undefined2 *)((int)puVar168 + -10) = pcVar495;
                pcVar495 = (char *)0x1000;
                puVar169 = (undefined1 *)((int)puVar168 + -0xc);
                *(undefined2 *)((int)puVar168 + -0xc) =
                     (char *)"Next wave of enemies appear." + 0x1a;
                _fsetmem((void *)*(undefined4 *)((int)puVar168 + -8),
                         *(uint16_t *)((int)puVar168 + -4),*(uint16_t *)((int)puVar168 + -2));
                *(undefined1 *)(iVar404 + -4) = 0;
                while ((*(byte *)(iVar404 + -4) < 7 &&
                       ((int)((uint)*(byte *)(iVar404 + -4) + *(int *)(iVar404 + -6)) <
                        (int)pfVar489))) {
                  uVar493 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 8) >> 0x10);
                  puVar36 = (undefined2 *)
                            ((int)*(undefined4 *)(iVar404 + 8) +
                            ((uint)*(byte *)(iVar404 + -4) + *(int *)(iVar404 + -6)) * 4);
                  uVar20 = *puVar36;
                  puVar32 = (undefined2 *)((uint)*(byte *)(iVar404 + -4) * 4 + iVar404 + -0x28);
                  puVar32[1] = puVar36[1];
                  *puVar32 = uVar20;
                  *(char *)(iVar404 + -4) = *(char *)(iVar404 + -4) + '\x01';
                }
                *(undefined2 *)(puVar169 + 10) = 0x1000;
                puVar170 = (uint16_t *)(puVar169 + 8);
                *(char **)(puVar169 + 8) = (char *)"strong.sav" + 10;
                saveui_4528_0533();
                puVar172 = puVar170 + 2;
                if (*(int *)(iVar404 + 4) != 0 || *(int *)(iVar404 + 6) != 0) {
                  TextBlitX = 0x16;
                  TextBlitY = 0xb;
                  puVar170[1] = 7;
                  *puVar170 = 0xde;
                  puVar170[-1] = Font03.seg;
                  puVar170[-2] = Font03.ofs;
                  puVar170[-3] = *(undefined2 *)(iVar404 + 6);
                  puVar170[-4] = *(undefined2 *)(iVar404 + 4);
                  puVar170[-5] = 0x1000;
                  pcVar495 = (char *)"steam bath" + 6;
                  puVar171 = puVar170 + -6;
                  puVar170[-6] = (uint16_t)((char *)"Path to write game data:\n" + 0x12);
                  ovr_blitText(*(char **)(puVar170 + -4),(byte *)puVar170[-2],*puVar170,
                               (uint8_t)puVar170[1]);
                  puVar172 = (uint16_t *)((int)puVar171 + 0x10);
                }
                *(undefined2 *)((int)puVar172 + -2) = 8;
                *(undefined2 *)((int)puVar172 + -4) = unaff_SS;
                *(int *)((int)puVar172 + -6) = iVar404 + -0x28;
                *(undefined2 *)((int)puVar172 + -8) = pcVar495;
                puVar173 = (undefined1 *)((int)puVar172 + -10);
                *(undefined2 *)((int)puVar172 + -10) =
                     (char *)"ENTER: use previous configuration, SPACE: reconfigure, ESC: quit" + 6;
                saveui_4528_0664();
                *(char **)(puVar173 + 8) = pcVar495;
                puVar174 = puVar173 + 6;
                *(char **)(puVar173 + 6) =
                     (char *)"ENTER: use previous configuration, SPACE: reconfigure, ESC: quit" +
                     0xd;
                saveui_4528_01b2();
                puVar114 = (uint16_t *)(puVar174 + 4);
              }
            }
            goto LAB_4528_0840;
          }
          if (pcVar21 == (char *)"Please type your character\'s name. Esc go back." + 8)
          goto LAB_4528_0903;
          puVar114 = puVar153 + 2;
          if (pcVar21 != (char *)"%s will now build homes automatically.") goto LAB_4528_0840;
        }
        puVar114 = puVar153 + 2;
        if ((far_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) < pfVar489) {
          if (*(int *)(iVar404 + -6) + 7 < (int)pfVar489) {
            *(int *)(iVar404 + -6) = *(int *)(iVar404 + -6) + 7;
          }
          else {
            *(undefined2 *)(iVar404 + -6) = 0;
          }
          puVar153[1] = 0;
          *puVar153 = 0x1c;
          puVar153[-1] = unaff_SS;
          puVar153[-2] = iVar404 + -0x28;
          puVar153[-3] = (uint16_t)pcVar495;
          pcVar495 = (char *)0x1000;
          puVar160 = puVar153 + -4;
          puVar153[-4] = 0x5cea;
          _fsetmem(*(void **)(puVar153 + -2),*puVar153,puVar153[1]);
          *(undefined1 *)(iVar404 + -4) = 0;
          while ((*(byte *)(iVar404 + -4) < 7 &&
                 ((int)((uint)*(byte *)(iVar404 + -4) + *(int *)(iVar404 + -6)) < (int)pfVar489))) {
            uVar493 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 8) >> 0x10);
            puVar36 = (undefined2 *)
                      ((int)*(undefined4 *)(iVar404 + 8) +
                      ((uint)*(byte *)(iVar404 + -4) + *(int *)(iVar404 + -6)) * 4);
            uVar20 = *puVar36;
            puVar32 = (undefined2 *)((uint)*(byte *)(iVar404 + -4) * 4 + iVar404 + -0x28);
            puVar32[1] = puVar36[1];
            *puVar32 = uVar20;
            *(char *)(iVar404 + -4) = *(char *)(iVar404 + -4) + '\x01';
          }
          *(undefined2 *)((int)puVar160 + 10) = 0x1000;
          puVar161 = (uint16_t *)((int)puVar160 + 8);
          *(undefined2 *)((int)puVar160 + 8) =
               (char *)
               "Pause. Select \'Resume\' to enable game events. Press SPACE for a single game event."
               + 8;
          saveui_4528_0533();
          puVar163 = puVar161 + 2;
          if (*(int *)(iVar404 + 4) != 0 || *(int *)(iVar404 + 6) != 0) {
            TextBlitX = 0x16;
            TextBlitY = 0xb;
            puVar161[1] = 7;
            *puVar161 = 0xde;
            puVar161[-1] = Font03.seg;
            puVar161[-2] = Font03.ofs;
            puVar161[-3] = *(undefined2 *)(iVar404 + 6);
            puVar161[-4] = *(undefined2 *)(iVar404 + 4);
            puVar161[-5] = 0x1000;
            pcVar495 = (char *)"steam bath" + 6;
            puVar162 = puVar161 + -6;
            puVar161[-6] = (uint16_t)
                           ((char *)
                            "Pause. Select \'Resume\' to enable game events. Press SPACE for a single game event."
                           + 0x47);
            ovr_blitText(*(char **)(puVar161 + -4),(byte *)puVar161[-2],*puVar161,
                         (uint8_t)puVar161[1]);
            puVar163 = (uint16_t *)((int)puVar162 + 0x10);
          }
          *(undefined2 *)((int)puVar163 + -2) = 8;
          *(undefined2 *)((int)puVar163 + -4) = unaff_SS;
          *(int *)((int)puVar163 + -6) = iVar404 + -0x28;
          *(undefined2 *)((int)puVar163 + -8) = pcVar495;
          puVar164 = (undefined1 *)((int)puVar163 + -10);
          *(undefined2 *)((int)puVar163 + -10) =
               (char *)"Resume. Game events will now occur normally." + 2;
          saveui_4528_0664();
          GMenuItem = 8;
          *(char **)(puVar164 + 8) = pcVar495;
          puVar165 = puVar164 + 6;
          *(char **)(puVar164 + 6) = (char *)"Resume. Game events will now occur normally." + 0x14;
          saveui_4528_01b2();
          puVar114 = (uint16_t *)(puVar165 + 4);
        }
        goto LAB_4528_0840;
      }
      if (pcVar21 == (char *)"dc%lx %d ln %ld lc %ld @%lx \r" + 0xf) {
LAB_4528_08ad:
        do {
          GMenuItem = GMenuItem - 1;
          if (GMenuItem == 0xff) {
            GMenuItem = *(byte *)(iVar404 + -8);
          }
        } while ((GMenuItem != 0) &&
                (piVar22 = (int *)((uint)GMenuItem * 4 + iVar404 + -0x2c),
                *piVar22 == 0 && piVar22[1] == 0));
        puVar153[1] = (uint16_t)pcVar495;
        *puVar153 = (uint16_t)((char *)"disintegrate" + 3);
        saveui_4528_01b2();
        puVar114 = (uint16_t *)((int)puVar153 + 4);
      }
      else if ((char *)"dc%lx %d ln %ld lc %ld @%lx \r" + 0xf < pcVar21) {
        if (((pcVar21 == (char *)"pasopl.adv" + 7) ||
            (puVar114 = puVar153 + 2, pcVar21 == (char *)0x4939)) &&
           (puVar114 = puVar153 + 2,
           (far_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) < pfVar489)) {
          if (*(int *)(iVar404 + -6) == 0) {
            *(int *)(iVar404 + -6) = ((iVar488 + 1U) / 7) * 7;
          }
          else {
            *(int *)(iVar404 + -6) = *(int *)(iVar404 + -6) + -7;
          }
          puVar153[1] = 0;
          *puVar153 = 0x1c;
          puVar153[-1] = unaff_SS;
          puVar153[-2] = iVar404 + -0x28;
          puVar153[-3] = (uint16_t)pcVar495;
          pcVar495 = (char *)0x1000;
          puVar154 = puVar153 + -4;
          puVar153[-4] = (uint16_t)((char *)"%s takes half damage from lightning." + 3);
          _fsetmem(*(void **)(puVar153 + -2),*puVar153,puVar153[1]);
          *(undefined1 *)(iVar404 + -4) = 0;
          while ((*(byte *)(iVar404 + -4) < 7 &&
                 ((int)((uint)*(byte *)(iVar404 + -4) + *(int *)(iVar404 + -6)) < (int)pfVar489))) {
            uVar493 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 8) >> 0x10);
            puVar36 = (undefined2 *)
                      ((int)*(undefined4 *)(iVar404 + 8) +
                      ((uint)*(byte *)(iVar404 + -4) + *(int *)(iVar404 + -6)) * 4);
            uVar20 = *puVar36;
            puVar32 = (undefined2 *)((uint)*(byte *)(iVar404 + -4) * 4 + iVar404 + -0x28);
            puVar32[1] = puVar36[1];
            *puVar32 = uVar20;
            *(char *)(iVar404 + -4) = *(char *)(iVar404 + -4) + '\x01';
          }
          *(undefined2 *)((int)puVar154 + 10) = 0x1000;
          puVar155 = (uint16_t *)((int)puVar154 + 8);
          *(undefined2 *)((int)puVar154 + 8) = (char *)"%s is immune to fire.";
          saveui_4528_0533();
          puVar157 = puVar155 + 2;
          if (*(int *)(iVar404 + 4) != 0 || *(int *)(iVar404 + 6) != 0) {
            TextBlitX = 0x16;
            TextBlitY = 0xb;
            puVar155[1] = 7;
            *puVar155 = 0xde;
            puVar155[-1] = Font03.seg;
            puVar155[-2] = Font03.ofs;
            puVar155[-3] = *(undefined2 *)(iVar404 + 6);
            puVar155[-4] = *(undefined2 *)(iVar404 + 4);
            puVar155[-5] = 0x1000;
            pcVar495 = (char *)"steam bath" + 6;
            puVar156 = puVar155 + -6;
            puVar155[-6] = (uint16_t)((char *)"%s is held by %s." + 9);
            ovr_blitText(*(char **)(puVar155 + -4),(byte *)puVar155[-2],*puVar155,
                         (uint8_t)puVar155[1]);
            puVar157 = (uint16_t *)((int)puVar156 + 0x10);
          }
          *(undefined2 *)((int)puVar157 + -2) = 8;
          *(undefined2 *)((int)puVar157 + -4) = unaff_SS;
          *(int *)((int)puVar157 + -6) = iVar404 + -0x28;
          *(undefined2 *)((int)puVar157 + -8) = pcVar495;
          puVar158 = (undefined1 *)((int)puVar157 + -10);
          *(undefined2 *)((int)puVar157 + -10) = (char *)"%s is put to sleep by %s." + 5;
          saveui_4528_0664();
          GMenuItem = 8;
          *(char **)(puVar158 + 8) = pcVar495;
          puVar159 = puVar158 + 6;
          *(char **)(puVar158 + 6) = (char *)"%s is put to sleep by %s." + 0x17;
          saveui_4528_01b2();
          puVar114 = (uint16_t *)(puVar159 + 4);
        }
      }
      else {
        if (pcVar21 == (char *)0x11b) {
          GMenuFlag = 0;
          return (far_t *)0x0;
        }
        if (pcVar21 == (char *)"%s: provides housing and income." + 8) goto LAB_4528_0b46;
        puVar114 = puVar153 + 2;
        if (pcVar21 == (char *)0x4800) goto LAB_4528_08ad;
      }
    } while( true );
  case 0x1a:
  case 0x87:
  case 0xe5:
  case 0xe8:
    goto LAB_474a_148a;
  case 0x1b:
    while( true ) {
      *(char **)((char *)((int)pfVar37 + iVar404 + -0x92) + 2) = (char *)"puppetmaker" + 3;
      *(char **)(char *)((int)pfVar37 + iVar404 + -0x92) = (char *)"Reroll";
      pcVar21 = (char *)((int)&pfVar489->ofs + 1);
      pcVar21[iVar404 + -0x9e] = '\0';
      puVar36 = (undefined2 *)((int)pcVar21 * 4 + iVar404 + -0x92);
      puVar36[1] = 0;
      *puVar36 = 0;
      puVar114 = &pfVar489->seg;
      *(undefined2 *)(iVar404 + -0x12) = 0;
      while (*(int *)(iVar404 + -0x12) < 4) {
        *(char *)((int)puVar114 + iVar404 + -0x9e) = *(char *)(iVar404 + -0x12) + '\x02';
        uVar20 = *(undefined2 *)(*(int *)(iVar404 + -0x12) * 4 + 0xeb);
        puVar36 = (undefined2 *)((int)puVar114 * 4 + iVar404 + -0x92);
        puVar36[1] = *(undefined2 *)(*(int *)(iVar404 + -0x12) * 4 + 0xed);
        *puVar36 = uVar20;
        puVar114 = (uint16_t *)((int)puVar114 + 1);
        *(int *)(iVar404 + -0x12) = *(int *)(iVar404 + -0x12) + 1;
      }
      *(undefined1 *)((int)puVar114 + iVar404 + -0x9e) = 6;
      uVar23 = GUnitDescriptions[4].ofs;
      if (*(byte *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x2d) < 9) {
        puVar36 = (undefined2 *)((int)puVar114 * 4 + iVar404 + -0x92);
        puVar36[1] = 0;
        *puVar36 = 0;
      }
      else {
        puVar35 = (uint16_t *)((int)puVar114 * 4 + iVar404 + -0x92);
        puVar35[1] = GUnitDescriptions[4].seg;
        *puVar35 = uVar23;
      }
      puVar485 = (undefined1 *)((int)puVar114 + 1);
      puVar485[iVar404 + -0x9e] = 7;
      uVar23 = GUnitDescriptions[5].ofs;
      if (*(byte *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x2a) < 9) {
        puVar36 = (undefined2 *)((int)puVar485 * 4 + iVar404 + -0x92);
        puVar36[1] = 0;
        *puVar36 = 0;
      }
      else {
        puVar35 = (uint16_t *)((int)puVar485 * 4 + iVar404 + -0x92);
        puVar35[1] = GUnitDescriptions[5].seg;
        *puVar35 = uVar23;
      }
      iVar488 = (int)(puVar114 + 1);
      *(undefined1 *)(iVar488 + iVar404 + -0x9e) = 8;
      uVar23 = GUnitDescriptions[6].ofs;
      if ((*(byte *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x2d) < 9) ||
         (*(byte *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x2c) < 9)) {
        puVar36 = (undefined2 *)(iVar488 * 4 + iVar404 + -0x92);
        puVar36[1] = 0;
        *puVar36 = 0;
      }
      else {
        puVar114 = (uint16_t *)(iVar488 * 4 + iVar404 + -0x92);
        puVar114[1] = GUnitDescriptions[6].seg;
        *puVar114 = uVar23;
      }
      *(undefined2 *)((int)puVar365 + -2) = (char *)"puppetmaker" + 3;
      *(undefined2 *)((int)puVar365 + -4) =
           (char *)"Reroll ability scores, or select the character\'s class.";
      *(undefined2 *)((int)puVar365 + -6) = pcVar495;
      puVar366 = (undefined2 *)((int)puVar365 + -8);
      *(undefined2 *)((int)puVar365 + -8) = 0xe4f2;
      ovr_drawString();
      puVar366[3] = 0;
      puVar366[2] = 0;
      puVar366[1] = 0;
      *puVar366 = 9;
      puVar366[-1] = unaff_SS;
      puVar366[-2] = iVar404 + -0x92;
      puVar366[-3] = (char *)"money dealer\'s shop" + 0xe;
      pcVar495 = (char *)"halfling outpost" + 4;
      puVar367 = puVar366 + -4;
      puVar366[-4] = 0xe508;
      bVar19 = ovr_uiInputText();
      puVar361 = (undefined1 *)((int)puVar367 + 0x10);
      puVar389 = (undefined4 *)((int)puVar367 + 0x10);
      *(uint *)(iVar404 + -0x10) = (uint)bVar19;
      if (*(int *)(iVar404 + -0x10) != 0) {
        *(int *)(iVar404 + -0x10) = (int)*(char *)(*(int *)(iVar404 + -0x10) + iVar404 + -0x9f);
      }
      if (*(int *)(iVar404 + -0x10) == 0) break;
      if (*(int *)(iVar404 + -0x10) == 1) {
        TimerSeed.hi = 0;
        TimerSeed.lo = 0;
      }
      if (*(int *)(iVar404 + -0x10) != 1) {
        *(int *)(iVar404 + -0x10) = *(int *)(iVar404 + -0x10) + -1;
        if (DAT_2000_d19d < 2) {
          pbVar1 = (byte *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x5d);
          *pbVar1 = *pbVar1 | 4;
        }
        else {
          pbVar1 = (byte *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x5d);
          *pbVar1 = *pbVar1 | 6;
        }
        *(char *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x2f) = *(char *)(iVar404 + -0x10) + -1;
        *(undefined2 *)((int)puVar367 + 0xe) =
             CONCAT11(0x24,*(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x2f));
        *(undefined2 *)((int)puVar367 + 0xc) = (char *)"halfling outpost" + 4;
        puVar368 = (undefined2 *)((int)puVar367 + 10);
        *(undefined2 *)((int)puVar367 + 10) = 0xe584;
        uVar17 = chargen_switch(*(uint16_t *)((int)puVar367 + 0xe));
        *(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x3e) = uVar17;
        *(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x30) = 6;
        iVar488 = (uint)*(byte *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x2f) * 0x94 +
                  (uint)*(byte *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x30) * 4;
        pcVar21 = (char *)*(undefined2 *)(iVar488 + -4);
        uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -0x16) >> 0x10);
        iVar490 = (int)*(undefined4 *)(iVar404 + -0x16);
        *(undefined2 *)(iVar490 + 0x37) = *(undefined2 *)(iVar488 + -2);
        *(undefined2 *)(iVar490 + 0x35) = pcVar21;
        pbVar1 = (byte *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x28);
        *pbVar1 = *pbVar1 | 8;
        pbVar1 = (byte *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x28);
        *pbVar1 = *pbVar1 | 1;
        if (DAT_2000_d19d == 1) {
          uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -0x16) >> 0x10);
          iVar488 = (int)*(undefined4 *)(iVar404 + -0x16);
          *(undefined2 *)(iVar488 + 0x58) = 0;
          *(undefined2 *)(iVar488 + 0x56) = 500;
        }
        else if (DAT_2000_d19d == 2) {
          uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -0x16) >> 0x10);
          iVar488 = (int)*(undefined4 *)(iVar404 + -0x16);
          *(undefined2 *)(iVar488 + 0x58) = 0;
          *(undefined2 *)(iVar488 + 0x56) = 300;
        }
        else {
          uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -0x16) >> 0x10);
          iVar488 = (int)*(undefined4 *)(iVar404 + -0x16);
          *(undefined2 *)(iVar488 + 0x58) = 0;
          *(undefined2 *)(iVar488 + 0x56) = 100;
        }
        *(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x85) = 7;
        *(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x89) = 0xff;
        puVar368[2] = *(undefined2 *)(iVar404 + -0x14);
        puVar368[1] = *(undefined2 *)(iVar404 + -0x16);
        *puVar368 = (char *)"halfling outpost" + 4;
        puVar369 = (undefined4 *)(puVar368 + -1);
        puVar368[-1] = 0xe642;
        manage_4d05_056e();
        *(undefined2 *)((int)puVar369 + 6) = *(undefined2 *)(iVar404 + -0x14);
        *(undefined2 *)((int)puVar369 + 4) = *(undefined2 *)(iVar404 + -0x16);
        *(undefined2 *)((int)puVar369 + 2) = (char *)"halfling outpost" + 4;
        *(undefined2 *)puVar369 = 0xe64f;
        cVar18 = abilitiesDlg();
        puVar389 = puVar369 + 2;
        if (cVar18 != '\0') {
          *(undefined2 *)((int)puVar369 + 6) = *(undefined2 *)(iVar404 + -0x14);
          *(undefined2 *)(puVar369 + 1) = *(undefined2 *)(iVar404 + -0x16);
          *(undefined2 *)((int)puVar369 + 2) = (char *)"halfling outpost" + 4;
          *(undefined2 *)puVar369 = 59000;
          manage_4d05_11cb();
          puVar370 = (undefined1 *)((int)puVar369 + 8);
          while( true ) {
            *(undefined2 *)(puVar370 + -2) = *(undefined2 *)(iVar404 + -0x14);
            *(undefined2 *)(puVar370 + -4) = *(undefined2 *)(iVar404 + -0x16);
            *(char **)(puVar370 + -6) = pcVar495;
            puVar369 = (undefined4 *)(puVar370 + -8);
            *(undefined2 *)(puVar370 + -8) = 0xe685;
            manage_4d05_056e();
            *(undefined2 *)((int)puVar369 + 6) = *(undefined2 *)(iVar404 + -0x14);
            *(undefined2 *)((int)puVar369 + 4) = *(undefined2 *)(iVar404 + -0x16);
            *(undefined2 *)((int)puVar369 + 2) = pcVar495;
            *(undefined2 *)puVar369 = 0xe692;
            cVar18 = alignmentDlg();
            puVar371 = puVar369 + 2;
            puVar389 = puVar369 + 2;
            if (cVar18 == '\0') break;
LAB_4d05_1661:
            *(undefined2 *)((int)puVar371 + -2) = pcVar495;
            puVar372 = (undefined2 *)((int)puVar371 + -4);
            *(undefined2 *)((int)puVar371 + -4) = 0xe6b5;
            manage_4d05_0081();
            puVar372[1] = *(undefined2 *)(iVar404 + -0x14);
            *puVar372 = *(undefined2 *)(iVar404 + -0x16);
            puVar372[-1] = pcVar495;
            puVar373 = puVar372 + -2;
            puVar372[-2] = 0xe6bf;
            manage_4d05_056e();
            puVar373[3] = *(undefined2 *)(iVar404 + -0x14);
            puVar373[2] = *(undefined2 *)(iVar404 + -0x16);
            puVar373[1] = pcVar495;
            *puVar373 = 0xe6cc;
            cVar18 = uiPickGender();
            puVar370 = (undefined1 *)((int)puVar373 + 8);
            puVar374 = (undefined1 *)((int)puVar373 + 8);
            puVar389 = (undefined4 *)((int)puVar373 + 8);
            if (cVar18 != '\0') {
              do {
                *(char **)(puVar374 + -2) = pcVar495;
                puVar375 = (undefined2 *)(puVar374 + -4);
                *(undefined2 *)(puVar374 + -4) = 0xe6eb;
                manage_4d05_0166();
                puVar375[1] = (char *)"puppetmaker" + 3;
                *puVar375 = (char *)"Select the character\'s name.";
                puVar375[-1] = pcVar495;
                puVar376 = puVar375 + -2;
                puVar375[-2] = 0xe6f4;
                ovr_drawString();
                puVar377 = (undefined1 *)((int)puVar376 + 8);
                while( true ) {
                  *(undefined2 *)(puVar377 + -2) = 0;
                  *(undefined2 *)(puVar377 + -4) = 0;
                  *(undefined2 *)(puVar377 + -6) = 6;
                  *(undefined2 *)(puVar377 + -8) = 0;
                  *(undefined2 *)(puVar377 + -10) = 0;
                  *(char **)(puVar377 + -0xc) = (char *)"money dealer\'s shop" + 0xe;
                  pcVar495 = (char *)"glassworks";
                  puVar378 = puVar377 + -0xe;
                  *(undefined2 *)(puVar377 + -0xe) = 0xe706;
                  uVar20 = ovr_uiReadString();
                  puVar371 = (undefined4 *)(puVar378 + 0xe);
                  puVar389 = (undefined4 *)(puVar378 + 0xe);
                  *(undefined2 *)(iVar404 + -0xc) = pcVar21;
                  *(undefined2 *)(iVar404 + -0xe) = uVar20;
                  if (*(int *)(iVar404 + -0xe) != 0 || *(int *)(iVar404 + -0xc) != 0) break;
                  if (DAT_2000_d19c != '\0') {
                    if (UserWantsExit != '\0') goto LAB_4d05_17b2;
                    goto LAB_4d05_1661;
                  }
                  *(char **)(puVar378 + 0xc) = (char *)"glassworks";
                  puVar379 = (undefined2 *)(puVar378 + 10);
                  *(undefined2 *)(puVar378 + 10) = 0xe73b;
                  manage_4d05_0166();
                  puVar379[1] = (char *)"puppetmaker" + 3;
                  *puVar379 = (char *)"Please type your character\'s name. Esc go back.";
                  puVar379[-1] = (char *)"glassworks";
                  puVar380 = puVar379 + -2;
                  puVar379[-2] = 0xe744;
                  ovr_drawString();
                  puVar377 = (undefined1 *)((int)puVar380 + 8);
                }
                *(char **)(puVar378 + 0xc) = (char *)"puppetmaker" + 3;
                *(char **)(puVar378 + 10) = (char *)"Lawful" + 6;
                *(char **)(puVar378 + 8) = (char *)"glassworks";
                puVar381 = (undefined2 *)(puVar378 + 6);
                *(undefined2 *)(puVar378 + 6) = 0xe752;
                ovr_drawString();
                puVar381[3] = 0x27;
                puVar381[2] = *(undefined2 *)(iVar404 + -0xc);
                puVar381[1] = *(undefined2 *)(iVar404 + -0xe);
                *puVar381 = *(undefined2 *)(iVar404 + -0x14);
                puVar381[-1] = *(undefined2 *)(iVar404 + -0x16);
                puVar381[-2] = (char *)"money dealer\'s shop" + 0xe;
                puVar382 = puVar381 + -3;
                puVar381[-3] = 0xe768;
                __fstrncpy();
                *(undefined2 *)((int)puVar382 + 0xc) = *(undefined2 *)(iVar404 + -0xc);
                *(undefined2 *)((int)puVar382 + 10) = *(undefined2 *)(iVar404 + -0xe);
                *(undefined2 *)((int)puVar382 + 8) = 0x1000;
                puVar383 = (undefined4 *)((int)puVar382 + 6);
                *(undefined2 *)((int)puVar382 + 6) = 0xe776;
                ovr_stshFree(*(far_t *)((int)puVar382 + 10));
                *(undefined2 *)((int)puVar383 + 6) = *(undefined2 *)(iVar404 + -0x14);
                *(undefined2 *)(puVar383 + 1) = *(undefined2 *)(iVar404 + -0x16);
                *(undefined2 *)((int)puVar383 + 2) = (char *)"puppetmaker" + 3;
                *(char **)puVar383 = (char *)"Keep %s.";
                *(undefined2 *)((int)puVar383 + -2) = unaff_SS;
                *(int *)(puVar383 + -1) = iVar404 + -0x66;
                *(undefined2 *)((int)puVar383 + -6) = (char *)"glassworks" + 9;
                puVar384 = puVar383 + -2;
                *(undefined2 *)(puVar383 + -2) = 0xe78d;
                pcVar508 = ovr_stsprintf(*(char **)(puVar383 + -1),(char *)*puVar383,
                                         *(char **)(puVar383 + 1));
                pcVar21 = (char *)((ulong)pcVar508 >> 0x10);
                *(undefined2 *)((int)puVar384 + 0xe) = pcVar21;
                *(undefined2 *)((int)puVar384 + 0xc) = (char *)pcVar508;
                *(undefined2 *)((int)puVar384 + 10) = (char *)"glassworks" + 9;
                pcVar495 = (char *)"money dealer\'s shop" + 0xe;
                puVar386 = (undefined1 *)((int)puVar384 + 8);
                *(undefined2 *)((int)puVar384 + 8) = 0xe797;
                ovr_drawString();
                puVar385 = (undefined2 *)(puVar386 + 4);
code_r0x0004e797:
                puVar385[1] = 0;
                *puVar385 = 0;
                puVar385[-1] = 0;
                puVar385[-2] = 2;
                puVar385[-3] = unaff_SS;
                puVar385[-4] = iVar404 + -10;
                puVar385[-5] = pcVar495;
                pcVar495 = (char *)"halfling outpost" + 4;
                puVar387 = puVar385 + -6;
                puVar385[-6] = 0xe7ac;
                bVar19 = ovr_uiInputText();
                puVar374 = (undefined1 *)((int)puVar387 + 0x10);
                puVar389 = (undefined4 *)((int)puVar387 + 0x10);
                *(uint *)(iVar404 + -0x10) = (uint)bVar19;
                if (*(int *)(iVar404 + -0x10) != 0) {
                  puVar389 = (undefined4 *)((int)puVar387 + 0x10);
                  if (*(int *)(iVar404 + -0x10) != 2) {
                    pbVar1 = (byte *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x28);
                    *pbVar1 = *pbVar1 | 2;
                    *(undefined2 *)((int)puVar387 + 0xe) = (char *)"halfling outpost" + 4;
                    puVar388 = (undefined2 *)((int)puVar387 + 0xc);
                    *(undefined2 *)((int)puVar387 + 0xc) = 0xe7e1;
                    manage_4d05_0081();
                    puVar388[1] = *(undefined2 *)(iVar404 + -0x14);
                    *puVar388 = *(undefined2 *)(iVar404 + -0x16);
                    puVar388[-1] = (char *)"halfling outpost" + 4;
                    puVar388[-2] = 0xe7eb;
                    manage_4d05_056e();
                    TimerSeed.lo = 0;
                    TimerSeed.hi = 0;
                    return (far_t *)*(undefined2 *)(iVar404 + -0x16);
                  }
                  break;
                }
              } while (UserWantsExit == '\0');
              goto LAB_4d05_17b2;
            }
            if (UserWantsExit != '\0') goto LAB_4d05_17b2;
          }
        }
        if (UserWantsExit != '\0') break;
        *(undefined2 *)((int)puVar369 + 6) = 0xae;
        *(undefined2 *)(puVar369 + 1) = 0;
        *(undefined2 *)((int)puVar369 + 2) = *(undefined2 *)(iVar404 + -0x14);
        *(undefined2 *)puVar369 = *(undefined2 *)(iVar404 + -0x16);
        *(undefined2 *)((int)puVar369 + -2) = pcVar495;
        pcVar495 = (char *)0x1000;
        puVar360 = puVar369 + -1;
        *(undefined2 *)(puVar369 + -1) = 0xe331;
        _fmemset((void *)*puVar369,*(uint16_t *)(puVar369 + 1),*(uint16_t *)((int)puVar369 + 6));
        puVar361 = (undefined1 *)((int)puVar360 + 0xc);
        *(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x16) + 0x51) = 0xff;
      }
      if (TimerSeed.lo == 0 && TimerSeed.hi == 0) {
        TimerSeed.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
        TimerSeed.lo = *(uint16_t *)BDA_DailyTimeCounter;
      }
      *(uint16_t *)(puVar361 + -2) = TimerSeed.hi;
      *(uint16_t *)(puVar361 + -4) = TimerSeed.lo;
      *(char **)(puVar361 + -6) = pcVar495;
      pcVar495 = (char *)0x1000;
      puVar362 = puVar361 + -8;
      *(undefined2 *)(puVar361 + -8) = 0xe36a;
      srand8(*(uint32_t *)(puVar361 + -4));
      *(undefined2 *)(puVar362 + 6) = 0x1000;
      puVar363 = (undefined2 *)(puVar362 + 4);
      *(undefined2 *)(puVar362 + 4) = 0xe371;
      manage_4d05_0081();
      puVar363[1] = *(undefined2 *)(iVar404 + -0x14);
      *puVar363 = *(undefined2 *)(iVar404 + -0x16);
      puVar363[-1] = 0x1000;
      puVar364 = puVar363 + -2;
      puVar363[-2] = 0xe37b;
      manage_4d05_01d4();
      puVar364[3] = *(undefined2 *)(iVar404 + -0x14);
      puVar364[2] = *(undefined2 *)(iVar404 + -0x16);
      puVar364[1] = 0x1000;
      *puVar364 = 0xe388;
      manage_4d05_056e();
      puVar365 = (undefined2 *)((int)puVar364 + 8);
      pfVar489 = (far_t *)0x0;
      *(undefined1 *)(iVar404 + -0x9e) = 1;
      pfVar37 = (far_t *)0x0;
    }
    goto LAB_4d05_17b2;
  case 0x1f:
    do {
      pfVar37->ofs = (uint16_t)pcVar21;
      puVar456 = puVar457;
      while( true ) {
        puVar114 = &pfVar24->ofs;
        pfVar489 = (far_t *)((int)&pfVar489->ofs + 1);
LAB_4d05_2ee8:
        pfVar24 = (far_t *)((int)puVar114 + 1);
        if ((int)(uint)*(byte *)(iVar404 + -0xb) <= (int)pfVar489) {
          *(undefined1 *)(iVar404 + -0xd) = 2;
          *(undefined2 *)((int)puVar456 + -2) = 0x4000;
          puVar458 = (undefined2 *)((int)puVar456 + -4);
          *(undefined2 *)((int)puVar456 + -4) = 0xff4c;
          manage_4d05_0081();
          puVar36 = puVar458 + 2;
          puVar459 = puVar458 + 2;
          *(undefined1 *)(iVar404 + -0xe) = 0;
          if (*(char *)(iVar404 + -0xd) != '\x02') goto LAB_3f0b_11ea;
          if (DAT_2410_26a8 == 0) {
            puVar458[1] = 0x4000;
            *puVar458 = 0xff6c;
            manage_4d05_0081();
            puVar459 = (undefined2 *)((int)puVar458 + 4);
          }
          TextBlitY = 0xc;
          TextBlitX = 0x11;
          if (*(char *)(iVar404 + 4) != -1) {
            pcVar21 = (char *)*(undefined2 *)((uint)*(byte *)(iVar404 + 4) * 4);
            *(undefined2 *)(iVar404 + -0x10) = ((undefined2 *)((uint)*(byte *)(iVar404 + 4) * 4))[1]
            ;
            *(undefined2 *)(iVar404 + -0x12) = pcVar21;
            *(undefined2 *)((int)puVar459 + -2) = 0x50;
            *(undefined2 *)((int)puVar459 + -4) = 0xde;
            *(uint16_t *)((int)puVar459 + -6) = Font02.seg;
            *(uint16_t *)((int)puVar459 + -8) = Font02.ofs;
            *(undefined2 *)((int)puVar459 + -10) = 3;
            *(undefined2 *)((int)puVar459 + -0xc) = 0x4b;
            *(uint16_t *)((int)puVar459 + -0xe) = Font02.seg;
            *(uint16_t *)((int)puVar459 + -0x10) = Font02.ofs;
            *(undefined2 *)((int)puVar459 + -0x12) = *(undefined2 *)(iVar404 + -0x10);
            *(undefined2 *)((int)puVar459 + -0x14) = *(undefined2 *)(iVar404 + -0x12);
            puVar461 = (undefined2 *)((int)puVar459 + -0x16);
            *(undefined2 *)((int)puVar459 + -0x16) = unaff_SS;
            pfVar25 = (far_t *)(iVar404 + -0x1b6);
            goto code_r0x0004fffe;
          }
          *(undefined2 *)((int)puVar459 + -2) = 0x50;
          *(undefined2 *)((int)puVar459 + -4) = 0xde;
          *(uint16_t *)((int)puVar459 + -6) = Font02.seg;
          *(uint16_t *)((int)puVar459 + -8) = Font02.ofs;
          *(undefined2 *)((int)puVar459 + -10) = (char *)"puppetmaker" + 3;
          *(undefined2 *)((int)puVar459 + -0xc) = (char *)"Total population.";
          *(undefined2 *)((int)puVar459 + -0xe) = 0x4000;
          pcVar495 = (char *)"steam bath" + 6;
          puVar460 = (undefined1 *)((int)puVar459 + -0x10);
          *(undefined2 *)((int)puVar459 + -0x10) = 0xffa7;
          ovr_blitLabel((char *)*(undefined4 *)((int)puVar459 + -0xc),
                        (uint8_t *)*(undefined4 *)((int)puVar459 + -8),
                        *(int16_t *)((int)puVar459 + -4),*(uint8_t *)((int)puVar459 + -2));
          puVar43 = puVar460 + 0x10;
          *(char *)&pfVar489->ofs =
               (char)pfVar489->ofs + extraout_AH_00 + ((undefined1 *)0xfff3 < puVar460 + 4);
          goto LAB_3f0b_0f99;
        }
        if (((int)pfVar489 < 5) || (*(char *)(iVar404 + -0xc) == '\0')) break;
        pcVar494 = (char *)((ulong)*(undefined4 *)((uint)*(byte *)(iVar404 + 4) << 2) >> 0x10);
        iVar488 = (uint)*(byte *)((int)*(undefined4 *)((uint)*(byte *)(iVar404 + 4) << 2) + 0x2f) *
                  0x10 + (int)pfVar489 * 4 + iVar404 + -0x106;
        uVar23 = *(uint16_t *)((code *)init_3381_08dc + iVar488);
        in_CX = (uint16_t *)(iVar404 + -0x66);
        pfVar37 = (far_t *)(in_CX + (int)pfVar24 * 2);
        pfVar37->seg = *(uint16_t *)(iVar488 + -0x12);
        pfVar37->ofs = uVar23;
      }
      puVar36 = (undefined2 *)((int)pfVar489 * 4 + iVar404 + -0x96);
      pfVar25 = (far_t *)puVar36[1];
      pcVar21 = (char *)*puVar36;
      pfVar37 = (far_t *)((int)pfVar24 * 4);
      puVar457 = puVar456;
code_r0x0004ff2a:
      in_CX = (uint16_t *)(iVar404 + -0x66);
      pfVar37 = (far_t *)((int)pfVar37 + (int)in_CX);
      pfVar37->seg = (uint16_t)pfVar25;
    } while( true );
  case 0x20:
    *(undefined2 *)((int)puVar97 + 0xe) = pfVar25;
    *(undefined2 *)((int)puVar97 + 0xc) = (char *)"puppetmaker" + 3;
    *(undefined2 *)((int)puVar97 + 10) = (char *)"%s%s, ";
    *(undefined2 *)((int)puVar97 + 8) = unaff_SS;
    *(int *)((int)puVar97 + 6) = iVar404 + -0xf6;
    *(undefined2 *)((int)puVar97 + 4) = 0x4000;
    puVar284 = (undefined2 *)((int)puVar97 + 2);
    *(undefined2 *)((int)puVar97 + 2) = 0xd6f9;
    pcVar508 = ovr_stsprintf((char *)*(undefined2 *)((int)puVar97 + 6),
                             (char *)*(undefined4 *)((int)puVar97 + 10),
                             (char *)*(undefined2 *)((int)puVar97 + 0xe));
    uVar20 = (undefined2)((ulong)pcVar508 >> 0x10);
    *(undefined2 *)((int)puVar284 + 0x12) = uVar20;
    *(undefined2 *)((int)puVar284 + 0x10) = (char *)pcVar508;
    *(undefined2 *)((int)puVar284 + 0xe) = (char *)"glassworks" + 9;
    puVar285 = (undefined2 *)((int)puVar284 + 0xc);
    *(undefined2 *)((int)puVar284 + 0xc) = 0xd703;
    ovr_blitLabel((char *)*(undefined4 *)((int)puVar284 + 0x10),
                  (uint8_t *)*(undefined4 *)((int)puVar284 + 0x14),
                  *(int16_t *)((int)puVar284 + 0x18),*(uint8_t *)((int)puVar284 + 0x1a));
    puVar291 = puVar285 + 8;
    if ((*(byte *)(iVar404 + -6) & 4) != 0) {
      puVar285[7] = 0x50;
      puVar285[6] = 0xde;
      puVar285[5] = Font02.seg;
      puVar285[4] = Font02.ofs;
      uVar487 = (uint)*(byte *)((int)*(undefined4 *)(iVar404 + 4) + 0x33);
      puVar285[3] = *(undefined2 *)((int)&GAlignmentsNames[0].seg + uVar487 * 4);
      puVar285[2] = ((far_t *)GAlignmentsNames + uVar487)->ofs;
      puVar285[1] = (char *)"puppetmaker" + 3;
      *puVar285 = (char *)"%s ";
      puVar285[-1] = (char *)"steam bath" + 6;
      puVar286 = puVar285 + -2;
      puVar285[-2] = 0xd73f;
      pcVar495 = ovr_fmVsprintf((char *)*puVar285,(char *)puVar285[2]);
      *(undefined2 *)((int)puVar286 + 10) = uVar20;
      *(undefined2 *)((int)puVar286 + 8) = pcVar495;
      *(undefined2 *)((int)puVar286 + 6) = (char *)"glassworks" + 9;
      puVar287 = (undefined1 *)((int)puVar286 + 4);
      *(undefined2 *)((int)puVar286 + 4) = 0xd749;
      ovr_blitLabel((char *)*(undefined4 *)((int)puVar286 + 8),
                    (uint8_t *)*(undefined4 *)((int)puVar286 + 0xc),
                    *(int16_t *)((int)puVar286 + 0x10),*(uint8_t *)((int)puVar286 + 0x12));
      puVar291 = (undefined2 *)(puVar287 + 0x10);
    }
    if ((*(byte *)(iVar404 + -6) & 1) != 0) {
      *(undefined2 *)((int)puVar291 + -2) = 0x50;
      *(undefined2 *)((int)puVar291 + -4) = 0xde;
      *(uint16_t *)((int)puVar291 + -6) = Font02.seg;
      *(uint16_t *)((int)puVar291 + -8) = Font02.ofs;
      iVar488 = (uint)*(byte *)((int)*(undefined4 *)(iVar404 + 4) + 0x2f) * 4;
      pcVar21 = (char *)"puppetmaker" + 3;
      *(undefined2 *)((int)puVar291 + -10) = *(undefined2 *)(iVar488 + 0xed);
      *(undefined2 *)((int)puVar291 + -0xc) = *(undefined2 *)(iVar488 + 0xeb);
      *(undefined2 *)((int)puVar291 + -0xe) = (char *)"puppetmaker" + 3;
      *(undefined2 *)((int)puVar291 + -0x10) = (char *)"%s";
      *(undefined2 *)((int)puVar291 + -0x12) = (char *)"steam bath" + 6;
      pcVar495 = (char *)"glassworks" + 9;
      puVar288 = (undefined1 *)((int)puVar291 + -0x14);
      *(undefined2 *)((int)puVar291 + -0x14) = 0xd78c;
      pfVar25 = (far_t *)ovr_fmVsprintf((char *)*(undefined2 *)((int)puVar291 + -0x10),
                                        (char *)*(undefined2 *)((int)puVar291 + -0xc));
      puVar289 = (undefined4 *)(puVar288 + 0xc);
      goto code_r0x0004d78b;
    }
    goto LAB_4d05_0749;
  case 0x21:
    *(byte *)&pfVar24->ofs = bVar19;
    *(undefined2 *)((int)puVar97 + 0xe) = DAT_2000_d1a8;
    *(undefined2 *)((int)puVar97 + 0xc) = 0x4000;
    *(undefined2 *)((int)puVar97 + 10) = 0x8b0c;
    pfVar24 = (far_t *)ovr_blitLoadRleGfx(*(far_t *)((int)puVar97 + 0xe),
                                          *(far_t *)((int)puVar97 + 0x12));
    return pfVar24;
  case 0x22:
  case 0x32:
  case 0x3d:
  case 0x49:
switchD_4000_f055_caseD_3:
    *(byte *)(&pfVar24[-0x16f].seg + (int)pfVar25) =
         (char)(&pfVar24[-0x16f].seg)[(int)pfVar25] + bVar15;
    *(undefined2 *)(iVar404 + -10) = pcVar21;
    goto stshStoreFile_case5;
  case 0x24:
  case 0x34:
  case 0x3f:
  case 0x4b:
switchD_4000_f055_caseD_5:
    pcVar495 = "";
    if (bVar19 == 0) goto code_r0x0004eafb;
code_r0x0004eaed:
    *(undefined2 *)((int)pfVar392 + -2) = *(undefined2 *)(iVar404 + -0x12);
    *(undefined2 *)((int)pfVar392 + -4) = pcVar495;
    puVar394 = (undefined1 *)((int)pfVar392 + -6);
    *(undefined2 *)((int)pfVar392 + -6) = 0xeaf5;
    manage_4d05_056e();
    pfVar395 = (far_t *)(puVar394 + 8);
    goto LAB_4d05_1aa8;
  case 0x25:
  case 0x4c:
  case 0x5d:
  case 0x7f:
code_r0x0004d78b:
    uVar487 = *(uint *)((int)&pfVar24[0x230].seg + iVar404);
    *(undefined2 *)((int)puVar289 + -2) = pcVar21;
    *(uint *)(puVar289 + -1) = (uint)pfVar25 & uVar487;
    *(undefined2 *)((int)puVar289 + -6) = pcVar495;
    puVar290 = puVar289 + -2;
    *(undefined2 *)(puVar289 + -2) = 0xd796;
    ovr_blitLabel((char *)puVar289[-1],(uint8_t *)*puVar289,*(int16_t *)(puVar289 + 1),
                  *(uint8_t *)((int)puVar289 + 6));
    puVar291 = (undefined2 *)((int)puVar290 + 0x10);
LAB_4d05_0749:
    TextBlitY = TextBlitY + 10;
    if (((*(byte *)(iVar404 + -6) & 0x40) != 0) ||
       (pfVar24 = (far_t *)((char *)"puppetmaker" + 3), DebugVerbose != false)) {
      TextBlitX = 0x37;
      *(undefined2 *)((int)puVar291 + -2) = 0xe0;
      *(undefined2 *)((int)puVar291 + -4) = 0xde;
      *(uint16_t *)((int)puVar291 + -6) = Font02.seg;
      *(uint16_t *)((int)puVar291 + -8) = Font02.ofs;
      *(undefined2 *)((int)puVar291 + -10) = (char *)"puppetmaker" + 3;
      *(undefined2 *)((int)puVar291 + -0xc) = (char *)"Population";
      *(undefined2 *)((int)puVar291 + -0xe) = (char *)"steam bath" + 6;
      puVar292 = (undefined2 *)((int)puVar291 + -0x10);
      *(undefined2 *)((int)puVar291 + -0x10) = 0xd7e4;
      ovr_blitLabel((char *)*(undefined4 *)((int)puVar291 + -0xc),
                    (uint8_t *)*(undefined4 *)((int)puVar291 + -8),*(int16_t *)((int)puVar291 + -4),
                    *(uint8_t *)((int)puVar291 + -2));
      puVar292[7] = 0x7d;
      puVar292[6] = *(undefined2 *)((int)*(undefined4 *)(iVar404 + 4) + 0x4d);
      puVar292[5] = (char *)"puppetmaker" + 3;
      puVar292[4] = (char *)"%d";
      puVar292[3] = unaff_SS;
      puVar292[2] = iVar404 + -0x7e;
      puVar292[1] = (char *)"steam bath" + 6;
      *puVar292 = 0xd7fe;
      pcVar508 = ovr_stsprintf((char *)puVar292[2],*(char **)(puVar292 + 4),(char *)puVar292[6]);
      pcVar21 = (char *)((ulong)pcVar508 >> 0x10);
      *(undefined2 *)((int)puVar292 + 0xc) = pcVar21;
      *(undefined2 *)((int)puVar292 + 10) = (char *)pcVar508;
      *(undefined2 *)((int)puVar292 + 8) = (char *)"glassworks" + 9;
      puVar293 = (undefined1 *)((int)puVar292 + 6);
      *(undefined2 *)((int)puVar292 + 6) = 0xd807;
      manage_4d05_04c6();
      TextBlitX = 0x82;
      *(uint *)(puVar293 + 8) =
           CONCAT11(0x24,*(undefined1 *)((int)*(undefined4 *)(iVar404 + 4) + 0x51));
      *(char **)(puVar293 + 6) = (char *)"glassworks" + 9;
      puVar294 = (uint16_t *)(puVar293 + 4);
      *(undefined2 *)(puVar293 + 4) = 0xd823;
      ovr_OVC22_5087_056e();
      puVar294[2] = 0xe0;
      puVar294[1] = 0xde;
      *puVar294 = Font02.seg;
      puVar294[-1] = Font02.ofs;
      puVar294[-2] = (uint16_t)((char *)"puppetmaker" + 3);
      puVar294[-3] = (uint16_t)(char *)"Food prod.";
      puVar294[-4] = (uint16_t)((char *)"cleric outpost" + 0xd);
      pcVar495 = (char *)"steam bath" + 6;
      puVar295 = puVar294 + -5;
      puVar294[-5] = 0xd844;
      ovr_blitLabel(*(char **)(puVar294 + -3),*(uint8_t **)(puVar294 + -1),puVar294[1],
                    (uint8_t)puVar294[2]);
      *(undefined2 *)((int)puVar295 + 0xe) = 0xdc;
      uVar509 = *(undefined4 *)(iVar404 + 4);
      *(undefined2 *)((int)puVar295 + 0xc) = 0;
      *(undefined2 *)((int)puVar295 + 10) = *(undefined2 *)((int)uVar509 + 0x4f);
      *(undefined2 *)((int)puVar295 + 8) = unaff_SS;
      *(int *)((int)puVar295 + 6) = iVar404 + -0xf6;
      *(undefined2 *)((int)puVar295 + 4) = (char *)"steam bath" + 6;
      puVar296 = (undefined1 *)((int)puVar295 + 2);
      *(undefined2 *)((int)puVar295 + 2) = 0xd85e;
      pcVar494 = litoa10((char *)*(undefined2 *)((int)puVar295 + 6),*(long *)((int)puVar295 + 10));
      *(char **)(puVar296 + 10) = pcVar21;
      *(char **)(puVar296 + 8) = pcVar494;
      *(char **)(puVar296 + 6) = (char *)"steam bath" + 6;
      puVar297 = (undefined2 *)(puVar296 + 4);
      *(undefined2 *)(puVar296 + 4) = 0xd867;
      manage_4d05_04c6();
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x82;
      puVar297[4] = 0xe0;
      puVar297[3] = 0xde;
      puVar297[2] = Font02.seg;
      puVar297[1] = Font02.ofs;
      *puVar297 = (char *)"puppetmaker" + 3;
      puVar298 = (undefined4 *)(puVar297 + -1);
      puVar297[-1] = (char *)"Food stored";
code_r0x0004d89a:
      *(undefined2 *)((int)puVar298 + -2) = pcVar495;
      puVar299 = puVar298 + -1;
      *(undefined2 *)(puVar298 + -1) = 0xd89f;
      ovr_blitLabel((char *)*puVar298,(uint8_t *)puVar298[1],*(int16_t *)(puVar298 + 2),
                    *(uint8_t *)((int)puVar298 + 10));
      *(undefined2 *)((int)puVar299 + 0xe) = 0xdc;
      uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
      iVar488 = (int)*(undefined4 *)(iVar404 + 4);
      *(undefined2 *)((int)puVar299 + 0xc) = *(undefined2 *)(iVar488 + 0x62);
      *(undefined2 *)((int)puVar299 + 10) = *(undefined2 *)(iVar488 + 0x60);
      *(undefined2 *)((int)puVar299 + 8) = unaff_SS;
      *(int *)((int)puVar299 + 6) = iVar404 + -0xf6;
      *(undefined2 *)((int)puVar299 + 4) = (char *)"steam bath" + 6;
      puVar300 = (undefined1 *)((int)puVar299 + 2);
      *(undefined2 *)((int)puVar299 + 2) = 0xd8bb;
      pcVar495 = litoa10((char *)*(undefined2 *)((int)puVar299 + 6),*(long *)((int)puVar299 + 10));
      *(char **)(puVar300 + 10) = pcVar21;
      *(char **)(puVar300 + 8) = pcVar495;
      *(char **)(puVar300 + 6) = (char *)"steam bath" + 6;
      puVar301 = (undefined2 *)(puVar300 + 4);
      *(undefined2 *)(puVar300 + 4) = 0xd8c4;
      manage_4d05_04c6();
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x37;
      puVar301[4] = 0xe0;
      puVar301[3] = 0xde;
      puVar301[2] = Font02.seg;
      puVar301[1] = Font02.ofs;
      *puVar301 = (char *)"puppetmaker" + 3;
      puVar301[-1] = (char *)"Housing";
      puVar301[-2] = (char *)"steam bath" + 6;
      puVar302 = puVar301 + -3;
      puVar301[-3] = 0xd8fc;
      ovr_blitLabel(*(char **)(puVar301 + -1),*(uint8_t **)(puVar301 + 1),puVar301[3],
                    *(uint8_t *)(puVar301 + 4));
      puVar302[7] = 0x7d;
      puVar302[6] = *(undefined2 *)((int)*(undefined4 *)(iVar404 + 4) + 0x5b);
      puVar302[5] = (char *)"puppetmaker" + 3;
      puVar302[4] = (char *)"%d";
      puVar302[3] = unaff_SS;
      puVar302[2] = iVar404 + -0x7e;
      puVar302[1] = (char *)"steam bath" + 6;
      *puVar302 = 0xd916;
      pcVar508 = ovr_stsprintf((char *)puVar302[2],*(char **)(puVar302 + 4),(char *)puVar302[6]);
      uVar20 = (undefined2)((ulong)pcVar508 >> 0x10);
      *(undefined2 *)((int)puVar302 + 0xc) = uVar20;
      *(undefined2 *)((int)puVar302 + 10) = (char *)pcVar508;
      *(undefined2 *)((int)puVar302 + 8) = (char *)"glassworks" + 9;
      puVar303 = (undefined2 *)((int)puVar302 + 6);
      *(undefined2 *)((int)puVar302 + 6) = 0xd91f;
      manage_4d05_04c6();
      TextBlitX = 0x82;
      puVar303[4] = 0xe0;
      puVar303[3] = 0xde;
      puVar303[2] = Font02.seg;
      puVar303[1] = Font02.ofs;
      *puVar303 = (char *)"puppetmaker" + 3;
      puVar303[-1] = (char *)"Food storage";
      puVar303[-2] = (char *)"glassworks" + 9;
      pcVar495 = (char *)"steam bath" + 6;
      puVar304 = puVar303 + -3;
      puVar303[-3] = 0xd94c;
      ovr_blitLabel(*(char **)(puVar303 + -1),*(uint8_t **)(puVar303 + 1),puVar303[3],
                    *(uint8_t *)(puVar303 + 4));
      *(undefined2 *)((int)puVar304 + 0xe) = 0xdc;
      uVar493 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
      iVar488 = (int)*(undefined4 *)(iVar404 + 4);
      *(undefined2 *)((int)puVar304 + 0xc) = *(undefined2 *)(iVar488 + 0x80);
      *(undefined2 *)((int)puVar304 + 10) = *(undefined2 *)(iVar488 + 0x7e);
      *(undefined2 *)((int)puVar304 + 8) = unaff_SS;
      *(int *)((int)puVar304 + 6) = iVar404 + -0xf6;
      *(undefined2 *)((int)puVar304 + 4) = (char *)"steam bath" + 6;
      puVar305 = (undefined1 *)((int)puVar304 + 2);
      *(undefined2 *)((int)puVar304 + 2) = 0xd969;
      pcVar21 = litoa10((char *)*(undefined2 *)((int)puVar304 + 6),*(long *)((int)puVar304 + 10));
      *(undefined2 *)(puVar305 + 10) = uVar20;
      *(char **)(puVar305 + 8) = pcVar21;
      *(char **)(puVar305 + 6) = (char *)"steam bath" + 6;
      puVar306 = puVar305 + 4;
      *(undefined2 *)(puVar305 + 4) = 0xd972;
      manage_4d05_04c6();
      puVar307 = (undefined2 *)(puVar306 + 10);
      puVar318 = puVar306 + 10;
      TextBlitY = TextBlitY + 0xf;
      if (*(int *)((int)*(undefined4 *)(iVar404 + 4) + 0xa0) != 0) {
LAB_4d05_093e:
        TextBlitX = 0x37;
        if (*(int *)((int)*(undefined4 *)(iVar404 + 4) + 0xa2) < 0) {
          *(undefined2 *)((int)puVar307 + -2) = 0xe0;
          *(undefined2 *)((int)puVar307 + -4) = 0xde;
          *(uint16_t *)((int)puVar307 + -6) = Font02.seg;
          *(uint16_t *)((int)puVar307 + -8) = Font02.ofs;
          *(undefined2 *)((int)puVar307 + -10) = (char *)"puppetmaker" + 3;
          *(undefined2 *)((int)puVar307 + -0xc) = (char *)"Food sold";
          *(undefined2 *)((int)puVar307 + -0xe) = pcVar495;
          puVar312 = (undefined1 *)((int)puVar307 + -0x10);
          *(undefined2 *)((int)puVar307 + -0x10) = 0xda0a;
          ovr_blitLabel((char *)*(undefined4 *)((int)puVar307 + -0xc),
                        (uint8_t *)*(undefined4 *)((int)puVar307 + -8),
                        *(int16_t *)((int)puVar307 + -4),*(uint8_t *)((int)puVar307 + -2));
          *(undefined2 *)(puVar312 + 0xe) = 0x7d;
          iVar488 = -*(int *)((int)*(undefined4 *)(iVar404 + 4) + 0xa2);
          iVar490 = iVar488 >> 0xf;
          *(int *)(puVar312 + 0xc) = iVar490;
          *(int *)(puVar312 + 10) = iVar488;
          *(undefined2 *)(puVar312 + 8) = unaff_SS;
          *(int *)(puVar312 + 6) = iVar404 + -0xf6;
          *(char **)(puVar312 + 4) = (char *)"steam bath" + 6;
          puVar313 = puVar312 + 2;
          *(undefined2 *)(puVar312 + 2) = 0xda27;
          pcVar495 = litoa10(*(char **)(puVar312 + 6),*(long *)(puVar312 + 10));
          *(int *)(puVar313 + 10) = iVar490;
          *(char **)(puVar313 + 8) = pcVar495;
          *(char **)(puVar313 + 6) = (char *)"steam bath" + 6;
          puVar314 = puVar313 + 4;
          *(undefined2 *)(puVar313 + 4) = 0xda30;
          manage_4d05_04c6();
          puVar311 = puVar314 + 10;
        }
        else {
          *(undefined2 *)((int)puVar307 + -2) = 0xe0;
          *(undefined2 *)((int)puVar307 + -4) = 0xde;
          *(uint16_t *)((int)puVar307 + -6) = Font02.seg;
          *(uint16_t *)((int)puVar307 + -8) = Font02.ofs;
          *(undefined2 *)((int)puVar307 + -10) = (char *)"puppetmaker" + 3;
          *(undefined2 *)((int)puVar307 + -0xc) = (char *)"Food bought";
          *(undefined2 *)((int)puVar307 + -0xe) = pcVar495;
          puVar308 = (undefined1 *)((int)puVar307 + -0x10);
          *(undefined2 *)((int)puVar307 + -0x10) = 0xd9c3;
          ovr_blitLabel((char *)*(undefined4 *)((int)puVar307 + -0xc),
                        (uint8_t *)*(undefined4 *)((int)puVar307 + -8),
                        *(int16_t *)((int)puVar307 + -4),*(uint8_t *)((int)puVar307 + -2));
          *(undefined2 *)(puVar308 + 0xe) = 0x7d;
          iVar488 = *(int *)((int)*(undefined4 *)(iVar404 + 4) + 0xa2);
          iVar490 = iVar488 >> 0xf;
          *(int *)(puVar308 + 0xc) = iVar490;
          *(int *)(puVar308 + 10) = iVar488;
          *(undefined2 *)(puVar308 + 8) = unaff_SS;
          *(int *)(puVar308 + 6) = iVar404 + -0xf6;
          *(char **)(puVar308 + 4) = (char *)"steam bath" + 6;
          puVar309 = puVar308 + 2;
          *(undefined2 *)(puVar308 + 2) = 0xd9de;
          pcVar495 = litoa10(*(char **)(puVar308 + 6),*(long *)(puVar308 + 10));
          *(int *)(puVar309 + 10) = iVar490;
          *(char **)(puVar309 + 8) = pcVar495;
          *(char **)(puVar309 + 6) = (char *)"steam bath" + 6;
          puVar310 = puVar309 + 4;
          *(undefined2 *)(puVar309 + 4) = 0xd9e7;
          manage_4d05_04c6();
          puVar311 = puVar310 + 10;
        }
        TextBlitX = 0x82;
        *(undefined2 *)(puVar311 + -2) = 0xe0;
        *(undefined2 *)(puVar311 + -4) = 0xde;
        *(uint16_t *)(puVar311 + -6) = Font02.seg;
        *(uint16_t *)(puVar311 + -8) = Font02.ofs;
        *(char **)(puVar311 + -10) = (char *)"puppetmaker" + 3;
        *(char **)(puVar311 + -0xc) = (char *)"Max. trade";
        *(char **)(puVar311 + -0xe) = (char *)"steam bath" + 6;
        puVar315 = puVar311 + -0x10;
        *(undefined2 *)(puVar311 + -0x10) = 0xda5d;
        ovr_blitLabel(*(char **)(puVar311 + -0xc),*(uint8_t **)(puVar311 + -8),
                      *(int16_t *)(puVar311 + -4),puVar311[-2]);
        *(undefined2 *)(puVar315 + 0xe) = 0xdc;
        uVar509 = *(undefined4 *)(iVar404 + 4);
        *(undefined2 *)(puVar315 + 0xc) = 0;
        *(undefined2 *)(puVar315 + 10) = *(undefined2 *)((int)uVar509 + 0xa0);
        *(undefined2 *)(puVar315 + 8) = unaff_SS;
        *(int *)(puVar315 + 6) = iVar404 + -0xf6;
        *(char **)(puVar315 + 4) = (char *)"steam bath" + 6;
        puVar316 = puVar315 + 2;
        *(undefined2 *)(puVar315 + 2) = 0xda78;
        pcVar495 = litoa10(*(char **)(puVar315 + 6),*(long *)(puVar315 + 10));
        *(int *)(puVar316 + 10) = iVar490;
        *(char **)(puVar316 + 8) = pcVar495;
        *(char **)(puVar316 + 6) = (char *)"steam bath" + 6;
        puVar317 = puVar316 + 4;
        *(undefined2 *)(puVar316 + 4) = 0xda81;
        manage_4d05_04c6();
        puVar318 = puVar317 + 10;
      }
      TextBlitY = TextBlitY + 0xf;
      TextBlitX = 0x37;
      *(undefined2 *)(puVar318 + -2) = 0xe0;
      *(undefined2 *)(puVar318 + -4) = 0xde;
      *(uint16_t *)(puVar318 + -6) = Font02.seg;
      *(uint16_t *)(puVar318 + -8) = Font02.ofs;
      *(char **)(puVar318 + -10) = (char *)"puppetmaker" + 3;
      *(char **)(puVar318 + -0xc) = (char *)"Income";
      *(char **)(puVar318 + -0xe) = (char *)"steam bath" + 6;
      puVar319 = puVar318 + -0x10;
      *(undefined2 *)(puVar318 + -0x10) = 0xdab9;
      ovr_blitLabel(*(char **)(puVar318 + -0xc),*(uint8_t **)(puVar318 + -8),
                    *(int16_t *)(puVar318 + -4),puVar318[-2]);
      *(undefined2 *)(puVar319 + 0xe) = 0xdc;
      iVar488 = *(int *)((int)*(undefined4 *)(iVar404 + 4) + 0x54);
      iVar490 = iVar488 >> 0xf;
      *(int *)(puVar319 + 0xc) = iVar490;
      *(int *)(puVar319 + 10) = iVar488;
      *(undefined2 *)(puVar319 + 8) = unaff_SS;
      *(int *)(puVar319 + 6) = iVar404 + -0x7e;
      *(char **)(puVar319 + 4) = (char *)"steam bath" + 6;
      puVar320 = puVar319 + 2;
      *(undefined2 *)(puVar319 + 2) = 0xdad3;
      pcVar495 = litoa10(*(char **)(puVar319 + 6),*(long *)(puVar319 + 10));
      *(int *)(puVar320 + 10) = iVar490;
      *(char **)(puVar320 + 8) = pcVar495;
      *(char **)(puVar320 + 6) = (char *)"steam bath" + 6;
      puVar321 = (undefined2 *)(puVar320 + 4);
      *(undefined2 *)(puVar320 + 4) = 0xdadc;
      manage_4d05_04c6();
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x37;
      puVar321[4] = 0xe0;
      puVar321[3] = 0xde;
      puVar321[2] = Font02.seg;
      puVar321[1] = Font02.ofs;
      *puVar321 = (char *)"puppetmaker" + 3;
      puVar321[-1] = (char *)"Gold";
      puVar321[-2] = (char *)"steam bath" + 6;
      puVar322 = puVar321 + -3;
      puVar321[-3] = 0xdb14;
      ovr_blitLabel(*(char **)(puVar321 + -1),*(uint8_t **)(puVar321 + 1),puVar321[3],
                    *(uint8_t *)(puVar321 + 4));
      *(undefined2 *)((int)puVar322 + 0xe) = 0xdc;
      uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
      iVar488 = (int)*(undefined4 *)(iVar404 + 4);
      *(undefined2 *)((int)puVar322 + 0xc) = *(undefined2 *)(iVar488 + 0x58);
      *(undefined2 *)((int)puVar322 + 10) = *(undefined2 *)(iVar488 + 0x56);
      *(undefined2 *)((int)puVar322 + 8) = unaff_SS;
      *(int *)((int)puVar322 + 6) = iVar404 + -0x7e;
      *(undefined2 *)((int)puVar322 + 4) = (char *)"steam bath" + 6;
      puVar323 = (undefined1 *)((int)puVar322 + 2);
      *(undefined2 *)((int)puVar322 + 2) = 0xdb2f;
      pcVar495 = litoa10((char *)*(undefined2 *)((int)puVar322 + 6),*(long *)((int)puVar322 + 10));
      *(int *)(puVar323 + 10) = iVar490;
      *(char **)(puVar323 + 8) = pcVar495;
      *(char **)(puVar323 + 6) = (char *)"steam bath" + 6;
      puVar324 = (undefined2 *)(puVar323 + 4);
      *(undefined2 *)(puVar323 + 4) = 0xdb38;
      manage_4d05_04c6();
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x37;
      puVar324[4] = 0xe0;
      puVar324[3] = 0xde;
      puVar324[2] = Font02.seg;
      puVar324[1] = Font02.ofs;
      *puVar324 = (char *)"puppetmaker" + 3;
      puVar324[-1] = (char *)"Vault storage";
      puVar324[-2] = (char *)"steam bath" + 6;
      puVar325 = puVar324 + -3;
      puVar324[-3] = 0xdb70;
      ovr_blitLabel(*(char **)(puVar324 + -1),*(uint8_t **)(puVar324 + 1),puVar324[3],
                    *(uint8_t *)(puVar324 + 4));
      *(undefined2 *)((int)puVar325 + 0xe) = 0xdc;
      uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
      iVar488 = (int)*(undefined4 *)(iVar404 + 4);
      *(undefined2 *)((int)puVar325 + 0xc) = *(undefined2 *)(iVar488 + 0x8c);
      *(undefined2 *)((int)puVar325 + 10) = *(undefined2 *)(iVar488 + 0x8a);
      *(undefined2 *)((int)puVar325 + 8) = unaff_SS;
      *(int *)((int)puVar325 + 6) = iVar404 + -0x7e;
      *(undefined2 *)((int)puVar325 + 4) = (char *)"steam bath" + 6;
      puVar326 = (undefined1 *)((int)puVar325 + 2);
      *(undefined2 *)((int)puVar325 + 2) = 0xdb8d;
      pcVar495 = litoa10((char *)*(undefined2 *)((int)puVar325 + 6),*(long *)((int)puVar325 + 10));
      *(int *)(puVar326 + 10) = iVar490;
      *(char **)(puVar326 + 8) = pcVar495;
      *(char **)(puVar326 + 6) = (char *)"steam bath" + 6;
      puVar327 = (undefined2 *)(puVar326 + 4);
      *(undefined2 *)(puVar326 + 4) = 0xdb96;
      manage_4d05_04c6();
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x37;
      puVar327[4] = 0xe0;
      puVar327[3] = 0xde;
      puVar327[2] = Font02.seg;
      puVar327[1] = Font02.ofs;
      *puVar327 = (char *)"puppetmaker" + 3;
      puVar327[-1] = (char *)"Fund Access";
      puVar327[-2] = (char *)"steam bath" + 6;
      puVar328 = puVar327 + -3;
      puVar327[-3] = 0xdbce;
      ovr_blitLabel(*(char **)(puVar327 + -1),*(uint8_t **)(puVar327 + 1),puVar327[3],
                    *(uint8_t *)(puVar327 + 4));
      *(undefined2 *)((int)puVar328 + 0xe) = 0xdc;
      *(undefined2 *)((int)puVar328 + 0xc) =
           CONCAT11(extraout_AH,*(undefined1 *)((int)*(undefined4 *)(iVar404 + 4) + 0x51));
      *(undefined2 *)((int)puVar328 + 10) = (char *)"steam bath" + 6;
      puVar329 = (undefined2 *)((int)puVar328 + 8);
      *(undefined2 *)((int)puVar328 + 8) = 0xdbe1;
      uVar20 = ovr_OVC45_77eb_0904();
      puVar329[2] = iVar490;
      puVar329[1] = uVar20;
      *puVar329 = unaff_SS;
      puVar329[-1] = iVar404 + -0xf6;
      puVar329[-2] = (char *)"trade faire" + 8;
      puVar330 = puVar329 + -3;
      puVar329[-3] = 0xdbf1;
      pcVar495 = litoa10((char *)puVar329[-1],*(long *)(puVar329 + 1));
      *(int *)((int)puVar330 + 10) = iVar490;
      *(undefined2 *)((int)puVar330 + 8) = pcVar495;
      *(undefined2 *)((int)puVar330 + 6) = (char *)"trade faire" + 8;
      puVar331 = (undefined2 *)((int)puVar330 + 4);
      *(undefined2 *)((int)puVar330 + 4) = 0xdbfa;
      manage_4d05_04c6();
      TextBlitY = TextBlitY + 10;
      TextBlitX = 0x37;
      puVar331[4] = 0xe0;
      puVar331[3] = 0xde;
      puVar331[2] = Font02.seg;
      puVar331[1] = Font02.ofs;
      *puVar331 = (char *)"puppetmaker" + 3;
      puVar331[-1] = (char *)"Common fund";
      puVar331[-2] = (char *)"trade faire" + 8;
      puVar332 = puVar331 + -3;
      puVar331[-3] = 0xdc32;
      ovr_blitLabel(*(char **)(puVar331 + -1),*(uint8_t **)(puVar331 + 1),puVar331[3],
                    *(uint8_t *)(puVar331 + 4));
      *(undefined2 *)((int)puVar332 + 0xe) = 0xdc;
      *(undefined2 *)((int)puVar332 + 0xc) = DAT_2000_ca93;
      *(undefined2 *)((int)puVar332 + 10) = DAT_2000_ca91;
      *(undefined2 *)((int)puVar332 + 8) = unaff_SS;
      *(int *)((int)puVar332 + 6) = iVar404 + -0xf6;
      *(undefined2 *)((int)puVar332 + 4) = (char *)"steam bath" + 6;
      puVar333 = (undefined1 *)((int)puVar332 + 2);
      *(undefined2 *)((int)puVar332 + 2) = 0xdc52;
      pcVar495 = litoa10((char *)*(undefined2 *)((int)puVar332 + 6),*(long *)((int)puVar332 + 10));
      *(int *)(puVar333 + 10) = iVar490;
      *(char **)(puVar333 + 8) = pcVar495;
      *(char **)(puVar333 + 6) = (char *)"steam bath" + 6;
      puVar334 = puVar333 + 4;
      *(undefined2 *)(puVar333 + 4) = 0xdc5b;
      manage_4d05_04c6();
      *(char **)(puVar334 + 8) = (char *)"steam bath" + 6;
      puVar335 = (undefined2 *)(puVar334 + 6);
      *(undefined2 *)(puVar334 + 6) = 0xdc63;
      uVar17 = manage_4d05_1b1d();
      *(undefined1 *)(iVar404 + -5) = uVar17;
      pfVar24 = (far_t *)((char *)"puppetmaker" + 3);
      TextBlitY = TextBlitY + 0xf;
      if (((*(char *)((int)*(undefined4 *)(iVar404 + 4) + 0x86) != '\0') &&
          (*(char *)(iVar404 + -5) != -1)) &&
         (pfVar24 = (far_t *)((uint)*(byte *)(iVar404 + -5) << 2),
         *(byte *)((*pfVar24).ofs + 0x86) < 9)) {
        puVar335[1] = 0xe0;
        *puVar335 = 0x7d;
        puVar335[-1] = (char *)"puppetmaker" + 3;
        puVar335[-2] = (char *)"popularity";
        puVar335[-3] = (char *)"steam bath" + 6;
        puVar336 = (undefined4 *)(puVar335 + -4);
        puVar335[-4] = 0xdcb4;
        manage_4d05_0519();
        *(undefined2 *)((int)puVar336 + 10) = 0xe0;
        *(undefined2 *)((int)puVar336 + 8) = 0xdc;
        *(undefined2 *)((int)puVar336 + 6) = (char *)"puppetmaker" + 3;
        *(undefined2 *)((int)puVar336 + 4) = (char *)"city blocks";
        *(undefined2 *)((int)puVar336 + 2) = (char *)"steam bath" + 6;
        *(undefined2 *)puVar336 = 0xdcc5;
        manage_4d05_0519();
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x11;
        *(undefined2 *)((int)puVar336 + 10) = 0xe0;
        *(undefined2 *)(puVar336 + 2) = 0xde;
        *(uint16_t *)((int)puVar336 + 6) = Font02.seg;
        *(uint16_t *)(puVar336 + 1) = Font02.ofs;
        *(undefined2 *)((int)puVar336 + 2) = (char *)"puppetmaker" + 3;
        *(char **)puVar336 = (char *)"Current";
        *(undefined2 *)((int)puVar336 + -2) = (char *)"steam bath" + 6;
        puVar337 = puVar336 + -1;
        *(undefined2 *)(puVar336 + -1) = 0xdcfd;
        ovr_blitLabel((char *)*puVar336,(uint8_t *)puVar336[1],*(int16_t *)(puVar336 + 2),
                      *(uint8_t *)((int)puVar336 + 10));
        *(undefined2 *)((int)puVar337 + 0xe) = 0x7d;
        *(undefined2 *)((int)puVar337 + 0xc) = (char *)"steam bath" + 6;
        puVar338 = (undefined2 *)((int)puVar337 + 10);
        *(undefined2 *)((int)puVar337 + 10) = 0xdd06;
        uVar20 = manage_4d05_044e();
        puVar338[1] = uVar20;
        *puVar338 = (char *)"puppetmaker" + 3;
        puVar338[-1] = (char *)"%d%%";
        puVar338[-2] = unaff_SS;
        puVar338[-3] = iVar404 + -0x7e;
        puVar338[-4] = (char *)"steam bath" + 6;
        puVar339 = puVar338 + -5;
        puVar338[-5] = 0xdd15;
        pcVar508 = ovr_stsprintf((char *)puVar338[-3],*(char **)(puVar338 + -1),(char *)puVar338[1])
        ;
        *(undefined2 *)((int)puVar339 + 0xc) = (int)((ulong)pcVar508 >> 0x10);
        *(undefined2 *)((int)puVar339 + 10) = (char *)pcVar508;
        *(undefined2 *)((int)puVar339 + 8) = (char *)"glassworks" + 9;
        puVar340 = (undefined2 *)((int)puVar339 + 6);
        *(undefined2 *)((int)puVar339 + 6) = 0xdd1e;
        manage_4d05_04c6();
        puVar340[4] = 0xdc;
        puVar340[3] = DAT_2000_d3ca;
        puVar340[2] = (char *)"puppetmaker" + 3;
        puVar340[1] = (char *)"%d";
        *puVar340 = unaff_SS;
        puVar340[-1] = iVar404 + -0x7e;
        puVar340[-2] = (char *)"glassworks" + 9;
        puVar341 = puVar340 + -3;
        puVar340[-3] = 0xdd3c;
        pcVar508 = ovr_stsprintf((char *)puVar340[-1],*(char **)(puVar340 + 1),(char *)puVar340[3]);
        *(undefined2 *)((int)puVar341 + 0xc) = (int)((ulong)pcVar508 >> 0x10);
        *(undefined2 *)((int)puVar341 + 10) = (char *)pcVar508;
        *(undefined2 *)((int)puVar341 + 8) = (char *)"glassworks" + 9;
        puVar342 = (undefined2 *)((int)puVar341 + 6);
        *(undefined2 *)((int)puVar341 + 6) = 0xdd45;
        manage_4d05_04c6();
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x11;
        puVar342[4] = 0xe0;
        puVar342[3] = 0xde;
        puVar342[2] = Font02.seg;
        puVar342[1] = Font02.ofs;
        *puVar342 = (char *)"puppetmaker" + 3;
        puVar342[-1] = (char *)"to promote";
        puVar342[-2] = (char *)"glassworks" + 9;
        puVar343 = puVar342 + -3;
        puVar342[-3] = 0xdd7d;
        ovr_blitLabel(*(char **)(puVar342 + -1),*(uint8_t **)(puVar342 + 1),puVar342[3],
                      *(uint8_t *)(puVar342 + 4));
        *(undefined2 *)((int)puVar343 + 0xe) = 0x7d;
        *(undefined2 *)((int)puVar343 + 0xc) = (char *)"steam bath" + 6;
        puVar344 = (undefined2 *)((int)puVar343 + 10);
        *(undefined2 *)((int)puVar343 + 10) = 0xdd87;
        bVar19 = ovr_season_67e7_04e5();
        puVar344[1] = (uint)bVar19;
        *puVar344 = (char *)"puppetmaker" + 3;
        puVar344[-1] = (char *)"%d%%";
        puVar344[-2] = unaff_SS;
        puVar344[-3] = iVar404 + -0x7e;
        puVar344[-4] = (char *)"forester\'s camp" + 5;
        puVar345 = puVar344 + -5;
        puVar344[-5] = 0xdd98;
        pcVar508 = ovr_stsprintf((char *)puVar344[-3],*(char **)(puVar344 + -1),(char *)puVar344[1])
        ;
        *(undefined2 *)((int)puVar345 + 0xc) = (int)((ulong)pcVar508 >> 0x10);
        *(undefined2 *)((int)puVar345 + 10) = (char *)pcVar508;
        *(undefined2 *)((int)puVar345 + 8) = (char *)"glassworks" + 9;
        puVar346 = (undefined1 *)((int)puVar345 + 6);
        *(undefined2 *)((int)puVar345 + 6) = 0xdda1;
        manage_4d05_04c6();
        *(undefined2 *)(puVar346 + 8) = 0xdc;
        *(char **)(puVar346 + 6) = (char *)"glassworks" + 9;
        puVar347 = (undefined2 *)(puVar346 + 4);
        *(undefined2 *)(puVar346 + 4) = 0xddac;
        uVar20 = ovr_season_67e7_048f();
        puVar347[1] = uVar20;
        *puVar347 = (char *)"puppetmaker" + 3;
        puVar347[-1] = (char *)"%d";
        puVar347[-2] = unaff_SS;
        puVar347[-3] = iVar404 + -0x7e;
        puVar347[-4] = (char *)"forester\'s camp" + 5;
        puVar348 = puVar347 + -5;
        puVar347[-5] = 0xddbb;
        pcVar508 = ovr_stsprintf((char *)puVar347[-3],*(char **)(puVar347 + -1),(char *)puVar347[1])
        ;
        *(undefined2 *)((int)puVar348 + 0xc) = (int)((ulong)pcVar508 >> 0x10);
        *(undefined2 *)((int)puVar348 + 10) = (char *)pcVar508;
        *(undefined2 *)((int)puVar348 + 8) = (char *)"glassworks" + 9;
        *(undefined2 *)((int)puVar348 + 6) = 0xddc4;
        pfVar24 = (far_t *)manage_4d05_04c6();
      }
    }
    return pfVar24;
  case 0x26:
  case 0x4d:
    return pfVar25;
  case 0x27:
  case 0x4e:
  case 0x71:
  case 0xe0:
  case 0xfb:
    *(byte *)&pfVar37->ofs = (char)pfVar37->ofs + bVar27;
    uVar487 = *(uint *)((int)&pfVar24[0x130].seg + iVar404);
    *(undefined2 *)(iVar404 + -8) = pcVar21;
    *(uint *)(iVar404 + -10) = (uint)pfVar25 & uVar487;
    *(undefined2 *)((int)puVar97 + 0xe) = unaff_SS;
    *(int *)((int)puVar97 + 0xc) = iVar404 + -0x30e;
    *(undefined2 *)((int)puVar97 + 10) = *(undefined2 *)(iVar404 + -8);
    *(undefined2 *)((int)puVar97 + 8) = *(undefined2 *)(iVar404 + -10);
    *(undefined2 *)((int)puVar97 + 6) = 0x4000;
    puVar261 = (undefined2 *)((int)puVar97 + 4);
    *(undefined2 *)((int)puVar97 + 4) = 0xc220;
    uVar20 = ovr_calcSeasonPalette();
    *(undefined2 *)((int)puVar261 + 10) = pcVar21;
    *(undefined2 *)((int)puVar261 + 8) = uVar20;
    *(undefined2 *)((int)puVar261 + 6) = (char *)"forester\'s camp" + 5;
    puVar262 = (undefined2 *)((int)puVar261 + 4);
    *(undefined2 *)((int)puVar261 + 4) = 0xc229;
    init_special_graphics();
    puVar262[3] = unaff_SS;
    puVar262[2] = iVar404 + -0x30e;
    puVar262[1] = (char *)"forester\'s camp" + 5;
    *puVar262 = 0xc237;
    ovr_vgaSetPalette8bit();
    puVar262[3] = Lbm_nwpanel1.seg;
    puVar262[2] = Lbm_nwpanel1.ofs;
    puVar262[1] = (char *)"arrowsmith" + 3;
    *puVar262 = 0xc246;
    init_special_graphics();
    puVar262[3] = DAT_2000_d1ce;
    puVar262[2] = DAT_2000_d1cc;
    puVar262[1] = (char *)"arrowsmith" + 3;
    *puVar262 = 0xc256;
    psVar505 = ovr_stshLoadGfx(*(far_t *)(puVar262 + 2));
    *(undefined2 *)(iVar404 + -0xc) = (int)((ulong)psVar505 >> 0x10);
    *(undefined2 *)(iVar404 + -0xe) = (stg_tmp_t *)psVar505;
    puVar262[3] = 8;
    puVar262[2] = *(undefined2 *)(iVar404 + -0xc);
    puVar262[1] = *(undefined2 *)(iVar404 + -0xe);
    *puVar262 = (char *)"puppetmaker" + 3;
    puVar262[-1] = (uint8_t *)SpecialColors;
    puVar262[-2] = (char *)"glassworks" + 9;
    puVar263 = puVar262 + -3;
    puVar262[-3] = 0xc272;
    memcpy((uint8_t *)puVar262[-1],(uint8_t *)puVar262[1],puVar262[3]);
    *(undefined2 *)((int)puVar263 + 0xc) = DAT_2000_d1ce;
    *(undefined2 *)((int)puVar263 + 10) = DAT_2000_d1cc;
    *(undefined2 *)((int)puVar263 + 8) = 0x1000;
    puVar264 = (undefined2 *)((int)puVar263 + 6);
    *(undefined2 *)((int)puVar263 + 6) = 0xc281;
    init_special_graphics();
    puVar264[3] = 0;
    puVar264[2] = 0xfa0f;
    puVar264[1] = 0x1000;
    pcVar495 = (char *)"glassworks" + 9;
    *puVar264 = 0xc28e;
    pfVar506 = ovr_stshAlloc(*(uint32_t *)(puVar264 + 2));
    pfVar265 = (far_t *)((int)puVar264 + 4);
code_r0x0004c28e:
    *(undefined2 *)(iVar404 + -4) = (int)((ulong)pfVar506 >> 0x10);
    *(undefined2 *)(iVar404 + -6) = (far_t *)pfVar506;
    pfVar265->seg = *(undefined2 *)(iVar404 + -4);
    pfVar265->ofs = *(undefined2 *)(iVar404 + -6);
    pfVar265[-1].seg = (uint16_t)pcVar495;
    pfVar266 = pfVar265 + -1;
    (pfVar265 + -1)->ofs = 0xc2a2;
    fVar503 = ovr_alignToSeg(*pfVar265);
    pfVar24 = (far_t *)fVar503.seg;
    *(undefined2 *)((int)pfVar266 + 6) = pfVar24;
    *(undefined2 *)((int)pfVar266 + 4) = 0;
    *(undefined2 *)((int)pfVar266 + 2) = 199;
    pfVar266->ofs = 0x13f;
    *(undefined2 *)((int)pfVar266 + -2) = 0;
    *(undefined2 *)((int)pfVar266 + -4) = 0;
    *(undefined2 *)((int)pfVar266 + -6) = (char *)"bath house" + 2;
    puVar267 = (undefined2 *)((int)pfVar266 + -8);
    *(undefined2 *)((int)pfVar266 + -8) = 0xc2b9;
    ovr_driver_2d63_05e5();
    *(undefined2 *)((int)puVar267 + 0xe) = pfVar24;
    *(undefined2 *)((int)puVar267 + 0xc) = 0;
    *(undefined2 *)((int)puVar267 + 10) = DAT_2000_d1ca;
    *(undefined2 *)((int)puVar267 + 8) = DAT_2000_d1c8;
    *(undefined2 *)((int)puVar267 + 6) = (char *)"arrowsmith" + 3;
    puVar268 = (undefined1 *)((int)puVar267 + 4);
    *(undefined2 *)((int)puVar267 + 4) = 0xc2cc;
    ovr_blitLoadRleGfx(*(far_t *)((int)puVar267 + 8),*(far_t *)((int)puVar267 + 0xc));
    *(undefined2 *)(puVar268 + 10) = DAT_2000_d1ca;
    *(undefined2 *)(puVar268 + 8) = DAT_2000_d1c8;
    *(char **)(puVar268 + 6) = (char *)"bath house" + 10;
    puVar269 = (undefined2 *)(puVar268 + 4);
    *(undefined2 *)(puVar268 + 4) = 0xc2db;
    init_special_graphics();
    puVar269[3] = pfVar24;
    puVar269[2] = 0;
    puVar269[1] = (char *)"bath house" + 10;
    *puVar269 = 0xc2e6;
    Font03 = ovr_stshProcessFontSub(*(far_t *)(puVar269 + 2));
    puVar269[3] = pfVar24;
    puVar269[2] = 0;
    puVar269[1] = 199;
    *puVar269 = 0x13f;
    puVar269[-1] = 0;
    puVar269[-2] = 0;
    puVar269[-3] = (char *)"steam bath" + 6;
    puVar270 = puVar269 + -4;
    puVar269[-4] = 0xc309;
    ovr_driver_2d63_05e5();
    *(undefined2 *)((int)puVar270 + 0xe) = pfVar24;
    *(undefined2 *)((int)puVar270 + 0xc) = 0;
    *(undefined2 *)((int)puVar270 + 10) = DAT_2000_d1c6;
    *(undefined2 *)((int)puVar270 + 8) = DAT_2000_d1c4;
    *(undefined2 *)((int)puVar270 + 6) = (char *)"arrowsmith" + 3;
    puVar271 = (undefined1 *)((int)puVar270 + 4);
    *(undefined2 *)((int)puVar270 + 4) = 0xc31c;
    ovr_blitLoadRleGfx(*(far_t *)((int)puVar270 + 8),*(far_t *)((int)puVar270 + 0xc));
    *(undefined2 *)(puVar271 + 10) = DAT_2000_d1c6;
    *(undefined2 *)(puVar271 + 8) = DAT_2000_d1c4;
    *(char **)(puVar271 + 6) = (char *)"bath house" + 10;
    puVar272 = (undefined2 *)(puVar271 + 4);
    *(undefined2 *)(puVar271 + 4) = 0xc32b;
    init_special_graphics();
    puVar272[3] = pfVar24;
    puVar272[2] = 0;
    puVar272[1] = (char *)"bath house" + 10;
    *puVar272 = 0xc336;
    Font02 = ovr_stshProcessFontSub(*(far_t *)(puVar272 + 2));
    puVar272[3] = pfVar24;
    puVar272[2] = 0;
    puVar272[1] = 199;
    *puVar272 = 0x13f;
    puVar272[-1] = 0;
    puVar272[-2] = 0;
    puVar272[-3] = (char *)"steam bath" + 6;
    puVar273 = puVar272 + -4;
    puVar272[-4] = 0xc359;
    ovr_driver_2d63_05e5();
    *(undefined2 *)((int)puVar273 + 0xe) = pfVar24;
    *(undefined2 *)((int)puVar273 + 0xc) = 0;
    *(undefined2 *)((int)puVar273 + 10) = DAT_2000_d1c2;
    *(undefined2 *)((int)puVar273 + 8) = DAT_2000_d1c0;
    *(undefined2 *)((int)puVar273 + 6) = (char *)"arrowsmith" + 3;
    puVar274 = (undefined1 *)((int)puVar273 + 4);
    *(undefined2 *)((int)puVar273 + 4) = 0xc36c;
    ovr_blitLoadRleGfx(*(far_t *)((int)puVar273 + 8),*(far_t *)((int)puVar273 + 0xc));
    *(undefined2 *)(puVar274 + 10) = DAT_2000_d1c2;
    *(undefined2 *)(puVar274 + 8) = DAT_2000_d1c0;
    *(char **)(puVar274 + 6) = (char *)"bath house" + 10;
    puVar275 = (undefined2 *)(puVar274 + 4);
    *(undefined2 *)(puVar274 + 4) = 0xc37b;
    init_special_graphics();
    puVar275[3] = pfVar24;
    puVar275[2] = 0;
    puVar275[1] = (char *)"bath house" + 10;
    pcVar495 = (char *)"steam bath" + 6;
    *puVar275 = 0xc386;
    Font01 = ovr_stshProcessFontSub(*(far_t *)(puVar275 + 2));
    FontMain.seg = Font01.seg;
    puVar276 = (undefined2 *)((int)puVar275 + 8);
    pfVar489 = (far_t *)0x0;
    fVar9 = Font01;
    while( true ) {
      pfVar25 = (far_t *)fVar9.seg;
      FontMain.ofs = fVar9.ofs;
      if (3 < (int)pfVar489) break;
LAB_4b0a_1318:
      *(undefined2 *)((int)puVar276 + -2) = pfVar24;
      *(undefined2 *)((int)puVar276 + -4) = 0;
      *(undefined2 *)((int)puVar276 + -6) = 0x11;
      *(undefined2 *)((int)puVar276 + -8) = 0x11;
      *(undefined2 *)((int)puVar276 + -10) = 0;
      *(undefined2 *)((int)puVar276 + -0xc) = 0;
      *(undefined2 *)((int)puVar276 + -0xe) = pcVar495;
      puVar277 = (undefined1 *)((int)puVar276 + -0x10);
      *(undefined2 *)((int)puVar276 + -0x10) = 0xc3c8;
      ovr_driver_2d63_05e5();
      *(far_t **)(puVar277 + 0xe) = pfVar24;
      *(undefined2 *)(puVar277 + 0xc) = 0;
      *(undefined2 *)(puVar277 + 10) = *(undefined2 *)((int)&MiceCursors[0].seg + (int)pfVar489 * 4)
      ;
      *(uint16_t *)(puVar277 + 8) = ((far_t *)MiceCursors + (int)pfVar489)->ofs;
      *(char **)(puVar277 + 6) = (char *)"arrowsmith" + 3;
      puVar278 = puVar277 + 4;
      *(undefined2 *)(puVar277 + 4) = 0xc3e7;
      ovr_blitLoadRleGfx(*(far_t *)(puVar277 + 8),*(far_t *)(puVar277 + 0xc));
      *(undefined2 *)(puVar278 + 10) = *(undefined2 *)((int)&MiceCursors[0].seg + (int)pfVar489 * 4)
      ;
      *(uint16_t *)(puVar278 + 8) = ((far_t *)MiceCursors + (int)pfVar489)->ofs;
      *(char **)(puVar278 + 6) = (char *)"bath house" + 10;
      puVar279 = (undefined2 *)(puVar278 + 4);
      *(undefined2 *)(puVar278 + 4) = 0xc402;
      init_special_graphics();
      puVar279[3] = 0;
      puVar279[2] = 0;
      puVar279[1] = pfVar24;
      *puVar279 = (char *)"bath house" + 10;
      puVar280 = puVar279 + -1;
      puVar279[-1] = 0xc40f;
      video_13aa_0266();
      *(undefined2 *)((int)puVar280 + 8) = 0;
      *(undefined2 *)((int)puVar280 + 6) = 0x121;
      *(undefined2 *)((int)puVar280 + 4) = 0x13aa;
      puVar281 = (undefined2 *)((int)puVar280 + 2);
      *(undefined2 *)((int)puVar280 + 2) = 0xc41c;
      pvVar507 = ovr_stshAlloc(*(uint32_t *)((int)puVar280 + 6));
      *(undefined2 *)((int)&MicePtrs.seg + (int)pfVar489 * 4) = (int)((ulong)pvVar507 >> 0x10);
      ((far_t *)&MicePtrs + (int)pfVar489)->ofs = (uint16_t)(void *)pvVar507;
      puVar281[3] = 0x121;
      puVar281[2] = (char *)"sturdy n/s gate" + 10;
      puVar281[1] = 0;
      pcVar21 = (char *)"puppetmaker" + 3;
      *puVar281 = *(undefined2 *)((int)&MicePtrs.seg + (int)pfVar489 * 4);
      puVar281[-1] = ((far_t *)&MicePtrs + (int)pfVar489)->ofs;
      puVar281[-2] = (char *)"glassworks" + 9;
      pcVar495 = (char *)0x1000;
      puVar282 = puVar281 + -3;
      puVar281[-3] = 0xc455;
      memcpy((uint8_t *)puVar281[-1],(uint8_t *)puVar281[1],puVar281[3]);
      fVar9.seg = (uint16_t)pcVar21;
      fVar9.ofs = FontMain.ofs;
      puVar276 = (undefined2 *)((int)puVar282 + 0xe);
      pfVar489 = (far_t *)((int)&pfVar489->ofs + 1);
    }
    *(undefined2 *)((int)puVar276 + -2) = *(undefined2 *)(iVar404 + -4);
    *(undefined2 *)((int)puVar276 + -4) = *(undefined2 *)(iVar404 + -6);
    *(undefined2 *)((int)puVar276 + -6) = pcVar495;
    *(undefined2 *)((int)puVar276 + -8) = 0xc46c;
    ovr_stshFree(*(far_t *)((int)puVar276 + -4));
    return pfVar25;
  case 0x28:
  case 0x35:
  case 0x40:
  case 0x4f:
  case 0x72:
  case 0xe1:
  case 0xfc:
    *(byte *)&pfVar489->ofs = (char)pfVar489->ofs + bVar29 + bVar499;
    goto code_r0x00045dbc;
  case 0x29:
  case 0x36:
  case 0x41:
  case 0x50:
  case 0x73:
  case 0xe2:
  case 0xfd:
    puVar216 = (undefined2 *)((int)puVar97 + 0xe);
    *(undefined2 *)((int)puVar97 + 0xe) = pcVar494;
    pcVar508 = (char *)((int)&pfVar489->ofs + (int)&pfVar37[-0x11f1].seg);
    *pcVar508 = *pcVar508 + bVar19;
    puVar485 = (undefined1 *)(iVar404 + -1);
    *(byte *)&pfVar24[3].seg = (char)pfVar24[3].seg + bVar27;
    bVar499 = GameRunning == false;
code_r0x00048b2f:
    if (bVar499) {
      *(undefined2 *)((int)puVar216 + -2) = 2;
      *(undefined2 *)((int)puVar216 + -4) = 0;
      *(undefined2 *)((int)puVar216 + -6) = unaff_SS;
      *(int *)((int)puVar216 + -8) = (int)(puVar485 + -6);
      *(undefined2 *)((int)puVar216 + -10) = 0x4000;
      pcVar495 = (char *)0x1000;
      puVar215 = (undefined1 *)((int)puVar216 + -0xc);
      *(undefined2 *)((int)puVar216 + -0xc) = 0x8b47;
      _fmemset((void *)*(undefined4 *)((int)puVar216 + -8),*(uint16_t *)((int)puVar216 + -4),
               *(uint16_t *)((int)puVar216 + -2));
      puVar216 = (undefined2 *)(puVar215 + 0xc);
      for (pfVar489 = (far_t *)0x0; (int)pfVar489 < (int)(uint)DAT_2000_d1e6;
          pfVar489 = (far_t *)((int)&pfVar489->ofs + 1)) {
        pfVar37 = (far_t *)((int)pfVar489 << 2);
code_r0x00048b54:
        if (((*(char *)((*pfVar37).ofs + 0x3d) != '\0') &&
            (puVar485[*(byte *)((int)*(undefined4 *)((int)pfVar489 << 2) + 0x3f) - 6] =
                  puVar485[*(byte *)((int)*(undefined4 *)((int)pfVar489 << 2) + 0x3f) - 6] + '\x01',
            *(int *)((int)*(undefined4 *)((int)pfVar489 << 2) + 0x39) == GfxRndSeed)) &&
           (*(int *)((int)*(undefined4 *)((int)pfVar489 << 2) + 0x3b) == GfxRndSeed2)) {
          *(undefined2 *)((int)puVar216 + -2) = pcVar495;
          pcVar495 = (char *)"fletcher\'s shop" + 0xd;
          puVar217 = (undefined1 *)((int)puVar216 + -4);
          *(undefined2 *)((int)puVar216 + -4) = 0x8bca;
          cVar18 = ovr_draw_2e25_15d6();
          puVar220 = (undefined2 *)(puVar217 + 4);
          if (cVar18 == '\0') {
            return (far_t *)0x0;
          }
          pcVar21 = (char *)*(undefined2 *)((int)pfVar489 * 4);
          *(undefined2 *)(puVar485 + -2) = ((undefined2 *)((int)pfVar489 * 4))[1];
          puVar486 = puVar485;
          goto code_r0x00048bea;
        }
      }
      if (DAT_2000_d1e4 != 0) {
        uVar20 = *(undefined2 *)((uint)DAT_2000_d1e4 * 4 + -4);
        *(undefined2 *)(puVar485 + -2) = *(undefined2 *)((uint)DAT_2000_d1e4 * 4 + -2);
        *(undefined2 *)(puVar485 + -4) = uVar20;
        *(undefined2 *)((int)puVar216 + -2) = pcVar495;
        puVar221 = (undefined2 *)((int)puVar216 + -4);
        *(undefined2 *)((int)puVar216 + -4) = (char *)GOriginalDir + 0x41;
        cVar18 = OVC18_48ac_1092();
        if (cVar18 == '\0') {
          puVar221[1] = *(undefined2 *)(puVar485 + -2);
          *puVar221 = *(undefined2 *)(puVar485 + -4);
          puVar221[-1] = (char *)"puppetmaker" + 3;
          puVar221[-2] = (char *)"View %s. (Cannot place)";
          puVar221[-3] = pcVar495;
          puVar225 = puVar221 + -4;
          puVar221[-4] = 0x8c9a;
          pcVar495 = ovr_fmVsprintf((char *)puVar221[-2],(char *)*puVar221);
          *(undefined2 *)((int)puVar225 + 10) = uVar20;
          *(undefined2 *)((int)puVar225 + 8) = pcVar495;
          *(undefined2 *)((int)puVar225 + 6) = (char *)"glassworks" + 9;
          puVar226 = (undefined1 *)((int)puVar225 + 4);
          *(undefined2 *)((int)puVar225 + 4) = 0x8ca4;
          ovr_say((char *)*(undefined4 *)((int)puVar225 + 8));
          puVar224 = puVar226 + 8;
        }
        else {
          puVar221[1] = *(undefined2 *)(puVar485 + -2);
          *puVar221 = *(undefined2 *)(puVar485 + -4);
          puVar221[-1] = (char *)"puppetmaker" + 3;
          puVar221[-2] = (char *)"Place %s.";
          puVar221[-3] = pcVar495;
          puVar222 = puVar221 + -4;
          puVar221[-4] = 0x8c7c;
          pcVar495 = ovr_fmVsprintf((char *)puVar221[-2],(char *)*puVar221);
          *(undefined2 *)((int)puVar222 + 10) = uVar20;
          *(undefined2 *)((int)puVar222 + 8) = pcVar495;
          *(undefined2 *)((int)puVar222 + 6) = (char *)"glassworks" + 9;
          puVar223 = (undefined1 *)((int)puVar222 + 4);
          *(undefined2 *)((int)puVar222 + 4) = 0x8c86;
          ovr_say((char *)*(undefined4 *)((int)puVar222 + 8));
          puVar224 = puVar223 + 8;
        }
        DAT_2000_d1ae = 1;
        *(char **)(puVar224 + -2) = (char *)"steam bath" + 6;
        *(undefined2 *)(puVar224 + -4) = 0x8cb0;
        pfVar24 = (far_t *)OVC18_48ac_0000();
        return pfVar24;
      }
      if (DAT_2000_d1e5 < DAT_2000_d1e3) {
        if (GameRunning == false) {
          if (DAT_2000_d1e5 == 0) {
            *(undefined2 *)((int)puVar216 + -2) = (char *)"puppetmaker" + 3;
            *(undefined2 *)((int)puVar216 + -4) = (char *)"Create baron or baroness.";
            *(undefined2 *)((int)puVar216 + -6) = pcVar495;
            pcVar495 = (char *)"steam bath" + 6;
            puVar227 = (undefined1 *)((int)puVar216 + -8);
            *(undefined2 *)((int)puVar216 + -8) = 0x8cee;
            ovr_say((char *)*(undefined4 *)((int)puVar216 + -4));
            puVar216 = (undefined2 *)(puVar227 + 8);
          }
          else {
            *(undefined2 *)((int)puVar216 + -2) = (char *)"puppetmaker" + 3;
            *(undefined2 *)((int)puVar216 + -4) = (char *)"Create party member.";
            *(undefined2 *)((int)puVar216 + -6) = pcVar495;
            pcVar495 = (char *)"steam bath" + 6;
            puVar228 = (undefined1 *)((int)puVar216 + -8);
            *(undefined2 *)((int)puVar216 + -8) = 0x8cfc;
            ovr_say((char *)*(undefined4 *)((int)puVar216 + -4));
            puVar216 = (undefined2 *)(puVar228 + 8);
          }
        }
        DAT_2000_d1ae = 1;
        *(undefined2 *)((int)puVar216 + -2) = pcVar495;
        *(undefined2 *)((int)puVar216 + -4) = 0x8d08;
        pfVar24 = (far_t *)OVC18_48ac_0000();
        return pfVar24;
      }
    }
    else {
      DAT_2410_45b8 = 0;
    }
    *(undefined2 *)((int)puVar216 + -2) = pcVar495;
    *(undefined2 *)((int)puVar216 + -4) = 0x8d0e;
    pfVar24 = (far_t *)OVC18_48ac_0027();
    return pfVar24;
  case 0x2a:
  case 0x37:
  case 0x42:
  case 0x51:
  case 0x74:
  case 0xe3:
  case 0xfe:
    *(undefined2 *)((int)puVar97 + 0xe) = 0;
    *(undefined2 *)((int)puVar97 + 0xc) = pfVar24;
    *(undefined2 *)((int)puVar97 + 10) = pfVar489;
    *(undefined2 *)((int)puVar97 + 8) = *(undefined2 *)(iVar404 + -8);
    *(undefined2 *)((int)puVar97 + 6) = *(undefined2 *)(iVar404 + -6);
    *(undefined2 *)((int)puVar97 + 4) = 0x4000;
    puVar229 = (undefined2 *)((int)puVar97 + 2);
    *(undefined2 *)((int)puVar97 + 2) = 0x8ee7;
    ovr_OVC15_4207_10a3();
    *(undefined2 *)((int)puVar229 + 0x10) = 2;
    *(undefined2 *)((int)puVar229 + 0xe) = (char *)"jeweler\'s shop" + 3;
    pcVar495 = (char *)"glassworks" + 9;
    puVar230 = (undefined2 *)((int)puVar229 + 0xc);
    *(undefined2 *)((int)puVar229 + 0xc) = 0x8ef1;
    uVar23 = ovr_randBelow(*(uint16_t *)((int)puVar229 + 0x10));
    puVar232 = puVar230 + 3;
    if ((uVar23 & 0xff) == 0) {
      puVar230[2] = (uint)*(byte *)(iVar404 + 4);
      puVar230[1] = 1;
      *puVar230 = 5;
      puVar230[-1] = pfVar24;
      puVar230[-2] = pfVar489;
      puVar230[-3] = *(undefined2 *)(iVar404 + -8);
      puVar230[-4] = *(undefined2 *)(iVar404 + -6);
      puVar230[-5] = (char *)"glassworks" + 9;
      pcVar495 = (char *)"jeweler\'s shop" + 3;
      puVar231 = puVar230 + -6;
      puVar230[-6] = 0x8f12;
      ovr_OVC15_4207_10a3();
      puVar232 = (undefined2 *)((int)puVar231 + 0x12);
    }
    pfVar25 = (far_t *)((uint)*(byte *)((int)*(undefined4 *)(iVar404 + -0xc) + 0x3e) * 0x95);
    if (((pfVar25 + 0x9c5)->ofs & 0x8000) != 0) {
      uVar17 = (undefined1)((uint)pfVar25 >> 8);
      *(undefined2 *)((int)puVar232 + -2) = CONCAT11(uVar17,*(undefined1 *)(iVar404 + 10));
      *(undefined2 *)((int)puVar232 + -4) = CONCAT11(uVar17,*(undefined1 *)(iVar404 + 4));
      *(undefined2 *)((int)puVar232 + -6) = 1;
      *(undefined2 *)((int)puVar232 + -8) = pfVar24;
      *(undefined2 *)((int)puVar232 + -10) = pfVar489;
      *(undefined2 *)((int)puVar232 + -0xc) = *(undefined2 *)(iVar404 + -8);
      *(undefined2 *)((int)puVar232 + -0xe) = *(undefined2 *)(iVar404 + -6);
      *(undefined2 *)((int)puVar232 + -0x10) = pcVar495;
      *(undefined2 *)((int)puVar232 + -0x12) = (undefined2 *)&DAT_2000_d1a3;
      pfVar25 = (far_t *)OVC18_48ac_0251();
    }
    return pfVar25;
  case 0x2b:
  case 0x38:
  case 0x43:
  case 0x52:
  case 0x75:
    goto code_r0x000426c2;
  case 0x2c:
    StshCount = StshCount + 1;
    *(undefined2 *)((int)puVar97 + 0xe) = 0x4000;
    puVar260 = (uint16_t *)((int)puVar97 + 0xc);
    *(undefined2 *)((int)puVar97 + 0xc) = 0xbf9c;
    lVar502 = LXMUL_at_(0x15,(ulong)uVar23);
    puVar260[1] = (int)lVar502;
    *puVar260 = (int)((ulong)lVar502 >> 0x10);
    uVar11 = StshCtPtr.seg;
    uVar10 = StshCtPtr.ofs;
    uVar23 = *puVar260;
    uVar492 = puVar260[1];
    puVar260[1] = 0x1000;
    *puVar260 = 0xbfac;
    fVar503.seg = uVar11;
    fVar503.ofs = uVar10;
    ptr_ofs_00.seg = uVar23;
    ptr_ofs_00.ofs = uVar492;
    fVar503 = PADD_at_(fVar503,ptr_ofs_00);
    *puVar260 = fVar503.seg;
    puVar260[-1] = fVar503.ofs;
    puVar260[-2] = 0x1000;
    puVar260[-3] = 0xbfb3;
    uVar504 = ovr_mkp(puVar260[-1],*puVar260);
    *(undefined2 *)(iVar404 + -4) = (int)(uVar504 >> 0x10);
    *(undefined2 *)(iVar404 + -6) = (int)uVar504;
    uVar493 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
    iVar488 = (int)*(undefined4 *)(iVar404 + -6);
    uVar20 = *(undefined2 *)(iVar404 + 4);
    *(undefined2 *)(iVar488 + 7) = *(undefined2 *)(iVar404 + 6);
    *(undefined2 *)(iVar488 + 5) = uVar20;
    *(undefined1 *)*(undefined4 *)(iVar404 + -6) = 0;
    uVar23 = StshCtOfs.lo;
    uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
    iVar488 = (int)*(undefined4 *)(iVar404 + -6);
    *(uint16_t *)(iVar488 + 3) = StshCtOfs.hi;
    *(uint16_t *)(iVar488 + 1) = uVar23;
    uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
    iVar488 = (int)*(undefined4 *)(iVar404 + -6);
    *(undefined2 *)(iVar488 + 0x13) = 0;
    *(undefined2 *)(iVar488 + 0x11) = 0;
    bVar499 = CARRY2(StshCtOfs.lo,*(uint *)(iVar404 + 4));
    StshCtOfs.lo = StshCtOfs.lo + *(uint *)(iVar404 + 4);
    StshCtOfs.hi = StshCtOfs.hi + *(int *)(iVar404 + 6) + (uint)bVar499;
    uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
    iVar488 = (int)*(undefined4 *)(iVar404 + -6);
    *(undefined2 *)(iVar488 + 0xb) = 0;
    *(undefined2 *)(iVar488 + 9) = 0;
    uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
    iVar488 = (int)*(undefined4 *)(iVar404 + -6);
    *(undefined2 *)(iVar488 + 0xf) = 0;
    *(undefined2 *)(iVar488 + 0xd) = 0;
    return (far_t *)*(undefined2 *)(iVar404 + -6);
  case 0x2d:
  case 0x54:
    *(char *)(iVar488 + 0x79) = *(char *)(iVar488 + 0x79) + bVar27;
    puVar112 = (undefined2 *)((int)puVar97 + 0x10);
    goto code_r0x0004270b;
  case 0x2e:
    bVar19 = bVar19 + 0x54 + bVar499;
    uVar30 = (uint)pcVar21 ^ pfVar24->ofs;
    cVar18 = bVar19 + (9 < (bVar19 & 0xf) | in_AF) * '\x06' + (0x99 < bVar19) * 'a';
    bVar39 = (byte)uVar30;
    *(byte *)&pfVar24->ofs = (char)pfVar24->ofs + bVar39;
    bVar499 = 0x1d < (byte)(cVar18 + 0xeU);
    bVar500 = 0x26 < (byte)(cVar18 - 0x10U) || CARRY1(cVar18 - 0x37U,bVar499);
    bVar15 = (cVar18 - 0x37U) + bVar499;
    bVar19 = bVar15 - 0x38;
    bVar499 = 0x37 < bVar15 || CARRY1(bVar19,bVar500);
    bVar19 = bVar19 + bVar500;
    bVar15 = bVar19 + 0xaa;
    bVar500 = 0x55 < bVar19 || CARRY1(bVar15,bVar499);
    bVar15 = bVar15 + bVar499;
    bVar19 = bVar15 + 0x95;
    bVar499 = 0x6a < bVar15 || CARRY1(bVar19,bVar500);
    bVar19 = bVar19 + bVar500;
    bVar15 = bVar19 + 0x84;
    bVar500 = 0x7b < bVar19 || CARRY1(bVar15,bVar499);
    bVar15 = bVar15 + bVar499;
    bVar19 = bVar15 + 0x78;
    bVar499 = 0x87 < bVar15 || CARRY1(bVar19,bVar500);
    bVar19 = bVar19 + bVar500;
    bVar15 = bVar19 + 0x69;
    bVar500 = 0x96 < bVar19 || CARRY1(bVar15,bVar499);
    bVar15 = bVar15 + bVar499;
    bVar19 = bVar15 + 0x58;
    bVar499 = 0xa7 < bVar15 || CARRY1(bVar19,bVar500);
    bVar19 = bVar19 + bVar500;
    bVar15 = bVar19 + 0x2b;
    bVar500 = 0xd4 < bVar19 || CARRY1(bVar15,bVar499);
    bVar15 = bVar15 + bVar499;
    bVar19 = bVar15 + 0x1f;
    bVar499 = 0xe0 < bVar15 || CARRY1(bVar19,bVar500);
    bVar19 = bVar19 + bVar500;
    bVar15 = bVar19 + 0x15;
    bVar500 = 0xea < bVar19 || CARRY1(bVar15,bVar499);
    bVar15 = bVar15 + bVar499;
    bVar19 = bVar15 + 3;
    bVar498 = 0xfc < bVar15 || CARRY1(bVar19,bVar500);
    bVar19 = bVar19 + bVar500;
    bVar499 = CARRY1(bVar19,bVar498);
    bVar19 = bVar19 + bVar498;
    bVar15 = bVar19 + 0xa5;
    bVar29 = bVar15 + bVar499;
    piVar3 = (int *)((int)&pfVar489[6].ofs + (int)((int)&pfVar37->seg + 1));
    uVar487 = (uint)(0x5a < bVar19 || CARRY1(bVar15,bVar499));
    pfVar25 = (far_t *)*piVar3;
    uVar484 = (int)pfVar24 - *piVar3;
    puVar32 = (undefined2 *)(uVar484 - uVar487);
    *(undefined2 *)((int)puVar97 + 0xe) = pfVar489;
    uVar487 = (uint)(pfVar24 < pfVar25 || uVar484 < uVar487);
    uVar484 = (int)pfVar37 - pfVar37->ofs;
    iVar490 = uVar484 - uVar487;
    pcVar495 = (char *)(uint)(pfVar37 < (far_t *)pfVar37->ofs || uVar484 < uVar487);
    bVar499 = in_CX < (char *)"cue9a.xmi" + 1 || (char *)((int)in_CX + -0x36ff) < pcVar495;
    bVar27 = (byte)(uVar30 >> 8);
    bVar15 = (bVar39 - bVar29) - bVar499;
    bVar19 = (byte)(((int)in_CX + -0x36ff) - (int)pcVar495);
    bVar499 = bVar19 < bVar29 ||
              (byte)(bVar19 - bVar29) < (bVar39 < bVar29 || (byte)(bVar39 - bVar29) < bVar499);
    bVar19 = bVar15 - ((char *)"%s will be salvaged for %d gold. Are you sure?" + 0x2c)[iVar488];
    bVar500 = bVar15 < (byte)((char *)"%s will be salvaged for %d gold. Are you sure?" + 0x2c)
                             [iVar488] || bVar19 < bVar499;
    bVar15 = bVar27 - *(byte *)((int)&pfVar489[6].ofs + iVar404);
    bVar498 = bVar27 < *(byte *)((int)&pfVar489[6].ofs + iVar404) || bVar15 < bVar500;
    uVar493 = in(CONCAT11(bVar15 - bVar500,bVar19 - bVar499));
    *puVar32 = uVar493;
    pbVar1 = (byte *)((int)puVar32 + iVar490 + 0x1c);
    bVar19 = (byte)iVar490 - *pbVar1;
    bVar499 = (byte)iVar490 < *pbVar1 || bVar19 < bVar498;
    cVar18 = (char)((uint)iVar490 >> 8);
    pdVar491 = (double *)((int)puVar32 + 1);
    bVar15 = cVar18 - 1;
    uVar30 = CONCAT11(bVar15 - bVar499,bVar19 - bVar498);
    uVar487 = (uint)(cVar18 == '\0' || bVar15 < bVar499);
    iVar490 = -uVar487;
    piVar3 = (int *)((int)&pfVar489[0xb86].ofs + uVar30 + 1);
    uVar487 = (uint)(uVar487 != 0);
    pfVar24 = (far_t *)*piVar3;
    iVar488 = *piVar3;
    *piVar3 = (iVar488 - (int)pfVar489) - uVar487;
    uVar487 = (uint)(pfVar24 < pfVar489 || (uint)(iVar488 - (int)pfVar489) < uVar487);
    puVar36 = (undefined2 *)-uVar487;
    pcVar508 = (char *)((int)&pfVar489[6].ofs + uVar30);
    bVar19 = (byte)iVar490;
    *pcVar508 = (*pcVar508 - bVar19) - (uVar487 != 0);
    uVar496 = *puVar36;
    uVar497 = puVar36[2];
    puVar36[2] = uVar497;
    ((undefined2 *)CONCAT22(uVar20,puVar36 + 2))[-2] = uVar497;
    uVar487 = *(uint *)((char *)"elven cottage" + 3);
    uVar484 = uVar30 - *(uint *)((char *)"elven cottage" + 3);
    *pdVar491 = (double)in_ST0;
    *(int *)pdVar491 =
         (int)(CONCAT12(uVar30 < uVar487 || uVar484 < (bVar19 < 0x1e),*(undefined2 *)pdVar491) >> 1)
    ;
    uVar493 = in(iVar490 >> 0xf);
    *(undefined2 *)pdVar491 = uVar493;
    *(byte *)((int)puVar32 + 3) = *(byte *)((int)puVar32 + 3) | (char)uVar484 - (bVar19 < 0x1e);
    uVar23 = pfVar489->seg;
    pcVar4 = (code *)pfVar489->ofs;
    puVar189 = (undefined2 *)((undefined2 *)CONCAT22(uVar20,puVar36 + 2) + -2);
    puVar189[-1] = 0x4000;
    puVar189[-2] = (char *)"You will truly be master of your..." + 0x22;
    pfVar24 = (far_t *)(*pcVar4)();
    pfVar489->ofs = -pfVar489->ofs;
    return pfVar24;
  case 0x2f:
    bVar5 = bVar27 + (byte)(&pfVar24[0x1984].seg)[(int)pfVar25];
    bVar500 = CARRY1(bVar27,(byte)(&pfVar24[0x1984].seg)[(int)pfVar25]) || CARRY1(bVar5,bVar499);
    pbVar1 = (byte *)((int)&pfVar489->ofs + (int)&pfVar37[4].seg);
    bVar27 = bVar29 + *pbVar1;
    bVar498 = CARRY1(bVar29,*pbVar1) || CARRY1(bVar27,bVar500);
    bVar27 = bVar27 + bVar500;
    iVar490 = CONCAT11(bVar5 + bVar499,cVar18) + -1;
    bVar29 = bVar39 + (char)pfVar24->ofs;
    bVar499 = CARRY1(bVar39,(byte)pfVar24->ofs) || CARRY1(bVar29,bVar498);
    bVar29 = bVar29 + bVar498;
    uVar28 = CONCAT11(bVar29,bVar15);
    bVar15 = bVar38 + bVar27;
    bVar39 = bVar15 + bVar499;
    uVar34 = CONCAT11(bVar39,bVar31);
    puVar2 = (uint *)((int)pfVar24 + uVar34 + 0xa211);
    uVar484 = (uint)(CARRY1(bVar38,bVar27) || CARRY1(bVar15,bVar499));
    uVar487 = *puVar2;
    pcVar495 = (char *)((int)&pfVar489->ofs + *puVar2);
    *puVar2 = (uint)(pcVar495 + uVar484);
    puVar2 = (uint *)((int)&pfVar489[0xf83].seg + iVar404 + 1);
    uVar30 = (uint)(CARRY2(uVar487,(uint)pfVar489) || CARRY2((uint)pcVar495,uVar484));
    uVar487 = *puVar2;
    uVar484 = *puVar2;
    *puVar2 = uVar484 + uVar28 + uVar30;
    puVar2 = (uint *)((int)&pfVar24->ofs + uVar34);
    uVar30 = (uint)(CARRY2(uVar487,uVar28) || CARRY2(uVar484 + uVar28,uVar30));
    uVar487 = *puVar2;
    uVar484 = *puVar2;
    *puVar2 = uVar484 + uVar28 + uVar30;
    uVar487 = (uint)(CARRY2(uVar487,uVar28) || CARRY2(uVar484 + uVar28,uVar30));
    puVar485 = (undefined1 *)((int)puVar97 + uVar34 + 0x10);
    bVar499 = CARRY2((uint)((int)puVar97 + 0x10),uVar34) || CARRY2((uint)puVar485,uVar487);
    pfVar506 = pfVar24 + -0x1bfc;
    bVar15 = (char)pfVar506->ofs + bVar39;
    bVar500 = CARRY1((byte)pfVar506->ofs,bVar39) || CARRY1(bVar15,bVar499);
    *(byte *)&pfVar506->ofs = bVar15 + bVar499;
    pbVar1 = (byte *)((int)&pfVar489[4].ofs + uVar34);
    bVar499 = CARRY1(*pbVar1,bVar39) || CARRY1(*pbVar1 + bVar39,bVar500);
    *pbVar1 = *pbVar1 + bVar39 + bVar500;
    *(uint *)(puVar485 + (uVar487 - 2)) = uVar28;
    pbVar1 = (byte *)((int)&pfVar24->ofs + uVar34);
    bVar500 = CARRY1(*pbVar1,bVar39) || CARRY1(*pbVar1 + bVar39,bVar499);
    *pbVar1 = *pbVar1 + bVar39 + bVar499;
    pbVar1 = (byte *)((int)(undefined2 *)&_atexitcnt + iVar488);
    bVar499 = CARRY1(*pbVar1,bVar29) || CARRY1(*pbVar1 + bVar29,bVar500);
    *pbVar1 = *pbVar1 + bVar29 + bVar500;
    bVar500 = 0x97 < bVar19 || CARRY1(bVar19 + 0x68,bVar499);
    bVar15 = bVar19 + 0x68 + bVar499;
    bVar19 = bVar15 + 0x31;
    bVar499 = 0xce < bVar15 || CARRY1(bVar19,bVar500);
    bVar19 = bVar19 + bVar500;
    bVar15 = bVar19 + 0x1e;
    cVar18 = bVar15 + bVar499 + (0xe1 < bVar19 || CARRY1(bVar15,bVar499));
    pcVar508 = (char *)((int)&pfVar489->ofs + uVar34);
    *pcVar508 = *pcVar508 + cVar18;
    pcVar508 = (char *)((int)&pfVar489->ofs + uVar34);
    *pcVar508 = *pcVar508 + cVar18;
    pcVar508 = (char *)((int)&pfVar489->ofs + uVar34);
    *pcVar508 = *pcVar508 + cVar18;
    pcVar508 = (char *)((int)&pfVar489->ofs + uVar34);
    *pcVar508 = *pcVar508 + cVar18;
    pcVar508 = (char *)((int)&pfVar489->ofs + uVar34);
    *pcVar508 = *pcVar508 + cVar18;
    pcVar508 = (char *)((int)&pfVar489->ofs + uVar34);
    *pcVar508 = *pcVar508 + cVar18;
    pcVar508 = (char *)((int)&pfVar489->ofs + uVar34);
    *pcVar508 = *pcVar508 + cVar18;
    pcVar508 = (char *)((int)&pfVar489->ofs + uVar34);
    *pcVar508 = *pcVar508 + cVar18;
    pcVar508 = (char *)((int)&pfVar489->ofs + uVar34);
    *pcVar508 = *pcVar508 + cVar18;
    pcVar508 = (char *)((int)&pfVar489->ofs + uVar34);
    *pcVar508 = *pcVar508 + cVar18;
    pcVar508 = (char *)((int)&pfVar489->ofs + uVar34);
    *pcVar508 = *pcVar508 + cVar18;
    pcVar508 = (char *)((int)&pfVar489->ofs + uVar34);
    *pcVar508 = *pcVar508 + cVar18;
    pcVar508 = (char *)((int)&pfVar489->ofs + uVar34);
    *pcVar508 = *pcVar508 + cVar18;
    pcVar508 = (char *)((int)&pfVar24[-0x1e].seg + 1);
    *pcVar508 = *pcVar508 + (char)iVar490;
    in(iVar490);
    *(undefined2 *)(puVar485 + (uVar487 - 4)) = 0xa000;
    *(undefined2 *)(puVar485 + (uVar487 - 6)) = 0xc306;
    *(undefined2 *)(puVar485 + (uVar487 - 8)) = DAT_2000_cac7;
    *(undefined2 *)(puVar485 + (uVar487 - 10)) = DAT_2000_cac5;
    *(undefined2 *)(puVar485 + (uVar487 - 0xc)) = 0x4000;
    *(undefined2 *)(puVar485 + (uVar487 - 0xe)) = 0x8add;
    pfVar24 = (far_t *)ovr_blitLoadRleGfx(*(far_t *)(puVar485 + (uVar487 - 10)),
                                          *(far_t *)(puVar485 + (uVar487 - 6)));
    DAT_2000_d1ae = 1;
    return pfVar24;
  case 0x30:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x39:
    break;
  case 0x3a:
switchD_4000_f055_caseD_8:
    *(int *)((int)&pfVar24[-0x1c4a].ofs + *(int *)((int)puVar97 + 0x10)) =
         (*(int *)((int)&pfVar24[-0x1c4a].ofs + *(int *)((int)puVar97 + 0x10)) - (int)in_CX) -
         (uint)bVar499;
code_r0x000426dd:
    return pfVar25;
  case 0x3b:
    goto code_r0x000400b4;
  case 0x44:
  case 0x53:
  case 0xce:
    pcVar508 = (char *)((int)&pfVar37->ofs + (int)&pfVar489->ofs);
    *pcVar508 = *pcVar508 + cVar18;
    goto code_r0x0004b801;
  case 0x45:
    uVar23 = (pfVar37 + 0x9c2)->ofs;
    goto code_r0x00042709;
  case 0x46:
  case 0xb3:
  case 0xcb:
    ffree(in_ST1);
    puVar457 = (undefined2 *)((int)puVar97 + 0x10);
    if (in_CX != (uint16_t *)0x0) goto code_r0x0004ff2a;
    puVar457 = (undefined2 *)((int)puVar97 + 0xe);
    *(uint *)((int)puVar97 + 0xe) =
         (uint)(in_NT & 1) * 0x4000 | (uint)(bVar499 != (int)pfVar37 < 0) * 0x800 |
         (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)pfVar37 < 0) * 0x80 |
         (uint)bVar500 * 0x40 | (uint)(in_AF & 1) * 0x10 |
         (uint)((POPCOUNT((uint)pfVar37 & 0xff) & 1U) == 0) * 4 | (uint)bVar499;
    goto code_r0x0004ff2a;
  case 0x47:
    pfVar37->ofs = (uint16_t)(char *)"All levels";
    goto code_r0x0004fe85;
  case 0x55:
LAB_4d05_17b2:
    *(undefined2 *)((int)puVar389 + -2) = *(undefined2 *)(iVar404 + -0x14);
    *(undefined2 *)((int)puVar389 + -4) = *(undefined2 *)(iVar404 + -0x16);
    *(undefined2 *)((int)puVar389 + -6) = pcVar495;
    *(undefined2 *)((int)puVar389 + -8) = 0xe80d;
    ovr_stshFree(*(far_t *)((int)puVar389 + -4));
                    /* WARNING: Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
    return (far_t *)0x0;
  case 0x56:
    *(undefined2 *)((int)puVar97 + 0xe) = pcVar494;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x57:
  case 0xb8:
  case 0xc2:
    cVar18 = in(pcVar21);
    *(char *)&pfVar24->ofs = cVar18;
    *(undefined2 *)((int)puVar97 + 0xe) = 0x4000;
    puVar283 = (undefined2 *)((int)puVar97 + 0xc);
    *(undefined2 *)((int)puVar97 + 0xc) = 0xc489;
    far_t_2000_d098 =
         stshStoreFile((char *)*(undefined2 *)((int)puVar97 + 0x10),
                       *(uint16_t *)((int)puVar97 + 0x14));
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"cmidpak.com";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc4a4;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d096 = fVar503.seg;
    DAT_2000_d094 = fVar503.ofs;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"ibmsnd.com";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc4bf;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0ca = fVar503.seg;
    DAT_2000_d0c8 = fVar503.ofs;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"sblaster.com";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc4da;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0ce = fVar503.seg;
    DAT_2000_d0cc = fVar503.ofs;
    DAT_2000_d0d2 = 0;
    DAT_2000_d0d0 = 0;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"fibmbak.com";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc508;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0d6 = fVar503.seg;
    DAT_2000_d0d4 = fVar503.ofs;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"sbpro.com";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc523;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0da = fVar503.seg;
    DAT_2000_d0d8 = fVar503.ofs;
    DAT_2000_d0dc = DAT_2000_d0d8;
    DAT_2000_d0de = DAT_2000_d0da;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"paudio.com";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc55a;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0e2 = fVar503.seg;
    DAT_2000_d0e0 = fVar503.ofs;
    DAT_2000_d0e6 = DAT_2000_d0ce;
    DAT_2000_d0e4 = DAT_2000_d0cc;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"adlib.com";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc591;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0ea = fVar503.seg;
    DAT_2000_d0e8 = fVar503.ofs;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"adlibg.com";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc5ac;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0ee = fVar503.seg;
    DAT_2000_d0ec = fVar503.ofs;
    DAT_2000_d0f2 = 0;
    DAT_2000_d0f0 = 0;
    DAT_2000_d09e = 0;
    DAT_2000_d09c = 0;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"sbfm.adv";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc5ed;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0a2 = fVar503.seg;
    DAT_2000_d0a0 = fVar503.ofs;
    DAT_2000_d0a6 = 0;
    DAT_2000_d0a4 = 0;
    DAT_2000_d0aa = 0;
    DAT_2000_d0a8 = 0;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"sbp2fm.adv";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc62e;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0ae = fVar503.seg;
    DAT_2000_d0ac = fVar503.ofs;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"sbp1fm.adv";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc649;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0b2 = fVar503.seg;
    DAT_2000_d0b0 = fVar503.ofs;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"pasfm.adv";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc664;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0b6 = fVar503.seg;
    DAT_2000_d0b4 = fVar503.ofs;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"pasopl.adv";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc67f;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0ba = fVar503.seg;
    DAT_2000_d0b8 = fVar503.ofs;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"adlib.adv";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc69a;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0be = fVar503.seg;
    DAT_2000_d0bc = fVar503.ofs;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"adlibg.adv";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc6b5;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0c2 = fVar503.seg;
    DAT_2000_d0c0 = fVar503.ofs;
    puVar283[4] = 1;
    puVar283[3] = (char *)"puppetmaker" + 3;
    puVar283[2] = (char *)"mt32mpu.adv";
    puVar283[1] = 0x4000;
    *puVar283 = 0xc6d0;
    fVar503 = stshStoreFile((char *)puVar283[2],puVar283[4]);
    DAT_2000_d0c6 = fVar503.seg;
    DAT_2000_d0c4 = (uint16_t)(fVar503.ofs);
    return (far_t *)fVar503.ofs;
  case 0x58:
    pfVar37->ofs = pfVar37->ofs & (uint)pfVar25;
                    /* WARNING (jumptable): Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x000247db) is written */
    s_Turn_to_page___d_of_the_manual__2410_06cd[0xe] = '&';
    *(undefined2 *)((int)puVar97 + 0xe) = pcVar494;
    *(undefined2 *)((int)puVar97 + 0xc) = pcVar494;
    *(char *)&pfVar24->ofs = (char)pfVar24->ofs + '\x01';
    puVar136 = (undefined2 *)((int)puVar97 + 10);
    *(undefined2 *)((int)puVar97 + 10) = (char *)"Select the character\'s name." + 0x16;
    func_0x00041e28();
  case 0x7a:
    *(undefined2 *)((int)puVar136 + -2) = 0x4000;
    *(undefined2 *)((int)puVar136 + -4) =
         (char *)"Please type your character\'s name. Esc go back." + 1;
    cVar18 = func_0x00069e55();
    *(byte *)&pfVar24->ofs = (char)pfVar24->ofs + ((cVar18 + 0x4aU ^ 5) - (char)pfVar24->ofs);
    in(4);
    pcVar6 = (code *)swi(3);
    pfVar24 = (far_t *)(*pcVar6)();
    return pfVar24;
  case 0x5b:
  case 0x7d:
    if (in_CX == (uint16_t *)0x0) {
      in_AF = 9 < (bVar19 & 0xf) | in_AF;
      bVar499 = 0x99 < bVar19 || bVar499;
      pfVar25 = (far_t *)((uint)bVar29 << 8);
    }
    cVar16 = (char)((uint)pfVar25 >> 8);
    bVar19 = -bVar499;
    piVar22 = (int *)((int)pfVar37 - CONCAT11(cVar16,bVar19));
    *(int *)((char *)((int)piVar22 + (int)pfVar24) + -0x6bd7) =
         *(int *)((char *)((int)piVar22 + (int)pfVar24) + -0x6bd7) - (iVar404 + -2);
    *(int *)((int)piVar22 + 0x29) = *(int *)((int)piVar22 + 0x29) - (int)pfVar24;
    *(undefined2 *)((int)puVar97 + 0xe) = pfVar24;
    *(int *)((char *)((int)piVar22 + (int)pfVar489) + 0x29) =
         *(int *)((char *)((int)piVar22 + (int)pfVar489) + 0x29) - (int)in_CX;
    in_AF = 9 < (bVar19 & 0xf) | in_AF;
    bVar19 = bVar19 + in_AF * -6 +
             (0x99 < bVar19 || *(byte *)((int)piVar22 + (int)pfVar24) < bVar39) * -0x60;
    *(int *)(iVar404 + -2 + (int)pfVar24) =
         *(int *)(iVar404 + -2 + (int)pfVar24) - (int)((int)puVar97 + 0xe);
    *(int *)(iVar404 + -2 + (int)pfVar24) = *(int *)(iVar404 + -2 + (int)pfVar24) - (int)pcVar21;
    *piVar22 = *piVar22 - CONCAT11(cVar16,bVar19);
    iVar26 = (int)pfVar489 - (int)pfVar24;
    cVar18 = cVar18 - bVar15;
    uVar20 = CONCAT11(bVar27,cVar18);
    *(char *)((int)pfVar24 + iVar404 + -0x5dda) =
         *(char *)((int)pfVar24 + iVar404 + -0x5dda) - (char)((uint)piVar22 >> 8);
    *(char *)(iVar404 + 0x6c26) = *(char *)(iVar404 + 0x6c26) - cVar18;
    *(char *)&(pfVar24 + 10)->ofs = (char)(pfVar24 + 10)->ofs - cVar16;
    uVar23 = in(uVar20);
    pfVar24->ofs = uVar23;
    iVar488 = in(uVar20);
    iVar490 = CONCAT11(0x2e,(char)piVar22);
    bVar15 = (char)(char *)(iVar488 + -0x5b3f) - 0x3a;
    cVar16 = (bVar15 + (9 < (bVar15 & 0xf) | 9 < (bVar19 & 0xf) | in_AF) * '\x06' +
              (0x99 < bVar15 || (char *)(iVar488 + -0x5b3f) < (char *)"anim\\nubats.lbm" + 9) * '`'
             + 'F') - (char)*(undefined2 *)(iVar490 + iVar26);
    *(char *)(iVar490 + iVar26) = *(char *)(iVar490 + iVar26) + cVar16;
    *(char *)(iVar490 + iVar26) = *(char *)(iVar490 + iVar26) + cVar16;
    *(char *)(iVar490 + iVar26) = *(char *)(iVar490 + iVar26) + cVar16;
    *(char *)(iVar490 + iVar26) = *(char *)(iVar490 + iVar26) + cVar16;
    *(char *)(iVar490 + iVar26) = *(char *)(iVar490 + iVar26) + cVar16;
    *(char *)(iVar490 + iVar26) = *(char *)(iVar490 + iVar26) + cVar16;
    *(char *)(iVar490 + iVar26) = *(char *)(iVar490 + iVar26) + cVar16;
    *(char *)(iVar490 + iVar26) = *(char *)(iVar490 + iVar26) + cVar16;
    *(char *)(iVar490 + iVar26) = *(char *)(iVar490 + iVar26) + cVar16;
    *(char *)(iVar490 + iVar26) = *(char *)(iVar490 + iVar26) + cVar16;
    *(char *)(iVar490 + iVar26) = *(char *)(iVar490 + iVar26) + cVar16;
    *(char *)(iVar490 + iVar26) = *(char *)(iVar490 + iVar26) + cVar16;
    pcVar508 = (char *)((int)&pfVar24[-0x1d].ofs + 1);
    *pcVar508 = *pcVar508 + cVar18;
    in(uVar20);
    *(int *)((int)puVar97 + 6) = iVar26;
    *(int *)((int)puVar97 + 4) = (int)&pfVar24->seg;
    MiceUnkState = 0;
    *(undefined2 *)((int)puVar97 + 2) = 0x4000;
    *(char **)puVar97 = (char *)"All property." + 5;
    ovr_init2_3338_0401();
    MiceProcessed = 0;
    *(undefined2 *)((int)puVar97 + 2) = (char *)"puppetmaker" + 3;
    *(undefined2 *)puVar97 = 0x44a;
    *(undefined2 *)((int)puVar97 + -2) = (char *)"public baths" + 10;
    puVar137 = puVar97 + -1;
    *(char **)(puVar97 + -1) = (char *)"Buildings belonging to %s%s" + 0xd;
    ovr_miceBlitRect((brect_t *)*puVar97);
    puVar138 = (undefined1 *)((int)puVar137 + 8);
    *(undefined1 *)0x9f2c = 0;
    iVar490 = DAT_2410_00e6;
    iVar488 = DAT_2410_00e4;
    DAT_2410_00e8 = 0;
    while( true ) {
      pcVar495 = (char *)"public baths" + 10;
      if ((*(int *)(BDA_DailyTimeCounter.ofs + 2) != *(int *)0x9f29) ||
         (*(int *)BDA_DailyTimeCounter != *(int *)0x9f27)) {
        uVar20 = *(undefined2 *)BDA_DailyTimeCounter;
        *(undefined2 *)0x9f29 = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
        *(undefined2 *)0x9f27 = uVar20;
        *(char **)(puVar138 + -2) = (char *)"public baths" + 10;
        puVar139 = (undefined2 *)(puVar138 + -4);
        *(char **)(puVar138 + -4) =
             (char *)"The %s belonging to %s the %s are highlighted in red." + 0x1f;
        ovr_draw_2e25_046b();
        puVar139[1] = (char *)"fletcher\'s shop" + 0xd;
        pcVar495 = (char *)"jeweler" + 6;
        *puVar139 = (char *)"The %s belonging to %s the %s are highlighted in red." + 0x24;
        ovr_OVC13_3d16_005b();
        puVar138 = (undefined1 *)((int)puVar139 + 4);
      }
      *(char **)(puVar138 + -2) = pcVar495;
      puVar140 = (undefined4 *)(puVar138 + -4);
      *(char **)(puVar138 + -4) =
           (char *)"The %s belonging to %s the %s are highlighted in red." + 0x29;
      uVar23 = ovr_biosKeyAvail();
      if ((char)uVar23 != '\0') break;
      *(undefined2 *)((int)puVar140 + 2) = (char *)"puppetmaker" + 3;
      *(undefined2 *)puVar140 = 0xe6;
      *(undefined2 *)((int)puVar140 + -2) = (char *)"puppetmaker" + 3;
      *(undefined2 *)(puVar140 + -1) = 0xe4;
      *(undefined2 *)((int)puVar140 + -6) = (char *)"arrowsmith" + 3;
      puVar143 = puVar140 + -2;
      *(char **)(puVar140 + -2) =
           (char *)"The %s belonging to all leaders are highlighted in red." + 0x28;
      iVar26 = ovr_init2_3338_0388();
      puVar138 = (undefined1 *)((int)puVar143 + 0xc);
      if (iVar26 == 0) {
        *(undefined1 *)0x9f2c = 1;
      }
      else if (((*(char *)0x9f2c != '\0') || (DAT_2410_00e4 != iVar488)) ||
              (DAT_2410_00e6 != iVar490)) {
        if (*(char *)0x9f2c == '\0') {
          DAT_2410_00e8 = 1;
        }
        *(undefined2 *)((int)puVar143 + 10) = (char *)"puppetmaker" + 3;
        *(undefined2 *)((int)puVar143 + 8) = 0x44a;
        *(undefined2 *)((int)puVar143 + 6) = (char *)"public baths" + 10;
        puVar144 = (undefined1 *)((int)puVar143 + 4);
        *(undefined2 *)((int)puVar143 + 4) =
             (char *)"The damaged structures belonging to %s the %s are highlighted in red." + 0x35;
        ovr_miceRestoreArea((brect_t *)*(undefined4 *)((int)puVar143 + 8));
        DAT_2410_00ea = *(undefined1 *)(DAT_2410_00e6 * 0x140 + DAT_2410_00e4);
        *(char **)(puVar144 + 6) = (char *)"public baths" + 10;
        puVar145 = (undefined2 *)(puVar144 + 4);
        *(char **)(puVar144 + 4) =
             (char *)"The damaged structures belonging to all leaders are highlighted in red." +
             0x22;
        ovr_draw_2e25_0573();
        puVar145[1] = (char *)"fletcher\'s shop" + 0xd;
        *puVar145 = (char *)
                    "The damaged structures belonging to all leaders are highlighted in red." + 0x27
        ;
        ovr_font_302d_0a30();
        return (far_t *)0xffff;
      }
      if (DAT_2000_ccaf != '\0') {
        *(undefined2 *)((int)puVar143 + 10) = (char *)"puppetmaker" + 3;
        *(undefined2 *)((int)puVar143 + 8) = 0x44a;
        *(undefined2 *)((int)puVar143 + 6) = (char *)"public baths" + 10;
        puVar146 = (undefined1 *)((int)puVar143 + 4);
        *(undefined2 *)((int)puVar143 + 4) = (char *)"level 1" + 5;
        ovr_miceRestoreArea((brect_t *)*(undefined4 *)((int)puVar143 + 8));
        DAT_2410_00ea = *(undefined1 *)(DAT_2410_00e6 * 0x140 + DAT_2410_00e4);
        *(char **)(puVar146 + 6) = (char *)"public baths" + 10;
        puVar147 = (undefined2 *)(puVar146 + 4);
        *(char **)(puVar146 + 4) = (char *)"levels 11-15" + 4;
        ovr_draw_2e25_0573();
        puVar147[1] = (char *)"fletcher\'s shop" + 0xd;
        *puVar147 = (char *)"levels 11-15" + 9;
        ovr_font_302d_0a30();
                    /* WARNING: Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
        return (far_t *)0xfffe;
      }
    }
    *(undefined2 *)((int)puVar140 + 2) = (char *)"puppetmaker" + 3;
    *(undefined2 *)puVar140 = 0x44a;
    *(undefined2 *)((int)puVar140 + -2) = (char *)"arrowsmith" + 3;
    puVar141 = puVar140 + -1;
    *(char **)(puVar140 + -1) =
         (char *)"The %s belonging to all leaders are highlighted in red." + 2;
    ovr_miceRestoreArea((brect_t *)*puVar140);
    *(undefined2 *)((int)puVar141 + 6) = (char *)"public baths" + 10;
    puVar142 = (undefined2 *)((int)puVar141 + 4);
    *(undefined2 *)((int)puVar141 + 4) =
         (char *)"The %s belonging to all leaders are highlighted in red." + 10;
    ovr_draw_2e25_0573();
    puVar142[1] = (char *)"fletcher\'s shop" + 0xd;
    *puVar142 = (char *)"The %s belonging to all leaders are highlighted in red." + 0xf;
    ovr_font_302d_0a30();
    puVar142[1] = (char *)"steam bath" + 6;
    *puVar142 = (char *)"The %s belonging to all leaders are highlighted in red." + 0x14;
    pfVar24 = (far_t *)ovr_gameProcessKey();
    return pfVar24;
  case 0x5c:
  case 0x7e:
    do {
      if (*(char *)((*pfVar37).ofs + 0x3f) ==
          *(char *)((int)*(undefined4 *)((uint)*(byte *)(iVar404 + 4) << 2) + 0x3f)) {
                    /* WARNING: Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
        return (far_t *)(uint)*(byte *)(iVar404 + -4);
      }
      do {
        *(char *)(iVar404 + -4) = *(char *)(iVar404 + -4) + '\x01';
        if (DAT_2000_d1e6 <= *(byte *)(iVar404 + -4)) {
          *(undefined1 *)(iVar404 + -4) = 0;
        }
        if (*(char *)(iVar404 + -4) == *(char *)(iVar404 + 4)) {
          return (far_t *)(GUnitDescriptions + 5);
        }
      } while ((((DAT_2000_d1e6 <= *(byte *)(iVar404 + -4)) ||
                (*(char *)(iVar404 + -4) == *(char *)(iVar404 + -3))) ||
               (*(char *)(iVar404 + -4) == *(char *)(iVar404 + 4))) ||
              (*(char *)((int)*(undefined4 *)((uint)*(byte *)(iVar404 + -4) << 2) + 0x3d) == '\0'));
      pfVar37 = (far_t *)((uint)*(byte *)(iVar404 + -4) << 2);
      pcVar494 = (char *)"halfling castle" + 0xc;
    } while( true );
  case 0x5e:
  case 0x80:
    *(char *)(iVar404 + iVar488 + 2) = cVar18;
                    /* WARNING: Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
    return (far_t *)CONCAT11(bVar29,cVar18);
  case 0x5f:
  case 0x81:
    pcVar494 = (char *)*(undefined2 *)((int)puVar97 + 0x10);
    puVar58 = (undefined2 *)((int)puVar97 + 0x12);
    goto code_r0x00040300;
  case 0x60:
  case 0x82:
  case 0x99:
  case 0xaf:
    return pfVar25;
  case 0x66:
    puVar35 = in_CX;
  case 0xa1:
    puVar114 = puVar35;
    goto code_r0x000426ec;
  case 0x6a:
    iVar488 = *(int *)(iVar404 + -4);
    *(undefined2 *)((int)puVar97 + 0xe) = 0x1726;
    *(int *)((int)puVar97 + 0xc) = iVar488 * 0x34;
    *(undefined2 *)((int)puVar97 + 10) =
         CONCAT11((char)((uint)(iVar488 * 0x34) >> 8),*(char *)(iVar404 + -4) + '\x01');
    *(undefined2 *)((int)puVar97 + 8) = 0x4000;
    *(undefined2 *)((int)puVar97 + 6) = (char *)"build\\tree05.lbm" + 3;
    ovr_OVC49_8699_1753();
    AgntCount = AgntCount + 1;
    for (iVar488 = 0; iVar488 < (int)(uint)AgntCount; iVar488 = iVar488 + 1) {
      if ((*(char *)(iVar488 * 0x34 + 0xc) != -1) &&
         (*(int *)(iVar404 + -4) <= (int)(uint)*(byte *)(iVar488 * 0x34 + 0xc))) {
        pcVar508 = (char *)(iVar488 * 0x34 + 0xc);
        *pcVar508 = *pcVar508 + '\x01';
      }
    }
    return (far_t *)((int)(undefined4 *)&_DATA + 1);
  case 0x6e:
  case 0x96:
  case 0xac:
    goto code_r0x00048bea;
  case 0x6f:
  case 0xde:
  case 0xf9:
    *(undefined2 *)((int)puVar97 + 0xe) = pfVar489;
    *(undefined2 *)((int)puVar97 + 0xc) = pcVar494;
    *(undefined2 *)(iVar404 + -4) = pfVar25;
    *(undefined2 *)(iVar404 + -6) = pcVar21;
    uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
    iVar488 = (int)*(undefined4 *)(iVar404 + -6);
    *(undefined2 *)(iVar488 + 0x13) = 0;
    *(undefined2 *)(iVar488 + 0x11) = 0;
    return pfVar25;
  case 0x70:
  case 0xdf:
  case 0xfa:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x76:
    puVar208 = (undefined2 *)((int)puVar97 + 0x12);
    break;
  case 0x77:
    goto code_r0x000426df;
  case 0x79:
    puVar307 = (undefined2 *)((int)puVar97 + 0x10);
    *(undefined2 *)((int)puVar97 + 0x10) = pcVar494;
    goto LAB_4d05_093e;
  case 0x88:
    goto code_r0x0004e797;
  case 0x8c:
    *(undefined2 *)((int)puVar97 + 0xe) = 0x4000;
    puVar200 = (undefined2 *)((int)puVar97 + 0xc);
    *(undefined2 *)((int)puVar97 + 0xc) = (char *)"house2.txt" + 1;
    uVar504 = ovr_mkp(*(uint16_t *)((int)puVar97 + 0x10),*(uint16_t *)((int)puVar97 + 0x12));
    *(undefined2 *)(iVar404 + 6) = (int)(uVar504 >> 0x10);
    *(undefined2 *)(iVar404 + 4) = (int)uVar504;
    if (*(char *)*(undefined4 *)(iVar404 + 4) == '\0') {
      uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
      iVar488 = (int)*(undefined4 *)(iVar404 + 4);
      puVar200[3] = *(undefined2 *)(iVar488 + 7);
      puVar200[2] = *(undefined2 *)(iVar488 + 5);
      puVar200[1] = (char *)"arrowsmith" + 3;
      *puVar200 = (char *)"house5.txt" + 10;
      fVar503 = fmMalloc(*(uint32_t *)(puVar200 + 2));
      *(uint16_t *)(iVar404 + -0xc) = fVar503.seg;
      *(uint16_t *)(iVar404 + -0xe) = fVar503.ofs;
      if (*(int *)(iVar404 + -0xe) == 0 && *(int *)(iVar404 + -0xc) == 0) {
        pfVar24 = (far_t *)0x0;
      }
      else {
        uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
        iVar488 = (int)*(undefined4 *)(iVar404 + 4);
        if (*(int *)(iVar488 + 0x11) == 0 && *(int *)(iVar488 + 0x13) == 0) {
          uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
          iVar488 = (int)*(undefined4 *)(iVar404 + 4);
          puVar200[3] = *(undefined2 *)(iVar488 + 3);
          puVar200[2] = *(undefined2 *)(iVar488 + 1);
          puVar200[1] = StshStrongDatHnd;
          *puVar200 = (char *)"arrowsmith" + 3;
          puVar203 = puVar200 + -1;
          puVar200[-1] = (char *)"incom5.txt" + 6;
          stshSeek(puVar200[1],*(long *)(puVar200 + 3));
          uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
          iVar488 = (int)*(undefined4 *)(iVar404 + 4);
          puVar203[4] = *(undefined2 *)(iVar488 + 7);
          puVar203[3] = *(undefined2 *)(iVar488 + 5);
          puVar203[2] = *(undefined2 *)(iVar404 + -0xc);
          puVar203[1] = *(undefined2 *)(iVar404 + -0xe);
          *puVar203 = StshStrongDatHnd;
          puVar203[-1] = (uint16_t)((char *)"arrowsmith" + 3);
          puVar204 = puVar203 + -2;
          puVar203[-2] = (uint16_t)((char *)"cflow3.txt" + 7);
          stshRead(*puVar203,*(far_t *)(puVar203 + 1),*(long *)(puVar203 + 3));
          uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
          iVar488 = (int)*(undefined4 *)(iVar404 + 4);
          *(undefined2 *)((int)puVar204 + 0xc) = *(undefined2 *)(iVar488 + 7);
          *(undefined2 *)((int)puVar204 + 10) = *(undefined2 *)(iVar488 + 5);
          *(undefined2 *)((int)puVar204 + 8) = (char *)"arrowsmith" + 3;
          pcVar495 = (char *)"money dealer\'s shop" + 8;
          puVar205 = (undefined2 *)((int)puVar204 + 6);
          *(undefined2 *)((int)puVar204 + 6) = (char *)"cflow5.txt" + 4;
          fVar503 = far_from_u32((uint32_t)ovr_heapMalloc(*(uint32_t *)((int)puVar204 + 10)));
          puVar202 = puVar205 + 4;
          uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
          iVar488 = (int)*(undefined4 *)(iVar404 + 4);
          *(uint16_t *)(iVar488 + 0x13) = fVar503.seg;
          *(uint16_t *)(iVar488 + 0x11) = fVar503.ofs;
          uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
          iVar488 = (int)*(undefined4 *)(iVar404 + 4);
          if (*(int *)(iVar488 + 0x11) == 0 && *(int *)(iVar488 + 0x13) == 0) {
            *(undefined1 *)(iVar404 + -0xf) = 0;
          }
          else {
            puVar205[3] = *(undefined2 *)((int)*(undefined4 *)(iVar404 + 4) + 5);
            puVar205[2] = *(undefined2 *)(iVar404 + -0xc);
            puVar205[1] = *(undefined2 *)(iVar404 + -0xe);
            uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
            iVar488 = (int)*(undefined4 *)(iVar404 + 4);
            *puVar205 = *(undefined2 *)(iVar488 + 0x13);
            puVar205[-1] = *(undefined2 *)(iVar488 + 0x11);
            puVar205[-2] = (char *)"money dealer\'s shop" + 8;
            pcVar495 = (char *)0x1000;
            puVar206 = puVar205 + -3;
            puVar205[-3] = (char *)"%s is no longer paralyzed." + 0x12;
            memcpy((uint8_t *)puVar205[-1],(uint8_t *)puVar205[1],puVar205[3]);
            puVar202 = (undefined2 *)((int)puVar206 + 0xe);
            *(undefined1 *)(iVar404 + -0xf) = 1;
          }
        }
        else {
          puVar200[3] = *(undefined2 *)((int)*(undefined4 *)(iVar404 + 4) + 5);
          uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
          iVar488 = (int)*(undefined4 *)(iVar404 + 4);
          puVar200[2] = *(undefined2 *)(iVar488 + 0x13);
          puVar200[1] = *(undefined2 *)(iVar488 + 0x11);
          *puVar200 = *(undefined2 *)(iVar404 + -0xc);
          puVar200[-1] = *(undefined2 *)(iVar404 + -0xe);
          puVar200[-2] = (char *)"arrowsmith" + 3;
          pcVar495 = (char *)0x1000;
          puVar201 = puVar200 + -3;
          puVar200[-3] = (char *)"incom2.txt" + 4;
          memcpy((uint8_t *)puVar200[-1],(uint8_t *)puVar200[1],puVar200[3]);
          puVar202 = (undefined2 *)((int)puVar201 + 0xe);
          *(undefined1 *)(iVar404 + -0xf) = 1;
        }
        if (*(char *)(iVar404 + -0xf) != '\0') {
          *(uint16_t *)((int)puVar202 + -2) = Stsh_2410_47f6.seg;
          *(uint16_t *)((int)puVar202 + -4) = Stsh_2410_47f6.ofs;
          *(undefined2 *)((int)puVar202 + -6) = pcVar495;
          puVar207 = (undefined1 *)((int)puVar202 + -8);
          *(undefined2 *)((int)puVar202 + -8) =
               (char *)"%s regenerates 3 hitpoints to a total of %d hitpoints." + 6;
          uVar504 = ovr_mkp(*(uint16_t *)((int)puVar202 + -4),*(uint16_t *)((int)puVar202 + -2));
          if (((int)(uVar504 >> 0x10) != *(int *)(iVar404 + 6)) ||
             ((int)uVar504 != *(int *)(iVar404 + 4))) {
            uVar493 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
            iVar488 = (int)*(undefined4 *)(iVar404 + 4);
            uVar20 = *(undefined2 *)(iVar488 + 0xd);
            *(undefined2 *)(iVar404 + -8) = *(undefined2 *)(iVar488 + 0xf);
            *(undefined2 *)(iVar404 + -10) = uVar20;
            uVar493 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
            iVar488 = (int)*(undefined4 *)(iVar404 + 4);
            uVar20 = *(undefined2 *)(iVar488 + 9);
            *(undefined2 *)(iVar404 + -4) = *(undefined2 *)(iVar488 + 0xb);
            *(undefined2 *)(iVar404 + -6) = uVar20;
            if (*(int *)(iVar404 + -6) != 0 || *(int *)(iVar404 + -4) != 0) {
              uVar493 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
              iVar488 = (int)*(undefined4 *)(iVar404 + -6);
              uVar20 = *(undefined2 *)(iVar404 + -10);
              *(undefined2 *)(iVar488 + 0xf) = *(undefined2 *)(iVar404 + -8);
              *(undefined2 *)(iVar488 + 0xd) = uVar20;
            }
            if (*(int *)(iVar404 + -10) == 0 && *(int *)(iVar404 + -8) == 0) {
              StshCtPtr2.seg = *(uint16_t *)(iVar404 + -4);
              StshCtPtr2.ofs = *(uint16_t *)(iVar404 + -6);
            }
            else {
              uVar493 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -10) >> 0x10);
              iVar488 = (int)*(undefined4 *)(iVar404 + -10);
              uVar20 = *(undefined2 *)(iVar404 + -6);
              *(undefined2 *)(iVar488 + 0xb) = *(undefined2 *)(iVar404 + -4);
              *(undefined2 *)(iVar488 + 9) = uVar20;
            }
            iVar488 = (int)*(undefined4 *)(iVar404 + 4);
            *(int *)(puVar207 + 6) = (int)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
            uVar23 = Stsh_2410_47f6.ofs;
            uVar20 = *(undefined2 *)(puVar207 + 6);
            *(uint16_t *)(iVar488 + 0xf) = Stsh_2410_47f6.seg;
            *(uint16_t *)(iVar488 + 0xd) = uVar23;
            uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + 4) >> 0x10);
            iVar488 = (int)*(undefined4 *)(iVar404 + 4);
            *(undefined2 *)(iVar488 + 0xb) = 0;
            *(undefined2 *)(iVar488 + 9) = 0;
            uVar20 = *(undefined2 *)(iVar404 + 4);
            *(undefined2 *)(Stsh_2410_47f6.ofs + 0xb) = *(undefined2 *)(iVar404 + 6);
            *(undefined2 *)(Stsh_2410_47f6.ofs + 9) = uVar20;
            Stsh_2410_47f6.seg = *(uint16_t *)(iVar404 + 6);
            Stsh_2410_47f6.ofs = *(uint16_t *)(iVar404 + 4);
          }
        }
        pfVar24 = (far_t *)*(undefined2 *)(iVar404 + -0xe);
      }
    }
    else {
      pfVar24 = (far_t *)*(undefined2 *)(iVar404 + 4);
    }
    return pfVar24;
  case 0x8d:
    uVar17 = in(0x26);
    pfVar25 = (far_t *)CONCAT11(bVar29,uVar17);
    pfVar37->ofs = (uint16_t)((int)&pfVar25->ofs + pfVar37->ofs);
    puVar58 = (undefined2 *)((int)puVar97 + 0x10);
    goto code_r0x00040300;
  case 0x8e:
    goto code_r0x0004037f;
  case 0x8f:
    do {
      *(undefined2 *)(iVar404 + -0x18) = pfVar25;
      puVar103 = puVar102;
      while( true ) {
        while( true ) {
          *(undefined1 *)*(undefined4 *)(iVar404 + -0x20) = 4;
          uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -0x20) >> 0x10);
          iVar488 = (int)*(undefined4 *)(iVar404 + -0x20);
          *(undefined2 *)(iVar488 + 3) = 0;
          *(undefined2 *)(iVar488 + 1) = 0;
          *(int *)(iVar404 + -6) =
               *(int *)(iVar404 + -6) +
               (uint)*(byte *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 10);
          *(int *)(iVar404 + -10) =
               *(int *)(iVar404 + -10) +
               (uint)*(byte *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 10);
          bVar499 = *(uint *)(iVar404 + -10) < 200;
code_r0x0004234c:
          if (!bVar499) {
            *(uint *)((int)puVar103 + -2) =
                 (uint)*(byte *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 10);
            *(int *)(iVar404 + -6) =
                 *(int *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 3) %
                 *(int *)((int)puVar103 + -2);
            *(int *)(iVar404 + -10) = *(int *)(iVar404 + -6) + *(int *)(iVar404 + -0xe);
            *(int *)(iVar404 + -4) =
                 *(int *)(iVar404 + -4) +
                 (uint)*(byte *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 9);
            *(int *)(iVar404 + -8) =
                 *(int *)(iVar404 + -8) +
                 (uint)*(byte *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 9);
            *(int *)(iVar404 + -0x16) =
                 *(int *)(iVar404 + -0x16) +
                 (uint)*(byte *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 9);
            *(int *)(iVar404 + -0x18) =
                 *(int *)(iVar404 + -0x18) +
                 (uint)*(byte *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 9);
          }
          *(int *)(iVar404 + -0x14) = *(int *)(iVar404 + -0x14) + 1;
          while ((uint)*(byte *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 0x1b) <=
                 *(uint *)(iVar404 + -0x14)) {
            if (*(int *)(iVar404 + -0x12) != 0 || *(int *)(iVar404 + -0x10) != 0) {
              *(char *)*(undefined4 *)(iVar404 + -0x12) =
                   *(char *)(iVar404 + -0x18) - *(char *)(iVar404 + -0x16);
            }
            pfVar489 = (far_t *)((int)&pfVar489->ofs + 1);
            if (((far_t *)*(undefined2 *)(iVar404 + 0xc) <= pfVar489) ||
               (*(char *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 0x1b) == '\0'))
            goto LAB_4207_03a2;
            *(uint *)(iVar404 + -0x1c) =
                 (uint)*(byte *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e);
            iVar488 = *(int *)(iVar404 + -0x1c);
            iVar490 = *(int *)(iVar404 + -0x28);
            *(undefined2 *)(iVar404 + -0x22) = *(undefined2 *)(iVar404 + -0x26);
            *(int *)(iVar404 + -0x24) = iVar490 + iVar488 * 4 + 0x58;
            iVar488 = *(int *)(iVar404 + 8);
            iVar490 = *(int *)(iVar404 + -0x1c);
            uVar20 = *(undefined2 *)(iVar404 + -0x26);
            *(undefined2 *)((int)puVar103 + -2) = *(undefined2 *)(iVar404 + 10);
            *(int *)((int)puVar103 + -4) = iVar488 + (int)pfVar489 * 0x1e;
            puVar36 = (undefined2 *)(*(int *)(iVar404 + -0x28) + iVar490 * 4);
            uVar493 = *(undefined2 *)((int)puVar103 + -4);
            puVar36[1] = *(undefined2 *)((int)puVar103 + -2);
            *puVar36 = uVar493;
            *(undefined2 *)(iVar404 + -4) =
                 *(undefined2 *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 1);
            *(undefined2 *)(iVar404 + -6) =
                 *(undefined2 *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 3);
            *(undefined2 *)(iVar404 + -8) =
                 *(undefined2 *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 5);
            *(undefined2 *)(iVar404 + -10) =
                 *(undefined2 *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 7);
            *(int *)(iVar404 + -0xe) = *(int *)(iVar404 + -10) - *(int *)(iVar404 + -6);
            if (*(int *)(iVar404 + -0xe) < 0) {
              *(undefined2 *)((int)puVar103 + -2) = 0x33;
                    /* WARNING: Subroutine does not return */
              *(undefined2 *)((int)puVar103 + -4) = pcVar495;
              *(undefined2 *)((int)puVar103 + -6) = (char *)"corner wall";
              ovr_stExit(*(int *)((int)puVar103 + -2));
            }
            *(undefined2 *)(iVar404 + -0x10) = 0;
            *(undefined2 *)(iVar404 + -0x12) = 0;
            *(undefined2 *)(iVar404 + -0x14) = 0;
          }
          *(undefined2 *)((int)puVar103 + -2) = 0x15;
          *(undefined2 *)((int)puVar103 + -4) = *(undefined2 *)(iVar404 + -10);
          *(undefined2 *)((int)puVar103 + -6) = *(undefined2 *)(iVar404 + -8);
          *(undefined2 *)((int)puVar103 + -8) = *(undefined2 *)(iVar404 + -6);
          *(undefined2 *)((int)puVar103 + -10) = *(undefined2 *)(iVar404 + -4);
          *(undefined2 *)((int)puVar103 + -0xc) = *(undefined2 *)(iVar404 + 6);
          *(undefined2 *)((int)puVar103 + -0xe) = *(undefined2 *)(iVar404 + 4);
          *(undefined2 *)((int)puVar103 + -0x10) = pcVar495;
          pcVar495 = (char *)"bath house" + 10;
          puVar101 = (undefined1 *)((int)puVar103 + -0x12);
          *(undefined2 *)((int)puVar103 + -0x12) = (char *)"sturdy corner wall" + 2;
          fVar503 = ovr_stshRleSub((uint8_t *)*(undefined4 *)((int)puVar103 + -0xe),
                                   *(uint16_t *)((int)puVar103 + -10),
                                   *(uint16_t *)((int)puVar103 + -8),
                                   *(uint16_t *)((int)puVar103 + -6),
                                   *(uint16_t *)((int)puVar103 + -4),
                                   *(int16_t *)((int)puVar103 + -2));
          puVar102 = (undefined2 *)(puVar101 + 0x12);
          *(uint16_t *)(iVar404 + -0x1e) = fVar503.seg;
          *(uint16_t *)(iVar404 + -0x20) = fVar503.ofs;
          *(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x20) + 6) = 2;
          *(undefined2 *)((int)*(undefined4 *)(iVar404 + -0x20) + 7) =
               *(undefined2 *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 0xb);
          *(undefined2 *)((int)*(undefined4 *)(iVar404 + -0x20) + 9) =
               *(undefined2 *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 0xd);
          puVar7 = (undefined2 *)*(undefined4 *)(iVar404 + -0x24);
          uVar20 = *(undefined2 *)(iVar404 + -0x20);
          ((undefined2 *)puVar7)[1] = *(undefined2 *)(iVar404 + -0x1e);
          *puVar7 = uVar20;
          iVar488 = *(int *)(iVar404 + -0x20);
          *(undefined2 *)(iVar404 + -0x22) = *(undefined2 *)(iVar404 + -0x1e);
          *(int *)(iVar404 + -0x24) = iVar488 + 1;
          if ((*(byte *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 0x1c) & 1) != 0)
          break;
          *(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x20) + 5) =
               *(undefined1 *)((int)*(undefined4 *)(iVar404 + 8) + (int)pfVar489 * 0x1e + 0xf);
          puVar103 = (undefined2 *)(puVar101 + 0x12);
        }
        *(int *)(iVar404 + -0xc) = *(int *)(iVar404 + -10) * 0x140 + 0x140;
        if (*(int *)(iVar404 + -0x14) != 0) break;
        uVar487 = 0;
        *(undefined2 *)(iVar404 + -0x1a) = *(undefined2 *)(iVar404 + -4);
        while (uVar487 < 2) {
          if ((uint)(*(int *)(iVar404 + -8) + *(int *)(iVar404 + -0xc)) < *(uint *)(iVar404 + -0x1a)
             ) {
            *(undefined2 *)(puVar101 + 0x10) = 9;
                    /* WARNING: Subroutine does not return */
            *(char **)(puVar101 + 0xe) = (char *)"bath house" + 10;
            *(char **)(puVar101 + 0xc) = (char *)"manned n/s gate" + 6;
            ovr_stExit(*(int *)(puVar101 + 0x10));
          }
          if (*(char *)((int)*(undefined4 *)(iVar404 + 4) +
                       *(int *)(iVar404 + -0x1a) + *(int *)(iVar404 + -0xc)) == -2) {
            if (uVar487 == 0) {
              *(undefined2 *)(iVar404 + -0x16) = *(undefined2 *)(iVar404 + -0x1a);
            }
            else {
              *(undefined2 *)(iVar404 + -0x18) = *(undefined2 *)(iVar404 + -0x1a);
            }
            uVar487 = uVar487 + 1;
          }
          *(int *)(iVar404 + -0x1a) = *(int *)(iVar404 + -0x1a) + 1;
        }
        iVar488 = *(int *)(iVar404 + -0x20);
        *(undefined2 *)(iVar404 + -0x10) = *(undefined2 *)(iVar404 + -0x1e);
        *(int *)(iVar404 + -0x12) = iVar488 + 5;
        puVar103 = (undefined2 *)(puVar101 + 0x12);
      }
      *(undefined2 *)(iVar404 + -0x1a) = *(undefined2 *)(iVar404 + -4);
      while( true ) {
        pfVar25 = (far_t *)*(undefined2 *)(iVar404 + -0x1a);
        puVar14 = puVar102;
code_r0x000422cb:
        puVar102 = puVar14;
        if (*(char *)((int)&pfVar25->ofs +
                     (int)*(undefined4 *)(iVar404 + 4) + *(int *)(iVar404 + -0xc)) == -2) break;
        if ((uint)(*(int *)(iVar404 + -8) + *(int *)(iVar404 + -0xc)) < *(uint *)(iVar404 + -0x1a))
        {
          *(undefined2 *)((int)puVar102 + -2) = 9;
                    /* WARNING: Subroutine does not return */
          *(undefined2 *)((int)puVar102 + -4) = pcVar495;
          *(undefined2 *)((int)puVar102 + -6) = (char *)"steam bath" + 4;
          ovr_stExit(*(int *)((int)puVar102 + -2));
        }
        *(int *)(iVar404 + -0x1a) = *(int *)(iVar404 + -0x1a) + 1;
      }
      *(char *)((int)*(undefined4 *)(iVar404 + -0x20) + 5) =
           *(char *)(iVar404 + -0x18) - *(char *)(iVar404 + -0x1a);
      pfVar25 = (far_t *)*(undefined2 *)(iVar404 + -0x1a);
    } while( true );
  case 0x90:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0x91:
    return pfVar25;
  case 0x92:
    *(undefined2 *)((int)puVar97 + 0xe) = unaff_SS;
    *(int *)((int)puVar97 + 0xc) = iVar404 + -0xe;
    *(undefined2 *)((int)puVar97 + 10) = 0x4000;
    puVar52 = (undefined2 *)((int)puVar97 + 8);
    *(undefined2 *)((int)puVar97 + 8) = 0x150;
    _fmemset((void *)*(undefined4 *)((int)puVar97 + 0xc),*(uint16_t *)((int)puVar97 + 0x10),
             *(uint16_t *)((int)puVar97 + 0x12));
    puVar36 = puVar52 + 6;
    GGameState = 0x3f;
    if (DebugVerbose != false) {
      puVar52[5] = DAT_2000_d163;
      puVar52[4] = DAT_2000_d165;
      puVar52[3] = GGameState;
      puVar52[2] = (char *)"puppetmaker" + 3;
      puVar52[1] = 0x8df;
      *puVar52 = 0x1000;
      puVar53 = puVar52 + -1;
      puVar52[-1] = 0x187;
      printf(*(char **)(puVar52 + 1),puVar52[3]);
      puVar36 = (undefined2 *)((int)puVar53 + 0xe);
    }
    pcVar495 = (char *)0x1000;
    DAT_2000_d165 = 0;
    DAT_2000_d163 = 0;
    pfVar24 = (far_t *)0x0;
    goto LAB_3f0b_1785;
  case 0x97:
  case 0xad:
    *(char *)(iVar404 + -2 + (int)pfVar489) = *(char *)(iVar404 + -2 + (int)pfVar489) + bVar39;
    *(undefined2 *)((int)puVar97 + 0xe) = DAT_2000_cc87;
    *(undefined2 *)((int)puVar97 + 0xc) = DAT_2000_cc85;
    *(undefined2 *)((int)puVar97 + 10) = 0x4000;
    *(undefined2 *)((int)puVar97 + 8) = 0xd1ee;
    pfVar24 = (far_t *)ovr_blitGfxRect(*(far_t *)((int)puVar97 + 0xc),
                                       *(int16_t *)((int)puVar97 + 0x10),
                                       *(int16_t *)((int)puVar97 + 0x12),
                                       (brect_t *)*(undefined4 *)((int)puVar97 + 0x14),
                                       *(uint8_t *)((int)puVar97 + 0x18),
                                       *(bool *)(undefined2 *)((int)puVar97 + 0x1a));
    return pfVar24;
  case 0x98:
  case 0xae:
    puVar65 = (undefined2 *)((int)puVar97 + 0x12);
    uVar17 = in(0x8b);
    out(pcVar21,uVar17);
    goto code_r0x000403e1;
  case 0x9d:
    goto code_r0x00048328;
  case 0x9e:
    if (in_CX != (uint16_t *)&EntityTypeSeg[0].sx) goto code_r0x00042ac3;
    goto code_r0x00042ac1;
  case 0x9f:
    goto code_r0x00040027;
  case 0xa0:
    goto code_r0x00040375;
  case 0xa2:
    pcVar508 = (char *)((int)&pfVar37->ofs + (int)&pfVar489->ofs);
    *pcVar508 = *pcVar508 + '\x01';
    bVar499 = *pcVar508 == '\0';
    while ((bVar499 || (pfVar489 == (far_t *)((char *)"Divide error\r\n" + 8)))) {
      *(undefined2 *)((int)puVar197 + -2) = pcVar495;
      puVar195 = (undefined2 *)((int)puVar197 + -4);
      *(undefined2 *)((int)puVar197 + -4) = (char *)"%s: %s %d gold. Feeds %d %s." + 0xd;
      ioErrorHndlrInstall();
      puVar195[1] = 0;
      *puVar195 = *(undefined2 *)(iVar404 + 6);
      puVar195[-1] = *(undefined2 *)(iVar404 + 4);
      puVar195[-2] = 0x1000;
      puVar196 = puVar195 + -3;
      puVar195[-3] = (char *)"%s: %s %d gold. Feeds %d %s." + 0x1a;
      pfVar24 = (far_t *)_creat((char *)puVar195[-1],puVar195[1]);
      *(undefined2 *)((int)puVar196 + 8) = 0x1000;
      pcVar495 = (char *)0x1000;
      puVar198 = (undefined1 *)((int)puVar196 + 6);
      *(undefined2 *)((int)puVar196 + 6) =
           (char *)"%s: %s %d gold. provides housing for %d %s and feeds %d %s." + 7;
      pfVar489 = (far_t *)ioErrorHndlrUninstall();
      puVar197 = (undefined2 *)(puVar198 + 4);
      if (pfVar24 != (far_t *)0xffff) {
        return pfVar24;
      }
      bVar499 = pfVar489 == (far_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x1c);
      pfVar24 = (far_t *)0xffff;
    }
                    /* WARNING: Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
    return pfVar24;
  case 0xa3:
    return pfVar25;
  case 0xa4:
    *(undefined2 *)((int)puVar97 + 0xe) = *(undefined2 *)(iVar488 + 0x18);
    *(int *)((int)puVar97 + 0xc) = ((int *)StshHandles)[(int)pfVar489];
    *(undefined2 *)((int)puVar97 + 10) = 0x4000;
    *(undefined2 *)((int)puVar97 + 8) = (char *)" Bridges must be near water\'s edge." + 1;
    close(*(int *)((int)puVar97 + 0xc));
    ((int *)StshHandles)[(int)pfVar489] = -1;
    return (far_t *)((char *)"clerics\' retreat" + 8);
  case 0xa5:
    *(undefined2 *)(iVar404 + -4) = 0;
    while (*(int *)(iVar404 + -4) < (int)(uint)DAT_2000_d1e6) {
      if (((*(char *)((int)*(undefined4 *)(*(int *)(iVar404 + -4) << 2) + 0x3d) != '\0') &&
          (pcVar21 = (char *)"puppetmaker" + 3,
          *(int *)((int)*(undefined4 *)(*(int *)(iVar404 + -4) << 2) + 0x39) == GfxRndSeed)) &&
         (pcVar21 = (char *)"puppetmaker" + 3,
         *(int *)((int)*(undefined4 *)(*(int *)(iVar404 + -4) << 2) + 0x3b) == GfxRndSeed2)) {
        if (GCharLevelsInc != '\0') {
          uVar20 = (undefined2)((ulong)*(undefined4 *)(*(int *)(iVar404 + -4) << 2) >> 0x10);
          iVar488 = (int)*(undefined4 *)(*(int *)(iVar404 + -4) << 2);
          puVar2 = (uint *)(iVar488 + 0x56);
          uVar487 = *puVar2;
          *puVar2 = *puVar2 + 10000;
          piVar3 = (int *)(iVar488 + 0x58);
          *piVar3 = *piVar3 + (uint)(0xd8ef < uVar487);
          GCharLevelsInc = '\0';
        }
        *(undefined2 *)((int)puVar97 + 0xe) = CONCAT11(0x24,*(undefined1 *)(iVar404 + -4));
        *(undefined2 *)((int)puVar97 + 0xc) = 0x4000;
        puVar390 = (undefined2 *)((int)puVar97 + 10);
        *(undefined2 *)((int)puVar97 + 10) = 0xe9a1;
        manage_4d05_1bee();
        *(undefined2 *)((int)puVar390 + 4) = 0x4000;
        puVar391 = (undefined2 *)((int)puVar390 + 2);
        *(undefined2 *)((int)puVar390 + 2) = 0xe9a9;
        ovr_stats_6386_232d();
        puVar391[1] = (char *)"money dealer\'s shop" + 0xe;
        *puVar391 = 0xe9ae;
        pfVar24 = (far_t *)ovr_OVC41_6a8f_18c6();
        return pfVar24;
      }
      *(int *)(iVar404 + -4) = *(int *)(iVar404 + -4) + 1;
    }
    *(undefined2 *)((int)puVar97 + 0xe) = 0x4000;
    pcVar495 = (char *)"money dealer\'s shop" + 0xe;
    pfVar392 = (far_t *)((int)puVar97 + 0xc);
    *(undefined2 *)((int)puVar97 + 0xc) = 0xe9c6;
    ovr_stats_6386_00f8();
    if (DAT_2000_d1e4 != 0) {
      *(undefined2 *)((int)pfVar392 + 2) = (char *)"money dealer\'s shop" + 0xe;
      pfVar392->ofs = 0xeacc;
      manage_4d05_0081();
      pcVar21 = (char *)*(undefined2 *)((uint)DAT_2000_d1e4 * 4 + -4);
      *(undefined2 *)(iVar404 + -0x10) = *(undefined2 *)((uint)DAT_2000_d1e4 * 4 + -2);
      *(undefined2 *)(iVar404 + -0x12) = pcVar21;
      *(undefined2 *)((int)pfVar392 + 2) = *(undefined2 *)(iVar404 + -0x10);
      pfVar392->ofs = *(undefined2 *)(iVar404 + -0x12);
      goto code_r0x0004eaed;
    }
    if (DAT_2000_d1e3 <= DAT_2000_d1e5) {
      *(undefined2 *)((int)pfVar392 + 2) = (char *)"money dealer\'s shop" + 0xe;
      pfVar392->ofs = 0xe9e0;
      pfVar24 = (far_t *)ovr_OVC41_6a8f_18c6();
      return pfVar24;
    }
    *(undefined2 *)((int)pfVar392 + 2) = (char *)"money dealer\'s shop" + 0xe;
    pfVar392->ofs = 0xe9e7;
    uVar20 = chargen();
    pfVar395 = pfVar392 + 1;
    *(undefined2 *)(iVar404 + -0x10) = pcVar21;
    *(undefined2 *)(iVar404 + -0x12) = uVar20;
    if (*(int *)(iVar404 + -0x12) == 0 && *(int *)(iVar404 + -0x10) == 0) {
      pfVar392->seg = (uint16_t)((char *)"money dealer\'s shop" + 0xe);
      pfVar392->ofs = 0xe9fa;
      ovr_stats_6386_232d();
      *(undefined2 *)((int)pfVar392 + 2) = (char *)"money dealer\'s shop" + 0xe;
      pfVar392->ofs = 0xe9ff;
      pfVar24 = (far_t *)ovr_OVC41_6a8f_18c6();
      return pfVar24;
                    /* WARNING: Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
    }
    *(undefined2 *)(iVar404 + -4) = 0;
    while ((*(int *)(iVar404 + -4) < (int)(uint)DAT_2000_d1e6 &&
           (*(char *)((int)*(undefined4 *)(*(int *)(iVar404 + -4) << 2) + 0x28) != '\0'))) {
      *(int *)(iVar404 + -4) = *(int *)(iVar404 + -4) + 1;
    }
    if (*(int *)(iVar404 + -4) < (int)(uint)DAT_2000_d1e6) {
      DAT_2000_d1e4 = *(char *)(iVar404 + -4) + 1;
      uVar487 = (uint)DAT_2000_d1e4;
      pfVar392->seg = *(undefined2 *)(uVar487 * 4 + -2);
      pfVar392->ofs = *(undefined2 *)(uVar487 * 4 + -4);
      pfVar392[-1].seg = (uint16_t)((char *)"money dealer\'s shop" + 0xe);
      pcVar495 = (char *)"glassworks" + 9;
      pfVar393 = pfVar392 + -1;
      (pfVar392 + -1)->ofs = 0xea5d;
      ovr_stshFree(*pfVar392);
      pfVar395 = (far_t *)((int)pfVar393 + 8);
    }
    else {
      if (0x4f < DAT_2000_d1e6) {
        pfVar392->seg = 0x1d;
                    /* WARNING: Subroutine does not return */
        *(char **)pfVar392 = (char *)"money dealer\'s shop" + 0xe;
        pfVar392[-1].seg = 0xea70;
        ovr_stExit(pfVar392->seg);
      }
      DAT_2000_d1e4 = DAT_2000_d1e6 + 1;
      DAT_2000_d1e6 = DAT_2000_d1e4;
    }
    pbVar1 = (byte *)((int)*(undefined4 *)(iVar404 + -0x12) + 0x28);
    *pbVar1 = *pbVar1 | 0x40;
    *(char *)((int)*(undefined4 *)(iVar404 + -0x12) + 0x51) = DAT_2000_d1e4 - 1;
    uVar487 = (uint)DAT_2000_d1e4;
    pcVar21 = (char *)"halfling castle" + 0xc;
    uVar20 = *(undefined2 *)(iVar404 + -0x12);
    *(undefined2 *)(uVar487 * 4 + -2) = *(undefined2 *)(iVar404 + -0x10);
    *(undefined2 *)(uVar487 * 4 + -4) = uVar20;
    if (DAT_2000_d1e5 == 0) {
      *(undefined1 *)((int)*(undefined4 *)(iVar404 + -0x12) + 0x86) = 1;
    }
    DAT_2000_d1e5 = DAT_2000_d1e5 + 1;
LAB_4d05_1aa8:
    puVar396 = (undefined2 *)((int)pfVar395 + -2);
    *(undefined2 *)((int)pfVar395 + -2) = *(undefined2 *)(iVar404 + -0x10);
code_r0x0004eafb:
    *(undefined2 *)((int)puVar396 + -2) = *(undefined2 *)(iVar404 + -0x12);
    *(undefined2 *)((int)puVar396 + -4) = (char *)"puppetmaker" + 3;
    *(undefined2 *)((int)puVar396 + -6) = (char *)"Place %s here.";
    *(undefined2 *)((int)puVar396 + -8) = pcVar495;
    puVar397 = (undefined1 *)((int)puVar396 + -10);
    *(undefined2 *)((int)puVar396 + -10) = 0xeb07;
    pcVar495 = ovr_fmVsprintf((char *)*(undefined2 *)((int)puVar396 + -6),
                              (char *)*(undefined2 *)((int)puVar396 + -2));
    *(char **)(puVar397 + 10) = pcVar21;
    *(char **)(puVar397 + 8) = pcVar495;
    *(char **)(puVar397 + 6) = (char *)"glassworks" + 9;
    puVar398 = (undefined2 *)(puVar397 + 4);
    *(undefined2 *)(puVar397 + 4) = 0xeb11;
    ovr_drawString();
    puVar398[3] = 0;
    puVar398[2] = 0;
    puVar398[1] = 0;
    *puVar398 = 2;
    puVar398[-1] = unaff_SS;
    puVar398[-2] = iVar404 + -0xe;
    puVar398[-3] = (char *)"money dealer\'s shop" + 0xe;
    puVar399 = puVar398 + -4;
    puVar398[-4] = 0xeb26;
    bVar19 = ovr_uiInputText();
    *(uint *)(iVar404 + -6) = (uint)bVar19;
    if (*(int *)(iVar404 + -6) == 1) {
      *(int *)(iVar404 + -4) = DAT_2000_d1e4 - 1;
      if (DAT_2000_d1e5 == 1) {
        *(undefined2 *)((int)puVar399 + 0xe) = 2;
        *(undefined2 *)((int)puVar399 + 0xc) = (char *)"halfling outpost" + 4;
        puVar403 = (undefined1 *)((int)puVar399 + 10);
        *(undefined2 *)((int)puVar399 + 10) = 0xeb63;
        ovr_OVC18_48ac_05f2();
        puVar402 = puVar403 + 6;
      }
      else {
        *(undefined2 *)((int)puVar399 + 0xe) = 1;
        *(undefined2 *)((int)puVar399 + 0xc) = (char *)"halfling outpost" + 4;
        puVar401 = (undefined1 *)((int)puVar399 + 10);
        *(undefined2 *)((int)puVar399 + 10) = 0xeb57;
        ovr_OVC18_48ac_05f2();
        puVar402 = puVar401 + 6;
      }
      *(char **)(puVar402 + -2) = (char *)"fighter outpost" + 9;
      *(undefined2 *)(puVar402 + -4) = 0xeb6b;
      pfVar24 = (far_t *)ovr_OVC41_6a8f_18c6();
    }
    else {
      *(undefined2 *)((int)puVar399 + 0xe) = (char *)"halfling outpost" + 4;
      puVar400 = (undefined2 *)((int)puVar399 + 0xc);
      *(undefined2 *)((int)puVar399 + 0xc) = 0xeb39;
      ovr_stats_6386_232d();
      puVar400[1] = (char *)"money dealer\'s shop" + 0xe;
      *puVar400 = 0xeb3e;
      pfVar24 = (far_t *)ovr_OVC41_6a8f_18c6();
    }
                    /* WARNING: Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
    return pfVar24;
  case 0xa6:
    goto LAB_3f0b_104a;
  case 0xa7:
  case 0xa8:
    return (far_t *)((uint)pfVar25 & 0xff8e);
  case 0xb4:
    goto code_r0x00042ab7;
  case 0xb5:
    pfVar24 = (far_t *)*(int *)((int)pfVar25 * 3 + *(int *)(iVar404 + 6) * 2);
    *(undefined1 *)((int)DAT_2000_ca95 + (int)pfVar24 * 9) = 0;
    *(undefined1 *)((int)DAT_2000_ca95 + (int)pfVar24 * 9 + 1) = 8;
    *(undefined1 *)((int)DAT_2000_ca95 + (int)pfVar24 * 9 + 2) = 0xff;
    *(undefined2 *)((int)DAT_2000_cb0d + *(int *)(iVar404 + 4) * 0x78 + *(int *)(iVar404 + 6) * 2) =
         0;
    puVar2 = (uint *)((int)DAT_2000_cb09 + *(int *)(iVar404 + 6) * 0x128 + *(int *)(iVar404 + 4) * 2
                     );
    *puVar2 = *puVar2 & 0x3fff;
                    /* WARNING: Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
    return pfVar24;
  case 0xb6:
    goto code_r0x00040020;
  case 0xb7:
    goto code_r0x000422cb;
  case 0xb9:
    goto code_r0x00048906;
  case 0xba:
    return pfVar25;
  case 0xbb:
    goto switchD_4000_4689_switchD;
  case 0xbc:
    pcVar508 = (char *)((int)&pfVar489->ofs + (int)&pfVar37[-0x1a].seg);
    *pcVar508 = *pcVar508 + '\x01';
    pcVar6 = (code *)swi(1);
    pfVar24 = (far_t *)(*pcVar6)();
    return pfVar24;
  case 0xbd:
    puVar2 = (uint *)((int)pfVar24 + iVar404 + -0x3e23);
    uVar487 = *puVar2;
    *puVar2 = *puVar2 - 1;
    puVar456 = (undefined2 *)((int)puVar97 + 0x10);
    if (in_CX == (uint16_t *)0x0) {
      puVar456 = (undefined2 *)((int)puVar97 + 0xe);
      *(uint *)((int)puVar97 + 0xe) =
           (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW2(uVar487,1) * 0x800 |
           (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)*puVar2 < 0) * 0x80 |
           (uint)(*puVar2 == 0) * 0x40 | (uint)(9 < (bVar19 & 0xf) | in_AF & 1) * 0x10 |
           (uint)((POPCOUNT(*puVar2 & 0xff) & 1U) == 0) * 4;
    }
code_r0x0004fe85:
    *(char **)((char *)((int)pfVar37 + iVar404 + -0x66) + 2) = (char *)"puppetmaker" + 3;
    *(char **)(char *)((int)pfVar37 + iVar404 + -0x66) = (char *)"Done";
    puVar36 = (undefined2 *)((int)((int)&pfVar24->ofs + 1) * 4 + iVar404 + -0x66);
    puVar36[1] = (char *)"puppetmaker" + 3;
    *puVar36 = (char *)"Summary";
    pfVar37 = (far_t *)((int)&pfVar24->seg * 4 + iVar404 + -0x66);
    pfVar37->seg = (uint16_t)((char *)"puppetmaker" + 3);
    pfVar37->ofs = (uint16_t)(char *)"All levels";
    puVar114 = &pfVar24->seg;
    pfVar489 = (far_t *)0x0;
    goto LAB_4d05_2ee8;
  case 0xbe:
  case 0xed:
    if ((!bVar499 && !bVar500) || ((char *)*(uint *)((int)&AgntAnms[0x53].y + 1) < pcVar21)) {
      uVar487 = (((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
                 (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
      if ((uVar487 < *(uint *)(iVar404 + -0xe)) ||
         ((uVar487 <= *(uint *)(iVar404 + -0xe) &&
          (((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0] <= *(uint *)(iVar404 + -0x10)
          )))) {
        iVar488 = ((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0];
        *(int *)(iVar404 + -10) =
             (((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
              (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
             (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
        *(int *)(iVar404 + -0xc) = iVar488;
      }
      else {
        uVar20 = *(undefined2 *)(iVar404 + -0x10);
        *(undefined2 *)(iVar404 + -10) = *(undefined2 *)(iVar404 + -0xe);
        *(undefined2 *)(iVar404 + -0xc) = uVar20;
      }
      *(undefined2 *)((int)puVar97 + 0xe) = *(undefined2 *)(iVar404 + -10);
      *(undefined2 *)((int)puVar97 + 0xc) = *(undefined2 *)(iVar404 + -0xc);
      iVar488 = (uint)StshPtrs[0] - (uint)FMXmsHandle;
      *(int *)((int)puVar97 + 10) =
           ((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) - (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) - (uint)((uint)StshPtrs[0] < (uint)FMXmsHandle);
      *(int *)((int)puVar97 + 8) = iVar488;
      *(undefined2 *)((int)puVar97 + 6) = *(undefined2 *)(iVar404 + 8);
      *(undefined2 *)((int)puVar97 + 4) = *(undefined2 *)(iVar404 + 6);
      *(undefined2 *)((int)puVar97 + 2) = 0x4000;
      *(char **)puVar97 = (char *)"Iron deposits discovered." + 1;
      uVar504 = ovr_mkp(*(uint16_t *)((int)puVar97 + 4),*(uint16_t *)((int)puVar97 + 6));
      *(undefined2 *)((int)puVar97 + 6) = (int)(uVar504 >> 0x10);
      *(undefined2 *)((int)puVar97 + 4) = (int)uVar504;
      *(undefined2 *)((int)puVar97 + 2) = (char *)"arrowsmith" + 3;
      *(char **)puVar97 = (char *)"Iron deposits discovered." + 0xb;
      ems_memmove1();
      bVar499 = CARRY2((uint)StshPtrs[0],*(uint *)(iVar404 + -0xc));
      (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + *(uint *)(iVar404 + -0xc);
      (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + *(int *)(iVar404 + -10) + (uint)bVar499;
      iVar488 = *(int *)(iVar404 + -10);
      uVar484 = *(uint *)(iVar404 + -0xc);
      puVar2 = (uint *)(iVar404 + -0x10);
      uVar487 = *puVar2;
      *puVar2 = *puVar2 - uVar484;
      *(int *)(iVar404 + -0xe) = (*(int *)(iVar404 + -0xe) - iVar488) - (uint)(uVar487 < uVar484);
      uVar20 = *(undefined2 *)(iVar404 + -10);
      uVar493 = *(undefined2 *)(iVar404 + -0xc);
      *(undefined2 *)((int)puVar97 + 0xe) = 0x1000;
      pcVar495 = (char *)0x1000;
      puVar190 = (undefined1 *)((int)puVar97 + 0xc);
      *(undefined2 *)((int)puVar97 + 0xc) = (char *)"Remove %s permanently. Are you sure?" + 0xe;
      uVar504 = LXURSH_at_(CONCAT22(uVar20,uVar493),0x4);
      puVar192 = (undefined2 *)(puVar190 + 4);
      uVar487 = *(uint *)(iVar404 + -0xc);
      iVar488 = *(int *)(iVar404 + 6);
      *(int *)(iVar404 + 8) = (int)uVar504 + *(int *)(iVar404 + 8);
      *(int *)(iVar404 + 6) = iVar488 + (uVar487 & 0xf);
    }
    uVar487 = (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
              (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle);
    if ((uVar487 <= (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) &&
       ((uVar487 != (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) ||
        ((uint)FMXmsHandle + (uint)FMEmsHandle <= (uint)StshPtrs[0])))) {
      *(undefined2 *)((int)puVar192 + -2) = 0;
      *(uint *)((int)puVar192 + -4) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2));
      *(uint *)((int)puVar192 + -6) = (uint)StshPtrs[0];
      *(int *)((int)puVar192 + -8) = StshHandles[0];
      *(undefined2 *)((int)puVar192 + -10) = pcVar495;
      pcVar495 = (char *)0x1000;
      puVar191 = (undefined1 *)((int)puVar192 + -0xc);
      *(undefined2 *)((int)puVar192 + -0xc) =
           (char *)"%s: Claim this tree? Harvest value is %d gold. Active party is %s the %s." +
           0x23;
      lseek(*(int *)((int)puVar192 + -8),*(long *)((int)puVar192 + -6),*(int *)((int)puVar192 + -2))
      ;
      puVar192 = (undefined2 *)(puVar191 + 0xc);
    }
    if (*(int *)(iVar404 + -0x10) == 0 && *(int *)(iVar404 + -0xe) == 0) {
      pfVar24 = (far_t *)(*(int *)(iVar404 + -8) - *(int *)(iVar404 + 10));
    }
    else {
      *(undefined2 *)(iVar404 + -4) = *(undefined2 *)((char *)"toymaker" + 7 + (int)pfVar489 * 2);
      uVar20 = *(undefined2 *)(iVar404 + 6);
      *(undefined2 *)(iVar404 + -0x14) = *(undefined2 *)(iVar404 + 8);
      *(undefined2 *)(iVar404 + -0x16) = uVar20;
      while( true ) {
        if ((*(int *)(iVar404 + -0xe) == 0) && (*(int *)(iVar404 + -0x10) == 0))
        goto next_iteration;
        if ((*(int *)(iVar404 + -0xe) == 0) && (*(uint *)(iVar404 + -0x10) < 0xc001)) {
          uVar20 = *(undefined2 *)(iVar404 + -0x10);
        }
        else {
          uVar20 = 0xc000;
        }
        *(undefined2 *)(iVar404 + -0x12) = uVar20;
        *(undefined2 *)((int)puVar192 + -2) = *(undefined2 *)(iVar404 + -0x12);
        *(undefined2 *)((int)puVar192 + -4) = *(undefined2 *)(iVar404 + -0x14);
        *(undefined2 *)((int)puVar192 + -6) = *(undefined2 *)(iVar404 + -0x16);
        *(undefined2 *)((int)puVar192 + -8) = *(undefined2 *)(iVar404 + -4);
        *(undefined2 *)((int)puVar192 + -10) = pcVar495;
        puVar193 = (undefined2 *)((int)puVar192 + -0xc);
        *(undefined2 *)((int)puVar192 + -0xc) =
             (char *)"Forest claimed. This forest creates %d gold of income and feeds %d %s." + 0x3e
        ;
        uVar487 = read(*(int *)((int)puVar192 + -8),(void *)*(undefined2 *)((int)puVar192 + -6),
                       *(uint *)((int)puVar192 + -2));
        if (uVar487 != *(uint *)(iVar404 + -0x12)) break;
        puVar2 = (uint *)(iVar404 + -0x10);
        uVar484 = *puVar2;
        *puVar2 = *puVar2 - uVar487;
        *(int *)(iVar404 + -0xe) = *(int *)(iVar404 + -0xe) - (uint)(uVar484 < uVar487);
        iVar488 = *(int *)(iVar404 + -0x16);
        puVar193[5] = *(undefined2 *)(iVar404 + -0x14);
        puVar193[4] = iVar488 + uVar487;
        puVar193[3] = 0x1000;
        pcVar495 = (char *)"arrowsmith" + 3;
        puVar194 = puVar193 + 2;
        puVar193[2] = (char *)"Income created is" + 8;
        uVar504 = ovr_mkp(puVar193[4],puVar193[5]);
        puVar192 = (undefined2 *)((int)puVar194 + 8);
        *(undefined2 *)(iVar404 + -0x14) = (int)(uVar504 >> 0x10);
        *(undefined2 *)(iVar404 + -0x16) = (int)uVar504;
        puVar2 = (uint *)((int)&AgntAnms[0x53].y + 1 + (int)pfVar489 * 4);
        uVar484 = *puVar2;
        *puVar2 = *puVar2 + uVar487;
        piVar3 = (int *)((int)&AgntAnms[0x53].field_0x10 + (int)pfVar489 * 4);
        *piVar3 = *piVar3 + (uint)CARRY2(uVar484,uVar487);
      }
      puVar193[5] = ((undefined2 *)((int)pfVar489 * 4))[1];
      puVar193[4] = *(undefined2 *)((int)pfVar489 * 4);
      puVar193[3] = (char *)"puppetmaker" + 3;
      puVar193[2] = (char *)"File read error %s \r";
      puVar193[1] = 0x1000;
      *puVar193 = (char *)"Tree cut down. %d gold obtained." + 0x1e;
      printf(*(char **)(puVar193 + 2),puVar193[4]);
      *(undefined2 *)((int)puVar193 + 10) = 0x1000;
      *(undefined2 *)((int)puVar193 + 8) = (char *)"Maintenance cost is" + 5;
      ovr_biosReadKey();
next_iteration:
      pfVar24 = (far_t *)(*(int *)(iVar404 + -8) - *(int *)(iVar404 + 10));
    }
    return pfVar24;
  case 0xbf:
    while( true ) {
      *(undefined2 *)((int)puVar247 + -2) = *(undefined2 *)(Entities.ofs + (int)pfVar489 * 0x37);
      *(undefined2 *)((int)puVar247 + -4) = pcVar495;
      pcVar495 = (char *)"dwarf outpost" + 6;
      puVar246 = (undefined1 *)((int)puVar247 + -6);
      *(undefined2 *)((int)puVar247 + -6) = 0x9b1a;
      iVar488 = ovr_OVC23_55fe_3450();
      puVar247 = (undefined2 *)(puVar246 + 6);
      if ((iVar488 == *(int *)(iVar404 + -4)) &&
         ((far_t *)*(undefined2 *)(Entities.ofs + (int)pfVar489 * 0x37 + 2) == pfVar24)) break;
      pfVar489 = (far_t *)((int)&pfVar489->ofs + 1);
      if (EntityCount <= pfVar489) {
        return (far_t *)0x0;
      }
    }
    return (far_t *)((int)(undefined4 *)&_DATA + 1);
  case 0xc0:
    goto code_r0x00040061;
  case 0xc1:
    goto code_r0x0004234c;
  case 0xc3:
    pfVar489 = (far_t *)(iVar488 + 3);
  case 0xc4:
  case 0xc5:
  case 200:
    uVar20 = *(undefined2 *)(iVar404 + -6);
    iVar488 = *(int *)(iVar404 + -8);
    *(undefined2 *)((int)puVar97 + 0xe) = *(undefined2 *)(char *)((int)pfVar25 + iVar488 + -2);
    *(undefined2 *)((int)puVar97 + 0xc) = *(undefined2 *)(char *)((int)&pfVar25[-1].ofs + iVar488);
    *(undefined2 *)((int)puVar97 + 10) = 0x4000;
    pcVar495 = (char *)0x1000;
    puVar177 = (undefined2 *)((int)puVar97 + 8);
    *(undefined2 *)((int)puVar97 + 8) =
         (char *)"Your may continue playing, but your score will not be recorded." + 0x3a;
    iVar488 = strcmp((char *)*(undefined2 *)((int)puVar97 + 0xc),
                     (char *)*(undefined2 *)((int)puVar97 + 0x10));
    puVar178 = (undefined2 *)((int)puVar177 + 0xc);
    puVar184 = (undefined2 *)((int)puVar177 + 0xc);
    if (iVar488 == 0) {
      pfVar25 = (far_t *)((uint)*(byte *)(iVar404 + -9) << 2);
      pcVar494 = (char *)*(undefined2 *)(iVar404 + -6);
code_r0x00046a27:
      iVar488 = *(int *)(iVar404 + -8);
      *(undefined2 *)((int)puVar178 + -2) = *(undefined2 *)(char *)((int)pfVar25 + iVar488 + -2);
      *(undefined2 *)((int)puVar178 + -4) = *(undefined2 *)(char *)((int)&pfVar25[-1].ofs + iVar488)
      ;
      *(undefined2 *)((int)puVar178 + -6) = pcVar495;
      pcVar495 = (char *)"glassworks" + 9;
      puVar179 = (undefined1 *)((int)puVar178 + -8);
      *(undefined2 *)((int)puVar178 + -8) = (char *)"The season has changed to summer." + 0xb;
      ovr_stshFree(*(far_t *)((int)puVar178 + -4));
      uVar20 = *(undefined2 *)(iVar404 + -6);
      iVar488 = (uint)*(byte *)(iVar404 + -9) * 4 + *(int *)(iVar404 + -8);
      *(undefined2 *)(iVar488 + -2) = 0;
      *(undefined2 *)(iVar488 + -4) = 0;
      puVar184 = (undefined2 *)(puVar179 + 8);
    }
LAB_4528_17d8:
    iVar488 = (uint)*(byte *)(iVar404 + -9) * 4 + *(int *)(iVar404 + -8);
    uVar487 = *(uint *)(iVar488 + -4) | *(uint *)(iVar488 + -2);
    if (uVar487 == 0) {
code_r0x00046a72:
    }
    else {
      *(undefined2 *)((int)puVar184 + -2) =
           CONCAT11((char)(uVar487 >> 8),*(undefined1 *)(iVar404 + -9));
      *(undefined2 *)((int)puVar184 + -4) = pcVar495;
      pcVar495 = (char *)"fighter outpost" + 0xe;
      puVar180 = (undefined1 *)((int)puVar184 + -6);
      *(undefined2 *)((int)puVar184 + -6) = (char *)"%d building%s repaired." + 0x10;
      cVar18 = ovr_stSave();
      puVar181 = puVar180 + 6;
      if (cVar18 == '\0') {
        uVar20 = *(undefined2 *)(iVar404 + -6);
        iVar488 = (uint)*(byte *)(iVar404 + -9) * 4 + *(int *)(iVar404 + -8);
        *(undefined2 *)(iVar488 + -2) = 0;
        *(undefined2 *)(iVar488 + -4) = 0;
      }
      else {
        GWantsExit2 = 0;
      }
      for (pfVar24 = (far_t *)0x0; pfVar24 < pfVar489; pfVar24 = (far_t *)((int)&pfVar24->ofs + 1))
      {
        *(uint16_t *)(puVar181 + -2) = GSPEmpty.seg;
        *(uint16_t *)(puVar181 + -4) = GSPEmpty.ofs;
        uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -8) >> 0x10);
        puVar36 = (undefined2 *)((int)*(undefined4 *)(iVar404 + -8) + (int)pfVar24 * 4);
        *(undefined2 *)(puVar181 + -6) = puVar36[1];
        *(undefined2 *)(puVar181 + -8) = *puVar36;
        *(char **)(puVar181 + -10) = pcVar495;
        pcVar495 = (char *)0x1000;
        puVar182 = puVar181 + -0xc;
        *(char **)(puVar181 + -0xc) =
             (char *)
             "$My %s, we in this neighborhood are doing well. We thank you for all you have done to help your people."
             + 3;
        iVar488 = strcmp(*(char **)(puVar181 + -8),*(char **)(puVar181 + -4));
        puVar181 = puVar182 + 0xc;
        if (iVar488 == 0) {
          uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -8) >> 0x10);
          puVar36 = (undefined2 *)((int)*(undefined4 *)(iVar404 + -8) + (int)pfVar24 * 4);
          puVar36[1] = 0;
          *puVar36 = 0;
        }
      }
      while ((pfVar489 != (far_t *)0x0 &&
             (uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -8) >> 0x10),
             piVar22 = (int *)((int)*(undefined4 *)(iVar404 + -8) +
                              (int)((int)&pfVar489[-1].seg + 1) * 4),
             *piVar22 == 0 && piVar22[1] == 0))) {
        pfVar489 = (far_t *)((int)&pfVar489[-1].seg + 1);
      }
      *(far_t **)(puVar181 + -2) = pfVar489;
      *(undefined2 *)(puVar181 + -4) = *(undefined2 *)(iVar404 + -6);
      *(undefined2 *)(puVar181 + -6) = *(undefined2 *)(iVar404 + -8);
      *(char **)(puVar181 + -8) = pcVar495;
      puVar183 = puVar181 + -10;
      *(char **)(puVar181 + -10) =
           (char *)
           "$My %s, we in this neighborhood are doing well. We thank you for all you have done to help your people."
           + 0x4a;
      saveui_4528_120d();
      puVar184 = (undefined2 *)(puVar183 + 10);
    }
    *(undefined2 *)((int)puVar184 + -2) = pcVar495;
    puVar186 = (undefined1 *)((int)puVar184 + -4);
    *(undefined2 *)((int)puVar184 + -4) =
         (char *)
         "$My %s, we in this neighborhood are doing well. We thank you for all you have done to help your people."
         + 0x51;
    saveui_4528_0533();
    puVar185 = puVar186 + 4;
    do {
      if ((SaveAuto != '\0') && (*(char *)(iVar404 + -4) != '\0')) {
        *(far_t **)(puVar185 + -2) = pfVar489;
        *(undefined2 *)(puVar185 + -4) = *(undefined2 *)(iVar404 + -6);
        *(undefined2 *)(puVar185 + -6) = *(undefined2 *)(iVar404 + -8);
        *(char **)(puVar185 + -8) = pcVar495;
        puVar187 = puVar185 + -10;
        *(char **)(puVar185 + -10) = (char *)"inspired you to seek a life of glory and" + 0x24;
        saveui_4528_1288();
        *(undefined2 *)(puVar187 + 8) = *(undefined2 *)(iVar404 + -6);
        *(undefined2 *)(puVar187 + 6) = *(undefined2 *)(iVar404 + -8);
        *(char **)(puVar187 + 4) = pcVar495;
        puVar188 = puVar187 + 2;
        *(char **)(puVar187 + 2) = (char *)"adventure." + 9;
        ovr_stshFree(*(far_t *)(puVar187 + 6));
        *(char **)(puVar188 + 6) = (char *)"glassworks" + 9;
        *(char **)(puVar188 + 4) = (char *)"%s stronghold destroyed" + 6;
        pfVar24 = (far_t *)ovr_OVC28_6018_0251();
        return pfVar24;
      }
      if (SaveAuto == '\0') {
        *(undefined2 *)(iVar404 + -0x2e) = 0;
        *(undefined2 *)(iVar404 + -0x30) = 0;
      }
      else {
        *(undefined2 *)(iVar404 + -0x2e) = (char *)"puppetmaker" + 3;
        *(undefined2 *)(iVar404 + -0x30) = (char *)"Save Game";
      }
      if ((DAT_2000_ca90 == '\0') && (SaveAuto != '\0')) {
        *(undefined2 *)(iVar404 + -0x16) = (char *)"puppetmaker" + 3;
        *(undefined2 *)(iVar404 + -0x18) = (char *)"Begin Play";
      }
      else {
        *(undefined2 *)(iVar404 + -0x16) = 0;
        *(undefined2 *)(iVar404 + -0x18) = 0;
      }
      pcVar21 = (char *)"puppetmaker" + 3;
      *(undefined2 *)(puVar185 + -2) = 8;
      *(undefined2 *)(puVar185 + -4) = unaff_SS;
      iVar488 = iVar404 + -0x34;
      *(int *)(puVar185 + -6) = iVar488;
      *(char **)(puVar185 + -8) = (char *)"puppetmaker" + 3;
      *(char **)(puVar185 + -10) = (char *)"Select an option:";
      *(char **)(puVar185 + -0xc) = pcVar495;
      puVar175 = puVar185 + -0xe;
      *(char **)(puVar185 + -0xe) = (char *)"@Guard house" + 7;
      uiMenu(*(char **)(puVar185 + -10),*(far_t *)(puVar185 + -6),*(int *)(puVar185 + -2));
      *(undefined1 *)(iVar404 + -0x13) = (char)iVar488;
      *(char **)(puVar175 + 0xc) = (char *)"puppetmaker" + 3;
      *(char **)(puVar175 + 10) = (char *)"<Empty>" + 7;
      *(char **)(puVar175 + 8) = pcVar495;
      pcVar495 = (char *)"steam bath" + 6;
      puVar176 = puVar175 + 6;
      *(char **)(puVar175 + 6) = (char *)"@Thieve\'s Den" + 9;
      ovr_say(*(char **)(puVar175 + 10));
      puVar134 = puVar176 + 8;
      puVar241 = (undefined2 *)(puVar176 + 8);
      puVar251 = (uint16_t *)(puVar176 + 8);
      puVar40 = (undefined2 *)(puVar176 + 8);
      puVar185 = puVar176 + 8;
      uVar487 = (uint)*(byte *)(iVar404 + -0x13);
    } while (8 < uVar487);
    pbVar33 = (byte *)(uVar487 * 2);
    pcVar495 = "";
    switch(uVar487) {
    case 0:
      *(undefined1 **)(puVar176 + 6) = puVar176 + 8;
      *(byte *)&pfVar24->ofs = (byte)pfVar24->ofs & (byte)in_CX;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 1:
      pfVar489 = (far_t *)((*(byte *)(iVar404 + -0x13) &
                           (byte)*(undefined2 *)((int)&pfVar24[0xb0].seg + iVar404)) + 0xf8);
      *(undefined2 *)(iVar404 + -4) = pfVar489;
      goto LAB_48ac_0cb6;
    case 2:
      while( true ) {
        (pbVar33 + (int)pfVar24)[-0x1ba] = (pbVar33 + (int)pfVar24)[-0x1ba] + (char)in_CX;
        iVar488 = *(int *)(iVar404 + 4);
        iVar490 = *(int *)(iVar404 + -4);
        uVar20 = *(undefined2 *)(iVar404 + -6);
        *(undefined2 *)((int)puVar251 + -2) = *(undefined2 *)(iVar404 + 6);
        *(int *)((int)puVar251 + -4) = iVar488 + (int)pfVar24 * 0x1e;
        puVar36 = (undefined2 *)(*(int *)(iVar404 + -8) + iVar490 * 4);
        uVar493 = *(undefined2 *)((int)puVar251 + -4);
        puVar36[1] = *(undefined2 *)((int)puVar251 + -2);
        *puVar36 = uVar493;
        for (uVar487 = 0;
            uVar487 < *(byte *)((int)*(undefined4 *)(iVar404 + 4) + (int)pfVar24 * 0x1e + 0x1b);
            uVar487 = uVar487 + 1) {
          if (uVar487 == 0) {
            *(undefined2 *)((int)puVar251 + -2) = pcVar495;
            puVar250 = (uint16_t *)((int)puVar251 + -4);
            *(undefined2 *)((int)puVar251 + -4) = 0xb941;
            fVar503 = ovr_stshAllocStub();
            puVar251 = puVar250 + 2;
            iVar488 = *(int *)(iVar404 + -4);
            uVar20 = *(undefined2 *)(iVar404 + -6);
            puVar250[1] = fVar503.ofs;
            *puVar250 = fVar503.seg;
            puVar250[-1] = iVar488 << 2;
            iVar488 = *(int *)(iVar404 + -8);
            iVar490 = puVar250[-1];
            *(undefined2 *)(iVar488 + iVar490 + 0x5a) = *puVar250;
            *(undefined2 *)(iVar488 + iVar490 + 0x58) = puVar250[1];
          }
          else {
            *(undefined2 *)((int)puVar251 + -2) = pcVar495;
            puVar252 = (undefined1 *)((int)puVar251 + -4);
            *(undefined2 *)((int)puVar251 + -4) = 0xb964;
            ovr_stshAllocStub();
            puVar251 = (uint16_t *)(puVar252 + 4);
          }
          pcVar495 = (char *)"trade faire" + 4;
        }
        pfVar24 = (far_t *)((int)&pfVar24->ofs + 1);
        if (((far_t *)*(undefined2 *)(iVar404 + 8) <= pfVar24) ||
           (*(char *)((int)*(undefined4 *)(iVar404 + 4) + (int)pfVar24 * 0x1e + 0x1b) == '\0'))
        break;
        pbVar33 = (byte *)((int)*(undefined4 *)(iVar404 + 4) + (int)pfVar24 * 0x1e);
        *(uint *)(iVar404 + -4) = (uint)*pbVar33;
      }
      return (far_t *)*(undefined2 *)(iVar404 + -8);
    case 3:
      *(char *)&pfVar489->ofs = (char)pfVar489->ofs;
    case 5:
      pfVar25 = (far_t *)(uint)*(byte *)(Entities.ofs + uVar487 + 0xd);
      pcVar21 = "%d \r";
switchD_4000_f055_caseD_4:
      pfVar25 = (far_t *)((int)pfVar25 * (int)pcVar21);
      puVar13 = puVar40;
      break;
    case 4:
      do {
        *(undefined2 *)(puVar134 + -2) = *(undefined2 *)(pbVar33 + uVar487);
        *(char **)(puVar134 + -4) = pcVar495;
        pcVar495 = (char *)"thief outpost" + 10;
        puVar135 = puVar134 + -6;
        *(char **)(puVar134 + -6) = (char *)"Select an alignment." + 8;
        cVar18 = ovr_OVC23_55fe_05db();
        uVar23 = Entities.ofs;
        uVar492 = Entities.seg;
        if ((cVar18 == '\0') && ((*(byte *)(uVar23 + (int)pfVar489 * 0x37 + 0x33) & 3) == 0)) {
                    /* WARNING: Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
          return pfVar489;
        }
        do {
          pfVar489 = (far_t *)((int)&pfVar489->ofs + 1);
          if (EntityCount <= pfVar489) {
            pfVar489 = (far_t *)0x0;
          }
          if (pfVar489 == pfVar24) {
            *(far_t **)(puVar135 + 6) = EntityCount;
            *(char **)(puVar135 + 4) = (char *)"thief outpost" + 10;
            *(char **)(puVar135 + 2) =
                 (char *)"Reroll ability scores, or select the character\'s class." + 10;
            uVar23 = ovr_randBelow(*(uint16_t *)(puVar135 + 6));
            return (far_t *)(uVar23 & 0xff);
          }
        } while (*(char *)(uVar23 + (int)pfVar489 * 0x37 + 0x1a) != *(char *)(iVar404 + -8));
        puVar134 = puVar135 + 6;
        *(undefined2 *)(puVar135 + 6) = *(undefined2 *)(uVar23 + (int)pfVar489 * 0x37 + 2);
        uVar487 = (int)pfVar489 * 0x37;
        pcVar21 = (char *)Entities.seg;
        pbVar33 = (byte *)Entities.ofs;
      } while( true );
    case 6:
      pfVar489 = (far_t *)((int)&pfVar489->ofs + 1);
      piVar248 = (int *)(puVar176 + 6);
      *(undefined2 *)(puVar176 + 6) = 0x4000;
code_r0x0004b801:
      while( true ) {
        *(int *)(iVar404 + 6) = (int)((int)&pfVar489->ofs + *(int *)(iVar404 + 6));
        piVar3 = (int *)(iVar404 + 10);
        pfVar25 = (far_t *)*piVar3;
        *piVar3 = *piVar3 - (int)pfVar489;
        *(int *)(iVar404 + 0xc) = *(int *)(iVar404 + 0xc) - (uint)(pfVar25 < pfVar489);
        if (*(int *)(iVar404 + 10) == 0 && *(int *)(iVar404 + 0xc) == 0) break;
        if ((*(int *)(iVar404 + 0xc) < 1) &&
           ((*(int *)(iVar404 + 0xc) < 0 || (*(uint *)(iVar404 + 10) < 0xc000)))) {
          pfVar489 = (far_t *)*(undefined2 *)(iVar404 + 10);
        }
        else {
          pfVar489 = (far_t *)0xc000;
        }
        piVar248[3] = *(undefined2 *)(iVar404 + 8);
        piVar248[2] = *(undefined2 *)(iVar404 + 6);
        piVar248[1] = (int)pcVar495;
        *piVar248 = 0xb7eb;
        uVar504 = ovr_mkp(piVar248[2],piVar248[3]);
        *(undefined2 *)(iVar404 + 8) = (int)(uVar504 >> 0x10);
        *(undefined2 *)(iVar404 + 6) = (int)uVar504;
        piVar248[3] = (int)pfVar489;
        piVar248[2] = *(undefined2 *)(iVar404 + 8);
        piVar248[1] = *(undefined2 *)(iVar404 + 6);
        *piVar248 = (int)pfVar24;
        piVar248[-1] = (int)((char *)"arrowsmith" + 3);
        pcVar495 = (char *)0x1000;
        piVar249 = piVar248 + -2;
        piVar248[-2] = 0xb801;
        write(*piVar248,(void *)piVar248[1],piVar248[3]);
        piVar248 = (int *)((int)piVar249 + 4);
      }
      return (far_t *)0x0;
    case 7:
LAB_4207_03a2:
      return (far_t *)*(undefined2 *)(iVar404 + -0x28);
    case 8:
                    /* WARNING: Subroutine does not return */
      *(undefined2 *)(puVar176 + 6) = 0x4000;
      *(undefined2 *)(puVar176 + 4) = 0xc093;
      ovr_stExit(*(int *)(puVar176 + 8));
    }
code_r0x00040020:
    puVar41 = puVar13;
    pcVar494 = (char *)0x195d;
    pfVar37 = pfVar25;
code_r0x00040027:
    if ((char)pfVar37[0x9b5].seg == '\0') {
      *(undefined2 *)((int)puVar41 + -2) = 0;
      *(undefined2 *)((int)puVar41 + -4) = 0x26;
      *(undefined2 *)((int)puVar41 + -6) = 0x4000;
      pcVar495 = (char *)"stonemasonry" + 0xc;
      puVar44 = (undefined1 *)((int)puVar41 + -8);
      *(undefined2 *)((int)puVar41 + -8) = 0x46;
      ovr_play_sfx(*(int16_t *)((int)puVar41 + -4),*(int16_t *)((int)puVar41 + -2));
      puVar43 = puVar44 + 8;
    }
    else {
      *(undefined2 *)((int)puVar41 + -2) = 0;
      *(undefined2 *)((int)puVar41 + -4) = 0x24;
      *(undefined2 *)((int)puVar41 + -6) = 0x4000;
      pcVar495 = (char *)"stonemasonry" + 0xc;
      puVar42 = (undefined1 *)((int)puVar41 + -8);
      *(undefined2 *)((int)puVar41 + -8) = 0x38;
      ovr_play_sfx(*(int16_t *)((int)puVar41 + -4),*(int16_t *)((int)puVar41 + -2));
      puVar43 = puVar42 + 8;
    }
LAB_3f0b_0f99:
    *(undefined1 *)(Entities.ofs + (int)pfVar489 * 0x37 + 0x18) = 0;
    puVar12 = (undefined2 *)puVar43;
code_r0x00040061:
    puVar45 = puVar12;
    *(undefined2 *)((int)puVar45 + -2) =
         CONCAT11((char)((uint)((int)pfVar489 * 0x37) >> 8),
                  *(undefined1 *)(Entities.ofs + (int)pfVar489 * 0x37 + 0x32));
    *(undefined1 *)(Entities.ofs + (int)pfVar489 * 0x37 + 0x31) =
         (char)*(undefined2 *)((int)puVar45 + -2);
    pfVar489 = (far_t *)((int)&pfVar489->ofs + 1);
    pfVar25 = (far_t *)((char *)"puppetmaker" + 3);
code_r0x00040095:
    if ((far_t *)*(undefined2 *)&EntityCount <= pfVar489) {
      if ((*(char *)(iVar404 + -0xe) != '\0') ||
         (puVar48 = puVar45, *(char *)(iVar404 + -0xd) != '\0')) {
        bVar500 = *(char *)(iVar404 + -3) == '\0';
        puVar36 = puVar45;
code_r0x000400b4:
        if (bVar500) {
          *(undefined2 *)((int)puVar36 + -2) = pcVar495;
          piVar46 = (int16_t *)((int)puVar36 + -4);
          *(undefined2 *)((int)puVar36 + -4) = 0xbb;
          ovr_stop_audio();
          CurSfxType3 = 0xff;
          piVar46[1] = 0;
          *piVar46 = 0x5a;
          piVar46[-1] = (int16_t)((char *)"stonemasonry" + 0xc);
          pcVar495 = (char *)"stonemasonry" + 0xc;
          piVar47 = piVar46 + -2;
          piVar46[-2] = 0xcf;
          ovr_play_sfx(*piVar46,piVar46[1]);
          puVar48 = (undefined2 *)((int)piVar47 + 8);
        }
        else if (*(char *)(iVar404 + -0xd) == '\0') {
          puVar48 = puVar36;
          if (*(char *)(iVar404 + -0xe) != '\0') {
            *(undefined2 *)((int)puVar36 + -2) = 0;
            *(undefined2 *)((int)puVar36 + -4) = 0x25;
            *(undefined2 *)((int)puVar36 + -6) = pcVar495;
            pcVar495 = (char *)"stonemasonry" + 0xc;
            puVar50 = (undefined1 *)((int)puVar36 + -8);
            *(undefined2 *)((int)puVar36 + -8) = 0xf7;
            ovr_play_sfx(*(int16_t *)((int)puVar36 + -4),*(int16_t *)((int)puVar36 + -2));
            puVar48 = (undefined2 *)(puVar50 + 8);
          }
        }
        else {
          *(undefined2 *)((int)puVar36 + -2) = 0;
          *(undefined2 *)((int)puVar36 + -4) = 0x23;
          *(undefined2 *)((int)puVar36 + -6) = pcVar495;
          pcVar495 = (char *)"stonemasonry" + 0xc;
          puVar49 = (undefined1 *)((int)puVar36 + -8);
          *(undefined2 *)((int)puVar36 + -8) = 0xe3;
          ovr_play_sfx(*(int16_t *)((int)puVar36 + -4),*(int16_t *)((int)puVar36 + -2));
          puVar48 = (undefined2 *)(puVar49 + 8);
        }
      }
LAB_3f0b_104a:
      GGameState = 0x3d;
      if (DebugVerbose != false) {
        *(undefined2 *)((int)puVar48 + -2) = 0x3d;
        *(undefined2 *)((int)puVar48 + -4) = (char *)"puppetmaker" + 3;
        *(undefined2 *)((int)puVar48 + -6) = 0x8da;
        *(undefined2 *)((int)puVar48 + -8) = pcVar495;
        pcVar495 = (char *)0x1000;
        puVar51 = (undefined1 *)((int)puVar48 + -10);
        *(undefined2 *)((int)puVar48 + -10) = 0x126;
        printf((char *)*(undefined4 *)((int)puVar48 + -6),*(undefined2 *)((int)puVar48 + -2));
        puVar48 = (undefined2 *)(puVar51 + 10);
      }
      *(undefined2 *)((int)puVar48 + -2) = pcVar495;
      *(undefined2 *)((int)puVar48 + -4) = 0x12e;
      pfVar24 = (far_t *)ovr_OVC23_55fe_2b82();
      return pfVar24;
    }
LAB_4d05_2d65_2:
    pfVar24 = (far_t *)((byte)((char)pfVar25 - 0x15) | 0x1e);
    *(undefined2 *)((int)puVar45 + -2) =
         (char *)"The damaged structures belonging to all leaders are highlighted in red.";
    *(undefined2 *)((int)puVar45 + -4) = pcVar495;
    *(undefined2 *)((int)puVar45 + -6) = 0xfdc3;
    ovr_say((char *)*(undefined4 *)((int)puVar45 + -2));
                    /* WARNING: Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
    return pfVar24;
  case 0xc6:
    puVar184 = (undefined2 *)((int)puVar97 + 0x10);
    goto LAB_4528_17d8;
  case 199:
    goto code_r0x00046a72;
  case 0xc9:
    goto LAB_4b0a_1318;
  case 0xca:
    GfxRndSeed = Seed_2000_d1da;
    GfxRndSeed2 = Seed_2000_d1d8;
    *(undefined2 *)((int)puVar97 + 0xe) = 0x4000;
    pcVar495 = (char *)"jeweler" + 6;
    puVar450 = (undefined2 *)((int)puVar97 + 0xc);
    *(undefined2 *)((int)puVar97 + 0xc) = 0xfc81;
    ovr_OVC13_3d16_1558();
    puVar449 = (undefined2 *)((int)puVar450 + 4);
    goto code_r0x0004fc81;
  case 0xcc:
    if (in_CX != (uint16_t *)((int)(undefined4 *)&_DATA + 1)) {
      pcVar508 = (char *)((int)&pfVar489->ofs + (int)(pfVar37 + 0x1d));
      *pcVar508 = *pcVar508 +
                  bVar19 + (9 < (bVar19 & 0xf) | in_AF) * '\x06' +
                  (0x99 < bVar19 || CARRY2((uint)pcVar21,(uint)pfVar25)) * '`';
      puVar36 = (undefined2 *)((int)puVar97 + 0xe);
      *(undefined2 *)((int)puVar97 + 0xe) = pcVar494;
      goto code_r0x0004024a;
    }
    return pfVar25;
  case 0xcd:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xcf:
  case 0xec:
    goto code_r0x00040300;
  case 0xd0:
  case 0xd5:
    puVar105 = (undefined2 *)((int)puVar97 + 0xe);
    *(undefined2 *)((int)puVar97 + 0xe) = pcVar494;
    goto code_r0x0004259b;
  case 0xd1:
    pfVar506 = pfVar489;
    *(byte *)&pfVar506->ofs = (byte)pfVar506->ofs ^ bVar15;
    if ((char)pfVar506->ofs == '\0') {
      if ((*(char *)((int)*(undefined4 *)(iVar404 + 4) + 0x2f) == '\x05') &&
         (10 < *(byte *)((int)*(undefined4 *)(iVar404 + 4) + 0x30))) {
        pfVar24 = (far_t *)CONCAT11(bVar29,10);
      }
      else if ((*(char *)((int)*(undefined4 *)(iVar404 + 4) + 0x2f) == '\x06') &&
              (8 < *(byte *)((int)*(undefined4 *)(iVar404 + 4) + 0x30))) {
        pfVar24 = (far_t *)CONCAT11(bVar29,8);
      }
      else {
        pfVar24 = (far_t *)CONCAT11(bVar29,*(undefined1 *)((int)*(undefined4 *)(iVar404 + 4) + 0x30)
                                   );
      }
    }
    else {
      pfVar24 = (far_t *)CONCAT11(bVar29,0xc);
    }
    return pfVar24;
  case 0xd2:
    *(int *)((int)puVar97 + 0xe) = *(int *)&StshStrongDatHnd;
    goto code_r0x00048327;
  case 0xd3:
    pcVar21 = (char *)((int)in_CX + iVar404 + -2);
    if (!CARRY2(iVar404 - 2,(uint)in_CX) && pcVar21 != (char *)0x0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
code_r0x000410c8:
    puVar485 = (undefined1 *)((int)puVar97 + 0x10);
code_r0x00041120:
    do {
      puVar486 = puVar485;
      if ((int)(uint)*(byte *)((int)&pfVar24[3].seg + (int)*(undefined4 *)(pcVar21 + 6)) <=
          (int)pfVar489) {
code_r0x000411ab:
        for (; puVar485 = puVar486,
            (int)pfVar489 <
            (int)(uint)*(byte *)((int)&pfVar24[3].seg + (int)*(undefined4 *)(pcVar21 + 6));
            pfVar489 = (far_t *)((int)&pfVar489->ofs + 1)) {
          *(undefined2 *)(puVar485 + -2) = *(undefined2 *)((int)*(undefined4 *)(pcVar21 + 6) + 2);
          *(undefined2 *)(puVar485 + -4) = **(undefined2 **)(pcVar21 + 6);
          *(uint *)(puVar485 + -6) = (uint)(byte)pcVar21[-1];
          *(undefined2 *)(puVar485 + -8) = 0;
          *(undefined2 *)(puVar485 + -10) = unaff_SS;
          *(char **)(puVar485 + -0xc) = pcVar21 + -4;
          *(char **)(puVar485 + -0xe) = pcVar495;
          puVar99 = puVar485 + -0x10;
          *(undefined2 *)(puVar485 + -0x10) = 0x11d7;
          cVar18 = attact_3f0b_1a2f();
          puVar485 = puVar99 + 0x10;
          if (cVar18 == '\0') break;
          *(undefined1 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 0x30) = 0;
          *(undefined2 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 8) =
               *(undefined2 *)(pcVar21 + -6);
          *(undefined2 *)(puVar99 + 0xe) = *(undefined2 *)((int)*(undefined4 *)(pcVar21 + 6) + 2);
          *(undefined2 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 10) =
               *(undefined2 *)(puVar99 + 0xe);
          puVar486 = puVar99 + 0x10;
        }
        do {
          pfVar37 = (far_t *)(uint)*(byte *)((int)&pfVar24[3].seg +
                                            (int)*(undefined4 *)(pcVar21 + 6));
          pfVar25 = pfVar24;
          if ((int)pfVar489 <= (int)pfVar37) goto code_r0x00041292;
          *(undefined2 *)(puVar485 + -2) = *(undefined2 *)((int)*(undefined4 *)(pcVar21 + 6) + 2);
          *(undefined2 *)(puVar485 + -4) = **(undefined2 **)(pcVar21 + 6);
          *(uint *)(puVar485 + -6) = (uint)(byte)pcVar21[-1];
          *(undefined2 *)(puVar485 + -8) = unaff_SS;
          *(char **)(puVar485 + -10) = pcVar21 + -4;
          *(char **)(puVar485 + -0xc) = pcVar495;
          puVar100 = puVar485 + -0xe;
          *(undefined2 *)(puVar485 + -0xe) = 0x1288;
          pfVar37 = (far_t *)attact_3f0b_1bfc();
          puVar485 = puVar100 + 0xe;
          if ((char)pfVar37 == '\0') goto code_r0x00041292;
          *(undefined1 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 0x30) = 0;
          *(undefined2 *)(puVar100 + 0xc) =
               *(undefined2 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 4);
          *(undefined2 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 8) =
               *(undefined2 *)(puVar100 + 0xc);
          *(undefined2 *)(puVar100 + 0xc) =
               *(undefined2 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 6);
          *(undefined2 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 10) =
               *(undefined2 *)(puVar100 + 0xc);
          pfVar489 = (far_t *)((int)&pfVar489[-1].seg + 1);
          puVar485 = puVar100 + 0xe;
        } while( true );
      }
      *(undefined2 *)(puVar485 + -2) = *(undefined2 *)((int)*(undefined4 *)(pcVar21 + 6) + 2);
      *(undefined2 *)(puVar485 + -4) = **(undefined2 **)(pcVar21 + 6);
      *(uint *)(puVar485 + -6) = (uint)(byte)pcVar21[-1];
      *(undefined2 *)(puVar485 + -8) = 1;
      *(undefined2 *)(puVar485 + -10) = unaff_SS;
      *(char **)(puVar485 + -0xc) = pcVar21 + -4;
      *(char **)(puVar485 + -0xe) = pcVar495;
      puVar98 = puVar485 + -0x10;
      *(undefined2 *)(puVar485 + -0x10) = 0x1149;
      cVar18 = attact_3f0b_1a2f();
      puVar485 = puVar98 + 0x10;
      puVar486 = puVar98 + 0x10;
      if (cVar18 == '\0') goto code_r0x000411ab;
      *(undefined1 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 0x30) = 0;
      *(undefined2 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 8) =
           *(undefined2 *)(pcVar21 + -6);
      *(undefined2 *)(puVar98 + 0xe) = *(undefined2 *)((int)*(undefined4 *)(pcVar21 + 6) + 2);
      *(undefined2 *)(Entities.ofs + *(int *)(pcVar21 + -4) * 0x37 + 10) =
           *(undefined2 *)(puVar98 + 0xe);
      pfVar489 = (far_t *)((int)&pfVar489->ofs + 1);
    } while( true );
  case 0xd4:
    *(byte *)(iVar404 + -2 + (int)pfVar24) = *(byte *)(iVar404 + -2 + (int)pfVar24) ^ bVar15;
    pbVar1 = (byte *)(iVar404 + -2 + (int)pfVar24);
    bVar29 = *pbVar1;
    *pbVar1 = *pbVar1 - bVar15;
    *(char *)(iVar404 + -2 + (int)pfVar24) =
         (*(char *)(iVar404 + -2 + (int)pfVar24) - bVar15) - (bVar29 < bVar15);
    *(uint *)(iVar404 + -2 + (int)pfVar24) = *(uint *)(iVar404 + -2 + (int)pfVar24) | (uint)in_CX;
    *(long *)(iVar404 + -2 + (int)pfVar489) = (long)in_ST0;
    bVar38 = bVar38 | *(byte *)((int)&pfVar489->ofs + (int)&pfVar37[2].seg);
    pbVar33 = (byte *)CONCAT11(bVar38,bVar31);
    *(undefined2 *)((int)puVar97 + 0xe) = (undefined2 *)((int)puVar97 + 0x10);
    bVar29 = pbVar33[(int)pfVar489];
    uVar487 = CONCAT11(bVar39 | bVar29 | 0x99,bVar15 | *pbVar33);
    uVar484 = iVar404 - 2U | uVar487;
    *(uint *)((char *)_dosErrorToSV + 0x25 + iVar488) =
         *(uint *)((char *)_dosErrorToSV + 0x25 + iVar488) | uVar484;
    *(uint *)(iVar488 + 0xb) = *(uint *)(iVar488 + 0xb) | (uint)((int)puVar97 + 0xe);
    *(uint *)(pbVar33 + (int)pfVar24) = *(uint *)(pbVar33 + (int)pfVar24) | uVar487;
    (pbVar33 + (int)pfVar489)[-0x6af8] = (pbVar33 + (int)pfVar489)[-0x6af8] | bVar38;
    pbVar1 = (byte *)((int)&pfVar489[0x1b42].ofs + uVar484);
    *pbVar1 = *pbVar1 | bVar19;
    pbVar1 = (byte *)((int)&pfVar489[2].ofs + uVar484);
    *pbVar1 = *pbVar1 | bVar31;
    *(undefined2 *)((int)puVar97 + 0xc) = pfVar25;
    *(byte *)((uint)pfVar24 | uVar484) = *(byte *)((uint)pfVar24 | uVar484) | bVar29 | 0x99;
    *pbVar33 = *pbVar33 | bVar31;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xd6:
  case 0xf1:
    *(char *)((int)&pfVar489[10].ofs + iVar404) =
         *(char *)((int)&pfVar489[10].ofs + iVar404) + bVar27;
    do {
      if ((far_t *)*(undefined2 *)((int)in_CX * 0x34 + 0x26) != pfVar489) goto LAB_4207_2be8;
      if (pfVar24 <= (far_t *)*(undefined2 *)((int)in_CX * 0x34 + 0x28)) goto LAB_4207_2be8;
      do {
        *(undefined1 *)(iVar404 + -3) = (char)in_CX;
        pfVar489 = (far_t *)*(undefined2 *)((int)in_CX * 0x34 + 0x26);
        pfVar24 = (far_t *)*(undefined2 *)((int)in_CX * 0x34 + 0x28);
LAB_4207_2be8:
        do {
          in_CX = (uint16_t *)((int)in_CX + 1);
          if ((int)(uint)AgntCount <= (int)in_CX) {
            if (*(char *)(iVar404 + -3) == -1) {
              pfVar24 = (far_t *)0x0;
            }
            else {
              DAT_2000_ca6e = *(byte *)(iVar404 + -3);
              pfVar24 = (far_t *)((char *)"arena" + 5);
            }
            return pfVar24;
          }
        } while (((uint16_t *)(uint)DAT_2000_ca6e == in_CX) ||
                ((*(undefined2 *)((int)puVar97 + 0xe) =
                       *(undefined2 *)((uint)DAT_2000_ca6e * 0x34 + 0x26),
                 *(uint *)((int)in_CX * 0x34 + 0x26) <= *(uint *)((int)puVar97 + 0xe) &&
                 ((*(undefined2 *)((int)puVar97 + 0xe) =
                        *(undefined2 *)((uint)DAT_2000_ca6e * 0x34 + 0x26),
                  *(int *)((int)puVar97 + 0xe) != *(int *)((int)in_CX * 0x34 + 0x26) ||
                  (*(undefined2 *)((int)puVar97 + 0xe) =
                        *(undefined2 *)((uint)DAT_2000_ca6e * 0x34 + 0x28),
                  *(uint *)((int)in_CX * 0x34 + 0x28) <= *(uint *)((int)puVar97 + 0xe)))))));
      } while ((far_t *)*(undefined2 *)((int)in_CX * 0x34 + 0x26) < pfVar489);
    } while( true );
  case 0xd7:
  case 0xf2:
    *(int *)((int)puVar97 + 0xe) = StshStrongDatHnd;
code_r0x00048327:
    puVar199 = (undefined2 *)((int)puVar97 + 0xc);
    *(undefined2 *)((int)puVar97 + 0xc) = 0x4000;
code_r0x00048328:
    *(undefined2 *)((int)puVar199 + -2) = (char *)"text4.txt" + 9;
    stshRead(*(uint16_t *)((int)puVar199 + 2),*(far_t *)((int)puVar199 + 4),
             *(long *)((int)puVar199 + 8));
    return (far_t *)*(undefined2 *)((int)*(undefined4 *)(iVar404 + 4) + 0x11);
  case 0xd8:
    goto code_r0x000404c4;
  case 0xdd:
  case 0xf8:
    puVar220 = (undefined2 *)((int)puVar97 + 0xe);
    *(undefined2 *)((int)puVar97 + 0xe) = pfVar489;
    puVar486 = (undefined1 *)(iVar404 + -2);
code_r0x00048bea:
    *(char **)(puVar486 + -4) = pcVar21;
    bVar500 = GameRunning == false;
switchD_4000_f055_caseD_2:
    if (bVar500) {
      *(undefined2 *)((int)puVar220 + -2) = *(undefined2 *)(puVar486 + -2);
      *(undefined2 *)((int)puVar220 + -4) = *(undefined2 *)(puVar486 + -4);
      *(undefined2 *)((int)puVar220 + -6) = (char *)"puppetmaker" + 3;
      *(undefined2 *)((int)puVar220 + -8) = (char *)"View %s.";
      *(undefined2 *)((int)puVar220 + -10) = pcVar495;
      puVar218 = (undefined1 *)((int)puVar220 + -0xc);
      *(undefined2 *)((int)puVar220 + -0xc) = 0x8c0b;
      pcVar495 = ovr_fmVsprintf((char *)*(undefined2 *)((int)puVar220 + -8),
                                (char *)*(undefined2 *)((int)puVar220 + -4));
      *(char **)(puVar218 + 10) = pcVar21;
      *(char **)(puVar218 + 8) = pcVar495;
      *(char **)(puVar218 + 6) = (char *)"glassworks" + 9;
      pcVar495 = (char *)"steam bath" + 6;
      puVar219 = puVar218 + 4;
      *(undefined2 *)(puVar218 + 4) = 0x8c15;
      ovr_say(*(char **)(puVar218 + 8));
      puVar220 = (undefined2 *)(puVar219 + 8);
    }
    *(undefined2 *)((int)puVar220 + -2) = pcVar495;
    *(undefined2 *)((int)puVar220 + -4) = 0x8c1c;
    pfVar24 = (far_t *)OVC18_48ac_0000();
                    /* WARNING: Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
    return pfVar24;
  case 0xe4:
  case 0xff:
    puVar151 = (undefined2 *)((int)puVar97 + 0xe);
    *(undefined2 *)((int)puVar97 + 0xe) = 0x4000;
    goto code_r0x000458c3;
  case 0xe6:
    while( true ) {
      if ((far_t *)*(undefined2 *)((int)&pfVar37[6].seg + 1) == pfVar24) {
        *(undefined1 *)((int)pfVar489 * 0x34 + 0xc) = 0xff;
        *(int *)((int)puVar131 + -2) =
             (uint)*(byte *)((int)*(undefined4 *)(iVar404 + -8) + 0xd) * 0x95 + 0x26d6;
        *(undefined2 *)((int)pfVar489 * 0x34 + 0x1f) = 0x195d;
        *(undefined2 *)((int)pfVar489 * 0x34 + 0x1d) = *(undefined2 *)((int)puVar131 + -2);
        *(undefined1 *)((int)pfVar489 * 0x34 + 0x21) =
             *(undefined1 *)((int)*(undefined4 *)(iVar404 + -8) + 0x31);
        *(undefined1 *)((int)pfVar489 * 0x34 + 0x22) =
             *(undefined1 *)((int)*(undefined4 *)(iVar404 + -8) + 0x32);
        if ((*(uint *)((int)*(undefined4 *)(iVar404 + -8) + 0x16) & 1) == 0) {
          *(undefined1 *)(iVar404 + -3) = 0;
        }
        else {
          *(undefined1 *)(iVar404 + -3) = 1;
        }
        if (*(byte *)((int)*(undefined4 *)(iVar404 + -8) + 0xf) < 10) {
          if (*(byte *)((int)*(undefined4 *)(iVar404 + -8) + 0xf) < 4) {
            *(int *)((int)puVar131 + -2) = (uint)*(byte *)(iVar404 + -3) * 0xc;
            uVar509 = *(undefined4 *)((int)pfVar489 * 0x34 + 0x1d);
            uVar493 = (undefined2)((ulong)uVar509 >> 0x10);
            iVar488 = (int)uVar509 + *(int *)((int)puVar131 + -2);
            uVar20 = *(undefined2 *)(iVar488 + 3);
            *(undefined2 *)((int)puVar131 + -2) = *(undefined2 *)(iVar488 + 5);
            *(undefined2 *)((int)puVar131 + -4) = uVar20;
            uVar20 = *(undefined2 *)((int)puVar131 + -4);
            *(undefined2 *)((int)pfVar489 * 0x34 + 0x15) = *(undefined2 *)((int)puVar131 + -2);
            *(undefined2 *)((int)pfVar489 * 0x34 + 0x13) = uVar20;
          }
          else {
            *(int *)((int)puVar131 + -2) = (uint)*(byte *)(iVar404 + -3) * 0xc;
            uVar509 = *(undefined4 *)((int)pfVar489 * 0x34 + 0x1d);
            uVar493 = (undefined2)((ulong)uVar509 >> 0x10);
            iVar488 = (int)uVar509 + *(int *)((int)puVar131 + -2);
            uVar20 = *(undefined2 *)(iVar488 + 7);
            *(undefined2 *)((int)puVar131 + -2) = *(undefined2 *)(iVar488 + 9);
            *(undefined2 *)((int)puVar131 + -4) = uVar20;
            uVar20 = *(undefined2 *)((int)puVar131 + -4);
            *(undefined2 *)((int)pfVar489 * 0x34 + 0x15) = *(undefined2 *)((int)puVar131 + -2);
            *(undefined2 *)((int)pfVar489 * 0x34 + 0x13) = uVar20;
          }
        }
        else {
          *(int *)((int)puVar131 + -2) = (uint)*(byte *)(iVar404 + -3) * 0xc;
          uVar509 = *(undefined4 *)((int)pfVar489 * 0x34 + 0x1d);
          uVar493 = (undefined2)((ulong)uVar509 >> 0x10);
          iVar488 = (int)uVar509 + *(int *)((int)puVar131 + -2);
          uVar20 = *(undefined2 *)(iVar488 + 0xb);
          *(undefined2 *)((int)puVar131 + -2) = *(undefined2 *)(iVar488 + 0xd);
          *(undefined2 *)((int)puVar131 + -4) = uVar20;
          uVar20 = *(undefined2 *)((int)puVar131 + -4);
          *(undefined2 *)((int)pfVar489 * 0x34 + 0x15) = *(undefined2 *)((int)puVar131 + -2);
          *(undefined2 *)((int)pfVar489 * 0x34 + 0x13) = uVar20;
        }
        *(undefined1 *)((int)pfVar489 * 0x34 + 0xe) = 0xff;
        *(undefined2 *)((int)puVar131 + -2) =
             CONCAT11((char)((uint)((int)pfVar489 * 0x34) >> 8),
                      *(undefined1 *)*(undefined4 *)((int)pfVar489 * 0x34 + 0x1d));
        *(undefined1 *)((int)pfVar489 * 0x34 + 0x2f) = (char)*(undefined2 *)((int)puVar131 + -2);
        uVar509 = *(undefined4 *)((int)pfVar489 * 0x34 + 0x13);
        uVar20 = (undefined2)((ulong)uVar509 >> 0x10);
        iVar488 = (int)uVar509;
        if ((*(int *)(iVar488 + 0x68) == 0 && *(int *)(iVar488 + 0x6a) == 0) ||
           (uVar509 = *(undefined4 *)((int)pfVar489 * 0x34 + 0x13),
           uVar20 = (undefined2)((ulong)uVar509 >> 0x10), iVar488 = (int)uVar509,
           *(int *)(iVar488 + 0x58) == 0 && *(int *)(iVar488 + 0x5a) == 0)) {
          uVar509 = *(undefined4 *)((int)pfVar489 * 0x34 + 0x13);
          uVar20 = (undefined2)((ulong)uVar509 >> 0x10);
          iVar488 = (int)uVar509;
          if (*(int *)(iVar488 + 0x68) == 0 && *(int *)(iVar488 + 0x6a) == 0) {
            *(undefined1 *)((int)pfVar489 * 0x34 + 0x11) = 0;
          }
          else {
            *(undefined1 *)((int)pfVar489 * 0x34 + 0x11) = 1;
          }
        }
        else {
          *(undefined2 *)((int)puVar131 + -2) = 2;
          *(undefined2 *)((int)puVar131 + -4) = pcVar495;
          pcVar495 = (char *)"glassworks" + 9;
          puVar130 = (undefined1 *)((int)puVar131 + -6);
          *(undefined2 *)((int)puVar131 + -6) = (char *)"breeze3.voc" + 3;
          uVar23 = ovr_randBelow(*(uint16_t *)((int)puVar131 + -2));
          puVar131 = (undefined2 *)(puVar130 + 6);
          *(uint16_t *)(puVar130 + 4) = uVar23;
          *(undefined1 *)((int)pfVar489 * 0x34 + 0x11) = (char)*(undefined2 *)(puVar130 + 4);
        }
        *(undefined2 *)((int)puVar131 + -2) = 0x1726;
        *(int *)((int)puVar131 + -4) = (int)pfVar489 * 0x34;
        *(undefined2 *)((int)puVar131 + -6) = pcVar495;
        puVar132 = (undefined2 *)((int)puVar131 + -8);
        *(undefined2 *)((int)puVar131 + -8) = (char *)"anim\\2phoen0.lbm";
        uVar20 = ovr_audio_3a5b_0afd();
        puVar132[3] = uVar20;
        puVar132[2] = 0;
        puVar132[1] = 0x1b;
        *puVar132 = (char *)"stonemasonry" + 0xc;
        pcVar495 = (char *)"stonemasonry" + 0xc;
        puVar133 = puVar132 + -1;
        puVar132[-1] = (char *)"anim\\2phoen0.lbm" + 0xd;
        ovr_play_sfxU(*(byte *)(puVar132 + 1),puVar132[2],puVar132[3]);
        puVar131 = (undefined2 *)((int)puVar133 + 10);
      }
      pfVar489 = (far_t *)((int)&pfVar489->ofs + 1);
      if ((int)(uint)AgntCount <= (int)pfVar489) break;
      pfVar37 = (far_t *)((int)pfVar489 * 0x34);
      pcVar494 = (char *)0x1726;
    }
    return (far_t *)(uint)AgntCount;
  case 0xe7:
    *(undefined2 *)((int)puVar97 + 0xe) = 0x16;
    *(undefined2 *)((int)puVar97 + 0xc) = *(undefined2 *)(iVar404 + 6);
    *(undefined2 *)((int)puVar97 + 10) = *(undefined2 *)(iVar404 + 4);
    *(undefined2 *)((int)puVar97 + 8) = 0x4000;
    puVar148 = (undefined2 *)((int)puVar97 + 6);
    *(undefined2 *)((int)puVar97 + 6) =
         (char *)"You may continue playing, but your score will not be recorded." + 0x32;
    ovr_blitGfx10(*(far_t *)((int)puVar97 + 10),*(uint16_t *)((int)puVar97 + 0xe),
                  *(uint16_t *)((int)puVar97 + 0x10),(brect_t *)*(undefined4 *)((int)puVar97 + 0x12)
                  ,*(undefined1 *)(undefined2 *)((int)puVar97 + 0x16));
    TextBlitX = 0x2a;
    TextBlitY = (int)pfVar489 * 0xf + 0x1d;
    *(undefined2 *)((int)puVar148 + 0x10) = 0xf;
    *(undefined2 *)((int)puVar148 + 0xe) = 0xde;
    *(uint16_t *)((int)puVar148 + 0xc) = Font03.seg;
    *(uint16_t *)((int)puVar148 + 10) = Font03.ofs;
    *(undefined2 *)((int)puVar148 + 8) = *(undefined2 *)(iVar404 + 10);
    *(undefined2 *)((int)puVar148 + 6) = *(undefined2 *)(iVar404 + 8);
    *(undefined2 *)((int)puVar148 + 4) = (char *)"bath house" + 10;
    pcVar495 = (char *)"steam bath" + 6;
    puVar149 = (undefined2 *)((int)puVar148 + 2);
    *(undefined2 *)((int)puVar148 + 2) =
         (char *)"Intelligence reports %s unit cured of disease. (%d, %d)" + 0x34;
    ovr_blitText((char *)*(undefined4 *)((int)puVar148 + 6),
                 (byte *)*(undefined2 *)((int)puVar148 + 10),*(uint16_t *)((int)puVar148 + 0xe),
                 *(uint8_t *)((int)puVar148 + 0x10));
    puVar151 = puVar149 + 8;
    if (TextBlitX < *(uint *)*(undefined4 *)(iVar404 + 0xc)) {
      *(uint16_t *)(iVar404 + -0xc) = TextBlitX;
      puVar149[7] = 0;
      puVar149[6] = unaff_SS;
      puVar149[5] = iVar404 + -0xc;
      puVar149[4] = (int)pfVar489 * 0xf + 0x1d;
      puVar149[3] = 0x16;
      puVar149[2] = *(undefined2 *)(iVar404 + 6);
      puVar149[1] = *(undefined2 *)(iVar404 + 4);
      *puVar149 = (char *)"steam bath" + 6;
      pcVar495 = (char *)"bath house" + 10;
      puVar150 = puVar149 + -1;
      puVar149[-1] = (char *)
                     "Intelligence reports %s unit succombs to blast spore disease. (%d, %d)" + 0x3b
      ;
      ovr_blitGfx10(*(far_t *)(puVar149 + 1),puVar149[3],puVar149[4],*(brect_t **)(puVar149 + 5),
                    *(undefined1 *)(puVar149 + 7));
      puVar151 = (undefined2 *)((int)puVar150 + 0x12);
    }
    pcVar494 = (char *)((ulong)*(undefined4 *)(iVar404 + 0xc) >> 0x10);
    pfVar37 = (far_t *)(far_t *)*(undefined4 *)(iVar404 + 0xc);
    pfVar25 = (far_t *)TextBlitX;
code_r0x000458c3:
    pfVar37->ofs = (uint16_t)pfVar25;
    *(undefined2 *)((int)puVar151 + -2) = 0xf;
    pfVar24 = (far_t *)((char *)"puppetmaker" + 3);
    *(uint16_t *)((int)puVar151 + -4) = Font03.seg;
    *(uint16_t *)((int)puVar151 + -6) = Font03.ofs;
    *(undefined2 *)((int)puVar151 + -8) = 0x5f;
    *(undefined2 *)((int)puVar151 + -10) = pcVar495;
    *(undefined2 *)((int)puVar151 + -0xc) =
         (char *)"Spies report %s heading towards stronghold. (%d, %d)" + 0x1e;
    ovr_blitLetter(*(char *)((int)puVar151 + -8),(byte *)*(undefined4 *)((int)puVar151 + -6),
                   *(uint8_t *)((int)puVar151 + -2));
    return pfVar24;
  case 0xe9:
    *(char *)&pfVar24->ofs = (char)pfVar24->ofs + cVar18;
    *(char *)(iVar488 + 0x6f) = *(char *)(iVar488 + 0x6f) + bVar27;
    puVar36 = (undefined2 *)((int)puVar97 + 0x10);
    goto code_r0x00043691;
  case 0xea:
    goto code_r0x00046a27;
  case 0xeb:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xee:
code_r0x0004fffe:
    *(undefined2 *)((int)puVar461 + -2) = pfVar25;
    *(undefined2 *)((int)puVar461 + -4) = 0x4000;
    puVar462 = (undefined1 *)((int)puVar461 + -6);
    *(undefined2 *)((int)puVar461 + -6) = 4;
    uVar20 = ovr_OVC45_77eb_226e();
    *(char **)(puVar462 + 0x12) = pcVar21;
    *(undefined2 *)(puVar462 + 0x10) = uVar20;
    *(undefined2 *)(puVar462 + 0xe) = *(undefined2 *)(iVar404 + -0x10);
    *(undefined2 *)(puVar462 + 0xc) = *(undefined2 *)(iVar404 + -0x12);
    *(char **)(puVar462 + 10) = (char *)"trade faire" + 8;
    puVar463 = (undefined2 *)(puVar462 + 8);
    *(undefined2 *)(puVar462 + 8) = 0x13;
    uVar509 = func_0x0005d3f4();
    puVar463[1] = (int)((ulong)uVar509 >> 0x10);
    *puVar463 = (int)uVar509;
    iVar488 = (uint)*(byte *)((int)*(undefined4 *)(iVar404 + -0x12) + 0x2f) * 4;
    puVar463[-1] = *(undefined2 *)(iVar488 + 0xed);
    puVar463[-2] = *(undefined2 *)(iVar488 + 0xeb);
    puVar463[-3] = (char *)"puppetmaker" + 3;
    puVar463[-4] = (char *)"%s population, loyal to %s%s";
    puVar463[-5] = unaff_SS;
    puVar463[-6] = iVar404 + -0x13e;
    puVar463[-7] = (char *)"trade faire" + 8;
    puVar464 = puVar463 + -8;
    puVar463[-8] = 0x44;
    pcVar508 = ovr_stsprintf((char *)puVar463[-6],*(char **)(puVar463 + -4),(char *)puVar463[-2]);
    *(undefined2 *)((int)puVar464 + 0x16) = (int)((ulong)pcVar508 >> 0x10);
    *(undefined2 *)((int)puVar464 + 0x14) = (char *)pcVar508;
    *(undefined2 *)((int)puVar464 + 0x12) = (char *)"glassworks" + 9;
    puVar465 = (undefined1 *)((int)puVar464 + 0x10);
    *(undefined2 *)((int)puVar464 + 0x10) = 0x4e;
    ovr_blitLabel((char *)*(undefined4 *)((int)puVar464 + 0x14),
                  (uint8_t *)*(undefined4 *)((int)puVar464 + 0x18),
                  *(int16_t *)((int)puVar464 + 0x1c),*(uint8_t *)((int)puVar464 + 0x1e));
    TextBlitY = TextBlitY + 0xc;
    *(uint16_t *)(puVar465 + 0xe) = Font02.seg;
    *(uint16_t *)(puVar465 + 0xc) = Font02.ofs;
    *(char **)(puVar465 + 10) = (char *)"puppetmaker" + 3;
    *(char **)(puVar465 + 8) = (char *)"UNITS";
    *(char **)(puVar465 + 6) = (char *)"steam bath" + 6;
    puVar466 = (undefined4 *)(puVar465 + 4);
    *(undefined2 *)(puVar465 + 4) = 0x74;
    iVar488 = ovr_font_302d_06ea();
    TextBlitX = 0x89 - iVar488;
    *(undefined2 *)((int)puVar466 + 10) = 0xe0;
    *(undefined2 *)(puVar466 + 2) = 0xde;
    *(uint16_t *)((int)puVar466 + 6) = Font02.seg;
    *(uint16_t *)(puVar466 + 1) = Font02.ofs;
    *(undefined2 *)((int)puVar466 + 2) = (char *)"puppetmaker" + 3;
    *(char **)puVar466 = (char *)"UNITS";
    *(undefined2 *)((int)puVar466 + -2) = (char *)"steam bath" + 6;
    puVar467 = puVar466 + -1;
    *(undefined2 *)(puVar466 + -1) = 0xa4;
    ovr_blitLabel((char *)*puVar466,(uint8_t *)puVar466[1],*(int16_t *)(puVar466 + 2),
                  *(uint8_t *)((int)puVar466 + 10));
    *(uint16_t *)((int)puVar467 + 0xe) = Font02.seg;
    *(uint16_t *)((int)puVar467 + 0xc) = Font02.ofs;
    *(undefined2 *)((int)puVar467 + 10) = (char *)"puppetmaker" + 3;
    *(undefined2 *)((int)puVar467 + 8) = (char *)"POPULATION";
    *(undefined2 *)((int)puVar467 + 6) = (char *)"steam bath" + 6;
    puVar468 = (undefined4 *)((int)puVar467 + 4);
    *(undefined2 *)((int)puVar467 + 4) = 0xbf;
    iVar488 = ovr_font_302d_06ea();
    uVar23 = 0xd4 - iVar488;
    TextBlitX = uVar23;
    *(undefined2 *)((int)puVar468 + 10) = 0xe0;
    *(undefined2 *)(puVar468 + 2) = 0xde;
    *(uint16_t *)((int)puVar468 + 6) = Font02.seg;
    *(uint16_t *)(puVar468 + 1) = Font02.ofs;
    *(undefined2 *)((int)puVar468 + 2) = (char *)"puppetmaker" + 3;
    *(char **)puVar468 = (char *)"POPULATION";
    *(undefined2 *)((int)puVar468 + -2) = (char *)"steam bath" + 6;
    puVar469 = puVar468 + -1;
    *(undefined2 *)(puVar468 + -1) = 0xef;
    ovr_blitLabel((char *)*puVar468,(uint8_t *)puVar468[1],*(int16_t *)(puVar468 + 2),
                  *(uint8_t *)((int)puVar468 + 10));
    puVar470 = (undefined1 *)((int)puVar469 + 0x10);
    pcVar495 = (char *)0x0;
    while( true ) {
      TextBlitY = TextBlitY + 0xc;
      cVar18 = (char)in_CX;
      if ((int)(uint)*(byte *)(iVar404 + -0xb) <= (int)pcVar495) break;
      TextBlitX = 0x11;
      if (((int)pcVar495 < 5) || (*(char *)(iVar404 + -0xc) == '\0')) {
        *(undefined2 *)(puVar470 + -2) = 0xe0;
        *(undefined2 *)(puVar470 + -4) = 0x13f;
        *(uint16_t *)(puVar470 + -6) = Font02.seg;
        *(uint16_t *)(puVar470 + -8) = Font02.ofs;
        puVar36 = (undefined2 *)((int)pcVar495 * 4 + iVar404 + -0x96);
        *(undefined2 *)(puVar470 + -10) = puVar36[1];
        *(undefined2 *)(puVar470 + -0xc) = *puVar36;
        *(char **)(puVar470 + -0xe) = (char *)"steam bath" + 6;
        puVar473 = puVar470 + -0x10;
        *(undefined2 *)(puVar470 + -0x10) = 0x198;
        ovr_blitLabel(*(char **)(puVar470 + -0xc),*(uint8_t **)(puVar470 + -8),
                      *(int16_t *)(puVar470 + -4),puVar470[-2]);
        puVar472 = puVar473 + 0x10;
      }
      else {
        *(undefined2 *)(puVar470 + -2) = 0xe0;
        *(undefined2 *)(puVar470 + -4) = 0x13f;
        *(uint16_t *)(puVar470 + -6) = Font02.seg;
        *(uint16_t *)(puVar470 + -8) = Font02.ofs;
        iVar488 = (uint)*(byte *)((int)*(undefined4 *)((uint)*(byte *)(iVar404 + 4) << 2) + 0x2f) *
                  0x10 + (int)pcVar495 * 4 + iVar404 + -0x106;
        *(undefined2 *)(puVar470 + -10) = *(undefined2 *)(iVar488 + -0x12);
        *(undefined2 *)(puVar470 + -0xc) = *(undefined2 *)((code *)init_3381_08dc + iVar488);
        *(char **)(puVar470 + -0xe) = (char *)"steam bath" + 6;
        puVar471 = puVar470 + -0x10;
        *(undefined2 *)(puVar470 + -0x10) = 0x167;
        ovr_blitLabel(*(char **)(puVar470 + -0xc),*(uint8_t **)(puVar470 + -8),
                      *(int16_t *)(puVar470 + -4),puVar470[-2]);
        puVar472 = puVar471 + 0x10;
      }
      *(undefined2 *)(puVar472 + -2) = unaff_SS;
      *(int *)(puVar472 + -4) = iVar404 + -0x16;
      *(undefined2 *)(puVar472 + -6) = unaff_SS;
      *(int *)(puVar472 + -8) = iVar404 + -0x14;
      uVar17 = (undefined1)((uint)(iVar404 + -0x14) >> 8);
      *(uint *)(puVar472 + -10) = CONCAT11(uVar17,((undefined1 *)&DAT_2410_4afa)[(int)pcVar495]);
      *(uint *)(puVar472 + -0xc) = CONCAT11(uVar17,((undefined1 *)&DAT_2410_4aee)[(int)pcVar495]);
      *(uint *)(puVar472 + -0xe) = CONCAT11(uVar17,*(undefined1 *)(iVar404 + 4));
      *(char **)(puVar472 + -0x10) = (char *)"steam bath" + 6;
      puVar474 = puVar472 + -0x12;
      *(undefined2 *)(puVar472 + -0x12) = 0x1b7;
      OVC27_5ded_1433();
      *(undefined2 *)(puVar474 + 0xe) = *(undefined2 *)(iVar404 + -0x14);
      *(char **)(puVar474 + 0xc) = (char *)"puppetmaker" + 3;
      *(char **)(puVar474 + 10) = (char *)"%d";
      *(undefined2 *)(puVar474 + 8) = unaff_SS;
      *(int *)(puVar474 + 6) = iVar404 + -0x13e;
      *(char **)(puVar474 + 4) = (char *)"steam bath" + 6;
      puVar475 = puVar474 + 2;
      *(undefined2 *)(puVar474 + 2) = 0x1cc;
      ovr_stsprintf(*(char **)(puVar474 + 6),*(char **)(puVar474 + 10),*(char **)(puVar474 + 0xe));
      *(uint16_t *)(puVar475 + 0xc) = Font02.seg;
      *(uint16_t *)(puVar475 + 10) = Font02.ofs;
      *(undefined2 *)(puVar475 + 8) = unaff_SS;
      *(int *)(puVar475 + 6) = iVar404 + -0x13e;
      *(char **)(puVar475 + 4) = (char *)"glassworks" + 9;
      piVar476 = (int *)(puVar475 + 2);
      *(undefined2 *)(puVar475 + 2) = 0x1e9;
      iVar488 = ovr_font_302d_06ea();
      TextBlitX = 0x89 - iVar488;
      piVar476[5] = 0x50;
      piVar476[4] = 0xde;
      piVar476[3] = Font02.seg;
      piVar476[2] = Font02.ofs;
      piVar476[1] = unaff_SS;
      *piVar476 = iVar404 + -0x13e;
      piVar476[-1] = (int)((char *)"steam bath" + 6);
      piVar477 = piVar476 + -2;
      piVar476[-2] = 0x21a;
      ovr_blitLabel(*(char **)piVar476,*(uint8_t **)(piVar476 + 2),piVar476[4],(uint8_t)piVar476[5])
      ;
      *(undefined2 *)((int)piVar477 + 0xe) = *(undefined2 *)(iVar404 + -0x16);
      *(undefined2 *)((int)piVar477 + 0xc) = (char *)"puppetmaker" + 3;
      *(undefined2 *)((int)piVar477 + 10) = (char *)"%d";
      *(undefined2 *)((int)piVar477 + 8) = unaff_SS;
      *(int *)((int)piVar477 + 6) = iVar404 + -0x13e;
      *(undefined2 *)((int)piVar477 + 4) = (char *)"steam bath" + 6;
      puVar478 = (undefined1 *)((int)piVar477 + 2);
      *(undefined2 *)((int)piVar477 + 2) = 0x22f;
      ovr_stsprintf((char *)*(undefined2 *)((int)piVar477 + 6),
                    (char *)*(undefined4 *)((int)piVar477 + 10),
                    (char *)*(undefined2 *)((int)piVar477 + 0xe));
      *(uint16_t *)(puVar478 + 0xc) = Font02.seg;
      *(uint16_t *)(puVar478 + 10) = Font02.ofs;
      *(undefined2 *)(puVar478 + 8) = unaff_SS;
      *(int *)(puVar478 + 6) = iVar404 + -0x13e;
      *(char **)(puVar478 + 4) = (char *)"glassworks" + 9;
      piVar479 = (int *)(puVar478 + 2);
      *(undefined2 *)(puVar478 + 2) = 0x24c;
      iVar488 = ovr_font_302d_06ea();
      uVar23 = 0xd4 - iVar488;
      TextBlitX = uVar23;
      piVar479[5] = 0x50;
      piVar479[4] = 0xde;
      piVar479[3] = Font02.seg;
      piVar479[2] = Font02.ofs;
      piVar479[1] = unaff_SS;
      *piVar479 = iVar404 + -0x13e;
      piVar479[-1] = (int)((char *)"steam bath" + 6);
      piVar480 = piVar479 + -2;
      piVar479[-2] = 0x27d;
      ovr_blitLabel(*(char **)piVar479,*(uint8_t **)(piVar479 + 2),piVar479[4],(uint8_t)piVar479[5])
      ;
      puVar470 = (undefined1 *)((int)piVar480 + 0x10);
      pcVar495 = pcVar495 + 1;
    }
    CurSfxType3 = 0x3c;
    *(undefined2 *)(puVar470 + -2) = unaff_SS;
    *(int *)(puVar470 + -4) = iVar404 + -0xe;
    *(undefined2 *)(puVar470 + -6) = 0;
    *(undefined2 *)(puVar470 + -8) = 0;
    *(far_t **)(puVar470 + -10) = pfVar24;
    *(undefined2 *)(puVar470 + -0xc) = unaff_SS;
    *(int *)(puVar470 + -0xe) = iVar404 + -0x66;
    *(char **)(puVar470 + -0x10) = (char *)"steam bath" + 6;
    puVar481 = puVar470 + -0x12;
    *(undefined2 *)(puVar470 + -0x12) = 0x327;
    uVar17 = ovr_OVC28_6018_1398();
    *(undefined1 *)(iVar404 + -0xd) = uVar17;
    DAT_2410_5cf0 = 0;
    if (((*(char *)(iVar404 + -0xd) != '\0') && (*(char *)(iVar404 + -0xd) != '\x01')) &&
       (*(char *)(iVar404 + -0xd) != -2)) {
      *(char *)((int)&pfVar24[-0x114f].ofs + iVar404) =
           *(char *)((int)&pfVar24[-0x114f].ofs + iVar404) + cVar18;
      pcVar21 = (char *)"puppetmaker" + 3;
      do {
        *(uint *)(puVar481 + 0x10) =
             CONCAT11((char)((int)pcVar21 * uVar23 >> 8),
                      *(undefined1 *)((int)pcVar21 * uVar23 + 0x21));
        pcVar21 = pcVar495;
        if (*(byte *)((int)pcVar495 * 0x34 + 0x22) < (byte)*(undefined2 *)(puVar481 + 0x10)) {
          *(uint *)(puVar481 + 0x10) =
               CONCAT11((char)((uint)((int)pcVar495 * 0x34) >> 8),
                        *(undefined1 *)((int)pcVar495 * 0x34 + 0x22));
          *(undefined1 *)((int)pcVar495 * 0x34 + 0x21) = (char)*(undefined2 *)(puVar481 + 0x10);
        }
        do {
          pcVar21 = pcVar21 + 1;
          if ((int)(uint)AgntCount <= (int)pcVar21) {
            *(undefined2 *)(puVar481 + 0x10) = *(undefined2 *)(iVar404 + 10);
            *(undefined2 *)(puVar481 + 0xe) = *(undefined2 *)(iVar404 + 8);
            *(char **)(puVar481 + 0xc) = (char *)"halfling outpost" + 4;
            puVar482 = (undefined2 *)(puVar481 + 10);
            *(undefined2 *)(puVar481 + 10) = 0xffc1;
            uVar20 = ovr_audio_3a5b_0afd();
            puVar482[3] = uVar20;
            puVar482[2] = 0;
            puVar482[1] = 0x1c;
            *puVar482 = (char *)"stonemasonry" + 0xc;
            puVar482[-1] = 0xffce;
            ovr_play_sfxU(*(byte *)(puVar482 + 1),puVar482[2],puVar482[3]);
            return (far_t *)((int)(undefined4 *)&_DATA + 1);
          }
        } while (*(int *)((int)pcVar21 * 0x34 + 0x1b) !=
                 *(int *)((int)*(undefined4 *)(iVar404 + 8) + 0x1b));
        if (*(byte *)((int)*(undefined4 *)(iVar404 + -6) + 0x32) <
            *(byte *)((int)pcVar21 * 0x34 + 0x22)) {
          *(undefined1 *)((int)pcVar21 * 0x34 + 0x22) =
               *(undefined1 *)((int)*(undefined4 *)(iVar404 + -6) + 0x32);
        }
        uVar23 = 0x34;
        pcVar495 = pcVar21;
      } while( true );
    }
    if (*(char *)(iVar404 + -0xd) == -2) {
      DAT_2410_4926 = 1;
    }
    return (far_t *)((char *)"puppetmaker" + 3);
  case 0xef:
    (*(uint8_t *)((uint8_t *)&(AgntAnms[0x70]) + 17)) = 0;
    *(undefined2 *)((int)&pfVar489[7].seg + iVar404) = pfVar37;
code_r0x0004fc81:
    GfxRndSeed = *(int *)(iVar404 + -4);
    iVar488 = *(int *)(iVar404 + -6);
    Highlight1 = 0xff;
    pfVar25 = (far_t *)((char *)"puppetmaker" + 3);
    Highlight1 = 0xff;
    GfxRndSeed2 = iVar488;
    if (*(int *)(iVar404 + 6) != 0xfe) {
      iVar490 = iVar488;
      for (iVar26 = 0; iVar26 < 0x1e; iVar26 = iVar26 + 1) {
        iVar490 = (int)((ulong)((long)iVar26 * 6) >> 0x10);
        pfVar25 = (far_t *)(uint)(&((unk01_t *)GStructures)->field0_0x0)[(int)((long)iVar26 * 6)];
        if (pfVar25 == (far_t *)*(undefined2 *)(iVar404 + 6)) break;
      }
      if (iVar26 == 0x1e) {
        Highlight1 = 0xff;
        Highlight1 = 0xff;
        return pfVar25;
      }
      if (*(char *)(iVar404 + 4) == -1) {
        *(undefined2 *)((int)puVar449 + -2) =
             *(undefined2 *)((int)&GStructures[0].field2_0x2 + 2 + iVar26 * 6);
        *(undefined2 *)((int)puVar449 + -4) =
             *(undefined2 *)((int)&GStructures[0].field2_0x2 + iVar26 * 6);
        *(undefined2 *)((int)puVar449 + -6) = (char *)"puppetmaker" + 3;
        *(undefined2 *)((int)puVar449 + -8) =
             (char *)"The %s belonging to all leaders are highlighted in red.";
        *(undefined2 *)((int)puVar449 + -10) = unaff_SS;
        *(int *)((int)puVar449 + -0xc) = iVar404 + -0x106;
        *(undefined2 *)((int)puVar449 + -0xe) = pcVar495;
        puVar453 = (undefined1 *)((int)puVar449 + -0x10);
        *(undefined2 *)((int)puVar449 + -0x10) = 0xfd5e;
        pfVar506 = (far_t *)ovr_stsprintf((char *)*(undefined2 *)((int)puVar449 + -0xc),
                                          (char *)*(undefined4 *)((int)puVar449 + -8),
                                          (char *)*(undefined2 *)((int)puVar449 + -4));
        pfVar24 = (far_t *)pfVar506;
        *(int *)(puVar453 + 0xe) = (int)((ulong)pfVar506 >> 0x10);
        *(far_t **)(puVar453 + 0xc) = pfVar24;
        *(char **)(puVar453 + 10) = (char *)"glassworks" + 9;
        *(undefined2 *)(puVar453 + 8) = 0xfd68;
        ovr_say(*(char **)(puVar453 + 0xc));
        return pfVar24;
      }
      *(undefined2 *)((int)puVar449 + -2) =
           CONCAT11((char)((uint)pfVar25 >> 8),*(undefined1 *)(iVar404 + 4));
      *(undefined2 *)((int)puVar449 + -4) = pcVar495;
      puVar451 = (undefined2 *)((int)puVar449 + -6);
      *(undefined2 *)((int)puVar449 + -6) = 0xfcf0;
      uVar20 = ovr_OVC22_5087_0119();
      puVar451[2] = iVar490;
      puVar451[1] = uVar20;
      bVar19 = *(byte *)(iVar404 + 4);
      *puVar451 = ((undefined2 *)((uint)bVar19 * 4))[1];
      puVar451[-1] = *(undefined2 *)((uint)bVar19 * 4);
      puVar451[-2] = *(undefined2 *)((int)&GStructures[0].field2_0x2 + 2 + iVar26 * 6);
      puVar451[-3] = *(undefined2 *)((int)&GStructures[0].field2_0x2 + iVar26 * 6);
      puVar451[-4] = (char *)"puppetmaker" + 3;
      puVar451[-5] = (char *)"The %s belonging to %s the %s are highlighted in red.";
      puVar451[-6] = unaff_SS;
      puVar451[-7] = iVar404 + -0x106;
      puVar451[-8] = (char *)"cleric outpost" + 0xd;
      puVar452 = puVar451 + -9;
      puVar451[-9] = 0xfd2e;
      pfVar506 = (far_t *)ovr_stsprintf((char *)puVar451[-7],*(char **)(puVar451 + -5),
                                        (char *)puVar451[-3]);
      pfVar24 = (far_t *)pfVar506;
      *(undefined2 *)((int)puVar452 + 0x16) = (int)((ulong)pfVar506 >> 0x10);
      *(undefined2 *)((int)puVar452 + 0x14) = pfVar24;
      *(undefined2 *)((int)puVar452 + 0x12) = (char *)"glassworks" + 9;
      *(undefined2 *)((int)puVar452 + 0x10) = 0xfd38;
      ovr_say((char *)*(undefined4 *)((int)puVar452 + 0x14));
      return pfVar24;
    }
    if (*(char *)(iVar404 + 4) != -1) {
      *(undefined2 *)((int)puVar449 + -2) = CONCAT11(0x24,*(undefined1 *)(iVar404 + 4));
      *(undefined2 *)((int)puVar449 + -4) = pcVar495;
      puVar454 = (undefined2 *)((int)puVar449 + -6);
      *(undefined2 *)((int)puVar449 + -6) = 0xfd7e;
      uVar20 = ovr_OVC22_5087_0119();
      puVar454[2] = iVar488;
      puVar454[1] = uVar20;
      bVar19 = *(byte *)(iVar404 + 4);
      *puVar454 = ((undefined2 *)((uint)bVar19 * 4))[1];
      puVar454[-1] = *(undefined2 *)((uint)bVar19 * 4);
      puVar454[-2] = (char *)"puppetmaker" + 3;
      puVar454[-3] = (char *)"The damaged structures belonging to %s the %s are highlighted in red."
      ;
      puVar454[-4] = unaff_SS;
      puVar454[-5] = iVar404 + -0x106;
      puVar454[-6] = (char *)"cleric outpost" + 0xd;
      puVar455 = puVar454 + -7;
      puVar454[-7] = 0xfdab;
      pfVar506 = (far_t *)ovr_stsprintf((char *)puVar454[-5],*(char **)(puVar454 + -3),
                                        (char *)puVar454[-1]);
      pfVar24 = (far_t *)pfVar506;
      *(undefined2 *)((int)puVar455 + 0x12) = (int)((ulong)pfVar506 >> 0x10);
      *(undefined2 *)((int)puVar455 + 0x10) = pfVar24;
      *(undefined2 *)((int)puVar455 + 0xe) = (char *)"glassworks" + 9;
      *(undefined2 *)((int)puVar455 + 0xc) = 0xfdb5;
      ovr_say((char *)*(undefined4 *)((int)puVar455 + 0x10));
      return pfVar24;
    }
    puVar45 = (undefined2 *)((int)puVar449 + -2);
    *(undefined2 *)((int)puVar449 + -2) = (char *)"puppetmaker" + 3;
    goto LAB_4d05_2d65_2;
  case 0xf0:
    uVar487 = CONCAT11(bVar39,bVar15 + bVar19) - 1;
    if (uVar487 != 0 && (byte)(bVar15 + bVar19) != '\0') {
      *(uint *)((int)pfVar24 + iVar404 + -0x712a) =
           *(uint *)((int)pfVar24 + iVar404 + -0x712a) & uVar487;
      return pfVar25;
    }
    if ((((*(byte *)((*pfVar25).ofs + 0x5d) & 0x10) != 0) &&
        (puVar32 = (undefined2 *)((int)puVar97 + 0x10),
        *(byte *)((int)&far_t_ARRAY_2410_26f7[8].seg + (uint)*(byte *)(iVar404 + 0xc) * 0x95) < 5))
       && (puVar32 = (undefined2 *)((int)puVar97 + 0x10),
          *(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)*(byte *)(iVar404 + 0xc) * 0x95)
          != -1)) goto LAB_4207_1503;
LAB_4207_151b:
    if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)*(byte *)(iVar404 + 0xc) * 0x95) ==
        -1) {
      iVar488 = (uint)*(byte *)(Entities.ofs + (int)EntityCount * 0x37 + 0xf) * 4;
      uVar20 = *(undefined2 *)(iVar488 + -4);
      *(undefined2 *)((int)puVar32 + -2) = *(undefined2 *)(iVar488 + -2);
      pfVar24 = EntityCount;
      *(undefined2 *)((int)puVar32 + -4) = uVar20;
      uVar23 = Entities.seg;
      iVar488 = Entities.ofs + (int)pfVar24 * 0x37;
      uVar20 = *(undefined2 *)((int)puVar32 + -4);
      *(undefined2 *)(iVar488 + 0x12) = *(undefined2 *)((int)puVar32 + -2);
      *(undefined2 *)(iVar488 + 0x10) = uVar20;
    }
    else {
      *(int *)((int)puVar32 + -2) =
           (uint)*(byte *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 +
                          (uint)*(byte *)(iVar404 + 0xc) * 0x95) * 0x94;
      iVar488 = *(int *)((int)puVar32 + -2) +
                (uint)*(byte *)(Entities.ofs + (int)EntityCount * 0x37 + 0xf) * 4;
      uVar20 = *(undefined2 *)(iVar488 + -4);
      *(undefined2 *)((int)puVar32 + -2) = *(undefined2 *)(iVar488 + -2);
      pfVar24 = EntityCount;
      *(undefined2 *)((int)puVar32 + -4) = uVar20;
      uVar23 = Entities.seg;
      iVar488 = Entities.ofs + (int)pfVar24 * 0x37;
      uVar20 = *(undefined2 *)((int)puVar32 + -4);
      *(undefined2 *)(iVar488 + 0x12) = *(undefined2 *)((int)puVar32 + -2);
      *(undefined2 *)(iVar488 + 0x10) = uVar20;
    }
    uVar23 = Entities.seg;
    iVar488 = Entities.ofs + (int)EntityCount * 0x37;
    if (*(int *)(iVar488 + 0x10) == 0 && *(int *)(iVar488 + 0x12) == 0) {
      iVar488 = Entities.ofs + (int)EntityCount * 0x37;
      *(undefined2 *)(iVar488 + 0x12) = 0;
      *(undefined2 *)(iVar488 + 0x10) = 100;
    }
    *(undefined2 *)(iVar404 + -4) = EntityCount;
    EntityCount = (uint16_t)(((int)&EntityCount->ofs + 1));
    *(undefined2 *)((int)puVar32 + -2) = 0x4000;
    pcVar495 = (char *)"ringmaker\'s shop" + 7;
    puVar127 = (undefined1 *)((int)puVar32 + -4);
    *(undefined2 *)((int)puVar32 + -4) = (char *)"spore3.voc";
    ovr_attact_3f0b_0c2a();
    puVar129 = puVar127 + -0xffffffffffff5ced;
    puVar36 = (undefined2 *)(puVar127 + -0xffffffffffff5ced);
    if (AgntFlag1 != false) {
code_r0x00043691:
      puVar129 = (undefined1 *)puVar36;
      *(int *)(puVar129 + -2) = GfxRndSeed + -2;
      if (*(uint *)(puVar129 + -2) <= *(uint *)(Entities.ofs + *(int *)(iVar404 + -4) * 0x37)) {
        *(int *)(puVar129 + -2) = GfxRndSeed + 1;
        if ((*(uint *)(Entities.ofs + *(int *)(iVar404 + -4) * 0x37) <= *(uint *)(puVar129 + -2)) &&
           (*(int *)(Entities.ofs + *(int *)(iVar404 + -4) * 0x37 + 2) == GfxRndSeed2)) {
          *(undefined2 *)(puVar129 + -2) = 0;
          *(undefined2 *)(puVar129 + -4) = 0;
          *(undefined2 *)(puVar129 + -6) = *(undefined2 *)(iVar404 + -4);
          *(char **)(puVar129 + -8) = pcVar495;
          puVar128 = puVar129 + -10;
          *(char **)(puVar129 + -10) = (char *)"volume.xmi" + 8;
          OVC15_4207_2301();
          puVar129 = puVar128 + 10;
        }
      }
    }
    *(int *)(puVar129 + -2) = *(int *)(iVar404 + -4) * 0x37;
    pfVar24 = (far_t *)(Entities.ofs + *(int *)(puVar129 + -2));
    return pfVar24;
  case 0xf3:
    pfVar489->ofs = (uint16_t)in_CX;
    pcVar508 = (char *)((int)&pfVar489->ofs + (int)(pfVar37 + 0x904));
    *pcVar508 = *pcVar508 + bVar38;
code_r0x000408ca:
    if (*(bool *)&DebugVerbose != false) {
      *(undefined2 *)((int)puVar88 + -2) = DAT_2000_d165;
      *(undefined2 *)((int)puVar88 + -4) = DAT_2000_d163;
      *(undefined2 *)((int)puVar88 + -6) = GGameState;
      *(undefined2 *)((int)puVar88 + -8) = (char *)"puppetmaker" + 3;
      *(undefined2 *)((int)puVar88 + -10) = 0x8ea;
      *(undefined2 *)((int)puVar88 + -0xc) = pcVar495;
      pcVar495 = (char *)0x1000;
      puVar87 = (undefined1 *)((int)puVar88 + -0xe);
      *(undefined2 *)((int)puVar88 + -0xe) = 0x8ef;
      printf((char *)*(undefined4 *)((int)puVar88 + -10),*(undefined2 *)((int)puVar88 + -6));
      puVar88 = (undefined2 *)(puVar87 + 0xe);
    }
    *(undefined2 *)((int)puVar88 + -2) = unaff_SS;
    *(int *)((int)puVar88 + -4) = iVar404 + -0x17;
    *(undefined2 *)((int)puVar88 + -6) = pcVar495;
    pcVar495 = (char *)"dwarf outpost" + 6;
    puVar89 = (undefined1 *)((int)puVar88 + -8);
    *(undefined2 *)((int)puVar88 + -8) = 0x8fc;
    ovr_OVC24_5943_0d5a();
    puVar90 = puVar89 + 8;
    GGameState = 0x1f;
    if (*(char *)(iVar404 + -0x17) != '\0') {
      *(char **)(puVar89 + 6) = (char *)"dwarf outpost" + 6;
      pcVar495 = (char *)"stonemasonry" + 3;
      puVar91 = puVar89 + 4;
      *(undefined2 *)(puVar89 + 4) = 0x916;
      ovr_constr_36ce_03a6();
      puVar90 = puVar91 + 4;
      GGameState = 0x13;
    }
    *(char **)(puVar90 + -2) = pcVar495;
    puVar483 = (undefined1 *)ZEXT24(puVar90 + -4);
                    /* WARNING: Call to offcut address within same function */
    *(undefined2 *)(puVar90 + -4) = 0x926;
    func_0x0004f68f();
    GGameState = 0x1d;
    for (iVar488 = 0; puVar94 = (undefined1 *)puVar483, iVar488 < 5; iVar488 = iVar488 + 1) {
      if (*(char *)(iVar404 + iVar488 + -0xe) != '\0') {
        *(int *)(puVar94 + -2) = iVar488;
        *(char **)(puVar94 + -4) = pcVar495;
        pcVar495 = (char *)"builder\'s hall" + 8;
        puVar92 = puVar94 + -6;
        *(undefined2 *)(puVar94 + -6) = 0x942;
        ovr_OVC41_6a8f_1be0();
        puVar483 = (undefined1 *)(ulong)((int)puVar92 + 6);
      }
    }
    GGameState = 0xd;
    if (DebugVerbose != false) {
      *(undefined2 *)(puVar94 + -2) = DAT_2000_d165;
      *(undefined2 *)(puVar94 + -4) = DAT_2000_d163;
      *(undefined2 *)(puVar94 + -6) = GGameState;
      *(char **)(puVar94 + -8) = (char *)"puppetmaker" + 3;
      *(undefined2 *)(puVar94 + -10) = 0x8ea;
      *(char **)(puVar94 + -0xc) = pcVar495;
      pcVar495 = (char *)0x1000;
      puVar93 = puVar94 + -0xe;
      *(undefined2 *)(puVar94 + -0xe) = 0x98b;
      printf(*(char **)(puVar94 + -10),*(undefined2 *)(puVar94 + -6));
      puVar94 = puVar93 + 0xe;
    }
    *(char **)(puVar94 + -2) = pcVar495;
    *(undefined2 *)(puVar94 + -4) = 0x993;
    ovr_OVC24_5943_112e();
    GGameState = 0xe;
    DAT_2410_648e = 1;
    return (far_t *)((char *)"puppetmaker" + 3);
  }
  if ((bVar19 & *(byte *)((int)&pfVar24[0xb0].seg + iVar404)) == 0) {
    iVar488 = *(int *)(iVar404 + 6);
    pcVar4 = (code *)*(uint *)(iVar404 + 4);
    *(undefined2 *)((int)puVar208 + -2) = 0x4000;
    pcVar495 = (char *)0x1000;
    puVar209 = (undefined2 *)((int)puVar208 + -4);
    *(undefined2 *)((int)puVar208 + -4) = 0x87aa;
    lVar502 = LXRSH_at_((long)CONCAT22(iVar488 + (uint)((code *)init_3381_08dc < pcVar4),
                                       pcVar4 + 0x13),0x4);
    uVar8 = (ulong)HeapPtr;
    *(undefined2 *)(iVar404 + -0xc) = (int)(lVar502 + uVar8 >> 0x10);
    *(undefined2 *)(iVar404 + -0xe) = (int)(lVar502 + uVar8);
    if (*(int *)(iVar404 + -0xc) == 0) {
      pfVar24 = (far_t *)*(undefined2 *)(iVar404 + -0xe);
    }
    else {
      pfVar24 = (far_t *)0xffff;
    }
    if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) &&
        ((*(int *)(iVar404 + -0xc) != 0 || (MUSHandle.seg < *(uint *)(iVar404 + -0xe))))) ||
       ((puVar211 = puVar209 + 2, DIGHandle.ofs != 0 || DIGHandle.seg != 0 &&
        ((*(int *)(iVar404 + -0xc) != 0 ||
         (puVar211 = puVar209 + 2, MUSHandle.seg < *(uint *)(iVar404 + -0xe))))))) {
      puVar209[1] = 1;
      *puVar209 = 0x1000;
      pcVar495 = (char *)"stonemasonry" + 0xc;
      puVar210 = puVar209 + -1;
      puVar209[-1] = (char *)_dosErrorToSV + 0x42;
      ovr_fmFreeAudio(puVar209[1]);
      puVar211 = (undefined2 *)((int)puVar210 + 6);
    }
    *(undefined2 *)(iVar404 + -10) = 0xffff;
    HeapPtr = 0xffff;
    uVar487 = 0xffff;
    *(undefined1 *)(iVar404 + -7) = 0;
    uVar23 = StshCtPtr2.ofs;
    *(uint16_t *)(iVar404 + -4) = StshCtPtr2.seg;
    *(uint16_t *)(iVar404 + -6) = uVar23;
    while (*(int *)(iVar404 + -6) != 0 || *(int *)(iVar404 + -4) != 0) {
      uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
      iVar488 = (int)*(undefined4 *)(iVar404 + -6);
      if (*(int *)(iVar488 + 0x11) != 0 || *(int *)(iVar488 + 0x13) != 0) {
        if ((far_t *)*(undefined2 *)((int)*(undefined4 *)(iVar404 + -6) + 0x13) < pfVar24) {
          uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
          iVar488 = (int)*(undefined4 *)(iVar404 + -6);
          *(undefined2 *)((int)puVar211 + -2) = *(undefined2 *)(iVar488 + 0x13);
          *(undefined2 *)((int)puVar211 + -4) = *(undefined2 *)(iVar488 + 0x11);
          *(undefined2 *)((int)puVar211 + -6) = pcVar495;
          puVar212 = (undefined1 *)((int)puVar211 + -8);
          *(undefined2 *)((int)puVar211 + -8) = (uint8_t *)vprinter_printCtype + 0x34;
          stshFree(*(far_t *)((int)puVar211 + -4));
          puVar211 = (undefined2 *)(puVar212 + 8);
          uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
          iVar488 = (int)*(undefined4 *)(iVar404 + -6);
          *(undefined2 *)(iVar488 + 0x13) = 0;
          *(undefined2 *)(iVar488 + 0x11) = 0;
          *(undefined1 *)(iVar404 + -7) = 1;
        }
        else {
          if (*(uint *)((int)*(undefined4 *)(iVar404 + -6) + 0x13) < uVar487) {
            *(uint *)(iVar404 + -10) = uVar487;
            uVar487 = *(uint *)((int)*(undefined4 *)(iVar404 + -6) + 0x13);
            uVar20 = *(undefined2 *)(iVar404 + -6);
            *(undefined2 *)(iVar404 + -0x10) = *(undefined2 *)(iVar404 + -4);
            *(undefined2 *)(iVar404 + -0x12) = uVar20;
          }
          if (*(uint *)((int)*(undefined4 *)(iVar404 + -6) + 0x13) < HeapPtr) {
            HeapPtr = *(uint *)((int)*(undefined4 *)(iVar404 + -6) + 0x13);
          }
        }
      }
      uVar493 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -6) >> 0x10);
      iVar488 = (int)*(undefined4 *)(iVar404 + -6);
      uVar20 = *(undefined2 *)(iVar488 + 9);
      *(undefined2 *)(iVar404 + -4) = *(undefined2 *)(iVar488 + 0xb);
      *(undefined2 *)(iVar404 + -6) = uVar20;
    }
    if (*(char *)(iVar404 + -7) == '\0') {
      if (uVar487 == 0xffff) {
        *(undefined2 *)((int)puVar211 + -2) = 1;
        *(undefined2 *)((int)puVar211 + -4) = pcVar495;
        pcVar495 = (char *)"stonemasonry" + 0xc;
        puVar213 = (undefined1 *)((int)puVar211 + -6);
        *(undefined2 *)((int)puVar211 + -6) = (undefined2 *)&_stdinStarted;
        bVar499 = ovr_fmFreeAudio(*(uint16_t *)((int)puVar211 + -2));
        pfVar25 = (far_t *)(uint)bVar499;
        puVar214 = (undefined2 *)(puVar213 + 6);
code_r0x00048906:
        if (((byte)pfVar25 & *(byte *)((int)&pfVar24[0xb0].seg + iVar404)) != 0) {
          return (far_t *)((int)(undefined4 *)&_DATA + 1);
        }
        if (DAT_2410_2a4e == '\0') {
          *(undefined2 *)((int)puVar214 + -2) = 0x14;
                    /* WARNING: Subroutine does not return */
          *(undefined2 *)((int)puVar214 + -4) = pcVar495;
          *(undefined2 *)((int)puVar214 + -6) = 0x8927;
          ovr_stExit(*(int *)((int)puVar214 + -2));
        }
        return (far_t *)0x0;
      }
LAB_474a_148a:
      uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -0x12) >> 0x10);
      iVar488 = (int)*(undefined4 *)(iVar404 + -0x12);
      *(undefined2 *)((int)puVar211 + -2) = *(undefined2 *)(iVar488 + 0x13);
      *(undefined2 *)((int)puVar211 + -4) = *(undefined2 *)(iVar488 + 0x11);
      *(undefined2 *)((int)puVar211 + -6) = pcVar495;
      *(undefined2 *)((int)puVar211 + -8) = 0x8939;
      stshFree(*(far_t *)((int)puVar211 + -4));
      uVar20 = (undefined2)((ulong)*(undefined4 *)(iVar404 + -0x12) >> 0x10);
      iVar488 = (int)*(undefined4 *)(iVar404 + -0x12);
      *(undefined2 *)(iVar488 + 0x13) = 0;
      *(undefined2 *)(iVar488 + 0x11) = 0;
      HeapPtr = *(uint *)(iVar404 + -10);
    }
    pfVar24 = (far_t *)((int)(undefined4 *)&_DATA + 1);
  }
  else {
    pfVar24 = (far_t *)CONCAT11(bVar29,1);
  }
                    /* WARNING: Read-only address (ram,0x000247db) is written */
                    /* WARNING: Read-only address (ram,0x00025f50) is written */
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
                    /* WARNING: Read-only address (ram,0x00027f80) is written */
  return pfVar24;
}




/* 4d05:217a */

/* Long itoa in base 10 */

char * __cdecl16far litoa10(char *buf,long n)

{
  bool bVar1;
  size_t len;
  long digit;
  undefined2 in_stack_00000006;
  
  if ((n < 0x10000) && (n < 0)) {
    bVar1 = true;
    n = CONCAT22(-(uint)((int)n != 0) - (*(uint16_t *)((uint8_t *)&(n) + 2)),-(int)n);
  }
  else {
    bVar1 = false;
  }
  digit = LMOD_at_(n,10);
  *_buf = (char)digit + '0';
  buf[1] = '\0';
  while (digit = LDIV_at_(n,10), digit != 0) {
    len = strlen(buf);
    if ((len & 3) == 3) {
      len = strlen(buf);
      _fmemmove((uint8_t *)(buf + 1),(uint8_t *)buf,len + 1);
      *_buf = ',';
    }
    len = strlen(buf);
    _fmemmove((uint8_t *)(buf + 1),(uint8_t *)buf,len + 1);
    n = LDIV_at_(n,10);
    digit = LMOD_at_(n,10);
    *_buf = (char)digit + '0';
  }
  if (bVar1) {
    len = strlen(buf);
    _fmemmove((uint8_t *)(buf + 1),(uint8_t *)buf,len + 1);
    *_buf = '-';
  }
  return buf;
}



/* 4d05:22b3 */

void __cdecl16far manage_4d05_22b3(void)

{
  undefined2 *in_stack_0000000a;
  undefined2 *in_stack_0000000e;
  
  *in_stack_0000000a = 0;
  *in_stack_0000000e = 0;
  if (EntityCount != 0) {
    manage_4d05_22cf();
    return;
  }
  return;
}



/* 4d05:22cf */

void __cdecl16far manage_4d05_22cf(void)

{
  char in_CL;
  uint16_t uVar1;
  int unaff_BP;
  int unaff_SI;
  uint16_t uVar2;
  undefined2 unaff_SS;
  
  if (in_CL != -1) {
    manage_4d05_2371();
    return;
  }
  uVar2 = Entities.seg;
  uVar1 = Entities.ofs;
  if (((*(char *)((int)(char **)GMenuStrings +
                 (uint)*(byte *)(uVar1 + unaff_SI * 0x37 + 0xd) * 0x95 + 0x1f) == '\0') &&
      (*(byte *)(unaff_BP + 8) <= *(byte *)(uVar1 + unaff_SI * 0x37 + 0xf))) &&
     (*(byte *)(uVar1 + unaff_SI * 0x37 + 0xf) <= *(byte *)(unaff_BP + 10))) {
    *(int *)*(undefined4 *)(unaff_BP + 0xc) = *(int *)*(undefined4 *)(unaff_BP + 0xc) + 1;
    *(int *)*(undefined4 *)(unaff_BP + 0x10) =
         *(int *)*(undefined4 *)(unaff_BP + 0x10) +
         (uint)*(byte *)(Entities.ofs + unaff_SI * 0x37 + 0xe);
  }
  if (EntityCount <= unaff_SI + 1U) {
    return;
  }
  manage_4d05_22cf();
  return;
}



/* 4d05:2371 */

void __cdecl16far manage_4d05_2371(void)

{
  char in_CL;
  uint16_t uVar1;
  int unaff_BP;
  int unaff_SI;
  uint16_t uVar2;
  undefined2 unaff_SS;
  
  uVar2 = Entities.seg;
  uVar1 = Entities.ofs;
  if (((*(char *)(uVar1 + unaff_SI * 0x37 + 0x1a) == in_CL) &&
      (*(byte *)(unaff_BP + 8) <= *(byte *)(uVar1 + unaff_SI * 0x37 + 0xf))) &&
     (*(byte *)(uVar1 + unaff_SI * 0x37 + 0xf) <= *(byte *)(unaff_BP + 10))) {
    *(int *)*(undefined4 *)(unaff_BP + 0xc) = *(int *)*(undefined4 *)(unaff_BP + 0xc) + 1;
    *(int *)*(undefined4 *)(unaff_BP + 0x10) =
         *(int *)*(undefined4 *)(unaff_BP + 0x10) +
         (uint)*(byte *)(Entities.ofs + unaff_SI * 0x37 + 0xe);
  }
  if (unaff_SI + 1U < EntityCount) {
    manage_4d05_22cf();
    return;
  }
  return;
}



/* 4d05:23fc */

int __cdecl16far
manage_4d05_23fc(char param_1,char param_2,int *param_3,int *param_4,int *param_5,int *param_6,
                int *param_7,int *param_8,int *param_9)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined2 uVar6;
  int iStack_4;
  
  iStack_4 = 0;
  *param_3 = 0;
  *param_4 = 0;
  *param_5 = 0;
  *param_6 = 0;
  *param_7 = 0;
  *param_8 = 0;
  *param_9 = 0;
  uVar5 = 0xf8;
  while( true ) {
    if (DAT_2000_ca99 <= uVar5) {
      for (uVar5 = 0; uVar5 < DAT_2000_d2df; uVar5 = uVar5 + 1) {
        if ((*(char *)(uVar5 * 0x12 + 9) == param_1) &&
           (bVar1 = *(byte *)(uVar5 * 0x12 + 8), *(char *)((uint)bVar1 * 0x27 + 0x133) == param_2))
        {
          *param_6 = *param_6 + 1;
          if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x01') {
            *param_7 = *param_7 + 1;
          }
          else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x02') {
            *param_8 = *param_8 + 1;
          }
          else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x03') {
            *param_9 = *param_9 + 1;
          }
        }
      }
      iVar4 = *param_8;
      iVar2 = *param_9;
      *param_3 = *param_3 - *param_8;
      *param_4 = *param_4 - *param_9;
      return iStack_4 - (iVar4 + iVar2);
    }
    if (param_1 != -1) break;
    uVar6 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
    iVar4 = (int)DAT_2000_ca95;
    if (((*(char *)(iVar4 + uVar5 * 9 + 2) != -1) &&
        (uVar3 = *(undefined4 *)((uint)*(byte *)(iVar4 + uVar5 * 9 + 2) << 2),
        *(char *)((int)uVar3 + 0x3f) == '\0')) &&
       (bVar1 = *(byte *)(iVar4 + uVar5 * 9), *(char *)((uint)bVar1 * 0x27 + 0x133) == param_2)) {
      iStack_4 = iStack_4 + 1;
      if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x01') {
        *param_3 = *param_3 + 1;
      }
      else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x02') {
        *param_4 = *param_4 + 1;
      }
      else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x03') {
        *param_5 = *param_5 + 1;
      }
    }
    uVar5 = uVar5 + 1;
  }
  iVar4 = manage_4d05_2543();
  return iVar4;
}



/* 4d05:2543 */

undefined2 __cdecl16far manage_4d05_2543(void)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_BP;
  uint unaff_SI;
  uint uVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  
  uVar5 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
  if ((*(char *)((int)DAT_2000_ca95 + unaff_SI * 9 + 2) == *(char *)(unaff_BP + 6)) &&
     (bVar1 = *(byte *)((int)DAT_2000_ca95 + unaff_SI * 9),
     *(char *)((uint)bVar1 * 0x27 + 0x133) == *(char *)(unaff_BP + 8))) {
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
    if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x01') {
      *(int *)*(undefined4 *)(unaff_BP + 10) = *(int *)*(undefined4 *)(unaff_BP + 10) + 1;
    }
    else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x02') {
      *(int *)*(undefined4 *)(unaff_BP + 0xe) = *(int *)*(undefined4 *)(unaff_BP + 0xe) + 1;
    }
    else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x03') {
      *(int *)*(undefined4 *)(unaff_BP + 0x12) = *(int *)*(undefined4 *)(unaff_BP + 0x12) + 1;
    }
  }
  while( true ) {
    unaff_SI = unaff_SI + 1;
    if (DAT_2000_ca99 <= unaff_SI) {
      for (uVar4 = 0; uVar4 < DAT_2000_d2df; uVar4 = uVar4 + 1) {
        if ((*(char *)(uVar4 * 0x12 + 9) == *(char *)(unaff_BP + 6)) &&
           (bVar1 = *(byte *)(uVar4 * 0x12 + 8),
           *(char *)((uint)bVar1 * 0x27 + 0x133) == *(char *)(unaff_BP + 8))) {
          *(int *)*(undefined4 *)(unaff_BP + 0x16) = *(int *)*(undefined4 *)(unaff_BP + 0x16) + 1;
          if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x01') {
            *(int *)*(undefined4 *)(unaff_BP + 0x1a) = *(int *)*(undefined4 *)(unaff_BP + 0x1a) + 1;
          }
          else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x02') {
            *(int *)*(undefined4 *)(unaff_BP + 0x1e) = *(int *)*(undefined4 *)(unaff_BP + 0x1e) + 1;
          }
          else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x03') {
            *(int *)*(undefined4 *)(unaff_BP + 0x22) = *(int *)*(undefined4 *)(unaff_BP + 0x22) + 1;
          }
        }
      }
      *(int *)(unaff_BP + -2) =
           *(int *)(unaff_BP + -2) -
           (*(int *)*(undefined4 *)(unaff_BP + 0x1e) + *(int *)*(undefined4 *)(unaff_BP + 0x22));
      *(int *)*(undefined4 *)(unaff_BP + 10) =
           *(int *)*(undefined4 *)(unaff_BP + 10) - *(int *)*(undefined4 *)(unaff_BP + 0x1e);
      *(int *)*(undefined4 *)(unaff_BP + 0xe) =
           *(int *)*(undefined4 *)(unaff_BP + 0xe) - *(int *)*(undefined4 *)(unaff_BP + 0x22);
      return *(undefined2 *)(unaff_BP + -2);
    }
    if (*(char *)(unaff_BP + 6) != -1) break;
    uVar5 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
    iVar3 = (int)DAT_2000_ca95;
    if (((*(char *)(iVar3 + unaff_SI * 9 + 2) != -1) &&
        (uVar2 = *(undefined4 *)((uint)*(byte *)(iVar3 + unaff_SI * 9 + 2) << 2),
        *(char *)((int)uVar2 + 0x3f) == '\0')) &&
       (bVar1 = *(byte *)(iVar3 + unaff_SI * 9),
       *(char *)((uint)bVar1 * 0x27 + 0x133) == *(char *)(unaff_BP + 8))) {
      *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
      if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x01') {
        *(int *)*(undefined4 *)(unaff_BP + 10) = *(int *)*(undefined4 *)(unaff_BP + 10) + 1;
      }
      else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x02') {
        *(int *)*(undefined4 *)(unaff_BP + 0xe) = *(int *)*(undefined4 *)(unaff_BP + 0xe) + 1;
      }
      else if (*(char *)((uint)bVar1 * 0x27 + 0x131) == '\x03') {
        *(int *)*(undefined4 *)(unaff_BP + 0x12) = *(int *)*(undefined4 *)(unaff_BP + 0x12) + 1;
      }
    }
  }
  uVar5 = manage_4d05_2543();
  return uVar5;
}



/* 4d05:26f6 */

void __cdecl16far manage_4d05_26f6(byte param_1)

{
  long lVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 uVar5;
  char *pcVar4;
  int iVar6;
  int iVar7;
  undefined2 unaff_SS;
  char *pcVar8;
  far_t gfx;
  uint8_t *puVar9;
  uint16_t uVar10;
  undefined1 uVar11;
  uint8_t term;
  undefined2 uVar12;
  uint8_t local_158 [20];
  undefined2 local_144 [10];
  undefined2 local_130 [60];
  char acStack_b8 [80];
  char acStack_68 [80];
  undefined1 uStack_18;
  char cStack_17;
  char *pcStack_16;
  int iStack_14;
  int iStack_12;
  int iStack_10;
  int iStack_e;
  char *pcStack_c;
  char *pcStack_a;
  char *pcStack_8;
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  F_SCOPY(local_158,(uint8_t *)(far_t *)far_t_ARRAY_2410_4ada,0x14);
  for (iVar6 = 0; iVar6 < 5; iVar6 = iVar6 + 1) {
    uVar12 = *(undefined2 *)(local_158 + iVar6 * 4);
    local_144[iVar6 * 2 + 1] = *(undefined2 *)(local_158 + iVar6 * 4 + 2);
    local_144[iVar6 * 2] = uVar12;
  }
  for (iVar6 = 0; iVar6 < 0x1e; iVar6 = iVar6 + 1) {
    uVar12 = *(undefined2 *)((int)&GStructures[0].field2_0x2 + iVar6 * 6);
    local_130[iVar6 * 2 + 1] = *(undefined2 *)((int)&GStructures[0].field2_0x2 + 2 + iVar6 * 6);
    local_130[iVar6 * 2] = uVar12;
  }
  cStack_17 = '\x02';
  manage_4d05_0081();
  uStack_18 = 0;
  if (((cStack_17 != '\x02') && (cStack_17 != '\x03')) && (cStack_17 != '\x04')) {
    manage_4d05_2b09();
    return;
  }
  if (DAT_2410_26a8 == '\0') {
    manage_4d05_0081();
  }
  else {
    gfx.seg = DAT_2000_cc87;
    gfx.ofs = DAT_2000_cc85;
    ovr_blitGfxRect(gfx,0,0,BlitRects + 1,0x10,false);
  }
  TextBlitY = 0xc;
  TextBlitX = 0x11;
  if (param_1 == 0xff) {
    ovr_blitLabel("All property.",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0x50);
  }
  else {
    uStack_4 = ((undefined2 *)((uint)param_1 * 4))[1];
    uVar12 = *(undefined2 *)((uint)param_1 * 4);
    term = 0x50;
    uVar5 = 0xde;
    uVar11 = 0;
    puVar9 = (uint8_t *)Font02.ofs;
    uVar10 = Font02.seg;
    uStack_6 = uVar12;
    uVar2 = ovr_OVC45_77eb_226e(acStack_68);
    pcVar4 = (char *)manage_4d05_03a4(uStack_6,uStack_4,uVar2,uVar12);
    pcVar8 = ovr_stsprintf(acStack_b8,"Buildings belonging to %s%s",pcVar4);
    ovr_blitLabel(pcVar8,(uint8_t *)CONCAT22(uVar10,puVar9),CONCAT11(uVar11,uVar5),term);
  }
  TextBlitY = TextBlitY + 0xc;
  TextBlitX = 0x11;
  ovr_blitLabel("Buildings",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
  manage_4d05_0519((char *)"Total",(char *)"puppetmaker" + 3,100,0xe0);
  manage_4d05_0519((char *)"Level 1",(char *)"puppetmaker" + 3,0x8c,0xe0);
  manage_4d05_0519((char *)"Level 2",(char *)"puppetmaker" + 3,0xb4,0xe0);
  manage_4d05_0519((char *)"Level 3",(char *)"puppetmaker" + 3,0xdc,0xe0);
  TextBlitY = TextBlitY + 0xc;
  if (cStack_17 == '\x04') {
    iVar6 = 0x1a;
  }
  else if (cStack_17 == '\x03') {
    iVar6 = 0xd;
  }
  else {
    iVar6 = 0;
  }
  for (iVar7 = 0; iVar7 < 0xd; iVar7 = iVar7 + 1) {
    if (iVar7 + iVar6 < 0x1e) {
      TextBlitX = 0x11;
      iVar3 = (iVar7 + iVar6) * 6;
      ovr_blitLabel((char *)CONCAT22(*(undefined2 *)((int)&GStructures[0].field2_0x2 + 2 + iVar3),
                                     (char *)*(undefined2 *)
                                              ((int)&GStructures[0].field2_0x2 + iVar3)),
                    (uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
      lVar1 = (long)(iVar7 + iVar6) * 6;
      uVar11 = (undefined1)((ulong)lVar1 >> 0x10);
      uVar5 = (undefined1)((ulong)lVar1 >> 8);
      pcStack_16 = (char *)manage_4d05_23fc(CONCAT11(uVar5,param_1),
                                            CONCAT11(uVar5,(&((unk01_t *)GStructures)->field0_0x0)
                                                           [(int)lVar1]),&pcStack_8);
      if (iStack_e == 0) {
        uVar12 = 100;
        pcVar4 = litoa10(acStack_68,ZEXT24(pcStack_16));
        manage_4d05_04c6(pcVar4,uVar11,uVar12);
      }
      else {
        uVar12 = 100;
        pcVar8 = ovr_stsprintf(acStack_b8,"%d (%d)",pcStack_16);
        manage_4d05_04c6((char *)pcVar8,(char)((ulong)pcVar8 >> 0x10),uVar12);
      }
      lVar1 = (long)(iVar7 + iVar6) * 6;
      uVar5 = (undefined1)((ulong)lVar1 >> 0x10);
      if (*(char *)((int)&GStructures[0].field1_0x1 + (int)lVar1) != '\0') {
        if (iStack_10 == 0) {
          uVar12 = 0x8c;
          pcVar4 = litoa10(acStack_68,ZEXT24(pcStack_8));
          manage_4d05_04c6(pcVar4,uVar5,uVar12);
        }
        else {
          uVar12 = 0x8c;
          pcVar8 = ovr_stsprintf(acStack_b8,"%d (%d)",pcStack_8);
          uVar5 = (undefined1)((ulong)pcVar8 >> 0x10);
          manage_4d05_04c6((char *)pcVar8,uVar5,uVar12);
        }
        if (iStack_12 == 0) {
          uVar12 = 0xb4;
          pcVar4 = litoa10(acStack_68,ZEXT24(pcStack_a));
          manage_4d05_04c6(pcVar4,uVar5,uVar12);
        }
        else {
          uVar12 = 0xb4;
          pcVar8 = ovr_stsprintf(acStack_b8,"%d (%d)",pcStack_a);
          uVar5 = (undefined1)((ulong)pcVar8 >> 0x10);
          manage_4d05_04c6((char *)pcVar8,uVar5,uVar12);
        }
        if (iStack_14 == 0) {
          uVar12 = 0xdc;
          pcVar4 = litoa10(acStack_68,ZEXT24(pcStack_c));
          manage_4d05_04c6(pcVar4,uVar5,uVar12);
        }
        else {
          uVar12 = 0xdc;
          pcVar8 = ovr_stsprintf(acStack_b8,"%d (%d)",pcStack_c);
          manage_4d05_04c6((char *)pcVar8,(char)((ulong)pcVar8 >> 0x10),uVar12);
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
  }
  CurSfxType3 = 0x3c;
  cStack_17 = ovr_OVC28_6018_1398();
  DAT_2410_5cf0 = 0;
  if (((cStack_17 != '\0') && (cStack_17 != '\x01')) && (cStack_17 != -2)) {
    manage_4d05_277a();
    return;
  }
  if ((DAT_2410_26a8 == '\0') && (cStack_17 != -2)) {
    manage_4d05_0081();
  }
  if (cStack_17 == -2) {
    DAT_2410_4926 = 1;
  }
  return;
}



/* 4d05:277a */

void __cdecl16far manage_4d05_277a(void)

{
  long lVar1;
  undefined1 uVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  int iVar5;
  undefined2 uVar6;
  char *pcVar7;
  int unaff_BP;
  int iVar8;
  int iVar9;
  undefined2 unaff_SS;
  char *pcVar10;
  far_t gfx;
  uint8_t *puVar11;
  uint16_t uVar12;
  undefined1 uVar13;
  uint8_t term;
  
  if (((*(char *)(unaff_BP + -0x15) != '\x02') && (*(char *)(unaff_BP + -0x15) != '\x03')) &&
     (*(char *)(unaff_BP + -0x15) != '\x04')) {
    manage_4d05_2b09();
    return;
  }
  if (DAT_2410_26a8 == '\0') {
    manage_4d05_0081();
  }
  else {
    gfx.seg = DAT_2000_cc87;
    gfx.ofs = DAT_2000_cc85;
    ovr_blitGfxRect(gfx,0,0,BlitRects + 1,0x10,false);
  }
  TextBlitY = 0xc;
  TextBlitX = 0x11;
  if (*(char *)(unaff_BP + 6) == -1) {
    ovr_blitLabel("All property.",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0x50);
  }
  else {
    puVar3 = (undefined2 *)((uint)*(byte *)(unaff_BP + 6) * 4);
    uVar6 = *puVar3;
    *(undefined2 *)(unaff_BP + -2) = puVar3[1];
    *(undefined2 *)(unaff_BP + -4) = uVar6;
    term = 0x50;
    uVar2 = 0xde;
    uVar13 = 0;
    puVar11 = (uint8_t *)Font02.ofs;
    uVar12 = Font02.seg;
    uVar4 = ovr_OVC45_77eb_226e(unaff_BP + -0x66);
    pcVar7 = (char *)manage_4d05_03a4(*(undefined2 *)(unaff_BP + -4),*(undefined2 *)(unaff_BP + -2),
                                      uVar4,uVar6);
    pcVar10 = ovr_stsprintf((char *)(unaff_BP + -0xb6),"Buildings belonging to %s%s",pcVar7);
    ovr_blitLabel(pcVar10,(uint8_t *)CONCAT22(uVar12,puVar11),CONCAT11(uVar13,uVar2),term);
  }
  TextBlitY = TextBlitY + 0xc;
  TextBlitX = 0x11;
  ovr_blitLabel("Buildings",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
  manage_4d05_0519((char *)"Total",(char *)"puppetmaker" + 3,100,0xe0);
  manage_4d05_0519((char *)"Level 1",(char *)"puppetmaker" + 3,0x8c,0xe0);
  manage_4d05_0519((char *)"Level 2",(char *)"puppetmaker" + 3,0xb4,0xe0);
  manage_4d05_0519((char *)"Level 3",(char *)"puppetmaker" + 3,0xdc,0xe0);
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
  for (iVar8 = 0; iVar8 < 0xd; iVar8 = iVar8 + 1) {
    if (iVar8 + iVar9 < 0x1e) {
      TextBlitX = 0x11;
      iVar5 = (iVar8 + iVar9) * 6;
      ovr_blitLabel((char *)CONCAT22(*(undefined2 *)((int)&GStructures[0].field2_0x2 + 2 + iVar5),
                                     (char *)*(undefined2 *)
                                              ((int)&GStructures[0].field2_0x2 + iVar5)),
                    (uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
      lVar1 = (long)(iVar8 + iVar9) * 6;
      uVar13 = (undefined1)((ulong)lVar1 >> 0x10);
      uVar2 = (undefined1)((ulong)lVar1 >> 8);
      uVar6 = manage_4d05_23fc(CONCAT11(uVar2,*(undefined1 *)(unaff_BP + 6)),
                               CONCAT11(uVar2,(&((unk01_t *)GStructures)->field0_0x0)[(int)lVar1]),
                               unaff_BP + -6);
      *(undefined2 *)((code *)init_3381_08dc + unaff_BP) = uVar6;
      if (*(int *)(unaff_BP + -0xc) == 0) {
        uVar6 = 100;
        pcVar7 = litoa10((char *)(unaff_BP + -0x66),
                         (ulong)*(uint *)((code *)init_3381_08dc + unaff_BP));
        manage_4d05_04c6(pcVar7,uVar13,uVar6);
      }
      else {
        uVar6 = 100;
        pcVar10 = ovr_stsprintf((char *)(unaff_BP + -0xb6),"%d (%d)",
                                *(char **)((code *)init_3381_08dc + unaff_BP));
        manage_4d05_04c6((char *)pcVar10,(char)((ulong)pcVar10 >> 0x10),uVar6);
      }
      lVar1 = (long)(iVar8 + iVar9) * 6;
      uVar2 = (undefined1)((ulong)lVar1 >> 0x10);
      if (*(char *)((int)&GStructures[0].field1_0x1 + (int)lVar1) != '\0') {
        if (*(int *)(unaff_BP + -0xe) == 0) {
          uVar6 = 0x8c;
          pcVar7 = litoa10((char *)(unaff_BP + -0x66),(ulong)*(uint *)(unaff_BP + -6));
          manage_4d05_04c6(pcVar7,uVar2,uVar6);
        }
        else {
          uVar6 = 0x8c;
          pcVar10 = ovr_stsprintf((char *)(unaff_BP + -0xb6),"%d (%d)",
                                  (char *)*(undefined2 *)(unaff_BP + -6));
          uVar2 = (undefined1)((ulong)pcVar10 >> 0x10);
          manage_4d05_04c6((char *)pcVar10,uVar2,uVar6);
        }
        if (*(int *)(unaff_BP + -0x10) == 0) {
          uVar6 = 0xb4;
          pcVar7 = litoa10((char *)(unaff_BP + -0x66),(ulong)*(uint *)(unaff_BP + -8));
          manage_4d05_04c6(pcVar7,uVar2,uVar6);
        }
        else {
          uVar6 = 0xb4;
          pcVar10 = ovr_stsprintf((char *)(unaff_BP + -0xb6),"%d (%d)",
                                  (char *)*(undefined2 *)(unaff_BP + -8));
          uVar2 = (undefined1)((ulong)pcVar10 >> 0x10);
          manage_4d05_04c6((char *)pcVar10,uVar2,uVar6);
        }
        if (*(int *)(unaff_BP + -0x12) == 0) {
          uVar6 = 0xdc;
          pcVar7 = litoa10((char *)(unaff_BP + -0x66),(ulong)*(uint *)(unaff_BP + -10));
          manage_4d05_04c6(pcVar7,uVar2,uVar6);
        }
        else {
          uVar6 = 0xdc;
          pcVar10 = ovr_stsprintf((char *)(unaff_BP + -0xb6),"%d (%d)",
                                  (char *)*(undefined2 *)(unaff_BP + -10));
          manage_4d05_04c6((char *)pcVar10,(char)((ulong)pcVar10 >> 0x10),uVar6);
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
  }
  CurSfxType3 = 0x3c;
  uVar2 = ovr_OVC28_6018_1398();
  *(undefined1 *)(unaff_BP + -0x15) = uVar2;
  DAT_2410_5cf0 = 0;
  if (((*(char *)(unaff_BP + -0x15) != '\0') && (*(char *)(unaff_BP + -0x15) != '\x01')) &&
     (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_4d05_277a();
    return;
  }
  if ((DAT_2410_26a8 == '\0') && (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_4d05_0081();
  }
  if (*(char *)(unaff_BP + -0x15) == -2) {
    DAT_2410_4926 = 1;
  }
  return;
}



/* 4d05:28e0 */

void __cdecl16far manage_4d05_28e0(void)

{
  long lVar1;
  code *pcVar2;
  undefined1 uVar3;
  int iVar4;
  undefined2 uVar5;
  int unaff_BP;
  int iVar6;
  int iVar7;
  undefined2 unaff_SS;
  
  pcVar2 = (code *)swi(0x52);
  (*pcVar2)();
  manage_4d05_0519();
  manage_4d05_0519();
  manage_4d05_0519();
  TextBlitY = TextBlitY + 0xc;
  if (*(char *)(unaff_BP + -0x15) == '\x04') {
    iVar7 = 0x1a;
  }
  else if (*(char *)(unaff_BP + -0x15) == '\x03') {
    iVar7 = 0xd;
  }
  else {
    iVar7 = 0;
  }
  for (iVar6 = 0; iVar6 < 0xd; iVar6 = iVar6 + 1) {
    if (iVar6 + iVar7 < 0x1e) {
      TextBlitX = 0x11;
      iVar4 = (iVar6 + iVar7) * 6;
      ovr_blitLabel((char *)CONCAT22(*(undefined2 *)((int)&GStructures[0].field2_0x2 + 2 + iVar4),
                                     (char *)*(undefined2 *)
                                              ((int)&GStructures[0].field2_0x2 + iVar4)),
                    (uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
      lVar1 = (long)(iVar6 + iVar7) * 6;
      uVar3 = (undefined1)((ulong)lVar1 >> 8);
      uVar5 = manage_4d05_23fc(CONCAT11(uVar3,*(undefined1 *)(unaff_BP + 6)),
                               CONCAT11(uVar3,(&((unk01_t *)GStructures)->field0_0x0)[(int)lVar1]),
                               unaff_BP + -6);
      *(undefined2 *)((code *)init_3381_08dc + unaff_BP) = uVar5;
      if (*(int *)(unaff_BP + -0xc) == 0) {
        litoa10((char *)(unaff_BP + -0x66),(ulong)*(uint *)((code *)init_3381_08dc + unaff_BP));
        manage_4d05_04c6();
      }
      else {
        ovr_stsprintf((char *)(unaff_BP + -0xb6),"%d (%d)",
                      *(char **)((code *)init_3381_08dc + unaff_BP));
        manage_4d05_04c6();
      }
      if (*(char *)((int)&GStructures[0].field1_0x1 + (iVar6 + iVar7) * 6) != '\0') {
        if (*(int *)(unaff_BP + -0xe) == 0) {
          litoa10((char *)(unaff_BP + -0x66),(ulong)*(uint *)(unaff_BP + -6));
          manage_4d05_04c6();
        }
        else {
          ovr_stsprintf((char *)(unaff_BP + -0xb6),"%d (%d)",(char *)*(undefined2 *)(unaff_BP + -6))
          ;
          manage_4d05_04c6();
        }
        if (*(int *)(unaff_BP + -0x10) == 0) {
          litoa10((char *)(unaff_BP + -0x66),(ulong)*(uint *)(unaff_BP + -8));
          manage_4d05_04c6();
        }
        else {
          ovr_stsprintf((char *)(unaff_BP + -0xb6),"%d (%d)",(char *)*(undefined2 *)(unaff_BP + -8))
          ;
          manage_4d05_04c6();
        }
        if (*(int *)(unaff_BP + -0x12) == 0) {
          litoa10((char *)(unaff_BP + -0x66),(ulong)*(uint *)(unaff_BP + -10));
          manage_4d05_04c6();
        }
        else {
          ovr_stsprintf((char *)(unaff_BP + -0xb6),"%d (%d)",(char *)*(undefined2 *)(unaff_BP + -10)
                       );
          manage_4d05_04c6();
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
  }
  CurSfxType3 = 0x3c;
  uVar3 = ovr_OVC28_6018_1398(unaff_BP + -0x142);
  *(undefined1 *)(unaff_BP + -0x15) = uVar3;
  DAT_2410_5cf0 = 0;
  if (((*(char *)(unaff_BP + -0x15) != '\0') && (*(char *)(unaff_BP + -0x15) != '\x01')) &&
     (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_4d05_277a();
    return;
  }
  if ((DAT_2410_26a8 == '\0') && (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_4d05_0081();
  }
  if (*(char *)(unaff_BP + -0x15) == -2) {
    DAT_2410_4926 = 1;
  }
  return;
}



/* 4d05:28f4 */

/* WARNING: This function may have set the stack pointer */

void __cdecl16far manage_4d05_28f4(void)

{
  long lVar1;
  undefined1 uVar2;
  int iVar3;
  undefined2 uVar4;
  int unaff_BP;
  int iVar5;
  int iVar6;
  undefined2 unaff_SS;
  
  manage_4d05_0519();
  manage_4d05_0519();
  TextBlitY = TextBlitY + 0xc;
  if (*(char *)(unaff_BP + -0x15) == '\x04') {
    iVar6 = 0x1a;
  }
  else if (*(char *)(unaff_BP + -0x15) == '\x03') {
    iVar6 = 0xd;
  }
  else {
    iVar6 = 0;
  }
  for (iVar5 = 0; iVar5 < 0xd; iVar5 = iVar5 + 1) {
    if (iVar5 + iVar6 < 0x1e) {
      TextBlitX = 0x11;
      iVar3 = (iVar5 + iVar6) * 6;
      ovr_blitLabel((char *)CONCAT22(*(undefined2 *)((int)&GStructures[0].field2_0x2 + 2 + iVar3),
                                     (char *)*(undefined2 *)
                                              ((int)&GStructures[0].field2_0x2 + iVar3)),
                    (uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
      lVar1 = (long)(iVar5 + iVar6) * 6;
      uVar2 = (undefined1)((ulong)lVar1 >> 8);
      uVar4 = manage_4d05_23fc(CONCAT11(uVar2,*(undefined1 *)(unaff_BP + 6)),
                               CONCAT11(uVar2,(&((unk01_t *)GStructures)->field0_0x0)[(int)lVar1]),
                               unaff_BP + -6);
      *(undefined2 *)((code *)init_3381_08dc + unaff_BP) = uVar4;
      if (*(int *)(unaff_BP + -0xc) == 0) {
        litoa10((char *)(unaff_BP + -0x66),(ulong)*(uint *)((code *)init_3381_08dc + unaff_BP));
        manage_4d05_04c6();
      }
      else {
        ovr_stsprintf((char *)(unaff_BP + -0xb6),"%d (%d)",
                      *(char **)((code *)init_3381_08dc + unaff_BP));
        manage_4d05_04c6();
      }
      if (*(char *)((int)&GStructures[0].field1_0x1 + (iVar5 + iVar6) * 6) != '\0') {
        if (*(int *)(unaff_BP + -0xe) == 0) {
          litoa10((char *)(unaff_BP + -0x66),(ulong)*(uint *)(unaff_BP + -6));
          manage_4d05_04c6();
        }
        else {
          ovr_stsprintf((char *)(unaff_BP + -0xb6),"%d (%d)",(char *)*(undefined2 *)(unaff_BP + -6))
          ;
          manage_4d05_04c6();
        }
        if (*(int *)(unaff_BP + -0x10) == 0) {
          litoa10((char *)(unaff_BP + -0x66),(ulong)*(uint *)(unaff_BP + -8));
          manage_4d05_04c6();
        }
        else {
          ovr_stsprintf((char *)(unaff_BP + -0xb6),"%d (%d)",(char *)*(undefined2 *)(unaff_BP + -8))
          ;
          manage_4d05_04c6();
        }
        if (*(int *)(unaff_BP + -0x12) == 0) {
          litoa10((char *)(unaff_BP + -0x66),(ulong)*(uint *)(unaff_BP + -10));
          manage_4d05_04c6();
        }
        else {
          ovr_stsprintf((char *)(unaff_BP + -0xb6),"%d (%d)",(char *)*(undefined2 *)(unaff_BP + -10)
                       );
          manage_4d05_04c6();
        }
      }
      TextBlitY = TextBlitY + 0xc;
    }
  }
  CurSfxType3 = 0x3c;
  uVar2 = ovr_OVC28_6018_1398(unaff_BP + -0x142);
  *(undefined1 *)(unaff_BP + -0x15) = uVar2;
  DAT_2410_5cf0 = 0;
  if (((*(char *)(unaff_BP + -0x15) != '\0') && (*(char *)(unaff_BP + -0x15) != '\x01')) &&
     (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_4d05_277a();
    return;
  }
  if ((DAT_2410_26a8 == '\0') && (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_4d05_0081();
  }
  if (*(char *)(unaff_BP + -0x15) == -2) {
    DAT_2410_4926 = 1;
  }
  return;
}



/* 4d05:2b09 */

void __cdecl16far manage_4d05_2b09(void)

{
  undefined1 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  
  if (*(char *)(unaff_BP + -0x15) == '\x05') {
    manage_4d05_2bc4(*(uint8_t *)(unaff_BP + 6),0xfe);
  }
  else {
    manage_4d05_2bc4(*(uint8_t *)(unaff_BP + 6),
                     (uint)*(byte *)((int)&far_t_ARRAY_2410_49f7[2].seg + 1 +
                                    (uint)*(byte *)(unaff_BP + -0x15) * 6));
  }
  DAT_2410_5cf0 = 1;
  CurSfxType3 = 0x3c;
  uVar1 = ovr_OVC28_6018_1398(unaff_BP + -0x142);
  *(undefined1 *)(unaff_BP + -0x15) = uVar1;
  DAT_2410_5cf0 = 0;
  if (((*(char *)(unaff_BP + -0x15) != '\0') && (*(char *)(unaff_BP + -0x15) != '\x01')) &&
     (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_4d05_277a();
    return;
  }
  if ((DAT_2410_26a8 == '\0') && (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_4d05_0081();
  }
  if (*(char *)(unaff_BP + -0x15) == -2) {
    DAT_2410_4926 = 1;
  }
  return;
}



/* 4d05:2b3e */

void __cdecl16far manage_4d05_2b3e(void)

{
  undefined1 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  int in_stack_00000000;
  
  manage_4d05_2bc4(*(uint8_t *)(unaff_BP + 6),in_stack_00000000);
  DAT_2410_5cf0 = 1;
  CurSfxType3 = 0x3c;
  uVar1 = ovr_OVC28_6018_1398(unaff_BP + -0x142);
  *(undefined1 *)(unaff_BP + -0x15) = uVar1;
  DAT_2410_5cf0 = 0;
  if (((*(char *)(unaff_BP + -0x15) != '\0') && (*(char *)(unaff_BP + -0x15) != '\x01')) &&
     (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_4d05_277a();
    return;
  }
  if ((DAT_2410_26a8 == '\0') && (*(char *)(unaff_BP + -0x15) != -2)) {
    manage_4d05_0081();
  }
  if (*(char *)(unaff_BP + -0x15) == -2) {
    DAT_2410_4926 = 1;
  }
  return;
}



/* 4d05:2bc4 */

void __cdecl16far manage_4d05_2bc4(uint8_t param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  char local_106 [256];
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  Highlight1 = (undefined1)param_2;
  Highlight1 = param_1;
  if (DAT_2410_26a8 != '\0') {
    ovr_stats_6386_232d();
  }
  uStack_4 = GfxRndSeed;
  uStack_6 = GfxRndSeed2;
  GfxRndSeed = Seed_2000_d1da;
  GfxRndSeed2 = Seed_2000_d1d8;
  ovr_OVC13_3d16_1558();
  GfxRndSeed = uStack_4;
  GfxRndSeed2 = uStack_6;
  Highlight1 = 0xff;
  Highlight1 = 0xff;
  if (param_2 == 0xfe) {
    if (param_1 == 0xff) {
      ovr_say("The damaged structures belonging to all leaders are highlighted in red.");
    }
    else {
      ovr_OVC22_5087_0119();
      pcVar2 = ovr_stsprintf(local_106,
                             "The damaged structures belonging to %s the %s are highlighted in red."
                             ,(char *)*(undefined2 *)((uint)param_1 * 4));
      ovr_say(pcVar2);
    }
  }
  else {
    iVar1 = 0;
    while ((iVar1 < 0x1e && ((uint)((unk01_t *)GStructures + iVar1)->field0_0x0 != param_2))) {
      iVar1 = iVar1 + 1;
    }
    if (iVar1 != 0x1e) {
      if (param_1 == 0xff) {
        pcVar2 = ovr_stsprintf(local_106,"The %s belonging to all leaders are highlighted in red.",
                               (char *)*(undefined2 *)((int)&GStructures[0].field2_0x2 + iVar1 * 6))
        ;
        ovr_say(pcVar2);
      }
      else {
        ovr_OVC22_5087_0119();
        pcVar2 = ovr_stsprintf(local_106,"The %s belonging to %s the %s are highlighted in red.",
                               (char *)*(undefined2 *)((int)&GStructures[0].field2_0x2 + iVar1 * 6))
        ;
        ovr_say(pcVar2);
      }
    }
  }
  return;
}



/* 4d05:2d79 */

/* WARNING: Instruction at (ram,0x0005ff51) overlaps instruction at (ram,0x0005ff50)
    */

char * __cdecl16far manage_4d05_2d79(byte param_1,undefined2 param_2,undefined4 param_3)

{
  char **ppcVar1;
  far_t ptr;
  char cVar2;
  uint16_t uVar3;
  int iVar4;
  char *in_DX;
  char **ppcVar5;
  char **ppcVar6;
  uint uVar7;
  char *pcVar8;
  undefined2 unaff_DI;
  char *pcVar9;
  undefined2 uVar10;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  bool bVar11;
  char *pcVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  uint8_t term;
  undefined1 uVar16;
  char acStack_13e [36];
  uint auStack_11a [42];
  uint8_t local_c6 [48];
  uint local_96 [24];
  char *apcStack_66 [4];
  char *pcStack_5e;
  char *pcStack_5c;
  char **ppcStack_1e;
  char cStack_1a;
  char cStack_19;
  char cStack_18;
  char cStack_17;
  char *pcStack_16;
  char *pcStack_14;
  int iStack_12;
  undefined2 uStack_10;
  char acStack_e [6];
  char *pcStack_8;
  undefined1 auStack_6 [2];
  undefined2 uStack_4;
  
  F_SCOPY((uint8_t *)local_96,(uint8_t *)(far_t *)far_t_ARRAY_2410_4b06,0x30);
  F_SCOPY(local_c6,(uint8_t *)(far_t *)(far_t_ARRAY_2410_4b06 + 0xc),0x30);
  ppcVar6 = (char **)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 3);
  F_SCOPY((uint8_t *)(acStack_e + 4),(uint8_t *)0x4b66,7);
  acStack_e[2] = '\0';
  if (param_1 == 0xff) {
    acStack_e[3] = 0xc;
  }
  else {
    in_DX = (char *)"halfling castle" + 0xc;
    unaff_ES = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
    if (*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x2f) == -1) {
      acStack_e[3] = 0xc;
    }
    else {
      acStack_e[3] = acStack_e[*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x2f) + 4];
      in_DX = (char *)"halfling castle" + 0xc;
      unaff_ES = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
      if (3 < *(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x2f)) {
        acStack_e[2] = '\x01';
      }
    }
  }
  apcStack_66[1] = (char *)"puppetmaker" + 3;
  apcStack_66[0] = (char *)"Done";
  apcStack_66[3] = (char *)"puppetmaker" + 3;
  apcStack_66[2] = (char *)"Summary";
  ppcVar5 = apcStack_66 + 4;
  pcStack_5c = (char *)"puppetmaker" + 3;
  pcStack_5e = (char *)"All levels";
  pcVar9 = (char *)((int)(undefined4 *)&_DATA + 3);
  for (pcVar8 = (char *)0x0; (int)pcVar8 < (int)(uint)(byte)acStack_e[3]; pcVar8 = pcVar8 + 1) {
    if (((int)pcVar8 < 5) || (acStack_e[2] == '\0')) {
      in_DX = (char *)local_96[(int)pcVar8 * 2];
      ppcVar5 = apcStack_66 + (int)pcVar9 * 2;
      apcStack_66[(int)pcVar9 * 2 + 1] = (char *)local_96[(int)pcVar8 * 2 + 1];
      *ppcVar5 = in_DX;
    }
    else {
      unaff_ES = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
      uVar7 = (uint)*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x2f);
      in_DX = (char *)auStack_11a[(int)pcVar8 * 2 + uVar7 * 8];
      ppcVar5 = apcStack_66 + (int)pcVar9 * 2;
      apcStack_66[(int)pcVar9 * 2 + 1] = (char *)auStack_11a[(int)pcVar8 * 2 + uVar7 * 8 + 1];
      *ppcVar5 = in_DX;
    }
    ppcVar6 = apcStack_66;
    pcVar9 = pcVar9 + 1;
  }
  acStack_e[1] = '\x02';
  manage_4d05_0081();
  acStack_e[0] = '\0';
  if (acStack_e[1] == '\x02') {
    if (DAT_2410_26a8 == '\0') {
      manage_4d05_0081();
    }
    TextBlitY = 0xc;
    TextBlitX = 0x11;
    uVar15 = (undefined1)Font02.seg;
    uVar16 = (undefined1)(Font02.seg >> 8);
    if (param_1 == 0xff) {
      iVar4 = ovr_blitLabel("Total population.",
                            (uint8_t *)CONCAT13(uVar16,CONCAT12(uVar15,Font02.ofs)),222,0x50);
      *pcVar8 = *pcVar8 + (char)((uint)iVar4 >> 8) + ((undefined1 *)0xfff3 < &stack0xfe3a);
      *(undefined1 *)((*(far_t *)&Entities).ofs + iVar4 + 0x18) = 0;
      *(undefined1 *)(Entities.ofs + (int)pcVar8 * 0x37 + 0x31) =
           *(undefined1 *)(Entities.ofs + (int)pcVar8 * 0x37 + 0x32);
      if (EntityCount <= pcVar8 + 1) {
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
        if (DebugVerbose != false) {
          printf("%d \r",0x3d);
        }
        pcVar8 = (char *)ovr_OVC23_55fe_2b82();
        return pcVar8;
      }
      pcVar8 = (char *)"thief" + 5;
      ovr_say((char *)CONCAT22(unaff_DI,(char *)
                                        "The damaged structures belonging to all leaders are highlighted in red."
                              ));
      return pcVar8;
    }
    uStack_10 = ((int *)((uint)param_1 * 4))[1];
    iStack_12 = *(int *)((uint)param_1 * 4);
    term = 0x50;
    uVar13 = 0xde;
    uVar14 = 0;
    uVar3 = Font02.ofs;
    ovr_OVC45_77eb_226e();
    func_0x0005d3f4();
    pcVar12 = ovr_stsprintf(acStack_13e,"%s population, loyal to %s%s",
                            (char *)*(undefined2 *)((uint)*(byte *)(iStack_12 + 0x2f) * 4 + 0xeb));
    ovr_blitLabel(pcVar12,(uint8_t *)CONCAT13(uVar16,CONCAT12(uVar15,uVar3)),CONCAT11(uVar14,uVar13)
                  ,term);
    TextBlitY = TextBlitY + 0xc;
    iVar4 = ovr_font_302d_06ea();
    TextBlitX = 0x89 - iVar4;
    ovr_blitLabel("UNITS",(uint8_t *)
                          CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs)),
                  222,0xe0);
    iVar4 = ovr_font_302d_06ea();
    uVar3 = 0xd4 - iVar4;
    TextBlitX = uVar3;
    ovr_blitLabel("POPULATION",
                  (uint8_t *)CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs))
                  ,222,0xe0);
    pcVar8 = (char *)0x0;
    while( true ) {
      TextBlitY = TextBlitY + 0xc;
      cVar2 = (char)ppcVar6;
      if ((int)(uint)(byte)acStack_e[3] <= (int)pcVar8) break;
      TextBlitX = 0x11;
      uVar15 = (undefined1)(Font02.seg >> 8);
      if (((int)pcVar8 < 5) || (acStack_e[2] == '\0')) {
        ovr_blitLabel((char *)CONCAT22(local_96[(int)pcVar8 * 2 + 1],
                                       (char *)local_96[(int)pcVar8 * 2]),
                      (uint8_t *)CONCAT13(uVar15,CONCAT12((char)Font02.seg,Font02.ofs)),319,0xe0);
      }
      else {
        uVar7 = (uint)*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x2f);
        ovr_blitLabel((char *)CONCAT22(auStack_11a[(int)pcVar8 * 2 + uVar7 * 8 + 1],
                                       (char *)auStack_11a[(int)pcVar8 * 2 + uVar7 * 8]),
                      (uint8_t *)CONCAT13(uVar15,CONCAT12((char)Font02.seg,Font02.ofs)),319,0xe0);
      }
      OVC27_5ded_1433();
      ovr_stsprintf(acStack_13e,"%d",pcStack_14);
      iVar4 = ovr_font_302d_06ea();
      TextBlitX = 0x89 - iVar4;
      ovr_blitLabel((char *)CONCAT22(unaff_SS,acStack_13e),
                    (uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0x50);
      ovr_stsprintf(acStack_13e,"%d",pcStack_16);
      iVar4 = ovr_font_302d_06ea();
      uVar3 = 0xd4 - iVar4;
      TextBlitX = uVar3;
      ovr_blitLabel((char *)CONCAT22(unaff_SS,acStack_13e),
                    (uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0x50);
      pcVar8 = pcVar8 + 1;
    }
    CurSfxType3 = 0x3c;
    acStack_e[1] = ovr_OVC28_6018_1398();
    DAT_2410_5cf0 = 0;
    if (((acStack_e[1] != '\0') && (acStack_e[1] != '\x01')) && (acStack_e[1] != -2)) {
      (&stack0xbac4)[(int)pcVar9] = (&stack0xbac4)[(int)pcVar9] + cVar2;
      pcVar9 = (char *)"puppetmaker" + 3;
      do {
        iVar4 = (int)pcVar9 * uVar3;
        pcVar9 = pcVar8;
        if (*(byte *)((int)pcVar8 * 0x34 + 0x22) < *(byte *)(iVar4 + 0x21)) {
          *(undefined1 *)((int)pcVar8 * 0x34 + 0x21) = *(undefined1 *)((int)pcVar8 * 0x34 + 0x22);
        }
        do {
          pcVar9 = pcVar9 + 1;
          if ((int)(uint)AgntCount <= (int)pcVar9) {
            uVar3 = ovr_audio_3a5b_0afd();
            ovr_play_sfxU(0x1c,0,uVar3);
            return (char *)0x1;
          }
        } while (*(int *)((int)pcVar9 * 0x34 + 0x1b) != *(int *)((int)param_3 + 0x1b));
        uVar10 = (undefined2)((ulong)_auStack_6 >> 0x10);
        if ((byte)((char *)_auStack_6)[0x32] < *(byte *)((int)pcVar9 * 0x34 + 0x22)) {
          *(char *)((int)pcVar9 * 0x34 + 0x22) = ((char *)_auStack_6)[0x32];
        }
        uVar3 = 0x34;
        pcVar8 = pcVar9;
      } while( true );
    }
    if (acStack_e[1] == -2) {
      DAT_2410_4926 = 1;
    }
    return (char *)"puppetmaker" + 3;
  }
  do {
    uVar10 = (undefined2)((ulong)ppcStack_1e >> 0x10);
    ppcVar6 = (char **)ppcStack_1e;
    *(byte *)(ppcVar6 + 6) =
         (byte)((int)(uint)*(byte *)((int)ppcVar6 +
                                    ((int)(uint)*(byte *)((int)ppcVar5 + 0x2f) >> 2) + 0x1b) >>
               ((*(byte *)((int)ppcVar6 + 0x2f) & 3) << 1)) & 3;
    cVar2 = func_0x0004f32d();
    ppcVar6 = (char **)ppcStack_1e;
    uVar10 = (undefined2)((ulong)ppcStack_1e >> 0x10);
    if (cVar2 == '\0') {
      *ppcStack_1e = *ppcStack_1e + *(char *)(*(byte *)(ppcVar6 + 6) + 0x885);
      ppcVar6[1] = ppcVar6[1] + *(char *)(*(byte *)(ppcVar6 + 6) + 0x889);
      *(char *)((int)ppcVar6 + 0x2f) = *(char *)((int)ppcVar6 + 0x2f) + '\x01';
    }
    else {
      *(undefined1 *)((int)ppcVar6 + 0x2f) = 0;
      *(undefined1 *)(ppcVar6 + 0x18) = 0;
    }
LAB_3f0b_1477:
    cStack_17 = '\x01';
    uVar10 = ovr_OVC23_55fe_3450();
    uVar15 = (undefined1)uVar10;
    uVar16 = (undefined1)((uint)uVar10 >> 8);
    iVar4 = ovr_OVC23_55fe_3450();
    if (CONCAT11(uVar16,uVar15) == iVar4) {
      uVar10 = (undefined2)((ulong)ppcStack_1e >> 0x10);
      ppcVar6 = (char **)ppcStack_1e;
      if (ppcVar6[5] == ppcVar6[1]) {
        ppcVar6[4] = (char *)0x0;
        ppcVar6[5] = (char *)0x0;
        if (*(char *)(ppcVar6 + 0xd) == -1) {
          _auStack_6 = CONCAT12(0xff,auStack_6);
        }
        else {
          _auStack_6 = CONCAT12(*(undefined1 *)
                                 ((int)*(undefined4 *)((uint)*(byte *)(ppcVar6 + 0xd) << 2) + 0x89),
                                auStack_6);
        }
        pcVar12 = _auStack_6;
        (*(uint8_t *)((uint8_t *)&(uStack_4))) = (byte)((uint3)_auStack_6 >> 0x10);
        bVar11 = (byte)uStack_4 != -1;
        _auStack_6 = pcVar12;
        if (bVar11) {
          for (uVar7 = 0; uVar7 < DAT_2410_0881; uVar7 = uVar7 + 1) {
            uVar10 = ovr_OVC23_55fe_3450();
            uVar15 = (undefined1)uVar10;
            uVar16 = (undefined1)((uint)uVar10 >> 8);
            iVar4 = ovr_OVC23_55fe_3450();
            if ((CONCAT11(uVar16,uVar15) == iVar4) &&
               ((char *)*(uint *)(uVar7 * 0x13 + 2) == ((char **)ppcStack_1e)[1])) {
              manage_4d05_28e0();
              if ((char *)*(uint *)(uVar7 * 0x13 + 2) == GfxRndSeed2) {
                uVar10 = ovr_OVC23_55fe_3450();
                uVar15 = (undefined1)uVar10;
                uVar16 = (undefined1)((uint)uVar10 >> 8);
                iVar4 = ovr_OVC23_55fe_3450();
                if (CONCAT11(uVar16,uVar15) == iVar4) {
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
      uVar10 = (undefined2)((ulong)ppcStack_1e >> 0x10);
      if (((*ppcStack_1e < (char *)(GfxRndSeed - 2U)) || ((char *)(GfxRndSeed + 1U) < *ppcStack_1e))
         || (((char **)ppcStack_1e)[1] != GfxRndSeed2)) {
        cStack_19 = '\0';
      }
      else {
        cStack_19 = '\x01';
      }
      if ((((uint)auStack_6 < (char *)(GfxRndSeed - 2U)) ||
          ((char *)(GfxRndSeed + 1U) < (uint)auStack_6)) || (GfxRndSeed2 != pcStack_8)) {
        cStack_18 = '\0';
      }
      else {
        cStack_18 = '\x01';
      }
      if (cStack_18 != '\0' || cStack_19 != '\0') {
        if (cStack_18 == '\0') {
          ovr_OVC15_4207_0b88();
          uVar10 = (undefined2)((ulong)ppcStack_1e >> 0x10);
          ppcVar6 = (char **)ppcStack_1e;
          cStack_1a = (char)((ulong)(*(byte *)(ppcVar6 + 7) + 0xf) / 0x10);
          if (((uint)ppcVar6[6] & 1) == 0) {
            pcStack_16 = (char *)0x0;
          }
          else {
            pcStack_16 = (char *)(*(byte *)(ppcVar6 + 6) - 2);
          }
          while (cStack_1a != '\0') {
            cStack_1a = cStack_1a + -1;
            ovr_OVC15_4207_2301();
          }
          cStack_1a = -1;
        }
        else if (cStack_19 == '\0') {
          cStack_1a = (char)((ulong)(*(byte *)((char **)ppcStack_1e + 7) + 0xf) / 0x10);
          while (cStack_1a != '\0') {
            (*(uint8_t *)((uint8_t *)&(ptr.seg))) = (char)Entities.seg;
            ptr.ofs = Entities.ofs + (int)pcVar9 * 0x37;
            (*(uint8_t *)((uint8_t *)&(ptr.seg) + 1)) = (*(uint8_t *)((uint8_t *)&(Entities.seg) + 1));
            cStack_1a = cStack_1a + -1;
            ovr_agnt_3b1d_196b(ptr);
          }
          cStack_1a = -1;
        }
        else if ((cStack_18 != '\0') && (cStack_19 != '\0')) {
          for (cStack_1a = manage_4d05_28f4(); cStack_1a != '\0'; cStack_1a = cStack_1a + -1) {
            uVar10 = (undefined2)((ulong)ppcStack_1e >> 0x10);
            if (((uint)((char **)ppcStack_1e)[6] & 1) == 0) {
              pcStack_16 = (char *)0x0;
            }
            else {
              pcStack_16 = (char *)(*(byte *)((char **)ppcStack_1e + 6) - 2);
            }
            cVar2 = ovr_OVC15_4207_2301();
            if (cVar2 == '\0') break;
          }
        }
      }
    }
    do {
      pcVar9 = pcVar9 + 1;
      if (EntityCount <= pcVar9) {
        GGameState = 0x3c;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r",0x3c);
        }
        func_0x0004fcda();
        GGameState = 0x3d;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r",0x3d);
        }
        ovr_OVC23_55fe_2b82();
        GGameState = 0xc;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r",0xc);
        }
        ovr_OVC24_5943_0d5a();
        GGameState = 0x1f;
        if (cStack_17 != '\0') {
          ovr_constr_36ce_03a6();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (iVar4 = 0; iVar4 < 5; iVar4 = iVar4 + 1) {
          if (acStack_e[iVar4] != '\0') {
            ovr_OVC41_6a8f_1be0();
          }
        }
        GGameState = 0xd;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r",0xd);
        }
        ovr_OVC24_5943_112e();
        GGameState = 0xe;
        DAT_2410_648e = 1;
        return (char *)"puppetmaker" + 3;
      }
      ppcStack_1e = (char **)CONCAT22(Entities.seg,(char **)(Entities.ofs + (int)pcVar9 * 0x37));
      uVar10 = ovr_OVC23_55fe_3450();
      uVar15 = (undefined1)uVar10;
      uVar16 = (undefined1)((uint)uVar10 >> 8);
      iVar4 = ovr_OVC23_55fe_3450();
      if ((CONCAT11(uVar16,uVar15) == iVar4) &&
         (uVar10 = (undefined2)((ulong)ppcStack_1e >> 0x10),
         ((char **)ppcStack_1e)[5] == ((char **)ppcStack_1e)[1])) {
        manage_4d05_2b3e();
      }
      unaff_ES = (undefined2)((ulong)ppcStack_1e >> 0x10);
      ppcVar5 = (char **)ppcStack_1e;
    } while ((ppcVar5[4] == (char *)0x0 && ppcVar5[5] == (char *)0x0) ||
            (*(char *)(ppcVar5 + 0xc) != '\0'));
    if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].ofs + 1 +
                  (uint)*(byte *)((int)ppcVar5 + 0xd) * 0x95) & 0x4000) == 0) {
      uStack_4 = (uint)((ulong)_auStack_6 >> 0x10) & 0xff;
    }
    else {
      _auStack_6 = (char *)CONCAT13(1,_auStack_6);
    }
    _auStack_6 = (char *)CONCAT22(uStack_4,*ppcStack_1e);
    pcStack_8 = ppcVar5[1];
    _iStack_12 = CONCAT13(*(undefined1 *)
                           ((int)(char **)GMenuStrings +
                           (uint)*(byte *)((int)ppcVar5 + 0xd) * 0x95 + 0x1f),_iStack_12);
  } while (*(byte *)((int)ppcVar5 + 0x2f) < *(byte *)(ppcVar5 + 0x18));
  uVar10 = ovr_OVC07_32c9_0026();
  _iStack_12 = CONCAT22(uStack_10,uVar10);
  pcStack_14 = (char *)ovr_OVC07_32c9_0026();
  if (((iStack_12 == 0) || (uVar3 = ovr_randBelow(2), (char)uVar3 == '\0')) ||
     (cVar2 = func_0x0004f412(), cVar2 != '\0')) {
    if ((pcStack_14 == (char *)0x0) || (cVar2 = func_0x0004f412(), cVar2 != '\0')) {
      if ((iStack_12 == 0) || (cVar2 = func_0x0004f412(), cVar2 != '\0')) {
        cVar2 = ovr_OVC26_5d45_031f();
        if (cVar2 == '\0') {
          cVar2 = ovr_OVC26_5d45_06f0();
          if ((cVar2 == '\0') &&
             (*(char *)((int)(char **)GMenuStrings +
                       (uint)*(byte *)((int)(char **)ppcStack_1e + 0xd) * 0x95 + 0x1f) == '\0')) {
            manage_4d05_2b3e();
          }
        }
        else {
          uVar10 = (undefined2)((ulong)ppcStack_1e >> 0x10);
          ppcVar6 = (char **)ppcStack_1e;
          *(byte *)(ppcVar6 + 6) =
               (byte)((int)(uint)*(byte *)((int)ppcVar6 +
                                          ((int)(uint)*(byte *)((int)ppcVar6 + 0x2f) >> 2) + 0x1b)
                     >> ((*(byte *)((int)ppcVar6 + 0x2f) & 3) << 1)) & 3;
          cVar2 = func_0x0004f32d();
          if (cVar2 == '\0') {
            uVar10 = (undefined2)((ulong)ppcStack_1e >> 0x10);
            ppcVar6 = (char **)ppcStack_1e;
            *ppcStack_1e = *ppcStack_1e + *(char *)(*(byte *)(ppcVar6 + 6) + 0x885);
            ppcVar6[1] = ppcVar6[1] + *(char *)(*(byte *)(ppcVar6 + 6) + 0x889);
            *(char *)((int)ppcVar6 + 0x2f) = *(char *)((int)ppcVar6 + 0x2f) + '\x01';
          }
        }
      }
      else {
        *ppcStack_1e = *ppcStack_1e + iStack_12;
        *(char *)((char **)ppcStack_1e + 6) = '\x02' - (char)iStack_12;
      }
    }
    else {
      uVar10 = (undefined2)((ulong)ppcStack_1e >> 0x10);
      ppcVar1 = (char **)ppcStack_1e + 1;
      *ppcVar1 = pcStack_14 + (int)*ppcVar1;
      *(char *)((char **)ppcStack_1e + 6) = (char)pcStack_14 + '\x01';
    }
  }
  else {
    *ppcStack_1e = *ppcStack_1e + iStack_12;
    *(char *)((char **)ppcStack_1e + 6) = '\x02' - (char)iStack_12;
  }
  goto LAB_3f0b_1477;
}



/* 4d05:330c */

void __cdecl16far manage_4d05_330c(byte param_1,int param_2,char *param_3)

{
  char *pcVar1;
  char local_106 [256];
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  DAT_2410_4b6d = (undefined1)param_2;
  DAT_2410_4b6e = param_1;
  if (DAT_2410_26a8 != '\0') {
    ovr_stats_6386_232d();
  }
  uStack_4 = GfxRndSeed;
  uStack_6 = GfxRndSeed2;
  GfxRndSeed = Seed_2000_d1da;
  GfxRndSeed2 = Seed_2000_d1d8;
  ovr_OVC13_3d16_1558();
  GfxRndSeed = uStack_4;
  GfxRndSeed2 = uStack_6;
  DAT_2410_4b6d = 0xff;
  DAT_2410_4b6e = 0xff;
  if (param_2 == 0xfe) {
    if (param_1 == 0xff) {
      ovr_say("All units are displayed.");
    }
    else {
      ovr_OVC22_5087_0119();
      pcVar1 = ovr_stsprintf(local_106,"All units loyal to %s the %s are displayed.",
                             (char *)*(undefined2 *)((uint)param_1 * 4));
      ovr_say(pcVar1);
    }
  }
  else if (param_1 == 0xff) {
    pcVar1 = ovr_stsprintf(local_106,"Only units of %s are displayed.",param_3);
    ovr_say(pcVar1);
  }
  else {
    ovr_OVC22_5087_0119();
    pcVar1 = ovr_stsprintf(local_106,"Only units of %s loyal to %s the %s are displayed.",param_3);
    ovr_say(pcVar1);
  }
  return;
}



/* 4d05:35c9 */

/* WARNING: Unable to track spacebase fully for stack */

int __cdecl16far switchD_5000_123d_caseD_0(void)

{
  uint *puVar1;
  byte *pbVar2;
  undefined1 uVar3;
  byte bVar4;
  char *pcVar5;
  undefined2 uVar6;
  byte bVar7;
  undefined2 in_AX;
  int iVar8;
  byte bVar10;
  byte bVar11;
  int iVar9;
  uint in_CX;
  byte bVar12;
  uint in_DX;
  uint uVar13;
  int iVar14;
  byte bVar16;
  uint uVar15;
  byte bVar17;
  uint in_BX;
  int iVar18;
  byte bVar20;
  uint *puVar19;
  uint *puVar22;
  uint unaff_BP;
  undefined1 *puVar23;
  uint uVar24;
  uint *puVar25;
  uint *puVar26;
  uint *unaff_SI;
  uint *unaff_DI;
  uint uVar27;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 uVar28;
  bool bVar29;
  bool bVar30;
  bool bVar31;
  bool bVar32;
  byte in_AF;
  bool bVar33;
  bool bVar34;
  bool bVar35;
  undefined2 uStack_9;
  uint uStack_7;
  byte bVar21;
  
  AgntAnms[0x68].ey = AgntAnms[0x68].ey | in_DX;
  puVar1 = unaff_DI;
  iVar9 = (in_DX & 3) - (*puVar1 & 3);
  *puVar1 = *puVar1 + (uint)(0 < iVar9) * iVar9;
  *(char *)unaff_SI = (char)*unaff_SI + '\x01';
  uVar13 = CONCAT11(0x14,(char)in_DX);
  uVar27 = CONCAT11((char)((uint)in_AX >> 8),0xf1);
  puVar1 = (uint *)((int)unaff_DI + in_BX + 0x861b);
  iVar9 = -*puVar1;
  uVar15 = (uint)(&stack0xfffb < (undefined1 *)*puVar1);
  uVar24 = unaff_BP - *unaff_SI;
  puVar23 = (undefined1 *)(uVar24 - uVar15);
  uVar15 = (uint)(unaff_BP < *unaff_SI || uVar24 < uVar15);
  uVar24 = in_BX - *(uint *)(in_BX + (int)unaff_DI);
  iVar18 = uVar24 - uVar15;
  uVar15 = (uint)(in_BX < *(uint *)(in_BX + (int)unaff_DI) || uVar24 < uVar15);
  uVar24 = uVar13 - *(uint *)(iVar18 + (int)unaff_DI);
  iVar14 = uVar24 - uVar15;
  uVar15 = (uint)(uVar13 < *(uint *)(iVar18 + (int)unaff_DI) || uVar24 < uVar15);
  uVar24 = uVar27 - *unaff_DI;
  iVar8 = uVar24 - uVar15;
  uVar15 = (uint)(uVar27 < *unaff_DI || uVar24 < uVar15);
  uVar24 = (int)puVar23 - (int)(&stack0xfffb + iVar9);
  bVar29 = puVar23 < &stack0xfffb + iVar9 || uVar24 < uVar15;
  uVar24 = uVar24 - uVar15;
  bVar12 = (byte)((uint)iVar8 >> 8);
  bVar7 = (byte)((uint)iVar18 >> 8);
  bVar10 = bVar12 - bVar7;
  bVar30 = bVar12 < bVar7 || bVar10 < bVar29;
  bVar17 = (byte)iVar8;
  bVar10 = bVar10 - bVar29;
  bVar20 = (byte)iVar14;
  bVar12 = bVar20 - bVar10;
  bVar29 = bVar20 < bVar10 || bVar12 < bVar30;
  bVar16 = (byte)((uint)iVar14 >> 8);
  bVar12 = bVar12 - bVar30;
  bVar20 = bVar7 - *(byte *)(iVar18 + -0x4ae6);
  bVar30 = bVar7 < *(byte *)(iVar18 + -0x4ae6) || bVar20 < bVar29;
  bVar20 = bVar20 - bVar29;
  bVar7 = bVar17 - (byte)unaff_DI[0x250d];
  bVar29 = bVar17 < (byte)unaff_DI[0x250d] || bVar7 < bVar30;
  bVar7 = bVar7 - bVar30;
  bVar17 = (byte)iVar18 - AgntAnms[0xf].frmid;
  bVar30 = (byte)iVar18 < AgntAnms[0xf].frmid || bVar17 < bVar29;
  bVar17 = bVar17 - bVar29;
  bVar11 = bVar20 - bVar7;
  bVar21 = bVar11 - bVar30;
  puVar19 = (uint *)CONCAT11(bVar21,bVar17);
  uVar15 = (uint)(bVar20 < bVar7 || bVar11 < bVar30);
  uVar27 = uVar24 - in_CX;
  puVar25 = (uint *)(uVar27 - uVar15);
  puVar1 = (uint *)((int)unaff_DI + -0x57e7);
  uVar27 = (uint)(uVar24 < in_CX || uVar27 < uVar15);
  uVar15 = *puVar1;
  uVar24 = *puVar1;
  *puVar1 = (uVar24 - (int)puVar25) - uVar27;
  puVar1 = (uint *)((int)puVar25 + 0x7419);
  uVar27 = (uint)(uVar15 < puVar25 || uVar24 - (int)puVar25 < uVar27);
  uVar15 = *puVar1;
  uVar24 = *puVar1;
  *puVar1 = (uVar24 - in_CX) - uVar27;
  puVar1 = (uint *)((int)unaff_SI + 0x19);
  uVar24 = (uint)(uVar15 < in_CX || uVar24 - in_CX < uVar27);
  puVar26 = (uint *)*puVar1;
  uVar15 = *puVar1;
  *puVar1 = (uVar15 - (int)puVar19) - uVar24;
  *(undefined2 *)((int)&uStack_7 + iVar9) = unaff_DI;
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
  uVar15 = (uint)(puVar26 < puVar19 || uVar15 - (int)puVar19 < uVar24);
  (*(uint16_t *)((uint8_t *)&(s_Peaceful_2410_2915) + 4)) = (0x6665U - (int)unaff_DI) - uVar15;
  uVar15 = (uint)((uint)0x6665 < unaff_DI || (uint)(0x6665U - (int)unaff_DI) < uVar15);
  bVar29 = (uint)AgntAnms[6].y < CONCAT11(bVar16,bVar12);
  uVar24 = AgntAnms[6].y - CONCAT11(bVar16,bVar12);
  AgntAnms[6].y = uVar24 - uVar15;
  uVar15 = (uint)(bVar29 || uVar24 < uVar15);
  uVar24 = (int)&uStack_7 + (iVar9 - (int)unaff_DI);
  bVar29 = (uint *)((int)&uStack_7 + iVar9) < unaff_DI || uVar24 < uVar15;
  iVar9 = -uVar15;
  puVar22 = (uint *)(uVar24 + iVar9);
  bVar20 = (byte)(in_CX >> 8);
  bVar30 = bVar12 < bVar20 || (byte)(bVar12 - bVar20) < bVar29;
  bVar12 = (bVar12 - bVar20) - bVar29;
  bVar29 = bVar10 < bVar17 || (byte)(bVar10 - bVar17) < bVar30;
  bVar11 = (bVar10 - bVar17) - bVar30;
  bVar10 = bVar12 - bVar7;
  bVar30 = bVar12 < bVar7 || bVar10 < bVar29;
  bVar10 = bVar10 - bVar29;
  pbVar2 = (byte *)((char *)((int)puVar19 + (int)unaff_SI) + -0x60e8);
  bVar29 = *pbVar2 < bVar20 || (byte)(*pbVar2 - bVar20) < bVar30;
  *pbVar2 = (*pbVar2 - bVar20) - bVar30;
  puVar1 = puVar25 + -0x3974;
  bVar12 = (byte)*puVar1 - bVar10;
  bVar30 = (byte)*puVar1 < bVar10 || bVar12 < bVar29;
  *(byte *)puVar1 = bVar12 - bVar29;
  puVar1 = unaff_SI + 0x3c8c;
  bVar12 = (byte)*puVar1 - bVar7;
  bVar31 = (byte)*puVar1 < bVar7 || bVar12 < bVar30;
  *(byte *)puVar1 = bVar12 - bVar30;
  puVar1 = puVar25 + 0xc;
  bVar30 = (byte)*puVar1 < bVar16;
  bVar12 = (byte)*puVar1 - bVar16;
  bVar32 = bVar30 || bVar12 < bVar31;
  bVar35 = SBORROW1((byte)*puVar1,bVar16) != SBORROW1(bVar12,bVar31);
  *(byte *)puVar1 = bVar12 - bVar31;
  bVar34 = (char)(byte)*puVar1 < '\0';
  bVar33 = (byte)*puVar1 == 0;
  bVar29 = !bVar35;
  bVar20 = (byte)in_CX;
  puVar26 = puVar25;
  if (!bVar29) {
    puVar1 = unaff_DI;
    unaff_DI = (uint *)((int)unaff_DI + 1);
    uVar3 = in(CONCAT11(bVar16,bVar10));
    *(undefined1 *)puVar1 = uVar3;
    puVar1 = unaff_SI + 0xc;
    uVar15 = *puVar1;
    bVar4 = (byte)*puVar1 - bVar11;
    *(byte *)puVar1 = bVar4 - bVar32;
    *(undefined2 *)(uVar24 + iVar9 + -2) = puVar19;
    ((char *)((int)puVar25 + (int)unaff_SI))[0x18] =
         (((char *)((int)puVar25 + (int)unaff_SI))[0x18] - bVar20) -
         ((byte)uVar15 < bVar11 || bVar4 < bVar32);
    *(uint *)((int)puVar19 + (int)unaff_SI) =
         *(uint *)((int)puVar19 + (int)unaff_SI) ^ (uint)puVar19;
    *(uint *)((int)puVar19 + (int)unaff_SI) =
         *(uint *)((int)puVar19 + (int)unaff_SI) | (uint)puVar19;
    *(char *)((int)puVar19 + (int)unaff_SI) = *(char *)((int)puVar19 + (int)unaff_SI) + bVar17;
    *puVar19 = ~*puVar19;
    puVar26 = (uint *)*puVar25;
    uVar15 = CONCAT11(bVar11,bVar7 - 0x18) & 0x9e1f;
    bVar34 = (int)uVar15 < 0;
    bVar33 = uVar15 == 0;
    puVar22 = puVar25 + 3;
  }
  bVar32 = bVar29 && bVar32;
  uVar28 = *puVar22;
  if (bVar33 || (bVar29 && bVar35) != bVar34) {
    bVar34 = bVar32;
    if ((!bVar29 || !bVar30 && bVar12 >= bVar31) && !bVar33) {
      *puVar22 = (uint)puVar26;
      uVar28 = *puVar22;
      pcVar5 = (char *)(int)(char)bVar20 + -0x1d67;
      iVar9 = (int)pcVar5 - (int)(uint)bVar32;
      *puVar22 = iVar9;
      *(char *)unaff_SI = -(char)*unaff_SI;
      return (iVar9 + -0x1d32) -
             (uint)((char *)(int)(char)bVar20 < (char *)"magicians\' cottage" + 9 ||
                   pcVar5 < (char *)(uint)bVar32);
    }
  }
  else {
    bVar34 = bVar20 < 0x74 || (byte)(bVar20 + 0x8c) < bVar32;
    bVar20 = (bVar20 + 0x8c) - bVar32;
  }
  bVar29 = bVar20 < 100 || (byte)(bVar20 + 0x9c) < bVar34;
  bVar20 = (bVar20 + 0x9c) - bVar34;
  bVar12 = bVar20 - 0x39;
  bVar30 = bVar20 < 0x39 || bVar12 < bVar29;
  bVar12 = bVar12 - bVar29;
  bVar20 = bVar12 - 0x14;
  bVar29 = bVar12 < 0x14 || bVar20 < bVar30;
  bVar20 = bVar20 - bVar30;
  bVar12 = bVar20 - 8;
  bVar30 = bVar20 < 8 || bVar12 < bVar29;
  bVar12 = bVar12 - bVar29;
  bVar20 = bVar12 - 5;
  bVar7 = bVar20 - bVar30;
  iVar9 = ((int)puVar26 - (int)puVar19) -
          (uint)(bVar7 < 0xfa || (byte)(bVar7 + 6) < (bVar12 < 5 || bVar20 < bVar30));
  uVar24 = (uint)unaff_SI & *(uint *)((char *)((int)puVar19 + (int)unaff_SI) + -0x6bdd);
  uVar27 = (uint)unaff_DI & *(uint *)((undefined1 *)((int)puVar19 + (int)unaff_DI) + 0x23);
  *puVar22 = uVar24;
  uVar24 = uVar24 & *(uint *)((int)puVar19 + uVar27);
  uVar15 = CONCAT11(bVar16,bVar10) & *(uint *)(iVar9 + uVar24);
  puVar26 = (uint *)CONCAT11(bVar21,bVar17 & bVar21 &
                                    *(byte *)((int)&_streams[0xc].curp +
                                             CONCAT11(bVar21,bVar17 & bVar21)));
  uVar6 = *puVar22;
  *(uint *)(iVar9 + uVar24) = *(uint *)(iVar9 + uVar24) ^ (uint)(puVar22 + 1);
  *(int *)(iVar9 + uVar24) = *(int *)(iVar9 + uVar24) - (int)(puVar22 + 1);
  bVar10 = in(uVar15);
  uVar24 = uVar24 & uVar15;
  puVar1 = (uint *)((int)puVar26 + (int)((char *)"+%d ring of prot." + 1 + uVar24));
  *puVar1 = *puVar1 & uVar27;
  *(uint *)(uVar27 + 0x21) = *(uint *)(uVar27 + 0x21) & (uint)puVar26;
  *puVar26 = *puVar26 & uVar27;
  puVar1 = (uint *)&AgntAnms[0x5c].sx;
  *puVar1 = *puVar1 & (uint)(puVar22 + 1);
  puVar1 = (uint *)((int)puVar26 + uVar24);
  *puVar1 = *puVar1 & CONCAT11((char)((uint)uVar6 >> 8),bVar10);
  bVar12 = -(0x99 < bVar10);
  return CONCAT11((char)((uint)uVar6 >> 8),
                  bVar12 + (9 < (bVar12 & 0xf) | 9 < (bVar10 & 0xf) | in_AF) * '\x06' +
                  (0x99 < bVar12 || 0x99 < bVar10) * '`');
}


