/*
 * ovc16_saveui.c - recovered from STRONG.EXE
 * memory block: OVC16_saveui.c
 * range: 4528:0000 - 4528:221f
 * functions: 22
 */
#include "recovered.h"


/* 4528:0000 */

uint16_t __cdecl16far uiReadKey2(void)

{
  bool firstPass;
  int startX;
  int startY;
  byte miceResult;
  uint16_t keyAvail;
  uint16_t key;
  undefined1 extraout_AH;
  int startTick;
  int prevTick;
  
  MiceUnkState = 0;
  ovr_ovr_miceButton0PressStates_entry();
  MiceProcessed = 0;
  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x2410);
  startY = MouseY;
  startX = MouseX;
  firstPass = false;
  MouseMoved = 0;
  while( true ) {
    if ((*(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != prevTick) ||
       (*(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) != startTick)) {
      prevTick = *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
      startTick = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
      ovr_draw_usesBlitLoadRleGfx();
      ovr_ovc13_usesMiceBlitRect();
    }
    keyAvail = ovr_biosKeyAvail();
    if ((char)keyAvail != '\0') break;
    miceResult = ovr_init2_usesCFGMice((uint16_t *)&MouseX,(uint16_t *)&MouseY,0x2410);
    if (CONCAT11(extraout_AH,miceResult) == 0) {
      firstPass = true;
    }
    else if (((firstPass) || (MouseX != startX)) || (MouseY != startY)) {
      if (!firstPass) {
        MouseMoved = 1;
      }
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
      MouseBkgPixel = *(undefined1 *)(MouseY * 0x140 + MouseX);
      ovr_draw_usesBlitLoadRleGfx2();
      ovr_resetTextBlitCycle();
      return 0xffff;
    }
    if (rightButtonLatch != '\0') {
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
      MouseBkgPixel = *(undefined1 *)(MouseY * 0x140 + MouseX);
      ovr_draw_usesBlitLoadRleGfx2();
      ovr_resetTextBlitCycle();
      return 0xfffe;
    }
  }
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x2410);
  ovr_draw_usesBlitLoadRleGfx2();
  ovr_resetTextBlitCycle();
  key = ovr_gameProcessKey();
  return key;
}



/* 4528:01b2 */

/* Initialises the cross-hair animation state from the current menu item. */

void __cdecl16far saveui_startCrossBlit(void)

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
  else {
    CrossBlitX = 0x16;
    CrossBlitY = (uint)GMenuItem * 0xf + 0xb;
    in_DX = 0x2410;
  }
  if (CrossBlitPtr.ofs != 0 || CrossBlitPtr.seg != 0) {
    handle.seg = CrossBlitPtr.seg;
    handle.ofs = CrossBlitPtr.ofs;
    ovr_stshFree(handle);
  }
  src.seg = 0xa000;
  src.ofs = CrossBlitX;
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



/* 4528:02fb */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far saveui_usesBlitLoadRleGfx2(far_t textTable,int rowIndex,int itemOffset)

{
  far_t gfx;
  far_t gfx_00;
  uint16_t *puVar1;
  far_t dst;
  far_t dst_00;
  
  dst.seg = 0xa000;
  dst.ofs = rowIndex * 0x12c0 + 0x2096;
  gfx.seg = trianglsCut3Seg;
  gfx.ofs = trianglsCut3Ofs;
  ovr_blitLoadRleGfx(gfx,dst,0);
  TextBlitX = 0x2a;
  TextBlitY = rowIndex * 0xf + 0x1d;
  puVar1 = (uint16_t *)(textTable.ofs + (rowIndex + itemOffset) * 4);
  ovr_blitText((char *)*puVar1,(byte *)CONCAT22(Font03.ofs,(byte *)puVar1[1]),Font03.seg,0xde);
  ovr_ovc28_usesBDADailyTimeCounter(3);
  dst_00.seg = 0xa000;
  dst_00.ofs = rowIndex * 0x12c0 + 0x2096;
  gfx_00.seg = trianglsCut4Seg;
  gfx_00.ofs = trianglsCut4Ofs;
  ovr_blitLoadRleGfx(gfx_00,dst_00,0);
  TextBlitX = 0x2a;
  TextBlitY = rowIndex * 0xf + 0x1d;
  puVar1 = (uint16_t *)(textTable.ofs + (rowIndex + itemOffset) * 4);
  ovr_blitText((char *)*puVar1,(byte *)CONCAT22(Font03.ofs,(byte *)puVar1[1]),Font03.seg,0xde);
  return;
}



/* 4528:0404 */

/* [R6] touches MouseMoved, MouseX */

uint16_t __cdecl16far saveui_usesMouseMoved(far_t textTable,int rowLimit,int itemOffset)

{
  uint16_t uVar1;
  uint uVar2;
  uint rowIndex;
  int *piVar3;
  char menuItem;
  
  if ((((MouseMoved == 0) && (8 < MouseX)) && (MouseX < 0x19)) &&
     ((0xb4 < MouseY && ((MouseY < 0xb6 | 0xeU) != 0)))) {
    uVar1 = 0;
  }
  else {
    uVar2 = 0x2410;
    if ((((MouseMoved == 0) && ((uVar2 = 0x2410, 0x15 < MouseX && (uVar2 = 0x2410, MouseX < 0x26))))
        && (uVar2 = 0x2410, 0x19 < MouseY)) && (uVar2 = rowLimit * 0xf + 0x19, MouseY <= uVar2)) {
      rowIndex = (MouseY - 0x1a) / 0xf;
      uVar2 = rowIndex * 0xf + 0x1a;
      if ((MouseY - uVar2 < 0xf) &&
         (piVar3 = (int *)(textTable.ofs + (rowIndex + itemOffset) * 4), uVar2 = 0,
         *piVar3 != 0 || piVar3[1] != 0)) {
        saveui_usesBlitLoadRleGfx2(textTable,rowIndex,itemOffset);
        menuItem = (char)rowIndex;
        GMenuItem = menuItem + '\x01';
        return CONCAT11(0x24,menuItem + '\x01');
      }
    }
    uVar1 = CONCAT11((char)(uVar2 >> 8),0xff);
  }
  return uVar1;
}



/* 4528:0533 */

/* Blits the save-UI panel graphic (nwpanel2Cut1) at the screen origin. */

void __cdecl16far saveui_blitPanel(void)

{
  far_t gfx;
  
  ovr_ovc18_blitPanelIfNotRunning();
  gfx.seg = nwpanel2Cut1Seg;
  gfx.ofs = nwpanel2Cut1Ofs;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)(BlitRects + 1),0x10,true,0,0,0,0,0,0);
  return;
}



/* 4528:055b */

/* [R4] calls ovr_blitGfx10 */

void __cdecl16far saveui_usesBlitGfx10(far_t gfx,char *text,byte *widths,uint *cursorX,int row)

