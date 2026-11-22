/*
 * ovc06_blit.c - recovered from STRONG.EXE
 * memory block: OVC06_blit.c
 * range: 317e:0000 - 317e:14af
 * functions: 17
 */
#include "recovered.h"


/* 317e:0000 */
far_t * __cdecl16far
stshRleSub(far_t *__return_storage_ptr__,uint8_t *src,uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,int16_t hdrsz)

{
  uint16_t sz;
  uint16_t width;
  uint16_t rlesz;
  uint16_t written;
  uint16_t start;
  uint16_t uVar1;
  uint16_t rows_left;
  uint32_t block;
  uint32_t r;
  uint16_t dst;
  uint16_t prow;
  undefined1 *uStack_6;   /* hand fix: assigned a byte pointer and dereferenced as *uStack_6 */
  uint16_t src_seg;
  uint16_t dseg;
  
  sz = ((ex - sx) + ((ex - sx) + 1 >> 7) + 2) * ((ey - sy) + 1);
  (*(uint16_t *)((uint8_t *)&(block) + 2)) = (sz + hdrsz) - 1;
  (*(uint16_t *)((uint8_t *)&(block))) = (uint16_t)(uint32_t)ovr_stshAlloc(CONCAT22((CARRY2(sz,hdrsz) - 1) + (uint)(sz + hdrsz != 0),(*(uint16_t *)((uint8_t *)&(block) + 2)))
                             );
  uStack_6 = (undefined1 *)CONCAT22((*(uint16_t *)((uint8_t *)&(block) + 2)),(undefined1 *)((int)(void *)block + hdrsz + -10));
  prow = (int)&__return_storage_ptr__[sy * 0x50].ofs + sx;
  uVar1 = (int)(void *)block + hdrsz + -1;
  width = (ex - sx) + 1;
  rows_left = (ey - sy) + 1;
  dst = uVar1;
  while (rows_left != 0) {
    rlesz = ovr_rle_line((uint8_t *)prow,(uint8_t *)CONCAT22(dst,src),(*(uint16_t *)((uint8_t *)&(block) + 2)));
    dst = dst + rlesz;
    prow = prow + 0x140;
    rows_left = rows_left - 1;
  }
  written = dst - uVar1;
  if (written <= sz) {
    *(uint16_t *)((int)(void *)block + hdrsz + -7) = 0;
    *(uint16_t *)((int)(void *)block + hdrsz + -9) = written;
    *(uint16_t *)((int)(void *)block + hdrsz + -5) = width;
    *(int *)((int)(void *)block + hdrsz + -3) = (ey - sy) + 1;
    *uStack_6 = 1;
    (*(uint16_t *)((uint8_t *)&(r))) = (uint16_t)(far_t far *)ovr_stshRealloc((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(block) + 2)),(void *)block),
                                       (ulong)((written + hdrsz) - 1));
    return (far_t far *)r;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(5);
}


/* 317e:0148 */

/* Cuts X,Y,W,H rect out of 8bit pixels pointed by src.
   returns ptrr to stg_t struct */

far_t * __cdecl16far
stshRleCut(far_t *__return_storage_ptr__,far_t src,int16_t sx,int16_t sy,int16_t ex,int16_t ey,uint16_t arg7,uint16_t arg8,uint16_t arg9)

{
  far_t *pfVar1;
  
  pfVar1 = stshRleSub(__return_storage_ptr__,(uint8_t *)src.ofs,src.seg,sx,sy,ex,10);
  return pfVar1;
}



/* 317e:0168 */
far_t * __cdecl16far
stshRleType2(far_t *__return_storage_ptr__,far_t pixels,int16_t sx,int16_t sy,int16_t ex,int16_t ey,int16_t ox,int16_t oy,uint16_t arg9,uint16_t arg10)

{
  far_t far *pfVar1;
  uint16_t in_DX;
  far_t far *uStack_6;   /* hand fix: assigned a far_t pointer and used as uStack_6->ofs */
  
  pfVar1 = stshRleSub(__return_storage_ptr__,(uint8_t *)pixels.ofs,pixels.seg,sx,sy,ex,15);
  uStack_6 = (far_t far *)CONCAT22(in_DX,pfVar1);
  *(int16_t *)((int)&pfVar1->ofs + 1) = ey;
  *(int16_t *)((int)&pfVar1->seg + 1) = ox;
  *(undefined1 *)&uStack_6->ofs = 2;
  return pfVar1;
}


