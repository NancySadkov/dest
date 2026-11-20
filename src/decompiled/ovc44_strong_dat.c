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
  uint32_t *puVar1;
  int in_stack_0000fffa;
  far_t *pfVar2;
  uint16_t uVar3;
  
  if (StshCount < 0xd93) {
    StshCount = StshCount + 1;
    pfVar2 = (far_t *)StshCtPtrCopy.ofs;
    uVar3 = StshCtPtrCopy.seg;
    puVar1 = ovr_mkp((uint32_t *)StshCtPtrCopy.seg,StshCtPtrCopy.ofs,StshCtPtrCopy.seg,
                     StshCtPtrCopy.ofs + 0x15);
    StshCtPtrCopy.seg = StshCtPtrCopy.ofs;
    *(undefined2 *)((int)&pfVar2[4].seg + 1) = 0;
    StshCtPtrCopy.ofs = (uint16_t)puVar1;
    *(undefined2 *)((int)&pfVar2[4].ofs + 1) = 0;
    *(undefined2 *)((int)&pfVar2[2].seg + 1) = 0;
    *(undefined2 *)((int)&pfVar2[2].ofs + 1) = 0;
    *(undefined2 *)((int)&pfVar2[3].seg + 1) = 0;
    *(undefined2 *)((int)&pfVar2[3].ofs + 1) = 0;
    return pfVar2;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(in_stack_0000fffa,0x24);
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
  int iVar1;
  undefined4 uVar2;
  int in_stack_00000004;
  
  iVar1 = in_stack_00000004;
  stshTR_S_stubify0(in_stack_00000004);
  uVar2 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[0].seg + iVar1 * 0xc) = (int)((ulong)uVar2 >> 0x10);
  ((far_t *)BldGfxRuin + iVar1 * 3)->ofs = (uint16_t)uVar2;
  uVar2 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[1].seg + iVar1 * 0xc) = (int)((ulong)uVar2 >> 0x10);
  ((far_t *)(BldGfxRuin + 1) + iVar1 * 3)->ofs = (uint16_t)uVar2;
  uVar2 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[2].seg + iVar1 * 0xc) = (int)((ulong)uVar2 >> 0x10);
  ((far_t *)(BldGfxRuin + 2) + iVar1 * 3)->ofs = (uint16_t)uVar2;
  uVar2 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[3].seg + iVar1 * 0xc) = (int)((ulong)uVar2 >> 0x10);
  ((far_t *)(BldGfxRuin + 3) + iVar1 * 3)->ofs = (uint16_t)uVar2;
  uVar2 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[4].seg + iVar1 * 0xc) = (int)((ulong)uVar2 >> 0x10);
  ((far_t *)(BldGfxRuin + 4) + iVar1 * 3)->ofs = (uint16_t)uVar2;
  uVar2 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[5].seg + iVar1 * 0xc) = (int)((ulong)uVar2 >> 0x10);
  ((far_t *)(BldGfxRuin + 5) + iVar1 * 3)->ofs = (uint16_t)uVar2;
  uVar2 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[6].seg + iVar1 * 0xc) = (int)((ulong)uVar2 >> 0x10);
  ((far_t *)(BldGfxRuin + 6) + iVar1 * 3)->ofs = (uint16_t)uVar2;
  uVar2 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[7].seg + iVar1 * 0xc) = (int)((ulong)uVar2 >> 0x10);
  ((far_t *)(BldGfxRuin + 7) + iVar1 * 3)->ofs = (uint16_t)uVar2;
  uVar2 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[8].seg + iVar1 * 0xc) = (int)((ulong)uVar2 >> 0x10);
  ((far_t *)(BldGfxRuin + 8) + iVar1 * 3)->ofs = (uint16_t)uVar2;
  return;
}



/* 6ffe:02f7 */
/* DECOMPILATION FAILED: Exception while decompiling 6ffe:02f7: process: timeout
 */
