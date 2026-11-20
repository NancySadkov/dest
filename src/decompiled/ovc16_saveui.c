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
  bool bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint16_t uVar5;
  undefined1 extraout_AH;
  int iStack_8;
  int iStack_6;
  
  MiceUnkState = 0;
  ovr_ovr_miceButton0PressStates_entry();
  MiceProcessed = 0;
  ovr_miceBlitRect((brect_t *)(BlitRects + 1));
  iVar3 = MouseY;
  iVar2 = MouseX;
  bVar1 = false;
  MouseMoved = 0;
  while( true ) {
    if ((*(int *)(BDA_DailyTimeCounter.ofs + 2) != iStack_6) ||
       (*(int *)BDA_DailyTimeCounter != iStack_8)) {
      iStack_6 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
      iStack_8 = *(int *)BDA_DailyTimeCounter;
      ovr_draw_usesBlitLoadRleGfx();
      ovr_ovc13_usesMiceBlitRect();
    }
    uVar5 = ovr_biosKeyAvail();
    if ((char)uVar5 != '\0') break;
    bVar4 = ovr_init2_usesCFGMice((uint16_t *)&MouseX,(uint16_t *)((char *)"puppetmaker" + 3));
    if (CONCAT11(extraout_AH,bVar4) == 0) {
      bVar1 = true;
    }
    else if (((bVar1) || (MouseX != iVar2)) || (MouseY != iVar3)) {
      if (!bVar1) {
        MouseMoved = 1;
      }
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
      MouseBkgPixel = *(undefined1 *)(MouseY * 0x140 + MouseX);
      ovr_draw_usesBlitLoadRleGfx2();
      ovr_resetTextBlitCycle();
      return 0xffff;
    }
    if (rightButtonLatch != '\0') {
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
      MouseBkgPixel = *(undefined1 *)(MouseY * 0x140 + MouseX);
      ovr_draw_usesBlitLoadRleGfx2();
      ovr_resetTextBlitCycle();
      return 0xfffe;
    }
  }
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
  ovr_draw_usesBlitLoadRleGfx2();
  ovr_resetTextBlitCycle();
  uVar5 = ovr_gameProcessKey();
  return uVar5;
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



/* 4528:02fb */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far saveui_usesBlitLoadRleGfx2(far_t textTable,int rowIndex,int itemOffset)

{
  undefined2 *puVar1;
  uint16_t uVar2;
  far_t gfx;
  far_t gfx_00;
  far_t dst;
  far_t dst_00;
  
  dst.seg = 0xa000;
  dst.ofs = rowIndex * 0x12c0 + 0x2096;
  gfx.seg = trianglsCut3Seg;
  gfx.ofs = trianglsCut3Ofs;
  ovr_blitLoadRleGfx(gfx,dst);
  TextBlitX = 0x2a;
  TextBlitY = rowIndex * 0xf + 0x1d;
  uVar2 = textTable.seg;
  puVar1 = (undefined2 *)(textTable.ofs + (rowIndex + itemOffset) * 4);
  ovr_blitText((char *)*puVar1,(byte *)puVar1[1],Font03.ofs,(uint8_t)Font03.seg);
  ovr_ovc28_usesBDADailyTimeCounter(3);
  dst_00.seg = 0xa000;
  dst_00.ofs = rowIndex * 0x12c0 + 0x2096;
  gfx_00.seg = trianglsCut4Seg;
  gfx_00.ofs = trianglsCut4Ofs;
  ovr_blitLoadRleGfx(gfx_00,dst_00);
  TextBlitX = 0x2a;
  TextBlitY = rowIndex * 0xf + 0x1d;
  puVar1 = (undefined2 *)(textTable.ofs + (rowIndex + itemOffset) * 4);
  ovr_blitText((char *)*puVar1,(byte *)puVar1[1],Font03.ofs,(uint8_t)Font03.seg);
  return;
}



/* 4528:0404 */

/* [R6] touches MouseMoved, MouseX */

undefined2 __cdecl16far saveui_usesMouseMoved(far_t textTable,int rowLimit,int itemOffset)

{
  undefined2 uVar1;
  uint uVar2;
  uint rowIndex;
  int *piVar3;
  char cStack_4;
  
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
        cStack_4 = (char)rowIndex;
        GMenuItem = cStack_4 + '\x01';
        return CONCAT11(0x24,cStack_4 + '\x01');
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
  ovr_blitGfxRect(gfx,0,0,(brect_t *)(BlitRects + 1),0x10,true);
  return;
}



/* 4528:055b */

/* [R4] calls ovr_blitGfx10 */

void __cdecl16far saveui_usesBlitGfx10(far_t gfx,char *text,byte *widths,uint *cursorX,int row)

