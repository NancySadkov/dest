void __cdecl16far __EXITEMS(void)

{
  code *pcVar1;
  uint16_t uVar2;
  
  uVar2 = (uint)startx;   /* hand fix: startx is a function */
  if (((((char *)"Divide error\r\n")[9] & 4U) != 0) &&
     (*(int *)((char *)0x32) != -1)) {
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    ((char *)0x32)[0] = -1;
    ((char *)0x32)[1] = -1;
    ((char *)"Divide error\r\n")[9] = '\0';
  }
  return;
}
