/*
 * ovc28_ui.c - recovered from STRONG.EXE
 * memory block: OVC28_ui.c
 * range: 6018:0000 - 6018:177f
 * functions: 16
 */
#include "recovered.h"


/* 6018:0000 */

/* [R6] touches BDA_DailyTimeCounter */

void __cdecl16far ovc28_usesBDADailyTimeCounter(int ticks,...)

{
  int iVar1;
  int in_stack_00000004;
  
  do {
    iVar1 = in_stack_00000004 + -1;
    if (in_stack_00000004 == 0) {
      return;
    }
    do {
      in_stack_00000004 = iVar1;
      if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != *(int *)(BDA_DailyTimeCounter.ofs + 2)) break;
    } while (*(int *)BDA_DailyTimeCounter == *(int *)BDA_DailyTimeCounter);
  } while( true );
}



/* 6018:0048 */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far ovc28_usesBlitLoadRleGfx(void)

{
  uint16_t unaff_BP;
  far_t gfx;
  far_t dst;
  
  if (ScreenMode == '\0') {
    ovr_ovc18_blitPanelIfNotRunning();
    dst.seg = unaff_BP;
    dst.ofs = 0xa000;
    gfx.seg = 0xc31d;
    gfx.ofs = FontHandle.seg;
    ovr_blitLoadRleGfx(gfx,dst,FontHandle.ofs);
  }
  return;
}



/* 6018:007e */

void __cdecl16far update_pause_button(void)

{
  bool bVar1;
  undefined1 unaff_BP;
  far_t gfx;
  far_t gfx_00;
  
  TextBlitDstSeg = 0xa000;
  if ((GPaused != '\0') && ((bVar1 = ovr_ovc15_usesAlignUp42(), !bVar1 || (GOngoingBattle != '\0')))
     ) {
    gfx_00.seg = 0xeb;
    gfx_00.ofs = butt01Cut2Seg;
    ovr_blitGfxRect(gfx_00,116,1098,(brect_t *)0x102410,0x0,(bool)unaff_BP,butt01Cut2Ofs);
    TextBlitY = 0x76;
    TextBlitX = 0xf1;
    ovr_blitLabel();
    return;
  }
  gfx.seg = 0xeb;
  gfx.ofs = butt01Cut1Seg;
  ovr_blitGfxRect(gfx,116,1098,(brect_t *)0x102410,0x0,(bool)unaff_BP,butt01Cut1Ofs);
  TextBlitY = 0x76;
  TextBlitX = 0xf0;
  ovr_blitLabel();
  return;
}



/* 6018:0176 */

/* Blits the button1Cut3 toolbar button at (223,8) and updates the daily-time counter. */

void __cdecl16far ovc28_blitButton(void)

{
  int unaff_BP;
  far_t gfx;
  
  gfx.seg = 0xdf;
  gfx.ofs = button1Cut3Seg;
  ovr_blitGfxRect(gfx,8,1098,(brect_t *)0x102410,0x0,SUB21(unaff_BP,0),button1Cut3Ofs);
  ovc28_usesBDADailyTimeCounter(unaff_BP,3);
  ovc28_usesBlitGfxRect2();
  return;
}



/* 6018:01af */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc28_usesBlitGfxRect2(void)

{
  bool bVar1;
  undefined1 unaff_BP;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  
  bVar1 = ovr_draw_textArena();
  if ((bVar1) && (GameRunning == false)) {
    if (GOngoingBattle == '\0') {
      gfx_00.seg = 0xdf;
      gfx_00.ofs = button1Cut1Seg;
      ovr_blitGfxRect(gfx_00,8,1098,(brect_t *)0x102410,0x0,(bool)unaff_BP,button1Cut1Ofs);
    }
    else {
      gfx_01.seg = 0xdf;
      gfx_01.ofs = button1Cut2Seg;
      ovr_blitGfxRect(gfx_01,8,1098,(brect_t *)0x102410,0x0,(bool)unaff_BP,button1Cut2Ofs);
    }
  }
  else {
    gfx.seg = 0xdf;
    gfx.ofs = button1Cut3Seg;
    ovr_blitGfxRect(gfx,8,1098,(brect_t *)0x102410,0x0,(bool)unaff_BP,button1Cut3Ofs);
  }
  return;
}



/* 6018:0251 */

/* [R2] string "halfling castle" */

void __cdecl16far ovc28_textHalflingCastle(void)