/* 317e:01b2 */

void __cdecl16far blitLoadRleGfx(far_t gfx,far_t dst,uint16_t arg3)

{
  uint16_t consumed;
  uint16_t in_DX;
  uint16_t height;
  uint16_t src_ofs;
  
  if (gfx.ofs != 0 || gfx.seg != 0) {
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) == '\0') {
      gfx.ofs = (uint16_t)ovr_stshLoadGfx(gfx);
      gfx.seg = in_DX;
    }
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) != '\x01') {
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
    src_ofs = gfx.ofs + 9;
    height = *(uint16_t *)(gfx.ofs + 7);
    while (height != 0) {
      consumed = ovr_rle_blit_decode((byte *)src_ofs,(byte *)CONCAT22(dst.ofs,gfx.seg),dst.seg);
      src_ofs = src_ofs + consumed;
      dst.ofs = dst.ofs + 0x140;
      height = height - 1;
    }
  }
  return;
}



/* 317e:0239 */

void __cdecl16far drawGfx(far_t gfx,far_t dst,bool type)

{
  int16_t iVar1;
  int iVar2;
  char *pcStack_6;
  
  if (type) {
    if (gfx.ofs != 0 || gfx.seg != 0) {
      pcStack_6 = (char *)(gfx.ofs + 9);
      for (iVar2 = *(int *)(gfx.ofs + 7); iVar2 != 0; iVar2 = iVar2 + -1) {
        iVar1 = ovr_drawLine2(pcStack_6,(char *)CONCAT22(dst.ofs,gfx.seg),dst.seg);
        pcStack_6 = pcStack_6 + iVar1;
        dst.ofs = dst.ofs + 0x140;
      }
    }
  }
  else {
    blitLoadRleGfx(gfx,dst,0);
  }
  return;
}



/* 317e:02a9 */
void __cdecl16far blitGfx10(far_t gfx,uint16_t x,uint16_t y,brect_t *dst,bool type,uint16_t arg6,uint16_t arg7)

{
  far_t dst_00;
  far_t src;
  int iVar1;
  uint16_t in_DX;
  uint16_t pdst;
  int iVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  uint16_t unaff_SS;
  undefined1 uStack000f;
  bool in_stack_00000010;
  far_t dst_01;
  uint8_t rowBuf;
  uint16_t dst_h;
  uint16_t dst_w;
  uint16_t dst_y;
  uint16_t dst_x;
  int iStack_1c;
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
  
  dst = (uint16_t *)CONCAT13(uStack000f,CONCAT12(type,dst));
  uVar4 = 0x317e;
  if (gfx.ofs != 0 || gfx.seg != 0) {
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) == '\0') {
      uVar4 = 0x2337;
      gfx.ofs = (uint16_t)ovr_stshLoadGfx(gfx);
      gfx.seg = in_DX;
    }
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) != '\x01') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
    dst_x = dst->x;   /* hand fix: read the first field; *dst is the whole structure */
    uVar3 = (uint16_t)((ulong)dst >> 0x10);
    dst_y = dst->y;
    dst_w = dst->w;
    dst_h = dst->h;
    if (((((int)x < (int)dst_x) || ((int)y < (int)dst_y)) ||
        ((int)dst_w < (int)(x + *(int *)(gfx.ofs + 5) + -1))) ||
       ((int)dst_h < (int)(y + *(int *)(gfx.ofs + 7) + -1))) {
      if (in_stack_00000010 == false) {
        pfn = 0x133;
      }
      else {
        pfn = 0x129;
      }
      uStack_4 = 0x22a6;
      if (((int)dst_x <= (int)(x + *(int *)(gfx.ofs + 5) + -1)) && ((int)x <= (int)dst_w)) {
        if ((int)x < (int)dst_x) {
          iStack_10 = dst_x - x;
          uStack_8 = dst_x;
        }
        else {
          uStack_8 = x;
          iStack_10 = 0;
        }
        uStack_c = dst_w;
        if ((int)(x + *(int *)(gfx.ofs + 5) + -1) <= (int)dst_w) {
          uStack_c = (x + *(int *)(gfx.ofs + 5)) - 1;
        }
        uStack_12 = (uStack_c - uStack_8) + 1;
        uStack_a = dst_y;
        if ((int)dst_y <= (int)y) {
          uStack_a = y;
        }
        uStack_e = dst_h;
        if ((int)(y + *(int *)(gfx.ofs + 7) + -1) <= (int)dst_h) {
          uStack_e = (y + *(int *)(gfx.ofs + 7)) - 1;
        }
        iStack_14 = (uStack_e - y) + 1;
        uStack_18 = uStack_8 + uStack_a * 0x140;
        uStack_16 = dst->seg;
        iStack_1c = gfx.ofs + 9;
        uStack_1a = gfx.seg;
        for (iVar2 = 0; (iVar2 < iStack_14 && ((int)(iVar2 + y) <= (int)dst_h)); iVar2 = iVar2 + 1)
        {
          iVar1 = (*(code *)pfn)(uVar4,iStack_1c,uStack_1a,&rowBuf);
          iStack_1c = iStack_1c + iVar1;
          if ((int)dst_y <= (int)(iVar2 + y)) {
            dst_01.seg = uStack_16;
            dst_01.ofs = uStack_18;
            uVar4 = 0x138e;
            src.seg = unaff_SS;
            src.ofs = (uint16_t)(&rowBuf + iStack_10);
            blitTillAlpha(dst_01,src,uStack_12);
            uStack_18 = uStack_18 + 0x140;
          }
        }
      }
    }
    else {
      dst_00.seg = dst->seg;
      dst_00.ofs = x + y * 0x140;
      drawGfx(gfx,dst_00,in_stack_00000010);
    }
  }
  return;
}


