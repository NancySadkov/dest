far_t * __cdecl16far ovc22_textRingProt(byte partyIndex,...)

{
  char *pcVar1;
  byte *pbVar2;
  uint *puVar3;
  int *piVar4;
  uint8_t *puVar5;
  byte *pbVar6;
  short sVar7;
  undefined1 *puVar8;
  byte bVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  far_t table;
  far_t entries;
  far_t pctOut;
  far_t remainderOut;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  far_t gfx_08;
  far_t gfx_09;
  far_t gfx_10;
  far_t gfx_11;
  far_t partOut;
  uint3 uVar12;
  far_t *pfVar13;
  char cVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  char cVar18;
  undefined1 uVar19;
  far_t *in_AX;
  far_t *pfVar20;
  char *pcVar21;
  uint uVar22;
  uint uVar23;
  uint16_t index;
  uint16_t uVar24;
  char cVar25;
  undefined2 in_CX;
  byte bVar26;
  byte bVar27;
  uint16_t *puVar28;
  byte bVar34;
  int iVar29;
  int iVar30;
  uint16_t uVar31;
  uint uVar32;
  uint uVar33;
  byte bVar35;
  byte bVar43;
  uint *puVar36;
  unit_t *puVar37;
  unit_t *puVar38;
  int iVar39;
  int iVar40;
  entity_t *peVar41;
  entity_t *peVar42;
  uint *puVar45;
  uint uVar46;
  uint *puVar47;
  uint uVar48;
  uint16_t unaff_SI;
  uint *puVar49;
  uint *puVar50;
  undefined2 *puVar51;
  uint *unaff_DI;
  int iVar52;
  undefined2 uVar53;
  undefined2 uVar54;
  undefined2 uVar55;
  char *unaff_SS;
  bool bVar56;
  bool bVar57;
  bool bVar58;
  bool bVar59;
  byte in_AF;
  bool bVar60;
  bool bVar61;
  bool bVar62;
  byte bStack0006;
  byte bStack0008;
  undefined1 uStack0009;
  undefined1 *in_stack_0000000a;
  undefined2 in_stack_0000000c;
  byte in_stack_0000000e;
  char in_stack_00000010;
  char acStackY_13e [36];
  undefined2 auStackY_11a [58];
  char acStackY_a6 [16];
  undefined2 auStackY_96 [22];
  uint16_t unitNameOfs;
  char acStackY_68 [6];
  undefined2 uStackY_62;
  undefined2 uStackY_60;
  undefined2 *puVar63;
  char cVar64;
  undefined1 uVar65;
  char cVar66;
  undefined1 uVar67;
  undefined1 uVar68;
  undefined1 in_stack_0000ffb8;
  undefined1 in_stack_0000ffb9;
  undefined1 uVar69;
  uint16_t in_stack_0000ffbe;
  uint16_t in_stack_0000ffc0;
  agnt_t *in_stack_0000ffc2;
  int iStack_3c;
  uint uStack_38;
  int iStack_36;
  uint uStack_34;
  int16_t resourceTotals [4];
  int16_t animStep;
  undefined2 uStack_28;
  undefined2 uStack_26;
  uint uStack_24;
  int iStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  char cStack_1c;
  byte bStack_1b;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  uint *puStack_12;
  uint *puStack_10;
  undefined2 uStack_e;
  uint16_t scratch;
  uint *puStack_a;
  uint16_t uStack_8;
  undefined4 uStack_6;
  byte bVar44;
  
  uVar19 = (undefined1)((uint)in_CX >> 8);
  cVar25 = (char)unaff_DI;
  uVar68 = (undefined1)((uint)unaff_DI >> 8);
  if (partyIndex != 0xff) {
    uStack_1e = 0;
    uVar67 = 0;
    uVar69 = 0;
    iStack_22 = 0;
    uStack_20 =(uint16_t)( (byte *)__C0_ASM_CopyRight + 6);
    cVar14 = (char)unaff_SS;
    uVar65 = (undefined1)((uint)unaff_SS >> 8);
    _fmemset((void *)ZEXT24(unaff_SS),6,(uint16_t)unaff_DI);
    _fmemset((void *)ZEXT24(unaff_SS),6,CONCAT11(uVar68,cVar25));
    _fmemset((void *)(ulong)*(uint *)((uint)partyIndex * 4 + 2),3,CONCAT11(uVar68,cVar25));
    _fmemset((void *)ZEXT24(unaff_SS),6,CONCAT11(uVar68,cVar25));
    if (Difficulty == '\x01') {
      uStack_38 = 4000;
    }
    else if (Difficulty == '\x02') {
      uStack_38 = 3000;
    }
    else {
      uStack_38 = 2000;
    }
    iStack_36 = 0;
    resourceTotals[0] = 0;
    uStack_34 = 0;
    iStack_3c = 0;
    _fmemset((void *)ZEXT24(unaff_SS),8,CONCAT11(uVar68,cVar25));
    uStack_14 =(uint16_t)( (far_t *)&GUnitDescriptions[3].ofs);
    while (uStack_14 = (far_t *)((int)uStack_14 + 1), uStack_14 < GUnitCount) {
      pbVar2 = &((unit_t *)GUnits)[(int)uStack_14].flags;
      *pbVar2 = *pbVar2 & 0xfd;
    }
    bVar17 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3f);
    uVar23 = CONCAT11(uVar19,bVar17);
    uStack_e =(uint16_t)( (uint *)(0x1000 << (bVar17 & 0x1f)));
    *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xad) = 0;
    _fmemset((void *)(ulong)*(uint *)((uint)partyIndex * 4 + 2),3,CONCAT11(uVar68,cVar25));
    iVar30 = CONCAT11(uVar69,uVar67);
    if (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3f) == '\0') {
      pbVar2 = (byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d);
      *pbVar2 = *pbVar2 | 4;
    }
    else {
      pbVar2 = (byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d);
      *pbVar2 = *pbVar2 & 0xf9;
    }
    pbVar2 = (byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d);
    *pbVar2 = *pbVar2 & 0xf7;
    *(undefined2 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xa0) = 0;
    *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xa6) = 0;
    *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xa5) = 0;
    *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xa9) = 0;
    bVar17 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3e);
    (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)( (far_t *)CONCAT11(bVar17,(byte)uStack_6));
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar17 * 0x95) == '\x01') {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(far_t *)uStack_6);
      uVar12 = (uint3)uStack_6;
    }
    else {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((far_t *)uStack_6);
      uVar12 = (uint3)uStack_6;
    }
    (*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) = (byte)(uVar12 >> 8);
    if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) * 0x95) == '\0') ||
       (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) * 0x95) == '\x05')) {
      uStack_6 = (far_t *)CONCAT13(1,uVar12);
    }
    else {
      uStack_6 = (far_t *)(ulong)uVar12;
    }
    *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xa8) = 0;
    GCanPromote = '\0';
    puVar49 = (uint *)&GUnitDescriptions[3].ofs;
    while (puVar50 = puVar49, puVar49 = (uint *)((int)puVar50 + 1), puVar49 < GUnitCount) {
      uVar53 = (undefined2)((ulong)GUnits >> 0x10);
      puVar37 = (unit_t *)GUnits;
      if (puVar37[(int)puVar49].unitType == partyIndex) {
        (*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) = (puVar37 + (int)puVar49)->bldType;
        uStack_16 =(uint16_t)( (far_t *)ovr_alignUp4(puVar37[(int)puVar49].x));
        uVar53 = (undefined2)((ulong)GUnits >> 0x10);
        uStack_18 = ((unit_t *)GUnits)[(int)puVar49].y;
        puStack_10 = (uint *)0x0;
        uStack_1a = (uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) << 8;
        while( true ) {
          if (3 < (byte)uStack_1a) break;
          puStack_10 = (uint *)((uint)puStack_10 |
                               ((short (*) [60] [148])GMapFlags)[-1][uStack_18 + 0x3b]
                               [(int)uStack_16 + (uStack_1a & 0xff) + 0x92] & 0x3000U);
          uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(byte)uStack_1a + 1);
        }
        puStack_12 = (uint *)0x0;
        if ((*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x11e) & 3) == 1) {
          uStack_1a = (uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) << 8;
          while ((byte)uStack_1a < 4) {
            puStack_12 = (uint *)((uint)puStack_12 |
                                 (*(short (*) [60] [148])GMapFlags)[uStack_18]
                                 [(int)uStack_16 + (uStack_1a & 0xff) + 0x92] & 0x3000U);
            uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(byte)uStack_1a + 1);
          }
        }
        if ((((uint)uStack_e & (uint)puStack_10) != 0) || (((uint)uStack_e & (uint)puStack_12) != 0)
           ) {
          pbVar2 = &((unit_t *)GUnits)[(int)puVar49].flags;
          *pbVar2 = *pbVar2 | 3;
          iVar29 = 0x195d;
          uVar54 = 0x195d;
          pfVar20 = (far_t *)(*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) - 7);
          puVar37 = (unit_t *)GUnits;
          uVar53 = (undefined2)((ulong)GUnits >> 0x10);
          if (pfVar20 < (far_t *)((byte *)__C0_ASM_CopyRight + 0x12)) {
            puVar38 = (unit_t *)((int)pfVar20 * 2);
            bVar16 = (byte)pfVar20;
            uVar19 = (undefined1)((uint)pfVar20 >> 8);
            bVar17 = (byte)uVar23;
            bVar15 = (byte)(uVar23 >> 8);
            switch(pfVar20) {
            case (far_t *)0x0:
              AgntAnms[0x68].ey = AgntAnms[0x68].ey | 0x195d;
              puVar3 = unaff_DI;
              iVar30 = 1 - (*puVar3 & 3);
              *puVar3 = *puVar3 + (uint)(0 < iVar30) * iVar30;
              *(char *)puVar49 = (char)*puVar49 + '\x01';
              uVar33 = CONCAT11(uVar19,(s_my_s_we_in_this_neighborhood_are_doing_well[0x4c] - 0x2fU)
                                       + (0xe7U < (byte)
                                                  s_my_s_we_in_this_neighborhood_are_doing_well
                                                  [0x4c]));
              puVar3 = (uint *)((int)unaff_DI + (int)((int)&puVar38[-0xd8c].y + 1));
              uVar22 = (uint)(0x46 < (byte)(s_my_s_we_in_this_neighborhood_are_doing_well[0x4c] +
                                           0x18U) ||
                             CARRY1(s_my_s_we_in_this_neighborhood_are_doing_well[0x4c] - 0x2fU,
                                    0xe7U < (byte)s_my_s_we_in_this_neighborhood_are_doing_well
                                                  [0x4c]));
              uVar48 = (int)resourceTotals + (-0x1f - *puVar3);
              iVar30 = -uVar22;
              puVar8 = (undefined1 *)(uint)(&stack0xffaf < (undefined1 *)*puVar3 || uVar48 < uVar22)
              ;
              puVar10 = &stack0xfffe + -*puVar49;
              uVar22 = (uint)(&stack0xfffe < (undefined1 *)*puVar49 || puVar10 < puVar8);
              uVar32 = (int)puVar38 - *(uint *)(&puVar38->bldType + (int)unaff_DI);
              iVar39 = uVar32 - uVar22;
              uVar22 = (uint)(puVar38 < *(unit_t **)(&puVar38->bldType + (int)unaff_DI) ||
                             uVar32 < uVar22);
              uVar32 = 0x145d - *(uint *)(iVar39 + (int)unaff_DI);
              iVar52 = uVar32 - uVar22;
              uVar22 = (uint)(0x145d < *(uint *)(iVar39 + (int)unaff_DI) || uVar32 < uVar22);
              uVar32 = uVar33 - *unaff_DI;
              iVar29 = uVar32 - uVar22;
              uVar22 = (uint)(uVar33 < *unaff_DI || uVar32 < uVar22);
              uVar32 = (int)(puVar10 + -(int)puVar8) - (uVar48 + iVar30);
              bVar58 = puVar10 + -(int)puVar8 < (undefined1 *)(uVar48 + iVar30) || uVar32 < uVar22;
              uVar32 = uVar32 - uVar22;
              bVar26 = (byte)((uint)iVar29 >> 8);
              bVar27 = (byte)((uint)iVar39 >> 8);
              bVar16 = bVar26 - bVar27;
              bVar59 = bVar26 < bVar27 || bVar16 < bVar58;
              bVar35 = (byte)iVar29;
              bVar16 = bVar16 - bVar58;
              bVar43 = (byte)iVar52;
              bVar26 = bVar43 - bVar16;
              bVar58 = bVar43 < bVar16 || bVar26 < bVar59;
              bVar34 = (byte)((uint)iVar52 >> 8);
              bVar26 = bVar26 - bVar59;
              bVar43 = bVar27 - *(byte *)(iVar39 + -0x4ae6);
              bVar59 = bVar27 < *(byte *)(iVar39 + -0x4ae6) || bVar43 < bVar58;
              bVar43 = bVar43 - bVar58;
              bVar27 = bVar35 - (char)unaff_DI[0x250d];
              bVar58 = bVar35 < (byte)unaff_DI[0x250d] || bVar27 < bVar59;
              bVar27 = bVar27 - bVar59;
              bVar35 = (byte)iVar39 - AgntAnms[0xf].frmid;
              bVar59 = (byte)iVar39 < AgntAnms[0xf].frmid || bVar35 < bVar58;
              bVar35 = bVar35 - bVar58;
              bVar9 = bVar43 - bVar27;
              bVar44 = bVar9 - bVar59;
              puVar36 = (uint *)CONCAT11(bVar44,bVar35);
              uVar22 = (uint)(bVar43 < bVar27 || bVar9 < bVar59);
              uVar33 = uVar32 - uVar23;
              puVar47 = (uint *)(uVar33 - uVar22);
              puVar3 = (uint *)((int)unaff_DI + -0x57e7);
              uVar33 = (uint)(uVar32 < uVar23 || uVar33 < uVar22);
              uVar22 = *puVar3;
              uVar32 = *puVar3;
              *puVar3 = (uVar32 - (int)puVar47) - uVar33;
              puVar3 = (uint *)((int)puVar47 + 0x7419);
              uVar33 = (uint)(uVar22 < puVar47 || uVar32 - (int)puVar47 < uVar33);
              uVar32 = *puVar3;
              uVar22 = *puVar3;
              *puVar3 = (uVar22 - uVar23) - uVar33;
              puVar3 = puVar50 + 0xd;
              uVar22 = (uint)(uVar32 < uVar23 || uVar22 - uVar23 < uVar33);
              puVar50 = (uint *)*puVar3;
              uVar23 = *puVar3;
              *puVar3 = (uVar23 - (int)puVar36) - uVar22;
              *(undefined2 *)(uVar48 + iVar30 + -2) =(uint16_t)( unaff_DI);
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
              uVar23 = (uint)(puVar50 < puVar36 || uVar23 - (int)puVar36 < uVar22);
              (*(uint16_t *)((uint8_t *)&(s_Peaceful_2410_2915) + 4)) = (0x6665U - (int)unaff_DI) - uVar23;
              uVar23 = (uint)((uint)0x6665 < unaff_DI || (uint)(0x6665U - (int)unaff_DI) < uVar23);
              bVar58 = (uint)AgntAnms[6].y < CONCAT11(bVar34,bVar26);
              uVar22 = AgntAnms[6].y - CONCAT11(bVar34,bVar26);
              AgntAnms[6].y = uVar22 - uVar23;
              uVar23 = (uint)(bVar58 || uVar22 < uVar23);
              uVar22 = (uVar48 + iVar30 + -2) - (int)unaff_DI;
              bVar58 = (uint *)(uVar48 + iVar30 + -2) < unaff_DI || uVar22 < uVar23;
              iVar30 = -uVar23;
              puVar45 = (uint *)(uVar22 + iVar30);
              bVar59 = bVar26 < bVar15 || (byte)(bVar26 - bVar15) < bVar58;
              bVar43 = (bVar26 - bVar15) - bVar58;
              bVar58 = bVar16 < bVar35 || (byte)(bVar16 - bVar35) < bVar59;
              bVar26 = (bVar16 - bVar35) - bVar59;
              bVar16 = bVar43 - bVar27;
              bVar59 = bVar43 < bVar27 || bVar16 < bVar58;
              bVar16 = bVar16 - bVar58;
              pbVar2 = (byte *)((char *)((int)puVar36 + (int)puVar49) + -0x60e8);
              bVar58 = *pbVar2 < bVar15 || (byte)(*pbVar2 - bVar15) < bVar59;
              *pbVar2 = (*pbVar2 - bVar15) - bVar59;
              puVar3 = puVar47 + -0x3974;
              bVar15 = (byte)*puVar3 - bVar16;
              bVar59 = (byte)*puVar3 < bVar16 || bVar15 < bVar58;
              *(byte *)puVar3 = bVar15 - bVar58;
              puVar3 = puVar49 + 0x3c8c;
              bVar15 = (byte)*puVar3 - bVar27;
              bVar56 = (byte)*puVar3 < bVar27 || bVar15 < bVar59;
              *(byte *)puVar3 = bVar15 - bVar59;
              puVar3 = puVar47 + 0xc;
              bVar59 = (byte)*puVar3 < bVar34;
              bVar15 = (byte)*puVar3 - bVar34;
              bVar57 = bVar59 || bVar15 < bVar56;
              bVar62 = SBORROW1((byte)*puVar3,bVar34) != SBORROW1(bVar15,bVar56);
              *(byte *)puVar3 = bVar15 - bVar56;
              bVar61 = (char)(byte)*puVar3 < '\0';
              bVar60 = (byte)*puVar3 == 0;
              bVar58 = !bVar62;
              puVar50 = puVar47;
              if (!bVar58) {
                puVar3 = unaff_DI;
                unaff_DI = (uint *)((int)unaff_DI + 1);
                cVar25 = in(CONCAT11(bVar34,bVar16));
                *(char *)puVar3 = cVar25;
                puVar3 = puVar49 + 0xc;
                uVar23 = *puVar3;
                bVar43 = (byte)*puVar3 - bVar26;
                *(byte *)puVar3 = bVar43 - bVar57;
                *(undefined2 *)(uVar22 + iVar30 + -2) =(uint16_t)( puVar36);
                ((char *)((int)puVar47 + (int)puVar49))[0x18] =
                     (((char *)((int)puVar47 + (int)puVar49))[0x18] - bVar17) -
                     ((byte)uVar23 < bVar26 || bVar43 < bVar57);
                *(uint *)((int)puVar36 + (int)puVar49) =
                     *(uint *)((int)puVar36 + (int)puVar49) ^ (uint)puVar36;
                *(uint *)((int)puVar36 + (int)puVar49) =
                     *(uint *)((int)puVar36 + (int)puVar49) | (uint)puVar36;
                *(char *)((int)puVar36 + (int)puVar49) =
                     *(char *)((int)puVar36 + (int)puVar49) + bVar35;
                *puVar36 = ~*puVar36;
                puVar50 = (uint *)*puVar47;
                uVar23 = CONCAT11(bVar26,bVar27 - 0x18) & 0x9e1f;
                bVar61 = (int)uVar23 < 0;
                bVar60 = uVar23 == 0;
                puVar45 = puVar47 + 3;
              }
              bVar57 = bVar58 && bVar57;
              uVar53 = *puVar45;
              if (bVar60 || (bVar58 && bVar62) != bVar61) {
                bVar61 = bVar57;
                if ((!bVar58 || !bVar59 && bVar15 >= bVar56) && !bVar60) {
                  *puVar45 = (uint)puVar50;
                  uVar53 = *puVar45;
                  uVar23 = (int)(char)bVar17 + 0xe299;
                  iVar30 = uVar23 - bVar57;
                  *puVar45 = iVar30;
                  *(char *)puVar49 = -(char)*puVar49;
                  return (far_t *)((iVar30 + -0x1d32) -
                                  (uint)((uint)(int)(char)bVar17 < 0x1d67 || uVar23 < bVar57));
                }
              }
              else {
                bVar61 = bVar17 < 0x74 || (byte)(bVar17 + 0x8c) < bVar57;
                bVar17 = (bVar17 + 0x8c) - bVar57;
              }
              bVar58 = bVar17 < 100 || (byte)(bVar17 + 0x9c) < bVar61;
              bVar15 = (bVar17 + 0x9c) - bVar61;
              bVar17 = bVar15 - 0x39;
              bVar59 = bVar15 < 0x39 || bVar17 < bVar58;
              bVar17 = bVar17 - bVar58;
              bVar15 = bVar17 - 0x14;
              bVar58 = bVar17 < 0x14 || bVar15 < bVar59;
              bVar15 = bVar15 - bVar59;
              bVar17 = bVar15 - 8;
              bVar59 = bVar15 < 8 || bVar17 < bVar58;
              bVar17 = bVar17 - bVar58;
              bVar15 = bVar17 - 5;
              bVar26 = bVar15 - bVar59;
              iVar30 = ((int)puVar50 - (int)puVar36) -
                       (uint)(bVar26 < 0xfa || (byte)(bVar26 + 6) < (bVar17 < 5 || bVar15 < bVar59))
              ;
              uVar22 = (uint)puVar49 & *(uint *)((char *)((int)puVar36 + (int)puVar49) + -0x6bdd);
              uVar32 = (uint)unaff_DI & *(uint *)((char *)((int)puVar36 + (int)unaff_DI) + 0x23);
              *puVar45 = uVar22;
              uVar22 = uVar22 & *(uint *)((int)puVar36 + uVar32);
              uVar23 = CONCAT11(bVar34,bVar16) & *(uint *)(iVar30 + uVar22);
              puVar49 = (uint *)CONCAT11(bVar44,bVar35 & bVar44 &
                                                *(byte *)((int)&_streams[0xc].curp +
                                                         CONCAT11(bVar44,bVar35 & bVar44)));
              uVar54 = *puVar45;
              *(uint *)(iVar30 + uVar22) = *(uint *)(iVar30 + uVar22) ^ (uint)(puVar45 + 1);
              *(int *)(iVar30 + uVar22) = *(int *)(iVar30 + uVar22) - (int)(puVar45 + 1);
              bVar17 = in(uVar23);
              uVar22 = uVar22 & uVar23;
              puVar3 = (uint *)((int)puVar49 + (int)((char *)0x2a321 + uVar22));
              *puVar3 = *puVar3 & uVar32;
              *(uint *)(uVar32 + 0x21) = *(uint *)(uVar32 + 0x21) & (uint)puVar49;
              *puVar49 = *puVar49 & uVar32;
              puVar3 = (uint *)&AgntAnms[0x5c].sx;
              *puVar3 = *puVar3 & (uint)(puVar45 + 1);
              puVar3 = (uint *)((int)puVar49 + uVar22);
              *puVar3 = *puVar3 & CONCAT11((char)((uint)uVar54 >> 8),bVar17);
              bVar16 = -(0x99 < bVar17);
              return (far_t *)CONCAT11((char)((uint)uVar54 >> 8),
                                       bVar16 + (9 < (bVar16 & 0xf) | 9 < (bVar17 & 0xf) | in_AF) *
                                                '\x06' + (0x99 < bVar16 || 0x99 < bVar17) * '`');
            case (far_t *)0x1:
              *(uint *)(&stack0x8ed6 + (int)unaff_DI) =
                   *(uint *)(&stack0x8ed6 + (int)unaff_DI) & uVar23;
              return pfVar20;
            default:
              goto switchD_5000_123d_caseD_2;
            case (far_t *)0x3:
            case (far_t *)0x14:
              goto switchD_5000_123d_caseD_3;
            case (far_t *)0x4:
              break;
            case (far_t *)0x5:
              do {
                uVar11 = *(undefined4 *)(((uint)pfVar20 & 0xff) << 2);
                ovr_blitLabel((char *)auStackY_11a
                                      [(int)puVar49 * 2 + (uint)*(byte *)((int)uVar11 + 0x2f) * 8]);
                while( true ) {
                  func_0x0005f303();
                  ovr_stsprintf(acStackY_13e);
                  iVar30 = ovr_font_textWidth(acStackY_13e);
                  TextBlitX = 0x89 - iVar30;
                  ovr_blitLabel(acStackY_13e);
                  ovr_stsprintf(acStackY_13e);
                  iVar30 = ovr_font_textWidth(acStackY_13e);
                  puVar28 = (uint16_t *)(0xd4 - iVar30);
                  TextBlitX = (uint16_t)puVar28;
                  ovr_blitLabel(acStackY_13e);
                  puVar49 = (uint *)((int)puVar49 + 1);
L_OVC22_5087_0234_323C:
                  TextBlitY = TextBlitY + 0xc;
                  cVar25 = (char)uVar23;
                  if ((int)(scratch >> 8) <= (int)puVar49) goto L_OVC22_5087_0234_32B8;
                  TextBlitX = 0x11;
                  if ((4 < (int)puVar49) && ((char)scratch != '\0')) break;
                  ovr_blitLabel((char *)auStackY_96[(int)puVar49 * 2]);
                }
                pfVar20 = (far_t *)(uint)partyIndex;
              } while( true );
            case (far_t *)0x6:
              *(uint *)(&stack0x681c + (int)puVar49) =
                   *(uint *)(&stack0x681c + (int)puVar49) & uVar23;
            case (far_t *)0xb:
              *(uint *)(&stack0x681c + (int)puVar49) =
                   *(uint *)(&stack0x681c + (int)puVar49) & uVar23;
              ovr_blitLabel(&stack0xfffe);
              iVar30 = ovr_font_textWidth((char *)"POPULATION");
              puVar28 = (uint16_t *)(0xd4 - iVar30);
              TextBlitX = (uint16_t)puVar28;
              ovr_blitLabel((char *)"POPULATION");
              puVar49 = (uint *)0x0;
              goto L_OVC22_5087_0234_323C;
            case (far_t *)0x7:
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
              return pfVar20;
            case (far_t *)0x8:
              bVar26 = (&stack0xfffe)[(int)unaff_DI];
              in_AF = 9 < (bVar16 & 0xf) | in_AF;
              uVar46 = (uint)&stack0xffb4 ^ *(uint *)((int)puVar49 + (int)(&puVar38->level + -1));
              uVar22 = (uint)puVar38 ^ (uint)puVar49;
              uVar32 = CONCAT11((byte)(uVar22 >> 8) ^ *(byte *)((int)unaff_DI + uVar22 + 0x8332),
                                (char)uVar22);
              bVar27 = bVar15 ^ 0x5d ^ *(byte *)((int)unaff_DI + uVar32 + 0x32);
              uVar22 = CONCAT11(bVar26,bVar27) ^ 0x1900;
              *(uint *)(&stack0xfffe + (int)puVar49) =
                   *(uint *)(&stack0xfffe + (int)puVar49) ^ (uint)puVar49;
              uVar48 = (int)puVar49 - *(int *)(&stack0xfffe + (int)puVar49);
              uVar32 = uVar32 ^ uVar46;
              uVar33 = (uint)&stack0xfffe ^ uVar32;
              uVar23 = CONCAT11(uVar19,bVar16 + in_AF * -6 + (0x99 < bVar16) * -0x60 + '2' +
                                       (puVar49 < *(uint **)(&stack0xfffe + (int)puVar49))) - 0x5ceU
                       ^ uVar23;
              puVar3 = (uint *)((int)unaff_DI + uVar32 + 0xa231);
              *puVar3 = *puVar3 ^ uVar48;
              *(uint *)((char *)0x2c131 + uVar32) =
                   *(uint *)((char *)0x2c131 + uVar32) ^
                   uVar22;
              puVar3 = (uint *)(uVar33 + uVar48 + 0x31);
              *puVar3 = *puVar3 ^ (uint)unaff_DI;
              iVar29 = uVar48 + 1;
              *(uint *)(uVar33 + (int)unaff_DI) = *(uint *)(uVar33 + (int)unaff_DI) ^ uVar46;
              *unaff_DI = *unaff_DI ^ uVar22;
              puVar51 = (undefined2 *)((uint)unaff_DI ^ uVar46);
              bVar43 = (byte)(uVar23 >> 8);
              bVar16 = (byte)uVar23 ^ bVar27;
              pbVar2 = (byte *)((int)puVar51 + uVar33 + 0xa330);
              *pbVar2 = *pbVar2 ^ bVar26 ^ 0x19;
              *(byte *)(puVar51 + -0x3be8) = *(byte *)(puVar51 + -0x3be8) ^ (byte)uVar32;
              pbVar2 = (byte *)(uVar32 + iVar29 + 0x30);
              bVar26 = (byte)(uVar32 >> 8);
              *pbVar2 = *pbVar2 ^ bVar26;
              pbVar6 = (byte *)(puVar51 + 1);
              uVar53 = in(uVar22);
              *puVar51 = uVar53;
              pbVar2 = (byte *)(uVar32 + iVar29 + 0x30);
              *pbVar2 = *pbVar2 ^ (byte)uVar32;
              *(uint *)(uVar46 - 2) = uVar22;
              *pbVar6 = *pbVar6 ^ bVar26;
              *pbVar6 = *pbVar6 ^ bVar15;
              *(byte *)(uVar33 + iVar29) = *(byte *)(uVar33 + iVar29) ^ bVar43;
              *pbVar6 = *pbVar6 ^ bVar17;
              *(byte *)(uVar33 + iVar29) = *(byte *)(uVar33 + iVar29) ^ bVar16;
              in_AF = 9 < (bVar16 & 0xf) | in_AF;
              bVar17 = bVar16 + in_AF * -6 + (0x99 < bVar16) * -0x60;
              iVar30 = *(int *)(uVar46 - 2);
              uVar23 = CONCAT11(bVar43 ^ bVar26,
                                bVar17 + (9 < (bVar17 & 0xf) | in_AF) * -6 +
                                (0x99 < bVar17 || 0x99 < bVar16) * -0x60) ^ 0xaf;
              uVar33 = uVar33 ^ uVar23;
              bVar17 = (byte)uVar23 ^ (byte)*(undefined2 *)(uVar32 + iVar29);
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              *(char *)(uVar32 + iVar29) = *(char *)(uVar32 + iVar29) + bVar17;
              pcVar1 = (char *)(iVar30 + -0x75);
              *pcVar1 = *pcVar1 + bVar27;
              in(uVar22);
              *(int *)(uVar46 - 0x10) = iVar29;
              *(int *)(uVar46 - 0x12) = iVar30;
              iVar30 = *(int *)(uVar33 + 6);
              iVar29 = *(int *)(uVar33 + 8);
              if ((((iVar30 < 0) || (iVar29 < 0)) || (0x93 < iVar30 + 1)) || (0x3b < iVar29 + 1)) {
                placementStatus = 2;
                pfVar20 = (far_t *)((char *)0x2400);
              }
              else {
                uVar53 = (undefined2)((ulong)GMapFlags >> 0x10);
                if ((((*(short (*) [60] [148])GMapFlags)[iVar29][iVar30] & 3U) == 0) &&
                   (((*(short (*) [60] [148])GMapFlags)[iVar29 + 1][iVar30] & 3U) == 0)) {
                  *(int *)(uVar33 - 10) =
                       (int)(char)(*(byte (*) [59] [148])GMapCells)[iVar29 + 1][iVar30];
                  *(int *)(uVar33 - 8) =
                       (int)(char)(*(byte (*) [59] [148])GMapCells)[iVar29 + 1][iVar30 + 1];
                  iVar30 = *(int *)(uVar33 - 10);
                  *(undefined2 *)(uVar33 - 2) = *(undefined2 *)(uVar33 - 10);
                  if (*(int *)(uVar33 - 8) < iVar30) {
                    iVar30 = *(int *)(uVar33 - 8);
                  }
                  if (*(int *)(uVar33 - 2) < *(int *)(uVar33 - 8)) {
                    *(undefined2 *)(uVar33 - 2) = *(undefined2 *)(uVar33 - 8);
                  }
                  uVar23 = *(int *)(uVar33 - 2) - iVar30;
                  if ((int)uVar23 < 9) {
                    placementStatus = 3;
                    pfVar20 = (far_t *)((char *)0x2401);
                  }
                  else {
                    pfVar20 = (far_t *)(uVar23 & 0xff00);
                  }
                }
                else {
                  placementStatus = 1;
                  pfVar20 = (far_t *)((char *)0x2400);
                }
              }
              return pfVar20;
            case (far_t *)0x9:
              do {
                ovc22_textRingProt((byte)pfVar20);
                do {
                  uStack_16 =(uint16_t)( (far_t *)((int)uStack_16 + 1));
                  if ((int)(uint)GLeaderCount <= (int)uStack_16) {
                    GGameState = 0x3e;
                    if (DebugVerbose != false) {
                      printf("%d \r");
                    }
                    unaff_DI = (uint *)&GUnitDescriptions[3].ofs;
                    goto L_upd_units_5087_1d7d_202C;
                  }
                } while (*(char *)((int)*(undefined4 *)((int)uStack_16 * 4) + 0x3d) == '\0');
                pfVar20 = (far_t *)CONCAT11(0x21,(undefined1)uStack_16);
              } while( true );
            case (far_t *)0xa:
              iVar29 = 0x6574;
              break;
            case (far_t *)0xc:
              (*(uint8_t *)((uint8_t *)&(iVar30))) = (puVar38 + -0xc24)->bldType;
              (*(uint8_t *)((uint8_t *)&(iVar30) + 1)) = (puVar38 + -0xc24)->level;
              do {
                pfVar20 = (far_t *)uStack_6;
                if (puVar37[iVar30].unitType == partyIndex) {
                  if ((byte)uStack_6 == (*(uint8_t *)((uint8_t *)&(uStack_6) + 1))) {
L_OVC22_5087_4975_4ABE:
                    (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)( pfVar20);
                    if ((byte)uStack_8 < ListCount) {
                      puStack_a = (uint *)puVar37[*(int *)((uStack_8 & 0xff) * 2 + -0x6d44)].x;
                      scratch = puVar37[*(int *)((uStack_8 & 0xff) * 2 + -0x6d44)].y;
                    }
                    else {
                      puStack_a = (uint *)*(uint16_t *)
                                           ((int)*(undefined4 *)((uint)partyIndex << 2) + 0x39);
                      scratch = *(uint16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3b);
                    }
                    uVar53 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
                    iVar29 = (int)*(undefined4 *)((uint)partyIndex << 2);
                    iVar30 = *(int *)(iVar29 + 0x58);
                    if ((iVar30 < 1) && ((iVar30 < 0 || (*(uint *)(iVar29 + 0x56) < 10)))) {
                      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(far_t *)uStack_6);
                    }
                    else {
                      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((far_t *)uStack_6);
                    }
                    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                                  (uint)*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3e
                                                 ) * 0x95) & 0x80) == 0) {
                      uStack_6 = (far_t *)(ulong)(uint3)uStack_6;
                    }
                    else {
                      uStack_6 = (far_t *)CONCAT13(3,(uint3)uStack_6);
                    }
                    if ((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 2) != 0) {
                      uStack_6 = (far_t *)((ulong)uStack_6 | 0x1000000);
                    }
                    uVar11 = *(undefined4 *)((uint)partyIndex << 2);
                    if ((*(byte *)((int)uVar11 + 0x5d) & 4) != 0) {
                      uStack_6 = (far_t *)((ulong)uStack_6 | 0x2000000);
                    }
                    uVar23 = ovc22_searchCellsAround
                                       ((uint *)CONCAT13((char)((uint)&scratch >> 8),
                                                         CONCAT12((char)&scratch,unaff_SS)),
                                        (uint *)CONCAT13((char)(((uint)partyIndex << 2) >> 8),
                                                         CONCAT12(partyIndex,unaff_SS)),
                                        (*(uint8_t *)((uint8_t *)&(uStack_6) + 3)),(*(uint8_t *)((uint8_t *)&(uStack_6) + 2)),cVar25);
                    pfVar20 = (far_t *)(uVar23 & 0xff);
                    if (pfVar20 != (far_t *)0x0) {
                      if (pfVar20 != (far_t *)((int)(undefined4 *)&_DATA + 1U)) {
                        return pfVar20;
                      }
                      uStack_e =(uint16_t)( (uint *)ovc22_usesRandBelow(partyIndex,(uint16_t)puStack_a,scratch)
                      );
                      if (uStack_e == (uint *)0x0) {
                        puStack_a = (uint *)*(uint16_t *)
                                             ((int)*(undefined4 *)((uint)partyIndex << 2) + 0x39);
                        scratch = *(uint16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3b);
                      }
                      else {
                        if ((*(uint *)((int)uStack_e * 0x27 + 0x121) & 0x60) == 0) {
                          uVar53 = (undefined2)
                                   ((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
                          iVar29 = (int)*(undefined4 *)((uint)partyIndex << 2);
                          iVar30 = *(int *)(iVar29 + 0x58);
                          if ((iVar30 < 0) ||
                             ((iVar30 == 0 &&
                              (*(uint *)(iVar29 + 0x56) < *(uint *)((int)uStack_e * 0x27 + 0x125))))
                             ) {
                            uVar53 = (undefined2)
                                     ((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
                            iVar30 = (int)*(undefined4 *)((uint)partyIndex << 2);
                            *(undefined2 *)(iVar30 + 0x58) = 0;
                            *(undefined2 *)(iVar30 + 0x56) = 0;
                          }
                          else {
                            uVar22 = *(uint *)((int)uStack_e * 0x27 + 0x125);
                            uVar53 = (undefined2)
                                     ((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
                            iVar30 = (int)*(undefined4 *)((uint)partyIndex << 2);
                            puVar3 = (uint *)(iVar30 + 0x56);
                            uVar23 = *puVar3;
                            *puVar3 = *puVar3 - uVar22;
                            piVar4 = (int *)(iVar30 + 0x58);
                            *piVar4 = *piVar4 - (uint)(uVar23 < uVar22);
                          }
                        }
                        ovr_createConstructionRecordFar((byte)uStack_e);
                      }
                    }
                    if (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3f) == '\0') {
                      if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5b) <
                          *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d)) {
                        pfVar20 = (far_t *)ovr_ovc18_textTypeLen(partyIndex);
                      }
                      else {
                        pfVar20 = (far_t *)ovr_ovc18_textTypeLen(partyIndex);
                      }
                    }
                    else {
                      pfVar20 = (far_t *)ovr_ovc18_textTypeLen(partyIndex);
                    }
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
                    return pfVar20;
                  }
                  uStack_6 = (far_t *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),(byte)uStack_6 + '\x01');
                }
                do {
                  bVar17 = (byte)uStack_8 + 1;
                  uStack_8 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_8) + 1)),bVar17);
                  pfVar20 = (far_t *)uStack_6;
                  if (ListCount <= bVar17) goto L_OVC22_5087_4975_4ABE;
                } while (*(char *)((uint)(puVar37 + *(int *)((uint)bVar17 * 2 + -0x6d44))->bldType *
                                   0x27 + 0x133) != '\x12');
                iVar30 = *(int *)((uint)bVar17 * 2 + -0x6d44);
              } while( true );
            case (far_t *)0xd:
              bVar17 = (byte)((uint)puVar38 >> 8);
              if (!CARRY1(bVar17,bVar17) && ((uint)puVar38 & 0x7f00) != 0) {
                uVar23 = ovr_ovc23_findRecordAt((int)unaff_DI);
                if (uVar23 == 0xffff) {
                  pfVar20 = (far_t *)(uint)((unit_t *)GUnits + (*(uint16_t *)((uint8_t *)&(uStack_6) + 2)))->bldType;
                  if ((*(uint *)((int)pfVar20 * 0x27 + 0x121) & 0x20) == 0) {
                    pfVar20 = (far_t *)0x0;
                  }
                  else if (*(char *)((int)pfVar20 * 0x27 + 0x131) == '\0') {
                    if (*(char *)((int)*(undefined4 *)((uint)bStack0008 << 2) + 0x2f) == '\x05') {
                      pfVar20 = pfVar20 + 6;
                    }
                    else {
                      pfVar20 = (far_t *)&pfVar20[1].seg;
                    }
                  }
                }
                else {
                  pfVar20 = (far_t *)0x0;
                }
                return pfVar20;
              }
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            case (far_t *)0xe:
              puVar38->bldType = puVar38->bldType | bVar16;
              if (uVar23 != 0) {
                pfVar20 = (far_t *)*(far_t **)((char *)0x24751);
              }
              *(uint *)((char *)0x24721) = *(uint *)((char *)0x24721) ^ (uint)pfVar20;
              uVar19 = in(5);
              if (((uint)pfVar20 | 0x606) == 0) {
                *unaff_DI = *unaff_DI +
                            ((CONCAT11((char)(((uint)pfVar20 | 0x606) >> 8),uVar19) + 0x53e) -
                            *unaff_DI);
              }
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            case (far_t *)0xf:
              do {
                uVar53 = (undefined2)((ulong)Entities >> 0x10);
                uVar23 = CONCAT11(uVar68,cVar25) -
                         *(uint16_t *)
                          ((int)&(((entity_t *)Entities)->base).x +
                          CONCAT11((char)((int)pfVar20 % (int)(char)(&stack0x0035)[(int)puVar49]),
                                   (char)((int)pfVar20 / (int)(char)(&stack0x0035)[(int)puVar49])) *
                          iVar29);
                uVar32 = (int)uVar23 >> 0xf;
                uVar22 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b) -
                         ((entity_t *)Entities)[scratch].base.y;
                uVar33 = (int)uVar22 >> 0xf;
                puVar49 = (uint *)((int)((uVar23 ^ uVar32) - uVar32) / 2 +
                                  ((uVar22 ^ uVar33) - uVar33));
                if (puVar49 < uStack_e) {
                  uStack_e =(uint16_t)( puVar49);
                  unaff_DI = (uint *)scratch;
                }
                if (puVar49 < (byte *)__C0_ASM_CopyRight + 6) {
                  piVar4 = (int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x43);
                  *piVar4 = *piVar4 + 1;
                }
                do {
                  while( true ) {
                    scratch = scratch + 1;
                    while (EntityCount <= scratch) {
                      *(undefined2 *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x4b) =(uint16_t)( unaff_DI);
                      uStack_16 =(uint16_t)( (far_t *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_16) + 1)),0xff));
                      if (*(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x40) != '\0') {
                        puStack_10 = (uint *)0xffff;
                        for (scratch = 0; (int)scratch < (int)(uint)GLeaderCount;
                            scratch = scratch + 1) {
                          if ((*(char *)((int)*(undefined4 *)(scratch << 2) + 0x3f) !=
                               *(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3f)) &&
                             (uVar23 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x39) -
                                       *(int *)((int)*(undefined4 *)(scratch << 2) + 0x39),
                             uVar32 = (int)uVar23 >> 0xf,
                             uVar22 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b) -
                                      *(int *)((int)*(undefined4 *)(scratch << 2) + 0x3b),
                             uVar33 = (int)uVar22 >> 0xf,
                             puVar49 = (uint *)((int)((uVar23 ^ uVar32) - uVar32) / 2 +
                                               ((uVar22 ^ uVar33) - uVar33)), puVar49 < puStack_10))
                          {
                            uStack_16 =(uint16_t)( (far_t *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_16) + 1)),(char)scratch));
                            puStack_10 = puVar49;
                          }
                        }
                      }
                      *(undefined1 *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x49) =
                           (undefined1)uStack_16;
                      do {
                        puStack_a = (uint *)((int)puStack_a + 1);
                        if ((int)(uint)GLeaderCount <= (int)puStack_a) {
                          for (puStack_a = (uint *)0x0; pfVar20 = (far_t *)(uint)GLeaderCount,
                              (int)puStack_a < (int)pfVar20;
                              puStack_a = (uint *)((int)puStack_a + 1)) {
                            if ((*(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x40) != '\0'
                                ) && (*(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3d) !=
                                      '\0')) {
                              ovc25_intelAttackingNotice((byte)puStack_a);
                              if (*(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x4b) == -1)
                              {
                                uStack_14 =(uint16_t)( (far_t *)0xffff);
                              }
                              else {
                                unaff_DI = (uint *)*(undefined2 *)
                                                    ((int)*(undefined4 *)((int)puStack_a << 2) +
                                                    0x4b);
                                uVar53 = (undefined2)((ulong)Entities >> 0x10);
                                uVar23 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x39)
                                         - (((entity_t *)Entities + (int)unaff_DI)->base).x;
                                uVar32 = (int)uVar23 >> 0xf;
                                uVar22 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b)
                                         - ((entity_t *)Entities)[(int)unaff_DI].base.y;
                                uVar33 = (int)uVar22 >> 0xf;
                                uStack_14 =(uint16_t)( (far_t *)((int)((uVar23 ^ uVar32) - uVar32) / 2 +
                                                     ((uVar22 ^ uVar33) - uVar33)));
                              }
                              if ((*(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x43) == 0)
                                 || ((byte *)__C0_ASM_CopyRight + 6 <= uStack_14)) {
                                if ((*(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x49) ==
                                     -1) || ((*(byte *)((int)*(undefined4 *)((int)puStack_a << 2) +
                                                       0x5d) & 1) == 0)) {
                                  if (*(uint *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x47) <
                                      10) {
                                    ovc25_usesAlignUp43((byte)puStack_a,10,
                                                        *(uint16_t *)
                                                         ((int)*(undefined4 *)((int)puStack_a << 2)
                                                         + 0x39),*(uint16_t *)
                                                                  ((int)*(undefined4 *)
                                                                         ((int)puStack_a << 2) +
                                                                  0x3b),'\0');
                                    *(undefined1 *)
                                     ((int)*(undefined4 *)((int)puStack_a << 2) + 0x4a) = 0;
                                  }
                                  else {
                                    *(undefined1 *)
                                     ((int)*(undefined4 *)((int)puStack_a << 2) + 0x4a) = 0;
                                    bVar17 = *(byte *)((int)*(undefined4 *)((int)puStack_a << 2) +
                                                      0x3e);
                                    uStack_18 = CONCAT11(bVar17,(undefined1)uStack_18);
                                    iVar30 = ovc25_compute1(bVar17);
                                    uStack_6 = (far_t *)CONCAT22(iVar30,(far_t *)uStack_6);
                                    if ((int)(uint)PlayerCount < iVar30) {
                                      uVar31 = ovr_randBelow(0x28);
                                      pfVar20 = (far_t *)(*(int *)((int)*(undefined4 *)
                                                                         ((int)puStack_a << 2) +
                                                                  0x39) + -0x14 + (uVar31 & 0xff));
                                      (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)( pfVar20);
                                      if ((int)pfVar20 < 4) {
                                        (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)( (far_t *)__C0_ASM_CopyRight);
                                      }
                                      if (0x8c < (int)(far_t *)uStack_6) {
                                        (*(uint16_t *)((uint8_t *)&(uStack_6))) =(uint16_t)( (far_t *)&_brklvl);
                                      }
                                      uVar31 = ovr_randBelow(0x14);
                                      uStack_8 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2)
                                                         + 0x3b) + -10 + (uVar31 & 0xff);
                                      if ((int)uStack_8 < 1) {
                                        uStack_8 = 1;
                                      }
                                      if (0x3a < (int)uStack_8) {
                                        uStack_8 = 0x3a;
                                      }
                                      ovc25_usesAlignUp44((char)puStack_a,1);
                                    }
                                  }
                                }
                                else {
                                  ovc25_usesEntityCount((byte)puStack_a);
                                  bVar17 = *(byte *)((int)*(undefined4 *)((int)puStack_a << 2) +
                                                    0x49);
                                  uStack_16 =(uint16_t)( (far_t *)CONCAT11(bVar17,(undefined1)uStack_16));
                                  if (0xe < *(uint *)((int)*(undefined4 *)((int)puStack_a << 2) +
                                                     0x47)) {
                                    ovc25_usesAlignUp42((byte)puStack_a,10,
                                                        *(uint16_t *)
                                                         ((int)*(undefined4 *)((uint)bVar17 << 2) +
                                                         0x39),*(uint16_t *)
                                                                ((int)*(undefined4 *)
                                                                       ((uint)bVar17 << 2) + 0x3b),
                                                        *(uint16_t *)
                                                         ((int)*(undefined4 *)((int)puStack_a << 2)
                                                         + 0x39),*(uint16_t *)
                                                                  ((int)*(undefined4 *)
                                                                         ((int)puStack_a << 2) +
                                                                  0x3b));
                                    if (*(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x4a)
                                        != '\x02') {
                                      uVar11 = *(undefined4 *)(((uint)uStack_16 >> 8) << 2);
                                      ovr_alignUp4(*(int *)((int)uVar11 + 0x39));
                                      uStackY_60 = 0xc5d4;
                                      pcVar21 = ovr_stsprintf(acStackY_68,
                                                              (char *)CONCAT13(0x58,CONCAT12(0xc0,
                                                  unaff_SS)));
                                      ovr_uiNotify(pcVar21);
                                    }
                                  }
                                  ovc25_usesAlignUp43((byte)puStack_a,0xf,
                                                      *(uint16_t *)
                                                       ((int)*(undefined4 *)((int)puStack_a << 2) +
                                                       0x39),*(uint16_t *)
                                                              ((int)*(undefined4 *)
                                                                     ((int)puStack_a << 2) + 0x3b),
                                                      '\0');
                                  *(undefined1 *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x4a)
                                       = 2;
                                }
                              }
                              else {
                                ovc25_usesEntityCount((byte)puStack_a);
                                if (9 < *(uint *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x47))
                                {
                                  uVar53 = (undefined2)((ulong)Entities >> 0x10);
                                  ovc25_usesAlignUp43((byte)puStack_a,5,
                                                      (((entity_t *)Entities + (int)unaff_DI)->base
                                                      ).x,((entity_t *)Entities)[(int)unaff_DI].
                                                          base.y,'\x01');
                                }
                                ovc25_usesAlignUp43((byte)puStack_a,10,
                                                    *(uint16_t *)
                                                     ((int)*(undefined4 *)((int)puStack_a << 2) +
                                                     0x39),*(uint16_t *)
                                                            ((int)*(undefined4 *)
                                                                   ((int)puStack_a << 2) + 0x3b),
                                                    '\0');
                                *(undefined1 *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x4a) =
                                     1;
                              }
                            }
                          }
                          ovc25_clearEntityFlags();
                          return pfVar20;
                        }
                      } while (*(char *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x3d) == '\0');
                      *(undefined2 *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x47) = 0;
                      *(undefined2 *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x41) = 0;
                      *(undefined2 *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x43) = 0;
                      *(undefined2 *)((int)*(undefined4 *)((int)puStack_a * 4) + 0x45) = 0;
                      uStack_e =(uint16_t)( (uint *)0xffff);
                      unaff_DI = (uint *)0xffff;
                      puStack_12 = (uint *)ovr_alignUp4(*(int *)((int)*(undefined4 *)
                                                                       ((int)puStack_a * 4) + 0x39))
                      ;
                      scratch = 0;
                    }
                    uVar53 = (undefined2)((ulong)Entities >> 0x10);
                    peVar41 = (entity_t *)Entities;
                    if ((uint *)(uint)*(byte *)((int)&peVar41[scratch].base.entity + 3) != puStack_a
                       ) break;
                    uVar23 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x39) -
                             ((peVar41 + scratch)->base).x;
                    uVar32 = (int)uVar23 >> 0xf;
                    uVar22 = *(int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b) -
                             peVar41[scratch].base.y;
                    uVar33 = (int)uVar22 >> 0xf;
                    puVar49 = (uint *)((int)((uVar23 ^ uVar32) - uVar32) / 2 +
                                      ((uVar22 ^ uVar33) - uVar33));
                    piVar4 = (int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x45);
                    *piVar4 = *piVar4 + 1;
                    if (puVar49 < (byte *)__C0_ASM_CopyRight + 6) {
                      piVar4 = (int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x41);
                      *piVar4 = *piVar4 + 1;
                      uVar53 = (undefined2)((ulong)Entities >> 0x10);
                      if ((*(uint16_t *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3b) ==
                           ((entity_t *)Entities)[scratch].base.y) &&
                         (puVar50 = (uint *)ovr_alignUp4((((entity_t *)Entities + scratch)->base).x
                                                        ), puVar50 == puStack_12)) {
                        piVar4 = (int *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x47);
                        *piVar4 = *piVar4 + 1;
                      }
                    }
                  }
                } while (*(char *)((int)(char **)GMenuStrings +
                                  (uint)peVar41[scratch].base.gindex * 0x95 + 0x1f) ==
                         *(char *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x3f));
                uVar53 = *(undefined2 *)((int)*(undefined4 *)((int)puStack_a << 2) + 0x39);
                cVar25 = (char)uVar53;
                uVar68 = (undefined1)((uint)uVar53 >> 8);
                iVar29 = 0x37;
                pfVar20 = (far_t *)scratch;
              } while( true );
            case (far_t *)0x10:
              puVar28 = &unitNameOfs;
              manage_applyUnitFilter
                        (partyIndex,((uint)uStack_e >> 8) - 4,
                         (char *)CONCAT13((char)((uint)*(undefined2 *)
                                                        (acStackY_68 + ((uint)pfVar20 & 0xff) * 4)
                                                >> 8),
                                          CONCAT12((char)*(undefined2 *)
                                                          (acStackY_68 + ((uint)pfVar20 & 0xff) * 4)
                                                   ,puVar28[((uint)pfVar20 & 0xff) * 2])));
              cVar25 = (char)uVar23;
