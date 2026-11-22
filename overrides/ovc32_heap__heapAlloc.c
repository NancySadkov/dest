uint32_t * __cdecl16far heapAlloc(uint32_t *__return_storage_ptr__,uint32_t nbytes,...)

{
  long *plVar1;
  long *plVar2;
  uint16_t unaff_SI;
  uint16_t entry;
  long *unaff_DI;
  uint32_t in_stack_0000fff8;
  uint8_t in_stack_0000fffc;
  
  plVar2 = LXRSH_at_(unaff_DI,CONCAT22((int)((ulong)in_stack_0000fff8 >> 0x10),unaff_SI),
                     in_stack_0000fffc);
  entry = 0;
  while( true ) {
    entry = heapValidate(entry);
    if (entry == 0) {
      return (uint32_t *)0x0;
    }
    if (HeapPtr <= entry) break;
    plVar1 = (long *)*(uint *)0x0;
    if ((*(int *)((int)(uint32_t *)&_DATA + 2) == 0) && (plVar2 <= plVar1)) {
      *(uint16_t *)0x0 = (uint16_t)plVar2;   /* hand fix: 2-byte slot */
      *(uint16_t *)((int)(uint32_t *)&_DATA + 2) =
           *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4);
      if (plVar2 < plVar1) {
        *(int *)0x0 = (int)plVar1 - (int)plVar2;
        *(uint16_t *)((int)(uint32_t *)&_DATA + 2) = 0;
        *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4) = entry;
        heapFreeSub(entry + (int)plVar2);
      }
      return (uint32_t *)__C0_ASM_CopyRight;
    }
  }
  return (uint32_t *)0x0;
}
