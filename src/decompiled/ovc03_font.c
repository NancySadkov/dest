/*
 * ovc03_font.c - recovered from STRONG.EXE
 * memory block: OVC03_font.c
 * range: 302d:0000 - 302d:0b8f
 * functions: 15
 */
#include "recovered.h"


/* 302d:0000 */

void __cdecl16far stshCopyFontChar(uint8_t *src,uint8_t *dst,int16_t width,int16_t count)

{
  char *in_stack_00000004;
  
  while (width != 0) {
    _fmemmove((char far *)MK_FP((uint8_t *)dst,(*(uint16_t *)((uint8_t *)&(src) + 2))),
           (char far *)MK_FP((uint8_t *)src,in_stack_00000004),(*(uint16_t *)((uint8_t *)&(dst) + 2)));
    src = (uint8_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(src) + 2)) + (*(uint16_t *)((uint8_t *)&(dst) + 2)),(uint8_t *)src);
    in_stack_00000004 = in_stack_00000004 + 0x140;
    width = width + -1;
  }
  return;
}



/* 302d:0035 */

far_t * __cdecl16far stshProcessFontSub(far_t *retStorage,far_t hndl,uint16_t arg3)

{
  far_t *pfVar1;
  uint16_t in_DX;
  int16_t line;
  uint16_t o;
  int16_t unaff_DI;
  uint16_t m;
  uint8_t widths [96];
  uint8_t dchofs [192];
  uint8_t schofs [192];
  uint16_t x;
  uint16_t dofs;
  uint16_t height;
  uint16_t j;
  uint16_t i;
  uint32_t r;
  
  height = 0;
  for (line = 320; *(char *)((int)&retStorage->ofs + line) != -1; line = line + 0x140) {
    if (height == 200) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(1);
    }
    height = height + 1;
  }
  if (height != 0) {
    o = 0;
    dofs = 0;
    x = 0;
    m = 0;
    i = 0;
    while( true ) {
      if (0x5f < i) {
        FontSize.lo = dofs + 0x121;
        FontSize.hi = 0;
        pfVar1 = ovr_stshAlloc((ulong)FontSize.lo);
        r = CONCAT22(in_DX,pfVar1);
        *(undefined1 *)r = (undefined1)height;
        for (i = 0; i < 0x60; i = i + 1) {
          stshCopyFontChar((uint8_t *)
                           CONCAT22((int)&pfVar1[0x48].ofs + *(int *)(dchofs + i * 2) + 1,hndl.ofs),
                           (uint8_t *)(ulong)CONCAT12(widths[i],in_DX),height,unaff_DI);
          *(uint16_t *)((int)&pfVar1->ofs + i * 2 + 1) = *(uint16_t *)(dchofs + i * 2);
          *(uint8_t *)((int)&pfVar1[0x30].ofs + i + 1) = widths[i];
        }
        return pfVar1;
      }
      do {
        if (0x13f < m) {
          m = 0;
          for (o = height * 0x140 + x + 0x280; x = o,
              *(char *)((int)&retStorage->ofs + o) != -1; o = o + 0x140) {
            if (64000 < o) {
                    /* WARNING: Subroutine does not return */
              ovr_stExit(2);
            }
          }
        }
        for (; (*(char *)((int)&retStorage->ofs + o) != -1 && (m < 0x140)); m = m + 1) {
          o = o + 1;
        }
      } while (0x13f < m);
      *(uint16_t *)(schofs + i * 2) = o + 0x140;
      *(uint16_t *)(dchofs + i * 2) = dofs;
      j = 2;
      while( true ) {
        if (*(char *)((int)&retStorage->ofs + o + 1) == -1) break;
        j = j + 1;
        o = o + 1;
        m = m + 1;
      }
      if (0x13f < m + 1) break;
      widths[i] = (uint8_t)j;
      in_DX = (uint16_t)((ulong)((long)(int)j * (long)(int)height) >> 0x10);
      dofs = dofs + (int)((long)(int)j * (long)(int)height);
      m = m + 2;
      o = o + 2;
      i = i + 1;
    }
                    /* WARNING: Subroutine does not return */
    ovr_stExit(3);
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(1);
}



/* 302d:021a */

far_t * __cdecl16far stshProcessFont(far_t *retStorage,int16_t file_id)

