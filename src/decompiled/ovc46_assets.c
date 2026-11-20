/*
 * ovc46_assets.c - recovered from STRONG.EXE
 * memory block: OVC46_assets.c
 * range: 7a57:0000 - 7a57:424f
 * functions: 1
 */
#include "recovered.h"


/* 7a57:0000 */

void __cdecl16far init_assets1(bool grab,...)

{
  stg_tmp_t *psVar1;
  far_t *pfVar2;
  stg_tmp_t *psVar3;
  stg_tmp_t *in_DX;
  uint16_t uVar4;
  uint16_t uVar5;
  stg_tmp_t *psVar6;
  uint8_t *puVar7;
  uint8_t *puVar8;
  stg_tmp_t *psVar9;
  uint16_t unaff_SI;
  char in_stack_00000004;
  stg_tmp_t *psVar10;
  int16_t iVar12;
  uint8_t *puVar11;
  
  if (in_stack_00000004 == '\0') {
    ovr_stshStubifyBld();
  }
  else {
    psVar3 = ovr_grabLbmTR();
    psVar6 = in_DX;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7e001b)),110,176,0,-6,unaff_SI,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar6);
    BldGfxNormal[0x201].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x201].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7e0076)),201,176,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x202].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x202].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7e00d1)),292,176,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x203].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x203].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x45001b)),110,119,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x204].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x204].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x450076)),201,119,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x205].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x205].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4500d1)),292,119,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x206].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x206].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0xb001b)),110,61,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x207].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x207].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0xb0076)),201,61,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x208].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x208].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0xb00d1)),292,61,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x209].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar1 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),in_DX);
    BldGfxNormal[0x209].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar1;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7e001b)),110,176,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x201].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x201].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7e0076)),201,176,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x202].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x202].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7e00d1)),292,176,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x203].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x203].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x45001b)),110,119,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x204].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x204].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x450076)),201,119,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x205].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x205].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4500d1)),292,119,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x206].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x206].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0xb001b)),110,61,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x207].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x207].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0xb0076)),201,61,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x208].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x208].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0xb00d1)),292,61,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x209].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    in_DX = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar1);
    BldGfxRuin[0x209].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  if (in_stack_00000004 == '\0') {
    ovr_stshStubifyBld();
  }
  else {
    psVar3 = ovr_grabLbmTR();
    psVar6 = in_DX;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x820002)),95,180,0,-6,unaff_SI,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar6);
    BldGfxNormal[0x20a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x20a].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x82006c)),191,180,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x20b].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x20b].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x8200cc)),298,180,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x20c].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x20c].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x460002)),95,120,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x20d].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x20d].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x46006c)),191,120,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x20e].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x20e].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4600cc)),298,120,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x20f].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x20f].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x90002)),95,59,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x210].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x210].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x9006c)),191,59,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x211].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x211].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x900cc)),298,59,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x212].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar1 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),in_DX);
    BldGfxNormal[0x212].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar1;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x820002)),95,180,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x20a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x20a].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x82006c)),191,180,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x20b].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x20b].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x8200cc)),298,180,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x20c].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x20c].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x460002)),95,120,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x20d].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x20d].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x46006c)),191,120,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x20e].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x20e].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4600cc)),298,120,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x20f].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x20f].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x90002)),95,59,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x210].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x210].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x9006c)),191,59,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x211].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x211].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x900cc)),298,59,0,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x212].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    in_DX = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar1);
    BldGfxRuin[0x212].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  if (in_stack_00000004 == '\0') {
    ovr_stshStubifyBld();
  }
  else {
    psVar3 = ovr_grabLbmTR();
    psVar6 = in_DX;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7e001b)),110,176,-10,-6,unaff_SI,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar6);
    BldGfxNormal[0x213].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x213].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7e0076)),201,176,-10,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x214].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x214].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7e00d1)),292,176,-10,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x215].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x215].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x45001b)),110,119,-10,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x216].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x216].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x450076)),201,119,-10,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x217].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x217].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4500d1)),292,119,-10,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x218].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x218].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x1001b)),110,61,-10,4,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x219].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x219].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x10076)),201,61,-10,4,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x21a].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x21a].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x100d1)),292,61,-10,4,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x21b].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar1 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),in_DX);
    BldGfxNormal[0x21b].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar1;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7e001b)),110,176,-10,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x213].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x213].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7e0076)),201,176,-10,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x214].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x214].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7e00d1)),292,176,-10,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x215].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x215].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x45001b)),110,119,-10,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x216].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x216].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x450076)),201,119,-10,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x217].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x217].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4500d1)),292,119,-10,-6,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x218].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x218].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x1001b)),110,61,-10,4,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x219].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x219].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x10076)),201,61,-10,4,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x21a].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x21a].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x100d1)),292,61,-10,4,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x21b].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    in_DX = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar1);
    BldGfxRuin[0x21b].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  if (in_stack_00000004 == '\0') {
    ovr_stshStubifyBld();
  }
  else {
    ovr_grabBldLbm(474,180,unaff_SI,0x1d9);
  }
  if (in_stack_00000004 == '\0') {
    BldGfxNormal[0x225].ofs = (uint16_t)ovr_stshAllocStub();
    uVar4 = 0x195d;
    BldGfxNormal[0x225].seg = (uint16_t)in_DX;
    BldGfxNormal[0x226].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxNormal[0x226].seg = uVar4;
    BldGfxNormal[0x227].ofs = (uint16_t)ovr_stshAllocStub();
    uVar4 = 0x195d;
    BldGfxNormal[0x227].seg = uVar5;
    BldGfxRuin[0x225].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxRuin[0x225].seg = uVar4;
    BldGfxRuin[0x226].ofs = (uint16_t)ovr_stshAllocStub();
    uVar4 = 0x195d;
    BldGfxRuin[0x226].seg = uVar5;
    BldGfxRuin[0x227].ofs = (uint16_t)ovr_stshAllocStub();
    psVar6 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x227].seg = uVar4;
  }
  else {
    psVar3 = ovr_grabLbmTR();
    psVar6 = in_DX;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4b0002)),85,115,0,-15,unaff_SI,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar6);
    BldGfxNormal[0x225].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x225].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4b006c)),191,115,0,-15,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x226].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x226].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4b00d7)),298,115,0,-15,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x227].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar1 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),in_DX);
    BldGfxNormal[0x227].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar1;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4b0002)),85,115,0,-15,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x225].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x225].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4b006c)),191,115,0,-15,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x226].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x226].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4b00d7)),298,115,0,-15,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x227].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar6 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar1);
    BldGfxRuin[0x227].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  if (in_stack_00000004 == '\0') {
    BldGfxNormal[0x229].ofs = (uint16_t)ovr_stshAllocStub();
    uVar4 = 0x195d;
    BldGfxNormal[0x229].seg = (uint16_t)psVar6;
    BldGfxRuin[0x229].ofs = (uint16_t)ovr_stshAllocStub();
    BldGfxRuin[0x229].seg = uVar4;
  }
  else {
    psVar1 = ovr_grabLbmTR();
    psVar3 = psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x32006c)),191,115,-4,9,unaff_SI,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar3);
    BldGfxNormal[0x229].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    psVar9 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)psVar10 >> 0x10),psVar6);
    BldGfxNormal[0x229].seg = (uint16_t)psVar3;
    ovr_stgFreeTmp(psVar10,psVar1);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar9;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x32006c)),191,115,-4,9,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x229].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)psVar10 >> 0x10),psVar9);
    BldGfxRuin[0x229].seg = (uint16_t)psVar6;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  BldGfxNormal[0x228].seg = BldGfxNormal[0x229].seg;
  BldGfxNormal[0x228].ofs = BldGfxNormal[0x229].ofs;
  BldGfxNormal[0x22a].seg = BldGfxNormal[0x229].seg;
  BldGfxNormal[0x22a].ofs = BldGfxNormal[0x229].ofs;
  BldGfxRuin[0x228].seg = BldGfxRuin[0x229].seg;
  BldGfxRuin[0x228].ofs = BldGfxRuin[0x229].ofs;
  BldGfxRuin[0x22a].seg = BldGfxRuin[0x229].seg;
  BldGfxRuin[0x22a].ofs = BldGfxRuin[0x229].ofs;
  psVar6 = (stg_tmp_t *)BldGfxRuin[0x229].seg;
  ovr_stshStubifyFromSrc(0xb9,unaff_SI,0xb8);
  ovr_stshStubifyFromSrc(0xba,unaff_SI,0xb8);
  ovr_stshStubifyFromSrc(0xbb,unaff_SI,0xb8);
  ovr_stshStubifyFromSrc(0xbc,unaff_SI,0xb8);
  ovr_stshStubifyFromSrc(0xbd,unaff_SI,0xb8);
  ovr_stshStubifyFromSrc(0xbe,unaff_SI,0xb8);
  if (in_stack_00000004 == '\0') {
    BldGfxNormal[0x23e].ofs = (uint16_t)ovr_stshAllocStub();
    uVar4 = 0x195d;
    BldGfxNormal[0x23e].seg = (uint16_t)psVar6;
    BldGfxNormal[0x241].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxNormal[0x241].seg = uVar4;
    BldGfxNormal[0x244].ofs = (uint16_t)ovr_stshAllocStub();
    uVar4 = 0x195d;
    BldGfxNormal[0x244].seg = uVar5;
    BldGfxRuin[0x23e].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxRuin[0x23e].seg = uVar4;
    BldGfxRuin[0x241].ofs = (uint16_t)ovr_stshAllocStub();
    uVar4 = 0x195d;
    BldGfxRuin[0x241].seg = uVar5;
    BldGfxRuin[0x244].ofs = (uint16_t)ovr_stshAllocStub();
    BldGfxRuin[0x244].seg = uVar4;
  }
  else {
    psVar1 = ovr_grabLbmTR();
    psVar3 = psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x97006e)),185,180,-8,-26,unaff_SI,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar3);
    BldGfxNormal[0x23e].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x23e].seg = (uint16_t)psVar3;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x48006e)),185,115,-8,-12,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x241].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x241].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x6006e)),185,59,-8,-2,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x244].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar9 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar6);
    BldGfxNormal[0x244].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar1);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar9;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x97006e)),185,180,-8,-26,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x23e].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x23e].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x48006e)),185,115,-8,-12,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x241].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x241].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x6006e)),185,59,-8,-2,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x244].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar9);
    BldGfxRuin[0x244].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  BldGfxNormal[0x23d].seg = BldGfxNormal[0x23e].seg;
  BldGfxNormal[0x23d].ofs = BldGfxNormal[0x23e].ofs;
  BldGfxNormal[0x23f].seg = BldGfxNormal[0x23e].seg;
  BldGfxNormal[0x23f].ofs = BldGfxNormal[0x23e].ofs;
  BldGfxNormal[0x240].seg = BldGfxNormal[0x241].seg;
  BldGfxNormal[0x240].ofs = BldGfxNormal[0x241].ofs;
  BldGfxNormal[0x242].seg = BldGfxNormal[0x241].seg;
  BldGfxNormal[0x242].ofs = BldGfxNormal[0x241].ofs;
  BldGfxNormal[0x243].seg = BldGfxNormal[0x244].seg;
  BldGfxNormal[0x243].ofs = BldGfxNormal[0x244].ofs;
  BldGfxNormal[0x245].seg = BldGfxNormal[0x244].seg;
  BldGfxNormal[0x245].ofs = BldGfxNormal[0x244].ofs;
  BldGfxRuin[0x23d].seg = BldGfxRuin[0x23e].seg;
  BldGfxRuin[0x23d].ofs = BldGfxRuin[0x23e].ofs;
  BldGfxRuin[0x23f].seg = BldGfxRuin[0x23e].seg;
  BldGfxRuin[0x23f].ofs = BldGfxRuin[0x23e].ofs;
  BldGfxRuin[0x240].seg = BldGfxRuin[0x241].seg;
  BldGfxRuin[0x240].ofs = BldGfxRuin[0x241].ofs;
  BldGfxRuin[0x242].seg = BldGfxRuin[0x241].seg;
  BldGfxRuin[0x242].ofs = BldGfxRuin[0x241].ofs;
  BldGfxRuin[0x243].seg = BldGfxRuin[0x244].seg;
  BldGfxRuin[0x243].ofs = BldGfxRuin[0x244].ofs;
  BldGfxRuin[0x245].seg = BldGfxRuin[0x244].seg;
  BldGfxRuin[0x245].ofs = BldGfxRuin[0x244].ofs;
  if (in_stack_00000004 == '\0') {
    uVar4 = BldGfxRuin[0x244].seg;
    BldGfxNormal[0x247].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxNormal[0x247].seg = uVar4;
    BldGfxRuin[0x247].ofs = (uint16_t)ovr_stshAllocStub();
    BldGfxRuin[0x247].seg = uVar5;
  }
  else {
    psVar6 = (stg_tmp_t *)BldGfxRuin[0x244].seg;
    psVar1 = ovr_grabLbmTR();
    psVar3 = psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x7c006b)),191,183,0,3,unaff_SI,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar3);
    BldGfxNormal[0x247].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    psVar9 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)psVar10 >> 0x10),psVar6);
    BldGfxNormal[0x247].seg = (uint16_t)psVar3;
    ovr_stgFreeTmp(psVar10,psVar1);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar9;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7c006b)),191,183,0,3,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x247].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)psVar10 >> 0x10),psVar9);
    BldGfxRuin[0x247].seg = (uint16_t)psVar6;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  BldGfxNormal[0x246].seg = BldGfxNormal[0x247].seg;
  BldGfxNormal[0x246].ofs = BldGfxNormal[0x247].ofs;
  BldGfxNormal[0x248].seg = BldGfxNormal[0x247].seg;
  BldGfxNormal[0x248].ofs = BldGfxNormal[0x247].ofs;
  BldGfxRuin[0x246].seg = BldGfxRuin[0x247].seg;
  BldGfxRuin[0x246].ofs = BldGfxRuin[0x247].ofs;
  BldGfxRuin[0x248].seg = BldGfxRuin[0x247].seg;
  BldGfxRuin[0x248].ofs = BldGfxRuin[0x247].ofs;
  if (in_stack_00000004 == '\0') {
    uVar4 = BldGfxRuin[0x247].seg;
    BldGfxNormal[0x24a].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxNormal[0x24a].seg = uVar4;
    BldGfxRuin[0x24a].ofs = (uint16_t)ovr_stshAllocStub();
    BldGfxRuin[0x24a].seg = uVar5;
  }
  else {
    psVar6 = (stg_tmp_t *)BldGfxRuin[0x247].seg;
    psVar1 = ovr_grabLbmTR();
    psVar3 = psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x7e006b)),191,166,0,-15,unaff_SI,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar3);
    BldGfxNormal[0x24a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    psVar9 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)psVar10 >> 0x10),psVar6);
    BldGfxNormal[0x24a].seg = (uint16_t)psVar3;
    ovr_stgFreeTmp(psVar10,psVar1);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar9;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7e006b)),191,166,0,-15,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x24a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)psVar10 >> 0x10),psVar9);
    BldGfxRuin[0x24a].seg = (uint16_t)psVar6;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  BldGfxNormal[0x249].seg = BldGfxNormal[0x24a].seg;
  BldGfxNormal[0x249].ofs = BldGfxNormal[0x24a].ofs;
  BldGfxNormal[0x24b].seg = BldGfxNormal[0x24a].seg;
  BldGfxNormal[0x24b].ofs = BldGfxNormal[0x24a].ofs;
  BldGfxRuin[0x249].seg = BldGfxRuin[0x24a].seg;
  BldGfxRuin[0x249].ofs = BldGfxRuin[0x24a].ofs;
  BldGfxRuin[0x24b].seg = BldGfxRuin[0x24a].seg;
  BldGfxRuin[0x24b].ofs = BldGfxRuin[0x24a].ofs;
  if (in_stack_00000004 == '\0') {
    psVar6 = (stg_tmp_t *)BldGfxRuin[0x24a].seg;
    ovr_stshStubifyBld();
  }
  else {
    psVar6 = (stg_tmp_t *)BldGfxRuin[0x24a].seg;
    psVar1 = ovr_grabLbmTR();
    psVar3 = psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x91000d)),99,187,0,-16,unaff_SI,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar3);
    BldGfxNormal[0x24c].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x24c].seg = (uint16_t)psVar3;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x91006c)),195,187,0,-16,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x24d].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x24d].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x9100cc)),292,187,0,-16,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x24e].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x24e].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x4e000d)),99,134,0,-2,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x24f].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x24f].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x4e006c)),195,134,0,-2,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x250].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x250].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x4e00cc)),292,134,0,-2,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x251].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x251].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x1000d)),99,62,0,3,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x252].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x252].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x1006c)),195,62,0,3,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x253].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x253].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x100cc)),292,62,0,3,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x254].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar9 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar6);
    BldGfxNormal[0x254].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar1);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar9;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x91000d)),99,187,0,-16,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x24c].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x24c].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x91006c)),195,187,0,-16,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x24d].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x24d].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x9100cc)),292,187,0,-16,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x24e].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x24e].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4e000d)),99,134,0,-2,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x24f].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x24f].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4e006c)),195,134,0,-2,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x250].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x250].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4e00cc)),292,134,0,-2,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x251].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x251].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x1000d)),99,62,0,3,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x252].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x252].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x1006c)),195,62,0,3,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x253].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x253].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x100cc)),292,62,0,3,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x254].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar6 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar9);
    BldGfxRuin[0x254].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  if (in_stack_00000004 == '\0') {
    BldGfxNormal[0x256].ofs = (uint16_t)ovr_stshAllocStub();
    uVar4 = 0x195d;
    BldGfxNormal[0x256].seg = (uint16_t)psVar6;
    BldGfxRuin[0x256].ofs = (uint16_t)ovr_stshAllocStub();
    BldGfxRuin[0x256].seg = uVar4;
  }
  else {
    psVar1 = ovr_grabLbmTR();
    psVar3 = psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x3b0047)),238,129,-10,1,unaff_SI,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar3);
    BldGfxNormal[0x256].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    psVar9 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)psVar10 >> 0x10),psVar6);
    BldGfxNormal[0x256].seg = (uint16_t)psVar3;
    ovr_stgFreeTmp(psVar10,psVar1);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar9;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x3b0047)),238,129,-10,1,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x256].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)psVar10 >> 0x10),psVar9);
    BldGfxRuin[0x256].seg = (uint16_t)psVar6;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  BldGfxNormal[0x255].seg = BldGfxNormal[0x256].seg;
  BldGfxNormal[0x255].ofs = BldGfxNormal[0x256].ofs;
  BldGfxNormal[599].seg = BldGfxNormal[0x256].seg;
  BldGfxNormal[599].ofs = BldGfxNormal[0x256].ofs;
  BldGfxRuin[0x255].seg = BldGfxRuin[0x256].seg;
  BldGfxRuin[0x255].ofs = BldGfxRuin[0x256].ofs;
  BldGfxRuin[599].seg = BldGfxRuin[0x256].seg;
  BldGfxRuin[599].ofs = BldGfxRuin[0x256].ofs;
  if (in_stack_00000004 == '\0') {
    uVar4 = BldGfxRuin[0x256].seg;
    BldGfxNormal[0x259].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxNormal[0x259].seg = uVar4;
    BldGfxNormal[0x25c].ofs = (uint16_t)ovr_stshAllocStub();
    uVar4 = 0x195d;
    BldGfxNormal[0x25c].seg = uVar5;
    BldGfxNormal[0x25f].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxNormal[0x25f].seg = uVar4;
    BldGfxRuin[0x259].ofs = (uint16_t)ovr_stshAllocStub();
    uVar4 = 0x195d;
    BldGfxRuin[0x259].seg = uVar5;
    BldGfxRuin[0x25c].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxRuin[0x25c].seg = uVar4;
    BldGfxRuin[0x25f].ofs = (uint16_t)ovr_stshAllocStub();
    psVar6 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x25f].seg = uVar5;
  }
  else {
    psVar6 = (stg_tmp_t *)BldGfxRuin[0x256].seg;
    psVar1 = ovr_grabLbmTR();
    psVar3 = psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x760009)),92,183,0,9,unaff_SI,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar3);
    BldGfxNormal[0x259].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x259].seg = (uint16_t)psVar3;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x76006c)),191,183,0,9,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x25c].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x25c].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x7600cf)),291,183,0,9,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x25f].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar9 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar6);
    BldGfxNormal[0x25f].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar1);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar9;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x760009)),92,183,0,9,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x259].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x259].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x76006c)),191,183,0,9,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x25c].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x25c].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x7600cf)),291,183,0,9,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x25f].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar6 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar9);
    BldGfxRuin[0x25f].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  ovr_stshStubifyCopy1to0();
  if (in_stack_00000004 == '\0') {
    BldGfxNormal[0x262].ofs = (uint16_t)ovr_stshAllocStub();
    uVar4 = 0x195d;
    BldGfxNormal[0x262].seg = (uint16_t)psVar6;
    BldGfxNormal[0x265].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxNormal[0x265].seg = uVar4;
    BldGfxNormal[0x268].ofs = (uint16_t)ovr_stshAllocStub();
    uVar4 = 0x195d;
    BldGfxNormal[0x268].seg = uVar5;
    BldGfxRuin[0x262].ofs = (uint16_t)ovr_stshAllocStub();
    uVar5 = 0x195d;
    BldGfxRuin[0x262].seg = uVar4;
    BldGfxRuin[0x265].ofs = (uint16_t)ovr_stshAllocStub();
    uVar4 = 0x195d;
    BldGfxRuin[0x265].seg = uVar5;
    BldGfxRuin[0x268].ofs = (uint16_t)ovr_stshAllocStub();
    psVar6 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x268].seg = uVar4;
  }
  else {
    psVar1 = ovr_grabLbmTR();
    psVar3 = psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x8c0002)),85,180,0,-15,unaff_SI,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar3);
    BldGfxNormal[0x262].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x262].seg = (uint16_t)psVar3;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x4b0002)),85,115,0,-15,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x265].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x265].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x130002)),85,59,0,-15,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x268].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar9 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar6);
    BldGfxNormal[0x268].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar1);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar9;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x8c0002)),85,180,0,-15,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x262].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x262].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4b0002)),85,115,0,-15,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x265].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x265].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x130002)),85,59,0,-15,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x268].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar6 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar9);
    BldGfxRuin[0x268].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  ovr_stshStubifyCopy1to0();
  if (in_stack_00000004 == '\0') {
    ovr_stshStubifyBld();
  }
  else {
    psVar1 = ovr_grabLbmTR();
    psVar3 = psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x850002)),93,179,0,-9,unaff_SI,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar3);
    BldGfxNormal[0x26a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x26a].seg = (uint16_t)psVar3;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x85006b)),192,179,0,-9,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x26b].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x26b].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x8500d7)),304,179,0,-9,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x26c].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x26c].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x440002)),93,114,0,-9,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x26d].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x26d].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x44006b)),192,114,0,-9,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x26e].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x26e].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x4400d7)),304,114,0,-9,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x26f].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x26f].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0xc0002)),93,58,0,-9,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x270].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x270].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0xc006b)),192,58,0,-9,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x271].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x271].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0xc00d7)),304,58,0,-9,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x272].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar9 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar6);
    BldGfxNormal[0x272].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar1);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar9;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x850002)),93,179,0,-9,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x26a].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x26a].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x85006b)),192,179,0,-9,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x26b].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x26b].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x8500d7)),304,179,0,-9,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x26c].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x26c].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x440002)),93,114,0,-9,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x26d].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x26d].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x44006b)),192,114,0,-9,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x26e].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x26e].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4400d7)),304,114,0,-9,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x26f].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x26f].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0xc0002)),93,58,0,-9,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x270].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x270].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0xc006b)),192,58,0,-9,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x271].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x271].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0xc00d7)),304,58,0,-9,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x272].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar6 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar9);
    BldGfxRuin[0x272].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  if (in_stack_00000004 == '\0') {
    ovr_stshStubifyBld();
  }
  else {
    psVar1 = ovr_grabLbmTR();
    psVar3 = psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x8c0002)),85,180,-3,-14,unaff_SI,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar3);
    BldGfxNormal[0x273].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x273].seg = (uint16_t)psVar3;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x8c006c)),191,180,-3,-14,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x274].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x274].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x8c00d7)),298,180,-3,-14,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x275].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x275].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x4b0002)),85,115,-3,-14,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x276].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x276].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x4b006c)),191,115,-3,-14,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x277].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x277].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x4b00d7)),298,115,-3,-14,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x278].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x278].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x130002)),85,59,-3,-14,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x279].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x279].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x13006c)),191,59,-3,-14,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x27a].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x27a].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x1300d7)),298,59,-3,-14,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x27b].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar9 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar6);
    BldGfxNormal[0x27b].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar1);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar9;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x8c0002)),85,180,-3,-14,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x273].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x273].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x8c006c)),191,180,-3,-14,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x274].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x274].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x8c00d7)),298,180,-3,-14,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x275].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x275].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4b0002)),85,115,-3,-14,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x276].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x276].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4b006c)),191,115,-3,-14,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x277].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x277].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4b00d7)),298,115,-3,-14,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x278].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x278].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x130002)),85,59,-3,-14,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x279].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x279].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x13006c)),191,59,-3,-14,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x27a].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x27a].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x1300d7)),298,59,-3,-14,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x27b].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar6 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar9);
    BldGfxRuin[0x27b].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  if (in_stack_00000004 == '\0') {
    ovr_stshStubifyBld();
  }
  else {
    psVar1 = ovr_grabLbmTR();
    psVar3 = psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x850002)),85,192,-10,5,unaff_SI,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(unaff_SI,psVar3);
    BldGfxNormal[0x27c].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x27c].seg = (uint16_t)psVar3;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x85006c)),191,192,-10,5,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x27d].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x27d].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x8500d7)),298,192,-10,5,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x27e].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x27e].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x490002)),85,132,-10,5,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x27f].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x27f].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x49006c)),191,132,-10,5,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x280].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x280].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x4900d7)),298,132,-10,5,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x281].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x281].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0xd0002)),85,72,-10,5,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x282].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x282].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0xd006c)),191,72,-10,5,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxNormal[0x283].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxNormal[0x283].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0xd00d7)),298,72,-10,5,iVar12,
                              (int16_t)psVar1,(&psVar1->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxNormal[0x284].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar9 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar6);
    BldGfxNormal[0x284].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar1);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    psVar3 = ovr_grabLbmTR();
    psVar6 = psVar9;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x850002)),85,192,-10,5,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    psVar10 = (stg_tmp_t *)CONCAT22(iVar12,psVar6);
    BldGfxRuin[0x27c].ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)psVar10,pfVar2);
    iVar12 = (int16_t)((ulong)psVar10 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x27c].seg = (uint16_t)psVar6;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x85006c)),191,192,-10,5,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x27d].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x27d].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x8500d7)),298,192,-10,5,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x27e].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x27e].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x490002)),85,132,-10,5,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x27f].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x27f].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x49006c)),191,132,-10,5,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x280].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x280].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0x4900d7)),298,132,-10,5,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x281].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x281].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0xd0002)),85,72,-10,5,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x282].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar7 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x282].seg = (uint16_t)puVar8;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0xd006c)),191,72,-10,5,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar7);
    BldGfxRuin[0x283].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    iVar12 = (int16_t)((ulong)puVar11 >> 0x10);
    puVar8 = (uint8_t *)&AgntAnms[0x88].missileDy;
    BldGfxRuin[0x283].seg = (uint16_t)puVar7;
    pfVar2 = ovr_stshRleType2((far_t *)(psVar3->aptr).seg,far_from_u32((uint32_t)(0xd00d7)),298,72,-10,5,iVar12,
                              (int16_t)psVar3,(&psVar3->aptr)->ofs);
    puVar11 = (uint8_t *)CONCAT22(iVar12,puVar8);
    BldGfxRuin[0x284].ofs = (uint16_t)ovr_stshStoreFile(puVar11,pfVar2);
    psVar10 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar11 >> 0x10),psVar9);
    BldGfxRuin[0x284].seg = (uint16_t)puVar8;
    ovr_stgFreeTmp(psVar10,psVar3);
    unaff_SI = (uint16_t)((ulong)psVar10 >> 0x10);
  }
  if (in_stack_00000004 == '\0') {
    ovr_stshStubifyBld();
  }
  else {
    ovr_grabBldLbm(507,215,unaff_SI,0x1fa);
  }
  return;
}


