/*
 * ovc04_lbm.c - recovered from STRONG.EXE
 * memory block: OVC04_lbm.c
 * range: 30e6:0000 - 30e6:081f
 * functions: 3
 */
#include "recovered.h"


/* 30e6:0000 */

/* Aligns pointer up to 16 bytes */

uint16_t __cdecl16far alignToSeg(far_t ptr,...)

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
  far_t src_00;
  far_t src_01;
  far_t src_02;
  far_t dst_00;
  far_t dst_01;
  far_t src_03;
  far_t dst_02;
  far_t dst_03;
  far_t ptr;
  far_t handle;
  far_t handle_00;
  far_t ptr_base;
  far_t ptr_ofs;
  uint16_t uVar2;
  uint16_t written;
  uint16_t uVar3;
  uint16_t t;
  uint16_t unaff_SI;
  uint uVar4;
  int16_t y;
  uint16_t unaff_DI;
  word count;
  uint16_t dseg;
  uint32_t buf;
  far_t dstline;
  far_t bsrcline;
  char *srcline;
  char in_stack_00000004;
  undefined1 in_stack_0000000d;
  uint8_t nplanes_00;
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
  
  (*(uint16_t *)((uint8_t *)&(buf))) = ovr_stshAlloc((ulong)unaff_DI << 0x10,0xf);
  *(undefined2 *)(src.seg + 0x306) = (*(uint16_t *)((uint8_t *)&(buf) + 2));
  *(undefined2 *)(src.seg + 0x304) = (void *)buf;
  ptr.seg = unaff_DI;
  ptr.ofs = *(uint16_t *)(src.seg + 0x306);
  uVar2 = alignToSeg(ptr,(char)*(undefined2 *)(src.seg + 0x304));
  *(undefined2 *)(src.seg + 0x302) = (*(uint16_t *)((uint8_t *)&(buf) + 2));
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
    count = (word)lVar1;
    dstline.ofs = (uint16_t)ovr_stshAlloc((ulong)unaff_DI << 0x10,(char)(count + 0x80));
    uVar3 = 0x2337;
    bsrcline.seg = dstline.seg;
    bsrcline.ofs = (uint16_t)ovr_stshAlloc((ulong)unaff_DI << 0x10,(char)(count + 0x80));
    if (DebugVerbose != false) {
      printf("N %d W %u s %u \r");
      uVar3 = 0x22a6;
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
        ptr_base.ofs = uVar3;
        ptr_ofs.seg = x;
        ptr_ofs.ofs = unaff_SI;
        unaff_DI = uVar3;
        srcline = (char *)PADD_at_(ptr_base,ptr_ofs);
        if (format == LBM_PBM) {
          uVar3 = 0x1000;
          _fmemmove((char *)CONCAT22(dstline.seg,dstline.ofs),srcline,count);
        }
        else {
          uVar3 = 0x22a6;
          src_02.seg = dstline.ofs;
          src_02.ofs = (uint16_t)((ulong)srcline >> 0x10);
          (*(uint8_t *)((uint8_t *)&(dst_02.seg))) = (char)lVar1;
          dst_02.ofs = dstline.seg;
          (*(uint8_t *)((uint8_t *)&(dst_02.seg) + 1)) = (char)((ulong)lVar1 >> 8);
          ovr_unrle(src_02,dst_02,unaff_DI,(char *)srcline,(char)lVar1);
        }
        if (sx <= y) {
          if (in_stack_00000004 == '\0') {
            uVar3 = 0x1000;
            _fmemmove((char *)CONCAT22(uVar2,dst_ofs),
                      (char *)CONCAT22(dstline.seg,(char *)(dstline.ofs + x)),npixels);
          }
          else {
            nplanes_00 = (uint8_t)plane_sz;
            if (x == 0) {
              uVar3 = 0x22a6;
              src_00.seg = dst_ofs;
              src_00.ofs = dstline.seg;
              dst_00.seg = npixels;
              dst_00.ofs = uVar2;
              ovr_lbm_combine_bitplanes
                        (src_00,dst_00,(uint)(byte)encoding,nplanes_00,unaff_DI,dstline.ofs,
                         nplanes_00);
            }
            else {
              src_01.seg = bsrcline.ofs;
              src_01.ofs = dstline.seg;
              dst_01.seg = sy;
              dst_01.ofs = bsrcline.seg;
              ovr_lbm_combine_bitplanes
                        (src_01,dst_01,(uint)(byte)encoding,nplanes_00,unaff_DI,dstline.ofs,
                         nplanes_00);
              uVar3 = 0x1000;
              _fmemmove((char *)CONCAT22(uVar2,dst_ofs),
                        (char *)CONCAT22(bsrcline.seg,(char *)(bsrcline.ofs + x)),npixels);
            }
          }
          dst_ofs = dst_ofs + 0x140;
        }
      }
      handle.seg = unaff_DI;
      handle.ofs = dstline.seg;
      ovr_stshFree(handle,(char)dstline.ofs);
      handle_00.seg = unaff_DI;
      handle_00.ofs = bsrcline.seg;
      ovr_stshFree(handle_00,(char)bsrcline.ofs);
    }
  }
  else {
    src_seg = src.ofs;
    src_ofs = _mask;
    if (200 < (uint)w) {
      w = 200;
    }
    for (uVar4 = 0; uVar4 < (uint)w; uVar4 = uVar4 + 1) {
      src_03.seg = dst_ofs;
      src_03.ofs = src_seg;
      dst_03.seg = 0x140;
      dst_03.ofs = uVar2;
      written = ovr_unrle(src_03,dst_03,unaff_DI,src_ofs,(char)uVar2);
      uVar3 = src_ofs + written;
      src_ofs = (uint16_t)ovr_mkp((uint32_t *)src_seg,unaff_DI,unaff_SI,(char)uVar3);
      dst_ofs = dst_ofs + 0x140;
      src_seg = uVar3;
    }
  }
  return;
}



