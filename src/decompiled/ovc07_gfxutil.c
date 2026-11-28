/*
 * ovc07_gfxutil.c - recovered from STRONG.EXE
 * memory block: OVC07_gfxutil.c
 * range: 32c9:0000 - 32c9:06ef
 * functions: 5
 */
#include "recovered.h"


/* 32c9:0000 */

/* Swaps the two 16-bit values it is given. */

void __cdecl16far ovc07_swapWords(uint16_t far *wordA,uint16_t far *wordB)

{
  /* Re-derived from 32c9:0000 (38 bytes): tmp = *wordA; *wordA = *wordB; *wordB = tmp.  Both
     parameters are loaded with `les`, so they are `uint16_t far *`, not the near pointers the export
     declared; its CONCAT22 rebuilds could not address the same object. */
  uint16_t tmp;

  tmp = *wordA;
  *wordA = *wordB;
  *wordB = tmp;
  return;
}



/* 32c9:0026 */

/* Returns the sign of its argument (-1, 0 or 1). */

uint16_t __cdecl16far ovc07_signum(int value)

{
  uint16_t uVar1;
  
  if (value < 0) {
    uVar1 = 0xffff;
  }
  else if (value < 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 32c9:0044 */

/* [R4] calls ovr_biosReadKey */

void __cdecl16far
ovc07_usesBiosReadKey(int x1,int y1,int x2,int y2,int x3,int y3,uint16_t rectSeg,brect_t *rect,uint16_t arg9,uint16_t arg10,uint16_t arg11,uint16_t arg12,uint16_t arg13,uint16_t arg14)

{
  /* 32c9:0044, re-derived.  Triangle rasteriser.  When the triangle is not wholly
     inside the clip rectangle its vertices are sorted by y ascending and two DDA edge
     walks fill the spans between the (x1,y1)-(x2,y2) edge and the (x1,y1)-(x3,y3) edge;
     when it is wholly inside, the driver helper draws it directly. */
  int clipX;
  int clipY;
  int clipW;
  int clipH;
  uint16_t clipSeg;
  brect_t *clip;
  int swapX;
  int swapY;
  int tmpY;
  int yB;
  int xEdge;
  int curX;
  int rowY;
  int slope1;
  int frac1;
  int err1;
  int stepX1;
  int slope2;
  int frac2;
  int err2;
  int stepX2;
  uint rem;
  uint sgn;

  swapY = y2;
  swapX = x1;
  clipX = rect->x;
  clipSeg = (uint16_t)((ulong)rect >> 0x10);
  clip = (brect_t *)rect;
  clipY = clip->y;
  clipW = clip->w;
  clipH = clip->h;
  if (((((((x1 < clipX) || (clipW < x1)) || (y1 < clipY)) ||
        ((clipH < y1 || (x2 < clipX)))) ||
       ((clipW < x2 || ((y2 < clipY || (clipH < y2)))))) || (x3 < clipX)) ||
     (((clipW < x3 || (y3 < clipY)) || (clipH < y3)))) {
    if (y2 < y1) {
      y2 = y1;
      x1 = x2;
      x2 = swapX;
      y1 = swapY;
    }
    swapY = x2;
    swapX = x1;
    tmpY = y3;
    if (y3 < y1) {
      x1 = x3;
      x3 = swapX;
      tmpY = y1;
      y1 = y3;
    }
    yB = tmpY;
    if (tmpY < y2) {
      x2 = x3;
      x3 = swapY;
      yB = y2;
      y2 = tmpY;
    }
    if ((((y1 <= clipH) && (clipY <= yB)) &&
        ((clipX <= x1 || ((clipX <= x2 || (clipX <= x3)))))) &&
       ((x1 <= clipW || ((x2 <= clipW || (x3 <= clipW)))))) {
      if (199 < y1) {
        printf("y1 %d yn %d y3 %d yx %d ");
        ovr_biosReadKey();
      }
      xEdge = x1;
      if (y1 != yB) {
        slope1 = (x3 - x1) / (yB - y1);
        rem = (x3 - x1) % (yB - y1);
        sgn = (int)rem >> 0xf;
        frac1 = (rem ^ sgn) - sgn;
        stepX1 = ovc07_signum(x3 - x1);
        err1 = yB - y1 >> 1;
      }
      curX = x1;
      err2 = y2 - y1 >> 1;
      stepX2 = ovc07_signum(x2 - x1);
      rowY = y1;
      if (y1 == y2) {
        slope2 = 0;
        frac2 = 0;
      }
      else {
        slope2 = (x2 - x1) / (y2 - y1);
        rem = (x2 - x1) % (y2 - y1);
        sgn = (int)rem >> 0xf;
        frac2 = (rem ^ sgn) - sgn;
      }
      for (; rowY < y2; rowY = rowY + 1) {
        if ((clipY <= rowY) && (rowY <= clipH)) {
          ovr_driver_fillSpan(curX,xEdge,(byte)rowY,(uint8_t)rectSeg,&clip->x,clipSeg);
        }
        curX = curX + slope2;
        err2 = err2 + frac2;
        if (y2 - y1 <= err2) {
          curX = curX + stepX2;
          err2 = err2 - (y2 - y1);
        }
        xEdge = xEdge + slope1;
        err1 = err1 + frac1;
        if (yB - y1 <= err1) {
          xEdge = xEdge + stepX1;
          err1 = err1 - (yB - y1);
        }
      }
      curX = x2;
      err2 = yB - y2 >> 1;
      stepX2 = ovc07_signum(x3 - x2);
      if (y2 == yB) {
        slope2 = 0;
        frac2 = 0;
      }
      else {
        slope2 = (x3 - x2) / (yB - y2);
        rem = (x3 - x2) % (yB - y2);
        sgn = (int)rem >> 0xf;
        frac2 = (rem ^ sgn) - sgn;
      }
      for (rowY = y2; rowY <= yB; rowY = rowY + 1) {
        if ((clipY <= rowY) && (rowY <= clipH)) {
          ovr_driver_fillSpan(curX,xEdge,(byte)rowY,(uint8_t)rectSeg,&clip->x,clipSeg);
        }
        curX = curX + slope2;
        err2 = err2 + frac2;
        if (yB - y2 <= err2) {
          curX = curX + stepX2;
          err2 = err2 - (yB - y2);
        }
        xEdge = xEdge + slope1;
        err1 = err1 + frac1;
        if (yB - y1 <= err1) {
          xEdge = xEdge + stepX1;
          err1 = err1 - (yB - y1);
        }
      }
    }
  }
  else {
    ovr_driver_compute5(x1,(byte)y1,x2,(byte)y2,x3,(byte)y3,rectSeg,clip->seg);
  }
  return;
}



/* 32c9:03c4 */

/* [R4] calls ovr_driver_fillRect */

void __cdecl16far ovc07_usesFillRect(int x1, int y1, int x2, int y2, uint16_t colour, brect_t far *rect, uint16_t arg7)

{
  int x2Orig;
  int y2Orig;
  
  y2Orig = y2;
  x2Orig = x2;
  if (x2 < x1) {
    x2 = x1;
    x1 = x2Orig;
  }
  if (y2 < y1) {
    y2 = y1;
    y1 = y2Orig;
  }
  if (x1 < rect->x) {
    x1 = rect->x;
  }
  if (y1 < rect->y) {
    y1 = rect->y;
  }
  if (rect->w < x2) {
    x2 = rect->w;
  }
  if (rect->h < y2) {
    y2 = rect->h;
  }
  if ((x1 <= x2) && (y1 <= y2)) {
    ovr_driver_fillRect(x1,y1,x2,y2,(uint8_t)colour,rect->seg,0,0,0,0,0);
  }
  return;
}



/* 32c9:0466 */

/* [R4] calls LDIV_at_ */

void __cdecl16far
ovc07_usesLDIV_at_(int ofs1,int row1,int ofs2,int row2,uint8_t colour,brect_t *rect,uint16_t arg7)

{
  uint8_t *clipX0;          /* rect->x, the left clip edge */
  int clipY0;               /* rect->y, the top clip edge */
  uint8_t *clipX1;          /* rect->w, the right clip edge */
  int clipY1;               /* rect->h, the bottom clip edge */
  uint8_t *curOfs;          /* the endpoint the loop is working on */
  long *plVar6;
  long *plVar7;
  int deltaHi;               /* the high word of a 32-bit delta */
  int divHi;                /* the high word of the division numerator */
  int iVar10;
  uint unaff_SI;
  uint16_t unaff_DI;
  bool anyOut;              /* either endpoint is still outside */
  long lVar12;
  uint16_t in_stack_00000010;
  uint3 out2;                /* the second endpoint's packed outcodes */
  byte outcodeB;            /* the second endpoint's outcode byte */
  ulong b;
  byte outcodeA;            /* the first endpoint's outcode byte */
  ulong outpack;            /* both endpoints' outcodes, packed 4 bits each */
  
  clipX0 = (uint8_t *)rect->x;
  clipY0 = rect->y;
  clipX1 = (uint8_t *)rect->w;
  clipY1 = rect->h;
  outpack = (ulong)unaff_SI;
  if (ofs1 < (int)clipX0) {
    outpack = CONCAT13(1,(uint3)unaff_SI);
  }
  if ((int)clipX1 < ofs1) {
    outpack = CONCAT13((char)(outpack >> 0x18) + '\x04',(int3)outpack);
  }
  if (row1 < clipY0) {
    outpack = CONCAT13((char)(outpack >> 0x18) + '\x02',(int3)outpack);
  }
  if (clipY1 < row1) {
    outpack = CONCAT13((char)(outpack >> 0x18) + '\b',(int3)outpack);
  }
  outcodeA = (byte)(outpack >> 0x18);
  out2 = (uint3)(uint)outpack;
  if (ofs2 < (int)clipX0) {
    out2 = CONCAT12(1,(uint)outpack);
  }
  if ((int)clipX1 < ofs2) {
    out2 = CONCAT12((char)(out2 >> 0x10) + '\x04',(int)out2);
  }
  if (row2 < clipY0) {
    out2 = CONCAT12((char)(out2 >> 0x10) + '\x02',(int)out2);
  }
  if (clipY1 < row2) {
    out2 = CONCAT12((char)(out2 >> 0x10) + '\b',(int)out2);
  }
  outpack = CONCAT13(outcodeA,out2);
  outcodeB = (byte)(out2 >> 0x10);
  anyOut = outcodeA != 0 || outcodeB != 0;
  outcodeA = outcodeA & outcodeB;
  while ((outcodeA == 0 && (anyOut))) {
    curOfs = (uint8_t *)ofs1;
    iVar10 = row1;
    b = outpack;
    if ((char)(outpack >> 0x18) == '\0') {
      b = CONCAT13((char)(outpack >> 0x10),(uint3)(uint)outpack);
      curOfs = (uint8_t *)ofs2;
      iVar10 = row2;
      ofs2 = ofs1;
      row2 = row1;
    }
    ofs1 = (int)curOfs;
    if ((b & 0x1000000) == 0) {
      if ((b & 0x2000000) == 0) {
        if ((b & 0x4000000) == 0) {
          row1 = iVar10;
          if ((b & 0x8000000) != 0) {
            plVar6 = (long *)(row2 - iVar10);
            deltaHi = (int)plVar6 >> 0xf;
            iVar10 = clipY1 - iVar10 >> 0xf;
            plVar7 = LXMUL_at_(plVar6,CONCAT22(unaff_DI,deltaHi),b);
            lVar12 = LDIV_at_((long)CONCAT22(iVar10,plVar7),(long)CONCAT22(deltaHi,plVar6));
            ofs1 = ofs1 + (int)lVar12;
            row1 = clipY1;
          }
        }
        else {
          plVar6 = (long *)(ofs2 - ofs1);
          deltaHi = (int)plVar6 >> 0xf;
          divHi = (int)clipX1 - ofs1 >> 0xf;
          plVar7 = LXMUL_at_(plVar6,CONCAT22(unaff_DI,deltaHi),b);
          lVar12 = LDIV_at_((long)CONCAT22(divHi,plVar7),(long)CONCAT22(deltaHi,plVar6));
          ofs1 = (int)clipX1;
          row1 = iVar10 + (int)lVar12;
        }
      }
      else {
        plVar6 = (long *)(row2 - iVar10);
        deltaHi = (int)plVar6 >> 0xf;
        iVar10 = clipY0 - iVar10 >> 0xf;
        plVar7 = LXMUL_at_(plVar6,CONCAT22(unaff_DI,deltaHi),b);
        lVar12 = LDIV_at_((long)CONCAT22(iVar10,plVar7),(long)CONCAT22(deltaHi,plVar6));
        ofs1 = (int)(ofs1 + (int)lVar12);
        row1 = clipY0;
      }
    }
    else {
      plVar6 = (long *)(ofs2 - ofs1);
      deltaHi = (int)plVar6 >> 0xf;
      divHi = (int)clipX0 - ofs1 >> 0xf;
      plVar7 = LXMUL_at_(plVar6,CONCAT22(unaff_DI,deltaHi),b);
      lVar12 = LDIV_at_((long)CONCAT22(divHi,plVar7),(long)CONCAT22(deltaHi,plVar6));
      ofs1 = (int)clipX0;
      row1 = iVar10 + (int)lVar12;
    }
    outpack = b & 0xffffff;
    if (ofs1 < (int)clipX0) {
      outpack = CONCAT13(1,(int3)b);
    }
    if ((int)clipX1 < ofs1) {
      outpack = CONCAT13((char)(outpack >> 0x18) + '\x04',(int3)outpack);
    }
    if (row1 < clipY0) {
      outpack = CONCAT13((char)(outpack >> 0x18) + '\x02',(int3)outpack);
    }
    if (clipY1 < row1) {
      outpack = CONCAT13((char)(outpack >> 0x18) + '\b',(int3)outpack);
    }
    outcodeA = (byte)(outpack >> 0x18);
    outcodeB = (byte)(outpack >> 0x10);
    anyOut = outcodeA != 0 || outcodeB != 0;
    outcodeA = outcodeA & outcodeB;
  }
  if (!anyOut) {
    ovr_driver_drawLine((uint8_t *)ofs1,row1,(uint8_t *)ofs2,row2,colour,colour,rect->seg,0,0);
  }
  return;
}


