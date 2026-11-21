/*
 * ovc06_blit.c - recovered from STRONG.EXE
 * memory block: OVC06_blit.c
 * range: 317e:0000 - 317e:14af
 * functions: 17
 */
#include "recovered.h"


/* 317e:0000 */

far_t * __cdecl16far
stshRleSub(far_t *__return_storage_ptr__,uint8_t *src,uint16_t sx,uint16_t sy,uint16_t ex,
          uint16_t ey,int16_t hdrsz,...)

{
  uint16_t sz;
  uint16_t width;
  uint16_t rlesz;
  uint16_t written;
  uint16_t start;
  uint16_t uVar1;
  uint16_t rows_left;
  uint unaff_DI;
  uint32_t block;
  uint32_t r;
  int in_stack_00000004;
  uint16_t dst;
  uint16_t prow;
  undefined4 uStack_6;
  uint16_t src_seg;
  uint16_t dseg;
  
  sz = ((sy - (int)src) + ((sy - (int)src) + 1 >> 7) + 2) * ((ex - sx) + 1);
  (*(uint16_t *)((uint8_t *)&(block) + 2)) = (uint8_t *)(sz + ey + -1);
  (*(uint16_t *)((uint8_t *)&(block))) = ovr_stshAlloc(CONCAT22(unaff_DI,(CARRY2(sz,ey) - 1) + (uint)(sz + ey != 0)),
                              (*(uint16_t *)((uint8_t *)&(block) + 2)));
  uStack_6 = (undefined1 *)CONCAT22((*(uint16_t *)((uint8_t *)&(block) + 2)),(undefined1 *)((int)(void *)block + (ey - 10)));
  prow = (uint16_t)(src + in_stack_00000004 + sx * 0x140);
  uVar1 = (int)(void *)block + (ey - 1);
  width = (sy - (int)src) + 1;
  rows_left = (ex - sx) + 1;
  dst = uVar1;
  while (rows_left != 0) {
    rlesz = ovr_rle_line((uint8_t *)CONCAT22(dst,__return_storage_ptr__),
                         (uint8_t *)CONCAT22(width,(*(uint16_t *)((uint8_t *)&(block) + 2))),unaff_DI,prow);
    dst = dst + rlesz;
    prow = prow + 0x140;
    rows_left = rows_left - 1;
  }
  written = dst - uVar1;
  if (written <= sz) {
    *(undefined2 *)((int)(void *)block + (ey - 7)) = 0;
    *(uint16_t *)((int)(void *)block + (ey - 9)) = written;
    *(uint16_t *)((int)(void *)block + (ey - 5)) = width;
    *(int *)((int)(void *)block + (ey - 3)) = (ex - sx) + 1;
    *uStack_6 = 1;
    (*(uint16_t *)((uint8_t *)&(r))) = (far_t *)ovr_stshRealloc((uint32_t)CONCAT22(written + ey + -1,(*(uint16_t *)((uint8_t *)&(block) + 2))),
                                       (ulong)unaff_DI << 0x10,(void *)block);
    return (far_t *)r;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(unaff_DI,5);
}



/* 317e:0148 */

/* Cuts X,Y,W,H rect out of 8bit pixels pointed by src.
   returns ptrr to stg_t struct */

far_t * __cdecl16far
stshRleCut(far_t *__return_storage_ptr__,far_t src,int16_t sx,int16_t sy,int16_t ex,int16_t ey,...)

{
  far_t *pfVar1;
  int16_t unaff_BP;
  undefined2 in_stack_00000004;
  
  pfVar1 = stshRleSub(__return_storage_ptr__,(uint8_t *)src.ofs,src.seg,sx,sy,10,unaff_BP,
                      in_stack_00000004);
  return pfVar1;
}



/* 317e:0168 */

far_t * __cdecl16far
stshRleType2(far_t *__return_storage_ptr__,far_t pixels,int16_t sx,int16_t sy,int16_t ex,int16_t ey,
            int16_t ox,int16_t oy,...)

{
  far_t *pfVar1;
  undefined2 in_DX;
  undefined2 in_stack_00000004;
  int16_t in_stack_0000fffa;
  far_t *pfStack_6;
  undefined2 uStack_4;
  
  pfVar1 = stshRleSub(__return_storage_ptr__,(uint8_t *)pixels.ofs,pixels.seg,sx,sy,0xf,
                      in_stack_0000fffa,in_stack_00000004);
  pfStack_6 = (far_t *)CONCAT22(in_DX,pfVar1);
  *(int16_t *)((int)&pfVar1->ofs + 1) = ex;
  *(int16_t *)((int)&pfVar1->seg + 1) = ey;
  *(undefined1 *)&pfStack_6->ofs = 2;
  return pfVar1;
}



/* 317e:01b2 */

void __cdecl16far blitLoadRleGfx(far_t gfx,far_t dst,...)

{
  far_t handle;
  uint16_t consumed;
  uint16_t in_DX;
  uint16_t unaff_SI;
  uint16_t height;
  stg_tmp_t *in_stack_00000004;
  uint16_t src_ofs;
  
  if (in_stack_00000004 != (stg_tmp_t *)0x0 || gfx.ofs != 0) {
    if (((stg_tmp_t *)CONCAT22(gfx.ofs,in_stack_00000004))->cmap[0] == 0x0) {
      handle.seg = unaff_SI;
      handle.ofs = gfx.ofs;
      in_stack_00000004 = ovr_stshLoadGfx(handle,in_stack_00000004);
      gfx.ofs = in_DX;
    }
    if (((stg_tmp_t *)CONCAT22(gfx.ofs,in_stack_00000004))->cmap[0] != 0x1) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(unaff_SI,0x1a);
    }
                    /* typedef struct { //stronghold graphics
                         uint8_t type;  //0=not loaded, 1=loaded
                         uint8_t sz;
                         uint16_t width;
                         uint16_t height;
                         uint8_t pixels[width*height];
                       } gfx_t; */
    src_ofs = (uint16_t)(in_stack_00000004->cmap + 9);
    height = *(uint16_t *)(in_stack_00000004->cmap + 7);
    while (height != 0) {
      consumed = ovr_rle_blit_decode((byte *)CONCAT22(gfx.seg,gfx.ofs),
                                     (byte *)CONCAT22(*(undefined2 *)(in_stack_00000004->cmap + 5),
                                                      dst.ofs),unaff_SI,src_ofs);
      src_ofs = src_ofs + consumed;
      gfx.seg = gfx.seg + 0x140;
      height = height - 1;
    }
  }
  return;
}



