/*
 * ovc48.c - recovered from STRONG.EXE
 * memory block: OVC48
 * range: 81b9:0000 - 81b9:4dff
 * functions: 4
 */
#include "recovered.h"


/* 81b9:0000 */

void __cdecl16far stshInitTxtFiles(char grab)

{
  undefined2 unaff_SS;
  far_t fVar1;
  uint8_t local_8c [137];
  byte i;
  
  F_SCOPY(local_8c,(uint8_t *)(far_t *)GTxtFiles,0x88);
  for (i = 0; i < 0x22; i = i + 1) {
    if (grab == '\0') {
      fVar1 = ovr_stshAllocStub();
      *(uint16_t *)((uint)i * 4 + -0x6c6e) = fVar1.seg;
      *(uint16_t *)((uint)i * 4 + -0x6c70) = fVar1.ofs;
    }
    else {
      fVar1 = ovr_stshStoreFile_2(*(char **)(local_8c + (uint)i * 4),0);
      *(uint16_t *)((uint)i * 4 + -0x6c6e) = fVar1.seg;
      *(uint16_t *)((uint)i * 4 + -0x6c70) = fVar1.ofs;
    }
  }
  return;
}



/* 81b9:0086 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far init_assets2(bool grab)

{
  uint16_t uVar1;
  undefined2 uVar2;
  stg_tmp_t *psVar3;
  int iVar4;
  uint8_t *puVar5;
  cte_t *pcVar6;
  far_t fVar7;
  far_t fVar8;
  far_t fVar9;
  far_t fVar10;
  far_t fVar11;
  stg_tmp_t *psVar12;
  far_t fVar13;
  far_t fVar14;
  far_t fVar15;
  uint32_t uVar16;
  far_t fVar17;
  far_t fVar18;
  far_t fVar19;
  far_t fVar20;
  far_t fVar21;
  far_t fVar22;
  far_t fVar23;
  far_t fVar24;
  far_t fVar25;
  far_t fVar26;
  far_t fVar27;
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
  far_t src;
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
  far_t hndl;
  undefined4 uStack_a;
  
  if (grab) {
    grabBldLbm2(218,509,510);
  }
  else {
    stshAllocBldStubs2(218);
  }
  ovr_stshStubifyCopy1to0();
  ovr_stshStubifyCopy1to0();
  ovr_stshStubifyCopy1to0();
  if (grab) {
    grabBldLbm2(227,511,512);
  }
  else {
    stshAllocBldStubs2(227);
  }
  ovr_stshStubifyCopy1to0();
  ovr_stshStubifyCopy1to0();
  ovr_stshStubifyCopy1to0();
  if (grab) {
    uStack_a = ovr_grabLbmTR(527);
  }
  iVar4 = 0;
  while( true ) {
    if (2 < iVar4) break;
    if (grab) {
      fVar7.seg = (((stg_tmp_t *)uStack_a)->aptr).seg;
      fVar7.ofs = (&((stg_tmp_t *)uStack_a)->aptr)->ofs;
      puVar5 = (uint8_t *)ovr_stshRleType2(fVar7,iVar4 * 100 + 0x14,33,iVar4 * 100 + 99,116,10,28);
      pcVar6 = ovr_stshStoreFile(puVar5);
      *(undefined2 *)((int)&BldGfxNormal[1].seg + (iVar4 + 0xec) * 0xc) =
           (int)((ulong)pcVar6 >> 0x10);
      ((far_t *)(BldGfxNormal + 1) + (iVar4 + 0xec) * 3)->ofs = (uint16_t)(cte_t *)pcVar6;
    }
    else {
      fVar7 = ovr_stshAllocStub();
      *(uint16_t *)((int)&BldGfxNormal[1].seg + (iVar4 + 0xec) * 0xc) = fVar7.seg;
      ((far_t *)(BldGfxNormal + 1) + (iVar4 + 0xec) * 3)->ofs = fVar7.ofs;
    }
    uVar1 = ((far_t *)(BldGfxNormal + 1) + (iVar4 + 0xec) * 3)->ofs;
    *(undefined2 *)((int)&BldGfxNormal[0].seg + (iVar4 + 0xec) * 0xc) =
         *(undefined2 *)((int)&BldGfxNormal[1].seg + (iVar4 + 0xec) * 0xc);
    ((far_t *)BldGfxNormal + (iVar4 + 0xec) * 3)->ofs = uVar1;
    uVar1 = ((far_t *)(BldGfxNormal + 1) + (iVar4 + 0xec) * 3)->ofs;
    *(undefined2 *)((int)&BldGfxNormal[2].seg + (iVar4 + 0xec) * 0xc) =
         *(undefined2 *)((int)&BldGfxNormal[1].seg + (iVar4 + 0xec) * 0xc);
    ((far_t *)(BldGfxNormal + 2) + (iVar4 + 0xec) * 3)->ofs = uVar1;
    iVar4 = iVar4 + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(uStack_a);
    uStack_a = ovr_grabLbmTR(528);
  }
  iVar4 = 0;
  while( true ) {
    if (2 < iVar4) break;
    if (grab) {
      pixels.seg = (((stg_tmp_t *)uStack_a)->aptr).seg;
      pixels.ofs = (&((stg_tmp_t *)uStack_a)->aptr)->ofs;
      puVar5 = (uint8_t *)ovr_stshRleType2(pixels,iVar4 * 100 + 0x14,33,iVar4 * 100 + 99,116,10,28);
      pcVar6 = ovr_stshStoreFile(puVar5);
      *(undefined2 *)((int)&BldGfxRuin[1].seg + (iVar4 + 0xec) * 0xc) = (int)((ulong)pcVar6 >> 0x10)
      ;
      ((far_t *)(BldGfxRuin + 1) + (iVar4 + 0xec) * 3)->ofs = (uint16_t)(cte_t *)pcVar6;
    }
    else {
      fVar7 = ovr_stshAllocStub();
      *(uint16_t *)((int)&BldGfxRuin[1].seg + (iVar4 + 0xec) * 0xc) = fVar7.seg;
      ((far_t *)(BldGfxRuin + 1) + (iVar4 + 0xec) * 3)->ofs = fVar7.ofs;
    }
    iVar4 = iVar4 + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(uStack_a);
  }
  ovr_stshStubifyCopy1to0();
  if (grab) {
    psVar12 = ovr_grabLbmTR(529);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    pixels_00.seg = (psVar3->aptr).seg;
    pixels_00.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_00,0,130,99,194,26,-1);
    pcVar6 = ovr_stshStoreFile(puVar5);
    BldGfxNormal[0x2e6].seg = (uint16_t)((ulong)pcVar6 >> 0x10);
    BldGfxNormal[0x2e6].ofs = (uint16_t)pcVar6;
    pixels_01.seg = (psVar3->aptr).seg;
    pixels_01.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_01,100,130,199,194,26,-1);
    pcVar6 = ovr_stshStoreFile(puVar5);
    BldGfxNormal[0x2e3].seg = (uint16_t)((ulong)pcVar6 >> 0x10);
    BldGfxNormal[0x2e3].ofs = (uint16_t)pcVar6;
    pixels_02.seg = (psVar3->aptr).seg;
    pixels_02.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_02,200,130,299,194,26,-1);
    pcVar6 = ovr_stshStoreFile(puVar5);
    BldGfxNormal[0x2e0].seg = (uint16_t)((ulong)pcVar6 >> 0x10);
    BldGfxNormal[0x2e0].ofs = (uint16_t)pcVar6;
    pixels_03.seg = (psVar3->aptr).seg;
    pixels_03.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_03,0,65,99,129,26,-1);
    pcVar6 = ovr_stshStoreFile(puVar5);
    BldGfxNormal[0x2dd].seg = (uint16_t)((ulong)pcVar6 >> 0x10);
    BldGfxNormal[0x2dd].ofs = (uint16_t)pcVar6;
    pixels_04.seg = (psVar3->aptr).seg;
    pixels_04.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_04,100,65,199,129,26,-1);
    pcVar6 = ovr_stshStoreFile(puVar5);
    BldGfxNormal[0x2da].seg = (uint16_t)((ulong)pcVar6 >> 0x10);
    BldGfxNormal[0x2da].ofs = (uint16_t)pcVar6;
    pixels_05.seg = (psVar3->aptr).seg;
    pixels_05.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_05,200,65,299,129,26,-1);
    pcVar6 = ovr_stshStoreFile(puVar5);
    BldGfxNormal[0x2d7].seg = (uint16_t)((ulong)pcVar6 >> 0x10);
    BldGfxNormal[0x2d7].ofs = (uint16_t)pcVar6;
    pixels_06.seg = (psVar3->aptr).seg;
    pixels_06.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_06,0,0,99,64,26,-1);
    pcVar6 = ovr_stshStoreFile(puVar5);
    BldGfxNormal[0x2d4].seg = (uint16_t)((ulong)pcVar6 >> 0x10);
    BldGfxNormal[0x2d4].ofs = (uint16_t)pcVar6;
    pixels_07.seg = (psVar3->aptr).seg;
    pixels_07.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_07,100,0,199,64,26,-1);
    pcVar6 = ovr_stshStoreFile(puVar5);
    BldGfxNormal[0x2d1].seg = (uint16_t)((ulong)pcVar6 >> 0x10);
    BldGfxNormal[0x2d1].ofs = (uint16_t)pcVar6;
    pixels_08.seg = (psVar3->aptr).seg;
    pixels_08.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_08,200,0,299,64,26,-1);
    pcVar6 = ovr_stshStoreFile(puVar5);
    BldGfxNormal[0x2ce].seg = (uint16_t)((ulong)pcVar6 >> 0x10);
    BldGfxNormal[0x2ce].ofs = (uint16_t)pcVar6;
    ovr_stgFreeTmp(psVar12);
    uStack_a = psVar12;
  }
  else {
    fVar7 = ovr_stshAllocStub();
    BldGfxNormal[0x2e6].seg = fVar7.seg;
    BldGfxNormal[0x2e6].ofs = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    BldGfxNormal[0x2e3].seg = fVar7.seg;
    BldGfxNormal[0x2e3].ofs = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    BldGfxNormal[0x2e0].seg = fVar7.seg;
    BldGfxNormal[0x2e0].ofs = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    BldGfxNormal[0x2dd].seg = fVar7.seg;
    BldGfxNormal[0x2dd].ofs = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    BldGfxNormal[0x2da].seg = fVar7.seg;
    BldGfxNormal[0x2da].ofs = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    BldGfxNormal[0x2d7].seg = fVar7.seg;
    BldGfxNormal[0x2d7].ofs = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    BldGfxNormal[0x2d4].seg = fVar7.seg;
    BldGfxNormal[0x2d4].ofs = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    BldGfxNormal[0x2d1].seg = fVar7.seg;
    BldGfxNormal[0x2d1].ofs = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    BldGfxNormal[0x2ce].seg = fVar7.seg;
    BldGfxNormal[0x2ce].ofs = fVar7.ofs;
  }
  ovr_stshStubifyCopy1to0();
  ovr_stshStubifyCopy1to0();
  ovr_stshStubifyCopy1to0();
  for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
    *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar4 * 4) = 0;
    ((far_t *)BldGfxNormal + iVar4)->ofs = 0;
  }
  if (grab) {
    psVar12 = ovr_grabLbmTR(10);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    pixels_09.seg = (psVar3->aptr).seg;
    pixels_09.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_09,12,7,222,150,-12,-7);
    pcVar6 = ovr_stshStoreFile(puVar5);
    DAT_2000_d1a5 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d1a3 = (uint16_t)(pcVar6);
    src.seg = (psVar3->aptr).seg;
    src.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src,239,7,308,54);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d1a1 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d19f = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar8.seg = DAT_2000_d1a1;
    fVar8.ofs = (uint16_t)DAT_2000_d19f;
    uStack_a = psVar12;
  }
  else {
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d1a5 = fVar7.seg;
    DAT_2000_d1a3 = (uint16_t)(fVar7.ofs);
    fVar8 = ovr_stshAllocStub();
  }
  DAT_2000_d1a1 = fVar8.seg;
  DAT_2000_d19f = (uint16_t)(fVar8.ofs);
  if (grab) {
    psVar12 = ovr_grabLbmTR(14);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    SpecialColors[0] = *(uint8_t *)((int)&GStrangeTable[0x12].ofs + 1 + (psVar3->aptr).ofs);
    SpecialColors[1] = ((char *)"%s turns %d undead." + 0x12)[(psVar3->aptr).ofs];
    SpecialColors[2] = ((char *)"If you lead with wisdom and cunning..." + 9)[(psVar3->aptr).ofs];
    SpecialColors[3] =
         ((char *)"ENTER: use previous configuration, SPACE: reconfigure, ESC: quit" + 0x12)
         [(psVar3->aptr).ofs];
    SpecialColors[4] = ((char *)"%s turns %d undead." + 0x10)[(psVar3->aptr).ofs];
    SpecialColors[5] = *(uint8_t *)((int)&GStrangeTable[0x12].seg + 1 + (psVar3->aptr).ofs);
    SpecialColors[6] = *(uint8_t *)((int)(undefined2 *)&DAT_2000_d43e + (psVar3->aptr).ofs);
    SpecialColors[7] = *(uint8_t *)((psVar3->aptr).ofs + 0x936e);
    uVar16 = ovr_stshWrite((uint8_t *)SpecialColors,8);
    DAT_2000_d1ce = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d1cc = (uint16_t)uVar16;
    src_00.seg = (psVar3->aptr).seg;
    src_00.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_00,234,64,314,120);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_cafb = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_caf9 = (uint16_t)(pcVar6);
    src_01.seg = (psVar3->aptr).seg;
    src_01.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_01,208,158,228,176);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_cb13 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_cb11 = (uint16_t)(pcVar6);
    src_02.seg = (psVar3->aptr).seg;
    src_02.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_02,179,180,198,196);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_cacb = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_cac9 = (uint16_t)(pcVar6);
    src_03.seg = (psVar3->aptr).seg;
    src_03.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_03,207,180,226,196);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_cac7 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_cac5 = (uint16_t)(pcVar6);
    src_04.seg = (psVar3->aptr).seg;
    src_04.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_04,38,181,57,196);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_cac3 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_cac1 = (uint16_t)(pcVar6);
    src_05.seg = (psVar3->aptr).seg;
    src_05.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_05,9,181,24,196);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_cabf = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_cabd = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar9.seg = DAT_2000_cabf;
    fVar9.ofs = (uint16_t)DAT_2000_cabd;
    uStack_a = psVar12;
  }
  else {
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d1ce = fVar7.seg;
    DAT_2000_d1cc = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_cafb = fVar7.seg;
    DAT_2000_caf9 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_cb13 = fVar7.seg;
    DAT_2000_cb11 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_cacb = fVar7.seg;
    DAT_2000_cac9 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_cac7 = fVar7.seg;
    DAT_2000_cac5 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_cac3 = fVar7.seg;
    DAT_2000_cac1 = (uint16_t)(fVar7.ofs);
    fVar9 = ovr_stshAllocStub();
  }
  DAT_2000_cabf = fVar9.seg;
  DAT_2000_cabd = (uint16_t)(fVar9.ofs);
  if (grab) {
    psVar12 = ovr_grabLbmTR(127);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_06.seg = (psVar3->aptr).seg;
    src_06.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_06,245,116,267,128);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_ca3a = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_ca38 = (uint16_t)(pcVar6);
    src_07.seg = (psVar3->aptr).seg;
    src_07.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_07,292,114,314,133);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_caf7 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_caf5 = (uint16_t)(pcVar6);
    src_08.seg = (psVar3->aptr).seg;
    src_08.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_08,221,157,228,198);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_caf3 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_caf1 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar10.seg = DAT_2000_caf3;
    fVar10.ofs = (uint16_t)DAT_2000_caf1;
    uStack_a = psVar12;
  }
  else {
    fVar7 = ovr_stshAllocStub();
    DAT_2000_ca3a = fVar7.seg;
    DAT_2000_ca38 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_caf7 = fVar7.seg;
    DAT_2000_caf5 = (uint16_t)(fVar7.ofs);
    fVar10 = ovr_stshAllocStub();
  }
  DAT_2000_caf3 = fVar10.seg;
  DAT_2000_caf1 = (uint16_t)(fVar10.ofs);
  if (grab) {
    psVar12 = ovr_grabLbm(15,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    Lbm_nwpanel1 = far_from_u32((uint32_t)(ovr_stshWrite(psVar3->cmap,0x300)));
    src_09.seg = (psVar3->aptr).seg;
    src_09.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_09,230,57,314,113);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_caff = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_cafd = (uint16_t)(pcVar6);
    src_10.seg = (psVar3->aptr).seg;
    src_10.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_10,0,0,319,199);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_cacf = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_cacd = (uint16_t)(pcVar6);
    src_11.seg = (psVar3->aptr).seg;
    src_11.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_11,29,156,207,199);
    FontHandle = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs))));
    src_12.seg = (psVar3->aptr).seg;
    src_12.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_12,9,181,28,196);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_cabb = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_cab9 = (uint16_t)(pcVar6);
    src_13.seg = (psVar3->aptr).seg;
    src_13.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_13,223,8,237,50);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_caab = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_caa9 = (uint16_t)(pcVar6);
    src_14.seg = (psVar3->aptr).seg;
    src_14.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_14,6,156,28,171);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d1aa = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d1a8 = (uint16_t)(pcVar6);
    src_15.seg = (psVar3->aptr).seg;
    src_15.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_15,208,157,229,198);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d119 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d117 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar11.seg = DAT_2000_d119;
    fVar11.ofs = (uint16_t)DAT_2000_d117;
    uStack_a = psVar12;
  }
  else {
    Lbm_nwpanel1 = ovr_stshAllocStub();
    fVar7 = ovr_stshAllocStub();
    DAT_2000_caff = fVar7.seg;
    DAT_2000_cafd = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_cacf = fVar7.seg;
    DAT_2000_cacd = (uint16_t)(fVar7.ofs);
    FontHandle = ovr_stshAllocStub();
    fVar7 = ovr_stshAllocStub();
    DAT_2000_cabb = fVar7.seg;
    DAT_2000_cab9 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_caab = fVar7.seg;
    DAT_2000_caa9 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d1aa = fVar7.seg;
    DAT_2000_d1a8 = (uint16_t)(fVar7.ofs);
    fVar11 = ovr_stshAllocStub();
  }
  DAT_2000_d119 = fVar11.seg;
  DAT_2000_d117 = (uint16_t)(fVar11.ofs);
  if (grab) {
    uStack_a = ovr_grabLbm(12,0,0);
    psVar3 = (stg_tmp_t *)uStack_a;
    uVar2 = (undefined2)((ulong)uStack_a >> 0x10);
    for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
      src_16.seg = (psVar3->aptr).seg;
      src_16.ofs = (&psVar3->aptr)->ofs;
      fVar7 = ovr_stshRleCut(src_16,iVar4 * 0xe,46,iVar4 * 0xe + 0xd,55);
      pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
      *(undefined2 *)((int)&CrossBlitGfx.seg + iVar4 * 4) = (int)((ulong)pcVar6 >> 0x10);
      ((far_t *)&CrossBlitGfx + iVar4)->ofs = (uint16_t)(cte_t *)pcVar6;
      pixels_10.seg = (psVar3->aptr).seg;
      pixels_10.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)ovr_stshRleType2(pixels_10,iVar4 * 0xe,16,iVar4 * 0xe + 0xd,24,6,4);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cc67)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cc65)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    ovr_stgFreeTmp(uStack_a);
    fVar11.seg = DAT_2000_d119;
    fVar11.ofs = (uint16_t)DAT_2000_d117;
  }
  else {
    iVar4 = 0;
    while( true ) {
      DAT_2000_d119 = fVar11.seg;
      DAT_2000_d117 = (uint16_t)(fVar11.ofs);
      if (3 < iVar4) break;
      fVar7 = ovr_stshAllocStub();
      *(uint16_t *)((int)&CrossBlitGfx.seg + iVar4 * 4) = fVar7.seg;
      ((far_t *)&CrossBlitGfx + iVar4)->ofs = fVar7.ofs;
      fVar7 = ovr_stshAllocStub();
      ((undefined2 *)&DAT_2000_cc67)[iVar4 * 2] = fVar7.seg;
      ((undefined2 *)&DAT_2000_cc65)[iVar4 * 2] = fVar7.ofs;
      fVar11.seg = DAT_2000_d119;
      fVar11.ofs = (uint16_t)DAT_2000_d117;
      iVar4 = iVar4 + 1;
    }
  }
  DAT_2000_d119 = fVar11.seg;
  DAT_2000_d117 = (uint16_t)(fVar11.ofs);
  if (grab) {
    psVar12 = ovr_grabLbm(93,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
      pixels_11.seg = (psVar3->aptr).seg;
      pixels_11.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)ovr_stshRleType2(pixels_11,8,iVar4 * 0x20 + 10,63,iVar4 * 0x20 + 0x24,0,0)
      ;
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cc0b)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cc09)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
      pixels_12.seg = (psVar3->aptr).seg;
      pixels_12.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_12,85,iVar4 * 0x20 + 10,140,iVar4 * 0x20 + 0x24,0,0);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cc23)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cc21)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
      pixels_13.seg = (psVar3->aptr).seg;
      pixels_13.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_13,159,iVar4 * 0x20 + 10,214,iVar4 * 0x20 + 0x24,0,0);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cc3b)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cc39)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 5; iVar4 = iVar4 + 1) {
      pixels_14.seg = (psVar3->aptr).seg;
      pixels_14.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_14,229,iVar4 * 0x20 + 10,284,iVar4 * 0x20 + 0x24,0,0);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cc53)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cc51)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(94,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_15.seg = (psVar3->aptr).seg;
      pixels_15.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_15,0,iVar4 * 0x3d + 0x11,104,iVar4 * 0x3d + 0x49,0,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cbab)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cba9)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_16.seg = (psVar3->aptr).seg;
      pixels_16.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_16,109,iVar4 * 0x3d + 0x11,213,iVar4 * 0x3d + 0x49,0,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cbb7)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cbb5)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_17.seg = (psVar3->aptr).seg;
      pixels_17.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_17,215,iVar4 * 0x3d + 0x11,319,iVar4 * 0x3d + 0x49,0,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cbc3)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cbc1)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(95,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_18.seg = (psVar3->aptr).seg;
      pixels_18.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_18,0,iVar4 * 0x3d + 0x11,104,iVar4 * 0x3d + 0x49,0,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cbcf)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cbcd)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_19.seg = (psVar3->aptr).seg;
      pixels_19.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_19,109,iVar4 * 0x3d + 0x11,213,iVar4 * 0x3d + 0x49,0,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cbdb)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cbd9)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(96,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_20.seg = (psVar3->aptr).seg;
      pixels_20.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_20,0,iVar4 * 0x3d + 0x11,104,iVar4 * 0x3d + 0x49,0,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cbe7)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cbe5)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_21.seg = (psVar3->aptr).seg;
      pixels_21.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_21,109,iVar4 * 0x3d + 0x11,213,iVar4 * 0x3d + 0x49,0,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cbf3)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cbf1)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_22.seg = (psVar3->aptr).seg;
      pixels_22.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_22,215,iVar4 * 0x3d + 0x11,319,iVar4 * 0x3d + 0x49,0,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cbff)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cbfd)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(531,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_23.seg = (psVar3->aptr).seg;
      pixels_23.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_23,1,iVar4 * 0x3d + 0x11,103,iVar4 * 0x3d + 0x49,-4,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cb2b)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cb29)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_24.seg = (psVar3->aptr).seg;
      pixels_24.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_24,104,iVar4 * 0x3d + 0x11,206,iVar4 * 0x3d + 0x49,-4,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cb37)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cb35)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_25.seg = (psVar3->aptr).seg;
      pixels_25.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_25,209,iVar4 * 0x3d + 0x11,311,iVar4 * 0x3d + 0x49,-4,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cb43)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cb41)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(532,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_26.seg = (psVar3->aptr).seg;
      pixels_26.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_26,1,iVar4 * 0x3d + 0x11,103,iVar4 * 0x3d + 0x49,-4,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cb4f)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cb4d)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_27.seg = (psVar3->aptr).seg;
      pixels_27.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_27,104,iVar4 * 0x3d + 0x11,206,iVar4 * 0x3d + 0x49,-4,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cb5b)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cb59)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_28.seg = (psVar3->aptr).seg;
      pixels_28.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_28,209,iVar4 * 0x3d + 0x11,311,iVar4 * 0x3d + 0x49,-4,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cb67)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cb65)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(533,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_29.seg = (psVar3->aptr).seg;
      pixels_29.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_29,1,iVar4 * 0x3d + 0x11,103,iVar4 * 0x3d + 0x49,-4,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cb73)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cb71)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_30.seg = (psVar3->aptr).seg;
      pixels_30.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_30,104,iVar4 * 0x3d + 0x11,206,iVar4 * 0x3d + 0x49,-4,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cb7f)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cb7d)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_31.seg = (psVar3->aptr).seg;
      pixels_31.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_31,209,iVar4 * 0x3d + 0x11,311,iVar4 * 0x3d + 0x49,-4,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cb8b)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cb89)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(534,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_32.seg = (psVar3->aptr).seg;
      pixels_32.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_32,1,iVar4 * 0x3d + 0x11,103,iVar4 * 0x3d + 0x49,-4,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cb97)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cb95)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 2; iVar4 = iVar4 + 1) {
      pixels_33.seg = (psVar3->aptr).seg;
      pixels_33.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_33,104,iVar4 * 0x3d + 0x11,206,iVar4 * 0x3d + 0x49,-4,-60);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_cba3)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_cba1)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    ovr_stgFreeTmp(psVar12);
    uStack_a = ovr_grabLbm(535,0,0);
    psVar3 = (stg_tmp_t *)uStack_a;
    uVar2 = (undefined2)((ulong)uStack_a >> 0x10);
    for (iVar4 = 0; iVar4 < 7; iVar4 = iVar4 + 1) {
      pixels_34.seg = (psVar3->aptr).seg;
      pixels_34.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)ovr_stshRleType2(pixels_34,6,iVar4 * 0x1b + 8,33,iVar4 * 0x1b + 0x13,0,0);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_d2a0)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_d29e)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 7; iVar4 = iVar4 + 1) {
      pixels_35.seg = (psVar3->aptr).seg;
      pixels_35.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)ovr_stshRleType2(pixels_35,35,iVar4 * 0x1b + 8,62,iVar4 * 0x1b + 0x13,0,0)
      ;
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_d2bc)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_d2ba)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 7; iVar4 = iVar4 + 1) {
      pixels_36.seg = (psVar3->aptr).seg;
      pixels_36.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)ovr_stshRleType2(pixels_36,76,iVar4 * 0x1b + 8,88,iVar4 * 0x1b + 0x13,0,0)
      ;
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_d25c)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_d25a)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 7; iVar4 = iVar4 + 1) {
      pixels_37.seg = (psVar3->aptr).seg;
      pixels_37.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_37,102,iVar4 * 0x1b + 8,114,iVar4 * 0x1b + 0x13,0,0);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_d278)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_d276)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
      pixels_38.seg = (psVar3->aptr).seg;
      pixels_38.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_38,128,iVar4 * 0x1b + 8,140,iVar4 * 0x1b + 0x13,0,0);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_d294)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_d292)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 7; iVar4 = iVar4 + 1) {
      pixels_39.seg = (psVar3->aptr).seg;
      pixels_39.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_39,154,iVar4 * 0x1b + 8,163,iVar4 * 0x1b + 0x13,0,0);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_d240)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_d23e)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 7; iVar4 = iVar4 + 1) {
      pixels_40.seg = (psVar3->aptr).seg;
      pixels_40.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_40,184,iVar4 * 0x1b + 8,185,iVar4 * 0x1b + 0x13,0,0);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_d224)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_d222)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    for (iVar4 = 0; iVar4 < 7; iVar4 = iVar4 + 1) {
      pixels_41.seg = (psVar3->aptr).seg;
      pixels_41.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_41,207,iVar4 * 0x1b + 8,223,iVar4 * 0x1b + 0x13,0,0);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_d204)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_d202)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    pixels_42.seg = (psVar3->aptr).seg;
    pixels_42.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_42,235,8,251,19,0,0);
    pcVar6 = ovr_stshStoreFile(puVar5);
    iVar4 = 0;
    while( true ) {
      DAT_2000_d220 = (undefined2)((ulong)pcVar6 >> 0x10);
      DAT_2000_d21e = (uint16_t)(pcVar6);
      if (4 < iVar4) break;
      pixels_43.seg = (psVar3->aptr).seg;
      pixels_43.ofs = (&psVar3->aptr)->ofs;
      puVar5 = (uint8_t *)
               ovr_stshRleType2(pixels_43,267,iVar4 * 0x1b + 8,286,iVar4 * 0x1b + 0x13,0,0);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_d1f0)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_d1ee)[iVar4 * 2] = (uint16_t)(pcVar6);
      pcVar6 = (cte_t *)CONCAT22(DAT_2000_d220,DAT_2000_d21e);
      iVar4 = iVar4 + 1;
    }
    ovr_stgFreeTmp(uStack_a);
    fVar11.seg = DAT_2000_d119;
    fVar11.ofs = (uint16_t)DAT_2000_d117;
  }
  else {
    iVar4 = 0;
    while( true ) {
      DAT_2000_d119 = fVar11.seg;
      DAT_2000_d117 = (uint16_t)(fVar11.ofs);
      if (0x16 < iVar4) break;
      fVar7 = ovr_stshAllocStub();
      ((undefined2 *)&DAT_2000_cc0b)[iVar4 * 2] = fVar7.seg;
      ((undefined2 *)&DAT_2000_cc09)[iVar4 * 2] = fVar7.ofs;
      fVar11.seg = DAT_2000_d119;
      fVar11.ofs = (uint16_t)DAT_2000_d117;
      iVar4 = iVar4 + 1;
    }
    iVar4 = 0;
    while( true ) {
      DAT_2000_d119 = fVar11.seg;
      DAT_2000_d117 = (uint16_t)(fVar11.ofs);
      if (0x17 < iVar4) break;
      fVar7 = ovr_stshAllocStub();
      ((undefined2 *)&DAT_2000_cbab)[iVar4 * 2] = fVar7.seg;
      ((undefined2 *)&DAT_2000_cba9)[iVar4 * 2] = fVar7.ofs;
      fVar11.seg = DAT_2000_d119;
      fVar11.ofs = (uint16_t)DAT_2000_d117;
      iVar4 = iVar4 + 1;
    }
    iVar4 = 0;
    while( true ) {
      DAT_2000_d119 = fVar11.seg;
      DAT_2000_d117 = (uint16_t)(fVar11.ofs);
      if (0x1f < iVar4) break;
      fVar7 = ovr_stshAllocStub();
      ((undefined2 *)&DAT_2000_cb2b)[iVar4 * 2] = fVar7.seg;
      ((undefined2 *)&DAT_2000_cb29)[iVar4 * 2] = fVar7.ofs;
      fVar11.seg = DAT_2000_d119;
      fVar11.ofs = (uint16_t)DAT_2000_d117;
      iVar4 = iVar4 + 1;
    }
    iVar4 = 0;
    while( true ) {
      DAT_2000_d119 = fVar11.seg;
      DAT_2000_d117 = (uint16_t)(fVar11.ofs);
      if (0xd < iVar4) break;
      fVar7 = ovr_stshAllocStub();
      ((undefined2 *)&DAT_2000_d2a0)[iVar4 * 2] = fVar7.seg;
      ((undefined2 *)&DAT_2000_d29e)[iVar4 * 2] = fVar7.ofs;
      fVar11.seg = DAT_2000_d119;
      fVar11.ofs = (uint16_t)DAT_2000_d117;
      iVar4 = iVar4 + 1;
    }
    iVar4 = 0;
    while( true ) {
      DAT_2000_d119 = fVar11.seg;
      DAT_2000_d117 = (uint16_t)(fVar11.ofs);
      if (0x10 < iVar4) break;
      fVar7 = ovr_stshAllocStub();
      ((undefined2 *)&DAT_2000_d25c)[iVar4 * 2] = fVar7.seg;
      ((undefined2 *)&DAT_2000_d25a)[iVar4 * 2] = fVar7.ofs;
      fVar11.seg = DAT_2000_d119;
      fVar11.ofs = (uint16_t)DAT_2000_d117;
      iVar4 = iVar4 + 1;
    }
    iVar4 = 0;
    while( true ) {
      DAT_2000_d119 = fVar11.seg;
      DAT_2000_d117 = (uint16_t)(fVar11.ofs);
      if (6 < iVar4) break;
      fVar7 = ovr_stshAllocStub();
      ((undefined2 *)&DAT_2000_d240)[iVar4 * 2] = fVar7.seg;
      ((undefined2 *)&DAT_2000_d23e)[iVar4 * 2] = fVar7.ofs;
      fVar11.seg = DAT_2000_d119;
      fVar11.ofs = (uint16_t)DAT_2000_d117;
      iVar4 = iVar4 + 1;
    }
    iVar4 = 0;
    while( true ) {
      DAT_2000_d119 = fVar11.seg;
      DAT_2000_d117 = (uint16_t)(fVar11.ofs);
      if (6 < iVar4) break;
      fVar7 = ovr_stshAllocStub();
      ((undefined2 *)&DAT_2000_d224)[iVar4 * 2] = fVar7.seg;
      ((undefined2 *)&DAT_2000_d222)[iVar4 * 2] = fVar7.ofs;
      fVar11.seg = DAT_2000_d119;
      fVar11.ofs = (uint16_t)DAT_2000_d117;
      iVar4 = iVar4 + 1;
    }
    iVar4 = 0;
    while( true ) {
      DAT_2000_d119 = fVar11.seg;
      DAT_2000_d117 = (uint16_t)(fVar11.ofs);
      if (7 < iVar4) break;
      fVar7 = ovr_stshAllocStub();
      ((undefined2 *)&DAT_2000_d204)[iVar4 * 2] = fVar7.seg;
      ((undefined2 *)&DAT_2000_d202)[iVar4 * 2] = fVar7.ofs;
      fVar11.seg = DAT_2000_d119;
      fVar11.ofs = (uint16_t)DAT_2000_d117;
      iVar4 = iVar4 + 1;
    }
    iVar4 = 0;
    while( true ) {
      DAT_2000_d119 = fVar11.seg;
      DAT_2000_d117 = (uint16_t)(fVar11.ofs);
      if (4 < iVar4) break;
      fVar7 = ovr_stshAllocStub();
      ((undefined2 *)&DAT_2000_d1f0)[iVar4 * 2] = fVar7.seg;
      ((undefined2 *)&DAT_2000_d1ee)[iVar4 * 2] = fVar7.ofs;
      fVar11.seg = DAT_2000_d119;
      fVar11.ofs = (uint16_t)DAT_2000_d117;
      iVar4 = iVar4 + 1;
    }
  }
  DAT_2000_d119 = fVar11.seg;
  DAT_2000_d117 = (uint16_t)(fVar11.ofs);
  if (grab) {
    uStack_a = ovr_grabLbm(35,0,0);
    fVar11.seg = DAT_2000_d119;
    fVar11.ofs = (uint16_t)DAT_2000_d117;
  }
  iVar4 = 0;
  while( true ) {
    DAT_2000_d119 = fVar11.seg;
    DAT_2000_d117 = (uint16_t)(fVar11.ofs);
    if (3 < iVar4) break;
    if (grab) {
      pixels_44.seg = (((stg_tmp_t *)uStack_a)->aptr).seg;
      pixels_44.ofs = (&((stg_tmp_t *)uStack_a)->aptr)->ofs;
      puVar5 = (uint8_t *)ovr_stshRleType2(pixels_44,iVar4 * 0x16,0,iVar4 * 0x16 + 0x15,14,11,7);
      pcVar6 = ovr_stshStoreFile(puVar5);
      ((undefined2 *)&DAT_2000_d2ee)[iVar4 * 2] = (int)((ulong)pcVar6 >> 0x10);
      ((undefined2 *)&DAT_2000_d2ec)[iVar4 * 2] = (uint16_t)(pcVar6);
    }
    else {
      fVar7 = ovr_stshAllocStub();
      ((undefined2 *)&DAT_2000_d2ee)[iVar4 * 2] = fVar7.seg;
      ((undefined2 *)&DAT_2000_d2ec)[iVar4 * 2] = fVar7.ofs;
    }
    fVar11.seg = DAT_2000_d119;
    fVar11.ofs = (uint16_t)DAT_2000_d117;
    iVar4 = iVar4 + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(uStack_a);
    psVar12 = ovr_grabLbm(8,0,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_17.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_17.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_17,0,0,319,199);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d1ca = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d1c8 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar13.seg = DAT_2000_d1ca;
    fVar13.ofs = (uint16_t)DAT_2000_d1c8;
  }
  else {
    fVar13 = ovr_stshAllocStub();
  }
  DAT_2000_d1ca = fVar13.seg;
  DAT_2000_d1c8 = (uint16_t)(fVar13.ofs);
  if (grab) {
    psVar12 = ovr_grabLbm(6,0,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_18.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_18.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_18,0,0,319,199);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d1c6 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d1c4 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar14.seg = DAT_2000_d1c6;
    fVar14.ofs = (uint16_t)DAT_2000_d1c4;
  }
  else {
    fVar14 = ovr_stshAllocStub();
  }
  DAT_2000_d1c6 = fVar14.seg;
  DAT_2000_d1c4 = (uint16_t)(fVar14.ofs);
  if (grab) {
    psVar12 = ovr_grabLbm(140,0,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_19.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_19.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_19,0,0,319,27);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d1c2 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d1c0 = (uint16_t)pcVar6;
    ovr_stgFreeTmp(psVar12);
    fVar15.seg = DAT_2000_d1c2;
    fVar15.ofs = (uint16_t)DAT_2000_d1c0;
  }
  else {
    fVar15 = ovr_stshAllocStub();
  }
  DAT_2000_d1c2 = fVar15.seg;
  DAT_2000_d1c0 = fVar15.ofs;
  if (grab) {
    psVar12 = ovr_grabLbm(411,0,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    FontSize.hi = 0;
    FontSize.lo = 0;
    hndl.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    hndl.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshProcessFontSub(hndl);
    uVar16 = ovr_stshWrite((uint8_t *)fVar7.ofs,CONCAT22(FontSize.hi,FontSize.lo));
    DAT_2000_d47e = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d47c = (uint16_t)uVar16;
    ovr_stgFreeTmp(psVar12);
    fVar17.seg = DAT_2000_d47e;
    fVar17.ofs = DAT_2000_d47c;
  }
  else {
    fVar17 = ovr_stshAllocStub();
  }
  DAT_2000_d47e = fVar17.seg;
  DAT_2000_d47c = fVar17.ofs;
  if (grab) {
    psVar12 = ovr_grabLbm(78,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    pixels_45.seg = (psVar3->aptr).seg;
    pixels_45.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_45,8,3,226,194,-8,-3);
    pcVar6 = ovr_stshStoreFile(puVar5);
    DAT_2000_cc87 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_cc85 = (uint16_t)(pcVar6);
    pixels_46.seg = (psVar3->aptr).seg;
    pixels_46.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_46,221,157,229,198,-221,-157);
    pcVar6 = ovr_stshStoreFile(puVar5);
    DAT_2000_d3a6 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d3a4 = (uint16_t)(pcVar6);
    pixels_47.seg = (psVar3->aptr).seg;
    pixels_47.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_47,208,195,223,199,-208,-195);
    pcVar6 = ovr_stshStoreFile(puVar5);
    DAT_2000_d3a2 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d3a0 = (uint16_t)(pcVar6);
    pixels_48.seg = (psVar3->aptr).seg;
    pixels_48.ofs = (&psVar3->aptr)->ofs;
    puVar5 = (uint8_t *)ovr_stshRleType2(pixels_48,8,117,226,194,-8,-117);
    pcVar6 = ovr_stshStoreFile(puVar5);
    DAT_2000_d39e = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d39c = (uint16_t)(pcVar6);
    uVar16 = ovr_stshWrite(psVar3->cmap,0x300);
    DAT_2000_d386 = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d384 = (uint16_t)uVar16;
    ovr_stgFreeTmp(psVar12);
    fVar18.seg = DAT_2000_d386;
    fVar18.ofs = DAT_2000_d384;
  }
  else {
    fVar7 = ovr_stshAllocStub();
    DAT_2000_cc87 = fVar7.seg;
    DAT_2000_cc85 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d3a6 = fVar7.seg;
    DAT_2000_d3a4 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d3a2 = fVar7.seg;
    DAT_2000_d3a0 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d39e = fVar7.seg;
    DAT_2000_d39c = (uint16_t)(fVar7.ofs);
    fVar18 = ovr_stshAllocStub();
  }
  DAT_2000_d386 = fVar18.seg;
  DAT_2000_d384 = fVar18.ofs;
  if (grab) {
    psVar12 = ovr_grabLbm(543,0,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_20.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_20.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_20,8,5,16,10);
    LbxButton2 = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs))));
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(139,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_21.seg = (psVar3->aptr).seg;
    src_21.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_21,16,121,57,131);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d36e = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d36c = (uint16_t)(pcVar6);
    src_22.seg = (psVar3->aptr).seg;
    src_22.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_22,16,134,57,144);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d372 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d370 = (uint16_t)(pcVar6);
    src_23.seg = (psVar3->aptr).seg;
    src_23.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_23,234,121,300,131);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d376 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d374 = (uint16_t)(pcVar6);
    src_24.seg = (psVar3->aptr).seg;
    src_24.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_24,234,134,300,144);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d37a = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d378 = (uint16_t)(pcVar6);
    src_25.seg = (psVar3->aptr).seg;
    src_25.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_25,153,121,230,131);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d37e = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d37c = (uint16_t)(pcVar6);
    src_26.seg = (psVar3->aptr).seg;
    src_26.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_26,153,134,230,144);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d382 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d380 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar19.seg = DAT_2000_d382;
    fVar19.ofs = (uint16_t)DAT_2000_d380;
  }
  else {
    LbxButton2 = ovr_stshAllocStub();
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d36e = fVar7.seg;
    DAT_2000_d36c = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d372 = fVar7.seg;
    DAT_2000_d370 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d376 = fVar7.seg;
    DAT_2000_d374 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d37a = fVar7.seg;
    DAT_2000_d378 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d37e = fVar7.seg;
    DAT_2000_d37c = (uint16_t)(fVar7.ofs);
    fVar19 = ovr_stshAllocStub();
  }
  DAT_2000_d382 = fVar19.seg;
  DAT_2000_d380 = (uint16_t)(fVar19.ofs);
  if (grab) {
    psVar12 = ovr_grabLbm(179,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_27.seg = (psVar3->aptr).seg;
    src_27.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_27,94,47,108,89);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_cab7 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_cab5 = (uint16_t)(pcVar6);
    src_28.seg = (psVar3->aptr).seg;
    src_28.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_28,114,47,128,89);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_cab3 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_cab1 = (uint16_t)(pcVar6);
    src_29.seg = (psVar3->aptr).seg;
    src_29.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_29,223,8,237,50);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_caaf = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_caad = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar20.seg = DAT_2000_caaf;
    fVar20.ofs = (uint16_t)DAT_2000_caad;
  }
  else {
    fVar7 = ovr_stshAllocStub();
    DAT_2000_cab7 = fVar7.seg;
    DAT_2000_cab5 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_cab3 = fVar7.seg;
    DAT_2000_cab1 = (uint16_t)(fVar7.ofs);
    fVar20 = ovr_stshAllocStub();
  }
  DAT_2000_caaf = fVar20.seg;
  DAT_2000_caad = (uint16_t)(fVar20.ofs);
  if (grab) {
    psVar12 = ovr_grabLbm(158,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    uVar16 = ovr_stshWrite(psVar3->cmap,0x300);
    DAT_2000_d3d6 = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d3d4 = (uint16_t)uVar16;
    src_30.seg = (psVar3->aptr).seg;
    src_30.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_30,0,0,319,80);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d3ee = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d3ec = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(159,0,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_31.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_31.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_31,0,0,219,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d3fe = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d3fc = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(159,220,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_32.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_32.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_32,0,0,219,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d40e = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d40c = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(160,0,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_33.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_33.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_33,0,0,279,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d41e = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d41c = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(160,280,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_34.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_34.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_34,0,0,279,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d42e = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d42c = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(161,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    uVar16 = ovr_stshWrite(psVar3->cmap,0x300);
    DAT_2000_d3d2 = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d3d0 = (uint16_t)uVar16;
    src_35.seg = (psVar3->aptr).seg;
    src_35.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_35,0,144,319,199);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d3ea = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d3e8 = (uint16_t)(pcVar6);
    src_36.seg = (psVar3->aptr).seg;
    src_36.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_36,0,0,47,10);
    far_t_2000_d3e4 = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs))));
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(412,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    uVar16 = ovr_stshWrite(psVar3->cmap,0x300);
    DAT_2000_d3da = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d3d8 = (uint16_t)uVar16;
    src_37.seg = (psVar3->aptr).seg;
    src_37.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_37,0,0,319,80);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d3f2 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d3f0 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(414,0,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_38.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_38.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_38,0,0,219,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d402 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d400 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(414,220,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_39.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_39.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_39,0,0,219,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d412 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d410 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(413,0,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_40.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_40.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_40,0,0,279,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d422 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d420 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(413,280,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_41.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_41.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_41,0,0,279,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d432 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d430 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar21.seg = DAT_2000_d432;
    fVar21.ofs = (uint16_t)DAT_2000_d430;
  }
  else {
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d3d6 = fVar7.seg;
    DAT_2000_d3d4 = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d3ee = fVar7.seg;
    DAT_2000_d3ec = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d3fe = fVar7.seg;
    DAT_2000_d3fc = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d40e = fVar7.seg;
    DAT_2000_d40c = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d41e = fVar7.seg;
    DAT_2000_d41c = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d42e = fVar7.seg;
    DAT_2000_d42c = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d3d2 = fVar7.seg;
    DAT_2000_d3d0 = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d3ea = fVar7.seg;
    DAT_2000_d3e8 = (uint16_t)(fVar7.ofs);
    far_t_2000_d3e4 = ovr_stshAllocStub();
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d3da = fVar7.seg;
    DAT_2000_d3d8 = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d3f2 = fVar7.seg;
    DAT_2000_d3f0 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d402 = fVar7.seg;
    DAT_2000_d400 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d412 = fVar7.seg;
    DAT_2000_d410 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d422 = fVar7.seg;
    DAT_2000_d420 = (uint16_t)(fVar7.ofs);
    fVar21 = ovr_stshAllocStub();
  }
  DAT_2000_d432 = fVar21.seg;
  DAT_2000_d430 = (uint16_t)(fVar21.ofs);
  if (grab) {
    psVar12 = ovr_grabLbm(422,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    uVar16 = ovr_stshWrite(psVar3->cmap,0x300);
    DAT_2000_d3de = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d3dc = (uint16_t)uVar16;
    src_42.seg = (psVar3->aptr).seg;
    src_42.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_42,0,0,319,113);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d3f6 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d3f4 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(421,0,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_43.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_43.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_43,0,0,219,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d406 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d404 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(421,220,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_44.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_44.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_44,0,0,219,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d416 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d414 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(420,0,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_45.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_45.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_45,0,0,279,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d426 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d424 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(420,280,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_46.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_46.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_46,0,0,279,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d436 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d434 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar22.seg = DAT_2000_d436;
    fVar22.ofs = (uint16_t)DAT_2000_d434;
  }
  else {
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d3de = fVar7.seg;
    DAT_2000_d3dc = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d3f6 = fVar7.seg;
    DAT_2000_d3f4 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d406 = fVar7.seg;
    DAT_2000_d404 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d416 = fVar7.seg;
    DAT_2000_d414 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d426 = fVar7.seg;
    DAT_2000_d424 = (uint16_t)(fVar7.ofs);
    fVar22 = ovr_stshAllocStub();
  }
  DAT_2000_d436 = fVar22.seg;
  DAT_2000_d434 = (uint16_t)(fVar22.ofs);
  if (grab) {
    psVar12 = ovr_grabLbm(437,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    uVar16 = ovr_stshWrite(psVar3->cmap,0x300);
    DAT_2000_d3e2 = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d3e0 = (uint16_t)uVar16;
    src_47.seg = (psVar3->aptr).seg;
    src_47.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_47,0,0,319,113);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d3fa = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d3f8 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(438,0,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_48.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_48.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_48,0,0,219,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d40a = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d408 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(438,220,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_49.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_49.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_49,0,0,219,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d41a = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d418 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(439,0,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_50.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_50.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_50,0,0,279,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d42a = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d428 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(439,280,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    src_51.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_51.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_51,0,0,279,143);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d43a = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d438 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar23.seg = DAT_2000_d43a;
    fVar23.ofs = (uint16_t)DAT_2000_d438;
  }
  else {
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d3e2 = fVar7.seg;
    DAT_2000_d3e0 = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d3fa = fVar7.seg;
    DAT_2000_d3f8 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d40a = fVar7.seg;
    DAT_2000_d408 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d41a = fVar7.seg;
    DAT_2000_d418 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d42a = fVar7.seg;
    DAT_2000_d428 = (uint16_t)(fVar7.ofs);
    fVar23 = ovr_stshAllocStub();
  }
  DAT_2000_d43a = fVar23.seg;
  DAT_2000_d438 = (uint16_t)(fVar23.ofs);
  if (grab) {
    psVar12 = ovr_grabLbm(305,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_52.seg = (psVar3->aptr).seg;
    src_52.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_52,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d04a = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d048 = (uint16_t)(pcVar6);
    uVar16 = ovr_stshWrite(psVar3->cmap + 0x1e0,0x90);
    DAT_2000_d026 = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d024 = (uint16_t)uVar16;
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(305,320,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_53.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_53.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_53,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d04e = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d04c = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(328,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_54.seg = (psVar3->aptr).seg;
    src_54.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_54,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d052 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d050 = (uint16_t)(pcVar6);
    uVar16 = ovr_stshWrite(psVar3->cmap + 0x1e0,0x90);
    DAT_2000_d02a = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d028 = (uint16_t)uVar16;
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(328,320,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_55.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_55.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_55,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d056 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d054 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(331,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_56.seg = (psVar3->aptr).seg;
    src_56.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_56,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d05a = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d058 = (uint16_t)(pcVar6);
    uVar16 = ovr_stshWrite(psVar3->cmap + 0x1e0,0x90);
    DAT_2000_d02e = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d02c = (uint16_t)uVar16;
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(331,320,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_57.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_57.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_57,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d05e = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d05c = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(307,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_58.seg = (psVar3->aptr).seg;
    src_58.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_58,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d062 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d060 = (uint16_t)(pcVar6);
    uVar16 = ovr_stshWrite(psVar3->cmap + 0x1e0,0x90);
    DAT_2000_d032 = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d030 = (uint16_t)uVar16;
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(307,320,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_59.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_59.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_59,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d066 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d064 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(329,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_60.seg = (psVar3->aptr).seg;
    src_60.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_60,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d06a = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d068 = (uint16_t)(pcVar6);
    uVar16 = ovr_stshWrite(psVar3->cmap + 0x1e0,0x90);
    DAT_2000_d036 = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d034 = (uint16_t)uVar16;
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(329,320,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_61.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_61.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_61,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d06e = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d06c = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(332,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_62.seg = (psVar3->aptr).seg;
    src_62.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_62,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d072 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d070 = (uint16_t)(pcVar6);
    uVar16 = ovr_stshWrite(psVar3->cmap + 0x1e0,0x90);
    DAT_2000_d03a = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d038 = (uint16_t)uVar16;
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(332,320,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_63.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_63.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_63,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d076 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d074 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(306,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_64.seg = (psVar3->aptr).seg;
    src_64.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_64,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d07a = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d078 = (uint16_t)(pcVar6);
    uVar16 = ovr_stshWrite(psVar3->cmap + 0x1e0,0x90);
    DAT_2000_d03e = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d03c = (uint16_t)uVar16;
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(306,320,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_65.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_65.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_65,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d07e = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d07c = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(330,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_66.seg = (psVar3->aptr).seg;
    src_66.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_66,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d082 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d080 = (uint16_t)(pcVar6);
    uVar16 = ovr_stshWrite(psVar3->cmap + 0x1e0,0x90);
    DAT_2000_d042 = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d040 = (uint16_t)uVar16;
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(330,320,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_67.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_67.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_67,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d086 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d084 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(333,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_68.seg = (psVar3->aptr).seg;
    src_68.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_68,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d08a = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d088 = (uint16_t)(pcVar6);
    uVar16 = ovr_stshWrite(psVar3->cmap + 0x1e0,0x90);
    DAT_2000_d046 = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d044 = (uint16_t)uVar16;
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(333,320,0);
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    ovr_stshUniqueColorsRemap(psVar12);
    src_69.seg = (((stg_tmp_t *)psVar12)->aptr).seg;
    src_69.ofs = (&((stg_tmp_t *)psVar12)->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_69,0,0,319,59);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d08e = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d08c = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar24.seg = DAT_2000_d08e;
    fVar24.ofs = (uint16_t)DAT_2000_d08c;
  }
  else {
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d04a = fVar7.seg;
    DAT_2000_d048 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d026 = fVar7.seg;
    DAT_2000_d024 = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d04e = fVar7.seg;
    DAT_2000_d04c = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d052 = fVar7.seg;
    DAT_2000_d050 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d02a = fVar7.seg;
    DAT_2000_d028 = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d056 = fVar7.seg;
    DAT_2000_d054 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d05a = fVar7.seg;
    DAT_2000_d058 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d02e = fVar7.seg;
    DAT_2000_d02c = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d05e = fVar7.seg;
    DAT_2000_d05c = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d062 = fVar7.seg;
    DAT_2000_d060 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d032 = fVar7.seg;
    DAT_2000_d030 = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d066 = fVar7.seg;
    DAT_2000_d064 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d06a = fVar7.seg;
    DAT_2000_d068 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d036 = fVar7.seg;
    DAT_2000_d034 = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d06e = fVar7.seg;
    DAT_2000_d06c = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d072 = fVar7.seg;
    DAT_2000_d070 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d03a = fVar7.seg;
    DAT_2000_d038 = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d076 = fVar7.seg;
    DAT_2000_d074 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d07a = fVar7.seg;
    DAT_2000_d078 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d03e = fVar7.seg;
    DAT_2000_d03c = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d07e = fVar7.seg;
    DAT_2000_d07c = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d082 = fVar7.seg;
    DAT_2000_d080 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d042 = fVar7.seg;
    DAT_2000_d040 = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d086 = fVar7.seg;
    DAT_2000_d084 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d08a = fVar7.seg;
    DAT_2000_d088 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d046 = fVar7.seg;
    DAT_2000_d044 = fVar7.ofs;
    fVar24 = ovr_stshAllocStub();
  }
  DAT_2000_d08e = fVar24.seg;
  DAT_2000_d08c = (uint16_t)(fVar24.ofs);
  ovr_stshInitAudioAssets();
  ovr_stshLoadAudioDrivers(grab);
  ovr_stshInitSprites(grab);
  stshInitTxtFiles(grab);
  if (grab) {
    fVar7 = ovr_stshStoreFile_2((char *)StshNames[0x19f],0);
  }
  else {
    fVar7 = ovr_stshAllocStub();
  }
  DAT_2000_d486 = fVar7.seg;
  DAT_2000_d484 = fVar7.ofs;
  if (grab) {
    fVar7 = ovr_stshStoreFile_2((char *)"bolt12.fli",0);
  }
  else {
    fVar7 = ovr_stshAllocStub();
  }
  DAT_2000_d482 = fVar7.seg;
  DAT_2000_d480 = fVar7.ofs;
  if (grab) {
    psVar12 = ovr_grabLbm(417,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    uVar16 = ovr_stshWrite(psVar3->cmap,0x300);
    DAT_2000_d45a = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d458 = (uint16_t)uVar16;
    src_70.seg = (psVar3->aptr).seg;
    src_70.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_70,0,0,319,199);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d476 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d474 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar25.seg = DAT_2000_d476;
    fVar25.ofs = (uint16_t)DAT_2000_d474;
  }
  else {
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d45a = fVar7.seg;
    DAT_2000_d458 = fVar7.ofs;
    fVar25 = ovr_stshAllocStub();
  }
  DAT_2000_d476 = fVar25.seg;
  DAT_2000_d474 = (uint16_t)(fVar25.ofs);
  if (grab) {
    psVar12 = ovr_grabLbm(542,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    uVar16 = ovr_stshWrite(psVar3->cmap,0x300);
    DAT_2000_d43e = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d43c = (uint16_t)uVar16;
    src_71.seg = (psVar3->aptr).seg;
    src_71.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_71,0,0,319,144);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d45e = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d45c = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar26.seg = DAT_2000_d45e;
    fVar26.ofs = (uint16_t)DAT_2000_d45c;
  }
  else {
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d43e = fVar7.seg;
    DAT_2000_d43c = fVar7.ofs;
    fVar26 = ovr_stshAllocStub();
  }
  DAT_2000_d45e = fVar26.seg;
  DAT_2000_d45c = (uint16_t)(fVar26.ofs);
  if (grab) {
    psVar12 = ovr_grabLbm(539,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    uVar16 = ovr_stshWrite(psVar3->cmap,0x300);
    DAT_2000_d442 = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d440 = (uint16_t)uVar16;
    src_72.seg = (psVar3->aptr).seg;
    src_72.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_72,0,0,319,199);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d462 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d460 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(540,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    uVar16 = ovr_stshWrite(psVar3->cmap,0x300);
    DAT_2000_d446 = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d444 = (uint16_t)uVar16;
    src_73.seg = (psVar3->aptr).seg;
    src_73.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_73,0,0,319,199);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d466 = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d464 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    psVar12 = ovr_grabLbm(541,0,0);
    psVar3 = (stg_tmp_t *)psVar12;
    (*(uint16_t *)((uint8_t *)&(uStack_a) + 2)) = (undefined2)((ulong)psVar12 >> 0x10);
    uVar16 = ovr_stshWrite(psVar3->cmap,0x300);
    DAT_2000_d44a = (uint16_t)(uVar16 >> 0x10);
    DAT_2000_d448 = (uint16_t)uVar16;
    src_74.seg = (psVar3->aptr).seg;
    src_74.ofs = (&psVar3->aptr)->ofs;
    fVar7 = ovr_stshRleCut(src_74,0,0,319,199);
    pcVar6 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar7.seg, fVar7.ofs));
    DAT_2000_d46a = (uint16_t)((ulong)pcVar6 >> 0x10);
    DAT_2000_d468 = (uint16_t)(pcVar6);
    ovr_stgFreeTmp(psVar12);
    fVar27.seg = DAT_2000_d46a;
    fVar27.ofs = (uint16_t)DAT_2000_d468;
  }
  else {
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d442 = fVar7.seg;
    DAT_2000_d440 = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d462 = fVar7.seg;
    DAT_2000_d460 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d446 = fVar7.seg;
    DAT_2000_d444 = fVar7.ofs;
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d466 = fVar7.seg;
    DAT_2000_d464 = (uint16_t)(fVar7.ofs);
    fVar7 = ovr_stshAllocStub();
    DAT_2000_d44a = fVar7.seg;
    DAT_2000_d448 = fVar7.ofs;
    fVar27 = ovr_stshAllocStub();
  }
  DAT_2000_d46a = fVar27.seg;
  DAT_2000_d468 = (uint16_t)(fVar27.ofs);
  if (grab) {
    fVar7 = ovr_stshStoreFile_2((char *)"save.999",0);
  }
  else {
    fVar7 = ovr_stshAllocStub();
  }
  DAT_2000_d1b2 = fVar7.seg;
  DAT_2000_d1b0 = fVar7.ofs;
  return;
}



/* 81b9:3e84 */

