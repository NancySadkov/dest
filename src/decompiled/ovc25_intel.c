/*
 * ovc25_intel.c - recovered from STRONG.EXE
 * memory block: OVC25_intel.c
 * range: 5b66:0000 - 5b66:1def
 * functions: 19
 */
#include "recovered.h"


/* 5b66:0000 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

uint __cdecl16far
ovc25_usesAlignUp4(char partyIndex,uint16_t x,uint16_t y,uint16_t destX,uint16_t destY)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined2 uVar6;
  
  uVar1 = ovr_alignUp4(destX);
  uVar2 = ovr_alignUp4(x);
  uVar5 = 0;
  do {
    if (EntityCount <= uVar5) {
      return 0xffff;
    }
    uVar6 = (undefined2)((ulong)Entities >> 0x10);
    iVar4 = (int)Entities;
    if ((*(char *)(iVar4 + uVar5 * 0x37 + 0x1a) == partyIndex) &&
       ((*(byte *)(iVar4 + uVar5 * 0x37 + 0x33) & 2) == 0)) {
      uVar3 = ovr_alignUp4(*(int *)(iVar4 + uVar5 * 0x37));
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      if ((uVar3 == uVar2) && (*(uint16_t *)((int)Entities + uVar5 * 0x37 + 2) == y)) {
        return uVar5;
      }
      uVar3 = ovr_alignUp4(*(int *)((int)Entities + uVar5 * 0x37 + 8));
      if (uVar3 != uVar1) {
        return uVar5;
      }
      if (*(uint16_t *)((int)Entities + uVar5 * 0x37 + 10) != destY) {
        return uVar5;
      }
    }
    uVar5 = uVar5 + 1;
  } while( true );
}



/* 5b66:00ff */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

undefined2 __cdecl16far
ovc25_usesAlignUp42(char partyIndex,byte count,uint16_t destX,uint16_t destY,uint16_t x,uint16_t y)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  int iStack_4;
  
  uVar4 = 0;
  do {
    if (EntityCount <= uVar4) {
      if (count != 0) {
        iStack_4 = 0;
        while ((iStack_4 < (int)(uint)count &&
               (uVar4 = ovc25_usesAlignUp4(partyIndex,x,y,destX,destY), -1 < (int)uVar4))) {
          *(undefined1 *)((int)Entities + uVar4 * 0x37 + 0x30) = 0;
          *(uint16_t *)((int)Entities + uVar4 * 0x37 + 8) = destX;
          *(uint16_t *)((int)Entities + uVar4 * 0x37 + 10) = destY;
          pbVar1 = (byte *)((int)Entities + uVar4 * 0x37 + 0x33);
          *pbVar1 = *pbVar1 | 8;
          iStack_4 = iStack_4 + 1;
        }
      }
      return 0xffff;
    }
    uVar5 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)Entities + uVar4 * 0x37 + 0x1a) == partyIndex) {
      uVar2 = ovr_alignUp4(*(int *)((int)Entities + uVar4 * 0x37));
      uVar3 = ovr_alignUp4(destX);
      uVar5 = (undefined2)((ulong)Entities >> 0x10);
      if ((uVar2 != uVar3) || (*(uint16_t *)((int)Entities + uVar4 * 0x37 + 2) != destY)) {
        uVar2 = ovr_alignUp4(*(int *)((int)Entities + uVar4 * 0x37 + 8));
        uVar3 = ovr_alignUp4(destX);
        if ((uVar2 != uVar3) || (*(uint16_t *)((int)Entities + uVar4 * 0x37 + 10) != destY))
        goto L_OVC25_5b66_00ff_01D9;
      }
      pbVar1 = (byte *)((int)Entities + uVar4 * 0x37 + 0x33);
      *pbVar1 = *pbVar1 | 8;
    }
L_OVC25_5b66_00ff_01D9:
    uVar4 = uVar4 + 1;
  } while( true );
}



/* 5b66:028d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R2] string "arena" */

bool __cdecl16far ovc25_textArena(uint *foundIndexOut,char includeFlag8,uint16_t partyIndex,int x)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined2 uVar8;
  int in_stack_0000000e;
  uint uStack_4;
  
  uStack_4 = 0xffff;
  uVar1 = ovr_alignUp4(x);
  for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)Entities + uVar7 * 0x37 + 0x1a) == (char)partyIndex) {
      uVar2 = ovr_alignUp4(*(int *)((int)Entities + uVar7 * 0x37));
      uVar4 = (int)(uVar2 - uVar1) >> 0xf;
      uVar8 = (undefined2)((ulong)Entities >> 0x10);
      iVar6 = (int)Entities;
      uVar3 = *(int *)(iVar6 + uVar7 * 0x37 + 2) - in_stack_0000000e;
      uVar5 = (int)uVar3 >> 0xf;
      uVar2 = ((uVar2 - uVar1 ^ uVar4) - uVar4) + ((uVar3 ^ uVar5) - uVar5) * 2;
      if ((((uVar2 != 0) && (uVar2 < uStack_4)) &&
          ((*(byte *)(iVar6 + uVar7 * 0x37 + 0x33) & 2) == 0)) &&
         ((includeFlag8 != '\0' || ((*(byte *)(iVar6 + uVar7 * 0x37 + 0x33) & 8) == 0)))) {
        *foundIndexOut = uVar7;
        uStack_4 = uVar2;
      }
    }
  }
  return uStack_4 != 0xffff;
}



