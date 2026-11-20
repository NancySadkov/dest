/*
 * ovc28.c - recovered from STRONG.EXE
 * memory block: OVC28
 * range: 6018:0000 - 6018:177f
 * functions: 16
 */
#include "recovered.h"


/* 6018:0000 */

/* [R6] touches BDA_DailyTimeCounter */

void __cdecl16far ovc28_usesBDADailyTimeCounter(int ticks)

{
  int iVar1;
  
  do {
    iVar1 = ticks + -1;
    if (ticks == 0) {
      return;
    }
    do {
      ticks = iVar1;
      if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != *(int *)(BDA_DailyTimeCounter.ofs + 2)) break;
    } while (*(int *)BDA_DailyTimeCounter == *(int *)BDA_DailyTimeCounter);
  } while( true );
}



/* 6018:0048 */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far ovc28_usesBlitLoadRleGfx(void)

{
  far_t gfx;
  
  if (ScreenMode == '\0') {
    ovr_ovc18_blitPanelIfNotRunning();
    gfx.seg = FontHandle.seg;
    gfx.ofs = FontHandle.ofs;
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)));
  }
  return;
}



/* 6018:007e */

void __cdecl16far update_pause_button(void)

{
  bool bVar1;
  far_t gfx;
  far_t gfx_00;
  
  TextBlitDstSeg = 0xa000;
  if ((GPaused != '\0') && ((bVar1 = ovr_ovc15_usesAlignUp42(), !bVar1 || (GOngoingBattle != '\0')))
     ) {
    gfx_00.seg = butt01Cut2Seg;
    gfx_00.ofs = butt01Cut2Ofs;
    ovr_blitGfxRect(gfx_00,235,116,(brect_t *)(BlitRects + 1),0x10,true);
    TextBlitY = 0x76;
    TextBlitX = 0xf1;
    ovr_blitLabel((char *)"Resume",(uint8_t *)((char *)"puppetmaker" + 3),FontMain.ofs,
                  (uint8_t)FontMain.seg);
    return;
  }
  gfx.seg = butt01Cut1Seg;
  gfx.ofs = butt01Cut1Ofs;
  ovr_blitGfxRect(gfx,235,116,(brect_t *)(BlitRects + 1),0x10,true);
  TextBlitY = 0x76;
  TextBlitX = 0xf0;
  ovr_blitLabel((char *)"Pause",(uint8_t *)((char *)"puppetmaker" + 3),Font01.ofs,
                (uint8_t)Font01.seg);
  return;
}



/* 6018:0176 */

/* Blits the button1Cut3 toolbar button at (223,8) and updates the daily-time counter. */

void __cdecl16far ovc28_blitButton(void)

{
  far_t gfx;
  
  gfx.seg = button1Cut3Seg;
  gfx.ofs = button1Cut3Ofs;
  ovr_blitGfxRect(gfx,223,8,(brect_t *)(BlitRects + 1),0x10,true);
  ovc28_usesBDADailyTimeCounter(3);
  ovc28_usesBlitGfxRect2();
  return;
}



/* 6018:01af */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc28_usesBlitGfxRect2(void)

