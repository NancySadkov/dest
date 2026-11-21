void __cdecl16far __OVREXIT(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar1 = (uint)startx;   /* hand fix: startx is a function */
  uVar2 = 0x2410;
  if (*(int *)((int)&GUnitDescriptions[0xf].ofs + 1) != 0) {
    __OvrResetInterruptVector();
  }
  (*(code *)*(undefined2 *)&__CALLEMSEXIT)(0x1000,uVar2);
  (*(code *)*(undefined2 *)&__CALLEXTEXIT)(0x1000);
  return;
}
