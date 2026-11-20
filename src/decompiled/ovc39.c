/*
 * ovc39.c - recovered from STRONG.EXE
 * memory block: OVC39
 * range: 690b:0000 - 690b:0bcf
 * functions: 4
 */
#include "recovered.h"


/* 690b:0000 */

/* Loads an archive entry, allocates a buffer of its recorded size and copies it there. */

int __cdecl16far ovc39_loadArchiveEntry(byte fileId)

{
  undefined4 uVar1;
  far_t handle;
  stg_tmp_t *psVar2;
  stg_tmp_t *in_DX;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
  bool bVar6;
  word wStack_e;
  int iStack_c;
  char *pcStack_a;
  stg_tmp_t *psStack_8;
  
  if (fileId < 0x22) {
    uVar3 = 0x2410;
    handle.seg = *(uint16_t *)((uint)fileId * 4 + -0x6c6e);
    handle.ofs = *(uint16_t *)((uint)fileId * 4 + -0x6c70);
    psVar2 = ovr_stshLoadGfx(handle);
    uVar1 = *(undefined4 *)((uint)fileId * 4 + -0x6c70);
    uVar5 = (undefined2)((ulong)uVar1 >> 0x10);
    iVar4 = (int)uVar1;
    iStack_c = *(int *)(iVar4 + 7);
    wStack_e = *(uint *)(iVar4 + 5);
    if (wStack_e == 0 && iStack_c == 0) {
      bVar6 = 0xfffe < wStack_e;
      wStack_e = wStack_e + 1;
      iStack_c = iStack_c + (uint)bVar6;
    }
    psStack_8 = psVar2;
    pcStack_a = ovr_stshAlloc(CONCAT22(iStack_c,wStack_e));
    memcpy((char *)CONCAT22(psStack_8,pcStack_a),(char *)CONCAT22(uVar3,psVar2),wStack_e);
  }
  else {
    pcStack_a = ovr_stshAlloc(1);
    wStack_e = 1;
    psStack_8 = in_DX;
  }
  pcStack_a[wStack_e - 1] = '\0';
  return (int)pcStack_a;
}



/* 690b:00d1 */

/* Returns "lord" or "lady" for the first leader with a level, from the sheet's gender byte. */

char * __cdecl16far ovc39_lordOrLady(void)

{
  byte bVar1;
  char *pcVar2;
  
  bVar1 = ovr_manage_findFirstLeader();
  if ((bVar1 == 0xff) || (*(char *)((int)*(undefined4 *)((uint)bVar1 << 2) + 0x34) == '\0')) {
    pcVar2 = (char *)"lord";
  }
  else {
    pcVar2 = (char *)"lady";
  }
  return pcVar2;
}



/* 690b:0111 */

/* Finds the building covering (x,y) by scanning left up to four columns for a unit whose
   bldtp_t.size spans it. */

undefined2 __cdecl16far ovc39_findBuildingAt(int x,uint16_t y)

{
  byte bVar1;
  short sVar2;
  byte bStack_4;
  
  bStack_4 = 0;
  while( true ) {
    if (3 < bStack_4) {
      return 0;
    }
    bVar1 = ovr_ovc45_getUnitType(x - (uint)bStack_4,y);
    if ((bVar1 != 0) && (bStack_4 < *(byte *)((uint)bVar1 * 0x27 + 0x11b))) break;
    bStack_4 = bStack_4 + 1;
  }
  sVar2 = ovr_ovc45_getUnitIndex(x - (uint)bStack_4,y);
  return sVar2;
}



/* 690b:0180 */

/* [R2] string "halfling castle" */

