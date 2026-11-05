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
  while (count != 0) {
    memcpy(dst,src,width);
    dst = dst + width;
    src = src + 0x140;
    count = count + -1;
  }
  return;
}



/* 302d:0035 */

far_t __cdecl16far stshProcessFontSub(far_t hndl)

{
  uint uVar1;
  uint8_t *psrc;
  int16_t line;
  uint o;
  uint m;
  uint16_t uVar2;
  undefined2 unaff_SS;
  byte widths [96];
  int dchofs [96];
  int schofs [96];
  uint x;
  int dofs;
  int height;
  int j;
  uint i;
  far_t r;
  
  line = 320;
  height = 0;
  while( true ) {
    uVar2 = hndl.seg;
    psrc = (uint8_t *)hndl.ofs;
    if (psrc[line] == 0xff) break;
    if (height == 200) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(1);
    }
    height = height + 1;
    line = line + 0x140;
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
        r = (far_t)ovr_stshAlloc((ulong)FontSize.lo);
        *(undefined1 *)r = (undefined1)height;
        for (i = 0; i < 0x60; i = i + 1) {
          stshCopyFontChar(psrc + schofs[i],(uint8_t *)(r.ofs + dchofs[i] + 0x121),(uint)widths[i],
                           height);
          *(int *)((int)r.ofs + i * 2 + 1) = dchofs[i];
          *(byte *)((int)r.ofs + i + 0xc1) = widths[i];
        }
        return r;
      }
      do {
        uVar1 = x;
        if (0x13f < m) {
          m = 0;
          for (o = height * 0x140 + x + 0x280; uVar1 = o, psrc[o] != 0xff; o = o + 0x140) {
            if (64000 < o) {
                    /* WARNING: Subroutine does not return */
              ovr_stExit(2);
            }
          }
        }
        for (; (x = uVar1, psrc[o] != 0xff && (m < 0x140)); m = m + 1) {
          o = o + 1;
          uVar1 = x;
        }
      } while (0x13f < m);
      schofs[i] = o + 0x140;
      dchofs[i] = dofs;
      j = 2;
      while( true ) {
        if (psrc[o + 1] == 0xff) break;
        j = j + 1;
        o = o + 1;
        m = m + 1;
      }
      if (0x13f < m + 1) break;
      widths[i] = (byte)j;
      dofs = dofs + j * height;
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

far_t __cdecl16far stshProcessFont(int16_t file_id)

{
  uint16_t uVar1;
  far_t handle;
  far_t fVar2;
  far_t handle_00;
  undefined2 uStack_8;
  
  handle = (far_t)ovr_grabLbm(file_id,0,0);
  uVar1 = handle.ofs;
  uStack_8 = handle.seg;
  if (uVar1 == 0 && uStack_8 == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(6);
  }
  fVar2.seg = *(uint16_t *)(uVar1 + 0x302);
  fVar2.ofs = *(uint16_t *)(uVar1 + 0x300);
  fVar2 = stshProcessFontSub(fVar2);
  handle_00.seg = *(uint16_t *)(uVar1 + 0x306);
  handle_00.ofs = *(uint16_t *)(uVar1 + 0x304);
  ovr_stshFree(handle_00);
  ovr_stshFree(handle);
  return fVar2;
}



/* 302d:028c */

void __cdecl16far blitLetter(char ch,byte *widths,uint8_t term)