{
  undefined4 uVar1;
  far_t gfx;
  far_t gfx_00;
  far_t dst;
  far_t dst_00;
  undefined2 *puVar2;
  char *pcVar3;
  char *pcVar4;
  undefined2 unaff_SI;
  int iVar5;
  char *unaff_SS;
  uint16_t uVar6;
  byte *pbVar7;
  undefined2 uVar8;
  uint16_t seg;
  uint8_t term;
  undefined1 uVar9;
  uint8_t msg;
  uint8_t text;
  char cStack_4;
  byte bStack_3;
  
  term = (uint8_t)unaff_SI;
  uVar9 = (undefined1)((uint)unaff_SI >> 8);
  ovr_ovc18_blitPanelIfNotRunning();
  ovr_blitGfx10();
  if (GameRunning == false) {
    gfx.seg = 0x8fa4;
    gfx.ofs = panel01Cut2Seg;
    (*(uint8_t *)((uint8_t *)&(dst.seg))) = term;
    dst.ofs = 0xa000;
    (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar9;
    ovr_blitLoadRleGfx(gfx,dst,panel01Cut2Ofs);
    gfx_00.seg = 0xe249;
    gfx_00.ofs = trianglsCut5Seg;
    (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = term;
    dst_00.ofs = 0xa000;
    (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = uVar9;
    ovr_blitLoadRleGfx(gfx_00,dst_00,trianglsCut5Ofs);
    for (iVar5 = 0; iVar5 < 5; iVar5 = iVar5 + 1) {
      if (((uint8_t *)MenuItemEnabled)[iVar5] != 0xff) {
        TextBlitX = 0xea;
        TextBlitY = iVar5 * 0xd + 0x87;
        uVar1 = *(undefined4 *)((uint)((uint8_t *)MenuItemEnabled)[iVar5] << 2);
        bStack_3 = *(byte *)((int)uVar1 + 0x2f);
        if (bStack_3 == 0xff) {
          cStack_4 = 'F';
        }
        else {
          cStack_4 = *(char *)*(undefined4 *)((uint)bStack_3 * 4 + 0xeb);
        }
        seg = 0xe;
        uVar8 = 0x13f;
        puVar2 = (undefined2 *)((uint)((uint8_t *)MenuItemEnabled)[iVar5] * 4);
        pcVar4 = (char *)"halfling castle" + 0xc;
        uVar6 = Font03.ofs;
        pbVar7 = (byte *)Font03.seg;
        ovr_ovc45_compute9((char *)CONCAT22(*puVar2,unaff_SS),
                           (char *)CONCAT22(Font03.ofs,(char *)puVar2[1]),
                           (char *)CONCAT22(0x2a,Font03.seg),3,cStack_4,&text);
        pcVar3 = ovr_stsprintf();
        ovr_blitText((char *)CONCAT22(uVar6,pcVar4),(byte *)CONCAT22(uVar8,pbVar7),seg,term,pcVar3);
      }
    }
    update_pause_button();
    ovc28_usesBlitGfxRect2();
  }
  return;
}



/* 6018:03d3 */

void __cdecl16far toggle_pause(void)

{
  bool bVar1;
  uint16_t unaff_BP;
  
  bVar1 = ovr_ovc15_usesAlignUp42();
  if ((bVar1) && (GOngoingBattle == '\0')) {
    ovr_drawTextAt((char *)0xa0002410,unaff_BP,0x5d05);
    GPaused = '\0';
  }
  else {
    GPaused = '\x01' - (GPaused != '\0');
    if (GPaused == '\0') {
      ovr_drawTextAt((char *)0xa0002410,unaff_BP,0x5d82);
    }
    else {
      ovr_drawTextAt((char *)0xa0002410,unaff_BP,0x5d2f);
    }
    update_pause_button();
  }
  return;
}



/* 6018:0456 */

/* [R4] calls ovr_blitGfx10 */

void __cdecl16far ovc28_usesBlitGfx10(far_t entries,int count)

{
  char *pcVar1;
  far_t gfx;
  far_t gfx_00;
  far_t dst;
  int iVar2;
  char *pcVar3;
  uint16_t uVar4;
  int *piVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined2 unaff_DI;
  int iVar8;
  uint16_t uVar9;
  char *unaff_SS;
  char mode;
  undefined1 uVar10;
  uint8_t *puVar11;
  undefined2 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  uint8_t type;
  undefined1 uVar15;
  uint8_t text;
  int iStack_8;
  undefined4 uStack_6;
  
  type = (uint8_t)unaff_DI;
  uVar15 = (undefined1)((uint)unaff_DI >> 8);
  gfx.seg = 0;
  gfx.ofs = fullScreenGfxSeg;
  ovr_blitGfx10(gfx,0,0x5ce5,(brect_t *)0x2410,(bool)type,fullScreenGfxOfs,0,0);
  iStack_8 = 0xeb;
  iVar8 = 0x3c;
  for (iVar7 = 0; iVar7 < count; iVar7 = iVar7 + 1) {
    uVar9 = entries.seg;
    uVar4 = entries.ofs;
    piVar5 = (int *)(uVar4 + iVar7 * 4);
    if (*piVar5 != 0 || piVar5[1] != 0) {
      gfx_00.seg = iStack_8 + iVar8 * 0x140;
      gfx_00.ofs = butt01Cut5Seg;
      (*(uint8_t *)((uint8_t *)&(dst.seg))) = type;
      dst.ofs = 0xa000;
      (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar15;
      ovr_blitLoadRleGfx(gfx_00,dst,(char)butt01Cut5Ofs,0);
      TextBlitDstSeg = 0xa000;
      TextBlitX = iStack_8 + 6;
      TextBlitY = iVar8 + 2;
      puVar6 = (undefined2 *)(uVar4 + iVar7 * 4);
      pcVar1 = (char *)puVar6[1];
      pcVar3 = (char *)*puVar6;
      uStack_6 = (char *)CONCAT22(pcVar1,pcVar3);
      mode = (char)FontMain.ofs;
      uVar10 = (undefined1)(FontMain.ofs >> 8);
      if (*uStack_6 == '%') {
        BlitLetterType = 2;
        uVar13 = 0xf;
        uVar14 = 0;
        uVar12 = 0x13f;
        puVar11 = (uint8_t *)FontMain.seg;
        iVar2 = ovr_ovc45_compute9((char *)CONCAT22(pcVar3 + 1,unaff_SS),
                                   (char *)CONCAT22(FontMain.ofs,pcVar1),
                                   (char *)CONCAT22(0x45,FontMain.seg),3,mode,&text);
        ovr_blitLabel((char *)CONCAT13(uVar10,CONCAT12(mode,pcVar3)),
                      (uint8_t *)CONCAT22(uVar12,puVar11),CONCAT11(uVar14,uVar13),type,iVar2,uVar13)
        ;
        BlitLetterType = 0;
      }
      else if (*uStack_6 == '@') {
        uVar13 = 0xf;
        uVar14 = 0;
        uVar12 = 0x13f;
        puVar11 = (uint8_t *)FontMain.seg;
        iVar2 = ovr_ovc45_compute9((char *)CONCAT22(pcVar3 + 1,unaff_SS),
                                   (char *)CONCAT22(FontMain.ofs,pcVar1),
                                   (char *)CONCAT22(0x45,FontMain.seg),3,mode,&text);
        ovr_blitLabel((char *)CONCAT13(uVar10,CONCAT12(mode,pcVar3)),
                      (uint8_t *)CONCAT22(uVar12,puVar11),CONCAT11(uVar14,uVar13),type,iVar2,uVar13)
        ;
      }
      else {
        uVar13 = 0xf;
        uVar14 = 0;
        uVar12 = 0x13f;
        puVar6 = (undefined2 *)(uVar4 + iVar7 * 4);
        puVar11 = (uint8_t *)FontMain.seg;
        iVar2 = ovr_ovc45_compute9((char *)CONCAT22(*puVar6,unaff_SS),
                                   (char *)CONCAT22(FontMain.ofs,(char *)puVar6[1]),
                                   (char *)CONCAT22(0x45,FontMain.seg),3,mode,&text);
        ovr_blitLabel((char *)CONCAT13(uVar10,CONCAT12(mode,pcVar3)),
                      (uint8_t *)CONCAT22(uVar12,puVar11),CONCAT11(uVar14,uVar13),type,iVar2,uVar13)
        ;
      }
    }
    iVar8 = iVar8 + 0xe;
  }
  if (goldPartyIndex != 0xff) {
    ovc28_drawGold(goldPartyIndex);
  }
  return;
}



/* 6018:0634 */

/* WARNING: Variable defined which should be unmapped: numText */
/* Draws the "Gold" label and the party's gold amount. */

void __cdecl16far ovc28_drawGold(byte partyIndex)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  char *unaff_SS;
  uint8_t numText;
  undefined4 uStack_54;
  
  uVar1 = ovr_font_textWidth();
  TextBlitX = 0x10e - (uVar1 >> 1);
  TextBlitY = 0x9c;
  ovr_blitText();
  ovr_litoa10();
  uVar1 = ovr_font_textWidth();
  uVar4 = 0x10e - (uVar1 >> 1);
  TextBlitY = 0xa7;
  TextBlitX = uVar4;
  iVar2 = ovr_blitText();
  iVar2 = ovr_ovc45_usesLDIV_at_(numText,CONCAT11((char)((uint)iVar2 >> 8),partyIndex));
  if (iVar2 != 0 || uVar4 != 0) {
    uVar1 = ovr_font_textWidth();
    TextBlitX = 0x10e - (uVar1 >> 1);
    TextBlitY = 0xb2;
    iVar2 = ovr_blitText();
    ovr_ovc45_usesLDIV_at_(numText,CONCAT11((char)((uint)iVar2 >> 8),partyIndex));
    ovr_litoa10();
    uVar1 = ovr_font_textWidth();
    uVar5 = 0x10e - (uVar1 >> 1);
    TextBlitY = 0xbd;
    uStack_54 = CONCAT22(numText,0xed);
    TextBlitX = uVar5;
    uVar4 = Font03.ofs;
    uVar3 = ovr_ovc45_usesLDIV_at_((uint8_t)Font03.ofs,CONCAT11(0x24,partyIndex));
    ovr_litoa10((char *)CONCAT22(uVar3,unaff_SS),CONCAT22(uVar4,uVar5),&numText);
    ovr_blitText();
  }
  return;
}



/* 6018:0813 */

/* Draws a butt01Cut6 button at (x,y) and its label. */

void __cdecl16far ovc28_drawButton(int x,int y,char *label)

{
  char *unaff_SS;
  char cVar1;
  uint8_t text;
  
  ovr_blitLoadRleGfx();
  TextBlitX = x + 6;
  TextBlitY = y + 2;
  cVar1 = (char)Font01.ofs;
  if (*label == '%') {
    BlitLetterType = 2;
    ovr_ovc45_compute9((char *)CONCAT22((char *)label + 1,unaff_SS),
                       (char *)CONCAT22(Font01.ofs,(*(uint16_t *)((uint8_t *)&(label) + 2))),(char *)CONCAT22(0x45,Font01.seg),3,
                       cVar1,&text);
    ovr_blitLabel();
    BlitLetterType = 0;
  }
  else if (*label == '@') {
    ovr_ovc45_compute9((char *)CONCAT22((char *)label + 1,unaff_SS),
                       (char *)CONCAT22(Font01.ofs,(*(uint16_t *)((uint8_t *)&(label) + 2))),(char *)CONCAT22(0x45,Font01.seg),3,
                       cVar1,&text);
    ovr_blitLabel();
  }
  else {
    ovr_ovc45_compute9((char *)CONCAT22((char *)label,unaff_SS),
                       (char *)CONCAT22(FontMain.ofs,(*(uint16_t *)((uint8_t *)&(label) + 2))),
                       (char *)CONCAT22(0x45,FontMain.seg),3,cVar1,&text);
    ovr_blitText();
  }
  ovc28_usesBDADailyTimeCounter();
  ovr_blitLoadRleGfx();
  TextBlitX = x + 6;
  TextBlitY = y + 2;
  cVar1 = (char)FontMain.ofs;
  if (*label == '%') {
    BlitLetterType = 2;
    ovr_ovc45_compute9((char *)CONCAT22((char *)label + 1,unaff_SS),
                       (char *)CONCAT22(FontMain.ofs,(*(uint16_t *)((uint8_t *)&(label) + 2))),
                       (char *)CONCAT22(0x45,FontMain.seg),3,cVar1,&text);
    ovr_blitLabel();
    BlitLetterType = 0;
  }
  else if (*label == '@') {
    ovr_ovc45_compute9((char *)CONCAT22((char *)label + 1,unaff_SS),
                       (char *)CONCAT22(FontMain.ofs,(*(uint16_t *)((uint8_t *)&(label) + 2))),
                       (char *)CONCAT22(0x45,FontMain.seg),3,cVar1,&text);
    ovr_blitLabel();
  }
  else {
    ovr_ovc45_compute9((char *)CONCAT22((char *)label,unaff_SS),
                       (char *)CONCAT22(FontMain.ofs,(*(uint16_t *)((uint8_t *)&(label) + 2))),
                       (char *)CONCAT22(0x45,FontMain.seg),3,cVar1,&text);
    ovr_blitText();
  }
  return;
}



/* 6018:0aac */

/* Draws menu entry `index` of a far-pointer table at x=0xeb and y=0x3c+index*0xe. */

void __cdecl16far ovc28_blitMenuEntry(far_t entries,int index)

{
  undefined2 *puVar1;
  
  if (index < 0xfa) {
    puVar1 = (undefined2 *)(entries.ofs + index * 4);
    ovc28_drawButton(0xeb,index * 0xe + 0x3c,(char *)CONCAT22(puVar1[1],(char *)*puVar1));
  }
  return;
}



/* 6018:0aef */

/* Initialises the cross-hair animation state from the current menu item. */

void __cdecl16far ovc28_startCrossBlit(void)

{
  far_t src;
  far_t gfx;
  uint type;
  uint16_t in_DX;
  int iVar1;
  uint16_t unaff_BP;
  int16_t in_stack_00000000;
  far_t handle;
  far_t dst;
  uint16_t unk;
  
  CrossBlitFlag = 0;
  CrossBlitCount2 = 0;
  CrossBlitCount = 1;
  if (GMenuItem == 0) {
    CrossBlitX = 3;
    CrossBlitY = 0xb0;
  }
  else if ((GMenuItem < 0x7f) || (menuBarShown == '\0')) {
    CrossBlitX = 0xe7;
    CrossBlitY = (uint)GMenuItem * 0xe + 0x2b;
    in_DX = 0x2410;
  }
  else {
    CrossBlitX = (GMenuItem - 0xfc) * 0x44 + 10;
    in_DX = 0x2410;
    CrossBlitY = 0xb0;
  }
  if (CrossBlitPtr.ofs != 0 || CrossBlitPtr.seg != 0) {
    handle.seg = unaff_BP;
    handle.ofs = CrossBlitPtr.seg;
    ovr_stshFree(handle,(char)CrossBlitPtr.ofs);
    unaff_BP = handle.seg;
  }
  src.seg = CrossBlitY;
  src.ofs = CrossBlitX;
  CrossBlitPtr.ofs =
       (uint16_t)
       ovr_stshRleCut((far_t *)0xa000,src,CrossBlitX + 0xd,CrossBlitY + 9,unaff_BP,in_stack_00000000
                      ,0,(char)(CrossBlitX + 0xd));
  dst.seg = unaff_BP;
  dst.ofs = 0xa000;
  iVar1 = CrossBlitX + CrossBlitY * 0x140;
  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)iVar1;
  gfx.ofs = CrossBlitGfx.seg;
  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)iVar1 >> 8);
  CrossBlitPtr.seg = in_DX;
  ovr_blitLoadRleGfx(gfx,dst,CrossBlitGfx.ofs);
  if (MouseMoved == 0) {
    unk = dst.seg;
    type = ovr_draw_compute3();
    ovr_play_sfxU(1,type,unk,0);
  }
  return;
}



