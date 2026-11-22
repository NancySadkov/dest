/*
 * ovc35_bldng.c - recovered from STRONG.EXE
 * memory block: OVC35_bldng.c
 * range: 676c:0000 - 676c:064f
 * functions: 7
 */
#include "recovered.h"


/* 676c:0000 */

/* Returns the class byte of a party sheet (0 when unset). */

int __cdecl16far bldng_getClass(byte partyIndex,...)

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

bool __cdecl16far bldng_textArena(byte bldType,char partyIndex,...)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  uint16_t uVar5;
  byte bStack_6;
  
  bVar1 = *(byte *)((uint)bldType * 0x27 + 0x134);
  if (bVar1 == 1) {
    bVar2 = true;
  }
  else {
    bVar1 = bVar1 & 0x7f;
    if ((*(byte *)((uint)bldType * 0x27 + 0x134) & 0x80) == 0) {
      for (uVar4 = 0; uVar4 < EntityCount; uVar4 = uVar4 + 1) {
        uVar5 = (uint16_t)((ulong)Entities >> 0x10);
        if ((*(char *)((int)Entities + uVar4 * 0x37 + 0x1a) == partyIndex) &&
           (bVar1 <= ((entity_t *)Entities)[uVar4].base.level)) {
          return true;
        }
      }
      bVar2 = false;
    }
    else {
      bVar3 = ovr_manage_findFirstLeader();
      if (bVar3 == 0xff) {
        bVar2 = false;
      }
      else if (((char_sheet_t *)(((uint)bVar3 << 2)))->titleIndex < bVar1) {
        bVar2 = false;
      }
      else if (*(char *)((uint)bldType * 0x27 + 0x133) == '\x12') {
        bStack_6 = ListCount;
        for (uVar4 = 0; uVar4 < GRecordCount; uVar4 = uVar4 + 1) {
          if (*(char *)((uint)*(byte *)(uVar4 * 0x12 + 8) * 0x27 + 0x133) == '\x12') {
            bStack_6 = bStack_6 + 1;
          }
        }
        if (bStack_6 < 5) {
          if ((uint)((char_sheet_t *)(((uint)bVar3 << 2)))->titleIndex < bStack_6 + 4) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
        }
        else {
          bVar2 = false;
        }
      }
      else {
        bVar2 = true;
      }
    }
  }
  return bVar2;
}



/* 676c:01b0 */
void __cdecl16far
bldng_buildMenuEntries(uint32_t bldTypes,far_t entries,int count,uint8_t partyIndex)

