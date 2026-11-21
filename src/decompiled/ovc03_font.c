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
    memcpy((char *)CONCAT22((uint8_t *)dst,(*(uint16_t *)((uint8_t *)&(src) + 2))),
           (char *)CONCAT22((uint8_t *)src,in_stack_00000004),(*(uint16_t *)((uint8_t *)&(dst) + 2)));
    src = (uint8_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(src) + 2)) + (*(uint16_t *)((uint8_t *)&(dst) + 2)),(uint8_t *)src);
    in_stack_00000004 = in_stack_00000004 + 0x140;
    width = width + -1;
  }
  return;
}



/* 302d:0035 */

far_t * __cdecl16far stshProcessFontSub(far_t *__return_storage_ptr__,far_t hndl,...)

{
  far_t *pfVar1;
  undefined2 in_DX;
  uint8_t *psrc;
  int16_t line;
  uint16_t o;
  uint unaff_DI;
  uint16_t m;
  undefined2 unaff_SS;
  int in_stack_00000004;
  long lVar2;
  int16_t count;
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
  for (line = 320; *(char *)(in_stack_00000004 + line) != -1; line = line + 0x140) {
    if (height == 200) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit();
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
        lVar2 = (ulong)unaff_DI << 0x10;
        pfVar1 = ovr_stshAlloc();
        r = CONCAT22(in_DX,pfVar1);
        *(undefined1 *)r = (undefined1)height;
        for (i = 0; i < 0x60; i = i + 1) {
          count = (int16_t)((ulong)lVar2 >> 0x10);
          lVar2 = CONCAT22(count,height);
          stshCopyFontChar((uint8_t *)
                           CONCAT22((int)&pfVar1[0x48].ofs + *(int *)(dchofs + i * 2) + 1,
                                    __return_storage_ptr__),
                           (uint8_t *)(ulong)CONCAT12(widths[i],in_DX),height,count);
          *(undefined2 *)((int)&pfVar1->ofs + i * 2 + 1) = *(undefined2 *)(dchofs + i * 2);
          *(uint8_t *)((int)&pfVar1[0x30].ofs + i + 1) = widths[i];
        }
        return pfVar1;
      }
      do {
        if (0x13f < m) {
          m = 0;
          for (o = height * 0x140 + x + 0x280; x = o, *(char *)(in_stack_00000004 + o) != -1;
              o = o + 0x140) {
            if (64000 < o) {
                    /* WARNING: Subroutine does not return */
              ovr_stExit();
            }
          }
        }
        for (; (*(char *)(in_stack_00000004 + o) != -1 && (m < 0x140)); m = m + 1) {
          o = o + 1;
        }
      } while (0x13f < m);
      *(uint16_t *)(schofs + i * 2) = o + 0x140;
      *(uint16_t *)(dchofs + i * 2) = dofs;
      j = 2;
      while( true ) {
        if (*(char *)(in_stack_00000004 + o + 1) == -1) break;
        j = j + 1;
        o = o + 1;
        m = m + 1;
      }
      if (0x13f < m + 1) break;
      widths[i] = (uint8_t)j;
      in_DX = (undefined2)((ulong)((long)(int)j * (long)(int)height) >> 0x10);
      dofs = dofs + (int)((long)(int)j * (long)(int)height);
      m = m + 2;
      o = o + 2;
      i = i + 1;
    }
                    /* WARNING: Subroutine does not return */
    ovr_stExit();
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit();
}



/* 302d:021a */

far_t * __cdecl16far stshProcessFont(far_t *__return_storage_ptr__,int16_t file_id)

{
  far_t handle;
  far_t handle_00;
  far_t hndl;
  stg_tmp_t *n;
  far_t *pfVar1;
  uint16_t in_DX;
  uint16_t uVar2;
  
  n = ovr_grabLbm();
  if (n == (stg_tmp_t *)0x0 && in_DX == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit((int)n,6);
  }
  hndl.seg = in_DX;
  hndl.ofs = (uint16_t)n;
  uVar2 = in_DX;
  pfVar1 = stshProcessFontSub((far_t *)(n->aptr).seg,hndl,(&n->aptr)->ofs);
  handle.seg = (uint16_t)n;
  handle.ofs = (n->bptr).seg;
  ovr_stshFree(handle,(&n->bptr)->ofs,uVar2,pfVar1,in_DX);
  handle_00.seg = (uint16_t)n;
  handle_00.ofs = uVar2;
  ovr_stshFree(handle_00,n);
  return pfVar1;
}