/* 30e6:0321 */

stg_tmp_t * __cdecl16far grabLbm(int16_t file_id,int16_t x,int16_t y,...)

{
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
  uint16_t unaff_SI;
  uint16_t i;
  uint32_t *unaff_DI;
  undefined2 unaff_SS;
  bool bVar17;
  stg_tmp_t *dst;
  uint32_t remain;
  uint32_t cmszB;
  undefined2 in_stack_00000004;
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
  (*(uint16_t *)((uint8_t *)&(dst) + 2)) = (stg_tmp_t *)IdPBM_.lo;
  fid = ovr_stshOpen((uint16_t)unaff_DI,in_stack_00000004);
  if ((int)fid < 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit((int)unaff_DI,0x16);
  }
  (*(uint16_t *)((uint8_t *)&(dst))) = ovr_stshAlloc();
  (*(uint16_t *)((uint8_t *)&(remain) + 2)) = (*(uint16_t *)((uint8_t *)&(dst) + 2));
  _fmemset((void *)ZEXT24((*(uint16_t *)((uint8_t *)&(dst) + 2))),0x308,(uint16_t)unaff_DI);
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
          if ((((iVar13 != 0 || uVar16 != 0) || (puVar15 = ovr_be4(), uVar16 != 0)) ||
              (puVar15 != (uint32_t *)((byte *)__C0_ASM_CopyRight + 0x10))) ||
             (iVar13 = ovr_stshRead(), iVar13 != 0 || uVar16 != 0)) break;
          w = ovr_be2((uint16_t)unaff_DI,hd.w);
          h = ovr_be2((uint16_t)unaff_DI,hd.h);
        }
        else if ((tmp.hi == uVar10) && (tmp.lo == uVar9)) {
          (*(uint16_t *)((uint8_t *)&(cmszB) + 2)) = tmp.lo;
          ovr_stshRead();
          (*(uint16_t *)((uint8_t *)&(cmszB))) = ovr_be4();
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
               ((0 < (int)(*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) || ((char *)"Error 4 %d \r" + 0xb < (uint32_t *)chnk_sz))))
            {
              ovr_stshTell(unaff_DI,unaff_SI,fid);
              ovr_stshSeek();
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
            if (((int)uVar16 < 1) && ((uVar16 != 0 || (puVar15 <= i)))) break;
            ((stg_tmp_t *)dst)->cmap[i] = (uint8_t)((int)(uint)cmap[i] >> 2);
            i = i + 1;
          }
        }
        else {
          if ((tmp.hi == uVar8) && (tmp.lo == uVar7)) {
            if (bVar1) {
              ovr_stshRead();
              puVar15 = ovr_be4();
              pvVar14 = ovr_stshAlloc();
              ovr_stshRead();
              ovr_stshClose((uint16_t)unaff_DI,fid);
              src.seg = (uint16_t)(stg_tmp_t *)dst;
              src.ofs = (uint16_t)puVar15;
              lbm_decode_body(hd.enc,hd.nplanes,hd.mask,(uint8_t)pvVar14,src,
                              (stg_tmp_t *)CONCAT22(file_id,(*(uint16_t *)((uint8_t *)&(dst) + 2))),x,w,h,(int16_t)unaff_DI);
              ovr_stshFree();
              return (stg_tmp_t *)dst;
            }
            break;
          }
          (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) = tmp.lo;
          ovr_stshRead();
          (*(uint16_t *)((uint8_t *)&(chnk_sz))) = ovr_be4();
          if (((uint)(uint32_t *)chnk_sz & 1) != 0) {
            bVar17 = (uint32_t *)0xfffe < (uint32_t *)chnk_sz;
            (*(uint16_t *)((uint8_t *)&(chnk_sz))) = (uint32_t *)((int)(uint32_t *)chnk_sz + 1);
            (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) = (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) + bVar17;
          }
          puVar15 = ovr_stshTell(unaff_DI,unaff_SI,fid);
          uVar16 = ((int)puVar15 >> 0xf) + (*(uint16_t *)((uint8_t *)&(chnk_sz) + 2)) +
                   (uint)CARRY2((uint)puVar15,(uint)(uint32_t *)chnk_sz);
          ovr_stshSeek();
        }
      }
    }
  }
                    /* free the pixels pointer at the end */
  if ((&((stg_tmp_t *)dst)->bptr)->ofs != 0 || (((stg_tmp_t *)dst)->bptr).seg != 0) {
    ovr_stshFree();
  }
  ovr_stshClose((uint16_t)unaff_DI,fid);
  ovr_stshFree();
  printf("Filename %d %s  \r");
  ovr_biosReadKey();
                    /* WARNING: Subroutine does not return */
  ovr_stExit((int)unaff_DI,0xd);
}