/* 5b66:038d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

void __cdecl16far
ovc25_usesAlignUp43(char partyIndex,byte count,uint16_t destX,uint16_t destY,char setFlag8)

{
  byte *pbVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  uint8_t entityIndex;
  
  if (count != 0) {
    iVar5 = 0;
    for (entityIndex = 0; entityIndex < EntityCount; entityIndex = entityIndex + 1) {
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      if (*(char *)((int)Entities + entityIndex * 0x37 + 0x1a) == partyIndex) {
        uVar3 = ovr_alignUp4(*(int *)((int)Entities + entityIndex * 0x37));
        uVar4 = ovr_alignUp4(destX);
        uVar6 = (undefined2)((ulong)Entities >> 0x10);
        if ((uVar3 != uVar4) || (*(uint16_t *)((int)Entities + entityIndex * 0x37 + 2) != destY))
        {
          uVar3 = ovr_alignUp4(*(int *)((int)Entities + entityIndex * 0x37 + 8));
          uVar4 = ovr_alignUp4(destX);
          if ((uVar3 != uVar4) ||
             (*(uint16_t *)((int)Entities + entityIndex * 0x37 + 10) != destY))
          goto L_OVC25_5b66_038d_0482;
        }
        iVar5 = iVar5 + 1;
        if (setFlag8 != '\0') {
          pbVar1 = (byte *)((int)Entities + entityIndex * 0x37 + 0x33);
          *pbVar1 = *pbVar1 | 8;
        }
      }
L_OVC25_5b66_038d_0482:
    }
    while ((iVar5 < (int)(uint)count &&
           (bVar2 = ovc25_textArena((uint *)CONCAT22(unaff_SS,&entityIndex),setFlag8,
                                    (uint)(byte)partyIndex,destX), bVar2))) {
      *(undefined1 *)((int)Entities + entityIndex * 0x37 + 0x30) = 0;
      *(uint16_t *)((int)Entities + entityIndex * 0x37 + 8) = destX;
      *(uint16_t *)((int)Entities + entityIndex * 0x37 + 10) = destY;
      if (setFlag8 != '\0') {
        pbVar1 = (byte *)((int)Entities + entityIndex * 0x37 + 0x33);
        *pbVar1 = *pbVar1 | 8;
      }
      iVar5 = iVar5 + 1;
    }
  }
  return;
}



/* 5b66:0530 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

void __cdecl16far ovc25_usesAlignUp44(char partyIndex,byte count,uint16_t destX,uint16_t destY,...)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  uint8_t entityIndex;
  
  if (count != 0) {
    iVar4 = 0;
    for (entityIndex = 0; entityIndex < EntityCount; entityIndex = entityIndex + 1) {
      uVar5 = (undefined2)((ulong)Entities >> 0x10);
      if (*(char *)((int)Entities + entityIndex * 0x37 + 0x1a) == partyIndex) {
        uVar2 = ovr_alignUp4(*(int *)((int)Entities + entityIndex * 0x37 + 8));
        uVar3 = ovr_alignUp4(destX);
        if ((uVar2 == uVar3) && (*(uint16_t *)((int)Entities + entityIndex * 0x37 + 10) == destY))
        {
          iVar4 = iVar4 + 1;
        }
      }
    }
    while ((iVar4 < (int)(uint)count &&
           (bVar1 = ovc25_textArena((uint *)CONCAT22(unaff_SS,&entityIndex),'\x02',
                                    (uint)(byte)partyIndex,destX), bVar1))) {
      *(undefined1 *)((int)Entities + entityIndex * 0x37 + 0x30) = 0;
      *(uint16_t *)((int)Entities + entityIndex * 0x37 + 8) = destX;
      *(uint16_t *)((int)Entities + entityIndex * 0x37 + 10) = destY;
      iVar4 = iVar4 + 1;
    }
    while ((iVar4 < (int)(uint)count &&
           (bVar1 = ovc25_textArena((uint *)CONCAT22(unaff_SS,&entityIndex),'\x01',
                                    (uint)(byte)partyIndex,destX), bVar1))) {
      *(undefined1 *)((int)Entities + entityIndex * 0x37 + 0x30) = 0;
      *(uint16_t *)((int)Entities + entityIndex * 0x37 + 8) = destX;
      *(uint16_t *)((int)Entities + entityIndex * 0x37 + 10) = destY;
      iVar4 = iVar4 + 1;
    }
    while ((iVar4 < (int)(uint)count &&
           (bVar1 = ovc25_textArena((uint *)CONCAT22(unaff_SS,&entityIndex),'\0',
                                    (uint)(byte)partyIndex,destX), bVar1))) {
      *(undefined1 *)((int)Entities + entityIndex * 0x37 + 0x30) = 0;
      *(uint16_t *)((int)Entities + entityIndex * 0x37 + 8) = destX;
      *(uint16_t *)((int)Entities + entityIndex * 0x37 + 10) = destY;
      iVar4 = iVar4 + 1;
    }
  }
  return;
}



/* 5b66:0722 */

/* Searches square rings out to 99 cells for a cell occupied by a unit (attact_usesGUnits), writing
   the found coordinates through the two pointers. */

