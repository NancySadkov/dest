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