/* 317e:0239 */

void __cdecl16far drawGfx(far_t gfx,far_t dst,bool type)

{
  far_t gfx_00;
  far_t dst_00;
  int16_t iVar1;
  uint16_t unaff_SI;
  int iVar2;
  undefined2 uStack_6;
  
  if (type) {
    if (gfx.ofs != 0 || gfx.seg != 0) {
      uStack_6 = gfx.ofs + 9;
      for (iVar2 = *(int *)(gfx.ofs + 7); iVar2 != 0; iVar2 = iVar2 + -1) {
        iVar1 = ovr_drawLine2((char *)CONCAT22(dst.ofs,gfx.seg),
                              (char *)CONCAT22(*(undefined2 *)(gfx.ofs + 5),dst.seg),unaff_SI,
                              uStack_6);
        uStack_6 = uStack_6 + iVar1;
        dst.ofs = dst.ofs + 0x140;
      }
    }
  }
  else {
    gfx_00.seg = dst.ofs;
    gfx_00.ofs = gfx.seg;
    dst_00.seg = unaff_SI;
    dst_00.ofs = dst.seg;
    blitLoadRleGfx(gfx_00,dst_00,gfx.ofs);
  }
  return;
}



/* 317e:02a9 */

/* Blits the graphics on screen */

void __cdecl16far blitGfx10(far_t gfx,uint16_t x,uint16_t y,brect_t *dst,bool type,...)

{
  int iVar1;
  uint16_t in_DX;
  uint16_t pdst;
  int iVar2;
  undefined2 uVar3;
  uint16_t unaff_SS;
  stg_tmp_t *in_stack_00000004;
  far_t gfx_00;
  far_t dst_00;
  far_t dst_01;
  far_t src;
  uint8_t rowBuf;
  uint16_t dst_h;
  uint16_t dst_w;
  uint16_t dst_y;
  uint16_t dst_x;
  uint8_t *puStack_1c;
  uint16_t uStack_1a;
  uint16_t uStack_18;
  uint16_t uStack_16;
  int iStack_14;
  uint16_t uStack_12;
  int iStack_10;
  uint16_t uStack_e;
  uint16_t uStack_c;
  uint16_t uStack_a;
  uint16_t uStack_8;
  uint16_t pfn;
  uint16_t uStack_4;
  
  uVar3 = 0x317e;
  if (in_stack_00000004 != (stg_tmp_t *)0x0 || gfx.ofs != 0) {
    if (((stg_tmp_t *)CONCAT22(gfx.ofs,in_stack_00000004))->cmap[0] == 0x0) {
      uVar3 = 0x2337;
      in_stack_00000004 = ovr_stshLoadGfx();
      gfx.ofs = in_DX;
    }
    if (((stg_tmp_t *)CONCAT22(gfx.ofs,in_stack_00000004))->cmap[0] != 0x1) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit();
    }
    dst_x = *(uint16_t *)CONCAT22((brect_t *)dst,y);
    dst_y = *(uint16_t *)(y + 2);
    dst_w = *(uint16_t *)(y + 4);
    dst_h = *(uint16_t *)(y + 6);
    if (((((int)gfx.seg < (int)dst_x) || ((int)x < (int)dst_y)) ||
        ((int)dst_w < (int)(gfx.seg + *(int *)(in_stack_00000004->cmap + 5) + -1))) ||
       ((int)dst_h < (int)(x + *(int *)(in_stack_00000004->cmap + 7) + -1))) {
      if ((*(uint8_t *)((uint8_t *)&(dst) + 2)) == false) {
        pfn = 0x133;
      }
      else {
        pfn = 0x129;
      }
      uStack_4 = 0x22a6;
      if (((int)dst_x <= (int)(gfx.seg + *(int *)(in_stack_00000004->cmap + 5) + -1)) &&
         ((int)gfx.seg <= (int)dst_w)) {
        if ((int)gfx.seg < (int)dst_x) {
          iStack_10 = dst_x - gfx.seg;
          uStack_8 = dst_x;
        }
        else {
          uStack_8 = gfx.seg;
          iStack_10 = 0;
        }
        uStack_c = dst_w;
        if ((int)(gfx.seg + *(int *)(in_stack_00000004->cmap + 5) + -1) <= (int)dst_w) {
          uStack_c = (gfx.seg + *(int *)(in_stack_00000004->cmap + 5)) - 1;
        }
        uStack_12 = (uStack_c - uStack_8) + 1;
        uStack_a = dst_y;
        if ((int)dst_y <= (int)x) {
          uStack_a = x;
        }
        uStack_e = dst_h;
        if ((int)(x + *(int *)(in_stack_00000004->cmap + 7) + -1) <= (int)dst_h) {
          uStack_e = (x + *(int *)(in_stack_00000004->cmap + 7)) - 1;
        }
        iStack_14 = (uStack_e - x) + 1;
        uStack_18 = uStack_8 + uStack_a * 0x140;
        uStack_16 = *(uint16_t *)(y + 8);
        puStack_1c = in_stack_00000004->cmap + 9;
        uStack_1a = gfx.ofs;
        for (iVar2 = 0; (iVar2 < iStack_14 && ((int)(iVar2 + x) <= (int)dst_h)); iVar2 = iVar2 + 1)
        {
          iVar1 = (*(code *)pfn)(uVar3,puStack_1c,uStack_1a,&rowBuf);
          puStack_1c = puStack_1c + iVar1;
          if ((int)dst_y <= (int)(iVar2 + x)) {
            src.seg = unaff_SS;
            src.ofs = (uint16_t)(&rowBuf + iStack_10);
            dst_00.seg = uStack_16;
            dst_00.ofs = uStack_18;
            uVar3 = 0x138e;
            blitTillAlpha(dst_00,src,uStack_12);
            uStack_18 = uStack_18 + 0x140;
          }
        }
      }
    }
    else {
      dst_01.seg = *(uint16_t *)(y + 8);
      dst_01.ofs = gfx.seg + x * 0x140;
      gfx_00.seg = gfx.ofs;
      gfx_00.ofs = (uint16_t)in_stack_00000004;
      drawGfx(gfx_00,dst_01,(*(uint8_t *)((uint8_t *)&(dst) + 2)));
    }
  }
  return;
}



