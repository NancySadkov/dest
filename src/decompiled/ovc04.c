/*
 * ovc04.c - recovered from STRONG.EXE
 * memory block: OVC04
 * range: 30e6:0000 - 30e6:081f
 * functions: 3
 */
#include "recovered.h"


/* 30e6:0000 */

/* Aligns pointer up to 16 bytes */

far_t __cdecl16far alignToSeg(far_t ptr)

{
  if (((ulong)ptr & 0xf) != 0) {
    ptr.seg = ptr.seg + 1;
    ptr.ofs = ptr.ofs & 0xfff0;
  }
  return (far_t)((ulong)(ptr.seg + (ptr.ofs >> 4)) << 0x10);
}



/* 30e6:0024 */

void __cdecl16far
lbm_decode_body(lbm_type_t format,int8_t encoding,uint8_t nplanes,uint8_t mask,far_t src,
               stg_tmp_t *dst,int16_t sx,int16_t sy,int16_t w,int16_t h)

{
  uint16_t uVar1;
  far_t dst_00;
  int written;
  uint16_t len;
  stg_tmp_t *t;
  uint uVar2;
  int16_t y;
  undefined2 dseg;
  bool bVar3;
  void *buf;
  far_t dstline;
  far_t bsrcline;
  far_t srcline;
  int x;
  uint16_t npixels;
  uint16_t plane_sz;
  uint8_t *dst_ofs;
  uint16_t src_ofs;
  uint16_t src_seg;
  uint8_t *pdst;
  uint ofs_inc;
  uint src_ofsS;
  uint16_t src_segS;
  
  buf = ovr_stshAlloc(0xfa0f);
  dseg = (undefined2)((ulong)dst >> 0x10);
  t = (stg_tmp_t *)dst;
  (t->bptr).seg = (uint16_t)((ulong)buf >> 0x10);
  (&t->bptr)->ofs = (uint16_t)(void *)buf;
  dstline.seg = (t->bptr).seg;
  dstline.ofs = (&t->bptr)->ofs;
  dstline = alignToSeg(dstline);
  (t->aptr).seg = dstline.seg;
  (&t->aptr)->ofs = dstline.ofs;
  uVar1 = (t->aptr).seg;
  _fmemset((void *)CONCAT13((char)(uVar1 >> 8),CONCAT12((char)uVar1,(&t->aptr)->ofs)),0,64000);
  uVar1 = (t->aptr).seg;
  dst_ofs = (uint8_t *)(&t->aptr)->ofs;
  if (((((encoding == '\0') || (format != LBM_PBM)) || (sx != 0)) ||
      ((sy != 0 || (0x140 < (uint)w)))) || (nplanes != 0x8)) {
    src_segS = 0;
    src_ofsS = 0;
    if (format == LBM_PBM) {
      plane_sz = w;
      len = w;
    }
    else {
      plane_sz = (w + 0xfU >> 4) * 2;
      len = plane_sz * nplanes;
      if ((format != LBM_PBM) && ((mask & 1) != 0)) {
        len = len + plane_sz;
      }
    }
    dstline = (far_t)ovr_stshAlloc((ulong)(len + 0x80));
    bsrcline = (far_t)ovr_stshAlloc((ulong)(len + 0x80));
    if (DebugVerbose != false) {
      printf("N %d W %u s %u \r",(uint)format);
      ovr_biosReadKey();
    }
    if (sx < 0) {
      dst_ofs = dst_ofs + -sx;
      npixels = sx + 0x140;
      x = 0;
    }
    else {
      npixels = 0x140;
      x = sx;
    }
    if ((uint)w < npixels + x) {
      npixels = w - x;
    }
    if (npixels != 0) {
      for (y = 0; (pdst = (uint8_t *)dstline.ofs, (uint)y < (uint)h && (y - sy < 200)); y = y + 1) {
        srcline.seg = src_segS;
        srcline.ofs = src_ofsS;
        srcline = PADD_at_(src,srcline);
        if (encoding == '\0') {
          _fmemmove(pdst,(uint8_t *)srcline.ofs,len);
          ofs_inc = len;
        }
        else {
          ofs_inc = ovr_unrle(srcline,dstline,len);
        }
        bVar3 = CARRY2(src_ofsS,ofs_inc);
        src_ofsS = src_ofsS + ofs_inc;
        src_segS = src_segS + bVar3;
        if (sy <= y) {
          if (format == LBM_PBM) {
            _fmemmove(dst_ofs,pdst + x,npixels);
          }
          else if (x == 0) {
            dst_00.seg = uVar1;
            dst_00.ofs = (uint16_t)dst_ofs;
            ovr_lbm_combine_bitplanes(dstline,dst_00,npixels,nplanes,plane_sz);
          }
          else {
            ovr_lbm_combine_bitplanes(dstline,bsrcline,w,nplanes,plane_sz);
            _fmemmove(dst_ofs,(uint8_t *)(bsrcline.ofs + x),npixels);
          }
          dst_ofs = dst_ofs + 0x140;
        }
      }
      ovr_stshFree(dstline);
      ovr_stshFree(bsrcline);
    }
  }
  else {
    if (200 < (uint)h) {
      h = 200;
    }
    uVar2 = 0;
    while( true ) {
      src_seg = src.seg;
      src_ofs = src.ofs;
      if ((uint)h <= uVar2) break;
      bsrcline.seg = uVar1;
      bsrcline.ofs = (uint16_t)dst_ofs;
      written = ovr_unrle(src,bsrcline,0x140);
      src = (far_t)ovr_mkp(src_ofs + written,src_seg);
      dst_ofs = dst_ofs + 0x140;
      uVar2 = uVar2 + 1;
    }
  }
  return;
}



