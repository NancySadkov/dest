/*
 * ovc35_bldng.c - recovered from STRONG.EXE
 * memory block: OVC35_bldng.c
 * range: 676c:0000 - 676c:064f
 * functions: 7
 */
#include "recovered.h"


/* 676c:0000 */

int __cdecl16far bldng_676c_0000(byte param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x2f) == -1) {
    iVar2 = (uint)(param_1 >> 6) << 8;
  }
  else {
    uVar1 = *(undefined4 *)((uint)param_1 << 2);
    iVar2 = CONCAT11((char)(((uint)param_1 << 2) >> 8),*(undefined1 *)((int)uVar1 + 0x2f));
  }
  return iVar2;
}



/* 676c:003d */

char * __cdecl16far bldng_676c_003d(byte param_1,char param_2)

{
  byte bVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  byte bStack_6;
  
  bVar1 = *(byte *)((uint)param_1 * 0x27 + 0x134);
  if (bVar1 == 1) {
    pcVar3 = (char *)CONCAT11((char)((uint)param_1 * 0x27 >> 8),1);
  }
  else {
    bVar1 = bVar1 & 0x7f;
    if ((*(byte *)((uint)param_1 * 0x27 + 0x134) & 0x80) == 0) {
      for (uVar5 = 0; uVar5 < EntityCount; uVar5 = uVar5 + 1) {
        if ((*(char *)(Entities.ofs + uVar5 * 0x37 + 0x1a) == param_2) &&
           (bVar1 <= *(byte *)(Entities.ofs + uVar5 * 0x37 + 0xf))) {
          return (char *)CONCAT11((char)(uVar5 * 0x37 >> 8),1);
        }
      }
      pcVar3 = (char *)"arena" + 4;
    }
    else {
      uVar5 = ovr_manage_4d05_1b1d();
      if ((byte)uVar5 == 0xff) {
        pcVar3 = (char *)(uVar5 & 0xff00);
      }
      else {
        uVar2 = *(undefined4 *)((uVar5 & 0xff) << 2);
        if (*(byte *)((int)uVar2 + 0x86) < bVar1) {
          pcVar3 = (char *)((uint)(byte)((byte)uVar5 >> 6) << 8);
        }
        else if (*(char *)((uint)param_1 * 0x27 + 0x133) == '\x12') {
          bStack_6 = DAT_2000_d3c6;
          for (uVar4 = 0; uVar4 < DAT_2000_d2df; uVar4 = uVar4 + 1) {
            if (*(char *)((uint)*(byte *)(uVar4 * 0x12 + 8) * 0x27 + 0x133) == '\x12') {
              bStack_6 = bStack_6 + 1;
            }
          }
          if (bStack_6 < 5) {
            uVar2 = *(undefined4 *)((uVar5 & 0xff) << 2);
            if ((uint)*(byte *)((int)uVar2 + 0x86) < bStack_6 + 4) {
              pcVar3 = (char *)0x0;
            }
            else {
              pcVar3 = (char *)0x1;
            }
          }
          else {
            pcVar3 = (char *)"arena" + 4;
          }
        }
        else {
          pcVar3 = (char *)CONCAT11((char)((uint)param_1 * 0x27 >> 8),1);
        }
      }
    }
  }
  return pcVar3;
}



/* 676c:01b0 */

void __cdecl16far
bldng_676c_01b0(undefined4 param_1,undefined4 param_2,int param_3,undefined1 param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  undefined2 uVar7;
  undefined1 *puVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  int iVar11;
  int iVar13;
  int iVar14;
  undefined2 uVar15;
  undefined1 *puVar17;
  uint uStack_e;
  undefined4 uStack_c;
  int iVar12;
  undefined2 uVar16;
  
  iVar13 = 0;
  while( true ) {
    iVar11 = (int)param_1;
    uVar15 = (undefined2)((ulong)param_1 >> 0x10);
    iVar12 = (int)param_2;
    uVar16 = (undefined2)((ulong)param_2 >> 0x10);
    if (param_3 + -1 <= iVar13) break;
    bVar4 = bldng_676c_05ac(CONCAT11((char)((uint)(iVar13 * 2) >> 8),
                                     *(undefined1 *)(iVar11 + iVar13 * 2)));
    uStack_e = *(uint *)((uint)bVar4 * 0x27 + 0x125);
    iVar14 = iVar13;
    while (iVar14 = iVar14 + 1, iVar14 < param_3) {
      bVar4 = bldng_676c_05ac(CONCAT11((char)((uint)(iVar14 * 2) >> 8),
                                       *(undefined1 *)(iVar11 + iVar14 * 2)));
      if (*(uint *)((uint)bVar4 * 0x27 + 0x125) < uStack_e) {
        uVar7 = *(undefined2 *)(iVar11 + iVar14 * 2);
        *(undefined2 *)(iVar11 + iVar14 * 2) = *(undefined2 *)(iVar11 + iVar13 * 2);
        *(undefined2 *)(iVar11 + iVar13 * 2) = uVar7;
        puVar9 = (undefined2 *)(iVar12 + iVar14 * 4);
        uVar7 = puVar9[1];
        uVar1 = *puVar9;
        puVar9 = (undefined2 *)(iVar12 + iVar13 * 4);
        uVar2 = *puVar9;
        puVar10 = (undefined2 *)(iVar12 + iVar14 * 4);
        puVar10[1] = puVar9[1];
        *puVar10 = uVar2;
        puVar9 = (undefined2 *)(iVar12 + iVar13 * 4);
        puVar9[1] = uVar7;
        *puVar9 = uVar1;
        bVar4 = bldng_676c_05ac(CONCAT11((char)((uint)(iVar13 * 2) >> 8),
                                         *(undefined1 *)(iVar11 + iVar13 * 2)));
        uStack_e = *(uint *)((uint)bVar4 * 0x27 + 0x125);
      }
    }
    iVar13 = iVar13 + 1;
  }
  iVar13 = 0;
  do {
    if (param_3 <= iVar13) {
      return;
    }
    bVar4 = bldng_676c_05ac(CONCAT11((char)((uint)(iVar13 * 2) >> 8),
                                     *(undefined1 *)(iVar11 + iVar13 * 2)));
    uVar3 = *(uint *)((uint)bVar4 * 0x27 + 0x125);
    puVar9 = (undefined2 *)(iVar12 + iVar13 * 4);
    puVar8 = (undefined1 *)*puVar9;
    uStack_c = (undefined1 *)CONCAT22(puVar9[1],puVar8);
    puVar17 = (undefined1 *)0x0;
    uVar6 = ovr_OVC45_77eb_09c1(param_4);
    if (((int)puVar8 < (int)puVar17) || ((puVar17 == puVar8 && (uVar6 < uVar3)))) {
LAB_676c_037f:
      *uStack_c = 0x25;
    }
    else {
      uVar7 = bldng_676c_05ac(CONCAT11((char)((uint)(iVar13 * 2) >> 8),
                                       *(undefined1 *)(iVar11 + iVar13 * 2)),param_4);
      cVar5 = bldng_676c_003d(uVar7);
      if (cVar5 == '\0') goto LAB_676c_037f;
      *uStack_c = 0x40;
    }
    iVar13 = iVar13 + 1;
  } while( true );
}