/* 317e:04c2 */

/* [R4] calls drawGfx */

void __cdecl16far blit_usesDrawGfx(far_t gfx,int x,int y,brect_t *rect)

{
  far_t src;
  far_t dst;
  far_t dst_00;
  far_t handle;
  int iVar1;
  uint16_t in_DX;
  brect_t *pbVar2;
  int iVar3;
  uint16_t unaff_DI;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined1 uVar5;
  uint8_t rowBuf;
  int iStack_20;
  int iStack_1e;
  int iStack_1c;
  int iStack_1a;
  int iStack_18;
  uint16_t uStack_16;
  char *pcStack_14;
  uint16_t uStack_12;
  int iStack_10;
  word wStack_e;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  if (gfx.ofs != 0 || gfx.seg != 0) {
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) == '\0') {
      handle.seg = unaff_DI;
      handle.ofs = gfx.seg;
      gfx.ofs = (uint16_t)ovr_stshLoadGfx(handle,gfx.ofs);
      gfx.seg = in_DX;
    }
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) != '\x01') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(unaff_DI,0x1a);
    }
    iStack_1a = rect->x;
    uVar4 = (undefined2)((ulong)rect >> 0x10);
    pbVar2 = (brect_t *)rect;
    iStack_1c = pbVar2->y;
    iStack_1e = pbVar2->w;
    iStack_20 = pbVar2->h;
    if ((((x < iStack_1a) || (y < iStack_1c)) || (iStack_1e < x + *(int *)(gfx.ofs + 5) + -1)) ||
       (iStack_20 < y + *(int *)(gfx.ofs + 7) + -1)) {
      if ((iStack_1a <= x + *(int *)(gfx.ofs + 5) + -1) && (x <= iStack_1e)) {
        if (x < iStack_1a) {
          iStack_c = iStack_1a - x;
          iStack_4 = iStack_1a;
        }
        else {
          iStack_4 = x;
          iStack_c = 0;
        }
        iStack_8 = iStack_1e;
        if (x + *(int *)(gfx.ofs + 5) + -1 <= iStack_1e) {
          iStack_8 = x + *(int *)(gfx.ofs + 5) + -1;
        }
        wStack_e = (iStack_8 - iStack_4) + 1;
        iStack_6 = iStack_1c;
        if (iStack_1c <= y) {
          iStack_6 = y;
        }
        iStack_a = iStack_20;
        if (y + *(int *)(gfx.ofs + 7) + -1 <= iStack_20) {
          iStack_a = y + *(int *)(gfx.ofs + 7) + -1;
        }
        iStack_10 = (iStack_a - y) + 1;
        pcStack_14 = (char *)(iStack_4 + iStack_6 * 0x140);
        uStack_12 = pbVar2->seg;
        iStack_18 = gfx.ofs + 9;
        uStack_16 = gfx.seg;
        for (iVar3 = 0; (iVar3 < iStack_10 && (iVar3 + y <= iStack_20)); iVar3 = iVar3 + 1) {
          uVar5 = (undefined1)*(undefined2 *)(gfx.ofs + 5);
          src.seg = (uint16_t)&rowBuf;
          src.ofs = uStack_16;
          (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = uVar5;
          dst_00.ofs = unaff_SS;
          (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = (char)((uint)*(undefined2 *)(gfx.ofs + 5) >> 8);
          iVar1 = ovr_unrle(src,dst_00,unaff_DI,iStack_18,uVar5);
          iStack_18 = iStack_18 + iVar1;
          if (iStack_1c <= iVar3 + y) {
            memcpy((char *)CONCAT22(uStack_12,pcStack_14),
                   (char *)CONCAT22(unaff_SS,&rowBuf + iStack_c),wStack_e);
            pcStack_14 = pcStack_14 + 0x140;
          }
        }
      }
    }
    else {
      dst.seg = pbVar2->seg;
      dst.ofs = x + y * 0x140;
      drawGfx(gfx,dst,false);
    }
  }
  return;
}



/* 317e:06bc */

