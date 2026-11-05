/*
 * ovc45.c - recovered from STRONG.EXE
 * memory block: OVC45
 * range: 77eb:0000 - 77eb:26bf
 * functions: 29
 */
#include "recovered.h"


/* 77eb:0121 */

undefined1 __cdecl16far OVC45_77eb_0121(int param_1,int param_2)

{
  undefined1 uVar1;
  
  if ((((param_1 < 0x94) && (-1 < param_1)) && (param_2 < 0x3c)) && (-1 < param_2)) {
    uVar1 = *(undefined1 *)
             ((int)DAT_2000_ca95 + *(int *)((int)DAT_2000_cb0d + param_1 * 0x78 + param_2 * 2) * 9);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 77eb:0179 */

undefined2 __cdecl16far OVC45_77eb_0179(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if ((((param_1 < 0x94) && (-1 < param_1)) && (param_2 < 0x3c)) && (-1 < param_2)) {
    uVar1 = *(undefined2 *)((int)DAT_2000_cb0d + param_1 * 0x78 + param_2 * 2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 77eb:01bb */

uint __cdecl16far OVC45_77eb_01bb(int param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint16_t uVar2;
  uint uVar3;
  uint16_t uVar4;
  byte bStack_3;
  
  bStack_3 = 0xff;
  for (uVar3 = 0; uVar3 < EntityCount; uVar3 = uVar3 + 1) {
    iVar1 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar3 * 0x37));
    if (iVar1 == param_2) {
      uVar4 = Entities.seg;
      uVar2 = Entities.ofs;
      if ((((*(int *)(uVar2 + uVar3 * 0x37 + 2) == param_3) &&
           (*(char *)((int)(char **)GMenuStrings +
                     (uint)*(byte *)(uVar2 + uVar3 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0')) &&
          (param_1 < (int)(uint)*(byte *)(uVar2 + uVar3 * 0x37 + 0x1a))) &&
         (*(byte *)(uVar2 + uVar3 * 0x37 + 0x1a) < bStack_3)) {
        bStack_3 = *(byte *)(uVar2 + uVar3 * 0x37 + 0x1a);
        *param_4 = uVar3;
      }
    }
  }
  if (bStack_3 == 0xff) {
    uVar3 = 0xffff;
  }
  else {
    uVar3 = (uint)bStack_3;
  }
  return uVar3;
}



/* 77eb:02c1 */

char * __cdecl16far
OVC45_77eb_02c1(undefined2 param_1,int param_2,uint *param_3,undefined1 *param_4,char param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint16_t uVar4;
  uint uVar5;
  uint uVar6;
  uint16_t uVar7;
  uint uStack_6;
  uint uStack_4;
  
  *param_4 = 0;
  iVar1 = ovr_OVC23_55fe_3450(param_1);
  *param_3 = 0xffff;
  uStack_6 = 0xffff;
  uVar6 = 0xffff;
  uStack_4 = 0xffff;
  for (uVar5 = 0; uVar5 < EntityCount; uVar5 = uVar5 + 1) {
    iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar5 * 0x37));
    if (iVar2 == iVar1) {
      uVar7 = Entities.seg;
      uVar4 = Entities.ofs;
      if (*(int *)(uVar4 + uVar5 * 0x37 + 2) == param_2) {
        uVar3 = (uint)*(byte *)(uVar4 + uVar5 * 0x37 + 0xd) * 0x95;
        if (*(char *)((int)(char **)GMenuStrings + uVar3 + 0x1f) != '\0') {
          return (char *)(uVar3 & 0xff00);
        }
        if ((*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 +
                      (uint)*(byte *)(uVar4 + uVar5 * 0x37 + 0xd) * 0x95) != -1) &&
           (*(char *)(uVar4 + uVar5 * 0x37 + 0x1a) != -1)) {
          if (*(char *)(uVar4 + uVar5 * 0x37 + 0x1a) == param_5) {
            *param_3 = uVar5;
          }
          else if (*(char *)(uVar4 + uVar5 * 0x37 + 0x1a) == DAT_2410_74ac) {
            uStack_6 = uVar5;
          }
          if ((uStack_4 != 0xffff) && (*(byte *)(Entities.ofs + uVar5 * 0x37 + 0x1a) != uStack_4)) {
            *param_4 = 1;
          }
          uStack_4 = (uint)*(byte *)(Entities.ofs + uVar5 * 0x37 + 0x1a);
          uVar6 = uVar5;
        }
      }
    }
  }
  if (*param_3 == 0xffff) {
    if (uStack_6 == 0xffff) {
      if (uVar6 == 0xffff) {
        return (char *)"arena" + 4;
      }
      *param_3 = uVar6;
    }
    else {
      *param_3 = uStack_6;
    }
  }
  iVar1 = (uint)*(byte *)(Entities.ofs + *param_3 * 0x37 + 0xd) * 0x95;
  DAT_2410_74ac = *(undefined1 *)(Entities.ofs + *param_3 * 0x37 + 0x1a);
  return (char *)CONCAT11((char)((uint)iVar1 >> 8),
                          '\x01' << (*(byte *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + iVar1) &
                                    0x1f));
}



/* 77eb:04d8 */

undefined2 __cdecl16far OVC45_77eb_04d8(undefined2 param_1,undefined2 param_2,int *param_3)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_SS;
  int local_42 [10];
  int local_2e [20];
  int local_6;
  byte bStack_3;
  
  uVar2 = ovr_OVC23_55fe_3450(param_1);
  local_6 = *param_3;
  iVar4 = -1;
  for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
    iVar4 = OVC45_77eb_01bb(iVar4,uVar2,param_2,&local_6);
    if (iVar4 == -1) break;
    local_42[iVar3] = local_6;
    iVar1 = *(int *)(iVar4 * 4);
    local_2e[iVar3 * 2 + 1] = ((int *)(iVar4 * 4))[1];
    local_2e[iVar3 * 2] = iVar1;
  }
  if (iVar3 < 2) {
    *param_3 = local_6;
    iVar4 = (uint)*(byte *)(Entities.ofs + *param_3 * 0x37 + 0xd) * 0x95;
    uVar2 = CONCAT11((char)((uint)iVar4 >> 8),
                     '\x01' << (*(byte *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + iVar4) & 0x1f));
  }
  else {
    ovr_OVC22_5087_0119(CONCAT11((char)((uint)(*param_3 * 0x37) >> 8),
                                 *(undefined1 *)(Entities.ofs + *param_3 * 0x37 + 0x1a)));
    ovr_fmVsprintf((char *)"Choose party to build for.  Now building for %s the %s.",
                   (char *)*(undefined2 *)
                            ((uint)*(byte *)(Entities.ofs + *param_3 * 0x37 + 0x1a) * 4));
    bStack_3 = ovr_OVC28_6018_1527(local_2e);
    if (bStack_3 == 0) {
      uVar2 = 0xff;
    }
    else {
      *param_3 = local_2e[bStack_3 - 0xb];
      DAT_2410_74ac = *(undefined1 *)(Entities.ofs + *param_3 * 0x37 + 0x1a);
      iVar4 = (uint)*(byte *)(Entities.ofs + *param_3 * 0x37 + 0xd) * 0x95;
      uVar2 = CONCAT11((char)((uint)iVar4 >> 8),
                       '\x01' << (*(byte *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + iVar4) & 0x1f))
      ;
    }
  }
  return uVar2;
}



/* 77eb:0683 */

int __cdecl16far OVC45_77eb_0683(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2;
  if ((*(uint *)(iVar1 + 0x128) & 3) == 0) {
    iVar1 = OVC45_77eb_0179(param_1,param_2);
    iVar1 = (uint)*(byte *)((int)DAT_2000_ca95 + iVar1 * 9) * 0x27;
    bVar2 = (byte)((uint)iVar1 >> 8);
    if ((*(uint *)(iVar1 + 0x121) & 0x18) == 0) {
      iVar1 = (uint)bVar2 << 8;
    }
    else {
      iVar1 = CONCAT11(bVar2,1);
    }
  }
  else {
    iVar1 = CONCAT11((char)((uint)iVar1 >> 8),1);
  }
  return iVar1;
}



/* 77eb:0708 */

bool __cdecl16far OVC45_77eb_0708(int param_1,int param_2)

{
  return (*(uint *)(param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2 + 0x128) & 3) == 3;
}



/* 77eb:0742 */

int __cdecl16far OVC45_77eb_0742(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2;
  bVar2 = (byte)((uint)iVar1 >> 8);
  if ((*(uint *)(iVar1 + 0x128) & 3) == 0) {
    iVar1 = (uint)bVar2 << 8;
  }
  else {
    iVar1 = CONCAT11(bVar2,1);
  }
  return iVar1;
}



/* 77eb:0778 */

uint __cdecl16far OVC45_77eb_0778(byte param_1,int param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  
  if ((*(uint *)((uint)param_1 * 0x27 + 0x121) & 0x10) != 0) {
    cVar1 = OVC45_77eb_0683(param_2,param_3 + 1);
    if (((cVar1 == '\0') && (cVar1 = OVC45_77eb_0683(param_2,param_3), cVar1 == '\0')) &&
       (cVar1 = OVC45_77eb_0683(param_2,param_3 + -1), cVar1 == '\0')) {
      return 0;
    }
    cVar1 = OVC45_77eb_0708(param_2,param_3 + 1);
    if (((cVar1 != '\0') && (cVar1 = OVC45_77eb_0708(param_2,param_3), cVar1 != '\0')) &&
       (uVar3 = OVC45_77eb_0708(param_2,param_3 + -1), (char)uVar3 != '\0')) {
      return uVar3 & 0xff00;
    }
    cVar1 = OVC45_77eb_0742(param_2,param_3 + 1);
    if (((cVar1 == '\0') && (cVar1 = OVC45_77eb_0742(param_2,param_3), cVar1 == '\0')) &&
       (cVar1 = OVC45_77eb_0742(param_2,param_3 + -1), cVar1 == '\0')) {
      return 0;
    }
  }
  uVar3 = (uint)param_1 * 0x27;
  if ((*(uint *)(uVar3 + 0x121) & 8) != 0) {
    cVar1 = OVC45_77eb_0683(param_2,param_3);
    if (((cVar1 == '\0') && (cVar1 = OVC45_77eb_0683(param_2 + -1,param_3), cVar1 == '\0')) &&
       (cVar1 = OVC45_77eb_0683(param_2 + 1,param_3), cVar1 == '\0')) {
      return 0;
    }
    cVar1 = OVC45_77eb_0708(param_2,param_3);
    if (((cVar1 != '\0') && (cVar1 = OVC45_77eb_0708(param_2 + -1,param_3), cVar1 != '\0')) &&
       (uVar3 = OVC45_77eb_0708(param_2 + 1,param_3), (char)uVar3 != '\0')) {
      return uVar3 & 0xff00;
    }
    bVar2 = OVC45_77eb_0742(param_2,param_3);
    uVar3 = (uint)bVar2;
    if (uVar3 == 0) {
      bVar2 = OVC45_77eb_0742(param_2 + -1,param_3);
      uVar3 = (uint)bVar2;
      if (uVar3 == 0) {
        bVar2 = OVC45_77eb_0742(param_2 + 1,param_3);
        uVar3 = (uint)bVar2;
        if (uVar3 == 0) {
          return 0;
        }
      }
    }
  }
  return CONCAT11((char)(uVar3 >> 8),1);
}



/* 77eb:0904 */

undefined2 __cdecl16far OVC45_77eb_0904(byte param_1)

{
  uint uVar1;
  long lVar2;
  long b;
  
  if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x87) < 0xb) {
    uVar1 = *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x87);
  }
  else {
    uVar1 = 10;
  }
  b = 10;
  lVar2 = LXMUL_at_(CONCAT22(DAT_2000_ca93,DAT_2000_ca91),(ulong)uVar1);
  lVar2 = LDIV_at_(lVar2,b);
  return (int)lVar2;
}



/* 77eb:0976 */

int __cdecl16far OVC45_77eb_0976(byte param_1)

{
  int iVar1;
  
  if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x87) < 0xb) {
    iVar1 = *(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x87) * 10;
  }
  else {
    iVar1 = 100;
  }
  return iVar1;
}



/* 77eb:09c1 */

int __cdecl16far OVC45_77eb_09c1(byte param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
  iVar3 = (int)*(undefined4 *)((uint)param_1 << 2);
  uVar1 = *(undefined2 *)(iVar3 + 0x58);
  iVar3 = *(int *)(iVar3 + 0x56);
  iVar2 = OVC45_77eb_0904(CONCAT11((char)((uint)uVar1 >> 8),param_1),iVar3,uVar1);
  return iVar3 + iVar2;
}



/* 77eb:0a02 */

void __cdecl16far OVC45_77eb_0a02(byte param_1,uint param_2,int param_3)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  bool bVar11;
  
  uVar10 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
  iVar8 = (int)*(undefined4 *)((uint)param_1 << 2);
  iVar9 = *(int *)(iVar8 + 0x58);
  if ((iVar9 < param_3) || ((iVar9 == param_3 && (*(uint *)(iVar8 + 0x56) < param_2)))) {
    uVar10 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
    iVar9 = (int)*(undefined4 *)((uint)param_1 << 2);
    uVar6 = *(uint *)(iVar9 + 0x56);
    uVar3 = param_2 - uVar6;
    pcVar4 = (char *)((param_3 - *(int *)(iVar9 + 0x58)) - (uint)(param_2 < uVar6));
    pcVar7 = (char *)"halfling castle" + 0xc;
    uVar5 = *(undefined4 *)((uint)param_1 << 2);
    uVar10 = (undefined2)((ulong)uVar5 >> 0x10);
    iVar9 = (int)uVar5;
    *(undefined2 *)(iVar9 + 0x58) = 0;
    *(undefined2 *)(iVar9 + 0x56) = 0;
    uVar6 = OVC45_77eb_0904(CONCAT11((char)(((uint)param_1 << 2) >> 8),param_1));
    if (((int)pcVar4 < (int)pcVar7) || ((pcVar4 == pcVar7 && (uVar3 < uVar6)))) {
      bVar11 = DAT_2000_ca91 < uVar3;
      DAT_2000_ca91 = DAT_2000_ca91 - uVar3;
      DAT_2000_ca93 = (DAT_2000_ca93 - (int)pcVar4) - (uint)bVar11;
    }
    else {
      bVar11 = DAT_2000_ca91 < uVar6;
      DAT_2000_ca91 = DAT_2000_ca91 - uVar6;
      DAT_2000_ca93 = (DAT_2000_ca93 - (int)pcVar7) - (uint)bVar11;
    }
  }
  else {
    uVar10 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
    iVar9 = (int)*(undefined4 *)((uint)param_1 << 2);
    puVar1 = (uint *)(iVar9 + 0x56);
    uVar3 = *puVar1;
    *puVar1 = *puVar1 - param_2;
    piVar2 = (int *)(iVar9 + 0x58);
    *piVar2 = (*piVar2 - param_3) - (uint)(uVar3 < param_2);
  }
  return;
}



/* 77eb:0aea */

uint __cdecl16far OVC45_77eb_0aea(int param_1,undefined2 param_2)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  
  cVar1 = ovr_constr_36ce_306b(param_1,param_2);
  if (cVar1 == '\0') {
    uVar3 = 0;
  }
  else {
    uVar3 = ovr_OVC23_55fe_2937(param_1,param_2);
    if (uVar3 == 0xffff) {
      uVar3 = OVC45_77eb_0121(param_1,param_2);
      if (uVar3 == 0) {
        bVar2 = OVC45_77eb_0121(param_1 + -1,param_2);
        if (*(byte *)((uint)bVar2 * 0x27 + 0x11b) < 2) {
          bVar2 = OVC45_77eb_0121(param_1 + -2,param_2);
          if (*(byte *)((uint)bVar2 * 0x27 + 0x11b) < 3) {
            bVar2 = OVC45_77eb_0121(param_1 + -3,param_2);
            bVar4 = (byte)((uint)bVar2 * 0x27 >> 8);
            if (*(byte *)((uint)bVar2 * 0x27 + 0x11b) < 4) {
              uVar3 = CONCAT11(bVar4,1);
            }
            else {
              uVar3 = (uint)bVar4 << 8;
            }
          }
          else {
            uVar3 = (uint)bVar2 * 0x27 & 0xff00;
          }
        }
        else {
          uVar3 = (uint)bVar2 * 0x27 & 0xff00;
        }
      }
      else {
        uVar3 = uVar3 & 0xff00;
      }
    }
    else {
      uVar3 = uVar3 & 0xff00;
    }
  }
  return uVar3;
}