L_OVC22_5087_0234_32B8:
              CurSfxType3 = 0x3c;
              (*(uint8_t *)((uint8_t *)&(entries.seg))) = cVar14;
              entries.ofs = (uint16_t)(acStackY_68 + 2);
              (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar65;
              uVar53 = ovr_ovc28_usesUiInputText(entries);
              cVar14 = (char)uVar53;
              uStack_e =(uint16_t)( (uint *)CONCAT11(cVar14,(byte)uStack_e));
              keyboardInputMode = 0;
              if (((cVar14 != '\0') && (cVar14 != '\x01')) && (cVar14 != -2)) {
                (&stack0xbac4)[(int)unaff_DI] = (&stack0xbac4)[(int)unaff_DI] + cVar25;
                puVar50 = (uint *)((char *)0x26510);
                do {
                  iVar30 = (int)puVar50 * (int)puVar28;
                  puVar50 = puVar49;
                  if (*(byte *)((int)puVar49 * 0x34 + 0x22) < *(byte *)(iVar30 + 0x21)) {
                    *(undefined1 *)((int)puVar49 * 0x34 + 0x21) =
                         *(undefined1 *)((int)puVar49 * 0x34 + 0x22);
                  }
                  do {
                    puVar50 = (uint *)((int)puVar50 + 1);
                    if ((int)(uint)AgntCount <= (int)puVar50) {
                      iVar30 = ovr_audio_panFromX((agnt_t *)CONCAT11(uStack0009,bStack0008));
                      uVar19 = (undefined1)((uint)iVar30 >> 8);
                      ovr_play_sfxU(0x1c);
                      return (far_t *)CONCAT11(uVar19,1);
                    }
                  } while (*(int *)((int)puVar50 * 0x34 + 0x1b) !=
                           *(int *)(CONCAT11(uStack0009,bStack0008) + 0x1b));
                  uVar53 = (undefined2)((ulong)uStack_6 >> 0x10);
                  if ((byte)((far_t *)uStack_6)[0xc].seg < *(byte *)((int)puVar50 * 0x34 + 0x22)) {
                    *(undefined1 *)((int)puVar50 * 0x34 + 0x22) = (char)((far_t *)uStack_6)[0xc].seg
                    ;
                  }
                  puVar28 = (uint16_t *)((char *)0x24134);
                  puVar49 = puVar50;
                } while( true );
              }
              if (cVar14 != -2) {
                keyboardInputMode = 0;
                return (far_t *)((char *)0x26510);
              }
              Cancelled = 1;
              keyboardInputMode = 0;
              return (far_t *)((char *)0x26510);
            case (far_t *)0x11:
              GRecordCount = GRecordCount + -1;
              _fmemset((void *)0x21f2,0x12,in_stack_0000ffbe);
              *(byte *)(GRecordCount * 0x12 + 8) = partyIndex;
              *(uint16_t *)(GRecordCount * 0x12 + 2) = (uint16_t)bStack0006;
              *(undefined2 *)(GRecordCount * 0x12 + 4) = CONCAT11(uStack0009,bStack0008);
              *(byte *)(GRecordCount * 0x12 + 9) = in_stack_0000000e;
              iVar30 = ovc23_isLargeBuilding((int)bStack0006,CONCAT11(uStack0009,bStack0008));
              uVar54 = (undefined2)((ulong)GUnitGrid >> 0x10);
              uVar53 = (undefined2)((ulong)GUnits >> 0x10);
              if ((char)iVar30 == '\0') {
                bVar17 = ((unit_t *)GUnits +
                         (*(short (*) [148] [60])GUnitGrid)[(int)bStack0006]
                         [CONCAT11(uStack0009,bStack0008)])->bldType;
              }
              else {
                bVar17 = ((unit_t *)GUnits +
                         (*(short (*) [148] [60])GUnitGrid)[(int)((int)&bStack0006[-1].seg + 1)]
                         [CONCAT11(uStack0009,bStack0008)])->bldType;
              }
              cVar25 = *(char *)((uint)bVar17 * 0x27 + 0x11d);
              (*(uint32_t *)((uint8_t *)&(uStack_6))) =
                   CONCAT12(*(undefined1 *)((uint)bVar17 * 0x27 + 0x11b),
                            CONCAT11(bVar17,(byte)uStack_6));
              uStack_6 = (far_t *)CONCAT13(cVar25,(uint3)uStack_6);
              if (cVar25 == '\0') {
                uStack_6 = (far_t *)CONCAT13(1,(uint3)uStack_6);
              }
              if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) < *(byte *)((uint)partyIndex * 0x27 + 0x11c)) {
                *(undefined1 *)(GRecordCount * 0x12 + 6) =
                     *(undefined1 *)((uint)partyIndex * 0x27 + 0x11c);
              }
              else {
                *(byte *)(GRecordCount * 0x12 + 6) = (*(uint8_t *)((uint8_t *)&(uStack_6) + 3));
              }
              *(undefined2 *)(GRecordCount * 0x12 + 0xf) = GameTick;
              *(undefined2 *)(GRecordCount * 0x12) = 0;
              uVar53 = ovc23_usesGRecordCount3
                                 (*(byte *)((uint)partyIndex * 0x27 + 0x120),in_stack_0000000e,
                                  GRecordCount);
              *(undefined1 *)(GRecordCount * 0x12 + 0xc) = (char)uVar53;
              if (*(char *)(GRecordCount * 0x12 + 0xc) == '\0') {
                *(undefined1 *)(GRecordCount * 0x12 + 0xc) = 1;
              }
              if (partyIndex == 0) {
                iVar30 = ovc23_isLargeBuilding((int)bStack0006,CONCAT11(uStack0009,bStack0008));
                if ((char)iVar30 != '\0') {
                  piVar4 = (int *)(GRecordCount * 0x12 + 2);
                  *piVar4 = *piVar4 + -1;
                }
                *(undefined1 *)(GRecordCount * 0x12 + 7) = (*(uint8_t *)((uint8_t *)&(uStack_6) + 2));
                if (in_stack_00000010 == '\x01') {
                  *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 1;
                }
                else {
                  *(char *)(GRecordCount * 0x12 + 0xc) = in_stack_00000010;
                  *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 0;
                }
                pbVar2 = (byte *)(GRecordCount * 0x12 + 0xd);
                *pbVar2 = *pbVar2 | 3;
              }
              else {
                *(undefined1 *)(GRecordCount * 0x12 + 7) =
                     *(undefined1 *)((uint)partyIndex * 0x27 + 0x11b);
                if (in_stack_00000010 != '\0') {
                  ovc23_placeBuilding((int)bStack0006);
                  uVar53 = ovr_ovc22_usesGOngoingBattle(bStack0006,bStack0008);
                  if ((char)uVar53 != '\0') {
                    *(undefined1 *)CONCAT22(in_stack_0000000c,in_stack_0000000a) = 1;
                  }
                }
                *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 0;
              }
              *(undefined1 *)(GRecordCount * 0x12 + 0x11) = 0;
              *(undefined1 *)(GRecordCount * 0x12 + 0xb) =
                   *(undefined1 *)(GRecordCount * 0x12 + 0xc);
              iVar30 = GRecordCount;
              GRecordCount = GRecordCount + 1;
              ovc23_abandonConstruction(iVar30);
              pfVar20 = (far_t *)ovc23_textAdlibNone(in_stack_0000ffbe,in_stack_0000ffc0,
                                                     in_stack_0000ffc2);
              return pfVar20;
            case (far_t *)0x12:
              GRecordCount = GRecordCount + -1;
              pfVar20 = (far_t *)ovc23_textAdlibNone(CONCAT11(uVar68,cVar25),unaff_SI);
              return pfVar20;
            case (far_t *)0x15:
              iVar30 = (uint)*(byte *)((int)&pfVar20[3].ofs + (int)ovrAuxSlot + 1) * 0x95;
              uVar31 = 0x195d;
              uVar53 = *(undefined2 *)((int)&worldMenuLabels[1].ofs + 1 + iVar30);
              pcVar21 = ovr_fmVsprintf("Intelligence reports %s unit infected with disease. (%d, %d)"
                                       ,(char *)CONCAT13((char)((uint)uVar53 >> 8),
                                                         CONCAT12((char)uVar53,
                                                                  *(undefined2 *)
                                                                   ((int)&worldMenuLabels[0].seg + 1
                                                                   + iVar30))));
              ovr_uiNotify(pcVar21,uVar31);
              uVar53 = (undefined2)((ulong)Entities >> 0x10);
              pfVar20 = (far_t *)((uint)((entity_t *)Entities)[(int)puStack_a].base.gindex * 0x95);
              if (((pfVar20 + 0x9c5)->ofs & 0xc00) != 0) {
                uVar23 = ovr_ovc27_rollToHitAgent
                                   ((uint32_t)CONCAT22(uVar53,(entity_t *)Entities + (int)unaff_DI)
                                    ,3);
                pfVar20 = (far_t *)(uVar23 & 0xff);
                if (pfVar20 == (far_t *)0x0) {
                  uVar53 = (undefined2)((ulong)Entities >> 0x10);
                  if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                                (uint)((entity_t *)Entities)[(int)puStack_a].base.gindex * 0x95) &
                      0x800) == 0) {
                    puStack_12 = (uint *)CONCAT11((*(uint8_t *)((uint8_t *)&(puStack_12) + 1)),1);
                  }
                  else {
                    puStack_12 = (uint *)CONCAT11((*(uint8_t *)((uint8_t *)&(puStack_12) + 1)),2);
                  }
                  uVar53 = ovr_ovc27_compute3((uint32_t)
                                              CONCAT22(uVar53,(entity_t *)Entities + (int)unaff_DI)
                                              ,(char)puStack_12);
                  if ((char)uVar53 != '\0') {
                    if (DebugVerbose != false) {
                      printf("kill 3\r");
                    }
                    uVar53 = (undefined2)((ulong)Entities >> 0x10);
                    if (((entity_t *)Entities)[(int)unaff_DI].base.animFrame != 0x0) {
                      puVar5 = &((entity_t *)Entities)[(int)unaff_DI].base.animFrame;
                      *puVar5 = *puVar5 + 0xff;
                    }
                  }
                  alignUp4((((entity_t *)Entities + (int)puVar49)->base).x);
                  iVar30 = (uint)((entity_t *)Entities)[(int)unaff_DI].base.gindex * 0x95;
                  uVar31 = 0x195d;
                  uVar53 = *(undefined2 *)((int)&worldMenuLabels[1].ofs + 1 + iVar30);
                  pfVar20 = (far_t *)ovr_fmVsprintf(
                                                  "Intelligence reports %s unit drained of energy. (%d, %d)"
                                                  ,(char *)CONCAT13((char)((uint)uVar53 >> 8),
                                                                    CONCAT12((char)uVar53,
                                                                             *(undefined2 *)
                                                                              ((int)&worldMenuLabels
                                                                                     [0].seg + 1 +
                                                                              iVar30))));
                  ovr_uiNotify((char *)pfVar20,uVar31);
                }
              }
              return pfVar20;
            }
            do {
              uVar53 = *(undefined2 *)((int)(undefined2 *)&tmstrsSprites3Seg + iVar29);
              (*(uint8_t *)((uint8_t *)&(gfx_05.seg))) = (char)uVar53;
              gfx_05.ofs = *(undefined2 *)((int)(undefined2 *)&tmstrsSprites3Ofs + iVar29);
              (*(uint8_t *)((uint8_t *)&(gfx_05.seg) + 1)) = (char)((uint)uVar53 >> 8);
              ovr_blitGfxRect(gfx_05);
              (*(uint8_t *)((uint8_t *)&(gfx_06.seg))) = (char)((undefined2 *)&tmstrsSprites3Seg)[((uint)unaff_DI % 7) * 2];
              gfx_06.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[((uint)unaff_DI % 7) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_06.seg) + 1)) =
                   (char)((uint)((undefined2 *)&tmstrsSprites3Seg)[((uint)unaff_DI % 7) * 2] >> 8);
              ovr_blitGfxRect(gfx_06);
              (*(uint8_t *)((uint8_t *)&(gfx_07.seg))) =
                   (char)((undefined2 *)&tmstrsSprites3Seg)[((uint)(unaff_DI + 1) % 7) * 2];
              gfx_07.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[((uint)(unaff_DI + 1) % 7) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_07.seg) + 1)) =
                   (char)((uint)((undefined2 *)&tmstrsSprites3Seg)[((uint)(unaff_DI + 1) % 7) * 2]
                         >> 8);
              ovr_blitGfxRect(gfx_07);
              uVar23 = (uint)((int)unaff_DI + 3) & 7;
              (*(uint8_t *)((uint8_t *)&(gfx_08.seg))) = (char)((undefined2 *)&tmstrsSprites2Seg)[uVar23 * 2];
              gfx_08.ofs = ((undefined2 *)&tmstrsSprites2Ofs)[uVar23 * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_08.seg) + 1)) = (char)((uint)((undefined2 *)&tmstrsSprites2Seg)[uVar23 * 2] >> 8);
              ovr_blitGfxRect(gfx_08);
              (*(uint8_t *)((uint8_t *)&(gfx_09.seg))) = (char)((undefined2 *)&tmstrsSprites2Seg)[((uint)unaff_DI & 7) * 2];
              gfx_09.ofs = ((undefined2 *)&tmstrsSprites2Ofs)[((uint)unaff_DI & 7) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_09.seg) + 1)) =
                   (char)((uint)((undefined2 *)&tmstrsSprites2Seg)[((uint)unaff_DI & 7) * 2] >> 8);
              ovr_blitGfxRect(gfx_09);
              (*(uint8_t *)((uint8_t *)&(gfx_10.seg))) = (char)((undefined2 *)&tmstrsSprites1Seg)[((uint)unaff_DI % 5) * 2];
              gfx_10.ofs = ((undefined2 *)&tmstrsSprites1Ofs)[((uint)unaff_DI % 5) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_10.seg) + 1)) =
                   (char)((uint)((undefined2 *)&tmstrsSprites1Seg)[((uint)unaff_DI % 5) * 2] >> 8);
              ovr_blitGfxRect(gfx_10);
              pfVar20 = (far_t *)((char *)0x26510);
              (*(uint8_t *)((uint8_t *)&(gfx_11.seg))) = (char)((undefined2 *)&tmstrsSprites1Seg)[((uint)unaff_DI % 5) * 2];
              gfx_11.ofs = ((undefined2 *)&tmstrsSprites1Ofs)[((uint)unaff_DI % 5) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_11.seg) + 1)) =
                   (char)((uint)((undefined2 *)&tmstrsSprites1Seg)[((uint)unaff_DI % 5) * 2] >> 8);
              ovr_blitGfxRect(gfx_11);
              while( true ) {
                while( true ) {
                  scratch = scratch - 1;
                  if ((int)scratch < 0) {
                    return pfVar20;
                  }
                  pcVar21 = (char *)(scratch + GfxRndSeed2 + ((uint)unaff_DI >> 5));
                  puStack_a = (uint *)((int)puStack_a + 0x13);
                  if (((*(uint8_t *)((uint8_t *)&(uStack_14) + 1)) == 2) || ((byte *)__C0_ASM_CopyRight + 0xf < unaff_DI))
                  break;
                  if (((char *)((int)puStack_12 + -1) == (char *)scratch) &&
                     (unaff_DI <= (byte *)__C0_ASM_CopyRight + 8)) {
                    uStack_8 = ((undefined2 *)&csite1Ofs)[(int)unaff_DI * 2];
                    pfVar20 = (far_t *)((undefined2 *)&csite1Seg)[(int)unaff_DI * 2];
                  }
                  else {
                    uStack_8 = csite1_12Ofs;
                    pfVar20 = csite1_12Seg;
                  }
                  uStack_6 = (far_t *)CONCAT22(pcVar21,pfVar20);
                  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)pfVar20;
                  gfx.ofs = uStack_8;
                  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)pfVar20 >> 8);
                  ovr_blitGfxRect(gfx);
                }
                if ((*(uint8_t *)((uint8_t *)&(uStack_14) + 1)) < 2) break;
                if ((byte *)__C0_ASM_CopyRight + 5 < unaff_DI) {
                  uStack_8 = csite1_22Ofs;
                  pfVar20 = csite1_22Seg;
                }
                else {
                  uStack_8 = ((undefined2 *)&csite1Ofs)[(int)(unaff_DI + 6) * 2];
                  pfVar20 = (far_t *)((undefined2 *)&csite1Seg)[(int)(unaff_DI + 6) * 2];
                }
                uStack_6 = (far_t *)CONCAT22(pcVar21,pfVar20);
                (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)pfVar20;
                gfx_00.ofs = uStack_8;
                (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)pfVar20 >> 8);
                ovr_blitGfxRect(gfx_00);
              }
              uStack_6 = (far_t *)CONCAT22(pcVar21,csite1_12Seg);
              uStack_8 = csite1_12Ofs;
              if ((char *)scratch == (char *)0x0) {
                uVar23 = (uint)((int)unaff_DI + GfxRndSeed2) % 0xe;
                (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = (char)((undefined2 *)&tmstrsSprites6Seg)[uVar23 * 2];
                gfx_01.ofs = ((undefined2 *)&tmstrsSprites6Ofs)[uVar23 * 2];
                (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = (char)((uint)((undefined2 *)&tmstrsSprites6Seg)[uVar23 * 2] >> 8)
                ;
                ovr_blitGfxRect(gfx_01);
              }
              (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)uStack_6;
              gfx_02.ofs = uStack_8;
              (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = (char)((ulong)uStack_6 >> 8);
              ovr_blitGfxRect(gfx_02);
              if (((uint)((char *)((int)unaff_DI + GfxRndSeed2 + scratch) + (int)puVar49) & 0x1f) <
                  0x11) {
                uVar23 = ((uint)((char *)((int)unaff_DI + GfxRndSeed2 + scratch) + (int)puVar49) >>
                         5) + scratch + GfxRndSeed2;
                uStack_6 = (far_t *)CONCAT22(uVar23,(far_t *)uStack_6);
                uStack_e = (uint *)((int)((uint)*(byte *)(uVar23 & 0xff) * 0x25) >> 8);
                uVar23 = (uint)((char *)((int)unaff_DI + GfxRndSeed2 + scratch) + (int)puVar49) &
                         0x1f;
                (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = (char)((undefined2 *)&tmstrsSprites5Seg)[uVar23 * 2];
                gfx_03.ofs = ((undefined2 *)&tmstrsSprites5Ofs)[uVar23 * 2];
                (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) = (char)((uint)((undefined2 *)&tmstrsSprites5Seg)[uVar23 * 2] >> 8)
                ;
                ovr_blitGfxRect(gfx_03);
              }
              if (((uint)((int)unaff_DI + ((scratch - GfxRndSeed2) - (int)puVar49)) & 0xf) < 7) {
                iVar30 = (((uint)((int)unaff_DI + ((scratch - GfxRndSeed2) - (int)puVar49)) >> 4) +
                         scratch) - GfxRndSeed2;
                uStack_6 = (far_t *)CONCAT22(iVar30,(far_t *)uStack_6);
                uStack_e = (uint *)((int)((uint)*(byte *)(iVar30 + 0xeU & 0xff) * 0x25) >> 8);
                uVar23 = (uint)((int)unaff_DI + ((scratch - GfxRndSeed2) - (int)puVar49)) & 0xf;
                (*(uint8_t *)((uint8_t *)&(gfx_04.seg))) = (char)((undefined2 *)&tmstrsSprites4Seg)[uVar23 * 2];
                gfx_04.ofs = ((undefined2 *)&tmstrsSprites4Ofs)[uVar23 * 2];
                (*(uint8_t *)((uint8_t *)&(gfx_04.seg) + 1)) = (char)((uint)((undefined2 *)&tmstrsSprites4Seg)[uVar23 * 2] >> 8)
                ;
                ovr_blitGfxRect(gfx_04);
              }
              iVar29 = (uint)((int)unaff_DI + 5) % 7 << 2;
            } while( true );
          }
          if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) == '\x13') {
            uVar22 = *(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x12a);
            bVar58 = CARRY2(uStack_38,uVar22);
            uStack_38 = uStack_38 + uVar22;
            iStack_36 = iStack_36 + (uint)bVar58;
          }
          else {
            uVar22 = *(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x12a);
            bVar58 = CARRY2(uStack_34,uVar22);
            uStack_34 = uStack_34 + uVar22;
            resourceTotals[0] = resourceTotals[0] + (uint)bVar58;
          }
          if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) == '\x1d') {
            if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 2)) == '\0') {
              resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131)] =
                   resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131)] +
                   (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129);
            }
          }
          else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) == '\x10') {
            if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 2)) != '\0') {
              resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131)] =
                   resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131)] +
                   (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129);
            }
          }
          else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129) != '\0') {
            if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) == '\r') {
              if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) != '\0') {
                resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) + 3] =
                     resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) + 3] +
                     (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129);
              }
            }
            else {
              resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) + 3] =
                   resourceTotals[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) + 3] +
                   (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129);
            }
          }
          iStack_22 = iStack_22 + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x127);
          if (0xf7 < (int)puVar49) {
            pcVar21 = ovc22_textPOPULATION((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),partyIndex);
            uStack_20 = uStack_20 + (int)pcVar21;
            uVar22 = ovc22_seasonalIncome((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),partyIndex);
            iVar30 = iVar30 + uVar22;
          }
          if (((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x121) & 1) != 0) &&
             (((*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x2f) == -1 ||
               (bVar17 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x2f),
               uVar23 = CONCAT11((char)(uVar23 >> 8),bVar17),
               (1 << (bVar17 & 0x1f) & (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x11f)) != 0))
              && (*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) < 4)))) {
            *(int *)(&stack0xffbc + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) * 2) =
                 *(int *)(&stack0xffbc + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) * 2)
                 + 1;
          }
          if ((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x121) & 0x200) != 0) {
            iStack_3c = iStack_3c + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131);
          }
        }
      }
    }
    for (uStack_14 = (far_t *)0x0; uStack_14 < EntityCount;
        uStack_14 = (far_t *)((int)&uStack_14->ofs + 1)) {
      uVar53 = (undefined2)((ulong)Entities >> 0x10);
      if (*(byte *)((int)&((entity_t *)Entities)[(int)uStack_14].base.entity + 3) == partyIndex) {
        uStack_1e = uStack_1e + ((entity_t *)Entities)[(int)uStack_14].base.animFrame;
      }
    }
    bStack_1b = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xad);
    for (iVar29 = 2; -1 < iVar29; iVar29 = iVar29 + -1) {
      if (bStack_1b < *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + iVar29 + 0xaa)) {
        *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + iVar29 + 0xaa) = bStack_1b;
        bStack_1b = 0;
      }
      else {
        bStack_1b = bStack_1b -
                    *(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + iVar29 + 0xaa);
      }
    }
    iVar29 = 0;
    for (iVar52 = 0; iVar52 < 3; iVar52 = iVar52 + 1) {
      iVar29 = iVar29 + (uint)*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + iVar52 + 0xaa)
                        * (iVar52 + 1) * 3;
    }
    if (iVar29 < 0x32) {
      *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xaa) = (char)iVar29;
    }
    else {
      *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0xaa) = 0x32;
    }
    *(uint16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x94) = scratch;
    *(undefined2 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x96) = puStack_a;
    *(uint16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x98) = uStack_8;
    uStack_24 = in_stack_0000ffbe;
    if (5 < in_stack_0000ffbe) {
      uStack_24 = 5;
    }
    if (in_stack_0000ffc0 + uStack_24 < 0xb) {
      uStack_24 = uStack_24 + in_stack_0000ffc0;
    }
    else {
      uStack_24 = 10;
    }
    uStack_24 = (int)&in_stack_0000ffc2->x + uStack_24;
    if (in_stack_0000ffc2 == (agnt_t *)0x0) {
      if (in_stack_0000ffc0 == 0) {
        if (in_stack_0000ffbe == 0) {
          *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x53) = 4;
        }
        else {
          *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x53) = 8;
        }
      }
      else {
        *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x53) = 0xc;
      }
    }
    else {
      *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x53) = 0xff;
    }
    *(undefined2 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x82) = 0;
    if ((resourceTotals[0] < 0) || (resourceTotals[0] < 1)) {
      uVar53 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
      iVar29 = (int)*(undefined4 *)((uint)partyIndex << 2);
      *(int16_t *)(iVar29 + 0x80) = resourceTotals[0];
      *(uint *)(iVar29 + 0x7e) = uStack_34;
    }
    else {
      uVar53 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
      iVar29 = (int)*(undefined4 *)((uint)partyIndex << 2);
      *(undefined2 *)(iVar29 + 0x80) = 0;
      *(undefined2 *)(iVar29 + 0x7e) = 0xffff;
    }
    *(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5b) = iStack_22;
    *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d) = uStack_1e;
    *(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4f) = (int)uStack_20;
    *(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x54) = iVar30;
    uVar53 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
    iVar30 = (int)*(undefined4 *)((uint)partyIndex << 2);
    *(int *)(iVar30 + 0x8c) = iStack_36;
    *(uint *)(iVar30 + 0x8a) = uStack_38;
    *(int16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 100) = animStep;
    *(undefined2 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x66) = uStack_28;
    *(undefined2 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x68) = uStack_26;
    *(int16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x70) = resourceTotals[1];
    *(int16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x72) = resourceTotals[2];
    *(int16_t *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x74) = resourceTotals[3];
    *(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x87) = iStack_3c;
    if (uStack_24 < 0x100) {
      *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x52) = (undefined1)uStack_24;
    }
    else {
      *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x52) = 0xff;
    }
    uVar23 = ovr_ovc36_usesLDIV_at_(partyIndex);
    *(undefined1 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x84) = (char)uVar23;
    in_AX = (far_t *)ovc22_usesPlayerCount(partyIndex);
  }
  return in_AX;