void __cdecl16far blitGfxN(far_t gfx,int16_t x,int16_t y,brect_t *dst,uint8_t type,bool mirror,...)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  far_t gfx_00;
  far_t handle;
  stg_tmp_t *psVar4;
  int src_sz;
  int iVar5;
  uint16_t in_DX;
  uint uVar6;
  undefined2 unaff_DI;
  undefined2 uVar7;
  char *unaff_SS;
  stg_tmp_t *in_stack_00000004;
  undefined1 type_00;
  undefined1 uVar8;
  char buf [320];
  uint8_t *puStack_1e;
  uint16_t pdst;
  uint16_t h;
  uint16_t sx;
  uint16_t pd;
  uint16_t srcsz;
  uint16_t skip;
  uint uStack_8;
  code *pcStack_6;
  code *pcStack_4;
  
  uVar7 = 0x317e;
  type_00 = (undefined1)unaff_DI;
  uVar8 = (undefined1)((uint)unaff_DI >> 8);
  if ((in_stack_00000004 != (stg_tmp_t *)0x0 || gfx.ofs != 0) && ((*(uint8_t *)((uint8_t *)&(dst) + 2)) != 0)) {
    psVar4 = (stg_tmp_t *)(uint)((stg_tmp_t *)CONCAT22(gfx.ofs,in_stack_00000004))->cmap[0];
    if (psVar4 == (stg_tmp_t *)0x0) {
      uVar7 = 0x2337;
      (*(uint8_t *)((uint8_t *)&(handle.seg))) = type_00;
      handle.ofs = gfx.ofs;
      (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uVar8;
      psVar4 = ovr_stshLoadGfx(handle,in_stack_00000004);
      in_stack_00000004 = psVar4;
      gfx.ofs = in_DX;
    }
    if (((stg_tmp_t *)CONCAT22(gfx.ofs,in_stack_00000004))->cmap[0] != 0x1) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(CONCAT11(uVar8,type_00),0x1a);
    }
    if ((*(uint8_t *)((uint8_t *)&(dst) + 2)) < 0x10) {
      pd = *(uint16_t *)CONCAT22((brect_t *)dst,y);
      uVar1 = *(uint *)(y + 2);
      uVar2 = *(uint *)(y + 6);
      if ((int)gfx.seg < (int)pd) {
        skip = pd - gfx.seg;
      }
      else {
        pd = gfx.seg;
        skip = 0;
      }
      src_sz = (*(int *)(y + 4) - pd) + 1;
      if (0 < src_sz) {
        pdst = pd + x * 0x140;
        pcVar3 = (char *)*(undefined2 *)(y + 8);
        uVar6 = 1;
        if (type == 0x0) {
          pcStack_6 = (code *)ovr_unrle;
        }
        else {
          pcStack_6 = (code *)ovr_unrle_mirror;
        }
        pcStack_4 = (code *)0x22a6;
        puStack_1e = in_stack_00000004->cmap + 9;
        uStack_8 = 0;
        while ((uStack_8 < *(uint *)(in_stack_00000004->cmap + 7) && ((uint)x <= uVar2))) {
          iVar5 = (*pcStack_6)(uVar7,puStack_1e,gfx.ofs,buf);
          puStack_1e = puStack_1e + iVar5;
          if ((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(dst) + 2)) * 2 + 0x470) & uVar6) != 0) {
            if (uVar1 <= (uint)x) {
              uVar7 = 0x22a6;
              ovr_masked_memcpy((char *)CONCAT22(buf,pcVar3),(char *)CONCAT22(skip,unaff_SS),
                                *(int *)(in_stack_00000004->cmap + 5),src_sz,
                                *(int *)((uint)(*(uint8_t *)((uint8_t *)&(dst) + 2)) * 2 + 0x470),pdst);
            }
            pdst = pdst + 0x140;
            x = x + 1;
          }
          if (uVar6 == 0x8000) {
            uVar6 = 1;
          }
          else {
            uVar6 = uVar6 << 1;
          }
          uStack_8 = uStack_8 + 1;
        }
      }
    }
    else {
      gfx_00.seg = gfx.seg;
      gfx_00.ofs = gfx.ofs;
      blitGfx10(gfx_00,x,y,
                (brect_t *)CONCAT22(CONCAT11((char)((uint)psVar4 >> 8),type),(brect_t *)dst),
                (bool)type_00,in_stack_00000004);
    }
  }
  return;
}



/* 317e:0879 */

/* [R4] calls ovr_randBelow */

void __cdecl16far blit_usesRandBelow(byte *buf,uint16_t count,byte value,byte chance)

{
  uint16_t uVar1;
  uint16_t unaff_SI;
  
  while (count != 0) {
    if (*buf != 0) {
      uVar1 = ovr_randBelow(unaff_SI,0x100);
      if (chance < (byte)uVar1) {
        *buf = 0;
      }
      else {
        *buf = value;
      }
    }
    buf = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(buf) + 2)),(byte *)buf + 1);
    count = count - 1;
  }
  return;
}



/* 317e:08ba */

void __cdecl16far copyGrayscalePalette(uint8_t *dst,int count)

{
  while (count != 0) {
    *dst = *(uint8_t *)(GrayscalePalette.ofs + (uint)*dst);
    dst = (uint8_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(dst) + 2)),(uint8_t *)dst + 1);
    count = count + -1;
  }
  return;
}



/* 317e:08ed */

void __cdecl16far gfxRlePrepare(far_t gfx,int x,int y,int *rectOfs,char scale,char flip,...)

