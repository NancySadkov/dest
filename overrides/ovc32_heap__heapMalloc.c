far_t * __cdecl16far heapMalloc(far_t *__return_storage_ptr__,uint32_t nbytes,...)

{
  long *plVar1;
  long *plVar2;
  far_t far *pfVar3;
  uint16_t unaff_SI;
  uint16_t uVar4;
  long *unaff_DI;
  uint16_t uVar5;
  uint32_t in_stack_0000fff2;
  uint16_t uVar6;
  uint8_t in_stack_0000fff6;
  
  plVar2 = LXRSH_at_(unaff_DI,CONCAT22((int)((ulong)in_stack_0000fff2 >> 0x10),unaff_SI),
                     in_stack_0000fff6);
  uVar4 = 0;
  uVar5 = 0;
  while( true ) {
    uVar4 = heapValidate(uVar4);
    if (uVar4 == 0) break;
    if ((*(int *)((int)(uint32_t *)&_DATA + 2) == 0) && (plVar2 <= (long *)*(uint *)0x0)) {
      uVar5 = uVar4;
    }
  }
  if (uVar5 == 0) {
    pfVar3 = (far_t far *)0x0;
  }
  else {
    plVar1 = (long *)*(uint *)0x0;
    uVar4 = uVar5;
    uVar6 = *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4);
    if (plVar2 < plVar1) {
      *(int *)0x0 = (int)plVar1 - (int)plVar2;
      uVar4 = (int)plVar1 + (uVar5 - (int)plVar2);
      uVar6 = uVar5;
    }
    *(uint16_t *)0x0 = (uint16_t)plVar2;   /* hand fix: 2-byte slot */
    *(uint16_t *)((int)(uint32_t *)&_DATA + 2) = uVar6;
    heapFreeSub(uVar4);
    if (uVar4 < HeapPtr) {
      HeapPtr = uVar4;
    }
    pfVar3 = (far_t far *)__C0_ASM_CopyRight;
  }
  return pfVar3;
}