switchD_5000_123d_caseD_2:
  do {
    bVar17 = ((entity_t *)Entities)[(int)puVar49].base.gindex;
    uStack_6 = (far_t *)CONCAT13(bVar17,(uint3)uStack_6);
    pfVar20 = (far_t *)(uint)*(byte *)((int)(char **)GMenuStrings + (uint)bVar17 * 0x95 + 0x1f);
    if (pfVar20 == (far_t *)0x0) {
      ovr_ovc15_capitalize(acStackY_a6);
      uStackY_60 = 0x2322;
      uStackY_62 = 0x8f4e;
      pfVar20 = (far_t *)ovr_stsprintf(&stack0xffaa,(char *)CONCAT22(0x5665,unaff_SS));
      ovr_uiNotify((char *)pfVar20);
    }
    ovr_ovc15_removeEntity((uint)puVar49);
    while( true ) {
      do {
        puVar49 = (uint *)((int)puVar49 + -1);
        if ((int)puVar49 < 0) {
          return pfVar20;
        }
        pfVar20 = (far_t *)((int)puVar49 * 0x37);
        uVar53 = (undefined2)((ulong)Entities >> 0x10);
      } while (((uint *)(((entity_t *)Entities + (int)puVar49)->base).x != unaff_DI) ||
              (pfVar20 = (far_t *)((entity_t *)Entities)[(int)puVar49].base.y,
              pfVar20 != bStack0006));
      pfVar20 = (far_t *)ovc23_findClearColumn((int)unaff_DI);
      uStack_6 = (far_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),pfVar20);
      if ((int)pfVar20 < 0) break;
      (((entity_t *)Entities + (int)puVar49)->base).x = (uint16_t)pfVar20;
    }
  } while( true );