/* 30e6:0321 */

/* WARNING: Removing unreachable block (ram,0x00031406) */
/* WARNING: Removing unreachable block (ram,0x000313af) */
/* WARNING: Removing unreachable block (ram,0x000313d2) */
/* WARNING: Removing unreachable block (ram,0x00031440) */

stg_tmp_t * __cdecl16far grabLbm(int16_t file_id,int16_t x,int16_t y)

{
  far_t buf;
  far_t buf_00;
  far_t buf_01;
  far_t buf_02;
  far_t buf_03;
  far_t buf_04;
  far_t buf_05;
  far_t buf_06;
  far_t buf_07;
  far_t buf_08;
  far_t handle;
  undefined2 uVar1;
  bool bVar2;
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
  uint16_t uVar13;
  uint16_t uVar14;
  uint16_t fid;
  uint i;
  undefined2 unaff_DI;
  uint16_t unaff_SS;
  stg_tmp_t *dst;
  long remain;
  uint32_t cmszB;
  far_t fVar15;
  byte cmap [768];
  lbm_bmhd_t hd;
  uint16_t h;
  uint16_t w;
  bool got_header;
  lbm_type_t lbm_type;
  uint32_t sz;
  undefined4 chnk_sz;
  DW tmp;
  
  uVar14 = IdPBM_.hi;
  uVar13 = IdPBM_.lo;
  uVar12 = IdCMAP.hi;
  uVar11 = IdCMAP.lo;
  uVar10 = IdBODY.hi;
  uVar9 = IdBODY.lo;
  uVar8 = IdBMHD.hi;
  uVar7 = IdBMHD.lo;
  uVar6 = IdILBM.hi;
  uVar5 = IdILBM.lo;
  uVar4 = IdFORM.hi;
  uVar3 = IdFORM.lo;
  fid = ovr_stshOpen(file_id);
  if ((int)fid < 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x16);
  }
  dst = ovr_stshAlloc(0x308);
  dst._0_2_ = (stg_tmp_t *)dst;
  uVar1 = (undefined2)((ulong)dst >> 0x10);
  _fmemset(dst,0,0x308);
  fVar15.seg = unaff_SS;
  fVar15.ofs = (uint16_t)&tmp;
  remain = ovr_stshRead(fid,fVar15,4);
  if (((remain == 0) &&
      (sz = CONCAT22(sz._2_2_,(undefined2)sz), chnk_sz = CONCAT22(chnk_sz._2_2_,(undefined2)chnk_sz)
      , tmp.hi == uVar4)) &&
     (sz = CONCAT22(sz._2_2_,(undefined2)sz), chnk_sz = CONCAT22(chnk_sz._2_2_,(undefined2)chnk_sz),
     tmp.lo == uVar3)) {
    bVar2 = false;
    buf.seg = unaff_SS;
    buf.ofs = (uint16_t)&chnk_sz;
    ovr_stshRead(fid,buf,4);
    buf_00.seg = unaff_SS;
    buf_00.ofs = (uint16_t)&tmp;
    ovr_stshRead(fid,buf_00,4);
    if ((tmp.hi == uVar14) && (tmp.lo == uVar13)) {
      lbm_type = LBM_PBM;
      sz = CONCAT22(sz._2_2_,(undefined2)sz);
      chnk_sz = CONCAT22(chnk_sz._2_2_,(undefined2)chnk_sz);
    }
    else {
      if ((tmp.hi != uVar6) || (tmp.lo != uVar5)) goto bad_lbm;
      lbm_type = LBM_ILBM;
    }
    while( true ) {
      buf_01.seg = unaff_SS;
      buf_01.ofs = (uint16_t)&tmp;
      remain = ovr_stshRead(fid,buf_01,4);
      if (remain != 0) break;
      if ((tmp.hi == uVar8) && (tmp.lo == uVar7)) {
        bVar2 = true;
        buf_02.seg = unaff_SS;
        buf_02.ofs = (uint16_t)&sz;
        remain = ovr_stshRead(fid,buf_02,4);
        if (remain != 0) break;
        cmszB = ovr_be4(sz);
        sz = cmszB;
        if (cmszB != 0x14) break;
        buf_03.seg = unaff_SS;
        buf_03.ofs = (uint16_t)&hd;
        remain = ovr_stshRead(fid,buf_03,0x14);
        if (remain != 0) break;
        w = ovr_be2(hd.w);
        h = ovr_be2(hd.h);
      }
      else if ((tmp.hi == uVar12) && (tmp.lo == uVar11)) {
        buf_04.seg = unaff_SS;
        buf_04.ofs = (uint16_t)&sz;
        ovr_stshRead(fid,buf_04,4);
        cmszB = ovr_be4(sz);
        sz = cmszB;
        chnk_sz = cmszB;
        if ((cmszB & 1) != 0) {
          chnk_sz = cmszB + 1;
        }
        if ((long)chnk_sz < 0x300) {
          if (0 < (long)chnk_sz) {
            buf_06.seg = unaff_SS;
            buf_06.ofs = (uint16_t)cmap;
            ovr_stshRead(fid,buf_06,chnk_sz);
          }
        }
        else {
          buf_05.seg = unaff_SS;
          buf_05.ofs = (uint16_t)cmap;
          ovr_stshRead(fid,buf_05,0x300);
          if (0x300 < (long)chnk_sz) {
            cmszB = ovr_stshTell(fid);
            remain = chnk_sz + (long)(int)cmszB;
            ovr_stshSeek(fid,CONCAT22(unaff_DI,(int)((ulong)remain >> 0x10) + -1 +
                                               (uint)(0x2ff < (uint)remain)));
          }
        }
        i = 0;
        while( true ) {
          cmszB = sz;
          if (0x300 < (long)sz) {
            cmszB = 0x300;
          }
          if (((long)cmszB < 0x10000) && (((int)(cmszB >> 0x10) != 0 || ((uint)cmszB <= i)))) break;
          ((stg_tmp_t *)dst)->cmap[i] = (uint8_t)((int)(uint)cmap[i] >> 2);
          i = i + 1;
        }
      }
      else {
        if ((tmp.hi == uVar10) && (tmp.lo == uVar9)) {
          if (bVar2) {
            buf_07.seg = unaff_SS;
            buf_07.ofs = (uint16_t)&sz;
            ovr_stshRead(fid,buf_07,4);
            cmszB = ovr_be4(sz);
            chnk_sz = cmszB;
            if ((cmszB & 1) != 0) {
              chnk_sz = cmszB + 1;
            }
            sz = cmszB;
            fVar15 = (far_t)ovr_stshAlloc(chnk_sz);
            ovr_stshRead(fid,fVar15,chnk_sz);
            ovr_stshClose(fid);
            lbm_decode_body(lbm_type,hd.enc,hd.nplanes,hd.mask,fVar15,dst,x,y,w,h);
            ovr_stshFree(fVar15);
            return dst;
          }
          break;
        }
        buf_08.seg = unaff_SS;
        buf_08.ofs = (uint16_t)&chnk_sz;
        ovr_stshRead(fid,buf_08,4);
        cmszB = ovr_be4(chnk_sz);
        if ((cmszB & 1) != 0) {
          cmszB = cmszB + 1;
        }
        chnk_sz = cmszB;
        cmszB = ovr_stshTell(fid);
        ovr_stshSeek(fid,CONCAT22(unaff_DI,(int)(chnk_sz + (long)(int)cmszB >> 0x10)));
      }
    }
  }
bad_lbm:
                    /* free the pixels pointer at the end */
  if ((&((stg_tmp_t *)dst)->bptr)->ofs != 0 || (((stg_tmp_t *)dst)->bptr).seg != 0) {
    handle.seg = (((stg_tmp_t *)dst)->bptr).seg;
    handle.ofs = (&((stg_tmp_t *)dst)->bptr)->ofs;
    ovr_stshFree(handle);
  }
  ovr_stshClose(fid);
  ovr_stshFree((far_t)dst);
  printf("Filename %d %s  \r",file_id);
  ovr_biosReadKey();
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0xd);
}


