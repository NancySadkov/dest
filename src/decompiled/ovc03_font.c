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
  word in_stack_0000000c;
  int in_stack_0000000e;
  
  while (in_stack_0000000e != 0) {
    memcpy((char *)CONCAT22(count,width),(char *)CONCAT22(dst,src),in_stack_0000000c);
    width = width + in_stack_0000000c;
    src = src + 0x140;
    in_stack_0000000e = in_stack_0000000e + -1;
  }
  return;
}



/* 302d:0035 */

far_t * __cdecl16far stshProcessFontSub(far_t *__return_storage_ptr__,far_t hndl)

{
  far_t *pfVar1;
  int16_t in_DX;
  uint8_t *psrc;
  int16_t line;
  uint16_t o;
  uint16_t m;
  undefined2 unaff_SS;
  uint8_t widths [96];
  uint8_t dchofs [192];
  uint8_t schofs [192];
  uint16_t x;
  uint16_t dofs;
  uint16_t height;
  uint16_t j;
  uint16_t i;
  uint32_t r;
  uint16_t xx;
  
  height = 0;
  for (line = 320; *(char *)((int)&__return_storage_ptr__->ofs + line) != -1; line = line + 0x140) {
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
          stshCopyFontChar((uint8_t *)((int)&__return_storage_ptr__->ofs + *(int *)(schofs + i * 2))
                           ,(uint8_t *)hndl.ofs,
                           (int)&pfVar1[0x48].ofs + *(int *)(dchofs + i * 2) + 1,in_DX);
          *(undefined2 *)((int)&pfVar1->ofs + i * 2 + 1) = *(undefined2 *)(dchofs + i * 2);
          *(uint8_t *)((int)&pfVar1[0x30].ofs + i + 1) = widths[i];
        }
        return pfVar1;
      }
      do {
        if (0x13f < m) {
          m = 0;
          for (o = height * 0x140 + x + 0x280; x = o,
              *(char *)((int)&__return_storage_ptr__->ofs + o) != -1; o = o + 0x140) {
            if (64000 < o) {
                    /* WARNING: Subroutine does not return */
              ovr_stExit(2);
            }
          }
        }
        for (; (*(char *)((int)&__return_storage_ptr__->ofs + o) != -1 && (m < 0x140)); m = m + 1) {
          o = o + 1;
        }
      } while (0x13f < m);
      *(uint16_t *)(schofs + i * 2) = o + 0x140;
      *(uint16_t *)(dchofs + i * 2) = dofs;
      j = 2;
      while( true ) {
        if (*(char *)((int)&__return_storage_ptr__->ofs + o + 1) == -1) break;
        j = j + 1;
        o = o + 1;
        m = m + 1;
      }
      if (0x13f < m + 1) break;
      widths[i] = (uint8_t)j;
      in_DX = (int16_t)((ulong)((long)(int)j * (long)(int)height) >> 0x10);
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

far_t * __cdecl16far stshProcessFont(far_t *__return_storage_ptr__,int16_t file_id)

{
  far_t handle;
  far_t handle_00;
  far_t hndl;
  stg_tmp_t *psVar1;
  far_t *pfVar2;
  uint16_t in_DX;
  
  psVar1 = ovr_grabLbm((int16_t)__return_storage_ptr__,0,0);
  if (psVar1 == (stg_tmp_t *)0x0 && in_DX == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(6);
  }
  hndl.seg = (uint16_t)psVar1;
  hndl.ofs = (psVar1->aptr).seg;
  pfVar2 = stshProcessFontSub((far_t *)(&psVar1->aptr)->ofs,hndl);
  handle.seg = (psVar1->bptr).seg;
  handle.ofs = (&psVar1->bptr)->ofs;
  ovr_stshFree(handle);
  handle_00.seg = in_DX;
  handle_00.ofs = (uint16_t)psVar1;
  ovr_stshFree(handle_00);
  return pfVar2;
}



/* 302d:028c */

void __cdecl16far blitLetter(char ch,byte *widths,uint8_t term)