/* 317e:04c2 */

/* [R4] calls drawGfx */

void __cdecl16far blit_usesDrawGfx(far_t gfx,int x,int y,brect_t *rect)

{
  far_t dst;
  far_t dst_00;
  int rowLen;
  uint16_t in_DX;
  brect_t *rectP;
  int row;
  uint16_t uVar4;
  uint16_t unaff_SS;
  far_t src;
  uint8_t rowBuf;
  int rectH;
  int rectW;
  int rectY;
  int rectX;
  uint16_t srcOfs;
  uint16_t srcSeg;
  char *dstOfs;
  uint16_t dstSeg;
  int copyH;
  word copyW;
  int xSkip;
  int clipY1;
  int clipX1;
  int clipY0;
  int clipX0;
  
  if (gfx.ofs != 0 || gfx.seg != 0) {
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) == '\0') {
      gfx.ofs = (uint16_t)ovr_stshLoadGfx(gfx);
      gfx.seg = in_DX;
    }
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) != '\x01') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
    rectX = rect->x;
    uVar4 = (uint16_t)((ulong)rect >> 0x10);
    rectP = (brect_t *)rect;
    rectY = rectP->y;
    rectW = rectP->w;
    rectH = rectP->h;
    if ((((x < rectX) || (y < rectY)) || (rectW < x + *(int *)(gfx.ofs + 5) + -1)) ||
       (rectH < y + *(int *)(gfx.ofs + 7) + -1)) {
      if ((rectX <= x + *(int *)(gfx.ofs + 5) + -1) && (x <= rectW)) {
        if (x < rectX) {
          xSkip = rectX - x;
          clipX0 = rectX;
        }
        else {
          clipX0 = x;
          xSkip = 0;
        }
        clipX1 = rectW;
        if (x + *(int *)(gfx.ofs + 5) + -1 <= rectW) {
          clipX1 = x + *(int *)(gfx.ofs + 5) + -1;
        }
        copyW = (clipX1 - clipX0) + 1;
        clipY0 = rectY;
        if (rectY <= y) {
          clipY0 = y;
        }
        clipY1 = rectH;
        if (y + *(int *)(gfx.ofs + 7) + -1 <= rectH) {
          clipY1 = y + *(int *)(gfx.ofs + 7) + -1;
        }
        copyH = (clipY1 - y) + 1;
        dstOfs = (char *)(clipX0 + clipY0 * 0x140);
        dstSeg = rectP->seg;
        srcOfs = gfx.ofs + 9;
        srcSeg = gfx.seg;
        for (row = 0; (row < copyH && (row + y <= rectH)); row = row + 1) {
          src.seg = srcSeg;
          src.ofs = srcOfs;
          dst_00.seg = unaff_SS;
          dst_00.ofs = (uint16_t)&rowBuf;
          rowLen = ovr_unrle(src,dst_00,*(uint16_t *)(gfx.ofs + 5),(char)*(uint16_t *)(gfx.ofs + 5),0);
          srcOfs = srcOfs + rowLen;
          if (rectY <= row + y) {
            memcpy((char *)CONCAT22(dstSeg,dstOfs),
                   (char *)CONCAT22(unaff_SS,&rowBuf + xSkip),copyW);
            dstOfs = dstOfs + 0x140;
          }
        }
      }
    }
    else {
      dst.seg = rectP->seg;
      dst.ofs = x + y * 0x140;
      drawGfx(gfx,dst,false);
    }
  }
  return;
}