uint __cdecl16far ovc25_findUnitCell(int *x,uint *y)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *in_stack_00000004;
  char cStack_a;
  byte bStack_9;
  uint uStack_8;
  
  iVar1 = *(int *)CONCAT22((int *)x,in_stack_00000004);
  uVar2 = *(uint *)CONCAT22((uint *)y,(*(uint16_t *)((uint8_t *)&(x) + 2)));
  uStack_8 = 0;
  uVar4 = uVar2;
  do {
    if (99 < uStack_8) {
      return uVar4 & 0xff00;
    }
    for (uVar6 = 0; uVar6 <= uStack_8; uVar6 = uVar6 + 1) {
      for (uVar5 = 0; uVar5 <= uStack_8; uVar5 = uVar5 + 1) {
        bStack_9 = 0xff;
        while ((0x7f < bStack_9 || ((uVar6 != 0 && ((char)bStack_9 < '\x02'))))) {
          cStack_a = -1;
          while ((cStack_a < '\0' || ((uVar5 != 0 && (cStack_a < '\x02'))))) {
            uVar3 = ovr_attact_usesGUnits
                              (iVar1 + uVar6 * (int)cStack_a,uVar2 + uVar5 * (int)cStack_a);
            if ((char)uVar3 != '\0') {
              *(uint *)CONCAT22((int *)x,in_stack_00000004) = iVar1 + uVar6 * (int)cStack_a;
              *(uint *)CONCAT22((uint *)y,(*(uint16_t *)((uint8_t *)&(x) + 2))) = uVar2 + uVar5 * (int)cStack_a;
              return CONCAT11((char)(uVar5 * (int)cStack_a >> 8),1);
            }
            cStack_a = cStack_a + '\x02';
            uVar4 = CONCAT11((char)((uint)uVar3 >> 8),cStack_a);
          }
          bStack_9 = bStack_9 + 2;
          uVar4 = CONCAT11((char)(uVar4 >> 8),bStack_9);
        }
      }
    }
    uStack_8 = uStack_8 + 1;
  } while( true );
}



/* 5b66:080f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches EntityCount, Entities */

void __cdecl16far ovc25_usesEntityCount(char partyIndex)

{
  byte *pbVar1;
  uint uVar2;
  undefined2 uVar3;
  
  for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
    uVar3 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)Entities + uVar2 * 0x37 + 0x1a) == partyIndex) {
      pbVar1 = (byte *)((int)Entities + uVar2 * 0x37 + 0x33);
      *pbVar1 = *pbVar1 & 0xf7;
    }
  }
  return;
}



/* 5b66:085d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Emits the spy report for a party heading towards a stronghold. */