/* 6018:0c76 */

/* [R6] touches ScreenMode, MouseMoved */

undefined2 __cdecl16far ovc28_usesScreenMode(far_t entries,uint count)

{
  undefined2 uVar1;
  uint uVar2;
  byte bVar3;
  undefined1 uVar4;
  int *piVar5;
  char cStack_8;
  char cStack_4;
  
  if ((((ScreenMode == '\0') && (MouseMoved == 0)) && (8 < MouseX)) &&
     (((MouseX < 0x19 && (0xb4 < MouseY)) && ((MouseY < 0xb6 | 0xeU) != 0)))) {
    uVar1 = 0;
  }
  else {
    if (((MouseMoved == 0) && (0xea < MouseX)) && ((0x3b < MouseY && (MouseX < 0x139)))) {
      uVar2 = (MouseY - 0x3c) / 0xe;
      if (((uVar2 < count) && ((MouseY - 0x3c) % 0xe < 0xc)) &&
         (piVar5 = (int *)(entries.ofs + uVar2 * 4), *piVar5 != 0 || piVar5[1] != 0)) {
        ovc28_blitMenuEntry(entries,uVar2);
        cStack_4 = (char)uVar2;
        GMenuItem = cStack_4 + '\x01';
        return CONCAT11(0x24,cStack_4 + '\x01');
      }
    }
    uVar4 = 0x24;
    if (((MouseMoved == 0) && (menuBarShown != '\0')) &&
       ((uVar4 = 0x24, 0xf < MouseX &&
        ((uVar4 = 0x24, 0xb2 < MouseY && (uVar4 = 0x24, MouseY < 0xbf)))))) {
      uVar2 = (MouseX - 0x10) / 0x44;
      uVar4 = (undefined1)((MouseX - 0x10) / 0x44 >> 8);
      if ((uVar2 < 3) && ((MouseX - 0x10) % 0x44 < 0x43)) {
        cStack_8 = (char)uVar2;
        GMenuItem = cStack_8 + -4;
        return CONCAT11(0x24,cStack_8 + -4);
      }
    }
    if (((((keyboardInputMode == '\0') || (uVar4 = 0x24, MouseMoved != 0)) ||
         (uVar4 = 0x24, MouseX < 0xc)) ||
        ((uVar4 = 0x24, 0xde < MouseX || (uVar4 = 0x24, MouseY < 7)))) ||
       (uVar4 = 0x24, 0x96 < MouseY)) {
      if (((keyboardInputMode == '\0') || (uVar4 = 0x24, MouseMoved != 0)) ||
         ((uVar4 = 0x24, MouseX < 0xef ||
          (((uVar4 = 0x24, 0x134 < MouseX || (uVar4 = 0x24, MouseY < 7)) ||
           (uVar4 = 0x24, 0x36 < MouseY)))))) {
        uVar1 = CONCAT11(uVar4,0xff);
      }
      else {
        ovc28_textHalflingCastle();
        bVar3 = (byte)(MouseX - 0xef >> 9);
        ovr_ovc13_usesBlitLoadRleGfx3();
        uVar1 = CONCAT11(bVar3,0xfe);
      }
    }
    else {
      ovc28_textHalflingCastle();
      bVar3 = (byte)(MouseX - 0xc >> 9);
      ovr_ovc13_usesBlitLoadRleGfx2();
      uVar1 = CONCAT11(bVar3,0xfe);
    }
  }
  return uVar1;
}



