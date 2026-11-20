/*
 * ovc07.c - recovered from STRONG.EXE
 * memory block: OVC07
 * range: 32c9:0000 - 32c9:06ef
 * functions: 5
 */
#include "recovered.h"


/* 32c9:0000 */

/* Swaps the two 16-bit values it is given. */

void __cdecl16far ovc07_swapWords(uint16_t *wordA,uint16_t *wordB)

{
  uint16_t uVar1;
  uint16_t *in_stack_00000008;
  
  uVar1 = *_wordA;
  *_wordA = *in_stack_00000008;
  *in_stack_00000008 = uVar1;
  return;
}



/* 32c9:0026 */

/* Returns the sign of its argument (-1, 0 or 1). */

undefined2 __cdecl16far ovc07_signum(int value)

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
ovc07_usesBiosReadKey(int x1,int y1,int x2,int y2,int x3,int y3,uint16_t rectSeg,brect_t *rect)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *in_stack_00000012;
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
  iVar5 = *(int *)CONCAT22((brect_t *)rect,in_stack_00000012);
  iVar1 = in_stack_00000012[1];
  iVar2 = in_stack_00000012[2];
  iVar3 = in_stack_00000012[3];
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
          ovr_driver_fillSpan(iStack_4,iStack_8,(byte)iStack_c,(uint8_t)rectSeg,in_stack_00000012);
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
          ovr_driver_fillSpan(iStack_4,iStack_8,(byte)iStack_c,(uint8_t)rectSeg,in_stack_00000012);
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
    ovr_driver_compute5(x1,(byte)y1,x2,(byte)y2,x3,(byte)y3);
  }
  return;
}



/* 32c9:03c4 */

/* [R4] calls ovr_driver_fillRect */

void __cdecl16far ovc07_usesFillRect(int x1,int y1,int x2,int y2,uint16_t colour,brect_t *rect)

{
  int iVar1;
  int iVar2;
  uint *in_stack_0000000e;
  
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
  if (x1 < (int)*(uint *)CONCAT22((brect_t *)rect,in_stack_0000000e)) {
    x1 = *(uint *)CONCAT22((brect_t *)rect,in_stack_0000000e);
  }
  if (y1 < (int)in_stack_0000000e[1]) {
    y1 = in_stack_0000000e[1];
  }
  if ((int)in_stack_0000000e[2] < x2) {
    x2 = in_stack_0000000e[2];
  }
  if ((int)in_stack_0000000e[3] < y2) {
    y2 = in_stack_0000000e[3];
  }
  if ((x1 <= x2) && (y1 <= y2)) {
    ovr_driver_fillRect(x1,y1,x2,y2,(uint8_t)colour,in_stack_0000000e[4]);
  }
  return;
}



/* 32c9:0466 */

/* [R4] calls LDIV_at_ */

void __cdecl16far
ovc07_usesLDIV_at_(int ofs1,int row1,int ofs2,int row2,uint8_t colour,brect_t *rect)

