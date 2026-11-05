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
  uint16_t uVar1;
  uint16_t uVar2;
  far_t fVar3;
  
  uVar2 = StshCtPtrCopy.seg;
  uVar1 = StshCtPtrCopy.ofs;
  if (StshCount < 0xd93) {
    StshCount = StshCount + 1;
    StshCtPtrCopy = (far_t)ovr_mkp(StshCtPtrCopy.ofs + 0x15,StshCtPtrCopy.seg);
    *(undefined2 *)(uVar1 + 0x13) = 0;
    *(undefined2 *)(uVar1 + 0x11) = 0;
    *(undefined2 *)(uVar1 + 0xb) = 0;
    *(undefined2 *)(uVar1 + 9) = 0;
    *(undefined2 *)(uVar1 + 0xf) = 0;
    *(undefined2 *)(uVar1 + 0xd) = 0;
    fVar3.seg = uVar2;
    fVar3.ofs = uVar1;
    return fVar3;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x24);
}



/* 6ffe:009b */

void __cdecl16far stshTR_S_stubify0(int index)

{
  undefined4 uVar1;
  
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[0].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)BldGfxNormal + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[1].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[2].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 2) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[3].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 3) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[4].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 4) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[5].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 5) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[6].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 6) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[7].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 7) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxNormal[8].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxNormal + 8) + index * 3)->ofs = (uint16_t)uVar1;
  return;
}



/* 6ffe:01c5 */

void __cdecl16far stshStubifyBld(uint16_t index)

{
  undefined4 uVar1;
  
  stshTR_S_stubify0(index);
  uVar1 = func_0x0007ffe0((char *)
                          "%s casts %s on %s to heal %d hitpoint%s for a total of %d hitpoint%s." +
                          0x13);
  *(undefined2 *)((int)&BldGfxRuin[0].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)BldGfxRuin + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[1].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[2].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 2) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[3].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 3) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[4].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 4) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[5].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 5) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[6].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 6) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[7].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 7) + index * 3)->ofs = (uint16_t)uVar1;
  uVar1 = func_0x0007ffe0(0x6ffe);
  *(undefined2 *)((int)&BldGfxRuin[8].seg + index * 0xc) = (int)((ulong)uVar1 >> 0x10);
  ((far_t *)(BldGfxRuin + 8) + index * 3)->ofs = (uint16_t)uVar1;
  return;
}



/* 6ffe:02f7 */
/* recovered by relaxed-limit retry */
/* init_assets @ 6ffe:02f7 */

void __cdecl16far init_assets(bool grab)

