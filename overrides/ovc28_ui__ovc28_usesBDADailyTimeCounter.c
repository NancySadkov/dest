void __cdecl16far ovc28_usesBDADailyTimeCounter(int ticks,...)

{
  int iVar1;
  
  do {
    iVar1 = ticks + -1;
    if (ticks == 0) {
      return;
    }
    do {
      ticks = iVar1;
      if (*(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != *(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2)) break;
    } while (*(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */ == *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */);
  } while( true );
}