{
  far_t gfx_00;
  far_t gfx_01;
  uint16_t uVar1;
  uint16_t in_stack_00000004;
  far_t dst;
  uint8_t rect;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)&rect;
  F_SCOPY(far_from_u32((uint32_t)(0x241026ad)),dst,10);
  rect = *(uint *)CONCAT22((byte *)widths,(*(uint16_t *)((uint8_t *)&(text) + 2)));
  uVar1 = (*(uint16_t *)((uint8_t *)&(widths) + 2)) * 0xf + 0x1d;
  gfx_00.seg = gfx.ofs;
  gfx_00.ofs = in_stack_00000004;
  ovr_blitGfx10(gfx_00,0x16,uVar1,(brect_t *)&rect,SUB21(_SS,0),(char)uVar1,0);
  TextBlitX = 0x2a;
  TextBlitY = (*(uint16_t *)((uint8_t *)&(widths) + 2)) * 0xf + 0x1d;
  ovr_blitText((char *)gfx.seg,
               (byte *)CONCAT13((char)(Font03.ofs >> 8),CONCAT12((char)Font03.ofs,(char *)text)),
               Font03.seg,0xde,(char)Font03.ofs);
  if (TextBlitX < *(uint *)CONCAT22((byte *)widths,(*(uint16_t *)((uint8_t *)&(text) + 2)))) {
    rect = TextBlitX;
    uVar1 = (*(uint16_t *)((uint8_t *)&(widths) + 2)) * 0xf + 0x1d;
    gfx_01.seg = gfx.ofs;
    gfx_01.ofs = in_stack_00000004;
    ovr_blitGfx10(gfx_01,0x16,uVar1,(brect_t *)&rect,SUB21(_SS,0),(char)uVar1,0);
  }
  *(uint16_t *)CONCAT22((byte *)widths,(*(uint16_t *)((uint8_t *)&(text) + 2))) = TextBlitX;
  ovr_blitLetter('_',(byte *)Font03.ofs,(uint8_t)Font03.seg,0xf);
  return;
}



/* 4528:0664 */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far saveui_usesBlitLoadRleGfx3(far_t entries,int count)

{
  far_t gfx;
  int *entryPtr;
  uint16_t *entryWords;
  int idx;
  far_t dst;
  
  for (idx = 0; idx < count; idx = idx + 1) {
    entryPtr = (int *)(entries.ofs + idx * 4);
    if (*entryPtr != 0 || entryPtr[1] != 0) {
      dst.seg = 0xa000;
      dst.ofs = idx * 0x12c0 + 0x2096;
      gfx.seg = trianglsCut4Seg;
      gfx.ofs = trianglsCut4Ofs;
      ovr_blitLoadRleGfx(gfx,dst,0);
      TextBlitX = 0x2a;
      TextBlitY = idx * 0xf + 0x1d;
      entryWords = (uint16_t *)(entries.ofs + idx * 4);
      ovr_blitText((char *)*entryWords,(byte *)CONCAT22(Font03.ofs,(byte *)entryWords[1]),Font03.seg,0xde);
    }
  }
  return;
}



/* 4528:0706 */

uint16_t __cdecl16far uiMenuSub(char far *title,far_t items,uint16_t nitems,uint16_t defopt)