{
  far_t pattern;
  far_t handle;
  uint uVar1;
  int iVar2;
  uint16_t in_DX;
  uint uVar3;
  uint16_t unaff_DI;
  char *unaff_SS;
  stg_tmp_t *in_stack_00000004;
  uint8_t in_stack_00000016;
  char in_stack_00000018;
  far_t buf;
  uint8_t skip;
  uint8_t *puStack_1e;
  uint16_t uStack_1c;
  int iStack_1a;
  char *pcStack_18;
  uint uStack_16;
  int iStack_14;
  uint uStack_12;
  uint16_t uStack_10;
  uint16_t uStack_e;
  int iStack_c;
  uint uStack_a;
  uint uStack_8;
  far_t *pfStack_6;
  far_t *pfStack_4;
  
  if ((in_stack_00000004 != (stg_tmp_t *)0x0 || gfx.ofs != 0) && ((*(uint8_t *)((uint8_t *)&(rectOfs) + 2)) != 0)) {
    if (((stg_tmp_t *)CONCAT22(gfx.ofs,in_stack_00000004))->cmap[0] == 0x0) {
      handle.seg = unaff_DI;
      handle.ofs = gfx.ofs;
      in_stack_00000004 = ovr_stshLoadGfx(handle,in_stack_00000004);
      gfx.ofs = in_DX;
    }
    if (((stg_tmp_t *)CONCAT22(gfx.ofs,in_stack_00000004))->cmap[0] != 0x2) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(unaff_DI,0x1a);
    }
    uStack_10 = *(uint16_t *)CONCAT22((int *)rectOfs,y);
    uStack_12 = *(uint *)(y + 2);
    iStack_14 = *(int *)(y + 4);
    uStack_16 = *(uint *)(y + 6);
    if (scale == '\0') {
      uVar1 = (int)((uint)(*(uint8_t *)((uint8_t *)&(rectOfs) + 2)) * *(int *)(in_stack_00000004->cmap + 1)) >> 4;
    }
    else {
      uVar1 = (uint)(*(uint8_t *)((uint8_t *)&(rectOfs) + 2)) *
              ((*(int *)(in_stack_00000004->cmap + 10) + -1) - *(int *)(in_stack_00000004->cmap + 1)
              ) >> 4;
    }
    gfx.seg = gfx.seg - uVar1;
    uVar1 = x - ((int)((uint)(*(uint8_t *)((uint8_t *)&(rectOfs) + 2)) * *(int *)(in_stack_00000004->cmap + 3)) >> 4);
    if ((int)gfx.seg < (int)uStack_10) {
      uStack_a = uStack_10 - gfx.seg;
      uStack_e = uStack_10;
      if (*(uint *)(in_stack_00000004->cmap + 10) <= uStack_a) {
        return;
      }
    }
    else {
      uStack_e = gfx.seg;
      uStack_a = 0;
    }
    iStack_c = (iStack_14 - uStack_e) + 1;
    if (0 < iStack_c) {
      iStack_1a = uStack_e + uVar1 * 0x140;
      pcStack_18 = (char *)*(undefined2 *)(y + 8);
      uVar3 = 1;
      if (scale == '\0') {
        pfStack_6 = (far_t *)(GUnitDescriptions + 0x12);
      }
      else {
        pfStack_6 = (far_t *)&GUnitDescriptions[0xf].seg;
      }
      pfStack_4 = (far_t *)0x22a6;
      puStack_1e = in_stack_00000004->cmap + 0xe;
      uStack_1c = gfx.ofs;
      uStack_e = iStack_1a;
      if (flip == -1) {
        uStack_8 = 0;
        while ((uStack_8 < *(uint *)(in_stack_00000004->cmap + 0xc) && (uVar1 <= uStack_16))) {
          iVar2 = (*(code *)pfStack_6)();
          puStack_1e = puStack_1e + iVar2;
          if ((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(rectOfs) + 2)) * 2 + 0x470) & uVar3) != 0) {
            if (uStack_12 <= uVar1) {
              copyGrayscalePalette
                        ((uint8_t *)CONCAT22(unaff_SS,&skip + uStack_a),
                         *(int *)(in_stack_00000004->cmap + 10) - uStack_a);
              ovr_masked_memcpy((char *)CONCAT22(&skip,pcStack_18),
                                (char *)CONCAT22(uStack_a,unaff_SS),
                                *(int *)(in_stack_00000004->cmap + 10),iStack_c,
                                *(int *)((uint)(*(uint8_t *)((uint8_t *)&(rectOfs) + 2)) * 2 + 0x470),unaff_DI,iStack_1a,
                                (char)*(int *)(in_stack_00000004->cmap + 10));
            }
            iStack_1a = iStack_1a + 0x140;
            uVar1 = uVar1 + 1;
          }
          if (uVar3 == 0x8000) {
            uVar3 = 1;
          }
          else {
            uVar3 = uVar3 << 1;
          }
          uStack_8 = uStack_8 + 1;
        }
      }
      else {
        uStack_8 = 0;
        while ((uStack_8 < *(uint *)(in_stack_00000004->cmap + 0xc) && (uVar1 <= uStack_16))) {
          iVar2 = (*(code *)pfStack_6)();
          puStack_1e = puStack_1e + iVar2;
          if ((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(rectOfs) + 2)) * 2 + 0x470) & uVar3) != 0) {
            if (uStack_12 <= uVar1) {
              buf.seg = *(int *)(in_stack_00000004->cmap + 10) - uStack_a;
              buf.ofs = (uint16_t)unaff_SS;
              (*(uint8_t *)((uint8_t *)&(pattern.seg))) = in_stack_00000018;
              pattern.ofs = 0x1529;
              (*(uint8_t *)((uint8_t *)&(pattern.seg) + 1)) = 0;
              ovr_driver_scan1(buf,(uint)(byte)flip,in_stack_00000016,0x0,pattern,unaff_DI,
                               &skip + uStack_a,0);
              in_stack_00000018 = in_stack_00000018 + (in_stack_00000004->cmap[10] - (char)uStack_a)
              ;
              ovr_masked_memcpy((char *)CONCAT22(&skip,pcStack_18),
                                (char *)CONCAT22(uStack_a,unaff_SS),
                                *(int *)(in_stack_00000004->cmap + 10),iStack_c,
                                *(int *)((uint)(*(uint8_t *)((uint8_t *)&(rectOfs) + 2)) * 2 + 0x470),unaff_DI,iStack_1a,
                                (char)*(int *)(in_stack_00000004->cmap + 10));
            }
            iStack_1a = iStack_1a + 0x140;
            uVar1 = uVar1 + 1;
          }
          if (uVar3 == 0x8000) {
            uVar3 = 1;
          }
          else {
            uVar3 = uVar3 << 1;
          }
          uStack_8 = uStack_8 + 1;
        }
      }
    }
  }
  return;
}



/* 317e:0bf2 */

/* Blits graphics inside the dst rect */

void __cdecl16far
blitGfxRect(far_t gfx,int16_t x,int16_t y,brect_t *dst,uint8_t type,bool mirror,...)