{
  char *pcVar1;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  
  pcVar1 = ovr_draw_textArena();
  if ((((uint)pcVar1 & 0xff) == 0) || (GameRunning != false)) {
    gfx.seg = button1Cut3Seg;
    gfx.ofs = button1Cut3Ofs;
    ovr_blitGfxRect(gfx,223,8,(brect_t *)(BlitRects + 1),0x10,true);
  }
  else if (GOngoingBattle == '\0') {
    gfx_00.seg = button1Cut1Seg;
    gfx_00.ofs = button1Cut1Ofs;
    ovr_blitGfxRect(gfx_00,223,8,(brect_t *)(BlitRects + 1),0x10,true);
  }
  else {
    gfx_01.seg = button1Cut2Seg;
    gfx_01.ofs = button1Cut2Ofs;
    ovr_blitGfxRect(gfx_01,223,8,(brect_t *)(BlitRects + 1),0x10,true);
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
  undefined2 *puVar2;
  char *text_00;
  byte *widths;
  int iVar3;
  char *unaff_SS;
  far_t gfx_01;
  uint16_t seg;
  uint8_t term;
  uint8_t msg;
  uint8_t text;
  undefined1 uStack_4;
  byte bStack_3;
  
  ovr_ovc18_blitPanelIfNotRunning();
  gfx_01.seg = fullScreenGfxSeg;
  gfx_01.ofs = fullScreenGfxOfs;
  ovr_blitGfx10(gfx_01,0,0,(brect_t *)0x24105ce5,false);
  if (GameRunning == false) {
    (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)panel01Cut2Seg;
    gfx.ofs = panel01Cut2Ofs;
    (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)panel01Cut2Seg >> 8);
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa0008fa4)));
    (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)trianglsCut5Seg;
    gfx_00.ofs = trianglsCut5Ofs;
    (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)trianglsCut5Seg >> 8);
    ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa000e249)));
    for (iVar3 = 0; iVar3 < 5; iVar3 = iVar3 + 1) {
      if (((uint8_t *)MenuItemEnabled)[iVar3] != 0xff) {
        TextBlitX = 0xea;
        TextBlitY = iVar3 * 0xd + 0x87;
        uVar1 = *(undefined4 *)((uint)((uint8_t *)MenuItemEnabled)[iVar3] << 2);
        bStack_3 = *(byte *)((int)uVar1 + 0x2f);
        if (bStack_3 == 0xff) {
          uStack_4 = 0x46;
        }
        else {
          uStack_4 = *(undefined1 *)*(undefined4 *)((uint)bStack_3 * 4 + 0xeb);
        }
        term = (uint8_t)Font03.seg;
        puVar2 = (undefined2 *)((uint)((uint8_t *)MenuItemEnabled)[iVar3] * 4);
        widths = (byte *)((char *)"halfling castle" + 0xc);
        seg = Font03.ofs;
        ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text),
                           (char *)CONCAT22(puVar2[1],(char *)*puVar2),
                           (char *)CONCAT22(Font03.seg,Font03.ofs),0x2a,'\x03');
        text_00 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s-%c");
        ovr_blitText(text_00,widths,seg,term);
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
  
  bVar1 = ovr_ovc15_usesAlignUp42();
  if ((bVar1) && (GOngoingBattle == '\0')) {
    ovr_drawTextAt((char *)"Sorry, you may not pause during a battle.",0x2410);
    GPaused = '\0';
  }
  else {
    GPaused = '\x01' - (GPaused != '\0');
    if (GPaused == '\0') {
      ovr_drawTextAt((char *)"Resume. Game events will now occur normally.",0x2410);
    }
    else {
      ovr_drawTextAt((char *)
                     "Pause. Select \'Resume\' to enable game events. Press SPACE for a single game event."
                     ,0x2410);
    }
    update_pause_button();
  }
  return;
}



/* 6018:0456 */

/* [R4] calls ovr_blitGfx10 */

void __cdecl16far ovc28_usesBlitGfx10(far_t entries,int count)