{
  undefined1 stk_ffd4;   /* stack slot ffd4 */
  undefined1 stk_ffd6;   /* stack slot ffd6 */
  far_t textTable;
  far_t textTable_00;
  far_t entries;
  far_t entries_00;
  far_t entries_01;
  far_t entries_02;
    byte selIndex;
    uint16_t key;
    uint16_t itemOfs;
  uint16_t mouseHit;
  uint readLen;
    uint16_t far *itemPtr;
    undefined1 ssLow;
    undefined1 ssHigh;
  far_t dest[7];   /* 7 far string pointers: _fsetmem zeroes 0x1c bytes and row runs 0..6 */
    uint16_t titleOfs;
    uint16_t titleSeg;
  uint16_t sz;
    int scrollOfs;
  uint8_t readed;
  byte menuId;
  
  TextBlitDstSeg = 0xa000;
  if ((char *)far_ofs_u32(title) != (char *)0x0 || (char *)title != (char *)0x0) {
    TextBlitX = 0x16;
    TextBlitY = 0xb;
    ovr_blitText(title,(byte far *)MK_FP(Font03.seg,Font03.ofs),0xde,7);
  }
  scrollOfs = 0;
  if ((int)nitems < 9) {
    sz = nitems;
  }
  else {
    sz = 8;
  }
  for (readed = 0x0; (int)(uint)readed < (int)sz; readed = readed + 0x1) {
    itemPtr = (uint16_t far *)MK_FP(items.seg,(uint16_t)(items.ofs + (uint)readed * 4));
    itemOfs = *itemPtr;
    readLen = (uint)readed;
    dest[readLen].seg = itemPtr[1];
    dest[readLen].ofs = itemOfs;
  }
  if (8 < (int)nitems) {
    titleSeg = _DS;
    titleOfs = (uint16_t)"More";
  }
  ssLow = (undefined1)_SS;
  ssHigh = (undefined1)(_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(entries.seg))) = ssLow;
  entries.ofs = (uint16_t)&dest;
  (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = ssHigh;
  saveui_usesBlitLoadRleGfx3(entries,sz);
  GMenuItem = (byte)nitems;
  while (((int)(uint)GMenuItem <= (int)sz &&
         (*(int *)(&stk_ffd4 + (uint)GMenuItem * 4) == 0 &&
          *(int *)(&stk_ffd6 + (uint)GMenuItem * 4) == 0))) {
    GMenuItem = GMenuItem + 1;
  }
  if ((int)sz < (int)(uint)GMenuItem) {
    GMenuItem = 0;
  }
  saveui_startCrossBlit();
  ovr_ovc40_flushInput();
  GMenuFlag = 1;
L_uiMenuSub_0840:
  do {
    while (key = uiReadKey2(), key == 0x5000) {
L_uiMenuSub_0903:
      do {
        GMenuItem = GMenuItem + 1;
        if ((int)sz < (int)(uint)GMenuItem) {
          GMenuItem = 0;
        }
      } while ((GMenuItem != 0) &&
              (*(int *)(&stk_ffd4 + (uint)GMenuItem * 4) == 0 &&
               *(int *)(&stk_ffd6 + (uint)GMenuItem * 4) == 0));
      saveui_startCrossBlit();
    }
    if (0x5000 < key) {
      if (key != 0x5133) {
        if (0x5133 < key) {
          if (key == 0xfffe) {
            GMenuFlag = 0;
            return;
          }
          if (key == 0xffff) {
            textTable.seg = _SS;
            textTable.ofs = (uint16_t)&dest;
            mouseHit = saveui_usesMouseMoved(textTable,sz,0);
            menuId = (byte)mouseHit;
            selIndex = menuId;
            if (menuId != 0xff) {
L_uiMenuSub_0B46:
              GMenuItem = selIndex;
              if (GMenuItem != 0) {
                textTable_00.seg = _SS;
                textTable_00.ofs = (uint16_t)&dest;
                saveui_usesBlitLoadRleGfx2(textTable_00,GMenuItem - 1,0);
              }
              if (((int)nitems < 9) || (GMenuItem != 8)) {
                GMenuFlag = 0;
                return;
              }
              if (scrollOfs + 7 < (int)nitems) {
                scrollOfs = scrollOfs + 7;
              }
              else {
                scrollOfs = 0;
              }
              _fsetmem(MK_FP(_SS,&dest),0x1c,0);
              for (readed = 0x0; (readed < 7 && ((int)((uint)readed + scrollOfs) < (int)nitems));
                  readed = readed + 0x1) {
                itemPtr = (uint16_t far *)MK_FP(items.seg,(uint16_t)(items.ofs + ((uint)readed + scrollOfs) * 4));
                itemOfs = *itemPtr;
                readLen = (uint)readed;
                dest[readLen].seg = itemPtr[1];
                dest[readLen].ofs = itemOfs;
              }
              saveui_blitPanel();
              if ((char *)far_ofs_u32(title) != (char *)0x0 || (char *)title != (char *)0x0) {
                TextBlitX = 0x16;
                TextBlitY = 0xb;
                ovr_blitText(title,(byte far *)MK_FP(Font03.seg,Font03.ofs),0xde,7);
              }
              (*(uint8_t *)((uint8_t *)&(entries_02.seg))) = ssLow;
              entries_02.ofs = (uint16_t)&dest;
              (*(uint8_t *)((uint8_t *)&(entries_02.seg) + 1)) = ssHigh;
              saveui_usesBlitLoadRleGfx3(entries_02,8);
              saveui_startCrossBlit();
            }
          }
          goto L_uiMenuSub_0840;
        }
        if (key == 0x5032) goto L_uiMenuSub_0903;
        if (key != 0x5100) goto L_uiMenuSub_0840;
      }
      if (8 < (int)nitems) {
        if (scrollOfs + 7 < (int)nitems) {
          scrollOfs = scrollOfs + 7;
        }
        else {
          scrollOfs = 0;
        }
        _fsetmem(MK_FP(_SS,&dest),0x1c,0);
        for (readed = 0x0; (readed < 7 && ((int)((uint)readed + scrollOfs) < (int)nitems));
            readed = readed + 0x1) {
          itemPtr = (uint16_t far *)MK_FP(items.seg,(uint16_t)(items.ofs + ((uint)readed + scrollOfs) * 4));
          itemOfs = *itemPtr;
          readLen = (uint)readed;
          dest[readLen].seg = itemPtr[1];
          dest[readLen].ofs = itemOfs;
        }
        saveui_blitPanel();
        if ((char *)far_ofs_u32(title) != (char *)0x0 || (char *)title != (char *)0x0) {
          TextBlitX = 0x16;
          TextBlitY = 0xb;
          ovr_blitText(title,(byte far *)MK_FP(Font03.seg,Font03.ofs),0xde,7);
        }
        (*(uint8_t *)((uint8_t *)&(entries_01.seg))) = ssLow;
        entries_01.ofs = (uint16_t)&dest;
        (*(uint8_t *)((uint8_t *)&(entries_01.seg) + 1)) = ssHigh;
        saveui_usesBlitLoadRleGfx3(entries_01,8);
        GMenuItem = 8;
        saveui_startCrossBlit();
      }
      goto L_uiMenuSub_0840;
    }
    if (key == 0x4838) {
L_uiMenuSub_08AD:
      do {
        GMenuItem = GMenuItem - 1;
        if (GMenuItem == 0xff) {
          GMenuItem = (byte)sz;
        }
      } while ((GMenuItem != 0) &&
              (*(int *)(&stk_ffd4 + (uint)GMenuItem * 4) == 0 &&
               *(int *)(&stk_ffd6 + (uint)GMenuItem * 4) == 0));
      saveui_startCrossBlit();
    }
    else if (key < 0x4839) {
      if (key == 0x11b) {
        GMenuFlag = 0;
        return;
      }
      selIndex = GMenuItem;
      if (key == 0x1c0d) goto L_uiMenuSub_0B46;
      if (key == 0x4800) goto L_uiMenuSub_08AD;
    }
    else if (((key == 0x4900) || (key == 0x4939)) && (8 < (int)nitems)) {
      if (scrollOfs == 0) {
        scrollOfs = ((int)(nitems - 1) / 7) * 7;
      }
      else {
        scrollOfs = scrollOfs + -7;
      }
      _fsetmem(MK_FP(_SS,&dest),0x1c,0);
      for (readed = 0x0; (readed < 7 && ((int)((uint)readed + scrollOfs) < (int)nitems));
          readed = readed + 0x1) {
        itemPtr = (uint16_t far *)MK_FP(items.seg,(uint16_t)(items.ofs + ((uint)readed + scrollOfs) * 4));
        itemOfs = *itemPtr;
        readLen = (uint)readed;
        dest[readLen].seg = itemPtr[1];
        dest[readLen].ofs = itemOfs;
      }
      saveui_blitPanel();
      if ((char *)far_ofs_u32(title) != (char *)0x0 || (char *)title != (char *)0x0) {
        TextBlitX = 0x16;
        TextBlitY = 0xb;
        ovr_blitText(title,(byte far *)MK_FP(Font03.seg,Font03.ofs),0xde,7);
      }
      (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = ssLow;
      entries_00.ofs = (uint16_t)&dest;
      (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = ssHigh;
      saveui_usesBlitLoadRleGfx3(entries_00,8);
      GMenuItem = 8;
      saveui_startCrossBlit();
    }
  } while( true );
}



/* 4528:0c98 */
char * __cdecl16far uiReadString(char *textOfs,int textSeg,int row,char *gfxOfs,uint16_t gfxSeg,uint16_t arg6)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t dst;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  far_t handle_03;
  far_t handle_04;
  size_t sVar1;
  far_t far *pfVar2;
  uint16_t rowOfs;
  int textW;
  int underscoreW;
  char *pcVar6;
  uint8_t *puVar7;
  uint16_t rowSegHi;
  uint16_t uVar9;
  /* 4528:0C98 prologue: mov si, word ptr [bp + 0xa] - the third parameter (row),
     and the only write to SI in the whole function, so the pseudo-register IS
     that parameter. */
  uint8_t *puVar10;
  uint *ey;
  uint3 uStack_5e;
  uint8_t text;
  undefined1 uStack_5b;
  int in_stack_0000ffa6;
  uint8_t cursorX;
  byte bStack_5;
  uint16_t keyCode;
  
  uStack_5e = (uint16_t)CONCAT22(text,row);
  UserWantsExit = 0;
  inputCancelled = 0;
  if (textOfs != (char *)0x0 || textSeg != 0) {
    TextBlitX = 0x16;
    TextBlitY = 0xb;
    ovr_blitText(textOfs,(byte *)CONCAT22(Font03.ofs,textSeg),Font03.seg,0xde,0xde,7);
  }
  if (gfxOfs == (char *)0x0 && gfxSeg == 0) {
    uStack_5e = ZEXT23(ey);
  }
  else {
    strcpy((char *)CONCAT22(_SS,&text),(char *)CONCAT22(gfxSeg,gfxOfs));
  }
  sVar1 = strlen((char *)CONCAT22(_SS,&text));
  bStack_5 = (byte)sVar1;
  rowSegHi = (uint16_t)((ulong)((long)row * 0xf) >> 0x10);
  pfVar2 = ovr_stshRleCut((far_t far *)0x0,far_from_u32((uint32_t)(0x16a000)),(int)((long)row * 0xf) + 0x1d,222,row * 0xf + 0x29,(int16_t)ey,0xde,0,0);
  TextBlitX = 0x2a;
  TextBlitY = row * 0xf + 0x1d;
  cursorX = 0;
  gfx.seg = (uint16_t)&text;
  gfx.ofs = rowSegHi;
  saveui_usesBlitGfx10
            (gfx,(char *)CONCAT22(&cursorX,_SS),(byte *)CONCAT22(row,_SS),(uint *)uStack_5e,
             in_stack_0000ffa6);
  rowOfs = row * 0x12c0 + 0x2096;
  gfx_02.seg = trianglsCut4Seg;
  gfx_02.ofs = trianglsCut4Ofs;
  dst.seg = 0xa000;
  dst.ofs = rowOfs;
  ovr_blitLoadRleGfx(gfx_02,dst,(char)rowOfs);
  ovr_ovc40_flushInput();
  GMenuFlag = 1;
L_uiReadString_0DC9:
  do {
    while( true ) {
      while ((((keyCode = uiReadKey2(), 0x1f < (keyCode & 0xff) && ((keyCode & 0xff) < 0x7f)) &&
              (bStack_5 < 0x4f)) && ((keyCode & 0xff) != 0x40))) {
        (&text)[bStack_5] = (uint8_t)keyCode;
        (&uStack_5b)[bStack_5] = 0;
        textW = ovr_font_textWidth((char *)&text,(char *)CONCAT13((char)(Font03.ofs >> 8),
                                                    CONCAT12((char)Font03.ofs,_SS)),(char)Font03.ofs,Font03.seg,0);
        underscoreW = ovr_font_textWidth((char *)"_",(char *)CONCAT22(Font03.ofs,(char *)0x26510),(char)Font03.seg,0,0);
        if (textW + underscoreW + 0x2aU < 0xe0) {
          bStack_5 = bStack_5 + 1;
        }
        (&text)[bStack_5] = 0x0;
        gfx_00.seg = (uint16_t)&text;
        gfx_00.ofs = rowSegHi;
        saveui_usesBlitGfx10
                  (gfx_00,(char *)CONCAT22(&cursorX,_SS),(byte *)CONCAT22(row,_SS),
                   (uint *)uStack_5e,in_stack_0000ffa6);
      }
      if (keyCode != 0x4b00) break;
L_uiReadString_0ECE:
      if (bStack_5 != 0) {
        bStack_5 = bStack_5 - 1;
        (&text)[bStack_5] = 0x0;
        gfx_01.seg = (uint16_t)&text;
        gfx_01.ofs = rowSegHi;
        saveui_usesBlitGfx10
                  (gfx_01,(char *)CONCAT22(&cursorX,_SS),(byte *)CONCAT22(row,_SS),
                   (uint *)uStack_5e,in_stack_0000ffa6);
      }
    }
    if (keyCode < 0x4b01) {
      if (keyCode == 0x11b) {
        UserWantsExit = 1;
L_uiReadString_1068:
        inputCancelled = 1;
        handle_03.seg = rowSegHi;
        handle_03.ofs = (uint16_t)pfVar2;
        ovr_stshFree(handle_03);
        if (gfxOfs != (char *)0x0 || gfxSeg != 0) {
          handle_04.seg = gfxSeg;
          handle_04.ofs = (uint16_t)gfxOfs;
          ovr_stshFree(handle_04);
        }
        GMenuFlag = 0;
        return (char *)0x0;
      }
      if (keyCode == 0xe08) goto L_uiReadString_0ECE;
      if (keyCode == 0x1c0d) goto L_uiReadString_0FF7;
      goto L_uiReadString_0DC9;
    }
    if (keyCode == 0x4b34) goto L_uiReadString_0ECE;
    if (keyCode == 0xfffe) goto L_uiReadString_1068;
    if (keyCode == 0xffff) {
      if (((MouseMoved == 0) && (8 < MouseX)) &&
         ((MouseX < 0x19 && ((0xb4 < MouseY && ((MouseY < 0xb6 | 0xeU) != 0)))))) {
        inputCancelled = 1;
        handle.seg = rowSegHi;
        handle.ofs = (uint16_t)pfVar2;
        ovr_stshFree(handle);
        if (gfxOfs != (char *)0x0 || gfxSeg != 0) {
          handle_00.seg = gfxSeg;
          handle_00.ofs = (uint16_t)gfxOfs;
          ovr_stshFree(handle_00);
        }
        GMenuFlag = 0;
        return (char *)0x0;
      }
      if ((((MouseMoved == 0) && (0x15 < MouseX)) && (MouseX < 0x26)) &&
         ((row * 0xf + 0x1aU <= MouseY && (MouseY <= row * 0xf + 0x28U)))) {
L_uiReadString_0FF7:
        handle_01.seg = rowSegHi;
        handle_01.ofs = (uint16_t)pfVar2;
        ovr_stshFree(handle_01);
        GMenuFlag = 0;
        if (bStack_5 == 0) {
          if (gfxOfs != (char *)0x0 || gfxSeg != 0) {
            handle_02.seg = gfxSeg;
            handle_02.ofs = (uint16_t)gfxOfs;
            ovr_stshFree(handle_02);
          }
          pcVar6 = (char *)0x0;
        }
        else {
          puVar10 = &text;
          uVar9 = 0;
          puVar7 = ovr_stshRealloc((uint32_t)CONCAT22(gfxSeg,gfxOfs),(ulong)(bStack_5 + 1));
          pcVar6 = strcpy((char *)CONCAT22(uVar9,puVar7),(char *)CONCAT22(_SS,puVar10));
        }
        return pcVar6;
      }
    }
  } while( true );
}


/* 4528:10a8 */

uint16_t __cdecl16far uiMenu(char far *title,far_t items,uint16_t nitems)

{
  /* Re-derived from 4528:10a8 (29 bytes, 13 instructions, no locals): a pure argument shuffle that
     forwards its three arguments to uiMenuSub with defopt = 1 and returns the result in AX
     (`pop bp / retf` leaves AX alone, so the return type is not void). */
  return (uint16_t)uiMenuSub(title,items,nitems,1);
}



/* 4528:10c5 */

/* Writes a text line followed by CRLF to a file handle. */

void __cdecl16far saveui_writeLine(int handle,char *text,int count)

{
  size_t len;
  
  if (text != (char *)0x0 || count != 0) {
    len = strlen((char *)CONCAT22(count,text));
    write(handle,(char *)CONCAT22(count,text),len);
  }
  write(handle,"\r\n",2);
  return;
}



/* 4528:1104 */

/* Reads one line from the file and returns a heap copy (empty for ^Z/empty lines). */

char * __cdecl16far saveui_readLine(int fd)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  uint unaff_DI;
  uint8_t *src;
  uint8_t lineBuf;
  
  iVar3 = 0;
  while (iVar3 < 0x4f) {
    iVar2 = read(fd,(void *)CONCAT22(1,_SS),unaff_DI);
    if ((iVar2 != 1) || ((&lineBuf)[iVar3] == 0xa)) break;
    if ((&lineBuf)[iVar3] != 0xd) {
      iVar3 = iVar3 + 1;
    }
  }
  if (lineBuf == 0x1a) {
    iVar3 = 0;
  }
  (&lineBuf)[iVar3] = 0x0;
  if (iVar3 == 0) {
    pcVar1 = (char *)0x0;
  }
  else {
    src = (uint8_t *)CONCAT22(_SS,&lineBuf);
    iVar2 = iVar3 + 1 >> 0xf;
    pcVar1 = ovr_stshAlloc((long)(iVar3 + 1));
    pcVar1 = strcpy((char *)CONCAT22(iVar2,pcVar1),(char *)src);
  }
  return pcVar1;
}



