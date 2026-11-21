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
  uint unaff_DI;
  uint16_t *mouseY;
  undefined2 uVar6;
  int iStack_8;
  int iStack_6;
  
  MiceUnkState = 0;
  ovr_ovr_miceButton0PressStates_entry();
  MiceProcessed = 0;
  mouseY = (uint16_t *)((ulong)unaff_DI << 0x10);
  ovr_miceBlitRect();
  iVar3 = MouseY;
  iVar2 = MouseX;
  bVar1 = false;
  MouseMoved = 0;
  while( true ) {
    uVar6 = (undefined2)((ulong)mouseY >> 0x10);
    if ((*(int *)(BDA_DailyTimeCounter.ofs + 2) != iStack_6) ||
       (*(int *)BDA_DailyTimeCounter != iStack_8)) {
      iStack_6 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
      iStack_8 = *(int *)BDA_DailyTimeCounter;
      ovr_draw_usesBlitLoadRleGfx();
      ovr_ovc13_usesMiceBlitRect();
    }
    uVar5 = ovr_biosKeyAvail();
    if ((char)uVar5 != '\0') break;
    mouseY = (uint16_t *)CONCAT22(uVar6,(char *)"puppetmaker" + 3);
    bVar4 = ovr_init2_usesCFGMice((uint16_t *)0xe62410,mouseY,0xe4);
    if (CONCAT11(extraout_AH,bVar4) == 0) {
      bVar1 = true;
    }
    else if (((bVar1) || (MouseX != iVar2)) || (MouseY != iVar3)) {
      if (!bVar1) {
        MouseMoved = 1;
      }
      ovr_miceRestoreArea();
      MouseBkgPixel = *(undefined1 *)(MouseY * 0x140 + MouseX);
      ovr_draw_usesBlitLoadRleGfx2();
      ovr_resetTextBlitCycle();
      return 0xffff;
    }
    if (rightButtonLatch != '\0') {
      ovr_miceRestoreArea();
      MouseBkgPixel = *(undefined1 *)(MouseY * 0x140 + MouseX);
      ovr_draw_usesBlitLoadRleGfx2();
      ovr_resetTextBlitCycle();
      return 0xfffe;
    }
  }
  ovr_miceRestoreArea();
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
  else {
    CrossBlitX = 0x16;
    CrossBlitY = (uint)GMenuItem * 0xf + 0xb;
    in_DX = 0x2410;
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



/* 4528:02fb */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far saveui_usesBlitLoadRleGfx2(far_t textTable,int rowIndex,int itemOffset)

{
  undefined2 *puVar1;
  uint8_t unaff_DI;
  uint16_t uVar2;
  
  ovr_blitLoadRleGfx();
  TextBlitX = 0x2a;
  TextBlitY = rowIndex * 0xf + 0x1d;
  uVar2 = textTable.seg;
  puVar1 = (undefined2 *)(textTable.ofs + (rowIndex + itemOffset) * 4);
  ovr_blitText((char *)CONCAT22(Font03.ofs,(char *)puVar1[1]),(byte *)CONCAT22(0xde,Font03.seg),8,
               unaff_DI,*puVar1);
  ovr_ovc28_usesBDADailyTimeCounter();
  ovr_blitLoadRleGfx();
  TextBlitX = 0x2a;
  TextBlitY = rowIndex * 0xf + 0x1d;
  puVar1 = (undefined2 *)(textTable.ofs + (rowIndex + itemOffset) * 4);
  ovr_blitText((char *)CONCAT22(Font03.ofs,(char *)puVar1[1]),(byte *)CONCAT22(0xde,Font03.seg),0xf,
               unaff_DI,*puVar1);
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
  undefined1 unaff_BP;
  far_t gfx;
  
  ovr_ovc18_blitPanelIfNotRunning();
  gfx.seg = 0;
  gfx.ofs = nwpanel2Cut1Seg;
  ovr_blitGfxRect(gfx,0,1098,(brect_t *)0x102410,0x0,(bool)unaff_BP,nwpanel2Cut1Ofs);
  return;
}



/* 4528:055b */

/* [R4] calls ovr_blitGfx10 */

void __cdecl16far saveui_usesBlitGfx10(far_t gfx,char *text,byte *widths,uint *cursorX,int row)

{
  far_t gfx_00;
  far_t gfx_01;
  far_t dst;
  uint8_t unaff_SI;
  uint unaff_SS;
  undefined2 in_stack_00000004;
  uint8_t rect;
  int iStack_a;
  int iStack_6;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&rect;
  F_SCOPY(far_from_u32((uint32_t)(0x241026ad)),dst);
  rect = *(uint *)CONCAT22((byte *)widths,(*(uint16_t *)((uint8_t *)&(text) + 2)));
  iStack_a = (*(uint16_t *)((uint8_t *)&(widths) + 2)) * 0xf + 0x1d;
  iStack_6 = (*(uint16_t *)((uint8_t *)&(widths) + 2)) * 0xf + 0x28;
  gfx_00.seg = 0x16;
  gfx_00.ofs = gfx.ofs;
  ovr_blitGfx10(gfx_00,(*(uint16_t *)((uint8_t *)&(widths) + 2)) * 0xf + 0x1d,(uint16_t)&rect,(brect_t *)(ulong)unaff_SS,
                (bool)unaff_SI,in_stack_00000004,(char)&rect);
  TextBlitX = 0x2a;
  TextBlitY = (*(uint16_t *)((uint8_t *)&(widths) + 2)) * 0xf + 0x1d;
  ovr_blitText((char *)CONCAT22(Font03.ofs,(char *)text),(byte *)CONCAT22(0xde,Font03.seg),0xf,
               unaff_SI,gfx.seg,(char)Font03.seg);
  if (TextBlitX < *(uint *)CONCAT22((byte *)widths,(*(uint16_t *)((uint8_t *)&(text) + 2)))) {
    rect = TextBlitX;
    gfx_01.seg = 0x16;
    gfx_01.ofs = gfx.ofs;
    ovr_blitGfx10(gfx_01,(*(uint16_t *)((uint8_t *)&(widths) + 2)) * 0xf + 0x1d,(uint16_t)&rect,(brect_t *)(ulong)unaff_SS,
                  (bool)unaff_SI,in_stack_00000004,(char)&rect);
  }
  *(uint16_t *)CONCAT22((byte *)widths,(*(uint16_t *)((uint8_t *)&(text) + 2))) = TextBlitX;
  ovr_blitLetter((char)Font03.ofs,(byte *)CONCAT22(0xf,Font03.seg),unaff_SI,0x5f);
  return;
}



/* 4528:0664 */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far saveui_usesBlitLoadRleGfx3(far_t entries,int count)

{
  int *piVar1;
  undefined2 *puVar2;
  int iVar3;
  uint unaff_DI;
  uint16_t uVar4;
  undefined2 uVar6;
  long lVar5;
  
  lVar5 = (ulong)unaff_DI << 0x10;
  for (iVar3 = 0; iVar3 < count; iVar3 = iVar3 + 1) {
    uVar4 = entries.seg;
    piVar1 = (int *)(entries.ofs + iVar3 * 4);
    if (*piVar1 != 0 || piVar1[1] != 0) {
      uVar6 = (undefined2)((ulong)lVar5 >> 0x10);
      ovr_blitLoadRleGfx();
      TextBlitX = 0x2a;
      TextBlitY = iVar3 * 0xf + 0x1d;
      lVar5 = CONCAT22(uVar6,0xf);
      puVar2 = (undefined2 *)(entries.ofs + iVar3 * 4);
      ovr_blitText((char *)CONCAT22(Font03.ofs,(char *)puVar2[1]),(byte *)CONCAT22(0xde,Font03.seg),
                   0xf,(uint8_t)uVar6,*puVar2);
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
  undefined2 unaff_DI;
  uint16_t unaff_SS;
  int in_stack_00000004;
  uint8_t dest;
  undefined2 auStack_26 [13];
  undefined2 uStack_c;
  undefined2 uStack_a;
  uint16_t sz;
  int iStack_6;
  uint8_t readed;
  byte bStack_3;
  
  TextBlitDstSeg = 0xa000;
  if (in_stack_00000004 != 0 || (char *)title != (char *)0x0) {
    TextBlitX = 0x16;
    TextBlitY = 0xb;
    ovr_blitText();
  }
  iStack_6 = 0;
  if ((int)items.seg < 9) {
    sz = items.seg;
  }
  else {
    sz = 8;
  }
  for (readed = 0x0; (int)(uint)readed < (int)sz; readed = readed + 0x1) {
    puVar5 = (undefined2 *)((*(uint16_t *)((uint8_t *)&(title) + 2)) + (uint)readed * 4);
    uVar3 = *puVar5;
    uVar4 = (uint)readed;
    auStack_26[uVar4 * 2] = puVar5[1];
    *(undefined2 *)(&dest + uVar4 * 4) = uVar3;
  }
  if (8 < (int)items.seg) {
    uStack_a = 0x2410;
    uStack_c = 0x2733;
  }
  entries.seg = unaff_SS;
  entries.ofs = (uint16_t)&dest;
  saveui_usesBlitLoadRleGfx3(entries,sz);
  GMenuItem = (byte)nitems;
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
    if (0x5000 < uVar2) {
      if (uVar2 != 0x5133) {
        if (0x5133 < uVar2) {
          if (uVar2 == 0xfffe) {
            GMenuFlag = 0;
            return;
          }
          if (uVar2 == 0xffff) {
            textTable.seg = unaff_SS;
            textTable.ofs = (uint16_t)&dest;
            uVar3 = saveui_usesMouseMoved(textTable,sz,0);
            bStack_3 = (byte)uVar3;
            bVar1 = bStack_3;
            if (bStack_3 != 0xff) {
L_uiMenuSub_0B46:
              GMenuItem = bVar1;
              if (GMenuItem != 0) {
                textTable_00.seg = unaff_SS;
                textTable_00.ofs = (uint16_t)&dest;
                saveui_usesBlitLoadRleGfx2(textTable_00,GMenuItem - 1,0);
              }
              if (((int)items.seg < 9) || (GMenuItem != 8)) {
                GMenuFlag = 0;
                return;
              }
              if (iStack_6 + 7 < (int)items.seg) {
                iStack_6 = iStack_6 + 7;
              }
              else {
                iStack_6 = 0;
              }
              _fsetmem((uint8_t *)CONCAT22(unaff_SS,&dest),0x1c,0);
              for (readed = 0x0; (readed < 7 && ((int)((uint)readed + iStack_6) < (int)items.seg));
                  readed = readed + 0x1) {
                puVar5 = (undefined2 *)((*(uint16_t *)((uint8_t *)&(title) + 2)) + ((uint)readed + iStack_6) * 4);
                uVar3 = *puVar5;
                uVar4 = (uint)readed;
                auStack_26[uVar4 * 2] = puVar5[1];
                *(undefined2 *)(&dest + uVar4 * 4) = uVar3;
              }
              saveui_blitPanel();
              if (in_stack_00000004 != 0 || (char *)title != (char *)0x0) {
                TextBlitX = 0x16;
                TextBlitY = 0xb;
                ovr_blitText((char *)CONCAT22(Font03.ofs,(char *)title),
                             (byte *)CONCAT22(0xde,Font03.seg),7,(uint8_t)unaff_DI,in_stack_00000004
                            );
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
      if (8 < (int)items.seg) {
        if (iStack_6 + 7 < (int)items.seg) {
          iStack_6 = iStack_6 + 7;
        }
        else {
          iStack_6 = 0;
        }
        _fsetmem((uint8_t *)CONCAT22(unaff_SS,&dest),0x1c,0);
        for (readed = 0x0; (readed < 7 && ((int)((uint)readed + iStack_6) < (int)items.seg));
            readed = readed + 0x1) {
          puVar5 = (undefined2 *)((*(uint16_t *)((uint8_t *)&(title) + 2)) + ((uint)readed + iStack_6) * 4);
          uVar3 = *puVar5;
          uVar4 = (uint)readed;
          auStack_26[uVar4 * 2] = puVar5[1];
          *(undefined2 *)(&dest + uVar4 * 4) = uVar3;
        }
        saveui_blitPanel();
        if (in_stack_00000004 != 0 || (char *)title != (char *)0x0) {
          TextBlitX = 0x16;
          TextBlitY = 0xb;
          ovr_blitText((char *)CONCAT22(Font03.ofs,(char *)title),(byte *)CONCAT22(0xde,Font03.seg),
                       7,(uint8_t)unaff_DI,in_stack_00000004);
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
    else if (((uVar2 == 0x4900) || (uVar2 == 0x4939)) && (8 < (int)items.seg)) {
      if (iStack_6 == 0) {
        iStack_6 = ((int)(items.seg - 1) / 7) * 7;
      }
      else {
        iStack_6 = iStack_6 + -7;
      }
      _fsetmem((uint8_t *)CONCAT22(unaff_SS,&dest),0x1c,0);
      for (readed = 0x0; (readed < 7 && ((int)((uint)readed + iStack_6) < (int)items.seg));
          readed = readed + 0x1) {
        puVar5 = (undefined2 *)((*(uint16_t *)((uint8_t *)&(title) + 2)) + ((uint)readed + iStack_6) * 4);
        uVar3 = *puVar5;
        uVar4 = (uint)readed;
        auStack_26[uVar4 * 2] = puVar5[1];
        *(undefined2 *)(&dest + uVar4 * 4) = uVar3;
      }
      saveui_blitPanel();
      if (in_stack_00000004 != 0 || (char *)title != (char *)0x0) {
        TextBlitX = 0x16;
        TextBlitY = 0xb;
        ovr_blitText((char *)CONCAT22(Font03.ofs,(char *)title),(byte *)CONCAT22(0xde,Font03.seg),7,
                     (uint8_t)unaff_DI,in_stack_00000004);
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

/* WARNING: Variable defined which should be unmapped: text */

char * __cdecl16far uiReadString(char *textOfs,int textSeg,int row,char *gfxOfs,uint16_t gfxSeg,...)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t src;
  far_t gfx_02;
  far_t dst;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  far_t handle_03;
  far_t handle_04;
  size_t sVar1;
  far_t *pfVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint8_t *puVar6;
  uint16_t uVar7;
  undefined2 uVar8;
  undefined2 unaff_SI;
  byte *unaff_SS;
  int in_stack_00000004;
  uint8_t *puVar9;
  uint8_t term;
  undefined1 uVar10;
  uint8_t text;
  undefined1 uStack_5b;
  int in_stack_0000ffa6;
  uint8_t cursorX;
  byte bStack_5;
  uint16_t uStack_4;
  
  term = (uint8_t)unaff_SI;
  uVar10 = (undefined1)((uint)unaff_SI >> 8);
  UserWantsExit = 0;
  inputCancelled = 0;
  if (in_stack_00000004 != 0 || (char *)textOfs != (char *)0x0) {
    TextBlitX = 0x16;
    TextBlitY = 0xb;
    ovr_blitText((char *)CONCAT22(Font03.ofs,(char *)textOfs),(byte *)CONCAT22(0xde,Font03.seg),7,
                 term,in_stack_00000004);
  }
  if (textSeg == 0 && row == 0) {
    text = 0x0;
  }
  else {
    strcpy((char *)CONCAT22(unaff_SS,&text),(char *)CONCAT22(row,textSeg));
  }
  sVar1 = strlen((char *)CONCAT22(unaff_SS,&text));
  bStack_5 = (byte)sVar1;
  uVar7 = (uint16_t)((ulong)((long)(*(uint16_t *)((uint8_t *)&(textOfs) + 2)) * 0xf) >> 0x10);
  src.seg = (int)((long)(*(uint16_t *)((uint8_t *)&(textOfs) + 2)) * 0xf) + 0x1d;
  src.ofs = 0x16;
  pfVar2 = ovr_stshRleCut((far_t *)0xa000,src,222,(*(uint16_t *)((uint8_t *)&(textOfs) + 2)) * 0xf + 0x29,0);
  TextBlitX = 0x2a;
  TextBlitY = (*(uint16_t *)((uint8_t *)&(textOfs) + 2)) * 0xf + 0x1d;
  cursorX = 0;
  gfx.seg = (uint16_t)&text;
  gfx.ofs = uVar7;
  saveui_usesBlitGfx10
            (gfx,(char *)CONCAT22(&cursorX,unaff_SS),(byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(textOfs) + 2)),unaff_SS),
             (uint *)CONCAT13(uStack_5b,CONCAT12(text,CONCAT11(uVar10,term))),in_stack_0000ffa6);
  gfx_02.seg = (*(uint16_t *)((uint8_t *)&(textOfs) + 2)) * 0x12c0 + 0x2096;
  gfx_02.ofs = trianglsCut4Seg;
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = term;
  dst.ofs = 0xa000;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar10;
  ovr_blitLoadRleGfx(gfx_02,dst,trianglsCut4Ofs);
  ovr_ovc40_flushInput();
  GMenuFlag = 1;
L_uiReadString_0DC9:
  do {
    while( true ) {
      while ((((uStack_4 = uiReadKey2(), 0x1f < (uStack_4 & 0xff) && ((uStack_4 & 0xff) < 0x7f)) &&
              (bStack_5 < 0x4f)) && ((uStack_4 & 0xff) != 0x40))) {
        (&text)[bStack_5] = (uint8_t)uStack_4;
        (&uStack_5b)[bStack_5] = 0;
        iVar3 = ovr_font_textWidth((char *)CONCAT22(Font03.ofs,unaff_SS),
                                   (char *)CONCAT13(uVar10,CONCAT12(term,Font03.seg)),&text);
        iVar4 = ovr_font_textWidth((char *)CONCAT22(Font03.ofs,(char *)"puppetmaker" + 3),
                                   (char *)CONCAT22(iVar3,Font03.seg),0x2738);
        if (iVar3 + iVar4 + 0x2aU < 0xe0) {
          bStack_5 = bStack_5 + 1;
        }
        (&text)[bStack_5] = 0x0;
        gfx_00.seg = (uint16_t)&text;
        gfx_00.ofs = uVar7;
        saveui_usesBlitGfx10
                  (gfx_00,(char *)CONCAT22(&cursorX,unaff_SS),
                   (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(textOfs) + 2)),unaff_SS),
                   (uint *)CONCAT13(uStack_5b,CONCAT12(text,CONCAT11(uVar10,term))),
                   in_stack_0000ffa6);
      }
      if (uStack_4 != 0x4b00) break;
L_uiReadString_0ECE:
      if (bStack_5 != 0) {
        bStack_5 = bStack_5 - 1;
        (&text)[bStack_5] = 0x0;
        gfx_01.seg = (uint16_t)&text;
        gfx_01.ofs = uVar7;
        saveui_usesBlitGfx10
                  (gfx_01,(char *)CONCAT22(&cursorX,unaff_SS),
                   (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(textOfs) + 2)),unaff_SS),
                   (uint *)CONCAT13(uStack_5b,CONCAT12(text,CONCAT11(uVar10,term))),
                   in_stack_0000ffa6);
      }
    }
    if (uStack_4 < 0x4b01) {
      if (uStack_4 == 0x11b) {
        UserWantsExit = 1;
L_uiReadString_1068:
        inputCancelled = 1;
        (*(uint8_t *)((uint8_t *)&(handle_03.seg))) = term;
        handle_03.ofs = uVar7;
        (*(uint8_t *)((uint8_t *)&(handle_03.seg) + 1)) = uVar10;
        ovr_stshFree(handle_03,pfVar2);
        if (textSeg != 0 || row != 0) {
          (*(uint8_t *)((uint8_t *)&(handle_04.seg))) = term;
          handle_04.ofs = row;
          (*(uint8_t *)((uint8_t *)&(handle_04.seg) + 1)) = uVar10;
          ovr_stshFree(handle_04,textSeg);
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
        (*(uint8_t *)((uint8_t *)&(handle.seg))) = term;
        handle.ofs = uVar7;
        (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uVar10;
        ovr_stshFree(handle,pfVar2);
        if (textSeg != 0 || row != 0) {
          (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = term;
          handle_00.ofs = row;
          (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = uVar10;
          ovr_stshFree(handle_00,textSeg);
        }
        GMenuFlag = 0;
        return (char *)0x0;
      }
      if ((((MouseMoved == 0) && (0x15 < MouseX)) && (MouseX < 0x26)) &&
         (((*(uint16_t *)((uint8_t *)&(textOfs) + 2)) * 0xf + 0x1aU <= MouseY && (MouseY <= (*(uint16_t *)((uint8_t *)&(textOfs) + 2)) * 0xf + 0x28U)))) {
L_uiReadString_0FF7:
        (*(uint8_t *)((uint8_t *)&(handle_01.seg))) = term;
        handle_01.ofs = uVar7;
        (*(uint8_t *)((uint8_t *)&(handle_01.seg) + 1)) = uVar10;
        ovr_stshFree(handle_01,pfVar2);
        GMenuFlag = 0;
        if (bStack_5 == 0) {
          if (textSeg != 0 || row != 0) {
            (*(uint8_t *)((uint8_t *)&(handle_02.seg))) = term;
            handle_02.ofs = row;
            (*(uint8_t *)((uint8_t *)&(handle_02.seg) + 1)) = uVar10;
            ovr_stshFree(handle_02,textSeg);
          }
          pcVar5 = (char *)0x0;
        }
        else {
          puVar9 = &text;
          uVar8 = 0;
          puVar6 = ovr_stshRealloc(CONCAT22(bStack_5 + 1,row),ZEXT24(puVar9) << 0x10,textSeg);
          pcVar5 = strcpy((char *)CONCAT22(uVar8,puVar6),(char *)CONCAT22(unaff_SS,puVar9));
        }
        return pcVar5;
      }
    }
  } while( true );
}



/* 4528:10a8 */

void __cdecl16far uiMenu(char *title,far_t items,int nitems,...)

{
  uint16_t unaff_BP;
  undefined2 in_stack_00000004;
  
  uiMenuSub(title,items,1,unaff_BP);
  return;
}



/* 4528:10c5 */

/* Writes a text line followed by CRLF to a file handle. */

void __cdecl16far saveui_writeLine(int handle,char *text,int count,...)

{
  int handle_00;
  size_t len;
  int in_stack_00000004;
  
  handle_00 = in_stack_00000004;
  if (handle != 0 || (char *)text != (char *)0x0) {
    len = strlen((char *)CONCAT22((char *)text,handle));
    write(handle_00,(void *)CONCAT22((char *)text,handle),len);
  }
  write(handle_00,"\r\n",2);
  return;
}



/* 4528:1104 */

/* Reads one line from the file and returns a heap copy (empty for ^Z/empty lines). */

char * __cdecl16far saveui_readLine(int fd,...)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  uint unaff_DI;
  void *unaff_SS;
  int in_stack_00000004;
  uint8_t *puVar5;
  uint8_t lineBuf;
  
  iVar3 = in_stack_00000004;
  iVar4 = 0;
  while (iVar4 < 0x4f) {
    iVar1 = read(iVar3,(void *)CONCAT22(1,unaff_SS),unaff_DI);
    if ((iVar1 != 1) || ((&lineBuf)[iVar4] == 0xa)) break;
    if ((&lineBuf)[iVar4] != 0xd) {
      iVar4 = iVar4 + 1;
    }
  }
  if (lineBuf == 0x1a) {
    iVar4 = 0;
  }
  (&lineBuf)[iVar4] = 0x0;
  if (iVar4 == 0) {
    pcVar2 = (char *)0x0;
  }
  else {
    puVar5 = &lineBuf;
    iVar3 = iVar4 + 1 >> 0xf;
    pcVar2 = ovr_stshAlloc(CONCAT22(puVar5,iVar3),iVar4 + 1);
    pcVar2 = strcpy((char *)CONCAT22(iVar3,pcVar2),(char *)CONCAT22(unaff_SS,puVar5));
  }
  return pcVar2;
}



/* 4528:1175 */

/* Reads the save-slot list from saves.txt. */

uint __cdecl16far saveui_readSavesList(int entries,uint16_t entriesSeg)

{
  far_t handle;
  char *pcVar1;
  int handle_00;
  char *pcVar2;
  undefined2 uVar3;
  char *in_DX;
  undefined2 *puVar4;
  uint uVar5;
  uint16_t unaff_DI;
  uint16_t uStack_4;
  
  uStack_4 = 0;
  pcVar1 = ovr_fmVsprintf((char *)0x8c6c2410,(char *)CONCAT22(unaff_DI,(char *)"puppetmaker" + 3));
  handle_00 = ovr_open_wait_unlock_and_disk((char *)CONCAT22(unaff_DI,in_DX),pcVar1);
  if (-1 < handle_00) {
    pcVar2 = (char *)saveui_readLine(unaff_DI,handle_00);
    pcVar1 = in_DX;
    uStack_4 = _atol((char *)CONCAT22(in_DX,pcVar2));
    handle.seg = unaff_DI;
    handle.ofs = (uint16_t)in_DX;
    ovr_stshFree(handle,pcVar2);
    for (uVar5 = 0; uVar5 < uStack_4; uVar5 = uVar5 + 1) {
      uVar3 = saveui_readLine(unaff_DI,handle_00);
      puVar4 = (undefined2 *)(entries + uVar5 * 4);
      puVar4[1] = pcVar1;
      *puVar4 = uVar3;
    }
    close(handle_00);
  }
  return uStack_4;
}



/* 4528:120d */

/* Writes the save-slot list to saves.txt (count line plus one line per entry). */

void __cdecl16far saveui_writeSavesList(far_t entries,uint count)

{
  int handle;
  uint uVar1;
  undefined2 unaff_DI;
  undefined2 unaff_SS;
  uint8_t msg;
  
  ovr_fmVsprintf((char *)0x8c6c2410,(char *)CONCAT22(unaff_DI,(char *)"puppetmaker" + 3));
  handle = ovr_creat_wait_unlock_and_disk();
  if (-1 < handle) {
    _sprintf((char *)CONCAT22(unaff_SS,&msg),"%u");
    saveui_writeLine();
    for (uVar1 = 0; uVar1 < count; uVar1 = uVar1 + 1) {
      saveui_writeLine();
    }
    close(handle);
  }
  return;
}



/* 4528:1288 */

/* Frees and clears a list of heap lines. */

void __cdecl16far saveui_freeLines(far_t entries,uint count)

{
  far_t handle;
  int iVar1;
  uint16_t uVar2;
  int *piVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint16_t unaff_DI;
  uint16_t uVar6;
  
  for (uVar5 = 0; uVar5 < count; uVar5 = uVar5 + 1) {
    uVar6 = entries.seg;
    uVar2 = entries.ofs;
    piVar3 = (int *)(uVar2 + uVar5 * 4);
    if (*piVar3 != 0 || piVar3[1] != 0) {
      puVar4 = (undefined2 *)(uVar2 + uVar5 * 4);
      iVar1 = strcmp((char *)CONCAT22(puVar4[1],(char *)*puVar4),
                     (char *)CONCAT22(GSPEmpty.seg,GSPEmpty.ofs));
      if (iVar1 != 0) {
        puVar4 = (undefined2 *)(uVar2 + uVar5 * 4);
        handle.seg = unaff_DI;
        handle.ofs = puVar4[1];
        ovr_stshFree(handle,*puVar4);
      }
    }
    puVar4 = (undefined2 *)(uVar2 + uVar5 * 4);
    puVar4[1] = 0;
    *puVar4 = 0;
  }
  return;
}



/* 4528:1303 */

/* WARNING: Instruction at (ram,0x0004072b) overlaps instruction at (ram,0x0004072a)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Variable defined which should be unmapped: menuLabel */
/* Edits the message delay, persists it to cflow4.txt and reports the new value. */

char * __cdecl16far saveui_configureMessageDelay(void)

{
  uint *puVar1;
  uint16_t *puVar2;
  uint8_t *puVar3;
  byte *pbVar4;
  undefined4 uVar5;
  far_t items;
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
  uint *puVar14;
  byte bVar15;
  int iVar16;
  byte *unaff_SI;
  uint unaff_DI;
  undefined2 uVar17;
  undefined2 uVar18;
  uint16_t unaff_SS;
  byte abStackY_15bc [5516];
  undefined2 uStackY_30;
  undefined2 uStackY_2e;
  undefined2 uStackY_2c;
  uint8_t menuLabel;
  entity_t *peStack_1e;
  undefined2 uStack_1c;
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
  
  bStack_3 = 0;
  GMenuItem = '\x01';
  while( true ) {
    ovr_resetTextBlitCycle();
    saveui_blitPanel();
    ovr_fmVsprintf((char *)(ulong)CONCAT12(MessageDelay,0x2410),
                   (char *)CONCAT22(peStack_1e,menuLabel));
    ovr_say();
    if (MessageDelay == 0) {
      peStack_1e = (entity_t *)0x0;
      menuLabel = (char *)0x0;
    }
    else {
      peStack_1e = (entity_t *)((char *)"puppetmaker" + 3);
      menuLabel = (char *)"Decrease message delay";
    }
    if (MessageDelay < 0x28) {
      uStack_1a = 0x2410;
      uStack_1c = 0x277c;
    }
    else {
      uStack_1a = 0;
      uStack_1c = 0;
    }
    iStack_16 = 0x2410;
    uStack_18 = 0x2793;
    iStack_12 = 0x2410;
    iStack_14 = 0x2798;
    puVar12 = &menuLabel;
    uStackY_2c = 0x279d;
    uStackY_2e = 0x22c4;
    uStackY_30 = 0x662e;
    items.seg = 4;
    items.ofs = unaff_SS;
    uiMenuSub((char *)CONCAT22(puVar12,(char *)"puppetmaker" + 3),items,CONCAT11(0x24,GMenuItem),
              (uint16_t)menuLabel);
    bStack_4 = (byte)puVar12;
    uVar8 = (uint)puVar12 & 0xff;
    if (uVar8 < 5) break;
    if ((char *)(uint)bStack_3 != (char *)0x0) {
      return (char *)(uint)bStack_3;
    }
  }
  puVar14 = (uint *)(uVar8 * 2);
  uVar17 = 0x4000;
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
    bVar15 = *unaff_SI;
    *(uint *)((byte *)((int)puVar14 + (int)unaff_SI) + -0x6af7) =
         *(uint *)((byte *)((int)puVar14 + (int)unaff_SI) + -0x6af7) | unaff_DI;
    *(uint *)(&stack0x0007 + (int)unaff_SI) =
         *(uint *)(&stack0x0007 + (int)unaff_SI) | (uint)unaff_SI;
    puVar1 = (uint *)(&stack0xffff + unaff_DI);
    *puVar1 = *puVar1 | unaff_DI;
    *puVar14 = *puVar14 | (uint)&stack0xffff;
                    /* WARNING: Read-only address (ram,0x00025f09) is written */
    (*(uint16_t *)((uint8_t *)&(s_fighters__residence_2410_1e09))) = (uint)&stack0xffde | 0x6966;
    bVar15 = (byte)((uint)puVar14 >> 8) | (byte)in_CX | bVar15 | (byte)unaff_DI;
    iVar16 = CONCAT11(bVar15,(byte)puVar14);
    pbVar4 = (byte *)(iVar16 + -0x51f8);
    *pbVar4 = *pbVar4 | bVar15;
    ((char *)"cflow4.txt" + 7)[unaff_DI] =
         ((char *)"cflow4.txt" + 7)[unaff_DI] | (byte)in_DX | (byte)puVar14;
    unaff_SI[iVar16 + 8] = unaff_SI[iVar16 + 8] | bVar15;
    (&stack0x0007)[(int)unaff_SI] = (&stack0x0007)[(int)unaff_SI] | (byte)puVar12;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 2:
    ((byte *)((int)puVar14 + (int)unaff_SI))[-0x75] =
         ((byte *)((int)puVar14 + (int)unaff_SI))[-0x75] + (byte)in_DX;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 3:
    break;
  }
switchD_4000_6642_caseD_3:
  *(int *)(abStackY_15bc + (int)unaff_SI) = *(int *)(abStackY_15bc + (int)unaff_SI) + in_CX;
  if (uVar8 == 0) {
    ovr_ovc15_clearVisited();
    uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)((ulong)((peStack_1e->base).animFrame + 0xf) / 0x10))
    ;
    if (((peStack_1e->base).target & 1) == 0) {
      iStack_16 = 0;
    }
    else {
      iStack_16 = (peStack_1e->base).target - 2;
    }
    while( true ) {
      uVar17 = 0x2322;
      cVar6 = (char)uStack_1a;
      uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)uStack_1a + -1);
      if (cVar6 == '\0') break;
      ovr_ovc15_textArena();
    }
  }
  else if ((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) == '\0') {
    uStack_1a = (uint)(byte)((ulong)((peStack_1e->base).animFrame + 0xf) / 0x10);
    while( true ) {
      cVar6 = (char)uStack_1a;
      uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)uStack_1a + -1);
      if (cVar6 == '\0') break;
      uVar17 = 0x22ff;
      ovr_agnt_usesAgntCount6();
    }
  }
  else if (((char)uStack_18 != '\0') && ((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) != '\0')) {
    uVar7 = func_0x0004f944();
    uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),uVar7);
    while ((char)uStack_1a != '\0') {
      if (((peStack_1e->base).target & 1) == 0) {
        iStack_16 = 0;
      }
      else {
        iStack_16 = (peStack_1e->base).target - 2;
      }
      uVar17 = 0x2322;
      pcVar11 = ovr_ovc15_textArena();
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
          uVar18 = uVar17;
          if (DebugVerbose != false) {
            uVar18 = 0x1000;
            uStackY_2e = 0x878;
            uStackY_2c = uVar17;
            printf("%d %d %d  \r");
          }
          func_0x0004fcda();
          GGameState = 0x3d;
          if (DebugVerbose != false) {
            uStackY_2e = 0x8b3;
            uStackY_2c = uVar18;
            printf("%d %d %d  \r");
          }
          ovr_OVC23_55fe_29a2_entry();
          GGameState = 0xc;
          if (DebugVerbose != false) {
            uStackY_2c = 0x236f;
            uStackY_2e = 0x8ef;
            printf("%d %d %d  \r");
          }
          uVar17 = 0x2379;
          ovr_ovc24_removeOtherEntities();
          GGameState = 0x1f;
          if ((*(uint8_t *)((uint8_t *)&(uStack_18) + 1)) != '\0') {
            uVar17 = 0x22ef;
            ovr_constr_usesBlitRect();
            GGameState = 0x13;
          }
          func_0x0004f68f();
          GGameState = 0x1d;
          for (iVar16 = 0; iVar16 < 5; iVar16 = iVar16 + 1) {
            if (acStack_e[iVar16] != '\0') {
              uVar17 = 0x23d5;
              ovr_ovc41_usesMiceBlitRect();
            }
          }
          GGameState = 0xd;
          if (DebugVerbose != false) {
            uStackY_2e = 0x98b;
            uStackY_2c = uVar17;
            printf("%d %d %d  \r");
          }
          ovr_ovc24_checkStrongholds();
          GGameState = 0xe;
          mapDirty = 1;
          return (char *)"puppetmaker" + 3;
        }
        peStack_1e = (entity_t *)Entities + unaff_DI;
        uStack_1c = (*(uint16_t *)((uint8_t *)&(Entities) + 2));
        uVar8 = ovr_alignUp4();
        uVar17 = 0x2379;
        uVar9 = ovr_alignUp4();
        if ((uVar8 == uVar9) && ((peStack_1e->base).destY == (peStack_1e->base).y)) {
          uStackY_2c = 0x2379;
          uStackY_2e = 0x204;
          func_0x0004fb8e();
        }
      } while (((peStack_1e->base).destX == 0 && (peStack_1e->base).destY == 0) ||
              (*(char *)((int)&(peStack_1e->base).entity + 1) != '\0'));
      bStack_3 = (*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                           (uint)(peStack_1e->base).gindex * 0x95) & 0x4000) != 0;
      uStack_6 = (((entity_t *)CONCAT22(uStack_1c,peStack_1e))->base).x;
      uStack_8 = (peStack_1e->base).y;
      uStack_f = *(undefined1 *)
                  ((int)(char **)GMenuStrings + (uint)(peStack_1e->base).gindex * 0x95 + 0x1f);
      if ((peStack_1e->base).faction < (byte)(peStack_1e->base).state) {
        sVar13 = ((peStack_1e->base).faction & 3) << 1;
        in_CX = CONCAT11((char)((uint)in_CX >> 8),sVar13);
        (peStack_1e->base).target =
             (byte)((int)(uint)*(byte *)((int)&(peStack_1e->base).owner +
                                        ((int)(uint)(peStack_1e->base).faction >> 2)) >> sVar13) & 3
        ;
        uStackY_2c = 0x2e4;
        cVar6 = func_0x0004f32d();
        if (cVar6 == '\0') {
          (((entity_t *)CONCAT22(uStack_1c,peStack_1e))->base).x =
               (((entity_t *)CONCAT22(uStack_1c,peStack_1e))->base).x +
               (int)*(char *)((peStack_1e->base).target + 0x885);
          puVar2 = &(peStack_1e->base).y;
          *puVar2 = *puVar2 + (int)*(char *)((peStack_1e->base).target + 0x889);
          puVar3 = &(peStack_1e->base).faction;
          *puVar3 = *puVar3 + 0x1;
        }
        else {
          (peStack_1e->base).faction = 0x0;
          *(undefined1 *)&(peStack_1e->base).state = 0;
        }
      }
      else {
        iStack_12 = ovr_ovc07_signum();
        uVar17 = 0x22da;
        iStack_14 = ovr_ovc07_signum();
        if (iStack_12 != 0) {
          uVar17 = 0x2337;
          uVar10 = ovr_randBelow();
          if ((char)uVar10 != '\0') {
            uStackY_2c = 0x2337;
            uStackY_2e = 0x399;
            cVar6 = func_0x0004f412();
            if (cVar6 == '\0') {
              (((entity_t *)CONCAT22(uStack_1c,peStack_1e))->base).x =
                   (((entity_t *)CONCAT22(uStack_1c,peStack_1e))->base).x + iStack_12;
              (peStack_1e->base).target = 0x2 - (char)iStack_12;
              goto L_attact_3f0b_1082_1477;
            }
          }
        }
        if (iStack_14 != 0) {
          uStackY_2e = 0x3d8;
          uStackY_2c = uVar17;
          cVar6 = func_0x0004f412();
          if (cVar6 == '\0') {
            puVar2 = &(peStack_1e->base).y;
            *puVar2 = *puVar2 + iStack_14;
            (peStack_1e->base).target = (char)iStack_14 + 0x1;
            goto L_attact_3f0b_1082_1477;
          }
        }
        if (iStack_12 != 0) {
          uStackY_2e = 0x418;
          uStackY_2c = uVar17;
          cVar6 = func_0x0004f412();
          if (cVar6 == '\0') {
            (((entity_t *)CONCAT22(uStack_1c,peStack_1e))->base).x =
                 (((entity_t *)CONCAT22(uStack_1c,peStack_1e))->base).x + iStack_12;
            (peStack_1e->base).target = 0x2 - (char)iStack_12;
            goto L_attact_3f0b_1082_1477;
          }
        }
        uVar8 = ovr_ovc26_usesStExit();
        if ((char)uVar8 == '\0') {
          uStackY_2c = 0x2386;
          uStackY_2e = 0x4e3;
          uVar8 = ovr_ovc26_usesRandBelow();
          if (((uVar8 & 0xff) == 0) &&
             (*(char *)((int)(char **)GMenuStrings + (uint)(peStack_1e->base).gindex * 0x95 + 0x1f)
              == '\0')) {
            uStackY_2c = 0x2386;
            uStackY_2e = 0x524;
            func_0x0004fb8e();
          }
        }
        else {
          sVar13 = ((peStack_1e->base).faction & 3) << 1;
          in_CX = CONCAT11((char)((uint)in_CX >> 8),sVar13);
          (peStack_1e->base).target =
               (byte)((int)(uint)*(byte *)((int)&(peStack_1e->base).owner +
                                          ((int)(uint)(peStack_1e->base).faction >> 2)) >> sVar13) &
               3;
          uStackY_2c = 0x48f;
          cVar6 = func_0x0004f32d();
          if (cVar6 == '\0') {
            (((entity_t *)CONCAT22(uStack_1c,peStack_1e))->base).x =
                 (((entity_t *)CONCAT22(uStack_1c,peStack_1e))->base).x +
                 (int)*(char *)((peStack_1e->base).target + 0x885);
            puVar2 = &(peStack_1e->base).y;
            *puVar2 = *puVar2 + (int)*(char *)((peStack_1e->base).target + 0x889);
            puVar3 = &(peStack_1e->base).faction;
            *puVar3 = *puVar3 + 0x1;
          }
        }
      }
L_attact_3f0b_1082_1477:
      uStack_18 = CONCAT11(1,(char)uStack_18);
      uVar8 = ovr_alignUp4();
      uVar9 = ovr_alignUp4();
      if ((uVar8 == uVar9) && ((peStack_1e->base).destY == (peStack_1e->base).y)) {
        (peStack_1e->base).destX = 0;
        (peStack_1e->base).destY = 0;
        if (*(char *)((int)&(peStack_1e->base).entity + 3) == -1) {
          bStack_4 = 0xff;
        }
        else {
          uVar5 = *(undefined4 *)((uint)*(byte *)((int)&(peStack_1e->base).entity + 3) << 2);
          bStack_4 = *(byte *)((int)uVar5 + 0x89);
        }
        if (bStack_4 != 0xff) {
          for (unaff_SI = (byte *)0x0; unaff_SI < SquareRecCount; unaff_SI = unaff_SI + 1) {
            uVar8 = ovr_alignUp4();
            uVar9 = ovr_alignUp4();
            if ((uVar8 == uVar9) &&
               (*(uint16_t *)((int)unaff_SI * 0x13 + 2) == (peStack_1e->base).y)) {
              func_0x0004f930();
              if (*(uint16_t *)((int)unaff_SI * 0x13 + 2) == GfxRndSeed2) {
                uVar8 = ovr_alignUp4();
                uVar9 = ovr_alignUp4();
                if (uVar8 == uVar9) {
                  acStack_e[bStack_4] = '\x01';
                }
              }
              break;
            }
          }
        }
      }
      uVar17 = 0x2379;
    } while (AgntFlag1 == false);
    if ((((((entity_t *)CONCAT22(uStack_1c,peStack_1e))->base).x < GfxRndSeed - 2U) ||
        (GfxRndSeed + 1U < (((entity_t *)CONCAT22(uStack_1c,peStack_1e))->base).x)) ||
       ((peStack_1e->base).y != GfxRndSeed2)) {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    uStack_1a = CONCAT11(cVar6,(char)uStack_1a);
    if (((uStack_6 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uStack_6)) || (GfxRndSeed2 != uStack_8))
    {
      bVar15 = 0;
    }
    else {
      bVar15 = 1;
    }
    uStack_18 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_18) + 1)),bVar15);
  } while (bVar15 == 0 && cVar6 == '\0');
  uVar8 = (uint)bVar15;
  goto switchD_4000_6642_caseD_3;
}