switchD_5000_123d_caseD_3:
  while( true ) {
    if ((puVar38->flags & 3) == 0) {
      uVar53 = (undefined2)((ulong)GUnits >> 0x10);
      bVar17 = ((unit_t *)GUnits)[(int)unaff_DI].unitType;
      if ((bVar17 == 0xff) ||
         (uVar11 = *(undefined4 *)((uint)bVar17 << 2), *(char *)((int)uVar11 + 0x3f) == '\0')) {
        uStack_8 = 0x96;
      }
      else {
        uStack_8 = 0x5dc;
      }
      if (((unit_t *)GUnits)[(int)unaff_DI].level != 0) {
        uVar31 = ovr_randBelow(uStack_8);
        uVar53 = (undefined2)((ulong)GUnits >> 0x10);
        puVar37 = (unit_t *)GUnits;
        if ((int)(uVar31 & 0xff) <
            (int)(100 - (uint)*(byte *)((uint)(puVar37 + (int)unaff_DI)->bldType * 0x27 + 0x130))) {
          bVar17 = (puVar37 + (int)unaff_DI)->bldType;
          uStack_20 = (byte *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)),bVar17);
          puVar37[(int)unaff_DI].level = puVar37[(int)unaff_DI].level - 1;
          puVar37 = (unit_t *)GUnits;
          uVar53 = (undefined2)((ulong)GUnits >> 0x10);
          if (((*(uint *)((uint)bVar17 * 0x27 + 0x121) & 4) == 0) &&
             ((puVar37[(int)unaff_DI].level == 0 ||
              ((*(uint *)((uint)bVar17 * 0x27 + 0x121) & 0x200) != 0)))) {
            ovc22_usesGUnits((int)unaff_DI,
                             (uint8_t *)
                             CONCAT13((char)((uint)((int)unaff_DI * 9) >> 8),
                                      CONCAT12(puVar37[(int)unaff_DI].unitType,unaff_SS)));
          }
          else if (((((bld_inst_t *)BldInstances + bVar17)->ofs != 0 ||
                     *(int *)((int)&BldInstances[0].seg + (uint)bVar17 * 0xc) != 0) ||
                   (*(char *)((uint)bVar17 * 0x27 + 0x11e) == '\x10')) &&
                  (uVar53 = ovc22_usesGOngoingBattle2
                                      (*(byte *)&puVar37[(int)unaff_DI].x,
                                       *(byte *)&puVar37[(int)unaff_DI].y), (char)uVar53 != '\0')) {
            cStack_1c = '\x01';
          }
        }
      }
    }
