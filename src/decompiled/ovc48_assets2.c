/*
 * ovc48_assets2.c - recovered from STRONG.EXE
 * memory block: OVC48_assets2.c
 * range: 81b9:0000 - 81b9:4dff
 * functions: 4
 */
#include "recovered.h"


/* 81b9:0000 */
void __cdecl16far stshInitTxtFiles(char grab)

{
  undefined1 stk_ff74;   /* stack slot ff74 */
  far_t far *pfVar1;
  undefined1 *in_DX;
  far_t dst;
  far_t far *in_stack_0000ff74;
  uint auStack_8a [67];
  uint8_t i;
  
  dst.seg = _SS;
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


/* 81b9:0086 */
void __cdecl16far init_assets2(bool grab)

{
  far_t hndl;
  far_t src;
  far_t pixels;
  far_t pixels_00;
  stg_tmp_t *lbmTmp;
  far_t far *pfVar2;
  cte_t *stored;
  uint16_t in_DX;
  uint16_t uVar4;
  uint16_t uVar5;
  uint16_t rleSeg;
  uint8_t *tmpSeg;
  uint8_t *segArg2;
  uint8_t *segArg;
  int i;
  far_t far *unaff_DI;
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
    lbmTmp = ovr_grabLbmTR(527);
    psStack_a = (stg_tmp_t *)CONCAT22(in_DX,lbmTmp);
  }
  i = 0;
  while( true ) {
    if (2 < i) break;
    if (grab) {
      uVar4 = (uint16_t)((ulong)((long)i * 100) >> 0x10);
      pixels_01.seg = (int)((long)i * 100) + 0x14;
      pixels_01.ofs = (psStack_a->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&psStack_a->aptr)->ofs,pixels_01,33,i * 100 + 99,116,10,28,(int16_t)unaff_DI,0x1c,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar4);
      *(uint16_t *)((int)&BldGfxNormal[1].seg + (i + 0xec) * 0xc) = uVar4;
      ((far_t far *)(BldGfxNormal + 1) + (i + 0xec) * 3)->ofs = (uint16_t)stored;
    }
    else {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      *(uint16_t *)((int)&BldGfxNormal[1].seg + (i + 0xec) * 0xc) = in_DX;
      ((far_t far *)(BldGfxNormal + 1) + (i + 0xec) * 3)->ofs = (uint16_t)pfVar2;
    }
    uVar5 = ((far_t far *)(BldGfxNormal + 1) + (i + 0xec) * 3)->ofs;
    *(uint16_t *)((int)&BldGfxNormal[0].seg + (i + 0xec) * 0xc) =
         *(uint16_t *)((int)&BldGfxNormal[1].seg + (i + 0xec) * 0xc);
    ((far_t far *)BldGfxNormal + (i + 0xec) * 3)->ofs = uVar5;
    in_DX = *(uint16_t *)((int)&BldGfxNormal[1].seg + (i + 0xec) * 0xc);
    uVar5 = ((far_t far *)(BldGfxNormal + 1) + (i + 0xec) * 3)->ofs;
    *(uint16_t *)((int)&BldGfxNormal[2].seg + (i + 0xec) * 0xc) = in_DX;
    ((far_t far *)(BldGfxNormal + 2) + (i + 0xec) * 3)->ofs = uVar5;
    i = i + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(psStack_a,(char)((ulong)psStack_a >> 0x10));
    lbmTmp = ovr_grabLbmTR(528);
    psStack_a = (stg_tmp_t *)CONCAT22(in_DX,lbmTmp);
  }
  i = 0;
  while( true ) {
    if (2 < i) break;
    if (grab) {
      uVar4 = (uint16_t)((ulong)((long)i * 100) >> 0x10);
      pixels_02.seg = (int)((long)i * 100) + 0x14;
      pixels_02.ofs = (psStack_a->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&psStack_a->aptr)->ofs,pixels_02,33,i * 100 + 99,116,10,28,(int16_t)unaff_DI,0x1c,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar4);
      *(uint16_t *)((int)&BldGfxRuin[1].seg + (i + 0xec) * 0xc) = uVar4;
      ((far_t far *)(BldGfxRuin + 1) + (i + 0xec) * 3)->ofs = (uint16_t)stored;
    }
    else {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      *(uint16_t *)((int)&BldGfxRuin[1].seg + (i + 0xec) * 0xc) = in_DX;
      ((far_t far *)(BldGfxRuin + 1) + (i + 0xec) * 3)->ofs = (uint16_t)pfVar2;
    }
    in_DX = 0x195d;
    i = i + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(psStack_a,(char)((ulong)psStack_a >> 0x10));
  }
  ovr_stshStubifyCopy1to0(0xec);
  if (grab) {
    lbmTmp = ovr_grabLbmTR(529);
    psStack_a = (stg_tmp_t *)CONCAT22(in_DX,lbmTmp);
    pixels_03.seg = 0;
    pixels_03.ofs = (lbmTmp->aptr).seg;
    uVar5 = in_DX;
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_03,130,99,194,26,-1,(int16_t)unaff_DI,0xff,0);
    asm { mov uVar5,dx };
    BldGfxNormal[0x2e6].ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)(char)uVar5, &stshSegTmp);
    pixels_04.seg = 100;
    pixels_04.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x2e6].seg = stshSegTmp;
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_04,130,199,194,26,-1,(int16_t)unaff_DI,0xff,0);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x2e3].ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_05.seg = 200;
    pixels_05.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x2e3].seg = stshSegTmp;
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_05,130,299,194,26,-1,(int16_t)unaff_DI,0xff,0);
    asm { mov uVar5,dx };
    BldGfxNormal[0x2e0].ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)(char)uVar5, &stshSegTmp);
    pixels_06.seg = 0;
    pixels_06.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x2e0].seg = stshSegTmp;
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_06,65,99,129,26,-1,(int16_t)unaff_DI,0xff,0);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x2dd].ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_07.seg = 100;
    pixels_07.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x2dd].seg = stshSegTmp;
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_07,65,199,129,26,-1,(int16_t)unaff_DI,0xff,0);
    asm { mov uVar5,dx };
    BldGfxNormal[0x2da].ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)(char)uVar5, &stshSegTmp);
    pixels_08.seg = 200;
    pixels_08.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x2da].seg = stshSegTmp;
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_08,65,299,129,26,-1,(int16_t)unaff_DI,0xff,0);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x2d7].ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_09.seg = 0;
    pixels_09.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x2d7].seg = stshSegTmp;
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_09,0,99,64,26,-1,(int16_t)unaff_DI,0xff,0);
    asm { mov uVar5,dx };
    BldGfxNormal[0x2d4].ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)(char)uVar5, &stshSegTmp);
    pixels_10.seg = 100;
    pixels_10.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x2d4].seg = stshSegTmp;
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_10,0,199,64,26,-1,(int16_t)unaff_DI,0xff,0);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x2d1].ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_11.seg = 200;
    pixels_11.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x2d1].seg = stshSegTmp;
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_11,0,299,64,26,-1,(int16_t)unaff_DI,0xff,0);
    asm { mov uVar5,dx };
    BldGfxNormal[0x2ce].ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)(char)uVar5, &stshSegTmp);
    segArg = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
    BldGfxNormal[0x2ce].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)in_DX);
  }
  else {
    BldGfxNormal[0x2e6].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    BldGfxNormal[0x2e6].seg = in_DX;
    BldGfxNormal[0x2e3].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    BldGfxNormal[0x2e3].seg = uVar5;
    BldGfxNormal[0x2e0].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    BldGfxNormal[0x2e0].seg = rleSeg;
    BldGfxNormal[0x2dd].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    BldGfxNormal[0x2dd].seg = uVar5;
    BldGfxNormal[0x2da].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    BldGfxNormal[0x2da].seg = rleSeg;
    BldGfxNormal[0x2d7].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    BldGfxNormal[0x2d7].seg = uVar5;
    BldGfxNormal[0x2d4].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    BldGfxNormal[0x2d4].seg = rleSeg;
    BldGfxNormal[0x2d1].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    BldGfxNormal[0x2d1].seg = uVar5;
    BldGfxNormal[0x2ce].ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    segArg = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
    BldGfxNormal[0x2ce].seg = rleSeg;
  }
  ovr_stshStubifyCopy1to0(0xef);
  ovr_stshStubifyCopy1to0(0xf2);
  ovr_stshStubifyCopy1to0(0xf5);
  for (i = 0; i < 3; i = i + 1) {
    *(uint16_t *)((int)&BldGfxNormal[0].seg + i * 4) = 0;
    ((far_t far *)BldGfxNormal + i)->ofs = 0;
  }
  if (grab) {
    lbmTmp = ovr_grabLbmTR(10);
    pixels_12.seg = 0xc;
    pixels_12.ofs = (lbmTmp->aptr).seg;
    tmpSeg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_12,7,222,150,-12,-7,(int16_t)unaff_DI,0xf9,0);
    asm { mov tmpSeg,dx };
    nwpanel2Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    src_00.seg = 0xef;
    src_00.ofs = (lbmTmp->aptr).seg;
    nwpanel2Cut1Seg =(uint16_t)( tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_00,7,308,54,(int16_t)unaff_DI,0x36,0,0);
    GMenuGfxOfs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    GMenuGfxSeg =(uint16_t)( tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbmTR(14);
    SpecialColors[0] = *(uint8_t *)((int)&GStrangeTable[0x12].ofs + 1 + (lbmTmp->aptr).ofs);
    SpecialColors[1] = ((char *)0x2b021)[(lbmTmp->aptr).ofs];
    SpecialColors[2] = ((char *)0x2b516)[(lbmTmp->aptr).ofs];
    SpecialColors[3] =
         ((char *)0x29fcf)
         [(lbmTmp->aptr).ofs];
    SpecialColors[4] = ((char *)0x2b01f)[(lbmTmp->aptr).ofs];
    SpecialColors[5] = *(uint8_t *)((int)&GStrangeTable[0x12].seg + 1 + (lbmTmp->aptr).ofs);
    SpecialColors[6] = *(uint8_t *)((int)(uint16_t *)&youlose1Cut1Seg + (lbmTmp->aptr).ofs);
    SpecialColors[7] = *(uint8_t *)((lbmTmp->aptr).ofs + 0x936e);
    segArg2 = (uint8_t *)((char *)0x26510);
    specialColorsOfs =(uint16_t)(
         (far_t far *)ovr_stshWrite((uint32_t *)SpecialColors,(uint8_t *)MK_FP(0x2410, 0x8),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_01.seg = 0xea;
    src_01.ofs = (lbmTmp->aptr).seg;
    specialColorsSeg =(uint16_t)( segArg2);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_01,64,314,120,(int16_t)unaff_DI,0x78,0,0);
    trianglsCut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg2);
    src_02.seg = 0xd0;
    src_02.ofs = (lbmTmp->aptr).seg;
    trianglsCut1Seg =(uint16_t)( segArg2);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_02,158,228,176,(int16_t)unaff_DI,0xb0,0,0)
    ;
    trianglsCut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg2);
    src_03.seg = 0xb3;
    src_03.ofs = (lbmTmp->aptr).seg;
    trianglsCut2Seg =(uint16_t)( segArg2);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_03,180,198,196,(int16_t)unaff_DI,0xc4,0,0)
    ;
    trianglsCut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg2);
    src_04.seg = 0xcf;
    src_04.ofs = (lbmTmp->aptr).seg;
    trianglsCut3Seg =(uint16_t)( segArg2);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_04,180,226,196,(int16_t)unaff_DI,0xc4,0,0)
    ;
    trianglsCut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg2);
    src_05.seg = 0x26;
    src_05.ofs = (lbmTmp->aptr).seg;
    trianglsCut4Seg =(uint16_t)( segArg2);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_05,181,57,196,(int16_t)unaff_DI,0xc4,0,0);
    trianglsCut5Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg2);
    src_06.seg = 9;
    src_06.ofs = (lbmTmp->aptr).seg;
    trianglsCut5Seg =(uint16_t)( segArg2);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_06,181,24,196,(int16_t)unaff_DI,0xc4,0,0);
    trianglsCut6Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg2);
    trianglsCut6Seg =(uint16_t)( segArg2);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbmTR(127);
    src_07.seg = 0xf5;
    src_07.ofs = (lbmTmp->aptr).seg;
    segArg = (uint16_t)(segArg2);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_07,116,267,128,(int16_t)unaff_DI,0x80,0,0)
    ;
    panel01Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    src_08.seg = 0x124;
    src_08.ofs = (lbmTmp->aptr).seg;
    panel01Cut1Seg =(uint16_t)( segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_08,114,314,133,(int16_t)unaff_DI,0x85,0,0)
    ;
    panel01Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    src_09.seg = 0xdd;
    src_09.ofs = (lbmTmp->aptr).seg;
    panel01Cut2Seg =(uint16_t)( segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_09,157,228,198,(int16_t)unaff_DI,0xc6,0,0)
    ;
    panel01Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    panel01Cut3Seg =(uint16_t)( segArg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg2);
    lbmTmp = ovr_grabLbm(15,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    Lbm_nwpanel1.ofs =
         (uint16_t)
         ovr_stshWrite((uint32_t *)lbmTmp,(uint8_t *)CONCAT22(0x300,segArg),ZEXT24(unaff_DI) << 0x10
                       ,0);
    src_10.seg = 0xe6;
    src_10.ofs = (lbmTmp->aptr).seg;
    Lbm_nwpanel1.seg = (uint16_t)tmpSeg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_10,57,314,113,(int16_t)unaff_DI,0x71,0,0);
    nwpanel1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    src_11.seg = 0;
    src_11.ofs = (lbmTmp->aptr).seg;
    nwpanel1Cut1Seg =(uint16_t)( tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_11,0,319,199,(int16_t)unaff_DI,199,0,0);
    fullScreenGfxOfs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    src_12.seg = 0x1d;
    src_12.ofs = (lbmTmp->aptr).seg;
    fullScreenGfxSeg =(uint16_t)( tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_12,156,207,199,(int16_t)unaff_DI,199,0,0);
    FontHandle.ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)(char)tmpSeg, &stshSegTmp);
    src_13.seg = 9;
    src_13.ofs = (lbmTmp->aptr).seg;
    FontHandle.seg = (uint16_t)tmpSeg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_13,181,28,196,(int16_t)unaff_DI,0xc4,0,0);
    nwpanel1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    src_14.seg = 0xdf;
    src_14.ofs = (lbmTmp->aptr).seg;
    nwpanel1Cut2Seg =(uint16_t)( tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_14,8,237,50,(int16_t)unaff_DI,0x32,0,0);
    nwpanel1Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    src_15.seg = 6;
    src_15.ofs = (lbmTmp->aptr).seg;
    nwpanel1Cut3Seg =(uint16_t)( tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_15,156,28,171,(int16_t)unaff_DI,0xab,0,0);
    nwpanel1Cut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    src_16.seg = 0xd0;
    src_16.ofs = (lbmTmp->aptr).seg;
    nwpanel1Cut4Seg =(uint16_t)( tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_16,157,229,198,(int16_t)unaff_DI,0xc6,0,0)
    ;
    nwpanel1Cut5Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    nwpanel1Cut5Seg =(uint16_t)( tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(12,0,0,0,0);
    psStack_a = (stg_tmp_t *)CONCAT22(tmpSeg,lbmTmp);
    segArg = (uint16_t)(tmpSeg);
    for (i = 0; i < 4; i = i + 1) {
      uVar4 = (uint16_t)((ulong)((long)i * 0xe) >> 0x10);
      src.seg = (uint16_t)((long)i * 0xe);
      src.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src,46,i * 0xe + 0xd,55,(int16_t)unaff_DI,0x37,0,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)uVar4);
      *(uint16_t *)((int)&CrossBlitGfx.seg + i * 4) = uVar4;
      ((far_t far *)&CrossBlitGfx + i)->ofs = (uint16_t)stored;
      segArg = (uint8_t *)((ulong)((long)i * 0xe) >> 0x10);
      pixels.seg = (uint16_t)((long)i * 0xe);
      pixels.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels,16,i * 0xe + 0xd,24,6,4,(int16_t)unaff_DI,4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&crossBlitType2Seg)[i * 2] =(uint16_t)( segArg);
      ((uint16_t *)&crossBlitType2Ofs)[i * 2] =(uint16_t)( stored);
    }
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
  }
  else {
    nwpanel2Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    nwpanel2Cut1Seg =(uint16_t)( segArg);
    GMenuGfxOfs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    GMenuGfxSeg =(uint16_t)( segArg);
    specialColorsOfs = ovr_stshAllocStub(unaff_DI);
    specialColorsSeg =(uint16_t)( segArg);
    trianglsCut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    trianglsCut1Seg =(uint16_t)( segArg);
    trianglsCut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    trianglsCut2Seg =(uint16_t)( segArg);
    trianglsCut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    trianglsCut3Seg =(uint16_t)( segArg);
    trianglsCut4Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    trianglsCut4Seg =(uint16_t)( segArg);
    trianglsCut5Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    trianglsCut5Seg =(uint16_t)( segArg);
    trianglsCut6Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    trianglsCut6Seg =(uint16_t)( segArg);
    panel01Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    panel01Cut1Seg =(uint16_t)( segArg);
    panel01Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    panel01Cut2Seg =(uint16_t)( segArg);
    panel01Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    panel01Cut3Seg =(uint16_t)( segArg);
    Lbm_nwpanel1.ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    Lbm_nwpanel1.seg = (uint16_t)segArg;
    nwpanel1Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    nwpanel1Cut1Seg =(uint16_t)( segArg);
    fullScreenGfxOfs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    fullScreenGfxSeg =(uint16_t)( segArg);
    FontHandle.ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    FontHandle.seg = (uint16_t)segArg;
    nwpanel1Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    nwpanel1Cut2Seg =(uint16_t)( segArg);
    nwpanel1Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    nwpanel1Cut3Seg =(uint16_t)( segArg);
    nwpanel1Cut4Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    nwpanel1Cut4Seg =(uint16_t)( segArg);
    nwpanel1Cut5Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    nwpanel1Cut5Seg =(uint16_t)( segArg);
    for (i = 0; i < 4; i = i + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      *(uint16_t *)((int)&CrossBlitGfx.seg + i * 4) =(uint16_t)( segArg);
      ((far_t far *)&CrossBlitGfx + i)->ofs = (uint16_t)pfVar2;
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((uint16_t *)&crossBlitType2Seg)[i * 2] =(uint16_t)( segArg);
      ((uint16_t *)&crossBlitType2Ofs)[i * 2] =(uint16_t)( pfVar2);
    }
  }
  if (grab) {
    lbmTmp = ovr_grabLbm(93,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    for (i = 0; i < 6; i = i + 1) {
      pixels_13.seg = 8;
      pixels_13.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_13,i * 0x20 + 10,63,i * 0x20 + 0x24,0,0,(int16_t)unaff_DI,0,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
      ((uint16_t *)&csite1Seg)[i * 2] =(uint16_t)( tmpSeg);
      ((uint16_t *)&csite1Ofs)[i * 2] =(uint16_t)( stored);
    }
    for (i = 0; i < 6; i = i + 1) {
      pixels_14.seg = 0x55;
      pixels_14.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_14,i * 0x20 + 10,140,i * 0x20 + 0x24,0,0,(int16_t)unaff_DI,0,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
      ((uint16_t *)&csite1_6Seg)[i * 2] =(uint16_t)( tmpSeg);
      ((uint16_t *)&csite1_6Ofs)[i * 2] =(uint16_t)( stored);
    }
    for (i = 0; i < 6; i = i + 1) {
      pixels_15.seg = 0x9f;
      pixels_15.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_15,i * 0x20 + 10,214,i * 0x20 + 0x24,0,0,(int16_t)unaff_DI,0,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
      ((uint16_t *)&csite1_12Seg)[i * 2] =(uint16_t)( tmpSeg);
      ((uint16_t *)&csite1_12Ofs)[i * 2] =(uint16_t)( stored);
    }
    for (i = 0; i < 5; i = i + 1) {
      pixels_16.seg = 0xe5;
      pixels_16.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_16,i * 0x20 + 10,284,i * 0x20 + 0x24,0,0,(int16_t)unaff_DI,0,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
      ((uint16_t *)&csite1_18Seg)[i * 2] = (uint16_t)(tmpSeg);
      ((uint16_t *)&csite1_18Ofs)[i * 2] = (uint16_t)(stored);
    }
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(94,0,0,0,0);
    segArg = (uint16_t)(tmpSeg);
    for (i = 0; i < 3; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_17.seg = 0;
      pixels_17.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_17,(int)((long)i * 0x3d) + 0x11,104,i * 0x3d + 0x49,0,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&csite2Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&csite2Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 3; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_18.seg = 0x6d;
      pixels_18.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_18,(int)((long)i * 0x3d) + 0x11,213,i * 0x3d + 0x49,0,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&csite2_3Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&csite2_3Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 3; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_19.seg = 0xd7;
      pixels_19.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_19,(int)((long)i * 0x3d) + 0x11,319,i * 0x3d + 0x49,0,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&csite2_6Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&csite2_6Ofs)[i * 2] = (uint16_t)(stored);
    }
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(95,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    for (i = 0; i < 3; i = i + 1) {
      tmpSeg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_20.seg = 0;
      pixels_20.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_20,(int)((long)i * 0x3d) + 0x11,104,i * 0x3d + 0x49,0,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
      ((uint16_t *)&csite3Seg)[i * 2] = (uint16_t)(tmpSeg);
      ((uint16_t *)&csite3Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 3; i = i + 1) {
      tmpSeg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_21.seg = 0x6d;
      pixels_21.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_21,(int)((long)i * 0x3d) + 0x11,213,i * 0x3d + 0x49,0,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
      ((uint16_t *)&csite3_3Seg)[i * 2] = (uint16_t)(tmpSeg);
      ((uint16_t *)&csite3_3Ofs)[i * 2] = (uint16_t)(stored);
    }
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(96,0,0,0,0);
    segArg = (uint16_t)(tmpSeg);
    for (i = 0; i < 3; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_22.seg = 0;
      pixels_22.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_22,(int)((long)i * 0x3d) + 0x11,104,i * 0x3d + 0x49,0,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&csite4Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&csite4Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 3; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_23.seg = 0x6d;
      pixels_23.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_23,(int)((long)i * 0x3d) + 0x11,213,i * 0x3d + 0x49,0,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&csite4_3Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&csite4_3Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 3; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_24.seg = 0xd7;
      pixels_24.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_24,(int)((long)i * 0x3d) + 0x11,319,i * 0x3d + 0x49,0,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&csite4_6Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&csite4_6Ofs)[i * 2] = (uint16_t)(stored);
    }
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(531,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    for (i = 0; i < 3; i = i + 1) {
      tmpSeg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_25.seg = 1;
      pixels_25.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_25,(int)((long)i * 0x3d) + 0x11,103,i * 0x3d + 0x49,-4,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
      ((uint16_t *)&csite5Seg)[i * 2] = (uint16_t)(tmpSeg);
      ((uint16_t *)&csite5Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 3; i = i + 1) {
      tmpSeg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_26.seg = 0x68;
      pixels_26.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_26,(int)((long)i * 0x3d) + 0x11,206,i * 0x3d + 0x49,-4,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
      ((uint16_t *)&csite5_3Seg)[i * 2] = (uint16_t)(tmpSeg);
      ((uint16_t *)&csite5_3Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 3; i = i + 1) {
      tmpSeg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_27.seg = 0xd1;
      pixels_27.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_27,(int)((long)i * 0x3d) + 0x11,311,i * 0x3d + 0x49,-4,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
      ((uint16_t *)&csite5_6Seg)[i * 2] = (uint16_t)(tmpSeg);
      ((uint16_t *)&csite5_6Ofs)[i * 2] = (uint16_t)(stored);
    }
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(532,0,0,0,0);
    segArg = (uint16_t)(tmpSeg);
    for (i = 0; i < 3; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_28.seg = 1;
      pixels_28.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_28,(int)((long)i * 0x3d) + 0x11,103,i * 0x3d + 0x49,-4,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&csite6Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&csite6Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 3; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_29.seg = 0x68;
      pixels_29.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_29,(int)((long)i * 0x3d) + 0x11,206,i * 0x3d + 0x49,-4,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&csite6_3Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&csite6_3Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 3; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_30.seg = 0xd1;
      pixels_30.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_30,(int)((long)i * 0x3d) + 0x11,311,i * 0x3d + 0x49,-4,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&csite6_6Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&csite6_6Ofs)[i * 2] = (uint16_t)(stored);
    }
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(533,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    for (i = 0; i < 3; i = i + 1) {
      tmpSeg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_31.seg = 1;
      pixels_31.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_31,(int)((long)i * 0x3d) + 0x11,103,i * 0x3d + 0x49,-4,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
      ((uint16_t *)&csite7Seg)[i * 2] = (uint16_t)(tmpSeg);
      ((uint16_t *)&csite7Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 3; i = i + 1) {
      tmpSeg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_32.seg = 0x68;
      pixels_32.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_32,(int)((long)i * 0x3d) + 0x11,206,i * 0x3d + 0x49,-4,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
      ((uint16_t *)&csite7_3Seg)[i * 2] = (uint16_t)(tmpSeg);
      ((uint16_t *)&csite7_3Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 3; i = i + 1) {
      tmpSeg = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_33.seg = 0xd1;
      pixels_33.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_33,(int)((long)i * 0x3d) + 0x11,311,i * 0x3d + 0x49,-4,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
      ((uint16_t *)&csite7_6Seg)[i * 2] = (uint16_t)(tmpSeg);
      ((uint16_t *)&csite7_6Ofs)[i * 2] = (uint16_t)(stored);
    }
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(534,0,0,0,0);
    segArg2 = (uint16_t)(tmpSeg);
    for (i = 0; i < 3; i = i + 1) {
      segArg2 = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_34.seg = 1;
      pixels_34.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_34,(int)((long)i * 0x3d) + 0x11,103,i * 0x3d + 0x49,-4,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg2);
      ((uint16_t *)&csite8Seg)[i * 2] = (uint16_t)(segArg2);
      ((uint16_t *)&csite8Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 2; i = i + 1) {
      segArg2 = (uint8_t *)((ulong)((long)i * 0x3d) >> 0x10);
      pixels_35.seg = 0x68;
      pixels_35.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_35,(int)((long)i * 0x3d) + 0x11,206,i * 0x3d + 0x49,-4,-60,(int16_t)unaff_DI,0xc4,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg2);
      ((uint16_t *)&csite8_3Seg)[i * 2] = (uint16_t)(segArg2);
      ((uint16_t *)&csite8_3Ofs)[i * 2] = (uint16_t)(stored);
    }
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(535,0,0,0,0);
    psStack_a = (stg_tmp_t *)CONCAT22(segArg2,lbmTmp);
    segArg = (uint16_t)(segArg2);
    for (i = 0; i < 7; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x1b) >> 0x10);
      pixels_36.seg = 6;
      pixels_36.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_36,(int)((long)i * 0x1b) + 8,33,i * 0x1b + 0x13,0,0,(int16_t)unaff_DI,0,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&tmstrsSprites6Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites6Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 7; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x1b) >> 0x10);
      pixels_37.seg = 0x23;
      pixels_37.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_37,(int)((long)i * 0x1b) + 8,62,i * 0x1b + 0x13,0,0,(int16_t)unaff_DI,0,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&tmstrsSprites9Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites9Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 7; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x1b) >> 0x10);
      pixels_38.seg = 0x4c;
      pixels_38.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_38,(int)((long)i * 0x1b) + 8,88,i * 0x1b + 0x13,0,0,(int16_t)unaff_DI,0,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&tmstrsSprites5Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites5Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 7; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x1b) >> 0x10);
      pixels_39.seg = 0x66;
      pixels_39.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_39,(int)((long)i * 0x1b) + 8,114,i * 0x1b + 0x13,0,0,(int16_t)unaff_DI,0,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&tmstrsSprites6Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites6Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 3; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x1b) >> 0x10);
      pixels_40.seg = 0x80;
      pixels_40.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_40,(int)((long)i * 0x1b) + 8,140,i * 0x1b + 0x13,0,0,(int16_t)unaff_DI,0,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&tmstrsSprites7Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites7Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 7; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x1b) >> 0x10);
      pixels_41.seg = 0x9a;
      pixels_41.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_41,(int)((long)i * 0x1b) + 8,163,i * 0x1b + 0x13,0,0,(int16_t)unaff_DI,0,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&tmstrsSprites4Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites4Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 7; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x1b) >> 0x10);
      pixels_42.seg = 0xb8;
      pixels_42.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_42,(int)((long)i * 0x1b) + 8,185,i * 0x1b + 0x13,0,0,(int16_t)unaff_DI,0,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&tmstrsSprites3Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites3Ofs)[i * 2] = (uint16_t)(stored);
    }
    for (i = 0; i < 7; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x1b) >> 0x10);
      pixels_43.seg = 0xcf;
      pixels_43.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_43,(int)((long)i * 0x1b) + 8,223,i * 0x1b + 0x13,0,0,(int16_t)unaff_DI,0,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&tmstrsSprites2Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites2Ofs)[i * 2] = (uint16_t)(stored);
    }
    pixels_44.seg = 0xeb;
    pixels_44.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_44,8,251,19,0,0,(int16_t)unaff_DI,0,0);
    anim_tmstrsCut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    anim_tmstrsCut1Seg = (uint16_t)(segArg);
    for (i = 0; i < 5; i = i + 1) {
      segArg = (uint8_t *)((ulong)((long)i * 0x1b) >> 0x10);
      pixels_45.seg = 0x10b;
      pixels_45.ofs = (lbmTmp->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_45,(int)((long)i * 0x1b) + 8,286,i * 0x1b + 0x13,0,0,(int16_t)unaff_DI,0,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&tmstrsSprites1Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites1Ofs)[i * 2] = (uint16_t)(stored);
    }
    ovr_stgFreeTmp(lbmTmp,(char)segArg2);
  }
  else {
    for (i = 0; i < 0x17; i = i + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((uint16_t *)&csite1Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&csite1Ofs)[i * 2] = (uint16_t)(pfVar2);
    }
    for (i = 0; i < 0x18; i = i + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((uint16_t *)&csite2Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&csite2Ofs)[i * 2] = (uint16_t)(pfVar2);
    }
    for (i = 0; i < 0x20; i = i + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((uint16_t *)&csite5Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&csite5Ofs)[i * 2] = (uint16_t)(pfVar2);
    }
    for (i = 0; i < 0xe; i = i + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((uint16_t *)&tmstrsSprites6Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites6Ofs)[i * 2] = (uint16_t)(pfVar2);
    }
    for (i = 0; i < 0x11; i = i + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((uint16_t *)&tmstrsSprites5Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites5Ofs)[i * 2] = (uint16_t)(pfVar2);
    }
    for (i = 0; i < 7; i = i + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((uint16_t *)&tmstrsSprites4Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites4Ofs)[i * 2] = (uint16_t)(pfVar2);
    }
    for (i = 0; i < 7; i = i + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((uint16_t *)&tmstrsSprites3Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites3Ofs)[i * 2] = (uint16_t)(pfVar2);
    }
    for (i = 0; i < 8; i = i + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((uint16_t *)&tmstrsSprites2Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites2Ofs)[i * 2] = (uint16_t)(pfVar2);
    }
    for (i = 0; i < 5; i = i + 1) {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((uint16_t *)&tmstrsSprites1Seg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&tmstrsSprites1Ofs)[i * 2] = (uint16_t)(pfVar2);
    }
  }
  if (grab) {
    lbmTmp = ovr_grabLbm(35,0,0,0,0);
    psStack_a = (stg_tmp_t *)CONCAT22(segArg,lbmTmp);
  }
  i = 0;
  while( true ) {
    if (3 < i) break;
    if (grab) {
      segArg = (uint8_t *)((ulong)((long)i * 0x16) >> 0x10);
      pixels_00.seg = (uint16_t)((long)i * 0x16);
      pixels_00.ofs = (psStack_a->aptr).seg;
      pfVar2 = ovr_stshRleType2((far_t far *)(&psStack_a->aptr)->ofs,pixels_00,0,i * 0x16 + 0x15,14,11,7,(int16_t)unaff_DI,7,0);
      stored = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
      ((uint16_t *)&boltSpritesSeg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&boltSpritesOfs)[i * 2] = (uint16_t)(stored);
    }
    else {
      pfVar2 = ovr_stshAllocStub(unaff_DI);
      ((uint16_t *)&boltSpritesSeg)[i * 2] = (uint16_t)(segArg);
      ((uint16_t *)&boltSpritesOfs)[i * 2] = (uint16_t)(pfVar2);
    }
    i = i + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(psStack_a,(char)((ulong)psStack_a >> 0x10));
    lbmTmp = ovr_grabLbm(8,0,0,0,0);
    src_17.seg = 0;
    src_17.ofs = (lbmTmp->aptr).seg;
    tmpSeg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_17,0,319,199,(int16_t)unaff_DI,199,0,0);
    gamfont1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    gamfont1Cut1Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(6,0,0,0,0);
    src_18.seg = 0;
    src_18.ofs = (lbmTmp->aptr).seg;
    segArg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_18,0,319,199,(int16_t)unaff_DI,199,0,0);
    davfontCut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    davfontCut1Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(140,0,0,0,0);
    src_19.seg = 0;
    src_19.ofs = (lbmTmp->aptr).seg;
    tmpSeg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_19,0,319,27,(int16_t)unaff_DI,0x1b,0,0);
    davfont2Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    davfont2Cut1Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(411,0,0,0,0);
    FontSize.hi = 0;
    FontSize.lo = 0;
    uVar5 = (lbmTmp->aptr).seg;
    hndl.seg = (uint16_t)unaff_DI;
    hndl.ofs = uVar5;
    segArg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshProcessFontSub((far_t far *)(&lbmTmp->aptr)->ofs,hndl,(char)uVar5);
    demfont1FontOfs =(uint16_t)(
         (far_t far *)ovr_stshWrite((uint32_t *)pfVar2,(uint8_t *)CONCAT22(FontSize.lo,segArg),
                                CONCAT22(unaff_DI,FontSize.hi),(char)FontSize.hi));
    demfont1FontSeg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(78,0,0,0,0);
    pixels_46.seg = 8;
    pixels_46.ofs = (lbmTmp->aptr).seg;
    tmpSeg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_46,3,226,194,-8,-3,(int16_t)unaff_DI,0xfd,0);
    talkwin9Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    pixels_47.seg = 0xdd;
    pixels_47.ofs = (lbmTmp->aptr).seg;
    talkwin9Cut1Seg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_47,157,229,198,-221,-157,(int16_t)unaff_DI,99,0);
    talkwin9Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    pixels_48.seg = 0xd0;
    pixels_48.ofs = (lbmTmp->aptr).seg;
    talkwin9Cut2Seg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_48,195,223,199,-208,-195,(int16_t)unaff_DI,0x3d,0);
    talkwin9Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    pixels_49.seg = 8;
    pixels_49.ofs = (lbmTmp->aptr).seg;
    talkwin9Cut3Seg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_49,117,226,194,-8,-117,(int16_t)unaff_DI,0x8b,0);
    asm { mov segArg,dx };
    talkwin9Cut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    talkwin9Cut4Seg = (uint16_t)(tmpSeg);
    talkwin9Cut5Ofs =(uint16_t)(
         (far_t far *)ovr_stshWrite((uint32_t *)lbmTmp,(uint8_t *)CONCAT22(0x300,segArg),
                                ZEXT24(unaff_DI) << 0x10,0));
    talkwin9Cut5Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(543,0,0,0,0);
    src_20.seg = 8;
    src_20.ofs = (lbmTmp->aptr).seg;
    segArg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_20,5,16,10,(int16_t)unaff_DI,10,0,0);
    LbxButton2.ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)(char)segArg, &stshSegTmp);
    LbxButton2.seg = (uint16_t)segArg;
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(139,0,0,0,0);
    src_21.seg = 0x10;
    src_21.ofs = (lbmTmp->aptr).seg;
    tmpSeg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_21,121,57,131,(int16_t)unaff_DI,0x83,0,0);
    butt01Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    src_22.seg = 0x10;
    src_22.ofs = (lbmTmp->aptr).seg;
    butt01Cut1Seg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_22,134,57,144,(int16_t)unaff_DI,0x90,0,0);
    butt01Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    src_23.seg = 0xea;
    src_23.ofs = (lbmTmp->aptr).seg;
    butt01Cut2Seg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_23,121,300,131,(int16_t)unaff_DI,0x83,0,0)
    ;
    butt01Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    src_24.seg = 0xea;
    src_24.ofs = (lbmTmp->aptr).seg;
    butt01Cut3Seg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_24,134,300,144,(int16_t)unaff_DI,0x90,0,0)
    ;
    butt01Cut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    src_25.seg = 0x99;
    src_25.ofs = (lbmTmp->aptr).seg;
    butt01Cut4Seg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_25,121,230,131,(int16_t)unaff_DI,0x83,0,0)
    ;
    butt01Cut5Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    src_26.seg = 0x99;
    src_26.ofs = (lbmTmp->aptr).seg;
    butt01Cut5Seg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_26,134,230,144,(int16_t)unaff_DI,0x90,0,0)
    ;
    butt01Cut6Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    butt01Cut6Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(179,0,0,0,0);
    src_27.seg = 0x5e;
    src_27.ofs = (lbmTmp->aptr).seg;
    segArg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_27,47,108,89,(int16_t)unaff_DI,0x59,0,0);
    button1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    src_28.seg = 0x72;
    src_28.ofs = (lbmTmp->aptr).seg;
    button1Cut1Seg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_28,47,128,89,(int16_t)unaff_DI,0x59,0,0);
    button1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    src_29.seg = 0xdf;
    src_29.ofs = (lbmTmp->aptr).seg;
    button1Cut2Seg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_29,8,237,50,(int16_t)unaff_DI,0x32,0,0);
    button1Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    button1Cut3Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(158,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    back03Cut1Ofs =(uint16_t)(
         (far_t far *)ovr_stshWrite((uint32_t *)lbmTmp,(uint8_t *)CONCAT22(0x300,segArg),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_30.seg = 0;
    src_30.ofs = (lbmTmp->aptr).seg;
    back03Cut1Seg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_30,0,319,80,(int16_t)unaff_DI,0x50,0,0);
    back03Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    back03Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(159,0,0,0,0);
    src_31.seg = 0;
    src_31.ofs = (lbmTmp->aptr).seg;
    segArg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_31,0,219,143,(int16_t)unaff_DI,0x8f,0,0);
    midgrnd5Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    midgrnd5Cut1Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(159,220,0,0,0);
    src_32.seg = 0;
    src_32.ofs = (lbmTmp->aptr).seg;
    tmpSeg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_32,0,219,143,(int16_t)unaff_DI,0x8f,0,0);
    midgrnd5Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    midgrnd5Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(160,0,0,0,0);
    src_33.seg = 0;
    src_33.ofs = (lbmTmp->aptr).seg;
    segArg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_33,0,279,143,(int16_t)unaff_DI,0x8f,0,0);
    strong4Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    strong4Cut1Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(160,280,0,0,0);
    src_34.seg = 0;
    src_34.ofs = (lbmTmp->aptr).seg;
    tmpSeg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_34,0,279,143,(int16_t)unaff_DI,0x8f,0,0);
    strong4Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    strong4Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(161,0,0,0,0);
    segArg = (uint16_t)(tmpSeg);
    marbleCut1Ofs =(uint16_t)(
         (far_t far *)ovr_stshWrite((uint32_t *)lbmTmp,(uint8_t *)CONCAT22(0x300,tmpSeg),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_35.seg = 0;
    src_35.ofs = (lbmTmp->aptr).seg;
    marbleCut1Seg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_35,144,319,199,(int16_t)unaff_DI,199,0,0);
    marbleCut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    src_36.seg = 0;
    src_36.ofs = (lbmTmp->aptr).seg;
    marbleCut2Seg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_36,0,47,10,(int16_t)unaff_DI,10,0,0);
    far_t_2000_d3e4.ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)(char)segArg, &stshSegTmp);
    far_t_2000_d3e4.seg = (uint16_t)segArg;
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(412,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    back2Cut1Ofs =(uint16_t)( (far_t far *)ovr_stshWrite((uint32_t *)lbmTmp,(uint8_t *)CONCAT22(0x300,segArg),
                                          ZEXT24(unaff_DI) << 0x10,0));
    src_37.seg = 0;
    src_37.ofs = (lbmTmp->aptr).seg;
    back2Cut1Seg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_37,0,319,80,(int16_t)unaff_DI,0x50,0,0);
    back2Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    back2Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(414,0,0,0,0);
    src_38.seg = 0;
    src_38.ofs = (lbmTmp->aptr).seg;
    segArg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_38,0,219,143,(int16_t)unaff_DI,0x8f,0,0);
    midl3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    midl3Cut1Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(414,220,0,0,0);
    src_39.seg = 0;
    src_39.ofs = (lbmTmp->aptr).seg;
    tmpSeg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_39,0,219,143,(int16_t)unaff_DI,0x8f,0,0);
    midl3Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    midl3Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(413,0,0,0,0);
    src_40.seg = 0;
    src_40.ofs = (lbmTmp->aptr).seg;
    segArg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_40,0,279,143,(int16_t)unaff_DI,0x8f,0,0);
    frnt3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    frnt3Cut1Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(413,280,0,0,0);
    src_41.seg = 0;
    src_41.ofs = (lbmTmp->aptr).seg;
    tmpSeg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_41,0,279,143,(int16_t)unaff_DI,0x8f,0,0);
    frnt3Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    frnt3Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(422,0,0,0,0);
    segArg = (uint16_t)(tmpSeg);
    winrebg1Cut1Ofs =(uint16_t)(
         (far_t far *)ovr_stshWrite((uint32_t *)lbmTmp,(uint8_t *)CONCAT22(0x300,tmpSeg),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_42.seg = 0;
    src_42.ofs = (lbmTmp->aptr).seg;
    winrebg1Cut1Seg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_42,0,319,113,(int16_t)unaff_DI,0x71,0,0);
    winrebg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    winrebg1Cut2Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(421,0,0,0,0);
    src_43.seg = 0;
    src_43.ofs = (lbmTmp->aptr).seg;
    tmpSeg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_43,0,219,143,(int16_t)unaff_DI,0x8f,0,0);
    winremg2Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    winremg2Cut1Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(421,220,0,0,0);
    src_44.seg = 0;
    src_44.ofs = (lbmTmp->aptr).seg;
    segArg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_44,0,219,143,(int16_t)unaff_DI,0x8f,0,0);
    winremg2Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    winremg2Cut2Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(420,0,0,0,0);
    src_45.seg = 0;
    src_45.ofs = (lbmTmp->aptr).seg;
    tmpSeg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_45,0,279,143,(int16_t)unaff_DI,0x8f,0,0);
    winrefg1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    winrefg1Cut1Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(420,280,0,0,0);
    src_46.seg = 0;
    src_46.ofs = (lbmTmp->aptr).seg;
    segArg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_46,0,279,143,(int16_t)unaff_DI,0x8f,0,0);
    winrefg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    winrefg1Cut2Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(437,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    captbg2Cut1Ofs =(uint16_t)(
         (far_t far *)ovr_stshWrite((uint32_t *)lbmTmp,(uint8_t *)CONCAT22(0x300,segArg),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_47.seg = 0;
    src_47.ofs = (lbmTmp->aptr).seg;
    captbg2Cut1Seg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_47,0,319,113,(int16_t)unaff_DI,0x71,0,0);
    captbg2Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    captbg2Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(438,0,0,0,0);
    src_48.seg = 0;
    src_48.ofs = (lbmTmp->aptr).seg;
    segArg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_48,0,219,143,(int16_t)unaff_DI,0x8f,0,0);
    captmg3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    captmg3Cut1Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(438,220,0,0,0);
    src_49.seg = 0;
    src_49.ofs = (lbmTmp->aptr).seg;
    tmpSeg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_49,0,219,143,(int16_t)unaff_DI,0x8f,0,0);
    captmg3Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    captmg3Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(439,0,0,0,0);
    src_50.seg = 0;
    src_50.ofs = (lbmTmp->aptr).seg;
    segArg2 = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_50,0,279,143,(int16_t)unaff_DI,0x8f,0,0);
    captfg1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg2);
    captfg1Cut1Seg = (uint16_t)(segArg2);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(439,280,0,0,0);
    src_51.seg = 0;
    src_51.ofs = (lbmTmp->aptr).seg;
    segArg = (uint16_t)(segArg2);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_51,0,279,143,(int16_t)unaff_DI,0x8f,0,0);
    captfg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    captfg1Cut2Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg2);
    lbmTmp = ovr_grabLbm(305,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)segArg);
    src_52.seg = 0;
    src_52.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_52,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    l1Cut1Seg = (uint16_t)(tmpSeg);
    l1Cut2Ofs =(uint16_t)( (far_t far *)ovr_stshWrite((uint32_t *)(lbmTmp->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,segArg),ZEXT24(unaff_DI) << 0x10,0));
    l1Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(305,320,0,0,0);
    segArg = (uint16_t)(tmpSeg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)tmpSeg);
    src_53.seg = 0;
    src_53.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_53,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l1Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    l1Cut3Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(328,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)segArg);
    src_54.seg = 0;
    src_54.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_54,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l4Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    l4Cut1Seg = (uint16_t)(tmpSeg);
    l4Cut2Ofs =(uint16_t)( (far_t far *)ovr_stshWrite((uint32_t *)(lbmTmp->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,segArg),ZEXT24(unaff_DI) << 0x10,0));
    l4Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(328,320,0,0,0);
    segArg2 = (uint16_t)(tmpSeg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)tmpSeg);
    src_55.seg = 0;
    src_55.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_55,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l4Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg2);
    l4Cut3Seg = (uint16_t)(segArg2);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(331,0,0,0,0);
    segArg = (uint16_t)(segArg2);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)segArg2);
    src_56.seg = 0;
    src_56.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_56,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l7Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    l7Cut1Seg = (uint16_t)(segArg);
    l7Cut2Ofs =(uint16_t)( (far_t far *)ovr_stshWrite((uint32_t *)(lbmTmp->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,segArg2),ZEXT24(unaff_DI) << 0x10,0));
    l7Cut2Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg2);
    lbmTmp = ovr_grabLbm(331,320,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)segArg);
    src_57.seg = 0;
    src_57.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_57,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l7Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    l7Cut3Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(307,0,0,0,0);
    segArg = (uint16_t)(tmpSeg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)tmpSeg);
    src_58.seg = 0;
    src_58.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_58,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l2Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    l2Cut1Seg = (uint16_t)(segArg);
    l2Cut2Ofs =(uint16_t)( (far_t far *)ovr_stshWrite((uint32_t *)(lbmTmp->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,tmpSeg),ZEXT24(unaff_DI) << 0x10,0));
    l2Cut2Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(307,320,0,0,0);
    segArg2 = (uint16_t)(segArg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)segArg);
    src_59.seg = 0;
    src_59.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_59,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l2Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg2);
    l2Cut3Seg = (uint16_t)(segArg2);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(329,0,0,0,0);
    tmpSeg = (uint16_t)(segArg2);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)segArg2);
    src_60.seg = 0;
    src_60.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_60,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l5Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    l5Cut1Seg = (uint16_t)(tmpSeg);
    l5Cut2Ofs =(uint16_t)( (far_t far *)ovr_stshWrite((uint32_t *)(lbmTmp->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,segArg2),ZEXT24(unaff_DI) << 0x10,0));
    l5Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg2);
    lbmTmp = ovr_grabLbm(329,320,0,0,0);
    segArg = (uint16_t)(tmpSeg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)tmpSeg);
    src_61.seg = 0;
    src_61.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_61,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l5Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    l5Cut3Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(332,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)segArg);
    src_62.seg = 0;
    src_62.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_62,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l8Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    l8Cut1Seg = (uint16_t)(tmpSeg);
    l8Cut2Ofs =(uint16_t)( (far_t far *)ovr_stshWrite((uint32_t *)(lbmTmp->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,segArg),ZEXT24(unaff_DI) << 0x10,0));
    l8Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(332,320,0,0,0);
    segArg = (uint16_t)(tmpSeg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)tmpSeg);
    src_63.seg = 0;
    src_63.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_63,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l8Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    l8Cut3Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(306,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)segArg);
    src_64.seg = 0;
    src_64.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_64,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    l3Cut1Seg = (uint16_t)(tmpSeg);
    l3Cut2Ofs =(uint16_t)( (far_t far *)ovr_stshWrite((uint32_t *)(lbmTmp->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,segArg),ZEXT24(unaff_DI) << 0x10,0));
    l3Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(306,320,0,0,0);
    segArg = (uint16_t)(tmpSeg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)tmpSeg);
    src_65.seg = 0;
    src_65.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_65,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l3Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    l3Cut3Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(330,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)segArg);
    src_66.seg = 0;
    src_66.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_66,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l6Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    l6Cut1Seg = (uint16_t)(tmpSeg);
    l6Cut2Ofs =(uint16_t)( (far_t far *)ovr_stshWrite((uint32_t *)(lbmTmp->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,segArg),ZEXT24(unaff_DI) << 0x10,0));
    l6Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(330,320,0,0,0);
    segArg = (uint16_t)(tmpSeg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)tmpSeg);
    src_67.seg = 0;
    src_67.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_67,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l6Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    l6Cut3Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(333,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)segArg);
    src_68.seg = 0;
    src_68.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_68,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l9Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    l9Cut1Seg = (uint16_t)(tmpSeg);
    l9Cut2Ofs =(uint16_t)( (far_t far *)ovr_stshWrite((uint32_t *)(lbmTmp->cmap + 0x1e0),
                                       (uint8_t *)CONCAT22(0x90,segArg),ZEXT24(unaff_DI) << 0x10,0));
    l9Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(333,320,0,0,0);
    segArg = (uint16_t)(tmpSeg);
    ovr_stshUniqueColorsRemap(lbmTmp,(char)tmpSeg);
    src_69.seg = 0;
    src_69.ofs = (lbmTmp->aptr).seg;
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_69,0,319,59,(int16_t)unaff_DI,0x3b,0,0);
    l9Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    l9Cut3Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
  }
  else {
    gamfont1Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    gamfont1Cut1Seg = (uint16_t)(segArg);
    davfontCut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    davfontCut1Seg = (uint16_t)(segArg);
    davfont2Cut1Ofs =(uint16_t)( (cte_t *)ovr_stshAllocStub(unaff_DI));
    davfont2Cut1Seg = (uint16_t)(segArg);
    demfont1FontOfs = ovr_stshAllocStub(unaff_DI);
    demfont1FontSeg = (uint16_t)(segArg);
    talkwin9Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    talkwin9Cut1Seg = (uint16_t)(segArg);
    talkwin9Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    talkwin9Cut2Seg = (uint16_t)(segArg);
    talkwin9Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    talkwin9Cut3Seg = (uint16_t)(segArg);
    talkwin9Cut4Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    talkwin9Cut4Seg = (uint16_t)(segArg);
    talkwin9Cut5Ofs = ovr_stshAllocStub(unaff_DI);
    talkwin9Cut5Seg = (uint16_t)(segArg);
    LbxButton2.ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    LbxButton2.seg = (uint16_t)segArg;
    butt01Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    butt01Cut1Seg = (uint16_t)(segArg);
    butt01Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    butt01Cut2Seg = (uint16_t)(segArg);
    butt01Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    butt01Cut3Seg = (uint16_t)(segArg);
    butt01Cut4Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    butt01Cut4Seg = (uint16_t)(segArg);
    butt01Cut5Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    butt01Cut5Seg = (uint16_t)(segArg);
    butt01Cut6Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    butt01Cut6Seg = (uint16_t)(segArg);
    button1Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    button1Cut1Seg = (uint16_t)(segArg);
    button1Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    button1Cut2Seg = (uint16_t)(segArg);
    button1Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    button1Cut3Seg = (uint16_t)(segArg);
    back03Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    back03Cut1Seg = (uint16_t)(segArg);
    back03Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    back03Cut2Seg = (uint16_t)(segArg);
    midgrnd5Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    midgrnd5Cut1Seg = (uint16_t)(segArg);
    midgrnd5Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    midgrnd5Cut2Seg = (uint16_t)(segArg);
    strong4Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    strong4Cut1Seg = (uint16_t)(segArg);
    strong4Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    strong4Cut2Seg = (uint16_t)(segArg);
    marbleCut1Ofs = ovr_stshAllocStub(unaff_DI);
    marbleCut1Seg = (uint16_t)(segArg);
    marbleCut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    marbleCut2Seg = (uint16_t)(segArg);
    far_t_2000_d3e4.ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
    far_t_2000_d3e4.seg = (uint16_t)segArg;
    back2Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    back2Cut1Seg = (uint16_t)(segArg);
    back2Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    back2Cut2Seg = (uint16_t)(segArg);
    midl3Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    midl3Cut1Seg = (uint16_t)(segArg);
    midl3Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    midl3Cut2Seg = (uint16_t)(segArg);
    frnt3Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    frnt3Cut1Seg = (uint16_t)(segArg);
    frnt3Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    frnt3Cut2Seg = (uint16_t)(segArg);
    winrebg1Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    winrebg1Cut1Seg = (uint16_t)(segArg);
    winrebg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    winrebg1Cut2Seg = (uint16_t)(segArg);
    winremg2Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    winremg2Cut1Seg = (uint16_t)(segArg);
    winremg2Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    winremg2Cut2Seg = (uint16_t)(segArg);
    winrefg1Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    winrefg1Cut1Seg = (uint16_t)(segArg);
    winrefg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    winrefg1Cut2Seg = (uint16_t)(segArg);
    captbg2Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    captbg2Cut1Seg = (uint16_t)(segArg);
    captbg2Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    captbg2Cut2Seg = (uint16_t)(segArg);
    captmg3Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    captmg3Cut1Seg = (uint16_t)(segArg);
    captmg3Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    captmg3Cut2Seg = (uint16_t)(segArg);
    captfg1Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    captfg1Cut1Seg = (uint16_t)(segArg);
    captfg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    captfg1Cut2Seg = (uint16_t)(segArg);
    l1Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l1Cut1Seg = (uint16_t)(segArg);
    l1Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l1Cut2Seg = (uint16_t)(segArg);
    l1Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l1Cut3Seg = (uint16_t)(segArg);
    l4Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l4Cut1Seg = (uint16_t)(segArg);
    l4Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l4Cut2Seg = (uint16_t)(segArg);
    l4Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l4Cut3Seg = (uint16_t)(segArg);
    l7Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l7Cut1Seg = (uint16_t)(segArg);
    l7Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l7Cut2Seg = (uint16_t)(segArg);
    l7Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l7Cut3Seg = (uint16_t)(segArg);
    l2Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l2Cut1Seg = (uint16_t)(segArg);
    l2Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l2Cut2Seg = (uint16_t)(segArg);
    l2Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l2Cut3Seg = (uint16_t)(segArg);
    l5Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l5Cut1Seg = (uint16_t)(segArg);
    l5Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l5Cut2Seg = (uint16_t)(segArg);
    l5Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l5Cut3Seg = (uint16_t)(segArg);
    l8Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l8Cut1Seg = (uint16_t)(segArg);
    l8Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l8Cut2Seg = (uint16_t)(segArg);
    l8Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l8Cut3Seg = (uint16_t)(segArg);
    l3Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l3Cut1Seg = (uint16_t)(segArg);
    l3Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l3Cut2Seg = (uint16_t)(segArg);
    l3Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l3Cut3Seg = (uint16_t)(segArg);
    l6Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l6Cut1Seg = (uint16_t)(segArg);
    l6Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l6Cut2Seg = (uint16_t)(segArg);
    l6Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l6Cut3Seg = (uint16_t)(segArg);
    l9Cut1Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l9Cut1Seg = (uint16_t)(segArg);
    l9Cut2Ofs = ovr_stshAllocStub(unaff_DI);
    l9Cut2Seg = (uint16_t)(segArg);
    l9Cut3Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    l9Cut3Seg = (uint16_t)(segArg);
  }
  ovr_stshInitAudioAssets(grab);
  ovr_stshLoadAudioDrivers(grab);
  ovr_stshInitSprites(grab);
  stshInitTxtFiles(grab);
  if (grab) {
    sky06FliOfs = ovr_stshStoreFile_2((far_t far *)(char *)StshNames[0x19f],
                                      (char *)(ulong)(*(uint16_t *)((uint8_t *)&(StshNames[0x19f]) + 2)),(uint16_t)unaff_DI);
    sky06FliSeg = (uint16_t)(segArg);
    l9Cut4Ofs = ovr_stshStoreFile_2((far_t far *)"bolt12.fli",(char *)0x2410,(uint16_t)unaff_DI);
    l9Cut4Seg = (uint16_t)(segArg);
    lbmTmp = ovr_grabLbm(417,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    ssilogoCut1Ofs =(uint16_t)(
         (far_t far *)ovr_stshWrite((uint32_t *)lbmTmp,(uint8_t *)CONCAT22(0x300,segArg),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_70.seg = 0;
    src_70.ofs = (lbmTmp->aptr).seg;
    ssilogoCut1Seg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_70,0,319,199,(int16_t)unaff_DI,199,0,0);
    ssilogoCut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    ssilogoCut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(542,0,0,0,0);
    segArg = (uint16_t)(tmpSeg);
    youlose1Cut1Ofs =(uint16_t)(
         (far_t far *)ovr_stshWrite((uint32_t *)lbmTmp,(uint8_t *)CONCAT22(0x300,tmpSeg),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_71.seg = 0;
    src_71.ofs = (lbmTmp->aptr).seg;
    youlose1Cut1Seg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_71,0,319,144,(int16_t)unaff_DI,0x90,0,0);
    youlose1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    youlose1Cut2Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(539,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    cred01Cut1Ofs =(uint16_t)(
         (far_t far *)ovr_stshWrite((uint32_t *)lbmTmp,(uint8_t *)CONCAT22(0x300,segArg),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_72.seg = 0;
    src_72.ofs = (lbmTmp->aptr).seg;
    cred01Cut1Seg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_72,0,319,199,(int16_t)unaff_DI,199,0,0);
    cred01Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    cred01Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    lbmTmp = ovr_grabLbm(540,0,0,0,0);
    segArg = (uint16_t)(tmpSeg);
    cred02Cut1Ofs =(uint16_t)(
         (far_t far *)ovr_stshWrite((uint32_t *)lbmTmp,(uint8_t *)CONCAT22(0x300,tmpSeg),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_73.seg = 0;
    src_73.ofs = (lbmTmp->aptr).seg;
    cred02Cut1Seg = (uint16_t)(segArg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_73,0,319,199,(int16_t)unaff_DI,199,0,0);
    cred02Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)segArg);
    cred02Cut2Seg = (uint16_t)(segArg);
    ovr_stgFreeTmp(lbmTmp,(char)tmpSeg);
    lbmTmp = ovr_grabLbm(541,0,0,0,0);
    tmpSeg = (uint16_t)(segArg);
    cred03Cut1Ofs =(uint16_t)(
         (far_t far *)ovr_stshWrite((uint32_t *)lbmTmp,(uint8_t *)CONCAT22(0x300,segArg),
                                ZEXT24(unaff_DI) << 0x10,0));
    src_74.seg = 0;
    src_74.ofs = (lbmTmp->aptr).seg;
    cred03Cut1Seg = (uint16_t)(tmpSeg);
    pfVar2 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_74,0,319,199,(int16_t)unaff_DI,199,0,0);
    cred03Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar2,(char)tmpSeg);
    cred03Cut2Seg = (uint16_t)(tmpSeg);
    ovr_stgFreeTmp(lbmTmp,(char)segArg);
    cred03Cut3Ofs = ovr_stshStoreFile_2((far_t far *)"save.999",(char *)0x2410,(uint16_t)unaff_DI);
    cred03Cut3Seg = (uint16_t)(tmpSeg);
  }
  else {
    sky06FliOfs = ovr_stshAllocStub(unaff_DI);
    sky06FliSeg = (uint16_t)(segArg);
    l9Cut4Ofs = ovr_stshAllocStub(unaff_DI);
    l9Cut4Seg = (uint16_t)(segArg);
    ssilogoCut1Ofs = ovr_stshAllocStub(unaff_DI);
    ssilogoCut1Seg = (uint16_t)(segArg);
    ssilogoCut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    ssilogoCut2Seg = (uint16_t)(segArg);
    youlose1Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    youlose1Cut1Seg = (uint16_t)(segArg);
    youlose1Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    youlose1Cut2Seg = (uint16_t)(segArg);
    cred01Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    cred01Cut1Seg = (uint16_t)(segArg);
    cred01Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    cred01Cut2Seg = (uint16_t)(segArg);
    cred02Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    cred02Cut1Seg = (uint16_t)(segArg);
    cred02Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    cred02Cut2Seg = (uint16_t)(segArg);
    cred03Cut1Ofs = ovr_stshAllocStub(unaff_DI);
    cred03Cut1Seg = (uint16_t)(segArg);
    cred03Cut2Ofs = (uint16_t)(ovr_stshAllocStub(unaff_DI));
    cred03Cut2Seg = (uint16_t)(segArg);
    cred03Cut3Ofs = ovr_stshAllocStub(unaff_DI);
    cred03Cut3Seg = (uint16_t)(segArg);
  }
  return;
}


/* 81b9:3e84 */

void __cdecl16far grabBldLbm2(int16_t index,int16_t normal,int16_t ruin,uint16_t arg4)

{
  stg_tmp_t *lbmTmp;
  far_t *pfVar2;
  cte_t *stored;
  uint16_t in_DX;
  uint16_t uVar4;
  uint16_t resSeg;
  uint16_t uVar6;
  int16_t unaff_SI;
  far_t pixels;
  far_t pixels_00;
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
  
  lbmTmp = ovr_grabLbmTR(normal);
  pixels.seg = 0;
  pixels.ofs = (lbmTmp->aptr).seg;
  resSeg = in_DX;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels,130,99,194,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,resSeg);
  uVar4 = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[0x19].seg + index * 0xc) = resSeg;
  ((far_t *)(BldGfxNormal + 0x19) + index * 3)->ofs = (uint16_t)stored;
  pixels_00.seg = 100;
  pixels_00.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_00,130,199,194,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,uVar4);
  resSeg = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[0x16].seg + index * 0xc) = uVar4;
  ((far_t *)(BldGfxNormal + 0x16) + index * 3)->ofs = (uint16_t)stored;
  pixels_01.seg = 200;
  pixels_01.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_01,130,299,194,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,resSeg);
  uVar4 = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[0x13].seg + index * 0xc) = resSeg;
  ((far_t *)(BldGfxNormal + 0x13) + index * 3)->ofs = (uint16_t)stored;
  pixels_02.seg = 0;
  pixels_02.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_02,65,99,129,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,uVar4);
  resSeg = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[0x10].seg + index * 0xc) = uVar4;
  ((far_t *)(BldGfxNormal + 0x10) + index * 3)->ofs = (uint16_t)stored;
  pixels_03.seg = 100;
  pixels_03.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_03,65,199,129,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,resSeg);
  uVar4 = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[0xd].seg + index * 0xc) = resSeg;
  ((far_t *)(BldGfxNormal + 0xd) + index * 3)->ofs = (uint16_t)stored;
  pixels_04.seg = 200;
  pixels_04.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_04,65,299,129,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,uVar4);
  resSeg = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[10].seg + index * 0xc) = uVar4;
  ((far_t *)(BldGfxNormal + 10) + index * 3)->ofs = (uint16_t)stored;
  pixels_05.seg = 0;
  pixels_05.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_05,0,99,64,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,resSeg);
  uVar4 = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[7].seg + index * 0xc) = resSeg;
  ((far_t *)(BldGfxNormal + 7) + index * 3)->ofs = (uint16_t)stored;
  pixels_06.seg = 100;
  pixels_06.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_06,0,199,64,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,uVar4);
  resSeg = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[4].seg + index * 0xc) = uVar4;
  ((far_t *)(BldGfxNormal + 4) + index * 3)->ofs = (uint16_t)stored;
  pixels_07.seg = 200;
  pixels_07.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_07,0,299,64,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,resSeg);
  uVar4 = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[1].seg + index * 0xc) = resSeg;
  ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs = (uint16_t)stored;
  ovr_stgFreeTmp(lbmTmp,in_DX);
  lbmTmp = ovr_grabLbmTR(ruin);
  pixels_08.seg = 0;
  pixels_08.ofs = (lbmTmp->aptr).seg;
  resSeg = uVar4;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_08,130,99,194,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,resSeg);
  *(uint16_t *)((int)&BldGfxRuin[0x19].seg + index * 0xc) = resSeg;
  ((far_t *)(BldGfxRuin + 0x19) + index * 3)->ofs = (uint16_t)stored;
  pixels_09.seg = 100;
  pixels_09.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_09,130,199,194,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,uVar6);
  resSeg = 0x195d;
  *(uint16_t *)((int)&BldGfxRuin[0x16].seg + index * 0xc) = uVar6;
  ((far_t *)(BldGfxRuin + 0x16) + index * 3)->ofs = (uint16_t)stored;
  pixels_10.seg = 200;
  pixels_10.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_10,130,299,194,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,resSeg);
  *(uint16_t *)((int)&BldGfxRuin[0x13].seg + index * 0xc) = resSeg;
  ((far_t *)(BldGfxRuin + 0x13) + index * 3)->ofs = (uint16_t)stored;
  pixels_11.seg = 0;
  pixels_11.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_11,65,99,129,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,uVar6);
  resSeg = 0x195d;
  *(uint16_t *)((int)&BldGfxRuin[0x10].seg + index * 0xc) = uVar6;
  ((far_t *)(BldGfxRuin + 0x10) + index * 3)->ofs = (uint16_t)stored;
  pixels_12.seg = 100;
  pixels_12.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_12,65,199,129,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,resSeg);
  *(uint16_t *)((int)&BldGfxRuin[0xd].seg + index * 0xc) = resSeg;
  ((far_t *)(BldGfxRuin + 0xd) + index * 3)->ofs = (uint16_t)stored;
  pixels_13.seg = 200;
  pixels_13.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_13,65,299,129,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,uVar6);
  resSeg = 0x195d;
  *(uint16_t *)((int)&BldGfxRuin[10].seg + index * 0xc) = uVar6;
  ((far_t *)(BldGfxRuin + 10) + index * 3)->ofs = (uint16_t)stored;
  pixels_14.seg = 0;
  pixels_14.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_14,0,99,64,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,resSeg);
  *(uint16_t *)((int)&BldGfxRuin[7].seg + index * 0xc) = resSeg;
  ((far_t *)(BldGfxRuin + 7) + index * 3)->ofs = (uint16_t)stored;
  pixels_15.seg = 100;
  pixels_15.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_15,0,199,64,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,uVar6);
  resSeg = 0x195d;
  *(uint16_t *)((int)&BldGfxRuin[4].seg + index * 0xc) = uVar6;
  ((far_t *)(BldGfxRuin + 4) + index * 3)->ofs = (uint16_t)stored;
  pixels_16.seg = 200;
  pixels_16.ofs = (lbmTmp->aptr).seg;
  pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_16,0,299,64,26,-1,unaff_SI,0,0);
  stored = ovr_stshStoreFile((uint8_t *)pfVar2,resSeg);
  *(uint16_t *)((int)&BldGfxRuin[1].seg + index * 0xc) = resSeg;
  ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs = (uint16_t)stored;
  ovr_stgFreeTmp(lbmTmp,uVar4);
  return;
}



