stg_tmp_t * __cdecl16far grabLbm(int16_t file_id,int16_t x,int16_t y,...)

{
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  bool bVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  uint16_t uVar7;
  uint16_t uVar8;
  uint16_t uVar9;
  uint16_t uVar10;
  uint16_t uVar11;
  uint16_t uVar12;
  uint16_t fid;
  int iVar13;
  void *pvVar14;
  uint32_t *puVar15;
  uint16_t uVar16;
  uint16_t ppgfx;
  uint16_t i;
  uint16_t unaff_DI;
  uint16_t unaff_SS;
  bool bVar17;
  stg_tmp_t *dst;
  uint32_t remain;
  uint32_t cmszB;
  far_t src;
  uint8_t cmap [768];
  lbm_bmhd_t hd;
  uint16_t h;
  uint16_t w;
  uint16_t dst_seg;
  bool got_header;
  lbm_type_t lbm_type;
  uint32_t sz;
  uint32_t chnk_sz;
  DW tmp;
  uint16_t IdFORM1;
  uint16_t IdILBM0;
  uint16_t IdILBM1;
  uint16_t IdBMHD1;
  uint16_t IdBMHD0;
  uint16_t IdBODY0;
  uint16_t IdBODY1;
  uint16_t IdCMAP1;
  uint16_t IdCMAP0;
  uint16_t IdPBM_1;
  uint16_t IdPBM_0;
  uint8_t got_hdr;
  
  uVar12 = IdPBM_.hi;
  uVar11 = IdPBM_.lo;
  uVar10 = IdCMAP.hi;
  uVar9 = IdCMAP.lo;
  uVar8 = IdBODY.hi;
  uVar7 = IdBODY.lo;
  uVar6 = IdBMHD.hi;
  uVar5 = IdBMHD.lo;
  uVar4 = IdILBM.hi;
  uVar3 = IdILBM.lo;
  uVar2 = IdFORM.hi;
  uVar16 = IdFORM.lo;
  (*(uint16_t *)((uint8_t *)&(dst) + 2)) = (uint16_t)(stg_tmp_t *)IdPBM_.lo;
  fid = ovr_stshOpen(file_id);
  if ((int)fid < 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x16);
  }
  (*(uint16_t *)((uint8_t *)&(dst))) = ovr_stshAlloc(0x308);
  (*(uint16_t *)((uint8_t *)&(remain) + 2)) = (*(uint16_t *)((uint8_t *)&(dst) + 2));
  _fmemset((void *)ZEXT24((*(uint16_t *)((uint8_t *)&(dst) + 2))),0x308,unaff_DI);
  (*(uint16_t *)((uint8_t *)&(remain))) = ovr_stshRead();
  if ((((int)remain == 0 && (*(uint16_t *)((uint8_t *)&(remain) + 2)) == (stg_tmp_t *)0x0) && (tmp.hi == uVar2)) &&
     (tmp.lo == uVar16)) {
    bVar1 = false;
    ovr_stshRead();
    ovr_stshRead();
    uVar16 = tmp.lo;
    if (((tmp.hi == uVar12) && (tmp.lo == uVar11)) || ((tmp.hi == uVar4 && (tmp.lo == uVar3)))) {
      while (iVar13 = ovr_stshRead(), iVar13 == 0 && uVar16 == 0) {
        if ((tmp.hi == uVar6) && (tmp.lo == uVar5)) {
          bVar1 = true;
          uVar16 = tmp.lo;
          iVar13 = ovr_stshRead();
          if ((iVar13 != 0 || uVar16 != 0) ||
             (((puVar15 = ovr_be4((uint32_t *)sz,CONCAT22(unaff_DI,(*(uint16_t *)((uint8_t *)&(sz) + 2)))), uVar16 != 0 ||
               (puVar15 != (uint32_t *)((byte *)__C0_ASM_CopyRight + 0x10))) ||
              (iVar13 = ovr_stshRead(), iVar13 != 0 || uVar16 != 0)))) break;
          w = ovr_be2(hd.w);
          h = ovr_be2(hd.h);
          (*(uint16_t *)((uint8_t *)&(sz) + 2)) = 0;
          (*(uint16_t *)((uint8_t *)&(sz))) = (uint16_t)(uint32_t *)((byte *)__C0_ASM_CopyRight + 0x10);
        }
        else if ((tmp.hi == uVar10) && (tmp.lo == uVar9)) {
          (*(uint16_t *)((uint8_t *)&(cmszB) + 2)) = tmp.lo;
          ovr_stshRead();
          (*(uint16_t *)((uint8_t *)&(cmszB))) = ovr_be4((uint32_t *)sz,CONCAT22(unaff_DI,(*(uint16_t *)((uint8_t *)&(sz) + 2))));
          (*(uint16_t *)((uint8_t *)&(chnk_sz))) = (uint16_t)(uint32_t *)cmszB;
          (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) = (*(uint16_t *)((uint8_t *)&(cmszB) + 2));
          if (((uint)(uint32_t *)cmszB & 1) != 0) {
            (*(uint16_t *)((uint8_t *)&(chnk_sz))) = (uint16_t)(uint32_t *)((int)(uint32_t *)cmszB + 1);
            (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) = (*(uint16_t *)((uint8_t *)&(cmszB) + 2)) + ((uint32_t *)0xfffe < (uint32_t *)cmszB);
          }
          if (((int)(*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) < 0) ||
             (((*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) == 0 && ((uint32_t *)chnk_sz < (char *)0x300)))) {
            if ((-1 < (int)(*(uint16_t *)((uint8_t *)&(chnk_sz) + 2))) &&
               ((0 < (int)(*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) || ((uint32_t *)chnk_sz != (uint32_t *)0x0)))) {
              ovr_stshRead();
            }
          }
          else {
            ovr_stshRead();
            if ((-1 < (int)(*(uint16_t *)((uint8_t *)&(chnk_sz) + 2))) &&
               ((0 < (int)(*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) || ((char *)0x300 < (uint32_t *)chnk_sz))))
            {
              puVar15 = ovr_stshTell((uint32_t *)fid,unaff_DI);
              ovr_stshSeek(fid,(long)CONCAT22(((int)puVar15 >> 0xf) + (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) +
                                              (uint)CARRY2((uint)puVar15,(uint)(uint32_t *)chnk_sz)
                                              + -1 + (uint)(" \r" < (char *)((int)puVar15 +
                                                                            (int)(uint32_t *)chnk_sz
                                                                            )),
                                              (char *)((int)puVar15 + (int)(uint32_t *)chnk_sz) +
                                              -0x300));
            }
          }
          i = 0;
          while( true ) {
            if ((0 < (int)(*(uint16_t *)((uint8_t *)&(cmszB) + 2))) ||
               ((puVar15 = (uint32_t *)cmszB, uVar16 = (*(uint16_t *)((uint8_t *)&(cmszB) + 2)), (*(uint16_t *)((uint8_t *)&(cmszB) + 2)) == 0 &&
                ((char *)0x300 < (uint32_t *)cmszB)))) {
              puVar15 = (uint32_t *)((char *)0x300);
              uVar16 = 0;
            }
            if (((int)uVar16 < 1) &&
               (((*(uint16_t *)((uint8_t *)&(sz))) = (uint16_t)(uint32_t *)cmszB, (*(uint16_t *)((uint8_t *)&(sz) + 2)) = (*(uint16_t *)((uint8_t *)&(cmszB) + 2)), uVar16 != 0 || (puVar15 <= i)
                ))) break;
            ((stg_tmp_t *)dst)->cmap[i] = (uint8_t)((int)(uint)cmap[i] >> 2);
            i = i + 1;
          }
        }
        else {
          if ((tmp.hi == uVar8) && (tmp.lo == uVar7)) {
            if (bVar1) {
              ovr_stshRead();
              puVar15 = ovr_be4((uint32_t *)sz,CONCAT22(unaff_DI,(*(uint16_t *)((uint8_t *)&(sz) + 2))));
              (*(uint16_t *)((uint8_t *)&(chnk_sz))) = (uint16_t)puVar15;
              (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) = tmp.lo;
              if (((uint)puVar15 & 1) != 0) {
                (*(uint16_t *)((uint8_t *)&(chnk_sz))) = (uint16_t)(uint32_t *)((int)puVar15 + 1);
                (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) = tmp.lo + ((uint32_t *)0xfffe < puVar15);
              }
              pvVar14 = ovr_stshAlloc((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)),(uint32_t *)chnk_sz));
              ovr_stshRead();
              ovr_stshClose(fid);
              src.seg = (uint16_t)(stg_tmp_t *)dst;
              src.ofs = (uint16_t)puVar15;
              lbm_decode_body(hd.enc,hd.nplanes,hd.mask,(uint8_t)pvVar14,src,
                              (stg_tmp_t *)CONCAT22(x,(*(uint16_t *)((uint8_t *)&(dst) + 2))),y,w,h,unaff_DI);
              handle.seg = (uint16_t)puVar15;
              handle.ofs = (uint16_t)pvVar14;
              ovr_stshFree(handle);
              return (stg_tmp_t *)dst;
            }
            break;
          }
          uVar16 = tmp.lo;
          ovr_stshRead();
          (*(uint16_t *)((uint8_t *)&(chnk_sz))) = ovr_be4((uint32_t *)chnk_sz,CONCAT22(unaff_DI,(*(uint16_t *)((uint8_t *)&(chnk_sz) + 2))));
          (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) = uVar16;
          if (((uint)(uint32_t *)chnk_sz & 1) != 0) {
            bVar17 = (uint32_t *)0xfffe < (uint32_t *)chnk_sz;
            (*(uint16_t *)((uint8_t *)&(chnk_sz))) = (uint16_t)(uint32_t *)((int)(uint32_t *)chnk_sz + 1);
            (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) = uVar16 + bVar17;
          }
          puVar15 = ovr_stshTell((uint32_t *)fid,unaff_DI);
          uVar16 = ((int)puVar15 >> 0xf) + (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) +
                   (uint)CARRY2((uint)puVar15,(uint)(uint32_t *)chnk_sz);
          ovr_stshSeek(fid,CONCAT22(uVar16,(int)puVar15 + (int)(uint32_t *)chnk_sz));
        }
      }
    }
  }
                    /* free the pixels pointer at the end */
  if ((&((stg_tmp_t *)dst)->bptr)->ofs != 0 || (((stg_tmp_t *)dst)->bptr).seg != 0) {
    handle_00.seg = (((stg_tmp_t *)dst)->bptr).seg;
    handle_00.ofs = (&((stg_tmp_t *)dst)->bptr)->ofs;
    ovr_stshFree(handle_00);
  }
  ovr_stshClose(fid);
  handle_01.seg = (uint16_t)(*(uint16_t *)((uint8_t *)&(dst) + 2));
  handle_01.ofs = (uint16_t)(stg_tmp_t *)dst;
  ovr_stshFree(handle_01);
  printf("Filename %d %s  \r");
  ovr_biosReadKey();
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0xd);
}