{
  uint16_t uVar1;
  uint16_t uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint16_t uVar6;
  undefined1 *puVar7;
  uint16_t *puVar8;
  uint16_t *puVar9;
  int iVar10;
  int iVar12;
  int iVar13;
  uint16_t uVar14;
  uint8_t partyIndex_00;
  undefined1 *puVar16;
  uint uStack_e;
  undefined1 *uStack_c;   /* hand fix: assigned a byte pointer and dereferenced as *uStack_c */
  uint16_t uVar11;
  uint16_t uVar15;
  
  iVar12 = 0;
  while( true ) {
    iVar10 = (int)bldTypes;
    uVar14 = (uint16_t)(bldTypes >> 0x10);
    uVar11 = entries.ofs;
    uVar15 = entries.seg;
    if (count + -1 <= iVar12) break;
    uVar4 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar12 * 2));
    uStack_e = *(uint *)((uVar4 & 0xff) * 0x27 + 0x125);
    iVar13 = iVar12;
    while (iVar13 = iVar13 + 1, iVar13 < count) {
      uVar4 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar13 * 2));
      if (*(uint *)((uVar4 & 0xff) * 0x27 + 0x125) < uStack_e) {
        uVar6 = *(uint16_t *)(iVar10 + iVar13 * 2);
        *(uint16_t *)(iVar10 + iVar13 * 2) = *(uint16_t *)(iVar10 + iVar12 * 2);
        *(uint16_t *)(iVar10 + iVar12 * 2) = uVar6;
        puVar8 = (uint16_t *)(uVar11 + iVar13 * 4);
        uVar6 = puVar8[1];
        uVar1 = *puVar8;
        puVar8 = (uint16_t *)(uVar11 + iVar12 * 4);
        uVar2 = *puVar8;
        puVar9 = (uint16_t *)(uVar11 + iVar13 * 4);
        puVar9[1] = puVar8[1];
        *puVar9 = uVar2;
        puVar8 = (uint16_t *)(uVar11 + iVar12 * 4);
        puVar8[1] = uVar6;
        *puVar8 = uVar1;
        uVar4 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar12 * 2));
        uStack_e = *(uint *)((uVar4 & 0xff) * 0x27 + 0x125);
      }
    }
    iVar12 = iVar12 + 1;
  }
  iVar12 = 0;
  do {
    if (count <= iVar12) {
      return;
    }
    uVar4 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar12 * 2));
    uVar4 = *(uint *)((uVar4 & 0xff) * 0x27 + 0x125);
    puVar8 = (uint16_t *)(uVar11 + iVar12 * 4);
    puVar7 = (undefined1 *)*puVar8;
    uStack_c = (undefined1 *)CONCAT22(puVar8[1],puVar7);
    puVar16 = (undefined1 *)0x0;
    uVar5 = ovr_ovc45_compute3(partyIndex);
    if (((int)puVar7 < (int)puVar16) || ((puVar16 == puVar7 && (uVar5 < uVar4)))) {
L_bldng_676c_01b0_037F:
      *uStack_c = 0x25;
    }
    else {
      partyIndex_00 = partyIndex;
      uVar6 = bldng_usesGStrangeTable(*(byte *)(iVar10 + iVar12 * 2));
      bVar3 = bldng_textArena((byte)uVar6,partyIndex_00);
      if (!bVar3) goto L_bldng_676c_01b0_037F;
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
  char *unaff_SS;
  byte in_stack_00000004;
  undefined1 uVar8;
  uint8_t buildTypes;
  uint8_t menuEntries;
  uint16_t auStack_190 [97];
  char acStack_ce [200];
  int iStack_6;
  char cStack_4;
  byte bStack_3;
  
  bStack_3 = '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 +
                                 (uint)((char_sheet_t *)(((uint)in_stack_00000004 << 2)))->classStr * 0x95) & 0x1f);
  buildTypes = bldng_getClass(in_stack_00000004);
  buildTypes = buildTypes & 0xff;
  auStack_190[0] = *(uint16_t *)((int)&GStrangeTable[0x31].seg + buildTypes * 4);
  menuEntries = ((far_t far *)(GStrangeTable + 0x31) + buildTypes)->ofs;
  count = 1;
  iStack_6 = 7;
  while( true ) {
    if (0x30 < iStack_6) break;
    uVar2 = bldng_usesGStrangeTable((byte)iStack_6);
    if ((*(byte *)((uVar2 & 0xff) * 0x27 + 0x11f) & bStack_3) != 0) {
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
  entries_00.seg = (uint16_t)unaff_SS;
  entries_00.ofs = (uint16_t)&menuEntries;
  bldng_buildMenuEntries
            ((uint32_t)CONCAT22(unaff_SS,&buildTypes),entries_00,count,in_stack_00000004);
  uVar2 = bldng_usesGStrangeTable
                    (((char_sheet_t *)(((uint)in_stack_00000004 << 2)))->buildType[0]);
  iVar4 = (uVar2 & 0xff) * 0x27;
  uVar7 = 0x195d;
  uVar3 = *(uint16_t *)(iVar4 + 0x10e);
  uVar8 = (undefined1)uVar3;
  pcVar5 = ovr_stsprintf(acStack_ce,(char *)CONCAT22(0x690b,unaff_SS),
                         (char *)CONCAT13((char)((uint)uVar3 >> 8),CONCAT12(uVar8,0x2410)),uVar8,
                         (char)*(uint16_t *)(iVar4 + 0x110));
  puVar6 = &menuEntries;
  entries.seg = (uint16_t)unaff_SS;
  entries.ofs = (uint16_t)puVar6;
  (*(uint8_t *)((uint8_t *)&(hint.seg))) = (char)uVar7;
  hint.ofs = (uint16_t)pcVar5;
  (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = (char)((uint)uVar7 >> 8);
  ovr_ovc28_compute2(entries,count,hint,(char)pcVar5);
  cStack_4 = (char)puVar6;
  if ((char)puVar6 != '\0') {
    ((char_sheet_t *)(((uint)in_stack_00000004 << 2)))->buildType[0] =
         (&stk_fe0a)[((uint)puVar6 & 0xff) * 2];
  }
  return;
}


/* 676c:05ac */

/* [R6] touches GStrangeTable */

uint16_t __cdecl16far bldng_usesGStrangeTable(byte typeIndex,...)

{
  return CONCAT11((char)((uint)typeIndex * 4 >> 8),
                  *(undefined1 *)(((far_t *)GStrangeTable)[typeIndex].ofs + 1));
}



/* 676c:05c3 */
uint16_t __cdecl16far bldng_usesRandBelow(byte typeIndex,...)

{
  uint16_t uVar1;
  int iVar2;
  
  uVar1 = ovr_randBelow((uint)*(byte *)MK_FP(((far_t far *)GStrangeTable)[typeIndex].seg,((far_t far *)GStrangeTable)[typeIndex].ofs))   /* hand fix: the entry is a far pointer, not a far_t value */;
  iVar2 = (uVar1 & 0xff) + ((far_t far *)GStrangeTable + typeIndex)->ofs;
  return CONCAT11((char)((uint)iVar2 >> 8),*(undefined1 *)(iVar2 + 1));
}

