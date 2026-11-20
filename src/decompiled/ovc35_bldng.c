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
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x2f) == -1) {
    iVar2 = (uint)(partyIndex >> 6) << 8;
  }
  else {
    uVar1 = *(undefined4 *)((uint)partyIndex << 2);
    iVar2 = CONCAT11((char)(((uint)partyIndex << 2) >> 8),*(undefined1 *)((int)uVar1 + 0x2f));
  }
  return iVar2;
}



/* 676c:003d */

/* [R2] string "arena" */

char * __cdecl16far bldng_textArena(byte bldType,char partyIndex)

{
  byte bVar1;
  byte bVar2;
  char *pcVar3;
  byte extraout_AH;
  uint uVar4;
  undefined2 uVar5;
  byte bStack_6;
  
  bVar1 = *(byte *)((uint)bldType * 0x27 + 0x134);
  if (bVar1 == 1) {
    pcVar3 = (char *)CONCAT11((char)((uint)bldType * 0x27 >> 8),1);
  }
  else {
    bVar1 = bVar1 & 0x7f;
    if ((*(byte *)((uint)bldType * 0x27 + 0x134) & 0x80) == 0) {
      for (uVar4 = 0; uVar4 < EntityCount; uVar4 = uVar4 + 1) {
        uVar5 = (undefined2)((ulong)Entities >> 0x10);
        if ((*(char *)((int)&((entity_t *)Entities)[uVar4].base.entity + 3) == partyIndex) &&
           (bVar1 <= ((entity_t *)Entities)[uVar4].base.level)) {
          return (char *)CONCAT11((char)(uVar4 * 0x37 >> 8),1);
        }
      }
      pcVar3 = (char *)"arena" + 4;
    }
    else {
      bVar2 = ovr_manage_findFirstLeader();
      if (bVar2 == 0xff) {
        pcVar3 = (char *)((uint)extraout_AH << 8);
      }
      else if (*(byte *)((int)*(undefined4 *)((uint)bVar2 << 2) + 0x86) < bVar1) {
        pcVar3 = (char *)((uint)(bVar2 >> 6) << 8);
      }
      else if (*(char *)((uint)bldType * 0x27 + 0x133) == '\x12') {
        bStack_6 = ListCount;
        for (uVar4 = 0; uVar4 < GRecordCount; uVar4 = uVar4 + 1) {
          if (*(char *)((uint)*(byte *)(uVar4 * 0x12 + 8) * 0x27 + 0x133) == '\x12') {
            bStack_6 = bStack_6 + 1;
          }
        }
        if (bStack_6 < 5) {
          if ((uint)*(byte *)((int)*(undefined4 *)((uint)bVar2 << 2) + 0x86) < bStack_6 + 4) {
            pcVar3 = (char *)0x0;
          }
          else {
            pcVar3 = (char *)((int)(undefined4 *)&_DATA + 1);
          }
        }
        else {
          pcVar3 = (char *)"arena" + 4;
        }
      }
      else {
        pcVar3 = (char *)CONCAT11((char)((uint)bldType * 0x27 >> 8),1);
      }
    }
  }
  return pcVar3;
}



/* 676c:01b0 */

/* Builds the building-selection menu entries (names and prices) for the candidate types. */

void __cdecl16far
bldng_buildMenuEntries(uint32_t bldTypes,far_t entries,int count,uint8_t partyIndex)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  char *pcVar6;
  undefined1 *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  int iVar10;
  int iVar12;
  int iVar13;
  undefined2 uVar14;
  uint8_t partyIndex_00;
  undefined1 *puVar16;
  uint uStack_e;
  undefined4 uStack_c;
  uint16_t uVar11;
  uint16_t uVar15;
  
  iVar12 = 0;
  while( true ) {
    iVar10 = (int)bldTypes;
    uVar14 = (undefined2)(bldTypes >> 0x10);
    uVar11 = entries.ofs;
    uVar15 = entries.seg;
    if (count + -1 <= iVar12) break;
    uVar3 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar12 * 2));
    uStack_e = *(uint *)((uVar3 & 0xff) * 0x27 + 0x125);
    iVar13 = iVar12;
    while (iVar13 = iVar13 + 1, iVar13 < count) {
      uVar3 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar13 * 2));
      if (*(uint *)((uVar3 & 0xff) * 0x27 + 0x125) < uStack_e) {
        uVar5 = *(undefined2 *)(iVar10 + iVar13 * 2);
        *(undefined2 *)(iVar10 + iVar13 * 2) = *(undefined2 *)(iVar10 + iVar12 * 2);
        *(undefined2 *)(iVar10 + iVar12 * 2) = uVar5;
        puVar8 = (undefined2 *)(uVar11 + iVar13 * 4);
        uVar5 = puVar8[1];
        uVar1 = *puVar8;
        puVar8 = (undefined2 *)(uVar11 + iVar12 * 4);
        uVar2 = *puVar8;
        puVar9 = (undefined2 *)(uVar11 + iVar13 * 4);
        puVar9[1] = puVar8[1];
        *puVar9 = uVar2;
        puVar8 = (undefined2 *)(uVar11 + iVar12 * 4);
        puVar8[1] = uVar5;
        *puVar8 = uVar1;
        uVar3 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar12 * 2));
        uStack_e = *(uint *)((uVar3 & 0xff) * 0x27 + 0x125);
      }
    }
    iVar12 = iVar12 + 1;
  }
  iVar12 = 0;
  do {
    if (count <= iVar12) {
      return;
    }
    uVar3 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar12 * 2));
    uVar3 = *(uint *)((uVar3 & 0xff) * 0x27 + 0x125);
    puVar8 = (undefined2 *)(uVar11 + iVar12 * 4);
    puVar7 = (undefined1 *)*puVar8;
    uStack_c = (undefined1 *)CONCAT22(puVar8[1],puVar7);
    puVar16 = (undefined1 *)0x0;
    uVar4 = ovr_ovc45_compute3(partyIndex);
    if (((int)puVar7 < (int)puVar16) || ((puVar16 == puVar7 && (uVar4 < uVar3)))) {
L_bldng_676c_01b0_037F:
      *uStack_c = 0x25;
    }
    else {
      partyIndex_00 = partyIndex;
      uVar5 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar12 * 2));
      pcVar6 = bldng_textArena((byte)uVar5,partyIndex_00);
      if ((char)pcVar6 == '\0') goto L_bldng_676c_01b0_037F;
      *uStack_c = 0x40;
    }
    iVar12 = iVar12 + 1;
  } while( true );
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

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Lets the player pick the building type to place and stores it in the sheet's buildType. */