/* 302d:028c */

void __cdecl16far blitLetter(char ch,byte *widths,uint8_t term,...)

{
  uint8_t ch_index;
  uint uVar1;
  uint16_t letter_w;
  uint16_t ws;
  int iVar2;
  uint16_t unaff_DI;
  char in_stack_00000004;
  far_t gfx;
  far_t dst;
  uint uStack_e;
  byte *pbStack_a;
  undefined4 uStack_6;
  
  if (((in_stack_00000004 != '\r') && (in_stack_00000004 != '\n')) && (in_stack_00000004 != '\x1a'))
  {
    if (in_stack_00000004 == '\x7f') {
      dst.seg = unaff_DI;
      dst.ofs = TextBlitDstSeg;
      gfx.seg = TextBlitY * 0x140 + TextBlitX + 0x140;
      gfx.ofs = LbxButton2.seg;
      ovr_blitLoadRleGfx(gfx,dst,LbxButton2.ofs);
    }
    else {
      ch_index = in_stack_00000004 + 0xe0;
      if (ch_index < 0x61) {
        uVar1 = (uint)*(byte *)CONCAT22((byte *)widths,_ch);
        letter_w = (uint16_t)_ch[ch_index + 0xc1];
        uStack_6 = (byte *)CONCAT22(TextBlitDstSeg,(byte *)(TextBlitX + TextBlitY * 0x140));
        pbStack_a = (byte *)CONCAT22((byte *)widths,
                                     _ch + *(int *)(_ch + (uint)ch_index * 2 + 1) + 0x121);
        if (BlitLetterType == '\x02') {
          for (uStack_e = 0; uStack_e < uVar1; uStack_e = uStack_e + 1) {
            iVar2 = 0;
            while( true ) {
              if ((int)letter_w <= iVar2) break;
              if ((*pbStack_a == 0x9f) || (*pbStack_a == 0x9b)) {
                *uStack_6 = 0x92;
              }
              else if (*pbStack_a != 0) {
                *uStack_6 = *pbStack_a;
              }
              uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + 1);
              pbStack_a = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(pbStack_a) + 2)),(byte *)pbStack_a + 1);
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
              if (*pbStack_a == 1) {
                *uStack_6 = 0xec;
              }
              else if (*pbStack_a == 0xe) {
                *uStack_6 = (*(uint8_t *)((uint8_t *)&(widths) + 2));
              }
              else if (*pbStack_a != 0) {
                *uStack_6 = *pbStack_a;
              }
              uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + 1);
              pbStack_a = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(pbStack_a) + 2)),(byte *)pbStack_a + 1);
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
              if (*pbStack_a == 1) {
                *uStack_6 = 0xec;
              }
              else if (*pbStack_a == 0xe) {
                *uStack_6 = (*(uint8_t *)((uint8_t *)&(widths) + 2));
              }
              else if ((*pbStack_a < 0xe4) || (0xe7 < *pbStack_a)) {
                if (*pbStack_a != 0) {
                  *uStack_6 = *pbStack_a;
                }
              }
              else {
                *uStack_6 = *pbStack_a | 0x10;
              }
              uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + 1);
              pbStack_a = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(pbStack_a) + 2)),(byte *)pbStack_a + 1);
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

int __cdecl16far blitText(char *text,byte *widths,uint16_t seg,uint8_t term,...)

