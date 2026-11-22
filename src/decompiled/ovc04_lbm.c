/*
 * ovc04_lbm.c - recovered from STRONG.EXE
 * memory block: OVC04_lbm.c
 * range: 30e6:0000 - 30e6:081f
 * functions: 4
 */
#include "recovered.h"


/* 30e6:0000 */

/* Aligns pointer up to 16 bytes */

uint16_t __cdecl16far alignToSeg(far_t ptr,...)

{
  return 0;
}



/* 30e6:0001 */

uint16_t __cdecl16far sub_OVC04_0001()

{
  return 0;
}



/* 30e6:0024 */
void __cdecl16far
lbm_decode_body(lbm_type_t format,int8_t encoding,uint8_t nplanes,uint8_t mask,far_t src,
               stg_tmp_t *dst,int16_t sx,int16_t sy,int16_t w,int16_t h)

{
  long lVar1;
  far_t dst_00;
  far_t dst_01;
  far_t src_00;
  far_t dst_02;
  far_t dst_03;
  far_t ptr;
  far_t handle;
  far_t handle_00;
  far_t ptr_base;
  far_t ptr_ofs;
  uint16_t uVar2;
  uint16_t written;
  uint32_t *__return_storage_ptr__;
  uint16_t t;
  uint16_t unaff_SI;
  uint uVar3;
  int16_t y;
  uint16_t unaff_DI;
  word len;
  uint16_t dseg;
  uint16_t uVar4;
  uint32_t buf;
  far_t dstline;
  far_t bsrcline;
  char *srcline;
  char in_stack_00000004;
  undefined1 in_stack_0000000d;
  far_t src_01;
  far_t src_02;
  undefined1 uVar5;
  undefined1 uVar6;
  uint16_t uVar7;
  uint16_t x;
  uint16_t npixels;
  uint16_t plane_sz;
  uint16_t dst_ofs;
  uint16_t src_ofs;
  uint16_t src_seg;
  uint16_t pdst;
  uint16_t ofs_inc;
  uint16_t src_ofsS;
  uint16_t src_segS;
  uint16_t dst_seg;
  
  (*(uint16_t *)((uint8_t *)&(buf))) = ovr_stshAlloc(0xfa0f);
  *(uint16_t *)(src.seg + 0x306) = (*(uint16_t *)((uint8_t *)&(buf) + 2));
  *(uint16_t *)(src.seg + 0x304) = (uint16_t)(void *)buf;   /* hand fix: 2-byte slot */
  ptr.seg = *(uint16_t *)(src.seg + 0x306);
  ptr.ofs = *(uint16_t *)(src.seg + 0x304);
  uVar2 = alignToSeg(ptr);
  *(uint16_t *)(src.seg + 0x302) = (*(uint16_t *)((uint8_t *)&(buf) + 2));
  *(uint16_t *)(src.seg + 0x300) = uVar2;
  _fmemset((void *)(ulong)*(uint *)(src.seg + 0x302),64000,unaff_DI);
  uVar2 = *(uint16_t *)(src.seg + 0x302);
  dst_ofs = *(uint16_t *)(src.seg + 0x300);
  if (((((format == LBM_PBM) || (in_stack_00000004 != '\0')) || ((*(uint16_t *)((uint8_t *)&(dst) + 2)) != 0)) ||
      ((sx != 0 || (0x140 < (uint)sy)))) || (encoding != '\b')) {
    if (in_stack_00000004 == '\0') {
      plane_sz = sy;
      lVar1 = CONCAT22(dst_ofs,sy);
    }
    else {
      plane_sz = (sy + 0xfU >> 4) * 2;
      lVar1 = (long)(int)plane_sz * (long)(int)(uint)(byte)encoding;
      if ((in_stack_00000004 != '\0') && ((nplanes & 1) != 0)) {
        lVar1 = CONCAT22((int)((ulong)lVar1 >> 0x10),(int)lVar1 + plane_sz);
      }
    }
    dstline.seg = (uint16_t)((ulong)lVar1 >> 0x10);
    len = (word)lVar1;
    dstline.ofs = (uint16_t)ovr_stshAlloc((ulong)(len + 0x80));
    uVar7 = 0;
    uVar4 = 0x2337;
    bsrcline.seg = dstline.seg;
    bsrcline.ofs = (uint16_t)ovr_stshAlloc((ulong)(len + 0x80));
    if (DebugVerbose != false) {
      printf("N %d W %u s %u \r");
      uVar7 = 0x1000;
      uVar4 = 0x22a6;
      ovr_biosReadKey();
    }
    if ((long)dst < 0) {
      dst_ofs = dst_ofs - (*(uint16_t *)((uint8_t *)&(dst) + 2));
      npixels = (*(uint16_t *)((uint8_t *)&(dst) + 2)) + 0x140;
      x = 0;
    }
    else {
      npixels = 0x140;
      x = (*(uint16_t *)((uint8_t *)&(dst) + 2));
    }
    if ((uint)sy < npixels + x) {
      npixels = sy - x;
    }
    if (npixels != 0) {
      for (y = 0; ((uint)y < (uint)w && (y - sx < 200)); y = y + 1) {
        ptr_base.seg = unaff_SI;
        ptr_base.ofs = uVar4;
        ptr_ofs.seg = x;
        ptr_ofs.ofs = unaff_SI;
        *(far_t far *)&srcline = PADD_at_(ptr_base,ptr_ofs);   /* hand fix: PADD_at_ returns a far_t struct; assign the 4 bytes through the pointer */
        uVar5 = (undefined1)dstline.seg;
        uVar6 = (undefined1)(dstline.seg >> 8);
        if (format == LBM_PBM) {
          uVar4 = 0x1000;
          _fmemmove((char *)CONCAT22(dstline.seg,dstline.ofs),srcline,len);
        }
        else {
          uVar4 = 0x22a6;
          (*(uint8_t *)((uint8_t *)&(dst_02.seg))) = uVar5;
          dst_02.ofs = dstline.ofs;
          (*(uint8_t *)((uint8_t *)&(dst_02.seg) + 1)) = uVar6;
          ovr_unrle(far_from_u32((uint32_t)(srcline)),dst_02,len,uVar5,uVar7);
        }
        if (sx <= y) {
          if (in_stack_00000004 == '\0') {
            uVar4 = 0x1000;
            _fmemmove((char *)CONCAT22(uVar2,dst_ofs),
                      (char *)CONCAT13(uVar6,CONCAT12(uVar5,dstline.ofs + x)),npixels);
          }
          else if (x == 0) {
            src_01.seg = dstline.seg;
            src_01.ofs = dstline.ofs;
            uVar4 = 0x22a6;
            dst_00.seg = uVar2;
            dst_00.ofs = dst_ofs;
            ovr_lbm_combine_bitplanes(src_01,dst_00,npixels,encoding,plane_sz,encoding);
          }
          else {
            src_02.seg = dstline.seg;
            src_02.ofs = dstline.ofs;
            dst_01.seg = bsrcline.seg;
            dst_01.ofs = bsrcline.ofs;
            ovr_lbm_combine_bitplanes(src_02,dst_01,sy,encoding,plane_sz,encoding);
            uVar4 = 0x1000;
            _fmemmove((char *)CONCAT22(uVar2,dst_ofs),
                      (char *)CONCAT13((char)(bsrcline.seg >> 8),
                                       CONCAT12((char)bsrcline.seg,bsrcline.ofs + x)),npixels);
          }
          dst_ofs = dst_ofs + 0x140;
        }
      }
      handle.seg = dstline.seg;
      handle.ofs = dstline.ofs;
      ovr_stshFree(handle);
      handle_00.seg = bsrcline.seg;
      handle_00.ofs = bsrcline.ofs;
      ovr_stshFree(handle_00);
    }
  }
  else {
    src_seg = src.ofs;
    src_ofs = mask;
    if (200 < (uint)w) {
      w = 200;
    }
    for (uVar3 = 0; uVar3 < (uint)w; uVar3 = uVar3 + 1) {
      src_00.seg = src_seg;
      src_00.ofs = src_ofs;
      dst_03.seg = uVar2;
      dst_03.ofs = dst_ofs;
      written = ovr_unrle(src_00,dst_03,0x140,(char)dst_ofs);
      __return_storage_ptr__ = (uint32_t *)(src_ofs + written);
      src_ofs = (uint16_t)ovr_mkp(__return_storage_ptr__,src_seg,unaff_DI);
      dst_ofs = dst_ofs + 0x140;
      src_seg = (uint16_t)__return_storage_ptr__;
    }
  }
  return;
}


/* 30e6:0321 */
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

