void __cdecl16far setSeasonPalette(far_t palette,...)

{
  uint uVar1;
  uint uVar2;
  undefined2 unaff_SS;
  uint8_t pal;
  int iStack_6;
  int iStack_4;
  
  iStack_4 = *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  iStack_6 = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
  uVar2 = 0;
  do {
    if (10 < uVar2) {
      return;
    }
    for (uVar1 = 0; uVar1 < 0x300; uVar1 = uVar1 + 1) {
      (&pal)[uVar1] =
           (uint8_t)(((long)(int)(uint)*(byte *)(palette.ofs + uVar1) * (long)(int)uVar2 & 0xffffU)
                    / 10);
    }
    ovr_vgaSetPalette8bit(&pal);
    do {
      if (*(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != iStack_4) break;
    } while (*(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */ == iStack_6);
    iStack_4 = *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    iStack_6 = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
    uVar2 = uVar2 + 1;
  } while( true );
}
