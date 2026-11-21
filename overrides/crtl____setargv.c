void __setargv(uint savedES)

{
  char *pcVar1;
  char *pcVar2;
  byte bVar3;
  undefined1 *puVar4;
  uint uVar6;
  int iVar7;
  uint in_BX;
  int iVar8;
  int *piVar9;
  undefined2 unaff_SI;
  char *pcVar10;
  undefined2 unaff_DI;
  char *pcVar11;
  undefined2 uVar12;
  int unaff_SS;
  undefined2 uVar13;
  bool bVar14;
  undefined1 uVar15;
  undefined2 in_stack_00000000;
  uint in_stack_00000004;
  int iVar5;
  
  __setargv_SavedES = savedES;
  __setargv_SavedReturn2 = in_stack_00000004;
  __setargv_SavedDS = 0x2410;
  pcVar10 = (char *)(_env + 2);
  uVar6 = 1;
  uVar12 = _psp;
  __setargv_SavedReturn = in_stack_00000000;
  __setargv_SavedSI = unaff_SI;
  __setargv_SavedDI = unaff_DI;
  if (2 < DosVersion.major) {
    uVar6 = 0x7f;
    in_BX = in_BX & 0xff00;
    pcVar11 = pcVar10;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar1 = pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (*pcVar1 != '\0');
    if (uVar6 == 0) goto code_r0x000120eb;
    uVar6 = uVar6 ^ 0x7f;
    uVar12 = _envseg_at_;
  }
  in_stack_00000004 = in_BX;
  puVar4 = (undefined1 *)(uVar6 + *(byte *)((int)(int *)&errno + 1) + 2 & 0xfffe);
  iVar8 = -(int)puVar4;
  pcVar11 = (char *)((int)&stack0x0004 + iVar8);
  if (puVar4 <= &stack0x0004) {
    *(undefined2 *)((int)&savedES + iVar8) = uVar12;
    uVar13 = *(undefined2 *)((int)&savedES + iVar8);
    *(int *)((int)&savedES + iVar8) = unaff_SS;
    uVar12 = *(undefined2 *)((int)&savedES + iVar8);
    *(uint *)((int)&savedES + iVar8) = uVar6;
    while (uVar6 - 1 != 0) {
      pcVar2 = pcVar11;
      pcVar11 = pcVar11 + 1;
      pcVar1 = pcVar10;
      pcVar10 = pcVar10 + 1;
      *pcVar2 = *pcVar1;
      uVar6 = uVar6 - 1;
    }
    bVar14 = false;
    *pcVar11 = '\0';
    uVar15 = uVar6 == 0;
    iVar7 = 0;
Processing:
    *(char **)(&stack0x0000 + iVar8) = (char *)0x20a8;
    iVar5 = NextChar();
    bVar3 = (byte)iVar5;
    if (bVar14 || (bool)uVar15) {
      do {
        uVar12 = __setargv_SavedDS;
        if (bVar14) {
          pcVar10 = (char *)&stack0x0004;
          iVar7 = *(int *)((int)&savedES + iVar8) + iVar7;
          *(uint *)&_argc_at_ = uVar6;
          iVar8 = uVar6 + 1;
          piVar9 = (int *)(&stack0x0004 + iVar8 * -2);
          if (&stack0x0004 < (undefined1 *)(iVar8 * 4)) goto code_r0x000120eb;
          *(undefined2 *)&_argv_at_ = (uint16_t)piVar9;   /* hand fix: 2-byte slot */
          *(int *)&_argv_at__2 = unaff_SS;
          uVar12 = __setargv_SavedDS;
          goto SetArgvX;
        }
        *(char **)(&stack0x0000 + iVar8) = (char *)0x20af;
        iVar5 = NextChar();
        bVar3 = (byte)iVar5;
      } while (!bVar14 && !(bool)uVar15);
    }
    if ((bVar3 != 0x20) && (bVar3 != 0xd)) goto code_r0x000120b9;
    goto EndArgument;
  }
code_r0x000120eb:
                    /* WARNING: Subroutine does not return */
  _abort();
code_r0x000120b9:
  bVar14 = bVar3 < 9;
  uVar15 = false;
  if (bVar3 == 9) {
EndArgument:
    bVar14 = false;
    uVar15 = true;
  }
  goto Processing;
  while( true ) {
    *piVar9 = (int)pcVar10;
    piVar9[1] = unaff_SS;
    piVar9 = piVar9 + 2;
    do {
      pcVar1 = pcVar10;
      pcVar10 = pcVar10 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0 && *pcVar1 != '\0');
    if (*pcVar1 != '\0') break;
SetArgvX:
    if (iVar7 == 0) break;
  }
  *piVar9 = 0;
  piVar9[1] = 0;
  (&savedES)[iVar8 * -2] = *(undefined2 *)&__setargv_SavedReturn2;
  *(undefined2 *)(&stack0x0000 + iVar8 * -4) = *(undefined2 *)&__setargv_SavedES;
  *(undefined2 *)&__C0argc = *(undefined2 *)&_argc_at_;
  *(undefined2 *)&__C0argv_2 = *(undefined2 *)&_argv_at__2;
  *(undefined2 *)&__C0argv = *(undefined2 *)&_argv_at_;
                    /* WARNING: Could not recover jumptable at 0x00012153. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*(undefined2 *)&__setargv_SavedReturn)();
  return;
}
