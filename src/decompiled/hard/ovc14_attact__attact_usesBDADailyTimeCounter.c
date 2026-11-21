ulong * __cdecl16far
attact_usesBDADailyTimeCounter(ulong *__return_storage_ptr__,ulong prevTick,...)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(BDA_DailyTimeCounter.ofs + 2);
  if (((uint)prevTick < uVar1) ||
     (((uint)prevTick == uVar1 && (__return_storage_ptr__ <= *(ulong **)BDA_DailyTimeCounter.ofs)))) {
    iVar2 = -(int)__return_storage_ptr__;
  }
  else {
    iVar2 = 0xb0 - (int)__return_storage_ptr__;
  }
  return (ulong *)((int)*(ulong **)BDA_DailyTimeCounter.ofs + iVar2);
}
