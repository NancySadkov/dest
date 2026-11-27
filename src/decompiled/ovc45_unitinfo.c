/*
 * ovc45_unitinfo.c - recovered from STRONG.EXE
 * memory block: OVC45_unitinfo.c
 * range: 77eb:0000 - 77eb:26bf
 * functions: 29
 */
#include "recovered.h"


/* 77eb:0121 */

/* Returns the bldType of the unit in GUnitGrid[x][y], or 0 outside the map. */

/* 77eb:0121 */

byte __cdecl16far ovc45_getUnitType(int x,int y)

{
  byte bVar1;
  
  if ((((x < 0x94) && (-1 < x)) && (y < 0x3c)) && (-1 < y)) {
    bVar1 = (GUnits + (*(short (*) [148] [60])GUnitGrid)[x][y])->bldType;
  }
  else {
    bVar1 = 0;
  }
  return bVar1;
}



/* 77eb:0179 */

/* Returns GUnitGrid[x][y] (the unit index) inside the map bounds, else 0. */

/* 77eb:0179 */

short __cdecl16far ovc45_getUnitIndex(int x,int y)

{
  short sVar1;
  
  if ((((x < 0x94) && (-1 < x)) && (y < 0x3c)) && (-1 < y)) {
    sVar1 = (*(short (*) [148] [60])GUnitGrid)[x][y];
  }
  else {
    sVar1 = 0;
  }
  return sVar1;
}



/* 77eb:01bb */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

/* 77eb:01bb */

uint __cdecl16far ovc45_usesAlignUp4(int slotMin,int x,uint16_t y,uint *entityIndexOut)