{
  undefined2 uVar1;
  far_t gfx;
  far_t gfx_00;
  far_t dst;
  char *pcVar2;
  uint8_t *widths;
  uint16_t uVar3;
  int *piVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  uint16_t uVar8;
  undefined2 unaff_SS;
  uint8_t term;
  uint8_t text;
  int iStack_8;
  undefined4 uStack_6;
  
  gfx.seg = fullScreenGfxSeg;
  gfx.ofs = fullScreenGfxOfs;
  ovr_blitGfx10(gfx,0,0,(brect_t *)0x24105ce5,false);
  iStack_8 = 0xeb;
  iVar7 = 0x3c;
  for (iVar6 = 0; iVar6 < count; iVar6 = iVar6 + 1) {
    uVar8 = entries.seg;
    uVar3 = entries.ofs;
    piVar4 = (int *)(uVar3 + iVar6 * 4);
    if (*piVar4 != 0 || piVar4[1] != 0) {
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)butt01Cut5Seg;
      gfx_00.ofs = butt01Cut5Ofs;
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)butt01Cut5Seg >> 8);
      (*(uint8_t *)((uint8_t *)&(dst.seg))) = 0;
      dst.ofs = iStack_8 + iVar7 * 0x140;
      (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = 0xa0;
      ovr_blitLoadRleGfx(gfx_00,dst);
      TextBlitDstSeg = 0xa000;
      TextBlitX = iStack_8 + 6;
      TextBlitY = iVar7 + 2;
      puVar5 = (undefined2 *)(uVar3 + iVar6 * 4);
      uVar1 = puVar5[1];
      widths = (uint8_t *)*puVar5;
      uStack_6 = (uint8_t *)CONCAT22(uVar1,widths);
      term = (uint8_t)FontMain.seg;
      if (*uStack_6 == 0x25) {
        BlitLetterType = 2;
        uVar3 = FontMain.ofs;
        pcVar2 = (char *)ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text),
                                            (char *)CONCAT22(uVar1,widths + 1),
                                            (char *)CONCAT22(FontMain.seg,FontMain.ofs),0x45,'\x03')
        ;
        ovr_blitLabel(pcVar2,widths,uVar3,term);
        BlitLetterType = 0;
      }
      else if (*uStack_6 == 0x40) {
        uVar3 = FontMain.ofs;
        pcVar2 = (char *)ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text),
                                            (char *)CONCAT22(uVar1,widths + 1),
                                            (char *)CONCAT22(FontMain.seg,FontMain.ofs),0x45,'\x03')
        ;
        ovr_blitLabel(pcVar2,widths,uVar3,term);
      }
      else {
        puVar5 = (undefined2 *)(uVar3 + iVar6 * 4);
        uVar3 = FontMain.ofs;
        pcVar2 = (char *)ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text),
                                            (char *)CONCAT22(puVar5[1],(char *)*puVar5),
                                            (char *)CONCAT22(FontMain.seg,FontMain.ofs),0x45,'\x03')
        ;
        ovr_blitLabel(pcVar2,widths,uVar3,term);
      }
    }
    iVar7 = iVar7 + 0xe;
  }
  if (goldPartyIndex != 0xff) {
    ovc28_drawGold(goldPartyIndex);
  }
  return;
}



/* 6018:0634 */

/* Draws the "Gold" label and the party's gold amount. */

void __cdecl16far ovc28_drawGold(byte partyIndex)

{
  uint uVar1;
  char *text;
  uint16_t uVar2;
  byte *widths;
  int iVar3;
  undefined2 uVar4;
  byte *unaff_SS;
  undefined4 uVar5;
  uint8_t numText;
  
  uVar1 = ovr_font_textWidth("Gold",(char *)CONCAT22(Font03.seg,Font03.ofs));
  TextBlitX = 0x10e - (uVar1 >> 1);
  TextBlitY = 0x9c;
  ovr_blitText((char *)"Gold",(byte *)((char *)"puppetmaker" + 3),Font03.ofs,(uint8_t)Font03.seg);
  uVar4 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
  iVar3 = (int)*(undefined4 *)((uint)partyIndex << 2);
  ovr_litoa10((char *)&numText,CONCAT22(*(undefined2 *)(iVar3 + 0x58),*(undefined2 *)(iVar3 + 0x56))
             );
  uVar1 = ovr_font_textWidth((char *)CONCAT22(unaff_SS,&numText),
                             (char *)CONCAT22(Font03.seg,Font03.ofs));
  uVar2 = 0x10e - (uVar1 >> 1);
  TextBlitY = 0xa7;
  TextBlitX = uVar2;
  ovr_blitText((char *)&numText,unaff_SS,Font03.ofs,(uint8_t)Font03.seg);
  iVar3 = ovr_ovc45_usesLDIV_at_(partyIndex);
  if (iVar3 != 0 || uVar2 != 0) {
    uVar1 = ovr_font_textWidth("Fund",(char *)CONCAT22(Font03.seg,Font03.ofs));
    uVar2 = 0x10e - (uVar1 >> 1);
    TextBlitY = 0xb2;
    TextBlitX = uVar2;
    ovr_blitText((char *)"Fund",(byte *)((char *)"puppetmaker" + 3),Font03.ofs,(uint8_t)Font03.seg);
    uVar4 = ovr_ovc45_usesLDIV_at_(partyIndex);
    ovr_litoa10((char *)&numText,CONCAT22(uVar2,uVar4));
    uVar1 = ovr_font_textWidth((char *)CONCAT22(unaff_SS,&numText),
                               (char *)CONCAT22(Font03.seg,Font03.ofs));
    widths = (byte *)(0x10e - (uVar1 >> 1));
    TextBlitY = 0xbd;
    uVar5 = CONCAT22(Font03.seg,Font03.ofs);
    TextBlitX = (uint16_t)widths;
    uVar4 = ovr_ovc45_usesLDIV_at_(partyIndex);
    text = ovr_litoa10((char *)&numText,CONCAT22(widths,uVar4));
    ovr_blitText(text,widths,(uint16_t)uVar5,(uint8_t)((ulong)uVar5 >> 0x10));
  }
  return;
}



