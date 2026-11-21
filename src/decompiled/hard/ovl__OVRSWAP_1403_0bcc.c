void __cdecl16near OVRSWAP_1403_0bcc(void)

{
  undefined2 uVar1;
  undefined2 in_CX;
  undefined2 in_DX;
  undefined2 in_BX;
  undefined2 unaff_ES;
  undefined1 in_CF;
  bool bVar2;
  
  uVar1 = 0x2270;
  OVRSWAP_1403_0c2b();
  if (!(bool)in_CF) {
    (*(code **)&ram0x00024186)(0x1403,in_DX,in_CX,in_BX,uVar1);
    bVar2 = (int)((ulong)*(uint *)((byte *)__C0_ASM_CopyRight + 0xc) * 0x10 >> 0x10) != 0;
    __EXTCOPY();
    if (bVar2) {
      __OverlayHalt();
      return;
    }
  }
  return;
}