{
  far_t dst;
  undefined2 unaff_SS;
  int in_stack_00000010;
  undefined1 uVar1;
  undefined1 uVar2;
  uint8_t rect;
  int iStack_a;
  int iStack_6;
  
  uVar1 = (undefined1)unaff_SS;
  uVar2 = (undefined1)((uint)unaff_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = uVar1;
  dst.ofs = (uint16_t)&rect;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar2;
  F_SCOPY(far_from_u32((uint32_t)(0x241026ad)),dst);
  _rect = *_cursorX;
  iStack_a = in_stack_00000010 * 0xf + 0x1d;
  iStack_6 = in_stack_00000010 * 0xf + 0x28;
  ovr_blitGfx10(gfx,0x16,in_stack_00000010 * 0xf + 0x1d,
                (brect_t *)CONCAT13(uVar2,CONCAT12(uVar1,&rect)),false);
  TextBlitX = 0x2a;
  TextBlitY = in_stack_00000010 * 0xf + 0x1d;
  ovr_blitText(text,widths,Font03.ofs,(uint8_t)Font03.seg);
  if (TextBlitX < *_cursorX) {
    _rect = TextBlitX;
    ovr_blitGfx10(gfx,0x16,in_stack_00000010 * 0xf + 0x1d,
                  (brect_t *)CONCAT13(uVar2,CONCAT12(uVar1,&rect)),false);
  }
  *_cursorX = TextBlitX;
  ovr_blitLetter('_',(byte *)Font03.ofs,(uint8_t)Font03.seg);
  return;
}



/* 4528:0664 */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far saveui_usesBlitLoadRleGfx3(far_t entries,int count)

{
  int *piVar1;
  undefined2 *puVar2;
  int iVar3;
  uint16_t uVar4;
  far_t gfx;
  far_t dst;
  
  for (iVar3 = 0; iVar3 < count; iVar3 = iVar3 + 1) {
    uVar4 = entries.seg;
    piVar1 = (int *)(entries.ofs + iVar3 * 4);
    if (*piVar1 != 0 || piVar1[1] != 0) {
      dst.seg = 0xa000;
      dst.ofs = iVar3 * 0x12c0 + 0x2096;
      gfx.seg = trianglsCut4Seg;
      gfx.ofs = trianglsCut4Ofs;
      ovr_blitLoadRleGfx(gfx,dst);
      TextBlitX = 0x2a;
      TextBlitY = iVar3 * 0xf + 0x1d;
      puVar2 = (undefined2 *)(entries.ofs + iVar3 * 4);
      ovr_blitText((char *)*puVar2,(byte *)puVar2[1],Font03.ofs,(uint8_t)Font03.seg);
    }
  }
  return;
}



/* 4528:0706 */

void __cdecl16far uiMenuSub(char *title,far_t items,uint16_t nitems,uint16_t defopt)

{
  far_t textTable;
  far_t textTable_00;
  far_t entries;
  far_t entries_00;
  far_t entries_01;
  far_t entries_02;
  byte bVar1;
  uint16_t uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined2 *puVar5;
  uint16_t unaff_SS;
  byte in_stack_0000000e;
  undefined1 uVar6;
  uint8_t dest;
  undefined2 auStack_26 [13];
  undefined2 uStack_c;
  undefined2 uStack_a;
  uint16_t sz;
  int iStack_6;
  uint8_t readed;
  byte bStack_3;
  
  TextBlitDstSeg = 0xa000;
  if (title != (char *)0x0 || items.ofs != 0) {
    TextBlitX = 0x16;
    TextBlitY = 0xb;
    ovr_blitText(title,(byte *)items.ofs,Font03.ofs,(uint8_t)Font03.seg);
  }
  iStack_6 = 0;
  if ((int)defopt < 9) {
    sz = defopt;
  }
  else {
    sz = 8;
  }
  for (readed = 0x0; (int)(uint)readed < (int)sz; readed = readed + 0x1) {
    puVar5 = (undefined2 *)(items.seg + (uint)readed * 4);
    uVar3 = *puVar5;
    uVar4 = (uint)readed;
    auStack_26[uVar4 * 2] = puVar5[1];
    *(undefined2 *)(&dest + uVar4 * 4) = uVar3;
  }
  if (8 < (int)defopt) {
    uStack_a = 0x2410;
    uStack_c = 0x2733;
  }
  entries.seg = unaff_SS;
  entries.ofs = (uint16_t)&dest;
  saveui_usesBlitLoadRleGfx3(entries,sz);
  GMenuItem = in_stack_0000000e;
  while (((int)(uint)GMenuItem <= (int)sz &&
         (*(int *)(&stack0xffd4 + (uint)GMenuItem * 4) == 0 &&
          *(int *)(&stack0xffd6 + (uint)GMenuItem * 4) == 0))) {
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
    while (uVar2 = uiReadKey2(), uVar2 == 0x5000) {
L_uiMenuSub_0903:
      do {
        GMenuItem = GMenuItem + 1;
        if ((int)sz < (int)(uint)GMenuItem) {
          GMenuItem = 0;
        }
      } while ((GMenuItem != 0) &&
              (*(int *)(&stack0xffd4 + (uint)GMenuItem * 4) == 0 &&
               *(int *)(&stack0xffd6 + (uint)GMenuItem * 4) == 0));
      saveui_startCrossBlit();
    }
    uVar6 = (undefined1)(unaff_SS >> 8);
    if (0x5000 < uVar2) {
      if (uVar2 != 0x5133) {
        if (0x5133 < uVar2) {
          if (uVar2 == 0xfffe) {
            GMenuFlag = 0;
            return;
          }
          if (uVar2 == 0xffff) {
            (*(uint8_t *)((uint8_t *)&(textTable.seg))) = (char)unaff_SS;
            textTable.ofs = (uint16_t)&dest;
            (*(uint8_t *)((uint8_t *)&(textTable.seg) + 1)) = uVar6;
            uVar3 = saveui_usesMouseMoved(textTable,sz,0);
            bStack_3 = (byte)uVar3;
            bVar1 = bStack_3;
            if (bStack_3 != 0xff) {
L_uiMenuSub_0B46:
              GMenuItem = bVar1;
              if (GMenuItem != 0) {
                (*(uint8_t *)((uint8_t *)&(textTable_00.seg))) = (char)unaff_SS;
                textTable_00.ofs = (uint16_t)&dest;
                (*(uint8_t *)((uint8_t *)&(textTable_00.seg) + 1)) = uVar6;
                saveui_usesBlitLoadRleGfx2(textTable_00,GMenuItem - 1,0);
              }
              if (((int)defopt < 9) || (GMenuItem != 8)) {
                GMenuFlag = 0;
                return;
              }
              if (iStack_6 + 7 < (int)defopt) {
                iStack_6 = iStack_6 + 7;
              }
              else {
                iStack_6 = 0;
              }
              _fsetmem(&dest,unaff_SS,0x1c);
              for (readed = 0x0; (readed < 7 && ((int)((uint)readed + iStack_6) < (int)defopt));
                  readed = readed + 0x1) {
                puVar5 = (undefined2 *)(items.seg + ((uint)readed + iStack_6) * 4);
                uVar3 = *puVar5;
                uVar4 = (uint)readed;
                auStack_26[uVar4 * 2] = puVar5[1];
                *(undefined2 *)(&dest + uVar4 * 4) = uVar3;
              }
              saveui_blitPanel();
              if (title != (char *)0x0 || items.ofs != 0) {
                TextBlitX = 0x16;
                TextBlitY = 0xb;
                ovr_blitText(title,(byte *)items.ofs,Font03.ofs,(uint8_t)Font03.seg);
              }
              entries_02.seg = unaff_SS;
              entries_02.ofs = (uint16_t)&dest;
              saveui_usesBlitLoadRleGfx3(entries_02,8);
              saveui_startCrossBlit();
            }
          }
          goto L_uiMenuSub_0840;
        }
        if (uVar2 == 0x5032) goto L_uiMenuSub_0903;
        if (uVar2 != 0x5100) goto L_uiMenuSub_0840;
      }
      if (8 < (int)defopt) {
        if (iStack_6 + 7 < (int)defopt) {
          iStack_6 = iStack_6 + 7;
        }
        else {
          iStack_6 = 0;
        }
        _fsetmem(&dest,unaff_SS,0x1c);
        for (readed = 0x0; (readed < 7 && ((int)((uint)readed + iStack_6) < (int)defopt));
            readed = readed + 0x1) {
          puVar5 = (undefined2 *)(items.seg + ((uint)readed + iStack_6) * 4);
          uVar3 = *puVar5;
          uVar4 = (uint)readed;
          auStack_26[uVar4 * 2] = puVar5[1];
          *(undefined2 *)(&dest + uVar4 * 4) = uVar3;
        }
        saveui_blitPanel();
        if (title != (char *)0x0 || items.ofs != 0) {
          TextBlitX = 0x16;
          TextBlitY = 0xb;
          ovr_blitText(title,(byte *)items.ofs,Font03.ofs,(uint8_t)Font03.seg);
        }
        entries_01.seg = unaff_SS;
        entries_01.ofs = (uint16_t)&dest;
        saveui_usesBlitLoadRleGfx3(entries_01,8);
        GMenuItem = 8;
        saveui_startCrossBlit();
      }
      goto L_uiMenuSub_0840;
    }
    if (uVar2 == 0x4838) {
L_uiMenuSub_08AD:
      do {
        GMenuItem = GMenuItem - 1;
        if (GMenuItem == 0xff) {
          GMenuItem = (byte)sz;
        }
      } while ((GMenuItem != 0) &&
              (*(int *)(&stack0xffd4 + (uint)GMenuItem * 4) == 0 &&
               *(int *)(&stack0xffd6 + (uint)GMenuItem * 4) == 0));
      saveui_startCrossBlit();
    }
    else if (uVar2 < 0x4839) {
      if (uVar2 == 0x11b) {
        GMenuFlag = 0;
        return;
      }
      bVar1 = GMenuItem;
      if (uVar2 == 0x1c0d) goto L_uiMenuSub_0B46;
      if (uVar2 == 0x4800) goto L_uiMenuSub_08AD;
    }
    else if (((uVar2 == 0x4900) || (uVar2 == 0x4939)) && (8 < (int)defopt)) {
      if (iStack_6 == 0) {
        iStack_6 = ((int)(defopt - 1) / 7) * 7;
      }
      else {
        iStack_6 = iStack_6 + -7;
      }
      _fsetmem(&dest,unaff_SS,0x1c);
      for (readed = 0x0; (readed < 7 && ((int)((uint)readed + iStack_6) < (int)defopt));
          readed = readed + 0x1) {
        puVar5 = (undefined2 *)(items.seg + ((uint)readed + iStack_6) * 4);
        uVar3 = *puVar5;
        uVar4 = (uint)readed;
        auStack_26[uVar4 * 2] = puVar5[1];
        *(undefined2 *)(&dest + uVar4 * 4) = uVar3;
      }
      saveui_blitPanel();
      if (title != (char *)0x0 || items.ofs != 0) {
        TextBlitX = 0x16;
        TextBlitY = 0xb;
        ovr_blitText(title,(byte *)items.ofs,Font03.ofs,(uint8_t)Font03.seg);
      }
      entries_00.seg = unaff_SS;
      entries_00.ofs = (uint16_t)&dest;
      saveui_usesBlitLoadRleGfx3(entries_00,8);
      GMenuItem = 8;
      saveui_startCrossBlit();
    }
  } while( true );
}



/* 4528:0c98 */

char * __cdecl16far uiReadString(char *textOfs,int textSeg,int row,char *gfxOfs,uint16_t gfxSeg)

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
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint8_t *dst_00;
  uint16_t uVar5;
  int16_t unaff_SI;
  byte *unaff_SS;
  uint8_t text;
  undefined1 auStack_5b [79];
  far_t *pfStack_c;
  uint16_t uStack_a;
  uint8_t cursorX;
  byte bStack_5;
  uint16_t uStack_4;
  
  UserWantsExit = 0;
  inputCancelled = 0;
  if (textOfs != (char *)0x0 || textSeg != 0) {
    TextBlitX = 0x16;
    TextBlitY = 0xb;
    ovr_blitText(textOfs,(byte *)textSeg,Font03.ofs,(uint8_t)Font03.seg);
  }
  if (gfxOfs == (char *)0x0 && gfxSeg == 0) {
    text = 0x0;
  }
  else {
    strcpy((char *)&text,(char *)unaff_SS);
  }
  sVar1 = strlen((char *)&text);
  bStack_5 = (byte)sVar1;
  uVar5 = (uint16_t)((ulong)((long)row * 0xf) >> 0x10);
  pfStack_c = ovr_stshRleCut((far_t *)0x0,far_from_u32((uint32_t)(0x16a000)),(int)((long)row * 0xf) + 0x1d,222,
                             row * 0xf + 0x29,unaff_SI);
  TextBlitX = 0x2a;
  TextBlitY = row * 0xf + 0x1d;
  _cursorX = 0;
  gfx.seg = uVar5;
  gfx.ofs = (uint16_t)pfStack_c;
  uStack_a = uVar5;
  saveui_usesBlitGfx10(gfx,(char *)&text,unaff_SS,(uint *)&cursorX,(int)unaff_SS);
  (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)trianglsCut4Seg;
  gfx_02.ofs = trianglsCut4Ofs;
  (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = (char)((uint)trianglsCut4Seg >> 8);
  dst.seg = 0xa000;
  dst.ofs = row * 0x12c0 + 0x2096;
  ovr_blitLoadRleGfx(gfx_02,dst);
  ovr_ovc40_flushInput();
  GMenuFlag = 1;
L_uiReadString_0DC9:
  do {
    while( true ) {
      while ((((uStack_4 = uiReadKey2(), 0x1f < (uStack_4 & 0xff) && ((uStack_4 & 0xff) < 0x7f)) &&
              (bStack_5 < 0x4f)) && ((uStack_4 & 0xff) != 0x40))) {
        auStack_5b[bStack_5 - 1] = (undefined1)uStack_4;
        auStack_5b[bStack_5] = 0;
        iVar2 = ovr_font_textWidth((char *)CONCAT13((char)((uint)unaff_SS >> 8),
                                                    CONCAT12((char)unaff_SS,&text)),
                                   (char *)CONCAT22(Font03.seg,Font03.ofs));
        iVar3 = ovr_font_textWidth("_",(char *)CONCAT22(Font03.seg,Font03.ofs));
        if (iVar2 + iVar3 + 0x2aU < 0xe0) {
          bStack_5 = bStack_5 + 1;
        }
        auStack_5b[bStack_5 - 1] = 0;
        gfx_00.seg = uStack_a;
        gfx_00.ofs = (uint16_t)pfStack_c;
        saveui_usesBlitGfx10(gfx_00,(char *)&text,unaff_SS,(uint *)&cursorX,(int)unaff_SS);
      }
      if (uStack_4 != 0x4b00) break;
L_uiReadString_0ECE:
      if (bStack_5 != 0) {
        bStack_5 = bStack_5 - 1;
        auStack_5b[bStack_5 - 1] = 0;
        gfx_01.seg = uStack_a;
        gfx_01.ofs = (uint16_t)pfStack_c;
        saveui_usesBlitGfx10(gfx_01,(char *)&text,unaff_SS,(uint *)&cursorX,(int)unaff_SS);
      }
    }
    if (uStack_4 < 0x4b01) {
      if (uStack_4 == 0x11b) {
        UserWantsExit = 1;
L_uiReadString_1068:
        inputCancelled = 1;
        handle_03.seg = uStack_a;
        handle_03.ofs = (uint16_t)pfStack_c;
        ovr_stshFree(handle_03);
        if (gfxOfs != (char *)0x0 || gfxSeg != 0) {
          handle_04.seg = gfxSeg;
          handle_04.ofs = (uint16_t)gfxOfs;
          ovr_stshFree(handle_04);
        }
        GMenuFlag = 0;
        return (char *)0x0;
      }
      if (uStack_4 == 0xe08) goto L_uiReadString_0ECE;
      if (uStack_4 == 0x1c0d) goto L_uiReadString_0FF7;
      goto L_uiReadString_0DC9;
    }
    if (uStack_4 == 0x4b34) goto L_uiReadString_0ECE;
    if (uStack_4 == 0xfffe) goto L_uiReadString_1068;
    if (uStack_4 == 0xffff) {
      if (((MouseMoved == 0) && (8 < MouseX)) &&
         ((MouseX < 0x19 && ((0xb4 < MouseY && ((MouseY < 0xb6 | 0xeU) != 0)))))) {
        inputCancelled = 1;
        handle.seg = uStack_a;
        handle.ofs = (uint16_t)pfStack_c;
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
        handle_01.seg = uStack_a;
        handle_01.ofs = (uint16_t)pfStack_c;
        ovr_stshFree(handle_01);
        GMenuFlag = 0;
        if (bStack_5 == 0) {
          if (gfxOfs != (char *)0x0 || gfxSeg != 0) {
            handle_02.seg = gfxSeg;
            handle_02.ofs = (uint16_t)gfxOfs;
            ovr_stshFree(handle_02);
          }
          pcVar4 = (char *)0x0;
        }
        else {
          pcVar4 = (char *)0x0;
          dst_00 = ovr_stshRealloc((uint32_t)CONCAT22(gfxSeg,gfxOfs),(ulong)(bStack_5 + 1));
          pcVar4 = strcpy((char *)dst_00,pcVar4);
        }
        return pcVar4;
      }
    }
  } while( true );
}



/* 4528:10a8 */

void __cdecl16far uiMenu(char *title,far_t items,int nitems)

{
  uint16_t in_stack_0000000c;
  
  uiMenuSub(title,items,nitems,in_stack_0000000c);
  return;
}



/* 4528:10c5 */

/* Writes a text line followed by CRLF to a file handle. */

void __cdecl16far saveui_writeLine(int handle,char *text,int count)

{
  if (text != (char *)0x0 || count != 0) {
    strlen(text);
    write(handle,text,count);
  }
  write(handle,(char *)"\r\n",0x2410);
  return;
}



/* 4528:1104 */

/* Reads one line from the file and returns a heap copy (empty for ^Z/empty lines). */

char * __cdecl16far saveui_readLine(int fd)

{
  int iVar1;
  char *pcVar2;
  char *src;
  int iVar3;
  uint unaff_SS;
  uint8_t lineBuf;
  
  iVar3 = 0;
  while (iVar3 < 0x4f) {
    iVar1 = read(fd,&lineBuf + iVar3,unaff_SS);
    if ((iVar1 != 1) || ((&lineBuf)[iVar3] == 0xa)) break;
    if ((&lineBuf)[iVar3] != 0xd) {
      iVar3 = iVar3 + 1;
    }
  }
  if (lineBuf == 0x1a) {
    iVar3 = 0;
  }
  (&lineBuf)[iVar3] = 0x0;
  if (iVar3 == 0) {
    pcVar2 = (char *)0x0;
  }
  else {
    src = (char *)(iVar3 + 1 >> 0xf);
    pcVar2 = ovr_stshAlloc((long)(iVar3 + 1));
    pcVar2 = strcpy(pcVar2,src);
  }
  return pcVar2;
}



/* 4528:1175 */

/* Reads the save-slot list from saves.txt. */

uint __cdecl16far saveui_readSavesList(int entries,uint16_t entriesSeg)

{
  char *pcVar1;
  int fd;
  undefined2 uVar2;
  uint16_t in_DX;
  uint16_t uVar3;
  undefined2 *puVar4;
  uint uVar5;
  far_t handle;
  uint16_t uStack_4;
  
  uStack_4 = 0;
  pcVar1 = ovr_fmVsprintf((char *)"%ssaves.txt",(char *)"puppetmaker" + 3);
  fd = ovr_open_wait_unlock_and_disk(pcVar1);
  if (-1 < fd) {
    pcVar1 = (char *)saveui_readLine(fd);
    uVar3 = in_DX;
    uStack_4 = _atol((char *)CONCAT22(in_DX,pcVar1));
    handle.seg = in_DX;
    handle.ofs = (uint16_t)pcVar1;
    ovr_stshFree(handle);
    for (uVar5 = 0; uVar5 < uStack_4; uVar5 = uVar5 + 1) {
      uVar2 = saveui_readLine(fd);
      puVar4 = (undefined2 *)(entries + uVar5 * 4);
      puVar4[1] = uVar3;
      *puVar4 = uVar2;
    }
    close(fd);
  }
  return uStack_4;
}



/* 4528:120d */

/* Writes the save-slot list to saves.txt (count line plus one line per entry). */

void __cdecl16far saveui_writeSavesList(far_t entries,uint count)

{
  char *path;
  int handle;
  undefined2 *puVar1;
  uint uVar2;
  int unaff_SS;
  uint8_t msg;
  
  path = ovr_fmVsprintf((char *)"%ssaves.txt",(char *)"puppetmaker" + 3);
  handle = ovr_creat_wait_unlock_and_disk(path);
  if (-1 < handle) {
    _sprintf((char *)CONCAT22(unaff_SS,&msg),"%u");
    saveui_writeLine(handle,(char *)&msg,unaff_SS);
    for (uVar2 = 0; uVar2 < count; uVar2 = uVar2 + 1) {
      puVar1 = (undefined2 *)(entries.ofs + uVar2 * 4);
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
  int iVar1;
  uint16_t uVar2;
  int *piVar3;
  undefined2 *puVar4;
  uint16_t *puVar5;
  uint uVar6;
  uint16_t uVar7;
  far_t handle;
  
  for (uVar6 = 0; uVar6 < count; uVar6 = uVar6 + 1) {
    uVar7 = entries.seg;
    uVar2 = entries.ofs;
    piVar3 = (int *)(uVar2 + uVar6 * 4);
    if (*piVar3 != 0 || piVar3[1] != 0) {
      puVar4 = (undefined2 *)(uVar2 + uVar6 * 4);
      iVar1 = strcmp((char *)*puVar4,(char *)puVar4[1]);
      if (iVar1 != 0) {
        puVar5 = (uint16_t *)(uVar2 + uVar6 * 4);
        handle.seg = puVar5[1];
        handle.ofs = *puVar5;
        ovr_stshFree(handle);
      }
    }
    puVar4 = (undefined2 *)(uVar2 + uVar6 * 4);
    puVar4[1] = 0;
    *puVar4 = 0;
  }
  return;
}



/* 4528:1303 */

/* WARNING: Instruction at (ram,0x0004072b) overlaps instruction at (ram,0x0004072a)
    */
/* WARNING: Control flow encountered bad instruction data */
/* Edits the message delay, persists it to cflow4.txt and reports the new value. */

char * __cdecl16far saveui_configureMessageDelay(void)

{
  uint *puVar1;
  uint16_t *puVar2;
  uint8_t *puVar3;
  byte *pbVar4;
  undefined4 uVar5;
  char cVar6;
  undefined1 uVar7;
  uint uVar8;
  uint uVar9;
  uint16_t uVar10;
  char *pcVar11;
  uint8_t *puVar12;
  int in_CX;
  sbyte sVar13;
  undefined2 in_DX;
  entity_t *peVar14;
  uint *puVar15;
  int iVar16;
  byte *unaff_SI;
  uint unaff_DI;
  undefined2 uVar18;
  uint16_t unaff_SS;
  byte abStackY_15bc [5516];
  undefined2 uStackY_30;
  undefined2 uStackY_2e;
  far_t items;
  uint8_t menuLabel;
  undefined4 uStack_1e;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  undefined1 uStack_f;
  char acStack_e [6];
  uint16_t uStack_8;
  uint16_t uStack_6;
  byte bStack_4;
  byte bStack_3;
  byte bVar17;
  
  bStack_3 = 0;
  GMenuItem = '\x01';
  while( true ) {
    ovr_resetTextBlitCycle();
    saveui_blitPanel();
    pcVar11 = ovr_fmVsprintf((char *)"Message delay is now %d.",(char *)"puppetmaker" + 3);
    ovr_say(pcVar11);
    if (MessageDelay == 0) {
      uStack_1e = (entity_t *)0x0;
      _menuLabel = 0;
    }
    else {
      uStack_1e = (entity_t *)0x2410;
      _menuLabel = 0x2765;
    }
    if (MessageDelay < 0x28) {
      uStack_1a = 0x2410;
      uStack_1e = (entity_t *)CONCAT22(0x277c,(entity_t *)uStack_1e);
    }
    else {
      uStack_1a = 0;
    }
    iStack_16 = 0x2410;
    uStack_18 = 0x2793;
    iStack_12 = 0x2410;
    iStack_14 = 0x2798;
    puVar12 = &menuLabel;
    items.seg = (uint16_t)puVar12;
    items.ofs = 0x2410;
    uStackY_2e = 0x22c4;
    uStackY_30 = 0x662e;
    uiMenuSub((char *)"Change message delay:",items,unaff_SS,4);
    bStack_4 = (byte)puVar12;
    uVar8 = (uint)puVar12 & 0xff;
    if (uVar8 < 5) break;
    if ((char *)(uint)bStack_3 != (char *)0x0) {
      return (char *)(uint)bStack_3;
    }
  }
  puVar15 = (uint *)(uVar8 * 2);
  switch(uVar8) {
  default:
    if (GMenuItem == '\0') {
      pcVar11 = (char *)"arena" + 4;
    }
    else {
      pcVar11 = (char *)CONCAT11(0x24,GMenuItem + (char)uStack_6);
    }
    GMenuFlag = 0;
    return pcVar11;
  case 1:
    bVar17 = *unaff_SI;
    *(uint *)((byte *)((int)puVar15 + (int)unaff_SI) + -0x6af7) =
         *(uint *)((byte *)((int)puVar15 + (int)unaff_SI) + -0x6af7) | unaff_DI;
    *(uint *)(&stack0x0007 + (int)unaff_SI) =
         *(uint *)(&stack0x0007 + (int)unaff_SI) | (uint)unaff_SI;
    puVar1 = (uint *)(&stack0xffff + unaff_DI);
    *puVar1 = *puVar1 | unaff_DI;
    *puVar15 = *puVar15 | (uint)&stack0xffff;
                    /* WARNING: Read-only address (ram,0x00025f09) is written */
    (*(uint16_t *)((uint8_t *)&(s_fighters__residence_2410_1e09))) = (uint)&stack0xffde | 0x6966;
    bVar17 = (byte)((uint)puVar15 >> 8) | (byte)in_CX | bVar17 | (byte)unaff_DI;
    iVar16 = CONCAT11(bVar17,(byte)puVar15);
    pbVar4 = (byte *)(iVar16 + -0x51f8);
    *pbVar4 = *pbVar4 | bVar17;
    ((char *)"cflow4.txt" + 7)[unaff_DI] =
         ((char *)"cflow4.txt" + 7)[unaff_DI] | (byte)in_DX | (byte)puVar15;
    unaff_SI[iVar16 + 8] = unaff_SI[iVar16 + 8] | bVar17;
    (&stack0x0007)[(int)unaff_SI] = (&stack0x0007)[(int)unaff_SI] | (byte)puVar12;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 2:
    ((byte *)((int)puVar15 + (int)unaff_SI))[-0x75] =
         ((byte *)((int)puVar15 + (int)unaff_SI))[-0x75] + (byte)in_DX;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 3:
    break;
  }
switchD_4000_6642_caseD_3:
  *(int *)(abStackY_15bc + (int)unaff_SI) = *(int *)(abStackY_15bc + (int)unaff_SI) + in_CX;
  if (uVar8 == 0) {
    ovr_ovc15_clearVisited();
    uVar18 = (undefined2)((ulong)uStack_1e >> 0x10);
    peVar14 = (entity_t *)uStack_1e;
    uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)((ulong)((peVar14->base).animFrame + 0xf) / 0x10));
    if (((peVar14->base).target & 1) == 0) {
      iStack_16 = 0;
    }
    else {
      iStack_16 = (peVar14->base).target - 2;
    }
    while( true ) {
      cVar6 = (char)uStack_1a;
      uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)uStack_1a + -1);
      if (cVar6 == '\0') break;
      ovr_ovc15_textArena(unaff_DI);
    }
  }
  else if ((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) == '\0') {
    uStack_1a = (uint)(byte)((ulong)((((entity_t *)uStack_1e)->base).animFrame + 0xf) / 0x10);
    while( true ) {
      cVar6 = (char)uStack_1a;
      uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)uStack_1a + -1);
      if (cVar6 == '\0') break;
      ovr_agnt_usesAgntCount6((entity_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(Entities) + 2)),(entity_t *)Entities + unaff_DI));
    }
  }
  else if (((char)uStack_18 != '\0') && ((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) != '\0')) {
    uVar7 = func_0x0004f944();
    uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),uVar7);
    while ((char)uStack_1a != '\0') {
      uVar18 = (undefined2)((ulong)uStack_1e >> 0x10);
      if (((((entity_t *)uStack_1e)->base).target & 1) == 0) {
        iStack_16 = 0;
      }
      else {
        iStack_16 = (((entity_t *)uStack_1e)->base).target - 2;
      }
      pcVar11 = ovr_ovc15_textArena(unaff_DI);
      if (((uint)pcVar11 & 0xff) == 0) break;
      uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)uStack_1a + -1);
    }
  }
  do {
    do {
      do {
        unaff_DI = unaff_DI + 1;
        if (EntityCount <= unaff_DI) {
          GGameState = 0x3c;
          if (DebugVerbose != false) {
            uStackY_2e = 0x878;
            printf("%d %d %d  \r");
          }
          func_0x0004fcda();
          GGameState = 0x3d;
          if (DebugVerbose != false) {
            uStackY_2e = 0x8b3;
            printf("%d %d %d  \r");
          }
          ovr_OVC23_55fe_29a2_entry();
          GGameState = 0xc;
          if (DebugVerbose != false) {
            uStackY_2e = 0x8ef;
            printf("%d %d %d  \r");
          }
          ovr_ovc24_removeOtherEntities((uint8_t *)((int)&uStack_18 + 1));
          GGameState = 0x1f;
          if ((*(uint8_t *)((uint8_t *)&(uStack_18) + 1)) != '\0') {
            ovr_constr_usesBlitRect();
            GGameState = 0x13;
          }
          func_0x0004f68f();
          GGameState = 0x1d;
          for (uVar8 = 0; (int)uVar8 < 5; uVar8 = uVar8 + 1) {
            if (acStack_e[uVar8] != '\0') {
              ovr_ovc41_usesMiceBlitRect(uVar8);
            }
          }
          GGameState = 0xd;
          if (DebugVerbose != false) {
            uStackY_2e = 0x98b;
            printf("%d %d %d  \r");
          }
          ovr_ovc24_checkStrongholds();
          GGameState = 0xe;
          mapDirty = 1;
          return (char *)"puppetmaker" + 3;
        }
        uStack_1e = (entity_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(Entities) + 2)),(entity_t *)Entities + unaff_DI);
        uVar8 = ovr_alignUp4(((entity_t *)Entities)[unaff_DI].base.destX);
        uVar9 = ovr_alignUp4((uStack_1e->base).x);
        if ((uVar8 == uVar9) &&
           (uVar18 = (undefined2)((ulong)uStack_1e >> 0x10),
           (((entity_t *)uStack_1e)->base).destY == (((entity_t *)uStack_1e)->base).y)) {
          uStackY_2e = 0x204;
          func_0x0004fb8e();
        }
        uVar18 = (undefined2)((ulong)uStack_1e >> 0x10);
        peVar14 = (entity_t *)uStack_1e;
      } while (((peVar14->base).destX == 0 && (peVar14->base).destY == 0) ||
              (*(char *)((int)&(peVar14->base).entity + 1) != '\0'));
      bStack_3 = (*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)(peVar14->base).gindex * 0x95)
                 & 0x4000) != 0;
      uStack_6 = (uStack_1e->base).x;
      uStack_8 = (peVar14->base).y;
      uStack_f = *(undefined1 *)
                  ((int)(char **)GMenuStrings + (uint)(peVar14->base).gindex * 0x95 + 0x1f);
      if ((peVar14->base).faction < (byte)(peVar14->base).state) {
        sVar13 = ((peVar14->base).faction & 3) << 1;
        in_CX = CONCAT11((char)((uint)in_CX >> 8),sVar13);
        (peVar14->base).target =
             (byte)((int)(uint)*(byte *)((int)&(peVar14->base).owner +
                                        ((int)(uint)(peVar14->base).faction >> 2)) >> sVar13) & 3;
        cVar6 = func_0x0004f32d();
        peVar14 = (entity_t *)uStack_1e;
        uVar18 = (undefined2)((ulong)uStack_1e >> 0x10);
        if (cVar6 == '\0') {
          (uStack_1e->base).x = (uStack_1e->base).x + (int)*(char *)((peVar14->base).target + 0x885)
          ;
          puVar2 = &(peVar14->base).y;
          *puVar2 = *puVar2 + (int)*(char *)((peVar14->base).target + 0x889);
          puVar3 = &(peVar14->base).faction;
          *puVar3 = *puVar3 + 0x1;
        }
        else {
          (peVar14->base).faction = 0x0;
          *(undefined1 *)&(peVar14->base).state = 0;
        }
      }
      else {
        iStack_12 = ovr_ovc07_signum((peVar14->base).destX - (uStack_1e->base).x);
        uVar18 = (undefined2)((ulong)uStack_1e >> 0x10);
        iStack_14 = ovr_ovc07_signum((((entity_t *)uStack_1e)->base).destY -
                                     (((entity_t *)uStack_1e)->base).y);
        if ((iStack_12 != 0) && (uVar10 = ovr_randBelow(2), (char)uVar10 != '\0')) {
          uStackY_2e = 0x399;
          cVar6 = func_0x0004f412();
          if (cVar6 == '\0') {
            (uStack_1e->base).x = (uStack_1e->base).x + iStack_12;
            (((entity_t *)uStack_1e)->base).target = 0x2 - (char)iStack_12;
            goto L_attact_3f0b_1082_1477;
          }
        }
        if (iStack_14 != 0) {
          uStackY_2e = 0x3d8;
          cVar6 = func_0x0004f412();
          if (cVar6 == '\0') {
            uVar18 = (undefined2)((ulong)uStack_1e >> 0x10);
            puVar2 = &(((entity_t *)uStack_1e)->base).y;
            *puVar2 = *puVar2 + iStack_14;
            (((entity_t *)uStack_1e)->base).target = (char)iStack_14 + 0x1;
            goto L_attact_3f0b_1082_1477;
          }
        }
        if (iStack_12 != 0) {
          uStackY_2e = 0x418;
          cVar6 = func_0x0004f412();
          if (cVar6 == '\0') {
            (uStack_1e->base).x = (uStack_1e->base).x + iStack_12;
            (((entity_t *)uStack_1e)->base).target = 0x2 - (char)iStack_12;
            goto L_attact_3f0b_1082_1477;
          }
        }
        uVar8 = ovr_ovc26_usesStExit(unaff_DI);
        if ((char)uVar8 == '\0') {
          uStackY_2e = 0x4e3;
          uVar8 = ovr_ovc26_usesRandBelow
                            (unaff_DI,(int)&uStack_18 + 1,unaff_SS,(uint16_t)acStack_e,unaff_SS);
          if (((uVar8 & 0xff) == 0) &&
             (*(char *)((int)(char **)GMenuStrings +
                       (uint)(((entity_t *)uStack_1e)->base).gindex * 0x95 + 0x1f) == '\0')) {
            uStackY_2e = 0x524;
            func_0x0004fb8e();
          }
        }
        else {
          uVar18 = (undefined2)((ulong)uStack_1e >> 0x10);
          peVar14 = (entity_t *)uStack_1e;
          sVar13 = ((peVar14->base).faction & 3) << 1;
          in_CX = CONCAT11((char)((uint)in_CX >> 8),sVar13);
          (peVar14->base).target =
               (byte)((int)(uint)*(byte *)((int)&(peVar14->base).owner +
                                          ((int)(uint)(peVar14->base).faction >> 2)) >> sVar13) & 3;
          cVar6 = func_0x0004f32d();
          if (cVar6 == '\0') {
            uVar18 = (undefined2)((ulong)uStack_1e >> 0x10);
            peVar14 = (entity_t *)uStack_1e;
            (uStack_1e->base).x =
                 (uStack_1e->base).x + (int)*(char *)((peVar14->base).target + 0x885);
            puVar2 = &(peVar14->base).y;
            *puVar2 = *puVar2 + (int)*(char *)((peVar14->base).target + 0x889);
            puVar3 = &(peVar14->base).faction;
            *puVar3 = *puVar3 + 0x1;
          }
        }
      }
