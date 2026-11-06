/*
 * ovc28.c - recovered from STRONG.EXE
 * memory block: OVC28
 * range: 6018:0000 - 6018:177f
 * functions: 16
 */
#include "recovered.h"


/* 6018:0000 */

void __cdecl16far OVC28_6018_0000(int param_1)

{
  int iVar1;
  
  do {
    iVar1 = param_1 + -1;
    if (param_1 == 0) {
      return;
    }
    do {
      param_1 = iVar1;
      if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != *(int *)(BDA_DailyTimeCounter.ofs + 2)) break;
    } while (*(int *)(BDA_DailyTimeCounter.ofs) == *(int *)(BDA_DailyTimeCounter.ofs));
  } while( true );
}



/* 6018:0048 */

void __cdecl16far OVC28_6018_0048(void)

{
  far_t gfx;
  
  if (DAT_2410_26a8 == '\0') {
    ovr_OVC18_48ac_0027();
    gfx.seg = FontHandle.seg;
    gfx.ofs = FontHandle.ofs;
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)));
  }
  return;
}



/* 6018:007e */

void __cdecl16far update_pause_button(void)

{
  char cVar1;
  far_t gfx;
  far_t gfx_00;
  
  TextBlitDstSeg = 0xa000;
  if ((GPaused != '\0') &&
     ((cVar1 = ovr_OVC15_4207_288b(), cVar1 == '\0' || (GOngoingBattle != '\0')))) {
    gfx_00.seg = DAT_2000_d372;
    gfx_00.ofs = DAT_2000_d370;
    ovr_blitGfxRect(gfx_00,235,116,BlitRects + 1,0x10,false);
    TextBlitY = 0x76;
    TextBlitX = 0xf1;
    ovr_blitLabel("Resume",(uint8_t *)CONCAT22(FontMain.seg,FontMain.ofs),319,0xe0);
    return;
  }
  gfx.seg = DAT_2000_d36e;
  gfx.ofs = DAT_2000_d36c;
  ovr_blitGfxRect(gfx,235,116,BlitRects + 1,0x10,false);
  TextBlitY = 0x76;
  TextBlitX = 0xf0;
  ovr_blitLabel("Pause",(uint8_t *)CONCAT22(Font01.seg,Font01.ofs),319,0xe0);
  return;
}



/* 6018:0176 */

void __cdecl16far OVC28_6018_0176(void)

{
  far_t gfx;
  
  gfx.seg = DAT_2000_caaf;
  gfx.ofs = DAT_2000_caad;
  ovr_blitGfxRect(gfx,223,8,BlitRects + 1,0x10,false);
  OVC28_6018_0000(3);
  OVC28_6018_01af();
  return;
}



/* 6018:01af */

void __cdecl16far OVC28_6018_01af(void)

{
  char cVar1;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  
  cVar1 = ovr_draw_2e25_15d6();
  if ((cVar1 == '\0') || (GameRunning != false)) {
    gfx.seg = DAT_2000_caaf;
    gfx.ofs = DAT_2000_caad;
    ovr_blitGfxRect(gfx,223,8,BlitRects + 1,0x10,false);
  }
  else if (GOngoingBattle == '\0') {
    gfx_00.seg = DAT_2000_cab7;
    gfx_00.ofs = DAT_2000_cab5;
    ovr_blitGfxRect(gfx_00,223,8,BlitRects + 1,0x10,false);
  }
  else {
    gfx_01.seg = DAT_2000_cab3;
    gfx_01.ofs = DAT_2000_cab1;
    ovr_blitGfxRect(gfx_01,223,8,BlitRects + 1,0x10,false);
  }
  return;
}



/* 6018:0251 */

void __cdecl16far OVC28_6018_0251(void)

