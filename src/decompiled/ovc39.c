/*
 * ovc39.c - recovered from STRONG.EXE
 * memory block: OVC39
 * range: 690b:0000 - 690b:0bcf
 * functions: 4
 */
#include "recovered.h"


/* 690b:0000 */

int __cdecl16far OVC39_690b_0000(byte param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 uVar3;
  bool bVar4;
  uint8_t *puVar5;
  stg_tmp_t *psVar6;
  far_t handle;
  undefined2 uStack_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  undefined2 uStack_8;
  
  if (param_1 < 0x22) {
    handle.seg = *(uint16_t *)((uint)param_1 * 4 + -0x6c6e);
    handle.ofs = *(uint16_t *)((uint)param_1 * 4 + -0x6c70);
    psVar6 = ovr_stshLoadGfx(handle);
    uVar1 = *(undefined4 *)((uint)param_1 * 4 + -0x6c70);
    uVar3 = (undefined2)((ulong)uVar1 >> 0x10);
    iVar2 = (int)uVar1;
    uStack_c = *(int *)(iVar2 + 7);
    uStack_e = *(uint *)(iVar2 + 5);
    if (uStack_e == 0 && uStack_c == 0) {
      bVar4 = 0xfffe < uStack_e;
      uStack_e = uStack_e + 1;
      uStack_c = uStack_c + (uint)bVar4;
    }
    puVar5 = ovr_stshAlloc(CONCAT22(uStack_c,uStack_e));
    memcpy((uint8_t *)puVar5,((stg_tmp_t *)psVar6)->cmap,uStack_e);
  }
  else {
    puVar5 = ovr_stshAlloc(1);
    uStack_e = 1;
  }
  uStack_8 = (undefined2)((ulong)puVar5 >> 0x10);
  uStack_a = (int)puVar5;
  *(undefined1 *)(uStack_e + uStack_a + -1) = 0;
  return uStack_a;
}



/* 690b:00d1 */

char * __cdecl16far OVC39_690b_00d1(void)

{
  byte bVar1;
  char *pcVar2;
  
  bVar1 = ovr_manage_4d05_1b1d();
  if ((bVar1 == 0xff) || (*(char *)((int)*(undefined4 *)((uint)bVar1 << 2) + 0x34) == '\0')) {
    pcVar2 = (char *)"lord";
  }
  else {
    pcVar2 = (char *)"lady";
  }
  return pcVar2;
}



/* 690b:0111 */

undefined2 __cdecl16far OVC39_690b_0111(int param_1,undefined2 param_2)

{
  byte bVar1;
  undefined2 uVar2;
  byte bStack_4;
  
  bStack_4 = 0;
  while( true ) {
    if (3 < bStack_4) {
      return 0;
    }
    bVar1 = ovr_OVC45_77eb_0121(param_1 - (uint)bStack_4,param_2);
    if ((bVar1 != 0) && (bStack_4 < *(byte *)((uint)bVar1 * 0x27 + 0x11b))) break;
    bStack_4 = bStack_4 + 1;
  }
  uVar2 = ovr_OVC45_77eb_0179(param_1 - (uint)bStack_4,param_2);
  return uVar2;
}



