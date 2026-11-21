/*
 * ovc44_strong_dat.c - recovered from STRONG.EXE
 * memory block: OVC44_strong_dat
 * range: 6ffe:0000 - 6ffe:7ecf
 * functions: 5
 */
#include "recovered.h"


/* 6ffe:0000 */

far_t * __cdecl16far stshAllocStub(far_t *__return_storage_ptr__,...)

{
  uint16_t uVar1;
  uint16_t uVar2;
  uint32_t *puVar3;
  
  uVar2 = StshCtPtrCopy.seg;
  uVar1 = StshCtPtrCopy.ofs;
  if (StshCount < 0xd93) {
    StshCount = StshCount + 1;
    puVar3 = ovr_mkp((uint32_t *)(StshCtPtrCopy.ofs + 0x15),StshCtPtrCopy.seg,StshCtPtrCopy.ofs);
    StshCtPtrCopy.seg = StshCtPtrCopy.ofs;
    *(undefined2 *)(uVar1 + 0x13) = 0;
    StshCtPtrCopy.ofs = (uint16_t)puVar3;
    *(undefined2 *)(uVar1 + 0x11) = 0;
    *(undefined2 *)(uVar1 + 0xb) = 0;
    *(undefined2 *)(uVar1 + 9) = 0;
    *(undefined2 *)(uVar1 + 0xf) = 0;
    *(undefined2 *)(uVar1 + 0xd) = 0;
    return (far_t *)uVar1;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x24);
}



/* 6ffe:009b */

void __cdecl16far stshTR_S_stubify0(int index)

{
  undefined4 uVar1;
  
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[0].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)BldGfxNormal + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[1].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[2].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 2) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[3].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 3) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[4].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 4) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[5].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 5) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[6].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 6) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[7].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 7) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[8].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 8) + index * 3)->ofs = (uint16_t)uVar1;
  return;
}



/* 6ffe:01c5 */

void __cdecl16far stshStubifyBld(uint16_t index,...)

{
  undefined4 uVar1;
  
  stshTR_S_stubify0(index);
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[0].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)BldGfxRuin + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[1].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[2].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 2) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[3].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 3) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[4].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 4) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[5].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 5) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[6].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 6) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[7].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 7) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[8].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 8) + index * 3)->ofs = (uint16_t)uVar1;
  return;
}



/* 6ffe:02f7 */
/* DECOMPILATION FAILED: Exception while decompiling 6ffe:02f7: process: timeout
 */
undefined init_assets() { return 0; }

/* 6ffe:733c */
void __cdecl16far stshInitPtrs(void)

