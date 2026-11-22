void __cdecl16near __OvrAllocEvict(void)

{
  uint16_t unaff_ES;
  
  __OvrTrapJmpsAndStack();
  if (*(int *)((byte *)__C0_ASM_CopyRight + 0x14) == 0x4c3) {
    (*(code **)&ram0x00024180)();
  }
  ((byte *)__C0_ASM_CopyRight + 0xc)[0] = 0;
  ((byte *)__C0_ASM_CopyRight + 0xc)[1] = 0;
  return;
}
