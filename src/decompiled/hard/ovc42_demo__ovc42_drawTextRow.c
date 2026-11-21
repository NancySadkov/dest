void __cdecl16far ovc42_drawTextRow(char *text,byte row)

{
  int16_t max_width;
  uint16_t unaff_SS;
  far_t gfx;
  far_t dst_00;
  far_t handle;
  uint8_t dst;
  stg_tmp_t *psStack_6;
  int16_t iStack_4;
  
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&dst;
  F_SCOPY(far_from_u32((uint32_t)(0x2410715b)),dst_00);
  if (row == 0) {
    gfx.seg = fullScreenGfxSeg;
    gfx.ofs = fullScreenGfxOfs;
    ovr_blitGfx10(gfx,0,0,(brect_t *)&dst,SUB21(unaff_SS,0));
  }
  TextBlitY = (uint)row * 0xd + 0x9e;
  max_width = 9232;
  TextBlitX = 0xb;
  handle.seg = demfont1FontSeg;
  handle.ofs = demfont1FontOfs;
  psStack_6 = ovr_stshLoadGfx(handle);
  TextBlitDstSeg = 0xa000;
  iStack_4 = max_width;
  ovr_blitLabel((char *)text,(uint8_t *)CONCAT22(psStack_6,(*(uint16_t *)((uint8_t *)&(text) + 2))),max_width,0x3f);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
  return;
}
