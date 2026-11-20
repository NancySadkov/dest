/*
 * ovc04.c - recovered from STRONG.EXE
 * memory block: OVC04
 * range: 30e6:0000 - 30e6:081f
 * functions: 3
 */
#include "recovered.h"


/* 30e6:0000 */

/* Aligns pointer up to 16 bytes */

uint16_t __cdecl16far alignToSeg(far_t ptr)

{
  return 0;
}



/* 30e6:0024 */

/* WARNING: Variable defined which should be unmapped: x */

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
  uint in_stack_0000001a;
  far_t src_01;
  far_t src_02;
  undefined1 uVar5;
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
  (dst->bptr).seg = (*(uint16_t *)((uint8_t *)&(buf) + 2));
  (&dst->bptr)->ofs = (uint16_t)(void *)buf;
  ptr.seg = (dst->bptr).seg;
  ptr.ofs = (&dst->bptr)->ofs;
  uVar2 = alignToSeg(ptr);
  (dst->aptr).seg = (*(uint16_t *)((uint8_t *)&(buf) + 2));
  (&dst->aptr)->ofs = uVar2;
  _fmemset((void *)(&dst->aptr)->ofs,(dst->aptr).seg,0);
  uVar2 = (dst->aptr).seg;
  dst_ofs = (&dst->aptr)->ofs;
  if (((((encoding == '\0') || (format != LBM_PBM)) || (sy != 0)) || ((w != 0 || (0x140 < (uint)h)))
      ) || (nplanes != 0x8)) {
    if (format == LBM_PBM) {
      plane_sz = h;
      lVar1 = CONCAT22(dst_ofs,h);
    }
    else {
      plane_sz = (h + 0xfU >> 4) * 2;
      lVar1 = (long)(int)plane_sz * (long)(int)(uint)nplanes;
      if ((format != LBM_PBM) && ((mask & 1) != 0)) {
        lVar1 = CONCAT22((int)((ulong)lVar1 >> 0x10),(int)lVar1 + plane_sz);
      }
    }
    dstline.seg = (uint16_t)((ulong)lVar1 >> 0x10);
    len = (word)lVar1;
    dstline.ofs = (uint16_t)ovr_stshAlloc((ulong)(len + 0x80));
    uVar4 = 0x2337;
    bsrcline.seg = dstline.seg;
    bsrcline.ofs = (uint16_t)ovr_stshAlloc((ulong)(len + 0x80));
    if (DebugVerbose != false) {
      printf("N %d W %u s %u \r");
      uVar4 = 0x22a6;
      ovr_biosReadKey();
    }
    if (sy < 0) {
      dst_ofs = dst_ofs - sy;
      npixels = sy + 0x140;
      x = 0;
    }
    else {
      npixels = 0x140;
      x = sy;
    }
    if ((uint)h < npixels + x) {
      npixels = h - x;
    }
    if (npixels != 0) {
      for (y = 0; ((uint)y < in_stack_0000001a && (y - w < 200)); y = y + 1) {
        ptr_base.seg = unaff_SI;
        ptr_base.ofs = uVar4;
        ptr_ofs.seg = x;
        ptr_ofs.ofs = unaff_SI;
        srcline = (char *)PADD_at_(ptr_base,ptr_ofs);
        uVar5 = (undefined1)(dstline.seg >> 8);
        if (encoding == '\0') {
          uVar4 = 0x1000;
          _fmemmove((char *)CONCAT22(dstline.seg,dstline.ofs),srcline,len);
        }
        else {
          uVar4 = 0x22a6;
          (*(uint8_t *)((uint8_t *)&(dst_02.seg))) = (char)dstline.seg;
          dst_02.ofs = dstline.ofs;
          (*(uint8_t *)((uint8_t *)&(dst_02.seg) + 1)) = uVar5;
          ovr_unrle(far_from_u32((uint32_t)(srcline)),dst_02,len);
        }
        if (w <= y) {
          if (format == LBM_PBM) {
            uVar4 = 0x1000;
            _fmemmove((char *)CONCAT22(uVar2,dst_ofs),
                      (char *)CONCAT13(uVar5,CONCAT12((char)dstline.seg,dstline.ofs + x)),npixels);
          }
          else if (x == 0) {
            src_01.seg = dstline.seg;
            src_01.ofs = dstline.ofs;
            uVar4 = 0x22a6;
            dst_00.seg = uVar2;
            dst_00.ofs = dst_ofs;
            ovr_lbm_combine_bitplanes(src_01,dst_00,npixels,nplanes,plane_sz);
          }
          else {
            src_02.seg = dstline.seg;
            src_02.ofs = dstline.ofs;
            dst_01.seg = bsrcline.seg;
            dst_01.ofs = bsrcline.ofs;
            ovr_lbm_combine_bitplanes(src_02,dst_01,h,nplanes,plane_sz);
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
    src_seg = src.seg;
    src_ofs = src.ofs;
    if (200 < in_stack_0000001a) {
      in_stack_0000001a = 200;
    }
    for (uVar3 = 0; uVar3 < in_stack_0000001a; uVar3 = uVar3 + 1) {
      src_00.seg = src_seg;
      src_00.ofs = src_ofs;
      dst_03.seg = uVar2;
      dst_03.ofs = dst_ofs;
      written = ovr_unrle(src_00,dst_03,0x140);
      __return_storage_ptr__ = (uint32_t *)(src_ofs + written);
      src_ofs = (uint16_t)ovr_mkp(__return_storage_ptr__,src_seg,unaff_DI);
      dst_ofs = dst_ofs + 0x140;
      src_seg = (uint16_t)__return_storage_ptr__;
    }
  }
  return;
}



/* 30e6:0321 */

stg_tmp_t * __cdecl16far grabLbm(int16_t file_id,int16_t x,int16_t y)

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
  undefined2 unaff_SI;
  uint16_t i;
  uint16_t unaff_DI;
  undefined2 unaff_SS;
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
  (*(uint16_t *)((uint8_t *)&(dst) + 2)) = IdPBM_.lo;
  fid = ovr_stshOpen(file_id);
  if ((int)fid < 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x16);
  }
  (*(uint16_t *)((uint8_t *)&(dst))) = ovr_stshAlloc(0x308);
  (*(uint16_t *)((uint8_t *)&(remain) + 2)) = (*(uint16_t *)((uint8_t *)&(dst) + 2));
  _fmemset((stg_tmp_t *)dst,(*(uint16_t *)((uint8_t *)&(dst) + 2)),0);
  (*(uint16_t *)((uint8_t *)&(remain))) = ovr_stshRead();
  if ((((int)remain == 0 && (*(uint16_t *)((uint8_t *)&(remain) + 2)) == 0) && (tmp.hi == uVar2)) && (tmp.lo == uVar16)) {
    bVar1 = false;
    ovr_stshRead();
    ovr_stshRead();
    uVar16 = tmp.lo;
    if ((tmp.hi == uVar12) && (tmp.lo == uVar11)) {
      lbm_type = LBM_PBM;
    }
    else {
      if ((tmp.hi != uVar4) || (tmp.lo != uVar3)) goto bad_lbm;
      lbm_type = LBM_ILBM;
    }
    while (iVar13 = ovr_stshRead(), iVar13 == 0 && uVar16 == 0) {
      if ((tmp.hi == uVar6) && (tmp.lo == uVar5)) {
        bVar1 = true;
        uVar16 = tmp.lo;
        iVar13 = ovr_stshRead();
        if ((iVar13 != 0 || uVar16 != 0) ||
           (((puVar15 = ovr_be4((uint32_t *)sz,CONCAT22(unaff_SI,unaff_DI)), uVar16 != 0 ||
             (puVar15 != (uint32_t *)((byte *)__C0_ASM_CopyRight + 0x10))) ||
            (iVar13 = ovr_stshRead(), iVar13 != 0 || uVar16 != 0)))) break;
        w = ovr_be2(hd.w);
        ovr_be2(hd.h);
        (*(uint16_t *)((uint8_t *)&(sz))) = (uint32_t *)((byte *)__C0_ASM_CopyRight + 0x10);
      }
      else if ((tmp.hi == uVar10) && (tmp.lo == uVar9)) {
        (*(uint16_t *)((uint8_t *)&(cmszB) + 2)) = tmp.lo;
        ovr_stshRead();
        (*(uint16_t *)((uint8_t *)&(cmszB))) = ovr_be4((uint32_t *)sz,CONCAT22(unaff_SI,unaff_DI));
        (*(uint16_t *)((uint8_t *)&(chnk_sz))) = (uint32_t *)cmszB;
        (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) = (*(uint16_t *)((uint8_t *)&(cmszB) + 2));
        if (((uint)(uint32_t *)cmszB & 1) != 0) {
          (*(uint16_t *)((uint8_t *)&(chnk_sz))) = (uint32_t *)((int)(uint32_t *)cmszB + 1);
          (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) = (*(uint16_t *)((uint8_t *)&(cmszB) + 2)) + ((uint32_t *)0xfffe < (uint32_t *)cmszB);
        }
        if (((int)(*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) < 0) ||
           (((*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) == 0 && ((uint32_t *)chnk_sz < (char *)"Error 4 %d \r" + 0xb)))) {
          if ((-1 < (int)(*(uint16_t *)((uint8_t *)&(chnk_sz) + 2))) &&
             ((0 < (int)(*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) || ((uint32_t *)chnk_sz != (uint32_t *)0x0)))) {
            ovr_stshRead();
          }
        }
        else {
          ovr_stshRead();
          if ((-1 < (int)(*(uint16_t *)((uint8_t *)&(chnk_sz) + 2))) &&
             ((0 < (int)(*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) || ((char *)"Error 4 %d \r" + 0xb < (uint32_t *)chnk_sz)))) {
            puVar15 = ovr_stshTell((uint32_t *)fid,unaff_DI);
            ovr_stshSeek(fid,CONCAT22(unaff_DI,((int)puVar15 >> 0xf) + (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) +
                                               (uint)CARRY2((uint)puVar15,(uint)(uint32_t *)chnk_sz)
                                               + -1 + (uint)(" \r" < (char *)((int)puVar15 +
                                                                             (int)(uint32_t *)
                                                                                  chnk_sz))));
          }
        }
        i = 0;
        while( true ) {
          if ((0 < (int)(*(uint16_t *)((uint8_t *)&(cmszB) + 2))) ||
             ((puVar15 = (uint32_t *)cmszB, uVar16 = (*(uint16_t *)((uint8_t *)&(cmszB) + 2)), (*(uint16_t *)((uint8_t *)&(cmszB) + 2)) == 0 &&
              ((char *)"Error 4 %d \r" + 0xb < (uint32_t *)cmszB)))) {
            puVar15 = (uint32_t *)((char *)"Error 4 %d \r" + 0xb);
            uVar16 = 0;
          }
          if (((int)uVar16 < 1) && (((*(uint16_t *)((uint8_t *)&(sz))) = (uint32_t *)cmszB, uVar16 != 0 || (puVar15 <= i))))
          break;
          ((stg_tmp_t *)dst)->cmap[i] = (uint8_t)((int)(uint)cmap[i] >> 2);
          i = i + 1;
        }
      }
      else {
        if ((tmp.hi == uVar8) && (tmp.lo == uVar7)) {
          if (bVar1) {
            ovr_stshRead();
            puVar15 = ovr_be4((uint32_t *)sz,CONCAT22(unaff_SI,unaff_DI));
            (*(uint16_t *)((uint8_t *)&(chnk_sz))) = puVar15;
            (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) = tmp.lo;
            if (((uint)puVar15 & 1) != 0) {
              (*(uint16_t *)((uint8_t *)&(chnk_sz))) = (uint32_t *)((int)puVar15 + 1);
              (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) = tmp.lo + ((uint32_t *)0xfffe < puVar15);
            }
            pvVar14 = ovr_stshAlloc((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)),(uint32_t *)chnk_sz));
            ovr_stshRead();
            ovr_stshClose(fid);
            src.seg = (uint16_t)puVar15;
            src.ofs = (uint16_t)pvVar14;
            lbm_decode_body(lbm_type,hd.enc,hd.nplanes,hd.mask,src,(stg_tmp_t *)dst,(*(uint16_t *)((uint8_t *)&(dst) + 2)),x,y,w)
            ;
            handle.seg = (uint16_t)puVar15;
            handle.ofs = (uint16_t)pvVar14;
            ovr_stshFree(handle);
            return (stg_tmp_t *)dst;
          }
          break;
        }
        (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) = tmp.lo;
        ovr_stshRead();
        (*(uint16_t *)((uint8_t *)&(chnk_sz))) = ovr_be4((uint32_t *)chnk_sz,CONCAT22(unaff_SI,unaff_DI));
        if (((uint)(uint32_t *)chnk_sz & 1) != 0) {
          bVar17 = (uint32_t *)0xfffe < (uint32_t *)chnk_sz;
          (*(uint16_t *)((uint8_t *)&(chnk_sz))) = (uint32_t *)((int)(uint32_t *)chnk_sz + 1);
          (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) = (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) + bVar17;
        }
        puVar15 = ovr_stshTell((uint32_t *)fid,unaff_DI);
        uVar16 = ((int)puVar15 >> 0xf) + (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) +
                 (uint)CARRY2((uint)puVar15,(uint)(uint32_t *)chnk_sz);
        ovr_stshSeek(fid,CONCAT22(unaff_DI,uVar16));
      }
    }
  }
bad_lbm:
                    /* free the pixels pointer at the end */
  if ((&((stg_tmp_t *)dst)->bptr)->ofs != 0 || (((stg_tmp_t *)dst)->bptr).seg != 0) {
    handle_00.seg = (((stg_tmp_t *)dst)->bptr).seg;
    handle_00.ofs = (&((stg_tmp_t *)dst)->bptr)->ofs;
    ovr_stshFree(handle_00);
  }
  ovr_stshClose(fid);
  handle_01.seg = (*(uint16_t *)((uint8_t *)&(dst) + 2));
  handle_01.ofs = (uint16_t)(stg_tmp_t *)dst;
  ovr_stshFree(handle_01);
  printf("Filename %d %s  \r");
  ovr_biosReadKey();
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0xd);
}