/* 6018:0f29 */

char * __cdecl16far uiInputText(far_t entries,uint16_t count,far_t hint,uint8_t flags,...)

{
  far_t entries_00;
  far_t entries_01;
  far_t entries_02;
  uint16_t count_00;
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar6;
  uint16_t uVar4;
  undefined2 uVar5;
  uint16_t unaff_SI;
  uint16_t in_stack_00000004;
  uint16_t in_stack_0000fffc;
  
  UserWantsExit = 0;
  if (count != 0 || hint.ofs != 0) {
    if (ScreenMode == '\0') {
      ovr_drawTextAt((char *)CONCAT22(0xa000,hint.ofs),unaff_SI,count);
    }
    else {
      ovr_drawString((char *)CONCAT22(unaff_SI,hint.ofs),in_stack_0000fffc,count);
    }
  }
  count_00 = entries.seg;
  entries_00.seg = entries.ofs;
  entries_00.ofs = in_stack_00000004;
  ovc28_usesBlitGfx10(entries_00,entries.seg);
  GMenuItem = 1;
  while (((int)(uint)GMenuItem <= (int)entries.seg &&
         (iVar2 = (uint)GMenuItem * 4 + in_stack_00000004,
         *(int *)(iVar2 + -4) == 0 && *(int *)(iVar2 + -2) == 0))) {
    GMenuItem = GMenuItem + 1;
  }
  uVar3 = (uint)GMenuItem;
  if ((int)entries.seg < (int)uVar3) {
    uVar3 = 0x2410;
    GMenuItem = 0;
  }
  uVar6 = (undefined1)(uVar3 >> 8);
  ovr_ovc40_flushInput();
  if (SfxPending != '\0') {
    ovr_play_sfx(0,unaff_SI,CONCAT11(uVar6,SfxPending));
    SfxPending = '\0';
  }
  GMenuFlag = 1;
L_uiInputText_1007:
  do {
    while( true ) {
      uVar4 = ovr_uiReadKey2();
      if (uVar4 != 0x4838) break;
L_uiInputText_110E:
      do {
        if (menuBarShown == '\0') {
          if (ScreenMode == '\0') {
            if (GMenuItem == 0) {
              GMenuItem = (byte)entries.seg;
            }
            else {
              GMenuItem = GMenuItem - 1;
            }
          }
          else if (GMenuItem < 2) {
            GMenuItem = (byte)entries.seg;
          }
          else {
            GMenuItem = GMenuItem - 1;
          }
        }
        else if (GMenuItem == 0xfc) {
          GMenuItem = (byte)entries.seg;
        }
        else if (GMenuItem < 2) {
          GMenuItem = 0xfe;
        }
        else {
          GMenuItem = GMenuItem - 1;
        }
      } while ((GMenuItem != 0) &&
              (iVar2 = (uint)GMenuItem * 4 + in_stack_00000004,
              *(int *)(iVar2 + -4) == 0 && *(int *)(iVar2 + -2) == 0));
      ovc28_startCrossBlit();
    }
    if (uVar4 < 0x4839) {
      if (uVar4 == 0x1675) {
L_uiInputText_10F1:
        if (menuBarShown != '\0') {
          GMenuFlag = 0;
          return (char *)"thief" + 4;
        }
        goto L_uiInputText_1007;
      }
      if (uVar4 < 0x1676) {
        if (uVar4 != 0x1372) {
          if (0x1372 < uVar4) {
            if (uVar4 == 0x1655) goto L_uiInputText_10F1;
            goto L_uiInputText_1007;
          }
          if (uVar4 == 0x11b) {
            UserWantsExit = 1;
            goto L_uiInputText_1348;
          }
          if (uVar4 != 0x1352) goto L_uiInputText_1007;
        }
        if (menuBarShown != '\0') {
          GMenuFlag = 0;
          return (char *)"thief" + 2;
        }
        goto L_uiInputText_1007;
      }
      if (uVar4 != 0x2368) {
        if (0x2368 < uVar4) {
          if (uVar4 == 0x4800) goto L_uiInputText_110E;
          goto L_uiInputText_1007;
        }
        if (uVar4 == 0x1c0d) {
          if (GMenuItem != 0) {
            entries_02.seg = entries.ofs;
            entries_02.ofs = in_stack_00000004;
            ovc28_blitMenuEntry(entries_02,GMenuItem - 1);
          }
          ovc28_usesBlitLoadRleGfx();
          GMenuFlag = 0;
          return (char *)CONCAT11(0x24,GMenuItem);
        }
        if (uVar4 != 0x2348) goto L_uiInputText_1007;
      }
      if (menuBarShown != '\0') {
        GMenuFlag = 0;
        return (char *)"thief" + 3;
      }
      goto L_uiInputText_1007;
    }
    if (uVar4 == 0x5100) {
L_uiInputText_1376:
      if ((far_to_u32(hint) & 0x20000) != 0) {
        GMenuFlag = 0;
        return (char *)CONCAT11(0x24,(byte)entries.seg);
      }
    }
    else if (uVar4 < 0x5101) {
      if (uVar4 == 0x5000) {
L_uiInputText_11EE:
        do {
          if (menuBarShown == '\0') {
            if (ScreenMode == '\0') {
              if ((int)(uint)GMenuItem < (int)count_00) {
                GMenuItem = GMenuItem + 1;
              }
              else {
                GMenuItem = 0;
              }
            }
            else if ((int)(uint)GMenuItem < (int)count_00) {
              GMenuItem = GMenuItem + 1;
            }
            else {
              GMenuItem = 1;
            }
          }
          else if (GMenuItem == 0xfe) {
            GMenuItem = 1;
          }
          else if (GMenuItem == count_00) {
            GMenuItem = 0xfc;
          }
          else {
            GMenuItem = GMenuItem + 1;
          }
        } while ((GMenuItem != 0) &&
                (iVar2 = (uint)GMenuItem * 4 + in_stack_00000004,
                *(int *)(iVar2 + -4) == 0 && *(int *)(iVar2 + -2) == 0));
        ovc28_startCrossBlit();
      }
      else if (uVar4 < 0x5001) {
        if (((uVar4 == 0x4900) || (uVar4 == 0x4939)) && ((far_to_u32(hint) & 0x10000) != 0)) {
          GMenuFlag = 0;
          return (char *)"arena" + 5;
        }
      }
      else if (uVar4 == 0x5032) goto L_uiInputText_11EE;
    }
    else {
      if (uVar4 == 0x5133) goto L_uiInputText_1376;
      if (uVar4 == 0xfffe) {
L_uiInputText_1348:
        ovc28_usesBlitLoadRleGfx();
        GMenuFlag = 0;
        return (char *)"arena" + 4;
      }
      if (uVar4 == 0xffff) {
        entries_01.seg = entries.ofs;
        entries_01.ofs = in_stack_00000004;
        uVar5 = ovc28_usesScreenMode(entries_01,count_00);
        cVar1 = (char)uVar5;
        if (cVar1 != -1) {
          ovc28_usesBlitLoadRleGfx();
          GMenuFlag = 0;
          return (char *)CONCAT11(0x24,cVar1);
        }
      }
    }
  } while( true );
}