/* 77eb:0bc1 */

uint __cdecl16far OVC45_77eb_0bc1(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar2 = ovr_manage_4d05_1b1d();
  if ((byte)uVar2 == 0xff) {
    uVar2 = uVar2 & 0xff00;
  }
  else {
    puVar3 = (undefined4 *)((uVar2 & 0xff) << 2);
    uVar1 = *puVar3;
    if (*(byte *)((int)uVar1 + 0x86) < 4) {
      uVar2 = CONCAT11((char)((uint)puVar3 >> 8),4);
    }
    else {
      uVar1 = *(undefined4 *)((uVar2 & 0xff) << 2);
      if (*(byte *)((int)uVar1 + 0x86) < 9) {
        puVar3 = (undefined4 *)((uVar2 & 0xff) << 2);
        uVar1 = *puVar3;
        uVar2 = CONCAT11((char)((uint)puVar3 >> 8),*(char *)((int)uVar1 + 0x86) + '\x01');
      }
      else {
        uVar2 = (uint)(byte)((byte)uVar2 >> 6) << 8;
      }
    }
  }
  return uVar2;
}



/* 77eb:0c36 */

char * __cdecl16far OVC45_77eb_0c36(byte param_1)

{
  byte bVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  undefined2 uVar5;
  
  if (*(char *)((uint)param_1 * 0x27 + 0x133) == '\x17') {
    for (uVar4 = 0xf8; uVar4 < DAT_2000_ca99; uVar4 = uVar4 + 1) {
      uVar5 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
      bVar1 = *(byte *)((int)DAT_2000_ca95 + uVar4 * 9 + 2);
      if (((*(char *)((uint)*(byte *)((int)DAT_2000_ca95 + uVar4 * 9) * 0x27 + 0x133) == '\x17') &&
          (bVar1 != 0xff)) &&
         (uVar2 = *(undefined4 *)((uint)bVar1 << 2), *(char *)((int)uVar2 + 0x3f) == '\0')) {
        return (char *)0x1;
      }
    }
    for (uVar4 = 0; uVar4 < DAT_2000_d2df; uVar4 = uVar4 + 1) {
      bVar1 = *(byte *)(uVar4 * 0x12 + 9);
      if (((*(char *)((uint)*(byte *)(uVar4 * 0x12 + 8) * 0x27 + 0x133) == '\x17') &&
          (bVar1 != 0xff)) &&
         (uVar2 = *(undefined4 *)((uint)bVar1 << 2), *(char *)((int)uVar2 + 0x3f) == '\0')) {
        return (char *)0x1;
      }
    }
    pcVar3 = (char *)"arena" + 4;
  }
  else {
    pcVar3 = (char *)((uint)param_1 * 0x27 & 0xff00);
  }
  return pcVar3;
}



/* 77eb:0d61 */
/* recovered by relaxed-limit retry */
/* OVC45_77eb_0d61 @ 77eb:0d61 */

/* WARNING: Removing unreachable block (ram,0x00079554) */

undefined2 __cdecl16far
OVC45_77eb_0d61(int param_1,int param_2,int param_3,undefined2 param_4,char param_5)