{
  uint uVar1;
  uint uVar3;
  uint *in_stack_0000000a;
  byte bStack_3;
  
  bStack_3 = 0xff;
  for (uVar3 = 0; uVar3 < EntityCount; uVar3 = uVar3 + 1) {
    uVar1 = ovr_alignUp4((Entities)[uVar3].base.x,0,0);
    if (uVar1 == x) {
      if (((((Entities)[uVar3].base.y == y) &&
           (AgntGs[(uint)(Entities)[uVar3].base.gindex].ai == '\0')) &&
          (slotMin < (int)(uint)AGNT_FIELD(&(Entities)[uVar3], base.entity, 3))) &&
         (AGNT_FIELD(&(Entities)[uVar3], base.entity, 3) < bStack_3)) {
        bStack_3 = AGNT_FIELD(&(Entities)[uVar3], base.entity, 3);
        *(uint *)CONCAT22((uint *)entityIndexOut,in_stack_0000000a) = uVar3;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Finds the entity at (x,y) and writes its index and a found flag through the out pointers. */

char * __cdecl16far
ovc45_findEntityAt(uint16_t x,uint16_t y,uint *foundIndex,uint8_t *foundFlagOut,char foundFlag)

{
  /* Re-derived from 77eb:02c1.  Both out-parameters are far pointers read directly by the
     original, so the exported CONCAT22/CONCAT13 constructions - which mixed one parameter's
     offset with another's segment - reduce to *foundIndex and *foundFlagOut.  The
     in_stack_00000010 comparisons were the segment half of foundFlagOut and are really the
     5th argument `foundFlag`.  x is reassigned by alignUp4 (`mov word ptr [bp+6], ax`). */
  uint alignedX;
  uint entAlignedX;
  int entitiesOfs;
  uint entIdx;
  uint grpOfs;
  uint lastParty;
  uint selIdx;
  uint fallbackIdx;

  *foundFlagOut = 0;
  alignedX = ovr_alignUp4(x,0,0);
  *foundIndex = 0xffff;
  selIdx = 0xffff;
  fallbackIdx = 0xffff;
  lastParty = 0xffff;
  for (entIdx = 0; entIdx < EntityCount; entIdx = entIdx + 1) {
    entAlignedX = ovr_alignUp4((Entities)[entIdx].base.x,0,0);
    if (entAlignedX == alignedX) {
      entitiesOfs = (int)Entities;
      if (((entity_t *)entitiesOfs)[entIdx].base.y == y) {
        grpOfs = (uint)((entity_t *)entitiesOfs)[entIdx].base.gindex * 0x95;
        if (*(char *)((int)(char **)GMenuStrings + grpOfs + 0x1f) != '\0') {
          return (char *)(grpOfs & 0xff00);
        }
        if ((AgntGs[(uint)((entity_t *)entitiesOfs)[entIdx].base.gindex].shortName[3] != -1) &&
           (AGNT_FIELD(&(Entities)[entIdx], base.entity, 3) != -1)) {
          if (AGNT_FIELD(&(Entities)[entIdx], base.entity, 3) == foundFlag) {
            *foundIndex = entIdx;
          }
          else if (AGNT_FIELD(&(Entities)[entIdx], base.entity, 3) ==
                   selectedPartyIndex) {
            selIdx = entIdx;
          }
          if ((lastParty != 0xffff) &&
             (AGNT_FIELD(&(Entities)[entIdx], base.entity, 3) != lastParty)) {
            *foundFlagOut = 1;
          }
          lastParty = (uint)AGNT_FIELD(&(Entities)[entIdx], base.entity, 3);
          fallbackIdx = entIdx;
        }
      }
    }
  }
  if (*foundIndex == 0xffff) {
    if (selIdx == 0xffff) {
      if (fallbackIdx == 0xffff) {
        return (char *)0x2400;
      }
      *foundIndex = fallbackIdx;
    }
    else {
      *foundIndex = selIdx;
    }
  }
  grpOfs = (uint)*(byte *)((int)Entities + *foundIndex * 0x37 + 0xd) * 0x95;
  selectedPartyIndex = *(undefined1 *)((int)Entities + *foundIndex * 0x37 + 0x1a);
  return (char *)CONCAT11((char)((uint)grpOfs >> 8),
                          '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 + grpOfs) &
                                      0x1f));
}



/* 77eb:04d8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R2] string "Choose party to build for.  Now building" */

/* 77eb:04d8 */

uint16_t __cdecl16far ovc45_textChoosePartyBuild(uint16_t x,uint16_t y,int *entityIndexPtr,uint16_t arg4)

{
  far_t entries;
  far_t hint;
  uint x_00;
  int iVar1;
  uint16_t *puVar2;
  char *pcVar3;
  uint8_t *puVar4;
  uint16_t uVar5;
  uint16_t count;
  uint16_t unaff_DI;
  uint slotMin;
  uint8_t foundEntities;
  uint8_t menuItems;
  int aiStack_2c [19];
  uint8_t entityIndex;
  char cStack_3;
  
  x_00 = ovr_alignUp4(x,0,0);
  entityIndex = *entityIndexPtr;
  slotMin = 0xffff;
  for (count = 0; (int)count < 10; count = count + 1) {
    slotMin = ovc45_usesAlignUp4(slotMin,x_00,y,(uint *)CONCAT22(unaff_DI,_SS));
    if (slotMin == 0xffff) break;
    *(int *)(&foundEntities + count * 2) = entityIndex;
    uVar5 = *(uint16_t *)(slotMin * 4);
    aiStack_2c[count * 2] = ((uint16_t *)(slotMin * 4))[1];
    *(uint16_t *)(&menuItems + count * 4) = uVar5;
  }
  if ((int)count < 2) {
    *entityIndexPtr = entityIndex;
    iVar1 = (uint)*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0xd) * 0x95;
    uVar5 = CONCAT11((char)((uint)iVar1 >> 8),
                     '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 + iVar1) & 0x1f));
  }
  else {
    ovr_ovc22_className(*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0x1a),0);
    puVar2 = (uint16_t *)((uint)*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0x1a) * 4);
    uVar5 = _DS;
    pcVar3 = ovr_fmVsprintf("Choose party to build for.  Now building for %s the %s.",
                            (char *)CONCAT22(puVar2[1],(char *)*puVar2));
    puVar4 = &menuItems;
    entries.seg = (uint16_t)_SS;
    entries.ofs = (uint16_t)puVar4;
    (*(uint8_t *)((uint8_t *)&(hint.seg))) = (char)uVar5;
    hint.ofs = (uint16_t)pcVar3;
    (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = (char)((uint)uVar5 >> 8);
    ovr_ovc28_compute2(entries,count,hint,0,0);
    cStack_3 = (char)puVar4;
    if ((char)puVar4 == '\0') {
      uVar5 = 0xff;
    }
    else {
      *entityIndexPtr = aiStack_2c[((uint)puVar4 & 0xff) - 0xc];
      uVar5 = (uint16_t)((ulong)Entities >> 0x10);
      selectedPartyIndex = *(undefined1 *)((int)Entities + *entityIndexPtr * 0x37 + 0x1a);
      iVar1 = (uint)*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0xd) * 0x95;
      uVar5 = CONCAT11((char)((uint)iVar1 >> 8),
                       '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 + iVar1) & 0x1f));
    }
  }
  return uVar5;
}



/* 77eb:0683 */

/* [R6] touches GMapFlags, GUnits */

/* 77eb:0683 */

uint8_t __cdecl16far ovc45_usesGMapFlags(int x,int y)

{
  /* 77eb:0683, re-derived.  The map word for (x,y) is the word at
     GMapFlags + y*0x128 + x*2 + 0x128; bits 0-1 nonzero means the square is already flagged.  Only
     AL is ever written on the three return paths, so the result is a byte, not a word (the tree's
     CONCAT11 pairs were the decompiler's rendering of that uninitialised AH).  The building lookup
     is BuildingTypes[GUnits[idx].bldType] with the type stride 0x27, and the tested word is flags2
     at +0x13 (image 0x60:0x121 = base 0x10e + 0x13). */
  short *rowPtr;
  short unitIdx;

  rowPtr = (*(short (*) [60] [148])GMapFlags)[y] + x;
  if ((rowPtr[0x94] & 3U) != 0) {
    return 1;
  }
  unitIdx = ovc45_getUnitIndex(x,y);
  return (uint8_t)((BuildingTypes[(GUnits + unitIdx)->bldType].flags2 & 0x18) != 0);
}



/* 77eb:0708 */

/* [R6] touches GMapFlags */

/* 77eb:0708 */

bool __cdecl16far ovc45_usesGMapFlags2(int x,int y)

{
  return ((*(short (*) [60] [148])GMapFlags)[y + 1][x] & 3U) == 3;
}



/* 77eb:0742 */

/* Returns whether the map cell directly below (x,y) has either of its low two flag bits set. */

/* 77eb:0742 */

int __cdecl16far ovc45_cellBelowBlocked(int x,int y)

{
  short *psVar1;
  byte bVar3;
  int iVar2;
  
  psVar1 = (*(short (*) [60] [148])GMapFlags)[y] + x;
  bVar3 = (byte)((uint)psVar1 >> 8);
  if ((psVar1[0x94] & 3U) == 0) {
    iVar2 = (uint)bVar3 << 8;
  }
  else {
    iVar2 = CONCAT11(bVar3,1);
  }
  return iVar2;
}



/* 77eb:0778 */

/* [R7] body shape: compute */

/* 77eb:0778 */

uint __cdecl16far ovc45_compute1(byte bldType,int x,int y)

{
  bool flag;
  uint mapRes;
  uint bldOfs;
  
  if ((BuildingTypes[bldType].flags2 & 0x10) != 0) {
    mapRes = ovc45_usesGMapFlags(x,y + 1);
    if ((((mapRes & 0xff) == 0) && (mapRes = ovc45_usesGMapFlags(x,y), (mapRes & 0xff) == 0)) &&
       (mapRes = ovc45_usesGMapFlags(x,y + -1), (mapRes & 0xff) == 0)) {
      return 0;
    }
    flag = ovc45_usesGMapFlags2(x,y + 1);
    if (((flag) && (flag = ovc45_usesGMapFlags2(x,y), flag)) &&
       (flag = ovc45_usesGMapFlags2(x,y + -1), flag)) {
      return 0;
    }
    mapRes = ovc45_cellBelowBlocked(x,y + 1);
    if ((((mapRes & 0xff) == 0) && (mapRes = ovc45_cellBelowBlocked(x,y), (mapRes & 0xff) == 0)) &&
       (mapRes = ovc45_cellBelowBlocked(x,y + -1), (mapRes & 0xff) == 0)) {
      return 0;
    }
  }
  bldOfs = (uint)bldType * 0x27;
  if ((*(uint *)(bldOfs + 0x121) & 8) != 0) {
    mapRes = ovc45_usesGMapFlags(x,y);
    if ((((mapRes & 0xff) == 0) && (mapRes = ovc45_usesGMapFlags(x + -1,y), (mapRes & 0xff) == 0)) &&
       (mapRes = ovc45_usesGMapFlags(x + 1,y), (mapRes & 0xff) == 0)) {
      return 0;
    }
    flag = ovc45_usesGMapFlags2(x,y);
    if (((flag) && (flag = ovc45_usesGMapFlags2(x + -1,y), flag)) &&
       (flag = ovc45_usesGMapFlags2(x + 1,y), flag)) {
      return 0;
    }
    mapRes = ovc45_cellBelowBlocked(x,y);
    mapRes = mapRes & 0xff;
    if (mapRes == 0) {
      mapRes = ovc45_cellBelowBlocked(x + -1,y);
      mapRes = mapRes & 0xff;
      if (mapRes == 0) {
        mapRes = ovc45_cellBelowBlocked(x + 1,y);
        mapRes = mapRes & 0xff;
        if (mapRes == 0) {
          return 0;
        }
      }
    }
  }
  return 1;
}



/* 77eb:0904 */

/* [R4] calls LDIV_at_ */

/* 77eb:0904 */

uint16_t __cdecl16far ovc45_usesLDIV_at_(uint8_t partyIndex,uint16_t arg2,uint16_t arg3)

{
  long *plVar1;
  uint16_t dividendHi;
  uint unaff_SI;
  long lVar3;
  uint16_t divisorLo;
  uint16_t divisorHi;
  long in_stack_0000fffa;
  
  divisorHi = 0;
  divisorLo = 10;
  dividendHi = GPopulationHi;
  plVar1 = LXMUL_at_((long *)((byte *)__C0_ASM_CopyRight + 6),(ulong)unaff_SI << 0x10,
                     in_stack_0000fffa);
  lVar3 = LDIV_at_((long)CONCAT22(dividendHi,plVar1),CONCAT22(divisorHi,divisorLo));
  return (int)lVar3;
}



/* 77eb:0976 */

/* Returns the leader's rank as a percentage (rank*10, capped at 100). */

/* 77eb:0976 */

int __cdecl16far ovc45_rankPercent(byte partyIndex)

{
  int iVar1;
  
  if ((GLeaderSheets[partyIndex])->rank < 0xb) {
    iVar1 = (GLeaderSheets[partyIndex])->rank * 10;
  }
  else {
    iVar1 = 100;
  }
  return iVar1;
}



/* 77eb:09c1 */

/* [R7] body shape: compute */

/* 77eb:09c1 */

int __cdecl16far ovc45_compute3(byte partyIndex)

{
  int iVar1;
  int iVar3;
  
  iVar1 = (int)(uint32_t)GLeaderSheets[partyIndex];
  iVar3 = *(int *)(iVar1 + 0x56);
  iVar1 = ovc45_usesLDIV_at_(partyIndex,iVar3,*(uint16_t *)(iVar1 + 0x58));
  return iVar3 + iVar1;
}



/* 77eb:0a02 */

/* [R6] touches GPopulationLo, GPopulationHi */

/* 77eb:0a02 */

void __cdecl16far ovc45_usesGPopulationLo(byte partyIndex,uint goldLo,int goldHi)

{
  /* Re-derived.  The party sheet keeps a 32-bit gold value at +0x56 (low) and +0x58
     (high).  When the sheet cannot cover goldLo/goldHi the sheet is zeroed and the
     remainder is taken from the population counters instead, split between the
     ovc45_usesLDIV_at_ result and the shortfall by comparing both halves.  The dead
     segment half (uVar8) is gone; the export's iVar5 carried two roles (party offset,
     then _DS) and is split into partyOfs / dsValue. */
  uint *goldLoPtr;
  int *goldHiPtr;
  uint oldLo;
  uint costLo;
  int costHi;
  int partyOfs;
  int dsValue;
  uint availLo;
  int sheetHi;
  bool borrow;

  partyOfs = (int)(uint32_t)GLeaderSheets[partyIndex];
  sheetHi = *(int *)(partyOfs + 0x58);
  if ((sheetHi < goldHi) || ((sheetHi == goldHi && (*(uint *)(partyOfs + 0x56) < goldLo)))) {
    partyOfs = (int)(uint32_t)GLeaderSheets[partyIndex];
    oldLo = *(uint *)(partyOfs + 0x56);
    costLo = goldLo - oldLo;
    costHi = (goldHi - *(int *)(partyOfs + 0x58)) - (uint)(goldLo < oldLo);
    dsValue = _DS;
    partyOfs = (int)(uint32_t)GLeaderSheets[partyIndex];
    *(uint16_t *)(partyOfs + 0x58) = 0;
    *(uint16_t *)(partyOfs + 0x56) = 0;
    availLo = ovc45_usesLDIV_at_(partyIndex,0,0);
    if ((costHi < dsValue) || ((costHi == dsValue && (costLo < availLo)))) {
      borrow = GPopulationLo < costLo;
      GPopulationLo = GPopulationLo - costLo;
      GPopulationHi = (GPopulationHi - costHi) - (uint)borrow;
    }
    else {
      borrow = GPopulationLo < availLo;
      GPopulationLo = GPopulationLo - availLo;
      GPopulationHi = (GPopulationHi - dsValue) - (uint)borrow;
    }
  }
  else {
    partyOfs = (int)(uint32_t)GLeaderSheets[partyIndex];
    goldLoPtr = (uint *)(partyOfs + 0x56);
    oldLo = *goldLoPtr;
    *goldLoPtr = *goldLoPtr - goldLo;
    goldHiPtr = (int *)(partyOfs + 0x58);
    *goldHiPtr = (*goldHiPtr - goldHi) - (uint)(oldLo < goldLo);
  }
  return;
}



/* 77eb:0aea */

/* [R7] body shape: compute */

/* 77eb:0aea */

uint __cdecl16far ovc45_compute4(int x,uint16_t y,uint16_t arg3)

{
  byte cellType;
  uint flagVal;
  uint recIdx;
  uint result;
  byte extraout_AH;
  byte sizeHi;
  
  flagVal = ovr_constr_usesGMapFlags(x,y,0);
  if ((flagVal & 0xff) == 0) {
    result = 0;
  }
  else {
    recIdx = ovr_ovc23_findRecordAt(x,y,0);
    if (recIdx == 0xffff) {
      cellType = ovc45_getUnitType(x,y);
      if (CONCAT11(extraout_AH,cellType) == 0) {
        cellType = ovc45_getUnitType(x + -1,y);
        if (BuildingTypes[cellType].size < 2) {
          cellType = ovc45_getUnitType(x + -2,y);
          if (BuildingTypes[cellType].size < 3) {
            cellType = ovc45_getUnitType(x + -3,y);
            sizeHi = (byte)((uint)cellType * 0x27 >> 8);
            if (BuildingTypes[cellType].size < 4) {
              result = CONCAT11(sizeHi,1);
            }
            else {
              result = (uint)sizeHi << 8;
            }
          }
          else {
            result = (uint)cellType * 0x27 & 0xff00;
          }
        }
        else {
          result = (uint)cellType * 0x27 & 0xff00;
        }
      }
      else {
        result = (uint)extraout_AH << 8;
      }
    }
    else {
      result = result & 0xff00;
    }
  }
  return result;
}



/* 77eb:0bc1 */

/* [R7] body shape: compute */

/* 77eb:0bc1 */

uint __cdecl16far ovc45_compute5(void)

{
  uint32_t sheetPtr;
  byte leaderIdx;
  byte extraout_AH;
  uint result;
  
  leaderIdx = ovr_manage_findFirstLeader();
  if (leaderIdx == 0xff) {
    result = (uint)extraout_AH << 8;
  }
  else {
    sheetPtr = *(uint32_t *)((uint)leaderIdx << 2);
    if (*(byte *)((int)sheetPtr + 0x86) < 4) {
      result = CONCAT11((char)(((uint)leaderIdx << 2) >> 8),4);
    }
    else if ((GLeaderSheets[leaderIdx])->titleIndex < 9) {
      sheetPtr = *(uint32_t *)((uint)leaderIdx << 2);
      result = CONCAT11((char)(((uint)leaderIdx << 2) >> 8),*(char *)((int)sheetPtr + 0x86) + '\x01');
    }
    else {
      result = (uint)(leaderIdx >> 6) << 8;
    }
  }
  return result;
}



/* 77eb:0c36 */

/* [R2] string "arena" */

/* 77eb:0c36 */

bool __cdecl16far ovc45_textArena2(byte bldType)

{
  /* Re-derived: true when a unit of the queried building type exists among the placed units
     or among the construction records, counting only entries whose leader sheet +0x3f byte is
     clear.  The segment half uVar4 was dead. */
  byte unitType;
  uint32_t sheetRef;
  uint idx;

  if (BuildingTypes[bldType].unitType == '\x17') {
    for (idx = 0xf8; idx < GUnitCount; idx = idx + 1) {
      unitType = (GUnits)[idx].unitType;
      if (((BuildingTypes[(uint)(GUnits + idx)->bldType].unitType == '\x17') &&
          (unitType != 0xff)) &&
         (sheetRef = *(uint32_t *)((uint)unitType << 2),
          *(char *)((int)sheetRef + 0x3f) == '\0')) {
        return true;
      }
    }
    for (idx = 0; idx < GRecordCount; idx = idx + 1) {
      unitType = GRecords[idx].party;
      if (((BuildingTypes[GRecords[idx].reserved08].unitType == '\x17') &&
          (unitType != 0xff)) &&
         (sheetRef = *(uint32_t *)((uint)unitType << 2),
          *(char *)((int)sheetRef + 0x3f) == '\0')) {
        return true;
      }
    }
  }
  return false;
}



/* 77eb:0d61 */

/* Building-placement message builder.  Image extent 0x0d61..0x16b2 (2,385 bytes) plus the
   five-entry switch jump table at cs:0x16a8.

   The 3,202-line body that used to live here was NOT this function: it was the asset
   stubify/RLE loader (201 ovr_stshRleType2, 190 stsh_store, 138 func_0x0007ffe0, 59
   ovr_stgFreeTmp, 57 ovr_grabLbmTR, 38 ovr_stshStoreFile).  That body lives, byte for byte, in
   ovc44's getcache (6ffe:02f7) in ovc44_strong_dat.c; it also overflowed Borland's compiler
   table limit, which is why this module could not be listed at all (`--only o45 --asm`).

   What the image does (tmp/o45_d61.txt + tmp/o45_d61b.txt):
     - parameters: x at [bp+6], y at [bp+8] (kept in di), entity index at [bp+0xa], an in/out
       result byte at [bp+0xc] and a flag byte at [bp+0xe];
     - the moving entity is GEntities[entityIndex] (stride 0x37) and its +0x1a byte selects
       GLeaderSheets[] (segment 0x70 at run time), whose sheet byte +0x85 gives the building type;
     - BuildingTypes[bldType] (stride 0x27; image base 0060:010e, model base 195d:010e) supplies
       name/description (far strings at +0/+4), kind (+0x0c), size (+0x0d), flags (+0x10),
       flags2 (+0x13), cost (+0x17), unitType (+0x25) and flags3 (+0x26);
     - the 15 rejection strings at 0x74f0..0x76e9: "%s:", " You can only place a single arena.",
       " Bridges must be near water's edge.", " Next outpost available at rank %s.",
       " No more outposts are available.", " Requires a rank of %s.",
       " Requires a unit of level %d.", " Location is too narrow for %s.",
       " Location is too narrow for a %s.", " Walls must be near land.",
       "Buildings cannot be placed over water.", "This location is unsuitable for buildings.",
       " It will cost %s the %s %d gp. ", "Party member %s doesn't have enough gold to construct
       a %s.", "Too many construction sites.";
     - a five-way menu switch at 0x1427 (codes 0x7685/0x768b/0x769b/0x76a8, jump table
       cs:0x16a8) that ends by choosing the building party (0x4d8, ovc45_textChoosePartyBuild)
       and rejecting 0xff, then loops back to 0xd86 while the local reject flag is clear.

   Body not derived yet; the addresses, the struct offsets and the call census are recorded above
   and in doc/step6_entry.md. */

uint __cdecl16far
ovc45_buildPlacementMessage
          (uint x,uint16_t y,int entityIndex,uint16_t reserved,char flag)

{
  /* Not derived yet - see the comment above. */
  (void)x; (void)y; (void)entityIndex; (void)reserved; (void)flag;
  return 0;
}


/* 77eb:16b2 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_randBelow */

/* 77eb:16b2 */

uint __cdecl16far ovc45_usesRandBelow(int entityIndex)

{
  char entityClass;
  uint32_t entityPtr;
  uint result;
  byte drawHi;
  uint16_t randDraw;
  
  if (*(char *)((int)&(Entities)[entityIndex].base.entity + 3) == -1) {
    result = entityIndex * 0x37 & 0xff00;
  }
  else {
    entityPtr = *(uint32_t *)((uint)AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3) << 2);
    entityClass = *(char *)((int)entityPtr + 0x2f);
    if (entityClass == '\x04') {
      randDraw = ovr_randBelow(5,0);
      drawHi = (byte)(randDraw >> 8);
      if ((byte)randDraw < 4) {
        result = CONCAT11(drawHi,1);
      }
      else {
        result = (uint)drawHi << 8;
      }
    }
    else if (entityClass == '\x05') {
      randDraw = ovr_randBelow(3,0);
      drawHi = (byte)(randDraw >> 8);
      if ((char)randDraw == '\0') {
        result = CONCAT11(drawHi,1);
      }
      else {
        result = (uint)drawHi << 8;
      }
    }
    else {
      randDraw = ovr_randBelow(4,0);
      drawHi = (byte)(randDraw >> 8);
      if ((byte)randDraw < 2) {
        result = CONCAT11(drawHi,1);
      }
      else {
        result = (uint)drawHi << 8;
      }
    }
  }
  return result;
}



/* 77eb:1754 */
void __cdecl16far
ovc45_textDone(char foundFlag,byte bldType,int entityIndex,uint16_t x,uint16_t outFlag,uint16_t outFlagSeg,uint16_t arg7,uint16_t arg8)

{
  byte bVar1;
  far_t entries;
  far_t entries_00;
  far_t hint;
  far_t hint_00;
  uint16_t x_00;
  char *pcVar2;
  uint16_t *puVar3;
  int iVar4;
  uint8_t *puVar5;
  uint uVar6;
  uint16_t uVar7;
  uint16_t uVar8;
  uint16_t uVar9;
  int iVar10;
  uint16_t unaff_DI;
  undefined1 uVar11;
  undefined1 uVar12;
  uint8_t menuItems;
  uint16_t auStack_28e [19];
  uint8_t msg;
  uint8_t text;
  char cStack_17;
  char cStack_16;
  char cStack_15;
  uint8_t menuLabel;
  uint16_t uStack_12;
  uint16_t uStack_10;
  char cStack_e;
  char acStack_d [11];
  
  x_00 = x;
  auStack_28e[0] = 0x2410;
  menuItems = 0x7706;
  acStack_d[1] = 1;
  if (BLD_WORD(&BuildingTypes[bldType], action, 0) == 0 && BLD_WORD(&BuildingTypes[bldType], action, 2) == 0) {
    auStack_28e[2] = 0x2410;
    auStack_28e[1] = 0x770f;
  }
  else {
    auStack_28e[2] = BLD_WORD(&BuildingTypes[bldType], action, 2);
    auStack_28e[1] = BLD_WORD(&BuildingTypes[bldType], action, 0);
  }
  acStack_d[2] = 2;
  iVar10 = 2;
  if (foundFlag != '\0') {
    auStack_28e[4] = 0x2410;
    auStack_28e[3] = 0x7716;
    acStack_d[3] = 3;
    iVar10 = 3;
  }
  auStack_28e[iVar10 * 2] = 0x2410;   /* hand fix: segment-half array; this function already stores 0x2410 in auStack_28e[0],[2],[4] */
  *(char **)(&menuItems + iVar10 * 4) = (char *)"Done";
  acStack_d[iVar10 + 1] = '\x04';
  cStack_16 = '\0';
  do {
    uVar11 = 0x10;
    pcVar2 = ovr_ovc22_className(AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3),0);
    puVar3 = (uint16_t *)((uint)AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3) * 4);
    uVar8 = _DS;
    iVar4 = ovc45_compute9((char *)&text,(char *)CONCAT22(*puVar3,_SS),
                           (char *)CONCAT13((char)(Font03.ofs >> 8),
                                            CONCAT12((char)Font03.ofs,puVar3[1])),Font03.seg,'U',
                           (char)Font03.ofs,0x55,3,pcVar2,uVar11);
    puVar5 = ovr_ovc15_usesStshRealloc
                       ((char *)BLD_WORD(&BuildingTypes[bldType], name, 0),BLD_WORD(&BuildingTypes[bldType], name, 2),(char)iVar4,uVar8,0,0,0,0);
    pcVar2 = ovr_fmVsprintf("%s: Search this location for minerals?  Active party is %s the %s.",
                            (char *)CONCAT22(uVar9,puVar5));
                            asm { mov uVar9,dx };
    strcpy((char *)CONCAT22(_SS,&msg),
           (char *)CONCAT13((char)((uint)uVar9 >> 8),CONCAT12((char)uVar9,pcVar2)));
    goldPartyIndex = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
    uVar11 = SUB21(_SS,0);
    uVar12 = (undefined1)((uint)_SS >> 8);
    puVar5 = &menuItems;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = uVar11;
    entries.ofs = (uint16_t)puVar5;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar12;
    (*(uint8_t *)((uint8_t *)&(hint.seg))) = uVar11;
    hint.ofs = (uint16_t)&msg;
    (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = uVar12;
    ovr_ovc28_compute2(entries,iVar10 + 1,hint,0,0);
    cStack_15 = (char)puVar5;
    goldPartyIndex = 0xff;
    if (cStack_15 != '\0') {
      cStack_15 = acStack_d[(uint)puVar5 & 0xff];
    }
    if (cStack_15 == '\x01') {
      uVar6 = ovc45_usesRandBelow(entityIndex);
      if ((uVar6 & 0xff) == 0) {
        ovr_play_sfx(47,0,0);
        ovr_say((char *)"No minerals were found.",0x10);
        bVar1 = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
        ovr_createConstructionRecordFar
                  (0,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,(char)unaff_DI,(char)GfxRndSeed2,bVar1,0);
      }
      else {
        uVar7 = ovr_randBelow(0x10,0);
        if ((uVar7 & 0xff) == 0) {
          ovr_play_sfx(42,0,0);
          ovr_say((char *)"Gems discovered.",0x10);
          bVar1 = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
          ovr_createConstructionRecordFar
                    (0x72,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,(char)unaff_DI,(char)GfxRndSeed2,bVar1,0);
        }
        else {
          uVar7 = ovr_randBelow(4,0);
          if ((char)uVar7 == '\0') {
            ovr_play_sfx(43,0,0);
            ovr_say((char *)"Gold discovered.",0x10);
            bVar1 = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
            ovr_createConstructionRecordFar
                      (0x71,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,(char)unaff_DI,(char)GfxRndSeed2,bVar1,0);
          }
          else {
            ovr_play_sfx(42,0,0);
            ovr_say((char *)"Iron deposits discovered.",0x10);
            bVar1 = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
            ovr_createConstructionRecordFar
                      (0x70,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,(char)unaff_DI,(char)GfxRndSeed2,bVar1,0);
          }
        }
      }
      ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x12));
      cStack_16 = '\x01';
    }
    else if (cStack_15 == '\x02') {
      uStack_12 = 0x2410;
      menuLabel = 0x770f;
      cStack_e = '\x10';
      acStack_d[0] = '$';
      uStack_10 = 0x77ba;
      uVar8 = BLD_WORD(&BuildingTypes[bldType], name, 2);
      pcVar2 = ovr_fmVsprintf("Remove %s permanently. Are you sure?",
                              (char *)CONCAT13((char)((uint)uVar8 >> 8),
                                               CONCAT12((char)uVar8,
                                                        BLD_WORD(&BuildingTypes[bldType], name, 0))));
                                                        asm { mov uVar9,dx };
      puVar5 = &menuLabel;
      (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = uVar11;
      entries_00.ofs = (uint16_t)puVar5;
      (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = uVar12;
      (*(uint8_t *)((uint8_t *)&(hint_00.seg))) = (char)uVar9;
      hint_00.ofs = (uint16_t)pcVar2;
      (*(uint8_t *)((uint8_t *)&(hint_00.seg) + 1)) = (char)((uint)uVar9 >> 8);
      ovr_ovc28_compute2(entries_00,2,hint_00,0,0);
      cStack_15 = (char)puVar5;
      if (cStack_15 == '\x01') {
        bVar1 = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
        ovr_createConstructionRecordFar
                  (0,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar1,(char)unaff_DI,(char)GfxRndSeed2,bVar1,0);
      }
      cStack_16 = '\x01';
    }
    else if (cStack_15 == '\x03') {
      uVar8 = ovc45_textChoosePartyBuild(x_00,GfxRndSeed2,&entityIndex,0);
      cStack_17 = (char)uVar8;
      if (cStack_17 == -1) {
        cStack_16 = '\x01';
      }
    }
    else if ((cStack_15 == '\x04') || (cStack_15 == '\0')) {
      cStack_16 = '\x01';
    }
  } while (cStack_16 == '\0');
  return;
}


