/*
 * ovc48_assets2.c - recovered from STRONG.EXE
 * memory block: OVC48_assets2.c
 * range: 81b9:0000 - 81b9:4dff
 * functions: 4
 */
#include "recovered.h"


/* 81b9:0000 */

void __cdecl16far stshInitTxtFiles(char grab,...)

{
  far_t *pfVar1;
  undefined1 *in_DX;
  uint16_t unaff_SS;
  char in_stack_00000004;
  far_t dst;
  uint16_t in_stack_0000ff74;
  uint8_t i;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&stack0xff74;
  F_SCOPY(far_from_u32((uint32_t)(0x2410822c)),dst);
  for (i = 0x0; i < 0x22; i = i + 0x1) {
    if (in_stack_00000004 == '\0') {
      pfVar1 = ovr_stshAllocStub();
      *(int *)((uint)i * 4 + -0x6c6e) = (int)in_DX;
      *(undefined2 *)((uint)i * 4 + -0x6c70) = pfVar1;
    }
    else {
      in_DX = &stack0xff74;
      pfVar1 = ovr_stshStoreFile_2(*(far_t **)(&stack0xff76 + (uint)i * 4),(char *)0x0,
                                   in_stack_0000ff74);
      *(int *)((uint)i * 4 + -0x6c6e) = (int)in_DX;
      *(undefined2 *)((uint)i * 4 + -0x6c70) = pfVar1;
    }
  }
  return;
}



