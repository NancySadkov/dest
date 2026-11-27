/*
 * ovc44_strong_dat.c - recovered from STRONG.EXE
 * memory block: OVC44_strong_dat
 * range: 6ffe:0000 - 6ffe:7ecf
 * functions: 5
 */
#include "recovered.h"


/* 6ffe:0000 */

far_t __cdecl16far stshAllocStub(void)
{
  far_t old;
  uint32_t fresh;

  old.ofs = StshCtPtrCopy.ofs;
  old.seg = StshCtPtrCopy.seg;
  if (StshCount < 0xd93) {
    StshCount = StshCount + 1;
    fresh = (uint32_t)ovr_mkp((uint32_t *)(old.ofs + 0x15),old.seg,old.ofs);
    StshCtPtrCopy.seg = (uint16_t)(fresh >> 16);
    StshCtPtrCopy.ofs = (uint16_t)fresh;
    *(uint16_t *)(old.ofs + 0x13) = 0;
    *(uint16_t *)(old.ofs + 0x11) = 0;
    *(uint16_t *)(old.ofs + 0xb) = 0;
    *(uint16_t *)(old.ofs + 9) = 0;
    *(uint16_t *)(old.ofs + 0xf) = 0;
    *(uint16_t *)(old.ofs + 0xd) = 0;
    return old;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x24);
}




/* 6ffe:009b */

/* Fill one row of BldGfxNormal with ten freshly allocated asset stubs.  The image is fully
   unrolled: every block does `push cs; call 0` (the allocator at this segment's offset 0) and stores
   the returned far pointer at 0060:4dd0 + index*0xc + i*4, segment half first.  0xc bytes per index
   is three far_t slots, so the source indexes BldGfxNormal[3*index + i]; rows overlap when index is
   nonzero, exactly as the image's arithmetic does. */
void __cdecl16far stshTR_S_stubify0(int index)

{
  uint8_t i;
  uint32_t res;

  for (i = 0; i < 10; i++) {
    res = func_0x0007ffe0(0x6ffe);
    BldGfxNormal[index * 3 + i].seg = (uint16_t)(res >> 0x10);
    BldGfxNormal[index * 3 + i].ofs = (uint16_t)res;
  }
  return;
}



/* 6ffe:01c5 */

/* The same row for BldGfxRuin, nine slots in the image (0060:4230 + index*0xc + i*4, i = 0..8),
   preceded by the BldGfxNormal pass. */
void __cdecl16far stshStubifyBld(uint16_t index)

{
  uint8_t i;
  uint32_t res;

  stshTR_S_stubify0(index);
  for (i = 0; i < 9; i++) {
    res = func_0x0007ffe0(0x6ffe);
    BldGfxRuin[index * 3 + i].seg = (uint16_t)(res >> 0x10);
    BldGfxRuin[index * 3 + i].ofs = (uint16_t)res;
  }
  return;
}




/* 6ffe:02f7 */
void __cdecl16far getcache(bool updateFile)