/* 6018:0813 */

/* Draws a butt01Cut6 button at (x,y) and its label. */

void __cdecl16far ovc28_drawButton(int x,int y,char *label)

{
  char *pcVar1;
  byte *pbVar2;
  undefined2 unaff_SS;
  undefined2 in_stack_0000000a;
  far_t gfx;
  undefined4 uVar3;
  far_t gfx_00;
  far_t dst;
  far_t dst_00;
  uint8_t text;
  
  dst.seg = 0xa000;
  dst.ofs = x + y * 0x140;
  gfx.seg = butt01Cut6Seg;
  gfx.ofs = butt01Cut6Ofs;
  ovr_blitLoadRleGfx(gfx,dst);
  TextBlitX = x + 6;
  TextBlitY = y + 2;
  pbVar2 = (byte *)((char *)"puppetmaker" + 3);
  if (*_label == '%') {
    BlitLetterType = 2;
    uVar3 = CONCAT22(Font01.seg,Font01.ofs);
    pcVar1 = (char *)ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text),
                                        (char *)CONCAT22(in_stack_0000000a,label + 1),
                                        (char *)CONCAT22(Font01.seg,Font01.ofs),0x45,'\x03');
    ovr_blitLabel(pcVar1,pbVar2,(int16_t)uVar3,(uint8_t)((ulong)uVar3 >> 0x10));
    BlitLetterType = 0;
  }
  else if (*_label == '@') {
    uVar3 = CONCAT22(Font01.seg,Font01.ofs);
    pcVar1 = (char *)ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text),
                                        (char *)CONCAT22(in_stack_0000000a,label + 1),
                                        (char *)CONCAT22(Font01.seg,Font01.ofs),0x45,'\x03');
    ovr_blitLabel(pcVar1,pbVar2,(int16_t)uVar3,(uint8_t)((ulong)uVar3 >> 0x10));
  }
  else {
    uVar3 = CONCAT22(Font01.seg,Font01.ofs);
    pcVar1 = (char *)ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text),
                                        (char *)CONCAT22(in_stack_0000000a,label),
                                        (char *)CONCAT22(FontMain.seg,FontMain.ofs),0x45,'\x03');
    ovr_blitText(pcVar1,pbVar2,(uint16_t)uVar3,(uint8_t)((ulong)uVar3 >> 0x10));
  }
  ovc28_usesBDADailyTimeCounter(3);
  dst_00.seg = 0xa000;
  dst_00.ofs = x + y * 0x140;
  gfx_00.seg = butt01Cut5Seg;
  gfx_00.ofs = butt01Cut5Ofs;
  ovr_blitLoadRleGfx(gfx_00,dst_00);
  TextBlitX = x + 6;
  TextBlitY = y + 2;
  pbVar2 = (byte *)((char *)"puppetmaker" + 3);
  if (*_label == '%') {
    BlitLetterType = 2;
    uVar3 = CONCAT22(FontMain.seg,FontMain.ofs);
    pcVar1 = (char *)ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text),
                                        (char *)CONCAT22(in_stack_0000000a,label + 1),
                                        (char *)CONCAT22(FontMain.seg,FontMain.ofs),0x45,'\x03');
    ovr_blitLabel(pcVar1,pbVar2,(int16_t)uVar3,(uint8_t)((ulong)uVar3 >> 0x10));
    BlitLetterType = 0;
  }
  else if (*_label == '@') {
    uVar3 = CONCAT22(FontMain.seg,FontMain.ofs);
    pcVar1 = (char *)ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text),
                                        (char *)CONCAT22(in_stack_0000000a,label + 1),
                                        (char *)CONCAT22(FontMain.seg,FontMain.ofs),0x45,'\x03');
    ovr_blitLabel(pcVar1,pbVar2,(int16_t)uVar3,(uint8_t)((ulong)uVar3 >> 0x10));
  }
  else {
    uVar3 = CONCAT22(FontMain.seg,FontMain.ofs);
    pcVar1 = (char *)ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&text),
                                        (char *)CONCAT22(in_stack_0000000a,label),
                                        (char *)CONCAT22(FontMain.seg,FontMain.ofs),0x45,'\x03');
    ovr_blitText(pcVar1,pbVar2,(uint16_t)uVar3,(uint8_t)((ulong)uVar3 >> 0x10));
  }
  return;
}