{
  far_t handle;
  far_t handle_00;
  far_t hndl;
  stg_tmp_t *psVar1;
  far_t *pfVar2;
  uint16_t in_DX;
  
  psVar1 = ovr_grabLbm((int16_t)retStorage,0,0,0,0);
  if (psVar1 == (stg_tmp_t *)0x0 && in_DX == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(6);
  }
  hndl.seg = (uint16_t)psVar1;
  hndl.ofs = (psVar1->aptr).seg;
  pfVar2 = stshProcessFontSub((far_t *)(&psVar1->aptr)->ofs,hndl,0);
  handle.seg = (psVar1->bptr).seg;
  handle.ofs = (&psVar1->bptr)->ofs;
  ovr_stshFree(handle);
  handle_00.seg = in_DX;
  handle_00.ofs = (uint16_t)psVar1;
  ovr_stshFree(handle_00);
  return pfVar2;
}



/* 302d:028c */

/* Blit one character: ch is turned into a glyph index by adding 0xe0, rows is
   widths[0], the glyph width is widths[ch_index + 0xc1], and the glyph data
   starts at widths + word[ch_index*2 + 1] + 0x121 in the same segment.
   Zero pixels leave the destination alone; 0x9f/0x9b (type 2) become 0x92,
   1 becomes 0xec, 0xe becomes the caller's color, and in type 1 the run
   0xe4..0xe7 is ORed with 0x10. */

void __cdecl16far blitLetter(char ch,byte far *widths,uint8_t color)

{
  byte far *dst;
  byte far *src;
  uint16_t rows;
  uint16_t letter_w;
  uint16_t row;
  uint16_t col;
  uint8_t ch_index;
  far_t gfx;
  far_t rle_dst;

  if (((ch != '\r') && (ch != '\n')) && (ch != '\x1a')) {
    if (ch == '\x7f') {
      gfx.seg = LbxButton2.seg;
      gfx.ofs = LbxButton2.ofs;
      rle_dst.seg = TextBlitDstSeg;
      rle_dst.ofs = TextBlitY * 0x140 + TextBlitX + 0x140;
      ovr_blitLoadRleGfx(gfx,rle_dst,0);
    }
    else {
      ch_index = ch + 0xe0;
      if (ch_index < 0x61) {
        rows = *widths;
        letter_w = widths[ch_index + 0xc1];
        dst = (byte far *)MK_FP(TextBlitDstSeg,TextBlitX + TextBlitY * 0x140);
        src = widths + *(int far *)(widths + (uint)ch_index * 2 + 1) + 0x121;
        if (BlitLetterType == '\x02') {
          for (row = 0; row < rows; row = row + 1) {
            for (col = 0; col < letter_w; col = col + 1) {
              if ((*src == 0x9f) || (*src == 0x9b)) {
                *dst = 0x92;
              }
              else if (*src != 0) {
                *dst = *src;
              }
              dst = dst + 1;
              src = src + 1;
            }
            dst = dst + (0x140 - letter_w);
          }
        }
        else if (BlitLetterType == '\0') {
          for (row = 0; row < rows; row = row + 1) {
            for (col = 0; col < letter_w; col = col + 1) {
              if (*src == 1) {
                *dst = 0xec;
              }
              else if (*src == 0xe) {
                *dst = color;
              }
              else if (*src != 0) {
                *dst = *src;
              }
              dst = dst + 1;
              src = src + 1;
            }
            dst = dst + (0x140 - letter_w);
          }
        }
        else {
          for (row = 0; row < rows; row = row + 1) {
            for (col = 0; col < letter_w; col = col + 1) {
              if (*src == 1) {
                *dst = 0xec;
              }
              else if (*src == 0xe) {
                *dst = color;
              }
              else if ((*src < 0xe4) || (0xe7 < *src)) {
                if (*src != 0) {
                  *dst = *src;
                }
              }
              else {
                *dst = *src | 0x10;
              }
              dst = dst + 1;
              src = src + 1;
            }
            dst = dst + (0x140 - letter_w);
          }
        }
        TextBlitX = TextBlitX + letter_w;
      }
      else {
        printf("Error 4 %d \r",ch_index);
        ovr_biosReadKey();
      }
    }
  }
  return;
}



/* 302d:04eb */

uint8_t __cdecl16far fontChWidth(uint8_t far *widths,char ch)

{
  uint8_t width;

  if ((byte)ch < 0x20) {
    width = 0x0;
  }
  else {
    width = widths[(byte)ch + 0xa1];
  }
  return width;
}



/* 302d:050a */
/* 302d:050a */

int __cdecl16far blitText(char far *text,byte far *widths,uint16_t term,uint8_t color)