{
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
  far_t dst;
  far_t pixels;
  far_t buf;
  DW sz;
  far_t pixels_00;
  far_t pixels_01;
  far_t far *pfVar1;
  cte_t *stored;
  int iVar3;
  int iVar4;
  stg_tmp_t *lbmTmp;
  long *plVar6;
  uint16_t in_DX;
  uint16_t rleSeg;
  uint16_t segArg;
  uint16_t rleSeg2;
  uint16_t uVar10;
  uint16_t *puVar11;
  uint16_t unaff_SI;
  long *unaff_DI;
  int iVar12;
  uint16_t rleSeg3;
  undefined1 resId;
  bool bVar15;
  uint32_t farPtr;
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
  far_t pixels_50;
  far_t pixels_51;
  far_t pixels_52;
  far_t pixels_53;
  far_t pixels_54;
  far_t pixels_55;
  far_t pixels_56;
  far_t pixels_57;
  far_t pixels_58;
  far_t pixels_59;
  far_t pixels_60;
  far_t pixels_61;
  far_t pixels_62;
  far_t pixels_63;
  far_t pixels_64;
  far_t pixels_65;
  far_t pixels_66;
  far_t pixels_67;
  far_t pixels_68;
  far_t pixels_69;
  far_t pixels_70;
  far_t pixels_71;
  far_t pixels_72;
  far_t pixels_73;
  far_t pixels_74;
  far_t pixels_75;
  far_t pixels_76;
  far_t pixels_77;
  far_t pixels_78;
  far_t pixels_79;
  far_t pixels_80;
  far_t pixels_81;
  far_t pixels_82;
  far_t pixels_83;
  far_t pixels_84;
  far_t pixels_85;
  far_t pixels_86;
  far_t pixels_87;
  far_t pixels_88;
  far_t pixels_89;
  far_t pixels_90;
  far_t pixels_91;
  far_t pixels_92;
  far_t pixels_93;
  far_t pixels_94;
  far_t pixels_95;
  far_t pixels_96;
  far_t pixels_97;
  far_t pixels_98;
  far_t pixels_99;
  far_t pixels_x00100;
  far_t pixels_x00101;
  far_t pixels_x00102;
  far_t pixels_x00103;
  far_t pixels_x00104;
  far_t pixels_x00105;
  far_t pixels_x00106;
  far_t pixels_x00107;
  far_t pixels_x00108;
  far_t pixels_x00109;
  far_t pixels_x00110;
  far_t pixels_x00111;
  far_t pixels_x00112;
  far_t pixels_x00113;
  far_t pixels_x00114;
  far_t pixels_x00115;
  far_t pixels_x00116;
  far_t pixels_x00117;
  far_t pixels_x00118;
  far_t pixels_x00119;
  far_t pixels_x00120;
  far_t pixels_x00121;
  far_t pixels_x00122;
  far_t pixels_x00123;
  far_t pixels_x00124;
  far_t pixels_x00125;
  far_t pixels_x00126;
  far_t pixels_x00127;
  far_t pixels_x00128;
  far_t pixels_x00129;
  far_t pixels_x00130;
  far_t pixels_x00131;
  far_t pixels_x00132;
  far_t pixels_x00133;
  far_t pixels_x00134;
  far_t pixels_x00135;
  far_t pixels_x00136;
  far_t pixels_x00137;
  far_t pixels_x00138;
  far_t pixels_x00139;
  far_t pixels_x00140;
  far_t pixels_x00141;
  far_t pixels_x00142;
  far_t pixels_x00143;
  far_t pixels_x00144;
  far_t pixels_x00145;
  far_t pixels_x00146;
  far_t pixels_x00147;
  far_t pixels_x00148;
  far_t pixels_x00149;
  far_t pixels_x00150;
  far_t pixels_x00151;
  far_t pixels_x00152;
  far_t pixels_x00153;
  far_t pixels_x00154;
  far_t pixels_x00155;
  far_t pixels_x00156;
  far_t pixels_x00157;
  far_t pixels_x00158;
  far_t pixels_x00159;
  far_t pixels_x00160;
  far_t pixels_x00161;
  far_t pixels_x00162;
  far_t pixels_x00163;
  far_t pixels_x00164;
  far_t pixels_x00165;
  far_t pixels_x00166;
  far_t pixels_x00167;
  far_t pixels_x00168;
  far_t pixels_x00169;
  far_t pixels_x00170;
  far_t pixels_x00171;
  far_t pixels_x00172;
  far_t pixels_x00173;
  far_t pixels_x00174;
  far_t pixels_x00175;
  far_t pixels_x00176;
  far_t pixels_x00177;
  far_t pixels_x00178;
  far_t pixels_x00179;
  far_t pixels_x00180;
  far_t pixels_x00181;
  far_t pixels_x00182;
  far_t pixels_x00183;
  far_t pixels_x00184;
  far_t pixels_x00185;
  far_t pixels_x00186;
  far_t pixels_x00187;
  far_t pixels_x00188;
  far_t pixels_x00189;
  far_t pixels_x00190;
  far_t pixels_x00191;
  far_t pixels_x00192;
  far_t pixels_x00193;
  far_t pixels_x00194;
  far_t pixels_x00195;
  far_t pixels_x00196;
  far_t pixels_x00197;
  far_t pixels_x00198;
  far_t pixels_x00199;
  far_t pixels_x00200;
  uint32_t tg;
  uint16_t jj;
  uint16_t ii;
  uint16_t cc;
  
  ovr_animInitSeqs();
  StshCtPtrCopy.ofs = (uint16_t)ovr_stshAlloc(0x11d0f);
  StshCount = 0;
  StshCtPtrCopy.seg = in_DX;
  StshCtPtr.ofs = StshCtPtrCopy.ofs;
  StshCtPtr.seg = in_DX;
  ovr_allocSprSeqs();
  ovr_initStshTables();
  _fsetmem(BldGfxNormal,0xba0,0);
  _fsetmem(BldGfxRuin,0xba0,0);
  _fsetmem(BldFlags,0x2e8,0);
  StshCtOfs.hi = 0;
  StshCtOfs.lo = 0;
  if (updateFile == false) {
    StshFile = ovr_open_wait_unlock_and_disk((char *)"strong.dat",0x10);
    read(StshFile,(void *)&__C0_ASM_CopyRight,(uint)unaff_DI);
    lseek(StshFile,(ulong)StshCtOfs.hi,(int)unaff_DI);
    dst.seg = StshCtPtr.seg;
    dst.ofs = StshCtPtr.ofs;
    {
  DW nbytes;   /* hand fix: DW is a {lo,hi} struct, a scalar cast is invalid C */
  nbytes.lo = 0x1d0f;
  nbytes.hi = 1;
  ovr_stshReadFile(StshFile,dst,nbytes,0xf);
}
    resId = 0;
    close(StshFile);
    MiceCursors[0] = far_from_u32((uint32_t)(func_0x0007ffe0(0)));
    MiceCursors[1] = far_from_u32((uint32_t)(func_0x0007ffe0(0)));
    MiceCursors[2] = far_from_u32((uint32_t)(func_0x0007ffe0(0)));
    farPtr = func_0x0007ffe0(0);
    MiceCursors[3].seg = (uint16_t)((ulong)farPtr >> 0x10);
  }
  else {
    StshFile = ovr_creat_wait_unlock_and_disk((char *)"strong.dat",0x10);
    rleSeg = 0x2410;
    write(StshFile,&StshFileSizeVar,4);
    bVar15 = 0xfffb < StshCtOfs.lo;
    StshCtOfs.lo = StshCtOfs.lo + 4;
    StshCtOfs.hi = StshCtOfs.hi + bVar15;
    lbmTmp = ovr_grabLbm(129,0,0,0,0);
    src.seg = 0;
    src.ofs = (lbmTmp->aptr).seg;
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = rleSeg;
    pfVar1 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src,0,10,15,(int16_t)unaff_DI,10,0xf,0);
    MiceCursors[0].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)), &stshSegTmp);
    src_00.seg = 0x4d;
    src_00.ofs = (lbmTmp->aptr).seg;
    MiceCursors[0].seg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    pfVar1 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_00,11,93,27,(int16_t)unaff_DI,0x5d,0x1b,0);
    MiceCursors[1].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)), &stshSegTmp);
    src_01.seg = 0x60;
    src_01.ofs = (lbmTmp->aptr).seg;
    MiceCursors[1].seg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    pfVar1 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_01,55,109,62,(int16_t)unaff_DI,0x6d,0x3e,0);
    MiceCursors[2].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)), &stshSegTmp);
    src_02.seg = 0x9f;
    src_02.ofs = (lbmTmp->aptr).seg;
    MiceCursors[2].seg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    pfVar1 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_02,22,171,32,(int16_t)unaff_DI,0xab,0x20,0);
    MiceCursors[3].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)), &stshSegTmp);
    MiceCursors[3].seg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg);
    resId = 0x4c;
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(1);
    asm { mov word ptr [(tg) + 2], dx };
    farPtr = CONCAT22((*(uint16_t *)((uint8_t *)&(tg) + 2)),MiceCursors[3].ofs);
  }
  cc = 0;
  jj = 1;
  while( true ) {
    rleSeg = (uint16_t)((ulong)farPtr >> 0x10);
    MiceCursors[3].ofs = (uint16_t)farPtr;
    if (0x2d < (int)jj) break;
    ii = 1;
    while( true ) {
      segArg = (uint16_t)((ulong)farPtr >> 0x10);
      MiceCursors[3].ofs = (uint16_t)farPtr;
      if (0x9d < (int)ii) break;
      if (updateFile == false) {
        farPtr = func_0x0007ffe0(resId);
        segArg = (uint16_t)((ulong)farPtr >> 0x10);
        *(uint16_t *)((int)&LbmBigcomp50x42.seg + cc * 4) = segArg;
        ((far_t far *)&LbmBigcomp50x42 + cc)->ofs = (uint16_t)farPtr;
      }
      else {
        src_03.seg = ii;
        src_03.ofs = (((stg_tmp_t *)tg)->aptr).seg;
        pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_03,jj,ii + 0x32,jj + 0x2a,(int16_t)unaff_DI,(char)(ii + 0x32),(char)(jj + 0x2a),0);
        resId = 0x4c;
        stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
        *(uint16_t *)((int)&LbmBigcomp50x42.seg + cc * 4) = segArg;
        ((far_t far *)&LbmBigcomp50x42 + cc)->ofs = (uint16_t)stored;
      }
      farPtr = CONCAT22(segArg,MiceCursors[3].ofs);
      cc = cc + 1;
      ii = ii + 0x34;
    }
    jj = jj + 0x2c;
  }
  if (updateFile != false) {
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
    resId = 0xcb;
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbm(508,0,0,0,0);
    farPtr = CONCAT22(rleSeg,MiceCursors[3].ofs);
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = rleSeg;
  }
  for (cc = 0; MiceCursors[3].ofs = (uint16_t)farPtr, (int)cc < 0xc; cc = cc + 1) {
    if (updateFile == false) {
      farPtr = func_0x0007ffe0(resId);
      segArg = (uint16_t)((ulong)farPtr >> 0x10);
      *(uint16_t *)((int)&timeOfDayGfx[0].seg + cc * 4) = segArg;
      ((far_t far *)timeOfDayGfx + cc)->ofs = (uint16_t)farPtr;
    }
    else {
      iVar12 = cc * 0x17 + 0x1b;
      segArg = (uint16_t)((ulong)((long)(int)cc * 0x17) >> 0x10);
      src_04.seg = (int)((long)(int)cc * 0x17) + 6;
      src_04.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_04,21,iVar12,62,(int16_t)unaff_DI,(char)iVar12,0x3e,0);
      resId = 0x4c;
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&timeOfDayGfx[0].seg + cc * 4) = segArg;
      ((far_t far *)timeOfDayGfx + cc)->ofs = (uint16_t)stored;
    }
    farPtr = CONCAT22(segArg,MiceCursors[3].ofs);
  }
  cc = 0;
  while( true ) {
    rleSeg = (uint16_t)((ulong)farPtr >> 0x10);
    MiceCursors[3].ofs = (uint16_t)farPtr;
    if (5 < (int)cc) break;
    if (updateFile == false) {
      farPtr = func_0x0007ffe0(resId);
      segArg = (uint16_t)((ulong)farPtr >> 0x10);
      ((uint16_t *)&blitFrameSeg)[cc * 2] = segArg;
      ((uint16_t *)&blitFrameOfs)[cc * 2] = (int)farPtr;
    }
    else {
      iVar12 = cc * 0x17 + 0x16;
      segArg = (uint16_t)((ulong)((long)(int)cc * 0x17) >> 0x10);
      src_05.seg = (int)((long)(int)cc * 0x17) + 9;
      src_05.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_05,72,iVar12,75,(int16_t)unaff_DI,(char)iVar12,0x4b,0);
      resId = 0x4c;
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      ((uint16_t *)&blitFrameSeg)[cc * 2] = segArg;
      ((uint16_t *)&blitFrameOfs)[cc * 2] = (uint16_t)stored;
    }
    farPtr = CONCAT22(segArg,MiceCursors[3].ofs);
    cc = cc + 1;
  }
  if (updateFile == false) {
    BldGfxNormal[4] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[7] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[10] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxRuin[4] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxRuin[7] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxRuin[10] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    stshStubifyBld(4);
    stshStubifyBld(7);
    stshStubifyBld(10);
    stshStubifyBld(0xd);
    stshStubifyBld(0x10);
    stshStubifyBld(0x13);
    stshStubifyBld(0x16);
    BldGfxNormal[0x4c] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x4f] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x52] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxRuin[0x4c] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxRuin[0x4f] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxRuin[0x52] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
  }
  else {
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
    lbmTmp = ovr_grabLbmTR(80);
    src_06.seg = 0x28;
    src_06.ofs = (lbmTmp->aptr).seg;
    rleSeg2 = rleSeg;
    pfVar1 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_06,173,50,179,(int16_t)unaff_DI,0x32,0xb3,0);
    BldGfxNormal[4].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    src_07.seg = 0x8c;
    src_07.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[4].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_07,108,150,114,(int16_t)unaff_DI,0x96,0x72,0);
    BldGfxNormal[7].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    src_08.seg = 0xf0;
    src_08.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[7].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_08,43,252,49,(int16_t)unaff_DI,0xfc,0x31,0);
    BldGfxNormal[10].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    src_09.seg = 0x28;
    src_09.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[10].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_09,108,50,114,(int16_t)unaff_DI,0x32,0x72,0);
    BldGfxRuin[4].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    src_10.seg = 0x8c;
    src_10.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[4].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_10,173,150,179,(int16_t)unaff_DI,0x96,0xb3,0);
    BldGfxRuin[7].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    src_11.seg = 0xf0;
    src_11.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[7].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_11,108,252,114,(int16_t)unaff_DI,0xfc,0x72,0);
    BldGfxRuin[10].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    BldGfxRuin[10].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg);
    lbmTmp = ovr_grabLbmTR(387);
    pixels_02.seg = 9;
    pixels_02.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg2;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_02,130,97,194,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg,dx };
    BldGfxNormal[0xc].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_03.seg = 100;
    pixels_03.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0xc].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_03,130,199,194,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0xd].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_04.seg = 0xcc;
    pixels_04.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0xd].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_04,130,292,194,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg,dx };
    BldGfxNormal[0xe].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_05.seg = 9;
    pixels_05.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0xe].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_05,65,97,129,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0xf].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_06.seg = 100;
    pixels_06.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0xf].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_06,65,199,129,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x10].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_07.seg = 0xcc;
    pixels_07.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x10].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_07,65,292,129,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x11].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_08.seg = 9;
    pixels_08.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x11].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_08,0,97,64,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x12].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_09.seg = 0x6c;
    pixels_09.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x12].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_09,0,191,64,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x13].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_10.seg = 0xcc;
    pixels_10.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x13].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_10,0,292,64,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x14].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxNormal[0x14].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg2);
    lbmTmp = ovr_grabLbmTR(485);
    pixels_11.seg = 9;
    pixels_11.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg3;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_11,130,97,194,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg,dx };
    BldGfxRuin[0xc].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_12.seg = 100;
    pixels_12.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0xc].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_12,130,199,194,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0xd].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_13.seg = 0xcc;
    pixels_13.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0xd].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_13,130,292,194,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg,dx };
    BldGfxRuin[0xe].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_14.seg = 9;
    pixels_14.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0xe].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_14,65,97,129,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0xf].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_15.seg = 100;
    pixels_15.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0xf].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_15,65,199,129,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x10].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_16.seg = 0xcc;
    pixels_16.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x10].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_16,65,292,129,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x11].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_17.seg = 9;
    pixels_17.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x11].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_17,0,97,64,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x12].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_18.seg = 0x6c;
    pixels_18.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x12].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_18,0,191,64,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x13].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_19.seg = 0xcc;
    pixels_19.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x13].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_19,0,292,64,11,-5,
                              (int16_t)unaff_DI,0xb,0xfb);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x14].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x14].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg3);
    lbmTmp = ovr_grabLbmTR(392);
    pixels_20.seg = 0;
    pixels_20.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg2;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_20,130,99,194,26,-1,
                              (int16_t)unaff_DI,0x1a,0xff);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x15].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_21.seg = 100;
    pixels_21.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x15].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_21,130,199,194,26,-1,
                              (int16_t)unaff_DI,0x1a,0xff);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x16].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_22.seg = 200;
    pixels_22.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x16].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_22,130,299,194,26,-1,
                              (int16_t)unaff_DI,0x1a,0xff);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x17].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_23.seg = 0;
    pixels_23.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x17].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_23,65,99,129,26,-1,
                              (int16_t)unaff_DI,0x1a,0xff);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x18].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_24.seg = 100;
    pixels_24.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x18].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_24,65,199,129,26,-1,
                              (int16_t)unaff_DI,0x1a,0xff);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x19].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_25.seg = 200;
    pixels_25.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x19].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_25,65,299,129,26,-1,
                              (int16_t)unaff_DI,0x1a,0xff);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x1a].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_26.seg = 0;
    pixels_26.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x1a].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_26,0,99,64,26,7,(int16_t)unaff_DI
                              ,0x1a,7);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x1b].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_27.seg = 100;
    pixels_27.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x1b].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_27,0,199,64,26,7,
                              (int16_t)unaff_DI,0x1a,7);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x1c].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_28.seg = 200;
    pixels_28.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x1c].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_28,0,299,64,26,7,
                              (int16_t)unaff_DI,0x1a,7);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x1d].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxNormal[0x1d].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg2);
    lbmTmp = ovr_grabLbmTR(393);
    pixels_29.seg = 0;
    pixels_29.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg3;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_29,130,99,194,26,-1,
                              (int16_t)unaff_DI,0x1a,0xff);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x15].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_30.seg = 100;
    pixels_30.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x15].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_30,130,199,194,26,-1,
                              (int16_t)unaff_DI,0x1a,0xff);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x16].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_31.seg = 200;
    pixels_31.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x16].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_31,130,299,194,26,-1,
                              (int16_t)unaff_DI,0x1a,0xff);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x17].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_32.seg = 0;
    pixels_32.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x17].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_32,65,99,129,26,-1,
                              (int16_t)unaff_DI,0x1a,0xff);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x18].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_33.seg = 100;
    pixels_33.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x18].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_33,65,199,129,26,-1,
                              (int16_t)unaff_DI,0x1a,0xff);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x19].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_34.seg = 200;
    pixels_34.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x19].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_34,65,299,129,26,-1,
                              (int16_t)unaff_DI,0x1a,0xff);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x1a].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_35.seg = 0;
    pixels_35.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x1a].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_35,0,99,64,26,7,(int16_t)unaff_DI
                              ,0x1a,7);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x1b].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_36.seg = 100;
    pixels_36.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x1b].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_36,0,199,64,26,7,
                              (int16_t)unaff_DI,0x1a,7);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x1c].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_37.seg = 200;
    pixels_37.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x1c].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_37,0,299,64,26,7,
                              (int16_t)unaff_DI,0x1a,7);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x1d].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x1d].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg3);
    lbmTmp = ovr_grabLbmTR(56);
    pixels_38.seg = 6;
    pixels_38.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg2;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_38,151,91,180,0,-25,
                              (int16_t)unaff_DI,0,0xe7);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x1e].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_39.seg = 0x6e;
    pixels_39.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x1e].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_39,151,185,180,0,-25,
                              (int16_t)unaff_DI,0,0xe7);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x1f].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_40.seg = 0xd8;
    pixels_40.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x1f].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_40,151,299,180,0,-25,
                              (int16_t)unaff_DI,0,0xe7);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x20].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_41.seg = 6;
    pixels_41.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x20].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_41,72,91,115,0,-11,
                              (int16_t)unaff_DI,0,0xf5);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x21].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_42.seg = 0x6e;
    pixels_42.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x21].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_42,72,185,115,0,-11,
                              (int16_t)unaff_DI,0,0xf5);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x22].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_43.seg = 0xd8;
    pixels_43.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x22].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_43,72,299,115,0,-11,
                              (int16_t)unaff_DI,0,0xf5);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x23].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_44.seg = 6;
    pixels_44.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x23].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_44,6,91,59,0,-1,(int16_t)unaff_DI
                              ,0,0xff);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x24].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_45.seg = 0x6e;
    pixels_45.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x24].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_45,6,185,59,0,-1,
                              (int16_t)unaff_DI,0,0xff);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x25].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_46.seg = 0xd8;
    pixels_46.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x25].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_46,6,299,59,0,-1,
                              (int16_t)unaff_DI,0,0xff);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x26].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxNormal[0x26].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg2);
    lbmTmp = ovr_grabLbmTR(444);
    pixels_47.seg = 6;
    pixels_47.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg3;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_47,151,91,180,0,-25,
                              (int16_t)unaff_DI,0,0xe7);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x1e].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_48.seg = 0x6e;
    pixels_48.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x1e].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_48,151,185,180,0,-25,
                              (int16_t)unaff_DI,0,0xe7);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x1f].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_49.seg = 0xd8;
    pixels_49.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x1f].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_49,151,299,180,0,-25,
                              (int16_t)unaff_DI,0,0xe7);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x20].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_50.seg = 6;
    pixels_50.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x20].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_50,72,91,115,0,-11,
                              (int16_t)unaff_DI,0,0xf5);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x21].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_51.seg = 0x6e;
    pixels_51.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x21].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_51,72,185,115,0,-11,
                              (int16_t)unaff_DI,0,0xf5);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x22].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_52.seg = 0xd8;
    pixels_52.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x22].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_52,72,299,115,0,-11,
                              (int16_t)unaff_DI,0,0xf5);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x23].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_53.seg = 6;
    pixels_53.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x23].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_53,6,91,59,0,-1,(int16_t)unaff_DI
                              ,0,0xff);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x24].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_54.seg = 0x6e;
    pixels_54.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x24].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_54,6,185,59,0,-1,
                              (int16_t)unaff_DI,0,0xff);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x25].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_55.seg = 0xd8;
    pixels_55.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x25].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_55,6,299,59,0,-1,
                              (int16_t)unaff_DI,0,0xff);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x26].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x26].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg3);
    lbmTmp = ovr_grabLbmTR(447);
    pixels_56.seg = 2;
    pixels_56.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg2;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_56,130,89,180,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x27].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_57.seg = 0x6c;
    pixels_57.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x27].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_57,130,191,180,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x28].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_58.seg = 0xd4;
    pixels_58.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x28].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_58,130,298,180,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x29].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_59.seg = 2;
    pixels_59.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x29].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_59,65,89,115,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x2a].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_60.seg = 0x6c;
    pixels_60.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x2a].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_60,65,191,115,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x2b].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_61.seg = 0xd4;
    pixels_61.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x2b].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_61,65,298,115,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x2c].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_62.seg = 2;
    pixels_62.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x2c].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_62,9,89,59,0,-3,(int16_t)unaff_DI
                              ,0,0xfd);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x2d].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_63.seg = 0x6c;
    pixels_63.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x2d].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_63,9,191,59,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x2e].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_64.seg = 0xd4;
    pixels_64.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x2e].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_64,9,298,59,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x2f].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxNormal[0x2f].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg2);
    lbmTmp = ovr_grabLbmTR(448);
    pixels_65.seg = 2;
    pixels_65.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg3;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_65,130,89,180,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x27].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_66.seg = 0x6c;
    pixels_66.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x27].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_66,130,191,180,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x28].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_67.seg = 0xd4;
    pixels_67.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x28].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_67,130,298,180,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x29].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_68.seg = 2;
    pixels_68.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x29].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_68,65,89,115,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x2a].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_69.seg = 0x6c;
    pixels_69.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x2a].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_69,65,191,115,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x2b].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_70.seg = 0xd4;
    pixels_70.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x2b].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_70,65,298,115,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x2c].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_71.seg = 2;
    pixels_71.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x2c].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_71,9,89,59,0,-3,(int16_t)unaff_DI
                              ,0,0xfd);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x2d].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_72.seg = 0x6c;
    pixels_72.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x2d].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_72,9,191,59,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x2e].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_73.seg = 0xd4;
    pixels_73.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x2e].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_73,9,298,59,0,-3,
                              (int16_t)unaff_DI,0,0xfd);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x2f].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x2f].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg3);
    ovr_grabBldLbm(115,116,0x10,0x74,0x10);
    ovr_grabBldLbm(423,446,0x13,0xbe,0x13);
    ovr_grabBldLbm(312,313,0x16,0x39,0x16);
    lbmTmp = ovr_grabLbmTR(459);
    pixels_74.seg = 9;
    pixels_74.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg2;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_74,68,92,182,-4,56,
                              (int16_t)unaff_DI,0xfc,0x38);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x4c].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_75.seg = 0x6c;
    pixels_75.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x4c].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_75,68,191,182,-3,56,
                              (int16_t)unaff_DI,0xfd,0x38);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x4f].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_76.seg = 0xd0;
    pixels_76.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x4f].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_76,68,291,182,-1,56,
                              (int16_t)unaff_DI,0xff,0x38);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x52].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxNormal[0x52].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg2);
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(460);
    asm { mov word ptr [(tg) + 2], dx };
    pixels_77.seg = 9;
    pixels_77.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_77,68,92,182,-4,56,
                              (int16_t)unaff_DI,0xfc,0x38);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x4c].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_78.seg = 0x6c;
    pixels_78.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxRuin[0x4c].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_78,68,191,182,-3,56,
                              (int16_t)unaff_DI,0xfd,0x38);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x4f].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_79.seg = 0xd0;
    pixels_79.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxRuin[0x4f].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_79,68,291,182,-1,56,
                              (int16_t)unaff_DI,0xff,0x38);
    asm { mov rleSeg3,dx };
    BldGfxRuin[0x52].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    BldGfxRuin[0x52].seg = stshSegTmp;
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
  }
  ovr_stshStubifyCopy1to0(0x19);
  if (updateFile != false) {
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(172);
    asm { mov word ptr [(tg) + 2], dx };
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = rleSeg;
  }
  for (cc = 0; (int)cc < 3; cc = cc + 1) {
    if (updateFile == false) {
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[1].seg + (cc + 0x1c) * 0xc) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 1) + (cc + 0x1c) * 3)->ofs = (uint16_t)farPtr;
    }
    else {
      segArg = (uint16_t)((ulong)((long)(int)cc * 100) >> 0x10);
      pixels_80.seg = (int)((long)(int)cc * 100) + 0x14;
      pixels_80.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_80,33,cc * 100 + 99,
                                116,8,28,(int16_t)unaff_DI,8,0x1c);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[1].seg + (cc + 0x1c) * 0xc) = segArg;
      ((far_t far *)(BldGfxNormal + 1) + (cc + 0x1c) * 3)->ofs = (uint16_t)stored;
    }
    rleSeg = ((far_t far *)(BldGfxNormal + 1) + (cc + 0x1c) * 3)->ofs;
    *(uint16_t *)((int)&BldGfxNormal[0].seg + (cc + 0x1c) * 0xc) =
         *(uint16_t *)((int)&BldGfxNormal[1].seg + (cc + 0x1c) * 0xc);
    ((far_t far *)BldGfxNormal + (cc + 0x1c) * 3)->ofs = rleSeg;
    rleSeg = *(uint16_t *)((int)&BldGfxNormal[1].seg + (cc + 0x1c) * 0xc);
    rleSeg2 = ((far_t far *)(BldGfxNormal + 1) + (cc + 0x1c) * 3)->ofs;
    *(uint16_t *)((int)&BldGfxNormal[2].seg + (cc + 0x1c) * 0xc) = rleSeg;
    ((far_t far *)(BldGfxNormal + 2) + (cc + 0x1c) * 3)->ofs = rleSeg2;
  }
  if (updateFile != false) {
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(175);
    asm { mov word ptr [(tg) + 2], dx };
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = rleSeg;
  }
  for (cc = 0; (int)cc < 3; cc = cc + 1) {
    if (updateFile == false) {
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxRuin[1].seg + (cc + 0x1c) * 0xc) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxRuin + 1) + (cc + 0x1c) * 3)->ofs = (uint16_t)farPtr;
    }
    else {
      segArg = (uint16_t)((ulong)((long)(int)cc * 100) >> 0x10);
      pixels_81.seg = (int)((long)(int)cc * 100) + 0x14;
      pixels_81.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_81,33,cc * 100 + 99,
                                116,8,28,(int16_t)unaff_DI,8,0x1c);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxRuin[1].seg + (cc + 0x1c) * 0xc) = segArg;
      ((far_t far *)(BldGfxRuin + 1) + (cc + 0x1c) * 3)->ofs = (uint16_t)stored;
    }
    rleSeg = ((far_t far *)(BldGfxRuin + 1) + (cc + 0x1c) * 3)->ofs;
    *(uint16_t *)((int)&BldGfxRuin[0].seg + (cc + 0x1c) * 0xc) =
         *(uint16_t *)((int)&BldGfxRuin[1].seg + (cc + 0x1c) * 0xc);
    ((far_t far *)BldGfxRuin + (cc + 0x1c) * 3)->ofs = rleSeg;
    rleSeg = *(uint16_t *)((int)&BldGfxRuin[1].seg + (cc + 0x1c) * 0xc);
    rleSeg2 = ((far_t far *)(BldGfxRuin + 1) + (cc + 0x1c) * 3)->ofs;
    *(uint16_t *)((int)&BldGfxRuin[2].seg + (cc + 0x1c) * 0xc) = rleSeg;
    ((far_t far *)(BldGfxRuin + 2) + (cc + 0x1c) * 3)->ofs = rleSeg2;
  }
  if (updateFile == false) {
    BldGfxNormal[0x5e] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x61] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[100] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x5e] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x61] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[100] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
    lbmTmp = ovr_grabLbmTR(174);
    pixels_82.seg = 100;
    pixels_82.ofs = (lbmTmp->aptr).seg;
    rleSeg2 = rleSeg;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_82,130,199,194,26,-4,
                              (int16_t)unaff_DI,0x1a,0xfc);
    asm { mov rleSeg2,dx };
    BldGfxNormal[0x5e].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_83.seg = 100;
    pixels_83.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x5e].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_83,65,199,129,26,-4,
                              (int16_t)unaff_DI,0x1a,0xfc);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x61].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_84.seg = 100;
    pixels_84.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x61].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_84,0,199,64,26,-4,
                              (int16_t)unaff_DI,0x1a,0xfc);
    asm { mov rleSeg2,dx };
    BldGfxNormal[100].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    BldGfxNormal[100].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg);
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(176);
    asm { mov word ptr [(tg) + 2], dx };
    pixels_85.seg = 100;
    pixels_85.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_85,130,199,194,26,-4,
                              (int16_t)unaff_DI,0x1a,0xfc);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x5e].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_86.seg = 100;
    pixels_86.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxRuin[0x5e].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_86,65,199,129,26,-4,
                              (int16_t)unaff_DI,0x1a,0xfc);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x61].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_87.seg = 100;
    pixels_87.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxRuin[0x61].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_87,0,199,64,26,-4,
                              (int16_t)unaff_DI,0x1a,0xfc);
    asm { mov rleSeg,dx };
    BldGfxRuin[100].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[100].seg = stshSegTmp;
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
  }
  ovr_stshStubifyCopy1to0(0x1f);
  if (updateFile == false) {
    stshStubifyBld(0x22);
    stshStubifyBld(0x25);
    stshStubifyBld(0x28);
    stshStubifyBld(0x2b);
    BldGfxNormal[0x8b] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x8e] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x91] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x94] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x97] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x9a] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    ovr_grabBldLbm(449,450,0x22,0xc2,0x22);
    ovr_grabBldLbm(390,391,0x25,0x87,0x25);
    ovr_grabBldLbm(389,442,0x28,0xba,0x28);
    lbmTmp = ovr_grabLbmTR(394);
    pixels_88.seg = 6;
    pixels_88.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg2;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_88,151,91,180,-10,-26,
                              (int16_t)unaff_DI,0xf6,0xe6);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x81].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_89.seg = 0x6e;
    pixels_89.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x81].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_89,151,185,180,-10,-26,
                              (int16_t)unaff_DI,0xf6,0xe6);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x82].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_90.seg = 0xd8;
    pixels_90.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x82].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_90,151,299,180,-10,-26,
                              (int16_t)unaff_DI,0xf6,0xe6);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x83].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_91.seg = 6;
    pixels_91.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x83].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_91,72,91,115,-10,-12,
                              (int16_t)unaff_DI,0xf6,0xf4);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x84].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_92.seg = 0x6e;
    pixels_92.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x84].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_92,72,185,115,-10,-12,
                              (int16_t)unaff_DI,0xf6,0xf4);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x85].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_93.seg = 0xd8;
    pixels_93.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x85].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_93,72,299,115,-10,-12,
                              (int16_t)unaff_DI,0xf6,0xf4);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x86].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_94.seg = 6;
    pixels_94.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x86].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_94,6,91,59,-10,-4,
                              (int16_t)unaff_DI,0xf6,0xfc);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x87].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_95.seg = 0x6e;
    pixels_95.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x87].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_95,6,185,59,-10,-4,
                              (int16_t)unaff_DI,0xf6,0xfc);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x88].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_96.seg = 0xd8;
    pixels_96.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x88].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_96,6,299,59,-10,-4,
                              (int16_t)unaff_DI,0xf6,0xfc);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x89].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxNormal[0x89].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg2);
    lbmTmp = ovr_grabLbmTR(443);
    pixels_97.seg = 6;
    pixels_97.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg3;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_97,151,91,180,-10,-26,
                              (int16_t)unaff_DI,0xf6,0xe6);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x81].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_98.seg = 0x6e;
    pixels_98.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x81].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_98,151,185,180,-10,-26,
                              (int16_t)unaff_DI,0xf6,0xe6);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x82].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_99.seg = 0xd8;
    pixels_99.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x82].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_99,151,299,180,-10,-26,
                              (int16_t)unaff_DI,0xf6,0xe6);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x83].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00100.seg = 6;
    pixels_x00100.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x83].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00100,72,91,115,-10,-12,
                              (int16_t)unaff_DI,0xf6,0xf4);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x84].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00101.seg = 0x6e;
    pixels_x00101.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x84].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00101,72,185,115,-10,-12,
                              (int16_t)unaff_DI,0xf6,0xf4);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x85].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00102.seg = 0xd8;
    pixels_x00102.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x85].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00102,72,299,115,-10,-12,
                              (int16_t)unaff_DI,0xf6,0xf4);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x86].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00103.seg = 6;
    pixels_x00103.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x86].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00103,6,91,59,-10,-4,
                              (int16_t)unaff_DI,0xf6,0xfc);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x87].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00104.seg = 0x6e;
    pixels_x00104.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x87].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00104,6,185,59,-10,-4,
                              (int16_t)unaff_DI,0xf6,0xfc);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x88].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00105.seg = 0xd8;
    pixels_x00105.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x88].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00105,6,299,59,-10,-4,
                              (int16_t)unaff_DI,0xf6,0xfc);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x89].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x89].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg3);
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(173);
    asm { mov word ptr [(tg) + 2], dx };
    pixels_x00106.seg = 0;
    pixels_x00106.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00106,130,99,194,26,0
                              ,(int16_t)unaff_DI,0x1a,0);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x8b].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00107.seg = 100;
    pixels_x00107.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x8b].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00107,130,199,194,26,
                              0,(int16_t)unaff_DI,0x1a,0);
    asm { mov rleSeg2,dx };
    BldGfxNormal[0x8e].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00108.seg = 200;
    pixels_x00108.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x8e].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00108,130,299,194,26,
                              0,(int16_t)unaff_DI,0x1a,0);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x91].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00109.seg = 0;
    pixels_x00109.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x91].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00109,65,99,129,26,0,
                              (int16_t)unaff_DI,0x1a,0);
    asm { mov rleSeg2,dx };
    BldGfxNormal[0x94].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00110.seg = 100;
    pixels_x00110.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x94].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00110,65,199,129,26,0
                              ,(int16_t)unaff_DI,0x1a,0);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x97].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00111.seg = 200;
    pixels_x00111.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x97].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00111,65,299,129,26,0
                              ,(int16_t)unaff_DI,0x1a,0);
    asm { mov rleSeg2,dx };
    BldGfxNormal[0x9a].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    BldGfxNormal[0x9a].seg = stshSegTmp;
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
  }
  ovr_stshStubifyCopy1to0(0x2e);
  ovr_stshStubifyCopy1to0(0x31);
  if (updateFile == false) {
    stshStubifyBld(0x34);
    stshStubifyBld(0x37);
    BldGfxNormal[0xaf] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0xb2] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0xb5] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0xaf] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0xb2] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0xb5] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    ovr_grabBldLbm(314,315,0x34,0x3b,0x34);
    ovr_grabBldLbm(316,317,0x37,0x3d,0x37);
    lbmTmp = ovr_grabLbmTR(320);
    pixels_x00112.seg = 0x3a;
    pixels_x00112.ofs = (lbmTmp->aptr).seg;
    rleSeg2 = rleSeg;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00112,141,134,199,-4,0,
                              (int16_t)unaff_DI,0xfc,0);
    asm { mov rleSeg2,dx };
    BldGfxNormal[0xaf].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00113.seg = 0x3a;
    pixels_x00113.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0xaf].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00113,84,134,142,-4,0,
                              (int16_t)unaff_DI,0xfc,0);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0xb2].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_x00114.seg = 0x3a;
    pixels_x00114.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0xb2].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00114,25,134,83,-4,0,
                              (int16_t)unaff_DI,0xfc,0);
    asm { mov rleSeg2,dx };
    BldGfxNormal[0xb5].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    BldGfxNormal[0xb5].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg);
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(321);
    asm { mov word ptr [(tg) + 2], dx };
    pixels_x00115.seg = 0x3a;
    pixels_x00115.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00115,141,134,199,-4,
                              0,(int16_t)unaff_DI,0xfc,0);
    asm { mov rleSeg,dx };
    BldGfxRuin[0xaf].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00116.seg = 0x3a;
    pixels_x00116.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxRuin[0xaf].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00116,84,134,142,-4,0
                              ,(int16_t)unaff_DI,0xfc,0);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0xb2].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00117.seg = 0x3a;
    pixels_x00117.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxRuin[0xb2].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00117,25,134,83,-4,0,
                              (int16_t)unaff_DI,0xfc,0);
    asm { mov rleSeg3,dx };
    BldGfxRuin[0xb5].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    BldGfxRuin[0xb5].seg = stshSegTmp;
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
  }
  ovr_stshStubifyCopy1to0(0x3a);
  if (updateFile != false) {
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(500);
    asm { mov word ptr [(tg) + 2], dx };
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = rleSeg;
  }
  for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
    if (updateFile == false) {
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xb7].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xb7) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xb8].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xb8) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xb9].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xb9) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
    }
    else {
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00118.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00118.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00118,0,
                                iVar12 * 0x30 + 0x32,54,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xb7].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xb7) + iVar12 * 0x12)->ofs = (uint16_t)stored;
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00119.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00119.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00119,62,
                                iVar12 * 0x30 + 0x32,116,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xb8].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xb8) + iVar12 * 0x12)->ofs = (uint16_t)stored;
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00120.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00120.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00120,62,
                                iVar12 * 0x30 + 0x32,116,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xb9].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xb9) + iVar12 * 0x12)->ofs = (uint16_t)stored;
    }
  }
  if (updateFile != false) {
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(501);
    asm { mov word ptr [(tg) + 2], dx };
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = rleSeg;
  }
  for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
    if (updateFile == false) {
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xba].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xba) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xbb].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xbb) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xbc].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xbc) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
    }
    else {
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00121.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00121.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00121,0,
                                iVar12 * 0x30 + 0x32,54,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xba].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xba) + iVar12 * 0x12)->ofs = (uint16_t)stored;
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00122.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00122.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00122,62,
                                iVar12 * 0x30 + 0x32,116,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xbb].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xbb) + iVar12 * 0x12)->ofs = (uint16_t)stored;
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00123.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00123.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00123,62,
                                iVar12 * 0x30 + 0x32,116,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xbc].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xbc) + iVar12 * 0x12)->ofs = (uint16_t)stored;
    }
  }
  if (updateFile != false) {
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(502);
    asm { mov word ptr [(tg) + 2], dx };
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = rleSeg;
  }
  for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
    if (updateFile == false) {
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xbd].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xbd) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xbe].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xbe) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xbf].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xbf) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
    }
    else {
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00124.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00124.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00124,0,
                                iVar12 * 0x30 + 0x32,54,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xbd].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xbd) + iVar12 * 0x12)->ofs = (uint16_t)stored;
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00125.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00125.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00125,62,
                                iVar12 * 0x30 + 0x32,116,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xbe].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xbe) + iVar12 * 0x12)->ofs = (uint16_t)stored;
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00126.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00126.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00126,62,
                                iVar12 * 0x30 + 0x32,116,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xbf].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xbf) + iVar12 * 0x12)->ofs = (uint16_t)stored;
    }
  }
  if (updateFile != false) {
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(503);
    asm { mov word ptr [(tg) + 2], dx };
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = rleSeg;
  }
  for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
    if (updateFile == false) {
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xc0].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xc0) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xc1].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xc1) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xc2].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xc2) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
    }
    else {
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00127.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00127.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00127,0,
                                iVar12 * 0x30 + 0x32,54,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xc0].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xc0) + iVar12 * 0x12)->ofs = (uint16_t)stored;
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00128.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00128.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00128,62,
                                iVar12 * 0x30 + 0x32,116,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xc1].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xc1) + iVar12 * 0x12)->ofs = (uint16_t)stored;
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00129.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00129.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00129,62,
                                iVar12 * 0x30 + 0x32,116,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xc2].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xc2) + iVar12 * 0x12)->ofs = (uint16_t)stored;
    }
  }
  if (updateFile != false) {
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(504);
    asm { mov word ptr [(tg) + 2], dx };
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = rleSeg;
  }
  for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
    if (updateFile == false) {
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xc3].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xc3) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xc4].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xc4) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xc5].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xc5) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
    }
    else {
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00130.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00130.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00130,0,
                                iVar12 * 0x30 + 0x32,54,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xc3].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xc3) + iVar12 * 0x12)->ofs = (uint16_t)stored;
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00131.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00131.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00131,62,
                                iVar12 * 0x30 + 0x32,116,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xc4].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xc4) + iVar12 * 0x12)->ofs = (uint16_t)stored;
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00132.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00132.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00132,62,
                                iVar12 * 0x30 + 0x32,116,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xc5].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xc5) + iVar12 * 0x12)->ofs = (uint16_t)stored;
    }
  }
  if (updateFile != false) {
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(505);
    asm { mov word ptr [(tg) + 2], dx };
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = rleSeg;
  }
  for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
    if (updateFile == false) {
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[0xc6].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 0xc6) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[199].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 199) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
      farPtr = func_0x0007ffe0(0x4c);
      *(uint16_t *)((int)&BldGfxNormal[200].seg + iVar12 * 0x48) = (int)((ulong)farPtr >> 0x10);
      ((far_t far *)(BldGfxNormal + 200) + iVar12 * 0x12)->ofs = (uint16_t)farPtr;
    }
    else {
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00133.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00133.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00133,0,
                                iVar12 * 0x30 + 0x32,54,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[0xc6].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 0xc6) + iVar12 * 0x12)->ofs = (uint16_t)stored;
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00134.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00134.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00134,62,
                                iVar12 * 0x30 + 0x32,116,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[199].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 199) + iVar12 * 0x12)->ofs = (uint16_t)stored;
      segArg = (uint16_t)((ulong)((long)iVar12 * 0x30) >> 0x10);
      pixels_x00135.seg = (int)((long)iVar12 * 0x30) + 3;
      pixels_x00135.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00135,62,
                                iVar12 * 0x30 + 0x32,116,0,1,(int16_t)unaff_DI,0,1);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      *(uint16_t *)((int)&BldGfxNormal[200].seg + iVar12 * 0x48) = segArg;
      ((far_t far *)(BldGfxNormal + 200) + iVar12 * 0x12)->ofs = (uint16_t)stored;
    }
  }
  if (updateFile != false) {
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
  }
  for (cc = 0; (int)cc < 0x12; cc = cc + 1) {
    ovr_stshStubifyFromSrc(cc + 0x43,cc + 0x55,(char)(cc + 0x55));
  }
  if (updateFile != false) {
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(11);
    asm { mov word ptr [(tg) + 2], dx };
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = rleSeg;
  }
  for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
    for (cc = 0; (int)cc < 3; cc = cc + 1) {
      if (updateFile == false) {
        farPtr = func_0x0007ffe0(0x4c);
        iVar3 = iVar12 * 3 + cc;
        *(uint16_t *)((int)&BldGfxNormal[0x135].seg + iVar3 * 0xc) = (int)((ulong)farPtr >> 0x10);
        ((far_t far *)(BldGfxNormal + 0x135) + iVar3 * 3)->ofs = (uint16_t)farPtr;
      }
      else {
        segArg = (uint16_t)((ulong)((long)(int)cc * 100) >> 0x10);
        pixels_00.seg = (uint16_t)((long)(int)cc * 100);
        pixels_00.ofs = (((stg_tmp_t *)tg)->aptr).seg;
        pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_00,iVar12 * 0x41,
                                  cc * 100 + 99,iVar12 * 0x41 + 0x40,30,-4,(int16_t)unaff_DI,0x1e,
                                  0xfc);
        stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
        iVar3 = iVar12 * 3 + cc;
        *(uint16_t *)((int)&BldGfxNormal[0x135].seg + iVar3 * 0xc) = segArg;
        ((far_t far *)(BldGfxNormal + 0x135) + iVar3 * 3)->ofs = (uint16_t)stored;
      }
      iVar3 = iVar12 * 3 + cc;
      rleSeg = ((far_t far *)(BldGfxNormal + 0x135) + iVar3 * 3)->ofs;
      iVar4 = iVar12 * 3 + cc;
      *(uint16_t *)((int)&BldGfxNormal[0x136].seg + iVar4 * 0xc) =
           *(uint16_t *)((int)&BldGfxNormal[0x135].seg + iVar3 * 0xc);
      ((far_t far *)(BldGfxNormal + 0x136) + iVar4 * 3)->ofs = rleSeg;
      iVar3 = iVar12 * 3 + cc;
      rleSeg = *(uint16_t *)((int)&BldGfxNormal[0x135].seg + iVar3 * 0xc);
      rleSeg2 = ((far_t far *)(BldGfxNormal + 0x135) + iVar3 * 3)->ofs;
      iVar3 = iVar12 * 3 + cc;
      *(uint16_t *)((int)&BldGfxNormal[0x137].seg + iVar3 * 0xc) = rleSeg;
      ((far_t far *)(BldGfxNormal + 0x137) + iVar3 * 3)->ofs = rleSeg2;
    }
  }
  if (updateFile == false) {
    BldGfxNormal[0x151] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(52);
    asm { mov word ptr [(tg) + 2], dx };
    pixels_x00136.seg = 0xa7;
    pixels_x00136.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg2 = rleSeg;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00136,12,206,32,-4,
                              -37,(int16_t)unaff_DI,0xfc,0xdb);
    stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)rleSeg2);
    BldGfxNormal[0x151].seg = rleSeg2;
    BldGfxNormal[0x151].ofs = (uint16_t)stored;
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = rleSeg;
  }
  rleSeg = BldGfxNormal[0x151].seg;
  ovr_StubifyCopy1to0_alt(0x70);
  if (updateFile == false) {
    BldGfxNormal[0x154] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    pixels_x00137.seg = 0xa7;
    pixels_x00137.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00137,45,206,65,-4,
                              -37,(int16_t)unaff_DI,0xfc,0xdb);
    stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)rleSeg);
    BldGfxNormal[0x154].seg = rleSeg;
    BldGfxNormal[0x154].ofs = (uint16_t)stored;
  }
  rleSeg = BldGfxNormal[0x154].seg;
  ovr_StubifyCopy1to0_alt(0x71);
  if (updateFile == false) {
    BldGfxNormal[0x157] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    pixels_x00138.seg = 0xa7;
    pixels_x00138.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00138,78,206,98,-4,
                              -37,(int16_t)unaff_DI,0xfc,0xdb);
    stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)rleSeg);
    BldGfxNormal[0x157].seg = rleSeg;
    BldGfxNormal[0x157].ofs = (uint16_t)stored;
  }
  rleSeg = BldGfxNormal[0x157].seg;
  ovr_StubifyCopy1to0_alt(0x72);
  if (updateFile == false) {
    for (cc = 0; (int)cc < 6; cc = cc + 1) {
      farPtr = func_0x0007ffe0(0x4c);
      rleSeg = AnimSeqPtr[1].seg;
      puVar11 = (uint16_t *)(AnimSeqPtr[1].ofs + cc * 4);
      puVar11[1] = (int)((ulong)farPtr >> 0x10);
      *puVar11 = (int)farPtr;
      farPtr = func_0x0007ffe0(0x4c);
      rleSeg = AnimSeqPtr[2].seg;
      puVar11 = (uint16_t *)(AnimSeqPtr[2].ofs + cc * 4);
      puVar11[1] = (int)((ulong)farPtr >> 0x10);
      *puVar11 = (int)farPtr;
    }
    farPtr = func_0x0007ffe0(0x4c);
    rleSeg2 = AnimSeqPtr[1].seg;
    rleSeg = AnimSeqPtr[1].ofs;
    *(uint16_t *)(rleSeg + 0x1a) = (int)((ulong)farPtr >> 0x10);
    *(uint16_t *)(rleSeg + 0x18) = (int)farPtr;
    farPtr = func_0x0007ffe0(0x4c);
    rleSeg = (uint16_t)((ulong)farPtr >> 0x10);
    rleSeg3 = AnimSeqPtr[2].seg;
    rleSeg2 = AnimSeqPtr[2].ofs;
    *(uint16_t *)(rleSeg2 + 0x1a) = rleSeg;
    *(uint16_t *)(rleSeg2 + 0x18) = (int)farPtr;
  }
  else {
    for (cc = 0; (int)cc < 6; cc = cc + 1) {
      segArg = (uint16_t)((ulong)((long)(int)cc * 0x21) >> 0x10);
      pixels_x00139.seg = 0xd;
      pixels_x00139.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00139,
                                (int)((long)(int)cc * 0x21) + 0x14,16,cc * 0x21 + 0x20,-22,-44,
                                (int16_t)unaff_DI,0xea,0xd4);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
      rleSeg = AnimSeqPtr[1].seg;
      puVar11 = (uint16_t *)(AnimSeqPtr[1].ofs + cc * 4);
      puVar11[1] = segArg;
      *puVar11 = (uint16_t)stored;
      rleSeg = (uint16_t)((ulong)((long)(int)cc * 0x21) >> 0x10);
      pixels_x00140.seg = 0x5f;
      pixels_x00140.ofs = (((stg_tmp_t *)tg)->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00140,
                                (int)((long)(int)cc * 0x21) + 0x14,98,cc * 0x21 + 0x20,-22,-44,
                                (int16_t)unaff_DI,0xea,0xd4);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)rleSeg);
      rleSeg2 = AnimSeqPtr[2].seg;
      puVar11 = (uint16_t *)(AnimSeqPtr[2].ofs + cc * 4);
      puVar11[1] = rleSeg;
      *puVar11 = (uint16_t)stored;
    }
    pixels_x00141.seg = 0x2b;
    pixels_x00141.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00141,20,46,32,-22,
                              -44,(int16_t)unaff_DI,0xea,0xd4);
    stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)rleSeg);
    rleSeg3 = AnimSeqPtr[1].seg;
    rleSeg2 = AnimSeqPtr[1].ofs;
    *(uint16_t *)(rleSeg2 + 0x1a) = rleSeg;
    *(uint16_t *)(rleSeg2 + 0x18) = (uint16_t)stored;
    pixels_x00142.seg = 0x7d;
    pixels_x00142.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00142,20,128,32,-22,
                              -44,(int16_t)unaff_DI,0xea,0xd4);
    stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)rleSeg);
    rleSeg3 = AnimSeqPtr[2].seg;
    rleSeg2 = AnimSeqPtr[2].ofs;
    *(uint16_t *)(rleSeg2 + 0x1a) = rleSeg;
    *(uint16_t *)(rleSeg2 + 0x18) = (uint16_t)stored;
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
  }
  builtin_memcpy(&ram0x0000d528 + 0x153,"\x02\x02\x02\x03\x03\x03",6);
  if (updateFile == false) {
    BldGfxNormal[0x15a] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x15d] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x160] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x15a] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x15d] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x160] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    lbmTmp = ovr_grabLbmTR(308);
    pixels_x00143.seg = 2;
    pixels_x00143.ofs = (lbmTmp->aptr).seg;
    rleSeg2 = rleSeg;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00143,86,85,180,-2,38,
                              (int16_t)unaff_DI,0xfe,0x26);
    asm { mov rleSeg2,dx };
    BldGfxNormal[0x15a].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00144.seg = 0x6c;
    pixels_x00144.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x15a].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00144,86,191,180,-2,38,
                              (int16_t)unaff_DI,0xfe,0x26);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x15d].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_x00145.seg = 0xd0;
    pixels_x00145.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x15d].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00145,86,298,180,0,38,
                              (int16_t)unaff_DI,0,0x26);
    asm { mov rleSeg2,dx };
    BldGfxNormal[0x160].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    BldGfxNormal[0x160].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg);
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(309);
    asm { mov word ptr [(tg) + 2], dx };
    pixels_x00146.seg = 2;
    pixels_x00146.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00146,86,85,180,-2,38
                              ,(int16_t)unaff_DI,0xfe,0x26);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x15a].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00147.seg = 0x6c;
    pixels_x00147.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxRuin[0x15a].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00147,86,191,180,-2,
                              38,(int16_t)unaff_DI,0xfe,0x26);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x15d].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00148.seg = 0xd0;
    pixels_x00148.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxRuin[0x15d].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00148,86,298,180,0,38
                              ,(int16_t)unaff_DI,0,0x26);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x160].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x160].seg = stshSegTmp;
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
  }
  ovr_stshStubifyCopy1to0(0x73);
  if (updateFile == false) {
    BldGfxNormal[0x163] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x166] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x169] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x163] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x166] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x169] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    lbmTmp = ovr_grabLbmTR(467);
    pixels_x00149.seg = 4;
    pixels_x00149.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg2;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00149,74,91,180,-3,50,
                              (int16_t)unaff_DI,0xfd,0x32);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x163].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00150.seg = 0x6e;
    pixels_x00150.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x163].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00150,74,195,180,-3,50,
                              (int16_t)unaff_DI,0xfd,0x32);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x166].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_x00151.seg = 0xcc;
    pixels_x00151.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x166].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00151,74,299,180,3,50,
                              (int16_t)unaff_DI,3,0x32);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x169].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxNormal[0x169].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg2);
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(468);
    asm { mov word ptr [(tg) + 2], dx };
    pixels_x00152.seg = 4;
    pixels_x00152.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00152,74,91,180,-3,50
                              ,(int16_t)unaff_DI,0xfd,0x32);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x163].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00153.seg = 0x6e;
    pixels_x00153.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxRuin[0x163].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00153,74,195,180,-3,
                              50,(int16_t)unaff_DI,0xfd,0x32);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x166].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00154.seg = 0xcc;
    pixels_x00154.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxRuin[0x166].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00154,74,299,180,3,50
                              ,(int16_t)unaff_DI,3,0x32);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x169].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x169].seg = stshSegTmp;
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
  }
  ovr_stshStubifyCopy1to0(0x76);
  ovr_stubyBufSrcToDst(0x76,0x79,0x79);
  ovr_stubyBufSrcToDst(0x73,0x7c,0x7c);
  ovr_stubyBufSrcToDst(0x76,0x7f,0x7f);
  if (updateFile == false) {
    BldGfxNormal[0x186] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x187] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x188] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x186] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x187] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x188] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x189] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x18a] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x18b] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x189] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x18a] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x18b] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x18d] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x18e] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x18e] = BldGfxNormal[0x18d];
    BldGfxNormal[0x18c] = BldGfxNormal[0x18d];
    BldGfxRuin[0x18c] = BldGfxRuin[0x18e];
    BldGfxRuin[0x18d] = BldGfxRuin[0x18e];
    BldGfxNormal[399] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[400] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x191] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[399] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[400] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x191] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x193] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x194] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x194] = BldGfxNormal[0x193];
    BldGfxNormal[0x192] = BldGfxNormal[0x193];
    BldGfxRuin[0x192] = BldGfxRuin[0x194];
    BldGfxRuin[0x193] = BldGfxRuin[0x194];
    BldGfxNormal[0x196] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x197] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x197] = BldGfxNormal[0x196];
    BldGfxNormal[0x195] = BldGfxNormal[0x196];
    BldGfxRuin[0x195] = BldGfxRuin[0x197];
    BldGfxRuin[0x196] = BldGfxRuin[0x197];
    for (cc = 0; (int)cc < 5; cc = cc + 1) {
      farPtr = func_0x0007ffe0(0x4c);
      rleSeg = AnimSeqPtr[0].seg;
      puVar11 = (uint16_t *)(AnimSeqPtr[0].ofs + cc * 4);
      puVar11[1] = (int)((ulong)farPtr >> 0x10);
      *puVar11 = (int)farPtr;
    }
    BldGfxNormal[0x199] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x199] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    lbmTmp = ovr_grabLbmTR(513);
    pixels_x00155.seg = 2;
    pixels_x00155.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg2;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00155,70,86,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x186].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00156.seg = 0x6c;
    pixels_x00156.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x186].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00156,70,191,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x187].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_x00157.seg = 0xd7;
    pixels_x00157.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x187].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00157,70,298,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x188].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxNormal[0x188].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg2);
    lbmTmp = ovr_grabLbmTR(514);
    pixels_x00158.seg = 2;
    pixels_x00158.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg3;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00158,70,86,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x186].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00159.seg = 0x6c;
    pixels_x00159.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x186].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00159,70,191,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x187].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00160.seg = 0xd7;
    pixels_x00160.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x187].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00160,70,298,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x188].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x188].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg3);
    lbmTmp = ovr_grabLbmTR(517);
    pixels_x00161.seg = 2;
    pixels_x00161.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg2;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00161,70,86,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x189].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00162.seg = 0x6c;
    pixels_x00162.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x189].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00162,70,191,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x18a].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_x00163.seg = 0xd7;
    pixels_x00163.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x18a].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00163,70,298,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x18b].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxNormal[0x18b].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg2);
    lbmTmp = ovr_grabLbmTR(518);
    pixels_x00164.seg = 2;
    pixels_x00164.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg3;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00164,70,86,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x189].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00165.seg = 0x6c;
    pixels_x00165.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x189].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00165,70,191,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x18a].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00166.seg = 0xd7;
    pixels_x00166.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x18a].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00166,70,298,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x18b].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x18b].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg3);
    lbmTmp = ovr_grabLbmTR(525);
    pixels_x00167.seg = 0x6c;
    pixels_x00167.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg2;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00167,70,191,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x18d].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxNormal[0x18d].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg2);
    lbmTmp = ovr_grabLbmTR(526);
    pixels_x00168.seg = 0x6c;
    pixels_x00168.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg3;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00168,70,191,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x18d].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x18d].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg3);
    rleSeg = BldGfxRuin[0x18d].seg;
    BldGfxRuin[0x18c].ofs = BldGfxRuin[0x18d].ofs;
    BldGfxRuin[0x18c].seg = BldGfxRuin[0x18d].seg;
    BldGfxRuin[0x18e].ofs = BldGfxRuin[0x18d].ofs;
    BldGfxRuin[0x18e].seg = BldGfxRuin[0x18d].seg;
    BldGfxNormal[0x18c].ofs = BldGfxNormal[0x18d].ofs;
    BldGfxNormal[0x18c].seg = BldGfxNormal[0x18d].seg;
    BldGfxNormal[0x18e].ofs = BldGfxNormal[0x18d].ofs;
    BldGfxNormal[0x18e].seg = BldGfxNormal[0x18d].seg;
    lbmTmp = ovr_grabLbmTR(515);
    pixels_x00169.seg = 2;
    pixels_x00169.ofs = (lbmTmp->aptr).seg;
    rleSeg2 = rleSeg;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00169,70,86,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg2,dx };
    BldGfxNormal[399].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00170.seg = 0x6c;
    pixels_x00170.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[399].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00170,70,191,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg3,dx };
    BldGfxNormal[400].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_x00171.seg = 0xd7;
    pixels_x00171.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[400].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00171,70,298,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg2,dx };
    BldGfxNormal[0x191].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    BldGfxNormal[0x191].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg);
    lbmTmp = ovr_grabLbmTR(516);
    pixels_x00172.seg = 2;
    pixels_x00172.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg3;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00172,70,86,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxRuin[399].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00173.seg = 0x6c;
    pixels_x00173.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[399].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00173,70,191,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg2,dx };
    BldGfxRuin[400].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00174.seg = 0xd7;
    pixels_x00174.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[400].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00174,70,298,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x191].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x191].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg3);
    lbmTmp = ovr_grabLbmTR(519);
    pixels_x00175.seg = 0x6c;
    pixels_x00175.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg2;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00175,70,191,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x193].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxNormal[0x193].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg2);
    lbmTmp = ovr_grabLbmTR(520);
    pixels_x00176.seg = 0x6c;
    pixels_x00176.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg3;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00176,70,191,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x193].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x193].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg3);
    rleSeg = BldGfxRuin[0x193].seg;
    BldGfxRuin[0x192].ofs = BldGfxRuin[0x193].ofs;
    BldGfxRuin[0x192].seg = BldGfxRuin[0x193].seg;
    BldGfxRuin[0x194].ofs = BldGfxRuin[0x193].ofs;
    BldGfxRuin[0x194].seg = BldGfxRuin[0x193].seg;
    BldGfxNormal[0x192].ofs = BldGfxNormal[0x193].ofs;
    BldGfxNormal[0x192].seg = BldGfxNormal[0x193].seg;
    BldGfxNormal[0x194].ofs = BldGfxNormal[0x193].ofs;
    BldGfxNormal[0x194].seg = BldGfxNormal[0x193].seg;
    lbmTmp = ovr_grabLbmTR(521);
    pixels_x00177.seg = 0x6c;
    pixels_x00177.ofs = (lbmTmp->aptr).seg;
    rleSeg2 = rleSeg;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00177,70,191,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg2,dx };
    BldGfxNormal[0x196].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    BldGfxNormal[0x196].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg);
    lbmTmp = ovr_grabLbmTR(522);
    pixels_x00178.seg = 0x6c;
    pixels_x00178.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg3;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00178,70,191,180,0,52,
                              (int16_t)unaff_DI,0,0x34);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x196].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x196].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg3);
    rleSeg = BldGfxRuin[0x196].seg;
    BldGfxRuin[0x195].ofs = BldGfxRuin[0x196].ofs;
    BldGfxRuin[0x195].seg = BldGfxRuin[0x196].seg;
    BldGfxRuin[0x197].ofs = BldGfxRuin[0x196].ofs;
    BldGfxRuin[0x197].seg = BldGfxRuin[0x196].seg;
    BldGfxNormal[0x195].ofs = BldGfxNormal[0x196].ofs;
    BldGfxNormal[0x195].seg = BldGfxNormal[0x196].seg;
    BldGfxNormal[0x197].ofs = BldGfxNormal[0x196].ofs;
    BldGfxNormal[0x197].seg = BldGfxNormal[0x196].seg;
    lbmTmp = ovr_grabLbmTR(523);
    rleSeg2 = rleSeg;
    for (cc = 0; (int)cc < 5; cc = cc + 1) {
      rleSeg2 = (uint16_t)((ulong)((long)(int)cc * 0x22) >> 0x10);
      pixels_x00179.seg = (int)((long)(int)cc * 0x22) + 0x50;
      pixels_x00179.ofs = (lbmTmp->aptr).seg;
      pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00179,39,cc * 0x22 + 0x68,58,
                                -68,22,(int16_t)unaff_DI,0xbc,0x16);
      stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)rleSeg2);
      rleSeg3 = AnimSeqPtr[0].seg;
      puVar11 = (uint16_t *)(AnimSeqPtr[0].ofs + cc * 4);
      puVar11[1] = rleSeg2;
      *puVar11 = (uint16_t)stored;
    }
    pixels_x00180.seg = 0x52;
    pixels_x00180.ofs = (lbmTmp->aptr).seg;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00180,87,222,181,22,32,
                              (int16_t)unaff_DI,0x16,0x20);
    asm { mov rleSeg2,dx };
    BldGfxNormal[0x199].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    BldGfxNormal[0x199].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg);
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(524);
    asm { mov word ptr [(tg) + 2], dx };
    pixels_x00181.seg = 0x52;
    pixels_x00181.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00181,87,222,181,22,
                              32,(int16_t)unaff_DI,0x16,0x20);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x199].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x199].seg = stshSegTmp;
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
  }
  ovr_StubifyCopy1to0_alt(0x88);
  BldFlags[0x198] = 0x1;
  BldFlags[0x199] = 0x1;
  BldFlags[0x19a] = 0x1;
  if (updateFile == false) {
    BldGfxNormal[0x19c] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x19f] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x19c] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x19f] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x1a2] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x1a2] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    lbmTmp = ovr_grabLbmTR(156);
    pixels_x00182.seg = 0;
    pixels_x00182.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg2;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00182,101,319,199,60,26,
                              (int16_t)unaff_DI,0x3c,0x1a);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x19c].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00183.seg = 0;
    pixels_x00183.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x19c].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00183,0,319,100,60,28,
                              (int16_t)unaff_DI,0x3c,0x1c);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x19f].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    BldGfxNormal[0x19f].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg2);
    lbmTmp = ovr_grabLbmTR(441);
    asm { mov uVar10,dx };
    pixels_x00184.seg = 0;
    pixels_x00184.ofs = (lbmTmp->aptr).seg;
    rleSeg = uVar10;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00184,101,319,199,60,26,
                              (int16_t)unaff_DI,0x3c,0x1a);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x19c].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00185.seg = 0;
    pixels_x00185.ofs = (lbmTmp->aptr).seg;
    BldGfxRuin[0x19c].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00185,0,319,100,60,28,
                              (int16_t)unaff_DI,0x3c,0x1c);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x19f].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    BldGfxRuin[0x19f].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)uVar10);
    lbmTmp = ovr_grabLbmTR(157);
    pixels_x00186.seg = 0;
    pixels_x00186.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg3;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00186,70,319,193,60,51,
                              (int16_t)unaff_DI,0x3c,0x33);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x1a2].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxNormal[0x1a2].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg3);
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(440);
    asm { mov word ptr [(tg) + 2], dx };
    pixels_x00187.seg = 0;
    pixels_x00187.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00187,70,319,193,60,
                              51,(int16_t)unaff_DI,0x3c,0x33);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x1a2].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x1a2].seg = stshSegTmp;
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
  }
  ovr_stshStubifyCopy1to0(0x89);
  ovr_stubyBufSrcToDst(0x73,0x8c,0x8c);
  if (updateFile == false) {
    BldGfxNormal[0x1ae] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x1b1] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxNormal[0x1b4] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x1ae] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x1b1] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
    BldGfxRuin[0x1b4] = far_from_u32((uint32_t)(func_0x0007ffe0(0x4c)));
  }
  else {
    lbmTmp = ovr_grabLbmTR(318);
    pixels_x00188.seg = 8;
    pixels_x00188.ofs = (lbmTmp->aptr).seg;
    rleSeg = rleSeg2;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00188,50,110,154,-4,45,
                              (int16_t)unaff_DI,0xfc,0x2d);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x1ae].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00189.seg = 0x6f;
    pixels_x00189.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x1ae].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00189,50,212,154,-4,45,
                              (int16_t)unaff_DI,0xfc,0x2d);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x1b1].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_x00190.seg = 0xd5;
    pixels_x00190.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x1b1].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00190,50,313,154,-4,45,
                              (int16_t)unaff_DI,0xfc,0x2d);
    asm { mov rleSeg,dx };
    BldGfxNormal[0x1b4].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxNormal[0x1b4].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg2);
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(319);
    asm { mov word ptr [(tg) + 2], dx };
    pixels_x00191.seg = 8;
    pixels_x00191.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00191,50,110,154,-4,
                              45,(int16_t)unaff_DI,0xfc,0x2d);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x1ae].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00192.seg = 0x6f;
    pixels_x00192.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxRuin[0x1ae].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00192,50,212,154,-4,
                              45,(int16_t)unaff_DI,0xfc,0x2d);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x1b1].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00193.seg = 0xd5;
    pixels_x00193.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxRuin[0x1b1].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00193,50,313,154,-4,
                              45,(int16_t)unaff_DI,0xfc,0x2d);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x1b4].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x1b4].seg = stshSegTmp;
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
  }
  resId = 0x4c;
  ovr_stshStubifyCopy1to0(0x8f);
  iVar12 = 0x92;
  rleSeg = rleSeg2;
  if (updateFile != false) {
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbm(17,0,0,0,0);
    resId = 0xa6;
    pixels.seg = (((stg_tmp_t *)tg)->aptr).seg;
    pixels.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
    rleSeg = rleSeg2;
    ovr_grabRemap(pixels,0xff,0x0,0xff);
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = rleSeg2;
  }
  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
    for (cc = 0; (int)cc < 2; cc = cc + 1) {
      if ((cc != 0) || (iVar3 != 0)) {
        if (updateFile == false) {
          farPtr = func_0x0007ffe0(resId);
          *(uint16_t *)((int)&BldGfxNormal[0].seg + iVar12 * 0xc) = (int)((ulong)farPtr >> 0x10);
          ((far_t far *)BldGfxNormal + iVar12 * 3)->ofs = (uint16_t)farPtr;
        }
        else {
          segArg = (uint16_t)((ulong)((long)(int)cc * 0x87) >> 0x10);
          pixels_01.seg = (uint16_t)((long)(int)cc * 0x87);
          pixels_01.ofs = (((stg_tmp_t *)tg)->aptr).seg;
          pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_01,iVar3 * 0x41,
                                    cc * 0x87 + 0x86,iVar3 * 0x41 + 0x40,30,-10,(int16_t)unaff_DI,
                                    0x1e,0xf6);
          asm { mov rleSeg,dx };
          asm { mov rleSeg3,dx };
          asm { mov rleSeg2,dx };
          resId = 0x4c;
          stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)segArg);
          *(uint16_t *)((int)&BldGfxNormal[0].seg + iVar12 * 0xc) = segArg;
          ((far_t far *)BldGfxNormal + iVar12 * 3)->ofs = (uint16_t)stored;
        }
        rleSeg = ((far_t far *)BldGfxNormal + iVar12 * 3)->ofs;
        *(uint16_t *)((int)&BldGfxNormal[1].seg + iVar12 * 0xc) =
             *(uint16_t *)((int)&BldGfxNormal[0].seg + iVar12 * 0xc);
        ((far_t far *)(BldGfxNormal + 1) + iVar12 * 3)->ofs = rleSeg;
        rleSeg = *(uint16_t *)((int)&BldGfxNormal[0].seg + iVar12 * 0xc);
        rleSeg2 = ((far_t far *)BldGfxNormal + iVar12 * 3)->ofs;
        *(uint16_t *)((int)&BldGfxNormal[2].seg + iVar12 * 0xc) = rleSeg;
        ((far_t far *)(BldGfxNormal + 2) + iVar12 * 3)->ofs = rleSeg2;
        iVar12 = iVar12 + 1;
      }
    }
  }
  if (updateFile == false) {
    BldGfxNormal[0x1c5] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1c6] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1c7] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
  }
  else {
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(31);
    asm { mov word ptr [(tg) + 2], dx };
    src_12.seg = 0;
    src_12.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg2 = rleSeg;
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_12,18,200,33,(int16_t)unaff_DI,200,0x21,0);
    BldGfxNormal[0x1c5].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    src_13.seg = 0x83;
    src_13.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x1c5].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_13,74,179,130,(int16_t)unaff_DI,0xb3,0x82,0);
    BldGfxNormal[0x1c6].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    src_14.seg = 0x1f;
    src_14.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x1c6].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_14,49,79,55,(int16_t)unaff_DI,0x4f,0x37,0);
    resId = 0x4c;
    stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)rleSeg2);
    BldGfxNormal[0x1c7].seg = rleSeg2;
    BldGfxNormal[0x1c7].ofs = (uint16_t)stored;
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = rleSeg;
  }
  BldGfxNormal[0x1ca] = BldGfxNormal[0x1c7];
  BldGfxNormal[0x1c8] = BldGfxNormal[0x1c5];
  BldGfxNormal[0x1c9] = BldGfxNormal[0x1c6];
  BldGfxNormal[0x1cd] = BldGfxNormal[0x1c7];
  BldGfxNormal[0x1cb] = BldGfxNormal[0x1c5];
  BldGfxNormal[0x1cc] = BldGfxNormal[0x1c6];
  if (updateFile == false) {
    BldGfxNormal[0x1ce] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1cf] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1d0] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
  }
  else {
    src_15.seg = 0;
    src_15.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg = BldGfxNormal[0x1c7].ofs;
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_15,49,200,65,(int16_t)unaff_DI,200,0x41,0);
    BldGfxNormal[0x1ce].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    src_16.seg = 0x1f;
    src_16.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x1ce].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_16,74,79,130,(int16_t)unaff_DI,0x4f,0x82,0);
    BldGfxNormal[0x1cf].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    src_17.seg = 0x83;
    src_17.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x1cf].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_17,49,179,55,(int16_t)unaff_DI,0xb3,0x37,0);
    resId = 0x4c;
    stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)rleSeg);
    BldGfxNormal[0x1d0].seg = rleSeg;
    BldGfxNormal[0x1d0].ofs = (uint16_t)stored;
  }
  BldGfxNormal[0x1d3] = BldGfxNormal[0x1d0];
  BldGfxNormal[0x1d1] = BldGfxNormal[0x1ce];
  BldGfxNormal[0x1d2] = BldGfxNormal[0x1cf];
  BldGfxNormal[0x1d6] = BldGfxNormal[0x1d0];
  BldGfxNormal[0x1d4] = BldGfxNormal[0x1ce];
  BldGfxNormal[0x1d5] = BldGfxNormal[0x1cf];
  if (updateFile == false) {
    BldGfxNormal[0x1d7] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1d8] = BldGfxNormal[0x1d2];
    BldGfxNormal[0x1d9] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
  }
  else {
    src_18.seg = 0;
    src_18.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg = BldGfxNormal[0x1d0].ofs;
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_18,1,200,17,(int16_t)unaff_DI,200,0x11,0);
    BldGfxNormal[0x1d7].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    src_19.seg = 0xe7;
    src_19.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg2 = BldGfxNormal[0x1d2].seg;
    BldGfxNormal[0x1d7].seg = stshSegTmp;
    BldGfxNormal[0x1d8] = BldGfxNormal[0x1d2];
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_19,49,279,55,(int16_t)unaff_DI,0x17,0x37,0);
    resId = 0x4c;
    stored = ovr_stshStoreFile((uint8_t *)pfVar1,(char)rleSeg2);
    BldGfxNormal[0x1d9].seg = rleSeg2;
    BldGfxNormal[0x1d9].ofs = (uint16_t)stored;
  }
  BldGfxNormal[0x1dc] = BldGfxNormal[0x1d9];
  BldGfxNormal[0x1da] = BldGfxNormal[0x1d7];
  BldGfxNormal[0x1df] = BldGfxNormal[0x1d9];
  BldGfxNormal[0x1dd] = BldGfxNormal[0x1d7];
  BldGfxNormal[0x1db] = BldGfxNormal[0x1d8];
  BldGfxNormal[0x1de] = BldGfxNormal[0x1d8];
  if (updateFile == false) {
    BldGfxNormal[0x1e0] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1e1] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1e5] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1e3] = BldGfxNormal[0x1e0];
    BldGfxNormal[0x1e4] = BldGfxNormal[0x1e1];
    BldGfxNormal[0x1e2] = BldGfxNormal[0x1e5];
    BldGfxNormal[0x1e6] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1e7] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1e8] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1ec] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1ed] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1ee] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1f2] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[499] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[500] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
  }
  else {
    rleSeg = BldGfxNormal[0x1d9].ofs;
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
    lbmTmp = ovr_grabLbmTR(51);
    src_20.seg = 0x83;
    src_20.ofs = (lbmTmp->aptr).seg;
    rleSeg2 = rleSeg;
    pfVar1 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_20,49,219,65,(int16_t)unaff_DI,0xdb,0x41,0);
    BldGfxNormal[0x1e0].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    src_21.seg = 0x83;
    src_21.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x1e0].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_21,74,179,130,(int16_t)unaff_DI,0xb3,0x82,0);
    BldGfxNormal[0x1e1].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    src_22.seg = 0x83;
    src_22.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x1e1].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&lbmTmp->aptr)->ofs,src_22,59,179,65,(int16_t)unaff_DI,0xb3,0x41,0);
    BldGfxNormal[0x1e2].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    BldGfxNormal[0x1e2].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg);
    (*(uint16_t *)((uint8_t *)&(tg) + 2)) = BldGfxNormal[0x1e2].seg;
    BldGfxNormal[0x1e3].ofs = BldGfxNormal[0x1e0].ofs;
    BldGfxNormal[0x1e3].seg = BldGfxNormal[0x1e0].seg;
    BldGfxNormal[0x1e4].ofs = BldGfxNormal[0x1e1].ofs;
    BldGfxNormal[0x1e4].seg = BldGfxNormal[0x1e1].seg;
    BldGfxNormal[0x1e5].ofs = BldGfxNormal[0x1e2].ofs;
    BldGfxNormal[0x1e5].seg = BldGfxNormal[0x1e2].seg;
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(288);
    asm { mov word ptr [(tg) + 2], dx };
    src_23.seg = 0;
    src_23.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_23,51,200,65,(int16_t)unaff_DI,200,0x41,0);
    BldGfxNormal[0x1e6].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    src_24.seg = 0x1f;
    src_24.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x1e6].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_24,74,79,130,(int16_t)unaff_DI,0x4f,0x82,0);
    BldGfxNormal[0x1e7].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    src_25.seg = 0;
    src_25.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x1e7].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_25,51,48,57,(int16_t)unaff_DI,0x30,0x39,0);
    BldGfxNormal[0x1e8].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    src_26.seg = 0;
    src_26.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x1e8].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_26,14,200,28,(int16_t)unaff_DI,200,0x1c,0);
    BldGfxNormal[0x1ec].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    src_27.seg = 0x83;
    src_27.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x1ec].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_27,74,179,130,(int16_t)unaff_DI,0xb3,0x82,0);
    BldGfxNormal[0x1ed].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    src_28.seg = 0;
    src_28.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x1ed].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_28,14,48,20,(int16_t)unaff_DI,0x30,0x14,0);
    BldGfxNormal[0x1ee].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    src_29.seg = 0;
    src_29.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x1ee].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_29,168,200,195,(int16_t)unaff_DI,200,0xc3,0);
    BldGfxNormal[0x1f2].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    src_30.seg = 0xe7;
    src_30.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[0x1f2].seg = stshSegTmp;
    pfVar1 = ovr_stshRleCut((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,src_30,74,279,130,(int16_t)unaff_DI,0x17,0x82,0);
    BldGfxNormal[499].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00194.seg = 0;
    pixels_x00194.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxNormal[499].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00194,168,48,187,0,13
                              ,(int16_t)unaff_DI,0,0xd);
    asm { mov rleSeg,dx };
    BldGfxNormal[500].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    resId = 0x4c;
    BldGfxNormal[500].seg = stshSegTmp;
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
  }
  BldGfxNormal[0x1ef].ofs = BldGfxNormal[0x1ec].ofs;
  BldGfxNormal[0x1ef].seg = BldGfxNormal[0x1ec].seg;
  BldGfxNormal[0x1f0].ofs = BldGfxNormal[0x1ed].ofs;
  BldGfxNormal[0x1f0].seg = BldGfxNormal[0x1ed].seg;
  BldGfxNormal[0x1f1].ofs = BldGfxNormal[0x1ee].ofs;
  BldGfxNormal[0x1f1].seg = BldGfxNormal[0x1ee].seg;
  BldGfxNormal[0x1f5].ofs = BldGfxNormal[0x1ec].ofs;
  BldGfxNormal[0x1f5].seg = BldGfxNormal[0x1ec].seg;
  BldGfxNormal[0x1f6].ofs = BldGfxNormal[0x1ed].ofs;
  BldGfxNormal[0x1f6].seg = BldGfxNormal[0x1ed].seg;
  BldGfxNormal[0x1f7].ofs = BldGfxNormal[0x1ee].ofs;
  BldGfxNormal[0x1f7].seg = BldGfxNormal[0x1ee].seg;
  BldGfxNormal[0x1e9] = BldGfxNormal[0x1e6];
  BldGfxNormal[0x1ea] = BldGfxNormal[0x1e7];
  BldGfxNormal[0x1eb] = BldGfxNormal[0x1e8];
  if (updateFile == false) {
    BldGfxNormal[0x1f9] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1fc] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxNormal[0x1ff] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxRuin[0x1f9] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxRuin[0x1fc] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
    BldGfxRuin[0x1ff] = far_from_u32((uint32_t)(func_0x0007ffe0(resId)));
  }
  else {
    rleSeg = BldGfxNormal[0x1ee].seg;
    lbmTmp = ovr_grabLbmTR(462);
    pixels_x00195.seg = 0xd;
    pixels_x00195.ofs = (lbmTmp->aptr).seg;
    rleSeg2 = rleSeg;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00195,28,96,119,0,32,
                              (int16_t)unaff_DI,0,0x20);
    asm { mov rleSeg2,dx };
    BldGfxNormal[0x1f9].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00196.seg = 0x77;
    pixels_x00196.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x1f9].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00196,28,202,119,0,32,
                              (int16_t)unaff_DI,0,0x20);
    asm { mov rleSeg3,dx };
    BldGfxNormal[0x1fc].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg3, &stshSegTmp);
    pixels_x00197.seg = 0xe2;
    pixels_x00197.ofs = (lbmTmp->aptr).seg;
    BldGfxNormal[0x1fc].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&lbmTmp->aptr)->ofs,pixels_x00197,28,309,119,0,32,
                              (int16_t)unaff_DI,0,0x20);
    asm { mov rleSeg2,dx };
    BldGfxNormal[0x1ff].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    BldGfxNormal[0x1ff].seg = stshSegTmp;
    ovr_stgFreeTmp(lbmTmp,(char)rleSeg);
    (*(uint16_t *)((uint8_t *)&(tg))) = ovr_grabLbmTR(463);
    asm { mov word ptr [(tg) + 2], dx };
    pixels_x00198.seg = 0xd;
    pixels_x00198.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    rleSeg = (*(uint16_t *)((uint8_t *)&(tg) + 2));
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00198,28,96,119,0,32,
                              (int16_t)unaff_DI,0,0x20);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x1f9].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    pixels_x00199.seg = 0x77;
    pixels_x00199.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxRuin[0x1f9].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00199,28,202,119,0,32
                              ,(int16_t)unaff_DI,0,0x20);
    asm { mov rleSeg2,dx };
    BldGfxRuin[0x1fc].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg2, &stshSegTmp);
    pixels_x00200.seg = 0xe2;
    pixels_x00200.ofs = (((stg_tmp_t *)tg)->aptr).seg;
    BldGfxRuin[0x1fc].seg = stshSegTmp;
    pfVar1 = ovr_stshRleType2((far_t far *)(&((stg_tmp_t *)tg)->aptr)->ofs,pixels_x00200,28,309,119,0,32
                              ,(int16_t)unaff_DI,0,0x20);
    asm { mov rleSeg,dx };
    BldGfxRuin[0x1ff].ofs = stsh_store((uint8_t *)pfVar1, (uint16_t)(char)rleSeg, &stshSegTmp);
    BldGfxRuin[0x1ff].seg = stshSegTmp;
    ovr_stgFreeTmp((stg_tmp_t *)tg,(char)(*(uint16_t *)((uint8_t *)&(tg) + 2)));
  }
  ovr_stshStubifyCopy1to0(0xa8);
  ovr_init_assets1(updateFile);
  ovr_init_assets2(updateFile);
  if (updateFile != false) {
    segArg = 0;
    plVar6 = LXMUL_at_(unaff_DI,CONCAT22((stg_tmp_t *)tg,unaff_SI),CONCAT22(jj,(*(uint16_t *)((uint8_t *)&(tg) + 2))));
    buf.seg = StshCtPtr.seg;
    buf.ofs = StshCtPtr.ofs;
    (*(uint8_t *)((uint8_t *)&(sz.hi))) = (char)segArg;
    sz.lo = (uint16_t)plVar6;
    (*(uint8_t *)((uint8_t *)&(sz.hi) + 1)) = (char)((uint)segArg >> 8);
    ovr_stshWriteFile(StshFile,buf,sz,(char)plVar6,0);
    lseek(StshFile,0,(int)unaff_DI);
    write(StshFile,&StshCtOfs,4);
    close(StshFile);
    if (StshCount != 0xd93) {
      printf("getcache %d  SIZESTASH %d  \r",(uint16_t)StshCount,0xd93);
      ovr_biosReadKey();
    }
  }
  stshInitPtrs();
  return;
}


