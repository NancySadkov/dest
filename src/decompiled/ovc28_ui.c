/*
 * ovc28_ui.c - recovered from STRONG.EXE
 * memory block: OVC28_ui.c
 * range: 6018:0000 - 6018:177f
 * functions: 16
 */
#include "recovered.h"


/* 6018:0000 */
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
      if (*(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2)) break;
    } while (*(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */ == *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */);
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
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)),0);
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
    ovr_blitGfxRect(gfx_00,235,116,(brect_t *)(BlitRects + 1),0x10,true,0,0,0,0,0,0);
    TextBlitY = 0x76;
    TextBlitX = 0xf1;
    ovr_blitLabel((char *)"Resume",(uint8_t *)CONCAT22(FontMain.ofs,(char *)0x26510),
                  FontMain.seg,0x3f,0xe0);
    return;
  }
  gfx.seg = butt01Cut1Seg;
  gfx.ofs = butt01Cut1Ofs;
  ovr_blitGfxRect(gfx,235,116,(brect_t *)(BlitRects + 1),0x10,true,0,0,0,0,0,0);
  TextBlitY = 0x76;
  TextBlitX = 0xf0;
  ovr_blitLabel((char *)"Pause",(uint8_t *)CONCAT22(Font01.ofs,(char *)0x26510),Font01.seg
                ,0x3f,0xe0);
  return;
}



/* 6018:0176 */

/* Blits the button1Cut3 toolbar button at (223,8) and updates the daily-time counter. */

void __cdecl16far ovc28_blitButton(void)

{
  far_t gfx;
  
  gfx.seg = button1Cut3Seg;
  gfx.ofs = button1Cut3Ofs;
  ovr_blitGfxRect(gfx,223,8,(brect_t *)(BlitRects + 1),0x10,true,0,0,0,0,0,0);
  ovc28_usesBDADailyTimeCounter(3);
  ovc28_usesBlitGfxRect2();
  return;
}



/* 6018:01af */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc28_usesBlitGfxRect2(void)

{
  bool bVar1;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  
  bVar1 = ovr_draw_textArena();
  if ((bVar1) && (GameRunning == false)) {
    if (GOngoingBattle == '\0') {
      gfx_00.seg = button1Cut1Seg;
      gfx_00.ofs = button1Cut1Ofs;
      ovr_blitGfxRect(gfx_00,223,8,(brect_t *)(BlitRects + 1),0x10,true,0,0,0,0,0,0);
    }
    else {
      gfx_01.seg = button1Cut2Seg;
      gfx_01.ofs = button1Cut2Ofs;
      ovr_blitGfxRect(gfx_01,223,8,(brect_t *)(BlitRects + 1),0x10,true,0,0,0,0,0,0);
    }
  }
  else {
    gfx.seg = button1Cut3Seg;
    gfx.ofs = button1Cut3Ofs;
    ovr_blitGfxRect(gfx,223,8,(brect_t *)(BlitRects + 1),0x10,true,0,0,0,0,0,0);
  }
  return;
}



/* 6018:0251 */

/* [R2] string "halfling castle" */

void __cdecl16far ovc28_textHalflingCastle(void)

