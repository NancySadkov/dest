int __cdecl16far __INITEXT(void)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  code *pcVar5;
  long lVar6;
  undefined2 uVar7;
  char cVar8;
  undefined2 uVar9;
  byte extraout_AH;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined2 in_BX;
  byte *pbVar13;
  byte *pbVar14;
  undefined2 unaff_SS;
  bool bVar15;
  undefined1 uVar16;
  undefined4 uVar17;
  uint8_t cmpBuf [8];
  uint uStack_17;
  uint uStack_f;
  
  uVar7 = (uint)startx;   /* hand fix: startx is a function */
  if ((((char *)"Abnormal program termination\r\n")[5] & 1U) == 0) {
    ((char *)"Abnormal program termination\r\n")[5] = '\x01';
L__INITEXT_0EEC:
    ((char *)0x3a)[0] = '\0';
    ((char *)0x3a)[1] = '\0';
    ((char *)0x3c)[0] = '\x10';
    ((char *)0x3c)[1] = '\0';
    ((char *)0x3e)[0] = '\0';
    ((char *)0x3e)[1] = '\0';
    ((char *)0x40)[0] = '\x10';
    ((char *)0x40)[1] = '\0';
    pcVar5 = (code *)swi(0x21);
    uVar9 = (*pcVar5)();
    if (((((byte)uVar9 < 10) && ((*(byte *)0xFFFE) < 0xfd)) && ((*(byte *)0xFFFE) != 0xfb)) &&
       ((*(byte *)0xFFFE) != 0xf9)) {
      if (0x30 < CONCAT11((byte)uVar9,(char)((uint)uVar9 >> 8))) {
        pcVar5 = (code *)swi(0x2f);
        cVar8 = (*pcVar5)();
        if (cVar8 == -0x80) {
          pcVar5 = (code *)swi(0x2f);
          (*pcVar5)();
          *(undefined2 *)((char *)0x43) = in_BX;
          ((char *)0x45)[0] = '\0';
          ((char *)0x45)[1] = -0x10;
          (**(code **)((char *)0x43))();
          if (1 < extraout_AH) {
            uVar11 = (**(code **)((char *)0x43))();
            if (uVar11 != 0) {
              uVar17 = (**(code **)((char *)0x43))();
              if ((int)uVar17 != 0) {
                *(int *)((char *)0x47) =
                     (int)((ulong)uVar17 >> 0x10);
                uVar17 = (**(code **)((char *)0x43))();
                if ((int)uVar17 != 0) {
                  *(undefined2 *)((char *)0x3a) = in_BX;
                  *(int *)((char *)0x3c) = (int)((ulong)uVar17 >> 0x10);
                  uVar10 = (uint)((ulong)uVar11 * 0x400);
                  uVar4 = *(uint *)((char *)0x3a);
                  iVar12 = *(int *)((char *)0x3c);
                  *(uint *)((char *)0x3e) =
                       uVar10 + *(uint *)((char *)0x3a);
                  *(uint *)((char *)0x40) =
                       (int)((ulong)uVar11 * 0x400 >> 0x10) + iVar12 + (uint)CARRY2(uVar10,uVar4);
                }
                (**(code **)((char *)0x43))();
                (**(code **)((char *)0x43))();
                ((char *)0x47)[0] = '\0';
                ((char *)0x47)[1] = '\0';
              }
            }
            goto L__INITEXT_105D;
          }
        }
      }
      pcVar5 = (code *)swi(0x15);
      uVar11 = (*pcVar5)();
      if (uVar11 != 0) {
        lVar6 = (ulong)uVar11 * 0x400;
        *(int *)((char *)0x3e) = (int)lVar6;
        *(uint *)((char *)0x40) =
             CONCAT11((char)((ulong)lVar6 >> 0x18),(char)((ulong)lVar6 >> 0x10) + '\x10');
        if (*(int *)((char *)0x43) != 0 ||
            *(int *)((char *)0x45) != 0) {
          ((char *)"Divide error\r\n")[0xd] = '\x11';
          ((char *)0x3a)[0] = '\0';
          ((char *)0x3a)[1] = '\0';
        }
        bVar15 = false;
        uVar16 = 1;
        __EXTCOPY();
        if (!bVar15) {
          pbVar14 = cmpBuf;
          pbVar13 = (byte *)__C0_ASM_CopyRight + 0x1c;
          iVar12 = 5;
          do {
            if (iVar12 == 0) break;
            iVar12 = iVar12 + -1;
            pbVar2 = pbVar14;
            pbVar14 = pbVar14 + 1;
            pbVar1 = pbVar13;
            pbVar13 = pbVar13 + 1;
            uVar16 = *pbVar1 == *pbVar2;
          } while ((bool)uVar16);
          if ((bool)uVar16) {
            *(int *)((char *)0x3a) = (int)((ulong)uStack_17 * (ulong)uStack_f);
            ((char *)"Divide error\r\n")[0xd] =
                 (char)((ulong)uStack_17 * (ulong)uStack_f >> 0x10) + '\x10';
          }
          bVar15 = true;
          pbVar13 = (byte *)__C0_ASM_CopyRight + 0xe;
          pbVar14 = (byte *)__C0_ASM_CopyRight + 0x1c;
          iVar12 = 5;
          do {
            if (iVar12 == 0) break;
            iVar12 = iVar12 + -1;
            pbVar2 = pbVar13;
            pbVar13 = pbVar13 + 1;
            pbVar1 = pbVar14;
            pbVar14 = pbVar14 + 1;
            bVar15 = *pbVar1 == *pbVar2;
          } while (bVar15);
          if (bVar15) {
            bVar3 = ((byte *)__C0_ASM_CopyRight)[0x2a];
            if (((byte)((char *)"Divide error\r\n")[0xd] <= bVar3) &&
               ((bVar3 != ((char *)"Divide error\r\n")[0xd] ||
                (*(uint *)((char *)0x3a) <
                 *(uint *)((byte *)__C0_ASM_CopyRight + 0x28))))) {
              *(uint *)((char *)0x3a) =
                   *(uint *)((byte *)__C0_ASM_CopyRight + 0x28);
              ((char *)"Divide error\r\n")[0xd] = bVar3;
            }
          }
          goto L__INITEXT_105D;
        }
      }
    }
    iVar12 = 0;
  }
  else {
    if ((((char *)"Abnormal program termination\r\n")[5] & 2U) == 0) goto L__INITEXT_0EEC;
L__INITEXT_105D:
    iVar12 = *(int *)((char *)0x3e) -
             *(int *)((char *)0x3a);
  }
  return iVar12;
}
