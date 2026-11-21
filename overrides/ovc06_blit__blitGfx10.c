void __cdecl16far blitGfx10(far_t gfx,uint16_t x,uint16_t y,brect_t *dst,bool type,...)

{
  far_t dst_00;
  far_t src;
  int iVar1;
  uint16_t in_DX;
  uint16_t pdst;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  uint16_t unaff_SS;
  undefined1 uStack000f;
  bool in_stack_00000010;
  far_t dst_01;
  uint8_t rowBuf;
  uint16_t dst_h;
  uint16_t dst_w;
  uint16_t dst_y;
  uint16_t dst_x;
  int iStack_1c;
  uint16_t uStack_1a;
  uint16_t uStack_18;
  uint16_t uStack_16;
  int iStack_14;
  uint16_t uStack_12;
  int iStack_10;
  uint16_t uStack_e;
  uint16_t uStack_c;
  uint16_t uStack_a;
  uint16_t uStack_8;
  uint16_t pfn;
  uint16_t uStack_4;
  
  dst = (uint16_t *)CONCAT13(uStack000f,CONCAT12(type,dst));
  uVar4 = 0x317e;
  if (gfx.ofs != 0 || gfx.seg != 0) {
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) == '\0') {
      uVar4 = 0x2337;
      gfx.ofs = (uint16_t)ovr_stshLoadGfx(gfx);
      gfx.seg = in_DX;
    }
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) != '\x01') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
    dst_x = dst->x;   /* hand fix: read the first field; *dst is the whole structure */
    uVar3 = (undefined2)((ulong)dst >> 0x10);
    dst_y = dst->y;
    dst_w = dst->w;
    dst_h = dst->h;
    if (((((int)x < (int)dst_x) || ((int)y < (int)dst_y)) ||
        ((int)dst_w < (int)(x + *(int *)(gfx.ofs + 5) + -1))) ||
       ((int)dst_h < (int)(y + *(int *)(gfx.ofs + 7) + -1))) {
      if (in_stack_00000010 == false) {
        pfn = 0x133;
      }
      else {
        pfn = 0x129;
      }
      uStack_4 = 0x22a6;
      if (((int)dst_x <= (int)(x + *(int *)(gfx.ofs + 5) + -1)) && ((int)x <= (int)dst_w)) {
        if ((int)x < (int)dst_x) {
          iStack_10 = dst_x - x;
          uStack_8 = dst_x;
        }
        else {
          uStack_8 = x;
          iStack_10 = 0;
        }
        uStack_c = dst_w;
        if ((int)(x + *(int *)(gfx.ofs + 5) + -1) <= (int)dst_w) {
          uStack_c = (x + *(int *)(gfx.ofs + 5)) - 1;
        }
        uStack_12 = (uStack_c - uStack_8) + 1;
        uStack_a = dst_y;
        if ((int)dst_y <= (int)y) {
          uStack_a = y;
        }
        uStack_e = dst_h;
        if ((int)(y + *(int *)(gfx.ofs + 7) + -1) <= (int)dst_h) {
          uStack_e = (y + *(int *)(gfx.ofs + 7)) - 1;
        }
        iStack_14 = (uStack_e - y) + 1;
        uStack_18 = uStack_8 + uStack_a * 0x140;
        uStack_16 = dst->seg;
        iStack_1c = gfx.ofs + 9;
        uStack_1a = gfx.seg;
        for (iVar2 = 0; (iVar2 < iStack_14 && ((int)(iVar2 + y) <= (int)dst_h)); iVar2 = iVar2 + 1)
        {
          iVar1 = (*(code *)pfn)(uVar4,iStack_1c,uStack_1a,&rowBuf);
          iStack_1c = iStack_1c + iVar1;
          if ((int)dst_y <= (int)(iVar2 + y)) {
            dst_01.seg = uStack_16;
            dst_01.ofs = uStack_18;
            uVar4 = 0x138e;
            src.seg = unaff_SS;
            src.ofs = (uint16_t)(&rowBuf + iStack_10);
            blitTillAlpha(dst_01,src,uStack_12);
            uStack_18 = uStack_18 + 0x140;
          }
        }
      }
    }
    else {
      dst_00.seg = dst->seg;
      dst_00.ofs = x + y * 0x140;
      drawGfx(gfx,dst_00,in_stack_00000010);
    }
  }
  return;
}
