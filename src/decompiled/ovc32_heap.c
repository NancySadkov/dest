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
    printf("Bad Pointer %lx \r",ptr.seg);
    ovr_biosReadKey();
    bVar1 = true;
  }
  return bVar1;
}



/* 6316:0039 */

void __cdecl16far
heapMemmove(uint8_t *param_1,uint16_t param_2,uint8_t *param_3,uint16_t param_4,uint param_5,
           int param_6)

{
  uint count;
  uint8_t *puVar1;
  uint8_t *puVar2;
  
  for (; (param_6 != 0 || (param_5 != 0)); param_5 = param_5 - count) {
    puVar1 = (uint8_t *)ovr_mkp((uint16_t)param_1,param_2);
    puVar2 = (uint8_t *)ovr_mkp((uint16_t)param_3,param_4);
    param_1 = (uint8_t *)puVar1;
    if ((param_6 != 0) || (count = param_5, 0xff00 < param_5)) {
      count = 0xff00;
    }
    _fmemmove(param_1,(uint8_t *)puVar2,count);
    param_2 = (uint16_t)((ulong)puVar1 >> 0x10);
    param_4 = (uint16_t)((ulong)puVar2 >> 0x10);
    param_1 = param_1 + count;
    param_3 = (uint8_t *)puVar2 + count;
    param_6 = param_6 - (uint)(param_5 < count);
  }
  return;
}



/* 6316:00b1 */

void __cdecl16far heapInit(void)

{
  long lVar1;
  far_t fVar2;
  
  lVar1 = coreleft();
  fVar2 = farmalloc(CONCAT22((int)((ulong)lVar1 >> 0x10) - (uint)((uint)lVar1 < 4),(uint)lVar1 - 4))
  ;
  HeapMin = fVar2.seg + 1;
  *(int *)0x0 = *(int *)0x0 + -1;
  *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
  *(uint16_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) = HeapMin;
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
      printf("Str %x %x  \r",entry);
      ovr_biosReadKey();
      printf("Bad heap @%x S%x Z%x P%x  \r",entry);
      ovr_biosReadKey();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 6316:01b9 */

void __cdecl16far heapFreeSub(uint16_t param_1)

{
  int iVar1;
  
  iVar1 = heapValidate(param_1);
  if (iVar1 != 0) {
    if (*(int *)((int)(undefined4 *)&_DATA + 2) == 0) {
      *(uint16_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) = param_1;
    }
    else {
      *(uint16_t *)((int)(undefined4 *)&_DATA + 2) = param_1;
    }
  }
  return;
}



/* 6316:01ed */

uint32_t __cdecl16far heapAlloc(uint32_t nbytes)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  long lVar5;
  
  lVar5 = LXRSH_at_(nbytes + 0x13,0x4);
  uVar2 = (uint)lVar5;
  uVar4 = 0;
  while( true ) {
    uVar4 = heapValidate(uVar4);
    if (uVar4 == 0) {
      uVar4 = 0;
      uVar3 = 0;
      goto ret;
    }
    if (HeapPtr <= uVar4) break;
    uVar1 = *(uint *)0x0;
    if ((*(int *)((int)(undefined4 *)&_DATA + 2) == 0) && (uVar2 <= uVar1)) {
      *(uint *)0x0 = uVar2;
      *(undefined2 *)((int)(undefined4 *)&_DATA + 2) =
           *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4);
      if (uVar2 < uVar1) {
        *(int *)0x0 = uVar1 - uVar2;
        *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
        *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) = uVar4;
        heapFreeSub(uVar4 + uVar2);
      }
      uVar3 = 4;
ret:
      return CONCAT22(uVar4,uVar3);
    }
  }
  uVar4 = 0;
  uVar3 = 0;
  goto ret;
}



/* 6316:02a4 */

