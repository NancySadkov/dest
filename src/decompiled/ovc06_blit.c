/*
 * ovc06_blit.c - recovered from STRONG.EXE
 * memory block: OVC06_blit.c
 * range: 317e:0000 - 317e:14af
 * functions: 17
 */
#include "recovered.h"


/* 317e:0000 */
far_t * __cdecl16far
stshRleSub(far_t *retStorage,uint8_t *src,uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,int16_t hdrsz)

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
  prow = (int)&retStorage[sy * 0x50].ofs + sx;
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
stshRleCut(far_t *retStorage,far_t src,int16_t sx,int16_t sy,int16_t ex,int16_t ey,uint16_t arg7,uint16_t arg8,uint16_t arg9)

{
  far_t *pfVar1;
  
  pfVar1 = stshRleSub(retStorage,(uint8_t *)src.ofs,src.seg,sx,sy,ex,10);
  return pfVar1;
}



/* 317e:0168 */
far_t * __cdecl16far
stshRleType2(far_t *retStorage,far_t pixels,int16_t sx,int16_t sy,int16_t ex,int16_t ey,int16_t ox,int16_t oy,uint16_t arg9,uint16_t arg10)

{
  far_t far *pfVar1;
  uint16_t in_DX;
  far_t far *uStack_6;   /* hand fix: assigned a far_t pointer and used as uStack_6->ofs */
  
  pfVar1 = stshRleSub(retStorage,(uint8_t *)pixels.ofs,pixels.seg,sx,sy,ex,15);
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
  int16_t lineLen;
  int rows;
  char *linePtr;
  
  if (type) {
    if (gfx.ofs != 0 || gfx.seg != 0) {
      linePtr = (char *)(gfx.ofs + 9);
      for (rows = *(int *)(gfx.ofs + 7); rows != 0; rows = rows + -1) {
        lineLen = ovr_drawLine2(linePtr,(char *)CONCAT22(dst.ofs,gfx.seg),dst.seg);
        linePtr = linePtr + lineLen;
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
  int rowBytes;            /* bytes the row decoder consumed */
  uint16_t dxIn;           /* DX on entry: the decoded graphic's segment */
  int row;                 /* destination row counter */
  uint16_t ovlSeg;         /* overlay segment selector for the calls */
  undefined1 dstHighByte;  /* high byte of the split destination pointer */
  far_t dst_01;
  uint8_t rowBuf;
  uint16_t dst_h;
  uint16_t dst_w;
  uint16_t dst_y;
  uint16_t dst_x;
  int srcOfs;             /* source data offset, advanced by rowBytes */
  uint16_t gfxSeg;
  uint16_t dstOfs;         /* running destination offset */
  uint16_t savedDstSeg;
  int spanH;
  uint16_t spanW;
  int srcX;                /* column offset of the span inside the row */
  uint16_t bottomY;        /* clipped span bottom */
  uint16_t rightX;         /* clipped span right edge */
  uint16_t topY;           /* clipped span top */
  uint16_t leftX;          /* clipped span left edge */
  uint16_t pfn;
  uint16_t dstSegSel;      /* destination segment selector (0x22a6) */
  
  dst = (uint16_t *)CONCAT13(dstHighByte,CONCAT12(type,dst));
  ovlSeg = 0x317e;
  if (gfx.ofs != 0 || gfx.seg != 0) {
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) == '\0') {
      ovlSeg = 0x2337;
      gfx.ofs = (uint16_t)ovr_stshLoadGfx(gfx);
      gfx.seg = dxIn;
    }
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) != '\x01') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
    dst_x = dst->x;   /* hand fix: read the first field; *dst is the whole structure */
    dst_y = dst->y;
    dst_w = dst->w;
    dst_h = dst->h;
    if (((((int)x < (int)dst_x) || ((int)y < (int)dst_y)) ||
        ((int)dst_w < (int)(x + *(int *)(gfx.ofs + 5) + -1))) ||
       ((int)dst_h < (int)(y + *(int *)(gfx.ofs + 7) + -1))) {
      if (type == false) {
        pfn = 0x133;
      }
      else {
        pfn = 0x129;
      }
      dstSegSel = 0x22a6;
      if (((int)dst_x <= (int)(x + *(int *)(gfx.ofs + 5) + -1)) && ((int)x <= (int)dst_w)) {
        if ((int)x < (int)dst_x) {
          srcX = dst_x - x;
          leftX = dst_x;
        }
        else {
          leftX = x;
          srcX = 0;
        }
        rightX = dst_w;
        if ((int)(x + *(int *)(gfx.ofs + 5) + -1) <= (int)dst_w) {
          rightX = (x + *(int *)(gfx.ofs + 5)) - 1;
        }
        spanW = (rightX - leftX) + 1;
        topY = dst_y;
        if ((int)dst_y <= (int)y) {
          topY = y;
        }
        bottomY = dst_h;
        if ((int)(y + *(int *)(gfx.ofs + 7) + -1) <= (int)dst_h) {
          bottomY = (y + *(int *)(gfx.ofs + 7)) - 1;
        }
        spanH = (bottomY - y) + 1;
        dstOfs = leftX + topY * 0x140;
        savedDstSeg = dst->seg;
        srcOfs = gfx.ofs + 9;
        gfxSeg = gfx.seg;
        for (row = 0; (row < spanH && ((int)(row + y) <= (int)dst_h)); row = row + 1)
        {
          rowBytes = (*(code *)pfn)(ovlSeg,srcOfs,gfxSeg,&rowBuf);
          srcOfs = srcOfs + rowBytes;
          if ((int)dst_y <= (int)(row + y)) {
            dst_01.seg = savedDstSeg;
            dst_01.ofs = dstOfs;
            ovlSeg = 0x138e;
            src.seg = _SS;
            src.ofs = (uint16_t)(&rowBuf + srcX);
            blitTillAlpha(dst_01,src,spanW);
            dstOfs = dstOfs + 0x140;
          }
        }
      }
    }
    else {
      dst_00.seg = dst->seg;
      dst_00.ofs = x + y * 0x140;
      drawGfx(gfx,dst_00,type);
    }
  }
  return;
}