{
  far_t pixels;
  stg_tmp_t *psVar1;
  int iVar2;
  int iVar3;
  uint16_t uVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined2 uVar7;
  uint16_t uVar8;
  undefined1 uVar9;
  bool bVar10;
  far_t fVar11;
  cte_t *pcVar12;
  undefined4 uVar13;
  uint8_t *puVar14;
  stg_tmp_t *psVar15;
  DW sz;
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
  undefined4 tg;
  int jj;
  int ii;
  int cc;
  
  ovr_animInitSeqs();
  StshCtPtr = (far_t)ovr_stshAlloc(0x11d0f);
  StshCount = 0;
  StshCtPtrCopy = StshCtPtr;
  ovr_allocSprSeqs();
  ovr_initStshTables();
  _fsetmem(BldGfxNormal,0xba0,0);
  _fsetmem(BldGfxRuin,0xba0,0);
  _fsetmem(BldFlags,0x2e8,0);
  StshCtOfs.hi = 0;
  StshCtOfs.lo = 0;
  if (grab) {
    StshFile = ovr_creat_wait_unlock_and_disk((char *)"strong.dat");
    write(StshFile,(uint32_t *)&StshFileSize,4);
    bVar10 = 0xfffb < StshCtOfs.lo;
    StshCtOfs.lo = StshCtOfs.lo + 4;
    StshCtOfs.hi = StshCtOfs.hi + bVar10;
    psVar15 = ovr_grabLbm(129,0,0);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    fVar11.seg = (psVar1->aptr).seg;
    fVar11.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(fVar11,0,0,10,15);
    MiceCursors[0] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src.seg = (psVar1->aptr).seg;
    src.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src,77,11,93,27);
    MiceCursors[1] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_00.seg = (psVar1->aptr).seg;
    src_00.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_00,96,55,109,62);
    MiceCursors[2] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_01.seg = (psVar1->aptr).seg;
    src_01.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_01,159,22,171,32);
    MiceCursors[3] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    ovr_stgFreeTmp(psVar15);
    uVar9 = 0x4c;
    tg = ovr_grabLbmTR(1);
  }
  else {
    StshFile = ovr_open_wait_unlock_and_disk((char *)"strong.dat");
    read(StshFile,(DW *)&StshCtOfs,4);
    lseek(StshFile,CONCAT13((char)(StshCtOfs.hi >> 8),CONCAT12((char)StshCtOfs.hi,StshCtOfs.lo)),0);
    ovr_stshReadFile(StshFile,StshCtPtr,(DW)0x11d0f);
    uVar9 = 0;
    close(StshFile);
    MiceCursors[0] = (far_t)func_0x0007ffe0(0);
    MiceCursors[1] = (far_t)func_0x0007ffe0(0);
    MiceCursors[2] = (far_t)func_0x0007ffe0(0);
    MiceCursors[3] = (far_t)func_0x0007ffe0(0);
  }
  cc = 0;
  jj = 1;
  while( true ) {
    if (0x2d < jj) break;
    for (ii = 1; ii < 0x9e; ii = ii + 0x34) {
      if (grab) {
        src_02.seg = (((stg_tmp_t *)tg)->aptr).seg;
        src_02.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
        fVar11 = ovr_stshRleCut(src_02,ii,jj,ii + 0x32,jj + 0x2a);
        uVar9 = 0x4c;
        pcVar12 = ovr_stshStoreFile((uint8_t *)fVar11);
        *(undefined2 *)((int)&LbmBigcomp50x42.seg + cc * 4) = (int)((ulong)pcVar12 >> 0x10);
        ((far_t *)&LbmBigcomp50x42 + cc)->ofs = (uint16_t)(cte_t *)pcVar12;
      }
      else {
        uVar13 = func_0x0007ffe0(uVar9);
        *(undefined2 *)((int)&LbmBigcomp50x42.seg + cc * 4) = (int)((ulong)uVar13 >> 0x10);
        ((far_t *)&LbmBigcomp50x42 + cc)->ofs = (uint16_t)uVar13;
      }
      cc = cc + 1;
    }
    jj = jj + 0x2c;
  }
  if (grab) {
    ovr_stgFreeTmp(tg);
    uVar9 = 0xcb;
    tg = ovr_grabLbm(508,0,0);
  }
  cc = 0;
  while( true ) {
    psVar1 = (stg_tmp_t *)tg;
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    if (0xb < cc) break;
    if (grab) {
      src_03.seg = (psVar1->aptr).seg;
      src_03.ofs = (&psVar1->aptr)->ofs;
      fVar11 = ovr_stshRleCut(src_03,cc * 0x17 + 6,21,cc * 0x17 + 0x1b,62);
      uVar9 = 0x4c;
      pcVar12 = ovr_stshStoreFile((uint8_t *)fVar11);
      *(int *)((undefined *)&DAT_2000_d135 + cc * 4) = (int)((ulong)pcVar12 >> 0x10);
      *(cte_t **)((undefined *)&DAT_2000_d133 + cc * 4) = (cte_t *)pcVar12;
    }
    else {
      uVar13 = func_0x0007ffe0(uVar9);
      *(int *)((undefined *)&DAT_2000_d135 + cc * 4) = (int)((ulong)uVar13 >> 0x10);
      *(int *)((undefined *)&DAT_2000_d133 + cc * 4) = (int)uVar13;
    }
    cc = cc + 1;
  }
  for (cc = 0; cc < 6; cc = cc + 1) {
    if (grab) {
      src_04.seg = (psVar1->aptr).seg;
      src_04.ofs = (&psVar1->aptr)->ofs;
      fVar11 = ovr_stshRleCut(src_04,cc * 0x17 + 9,72,cc * 0x17 + 0x16,75);
      uVar9 = 0x4c;
      pcVar12 = ovr_stshStoreFile((uint8_t *)fVar11);
      ((undefined2 *)&DAT_2000_d11d)[cc * 2] = (int)((ulong)pcVar12 >> 0x10);
      ((undefined2 *)&DAT_2000_d11b)[cc * 2] = (cte_t *)pcVar12;
    }
    else {
      uVar13 = func_0x0007ffe0(uVar9);
      ((undefined2 *)&DAT_2000_d11d)[cc * 2] = (int)((ulong)uVar13 >> 0x10);
      ((undefined2 *)&DAT_2000_d11b)[cc * 2] = (int)uVar13;
    }
  }
  if (grab) {
    ovr_stgFreeTmp(tg);
    psVar15 = ovr_grabLbmTR(80);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    src_05.seg = (psVar1->aptr).seg;
    src_05.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_05,40,173,50,179);
    BldGfxNormal[4] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_06.seg = (psVar1->aptr).seg;
    src_06.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_06,140,108,150,114);
    BldGfxNormal[7] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_07.seg = (psVar1->aptr).seg;
    src_07.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_07,240,43,252,49);
    BldGfxNormal[10] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_08.seg = (psVar1->aptr).seg;
    src_08.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_08,40,108,50,114);
    BldGfxRuin[4] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_09.seg = (psVar1->aptr).seg;
    src_09.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_09,140,173,150,179);
    BldGfxRuin[7] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_10.seg = (psVar1->aptr).seg;
    src_10.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_10,240,108,252,114);
    BldGfxRuin[10] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(387);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_00.seg = (psVar1->aptr).seg;
    pixels_00.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_00,9,130,97,194,11,-5);
    BldGfxNormal[0xc] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_01.seg = (psVar1->aptr).seg;
    pixels_01.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_01,100,130,199,194,11,-5);
    BldGfxNormal[0xd] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_02.seg = (psVar1->aptr).seg;
    pixels_02.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_02,204,130,292,194,11,-5);
    BldGfxNormal[0xe] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_03.seg = (psVar1->aptr).seg;
    pixels_03.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_03,9,65,97,129,11,-5);
    BldGfxNormal[0xf] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_04.seg = (psVar1->aptr).seg;
    pixels_04.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_04,100,65,199,129,11,-5);
    BldGfxNormal[0x10] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_05.seg = (psVar1->aptr).seg;
    pixels_05.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_05,204,65,292,129,11,-5);
    BldGfxNormal[0x11] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_06.seg = (psVar1->aptr).seg;
    pixels_06.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_06,9,0,97,64,11,-5);
    BldGfxNormal[0x12] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_07.seg = (psVar1->aptr).seg;
    pixels_07.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_07,108,0,191,64,11,-5);
    BldGfxNormal[0x13] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_08.seg = (psVar1->aptr).seg;
    pixels_08.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_08,204,0,292,64,11,-5);
    BldGfxNormal[0x14] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(485);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_09.seg = (psVar1->aptr).seg;
    pixels_09.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_09,9,130,97,194,11,-5);
    BldGfxRuin[0xc] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_10.seg = (psVar1->aptr).seg;
    pixels_10.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_10,100,130,199,194,11,-5);
    BldGfxRuin[0xd] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_11.seg = (psVar1->aptr).seg;
    pixels_11.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_11,204,130,292,194,11,-5);
    BldGfxRuin[0xe] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_12.seg = (psVar1->aptr).seg;
    pixels_12.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_12,9,65,97,129,11,-5);
    BldGfxRuin[0xf] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_13.seg = (psVar1->aptr).seg;
    pixels_13.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_13,100,65,199,129,11,-5);
    BldGfxRuin[0x10] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_14.seg = (psVar1->aptr).seg;
    pixels_14.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_14,204,65,292,129,11,-5);
    BldGfxRuin[0x11] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_15.seg = (psVar1->aptr).seg;
    pixels_15.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_15,9,0,97,64,11,-5);
    BldGfxRuin[0x12] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_16.seg = (psVar1->aptr).seg;
    pixels_16.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_16,108,0,191,64,11,-5);
    BldGfxRuin[0x13] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_17.seg = (psVar1->aptr).seg;
    pixels_17.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_17,204,0,292,64,11,-5);
    BldGfxRuin[0x14] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(392);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_18.seg = (psVar1->aptr).seg;
    pixels_18.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_18,0,130,99,194,26,-1);
    BldGfxNormal[0x15] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_19.seg = (psVar1->aptr).seg;
    pixels_19.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_19,100,130,199,194,26,-1);
    BldGfxNormal[0x16] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_20.seg = (psVar1->aptr).seg;
    pixels_20.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_20,200,130,299,194,26,-1);
    BldGfxNormal[0x17] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_21.seg = (psVar1->aptr).seg;
    pixels_21.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_21,0,65,99,129,26,-1);
    BldGfxNormal[0x18] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_22.seg = (psVar1->aptr).seg;
    pixels_22.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_22,100,65,199,129,26,-1);
    BldGfxNormal[0x19] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_23.seg = (psVar1->aptr).seg;
    pixels_23.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_23,200,65,299,129,26,-1);
    BldGfxNormal[0x1a] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_24.seg = (psVar1->aptr).seg;
    pixels_24.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_24,0,0,99,64,26,7);
    BldGfxNormal[0x1b] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_25.seg = (psVar1->aptr).seg;
    pixels_25.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_25,100,0,199,64,26,7);
    BldGfxNormal[0x1c] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_26.seg = (psVar1->aptr).seg;
    pixels_26.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_26,200,0,299,64,26,7);
    BldGfxNormal[0x1d] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(393);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_27.seg = (psVar1->aptr).seg;
    pixels_27.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_27,0,130,99,194,26,-1);
    BldGfxRuin[0x15] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_28.seg = (psVar1->aptr).seg;
    pixels_28.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_28,100,130,199,194,26,-1);
    BldGfxRuin[0x16] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_29.seg = (psVar1->aptr).seg;
    pixels_29.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_29,200,130,299,194,26,-1);
    BldGfxRuin[0x17] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_30.seg = (psVar1->aptr).seg;
    pixels_30.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_30,0,65,99,129,26,-1);
    BldGfxRuin[0x18] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_31.seg = (psVar1->aptr).seg;
    pixels_31.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_31,100,65,199,129,26,-1);
    BldGfxRuin[0x19] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_32.seg = (psVar1->aptr).seg;
    pixels_32.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_32,200,65,299,129,26,-1);
    BldGfxRuin[0x1a] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_33.seg = (psVar1->aptr).seg;
    pixels_33.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_33,0,0,99,64,26,7);
    BldGfxRuin[0x1b] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_34.seg = (psVar1->aptr).seg;
    pixels_34.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_34,100,0,199,64,26,7);
    BldGfxRuin[0x1c] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_35.seg = (psVar1->aptr).seg;
    pixels_35.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_35,200,0,299,64,26,7);
    BldGfxRuin[0x1d] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(56);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_36.seg = (psVar1->aptr).seg;
    pixels_36.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_36,6,151,91,180,0,-25);
    BldGfxNormal[0x1e] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_37.seg = (psVar1->aptr).seg;
    pixels_37.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_37,110,151,185,180,0,-25);
    BldGfxNormal[0x1f] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_38.seg = (psVar1->aptr).seg;
    pixels_38.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_38,216,151,299,180,0,-25);
    BldGfxNormal[0x20] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_39.seg = (psVar1->aptr).seg;
    pixels_39.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_39,6,72,91,115,0,-11);
    BldGfxNormal[0x21] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_40.seg = (psVar1->aptr).seg;
    pixels_40.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_40,110,72,185,115,0,-11);
    BldGfxNormal[0x22] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_41.seg = (psVar1->aptr).seg;
    pixels_41.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_41,216,72,299,115,0,-11);
    BldGfxNormal[0x23] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_42.seg = (psVar1->aptr).seg;
    pixels_42.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_42,6,6,91,59,0,-1);
    BldGfxNormal[0x24] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_43.seg = (psVar1->aptr).seg;
    pixels_43.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_43,110,6,185,59,0,-1);
    BldGfxNormal[0x25] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_44.seg = (psVar1->aptr).seg;
    pixels_44.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_44,216,6,299,59,0,-1);
    BldGfxNormal[0x26] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(444);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_45.seg = (psVar1->aptr).seg;
    pixels_45.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_45,6,151,91,180,0,-25);
    BldGfxRuin[0x1e] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_46.seg = (psVar1->aptr).seg;
    pixels_46.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_46,110,151,185,180,0,-25);
    BldGfxRuin[0x1f] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_47.seg = (psVar1->aptr).seg;
    pixels_47.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_47,216,151,299,180,0,-25);
    BldGfxRuin[0x20] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_48.seg = (psVar1->aptr).seg;
    pixels_48.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_48,6,72,91,115,0,-11);
    BldGfxRuin[0x21] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_49.seg = (psVar1->aptr).seg;
    pixels_49.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_49,110,72,185,115,0,-11);
    BldGfxRuin[0x22] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_50.seg = (psVar1->aptr).seg;
    pixels_50.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_50,216,72,299,115,0,-11);
    BldGfxRuin[0x23] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_51.seg = (psVar1->aptr).seg;
    pixels_51.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_51,6,6,91,59,0,-1);
    BldGfxRuin[0x24] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_52.seg = (psVar1->aptr).seg;
    pixels_52.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_52,110,6,185,59,0,-1);
    BldGfxRuin[0x25] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_53.seg = (psVar1->aptr).seg;
    pixels_53.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_53,216,6,299,59,0,-1);
    BldGfxRuin[0x26] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(447);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_54.seg = (psVar1->aptr).seg;
    pixels_54.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_54,2,130,89,180,0,-3);
    BldGfxNormal[0x27] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_55.seg = (psVar1->aptr).seg;
    pixels_55.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_55,108,130,191,180,0,-3);
    BldGfxNormal[0x28] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_56.seg = (psVar1->aptr).seg;
    pixels_56.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_56,212,130,298,180,0,-3);
    BldGfxNormal[0x29] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_57.seg = (psVar1->aptr).seg;
    pixels_57.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_57,2,65,89,115,0,-3);
    BldGfxNormal[0x2a] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_58.seg = (psVar1->aptr).seg;
    pixels_58.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_58,108,65,191,115,0,-3);
    BldGfxNormal[0x2b] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_59.seg = (psVar1->aptr).seg;
    pixels_59.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_59,212,65,298,115,0,-3);
    BldGfxNormal[0x2c] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_60.seg = (psVar1->aptr).seg;
    pixels_60.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_60,2,9,89,59,0,-3);
    BldGfxNormal[0x2d] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_61.seg = (psVar1->aptr).seg;
    pixels_61.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_61,108,9,191,59,0,-3);
    BldGfxNormal[0x2e] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_62.seg = (psVar1->aptr).seg;
    pixels_62.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_62,212,9,298,59,0,-3);
    BldGfxNormal[0x2f] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(448);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_63.seg = (psVar1->aptr).seg;
    pixels_63.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_63,2,130,89,180,0,-3);
    BldGfxRuin[0x27] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_64.seg = (psVar1->aptr).seg;
    pixels_64.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_64,108,130,191,180,0,-3);
    BldGfxRuin[0x28] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_65.seg = (psVar1->aptr).seg;
    pixels_65.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_65,212,130,298,180,0,-3);
    BldGfxRuin[0x29] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_66.seg = (psVar1->aptr).seg;
    pixels_66.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_66,2,65,89,115,0,-3);
    BldGfxRuin[0x2a] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_67.seg = (psVar1->aptr).seg;
    pixels_67.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_67,108,65,191,115,0,-3);
    BldGfxRuin[0x2b] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_68.seg = (psVar1->aptr).seg;
    pixels_68.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_68,212,65,298,115,0,-3);
    BldGfxRuin[0x2c] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_69.seg = (psVar1->aptr).seg;
    pixels_69.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_69,2,9,89,59,0,-3);
    BldGfxRuin[0x2d] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_70.seg = (psVar1->aptr).seg;
    pixels_70.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_70,108,9,191,59,0,-3);
    BldGfxRuin[0x2e] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_71.seg = (psVar1->aptr).seg;
    pixels_71.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_71,212,9,298,59,0,-3);
    BldGfxRuin[0x2f] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    ovr_grabBldLbm(115,116,0x10);
    ovr_grabBldLbm(423,446,0x13);
    ovr_grabBldLbm(312,313,0x16);
    psVar15 = ovr_grabLbmTR(459);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_72.seg = (psVar1->aptr).seg;
    pixels_72.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_72,9,68,92,182,-4,56);
    BldGfxNormal[0x4c] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_73.seg = (psVar1->aptr).seg;
    pixels_73.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_73,108,68,191,182,-3,56);
    BldGfxNormal[0x4f] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_74.seg = (psVar1->aptr).seg;
    pixels_74.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_74,208,68,291,182,-1,56);
    BldGfxNormal[0x52] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    tg = ovr_grabLbmTR(460);
    psVar1 = (stg_tmp_t *)tg;
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    pixels_75.seg = (psVar1->aptr).seg;
    pixels_75.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_75,9,68,92,182,-4,56);
    BldGfxRuin[0x4c] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_76.seg = (psVar1->aptr).seg;
    pixels_76.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_76,108,68,191,182,-3,56);
    BldGfxRuin[0x4f] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_77.seg = (psVar1->aptr).seg;
    pixels_77.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_77,208,68,291,182,-1,56);
    BldGfxRuin[0x52] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(tg);
  }
  else {
    BldGfxNormal[4] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[7] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[10] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxRuin[4] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxRuin[7] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxRuin[10] = (far_t)func_0x0007ffe0(uVar9);
    stshStubifyBld(4);
    stshStubifyBld(7);
    stshStubifyBld(10);
    stshStubifyBld(0xd);
    stshStubifyBld(0x10);
    stshStubifyBld(0x13);
    stshStubifyBld(0x16);
    BldGfxNormal[0x4c] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x4f] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x52] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxRuin[0x4c] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxRuin[0x4f] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxRuin[0x52] = (far_t)func_0x0007ffe0(uVar9);
  }
  ovr_stshStubifyCopy1to0(0x19);
  if (grab) {
    tg = ovr_grabLbmTR(172);
  }
  cc = 0;
  while( true ) {
    if (2 < cc) break;
    if (grab) {
      pixels_78.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_78.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)ovr_stshRleType2(pixels_78,cc * 100 + 0x14,33,cc * 100 + 99,116,8,28);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[1].seg + (cc + 0x1c) * 0xc) = (int)((ulong)pcVar12 >> 0x10)
      ;
      ((far_t *)(BldGfxNormal + 1) + (cc + 0x1c) * 3)->ofs = (uint16_t)(cte_t *)pcVar12;
    }
    else {
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[1].seg + (cc + 0x1c) * 0xc) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 1) + (cc + 0x1c) * 3)->ofs = (uint16_t)uVar13;
    }
    uVar4 = ((far_t *)(BldGfxNormal + 1) + (cc + 0x1c) * 3)->ofs;
    *(undefined2 *)((int)&BldGfxNormal[0].seg + (cc + 0x1c) * 0xc) =
         *(undefined2 *)((int)&BldGfxNormal[1].seg + (cc + 0x1c) * 0xc);
    ((far_t *)BldGfxNormal + (cc + 0x1c) * 3)->ofs = uVar4;
    uVar4 = ((far_t *)(BldGfxNormal + 1) + (cc + 0x1c) * 3)->ofs;
    *(undefined2 *)((int)&BldGfxNormal[2].seg + (cc + 0x1c) * 0xc) =
         *(undefined2 *)((int)&BldGfxNormal[1].seg + (cc + 0x1c) * 0xc);
    ((far_t *)(BldGfxNormal + 2) + (cc + 0x1c) * 3)->ofs = uVar4;
    cc = cc + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(tg);
    tg = ovr_grabLbmTR(175);
  }
  cc = 0;
  while( true ) {
    if (2 < cc) break;
    if (grab) {
      pixels_79.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_79.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)ovr_stshRleType2(pixels_79,cc * 100 + 0x14,33,cc * 100 + 99,116,8,28);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxRuin[1].seg + (cc + 0x1c) * 0xc) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxRuin + 1) + (cc + 0x1c) * 3)->ofs = (uint16_t)(cte_t *)pcVar12;
    }
    else {
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxRuin[1].seg + (cc + 0x1c) * 0xc) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxRuin + 1) + (cc + 0x1c) * 3)->ofs = (uint16_t)uVar13;
    }
    uVar4 = ((far_t *)(BldGfxRuin + 1) + (cc + 0x1c) * 3)->ofs;
    *(undefined2 *)((int)&BldGfxRuin[0].seg + (cc + 0x1c) * 0xc) =
         *(undefined2 *)((int)&BldGfxRuin[1].seg + (cc + 0x1c) * 0xc);
    ((far_t *)BldGfxRuin + (cc + 0x1c) * 3)->ofs = uVar4;
    uVar4 = ((far_t *)(BldGfxRuin + 1) + (cc + 0x1c) * 3)->ofs;
    *(undefined2 *)((int)&BldGfxRuin[2].seg + (cc + 0x1c) * 0xc) =
         *(undefined2 *)((int)&BldGfxRuin[1].seg + (cc + 0x1c) * 0xc);
    ((far_t *)(BldGfxRuin + 2) + (cc + 0x1c) * 3)->ofs = uVar4;
    cc = cc + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(tg);
    psVar15 = ovr_grabLbmTR(174);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_80.seg = (psVar1->aptr).seg;
    pixels_80.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_80,100,130,199,194,26,-4);
    BldGfxNormal[0x5e] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_81.seg = (psVar1->aptr).seg;
    pixels_81.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_81,100,65,199,129,26,-4);
    BldGfxNormal[0x61] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_82.seg = (psVar1->aptr).seg;
    pixels_82.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_82,100,0,199,64,26,-4);
    BldGfxNormal[100] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    tg = ovr_grabLbmTR(176);
    psVar1 = (stg_tmp_t *)tg;
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    pixels_83.seg = (psVar1->aptr).seg;
    pixels_83.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_83,100,130,199,194,26,-4);
    BldGfxRuin[0x5e] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_84.seg = (psVar1->aptr).seg;
    pixels_84.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_84,100,65,199,129,26,-4);
    BldGfxRuin[0x61] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_85.seg = (psVar1->aptr).seg;
    pixels_85.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_85,100,0,199,64,26,-4);
    BldGfxRuin[100] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(tg);
  }
  else {
    BldGfxNormal[0x5e] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x61] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[100] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x5e] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x61] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[100] = (far_t)func_0x0007ffe0(0x4c);
  }
  ovr_stshStubifyCopy1to0(0x1f);
  if (grab) {
    ovr_grabBldLbm(449,450,0x22);
    ovr_grabBldLbm(390,391,0x25);
    ovr_grabBldLbm(389,442,0x28);
    psVar15 = ovr_grabLbmTR(394);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_86.seg = (psVar1->aptr).seg;
    pixels_86.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_86,6,151,91,180,-10,-26);
    BldGfxNormal[0x81] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_87.seg = (psVar1->aptr).seg;
    pixels_87.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_87,110,151,185,180,-10,-26);
    BldGfxNormal[0x82] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_88.seg = (psVar1->aptr).seg;
    pixels_88.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_88,216,151,299,180,-10,-26);
    BldGfxNormal[0x83] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_89.seg = (psVar1->aptr).seg;
    pixels_89.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_89,6,72,91,115,-10,-12);
    BldGfxNormal[0x84] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_90.seg = (psVar1->aptr).seg;
    pixels_90.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_90,110,72,185,115,-10,-12);
    BldGfxNormal[0x85] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_91.seg = (psVar1->aptr).seg;
    pixels_91.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_91,216,72,299,115,-10,-12);
    BldGfxNormal[0x86] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_92.seg = (psVar1->aptr).seg;
    pixels_92.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_92,6,6,91,59,-10,-4);
    BldGfxNormal[0x87] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_93.seg = (psVar1->aptr).seg;
    pixels_93.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_93,110,6,185,59,-10,-4);
    BldGfxNormal[0x88] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_94.seg = (psVar1->aptr).seg;
    pixels_94.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_94,216,6,299,59,-10,-4);
    BldGfxNormal[0x89] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(443);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_95.seg = (psVar1->aptr).seg;
    pixels_95.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_95,6,151,91,180,-10,-26);
    BldGfxRuin[0x81] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_96.seg = (psVar1->aptr).seg;
    pixels_96.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_96,110,151,185,180,-10,-26);
    BldGfxRuin[0x82] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_97.seg = (psVar1->aptr).seg;
    pixels_97.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_97,216,151,299,180,-10,-26);
    BldGfxRuin[0x83] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_98.seg = (psVar1->aptr).seg;
    pixels_98.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_98,6,72,91,115,-10,-12);
    BldGfxRuin[0x84] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_99.seg = (psVar1->aptr).seg;
    pixels_99.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_99,110,72,185,115,-10,-12);
    BldGfxRuin[0x85] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00100.seg = (psVar1->aptr).seg;
    pixels_x00100.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00100,216,72,299,115,-10,-12);
    BldGfxRuin[0x86] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00101.seg = (psVar1->aptr).seg;
    pixels_x00101.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00101,6,6,91,59,-10,-4);
    BldGfxRuin[0x87] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00102.seg = (psVar1->aptr).seg;
    pixels_x00102.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00102,110,6,185,59,-10,-4);
    BldGfxRuin[0x88] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00103.seg = (psVar1->aptr).seg;
    pixels_x00103.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00103,216,6,299,59,-10,-4);
    BldGfxRuin[0x89] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    tg = ovr_grabLbmTR(173);
    psVar1 = (stg_tmp_t *)tg;
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    pixels_x00104.seg = (psVar1->aptr).seg;
    pixels_x00104.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00104,0,130,99,194,26,0);
    BldGfxNormal[0x8b] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00105.seg = (psVar1->aptr).seg;
    pixels_x00105.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00105,100,130,199,194,26,0);
    BldGfxNormal[0x8e] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00106.seg = (psVar1->aptr).seg;
    pixels_x00106.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00106,200,130,299,194,26,0);
    BldGfxNormal[0x91] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00107.seg = (psVar1->aptr).seg;
    pixels_x00107.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00107,0,65,99,129,26,0);
    BldGfxNormal[0x94] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00108.seg = (psVar1->aptr).seg;
    pixels_x00108.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00108,100,65,199,129,26,0);
    BldGfxNormal[0x97] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00109.seg = (psVar1->aptr).seg;
    pixels_x00109.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00109,200,65,299,129,26,0);
    BldGfxNormal[0x9a] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(tg);
  }
  else {
    stshStubifyBld(0x22);
    stshStubifyBld(0x25);
    stshStubifyBld(0x28);
    stshStubifyBld(0x2b);
    BldGfxNormal[0x8b] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x8e] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x91] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x94] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x97] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x9a] = (far_t)func_0x0007ffe0(0x4c);
  }
  ovr_stshStubifyCopy1to0(0x2e);
  ovr_stshStubifyCopy1to0(0x31);
  if (grab) {
    ovr_grabBldLbm(314,315,0x34);
    ovr_grabBldLbm(316,317,0x37);
    psVar15 = ovr_grabLbmTR(320);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00110.seg = (psVar1->aptr).seg;
    pixels_x00110.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00110,58,141,134,199,-4,0);
    BldGfxNormal[0xaf] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00111.seg = (psVar1->aptr).seg;
    pixels_x00111.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00111,58,84,134,142,-4,0);
    BldGfxNormal[0xb2] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00112.seg = (psVar1->aptr).seg;
    pixels_x00112.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00112,58,25,134,83,-4,0);
    BldGfxNormal[0xb5] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    tg = ovr_grabLbmTR(321);
    psVar1 = (stg_tmp_t *)tg;
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    pixels_x00113.seg = (psVar1->aptr).seg;
    pixels_x00113.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00113,58,141,134,199,-4,0);
    BldGfxRuin[0xaf] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00114.seg = (psVar1->aptr).seg;
    pixels_x00114.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00114,58,84,134,142,-4,0);
    BldGfxRuin[0xb2] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00115.seg = (psVar1->aptr).seg;
    pixels_x00115.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00115,58,25,134,83,-4,0);
    BldGfxRuin[0xb5] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(tg);
  }
  else {
    stshStubifyBld(0x34);
    stshStubifyBld(0x37);
    BldGfxNormal[0xaf] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0xb2] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0xb5] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0xaf] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0xb2] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0xb5] = (far_t)func_0x0007ffe0(0x4c);
  }
  ovr_stshStubifyCopy1to0(0x3a);
  if (grab) {
    tg = ovr_grabLbmTR(500);
  }
  iVar6 = 0;
  while( true ) {
    if (3 < iVar6) break;
    if (grab) {
      pixels_x00116.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00116.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00116,iVar6 * 0x30 + 3,0,iVar6 * 0x30 + 0x32,54,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xb7].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb7) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
      pixels_x00117.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00117.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00117,iVar6 * 0x30 + 3,62,iVar6 * 0x30 + 0x32,116,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xb8].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb8) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
      pixels_x00118.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00118.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00118,iVar6 * 0x30 + 3,62,iVar6 * 0x30 + 0x32,116,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xb9].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb9) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
    }
    else {
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xb7].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb7) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xb8].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb8) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xb9].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb9) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
    }
    iVar6 = iVar6 + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(tg);
    tg = ovr_grabLbmTR(501);
  }
  iVar6 = 0;
  while( true ) {
    if (3 < iVar6) break;
    if (grab) {
      pixels_x00119.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00119.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00119,iVar6 * 0x30 + 3,0,iVar6 * 0x30 + 0x32,54,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xba].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xba) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
      pixels_x00120.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00120.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00120,iVar6 * 0x30 + 3,62,iVar6 * 0x30 + 0x32,116,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xbb].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbb) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
      pixels_x00121.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00121.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00121,iVar6 * 0x30 + 3,62,iVar6 * 0x30 + 0x32,116,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xbc].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbc) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
    }
    else {
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xba].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xba) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xbb].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbb) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xbc].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbc) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
    }
    iVar6 = iVar6 + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(tg);
    tg = ovr_grabLbmTR(502);
  }
  iVar6 = 0;
  while( true ) {
    if (3 < iVar6) break;
    if (grab) {
      pixels_x00122.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00122.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00122,iVar6 * 0x30 + 3,0,iVar6 * 0x30 + 0x32,54,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xbd].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbd) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
      pixels_x00123.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00123.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00123,iVar6 * 0x30 + 3,62,iVar6 * 0x30 + 0x32,116,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xbe].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbe) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
      pixels_x00124.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00124.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00124,iVar6 * 0x30 + 3,62,iVar6 * 0x30 + 0x32,116,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xbf].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbf) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
    }
    else {
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xbd].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbd) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xbe].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbe) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xbf].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbf) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
    }
    iVar6 = iVar6 + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(tg);
    tg = ovr_grabLbmTR(503);
  }
  iVar6 = 0;
  while( true ) {
    if (3 < iVar6) break;
    if (grab) {
      pixels_x00125.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00125.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00125,iVar6 * 0x30 + 3,0,iVar6 * 0x30 + 0x32,54,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xc0].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc0) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
      pixels_x00126.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00126.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00126,iVar6 * 0x30 + 3,62,iVar6 * 0x30 + 0x32,116,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xc1].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc1) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
      pixels_x00127.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00127.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00127,iVar6 * 0x30 + 3,62,iVar6 * 0x30 + 0x32,116,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xc2].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc2) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
    }
    else {
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xc0].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc0) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xc1].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc1) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xc2].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc2) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
    }
    iVar6 = iVar6 + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(tg);
    tg = ovr_grabLbmTR(504);
  }
  iVar6 = 0;
  while( true ) {
    if (3 < iVar6) break;
    if (grab) {
      pixels_x00128.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00128.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00128,iVar6 * 0x30 + 3,0,iVar6 * 0x30 + 0x32,54,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xc3].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc3) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
      pixels_x00129.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00129.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00129,iVar6 * 0x30 + 3,62,iVar6 * 0x30 + 0x32,116,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xc4].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc4) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
      pixels_x00130.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00130.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00130,iVar6 * 0x30 + 3,62,iVar6 * 0x30 + 0x32,116,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xc5].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc5) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
    }
    else {
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xc3].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc3) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xc4].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc4) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xc5].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc5) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
    }
    iVar6 = iVar6 + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(tg);
    tg = ovr_grabLbmTR(505);
  }
  iVar6 = 0;
  while( true ) {
    if (3 < iVar6) break;
    if (grab) {
      pixels_x00131.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00131.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00131,iVar6 * 0x30 + 3,0,iVar6 * 0x30 + 0x32,54,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[0xc6].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc6) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
      pixels_x00132.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00132.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00132,iVar6 * 0x30 + 3,62,iVar6 * 0x30 + 0x32,116,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[199].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 199) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
      pixels_x00133.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00133.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00133,iVar6 * 0x30 + 3,62,iVar6 * 0x30 + 0x32,116,0,1);
      pcVar12 = ovr_stshStoreFile(puVar14);
      *(undefined2 *)((int)&BldGfxNormal[200].seg + iVar6 * 0x48) = (int)((ulong)pcVar12 >> 0x10);
      ((far_t *)(BldGfxNormal + 200) + iVar6 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar12;
    }
    else {
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[0xc6].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc6) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[199].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 199) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
      uVar13 = func_0x0007ffe0(0x4c);
      *(undefined2 *)((int)&BldGfxNormal[200].seg + iVar6 * 0x48) = (int)((ulong)uVar13 >> 0x10);
      ((far_t *)(BldGfxNormal + 200) + iVar6 * 0x12)->ofs = (uint16_t)uVar13;
    }
    iVar6 = iVar6 + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(tg);
  }
  for (cc = 0; cc < 0x12; cc = cc + 1) {
    ovr_stshStubifyFromSrc((char)(cc + 0x43),(char)(cc + 0x55));
  }
  if (grab) {
    tg = ovr_grabLbmTR(11);
  }
  iVar6 = 0;
  while( true ) {
    if (2 < iVar6) break;
    for (cc = 0; cc < 3; cc = cc + 1) {
      if (grab) {
        pixels_x00134.seg = (((stg_tmp_t *)tg)->aptr).seg;
        pixels_x00134.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
        puVar14 = (uint8_t *)
                  ovr_stshRleType2(pixels_x00134,cc * 100,iVar6 * 0x41,cc * 100 + 99,
                                   iVar6 * 0x41 + 0x40,30,-4);
        pcVar12 = ovr_stshStoreFile(puVar14);
        iVar2 = iVar6 * 3 + cc;
        *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar2 * 0xc) = (int)((ulong)pcVar12 >> 0x10)
        ;
        ((far_t *)(BldGfxNormal + 0x135) + iVar2 * 3)->ofs = (uint16_t)(cte_t *)pcVar12;
      }
      else {
        uVar13 = func_0x0007ffe0(0x4c);
        iVar2 = iVar6 * 3 + cc;
        *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar2 * 0xc) = (int)((ulong)uVar13 >> 0x10);
        ((far_t *)(BldGfxNormal + 0x135) + iVar2 * 3)->ofs = (uint16_t)uVar13;
      }
      iVar2 = iVar6 * 3 + cc;
      uVar4 = ((far_t *)(BldGfxNormal + 0x135) + iVar2 * 3)->ofs;
      iVar3 = iVar6 * 3 + cc;
      *(undefined2 *)((int)&BldGfxNormal[0x136].seg + iVar3 * 0xc) =
           *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar2 * 0xc);
      ((far_t *)(BldGfxNormal + 0x136) + iVar3 * 3)->ofs = uVar4;
      iVar2 = iVar6 * 3 + cc;
      uVar4 = ((far_t *)(BldGfxNormal + 0x135) + iVar2 * 3)->ofs;
      iVar3 = iVar6 * 3 + cc;
      *(undefined2 *)((int)&BldGfxNormal[0x137].seg + iVar3 * 0xc) =
           *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar2 * 0xc);
      ((far_t *)(BldGfxNormal + 0x137) + iVar3 * 3)->ofs = uVar4;
    }
    iVar6 = iVar6 + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(tg);
    tg = ovr_grabLbmTR(52);
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    pixels_x00135.seg = (((stg_tmp_t *)tg)->aptr).seg;
    pixels_x00135.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00135,167,12,206,32,-4,-37);
    BldGfxNormal[0x151] = (far_t)ovr_stshStoreFile(puVar14);
  }
  else {
    BldGfxNormal[0x151] = (far_t)func_0x0007ffe0(0x4c);
    uVar7 = tg._2_2_;
  }
  ovr_StubifyCopy1to0_alt(0x70);
  if (grab) {
    pixels_x00136.seg = (((stg_tmp_t *)tg)->aptr).seg;
    pixels_x00136.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00136,167,45,206,65,-4,-37);
    BldGfxNormal[0x154] = (far_t)ovr_stshStoreFile(puVar14);
  }
  else {
    BldGfxNormal[0x154] = (far_t)func_0x0007ffe0(0x4c);
  }
  ovr_StubifyCopy1to0_alt(0x71);
  if (grab) {
    pixels_x00137.seg = (((stg_tmp_t *)tg)->aptr).seg;
    pixels_x00137.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00137,167,78,206,98,-4,-37);
    BldGfxNormal[0x157] = (far_t)ovr_stshStoreFile(puVar14);
  }
  else {
    BldGfxNormal[0x157] = (far_t)func_0x0007ffe0(0x4c);
  }
  ovr_StubifyCopy1to0_alt(0x72);
  if (grab) {
    for (cc = 0; cc < 6; cc = cc + 1) {
      pixels_x00138.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00138.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00138,13,cc * 0x21 + 0x14,16,cc * 0x21 + 0x20,-22,-44);
      pcVar12 = ovr_stshStoreFile(puVar14);
      uVar4 = AnimSeqPtr[1].seg;
      puVar5 = (undefined2 *)(AnimSeqPtr[1].ofs + cc * 4);
      puVar5[1] = (int)((ulong)pcVar12 >> 0x10);
      *puVar5 = (cte_t *)pcVar12;
      pixels_x00139.seg = (((stg_tmp_t *)tg)->aptr).seg;
      pixels_x00139.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00139,95,cc * 0x21 + 0x14,98,cc * 0x21 + 0x20,-22,-44);
      pcVar12 = ovr_stshStoreFile(puVar14);
      uVar4 = AnimSeqPtr[2].seg;
      puVar5 = (undefined2 *)(AnimSeqPtr[2].ofs + cc * 4);
      puVar5[1] = (int)((ulong)pcVar12 >> 0x10);
      *puVar5 = (cte_t *)pcVar12;
    }
    pixels_x00140.seg = (((stg_tmp_t *)tg)->aptr).seg;
    pixels_x00140.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00140,43,20,46,32,-22,-44);
    pcVar12 = ovr_stshStoreFile(puVar14);
    uVar8 = AnimSeqPtr[1].seg;
    uVar4 = AnimSeqPtr[1].ofs;
    *(undefined2 *)(uVar4 + 0x1a) = (int)((ulong)pcVar12 >> 0x10);
    *(undefined2 *)(uVar4 + 0x18) = (cte_t *)pcVar12;
    pixels_x00141.seg = (((stg_tmp_t *)tg)->aptr).seg;
    pixels_x00141.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00141,125,20,128,32,-22,-44);
    pcVar12 = ovr_stshStoreFile(puVar14);
    uVar8 = AnimSeqPtr[2].seg;
    uVar4 = AnimSeqPtr[2].ofs;
    *(undefined2 *)(uVar4 + 0x1a) = (int)((ulong)pcVar12 >> 0x10);
    *(undefined2 *)(uVar4 + 0x18) = (cte_t *)pcVar12;
    ovr_stgFreeTmp(tg);
  }
  else {
    for (cc = 0; cc < 6; cc = cc + 1) {
      uVar13 = func_0x0007ffe0(0x4c);
      uVar4 = AnimSeqPtr[1].seg;
      puVar5 = (undefined2 *)(AnimSeqPtr[1].ofs + cc * 4);
      puVar5[1] = (int)((ulong)uVar13 >> 0x10);
      *puVar5 = (int)uVar13;
      uVar13 = func_0x0007ffe0(0x4c);
      uVar4 = AnimSeqPtr[2].seg;
      puVar5 = (undefined2 *)(AnimSeqPtr[2].ofs + cc * 4);
      puVar5[1] = (int)((ulong)uVar13 >> 0x10);
      *puVar5 = (int)uVar13;
    }
    uVar13 = func_0x0007ffe0(0x4c);
    uVar8 = AnimSeqPtr[1].seg;
    uVar4 = AnimSeqPtr[1].ofs;
    *(undefined2 *)(uVar4 + 0x1a) = (int)((ulong)uVar13 >> 0x10);
    *(undefined2 *)(uVar4 + 0x18) = (int)uVar13;
    uVar13 = func_0x0007ffe0(0x4c);
    uVar8 = AnimSeqPtr[2].seg;
    uVar4 = AnimSeqPtr[2].ofs;
    *(undefined2 *)(uVar4 + 0x1a) = (int)((ulong)uVar13 >> 0x10);
    *(undefined2 *)(uVar4 + 0x18) = (int)uVar13;
  }
  builtin_memcpy(&ram0x0000d528 + 0x153,"\x02\x02\x02\x03\x03\x03",6);
  if (grab) {
    psVar15 = ovr_grabLbmTR(308);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00142.seg = (psVar1->aptr).seg;
    pixels_x00142.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00142,2,86,85,180,-2,38);
    BldGfxNormal[0x15a] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00143.seg = (psVar1->aptr).seg;
    pixels_x00143.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00143,108,86,191,180,-2,38);
    BldGfxNormal[0x15d] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00144.seg = (psVar1->aptr).seg;
    pixels_x00144.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00144,208,86,298,180,0,38);
    BldGfxNormal[0x160] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    tg = ovr_grabLbmTR(309);
    psVar1 = (stg_tmp_t *)tg;
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    pixels_x00145.seg = (psVar1->aptr).seg;
    pixels_x00145.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00145,2,86,85,180,-2,38);
    BldGfxRuin[0x15a] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00146.seg = (psVar1->aptr).seg;
    pixels_x00146.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00146,108,86,191,180,-2,38);
    BldGfxRuin[0x15d] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00147.seg = (psVar1->aptr).seg;
    pixels_x00147.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00147,208,86,298,180,0,38);
    BldGfxRuin[0x160] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(tg);
  }
  else {
    BldGfxNormal[0x15a] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x15d] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x160] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x15a] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x15d] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x160] = (far_t)func_0x0007ffe0(0x4c);
  }
  ovr_stshStubifyCopy1to0(0x73);
  if (grab) {
    psVar15 = ovr_grabLbmTR(467);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00148.seg = (psVar1->aptr).seg;
    pixels_x00148.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00148,4,74,91,180,-3,50);
    BldGfxNormal[0x163] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00149.seg = (psVar1->aptr).seg;
    pixels_x00149.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00149,110,74,195,180,-3,50);
    BldGfxNormal[0x166] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00150.seg = (psVar1->aptr).seg;
    pixels_x00150.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00150,204,74,299,180,3,50);
    BldGfxNormal[0x169] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    tg = ovr_grabLbmTR(468);
    psVar1 = (stg_tmp_t *)tg;
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    pixels_x00151.seg = (psVar1->aptr).seg;
    pixels_x00151.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00151,4,74,91,180,-3,50);
    BldGfxRuin[0x163] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00152.seg = (psVar1->aptr).seg;
    pixels_x00152.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00152,110,74,195,180,-3,50);
    BldGfxRuin[0x166] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00153.seg = (psVar1->aptr).seg;
    pixels_x00153.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00153,204,74,299,180,3,50);
    BldGfxRuin[0x169] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(tg);
  }
  else {
    BldGfxNormal[0x163] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x166] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x169] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x163] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x166] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x169] = (far_t)func_0x0007ffe0(0x4c);
  }
  ovr_stshStubifyCopy1to0(0x76);
  ovr_stubyBufSrcToDst(0x76,0x79);
  ovr_stubyBufSrcToDst(0x73,0x7c);
  ovr_stubyBufSrcToDst(0x76,0x7f);
  if (grab) {
    psVar15 = ovr_grabLbmTR(513);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00154.seg = (psVar1->aptr).seg;
    pixels_x00154.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00154,2,70,86,180,0,52);
    BldGfxNormal[0x186] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00155.seg = (psVar1->aptr).seg;
    pixels_x00155.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00155,108,70,191,180,0,52);
    BldGfxNormal[0x187] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00156.seg = (psVar1->aptr).seg;
    pixels_x00156.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00156,215,70,298,180,0,52);
    BldGfxNormal[0x188] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(514);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00157.seg = (psVar1->aptr).seg;
    pixels_x00157.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00157,2,70,86,180,0,52);
    BldGfxRuin[0x186] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00158.seg = (psVar1->aptr).seg;
    pixels_x00158.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00158,108,70,191,180,0,52);
    BldGfxRuin[0x187] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00159.seg = (psVar1->aptr).seg;
    pixels_x00159.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00159,215,70,298,180,0,52);
    BldGfxRuin[0x188] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(517);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00160.seg = (psVar1->aptr).seg;
    pixels_x00160.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00160,2,70,86,180,0,52);
    BldGfxNormal[0x189] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00161.seg = (psVar1->aptr).seg;
    pixels_x00161.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00161,108,70,191,180,0,52);
    BldGfxNormal[0x18a] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00162.seg = (psVar1->aptr).seg;
    pixels_x00162.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00162,215,70,298,180,0,52);
    BldGfxNormal[0x18b] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(518);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00163.seg = (psVar1->aptr).seg;
    pixels_x00163.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00163,2,70,86,180,0,52);
    BldGfxRuin[0x189] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00164.seg = (psVar1->aptr).seg;
    pixels_x00164.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00164,108,70,191,180,0,52);
    BldGfxRuin[0x18a] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00165.seg = (psVar1->aptr).seg;
    pixels_x00165.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00165,215,70,298,180,0,52);
    BldGfxRuin[0x18b] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(525);
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00166.seg = (((stg_tmp_t *)psVar15)->aptr).seg;
    pixels_x00166.ofs = (&((stg_tmp_t *)psVar15)->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00166,108,70,191,180,0,52);
    BldGfxNormal[0x18d] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    tg = ovr_grabLbmTR(526);
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    pixels_x00167.seg = (((stg_tmp_t *)tg)->aptr).seg;
    pixels_x00167.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00167,108,70,191,180,0,52);
    BldGfxRuin[0x18d] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(tg);
  }
  else {
    BldGfxNormal[0x186] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x187] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x188] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x186] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x187] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x188] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x189] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x18a] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x18b] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x189] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x18a] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x18b] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x18d] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x18d] = (far_t)func_0x0007ffe0(0x4c);
  }
  BldGfxNormal[0x18c].ofs = BldGfxNormal[0x18d].ofs;
  BldGfxNormal[0x18c].seg = BldGfxNormal[0x18d].seg;
  BldGfxNormal[0x18e].ofs = BldGfxNormal[0x18d].ofs;
  BldGfxNormal[0x18e].seg = BldGfxNormal[0x18d].seg;
  BldGfxRuin[0x18c].ofs = BldGfxRuin[0x18d].ofs;
  BldGfxRuin[0x18c].seg = BldGfxRuin[0x18d].seg;
  BldGfxRuin[0x18e].ofs = BldGfxRuin[0x18d].ofs;
  BldGfxRuin[0x18e].seg = BldGfxRuin[0x18d].seg;
  if (grab) {
    psVar15 = ovr_grabLbmTR(515);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00168.seg = (psVar1->aptr).seg;
    pixels_x00168.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00168,2,70,86,180,0,52);
    BldGfxNormal[399] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00169.seg = (psVar1->aptr).seg;
    pixels_x00169.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00169,108,70,191,180,0,52);
    BldGfxNormal[400] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00170.seg = (psVar1->aptr).seg;
    pixels_x00170.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00170,215,70,298,180,0,52);
    BldGfxNormal[0x191] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(516);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00171.seg = (psVar1->aptr).seg;
    pixels_x00171.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00171,2,70,86,180,0,52);
    BldGfxRuin[399] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00172.seg = (psVar1->aptr).seg;
    pixels_x00172.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00172,108,70,191,180,0,52);
    BldGfxRuin[400] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00173.seg = (psVar1->aptr).seg;
    pixels_x00173.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00173,215,70,298,180,0,52);
    BldGfxRuin[0x191] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(519);
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00174.seg = (((stg_tmp_t *)psVar15)->aptr).seg;
    pixels_x00174.ofs = (&((stg_tmp_t *)psVar15)->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00174,108,70,191,180,0,52);
    BldGfxNormal[0x193] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    tg = ovr_grabLbmTR(520);
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    pixels_x00175.seg = (((stg_tmp_t *)tg)->aptr).seg;
    pixels_x00175.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00175,108,70,191,180,0,52);
    BldGfxRuin[0x193] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(tg);
  }
  else {
    BldGfxNormal[399] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[400] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x191] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[399] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[400] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x191] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x193] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x193] = (far_t)func_0x0007ffe0(0x4c);
  }
  BldGfxNormal[0x192].ofs = BldGfxNormal[0x193].ofs;
  BldGfxNormal[0x192].seg = BldGfxNormal[0x193].seg;
  BldGfxNormal[0x194].ofs = BldGfxNormal[0x193].ofs;
  BldGfxNormal[0x194].seg = BldGfxNormal[0x193].seg;
  BldGfxRuin[0x192].ofs = BldGfxRuin[0x193].ofs;
  BldGfxRuin[0x192].seg = BldGfxRuin[0x193].seg;
  BldGfxRuin[0x194].ofs = BldGfxRuin[0x193].ofs;
  BldGfxRuin[0x194].seg = BldGfxRuin[0x193].seg;
  if (grab) {
    psVar15 = ovr_grabLbmTR(521);
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00176.seg = (((stg_tmp_t *)psVar15)->aptr).seg;
    pixels_x00176.ofs = (&((stg_tmp_t *)psVar15)->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00176,108,70,191,180,0,52);
    BldGfxNormal[0x196] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    tg = ovr_grabLbmTR(522);
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    pixels_x00177.seg = (((stg_tmp_t *)tg)->aptr).seg;
    pixels_x00177.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00177,108,70,191,180,0,52);
    BldGfxRuin[0x196] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(tg);
  }
  else {
    BldGfxNormal[0x196] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x196] = (far_t)func_0x0007ffe0(0x4c);
  }
  BldGfxNormal[0x195].ofs = BldGfxNormal[0x196].ofs;
  BldGfxNormal[0x195].seg = BldGfxNormal[0x196].seg;
  BldGfxNormal[0x197].ofs = BldGfxNormal[0x196].ofs;
  BldGfxNormal[0x197].seg = BldGfxNormal[0x196].seg;
  BldGfxRuin[0x195].ofs = BldGfxRuin[0x196].ofs;
  BldGfxRuin[0x195].seg = BldGfxRuin[0x196].seg;
  BldGfxRuin[0x197].ofs = BldGfxRuin[0x196].ofs;
  BldGfxRuin[0x197].seg = BldGfxRuin[0x196].seg;
  if (grab) {
    psVar15 = ovr_grabLbmTR(523);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    for (cc = 0; cc < 5; cc = cc + 1) {
      pixels_x00178.seg = (psVar1->aptr).seg;
      pixels_x00178.ofs = (&psVar1->aptr)->ofs;
      puVar14 = (uint8_t *)
                ovr_stshRleType2(pixels_x00178,cc * 0x22 + 0x50,39,cc * 0x22 + 0x68,58,-68,22);
      pcVar12 = ovr_stshStoreFile(puVar14);
      uVar4 = AnimSeqPtr[0].seg;
      puVar5 = (undefined2 *)(AnimSeqPtr[0].ofs + cc * 4);
      puVar5[1] = (int)((ulong)pcVar12 >> 0x10);
      *puVar5 = (cte_t *)pcVar12;
    }
    pixels_x00179.seg = (psVar1->aptr).seg;
    pixels_x00179.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00179,82,87,222,181,22,32);
    BldGfxNormal[0x199] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    tg = ovr_grabLbmTR(524);
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    pixels_x00180.seg = (((stg_tmp_t *)tg)->aptr).seg;
    pixels_x00180.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00180,82,87,222,181,22,32);
    BldGfxRuin[0x199] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(tg);
  }
  else {
    for (cc = 0; cc < 5; cc = cc + 1) {
      uVar13 = func_0x0007ffe0(0x4c);
      uVar4 = AnimSeqPtr[0].seg;
      puVar5 = (undefined2 *)(AnimSeqPtr[0].ofs + cc * 4);
      puVar5[1] = (int)((ulong)uVar13 >> 0x10);
      *puVar5 = (int)uVar13;
    }
    BldGfxNormal[0x199] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x199] = (far_t)func_0x0007ffe0(0x4c);
  }
  ovr_StubifyCopy1to0_alt(0x88);
  BldFlags[0x198] = 0x1;
  BldFlags[0x199] = 0x1;
  BldFlags[0x19a] = 0x1;
  if (grab) {
    psVar15 = ovr_grabLbmTR(156);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00181.seg = (psVar1->aptr).seg;
    pixels_x00181.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00181,0,101,319,199,60,26);
    BldGfxNormal[0x19c] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00182.seg = (psVar1->aptr).seg;
    pixels_x00182.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00182,0,0,319,100,60,28);
    BldGfxNormal[0x19f] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(441);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00183.seg = (psVar1->aptr).seg;
    pixels_x00183.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00183,0,101,319,199,60,26);
    BldGfxRuin[0x19c] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00184.seg = (psVar1->aptr).seg;
    pixels_x00184.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00184,0,0,319,100,60,28);
    BldGfxRuin[0x19f] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(157);
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00185.seg = (((stg_tmp_t *)psVar15)->aptr).seg;
    pixels_x00185.ofs = (&((stg_tmp_t *)psVar15)->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00185,0,70,319,193,60,51);
    BldGfxNormal[0x1a2] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    tg = ovr_grabLbmTR(440);
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    pixels_x00186.seg = (((stg_tmp_t *)tg)->aptr).seg;
    pixels_x00186.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00186,0,70,319,193,60,51);
    BldGfxRuin[0x1a2] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(tg);
  }
  else {
    BldGfxNormal[0x19c] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x19f] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x19c] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x19f] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x1a2] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x1a2] = (far_t)func_0x0007ffe0(0x4c);
  }
  ovr_stshStubifyCopy1to0(0x89);
  ovr_stubyBufSrcToDst(0x73,0x8c);
  if (grab) {
    psVar15 = ovr_grabLbmTR(318);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00187.seg = (psVar1->aptr).seg;
    pixels_x00187.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00187,8,50,110,154,-4,45);
    BldGfxNormal[0x1ae] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00188.seg = (psVar1->aptr).seg;
    pixels_x00188.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00188,111,50,212,154,-4,45);
    BldGfxNormal[0x1b1] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00189.seg = (psVar1->aptr).seg;
    pixels_x00189.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00189,213,50,313,154,-4,45);
    BldGfxNormal[0x1b4] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    tg = ovr_grabLbmTR(319);
    psVar1 = (stg_tmp_t *)tg;
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    pixels_x00190.seg = (psVar1->aptr).seg;
    pixels_x00190.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00190,8,50,110,154,-4,45);
    BldGfxRuin[0x1ae] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00191.seg = (psVar1->aptr).seg;
    pixels_x00191.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00191,111,50,212,154,-4,45);
    BldGfxRuin[0x1b1] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00192.seg = (psVar1->aptr).seg;
    pixels_x00192.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00192,213,50,313,154,-4,45);
    BldGfxRuin[0x1b4] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(tg);
  }
  else {
    BldGfxNormal[0x1ae] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x1b1] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxNormal[0x1b4] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x1ae] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x1b1] = (far_t)func_0x0007ffe0(0x4c);
    BldGfxRuin[0x1b4] = (far_t)func_0x0007ffe0(0x4c);
  }
  uVar9 = 0x4c;
  ovr_stshStubifyCopy1to0(0x8f);
  iVar6 = 0x92;
  if (grab) {
    tg = ovr_grabLbm(17,0,0);
    uVar7 = (undefined2)((ulong)tg >> 0x10);
    uVar9 = 0xa6;
    pixels.seg = (((stg_tmp_t *)tg)->aptr).seg;
    pixels.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
    ovr_grabRemap(pixels,0xff,0x0);
  }
  iVar2 = 0;
  while( true ) {
    if (2 < iVar2) break;
    for (cc = 0; cc < 2; cc = cc + 1) {
      if ((cc != 0) || (iVar2 != 0)) {
        if (grab) {
          pixels_x00193.seg = (((stg_tmp_t *)tg)->aptr).seg;
          pixels_x00193.ofs = (&((stg_tmp_t *)tg)->aptr)->ofs;
          puVar14 = (uint8_t *)
                    ovr_stshRleType2(pixels_x00193,cc * 0x87,iVar2 * 0x41,cc * 0x87 + 0x86,
                                     iVar2 * 0x41 + 0x40,30,-10);
          uVar9 = 0x4c;
          pcVar12 = ovr_stshStoreFile(puVar14);
          *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar6 * 0xc) = (int)((ulong)pcVar12 >> 0x10);
          ((far_t *)BldGfxNormal + iVar6 * 3)->ofs = (uint16_t)(cte_t *)pcVar12;
        }
        else {
          uVar13 = func_0x0007ffe0(uVar9);
          *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar6 * 0xc) = (int)((ulong)uVar13 >> 0x10);
          ((far_t *)BldGfxNormal + iVar6 * 3)->ofs = (uint16_t)uVar13;
        }
        uVar4 = ((far_t *)BldGfxNormal + iVar6 * 3)->ofs;
        *(undefined2 *)((int)&BldGfxNormal[1].seg + iVar6 * 0xc) =
             *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar6 * 0xc);
        ((far_t *)(BldGfxNormal + 1) + iVar6 * 3)->ofs = uVar4;
        uVar4 = ((far_t *)BldGfxNormal + iVar6 * 3)->ofs;
        *(undefined2 *)((int)&BldGfxNormal[2].seg + iVar6 * 0xc) =
             *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar6 * 0xc);
        ((far_t *)(BldGfxNormal + 2) + iVar6 * 3)->ofs = uVar4;
        iVar6 = iVar6 + 1;
      }
    }
    iVar2 = iVar2 + 1;
  }
  if (grab) {
    ovr_stgFreeTmp(tg);
    psVar15 = ovr_grabLbmTR(31);
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    psVar1 = (stg_tmp_t *)psVar15;
    src_11.seg = (psVar1->aptr).seg;
    src_11.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_11,0,18,200,33);
    BldGfxNormal[0x1c5] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_12.seg = (psVar1->aptr).seg;
    src_12.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_12,131,74,179,130);
    BldGfxNormal[0x1c6] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_13.seg = (psVar1->aptr).seg;
    src_13.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_13,31,49,79,55);
    BldGfxNormal[0x1c7] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_14.seg = (psVar1->aptr).seg;
    src_14.ofs = (&psVar1->aptr)->ofs;
    BldGfxNormal[0x1c8] = BldGfxNormal[0x1c5];
    BldGfxNormal[0x1c9] = BldGfxNormal[0x1c6];
    BldGfxNormal[0x1ca] = BldGfxNormal[0x1c7];
    BldGfxNormal[0x1cb] = BldGfxNormal[0x1c5];
    BldGfxNormal[0x1cc] = BldGfxNormal[0x1c6];
    BldGfxNormal[0x1cd] = BldGfxNormal[0x1c7];
    fVar11 = ovr_stshRleCut(src_14,0,49,200,65);
    BldGfxNormal[0x1ce] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_15.seg = (psVar1->aptr).seg;
    src_15.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_15,31,74,79,130);
    BldGfxNormal[0x1cf] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_16.seg = (psVar1->aptr).seg;
    src_16.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_16,131,49,179,55);
    BldGfxNormal[0x1d0] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_17.seg = (psVar1->aptr).seg;
    src_17.ofs = (&psVar1->aptr)->ofs;
    BldGfxNormal[0x1d1] = BldGfxNormal[0x1ce];
    BldGfxNormal[0x1d3] = BldGfxNormal[0x1d0];
    BldGfxNormal[0x1d4] = BldGfxNormal[0x1ce];
    BldGfxNormal[0x1d2] = BldGfxNormal[0x1cf];
    BldGfxNormal[0x1d6] = BldGfxNormal[0x1d0];
    BldGfxNormal[0x1d5] = BldGfxNormal[0x1cf];
    fVar11 = ovr_stshRleCut(src_17,0,1,200,17);
    BldGfxNormal[0x1d7] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_18.seg = (psVar1->aptr).seg;
    src_18.ofs = (&psVar1->aptr)->ofs;
    BldGfxNormal[0x1d8] = BldGfxNormal[0x1d2];
    fVar11 = ovr_stshRleCut(src_18,231,49,279,55);
    BldGfxNormal[0x1d9] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    BldGfxNormal[0x1da] = BldGfxNormal[0x1d7];
    BldGfxNormal[0x1dc] = BldGfxNormal[0x1d9];
    BldGfxNormal[0x1dd] = BldGfxNormal[0x1d7];
    BldGfxNormal[0x1df] = BldGfxNormal[0x1d9];
    BldGfxNormal[0x1db] = BldGfxNormal[0x1d8];
    BldGfxNormal[0x1de] = BldGfxNormal[0x1d8];
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(51);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    src_19.seg = (psVar1->aptr).seg;
    src_19.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_19,131,49,219,65);
    BldGfxNormal[0x1e0] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_20.seg = (psVar1->aptr).seg;
    src_20.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_20,131,74,179,130);
    BldGfxNormal[0x1e1] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_21.seg = (psVar1->aptr).seg;
    src_21.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_21,131,59,179,65);
    BldGfxNormal[0x1e2] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    uVar9 = 0x4c;
    ovr_stgFreeTmp(psVar15);
  }
  else {
    BldGfxNormal[0x1c5] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1c6] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1c7] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1c9] = BldGfxNormal[0x1c6];
    BldGfxNormal[0x1c8] = BldGfxNormal[0x1c5];
    BldGfxNormal[0x1ca] = BldGfxNormal[0x1c7];
    BldGfxNormal[0x1cb] = BldGfxNormal[0x1c8];
    BldGfxNormal[0x1cc] = BldGfxNormal[0x1c9];
    BldGfxNormal[0x1cd] = BldGfxNormal[0x1c7];
    BldGfxNormal[0x1ce] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1cf] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1d0] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1d5] = BldGfxNormal[0x1cf];
    BldGfxNormal[0x1d1] = BldGfxNormal[0x1ce];
    BldGfxNormal[0x1d3] = BldGfxNormal[0x1d0];
    BldGfxNormal[0x1d4] = BldGfxNormal[0x1d1];
    BldGfxNormal[0x1d6] = BldGfxNormal[0x1d0];
    BldGfxNormal[0x1d2] = BldGfxNormal[0x1d5];
    BldGfxNormal[0x1d7] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1d8] = BldGfxNormal[0x1d2];
    BldGfxNormal[0x1d9] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1da] = BldGfxNormal[0x1d7];
    BldGfxNormal[0x1dc] = BldGfxNormal[0x1d9];
    BldGfxNormal[0x1dd] = BldGfxNormal[0x1d7];
    BldGfxNormal[0x1df] = BldGfxNormal[0x1d9];
    BldGfxNormal[0x1db] = BldGfxNormal[0x1d8];
    BldGfxNormal[0x1de] = BldGfxNormal[0x1d8];
    BldGfxNormal[0x1e0] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1e1] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1e2] = (far_t)func_0x0007ffe0(uVar9);
  }
  BldGfxNormal[0x1e3].ofs = BldGfxNormal[0x1e0].ofs;
  BldGfxNormal[0x1e3].seg = BldGfxNormal[0x1e0].seg;
  BldGfxNormal[0x1e4].ofs = BldGfxNormal[0x1e1].ofs;
  BldGfxNormal[0x1e4].seg = BldGfxNormal[0x1e1].seg;
  BldGfxNormal[0x1e5].ofs = BldGfxNormal[0x1e2].ofs;
  BldGfxNormal[0x1e5].seg = BldGfxNormal[0x1e2].seg;
  if (grab) {
    psVar15 = ovr_grabLbmTR(288);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    src_22.seg = (psVar1->aptr).seg;
    src_22.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_22,0,51,200,65);
    BldGfxNormal[0x1e6] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_23.seg = (psVar1->aptr).seg;
    src_23.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_23,31,74,79,130);
    BldGfxNormal[0x1e7] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_24.seg = (psVar1->aptr).seg;
    src_24.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_24,0,51,48,57);
    BldGfxNormal[0x1e8] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_25.seg = (psVar1->aptr).seg;
    src_25.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_25,0,14,200,28);
    BldGfxNormal[0x1ec] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_26.seg = (psVar1->aptr).seg;
    src_26.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_26,131,74,179,130);
    BldGfxNormal[0x1ed] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_27.seg = (psVar1->aptr).seg;
    src_27.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_27,0,14,48,20);
    BldGfxNormal[0x1ee] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_28.seg = (psVar1->aptr).seg;
    src_28.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_28,0,168,200,195);
    BldGfxNormal[0x1f2] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    src_29.seg = (psVar1->aptr).seg;
    src_29.ofs = (&psVar1->aptr)->ofs;
    fVar11 = ovr_stshRleCut(src_29,231,74,279,130);
    BldGfxNormal[499] = (far_t)ovr_stshStoreFile((uint8_t *)fVar11);
    pixels_x00194.seg = (psVar1->aptr).seg;
    pixels_x00194.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00194,0,168,48,187,0,13);
    BldGfxNormal[500] = (far_t)ovr_stshStoreFile(puVar14);
    uVar9 = 0x4c;
    ovr_stgFreeTmp(psVar15);
  }
  else {
    BldGfxNormal[0x1e6] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1e7] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1e8] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1ec] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1ed] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1ee] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1f2] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[499] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[500] = (far_t)func_0x0007ffe0(uVar9);
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
  if (grab) {
    psVar15 = ovr_grabLbmTR(462);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00195.seg = (psVar1->aptr).seg;
    pixels_x00195.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00195,13,28,96,119,0,32);
    BldGfxNormal[0x1f9] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00196.seg = (psVar1->aptr).seg;
    pixels_x00196.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00196,119,28,202,119,0,32);
    BldGfxNormal[0x1fc] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00197.seg = (psVar1->aptr).seg;
    pixels_x00197.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00197,226,28,309,119,0,32);
    BldGfxNormal[0x1ff] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
    psVar15 = ovr_grabLbmTR(463);
    psVar1 = (stg_tmp_t *)psVar15;
    uVar7 = (undefined2)((ulong)psVar15 >> 0x10);
    pixels_x00198.seg = (psVar1->aptr).seg;
    pixels_x00198.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00198,13,28,96,119,0,32);
    BldGfxRuin[0x1f9] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00199.seg = (psVar1->aptr).seg;
    pixels_x00199.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00199,119,28,202,119,0,32);
    BldGfxRuin[0x1fc] = (far_t)ovr_stshStoreFile(puVar14);
    pixels_x00200.seg = (psVar1->aptr).seg;
    pixels_x00200.ofs = (&psVar1->aptr)->ofs;
    puVar14 = (uint8_t *)ovr_stshRleType2(pixels_x00200,226,28,309,119,0,32);
    BldGfxRuin[0x1ff] = (far_t)ovr_stshStoreFile(puVar14);
    ovr_stgFreeTmp(psVar15);
  }
  else {
    BldGfxNormal[0x1f9] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1fc] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxNormal[0x1ff] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxRuin[0x1f9] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxRuin[0x1fc] = (far_t)func_0x0007ffe0(uVar9);
    BldGfxRuin[0x1ff] = (far_t)func_0x0007ffe0(uVar9);
  }
  ovr_stshStubifyCopy1to0(0xa8);
  ovr_init_assets1(grab);
  ovr_init_assets2(grab);
  if (grab) {
    sz = (DW)LXMUL_(0x15,(ulong)StshCount);
    ovr_stshWriteFile(StshFile,StshCtPtr,sz);
    lseek(StshFile,0,0);
    write(StshFile,(DW *)&StshCtOfs,4);
    close(StshFile);
    if (StshCount != 0xd93) {
      printf("getcache %d  SIZESTASH %d  \r",StshCount);
      ovr_biosReadKey();
    }
  }
  stshInitPtrs();
  return;
}