void init_assets(void) { /* failed */ }

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
  uint16_t uVar3;
  undefined2 unaff_BP;
  long *unaff_SI;
  uint uVar4;
  uint16_t uVar5;
  far_t fVar6;
  undefined2 in_stack_00000000;
  long *plVar7;
  uint16_t uVar8;
  long *__return_storage_ptr__;
  uint32_t *in_stack_0000fffa;
  uint32_t *in_stack_0000fffc;
  uint32_t *puVar2;
  
  uVar5 = StshCtPtr.seg;
  uVar3 = StshCtPtr.ofs;
  StshCtPtr2.seg = StshCtPtr.seg;
  StshCtPtr2.ofs = StshCtPtr.ofs;
  *(undefined2 *)(StshCtPtr.ofs + 0xf) = 0;
  *(undefined2 *)(uVar3 + 0xd) = 0;
  __return_storage_ptr__ =
       (long *)((char *)"%s casts %s on %s to heal %d hitpoint%s for a total of %d hitpoint%s." +
               0x13);
  fVar6.seg = (uint16_t)unaff_SI;
  fVar6.ofs = 0x6ffe;
  ptr_ofs_08.seg = (uint16_t)in_stack_0000fffc;
  ptr_ofs_08.ofs = (uint16_t)in_stack_0000fffa;
  fVar6 = PADD_at_(fVar6,ptr_ofs_08);
  puVar2 = (uint32_t *)fVar6.seg;
  puVar1 = ovr_mkp(puVar2,(uint16_t)__return_storage_ptr__,(uint16_t)unaff_SI,fVar6.ofs);
  uVar5 = StshCtPtr.seg;
  uVar3 = StshCtPtr.ofs;
  *(undefined2 *)(uVar3 + 0xb) = puVar2;
  *(undefined2 *)(uVar3 + 9) = puVar1;
  for (uVar4 = 1; uVar4 < StshCount - 1; uVar4 = uVar4 + 1) {
    LXMUL_at_(unaff_SI,(long)CONCAT22(in_stack_0000fffc,in_stack_0000fffa),
              CONCAT22(in_stack_00000000,unaff_BP));
    uVar8 = 0x1000;
    ptr_base_05.seg = (uint16_t)__return_storage_ptr__;
    ptr_base_05.ofs = 0x1000;
    ptr_ofs_06.seg = (uint16_t)in_stack_0000fffa;
    ptr_ofs_06.ofs = (uint16_t)unaff_SI;
    fVar6 = PADD_at_(ptr_base_05,ptr_ofs_06);
    in_stack_0000fffc = (uint32_t *)fVar6.seg;
    in_stack_0000fffa = ovr_mkp(in_stack_0000fffc,uVar8,(uint16_t)__return_storage_ptr__,fVar6.ofs);
    LXMUL_at_(__return_storage_ptr__,(long)CONCAT22(in_stack_0000fffa,unaff_SI),
              (long)CONCAT22(unaff_BP,in_stack_0000fffc));
    plVar7 = (long *)((int)&AgntAnms[0x38].halfWidth + 1);
    ptr_base_03.seg = uVar8;
    ptr_base_03.ofs = 0x1000;
    ptr_ofs_04.seg = (uint16_t)unaff_SI;
    ptr_ofs_04.ofs = (uint16_t)__return_storage_ptr__;
    PADD_at_(ptr_base_03,ptr_ofs_04);
    uVar5 = 0x1000;
    ptr_base_01.seg = (uint16_t)plVar7;
    ptr_base_01.ofs = 0x1000;
    ptr_ofs_02.seg = (uint16_t)__return_storage_ptr__;
    ptr_ofs_02.ofs = uVar8;
    fVar6 = PADD_at_(ptr_base_01,ptr_ofs_02);
    puVar2 = (uint32_t *)fVar6.seg;
    puVar1 = ovr_mkp(puVar2,uVar5,(uint16_t)plVar7,fVar6.ofs);
    *(undefined2 *)((int)in_stack_0000fffa + 0xb) = puVar2;
    *(undefined2 *)((int)in_stack_0000fffa + 9) = puVar1;
    LXMUL_at_(plVar7,CONCAT22(__return_storage_ptr__,uVar8),
              (long)CONCAT22(in_stack_0000fffa,unaff_SI));
    uVar3 = 0x1000;
    ptr_base.seg = uVar5;
    ptr_base.ofs = 0x1000;
    ptr_ofs_00.seg = uVar8;
    ptr_ofs_00.ofs = (uint16_t)plVar7;
    PADD_at_(ptr_base,ptr_ofs_00);
    __return_storage_ptr__ = (long *)((int)&AgntAnms[0x38].halfWidth + 1);
    ptr_base_07.seg = (uint16_t)unaff_SI;
    ptr_base_07.ofs = 0x1000;
    ptr_ofs.seg = (uint16_t)plVar7;
    ptr_ofs.ofs = uVar5;
    fVar6 = PADD_at_(ptr_base_07,ptr_ofs);
    puVar2 = (uint32_t *)fVar6.seg;
    puVar1 = ovr_mkp(puVar2,(uint16_t)__return_storage_ptr__,uVar3,fVar6.ofs);
    *(undefined2 *)((int)in_stack_0000fffa + 0xf) = puVar2;
    *(undefined2 *)((int)in_stack_0000fffa + 0xd) = puVar1;
  }
  LXMUL_at_(unaff_SI,(long)CONCAT22(in_stack_0000fffc,in_stack_0000fffa),
            CONCAT22(in_stack_00000000,unaff_BP));
  plVar7 = (long *)((int)&AgntAnms[0x38].halfWidth + 1);
  ptr_base_06.seg = (uint16_t)__return_storage_ptr__;
  ptr_base_06.ofs = 0x1000;
  ptr_ofs_07.seg = (uint16_t)in_stack_0000fffa;
  ptr_ofs_07.ofs = (uint16_t)unaff_SI;
  PADD_at_(ptr_base_06,ptr_ofs_07);
  uVar8 = 0x1000;
  ptr_base_04.seg = (uint16_t)plVar7;
  ptr_base_04.ofs = 0x1000;
  ptr_ofs_05.seg = (uint16_t)unaff_SI;
  ptr_ofs_05.ofs = (uint16_t)__return_storage_ptr__;
  fVar6 = PADD_at_(ptr_base_04,ptr_ofs_05);
  puVar2 = (uint32_t *)fVar6.seg;
  puVar1 = ovr_mkp(puVar2,uVar8,(uint16_t)plVar7,fVar6.ofs);
  Stsh_2410_47f6.seg = (uint16_t)puVar2;
  Stsh_2410_47f6.ofs = (uint16_t)puVar1;
  *(undefined2 *)((int)puVar1 + 0xb) = 0;
  *(undefined2 *)((int)puVar1 + 9) = 0;
  LXMUL_at_(plVar7,(long)CONCAT22(unaff_SI,__return_storage_ptr__),
            (long)CONCAT22(in_stack_0000fffc,in_stack_0000fffa));
  uVar5 = 0x1000;
  ptr_base_02.seg = uVar8;
  ptr_base_02.ofs = 0x1000;
  ptr_ofs_03.seg = (uint16_t)__return_storage_ptr__;
  ptr_ofs_03.ofs = (uint16_t)plVar7;
  PADD_at_(ptr_base_02,ptr_ofs_03);
  uVar3 = 0x1000;
  ptr_base_00.seg = uVar5;
  ptr_base_00.ofs = 0x1000;
  ptr_ofs_01.seg = (uint16_t)plVar7;
  ptr_ofs_01.ofs = uVar8;
  fVar6 = PADD_at_(ptr_base_00,ptr_ofs_01);
  puVar2 = (uint32_t *)fVar6.seg;
  puVar1 = ovr_mkp(puVar2,uVar3,uVar5,fVar6.ofs);
  uVar5 = Stsh_2410_47f6.seg;
  uVar3 = Stsh_2410_47f6.ofs;
  *(undefined2 *)(uVar3 + 0xf) = puVar2;
  *(undefined2 *)(uVar3 + 0xd) = puVar1;
  return;
}


