int __cdecl16far saveui_usesBlitText(char *prompt,int textSeg,int row)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t handle;
  far_t handle_00;
  uint ey;
  far_t far *pfVar1;
  int iVar2;
  int iVar3;
  uint16_t uVar4;
  undefined2 unaff_SI;
  byte *unaff_SS;
  char *in_stack_00000004;
  uint3 uStack_5e;
  uint8_t text;
  undefined1 uStack_5b;
  int in_stack_0000ffa6;
  uint8_t cursorX;
  byte bStack_5;
  uint16_t uStack_4;
  
  uStack_5e = (uint16_t)CONCAT22(text,unaff_SI);
  inputCancelled = 0;
  if (in_stack_00000004 != (char *)0x0 || (char *)prompt != (char *)0x0) {
    TextBlitX = 0x16;
    TextBlitY = 0xb;
    ovr_blitText(in_stack_00000004,(byte *)CONCAT22(Font03.ofs,(char *)prompt),Font03.seg,0xde,0xde,
                 7);
  }
  bStack_5 = 0;
  ey = (uint)uStack_5e;
  uStack_5e = (uint3)(uint)uStack_5e;
  uVar4 = (uint16_t)((ulong)((long)(*(uint16_t *)((uint8_t *)&(prompt) + 2)) * 0xf) >> 0x10);
  pfVar1 = ovr_stshRleCut((far_t far *)0x0,far_from_u32((uint32_t)(0x16a000)),(int)((long)(*(uint16_t *)((uint8_t *)&(prompt) + 2)) * 0xf) + 0x1d,222,
                          (*(uint16_t *)((uint8_t *)&(prompt) + 2)) * 0xf + 0x27,ey,0xde);
  TextBlitX = 0x2a;
  TextBlitY = (*(uint16_t *)((uint8_t *)&(prompt) + 2)) * 0xf + 0x1d;
  cursorX = 0;
  gfx.seg = (uint16_t)&text;
  gfx.ofs = uVar4;
  saveui_usesBlitGfx10
            (gfx,(char *)CONCAT22(&cursorX,unaff_SS),(byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(prompt) + 2)),unaff_SS),
             (uint *)uStack_5e,in_stack_0000ffa6);
  ovr_ovc40_flushInput();
L_saveui_4528_1d55_1E1D:
  do {
    while( true ) {
      while ((uStack_4 = uiReadKey2(), (((byte *)_ctype + 1)[uStack_4 & 0xff] & 2) != 0 &&
             (bStack_5 < 2))) {
        (&text)[bStack_5] = (uint8_t)uStack_4;
        (&uStack_5b)[bStack_5] = 0;
        iVar3 = ovr_font_textWidth((char *)&text,
                                   (char *)CONCAT13((char)(Font03.ofs >> 8),
                                                    CONCAT12((char)Font03.ofs,unaff_SS)),
                                   (char)Font03.ofs,Font03.seg);
        iVar2 = ovr_font_textWidth((char *)"_",
                                   (char *)CONCAT22(Font03.ofs,(char *)0x26510),
                                   (char)Font03.seg);
        if (iVar3 + iVar2 + 0x2aU < 0xe0) {
          bStack_5 = bStack_5 + 1;
        }
        (&text)[bStack_5] = 0x0;
        gfx_00.seg = (uint16_t)&text;
        gfx_00.ofs = uVar4;
        saveui_usesBlitGfx10
                  (gfx_00,(char *)CONCAT22(&cursorX,unaff_SS),
                   (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(prompt) + 2)),unaff_SS),(uint *)uStack_5e,in_stack_0000ffa6);
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
                   (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(prompt) + 2)),unaff_SS),(uint *)uStack_5e,in_stack_0000ffa6);
      }
    }
    if (0x4b00 < uStack_4) {
      if (uStack_4 == 0x4b34) goto L_saveui_4528_1d55_1F0C;
      if (uStack_4 == 0xfffe) {
L_saveui_4528_1d55_1F83:
        inputCancelled = 1;
        handle_00.seg = uVar4;
        handle_00.ofs = (uint16_t)pfVar1;
        ovr_stshFree(handle_00);
        return 0xffff;
      }
      if ((uStack_4 == 0xffff) && (MouseMoved == 0)) goto L_saveui_4528_1d55_1F59;
      goto L_saveui_4528_1d55_1E1D;
    }
    if (uStack_4 == 0x11b) goto L_saveui_4528_1d55_1F83;
    if (uStack_4 == 0xe08) goto L_saveui_4528_1d55_1F0C;
    if (uStack_4 == 0x1c0d) {
L_saveui_4528_1d55_1F59:
      handle.seg = uVar4;
      handle.ofs = (uint16_t)pfVar1;
      ovr_stshFree(handle);
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