{
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t handle;
  stg_tmp_t *psVar1;
  undefined1 uVar2;
  uint16_t in_DX;
  undefined2 unaff_DI;
  stg_tmp_t *in_stack_00000004;
  undefined1 mirror_00;
  
  mirror_00 = (undefined1)unaff_DI;
  if (in_stack_00000004 != (stg_tmp_t *)0x0 || gfx.ofs != 0) {
    psVar1 = (stg_tmp_t *)(uint)((stg_tmp_t *)CONCAT22(gfx.ofs,in_stack_00000004))->cmap[0];
    if (psVar1 == (stg_tmp_t *)0x0) {
      (*(uint8_t *)((uint8_t *)&(handle.seg))) = mirror_00;
      handle.ofs = gfx.ofs;
      (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)unaff_DI >> 8);
      psVar1 = ovr_stshLoadGfx(handle,in_stack_00000004);
      in_stack_00000004 = psVar1;
      gfx.ofs = in_DX;
    }
    if (((stg_tmp_t *)CONCAT22(gfx.ofs,in_stack_00000004))->cmap[0] == 0x1) {
      uVar2 = (undefined1)((uint)psVar1 >> 8);
      if ((*(uint8_t *)((uint8_t *)&(dst) + 2)) == 0x10) {
        gfx_03.seg = gfx.seg;
        gfx_03.ofs = gfx.ofs;
        blitGfx10(gfx_03,x,y,(brect_t *)CONCAT13(uVar2,CONCAT12(type,(brect_t *)dst)),
                  (bool)mirror_00,in_stack_00000004,type);
      }
      else {
        gfx_00.seg = gfx.seg;
        gfx_00.ofs = gfx.ofs;
        blitGfxN(gfx_00,x,y,(brect_t *)CONCAT22(CONCAT11(uVar2,(*(uint8_t *)((uint8_t *)&(dst) + 2))),(brect_t *)dst),type,
                 (bool)mirror_00,in_stack_00000004,type);
      }
    }
    else if (((stg_tmp_t *)CONCAT22(gfx.ofs,in_stack_00000004))->cmap[0] == 0x2) {
      if (type == 0x0) {
        if ((*(uint8_t *)((uint8_t *)&(dst) + 2)) == 0x10) {
          gfx_04.seg = gfx.seg - *(int *)(in_stack_00000004->cmap + 1);
          gfx_04.ofs = gfx.ofs;
          blitGfx10(gfx_04,x - *(int *)(in_stack_00000004->cmap + 3),y,
                    (brect_t *)((ulong)dst & 0xffff),(bool)mirror_00,in_stack_00000004->cmap + 5,0);
        }
        else {
          gfx_01.seg = gfx.seg - ((int)((uint)(*(uint8_t *)((uint8_t *)&(dst) + 2)) * *(int *)(in_stack_00000004->cmap + 1)) >>
                                 4);
          gfx_01.ofs = gfx.ofs;
          blitGfxN(gfx_01,x - ((int)((uint)(*(uint8_t *)((uint8_t *)&(dst) + 2)) * *(int *)(in_stack_00000004->cmap + 3)) >> 4),
                   y,(brect_t *)((ulong)dst & 0xffffff),0x0,(bool)mirror_00,
                   in_stack_00000004->cmap + 5,0);
        }
      }
      else if ((*(uint8_t *)((uint8_t *)&(dst) + 2)) == 0x10) {
        gfx_05.seg = (gfx.seg + *(int *)(in_stack_00000004->cmap + 1)) -
                     (*(int *)(in_stack_00000004->cmap + 10) + -1);
        gfx_05.ofs = gfx.ofs;
        blitGfx10(gfx_05,x - *(int *)(in_stack_00000004->cmap + 3),y,
                  (brect_t *)(ulong)CONCAT12(type,(brect_t *)dst),(bool)mirror_00,
                  in_stack_00000004->cmap + 5,type);
      }
      else {
        gfx_02.seg = gfx.seg - ((uint)(*(uint8_t *)((uint8_t *)&(dst) + 2)) *
                                ((*(int *)(in_stack_00000004->cmap + 10) + -1) -
                                *(int *)(in_stack_00000004->cmap + 1)) >> 4);
        gfx_02.ofs = gfx.ofs;
        blitGfxN(gfx_02,x - ((int)((uint)(*(uint8_t *)((uint8_t *)&(dst) + 2)) * *(int *)(in_stack_00000004->cmap + 3)) >> 4),y,
                 (brect_t *)((ulong)dst & 0xffffff),type,(bool)mirror_00,in_stack_00000004->cmap + 5
                 ,type);
      }
    }
    else {
      printf("error(27) \r");
      ovr_biosReadKey();
    }
  }
  return;
}



/* 317e:0db7 */

/* [R4] calls blitGfxN */

void __cdecl16far
blit_usesBlitGfxN(far_t gfx,int16_t x,int y,byte shade1,int y2,byte shade2,brect_t *rect,
                 uint16_t type,...)

{
  int16_t iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int unaff_DI;
  undefined2 in_stack_00000004;
  int iStack_c;
  int iStack_a;
  uint uStack_4;
  
  iVar4 = y;
  iVar1 = x;
  if (shade1 < x) {
    x = shade1;
    shade1 = iVar1;
    y = y2 & 0xff;
    y2 = iVar4 & 0xff;
  }
  uVar2 = shade1 - x >> 1;
  if (uVar2 == 0) {
    iStack_a = 0;
    iStack_c = 0;
  }
  else {
    iStack_a = (int)((y2 & 0xffU) - (y & 0xffU)) / (int)uVar2;
    uVar5 = (int)((y2 & 0xffU) - (y & 0xffU)) % (int)uVar2;
    uVar3 = (int)uVar5 >> 0xf;
    iStack_c = (uVar5 ^ uVar3) - uVar3;
  }
  uVar3 = ovr_ovc07_signum(unaff_DI,(y2 & 0xffU) - (y & 0xffU));
  uVar6 = shade1 - x >> 0xf;
  iVar4 = (int)((uVar2 ^ uVar6) - uVar6) >> 1;
  uVar5 = y & 0xff;
  uStack_4 = uVar5;
  for (; x <= shade1; x = x + 2) {
    blitGfxN(gfx,x,shade2,
             (brect_t *)CONCAT22(CONCAT11((char)(uVar5 >> 8),(undefined1)uStack_4),(brect_t *)rect),
             0x0,SUB21(unaff_DI,0),in_stack_00000004);
    uStack_4 = uStack_4 + iStack_a;
    iVar4 = iVar4 + iStack_c;
    uVar5 = (uVar2 ^ uVar6) - uVar6;
    if ((int)uVar5 <= iVar4) {
      iVar4 = iVar4 - ((uVar2 ^ uVar6) - uVar6);
      uStack_4 = uStack_4 + uVar3;
      uVar5 = uVar3;
    }
  }
  return;
}



/* 317e:0ebe */

/* [R7] body shape: compute */

void __cdecl16far
blit_compute1(uint16_t dstSeg,int16_t y,int16_t x,far_t src,uint16_t imgWidth,uint16_t clipWidth,
             uint16_t mask,uint16_t dx,int16_t ySlope,int16_t yRemainder,int16_t yStep,int16_t yJump
             ,int16_t clipTop,int16_t clipBottom)

