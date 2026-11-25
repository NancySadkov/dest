/*
 * ovc07_gfxutil.c - recovered from STRONG.EXE
 * memory block: OVC07_gfxutil.c
 * range: 32c9:0000 - 32c9:06ef
 * functions: 5
 */
#include "recovered.h"


/* 32c9:0000 */

/* Swaps the two 16-bit values it is given. */

void __cdecl16far ovc07_swapWords(uint16_t *wordA,uint16_t *wordB)

{
  uint16_t uVar1;
  uint16_t *in_stack_00000004;
  
  uVar1 = *(uint16_t *)CONCAT22((uint16_t *)wordA,in_stack_00000004);
  *(uint16_t *)CONCAT22((uint16_t *)wordA,in_stack_00000004) =
       *(uint16_t *)CONCAT22((uint16_t *)wordB,(*(uint16_t *)((uint8_t *)&(wordA) + 2)));
  *(uint16_t *)CONCAT22((uint16_t *)wordB,(*(uint16_t *)((uint8_t *)&(wordA) + 2))) = uVar1;
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

void __cdecl16far ovc07_usesFillRect(int x1,int y1,int x2,int y2,uint16_t colour,brect_t *rect,uint16_t arg7)

{
  int iVar1;
  int iVar2;
  
  iVar2 = y2;
  iVar1 = x2;
  if (x2 < x1) {
    x2 = x1;
    x1 = iVar1;
  }
  if (y2 < y1) {
    y2 = y1;
    y1 = iVar2;
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
  uint8_t *puVar1;
  int iVar2;
  uint8_t *puVar3;
  int iVar4;
  uint8_t *puVar5;
  long *plVar6;
  long *plVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint unaff_SI;
  uint16_t unaff_DI;
  bool bVar11;
  long lVar12;
  uint16_t in_stack_00000010;
  uint3 uVar13;
  byte bVar15;
  ulong b;
  byte bStack_e;
  ulong uVar14;
  
  puVar1 = (uint8_t *)rect->x;
  iVar2 = rect->y;
  puVar3 = (uint8_t *)rect->w;
  iVar4 = rect->h;
  uVar14 = (ulong)unaff_SI;
  if (ofs1 < (int)puVar1) {
    uVar14 = CONCAT13(1,(uint3)unaff_SI);
  }
  if ((int)puVar3 < ofs1) {
    uVar14 = CONCAT13((char)(uVar14 >> 0x18) + '\x04',(int3)uVar14);
  }
  if (row1 < iVar2) {
    uVar14 = CONCAT13((char)(uVar14 >> 0x18) + '\x02',(int3)uVar14);
  }
  if (iVar4 < row1) {
    uVar14 = CONCAT13((char)(uVar14 >> 0x18) + '\b',(int3)uVar14);
  }
  bStack_e = (byte)(uVar14 >> 0x18);
  uVar13 = (uint3)(uint)uVar14;
  if (ofs2 < (int)puVar1) {
    uVar13 = CONCAT12(1,(uint)uVar14);
  }
  if ((int)puVar3 < ofs2) {
    uVar13 = CONCAT12((char)(uVar13 >> 0x10) + '\x04',(int)uVar13);
  }
  if (row2 < iVar2) {
    uVar13 = CONCAT12((char)(uVar13 >> 0x10) + '\x02',(int)uVar13);
  }
  if (iVar4 < row2) {
    uVar13 = CONCAT12((char)(uVar13 >> 0x10) + '\b',(int)uVar13);
  }
  uVar14 = CONCAT13(bStack_e,uVar13);
  bVar15 = (byte)(uVar13 >> 0x10);
  bVar11 = bStack_e != 0 || bVar15 != 0;
  bStack_e = bStack_e & bVar15;
  while ((bStack_e == 0 && (bVar11))) {
    puVar5 = (uint8_t *)ofs1;
    iVar10 = row1;
    b = uVar14;
    if ((char)(uVar14 >> 0x18) == '\0') {
      b = CONCAT13((char)(uVar14 >> 0x10),(uint3)(uint)uVar14);
      puVar5 = (uint8_t *)ofs2;
      iVar10 = row2;
      ofs2 = ofs1;
      row2 = row1;
    }
    ofs1 = (int)puVar5;
    if ((b & 0x1000000) == 0) {
      if ((b & 0x2000000) == 0) {
        if ((b & 0x4000000) == 0) {
          row1 = iVar10;
          if ((b & 0x8000000) != 0) {
            plVar6 = (long *)(row2 - iVar10);
            iVar8 = (int)plVar6 >> 0xf;
            iVar10 = iVar4 - iVar10 >> 0xf;
            plVar7 = LXMUL_at_(plVar6,CONCAT22(unaff_DI,iVar8),b);
            lVar12 = LDIV_at_((long)CONCAT22(iVar10,plVar7),(long)CONCAT22(iVar8,plVar6));
            ofs1 = ofs1 + (int)lVar12;
            row1 = iVar4;
          }
        }
        else {
          plVar6 = (long *)(ofs2 - ofs1);
          iVar8 = (int)plVar6 >> 0xf;
          iVar9 = (int)puVar3 - ofs1 >> 0xf;
          plVar7 = LXMUL_at_(plVar6,CONCAT22(unaff_DI,iVar8),b);
          lVar12 = LDIV_at_((long)CONCAT22(iVar9,plVar7),(long)CONCAT22(iVar8,plVar6));
          ofs1 = (int)puVar3;
          row1 = iVar10 + (int)lVar12;
        }
      }
      else {
        plVar6 = (long *)(row2 - iVar10);
        iVar8 = (int)plVar6 >> 0xf;
        iVar10 = iVar2 - iVar10 >> 0xf;
        plVar7 = LXMUL_at_(plVar6,CONCAT22(unaff_DI,iVar8),b);
        lVar12 = LDIV_at_((long)CONCAT22(iVar10,plVar7),(long)CONCAT22(iVar8,plVar6));
        ofs1 = (int)(ofs1 + (int)lVar12);
        row1 = iVar2;
      }
    }
    else {
      plVar6 = (long *)(ofs2 - ofs1);
      iVar8 = (int)plVar6 >> 0xf;
      iVar9 = (int)puVar1 - ofs1 >> 0xf;
      plVar7 = LXMUL_at_(plVar6,CONCAT22(unaff_DI,iVar8),b);
      lVar12 = LDIV_at_((long)CONCAT22(iVar9,plVar7),(long)CONCAT22(iVar8,plVar6));
      ofs1 = (int)puVar1;
      row1 = iVar10 + (int)lVar12;
    }
    uVar14 = b & 0xffffff;
    if (ofs1 < (int)puVar1) {
      uVar14 = CONCAT13(1,(int3)b);
    }
    if ((int)puVar3 < ofs1) {
      uVar14 = CONCAT13((char)(uVar14 >> 0x18) + '\x04',(int3)uVar14);
    }
    if (row1 < iVar2) {
      uVar14 = CONCAT13((char)(uVar14 >> 0x18) + '\x02',(int3)uVar14);
    }
    if (iVar4 < row1) {
      uVar14 = CONCAT13((char)(uVar14 >> 0x18) + '\b',(int3)uVar14);
    }
    bStack_e = (byte)(uVar14 >> 0x18);
    bVar15 = (byte)(uVar14 >> 0x10);
    bVar11 = bStack_e != 0 || bVar15 != 0;
    bStack_e = bStack_e & bVar15;
  }
  if (!bVar11) {
    ovr_driver_drawLine((uint8_t *)ofs1,row1,(uint8_t *)ofs2,row2,colour,colour,rect->seg,0,0);
  }
  return;
}


