int __cdecl16far __INITEMS(void)

{
  code *pcVar1;
  char cVar2;
  char extraout_AH;
  undefined2 uVar3;
  char extraout_AH_00;
  char extraout_AH_01;
  uint extraout_DX;
  int in_BX;
  undefined2 unaff_SI;
  int unaff_ES;
  bool bVar4;
  
  bVar4 = false;
  if ((((char *)"Divide error\r\n")[9] & 1U) == 0) {
    pcVar1 = (code *)swi(0x21);
    in_BX = (*pcVar1)();
    if (bVar4) goto L__INITEMS_0E2A;
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    if ((!bVar4) && (bVar4 = false, (extraout_DX & 0x80) != 0)) {
      pcVar1 = (code *)swi(0x21);
      cVar2 = (*pcVar1)();
      if (!bVar4) {
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)();
        if (cVar2 == -1) {
          pcVar1 = (code *)swi(0x21);
          (*pcVar1)();
          if (unaff_ES == 0 && in_BX == 0) goto L__INITEMS_0E2A;
          pcVar1 = (code *)swi(0x67);
          (*pcVar1)();
          if (extraout_AH != '\0') goto L__INITEMS_0E2A;
          ((char *)"Divide error\r\n")[9] = '\x01';
          pcVar1 = (code *)swi(0x67);
          uVar3 = (*pcVar1)();
          if (((char)((uint)uVar3 >> 8) != '\0') || ((byte)uVar3 < 0x32)) goto L__INITEMS_0E2A;
          ((char *)"Divide error\r\n")[10] = (byte)uVar3;
          pcVar1 = (code *)swi(0x67);
          (*pcVar1)();
          if (extraout_AH_00 != '\0') goto L__INITEMS_0E2A;
          *(int *)((char *)0x30) = in_BX;
          goto L__INITEMS_0E14;
        }
      }
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
  }
  else {
    unaff_SI = (uint)startx;   /* hand fix: startx is a function */
    if ((((char *)"Divide error\r\n")[9] & 2U) != 0) {
      return *(int *)((char *)0x36);
    }
L__INITEMS_0E14:
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    if (extraout_AH_01 == '\0') {
      *(int *)((char *)0x36) = in_BX;
      ((char *)0x32)[0] = -1;
      ((char *)0x32)[1] = -1;
      return in_BX;
    }
  }
L__INITEMS_0E2A:
  ((char *)"Divide error\r\n")[9] = '\0';
  return 0;
}