{
  undefined4 uVar1;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  char *arg1;
  int iVar2;
  char *text;
  byte *widths;
  uint16_t seg;
  uint8_t term;
  char local_104 [128];
  undefined1 local_84 [128];
  undefined1 uStack_4;
  byte bStack_3;
  
  ovr_OVC18_48ac_0027();
  gfx.seg = DAT_2000_cacf;
  gfx.ofs = DAT_2000_cacd;
  ovr_blitGfx10(gfx,0,0,(brect_t *)0x24105ce5,0);
  if (GameRunning == false) {
    gfx_00.seg = DAT_2000_caf7;
    gfx_00.ofs = DAT_2000_caf5;
    ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa0008fa4)));
    gfx_01.seg = DAT_2000_cac3;
    gfx_01.ofs = DAT_2000_cac1;
    ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa000e249)));
    for (iVar2 = 0; iVar2 < 5; iVar2 = iVar2 + 1) {
      if (((undefined1 *)&DAT_2000_d1de)[iVar2] != -1) {
        TextBlitX = 0xea;
        TextBlitY = iVar2 * 0xd + 0x87;
        uVar1 = *(undefined4 *)((uint)(byte)((undefined1 *)&DAT_2000_d1de)[iVar2] << 2);
        bStack_3 = *(byte *)((int)uVar1 + 0x2f);
        if (bStack_3 == 0xff) {
          uStack_4 = 0x46;
        }
        else {
          uStack_4 = *(undefined1 *)*(undefined4 *)((uint)bStack_3 * 4 + 0xeb);
        }
        term = 0xe;
        seg = 0x13f;
        widths = (byte *)Font03.ofs;
        arg1 = (char *)ovr_OVC45_77eb_226e(local_84);
        text = ovr_stsprintf(local_104,"%s-%c",arg1);
        ovr_blitText(text,widths,seg,term);
      }
    }
    update_pause_button();
    OVC28_6018_01af();
  }
  return;
}



/* 6018:03d3 */

void __cdecl16far toggle_pause(void)

{
  char cVar1;
  
  cVar1 = ovr_OVC15_4207_288b();
  if ((cVar1 == '\0') || (GOngoingBattle != '\0')) {
    GPaused = '\x01' - (GPaused != '\0');
    if (GPaused == '\0') {
      ovr_drawTextAt("Resume. Game events will now occur normally.",0xa000);
    }
    else {
      ovr_drawTextAt("Pause. Select \'Resume\' to enable game events. Press SPACE for a single game event."
                     ,0xa000);
    }
    update_pause_button();
  }
  else {
    ovr_drawTextAt("Sorry, you may not pause during a battle.",0xa000);
    GPaused = '\0';
  }
  return;
}



/* 6018:0456 */

void __cdecl16far OVC28_6018_0456(undefined4 param_1,int param_2)

