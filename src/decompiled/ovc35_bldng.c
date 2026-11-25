/*
 * ovc35_bldng.c - recovered from STRONG.EXE
 * memory block: OVC35_bldng.c
 * range: 676c:0000 - 676c:064f
 * functions: 7
 */
#include "recovered.h"


/* 676c:0000 */

/* Returns the class byte of a party sheet (0 when unset). */

int __cdecl16far bldng_getClass(byte partyIndex)

{
  uint32_t uVar1;
  int iVar2;
  
  if (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x2f) == -1) {
    iVar2 = (uint)(partyIndex >> 6) << 8;
  }
  else {
    uVar1 = *(uint32_t *)((uint)partyIndex << 2);
    iVar2 = CONCAT11((char)(((uint)partyIndex << 2) >> 8),*(undefined1 *)((int)uVar1 + 0x2f));
  }
  return iVar2;
}



/* 676c:003d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R2] string "arena" */

bool __cdecl16far bldng_textArena(byte bldType,char partyIndex)

{
  /* Re-derived: may this building type be placed for `partyIndex`?  flags3 == 1 allows it
     outright; with bit 0x80 clear it is allowed when an entity of that party already reaches
     (flags3 & 0x7f); otherwise the party's first leader must exist and its titleIndex must reach
     (flags3 & 0x7f), and a hospital (unitType 0x12) additionally needs fewer than 5 existing
     hospitals and titleIndex >= count + 4. */
  byte reqLevel;
  bool allowed;
  byte leaderIndex;
  byte hospitalCount;
  uint entityIndex;
  uint recIndex;

  reqLevel = BuildingTypes[bldType].flags3;
  if (reqLevel == 1) {
    return true;
  }
  reqLevel = reqLevel & 0x7f;
  if ((BuildingTypes[bldType].flags3 & 0x80) == 0) {
    for (entityIndex = 0; entityIndex < (int)(uint)EntityCount;
         entityIndex = entityIndex + 1) {
      if ((AGNT_FIELD(&((entity_t *)Entities)[entityIndex], base.entity, 3) == partyIndex) &&
         (reqLevel <= ((entity_t *)Entities)[entityIndex].base.level)) {
        return true;
      }
    }
    return false;
  }
  leaderIndex = ovr_manage_findFirstLeader();
  if (leaderIndex == 0xff) {
    return false;
  }
  if ((GLeaderSheets[leaderIndex])->titleIndex < reqLevel) {
    return false;
  }
  if (BuildingTypes[bldType].unitType != '\x12') {
    return true;
  }
  hospitalCount = ListCount;
  for (recIndex = 0; recIndex < (int)(uint)GRecordCount; recIndex = recIndex + 1) {
    if (BuildingTypes[GRecords[recIndex].reserved08].unitType == '\x12') {
      hospitalCount = hospitalCount + 1;
    }
  }
  if (5 <= hospitalCount) {
    return false;
  }
  if ((uint)(GLeaderSheets[leaderIndex])->titleIndex < hospitalCount + 4) {
    return false;
  }
  return true;
}



/* 676c:01b0 */
void __cdecl16far
bldng_buildMenuEntries(uint32_t bldTypes,far_t entries,int count,uint8_t partyIndex)