{
  int iVar1;
  uint uVar2;
  uint uStack_c;
  uint uStack_a;
  uint uStack_8;
  int16_t iStack_6;
  
  iVar1 = ySlope >> 1;
  uVar2 = 1;
  iStack_6 = x;
  uStack_a = 0;
  uStack_c = 0;
  uStack_8 = 0;
  do {
    if (clipWidth <= uStack_8) {
      return;
    }
    if ((dx & uVar2) != 0) {
      if (imgWidth <= uStack_a) {
        if (((*(char *)(src.ofs + uStack_8) != '\0') && (clipTop <= y)) && (y <= clipBottom)) {
          *(undefined1 *)(iStack_6 + y * 0x140) = *(undefined1 *)(src.ofs + uStack_8);
        }
        iStack_6 = iStack_6 + 1;
        uStack_c = uStack_c + 1;
        if (mask <= uStack_c) {
          return;
        }
      }
      uStack_a = uStack_a + 1;
      iVar1 = iVar1 + yStep;
      y = y + yRemainder;
      if (ySlope <= iVar1) {
        y = y + yJump;
        iVar1 = iVar1 - ySlope;
      }
    }
    if (uVar2 == 0x8000) {
      uVar2 = 1;
    }
    else {
      uVar2 = uVar2 << 1;
    }
    uStack_8 = uStack_8 + 1;
  } while( true );
}



/* 317e:0f7d */

/* [R4] calls ovr_stExit */

void __cdecl16far
blit_usesStExit(far_t gfx,int x1,int y1,byte shade1,int x2,int y2,byte shade2,int *rectOfs,...)

{
  uint16_t uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint16_t in_DX;
  uint uVar5;
  uint uVar6;
  uint16_t unaff_DI;
  uint16_t unaff_SS;
  stg_tmp_t *in_stack_00000004;
  undefined1 uStack0015;
  far_t src;
  far_t handle;
  uint8_t rowBuf;
  uint8_t *puStack_28;
  uint16_t uStack_26;
  int iStack_24;
  int iStack_22;
  int16_t iStack_20;
  int iStack_1e;
  int iStack_1c;
  int iStack_1a;
  int iStack_18;
  int16_t iStack_16;
  uint16_t uStack_14;
  uint16_t uStack_12;
  uint16_t uStack_10;
  uint uStack_e;
  uint16_t uStack_c;
  uint uStack_a;
  byte bStack_7;
  far_t *pfStack_6;
  far_t *pfStack_4;
  
  iVar3 = x1;
  uVar1 = gfx.seg;
  bVar2 = (byte)y1;
  if ((int)shade1 < (int)gfx.seg) {
    gfx.seg = shade1;
    shade1 = uVar1;
    x1 = x2;
    x2 = iVar3;
    uStack_a = y1 & 0xff;
    bVar2 = (byte)y2;
    (*(uint8_t *)((uint8_t *)&(y2))) = (byte)y1;
  }
  (*(uint8_t *)((uint8_t *)&(y1))) = bVar2;
  if ((in_stack_00000004 != (stg_tmp_t *)0x0 || gfx.ofs != 0) && ((byte)y1 != 0)) {
    if (((stg_tmp_t *)CONCAT22(gfx.ofs,in_stack_00000004))->cmap[0] == 0x0) {
      handle.seg = unaff_DI;
      handle.ofs = gfx.ofs;
      in_stack_00000004 = ovr_stshLoadGfx(handle,in_stack_00000004);
      gfx.ofs = in_DX;
    }
    if (((stg_tmp_t *)CONCAT22(gfx.ofs,in_stack_00000004))->cmap[0] != 0x1) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit();
    }
    uStack_14 = *(uint16_t *)CONCAT22((int *)rectOfs,(uint16_t *)CONCAT11(uStack0015,shade2));
    iStack_16 = *(int16_t *)(CONCAT11(uStack0015,shade2) + 2);
    iStack_18 = *(int *)(CONCAT11(uStack0015,shade2) + 4);
    iStack_1a = *(int *)(CONCAT11(uStack0015,shade2) + 6);
    if ((int)gfx.seg < (int)uStack_14) {
      uStack_c = uStack_14 - gfx.seg;
      uStack_12 = uStack_14;
    }
    else {
      uStack_12 = gfx.seg;
      uStack_c = 0;
    }
    if (iStack_18 < (int)shade1) {
      iVar3 = iStack_18 - uStack_12;
    }
    else {
      iVar3 = shade1 - uStack_12;
    }
    uStack_10 = iVar3 + 1;
    if (0 < (int)uStack_10) {
      bStack_7 = (byte)y2;
      if ((byte)y2 < (byte)y1) {
        bStack_7 = (byte)y1;
      }
      iVar3 = x1 - (*(int *)(in_stack_00000004->cmap + 7) * (uint)bStack_7 >> 4);
      uVar6 = 1;
      if ((*(uint8_t *)((uint8_t *)&(rectOfs) + 2)) == '\0') {
        pfStack_6 = (far_t *)(GUnitDescriptions + 0x12);
      }
      else {
        pfStack_6 = (far_t *)&GUnitDescriptions[0xf].seg;
      }
      pfStack_4 = (far_t *)0x22a6;
      puStack_28 = in_stack_00000004->cmap + 9;
      uStack_26 = gfx.ofs;
      iStack_22 = shade1 - gfx.seg;
      iStack_24 = (x2 - (*(int *)(in_stack_00000004->cmap + 7) * (uint)bStack_7 >> 4)) - iVar3;
      if (iStack_22 == 0) {
        iStack_1c = 0;
        iStack_1e = 0;
      }
      else {
        iStack_1c = iStack_24 / iStack_22;
        uVar5 = iStack_24 % iStack_22 >> 0xf;
        iStack_1e = (iStack_24 % iStack_22 ^ uVar5) - uVar5;
      }
      iStack_20 = ovr_ovc07_signum();
      uStack_e = 0;
      while ((uStack_e < *(uint *)(in_stack_00000004->cmap + 7) && (iVar3 <= iStack_1a))) {
        iVar4 = (*(code *)pfStack_6)(0x22da,puStack_28,uStack_26,&rowBuf);
        puStack_28 = puStack_28 + iVar4;
        if ((*(uint *)((uint)bStack_7 * 2 + 0x470) & uVar6) != 0) {
          src.seg = unaff_SS;
          src.ofs = (uint16_t)&rowBuf;
          blit_compute1(*(uint16_t *)(CONCAT11(uStack0015,shade2) + 8),iVar3,uStack_12,src,uStack_c,
                        *(uint16_t *)(in_stack_00000004->cmap + 5),uStack_10,
                        *(uint16_t *)((uint)bStack_7 * 2 + 0x470),iStack_22,iStack_1c,iStack_1e,
                        iStack_20,iStack_16,iStack_1a);
          iVar3 = iVar3 + 1;
        }
        if (uVar6 == 0x8000) {
          uVar6 = 1;
        }
        else {
          uVar6 = uVar6 << 1;
        }
        uStack_e = uStack_e + 1;
      }
    }
  }
  return;
}