/* 81b9:43f1 */

void __cdecl16far stshAllocBldStubs2(int16_t index)

{
  far_t *pfVar1;
  uint16_t in_DX;
  uint16_t uVar2;
  uint16_t uVar3;
  far_t *unaff_SI;
  
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar2 = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[0x19].seg + index * 0xc) = in_DX;
  ((far_t *)(BldGfxNormal + 0x19) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar3 = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[0x16].seg + index * 0xc) = uVar2;
  ((far_t *)(BldGfxNormal + 0x16) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar2 = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[0x13].seg + index * 0xc) = uVar3;
  ((far_t *)(BldGfxNormal + 0x13) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar3 = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[0x10].seg + index * 0xc) = uVar2;
  ((far_t *)(BldGfxNormal + 0x10) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar2 = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[0xd].seg + index * 0xc) = uVar3;
  ((far_t *)(BldGfxNormal + 0xd) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar3 = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[10].seg + index * 0xc) = uVar2;
  ((far_t *)(BldGfxNormal + 10) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar2 = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[7].seg + index * 0xc) = uVar3;
  ((far_t *)(BldGfxNormal + 7) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar3 = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[4].seg + index * 0xc) = uVar2;
  ((far_t *)(BldGfxNormal + 4) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar2 = 0x195d;
  *(uint16_t *)((int)&BldGfxNormal[1].seg + index * 0xc) = uVar3;
  ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar3 = 0x195d;
  *(uint16_t *)((int)&BldGfxRuin[0x19].seg + index * 0xc) = uVar2;
  ((far_t *)(BldGfxRuin + 0x19) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar2 = 0x195d;
  *(uint16_t *)((int)&BldGfxRuin[0x16].seg + index * 0xc) = uVar3;
  ((far_t *)(BldGfxRuin + 0x16) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar3 = 0x195d;
  *(uint16_t *)((int)&BldGfxRuin[0x13].seg + index * 0xc) = uVar2;
  ((far_t *)(BldGfxRuin + 0x13) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar2 = 0x195d;
  *(uint16_t *)((int)&BldGfxRuin[0x10].seg + index * 0xc) = uVar3;
  ((far_t *)(BldGfxRuin + 0x10) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar3 = 0x195d;
  *(uint16_t *)((int)&BldGfxRuin[0xd].seg + index * 0xc) = uVar2;
  ((far_t *)(BldGfxRuin + 0xd) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar2 = 0x195d;
  *(uint16_t *)((int)&BldGfxRuin[10].seg + index * 0xc) = uVar3;
  ((far_t *)(BldGfxRuin + 10) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar3 = 0x195d;
  *(uint16_t *)((int)&BldGfxRuin[7].seg + index * 0xc) = uVar2;
  ((far_t *)(BldGfxRuin + 7) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  uVar2 = 0x195d;
  *(uint16_t *)((int)&BldGfxRuin[4].seg + index * 0xc) = uVar3;
  ((far_t *)(BldGfxRuin + 4) + index * 3)->ofs = (uint16_t)pfVar1;
  pfVar1 = ovr_stshAllocStub(unaff_SI);
  *(uint16_t *)((int)&BldGfxRuin[1].seg + index * 0xc) = uVar2;
  ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs = (uint16_t)pfVar1;
  return;
}


