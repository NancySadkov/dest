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
  undefined4 uVar1;
  int iVar2;
  byte in_stack_00000004;
  
  if (*(char *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x2f) == -1) {
    iVar2 = (uint)(in_stack_00000004 >> 6) << 8;
  }
  else {
    uVar1 = *(undefined4 *)((uint)in_stack_00000004 << 2);
    iVar2 = CONCAT11((char)(((uint)in_stack_00000004 << 2) >> 8),*(undefined1 *)((int)uVar1 + 0x2f))
    ;
  }
  return iVar2;
}



/* 676c:003d */

/* [R2] string "arena" */

bool __cdecl16far bldng_textArena(byte bldType,char partyIndex,...)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  undefined2 uVar5;
  byte in_stack_00000004;
  byte bStack_6;
  
  bVar1 = *(byte *)((uint)in_stack_00000004 * 0x27 + 0x134);
  if (bVar1 == 1) {
    bVar2 = true;
  }
  else {
    bVar1 = bVar1 & 0x7f;
    if ((*(byte *)((uint)in_stack_00000004 * 0x27 + 0x134) & 0x80) == 0) {
      for (uVar4 = 0; uVar4 < EntityCount; uVar4 = uVar4 + 1) {
        uVar5 = (undefined2)((ulong)Entities >> 0x10);
        if ((*(byte *)((int)&((entity_t *)Entities)[uVar4].base.entity + 3) == bldType) &&
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
      else if (*(byte *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x86) < bVar1) {
        bVar2 = false;
      }
      else if (*(char *)((uint)in_stack_00000004 * 0x27 + 0x133) == '\x12') {
        bStack_6 = ListCount;
        for (uVar4 = 0; uVar4 < GRecordCount; uVar4 = uVar4 + 1) {
          if (*(char *)((uint)*(byte *)(uVar4 * 0x12 + 8) * 0x27 + 0x133) == '\x12') {
            bStack_6 = bStack_6 + 1;
          }
        }
        if (bStack_6 < 5) {
          if ((uint)*(byte *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x86) < bStack_6 + 4) {
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

/* Builds the building-selection menu entries (names and prices) for the candidate types. */

void __cdecl16far
bldng_buildMenuEntries(uint32_t bldTypes,far_t entries,int count,uint8_t partyIndex)

{
  undefined2 uVar1;
  undefined2 uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined1 *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  int iVar10;
  int iVar12;
  undefined2 unaff_DI;
  int iVar13;
  undefined2 uVar14;
  byte bldType;
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
    uVar4 = bldng_usesGStrangeTable
                      ((byte)unaff_DI,
                       CONCAT11((char)((uint)(iVar12 * 2) >> 8),*(undefined1 *)(iVar10 + iVar12 * 2)
                               ));
    uStack_e = *(uint *)((uVar4 & 0xff) * 0x27 + 0x125);
    iVar13 = iVar12;
    while (iVar13 = iVar13 + 1, iVar13 < count) {
      uVar4 = bldng_usesGStrangeTable
                        ((byte)unaff_DI,
                         CONCAT11((char)((uint)(iVar13 * 2) >> 8),
                                  *(undefined1 *)(iVar10 + iVar13 * 2)));
      if (*(uint *)((uVar4 & 0xff) * 0x27 + 0x125) < uStack_e) {
        uVar6 = *(undefined2 *)(iVar10 + iVar13 * 2);
        *(undefined2 *)(iVar10 + iVar13 * 2) = *(undefined2 *)(iVar10 + iVar12 * 2);
        *(undefined2 *)(iVar10 + iVar12 * 2) = uVar6;
        puVar8 = (undefined2 *)(uVar11 + iVar13 * 4);
        uVar6 = puVar8[1];
        uVar1 = *puVar8;
        puVar8 = (undefined2 *)(uVar11 + iVar12 * 4);
        uVar2 = *puVar8;
        puVar9 = (undefined2 *)(uVar11 + iVar13 * 4);
        puVar9[1] = puVar8[1];
        *puVar9 = uVar2;
        puVar8 = (undefined2 *)(uVar11 + iVar12 * 4);
        puVar8[1] = uVar6;
        *puVar8 = uVar1;
        uVar4 = bldng_usesGStrangeTable
                          ((byte)unaff_DI,
                           CONCAT11((char)((uint)(iVar12 * 2) >> 8),
                                    *(undefined1 *)(iVar10 + iVar12 * 2)));
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
    uVar4 = bldng_usesGStrangeTable
                      ((byte)unaff_DI,
                       CONCAT11((char)((uint)(iVar12 * 2) >> 8),*(undefined1 *)(iVar10 + iVar12 * 2)
                               ));
    uVar4 = *(uint *)((uVar4 & 0xff) * 0x27 + 0x125);
    puVar8 = (undefined2 *)(uVar11 + iVar12 * 4);
    puVar7 = (undefined1 *)*puVar8;
    uStack_c = (undefined1 *)CONCAT22(puVar8[1],puVar7);
    puVar16 = (undefined1 *)0x0;
    uVar5 = ovr_ovc45_compute3(0,(uint)partyIndex);
    if (((int)puVar7 < (int)puVar16) || ((puVar16 == puVar7 && (uVar5 < uVar4)))) {
L_bldng_676c_01b0_037F:
      *uStack_c = 0x25;
    }
    else {
      bldType = partyIndex;
      uVar6 = bldng_usesGStrangeTable
                        (partyIndex,
                         CONCAT11((char)((uint)(iVar12 * 2) >> 8),
                                  *(undefined1 *)(iVar10 + iVar12 * 2)));
      bVar3 = bldng_textArena(bldType,(char)unaff_DI,uVar6);
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
  undefined2 in_AX;
  uint uVar2;
  int iVar3;
  byte extraout_AH;
  byte in_stack_0000fffc;
  
  uVar2 = bldng_usesGStrangeTable(in_stack_0000fffc,CONCAT11((char)((uint)in_AX >> 8),buildType));
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
  undefined4 uVar1;
  far_t entries;
  far_t entries_00;
  undefined2 uVar2;
  uint uVar3;
  uint16_t *puVar4;
  int iVar5;
  char *count;
  uint8_t *puVar6;
  uint16_t uVar7;
  undefined1 uVar8;
  uint16_t count_00;
  uint unaff_DI;
  char *unaff_SS;
  byte in_stack_00000004;
  ulong uVar9;
  ulong uVar10;
  uint16_t uVar11;
  far_t hint;
  uint8_t buildTypes;
  uint8_t menuEntries;
  uint auStack_190 [97];
  undefined1 auStack_ce [200];
  int iStack_6;
  char cStack_4;
  byte bStack_3;
  
  bStack_3 = '\x01' << (*(byte *)((int)&worldMenuLabels[9].ofs + 1 +
                                 (uint)*(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2)
                                                + 0x3e) * 0x95) & 0x1f);
  uVar9 = (ulong)unaff_DI << 0x10;
  buildTypes = bldng_getClass();
  buildTypes = buildTypes & 0xff;
  uVar3 = *(uint *)((int)&GStrangeTable[0x31].seg + buildTypes * 4);
  menuEntries = ((far_t *)(GStrangeTable + 0x31) + buildTypes)->ofs;
  puVar4 = (uint16_t *)&menuEntries;
  count_00 = 1;
  iStack_6 = 7;
  auStack_190[0] = uVar3;
  while( true ) {
    uVar8 = (undefined1)((uint)puVar4 >> 8);
    uVar11 = (uint16_t)(uVar9 >> 0x10);
    if (0x30 < iStack_6) break;
    uVar2 = CONCAT11((char)(uVar3 >> 8),(undefined1)iStack_6);
    uVar10 = CONCAT22(uVar11,uVar2);
    uVar3 = bldng_usesGStrangeTable((byte)(uVar9 >> 0x10),uVar2);
    puVar4 = (uint16_t *)((uVar3 & 0xff) * 0x27);
    uVar3 = CONCAT11(uVar8,bStack_3);
    uVar9 = uVar10;
    if ((*(byte *)((int)puVar4 + 0x11f) & bStack_3) != 0) {
      uVar9 = CONCAT22((int)(uVar10 >> 0x10),CONCAT11(uVar8,(undefined1)iStack_6));
      uVar3 = bldng_usesGStrangeTable((byte)(uVar10 >> 0x10),CONCAT11(uVar8,(undefined1)iStack_6));
      puVar4 = (uint16_t *)((uVar3 & 0xff) * 0x27);
      uVar3 = (uint)*(byte *)((int)puVar4 + 0x12d);
      if (uVar3 == 0) {
        uVar9 = uVar9 & 0xffff0000;
        uVar3 = bldng_compute2((uint8_t)iStack_6,in_stack_00000004);
        if ((char)uVar3 != '\0') {
          *(int *)(&buildTypes + count_00 * 2) = iStack_6;
          puVar4 = (uint16_t *)(&menuEntries + count_00 * 4);
          uVar3 = *(uint *)((int)&GStrangeTable[0x31].seg + iStack_6 * 4);
          uVar11 = ((far_t *)(GStrangeTable + 0x31) + iStack_6)->ofs;
          auStack_190[count_00 * 2] = uVar3;
          *puVar4 = uVar11;
          count_00 = count_00 + 1;
        }
      }
    }
    iStack_6 = iStack_6 + 1;
  }
  entries.seg = (uint16_t)unaff_SS;
  entries.ofs = (uint16_t)&menuEntries;
  bldng_buildMenuEntries
            ((uint32_t)CONCAT22(unaff_SS,&buildTypes),entries,count_00,in_stack_00000004);
  uVar1 = *(undefined4 *)((uint)in_stack_00000004 << 2);
  uVar3 = bldng_usesGStrangeTable
                    ((byte)uVar11,
                     CONCAT11((char)(((uint)in_stack_00000004 << 2) >> 8),
                              *(undefined1 *)((int)uVar1 + 0x85)));
  iVar5 = (uVar3 & 0xff) * 0x27;
  uVar7 = 0x195d;
  uVar2 = *(undefined2 *)(iVar5 + 0x10e);
  uVar8 = (undefined1)uVar2;
  count = ovr_stsprintf((char *)CONCAT22(0x690b,unaff_SS),
                        (char *)CONCAT13((char)((uint)uVar2 >> 8),CONCAT12(uVar8,0x2410)),
                        (char *)*(undefined2 *)(iVar5 + 0x110),auStack_ce,uVar8);
  hint.seg = uVar11;
  hint.ofs = uVar7;
  puVar6 = &menuEntries;
  entries_00.seg = count_00;
  entries_00.ofs = (uint16_t)unaff_SS;
  ovr_ovc28_compute2(entries_00,(uint16_t)count,hint,puVar6,(char)count);
  cStack_4 = (char)puVar6;
  if ((char)puVar6 != '\0') {
    *(undefined1 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x85) =
         (&stack0xfe0a)[((uint)puVar6 & 0xff) * 2];
  }
  return;
}



/* 676c:05ac */

/* [R6] touches GStrangeTable */

undefined2 __cdecl16far bldng_usesGStrangeTable(byte typeIndex,...)

{
  byte in_stack_00000004;
  
  return CONCAT11((char)((uint)in_stack_00000004 * 4 >> 8),
                  *(undefined1 *)(((far_t *)GStrangeTable)[in_stack_00000004].ofs + 1));
}



/* 676c:05c3 */

/* [R4] calls ovr_randBelow */

undefined2 __cdecl16far bldng_usesRandBelow(byte typeIndex,...)

{
  uint16_t uVar1;
  int iVar2;
  uint16_t unaff_BP;
  byte in_stack_00000004;
  
  uVar1 = ovr_randBelow(unaff_BP,(uint)*(byte *)((far_t *)GStrangeTable)[in_stack_00000004]);
  iVar2 = (uVar1 & 0xff) + ((far_t *)GStrangeTable + in_stack_00000004)->ofs;
  return CONCAT11((char)((uint)iVar2 >> 8),*(undefined1 *)(iVar2 + 1));
}


