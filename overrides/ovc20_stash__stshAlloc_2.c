long * __cdecl16far stshAlloc_2(long *__return_storage_ptr__,DW sz)

{
  far_t ptr_ofs;
  uint32_t *puVar1;
  uint16_t unaff_BP;
  bool bVar2;
  far_t fVar3;
  long in_stack_00000000;
  uint16_t uVar4;
  long *in_stack_0000fffa;
  uint16_t in_stack_0000fffc;
  
  if (StshCount < 0xd93) {
    StshCount = StshCount + 1;
    LXMUL_at_(in_stack_0000fffa,CONCAT22(unaff_BP,in_stack_0000fffc),in_stack_00000000);
    uVar4 = 0x1000;
    fVar3.seg = (uint16_t)in_stack_0000fffa;
    fVar3.ofs = 0x1000;
    ptr_ofs.seg = unaff_BP;
    ptr_ofs.ofs = in_stack_0000fffc;
    fVar3 = PADD_at_(fVar3,ptr_ofs);
    fVar3.seg = fVar3.seg;
    puVar1 = ovr_mkp((uint32_t *)fVar3.ofs,fVar3.seg,uVar4);
    *(uint16_t *)((int)puVar1 + 7) = sz.lo;
    *(undefined2 *)((int)puVar1 + 5) =(uint16_t)( __return_storage_ptr__);
    *(undefined1 *)CONCAT22(fVar3.seg,puVar1) = 0;
    uVar4 = StshCtOfs.lo;
    *(uint16_t *)((int)puVar1 + 3) = StshCtOfs.hi;
    *(uint16_t *)((int)puVar1 + 1) = uVar4;
    *(undefined2 *)((int)puVar1 + 0x13) = 0;
    *(undefined2 *)((int)puVar1 + 0x11) = 0;
    bVar2 = CARRY2(StshCtOfs.lo,(uint)__return_storage_ptr__);
    StshCtOfs.lo = StshCtOfs.lo + (int)__return_storage_ptr__;
    StshCtOfs.hi = StshCtOfs.hi + sz.lo + (uint)bVar2;
    *(undefined2 *)((int)puVar1 + 0xb) = 0;
    *(undefined2 *)((int)puVar1 + 9) = 0;
    *(undefined2 *)((int)puVar1 + 0xf) = 0;
    *(undefined2 *)((int)puVar1 + 0xd) = 0;
    return (long *)puVar1;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x24);
}