/* 4528:1175 */
uint __cdecl16far saveui_readSavesList(int entries,uint16_t entriesSeg)

{
  char *path;
  char *linePtr;
  int fd;
  uint16_t lineOfs;
  uint16_t in_DX;
  uint16_t lineSeg;
  uint16_t *entryPtr;
  uint entryIdx;
  far_t handle;
  uint16_t entryCount;
  
  entryCount = 0;
  path = ovr_fmVsprintf("%ssaves.txt",&GWorkDir);
  fd = ovr_open_wait_unlock_and_disk(path,0);
  if (-1 < fd) {
    linePtr = (char *)saveui_readLine(fd);
    lineSeg = in_DX;
    entryCount = _atol((char *)CONCAT22(in_DX,linePtr));
    handle.seg = in_DX;
    handle.ofs = (uint16_t)linePtr;
    ovr_stshFree(handle);
    for (entryIdx = 0; entryIdx < entryCount; entryIdx = entryIdx + 1) {
      lineOfs =(uint16_t)( saveui_readLine(fd));
      entryPtr = (uint16_t *)(entries + entryIdx * 4);
      entryPtr[1] = lineSeg;
      *entryPtr = lineOfs;
    }
    close(fd);
  }
  return entryCount;
}


/* 4528:120d */

/* Writes the save-slot list to saves.txt (count line plus one line per entry). */