{
  uint8_t *puVar1;
  int iVar2;
  uint8_t *puVar3;
  int iVar4;
  uint8_t *puVar5;
  long *plVar6;
  int iVar7;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  int iVar8;
  long lVar9;
  int *in_stack_0000000e;
  long a;
  undefined2 uVar10;
  uint uVar11;
  byte bVar12;
  ulong b;
  char cVar13;
  
  a = CONCAT22(unaff_SI,unaff_DI);
  puVar1 = *(uint8_t **)CONCAT22((brect_t *)rect,in_stack_0000000e);
  iVar2 = in_stack_0000000e[1];
  puVar3 = (uint8_t *)in_stack_0000000e[2];
  iVar4 = in_stack_0000000e[3];
  lVar9 = 0;
  if (ofs1 < (int)puVar1) {
    lVar9 = 0x100;
  }
  if ((int)puVar3 < ofs1) {
    lVar9 = (ulong)(byte)((char)((ulong)lVar9 >> 8) + 4) << 8;
  }
  if (row1 < iVar2) {
    lVar9 = (ulong)(byte)((char)((ulong)lVar9 >> 8) + 2) << 8;
  }
  if (iVar4 < row1) {
    lVar9 = (ulong)(byte)((char)((ulong)lVar9 >> 8) + 8) << 8;
  }
  if (ofs2 < (int)puVar1) {
    lVar9 = CONCAT31((int3)((ulong)lVar9 >> 8),1);
  }
  if ((int)puVar3 < ofs2) {
    lVar9 = CONCAT31((int3)((ulong)lVar9 >> 8),(char)lVar9 + '\x04');
  }
  if (row2 < iVar2) {
    lVar9 = CONCAT31((int3)((ulong)lVar9 >> 8),(char)lVar9 + '\x02');
  }
  uVar10 = (undefined2)lVar9;
  if (iVar4 < row2) {
    uVar10 = (undefined2)CONCAT31((int3)((ulong)lVar9 >> 8),(char)lVar9 + '\b');
  }
  bVar12 = (byte)((uint)uVar10 >> 8);
  b = CONCAT13('\x01' - (bVar12 != 0 || (byte)uVar10 != 0),CONCAT12(bVar12 & (byte)uVar10,uVar10));
  while ((cVar13 = (char)(b >> 0x18), (char)(b >> 0x10) == '\0' && (cVar13 == '\0'))) {
    puVar5 = (uint8_t *)ofs1;
    iVar8 = row1;
    if ((char)(b >> 8) == '\0') {
      b = (ulong)CONCAT21((int)(b >> 0x10),(char)b) << 8;
      puVar5 = (uint8_t *)ofs2;
      iVar8 = row2;
      ofs2 = ofs1;
      row2 = row1;
    }
    ofs1 = (int)puVar5;
    if ((b & 0x100) == 0) {
      if ((b & 0x200) == 0) {
        if ((b & 0x400) == 0) {
          row1 = iVar8;
          if ((b & 0x800) != 0) {
            lVar9 = (long)(row2 - iVar8);
            iVar7 = iVar4 - iVar8 >> 0xf;
            plVar6 = LXMUL_at_((long *)(row2 - iVar8),a,b);
            lVar9 = LDIV_at_((long)CONCAT22(iVar7,plVar6),lVar9);
            ofs1 = ofs1 + (int)lVar9;
            row1 = iVar4;
          }
        }
        else {
          lVar9 = (long)(ofs2 - ofs1);
          iVar7 = (int)puVar3 - ofs1 >> 0xf;
          plVar6 = LXMUL_at_((long *)(ofs2 - ofs1),a,b);
          lVar9 = LDIV_at_((long)CONCAT22(iVar7,plVar6),lVar9);
          ofs1 = (int)puVar3;
          row1 = iVar8 + (int)lVar9;
        }
      }
      else {
        lVar9 = (long)(row2 - iVar8);
        iVar7 = iVar2 - iVar8 >> 0xf;
        plVar6 = LXMUL_at_((long *)(row2 - iVar8),a,b);
        lVar9 = LDIV_at_((long)CONCAT22(iVar7,plVar6),lVar9);
        ofs1 = (int)(ofs1 + (int)lVar9);
        row1 = iVar2;
      }
    }
    else {
      lVar9 = (long)(ofs2 - ofs1);
      iVar7 = (int)puVar1 - ofs1 >> 0xf;
      plVar6 = LXMUL_at_((long *)(ofs2 - ofs1),a,b);
      lVar9 = LDIV_at_((long)CONCAT22(iVar7,plVar6),lVar9);
      ofs1 = (int)puVar1;
      row1 = iVar8 + (int)lVar9;
    }
    uVar11 = (uint)b & 0xff;
    if (ofs1 < (int)puVar1) {
      uVar11 = CONCAT11(1,(char)b);
    }
    if ((int)puVar3 < ofs1) {
      uVar11 = CONCAT11((char)(uVar11 >> 8) + '\x04',(char)uVar11);
    }
    if (row1 < iVar2) {
      uVar11 = CONCAT11((char)(uVar11 >> 8) + '\x02',(char)uVar11);
    }
    if (iVar4 < row1) {
      uVar11 = CONCAT11((char)(uVar11 >> 8) + '\b',(char)uVar11);
    }
    bVar12 = (byte)(uVar11 >> 8);
    b = CONCAT13('\x01' - (bVar12 != 0 || (byte)uVar11 != 0),CONCAT12(bVar12 & (byte)uVar11,uVar11))
    ;
  }
  if (cVar13 != '\0') {
    ovr_driver_drawLine((uint8_t *)ofs1,row1,(uint8_t *)ofs2,row2,colour);
  }
  return;
}


