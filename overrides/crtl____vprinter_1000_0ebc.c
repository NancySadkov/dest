void __cdecl16near __vprinter_1000_0ebc(void)

{
  int iVar1;
  int unaff_BP;
  int unaff_DI;
  int iVar2;
  uint16_t unaff_SS;
  
  iVar2 = unaff_DI - (unaff_BP + -0x96);
  iVar1 = (*(code *)*(uint16_t *)(unaff_BP + 0xe))
                    (*(uint16_t *)(unaff_BP + 10),*(uint16_t *)(unaff_BP + 0xc),iVar2,
                     unaff_BP + -0x96);
  if (iVar1 == 0) {
    *(uint16_t *)(unaff_BP + -0x16) = 1;
  }
  *(uint16_t *)((char *)init_textFilename + unaff_BP) = 0x50;
  *(int *)(unaff_BP + -0x12) = *(int *)(unaff_BP + -0x12) + iVar2;
  return;
}