{
  far_t ptr_base;
  far_t ptr_base_00;
  far_t ptr_base_01;
  far_t ptr_ofs;
  far_t ptr_base_02;
  far_t ptr_base_03;
  far_t ptr_ofs_00;
  far_t ptr_base_04;
  far_t ptr_ofs_01;
  far_t ptr_base_05;
  far_t ptr_ofs_02;
  far_t ptr_base_06;
  far_t ptr_ofs_03;
  far_t ptr_ofs_04;
  far_t ptr_base_07;
  far_t ptr_ofs_05;
  far_t ptr_ofs_06;
  far_t ptr_ofs_07;
  far_t ptr_ofs_08;
  uint32_t *puVar1;
  uint16_t uVar2;
  undefined2 unaff_BP;
  uint16_t unaff_SI;
  uint uVar3;
  uint16_t uVar4;
  far_t fVar5;
  long *plVar6;
  uint16_t uVar7;
  long *__return_storage_ptr__;
  long *__return_storage_ptr___00;
  uint32_t *in_stack_0000fffa;
  uint16_t in_stack_0000fffc;
  
  uVar2 = StshCtPtr.seg;
  uVar7 = StshCtPtr.ofs;
  StshCtPtr2.seg = StshCtPtr.seg;
  StshCtPtr2.ofs = StshCtPtr.ofs;
  *(undefined2 *)(StshCtPtr.ofs + 0xf) = 0;
  *(undefined2 *)(uVar7 + 0xd) = 0;
  __return_storage_ptr___00 =
       (long *)((char *)"%s casts %s on %s to heal %d hitpoint%s for a total of %d hitpoint%s." +
               0x13);
  fVar5.seg = unaff_SI;
  fVar5.ofs = 0x6ffe;
  ptr_ofs_08.seg = in_stack_0000fffc;
  ptr_ofs_08.ofs = (uint16_t)in_stack_0000fffa;
  fVar5 = PADD_at_(fVar5,ptr_ofs_08);
  uVar7 = fVar5.seg;
  puVar1 = ovr_mkp((uint32_t *)fVar5.ofs,uVar7,(uint16_t)__return_storage_ptr___00);
  uVar4 = StshCtPtr.seg;
  uVar2 = StshCtPtr.ofs;
  *(uint16_t *)(uVar2 + 0xb) = uVar7;
  *(undefined2 *)(uVar2 + 9) = (uint16_t)puVar1;   /* hand fix: 2-byte half */
  for (uVar3 = 1; uVar3 < StshCount - 1; uVar3 = uVar3 + 1) {
    LXMUL_at_(__return_storage_ptr___00,CONCAT22(in_stack_0000fffa,unaff_SI),
              CONCAT22(unaff_BP,in_stack_0000fffc));
    __return_storage_ptr__ = (long *)((int)&AgntAnms[0x38].halfWidth + 1);
    ptr_base_05.seg = (uint16_t)__return_storage_ptr___00;
    ptr_base_05.ofs = 0x1000;
    ptr_ofs_06.seg = (uint16_t)in_stack_0000fffa;
    ptr_ofs_06.ofs = unaff_SI;
    fVar5 = PADD_at_(ptr_base_05,ptr_ofs_06);
    in_stack_0000fffc = fVar5.seg;
    in_stack_0000fffa =
         ovr_mkp((uint32_t *)fVar5.ofs,in_stack_0000fffc,(uint16_t)__return_storage_ptr__);
    LXMUL_at_(__return_storage_ptr__,(long)CONCAT22(unaff_SI,__return_storage_ptr___00),
              (long)CONCAT22(in_stack_0000fffc,in_stack_0000fffa));
    uVar2 = 0x1000;
    ptr_base_03.seg = (uint16_t)__return_storage_ptr__;
    ptr_base_03.ofs = 0x1000;
    ptr_ofs_04.seg = unaff_SI;
    ptr_ofs_04.ofs = (uint16_t)__return_storage_ptr___00;
    PADD_at_(ptr_base_03,ptr_ofs_04);
    plVar6 = (long *)((int)&AgntAnms[0x38].halfWidth + 1);
    ptr_base_01.seg = uVar2;
    ptr_base_01.ofs = 0x1000;
    ptr_ofs_02.seg = (uint16_t)__return_storage_ptr___00;
    ptr_ofs_02.ofs = (uint16_t)__return_storage_ptr__;
    fVar5 = PADD_at_(ptr_base_01,ptr_ofs_02);
    uVar7 = fVar5.seg;
    puVar1 = ovr_mkp((uint32_t *)fVar5.ofs,uVar7,(uint16_t)plVar6);
    *(uint16_t *)((int)in_stack_0000fffa + 0xb) = uVar7;
    *(undefined2 *)((int)in_stack_0000fffa + 9) = (uint16_t)puVar1;
    LXMUL_at_(plVar6,CONCAT22(__return_storage_ptr__,uVar2),
              (long)CONCAT22(unaff_SI,__return_storage_ptr___00));
    ptr_base.seg = (uint16_t)plVar6;
    ptr_base.ofs = 0x1000;
    ptr_ofs_00.seg = (uint16_t)__return_storage_ptr__;
    ptr_ofs_00.ofs = uVar2;
    PADD_at_(ptr_base,ptr_ofs_00);
    __return_storage_ptr___00 = (long *)((int)&AgntAnms[0x38].halfWidth + 1);
    ptr_base_07.seg = unaff_SI;
    ptr_base_07.ofs = 0x1000;
    ptr_ofs.seg = uVar2;
    ptr_ofs.ofs = (uint16_t)plVar6;
    fVar5 = PADD_at_(ptr_base_07,ptr_ofs);
    uVar7 = fVar5.seg;
    puVar1 = ovr_mkp((uint32_t *)fVar5.ofs,uVar7,(uint16_t)__return_storage_ptr___00);
    *(uint16_t *)((int)in_stack_0000fffa + 0xf) = uVar7;
    *(undefined2 *)((int)in_stack_0000fffa + 0xd) = (uint16_t)puVar1;
  }
  LXMUL_at_(__return_storage_ptr___00,CONCAT22(in_stack_0000fffa,unaff_SI),
            CONCAT22(unaff_BP,in_stack_0000fffc));
  uVar4 = 0x1000;
  ptr_base_06.seg = (uint16_t)__return_storage_ptr___00;
  ptr_base_06.ofs = 0x1000;
  ptr_ofs_07.seg = (uint16_t)in_stack_0000fffa;
  ptr_ofs_07.ofs = unaff_SI;
  PADD_at_(ptr_base_06,ptr_ofs_07);
  plVar6 = (long *)((int)&AgntAnms[0x38].halfWidth + 1);
  ptr_base_04.seg = uVar4;
  ptr_base_04.ofs = 0x1000;
  ptr_ofs_05.seg = unaff_SI;
  ptr_ofs_05.ofs = (uint16_t)__return_storage_ptr___00;
  fVar5 = PADD_at_(ptr_base_04,ptr_ofs_05);
  uVar7 = fVar5.seg;
  puVar1 = ovr_mkp((uint32_t *)fVar5.ofs,uVar7,(uint16_t)plVar6);
  Stsh_2410_47f6.seg = uVar7;
  Stsh_2410_47f6.ofs = (uint16_t)puVar1;
  *(undefined2 *)((int)puVar1 + 0xb) = 0;
  *(undefined2 *)((int)puVar1 + 9) = 0;
  LXMUL_at_(plVar6,CONCAT22(__return_storage_ptr___00,uVar4),CONCAT22(in_stack_0000fffa,unaff_SI));
  uVar7 = 0x1000;
  ptr_base_02.seg = (uint16_t)plVar6;
  ptr_base_02.ofs = 0x1000;
  ptr_ofs_03.seg = (uint16_t)__return_storage_ptr___00;
  ptr_ofs_03.ofs = uVar4;
  PADD_at_(ptr_base_02,ptr_ofs_03);
  uVar2 = 0x1000;
  ptr_base_00.seg = uVar7;
  ptr_base_00.ofs = 0x1000;
  ptr_ofs_01.seg = uVar4;
  ptr_ofs_01.ofs = (uint16_t)plVar6;
  fVar5 = PADD_at_(ptr_base_00,ptr_ofs_01);
  uVar7 = fVar5.seg;
  puVar1 = ovr_mkp((uint32_t *)fVar5.ofs,uVar7,uVar2);
  uVar4 = Stsh_2410_47f6.seg;
  uVar2 = Stsh_2410_47f6.ofs;
  *(uint16_t *)(uVar2 + 0xf) = uVar7;
  *(undefined2 *)(uVar2 + 0xd) = (uint16_t)puVar1;
  return;
}

