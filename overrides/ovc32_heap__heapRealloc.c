long * __cdecl16far heapRealloc(long *__return_storage_ptr__,long block,long nbytes,...)

{
  long *plVar1;
  far_t ptr;
  far_t ptr_00;
  bool bVar2;
  long *plVar3;
  long *plVar4;
  int iVar5;
  undefined2 unaff_SI;
  uint16_t entry;
  long *unaff_DI;
  undefined4 in_stack_0000fff0;
  long lVar6;
  uint8_t in_stack_0000fff4;
  byte s;
  
  lVar6 = CONCAT22((int)((ulong)in_stack_0000fff0 >> 0x10),unaff_SI);
  ptr.seg = (uint16_t)block;
  ptr.ofs = (uint16_t)__return_storage_ptr__;
  bVar2 = heapIsBadPtr(ptr);
  if (bVar2) {
    __return_storage_ptr__ = (long *)0x0;
  }
  else {
    plVar3 = LXRSH_at_(unaff_DI,lVar6,in_stack_0000fff4);
    plVar4 = (long *)*(uint *)0x0;
    if (plVar3 != plVar4) {
      if (plVar3 < plVar4) {
        if (*(int *)((int)(undefined4 *)&_DATA + 2) == 0) {
          *(int *)0x0 = (int)plVar4 + (*(int *)0x0 - (int)plVar3);
        }
        else {
          *(int *)0x0 = (int)plVar4 - (int)plVar3;
        }
        *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
        *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4) = (uint16_t)block;
        *(undefined2 *)0x0 = (uint16_t)plVar3;   /* hand fix: 2-byte slot */
        heapFreeSub((uint16_t)block + (int)plVar3);
      }
      else {
        iVar5 = *(int *)0x0;
        lVar6 = CONCAT22(iVar5,(int)lVar6);
        if ((*(int *)((int)(undefined4 *)&_DATA + 2) == 0) &&
           (plVar3 <= (long *)((int)plVar4 + iVar5))) {
          *(undefined2 *)0x0 = (uint16_t)plVar3;   /* hand fix: 2-byte slot */
          if (plVar3 < (long *)((int)plVar4 + iVar5)) {
            *(int *)0x0 = (int)plVar4 + (iVar5 - (int)plVar3);
            *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
            *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4) = (uint16_t)block;
            heapFreeSub((uint16_t)block + (int)plVar3);
          }
          else {
            heapFreeSub((uint16_t)block);
          }
        }
        else {
          entry = 0;
          do {
            entry = heapValidate(entry);
            s = (byte)plVar4;
            if (entry == 0) {
              return (long *)0x0;
            }
            if (HeapPtr <= entry) {
              return (long *)0x0;
            }
            plVar1 = (long *)*(uint *)0x0;
          } while ((*(int *)((int)(undefined4 *)&_DATA + 2) != 0) || (plVar1 < plVar3));
          *(undefined2 *)0x0 = (uint16_t)plVar3;   /* hand fix: 2-byte slot */
          *(undefined2 *)((int)(undefined4 *)&_DATA + 2) =
               *(undefined2 *)((byte *)__C0_ASM_CopyRight + 4);
          if (plVar3 < plVar1) {
            *(int *)0x0 = (int)plVar1 - (int)plVar3;
            *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
            *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4) = entry;
            heapFreeSub(entry + (int)plVar3);
          }
          else {
            heapFreeSub(entry);
          }
          iVar5 = 0;
          plVar4 = LXLSH_at_(unaff_DI,lVar6,s);
          heapMemmove((byte *)__C0_ASM_CopyRight,entry,
                      (uint8_t *)CONCAT22((uint16_t)block,__return_storage_ptr__),
                      (uint16_t)(plVar4 + -1),
                      iVar5 + -1 + (uint)((long *)((int)(undefined4 *)&_DATA + 3U) < plVar4),
                      (int)unaff_DI);
          ptr_00.seg = (uint16_t)block;
          ptr_00.ofs = (uint16_t)__return_storage_ptr__;
          heapFree(ptr_00);
          __return_storage_ptr__ = (long *)__C0_ASM_CopyRight;
        }
      }
    }
  }
  return __return_storage_ptr__;
}
