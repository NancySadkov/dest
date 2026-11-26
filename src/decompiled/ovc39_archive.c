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
  char *buf;
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
    buf = ovr_stshAlloc(CONCAT22(iStack_c,wStack_e));
    memcpy((char *)CONCAT22(psStack_8,buf),(char *)CONCAT22(uVar3,psVar2),wStack_e);
  }
  else {
    buf = ovr_stshAlloc(1);
    wStack_e = 1;
    psStack_8 = in_DX;
  }
  buf[wStack_e - 1] = '\0';
  return (int)buf;
}



/* 690b:00d1 */

/* Returns "lord" or "lady" for the first leader with a level, from the sheet's gender byte. */

char * __cdecl16far ovc39_lordOrLady(void)

{
  byte bVar1;
  char *pcVar2;
  
  bVar1 = ovr_manage_findFirstLeader();
  if ((bVar1 == 0xff) || ((GLeaderSheets[bVar1])->gender == '\0')) {
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
    if ((bVar1 != 0) && (bStack_4 < BuildingTypes[bVar1].size)) break;
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
  uint recordIdx;
  uint nearFlag;
  int unitIndex;
  char *textPtr;
  char *nameOfs;
  unit_t *units;
  int rowOffset;
  int storedHi;
  uint8_t msg;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  byte bStack_c;
  byte bStack_b;
  byte unitType;
  byte unitBldType;
  uint seedAligned;
  int archEntry;
  char *name;
  
  if ((partyIndex != 0xff) &&
     (*((char far *)GLeaderSheets[partyIndex] + 0x3f) == '\0')) {
    seedAligned = ovr_alignUp4(GfxRndSeed,0,0);
    for (bStack_b = 0; bStack_b < 4; bStack_b = bStack_b + 1) {
      for (rowOffset = -2; rowOffset < 2; rowOffset = rowOffset + 1) {
        recordIdx = ovr_ovc23_findRecordAt(seedAligned + rowOffset,GfxRndSeed2,(char)GfxRndSeed2);
        if (recordIdx == 0xffff) {
          unitIndex = ovc39_findBuildingAt(seedAligned + rowOffset,GfxRndSeed2);
          units = GUnits;
          unitBldType = (units + unitIndex)->bldType;
          nameOfs = (char *)0x26510;
          unitType = units[unitIndex].unitType;
          if ((((bStack_b == 0) &&
               (nameOfs = (char *)0x2627a,
               *(char *)((int)*(uint32_t *)((uint)unitType << 2) + 0x3f) == '\0')) &&
              (0xf7 < unitIndex)) && (nameOfs = (char *)0x26510, units[unitIndex].level < 8)) {
            nameOfs = (char *)&AgntAnms[0x88].missileDy;
            if ((BuildingTypes[unitBldType].flags2 & 0x80) == 0) {
              archEntry = ovc39_loadArchiveEntry(8);
            }
            else {
              archEntry = ovc39_loadArchiveEntry(9);
            }
            name = nameOfs;
            textPtr = ovc39_lordOrLady();
            textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(archEntry,_SS),
                                   (char *)CONCAT22(textPtr,name),(char)nameOfs);
            ovr_drawString(textPtr,(uint16_t)nameOfs,(char)nameOfs);
            (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)name;
            handle.ofs = archEntry;
            (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)name >> 8);
            ovr_stshFree(handle);
            return;
          }
          if (((bStack_b == 1) && (unitIndex < 0xf8)) &&
             (nameOfs = (char *)&AgntAnms[0x88].missileDy,
             (BuildingTypes[unitBldType].flags2 & 2) != 0)) {
            archEntry = ovc39_loadArchiveEntry(10);
            name = nameOfs;
            textPtr = ovc39_lordOrLady();
            textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(archEntry,_SS),
                                   (char *)CONCAT22(textPtr,name),(char)nameOfs);
            ovr_drawString(textPtr,(uint16_t)nameOfs,(char)nameOfs);
            (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = (char)name;
            handle_00.ofs = archEntry;
            (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = (char)((uint)name >> 8);
            ovr_stshFree(handle_00);
            return;
          }
          if (((bStack_b == 2) && (unitIndex < 0xf8)) &&
             (nameOfs = (char *)&AgntAnms[0x88].missileDy,
             (BuildingTypes[unitBldType].flags2 & 0x20) != 0)) {
            archEntry = ovc39_loadArchiveEntry(0xb);
            name = nameOfs;
            textPtr = ovc39_lordOrLady();
            textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(archEntry,_SS),
                                   (char *)CONCAT22(textPtr,name),(char)nameOfs);
            ovr_drawString(textPtr,(uint16_t)nameOfs,(char)nameOfs);
            (*(uint8_t *)((uint8_t *)&(handle_01.seg))) = (char)name;
            handle_01.ofs = archEntry;
            (*(uint8_t *)((uint8_t *)&(handle_01.seg) + 1)) = (char)((uint)name >> 8);
            ovr_stshFree(handle_01);
            return;
          }
          if ((bStack_b == 3) &&
             (nearFlag = ovr_ovc45_compute4(seedAligned + rowOffset,GfxRndSeed2,(char)GfxRndSeed2),
             (char)nearFlag != '\0')) {
            archEntry = ovc39_loadArchiveEntry(0xc);
            name = nameOfs;
            textPtr = ovc39_lordOrLady();
            textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(archEntry,_SS),
                                   (char *)CONCAT22(textPtr,name),(char)nameOfs);
            ovr_drawString(textPtr,(uint16_t)nameOfs,(char)nameOfs);
            (*(uint8_t *)((uint8_t *)&(handle_02.seg))) = (char)name;
            handle_02.ofs = archEntry;
            (*(uint8_t *)((uint8_t *)&(handle_02.seg) + 1)) = (char)((uint)name >> 8);
            ovr_stshFree(handle_02);
            return;
          }
          if (((bStack_b == 4) && (unitIndex < 0xf8)) &&
             (nameOfs = (char *)&AgntAnms[0x88].missileDy,
             (BuildingTypes[unitBldType].flags2 & 0x400) != 0)) {
            archEntry = ovc39_loadArchiveEntry(0xd);
            name = nameOfs;
            textPtr = ovc39_lordOrLady();
            textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(archEntry,_SS),
                                   (char *)CONCAT22(textPtr,name),(char)nameOfs);
            ovr_drawString(textPtr,(uint16_t)nameOfs,(char)nameOfs);
            (*(uint8_t *)((uint8_t *)&(handle_03.seg))) = (char)name;
            handle_03.ofs = archEntry;
            (*(uint8_t *)((uint8_t *)&(handle_03.seg) + 1)) = (char)((uint)name >> 8);
            ovr_stshFree(handle_03);
            return;
          }
        }
      }
    }
    if ((GLeaderSheets[partyIndex])->foodProd <
        (uint)((int)(GLeaderSheets[partyIndex])->population * 2 + (int)(GLeaderSheets[partyIndex])->population) >> 1) {
      if ((GLeaderSheets[partyIndex])->foodProd <
          (GLeaderSheets[partyIndex])->population) {
        if ((GLeaderSheets[partyIndex])->foodProd <
            (uint)((int)(GLeaderSheets[partyIndex])->population * 2 + (int)(GLeaderSheets[partyIndex])->population) >> 2) {
          if ((GLeaderSheets[partyIndex])->foodProd <
              (GLeaderSheets[partyIndex])->population >> 1) {
            if ((GLeaderSheets[partyIndex])->foodProd <
                (GLeaderSheets[partyIndex])->population >> 2) {
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
    storedHi = (int)((GLeaderSheets[partyIndex])->foodStored >> 16);
    if ((storedHi < 0) ||
       ((storedHi == 0 &&
        ((uint16_t)(GLeaderSheets[partyIndex])->foodStored <
         (uint)((GLeaderSheets[partyIndex])->population * 0x28))))) {
      storedHi = (int)((GLeaderSheets[partyIndex])->foodStored >> 16);
      if ((storedHi < 0) ||
         ((storedHi == 0 &&
          ((uint16_t)(GLeaderSheets[partyIndex])->foodStored <
           (uint)((GLeaderSheets[partyIndex])->population * 0x14))))) {
        storedHi = (int)((GLeaderSheets[partyIndex])->foodStored >> 16);
        if ((storedHi < 0) ||
           ((storedHi == 0 &&
            ((uint16_t)(GLeaderSheets[partyIndex])->foodStored <
             (uint)((GLeaderSheets[partyIndex])->population * 0x3c) >> 2)))) {
          storedHi = (int)((GLeaderSheets[partyIndex])->foodStored >> 16);
          if ((storedHi < 0) ||
             ((storedHi == 0 &&
              ((uint16_t)(GLeaderSheets[partyIndex])->foodStored <
               (uint)((GLeaderSheets[partyIndex])->population * 0x14) >> 1))))
          {
            storedHi = (int)((GLeaderSheets[partyIndex])->foodStored >> 16);
            if ((storedHi < 0) ||
               ((storedHi == 0 &&
                ((uint16_t)(GLeaderSheets[partyIndex])->foodStored <
                 (uint)((GLeaderSheets[partyIndex])->population * 0x14) >> 2)))
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
    if ((GLeaderSheets[partyIndex])->housing <
        (uint)((int)(GLeaderSheets[partyIndex])->population * 2 + (int)(GLeaderSheets[partyIndex])->population) >> 1) {
      if ((GLeaderSheets[partyIndex])->housing <
          (GLeaderSheets[partyIndex])->population) {
        if ((GLeaderSheets[partyIndex])->housing <
            (uint)((int)(GLeaderSheets[partyIndex])->population * 2 + (int)(GLeaderSheets[partyIndex])->population) >> 2) {
          if ((GLeaderSheets[partyIndex])->housing <
              (GLeaderSheets[partyIndex])->population >> 1) {
            if ((GLeaderSheets[partyIndex])->housing <
                (GLeaderSheets[partyIndex])->population >> 2) {
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
    nameOfs = (char *)0x2627a;
    if ((uint)(GLeaderSheets[partyIndex])->income <
        (uint)((GLeaderSheets[partyIndex])->population << 1)) {
      if ((uint)(GLeaderSheets[partyIndex])->income <
          (GLeaderSheets[partyIndex])->population) {
        nameOfs = (char *)0x2627a;
        if ((uint)(GLeaderSheets[partyIndex])->income <
            (GLeaderSheets[partyIndex])->population >> 1) {
          nameOfs = (char *)0x2627a;
          if ((int)(GLeaderSheets[partyIndex])->income < 0) {
            nameOfs = (char *)0x2627a;
            if ((uint)(GLeaderSheets[partyIndex])->income <
                (uint)-(GLeaderSheets[partyIndex])->population) {
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
          textPtr = ovc39_lordOrLady();
          textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(msgFormat.ofs,_SS),
                                 (char *)CONCAT22(textPtr,msgFormat.seg),(char)nameOfs);
          ovr_drawString(textPtr,(uint16_t)nameOfs,(char)nameOfs);
        }
        else {
          archEntry = ovc39_loadArchiveEntry(bStack_d + 0x17);
          name = nameOfs;
          textPtr = ovc39_lordOrLady();
          textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(archEntry,_SS),
                                 (char *)CONCAT22(textPtr,name),(char)nameOfs);
          ovr_drawString(textPtr,(uint16_t)nameOfs,(char)nameOfs);
          (*(uint8_t *)((uint8_t *)&(handle_06.seg))) = (char)name;
          handle_06.ofs = archEntry;
          (*(uint8_t *)((uint8_t *)&(handle_06.seg) + 1)) = (char)((uint)name >> 8);
          ovr_stshFree(handle_06);
        }
      }
      else {
        archEntry = ovc39_loadArchiveEntry(bStack_e + 0xd);
        name = nameOfs;
        textPtr = ovc39_lordOrLady();
        textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(archEntry,_SS),
                               (char *)CONCAT22(textPtr,name),(char)nameOfs);
        ovr_drawString(textPtr,(uint16_t)nameOfs,(char)nameOfs);
        (*(uint8_t *)((uint8_t *)&(handle_05.seg))) = (char)name;
        handle_05.ofs = archEntry;
        (*(uint8_t *)((uint8_t *)&(handle_05.seg) + 1)) = (char)((uint)name >> 8);
        ovr_stshFree(handle_05);
      }
    }
    else {
      archEntry = ovc39_loadArchiveEntry(bStack_c + 0x12);
      name = nameOfs;
      textPtr = ovc39_lordOrLady();
      textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(archEntry,_SS),
                             (char *)CONCAT22(textPtr,name),(char)nameOfs);
      ovr_drawString(textPtr,(uint16_t)nameOfs,(char)nameOfs);
      (*(uint8_t *)((uint8_t *)&(handle_04.seg))) = (char)name;
      handle_04.ofs = archEntry;
      (*(uint8_t *)((uint8_t *)&(handle_04.seg) + 1)) = (char)((uint)name >> 8);
      ovr_stshFree(handle_04);
    }
  }
  return;
}


