/*
 * ovc39_archive.c - recovered from STRONG.EXE
 * memory block: OVC39_archive.c
 * range: 690b:0000 - 690b:0bcf
 * functions: 4
 */
#include "recovered.h"


/* 690b:0000 */

/* Loads an archive entry, allocates a buffer of its recorded size and copies it there. */

int __cdecl16far ovc39_loadArchiveEntry(byte fileId)

{
  uint32_t uVar1;
  far_t handle;
  stg_tmp_t *psVar2;
  stg_tmp_t *in_DX;
  uint16_t uVar3;
  int iVar4;
  uint16_t uVar5;
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
    uVar1 = *(uint32_t *)((uint)fileId * 4 + -0x6c70);
    uVar5 = (uint16_t)((ulong)uVar1 >> 0x10);
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
  if ((bVar1 == 0xff) || (((char_sheet_t *)(((uint)bVar1 << 2)))->gender == '\0')) {
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

uint16_t __cdecl16far ovc39_findBuildingAt(int x,uint16_t y)

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
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  far_t handle_03;
  far_t handle_04;
  far_t handle_05;
  far_t handle_06;
  uint uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  unit_t *puVar5;
  int iVar6;
  uint16_t uVar7;
  char *unaff_SS;
  uint8_t msg;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  byte bStack_c;
  byte bStack_b;
  byte bStack_a;
  byte bStack_9;
  uint uStack_8;
  int iStack_6;
  char *pcStack_4;
  
  if ((partyIndex != 0xff) &&
     (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x3f) == '\0')) {
    uStack_8 = ovr_alignUp4(GfxRndSeed,0,0);
    for (bStack_b = 0; bStack_b < 4; bStack_b = bStack_b + 1) {
      for (iVar6 = -2; iVar6 < 2; iVar6 = iVar6 + 1) {
        uVar1 = ovr_ovc23_findRecordAt(uStack_8 + iVar6,GfxRndSeed2,(char)GfxRndSeed2);
        if (uVar1 == 0xffff) {
          iVar2 = ovc39_findBuildingAt(uStack_8 + iVar6,GfxRndSeed2);
          uVar7 = (uint16_t)((ulong)GUnits >> 0x10);
          puVar5 = (unit_t *)GUnits;
          bStack_9 = (puVar5 + iVar2)->bldType;
          pcVar4 = (char *)0x26510;
          bStack_a = puVar5[iVar2].unitType;
          if ((((bStack_b == 0) &&
               (pcVar4 = (char *)0x2627a,
               *(char *)((int)*(uint32_t *)((uint)bStack_a << 2) + 0x3f) == '\0')) &&
              (0xf7 < iVar2)) && (pcVar4 = (char *)0x26510, puVar5[iVar2].level < 8)) {
            pcVar4 = (char *)&AgntAnms[0x88].missileDy;
            if ((*(uint *)((uint)bStack_9 * 0x27 + 0x121) & 0x80) == 0) {
              iStack_6 = ovc39_loadArchiveEntry(8);
            }
            else {
              iStack_6 = ovc39_loadArchiveEntry(9);
            }
            pcStack_4 = pcVar4;
            pcVar3 = ovc39_lordOrLady();
            pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(iStack_6,unaff_SS),
                                   (char *)CONCAT22(pcVar3,pcStack_4),(char)pcVar4);
            ovr_drawString(pcVar3,(uint16_t)pcVar4,(char)pcVar4);
            (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)pcStack_4;
            handle.ofs = iStack_6;
            (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)pcStack_4 >> 8);
            ovr_stshFree(handle);
            return;
          }
          if (((bStack_b == 1) && (iVar2 < 0xf8)) &&
             (pcVar4 = (char *)&AgntAnms[0x88].missileDy,
             (*(uint *)((uint)bStack_9 * 0x27 + 0x121) & 2) != 0)) {
            iStack_6 = ovc39_loadArchiveEntry(10);
            pcStack_4 = pcVar4;
            pcVar3 = ovc39_lordOrLady();
            pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(iStack_6,unaff_SS),
                                   (char *)CONCAT22(pcVar3,pcStack_4),(char)pcVar4);
            ovr_drawString(pcVar3,(uint16_t)pcVar4,(char)pcVar4);
            (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = (char)pcStack_4;
            handle_00.ofs = iStack_6;
            (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = (char)((uint)pcStack_4 >> 8);
            ovr_stshFree(handle_00);
            return;
          }
          if (((bStack_b == 2) && (iVar2 < 0xf8)) &&
             (pcVar4 = (char *)&AgntAnms[0x88].missileDy,
             (*(uint *)((uint)bStack_9 * 0x27 + 0x121) & 0x20) != 0)) {
            iStack_6 = ovc39_loadArchiveEntry(0xb);
            pcStack_4 = pcVar4;
            pcVar3 = ovc39_lordOrLady();
            pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(iStack_6,unaff_SS),
                                   (char *)CONCAT22(pcVar3,pcStack_4),(char)pcVar4);
            ovr_drawString(pcVar3,(uint16_t)pcVar4,(char)pcVar4);
            (*(uint8_t *)((uint8_t *)&(handle_01.seg))) = (char)pcStack_4;
            handle_01.ofs = iStack_6;
            (*(uint8_t *)((uint8_t *)&(handle_01.seg) + 1)) = (char)((uint)pcStack_4 >> 8);
            ovr_stshFree(handle_01);
            return;
          }
          if ((bStack_b == 3) &&
             (uVar1 = ovr_ovc45_compute4(uStack_8 + iVar6,GfxRndSeed2,(char)GfxRndSeed2),
             (char)uVar1 != '\0')) {
            iStack_6 = ovc39_loadArchiveEntry(0xc);
            pcStack_4 = pcVar4;
            pcVar3 = ovc39_lordOrLady();
            pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(iStack_6,unaff_SS),
                                   (char *)CONCAT22(pcVar3,pcStack_4),(char)pcVar4);
            ovr_drawString(pcVar3,(uint16_t)pcVar4,(char)pcVar4);
            (*(uint8_t *)((uint8_t *)&(handle_02.seg))) = (char)pcStack_4;
            handle_02.ofs = iStack_6;
            (*(uint8_t *)((uint8_t *)&(handle_02.seg) + 1)) = (char)((uint)pcStack_4 >> 8);
            ovr_stshFree(handle_02);
            return;
          }
          if (((bStack_b == 4) && (iVar2 < 0xf8)) &&
             (pcVar4 = (char *)&AgntAnms[0x88].missileDy,
             (*(uint *)((uint)bStack_9 * 0x27 + 0x121) & 0x400) != 0)) {
            iStack_6 = ovc39_loadArchiveEntry(0xd);
            pcStack_4 = pcVar4;
            pcVar3 = ovc39_lordOrLady();
            pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(iStack_6,unaff_SS),
                                   (char *)CONCAT22(pcVar3,pcStack_4),(char)pcVar4);
            ovr_drawString(pcVar3,(uint16_t)pcVar4,(char)pcVar4);
            (*(uint8_t *)((uint8_t *)&(handle_03.seg))) = (char)pcStack_4;
            handle_03.ofs = iStack_6;
            (*(uint8_t *)((uint8_t *)&(handle_03.seg) + 1)) = (char)((uint)pcStack_4 >> 8);
            ovr_stshFree(handle_03);
            return;
          }
        }
      }
    }
    uVar7 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
    iVar6 = (int)*(uint32_t *)((uint)partyIndex << 2);
    if (((char_sheet_t *)(((uint)partyIndex << 2)))->foodProd <
        (uint)(*(int *)(iVar6 + 0x4d) * 2 + *(int *)(iVar6 + 0x4d)) >> 1) {
      if (((char_sheet_t *)(((uint)partyIndex << 2)))->foodProd <
          ((char_sheet_t *)(((uint)partyIndex << 2)))->population) {
        uVar7 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
        iVar6 = (int)*(uint32_t *)((uint)partyIndex << 2);
        if (((char_sheet_t *)(((uint)partyIndex << 2)))->foodProd <
            (uint)(*(int *)(iVar6 + 0x4d) * 2 + *(int *)(iVar6 + 0x4d)) >> 2) {
          if (((char_sheet_t *)(((uint)partyIndex << 2)))->foodProd <
              ((char_sheet_t *)(((uint)partyIndex << 2)))->population >> 1) {
            if (((char_sheet_t *)(((uint)partyIndex << 2)))->foodProd <
                ((char_sheet_t *)(((uint)partyIndex << 2)))->population >> 2) {
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
    uVar7 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
    iVar2 = (int)*(uint32_t *)((uint)partyIndex << 2);
    iVar6 = *(int *)(iVar2 + 0x62);
    if ((iVar6 < 0) ||
       ((iVar6 == 0 &&
        (*(uint *)(iVar2 + 0x60) <
         (uint)(((char_sheet_t *)(((uint)partyIndex << 2)))->population * 0x28))))) {
      uVar7 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
      iVar2 = (int)*(uint32_t *)((uint)partyIndex << 2);
      iVar6 = *(int *)(iVar2 + 0x62);
      if ((iVar6 < 0) ||
         ((iVar6 == 0 &&
          (*(uint *)(iVar2 + 0x60) <
           (uint)(((char_sheet_t *)(((uint)partyIndex << 2)))->population * 0x14))))) {
        uVar7 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
        iVar2 = (int)*(uint32_t *)((uint)partyIndex << 2);
        iVar6 = *(int *)(iVar2 + 0x62);
        if ((iVar6 < 0) ||
           ((iVar6 == 0 &&
            (*(uint *)(iVar2 + 0x60) <
             (uint)(((char_sheet_t *)(((uint)partyIndex << 2)))->population * 0x3c) >> 2)))) {
          uVar7 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
          iVar2 = (int)*(uint32_t *)((uint)partyIndex << 2);
          iVar6 = *(int *)(iVar2 + 0x62);
          if ((iVar6 < 0) ||
             ((iVar6 == 0 &&
              (*(uint *)(iVar2 + 0x60) <
               (uint)(((char_sheet_t *)(((uint)partyIndex << 2)))->population * 0x14) >> 1))))
          {
            uVar7 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
            iVar2 = (int)*(uint32_t *)((uint)partyIndex << 2);
            iVar6 = *(int *)(iVar2 + 0x62);
            if ((iVar6 < 0) ||
               ((iVar6 == 0 &&
                (*(uint *)(iVar2 + 0x60) <
                 (uint)(((char_sheet_t *)(((uint)partyIndex << 2)))->population * 0x14) >> 2)))
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
    uVar7 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
    iVar6 = (int)*(uint32_t *)((uint)partyIndex << 2);
    if (((char_sheet_t *)(((uint)partyIndex << 2)))->housing <
        (uint)(*(int *)(iVar6 + 0x4d) * 2 + *(int *)(iVar6 + 0x4d)) >> 1) {
      if (((char_sheet_t *)(((uint)partyIndex << 2)))->housing <
          ((char_sheet_t *)(((uint)partyIndex << 2)))->population) {
        uVar7 = (uint16_t)((ulong)*(uint32_t *)((uint)partyIndex << 2) >> 0x10);
        iVar6 = (int)*(uint32_t *)((uint)partyIndex << 2);
        if (((char_sheet_t *)(((uint)partyIndex << 2)))->housing <
            (uint)(*(int *)(iVar6 + 0x4d) * 2 + *(int *)(iVar6 + 0x4d)) >> 2) {
          if (((char_sheet_t *)(((uint)partyIndex << 2)))->housing <
              ((char_sheet_t *)(((uint)partyIndex << 2)))->population >> 1) {
            if (((char_sheet_t *)(((uint)partyIndex << 2)))->housing <
                ((char_sheet_t *)(((uint)partyIndex << 2)))->population >> 2) {
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
    pcVar4 = (char *)0x2627a;
    if (*(uint *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x54) <
        (uint)(((char_sheet_t *)(((uint)partyIndex << 2)))->population << 1)) {
      pcVar4 = (char *)((uint)partyIndex << 2);
      if (*(uint *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x54) <
          ((char_sheet_t *)(pcVar4))->population) {
        pcVar4 = (char *)0x2627a;
        if (*(uint *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x54) <
            ((char_sheet_t *)(((uint)partyIndex << 2)))->population >> 1) {
          pcVar4 = (char *)0x2627a;
          if (*(int *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x54) < 0) {
            pcVar4 = (char *)0x2627a;
            if (*(uint *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x54) <
                (uint)-((char_sheet_t *)(((uint)partyIndex << 2)))->population) {
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
          pcVar3 = ovc39_lordOrLady();
          pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(msgFormat.ofs,unaff_SS),
                                 (char *)CONCAT22(pcVar3,msgFormat.seg),(char)pcVar4);
          ovr_drawString(pcVar3,(uint16_t)pcVar4,(char)pcVar4);
        }
        else {
          iStack_6 = ovc39_loadArchiveEntry(bStack_d + 0x17);
          pcStack_4 = pcVar4;
          pcVar3 = ovc39_lordOrLady();
          pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(iStack_6,unaff_SS),
                                 (char *)CONCAT22(pcVar3,pcStack_4),(char)pcVar4);
          ovr_drawString(pcVar3,(uint16_t)pcVar4,(char)pcVar4);
          (*(uint8_t *)((uint8_t *)&(handle_06.seg))) = (char)pcStack_4;
          handle_06.ofs = iStack_6;
          (*(uint8_t *)((uint8_t *)&(handle_06.seg) + 1)) = (char)((uint)pcStack_4 >> 8);
          ovr_stshFree(handle_06);
        }
      }
      else {
        iStack_6 = ovc39_loadArchiveEntry(bStack_e + 0xd);
        pcStack_4 = pcVar4;
        pcVar3 = ovc39_lordOrLady();
        pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(iStack_6,unaff_SS),
                               (char *)CONCAT22(pcVar3,pcStack_4),(char)pcVar4);
        ovr_drawString(pcVar3,(uint16_t)pcVar4,(char)pcVar4);
        (*(uint8_t *)((uint8_t *)&(handle_05.seg))) = (char)pcStack_4;
        handle_05.ofs = iStack_6;
        (*(uint8_t *)((uint8_t *)&(handle_05.seg) + 1)) = (char)((uint)pcStack_4 >> 8);
        ovr_stshFree(handle_05);
      }
    }
    else {
      iStack_6 = ovc39_loadArchiveEntry(bStack_c + 0x12);
      pcStack_4 = pcVar4;
      pcVar3 = ovc39_lordOrLady();
      pcVar3 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(iStack_6,unaff_SS),
                             (char *)CONCAT22(pcVar3,pcStack_4),(char)pcVar4);
      ovr_drawString(pcVar3,(uint16_t)pcVar4,(char)pcVar4);
      (*(uint8_t *)((uint8_t *)&(handle_04.seg))) = (char)pcStack_4;
      handle_04.ofs = iStack_6;
      (*(uint8_t *)((uint8_t *)&(handle_04.seg) + 1)) = (char)((uint)pcStack_4 >> 8);
      ovr_stshFree(handle_04);
    }
  }
  return;
}