{
  far_t gfx;
  far_t gfx_00;
  far_t dst;
  char *pcVar1;
  char *pcVar2;
  int *piVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  uint8_t *puVar8;
  uint16_t uVar9;
  int16_t iVar10;
  uint8_t uVar11;
  undefined1 local_80 [120];
  int iStack_8;
  char *uStack_6;
  
  gfx.seg = DAT_2000_cacf;
  gfx.ofs = DAT_2000_cacd;
  ovr_blitGfx10(gfx,0,0,(brect_t *)0x24105ce5,0);
  iStack_8 = 0xeb;
  iVar6 = 0x3c;
  for (iVar5 = 0; iVar5 < param_2; iVar5 = iVar5 + 1) {
    uVar7 = (undefined2)((ulong)param_1 >> 0x10);
    piVar3 = (int *)((int)param_1 + iVar5 * 4);
    if (*piVar3 != 0 || piVar3[1] != 0) {
      gfx_00.seg = DAT_2000_d37e;
      gfx_00.ofs = DAT_2000_d37c;
      (*(uint8_t *)((uint8_t *)&(dst.seg))) = 0;
      dst.ofs = iStack_8 + iVar6 * 0x140;
      (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = 0xa0;
      ovr_blitLoadRleGfx(gfx_00,dst);
      TextBlitDstSeg = 0xa000;
      TextBlitX = iStack_8 + 6;
      TextBlitY = iVar6 + 2;
      puVar4 = (undefined2 *)((int)param_1 + iVar5 * 4);
      pcVar2 = (char *)*puVar4;
      uStack_6 = (char *)CONCAT22(puVar4[1],pcVar2);
      if (*uStack_6 == '%') {
        BlitLetterType = 2;
        uVar11 = 0xf;
        iVar10 = 319;
        puVar8 = (uint8_t *)FontMain.ofs;
        uVar9 = FontMain.seg;
        pcVar1 = (char *)ovr_OVC45_77eb_226e(local_80);
        ovr_blitLabel((char *)CONCAT22(pcVar2,pcVar1),(uint8_t *)CONCAT22(uVar9,puVar8),iVar10,
                      uVar11);
        BlitLetterType = 0;
      }
      else if (*uStack_6 == '@') {
        uVar11 = 0xf;
        iVar10 = 319;
        puVar8 = (uint8_t *)FontMain.ofs;
        uVar9 = FontMain.seg;
        pcVar1 = (char *)ovr_OVC45_77eb_226e(local_80);
        ovr_blitLabel((char *)CONCAT22(pcVar2,pcVar1),(uint8_t *)CONCAT22(uVar9,puVar8),iVar10,
                      uVar11);
      }
      else {
        uVar11 = 0xf;
        iVar10 = 319;
        puVar8 = (uint8_t *)FontMain.ofs;
        uVar9 = FontMain.seg;
        pcVar1 = (char *)ovr_OVC45_77eb_226e(local_80);
        ovr_blitLabel((char *)CONCAT22(pcVar2,pcVar1),(uint8_t *)CONCAT22(uVar9,puVar8),iVar10,
                      uVar11);
      }
    }
    iVar6 = iVar6 + 0xe;
  }
  if (DAT_2410_5cef != -1) {
    OVC28_6018_0634(DAT_2410_5cef);
  }
  return;
}



/* 6018:0634 */

void __cdecl16far OVC28_6018_0634(byte param_1)

{
  uint uVar1;
  char *pcVar2;
  uint16_t uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  byte *widths;
  undefined4 uVar6;
  char local_52 [80];
  
  uVar1 = ovr_font_302d_06ea((char *)"Gold",(char *)"puppetmaker" + 3,Font03.ofs);
  TextBlitX = 0x10e - (uVar1 >> 1);
  TextBlitY = 0x9c;
  ovr_blitText("Gold",(byte *)Font03.ofs,0x13f,0xed);
  uVar5 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
  iVar4 = (int)*(undefined4 *)((uint)param_1 << 2);
  ovr_litoa10(local_52,CONCAT22(*(undefined2 *)(iVar4 + 0x58),*(undefined2 *)(iVar4 + 0x56)));
  uVar1 = ovr_font_302d_06ea(local_52);
  uVar3 = 0x10e - (uVar1 >> 1);
  TextBlitY = 0xa7;
  TextBlitX = uVar3;
  ovr_blitText((char *)CONCAT22(unaff_SS,local_52),(byte *)Font03.ofs,0x13f,0xed);
  iVar4 = ovr_OVC45_77eb_0904();
  if (iVar4 != 0 || uVar3 != 0) {
    uVar1 = ovr_font_302d_06ea((char *)"Fund",(char *)"puppetmaker" + 3,Font03.ofs);
    uVar3 = 0x10e - (uVar1 >> 1);
    TextBlitY = 0xb2;
    TextBlitX = uVar3;
    ovr_blitText("Fund",(byte *)Font03.ofs,0x13f,0xed);
    uVar5 = ovr_OVC45_77eb_0904();
    ovr_litoa10(local_52,CONCAT22(uVar3,uVar5));
    uVar1 = ovr_font_302d_06ea(local_52);
    uVar3 = 0x10e - (uVar1 >> 1);
    TextBlitY = 0xbd;
    uVar6 = 0xed013f;
    TextBlitX = uVar3;
    widths = (byte *)Font03.ofs;
    uVar5 = ovr_OVC45_77eb_0904();
    pcVar2 = ovr_litoa10(local_52,CONCAT22(uVar3,uVar5));
    ovr_blitText((char *)CONCAT22(uVar3,pcVar2),widths,(uint16_t)uVar6,
                 (uint8_t)((ulong)uVar6 >> 0x10));
  }
  return;
}



/* 6018:0813 */

void __cdecl16far OVC28_6018_0813(int param_1,int param_2,char *param_3)

{
  char *pcVar1;
  char *pcVar2;
  byte *pbVar3;
  far_t gfx;
  uint8_t *puVar4;
  far_t gfx_00;
  far_t dst;
  undefined4 uVar5;
  far_t dst_00;
  undefined1 local_52 [80];
  
  dst.seg = 0xa000;
  dst.ofs = param_1 + param_2 * 0x140;
  gfx.seg = DAT_2000_d382;
  gfx.ofs = DAT_2000_d380;
  ovr_blitLoadRleGfx(gfx,dst);
  TextBlitX = param_1 + 6;
  TextBlitY = param_2 + 2;
  pcVar2 = (char *)"puppetmaker" + 3;
  if (*param_3 == '%') {
    BlitLetterType = 2;
    uVar5 = 0x8013f;
    puVar4 = (uint8_t *)CONCAT22(Font01.seg,Font01.ofs);
    pcVar1 = (char *)ovr_OVC45_77eb_226e(local_52);
    ovr_blitLabel((char *)CONCAT22(pcVar2,pcVar1),puVar4,(int16_t)uVar5,
                  (uint8_t)((ulong)uVar5 >> 0x10));
    BlitLetterType = 0;
  }
  else if (*param_3 == '@') {
    uVar5 = 0x8013f;
    puVar4 = (uint8_t *)CONCAT22(Font01.seg,Font01.ofs);
    pcVar1 = (char *)ovr_OVC45_77eb_226e(local_52);
    ovr_blitLabel((char *)CONCAT22(pcVar2,pcVar1),puVar4,(int16_t)uVar5,
                  (uint8_t)((ulong)uVar5 >> 0x10));
  }
  else {
    uVar5 = 0x8013f;
    pbVar3 = (byte *)Font01.ofs;
    pcVar1 = (char *)ovr_OVC45_77eb_226e(local_52);
    ovr_blitText((char *)CONCAT22(pcVar2,pcVar1),pbVar3,(uint16_t)uVar5,
                 (uint8_t)((ulong)uVar5 >> 0x10));
  }
  OVC28_6018_0000(0);
  dst_00.seg = 0xa000;
  dst_00.ofs = param_1 + param_2 * 0x140;
  gfx_00.seg = DAT_2000_d37e;
  gfx_00.ofs = DAT_2000_d37c;
  ovr_blitLoadRleGfx(gfx_00,dst_00);
  TextBlitX = param_1 + 6;
  TextBlitY = param_2 + 2;
  pcVar2 = (char *)"puppetmaker" + 3;
  if (*param_3 == '%') {
    BlitLetterType = 2;
    uVar5 = 0x8013f;
    puVar4 = (uint8_t *)CONCAT22(FontMain.seg,FontMain.ofs);
    pcVar1 = (char *)ovr_OVC45_77eb_226e(local_52);
    ovr_blitLabel((char *)CONCAT22(pcVar2,pcVar1),puVar4,(int16_t)uVar5,
                  (uint8_t)((ulong)uVar5 >> 0x10));
    BlitLetterType = 0;
  }
  else if (*param_3 == '@') {
    uVar5 = 0x8013f;
    puVar4 = (uint8_t *)CONCAT22(FontMain.seg,FontMain.ofs);
    pcVar1 = (char *)ovr_OVC45_77eb_226e(local_52);
    ovr_blitLabel((char *)CONCAT22(pcVar2,pcVar1),puVar4,(int16_t)uVar5,
                  (uint8_t)((ulong)uVar5 >> 0x10));
  }
  else {
    uVar5 = 0x8013f;
    pbVar3 = (byte *)FontMain.ofs;
    pcVar1 = (char *)ovr_OVC45_77eb_226e(local_52);
    ovr_blitText((char *)CONCAT22(pcVar2,pcVar1),pbVar3,(uint16_t)uVar5,
                 (uint8_t)((ulong)uVar5 >> 0x10));
  }
  return;
}



/* 6018:0aac */

void __cdecl16far OVC28_6018_0aac(undefined4 param_1,int param_2)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  
  if (param_2 < 0xfa) {
    uVar2 = (undefined2)((ulong)param_1 >> 0x10);
    puVar1 = (undefined2 *)((int)param_1 + param_2 * 4);
    OVC28_6018_0813(0xeb,param_2 * 0xe + 0x3c,(char *)(void far *)MK_FP(puVar1[1],*puVar1));
  }
  return;
}



