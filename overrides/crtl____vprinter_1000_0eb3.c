void __cdecl16near __vprinter_1000_0eb3(void)

{
  char *pcVar1;   /* hand fix: the bytes are read as chars */
  undefined1 in_AL;
  int iVar2;
  int unaff_BP;
  undefined1 *unaff_DI;
  uint16_t unaff_SS;
  
  *unaff_DI = in_AL;
  pcVar1 = (char *)init_textFilename + unaff_BP;
  *pcVar1 = (unsigned short)((char)*pcVar1 + -1);
  if (*pcVar1 == (unsigned short)0x0) {
    iVar2 = (*(code *)*(uint16_t *)(unaff_BP + 0xe))
                      (*(uint16_t *)(unaff_BP + 10),*(uint16_t *)(unaff_BP + 0xc),
                       unaff_DI + (1 - (unaff_BP + -0x96)),unaff_BP + -0x96);
    if (iVar2 == 0) {
      *(uint16_t *)(unaff_BP + -0x16) = 1;
    }
    *(uint16_t *)((char *)init_textFilename + unaff_BP) = 0x50;
    *(int *)(unaff_BP + -0x12) =
         (int)(unaff_DI + (1 - (unaff_BP + -0x96)) + *(int *)(unaff_BP + -0x12));
  }
  return;
}
