void startx(void)

{
  char *pcVar1;
  uint32_t *puVar2;
  code *pcVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  uint16_t uVar9;
  uint16_t extraout_DX;
  uint16_t extraout_DX_00;
  int iVar10;
  undefined1 *puVar11;
  int *piVar12;
  char *pcVar13;
  char *pcVar14;
  undefined1 *puVar15;
  uint32_t *puVar16;
  uint16_t unaff_ES;
  uint16_t uVar17;
  bool bVar18;
  uint32_t uVar19;
  
  puVar11 = (undefined1 *)((int)(int *)&errno + 1);
  DGROUP_at__at_ = 0x2410;
  pcVar3 = (code *)swi(0x21);
  uVar19 = (*pcVar3)();
  uVar17 = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 40));
  iVar10 = (*(uint16_t *)((uint8_t *)&(_DATA) + 2));
  uVar9 = (uint16_t)((ulong)uVar19 >> 0x10);
  *(uint16_t *)&DosVersion = SUB42(uVar19,0);   /* hand fix: write the 2 bytes of the struct */
  *(uint16_t *)&_psp = unaff_ES;
  *(uint16_t *)(byte *)&_envseg_at_ = uVar17;
  *(int *)&_heaptop.seg = iVar10;
  *(uint16_t *)(puVar11 + -2) = 0x28;
  SaveVectors();
  pcVar4 = (char *)*(uint32_t *)&_env;
  uVar17 = (uint16_t)((ulong)pcVar4 >> 0x10);
  pcVar13 = (char *)pcVar4;
  uVar8 = 0x7fff;
  pcVar14 = pcVar13;
L_startx_0034:
  do {
    if (uVar8 != 0) {
      uVar8 = uVar8 - 1;
      pcVar1 = pcVar14;
      pcVar14 = pcVar14 + 1;
      if ((char)pcVar4 != *pcVar1) goto L_startx_0034;
    }
    if (uVar8 == 0) goto L_startx_007B;
    pcVar13 = pcVar13 + 1;
  } while (*pcVar14 != (char)pcVar4);
  *(int *)&_env = -(uVar8 | 0x8000);
  *(uint *)&_envSize_at_ = (int)pcVar13 * 4 + 0x10U & 0xfff0;
  if (__stklen < 0x200) {
    __stklen = 0x200;
  }
  bVar7 = 4;
  uVar8 = (__stklen >> 4) + 1;
  if (iVar10 + 0xd2a6U < uVar8) {
L_startx_007B:
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  iVar10 = (__stklen >> 4) + 0x2d5b;
  *(int *)&_heapbase.seg = iVar10;
  *(int *)&_brklvl.seg = iVar10;
  piVar12 = (int *)(puVar11 + -2);
  *(uint *)(puVar11 + -2) = uVar8;
  pcVar3 = (code *)swi(0x21);
  (*pcVar3)();
  uVar17 = DGROUP_at__at_;
  puVar15 = (undefined1 *)(*piVar12 << (bVar7 & 0x1f));
  puVar16 = (uint32_t *)&recordUpdateTick;
  __stklen = (uint16_t)puVar15;
  for (iVar10 = 0xb66; iVar10 != 0; iVar10 = iVar10 + -1) {
    puVar2 = puVar16;
    puVar16 = (uint32_t *)((int)puVar16 + 1);
    *(undefined1 *)puVar2 = 0;
  }
  if (0x14 < *(uint *)&_nfile) {
    bVar7 = ((dosver_t *)&DosVersion)->major;
    bVar18 = bVar7 < 3;
    if ((!bVar18) && ((3 < bVar7 || (bVar18 = *(byte *)&DosVersion.minor < 0x1e, !bVar18)))) {
      pcVar3 = (code *)swi(0x21);
      (*pcVar3)();
      if (!bVar18) {
        pcVar3 = (code *)swi(0x21);
        (*pcVar3)();
        if (!bVar18) {
          pcVar3 = (code *)swi(0x21);
          iVar6 = (*pcVar3)();
          if (!bVar18) {
            *(int *)&_heaptop.seg = iVar6 + 1;
            pcVar3 = (code *)swi(0x21);
            (*pcVar3)();
            if (!bVar18) {
              pcVar3 = (code *)swi(0x21);
              (*pcVar3)();
              if (!bVar18) goto L_startx_0109;
            }
          }
        }
      }
                    /* WARNING: Subroutine does not return */
      _abort();
    }
  }
L_startx_0109:
  pcVar3 = (code *)swi(0x1a);
  cVar5 = (*pcVar3)();
  *(uint16_t *)(uint32_t *)&_StartTime = extraout_DX_00;
  *(int *)((int)(uint32_t *)&_StartTime + 2) = iVar10;
  if (cVar5 != '\0') {
    bda_midnight = 1;
  }
  *(uint16_t *)(puVar15 + -2) = 0x135;
  StartExit();
  *(uint16_t *)(puVar15 + -2) = *(uint16_t *)&__C0environ_2;
  *(uint16_t *)(puVar15 + -4) = *(uint16_t *)&__C0environ;
  *(uint16_t *)(puVar15 + -6) = *(uint16_t *)&__C0argv_2;
  *(uint16_t *)(puVar15 + -8) = *(uint16_t *)&__C0argv;
  *(uint16_t *)(puVar15 + -10) = *(uint16_t *)&__C0argc;
  *(uint16_t *)(puVar15 + -0xc) = 0x1000;
  *(uint16_t *)(puVar15 + -0xe) = 0x14e;
  iVar10 = main(*(int *)(puVar15 + -0xc),*(str_t **)(puVar15 + -10),*(str_t **)(puVar15 + -8));
  *(int *)(puVar15 + -8) = iVar10;
  *(uint16_t *)(puVar15 + -10) = 0x1301;
                    /* WARNING: Subroutine does not return */
  *(uint16_t *)(puVar15 + -0xc) = 0x154;
  exit(*(int *)(puVar15 + -8));
}
