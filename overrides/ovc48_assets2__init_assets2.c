void __cdecl16far init_assets2(bool grab,...)

{
  far_t hndl;
  far_t src;
  far_t pixels;
  far_t pixels_00;
  stg_tmp_t *psVar1;
  far_t *pfVar2;
  cte_t *pcVar3;
  uint16_t in_DX;
  undefined2 uVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  uint8_t *puVar7;
  uint8_t *puVar8;
  uint8_t *puVar9;
  int iVar10;
  far_t *unaff_DI;
  far_t pixels_01;
  far_t pixels_02;
  far_t pixels_03;
  far_t pixels_04;
  far_t pixels_05;
  far_t pixels_06;
  far_t pixels_07;
  far_t pixels_08;
  far_t pixels_09;
  far_t pixels_10;
  far_t pixels_11;
  far_t pixels_12;
  far_t pixels_13;
  far_t pixels_14;
  far_t pixels_15;
  far_t pixels_16;
  far_t pixels_17;
  far_t pixels_18;
  far_t pixels_19;
  far_t pixels_20;
  far_t pixels_21;
  far_t pixels_22;
  far_t pixels_23;
  far_t pixels_24;
  far_t pixels_25;
  far_t pixels_26;
  far_t pixels_27;
  far_t pixels_28;
  far_t pixels_29;
  far_t pixels_30;
  far_t pixels_31;
  far_t pixels_32;
  far_t pixels_33;
  far_t pixels_34;
  far_t pixels_35;
  far_t pixels_36;
  far_t pixels_37;
  far_t pixels_38;
  far_t pixels_39;
  far_t pixels_40;
  far_t pixels_41;
  far_t pixels_42;
  far_t pixels_43;
  far_t pixels_44;
  far_t pixels_45;
  far_t pixels_46;
  far_t pixels_47;
  far_t pixels_48;
  far_t pixels_49;
  far_t src_00;
  far_t src_01;
  far_t src_02;
  far_t src_03;
  far_t src_04;
  far_t src_05;
  far_t src_06;
  far_t src_07;
  far_t src_08;
  far_t src_09;
  far_t src_10;
  far_t src_11;
  far_t src_12;
  far_t src_13;
  far_t src_14;
  far_t src_15;
  far_t src_16;
  far_t src_17;
  far_t src_18;
  far_t src_19;
  far_t src_20;
  far_t src_21;
  far_t src_22;
  far_t src_23;
  far_t src_24;
  far_t src_25;
  far_t src_26;
  far_t src_27;
  far_t src_28;
  far_t src_29;
  far_t src_30;
  far_t src_31;
  far_t src_32;
  far_t src_33;
  far_t src_34;
  far_t src_35;
  far_t src_36;
  far_t src_37;
  far_t src_38;
  far_t src_39;
  far_t src_40;
  far_t src_41;
  far_t src_42;
  far_t src_43;
  far_t src_44;
  far_t src_45;
  far_t src_46;
  far_t src_47;
  far_t src_48;
  far_t src_49;
  far_t src_50;
  far_t src_51;
  far_t src_52;
  far_t src_53;
  far_t src_54;
  far_t src_55;
  far_t src_56;
  far_t src_57;
  far_t src_58;
  far_t src_59;
  far_t src_60;
  far_t src_61;
  far_t src_62;
  far_t src_63;
  far_t src_64;
  far_t src_65;
  far_t src_66;
  far_t src_67;
  far_t src_68;
  far_t src_69;
  far_t src_70;
  far_t src_71;
  far_t src_72;
  far_t src_73;
  far_t src_74;
  stg_tmp_t *psStack_a;
  uint8_t *puStack_8;
  
  if (grab) {
    grabBldLbm2(218,509,510,0xfe);
  }
  else {
    stshAllocBldStubs2(218);
  }
  ovr_stshStubifyCopy1to0(0xda);
  ovr_stshStubifyCopy1to0(0xdd);
  ovr_stshStubifyCopy1to0(0xe0);
  if (grab) {
    grabBldLbm2(227,511,512,0);
  }
  else {
    stshAllocBldStubs2(227);
  }
  ovr_stshStubifyCopy1to0(0xe3);
  ovr_stshStubifyCopy1to0(0xe6);
  ovr_stshStubifyCopy1to0(0xe9);
  if (grab) {
    psVar1 = ovr_grabLbmTR(527);
    psStack_a = (stg_tmp_t *)CONCAT22(in_DX,psVar1);
  }
  iVar10 = 0;
  while( true ) {
    if (2 < iVar10) break;
    if (grab) {
      uVar4 = (undefined2)((ulong)((long)iVar10 * 100) >> 0x10);
      pixels_01.seg = (int)((long)iVar10 * 100) + 0x14;
      pixels_01.ofs = (psStack_a->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psStack_a->aptr)->ofs,pixels_01,33,iVar10 * 100 + 99,116,
                                10,28,(int16_t)unaff_DI,0x1c);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar4);
      *(undefined2 *)((int)&BldGfxNormal[1].seg + (iVar10 + 0xec) * 0xc) = uVar4;
      ((far_t *)(BldGfxNormal + 1) + (iVar10 + 0xec) * 3)->ofs = (uint16_t)pcVar3;
    }
    else {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      *(uint16_t *)((int)&BldGfxNormal[1].seg + (iVar10 + 0xec) * 0xc) = in_DX;
      ((far_t *)(BldGfxNormal + 1) + (iVar10 + 0xec) * 3)->ofs = (uint16_t)pfVar2;
    }
    uVar5 = ((far_t *)(BldGfxNormal + 1) + (iVar10 + 0xec) * 3)->ofs;
    *(undefined2 *)((int)&BldGfxNormal[0].seg + (iVar10 + 0xec) * 0xc) =
         *(undefined2 *)((int)&BldGfxNormal[1].seg + (iVar10 + 0xec) * 0xc);
    ((far_t *)BldGfxNormal + (iVar10 + 0xec) * 3)->ofs = uVar5;
    in_DX = *(uint16_t *)((int)&BldGfxNormal[1].seg + (iVar10 + 0xec) * 0xc);
    uVar5 = ((far_t *)(BldGfxNormal + 1) + (iVar10 + 0xec) * 3)->ofs;
    *(uint16_t *)((int)&BldGfxNormal[2].seg + (iVar10 + 0xec) * 0xc) = in_DX;
    ((far_t *)(BldGfxNormal + 2) + (iVar10 + 0xec) * 3)->ofs = uVar5;
    iVar10 = iVar10 + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(psStack_a,(char)((ulong)psStack_a >> 0x10));
    psVar1 = ovr_grabLbmTR(528);
    psStack_a = (stg_tmp_t *)CONCAT22(in_DX,psVar1);
  }
  iVar10 = 0;
  while( true ) {
    if (2 < iVar10) break;
    if (grab) {
      uVar4 = (undefined2)((ulong)((long)iVar10 * 100) >> 0x10);
      pixels_02.seg = (int)((long)iVar10 * 100) + 0x14;
      pixels_02.ofs = (psStack_a->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psStack_a->aptr)->ofs,pixels_02,33,iVar10 * 100 + 99,116,
                                10,28,(int16_t)unaff_DI,0x1c);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar4);
      *(undefined2 *)((int)&BldGfxRuin[1].seg + (iVar10 + 0xec) * 0xc) = uVar4;
      ((far_t *)(BldGfxRuin + 1) + (iVar10 + 0xec) * 3)->ofs = (uint16_t)pcVar3;
    }
    else {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      *(uint16_t *)((int)&BldGfxRuin[1].seg + (iVar10 + 0xec) * 0xc) = in_DX;
      ((far_t *)(BldGfxRuin + 1) + (iVar10 + 0xec) * 3)->ofs = (uint16_t)pfVar2;
    }
    in_DX = 0x195d;
    iVar10 = iVar10 + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(psStack_a,(char)((ulong)psStack_a >> 0x10));
  }
  ovr_stshStubifyCopy1to0(0xec);
  if (grab) {
    psVar1 = ovr_grabLbmTR(529);
    psStack_a = (stg_tmp_t *)CONCAT22(in_DX,psVar1);
    pixels_03.seg = 0;
    pixels_03.ofs = (psVar1->aptr).seg;
    uVar5 = in_DX;
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_03,130,99,194,26,-1,
                              (int16_t)unaff_DI,0xff);
    BldGfxNormal[0x2e6].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar5);
    uVar6 = 0x195d;
    pixels_04.seg = 100;
    pixels_04.ofs = (psVar1->aptr).seg;
    BldGfxNormal[0x2e6].seg = uVar5;
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_04,130,199,194,26,-1,
                              (int16_t)unaff_DI,0xff);
    BldGfxNormal[0x2e3].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar6);
    uVar5 = 0x195d;
    pixels_05.seg = 200;
    pixels_05.ofs = (psVar1->aptr).seg;
    BldGfxNormal[0x2e3].seg = uVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_05,130,299,194,26,-1,
                              (int16_t)unaff_DI,0xff);
    BldGfxNormal[0x2e0].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar5);
    uVar6 = 0x195d;
    pixels_06.seg = 0;
    pixels_06.ofs = (psVar1->aptr).seg;
    BldGfxNormal[0x2e0].seg = uVar5;
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_06,65,99,129,26,-1,
                              (int16_t)unaff_DI,0xff);
    BldGfxNormal[0x2dd].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar6);
    uVar5 = 0x195d;
    pixels_07.seg = 100;
    pixels_07.ofs = (psVar1->aptr).seg;
    BldGfxNormal[0x2dd].seg = uVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_07,65,199,129,26,-1,
                              (int16_t)unaff_DI,0xff);
    BldGfxNormal[0x2da].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar5);
    uVar6 = 0x195d;
    pixels_08.seg = 200;
    pixels_08.ofs = (psVar1->aptr).seg;
    BldGfxNormal[0x2da].seg = uVar5;
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_08,65,299,129,26,-1,
                              (int16_t)unaff_DI,0xff);
    BldGfxNormal[0x2d7].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar6);
    uVar5 = 0x195d;
    pixels_09.seg = 0;
    pixels_09.ofs = (psVar1->aptr).seg;
    BldGfxNormal[0x2d7].seg = uVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_09,0,99,64,26,-1,
                              (int16_t)unaff_DI,0xff);
    BldGfxNormal[0x2d4].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar5);
    uVar6 = 0x195d;
    pixels_10.seg = 100;
    pixels_10.ofs = (psVar1->aptr).seg;
    BldGfxNormal[0x2d4].seg = uVar5;
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_10,0,199,64,26,-1,
                              (int16_t)unaff_DI,0xff);
    BldGfxNormal[0x2d1].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar6);
    uVar5 = 0x195d;
    pixels_11.seg = 200;
    pixels_11.ofs = (psVar1->aptr).seg;
    BldGfxNormal[0x2d1].seg = uVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_11,0,299,64,26,-1,
                              (int16_t)unaff_DI,0xff);
    BldGfxNormal[0x2ce].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar5);
    puVar9 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
    BldGfxNormal[0x2ce].seg = uVar5;
    ovr_stgFreeTmp(psVar1,(char)in_DX);
  }
  else {
    BldGfxNormal[0x2e6].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    uVar5 = 0x195d;
    BldGfxNormal[0x2e6].seg = in_DX;
    BldGfxNormal[0x2e3].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    uVar6 = 0x195d;
    BldGfxNormal[0x2e3].seg = uVar5;
    BldGfxNormal[0x2e0].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    uVar5 = 0x195d;
    BldGfxNormal[0x2e0].seg = uVar6;
    BldGfxNormal[0x2dd].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    uVar6 = 0x195d;
    BldGfxNormal[0x2dd].seg = uVar5;
    BldGfxNormal[0x2da].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    uVar5 = 0x195d;
    BldGfxNormal[0x2da].seg = uVar6;
    BldGfxNormal[0x2d7].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    uVar6 = 0x195d;
    BldGfxNormal[0x2d7].seg = uVar5;
    BldGfxNormal[0x2d4].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    uVar5 = 0x195d;
    BldGfxNormal[0x2d4].seg = uVar6;
    BldGfxNormal[0x2d1].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    uVar6 = 0x195d;
    BldGfxNormal[0x2d1].seg = uVar5;
    BldGfxNormal[0x2ce].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    puVar9 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
    BldGfxNormal[0x2ce].seg = uVar6;
  }
  ovr_stshStubifyCopy1to0(0xef);
  ovr_stshStubifyCopy1to0(0xf2);
  ovr_stshStubifyCopy1to0(0xf5);
  for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
    *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar10 * 4) = 0;
    ((far_t *)BldGfxNormal + iVar10)->ofs = 0;
  }
  if (grab) {
    psVar1 = ovr_grabLbmTR(10);
    pixels_12.seg = 0xc;
    pixels_12.ofs = (psVar1->aptr).seg;
    puVar7 = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_12,7,222,150,-12,-7,
                              (int16_t)unaff_DI,0xf9);
    nwpanel2Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    src_00.seg = 0xef;
    src_00.ofs = (psVar1->aptr).seg;
    nwpanel2Cut1Seg =(uint16_t)( puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_00,7,308,54,(int16_t)unaff_DI,0x36);
    GMenuGfxOfs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    GMenuGfxSeg =(uint16_t)( puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbmTR(14);
    SpecialColors[0] = *(uint8_t *)((int)&GStrangeTable[0x12].ofs + 1 + (psVar1->aptr).ofs);
    SpecialColors[1] = ((char *)0x2b021)[(psVar1->aptr).ofs];
    SpecialColors[2] = ((char *)0x2b516)[(psVar1->aptr).ofs];
    SpecialColors[3] =
         ((char *)0x29fcf)
         [(psVar1->aptr).ofs];
    SpecialColors[4] = ((char *)0x2b01f)[(psVar1->aptr).ofs];
    SpecialColors[5] = *(uint8_t *)((int)&GStrangeTable[0x12].seg + 1 + (psVar1->aptr).ofs);
    SpecialColors[6] = *(uint8_t *)((int)(undefined2 *)&youlose1Cut1Seg + (psVar1->aptr).ofs);
    SpecialColors[7] = *(uint8_t *)((psVar1->aptr).ofs + 0x936e);
    puVar8 = (uint8_t *)((char *)0x26510);
    specialColorsOfs =(uint16_t)(
         (far_t *)ovr_stshWrite((uint32_t *)SpecialColors,(uint8_t *)0x82410,
                                ZEXT24(unaff_DI) << 0x10,0));
    src_01.seg = 0xea;
    src_01.ofs = (psVar1->aptr).seg;
    specialColorsSeg =(uint16_t)( puVar8);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_01,64,314,120,(int16_t)unaff_DI,0x78);
    trianglsCut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar8);
    src_02.seg = 0xd0;
    src_02.ofs = (psVar1->aptr).seg;
    trianglsCut1Seg =(uint16_t)( puVar8);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_02,158,228,176,(int16_t)unaff_DI,0xb0)
    ;
    trianglsCut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar8);
    src_03.seg = 0xb3;
    src_03.ofs = (psVar1->aptr).seg;
    trianglsCut2Seg =(uint16_t)( puVar8);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_03,180,198,196,(int16_t)unaff_DI,0xc4)
    ;
    trianglsCut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar8);
    src_04.seg = 0xcf;
    src_04.ofs = (psVar1->aptr).seg;
    trianglsCut3Seg =(uint16_t)( puVar8);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_04,180,226,196,(int16_t)unaff_DI,0xc4)
    ;
    trianglsCut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar8);
    src_05.seg = 0x26;
    src_05.ofs = (psVar1->aptr).seg;
    trianglsCut4Seg =(uint16_t)( puVar8);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_05,181,57,196,(int16_t)unaff_DI,0xc4);
    trianglsCut5Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar8);
    src_06.seg = 9;
    src_06.ofs = (psVar1->aptr).seg;
    trianglsCut5Seg =(uint16_t)( puVar8);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_06,181,24,196,(int16_t)unaff_DI,0xc4);
    trianglsCut6Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar8);
    trianglsCut6Seg =(uint16_t)( puVar8);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbmTR(127);
    src_07.seg = 0xf5;
    src_07.ofs = (psVar1->aptr).seg;
    puVar9 = (uint16_t)(puVar8);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_07,116,267,128,(int16_t)unaff_DI,0x80)
    ;
    panel01Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    src_08.seg = 0x124;
    src_08.ofs = (psVar1->aptr).seg;
    panel01Cut1Seg =(uint16_t)( puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_08,114,314,133,(int16_t)unaff_DI,0x85)
    ;
    panel01Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    src_09.seg = 0xdd;
    src_09.ofs = (psVar1->aptr).seg;
    panel01Cut2Seg =(uint16_t)( puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_09,157,228,198,(int16_t)unaff_DI,0xc6)
    ;
    panel01Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    panel01Cut3Seg =(uint16_t)( puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar8);
    psVar1 = ovr_grabLbm(15,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    Lbm_nwpanel1.ofs =
         (uint16_t)
         ovr_stshWrite((uint32_t *)psVar1,(uint8_t *)CONCAT22(0x300,puVar9),ZEXT24(unaff_DI) << 0x10
                       ,0);
    src_10.seg = 0xe6;
    src_10.ofs = (psVar1->aptr).seg;
    Lbm_nwpanel1.seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_10,57,314,113,(int16_t)unaff_DI,0x71);
    nwpanel1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    src_11.seg = 0;
    src_11.ofs = (psVar1->aptr).seg;
    nwpanel1Cut1Seg =(uint16_t)( puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_11,0,319,199,(int16_t)unaff_DI,199);
    fullScreenGfxOfs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    src_12.seg = 0x1d;
    src_12.ofs = (psVar1->aptr).seg;
    fullScreenGfxSeg =(uint16_t)( puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_12,156,207,199,(int16_t)unaff_DI,199);
    FontHandle.ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    src_13.seg = 9;
    src_13.ofs = (psVar1->aptr).seg;
    FontHandle.seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_13,181,28,196,(int16_t)unaff_DI,0xc4);
    nwpanel1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    src_14.seg = 0xdf;
    src_14.ofs = (psVar1->aptr).seg;
    nwpanel1Cut2Seg =(uint16_t)( puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_14,8,237,50,(int16_t)unaff_DI,0x32);
    nwpanel1Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    src_15.seg = 6;
    src_15.ofs = (psVar1->aptr).seg;
    nwpanel1Cut3Seg =(uint16_t)( puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_15,156,28,171,(int16_t)unaff_DI,0xab);
    nwpanel1Cut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    src_16.seg = 0xd0;
    src_16.ofs = (psVar1->aptr).seg;
    nwpanel1Cut4Seg =(uint16_t)( puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_16,157,229,198,(int16_t)unaff_DI,0xc6)
    ;
    nwpanel1Cut5Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    nwpanel1Cut5Seg =(uint16_t)( puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(12,0,0,0);
    psStack_a = (stg_tmp_t *)CONCAT22(puVar7,psVar1);
    puVar9 = (uint16_t)(puVar7);
    for (iVar10 = 0; iVar10 < 4; iVar10 = iVar10 + 1) {
      uVar4 = (undefined2)((ulong)((long)iVar10 * 0xe) >> 0x10);
      src.seg = (uint16_t)((long)iVar10 * 0xe);
      src.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src,46,iVar10 * 0xe + 0xd,55,
                              (int16_t)unaff_DI,0x37);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar4);
      *(undefined2 *)((int)&CrossBlitGfx.seg + iVar10 * 4) = uVar4;
      ((far_t *)&CrossBlitGfx + iVar10)->ofs = (uint16_t)pcVar3;
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0xe) >> 0x10);
      pixels.seg = (uint16_t)((long)iVar10 * 0xe);
      pixels.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels,16,iVar10 * 0xe + 0xd,24,6,4,
                                (int16_t)unaff_DI,4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&crossBlitType2Seg)[iVar10 * 2] =(uint16_t)( puVar9);
      ((undefined2 *)&crossBlitType2Ofs)[iVar10 * 2] =(uint16_t)( pcVar3);
    }
    ovr_stgFreeTmp(psVar1,(char)puVar7);
  }
  else {
    nwpanel2Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    nwpanel2Cut1Seg =(uint16_t)( puVar9);
    GMenuGfxOfs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    GMenuGfxSeg =(uint16_t)( puVar9);
    specialColorsOfs = ovr_stshAllocStub(unaff_DI);
    specialColorsSeg =(uint16_t)( puVar9);
    trianglsCut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    trianglsCut1Seg =(uint16_t)( puVar9);
    trianglsCut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    trianglsCut2Seg =(uint16_t)( puVar9);
    trianglsCut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    trianglsCut3Seg =(uint16_t)( puVar9);
    trianglsCut4Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    trianglsCut4Seg =(uint16_t)( puVar9);
    trianglsCut5Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    trianglsCut5Seg =(uint16_t)( puVar9);
    trianglsCut6Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    trianglsCut6Seg =(uint16_t)( puVar9);
    panel01Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    panel01Cut1Seg =(uint16_t)( puVar9);
    panel01Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    panel01Cut2Seg =(uint16_t)( puVar9);
    panel01Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    panel01Cut3Seg =(uint16_t)( puVar9);
    Lbm_nwpanel1.ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    Lbm_nwpanel1.seg = (uint16_t)puVar9;
    nwpanel1Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    nwpanel1Cut1Seg =(uint16_t)( puVar9);
    fullScreenGfxOfs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    fullScreenGfxSeg =(uint16_t)( puVar9);
    FontHandle.ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    FontHandle.seg = (uint16_t)puVar9;
    nwpanel1Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    nwpanel1Cut2Seg =(uint16_t)( puVar9);
    nwpanel1Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    nwpanel1Cut3Seg =(uint16_t)( puVar9);
    nwpanel1Cut4Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    nwpanel1Cut4Seg =(uint16_t)( puVar9);
    nwpanel1Cut5Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    nwpanel1Cut5Seg =(uint16_t)( puVar9);
    for (iVar10 = 0; iVar10 < 4; iVar10 = iVar10 + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      *(undefined2 *)((int)&CrossBlitGfx.seg + iVar10 * 4) =(uint16_t)( puVar9);
      ((far_t *)&CrossBlitGfx + iVar10)->ofs = (uint16_t)pfVar2;
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((undefined2 *)&crossBlitType2Seg)[iVar10 * 2] =(uint16_t)( puVar9);
      ((undefined2 *)&crossBlitType2Ofs)[iVar10 * 2] =(uint16_t)( pfVar2);
    }
  }
  if (grab) {
    psVar1 = ovr_grabLbm(93,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    for (iVar10 = 0; iVar10 < 6; iVar10 = iVar10 + 1) {
      pixels_13.seg = 8;
      pixels_13.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_13,iVar10 * 0x20 + 10,63,
                                iVar10 * 0x20 + 0x24,0,0,(int16_t)unaff_DI,0);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
      ((undefined2 *)&csite1Seg)[iVar10 * 2] =(uint16_t)( puVar7);
      ((undefined2 *)&csite1Ofs)[iVar10 * 2] =(uint16_t)( pcVar3);
    }
    for (iVar10 = 0; iVar10 < 6; iVar10 = iVar10 + 1) {
      pixels_14.seg = 0x55;
      pixels_14.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_14,iVar10 * 0x20 + 10,140,
                                iVar10 * 0x20 + 0x24,0,0,(int16_t)unaff_DI,0);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
      ((undefined2 *)&csite1_6Seg)[iVar10 * 2] =(uint16_t)( puVar7);
      ((undefined2 *)&csite1_6Ofs)[iVar10 * 2] =(uint16_t)( pcVar3);
    }
    for (iVar10 = 0; iVar10 < 6; iVar10 = iVar10 + 1) {
      pixels_15.seg = 0x9f;
      pixels_15.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_15,iVar10 * 0x20 + 10,214,
                                iVar10 * 0x20 + 0x24,0,0,(int16_t)unaff_DI,0);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
      ((undefined2 *)&csite1_12Seg)[iVar10 * 2] =(uint16_t)( puVar7);
      ((undefined2 *)&csite1_12Ofs)[iVar10 * 2] =(uint16_t)( pcVar3);
    }
    for (iVar10 = 0; iVar10 < 5; iVar10 = iVar10 + 1) {
      pixels_16.seg = 0xe5;
      pixels_16.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_16,iVar10 * 0x20 + 10,284,
                                iVar10 * 0x20 + 0x24,0,0,(int16_t)unaff_DI,0);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
      ((undefined2 *)&csite1_18Seg)[iVar10 * 2] = (uint16_t)(puVar7);
      ((undefined2 *)&csite1_18Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(94,0,0,0);
    puVar9 = (uint16_t)(puVar7);
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_17.seg = 0;
      pixels_17.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_17,
                                (int)((long)iVar10 * 0x3d) + 0x11,104,iVar10 * 0x3d + 0x49,0,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&csite2Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&csite2Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_18.seg = 0x6d;
      pixels_18.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_18,
                                (int)((long)iVar10 * 0x3d) + 0x11,213,iVar10 * 0x3d + 0x49,0,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&csite2_3Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&csite2_3Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_19.seg = 0xd7;
      pixels_19.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_19,
                                (int)((long)iVar10 * 0x3d) + 0x11,319,iVar10 * 0x3d + 0x49,0,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&csite2_6Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&csite2_6Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(95,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar7 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_20.seg = 0;
      pixels_20.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_20,
                                (int)((long)iVar10 * 0x3d) + 0x11,104,iVar10 * 0x3d + 0x49,0,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
      ((undefined2 *)&csite3Seg)[iVar10 * 2] = (uint16_t)(puVar7);
      ((undefined2 *)&csite3Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar7 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_21.seg = 0x6d;
      pixels_21.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_21,
                                (int)((long)iVar10 * 0x3d) + 0x11,213,iVar10 * 0x3d + 0x49,0,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
      ((undefined2 *)&csite3_3Seg)[iVar10 * 2] = (uint16_t)(puVar7);
      ((undefined2 *)&csite3_3Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(96,0,0,0);
    puVar9 = (uint16_t)(puVar7);
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_22.seg = 0;
      pixels_22.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_22,
                                (int)((long)iVar10 * 0x3d) + 0x11,104,iVar10 * 0x3d + 0x49,0,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&csite4Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&csite4Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_23.seg = 0x6d;
      pixels_23.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_23,
                                (int)((long)iVar10 * 0x3d) + 0x11,213,iVar10 * 0x3d + 0x49,0,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&csite4_3Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&csite4_3Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_24.seg = 0xd7;
      pixels_24.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_24,
                                (int)((long)iVar10 * 0x3d) + 0x11,319,iVar10 * 0x3d + 0x49,0,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&csite4_6Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&csite4_6Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(531,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar7 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_25.seg = 1;
      pixels_25.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_25,
                                (int)((long)iVar10 * 0x3d) + 0x11,103,iVar10 * 0x3d + 0x49,-4,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
      ((undefined2 *)&csite5Seg)[iVar10 * 2] = (uint16_t)(puVar7);
      ((undefined2 *)&csite5Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar7 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_26.seg = 0x68;
      pixels_26.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_26,
                                (int)((long)iVar10 * 0x3d) + 0x11,206,iVar10 * 0x3d + 0x49,-4,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
      ((undefined2 *)&csite5_3Seg)[iVar10 * 2] = (uint16_t)(puVar7);
      ((undefined2 *)&csite5_3Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar7 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_27.seg = 0xd1;
      pixels_27.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_27,
                                (int)((long)iVar10 * 0x3d) + 0x11,311,iVar10 * 0x3d + 0x49,-4,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
      ((undefined2 *)&csite5_6Seg)[iVar10 * 2] = (uint16_t)(puVar7);
      ((undefined2 *)&csite5_6Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(532,0,0,0);
    puVar9 = (uint16_t)(puVar7);
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_28.seg = 1;
      pixels_28.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_28,
                                (int)((long)iVar10 * 0x3d) + 0x11,103,iVar10 * 0x3d + 0x49,-4,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&csite6Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&csite6Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_29.seg = 0x68;
      pixels_29.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_29,
                                (int)((long)iVar10 * 0x3d) + 0x11,206,iVar10 * 0x3d + 0x49,-4,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&csite6_3Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&csite6_3Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_30.seg = 0xd1;
      pixels_30.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_30,
                                (int)((long)iVar10 * 0x3d) + 0x11,311,iVar10 * 0x3d + 0x49,-4,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&csite6_6Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&csite6_6Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(533,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar7 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_31.seg = 1;
      pixels_31.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_31,
                                (int)((long)iVar10 * 0x3d) + 0x11,103,iVar10 * 0x3d + 0x49,-4,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
      ((undefined2 *)&csite7Seg)[iVar10 * 2] = (uint16_t)(puVar7);
      ((undefined2 *)&csite7Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar7 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_32.seg = 0x68;
      pixels_32.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_32,
                                (int)((long)iVar10 * 0x3d) + 0x11,206,iVar10 * 0x3d + 0x49,-4,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
      ((undefined2 *)&csite7_3Seg)[iVar10 * 2] = (uint16_t)(puVar7);
      ((undefined2 *)&csite7_3Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar7 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_33.seg = 0xd1;
      pixels_33.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_33,
                                (int)((long)iVar10 * 0x3d) + 0x11,311,iVar10 * 0x3d + 0x49,-4,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
      ((undefined2 *)&csite7_6Seg)[iVar10 * 2] = (uint16_t)(puVar7);
      ((undefined2 *)&csite7_6Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(534,0,0,0);
    puVar8 = (uint16_t)(puVar7);
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar8 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_34.seg = 1;
      pixels_34.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_34,
                                (int)((long)iVar10 * 0x3d) + 0x11,103,iVar10 * 0x3d + 0x49,-4,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar8);
      ((undefined2 *)&csite8Seg)[iVar10 * 2] = (uint16_t)(puVar8);
      ((undefined2 *)&csite8Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 2; iVar10 = iVar10 + 1) {
      puVar8 = (uint8_t *)((ulong)((long)iVar10 * 0x3d) >> 0x10);
      pixels_35.seg = 0x68;
      pixels_35.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_35,
                                (int)((long)iVar10 * 0x3d) + 0x11,206,iVar10 * 0x3d + 0x49,-4,-60,
                                (int16_t)unaff_DI,0xc4);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar8);
      ((undefined2 *)&csite8_3Seg)[iVar10 * 2] = (uint16_t)(puVar8);
      ((undefined2 *)&csite8_3Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(535,0,0,0);
    psStack_a = (stg_tmp_t *)CONCAT22(puVar8,psVar1);
    puVar9 = (uint16_t)(puVar8);
    for (iVar10 = 0; iVar10 < 7; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x1b) >> 0x10);
      pixels_36.seg = 6;
      pixels_36.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_36,
                                (int)((long)iVar10 * 0x1b) + 8,33,iVar10 * 0x1b + 0x13,0,0,
                                (int16_t)unaff_DI,0);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&tmstrsSprites6Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites6Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 7; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x1b) >> 0x10);
      pixels_37.seg = 0x23;
      pixels_37.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_37,
                                (int)((long)iVar10 * 0x1b) + 8,62,iVar10 * 0x1b + 0x13,0,0,
                                (int16_t)unaff_DI,0);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&tmstrsSprites9Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites9Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 7; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x1b) >> 0x10);
      pixels_38.seg = 0x4c;
      pixels_38.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_38,
                                (int)((long)iVar10 * 0x1b) + 8,88,iVar10 * 0x1b + 0x13,0,0,
                                (int16_t)unaff_DI,0);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&tmstrsSprites5Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites5Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 7; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x1b) >> 0x10);
      pixels_39.seg = 0x66;
      pixels_39.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_39,
                                (int)((long)iVar10 * 0x1b) + 8,114,iVar10 * 0x1b + 0x13,0,0,
                                (int16_t)unaff_DI,0);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&tmstrsSprites6Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites6Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x1b) >> 0x10);
      pixels_40.seg = 0x80;
      pixels_40.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_40,
                                (int)((long)iVar10 * 0x1b) + 8,140,iVar10 * 0x1b + 0x13,0,0,
                                (int16_t)unaff_DI,0);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&tmstrsSprites7Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites7Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 7; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x1b) >> 0x10);
      pixels_41.seg = 0x9a;
      pixels_41.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_41,
                                (int)((long)iVar10 * 0x1b) + 8,163,iVar10 * 0x1b + 0x13,0,0,
                                (int16_t)unaff_DI,0);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&tmstrsSprites4Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites4Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 7; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x1b) >> 0x10);
      pixels_42.seg = 0xb8;
      pixels_42.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_42,
                                (int)((long)iVar10 * 0x1b) + 8,185,iVar10 * 0x1b + 0x13,0,0,
                                (int16_t)unaff_DI,0);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&tmstrsSprites3Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites3Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    for (iVar10 = 0; iVar10 < 7; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x1b) >> 0x10);
      pixels_43.seg = 0xcf;
      pixels_43.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_43,
                                (int)((long)iVar10 * 0x1b) + 8,223,iVar10 * 0x1b + 0x13,0,0,
                                (int16_t)unaff_DI,0);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&tmstrsSprites2Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites2Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    pixels_44.seg = 0xeb;
    pixels_44.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_44,8,251,19,0,0,(int16_t)unaff_DI
                              ,0);
    anim_tmstrsCut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    anim_tmstrsCut1Seg = (uint16_t)(puVar9);
    for (iVar10 = 0; iVar10 < 5; iVar10 = iVar10 + 1) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x1b) >> 0x10);
      pixels_45.seg = 0x10b;
      pixels_45.ofs = (psVar1->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_45,
                                (int)((long)iVar10 * 0x1b) + 8,286,iVar10 * 0x1b + 0x13,0,0,
                                (int16_t)unaff_DI,0);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&tmstrsSprites1Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites1Ofs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    ovr_stgFreeTmp(psVar1,(char)puVar8);
  }
  else {
    for (iVar10 = 0; iVar10 < 0x17; iVar10 = iVar10 + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((undefined2 *)&csite1Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&csite1Ofs)[iVar10 * 2] = (uint16_t)(pfVar2);
    }
    for (iVar10 = 0; iVar10 < 0x18; iVar10 = iVar10 + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((undefined2 *)&csite2Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&csite2Ofs)[iVar10 * 2] = (uint16_t)(pfVar2);
    }
    for (iVar10 = 0; iVar10 < 0x20; iVar10 = iVar10 + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((undefined2 *)&csite5Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&csite5Ofs)[iVar10 * 2] = (uint16_t)(pfVar2);
    }
    for (iVar10 = 0; iVar10 < 0xe; iVar10 = iVar10 + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((undefined2 *)&tmstrsSprites6Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites6Ofs)[iVar10 * 2] = (uint16_t)(pfVar2);
    }
    for (iVar10 = 0; iVar10 < 0x11; iVar10 = iVar10 + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((undefined2 *)&tmstrsSprites5Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites5Ofs)[iVar10 * 2] = (uint16_t)(pfVar2);
    }
    for (iVar10 = 0; iVar10 < 7; iVar10 = iVar10 + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((undefined2 *)&tmstrsSprites4Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites4Ofs)[iVar10 * 2] = (uint16_t)(pfVar2);
    }
    for (iVar10 = 0; iVar10 < 7; iVar10 = iVar10 + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((undefined2 *)&tmstrsSprites3Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites3Ofs)[iVar10 * 2] = (uint16_t)(pfVar2);
    }
    for (iVar10 = 0; iVar10 < 8; iVar10 = iVar10 + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((undefined2 *)&tmstrsSprites2Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites2Ofs)[iVar10 * 2] = (uint16_t)(pfVar2);
    }
    for (iVar10 = 0; iVar10 < 5; iVar10 = iVar10 + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((undefined2 *)&tmstrsSprites1Seg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&tmstrsSprites1Ofs)[iVar10 * 2] = (uint16_t)(pfVar2);
    }
  }
  if (grab) {
    psVar1 = ovr_grabLbm(35,0,0,0);
    psStack_a = (stg_tmp_t *)CONCAT22(puVar9,psVar1);
  }
  iVar10 = 0;
  while( true ) {
    if (3 < iVar10) break;
    if (grab) {
      puVar9 = (uint8_t *)((ulong)((long)iVar10 * 0x16) >> 0x10);
      pixels_00.seg = (uint16_t)((long)iVar10 * 0x16);
      pixels_00.ofs = (psStack_a->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t *)(&psStack_a->aptr)->ofs,pixels_00,0,iVar10 * 0x16 + 0x15,14
                                ,11,7,(int16_t)unaff_DI,7);
      pcVar3 = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
      ((undefined2 *)&boltSpritesSeg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&boltSpritesOfs)[iVar10 * 2] = (uint16_t)(pcVar3);
    }
    else {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((undefined2 *)&boltSpritesSeg)[iVar10 * 2] = (uint16_t)(puVar9);
      ((undefined2 *)&boltSpritesOfs)[iVar10 * 2] = (uint16_t)(pfVar2);
    }
    iVar10 = iVar10 + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(psStack_a,(char)((ulong)psStack_a >> 0x10));
    psVar1 = ovr_grabLbm(8,0,0,0);
    src_17.seg = 0;
    src_17.ofs = (psVar1->aptr).seg;
    puVar7 = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_17,0,319,199,(int16_t)unaff_DI,199);
    gamfont1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    gamfont1Cut1Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(6,0,0,0);
    src_18.seg = 0;
    src_18.ofs = (psVar1->aptr).seg;
    puVar9 = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_18,0,319,199,(int16_t)unaff_DI,199);
    davfontCut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    davfontCut1Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(140,0,0,0);
    src_19.seg = 0;
    src_19.ofs = (psVar1->aptr).seg;
    puVar7 = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_19,0,319,27,(int16_t)unaff_DI,0x1b);
    davfont2Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    davfont2Cut1Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(411,0,0,0);
    FontSize.hi = 0;
    FontSize.lo = 0;
    uVar5 = (psVar1->aptr).seg;
    hndl.seg = (uint16_t)unaff_DI;
    hndl.ofs = uVar5;
    puVar9 = (uint16_t)(puVar7);
    pfVar2 = ovr_stshProcessFontSub((far_t *)(&psVar1->aptr)->ofs,hndl,(char)uVar5);
    demfont1FontOfs =(uint16_t)(
         (far_t *)ovr_stshWrite((uint32_t *)pfVar2,(uint8_t *)CONCAT22(FontSize.lo,puVar9),
                                CONCAT22(unaff_DI,FontSize.hi),(char)FontSize.hi));
    demfont1FontSeg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(78,0,0,0);
    pixels_46.seg = 8;
    pixels_46.ofs = (psVar1->aptr).seg;
    puVar7 = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_46,3,226,194,-8,-3,
                              (int16_t)unaff_DI,0xfd);
    talkwin9Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    pixels_47.seg = 0xdd;
    pixels_47.ofs = (psVar1->aptr).seg;
    talkwin9Cut1Seg = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_47,157,229,198,-221,-157,
                              (int16_t)unaff_DI,99);
    talkwin9Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    pixels_48.seg = 0xd0;
    pixels_48.ofs = (psVar1->aptr).seg;
    talkwin9Cut2Seg = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_48,195,223,199,-208,-195,
                              (int16_t)unaff_DI,0x3d);
    talkwin9Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    pixels_49.seg = 8;
    pixels_49.ofs = (psVar1->aptr).seg;
    talkwin9Cut3Seg = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleType2((far_t *)(&psVar1->aptr)->ofs,pixels_49,117,226,194,-8,-117,
                              (int16_t)unaff_DI,0x8b);
    talkwin9Cut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    talkwin9Cut4Seg = (uint16_t)(puVar7);
    talkwin9Cut5Ofs =(uint16_t)(
         (far_t *)ovr_stshWrite((uint32_t *)psVar1,(uint8_t *)CONCAT22(0x300,puVar9),
                                ZEXT24(unaff_DI) << 0x10,0));
    talkwin9Cut5Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(543,0,0,0);
    src_20.seg = 8;
    src_20.ofs = (psVar1->aptr).seg;
    puVar9 = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_20,5,16,10,(int16_t)unaff_DI,10);
    LbxButton2.ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    LbxButton2.seg = (uint16_t)puVar9;
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(139,0,0,0);
    src_21.seg = 0x10;
    src_21.ofs = (psVar1->aptr).seg;
    puVar7 = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_21,121,57,131,(int16_t)unaff_DI,0x83);
    butt01Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    src_22.seg = 0x10;
    src_22.ofs = (psVar1->aptr).seg;
    butt01Cut1Seg = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_22,134,57,144,(int16_t)unaff_DI,0x90);
    butt01Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    src_23.seg = 0xea;
    src_23.ofs = (psVar1->aptr).seg;
    butt01Cut2Seg = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_23,121,300,131,(int16_t)unaff_DI,0x83)
    ;
    butt01Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    src_24.seg = 0xea;
    src_24.ofs = (psVar1->aptr).seg;
    butt01Cut3Seg = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_24,134,300,144,(int16_t)unaff_DI,0x90)
    ;
    butt01Cut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    src_25.seg = 0x99;
    src_25.ofs = (psVar1->aptr).seg;
    butt01Cut4Seg = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_25,121,230,131,(int16_t)unaff_DI,0x83)
    ;
    butt01Cut5Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    src_26.seg = 0x99;
    src_26.ofs = (psVar1->aptr).seg;
    butt01Cut5Seg = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_26,134,230,144,(int16_t)unaff_DI,0x90)
    ;
    butt01Cut6Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    butt01Cut6Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(179,0,0,0);
    src_27.seg = 0x5e;
    src_27.ofs = (psVar1->aptr).seg;
    puVar9 = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_27,47,108,89,(int16_t)unaff_DI,0x59);
    button1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    src_28.seg = 0x72;
    src_28.ofs = (psVar1->aptr).seg;
    button1Cut1Seg = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_28,47,128,89,(int16_t)unaff_DI,0x59);
    button1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    src_29.seg = 0xdf;
    src_29.ofs = (psVar1->aptr).seg;
    button1Cut2Seg = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_29,8,237,50,(int16_t)unaff_DI,0x32);
    button1Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    button1Cut3Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(158,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    back03Cut1Ofs =(uint16_t)(
         (far_t *)ovr_stshWrite((uint32_t *)psVar1,(uint8_t *)CONCAT22(0x300,puVar9),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_30.seg = 0;
    src_30.ofs = (psVar1->aptr).seg;
    back03Cut1Seg = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_30,0,319,80,(int16_t)unaff_DI,0x50);
    back03Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    back03Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(159,0,0,0);
    src_31.seg = 0;
    src_31.ofs = (psVar1->aptr).seg;
    puVar9 = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_31,0,219,143,(int16_t)unaff_DI,0x8f);
    midgrnd5Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    midgrnd5Cut1Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(159,220,0,0);
    src_32.seg = 0;
    src_32.ofs = (psVar1->aptr).seg;
    puVar7 = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_32,0,219,143,(int16_t)unaff_DI,0x8f);
    midgrnd5Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    midgrnd5Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(160,0,0,0);
    src_33.seg = 0;
    src_33.ofs = (psVar1->aptr).seg;
    puVar9 = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_33,0,279,143,(int16_t)unaff_DI,0x8f);
    strong4Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    strong4Cut1Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(160,280,0,0);
    src_34.seg = 0;
    src_34.ofs = (psVar1->aptr).seg;
    puVar7 = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_34,0,279,143,(int16_t)unaff_DI,0x8f);
    strong4Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    strong4Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(161,0,0,0);
    puVar9 = (uint16_t)(puVar7);
    marbleCut1Ofs =(uint16_t)(
         (far_t *)ovr_stshWrite((uint32_t *)psVar1,(uint8_t *)CONCAT22(0x300,puVar7),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_35.seg = 0;
    src_35.ofs = (psVar1->aptr).seg;
    marbleCut1Seg = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_35,144,319,199,(int16_t)unaff_DI,199);
    marbleCut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    src_36.seg = 0;
    src_36.ofs = (psVar1->aptr).seg;
    marbleCut2Seg = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_36,0,47,10,(int16_t)unaff_DI,10);
    far_t_2000_d3e4.ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    far_t_2000_d3e4.seg = (uint16_t)puVar9;
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(412,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    back2Cut1Ofs =(uint16_t)( (far_t *)ovr_stshWrite((uint32_t *)psVar1,(uint8_t *)CONCAT22(0x300,puVar9),
                                          ZEXT24(unaff_DI) << 0x10,0));
    src_37.seg = 0;
    src_37.ofs = (psVar1->aptr).seg;
    back2Cut1Seg = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_37,0,319,80,(int16_t)unaff_DI,0x50);
    back2Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    back2Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(414,0,0,0);
    src_38.seg = 0;
    src_38.ofs = (psVar1->aptr).seg;
    puVar9 = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_38,0,219,143,(int16_t)unaff_DI,0x8f);
    midl3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    midl3Cut1Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(414,220,0,0);
    src_39.seg = 0;
    src_39.ofs = (psVar1->aptr).seg;
    puVar7 = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_39,0,219,143,(int16_t)unaff_DI,0x8f);
    midl3Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    midl3Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(413,0,0,0);
    src_40.seg = 0;
    src_40.ofs = (psVar1->aptr).seg;
    puVar9 = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_40,0,279,143,(int16_t)unaff_DI,0x8f);
    frnt3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    frnt3Cut1Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(413,280,0,0);
    src_41.seg = 0;
    src_41.ofs = (psVar1->aptr).seg;
    puVar7 = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_41,0,279,143,(int16_t)unaff_DI,0x8f);
    frnt3Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    frnt3Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(422,0,0,0);
    puVar9 = (uint16_t)(puVar7);
    winrebg1Cut1Ofs =(uint16_t)(
         (far_t *)ovr_stshWrite((uint32_t *)psVar1,(uint8_t *)CONCAT22(0x300,puVar7),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_42.seg = 0;
    src_42.ofs = (psVar1->aptr).seg;
    winrebg1Cut1Seg = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_42,0,319,113,(int16_t)unaff_DI,0x71);
    winrebg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    winrebg1Cut2Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(421,0,0,0);
    src_43.seg = 0;
    src_43.ofs = (psVar1->aptr).seg;
    puVar7 = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_43,0,219,143,(int16_t)unaff_DI,0x8f);
    winremg2Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    winremg2Cut1Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(421,220,0,0);
    src_44.seg = 0;
    src_44.ofs = (psVar1->aptr).seg;
    puVar9 = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_44,0,219,143,(int16_t)unaff_DI,0x8f);
    winremg2Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    winremg2Cut2Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(420,0,0,0);
    src_45.seg = 0;
    src_45.ofs = (psVar1->aptr).seg;
    puVar7 = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_45,0,279,143,(int16_t)unaff_DI,0x8f);
    winrefg1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    winrefg1Cut1Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(420,280,0,0);
    src_46.seg = 0;
    src_46.ofs = (psVar1->aptr).seg;
    puVar9 = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_46,0,279,143,(int16_t)unaff_DI,0x8f);
    winrefg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    winrefg1Cut2Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(437,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    captbg2Cut1Ofs =(uint16_t)(
         (far_t *)ovr_stshWrite((uint32_t *)psVar1,(uint8_t *)CONCAT22(0x300,puVar9),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_47.seg = 0;
    src_47.ofs = (psVar1->aptr).seg;
    captbg2Cut1Seg = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_47,0,319,113,(int16_t)unaff_DI,0x71);
    captbg2Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    captbg2Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(438,0,0,0);
    src_48.seg = 0;
    src_48.ofs = (psVar1->aptr).seg;
    puVar9 = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_48,0,219,143,(int16_t)unaff_DI,0x8f);
    captmg3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    captmg3Cut1Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(438,220,0,0);
    src_49.seg = 0;
    src_49.ofs = (psVar1->aptr).seg;
    puVar7 = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_49,0,219,143,(int16_t)unaff_DI,0x8f);
    captmg3Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    captmg3Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(439,0,0,0);
    src_50.seg = 0;
    src_50.ofs = (psVar1->aptr).seg;
    puVar8 = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_50,0,279,143,(int16_t)unaff_DI,0x8f);
    captfg1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar8);
    captfg1Cut1Seg = (uint16_t)(puVar8);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(439,280,0,0);
    src_51.seg = 0;
    src_51.ofs = (psVar1->aptr).seg;
    puVar9 = (uint16_t)(puVar8);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_51,0,279,143,(int16_t)unaff_DI,0x8f);
    captfg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    captfg1Cut2Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar8);
    psVar1 = ovr_grabLbm(305,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar9);
    src_52.seg = 0;
    src_52.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_52,0,319,59,(int16_t)unaff_DI,0x3b);
    l1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    l1Cut1Seg = (uint16_t)(puVar7);
    l1Cut2Ofs =(uint16_t)( (far_t *)ovr_stshWrite((uint32_t *)(psVar1->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,puVar9),ZEXT24(unaff_DI) << 0x10,0));
    l1Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(305,320,0,0);
    puVar9 = (uint16_t)(puVar7);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar7);
    src_53.seg = 0;
    src_53.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_53,0,319,59,(int16_t)unaff_DI,0x3b);
    l1Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    l1Cut3Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(328,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar9);
    src_54.seg = 0;
    src_54.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_54,0,319,59,(int16_t)unaff_DI,0x3b);
    l4Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    l4Cut1Seg = (uint16_t)(puVar7);
    l4Cut2Ofs =(uint16_t)( (far_t *)ovr_stshWrite((uint32_t *)(psVar1->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,puVar9),ZEXT24(unaff_DI) << 0x10,0));
    l4Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(328,320,0,0);
    puVar8 = (uint16_t)(puVar7);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar7);
    src_55.seg = 0;
    src_55.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_55,0,319,59,(int16_t)unaff_DI,0x3b);
    l4Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar8);
    l4Cut3Seg = (uint16_t)(puVar8);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(331,0,0,0);
    puVar9 = (uint16_t)(puVar8);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar8);
    src_56.seg = 0;
    src_56.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_56,0,319,59,(int16_t)unaff_DI,0x3b);
    l7Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    l7Cut1Seg = (uint16_t)(puVar9);
    l7Cut2Ofs =(uint16_t)( (far_t *)ovr_stshWrite((uint32_t *)(psVar1->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,puVar8),ZEXT24(unaff_DI) << 0x10,0));
    l7Cut2Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar8);
    psVar1 = ovr_grabLbm(331,320,0,0);
    puVar7 = (uint16_t)(puVar9);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar9);
    src_57.seg = 0;
    src_57.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_57,0,319,59,(int16_t)unaff_DI,0x3b);
    l7Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    l7Cut3Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(307,0,0,0);
    puVar9 = (uint16_t)(puVar7);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar7);
    src_58.seg = 0;
    src_58.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_58,0,319,59,(int16_t)unaff_DI,0x3b);
    l2Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    l2Cut1Seg = (uint16_t)(puVar9);
    l2Cut2Ofs =(uint16_t)( (far_t *)ovr_stshWrite((uint32_t *)(psVar1->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,puVar7),ZEXT24(unaff_DI) << 0x10,0));
    l2Cut2Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(307,320,0,0);
    puVar8 = (uint16_t)(puVar9);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar9);
    src_59.seg = 0;
    src_59.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_59,0,319,59,(int16_t)unaff_DI,0x3b);
    l2Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar8);
    l2Cut3Seg = (uint16_t)(puVar8);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(329,0,0,0);
    puVar7 = (uint16_t)(puVar8);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar8);
    src_60.seg = 0;
    src_60.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_60,0,319,59,(int16_t)unaff_DI,0x3b);
    l5Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    l5Cut1Seg = (uint16_t)(puVar7);
    l5Cut2Ofs =(uint16_t)( (far_t *)ovr_stshWrite((uint32_t *)(psVar1->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,puVar8),ZEXT24(unaff_DI) << 0x10,0));
    l5Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar8);
    psVar1 = ovr_grabLbm(329,320,0,0);
    puVar9 = (uint16_t)(puVar7);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar7);
    src_61.seg = 0;
    src_61.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_61,0,319,59,(int16_t)unaff_DI,0x3b);
    l5Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    l5Cut3Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(332,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar9);
    src_62.seg = 0;
    src_62.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_62,0,319,59,(int16_t)unaff_DI,0x3b);
    l8Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    l8Cut1Seg = (uint16_t)(puVar7);
    l8Cut2Ofs =(uint16_t)( (far_t *)ovr_stshWrite((uint32_t *)(psVar1->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,puVar9),ZEXT24(unaff_DI) << 0x10,0));
    l8Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(332,320,0,0);
    puVar9 = (uint16_t)(puVar7);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar7);
    src_63.seg = 0;
    src_63.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_63,0,319,59,(int16_t)unaff_DI,0x3b);
    l8Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    l8Cut3Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(306,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar9);
    src_64.seg = 0;
    src_64.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_64,0,319,59,(int16_t)unaff_DI,0x3b);
    l3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    l3Cut1Seg = (uint16_t)(puVar7);
    l3Cut2Ofs =(uint16_t)( (far_t *)ovr_stshWrite((uint32_t *)(psVar1->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,puVar9),ZEXT24(unaff_DI) << 0x10,0));
    l3Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(306,320,0,0);
    puVar9 = (uint16_t)(puVar7);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar7);
    src_65.seg = 0;
    src_65.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_65,0,319,59,(int16_t)unaff_DI,0x3b);
    l3Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    l3Cut3Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(330,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar9);
    src_66.seg = 0;
    src_66.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_66,0,319,59,(int16_t)unaff_DI,0x3b);
    l6Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    l6Cut1Seg = (uint16_t)(puVar7);
    l6Cut2Ofs =(uint16_t)( (far_t *)ovr_stshWrite((uint32_t *)(psVar1->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,puVar9),ZEXT24(unaff_DI) << 0x10,0));
    l6Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(330,320,0,0);
    puVar9 = (uint16_t)(puVar7);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar7);
    src_67.seg = 0;
    src_67.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_67,0,319,59,(int16_t)unaff_DI,0x3b);
    l6Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    l6Cut3Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(333,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar9);
    src_68.seg = 0;
    src_68.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_68,0,319,59,(int16_t)unaff_DI,0x3b);
    l9Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    l9Cut1Seg = (uint16_t)(puVar7);
    l9Cut2Ofs =(uint16_t)( (far_t *)ovr_stshWrite((uint32_t *)(psVar1->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,puVar9),ZEXT24(unaff_DI) << 0x10,0));
    l9Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(333,320,0,0);
    puVar9 = (uint16_t)(puVar7);
    ovr_stshUniqueColorsRemap(psVar1,(char)puVar7);
    src_69.seg = 0;
    src_69.ofs = (psVar1->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_69,0,319,59,(int16_t)unaff_DI,0x3b);
    l9Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    l9Cut3Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
  }
  else {
    gamfont1Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    gamfont1Cut1Seg = (uint16_t)(puVar9);
    davfontCut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    davfontCut1Seg = (uint16_t)(puVar9);
    davfont2Cut1Ofs =(uint16_t)( (cte_t *)ovr_stshAllocStub(unaff_DI));
    davfont2Cut1Seg = (uint16_t)(puVar9);
    demfont1FontOfs = ovr_stshAllocStub(unaff_DI);
    demfont1FontSeg = (uint16_t)(puVar9);
    talkwin9Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    talkwin9Cut1Seg = (uint16_t)(puVar9);
    talkwin9Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    talkwin9Cut2Seg = (uint16_t)(puVar9);
    talkwin9Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    talkwin9Cut3Seg = (uint16_t)(puVar9);
    talkwin9Cut4Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    talkwin9Cut4Seg = (uint16_t)(puVar9);
    talkwin9Cut5Ofs = ovr_stshAllocStub(unaff_DI);
    talkwin9Cut5Seg = (uint16_t)(puVar9);
    LbxButton2.ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    LbxButton2.seg = (uint16_t)puVar9;
    butt01Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    butt01Cut1Seg = (uint16_t)(puVar9);
    butt01Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    butt01Cut2Seg = (uint16_t)(puVar9);
    butt01Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    butt01Cut3Seg = (uint16_t)(puVar9);
    butt01Cut4Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    butt01Cut4Seg = (uint16_t)(puVar9);
    butt01Cut5Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    butt01Cut5Seg = (uint16_t)(puVar9);
    butt01Cut6Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    butt01Cut6Seg = (uint16_t)(puVar9);
    button1Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    button1Cut1Seg = (uint16_t)(puVar9);
    button1Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    button1Cut2Seg = (uint16_t)(puVar9);
    button1Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    button1Cut3Seg = (uint16_t)(puVar9);
    back03Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    back03Cut1Seg = (uint16_t)(puVar9);
    back03Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    back03Cut2Seg = (uint16_t)(puVar9);
    midgrnd5Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    midgrnd5Cut1Seg = (uint16_t)(puVar9);
    midgrnd5Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    midgrnd5Cut2Seg = (uint16_t)(puVar9);
    strong4Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    strong4Cut1Seg = (uint16_t)(puVar9);
    strong4Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    strong4Cut2Seg = (uint16_t)(puVar9);
    marbleCut1Ofs = ovr_stshAllocStub(unaff_DI);
    marbleCut1Seg = (uint16_t)(puVar9);
    marbleCut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    marbleCut2Seg = (uint16_t)(puVar9);
    far_t_2000_d3e4.ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    far_t_2000_d3e4.seg = (uint16_t)puVar9;
    back2Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    back2Cut1Seg = (uint16_t)(puVar9);
    back2Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    back2Cut2Seg = (uint16_t)(puVar9);
    midl3Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    midl3Cut1Seg = (uint16_t)(puVar9);
    midl3Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    midl3Cut2Seg = (uint16_t)(puVar9);
    frnt3Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    frnt3Cut1Seg = (uint16_t)(puVar9);
    frnt3Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    frnt3Cut2Seg = (uint16_t)(puVar9);
    winrebg1Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    winrebg1Cut1Seg = (uint16_t)(puVar9);
    winrebg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    winrebg1Cut2Seg = (uint16_t)(puVar9);
    winremg2Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    winremg2Cut1Seg = (uint16_t)(puVar9);
    winremg2Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    winremg2Cut2Seg = (uint16_t)(puVar9);
    winrefg1Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    winrefg1Cut1Seg = (uint16_t)(puVar9);
    winrefg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    winrefg1Cut2Seg = (uint16_t)(puVar9);
    captbg2Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    captbg2Cut1Seg = (uint16_t)(puVar9);
    captbg2Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    captbg2Cut2Seg = (uint16_t)(puVar9);
    captmg3Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    captmg3Cut1Seg = (uint16_t)(puVar9);
    captmg3Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    captmg3Cut2Seg = (uint16_t)(puVar9);
    captfg1Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    captfg1Cut1Seg = (uint16_t)(puVar9);
    captfg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    captfg1Cut2Seg = (uint16_t)(puVar9);
    l1Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l1Cut1Seg = (uint16_t)(puVar9);
    l1Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l1Cut2Seg = (uint16_t)(puVar9);
    l1Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l1Cut3Seg = (uint16_t)(puVar9);
    l4Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l4Cut1Seg = (uint16_t)(puVar9);
    l4Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l4Cut2Seg = (uint16_t)(puVar9);
    l4Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l4Cut3Seg = (uint16_t)(puVar9);
    l7Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l7Cut1Seg = (uint16_t)(puVar9);
    l7Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l7Cut2Seg = (uint16_t)(puVar9);
    l7Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l7Cut3Seg = (uint16_t)(puVar9);
    l2Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l2Cut1Seg = (uint16_t)(puVar9);
    l2Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l2Cut2Seg = (uint16_t)(puVar9);
    l2Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l2Cut3Seg = (uint16_t)(puVar9);
    l5Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l5Cut1Seg = (uint16_t)(puVar9);
    l5Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l5Cut2Seg = (uint16_t)(puVar9);
    l5Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l5Cut3Seg = (uint16_t)(puVar9);
    l8Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l8Cut1Seg = (uint16_t)(puVar9);
    l8Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l8Cut2Seg = (uint16_t)(puVar9);
    l8Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l8Cut3Seg = (uint16_t)(puVar9);
    l3Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l3Cut1Seg = (uint16_t)(puVar9);
    l3Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l3Cut2Seg = (uint16_t)(puVar9);
    l3Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l3Cut3Seg = (uint16_t)(puVar9);
    l6Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l6Cut1Seg = (uint16_t)(puVar9);
    l6Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l6Cut2Seg = (uint16_t)(puVar9);
    l6Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l6Cut3Seg = (uint16_t)(puVar9);
    l9Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l9Cut1Seg = (uint16_t)(puVar9);
    l9Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l9Cut2Seg = (uint16_t)(puVar9);
    l9Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l9Cut3Seg = (uint16_t)(puVar9);
  }
  ovr_stshInitAudioAssets(grab);
  ovr_stshLoadAudioDrivers(grab);
  ovr_stshInitSprites(grab);
  stshInitTxtFiles(grab);
  if (grab) {
    sky06FliOfs = ovr_stshStoreFile_2((far_t *)(char *)StshNames[0x19f],
                                      (char *)(ulong)(*(uint16_t *)((uint8_t *)&(StshNames[0x19f]) + 2)),(uint16_t)unaff_DI);
    sky06FliSeg = (uint16_t)(puVar9);
    l9Cut4Ofs = ovr_stshStoreFile_2((far_t *)"bolt12.fli",(char *)0x2410,(uint16_t)unaff_DI);
    l9Cut4Seg = (uint16_t)(puVar9);
    psVar1 = ovr_grabLbm(417,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    ssilogoCut1Ofs =(uint16_t)(
         (far_t *)ovr_stshWrite((uint32_t *)psVar1,(uint8_t *)CONCAT22(0x300,puVar9),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_70.seg = 0;
    src_70.ofs = (psVar1->aptr).seg;
    ssilogoCut1Seg = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_70,0,319,199,(int16_t)unaff_DI,199);
    ssilogoCut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    ssilogoCut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(542,0,0,0);
    puVar9 = (uint16_t)(puVar7);
    youlose1Cut1Ofs =(uint16_t)(
         (far_t *)ovr_stshWrite((uint32_t *)psVar1,(uint8_t *)CONCAT22(0x300,puVar7),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_71.seg = 0;
    src_71.ofs = (psVar1->aptr).seg;
    youlose1Cut1Seg = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_71,0,319,144,(int16_t)unaff_DI,0x90);
    youlose1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    youlose1Cut2Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(539,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    cred01Cut1Ofs =(uint16_t)(
         (far_t *)ovr_stshWrite((uint32_t *)psVar1,(uint8_t *)CONCAT22(0x300,puVar9),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_72.seg = 0;
    src_72.ofs = (psVar1->aptr).seg;
    cred01Cut1Seg = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_72,0,319,199,(int16_t)unaff_DI,199);
    cred01Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    cred01Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    psVar1 = ovr_grabLbm(540,0,0,0);
    puVar9 = (uint16_t)(puVar7);
    cred02Cut1Ofs =(uint16_t)(
         (far_t *)ovr_stshWrite((uint32_t *)psVar1,(uint8_t *)CONCAT22(0x300,puVar7),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_73.seg = 0;
    src_73.ofs = (psVar1->aptr).seg;
    cred02Cut1Seg = (uint16_t)(puVar9);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_73,0,319,199,(int16_t)unaff_DI,199);
    cred02Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar9);
    cred02Cut2Seg = (uint16_t)(puVar9);
    ovr_stgFreeTmp(psVar1,(char)puVar7);
    psVar1 = ovr_grabLbm(541,0,0,0);
    puVar7 = (uint16_t)(puVar9);
    cred03Cut1Ofs =(uint16_t)(
         (far_t *)ovr_stshWrite((uint32_t *)psVar1,(uint8_t *)CONCAT22(0x300,puVar9),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_74.seg = 0;
    src_74.ofs = (psVar1->aptr).seg;
    cred03Cut1Seg = (uint16_t)(puVar7);
    pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs,src_74,0,319,199,(int16_t)unaff_DI,199);
    cred03Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)puVar7);
    cred03Cut2Seg = (uint16_t)(puVar7);
    ovr_stgFreeTmp(psVar1,(char)puVar9);
    cred03Cut3Ofs = ovr_stshStoreFile_2((far_t *)"save.999",(char *)0x2410,(uint16_t)unaff_DI);
    cred03Cut3Seg = (uint16_t)(puVar7);
  }
  else {
    sky06FliOfs = ovr_stshAllocStub(unaff_DI);
    sky06FliSeg = (uint16_t)(puVar9);
    l9Cut4Ofs = ovr_stshAllocStub(unaff_DI);
    l9Cut4Seg = (uint16_t)(puVar9);
    ssilogoCut1Ofs = ovr_stshAllocStub(unaff_DI);
    ssilogoCut1Seg = (uint16_t)(puVar9);
    ssilogoCut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    ssilogoCut2Seg = (uint16_t)(puVar9);
    youlose1Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    youlose1Cut1Seg = (uint16_t)(puVar9);
    youlose1Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    youlose1Cut2Seg = (uint16_t)(puVar9);
    cred01Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    cred01Cut1Seg = (uint16_t)(puVar9);
    cred01Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    cred01Cut2Seg = (uint16_t)(puVar9);
    cred02Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    cred02Cut1Seg = (uint16_t)(puVar9);
    cred02Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    cred02Cut2Seg = (uint16_t)(puVar9);
    cred03Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    cred03Cut1Seg = (uint16_t)(puVar9);
    cred03Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    cred03Cut2Seg = (uint16_t)(puVar9);
    cred03Cut3Ofs = ovr_stshAllocStub(unaff_DI);
    cred03Cut3Seg = (uint16_t)(puVar9);
  }
  return;
}