/* 77eb:1ba2 */

/* [R7] body shape: compute */

/* 77eb:1ba2 */

bool __cdecl16far ovc45_compute6(uint16_t value)

{
  return value != 1;
}



/* 77eb:1bb3 */
void __cdecl16far
ovc45_textDone2(char foundFlag,byte bldType,int entityIndex,uint16_t x,uint16_t outFlag,uint16_t outFlagSeg,uint16_t arg7,uint16_t arg8)

{
  uint *puVar1;
  int *piVar2;
  uint8_t partyIndex;
  byte bVar3;
  far_t entries;
  far_t hint;
  uint16_t agnt;
  char *pcVar4;
  uint16_t *puVar5;
  int iVar6;
  uint8_t *puVar7;
  uint16_t uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint16_t unaff_DI;
  uint16_t uVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  uint8_t menuLabels;
  uint16_t auStack_290 [19];
  uint8_t msg;
  uint8_t text;
  uint uStack_1a;
  uint uStack_18;
  char *pcStack_16;
  uint uStack_14;
  byte bStack_11;
  byte bStack_10;
  char cStack_f;
  char cStack_e;
  uint8_t menuActions;
  undefined1 auStack_c [10];
  
  agnt = x;
  uStack_1a = BuildingTypes[bldType].cost / 10;
  auStack_290[0] = 0x2410;
  menuLabels = 0x77f0;
  auStack_c[0] = 1;
  if (BLD_WORD(&BuildingTypes[bldType], action, 0) == 0 && BLD_WORD(&BuildingTypes[bldType], action, 2) == 0) {
    auStack_290[2] = 0x2410;
    auStack_290[1] = 0x77f6;
  }
  else {
    auStack_290[2] = BLD_WORD(&BuildingTypes[bldType], action, 2);
    auStack_290[1] = BLD_WORD(&BuildingTypes[bldType], action, 0);
  }
  auStack_c[1] = 2;
  iVar12 = 2;
  if (foundFlag != '\0') {
    auStack_290[4] = 0x2410;
    auStack_290[3] = 0x7716;
    auStack_c[2] = 3;
    iVar12 = 3;
  }
  auStack_290[iVar12 * 2] = 0x2410;   /* hand fix: segment-half array, same value as the sibling stores in this function */
  *(char **)(&menuLabels + iVar12 * 4) = (char *)"Done";
  auStack_c[iVar12] = 4;
  cStack_e = '\0';
  do {
    uVar14 = 0x10;
    pcVar4 = ovr_ovc22_className(AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3),0);
    puVar5 = (uint16_t *)((uint)AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3) * 4);
    uVar15 = 0x7a;
    uVar8 = puVar5[1];
    iVar6 = ovc45_compute9((char *)&text,(char *)CONCAT22(*puVar5,_SS),
                           (char *)CONCAT13((char)(Font03.ofs >> 8),CONCAT12((char)Font03.ofs,uVar8)
                                           ),Font03.seg,'U',(char)uVar8,(char)Font03.ofs,0x55,3,
                           pcVar4,uVar14);
    puVar7 = ovr_ovc15_usesStshRealloc
                       ((char *)BLD_WORD(&BuildingTypes[bldType], name, 0),(char)BLD_WORD(&BuildingTypes[bldType], name, 2),uStack_1a,(char)iVar6,uVar15,0,0,0);
    pcVar4 = ovr_fmVsprintf("%s: Claim this tree? Harvest value is %d gold. Active party is %s the %s."
                            ,(char *)CONCAT13((char)((uint)uVar8 >> 8),CONCAT12((char)uVar8,puVar7))
                           );
                           asm { mov uVar8,dx };
    uVar14 = SUB21(_SS,0);
    uVar15 = (undefined1)((uint)_SS >> 8);
    strcpy((char *)CONCAT13(uVar15,CONCAT12(uVar14,&msg)),
           (char *)CONCAT13((char)((uint)uVar8 >> 8),CONCAT12((char)uVar8,pcVar4)));
    goldPartyIndex = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
    puVar7 = &menuLabels;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = uVar14;
    entries.ofs = (uint16_t)puVar7;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar15;
    (*(uint8_t *)((uint8_t *)&(hint.seg))) = uVar14;
    hint.ofs = (uint16_t)&msg;
    (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = uVar15;
    ovr_ovc28_compute2(entries,iVar12 + 1U,hint,(char)(iVar12 + 1U),0);
    menuActions = (uint8_t)puVar7;
    goldPartyIndex = 0xff;
    if ((uint8_t)puVar7 != 0x0) {
      menuActions = auStack_c[((uint)puVar7 & 0xff) - 1];
    }
    if (menuActions == 0x1) {
      ovr_play_sfx(86,0,0);
      if (BuildingTypes[bldType].resource == '\0') {
        if (AgntGs[(uint)(Entities)[entityIndex].base.gindex].shortName[3] == '\x05') {
          bStack_11 = bldType + 0x18;
        }
        else {
          bStack_11 = bldType + 6;
        }
      }
      else {
        bStack_11 = bldType;
      }
      uStack_14 = (uint)BuildingTypes[bStack_11].expinc;
      BuildingTypes[bStack_11].expinc = 1;
      ovr_createConstructionRecord
                (bStack_11,agnt,GfxRndSeed2,(uint8_t *)outFlag,(char)outFlagSeg,(char)agnt,
                 (char)outFlag,(char)outFlagSeg,
                 CONCAT11((char)((uint)(entityIndex * 0x37) >> 8),
                          AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3)),0);
      BuildingTypes[bStack_11].expinc = (undefined1)uStack_14;
      bVar3 = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
      pcStack_16 = ovr_ovc22_textPOPULATION(bStack_11,bVar3,(agnt_t far *)agnt,bVar3,(char)GfxRndSeed2);
      uVar14 = 0x10;
      partyIndex = *(char *)((int)&(Entities)[entityIndex].base.entity + 3);
      uStack_18 = ovr_ovc22_seasonalIncome(bStack_11,partyIndex,partyIndex,agnt,(char)GfxRndSeed2);
      ovc45_compute6((uint16_t)pcStack_16);
      pcVar4 = ovr_fmVsprintf("Forest claimed. This forest creates %d gold of income and feeds %d %s."
                              ,(char *)CONCAT13((char)((uint)pcStack_16 >> 8),
                                                CONCAT12((char)pcStack_16,uStack_18)));
      ovr_say(pcVar4,uVar14);
      ovr_inputUpdate((ulong)MessageDelay << 1);
      cStack_e = '\x01';
    }
    else if (menuActions == 0x2) {
      ovr_play_sfx(48,0,0);
      bVar3 = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
      ovr_createConstructionRecordFar
                (0,agnt,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),bVar3,(char)unaff_DI,
                 (char)GfxRndSeed2,(char)outFlag,bVar3);
      cStack_e = '\x01';
      bStack_10 = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
      uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
      iVar6 = (int)*(uint32_t *)((uint)bStack_10 << 2);
      puVar1 = (uint *)(iVar6 + 0x56);
      uVar9 = *puVar1;
      *puVar1 = *puVar1 + uStack_1a;
      piVar2 = (int *)(iVar6 + 0x58);
      *piVar2 = *piVar2 + (uint)CARRY2(uVar9,uStack_1a);
      uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
      iVar10 = (int)*(uint32_t *)((uint)bStack_10 << 2);
      iVar6 = *(int *)(iVar10 + 0x58);
      uVar9 = *(uint *)(iVar10 + 0x56);
      uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
      iVar11 = (int)*(uint32_t *)((uint)bStack_10 << 2);
      iVar10 = *(int *)(iVar11 + 0x8c);
      if ((iVar10 <= iVar6) && ((iVar10 < iVar6 || (*(uint *)(iVar11 + 0x8a) < uVar9)))) {
        uVar8 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
        iVar6 = (int)*(uint32_t *)((uint)bStack_10 << 2);
        uVar9 = *(uint *)(iVar6 + 0x8a);
        uVar13 = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
        iVar10 = (int)*(uint32_t *)((uint)bStack_10 << 2);
        *(uint16_t *)(iVar10 + 0x58) = *(uint16_t *)(iVar6 + 0x8c);
        *(uint *)(iVar10 + 0x56) = uVar9;
      }
      uVar14 = (undefined1)uVar9;
      pcVar4 = ovr_stsprintf((char *)&text);
      ovr_say(pcVar4,uVar14);
      ovr_inputUpdate((ulong)MessageDelay << 1);
    }
    else if (menuActions == 0x3) {
      uVar8 = ovc45_textChoosePartyBuild(agnt,GfxRndSeed2,&entityIndex,(char)GfxRndSeed2);
      cStack_f = (char)uVar8;
      if (cStack_f == -1) {
        cStack_e = '\x01';
      }
    }
    else if ((menuActions == 0x4) || (menuActions == 0x0)) {
      cStack_e = '\x01';
    }
  } while (cStack_e == '\0');
  return;
}


