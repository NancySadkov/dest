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
  uint alignedX;           /* alignUp4 of the entity's x */
  uint i;                  /* entity index */
  uint *entityIndexSeg;    /* segment half of entityIndexOut */
  byte bestSlot;           /* smallest slot above slotMin, 0xff when none */
  
  bestSlot = 0xff;
  for (i = 0; i < EntityCount; i = i + 1) {
    alignedX = ovr_alignUp4((Entities)[i].base.x,0,0);
    if (alignedX == x) {
      if (((((Entities)[i].base.y == y) &&
           (AgntGs[(uint)(Entities)[i].base.gindex].ai == '\0')) &&
          (slotMin < (int)(uint)AGNT_FIELD(&(Entities)[i], base.entity, 3))) &&
         (AGNT_FIELD(&(Entities)[i], base.entity, 3) < bestSlot)) {
        bestSlot = AGNT_FIELD(&(Entities)[i], base.entity, 3);
        *(uint *)CONCAT22((uint *)entityIndexOut,entityIndexSeg) = i;
      }
    }
  }
  if (bestSlot == 0xff) {
    return 0xffff;
  }
  return (uint)bestSlot;
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
  int clsOfs;              /* the class record offset, bldIdx * 0x95 */
  uint16_t *sheetSlot;     /* &GLeaderSheets[party] as a word pair */
  char *msgPtr;            /* ovr_fmVsprintf's result */
  uint8_t *puVar4;
  uint16_t uVar5;
  uint16_t count;
  uint16_t diArg;          /* the segment the image passes in DI */
  uint slotMin;
  uint8_t foundEntities;
  uint8_t menuItems;
  int aiStack_2c [19];
  uint8_t entityIndex;
  char choice;             /* the menu's answer */
  
  x_00 = ovr_alignUp4(x,0,0);
  entityIndex = *entityIndexPtr;
  slotMin = 0xffff;
  for (count = 0; (int)count < 10; count = count + 1) {
    slotMin = ovc45_usesAlignUp4(slotMin,x_00,y,(uint *)CONCAT22(diArg,_SS));
    if (slotMin == 0xffff) break;
    *(int *)(&foundEntities + count * 2) = entityIndex;
    uVar5 = *(uint16_t *)(slotMin * 4);
    aiStack_2c[count * 2] = ((uint16_t *)(slotMin * 4))[1];
    *(uint16_t *)(&menuItems + count * 4) = uVar5;
  }
  if ((int)count < 2) {
    *entityIndexPtr = entityIndex;
    clsOfs = (uint)*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0xd) * 0x95;
    uVar5 = CONCAT11((char)((uint)clsOfs >> 8),
                     '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 + clsOfs) & 0x1f));
  }
  else {
    ovr_ovc22_className(*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0x1a),0);
    sheetSlot = (uint16_t *)((uint)*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0x1a) * 4);
    uVar5 = _DS;
    msgPtr = ovr_fmVsprintf("Choose party to build for.  Now building for %s the %s.",
                            (char *)CONCAT22(sheetSlot[1],(char *)*sheetSlot));
    puVar4 = &menuItems;
    entries.seg = (uint16_t)_SS;
    entries.ofs = (uint16_t)puVar4;
    (*(uint8_t *)((uint8_t *)&(hint.seg))) = (char)uVar5;
    hint.ofs = (uint16_t)msgPtr;
    (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = (char)((uint)uVar5 >> 8);
    ovr_ovc28_compute2(entries,count,hint,0,0);
    choice = (char)puVar4;
    if ((char)puVar4 == '\0') {
      uVar5 = 0xff;
    }
    else {
      *entityIndexPtr = aiStack_2c[((uint)puVar4 & 0xff) - 0xc];
      uVar5 = (uint16_t)((ulong)Entities >> 0x10);
      selectedPartyIndex = *(undefined1 *)((int)Entities + *entityIndexPtr * 0x37 + 0x1a);
      clsOfs = (uint)*(byte *)((int)Entities + *entityIndexPtr * 0x37 + 0xd) * 0x95;
      uVar5 = CONCAT11((char)((uint)clsOfs >> 8),
                       '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 + clsOfs) & 0x1f));
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
  short *flagPtr;          /* &GMapFlags[y][x], the cell below is at +0x94 */
  byte axHigh;             /* high byte of the pointer value, as the image leaves it in AH */
  int result;
  
  flagPtr = (*(short (*) [60] [148])GMapFlags)[y] + x;
  axHigh = (byte)((uint)flagPtr >> 8);
  if ((flagPtr[0x94] & 3U) == 0) {
    result = (uint)axHigh << 8;
  }
  else {
    result = CONCAT11(axHigh,1);
  }
  return result;
}



/* 77eb:0778 */

/* [R7] body shape: compute */

/* 77eb:0778 */

uint __cdecl16far ovc45_compute1(byte bldType,int x,int y)

{
  bool flag;
  uint mapRes;

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
  /* BuildingTypes records sit at a 0x27 stride with their base at 0x10e of the overlay data
     segment, so the image's `bldType * 0x27 + 0x121` IS BuildingTypes[bldType].flags2
     (0x10e + 0x13).  The former raw-offset form dereferenced DS:0x121 + bldType*0x27 instead. */
  if ((BuildingTypes[bldType].flags2 & 8) != 0) {
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
  int sheetOfs;            /* offset of the party's leader sheet */
  int heldLo;              /* the sheet's 32-bit holding, low word */
  int converted;           /* what ovc45_usesLDIV_at_ returns for it */
  
  sheetOfs = (int)(uint32_t)GLeaderSheets[partyIndex];
  heldLo = *(int *)(sheetOfs + 0x56);
  converted = ovc45_usesLDIV_at_(partyIndex,heldLo,*(uint16_t *)(sheetOfs + 0x58));
  return heldLo + converted;
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

/* Building-placement message builder: 0x0d61..0x16b2 (2,385 bytes) plus the five-entry switch
   table at cs:0x16a8 = 0x142c, 0x1433, 0x1662, 0x1670, 0x142c.

   Frame: `sub sp,0x3f2`; y is kept in DI; arguments are x [bp+6], y [bp+8], the entity index
   [bp+0xa], a byte the menu path writes [bp+0xc], and the "offer change party" flag [bp+0xe].
   Three scratch buffers live in the frame: `bigBuf` at [bp-0x3ca] (712 bytes), an 80-byte buffer at
   [bp-0x102] for the cost prefix, and a 160-byte buffer at [bp-0xb2] for the one-off messages. The
   menu is up to five far string pointers at [bp-0x3f2] with the matching action codes one byte
   apart from [bp-0xb].

   The body is `do { ... } while (!done)`: "Change Building" and the two "cannot place at all"
   messages leave `done` clear so the whole message is rebuilt against the new selection, while
   Place, Done and a cancelled party pick set it.

   bldtp_t offsets used here (base 0060:010e, stride 0x27): name +0x00, description +0x04,
   kind +0x0c, size +0x0d, flags +0x10, flags2 +0x13, cost +0x17, unitType +0x25, flags3 +0x26.

   GUESS (recorded per AGENTS.md): the image calls into the relocated overlay window 0x200 at
   0x0dbb, 0x0ece, 0x1649 and 0x1666.  audit/overlay_segments.csv lists sixteen candidate modules
   for that window and marks the reference unresolved, and the VROOMM directory is out of scope, so
   the calls are not written and each result is taken from the nearest provable source:
     - bldType: the sheet byte the call is given (char_sheet_t::buildType is the BuildingTypes
       index by its own documentation);
     - the "may place?" gate (0x0ece) is taken as satisfied, so the three rejection messages below
       are kept in the body but are not reached in this build;
     - the construction-record type (0x1649) is the building type;
     - the "rebuild graphics" call (0x1666) has no visible result and is omitted.
   The far-string arguments go through the exported `ovr_*` thunks, which are unprototyped and so
   carry a far pointer as its two words, exactly as the image pushes them. */
uint __cdecl16far
ovc45_buildPlacementMessage
          (uint x,uint16_t y,int entityIndex,uint16_t chosen,char flag)

{
  byte colOfs;      /* [bp-0x11] x - (alignUp4(x) - 2) */
  byte party;       /* [bp-0x0f] Entities[entityIndex].party */
  byte bldType;     /* [bp-0x10] BuildingTypes index */
  byte count;       /* si: number of menu entries */
  byte choice;      /* [bp-0x0e] menu result, then the action code */
  byte code;
  byte placeOk;     /* GAP 0x0ece */
  bool rejected;    /* [bp-0x0c] a reason message was built */
  bool done;        /* [bp-0x0d] leave the outer loop */
  int gold;
  uint16_t rankIdx;
  uint16_t cnOfs;
  uint16_t cnSeg;
  uint16_t recType;
  char far *className;
  char far *sheet;
  char bigBuf[712];
  char buf80[80];
  char buf2[160];
  far_t menu[5];
  byte codes[5];

  colOfs = (byte)(x - (byte)((int)ovr_alignUp4(x) - 2));
  done = 0;
  do {
    party = ((byte far *)&Entities[entityIndex])[0x1a];
    sheet = (char far *)GLeaderSheets[party];

    /* GAP 0x0dbb: lcall 0x200,0x25(sheet->buildType) -> BuildingTypes index */
    bldType = ((char_sheet_t far *)sheet)->buildType[0];

    /* The image computes the copied name inside each branch (0x0dfe and 0x0e4e), not once. */
    if (BuildingTypes[bldType].description != (char far *)0) {
      ovr_stsprintf((char far *)bigBuf,BuildingTypes[bldType].description,
                    ovr_ovc15_usesStshRealloc(BuildingTypes[bldType].name));
    }
    else {
      ovr_stsprintf((char far *)bigBuf,(char far *)"%s:",
                    ovr_ovc15_usesStshRealloc(BuildingTypes[bldType].name));
    }

    count = 0;
    rejected = 0;

    if (ovc45_textArena2(bldType)) {
      strcat(bigBuf," You can only place a single arena.");
      rejected = 1;
      goto menu;
    }
    if (ovc45_compute1(bldType,(int)x,(int)y) == 0) {
      strcat(bigBuf," Bridges must be near water's edge.");
      rejected = 1;
      goto menu;
    }

    /* GAP 0x0ece: lcall 0x200,0x34(bldType,party) is the "may place here?" gate. */
    placeOk = 1;
    if (placeOk != 0) {
      goto suitability;
    }
    if (BuildingTypes[bldType].unitType == 0x12) {
      if (ovc45_compute5() != 0) {
        rankIdx = (uint16_t)ovc45_compute5();
        /* GUESS: 0x4955 is an 8-byte-stride table of far rank names with no audit symbol. */
        ovr_stsprintf((char far *)buf2,(char far *)" Next outpost available at rank %s.",
                      (char far *)MK_FP(*(uint16_t far *)MK_FP(_DS,0x4957 + rankIdx * 8),
                                        *(uint16_t far *)MK_FP(_DS,0x4955 + rankIdx * 8)));
        strcat(bigBuf,buf2);
      }
      else {
        strcat(bigBuf," No more outposts are available.");
      }
      rejected = 1;
      goto menu;
    }
    if ((BuildingTypes[bldType].flags3 & 0x80) != 0) {
      rankIdx = (uint16_t)(BuildingTypes[bldType].flags3 & 0x7f);
      ovr_stsprintf((char far *)buf2,(char far *)" Requires a rank of %s.",
                    (char far *)MK_FP(*(uint16_t far *)MK_FP(_DS,0x4957 + rankIdx * 8),
                                      *(uint16_t far *)MK_FP(_DS,0x4955 + rankIdx * 8)));
      strcat(bigBuf,buf2);
    }
    else {
      ovr_stsprintf((char far *)buf2,(char far *)" Requires a unit of level %d.",
                    (uint16_t)BuildingTypes[bldType].flags3);
      strcat(bigBuf,buf2);
    }
    rejected = 1;
    goto menu;

  suitability:
    if (BuildingTypes[bldType].size == 4) {
      if ((ovc45_compute4((int)(x - colOfs),(int)y,0) != 0) &&
          (ovc45_compute4((int)(x - colOfs + 1),(int)y,0) != 0) &&
          (ovc45_compute4((int)(x - colOfs + 2),(int)y,0) != 0) &&
          (ovc45_compute4((int)(x - colOfs + 3),(int)y,0) != 0)) {
        goto width2;
      }
      ovr_stsprintf((char far *)buf2,(char far *)" Location is too narrow for %s.",
                    BuildingTypes[bldType].name);
      strcat(bigBuf,buf2);
      rejected = 1;
      goto menu;
    }

  width2:
    if (BuildingTypes[bldType].size == 2) {
      if ((colOfs != 3) && (ovc45_compute4((int)(x + 1),(int)y,0) != 0)) {
        goto land;
      }
      if ((colOfs != 0) && (ovc45_compute4((int)(x - 1),(int)y,0) != 0)) {
        x = x - 1;
        goto land;
      }
      ovr_stsprintf((char far *)buf2,(char far *)" Location is too narrow for a %s.",
                    BuildingTypes[bldType].name);
      strcat(bigBuf,buf2);
      rejected = 1;
      goto menu;
    }

  land:
    if (ovc45_usesGMapFlags5((char)BuildingTypes[bldType].flags,x,(int)y) != 0) {
      strcat(bigBuf," Walls must be near land.");
      rejected = 1;
      goto menu;
    }
    if (!((BuildingTypes[bldType].kind == 2) ||
          (BuildingTypes[bldType].flags == 1) ||
          (BuildingTypes[bldType].flags == 2) ||
          (ovr_attact_usesGMapFlags(x,(int)y) != 0))) {
      strcpy(bigBuf,"Buildings cannot be placed over water.");
      rejected = 1;
      goto menu;
    }
    if ((ovr_constr_usesGMapFlags(x,(int)y) == 0) &&
        ((BuildingTypes[bldType].flags2 & 0x20) == 0) &&
        (BuildingTypes[bldType].flags == 0)) {
      strcpy(bigBuf,"This location is unsuitable for buildings.");
      rejected = 1;
      goto menu;
    }

    /* The cost line: ovc45_compute9 writes the party's titled name into buf80 and returns its
       destination (its epilogue is `mov dx,[bp+8]; mov ax,[bp+6]`), and the image then passes that
       return value to the sprintf - i.e. buf80 itself. */
    cnOfs = (uint16_t)ovr_ovc22_className(party,0);
    asm mov cnSeg, dx;
    className = (char far *)MK_FP(cnSeg,cnOfs);
    ovr_ovc45_compute9((char far *)buf80,sheet,(char far *)MK_FP(Font03.seg,Font03.ofs),0x55,3);
    ovr_stsprintf((char far *)buf2,(char far *)" It will cost %s the %s %d gp. ",
                  (char far *)buf80,className,(uint16_t)BuildingTypes[bldType].cost);
    strcat((char *)(bigBuf + strlen(bigBuf)),buf2);

  menu:
    if (!rejected) {
      if ((ovr_constr_usesGMapFlags(x,(int)y) != 0) ||
          ((BuildingTypes[bldType].flags2 & 0x20) != 0) ||
          (BuildingTypes[bldType].flags != 0)) {
        menu[count].seg = _DS;
        menu[count].ofs = (uint16_t)"Place";
        codes[count + 1] = 1;
        count = count + 1;
      }
    }
    menu[count].seg = _DS;
    menu[count].ofs = (uint16_t)"Change Building";
    codes[count + 1] = 2;
    count = count + 1;
    if (flag != 0) {
      menu[count].seg = _DS;
      menu[count].ofs = (uint16_t)"Change Party";
      codes[count + 1] = 3;
      count = count + 1;
    }
    menu[count].seg = _DS;
    menu[count].ofs = (uint16_t)"Done";
    codes[count + 1] = 4;
    count = count + 1;

    goldPartyIndex = party;
    choice = (byte)ovr_ovc28_compute2((char far *)menu,count,(char far *)bigBuf);
    goldPartyIndex = 0xff;
    code = 0;
    if (choice != 0) {
      code = codes[choice];
    }
    done = 0;
    switch (code) {
    case 1:
      gold = ovc45_compute3(party);
      if (gold > 0) {
        goto place;
      }
      if (gold < 0) {
        goto noGold;
      }
      if ((uint)gold < (uint)BuildingTypes[bldType].cost) {
        goto noGold;
      }
    place:
      if (GRecordCount >= 0x32) {
        ovr_say((char far *)"Too many construction sites.");
        TextBlitCycle = *(uint32_t far *)MK_FP(BDA_DailyTimeCounter.seg,
                                               BDA_DailyTimeCounter.ofs);
        ovr_inputUpdate((long)(MessageDelay * 2 + 0x24));
        break;
      }
      if (BuildingTypes[bldType].size == 2) {
        if ((colOfs != 3) && (ovc45_compute4((int)(x + 1),(int)y,0) != 0)) {
          goto place2;
        }
        if ((colOfs != 0) && (ovc45_compute4((int)(x - 1),(int)y,0) != 0)) {
          x = x - 1;
          goto place2;
        }
      }
    place2:
      if (BuildingTypes[bldType].size == 4) {
        x = x - colOfs;
      }
      if ((BuildingTypes[bldType].flags2 & 0x20) != 0) {
        ovr_play_sfx(0x56,0);
      }
      else {
        ovr_play_sfx(0x4f,0);
      }
      ovc45_usesGPopulationLo(party,(uint)BuildingTypes[bldType].cost,0);
      /* GAP 0x1649: lcall 0x200,0x2a(sheet->buildType) -> the record type. */
      recType = (uint16_t)bldType;
      ovr_createConstructionRecordFar(recType,(int)x,(int)y,(uint8_t far *)codes,party);
      done = 1;
      break;
    noGold:
      ovr_stsprintf((char far *)buf2,
                    (char far *)"Party member %s doesn't have enough gold to construct a %s.",
                    (char far *)GLeaderSheets[party],BuildingTypes[bldType].name);
      ovr_say((char far *)buf2);
      TextBlitCycle = *(uint32_t far *)MK_FP(BDA_DailyTimeCounter.seg,
                                             BDA_DailyTimeCounter.ofs);
      ovr_inputUpdate((long)(MessageDelay * 2 + 0x24));
      break;
    case 2:
      /* GAP 0x1666: lcall 0x200,0x20(party) - no visible result; the loop rebuilds the message. */
      break;
    case 3:
      chosen = (byte)ovc45_textChoosePartyBuild(x,y,&entityIndex,0);
      if (chosen == 0xff) {
        done = 1;
      }
      break;
    case 0:
    case 4:
    default:
      done = 1;
      break;
    }
  } while (!done);
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
  byte partyIdx;           /* AGNT_FIELD(base.entity, 3): the party index */
  far_t entries;
  far_t entries_00;
  far_t hint;
  far_t hint_00;
  uint16_t x_00;
  char *msgPtr;            /* className's result, then fmVsprintf's */
  uint16_t *sheetSlot;     /* &GLeaderSheets[partyIdx] as a word pair */
  int nameLen;             /* ovc45_compute9's result */
  uint8_t *puVar5;
  uint randRes;            /* ovc45_usesRandBelow(entityIndex) */
  uint16_t randPick;       /* ovr_randBelow(0x10) */
  uint16_t uVar8;
  uint16_t vsSeg;          /* DX returned by ovr_fmVsprintf */
  int menuIdx;             /* 2 or 3, then the chosen item */
  uint16_t diArg;          /* the value the image passes in DI */
  undefined1 uVar11;
  undefined1 ssHi;         /* high byte of _SS */
  uint8_t menuItems;
  uint16_t auStack_28e [19];
  uint8_t msg;
  uint8_t text;
  char loopState;          /* (char)uVar8, -1 ends the loop */
  char didSpend;           /* 0, set to 1 when the action is taken */
  char menuCode;           /* the code ovc28_compute2 returns */
  uint8_t menuLabel;
  uint16_t dgroupSeg;      /* 0x2410, the DATA segment argument */
  uint16_t fmtOfs;         /* 0x77ba, a DGROUP format string */
  char attr;               /* 0x10, the attribute passed with it */
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
  menuIdx = 2;
  if (foundFlag != '\0') {
    auStack_28e[4] = 0x2410;
    auStack_28e[3] = 0x7716;
    acStack_d[3] = 3;
    menuIdx = 3;
  }
  auStack_28e[menuIdx * 2] = 0x2410;   /* hand fix: segment-half array; this function already stores 0x2410 in auStack_28e[0],[2],[4] */
  *(char **)(&menuItems + menuIdx * 4) = (char *)"Done";
  acStack_d[menuIdx + 1] = '\x04';
  didSpend = '\0';
  do {
    uVar11 = 0x10;
    msgPtr = ovr_ovc22_className(AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3),0);
    sheetSlot = (uint16_t *)((uint)AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3) * 4);
    uVar8 = _DS;
    nameLen = ovc45_compute9((char *)&text,(char *)CONCAT22(*sheetSlot,_SS),
                           (char *)CONCAT13((char)(Font03.ofs >> 8),
                                            CONCAT12((char)Font03.ofs,sheetSlot[1])),Font03.seg,'U',
                           (char)Font03.ofs,0x55,3,msgPtr,uVar11);
    puVar5 = ovr_ovc15_usesStshRealloc
                       ((char *)BLD_WORD(&BuildingTypes[bldType], name, 0),BLD_WORD(&BuildingTypes[bldType], name, 2),(char)nameLen,uVar8,0,0,0,0);
    msgPtr = ovr_fmVsprintf("%s: Search this location for minerals?  Active party is %s the %s.",
                            (char *)CONCAT22(vsSeg,puVar5));
                            asm { mov vsSeg,dx };
    strcpy((char *)CONCAT22(_SS,&msg),
           (char *)CONCAT13((char)((uint)vsSeg >> 8),CONCAT12((char)vsSeg,msgPtr)));
    goldPartyIndex = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
    uVar11 = SUB21(_SS,0);
    ssHi = (undefined1)((uint)_SS >> 8);
    puVar5 = &menuItems;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = uVar11;
    entries.ofs = (uint16_t)puVar5;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = ssHi;
    (*(uint8_t *)((uint8_t *)&(hint.seg))) = uVar11;
    hint.ofs = (uint16_t)&msg;
    (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = ssHi;
    ovr_ovc28_compute2(entries,menuIdx + 1,hint,0,0);
    menuCode = (char)puVar5;
    goldPartyIndex = 0xff;
    if (menuCode != '\0') {
      menuCode = acStack_d[(uint)puVar5 & 0xff];
    }
    if (menuCode == '\x01') {
      randRes = ovc45_usesRandBelow(entityIndex);
      if ((randRes & 0xff) == 0) {
        ovr_play_sfx(47,0,0);
        ovr_say((char *)"No minerals were found.",0x10);
        partyIdx = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
        ovr_createConstructionRecordFar
                  (0,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),partyIdx,(char)diArg,(char)GfxRndSeed2,partyIdx,0);
      }
      else {
        randPick = ovr_randBelow(0x10,0);
        if ((randPick & 0xff) == 0) {
          ovr_play_sfx(42,0,0);
          ovr_say((char *)"Gems discovered.",0x10);
          partyIdx = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
          ovr_createConstructionRecordFar
                    (0x72,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),partyIdx,(char)diArg,(char)GfxRndSeed2,partyIdx,0);
        }
        else {
          randPick = ovr_randBelow(4,0);
          if ((char)randPick == '\0') {
            ovr_play_sfx(43,0,0);
            ovr_say((char *)"Gold discovered.",0x10);
            partyIdx = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
            ovr_createConstructionRecordFar
                      (0x71,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),partyIdx,(char)diArg,(char)GfxRndSeed2,partyIdx,0);
          }
          else {
            ovr_play_sfx(42,0,0);
            ovr_say((char *)"Iron deposits discovered.",0x10);
            partyIdx = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
            ovr_createConstructionRecordFar
                      (0x70,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),partyIdx,(char)diArg,(char)GfxRndSeed2,partyIdx,0);
          }
        }
      }
      ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x12));
      didSpend = '\x01';
    }
    else if (menuCode == '\x02') {
      dgroupSeg = 0x2410;
      menuLabel = 0x770f;
      attr = '\x10';
      acStack_d[0] = '$';
      fmtOfs = 0x77ba;
      uVar8 = BLD_WORD(&BuildingTypes[bldType], name, 2);
      msgPtr = ovr_fmVsprintf("Remove %s permanently. Are you sure?",
                              (char *)CONCAT13((char)((uint)uVar8 >> 8),
                                               CONCAT12((char)uVar8,
                                                        BLD_WORD(&BuildingTypes[bldType], name, 0))));
                                                        asm { mov vsSeg,dx };
      puVar5 = &menuLabel;
      (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = uVar11;
      entries_00.ofs = (uint16_t)puVar5;
      (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = ssHi;
      (*(uint8_t *)((uint8_t *)&(hint_00.seg))) = (char)vsSeg;
      hint_00.ofs = (uint16_t)msgPtr;
      (*(uint8_t *)((uint8_t *)&(hint_00.seg) + 1)) = (char)((uint)vsSeg >> 8);
      ovr_ovc28_compute2(entries_00,2,hint_00,0,0);
      menuCode = (char)puVar5;
      if (menuCode == '\x01') {
        partyIdx = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
        ovr_createConstructionRecordFar
                  (0,x_00,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),partyIdx,(char)diArg,(char)GfxRndSeed2,partyIdx,0);
      }
      didSpend = '\x01';
    }
    else if (menuCode == '\x03') {
      uVar8 = ovc45_textChoosePartyBuild(x_00,GfxRndSeed2,&entityIndex,0);
      loopState = (char)uVar8;
      if (loopState == -1) {
        didSpend = '\x01';
      }
    }
    else if ((menuCode == '\x04') || (menuCode == '\0')) {
      didSpend = '\x01';
    }
  } while (didSpend == '\0');
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
  uint *goldLoPtr;          /* &sheet->gold, the low word */
  int *goldHiPtr;           /* &sheet->gold + 2 */
  uint8_t partyIndex;
  byte actorIdx;            /* the acting agent's index */
  far_t entries;
  far_t hint;
  uint16_t agnt;
  char *msgPtr;            /* className's result, then fmVsprintf's */
  uint16_t *classRec;       /* the 4-byte class record for the actor */
  int compute9Res;         /* ovc45_compute9's result, unused */
  int entRec1;             /* the actor's sheet pointer */
  int goldHi1;             /* that sheet's +0x58 gold high word */
  uint8_t *namePtr;        /* ovr_ovc15_usesStshRealloc's result */
  uint16_t ptrSeg;         /* the segment half of the pointer in hand */
  uint amountLo;           /* the low word of the 32-bit amount */
  int sheetOfs;            /* the leader sheet's offset */
  int entRec2;              /* a second copy of the sheet pointer */
  int menuIdx;             /* 2 or 3, then the chosen item */
  uint16_t diArg;           /* the value the image leaves in DI */
  uint16_t segDead;         /* a segment half, stored and never read */
  undefined1 maxWidth;     /* 0x10, compute9's width argument */
  undefined1 msgWidth;     /* 0x7a, the width handed to usesStshRealloc */
  undefined1 ssHiByte;     /* (undefined1)(_SS >> 8), the high byte of _SS */
  uint8_t menuLabels;
  uint16_t auStack_290 [19];
  uint8_t msg;
  uint8_t text;
  uint costTenth;           /* BuildingTypes[bldType].cost / 10 */
  uint incomeRes;           /* ovr_ovc22_seasonalIncome's result */
  char *pcStack_16;
  uint savedExpinc;         /* expinc held across createConstructionRecord */
  byte bStack_11;
  byte bStack_10;
  char partyRes;            /* (char)ovc45_textChoosePartyBuild's result */
  char doneFlag;            /* set when the menu should close */
  uint8_t menuActions;
  undefined1 auStack_c [10];
  
  agnt = x;
  costTenth = BuildingTypes[bldType].cost / 10;
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
  menuIdx = 2;
  if (foundFlag != '\0') {
    auStack_290[4] = 0x2410;
    auStack_290[3] = 0x7716;
    auStack_c[2] = 3;
    menuIdx = 3;
  }
  auStack_290[menuIdx * 2] = 0x2410;   /* hand fix: segment-half array, same value as the sibling stores in this function */
  *(char **)(&menuLabels + menuIdx * 4) = (char *)"Done";
  auStack_c[menuIdx] = 4;
  doneFlag = '\0';
  do {
    maxWidth = 0x10;
    msgPtr = ovr_ovc22_className(AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3),0);
    classRec = (uint16_t *)((uint)AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3) * 4);
    msgWidth = 0x7a;
    ptrSeg = classRec[1];
    compute9Res = ovc45_compute9((char *)&text,(char *)CONCAT22(*classRec,_SS),
                           (char *)CONCAT13((char)(Font03.ofs >> 8),CONCAT12((char)Font03.ofs,ptrSeg)
                                           ),Font03.seg,'U',(char)ptrSeg,(char)Font03.ofs,0x55,3,
                           msgPtr,maxWidth);
    namePtr = ovr_ovc15_usesStshRealloc
                       ((char *)BLD_WORD(&BuildingTypes[bldType], name, 0),(char)BLD_WORD(&BuildingTypes[bldType], name, 2),costTenth,(char)compute9Res,msgWidth,0,0,0);
    msgPtr = ovr_fmVsprintf("%s: Claim this tree? Harvest value is %d gold. Active party is %s the %s."
                            ,(char *)CONCAT13((char)((uint)ptrSeg >> 8),CONCAT12((char)ptrSeg,namePtr))
                           );
                           asm { mov ptrSeg,dx };
    maxWidth = SUB21(_SS,0);
    ssHiByte = (undefined1)((uint)_SS >> 8);
    strcpy((char *)CONCAT13(ssHiByte,CONCAT12(maxWidth,&msg)),
           (char *)CONCAT13((char)((uint)ptrSeg >> 8),CONCAT12((char)ptrSeg,msgPtr)));
    goldPartyIndex = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
    namePtr = &menuLabels;
    (*(uint8_t *)((uint8_t *)&(entries.seg))) = maxWidth;
    entries.ofs = (uint16_t)namePtr;
    (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = ssHiByte;
    (*(uint8_t *)((uint8_t *)&(hint.seg))) = maxWidth;
    hint.ofs = (uint16_t)&msg;
    (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = ssHiByte;
    ovr_ovc28_compute2(entries,menuIdx + 1U,hint,(char)(menuIdx + 1U),0);
    menuActions = (uint8_t)namePtr;
    goldPartyIndex = 0xff;
    if ((uint8_t)namePtr != 0x0) {
      menuActions = auStack_c[((uint)namePtr & 0xff) - 1];
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
      savedExpinc = (uint)BuildingTypes[bStack_11].expinc;
      BuildingTypes[bStack_11].expinc = 1;
      ovr_createConstructionRecord
                (bStack_11,agnt,GfxRndSeed2,(uint8_t *)outFlag,(char)outFlagSeg,(char)agnt,
                 (char)outFlag,(char)outFlagSeg,
                 CONCAT11((char)((uint)(entityIndex * 0x37) >> 8),
                          AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3)),0);
      BuildingTypes[bStack_11].expinc = (undefined1)savedExpinc;
      actorIdx = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
      pcStack_16 = ovr_ovc22_textPOPULATION(bStack_11,actorIdx,(agnt_t far *)agnt,actorIdx,(char)GfxRndSeed2);
      maxWidth = 0x10;
      partyIndex = *(char *)((int)&(Entities)[entityIndex].base.entity + 3);
      incomeRes = ovr_ovc22_seasonalIncome(bStack_11,partyIndex,partyIndex,agnt,(char)GfxRndSeed2);
      ovc45_compute6((uint16_t)pcStack_16);
      msgPtr = ovr_fmVsprintf("Forest claimed. This forest creates %d gold of income and feeds %d %s."
                              ,(char *)CONCAT13((char)((uint)pcStack_16 >> 8),
                                                CONCAT12((char)pcStack_16,incomeRes)));
      ovr_say(msgPtr,maxWidth);
      ovr_inputUpdate((ulong)MessageDelay << 1);
      doneFlag = '\x01';
    }
    else if (menuActions == 0x2) {
      ovr_play_sfx(48,0,0);
      actorIdx = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
      ovr_createConstructionRecordFar
                (0,agnt,GfxRndSeed2,(uint8_t *)CONCAT22(outFlagSeg,outFlag),actorIdx,(char)diArg,
                 (char)GfxRndSeed2,(char)outFlag,actorIdx);
      doneFlag = '\x01';
      bStack_10 = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
      ptrSeg = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
      entRec1 = (int)*(uint32_t *)((uint)bStack_10 << 2);
      goldLoPtr = (uint *)(entRec1 + 0x56);
      amountLo = *goldLoPtr;
      *goldLoPtr = *goldLoPtr + costTenth;
      goldHiPtr = (int *)(entRec1 + 0x58);
      *goldHiPtr = *goldHiPtr + (uint)CARRY2(amountLo,costTenth);
      ptrSeg = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
      sheetOfs = (int)*(uint32_t *)((uint)bStack_10 << 2);
      goldHi1 = *(int *)(sheetOfs + 0x58);
      amountLo = *(uint *)(sheetOfs + 0x56);
      ptrSeg = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
      entRec2 = (int)*(uint32_t *)((uint)bStack_10 << 2);
      sheetOfs = *(int *)(entRec2 + 0x8c);
      if ((sheetOfs <= goldHi1) && ((sheetOfs < goldHi1 || (*(uint *)(entRec2 + 0x8a) < amountLo)))) {
        ptrSeg = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
        entRec1 = (int)*(uint32_t *)((uint)bStack_10 << 2);
        amountLo = *(uint *)(entRec1 + 0x8a);
        segDead = (uint16_t)((ulong)*(uint32_t *)((uint)bStack_10 << 2) >> 0x10);
        sheetOfs = (int)*(uint32_t *)((uint)bStack_10 << 2);
        *(uint16_t *)(sheetOfs + 0x58) = *(uint16_t *)(entRec1 + 0x8c);
        *(uint *)(sheetOfs + 0x56) = amountLo;
      }
      maxWidth = (undefined1)amountLo;
      msgPtr = ovr_stsprintf((char *)&text);
      ovr_say(msgPtr,maxWidth);
      ovr_inputUpdate((ulong)MessageDelay << 1);
    }
    else if (menuActions == 0x3) {
      ptrSeg = ovc45_textChoosePartyBuild(agnt,GfxRndSeed2,&entityIndex,(char)GfxRndSeed2);
      partyRes = (char)ptrSeg;
      if (partyRes == -1) {
        doneFlag = '\x01';
      }
    }
    else if ((menuActions == 0x4) || (menuActions == 0x0)) {
      doneFlag = '\x01';
    }
  } while (doneFlag == '\0');
  return;
}