{
  byte bVar1;
  uint8_t ch_width;
  uint16_t nchars;
  undefined1 uVar3;
  uint uVar2;
  uint16_t pt;
  uint uVar4;
  uint16_t index;
  undefined2 unaff_DI;
  char *in_stack_00000004;
  uint16_t bx;
  uint16_t snchars;
  
  if (*(char *)CONCAT22((char *)text,in_stack_00000004) == '\0') {
    nchars = 0;
  }
  else {
    nchars = 0;
    snchars = 0;
    bx = TextBlitX;
    uVar4 = 0;
    while( true ) {
      if (((in_stack_00000004[uVar4] == '\0') || (in_stack_00000004[uVar4] == '\n')) ||
         (in_stack_00000004[uVar4] == '\x1a')) break;
      ch_width = fontChWidth((uint8_t *)CONCAT22((byte *)widths,(*(uint16_t *)((uint8_t *)&(text) + 2))),in_stack_00000004[uVar4]
                            );
      if ((*(uint16_t *)((uint8_t *)&(widths) + 2)) + 1U < bx + ch_width) break;
      if (in_stack_00000004[uVar4] == ' ') {
        nchars = uVar4 + 1;
      }
      snchars = uVar4 + 1;
      bVar1 = fontChWidth((uint8_t *)CONCAT22((byte *)widths,(*(uint16_t *)((uint8_t *)&(text) + 2))),in_stack_00000004[uVar4]);
      bx = bx + bVar1;
      uVar4 = uVar4 + 1;
    }
    uVar2 = (uint)(byte)in_stack_00000004[uVar4];
    if (((uVar2 == 0) || (in_stack_00000004[uVar4] == '\n')) ||
       ((in_stack_00000004[uVar4] == ' ' || (in_stack_00000004[uVar4] == '\x1a')))) {
      nchars = uVar4;
    }
    if (nchars == 0) {
      nchars = snchars;
    }
    for (index = 0; index < nchars; index = index + 1) {
      uVar3 = (undefined1)(uVar2 >> 8);
      uVar2 = CONCAT11(uVar3,in_stack_00000004[index]);
      blitLetter((char)((ulong)text >> 0x10),
                 (byte *)CONCAT13(uVar3,CONCAT12((undefined1)seg,(byte *)widths)),(uint8_t)unaff_DI,
                 uVar2,(undefined1)seg);
    }
    for (; in_stack_00000004[nchars] == '\r'; nchars = nchars + 1) {
    }
    if (in_stack_00000004[nchars] == '\n') {
      nchars = nchars + 1;
    }
    else {
      for (; in_stack_00000004[nchars] == ' '; nchars = nchars + 1) {
      }
    }
    for (; in_stack_00000004[nchars] == '\x1a'; nchars = nchars + 1) {
    }
  }
  return nchars;
}



/* 302d:0634 */

uint __cdecl16far blitLabel(char *text,uint8_t *widths,int16_t max_width,uint8_t term,...)

{
  undefined1 uVar2;
  uint16_t uVar1;
  uint16_t ptext;
  uint16_t j;
  uint16_t i;
  undefined2 unaff_DI;
  uint16_t x;
  uint16_t w_seg;
  char *in_stack_00000004;
  uint16_t width;
  
  if (*(char *)CONCAT22((char *)text,in_stack_00000004) == '\0') {
    width = 0;
  }
  else {
    width = 0;
    j = 0;
    for (x = TextBlitX;
        ((in_stack_00000004[j] != '\0' && (in_stack_00000004[j] != '\n')) &&
        (x + *(byte *)((*(uint16_t *)((uint8_t *)&(text) + 2)) + (uint)(byte)in_stack_00000004[j] + 0xa1) <= (*(uint16_t *)((uint8_t *)&(widths) + 2)) + 1U));
        x = x + *(byte *)((*(uint16_t *)((uint8_t *)&(text) + 2)) + (uint)(byte)in_stack_00000004[j] + 0xa1)) {
      width = j + 1;
      j = j + 1;
    }
    uVar1 = width;
    for (i = 0; i < width; i = i + 1) {
      uVar2 = (undefined1)(uVar1 >> 8);
      uVar1 = CONCAT11(uVar2,in_stack_00000004[i]);
      blitLetter((char)((ulong)text >> 0x10),
                 (byte *)CONCAT22(CONCAT11(uVar2,(undefined1)max_width),(uint8_t *)widths),
                 (uint8_t)unaff_DI,uVar1);
    }
  }
  return width;
}



/* 302d:06ea */

/* Returns the pixel width of a string in the given font by summing font[ch+0xa1] over its
   characters. */

int __cdecl16far font_textWidth(char *text,char *font,...)

