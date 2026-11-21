far_t __cdecl16near malloc_ExpandBlock(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  byte *pbVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint16_t in_DX;
  uint uVar9;
  uint16_t in_BX;
  byte *pbVar10;
  undefined2 *puVar11;
  byte *pbVar12;
  undefined2 *puVar13;
  bool bVar14;
  far_t fVar15;
  far_t fVar16;
  uint32_t nbytes;
  uint16_t seg;
  
  nbytes = CONCAT22(in_BX,malloc_save_hi);
  fVar15.ofs = (uint16_t)farmalloc((far_t *)malloc_save_lo,nbytes);   /* hand fix: first argument is the hidden return pointer; result is the offset half */
  if (in_DX == 0) {
    fVar15.seg = 0;
    return fVar15;
  }
  seg = (uint16_t)(nbytes >> 0x10);
  uVar9 = *(int *)0x0 - 1;
  pbVar12 = (byte *)__C0_ASM_CopyRight;
  pbVar10 = (byte *)__C0_ASM_CopyRight;
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    pbVar3 = pbVar12;
    pbVar12 = pbVar12 + 2;
    pbVar1 = pbVar10;
    pbVar10 = pbVar10 + 2;
    *(undefined2 *)pbVar3 = *(undefined2 *)pbVar1;
  }
  if (uVar9 != 0) {
    iVar6 = in_DX + 1;
    iVar5 = seg + 1;
    while( true ) {
      puVar13 = (undefined2 *)0x0;
      puVar11 = (undefined2 *)0x0;
      uVar7 = uVar9;
      if (0x1000 < uVar9) {
        uVar7 = 0x1000;
      }
      for (iVar8 = uVar7 << 3; iVar8 != 0; iVar8 = iVar8 + -1) {
        puVar4 = puVar13;
        puVar13 = puVar13 + 1;
        puVar2 = puVar11;
        puVar11 = puVar11 + 1;
        *puVar4 = *puVar2;
      }
      bVar14 = uVar9 < 0x1000;
      uVar9 = uVar9 - 0x1000;
      if (bVar14 || uVar9 == 0) break;
      iVar6 = iVar6 + 0x1000;
      iVar5 = iVar5 + 0x1000;
    }
  }
  farfree(in_BX,seg);
  fVar16.seg = in_DX;
  fVar16.ofs = 4;
  return fVar16;
}