{
  far_t pixels;
  far_t pixels_00;
  far_t pixels_01;
  far_t pixels_02;
  far_t pixels_03;
  far_t pixels_04;
  far_t pixels_05;
  far_t pixels_06;
  far_t pixels_07;
  far_t pixels_08;
  far_t pixels_09;
  far_t pixels_10;
  far_t pixels_11;
  far_t pixels_12;
  far_t pixels_13;
  far_t pixels_14;
  far_t pixels_15;
  far_t pixels_16;
  far_t pixels_17;
  far_t pixels_18;
  far_t pixels_19;
  far_t pixels_20;
  far_t pixels_21;
  far_t pixels_22;
  far_t pixels_23;
  far_t pixels_24;
  far_t pixels_25;
  far_t pixels_26;
  far_t pixels_27;
  far_t pixels_28;
  far_t pixels_29;
  far_t pixels_30;
  far_t pixels_31;
  far_t pixels_32;
  far_t pixels_33;
  far_t pixels_34;
  far_t pixels_35;
  far_t pixels_36;
  far_t pixels_37;
  far_t pixels_38;
  far_t pixels_39;
  far_t pixels_40;
  far_t pixels_41;
  far_t pixels_42;
  far_t pixels_43;
  far_t pixels_44;
  far_t pixels_45;
  far_t pixels_46;
  far_t pixels_47;
  far_t pixels_48;
  far_t pixels_49;
  far_t pixels_50;
  far_t pixels_51;
  far_t pixels_52;
  far_t pixels_53;
  far_t pixels_54;
  far_t pixels_55;
  far_t pixels_56;
  far_t pixels_57;
  far_t pixels_58;
  far_t pixels_59;
  far_t pixels_60;
  far_t pixels_61;
  far_t pixels_62;
  far_t pixels_63;
  far_t pixels_64;
  far_t pixels_65;
  far_t pixels_66;
  far_t pixels_67;
  far_t pixels_68;
  far_t pixels_69;
  far_t pixels_70;
  far_t pixels_71;
  far_t pixels_72;
  far_t pixels_73;
  far_t pixels_74;
  far_t pixels_75;
  far_t pixels_76;
  far_t pixels_77;
  far_t pixels_78;
  far_t pixels_79;
  far_t pixels_80;
  far_t pixels_81;
  far_t pixels_82;
  far_t pixels_83;
  far_t pixels_84;
  far_t pixels_85;
  far_t pixels_86;
  far_t pixels_87;
  far_t pixels_88;
  far_t pixels_89;
  far_t pixels_90;
  far_t pixels_91;
  far_t pixels_92;
  far_t pixels_93;
  far_t pixels_94;
  far_t pixels_95;
  far_t pixels_96;
  far_t pixels_97;
  far_t pixels_98;
  far_t pixels_99;
  far_t pixels_x00100;
  far_t pixels_x00101;
  far_t pixels_x00102;
  far_t pixels_x00103;
  far_t pixels_x00104;
  far_t pixels_x00105;
  far_t pixels_x00106;
  far_t pixels_x00107;
  far_t pixels_x00108;
  far_t pixels_x00109;
  far_t pixels_x00110;
  far_t pixels_x00111;
  far_t pixels_x00112;
  far_t pixels_x00113;
  far_t pixels_x00114;
  far_t pixels_x00115;
  far_t pixels_x00116;
  far_t pixels_x00117;
  far_t pixels_x00118;
  far_t pixels_x00119;
  far_t pixels_x00120;
  far_t pixels_x00121;
  far_t pixels_x00122;
  far_t pixels_x00123;
  far_t pixels_x00124;
  far_t pixels_x00125;
  far_t pixels_x00126;
  far_t pixels_x00127;
  far_t pixels_x00128;
  far_t pixels_x00129;
  far_t pixels_x00130;
  far_t pixels_x00131;
  far_t pixels_x00132;
  far_t pixels_x00133;
  far_t pixels_x00134;
  far_t pixels_x00135;
  far_t pixels_x00136;
  far_t pixels_x00137;
  far_t pixels_x00138;
  far_t pixels_x00139;
  far_t pixels_x00140;
  far_t pixels_x00141;
  far_t pixels_x00142;
  far_t pixels_x00143;
  far_t pixels_x00144;
  far_t pixels_x00145;
  far_t pixels_x00146;
  far_t pixels_x00147;
  far_t pixels_x00148;
  far_t pixels_x00149;
  far_t pixels_x00150;
  far_t pixels_x00151;
  far_t pixels_x00152;
  far_t pixels_x00153;
  far_t pixels_x00154;
  far_t pixels_x00155;
  far_t pixels_x00156;
  far_t pixels_x00157;
  far_t pixels_x00158;
  far_t pixels_x00159;
  far_t pixels_x00160;
  far_t pixels_x00161;
  far_t pixels_x00162;
  far_t pixels_x00163;
  far_t pixels_x00164;
  far_t pixels_x00165;
  far_t pixels_x00166;
  far_t pixels_x00167;
  far_t pixels_x00168;
  far_t pixels_x00169;
  far_t pixels_x00170;
  far_t pixels_x00171;
  far_t pixels_x00172;
  far_t pixels_x00173;
  far_t pixels_x00174;
  far_t pixels_x00175;
  far_t pixels_x00176;
  far_t pixels_x00177;
  far_t pixels_x00178;
  far_t pixels_x00179;
  far_t pixels_x00180;
  far_t pixels_x00181;
  far_t pixels_x00182;
  far_t pixels_x00183;
  far_t pixels_x00184;
  far_t pixels_x00185;
  far_t pixels_x00186;
  far_t pixels_x00187;
  far_t pixels_x00188;
  far_t pixels_x00189;
  far_t pixels_x00190;
  far_t pixels_x00191;
  far_t pixels_x00192;
  far_t pixels_x00193;
  far_t pixels_x00194;
  far_t pixels_x00195;
  far_t pixels_x00196;
  far_t pixels_x00197;
  far_t pixels_x00198;
  far_t src;
  far_t src_00;
  far_t src_01;
  far_t src_02;
  far_t src_03;
  far_t src_04;
  far_t src_05;
  far_t src_06;
  far_t src_07;
  far_t src_08;
  far_t src_09;
  far_t src_10;
  far_t src_11;
  far_t src_12;
  far_t src_13;
  far_t src_14;
  far_t src_15;
  far_t src_16;
  far_t src_17;
  far_t src_18;
  far_t src_19;
  far_t src_20;
  far_t src_21;
  far_t src_22;
  far_t src_23;
  far_t src_24;
  far_t src_25;
  far_t pixels_x00199;
  far_t buf;
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  char *pcVar4;
  undefined1 uVar6;
  size_t sVar5;
  stg_tmp_t *psVar7;
  uint16_t uVar8;
  undefined2 *puVar9;
  int iVar10;
  undefined2 unaff_SI;
  int iVar11;
  int iVar12;
  undefined2 unaff_DI;
  undefined2 uVar13;
  uint16_t uVar14;
  undefined2 unaff_SS;
  uint8_t *puVar15;
  cte_t *pcVar16;
  undefined4 uVar17;
  far_t fVar18;
  stg_tmp_t *psVar19;
  DW sz;
  char *pcVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  char *apcStack_3f2 [19];
  char local_3cc [712];
  undefined1 local_104 [80];
  char local_b4 [161];
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  byte bStack_10;
  undefined1 uStack_f;
  char cStack_e;
  byte local_d;
  undefined4 uStack_c;
  int iStack_4;
  
  uVar21 = (undefined1)unaff_SI;
  uVar22 = (undefined1)((uint)unaff_SI >> 8);
  cVar2 = ovr_OVC23_55fe_3450(param_1);
  bStack_13 = param_1._0_1_ - (cVar2 + -2);
  do {
    uStack_f = 0;
    bStack_11 = *(byte *)(Entities.ofs + param_3 * 0x37 + 0x1a);
    uVar17 = *(undefined4 *)((uint)bStack_11 << 2);
    bStack_12 = ovr_bldng_676c_05ac(CONCAT11((char)(((uint)bStack_11 << 2) >> 8),
                                             *(undefined1 *)((int)uVar17 + 0x85)));
    if (*(int *)((uint)bStack_12 * 0x27 + 0x112) == 0 &&
        *(int *)((uint)bStack_12 * 0x27 + 0x114) == 0) {
      pcVar4 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)bStack_12 * 0x27 + 0x10e),
                                           *(undefined2 *)((uint)bStack_12 * 0x27 + 0x110));
      pcVar20 = ovr_stsprintf(local_3cc,"%s:",pcVar4);
      uVar6 = (undefined1)((ulong)pcVar20 >> 8);
    }
    else {
      pcVar4 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)bStack_12 * 0x27 + 0x10e),
                                           *(undefined2 *)((uint)bStack_12 * 0x27 + 0x110));
      pcVar20 = ovr_stsprintf(local_3cc,
                              (char *)CONCAT22(*(undefined2 *)((uint)bStack_12 * 0x27 + 0x114),
                                               (char *)*(undefined2 *)
                                                        ((uint)bStack_12 * 0x27 + 0x112)),pcVar4);
      uVar6 = (undefined1)((ulong)pcVar20 >> 8);
    }
    iVar11 = 0;
    cStack_e = '\0';
    cVar2 = OVC45_77eb_0c36(CONCAT11(uVar6,bStack_12));
    if (cVar2 == '\0') {
      cVar2 = OVC45_77eb_0778(bStack_12,param_1,param_2);
      if (cVar2 == '\0') {
        strcat(local_3cc,(char *)" Bridges must be near water\'s edge.");
        cStack_e = '\x01';
      }
      else {
        cVar2 = ovr_bldng_676c_003d(bStack_12,bStack_11);
        if (cVar2 == '\0') {
          if (*(char *)((uint)bStack_12 * 0x27 + 0x133) == '\x12') {
            cVar2 = OVC45_77eb_0bc1();
            if (cVar2 == '\0') {
              strcat(local_3cc,(char *)" No more outposts are available.");
            }
            else {
              bVar3 = OVC45_77eb_0bc1();
              pcVar20 = ovr_stsprintf(local_b4," Next outpost available at rank %s.",
                                      (char *)((far_t *)(GStatsLabels + 4) + (uint)bVar3 * 2)->ofs);
              strcat(local_3cc,(char *)pcVar20);
            }
          }
          else if ((*(byte *)((uint)bStack_12 * 0x27 + 0x134) & 0x80) == 0) {
            pcVar20 = ovr_stsprintf(local_b4," Requires a unit of level %d.",
                                    (char *)(uint)*(byte *)((uint)bStack_12 * 0x27 + 0x134));
            strcat(local_3cc,(char *)pcVar20);
          }
          else {
            pcVar20 = ovr_stsprintf(local_b4," Requires a rank of %s.",
                                    (char *)((far_t *)(GStatsLabels + 4) +
                                            (*(byte *)((uint)bStack_12 * 0x27 + 0x134) & 0x7f) * 2)
                                            ->ofs);
            strcat(local_3cc,(char *)pcVar20);
          }
          cStack_e = '\x01';
        }
        else if ((*(char *)((uint)bStack_12 * 0x27 + 0x11b) == '\x04') &&
                ((((cVar2 = OVC45_77eb_0aea(param_1 - (uint)bStack_13,param_2), cVar2 == '\0' ||
                   (cVar2 = OVC45_77eb_0aea((param_1 - (uint)bStack_13) + 1,param_2), cVar2 == '\0')
                   ) || (cVar2 = OVC45_77eb_0aea((param_1 - (uint)bStack_13) + 2,param_2),
                        cVar2 == '\0')) ||
                 (cVar2 = OVC45_77eb_0aea((param_1 - (uint)bStack_13) + 3,param_2), cVar2 == '\0')))
                ) {
          pcVar20 = ovr_stsprintf(local_b4," Location is too narrow for %s.",
                                  (char *)*(undefined2 *)((uint)bStack_12 * 0x27 + 0x10e));
          strcat(local_3cc,(char *)pcVar20);
          cStack_e = '\x01';
        }
        else if (((*(char *)((uint)bStack_12 * 0x27 + 0x11b) == '\x02') &&
                 ((bStack_13 == 3 || (cVar2 = OVC45_77eb_0aea(param_1 + 1,param_2), cVar2 == '\0')))
                 ) && ((bStack_13 == 0 ||
                       (cVar2 = OVC45_77eb_0aea(param_1 + -1,param_2), cVar2 == '\0')))) {
          pcVar20 = ovr_stsprintf(local_b4," Location is too narrow for a %s.",
                                  (char *)*(undefined2 *)((uint)bStack_12 * 0x27 + 0x10e));
          strcat(local_3cc,(char *)pcVar20);
          cStack_e = '\x01';
        }
        else {
          cVar2 = OVC45_77eb_234a(CONCAT11((char)((uint)bStack_12 * 0x27 >> 8),
                                           *(undefined1 *)((uint)bStack_12 * 0x27 + 0x11e)),param_1,
                                  param_2);
          if (cVar2 == '\0') {
            if (((*(char *)((uint)bStack_12 * 0x27 + 0x11a) == '\x02') ||
                (*(char *)((uint)bStack_12 * 0x27 + 0x11e) == '\x01')) ||
               ((*(char *)((uint)bStack_12 * 0x27 + 0x11e) == '\x02' ||
                (cVar2 = ovr_attact_3f0b_0000(param_1,param_2), cVar2 != '\0')))) {
              cVar2 = ovr_constr_36ce_306b(param_1,param_2);
              if (((cVar2 == '\0') && ((*(uint *)((uint)bStack_12 * 0x27 + 0x121) & 0x20) == 0)) &&
                 (*(char *)((uint)bStack_12 * 0x27 + 0x11e) == '\0')) {
                strcpy(local_3cc,(char *)"This location is unsuitable for buildings.");
                cStack_e = '\x01';
              }
              else {
                ovr_OVC22_5087_0119(CONCAT11((char)((uint)(param_3 * 0x37) >> 8),
                                             *(undefined1 *)(Entities.ofs + param_3 * 0x37 + 0x1a)),
                                    *(undefined2 *)((uint)bStack_12 * 0x27 + 0x125));
                pcVar4 = (char *)OVC45_77eb_226e(local_104);
                pcVar20 = ovr_stsprintf(local_b4," It will cost %s the %s %d gp. ",pcVar4);
                sVar5 = strlen(local_3cc);
                strcat(local_3cc + sVar5,(char *)pcVar20);
              }
            }
            else {
              strcpy(local_3cc,(char *)"Buildings cannot be placed over water.");
              cStack_e = '\x01';
            }
          }
          else {
            strcat(local_3cc,(char *)" Walls must be near land.");
            cStack_e = '\x01';
          }
        }
      }
    }
    else {
      strcat(local_3cc,(char *)" You can only place a single arena.");
      cStack_e = '\x01';
    }
    if ((cStack_e == '\0') &&
       (((cVar2 = ovr_constr_36ce_306b(param_1,param_2), cVar2 != '\0' ||
         ((*(uint *)((uint)bStack_12 * 0x27 + 0x121) & 0x20) != 0)) ||
        (*(char *)((uint)bStack_12 * 0x27 + 0x11e) != '\0')))) {
      apcStack_3f2[0] = (char *)"puppetmaker" + 3;
      uStack_c = (stg_tmp_t *)CONCAT31(uStack_c._1_3_,1);
      iVar11 = 1;
    }
    apcStack_3f2[iVar11 * 2] = (char *)"puppetmaker" + 3;
    apcStack_3f2[iVar11 * 2 + -1] = (char *)"Change Building";
    *(undefined1 *)((int)&uStack_c + iVar11) = 2;
    iVar12 = iVar11 + 1;
    if (param_5 != '\0') {
      apcStack_3f2[iVar12 * 2] = (char *)"puppetmaker" + 3;
      apcStack_3f2[iVar12 * 2 + -1] = (char *)"Change Party";
      *(undefined1 *)((int)&uStack_c + iVar11 + 1) = 3;
      iVar12 = iVar11 + 2;
    }
    apcStack_3f2[iVar12 * 2] = (char *)"puppetmaker" + 3;
    apcStack_3f2[iVar12 * 2 + -1] = (char *)"Done";
    *(undefined1 *)((int)&uStack_c + iVar12) = 4;
    iVar11 = iVar12 + 1;
    DAT_2410_5cef = bStack_11;
    bStack_10 = ovr_OVC28_6018_1527(&stack0xfc0c);
    DAT_2410_5cef = 0xff;
    if (bStack_10 != 0) {
      bStack_10 = (&local_d)[bStack_10];
    }
    uStack_f = 0;
    pcVar4 = (char *)(uint)bStack_10;
  } while ((char *)"Borland C++ - Copyright 1991 Borland Intl." + 1 <= pcVar4);
  iVar10 = (int)pcVar4 * 2;
  uVar6 = 0;
  uVar1 = 0;
  switch(pcVar4) {
  case (char *)0x0:
code_r0x00074dd2:
    *(undefined2 *)(pcVar4 + 0x4dd2) = unaff_DI;
    *(uint *)(pcVar4 + 0x4dd0) = CONCAT11(uVar22,uVar21);
    uVar17 = func_0x0007ffe0(uVar6);
    *(undefined2 *)((int)&BldGfxNormal[1].seg + iVar11 * 0xc) = (int)((ulong)uVar17 >> 0x10);
    ((far_t *)(BldGfxNormal + 1) + iVar11 * 3)->ofs = (uint16_t)uVar17;
    uVar17 = func_0x0007ffe0(uVar6);
    *(undefined2 *)((int)&BldGfxNormal[2].seg + iVar11 * 0xc) = (int)((ulong)uVar17 >> 0x10);
    ((far_t *)(BldGfxNormal + 2) + iVar11 * 3)->ofs = (uint16_t)uVar17;
    uVar17 = func_0x0007ffe0(uVar6);
    *(undefined2 *)((int)&BldGfxRuin[0].seg + iVar11 * 0xc) = (int)((ulong)uVar17 >> 0x10);
    ((far_t *)BldGfxRuin + iVar11 * 3)->ofs = (uint16_t)uVar17;
    uVar17 = func_0x0007ffe0(uVar6);
    *(undefined2 *)((int)&BldGfxRuin[1].seg + iVar11 * 0xc) = (int)((ulong)uVar17 >> 0x10);
    ((far_t *)(BldGfxRuin + 1) + iVar11 * 3)->ofs = (uint16_t)uVar17;
    uVar17 = func_0x0007ffe0(uVar6);
    *(undefined2 *)((int)&BldGfxRuin[2].seg + iVar11 * 0xc) = (int)((ulong)uVar17 >> 0x10);
    ((far_t *)(BldGfxRuin + 2) + iVar11 * 3)->ofs = (uint16_t)uVar17;
    goto LAB_6ffe_4ea5;
  case (char *)0x1:
code_r0x00072658:
    ovr_stgFreeTmp(uStack_c);
    uStack_c = ovr_grabLbmTR(176);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_81.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_81.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_81,100,130,199,194,26,-4);
    pcVar16 = ovr_stshStoreFile(puVar15);
    *(int *)((char *)"build\\clebath2.lbm" + 0xe + iVar11 * 0xc) = (int)((ulong)pcVar16 >> 0x10);
    *(cte_t **)((char *)"build\\clebath2.lbm" + 0xc + iVar11 * 0xc) = (cte_t *)pcVar16;
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_82.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_82.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_82,100,65,199,129,26,-4);
    pcVar16 = ovr_stshStoreFile(puVar15);
    iVar12 = (iVar11 + 1) * 0xc;
    *(int *)((char *)"build\\clebath2.lbm" + 0xe + iVar12) = (int)((ulong)pcVar16 >> 0x10);
    *(cte_t **)((char *)"build\\clebath2.lbm" + 0xc + iVar12) = (cte_t *)pcVar16;
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_83.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_83.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_83,100,0,199,64,26,-4);
    pcVar16 = ovr_stshStoreFile(puVar15);
    iVar11 = (iVar11 + 2) * 0xc;
    *(int *)((char *)"build\\clebath2.lbm" + 0xe + iVar11) = (int)((ulong)pcVar16 >> 0x10);
    *(cte_t **)((char *)"build\\clebath2.lbm" + 0xc + iVar11) = (cte_t *)pcVar16;
    ovr_stgFreeTmp(uStack_c);
    break;
  case (char *)0x2:
    cVar2 = OVC45_77eb_0742(pcVar4 + -1);
    if ((cVar2 == '\0') && (cVar2 = OVC45_77eb_0742(iVar12 + 2,param_2), cVar2 == '\0')) {
      uVar13 = 0;
    }
    else {
      uVar13 = 1;
    }
    return uVar13;
  case (char *)0x3:
    goto code_r0x00074dd0;
  case "Borland C++ - Copyright 1991 Borland Intl.":
    LOCK();
    *(undefined1 *)(iVar10 + iVar11) = (char)((uint)iVar10 >> 8);
    UNLOCK();
    strcpy(pcVar4,(char *)CONCAT11(uVar22,uVar21));
    LOCK();
    *(int *)(&stack0xfffe + param_2) = iVar11;
    UNLOCK();
    while (iStack_4 = iStack_4 + 1, iStack_4 < 0xc) {
      if (param_1._0_1_ == false) {
        uVar17 = func_0x0007ffe0();
        *(int *)((undefined *)&DAT_2000_d135 + iStack_4 * 4) = (int)((ulong)uVar17 >> 0x10);
        *(int *)((undefined *)&DAT_2000_d133 + iStack_4 * 4) = (int)uVar17;
      }
      else {
        uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
        src.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
        src.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
        fVar18 = ovr_stshRleCut(src,iStack_4 * 0x17 + 6,21,iStack_4 * 0x17 + 0x1b,62);
        pcVar16 = ovr_stshStoreFile((uint8_t *)fVar18);
        *(int *)((undefined *)&DAT_2000_d135 + iStack_4 * 4) = (int)((ulong)pcVar16 >> 0x10);
        *(cte_t **)((undefined *)&DAT_2000_d133 + iStack_4 * 4) = (cte_t *)pcVar16;
      }
    }
    iStack_4 = 0;
    while( true ) {
      if (5 < iStack_4) break;
      if (param_1._0_1_ == false) {
        uVar17 = func_0x0007ffe0();
        ((undefined2 *)&DAT_2000_d11d)[iStack_4 * 2] = (int)((ulong)uVar17 >> 0x10);
        ((undefined2 *)&DAT_2000_d11b)[iStack_4 * 2] = (int)uVar17;
      }
      else {
        src_00.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
        src_00.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
        fVar18 = ovr_stshRleCut(src_00,iStack_4 * 0x17 + 9,72,iStack_4 * 0x17 + 0x16,75);
        pcVar16 = ovr_stshStoreFile((uint8_t *)fVar18);
        ((undefined2 *)&DAT_2000_d11d)[iStack_4 * 2] = (int)((ulong)pcVar16 >> 0x10);
        ((undefined2 *)&DAT_2000_d11b)[iStack_4 * 2] = (cte_t *)pcVar16;
      }
      iStack_4 = iStack_4 + 1;
    }
    if (param_1._0_1_ == false) {
      BldGfxNormal[4] = (far_t)func_0x0007ffe0();
      BldGfxNormal[7] = (far_t)func_0x0007ffe0();
      BldGfxNormal[10] = (far_t)func_0x0007ffe0();
      BldGfxRuin[4] = (far_t)func_0x0007ffe0();
      BldGfxRuin[7] = (far_t)func_0x0007ffe0();
      BldGfxRuin[10] = (far_t)func_0x0007ffe0();
      stshStubifyBld(4);
      stshStubifyBld(7);
      stshStubifyBld(10);
      stshStubifyBld(0xd);
      stshStubifyBld(0x10);
      stshStubifyBld(0x13);
      stshStubifyBld(0x16);
      BldGfxNormal[0x4c] = (far_t)func_0x0007ffe0();
      BldGfxNormal[0x4f] = (far_t)func_0x0007ffe0();
      BldGfxNormal[0x52] = (far_t)func_0x0007ffe0();
      BldGfxRuin[0x4c] = (far_t)func_0x0007ffe0();
      BldGfxRuin[0x4f] = (far_t)func_0x0007ffe0();
      BldGfxRuin[0x52] = (far_t)func_0x0007ffe0();
    }
    else {
      ovr_stgFreeTmp(uStack_c);
      uStack_c = ovr_grabLbmTR(80);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      src_01.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      src_01.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      fVar18 = ovr_stshRleCut(src_01,40,173,50,179);
      BldGfxNormal[4] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      src_02.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      src_02.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      fVar18 = ovr_stshRleCut(src_02,140,108,150,114);
      BldGfxNormal[7] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      src_03.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      src_03.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      fVar18 = ovr_stshRleCut(src_03,240,43,252,49);
      BldGfxNormal[10] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      src_04.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      src_04.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      fVar18 = ovr_stshRleCut(src_04,40,108,50,114);
      BldGfxRuin[4] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      src_05.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      src_05.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      fVar18 = ovr_stshRleCut(src_05,140,173,150,179);
      BldGfxRuin[7] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      src_06.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      src_06.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      fVar18 = ovr_stshRleCut(src_06,240,108,252,114);
      BldGfxRuin[10] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
      ovr_stgFreeTmp(uStack_c);
      psVar19 = ovr_grabLbmTR(387);
      uStack_c._0_2_ = (stg_tmp_t *)psVar19;
      uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
      fVar18.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      fVar18.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(fVar18,9,130,97,194,11,-5);
      BldGfxNormal[0xc] = (far_t)ovr_stshStoreFile(puVar15);
      pixels.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels,100,130,199,194,11,-5);
      BldGfxNormal[0xd] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_00.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_00.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_00,204,130,292,194,11,-5);
      BldGfxNormal[0xe] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_01.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_01.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_01,9,65,97,129,11,-5);
      BldGfxNormal[0xf] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_02.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_02.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_02,100,65,199,129,11,-5);
      BldGfxNormal[0x10] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_03.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_03.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_03,204,65,292,129,11,-5);
      BldGfxNormal[0x11] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_04.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_04.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_04,9,0,97,64,11,-5);
      BldGfxNormal[0x12] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_05.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_05.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_05,108,0,191,64,11,-5);
      BldGfxNormal[0x13] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_06.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_06.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_06,204,0,292,64,11,-5);
      BldGfxNormal[0x14] = (far_t)ovr_stshStoreFile(puVar15);
      ovr_stgFreeTmp((stg_tmp_t *)
                     CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                              CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
      uStack_c = ovr_grabLbmTR(485);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_07.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_07.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_07,9,130,97,194,11,-5);
      BldGfxRuin[0xc] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_08.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_08.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_08,100,130,199,194,11,-5);
      BldGfxRuin[0xd] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_09.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_09.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_09,204,130,292,194,11,-5);
      BldGfxRuin[0xe] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_10.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_10.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_10,9,65,97,129,11,-5);
      BldGfxRuin[0xf] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_11.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_11.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_11,100,65,199,129,11,-5);
      BldGfxRuin[0x10] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_12.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_12.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_12,204,65,292,129,11,-5);
      BldGfxRuin[0x11] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_13.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_13.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_13,9,0,97,64,11,-5);
      BldGfxRuin[0x12] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_14.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_14.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_14,108,0,191,64,11,-5);
      BldGfxRuin[0x13] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_15.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_15.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_15,204,0,292,64,11,-5);
      BldGfxRuin[0x14] = (far_t)ovr_stshStoreFile(puVar15);
      ovr_stgFreeTmp(uStack_c);
      psVar19 = ovr_grabLbmTR(392);
      uStack_c._0_2_ = (stg_tmp_t *)psVar19;
      uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
      pixels_16.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_16.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_16,0,130,99,194,26,-1);
      BldGfxNormal[0x15] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_17.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_17.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_17,100,130,199,194,26,-1);
      BldGfxNormal[0x16] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_18.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_18.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_18,200,130,299,194,26,-1);
      BldGfxNormal[0x17] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_19.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_19.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_19,0,65,99,129,26,-1);
      BldGfxNormal[0x18] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_20.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_20.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_20,100,65,199,129,26,-1);
      BldGfxNormal[0x19] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_21.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_21.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_21,200,65,299,129,26,-1);
      BldGfxNormal[0x1a] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_22.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_22.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_22,0,0,99,64,26,7);
      BldGfxNormal[0x1b] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_23.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_23.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_23,100,0,199,64,26,7);
      BldGfxNormal[0x1c] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_24.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_24.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_24,200,0,299,64,26,7);
      BldGfxNormal[0x1d] = (far_t)ovr_stshStoreFile(puVar15);
      ovr_stgFreeTmp((stg_tmp_t *)
                     CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                              CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
      uStack_c = ovr_grabLbmTR(393);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_25.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_25.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_25,0,130,99,194,26,-1);
      BldGfxRuin[0x15] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_26.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_26.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_26,100,130,199,194,26,-1);
      BldGfxRuin[0x16] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_27.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_27.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_27,200,130,299,194,26,-1);
      BldGfxRuin[0x17] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_28.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_28.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_28,0,65,99,129,26,-1);
      BldGfxRuin[0x18] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_29.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_29.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_29,100,65,199,129,26,-1);
      BldGfxRuin[0x19] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_30.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_30.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_30,200,65,299,129,26,-1);
      BldGfxRuin[0x1a] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_31.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_31.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_31,0,0,99,64,26,7);
      BldGfxRuin[0x1b] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_32.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_32.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_32,100,0,199,64,26,7);
      BldGfxRuin[0x1c] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_33.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_33.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_33,200,0,299,64,26,7);
      BldGfxRuin[0x1d] = (far_t)ovr_stshStoreFile(puVar15);
      ovr_stgFreeTmp(uStack_c);
      psVar19 = ovr_grabLbmTR(56);
      uStack_c._0_2_ = (stg_tmp_t *)psVar19;
      uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
      pixels_34.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_34.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_34,6,151,91,180,0,-25);
      BldGfxNormal[0x1e] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_35.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_35.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_35,110,151,185,180,0,-25);
      BldGfxNormal[0x1f] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_36.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_36.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_36,216,151,299,180,0,-25);
      BldGfxNormal[0x20] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_37.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_37.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_37,6,72,91,115,0,-11);
      BldGfxNormal[0x21] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_38.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_38.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_38,110,72,185,115,0,-11);
      BldGfxNormal[0x22] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_39.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_39.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_39,216,72,299,115,0,-11);
      BldGfxNormal[0x23] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_40.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_40.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_40,6,6,91,59,0,-1);
      BldGfxNormal[0x24] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_41.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_41.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_41,110,6,185,59,0,-1);
      BldGfxNormal[0x25] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_42.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_42.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_42,216,6,299,59,0,-1);
      BldGfxNormal[0x26] = (far_t)ovr_stshStoreFile(puVar15);
      ovr_stgFreeTmp((stg_tmp_t *)
                     CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                              CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
      uStack_c = ovr_grabLbmTR(444);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_43.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_43.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_43,6,151,91,180,0,-25);
      BldGfxRuin[0x1e] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_44.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_44.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_44,110,151,185,180,0,-25);
      BldGfxRuin[0x1f] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_45.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_45.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_45,216,151,299,180,0,-25);
      BldGfxRuin[0x20] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_46.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_46.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_46,6,72,91,115,0,-11);
      BldGfxRuin[0x21] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_47.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_47.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_47,110,72,185,115,0,-11);
      BldGfxRuin[0x22] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_48.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_48.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_48,216,72,299,115,0,-11);
      BldGfxRuin[0x23] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_49.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_49.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_49,6,6,91,59,0,-1);
      BldGfxRuin[0x24] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_50.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_50.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_50,110,6,185,59,0,-1);
      BldGfxRuin[0x25] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_51.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_51.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_51,216,6,299,59,0,-1);
      BldGfxRuin[0x26] = (far_t)ovr_stshStoreFile(puVar15);
      ovr_stgFreeTmp(uStack_c);
      psVar19 = ovr_grabLbmTR(447);
      uStack_c._0_2_ = (stg_tmp_t *)psVar19;
      uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
      pixels_52.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_52.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_52,2,130,89,180,0,-3);
      BldGfxNormal[0x27] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_53.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_53.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_53,108,130,191,180,0,-3);
      BldGfxNormal[0x28] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_54.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_54.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_54,212,130,298,180,0,-3);
      BldGfxNormal[0x29] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_55.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_55.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_55,2,65,89,115,0,-3);
      BldGfxNormal[0x2a] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_56.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_56.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_56,108,65,191,115,0,-3);
      BldGfxNormal[0x2b] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_57.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_57.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_57,212,65,298,115,0,-3);
      BldGfxNormal[0x2c] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_58.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_58.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_58,2,9,89,59,0,-3);
      BldGfxNormal[0x2d] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_59.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_59.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_59,108,9,191,59,0,-3);
      BldGfxNormal[0x2e] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_60.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_60.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_60,212,9,298,59,0,-3);
      BldGfxNormal[0x2f] = (far_t)ovr_stshStoreFile(puVar15);
      ovr_stgFreeTmp((stg_tmp_t *)
                     CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                              CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
      uStack_c = ovr_grabLbmTR(448);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_61.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_61.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_61,2,130,89,180,0,-3);
      BldGfxRuin[0x27] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_62.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_62.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_62,108,130,191,180,0,-3);
      BldGfxRuin[0x28] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_63.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_63.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_63,212,130,298,180,0,-3);
      BldGfxRuin[0x29] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_64.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_64.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_64,2,65,89,115,0,-3);
      BldGfxRuin[0x2a] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_65.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_65.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_65,108,65,191,115,0,-3);
      BldGfxRuin[0x2b] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_66.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_66.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_66,212,65,298,115,0,-3);
      BldGfxRuin[0x2c] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_67.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_67.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_67,2,9,89,59,0,-3);
      BldGfxRuin[0x2d] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_68.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_68.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_68,108,9,191,59,0,-3);
      BldGfxRuin[0x2e] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_69.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_69.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_69,212,9,298,59,0,-3);
      BldGfxRuin[0x2f] = (far_t)ovr_stshStoreFile(puVar15);
      ovr_stgFreeTmp(uStack_c);
      ovr_grabBldLbm(115,116,0x10);
      ovr_grabBldLbm(423,446,0x13);
      ovr_grabBldLbm(312,313,0x16);
      psVar19 = ovr_grabLbmTR(459);
      uStack_c._0_2_ = (stg_tmp_t *)psVar19;
      uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
      pixels_70.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_70.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_70,9,68,92,182,-4,56);
      BldGfxNormal[0x4c] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_71.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_71.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_71,108,68,191,182,-3,56);
      BldGfxNormal[0x4f] = (far_t)ovr_stshStoreFile(puVar15);
      pixels_72.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_72.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_72,208,68,291,182,-1,56);
      BldGfxNormal[0x52] = (far_t)ovr_stshStoreFile(puVar15);
      ovr_stgFreeTmp((stg_tmp_t *)
                     CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                              CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
      uStack_c = ovr_grabLbmTR(460);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_73.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_73.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_73,9,68,92,182,-4,56);
      BldGfxRuin[0x4c] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_74.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_74.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_74,108,68,191,182,-3,56);
      BldGfxRuin[0x4f] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_75.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_75.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_75,208,68,291,182,-1,56);
      BldGfxRuin[0x52] = (far_t)ovr_stshStoreFile(puVar15);
      ovr_stgFreeTmp(uStack_c);
    }
    ovr_stshStubifyCopy1to0();
    if (param_1._0_1_ != false) {
      uStack_c = ovr_grabLbmTR(172);
    }
    iStack_4 = 0;
    while( true ) {
      if (2 < iStack_4) break;
      if (param_1._0_1_ == false) {
        uVar17 = func_0x0007ffe0();
        *(undefined2 *)((int)&BldGfxNormal[1].seg + (iStack_4 + 0x1c) * 0xc) =
             (int)((ulong)uVar17 >> 0x10);
        ((far_t *)(BldGfxNormal + 1) + (iStack_4 + 0x1c) * 3)->ofs = (uint16_t)uVar17;
      }
      else {
        pixels_76.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
        pixels_76.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
        puVar15 = (uint8_t *)
                  ovr_stshRleType2(pixels_76,iStack_4 * 100 + 0x14,33,iStack_4 * 100 + 99,116,8,28);
        pcVar16 = ovr_stshStoreFile(puVar15);
        *(undefined2 *)((int)&BldGfxNormal[1].seg + (iStack_4 + 0x1c) * 0xc) =
             (int)((ulong)pcVar16 >> 0x10);
        ((far_t *)(BldGfxNormal + 1) + (iStack_4 + 0x1c) * 3)->ofs = (uint16_t)(cte_t *)pcVar16;
      }
      uVar8 = ((far_t *)(BldGfxNormal + 1) + (iStack_4 + 0x1c) * 3)->ofs;
      *(undefined2 *)((int)&BldGfxNormal[0].seg + (iStack_4 + 0x1c) * 0xc) =
           *(undefined2 *)((int)&BldGfxNormal[1].seg + (iStack_4 + 0x1c) * 0xc);
      ((far_t *)BldGfxNormal + (iStack_4 + 0x1c) * 3)->ofs = uVar8;
      uVar8 = ((far_t *)(BldGfxNormal + 1) + (iStack_4 + 0x1c) * 3)->ofs;
      *(undefined2 *)((int)&BldGfxNormal[2].seg + (iStack_4 + 0x1c) * 0xc) =
           *(undefined2 *)((int)&BldGfxNormal[1].seg + (iStack_4 + 0x1c) * 0xc);
      ((far_t *)(BldGfxNormal + 2) + (iStack_4 + 0x1c) * 3)->ofs = uVar8;
      iStack_4 = iStack_4 + 1;
    }
    if (param_1._0_1_ != false) {
      ovr_stgFreeTmp(uStack_c);
      uStack_c = ovr_grabLbmTR(175);
    }
    iStack_4 = 0;
    while( true ) {
      if (2 < iStack_4) break;
      if (param_1._0_1_ == false) {
        uVar17 = func_0x0007ffe0();
        *(undefined2 *)((int)&BldGfxRuin[1].seg + (iStack_4 + 0x1c) * 0xc) =
             (int)((ulong)uVar17 >> 0x10);
        ((far_t *)(BldGfxRuin + 1) + (iStack_4 + 0x1c) * 3)->ofs = (uint16_t)uVar17;
      }
      else {
        pixels_77.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
        pixels_77.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
        puVar15 = (uint8_t *)
                  ovr_stshRleType2(pixels_77,iStack_4 * 100 + 0x14,33,iStack_4 * 100 + 99,116,8,28);
        pcVar16 = ovr_stshStoreFile(puVar15);
        *(undefined2 *)((int)&BldGfxRuin[1].seg + (iStack_4 + 0x1c) * 0xc) =
             (int)((ulong)pcVar16 >> 0x10);
        ((far_t *)(BldGfxRuin + 1) + (iStack_4 + 0x1c) * 3)->ofs = (uint16_t)(cte_t *)pcVar16;
      }
      uVar8 = ((far_t *)(BldGfxRuin + 1) + (iStack_4 + 0x1c) * 3)->ofs;
      *(undefined2 *)((int)&BldGfxRuin[0].seg + (iStack_4 + 0x1c) * 0xc) =
           *(undefined2 *)((int)&BldGfxRuin[1].seg + (iStack_4 + 0x1c) * 0xc);
      ((far_t *)BldGfxRuin + (iStack_4 + 0x1c) * 3)->ofs = uVar8;
      uVar8 = ((far_t *)(BldGfxRuin + 1) + (iStack_4 + 0x1c) * 3)->ofs;
      *(undefined2 *)((int)&BldGfxRuin[2].seg + (iStack_4 + 0x1c) * 0xc) =
           *(undefined2 *)((int)&BldGfxRuin[1].seg + (iStack_4 + 0x1c) * 0xc);
      ((far_t *)(BldGfxRuin + 2) + (iStack_4 + 0x1c) * 3)->ofs = uVar8;
      iStack_4 = iStack_4 + 1;
    }
    if (param_1._0_1_ != false) {
      ovr_stgFreeTmp(uStack_c);
    }
    iVar11 = 0x1f;
    if (param_1._0_1_ != false) {
      uStack_c = ovr_grabLbmTR(174);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_78.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_78.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_78,100,130,199,194,26,-4);
      BldGfxNormal[0x5e] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_79.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_79.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_79,100,65,199,129,26,-4);
      BldGfxNormal[0x61] = (far_t)ovr_stshStoreFile(puVar15);
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_80.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_80.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)ovr_stshRleType2(pixels_80,100,0,199,64,26,-4);
      BldGfxNormal[100] = (far_t)ovr_stshStoreFile(puVar15);
      goto code_r0x00072658;
    }
    BldGfxNormal[0x5e] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x61] = (far_t)func_0x0007ffe0();
    BldGfxNormal[100] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x5e] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x61] = (far_t)func_0x0007ffe0();
    BldGfxRuin[100] = (far_t)func_0x0007ffe0();
  }
  ovr_stshStubifyCopy1to0();
  if (param_1._0_1_ == false) {
    stshStubifyBld(0x22);
    stshStubifyBld(0x25);
    stshStubifyBld(0x28);
    stshStubifyBld(0x2b);
    BldGfxNormal[0x8b] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x8e] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x91] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x94] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x97] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x9a] = (far_t)func_0x0007ffe0();
  }
  else {
    ovr_grabBldLbm(449,450,0x22);
    ovr_grabBldLbm(390,391,0x25);
    ovr_grabBldLbm(389,442,0x28);
    psVar19 = ovr_grabLbmTR(394);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    pixels_84.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_84.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_84,6,151,91,180,-10,-26);
    BldGfxNormal[0x81] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_85.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_85.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_85,110,151,185,180,-10,-26);
    BldGfxNormal[0x82] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_86.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_86.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_86,216,151,299,180,-10,-26);
    BldGfxNormal[0x83] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_87.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_87.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_87,6,72,91,115,-10,-12);
    BldGfxNormal[0x84] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_88.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_88.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_88,110,72,185,115,-10,-12);
    BldGfxNormal[0x85] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_89.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_89.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_89,216,72,299,115,-10,-12);
    BldGfxNormal[0x86] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_90.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_90.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_90,6,6,91,59,-10,-4);
    BldGfxNormal[0x87] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_91.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_91.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_91,110,6,185,59,-10,-4);
    BldGfxNormal[0x88] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_92.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_92.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_92,216,6,299,59,-10,-4);
    BldGfxNormal[0x89] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    uStack_c = ovr_grabLbmTR(443);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_93.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_93.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_93,6,151,91,180,-10,-26);
    BldGfxRuin[0x81] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_94.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_94.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_94,110,151,185,180,-10,-26);
    BldGfxRuin[0x82] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_95.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_95.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_95,216,151,299,180,-10,-26);
    BldGfxRuin[0x83] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_96.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_96.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_96,6,72,91,115,-10,-12);
    BldGfxRuin[0x84] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_97.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_97.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_97,110,72,185,115,-10,-12);
    BldGfxRuin[0x85] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_98.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_98.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_98,216,72,299,115,-10,-12);
    BldGfxRuin[0x86] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_99.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_99.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_99,6,6,91,59,-10,-4);
    BldGfxRuin[0x87] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00100.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00100.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00100,110,6,185,59,-10,-4);
    BldGfxRuin[0x88] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00101.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00101.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00101,216,6,299,59,-10,-4);
    BldGfxRuin[0x89] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
    uStack_c = ovr_grabLbmTR(173);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00102.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00102.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00102,0,130,99,194,26,0);
    BldGfxNormal[0x8b] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00103.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00103.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00103,100,130,199,194,26,0);
    BldGfxNormal[0x8e] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00104.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00104.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00104,200,130,299,194,26,0);
    BldGfxNormal[0x91] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00105.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00105.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00105,0,65,99,129,26,0);
    BldGfxNormal[0x94] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00106.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00106.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00106,100,65,199,129,26,0);
    BldGfxNormal[0x97] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00107.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00107.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00107,200,65,299,129,26,0);
    BldGfxNormal[0x9a] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
  }
  ovr_stshStubifyCopy1to0();
  ovr_stshStubifyCopy1to0();
  if (param_1._0_1_ == false) {
    stshStubifyBld(0x34);
    stshStubifyBld(0x37);
    BldGfxNormal[0xaf] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0xb2] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0xb5] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0xaf] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0xb2] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0xb5] = (far_t)func_0x0007ffe0();
  }
  else {
    ovr_grabBldLbm(314,315,0x34);
    ovr_grabBldLbm(316,317,0x37);
    psVar19 = ovr_grabLbmTR(320);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    pixels_x00108.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00108.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00108,58,141,134,199,-4,0);
    BldGfxNormal[0xaf] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00109.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00109.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00109,58,84,134,142,-4,0);
    BldGfxNormal[0xb2] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00110.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00110.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00110,58,25,134,83,-4,0);
    BldGfxNormal[0xb5] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    uStack_c = ovr_grabLbmTR(321);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00111.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00111.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00111,58,141,134,199,-4,0);
    BldGfxRuin[0xaf] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00112.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00112.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00112,58,84,134,142,-4,0);
    BldGfxRuin[0xb2] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00113.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00113.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00113,58,25,134,83,-4,0);
    BldGfxRuin[0xb5] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
  }
  ovr_stshStubifyCopy1to0();
  if (param_1._0_1_ != false) {
    uStack_c = ovr_grabLbmTR(500);
  }
  iVar11 = 0;
  while( true ) {
    if (3 < iVar11) break;
    if (param_1._0_1_ == false) {
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xb7].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb7) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xb8].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb8) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xb9].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb9) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
    }
    else {
      pixels_x00114.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00114.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00114,iVar11 * 0x30 + 3,0,iVar11 * 0x30 + 0x32,54,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xb7].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb7) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_x00115.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00115.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00115,iVar11 * 0x30 + 3,62,iVar11 * 0x30 + 0x32,116,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xb8].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb8) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_x00116.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00116.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00116,iVar11 * 0x30 + 3,62,iVar11 * 0x30 + 0x32,116,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xb9].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xb9) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
    }
    iVar11 = iVar11 + 1;
  }
  if (param_1._0_1_ != false) {
    ovr_stgFreeTmp(uStack_c);
    uStack_c = ovr_grabLbmTR(501);
  }
  iVar11 = 0;
  while( true ) {
    if (3 < iVar11) break;
    if (param_1._0_1_ == false) {
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xba].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xba) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xbb].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbb) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xbc].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbc) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
    }
    else {
      pixels_x00117.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00117.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00117,iVar11 * 0x30 + 3,0,iVar11 * 0x30 + 0x32,54,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xba].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xba) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_x00118.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00118.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00118,iVar11 * 0x30 + 3,62,iVar11 * 0x30 + 0x32,116,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xbb].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbb) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_x00119.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00119.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00119,iVar11 * 0x30 + 3,62,iVar11 * 0x30 + 0x32,116,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xbc].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbc) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
    }
    iVar11 = iVar11 + 1;
  }
  if (param_1._0_1_ != false) {
    ovr_stgFreeTmp(uStack_c);
    uStack_c = ovr_grabLbmTR(502);
  }
  iVar11 = 0;
  while( true ) {
    if (3 < iVar11) break;
    if (param_1._0_1_ == false) {
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xbd].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbd) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xbe].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbe) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xbf].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbf) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
    }
    else {
      pixels_x00120.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00120.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00120,iVar11 * 0x30 + 3,0,iVar11 * 0x30 + 0x32,54,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xbd].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbd) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_x00121.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00121.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00121,iVar11 * 0x30 + 3,62,iVar11 * 0x30 + 0x32,116,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xbe].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbe) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_x00122.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00122.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00122,iVar11 * 0x30 + 3,62,iVar11 * 0x30 + 0x32,116,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xbf].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xbf) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
    }
    iVar11 = iVar11 + 1;
  }
  if (param_1._0_1_ != false) {
    ovr_stgFreeTmp(uStack_c);
    uStack_c = ovr_grabLbmTR(503);
  }
  iVar11 = 0;
  while( true ) {
    if (3 < iVar11) break;
    if (param_1._0_1_ == false) {
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xc0].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc0) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xc1].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc1) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xc2].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc2) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
    }
    else {
      pixels_x00123.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00123.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00123,iVar11 * 0x30 + 3,0,iVar11 * 0x30 + 0x32,54,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xc0].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc0) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_x00124.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00124.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00124,iVar11 * 0x30 + 3,62,iVar11 * 0x30 + 0x32,116,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xc1].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc1) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_x00125.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00125.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00125,iVar11 * 0x30 + 3,62,iVar11 * 0x30 + 0x32,116,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xc2].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc2) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
    }
    iVar11 = iVar11 + 1;
  }
  if (param_1._0_1_ != false) {
    ovr_stgFreeTmp(uStack_c);
    uStack_c = ovr_grabLbmTR(504);
  }
  iVar11 = 0;
  while( true ) {
    if (3 < iVar11) break;
    if (param_1._0_1_ == false) {
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xc3].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc3) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xc4].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc4) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xc5].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc5) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
    }
    else {
      pixels_x00126.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00126.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00126,iVar11 * 0x30 + 3,0,iVar11 * 0x30 + 0x32,54,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xc3].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc3) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_x00127.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00127.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00127,iVar11 * 0x30 + 3,62,iVar11 * 0x30 + 0x32,116,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xc4].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc4) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_x00128.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00128.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00128,iVar11 * 0x30 + 3,62,iVar11 * 0x30 + 0x32,116,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xc5].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc5) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
    }
    iVar11 = iVar11 + 1;
  }
  if (param_1._0_1_ != false) {
    ovr_stgFreeTmp(uStack_c);
    uStack_c = ovr_grabLbmTR(505);
  }
  iVar11 = 0;
  while( true ) {
    if (3 < iVar11) break;
    if (param_1._0_1_ == false) {
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[0xc6].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc6) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[199].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 199) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
      uVar17 = func_0x0007ffe0();
      *(undefined2 *)((int)&BldGfxNormal[200].seg + iVar11 * 0x48) = (int)((ulong)uVar17 >> 0x10);
      ((far_t *)(BldGfxNormal + 200) + iVar11 * 0x12)->ofs = (uint16_t)uVar17;
    }
    else {
      pixels_x00129.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00129.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00129,iVar11 * 0x30 + 3,0,iVar11 * 0x30 + 0x32,54,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[0xc6].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 0xc6) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_x00130.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00130.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00130,iVar11 * 0x30 + 3,62,iVar11 * 0x30 + 0x32,116,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[199].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 199) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_x00131.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00131.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00131,iVar11 * 0x30 + 3,62,iVar11 * 0x30 + 0x32,116,0,1);
      pcVar16 = ovr_stshStoreFile(puVar15);
      *(undefined2 *)((int)&BldGfxNormal[200].seg + iVar11 * 0x48) = (int)((ulong)pcVar16 >> 0x10);
      ((far_t *)(BldGfxNormal + 200) + iVar11 * 0x12)->ofs = (uint16_t)(cte_t *)pcVar16;
    }
    iVar11 = iVar11 + 1;
  }
  if (param_1._0_1_ != false) {
    ovr_stgFreeTmp(uStack_c);
  }
  for (iStack_4 = 0; iStack_4 < 0x12; iStack_4 = iStack_4 + 1) {
    ovr_stshStubifyFromSrc((char)(iStack_4 + 0x43));
  }
  if (param_1._0_1_ != false) {
    uStack_c = ovr_grabLbmTR(11);
  }
  for (iVar11 = 0; iVar11 < 3; iVar11 = iVar11 + 1) {
    for (iStack_4 = 0; iStack_4 < 3; iStack_4 = iStack_4 + 1) {
      if (param_1._0_1_ == false) {
        uVar17 = func_0x0007ffe0();
        iVar12 = iVar11 * 3 + iStack_4;
        *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar12 * 0xc) = (int)((ulong)uVar17 >> 0x10)
        ;
        ((far_t *)(BldGfxNormal + 0x135) + iVar12 * 3)->ofs = (uint16_t)uVar17;
      }
      else {
        uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
        pixels_x00132.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
        pixels_x00132.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
        puVar15 = (uint8_t *)
                  ovr_stshRleType2(pixels_x00132,iStack_4 * 100,iVar11 * 0x41,iStack_4 * 100 + 99,
                                   iVar11 * 0x41 + 0x40,30,-4);
        pcVar16 = ovr_stshStoreFile(puVar15);
        iVar12 = iVar11 * 3 + iStack_4;
        *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar12 * 0xc) =
             (int)((ulong)pcVar16 >> 0x10);
        ((far_t *)(BldGfxNormal + 0x135) + iVar12 * 3)->ofs = (uint16_t)(cte_t *)pcVar16;
      }
      iVar12 = iVar11 * 3 + iStack_4;
      uVar8 = ((far_t *)(BldGfxNormal + 0x135) + iVar12 * 3)->ofs;
      iVar10 = iVar11 * 3 + iStack_4;
      *(undefined2 *)((int)&BldGfxNormal[0x136].seg + iVar10 * 0xc) =
           *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar12 * 0xc);
      ((far_t *)(BldGfxNormal + 0x136) + iVar10 * 3)->ofs = uVar8;
      iVar12 = iVar11 * 3 + iStack_4;
      uVar8 = ((far_t *)(BldGfxNormal + 0x135) + iVar12 * 3)->ofs;
      iVar10 = iVar11 * 3 + iStack_4;
      *(undefined2 *)((int)&BldGfxNormal[0x137].seg + iVar10 * 0xc) =
           *(undefined2 *)((int)&BldGfxNormal[0x135].seg + iVar12 * 0xc);
      ((far_t *)(BldGfxNormal + 0x137) + iVar10 * 3)->ofs = uVar8;
    }
  }
  if (param_1._0_1_ == false) {
    BldGfxNormal[0x151] = (far_t)func_0x0007ffe0();
  }
  else {
    ovr_stgFreeTmp(uStack_c);
    uStack_c = ovr_grabLbmTR(52);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00133.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00133.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00133,167,12,206,32,-4,-37);
    BldGfxNormal[0x151] = (far_t)ovr_stshStoreFile(puVar15);
  }
  ovr_StubifyCopy1to0_alt();
  if (param_1._0_1_ == false) {
    BldGfxNormal[0x154] = (far_t)func_0x0007ffe0();
  }
  else {
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00134.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00134.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00134,167,45,206,65,-4,-37);
    BldGfxNormal[0x154] = (far_t)ovr_stshStoreFile(puVar15);
  }
  ovr_StubifyCopy1to0_alt();
  if (param_1._0_1_ == false) {
    BldGfxNormal[0x157] = (far_t)func_0x0007ffe0();
  }
  else {
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00135.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00135.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00135,167,78,206,98,-4,-37);
    BldGfxNormal[0x157] = (far_t)ovr_stshStoreFile(puVar15);
  }
  ovr_StubifyCopy1to0_alt();
  if (param_1._0_1_ == false) {
    for (iStack_4 = 0; iStack_4 < 6; iStack_4 = iStack_4 + 1) {
      uVar17 = func_0x0007ffe0();
      uVar8 = AnimSeqPtr[1].seg;
      puVar9 = (undefined2 *)(AnimSeqPtr[1].ofs + iStack_4 * 4);
      puVar9[1] = (int)((ulong)uVar17 >> 0x10);
      *puVar9 = (int)uVar17;
      uVar17 = func_0x0007ffe0();
      uVar8 = AnimSeqPtr[2].seg;
      puVar9 = (undefined2 *)(AnimSeqPtr[2].ofs + iStack_4 * 4);
      puVar9[1] = (int)((ulong)uVar17 >> 0x10);
      *puVar9 = (int)uVar17;
    }
    uVar17 = func_0x0007ffe0();
    uVar14 = AnimSeqPtr[1].seg;
    uVar8 = AnimSeqPtr[1].ofs;
    *(undefined2 *)(uVar8 + 0x1a) = (int)((ulong)uVar17 >> 0x10);
    *(undefined2 *)(uVar8 + 0x18) = (int)uVar17;
    uVar17 = func_0x0007ffe0();
    uVar14 = AnimSeqPtr[2].seg;
    uVar8 = AnimSeqPtr[2].ofs;
    *(undefined2 *)(uVar8 + 0x1a) = (int)((ulong)uVar17 >> 0x10);
    *(undefined2 *)(uVar8 + 0x18) = (int)uVar17;
  }
  else {
    iStack_4 = 0;
    while( true ) {
      psVar7 = (stg_tmp_t *)uStack_c;
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      if (5 < iStack_4) break;
      pixels_x00136.seg = (psVar7->aptr).seg;
      pixels_x00136.ofs = (&psVar7->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00136,13,iStack_4 * 0x21 + 0x14,16,iStack_4 * 0x21 + 0x20,
                                 -22,-44);
      pcVar16 = ovr_stshStoreFile(puVar15);
      uVar8 = AnimSeqPtr[1].seg;
      puVar9 = (undefined2 *)(AnimSeqPtr[1].ofs + iStack_4 * 4);
      puVar9[1] = (int)((ulong)pcVar16 >> 0x10);
      *puVar9 = (cte_t *)pcVar16;
      uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
      pixels_x00137.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00137.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00137,95,iStack_4 * 0x21 + 0x14,98,iStack_4 * 0x21 + 0x20,
                                 -22,-44);
      pcVar16 = ovr_stshStoreFile(puVar15);
      uVar8 = AnimSeqPtr[2].seg;
      puVar9 = (undefined2 *)(AnimSeqPtr[2].ofs + iStack_4 * 4);
      puVar9[1] = (int)((ulong)pcVar16 >> 0x10);
      *puVar9 = (cte_t *)pcVar16;
      iStack_4 = iStack_4 + 1;
    }
    pixels_x00138.seg = (psVar7->aptr).seg;
    pixels_x00138.ofs = (&psVar7->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00138,43,20,46,32,-22,-44);
    pcVar16 = ovr_stshStoreFile(puVar15);
    uVar14 = AnimSeqPtr[1].seg;
    uVar8 = AnimSeqPtr[1].ofs;
    *(undefined2 *)(uVar8 + 0x1a) = (int)((ulong)pcVar16 >> 0x10);
    *(undefined2 *)(uVar8 + 0x18) = (cte_t *)pcVar16;
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00139.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00139.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00139,125,20,128,32,-22,-44);
    pcVar16 = ovr_stshStoreFile(puVar15);
    uVar14 = AnimSeqPtr[2].seg;
    uVar8 = AnimSeqPtr[2].ofs;
    *(undefined2 *)(uVar8 + 0x1a) = (int)((ulong)pcVar16 >> 0x10);
    *(undefined2 *)(uVar8 + 0x18) = (cte_t *)pcVar16;
    ovr_stgFreeTmp(uStack_c);
  }
  builtin_memcpy(&ram0x0000d528 + 0x153,"\x02\x02\x02\x03\x03\x03",6);
  if (param_1._0_1_ == false) {
    BldGfxNormal[0x15a] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x15d] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x160] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x15a] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x15d] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x160] = (far_t)func_0x0007ffe0();
  }
  else {
    psVar19 = ovr_grabLbmTR(308);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    pixels_x00140.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00140.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00140,2,86,85,180,-2,38);
    BldGfxNormal[0x15a] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00141.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00141.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00141,108,86,191,180,-2,38);
    BldGfxNormal[0x15d] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00142.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00142.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00142,208,86,298,180,0,38);
    BldGfxNormal[0x160] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    uStack_c = ovr_grabLbmTR(309);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00143.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00143.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00143,2,86,85,180,-2,38);
    BldGfxRuin[0x15a] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00144.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00144.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00144,108,86,191,180,-2,38);
    BldGfxRuin[0x15d] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00145.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00145.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00145,208,86,298,180,0,38);
    BldGfxRuin[0x160] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
  }
  ovr_stshStubifyCopy1to0();
  if (param_1._0_1_ == false) {
    BldGfxNormal[0x163] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x166] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x169] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x163] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x166] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x169] = (far_t)func_0x0007ffe0();
  }
  else {
    psVar19 = ovr_grabLbmTR(467);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    pixels_x00146.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00146.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00146,4,74,91,180,-3,50);
    BldGfxNormal[0x163] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00147.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00147.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00147,110,74,195,180,-3,50);
    BldGfxNormal[0x166] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00148.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00148.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00148,204,74,299,180,3,50);
    BldGfxNormal[0x169] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    uStack_c = ovr_grabLbmTR(468);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00149.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00149.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00149,4,74,91,180,-3,50);
    BldGfxRuin[0x163] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00150.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00150.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00150,110,74,195,180,-3,50);
    BldGfxRuin[0x166] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00151.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00151.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00151,204,74,299,180,3,50);
    BldGfxRuin[0x169] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
  }
  ovr_stshStubifyCopy1to0();
  ovr_stubyBufSrcToDst(0x76);
  ovr_stubyBufSrcToDst(0x73);
  ovr_stubyBufSrcToDst(0x76);
  if (param_1._0_1_ == false) {
    BldGfxNormal[0x186] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x187] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x188] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x186] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x187] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x188] = (far_t)func_0x0007ffe0();
  }
  else {
    psVar19 = ovr_grabLbmTR(513);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    pixels_x00152.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00152.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00152,2,70,86,180,0,52);
    BldGfxNormal[0x186] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00153.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00153.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00153,108,70,191,180,0,52);
    BldGfxNormal[0x187] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00154.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00154.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00154,215,70,298,180,0,52);
    BldGfxNormal[0x188] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    uStack_c = ovr_grabLbmTR(514);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00155.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00155.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00155,2,70,86,180,0,52);
    BldGfxRuin[0x186] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00156.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00156.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00156,108,70,191,180,0,52);
    BldGfxRuin[0x187] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00157.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00157.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00157,215,70,298,180,0,52);
    BldGfxRuin[0x188] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
  }
  iVar11 = 0x83;
  if (param_1._0_1_ == false) {
    uVar17 = func_0x0007ffe0();
    unaff_DI = (undefined2)((ulong)uVar17 >> 0x10);
    uVar21 = (undefined1)uVar17;
    uVar22 = (undefined1)((ulong)uVar17 >> 8);
    pcVar4 = (char *)((int)(uint32_t *)&_StartTime + 2);
    iVar10 = 0xc;
    uVar1 = 0x4c;
code_r0x00074dd0:
    uVar6 = uVar1;
    pcVar4 = (char *)((int)pcVar4 * iVar10);
    goto code_r0x00074dd2;
  }
  psVar19 = ovr_grabLbmTR(517);
  uStack_c._0_2_ = (stg_tmp_t *)psVar19;
  uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
  pixels_x00158.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
  pixels_x00158.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
  puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00158,2,70,86,180,0,52);
  BldGfxNormal[0x189] = (far_t)ovr_stshStoreFile(puVar15);
  pixels_x00159.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
  pixels_x00159.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
  puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00159,108,70,191,180,0,52);
  BldGfxNormal[0x18a] = (far_t)ovr_stshStoreFile(puVar15);
  pixels_x00160.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
  pixels_x00160.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
  puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00160,215,70,298,180,0,52);
  BldGfxNormal[0x18b] = (far_t)ovr_stshStoreFile(puVar15);
  ovr_stgFreeTmp((stg_tmp_t *)
                 CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                          CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
  uStack_c = ovr_grabLbmTR(518);
  uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
  pixels_x00161.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
  pixels_x00161.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
  puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00161,2,70,86,180,0,52);
  BldGfxRuin[0x189] = (far_t)ovr_stshStoreFile(puVar15);
  uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
  pixels_x00162.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
  pixels_x00162.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
  puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00162,108,70,191,180,0,52);
  BldGfxRuin[0x18a] = (far_t)ovr_stshStoreFile(puVar15);
  uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
  pixels_x00163.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
  pixels_x00163.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
  puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00163,215,70,298,180,0,52);
  BldGfxRuin[0x18b] = (far_t)ovr_stshStoreFile(puVar15);
  ovr_stgFreeTmp(uStack_c);