void __cdecl16far ovc25_spyReportNotice(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  char *msg;
  uint16_t uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint unaff_DI;
  undefined2 uVar8;
  char *unaff_SS;
  uint8_t text;
  byte bStack_17;
  undefined1 uStack_16;
  byte bStack_15;
  uint uStack_14;
  uint uStack_12;
  uint uStack_10;
  uint uStack_e;
  uint uStack_c;
  uint uStack_a;
  uint16_t uStack_8;
  uint16_t uStack_6;
  int iStack_4;
  
  for (uStack_a = 0; (int)uStack_a < (int)(uint)GLeaderCount; uStack_a = uStack_a + 1) {
    if (*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x3d) != '\0') {
      *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x47) = 0;
      *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x41) = 0;
      *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x43) = 0;
      *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x45) = 0;
      uStack_e = 0xffff;
      unaff_DI = 0xffff;
      uStack_12 = ovr_alignUp4(*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39));
      for (uStack_c = 0; uStack_c < EntityCount; uStack_c = uStack_c + 1) {
        uVar8 = (undefined2)((ulong)Entities >> 0x10);
        iVar7 = (int)Entities;
        if (*(byte *)(iVar7 + uStack_c * 0x37 + 0x1a) == uStack_a) {
          uVar2 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                  *(int *)(iVar7 + uStack_c * 0x37);
          uVar5 = (int)uVar2 >> 0xf;
          uVar3 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) -
                  *(int *)(iVar7 + uStack_c * 0x37 + 2);
          uVar6 = (int)uVar3 >> 0xf;
          piVar1 = (int *)((int)*(undefined4 *)(uStack_a << 2) + 0x45);
          *piVar1 = *piVar1 + 1;
          if ((int)((uVar2 ^ uVar5) - uVar5) / 2 + ((uVar3 ^ uVar6) - uVar6) < 10) {
            piVar1 = (int *)((int)*(undefined4 *)(uStack_a << 2) + 0x41);
            *piVar1 = *piVar1 + 1;
            uVar8 = (undefined2)((ulong)Entities >> 0x10);
            if ((*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) ==
                 *(int *)((int)Entities + uStack_c * 0x37 + 2)) &&
               (uVar2 = ovr_alignUp4(*(int *)((int)Entities + uStack_c * 0x37)), uVar2 == uStack_12
               )) {
              piVar1 = (int *)((int)*(undefined4 *)(uStack_a << 2) + 0x47);
              *piVar1 = *piVar1 + 1;
            }
          }
        }
        else if (*(char *)((int)(char **)GMenuStrings +
                          (uint)*(byte *)(iVar7 + uStack_c * 0x37 + 0xd) * 0x95 + 0x1f) !=
                 *(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x3f)) {
          uVar2 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                  *(int *)(iVar7 + uStack_c * 0x37);
          uVar5 = (int)uVar2 >> 0xf;
          uVar3 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) -
                  *(int *)(iVar7 + uStack_c * 0x37 + 2);
          uVar6 = (int)uVar3 >> 0xf;
          uVar2 = (int)((uVar2 ^ uVar5) - uVar5) / 2 + ((uVar3 ^ uVar6) - uVar6);
          if (uVar2 < uStack_e) {
            unaff_DI = uStack_c;
            uStack_e = uVar2;
          }
          if (uVar2 < 10) {
            piVar1 = (int *)((int)*(undefined4 *)(uStack_a << 2) + 0x43);
            *piVar1 = *piVar1 + 1;
          }
        }
      }
      *(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x4b) = unaff_DI;
      uStack_16 = 0xff;
      if (*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x40) != '\0') {
        uStack_10 = 0xffff;
        for (uStack_c = 0; (int)uStack_c < (int)(uint)GLeaderCount; uStack_c = uStack_c + 1) {
          if ((*(char *)((int)*(undefined4 *)(uStack_c << 2) + 0x3f) !=
               *(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x3f)) &&
             (uVar2 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                      *(int *)((int)*(undefined4 *)(uStack_c << 2) + 0x39),
             uVar5 = (int)uVar2 >> 0xf,
             uVar3 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) -
                     *(int *)((int)*(undefined4 *)(uStack_c << 2) + 0x3b), uVar6 = (int)uVar3 >> 0xf
             , uVar2 = (int)((uVar2 ^ uVar5) - uVar5) / 2 + ((uVar3 ^ uVar6) - uVar6),
             uVar2 < uStack_10)) {
            uStack_16 = (undefined1)uStack_c;
            uStack_10 = uVar2;
          }
        }
      }
      *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x49) = uStack_16;
    }
  }
  for (uStack_a = 0; (int)uStack_a < (int)(uint)GLeaderCount; uStack_a = uStack_a + 1) {
    if ((*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x40) != '\0') &&
       (*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x3d) != '\0')) {
      ovc25_intelAttackingNotice((byte)uStack_a);
      if (*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x4b) == -1) {
        uStack_14 = 0xffff;
      }
      else {
        unaff_DI = *(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x4b);
        uVar8 = (undefined2)((ulong)Entities >> 0x10);
        uVar2 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                *(int *)((int)Entities + unaff_DI * 0x37);
        uVar5 = (int)uVar2 >> 0xf;
        uVar3 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) -
                *(int *)((int)Entities + unaff_DI * 0x37 + 2);
        uVar6 = (int)uVar3 >> 0xf;
        uStack_14 = (int)((uVar2 ^ uVar5) - uVar5) / 2 + ((uVar3 ^ uVar6) - uVar6);
      }
      if ((*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x43) == 0) || (9 < uStack_14)) {
        if ((*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x49) == -1) ||
           ((*(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x5d) & 1) == 0)) {
          if (*(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x47) < 10) {
            ovc25_usesAlignUp43((byte)uStack_a,10,
                                *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                                *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b),'\0');
            *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 0;
          }
          else {
            *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 0;
            bStack_17 = *(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x3e);
            iStack_4 = ovc25_compute1(bStack_17);
            if ((int)(uint)PlayerCount < iStack_4) {
              uVar4 = ovr_randBelow(0x28);
              uStack_6 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) + -0x14 +
                         (uVar4 & 0xff);
              if ((int)uStack_6 < 4) {
                uStack_6 = 4;
              }
              if (0x8c < (int)uStack_6) {
                uStack_6 = 0x8b;
              }
              uVar4 = ovr_randBelow(0x14);
              uStack_8 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) + -10 + (uVar4 & 0xff)
              ;
              if ((int)uStack_8 < 1) {
                uStack_8 = 1;
              }
              if (0x3a < (int)uStack_8) {
                uStack_8 = 0x3a;
              }
              ovc25_usesAlignUp44((char)uStack_a,1,uStack_6,uStack_8);
            }
          }
        }
        else {
          ovc25_usesEntityCount((byte)uStack_a);
          bStack_15 = *(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x49);
          if (0xe < *(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x47)) {
            ovc25_usesAlignUp42((byte)uStack_a,10,
                                *(uint16_t *)((int)*(undefined4 *)((uint)bStack_15 << 2) + 0x39),
                                *(uint16_t *)((int)*(undefined4 *)((uint)bStack_15 << 2) + 0x3b),
                                *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                                *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b));
            if (*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) != '\x02') {
              uVar2 = ovr_alignUp4(*(int *)((int)*(undefined4 *)((uint)bStack_15 << 2) + 0x39),
                                   *(undefined2 *)
                                    ((int)*(undefined4 *)((uint)bStack_15 << 2) + 0x3b),0xa000);
              iVar7 = (uint)*(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x3e) * 0x95;
              uVar4 = 0x195d;
              msg = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x58c0,unaff_SS),
                                  (char *)CONCAT22(*(undefined2 *)
                                                    ((int)&worldMenuLabels[0].seg + 1 + iVar7),
                                                   (char *)"puppetmaker" + 3),
                                  *(undefined2 *)((int)&worldMenuLabels[1].ofs + 1 + iVar7),uVar2);
              ovr_uiNotify(msg,uVar4);
            }
          }
          ovc25_usesAlignUp43((byte)uStack_a,0xf,
                              *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                              *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b),'\0');
          *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 2;
        }
      }
      else {
        ovc25_usesEntityCount((byte)uStack_a);
        if (9 < *(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x47)) {
          uVar8 = (undefined2)((ulong)Entities >> 0x10);
          ovc25_usesAlignUp43((byte)uStack_a,5,*(uint16_t *)((int)Entities + unaff_DI * 0x37),
                              *(uint16_t *)((int)Entities + unaff_DI * 0x37 + 2),'\x01');
        }
        ovc25_usesAlignUp43((byte)uStack_a,10,
                            *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                            *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b),'\0');
        *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 1;
      }
    }
  }
  ovc25_clearEntityFlags();
  return;
}