{
  int iVar1;
  int iVar2;
  int in_stack_00000004;
  
  if (in_stack_00000004 == 0 && (char *)text == (char *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    for (iVar2 = 0; *(char *)(in_stack_00000004 + iVar2) != '\0'; iVar2 = iVar2 + 1) {
      iVar1 = iVar1 + (uint)*(byte *)((*(uint16_t *)((uint8_t *)&(text) + 2)) + (uint)*(byte *)(in_stack_00000004 + iVar2) + 0xa1
                                     );
    }
  }
  return iVar1;
}



/* 302d:072b */

uint16_t __cdecl16far inputUpdate(ulong msg_delay,...)

{
  bool bVar1;
  undefined1 uVar2;
  ulong *puVar3;
  uint16_t uVar4;
  char cVar5;
  ulong *in_stack_00000004;
  undefined1 in_stack_0000fffa;
  undefined1 in_stack_0000fffb;
  undefined1 uVar6;
  
  rightButtonLatch = 0;
  cVar5 = MiceNeedsUpdate != '\0';
  if ((bool)cVar5) {
    ovr_miceBlitRect((brect_t *)CONCAT13(in_stack_0000fffb,CONCAT12(in_stack_0000fffa,0x2410)),0x44a
                    );
  }
  uVar6 = GDebug;
  GDebug = false;
  do {
    bVar1 = ovr_draw_textProvidesMoreHousing();
  } while (bVar1);
  do {
    uVar4 = *(uint16_t *)BDA_DailyTimeCounter;
    if ((*(uint16_t *)(BDA_DailyTimeCounter.ofs + 2) != InputEventTime.hi) ||
       (uVar4 != InputEventTime.lo)) {
      InputEventTime.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
      uVar4 = *(uint16_t *)BDA_DailyTimeCounter;
      InputEventTime.lo = uVar4;
      ovr_draw_usesBlitLoadRleGfx();
    }
    uVar2 = ovr_draw_textProvidesMoreHousing();
    if ((bool)uVar2) break;
    puVar3 = ovr_attact_usesBDADailyTimeCounter((*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)),(undefined2)TextBlitCycle);
  } while ((uVar4 < (uint)msg_delay) || ((uVar4 == (uint)msg_delay && (puVar3 < in_stack_00000004)))
          );
  if (cVar5 != '\0') {
    ovr_miceRestoreArea((brect_t *)CONCAT13(uVar2,CONCAT12(in_stack_0000fffa,0x2410)),0x44a);
  }
  GDebug = (bool)uVar6;
  return CONCAT11(0x24,uVar2);
}



/* 302d:080b */

/* [R4] calls ovr_miceBlitRect */

uint __cdecl16far font_usesMiceBlitRect(byte msgDelay,...)

{
  bool bVar1;
  uint uVar2;
  uint16_t uVar3;
  undefined1 extraout_AH;
  undefined1 uVar4;
  byte in_stack_00000004;
  undefined4 in_stack_0000fffa;
  uint uVar7;
  brect_t *pbVar5;
  long lVar6;
  
  rightButtonLatch = 0;
  uVar7 = (uint)((ulong)in_stack_0000fffa >> 0x10);
  uVar2 = ovr_ovr_midGetSequenceStatus_entry();
  if ((uVar2 & 0xff) == 0) {
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
    uVar3 = inputUpdate((ulong)uVar7 << 0x10,(uint)in_stack_00000004);
    uVar2 = uVar3 & 0xff00;
  }
  else {
    if (MiceNeedsUpdate == '\0') {
      pbVar5 = (brect_t *)((ulong)(uVar7 >> 8) << 0x18);
    }
    else {
      pbVar5 = (brect_t *)CONCAT22(uVar7,(brect_t *)((char *)"puppetmaker" + 3));
      ovr_miceBlitRect(pbVar5,0x44a);
      pbVar5 = (brect_t *)CONCAT13((char)((ulong)pbVar5 >> 0x18),0x10000);
    }
    do {
      pbVar5 = (brect_t *)((ulong)pbVar5 & 0xffff0000);
      bVar1 = ovr_draw_textProvidesMoreHousing();
    } while (bVar1);
    do {
      pbVar5 = (brect_t *)((ulong)pbVar5 & 0xffff0000);
      uVar2 = ovr_ovr_midGetSequenceStatus_entry();
      uVar7 = (uint)((ulong)pbVar5 >> 0x10);
      if ((char)uVar2 == '\0') break;
      if ((*(uint16_t *)(BDA_DailyTimeCounter.ofs + 2) != InputEventTime.hi) ||
         (*(uint16_t *)BDA_DailyTimeCounter != InputEventTime.lo)) {
        InputEventTime.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
        InputEventTime.lo = *(uint16_t *)BDA_DailyTimeCounter;
        ovr_draw_usesBlitLoadRleGfx();
      }
      lVar6 = (ulong)uVar7 << 0x10;
      bVar1 = ovr_draw_textProvidesMoreHousing();
      uVar2 = CONCAT11(extraout_AH,bVar1);
      pbVar5 = (brect_t *)CONCAT13(bVar1,(int3)lVar6);
    } while (!bVar1);
    uVar4 = (undefined1)(uVar2 >> 8);
    if ((char)((ulong)pbVar5 >> 0x10) != '\0') {
      pbVar5 = (brect_t *)
               CONCAT22((int)((ulong)pbVar5 >> 0x10),(brect_t *)((char *)"puppetmaker" + 3));
      ovr_miceRestoreArea(pbVar5,0x44a);
    }
    uVar2 = CONCAT11(uVar4,(char)((ulong)pbVar5 >> 0x18));
  }
  return uVar2;
}



