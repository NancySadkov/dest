/*
 * ovc32_heap.c - recovered from STRONG.EXE
 * memory block: OVC32_heap.c
 * range: 6316:0000 - 6316:06ff
 * functions: 10
 */
#include "recovered.h"


/* 6316:0000 */

bool __cdecl16far heapIsBadPtr(far_t ptr)

{
  bool bVar1;
  
  if (((ptr.ofs == 4) && (HeapMin <= ptr.seg)) && (ptr.seg < HeapMax)) {
    bVar1 = false;
  }
  else {
    ovr_biosReadKey();
    printf("Bad Pointer %lx \r");
    ovr_biosReadKey();
    bVar1 = true;
  }
  return bVar1;
}



/* 6316:0039 */

void __cdecl16far
heapMemmove(uint8_t *dstOfs,uint16_t dstSeg,uint8_t *srcOfs,uint16_t srcSeg,uint countLo,int countHi
           ,...)

{
  uint32_t *puVar1;
  uint32_t *puVar2;
  uint16_t in_DX;
  uint16_t uVar3;
  uint16_t uVar4;
  uint16_t unaff_SI;
  uint count;
  
  for (; (uVar3 = in_DX, countLo != 0 || (srcSeg != 0)); srcSeg = srcSeg - count) {
    puVar1 = ovr_mkp((uint32_t *)dstOfs,dstSeg,unaff_SI);
    uVar4 = uVar3;
    puVar2 = ovr_mkp((uint32_t *)srcOfs,(*(uint16_t *)((uint8_t *)&(srcOfs) + 2)),unaff_SI);
    if ((countLo != 0) || (count = srcSeg, 0xff00 < srcSeg)) {
      count = 0xff00;
    }
    in_DX = uVar4;
    _fmemmove((char *)CONCAT22(uVar3,puVar1),(char *)CONCAT22(uVar4,puVar2),count);
    dstOfs = (uint8_t *)((int)puVar1 + count);
    srcOfs = (uint8_t *)CONCAT22(uVar4,(uint8_t *)((int)puVar2 + count));
    countLo = countLo - (srcSeg < count);
    dstSeg = uVar3;
  }
  return;
}



/* 6316:00b1 */

void __cdecl16far heapInit(void)

{
  byte *pbVar1;
  int in_DX;
  undefined4 in_stack_0000fff6;
  long *__return_storage_ptr__;
  
  __return_storage_ptr__ = (long *)((ulong)in_stack_0000fff6 >> 0x10);
  pbVar1 = (byte *)coreleft(__return_storage_ptr__);
  in_DX = in_DX - (uint)(pbVar1 < (byte *)__C0_ASM_CopyRight);
  farmalloc((far_t *)(pbVar1 + -4),CONCAT22(__return_storage_ptr__,in_DX));
  HeapMin = in_DX + 1;
  *(int *)0x0 = *(int *)0x0 + -1;
  *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
  *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4) = HeapMin;
  HeapMax = HeapMin + *(int *)0x0;
  HeapPtr = HeapMin + *(int *)0x0;
  HeapReady = 1;
  return;
}



/* 6316:0121 */

uint16_t __cdecl16far heapValidate(int entry)

{
  uint16_t uVar1;
  
  uVar1 = HeapMin;
  if (entry != 0) {
    uVar1 = entry + *(int *)0x0;
    if (uVar1 == HeapMax) {
      uVar1 = 0;
    }
    else if ((uVar1 < HeapMin) || (HeapMax < uVar1)) {
      printf("Str %x %x  \r");
      ovr_biosReadKey();
      printf("Bad heap @%x S%x Z%x P%x  \r");
      ovr_biosReadKey();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 6316:01b9 */

void __cdecl16far heapFreeSub(uint16_t entry)

{
  uint16_t uVar1;
  
  uVar1 = heapValidate(entry);
  if (uVar1 != 0) {
    if (*(int *)((int)(undefined4 *)&_DATA + 2) == 0) {
      *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4) = entry;
    }
    else {
      *(uint16_t *)((int)(undefined4 *)&_DATA + 2) = entry;
    }
  }
  return;
}



/* 6316:01ed */
uint32_t * __cdecl16far heapAlloc(uint32_t *__return_storage_ptr__,uint32_t nbytes,...)

{
  long *plVar1;
  long *plVar2;
  undefined2 unaff_SI;
  uint16_t entry;
  long *unaff_DI;
  undefined4 in_stack_0000fff8;
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
    if ((*(int *)((int)(undefined4 *)&_DATA + 2) == 0) && (plVar2 <= plVar1)) {
      *(undefined2 *)0x0 = (uint16_t)plVar2;   /* hand fix: 2-byte slot */
      *(undefined2 *)((int)(undefined4 *)&_DATA + 2) =
           *(undefined2 *)((byte *)__C0_ASM_CopyRight + 4);
      if (plVar2 < plVar1) {
        *(int *)0x0 = (int)plVar1 - (int)plVar2;
        *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
        *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4) = entry;
        heapFreeSub(entry + (int)plVar2);
      }
      return (uint32_t *)__C0_ASM_CopyRight;
    }
  }
  return (uint32_t *)0x0;
}


