void __cdecl16far ovc40_usesVgaSetPalette8bit(far_t palette,...)

{
  int iVar1;
  int iVar2;
  uint16_t unaff_SS;
  uint8_t pal;
  int iStack_6;
  int iStack_4;
  
  iStack_4 = *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  iStack_6 = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
  iVar2 = 10;
  do {
    if (iVar2 < 0) {
      return;
    }
    for (iVar1 = 0; iVar1 < 0x300; iVar1 = iVar1 + 1) {
      (&pal)[iVar1] =
           (uint8_t)(((long)(int)(uint)*(byte *)(palette.ofs + iVar1) * (long)iVar2 & 0xffffU) / 10)
      ;
    }
    ovr_vgaSetPalette8bit(&pal);
    do {
      if (*(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != iStack_4) break;
    } while (*(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */ == iStack_6);
    iStack_4 = *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    iStack_6 = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
    iVar2 = iVar2 + -1;
  } while( true );
}
