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
    if (*(int *)((char *)"Abnormal program termination\r\n" + 6) == 0 &&
        *(int *)((char *)"Abnormal program termination\r\n" + 8) == 0) {
      *(uint *)((char *)"Divide error\r\n" + 0xb) = baseLo;
      *(int *)((char *)"Divide error\r\n" + 0xd) = baseHi;
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
      *(int *)((char *)"Abnormal program termination\r\n" + 1) = iVar2;
      *(int *)((char *)"Abnormal program termination\r\n" + 3) = iVar3;
      return 0;
    }
    uVar4 = 0x400;
    uVar5 = (**(code **)((char *)"Abnormal program termination\r\n" + 6))(0x1000);
    if ((int)uVar5 != 0) {
      *(int *)((char *)"Abnormal program termination\r\n" + 10) = (int)((ulong)uVar5 >> 0x10);
      uVar5 = (**(code **)((char *)"Abnormal program termination\r\n" + 6))(0x1000);
      iVar3 = (int)((ulong)uVar5 >> 0x10);
      if ((int)uVar5 != 0) {
        *(uint *)((char *)"Divide error\r\n" + 0xb) = uVar4;
        *(int *)((char *)"Divide error\r\n" + 0xd) = iVar3;
        *(uint *)((char *)"Abnormal program termination\r\n" + 0xc) = uVar4;
        *(int *)((char *)"Abnormal program termination\r\n" + 0xe) = iVar3;
        iVar2 = uVar4 + sizeLo;
        iVar3 = iVar3 + sizeHi + (uint)CARRY2(uVar4,sizeLo);
        goto L__INITEXTMEM_113B;
      }
    }
  }
  return 0xffff;
}
