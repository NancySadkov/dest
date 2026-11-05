/*
 * ovc26.c - recovered from STRONG.EXE
 * memory block: OVC26
 * range: 5d45:0000 - 5d45:0a7f
 * functions: 3
 */
#include "recovered.h"


/* 5d45:0000 */

void __cdecl16far OVC26_5d45_0000(int param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined2 uVar4;
  int *piVar5;
  undefined2 uVar6;
  int *piVar7;
  int *piVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined2 unaff_SS;
  int local_980 [300];
  int local_728 [300];
  int local_4d0 [300];
  int local_278 [300];
  byte bStack_1f;
  int *piStack_1e;
  undefined2 uVar13;
  int *piStack_1a;
  undefined2 uVar14;
  int *piStack_12;
  undefined2 uVar15;
  int *piStack_e;
  int iStack_a;
  int iStack_8;
  
  _fmemset(DAT_2000_d2e8,0,0x6541);
  iVar10 = 0x50 - param_1;
  iVar11 = 0x50 - param_2;
  iStack_a = 1;
  _piStack_1a = (int *)CONCAT22(unaff_SS,local_278);
  _piStack_1e = (int *)CONCAT22(unaff_SS,local_4d0);
  piStack_e = local_728;
  piStack_12 = local_980;
  *(undefined1 *)((int)(void *)DAT_2000_d2e8 + iVar11 + param_2 + (param_1 + iVar10) * 0xa1) = 1;
  *_piStack_1a = param_1;
  *_piStack_1e = param_2;
  bStack_1f = 2;
  uVar15 = unaff_SS;
  while( true ) {
    piVar8 = piStack_e;
    piVar7 = piStack_12;
    piVar5 = _piStack_1a;
    if (0x50 < bStack_1f) {
      return;
    }
    iVar12 = 0;
    iStack_8 = 0;
    while( true ) {
      piVar3 = _piStack_1e;
      piStack_1a = (int *)piVar5;
      uVar14 = (undefined2)((ulong)piVar5 >> 0x10);
      uVar6 = uVar14;
      uVar13 = (undefined2)((ulong)_piStack_1e >> 0x10);
      uVar4 = uVar13;
      if (iStack_a <= iStack_8) break;
      iVar1 = piStack_1a[iStack_8];
      iVar2 = piStack_1e[iStack_8];
      _piStack_1e = piVar3;
      if (((*(char *)((int)(void *)DAT_2000_d2e8 + iVar11 + iVar2 + (iVar1 + iVar10) * 0xa1 + -0xa1)
            == '\0') && (cVar9 = ovr_attact_3f0b_027d(iVar1,iVar2,3,param_3), cVar9 == '\0')) &&
         (iVar12 < 300)) {
        *(byte *)((int)(void *)DAT_2000_d2e8 + iVar11 + iVar2 + (iVar1 + iVar10) * 0xa1 + -0xa1) =
             bStack_1f;
        piStack_e[iVar12] = iVar1 + -1;
        piStack_12[iVar12] = iVar2;
        iVar12 = iVar12 + 1;
      }
      if (((*(char *)((int)(void *)DAT_2000_d2e8 + iVar11 + iVar2 + (iVar1 + iVar10) * 0xa1 + 0xa1)
            == '\0') && (cVar9 = ovr_attact_3f0b_027d(iVar1,iVar2,1,param_3), cVar9 == '\0')) &&
         (iVar12 < 300)) {
        *(byte *)((int)(void *)DAT_2000_d2e8 + iVar11 + iVar2 + (iVar1 + iVar10) * 0xa1 + 0xa1) =
             bStack_1f;
        piStack_e[iVar12] = iVar1 + 1;
        piStack_12[iVar12] = iVar2;
        iVar12 = iVar12 + 1;
      }
      if (((*(char *)((int)(void *)DAT_2000_d2e8 + iVar11 + iVar2 + (iVar1 + iVar10) * 0xa1 + -1) ==
            '\0') && (cVar9 = ovr_attact_3f0b_027d(iVar1,iVar2,0,param_3), cVar9 == '\0')) &&
         (iVar12 < 300)) {
        *(byte *)((int)(void *)DAT_2000_d2e8 + iVar2 + iVar11 + (iVar1 + iVar10) * 0xa1 + -1) =
             bStack_1f;
        piStack_e[iVar12] = iVar1;
        piStack_12[iVar12] = iVar2 + -1;
        iVar12 = iVar12 + 1;
      }
      if (((*(char *)((int)(void *)DAT_2000_d2e8 + iVar11 + iVar2 + (iVar1 + iVar10) * 0xa1 + 1) ==
            '\0') && (cVar9 = ovr_attact_3f0b_027d(iVar1,iVar2,2,param_3), cVar9 == '\0')) &&
         (iVar12 < 300)) {
        *(byte *)((int)(void *)DAT_2000_d2e8 + iVar2 + iVar11 + (iVar1 + iVar10) * 0xa1 + 1) =
             bStack_1f;
        piStack_e[iVar12] = iVar1;
        piStack_12[iVar12] = iVar2 + 1;
        iVar12 = iVar12 + 1;
      }
      iStack_8 = iStack_8 + 1;
    }
    if (iVar12 == 0) break;
    piStack_e = piStack_1a;
    _piStack_1a = (int *)CONCAT22(unaff_SS,piVar8);
    piStack_12 = piStack_1e;
    _piStack_1e = (int *)CONCAT22(uVar15,piVar7);
    bStack_1f = bStack_1f + 1;
    iStack_a = iVar12;
    unaff_SS = uVar6;
    uVar15 = uVar4;
  }
  return;
}



