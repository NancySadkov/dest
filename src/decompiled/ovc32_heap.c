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
  undefined2 in_DX;
  undefined2 uVar2;
  uint8_t *count;
  uint32_t *in_stack_00000004;
  
  for (; (srcSeg != 0 || (srcOfs != (uint8_t *)0x0)); srcOfs = srcOfs + -(int)count) {
    in_stack_00000004 = ovr_mkp();
    uVar2 = in_DX;
    puVar1 = ovr_mkp();
    if ((srcSeg != 0) || (count = srcOfs, (uint8_t *)0xff00 < srcOfs)) {
      count = (uint8_t *)0xff00;
    }
    _fmemmove((char *)CONCAT22(in_DX,in_stack_00000004),(char *)CONCAT22(uVar2,puVar1),(word)count);
    in_stack_00000004 = (uint32_t *)((int)in_stack_00000004 + (int)count);
    srcSeg = srcSeg - (srcOfs < count);
    in_DX = uVar2;
  }
  return;
}



/* 6316:00b1 */

void __cdecl16far heapInit(void...)

{
  byte *pbVar1;
  int in_DX;
  far_t *__return_storage_ptr__;
  uint32_t in_stack_0000fff8;
  
  pbVar1 = (byte *)coreleft((long *)(in_stack_0000fff8 >> 0x10));
  __return_storage_ptr__ = (far_t *)(in_DX - (uint)(pbVar1 < (byte *)__C0_ASM_CopyRight));
  farmalloc(__return_storage_ptr__,in_stack_0000fff8);
  HeapMin = (int)&__return_storage_ptr__->ofs + 1;
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
  uint8_t unaff_BP;
  long *unaff_SI;
  uint16_t entry;
  long in_stack_0000fffa;
  
  plVar2 = LXRSH_at_(unaff_SI,in_stack_0000fffa,unaff_BP);
  entry = 0;
  while( true ) {
    entry = heapValidate(entry);
    if (entry == 0) {
      return (uint32_t *)0x0;
    }
    if (HeapPtr <= entry) break;
    plVar1 = (long *)*(uint *)0x0;
    if ((*(int *)((int)(undefined4 *)&_DATA + 2) == 0) && (plVar2 <= plVar1)) {
      *(undefined2 *)0x0 = plVar2;
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
  long *unaff_SI;
  uint8_t *entry;
  uint unaff_DI;
  byte *in_stack_00000004;
  long in_stack_0000fff2;
  long i;
  uint8_t in_stack_0000fff6;
  byte s;
  
  ptr.seg = (uint16_t)__return_storage_ptr__;
  ptr.ofs = (uint16_t)in_stack_00000004;
  bVar2 = heapIsBadPtr(ptr);
  if (bVar2) {
    in_stack_00000004 = (byte *)0x0;
  }
  else {
    plVar3 = LXRSH_at_(unaff_SI,in_stack_0000fff2,in_stack_0000fff6);
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
        *(long **)((byte *)__C0_ASM_CopyRight + 4) = __return_storage_ptr__;
        *(undefined2 *)0x0 = plVar3;
        heapFreeSub((int)__return_storage_ptr__ + (int)plVar3);
      }
      else {
        iVar5 = *(int *)0x0;
        i = CONCAT22(plVar4,iVar5);
        if ((*(int *)((int)(undefined4 *)&_DATA + 2) == 0) &&
           (plVar3 <= (long *)((int)plVar4 + iVar5))) {
          *(undefined2 *)0x0 = plVar3;
          if (plVar3 < (long *)((int)plVar4 + iVar5)) {
            *(int *)0x0 = (int)plVar4 + (iVar5 - (int)plVar3);
            *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
            *(long **)((byte *)__C0_ASM_CopyRight + 4) = __return_storage_ptr__;
            heapFreeSub((int)__return_storage_ptr__ + (int)plVar3);
          }
          else {
            heapFreeSub((uint16_t)__return_storage_ptr__);
          }
        }
        else {
          entry = (uint8_t *)0x0;
          plVar4 = __return_storage_ptr__;
          do {
            entry = (uint8_t *)heapValidate((int)entry);
            s = (byte)plVar4;
            if (entry == (uint8_t *)0x0) {
              return (long *)0x0;
            }
            if (HeapPtr <= entry) {
              return (long *)0x0;
            }
            plVar1 = (long *)*(uint *)0x0;
          } while ((*(int *)((int)(undefined4 *)&_DATA + 2) != 0) || (plVar1 < plVar3));
          *(undefined2 *)0x0 = plVar3;
          *(undefined2 *)((int)(undefined4 *)&_DATA + 2) =
               *(undefined2 *)((byte *)__C0_ASM_CopyRight + 4);
          if (plVar3 < plVar1) {
            *(int *)0x0 = (int)plVar1 - (int)plVar3;
            *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
            *(uint8_t **)((byte *)__C0_ASM_CopyRight + 4) = entry;
            heapFreeSub((uint16_t)(entry + (int)plVar3));
          }
          else {
            heapFreeSub((uint16_t)entry);
          }
          iVar5 = 0;
          plVar4 = LXLSH_at_(unaff_SI,i,s);
          heapMemmove((uint8_t *)CONCAT22(in_stack_00000004,entry),(uint16_t)__return_storage_ptr__,
                      (uint8_t *)(plVar4 + -1),
                      iVar5 + -1 + (uint)((long *)((int)(undefined4 *)&_DATA + 3U) < plVar4),
                      unaff_DI,(int)unaff_SI,4);
          ptr_00.seg = unaff_DI;
          ptr_00.ofs = (uint16_t)__return_storage_ptr__;
          heapFree(ptr_00,in_stack_00000004);
          in_stack_00000004 = (byte *)__C0_ASM_CopyRight;
        }
      }
    }
  }
  return (long *)in_stack_00000004;
}



/* 6316:04ec */

far_t * __cdecl16far heapMalloc(far_t *__return_storage_ptr__,uint32_t nbytes,...)

{
  long *plVar1;
  long *plVar2;
  far_t *pfVar3;
  long *unaff_SI;
  uint16_t uVar4;
  uint16_t uVar5;
  uint16_t entry;
  long in_stack_0000fff4;
  uint8_t in_stack_0000fff8;
  
  plVar2 = LXRSH_at_(unaff_SI,in_stack_0000fff4,in_stack_0000fff8);
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
    entry = uVar5;
    uVar4 = *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4);
    if (plVar2 < plVar1) {
      *(int *)0x0 = (int)plVar1 - (int)plVar2;
      entry = (int)plVar1 + (uVar5 - (int)plVar2);
      uVar4 = uVar5;
    }
    *(undefined2 *)0x0 = plVar2;
    *(uint16_t *)((int)(undefined4 *)&_DATA + 2) = uVar4;
    heapFreeSub(entry);
    if (entry < HeapPtr) {
      HeapPtr = entry;
    }
    pfVar3 = (far_t *)__C0_ASM_CopyRight;
  }
  return pfVar3;
}



/* 6316:05aa */

void __cdecl16far heapValidateAll(void...)

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
  far_t ptr_00;
  bool bVar2;
  uint16_t in_DX;
  int iVar3;
  uint16_t in_stack_00000004;
  uint16_t uStack_4;
  
  ptr_00.seg = ptr.ofs;
  ptr_00.ofs = in_stack_00000004;
  bVar2 = heapIsBadPtr(ptr_00);
  if (!bVar2) {
    ovr_mkp();
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