/* 690b:0180 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far OVC39_690b_0180(byte param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint16_t uVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  char *pcVar8;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  far_t handle_03;
  far_t handle_04;
  far_t handle_05;
  far_t handle_06;
  char local_2cc [701];
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  byte bStack_c;
  byte bStack_b;
  byte bStack_a;
  byte bStack_9;
  int iStack_8;
  char *pcStack_6;
  char *pcStack_4;
  
  if ((param_1 != 0xff) && (*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3f) == '\0')) {
    iStack_8 = ovr_OVC23_55fe_3450();
    for (bStack_b = 0; bStack_b < 4; bStack_b = bStack_b + 1) {
      for (iVar6 = -2; iVar6 < 2; iVar6 = iVar6 + 1) {
        iVar2 = ovr_OVC23_55fe_2937(iStack_8 + iVar6);
        if (iVar2 == -1) {
          iVar2 = OVC39_690b_0111(iStack_8 + iVar6);
          uVar7 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
          iVar5 = (int)DAT_2000_ca95;
          bStack_9 = *(byte *)(iVar5 + iVar2 * 9);
          pcVar3 = (char *)"puppetmaker" + 3;
          bStack_a = *(byte *)(iVar5 + iVar2 * 9 + 2);
          if ((((bStack_b == 0) &&
               (pcVar3 = (char *)"halfling castle" + 0xc,
               *(char *)((int)*(undefined4 *)((uint)bStack_a << 2) + 0x3f) == '\0')) &&
              (0xf7 < iVar2)) &&
             (pcVar3 = (char *)"puppetmaker" + 3, *(byte *)(iVar5 + iVar2 * 9 + 1) < 8)) {
            uVar4 = 0x195d;
            if ((*(uint *)((uint)bStack_9 * 0x27 + 0x121) & 0x80) == 0) {
              pcStack_6 = (char *)OVC39_690b_0000();
            }
            else {
              pcStack_6 = (char *)OVC39_690b_0000();
            }
            pcStack_4 = (char *)uVar4;
            pcVar3 = (char *)OVC39_690b_00d1();
            pcVar8 = ovr_stsprintf(local_2cc,(char *)CONCAT22(pcStack_4,pcStack_6),pcVar3);
            ovr_drawString((char *)pcVar8);
            handle.seg = (uint16_t)pcStack_4;
            handle.ofs = (uint16_t)pcStack_6;
            ovr_stshFree(handle);
            return;
          }
          if (((bStack_b == 1) && (iVar2 < 0xf8)) &&
             (pcVar3 = (char *)0x195d, (*(uint *)((uint)bStack_9 * 0x27 + 0x121) & 2) != 0)) {
            pcStack_6 = (char *)OVC39_690b_0000();
            pcStack_4 = pcVar3;
            pcVar3 = (char *)OVC39_690b_00d1();
            pcVar8 = ovr_stsprintf(local_2cc,(char *)CONCAT22(pcStack_4,pcStack_6),pcVar3);
            ovr_drawString((char *)pcVar8);
            handle_00.seg = (uint16_t)pcStack_4;
            handle_00.ofs = (uint16_t)pcStack_6;
            ovr_stshFree(handle_00);
            return;
          }
          if (((bStack_b == 2) && (iVar2 < 0xf8)) &&
             (pcVar3 = (char *)0x195d, (*(uint *)((uint)bStack_9 * 0x27 + 0x121) & 0x20) != 0)) {
            pcStack_6 = (char *)OVC39_690b_0000();
            pcStack_4 = pcVar3;
            pcVar3 = (char *)OVC39_690b_00d1();
            pcVar8 = ovr_stsprintf(local_2cc,(char *)CONCAT22(pcStack_4,pcStack_6),pcVar3);
            ovr_drawString((char *)pcVar8);
            handle_01.seg = (uint16_t)pcStack_4;
            handle_01.ofs = (uint16_t)pcStack_6;
            ovr_stshFree(handle_01);
            return;
          }
          if ((bStack_b == 3) && (cVar1 = ovr_OVC45_77eb_0aea(iStack_8 + iVar6), cVar1 != '\0')) {
            pcStack_6 = (char *)OVC39_690b_0000();
            pcStack_4 = pcVar3;
            pcVar3 = (char *)OVC39_690b_00d1();
            pcVar8 = ovr_stsprintf(local_2cc,(char *)CONCAT22(pcStack_4,pcStack_6),pcVar3);
            ovr_drawString((char *)pcVar8);
            handle_02.seg = (uint16_t)pcStack_4;
            handle_02.ofs = (uint16_t)pcStack_6;
            ovr_stshFree(handle_02);
            return;
          }
          if (((bStack_b == 4) && (iVar2 < 0xf8)) &&
             (uVar4 = 0x195d, (*(uint *)((uint)bStack_9 * 0x27 + 0x121) & 0x400) != 0)) {
            pcStack_6 = (char *)OVC39_690b_0000();
            pcStack_4 = (char *)uVar4;
            pcVar3 = (char *)OVC39_690b_00d1();
            pcVar8 = ovr_stsprintf(local_2cc,(char *)CONCAT22(pcStack_4,pcStack_6),pcVar3);
            ovr_drawString((char *)pcVar8);
            handle_03.seg = (uint16_t)pcStack_4;
            handle_03.ofs = (uint16_t)pcStack_6;
            ovr_stshFree(handle_03);
            return;
          }
        }
      }
    }
    uVar7 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
    iVar6 = (int)*(undefined4 *)((uint)param_1 << 2);
    if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4f) <
        (uint)(*(int *)(iVar6 + 0x4d) * 2 + *(int *)(iVar6 + 0x4d)) >> 1) {
      if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4f) <
          *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d)) {
        uVar7 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
        iVar6 = (int)*(undefined4 *)((uint)param_1 << 2);
        if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4f) <
            (uint)(*(int *)(iVar6 + 0x4d) * 2 + *(int *)(iVar6 + 0x4d)) >> 2) {
          if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4f) <
              *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d) >> 1) {
            if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4f) <
                *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d) >> 2) {
              bStack_c = 5;
            }
            else {
              bStack_c = 4;
            }
          }
          else {
            bStack_c = 3;
          }
        }
        else {
          bStack_c = 2;
        }
      }
      else {
        bStack_c = 1;
      }
    }
    else {
      bStack_c = 0;
    }
    iVar2 = (int)*(undefined4 *)((uint)param_1 << 2);
    uVar7 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
    iVar6 = *(int *)(iVar2 + 0x62);
    if ((iVar6 < 0) ||
       ((iVar6 == 0 &&
        (*(uint *)(iVar2 + 0x60) <
         (uint)(*(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d) * 0x28))))) {
      iVar2 = (int)*(undefined4 *)((uint)param_1 << 2);
      uVar7 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
      iVar6 = *(int *)(iVar2 + 0x62);
      if ((iVar6 < 0) ||
         ((iVar6 == 0 &&
          (*(uint *)(iVar2 + 0x60) <
           (uint)(*(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d) * 0x14))))) {
        iVar2 = (int)*(undefined4 *)((uint)param_1 << 2);
        uVar7 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
        iVar6 = *(int *)(iVar2 + 0x62);
        if ((iVar6 < 0) ||
           ((iVar6 == 0 &&
            (*(uint *)(iVar2 + 0x60) <
             (uint)(*(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d) * 0x3c) >> 2)))) {
          iVar2 = (int)*(undefined4 *)((uint)param_1 << 2);
          uVar7 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
          iVar6 = *(int *)(iVar2 + 0x62);
          if ((iVar6 < 0) ||
             ((iVar6 == 0 &&
              (*(uint *)(iVar2 + 0x60) <
               (uint)(*(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d) * 0x14) >> 1)))) {
            iVar2 = (int)*(undefined4 *)((uint)param_1 << 2);
            uVar7 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
            iVar6 = *(int *)(iVar2 + 0x62);
            if ((iVar6 < 0) ||
               ((iVar6 == 0 &&
                (*(uint *)(iVar2 + 0x60) <
                 (uint)(*(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d) * 0x14) >> 2)))) {
              bStack_f = 5;
            }
            else {
              bStack_f = 4;
            }
          }
          else {
            bStack_f = 3;
          }
        }
        else {
          bStack_f = 2;
        }
      }
      else {
        bStack_f = 1;
      }
    }
    else {
      bStack_f = 0;
    }
    if (bStack_f < bStack_c) {
      bStack_c = bStack_f;
    }
    uVar7 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
    iVar6 = (int)*(undefined4 *)((uint)param_1 << 2);
    if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5b) <
        (uint)(*(int *)(iVar6 + 0x4d) * 2 + *(int *)(iVar6 + 0x4d)) >> 1) {
      if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5b) <
          *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d)) {
        uVar7 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
        iVar6 = (int)*(undefined4 *)((uint)param_1 << 2);
        if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5b) <
            (uint)(*(int *)(iVar6 + 0x4d) * 2 + *(int *)(iVar6 + 0x4d)) >> 2) {
          if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5b) <
              *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d) >> 1) {
            if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5b) <
                *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d) >> 2) {
              bStack_e = 5;
            }
            else {
              bStack_e = 4;
            }
          }
          else {
            bStack_e = 3;
          }
        }
        else {
          bStack_e = 2;
        }
      }
      else {
        bStack_e = 1;
      }
    }
    else {
      bStack_e = 0;
    }
    pcVar3 = (char *)"halfling castle" + 0xc;
    if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x54) <
        (uint)(*(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d) << 1)) {
      pcVar3 = (char *)((uint)param_1 << 2);
      if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x54) <
          *(uint *)((int)*(undefined4 *)pcVar3 + 0x4d)) {
        pcVar3 = (char *)"halfling castle" + 0xc;
        if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x54) <
            *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d) >> 1) {
          pcVar3 = (char *)"halfling castle" + 0xc;
          if (*(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x54) < 0) {
            pcVar3 = (char *)"halfling castle" + 0xc;
            if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x54) <
                (uint)-*(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d)) {
              bStack_d = 5;
            }
            else {
              bStack_d = 4;
            }
          }
          else {
            bStack_d = 3;
          }
        }
        else {
          bStack_d = 2;
        }
      }
      else {
        bStack_d = 1;
      }
    }
    else {
      bStack_d = 0;
    }
    if (((bStack_c == 0) || (bStack_c < bStack_e)) || (bStack_c < bStack_d)) {
      if ((bStack_e == 0) || (bStack_e < bStack_d)) {
        if (bStack_d == 0) {
          pcVar3 = (char *)OVC39_690b_00d1();
          pcVar8 = ovr_stsprintf(local_2cc,(char *)CONCAT22(DAT_2410_6ac6,DAT_2410_6ac4),pcVar3);
          ovr_drawString((char *)pcVar8,(int)((ulong)pcVar8 >> 0x10));
        }
        else {
          pcStack_6 = (char *)OVC39_690b_0000();
          pcStack_4 = pcVar3;
          pcVar3 = (char *)OVC39_690b_00d1();
          pcVar8 = ovr_stsprintf(local_2cc,(char *)CONCAT22(pcStack_4,pcStack_6),pcVar3);
          ovr_drawString((char *)pcVar8);
          handle_06.seg = (uint16_t)pcStack_4;
          handle_06.ofs = (uint16_t)pcStack_6;
          ovr_stshFree(handle_06);
        }
      }
      else {
        pcStack_6 = (char *)OVC39_690b_0000();
        pcStack_4 = pcVar3;
        pcVar3 = (char *)OVC39_690b_00d1();
        pcVar8 = ovr_stsprintf(local_2cc,(char *)CONCAT22(pcStack_4,pcStack_6),pcVar3);
        ovr_drawString((char *)pcVar8);
        handle_05.seg = (uint16_t)pcStack_4;
        handle_05.ofs = (uint16_t)pcStack_6;
        ovr_stshFree(handle_05);
      }
    }
    else {
      pcStack_6 = (char *)OVC39_690b_0000();
      pcStack_4 = pcVar3;
      pcVar3 = (char *)OVC39_690b_00d1();
      pcVar8 = ovr_stsprintf(local_2cc,(char *)CONCAT22(pcStack_4,pcStack_6),pcVar3);
      ovr_drawString((char *)pcVar8);
      handle_04.seg = (uint16_t)pcStack_4;
      handle_04.ofs = (uint16_t)pcStack_6;
      ovr_stshFree(handle_04);
    }
  }
  return;
}


