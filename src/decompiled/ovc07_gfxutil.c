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
  int in_stack_00000004;
  
  if (in_stack_00000004 < 0) {
    uVar1 = 0xffff;
  }
  else if (in_stack_00000004 < 1) {
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
  int iVar8;
  int iVar9;
  int in_stack_00000004;
  int iStack_18;
  int iStack_12;
  int iStack_c;
  int iStack_a;
  int iStack_6;
  
  iVar5 = x2;
  iVar9 = in_stack_00000004;
  iVar1 = *(int *)CONCAT22((brect_t *)rect,rectSeg);
  iVar2 = *(int *)(rectSeg + 2);
  iVar3 = *(int *)(rectSeg + 4);
  iVar4 = *(int *)(rectSeg + 6);
  if (((((((in_stack_00000004 < iVar1) || (iVar3 < in_stack_00000004)) || (x1 < iVar2)) ||
        ((iVar4 < x1 || (y1 < iVar1)))) || ((iVar3 < y1 || ((x2 < iVar2 || (iVar4 < x2)))))) ||
      (y2 < iVar1)) || (((iVar3 < y2 || (x3 < iVar2)) || (iVar4 < x3)))) {
    if (x2 < x1) {
      x2 = x1;
      in_stack_00000004 = y1;
      y1 = iVar9;
      x1 = iVar5;
    }
    iVar5 = y1;
    iVar9 = in_stack_00000004;
    iVar8 = x3;
    if (x3 < x1) {
      in_stack_00000004 = y2;
      y2 = iVar9;
      iVar8 = x1;
      x1 = x3;
    }
    iVar9 = iVar8;
    if (iVar8 < x2) {
      y1 = y2;
      y2 = iVar5;
      iVar9 = x2;
      x2 = iVar8;
    }
    if ((((x1 <= iVar4) && (iVar2 <= iVar9)) &&
        ((iVar1 <= in_stack_00000004 || ((iVar1 <= y1 || (iVar1 <= y2)))))) &&
       ((in_stack_00000004 <= iVar3 || ((y1 <= iVar3 || (y2 <= iVar3)))))) {
      if (199 < x1) {
        printf("y1 %d yn %d y3 %d yx %d ");
        ovr_biosReadKey();
      }
      if (x1 != iVar9) {
        uVar6 = (y2 - in_stack_00000004) % (iVar9 - x1);
        uVar7 = (int)uVar6 >> 0xf;
        iStack_18 = (uVar6 ^ uVar7) - uVar7;
        ovc07_signum();
        iStack_a = iVar9 - x1 >> 1;
      }
      iStack_6 = x2 - x1 >> 1;
      ovc07_signum();
      iStack_c = x1;
      if (x1 == x2) {
        iStack_12 = 0;
      }
      else {
        uVar6 = (y1 - in_stack_00000004) % (x2 - x1);
        uVar7 = (int)uVar6 >> 0xf;
        iStack_12 = (uVar6 ^ uVar7) - uVar7;
      }
      for (; iStack_c < x2; iStack_c = iStack_c + 1) {
        if ((iVar2 <= iStack_c) && (iStack_c <= iVar4)) {
          ovr_driver_fillSpan();
        }
        iStack_6 = iStack_6 + iStack_12;
        if (x2 - x1 <= iStack_6) {
          iStack_6 = iStack_6 - (x2 - x1);
        }
        iStack_a = iStack_a + iStack_18;
        if (iVar9 - x1 <= iStack_a) {
          iStack_a = iStack_a - (iVar9 - x1);
        }
      }
      iStack_6 = iVar9 - x2 >> 1;
      ovc07_signum();
      if (x2 == iVar9) {
        iStack_12 = 0;
      }
      else {
        uVar6 = (y2 - y1) % (iVar9 - x2);
        uVar7 = (int)uVar6 >> 0xf;
        iStack_12 = (uVar6 ^ uVar7) - uVar7;
      }
      for (iStack_c = x2; iStack_c <= iVar9; iStack_c = iStack_c + 1) {
        if ((iVar2 <= iStack_c) && (iStack_c <= iVar4)) {
          ovr_driver_fillSpan();
        }
        iStack_6 = iStack_6 + iStack_12;
        if (iVar9 - x2 <= iStack_6) {
          iStack_6 = iStack_6 - (iVar9 - x2);
        }
        iStack_a = iStack_a + iStack_18;
        if (iVar9 - x1 <= iStack_a) {
          iStack_a = iStack_a - (iVar9 - x1);
        }
      }
    }
  }
  else {
    ovr_driver_compute5(x1,(byte)y1,x2,(byte)y2,x3,(byte)y3,in_stack_00000004,
                        *(undefined2 *)(rectSeg + 8));
  }
  return;
}