void __cdecl16far grabBldLbm2(int16_t index,int16_t normal,int16_t ruin)

{
  stg_tmp_t *psVar1;
  stg_tmp_t *psVar2;
  uint8_t *puVar3;
  cte_t *pcVar4;
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
  undefined2 uStack_4;
  
  psVar2 = ovr_grabLbmTR(normal);
  psVar1 = (stg_tmp_t *)psVar2;
  uStack_4 = (undefined2)((ulong)psVar2 >> 0x10);
  pixels.seg = (psVar1->aptr).seg;
  pixels.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels,0,130,99,194,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxNormal[0x19].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxNormal + 0x19) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_00.seg = (psVar1->aptr).seg;
  pixels_00.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_00,100,130,199,194,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxNormal[0x16].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxNormal + 0x16) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_01.seg = (psVar1->aptr).seg;
  pixels_01.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_01,200,130,299,194,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxNormal[0x13].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxNormal + 0x13) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_02.seg = (psVar1->aptr).seg;
  pixels_02.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_02,0,65,99,129,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxNormal[0x10].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxNormal + 0x10) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_03.seg = (psVar1->aptr).seg;
  pixels_03.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_03,100,65,199,129,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxNormal[0xd].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxNormal + 0xd) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_04.seg = (psVar1->aptr).seg;
  pixels_04.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_04,200,65,299,129,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxNormal[10].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxNormal + 10) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_05.seg = (psVar1->aptr).seg;
  pixels_05.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_05,0,0,99,64,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxNormal[7].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxNormal + 7) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_06.seg = (psVar1->aptr).seg;
  pixels_06.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_06,100,0,199,64,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxNormal[4].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxNormal + 4) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_07.seg = (psVar1->aptr).seg;
  pixels_07.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_07,200,0,299,64,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxNormal[1].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  ovr_stgFreeTmp(psVar2);
  psVar2 = ovr_grabLbmTR(ruin);
  psVar1 = (stg_tmp_t *)psVar2;
  uStack_4 = (undefined2)((ulong)psVar2 >> 0x10);
  pixels_08.seg = (psVar1->aptr).seg;
  pixels_08.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_08,0,130,99,194,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxRuin[0x19].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxRuin + 0x19) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_09.seg = (psVar1->aptr).seg;
  pixels_09.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_09,100,130,199,194,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxRuin[0x16].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxRuin + 0x16) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_10.seg = (psVar1->aptr).seg;
  pixels_10.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_10,200,130,299,194,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxRuin[0x13].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxRuin + 0x13) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_11.seg = (psVar1->aptr).seg;
  pixels_11.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_11,0,65,99,129,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxRuin[0x10].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxRuin + 0x10) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_12.seg = (psVar1->aptr).seg;
  pixels_12.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_12,100,65,199,129,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxRuin[0xd].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxRuin + 0xd) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_13.seg = (psVar1->aptr).seg;
  pixels_13.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_13,200,65,299,129,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxRuin[10].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxRuin + 10) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_14.seg = (psVar1->aptr).seg;
  pixels_14.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_14,0,0,99,64,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxRuin[7].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxRuin + 7) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_15.seg = (psVar1->aptr).seg;
  pixels_15.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_15,100,0,199,64,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxRuin[4].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxRuin + 4) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  pixels_16.seg = (psVar1->aptr).seg;
  pixels_16.ofs = (&psVar1->aptr)->ofs;
  puVar3 = (uint8_t *)ovr_stshRleType2(pixels_16,200,0,299,64,26,-1);
  pcVar4 = ovr_stshStoreFile(puVar3);
  *(undefined2 *)((int)&BldGfxRuin[1].seg + index * 0xc) = (int)((ulong)pcVar4 >> 0x10);
  ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar4;
  ovr_stgFreeTmp(psVar2);
  return;
}



/* 81b9:43f1 */

void __cdecl16far stshAllocBldStubs2(int16_t index)

{
  far_t fVar1;
  
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxNormal[0x19].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxNormal + 0x19) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxNormal[0x16].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxNormal + 0x16) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxNormal[0x13].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxNormal + 0x13) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxNormal[0x10].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxNormal + 0x10) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxNormal[0xd].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxNormal + 0xd) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxNormal[10].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxNormal + 10) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxNormal[7].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxNormal + 7) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxNormal[4].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxNormal + 4) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxNormal[1].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxRuin[0x19].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxRuin + 0x19) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxRuin[0x16].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxRuin + 0x16) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxRuin[0x13].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxRuin + 0x13) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxRuin[0x10].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxRuin + 0x10) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxRuin[0xd].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxRuin + 0xd) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxRuin[10].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxRuin + 10) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxRuin[7].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxRuin + 7) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxRuin[4].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxRuin + 4) + index * 3)->ofs = fVar1.ofs;
  fVar1 = ovr_stshAllocStub();
  *(uint16_t *)((int)&BldGfxRuin[1].seg + index * 0xc) = fVar1.seg;
  ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs = fVar1.ofs;
  return;
}