{
  uint8_t ch_width;
  uint16_t nchars;
  uint8_t chval;
  uint16_t i;
  uint16_t bx;
  uint16_t snchars;

  if (*text == '\0') {
    nchars = 0;
  }
  else {
    nchars = 0;
    snchars = 0;
    i = 0;
    for (bx = TextBlitX;
        (((text[i] != '\0' && (text[i] != '\n')) && (text[i] != '\x1a')) &&
        (ch_width = fontChWidth(widths,text[i]), bx + ch_width <= term + 1U));
        bx = bx + ch_width) {
      if (text[i] == ' ') {
        snchars = i + 1;
        nchars = i + 1;
      }
      ch_width = fontChWidth(widths,text[i]);
      i = i + 1;
    }
    chval = (uint8_t)text[i];
    if (((chval == 0) || (text[i] == '\n')) || ((text[i] == ' ') || (text[i] == '\x1a')))
    {
      nchars = i;
    }
    if (nchars == 0) {
      nchars = snchars;
    }
    for (i = 0; i < nchars; i = i + 1) {
      blitLetter(text[i],widths,color);
    }
    for (; text[nchars] == '\r'; nchars = nchars + 1) {
    }
    if (text[nchars] == '\n') {
      nchars = nchars + 1;
    }
    else {
      for (; text[nchars] == ' '; nchars = nchars + 1) {
      }
    }
    for (; text[nchars] == '\x1a'; nchars = nchars + 1) {
    }
  }
  return nchars;
}


/* 302d:0634 */
/* 302d:0634 */

uint __cdecl16far blitLabel(char far *text,byte far *widths,uint16_t term,uint8_t color)

{
  uint16_t width;
  uint16_t i;
  uint16_t x;
  uint16_t j;

  if (*text == '\0') {
    width = 0;
  }
  else {
    width = 0;
    j = 0;
    for (x = TextBlitX;
        ((text[j] != '\0' && (text[j] != '\n')) &&
        (x + widths[(byte)text[j] + 0xa1] <= term + 1U));
        x = x + widths[(byte)text[j] + 0xa1], j = j + 1) {
      width = j + 1;
    }
    for (i = 0; i < width; i = i + 1) {
      blitLetter(text[i],widths,color);
    }
  }
  return width;
}


/* 302d:06ea */

/* Returns the pixel width of a string in the given font by summing font[ch+0xa1] over its
   characters. */

int __cdecl16far font_textWidth(char far *text, char far *font, uint16_t arg3, uint16_t arg4, uint16_t arg5)

{
  int iVar1;
  int iVar2;
  
  if (text == (char *)0x0 && (char *)font == (char *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    for (iVar2 = 0; text[iVar2] != '\0'; iVar2 = iVar2 + 1) {
      iVar1 = iVar1 + (uint)*(byte *)((*(uint16_t *)((uint8_t *)&(font) + 2)) + (uint)(byte)text[iVar2] + 0xa1);
    }
  }
  return iVar1;
}



/* 302d:072b */

uint16_t __cdecl16far inputUpdate(ulong msg_delay)

{
  bool bVar1;
  bool housing;
  ulong *puVar3;
  uint16_t uVar4;
  bool bVar5;
  ulong in_stack_0000fff8;
  uint uVar7;
  long lVar6;
  uint16_t uVar8;
  undefined1 uVar9;
  
  rightButtonLatch = 0;
  bVar5 = MiceNeedsUpdate != '\0';
  if (bVar5) {
    in_stack_0000fff8 = CONCAT22((int)(in_stack_0000fff8 >> 0x10),0x2410);
    ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x2410);
  }
  bVar1 = GDebug;
  GDebug = false;
  do {
    in_stack_0000fff8 = in_stack_0000fff8 & 0xffff0000;
    housing = ovr_draw_textProvidesMoreHousing();
  } while (housing);
  do {
    uVar7 = (uint)(in_stack_0000fff8 >> 0x10);
    uVar4 = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
    if ((*(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != InputEventTime.hi) ||
       (uVar4 != InputEventTime.lo)) {
      InputEventTime.hi = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
      uVar4 = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
      InputEventTime.lo = uVar4;
      ovr_draw_usesBlitLoadRleGfx();
    }
    lVar6 = (ulong)uVar7 << 0x10;
    housing = ovr_draw_textProvidesMoreHousing();
    uVar8 = (uint16_t)(CONCAT13(housing,(int3)lVar6) >> 0x10);
    if (housing) break;
    in_stack_0000fff8 = CONCAT22(uVar8,(*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)));
    puVar3 = ovr_attact_usesBDADailyTimeCounter((ulong *)TextBlitCycle,in_stack_0000fff8,0);
    uVar8 = (uint16_t)(in_stack_0000fff8 >> 0x10);
  } while ((uVar4 < (*(uint16_t *)((uint8_t *)&(msg_delay) + 2))) ||
          ((uVar4 == (*(uint16_t *)((uint8_t *)&(msg_delay) + 2)) && (puVar3 < (ulong *)msg_delay))));
  uVar9 = (undefined1)((uint)uVar8 >> 8);
  if (bVar5) {
    ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0);
  }
  GDebug = bVar1;
  return CONCAT11(0x24,uVar9);
}