/* 4528:144e */

/* [R4] calls ovr_blitLoadRleGfx */

void __cdecl16far saveui_usesBlitLoadRleGfx4(void)

{
  uint16_t unaff_BP;
  far_t gfx;
  far_t dst;
  
  dst.seg = unaff_BP;
  dst.ofs = 0xa000;
  gfx.seg = 0xc31d;
  gfx.ofs = FontHandle.seg;
  ovr_blitLoadRleGfx(gfx,dst,FontHandle.ofs);
  return;
}



/* 4528:1470 */

/* Blits the "Cancel" label at its fixed position in Font03. */

void __cdecl16far saveui_drawCancel(void)

{
  uint8_t unaff_BP;
  
  saveui_usesBlitLoadRleGfx4();
  TextBlitX = 0x1d;
  TextBlitY = 0xb7;
  ovr_blitText((char *)CONCAT22(Font03.ofs,(char *)"puppetmaker" + 3),
               (byte *)CONCAT22(0xcf,Font03.seg),0xf,unaff_BP,0x27e4);
  return;
}



/* 4528:14b1 */

void __cdecl16far uiMainMenuLoop(void)

{
  far_t gfx;
  far_t entries;
  far_t entries_00;
  far_t entries_01;
  far_t entries_02;
  far_t entries_03;
  far_t entries_04;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  bool bVar1;
  bool bVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  byte bVar5;
  char cVar6;
  void *entries_05;
  uint16_t pmenu;
  uint16_t uVar7;
  int iVar8;
  undefined2 uVar9;
  char *pcVar10;
  uint16_t in_DX;
  uint16_t uVar11;
  uint *puVar12;
  uint16_t *puVar13;
  undefined2 *puVar14;
  int *piVar15;
  uint uVar16;
  uint16_t unaff_DI;
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
  ovr_say((char *)CONCAT22(unaff_DI,(char *)"puppetmaker" + 3),0x2851);
  gfx.seg = 0x9af;
  gfx.ofs = GMenuGfxSeg;
  dst_01.seg = unaff_DI;
  dst_01.ofs = 0xa000;
  ovr_blitLoadRleGfx(gfx,dst_01,GMenuGfxOfs);
  ovr_stats_drawStatsPanel();
  saveui_blitPanel();
  entries_05 = ovr_stshAlloc((ulong)unaff_DI << 0x10,400);
  uVar11 = in_DX;
  _fsetmem((void *)CONCAT22(in_DX,entries_05),400,0);
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
    bVar5 = (byte)&menu;
    uiMenu();
    (*(uint8_t *)((uint8_t *)&(pmenu))) = bVar5;
    ovr_say((char *)CONCAT22(unaff_DI,(char *)"puppetmaker" + 3),0x2732);
    if ((byte)pmenu < 9) {
                    /* WARNING: Switch is manually overridden */
      switch((undefined4)
             *(undefined2 *)((char *)"%s: provides for food trade." + 1 + (uint)(byte)pmenu * 2)) {
      case 288826:
        saveui_blitPanel();
        bVar1 = false;
        if ((SaveAuto == '\0') || (GWantsExit2 == '\0')) {
          bVar1 = true;
        }
        else {
          cVar6 = (char)yesno;
          uiMenu();
          if (cVar6 == '\x01') {
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
        entries.ofs = (uint16_t)entries_05;
        saveui_freeLines(entries,uVar16);
        uVar16 = saveui_readSavesList((int)entries_05,in_DX);
        uVar7 = uVar16;
        for (uVar17 = 0; uVar4 = GSPEmpty.seg, uVar3 = GSPEmpty.ofs, uVar17 < uVar16;
            uVar17 = uVar17 + 1) {
          puVar12 = (uint *)((int)entries_05 + uVar17 * 4);
          uVar7 = *puVar12 | puVar12[1];
          if (uVar7 == 0) {
            puVar13 = (uint16_t *)((int)entries_05 + uVar17 * 4);
            puVar13[1] = GSPEmpty.seg;
            *puVar13 = uVar3;
            uVar7 = uVar4;
            uVar11 = uVar3;
          }
        }
        if (uVar16 < 100) {
          puVar13 = (uint16_t *)((int)entries_05 + uVar16 * 4);
          puVar13[1] = GSPEmpty.seg;
          *puVar13 = uVar3;
          uVar7 = uVar4;
          uVar11 = uVar3;
        }
        bVar5 = (byte)uVar7;
        uVar16 = uVar16 + 1;
        saveui_drawCancel();
        uiMenu();
        saveui_usesBlitLoadRleGfx4();
        if (bVar5 != 0) {
          iVar8 = strcmp((char *)CONCAT22(*(undefined2 *)((int)entries_05 + (uint)bVar5 * 4 + -2),
                                          (char *)*(undefined2 *)
                                                   ((int)entries_05 + (uint)bVar5 * 4 + -4)),
                         (char *)CONCAT22(GSPEmpty.seg,GSPEmpty.ofs));
          if (iVar8 == 0) {
            saveui_blitPanel();
            saveui_drawCancel();
            pcVar10 = uiReadString();
            *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -2) = uVar11;
            *(undefined2 *)((int)entries_05 + (uint)bVar5 * 4 + -4) = pcVar10;
            saveui_usesBlitLoadRleGfx4();
          }
          else {
            saveui_blitPanel();
            saveui_drawCancel();
            pcVar10 = uiReadString();
            *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -2) = uVar11;
            *(undefined2 *)((int)entries_05 + (uint)bVar5 * 4 + -4) = pcVar10;
            saveui_usesBlitLoadRleGfx4();
          }
          if ((*(int *)((int)entries_05 + (uint)bVar5 * 4 + -4) != 0 ||
               *(int *)((int)entries_05 + (uint)bVar5 * 4 + -2) != 0) &&
             (iVar8 = strcmp((char *)CONCAT22(*(undefined2 *)
                                               ((int)entries_05 + (uint)bVar5 * 4 + -2),
                                              (char *)*(undefined2 *)
                                                       ((int)entries_05 + (uint)bVar5 * 4 + -4)),
                             (char *)CONCAT22(GSPEmpty.seg,GSPEmpty.ofs)), iVar8 == 0)) {
            handle.seg = unaff_DI;
            handle.ofs = *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -2);
            ovr_stshFree(handle,*(undefined2 *)((int)entries_05 + (uint)bVar5 * 4 + -4));
            *(undefined2 *)((int)entries_05 + (uint)bVar5 * 4 + -2) = 0;
            *(undefined2 *)((int)entries_05 + (uint)bVar5 * 4 + -4) = 0;
          }
          if (*(int *)((int)entries_05 + (uint)bVar5 * 4 + -4) != 0 ||
              *(int *)((int)entries_05 + (uint)bVar5 * 4 + -2) != 0) {
            uVar9 = ovr_stSave();
            if ((char)uVar9 == '\0') {
              *(undefined2 *)((int)entries_05 + (uint)bVar5 * 4 + -2) = 0;
              *(undefined2 *)((int)entries_05 + (uint)bVar5 * 4 + -4) = 0;
            }
            else {
              GWantsExit2 = '\0';
            }
            for (uVar17 = 0; uVar17 < uVar16; uVar17 = uVar17 + 1) {
              puVar14 = (undefined2 *)((int)entries_05 + uVar17 * 4);
              iVar8 = strcmp((char *)CONCAT22(puVar14[1],(char *)*puVar14),
                             (char *)CONCAT22(GSPEmpty.seg,GSPEmpty.ofs));
              if (iVar8 == 0) {
                puVar14 = (undefined2 *)((int)entries_05 + uVar17 * 4);
                puVar14[1] = 0;
                *puVar14 = 0;
              }
            }
            while ((uVar16 != 0 &&
                   (piVar15 = (int *)((int)entries_05 + (uVar16 - 1) * 4),
                   *piVar15 == 0 && piVar15[1] == 0))) {
              uVar16 = uVar16 - 1;
            }
            entries_00.seg = in_DX;
            entries_00.ofs = (uint16_t)entries_05;
            saveui_writeSavesList(entries_00,uVar16);
          }
        }
        saveui_blitPanel();
        break;
      case 289563:
        saveui_blitPanel();
        entries_01.seg = in_DX;
        entries_01.ofs = (uint16_t)entries_05;
        saveui_freeLines(entries_01,uVar16);
        uVar16 = saveui_readSavesList((int)entries_05,in_DX);
        uVar17 = uVar16;
        saveui_drawCancel();
        cVar6 = (char)uVar17;
        uiMenu();
        saveui_usesBlitLoadRleGfx4();
        if (cVar6 != '\0') {
          bVar1 = false;
          if ((SaveAuto == '\0') || (GWantsExit2 == '\0')) {
            bVar1 = true;
          }
          else {
            saveui_blitPanel();
            cVar6 = (char)yesno;
            uiMenu();
            if (cVar6 == '\x01') {
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
        entries_02.ofs = (uint16_t)entries_05;
        saveui_freeLines(entries_02,uVar16);
        uVar16 = saveui_readSavesList((int)entries_05,in_DX);
        uVar17 = uVar16;
        saveui_drawCancel();
        bVar5 = (byte)uVar17;
        uiMenu();
        saveui_usesBlitLoadRleGfx4();
        if (bVar5 != 0) {
          saveui_blitPanel();
          pcVar10 = ovr_fmVsprintf((char *)CONCAT22(*(undefined2 *)
                                                     ((int)entries_05 + (uint)bVar5 * 4 + -4),
                                                    (char *)"puppetmaker" + 3),
                                   (char *)CONCAT22(yesno,(char *)*(undefined2 *)
                                                                   ((int)entries_05 +
                                                                   (uint)bVar5 * 4 + -2)));
          cVar6 = (char)pcVar10;
          uiMenu();
          if (cVar6 == '\x01') {
            ovr_save_deleteGameFile();
            handle_00.seg = unaff_DI;
            handle_00.ofs = *(uint16_t *)((int)entries_05 + (uint)bVar5 * 4 + -2);
            ovr_stshFree(handle_00,*(undefined2 *)((int)entries_05 + (uint)bVar5 * 4 + -4));
            *(undefined2 *)((int)entries_05 + (uint)bVar5 * 4 + -2) = 0;
            *(undefined2 *)((int)entries_05 + (uint)bVar5 * 4 + -4) = 0;
            while ((uVar16 != 0 &&
                   (piVar15 = (int *)((int)entries_05 + (uVar16 - 1) * 4),
                   *piVar15 == 0 && piVar15[1] == 0))) {
              uVar16 = uVar16 - 1;
            }
          }
        }
        entries_03.seg = in_DX;
        entries_03.ofs = (uint16_t)entries_05;
        saveui_writeSavesList(entries_03,uVar16);
        saveui_blitPanel();
        break;
      case 289977:
        saveui_blitPanel();
        if (SaveAuto != '\0') {
          ovr_stSave();
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(unaff_DI,0);
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
  entries_04.ofs = (uint16_t)entries_05;
  saveui_freeLines(entries_04,uVar16);
  handle_01.seg = unaff_DI;
  handle_01.ofs = in_DX;
  ovr_stshFree(handle_01,entries_05);
  ovr_ovc28_textHalflingCastle();
  return;
}



/* 4528:1ae8 */

/* WARNING: Variable defined which should be unmapped: worldItems */
/* Runs the new-world dialog (hostility, enemy intelligence, second-wave size) and starts the
   generated world. */

void __cdecl16far saveui_configureNewWorld(void)

{
  far_t dst_00;
  far_t dst_01;
  far_t dst_02;
  far_t items;
  far_t items_00;
  uint8_t *puVar1;
  uint16_t unaff_SS;
  uint8_t worldItems;
  int in_stack_0000ffae;
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
  items.seg = 7;
  items.ofs = unaff_SS;
  uiMenu((char *)CONCAT22(puVar1,(char *)"puppetmaker" + 3),items,worldItems,0x2979);
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
    items_00.seg = 5;
    items_00.ofs = unaff_SS;
    uiMenu((char *)CONCAT22(puVar1,(char *)"puppetmaker" + 3),items_00,worldItems,0x298a);
    bStack_b = (byte)puVar1;
    saveui_blitPanel();
    if ((bStack_b != '\x05') && (bStack_b != '\0')) {
      if (bStack_b == '\x04') {
        iStack_a = saveui_usesBlitText((char *)0x62410,worldItems,in_stack_0000ffae);
        saveui_blitPanel();
        if (iStack_a < 0) {
          if (inputCancelled != '\0') {
            return;
          }
          iStack_a = 0;
        }
        iStack_8 = saveui_usesBlitText((char *)0x62410,worldItems,in_stack_0000ffae);
        saveui_blitPanel();
        if (iStack_8 < 0) {
          if (inputCancelled != '\0') {
            return;
          }
          iStack_8 = 0;
        }
        iStack_6 = saveui_usesBlitText((char *)0x62410,worldItems,in_stack_0000ffae);
        saveui_blitPanel();
        if (iStack_6 < 0) {
          if (inputCancelled != '\0') {
            return;
          }
          iStack_6 = 0;
        }
        iStack_4 = saveui_usesBlitText((char *)0x62410,worldItems,in_stack_0000ffae);
        saveui_blitPanel();
        if (iStack_4 < 0) {
          if (inputCancelled != '\0') {
            return;
          }
          iStack_4 = 0;
        }
        if (0x3c < iStack_a + iStack_8 + iStack_6 + iStack_4) {
          ovr_say((char *)CONCAT22(worldItems,(char *)"puppetmaker" + 3),0x2a02);
          return;
        }
        lowIntelEnemies = (undefined1)iStack_a;
        medIntelEnemies = (undefined1)iStack_8;
        highIntelEnemies = (undefined1)iStack_6;
        secondWaveSize = (undefined1)iStack_4;
      }
      Difficulty = bStack_b;
      worldIndex = cStack_c;
      ovr_say((char *)CONCAT22(worldItems,(char *)"puppetmaker" + 3),0x2a28);
      ovr_init_usesClearEntities();
      ovr_say((char *)CONCAT22(worldItems,(char *)"puppetmaker" + 3),0x2a3a);
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

/* WARNING: Variable defined which should be unmapped: text */
/* [R4] calls ovr_blitText */

int __cdecl16far saveui_usesBlitText(char *prompt,int textSeg,int row)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t src;
  far_t handle;
  far_t handle_00;
  far_t *pfVar1;
  int iVar2;
  int iVar3;
  uint16_t uVar4;
  undefined2 unaff_SI;
  byte *unaff_SS;
  int in_stack_00000004;
  undefined1 uVar5;
  undefined1 uVar6;
  uint8_t text;
  undefined1 uStack_5b;
  int in_stack_0000ffa6;
  uint8_t cursorX;
  byte bStack_5;
  uint16_t uStack_4;
  
  uVar5 = (undefined1)unaff_SI;
  uVar6 = (undefined1)((uint)unaff_SI >> 8);
  inputCancelled = 0;
  if (in_stack_00000004 != 0 || (char *)prompt != (char *)0x0) {
    TextBlitX = 0x16;
    TextBlitY = 0xb;
    ovr_blitText();
  }
  bStack_5 = 0;
  text = 0x0;
  uVar4 = (uint16_t)((ulong)((long)(*(uint16_t *)((uint8_t *)&(prompt) + 2)) * 0xf) >> 0x10);
  src.seg = (int)((long)(*(uint16_t *)((uint8_t *)&(prompt) + 2)) * 0xf) + 0x1d;
  src.ofs = 0x16;
  pfVar1 = ovr_stshRleCut((far_t *)0xa000,src,222,(*(uint16_t *)((uint8_t *)&(prompt) + 2)) * 0xf + 0x27,0);
  TextBlitX = 0x2a;
  TextBlitY = (*(uint16_t *)((uint8_t *)&(prompt) + 2)) * 0xf + 0x1d;
  cursorX = 0;
  gfx.seg = (uint16_t)&text;
  gfx.ofs = uVar4;
  saveui_usesBlitGfx10
            (gfx,(char *)CONCAT22(&cursorX,unaff_SS),(byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(prompt) + 2)),unaff_SS),
             (uint *)CONCAT13(uStack_5b,CONCAT12(text,CONCAT11(uVar6,uVar5))),in_stack_0000ffa6);
  ovr_ovc40_flushInput();
L_saveui_4528_1d55_1E1D:
  do {
    while( true ) {
      while ((uStack_4 = uiReadKey2(), (((byte *)_ctype + 1)[uStack_4 & 0xff] & 2) != 0 &&
             (bStack_5 < 2))) {
        (&text)[bStack_5] = (uint8_t)uStack_4;
        (&uStack_5b)[bStack_5] = 0;
        iVar3 = ovr_font_textWidth((char *)CONCAT22(Font03.ofs,unaff_SS),
                                   (char *)CONCAT13(uVar6,CONCAT12(uVar5,Font03.seg)),&text);
        iVar2 = ovr_font_textWidth((char *)CONCAT22(Font03.ofs,(char *)"puppetmaker" + 3),
                                   (char *)CONCAT22(iVar3,Font03.seg),0x2738);
        if (iVar3 + iVar2 + 0x2aU < 0xe0) {
          bStack_5 = bStack_5 + 1;
        }
        (&text)[bStack_5] = 0x0;
        gfx_00.seg = (uint16_t)&text;
        gfx_00.ofs = uVar4;
        saveui_usesBlitGfx10
                  (gfx_00,(char *)CONCAT22(&cursorX,unaff_SS),
                   (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(prompt) + 2)),unaff_SS),
                   (uint *)CONCAT13(uStack_5b,CONCAT12(text,CONCAT11(uVar6,uVar5))),
                   in_stack_0000ffa6);
      }
      if (uStack_4 != 0x4b00) break;
L_saveui_4528_1d55_1F0C:
      if (bStack_5 != 0) {
        bStack_5 = bStack_5 - 1;
        (&text)[bStack_5] = 0x0;
        gfx_01.seg = (uint16_t)&text;
        gfx_01.ofs = uVar4;
        saveui_usesBlitGfx10
                  (gfx_01,(char *)CONCAT22(&cursorX,unaff_SS),
                   (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(prompt) + 2)),unaff_SS),
                   (uint *)CONCAT13(uStack_5b,CONCAT12(text,CONCAT11(uVar6,uVar5))),
                   in_stack_0000ffa6);
      }
    }
    if (0x4b00 < uStack_4) {
      if (uStack_4 == 0x4b34) goto L_saveui_4528_1d55_1F0C;
      if (uStack_4 == 0xfffe) {
L_saveui_4528_1d55_1F83:
        inputCancelled = 1;
        (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = uVar5;
        handle_00.ofs = uVar4;
        (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = uVar6;
        ovr_stshFree(handle_00,pfVar1);
        return 0xffff;
      }
      if ((uStack_4 == 0xffff) && (MouseMoved == 0)) goto L_saveui_4528_1d55_1F59;
      goto L_saveui_4528_1d55_1E1D;
    }
    if (uStack_4 == 0x11b) goto L_saveui_4528_1d55_1F83;
    if (uStack_4 == 0xe08) goto L_saveui_4528_1d55_1F0C;
    if (uStack_4 == 0x1c0d) {
L_saveui_4528_1d55_1F59:
      (*(uint8_t *)((uint8_t *)&(handle.seg))) = uVar5;
      handle.ofs = uVar4;
      (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uVar6;
      ovr_stshFree(handle,pfVar1);
      if (bStack_5 == 0) {
        iVar3 = -1;
      }
      else {
        iVar3 = saveui_parseNumber((char *)CONCAT22(unaff_SS,&text));
      }
      return iVar3;
    }
  } while( true );
}


