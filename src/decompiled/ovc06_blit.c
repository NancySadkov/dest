/*
 * ovc06_blit.c - recovered from STRONG.EXE
 * memory block: OVC06_blit.c
 * range: 317e:0000 - 317e:14af
 * functions: 17
 */
#include "recovered.h"


/* 317e:0000 */

far_t __cdecl16far
stshRleSub(uint8_t *src,uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,int16_t hdrsz)

{
  undefined2 uVar1;
  uint sz;
  void *pvVar2;
  uint16_t width;
  int rlesz;
  uint written;
  uint8_t *puVar3;
  int rows_left;
  void *block;
  far_t r;
  uint8_t *dst;
  uint8_t *prow;
  
  sz = ((ex - sx) + ((ex - sx) + 1 >> 7) + 2) * ((ey - sy) + 1);
  block = ovr_stshAlloc(CONCAT22((CARRY2(sz,hdrsz) - 1) + (uint)(sz + hdrsz != 0),sz + hdrsz + -1));
  pvVar2 = (void *)block;
  uVar1 = (undefined2)((ulong)block >> 0x10);
  prow = (uint8_t *)src + sx + sy * 0x140;
  puVar3 = (uint8_t *)((int)pvVar2 + hdrsz + -1);
  width = (ex - sx) + 1;
  rows_left = (ey - sy) + 1;
  dst = puVar3;
  while (rows_left != 0) {
    rlesz = ovr_rle_line((uint8_t *)CONCAT22(src._2_2_,prow),(uint8_t *)CONCAT22(uVar1,dst),width);
    dst = dst + rlesz;
    prow = prow + 0x140;
    rows_left = rows_left + -1;
  }
  written = (int)dst - (int)puVar3;
  if (written <= sz) {
    *(undefined2 *)((int)pvVar2 + hdrsz + -7) = 0;
    *(uint *)((int)pvVar2 + hdrsz + -9) = written;
    *(uint16_t *)((int)pvVar2 + hdrsz + -5) = width;
    *(int *)((int)pvVar2 + hdrsz + -3) = (ey - sy) + 1;
    *(undefined1 *)CONCAT22(uVar1,(undefined1 *)((int)pvVar2 + hdrsz + -10)) = 1;
    r = (far_t)ovr_stshRealloc((uint32_t)block,(ulong)((written + hdrsz) - 1));
    return r;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(5);
}



/* 317e:0148 */

/* Cuts X,Y,W,H rect out of 8bit pixels pointed by src.
   returns ptrr to stg_t struct */

far_t __cdecl16far stshRleCut(far_t src,int16_t sx,int16_t sy,int16_t ex,int16_t ey)

{
  far_t fVar1;
  
  fVar1 = stshRleSub((uint8_t *)src,sx,sy,ex,ey,10);
  return fVar1;
}



/* 317e:0168 */

far_t __cdecl16far
stshRleType2(far_t pixels,int16_t sx,int16_t sy,int16_t ex,int16_t ey,int16_t ox,int16_t oy)

{
  far_t fVar1;
  
  fVar1 = stshRleSub((uint8_t *)pixels,sx,sy,ex,ey,15);
  *(int16_t *)(fVar1.ofs + 1) = ox;
  *(int16_t *)(fVar1.ofs + 3) = oy;
  *(undefined1 *)fVar1 = 2;
  return fVar1;
}



/* 317e:01b2 */

void __cdecl16far blitLoadRleGfx(far_t gfx,far_t dst)

{
  int consumed;
  int height;
  byte *src_ofs;
  
  if (gfx.ofs != 0 || gfx.seg != 0) {
    if (*(char *)gfx == '\0') {
      gfx = (far_t)ovr_stshLoadGfx(gfx);
    }
    if (*(char *)gfx != '\x01') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
                    /* typedef struct { //stronghold graphics
                         uint8_t type;  //0=not loaded, 1=loaded
                         uint8_t sz;
                         uint16_t width;
                         uint16_t height;
                         uint8_t pixels[width*height];
                       } gfx_t; */
    src_ofs = (byte *)(gfx.ofs + 9);
    height = *(int *)(gfx.ofs + 7);
    while (height != 0) {
      consumed = ovr_rle_blit_decode(src_ofs,(byte *)dst.ofs,*(uint16_t *)(gfx.ofs + 5));
      src_ofs = src_ofs + consumed;
      dst.seg = 0;
      dst.ofs = dst.ofs + 0x140;
      height = height + -1;
    }
  }
  return;
}



/* 317e:0239 */

void __cdecl16far drawGfx(far_t gfx,far_t dst,bool type)

{
  int iVar1;
  int iVar2;
  undefined2 uStack_6;
  
  if (type) {
    if (gfx.ofs != 0 || gfx.seg != 0) {
      uStack_6 = gfx.ofs + 9;
      for (iVar2 = *(int *)(gfx.ofs + 7); iVar2 != 0; iVar2 = iVar2 + -1) {
        iVar1 = ovr_drawLine2(uStack_6,gfx.seg,dst.ofs,dst.seg,*(undefined2 *)(gfx.ofs + 5));
        uStack_6 = uStack_6 + iVar1;
        dst.ofs = dst.ofs + 0x140;
      }
    }
  }
  else {
    blitLoadRleGfx(gfx,dst);
  }
  return;
}



/* 317e:02a9 */

/* Blits the graphics on screen */

void __cdecl16far blitGfx10(far_t gfx,uint16_t x,uint16_t y,brect_t *dst,bool type)

{
  far_t dst_00;
  far_t src;
  int iVar1;
  brect_t *pdst;
  int iVar2;
  undefined2 uVar3;
  char *pcVar4;
  uint16_t unaff_SS;
  far_t dst_01;
  undefined1 local_164 [320];
  int dst_h;
  int dst_w;
  uint16_t dst_y;
  uint16_t dst_x;
  int iStack_1c;
  uint16_t uStack_1a;
  uint16_t uStack_18;
  uint16_t uStack_16;
  int iStack_14;
  uint16_t uStack_12;
  int iStack_10;
  int iStack_e;
  int iStack_c;
  uint16_t uStack_a;
  uint16_t uStack_8;
  code *pfn;
  code *pcStack_4;
  
  pcVar4 = (char *)"anim\\1ma3m.lbm" + 0xb;
  if (gfx.ofs != 0 || gfx.seg != 0) {
    if (*(char *)gfx == '\0') {
      pcVar4 = (char *)"glassworks" + 9;
      gfx = (far_t)ovr_stshLoadGfx(gfx);
    }
    if (*(char *)gfx != '\x01') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
    dst_x = dst->x;
    uVar3 = (undefined2)((ulong)dst >> 0x10);
    pdst = (brect_t *)dst;
    dst_y = pdst->y;
    dst_w = pdst->w;
    dst_h = pdst->h;
    if (((((int)x < (int)dst_x) || ((int)y < (int)dst_y)) ||
        (dst_w < (int)(x + *(int *)(gfx.ofs + 5) + -1))) ||
       (dst_h < (int)(y + *(int *)(gfx.ofs + 7) + -1))) {
      if (type == false) {
        pfn = (code *)ovr_unrle;
      }
      else {
        pfn = (code *)ovr_unrle_mirror;
      }
      pcStack_4 = (code *)0x22a6;
      if (((int)dst_x <= (int)(x + *(int *)(gfx.ofs + 5) + -1)) && ((int)x <= dst_w)) {
        if ((int)x < (int)dst_x) {
          iStack_10 = dst_x - x;
          uStack_8 = dst_x;
        }
        else {
          uStack_8 = x;
          iStack_10 = 0;
        }
        iStack_c = dst_w;
        if ((int)(x + *(int *)(gfx.ofs + 5) + -1) <= dst_w) {
          iStack_c = x + *(int *)(gfx.ofs + 5) + -1;
        }
        uStack_12 = (iStack_c - uStack_8) + 1;
        uStack_a = dst_y;
        if ((int)dst_y <= (int)y) {
          uStack_a = y;
        }
        iStack_e = dst_h;
        if ((int)(y + *(int *)(gfx.ofs + 7) + -1) <= dst_h) {
          iStack_e = y + *(int *)(gfx.ofs + 7) + -1;
        }
        iStack_14 = (iStack_e - y) + 1;
        uStack_18 = uStack_8 + uStack_a * 0x140;
        uStack_16 = pdst->seg;
        iStack_1c = gfx.ofs + 9;
        uStack_1a = gfx.seg;
        for (iVar2 = 0; (iVar2 < iStack_14 && ((int)(iVar2 + y) <= dst_h)); iVar2 = iVar2 + 1) {
          iVar1 = (*pfn)(pcVar4,iStack_1c,uStack_1a,local_164);
          iStack_1c = iStack_1c + iVar1;
          if ((int)dst_y <= (int)(iVar2 + y)) {
            dst_01.seg = uStack_16;
            dst_01.ofs = uStack_18;
            pcVar4 = (char *)0x138e;
            src.seg = unaff_SS;
            src.ofs = (uint16_t)(local_164 + iStack_10);
            blitTillAlpha(dst_01,src,uStack_12);
            uStack_18 = uStack_18 + 0x140;
          }
        }
      }
    }
    else {
      dst_00.seg = pdst->seg;
      dst_00.ofs = x + y * 0x140;
      drawGfx(gfx,dst_00,type);
    }
  }
  return;
}



/* 317e:04c2 */

void __cdecl16far blit_317e_04c2(far_t param_1,int param_2,int param_3,int *param_4)

{
  far_t dst;
  far_t dst_00;
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined2 uVar4;
  uint16_t unaff_SS;
  far_t src;
  uint8_t local_160 [320];
  int iStack_20;
  int iStack_1e;
  int iStack_1c;
  int iStack_1a;
  uint16_t uStack_18;
  uint16_t uStack_16;
  uint8_t *puStack_14;
  int iStack_12;
  int iStack_10;
  uint16_t uStack_e;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  if (param_1.ofs != 0 || param_1.seg != 0) {
    if (*(char *)param_1 == '\0') {
      param_1 = (far_t)ovr_stshLoadGfx(param_1);
    }
    if (*(char *)param_1 != '\x01') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
    iStack_1a = *param_4;
    uVar4 = (undefined2)((ulong)param_4 >> 0x10);
    piVar2 = (int *)param_4;
    iStack_1c = piVar2[1];
    iStack_1e = piVar2[2];
    iStack_20 = piVar2[3];
    if ((((param_2 < iStack_1a) || (param_3 < iStack_1c)) ||
        (iStack_1e < param_2 + *(int *)(param_1.ofs + 5) + -1)) ||
       (iStack_20 < param_3 + *(int *)(param_1.ofs + 7) + -1)) {
      if ((iStack_1a <= param_2 + *(int *)(param_1.ofs + 5) + -1) && (param_2 <= iStack_1e)) {
        if (param_2 < iStack_1a) {
          iStack_c = iStack_1a - param_2;
          iStack_4 = iStack_1a;
        }
        else {
          iStack_4 = param_2;
          iStack_c = 0;
        }
        iStack_8 = iStack_1e;
        if (param_2 + *(int *)(param_1.ofs + 5) + -1 <= iStack_1e) {
          iStack_8 = param_2 + *(int *)(param_1.ofs + 5) + -1;
        }
        uStack_e = (iStack_8 - iStack_4) + 1;
        iStack_6 = iStack_1c;
        if (iStack_1c <= param_3) {
          iStack_6 = param_3;
        }
        iStack_a = iStack_20;
        if (param_3 + *(int *)(param_1.ofs + 7) + -1 <= iStack_20) {
          iStack_a = param_3 + *(int *)(param_1.ofs + 7) + -1;
        }
        iStack_10 = (iStack_a - param_3) + 1;
        puStack_14 = (uint8_t *)(iStack_4 + iStack_6 * 0x140);
        iStack_12 = piVar2[4];
        uStack_18 = param_1.ofs + 9;
        uStack_16 = param_1.seg;
        for (iVar3 = 0; (iVar3 < iStack_10 && (iVar3 + param_3 <= iStack_20)); iVar3 = iVar3 + 1) {
          src.seg = uStack_16;
          src.ofs = uStack_18;
          dst_00.seg = unaff_SS;
          dst_00.ofs = (uint16_t)local_160;
          iVar1 = ovr_unrle(src,dst_00,*(uint16_t *)(param_1.ofs + 5));
          uStack_18 = uStack_18 + iVar1;
          if (iStack_1c <= iVar3 + param_3) {
            memcpy(puStack_14,local_160 + iStack_c,uStack_e);
            puStack_14 = puStack_14 + 0x140;
          }
        }
      }
    }
    else {
      dst.seg = piVar2[4];
      dst.ofs = param_2 + param_3 * 0x140;
      drawGfx(param_1,dst,false);
    }
  }
  return;
}



/* 317e:06bc */

void __cdecl16far blitGfxN(far_t gfx,int16_t x,int16_t y,brect_t *dst,uint8_t type,bool mirror)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  undefined2 unaff_SS;
  char buf [320];
  int iStack_1e;
  uint16_t uStack_1c;
  char *pdst;
  uint16_t uStack_18;
  uint h;
  int iStack_14;
  uint sx;
  int iStack_10;
  char *pd;
  int srcsz;
  int skip;
  uint uStack_8;
  code *pcStack_6;
  code *pcStack_4;
  
  pcVar3 = (char *)"anim\\1ma3m.lbm" + 0xb;
  if ((gfx.ofs != 0 || gfx.seg != 0) && (type != 0x0)) {
    if (*(char *)gfx == '\0') {
      pcVar3 = (char *)"glassworks" + 9;
      gfx = (far_t)ovr_stshLoadGfx(gfx);
    }
    if (*(char *)gfx != '\x01') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
    if (type < 0x10) {
      iStack_10 = dst->x;
      sx = ((brect_t *)dst)->y;
      iStack_14 = ((brect_t *)dst)->w;
      h = ((brect_t *)dst)->h;
      if (x < iStack_10) {
        skip = iStack_10 - x;
        pd = (char *)iStack_10;
      }
      else {
        pd = (char *)x;
        skip = 0;
      }
      srcsz = (iStack_14 - (int)pd) + 1;
      if (0 < srcsz) {
        pdst = (char *)((int)pd + y * 0x140);
        uStack_18 = ((brect_t *)dst)->seg;
        uVar2 = 1;
        if (mirror) {
          pcStack_6 = (code *)ovr_unrle_mirror;
        }
        else {
          pcStack_6 = (code *)ovr_unrle;
        }
        pcStack_4 = (code *)0x22a6;
        iStack_1e = gfx.ofs + 9;
        uStack_1c = gfx.seg;
        uStack_8 = 0;
        pd = pdst;
        while ((uStack_8 < *(uint *)(gfx.ofs + 7) && ((uint)y <= h))) {
          iVar1 = (*pcStack_6)(pcVar3,iStack_1e,uStack_1c,buf);
          iStack_1e = iStack_1e + iVar1;
          if ((*(uint *)((uint)type * 2 + 0x470) & uVar2) != 0) {
            if (sx <= (uint)y) {
              pcVar3 = (char *)"arrowsmith" + 3;
              ovr_masked_memcpy((char *)CONCAT22(uStack_18,pdst),(char *)CONCAT22(unaff_SS,buf),skip
                                ,*(int *)(gfx.ofs + 5),srcsz,*(uint *)((uint)type * 2 + 0x470));
            }
            pdst = pdst + 0x140;
            y = y + 1;
          }
          if (uVar2 == 0x8000) {
            uVar2 = 1;
          }
          else {
            uVar2 = uVar2 << 1;
          }
          uStack_8 = uStack_8 + 1;
        }
      }
    }
    else {
      blitGfx10(gfx,x,y,dst,mirror);
    }
  }
  return;
}