/* 6018:0aac */

/* Draws menu entry `index` of a far-pointer table at x=0xeb and y=0x3c+index*0xe. */

void __cdecl16far ovc28_blitMenuEntry(far_t entries,int index)

{
  if (index < 0xfa) {
    ovc28_drawButton(0xeb,index * 0xe + 0x3c,(char *)*(undefined2 *)(entries.ofs + index * 4));
  }
  return;
}



/* 6018:0aef */

/* Initialises the cross-hair animation state from the current menu item. */

void __cdecl16far ovc28_startCrossBlit(void)

{
  far_t src;
  far_t gfx;
  uint unk;
  uint16_t in_DX;
  int16_t unaff_BP;
  far_t handle;
  far_t dst;
  
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
    handle.seg = CrossBlitPtr.seg;
    handle.ofs = CrossBlitPtr.ofs;
    ovr_stshFree(handle);
  }
  src.seg = CrossBlitX;
  src.ofs = 0xa000;
  CrossBlitPtr.ofs =
       (uint16_t)
       ovr_stshRleCut((far_t *)0x0,src,CrossBlitY,CrossBlitX + 0xd,CrossBlitY + 9,unaff_BP);
  dst.seg = 0xa000;
  dst.ofs = CrossBlitX + CrossBlitY * 0x140;
  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)CrossBlitGfx.seg;
  gfx.ofs = CrossBlitGfx.ofs;
  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)(CrossBlitGfx.seg >> 8);
  CrossBlitPtr.seg = in_DX;
  ovr_blitLoadRleGfx(gfx,dst);
  if (MouseMoved == 0) {
    unk = ovr_draw_compute3(CrossBlitX);
    ovr_play_sfxU(0,1,unk);
  }
  return;
}



/* 6018:0c76 */

/* [R6] touches ScreenMode, MouseMoved */

undefined2 __cdecl16far ovc28_usesScreenMode(far_t entries,uint count)

