void __cdecl16far ovc13_blitAnimFrame(void)

{
  far_t gfx;
  
  if (GMenuFlag == '\0') {
    blitFrameTickHi = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    blitFrameTickLo = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t far */;
    if (5 < BlitFrame) {
      BlitFrame = 0;
    }
    gfx.seg = ((undefined2 *)&blitFrameSeg)[(uint)BlitFrame * 2];
    gfx.ofs = ((undefined2 *)&blitFrameOfs)[(uint)BlitFrame * 2];
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000db93)));
    BlitFrame = BlitFrame + 1;
  }
  return;
}