void __cdecl16far saveui_writeSavesList(far_t entries,uint count)

{
  char *path;
  int handle;
  uint16_t in_DX;
  uint16_t *puVar1;
  uint uVar2;
  static char msg[64];   /* DGROUP-backed formatting buffer */
  
  path = ovr_fmVsprintf("%ssaves.txt",&GWorkDir);
  handle = ovr_creat_wait_unlock_and_disk(path,in_DX);
  if (-1 < handle) {
    sprintf(msg,"%u");
    saveui_writeLine(handle,msg,_SS);
    for (uVar2 = 0; uVar2 < count; uVar2 = uVar2 + 1) {
      puVar1 = (uint16_t *)(entries.ofs + uVar2 * 4);
      saveui_writeLine(handle,(char *)*puVar1,puVar1[1]);
    }
    close(handle);
  }
  return;
}



/* 4528:1288 */

/* Frees and clears a list of heap lines. */

void __cdecl16far saveui_freeLines(far_t entries,uint count)

{
  /* Re-derived: frees every non-empty entry of the far handle array and clears it;
     entries equal to GSPEmpty are shared and only cleared. */
  int cmpResult;
  uint16_t entriesOfs;
  int *entryI;
  uint16_t *entryW;
  uint entryIdx;
  far_t handle;

  entriesOfs = entries.ofs;
  for (entryIdx = 0; entryIdx < count; entryIdx = entryIdx + 1) {
    entryI = (int *)(entriesOfs + entryIdx * 4);
    if (*entryI != 0 || entryI[1] != 0) {
      entryW = (uint16_t *)(entriesOfs + entryIdx * 4);
      cmpResult = strcmp((char *)CONCAT22(entryW[1],(char *)*entryW),
                         (char *)CONCAT22(GSPEmpty.seg,GSPEmpty.ofs));
      if (cmpResult != 0) {
        handle.seg = entryW[1];
        handle.ofs = *entryW;
        ovr_stshFree(handle);
      }
    }
    entryW = (uint16_t *)(entriesOfs + entryIdx * 4);
    entryW[1] = 0;
    *entryW = 0;
  }
  return;
}



/* 4528:1303 */

/* "Change message delay" screen: shows the current delay and a four-entry menu (decrease /
   increase / test / done) until the user leaves.  Re-derived from the image; the former body
   carried 430 lines and 32 calls for a 210-byte function. */

char * __cdecl16far saveui_configureMessageDelay(void)

{
  uint8_t done;
  uint8_t choice;
  far_t list;
  far_t items[4];
  char far *msg;

  done = 0;
  GMenuItem = 1;
  while (done == 0) {
    ovr_resetTextBlitCycle();
    saveui_blitPanel();
    msg = (char far *)
          ovr_fmVsprintf((char far *)MK_FP(_DS,(uint16_t)"Message delay is now %d."),
                         (uint16_t)MessageDelay);
    ovr_say(msg);
    items[0].ofs = 0;
    items[0].seg = 0;
    if (MessageDelay != 0) {
      items[0].ofs = (uint16_t)"Decrease message delay";
      items[0].seg = _DS;
    }
    items[1].ofs = 0;
    items[1].seg = 0;
    if (MessageDelay < 0x28) {
      items[1].ofs = (uint16_t)"Increase message delay";
      items[1].seg = _DS;
    }
    items[2].ofs = (uint16_t)"Test";
    items[2].seg = _DS;
    items[3].ofs = (uint16_t)"Done";
    items[3].seg = _DS;
    list.ofs = (uint16_t)&items;
    list.seg = _SS;
    choice = (uint8_t)
             uiMenuSub((char far *)MK_FP(_DS,(uint16_t)"Change message delay:"),
                       list,4,GMenuItem);
    switch (choice) {
    case 1:
      if (MessageDelay != 0) {
        MessageDelay = MessageDelay - 1;
      }
      break;
    case 2:
      if (MessageDelay < 0x28) {
        MessageDelay = MessageDelay + 1;
      }
      break;
    case 3:
      ovr_resetTextBlitCycle();
      msg = (char far *)
            ovr_fmVsprintf((char far *)MK_FP(_DS,(uint16_t)"This message appears at the message delay of %d."),
                           (uint16_t)MessageDelay);
      ovr_say(msg);
      ovr_say((char far *)MK_FP(_DS,(uint16_t)("")));
      break;
    default:
      done = 1;
      break;
    }
  }
  return (char *)(uint)done;
}


/* 4528:144e */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far saveui_usesBlitLoadRleGfx4(void)

{
  far_t gfx;
  
  gfx.seg = FontHandle.seg;
  gfx.ofs = FontHandle.ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)),0);
  return;
}



/* 4528:1470 */

/* Blits the "Cancel" label at its fixed position in Font03. */

void __cdecl16far saveui_drawCancel(void)

{
  saveui_usesBlitLoadRleGfx4();
  TextBlitX = 0x1d;
  TextBlitY = 0xb7;
  ovr_blitText((char *)"Cancel",(byte *)CONCAT22(Font03.ofs,(char *)0x26510),Font03.seg,
               0xcf,0xf);
  return;
}



/* 4528:14b1 */
void __cdecl16far uiMainMenuLoop(void)