/* 6018:0aef */

void __cdecl16far OVC28_6018_0aef(void)

{
  uint16_t unk;
  far_t gfx;
  far_t handle;
  far_t dst;
  
  CrossBlitFlag = 0;
  CrossBlitCount2 = 0;
  CrossBlitCount = 1;
  if (GMenuItem == 0) {
    CrossBlitX = 3;
    CrossBlitY = 0xb0;
  }
  else if ((GMenuItem < 0x7f) || (DAT_2410_5ce4 == '\0')) {
    CrossBlitX = 0xe7;
    CrossBlitY = (uint)GMenuItem * 0xe + 0x2b;
  }
  else {
    CrossBlitX = (GMenuItem - 0xfc) * 0x44 + 10;
    CrossBlitY = 0xb0;
  }
  if (CrossBlitPtr.ofs != 0 || CrossBlitPtr.seg != 0) {
    handle.seg = CrossBlitPtr.seg;
    handle.ofs = CrossBlitPtr.ofs;
    ovr_stshFree(handle);
  }
  CrossBlitPtr = ovr_stshRleCut(far_from_u32((uint32_t)(0xa0000000)),CrossBlitX,CrossBlitY,CrossBlitX + 0xd,
                                CrossBlitY + 9);
  dst.seg = 0xa000;
  dst.ofs = CrossBlitX + CrossBlitY * 0x140;
  gfx.seg = CrossBlitGfx.seg;
  gfx.ofs = CrossBlitGfx.ofs;
  ovr_blitLoadRleGfx(gfx,dst);
  if (DAT_2410_00e8 == 0) {
    unk = ovr_draw_2e25_0245();
    ovr_play_sfxU(0,1,unk);
  }
  return;
}



