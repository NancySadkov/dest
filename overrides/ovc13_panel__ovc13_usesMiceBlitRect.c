void __cdecl16far ovc13_usesMiceBlitRect(void)

{
  far_t dst;
  far_t dst_00;
  ulong *puVar1;
  int in_DX;
  uint8_t *paletteOfs;
  uint16_t unaff_SS;
  uint8_t paletteSeg;
  undefined2 in_stack_0000ffe2;
  uint8_t flashPalette1;
  uint8_t flashPalette2;
  uint8_t rect;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&stack0xffe2;
  F_SCOPY(far_from_u32((uint32_t)(0x24100846)),dst);
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&rect;
  F_SCOPY(far_from_u32((uint32_t)(0x24100858)),dst_00);
  puVar1 = ovr_attact_usesBDADailyTimeCounter(flashTickLo,CONCAT22(in_stack_0000ffe2,flashTickHi));
  if ((in_DX == 0) && (puVar1 <= (byte *)__C0_ASM_CopyRight + 4)) {
    paletteOfs = (uint8_t *)0x0;
  }
  else {
    flashTickHi = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    flashTickLo = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t */;
    FlashToggle = 1 - (FlashToggle != 0);
    paletteSeg = (uint8_t)unaff_SS;
    ovr_vgaSetPalette(&stack0xffe2 + (uint)FlashToggle * 3,paletteSeg,0xef,1);
    ovr_vgaSetPalette(&flashPalette1 + (uint)FlashToggle * 3,paletteSeg,0xee,1);
    paletteOfs = &flashPalette2 + (uint)FlashToggle * 3;
    ovr_vgaSetPalette(paletteOfs,paletteSeg,0xeb,1);
  }
  if ((((noAnimBlit == 0x0) && (GPaused == '\0')) && (mapViewActive == '\x01')) &&
     ((puVar1 = ovr_attact_usesBDADailyTimeCounter
                          (blitFrameTickLo,CONCAT22(in_stack_0000ffe2,blitFrameTickHi)),
      paletteOfs != (uint8_t *)0x0 || ((ulong *)((int)(undefined4 *)&_DATA + 3U) < puVar1)))) {
    ovr_miceRestoreArea((brect_t *)&rect);
    ovc13_blitAnimFrame();
    ovr_miceBlitRect((brect_t *)&rect);
  }
  return;
}
