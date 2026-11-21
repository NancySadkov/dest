void __cdecl16near OVRSWAP_1403_09c8(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  code *pcVar3;
  bool bVar4;
  undefined2 uVar5;
  int iVar6;
  undefined2 in_CX;
  uint uVar7;
  undefined2 in_DX;
  undefined1 *puVar8;
  uint uVar9;
  undefined2 in_BX;
  undefined1 *puVar10;
  undefined2 unaff_ES;
  undefined1 in_CF;
  
  uVar5 = 0x2271;
  OVRSWAP_1403_0c2b();
  if ((bool)in_CF) {
    return;
  }
  (*(code **)&ram0x00024186)(0x1403,in_DX,in_CX,in_BX,uVar5);
  puVar8 = (undefined1 *)(undefined1 *)(CONCAT22(in_CX,in_BX) % 0x4000);
  pcVar3 = (code *)swi(0x67);
  iVar6 = (*pcVar3)();
  if (-1 < iVar6) {
    uVar9 = *(uint *)((byte *)__C0_ASM_CopyRight + 4);
    puVar10 = (undefined1 *)0x0;
    do {
      uVar7 = 0x4000U - (int)puVar8;
      if (uVar9 <= 0x4000U - (int)puVar8) {
        uVar7 = uVar9;
      }
      uVar9 = uVar9 - uVar7;
      pcVar3 = (code *)swi(0x67);
      iVar6 = (*pcVar3)();
      bVar4 = true;
      if (iVar6 < 0) goto L_OVRSWAP_1403_09c8_0A34;
      uVar5 = *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0xc);
      for (; uVar7 != 0; uVar7 = uVar7 - 1) {
        puVar2 = puVar8;
        puVar8 = puVar8 + 1;
        puVar1 = puVar10;
        puVar10 = puVar10 + 1;
        *puVar2 = *puVar1;
      }
      puVar8 = (undefined1 *)0x0;
    } while (uVar9 != 0);
    bVar4 = false;
L_OVRSWAP_1403_09c8_0A34:
    pcVar3 = (code *)swi(0x67);
    (*pcVar3)();
    if (!bVar4) {
      return;
    }
  }
  __OverlayHalt();
  return;
}