LAB_6ffe_4ea5:
  if (param_1._0_1_ == false) {
    BldGfxNormal[0x18d] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x18d] = (far_t)func_0x0007ffe0();
  }
  else {
    psVar19 = ovr_grabLbmTR(525);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    pixels_x00164.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00164.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00164,108,70,191,180,0,52);
    BldGfxNormal[0x18d] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    uStack_c = ovr_grabLbmTR(526);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00165.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00165.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00165,108,70,191,180,0,52);
    BldGfxRuin[0x18d] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
  }
  BldGfxNormal[0x18c].ofs = BldGfxNormal[0x18d].ofs;
  BldGfxNormal[0x18c].seg = BldGfxNormal[0x18d].seg;
  BldGfxNormal[0x18e].ofs = BldGfxNormal[0x18d].ofs;
  BldGfxNormal[0x18e].seg = BldGfxNormal[0x18d].seg;
  BldGfxRuin[0x18c].ofs = BldGfxRuin[0x18d].ofs;
  BldGfxRuin[0x18c].seg = BldGfxRuin[0x18d].seg;
  BldGfxRuin[0x18e].ofs = BldGfxRuin[0x18d].ofs;
  BldGfxRuin[0x18e].seg = BldGfxRuin[0x18d].seg;
  if (param_1._0_1_ == false) {
    BldGfxNormal[399] = (far_t)func_0x0007ffe0();
    BldGfxNormal[400] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x191] = (far_t)func_0x0007ffe0();
    BldGfxRuin[399] = (far_t)func_0x0007ffe0();
    BldGfxRuin[400] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x191] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x193] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x193] = (far_t)func_0x0007ffe0();
  }
  else {
    psVar19 = ovr_grabLbmTR(515);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    pixels_x00166.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00166.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00166,2,70,86,180,0,52);
    BldGfxNormal[399] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00167.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00167.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00167,108,70,191,180,0,52);
    BldGfxNormal[400] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00168.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00168.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00168,215,70,298,180,0,52);
    BldGfxNormal[0x191] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    uStack_c = ovr_grabLbmTR(516);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00169.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00169.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00169,2,70,86,180,0,52);
    BldGfxRuin[399] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00170.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00170.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00170,108,70,191,180,0,52);
    BldGfxRuin[400] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00171.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00171.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00171,215,70,298,180,0,52);
    BldGfxRuin[0x191] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
    psVar19 = ovr_grabLbmTR(519);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    pixels_x00172.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00172.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00172,108,70,191,180,0,52);
    BldGfxNormal[0x193] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    uStack_c = ovr_grabLbmTR(520);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00173.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00173.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00173,108,70,191,180,0,52);
    BldGfxRuin[0x193] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
  }
  BldGfxNormal[0x192].ofs = BldGfxNormal[0x193].ofs;
  BldGfxNormal[0x192].seg = BldGfxNormal[0x193].seg;
  BldGfxNormal[0x194].ofs = BldGfxNormal[0x193].ofs;
  BldGfxNormal[0x194].seg = BldGfxNormal[0x193].seg;
  BldGfxRuin[0x192].ofs = BldGfxRuin[0x193].ofs;
  BldGfxRuin[0x192].seg = BldGfxRuin[0x193].seg;
  BldGfxRuin[0x194].ofs = BldGfxRuin[0x193].ofs;
  BldGfxRuin[0x194].seg = BldGfxRuin[0x193].seg;
  if (param_1._0_1_ == false) {
    BldGfxNormal[0x196] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x196] = (far_t)func_0x0007ffe0();
  }
  else {
    psVar19 = ovr_grabLbmTR(521);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    pixels_x00174.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00174.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00174,108,70,191,180,0,52);
    BldGfxNormal[0x196] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    uStack_c = ovr_grabLbmTR(522);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00175.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00175.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00175,108,70,191,180,0,52);
    BldGfxRuin[0x196] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
  }
  BldGfxNormal[0x195].ofs = BldGfxNormal[0x196].ofs;
  BldGfxNormal[0x195].seg = BldGfxNormal[0x196].seg;
  BldGfxNormal[0x197].ofs = BldGfxNormal[0x196].ofs;
  BldGfxNormal[0x197].seg = BldGfxNormal[0x196].seg;
  BldGfxRuin[0x195].ofs = BldGfxRuin[0x196].ofs;
  BldGfxRuin[0x195].seg = BldGfxRuin[0x196].seg;
  BldGfxRuin[0x197].ofs = BldGfxRuin[0x196].ofs;
  BldGfxRuin[0x197].seg = BldGfxRuin[0x196].seg;
  if (param_1._0_1_ == false) {
    for (iStack_4 = 0; iStack_4 < 5; iStack_4 = iStack_4 + 1) {
      uVar17 = func_0x0007ffe0();
      uVar8 = AnimSeqPtr[0].seg;
      puVar9 = (undefined2 *)(AnimSeqPtr[0].ofs + iStack_4 * 4);
      puVar9[1] = (int)((ulong)uVar17 >> 0x10);
      *puVar9 = (int)uVar17;
    }
    BldGfxNormal[0x199] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x199] = (far_t)func_0x0007ffe0();
  }
  else {
    psVar19 = ovr_grabLbmTR(523);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    for (iStack_4 = 0; iStack_4 < 5; iStack_4 = iStack_4 + 1) {
      pixels_x00176.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
      pixels_x00176.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
      puVar15 = (uint8_t *)
                ovr_stshRleType2(pixels_x00176,iStack_4 * 0x22 + 0x50,39,iStack_4 * 0x22 + 0x68,58,
                                 -68,22);
      pcVar16 = ovr_stshStoreFile(puVar15);
      uVar8 = AnimSeqPtr[0].seg;
      puVar9 = (undefined2 *)(AnimSeqPtr[0].ofs + iStack_4 * 4);
      puVar9[1] = (int)((ulong)pcVar16 >> 0x10);
      *puVar9 = (cte_t *)pcVar16;
    }
    pixels_x00177.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00177.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00177,82,87,222,181,22,32);
    BldGfxNormal[0x199] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    uStack_c = ovr_grabLbmTR(524);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00178.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00178.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00178,82,87,222,181,22,32);
    BldGfxRuin[0x199] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
  }
  ovr_StubifyCopy1to0_alt();
  BldFlags[0x198] = 0x1;
  BldFlags[0x199] = 0x1;
  BldFlags[0x19a] = 0x1;
  if (param_1._0_1_ == false) {
    BldGfxNormal[0x19c] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x19f] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x19c] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x19f] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1a2] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x1a2] = (far_t)func_0x0007ffe0();
  }
  else {
    psVar19 = ovr_grabLbmTR(156);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    pixels_x00179.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00179.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00179,0,101,319,199,60,26);
    BldGfxNormal[0x19c] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00180.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00180.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00180,0,0,319,100,60,28);
    BldGfxNormal[0x19f] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    psVar19 = ovr_grabLbmTR(441);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    pixels_x00181.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00181.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00181,0,101,319,199,60,26);
    BldGfxRuin[0x19c] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00182.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00182.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00182,0,0,319,100,60,28);
    BldGfxRuin[0x19f] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    psVar19 = ovr_grabLbmTR(157);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    pixels_x00183.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00183.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00183,0,70,319,193,60,51);
    BldGfxNormal[0x1a2] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    uStack_c = ovr_grabLbmTR(440);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00184.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00184.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00184,0,70,319,193,60,51);
    BldGfxRuin[0x1a2] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
  }
  ovr_stshStubifyCopy1to0();
  ovr_stubyBufSrcToDst(0x73);
  if (param_1._0_1_ == false) {
    BldGfxNormal[0x1ae] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1b1] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1b4] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x1ae] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x1b1] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x1b4] = (far_t)func_0x0007ffe0();
  }
  else {
    psVar19 = ovr_grabLbmTR(318);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    pixels_x00185.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00185.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00185,8,50,110,154,-4,45);
    BldGfxNormal[0x1ae] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00186.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00186.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00186,111,50,212,154,-4,45);
    BldGfxNormal[0x1b1] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00187.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00187.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00187,213,50,313,154,-4,45);
    BldGfxNormal[0x1b4] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    uStack_c = ovr_grabLbmTR(319);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00188.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00188.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00188,8,50,110,154,-4,45);
    BldGfxRuin[0x1ae] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00189.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00189.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00189,111,50,212,154,-4,45);
    BldGfxRuin[0x1b1] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00190.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00190.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00190,213,50,313,154,-4,45);
    BldGfxRuin[0x1b4] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
  }
  ovr_stshStubifyCopy1to0();
  iVar11 = 0x92;
  if (param_1._0_1_ != false) {
    uStack_c = ovr_grabLbm(17,0,0);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00199.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00199.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    ovr_grabRemap(pixels_x00199,0xff,0x0);
  }
  for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
    for (iStack_4 = 0; iStack_4 < 2; iStack_4 = iStack_4 + 1) {
      if ((iStack_4 != 0) || (iVar12 != 0)) {
        if (param_1._0_1_ == false) {
          uVar17 = func_0x0007ffe0();
          *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar11 * 0xc) = (int)((ulong)uVar17 >> 0x10);
          ((far_t *)BldGfxNormal + iVar11 * 3)->ofs = (uint16_t)uVar17;
        }
        else {
          uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
          pixels_x00191.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
          pixels_x00191.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
          puVar15 = (uint8_t *)
                    ovr_stshRleType2(pixels_x00191,iStack_4 * 0x87,iVar12 * 0x41,
                                     iStack_4 * 0x87 + 0x86,iVar12 * 0x41 + 0x40,30,-10);
          pcVar16 = ovr_stshStoreFile(puVar15);
          *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar11 * 0xc) = (int)((ulong)pcVar16 >> 0x10);
          ((far_t *)BldGfxNormal + iVar11 * 3)->ofs = (uint16_t)(cte_t *)pcVar16;
        }
        uVar8 = ((far_t *)BldGfxNormal + iVar11 * 3)->ofs;
        *(undefined2 *)((int)&BldGfxNormal[1].seg + iVar11 * 0xc) =
             *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar11 * 0xc);
        ((far_t *)(BldGfxNormal + 1) + iVar11 * 3)->ofs = uVar8;
        uVar8 = ((far_t *)BldGfxNormal + iVar11 * 3)->ofs;
        *(undefined2 *)((int)&BldGfxNormal[2].seg + iVar11 * 0xc) =
             *(undefined2 *)((int)&BldGfxNormal[0].seg + iVar11 * 0xc);
        ((far_t *)(BldGfxNormal + 2) + iVar11 * 3)->ofs = uVar8;
        iVar11 = iVar11 + 1;
      }
    }
  }
  if (param_1._0_1_ == false) {
    BldGfxNormal[0x1c5] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1c6] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1c7] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1c9] = BldGfxNormal[0x1c6];
    BldGfxNormal[0x1c8] = BldGfxNormal[0x1c5];
    BldGfxNormal[0x1ca] = BldGfxNormal[0x1c7];
    BldGfxNormal[0x1cb] = BldGfxNormal[0x1c8];
    BldGfxNormal[0x1cc] = BldGfxNormal[0x1c9];
    BldGfxNormal[0x1cd] = BldGfxNormal[0x1c7];
    BldGfxNormal[0x1ce] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1cf] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1d0] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1d5] = BldGfxNormal[0x1cf];
    BldGfxNormal[0x1d1] = BldGfxNormal[0x1ce];
    BldGfxNormal[0x1d3] = BldGfxNormal[0x1d0];
    BldGfxNormal[0x1d4] = BldGfxNormal[0x1d1];
    BldGfxNormal[0x1d6] = BldGfxNormal[0x1d0];
    BldGfxNormal[0x1d2] = BldGfxNormal[0x1d5];
    BldGfxNormal[0x1d7] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1d8] = BldGfxNormal[0x1d2];
    BldGfxNormal[0x1d9] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1da] = BldGfxNormal[0x1d7];
    BldGfxNormal[0x1dc] = BldGfxNormal[0x1d9];
    BldGfxNormal[0x1dd] = BldGfxNormal[0x1d7];
    BldGfxNormal[0x1df] = BldGfxNormal[0x1d9];
    BldGfxNormal[0x1db] = BldGfxNormal[0x1d8];
    BldGfxNormal[0x1de] = BldGfxNormal[0x1d8];
    BldGfxNormal[0x1e0] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1e1] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1e2] = (far_t)func_0x0007ffe0();
  }
  else {
    ovr_stgFreeTmp(uStack_c);
    uStack_c = ovr_grabLbmTR(31);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_07.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_07.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_07,0,18,200,33);
    BldGfxNormal[0x1c5] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_08.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_08.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_08,131,74,179,130);
    BldGfxNormal[0x1c6] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_09.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_09.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_09,31,49,79,55);
    BldGfxNormal[0x1c7] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_10.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_10.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    BldGfxNormal[0x1c8] = BldGfxNormal[0x1c5];
    BldGfxNormal[0x1c9] = BldGfxNormal[0x1c6];
    BldGfxNormal[0x1ca] = BldGfxNormal[0x1c7];
    BldGfxNormal[0x1cb] = BldGfxNormal[0x1c5];
    BldGfxNormal[0x1cc] = BldGfxNormal[0x1c6];
    BldGfxNormal[0x1cd] = BldGfxNormal[0x1c7];
    fVar18 = ovr_stshRleCut(src_10,0,49,200,65);
    BldGfxNormal[0x1ce] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_11.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_11.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_11,31,74,79,130);
    BldGfxNormal[0x1cf] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_12.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_12.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_12,131,49,179,55);
    BldGfxNormal[0x1d0] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_13.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_13.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    BldGfxNormal[0x1d1] = BldGfxNormal[0x1ce];
    BldGfxNormal[0x1d3] = BldGfxNormal[0x1d0];
    BldGfxNormal[0x1d4] = BldGfxNormal[0x1ce];
    BldGfxNormal[0x1d2] = BldGfxNormal[0x1cf];
    BldGfxNormal[0x1d6] = BldGfxNormal[0x1d0];
    BldGfxNormal[0x1d5] = BldGfxNormal[0x1cf];
    fVar18 = ovr_stshRleCut(src_13,0,1,200,17);
    BldGfxNormal[0x1d7] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_14.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_14.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    BldGfxNormal[0x1d8] = BldGfxNormal[0x1d2];
    fVar18 = ovr_stshRleCut(src_14,231,49,279,55);
    BldGfxNormal[0x1d9] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    BldGfxNormal[0x1da] = BldGfxNormal[0x1d7];
    BldGfxNormal[0x1dc] = BldGfxNormal[0x1d9];
    BldGfxNormal[0x1dd] = BldGfxNormal[0x1d7];
    BldGfxNormal[0x1df] = BldGfxNormal[0x1d9];
    BldGfxNormal[0x1db] = BldGfxNormal[0x1d8];
    BldGfxNormal[0x1de] = BldGfxNormal[0x1d8];
    ovr_stgFreeTmp(uStack_c);
    uStack_c = ovr_grabLbmTR(51);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_15.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_15.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_15,131,49,219,65);
    BldGfxNormal[0x1e0] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_16.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_16.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_16,131,74,179,130);
    BldGfxNormal[0x1e1] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_17.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_17.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_17,131,59,179,65);
    BldGfxNormal[0x1e2] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    ovr_stgFreeTmp(uStack_c);
  }
  BldGfxNormal[0x1e3].ofs = BldGfxNormal[0x1e0].ofs;
  BldGfxNormal[0x1e3].seg = BldGfxNormal[0x1e0].seg;
  BldGfxNormal[0x1e4].ofs = BldGfxNormal[0x1e1].ofs;
  BldGfxNormal[0x1e4].seg = BldGfxNormal[0x1e1].seg;
  BldGfxNormal[0x1e5].ofs = BldGfxNormal[0x1e2].ofs;
  BldGfxNormal[0x1e5].seg = BldGfxNormal[0x1e2].seg;
  if (param_1._0_1_ == false) {
    BldGfxNormal[0x1e6] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1e7] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1e8] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1ec] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1ed] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1ee] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1f2] = (far_t)func_0x0007ffe0();
    BldGfxNormal[499] = (far_t)func_0x0007ffe0();
    BldGfxNormal[500] = (far_t)func_0x0007ffe0();
  }
  else {
    uStack_c = ovr_grabLbmTR(288);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_18.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_18.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_18,0,51,200,65);
    BldGfxNormal[0x1e6] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_19.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_19.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_19,31,74,79,130);
    BldGfxNormal[0x1e7] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_20.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_20.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_20,0,51,48,57);
    BldGfxNormal[0x1e8] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_21.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_21.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_21,0,14,200,28);
    BldGfxNormal[0x1ec] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_22.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_22.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_22,131,74,179,130);
    BldGfxNormal[0x1ed] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_23.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_23.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_23,0,14,48,20);
    BldGfxNormal[0x1ee] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_24.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_24.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_24,0,168,200,195);
    BldGfxNormal[0x1f2] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    src_25.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    src_25.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    fVar18 = ovr_stshRleCut(src_25,231,74,279,130);
    BldGfxNormal[499] = (far_t)ovr_stshStoreFile((uint8_t *)fVar18);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00192.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00192.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00192,0,168,48,187,0,13);
    BldGfxNormal[500] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
  }
  BldGfxNormal[0x1ef].ofs = BldGfxNormal[0x1ec].ofs;
  BldGfxNormal[0x1ef].seg = BldGfxNormal[0x1ec].seg;
  BldGfxNormal[0x1f0].ofs = BldGfxNormal[0x1ed].ofs;
  BldGfxNormal[0x1f0].seg = BldGfxNormal[0x1ed].seg;
  BldGfxNormal[0x1f1].ofs = BldGfxNormal[0x1ee].ofs;
  BldGfxNormal[0x1f1].seg = BldGfxNormal[0x1ee].seg;
  BldGfxNormal[0x1f5].ofs = BldGfxNormal[0x1ec].ofs;
  BldGfxNormal[0x1f5].seg = BldGfxNormal[0x1ec].seg;
  BldGfxNormal[0x1f6].ofs = BldGfxNormal[0x1ed].ofs;
  BldGfxNormal[0x1f6].seg = BldGfxNormal[0x1ed].seg;
  BldGfxNormal[0x1f7].ofs = BldGfxNormal[0x1ee].ofs;
  BldGfxNormal[0x1f7].seg = BldGfxNormal[0x1ee].seg;
  BldGfxNormal[0x1e9] = BldGfxNormal[0x1e6];
  BldGfxNormal[0x1ea] = BldGfxNormal[0x1e7];
  BldGfxNormal[0x1eb] = BldGfxNormal[0x1e8];
  if (param_1._0_1_ == false) {
    BldGfxNormal[0x1f9] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1fc] = (far_t)func_0x0007ffe0();
    BldGfxNormal[0x1ff] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x1f9] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x1fc] = (far_t)func_0x0007ffe0();
    BldGfxRuin[0x1ff] = (far_t)func_0x0007ffe0();
  }
  else {
    psVar19 = ovr_grabLbmTR(462);
    uStack_c._0_2_ = (stg_tmp_t *)psVar19;
    uStack_c._2_2_ = (undefined2)((ulong)psVar19 >> 0x10);
    pixels_x00193.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00193.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00193,13,28,96,119,0,32);
    BldGfxNormal[0x1f9] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00194.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00194.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00194,119,28,202,119,0,32);
    BldGfxNormal[0x1fc] = (far_t)ovr_stshStoreFile(puVar15);
    pixels_x00195.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00195.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00195,226,28,309,119,0,32);
    BldGfxNormal[0x1ff] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp((stg_tmp_t *)
                   CONCAT13((char)((uint)uStack_c._2_2_ >> 8),
                            CONCAT12((char)uStack_c._2_2_,(stg_tmp_t *)uStack_c)));
    uStack_c = ovr_grabLbmTR(463);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00196.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00196.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00196,13,28,96,119,0,32);
    BldGfxRuin[0x1f9] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00197.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00197.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00197,119,28,202,119,0,32);
    BldGfxRuin[0x1fc] = (far_t)ovr_stshStoreFile(puVar15);
    uVar13 = (undefined2)((ulong)uStack_c >> 0x10);
    pixels_x00198.seg = (((stg_tmp_t *)uStack_c)->aptr).seg;
    pixels_x00198.ofs = (&((stg_tmp_t *)uStack_c)->aptr)->ofs;
    puVar15 = (uint8_t *)ovr_stshRleType2(pixels_x00198,226,28,309,119,0,32);
    BldGfxRuin[0x1ff] = (far_t)ovr_stshStoreFile(puVar15);
    ovr_stgFreeTmp(uStack_c);
  }
  ovr_stshStubifyCopy1to0();
  ovr_init_assets1(param_1._0_1_);
  ovr_init_assets2(param_1._0_1_);
  if (param_1._0_1_ != false) {
    sz = (DW)LXMUL_at_(0x15,(ulong)StshCount);
    buf.seg = StshCtPtr.seg;
    buf.ofs = StshCtPtr.ofs;
    ovr_stshWriteFile(StshFile,buf,sz);
    lseek(StshFile,0,0);
    write(StshFile,(DW *)&StshCtOfs,4);
    close(StshFile);
    if (StshCount != 0xd93) {
      printf("getcache %d  SIZESTASH %d  \r",StshCount);
      ovr_biosReadKey();
    }
  }
  uVar13 = stshInitPtrs();
  return uVar13;
}