/* 6ffe:733c */
void __cdecl16far stshInitPtrs(void)

{
  far_t padBase;
  far_t padBase00;
  far_t padBase01;
  far_t padOfs;
  far_t padBase02;
  far_t padBase03;
  far_t padOfs00;
  far_t padBase04;
  far_t padOfs01;
  far_t padBase05;
  far_t padOfs02;
  far_t padBase06;
  far_t padOfs03;
  far_t padOfs04;
  far_t padBase07;
  far_t padOfs05;
  far_t padOfs06;
  far_t padOfs07;
  far_t padOfs08;
  uint32_t *recPtr;
  uint16_t uVar2;
  uint16_t unaff_BP;
  uint16_t unaff_SI;
  uint uVar3;
  uint16_t uVar4;
  far_t fVar5;
  long *plVar6;
  uint16_t uVar7;
  long *retStorage;
  long *retStorage2;
  uint32_t *in_stack_0000fffa;
  uint16_t in_stack_0000fffc;
  
  uVar2 = StshCtPtr.seg;
  uVar7 = StshCtPtr.ofs;
  StshCtPtr2.seg = StshCtPtr.seg;
  StshCtPtr2.ofs = StshCtPtr.ofs;
  *(uint16_t far *)((uint8_t far *)MK_FP(StshCtPtr.seg, StshCtPtr.ofs) +  0xf) = 0;
  *(uint16_t *)(uVar7 + 0xd) = 0;
  retStorage2 =
       (long *)((char *)0x6ffe);
  fVar5.seg = unaff_SI;
  fVar5.ofs = 0x6ffe;
  padOfs08.seg = in_stack_0000fffc;
  padOfs08.ofs = (uint16_t)in_stack_0000fffa;
  fVar5 = PADD_at_(fVar5,padOfs08);
  uVar7 = fVar5.seg;
  recPtr = ovr_mkp((uint32_t *)fVar5.ofs,uVar7,(uint16_t)retStorage2);
  uVar4 = StshCtPtr.seg;
  uVar2 = StshCtPtr.ofs;
  *(uint16_t *)(uVar2 + 0xb) = uVar7;
  *(uint16_t *)(uVar2 + 9) = (uint16_t)recPtr;   /* hand fix: 2-byte half */
  for (uVar3 = 1; uVar3 < StshCount - 1; uVar3 = uVar3 + 1) {
    LXMUL_at_(retStorage2,CONCAT22(in_stack_0000fffa,unaff_SI),
              CONCAT22(unaff_BP,in_stack_0000fffc));
    retStorage = (long *)((int)&AgntAnms[0x38].halfWidth + 1);
    padBase05.seg = (uint16_t)retStorage2;
    padBase05.ofs = 0x1000;
    padOfs06.seg = (uint16_t)in_stack_0000fffa;
    padOfs06.ofs = unaff_SI;
    fVar5 = PADD_at_(padBase05,padOfs06);
    in_stack_0000fffc = fVar5.seg;
    in_stack_0000fffa =
         ovr_mkp((uint32_t *)fVar5.ofs,in_stack_0000fffc,(uint16_t)retStorage);
    LXMUL_at_(retStorage,(long)CONCAT22(unaff_SI,retStorage2),
              (long)CONCAT22(in_stack_0000fffc,in_stack_0000fffa));
    uVar2 = 0x1000;
    padBase03.seg = (uint16_t)retStorage;
    padBase03.ofs = 0x1000;
    padOfs04.seg = unaff_SI;
    padOfs04.ofs = (uint16_t)retStorage2;
    PADD_at_(padBase03,padOfs04);
    plVar6 = (long *)((int)&AgntAnms[0x38].halfWidth + 1);
    padBase01.seg = uVar2;
    padBase01.ofs = 0x1000;
    padOfs02.seg = (uint16_t)retStorage2;
    padOfs02.ofs = (uint16_t)retStorage;
    fVar5 = PADD_at_(padBase01,padOfs02);
    uVar7 = fVar5.seg;
    recPtr = ovr_mkp((uint32_t *)fVar5.ofs,uVar7,(uint16_t)plVar6);
    *(uint16_t *)((int)in_stack_0000fffa + 0xb) = uVar7;
    *(uint16_t *)((int)in_stack_0000fffa + 9) = (uint16_t)recPtr;
    LXMUL_at_(plVar6,CONCAT22(retStorage,uVar2),
              (long)CONCAT22(unaff_SI,retStorage2));
    padBase.seg = (uint16_t)plVar6;
    padBase.ofs = 0x1000;
    padOfs00.seg = (uint16_t)retStorage;
    padOfs00.ofs = uVar2;
    PADD_at_(padBase,padOfs00);
    retStorage2 = (long *)((int)&AgntAnms[0x38].halfWidth + 1);
    padBase07.seg = unaff_SI;
    padBase07.ofs = 0x1000;
    padOfs.seg = uVar2;
    padOfs.ofs = (uint16_t)plVar6;
    fVar5 = PADD_at_(padBase07,padOfs);
    uVar7 = fVar5.seg;
    recPtr = ovr_mkp((uint32_t *)fVar5.ofs,uVar7,(uint16_t)retStorage2);
    *(uint16_t *)((int)in_stack_0000fffa + 0xf) = uVar7;
    *(uint16_t *)((int)in_stack_0000fffa + 0xd) = (uint16_t)recPtr;
  }
  LXMUL_at_(retStorage2,CONCAT22(in_stack_0000fffa,unaff_SI),
            CONCAT22(unaff_BP,in_stack_0000fffc));
  uVar4 = 0x1000;
  padBase06.seg = (uint16_t)retStorage2;
  padBase06.ofs = 0x1000;
  padOfs07.seg = (uint16_t)in_stack_0000fffa;
  padOfs07.ofs = unaff_SI;
  PADD_at_(padBase06,padOfs07);
  plVar6 = (long *)((int)&AgntAnms[0x38].halfWidth + 1);
  padBase04.seg = uVar4;
  padBase04.ofs = 0x1000;
  padOfs05.seg = unaff_SI;
  padOfs05.ofs = (uint16_t)retStorage2;
  fVar5 = PADD_at_(padBase04,padOfs05);
  uVar7 = fVar5.seg;
  recPtr = ovr_mkp((uint32_t *)fVar5.ofs,uVar7,(uint16_t)plVar6);
  Stsh_2410_47f6.seg = uVar7;
  Stsh_2410_47f6.ofs = (uint16_t)recPtr;
  *(uint16_t *)((int)recPtr + 0xb) = 0;
  *(uint16_t *)((int)recPtr + 9) = 0;
  LXMUL_at_(plVar6,CONCAT22(retStorage2,uVar4),CONCAT22(in_stack_0000fffa,unaff_SI));
  uVar7 = 0x1000;
  padBase02.seg = (uint16_t)plVar6;
  padBase02.ofs = 0x1000;
  padOfs03.seg = (uint16_t)retStorage2;
  padOfs03.ofs = uVar4;
  PADD_at_(padBase02,padOfs03);
  uVar2 = 0x1000;
  padBase00.seg = uVar7;
  padBase00.ofs = 0x1000;
  padOfs01.seg = uVar4;
  padOfs01.ofs = (uint16_t)plVar6;
  fVar5 = PADD_at_(padBase00,padOfs01);
  uVar7 = fVar5.seg;
  recPtr = ovr_mkp((uint32_t *)fVar5.ofs,uVar7,uVar2);
  uVar4 = Stsh_2410_47f6.seg;
  uVar2 = Stsh_2410_47f6.ofs;
  *(uint16_t *)(uVar2 + 0xf) = uVar7;
  *(uint16_t *)(uVar2 + 0xd) = (uint16_t)recPtr;
  return;
}

