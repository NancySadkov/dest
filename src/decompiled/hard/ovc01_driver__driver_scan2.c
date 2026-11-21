void __cdecl16near driver_scan2(void)

{
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  int in_CX;
  int iVar5;
  byte bVar6;
  byte bVar7;
  int unaff_BP;
  undefined1 *unaff_SI;
  int unaff_DI;
  undefined1 *puVar8;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  bool bVar9;
  
  bVar2 = *(byte *)(unaff_BP + -6);
  bVar3 = *(byte *)(unaff_BP + -0x10);
  bVar6 = *(byte *)(unaff_BP + -2);
  bVar7 = *(byte *)(unaff_BP + -0xc);
  uVar4 = *(undefined1 *)(unaff_BP + 0x12);
  do {
    iVar5 = unaff_DI - (int)unaff_SI;
    bVar9 = iVar5 < 0;
    if (bVar9) {
      iVar5 = -iVar5;
    }
    puVar8 = unaff_SI;
    for (iVar5 = iVar5 + 1; iVar5 != 0; iVar5 = iVar5 + -1) {
      puVar1 = puVar8;
      puVar8 = puVar8 + (uint)bVar9 * -2 + 1;
      *puVar1 = uVar4;
    }
    unaff_SI = unaff_SI + *(int *)(unaff_BP + -4);
    bVar9 = bVar6 < bVar2;
    bVar6 = bVar6 - bVar2;
    if (bVar9) {
      unaff_SI = unaff_SI + *(int *)(unaff_BP + -8);
      bVar6 = bVar6 + *(char *)(unaff_BP + -10);
    }
    unaff_DI = unaff_DI + *(int *)(unaff_BP + -0xe);
    bVar9 = bVar7 < bVar3;
    bVar7 = bVar7 - bVar3;
    if (bVar9) {
      unaff_DI = unaff_DI + *(int *)(unaff_BP + -0x12);
      bVar7 = bVar7 + (char)((char *)init_textFilename   /* hand fix: indexing a code* has unknown size; the bytes are read as chars */)[unaff_BP];
    }
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  return;
}
