undefined2 __stdcall16far __INITEXTMEM(uint sizeLo,int sizeHi,uint baseLo,int baseHi)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar1 = (uint)startx;   /* hand fix: startx is a function */
  if ((((char *)"Abnormal program termination\r\n")[5] & 1U) != 0) {
    if ((((char *)"Abnormal program termination\r\n")[5] & 2U) != 0) {
      return 0;
    }
    ((char *)"Abnormal program termination\r\n")[5] =
         ((char *)"Abnormal program termination\r\n")[5] | 2;
    if (*(int *)((char *)0x43) == 0 &&
        *(int *)((char *)0x45) == 0) {
      *(uint *)((char *)0x3a) = baseLo;
      *(int *)((char *)0x3c) = baseHi;
      _BootHandlerCode = uRam00000064;
      Int19Seg = uRam00000066;
      uRam00000064 = 0x3f;
      uRam00000066 = 0x2272;
      vdiskBaseOfs = baseLo;
      vdiskBaseHi = (undefined1)baseHi;
      iVar2 = baseLo + sizeLo;
      iVar3 = baseHi + sizeHi + (uint)CARRY2(baseLo,sizeLo);
      vdiskEndHi = (undefined1)iVar3;
      vdiskEndOfs = iVar2;
L__INITEXTMEM_113B:
      *(int *)((char *)0x3e) = iVar2;
      *(int *)((char *)0x40) = iVar3;
      return 0;
    }
    uVar4 = 0x400;
    uVar5 = (**(code **)((char *)0x43))(0x1000);
    if ((int)uVar5 != 0) {
      *(int *)((char *)0x47) = (int)((ulong)uVar5 >> 0x10);
      uVar5 = (**(code **)((char *)0x43))(0x1000);
      iVar3 = (int)((ulong)uVar5 >> 0x10);
      if ((int)uVar5 != 0) {
        *(uint *)((char *)0x3a) = uVar4;
        *(int *)((char *)0x3c) = iVar3;
        *(uint *)((char *)0x49) = uVar4;
        *(int *)((char *)0x4b) = iVar3;
        iVar2 = uVar4 + sizeLo;
        iVar3 = iVar3 + sizeHi + (uint)CARRY2(uVar4,sizeLo);
        goto L__INITEXTMEM_113B;
      }
    }
  }
  return 0xffff;
}