{
  /* 676c:01b0, re-derived.  Selection sort of the bldTypes uint16 array (and the
     parallel entries array) by BuildingTypes[usesGStrangeTable(bldTypes[i])].word at
     +0x125 ascending; then each entry's first byte is set to 0x40 when the party can
     afford it and 0x25 otherwise.  bldTypesOfs / entries.ofs are loop invariants and are
     hoisted out of the loops; the two dead segment copies (uVar14, uVar15) and the
     constant-pointer comparison helper are gone. */
  int bldTypesOfs;
  uint tableIdx;
  uint sortKey;
  uint minKey;
  uint available;
  int i;
  int j;
  uint16_t swapTypes;
  far_t swapEntry;
  uint16_t *entryPair;
  uint16_t entryOfs;
  byte *entryPtr;

  bldTypesOfs = (int)bldTypes;
  for (i = 0; count + -1 > i; i = i + 1) {
    tableIdx = bldng_usesGStrangeTable(*(byte *)(bldTypesOfs + i * 2));
    minKey = BuildingTypes[(tableIdx & 0xff)].cost;
    for (j = i + 1; j < count; j = j + 1) {
      tableIdx = bldng_usesGStrangeTable(*(byte *)(bldTypesOfs + j * 2));
      sortKey = BuildingTypes[(tableIdx & 0xff)].cost;
      if (sortKey < minKey) {
        swapTypes = *(uint16_t *)(bldTypesOfs + j * 2);
        *(uint16_t *)(bldTypesOfs + j * 2) = *(uint16_t *)(bldTypesOfs + i * 2);
        *(uint16_t *)(bldTypesOfs + i * 2) = swapTypes;
        swapEntry = *(far_t *)(entries.ofs + j * 4);
        *(far_t *)(entries.ofs + j * 4) = *(far_t *)(entries.ofs + i * 4);
        *(far_t *)(entries.ofs + i * 4) = swapEntry;
        tableIdx = bldng_usesGStrangeTable(*(byte *)(bldTypesOfs + i * 2));
        minKey = BuildingTypes[(tableIdx & 0xff)].cost;
      }
    }
  }
  for (i = 0; i < count; i = i + 1) {
    tableIdx = bldng_usesGStrangeTable(*(byte *)(bldTypesOfs + i * 2));
    sortKey = BuildingTypes[(tableIdx & 0xff)].cost;
    entryPair = (uint16_t *)(entries.ofs + i * 4);
    entryOfs = *entryPair;
    entryPtr = (byte *)CONCAT22(entryPair[1],entryOfs);
    available = ovr_ovc45_compute3(partyIndex);
    if (((int)entryOfs < 0) || ((entryOfs == 0) && (available < sortKey))) {
setUnavailable:
      *entryPtr = 0x25;
    }
    else {
      tableIdx = bldng_usesGStrangeTable(*(byte *)(bldTypesOfs + i * 2));
      if (!bldng_textArena((byte)tableIdx,partyIndex)) goto setUnavailable;
      *entryPtr = 0x40;
    }
  }
}


/* 676c:0393 */

/* [R7] body shape: compute */

int __cdecl16far bldng_compute2(uint8_t buildType,char leader)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte extraout_AH;
  
  uVar2 = bldng_usesGStrangeTable(buildType);
  iVar3 = (uVar2 & 0xff) * 0x27;
  if (*(char *)(iVar3 + 0x133) == '\x17') {
    bVar1 = ovr_manage_findFirstLeader();
    if (bVar1 == leader) {
      iVar3 = CONCAT11(extraout_AH,1);
    }
    else {
      iVar3 = (uint)extraout_AH << 8;
    }
  }
  else {
    iVar3 = CONCAT11((char)((uint)iVar3 >> 8),1);
  }
  return iVar3;
}



/* 676c:03dd */
void bldng_selectBuildingType(byte partyIndex)