/* 32c9:03c4 */

/* [R4] calls ovr_driver_fillRect */

void __cdecl16far ovc07_usesFillRect(int x1,int y1,int x2,int y2,uint16_t colour,brect_t *rect,...)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint16_t unaff_DI;
  int in_stack_00000004;
  
  iVar2 = x2;
  iVar1 = y1;
  iVar3 = in_stack_00000004;
  if (y1 < in_stack_00000004) {
    y1 = in_stack_00000004;
    iVar3 = iVar1;
  }
  if (x2 < x1) {
    x2 = x1;
    x1 = iVar2;
  }
  if (iVar3 < *(int *)CONCAT22((brect_t *)rect,colour)) {
    iVar3 = *(int *)CONCAT22((brect_t *)rect,colour);
  }
  if (x1 < *(int *)(colour + 2)) {
    x1 = *(uint *)(colour + 2);
  }
  if (*(int *)(colour + 4) < y1) {
    y1 = *(int *)(colour + 4);
  }
  if (*(int *)(colour + 6) < x2) {
    x2 = *(int *)(colour + 6);
  }
  if ((iVar3 <= y1) && (x1 <= x2)) {
    ovr_driver_fillRect(x1,y1,x2,y2,(uint8_t)*(undefined2 *)(colour + 8),unaff_DI,iVar3);
  }
  return;
}



/* 32c9:0466 */

/* [R4] calls LDIV_at_ */

void __cdecl16far
ovc07_usesLDIV_at_(int ofs1,int row1,int ofs2,int row2,uint8_t colour,brect_t *rect,...)