{
  undefined2 uVar1;
  uint uVar2;
  undefined1 uVar3;
  int *piVar4;
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
         (piVar4 = (int *)(entries.ofs + uVar2 * 4), *piVar4 != 0 || piVar4[1] != 0)) {
        ovc28_blitMenuEntry(entries,uVar2);
        cStack_4 = (char)uVar2;
        GMenuItem = cStack_4 + '\x01';
        return CONCAT11(0x24,cStack_4 + '\x01');
      }
    }
    uVar3 = 0x24;
    if (((MouseMoved == 0) && (menuBarShown != '\0')) &&
       ((uVar3 = 0x24, 0xf < MouseX &&
        ((uVar3 = 0x24, 0xb2 < MouseY && (uVar3 = 0x24, MouseY < 0xbf)))))) {
      uVar2 = (MouseX - 0x10) / 0x44;
      uVar3 = (undefined1)((MouseX - 0x10) / 0x44 >> 8);
      if ((uVar2 < 3) && ((MouseX - 0x10) % 0x44 < 0x43)) {
        cStack_8 = (char)uVar2;
        GMenuItem = cStack_8 + -4;
        return CONCAT11(0x24,cStack_8 + -4);
      }
    }
    if (((((keyboardInputMode == '\0') || (uVar3 = 0x24, MouseMoved != 0)) ||
         (uVar3 = 0x24, MouseX < 0xc)) ||
        ((uVar3 = 0x24, 0xde < MouseX || (uVar3 = 0x24, MouseY < 7)))) ||
       (uVar3 = 0x24, 0x96 < MouseY)) {
      if (((keyboardInputMode == '\0') || (uVar3 = 0x24, MouseMoved != 0)) ||
         ((uVar3 = 0x24, MouseX < 0xef ||
          (((uVar3 = 0x24, 0x134 < MouseX || (uVar3 = 0x24, MouseY < 7)) ||
           (uVar3 = 0x24, 0x36 < MouseY)))))) {
        uVar1 = CONCAT11(uVar3,0xff);
      }
      else {
        ovc28_textHalflingCastle();
        uVar2 = MouseX - 0xef >> 1;
        ovr_ovc13_usesBlitLoadRleGfx3(uVar2,MouseY - 7,'\x01');
        uVar1 = CONCAT11((char)(uVar2 >> 8),0xfe);
      }
    }
    else {
      ovc28_textHalflingCastle();
      uVar2 = MouseX - 0xc >> 1;
      ovr_ovc13_usesBlitLoadRleGfx2(uVar2,MouseY - 7,'\x01');
      uVar1 = CONCAT11((char)(uVar2 >> 8),0xfe);
    }
  }
  return uVar1;
}



/* 6018:0f29 */

char * __cdecl16far uiInputText(far_t entries,uint16_t count,far_t hint,uint8_t flags)

