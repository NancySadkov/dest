void __cdecl16far __OVREXIT(void)

{
  uint16_t uVar1;
  uint16_t uVar2;
  
  uVar1 = (uint)startx;   /* hand fix: startx is a function */
  uVar2 = 0x2410;
  if (*(int *)((int)&GUnitDescriptions[0xf].ofs + 1) != 0) {
    __OvrResetInterruptVector();
  }
  (*(code *)*(uint16_t *)&__CALLEMSEXIT)(0x1000,uVar2);
  (*(code *)*(uint16_t *)&__CALLEXTEXIT)(0x1000);
  return;
}