{
  int iVar1;
  uint8_t *puVar2;
  int iVar3;
  uint8_t *puVar4;
  long *plVar5;
  int iVar6;
  int iVar7;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  uint8_t *puVar8;
  long lVar9;
  int in_stack_00000004;
  undefined1 uStack000f;
  ulong uVar10;
  long a;
  undefined2 uVar11;
  byte bVar13;
  uint uVar12;
  char cVar14;
  
  a = CONCAT22(unaff_SI,unaff_DI);
  iVar1 = *(int *)CONCAT22((brect_t *)rect,colour);
  puVar2 = (uint8_t *)colour[1];
  iVar3 = colour[2];
  puVar4 = (uint8_t *)colour[3];
  lVar9 = 0;
  if (in_stack_00000004 < iVar1) {
    lVar9 = 0x100;
  }
  if (iVar3 < in_stack_00000004) {
    lVar9 = (ulong)(byte)((char)((ulong)lVar9 >> 8) + 4) << 8;
  }
  if (ofs1 < (int)puVar2) {
    lVar9 = (ulong)(byte)((char)((ulong)lVar9 >> 8) + 2) << 8;
  }
  if ((int)puVar4 < ofs1) {
    lVar9 = (ulong)(byte)((char)((ulong)lVar9 >> 8) + 8) << 8;
  }
  if (row1 < iVar1) {
    lVar9 = CONCAT31((int3)((ulong)lVar9 >> 8),1);
  }
  if (iVar3 < row1) {
    lVar9 = CONCAT31((int3)((ulong)lVar9 >> 8),(char)lVar9 + '\x04');
  }
  if (ofs2 < (int)puVar2) {
    lVar9 = CONCAT31((int3)((ulong)lVar9 >> 8),(char)lVar9 + '\x02');
  }
  uVar11 = (undefined2)lVar9;
  if ((int)puVar4 < ofs2) {
    uVar11 = (undefined2)CONCAT31((int3)((ulong)lVar9 >> 8),(char)lVar9 + '\b');
  }
  bVar13 = (byte)((uint)uVar11 >> 8);
  uVar10 = CONCAT13('\x01' - (bVar13 != 0 || (byte)uVar11 != 0),
                    CONCAT12(bVar13 & (byte)uVar11,uVar11));
  iVar7 = in_stack_00000004;
  while ((cVar14 = (char)(uVar10 >> 0x18), (char)(uVar10 >> 0x10) == '\0' && (cVar14 == '\0'))) {
    iVar6 = iVar7;
    puVar8 = (uint8_t *)ofs1;
    if ((char)(uVar10 >> 8) == '\0') {
      uVar10 = (ulong)CONCAT21((int)(uVar10 >> 0x10),(char)uVar10) << 8;
      iVar6 = row1;
      puVar8 = (uint8_t *)ofs2;
      row1 = iVar7;
      ofs2 = ofs1;
    }
    iVar7 = iVar6;
    if ((uVar10 & 0x100) == 0) {
      if ((uVar10 & 0x200) == 0) {
        if ((uVar10 & 0x400) == 0) {
          ofs1 = (int)puVar8;
          if ((uVar10 & 0x800) != 0) {
            lVar9 = (long)(ofs2 - (int)puVar8);
            iVar6 = (int)puVar4 - (int)puVar8 >> 0xf;
            plVar5 = LXMUL_at_((long *)(ofs2 - (int)puVar8 >> 0xf),a,uVar10);
            lVar9 = LDIV_at_((long)CONCAT22(iVar6,plVar5),lVar9);
            iVar7 = iVar7 + (int)lVar9;
            ofs1 = (int)puVar4;
          }
        }
        else {
          lVar9 = (long)(row1 - iVar7);
          iVar6 = iVar3 - iVar7 >> 0xf;
          plVar5 = LXMUL_at_((long *)(row1 - iVar7 >> 0xf),a,uVar10);
          lVar9 = LDIV_at_((long)CONCAT22(iVar6,plVar5),lVar9);
          iVar7 = iVar3;
          ofs1 = (int)(puVar8 + (int)lVar9);
        }
      }
      else {
        lVar9 = (long)(ofs2 - (int)puVar8);
        iVar6 = (int)puVar2 - (int)puVar8 >> 0xf;
        plVar5 = LXMUL_at_((long *)(ofs2 - (int)puVar8 >> 0xf),a,uVar10);
        lVar9 = LDIV_at_((long)CONCAT22(iVar6,plVar5),lVar9);
        iVar7 = iVar7 + (int)lVar9;
        ofs1 = (int)puVar2;
      }
    }
    else {
      lVar9 = (long)(row1 - iVar7);
      iVar6 = iVar1 - iVar7 >> 0xf;
      plVar5 = LXMUL_at_((long *)(row1 - iVar7 >> 0xf),a,uVar10);
      lVar9 = LDIV_at_((long)CONCAT22(iVar6,plVar5),lVar9);
      iVar7 = iVar1;
      ofs1 = (int)(puVar8 + (int)lVar9);
    }
    uVar12 = (uint)uVar10 & 0xff;
    if (iVar7 < iVar1) {
      uVar12 = CONCAT11(1,(char)uVar10);
    }
    if (iVar3 < iVar7) {
      uVar12 = CONCAT11((char)(uVar12 >> 8) + '\x04',(char)uVar12);
    }
    if (ofs1 < (int)puVar2) {
      uVar12 = CONCAT11((char)(uVar12 >> 8) + '\x02',(char)uVar12);
    }
    if ((int)puVar4 < ofs1) {
      uVar12 = CONCAT11((char)(uVar12 >> 8) + '\b',(char)uVar12);
    }
    bVar13 = (byte)(uVar12 >> 8);
    uVar10 = CONCAT13('\x01' - (bVar13 != 0 || (byte)uVar12 != 0),
                      CONCAT12(bVar13 & (byte)uVar12,uVar12));
  }
  if (cVar14 != '\0') {
    uVar10 = CONCAT22(*(undefined2 *)(CONCAT11(uStack000f,colour) + 8),row2) & 0xffff00ff;
    ovr_driver_drawLine((uint8_t *)ofs1,row1,(uint8_t *)ofs2,(int)uVar10,(uint8_t)(uVar10 >> 0x10),
                        iVar7);
  }
  return;
}