/* 317e:06bc */

void __cdecl16far blitGfxN(far_t gfx,int16_t x,int16_t y,brect_t *dst,uint8_t type,bool mirror)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  uint mask;
  uint16_t in_DX;
  uint uVar4;
  int unaff_SS;
  char buf [320];
  uint16_t pdst;
  uint16_t h;
  uint16_t sx;
  uint16_t pd;
  uint16_t srcsz;
  uint16_t skip;
  uint uStack_8;
  code *pcStack_6;
  code *pcStack_4;
  
  if ((gfx.ofs != 0 || gfx.seg != 0) && (type != 0x0)) {
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) == '\0') {
      gfx.ofs = (uint16_t)ovr_stshLoadGfx(gfx);
      gfx.seg = in_DX;
    }
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) != '\x01') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
    if (type < 0x10) {
      pd = dst->x;
      uVar1 = ((brect_t *)dst)->y;
      uVar2 = ((brect_t *)dst)->h;
      if (x < (int)pd) {
        skip = pd - x;
      }
      else {
        pd = x;
        skip = 0;
      }
      mask = (((brect_t *)dst)->w - pd) + 1;
      if (0 < (int)mask) {
        pdst = pd + y * 0x140;
        pcVar3 = (char *)((brect_t *)dst)->seg;
        uVar4 = 1;
        if (mirror) {
          pcStack_6 = (code *)ovr_unrle_mirror;
        }
        else {
          pcStack_6 = (code *)ovr_unrle;
        }
        pcStack_4 = (code *)0x22a6;
        uStack_8 = 0;
        while ((uStack_8 < *(uint *)(gfx.ofs + 7) && ((uint)y <= uVar2))) {
          (*pcStack_6)();
          if ((*(uint *)((uint)type * 2 + 0x470) & uVar4) != 0) {
            if (uVar1 <= (uint)y) {
              ovr_masked_memcpy((char *)pdst,(char *)CONCAT22(buf,pcVar3),unaff_SS,skip,*(int *)(gfx.ofs + 5),mask,0);
            }
            pdst = pdst + 0x140;
            y = y + 1;
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
    else {
      blitGfx10(gfx,x,y,(brect_t *)dst,SUB41((ulong)dst >> 0x10,0),0,0);
    }
  }
  return;
}



/* 317e:0879 */

/* [R4] calls ovr_randBelow */

void __cdecl16far blit_usesRandBelow(byte *buf,uint16_t count,byte value,byte chance)

{
  uint16_t uVar1;
  
  while (count != 0) {
    if (*buf != 0) {
      uVar1 = ovr_randBelow(0x100,0);
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
    *dst = *(uint8_t far *)((uint8_t far *)MK_FP(GrayscalePalette.seg, GrayscalePalette.ofs) +  (uint)*dst);
    dst = (uint8_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(dst) + 2)),(uint8_t *)dst + 1);
    count = count + -1;
  }
  return;
}



/* 317e:08ed */

void __cdecl16far gfxRlePrepare(far_t gfx,int x,int y,int *rectOfs,char scale,char flip,uint16_t arg7,uint16_t arg8,uint16_t arg9,uint16_t arg10,uint16_t arg11,uint16_t arg12,uint16_t arg13)

{
  far_t buf;
  uint uVar1;
  int iVar2;
  uint16_t in_DX;
  uint uVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  uint16_t unaff_SS;
  undefined1 uStack000f;
  char in_stack_00000012;
  uint8_t in_stack_00000014;
  uint8_t in_stack_00000016;
  byte in_stack_00000018;
  uint8_t skip;
  int iStack_1e;
  uint16_t uStack_1c;
  char *pcStack_1a;
  char *pcStack_18;
  uint uStack_16;
  int iStack_14;
  uint uStack_12;
  int iStack_10;
  char *pcStack_e;
  uint uStack_c;
  uint uStack_a;
  uint uStack_8;
  far_t *pfStack_6;
  far_t *pfStack_4;
  
  rectOfs = (int *)CONCAT13(uStack000f,CONCAT12(scale,rectOfs));
  uVar5 = 0x317e;
  if ((gfx.ofs != 0 || gfx.seg != 0) && (flip != '\0')) {
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) == '\0') {
      uVar5 = 0x2337;
      gfx.ofs = (uint16_t)ovr_stshLoadGfx(gfx);
      gfx.seg = in_DX;
    }
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) != '\x02') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
    iStack_10 = *rectOfs;
    uVar4 = (uint16_t)((ulong)rectOfs >> 0x10);
    uStack_12 = rectOfs[1];
    iStack_14 = rectOfs[2];
    uStack_16 = rectOfs[3];
    if (in_stack_00000012 == '\0') {
      uVar1 = (int)((uint)(byte)flip * *(int *)(gfx.ofs + 1)) >> 4;
    }
    else {
      uVar1 = (uint)(byte)flip * ((*(int *)(gfx.ofs + 10) + -1) - *(int *)(gfx.ofs + 1)) >> 4;
    }
    x = x - uVar1;
    uVar1 = y - ((int)((uint)(byte)flip * *(int *)(gfx.ofs + 3)) >> 4);
    if (x < iStack_10) {
      uStack_a = iStack_10 - x;
      pcStack_e = (char *)iStack_10;
      if (*(uint *)(gfx.ofs + 10) <= uStack_a) {
        return;
      }
    }
    else {
      pcStack_e = (char *)x;
      uStack_a = 0;
    }
    uStack_c = (iStack_14 - (int)pcStack_e) + 1;
    if (0 < (int)uStack_c) {
      pcStack_1a = (char *)((int)pcStack_e + uVar1 * 0x140);
      pcStack_18 = (char *)rectOfs[4];
      uVar3 = 1;
      if (in_stack_00000012 == '\0') {
        pfStack_6 = (far_t *)(GUnitDescriptions + 0x12);
      }
      else {
        pfStack_6 = (far_t *)&GUnitDescriptions[0xf].seg;
      }
      pfStack_4 = (far_t *)0x22a6;
      iStack_1e = gfx.ofs + 0xe;
      uStack_1c = gfx.seg;
      pcStack_e = pcStack_1a;
      if (in_stack_00000014 == 0xff) {
        uStack_8 = 0;
        while ((uStack_8 < *(uint *)(gfx.ofs + 0xc) && (uVar1 <= uStack_16))) {
          iVar2 = (*(code *)pfStack_6)(uVar5,iStack_1e,uStack_1c,&skip);
          iStack_1e = iStack_1e + iVar2;
          if ((*(uint *)((uint)(byte)flip * 2 + 0x470) & uVar3) != 0) {
            if (uStack_12 <= uVar1) {
              copyGrayscalePalette
                        ((uint8_t *)CONCAT22(unaff_SS,&skip + uStack_a),
                         *(int *)(gfx.ofs + 10) - uStack_a);
              uVar5 = 0x22a6;
              ovr_masked_memcpy(pcStack_1a,(char *)CONCAT22(&skip,pcStack_18),unaff_SS,uStack_a,
                                *(int *)(gfx.ofs + 10),uStack_c,
                                *(uint16_t *)((uint)(byte)flip * 2 + 0x470));
            }
            pcStack_1a = pcStack_1a + 0x140;
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
        while ((uStack_8 < *(uint *)(gfx.ofs + 0xc) && (uVar1 <= uStack_16))) {
          iVar2 = (*(code *)pfStack_6)(uVar5,iStack_1e,uStack_1c,&skip);
          iStack_1e = iStack_1e + iVar2;
          if ((*(uint *)((uint)(byte)flip * 2 + 0x470) & uVar3) != 0) {
            if (uStack_12 <= uVar1) {
              buf.seg = unaff_SS;
              buf.ofs = (uint16_t)(&skip + uStack_a);
              ovr_driver_scan1(buf,*(int *)(gfx.ofs + 10) - uStack_a,in_stack_00000014,
                               in_stack_00000016,far_from_u32((uint32_t)(0x15290000)),(uint)in_stack_00000018);
              in_stack_00000018 = in_stack_00000018 + (*(char *)(gfx.ofs + 10) - (char)uStack_a);
              uVar5 = 0x22a6;
              ovr_masked_memcpy(pcStack_1a,(char *)CONCAT22(&skip,pcStack_18),unaff_SS,uStack_a,
                                *(int *)(gfx.ofs + 10),uStack_c,
                                *(uint16_t *)((uint)(byte)flip * 2 + 0x470));
            }
            pcStack_1a = pcStack_1a + 0x140;
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
blitGfxRect(far_t gfx,int16_t x,int16_t y,brect_t *dst,uint8_t type,bool mirror,uint16_t arg7,uint16_t arg8,uint16_t arg9,uint16_t arg10,uint16_t arg11,uint16_t arg12)

{
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  uint16_t in_DX;
  bool in_stack_00000012;
  
  if (gfx.ofs != 0 || gfx.seg != 0) {
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) == '\0') {
      gfx.ofs = (uint16_t)ovr_stshLoadGfx(gfx);
      gfx.seg = in_DX;
    }
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) == '\x01') {
      if (mirror == true) {
        blitGfx10(gfx,x,y,dst,(bool)type,0,0);
      }
      else {
        blitGfxN(gfx,x,y,(brect_t *)CONCAT22(type,dst),mirror,in_stack_00000012);
      }
    }
    else if (*(char *)MK_FP(gfx.seg, gfx.ofs) == '\x02') {
      if (in_stack_00000012 == false) {
        if (mirror == true) {
          gfx_02.seg = gfx.seg;
          gfx_02.ofs = gfx.ofs + 5;
          blitGfx10(gfx_02,x - *(int *)(gfx.ofs + 1),y - *(int *)(gfx.ofs + 3),dst,(bool)type,0,0);
        }
        else {
          gfx_00.seg = gfx.seg;
          gfx_00.ofs = gfx.ofs + 5;
          blitGfxN(gfx_00,x - ((int)((uint)mirror * *(int *)(gfx.ofs + 1)) >> 4),
                   y - ((int)((uint)mirror * *(int *)(gfx.ofs + 3)) >> 4),
                   (brect_t *)CONCAT22(type,dst),mirror,false);
        }
      }
      else if (mirror == true) {
        gfx_03.seg = gfx.seg;
        gfx_03.ofs = gfx.ofs + 5;
        blitGfx10(gfx_03,(x + *(int *)(gfx.ofs + 1)) - (*(int *)(gfx.ofs + 10) + -1),y - *(int *)(gfx.ofs + 3),dst,(bool)type,0,0);
      }
      else {
        gfx_01.seg = gfx.seg;
        gfx_01.ofs = gfx.ofs + 5;
        blitGfxN(gfx_01,x - ((uint)mirror * ((*(int *)(gfx.ofs + 10) + -1) - *(int *)(gfx.ofs + 1))
                            >> 4),y - ((int)((uint)mirror * *(int *)(gfx.ofs + 3)) >> 4),
                 (brect_t *)CONCAT22(type,dst),mirror,in_stack_00000012);
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
blit_usesBlitGfxN(far_t gfx,int16_t x,int y,byte shade1,int y2,byte shade2,brect_t *rect,uint16_t type,uint16_t arg9,uint16_t arg10,uint16_t arg11,uint16_t arg12,uint16_t arg13,uint16_t arg14,uint16_t arg15)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint16_t uStack_c;
  uint16_t uStack_a;
  uint16_t uStack_4;
  
  bVar1 = shade1;
  iVar3 = y;
  if (y2 < y) {
    y = y2;
    y2 = iVar3;
    shade1 = shade2;
    shade2 = bVar1;
  }
  uVar2 = y2 - y >> 1;
  if (uVar2 == 0) {
    uStack_a = 0;
    uStack_c = 0;
  }
  else {
    uStack_a = (int)((uint)shade2 - (uint)shade1) / (int)uVar2;
    uVar6 = (int)((uint)shade2 - (uint)shade1) % (int)uVar2;
    uVar5 = (int)uVar6 >> 0xf;
    uStack_c = (uVar6 ^ uVar5) - uVar5;
  }
  iVar3 = ovr_ovc07_signum((uint)shade2 - (uint)shade1);
  uVar6 = y2 - y >> 0xf;
  iVar4 = (int)((uVar2 ^ uVar6) - uVar6) >> 1;
  uStack_4 = (uint)shade1;
  for (; y <= y2; y = y + 2) {
    blitGfxN(gfx,x,y,(brect_t *)CONCAT22(type,rect),(uint8_t)uStack_4,false);
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
blit_usesStExit(far_t gfx,int x1,int y1,byte shade1,int x2,int y2,byte shade2,int *rectOfs,uint16_t arg9,uint16_t arg10,uint16_t arg11,uint16_t arg12,uint16_t arg13,uint16_t arg14,uint16_t arg15)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint16_t in_DX;
  uint uVar4;
  uint16_t uVar5;
  uint uVar6;
  uint16_t uVar7;
  uint16_t unaff_SS;
  uint16_t in_stack_00000016;
  char in_stack_00000018;
  far_t src;
  uint8_t rowBuf;
  int iStack_28;
  uint16_t uStack_26;
  int iStack_24;
  int iStack_22;
  int16_t iStack_20;
  int iStack_1e;
  int iStack_1c;
  int iStack_1a;
  int iStack_18;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  uint16_t uStack_10;
  uint uStack_e;
  uint16_t uStack_c;
  uint uStack_a;
  byte bStack_7;
  far_t *pfStack_6;
  far_t *pfStack_4;
  
  bVar1 = shade1;
  iVar3 = y1;
  iVar2 = x1;
  if (x2 < x1) {
    x1 = x2;
    x2 = iVar2;
    y1 = y2;
    y2 = iVar3;
    uStack_a = (uint)shade1;
    shade1 = shade2;
    shade2 = bVar1;
  }
  if ((gfx.ofs != 0 || gfx.seg != 0) && (shade1 != 0)) {
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) == '\0') {
      gfx.ofs = (uint16_t)ovr_stshLoadGfx(gfx);
      gfx.seg = in_DX;
    }
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) != '\x01') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
    iStack_14 = *rectOfs;
    iStack_16 = rectOfs[1];
    iStack_18 = rectOfs[2];
    iStack_1a = rectOfs[3];
    if (x1 < iStack_14) {
      uStack_c = iStack_14 - x1;
      iStack_12 = iStack_14;
    }
    else {
      iStack_12 = x1;
      uStack_c = 0;
    }
    if (iStack_18 < x2) {
      iVar2 = iStack_18 - iStack_12;
    }
    else {
      iVar2 = x2 - iStack_12;
    }
    uStack_10 = iVar2 + 1;
    if (0 < (int)uStack_10) {
      bStack_7 = shade2;
      if (shade2 < shade1) {
        bStack_7 = shade1;
      }
      uVar7 = gfx.seg;
      uVar5 = gfx.ofs;
      iVar2 = y1 - (*(int *)(uVar5 + 7) * (uint)bStack_7 >> 4);
      uVar6 = 1;
      if (in_stack_00000018 == '\0') {
        pfStack_6 = (far_t *)(GUnitDescriptions + 0x12);
      }
      else {
        pfStack_6 = (far_t *)&GUnitDescriptions[0xf].seg;
      }
      pfStack_4 = (far_t *)0x22a6;
      iStack_28 = uVar5 + 9;
      iStack_22 = x2 - x1;
      iStack_24 = (y2 - (*(int *)(uVar5 + 7) * (uint)bStack_7 >> 4)) - iVar2;
      if (iStack_22 == 0) {
        iStack_1c = 0;
        iStack_1e = 0;
      }
      else {
        iStack_1c = iStack_24 / iStack_22;
        uVar4 = iStack_24 % iStack_22 >> 0xf;
        iStack_1e = (iStack_24 % iStack_22 ^ uVar4) - uVar4;
      }
      uStack_26 = uVar7;
      iStack_20 = ovr_ovc07_signum(iStack_24);
      uStack_e = 0;
      while ((uStack_e < *(uint *)(uVar5 + 7) && (iVar2 <= iStack_1a))) {
        iVar3 = (*(code *)pfStack_6)(0x22da,iStack_28,uStack_26,&rowBuf);
        iStack_28 = iStack_28 + iVar3;
        if ((*(uint *)((uint)bStack_7 * 2 + 0x470) & uVar6) != 0) {
          src.seg = unaff_SS;
          src.ofs = (uint16_t)&rowBuf;
          blit_compute1(rectOfs[4],iVar2,iStack_12,src,uStack_c,*(uint16_t *)(uVar5 + 5),uStack_10,
                        *(uint16_t *)((uint)bStack_7 * 2 + 0x470),iStack_22,iStack_1c,iStack_1e,
                        iStack_20,iStack_16,iStack_1a);
          iVar2 = iVar2 + 1;
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
    uVar2 = ovr_randBelow(0x100,0);
    *puVar3 = (char)uVar2;
  }
  return;
}



/* 317e:1240 */

/* [R4] calls blitGfxN */

void __cdecl16far
blit_usesBlitGfxN2(far_t gfx,far_t gfx_00,int x1,int y1,byte shade1,int x2,int y2,byte shade2,brect_t *rect,uint16_t type,byte highlightLevel,uint16_t arg12,uint16_t arg13,uint16_t arg14,uint16_t arg15,uint16_t arg16,uint16_t arg17)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iStack_1a;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  int iStack_e;
  int iStack_c;
  uint uStack_8;
  int iStack_6;
  byte *pbStack_4;
  
  iVar4 = x2;
  bVar2 = shade1;
  iVar3 = y1 + ((int)((uint)shade1 * 0x38) >> 4);
  y2 = y2 + ((int)((uint)shade2 * 0x38) >> 4);
  ovr_ovc07_usesLDIV_at_(x1,iVar3,x2,y2,0x35,rect,type);
  y1 = iVar3;
  if (y2 < iVar3) {
    x2 = x1;
    shade1 = shade2;
    shade2 = bVar2;
    x1 = iVar4;
    y1 = y2;
    y2 = iVar3;
  }
  iVar3 = (y2 - y1) / 4;
  if (iVar3 == 0) {
    iStack_c = 0;
    iStack_e = 0;
  }
  else {
    iStack_c = (int)((uint)shade2 - (uint)shade1) / iVar3;
    uVar6 = (int)((uint)shade2 - (uint)shade1) % iVar3;
    uVar7 = (int)uVar6 >> 0xf;
    iStack_e = (uVar6 ^ uVar7) - uVar7;
  }
  iVar4 = ovr_ovc07_signum((uint)shade2 - (uint)shade1);
  iStack_1a = iVar3 >> 1;
  if (iVar3 == 0) {
    iStack_14 = 0;
    iStack_16 = 0;
  }
  else {
    iStack_14 = (x2 - x1) / iVar3;
    uVar6 = (x2 - x1) % iVar3;
    uVar7 = (int)uVar6 >> 0xf;
    iStack_16 = (uVar6 ^ uVar7) - uVar7;
  }
  iVar5 = ovr_ovc07_signum(x2 - x1);
  uStack_8 = (uint)shade1;
  pbStack_4 = (byte *)(x1 << 2);
  iStack_12 = iStack_1a;
  for (iStack_6 = y1; iStack_6 <= y2; iStack_6 = iStack_6 + 4) {
    pbVar1 = (byte *)((uint)pbStack_4 & 0xff);
    pbStack_4 = pbVar1 + 1;
    if ((*pbVar1 & 7) < highlightLevel) {
      blitGfxN(gfx,x1 + -7,iStack_6 + -2,(brect_t *)CONCAT22(type,rect),(uint8_t)uStack_8,false);
    }
    else {
      blitGfxN(gfx_00,x1 + -7,iStack_6 + -2,(brect_t *)CONCAT22(type,rect),(uint8_t)uStack_8,false);
    }
    uStack_8 = uStack_8 + iStack_c;
    iStack_12 = iStack_12 + iStack_e;
    if (iVar3 <= iStack_12) {
      iStack_12 = iStack_12 - iVar3;
      uStack_8 = uStack_8 + iVar4;
    }
    x1 = x1 + iStack_14;
    iStack_1a = iStack_1a + iStack_16;
    if (iVar3 <= iStack_1a) {
      iStack_1a = iStack_1a - iVar3;
      x1 = x1 + iVar5;
    }
  }
  return;
}