/* 77eb:16b2 */

undefined2 __cdecl16far OVC45_77eb_16b2(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  uint16_t uVar4;
  
  if (*(char *)(Entities.ofs + param_1 * 0x37 + 0x1a) == -1) {
    uVar3 = 0;
  }
  else {
    uVar2 = *(undefined4 *)((uint)*(byte *)(Entities.ofs + param_1 * 0x37 + 0x1a) << 2);
    cVar1 = *(char *)((int)uVar2 + 0x2f);
    if (cVar1 == '\x04') {
      uVar4 = ovr_randBelow(5);
      if ((byte)uVar4 < 4) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
    else if (cVar1 == '\x05') {
      uVar4 = ovr_randBelow(3);
      if ((char)uVar4 == '\0') {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar4 = ovr_randBelow(4);
      if ((byte)uVar4 < 2) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}



/* 77eb:1754 */

void __cdecl16far
OVC45_77eb_1754(char param_1,byte param_2,int param_3,undefined2 param_4,undefined2 param_5,
               undefined2 param_6)

{
  undefined2 uVar1;
  char cVar2;
  undefined2 uVar3;
  char *pcVar4;
  uint16_t uVar5;
  int iVar6;
  undefined2 unaff_SS;
  undefined4 uVar7;
  char *local_290 [4];
  char *pcStack_288;
  char *pcStack_286;
  char local_268 [512];
  undefined1 local_68 [81];
  char cStack_17;
  char cStack_16;
  byte bStack_15;
  char *local_14;
  char *pcStack_12;
  char *pcStack_10;
  undefined2 uStack_e;
  undefined1 auStack_c [10];
  
  uVar1 = param_4;
  local_290[1] = (char *)"puppetmaker" + 3;
  local_290[0] = (char *)"Excavate";
  auStack_c[0] = 1;
  if (*(int *)((uint)param_2 * 0x27 + 0x116) == 0 && *(int *)((uint)param_2 * 0x27 + 0x118) == 0) {
    local_290[3] = (char *)"puppetmaker" + 3;
    local_290[2] = (char *)"Remove";
  }
  else {
    local_290[3] = (char *)*(undefined2 *)((uint)param_2 * 0x27 + 0x118);
    local_290[2] = (char *)*(undefined2 *)((uint)param_2 * 0x27 + 0x116);
  }
  auStack_c[1] = 2;
  iVar6 = 2;
  if (param_1 != '\0') {
    pcStack_286 = (char *)"puppetmaker" + 3;
    pcStack_288 = (char *)"Change party";
    auStack_c[2] = 3;
    iVar6 = 3;
  }
  local_290[iVar6 * 2 + 1] = (char *)"puppetmaker" + 3;
  local_290[iVar6 * 2] = (char *)"Done";
  auStack_c[iVar6] = 4;
  cStack_16 = '\0';
  do {
    pcVar4 = (char *)"puppetmaker" + 3;
    uVar3 = ovr_OVC22_5087_0119();
    uVar7 = CONCAT22(pcVar4,uVar3);
    pcVar4 = (char *)"halfling castle" + 0xc;
    uVar3 = OVC45_77eb_226e(local_68);
    pcVar4 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)param_2 * 0x27 + 0x10e),
                                         *(undefined2 *)((uint)param_2 * 0x27 + 0x110),uVar3,pcVar4,
                                         uVar7);
    pcVar4 = ovr_fmVsprintf((char *)
                            "%s: Search this location for minerals?  Active party is %s the %s.",
                            pcVar4);
    strcpy(local_268,pcVar4);
    DAT_2410_5cef = *(undefined1 *)(Entities.ofs + param_3 * 0x37 + 0x1a);
    bStack_15 = ovr_OVC28_6018_1527(local_290);
    DAT_2410_5cef = 0xff;
    if (bStack_15 != 0) {
      bStack_15 = auStack_c[bStack_15 - 1];
    }
    if (bStack_15 == 1) {
      cVar2 = OVC45_77eb_16b2();
      if (cVar2 == '\0') {
        ovr_play_sfx(47,0);
        ovr_say("No minerals were found.");
        ovr_OVC23_55fe_1e87(0,uVar1,GfxRndSeed2,param_5,param_6);
      }
      else {
        uVar5 = ovr_randBelow(0x10);
        if ((uVar5 & 0xff) == 0) {
          ovr_play_sfx(42,0);
          ovr_say("Gems discovered.");
          ovr_OVC23_55fe_1e87(0x72,uVar1,GfxRndSeed2,param_5,param_6);
        }
        else {
          uVar5 = ovr_randBelow(4);
          if ((char)uVar5 == '\0') {
            ovr_play_sfx(43,0);
            ovr_say("Gold discovered.");
            ovr_OVC23_55fe_1e87(0x71,uVar1,GfxRndSeed2,param_5,param_6);
          }
          else {
            ovr_play_sfx(42,0);
            ovr_say("Iron deposits discovered.");
            ovr_OVC23_55fe_1e87(0x70,uVar1,GfxRndSeed2,param_5,param_6);
          }
        }
      }
      ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x12));
      cStack_16 = '\x01';
    }
    else if (bStack_15 == 2) {
      pcStack_12 = (char *)"puppetmaker" + 3;
      local_14 = (char *)"Remove";
      uStack_e = (char *)"puppetmaker" + 3;
      pcStack_10 = (char *)"No";
      ovr_fmVsprintf((char *)"Remove %s permanently. Are you sure?",
                     (char *)*(undefined2 *)((uint)param_2 * 0x27 + 0x10e));
      bStack_15 = ovr_OVC28_6018_1527(&local_14);
      if (bStack_15 == 1) {
        ovr_OVC23_55fe_1e87(0,uVar1,GfxRndSeed2,param_5,param_6);
      }
      cStack_16 = '\x01';
    }
    else if (bStack_15 == 3) {
      cStack_17 = OVC45_77eb_04d8(uVar1,GfxRndSeed2,&param_3);
      if (cStack_17 == -1) {
        cStack_16 = '\x01';
      }
    }
    else if ((bStack_15 == 4) || (bStack_15 == 0)) {
      cStack_16 = '\x01';
    }
  } while (cStack_16 == '\0');
  return;
}