L_upd_units_5087_1d7d_202C:
    unaff_DI = (uint *)((int)unaff_DI + 1);
    if (GUnitCount <= unaff_DI) break;
    uVar54 = (undefined2)((ulong)GUnits >> 0x10);
    puVar38 = (unit_t *)GUnits + (int)unaff_DI;
  }
  GGameState = 0x43;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  for (uStack_16 = (far_t *)0x0; (int)uStack_16 < (int)(uint)GLeaderCount;
      uStack_16 = (far_t *)((int)uStack_16 + 1)) {
    if (*(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3d) != '\0') {
      *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa2) = 0;
      cVar18 = *(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3f);
      if ((cVar18 == '\0') &&
         (*(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f) <
          *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d) >> 1)) {
        bVar58 = true;
      }
      else {
        bVar58 = false;
      }
      uVar23 = *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54);
      uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar29 = *(int *)(iVar29 + 0x58) + ((int)uVar23 >> 0xf) +
               (uint)CARRY2(*(uint *)(iVar29 + 0x56),uVar23);
      if ((iVar29 < 1) && (iVar29 < 0)) {
        puVar49 = (uint *)&GUnitDescriptions[3].ofs;
        while (puVar49 = (uint *)((int)puVar49 + 1), puVar49 < GUnitCount) {
          uVar53 = (undefined2)((ulong)GUnits >> 0x10);
          puVar37 = (unit_t *)GUnits;
          bVar17 = (puVar37 + (int)puVar49)->bldType;
          uStack_20 = (byte *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)),bVar17);
          if (((far_t *)(uint)puVar37[(int)puVar49].unitType == uStack_16) &&
             (*(int *)((uint)bVar17 * 0x27 + 0x123) < 0)) {
            uVar23 = *(uint *)((uint)bVar17 * 0x27 + 0x123);
            uVar54 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
            iVar29 = *(int *)(iVar29 + 0x58) + ((int)uVar23 >> 0xf) +
                     (uint)CARRY2(*(uint *)(iVar29 + 0x56),uVar23);
            if ((iVar29 < 1) && (iVar29 < 0)) {
              if ((cVar18 == '\0') && (puVar37[(int)puVar49].level != 0)) {
                uVar31 = ovr_randBelow(100);
                uVar53 = (undefined2)((ulong)GUnits >> 0x10);
                puVar37 = (unit_t *)GUnits;
                if (*(byte *)((uint)(puVar37 + (int)puVar49)->bldType * 0x27 + 0x130) <=
                    (byte)uVar31) {
                  if (puVar37[(int)puVar49].level != 0) {
                    puVar37[(int)puVar49].level = puVar37[(int)puVar49].level - 1;
                  }
                  puVar37 = (unit_t *)GUnits;
                  uVar53 = (undefined2)((ulong)GUnits >> 0x10);
                  if (((*(uint *)(((uint)uStack_20 & 0xff) * 0x27 + 0x121) & 4) == 0) &&
                     ((iVar29 = 0, puVar37[(int)puVar49].level == 0 ||
                      (iVar29 = ((uint)uStack_20 & 0xff) * 0x27,
                      (*(uint *)(iVar29 + 0x121) & 0x200) != 0)))) {
                    ovc22_usesGUnits((int)puVar49,
                                     (uint8_t *)
                                     CONCAT13((char)((uint)iVar29 >> 8),
                                              CONCAT12((undefined1)uStack_16,unaff_SS)));
                  }
                  else if (((((bld_inst_t *)BldInstances + ((uint)uStack_20 & 0xff))->ofs != 0 ||
                             *(int *)((int)&BldInstances[0].seg + ((uint)uStack_20 & 0xff) * 0xc) !=
                             0) || (*(char *)(((uint)uStack_20 & 0xff) * 0x27 + 0x11e) == '\x10'))
                          && (uVar53 = ovc22_usesGOngoingBattle2
                                                 (*(byte *)&puVar37[(int)puVar49].x,
                                                  *(byte *)&puVar37[(int)puVar49].y),
                             (char)uVar53 != '\0')) {
                    cStack_1c = '\x01';
                  }
                }
              }
            }
            else {
              uVar22 = *(uint *)((uint)bVar17 * 0x27 + 0x123);
              uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
              iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
              puVar3 = (uint *)(iVar29 + 0x56);
              uVar23 = *puVar3;
              *puVar3 = *puVar3 + uVar22;
              piVar4 = (int *)(iVar29 + 0x58);
              *piVar4 = *piVar4 + ((int)uVar22 >> 0xf) + (uint)CARRY2(uVar23,uVar22);
            }
          }
        }
        uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar29 + 0x58) = 0;
        *(undefined2 *)(iVar29 + 0x56) = 0;
      }
      else {
        if ((cVar18 == '\0') && (0 < *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54))) {
          puStack_10 = (uint *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54) / 10);
        }
        else {
          puStack_10 = (uint *)0x0;
        }
        bVar59 = CARRY2((uint)GPopulationLo,(uint)puStack_10);
        GPopulationLo = GPopulationLo + (int)puStack_10;
        GPopulationHi = GPopulationHi + ((int)puStack_10 >> 0xf) + (uint)bVar59;
        uVar22 = *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54) - (int)puStack_10;
        uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar29 + 0x56);
        uVar23 = *puVar3;
        *puVar3 = *puVar3 + uVar22;
        piVar4 = (int *)(iVar29 + 0x58);
        *piVar4 = *piVar4 + ((int)uVar22 >> 0xf) + (uint)CARRY2(uVar23,uVar22);
      }
      if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                    (uint)*(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3e) * 0x95) &
          0x100) == 0) {
        if (*(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f) <
            *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d)) {
          puStack_12 = (uint *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d) -
                               *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f));
          uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar52 = (int)*(undefined4 *)((int)uStack_16 << 2);
          iVar29 = *(int *)(iVar52 + 0x62);
          if ((-1 < iVar29) && ((0 < iVar29 || (*(int *)(iVar52 + 0x60) != 0)))) {
            uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
            uVar23 = *(uint *)(iVar29 + 0x62);
            if ((0x7fff < uVar23) ||
               ((uStack_14 = (far_t *)puStack_12, (int)uVar23 < 1 &&
                ((uint *)*(undefined2 *)(iVar29 + 0x60) <= puStack_12)))) {
              uStack_14 = (far_t *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x60)
              ;
            }
            puStack_12 = (uint *)((int)puStack_12 - (int)uStack_14);
            uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
            piVar4 = (int *)(iVar29 + 0x60);
            puVar49 = (uint *)*piVar4;
            *piVar4 = *piVar4 - (int)uStack_14;
            piVar4 = (int *)(iVar29 + 0x62);
            *piVar4 = *piVar4 - (uint)(puVar49 < uStack_14);
          }
          if (puStack_12 != (uint *)0x0) {
            puStack_a = puStack_12;
            if ((uint *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0) <
                puStack_12) {
              puStack_a = (uint *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0);
            }
            uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
            uVar23 = *(uint *)(iVar29 + 0x58);
            if (((int)uVar23 < 1) &&
               ((0x7fff < uVar23 || ((uint *)*(undefined2 *)(iVar29 + 0x56) < puStack_a)))) {
              puStack_a = (uint *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x56);
            }
            uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
            piVar4 = (int *)(iVar29 + 0x56);
            puVar49 = (uint *)*piVar4;
            *piVar4 = *piVar4 - (int)puStack_a;
            piVar4 = (int *)(iVar29 + 0x58);
            *piVar4 = *piVar4 - (uint)(puVar49 < puStack_a);
            puStack_12 = (uint *)((int)puStack_12 - (int)puStack_a);
            *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa2) = puStack_a;
          }
          if (cVar18 == '\0') {
            for (iVar29 = 0; (puStack_12 != (uint *)0x0 && (iVar29 < (int)(uint)GLeaderCount));
                iVar29 = iVar29 + 1) {
              if ((*(char *)((int)*(undefined4 *)(iVar29 << 2) + 0x3d) != '\0') &&
                 ((*(char *)((int)*(undefined4 *)(iVar29 << 2) + 0x3f) == '\0' &&
                  (uVar53 = (undefined2)((ulong)*(undefined4 *)(iVar29 << 2) >> 0x10),
                  iVar52 = (int)*(undefined4 *)(iVar29 << 2),
                  *(int *)(iVar52 + 0x60) != 0 || *(int *)(iVar52 + 0x62) != 0)))) {
                uVar53 = (undefined2)((ulong)*(undefined4 *)(iVar29 << 2) >> 0x10);
                iVar52 = (int)*(undefined4 *)(iVar29 << 2);
                uVar23 = *(uint *)(iVar52 + 0x62);
                if ((uVar23 < 0x8000) &&
                   ((0 < (int)uVar23 || (puStack_12 < (uint *)*(undefined2 *)(iVar52 + 0x60))))) {
                  uStack_14 = (far_t *)puStack_12;
                }
                else {
                  uStack_14 = (far_t *)*(undefined2 *)((int)*(undefined4 *)(iVar29 << 2) + 0x60);
                }
                puStack_12 = (uint *)((int)puStack_12 - (int)uStack_14);
                uVar53 = (undefined2)((ulong)*(undefined4 *)(iVar29 << 2) >> 0x10);
                iVar52 = (int)*(undefined4 *)(iVar29 << 2);
                piVar4 = (int *)(iVar52 + 0x60);
                puVar49 = (uint *)*piVar4;
                *piVar4 = *piVar4 - (int)uStack_14;
                piVar4 = (int *)(iVar52 + 0x62);
                *piVar4 = *piVar4 - (uint)(puVar49 < uStack_14);
              }
            }
          }
          pfVar20 = (far_t *)0x0;
          while ((pfVar20 < EntityCount && (puStack_12 != (uint *)0x0))) {
            uVar53 = (undefined2)((ulong)Entities >> 0x10);
            peVar41 = (entity_t *)Entities;
            if (((*(char *)((int)&peVar41[(int)pfVar20].base.entity + 1) == '\0') &&
                ((far_t *)(uint)*(byte *)((int)&peVar41[(int)pfVar20].base.entity + 3) == uStack_16)
                ) && ((bVar58 || (1 < peVar41[(int)pfVar20].base.animFrame)))) {
              if (peVar41[(int)pfVar20].base.animFrame != 0x0) {
                if (DebugVerbose != false) {
                  printf("kill 3\r");
                }
                puVar5 = &((entity_t *)Entities)[(int)pfVar20].base.animFrame;
                *puVar5 = *puVar5 + 0xff;
                if (((entity_t *)Entities)[(int)pfVar20].base.animFrame == 0x0) {
                  uStack_1e = CONCAT11(1,(byte)uStack_1e);
                }
              }
              puStack_12 = (uint *)((int)puStack_12 + -1);
            }
            pfVar20 = (far_t *)((int)&pfVar20->ofs + 1);
          }
        }
        else {
          uVar22 = *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f) -
                   *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d);
          uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
          puVar3 = (uint *)(iVar29 + 0x60);
          uVar23 = *puVar3;
          *puVar3 = *puVar3 + uVar22;
          piVar4 = (int *)(iVar29 + 0x62);
          *piVar4 = *piVar4 + (uint)CARRY2(uVar23,uVar22);
        }
      }
      uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar39 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar29 = *(int *)(iVar39 + 0x62);
      uVar54 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar40 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar52 = *(int *)(iVar40 + 0x80);
      if ((iVar52 <= iVar29) &&
         ((iVar52 < iVar29 || (*(uint *)(iVar40 + 0x7e) < *(uint *)(iVar39 + 0x60))))) {
        uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
        uVar23 = *(uint *)(iVar29 + 0x60);
        uVar54 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar52 = (int)*(undefined4 *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar52 + 0x7e);
        uVar22 = (uint)(uVar23 < *puVar3);
        uVar32 = *(int *)(iVar29 + 0x62) - *(int *)(iVar52 + 0x80);
        if (((int)(uVar32 - uVar22) < 0) ||
           ((uVar32 == uVar22 &&
            (uVar23 - *puVar3 <= *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0))))) {
          puStack_a = (uint *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x60) -
                              *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x7e));
        }
        else {
          puStack_a = (uint *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0);
        }
        *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa2) = -(int)puStack_a;
        uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar29 + 0x56);
        uVar23 = *puVar3;
        *puVar3 = (uint)(*puVar3 + (int)puStack_a);
        piVar4 = (int *)(iVar29 + 0x58);
        *piVar4 = *piVar4 + (uint)CARRY2(uVar23,(uint)puStack_a);
        uVar54 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
        uVar53 = *(undefined2 *)(iVar29 + 0x7e);
        uVar55 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar52 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar52 + 0x62) = *(undefined2 *)(iVar29 + 0x80);
        *(undefined2 *)(iVar52 + 0x60) = uVar53;
      }
      if ((*(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x5b) <
           *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d)) &&
         ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                    (uint)*(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3e) * 0x95) & 0x80
          ) == 0)) {
        puStack_12 = (uint *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d) -
                             *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x5b));
        pfVar20 = (far_t *)0x0;
        while ((pfVar20 < EntityCount && (puStack_12 != (uint *)0x0))) {
          uVar53 = (undefined2)((ulong)Entities >> 0x10);
          peVar41 = (entity_t *)Entities;
          if (((far_t *)(uint)*(byte *)((int)&peVar41[(int)pfVar20].base.entity + 3) == uStack_16)
             && ((((*(char *)((int)&peVar41[(int)pfVar20].base.entity + 1) == '\0' &&
                   (peVar41[(int)pfVar20].base.destX == 0)) &&
                  (peVar41[(int)pfVar20].base.destY == 0)) &&
                 (3 < peVar41[(int)pfVar20].base.animFrame)))) {
            if (DebugVerbose != false) {
              printf("kill 2 \r");
            }
            puVar5 = &((entity_t *)Entities)[(int)pfVar20].base.animFrame;
            *puVar5 = *puVar5 + 0xff;
            puStack_12 = (uint *)((int)puStack_12 + -1);
          }
          pfVar20 = (far_t *)((int)&pfVar20->ofs + 1);
        }
      }
      ovr_ovc25_tickCountdown((int)uStack_16);
      _fmemset((void *)(ulong)*(uint *)((int)uStack_16 * 4 + 2),6,CONCAT11(uVar68,cVar25));
      _fmemset((void *)(ulong)*(uint *)((int)uStack_16 * 4 + 2),6,CONCAT11(uVar68,cVar25));
      uVar31 = ovr_randBelow(100);
      if ((byte)uVar31 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6c) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 100);
      }
      else {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6a) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 100);
      }
      uVar31 = ovr_randBelow(100);
      if ((byte)uVar31 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6e) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x66);
      }
      else {
        piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6c);
        *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x66);
      }
      piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6e);
      *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x68);
      uVar31 = ovr_randBelow(100);
      if ((byte)uVar31 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x78) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x70);
      }
      else {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x76) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x70);
      }
      uVar31 = ovr_randBelow(100);
      if ((byte)uVar31 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x7a) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x72);
      }
      else {
        piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x78);
        *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x72);
      }
      uVar31 = ovr_randBelow(100);
      if ((byte)uVar31 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x7c) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x74);
      }
      else {
        piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x7a);
        *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x74);
      }
      *(undefined1 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa7) =
           *(undefined1 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa6);
      if (*(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3f) != '\0') {
        uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar52 = (int)*(undefined4 *)((int)uStack_16 << 2);
        iVar29 = *(int *)(iVar52 + 0x58);
        if ((iVar29 < 1) && ((iVar29 != 0 || (*(int *)(iVar52 + 0x56) == 0)))) {
          uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
          *(undefined2 *)(iVar29 + 0x58) = 0;
          *(undefined2 *)(iVar29 + 0x56) = 0x32;
        }
      }
      if (*(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xaa) != '\0') {
        bVar17 = *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xaa);
        uStack_6 = (far_t *)(ulong)CONCAT12(bVar17,(far_t *)uStack_6);
        pfVar13 = uStack_6;
        for (uVar23 = 0; uStack_6 = pfVar13, (int)uVar23 < (int)(uint)GLeaderCount;
            uVar23 = uVar23 + 1) {
          uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar39 = (int)*(undefined4 *)((int)uStack_16 << 2);
          iVar29 = *(int *)(iVar39 + 0x58);
          uVar54 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar40 = (int)*(undefined4 *)((int)uStack_16 << 2);
          iVar52 = *(int *)(iVar40 + 0x8c);
          if ((iVar52 <= iVar29) &&
             ((iVar29 != iVar52 || (*(uint *)(iVar40 + 0x8a) <= *(uint *)(iVar39 + 0x56))))) break;
          if ((*(char *)((int)*(undefined4 *)(uVar23 << 2) + 0x3d) != '\0') &&
             (((0 < *(int *)((int)*(undefined4 *)(uVar23 << 2) + 0x54) &&
               (*(char *)((int)*(undefined4 *)(uVar23 << 2) + 0x3f) == '\0')) &&
              ((far_t *)uVar23 != uStack_16)))) {
            (*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) = (uint)bVar17;
            resourceTotals[2] =
                 (int16_t)(((long)*(int *)((int)*(undefined4 *)(uVar23 << 2) + 0x54) *
                            (long)(int)(*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) & 0xffffU) / 100);
            resourceTotals[3] = 0;
            uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
            uVar22 = *(uint *)(iVar29 + 0x8a);
            uVar54 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar52 = (int)*(undefined4 *)((int)uStack_16 << 2);
            puVar3 = (uint *)(iVar52 + 0x56);
            iVar29 = (*(int *)(iVar29 + 0x8c) - *(int *)(iVar52 + 0x58)) - (uint)(uVar22 < *puVar3);
            if ((iVar29 < 1) && ((iVar29 < 0 || (uVar22 - *puVar3 < (uint)resourceTotals[2])))) {
              uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
              iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
              uVar22 = *(uint *)(iVar29 + 0x8a);
              uVar54 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
              iVar52 = (int)*(undefined4 *)((int)uStack_16 << 2);
              puVar3 = (uint *)(iVar52 + 0x56);
              resourceTotals[2] = uVar22 - *puVar3;
              resourceTotals[3] =
                   (*(int *)(iVar29 + 0x8c) - *(int *)(iVar52 + 0x58)) - (uint)(uVar22 < *puVar3);
            }
            uVar53 = (undefined2)((ulong)*(undefined4 *)(uVar23 << 2) >> 0x10);
            iVar52 = (int)*(undefined4 *)(uVar23 << 2);
            iVar29 = *(int *)(iVar52 + 0x58);
            if ((iVar29 <= resourceTotals[3]) &&
               ((iVar29 < resourceTotals[3] || (*(uint *)(iVar52 + 0x56) < (uint)resourceTotals[2]))
               )) {
              uVar53 = (undefined2)((ulong)*(undefined4 *)(uVar23 << 2) >> 0x10);
              iVar29 = (int)*(undefined4 *)(uVar23 << 2);
              resourceTotals[3] = *(int16_t *)(iVar29 + 0x58);
              resourceTotals[2] = *(int16_t *)(iVar29 + 0x56);
            }
            uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
            puVar3 = (uint *)(iVar29 + 0x56);
            uVar22 = *puVar3;
            *puVar3 = *puVar3 + resourceTotals[2];
            piVar4 = (int *)(iVar29 + 0x58);
            *piVar4 = *piVar4 + resourceTotals[3] + (uint)CARRY2(uVar22,resourceTotals[2]);
            uVar53 = (undefined2)((ulong)*(undefined4 *)(uVar23 << 2) >> 0x10);
            iVar29 = (int)*(undefined4 *)(uVar23 << 2);
            puVar3 = (uint *)(iVar29 + 0x56);
            uVar22 = *puVar3;
            *puVar3 = *puVar3 - resourceTotals[2];
            piVar4 = (int *)(iVar29 + 0x58);
            *piVar4 = (*piVar4 - resourceTotals[3]) - (uint)(uVar22 < (uint)resourceTotals[2]);
          }
        }
      }
      iVar29 = *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x58);
      if ((iVar29 < 1) && (iVar29 < 0)) {
        uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar29 + 0x58) = 0;
        *(undefined2 *)(iVar29 + 0x56) = 0;
      }
      uVar53 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar39 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar29 = *(int *)(iVar39 + 0x58);
      uVar54 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar40 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar52 = *(int *)(iVar40 + 0x8c);
      if ((iVar52 <= iVar29) &&
         ((iVar52 < iVar29 || (*(uint *)(iVar40 + 0x8a) < *(uint *)(iVar39 + 0x56))))) {
        uVar54 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar29 = (int)*(undefined4 *)((int)uStack_16 << 2);
        uVar53 = *(undefined2 *)(iVar29 + 0x8a);
        uVar55 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar52 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar52 + 0x58) = *(undefined2 *)(iVar29 + 0x8c);
        *(undefined2 *)(iVar52 + 0x56) = uVar53;
      }
    }
  }
  GGameState = 0x40;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  puVar49 = (uint *)&GUnitDescriptions[3].ofs;
  while (puVar49 = (uint *)((int)puVar49 + 1), puVar49 < GUnitCount) {
    uVar53 = (undefined2)((ulong)GUnits >> 0x10);
    puVar37 = (unit_t *)GUnits;
    if ((*(uint *)((uint)(puVar37 + (int)puVar49)->bldType * 0x27 + 0x121) & 0x40) != 0) {
      if (puVar37[(int)puVar49].timer != 0) {
        puVar37[(int)puVar49].timer = puVar37[(int)puVar49].timer - 1;
      }
      uVar53 = (undefined2)((ulong)GUnits >> 0x10);
      if (((unit_t *)GUnits)[(int)puVar49].timer == 0) {
        uVar11 = *(undefined4 *)((uint)((unit_t *)GUnits)[(int)puVar49].unitType << 2);
        if (*(char *)((int)uVar11 + 0x3f) == '\0') {
          ovr_play_sfx(81);
          uVar53 = (undefined2)((ulong)GUnits >> 0x10);
          sVar7 = ((unit_t *)GUnits)[(int)puVar49].y;
          uVar19 = (undefined1)sVar7;
          uVar67 = (undefined1)((uint)sVar7 >> 8);
          uVar23 = ovr_alignUp4(((unit_t *)GUnits)[(int)puVar49].x);
          pcVar21 = ovr_fmVsprintf("Mine exhausted at (%d, %d).",
                                   (char *)CONCAT13(uVar67,CONCAT12(uVar19,uVar23)));
          ovr_say(pcVar21);
          ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
        }
        ovc22_usesGUnits((int)puVar49,
                         (uint8_t *)
                         CONCAT13((char)((uint)((int)puVar49 * 9) >> 8),
                                  CONCAT12(((unit_t *)GUnits)[(int)puVar49].unitType,unaff_SS)));
      }
    }
  }
  GGameState = 0x42;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_driver_clearMapFlagsRect((uint32_t)GMapFlags);
  for (uStack_16 = (far_t *)0x0; uStack_16 < SquareRecCount;
      uStack_16 = (far_t *)((int)uStack_16 + 1)) {
    puVar3 = (uint *)((*(short (*) [60] [148])GMapFlags)[*(int *)((int)uStack_16 * 0x13 + 2)] +
                     *(int *)((int)uStack_16 * 0x13));
    *puVar3 = *puVar3 | 8;
  }
  if (EntityCount <= EntityScanPos) {
    EntityScanPos = (uint16_t)(0x0);
    for (uStack_16 = (far_t *)0x0; (int)uStack_16 < (int)(uint)GLeaderCount;
        uStack_16 = (far_t *)((int)uStack_16 + 1)) {
      if (*(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3d) != '\0') {
        iVar29 = ((int *)((int)uStack_16 * 4))[1];
        iVar52 = ((int *)((int)uStack_16 * 4))[1];
        memcpy((char *)CONCAT13((char)((uint)iVar52 >> 8),
                                CONCAT12((char)iVar52,*(int *)((int)uStack_16 * 4) + 0x8e)),
               (char *)CONCAT13((char)((uint)iVar29 >> 8),
                                CONCAT12((char)iVar29,*(int *)((int)uStack_16 * 4) + 0x94)),3);
      }
    }
  }
  uStack_e = (uint *)0x0;
  bVar17 = ovr_manage_findFirstLeader();
  (*(uint16_t *)((uint8_t *)&(uStack_6))) = (far_t *)CONCAT11(bVar17,(byte)uStack_6);
  if ((bVar17 == 0xff) || (GCanPromote == '\0')) {
    scratch = 0;
  }
  else if (*(byte *)((int)*(undefined4 *)((uint)bVar17 << 2) + 0x86) < 5) {
    scratch = 0x28;
  }
  else {
    scratch = (uint)*(byte *)((int)*(undefined4 *)((uint)bVar17 << 2) + 0x86) * 4 + 0x14;
  }
  for (uStack_16 = EntityScanPos; uStack_16 < EntityCount;
      uStack_16 = (far_t *)((int)&uStack_16->ofs + 1)) {
    uVar53 = (undefined2)((ulong)Entities >> 0x10);
    peVar41 = (entity_t *)Entities;
    if (((*(char *)((int)&peVar41[(int)uStack_16].base.entity + 1) == '\0') &&
        (peVar41[(int)uStack_16].base.destX == 0)) && (peVar41[(int)uStack_16].base.destY == 0)) {
      bVar17 = peVar41[(int)uStack_16].base.gindex;
      uStack_6 = (far_t *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),bVar17);
      bVar16 = *(byte *)((int)&peVar41[(int)uStack_16].base.entity + 3);
      bVar56 = false;
      bVar59 = false;
      bVar58 = false;
      if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar17 * 0x95) == -1) {
        bVar56 = false;
        bVar59 = true;
      }
      else {
        bStack_1b = *(byte *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0x89);
        if (bStack_1b < 5) {
          uStack_1a = peVar41[(int)uStack_16].base.y;
          uStack_18 = ovr_alignUp4(((peVar41 + (int)uStack_16)->base).x);
          uVar31 = 0x2410;
          if (((*(short (*) [60] [148])GMapFlags)[uStack_1a][uStack_18] & 8U) == 0) {
            uStack_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)),0x22);
            uStack_20 = (byte *)((char *)0x26222);
          }
          else {
            puVar51 = &uStack_1e;
            iVar29 = (int)&uStack_20 + 1;
            puVar63 = &uStack_20;
            index = CONCAT11((char)((uint)puVar63 >> 8),bStack_1b);
            uStackY_60 = 0x2379;
            uStackY_62 = 0x3d98;
            cVar18 = cVar14;
            uVar19 = uVar65;
            cVar64 = cVar14;
            uVar67 = uVar65;
            cVar66 = cVar14;
            uVar69 = uVar65;
            uVar24 = ovr_attact_usesSquareRecCount(uStack_18,uStack_1a);
            uStackY_60 = 0x2315;
            uStackY_62 = 0x3da2;
            table.seg = uVar31;
            table.ofs = uVar24;
            (*(uint8_t *)((uint8_t *)&(pctOut.seg))) = cVar18;
            pctOut.ofs = (uint16_t)puVar63;
            (*(uint8_t *)((uint8_t *)&(pctOut.seg) + 1)) = uVar19;
            (*(uint8_t *)((uint8_t *)&(remainderOut.seg))) = cVar64;
            remainderOut.ofs = iVar29;
            (*(uint8_t *)((uint8_t *)&(remainderOut.seg) + 1)) = uVar67;
            (*(uint8_t *)((uint8_t *)&(partOut.seg))) = cVar66;
            partOut.ofs = (uint16_t)puVar51;
            (*(uint8_t *)((uint8_t *)&(partOut.seg) + 1)) = uVar69;
            ovr_attact_compute3(table,index,pctOut,remainderOut,partOut);
          }
        }
        else {
          uStack_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)),0x22);
          uStack_20 = (byte *)((char *)0x26222);
        }
        uVar31 = ovr_randBelow(100);
        if ((byte)uVar31 < (byte)uStack_1e) {
          bVar56 = false;
          bVar59 = true;
        }
        else if ((uVar31 & 0xff) < ((uint)uStack_20 >> 8) + (uStack_1e & 0xff)) {
          bVar56 = true;
          bVar59 = false;
        }
        else {
          bVar58 = true;
        }
      }
      if ((bVar58) &&
         (cVar18 = ovr_ovc23_tickRecordsAt((((entity_t *)Entities + (int)uStack_16)->base).x),
         cVar18 == '\0')) {
        if (((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)) == 0) && ((byte)uStack_1e == '\0')) {
          uVar31 = ovr_randBelow(2);
          if ((uVar31 & 0xff) == 0) {
            bVar59 = true;
          }
          else {
            bVar56 = true;
          }
        }
        else {
          uVar31 = ovr_randBelow((uint)(*(uint8_t *)((uint8_t *)&(uStack_20) + 1)) + (uStack_1e & 0xff));
          if ((byte)uVar31 < (byte)uStack_1e) {
            bVar59 = true;
          }
          else {
            bVar56 = true;
          }
        }
      }
      if ((bVar59) && (uVar23 = ovc22_usesEntities((int)uStack_16), (uVar23 & 0xff) == 0)) {
        bVar56 = true;
      }
      if (bVar56) {
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(byte)uStack_6 * 0x95) != -1) &&
           (bVar16 != 0xff)) {
          if ((*(char *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0x3f) != '\0') ||
             (Entities[(int)uStack_16].base.level <
              *(byte *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0x53))) {
            uVar19 = (undefined1)scratch;
            uVar67 = (undefined1)(scratch >> 8);
            ovc22_usesLUDIV_at_((entity_t *)
                                CONCAT13((char)((ulong)Entities >> 0x18),
                                         CONCAT12((char)((ulong)Entities >> 0x10),
                                                  Entities + (int)uStack_16)));
            LXMUL_at_((long *)CONCAT11(uVar67,uVar19),CONCAT22(unaff_SI,CONCAT11(uVar68,cVar25)),
                      CONCAT13((char)((uint)iVar30 >> 8),
                               CONCAT12((char)iVar30,CONCAT11(in_stack_0000ffb9,in_stack_0000ffb8)))
                     );
            peVar41 = Entities + (int)uStack_16;
            uVar31 = ovr_ovc15_textError();
            uVar22 = ovc22_usesLUDIV_at_2(uVar31,(uint16_t)peVar41,CONCAT11(uVar67,uVar19));
            uVar53 = (undefined2)((ulong)Entities >> 0x10);
            peVar42 = (entity_t *)Entities;
            uVar23 = *(uint *)&peVar42[(int)uStack_16].base.health;
            *(uint *)&peVar42[(int)uStack_16].base.frameIndex =
                 (int)&(peVar41->base).x +
                 (uint)CARRY2(uVar23,uVar22) + *(int *)&peVar42[(int)uStack_16].base.frameIndex;
            *(uint *)&peVar42[(int)uStack_16].base.health = uVar23 + uVar22;
            ovr_ovc41_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                        CONCAT12((char)((ulong)Entities >> 0x10),
                                                 Entities + (int)uStack_16)));
          }
        }
        ovc22_usesEntities2((int)uStack_16);
        ovc22_usesEntities3((int)uStack_16);
        ovc22_usesEntities4((int)uStack_16);
      }
      animStep = (uint)((entity_t *)Entities)[(int)uStack_16].base.animFrame -
                 (uint)*(byte *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0xa4);
      if (0 < animStep) {
        if (3 < animStep) {
          animStep = 3;
        }
        if (animStep == 3) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0x92) == 0) {
            animStep = 2;
          }
          else {
            piVar4 = (int *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0x92);
            *piVar4 = *piVar4 + -1;
          }
        }
        if (animStep == 2) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0x90) == 0) {
            animStep = 1;
          }
          else {
            piVar4 = (int *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0x90);
            *piVar4 = *piVar4 + -1;
          }
        }
        if (animStep == 1) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0x8e) == 0) {
            animStep = 0;
          }
          else {
            piVar4 = (int *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0x8e);
            *piVar4 = *piVar4 + -1;
          }
        }
        ((entity_t *)Entities)[(int)uStack_16].base.animFrame =
             *(char *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0xa4) + (char)animStep;
      }
      uStack_e = (uint *)((int)uStack_e + 1);
      if (199 < (int)uStack_e) break;
    }
  }
  EntityScanPos = uStack_16;
  mapDirty = 1;
  ovr_unit_usesAlignUp4();
  GGameState = 0x44;
  pfVar20 = (far_t *)((char *)0x26510);
  if (DebugVerbose != false) {
    pfVar20 = (far_t *)((char *)0x26510);
    printf("%d \r");
  }
  if ((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)) != '\0') {
    pfVar20 = (far_t *)((int)&EntityCount[-1].seg + 1);
    for (uStack_16 = pfVar20; -1 < (int)uStack_16;
        uStack_16 = (far_t *)((int)&uStack_16[-1].seg + 1)) {
      uVar53 = (undefined2)((ulong)Entities >> 0x10);
      peVar41 = (entity_t *)Entities;
      pfVar20 = (far_t *)(uint)peVar41[(int)uStack_16].base.animFrame;
      if (pfVar20 == (far_t *)0x0) {
        pfVar20 = (far_t *)(uint)*(byte *)((int)(char **)GMenuStrings +
                                          (uint)peVar41[(int)uStack_16].base.gindex * 0x95 + 0x1f);
        if (pfVar20 == (far_t *)0x0) {
          ovr_alignUp4(((peVar41 + (int)uStack_16)->base).x);
          iVar30 = (uint)((entity_t *)Entities)[(int)uStack_16].base.gindex * 0x95;
          uVar53 = *(undefined2 *)((int)&worldMenuLabels[1].ofs + 1 + iVar30);
          pfVar20 = (far_t *)ovr_fmVsprintf("Intelligence reports %s unit died of starvation. (%d, %d)"
                                            ,(char *)CONCAT13((char)((uint)uVar53 >> 8),
                                                              CONCAT12((char)uVar53,
                                                                       *(undefined2 *)
                                                                        ((int)&worldMenuLabels[0].
                                                                               seg + 1 + iVar30))));
          ovr_uiNotify((char *)pfVar20);
        }
        ovr_ovc15_removeEntity((uint)uStack_16);
      }
    }
  }
  if (cStack_1c != '\0') {
    ovr_constr_flushDirtyRects();
  }
  return pfVar20;
}