{
  far_t gfx;
  far_t dst;
  uint8_t ch_index;
  uint uVar1;
  uint16_t letter_w;
  uint16_t ws;
  int iVar2;
  undefined2 uVar3;
  undefined1 in_stack_00000009;
  byte in_stack_0000000a;
  uint uStack_e;
  undefined4 uStack_a;
  undefined4 uStack_6;
  
  _widths = (byte *)CONCAT13(in_stack_00000009,CONCAT12(term,widths));
  if (((ch != '\r') && (ch != '\n')) && (ch != '\x1a')) {
    if (ch == '\x7f') {
      gfx.seg = LbxButton2.seg;
      gfx.ofs = LbxButton2.ofs;
      dst.seg = TextBlitDstSeg;
      dst.ofs = TextBlitY * 0x140 + TextBlitX + 0x140;
      ovr_blitLoadRleGfx(gfx,dst);
    }
    else {
      ch_index = ch + 0xe0;
      if (ch_index < 0x61) {
        uVar1 = (uint)*_widths;
        uVar3 = (undefined2)((ulong)_widths >> 0x10);
        letter_w = (uint16_t)widths[ch_index + 0xc1];
        uStack_6 = (byte *)CONCAT22(TextBlitDstSeg,(byte *)(TextBlitX + TextBlitY * 0x140));
        uStack_a = (byte *)CONCAT22(uVar3,widths + *(int *)(widths + (uint)ch_index * 2 + 1) + 0x121
                                   );
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
              uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + 1);
              uStack_a = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_a) + 2)),(byte *)uStack_a + 1);
              iVar2 = iVar2 + 1;
            }
            uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + (0x140 - letter_w));
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
                *uStack_6 = in_stack_0000000a;
              }
              else if (*uStack_a != 0) {
                *uStack_6 = *uStack_a;
              }
              uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + 1);
              uStack_a = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_a) + 2)),(byte *)uStack_a + 1);
              iVar2 = iVar2 + 1;
            }
            uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + (0x140 - letter_w));
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
                *uStack_6 = in_stack_0000000a;
              }
              else if ((*uStack_a < 0xe4) || (0xe7 < *uStack_a)) {
                if (*uStack_a != 0) {
                  *uStack_6 = *uStack_a;
                }
              }
              else {
                *uStack_6 = *uStack_a | 0x10;
              }
              uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + 1);
              uStack_a = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_a) + 2)),(byte *)uStack_a + 1);
              iVar2 = iVar2 + 1;
            }
            uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + (0x140 - letter_w));
          }
        }
        TextBlitX = TextBlitX + letter_w;
      }
      else {
        printf("Error 4 %d \r");
        ovr_biosReadKey();
      }
    }
  }
  return;
}



/* 302d:04eb */

uint8_t __cdecl16far fontChWidth(uint8_t *widths,char ch)

{
  uint8_t width;
  
  if ((byte)ch < 0x20) {
    width = 0x0;
  }
  else {
    width = ((uint8_t *)widths)[(byte)ch + 0xa1];
  }
  return width;
}



/* 302d:050a */

int __cdecl16far blitText(char *text,byte *widths,uint16_t seg,uint8_t term)