L_attact_3f0b_1082_1477:
      uStack_18 = CONCAT11(1,(char)uStack_18);
      uVar8 = ovr_alignUp4((((entity_t *)uStack_1e)->base).destX);
      uVar9 = ovr_alignUp4((uStack_1e->base).x);
      if (uVar8 == uVar9) {
        uVar18 = (undefined2)((ulong)uStack_1e >> 0x10);
        peVar14 = (entity_t *)uStack_1e;
        if ((peVar14->base).destY == (peVar14->base).y) {
          (peVar14->base).destX = 0;
          (peVar14->base).destY = 0;
          if (*(char *)((int)&(peVar14->base).entity + 3) == -1) {
            bStack_4 = 0xff;
          }
          else {
            uVar5 = *(undefined4 *)((uint)*(byte *)((int)&(peVar14->base).entity + 3) << 2);
            bStack_4 = *(byte *)((int)uVar5 + 0x89);
          }
          if (bStack_4 != 0xff) {
            for (unaff_SI = (byte *)0x0; unaff_SI < SquareRecCount; unaff_SI = unaff_SI + 1) {
              uVar8 = ovr_alignUp4(*(int *)((int)unaff_SI * 0x13));
              uVar9 = ovr_alignUp4((uStack_1e->base).x);
              if ((uVar8 == uVar9) &&
                 (*(uint16_t *)((int)unaff_SI * 0x13 + 2) == (((entity_t *)uStack_1e)->base).y)) {
                func_0x0004f930();
                if (*(uint16_t *)((int)unaff_SI * 0x13 + 2) == GfxRndSeed2) {
                  uVar8 = ovr_alignUp4(*(int *)((int)unaff_SI * 0x13));
                  uVar9 = ovr_alignUp4(GfxRndSeed);
                  if (uVar8 == uVar9) {
                    acStack_e[bStack_4] = '\x01';
                  }
                }
                break;
              }
            }
          }
        }
      }
    } while (AgntFlag1 == false);
    if ((((uStack_1e->base).x < GfxRndSeed - 2U) || (GfxRndSeed + 1U < (uStack_1e->base).x)) ||
       ((((entity_t *)uStack_1e)->base).y != GfxRndSeed2)) {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    uStack_1a = CONCAT11(cVar6,(char)uStack_1a);
    if (((uStack_6 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uStack_6)) || (GfxRndSeed2 != uStack_8))
    {
      bVar17 = 0;
    }
    else {
      bVar17 = 1;
    }
    uStack_18 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_18) + 1)),bVar17);
  } while (bVar17 == 0 && cVar6 == '\0');
  uVar8 = (uint)bVar17;
  goto switchD_4000_6642_caseD_3;
}