{
  int iVar1;
  uint uVar2;
  undefined1 uVar5;
  uint16_t uVar3;
  undefined2 uVar4;
  
  UserWantsExit = 0;
  if (hint.ofs != 0 || hint.seg != 0) {
    if (ScreenMode == '\0') {
      ovr_drawTextAt((char *)hint.ofs,hint.seg);
    }
    else {
      ovr_drawString((char *)hint.ofs,hint.seg);
    }
  }
  ovc28_usesBlitGfx10(entries,count);
  GMenuItem = 1;
  while (((int)(uint)GMenuItem <= (int)count &&
         (iVar1 = (uint)GMenuItem * 4 + entries.ofs,
         *(int *)(iVar1 + -4) == 0 && *(int *)(iVar1 + -2) == 0))) {
    GMenuItem = GMenuItem + 1;
  }
  uVar2 = (uint)GMenuItem;
  if ((int)count < (int)uVar2) {
    uVar2 = 0x2410;
    GMenuItem = 0;
  }
  uVar5 = (undefined1)(uVar2 >> 8);
  ovr_ovc40_flushInput();
  if (SfxPending != '\0') {
    ovr_play_sfx(CONCAT11(uVar5,SfxPending),0);
    SfxPending = '\0';
  }
  GMenuFlag = 1;
L_uiInputText_1007:
  do {
    while( true ) {
      uVar3 = ovr_uiReadKey2();
      if (uVar3 != 0x4838) break;
L_uiInputText_110E:
      do {
        if (menuBarShown == '\0') {
          if (ScreenMode == '\0') {
            if (GMenuItem == 0) {
              GMenuItem = (byte)count;
            }
            else {
              GMenuItem = GMenuItem - 1;
            }
          }
          else if (GMenuItem < 2) {
            GMenuItem = (byte)count;
          }
          else {
            GMenuItem = GMenuItem - 1;
          }
        }
        else if (GMenuItem == 0xfc) {
          GMenuItem = (byte)count;
        }
        else if (GMenuItem < 2) {
          GMenuItem = 0xfe;
        }
        else {
          GMenuItem = GMenuItem - 1;
        }
      } while ((GMenuItem != 0) &&
              (iVar1 = (uint)GMenuItem * 4 + entries.ofs,
              *(int *)(iVar1 + -4) == 0 && *(int *)(iVar1 + -2) == 0));
      ovc28_startCrossBlit();
    }
    if (uVar3 < 0x4839) {
      if (uVar3 == 0x1675) {
L_uiInputText_10F1:
        if (menuBarShown != '\0') {
          GMenuFlag = 0;
          return (char *)"thief" + 4;
        }
        goto L_uiInputText_1007;
      }
      if (uVar3 < 0x1676) {
        if (uVar3 != 0x1372) {
          if (0x1372 < uVar3) {
            if (uVar3 == 0x1655) goto L_uiInputText_10F1;
            goto L_uiInputText_1007;
          }
          if (uVar3 == 0x11b) {
            UserWantsExit = 1;
            goto L_uiInputText_1348;
          }
          if (uVar3 != 0x1352) goto L_uiInputText_1007;
        }
        if (menuBarShown != '\0') {
          GMenuFlag = 0;
          return (char *)"thief" + 2;
        }
        goto L_uiInputText_1007;
      }
      if (uVar3 != 0x2368) {
        if (0x2368 < uVar3) {
          if (uVar3 == 0x4800) goto L_uiInputText_110E;
          goto L_uiInputText_1007;
        }
        if (uVar3 == 0x1c0d) {
          if (GMenuItem != 0) {
            ovc28_blitMenuEntry(entries,GMenuItem - 1);
          }
          ovc28_usesBlitLoadRleGfx();
          GMenuFlag = 0;
          return (char *)CONCAT11(0x24,GMenuItem);
        }
        if (uVar3 != 0x2348) goto L_uiInputText_1007;
      }
      if (menuBarShown != '\0') {
        GMenuFlag = 0;
        return (char *)"thief" + 3;
      }
      goto L_uiInputText_1007;
    }
    if (uVar3 == 0x5100) {
L_uiInputText_1376:
      if ((flags & 2) != 0) {
        GMenuFlag = 0;
        return (char *)CONCAT11(0x24,(byte)count);
      }
    }
    else if (uVar3 < 0x5101) {
      if (uVar3 == 0x5000) {
L_uiInputText_11EE:
        do {
          if (menuBarShown == '\0') {
            if (ScreenMode == '\0') {
              if ((int)(uint)GMenuItem < (int)count) {
                GMenuItem = GMenuItem + 1;
              }
              else {
                GMenuItem = 0;
              }
            }
            else if ((int)(uint)GMenuItem < (int)count) {
              GMenuItem = GMenuItem + 1;
            }
            else {
              GMenuItem = 1;
            }
          }
          else if (GMenuItem == 0xfe) {
            GMenuItem = 1;
          }
          else if (GMenuItem == count) {
            GMenuItem = 0xfc;
          }
          else {
            GMenuItem = GMenuItem + 1;
          }
        } while ((GMenuItem != 0) &&
                (iVar1 = (uint)GMenuItem * 4 + entries.ofs,
                *(int *)(iVar1 + -4) == 0 && *(int *)(iVar1 + -2) == 0));
        ovc28_startCrossBlit();
      }
      else if (uVar3 < 0x5001) {
        if (((uVar3 == 0x4900) || (uVar3 == 0x4939)) && ((flags & 1) != 0)) {
          GMenuFlag = 0;
          return (char *)"arena" + 5;
        }
      }
      else if (uVar3 == 0x5032) goto L_uiInputText_11EE;
    }
    else {
      if (uVar3 == 0x5133) goto L_uiInputText_1376;
      if (uVar3 == 0xfffe) {
L_uiInputText_1348:
        ovc28_usesBlitLoadRleGfx();
        GMenuFlag = 0;
        return (char *)"arena" + 4;
      }
      if (uVar3 == 0xffff) {
        uVar4 = ovc28_usesScreenMode(entries,count);
        if ((char)uVar4 != -1) {
          ovc28_usesBlitLoadRleGfx();
          GMenuFlag = 0;
          return (char *)CONCAT11(0x24,(char)uVar4);
        }
      }
    }
  } while( true );
}