{
  uint32_t uVar1;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  uint16_t *puVar2;
  int iVar3;
  char *text_00;
  byte *pbVar4;
  int iVar5;
  uint16_t uVar6;
  uint16_t seg;
  uint8_t term;
  uint8_t msg;
  uint8_t text;
  char cStack_4;
  byte bStack_3;
  
  ovr_ovc18_blitPanelIfNotRunning();
  gfx.seg = fullScreenGfxSeg;
  gfx.ofs = fullScreenGfxOfs;
  ovr_blitGfx10(gfx,0,0,(brect_t *)0x5ce5,true,0,0);
  if (GameRunning == false) {
    gfx_00.seg = panel01Cut2Seg;
    gfx_00.ofs = panel01Cut2Ofs;
    ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa0008fa4)),0);
    gfx_01.seg = trianglsCut5Seg;
    gfx_01.ofs = trianglsCut5Ofs;
    ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa000e249)),0);
    for (iVar5 = 0; iVar5 < 5; iVar5 = iVar5 + 1) {
      if (((uint8_t *)MenuItemEnabled)[iVar5] != 0xff) {
        TextBlitX = 0xea;
        TextBlitY = iVar5 * 0xd + 0x87;
        uVar1 = *(uint32_t *)((uint)((uint8_t *)MenuItemEnabled)[iVar5] << 2);
        bStack_3 = *(byte *)((int)uVar1 + 0x2f);
        if (bStack_3 == 0xff) {
          cStack_4 = 'F';
        }
        else {
          cStack_4 = *(char *)*(uint32_t *)((uint)bStack_3 * 4 + 0xeb);
        }
        term = 0x3f;
        puVar2 = (uint16_t *)((uint)((uint8_t *)MenuItemEnabled)[iVar5] * 4);
        pbVar4 = (byte *)((char *)0x2627a);
        uVar6 = Font03.ofs;
        seg = Font03.seg;
        iVar3 = ovr_ovc45_compute9((char *)&text,(char *)CONCAT22(*puVar2,_SS),
                                   (char *)CONCAT22(Font03.ofs,(char *)puVar2[1]),Font03.seg,'*',
                                   0x2a,3,(int)cStack_4);
        text_00 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x5cff,_SS),
                                (char *)CONCAT13((char)((uint)iVar3 >> 8),
                                                 CONCAT12((char)iVar3,0x2410)),(char)iVar3,pbVar4);
        ovr_blitText(text_00,(byte *)CONCAT22(uVar6,pbVar4),seg,term);
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
    ovr_drawTextAt((char *)"Sorry, you may not pause during a battle.",0x2410,0xa000);
    GPaused = '\0';
  }
  else {
    GPaused = '\x01' - (GPaused != '\0');
    if (GPaused == '\0') {
      ovr_drawTextAt((char *)"Resume. Game events will now occur normally.",0x2410,0xa000);
    }
    else {
      ovr_drawTextAt((char *)
                     "Pause. Select \'Resume\' to enable game events. Press SPACE for a single game event."
                     ,0x2410,0xa000);
    }
    update_pause_button();
  }
  return;
}



/* 6018:0456 */
void __cdecl16far ovc28_usesBlitGfx10(far_t entries,int count)

