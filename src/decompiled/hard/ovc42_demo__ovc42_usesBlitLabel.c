void __cdecl16far ovc42_usesBlitLabel(char *text,byte row,...)

{
  stg_tmp_t *psVar1;
  int16_t max_width;
  byte in_stack_00000008;
  far_t handle;
  
  BlitLetterType = 1;
  TextBlitY = (uint)in_stack_00000008 * 0xd + 0x9c;
  max_width = 9232;
  TextBlitX = 0xb;
  handle.seg = demfont1FontSeg;
  handle.ofs = demfont1FontOfs;
  psVar1 = ovr_stshLoadGfx(handle);
  ovr_blitLabel(text,(uint8_t *)CONCAT22(psVar1,row),max_width,0x3f);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
  BlitLetterType = 0;
  return;
}
