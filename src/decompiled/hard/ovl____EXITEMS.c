void __cdecl16far __EXITEMS(void)

{
  code *pcVar1;
  undefined2 uVar2;
  
  uVar2 = (uint)startx;   /* hand fix: startx is a function */
  if (((((char *)"Divide error\r\n")[9] & 4U) != 0) &&
     (*(int *)((char *)"Divide error\r\n" + 3) != -1)) {
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    ((char *)"Divide error\r\n" + 3)[0] = -1;
    ((char *)"Divide error\r\n" + 3)[1] = -1;
    ((char *)"Divide error\r\n")[9] = '\0';
  }
  return;
}