{
  far_t gfx;
  far_t dst;
  byte ch_index;
  uint uVar1;
  uint letter_w;
  byte *ws;
  int iVar2;
  undefined2 uVar3;
  uint uStack_e;
  undefined4 uStack_a;
  undefined4 uStack_6;
  
  if (((ch != '\r') && (ch != '\n')) && (ch != '\x1a')) {
    if (ch == '\x7f') {
      gfx.seg = LbxButton2.seg;
      gfx.ofs = LbxButton2.ofs;
      dst.seg = TextBlitDstSeg;
      dst.ofs = TextBlitY * 0x140 + TextBlitX + 0x140;
      ovr_blitLoadRleGfx(gfx,dst);
    }
    else {
      ch_index = ch - 0x20;
      if (ch_index < 0x61) {
        uVar1 = (uint)*widths;
        uVar3 = (undefined2)((ulong)widths >> 0x10);
        ws = (byte *)widths;
        letter_w = (uint)ws[ch_index + 0xc1];
        uStack_6 = (byte *)CONCAT22(TextBlitDstSeg,(byte *)(TextBlitX + TextBlitY * 0x140));
        uStack_a = (byte *)CONCAT22(uVar3,ws + *(int *)(ws + (uint)ch_index * 2 + 1) + 0x121);
        if (BlitLetterType == '\x02') {
          for (uStack_e = 0; uStack_e < uVar1; uStack_e = uStack_e + 1) {
            iVar2 = 0;
            while( true ) {
              if ((int)letter_w <= iVar2) break;
              if ((*uStack_a == 0x9f) || (*uStack_a == 0x9b)) {
                *uStack_6 = 0x92;
              }
              else if (*uStack_a != 0) {
                *uStack_6 = *uStack_a;
              }
              uStack_6 = (byte *)CONCAT22(uStack_6._2_2_,(byte *)uStack_6 + 1);
              uStack_a = (byte *)CONCAT22(uStack_a._2_2_,(byte *)uStack_a + 1);
              iVar2 = iVar2 + 1;
            }
            uStack_6 = (byte *)CONCAT22(uStack_6._2_2_,(byte *)uStack_6 + (0x140 - letter_w));
          }
        }
        else if (BlitLetterType == '\0') {
          for (uStack_e = 0; uStack_e < uVar1; uStack_e = uStack_e + 1) {
            iVar2 = 0;
            while( true ) {
              if ((int)letter_w <= iVar2) break;
              if (*uStack_a == 1) {
                *uStack_6 = 0xec;
              }
              else if (*uStack_a == 0xe) {
                *uStack_6 = term;
              }
              else if (*uStack_a != 0) {
                *uStack_6 = *uStack_a;
              }
              uStack_6 = (byte *)CONCAT22(uStack_6._2_2_,(byte *)uStack_6 + 1);
              uStack_a = (byte *)CONCAT22(uStack_a._2_2_,(byte *)uStack_a + 1);
              iVar2 = iVar2 + 1;
            }
            uStack_6 = (byte *)CONCAT22(uStack_6._2_2_,(byte *)uStack_6 + (0x140 - letter_w));
          }
        }
        else {
          for (uStack_e = 0; uStack_e < uVar1; uStack_e = uStack_e + 1) {
            iVar2 = 0;
            while( true ) {
              if ((int)letter_w <= iVar2) break;
              if (*uStack_a == 1) {
                *uStack_6 = 0xec;
              }
              else if (*uStack_a == 0xe) {
                *uStack_6 = term;
              }
              else if ((*uStack_a < 0xe4) || (0xe7 < *uStack_a)) {
                if (*uStack_a != 0) {
                  *uStack_6 = *uStack_a;
                }
              }
              else {
                *uStack_6 = *uStack_a | 0x10;
              }
              uStack_6 = (byte *)CONCAT22(uStack_6._2_2_,(byte *)uStack_6 + 1);
              uStack_a = (byte *)CONCAT22(uStack_a._2_2_,(byte *)uStack_a + 1);
              iVar2 = iVar2 + 1;
            }
            uStack_6 = (byte *)CONCAT22(uStack_6._2_2_,(byte *)uStack_6 + (0x140 - letter_w));
          }
        }
        TextBlitX = TextBlitX + letter_w;
      }
      else {
        printf("Error 4 %d \r",(uint)ch_index);
        ovr_biosReadKey();
      }
    }
  }
  return;
}



/* 302d:04eb */

uint8_t __cdecl16far fontChWidth(byte *widths,char ch)

{
  byte width;
  undefined2 in_stack_00000006;
  
  if ((byte)ch < 0x20) {
    width = 0;
  }
  else {
    width = widths[(byte)ch + 0xa1];
  }
  return width;
}



/* 302d:050a */

int __cdecl16far blitText(char *text,byte *widths,uint16_t seg,uint8_t term)