/* 6018:0c76 */

undefined2 __cdecl16far OVC28_6018_0c76(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  undefined2 uVar3;
  char cStack_8;
  char cStack_4;
  
  if (((((DAT_2410_26a8 == '\0') && (DAT_2410_00e8 == 0)) && (8 < DAT_2410_00e4)) &&
      ((DAT_2410_00e4 < 0x19 && (0xb4 < DAT_2410_00e6)))) && ((DAT_2410_00e6 < 0xb6 | 0xeU) != 0)) {
    uVar3 = 0;
  }
  else {
    if (((DAT_2410_00e8 == 0) && (0xea < DAT_2410_00e4)) &&
       ((0x3b < DAT_2410_00e6 && (DAT_2410_00e4 < 0x139)))) {
      uVar1 = (DAT_2410_00e6 - 0x3c) / 0xe;
      if ((uVar1 < param_2) && ((DAT_2410_00e6 - 0x3c) % 0xe < 0xc)) {
        uVar3 = (undefined2)((ulong)param_1 >> 0x10);
        piVar2 = (int *)((int)param_1 + uVar1 * 4);
        if (*piVar2 != 0 || piVar2[1] != 0) {
          OVC28_6018_0aac(CONCAT22(uVar3,(int)param_1),uVar1);
          cStack_4 = (char)uVar1;
          GMenuItem = cStack_4 + '\x01';
          return CONCAT11(0x24,cStack_4 + '\x01');
        }
      }
    }
    if ((((DAT_2410_00e8 == 0) && (DAT_2410_5ce4 != '\0')) && (0xf < DAT_2410_00e4)) &&
       ((0xb2 < DAT_2410_00e6 && (DAT_2410_00e6 < 0xbf)))) {
      uVar1 = (DAT_2410_00e4 - 0x10) / 0x44;
      if ((uVar1 < 3) && ((DAT_2410_00e4 - 0x10) % 0x44 < 0x43)) {
        cStack_8 = (char)uVar1;
        GMenuItem = cStack_8 + -4;
        return CONCAT11(0x24,cStack_8 + -4);
      }
    }
    if (((DAT_2410_5cf0 == '\0') || (DAT_2410_00e8 != 0)) ||
       ((DAT_2410_00e4 < 0xc ||
        (((0xde < DAT_2410_00e4 || (DAT_2410_00e6 < 7)) || (0x96 < DAT_2410_00e6)))))) {
      if (((DAT_2410_5cf0 == '\0') || (DAT_2410_00e8 != 0)) ||
         ((DAT_2410_00e4 < 0xef ||
          (((0x134 < DAT_2410_00e4 || (DAT_2410_00e6 < 7)) || (0x36 < DAT_2410_00e6)))))) {
        uVar3 = 0xff;
      }
      else {
        OVC28_6018_0251();
        ovr_OVC13_3d16_1a01(DAT_2410_00e4 - 0xef >> 1,DAT_2410_00e6 - 7,1);
        uVar3 = 0xfe;
      }
    }
    else {
      OVC28_6018_0251();
      ovr_OVC13_3d16_1945(DAT_2410_00e4 - 0xc >> 1,DAT_2410_00e6 - 7,1);
      uVar3 = 0xfe;
    }
  }
  return uVar3;
}