/* 5b66:112d */

/* Returns whether a building stands within two columns of (x,y). */

uint __cdecl16far ovc25_hasBuildingNear(uint16_t x,int y)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = ovr_alignUp4(x);
  uVar4 = uVar3 + 3;
  if (((((int)uVar4 < 0x94) && (-1 < (int)uVar3)) && (y < 0x3c)) && (-1 < y)) {
    for (iVar5 = -2; iVar5 < 2; iVar5 = iVar5 + 1) {
      iVar2 = (*(short (*) [148] [60])GUnitGrid)[uVar3 + iVar5][y];
      bVar1 = ((unit_t *)GUnits + iVar2)->bldType;
      uVar4 = CONCAT11((char)((uint)(iVar2 * 9) >> 8),bVar1);
      if ((bVar1 < 0xf8) && (uVar4 = (uint)bVar1 * 0x27, *(char *)(uVar4 + 0x11a) != '\0')) {
        return CONCAT11((char)(uVar4 >> 8),1);
      }
    }
  }
  return uVar4 & 0xff00;
}



/* 5b66:11cb */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

int __cdecl16far ovc25_usesAlignUp46(uint16_t x,uint16_t y,char excluded,uint8_t *foundFlag)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined1 *in_stack_0000000a;
  int iStack_4;
  
  uVar1 = ovr_alignUp4(x);
  iStack_4 = 0;
  *(undefined1 *)CONCAT22((uint8_t *)foundFlag,in_stack_0000000a) = 0;
  uVar3 = 0;
  do {
    if (EntityCount <= uVar3) {
      return iStack_4;
    }
    uVar4 = (undefined2)((ulong)Entities >> 0x10);
    if ((((*(byte *)((int)Entities + uVar3 * 0x37 + 0x33) & 2) != 0) &&
        (uVar2 = ovr_alignUp4(*(int *)((int)Entities + uVar3 * 0x37 + 4)), uVar2 == uVar1)) &&
       (*(uint16_t *)((int)Entities + uVar3 * 0x37 + 6) == y)) {
      *(undefined1 *)CONCAT22((uint8_t *)foundFlag,in_stack_0000000a) = 1;
    }
    uVar2 = ovr_alignUp4(*(int *)((int)Entities + uVar3 * 0x37));
    if (uVar2 == uVar1) {
      uVar4 = (undefined2)((ulong)Entities >> 0x10);
      if (*(uint16_t *)((int)Entities + uVar3 * 0x37 + 2) == y) {
        if (*(char *)((int)(char **)GMenuStrings +
                     (uint)*(byte *)((int)Entities + uVar3 * 0x37 + 0xd) * 0x95 + 0x1f) != excluded
           ) {
          return 0xff;
        }
        iStack_4 = iStack_4 + 1;
      }
    }
    uVar3 = uVar3 + 1;
  } while( true );
}



/* 5b66:12de */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Clears the per-entity byte at base.entity+2 and rebuilds the derived table when entities exist.
    */

void __cdecl16far ovc25_clearEntityFlags(void)

{
  undefined2 uStack_6;
  
  for (uStack_6 = 0; uStack_6 < EntityCount; uStack_6 = uStack_6 + 1) {
    *(undefined1 *)((int)Entities + uStack_6 * 0x37 + 0x19) = 0;
  }
  if (EntityCount != 0) {
    ovc25_usesAlignUp47();
    return;
  }
  return;
}



/* 5b66:131f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* [R4] calls ovr_alignUp4 */