{
  byte bVar1;
  uint8_t ch_width;
  uint16_t nchars;
  uint16_t pt;
  uint uVar2;
  uint16_t index;
  undefined1 in_stack_0000000b;
  int in_stack_0000000c;
  uint16_t bx;
  uint16_t snchars;
  
  if (*_text == '\0') {
    nchars = 0;
  }
  else {
    nchars = 0;
    snchars = 0;
    uVar2 = 0;
    for (bx = TextBlitX;
        (((text[uVar2] != '\0' && (text[uVar2] != '\n')) && (text[uVar2] != '\x1a')) &&
        (ch_width = fontChWidth((uint8_t *)CONCAT22(_term,seg),text[uVar2]),
        bx + ch_width <= in_stack_0000000c + 1U)); bx = bx + bVar1) {
      if (text[uVar2] == ' ') {
        nchars = uVar2 + 1;
      }
      snchars = uVar2 + 1;
      bVar1 = fontChWidth((uint8_t *)CONCAT22(_term,seg),text[uVar2]);
      uVar2 = uVar2 + 1;
    }
    if (((text[uVar2] == '\0') || (text[uVar2] == '\n')) ||
       ((text[uVar2] == ' ' || (text[uVar2] == '\x1a')))) {
      nchars = uVar2;
    }
    if (nchars == 0) {
      nchars = snchars;
    }
    for (index = 0; index < nchars; index = index + 1) {
      blitLetter(text[index],(byte *)seg,term);
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

uint __cdecl16far blitLabel(char *text,uint8_t *widths,int16_t max_width,uint8_t term)

{
  uint16_t ptext;
  uint16_t j;
  uint16_t i;
  uint16_t x;
  uint16_t w_seg;
  undefined1 in_stack_0000000b;
  int in_stack_0000000c;
  uint16_t width;
  
  _max_width = CONCAT13(in_stack_0000000b,CONCAT12(term,max_width));
  if (*_text == '\0') {
    width = 0;
  }
  else {
    width = 0;
    j = 0;
    for (x = TextBlitX;
        ((w_seg = (uint16_t)((ulong)_max_width >> 0x10), text[j] != '\0' && (text[j] != '\n')) &&
        (x + *(byte *)(max_width + (uint)(byte)text[j] + 0xa1) <= in_stack_0000000c + 1U));
        x = x + *(byte *)(max_width + (uint)(byte)text[j] + 0xa1)) {
      width = j + 1;
      j = j + 1;
    }
    for (i = 0; i < width; i = i + 1) {
      blitLetter(text[i],(byte *)max_width,term);
    }
  }
  return width;
}



/* 302d:06ea */

/* Returns the pixel width of a string in the given font by summing font[ch+0xa1] over its
   characters. */

int __cdecl16far font_textWidth(char *text,char *font)

{
  int iVar1;
  int iVar2;
  
  if (text == (char *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    for (iVar2 = 0; ((char *)text)[iVar2] != '\0'; iVar2 = iVar2 + 1) {
      iVar1 = iVar1 + (uint)(byte)((char *)font)[(byte)((char *)text)[iVar2] + 0xa1];
    }
  }
  return iVar1;
}



/* 302d:072b */

uint16_t __cdecl16far inputUpdate(ulong msg_delay)

{
  char *pcVar1;
  ulong *puVar2;
  uint16_t uVar3;
  uint in_stack_0000fffa;
  uint3 uVar4;
  ulong prevTick;
  
  rightButtonLatch = 0;
  if (MiceNeedsUpdate == '\0') {
    uVar4 = (uint3)in_stack_0000fffa;
  }
  else {
    ovr_miceBlitRect((brect_t *)(BlitRects + 1));
    uVar4 = CONCAT12(1,in_stack_0000fffa);
  }
  prevTick = CONCAT13(GDebug,uVar4);
  GDebug = false;
  do {
    pcVar1 = ovr_draw_textProvidesMoreHousing();
  } while ((char)pcVar1 != '\0');
  do {
    uVar3 = *(uint16_t *)BDA_DailyTimeCounter;
    if ((*(uint16_t *)(BDA_DailyTimeCounter.ofs + 2) != InputEventTime.hi) ||
       (uVar3 != InputEventTime.lo)) {
      InputEventTime.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
      uVar3 = *(uint16_t *)BDA_DailyTimeCounter;
      InputEventTime.lo = uVar3;
      ovr_draw_usesBlitLoadRleGfx();
    }
    pcVar1 = ovr_draw_textProvidesMoreHousing();
    prevTick = CONCAT22((int)(prevTick >> 0x10),CONCAT11((char)pcVar1,(char)prevTick));
    if ((char)pcVar1 != '\0') break;
    puVar2 = ovr_attact_usesBDADailyTimeCounter((ulong *)TextBlitCycle,prevTick);
  } while ((uVar3 < (*(uint16_t *)((uint8_t *)&(msg_delay) + 2))) ||
          ((uVar3 == (*(uint16_t *)((uint8_t *)&(msg_delay) + 2)) && (puVar2 < (ulong *)msg_delay))));
  if ((char)(prevTick >> 0x10) != '\0') {
    ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
  }
  GDebug = (bool)(char)(prevTick >> 0x18);
  return CONCAT11(0x24,(char)(prevTick >> 8));
}



/* 302d:080b */

/* [R4] calls ovr_miceBlitRect */

uint __cdecl16far font_usesMiceBlitRect(byte msgDelay)

{
  bool bVar1;
  uint uVar2;
  uint16_t uVar3;
  char *pcVar4;
  undefined1 uVar5;
  char cStack_3;
  
  rightButtonLatch = 0;
  uVar2 = ovr_ovr_midGetSequenceStatus_entry();
  if ((uVar2 & 0xff) == 0) {
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
    uVar3 = inputUpdate((ulong)msgDelay);
    uVar2 = uVar3 & 0xff00;
  }
  else {
    if (MiceNeedsUpdate == '\0') {
      bVar1 = false;
    }
    else {
      ovr_miceBlitRect((brect_t *)(BlitRects + 1));
      bVar1 = true;
    }
    do {
      pcVar4 = ovr_draw_textProvidesMoreHousing();
    } while ((char)pcVar4 != '\0');
    do {
      pcVar4 = (char *)ovr_ovr_midGetSequenceStatus_entry();
      if ((char)pcVar4 == '\0') break;
      if ((*(uint16_t *)(BDA_DailyTimeCounter.ofs + 2) != InputEventTime.hi) ||
         (*(uint16_t *)BDA_DailyTimeCounter != InputEventTime.lo)) {
        InputEventTime.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
        InputEventTime.lo = *(uint16_t *)BDA_DailyTimeCounter;
        ovr_draw_usesBlitLoadRleGfx();
      }
      pcVar4 = ovr_draw_textProvidesMoreHousing();
      cStack_3 = (char)pcVar4;
    } while (cStack_3 == '\0');
    uVar5 = (undefined1)((uint)pcVar4 >> 8);
    if (bVar1) {
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
    }
    uVar2 = CONCAT11(uVar5,cStack_3);
  }
  return uVar2;
}



/* 302d:08ef */

void __cdecl16far drawTextAt(char *txt,uint16_t dst)

{
  uint16_t ndrawn;
  uint16_t txtsz;
  uint16_t in_stack_00000008;
  far_t gfx;
  far_t dst_00;
  
  if (GameRunning) {
    if (in_stack_00000008 != 0xa000) {
      ovr_blitRaw(0x1d,0x9c,0xcf,199,0xa000,in_stack_00000008);
    }
  }
  else {
    TextBlitFlag = 1;
    TextBlitDstSeg = in_stack_00000008;
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
    dst_00.seg = in_stack_00000008;
    dst_00.ofs = 0xc31d;
    gfx.seg = FontHandle.seg;
    gfx.ofs = FontHandle.ofs;
    ovr_blitLoadRleGfx(gfx,dst_00);
    for (TextBlitY = 0x9c; TextBlitX = 0x1d, TextBlitY + 9 < 200; TextBlitY = TextBlitY + 0xb) {
      ndrawn = blitText(txt,(byte *)dst,Font03.ofs,(uint8_t)Font03.seg);
      txtsz = strlen(txt);
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
  inputUpdate((ulong)MessageDelay << 1);
  drawTextAt(text,dst);
  return;
}



/* 302d:0a1b */

void __cdecl16far say(char *msg)

{
  uint16_t in_stack_00000006;
  
  drawAnimTextAt(msg,in_stack_00000006);
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

void __cdecl16far uiNotify(char *msg,uint16_t dst)

{
  uint8_t mice_no_update;
  uint16_t in_stack_00000008;
  
  inputUpdate((ulong)MessageDelay << 1);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
  BlitRects[4].seg = in_stack_00000008;
  mice_no_update = MiceNeedsUpdate == '\0';
  if ((bool)mice_no_update) {
    ovr_miceRestoreArea((brect_t *)(BlitRects + 4));
  }
  drawTextAt(msg,dst);
  if ((bool)mice_no_update) {
    ovr_miceBlitRect((brect_t *)(BlitRects + 4));
  }
  if (in_stack_00000008 != 0xa000) {
    ovr_blitRect((brect_t *)(BlitRects + 4));
    ovr_miceUpdate();
  }
  BlitRects[4].seg = 0xa000;
  return;
}