{
  far_t gfx;
  char *pcVar1;
  uint8_t *puVar2;
  uint16_t uVar3;
  int *piVar4;
  uint16_t *puVar5;
  int idx;
  int y;
  uint16_t uVar8;
  far_t gfx_00;
  uint16_t max_width;
  uint8_t uVar9;
  far_t dst;
  uint8_t text;
  int x;
  undefined1 *uStack_6;   /* hand fix: dereferenced as *uStack_6 */
  
  gfx_00.seg = fullScreenGfxSeg;
  gfx_00.ofs = fullScreenGfxOfs;
  ovr_blitGfx10(gfx_00,0,0,(brect_t *)0x5ce5,true,0,0);
  x = 0xeb;
  y = 0x3c;
  for (idx = 0; idx < count; idx = idx + 1) {
    uVar8 = entries.seg;
    uVar3 = entries.ofs;
    piVar4 = (int *)(uVar3 + idx * 4);
    if (*piVar4 != 0 || piVar4[1] != 0) {
      dst.seg = 0xa000;
      dst.ofs = x + y * 0x140;
      gfx.seg = butt01Cut5Seg;
      gfx.ofs = butt01Cut5Ofs;
      ovr_blitLoadRleGfx(gfx,dst,0);
      TextBlitDstSeg = 0xa000;
      TextBlitX = x + 6;
      TextBlitY = y + 2;
      puVar5 = (uint16_t *)(uVar3 + idx * 4);
      pcVar1 = (char *)puVar5[1];
      puVar2 = (uint8_t *)*puVar5;
      uStack_6 = (uint8_t *)CONCAT22(pcVar1,puVar2);
      if (*uStack_6 == 0x25) {
        BlitLetterType = 2;
        uVar9 = 0x3f;
        uVar3 = FontMain.ofs;
        uVar8 = FontMain.seg;
        pcVar1 = (char *)ovr_ovc45_compute9((char *)&text,(char *)CONCAT22(puVar2 + 1,_SS),
                                            (char *)CONCAT22(FontMain.ofs,pcVar1),FontMain.seg,'E',3
                                           );
        ovr_blitLabel(pcVar1,(uint8_t *)CONCAT22(uVar3,puVar2),uVar8,uVar9);
        BlitLetterType = 0;
      }
      else if (*uStack_6 == 0x40) {
        uVar9 = 0x3f;
        uVar3 = FontMain.ofs;
        uVar8 = FontMain.seg;
        pcVar1 = (char *)ovr_ovc45_compute9((char *)&text,(char *)CONCAT22(puVar2 + 1,_SS),
                                            (char *)CONCAT22(FontMain.ofs,pcVar1),FontMain.seg,'E',3
                                           );
        ovr_blitLabel(pcVar1,(uint8_t *)CONCAT22(uVar3,puVar2),uVar8,uVar9);
      }
      else {
        uVar9 = 0x3f;
        puVar5 = (uint16_t *)(uVar3 + idx * 4);
        uVar3 = FontMain.ofs;
        max_width = FontMain.seg;
        pcVar1 = (char *)ovr_ovc45_compute9((char *)&text,(char *)CONCAT22(*puVar5,_SS),
                                            (char *)CONCAT22(FontMain.ofs,(char *)puVar5[1]),
                                            FontMain.seg,'E',3);
        ovr_blitLabel(pcVar1,(uint8_t *)CONCAT22(uVar3,puVar2),max_width,uVar9);
      }
    }
    y = y + 0xe;
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
  byte *pbVar3;
  int iVar4;
  uint16_t uVar5;
  uint32_t uVar6;
  uint16_t uVar7;
  uint8_t numText;
  
  uVar1 = ovr_font_textWidth((char *)"Gold",(char *)CONCAT22(Font03.ofs,(char *)0x26510),Font03.seg,0,0);
  TextBlitX = 0x10e - (uVar1 >> 1);
  TextBlitY = 0x9c;
  ovr_blitText((char *)"Gold",(byte *)CONCAT22(Font03.ofs,(char *)0x26510),Font03.seg,0x3f
               ,0xed);
  uVar5 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
  iVar4 = (int)*(uint32_t *)((uint)partyIndex << 2);
  ovr_litoa10((char *)&numText,(long)CONCAT22(*(uint16_t *)(iVar4 + 0x56),_SS),*(uint16_t *)(iVar4 + 0x58),0);
  uVar1 = ovr_font_textWidth((char *)&numText,(char *)CONCAT22(Font03.ofs,_SS),Font03.seg,0,0);
  uVar2 = 0x10e - (uVar1 >> 1);
  TextBlitY = 0xa7;
  TextBlitX = uVar2;
  ovr_blitText((char *)&numText,(byte *)CONCAT22(Font03.ofs,_SS),Font03.seg,0x3f,0xed);
  iVar4 = ovr_ovc45_usesLDIV_at_(partyIndex,0,0);
  if (iVar4 != 0 || uVar2 != 0) {
    uVar1 = ovr_font_textWidth((char *)"Fund",(char *)CONCAT22(Font03.ofs,(char *)0x26510),Font03.seg,0,0);
    uVar2 = 0x10e - (uVar1 >> 1);
    TextBlitY = 0xb2;
    TextBlitX = uVar2;
    ovr_blitText((char *)"Fund",(byte *)CONCAT22(Font03.ofs,(char *)0x26510),Font03.seg,
                 0x3f,0xed);
    uVar5 = ovr_ovc45_usesLDIV_at_(partyIndex,0,0);
    ovr_litoa10((char *)&numText,(long)CONCAT22(uVar5,_SS),uVar2,0);
    uVar1 = ovr_font_textWidth((char *)&numText,(char *)CONCAT22(Font03.ofs,_SS),Font03.seg,0,0);
    pbVar3 = (byte *)(0x10e - (uVar1 >> 1));
    TextBlitY = 0xbd;
    uVar7 = 0xed;
    uVar6 = CONCAT22(0x13f,Font03.seg);
    TextBlitX = (uint16_t)pbVar3;
    uVar2 = Font03.ofs;
    uVar5 = ovr_ovc45_usesLDIV_at_(partyIndex,0,0);
    text = ovr_litoa10((char *)&numText,(long)CONCAT22(uVar5,_SS),pbVar3,0);
    ovr_blitText(text,(byte *)CONCAT22(uVar2,pbVar3),(uint16_t)uVar6,(uint8_t)((ulong)uVar6 >> 0x10)
                 ,uVar7);
  }
  return;
}



/* 6018:0813 */

/* Draws a butt01Cut6 button at (x,y) and its label. */

void __cdecl16far ovc28_drawButton(int x,int y,char *label)

{
  far_t gfx;
  far_t gfx_00;
  char *pcVar1;
  byte *pbVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  uint8_t uVar5;
  far_t dst;
  far_t dst_00;
  uint8_t text;
  
  dst.seg = 0xa000;
  dst.ofs = x + y * 0x140;
  gfx.seg = butt01Cut6Seg;
  gfx.ofs = butt01Cut6Ofs;
  ovr_blitLoadRleGfx(gfx,dst,0);
  TextBlitX = x + 6;
  TextBlitY = y + 2;
  pbVar2 = (byte *)((char *)0x26510);
  if (*label == '%') {
    BlitLetterType = 2;
    uVar5 = 0x3f;
    uVar3 = Font01.ofs;
    uVar4 = Font01.seg;
    pcVar1 = (char *)ovr_ovc45_compute9((char *)&text,(char *)CONCAT22((char *)label + 1,_SS),
                                        (char *)CONCAT22(Font01.ofs,(*(uint16_t *)((uint8_t *)&(label) + 2))),Font01.seg,'E',3);
    ovr_blitLabel(pcVar1,(byte *)CONCAT22(uVar3,pbVar2),uVar4,uVar5);
    BlitLetterType = 0;
  }
  else if (*label == '@') {
    uVar5 = 0x3f;
    uVar3 = Font01.ofs;
    uVar4 = Font01.seg;
    pcVar1 = (char *)ovr_ovc45_compute9((char *)&text,(char *)CONCAT22((char *)label + 1,_SS),
                                        (char *)CONCAT22(Font01.ofs,(*(uint16_t *)((uint8_t *)&(label) + 2))),Font01.seg,'E',3);
    ovr_blitLabel(pcVar1,(byte *)CONCAT22(uVar3,pbVar2),uVar4,uVar5);
  }
  else {
    uVar5 = 0x3f;
    uVar3 = Font01.ofs;
    uVar4 = Font01.seg;
    pcVar1 = (char *)ovr_ovc45_compute9((char *)&text,(char *)CONCAT22((char *)label,_SS),
                                        (char *)CONCAT22(FontMain.ofs,(*(uint16_t *)((uint8_t *)&(label) + 2))),FontMain.seg,'E',
                                        3);
    ovr_blitText(pcVar1,(byte *)CONCAT22(uVar3,pbVar2),uVar4,uVar5);
  }
  ovc28_usesBDADailyTimeCounter(3);
  dst_00.seg = 0xa000;
  dst_00.ofs = x + y * 0x140;
  gfx_00.seg = butt01Cut5Seg;
  gfx_00.ofs = butt01Cut5Ofs;
  ovr_blitLoadRleGfx(gfx_00,dst_00,0);
  TextBlitX = x + 6;
  TextBlitY = y + 2;
  pbVar2 = (byte *)((char *)0x26510);
  if (*label == '%') {
    BlitLetterType = 2;
    uVar5 = 0x3f;
    uVar3 = FontMain.ofs;
    uVar4 = FontMain.seg;
    pcVar1 = (char *)ovr_ovc45_compute9((char *)&text,(char *)CONCAT22((char *)label + 1,_SS),
                                        (char *)CONCAT22(FontMain.ofs,(*(uint16_t *)((uint8_t *)&(label) + 2))),FontMain.seg,'E',
                                        3);
    ovr_blitLabel(pcVar1,(byte *)CONCAT22(uVar3,pbVar2),uVar4,uVar5);
    BlitLetterType = 0;
  }
  else if (*label == '@') {
    uVar5 = 0x3f;
    uVar3 = FontMain.ofs;
    uVar4 = FontMain.seg;
    pcVar1 = (char *)ovr_ovc45_compute9((char *)&text,(char *)CONCAT22((char *)label + 1,_SS),
                                        (char *)CONCAT22(FontMain.ofs,(*(uint16_t *)((uint8_t *)&(label) + 2))),FontMain.seg,'E',
                                        3);
    ovr_blitLabel(pcVar1,(byte *)CONCAT22(uVar3,pbVar2),uVar4,uVar5);
  }
  else {
    uVar5 = 0x3f;
    uVar3 = FontMain.ofs;
    uVar4 = FontMain.seg;
    pcVar1 = (char *)ovr_ovc45_compute9((char *)&text,(char *)CONCAT22((char *)label,_SS),
                                        (char *)CONCAT22(FontMain.ofs,(*(uint16_t *)((uint8_t *)&(label) + 2))),FontMain.seg,'E',
                                        3);
    ovr_blitText(pcVar1,(byte *)CONCAT22(uVar3,pbVar2),uVar4,uVar5);
  }
  return;
}



/* 6018:0aac */

/* Draws menu entry `index` of a far-pointer table at x=0xeb and y=0x3c+index*0xe. */

void __cdecl16far ovc28_blitMenuEntry(far_t entries,int index)

{
  uint16_t *puVar1;
  
  if (index < 0xfa) {
    puVar1 = (uint16_t *)(entries.ofs + index * 4);
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
       ovr_stshRleCut((far_t *)0x0,src,CrossBlitY,CrossBlitX + 0xd,CrossBlitY + 9,unaff_BP,(char)CrossBlitY,0,0);
  dst.seg = 0xa000;
  dst.ofs = CrossBlitX + CrossBlitY * 0x140;
  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)CrossBlitGfx.seg;
  gfx.ofs = CrossBlitGfx.ofs;
  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)(CrossBlitGfx.seg >> 8);
  CrossBlitPtr.seg = in_DX;
  ovr_blitLoadRleGfx(gfx,dst,0);
  if (MouseMoved == 0) {
    unk = ovr_draw_compute3(CrossBlitX);
    ovr_play_sfxU(0,1,unk,0,0);
  }
  return;
}



