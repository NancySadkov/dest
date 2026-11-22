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
