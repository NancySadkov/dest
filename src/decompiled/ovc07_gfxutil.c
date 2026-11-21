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
  undefined2 uVar1;
  undefined2 *in_stack_00000004;
  
  uVar1 = *(undefined2 *)CONCAT22((uint16_t *)wordA,in_stack_00000004);
  *(undefined2 *)CONCAT22((uint16_t *)wordA,in_stack_00000004) =
       *(undefined2 *)CONCAT22((uint16_t *)wordB,(*(uint16_t *)((uint8_t *)&(wordA) + 2)));
  *(undefined2 *)CONCAT22((uint16_t *)wordB,(*(uint16_t *)((uint8_t *)&(wordA) + 2))) = uVar1;
  return;
}



/* 32c9:0026 */

/* Returns the sign of its argument (-1, 0 or 1). */

undefined2 __cdecl16far ovc07_signum(int value,...)

{
  undefined2 uVar1;
  
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
ovc07_usesBiosReadKey(int x1,int y1,int x2,int y2,int x3,int y3,uint16_t rectSeg,brect_t *rect,...)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  brect_t *rect_00;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  int iStack_1a;
  int iStack_18;
  int iStack_16;
  int iStack_12;
  int iStack_10;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  iVar4 = y2;
  iVar9 = x1;
  iVar5 = rect->x;
  uVar10 = (undefined2)((ulong)rect >> 0x10);
  rect_00 = (brect_t *)rect;
  iVar1 = rect_00->y;
  iVar2 = rect_00->w;
  iVar3 = rect_00->h;
  if (((((((x1 < iVar5) || (iVar2 < x1)) || (y1 < iVar1)) || ((iVar3 < y1 || (x2 < iVar5)))) ||
       ((iVar2 < x2 || ((y2 < iVar1 || (iVar3 < y2)))))) || (x3 < iVar5)) ||
     (((iVar2 < x3 || (y3 < iVar1)) || (iVar3 < y3)))) {
    if (y2 < y1) {
      y2 = y1;
      x1 = x2;
      x2 = iVar9;
      y1 = iVar4;
    }
    iVar4 = x2;
    iVar9 = x1;
    iVar8 = y3;
    if (y3 < y1) {
      x1 = x3;
      x3 = iVar9;
      iVar8 = y1;
      y1 = y3;
    }
    iVar9 = iVar8;
    if (iVar8 < y2) {
      x2 = x3;
      x3 = iVar4;
      iVar9 = y2;
      y2 = iVar8;
    }
    if ((((y1 <= iVar3) && (iVar1 <= iVar9)) && ((iVar5 <= x1 || ((iVar5 <= x2 || (iVar5 <= x3))))))
       && ((x1 <= iVar2 || ((x2 <= iVar2 || (x3 <= iVar2)))))) {
      if (199 < y1) {
        printf("y1 %d yn %d y3 %d yx %d ");
        ovr_biosReadKey();
      }
      iStack_8 = x1;
      if (y1 != iVar9) {
        iStack_16 = (x3 - x1) / (iVar9 - y1);
        uVar6 = (x3 - x1) % (iVar9 - y1);
        uVar7 = (int)uVar6 >> 0xf;
        iStack_18 = (uVar6 ^ uVar7) - uVar7;
        iStack_1a = ovc07_signum(x3 - x1);
        iStack_a = iVar9 - y1 >> 1;
      }
      iStack_4 = x1;
      iStack_6 = y2 - y1 >> 1;
      iVar5 = ovc07_signum(x2 - x1);
      iStack_c = y1;
      if (y1 == y2) {
        iStack_10 = 0;
        iStack_12 = 0;
      }
      else {
        iStack_10 = (x2 - x1) / (y2 - y1);
        uVar6 = (x2 - x1) % (y2 - y1);
        uVar7 = (int)uVar6 >> 0xf;
        iStack_12 = (uVar6 ^ uVar7) - uVar7;
      }
      for (; iStack_c < y2; iStack_c = iStack_c + 1) {
        if ((iVar1 <= iStack_c) && (iStack_c <= iVar3)) {
          ovr_driver_fillSpan(iStack_4,iStack_8,(byte)iStack_c,(uint8_t)rectSeg,&rect_00->x,uVar10);
        }
        iStack_4 = iStack_4 + iStack_10;
        iStack_6 = iStack_6 + iStack_12;
        if (y2 - y1 <= iStack_6) {
          iStack_4 = iStack_4 + iVar5;
          iStack_6 = iStack_6 - (y2 - y1);
        }
        iStack_8 = iStack_8 + iStack_16;
        iStack_a = iStack_a + iStack_18;
        if (iVar9 - y1 <= iStack_a) {
          iStack_8 = iStack_8 + iStack_1a;
          iStack_a = iStack_a - (iVar9 - y1);
        }
      }
      iStack_4 = x2;
      iStack_6 = iVar9 - y2 >> 1;
      iVar5 = ovc07_signum(x3 - x2);
      if (y2 == iVar9) {
        iStack_10 = 0;
        iStack_12 = 0;
      }
      else {
        iStack_10 = (x3 - x2) / (iVar9 - y2);
        uVar6 = (x3 - x2) % (iVar9 - y2);
        uVar7 = (int)uVar6 >> 0xf;
        iStack_12 = (uVar6 ^ uVar7) - uVar7;
      }
      for (iStack_c = y2; iStack_c <= iVar9; iStack_c = iStack_c + 1) {
        if ((iVar1 <= iStack_c) && (iStack_c <= iVar3)) {
          ovr_driver_fillSpan(iStack_4,iStack_8,(byte)iStack_c,(uint8_t)rectSeg,&rect_00->x,uVar10);
        }
        iStack_4 = iStack_4 + iStack_10;
        iStack_6 = iStack_6 + iStack_12;
        if (iVar9 - y2 <= iStack_6) {
          iStack_4 = iStack_4 + iVar5;
          iStack_6 = iStack_6 - (iVar9 - y2);
        }
        iStack_8 = iStack_8 + iStack_16;
        iStack_a = iStack_a + iStack_18;
        if (iVar9 - y1 <= iStack_a) {
          iStack_8 = iStack_8 + iStack_1a;
          iStack_a = iStack_a - (iVar9 - y1);
        }
      }
    }
  }
  else {
    ovr_driver_compute5(x1,(byte)y1,x2,(byte)y2,x3,(byte)y3,rectSeg,rect_00->seg);
  }
  return;
}



/* 32c9:03c4 */

/* [R4] calls ovr_driver_fillRect */

void __cdecl16far ovc07_usesFillRect(int x1,int y1,int x2,int y2,uint16_t colour,brect_t *rect,...)

{
  int iVar1;
  int iVar2;
  undefined2 in_stack_00000010;
  
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
    ovr_driver_fillRect(x1,y1,x2,y2,(uint8_t)colour,rect->seg);
  }
  return;
}



/* 32c9:0466 */

/* [R4] calls LDIV_at_ */

void __cdecl16far
ovc07_usesLDIV_at_(int ofs1,int row1,int ofs2,int row2,uint8_t colour,brect_t *rect,...)

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
  undefined2 unaff_DI;
  bool bVar11;
  long lVar12;
  undefined2 in_stack_00000010;
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
    ovr_driver_drawLine((uint8_t *)ofs1,row1,(uint8_t *)ofs2,row2,colour,colour,rect->seg);
  }
  return;
}