/* 6018:0f29 */

char * __cdecl16far
uiInputText(int param_1,undefined2 param_2,uint param_3,char *param_4,int param_5,byte param_6)

{
  char cVar1;
  int iVar2;
  undefined1 extraout_AH;
  char *pcVar3;
  
  UserWantsExit = 0;
  if (param_4 != (char *)0x0 || param_5 != 0) {
    if (DAT_2410_26a8 == '\0') {
      ovr_drawTextAt((char *)CONCAT22(param_5,param_4),0xa000);
    }
    else {
      ovr_drawString();
    }
  }
  OVC28_6018_0456(CONCAT22(param_2,param_1),param_3);
  GMenuItem = 1;
  while (((int)(uint)GMenuItem <= (int)param_3 &&
         (iVar2 = (uint)GMenuItem * 4 + param_1,
         *(int *)(iVar2 + -4) == 0 && *(int *)(iVar2 + -2) == 0))) {
    GMenuItem = GMenuItem + 1;
  }
  if ((int)param_3 < (int)(uint)GMenuItem) {
    GMenuItem = 0;
  }
  ovr_OVC40_69c8_047f();
  if (DAT_2410_5cf1 != '\0') {
    ovr_play_sfx(CONCAT11(extraout_AH,DAT_2410_5cf1),0);
    DAT_2410_5cf1 = '\0';
  }
  GMenuFlag = 1;
LAB_6018_1007:
  do {
    while( true ) {
      pcVar3 = (char *)ovr_uiReadKey2();
      if (pcVar3 != (char *)"dc%lx %d ln %ld lc %ld @%lx \r" + 0xf) break;
LAB_6018_110e:
      do {
        if (DAT_2410_5ce4 == '\0') {
          if (DAT_2410_26a8 == '\0') {
            if (GMenuItem == 0) {
              GMenuItem = (byte)param_3;
            }
            else {
              GMenuItem = GMenuItem - 1;
            }
          }
          else if (GMenuItem < 2) {
            GMenuItem = (byte)param_3;
          }
          else {
            GMenuItem = GMenuItem - 1;
          }
        }
        else if (GMenuItem == 0xfc) {
          GMenuItem = (byte)param_3;
        }
        else if (GMenuItem < 2) {
          GMenuItem = 0xfe;
        }
        else {
          GMenuItem = GMenuItem - 1;
        }
      } while ((GMenuItem != 0) &&
              (iVar2 = (uint)GMenuItem * 4 + param_1,
              *(int *)(iVar2 + -4) == 0 && *(int *)(iVar2 + -2) == 0));
      OVC28_6018_0aef();
    }
    if (pcVar3 < (char *)"dc%lx %d ln %ld lc %ld @%lx \r" + 0x10) {
      if (pcVar3 == (char *)0x1675) {
LAB_6018_10f1:
        if (DAT_2410_5ce4 != '\0') {
          GMenuFlag = 0;
          return (char *)"thief" + 4;
        }
        goto LAB_6018_1007;
      }
      if (pcVar3 <= (char *)&AgntAnms[0x6f].nframes) {
        if (pcVar3 != (char *)0x1372) {
          if ((char *)0x1372 < pcVar3) {
            if (pcVar3 == (char *)0x1655) goto LAB_6018_10f1;
            goto LAB_6018_1007;
          }
          if (pcVar3 == (char *)0x11b) {
            UserWantsExit = 1;
            goto LAB_6018_1348;
          }
          if (pcVar3 != (char *)0x1352) goto LAB_6018_1007;
        }
        if (DAT_2410_5ce4 != '\0') {
          GMenuFlag = 0;
          return (char *)"thief" + 2;
        }
        goto LAB_6018_1007;
      }
      if (pcVar3 != (char *)"thief outpost" + 3) {
        if ((char *)"thief outpost" + 3 < pcVar3) {
          if (pcVar3 == (char *)0x4800) goto LAB_6018_110e;
          goto LAB_6018_1007;
        }
        if (pcVar3 == (char *)"%s: provides housing and income." + 8) {
          if (GMenuItem != 0) {
            OVC28_6018_0aac(CONCAT22(param_2,param_1),GMenuItem - 1);
          }
          OVC28_6018_0048();
          GMenuFlag = 0;
          return (char *)CONCAT11(0x24,GMenuItem);
        }
        if (pcVar3 != (char *)"fighter outpost" + 0xf) goto LAB_6018_1007;
      }
      if (DAT_2410_5ce4 != '\0') {
        GMenuFlag = 0;
        return (char *)"thief" + 3;
      }
      goto LAB_6018_1007;
    }
    if (pcVar3 == (char *)"%s will now build homes automatically.") {
LAB_6018_1376:
      if ((param_6 & 2) != 0) {
        GMenuFlag = 0;
        return (char *)CONCAT11(0x24,(byte)param_3);
      }
    }
    else if (pcVar3 < (char *)"%s will now build homes automatically." + 1) {
      if (pcVar3 == (char *)"Reroll ability scores, or select the character\'s class." + 0x2b) {
LAB_6018_11ee:
        do {
          if (DAT_2410_5ce4 == '\0') {
            if (DAT_2410_26a8 == '\0') {
              if ((int)(uint)GMenuItem < (int)param_3) {
                GMenuItem = GMenuItem + 1;
              }
              else {
                GMenuItem = 0;
              }
            }
            else if ((int)(uint)GMenuItem < (int)param_3) {
              GMenuItem = GMenuItem + 1;
            }
            else {
              GMenuItem = 1;
            }
          }
          else if (GMenuItem == 0xfe) {
            GMenuItem = 1;
          }
          else if (GMenuItem == param_3) {
            GMenuItem = 0xfc;
          }
          else {
            GMenuItem = GMenuItem + 1;
          }
        } while ((GMenuItem != 0) &&
                (iVar2 = (uint)GMenuItem * 4 + param_1,
                *(int *)(iVar2 + -4) == 0 && *(int *)(iVar2 + -2) == 0));
        OVC28_6018_0aef();
      }
      else if (pcVar3 < (char *)"Reroll ability scores, or select the character\'s class." + 0x2c) {
        if (((pcVar3 == (char *)"pasopl.adv" + 7) || (pcVar3 == (char *)0x4939)) &&
           ((param_6 & 1) != 0)) {
          GMenuFlag = 0;
          return (char *)"arena" + 5;
        }
      }
      else if (pcVar3 == (char *)"Please type your character\'s name. Esc go back." + 8)
      goto LAB_6018_11ee;
    }
    else {
      if (pcVar3 == (char *)"%s will no longer build houses automatically." + 0xc)
      goto LAB_6018_1376;
      if (pcVar3 == (char *)0xfffe) {
LAB_6018_1348:
        OVC28_6018_0048();
        GMenuFlag = 0;
        return (char *)"arena" + 4;
      }
      if ((pcVar3 == (char *)0xffff) &&
         (cVar1 = OVC28_6018_0c76(CONCAT22(param_2,param_1),param_3), cVar1 != -1)) {
        OVC28_6018_0048();
        GMenuFlag = 0;
        return (char *)CONCAT11(0x24,cVar1);
      }
    }
  } while( true );
}