void bldng_selectBuildingType(byte partyIndex)

{
  far_t entries;
  far_t entries_00;
  uint uVar1;
  undefined2 uVar2;
  char *pcVar3;
  uint8_t *puVar4;
  uint16_t uVar5;
  uint16_t count;
  char *unaff_SS;
  byte in_stack_00000004;
  far_t hint;
  uint8_t buildTypes;
  uint8_t menuEntries;
  undefined2 auStack_190 [97];
  char acStack_ce [200];
  int iStack_6;
  char cStack_4;
  byte bStack_3;
  
  bStack_3 = '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 +
                                 (uint)*(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2)
                                                + 0x3e) * 0x95) & 0x1f);
  _buildTypes = bldng_getClass(in_stack_00000004);
  _buildTypes = _buildTypes & 0xff;
  auStack_190[0] = *(undefined2 *)((int)&GStrangeTable[0x31].seg + _buildTypes * 4);
  _menuEntries = ((far_t *)(GStrangeTable + 0x31) + _buildTypes)->ofs;
  count = 1;
  iStack_6 = 7;
  while( true ) {
    if (0x30 < iStack_6) break;
    uVar1 = bldng_usesGStrangeTable((byte)iStack_6);
    if ((*(byte *)((uVar1 & 0xff) * 0x27 + 0x11f) & bStack_3) != 0) {
      uVar1 = bldng_usesGStrangeTable((byte)iStack_6);
      if (*(char *)((uVar1 & 0xff) * 0x27 + 0x12d) == '\0') {
        uVar2 = bldng_compute2((uint8_t)iStack_6,in_stack_00000004);
        if ((char)uVar2 != '\0') {
          *(int *)(&buildTypes + count * 2) = iStack_6;
          uVar5 = ((far_t *)(GStrangeTable + 0x31) + iStack_6)->ofs;
          auStack_190[count * 2] = *(undefined2 *)((int)&GStrangeTable[0x31].seg + iStack_6 * 4);
          *(uint16_t *)(&menuEntries + count * 4) = uVar5;
          count = count + 1;
        }
      }
    }
    iStack_6 = iStack_6 + 1;
  }
  entries_00.seg = (uint16_t)unaff_SS;
  entries_00.ofs = (uint16_t)&menuEntries;
  bldng_buildMenuEntries
            ((uint32_t)CONCAT22(unaff_SS,&buildTypes),entries_00,count,in_stack_00000004);
  bldng_usesGStrangeTable(*(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x85));
  uVar5 = 0x195d;
  pcVar3 = ovr_stsprintf(acStack_ce,unaff_SS,(char *)"Building is now %s.  Select type of building."
                        );
  hint.seg = uVar5;
  hint.ofs = (uint16_t)pcVar3;
  puVar4 = &menuEntries;
  entries.seg = (uint16_t)unaff_SS;
  entries.ofs = (uint16_t)puVar4;
  ovr_ovc28_compute2(entries,count,hint);
  cStack_4 = (char)puVar4;
  if ((char)puVar4 != '\0') {
    *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x85) =
         (&stack0xfe0a)[((uint)puVar4 & 0xff) * 2];
  }
  return;
}



/* 676c:05ac */

/* [R6] touches GStrangeTable */

undefined2 __cdecl16far bldng_usesGStrangeTable(byte typeIndex)

{
  return CONCAT11((char)((uint)typeIndex * 4 >> 8),
                  *(undefined1 *)(((far_t *)GStrangeTable)[typeIndex].ofs + 1));
}



/* 676c:05c3 */

/* [R4] calls ovr_randBelow */

undefined2 __cdecl16far bldng_usesRandBelow(byte typeIndex)

{
  uint16_t uVar1;
  int iVar2;
  
  uVar1 = ovr_randBelow((uint)*(byte *)((far_t *)GStrangeTable)[typeIndex]);
  iVar2 = (uVar1 & 0xff) + ((far_t *)GStrangeTable + typeIndex)->ofs;
  return CONCAT11((char)((uint)iVar2 >> 8),*(undefined1 *)(iVar2 + 1));
}


