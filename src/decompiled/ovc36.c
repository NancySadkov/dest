/*
 * ovc36.c - recovered from STRONG.EXE
 * memory block: OVC36
 * range: 67d1:0000 - 67d1:015f
 * functions: 1
 */
#include "recovered.h"


/* 67d1:0000 */

uint __cdecl16far OVC36_67d1_0000(byte param_1)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  undefined2 uStack_4;
  
  if (*(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d) == 0) {
    uVar2 = (uint)(param_1 >> 6) << 8;
  }
  else {
    uVar4 = (ulong)*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d);
    lVar3 = LXMUL_at_(100,(ulong)*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4f));
    lVar3 = LDIV_at_(lVar3,uVar4);
    uVar2 = (uint)lVar3;
    if (200 < uVar2) {
      uVar2 = 200;
    }
    uVar4 = (ulong)*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d);
    lVar3 = LXMUL_at_(100,(ulong)*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5b));
    lVar3 = LDIV_at_(lVar3,uVar4);
    uStack_4 = (uint)lVar3;
    if (200 < uStack_4) {
      uStack_4 = 200;
    }
    uVar4 = (ulong)*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d);
    lVar3 = LXMUL_at_(100,(long)*(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x54));
    lVar3 = LDIV_at_(lVar3,uVar4);
    iVar1 = (int)lVar3;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    if (200 < iVar1) {
      iVar1 = 200;
    }
    uVar2 = (uVar2 + uStack_4 + iVar1) / 6;
  }
  return uVar2;
}