/* 6018:1398 */

undefined2 __cdecl16far
OVC28_6018_1398(undefined4 param_1,int param_2,undefined2 param_3,undefined2 param_4,byte *param_5)

{
  char *pcVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  undefined2 unaff_SS;
  char *local_36 [18];
  char *pcStack_12;
  char *pcStack_10;
  undefined2 uStack_e;
  undefined2 uStack_c;
  char cStack_9;
  undefined1 uStack_8;
  byte bStack_7;
  byte bStack_6;
  byte bStack_5;
  byte bStack_4;
  byte bStack_3;
  
  uStack_c = param_4;
  uStack_e = param_3;
  if (param_2 < 10) {
    uVar2 = (undefined2)(ulong)uiInputText((int)param_1,(*(uint16_t *)((uint8_t *)&(param_1) + 2)),param_2,(char *)(void far *)MK_FP(0,(uint16_t)param_3),param_4,0);
  }
  else {
    while( true ) {
      local_36[1] = (char *)"puppetmaker" + 3;
      local_36[0] = (char *)"Previous";
      pcStack_10 = (char *)"puppetmaker" + 3;
      pcStack_12 = (char *)"Next";
      if (*param_5 == 0) {
        bStack_4 = 0;
        bStack_6 = 0;
        bStack_5 = 9;
        uStack_8 = 2;
        cStack_9 = '\n';
      }
      else if ((int)((uint)*param_5 * 8 + 8) < param_2) {
        bStack_4 = 1;
        bStack_6 = *param_5 * '\b' + 1;
        bStack_5 = 8;
        uStack_8 = 3;
        cStack_9 = '\n';
      }
      else {
        bStack_4 = 1;
        bStack_6 = *param_5 * '\b' + 1;
        bStack_5 = (char)param_2 - bStack_6;
        cStack_9 = bStack_5 + 1;
        uStack_8 = 1;
      }
      for (bStack_7 = 0; bStack_7 < bStack_5; bStack_7 = bStack_7 + 1) {
        puVar4 = (undefined2 *)((int)param_1 + ((uint)bStack_6 + (uint)bStack_7) * 4);
        pcVar1 = (char *)*puVar4;
        uVar5 = (uint)bStack_4;
        uVar3 = (uint)bStack_7;
        local_36[(uVar5 + uVar3) * 2 + 1] = (char *)puVar4[1];
        local_36[(uVar5 + uVar3) * 2] = pcVar1;
      }
      bStack_3 = (byte)(ulong)uiInputText(0,0,0,(char *)0,0,0);
      if (bStack_3 == 0) {
        return 0;
      }
      if (bStack_3 == 0xfe) {
        return 0xfe;
      }
      if ((bStack_4 + 1 <= (uint)bStack_3) &&
         (uVar3 = (uint)bStack_4 + (uint)bStack_5 + 1, bStack_3 < uVar3)) break;
      if (bStack_3 == 1) {
        *param_5 = *param_5 - 1;
      }
      else {
        *param_5 = *param_5 + 1;
      }
    }
    uVar2 = CONCAT11((char)(uVar3 >> 8),(bStack_6 + bStack_3) - bStack_4);
  }
  return uVar2;
}



/* 6018:1527 */

void __cdecl16far
OVC28_6018_1527(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 param_5)

{
  undefined1 local_3;
  
  local_3 = 0;
  OVC28_6018_1398(CONCAT22(param_2,param_1),param_3,param_4,param_5,&local_3);
  return;
}