/* 4528:144e */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far saveui_usesBlitLoadRleGfx4(void)

{
  far_t gfx;
  
  gfx.seg = FontHandle.seg;
  gfx.ofs = FontHandle.ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)));
  return;
}



/* 4528:1470 */

/* Blits the "Cancel" label at its fixed position in Font03. */

void __cdecl16far saveui_drawCancel(void)

{
  saveui_usesBlitLoadRleGfx4();
  TextBlitX = 0x1d;
  TextBlitY = 0xb7;
  ovr_blitText((char *)"Cancel",(byte *)((char *)"puppetmaker" + 3),Font03.ofs,(uint8_t)Font03.seg);
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
  bool bVar1;
  bool bVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  byte bVar5;
  char cVar6;
  void *dest;
  uint16_t pmenu;
  uint16_t uVar7;
  int iVar8;
  char *pcVar9;
  undefined2 uVar10;
  char *title;
  uint16_t in_DX;
  uint16_t uVar11;
  uint *puVar12;
  uint16_t *puVar13;
  undefined2 *puVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  uint16_t unaff_SS;
  uint32_t menu;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined2 uStack_18;
  undefined2 uStack_16;
  byte bStack_13;
  char yesno [9];
  uint8_t yes_picked;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&menu;
  F_SCOPY(far_from_u32((uint32_t)(0x241026b7)),dst);
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)yesno;
  F_SCOPY(far_from_u32((uint32_t)(0x241026d7)),dst_00);
  ovr_say((char *)"Stronghold V 1.00");
  gfx.seg = GMenuGfxSeg;
  gfx.ofs = GMenuGfxOfs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa00009af)));
  ovr_stats_drawStatsPanel();
  saveui_blitPanel();
  dest = ovr_stshAlloc(400);
  uVar11 = in_DX;
  _fsetmem(dest,in_DX,400);
  uVar16 = 0;
  bVar2 = false;
  do {
    if (SaveAuto == '\0') {
      uStack_2e = 0;
      uStack_30 = 0;
    }
    else {
      uStack_2e = 0x2410;
      uStack_30 = 0x27f4;
    }
    if ((GGameInProgress == '\0') && (SaveAuto != '\0')) {
      uStack_16 = 0x2410;
      uStack_18 = 0x283f;
    }
    else {
      uStack_16 = 0;
      uStack_18 = 0;
    }
    pmenu = (uint16_t)&menu;
    items.seg = pmenu;
    items.ofs = 0x2410;
    uiMenu((char *)"Select an option:",items,unaff_SS);
    bStack_13 = (byte)pmenu;
    ovr_say((char *)"<Empty>" + 7);
    if (bStack_13 < 9) {
                    /* WARNING: Switch is manually overridden */
      switch((undefined4)
             *(undefined2 *)((char *)"%s: provides for food trade." + 1 + (uint)bStack_13 * 2)) {
      case 288826:
        saveui_blitPanel();
        bVar1 = false;
        if ((SaveAuto == '\0') || (GWantsExit2 == '\0')) {
          bVar1 = true;
        }
        else {
          pcVar9 = yesno;
          items_00.seg = (uint16_t)pcVar9;
          items_00.ofs = 0x2410;
          uiMenu((char *)"Game not saved: Are you sure?",items_00,unaff_SS);
          if ((char)pcVar9 == '\x01') {
            bVar1 = true;
          }
        }
        saveui_blitPanel();
        if (bVar1) {
          ovr_copyProtectionCheck();
          saveui_configureNewWorld();
        }
        break;
      case 288917:
        saveui_blitPanel();
        entries.seg = in_DX;
        entries.ofs = (uint16_t)dest;
        saveui_freeLines(entries,uVar16);
        uVar16 = saveui_readSavesList((int)dest,in_DX);
        uVar7 = uVar16;
        for (uVar17 = 0; uVar4 = GSPEmpty.seg, uVar3 = GSPEmpty.ofs, uVar17 < uVar16;
            uVar17 = uVar17 + 1) {
          puVar12 = (uint *)((int)dest + uVar17 * 4);
          uVar7 = *puVar12 | puVar12[1];
          if (uVar7 == 0) {
            puVar13 = (uint16_t *)((int)dest + uVar17 * 4);
            puVar13[1] = GSPEmpty.seg;
            *puVar13 = uVar3;
            uVar7 = uVar4;
            uVar11 = uVar3;
          }
        }
        if (uVar16 < 100) {
          puVar13 = (uint16_t *)((int)dest + uVar16 * 4);
          puVar13[1] = GSPEmpty.seg;
          *puVar13 = uVar3;
          uVar7 = uVar4;
          uVar11 = uVar3;
        }
        bVar5 = (byte)uVar7;
        uVar16 = uVar16 + 1;
        saveui_drawCancel();
        items_01.seg = (uint16_t)dest;
        items_01.ofs = 0x2410;
        uiMenu((char *)"Save Game:",items_01,in_DX);
        saveui_usesBlitLoadRleGfx4();
        if (bVar5 != 0) {
          iVar8 = strcmp((char *)*(undefined2 *)((int)dest + (uint)bVar5 * 4 + -4),
                         (char *)*(undefined2 *)((int)dest + (uint)bVar5 * 4 + -2));
          if (iVar8 == 0) {
            saveui_blitPanel();
            saveui_drawCancel();
            pcVar9 = uiReadString((char *)"Name this save:  (Esc to cancel)",0x2410,0,(char *)0x0,0)
            ;
            *(uint16_t *)((int)dest + (uint)bVar5 * 4 + -2) = uVar11;
            *(undefined2 *)((int)dest + (uint)bVar5 * 4 + -4) = pcVar9;
            saveui_usesBlitLoadRleGfx4();
          }
          else {
            saveui_blitPanel();
            saveui_drawCancel();
            pcVar9 = uiReadString((char *)"Name for this save:  (Esc to cancel)",0x2410,0,
                                  (char *)*(undefined2 *)((int)dest + (uint)bVar5 * 4 + -4),
                                  *(uint16_t *)((int)dest + (uint)bVar5 * 4 + -2));
            *(uint16_t *)((int)dest + (uint)bVar5 * 4 + -2) = uVar11;
            *(undefined2 *)((int)dest + (uint)bVar5 * 4 + -4) = pcVar9;
            saveui_usesBlitLoadRleGfx4();
          }
          if ((*(int *)((int)dest + (uint)bVar5 * 4 + -4) != 0 ||
               *(int *)((int)dest + (uint)bVar5 * 4 + -2) != 0) &&
             (iVar8 = strcmp((char *)*(undefined2 *)((int)dest + (uint)bVar5 * 4 + -4),
                             (char *)*(undefined2 *)((int)dest + (uint)bVar5 * 4 + -2)), iVar8 == 0)
             ) {
            handle.seg = *(uint16_t *)((int)dest + (uint)bVar5 * 4 + -2);
            handle.ofs = *(uint16_t *)((int)dest + (uint)bVar5 * 4 + -4);
            ovr_stshFree(handle);
            *(undefined2 *)((int)dest + (uint)bVar5 * 4 + -2) = 0;
            *(undefined2 *)((int)dest + (uint)bVar5 * 4 + -4) = 0;
          }
          if (*(int *)((int)dest + (uint)bVar5 * 4 + -4) != 0 ||
              *(int *)((int)dest + (uint)bVar5 * 4 + -2) != 0) {
            uVar10 = ovr_stSave();
            if ((char)uVar10 == '\0') {
              *(undefined2 *)((int)dest + (uint)bVar5 * 4 + -2) = 0;
              *(undefined2 *)((int)dest + (uint)bVar5 * 4 + -4) = 0;
            }
            else {
              GWantsExit2 = '\0';
            }
            for (uVar17 = 0; uVar17 < uVar16; uVar17 = uVar17 + 1) {
              puVar14 = (undefined2 *)((int)dest + uVar17 * 4);
              iVar8 = strcmp((char *)*puVar14,(char *)puVar14[1]);
              if (iVar8 == 0) {
                puVar14 = (undefined2 *)((int)dest + uVar17 * 4);
                puVar14[1] = 0;
                *puVar14 = 0;
              }
            }
            while ((uVar16 != 0 &&
                   (piVar15 = (int *)((int)dest + (uVar16 - 1) * 4),
                   *piVar15 == 0 && piVar15[1] == 0))) {
              uVar16 = uVar16 - 1;
            }
            entries_00.seg = in_DX;
            entries_00.ofs = (uint16_t)dest;
            saveui_writeSavesList(entries_00,uVar16);
          }
        }
        saveui_blitPanel();
        break;
      case 289563:
        saveui_blitPanel();
        entries_01.seg = in_DX;
        entries_01.ofs = (uint16_t)dest;
        saveui_freeLines(entries_01,uVar16);
        uVar16 = saveui_readSavesList((int)dest,in_DX);
        uVar17 = uVar16;
        saveui_drawCancel();
        cVar6 = (char)uVar17;
        items_02.seg = (uint16_t)dest;
        items_02.ofs = 0x2410;
        uiMenu((char *)"Load Game:",items_02,in_DX);
        saveui_usesBlitLoadRleGfx4();
        if (cVar6 != '\0') {
          bVar1 = false;
          if ((SaveAuto == '\0') || (GWantsExit2 == '\0')) {
            bVar1 = true;
          }
          else {
            saveui_blitPanel();
            pcVar9 = yesno;
            items_03.seg = (uint16_t)pcVar9;
            items_03.ofs = 0x2410;
            uiMenu((char *)"Game not saved: Are you sure?",items_03,unaff_SS);
            if ((char)pcVar9 == '\x01') {
              bVar1 = true;
            }
          }
          saveui_blitPanel();
          if (bVar1) {
            ovr_save_loadGameFile();
            GWantsExit2 = '\0';
          }
        }
        saveui_blitPanel();
        break;
      case 289727:
        saveui_blitPanel();
        entries_02.seg = in_DX;
        entries_02.ofs = (uint16_t)dest;
        saveui_freeLines(entries_02,uVar16);
        uVar16 = saveui_readSavesList((int)dest,in_DX);
        uVar17 = uVar16;
        saveui_drawCancel();
        bVar5 = (byte)uVar17;
        items_04.seg = (uint16_t)dest;
        items_04.ofs = 0x2410;
        uiMenu((char *)"Delete Game:",items_04,in_DX);
        saveui_usesBlitLoadRleGfx4();
        if (bVar5 != 0) {
          saveui_blitPanel();
          pcVar9 = yesno;
          uVar7 = unaff_SS;
          title = ovr_fmVsprintf((char *)"Delete %s: Are you sure?",(char *)"puppetmaker" + 3);
          items_05.seg = (uint16_t)pcVar9;
          items_05.ofs = uVar11;
          uiMenu(title,items_05,uVar7);
          if ((char)title == '\x01') {
            ovr_save_deleteGameFile();
            handle_00.seg = *(uint16_t *)((int)dest + (uint)bVar5 * 4 + -2);
            handle_00.ofs = *(uint16_t *)((int)dest + (uint)bVar5 * 4 + -4);
            ovr_stshFree(handle_00);
            *(undefined2 *)((int)dest + (uint)bVar5 * 4 + -2) = 0;
            *(undefined2 *)((int)dest + (uint)bVar5 * 4 + -4) = 0;
            while ((uVar16 != 0 &&
                   (piVar15 = (int *)((int)dest + (uVar16 - 1) * 4),
                   *piVar15 == 0 && piVar15[1] == 0))) {
              uVar16 = uVar16 - 1;
            }
          }
        }
        entries_03.seg = in_DX;
        entries_03.ofs = (uint16_t)dest;
        saveui_writeSavesList(entries_03,uVar16);
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
          bVar2 = true;
        }
      }
    }
  } while ((SaveAuto == '\0') || (!bVar2));
  entries_04.seg = in_DX;
  entries_04.ofs = (uint16_t)dest;
  saveui_freeLines(entries_04,uVar16);
  handle_01.seg = in_DX;
  handle_01.ofs = (uint16_t)dest;
  ovr_stshFree(handle_01);
  ovr_ovc28_textHalflingCastle();
  return;
}