{
  far_t gfx;
  far_t items;
  far_t items_00;
  far_t items_01;
  far_t items_02;
  far_t items_03;
  far_t items_04;
  far_t items_05;
  far_t entries;
  far_t entries_00;
  far_t entries_01;
  far_t entries_02;
  far_t entries_03;
  far_t entries_04;
  far_t dst;
  far_t dst_00;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  bool changed;
  bool again;
  uint16_t emptyOfs;
  uint16_t emptySeg;
  byte slotNo;
  char hasLast;
  void far *entries_05;
  far_t far *saves;
  uint16_t savesSeg;
  uint16_t pmenu;
  uint16_t slotWord;
  uint16_t ssVal;
  int cmpResult;
  char *yesnoSel;
  char *entryName;
  char *title;
  uint16_t segCopy;
  uint16_t ofsCopy;
  uint far *puVar11;
  uint16_t far *slotPtr;
  uint16_t far *clearPtr;
  int far *lastSlotPtr;
  uint saveCount;
  uint saveIndex;
  uint lastIndex;
  uint16_t saveOk;
  uint16_t menuCount;
  char far *menu[8];   /* 8 far string pointers = 0x20 bytes; the frame is sub sp,0x32 */
  uint16_t saveMenuOfs;
  uint16_t saveMenuSeg;
  uint16_t beginMenuOfs;
  uint16_t beginMenuSeg;
  byte pmenuIdx;
  char yesno [9];
  
  far_t src;

  dst.seg = _SS;
  dst.ofs = (uint16_t)&menu;
  src.seg = _DS;
  src.ofs = (uint16_t)&GMenuStrings;
  F_SCOPY(src,dst,32);
  dst_00.seg = _SS;
  dst_00.ofs = (uint16_t)yesno;
  src.seg = _DS;
  src.ofs = (uint16_t)&GYesNo;
  F_SCOPY(src,dst_00,8);
  ovr_say((char *)"Stronghold V 1.00",_DS);
  gfx.seg = GMenuGfxSeg;
  gfx.ofs = GMenuGfxOfs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa00009af)),0);
  ovr_stats_drawStatsPanel();
  saveui_blitPanel();
  entries_05 = ovr_stshAlloc(400);
  savesSeg = SEG_OF(entries_05);
  saves = (far_t far *)entries_05;
  segCopy = savesSeg;
  _fsetmem(MK_FP(savesSeg,far_ofs_u32(entries_05)),400,0);
  saveCount = 0;
  again = false;
  do {
    if (SaveAuto == '\0') {
      saveMenuSeg = 0;
      saveMenuOfs = 0;
    }
    else {
      saveMenuSeg = _DS;
      saveMenuOfs = (uint16_t)"Save Game";
    }
    if ((GGameInProgress == '\0') && (SaveAuto != '\0')) {
      beginMenuSeg = _DS;
      beginMenuOfs = (uint16_t)"Begin Play";
    }
    else {
      beginMenuSeg = 0;
      beginMenuOfs = 0;
    }
    pmenu = (uint16_t)&menu;
    items.seg = _SS;
    items.ofs = pmenu;
    pmenuIdx = (byte)uiMenu((char far *)"Select an option:",items,8);
    ovr_say((char *)0x26832,0x2410);
    if (pmenuIdx < 9) {
                    /* WARNING: Switch is manually overridden */
      switch((uint32_t)
             *(uint16_t *)((char *)0x25bd6 + (uint)pmenuIdx * 2)) {
      case 288826:
        saveui_blitPanel();
        changed = false;
        if ((SaveAuto == '\0') || (GWantsExit2 == '\0')) {
          changed = true;
        }
        else {
          yesnoSel = yesno;
          items_00.seg = _SS;
          items_00.ofs = (uint16_t)yesnoSel;
          uiMenu((char far *)"Game not saved: Are you sure?",items_00,2);
          if ((char)yesnoSel == '\x01') {
            changed = true;
          }
        }
        saveui_blitPanel();
        if (changed) {
          ovr_copyProtectionCheck();
          saveui_configureNewWorld();
        }
        break;
      case 288917:
        saveui_blitPanel();
        entries.seg = savesSeg;
        entries.ofs = far_ofs_u32(entries_05);
        saveui_freeLines(entries,saveCount);
        saveCount = saveui_readSavesList((int)far_ofs_u32(entries_05),savesSeg);
        slotWord = saveCount;
        for (saveIndex = 0; emptySeg = GSPEmpty.seg, emptyOfs = GSPEmpty.ofs, saveIndex < saveCount;
            saveIndex = saveIndex + 1) {
          puVar11 = (uint far *)&saves[saveIndex];
          slotWord = *puVar11 | puVar11[1];
          if (slotWord == 0) {
            slotPtr = (uint16_t far *)&saves[saveIndex];
            slotPtr[1] = GSPEmpty.seg;
            *slotPtr = emptyOfs;
            slotWord = emptySeg;
            ofsCopy = emptyOfs;
          }
        }
        if (saveCount < 100) {
          slotPtr = (uint16_t far *)&saves[saveCount];
          slotPtr[1] = GSPEmpty.seg;
          *slotPtr = emptyOfs;
          slotWord = emptySeg;
          ofsCopy = emptyOfs;
        }
        slotNo = (byte)slotWord;
        saveCount = saveCount + 1;
        saveui_drawCancel();
        items_01.seg = savesSeg;
        items_01.ofs = far_ofs_u32(entries_05);
        uiMenu((char far *)"Save Game:",items_01,saveCount);
        saveui_usesBlitLoadRleGfx4();
        if (slotNo != 0) {
          cmpResult = strcmp((char *)CONCAT22(saves[(uint)slotNo - 1].seg,
                                          (char *)saves[(uint)slotNo - 1].ofs),
                         (char *)CONCAT22(GSPEmpty.seg,GSPEmpty.ofs));
          if (cmpResult == 0) {
            saveui_blitPanel();
            saveui_drawCancel();
            entryName = uiReadString((char *)"Name this save:  (Esc to cancel)",_DS,0,(char *)0x0,0,0)
            ;
            saves[(uint)slotNo - 1].seg = segCopy;
            saves[(uint)slotNo - 1].ofs =(uint16_t)( entryName);
            saveui_usesBlitLoadRleGfx4();
          }
          else {
            saveui_blitPanel();
            saveui_drawCancel();
            entryName = uiReadString((char *)"Name for this save:  (Esc to cancel)",_DS,0,(char *)saves[(uint)slotNo - 1].ofs,saves[(uint)slotNo - 1].seg,0);
            saves[(uint)slotNo - 1].seg = segCopy;
            saves[(uint)slotNo - 1].ofs =(uint16_t)( entryName);
            saveui_usesBlitLoadRleGfx4();
          }
          if ((saves[(uint)slotNo - 1].ofs != 0 ||
               saves[(uint)slotNo - 1].seg != 0) &&
             (cmpResult = strcmp((char *)CONCAT22(saves[(uint)slotNo - 1].seg,
                                              (char *)saves[(uint)slotNo - 1].ofs),
                             (char *)CONCAT22(GSPEmpty.seg,GSPEmpty.ofs)), cmpResult == 0)) {
            handle.seg = saves[(uint)slotNo - 1].seg;
            handle.ofs = saves[(uint)slotNo - 1].ofs;
            ovr_stshFree(handle);
            saves[(uint)slotNo - 1].seg = 0;
            saves[(uint)slotNo - 1].ofs = 0;
          }
          if (saves[(uint)slotNo - 1].ofs != 0 ||
              saves[(uint)slotNo - 1].seg != 0) {
            saveOk = ovr_stSave();
            if ((char)saveOk == '\0') {
              saves[(uint)slotNo - 1].seg = 0;
              saves[(uint)slotNo - 1].ofs = 0;
            }
            else {
              GWantsExit2 = '\0';
            }
            for (saveIndex = 0; saveIndex < saveCount; saveIndex = saveIndex + 1) {
              clearPtr = (uint16_t far *)&saves[saveIndex];
              cmpResult = strcmp((char *)CONCAT22(clearPtr[1],(char *)*clearPtr),
                             (char *)CONCAT22(GSPEmpty.seg,GSPEmpty.ofs));
              if (cmpResult == 0) {
                clearPtr = (uint16_t far *)&saves[saveIndex];
                clearPtr[1] = 0;
                *clearPtr = 0;
              }
            }
            while ((saveCount != 0 &&
                   (lastSlotPtr = (int far *)&saves[saveCount - 1],
                   *lastSlotPtr == 0 && lastSlotPtr[1] == 0))) {
              saveCount = saveCount - 1;
            }
            entries_00.seg = savesSeg;
            entries_00.ofs = far_ofs_u32(entries_05);
            saveui_writeSavesList(entries_00,saveCount);
          }
        }
        saveui_blitPanel();
        break;
      case 289563:
        saveui_blitPanel();
        entries_01.seg = savesSeg;
        entries_01.ofs = far_ofs_u32(entries_05);
        saveui_freeLines(entries_01,saveCount);
        saveCount = saveui_readSavesList((int)far_ofs_u32(entries_05),savesSeg);
        lastIndex = saveCount;
        saveui_drawCancel();
        hasLast = (char)lastIndex;
        items_02.seg = savesSeg;
        items_02.ofs = far_ofs_u32(entries_05);
        uiMenu((char far *)"Load Game:",items_02,saveCount);
        saveui_usesBlitLoadRleGfx4();
        if (hasLast != '\0') {
          changed = false;
          if ((SaveAuto == '\0') || (GWantsExit2 == '\0')) {
            changed = true;
          }
          else {
            saveui_blitPanel();
            yesnoSel = yesno;
            items_03.seg = _SS;
            items_03.ofs = (uint16_t)yesnoSel;
            uiMenu((char far *)"Game not saved: Are you sure?",items_03,2);
            if ((char)yesnoSel == '\x01') {
              changed = true;
            }
          }
          saveui_blitPanel();
          if (changed) {
            ovr_save_loadGameFile();
            GWantsExit2 = '\0';
          }
        }
        saveui_blitPanel();
        break;
      case 289727:
        saveui_blitPanel();
        entries_02.seg = savesSeg;
        entries_02.ofs = far_ofs_u32(entries_05);
        saveui_freeLines(entries_02,saveCount);
        saveCount = saveui_readSavesList((int)far_ofs_u32(entries_05),savesSeg);
        lastIndex = saveCount;
        saveui_drawCancel();
        slotNo = (byte)lastIndex;
        items_04.seg = savesSeg;
        items_04.ofs = far_ofs_u32(entries_05);
        uiMenu((char far *)"Delete Game:",items_04,saveCount);
        saveui_usesBlitLoadRleGfx4();
        if (slotNo != 0) {
          saveui_blitPanel();
          menuCount = 2;
          yesnoSel = yesno;
          ssVal = _SS;
          title = ovr_fmVsprintf("Delete %s: Are you sure?",
                                 (char *)CONCAT22(saves[(uint)slotNo - 1].seg,
                                                  (char *)saves[(uint)slotNo - 1].ofs)
                                );
          items_05.seg = (uint16_t)yesnoSel;
          items_05.ofs = ofsCopy;
          uiMenu(title,items_05,menuCount);
          if ((char)title == '\x01') {
            ovr_save_deleteGameFile();
            handle_00.seg = saves[(uint)slotNo - 1].seg;
            handle_00.ofs = saves[(uint)slotNo - 1].ofs;
            ovr_stshFree(handle_00);
            saves[(uint)slotNo - 1].seg = 0;
            saves[(uint)slotNo - 1].ofs = 0;
            while ((saveCount != 0 &&
                   (lastSlotPtr = (int far *)&saves[saveCount - 1],
                   *lastSlotPtr == 0 && lastSlotPtr[1] == 0))) {
              saveCount = saveCount - 1;
            }
          }
        }
        entries_03.seg = savesSeg;
        entries_03.ofs = far_ofs_u32(entries_05);
        saveui_writeSavesList(entries_03,saveCount);
        saveui_blitPanel();
        break;
      case 289977:
        saveui_blitPanel();
        if (SaveAuto != '\0') {
          ovr_stSave();
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0);
      case 290016:
        saveui_configureMessageDelay();
        saveui_blitPanel();
        break;
      case 290026:
        ovr_ovc38_showAchievements();
        break;
      case 290033:
        if ((GGameInProgress == '\0') && (SaveAuto != '\0')) {
          again = true;
        }
      }
    }
  } while ((SaveAuto == '\0') || (!again));
  entries_04.seg = savesSeg;
  entries_04.ofs = far_ofs_u32(entries_05);
  saveui_freeLines(entries_04,saveCount);
  handle_01.seg = savesSeg;
  handle_01.ofs = far_ofs_u32(entries_05);
  ovr_stshFree(handle_01);
  ovr_ovc28_textHalflingCastle();
  return;
}