void ovc25_usesAlignUp47(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint16_t uVar4;
  int iVar5;
  int unaff_BP;
  uint uVar6;
  undefined2 uVar7;
  uint8_t *unaff_SS;
  undefined2 in_stack_00000000;
  
  uVar7 = (undefined2)((ulong)Entities >> 0x10);
  if (*(char *)((int)Entities + *(int *)(unaff_BP + -4) * 0x37 + 0x19) != '\0') {
    OVC25_5b66_131f_entry();
    return;
  }
  *(undefined1 *)((int)Entities + *(int *)(unaff_BP + -4) * 0x37 + 0x19) = 1;
  *(undefined1 *)(unaff_BP + -0xc) =
       *(undefined1 *)((int)Entities + *(int *)(unaff_BP + -4) * 0x37 + 0x1a);
  *(undefined1 *)(unaff_BP + -0xb) =
       *(undefined1 *)((int)Entities + *(int *)(unaff_BP + -4) * 0x37 + 0xd);
  *(undefined1 *)(unaff_BP + -0xd) =
       *(undefined1 *)((int)(char **)GMenuStrings + (uint)*(byte *)(unaff_BP + -0xb) * 0x95 + 0x1f);
  uVar7 = (undefined2)((ulong)Entities >> 0x10);
  if ((*(char *)((int)Entities + *(int *)(unaff_BP + -4) * 0x37 + 0x18) != '\0') ||
     (*(char *)(unaff_BP + -0xd) != '\0')) {
    if (*(char *)(unaff_BP + -0xd) == '\0') {
      OVC25_5b66_131f_entry();
      return;
    }
    uVar1 = *(undefined4 *)((uint)*(byte *)(unaff_BP + -0xc) << 2);
    if (*(char *)((int)uVar1 + 0x4a) != '\0') {
      OVC25_5b66_131f_entry();
      return;
    }
  }
  uVar2 = ovr_alignUp4(*(int *)((int)Entities + *(int *)(unaff_BP + -4) * 0x37));
  *(uint *)(unaff_BP + -6) = uVar2;
  uVar7 = (undefined2)((ulong)Entities >> 0x10);
  iVar5 = (int)Entities;
  if (((*(int *)(iVar5 + *(int *)(unaff_BP + -4) * 0x37 + 8) == 0) &&
      (*(int *)(iVar5 + *(int *)(unaff_BP + -4) * 0x37 + 10) == 0)) &&
     ((*(byte *)(iVar5 + *(int *)(unaff_BP + -4) * 0x37 + 0x33) & 3) == 0)) {
    uVar2 = *(uint *)(unaff_BP + -4);
  }
  else {
    uVar2 = 0xffff;
  }
  *(undefined2 *)(unaff_BP + -0x10) = 1;
  uVar6 = *(uint *)(unaff_BP + -4);
  while (uVar6 = uVar6 + 1, uVar6 < EntityCount) {
    uVar3 = ovr_alignUp4(*(int *)((int)Entities + uVar6 * 0x37));
    if (uVar3 == *(uint *)(unaff_BP + -6)) {
      uVar7 = (undefined2)((ulong)Entities >> 0x10);
      iVar5 = (int)Entities;
      if (*(int *)(iVar5 + uVar6 * 0x37 + 2) == *(int *)(iVar5 + *(int *)(unaff_BP + -4) * 0x37 + 2)
         ) {
        *(undefined1 *)(iVar5 + uVar6 * 0x37 + 0x19) = 1;
        uVar7 = (undefined2)((ulong)Entities >> 0x10);
        iVar5 = (int)Entities;
        if (((*(int *)(iVar5 + uVar6 * 0x37 + 8) == 0) && (*(int *)(iVar5 + uVar6 * 0x37 + 10) == 0)
            ) && ((*(char *)(iVar5 + uVar6 * 0x37 + 0x18) == '\0' &&
                  ((*(char *)((int)(char **)GMenuStrings +
                             (uint)*(byte *)(iVar5 + uVar6 * 0x37 + 0xd) * 0x95 + 0x1f) ==
                    *(char *)(unaff_BP + -0xd) &&
                   (*(int *)(unaff_BP + -0x10) = *(int *)(unaff_BP + -0x10) + 1,
                   (*(byte *)((int)Entities + uVar6 * 0x37 + 0x33) & 3) == 0)))))) {
          uVar2 = uVar6;
        }
      }
    }
  }
  if (uVar2 == 0xffff) {
    OVC25_5b66_131f_entry();
    return;
  }
  if (*(uint *)(unaff_BP + -0x10) < 2) {
    OVC25_5b66_131f_entry();
    return;
  }
  uVar4 = ovr_randBelow(4);
  *(undefined1 *)(unaff_BP + -9) = (char)uVar4;
  *(undefined1 *)(unaff_BP + -10) = *(undefined1 *)(unaff_BP + -9);
  uVar6 = ovr_alignUp4(*(int *)((int)Entities + uVar2 * 0x37) +
                       *(char *)(*(byte *)(unaff_BP + -9) + 0x885) * 4);
  *(uint *)(unaff_BP + -6) = uVar6;
  *(int *)(unaff_BP + -8) =
       *(int *)((int)Entities + uVar2 * 0x37 + 2) +
       (int)*(char *)(*(byte *)(unaff_BP + -9) + 0x889);
  uVar7 = ovr_attact_usesGUnits(*(int *)(unaff_BP + -6),*(int *)(unaff_BP + -8));
  if ((char)uVar7 != '\0') {
    iVar5 = ovc25_usesAlignUp46(*(uint16_t *)(unaff_BP + -6),*(uint16_t *)(unaff_BP + -8),
                                *(char *)(unaff_BP + -0xd),
                                (uint8_t *)CONCAT22(in_stack_00000000,unaff_SS));
    *(int *)(unaff_BP + -2) = iVar5;
    if (*(uint *)(unaff_BP + -0x10) <= *(uint *)(unaff_BP + -2)) {
      OVC25_5b66_131f_entry();
      return;
    }
    *(undefined2 *)((int)Entities + uVar2 * 0x37 + 8) = *(undefined2 *)(unaff_BP + -6);
    *(undefined2 *)((int)Entities + uVar2 * 0x37 + 10) = *(undefined2 *)(unaff_BP + -8);
    if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
      *(undefined2 *)((int)Entities + uVar2 * 0x37 + 4) = *(undefined2 *)(unaff_BP + -6);
      *(undefined2 *)((int)Entities + uVar2 * 0x37 + 6) = *(undefined2 *)(unaff_BP + -8);
      *(undefined1 *)((int)Entities + uVar2 * 0x37 + 0x33) = 2;
      OVC25_5b66_131f_entry();
      return;
    }
    *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
    if (EntityCount <= *(uint *)(unaff_BP + -4)) {
      return;
    }
    ovc25_usesAlignUp47();
    return;
  }
  ovc25_usesAlignUp48();
  return;
}