{
  undefined1 stk_fe0a;   /* stack slot fe0a */
  uint16_t uVar1;
  far_t entries;
  far_t entries_00;
  far_t hint;
  uint uVar2;
  uint16_t uVar3;
  int iVar4;
  char *pcVar5;
  uint8_t *puVar6;
  uint16_t uVar7;
  uint16_t count;
  byte in_stack_00000004;
  undefined1 uVar8;
  uint8_t buildTypes;
  uint8_t menuEntries;
  uint16_t auStack_190 [97];
  char acStack_ce [200];
  int iStack_6;
  char cStack_4;
  byte bitMask;
  
  bitMask = '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 +
                                 (uint)(GLeaderSheets[in_stack_00000004])->classStr * 0x95) & 0x1f);
  buildTypes = bldng_getClass(in_stack_00000004);
  buildTypes = buildTypes & 0xff;
  auStack_190[0] = *(uint16_t *)((int)&GStrangeTable[0x31].seg + buildTypes * 4);
  menuEntries = ((far_t far *)(GStrangeTable + 0x31) + buildTypes)->ofs;
  count = 1;
  iStack_6 = 7;
  while( true ) {
    if (0x30 < iStack_6) break;
    uVar2 = bldng_usesGStrangeTable((byte)iStack_6);
    if ((BuildingTypes[(uVar2 & 0xff)].type & bitMask) != 0) {
      uVar2 = bldng_usesGStrangeTable((byte)iStack_6);
      if (*(char *)((uVar2 & 0xff) * 0x27 + 0x12d) == '\0') {
        uVar3 = bldng_compute2((uint8_t)iStack_6,in_stack_00000004);
        if ((char)uVar3 != '\0') {
          *(int *)(&buildTypes + count * 2) = iStack_6;
          uVar1 = ((far_t far *)(GStrangeTable + 0x31) + iStack_6)->ofs;
          auStack_190[count * 2] = *(uint16_t *)((int)&GStrangeTable[0x31].seg + iStack_6 * 4);
          *(uint16_t *)(&menuEntries + count * 4) = uVar1;
          count = count + 1;
        }
      }
    }
    iStack_6 = iStack_6 + 1;
  }
  entries_00.seg = (uint16_t)_SS;
  entries_00.ofs = (uint16_t)&menuEntries;
  bldng_buildMenuEntries
            ((uint32_t)CONCAT22(_SS,&buildTypes),entries_00,count,in_stack_00000004);
  uVar2 = bldng_usesGStrangeTable
                    ((GLeaderSheets[in_stack_00000004])->buildType[0]);
  iVar4 = (uVar2 & 0xff) * 0x27;
  uVar3 = *(uint16_t *)(iVar4 + 0x10e);
  uVar8 = (undefined1)uVar3;
  pcVar5 = ovr_stsprintf(acStack_ce,(char *)CONCAT22(0x690b,_SS),
                         (char *)CONCAT13((char)((uint)uVar3 >> 8),CONCAT12(uVar8,0x2410)),uVar8,
                         (char)*(uint16_t *)(iVar4 + 0x110));
  asm { mov uVar7,dx };
  puVar6 = &menuEntries;
  entries.seg = (uint16_t)_SS;
  entries.ofs = (uint16_t)puVar6;
  (*(uint8_t *)((uint8_t *)&(hint.seg))) = (char)uVar7;
  hint.ofs = (uint16_t)pcVar5;
  (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = (char)((uint)uVar7 >> 8);
  ovr_ovc28_compute2(entries,count,hint,(char)pcVar5,0);
  cStack_4 = (char)puVar6;
  if ((char)puVar6 != '\0') {
    (GLeaderSheets[in_stack_00000004])->buildType[0] =
         (&stk_fe0a)[((uint)puVar6 & 0xff) * 2];
  }
  return;
}


/* 676c:05ac */

/* [R6] touches GStrangeTable */

uint16_t __cdecl16far bldng_usesGStrangeTable(byte typeIndex)

{
  return CONCAT11((char)((uint)typeIndex * 4 >> 8),
                  *(undefined1 *)(((far_t *)GStrangeTable)[typeIndex].ofs + 1));
}



/* 676c:05c3 */
uint16_t __cdecl16far bldng_usesRandBelow(byte typeIndex)

{
  uint16_t uVar1;
  int iVar2;
  
  uVar1 = ovr_randBelow((uint)*(byte *)MK_FP(((far_t far *)GStrangeTable)[typeIndex].seg,((far_t far *)GStrangeTable)[typeIndex].ofs),0)   /* hand fix: the entry is a far pointer, not a far_t value */;
  iVar2 = (uVar1 & 0xff) + ((far_t far *)GStrangeTable + typeIndex)->ofs;
  return CONCAT11((char)((uint)iVar2 >> 8),*(undefined1 *)(iVar2 + 1));
}