/* 4528:1ae8 */

/* Runs the new-world dialog (hostility, enemy intelligence, second-wave size) and starts the
   generated world. */

void __cdecl16far saveui_configureNewWorld(void)

{
  uint8_t *puVar1;
  uint16_t unaff_SS;
  far_t items;
  far_t items_00;
  far_t dst_00;
  far_t dst_01;
  far_t dst_02;
  uint8_t worldItems;
  uint8_t hostilityItems;
  uint8_t seedTable;
  undefined2 auStack_26 [3];
  uint8_t dst;
  char cStack_c;
  byte bStack_b;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&dst;
  F_SCOPY(far_from_u32((uint32_t)(0x241026e3)),dst_00);
  dst_01.seg = unaff_SS;
  dst_01.ofs = (uint16_t)&hostilityItems;
  F_SCOPY(far_from_u32((uint32_t)(0x241026f7)),dst_01);
  dst_02.seg = unaff_SS;
  dst_02.ofs = (uint16_t)&worldItems;
  F_SCOPY(far_from_u32((uint32_t)(0x2410270b)),dst_02);
  puVar1 = &worldItems;
  items.seg = (uint16_t)puVar1;
  items.ofs = 0x2410;
  uiMenu((char *)"Which new world:",items,unaff_SS);
  bStack_b = (byte)puVar1;
  saveui_blitPanel();
  if ((bStack_b != 8) && (bStack_b != 0)) {
    if (bStack_b == 7) {
      SeedHi = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
      GSeed = *(undefined2 *)BDA_DailyTimeCounter;
    }
    else {
      if (bStack_b == 1) {
        ovr_save_loadArchiveGame();
        return;
      }
      SeedHi = auStack_26[(uint)bStack_b * 2];
      GSeed = *(undefined2 *)(&seedTable + (uint)bStack_b * 4);
    }
    srand8(CONCAT22(SeedHi,GSeed));
    cStack_c = bStack_b - 1;
    puVar1 = &hostilityItems;
    items_00.seg = (uint16_t)puVar1;
    items_00.ofs = 0x2410;
    uiMenu((char *)"Hostility level:",items_00,unaff_SS);
    bStack_b = (byte)puVar1;
    saveui_blitPanel();
    if ((bStack_b != '\x05') && (bStack_b != '\0')) {
      if (bStack_b == '\x04') {
        iStack_a = saveui_usesBlitText((char *)"Low intelligence enemies:",0x2410,6);
        saveui_blitPanel();
        if (iStack_a < 0) {
          if (inputCancelled != '\0') {
            return;
          }
          iStack_a = 0;
        }
        iStack_8 = saveui_usesBlitText((char *)"Medium intelligence enemies:",0x2410,6);
        saveui_blitPanel();
        if (iStack_8 < 0) {
          if (inputCancelled != '\0') {
            return;
          }
          iStack_8 = 0;
        }
        iStack_6 = saveui_usesBlitText((char *)"High intelligence enemies:",0x2410,6);
        saveui_blitPanel();
        if (iStack_6 < 0) {
          if (inputCancelled != '\0') {
            return;
          }
          iStack_6 = 0;
        }
        iStack_4 = saveui_usesBlitText((char *)"Size of second wave:",0x2410,6);
        saveui_blitPanel();
        if (iStack_4 < 0) {
          if (inputCancelled != '\0') {
            return;
          }
          iStack_4 = 0;
        }
        if (0x3c < iStack_a + iStack_8 + iStack_6 + iStack_4) {
          ovr_say((char *)"Too many enemies. 60 enemies maximum.");
          return;
        }
        lowIntelEnemies = (undefined1)iStack_a;
        medIntelEnemies = (undefined1)iStack_8;
        highIntelEnemies = (undefined1)iStack_6;
        secondWaveSize = (undefined1)iStack_4;
      }
      Difficulty = bStack_b;
      worldIndex = cStack_c;
      ovr_say((char *)"Resetting game...");
      ovr_init_usesClearEntities();
      ovr_say((char *)"New world complete.");
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

/* [R4] calls ovr_blitText */

int __cdecl16far saveui_usesBlitText(char *prompt,int textSeg,int row)

{
  far_t handle;
  far_t handle_00;
  int iVar1;
  int iVar2;
  uint16_t uVar3;
  int16_t unaff_SI;
  byte *unaff_SS;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  uint8_t text;
  undefined1 auStack_5b [79];
  far_t *pfStack_c;
  uint16_t uStack_a;
  uint8_t cursorX;
  byte bStack_5;
  uint16_t uStack_4;
  
  inputCancelled = 0;
  if (prompt != (char *)0x0 || textSeg != 0) {
    TextBlitX = 0x16;
    TextBlitY = 0xb;
    ovr_blitText(prompt,(byte *)textSeg,Font03.ofs,(uint8_t)Font03.seg);
  }
  bStack_5 = 0;
  text = 0x0;
  uVar3 = (uint16_t)((ulong)((long)row * 0xf) >> 0x10);
  pfStack_c = ovr_stshRleCut((far_t *)0x0,far_from_u32((uint32_t)(0x16a000)),(int)((long)row * 0xf) + 0x1d,222,
                             row * 0xf + 0x27,unaff_SI);
  TextBlitX = 0x2a;
  TextBlitY = row * 0xf + 0x1d;
  _cursorX = 0;
  gfx.seg = uVar3;
  gfx.ofs = (uint16_t)pfStack_c;
  uStack_a = uVar3;
  saveui_usesBlitGfx10(gfx,(char *)&text,unaff_SS,(uint *)&cursorX,(int)unaff_SS);
  ovr_ovc40_flushInput();
L_saveui_4528_1d55_1E1D:
  do {
    while( true ) {
      while ((uStack_4 = uiReadKey2(), (((byte *)_ctype + 1)[uStack_4 & 0xff] & 2) != 0 &&
             (bStack_5 < 2))) {
        auStack_5b[bStack_5 - 1] = (undefined1)uStack_4;
        auStack_5b[bStack_5] = 0;
        iVar2 = ovr_font_textWidth((char *)CONCAT13((char)((uint)unaff_SS >> 8),
                                                    CONCAT12((char)unaff_SS,&text)),
                                   (char *)CONCAT22(Font03.seg,Font03.ofs));
        iVar1 = ovr_font_textWidth("_",(char *)CONCAT22(Font03.seg,Font03.ofs));
        if (iVar2 + iVar1 + 0x2aU < 0xe0) {
          bStack_5 = bStack_5 + 1;
        }
        auStack_5b[bStack_5 - 1] = 0;
        gfx_00.seg = uStack_a;
        gfx_00.ofs = (uint16_t)pfStack_c;
        saveui_usesBlitGfx10(gfx_00,(char *)&text,unaff_SS,(uint *)&cursorX,(int)unaff_SS);
      }
      if (uStack_4 != 0x4b00) break;
L_saveui_4528_1d55_1F0C:
      if (bStack_5 != 0) {
        bStack_5 = bStack_5 - 1;
        auStack_5b[bStack_5 - 1] = 0;
        gfx_01.seg = uStack_a;
        gfx_01.ofs = (uint16_t)pfStack_c;
        saveui_usesBlitGfx10(gfx_01,(char *)&text,unaff_SS,(uint *)&cursorX,(int)unaff_SS);
      }
    }
    if (0x4b00 < uStack_4) {
      if (uStack_4 == 0x4b34) goto L_saveui_4528_1d55_1F0C;
      if (uStack_4 == 0xfffe) {
L_saveui_4528_1d55_1F83:
        inputCancelled = 1;
        handle_00.seg = uStack_a;
        handle_00.ofs = (uint16_t)pfStack_c;
        ovr_stshFree(handle_00);
        return 0xffff;
      }
      if ((uStack_4 == 0xffff) && (MouseMoved == 0)) goto L_saveui_4528_1d55_1F59;
      goto L_saveui_4528_1d55_1E1D;
    }
    if (uStack_4 == 0x11b) goto L_saveui_4528_1d55_1F83;
    if (uStack_4 == 0xe08) goto L_saveui_4528_1d55_1F0C;
    if (uStack_4 == 0x1c0d) {
L_saveui_4528_1d55_1F59:
      handle.seg = uStack_a;
      handle.ofs = (uint16_t)pfStack_c;
      ovr_stshFree(handle);
      if (bStack_5 == 0) {
        iVar2 = -1;
      }
      else {
        iVar2 = saveui_parseNumber((char *)CONCAT22(unaff_SS,&text));
      }
      return iVar2;
    }
  } while( true );
}