/* 6316:02a4 */
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


/* 6316:04ec */
far_t * __cdecl16far heapMalloc(far_t *__return_storage_ptr__,uint32_t nbytes,...)

{
  long *plVar1;
  long *plVar2;
  far_t *pfVar3;
  undefined2 unaff_SI;
  uint16_t uVar4;
  long *unaff_DI;
  uint16_t uVar5;
  undefined4 in_stack_0000fff2;
  uint16_t uVar6;
  uint8_t in_stack_0000fff6;
  
  plVar2 = LXRSH_at_(unaff_DI,CONCAT22((int)((ulong)in_stack_0000fff2 >> 0x10),unaff_SI),
                     in_stack_0000fff6);
  uVar4 = 0;
  uVar5 = 0;
  while( true ) {
    uVar4 = heapValidate(uVar4);
    if (uVar4 == 0) break;
    if ((*(int *)((int)(undefined4 *)&_DATA + 2) == 0) && (plVar2 <= (long *)*(uint *)0x0)) {
      uVar5 = uVar4;
    }
  }
  if (uVar5 == 0) {
    pfVar3 = (far_t *)0x0;
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
    *(undefined2 *)0x0 = (uint16_t)plVar2;   /* hand fix: 2-byte slot */
    *(uint16_t *)((int)(undefined4 *)&_DATA + 2) = uVar6;
    heapFreeSub(uVar4);
    if (uVar4 < HeapPtr) {
      HeapPtr = uVar4;
    }
    pfVar3 = (far_t *)__C0_ASM_CopyRight;
  }
  return pfVar3;
}


/* 6316:05aa */

void __cdecl16far heapValidateAll(void)

{
  uint16_t entry;
  
  entry = 0;
  while( true ) {
    entry = heapValidate(entry);
    if (entry == 0) break;
    if (*(int *)((int)(undefined4 *)&_DATA + 2) == 0) {
      printf("@%x S%x Z%x P%x  \r");
      ovr_biosReadKey();
    }
  }
  return;
}



/* 6316:0600 */

void __cdecl16far heapFree(far_t ptr,...)

{
  uint16_t uVar1;
  bool bVar2;
  uint16_t in_DX;
  uint16_t unaff_DI;
  int iVar3;
  uint16_t uStack_4;
  
  bVar2 = heapIsBadPtr(ptr);
  if (!bVar2) {
    ovr_mkp((uint32_t *)ptr.ofs,ptr.seg,unaff_DI);
    iVar3 = *(int *)0x0;
    uVar1 = *(uint16_t *)((int)(undefined4 *)&_DATA + 2);
    if (uVar1 == 0) {
      printf("%lx already free \r");
      ovr_biosReadKey();
    }
    else {
      if ((in_DX + iVar3 < HeapMax) && (*(int *)((int)(undefined4 *)&_DATA + 2) == 0)) {
        iVar3 = iVar3 + *(int *)0x0;
      }
      uStack_4 = uVar1;
      if ((uVar1 != in_DX) && (*(int *)((int)(undefined4 *)&_DATA + 2) == 0)) {
        iVar3 = iVar3 + *(int *)0x0;
        uStack_4 = *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4);
        in_DX = uVar1;
      }
      *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4) = uStack_4;
      *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
      *(int *)0x0 = iVar3;
      heapFreeSub(in_DX);
    }
  }
  return;
}


