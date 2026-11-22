void __cdecl16far stshInitTxtFiles(char grab,...)

{
  undefined1 stk_ff74;   /* stack slot ff74 */
  far_t far *pfVar1;
  undefined1 *in_DX;
  uint16_t unaff_SS;
  far_t dst;
  far_t far *in_stack_0000ff74;
  uint auStack_8a [67];
  uint8_t i;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&stk_ff74;
  F_SCOPY(far_from_u32((uint32_t)(0x2410822c)),dst);
  for (i = 0x0; i < 0x22; i = i + 0x1) {
    if (grab == '\0') {
      pfVar1 = ovr_stshAllocStub(in_stack_0000ff74);
      *(int *)((uint)i * 4 + -0x6c6e) = (int)in_DX;
      *(uint16_t *)((uint)i * 4 + -0x6c70) =(uint16_t)( pfVar1);
    }
    else {
      in_DX = &stk_ff74;
      pfVar1 = ovr_stshStoreFile_2(*(far_t far **)(in_DX + (uint)i * 4),
                                   (char *)(ulong)auStack_8a[(uint)i * 2],
                                   (uint16_t)in_stack_0000ff74);
      *(int *)((uint)i * 4 + -0x6c6e) = (int)in_DX;
      *(uint16_t *)((uint)i * 4 + -0x6c70) =(uint16_t)( pfVar1);
    }
  }
  return;
}