void __cdecl16far ovc39_textHalflingCastle(byte partyIndex)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  uint16_t uVar5;
  unit_t *puVar6;
  int iVar7;
  undefined2 uVar8;
  char *unaff_SS;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  far_t handle_03;
  far_t handle_04;
  far_t handle_05;
  far_t handle_06;
  uint8_t msg;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  byte bStack_c;
  byte bStack_b;
  byte bStack_a;
  byte bStack_9;
  uint uStack_8;
  char *pcStack_6;
  char *pcStack_4;
  
  if ((partyIndex != 0xff) &&
     (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3f) == '\0')) {
    uStack_8 = ovr_alignUp4(GfxRndSeed);
    for (bStack_b = 0; bStack_b < 4; bStack_b = bStack_b + 1) {
      for (iVar7 = -2; iVar7 < 2; iVar7 = iVar7 + 1) {
        uVar1 = ovr_ovc23_findRecordAt(uStack_8 + iVar7,GfxRndSeed2);
        if (uVar1 == 0xffff) {
          iVar2 = ovc39_findBuildingAt(uStack_8 + iVar7,GfxRndSeed2);
          uVar8 = (undefined2)((ulong)GUnits >> 0x10);
          puVar6 = (unit_t *)GUnits;
          bStack_9 = (puVar6 + iVar2)->bldType;
          uVar5 = 0x2410;
          bStack_a = puVar6[iVar2].unitType;
          if ((((bStack_b == 0) &&
               (uVar5 = 0x217a, *(char *)((int)*(undefined4 *)((uint)bStack_a << 2) + 0x3f) == '\0')
               ) && (0xf7 < iVar2)) && (uVar5 = 0x2410, puVar6[iVar2].level < 8)) {
            uVar5 = 0x195d;
            if ((*(uint *)((uint)bStack_9 * 0x27 + 0x121) & 0x80) == 0) {
              pcStack_6 = (char *)ovc39_loadArchiveEntry(8);
            }
            else {
              pcStack_6 = (char *)ovc39_loadArchiveEntry(9);
            }
            pcStack_4 = (char *)uVar5;
            ovc39_lordOrLady();
            pcVar3 = ovr_stsprintf((char *)&msg,unaff_SS,pcStack_6);
            ovr_drawString(pcVar3,uVar5);
            handle.seg = (uint16_t)pcStack_4;
            handle.ofs = (uint16_t)pcStack_6;
            ovr_stshFree(handle);
            return;
          }
          if (((bStack_b == 1) && (iVar2 < 0xf8)) &&
             (uVar5 = 0x195d, (*(uint *)((uint)bStack_9 * 0x27 + 0x121) & 2) != 0)) {
            pcStack_6 = (char *)ovc39_loadArchiveEntry(10);
            pcStack_4 = (char *)uVar5;
            ovc39_lordOrLady();
            pcVar3 = ovr_stsprintf((char *)&msg,unaff_SS,pcStack_6);
            ovr_drawString(pcVar3,uVar5);
            handle_00.seg = (uint16_t)pcStack_4;
            handle_00.ofs = (uint16_t)pcStack_6;
            ovr_stshFree(handle_00);
            return;
          }
          if (((bStack_b == 2) && (iVar2 < 0xf8)) &&
             (uVar5 = 0x195d, (*(uint *)((uint)bStack_9 * 0x27 + 0x121) & 0x20) != 0)) {
            pcStack_6 = (char *)ovc39_loadArchiveEntry(0xb);
            pcStack_4 = (char *)uVar5;
            ovc39_lordOrLady();
            pcVar3 = ovr_stsprintf((char *)&msg,unaff_SS,pcStack_6);
            ovr_drawString(pcVar3,uVar5);
            handle_01.seg = (uint16_t)pcStack_4;
            handle_01.ofs = (uint16_t)pcStack_6;
            ovr_stshFree(handle_01);
            return;
          }
          if ((bStack_b == 3) &&
             (uVar1 = ovr_ovc45_compute4(uStack_8 + iVar7,GfxRndSeed2), (char)uVar1 != '\0')) {
            pcStack_6 = (char *)ovc39_loadArchiveEntry(0xc);
            pcStack_4 = (char *)uVar5;
            ovc39_lordOrLady();
            pcVar3 = ovr_stsprintf((char *)&msg,unaff_SS,pcStack_6);
            ovr_drawString(pcVar3,uVar5);
            handle_02.seg = (uint16_t)pcStack_4;
            handle_02.ofs = (uint16_t)pcStack_6;
            ovr_stshFree(handle_02);
            return;
          }
          if (((bStack_b == 4) && (iVar2 < 0xf8)) &&
             (uVar5 = 0x195d, (*(uint *)((uint)bStack_9 * 0x27 + 0x121) & 0x400) != 0)) {
            pcStack_6 = (char *)ovc39_loadArchiveEntry(0xd);
            pcStack_4 = (char *)uVar5;
            ovc39_lordOrLady();
            pcVar3 = ovr_stsprintf((char *)&msg,unaff_SS,pcStack_6);
            ovr_drawString(pcVar3,uVar5);
            handle_03.seg = (uint16_t)pcStack_4;
            handle_03.ofs = (uint16_t)pcStack_6;
            ovr_stshFree(handle_03);
            return;
          }
        }
      }
    }
    uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
    iVar7 = (int)*(undefined4 *)((uint)partyIndex << 2);
    if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4f) <
        (uint)(*(int *)(iVar7 + 0x4d) * 2 + *(int *)(iVar7 + 0x4d)) >> 1) {
      if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4f) <
          *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d)) {
        uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
        iVar7 = (int)*(undefined4 *)((uint)partyIndex << 2);
        if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4f) <
            (uint)(*(int *)(iVar7 + 0x4d) * 2 + *(int *)(iVar7 + 0x4d)) >> 2) {
          if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4f) <
              *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d) >> 1) {
            if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4f) <
                *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d) >> 2) {
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
    iVar2 = (int)*(undefined4 *)((uint)partyIndex << 2);
    uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
    iVar7 = *(int *)(iVar2 + 0x62);
    if ((iVar7 < 0) ||
       ((iVar7 == 0 &&
        (*(uint *)(iVar2 + 0x60) <
         (uint)(*(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d) * 0x28))))) {
      iVar2 = (int)*(undefined4 *)((uint)partyIndex << 2);
      uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
      iVar7 = *(int *)(iVar2 + 0x62);
      if ((iVar7 < 0) ||
         ((iVar7 == 0 &&
          (*(uint *)(iVar2 + 0x60) <
           (uint)(*(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d) * 0x14))))) {
        iVar2 = (int)*(undefined4 *)((uint)partyIndex << 2);
        uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
        iVar7 = *(int *)(iVar2 + 0x62);
        if ((iVar7 < 0) ||
           ((iVar7 == 0 &&
            (*(uint *)(iVar2 + 0x60) <
             (uint)(*(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d) * 0x3c) >> 2)))) {
          iVar2 = (int)*(undefined4 *)((uint)partyIndex << 2);
          uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
          iVar7 = *(int *)(iVar2 + 0x62);
          if ((iVar7 < 0) ||
             ((iVar7 == 0 &&
              (*(uint *)(iVar2 + 0x60) <
               (uint)(*(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d) * 0x14) >> 1))))
          {
            iVar2 = (int)*(undefined4 *)((uint)partyIndex << 2);
            uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
            iVar7 = *(int *)(iVar2 + 0x62);
            if ((iVar7 < 0) ||
               ((iVar7 == 0 &&
                (*(uint *)(iVar2 + 0x60) <
                 (uint)(*(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d) * 0x14) >> 2)))
               ) {
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
    uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
    iVar7 = (int)*(undefined4 *)((uint)partyIndex << 2);
    if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5b) <
        (uint)(*(int *)(iVar7 + 0x4d) * 2 + *(int *)(iVar7 + 0x4d)) >> 1) {
      if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5b) <
          *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d)) {
        uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)partyIndex << 2) >> 0x10);
        iVar7 = (int)*(undefined4 *)((uint)partyIndex << 2);
        if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5b) <
            (uint)(*(int *)(iVar7 + 0x4d) * 2 + *(int *)(iVar7 + 0x4d)) >> 2) {
          if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5b) <
              *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d) >> 1) {
            if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5b) <
                *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d) >> 2) {
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
    if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x54) <
        (uint)(*(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d) << 1)) {
      pcVar3 = (char *)((uint)partyIndex << 2);
      if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x54) <
          *(uint *)((int)*(undefined4 *)pcVar3 + 0x4d)) {
        pcVar3 = (char *)"halfling castle" + 0xc;
        if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x54) <
            *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d) >> 1) {
          pcVar3 = (char *)"halfling castle" + 0xc;
          if (*(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x54) < 0) {
            pcVar3 = (char *)"halfling castle" + 0xc;
            if (*(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x54) <
                (uint)-*(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x4d)) {
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
          ovc39_lordOrLady();
          pcVar4 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)msgFormat.ofs);
          ovr_drawString(pcVar4,(uint16_t)pcVar3);
        }
        else {
          pcStack_6 = (char *)ovc39_loadArchiveEntry(bStack_d + 0x17);
          pcStack_4 = pcVar3;
          ovc39_lordOrLady();
          pcVar4 = ovr_stsprintf((char *)&msg,unaff_SS,pcStack_6);
          ovr_drawString(pcVar4,(uint16_t)pcVar3);
          handle_06.seg = (uint16_t)pcStack_4;
          handle_06.ofs = (uint16_t)pcStack_6;
          ovr_stshFree(handle_06);
        }
      }
      else {
        pcStack_6 = (char *)ovc39_loadArchiveEntry(bStack_e + 0xd);
        pcStack_4 = pcVar3;
        ovc39_lordOrLady();
        pcVar4 = ovr_stsprintf((char *)&msg,unaff_SS,pcStack_6);
        ovr_drawString(pcVar4,(uint16_t)pcVar3);
        handle_05.seg = (uint16_t)pcStack_4;
        handle_05.ofs = (uint16_t)pcStack_6;
        ovr_stshFree(handle_05);
      }
    }
    else {
      pcStack_6 = (char *)ovc39_loadArchiveEntry(bStack_c + 0x12);
      pcStack_4 = pcVar3;
      ovc39_lordOrLady();
      pcVar4 = ovr_stsprintf((char *)&msg,unaff_SS,pcStack_6);
      ovr_drawString(pcVar4,(uint16_t)pcVar3);
      handle_04.seg = (uint16_t)pcStack_4;
      handle_04.ofs = (uint16_t)pcStack_6;
      ovr_stshFree(handle_04);
    }
  }
  return;
}