/* 4528:1ae8 */

/* WARNING: Variable defined which should be unmapped: worldItems */
/* Runs the new-world dialog (hostility, enemy intelligence, second-wave size) and starts the
   generated world. */

void __cdecl16far saveui_configureNewWorld(void)

{
  uint8_t *puVar1;
  far_t items;
  far_t items_00;
  far_t dst_00;
  far_t dst_01;
  far_t dst_02;
  uint8_t worldItems;
  int in_stack_0000ffae;
  uint8_t hostilityItems;
  uint8_t seedTable;
  uint16_t auStack_26 [3];
  uint8_t dst;
  char worldIdx;
  byte bStack_b;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  dst_00.seg = _SS;
  dst_00.ofs = (uint16_t)&dst;
  F_SCOPY(far_from_u32((uint32_t)(0x241026e3)),dst_00,20);
  dst_01.seg = _SS;
  dst_01.ofs = (uint16_t)&hostilityItems;
  F_SCOPY(far_from_u32((uint32_t)(0x241026f7)),dst_01,20);
  dst_02.seg = _SS;
  dst_02.ofs = (uint16_t)&worldItems;
  F_SCOPY(far_from_u32((uint32_t)(0x2410270b)),dst_02,32);
  puVar1 = &worldItems;
  items.seg = _SS;
  items.ofs = (uint16_t)puVar1;
  uiMenu((char far *)"Which new world:",items,0);
  bStack_b = (byte)puVar1;
  saveui_blitPanel();
  if ((bStack_b != 8) && (bStack_b != 0)) {
    if (bStack_b == 7) {
      SeedHi = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
      GSeed = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
    }
    else {
      if (bStack_b == 1) {
        ovr_save_loadArchiveGame();
        return;
      }
      SeedHi = auStack_26[(uint)bStack_b * 2];
      GSeed = *(uint16_t *)(&seedTable + (uint)bStack_b * 4);
    }
    srand8(CONCAT22(SeedHi,GSeed));
    worldIdx = bStack_b - 1;
    puVar1 = &hostilityItems;
    items_00.seg = _SS;
    items_00.ofs = (uint16_t)puVar1;
    uiMenu((char far *)"Hostility level:",items_00,0);
    bStack_b = (byte)puVar1;
    saveui_blitPanel();
    if ((bStack_b != '\x05') && (bStack_b != '\0')) {
      if (bStack_b == '\x04') {
        iStack_a = saveui_usesBlitText((char *)&__C0_ASM_CopyRight[2],worldItems,in_stack_0000ffae);
        saveui_blitPanel();
        if (iStack_a < 0) {
          if (inputCancelled != '\0') {
            return;
          }
          iStack_a = 0;
        }
        iStack_8 = saveui_usesBlitText((char *)&__C0_ASM_CopyRight[2],worldItems,in_stack_0000ffae);
        saveui_blitPanel();
        if (iStack_8 < 0) {
          if (inputCancelled != '\0') {
            return;
          }
          iStack_8 = 0;
        }
        iStack_6 = saveui_usesBlitText((char *)&__C0_ASM_CopyRight[2],worldItems,in_stack_0000ffae);
        saveui_blitPanel();
        if (iStack_6 < 0) {
          if (inputCancelled != '\0') {
            return;
          }
          iStack_6 = 0;
        }
        iStack_4 = saveui_usesBlitText((char *)&__C0_ASM_CopyRight[2],worldItems,in_stack_0000ffae);
        saveui_blitPanel();
        if (iStack_4 < 0) {
          if (inputCancelled != '\0') {
            return;
          }
          iStack_4 = 0;
        }
        if (0x3c < iStack_a + iStack_8 + iStack_6 + iStack_4) {
          ovr_say((char *)"Too many enemies. 60 enemies maximum.",0);
          return;
        }
        lowIntelEnemies[0] = (uint8_t)iStack_a;
        medIntelEnemies[0] = (uint8_t)iStack_8;
        highIntelEnemies[0] = (uint8_t)iStack_6;
        secondWaveSize[0] = (uint8_t)iStack_4;
      }
      Difficulty = bStack_b;
      worldIndex = worldIdx;
      ovr_say((char *)"Resetting game...",0);
      ovr_init_usesClearEntities();
      ovr_say((char *)"New world complete.",0);
    }
  }
  return;
}