/* 6018:0c76 */

/* [R6] touches ScreenMode, MouseMoved */

uint16_t __cdecl16far ovc28_usesScreenMode(far_t entries,uint count)

{
  uint16_t uVar1;
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

char * __cdecl16far uiInputText(far_t entries,uint16_t count,far_t hint,uint8_t flags,uint16_t arg5)

{
  int iVar1;
  uint uVar2;
  undefined1 uVar5;
  uint16_t key;
  uint16_t uVar4;
  
  UserWantsExit = 0;
  if (hint.ofs != 0 || hint.seg != 0) {
    if (ScreenMode == '\0') {
      ovr_drawTextAt((char *)hint.ofs,hint.seg,0xa000);
    }
    else {
      ovr_drawString((char *)hint.ofs,hint.seg,0);
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
    ovr_play_sfx(CONCAT11(uVar5,SfxPending),0,0);
    SfxPending = '\0';
  }
  GMenuFlag = 1;
L_uiInputText_1007:
  do {
    while( true ) {
      key = ovr_uiReadKey2();
      if (key != 0x4838) break;
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
    if (key < 0x4839) {
      if (key == 0x1675) {
L_uiInputText_10F1:
        if (menuBarShown != '\0') {
          GMenuFlag = 0;
          return (char *)0x1e5;
        }
        goto L_uiInputText_1007;
      }
      if (key < 0x1676) {
        if (key != 0x1372) {
          if (0x1372 < key) {
            if (key == 0x1655) goto L_uiInputText_10F1;
            goto L_uiInputText_1007;
          }
          if (key == 0x11b) {
            UserWantsExit = 1;
            goto L_uiInputText_1348;
          }
          if (key != 0x1352) goto L_uiInputText_1007;
        }
        if (menuBarShown != '\0') {
          GMenuFlag = 0;
          return (char *)0x1e3;
        }
        goto L_uiInputText_1007;
      }
      if (key != 0x2368) {
        if (0x2368 < key) {
          if (key == 0x4800) goto L_uiInputText_110E;
          goto L_uiInputText_1007;
        }
        if (key == 0x1c0d) {
          if (GMenuItem != 0) {
            ovc28_blitMenuEntry(entries,GMenuItem - 1);
          }
          ovc28_usesBlitLoadRleGfx();
          GMenuFlag = 0;
          return (char *)CONCAT11(0x24,GMenuItem);
        }
        if (key != 0x2348) goto L_uiInputText_1007;
      }
      if (menuBarShown != '\0') {
        GMenuFlag = 0;
        return (char *)0x1e4;
      }
      goto L_uiInputText_1007;
    }
    if (key == 0x5100) {
L_uiInputText_1376:
      if ((flags & 2) != 0) {
        GMenuFlag = 0;
        return (char *)CONCAT11(0x24,(byte)count);
      }
    }
    else if (key < 0x5101) {
      if (key == 0x5000) {
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
      else if (key < 0x5001) {
        if (((key == 0x4900) || (key == 0x4939)) && ((flags & 1) != 0)) {
          GMenuFlag = 0;
          return (char *)0x2401;
        }
      }
      else if (key == 0x5032) goto L_uiInputText_11EE;
    }
    else {
      if (key == 0x5133) goto L_uiInputText_1376;
      if (key == 0xfffe) {
L_uiInputText_1348:
        ovc28_usesBlitLoadRleGfx();
        GMenuFlag = 0;
        return (char *)0x2400;
      }
      if (key == 0xffff) {
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
ovc28_usesUiInputText(far_t entries,uint16_t count,far_t hint,uint8_t *pageOut,uint16_t arg5,uint16_t arg6)

{
  uint16_t uVar1;
  char *pcVar2;
  uint uVar3;
  uint16_t *puVar4;
  uint uVar5;
  uint16_t in_stack_00000010;
  far_t entries_00;
  far_t hint_00;
  uint8_t menuEntries;
  uint16_t auStack_34 [17];
  uint16_t uStack_12;
  uint16_t uStack_10;
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
    pcVar2 = uiInputText(entries,count,hint,0x0,0);
  }
  else {
    while( true ) {
      auStack_34[0] = 0x2410;
      menuEntries = 0x5db9;
      uStack_10 = 0x2410;
      uStack_12 = 0x5dc2;
      if (*pageOut == 0) {
        bStack_4 = 0;
        bStack_6 = 0;
        bStack_5 = 9;
        uStack_8 = 0x2;
        bStack_9 = 10;
      }
      else if ((int)((uint)*pageOut * 8 + 8) < (int)count) {
        bStack_4 = 1;
        bStack_6 = *pageOut * '\b' + 1;
        bStack_5 = 8;
        uStack_8 = 0x3;
        bStack_9 = 10;
      }
      else {
        bStack_4 = 1;
        bStack_6 = *pageOut * '\b' + 1;
        bStack_5 = (char)count - bStack_6;
        bStack_9 = bStack_5 + 1;
        uStack_8 = 0x1;
      }
      for (bStack_7 = 0; bStack_7 < bStack_5; bStack_7 = bStack_7 + 1) {
        puVar4 = (uint16_t *)(entries.ofs + ((uint)bStack_6 + (uint)bStack_7) * 4);
        uVar1 = *puVar4;
        uVar5 = (uint)bStack_4;
        uVar3 = (uint)bStack_7;
        auStack_34[(uVar5 + uVar3) * 2] = puVar4[1];
        *(uint16_t *)(&menuEntries + (uVar5 + uVar3) * 4) = uVar1;
      }
      hint_00.seg = uStack_c;
      hint_00.ofs = uStack_e;
      entries_00.seg = _SS;
      entries_00.ofs = (uint16_t)&menuEntries;
      pcVar2 = uiInputText(entries_00,(uint)bStack_9,hint_00,uStack_8,0);
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
        *pageOut = *pageOut - 1;
      }
      else {
        *pageOut = *pageOut + 1;
      }
    }
    pcVar2 = (char *)CONCAT11((char)(uVar3 >> 8),(bStack_6 + cStack_3) - bStack_4);
  }
  return pcVar2;
}



/* 6018:1527 */

/* [R7] body shape: compute */

void __cdecl16far ovc28_compute2(far_t entries,uint16_t count,far_t hint,uint16_t arg4,uint16_t arg5)

{
  uint8_t uStack_3;
  
  uStack_3 = 0x0;
  ovc28_usesUiInputText(entries,count,hint,&uStack_3,0,0);
  return;
}


