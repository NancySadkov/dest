void __cdecl16far constrct_usesLDIV_at_(byte partyIndex,int entityIndex)

{
  uint *puVar1;
  int *piVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  long *plVar6;
  char *msg;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined2 unaff_SI;
  uint uVar12;
  long *unaff_DI;
  int iVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  char *unaff_SS;
  long lVar16;
  long lVar17;
  undefined4 in_stack_0000ff5e;
  long in_stack_0000ff62;
  undefined2 uStack_12;
  
  lVar17 = CONCAT22((int)((ulong)in_stack_0000ff5e >> 0x10),unaff_SI);
  bVar3 = *(byte *)((int)Entities + entityIndex * 0x37 + 0x1a);
  if ((partyIndex != 0xff) && (bVar3 != 0xff)) {
    bVar4 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3e);
    iVar9 = *(int *)((int)&worldMenuLabels[9].seg + 1 + (uint)bVar4 * 0x95);
    uVar5 = *(int *)((int)&worldMenuLabels[9].seg + 1 + (uint)bVar4 * 0x95) * 0xf;
    iVar13 = 0;
    for (uVar12 = 0; uVar12 < EntityCount; uVar12 = uVar12 + 1) {
      uVar14 = (undefined2)((ulong)Entities >> 0x10);
      uVar14 = ovr_ovc23_isCursorAt
                         (*(uint16_t *)((int)Entities + uVar12 * 0x37),
                          *(int *)((int)Entities + uVar12 * 0x37 + 2));
      if (((char)uVar14 != '\0') &&
         (*(char *)((int)(char **)GMenuStrings +
                   (uint)*(byte *)((int)Entities + uVar12 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0')) {
        iVar13 = iVar13 + 1;
      }
    }
    lVar16 = LDIV_at_((ulong)(uint)(iVar9 * 0xf),(long)iVar13);
    uVar7 = (undefined2)((ulong)(lVar16 + 1) >> 0x10);
    uVar14 = uVar7;
    plVar6 = LXMUL_at_(unaff_DI,lVar17,in_stack_0000ff62);
    uStack_12 = (undefined2)(lVar16 + 1);
    msg = ovr_stsprintf(&stack0xff60,(char *)CONCAT22(0x81dc,unaff_SS),
                        (char *)CONCAT22(plVar6,(char *)0x2410),uVar14,uStack_12,uVar7,
                        uVar5);
    ovr_say(msg);
    lVar17 = LDIV_at_((ulong)uVar5,10);
    uVar14 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
    iVar9 = (int)*(undefined4 *)((uint)bVar3 << 2);
    uVar8 = uVar5 - (uint)lVar17;
    puVar1 = (uint *)(iVar9 + 0x56);
    uVar12 = *puVar1;
    *puVar1 = *puVar1 + uVar8;
    piVar2 = (int *)(iVar9 + 0x58);
    *piVar2 = *piVar2 + (-(uint)(uVar5 < (uint)lVar17) - (int)((ulong)lVar17 >> 0x10)) +
              (uint)CARRY2(uVar12,uVar8);
    lVar17 = lVar17 + CONCAT22(GPopulationHi,GPopulationLo);
    GPopulationLo = (undefined2)lVar17;
    GPopulationHi = (undefined2)((ulong)lVar17 >> 0x10);
    uVar14 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
    iVar10 = (int)*(undefined4 *)((uint)bVar3 << 2);
    iVar9 = *(int *)(iVar10 + 0x58);
    uVar7 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
    iVar11 = (int)*(undefined4 *)((uint)bVar3 << 2);
    iVar13 = *(int *)(iVar11 + 0x8c);
    if ((iVar13 <= iVar9) &&
       ((iVar13 < iVar9 || (*(uint *)(iVar11 + 0x8a) < *(uint *)(iVar10 + 0x56))))) {
      uVar7 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
      iVar9 = (int)*(undefined4 *)((uint)bVar3 << 2);
      uVar14 = *(undefined2 *)(iVar9 + 0x8a);
      uVar15 = (undefined2)((ulong)*(undefined4 *)((uint)bVar3 << 2) >> 0x10);
      iVar13 = (int)*(undefined4 *)((uint)bVar3 << 2);
      *(undefined2 *)(iVar13 + 0x58) = *(undefined2 *)(iVar9 + 0x8c);
      *(undefined2 *)(iVar13 + 0x56) = uVar14;
      lVar17 = CONCAT22(GPopulationHi,GPopulationLo);
    }
    GPopulationHi = (undefined2)((ulong)lVar17 >> 0x10);
    GPopulationLo = (undefined2)lVar17;
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter.ofs;   /* hand fix: the offset half is the address, not the far_t struct */
    ovr_inputUpdate(0x36);
  }
  return;
}