/* 81b9:0086 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far init_assets2(bool grab,...)

{
  stg_tmp_t *psVar1;
  far_t *pfVar2;
  cte_t *pcVar3;
  uint16_t in_DX;
  undefined2 uVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  uint16_t uVar7;
  int iVar8;
  int16_t unaff_DI;
  char in_stack_00000004;
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
  char grab_00;
  undefined1 uVar9;
  stg_tmp_t *psStack_a;
  uint16_t uStack_8;
  
  grab_00 = (char)unaff_DI;
  uVar9 = (undefined1)((uint)unaff_DI >> 8);
  if (in_stack_00000004 == '\0') {
    stshAllocBldStubs2(unaff_DI,0xda);
  }
  else {
    grabBldLbm2();
  }
  ovr_stshStubifyCopy1to0(CONCAT11(uVar9,grab_00),0xda);
  ovr_stshStubifyCopy1to0(CONCAT11(uVar9,grab_00),0xdd);
  ovr_stshStubifyCopy1to0(CONCAT11(uVar9,grab_00),0xe0);
  if (in_stack_00000004 == '\0') {
    stshAllocBldStubs2(CONCAT11(uVar9,grab_00),0xe3);
  }
  else {
    grabBldLbm2();
  }
  ovr_stshStubifyCopy1to0(CONCAT11(uVar9,grab_00),0xe3);
  ovr_stshStubifyCopy1to0(CONCAT11(uVar9,grab_00),0xe6);
  ovr_stshStubifyCopy1to0(CONCAT11(uVar9,grab_00),0xe9);
  if (in_stack_00000004 != '\0') {
    psVar1 = ovr_grabLbmTR(CONCAT11(uVar9,grab_00),0x20f);
    psStack_a = (stg_tmp_t *)CONCAT22(in_DX,psVar1);
  }
  for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
    if (in_stack_00000004 == '\0') {
      pfVar2 = ovr_stshAllocStub();
      *(uint16_t *)((int)&BldGfxNormal[1].seg + (iVar8 + 0xec) * 0xc) = in_DX;
      ((far_t *)(BldGfxNormal + 1) + (iVar8 + 0xec) * 3)->ofs = (uint16_t)pfVar2;
    }
    else {
      uVar4 = (undefined2)((ulong)((long)iVar8 * 100) >> 0x10);
      pixels.seg = 0x21;
      pixels.ofs = (int)((long)iVar8 * 100) + 0x14;
      pfVar2 = ovr_stshRleType2((far_t *)(psStack_a->aptr).seg,pixels,iVar8 * 100 + 99,116,10,28,
                                (&psStack_a->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar4)),pfVar2);
      *(undefined2 *)((int)&BldGfxNormal[1].seg + (iVar8 + 0xec) * 0xc) = uVar4;
      ((far_t *)(BldGfxNormal + 1) + (iVar8 + 0xec) * 3)->ofs = (uint16_t)pcVar3;
    }
    uVar5 = ((far_t *)(BldGfxNormal + 1) + (iVar8 + 0xec) * 3)->ofs;
    *(undefined2 *)((int)&BldGfxNormal[0].seg + (iVar8 + 0xec) * 0xc) =
         *(undefined2 *)((int)&BldGfxNormal[1].seg + (iVar8 + 0xec) * 0xc);
    ((far_t *)BldGfxNormal + (iVar8 + 0xec) * 3)->ofs = uVar5;
    in_DX = *(uint16_t *)((int)&BldGfxNormal[1].seg + (iVar8 + 0xec) * 0xc);
    uVar5 = ((far_t *)(BldGfxNormal + 1) + (iVar8 + 0xec) * 3)->ofs;
    *(uint16_t *)((int)&BldGfxNormal[2].seg + (iVar8 + 0xec) * 0xc) = in_DX;
    ((far_t *)(BldGfxNormal + 2) + (iVar8 + 0xec) * 3)->ofs = uVar5;
  }
  if (in_stack_00000004 != '\0') {
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uStack_8)),psStack_a);
  }
  if (in_stack_00000004 != '\0') {
    psVar1 = ovr_grabLbmTR(CONCAT11(uVar9,grab_00),0x210);
    psStack_a = (stg_tmp_t *)CONCAT22(in_DX,psVar1);
  }
  for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
    if (in_stack_00000004 == '\0') {
      pfVar2 = ovr_stshAllocStub();
      *(uint16_t *)((int)&BldGfxRuin[1].seg + (iVar8 + 0xec) * 0xc) = in_DX;
      ((far_t *)(BldGfxRuin + 1) + (iVar8 + 0xec) * 3)->ofs = (uint16_t)pfVar2;
    }
    else {
      uVar4 = (undefined2)((ulong)((long)iVar8 * 100) >> 0x10);
      pixels_00.seg = 0x21;
      pixels_00.ofs = (int)((long)iVar8 * 100) + 0x14;
      pfVar2 = ovr_stshRleType2((far_t *)(psStack_a->aptr).seg,pixels_00,iVar8 * 100 + 99,116,10,28,
                                (&psStack_a->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar4)),pfVar2);
      *(undefined2 *)((int)&BldGfxRuin[1].seg + (iVar8 + 0xec) * 0xc) = uVar4;
      ((far_t *)(BldGfxRuin + 1) + (iVar8 + 0xec) * 3)->ofs = (uint16_t)pcVar3;
    }
    in_DX = 0x195d;
  }
  if (in_stack_00000004 != '\0') {
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uStack_8)),psStack_a);
  }
  ovr_stshStubifyCopy1to0(CONCAT11(uVar9,grab_00),0xec);
  if (in_stack_00000004 == '\0') {
    BldGfxNormal[0x2e6].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxNormal[0x2e6].seg = in_DX;
    BldGfxNormal[0x2e3].ofs = (uint16_t)ovr_stshAllocStub();
    uVar6 = 0x195d;
    BldGfxNormal[0x2e3].seg = uVar5;
    BldGfxNormal[0x2e0].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxNormal[0x2e0].seg = uVar6;
    BldGfxNormal[0x2dd].ofs = (uint16_t)ovr_stshAllocStub();
    uVar6 = 0x195d;
    BldGfxNormal[0x2dd].seg = uVar5;
    BldGfxNormal[0x2da].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxNormal[0x2da].seg = uVar6;
    BldGfxNormal[0x2d7].ofs = (uint16_t)ovr_stshAllocStub();
    uVar6 = 0x195d;
    BldGfxNormal[0x2d7].seg = uVar5;
    BldGfxNormal[0x2d4].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxNormal[0x2d4].seg = uVar6;
    BldGfxNormal[0x2d1].ofs = (uint16_t)ovr_stshAllocStub();
    uVar7 = 0x195d;
    BldGfxNormal[0x2d1].seg = uVar5;
    BldGfxNormal[0x2ce].ofs = (uint16_t)ovr_stshAllocStub();
    uVar6 = 0x195d;
    BldGfxNormal[0x2ce].seg = uVar7;
  }
  else {
    psVar1 = ovr_grabLbmTR(CONCAT11(uVar9,grab_00),0x211);
    psStack_a = (stg_tmp_t *)CONCAT22(in_DX,psVar1);
    uVar5 = in_DX;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x820000)),99,194,26,-1,
                              (&psVar1->aptr)->ofs);
    BldGfxNormal[0x2e6].ofs =
         (uint16_t)ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    uVar6 = 0x195d;
    BldGfxNormal[0x2e6].seg = uVar5;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x820064)),199,194,26,-1,
                              (&psVar1->aptr)->ofs);
    BldGfxNormal[0x2e3].ofs =
         (uint16_t)ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    uVar5 = 0x195d;
    BldGfxNormal[0x2e3].seg = uVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x8200c8)),299,194,26,-1,
                              (&psVar1->aptr)->ofs);
    BldGfxNormal[0x2e0].ofs =
         (uint16_t)ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    uVar6 = 0x195d;
    BldGfxNormal[0x2e0].seg = uVar5;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x410000)),99,129,26,-1,
                              (&psVar1->aptr)->ofs);
    BldGfxNormal[0x2dd].ofs =
         (uint16_t)ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    uVar5 = 0x195d;
    BldGfxNormal[0x2dd].seg = uVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x410064)),199,129,26,-1,
                              (&psVar1->aptr)->ofs);
    BldGfxNormal[0x2da].ofs =
         (uint16_t)ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    uVar6 = 0x195d;
    BldGfxNormal[0x2da].seg = uVar5;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x4100c8)),299,129,26,-1,
                              (&psVar1->aptr)->ofs);
    BldGfxNormal[0x2d7].ofs =
         (uint16_t)ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    uVar5 = 0x195d;
    BldGfxNormal[0x2d7].seg = uVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x0)),99,64,26,-1,
                              (&psVar1->aptr)->ofs);
    BldGfxNormal[0x2d4].ofs =
         (uint16_t)ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    uVar6 = 0x195d;
    BldGfxNormal[0x2d4].seg = uVar5;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x64)),199,64,26,-1,
                              (&psVar1->aptr)->ofs);
    BldGfxNormal[0x2d1].ofs =
         (uint16_t)ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    uVar5 = 0x195d;
    BldGfxNormal[0x2d1].seg = uVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0xc8)),299,64,26,-1,
                              (&psVar1->aptr)->ofs);
    BldGfxNormal[0x2ce].ofs =
         (uint16_t)ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    uVar6 = 0x195d;
    BldGfxNormal[0x2ce].seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,in_DX)),psVar1);
  }
  ovr_stshStubifyCopy1to0(CONCAT11(uVar9,grab_00),0xef);
  ovr_stshStubifyCopy1to0(CONCAT11(uVar9,grab_00),0xf2);
  ovr_stshStubifyCopy1to0(CONCAT11(uVar9,grab_00),0xf5);
  for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
    *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar8 * 4) = 0;
    ((far_t *)BldGfxNormal + iVar8)->ofs = 0;
  }
  if (in_stack_00000004 == '\0') {
    nwpanel2Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    nwpanel2Cut1Seg = uVar6;
    GMenuGfxOfs = (uint16_t)(ovr_stshAllocStub());
    uVar5 = uVar6;
    GMenuGfxSeg = uVar6;
  }
  else {
    psVar1 = ovr_grabLbmTR(CONCAT11(uVar9,grab_00),10);
    psStack_a = (stg_tmp_t *)CONCAT22(uVar6,psVar1);
    uVar5 = uVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x7000c)),222,150,-12,-7,
                              (&psVar1->aptr)->ofs);
    nwpanel2Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    nwpanel2Cut1Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    GMenuGfxOfs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    GMenuGfxSeg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
  }
  if (in_stack_00000004 == '\0') {
    specialColorsOfs = ovr_stshAllocStub();
    specialColorsSeg = uVar5;
    trianglsCut1Ofs = (uint16_t)(ovr_stshAllocStub());
    trianglsCut1Seg = uVar5;
    trianglsCut2Ofs = (uint16_t)(ovr_stshAllocStub());
    trianglsCut2Seg = uVar5;
    trianglsCut3Ofs = (uint16_t)(ovr_stshAllocStub());
    trianglsCut3Seg = uVar5;
    trianglsCut4Ofs = (uint16_t)(ovr_stshAllocStub());
    trianglsCut4Seg = uVar5;
    trianglsCut5Ofs = (uint16_t)(ovr_stshAllocStub());
    trianglsCut5Seg = uVar5;
    trianglsCut6Ofs = (uint16_t)(ovr_stshAllocStub());
    uVar6 = uVar5;
    trianglsCut6Seg = uVar5;
  }
  else {
    psVar1 = ovr_grabLbmTR(CONCAT11(uVar9,grab_00),0xe);
    psStack_a = (stg_tmp_t *)CONCAT22(uVar5,psVar1);
    SpecialColors[0] = *(uint8_t *)((int)&GStrangeTable[0x12].ofs + 1 + (psVar1->aptr).ofs);
    SpecialColors[1] = ((char *)"%s turns %d undead." + 0x12)[(psVar1->aptr).ofs];
    SpecialColors[2] = ((char *)"If you lead with wisdom and cunning..." + 9)[(psVar1->aptr).ofs];
    SpecialColors[3] =
         ((char *)"ENTER: use previous configuration, SPACE: reconfigure, ESC: quit" + 0x12)
         [(psVar1->aptr).ofs];
    SpecialColors[4] = ((char *)"%s turns %d undead." + 0x10)[(psVar1->aptr).ofs];
    SpecialColors[5] = *(uint8_t *)((int)&GStrangeTable[0x12].seg + 1 + (psVar1->aptr).ofs);
    SpecialColors[6] = *(uint8_t *)((int)(undefined2 *)&youlose1Cut1Seg + (psVar1->aptr).ofs);
    SpecialColors[7] = *(uint8_t *)((psVar1->aptr).ofs + 0x936e);
    uVar6 = 0x2410;
    specialColorsOfs = (uint16_t)(ovr_stshWrite());
    specialColorsSeg = uVar6;
    pfVar2 = ovr_stshRleCut();
    trianglsCut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    trianglsCut1Seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    trianglsCut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    trianglsCut2Seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    trianglsCut3Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    trianglsCut3Seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    trianglsCut4Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    trianglsCut4Seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    trianglsCut5Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    trianglsCut5Seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    trianglsCut6Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    trianglsCut6Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
  }
  if (in_stack_00000004 == '\0') {
    panel01Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    panel01Cut1Seg = uVar6;
    panel01Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    panel01Cut2Seg = uVar6;
    panel01Cut3Ofs = (uint16_t)(ovr_stshAllocStub());
    uVar5 = uVar6;
    panel01Cut3Seg = uVar6;
  }
  else {
    psVar1 = ovr_grabLbmTR(CONCAT11(uVar9,grab_00),0x7f);
    psStack_a = (stg_tmp_t *)CONCAT22(uVar6,psVar1);
    uVar5 = uVar6;
    pfVar2 = ovr_stshRleCut();
    panel01Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    panel01Cut1Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    panel01Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    panel01Cut2Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    panel01Cut3Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    panel01Cut3Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
  }
  if (in_stack_00000004 == '\0') {
    Lbm_nwpanel1.ofs = (uint16_t)ovr_stshAllocStub();
    Lbm_nwpanel1.seg = uVar5;
    nwpanel1Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    nwpanel1Cut1Seg = uVar5;
    fullScreenGfxOfs = (uint16_t)(ovr_stshAllocStub());
    fullScreenGfxSeg = uVar5;
    FontHandle.ofs = (uint16_t)ovr_stshAllocStub();
    FontHandle.seg = uVar5;
    nwpanel1Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    nwpanel1Cut2Seg = uVar5;
    nwpanel1Cut3Ofs = (uint16_t)(ovr_stshAllocStub());
    nwpanel1Cut3Seg = uVar5;
    nwpanel1Cut4Ofs = (uint16_t)(ovr_stshAllocStub());
    nwpanel1Cut4Seg = uVar5;
    nwpanel1Cut5Ofs = (uint16_t)(ovr_stshAllocStub());
    uVar6 = uVar5;
    nwpanel1Cut5Seg = uVar5;
  }
  else {
    psVar1 = ovr_grabLbm();
    psStack_a = (stg_tmp_t *)CONCAT22(uVar5,psVar1);
    uVar6 = uVar5;
    Lbm_nwpanel1.ofs = (uint16_t)ovr_stshWrite();
    Lbm_nwpanel1.seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    nwpanel1Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    nwpanel1Cut1Seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    fullScreenGfxOfs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    fullScreenGfxSeg = uVar6;
    pfVar2 = ovr_stshRleCut();
    FontHandle.ofs =
         (uint16_t)ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    FontHandle.seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    nwpanel1Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    nwpanel1Cut2Seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    nwpanel1Cut3Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    nwpanel1Cut3Seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    nwpanel1Cut4Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    nwpanel1Cut4Seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    nwpanel1Cut5Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    nwpanel1Cut5Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
  }
  if (in_stack_00000004 == '\0') {
    for (iVar8 = 0; uVar5 = uVar6, iVar8 < 4; iVar8 = iVar8 + 1) {
      pfVar2 = ovr_stshAllocStub();
      *(uint16_t *)((int)&CrossBlitGfx.seg + iVar8 * 4) = uVar6;
      ((far_t *)&CrossBlitGfx + iVar8)->ofs = (uint16_t)pfVar2;
      pfVar2 = ovr_stshAllocStub();
      ((undefined2 *)&crossBlitType2Seg)[iVar8 * 2] = uVar6;
      ((undefined2 *)&crossBlitType2Ofs)[iVar8 * 2] = pfVar2;
    }
  }
  else {
    psVar1 = ovr_grabLbm();
    psStack_a = (stg_tmp_t *)CONCAT22(uVar6,psVar1);
    uVar5 = uVar6;
    for (iVar8 = 0; iVar8 < 4; iVar8 = iVar8 + 1) {
      uVar4 = (undefined2)((ulong)((long)iVar8 * 0xe) >> 0x10);
      pfVar2 = ovr_stshRleCut();
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar4)),pfVar2);
      *(undefined2 *)((int)&CrossBlitGfx.seg + iVar8 * 4) = uVar4;
      ((far_t *)&CrossBlitGfx + iVar8)->ofs = (uint16_t)pcVar3;
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0xe) >> 0x10);
      pixels_01.seg = 0x10;
      pixels_01.ofs = (uint16_t)((long)iVar8 * 0xe);
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_01,iVar8 * 0xe + 0xd,24,6,4,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&crossBlitType2Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&crossBlitType2Ofs)[iVar8 * 2] = pcVar3;
    }
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
  }
  if (in_stack_00000004 == '\0') {
    for (iVar8 = 0; iVar8 < 0x17; iVar8 = iVar8 + 1) {
      pfVar2 = ovr_stshAllocStub();
      ((undefined2 *)&csite1Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&csite1Ofs)[iVar8 * 2] = pfVar2;
    }
    for (iVar8 = 0; iVar8 < 0x18; iVar8 = iVar8 + 1) {
      pfVar2 = ovr_stshAllocStub();
      ((undefined2 *)&csite2Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&csite2Ofs)[iVar8 * 2] = pfVar2;
    }
    for (iVar8 = 0; iVar8 < 0x20; iVar8 = iVar8 + 1) {
      pfVar2 = ovr_stshAllocStub();
      ((undefined2 *)&csite5Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&csite5Ofs)[iVar8 * 2] = pfVar2;
    }
    for (iVar8 = 0; iVar8 < 0xe; iVar8 = iVar8 + 1) {
      pfVar2 = ovr_stshAllocStub();
      ((undefined2 *)&tmstrsSprites6Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites6Ofs)[iVar8 * 2] = pfVar2;
    }
    for (iVar8 = 0; iVar8 < 0x11; iVar8 = iVar8 + 1) {
      pfVar2 = ovr_stshAllocStub();
      ((undefined2 *)&tmstrsSprites5Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites5Ofs)[iVar8 * 2] = pfVar2;
    }
    for (iVar8 = 0; iVar8 < 7; iVar8 = iVar8 + 1) {
      pfVar2 = ovr_stshAllocStub();
      ((undefined2 *)&tmstrsSprites4Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites4Ofs)[iVar8 * 2] = pfVar2;
    }
    for (iVar8 = 0; iVar8 < 7; iVar8 = iVar8 + 1) {
      pfVar2 = ovr_stshAllocStub();
      ((undefined2 *)&tmstrsSprites3Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites3Ofs)[iVar8 * 2] = pfVar2;
    }
    for (iVar8 = 0; iVar8 < 8; iVar8 = iVar8 + 1) {
      pfVar2 = ovr_stshAllocStub();
      ((undefined2 *)&tmstrsSprites2Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites2Ofs)[iVar8 * 2] = pfVar2;
    }
    for (iVar8 = 0; iVar8 < 5; iVar8 = iVar8 + 1) {
      pfVar2 = ovr_stshAllocStub();
      ((undefined2 *)&tmstrsSprites1Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites1Ofs)[iVar8 * 2] = pfVar2;
    }
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    for (iVar8 = 0; iVar8 < 6; iVar8 = iVar8 + 1) {
      pixels_02.seg = iVar8 * 0x20 + 10;
      pixels_02.ofs = 8;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_02,63,iVar8 * 0x20 + 0x24,0,0,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
      ((undefined2 *)&csite1Seg)[iVar8 * 2] = uVar6;
      ((undefined2 *)&csite1Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 6; iVar8 = iVar8 + 1) {
      pixels_03.seg = iVar8 * 0x20 + 10;
      pixels_03.ofs = 0x55;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_03,140,iVar8 * 0x20 + 0x24,0,0,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
      ((undefined2 *)&csite1_6Seg)[iVar8 * 2] = uVar6;
      ((undefined2 *)&csite1_6Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 6; iVar8 = iVar8 + 1) {
      pixels_04.seg = iVar8 * 0x20 + 10;
      pixels_04.ofs = 0x9f;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_04,214,iVar8 * 0x20 + 0x24,0,0,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
      ((undefined2 *)&csite1_12Seg)[iVar8 * 2] = uVar6;
      ((undefined2 *)&csite1_12Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 5; iVar8 = iVar8 + 1) {
      pixels_05.seg = iVar8 * 0x20 + 10;
      pixels_05.ofs = 0xe5;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_05,284,iVar8 * 0x20 + 0x24,0,0,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
      ((undefined2 *)&csite1_18Seg)[iVar8 * 2] = uVar6;
      ((undefined2 *)&csite1_18Ofs)[iVar8 * 2] = pcVar3;
    }
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,
                                far_from_u32((uint32_t)((ulong)((int)((long)iVar8 * 0x3d) + 0x11) << 0x10)),104,
                                iVar8 * 0x3d + 0x49,0,-60,(&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&csite2Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&csite2Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_06.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_06.ofs = 0x6d;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_06,213,iVar8 * 0x3d + 0x49,0,-60,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&csite2_3Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&csite2_3Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_07.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_07.ofs = 0xd7;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_07,319,iVar8 * 0x3d + 0x49,0,-60,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&csite2_6Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&csite2_6Ofs)[iVar8 * 2] = pcVar3;
    }
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar6 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,
                                far_from_u32((uint32_t)((ulong)((int)((long)iVar8 * 0x3d) + 0x11) << 0x10)),104,
                                iVar8 * 0x3d + 0x49,0,-60,(&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
      ((undefined2 *)&csite3Seg)[iVar8 * 2] = uVar6;
      ((undefined2 *)&csite3Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar6 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_08.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_08.ofs = 0x6d;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_08,213,iVar8 * 0x3d + 0x49,0,-60,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
      ((undefined2 *)&csite3_3Seg)[iVar8 * 2] = uVar6;
      ((undefined2 *)&csite3_3Ofs)[iVar8 * 2] = pcVar3;
    }
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,
                                far_from_u32((uint32_t)((ulong)((int)((long)iVar8 * 0x3d) + 0x11) << 0x10)),104,
                                iVar8 * 0x3d + 0x49,0,-60,(&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&csite4Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&csite4Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_09.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_09.ofs = 0x6d;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_09,213,iVar8 * 0x3d + 0x49,0,-60,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&csite4_3Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&csite4_3Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_10.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_10.ofs = 0xd7;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_10,319,iVar8 * 0x3d + 0x49,0,-60,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&csite4_6Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&csite4_6Ofs)[iVar8 * 2] = pcVar3;
    }
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar6 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_11.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_11.ofs = 1;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_11,103,iVar8 * 0x3d + 0x49,-4,-60
                                ,(&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
      ((undefined2 *)&csite5Seg)[iVar8 * 2] = uVar6;
      ((undefined2 *)&csite5Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar6 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_12.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_12.ofs = 0x68;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_12,206,iVar8 * 0x3d + 0x49,-4,-60
                                ,(&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
      ((undefined2 *)&csite5_3Seg)[iVar8 * 2] = uVar6;
      ((undefined2 *)&csite5_3Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar6 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_13.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_13.ofs = 0xd1;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_13,311,iVar8 * 0x3d + 0x49,-4,-60
                                ,(&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
      ((undefined2 *)&csite5_6Seg)[iVar8 * 2] = uVar6;
      ((undefined2 *)&csite5_6Ofs)[iVar8 * 2] = pcVar3;
    }
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_14.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_14.ofs = 1;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_14,103,iVar8 * 0x3d + 0x49,-4,-60
                                ,(&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&csite6Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&csite6Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_15.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_15.ofs = 0x68;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_15,206,iVar8 * 0x3d + 0x49,-4,-60
                                ,(&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&csite6_3Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&csite6_3Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_16.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_16.ofs = 0xd1;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_16,311,iVar8 * 0x3d + 0x49,-4,-60
                                ,(&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&csite6_6Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&csite6_6Ofs)[iVar8 * 2] = pcVar3;
    }
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar6 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_17.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_17.ofs = 1;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_17,103,iVar8 * 0x3d + 0x49,-4,-60
                                ,(&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
      ((undefined2 *)&csite7Seg)[iVar8 * 2] = uVar6;
      ((undefined2 *)&csite7Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar6 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_18.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_18.ofs = 0x68;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_18,206,iVar8 * 0x3d + 0x49,-4,-60
                                ,(&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
      ((undefined2 *)&csite7_3Seg)[iVar8 * 2] = uVar6;
      ((undefined2 *)&csite7_3Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar6 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_19.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_19.ofs = 0xd1;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_19,311,iVar8 * 0x3d + 0x49,-4,-60
                                ,(&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
      ((undefined2 *)&csite7_6Seg)[iVar8 * 2] = uVar6;
      ((undefined2 *)&csite7_6Ofs)[iVar8 * 2] = pcVar3;
    }
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar7 = uVar6;
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar7 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_20.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_20.ofs = 1;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_20,103,iVar8 * 0x3d + 0x49,-4,-60
                                ,(&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),pfVar2);
      ((undefined2 *)&csite8Seg)[iVar8 * 2] = uVar7;
      ((undefined2 *)&csite8Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 2; iVar8 = iVar8 + 1) {
      uVar7 = (uint16_t)((ulong)((long)iVar8 * 0x3d) >> 0x10);
      pixels_21.seg = (int)((long)iVar8 * 0x3d) + 0x11;
      pixels_21.ofs = 0x68;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_21,206,iVar8 * 0x3d + 0x49,-4,-60
                                ,(&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),pfVar2);
      ((undefined2 *)&csite8_3Seg)[iVar8 * 2] = uVar7;
      ((undefined2 *)&csite8_3Ofs)[iVar8 * 2] = pcVar3;
    }
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    psStack_a = (stg_tmp_t *)CONCAT22(uVar7,psVar1);
    uVar5 = uVar7;
    for (iVar8 = 0; iVar8 < 7; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x1b) >> 0x10);
      pixels_22.seg = (int)((long)iVar8 * 0x1b) + 8;
      pixels_22.ofs = 6;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_22,33,iVar8 * 0x1b + 0x13,0,0,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&tmstrsSprites6Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites6Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 7; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x1b) >> 0x10);
      pixels_23.seg = (int)((long)iVar8 * 0x1b) + 8;
      pixels_23.ofs = 0x23;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_23,62,iVar8 * 0x1b + 0x13,0,0,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&tmstrsSprites9Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites9Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 7; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x1b) >> 0x10);
      pixels_24.seg = (int)((long)iVar8 * 0x1b) + 8;
      pixels_24.ofs = 0x4c;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_24,88,iVar8 * 0x1b + 0x13,0,0,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&tmstrsSprites5Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites5Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 7; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x1b) >> 0x10);
      pixels_25.seg = (int)((long)iVar8 * 0x1b) + 8;
      pixels_25.ofs = 0x66;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_25,114,iVar8 * 0x1b + 0x13,0,0,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&tmstrsSprites6Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites6Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x1b) >> 0x10);
      pixels_26.seg = (int)((long)iVar8 * 0x1b) + 8;
      pixels_26.ofs = 0x80;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_26,140,iVar8 * 0x1b + 0x13,0,0,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&tmstrsSprites7Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites7Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 7; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x1b) >> 0x10);
      pixels_27.seg = (int)((long)iVar8 * 0x1b) + 8;
      pixels_27.ofs = 0x9a;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_27,163,iVar8 * 0x1b + 0x13,0,0,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&tmstrsSprites4Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites4Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 7; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x1b) >> 0x10);
      pixels_28.seg = (int)((long)iVar8 * 0x1b) + 8;
      pixels_28.ofs = 0xb8;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_28,185,iVar8 * 0x1b + 0x13,0,0,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&tmstrsSprites3Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites3Ofs)[iVar8 * 2] = pcVar3;
    }
    for (iVar8 = 0; iVar8 < 7; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x1b) >> 0x10);
      pixels_29.seg = (int)((long)iVar8 * 0x1b) + 8;
      pixels_29.ofs = 0xcf;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_29,223,iVar8 * 0x1b + 0x13,0,0,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&tmstrsSprites2Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites2Ofs)[iVar8 * 2] = pcVar3;
    }
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x800eb)),251,19,0,0,
                              (&psVar1->aptr)->ofs);
    anim_tmstrsCut1Ofs =
         ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    anim_tmstrsCut1Seg = uVar5;
    for (iVar8 = 0; iVar8 < 5; iVar8 = iVar8 + 1) {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x1b) >> 0x10);
      pixels_30.seg = (int)((long)iVar8 * 0x1b) + 8;
      pixels_30.ofs = 0x10b;
      pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,pixels_30,286,iVar8 * 0x1b + 0x13,0,0,
                                (&psVar1->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&tmstrsSprites1Seg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&tmstrsSprites1Ofs)[iVar8 * 2] = pcVar3;
    }
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),psVar1);
  }
  if (in_stack_00000004 != '\0') {
    psVar1 = ovr_grabLbm();
    psStack_a = (stg_tmp_t *)CONCAT22(uVar5,psVar1);
  }
  for (iVar8 = 0; iVar8 < 4; iVar8 = iVar8 + 1) {
    if (in_stack_00000004 == '\0') {
      pfVar2 = ovr_stshAllocStub();
      ((undefined2 *)&boltSpritesSeg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&boltSpritesOfs)[iVar8 * 2] = pfVar2;
    }
    else {
      uVar5 = (uint16_t)((ulong)((long)iVar8 * 0x16) >> 0x10);
      pfVar2 = ovr_stshRleType2((far_t *)(psStack_a->aptr).seg,far_from_u32((uint32_t)((long)iVar8 * 0x16 & 0xffff)),
                                iVar8 * 0x16 + 0x15,14,11,7,(&psStack_a->aptr)->ofs);
      pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
      ((undefined2 *)&boltSpritesSeg)[iVar8 * 2] = uVar5;
      ((undefined2 *)&boltSpritesOfs)[iVar8 * 2] = pcVar3;
    }
  }
  if (in_stack_00000004 == '\0') {
    gamfont1Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    gamfont1Cut1Seg = uVar5;
  }
  else {
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uStack_8)),psStack_a);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    pfVar2 = ovr_stshRleCut();
    gamfont1Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    gamfont1Cut1Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    uVar5 = uVar6;
  }
  if (in_stack_00000004 == '\0') {
    davfontCut1Ofs = (uint16_t)(ovr_stshAllocStub());
    davfontCut1Seg = uVar5;
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    pfVar2 = ovr_stshRleCut();
    davfontCut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    davfontCut1Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    uVar5 = uVar6;
  }
  if (in_stack_00000004 == '\0') {
    _davfont2Cut1Ofs = (cte_t *)ovr_stshAllocStub();
    davfont2Cut1Seg = uVar5;
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    pfVar2 = ovr_stshRleCut();
    _davfont2Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    davfont2Cut1Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    uVar5 = uVar6;
  }
  if (in_stack_00000004 == '\0') {
    demfont1FontOfs = ovr_stshAllocStub();
    demfont1FontSeg = uVar5;
  }
  else {
    psVar1 = ovr_grabLbm();
    FontSize.hi = 0;
    FontSize.lo = 0;
    uVar6 = uVar5;
    ovr_stshProcessFontSub((far_t *)(psVar1->aptr).seg,(&psVar1->aptr)->ofs);
    demfont1FontOfs = (uint16_t)(ovr_stshWrite());
    demfont1FontSeg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    uVar5 = uVar6;
  }
  if (in_stack_00000004 == '\0') {
    talkwin9Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    talkwin9Cut1Seg = uVar5;
    talkwin9Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    talkwin9Cut2Seg = uVar5;
    talkwin9Cut3Ofs = (uint16_t)(ovr_stshAllocStub());
    talkwin9Cut3Seg = uVar5;
    talkwin9Cut4Ofs = (uint16_t)(ovr_stshAllocStub());
    talkwin9Cut4Seg = uVar5;
    talkwin9Cut5Ofs = ovr_stshAllocStub();
    uVar6 = uVar5;
    talkwin9Cut5Seg = uVar5;
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x30008)),226,194,-8,-3,
                              (&psVar1->aptr)->ofs);
    talkwin9Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    talkwin9Cut1Seg = uVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x9d00dd)),229,198,-221,-157,
                              (&psVar1->aptr)->ofs);
    talkwin9Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    talkwin9Cut2Seg = uVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0xc300d0)),223,199,-208,-195,
                              (&psVar1->aptr)->ofs);
    talkwin9Cut3Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    talkwin9Cut3Seg = uVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x750008)),226,194,-8,-117,
                              (&psVar1->aptr)->ofs);
    talkwin9Cut4Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    talkwin9Cut4Seg = uVar6;
    talkwin9Cut5Ofs = (uint16_t)(ovr_stshWrite());
    talkwin9Cut5Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
  }
  if (in_stack_00000004 == '\0') {
    LbxButton2.ofs = (uint16_t)ovr_stshAllocStub();
    LbxButton2.seg = uVar6;
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    pfVar2 = ovr_stshRleCut();
    LbxButton2.ofs =
         (uint16_t)ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    LbxButton2.seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    uVar6 = uVar5;
  }
  if (in_stack_00000004 == '\0') {
    butt01Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    butt01Cut1Seg = uVar6;
    butt01Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    butt01Cut2Seg = uVar6;
    butt01Cut3Ofs = (uint16_t)(ovr_stshAllocStub());
    butt01Cut3Seg = uVar6;
    butt01Cut4Ofs = (uint16_t)(ovr_stshAllocStub());
    butt01Cut4Seg = uVar6;
    butt01Cut5Ofs = (uint16_t)(ovr_stshAllocStub());
    butt01Cut5Seg = uVar6;
    butt01Cut6Ofs = (uint16_t)(ovr_stshAllocStub());
    uVar5 = uVar6;
    butt01Cut6Seg = uVar6;
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    pfVar2 = ovr_stshRleCut();
    butt01Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    butt01Cut1Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    butt01Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    butt01Cut2Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    butt01Cut3Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    butt01Cut3Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    butt01Cut4Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    butt01Cut4Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    butt01Cut5Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    butt01Cut5Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    butt01Cut6Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    butt01Cut6Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
  }
  if (in_stack_00000004 == '\0') {
    button1Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    button1Cut1Seg = uVar5;
    button1Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    button1Cut2Seg = uVar5;
    button1Cut3Ofs = (uint16_t)(ovr_stshAllocStub());
    uVar6 = uVar5;
    button1Cut3Seg = uVar5;
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    pfVar2 = ovr_stshRleCut();
    button1Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    button1Cut1Seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    button1Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    button1Cut2Seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    button1Cut3Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    button1Cut3Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
  }
  if (in_stack_00000004 == '\0') {
    back03Cut1Ofs = ovr_stshAllocStub();
    back03Cut1Seg = uVar6;
    back03Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    back03Cut2Seg = uVar6;
    midgrnd5Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    midgrnd5Cut1Seg = uVar6;
    midgrnd5Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    midgrnd5Cut2Seg = uVar6;
    strong4Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    strong4Cut1Seg = uVar6;
    strong4Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    strong4Cut2Seg = uVar6;
    marbleCut1Ofs = ovr_stshAllocStub();
    marbleCut1Seg = uVar6;
    marbleCut2Ofs = (uint16_t)(ovr_stshAllocStub());
    marbleCut2Seg = uVar6;
    far_t_2000_d3e4.ofs = (uint16_t)ovr_stshAllocStub();
    far_t_2000_d3e4.seg = uVar6;
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    back03Cut1Ofs = (uint16_t)(ovr_stshWrite());
    back03Cut1Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    back03Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    back03Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    pfVar2 = ovr_stshRleCut();
    midgrnd5Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    midgrnd5Cut1Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    pfVar2 = ovr_stshRleCut();
    midgrnd5Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    midgrnd5Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    pfVar2 = ovr_stshRleCut();
    strong4Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    strong4Cut1Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    pfVar2 = ovr_stshRleCut();
    strong4Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    strong4Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    marbleCut1Ofs = (uint16_t)(ovr_stshWrite());
    marbleCut1Seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    marbleCut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    marbleCut2Seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    far_t_2000_d3e4.ofs =
         (uint16_t)ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    far_t_2000_d3e4.seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
  }
  if (in_stack_00000004 == '\0') {
    back2Cut1Ofs = ovr_stshAllocStub();
    back2Cut1Seg = uVar6;
    back2Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    back2Cut2Seg = uVar6;
    midl3Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    midl3Cut1Seg = uVar6;
    midl3Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    midl3Cut2Seg = uVar6;
    frnt3Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    frnt3Cut1Seg = uVar6;
    frnt3Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    frnt3Cut2Seg = uVar6;
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    back2Cut1Ofs = (uint16_t)(ovr_stshWrite());
    back2Cut1Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    back2Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    back2Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    pfVar2 = ovr_stshRleCut();
    midl3Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    midl3Cut1Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    pfVar2 = ovr_stshRleCut();
    midl3Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    midl3Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar7 = uVar5;
    pfVar2 = ovr_stshRleCut();
    frnt3Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),pfVar2);
    frnt3Cut1Seg = uVar7;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar7;
    pfVar2 = ovr_stshRleCut();
    frnt3Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    frnt3Cut2Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),psVar1);
  }
  if (in_stack_00000004 == '\0') {
    winrebg1Cut1Ofs = ovr_stshAllocStub();
    winrebg1Cut1Seg = uVar6;
    winrebg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    winrebg1Cut2Seg = uVar6;
    winremg2Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    winremg2Cut1Seg = uVar6;
    winremg2Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    winremg2Cut2Seg = uVar6;
    winrefg1Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    winrefg1Cut1Seg = uVar6;
    winrefg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    winrefg1Cut2Seg = uVar6;
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    winrebg1Cut1Ofs = (uint16_t)(ovr_stshWrite());
    winrebg1Cut1Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    winrebg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    winrebg1Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    pfVar2 = ovr_stshRleCut();
    winremg2Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    winremg2Cut1Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    pfVar2 = ovr_stshRleCut();
    winremg2Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    winremg2Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar7 = uVar5;
    pfVar2 = ovr_stshRleCut();
    winrefg1Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),pfVar2);
    winrefg1Cut1Seg = uVar7;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar7;
    pfVar2 = ovr_stshRleCut();
    winrefg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    winrefg1Cut2Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),psVar1);
  }
  if (in_stack_00000004 == '\0') {
    captbg2Cut1Ofs = ovr_stshAllocStub();
    captbg2Cut1Seg = uVar6;
    captbg2Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    captbg2Cut2Seg = uVar6;
    captmg3Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    captmg3Cut1Seg = uVar6;
    captmg3Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    captmg3Cut2Seg = uVar6;
    captfg1Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    captfg1Cut1Seg = uVar6;
    captfg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    captfg1Cut2Seg = uVar6;
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    captbg2Cut1Ofs = (uint16_t)(ovr_stshWrite());
    captbg2Cut1Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    captbg2Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    captbg2Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    pfVar2 = ovr_stshRleCut();
    captmg3Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    captmg3Cut1Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    pfVar2 = ovr_stshRleCut();
    captmg3Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    captmg3Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar7 = uVar5;
    pfVar2 = ovr_stshRleCut();
    captfg1Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),pfVar2);
    captfg1Cut1Seg = uVar7;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar7;
    pfVar2 = ovr_stshRleCut();
    captfg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    captfg1Cut2Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),psVar1);
  }
  if (in_stack_00000004 == '\0') {
    l1Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    l1Cut1Seg = uVar6;
    l1Cut2Ofs = ovr_stshAllocStub();
    l1Cut2Seg = uVar6;
    l1Cut3Ofs = (uint16_t)(ovr_stshAllocStub());
    l1Cut3Seg = uVar6;
    l4Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    l4Cut1Seg = uVar6;
    l4Cut2Ofs = ovr_stshAllocStub();
    l4Cut2Seg = uVar6;
    l4Cut3Ofs = (uint16_t)(ovr_stshAllocStub());
    l4Cut3Seg = uVar6;
    l7Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    l7Cut1Seg = uVar6;
    l7Cut2Ofs = ovr_stshAllocStub();
    l7Cut2Seg = uVar6;
    l7Cut3Ofs = (uint16_t)(ovr_stshAllocStub());
    l7Cut3Seg = uVar6;
    l2Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    l2Cut1Seg = uVar6;
    l2Cut2Ofs = ovr_stshAllocStub();
    l2Cut2Seg = uVar6;
    l2Cut3Ofs = (uint16_t)(ovr_stshAllocStub());
    l2Cut3Seg = uVar6;
    l5Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    l5Cut1Seg = uVar6;
    l5Cut2Ofs = ovr_stshAllocStub();
    l5Cut2Seg = uVar6;
    l5Cut3Ofs = (uint16_t)(ovr_stshAllocStub());
    l5Cut3Seg = uVar6;
    l8Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    l8Cut1Seg = uVar6;
    l8Cut2Ofs = ovr_stshAllocStub();
    l8Cut2Seg = uVar6;
    l8Cut3Ofs = (uint16_t)(ovr_stshAllocStub());
    l8Cut3Seg = uVar6;
    l3Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    l3Cut1Seg = uVar6;
    l3Cut2Ofs = ovr_stshAllocStub();
    l3Cut2Seg = uVar6;
    l3Cut3Ofs = (uint16_t)(ovr_stshAllocStub());
    l3Cut3Seg = uVar6;
    l6Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    l6Cut1Seg = uVar6;
    l6Cut2Ofs = ovr_stshAllocStub();
    l6Cut2Seg = uVar6;
    l6Cut3Ofs = (uint16_t)(ovr_stshAllocStub());
    l6Cut3Seg = uVar6;
    l9Cut1Ofs = (uint16_t)(ovr_stshAllocStub());
    l9Cut1Seg = uVar6;
    l9Cut2Ofs = ovr_stshAllocStub();
    l9Cut2Seg = uVar6;
    pcVar3 = (cte_t *)ovr_stshAllocStub();
    l9Cut3Ofs = pcVar3;
    l9Cut3Seg = uVar6;
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l1Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    l1Cut1Seg = uVar5;
    l1Cut2Ofs = (uint16_t)(ovr_stshWrite());
    l1Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l1Cut3Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    l1Cut3Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l4Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    l4Cut1Seg = uVar5;
    l4Cut2Ofs = (uint16_t)(ovr_stshWrite());
    l4Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l4Cut3Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    l4Cut3Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l7Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    l7Cut1Seg = uVar5;
    l7Cut2Ofs = (uint16_t)(ovr_stshWrite());
    l7Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l7Cut3Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    l7Cut3Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l2Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    l2Cut1Seg = uVar5;
    l2Cut2Ofs = (uint16_t)(ovr_stshWrite());
    l2Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar7 = uVar5;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l2Cut3Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),pfVar2);
    l2Cut3Seg = uVar7;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar7;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l5Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    l5Cut1Seg = uVar6;
    l5Cut2Ofs = (uint16_t)(ovr_stshWrite());
    l5Cut2Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l5Cut3Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    l5Cut3Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l8Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    l8Cut1Seg = uVar6;
    l8Cut2Ofs = (uint16_t)(ovr_stshWrite());
    l8Cut2Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l8Cut3Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    l8Cut3Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l3Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    l3Cut1Seg = uVar6;
    l3Cut2Ofs = (uint16_t)(ovr_stshWrite());
    l3Cut2Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l3Cut3Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    l3Cut3Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar5;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l6Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    l6Cut1Seg = uVar6;
    l6Cut2Ofs = (uint16_t)(ovr_stshWrite());
    l6Cut2Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l6Cut3Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    l6Cut3Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar7 = uVar5;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    pfVar2 = ovr_stshRleCut();
    l9Cut1Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),pfVar2);
    l9Cut1Seg = uVar7;
    l9Cut2Ofs = (uint16_t)(ovr_stshWrite());
    l9Cut2Seg = uVar7;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar7;
    ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),psVar1);
    pfVar2 = ovr_stshRleCut();
    pcVar3 = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    l9Cut3Ofs = pcVar3;
    l9Cut3Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),psVar1);
  }
  uVar4 = CONCAT11((char)((uint)pcVar3 >> 8),in_stack_00000004);
  ovr_stshInitAudioAssets(grab_00,uVar4);
  uVar4 = CONCAT11((char)((uint)uVar4 >> 8),in_stack_00000004);
  ovr_stshLoadAudioDrivers((bool)grab_00,uVar4);
  uVar4 = CONCAT11((char)((uint)uVar4 >> 8),in_stack_00000004);
  ovr_stshInitSprites((bool)grab_00,uVar4);
  stshInitTxtFiles(grab_00,CONCAT11((char)((uint)uVar4 >> 8),in_stack_00000004));
  if (in_stack_00000004 == '\0') {
    sky06FliOfs = ovr_stshAllocStub();
  }
  else {
    sky06FliOfs = ovr_stshStoreFile_2((*(uint16_t *)((uint8_t *)&(StshNames[0x19f]) + 2)),(char *)0x0,CONCAT11(uVar9,grab_00));
  }
  sky06FliSeg = uVar6;
  if (in_stack_00000004 == '\0') {
    l9Cut4Ofs = ovr_stshAllocStub();
  }
  else {
    l9Cut4Ofs = ovr_stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),(char *)0x0,
                                    CONCAT11(uVar9,grab_00));
  }
  l9Cut4Seg = uVar6;
  if (in_stack_00000004 == '\0') {
    ssilogoCut1Ofs = ovr_stshAllocStub();
    ssilogoCut1Seg = uVar6;
    ssilogoCut2Ofs = (uint16_t)(ovr_stshAllocStub());
    ssilogoCut2Seg = uVar6;
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    ssilogoCut1Ofs = (uint16_t)(ovr_stshWrite());
    ssilogoCut1Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    ssilogoCut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    ssilogoCut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    uVar6 = uVar5;
  }
  if (in_stack_00000004 == '\0') {
    youlose1Cut1Ofs = ovr_stshAllocStub();
    youlose1Cut1Seg = uVar6;
    youlose1Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    youlose1Cut2Seg = uVar6;
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    youlose1Cut1Ofs = (uint16_t)(ovr_stshWrite());
    youlose1Cut1Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    youlose1Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    youlose1Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    uVar6 = uVar5;
  }
  if (in_stack_00000004 == '\0') {
    cred01Cut1Ofs = ovr_stshAllocStub();
    cred01Cut1Seg = uVar6;
    cred01Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    cred01Cut2Seg = uVar6;
    cred02Cut1Ofs = ovr_stshAllocStub();
    cred02Cut1Seg = uVar6;
    cred02Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    cred02Cut2Seg = uVar6;
    cred03Cut1Ofs = ovr_stshAllocStub();
    cred03Cut1Seg = uVar6;
    cred03Cut2Ofs = (uint16_t)(ovr_stshAllocStub());
    cred03Cut2Seg = uVar6;
  }
  else {
    psVar1 = ovr_grabLbm();
    uVar5 = uVar6;
    cred01Cut1Ofs = (uint16_t)(ovr_stshWrite());
    cred01Cut1Seg = uVar5;
    pfVar2 = ovr_stshRleCut();
    cred01Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),pfVar2);
    cred01Cut2Seg = uVar5;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar7 = uVar5;
    cred02Cut1Ofs = (uint16_t)(ovr_stshWrite());
    cred02Cut1Seg = uVar7;
    pfVar2 = ovr_stshRleCut();
    cred02Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),pfVar2);
    cred02Cut2Seg = uVar7;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar5)),psVar1);
    psVar1 = ovr_grabLbm();
    uVar6 = uVar7;
    cred03Cut1Ofs = (uint16_t)(ovr_stshWrite());
    cred03Cut1Seg = uVar6;
    pfVar2 = ovr_stshRleCut();
    cred03Cut2Ofs = ovr_stshStoreFile((uint8_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar6)),pfVar2);
    cred03Cut2Seg = uVar6;
    ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(uVar9,CONCAT12(grab_00,uVar7)),psVar1);
  }
  if (in_stack_00000004 == '\0') {
    cred03Cut3Ofs = ovr_stshAllocStub();
    cred03Cut3Seg = uVar6;
  }
  else {
    cred03Cut3Ofs =
         ovr_stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),(char *)0x0,
                             CONCAT11(uVar9,grab_00));
    cred03Cut3Seg = uVar6;
  }
  return;
}



/* 81b9:3e84 */