/* 317e:04c2 */

/* [R4] calls drawGfx */

void __cdecl16far blit_usesDrawGfx(far_t gfx, int x, int y, brect_t far *rect)

{
  far_t dst;
  far_t dst_00;
  int rowLen;
  uint16_t in_DX;
  brect_t *rectP;
  int row;
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
          dst_00.seg = _SS;
          dst_00.ofs = (uint16_t)&rowBuf;
          rowLen = ovr_unrle(src,dst_00,*(uint16_t *)(gfx.ofs + 5),(char)*(uint16_t *)(gfx.ofs + 5),0);
          srcOfs = srcOfs + rowLen;
          if (rectY <= row + y) {
            _fmemmove((char far *)MK_FP(dstSeg,dstOfs),
                   (char far *)MK_FP(_SS,&rowBuf + xSkip),copyW);
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
  uint dstY;
  uint dstH;
  char *dstSeg;
  uint mask;
  uint16_t in_DX;
  uint bitMask;
  char buf [320];
  uint16_t pdst;
  uint16_t h;
  uint16_t pd;
  uint16_t skip;
  uint row;
  code *unrleFn;
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
      dstY = ((brect_t *)dst)->y;
      dstH = ((brect_t *)dst)->h;
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
        dstSeg = (char *)((brect_t *)dst)->seg;
        bitMask = 1;
        if (mirror) {
          unrleFn = (code *)ovr_unrle_mirror;
        }
        else {
          unrleFn = (code *)ovr_unrle;
        }
        pcStack_4 = (code *)0x22a6;
        row = 0;
        while ((row < *(uint *)(gfx.ofs + 7) && ((uint)y <= dstH))) {
          (*unrleFn)();
          if ((*(uint *)((uint)type * 2 + 0x470) & bitMask) != 0) {
            if (dstY <= (uint)y) {
              ovr_masked_memcpy((char *)pdst,(char *)CONCAT22(buf,dstSeg),_SS,skip,*(int *)(gfx.ofs + 5),mask,0);
            }
            pdst = pdst + 0x140;
            y = y + 1;
          }
          if (bitMask == 0x8000) {
            bitMask = 1;
          }
          else {
            bitMask = bitMask << 1;
          }
          row = row + 1;
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

void __cdecl16far blit_usesRandBelow(byte far *buf, uint16_t count, byte value, byte chance)

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
  uint dstRow;             /* destination row, advanced per emitted row */
  int rowBytes;            /* bytes the row decoder consumed */
  uint16_t gfxSegIn;       /* DX on entry: the loaded graphic's segment */
  uint bitMask;            /* rotated 1, 2, 4 ... 0x8000 per row */
  uint16_t uVar4;
  uint16_t ovlSeg;         /* overlay segment selector for the calls */
  undefined1 ptrHighByte;  /* high byte of the split rectOfs pointer */
  uint8_t in_stack_00000016;
  byte in_stack_00000018;
  uint8_t skip;
  int srcOfs;              /* source data offset, advanced by rowBytes */
  uint16_t gfxSeg;
  char *dstPtr;            /* running destination pointer */
  char *srcPtr;
  uint rectBottom;
  int rectRight;
  uint rectTop;
  int rectLeft;
  char *colCursor;         /* the span's left column */
  uint spanW;
  uint clipLeft;           /* columns clipped off the left edge */
  uint row;                /* row counter within the graphic */
  far_t *rowDecode;        /* the row decoder selected by `scale` */
  far_t *unusedSel;        /* 0x22a6, stored and never read */
  
  rectOfs = (int *)CONCAT13(ptrHighByte,CONCAT12(scale,rectOfs));
  ovlSeg = 0x317e;
  if ((gfx.ofs != 0 || gfx.seg != 0) && (flip != '\0')) {
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) == '\0') {
      ovlSeg = 0x2337;
      gfx.ofs = (uint16_t)ovr_stshLoadGfx(gfx);
      gfx.seg = gfxSegIn;
    }
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) != '\x02') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
    rectLeft = *rectOfs;
    uVar4 = (uint16_t)((ulong)rectOfs >> 0x10);
    rectTop = rectOfs[1];
    rectRight = rectOfs[2];
    rectBottom = rectOfs[3];
    if (scale == '\0') {
      dstRow = (int)((uint)(byte)flip * *(int *)(gfx.ofs + 1)) >> 4;
    }
    else {
      dstRow = (uint)(byte)flip * ((*(int *)(gfx.ofs + 10) + -1) - *(int *)(gfx.ofs + 1)) >> 4;
    }
    x = x - dstRow;
    dstRow = y - ((int)((uint)(byte)flip * *(int *)(gfx.ofs + 3)) >> 4);
    if (x < rectLeft) {
      clipLeft = rectLeft - x;
      colCursor = (char *)rectLeft;
      if (*(uint *)(gfx.ofs + 10) <= clipLeft) {
        return;
      }
    }
    else {
      colCursor = (char *)x;
      clipLeft = 0;
    }
    spanW = (rectRight - (int)colCursor) + 1;
    if (0 < (int)spanW) {
      dstPtr = (char *)((int)colCursor + dstRow * 0x140);
      srcPtr = (char *)rectOfs[4];
      bitMask = 1;
      if (scale == '\0') {
        rowDecode = (far_t *)(GUnitDescriptions + 0x12);
      }
      else {
        rowDecode = (far_t *)&GUnitDescriptions[0xf].seg;
      }
      unusedSel = (far_t *)0x22a6;
      srcOfs = gfx.ofs + 0xe;
      gfxSeg = gfx.seg;
      colCursor = dstPtr;
      if (flip == 0xff) {
        row = 0;
        while ((row < *(uint *)(gfx.ofs + 0xc) && (dstRow <= rectBottom))) {
          rowBytes = (*(code *)rowDecode)(ovlSeg,srcOfs,gfxSeg,&skip);
          srcOfs = srcOfs + rowBytes;
          if ((*(uint *)((uint)(byte)flip * 2 + 0x470) & bitMask) != 0) {
            if (rectTop <= dstRow) {
              copyGrayscalePalette
                        ((uint8_t *)CONCAT22(_SS,&skip + clipLeft),
                         *(int *)(gfx.ofs + 10) - clipLeft);
              ovlSeg = 0x22a6;
              ovr_masked_memcpy(dstPtr,(char *)CONCAT22(&skip,srcPtr),_SS,clipLeft,
                                *(int *)(gfx.ofs + 10),spanW,
                                *(uint16_t *)((uint)(byte)flip * 2 + 0x470));
            }
            dstPtr = dstPtr + 0x140;
            dstRow = dstRow + 1;
          }
          if (bitMask == 0x8000) {
            bitMask = 1;
          }
          else {
            bitMask = bitMask << 1;
          }
          row = row + 1;
        }
      }
      else {
        row = 0;
        while ((row < *(uint *)(gfx.ofs + 0xc) && (dstRow <= rectBottom))) {
          rowBytes = (*(code *)rowDecode)(ovlSeg,srcOfs,gfxSeg,&skip);
          srcOfs = srcOfs + rowBytes;
          if ((*(uint *)((uint)(byte)flip * 2 + 0x470) & bitMask) != 0) {
            if (rectTop <= dstRow) {
              buf.seg = _SS;
              buf.ofs = (uint16_t)(&skip + clipLeft);
              ovr_driver_scan1(buf,*(int *)(gfx.ofs + 10) - clipLeft,flip,
                               in_stack_00000016,far_from_u32((uint32_t)(0x15290000)),(uint)in_stack_00000018);
              in_stack_00000018 = in_stack_00000018 + (*(char *)(gfx.ofs + 10) - (char)clipLeft);
              ovlSeg = 0x22a6;
              ovr_masked_memcpy(dstPtr,(char *)CONCAT22(&skip,srcPtr),_SS,clipLeft,
                                *(int *)(gfx.ofs + 10),spanW,
                                *(uint16_t *)((uint)(byte)flip * 2 + 0x470));
            }
            dstPtr = dstPtr + 0x140;
            dstRow = dstRow + 1;
          }
          if (bitMask == 0x8000) {
            bitMask = 1;
          }
          else {
            bitMask = bitMask << 1;
          }
          row = row + 1;
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
  /* Re-derived: vertical gradient blit.  When y2 < y the endpoints and their shade bytes
     are swapped, then the shade walks from shade1 to shade2 by a Bresenham step over
     (y2-y)/2, drawing one row every 2 lines. */
  byte savedShade;
  int savedY;
  uint halfSpan;
  int shadeStep;
  uint shadeRem;
  uint remSign;
  uint shadeFrac;
  int shadeStepSign;
  uint spanSign;
  uint spanAbs;
  int shadeErr;
  uint16_t shadeCur;

  savedShade = shade1;
  savedY = y;
  if (y2 < y) {
    y = y2;
    y2 = savedY;
    shade1 = shade2;
    shade2 = savedShade;
  }
  halfSpan = y2 - y >> 1;
  if (halfSpan == 0) {
    shadeStep = 0;
    shadeFrac = 0;
  }
  else {
    shadeStep = (int)((uint)shade2 - (uint)shade1) / (int)halfSpan;
    shadeRem = (int)((uint)shade2 - (uint)shade1) % (int)halfSpan;
    remSign = (int)shadeRem >> 0xf;
    shadeFrac = (shadeRem ^ remSign) - remSign;
  }
  shadeStepSign = ovr_ovc07_signum((uint)shade2 - (uint)shade1);
  spanSign = y2 - y >> 0xf;
  spanAbs = (halfSpan ^ spanSign) - spanSign;
  shadeErr = (int)spanAbs >> 1;
  shadeCur = (uint)shade1;
  for (; y <= y2; y = y + 2) {
    blitGfxN(gfx,x,y,(brect_t *)CONCAT22(type,rect),(uint8_t)shadeCur,false);
    shadeCur = shadeCur + shadeStep;
    shadeErr = shadeErr + shadeFrac;
    if ((int)spanAbs <= shadeErr) {
      shadeErr = shadeErr - spanAbs;
      shadeCur = shadeCur + shadeStepSign;
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
  int yAcc;                /* y accumulator advanced by yStep */
  uint bitMask;            /* rotated 1, 2, 4 ... 0x8000 across dx */
  uint drawn;              /* pixels written for the current mask bit */
  uint srcCol;             /* source column counter */
  uint dstCol;             /* destination column counter */
  int16_t screenOfs;       /* running screen offset, +1 per emitted pixel */
  
  yAcc = ySlope >> 1;
  bitMask = 1;
  screenOfs = x;
  srcCol = 0;
  drawn = 0;
  dstCol = 0;
  do {
    if (clipWidth <= dstCol) {
      return;
    }
    if ((dx & bitMask) != 0) {
      if (imgWidth <= srcCol) {
        if (((*(char *)(src.ofs + dstCol) != '\0') && (clipTop <= y)) && (y <= clipBottom)) {
          *(undefined1 *)(screenOfs + y * 0x140) = *(undefined1 *)(src.ofs + dstCol);
        }
        screenOfs = screenOfs + 1;
        drawn = drawn + 1;
        if (mask <= drawn) {
          return;
        }
      }
      srcCol = srcCol + 1;
      yAcc = yAcc + yStep;
      y = y + yRemainder;
      if (ySlope <= yAcc) {
        y = y + yJump;
        yAcc = yAcc - ySlope;
      }
    }
    if (bitMask == 0x8000) {
      bitMask = 1;
    }
    else {
      bitMask = bitMask << 1;
    }
    dstCol = dstCol + 1;
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
          src.seg = _SS;
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
  uint seedScaled;
  uint16_t randByte;
  undefined1 *tblPtr;
  
  seedScaled = GfxRndSeed * 0x100;
  srand8(CONCAT22(((int)GfxRndSeed2 >> 0xf) + ((int)seedScaled >> 0xf) + (uint)CARRY2(GfxRndSeed2,seedScaled),
                  GfxRndSeed2 + seedScaled));
  for (tblPtr = (undefined1 *)0x0; (int)tblPtr < 0x100; tblPtr = tblPtr + 1) {
    randByte = ovr_randBelow(0x100,0);
    *tblPtr = (char)randByte;
  }
  return;
}



/* 317e:1240 */

/* [R4] calls blitGfxN */

void __cdecl16far
blit_usesBlitGfxN2(far_t gfx,far_t gfx_00,int x1,int y1,byte shade1,int x2,int y2,byte shade2,brect_t *rect,uint16_t type,byte highlightLevel,uint16_t arg12,uint16_t arg13,uint16_t arg14,uint16_t arg15,uint16_t arg16,uint16_t arg17)

{
  /* Re-derived: two-edge gradient blit.  y1/y2 are shifted by shade*0x38>>4 before
     ovc07_usesLDIV_at_ decides whether the band is drawn; after the optional endpoint
     swap the span becomes (y2-y1)/4 bands, the shade walks with one DDA and x with
     another, and each band picks gfx or gfx_00 from (byte at x1<<2) & 7 against
     highlightLevel. */
  byte *highlightPtr;
  byte *highlightByte;
  byte savedShade;
  int savedX2;
  int y1adj;
  int bandCount;
  int shadeStep;
  uint shadeRem;
  uint remSign;
  int shadeFrac;
  int shadeStepSign;
  int errInit;
  int shadeErr;
  int xErr;
  int xStep;
  int xFrac;
  int xStepSign;
  uint16_t shadeCur;
  int rowY;

  savedX2 = x2;
  savedShade = shade1;
  y1adj = y1 + ((int)((uint)shade1 * 0x38) >> 4);
  y2 = y2 + ((int)((uint)shade2 * 0x38) >> 4);
  ovr_ovc07_usesLDIV_at_(x1,y1adj,x2,y2,0x35,rect,type);
  y1 = y1adj;
  if (y2 < y1adj) {
    x2 = x1;
    shade1 = shade2;
    shade2 = savedShade;
    x1 = savedX2;
    y1 = y2;
    y2 = y1adj;
  }
  bandCount = (y2 - y1) / 4;
  if (bandCount == 0) {
    shadeStep = 0;
    shadeFrac = 0;
  }
  else {
    shadeStep = (int)((uint)shade2 - (uint)shade1) / bandCount;
    shadeRem = (int)((uint)shade2 - (uint)shade1) % bandCount;
    remSign = (int)shadeRem >> 0xf;
    shadeFrac = (shadeRem ^ remSign) - remSign;
  }
  shadeStepSign = ovr_ovc07_signum((uint)shade2 - (uint)shade1);
  errInit = bandCount >> 1;
  if (bandCount == 0) {
    xStep = 0;
    xFrac = 0;
  }
  else {
    xStep = (x2 - x1) / bandCount;
    shadeRem = (x2 - x1) % bandCount;
    remSign = (int)shadeRem >> 0xf;
    xFrac = (shadeRem ^ remSign) - remSign;
  }
  xStepSign = ovr_ovc07_signum(x2 - x1);
  shadeCur = (uint)shade1;
  highlightPtr = (byte *)(x1 << 2);
  xErr = errInit;
  shadeErr = errInit;
  for (rowY = y1; rowY <= y2; rowY = rowY + 4) {
    highlightByte = (byte *)((uint)highlightPtr & 0xff);
    highlightPtr = highlightByte + 1;
    if ((*highlightByte & 7) < highlightLevel) {
      blitGfxN(gfx,x1 + -7,rowY + -2,(brect_t *)CONCAT22(type,rect),
               (uint8_t)shadeCur,false);
    }
    else {
      blitGfxN(gfx_00,x1 + -7,rowY + -2,(brect_t *)CONCAT22(type,rect),
               (uint8_t)shadeCur,false);
    }
    shadeCur = shadeCur + shadeStep;
    shadeErr = shadeErr + shadeFrac;
    if (bandCount <= shadeErr) {
      shadeErr = shadeErr - bandCount;
      shadeCur = shadeCur + shadeStepSign;
    }
    x1 = x1 + xStep;
    xErr = xErr + xFrac;
    if (bandCount <= xErr) {
      xErr = xErr - bandCount;
      x1 = x1 + xStepSign;
    }
  }
  return;
}


