undefined2 __vprinter_func_start(void)

{
    char cVar2;   /* hand fix: it holds a character, not code */
  char *pcVar3;
  char *pcVar1;   /* hand fix: the bytes are read as chars */
  uint *puVar4;
  undefined1 *puVar5;
  int *piVar6;
  char cVar7;
  uint uVar8;
  byte bVar11;
  int iVar9;
  int iVar10;
  char alphaBase;
  char cVar13;
  int iVar12;
  int unaff_BP;
  char *pcVar14;
  char *pcVar15;
  char *pcVar16;
  int *piVar17;
  undefined1 *puVar18;
  uint *puVar19;
  int *piVar20;
  undefined2 uVar21;
  int iVar22;
  int unaff_SS;
  bool bVar23;
  
  *(int *)(unaff_BP + -4) = unaff_BP + -0x96;
L__vprinter_func_start_0EF9:
  pcVar16 = (char *)*(undefined2 *)(unaff_BP + -4);
L__vprinter_func_start_0EFC:
  uVar21 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
  pcVar14 = (char *)(char *)*(undefined4 *)(unaff_BP + 6);
L__vprinter_func_start_0EFF:
  pcVar15 = pcVar14 + 1;
  cVar7 = *pcVar14;
  if (cVar7 == '\0') goto L__vprinter_func_start_12FA;
  if (cVar7 == '%') {
    *(int *)(unaff_BP + -0x10) = (int)pcVar15;
    pcVar3 = pcVar15;
    pcVar15 = pcVar14 + 2;
    cVar7 = *pcVar3;
    if (cVar7 != '%') goto code_r0x00010f23;
  }
  *pcVar16 = cVar7;
  pcVar16 = pcVar16 + 1;
  pcVar1 = (char *)init_textFilename + unaff_BP;
  cVar2 = *pcVar1;
  *pcVar1 = (unsigned short)((char)*pcVar1 + -1);
  pcVar14 = pcVar15;
  if (*pcVar1 == (unsigned short)0x0 || SBORROW1((char)cVar2,'\x01') != (char)*pcVar1 < '\0') {
    __vprinter_1000_0ebc();
  }
  goto L__vprinter_func_start_0EFF;
code_r0x00010f23:
  *(undefined2 *)(unaff_BP + -4) = (uint16_t)pcVar16;   /* hand fix: 2-byte slot */
  uVar8 = 0;
  *(undefined2 *)(unaff_BP + -0xe) = (uint16_t)0;   /* hand fix: 2-byte slot */
  *(undefined2 *)(unaff_BP + -2) = (uint16_t)0x20;   /* hand fix: 2-byte slot */
  *(undefined1 *)(unaff_BP + -0xb) = 0;
  *(undefined2 *)(unaff_BP + -8) = (uint16_t)0xffff;   /* hand fix: 2-byte slot */
  *(undefined2 *)(unaff_BP + -10) = (uint16_t)0xffff;   /* hand fix: 2-byte slot */
  do {
    if (0x5f < (byte)(cVar7 - 0x20U)) goto switchD_1000_0f5d_caseD_13;
    alphaBase = ((uint8_t *)vprinter_printCtype)[(byte)(cVar7 - 0x20U)] * '\x02';
    bVar11 = (byte)(uVar8 >> 8);
    iVar22 = unaff_SS;
    switch(((uint8_t *)vprinter_printCtype)[(byte)(cVar7 - 0x20U)]) {
    case '\0':
      if (bVar11 != 0) goto switchD_1000_0f5d_caseD_13;
      if (*(char *)(unaff_BP + -0xb) != '+') {
        *(char *)(unaff_BP + -0xb) = cVar7;
      }
      break;
    case '\x01':
      if (bVar11 != 0) goto switchD_1000_0f5d_caseD_13;
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 1;
      break;
    case '\x02':
      iVar22 = *(int *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
      if (bVar11 < 2) {
        if (iVar22 < 0) {
          iVar22 = -iVar22;
          *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 2;
        }
        *(int *)(unaff_BP + -8) = iVar22;
        uVar8 = 0x300;
      }
      else {
        if (bVar11 != 4) goto switchD_1000_0f5d_caseD_13;
        *(int *)(unaff_BP + -10) = iVar22;
        uVar8 = 0x500;
      }
      break;
    case '\x03':
      if (bVar11 != 0) goto switchD_1000_0f5d_caseD_13;
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 2;
      break;
    case '\x04':
      if (3 < bVar11) goto switchD_1000_0f5d_caseD_13;
      uVar8 = 0x400;
      *(int *)(unaff_BP + -10) = *(int *)(unaff_BP + -10) + 1;
      break;
    case '\x05':
switchD_1000_0f5d_caseD_5:
      if (bVar11 < 3) {
        uVar8 = 0x200;
        LOCK();
        iVar22 = *(int *)(unaff_BP + -8);
        *(int *)(unaff_BP + -8) = (int)(char)(cVar7 + -0x30);
        UNLOCK();
        if (-1 < iVar22) {
          *(int *)(unaff_BP + -8) = *(int *)(unaff_BP + -8) + iVar22 * 10;
        }
      }
      else {
        if (bVar11 != 4) {
switchD_1000_0f5d_caseD_13:
          pcVar16 = (char *)*(undefined2 *)(unaff_BP + -0x10);
          uVar21 = *(undefined2 *)(unaff_BP + 8);
          do {
            __vprinter_1000_0eb3();
            pcVar3 = pcVar16;
            pcVar16 = pcVar16 + 1;
          } while (*pcVar3 != '\0');
L__vprinter_func_start_12FA:
          if ((char)((char *)init_textFilename)[unaff_BP] < 'P') {
            __vprinter_1000_0ebc();
          }
          if (*(int *)(unaff_BP + -0x16) == 0) {
            uVar21 = *(undefined2 *)(unaff_BP + -0x12);
          }
          else {
            uVar21 = 0xffff;
          }
          return uVar21;
        }
        LOCK();
        iVar22 = *(int *)(unaff_BP + -10);
        *(int *)(unaff_BP + -10) = (int)(char)(cVar7 + -0x30);
        UNLOCK();
        if (iVar22 != 0) {
          *(int *)(unaff_BP + -10) = *(int *)(unaff_BP + -10) + iVar22 * 10;
        }
      }
      break;
    case '\x06':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x10;
      goto L__vprinter_func_start_0F95;
    case '\a':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x100;
    case '\b':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) & 0xffef;
      goto L__vprinter_func_start_0F95;
    case '\t':
      if (bVar11 != 0) goto switchD_1000_0f5d_caseD_5;
      if ((*(uint *)(unaff_BP + -2) & 2) == 0) {
        *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 8;
        uVar8 = 0x100;
      }
      break;
    case '\n':
      goto switchD_1000_0f5d_caseD_a;
    case '\v':
      cVar13 = '\b';
      goto L__vprinter_func_start_104A;
    case '\f':
      cVar13 = '\n';
      goto L__vprinter_func_start_104E;
    case '\r':
      alphaBase = cVar7 + -0x17;
      cVar13 = '\x10';
L__vprinter_func_start_104A:
      *(undefined1 *)(unaff_BP + -0xb) = 0;
L__vprinter_func_start_104E:
      *(char *)(unaff_BP + -5) = cVar7;
      iVar9 = 0;
      *(undefined1 *)(unaff_BP + -6) = 0;
      piVar20 = (int *)*(undefined2 *)(unaff_BP + 4);
      iVar12 = *piVar20;
      goto L__vprinter_func_start_106E;
    case '\x0e':
      *(char *)(unaff_BP + -5) = cVar7;
      *(undefined2 *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
      puVar18 = (undefined1 *)(unaff_BP + -0x46);
      iVar12 = *(int *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = iVar12 + 2;
      if ((*(uint *)(unaff_BP + -2) & 0x20) != 0) {
        *(int *)(unaff_BP + 4) = iVar12 + 4;
        __vprinter_1000_0e74();
        puVar5 = puVar18;
        puVar18 = (undefined1 *)(unaff_BP + -0x45);
        *puVar5 = 0x3a;
      }
      __vprinter_1000_0e74();
      *puVar18 = 0;
      *(undefined1 *)(unaff_BP + -6) = 0;
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) & 0xfffb;
      puVar19 = (uint *)(unaff_BP + -0x46);
      uVar8 = (int)puVar18 - (int)puVar19;
      goto L__vprinter_func_start_11AA;
    case '\x0f':
      *(undefined2 *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
      *(char *)(unaff_BP + -5) = cVar7;
      uVar8 = *(uint *)(unaff_BP + -10);
      if ((int)uVar8 < 0) {
        uVar8 = 6;
      }
      if ((*(uint *)(unaff_BP + -2) & 0x100) == 0) {
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 8;
      }
      else {
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 10;
      }
      ovr__FakRealCvt();
      puVar19 = (uint *)(unaff_BP + -0x45);
      goto L__vprinter_func_start_11AA;
    case '\x10':
      *(undefined2 *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
      *(char *)(unaff_BP + -5) = cVar7;
      uVar8 = *(uint *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
      puVar19 = (uint *)(unaff_BP + -0x45);
      *puVar19 = uVar8 & 0xff;
      uVar8 = 1;
      goto L__vprinter_func_start_11ED;
    case '\x11':
      *(undefined2 *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
      *(char *)(unaff_BP + -5) = cVar7;
      if ((*(uint *)(unaff_BP + -2) & 0x20) == 0) {
        puVar19 = *(uint **)(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
        iVar22 = 0x2410;
        bVar23 = puVar19 == (uint *)0x0;
      }
      else {
        puVar4 = (uint *)*(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        iVar22 = (int)((ulong)puVar4 >> 0x10);
        puVar19 = (uint *)puVar4;
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 4;
        bVar23 = iVar22 == 0 && puVar19 == (uint *)0x0;
      }
      if (bVar23) {
        iVar22 = 0x2410;
        puVar19 = (uint *)"(null)";
      }
      __vprinter_1000_0ea6();
      if (*(uint *)(unaff_BP + -10) < uVar8) {
        uVar8 = *(uint *)(unaff_BP + -10);
      }
      goto L__vprinter_func_start_11ED;
    case '\x12':
      *(undefined2 *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
      if ((*(uint *)(unaff_BP + -2) & 0x20) == 0) {
        piVar20 = *(int **)(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
        uVar21 = 0x2410;
      }
      else {
        piVar6 = (int *)*(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        uVar21 = (undefined2)((ulong)piVar6 >> 0x10);
        piVar20 = (int *)piVar6;
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 4;
      }
      *piVar20 = (uint)(byte)(0x50 - (char)((char *)init_textFilename)[unaff_BP]) +
                 *(int *)(unaff_BP + -0x12);
      if ((*(uint *)(unaff_BP + -2) & 0x10) != 0) {
        piVar20[1] = 0;
      }
      goto L__vprinter_func_start_0EF9;
    default:
      goto switchD_1000_0f5d_caseD_13;
    case '\x16':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) & 0xffdf;
      goto L__vprinter_func_start_0F95;
    case '\x17':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x20;
L__vprinter_func_start_0F95:
      uVar8 = 0x500;
    }
    pcVar3 = pcVar15;
    pcVar15 = pcVar15 + 1;
    cVar7 = *pcVar3;
  } while( true );
switchD_1000_0f5d_caseD_a:
  cVar13 = '\n';
  *(undefined1 *)(unaff_BP + -6) = 1;
  *(char *)(unaff_BP + -5) = cVar7;
  piVar20 = (int *)*(undefined2 *)(unaff_BP + 4);
  iVar12 = *piVar20;
  iVar9 = iVar12 >> 0xf;
L__vprinter_func_start_106E:
  piVar17 = piVar20 + 1;
  *(undefined2 *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
  if ((*(uint *)(unaff_BP + -2) & 0x10) != 0) {
    iVar9 = *piVar17;
    piVar17 = piVar20 + 2;
  }
  *(undefined2 *)(unaff_BP + 4) = (uint16_t)piVar17;   /* hand fix: 2-byte slot */
  puVar19 = (uint *)(unaff_BP + -0x45);
  if ((iVar12 == 0) && (iVar9 == 0)) {
    if (*(int *)(unaff_BP + -10) == 0) goto L__vprinter_func_start_0EF9;
  }
  else {
    *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 4;
  }
  __LONGTOA(alphaBase,*(char *)(unaff_BP + -6),(int)cVar13,(char *)CONCAT22(unaff_SS,puVar19),
            CONCAT22(iVar9,iVar12));
  iVar12 = *(int *)(unaff_BP + -10);
  if (iVar12 < 0) {
L__vprinter_func_start_11AA:
    if (((*(uint *)(unaff_BP + -2) & 8) != 0) && (iVar12 = *(int *)(unaff_BP + -8), 0 < iVar12))
    goto L__vprinter_func_start_11B8;
  }
  else {
L__vprinter_func_start_11B8:
    __vprinter_1000_0ea6();
    if ((char)*puVar19 == '-') {
      uVar8 = uVar8 - 1;
    }
    if (iVar12 - uVar8 != 0 && (int)uVar8 <= iVar12) {
      *(int *)(unaff_BP + -0xe) = iVar12 - uVar8;
    }
  }
  if ((char)*puVar19 != '-') {
    if (*(char *)(unaff_BP + -0xb) == '\0') goto L__vprinter_func_start_11EA;
    puVar19 = (uint *)((int)puVar19 + -1);
    *(char *)puVar19 = *(char *)(unaff_BP + -0xb);
  }
  if ((0 < *(int *)(unaff_BP + -0xe)) && (uVar8 = *(uint *)(unaff_BP + -10), (int)uVar8 < 0)) {
    *(int *)(unaff_BP + -0xe) = *(int *)(unaff_BP + -0xe) + -1;
  }
L__vprinter_func_start_11EA:
  __vprinter_1000_0ea6();
L__vprinter_func_start_11ED:
  pcVar16 = (char *)*(undefined2 *)(unaff_BP + -4);
  iVar12 = *(int *)(unaff_BP + -8);
  if ((*(uint *)(unaff_BP + -2) & 5) == 5) {
    cVar7 = *(char *)(unaff_BP + -5);
    if (cVar7 == 'o') {
      if (*(int *)(unaff_BP + -0xe) < 1) {
        *(undefined2 *)(unaff_BP + -0xe) = (uint16_t)1;   /* hand fix: 2-byte slot */
      }
    }
    else if ((cVar7 == 'x') || (cVar7 == 'X')) {
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x40;
      iVar12 = iVar12 + -2;
      piVar6 = (int *)(unaff_BP + -0xe);
      iVar9 = *piVar6;
      *piVar6 = *piVar6 + -2;
      if (SBORROW2(iVar9,2) != *piVar6 < 0) {
        *(undefined2 *)(unaff_BP + -0xe) = (uint16_t)0;   /* hand fix: 2-byte slot */
      }
    }
  }
  iVar9 = uVar8 + *(int *)(unaff_BP + -0xe);
  if ((*(uint *)(unaff_BP + -2) & 2) == 0) {
    for (; iVar9 < iVar12; iVar12 = iVar12 + -1) {
      __vprinter_1000_0eb3();
    }
  }
  if ((*(uint *)(unaff_BP + -2) & 0x40) != 0) {
    __vprinter_1000_0eb3();
    __vprinter_1000_0eb3();
  }
  iVar10 = *(int *)(unaff_BP + -0xe);
  if (0 < iVar10) {
    iVar9 = iVar9 - iVar10;
    iVar12 = iVar12 - iVar10;
    cVar7 = (char)*puVar19;
    if (((cVar7 == '-') || (cVar7 == ' ')) || (cVar7 == '+')) {
      puVar19 = (uint *)((int)puVar19 + 1);
      __vprinter_1000_0eb3();
      iVar9 = iVar9 + -1;
      iVar12 = iVar12 + -1;
    }
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      __vprinter_1000_0eb3();
    }
  }
  if (iVar9 != 0) {
    iVar12 = iVar12 - iVar9;
    do {
      puVar4 = puVar19;
      puVar19 = (uint *)((int)puVar19 + 1);
      *pcVar16 = (char)*puVar4;
      pcVar16 = pcVar16 + 1;
      pcVar1 = (char *)init_textFilename + unaff_BP;
      cVar2 = *pcVar1;
      *pcVar1 = (unsigned short)((char)*pcVar1 + -1);
      if (*pcVar1 == (unsigned short)0x0 || SBORROW1((char)cVar2,'\x01') != (char)*pcVar1 < '\0') {
        __vprinter_1000_0ebc();
      }
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  if (0 < iVar12) {
    do {
      __vprinter_1000_0eb3();
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  goto L__vprinter_func_start_0EFC;
}