void __cdecl16far grabBldLbm2(int16_t index,int16_t normal,int16_t ruin,...)

{
  int iVar1;
  stg_tmp_t *psVar2;
  far_t *pfVar3;
  cte_t *pcVar4;
  stg_tmp_t *in_DX;
  stg_tmp_t *psVar5;
  uint8_t *puVar6;
  uint8_t *puVar7;
  stg_tmp_t *psVar8;
  int16_t unaff_SI;
  int in_stack_00000004;
  stg_tmp_t *psVar9;
  int16_t iVar11;
  uint8_t *puVar10;
  
  iVar1 = in_stack_00000004;
  psVar2 = ovr_grabLbmTR();
  psVar5 = in_DX;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x820000)),99,194,26,-1,unaff_SI,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  psVar9 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar5);
  pcVar4 = ovr_stshStoreFile((uint8_t *)psVar9,pfVar3);
  iVar11 = (int16_t)((ulong)psVar9 >> 0x10);
  puVar6 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(undefined2 *)((int)&BldGfxNormal[0x19].seg + iVar1 * 0xc) = psVar5;
  ((far_t *)(BldGfxNormal + 0x19) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x820064)),199,194,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar6);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  iVar11 = (int16_t)((ulong)puVar10 >> 0x10);
  puVar7 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxNormal[0x16].seg + iVar1 * 0xc) = (int)puVar6;
  ((far_t *)(BldGfxNormal + 0x16) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x8200c8)),299,194,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar7);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  iVar11 = (int16_t)((ulong)puVar10 >> 0x10);
  puVar6 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxNormal[0x13].seg + iVar1 * 0xc) = (int)puVar7;
  ((far_t *)(BldGfxNormal + 0x13) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x410000)),99,129,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar6);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  iVar11 = (int16_t)((ulong)puVar10 >> 0x10);
  puVar7 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxNormal[0x10].seg + iVar1 * 0xc) = (int)puVar6;
  ((far_t *)(BldGfxNormal + 0x10) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x410064)),199,129,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar7);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  iVar11 = (int16_t)((ulong)puVar10 >> 0x10);
  puVar6 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxNormal[0xd].seg + iVar1 * 0xc) = (int)puVar7;
  ((far_t *)(BldGfxNormal + 0xd) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x4100c8)),299,129,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar6);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  iVar11 = (int16_t)((ulong)puVar10 >> 0x10);
  puVar7 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxNormal[10].seg + iVar1 * 0xc) = (int)puVar6;
  ((far_t *)(BldGfxNormal + 10) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x0)),99,64,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar7);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  iVar11 = (int16_t)((ulong)puVar10 >> 0x10);
  puVar6 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxNormal[7].seg + iVar1 * 0xc) = (int)puVar7;
  ((far_t *)(BldGfxNormal + 7) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x64)),199,64,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar6);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  iVar11 = (int16_t)((ulong)puVar10 >> 0x10);
  puVar7 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxNormal[4].seg + iVar1 * 0xc) = (int)puVar6;
  ((far_t *)(BldGfxNormal + 4) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0xc8)),299,64,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar7);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  psVar8 = (stg_tmp_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxNormal[1].seg + iVar1 * 0xc) = (int)puVar7;
  ((far_t *)(BldGfxNormal + 1) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  psVar9 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar10 >> 0x10),in_DX);
  ovr_stgFreeTmp(psVar9,psVar2);
  iVar11 = (int16_t)((ulong)psVar9 >> 0x10);
  psVar2 = ovr_grabLbmTR();
  psVar5 = psVar8;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x820000)),99,194,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  psVar9 = (stg_tmp_t *)CONCAT22(iVar11,psVar5);
  pcVar4 = ovr_stshStoreFile((uint8_t *)psVar9,pfVar3);
  iVar11 = (int16_t)((ulong)psVar9 >> 0x10);
  puVar6 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxRuin[0x19].seg + iVar1 * 0xc) = (int)psVar5;
  ((far_t *)(BldGfxRuin + 0x19) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x820064)),199,194,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar6);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  iVar11 = (int16_t)((ulong)puVar10 >> 0x10);
  puVar7 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxRuin[0x16].seg + iVar1 * 0xc) = (int)puVar6;
  ((far_t *)(BldGfxRuin + 0x16) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x8200c8)),299,194,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar7);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  iVar11 = (int16_t)((ulong)puVar10 >> 0x10);
  puVar6 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxRuin[0x13].seg + iVar1 * 0xc) = (int)puVar7;
  ((far_t *)(BldGfxRuin + 0x13) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x410000)),99,129,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar6);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  iVar11 = (int16_t)((ulong)puVar10 >> 0x10);
  puVar7 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxRuin[0x10].seg + iVar1 * 0xc) = (int)puVar6;
  ((far_t *)(BldGfxRuin + 0x10) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x410064)),199,129,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar7);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  iVar11 = (int16_t)((ulong)puVar10 >> 0x10);
  puVar6 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxRuin[0xd].seg + iVar1 * 0xc) = (int)puVar7;
  ((far_t *)(BldGfxRuin + 0xd) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x4100c8)),299,129,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar6);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  iVar11 = (int16_t)((ulong)puVar10 >> 0x10);
  puVar7 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxRuin[10].seg + iVar1 * 0xc) = (int)puVar6;
  ((far_t *)(BldGfxRuin + 10) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x0)),99,64,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar7);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  iVar11 = (int16_t)((ulong)puVar10 >> 0x10);
  puVar6 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxRuin[7].seg + iVar1 * 0xc) = (int)puVar7;
  ((far_t *)(BldGfxRuin + 7) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0x64)),199,64,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar6);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  iVar11 = (int16_t)((ulong)puVar10 >> 0x10);
  puVar7 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(int *)((int)&BldGfxRuin[4].seg + iVar1 * 0xc) = (int)puVar6;
  ((far_t *)(BldGfxRuin + 4) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  pfVar3 = ovr_stshRleType2((far_t *)(psVar2->aptr).seg,far_from_u32((uint32_t)(0xc8)),299,64,26,-1,iVar11,
                            (int16_t)psVar2,(&psVar2->aptr)->ofs);
  puVar10 = (uint8_t *)CONCAT22(iVar11,puVar7);
  pcVar4 = ovr_stshStoreFile(puVar10,pfVar3);
  *(int *)((int)&BldGfxRuin[1].seg + iVar1 * 0xc) = (int)puVar7;
  ((far_t *)(BldGfxRuin + 1) + iVar1 * 3)->ofs = (uint16_t)pcVar4;
  ovr_stgFreeTmp((stg_tmp_t *)CONCAT22((int)((ulong)puVar10 >> 0x10),psVar8),psVar2);
  return;
}