/* 5b66:1667 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* [R6] touches Entities, destX */

void ovc25_usesEntities(void)

{
  undefined2 in_AX;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  
  *(undefined2 *)(unaff_BP + -2) = in_AX;
  if (*(uint *)(unaff_BP + -0x10) <= *(uint *)(unaff_BP + -2)) {
    OVC25_5b66_131f_entry();
    return;
  }
  *(undefined2 *)((int)Entities + unaff_DI * 0x37 + 8) = *(undefined2 *)(unaff_BP + -6);
  *(undefined2 *)((int)Entities + unaff_DI * 0x37 + 10) = *(undefined2 *)(unaff_BP + -8);
  if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
    *(undefined2 *)((int)Entities + unaff_DI * 0x37 + 4) = *(undefined2 *)(unaff_BP + -6);
    *(undefined2 *)((int)Entities + unaff_DI * 0x37 + 6) = *(undefined2 *)(unaff_BP + -8);
    *(undefined1 *)((int)Entities + unaff_DI * 0x37 + 0x33) = 2;
    OVC25_5b66_131f_entry();
    return;
  }
  *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
  if (*(uint *)(unaff_BP + -4) < EntityCount) {
    ovc25_usesAlignUp47();
    return;
  }
  return;
}



/* 5b66:170e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* [R4] calls ovr_alignUp4 */

void ovc25_usesAlignUp48(void)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  int unaff_BP;
  int unaff_DI;
  uint8_t *unaff_SS;
  undefined2 in_stack_00000000;
  
  *(byte *)(unaff_BP + -9) = *(char *)(unaff_BP + -9) + 1U & 3;
  if (*(char *)(unaff_BP + -9) != *(char *)(unaff_BP + -10)) {
    uVar1 = ovr_alignUp4(*(int *)((int)Entities + unaff_DI * 0x37) +
                         *(char *)(*(byte *)(unaff_BP + -9) + 0x885) * 4);
    *(uint *)(unaff_BP + -6) = uVar1;
    *(int *)(unaff_BP + -8) =
         *(int *)((int)Entities + unaff_DI * 0x37 + 2) +
         (int)*(char *)(*(byte *)(unaff_BP + -9) + 0x889);
    uVar2 = ovr_attact_usesGUnits(*(int *)(unaff_BP + -6),*(int *)(unaff_BP + -8));
    if ((char)uVar2 == '\0') {
      ovc25_usesAlignUp48();
      return;
    }
    iVar3 = ovc25_usesAlignUp46(*(uint16_t *)(unaff_BP + -6),*(uint16_t *)(unaff_BP + -8),
                                *(char *)(unaff_BP + -0xd),
                                (uint8_t *)CONCAT22(in_stack_00000000,unaff_SS));
    *(int *)(unaff_BP + -2) = iVar3;
    if (*(uint *)(unaff_BP + -0x10) <= *(uint *)(unaff_BP + -2)) {
      OVC25_5b66_131f_entry();
      return;
    }
    *(undefined2 *)((int)Entities + unaff_DI * 0x37 + 8) = *(undefined2 *)(unaff_BP + -6);
    *(undefined2 *)((int)Entities + unaff_DI * 0x37 + 10) = *(undefined2 *)(unaff_BP + -8);
    if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
      *(undefined2 *)((int)Entities + unaff_DI * 0x37 + 4) = *(undefined2 *)(unaff_BP + -6);
      *(undefined2 *)((int)Entities + unaff_DI * 0x37 + 6) = *(undefined2 *)(unaff_BP + -8);
      *(undefined1 *)((int)Entities + unaff_DI * 0x37 + 0x33) = 2;
      OVC25_5b66_131f_entry();
      return;
    }
  }
  *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
  if (*(uint *)(unaff_BP + -4) < EntityCount) {
    ovc25_usesAlignUp47();
    return;
  }
  return;
}



/* 5b66:1723 */

/* [R1] forwards to OVC25_5b66_131f */

void __cdecl16far OVC25_5b66_131f_entry(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
  if (*(uint *)(unaff_BP + -4) < EntityCount) {
    ovc25_usesAlignUp47();
    return;
  }
  return;
}



/* 5b66:173b */

/* Formats the "%s is attacking." notice. */

void __cdecl16far ovc25_attackingNotice(byte partyIndex,...)