long __cdecl16far heapRealloc(long block,long nbytes)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  
  bVar4 = heapIsBadPtr((far_t)block);
  if (bVar4) {
    block = 0;
  }
  else {
    lVar7 = LXRSH_at_(nbytes + 0x13,0x4);
    uVar5 = (uint)lVar7;
    uVar1 = *(uint *)0x0;
    if (uVar5 != uVar1) {
      if (uVar5 < uVar1) {
        if (*(int *)((int)(undefined4 *)&_DATA + 2) == 0) {
          *(int *)0x0 = (uVar1 - uVar5) + *(int *)0x0;
        }
        else {
          *(int *)0x0 = uVar1 - uVar5;
        }
        *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
        *(uint16_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) = block._2_2_;
        *(uint *)0x0 = uVar5;
        heapFreeSub(block._2_2_ + uVar5);
      }
      else {
        iVar2 = *(int *)0x0;
        if ((*(int *)((int)(undefined4 *)&_DATA + 2) == 0) && (uVar5 <= uVar1 + iVar2)) {
          *(uint *)0x0 = uVar5;
          if (uVar5 < uVar1 + iVar2) {
            *(int *)0x0 = (uVar1 + iVar2) - uVar5;
            *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
            *(uint16_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) = block._2_2_;
            heapFreeSub(block._2_2_ + uVar5);
          }
          else {
            heapFreeSub(block._2_2_);
          }
        }
        else {
          do {
            uVar6 = heapValidate();
            if (uVar6 == 0) {
              return 0;
            }
            if (HeapPtr <= uVar6) {
              return 0;
            }
            uVar3 = *(uint *)0x0;
          } while ((*(int *)((int)(undefined4 *)&_DATA + 2) != 0) || (uVar3 < uVar5));
          *(uint *)0x0 = uVar5;
          *(undefined2 *)((int)(undefined4 *)&_DATA + 2) =
               *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4);
          if (uVar5 < uVar3) {
            *(int *)0x0 = uVar3 - uVar5;
            *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
            *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) = uVar6;
            heapFreeSub(uVar6 + uVar5);
          }
          else {
            heapFreeSub(uVar6);
          }
          if (uVar1 < uVar5) {
            uVar5 = uVar1;
          }
          lVar7 = LXLSH_at_((ulong)uVar5,4);
          heapMemmove(4,uVar6,block,(int)(lVar7 + -4));
          heapFree((far_t)block);
          block = CONCAT22(uVar6,4);
        }
      }
    }
  }
  return block;
}



/* 6316:04ec */

far_t __cdecl16far heapMalloc(uint32_t nbytes)

{
  uint uVar1;
  uint16_t uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  far_t fVar7;
  uint uStack_c;
  
  lVar6 = LXRSH_at_(nbytes + 0x13,0x4);
  uVar1 = (uint)lVar6;
  uVar4 = 0;
  uVar5 = 0;
  while( true ) {
    uVar4 = heapValidate(uVar4);
    if (uVar4 == 0) break;
    if ((*(int *)((int)(undefined4 *)&_DATA + 2) == 0) && (uVar1 <= *(uint *)0x0)) {
      uVar5 = uVar4;
    }
  }
  if (uVar5 == 0) {
    uVar3 = 0;
    uVar2 = 0;
  }
  else {
    uVar4 = *(uint *)0x0;
    uVar3 = uVar5;
    uStack_c = *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4);
    if (uVar1 < uVar4) {
      *(int *)0x0 = uVar4 - uVar1;
      uVar3 = uVar5 + (uVar4 - uVar1);
      uStack_c = uVar5;
    }
    *(uint *)0x0 = uVar1;
    *(uint *)((int)(undefined4 *)&_DATA + 2) = uStack_c;
    heapFreeSub(uVar3);
    if (uVar3 < HeapPtr) {
      HeapPtr = uVar3;
    }
    uVar2 = 4;
  }
  fVar7.seg = uVar3;
  fVar7.ofs = uVar2;
  return fVar7;
}



/* 6316:05aa */

void __cdecl16far heapValidateAll(void)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    iVar1 = heapValidate(iVar1);
    if (iVar1 == 0) break;
    if (*(int *)((int)(undefined4 *)&_DATA + 2) == 0) {
      printf("@%x S%x Z%x P%x  \r",iVar1);
      ovr_biosReadKey();
    }
  }
  return;
}



/* 6316:0600 */

void __cdecl16far heapFree(far_t ptr)

{
  uint16_t uVar1;
  bool bVar2;
  uint16_t uVar3;
  int iVar4;
  uint32_t uVar5;
  uint16_t uStack_4;
  
  bVar2 = heapIsBadPtr(ptr);
  if (!bVar2) {
    uVar5 = ovr_mkp(ptr.ofs,ptr.seg);
    uVar3 = (uint16_t)(uVar5 >> 0x10);
    iVar4 = *(int *)0x0;
    uVar1 = *(uint16_t *)((int)(undefined4 *)&_DATA + 2);
    if (uVar1 == 0) {
      printf("%lx already free \r",ptr.ofs);
      ovr_biosReadKey();
    }
    else {
      if ((uVar3 + iVar4 < HeapMax) && (*(int *)((int)(undefined4 *)&_DATA + 2) == 0)) {
        iVar4 = iVar4 + *(int *)0x0;
      }
      uStack_4 = uVar1;
      if ((uVar1 != uVar3) && (*(int *)((int)(undefined4 *)&_DATA + 2) == 0)) {
        iVar4 = iVar4 + *(int *)0x0;
        uStack_4 = *(uint16_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4);
        uVar3 = uVar1;
      }
      *(uint16_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) = uStack_4;
      *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
      *(int *)0x0 = iVar4;
      heapFreeSub(uVar3);
    }
  }
  return;
}