/* 6ffe:733c */

void __cdecl16far stshInitPtrs(void)

{
  undefined2 uVar1;
  int iVar2;
  uint16_t uVar3;
  uint uVar4;
  uint16_t uVar5;
  far_t fVar6;
  uint32_t uVar7;
  
  uVar5 = StshCtPtr.seg;
  uVar3 = StshCtPtr.ofs;
  StshCtPtr2.seg = StshCtPtr.seg;
  StshCtPtr2.ofs = StshCtPtr.ofs;
  *(undefined2 *)(StshCtPtr.ofs + 0xf) = 0;
  *(undefined2 *)(uVar3 + 0xd) = 0;
  fVar6 = PADD_at_(StshCtPtr,(far_t)0x15);
  uVar7 = ovr_mkp(fVar6.ofs,fVar6.seg);
  uVar5 = StshCtPtr.seg;
  uVar3 = StshCtPtr.ofs;
  *(undefined2 *)(uVar3 + 0xb) = (int)(uVar7 >> 0x10);
  *(undefined2 *)(uVar3 + 9) = (int)uVar7;
  for (uVar4 = 1; uVar4 < StshCount - 1; uVar4 = uVar4 + 1) {
    fVar6 = (far_t)LXMUL_at_(0x15,(long)(int)uVar4);
    fVar6 = PADD_at_(StshCtPtr,fVar6);
    uVar7 = ovr_mkp(fVar6.ofs,fVar6.seg);
    iVar2 = (int)uVar7;
    uVar1 = (undefined2)(uVar7 >> 0x10);
    fVar6 = (far_t)LXMUL_at_(0x15,(long)(int)uVar4);
    fVar6 = PADD_at_(StshCtPtr,fVar6);
    fVar6 = PADD_at_(fVar6,(far_t)0x15);
    uVar7 = ovr_mkp(fVar6.ofs,fVar6.seg);
    *(undefined2 *)(iVar2 + 0xb) = (int)(uVar7 >> 0x10);
    *(undefined2 *)(iVar2 + 9) = (int)uVar7;
    fVar6 = (far_t)LXMUL_at_(0x15,(long)(int)uVar4);
    fVar6 = PADD_at_(StshCtPtr,fVar6);
    fVar6 = PADD_at_(fVar6,(far_t)0xffffffeb);
    uVar7 = ovr_mkp(fVar6.ofs,fVar6.seg);
    *(undefined2 *)(iVar2 + 0xf) = (int)(uVar7 >> 0x10);
    *(undefined2 *)(iVar2 + 0xd) = (int)uVar7;
  }
  fVar6 = (far_t)LXMUL_at_(0x15,(ulong)StshCount);
  fVar6 = PADD_at_(StshCtPtr,fVar6);
  fVar6 = PADD_at_(fVar6,(far_t)0xffffffeb);
  Stsh_2410_47f6 = (far_t)ovr_mkp(fVar6.ofs,fVar6.seg);
  uVar5 = Stsh_2410_47f6.ofs;
  uVar3 = Stsh_2410_47f6.seg;
  *(undefined2 *)(uVar5 + 0xb) = 0;
  *(undefined2 *)(uVar5 + 9) = 0;
  fVar6 = (far_t)LXMUL_at_(0x15,(ulong)StshCount);
  fVar6 = PADD_at_(StshCtPtr,fVar6);
  fVar6 = PADD_at_(fVar6,(far_t)0xffffffd6);
  uVar7 = ovr_mkp(fVar6.ofs,fVar6.seg);
  uVar5 = Stsh_2410_47f6.seg;
  uVar3 = Stsh_2410_47f6.ofs;
  *(undefined2 *)(uVar3 + 0xf) = (int)(uVar7 >> 0x10);
  *(undefined2 *)(uVar3 + 0xd) = (int)uVar7;
  return;
}