/* 77eb:20e8 */

/* [R6] touches GfxRndSeed2 */

/* 77eb:20e8 */

uint __cdecl16far ovc45_usesGfxRndSeed2(int far *x)

{
  byte bldSize;
  uint axIn;               /* AX, which the image reads back as the result */
  undefined1 axHigh;       /* the AH half the image carries across the cell probe */
  uint result;
  byte scanDown;
  byte cellType;
  
  scanDown = 0;
  while( true ) {
    if (3 < scanDown) {
      return axIn & 0xff00;
    }
    cellType = ovc45_getUnitType(*x - (uint)scanDown,GfxRndSeed2);
    axIn = CONCAT11(axHigh,cellType);
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
  int axIn;                /* AX across the bounds tests, as the image uses it */
  int result;
  byte hiByte;
  
  if ((((x < 0) || (y < 0)) || (axIn = x + 1, 0x93 < axIn)) || (axIn = y + 1, 0x3b < axIn)) {
    result = CONCAT11((char)((uint)axIn >> 8),2);
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
  int dstIdx;              /* destination write cursor */
  int runWidth;            /* running pixel width while copying */
  char dotMode;            /* the variadic argument at [bp+0x12]; 2 selects two dots */
  int textWidth;
  
  fullWidth = ovr_font_textWidth((*(uint16_t *)((uint8_t *)&(src) + 2)),font,maxWidth,0,0);
  if (mode < fullWidth) {
    if (dotMode == '\x02') {
      textWidth = ovr_font_textWidth((char *)"..",(char *)CONCAT22((*(uint16_t *)((uint8_t *)&(font) + 2)),(char *)0x2410),maxWidth,0,0)
      ;
    }
    else {
      textWidth = ovr_font_textWidth((char *)"...",(char *)CONCAT22((*(uint16_t *)((uint8_t *)&(font) + 2)),(char *)0x2410),maxWidth,0,0)
      ;
    }
    dstIdx = 0;
    for (runWidth = 0;
        (((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   dstIdx] != '\0' &&
        ((int)(textWidth + runWidth + (uint)*(byte *)((*(uint16_t *)((uint8_t *)&(font) + 2)) + ((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   dstIdx] + 0xa1)) <=
         (int)mode)); runWidth = runWidth + (uint)fontByte) {
      fontByte = *(byte *)((*(uint16_t *)((uint8_t *)&(font) + 2)) + ((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   dstIdx] + 0xa1);
      dest[dstIdx] = ((byte *)(*(uint16_t *)((uint8_t *)&(src) + 2)))[   dstIdx];
      dstIdx = dstIdx + 1;
    }
    dest[dstIdx] = '.';
    dest[dstIdx + 1] = '.';
    runWidth = dstIdx + 2;
    if (dotMode != '\x02') {
      dest[runWidth] = '.';
      runWidth = dstIdx + 3;
    }
    dest[runWidth] = '\0';
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


