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