{
  byte *pbVar1;
  uint16_t uVar2;
  uint8_t *puVar3;
  char *msg;
  uint uVar4;
  char *unaff_SS;
  uint8_t text;
  byte bStack_3;
  
  if (((partyIndex != 0xff) &&
      (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3f) != '\0')) &&
     (*(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5e) == 0)) {
    bStack_3 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3e);
    uVar4 = (uint)*(byte *)((int)&worldMenuLabels[8].seg + (uint)bStack_3 * 0x95) +
            (uint)*(byte *)((int)&worldMenuLabels[8].ofs + 1 + (uint)bStack_3 * 0x95) +
            (uint)*(byte *)((int)&worldMenuLabels[8].seg + 1 + (uint)bStack_3 * 0x95);
    if (((uVar4 < PlayerCount) &&
        ((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 1) == 0)) &&
       (uVar2 = ovr_randBelow(100), (int)(uVar2 & 0xff) < (int)(PlayerCount - uVar4))) {
      *(undefined2 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5e) = 0x19;
      ovr_play_sfx(82,0);
      uVar2 = 0x217a;
      puVar3 = ovr_ovc15_usesStshRealloc
                         ((char *)*(undefined2 *)((uint)partyIndex * 4),
                          ((undefined2 *)((uint)partyIndex * 4))[1],GSavedBlitSeg);
      msg = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x58f5,unaff_SS),
                          (char *)CONCAT22(puVar3,(char *)"puppetmaker" + 3),uVar2);
      ovr_uiNotify(msg,uVar2);
      pbVar1 = (byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d);
      *pbVar1 = *pbVar1 | 1;
    }
  }
  return;
}



/* 5b66:18cc */

/* [R7] body shape: compute */

int __cdecl16far ovc25_compute1(byte gindex,...)

{
  return (uint)*(byte *)((int)&worldMenuLabels[8].seg + (uint)gindex * 0x95) +
         (uint)*(byte *)((int)&worldMenuLabels[8].ofs + 1 + (uint)gindex * 0x95) +
         (uint)*(byte *)((int)&worldMenuLabels[8].seg + 1 + (uint)gindex * 0x95);
}



/* 5b66:1929 */

/* Emits the "Intelligence reports %s attacking." notice for a party. */

void __cdecl16far ovc25_intelAttackingNotice(byte partyIndex)

{
  byte *pbVar1;
  char cVar2;
  uint16_t uVar3;
  uint8_t *puVar4;
  char *msg;
  char *unaff_SS;
  uint8_t text;
  byte bStack_5;
  int iStack_4;
  
  iStack_4 = ovc25_compute1(*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x3e));
  if ((((((iStack_4 < (int)(uint)PlayerCount) &&
         (*(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5e) == 0)) &&
        (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x40) != '\0')) &&
       (((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 1) == 0 &&
        (9 < *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x45))))) &&
      ((*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x49) != -1 &&
       ((bStack_5 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x49),
        *(uint *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x45) < 0x50 ||
        (uVar3 = ovr_randBelow(0x28), (char)uVar3 == '\0')))))) &&
     (8 < *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x2a))) {
    if (*(uint *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x45) < 0x28) {
      if (*(uint *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x45) < 0x14) {
        return;
      }
      uVar3 = ovr_randBelow(0x78);
      cVar2 = (char)uVar3;
    }
    else {
      uVar3 = ovr_randBelow(0x50);
      cVar2 = (char)uVar3;
    }
    if (cVar2 == '\0') {
      ovr_play_sfx(82,0);
      *(undefined2 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5e) = 0x19;
      uVar3 = 0x217a;
      puVar4 = ovr_ovc15_usesStshRealloc
                         ((char *)*(undefined2 *)((uint)partyIndex * 4),
                          ((undefined2 *)((uint)partyIndex * 4))[1],GSavedBlitSeg);
      msg = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x5906,unaff_SS),
                          (char *)CONCAT22(puVar4,(char *)"puppetmaker" + 3),uVar3);
      ovr_uiNotify(msg,uVar3);
      pbVar1 = (byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d);
      *pbVar1 = *pbVar1 | 1;
    }
  }
  return;
}



/* 5b66:1b48 */

/* Ticks the party's +0x5e countdown; at zero it resets it to 10 and clears bit 0 of flags5d. */

void __cdecl16far ovc25_tickCountdown(int partyIndex,...)

{
  int *piVar1;
  byte *pbVar2;
  
  if ((((*(char *)((int)*(undefined4 *)(partyIndex << 2) + 0x3f) != '\0') &&
       (*(int *)((int)*(undefined4 *)(partyIndex << 2) + 0x5e) != 0)) &&
      (piVar1 = (int *)((int)*(undefined4 *)(partyIndex << 2) + 0x5e), *piVar1 = *piVar1 + -1,
      (*(byte *)((int)*(undefined4 *)(partyIndex << 2) + 0x5d) & 1) != 0)) &&
     (*(int *)((int)*(undefined4 *)(partyIndex << 2) + 0x5e) == 0)) {
    *(undefined2 *)((int)*(undefined4 *)(partyIndex << 2) + 0x5e) = 10;
    pbVar2 = (byte *)((int)*(undefined4 *)(partyIndex << 2) + 0x5d);
    *pbVar2 = *pbVar2 & 0xfe;
  }
  return;
}