/* 5d45:031f */

uint __cdecl16far OVC26_5d45_031f(int param_1)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  char *pcVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 unaff_SS;
  byte local_6e [80];
  int iStack_1e;
  int iStack_1c;
  int iStack_1a;
  int iStack_18;
  int iStack_16;
  int iStack_14;
  undefined1 uStack_11;
  byte bStack_10;
  byte bStack_f;
  uint uStack_e;
  uint uStack_c;
  undefined4 uStack_a;
  char *pcStack_6;
  
  piVar8 = (int *)(Entities.ofs + param_1 * 0x37);
  uStack_a = (int *)CONCAT22(Entities.seg,piVar8);
  uStack_11 = *(undefined1 *)((int)piVar8 + 0xd);
  if (DAT_2000_d167 - piVar8[0x1a] < 0x19) {
    uVar6 = DAT_2000_d167 - piVar8[0x1a] & 0xff00;
  }
  else {
    DAT_2000_d165 = DAT_2000_d165 + 1;
    OVC26_5d45_0000();
    uVar10 = (undefined2)((ulong)uStack_a >> 0x10);
    piVar8 = (int *)uStack_a;
    iVar4 = piVar8[4] - (*uStack_a + -0x50);
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    if (0xa0 < iVar4) {
      iVar4 = 0xa0;
    }
    iVar5 = piVar8[5] - (piVar8[1] + -0x50);
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    if (0xa0 < iVar5) {
      iVar5 = 0xa0;
    }
    uVar11 = (undefined2)((ulong)DAT_2000_d2e8 >> 0x10);
    pcVar9 = (char *)DAT_2000_d2e8;
    if (pcVar9[iVar5 + iVar4 * 0xa1] == '\0') {
      DAT_2000_d163 = DAT_2000_d163 + 1;
      uStack_c = 0xffff;
      iStack_14 = (*uStack_a + -0x50) - piVar8[4];
      iStack_16 = (piVar8[1] + -0x50) - piVar8[5];
      pcStack_6 = DAT_2000_d2e8;
      for (iVar4 = 0; iVar4 < 0xa1; iVar4 = iVar4 + 1) {
        for (iVar5 = 0; pcVar2 = pcStack_6, iVar5 < 0xa1; iVar5 = iVar5 + 1) {
          pcStack_6 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(pcStack_6) + 2)),(char *)pcStack_6 + 1);
          if ((*pcVar2 != '\0') &&
             (uVar6 = iStack_14 + iVar4 >> 0xf, uVar7 = iStack_16 + iVar5 >> 0xf,
             uStack_e = ((iStack_14 + iVar4 ^ uVar6) - uVar6) +
                        ((iStack_16 + iVar5 ^ uVar7) - uVar7), uStack_e < uStack_c)) {
            iStack_1a = iVar5;
            iStack_18 = iVar4;
            uStack_c = uStack_e;
          }
        }
      }
      iVar5 = iStack_1a;
      iVar4 = iStack_18;
      if (uStack_c == 0xffff) {
        *(undefined1 *)((int)piVar8 + 0x2f) = 0;
        *(undefined1 *)(piVar8 + 0x18) = 0;
        uVar6 = DAT_2000_d167;
        piVar8[0x1a] = DAT_2000_d167;
        return uVar6 & 0xff00;
      }
    }
    if ((iVar4 == 0x50) && (iVar5 == 0x50)) {
      *(undefined1 *)((int)piVar8 + 0x2f) = 0;
      *(undefined1 *)(piVar8 + 0x18) = 0;
      uVar6 = DAT_2000_d167;
      piVar8[0x1a] = DAT_2000_d167;
      uVar6 = uVar6 & 0xff00;
    }
    else {
      bStack_f = 0;
      while (pcVar9[iVar5 + iVar4 * 0xa1] != '\x01') {
        bStack_10 = 0;
        while ((bStack_10 < 4 &&
               ((((SCARRY2(iVar4,(int)*(char *)(bStack_10 + 0x885)) !=
                   iVar4 + *(char *)(bStack_10 + 0x885) < 0 ||
                  (0xa0 < iVar4 + *(char *)(bStack_10 + 0x885))) ||
                 (SCARRY2(iVar5,(int)*(char *)(bStack_10 + 0x889)) !=
                  iVar5 + *(char *)(bStack_10 + 0x889) < 0)) ||
                ((0xa0 < iVar5 + *(char *)(bStack_10 + 0x889) ||
                 ((byte)pcVar9[(int)*(char *)(bStack_10 + 0x889) +
                               iVar5 + (iVar4 + *(char *)(bStack_10 + 0x885)) * 0xa1] + 1 !=
                  (uint)(byte)pcVar9[iVar5 + iVar4 * 0xa1]))))))) {
          bStack_10 = bStack_10 + 1;
        }
        if (3 < bStack_10) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x19);
        }
        local_6e[bStack_f] = bStack_10 ^ 2;
        bStack_f = bStack_f + 1;
        iVar4 = iVar4 + *(char *)(bStack_10 + 0x885);
        iVar5 = iVar5 + *(char *)(bStack_10 + 0x889);
      }
      if (bStack_f == 0) {
        *(undefined1 *)((int)(int *)uStack_a + 0x2f) = 0;
        *(undefined1 *)((int *)uStack_a + 0x18) = 0;
        uVar6 = DAT_2000_d167;
        ((int *)uStack_a)[0x1a] = DAT_2000_d167;
        uVar6 = uVar6 & 0xff00;
      }
      else {
        _fmemset((void *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_a) + 2)),(void *)((int)(int *)uStack_a + 0x1b)),0,0x14);
        uVar10 = (undefined2)((ulong)uStack_a >> 0x10);
        piVar8 = (int *)uStack_a;
        *(byte *)(piVar8 + 0x18) = bStack_f;
        iStack_1c = 0;
        iVar4 = bStack_f - 1;
        for (iStack_1e = iVar4; -1 < iStack_1e; iStack_1e = iStack_1e + -1) {
          bVar3 = local_6e[iStack_1e] << (((byte)iStack_1c & 3) << 1);
          iVar4 = CONCAT11((char)((uint)local_6e >> 8),bVar3);
          pbVar1 = (byte *)((int)piVar8 + (iStack_1c >> 2) + 0x1b);
          *pbVar1 = *pbVar1 | bVar3;
          iStack_1c = iStack_1c + 1;
        }
        *(undefined1 *)((int)piVar8 + 0x2f) = 0;
        uVar6 = CONCAT11((char)((uint)iVar4 >> 8),1);
      }
    }
  }
  return uVar6;
}



