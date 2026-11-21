ulong * __cdecl16far
attact_usesBDADailyTimeCounter(ulong *__return_storage_ptr__,ulong prevTick,...)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  if (((uint)prevTick < uVar1) ||
     (((uint)prevTick == uVar1 && (__return_storage_ptr__ <= *(ulong * far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs))))) {
    iVar2 = -(int)__return_storage_ptr__;
  }
  else {
    iVar2 = 0xb0 - (int)__return_storage_ptr__;
  }
  return (ulong *)((int)*(ulong * far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) + iVar2);
}