/* 302d:08ef */

void __cdecl16far drawTextAt(char *txt,uint16_t dst,...)

{
  uint16_t ndrawn;
  uint16_t txtsz;
  uint8_t unaff_DI;
  char *in_stack_00000004;
  
  if (GameRunning) {
    if ((*(uint16_t *)((uint8_t *)&(txt) + 2)) != 0xa000) {
      ovr_blitRaw(0x9c,0xcf,199,0xa000,(*(uint16_t *)((uint8_t *)&(txt) + 2)),0x1d);
    }
  }
  else {
    TextBlitFlag = 1;
    TextBlitDstSeg = (*(uint16_t *)((uint8_t *)&(txt) + 2));
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
    ovr_blitLoadRleGfx();
    for (TextBlitY = 0x9c; TextBlitX = 0x1d, TextBlitY + 9 < 200; TextBlitY = TextBlitY + 0xb) {
      ndrawn = blitText((char *)CONCAT22(Font03.ofs,(char *)txt),(byte *)CONCAT22(0xcf,Font03.seg),
                        0xed,unaff_DI,in_stack_00000004);
      txtsz = strlen((char *)CONCAT22((char *)txt,in_stack_00000004));
      if (txtsz <= ndrawn) {
        ovr_clean_ring_buffer();
        return;
      }
      in_stack_00000004 = in_stack_00000004 + ndrawn;
    }
  }
  return;
}



/* 302d:09f5 */

void __cdecl16far drawAnimTextAt(char *text,uint16_t dst)

{
  uint unaff_BP;
  undefined2 in_stack_00000004;
  
  inputUpdate((ulong)unaff_BP << 0x10,(uint)MessageDelay << 1);
  drawTextAt(text,unaff_BP,in_stack_00000004);
  return;
}



/* 302d:0a1b */

void __cdecl16far say(char *msg,...)

{
  uint16_t unaff_BP;
  undefined2 in_stack_00000004;
  
  drawAnimTextAt((char *)CONCAT22(0xa000,(char *)msg),unaff_BP);
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

void __cdecl16far uiNotify(char *msg,uint16_t dst,...)

{
  uint unaff_SI;
  uint8_t mice_no_update;
  undefined2 in_stack_00000004;
  
  inputUpdate((ulong)unaff_SI << 0x10,(uint)MessageDelay << 1);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
  BlitRects[4].seg = (*(uint16_t *)((uint8_t *)&(msg) + 2));
  mice_no_update = MiceNeedsUpdate == '\0';
  if ((bool)mice_no_update) {
    ovr_miceRestoreArea((brect_t *)CONCAT22(unaff_SI,(brect_t *)((char *)"puppetmaker" + 3)),0x468);
  }
  drawTextAt(msg,unaff_SI,in_stack_00000004);
  if ((bool)mice_no_update) {
    ovr_miceBlitRect((brect_t *)CONCAT22(unaff_SI,(brect_t *)((char *)"puppetmaker" + 3)),0x468);
  }
  if ((*(uint16_t *)((uint8_t *)&(msg) + 2)) != 0xa000) {
    ovr_blitRect((brect_t *)CONCAT22(unaff_SI,(brect_t *)((char *)"puppetmaker" + 3)),0x468);
    ovr_miceUpdate();
  }
  BlitRects[4].seg = 0xa000;
  return;
}


