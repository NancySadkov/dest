uint __cdecl16far blitLabel(char *text,uint8_t *widths,int16_t max_width,uint8_t term,...)

{
  undefined1 uVar2;
  uint16_t uVar1;
  uint16_t ptext;
  uint16_t j;
  uint16_t i;
  uint16_t x;
  uint16_t w_seg;
  undefined1 in_stack_0000000e;
  uint16_t width;
  
  if (*(char *)CONCAT22((uint8_t *)widths,text) == '\0') {
    width = 0;
  }
  else {
    width = 0;
    j = 0;
    for (x = TextBlitX;
        ((text[j] != '\0' && (text[j] != '\n')) &&
        (x + ((uint16_t *)max_width)[(byte)text[j] + 0xa1] <= term + 1U));
        x = x + ((uint16_t *)max_width)[(byte)text[j] + 0xa1]) {
      width = j + 1;
      j = j + 1;
    }
    uVar1 = width;
    for (i = 0; i < width; i = i + 1) {
      uVar2 = (undefined1)(uVar1 >> 8);
      uVar1 = CONCAT11(uVar2,text[i]);
      blitLetter(text[i],(byte *)max_width,   /* hand fix: slot after widths */(uint8_t)max_width,CONCAT11(uVar2,in_stack_0000000e));
    }
  }
  return width;
}