/* 317e:0879 */

void __cdecl16far blit_317e_0879(char *param_1,int param_2,char param_3,byte param_4)

{
  uint16_t uVar1;
  
  while (param_2 != 0) {
    if (*param_1 != '\0') {
      uVar1 = ovr_randBelow(0x100);
      if (param_4 < (byte)uVar1) {
        *param_1 = '\0';
      }
      else {
        *param_1 = param_3;
      }
    }
    param_1 = (char *)CONCAT22(param_1._2_2_,(char *)param_1 + 1);
    param_2 = param_2 + -1;
  }
  return;
}



/* 317e:08ba */

void __cdecl16far copyGrayscalePalette(uint8_t *dst,int count)

{
  while (count != 0) {
    *dst = *(uint8_t *)(GrayscalePalette.ofs + (uint)*dst);
    dst = (uint8_t *)CONCAT22(dst._2_2_,(uint8_t *)dst + 1);
    count = count + -1;
  }
  return;
}



/* 317e:08ed */

void __cdecl16far
gfxRlePrepare(far_t gfx,int param_2,int param_3,int *param_4,byte param_5,char param_6,char param_7)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined2 uVar5;
  char *pcVar6;
  undefined2 unaff_SS;
  uint8_t local_15e [320];
  uint8_t *puStack_1e;
  uint16_t uStack_1c;
  char *pcStack_1a;
  int iStack_18;
  uint uStack_16;
  int iStack_14;
  uint uStack_12;
  int iStack_10;
  char *pcStack_e;
  int iStack_c;
  uint uStack_a;
  uint uStack_8;
  far_t *pfStack_6;
  far_t *pfStack_4;
  
  pcVar6 = (char *)"anim\\1ma3m.lbm" + 0xb;
  if ((gfx.ofs != 0 || gfx.seg != 0) && (param_5 != 0)) {
    if (*(char *)gfx == '\0') {
      pcVar6 = (char *)"glassworks" + 9;
      gfx = (far_t)ovr_stshLoadGfx(gfx);
    }
    if (*(char *)gfx != '\x02') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
    iStack_10 = *param_4;
    uVar5 = (undefined2)((ulong)param_4 >> 0x10);
    piVar3 = (int *)param_4;
    uStack_12 = piVar3[1];
    iStack_14 = piVar3[2];
    uStack_16 = piVar3[3];
    if (param_6 == '\0') {
      uVar1 = (int)((uint)param_5 * *(int *)(((stg_tmp_t *)gfx.ofs)->cmap + 1)) >> 4;
    }
    else {
      uVar1 = (uint)param_5 *
              ((*(int *)(((stg_tmp_t *)gfx.ofs)->cmap + 10) + -1) -
              *(int *)(((stg_tmp_t *)gfx.ofs)->cmap + 1)) >> 4;
    }
    param_2 = param_2 - uVar1;
    uVar1 = param_3 - ((int)((uint)param_5 * *(int *)(((stg_tmp_t *)gfx.ofs)->cmap + 3)) >> 4);
    if (param_2 < iStack_10) {
      uStack_a = iStack_10 - param_2;
      pcStack_e = (char *)iStack_10;
      if (*(uint *)(((stg_tmp_t *)gfx.ofs)->cmap + 10) <= uStack_a) {
        return;
      }
    }
    else {
      pcStack_e = (char *)param_2;
      uStack_a = 0;
    }
    iStack_c = (iStack_14 - (int)pcStack_e) + 1;
    if (0 < iStack_c) {
      pcStack_1a = (char *)((int)pcStack_e + uVar1 * 0x140);
      iStack_18 = piVar3[4];
      uVar4 = 1;
      if (param_6 == '\0') {
        pfStack_6 = (far_t *)(GUnitDescriptions + 0x12);
      }
      else {
        pfStack_6 = (far_t *)&GUnitDescriptions[0xf].seg;
      }
      pfStack_4 = (far_t *)((char *)"arrowsmith" + 3);
      puStack_1e = ((stg_tmp_t *)gfx.ofs)->cmap + 0xe;
      uStack_1c = gfx.seg;
      pcStack_e = pcStack_1a;
      if (param_7 == -1) {
        uStack_8 = 0;
        while ((uStack_8 < *(uint *)(((stg_tmp_t *)gfx.ofs)->cmap + 0xc) && (uVar1 <= uStack_16))) {
          iVar2 = (*(code *)pfStack_6)(pcVar6,puStack_1e,uStack_1c,local_15e);
          puStack_1e = puStack_1e + iVar2;
          if ((*(uint *)((uint)param_5 * 2 + 0x470) & uVar4) != 0) {
            if (uStack_12 <= uVar1) {
              copyGrayscalePalette
                        ((uint8_t *)CONCAT22(unaff_SS,local_15e + uStack_a),
                         *(int *)(((stg_tmp_t *)gfx.ofs)->cmap + 10) - uStack_a);
              pcVar6 = (char *)"arrowsmith" + 3;
              ovr_masked_memcpy((char *)CONCAT22(iStack_18,pcStack_1a),
                                (char *)CONCAT22(unaff_SS,local_15e),uStack_a,
                                *(int *)(((stg_tmp_t *)gfx.ofs)->cmap + 10),iStack_c,
                                *(uint *)((uint)param_5 * 2 + 0x470));
            }
            pcStack_1a = pcStack_1a + 0x140;
            uVar1 = uVar1 + 1;
          }
          if (uVar4 == 0x8000) {
            uVar4 = 1;
          }
          else {
            uVar4 = uVar4 << 1;
          }
          uStack_8 = uStack_8 + 1;
        }
      }
      else {
        uStack_8 = 0;
        while ((uStack_8 < *(uint *)(((stg_tmp_t *)gfx.ofs)->cmap + 0xc) && (uVar1 <= uStack_16))) {
          iVar2 = (*(code *)pfStack_6)(pcVar6,puStack_1e,uStack_1c,local_15e);
          puStack_1e = puStack_1e + iVar2;
          if ((*(uint *)((uint)param_5 * 2 + 0x470) & uVar4) != 0) {
            if (uStack_12 <= uVar1) {
              ovr_driver_2d63_044e(local_15e + uStack_a);
              pcVar6 = (char *)"arrowsmith" + 3;
              ovr_masked_memcpy((char *)CONCAT22(iStack_18,pcStack_1a),
                                (char *)CONCAT22(unaff_SS,local_15e),uStack_a,
                                *(int *)(((stg_tmp_t *)gfx.ofs)->cmap + 10),iStack_c,
                                *(uint *)((uint)param_5 * 2 + 0x470));
            }
            pcStack_1a = pcStack_1a + 0x140;
            uVar1 = uVar1 + 1;
          }
          if (uVar4 == 0x8000) {
            uVar4 = 1;
          }
          else {
            uVar4 = uVar4 << 1;
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

void __cdecl16far blitGfxRect(far_t gfx,int16_t x,int16_t y,brect_t *dst,uint8_t type,bool mirror)

{
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  undefined2 unaff_DI;
  
  if (gfx.ofs != 0 || gfx.seg != 0) {
    if (*(char *)gfx == '\0') {
      gfx = (far_t)ovr_stshLoadGfx(gfx);
    }
    if (*(char *)gfx == '\x01') {
      if (type == 0x10) {
        blitGfx10(gfx,x,y,dst,mirror);
      }
      else {
        blitGfxN(gfx,x,y,dst,type,mirror);
      }
    }
    else if (*(char *)gfx == '\x02') {
      if (mirror) {
        if (type == 0x10) {
          gfx_03.seg = gfx.seg;
          gfx_03.ofs = gfx.ofs + 5;
          blitGfx10(gfx_03,(x + *(int *)(gfx.ofs + 1)) - (*(int *)(gfx.ofs + 10) + -1),
                    y - *(int *)(gfx.ofs + 3),dst,mirror);
        }
        else {
          gfx_01.seg = gfx.seg;
          gfx_01.ofs = gfx.ofs + 5;
          blitGfxN(gfx_01,x - ((uint)type * ((*(int *)(gfx.ofs + 10) + -1) - *(int *)(gfx.ofs + 1))
                              >> 4),y - ((int)((uint)type * *(int *)(gfx.ofs + 3)) >> 4),dst,type,
                   mirror);
        }
      }
      else if (type == 0x10) {
        gfx_02.seg = gfx.seg;
        gfx_02.ofs = gfx.ofs + 5;
        blitGfx10(gfx_02,x - *(int *)(gfx.ofs + 1),y - *(int *)(gfx.ofs + 3),dst,mirror);
      }
      else {
        gfx_00.seg = gfx.seg;
        gfx_00.ofs = gfx.ofs + 5;
        blitGfxN(gfx_00,x - ((int)((uint)type * *(int *)(gfx.ofs + 1)) >> 4),
                 y - ((int)((uint)type * *(int *)(gfx.ofs + 3)) >> 4),dst,type,mirror);
      }
    }
    else {
      printf("error(27) \r",unaff_DI);
      ovr_biosReadKey();
    }
  }
  return;
}



/* 317e:0db7 */

void __cdecl16far
blit_317e_0db7(uint16_t param_1,uint16_t param_2,int16_t param_3,int param_4,byte param_5,
              int param_6,byte param_7,brect_t *param_8,undefined2 param_9)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  far_t gfx;
  undefined2 uStack_c;
  undefined2 uStack_a;
  undefined2 uStack_4;
  
  bVar1 = param_5;
  iVar3 = param_4;
  if (param_6 < param_4) {
    param_4 = param_6;
    param_6 = iVar3;
    param_5 = param_7;
    param_7 = bVar1;
  }
  uVar2 = param_6 - param_4 >> 1;
  if (uVar2 == 0) {
    uStack_a = 0;
    uStack_c = 0;
  }
  else {
    uStack_a = (int)((uint)param_7 - (uint)param_5) / (int)uVar2;
    uVar6 = (int)((uint)param_7 - (uint)param_5) % (int)uVar2;
    uVar5 = (int)uVar6 >> 0xf;
    uStack_c = (uVar6 ^ uVar5) - uVar5;
  }
  iVar3 = ovr_OVC07_32c9_0026((uint)param_7 - (uint)param_5);
  uVar6 = param_6 - param_4 >> 0xf;
  iVar4 = (int)((uVar2 ^ uVar6) - uVar6) >> 1;
  uStack_4 = (uint)param_5;
  for (; param_4 <= param_6; param_4 = param_4 + 2) {
    gfx.seg = param_2;
    gfx.ofs = param_1;
    blitGfxN(gfx,param_3,param_4,(brect_t *)CONCAT22(param_9,param_8),(uint8_t)uStack_4,false);
    uStack_4 = uStack_4 + uStack_a;
    iVar4 = iVar4 + uStack_c;
    if ((int)((uVar2 ^ uVar6) - uVar6) <= iVar4) {
      iVar4 = iVar4 - ((uVar2 ^ uVar6) - uVar6);
      uStack_4 = uStack_4 + iVar3;
    }
  }
  return;
}



/* 317e:0ebe */

void __cdecl16far
blit_317e_0ebe(undefined2 param_1,int param_2,int param_3,undefined4 param_4,uint param_5,
              uint param_6,uint param_7,uint param_8,int param_9,int param_10,int param_11,
              int param_12,int param_13,int param_14)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uStack_c;
  uint uStack_a;
  uint uStack_8;
  int iStack_6;
  
  iVar1 = param_9 >> 1;
  uVar2 = 1;
  iStack_6 = param_3;
  uStack_a = 0;
  uStack_c = 0;
  uStack_8 = 0;
  do {
    if (param_6 <= uStack_8) {
      return;
    }
    if ((param_8 & uVar2) != 0) {
      if (param_5 <= uStack_a) {
        uVar3 = (undefined2)((ulong)param_4 >> 0x10);
        if (((*(char *)((int)param_4 + uStack_8) != '\0') && (param_13 <= param_2)) &&
           (param_2 <= param_14)) {
          *(undefined1 *)(iStack_6 + param_2 * 0x140) = *(undefined1 *)((int)param_4 + uStack_8);
        }
        iStack_6 = iStack_6 + 1;
        uStack_c = uStack_c + 1;
        if (param_7 <= uStack_c) {
          return;
        }
      }
      uStack_a = uStack_a + 1;
      iVar1 = iVar1 + param_11;
      param_2 = param_2 + param_10;
      if (param_9 <= iVar1) {
        param_2 = param_2 + param_12;
        iVar1 = iVar1 - param_9;
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

void __cdecl16far
blit_317e_0f7d(far_t param_1,int param_2,int param_3,byte param_4,int param_5,int param_6,
              byte param_7,int *param_8,char param_9)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  stg_tmp_t *psVar6;
  uint uVar7;
  undefined2 uVar8;
  uint16_t uVar9;
  undefined1 local_168 [320];
  uint8_t *puStack_28;
  uint16_t uStack_26;
  int iStack_24;
  int iStack_22;
  undefined2 uStack_20;
  int iStack_1e;
  int iStack_1c;
  int iStack_1a;
  int iStack_18;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  int iStack_10;
  uint uStack_e;
  int iStack_c;
  uint uStack_a;
  byte bStack_7;
  far_t *pfStack_6;
  far_t *pfStack_4;
  
  bVar2 = param_4;
  iVar1 = param_3;
  iVar3 = param_2;
  if (param_5 < param_2) {
    param_2 = param_5;
    param_5 = iVar3;
    param_3 = param_6;
    param_6 = iVar1;
    uStack_a = (uint)param_4;
    param_4 = param_7;
    param_7 = bVar2;
  }
  if ((param_1.ofs != 0 || param_1.seg != 0) && (param_4 != 0)) {
    if (*(char *)param_1 == '\0') {
      param_1 = (far_t)ovr_stshLoadGfx(param_1);
    }
    if (*(char *)param_1 != '\x01') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
    iStack_14 = *param_8;
    uVar8 = (undefined2)((ulong)param_8 >> 0x10);
    piVar5 = (int *)param_8;
    iStack_16 = piVar5[1];
    iStack_18 = piVar5[2];
    iStack_1a = piVar5[3];
    if (param_2 < iStack_14) {
      iStack_c = iStack_14 - param_2;
      iStack_12 = iStack_14;
    }
    else {
      iStack_12 = param_2;
      iStack_c = 0;
    }
    if (iStack_18 < param_5) {
      iStack_10 = iStack_18 - iStack_12;
    }
    else {
      iStack_10 = param_5 - iStack_12;
    }
    iStack_10 = iStack_10 + 1;
    if (0 < iStack_10) {
      bStack_7 = param_7;
      if (param_7 < param_4) {
        bStack_7 = param_4;
      }
      uVar9 = param_1.seg;
      psVar6 = (stg_tmp_t *)param_1.ofs;
      param_3 = param_3 - (*(int *)(psVar6->cmap + 7) * (uint)bStack_7 >> 4);
      uVar7 = 1;
      if (param_9 == '\0') {
        pfStack_6 = (far_t *)(GUnitDescriptions + 0x12);
      }
      else {
        pfStack_6 = (far_t *)&GUnitDescriptions[0xf].seg;
      }
      pfStack_4 = (far_t *)((char *)"arrowsmith" + 3);
      puStack_28 = psVar6->cmap + 9;
      iStack_22 = param_5 - param_2;
      iStack_24 = (param_6 - (*(int *)(psVar6->cmap + 7) * (uint)bStack_7 >> 4)) - param_3;
      if (iStack_22 == 0) {
        iStack_1c = 0;
        iStack_1e = 0;
      }
      else {
        iStack_1c = iStack_24 / iStack_22;
        uVar4 = iStack_24 % iStack_22 >> 0xf;
        iStack_1e = (iStack_24 % iStack_22 ^ uVar4) - uVar4;
      }
      uStack_26 = uVar9;
      uStack_20 = ovr_OVC07_32c9_0026();
      uStack_e = 0;
      while ((uStack_e < *(uint *)(psVar6->cmap + 7) && (param_3 <= iStack_1a))) {
        iVar3 = (*(code *)pfStack_6)((char *)"public baths" + 6,puStack_28,uStack_26,local_168);
        puStack_28 = puStack_28 + iVar3;
        if ((*(uint *)((uint)bStack_7 * 2 + 0x470) & uVar7) != 0) {
          blit_317e_0ebe(piVar5[4],param_3,iStack_12,local_168);
          param_3 = param_3 + 1;
        }
        if (uVar7 == 0x8000) {
          uVar7 = 1;
        }
        else {
          uVar7 = uVar7 << 1;
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
    uVar2 = ovr_randBelow(0x100);
    *puVar3 = (char)uVar2;
  }
  return;
}



/* 317e:1240 */

void __cdecl16far
blit_317e_1240(uint16_t param_1,uint16_t param_2,uint16_t param_3,uint16_t param_4,int param_5,
              int param_6,byte param_7,int param_8,int param_9,byte param_10,brect_t *param_11,
              undefined2 param_12,byte param_13)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  far_t gfx;
  far_t gfx_00;
  int iStack_1a;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  int iStack_e;
  int iStack_c;
  uint uStack_8;
  int iStack_6;
  byte *pbStack_4;
  
  iVar4 = param_8;
  bVar2 = param_7;
  iVar3 = param_6 + ((int)((uint)param_7 * 0x38) >> 4);
  param_9 = param_9 + ((int)((uint)param_10 * 0x38) >> 4);
  ovr_OVC07_32c9_0466();
  param_6 = iVar3;
  if (param_9 < iVar3) {
    param_8 = param_5;
    param_7 = param_10;
    param_10 = bVar2;
    param_5 = iVar4;
    param_6 = param_9;
    param_9 = iVar3;
  }
  iVar3 = (param_9 - param_6) / 4;
  if (iVar3 == 0) {
    iStack_c = 0;
    iStack_e = 0;
  }
  else {
    iStack_c = (int)((uint)param_10 - (uint)param_7) / iVar3;
    uVar6 = (int)((uint)param_10 - (uint)param_7) % iVar3;
    uVar7 = (int)uVar6 >> 0xf;
    iStack_e = (uVar6 ^ uVar7) - uVar7;
  }
  iVar4 = ovr_OVC07_32c9_0026((uint)param_10 - (uint)param_7);
  iStack_1a = iVar3 >> 1;
  if (iVar3 == 0) {
    iStack_14 = 0;
    iStack_16 = 0;
  }
  else {
    iStack_14 = (param_8 - param_5) / iVar3;
    uVar6 = (param_8 - param_5) % iVar3;
    uVar7 = (int)uVar6 >> 0xf;
    iStack_16 = (uVar6 ^ uVar7) - uVar7;
  }
  iVar5 = ovr_OVC07_32c9_0026(param_8 - param_5);
  uStack_8 = (uint)param_7;
  pbStack_4 = (byte *)(param_5 << 2);
  iStack_12 = iStack_1a;
  for (iStack_6 = param_6; iStack_6 <= param_9; iStack_6 = iStack_6 + 4) {
    pbVar1 = (byte *)((uint)pbStack_4 & 0xff);
    pbStack_4 = pbVar1 + 1;
    if ((*pbVar1 & 7) < param_13) {
      gfx.seg = param_2;
      gfx.ofs = param_1;
      blitGfxN(gfx,param_5 + -7,iStack_6 + -2,(brect_t *)CONCAT22(param_12,param_11),
               (uint8_t)uStack_8,false);
    }
    else {
      gfx_00.seg = param_4;
      gfx_00.ofs = param_3;
      blitGfxN(gfx_00,param_5 + -7,iStack_6 + -2,(brect_t *)CONCAT22(param_12,param_11),
               (uint8_t)uStack_8,false);
    }
    uStack_8 = uStack_8 + iStack_c;
    iStack_12 = iStack_12 + iStack_e;
    if (iVar3 <= iStack_12) {
      iStack_12 = iStack_12 - iVar3;
      uStack_8 = uStack_8 + iVar4;
    }
    param_5 = param_5 + iStack_14;
    iStack_1a = iStack_1a + iStack_16;
    if (iVar3 <= iStack_1a) {
      iStack_1a = iStack_1a - iVar3;
      param_5 = param_5 + iVar5;
    }
  }
  return;
}


