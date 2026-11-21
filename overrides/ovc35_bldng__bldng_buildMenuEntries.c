void __cdecl16far
bldng_buildMenuEntries(uint32_t bldTypes,far_t entries,int count,uint8_t partyIndex)

{
  undefined2 uVar1;
  undefined2 uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined1 *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  int iVar10;
  int iVar12;
  int iVar13;
  undefined2 uVar14;
  uint8_t partyIndex_00;
  undefined1 *puVar16;
  uint uStack_e;
  undefined1 *uStack_c;   /* hand fix: assigned a byte pointer and dereferenced as *uStack_c */
  uint16_t uVar11;
  uint16_t uVar15;
  
  iVar12 = 0;
  while( true ) {
    iVar10 = (int)bldTypes;
    uVar14 = (undefined2)(bldTypes >> 0x10);
    uVar11 = entries.ofs;
    uVar15 = entries.seg;
    if (count + -1 <= iVar12) break;
    uVar4 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar12 * 2));
    uStack_e = *(uint *)((uVar4 & 0xff) * 0x27 + 0x125);
    iVar13 = iVar12;
    while (iVar13 = iVar13 + 1, iVar13 < count) {
      uVar4 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar13 * 2));
      if (*(uint *)((uVar4 & 0xff) * 0x27 + 0x125) < uStack_e) {
        uVar6 = *(undefined2 *)(iVar10 + iVar13 * 2);
        *(undefined2 *)(iVar10 + iVar13 * 2) = *(undefined2 *)(iVar10 + iVar12 * 2);
        *(undefined2 *)(iVar10 + iVar12 * 2) = uVar6;
        puVar8 = (undefined2 *)(uVar11 + iVar13 * 4);
        uVar6 = puVar8[1];
        uVar1 = *puVar8;
        puVar8 = (undefined2 *)(uVar11 + iVar12 * 4);
        uVar2 = *puVar8;
        puVar9 = (undefined2 *)(uVar11 + iVar13 * 4);
        puVar9[1] = puVar8[1];
        *puVar9 = uVar2;
        puVar8 = (undefined2 *)(uVar11 + iVar12 * 4);
        puVar8[1] = uVar6;
        *puVar8 = uVar1;
        uVar4 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar12 * 2));
        uStack_e = *(uint *)((uVar4 & 0xff) * 0x27 + 0x125);
      }
    }
    iVar12 = iVar12 + 1;
  }
  iVar12 = 0;
  do {
    if (count <= iVar12) {
      return;
    }
    uVar4 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar12 * 2));
    uVar4 = *(uint *)((uVar4 & 0xff) * 0x27 + 0x125);
    puVar8 = (undefined2 *)(uVar11 + iVar12 * 4);
    puVar7 = (undefined1 *)*puVar8;
    uStack_c = (undefined1 *)CONCAT22(puVar8[1],puVar7);
    puVar16 = (undefined1 *)0x0;
    uVar5 = ovr_ovc45_compute3(partyIndex);
    if (((int)puVar7 < (int)puVar16) || ((puVar16 == puVar7 && (uVar5 < uVar4)))) {
L_bldng_676c_01b0_037F:
      *uStack_c = 0x25;
    }
    else {
      partyIndex_00 = partyIndex;
      uVar6 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar12 * 2));
      bVar3 = bldng_textArena((byte)uVar6,partyIndex_00);
      if (!bVar3) goto L_bldng_676c_01b0_037F;
      *uStack_c = 0x40;
    }
    iVar12 = iVar12 + 1;
  } while( true );
}