/* 302d:080b */

/* [R4] calls ovr_miceBlitRect */

uint __cdecl16far font_usesMiceBlitRect(byte msgDelay)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint16_t uVar4;
  undefined1 extraout_AH;
  undefined1 uVar5;
  undefined1 housing;
  
  rightButtonLatch = 0;
  uVar3 = ovr_ovr_midGetSequenceStatus_entry();
  if ((uVar3 & 0xff) == 0) {
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
    uVar4 = inputUpdate((ulong)msgDelay);
    uVar3 = uVar4 & 0xff00;
  }
  else {
    if (MiceNeedsUpdate == '\0') {
      bVar1 = false;
    }
    else {
      ovr_miceBlitRect((brect_t *)(BlitRects + 1),0);
      bVar1 = true;
    }
    do {
      bVar2 = ovr_draw_textProvidesMoreHousing();
    } while (bVar2);
    do {
      uVar3 = ovr_ovr_midGetSequenceStatus_entry();
      if ((char)uVar3 == '\0') break;
      if ((*(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != InputEventTime.hi) ||
         (*(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) != InputEventTime.lo)) {
        InputEventTime.hi = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
        InputEventTime.lo = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
        ovr_draw_usesBlitLoadRleGfx();
      }
      housing = ovr_draw_textProvidesMoreHousing();
      uVar3 = CONCAT11(extraout_AH,housing);
    } while (!(bool)housing);
    uVar5 = (undefined1)(uVar3 >> 8);
    if (bVar1) {
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0);
    }
    uVar3 = CONCAT11(uVar5,housing);
  }
  return uVar3;
}



/* 302d:08ef */

void __cdecl16far drawTextAt(char *txt,uint16_t dst,uint16_t arg3)

{
  far_t gfx;
  uint16_t ndrawn;
  uint16_t txtsz;
  far_t dst_00;
  
  if (GameRunning) {
    if (dst != 0xa000) {
      ovr_blitRaw(0x1d,0x9c,0xcf,199,0xa000,dst);
    }
  }
  else {
    TextBlitFlag = 1;
    TextBlitDstSeg = dst;
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
    dst_00.seg = dst;
    dst_00.ofs = 0xc31d;
    gfx.seg = FontHandle.seg;
    gfx.ofs = FontHandle.ofs;
    ovr_blitLoadRleGfx(gfx,dst_00,0);
    for (TextBlitY = 0x9c; TextBlitX = 0x1d, TextBlitY + 9 < 200; TextBlitY = TextBlitY + 0xb) {
      ndrawn = blitText((char far *)MK_FP(dst,txt),
                      (byte far *)MK_FP(Font03.seg,Font03.ofs),0xcf,0xed);
      txtsz = strlen((char *)CONCAT22(dst,txt));
      if (txtsz <= ndrawn) {
        ovr_clean_ring_buffer();
        return;
      }
      txt = txt + ndrawn;
    }
  }
  return;
}



/* 302d:09f5 */

void __cdecl16far drawAnimTextAt(char *text,uint16_t dst)

{
  char *in_stack_00000004;
  
  inputUpdate((ulong)MessageDelay << 1);
  drawTextAt(in_stack_00000004,(uint16_t)(char *)text,0);
  return;
}



/* 302d:0a1b */

void __cdecl16far say(char *msg,uint16_t arg2)

{
  uint16_t unaff_BP;
  
  drawAnimTextAt((char *)CONCAT22(0xa000,msg),unaff_BP);
  return;
}



/* 302d:0a30 */

/* clears the TextBlitCycle timestamp */

void __cdecl16far resetTextBlitCycle(void)

{
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = 0;
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = 0;
  return;
}



/* 302d:0a41 */

void __cdecl16far uiNotify(char *msg,uint16_t dst,uint16_t arg3)

{
  uint8_t mice_no_update;
  
  inputUpdate((ulong)MessageDelay << 1);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
  BlitRects[4].seg = dst;
  mice_no_update = MiceNeedsUpdate == '\0';
  if ((bool)mice_no_update) {
    ovr_miceRestoreArea((brect_t *)(BlitRects + 4),0);
  }
  drawTextAt(msg,dst,0);
  if ((bool)mice_no_update) {
    ovr_miceBlitRect((brect_t *)(BlitRects + 4),0);
  }
  if (dst != 0xa000) {
    ovr_blitRect((brect_t *)(BlitRects + 4),0);
    ovr_miceUpdate();
  }
  BlitRects[4].seg = 0xa000;
  return;
}