/* 676c:0393 */

undefined2 __cdecl16far bldng_676c_0393(undefined1 param_1,char param_2)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  
  bVar1 = bldng_676c_05ac(param_1);
  if (*(char *)((uint)bVar1 * 0x27 + 0x133) == '\x17') {
    cVar2 = ovr_manage_4d05_1b1d();
    if (cVar2 == param_2) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* 676c:03dd */

void __cdecl16far bldng_676c_03dd(byte param_1)

{
  uint16_t uVar1;
  undefined4 uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  uint16_t *puVar6;
  undefined1 uVar7;
  undefined2 unaff_SS;
  uint local_1f4 [49];
  uint16_t local_192 [98];
  char acStack_ce [200];
  uint uStack_6;
  byte bStack_4;
  byte bStack_3;
  
  iVar5 = (uint)*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3e) * 0x95;
  bStack_3 = '\x01' << (*(byte *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + iVar5) & 0x1f);
  bVar3 = bldng_676c_0000(CONCAT11((char)((uint)iVar5 >> 8),param_1));
  local_1f4[0] = (uint)bVar3;
  local_192[1] = *(undefined2 *)((int)&GStrangeTable[0x31].seg + local_1f4[0] * 4);
  local_192[0] = ((far_t *)(GStrangeTable + 0x31) + local_1f4[0])->ofs;
  puVar6 = local_192;
  iVar5 = 1;
  uStack_6 = 7;
  while( true ) {
    uVar7 = (undefined1)((uint)puVar6 >> 8);
    if (0x30 < (int)uStack_6) break;
    bVar3 = bldng_676c_05ac(uStack_6 & 0xff);
    puVar6 = (uint16_t *)((uint)bVar3 * 0x27);
    if ((*(byte *)((int)puVar6 + 0x11f) & bStack_3) != 0) {
      bVar3 = bldng_676c_05ac(CONCAT11(uVar7,(undefined1)uStack_6));
      puVar6 = (uint16_t *)((uint)bVar3 * 0x27);
      if (*(char *)((int)puVar6 + 0x12d) == '\0') {
        cVar4 = bldng_676c_0393(uStack_6,param_1);
        if (cVar4 != '\0') {
          local_1f4[iVar5] = uStack_6;
          puVar6 = local_192 + iVar5 * 2;
          uVar1 = ((far_t *)(GStrangeTable + 0x31) + uStack_6)->ofs;
          local_192[iVar5 * 2 + 1] = *(uint16_t *)((int)&GStrangeTable[0x31].seg + uStack_6 * 4);
          *puVar6 = uVar1;
          iVar5 = iVar5 + 1;
        }
      }
    }
    uStack_6 = uStack_6 + 1;
  }
  bldng_676c_01b0(local_1f4);
  uVar2 = *(undefined4 *)((uint)param_1 << 2);
  bVar3 = bldng_676c_05ac(CONCAT11((char)(((uint)param_1 << 2) >> 8),
                                   *(undefined1 *)((int)uVar2 + 0x85)));
  ovr_stsprintf(acStack_ce,"Building is now %s.  Select type of building.",
                (char *)*(undefined2 *)((uint)bVar3 * 0x27 + 0x10e));
  bStack_4 = ovr_OVC28_6018_1527(local_192);
  if (bStack_4 != 0) {
    *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x85) = (char)local_1f4[bStack_4 - 1]
    ;
  }
  return;
}



/* 676c:05ac */

undefined2 __cdecl16far bldng_676c_05ac(byte param_1)

{
  return CONCAT11((char)((uint)param_1 * 4 >> 8),
                  *(undefined1 *)(((far_t *)GStrangeTable)[param_1].ofs + 1));
}



/* 676c:05c3 */

undefined2 __cdecl16far bldng_676c_05c3(byte param_1)

{
  uint16_t uVar1;
  int iVar2;
  
  uVar1 = ovr_randBelow((uint)*(byte *)((far_t *)GStrangeTable)[param_1]);
  iVar2 = (uVar1 & 0xff) + ((far_t *)GStrangeTable + param_1)->ofs;
  return CONCAT11((char)((uint)iVar2 >> 8),*(undefined1 *)(iVar2 + 1));
}