/* 6018:1398 */

/* [R4] calls uiInputText */

char * __cdecl16far
ovc28_usesUiInputText(far_t entries,uint16_t count,far_t hint,uint8_t *pageOut,uint16_t pageOutSeg)

{
  undefined2 uVar1;
  char *pcVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint16_t unaff_SS;
  far_t entries_00;
  far_t hint_00;
  uint8_t menuEntries;
  undefined2 auStack_34 [17];
  undefined2 uStack_12;
  undefined2 uStack_10;
  uint16_t uStack_e;
  uint16_t uStack_c;
  byte bStack_9;
  uint8_t uStack_8;
  byte bStack_7;
  byte bStack_6;
  byte bStack_5;
  byte bStack_4;
  char cStack_3;
  
  uStack_c = hint.seg;
  uStack_e = hint.ofs;
  if ((int)count < 10) {
    pcVar2 = uiInputText(entries,count,hint,0x0);
  }
  else {
    while( true ) {
      auStack_34[0] = 0x2410;
      _menuEntries = 0x5db9;
      uStack_10 = 0x2410;
      uStack_12 = 0x5dc2;
      if (*_pageOut == 0) {
        bStack_4 = 0;
        bStack_6 = 0;
        bStack_5 = 9;
        uStack_8 = 0x2;
        bStack_9 = 10;
      }
      else if ((int)((uint)*_pageOut * 8 + 8) < (int)count) {
        bStack_4 = 1;
        bStack_6 = *_pageOut * '\b' + 1;
        bStack_5 = 8;
        uStack_8 = 0x3;
        bStack_9 = 10;
      }
      else {
        bStack_4 = 1;
        bStack_6 = *_pageOut * '\b' + 1;
        bStack_5 = (char)count - bStack_6;
        bStack_9 = bStack_5 + 1;
        uStack_8 = 0x1;
      }
      for (bStack_7 = 0; bStack_7 < bStack_5; bStack_7 = bStack_7 + 1) {
        puVar4 = (undefined2 *)(entries.ofs + ((uint)bStack_6 + (uint)bStack_7) * 4);
        uVar1 = *puVar4;
        uVar5 = (uint)bStack_4;
        uVar3 = (uint)bStack_7;
        auStack_34[(uVar5 + uVar3) * 2] = puVar4[1];
        *(undefined2 *)(&menuEntries + (uVar5 + uVar3) * 4) = uVar1;
      }
      hint_00.seg = uStack_c;
      hint_00.ofs = uStack_e;
      entries_00.seg = unaff_SS;
      entries_00.ofs = (uint16_t)&menuEntries;
      pcVar2 = uiInputText(entries_00,(uint)bStack_9,hint_00,uStack_8);
      cStack_3 = (char)pcVar2;
      if (cStack_3 == '\0') {
        return (char *)0;
      }
      if (cStack_3 == -2) {
        return (char *)0xfe;
      }
      if ((bStack_4 + 1 <= ((uint)pcVar2 & 0xff)) &&
         (uVar3 = (uint)bStack_4 + (uint)bStack_5 + 1, ((uint)pcVar2 & 0xff) < uVar3)) break;
      if (cStack_3 == '\x01') {
        *_pageOut = *_pageOut - 1;
      }
      else {
        *_pageOut = *_pageOut + 1;
      }
    }
    pcVar2 = (char *)CONCAT11((char)(uVar3 >> 8),(bStack_6 + cStack_3) - bStack_4);
  }
  return pcVar2;
}



/* 6018:1527 */

/* [R7] body shape: compute */

void __cdecl16far ovc28_compute2(far_t entries,uint16_t count,far_t hint)

{
  uint16_t unaff_SS;
  uint8_t uStack_3;
  
  uStack_3 = 0x0;
  ovc28_usesUiInputText(entries,count,hint,&uStack_3,unaff_SS);
  return;
}