/* 77eb:1ba2 */

bool __cdecl16far OVC45_77eb_1ba2(int param_1)

{
  return param_1 != 1;
}



/* 77eb:1bb3 */

void __cdecl16far
OVC45_77eb_1bb3(char param_1,byte param_2,int param_3,undefined2 param_4,undefined2 param_5,
               undefined2 param_6)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  char *pcVar7;
  undefined1 uVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined2 uVar14;
  undefined2 unaff_SS;
  char *msg;
  char *local_292 [4];
  char *pcStack_28a;
  char *pcStack_288;
  char local_26a [512];
  char local_6a [80];
  char *pcStack_1a;
  char *pcStack_18;
  undefined2 uStack_16;
  uint uStack_14;
  byte bStack_11;
  byte bStack_10;
  char cStack_f;
  char cStack_e;
  byte local_d [11];
  
  uVar4 = param_4;
  pcStack_1a = (char *)(*(uint *)((uint)param_2 * 0x27 + 0x125) / 10);
  local_292[1] = (char *)"puppetmaker" + 3;
  local_292[0] = (char *)"Claim";
  local_d[1] = 1;
  if (*(int *)((uint)param_2 * 0x27 + 0x116) == 0 && *(int *)((uint)param_2 * 0x27 + 0x118) == 0) {
    local_292[3] = (char *)"puppetmaker" + 3;
    local_292[2] = (char *)"Chop down";
  }
  else {
    local_292[3] = (char *)*(undefined2 *)((uint)param_2 * 0x27 + 0x118);
    local_292[2] = (char *)*(undefined2 *)((uint)param_2 * 0x27 + 0x116);
  }
  local_d[2] = 2;
  iVar13 = 2;
  if (param_1 != '\0') {
    pcStack_288 = (char *)"puppetmaker" + 3;
    pcStack_28a = (char *)"Change party";
    local_d[3] = 3;
    iVar13 = 3;
  }
  local_292[iVar13 * 2 + 1] = (char *)"puppetmaker" + 3;
  local_292[iVar13 * 2] = (char *)"Done";
  local_d[iVar13 + 1] = 4;
  cStack_e = '\0';
  do {
    pcVar7 = (char *)"puppetmaker" + 3;
    uVar5 = ovr_OVC22_5087_0119(CONCAT11((char)((uint)(param_3 * 0x37) >> 8),
                                         *(undefined1 *)(Entities.ofs + param_3 * 0x37 + 0x1a)));
    pcVar9 = (char *)"halfling castle" + 0xc;
    uVar6 = OVC45_77eb_226e(local_6a);
    pcVar7 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)param_2 * 0x27 + 0x10e),
                                         *(undefined2 *)((uint)param_2 * 0x27 + 0x110),pcStack_1a,
                                         uVar6,pcVar9,uVar5,pcVar7);
    pcVar7 = ovr_fmVsprintf((char *)
                            "%s: Claim this tree? Harvest value is %d gold. Active party is %s the %s."
                            ,pcVar7);
    strcpy(local_26a,pcVar7);
    DAT_2410_5cef = *(undefined1 *)(Entities.ofs + param_3 * 0x37 + 0x1a);
    local_d[0] = ovr_OVC28_6018_1527(local_292);
    DAT_2410_5cef = 0xff;
    if (local_d[0] != 0) {
      local_d[0] = local_d[local_d[0]];
    }
    if (local_d[0] == 1) {
      ovr_play_sfx(86,0);
      if (*(char *)((uint)param_2 * 0x27 + 0x131) == '\0') {
        if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 +
                     (uint)*(byte *)(Entities.ofs + param_3 * 0x37 + 0xd) * 0x95) == '\x05') {
          bStack_11 = param_2 + 0x18;
        }
        else {
          bStack_11 = param_2 + 6;
        }
      }
      else {
        bStack_11 = param_2;
      }
      uStack_14 = (uint)*(byte *)((uint)bStack_11 * 0x27 + 0x120);
      *(undefined1 *)((uint)bStack_11 * 0x27 + 0x120) = 1;
      ovr_OVC23_55fe_184e(CONCAT11(0x24,bStack_11),uVar4,GfxRndSeed2,param_5,param_6,
                          CONCAT11((char)((uint)(param_3 * 0x37) >> 8),
                                   *(undefined1 *)(Entities.ofs + param_3 * 0x37 + 0x1a)),0);
      *(undefined1 *)((uint)bStack_11 * 0x27 + 0x120) = (undefined1)uStack_14;
      uVar8 = (undefined1)((uint)(param_3 * 0x37) >> 8);
      uStack_16 = ovr_OVC22_5087_0234(CONCAT11(uVar8,bStack_11),
                                      CONCAT11(uVar8,*(undefined1 *)
                                                      (Entities.ofs + param_3 * 0x37 + 0x1a)),uVar4,
                                      GfxRndSeed2);
      pcVar9 = (char *)"puppetmaker" + 3;
      uVar8 = (undefined1)((uint)(param_3 * 0x37) >> 8);
      pcStack_18 = (char *)ovr_OVC22_5087_0411(CONCAT11(uVar8,bStack_11),
                                               CONCAT11(uVar8,*(undefined1 *)
                                                               (Entities.ofs + param_3 * 0x37 + 0x1a
                                                               )),uVar4,GfxRndSeed2);
      OVC45_77eb_1ba2(uStack_16);
      pcVar7 = ovr_fmVsprintf((char *)
                              "Forest claimed. This forest creates %d gold of income and feeds %d %s."
                              ,pcStack_18);
      ovr_say((char *)CONCAT22(pcVar9,pcVar7));
      ovr_inputUpdate((ulong)MessageDelay << 1);
      cStack_e = '\x01';
    }
    else if (local_d[0] == 2) {
      ovr_play_sfx(48,0);
      ovr_OVC23_55fe_1e87(0,uVar4,GfxRndSeed2,param_5,param_6,
                          CONCAT11((char)((uint)(param_3 * 0x37) >> 8),
                                   *(undefined1 *)(Entities.ofs + param_3 * 0x37 + 0x1a)));
      cStack_e = '\x01';
      bStack_10 = *(byte *)(Entities.ofs + param_3 * 0x37 + 0x1a);
      uVar5 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_10 << 2) >> 0x10);
      iVar13 = (int)*(undefined4 *)((uint)bStack_10 << 2);
      puVar1 = (uint *)(iVar13 + 0x56);
      uVar3 = *puVar1;
      *puVar1 = (uint)(pcStack_1a + *puVar1);
      piVar2 = (int *)(iVar13 + 0x58);
      *piVar2 = *piVar2 + (uint)CARRY2(uVar3,(uint)pcStack_1a);
      uVar5 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_10 << 2) >> 0x10);
      iVar10 = (int)*(undefined4 *)((uint)bStack_10 << 2);
      iVar13 = *(int *)(iVar10 + 0x58);
      uVar6 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_10 << 2) >> 0x10);
      iVar11 = (int)*(undefined4 *)((uint)bStack_10 << 2);
      iVar12 = *(int *)(iVar11 + 0x8c);
      if ((iVar12 <= iVar13) &&
         ((iVar12 < iVar13 || (*(uint *)(iVar11 + 0x8a) < *(uint *)(iVar10 + 0x56))))) {
        uVar6 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_10 << 2) >> 0x10);
        iVar13 = (int)*(undefined4 *)((uint)bStack_10 << 2);
        uVar5 = *(undefined2 *)(iVar13 + 0x8a);
        uVar14 = (undefined2)((ulong)*(undefined4 *)((uint)bStack_10 << 2) >> 0x10);
        iVar12 = (int)*(undefined4 *)((uint)bStack_10 << 2);
        *(undefined2 *)(iVar12 + 0x58) = *(undefined2 *)(iVar13 + 0x8c);
        *(undefined2 *)(iVar12 + 0x56) = uVar5;
      }
      msg = ovr_stsprintf(local_6a,"Tree cut down. %d gold obtained.",pcStack_1a);
      ovr_say(msg);
      ovr_inputUpdate((ulong)MessageDelay << 1);
    }
    else if (local_d[0] == 3) {
      cStack_f = OVC45_77eb_04d8(uVar4,GfxRndSeed2,&param_3);
      if (cStack_f == -1) {
        cStack_e = '\x01';
      }
    }
    else if ((local_d[0] == 4) || (local_d[0] == 0)) {
      cStack_e = '\x01';
    }
  } while (cStack_e == '\0');
  return;
}