/* 4528:1d0f */

/* Parses the decimal digits of a string into an integer (skipping non-digits) and returns the
   accumulated value. */

int __cdecl16far saveui_parseNumber(char *str)

{
  int iVar1;
  
  iVar1 = 0;
  while (*str != '\0') {
    if ((((byte *)_ctype + 1)[*str] & 2) != 0) {
      iVar1 = (int)*str + iVar1 * 10 + -0x30;
    }
    str = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(str) + 2)),(char *)str + 1);
  }
  return iVar1;
}



/* 4528:1d55 */
int __cdecl16far saveui_usesBlitText(char *prompt,int textSeg,int row)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t handle;
  far_t handle_00;
  uint ey;
  far_t far *pfVar1;
  int underscoreW;
  int iVar3;
  uint16_t rowOfs;
  uint16_t unaff_SI;
  char *in_stack_00000004;
  uint3 uStack_5e;
  uint8_t text;
  undefined1 uStack_5b;
  int in_stack_0000ffa6;
  uint8_t cursorX;
  byte bStack_5;
  uint16_t keyCode;
  
  uStack_5e = (uint16_t)CONCAT22(text,unaff_SI);
  inputCancelled = 0;
  if (in_stack_00000004 != (char *)0x0 || (char *)prompt != (char *)0x0) {
    TextBlitX = 0x16;
    TextBlitY = 0xb;
    ovr_blitText(in_stack_00000004,(byte *)CONCAT22(Font03.ofs,(char *)prompt),Font03.seg,0xde,0xde,
                 7);
  }
  bStack_5 = 0;
  ey = (uint)uStack_5e;
  uStack_5e = (uint3)(uint)uStack_5e;
  rowOfs = (uint16_t)((ulong)((long)(*(uint16_t *)((uint8_t *)&(prompt) + 2)) * 0xf) >> 0x10);
  pfVar1 = ovr_stshRleCut((far_t far *)0x0,far_from_u32((uint32_t)(0x16a000)),(int)((long)(*(uint16_t *)((uint8_t *)&(prompt) + 2)) * 0xf) + 0x1d,222,(*(uint16_t *)((uint8_t *)&(prompt) + 2)) * 0xf + 0x27,ey,0xde,0,0);
  TextBlitX = 0x2a;
  TextBlitY = (*(uint16_t *)((uint8_t *)&(prompt) + 2)) * 0xf + 0x1d;
  cursorX = 0;
  gfx.seg = (uint16_t)&text;
  gfx.ofs = rowOfs;
  saveui_usesBlitGfx10
            (gfx,(char *)CONCAT22(&cursorX,_SS),(byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(prompt) + 2)),_SS),
             (uint *)uStack_5e,in_stack_0000ffa6);
  ovr_ovc40_flushInput();
L_saveui_4528_1d55_1E1D:
  do {
    while( true ) {
      while ((keyCode = uiReadKey2(), (((byte *)_ctype + 1)[keyCode & 0xff] & 2) != 0 &&
             (bStack_5 < 2))) {
        (&text)[bStack_5] = (uint8_t)keyCode;
        (&uStack_5b)[bStack_5] = 0;
        iVar3 = ovr_font_textWidth((char *)&text,(char *)CONCAT13((char)(Font03.ofs >> 8),
                                                    CONCAT12((char)Font03.ofs,_SS)),(char)Font03.ofs,Font03.seg,0);
        underscoreW = ovr_font_textWidth((char *)"_",(char *)CONCAT22(Font03.ofs,(char *)0x26510),(char)Font03.seg,0,0);
        if (iVar3 + underscoreW + 0x2aU < 0xe0) {
          bStack_5 = bStack_5 + 1;
        }
        (&text)[bStack_5] = 0x0;
        gfx_00.seg = (uint16_t)&text;
        gfx_00.ofs = rowOfs;
        saveui_usesBlitGfx10
                  (gfx_00,(char *)CONCAT22(&cursorX,_SS),
                   (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(prompt) + 2)),_SS),(uint *)uStack_5e,in_stack_0000ffa6);
      }
      if (keyCode != 0x4b00) break;
L_saveui_4528_1d55_1F0C:
      if (bStack_5 != 0) {
        bStack_5 = bStack_5 - 1;
        (&text)[bStack_5] = 0x0;
        gfx_01.seg = (uint16_t)&text;
        gfx_01.ofs = rowOfs;
        saveui_usesBlitGfx10
                  (gfx_01,(char *)CONCAT22(&cursorX,_SS),
                   (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(prompt) + 2)),_SS),(uint *)uStack_5e,in_stack_0000ffa6);
      }
    }
    if (0x4b00 < keyCode) {
      if (keyCode == 0x4b34) goto L_saveui_4528_1d55_1F0C;
      if (keyCode == 0xfffe) {
L_saveui_4528_1d55_1F83:
        inputCancelled = 1;
        handle_00.seg = rowOfs;
        handle_00.ofs = (uint16_t)pfVar1;
        ovr_stshFree(handle_00);
        return 0xffff;
      }
      if ((keyCode == 0xffff) && (MouseMoved == 0)) goto L_saveui_4528_1d55_1F59;
      goto L_saveui_4528_1d55_1E1D;
    }
    if (keyCode == 0x11b) goto L_saveui_4528_1d55_1F83;
    if (keyCode == 0xe08) goto L_saveui_4528_1d55_1F0C;
    if (keyCode == 0x1c0d) {
L_saveui_4528_1d55_1F59:
      handle.seg = rowOfs;
      handle.ofs = (uint16_t)pfVar1;
      ovr_stshFree(handle);
      if (bStack_5 == 0) {
        iVar3 = -1;
      }
      else {
        iVar3 = saveui_parseNumber((char *)CONCAT22(_SS,&text));
      }
      return iVar3;
    }
  } while( true );
}