/* 77eb:20e8 */

/* [R6] touches GfxRndSeed2 */

/* 77eb:20e8 */

uint __cdecl16far ovc45_usesGfxRndSeed2(int far *x)

{
  byte bldSize;
  uint in_AX;
  undefined1 extraout_AH;
  uint result;
  byte scanDown;
  byte cellType;
  
  scanDown = 0;
  while( true ) {
    if (3 < scanDown) {
      return in_AX & 0xff00;
    }
    cellType = ovc45_getUnitType(*x - (uint)scanDown,GfxRndSeed2);
    in_AX = CONCAT11(extraout_AH,cellType);
    if (cellType != 0) break;
    scanDown = scanDown + 1;
  }
  bldSize = BuildingTypes[cellType].size;
  result = CONCAT11((char)((uint)cellType * 0x27 >> 8),bldSize);
  if (scanDown < bldSize) {
    result = (uint)scanDown;
    *x = *x - result;
  }
  else {
    cellType = 0;
  }
  return CONCAT11((char)(result >> 8),cellType);
}



/* 77eb:215a */

/* [R6] touches GMapFlags */

/* 77eb:215a */

int __cdecl16far ovc45_usesGMapFlags4(int x,int y)

{
  int in_AX;
  int result;
  byte hiByte;
  
  if ((((x < 0) || (y < 0)) || (in_AX = x + 1, 0x93 < in_AX)) || (in_AX = y + 1, 0x3b < in_AX)) {
    result = CONCAT11((char)((uint)in_AX >> 8),2);
  }
  else {
    if (((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) == 3) {
      result = 2;
    }
    else {
      hiByte = (byte)((uint)(x * 2) >> 8);
      if (((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) == 0) {
        result = (uint)hiByte << 8;
      }
      else {
        result = CONCAT11(hiByte,1);
      }
    }
  }
  return result;
}



/* 77eb:21d3 */

/* [R7] body shape: compute */

/* 77eb:21d3 */

uint8_t __cdecl16far ovc45_compute7(byte a,byte b)

{
  /* Re-derived from image 77eb:21d3: the image returns AL only, `imul` then `shr ax,3`. */
  return (uint8_t)(((uint)a * (uint)b) >> 3);
}



/* 77eb:21f1 */

/* Shows the land info for the tile under a screen point: hit-tests with video_compute1, maps x to a
   tile column via (x-9)/0x30, and calls land_info. */

/* 77eb:21f1 */

bool __cdecl16far ovc45_showLandInfo(int screenX,uint16_t y)

{
  uint16_t hitCode;
  bool hitButton;
  
  hitCode = video_pointInButton(screenX,y);
  hitButton = (char)hitCode != '\0';
  if (hitButton) {
    ovr_land_info((byte)((screenX - 9U) / 0x30));
  }
  return hitButton;
}



/* 77eb:2226 */

/* [R7] body shape: compute */

/* 77eb:2226 */

uint8_t __cdecl16far ovc45_compute8(byte partyIndex)

{
  /* Re-derived from image 77eb:2226: 0 for index 0xff, else 1 when the leader's byte at
     +0x3f is zero. */
  if (partyIndex == 0xff) {
    return 0;
  }
  if (*(uint8_t far *)((uint8_t far *)GLeaderSheets[partyIndex] + 0x3f) == 0) {
    return 1;
  }
  return 0;
}



/* 77eb:2257 */

/* Returns the "Maintenance cost is" or "Income created is" label for a signed amount. */

/* 77eb:2257 */

char * __cdecl16far ovc45_costOrIncomeLabel(int amount)

{
  char *pcVar1;
  
  if (amount < 1) {
    pcVar1 = (char *)"Maintenance cost is";
  }
  else {
    pcVar1 = (char *)"Income created is";
  }
  return pcVar1;
}



/* 77eb:226e */
/* 77eb:226e */

int __cdecl16far ovc45_compute9(char *dest,char *src,char *font,uint maxWidth,char mode,...)

{
  byte fontByte;
  uint fullWidth;
  int iVar3;
  int iVar4;
  char in_stack_00000012;
  int textWidth;
  
  fullWidth = ovr_font_textWidth((*(uint16_t *)((uint8_t *)&(src) + 2)),font,maxWidth,0,0);
  if (mode < fullWidth) {
    if (in_stack_00000012 == '\x02') {
      textWidth = ovr_font_textWidth((char *)"..",(char *)CONCAT22((*(uint16_t *)((uint8_t *)&(font) + 2)),(char *)0x2410),maxWidth,0,0)
      ;
    }
    else {
      textWidth = ovr_font_textWidth((char *)"...",(char *)CONCAT22((*(uint16_t *)((uint8_t *)&(font) + 2)),(char *)0x2410),maxWidth,0,0)
      ;
    }
    iVar3 = 0;
    for (iVar4 = 0;
        (((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   iVar3] != '\0' &&
        ((int)(textWidth + iVar4 + (uint)*(byte *)((*(uint16_t *)((uint8_t *)&(font) + 2)) + ((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   iVar3] + 0xa1)) <=
         (int)mode)); iVar4 = iVar4 + (uint)fontByte) {
      fontByte = *(byte *)((*(uint16_t *)((uint8_t *)&(font) + 2)) + ((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   iVar3] + 0xa1);
      dest[iVar3] = ((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   iVar3];
      iVar3 = iVar3 + 1;
    }
    dest[iVar3] = '.';
    dest[iVar3 + 1] = '.';
    iVar4 = iVar3 + 2;
    if (in_stack_00000012 != '\x02') {
      dest[iVar4] = '.';
      iVar4 = iVar3 + 3;
    }
    dest[iVar4] = '\0';
    (*(uint16_t *)((uint8_t *)&(src) + 2)) = (uint16_t)dest;   /* hand fix: 2-byte segment half */
  }
  return (int)(*(uint16_t *)((uint8_t *)&(src) + 2));
}


/* 77eb:234a */

/* [R6] touches GMapFlags */

/* 77eb:234a */

uint __cdecl16far ovc45_usesGMapFlags5(char mode,uint x,int y)

{
  /* Re-derived: 1 when the cell passes its mode's geometry test, 0 otherwise.  mode 1 tests the
     word at GMapFlags[y+1][x]: with bit 4 clear it wants bit 1 set, with bit 4 set it wants bit 2
     set.  mode 2 requires GMapFlags[y+1][x] bit 1, GMapFlags[y][x] bit 1, GMapFlags[y+1][x-1] bit
     2 and GMapFlags[y-1][x-1] bit 2.  Any other mode returns 0.  Every exported `& 0xff00`,
     CONCAT11 and `<< 8` return was stale AH: the exits write only AL (1 at 0x45, 0x56, 0x113). */
  short (*flags) [60] [148];
  uint word;

  flags = (short (*) [60] [148])GMapFlags;
  if (mode == '\x01') {
    word = ((*flags)[y] + x)[0x94];
    if ((word & 4) == 0) {
      if ((word & 1) != 0) {
        return 1;
      }
    }
    else if ((word & 2) != 0) {
      return 1;
    }
    return 0;
  }
  if (mode == '\x02') {
    if ((((*flags)[y] + x)[0x94] & 1U) == 0) {
      return 0;
    }
    if (((*flags)[y][x] & 1U) == 0) {
      return 0;
    }
    if ((((*flags)[y] + x)[0x93] & 2U) == 0) {
      return 0;
    }
    if ((((short (*) [60] [148])GMapFlags)[-1][y + 0x3b][x + 0x93] & 2U) == 0) {
      return 0;
    }
    return 1;
  }
  return 0;
}


