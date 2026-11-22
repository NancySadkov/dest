char * __cdecl16far uiReadString(char *textOfs,int textSeg,int row,char *gfxOfs,uint16_t gfxSeg,...)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t dst;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  far_t handle_03;
  far_t handle_04;
  size_t sVar1;
  far_t far *pfVar2;
  uint16_t uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  uint8_t *puVar7;
  uint16_t uVar8;
  undefined2 uVar9;
  uint *unaff_SI;
  byte *unaff_SS;
  uint8_t *puVar10;
  uint *ey;
  uint3 uStack_5e;
  uint8_t text;
  undefined1 uStack_5b;
  int in_stack_0000ffa6;
  uint8_t cursorX;
  byte bStack_5;
  uint16_t uStack_4;
  
  uStack_5e = (uint16_t)CONCAT22(text,unaff_SI);
  UserWantsExit = 0;
  inputCancelled = 0;
  if (textOfs != (char *)0x0 || textSeg != 0) {
    TextBlitX = 0x16;
    TextBlitY = 0xb;
    ovr_blitText(textOfs,(byte *)CONCAT22(Font03.ofs,textSeg),Font03.seg,0xde,0xde,7);
  }
  if (gfxOfs == (char *)0x0 && gfxSeg == 0) {
    uStack_5e = ZEXT23(ey);
  }
  else {
    strcpy((char *)CONCAT22(unaff_SS,&text),(char *)CONCAT22(gfxSeg,gfxOfs));
  }
  sVar1 = strlen((char *)CONCAT22(unaff_SS,&text));
  bStack_5 = (byte)sVar1;
  uVar8 = (uint16_t)((ulong)((long)row * 0xf) >> 0x10);
  pfVar2 = ovr_stshRleCut((far_t far *)0x0,far_from_u32((uint32_t)(0x16a000)),(int)((long)row * 0xf) + 0x1d,222,
                          row * 0xf + 0x29,(int16_t)ey,0xde);
  TextBlitX = 0x2a;
  TextBlitY = row * 0xf + 0x1d;
  cursorX = 0;
  gfx.seg = (uint16_t)&text;
  gfx.ofs = uVar8;
  saveui_usesBlitGfx10
            (gfx,(char *)CONCAT22(&cursorX,unaff_SS),(byte *)CONCAT22(row,unaff_SS),(uint *)uStack_5e,
             in_stack_0000ffa6);
  uVar3 = row * 0x12c0 + 0x2096;
  gfx_02.seg = trianglsCut4Seg;
  gfx_02.ofs = trianglsCut4Ofs;
  dst.seg = 0xa000;
  dst.ofs = uVar3;
  ovr_blitLoadRleGfx(gfx_02,dst,(char)uVar3);
  ovr_ovc40_flushInput();
  GMenuFlag = 1;
L_uiReadString_0DC9:
  do {
    while( true ) {
      while ((((uStack_4 = uiReadKey2(), 0x1f < (uStack_4 & 0xff) && ((uStack_4 & 0xff) < 0x7f)) &&
              (bStack_5 < 0x4f)) && ((uStack_4 & 0xff) != 0x40))) {
        (&text)[bStack_5] = (uint8_t)uStack_4;
        (&uStack_5b)[bStack_5] = 0;
        iVar4 = ovr_font_textWidth((char *)&text,
                                   (char *)CONCAT13((char)(Font03.ofs >> 8),
                                                    CONCAT12((char)Font03.ofs,unaff_SS)),
                                   (char)Font03.ofs,Font03.seg);
        iVar5 = ovr_font_textWidth((char *)"_",
                                   (char *)CONCAT22(Font03.ofs,(char *)0x26510),
                                   (char)Font03.seg);
        if (iVar4 + iVar5 + 0x2aU < 0xe0) {
          bStack_5 = bStack_5 + 1;
        }
        (&text)[bStack_5] = 0x0;
        gfx_00.seg = (uint16_t)&text;
        gfx_00.ofs = uVar8;
        saveui_usesBlitGfx10
                  (gfx_00,(char *)CONCAT22(&cursorX,unaff_SS),(byte *)CONCAT22(row,unaff_SS),
                   (uint *)uStack_5e,in_stack_0000ffa6);
      }
      if (uStack_4 != 0x4b00) break;
L_uiReadString_0ECE:
      if (bStack_5 != 0) {
        bStack_5 = bStack_5 - 1;
        (&text)[bStack_5] = 0x0;
        gfx_01.seg = (uint16_t)&text;
        gfx_01.ofs = uVar8;
        saveui_usesBlitGfx10
                  (gfx_01,(char *)CONCAT22(&cursorX,unaff_SS),(byte *)CONCAT22(row,unaff_SS),
                   (uint *)uStack_5e,in_stack_0000ffa6);
      }
    }
    if (uStack_4 < 0x4b01) {
      if (uStack_4 == 0x11b) {
        UserWantsExit = 1;
L_uiReadString_1068:
        inputCancelled = 1;
        handle_03.seg = uVar8;
        handle_03.ofs = (uint16_t)pfVar2;
        ovr_stshFree(handle_03);
        if (gfxOfs != (char *)0x0 || gfxSeg != 0) {
          handle_04.seg = gfxSeg;
          handle_04.ofs = (uint16_t)gfxOfs;
          ovr_stshFree(handle_04);
        }
        GMenuFlag = 0;
        return (char *)0x0;
      }
      if (uStack_4 == 0xe08) goto L_uiReadString_0ECE;
      if (uStack_4 == 0x1c0d) goto L_uiReadString_0FF7;
      goto L_uiReadString_0DC9;
    }
    if (uStack_4 == 0x4b34) goto L_uiReadString_0ECE;
    if (uStack_4 == 0xfffe) goto L_uiReadString_1068;
    if (uStack_4 == 0xffff) {
      if (((MouseMoved == 0) && (8 < MouseX)) &&
         ((MouseX < 0x19 && ((0xb4 < MouseY && ((MouseY < 0xb6 | 0xeU) != 0)))))) {
        inputCancelled = 1;
        handle.seg = uVar8;
        handle.ofs = (uint16_t)pfVar2;
        ovr_stshFree(handle);
        if (gfxOfs != (char *)0x0 || gfxSeg != 0) {
          handle_00.seg = gfxSeg;
          handle_00.ofs = (uint16_t)gfxOfs;
          ovr_stshFree(handle_00);
        }
        GMenuFlag = 0;
        return (char *)0x0;
      }
      if ((((MouseMoved == 0) && (0x15 < MouseX)) && (MouseX < 0x26)) &&
         ((row * 0xf + 0x1aU <= MouseY && (MouseY <= row * 0xf + 0x28U)))) {
L_uiReadString_0FF7:
        handle_01.seg = uVar8;
        handle_01.ofs = (uint16_t)pfVar2;
        ovr_stshFree(handle_01);
        GMenuFlag = 0;
        if (bStack_5 == 0) {
          if (gfxOfs != (char *)0x0 || gfxSeg != 0) {
            handle_02.seg = gfxSeg;
            handle_02.ofs = (uint16_t)gfxOfs;
            ovr_stshFree(handle_02);
          }
          pcVar6 = (char *)0x0;
        }
        else {
          puVar10 = &text;
          uVar9 = 0;
          puVar7 = ovr_stshRealloc((uint32_t)CONCAT22(gfxSeg,gfxOfs),(ulong)(bStack_5 + 1));
          pcVar6 = strcpy((char *)CONCAT22(uVar9,puVar7),(char *)CONCAT22(unaff_SS,puVar10));
        }
        return pcVar6;
      }
    }
  } while( true );
}
