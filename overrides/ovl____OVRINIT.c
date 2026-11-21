undefined2 __stdcall16far __OVRINIT(void)

{
  code *pcVar1;
  uint in_AX;
  undefined2 uVar2;
  bool bVar3;
  uint in_stack_00000004;
  uint in_stack_00000006;
  int iStack_16;
  
  uVar2 = (uint)startx;   /* hand fix: startx is a function */
  bVar3 = false;
  if (*(int *)((int)&GUnitDescriptions[9].ofs + 1) == 0) {
    uVar2 = 0;
  }
  else {
    __OvrExeOpenEnv();
    if (bVar3) {
      bVar3 = false;
      in_AX = in_stack_00000004 | in_stack_00000006;
      __OvrExeOpenFilename();
      if ((bVar3) && (__OvrExeOpenEnvPath(), bVar3)) {
        return 0xfffe;
      }
    }
    bVar3 = false;
    *(uint *)((int)&GUnitDescriptions[0xf].ofs + 1) = in_AX;
    __OvrReadHeader();
    if ((!bVar3) && (iStack_16 == 0x5a4d)) {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)();
      __OvrReadHeader();
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    uVar2 = 0xffff;
  }
  return uVar2;
}