/* 6018:1398 */

/* WARNING: Variable defined which should be unmapped: menuEntries */
/* [R4] calls uiInputText */

char * __cdecl16far
ovc28_usesUiInputText(far_t entries,uint16_t count,far_t hint,uint8_t *pageOut,...)

{
  undefined2 uVar1;
  char *pcVar2;
  int iVar3;
  undefined1 uVar6;
  undefined2 uVar4;
  uint uVar5;
  undefined2 *puVar7;
  uint uVar8;
  undefined2 unaff_SS;
  int in_stack_00000004;
  far_t entries_00;
  far_t hint_00;
  uint8_t menuEntries;
  undefined2 auStack_34 [17];
  undefined2 uStack_12;
  undefined2 uStack_10;
  uint16_t uStack_e;
  uint16_t uStack_c;
  char cStack_9;
  undefined1 uStack_8;
  byte bStack_7;
  byte bStack_6;
  byte bStack_5;
  byte bStack_4;
  char cStack_3;
  
  uStack_c = hint.ofs;
  uStack_e = count;
  if ((int)entries.seg < 10) {
    pcVar2 = uiInputText(entries,count,far_from_u32((uint32_t)(far_to_u32(hint) & 0xffff)),menuEntries,in_stack_00000004);
  }
  else {
    while( true ) {
      auStack_34[0] = 0x2410;
      menuEntries = 0x5db9;
      uStack_10 = 0x2410;
      uStack_12 = 0x5dc2;
      if (*(char *)CONCAT22((uint8_t *)pageOut,hint.seg) == '\0') {
        bStack_4 = 0;
        bStack_6 = 0;
        bStack_5 = 9;
        uStack_8 = 2;
        cStack_9 = '\n';
        uVar4 = 0;
      }
      else {
        iVar3 = (uint)*(byte *)CONCAT22((uint8_t *)pageOut,hint.seg) * 8 + 8;
        uVar6 = (undefined1)((uint)iVar3 >> 8);
        if (iVar3 < (int)entries.seg) {
          bStack_4 = 1;
          bStack_6 = *(char *)CONCAT22((uint8_t *)pageOut,hint.seg) * '\b' + 1;
          uVar4 = CONCAT11(uVar6,bStack_6);
          bStack_5 = 8;
          uStack_8 = 3;
          cStack_9 = '\n';
        }
        else {
          bStack_4 = 1;
          bStack_6 = *(char *)CONCAT22((uint8_t *)pageOut,hint.seg) * '\b' + 1;
          bStack_5 = (char)entries.seg - bStack_6;
          cStack_9 = bStack_5 + 1;
          uVar4 = CONCAT11(uVar6,cStack_9);
          uStack_8 = 1;
        }
      }
      for (bStack_7 = 0; bStack_7 < bStack_5; bStack_7 = bStack_7 + 1) {
        puVar7 = (undefined2 *)(in_stack_00000004 + ((uint)bStack_6 + (uint)bStack_7) * 4);
        uVar4 = puVar7[1];
        uVar1 = *puVar7;
        uVar8 = (uint)bStack_4;
        uVar5 = (uint)bStack_7;
        auStack_34[(uVar8 + uVar5) * 2] = uVar4;
        *(undefined2 *)(&menuEntries + (uVar8 + uVar5) * 4) = uVar1;
      }
      (*(uint8_t *)((uint8_t *)&(hint_00.seg) + 1)) = (char)((uint)uVar4 >> 8);
      (*(uint8_t *)((uint8_t *)&(hint_00.seg))) = uStack_8;
      hint_00.ofs = uStack_c;
      (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = cStack_9;
      entries_00.ofs = unaff_SS;
      (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = 0;
      pcVar2 = uiInputText(entries_00,uStack_e,hint_00,menuEntries,&menuEntries);
      cStack_3 = (char)pcVar2;
      if (cStack_3 == '\0') {
        return (char *)0;
      }
      if (cStack_3 == -2) {
        return (char *)0xfe;
      }
      if ((bStack_4 + 1 <= ((uint)pcVar2 & 0xff)) &&
         (uVar5 = (uint)bStack_4 + (uint)bStack_5 + 1, ((uint)pcVar2 & 0xff) < uVar5)) break;
      if (cStack_3 == '\x01') {
        *(char *)CONCAT22((uint8_t *)pageOut,hint.seg) =
             *(char *)CONCAT22((uint8_t *)pageOut,hint.seg) + -1;
      }
      else {
        *(char *)CONCAT22((uint8_t *)pageOut,hint.seg) =
             *(char *)CONCAT22((uint8_t *)pageOut,hint.seg) + '\x01';
      }
    }
    pcVar2 = (char *)CONCAT11((char)(uVar5 >> 8),(bStack_6 + cStack_3) - bStack_4);
  }
  return pcVar2;
}



/* 6018:1527 */

/* [R7] body shape: compute */

void __cdecl16far ovc28_compute2(far_t entries,uint16_t count,far_t hint,...)

{
  undefined2 unaff_SS;
  undefined2 in_stack_00000004;
  far_t hint_00;
  undefined3 in_stack_0000fffa;
  
  hint_00.seg = (uint16_t)&stack0xfffd;
  hint_00.ofs = hint.ofs;
  ovc28_usesUiInputText
            (entries,count,hint_00,
             (uint8_t *)(ulong)CONCAT12((char)((uint3)in_stack_0000fffa >> 0x10),unaff_SS),
             in_stack_00000004);
  return;
}