/* 77eb:20e8 */

uint __cdecl16far OVC45_77eb_20e8(int *param_1)

{
  byte bVar1;
  uint in_AX;
  int iVar2;
  uint uVar3;
  byte bStack_4;
  char cStack_3;
  
  bStack_4 = 0;
  while( true ) {
    if (3 < bStack_4) {
      return in_AX & 0xff00;
    }
    in_AX = OVC45_77eb_0121(*param_1 - (uint)bStack_4,GfxRndSeed2);
    cStack_3 = (char)in_AX;
    if (cStack_3 != '\0') break;
    bStack_4 = bStack_4 + 1;
  }
  iVar2 = (in_AX & 0xff) * 0x27;
  bVar1 = *(byte *)(iVar2 + 0x11b);
  uVar3 = CONCAT11((char)((uint)iVar2 >> 8),bVar1);
  if (bStack_4 < bVar1) {
    uVar3 = (uint)bStack_4;
    *param_1 = *param_1 - uVar3;
  }
  else {
    cStack_3 = '\0';
  }
  return CONCAT11((char)(uVar3 >> 8),cStack_3);
}



/* 77eb:215a */

undefined2 __cdecl16far OVC45_77eb_215a(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if ((((param_1 < 0) || (param_2 < 0)) || (0x93 < param_1 + 1)) || (0x3b < param_2 + 1)) {
    uVar1 = 2;
  }
  else {
    uVar1 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
    if ((*(uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2) & 3) == 3) {
      uVar1 = 2;
    }
    else if ((*(uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2) & 3) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* 77eb:21d3 */

undefined2 __cdecl16far OVC45_77eb_21d3(byte param_1,byte param_2)

{
  return CONCAT11((byte)((uint)param_1 * (uint)param_2 >> 0xb),
                  (char)((uint)param_1 * (uint)param_2 >> 3));
}



/* 77eb:21f1 */

bool __cdecl16far OVC45_77eb_21f1(int param_1,undefined2 param_2)

{
  char cVar1;
  
  cVar1 = video_13aa_000b(param_1,param_2);
  if (cVar1 != '\0') {
    ovr_land_info((param_1 - 9U) / 0x30);
  }
  return cVar1 != '\0';
}



/* 77eb:2226 */

uint __cdecl16far OVC45_77eb_2226(byte param_1)

{
  undefined4 uVar1;
  uint in_AX;
  uint uVar2;
  byte bVar3;
  
  if (param_1 == 0xff) {
    uVar2 = in_AX & 0xff00;
  }
  else {
    uVar1 = *(undefined4 *)((uint)param_1 << 2);
    bVar3 = (byte)(((uint)param_1 << 2) >> 8);
    if (*(char *)((int)uVar1 + 0x3f) == '\0') {
      uVar2 = CONCAT11(bVar3,1);
    }
    else {
      uVar2 = (uint)bVar3 << 8;
    }
  }
  return uVar2;
}



/* 77eb:2257 */

char * __cdecl16far OVC45_77eb_2257(int param_1)

{
  char *pcVar1;
  
  if (param_1 < 1) {
    pcVar1 = (char *)"Maintenance cost is";
  }
  else {
    pcVar1 = (char *)"Income created is";
  }
  return pcVar1;
}



/* 77eb:226e */

int __cdecl16far
OVC45_77eb_226e(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,char param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  int iStack_4;
  
  uVar1 = ovr_font_302d_06ea((int)param_2,param_2._2_2_,(int)param_3,param_3._2_2_);
  if (param_4 < uVar1) {
    if (param_5 == '\x02') {
      iStack_4 = ovr_font_302d_06ea((char *)"..",(char *)"puppetmaker" + 3,(int)param_3,
                                    param_3._2_2_);
    }
    else {
      iStack_4 = ovr_font_302d_06ea((char *)"...",(char *)"puppetmaker" + 3,(int)param_3,
                                    param_3._2_2_);
    }
    iVar3 = 0;
    iVar2 = 0;
    while( true ) {
      uVar4 = (undefined2)((ulong)param_1 >> 0x10);
      if ((*(char *)((int)param_2 + iVar2) == '\0') ||
         ((int)param_4 <
          (int)(iStack_4 + iVar3 +
               (uint)*(byte *)((int)param_3 + *(char *)((int)param_2 + iVar2) + 0xa1)))) break;
      iVar3 = iVar3 + (uint)*(byte *)((int)param_3 + *(char *)((int)param_2 + iVar2) + 0xa1);
      *(undefined1 *)((int)param_1 + iVar2) = *(undefined1 *)((int)param_2 + iVar2);
      iVar2 = iVar2 + 1;
    }
    *(undefined1 *)((int)param_1 + iVar2) = 0x2e;
    *(undefined1 *)((int)param_1 + iVar2 + 1) = 0x2e;
    iVar3 = iVar2 + 2;
    if (param_5 != '\x02') {
      *(undefined1 *)((int)param_1 + iVar3) = 0x2e;
      iVar3 = iVar2 + 3;
    }
    *(undefined1 *)((int)param_1 + iVar3) = 0;
    param_2._0_2_ = (int)param_1;
  }
  return (int)param_2;
}



/* 77eb:234a */

uint __cdecl16far OVC45_77eb_234a(char param_1,uint param_2,int param_3)

{
  uint in_AX;
  undefined1 uVar2;
  uint uVar1;
  byte bVar3;
  
  if (param_1 == '\x01') {
    in_AX = param_3 * 0x128 + (int)DAT_2000_cb09 + param_2 * 2;
    uVar1 = *(uint *)(in_AX + 0x128);
    uVar2 = (undefined1)(in_AX >> 8);
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 1) != 0) {
        return CONCAT11(uVar2,1);
      }
    }
    else if ((uVar1 & 2) != 0) {
      return CONCAT11(uVar2,1);
    }
  }
  else if (param_1 == '\x02') {
    uVar1 = param_3 * 0x128 + (int)DAT_2000_cb09 + param_2 * 2;
    if ((*(uint *)(uVar1 + 0x128) & 1) == 0) {
      return uVar1 & 0xff00;
    }
    if ((*(uint *)((int)DAT_2000_cb09 + param_3 * 0x128 + param_2 * 2) & 1) == 0) {
      return ((param_2 & 0x7fff) >> 7) << 8;
    }
    uVar1 = param_3 * 0x128 + (int)DAT_2000_cb09 + param_2 * 2;
    if ((*(uint *)(uVar1 + 0x126) & 2) == 0) {
      return uVar1 & 0xff00;
    }
    bVar3 = (byte)(param_2 * 2 >> 8);
    if ((*(uint *)((int)DAT_2000_cb09 + param_3 * 0x128 + param_2 * 2 + -2) & 2) == 0) {
      return (uint)bVar3 << 8;
    }
    return CONCAT11(bVar3,1);
  }
  return in_AX & 0xff00;
}