/* 317e:11f0 */

void __cdecl16far gfxInitRand(void)

{
  uint uVar1;
  uint16_t uVar2;
  undefined1 *puVar3;
  
  uVar1 = GfxRndSeed * 0x100;
  srand8(CONCAT22(((int)GfxRndSeed2 >> 0xf) + ((int)uVar1 >> 0xf) + (uint)CARRY2(GfxRndSeed2,uVar1),
                  GfxRndSeed2 + uVar1));
  for (puVar3 = (undefined1 *)0x0; (int)puVar3 < 0x100; puVar3 = puVar3 + 1) {
    uVar2 = ovr_randBelow();
    *puVar3 = (char)uVar2;
  }
  return;
}



/* 317e:1240 */

/* [R4] calls blitGfxN */

void __cdecl16far
blit_usesBlitGfxN2(far_t gfx,far_t gfx_00,int x1,int y1,byte shade1,int x2,int y2,byte shade2,
                  brect_t *rect,uint16_t type,byte highlightLevel,...)

{
  byte *pbVar1;
  uint16_t uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint16_t uVar8;
  uint unaff_DI;
  undefined2 in_stack_00000004;
  far_t gfx_01;
  far_t gfx_02;
  bool mirror;
  long lVar9;
  int iStack_1a;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  int iStack_e;
  int iStack_c;
  uint uStack_8;
  int iStack_6;
  byte *pbStack_4;
  
  uVar2 = shade1;
  iVar4 = y1;
  iVar3 = x1 + ((int)((y1 & 0xffU) * 0x38) >> 4);
  x2 = x2 + ((int)((y2 & 0xffU) * 0x38) >> 4);
  ovr_ovc07_usesLDIV_at_();
  uVar8 = gfx_00.seg;
  x1 = iVar3;
  if (x2 < iVar3) {
    shade1 = gfx_00.seg;
    y1 = y2 & 0xff;
    y2 = iVar4 & 0xff;
    uVar8 = uVar2;
    x1 = x2;
    x2 = iVar3;
  }
  iVar3 = (x2 - x1) / 4;
  if (iVar3 == 0) {
    iStack_c = 0;
    iStack_e = 0;
  }
  else {
    iStack_c = (int)((y2 & 0xffU) - (y1 & 0xffU)) / iVar3;
    uVar6 = (int)((y2 & 0xffU) - (y1 & 0xffU)) % iVar3;
    uVar7 = (int)uVar6 >> 0xf;
    iStack_e = (uVar6 ^ uVar7) - uVar7;
  }
  iVar4 = ovr_ovc07_signum();
  iStack_1a = iVar3 >> 1;
  if (iVar3 == 0) {
    iStack_14 = 0;
    iStack_16 = 0;
  }
  else {
    iStack_14 = (int)(shade1 - uVar8) / iVar3;
    uVar6 = (int)(shade1 - uVar8) % iVar3;
    uVar7 = (int)uVar6 >> 0xf;
    iStack_16 = (uVar6 ^ uVar7) - uVar7;
  }
  lVar9 = (ulong)unaff_DI << 0x10;
  iVar5 = ovr_ovc07_signum();
  uStack_8 = y1 & 0xff;
  pbStack_4 = (byte *)(uVar8 << 2);
  iStack_12 = iStack_1a;
  for (iStack_6 = x1; iStack_6 <= x2; iStack_6 = iStack_6 + 4) {
    pbVar1 = (byte *)((uint)pbStack_4 & 0xff);
    pbStack_4 = pbVar1 + 1;
    uVar6 = (uint)((ulong)lVar9 >> 0x10);
    mirror = SUB41((ulong)lVar9 >> 0x10,0);
    if ((*pbVar1 & 7) < (*(uint8_t *)((uint8_t *)&(rect) + 2))) {
      lVar9 = (ulong)uVar6 << 0x10;
      gfx_01.seg = uVar8 - 7;
      gfx_01.ofs = gfx.ofs;
      blitGfxN(gfx_01,iStack_6 + -2,shade2,
               (brect_t *)((ulong)CONCAT22(uStack_8,(brect_t *)rect) & 0xffffff),0x0,mirror,
               in_stack_00000004);
    }
    else {
      lVar9 = (ulong)uVar6 << 0x10;
      gfx_02.seg = uVar8 - 7;
      gfx_02.ofs = gfx_00.ofs;
      blitGfxN(gfx_02,iStack_6 + -2,shade2,
               (brect_t *)((ulong)CONCAT22(uStack_8,(brect_t *)rect) & 0xffffff),0x0,mirror,gfx.seg)
      ;
    }
    uStack_8 = uStack_8 + iStack_c;
    iStack_12 = iStack_12 + iStack_e;
    if (iVar3 <= iStack_12) {
      iStack_12 = iStack_12 - iVar3;
      uStack_8 = uStack_8 + iVar4;
    }
    uVar8 = uVar8 + iStack_14;
    iStack_1a = iStack_1a + iStack_16;
    if (iVar3 <= iStack_1a) {
      iStack_1a = iStack_1a - iVar3;
      uVar8 = uVar8 + iVar5;
    }
  }
  return;
}