/* 5d45:06f0 */

undefined2 __cdecl16far
OVC26_5d45_06f0(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 param_5)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  byte bVar5;
  undefined2 uVar6;
  int iVar7;
  uint16_t uVar8;
  uint16_t uVar9;
  int iStack_c;
  undefined1 uStack_7;
  
  uVar9 = Entities.seg;
  uVar8 = Entities.ofs;
  if (*(char *)((int)(char **)GMenuStrings +
               (uint)*(byte *)(uVar8 + param_1 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0') {
    uVar6 = 0;
  }
  else if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 +
                     (uint)*(byte *)(uVar8 + param_1 * 0x37 + 0xd) * 0x95) & 0x80) == 0) {
    if (*(char *)(uVar8 + param_1 * 0x37 + 0x18) == '\0') {
      iVar2 = *(int *)(uVar8 + param_1 * 0x37);
      iVar3 = *(int *)(uVar8 + param_1 * 0x37 + 2);
      uVar6 = *(undefined2 *)(uVar8 + param_1 * 0x37 + 8);
      uVar4 = *(undefined2 *)(uVar8 + param_1 * 0x37 + 10);
      iVar7 = ovr_OVC07_32c9_0026(*(int *)(uVar8 + param_1 * 0x37 + 8) - iVar2);
      iStack_c = ovr_OVC07_32c9_0026(*(int *)(Entities.ofs + param_1 * 0x37 + 10) - iVar3);
      if ((iVar7 != 0) &&
         ((*(uint *)(iVar3 * 0x128 + (int)DAT_2000_cb09 + (iVar2 + iVar7) * 2 + 0x128) & 3) == 0)) {
        iVar7 = 0;
      }
      if ((iStack_c != 0) &&
         ((*(uint *)((iVar3 + iStack_c) * 0x128 + (int)DAT_2000_cb09 + iVar2 * 2 + 0x128) & 3) == 0)
         ) {
        iStack_c = 0;
      }
      if ((iVar7 == 0) && (iStack_c == 0)) {
        uVar6 = 0;
      }
      else {
        if ((iVar7 != 0) && (iVar7 != 0)) {
          uVar8 = ovr_randBelow(2);
          if ((uVar8 & 0xff) == 0) {
            iVar7 = 0;
          }
          else {
            iStack_c = 0;
          }
        }
        if (iVar7 == 0) {
          uStack_7 = 0xa1;
        }
        else {
          uStack_7 = 0xa0;
        }
        bVar5 = ovr_OVC45_77eb_0121(iVar2 + iVar7,iVar3 + iStack_c);
        if ((*(byte *)((uint)bVar5 * 0x27 + 0x11e) & 0xc) == 0) {
          ovr_OVC23_55fe_1e87(CONCAT11((char)((uint)(iVar2 + iVar7) >> 8),uStack_7),iVar2 + iVar7,
                              iVar3 + iStack_c,param_2,param_3,
                              CONCAT11((char)((uint)(param_1 * 0x37) >> 8),
                                       *(undefined1 *)(Entities.ofs + param_1 * 0x37 + 0x1a)));
          ovr_attact_3f0b_0ade(param_1,iVar2 + iVar7,iVar3 + iStack_c,param_4,param_5);
          *(int *)(Entities.ofs + param_1 * 0x37 + 4) = iVar2 + iVar7;
          *(int *)(Entities.ofs + param_1 * 0x37 + 6) = iVar3 + iStack_c;
          pbVar1 = (byte *)(Entities.ofs + param_1 * 0x37 + 0x33);
          *pbVar1 = *pbVar1 | 2;
          pbVar1 = (byte *)(Entities.ofs + param_1 * 0x37 + 0x33);
          *pbVar1 = *pbVar1 & 0xfa;
          ovr_OVC25_5b66_0530(CONCAT11((char)((uint)(param_1 * 0x37) >> 8),
                                       *(undefined1 *)(Entities.ofs + param_1 * 0x37 + 0x1a)),1,
                              uVar6,uVar4);
          uVar6 = 1;
        }
        else {
          uVar6 = 0;
        }
      }
    }
    else {
      uVar6 = 0;
    }
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}