{
  byte ch_width;
  uint nchars;
  char *pt;
  uint index;
  undefined2 uVar1;
  undefined2 in_stack_0000000a;
  uint16_t bx;
  uint snchars;
  
  if (*text == '\0') {
    nchars = 0;
  }
  else {
    nchars = 0;
    snchars = 0;
    bx = TextBlitX;
    index = 0;
    while( true ) {
      uVar1 = (undefined2)((ulong)text >> 0x10);
      pt = (char *)text;
      if ((((pt[index] == '\0') || (pt[index] == '\n')) || (pt[index] == '\x1a')) ||
         (ch_width = fontChWidth(widths,pt[index]), seg + 1 < bx + ch_width)) break;
      if (pt[index] == ' ') {
        nchars = index + 1;
      }
      snchars = index + 1;
      ch_width = fontChWidth(widths,pt[index]);
      bx = bx + ch_width;
      index = index + 1;
    }
    if (((pt[index] == '\0') || (pt[index] == '\n')) ||
       ((pt[index] == ' ' || (pt[index] == '\x1a')))) {
      nchars = index;
    }
    if (nchars == 0) {
      nchars = snchars;
    }
    for (index = 0; index < nchars; index = index + 1) {
      blitLetter(pt[index],(byte *)CONCAT22(in_stack_0000000a,widths),term);
    }
    for (; pt[nchars] == '\r'; nchars = nchars + 1) {
    }
    if (pt[nchars] == '\n') {
      nchars = nchars + 1;
    }
    else {
      for (; pt[nchars] == ' '; nchars = nchars + 1) {
      }
    }
    for (; pt[nchars] == '\x1a'; nchars = nchars + 1) {
    }
  }
  return nchars;
}



/* 302d:0634 */

uint __cdecl16far blitLabel(char *text,uint8_t *widths,int16_t max_width,uint8_t term)

{
  char *ptext;
  int j;
  uint i;
  uint16_t x;
  undefined2 uVar1;
  undefined2 w_seg;
  uint width;
  
  if (*text == '\0') {
    width = 0;
  }
  else {
    width = 0;
    j = 0;
    x = TextBlitX;
    while( true ) {
      uVar1 = (undefined2)((ulong)text >> 0x10);
      ptext = (char *)text;
      w_seg = (undefined2)((ulong)widths >> 0x10);
      if (((ptext[j] == '\0') || (ptext[j] == '\n')) ||
         (max_width + 1U < x + ((uint8_t *)widths)[(byte)ptext[j] + 0xa1])) break;
      width = j + 1;
      x = x + ((uint8_t *)widths)[(byte)ptext[j] + 0xa1];
      j = j + 1;
    }
    for (i = 0; i < width; i = i + 1) {
      blitLetter(ptext[i],widths,term);
    }
  }
  return width;
}



/* 302d:06ea */

int __cdecl16far font_302d_06ea(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if ((int)param_1 == 0 && param_1._2_2_ == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    for (iVar2 = 0; *(char *)((int)param_1 + iVar2) != '\0'; iVar2 = iVar2 + 1) {
      iVar1 = iVar1 + (uint)*(byte *)((int)param_2 + (uint)*(byte *)((int)param_1 + iVar2) + 0xa1);
    }
  }
  return iVar1;
}



/* 302d:072b */

uint16_t __cdecl16far inputUpdate(ulong msg_delay)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  bool bVar4;
  ulong uVar5;
  
  DAT_2000_ccaf = 0;
  bVar4 = MiceNeedsUpdate != '\0';
  if (bVar4) {
    ovr_miceBlitRect(BlitRects + 1);
  }
  bVar1 = GDebug;
  GDebug = false;
  do {
    cVar2 = ovr_draw_2e25_1d7c();
  } while (cVar2 != '\0');
  do {
    if ((*(uint16_t *)(BDA_DailyTimeCounter.ofs + 2) != InputEventTime.hi) ||
       (*(uint16_t *)BDA_DailyTimeCounter != InputEventTime.lo)) {
      InputEventTime.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
      InputEventTime.lo = *(uint16_t *)BDA_DailyTimeCounter;
      ovr_draw_2e25_046b();
    }
    cVar2 = ovr_draw_2e25_1d7c();
    if (cVar2 != '\0') break;
    uVar5 = ovr_attact_3f0b_082f(CONCAT22(TextBlitCycle._2_2_,(undefined2)TextBlitCycle));
    uVar3 = (uint)(uVar5 >> 0x10);
  } while ((uVar3 < msg_delay._2_2_) ||
          ((uVar3 == msg_delay._2_2_ && ((uint)uVar5 < (uint)msg_delay))));
  if (bVar4) {
    ovr_miceRestoreArea(BlitRects + 1);
  }
  GDebug = bVar1;
  return CONCAT11(0x24,cVar2);
}



/* 302d:080b */

uint __cdecl16far font_302d_080b(byte param_1)

