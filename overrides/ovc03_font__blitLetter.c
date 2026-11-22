/* 302d:028c */
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
      ovr_blitLoadRleGfx(gfx,rle_dst);
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
