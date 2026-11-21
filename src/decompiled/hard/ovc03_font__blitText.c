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
  undefined1 in_stack_0000000e;
  uint16_t bx;
  uint16_t snchars;
  
  if (*(char *)CONCAT22((byte *)widths,text) == '\0') {
    nchars = 0;
  }
  else {
    nchars = 0;
    snchars = 0;
    uVar4 = 0;
    for (bx = TextBlitX;
        (((text[uVar4] != '\0' && (text[uVar4] != '\n')) && (text[uVar4] != '\x1a')) &&
        (ch_width = fontChWidth((byte *)CONCAT22(seg,(*(uint16_t *)((uint8_t *)&(widths) + 2))),text[uVar4]),
        bx + ch_width <= term + 1U)); bx = bx + bVar1) {
      if (text[uVar4] == ' ') {
        nchars = uVar4 + 1;
      }
      snchars = uVar4 + 1;
      bVar1 = fontChWidth((byte *)CONCAT22(seg,(*(uint16_t *)((uint8_t *)&(widths) + 2))),text[uVar4]);
      uVar4 = uVar4 + 1;
    }
    uVar2 = (uint)(byte)text[uVar4];
    if (((uVar2 == 0) || (text[uVar4] == '\n')) || ((text[uVar4] == ' ' || (text[uVar4] == '\x1a')))
       ) {
      nchars = uVar4;
    }
    if (nchars == 0) {
      nchars = snchars;
    }
    for (index = 0; index < nchars; index = index + 1) {
      uVar3 = (undefined1)(uVar2 >> 8);
      uVar2 = CONCAT11(uVar3,text[index]);
      blitLetter(text[index],(byte *)seg,   /* hand fix: slot after widths == seg */(uint8_t)seg,CONCAT11(uVar3,in_stack_0000000e));
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
