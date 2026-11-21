undefined2 __cdecl16far ovc42_usesMiceBlitRect(byte timeoutTicks)

{
  bool bVar1;
  undefined1 extraout_AH;
  ulong *puVar2;
  undefined1 uVar3;
  uint16_t uVar4;
  ulong prevTick;
  
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
  rightButtonLatch = 0;
  if (MiceNeedsUpdate == '\0') {
    prevTick = 0;
  }
  else {
    ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x2410);
    prevTick = 0x1000000;
  }
  do {
    prevTick = prevTick & 0xffff0000;
    bVar1 = ovr_draw_textProvidesMoreHousing();
  } while (bVar1);
  while( true ) {
    uVar3 = (undefined1)(prevTick >> 0x18);
    uVar4 = *(uint16_t *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
    if ((*(uint16_t *)(BDA_DailyTimeCounter.ofs + 2) != InputEventTime.hi) ||
       (uVar4 != InputEventTime.lo)) {
      InputEventTime.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
      uVar4 = *(uint16_t *)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
      InputEventTime.lo = uVar4;
      ovr_draw_usesPrintf();
    }
    bVar1 = ovr_draw_textProvidesMoreHousing();
    puVar2 = (ulong *)CONCAT11(extraout_AH,bVar1);
    prevTick = (ulong)CONCAT11(uVar3,bVar1) << 0x10;
    if (bVar1) break;
    prevTick = CONCAT22(CONCAT11(uVar3,bVar1),(*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)));
    puVar2 = ovr_attact_usesBDADailyTimeCounter((ulong *)TextBlitCycle,prevTick);
    if ((uVar4 != 0) || ((ulong *)(uint)timeoutTicks <= puVar2)) break;
  }
  uVar3 = (undefined1)((uint)puVar2 >> 8);
  if ((char)(prevTick >> 0x18) != '\0') {
    prevTick = CONCAT22((int)(prevTick >> 0x10),0x2410);
    ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
  }
  return CONCAT11(uVar3,(char)(prevTick >> 0x10));
}