{
  bool bVar1;
  char cVar2;
  uint16_t uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  undefined1 extraout_AH;
  char cStack_3;
  
  DAT_2000_ccaf = 0;
  cVar2 = ovr_audio_3a5b_037e();
  if (cVar2 == '\0') {
    TextBlitCycle._2_2_ = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    TextBlitCycle._0_2_ = *(undefined2 *)BDA_DailyTimeCounter;
    uVar3 = inputUpdate((ulong)param_1);
    uVar4 = uVar3 & 0xff00;
  }
  else {
    if (MiceNeedsUpdate == '\0') {
      bVar1 = false;
    }
    else {
      ovr_miceBlitRect(BlitRects + 1);
      bVar1 = true;
    }
    do {
      cVar2 = ovr_draw_2e25_1d7c();
    } while (cVar2 != '\0');
    do {
      uVar5 = ovr_audio_3a5b_037e();
      if ((char)uVar5 == '\0') break;
      if ((*(uint16_t *)(BDA_DailyTimeCounter.ofs + 2) != InputEventTime.hi) ||
         (*(uint16_t *)BDA_DailyTimeCounter != InputEventTime.lo)) {
        InputEventTime.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
        InputEventTime.lo = *(uint16_t *)BDA_DailyTimeCounter;
        ovr_draw_2e25_046b();
      }
      uVar5 = ovr_draw_2e25_1d7c();
      cStack_3 = (char)uVar5;
    } while (cStack_3 == '\0');
    uVar6 = (undefined1)((uint)uVar5 >> 8);
    if (bVar1) {
      ovr_miceRestoreArea(BlitRects + 1);
      uVar6 = extraout_AH;
    }
    uVar4 = CONCAT11(uVar6,cStack_3);
  }
  return uVar4;
}



/* 302d:08ef */

void __cdecl16far drawTextAt(char *txt,uint16_t dst)

{
  uint ndrawn;
  size_t txtsz;
  far_t gfx;
  far_t dst_00;
  
  if (GameRunning) {
    if (dst != 0xa000) {
      ovr_blitRaw(0x1d,0x9c,0xcf,199,0xa000,dst);
    }
  }
  else {
    TextBlitFlag = 1;
    TextBlitDstSeg = dst;
    TextBlitCycle._2_2_ = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    TextBlitCycle._0_2_ = *(undefined2 *)BDA_DailyTimeCounter;
    dst_00.seg = dst;
    dst_00.ofs = 0xc31d;
    gfx.seg = FontHandle.seg;
    gfx.ofs = FontHandle.ofs;
    ovr_blitLoadRleGfx(gfx,dst_00);
    for (TextBlitY = 0x9c; TextBlitX = 0x1d, TextBlitY + 9 < 200; TextBlitY = TextBlitY + 0xb) {
      ndrawn = blitText(txt,(byte *)Font03.ofs,0xcf,0xed);
      txtsz = strlen((char *)txt);
      if (txtsz <= ndrawn) {
        ovr_clean_ring_buffer();
        return;
      }
      txt = (char *)CONCAT22(txt._2_2_,(char *)txt + ndrawn);
    }
  }
  return;
}



/* 302d:09f5 */

void __cdecl16far drawAnimTextAt(char *param_1,uint16_t param_2)

{
  undefined2 in_stack_00000006;
  
  inputUpdate((ulong)MessageDelay << 1);
  drawTextAt((char *)CONCAT22(in_stack_00000006,param_1),param_2);
  return;
}



/* 302d:0a1b */

void __cdecl16far say(char *msg)

{
  drawAnimTextAt((char *)msg,0xa000);
  return;
}



/* 302d:0a30 */

void __cdecl16far font_302d_0a30(void)

{
  TextBlitCycle._2_2_ = 0;
  TextBlitCycle._0_2_ = 0;
  return;
}



/* 302d:0a41 */

void __cdecl16far uiNotify(char *msg,uint16_t dst)

{
  bool mice_no_update;
  
  inputUpdate((ulong)MessageDelay << 1);
  TextBlitCycle._2_2_ = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  TextBlitCycle._0_2_ = *(undefined2 *)BDA_DailyTimeCounter;
  BlitRects[4].seg = dst;
  mice_no_update = MiceNeedsUpdate == '\0';
  if (mice_no_update) {
    ovr_miceRestoreArea(BlitRects + 4);
  }
  drawTextAt(msg,dst);
  if (mice_no_update) {
    ovr_miceBlitRect(BlitRects + 4);
  }
  if (dst != 0xa000) {
    ovr_blitRect(BlitRects + 4);
    ovr_miceUpdate();
  }
  BlitRects[4].seg = 0xa000;
  return;
}