/* 81b9:43f1 */

void __cdecl16far stshAllocBldStubs2(int16_t index,...)

{
  int iVar1;
  far_t *pfVar2;
  undefined2 in_DX;
  undefined2 uVar3;
  undefined2 uVar4;
  int in_stack_00000004;
  
  iVar1 = in_stack_00000004;
  pfVar2 = ovr_stshAllocStub();
  uVar3 = 0x195d;
  *(undefined2 *)((int)&BldGfxNormal[0x19].seg + iVar1 * 0xc) = in_DX;
  ((far_t *)(BldGfxNormal + 0x19) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar4 = 0x195d;
  *(undefined2 *)((int)&BldGfxNormal[0x16].seg + iVar1 * 0xc) = uVar3;
  ((far_t *)(BldGfxNormal + 0x16) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar3 = 0x195d;
  *(undefined2 *)((int)&BldGfxNormal[0x13].seg + iVar1 * 0xc) = uVar4;
  ((far_t *)(BldGfxNormal + 0x13) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar4 = 0x195d;
  *(undefined2 *)((int)&BldGfxNormal[0x10].seg + iVar1 * 0xc) = uVar3;
  ((far_t *)(BldGfxNormal + 0x10) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar3 = 0x195d;
  *(undefined2 *)((int)&BldGfxNormal[0xd].seg + iVar1 * 0xc) = uVar4;
  ((far_t *)(BldGfxNormal + 0xd) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar4 = 0x195d;
  *(undefined2 *)((int)&BldGfxNormal[10].seg + iVar1 * 0xc) = uVar3;
  ((far_t *)(BldGfxNormal + 10) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar3 = 0x195d;
  *(undefined2 *)((int)&BldGfxNormal[7].seg + iVar1 * 0xc) = uVar4;
  ((far_t *)(BldGfxNormal + 7) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar4 = 0x195d;
  *(undefined2 *)((int)&BldGfxNormal[4].seg + iVar1 * 0xc) = uVar3;
  ((far_t *)(BldGfxNormal + 4) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar3 = 0x195d;
  *(undefined2 *)((int)&BldGfxNormal[1].seg + iVar1 * 0xc) = uVar4;
  ((far_t *)(BldGfxNormal + 1) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar4 = 0x195d;
  *(undefined2 *)((int)&BldGfxRuin[0x19].seg + iVar1 * 0xc) = uVar3;
  ((far_t *)(BldGfxRuin + 0x19) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar3 = 0x195d;
  *(undefined2 *)((int)&BldGfxRuin[0x16].seg + iVar1 * 0xc) = uVar4;
  ((far_t *)(BldGfxRuin + 0x16) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar4 = 0x195d;
  *(undefined2 *)((int)&BldGfxRuin[0x13].seg + iVar1 * 0xc) = uVar3;
  ((far_t *)(BldGfxRuin + 0x13) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar3 = 0x195d;
  *(undefined2 *)((int)&BldGfxRuin[0x10].seg + iVar1 * 0xc) = uVar4;
  ((far_t *)(BldGfxRuin + 0x10) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar4 = 0x195d;
  *(undefined2 *)((int)&BldGfxRuin[0xd].seg + iVar1 * 0xc) = uVar3;
  ((far_t *)(BldGfxRuin + 0xd) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar3 = 0x195d;
  *(undefined2 *)((int)&BldGfxRuin[10].seg + iVar1 * 0xc) = uVar4;
  ((far_t *)(BldGfxRuin + 10) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar4 = 0x195d;
  *(undefined2 *)((int)&BldGfxRuin[7].seg + iVar1 * 0xc) = uVar3;
  ((far_t *)(BldGfxRuin + 7) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  uVar3 = 0x195d;
  *(undefined2 *)((int)&BldGfxRuin[4].seg + iVar1 * 0xc) = uVar4;
  ((far_t *)(BldGfxRuin + 4) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  pfVar2 = ovr_stshAllocStub();
  *(undefined2 *)((int)&BldGfxRuin[1].seg + iVar1 * 0xc) = uVar3;
  ((far_t *)(BldGfxRuin + 1) + iVar1 * 3)->ofs = (uint16_t)pfVar2;
  return;
}


