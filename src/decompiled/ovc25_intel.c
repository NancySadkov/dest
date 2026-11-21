/*
 * ovc25_intel.c - recovered from STRONG.EXE
 * memory block: OVC25_intel.c
 * range: 5b66:0000 - 5b66:1def
 * functions: 19
 */
#include "recovered.h"


/* 5b66:0000 */

/* [R4] calls ovr_alignUp4 */

uint __cdecl16far
ovc25_usesAlignUp4(char partyIndex,uint16_t x,uint16_t y,uint16_t destX,uint16_t destY)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  entity_t *peVar4;
  uint uVar5;
  int unaff_DI;
  undefined2 uVar6;
  
  uVar1 = ovr_alignUp4(unaff_DI,destX);
  uVar2 = ovr_alignUp4(unaff_DI,x);
  uVar5 = 0;
  do {
    if (EntityCount <= uVar5) {
      return 0xffff;
    }
    uVar6 = (undefined2)((ulong)Entities >> 0x10);
    peVar4 = (entity_t *)Entities;
    if ((*(char *)((int)&peVar4[uVar5].base.entity + 3) == partyIndex) &&
       ((*(byte *)((int)&peVar4[uVar5].base.flags32 + 1) & 2) == 0)) {
      uVar3 = ovr_alignUp4(unaff_DI,((peVar4 + uVar5)->base).x);
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      if ((uVar3 == uVar2) && (((entity_t *)Entities)[uVar5].base.y == y)) {
        return uVar5;
      }
      uVar3 = ovr_alignUp4(unaff_DI,((entity_t *)Entities)[uVar5].base.destX);
      if (uVar3 != uVar1) {
        return uVar5;
      }
      if (((entity_t *)Entities)[uVar5].base.destY != destY) {
        return uVar5;
      }
    }
    uVar5 = uVar5 + 1;
  } while( true );
}



/* 5b66:00ff */

/* [R4] calls ovr_alignUp4 */

undefined2 __cdecl16far
ovc25_usesAlignUp42(char partyIndex,byte count,uint16_t destX,uint16_t destY,uint16_t x,uint16_t y)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int unaff_DI;
  undefined2 uVar5;
  int iStack_4;
  
  uVar4 = 0;
  do {
    if (EntityCount <= uVar4) {
      if (count != 0) {
        iStack_4 = 0;
        while ((iStack_4 < (int)(uint)count &&
               (uVar4 = ovc25_usesAlignUp4(partyIndex,x,y,destX,destY), -1 < (int)uVar4))) {
          *(undefined1 *)&((entity_t *)Entities)[uVar4].base.state = 0;
          ((entity_t *)Entities)[uVar4].base.destX = destX;
          ((entity_t *)Entities)[uVar4].base.destY = destY;
          pbVar1 = (byte *)((int)&((entity_t *)Entities)[uVar4].base.flags32 + 1);
          *pbVar1 = *pbVar1 | 8;
          iStack_4 = iStack_4 + 1;
        }
      }
      return 0xffff;
    }
    uVar5 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)&((entity_t *)Entities)[uVar4].base.entity + 3) == partyIndex) {
      uVar2 = ovr_alignUp4(unaff_DI,(((entity_t *)Entities + uVar4)->base).x);
      uVar3 = ovr_alignUp4(uVar2,destX);
      uVar5 = (undefined2)((ulong)Entities >> 0x10);
      if ((uVar2 != uVar3) || (((entity_t *)Entities)[uVar4].base.y != destY)) {
        uVar2 = ovr_alignUp4(unaff_DI,((entity_t *)Entities)[uVar4].base.destX);
        uVar3 = ovr_alignUp4(uVar2,destX);
        if ((uVar2 != uVar3) || (((entity_t *)Entities)[uVar4].base.destY != destY))
        goto L_OVC25_5b66_00ff_01D9;
      }
      pbVar1 = (byte *)((int)&((entity_t *)Entities)[uVar4].base.flags32 + 1);
      *pbVar1 = *pbVar1 | 8;
    }
L_OVC25_5b66_00ff_01D9:
    uVar4 = uVar4 + 1;
  } while( true );
}



/* 5b66:028d */

/* [R2] string "arena" */

bool __cdecl16far ovc25_textArena(uint *foundIndexOut,char includeFlag8,uint16_t partyIndex,int x)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  entity_t *peVar6;
  uint uVar7;
  int unaff_DI;
  undefined2 uVar8;
  int in_stack_0000000e;
  uint uStack_4;
  
  uStack_4 = 0xffff;
  uVar1 = ovr_alignUp4(unaff_DI,x);
  for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)&((entity_t *)Entities)[uVar7].base.entity + 3) == (char)partyIndex) {
      uVar2 = ovr_alignUp4(unaff_DI,(((entity_t *)Entities + uVar7)->base).x);
      uVar4 = (int)(uVar2 - uVar1) >> 0xf;
      uVar8 = (undefined2)((ulong)Entities >> 0x10);
      peVar6 = (entity_t *)Entities;
      uVar3 = peVar6[uVar7].base.y - in_stack_0000000e;
      uVar5 = (int)uVar3 >> 0xf;
      uVar2 = ((uVar2 - uVar1 ^ uVar4) - uVar4) + ((uVar3 ^ uVar5) - uVar5) * 2;
      if ((((uVar2 != 0) && (uVar2 < uStack_4)) &&
          ((*(byte *)((int)&peVar6[uVar7].base.flags32 + 1) & 2) == 0)) &&
         ((includeFlag8 != '\0' || ((*(byte *)((int)&peVar6[uVar7].base.flags32 + 1) & 8) == 0)))) {
        *foundIndexOut = uVar7;
        uStack_4 = uVar2;
      }
    }
  }
  return uStack_4 != 0xffff;
}



/* 5b66:038d */

/* [R4] calls ovr_alignUp4 */

void __cdecl16far
ovc25_usesAlignUp43(char partyIndex,byte count,uint16_t destX,uint16_t destY,char setFlag8)

{
  byte *pbVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int unaff_DI;
  undefined2 uVar6;
  undefined2 unaff_SS;
  uint8_t entityIndex;
  
  if (count != 0) {
    iVar5 = 0;
    for (_entityIndex = 0; _entityIndex < EntityCount; _entityIndex = _entityIndex + 1) {
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      if (*(char *)((int)&((entity_t *)Entities)[_entityIndex].base.entity + 3) == partyIndex) {
        uVar3 = ovr_alignUp4(unaff_DI,(((entity_t *)Entities + _entityIndex)->base).x);
        uVar4 = ovr_alignUp4(uVar3,destX);
        uVar6 = (undefined2)((ulong)Entities >> 0x10);
        if ((uVar3 != uVar4) || (((entity_t *)Entities)[_entityIndex].base.y != destY)) {
          uVar3 = ovr_alignUp4(unaff_DI,((entity_t *)Entities)[_entityIndex].base.destX);
          uVar4 = ovr_alignUp4(uVar3,destX);
          if ((uVar3 != uVar4) || (((entity_t *)Entities)[_entityIndex].base.destY != destY))
          goto L_OVC25_5b66_038d_0482;
        }
        iVar5 = iVar5 + 1;
        if (setFlag8 != '\0') {
          pbVar1 = (byte *)((int)&((entity_t *)Entities)[_entityIndex].base.flags32 + 1);
          *pbVar1 = *pbVar1 | 8;
        }
      }
L_OVC25_5b66_038d_0482:
    }
    while ((iVar5 < (int)(uint)count &&
           (bVar2 = ovc25_textArena((uint *)CONCAT22(unaff_SS,&entityIndex),setFlag8,
                                    (uint)(byte)partyIndex,destX), bVar2))) {
      *(undefined1 *)&((entity_t *)Entities)[_entityIndex].base.state = 0;
      ((entity_t *)Entities)[_entityIndex].base.destX = destX;
      ((entity_t *)Entities)[_entityIndex].base.destY = destY;
      if (setFlag8 != '\0') {
        pbVar1 = (byte *)((int)&((entity_t *)Entities)[_entityIndex].base.flags32 + 1);
        *pbVar1 = *pbVar1 | 8;
      }
      iVar5 = iVar5 + 1;
    }
  }
  return;
}



/* 5b66:0530 */

/* [R4] calls ovr_alignUp4 */

void __cdecl16far ovc25_usesAlignUp44(char partyIndex,byte count,uint16_t destX,uint16_t destY,...)

{
  bool bVar1;
  uint value;
  uint uVar2;
  int iVar3;
  int unaff_DI;
  undefined2 uVar4;
  undefined2 unaff_SS;
  byte in_stack_00000004;
  uint8_t entityIndex;
  
  if (partyIndex != '\0') {
    iVar3 = 0;
    for (_entityIndex = 0; _entityIndex < EntityCount; _entityIndex = _entityIndex + 1) {
      uVar4 = (undefined2)((ulong)Entities >> 0x10);
      if (*(byte *)((int)&((entity_t *)Entities)[_entityIndex].base.entity + 3) == in_stack_00000004
         ) {
        value = ovr_alignUp4(unaff_DI,((entity_t *)Entities)[_entityIndex].base.destX);
        uVar2 = ovr_alignUp4(value,_count);
        if ((value == uVar2) && (((entity_t *)Entities)[_entityIndex].base.destY == destX)) {
          iVar3 = iVar3 + 1;
        }
      }
    }
    while ((iVar3 < (int)(uint)(byte)partyIndex &&
           (bVar1 = ovc25_textArena((uint *)CONCAT22(unaff_SS,&entityIndex),'\x02',
                                    (uint)in_stack_00000004,_count), bVar1))) {
      *(undefined1 *)&((entity_t *)Entities)[_entityIndex].base.state = 0;
      ((entity_t *)Entities)[_entityIndex].base.destX = _count;
      ((entity_t *)Entities)[_entityIndex].base.destY = destX;
      iVar3 = iVar3 + 1;
    }
    while ((iVar3 < (int)(uint)(byte)partyIndex &&
           (bVar1 = ovc25_textArena((uint *)CONCAT22(unaff_SS,&entityIndex),'\x01',
                                    (uint)in_stack_00000004,_count), bVar1))) {
      *(undefined1 *)&((entity_t *)Entities)[_entityIndex].base.state = 0;
      ((entity_t *)Entities)[_entityIndex].base.destX = _count;
      ((entity_t *)Entities)[_entityIndex].base.destY = destX;
      iVar3 = iVar3 + 1;
    }
    while ((iVar3 < (int)(uint)(byte)partyIndex &&
           (bVar1 = ovc25_textArena((uint *)CONCAT22(unaff_SS,&entityIndex),'\0',
                                    (uint)in_stack_00000004,_count), bVar1))) {
      *(undefined1 *)&((entity_t *)Entities)[_entityIndex].base.state = 0;
      ((entity_t *)Entities)[_entityIndex].base.destX = _count;
      ((entity_t *)Entities)[_entityIndex].base.destY = destX;
      iVar3 = iVar3 + 1;
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
  int unaff_DI;
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
                              (uVar2 + uVar5 * (int)cStack_a,unaff_DI,iVar1 + uVar6 * (int)cStack_a)
            ;
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

/* [R6] touches EntityCount, Entities */

void __cdecl16far ovc25_usesEntityCount(char partyIndex)

{
  byte *pbVar1;
  uint uVar2;
  undefined2 uVar3;
  
  for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
    uVar3 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)&((entity_t *)Entities)[uVar2].base.entity + 3) == partyIndex) {
      pbVar1 = (byte *)((int)&((entity_t *)Entities)[uVar2].base.flags32 + 1);
      *pbVar1 = *pbVar1 & 0xf7;
    }
  }
  return;
}



/* 5b66:085d */

/* Emits the spy report for a party heading towards a stronghold. */

void __cdecl16far ovc25_spyReportNotice(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint16_t uVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  entity_t *peVar10;
  uint16_t unaff_DI;
  undefined2 uVar11;
  char *unaff_SS;
  uint16_t dst;
  uint8_t text;
  undefined1 uStack_17;
  undefined1 uStack_16;
  byte bStack_15;
  uint uStack_14;
  uint uStack_12;
  uint uStack_10;
  uint uStack_e;
  uint uStack_c;
  uint uStack_a;
  uint16_t uStack_8;
  int iStack_6;
  int iStack_4;
  
  dst = unaff_DI;
  for (uStack_a = 0; (int)uStack_a < (int)(uint)GLeaderCount; uStack_a = uStack_a + 1) {
    if (*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x3d) != '\0') {
      *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x47) = 0;
      *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x41) = 0;
      *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x43) = 0;
      *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x45) = 0;
      uStack_e = 0xffff;
      unaff_DI = 0xffff;
      uStack_12 = ovr_alignUp4();
      for (uStack_c = 0; uStack_c < EntityCount; uStack_c = uStack_c + 1) {
        uVar11 = (undefined2)((ulong)Entities >> 0x10);
        peVar10 = (entity_t *)Entities;
        if (*(byte *)((int)&peVar10[uStack_c].base.entity + 3) == uStack_a) {
          uVar2 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                  ((peVar10 + uStack_c)->base).x;
          uVar7 = (int)uVar2 >> 0xf;
          uVar3 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) - peVar10[uStack_c].base.y;
          uVar8 = (int)uVar3 >> 0xf;
          piVar1 = (int *)((int)*(undefined4 *)(uStack_a << 2) + 0x45);
          *piVar1 = *piVar1 + 1;
          if ((((int)((uVar2 ^ uVar7) - uVar7) / 2 + ((uVar3 ^ uVar8) - uVar8) < 10) &&
              (piVar1 = (int *)((int)*(undefined4 *)(uStack_a << 2) + 0x41), *piVar1 = *piVar1 + 1,
              *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) ==
              ((entity_t *)Entities)[uStack_c].base.y)) &&
             (uVar2 = ovr_alignUp4(), uVar2 == uStack_12)) {
            piVar1 = (int *)((int)*(undefined4 *)(uStack_a << 2) + 0x47);
            *piVar1 = *piVar1 + 1;
          }
        }
        else if (*(char *)((int)(char **)GMenuStrings +
                          (uint)peVar10[uStack_c].base.gindex * 0x95 + 0x1f) !=
                 *(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x3f)) {
          uVar2 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                  ((peVar10 + uStack_c)->base).x;
          uVar7 = (int)uVar2 >> 0xf;
          uVar3 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) - peVar10[uStack_c].base.y;
          uVar8 = (int)uVar3 >> 0xf;
          uVar2 = (int)((uVar2 ^ uVar7) - uVar7) / 2 + ((uVar3 ^ uVar8) - uVar8);
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
      *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x4b) = unaff_DI;
      uStack_16 = 0xff;
      if (*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x40) != '\0') {
        uStack_10 = 0xffff;
        for (uStack_c = 0; (int)uStack_c < (int)(uint)GLeaderCount; uStack_c = uStack_c + 1) {
          if ((*(char *)((int)*(undefined4 *)(uStack_c << 2) + 0x3f) !=
               *(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x3f)) &&
             (uVar2 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                      *(int *)((int)*(undefined4 *)(uStack_c << 2) + 0x39),
             uVar7 = (int)uVar2 >> 0xf,
             uVar3 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) -
                     *(int *)((int)*(undefined4 *)(uStack_c << 2) + 0x3b), uVar8 = (int)uVar3 >> 0xf
             , uVar2 = (int)((uVar2 ^ uVar7) - uVar7) / 2 + ((uVar3 ^ uVar8) - uVar8),
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
        unaff_DI = *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x4b);
        uVar11 = (undefined2)((ulong)Entities >> 0x10);
        uVar2 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                (((entity_t *)Entities + unaff_DI)->base).x;
        uVar7 = (int)uVar2 >> 0xf;
        uVar3 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) -
                ((entity_t *)Entities)[unaff_DI].base.y;
        uVar8 = (int)uVar3 >> 0xf;
        uStack_14 = (int)((uVar2 ^ uVar7) - uVar7) / 2 + ((uVar3 ^ uVar8) - uVar8);
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
            uStack_17 = *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x3e);
            iStack_4 = ovc25_compute1();
            if ((int)(uint)PlayerCount < iStack_4) {
              uVar6 = ovr_randBelow();
              iStack_6 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) + -0x14 +
                         (uVar6 & 0xff);
              if (iStack_6 < 4) {
                iStack_6 = 4;
              }
              if (0x8c < iStack_6) {
                iStack_6 = 0x8b;
              }
              uVar6 = ovr_randBelow();
              uStack_8 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) + -10 + (uVar6 & 0xff)
              ;
              if ((int)uStack_8 < 1) {
                uStack_8 = 1;
              }
              if (0x3a < (int)uStack_8) {
                uStack_8 = 0x3a;
              }
              ovc25_usesAlignUp44('\x01',(byte)iStack_6,uStack_8,dst,uStack_a & 0xff);
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
              uVar11 = 0xa000;
              uVar2 = ovr_alignUp4(*(int *)((int)*(undefined4 *)((uint)bStack_15 << 2) + 0x3b),
                                   *(undefined2 *)
                                    ((int)*(undefined4 *)((uint)bStack_15 << 2) + 0x39));
              iVar4 = (uint)*(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x3e) * 0x95;
              pcVar9 = (char *)&AgntAnms[0x88].missileDy;
              pcVar5 = ovr_stsprintf((char *)CONCAT22(0x58c0,unaff_SS),
                                     (char *)CONCAT22(*(undefined2 *)
                                                       ((int)&worldMenuLabels[0].seg + 1 + iVar4),
                                                      (char *)"puppetmaker" + 3),
                                     (char *)*(undefined2 *)
                                              ((int)&worldMenuLabels[1].ofs + 1 + iVar4),&text,uVar2
                                    );
              ovr_uiNotify((char *)CONCAT22(uVar11,pcVar9),dst,pcVar5);
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
          uVar11 = (undefined2)((ulong)Entities >> 0x10);
          ovc25_usesAlignUp43((byte)uStack_a,5,(((entity_t *)Entities + unaff_DI)->base).x,
                              ((entity_t *)Entities)[unaff_DI].base.y,'\x01');
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
  int unaff_DI;
  
  uVar3 = ovr_alignUp4(unaff_DI,x);
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

/* [R4] calls ovr_alignUp4 */

int __cdecl16far ovc25_usesAlignUp46(uint16_t x,uint16_t y,char excluded,uint8_t *foundFlag)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int unaff_DI;
  undefined2 uVar4;
  undefined1 *in_stack_0000000a;
  int iStack_4;
  
  uVar1 = ovr_alignUp4(unaff_DI,x);
  iStack_4 = 0;
  *(undefined1 *)CONCAT22((uint8_t *)foundFlag,in_stack_0000000a) = 0;
  uVar3 = 0;
  do {
    if (EntityCount <= uVar3) {
      return iStack_4;
    }
    uVar4 = (undefined2)((ulong)Entities >> 0x10);
    if ((((*(byte *)((int)&((entity_t *)Entities)[uVar3].base.flags32 + 1) & 2) != 0) &&
        (uVar2 = ovr_alignUp4(unaff_DI,((entity_t *)Entities)[uVar3].base.targetX), uVar2 == uVar1))
       && (((entity_t *)Entities)[uVar3].base.targetY == y)) {
      *(undefined1 *)CONCAT22((uint8_t *)foundFlag,in_stack_0000000a) = 1;
    }
    uVar2 = ovr_alignUp4(unaff_DI,(((entity_t *)Entities + uVar3)->base).x);
    if (uVar2 == uVar1) {
      uVar4 = (undefined2)((ulong)Entities >> 0x10);
      if (((entity_t *)Entities)[uVar3].base.y == y) {
        if (*(char *)((int)(char **)GMenuStrings +
                     (uint)((entity_t *)Entities)[uVar3].base.gindex * 0x95 + 0x1f) != excluded) {
          return 0xff;
        }
        iStack_4 = iStack_4 + 1;
      }
    }
    uVar3 = uVar3 + 1;
  } while( true );
}



/* 5b66:12de */

/* Clears the per-entity byte at base.entity+2 and rebuilds the derived table when entities exist.
    */

void __cdecl16far ovc25_clearEntityFlags(void)

{
  uint uStack_6;
  
  for (uStack_6 = 0; uStack_6 < EntityCount; uStack_6 = uStack_6 + 1) {
    *(undefined1 *)((int)&((entity_t *)Entities)[uStack_6].base.entity + 2) = 0;
  }
  if (EntityCount != 0) {
    ovc25_usesAlignUp47();
    return;
  }
  return;
}



/* 5b66:131f */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* [R4] calls ovr_alignUp4 */

void ovc25_usesAlignUp47(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint16_t uVar4;
  int iVar5;
  entity_t *peVar6;
  int unaff_BP;
  uint uVar7;
  undefined2 uVar8;
  uint8_t *unaff_SS;
  uint16_t in_stack_00000000;
  
  uVar8 = (undefined2)((ulong)Entities >> 0x10);
  if (*(char *)((int)&((entity_t *)Entities)[*(int *)(unaff_BP + -4)].base.entity + 2) != '\0') {
    OVC25_5b66_131f_entry();
    return;
  }
  *(undefined1 *)((int)&((entity_t *)Entities)[*(int *)(unaff_BP + -4)].base.entity + 2) = 1;
  *(undefined1 *)(unaff_BP + -0xc) =
       *(undefined1 *)((int)&((entity_t *)Entities)[*(int *)(unaff_BP + -4)].base.entity + 3);
  *(uint8_t *)(unaff_BP + -0xb) = ((entity_t *)Entities)[*(int *)(unaff_BP + -4)].base.gindex;
  *(undefined1 *)(unaff_BP + -0xd) =
       *(undefined1 *)((int)(char **)GMenuStrings + (uint)*(byte *)(unaff_BP + -0xb) * 0x95 + 0x1f);
  uVar8 = (undefined2)((ulong)Entities >> 0x10);
  if ((*(char *)((int)&((entity_t *)Entities)[*(int *)(unaff_BP + -4)].base.entity + 1) != '\0') ||
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
  uVar2 = ovr_alignUp4(in_stack_00000000,(((entity_t *)Entities + *(int *)(unaff_BP + -4))->base).x)
  ;
  *(uint *)(unaff_BP + -6) = uVar2;
  uVar8 = (undefined2)((ulong)Entities >> 0x10);
  peVar6 = (entity_t *)Entities;
  if (((peVar6[*(int *)(unaff_BP + -4)].base.destX == 0) &&
      (peVar6[*(int *)(unaff_BP + -4)].base.destY == 0)) &&
     ((*(byte *)((int)&peVar6[*(int *)(unaff_BP + -4)].base.flags32 + 1) & 3) == 0)) {
    uVar2 = *(uint *)(unaff_BP + -4);
  }
  else {
    uVar2 = 0xffff;
  }
  *(undefined2 *)(unaff_BP + -0x10) = 1;
  uVar7 = *(uint *)(unaff_BP + -4);
  while (uVar7 = uVar7 + 1, uVar7 < EntityCount) {
    uVar3 = ovr_alignUp4(in_stack_00000000,(((entity_t *)Entities + uVar7)->base).x);
    if (uVar3 == *(uint *)(unaff_BP + -6)) {
      uVar8 = (undefined2)((ulong)Entities >> 0x10);
      peVar6 = (entity_t *)Entities;
      if (peVar6[uVar7].base.y == peVar6[*(int *)(unaff_BP + -4)].base.y) {
        *(undefined1 *)((int)&peVar6[uVar7].base.entity + 2) = 1;
        uVar8 = (undefined2)((ulong)Entities >> 0x10);
        peVar6 = (entity_t *)Entities;
        if (((peVar6[uVar7].base.destX == 0) && (peVar6[uVar7].base.destY == 0)) &&
           ((*(char *)((int)&peVar6[uVar7].base.entity + 1) == '\0' &&
            ((*(char *)((int)(char **)GMenuStrings + (uint)peVar6[uVar7].base.gindex * 0x95 + 0x1f)
              == *(char *)(unaff_BP + -0xd) &&
             (*(int *)(unaff_BP + -0x10) = *(int *)(unaff_BP + -0x10) + 1,
             (*(byte *)((int)&((entity_t *)Entities)[uVar7].base.flags32 + 1) & 3) == 0)))))) {
          uVar2 = uVar7;
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
  uVar4 = ovr_randBelow(in_stack_00000000,4);
  *(undefined1 *)(unaff_BP + -9) = (char)uVar4;
  *(undefined1 *)(unaff_BP + -10) = *(undefined1 *)(unaff_BP + -9);
  uVar7 = ovr_alignUp4(in_stack_00000000,
                       (((entity_t *)Entities + uVar2)->base).x +
                       *(char *)(*(byte *)(unaff_BP + -9) + 0x885) * 4);
  *(uint *)(unaff_BP + -6) = uVar7;
  *(int *)(unaff_BP + -8) =
       ((entity_t *)Entities)[uVar2].base.y + (int)*(char *)(*(byte *)(unaff_BP + -9) + 0x889);
  uVar8 = ovr_attact_usesGUnits
                    (*(int *)(unaff_BP + -8),in_stack_00000000,*(undefined2 *)(unaff_BP + -6));
  if ((char)uVar8 != '\0') {
    iVar5 = ovc25_usesAlignUp46(*(uint16_t *)(unaff_BP + -6),*(uint16_t *)(unaff_BP + -8),
                                *(char *)(unaff_BP + -0xd),
                                (uint8_t *)CONCAT22(in_stack_00000000,unaff_SS));
    *(int *)(unaff_BP + -2) = iVar5;
    if (*(uint *)(unaff_BP + -0x10) <= *(uint *)(unaff_BP + -2)) {
      OVC25_5b66_131f_entry();
      return;
    }
    ((entity_t *)Entities)[uVar2].base.destX = *(uint16_t *)(unaff_BP + -6);
    ((entity_t *)Entities)[uVar2].base.destY = *(uint16_t *)(unaff_BP + -8);
    if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
      ((entity_t *)Entities)[uVar2].base.targetX = *(uint16_t *)(unaff_BP + -6);
      ((entity_t *)Entities)[uVar2].base.targetY = *(uint16_t *)(unaff_BP + -8);
      *(undefined1 *)((int)&((entity_t *)Entities)[uVar2].base.flags32 + 1) = 2;
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
  ((entity_t *)Entities)[unaff_DI].base.destX = *(uint16_t *)(unaff_BP + -6);
  ((entity_t *)Entities)[unaff_DI].base.destY = *(uint16_t *)(unaff_BP + -8);
  if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
    ((entity_t *)Entities)[unaff_DI].base.targetX = *(uint16_t *)(unaff_BP + -6);
    ((entity_t *)Entities)[unaff_DI].base.targetY = *(uint16_t *)(unaff_BP + -8);
    *(undefined1 *)((int)&((entity_t *)Entities)[unaff_DI].base.flags32 + 1) = 2;
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
  int in_stack_00000000;
  
  *(byte *)(unaff_BP + -9) = *(char *)(unaff_BP + -9) + 1U & 3;
  if (*(char *)(unaff_BP + -9) != *(char *)(unaff_BP + -10)) {
    uVar1 = ovr_alignUp4(in_stack_00000000,
                         (((entity_t *)Entities + unaff_DI)->base).x +
                         *(char *)(*(byte *)(unaff_BP + -9) + 0x885) * 4);
    *(uint *)(unaff_BP + -6) = uVar1;
    *(int *)(unaff_BP + -8) =
         ((entity_t *)Entities)[unaff_DI].base.y + (int)*(char *)(*(byte *)(unaff_BP + -9) + 0x889);
    uVar2 = ovr_attact_usesGUnits
                      (*(int *)(unaff_BP + -8),in_stack_00000000,*(undefined2 *)(unaff_BP + -6));
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
    ((entity_t *)Entities)[unaff_DI].base.destX = *(uint16_t *)(unaff_BP + -6);
    ((entity_t *)Entities)[unaff_DI].base.destY = *(uint16_t *)(unaff_BP + -8);
    if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
      ((entity_t *)Entities)[unaff_DI].base.targetX = *(uint16_t *)(unaff_BP + -6);
      ((entity_t *)Entities)[unaff_DI].base.targetY = *(uint16_t *)(unaff_BP + -8);
      *(undefined1 *)((int)&((entity_t *)Entities)[unaff_DI].base.flags32 + 1) = 2;
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
  uint uVar4;
  char *arg1;
  char *unaff_SS;
  byte in_stack_00000004;
  uint8_t text;
  byte bStack_3;
  
  if (((in_stack_00000004 != 0xff) &&
      (*(char *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x3f) != '\0')) &&
     (*(int *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x5e) == 0)) {
    bStack_3 = *(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x3e);
    uVar4 = (uint)*(byte *)((int)&worldMenuLabels[8].seg + (uint)bStack_3 * 0x95) +
            (uint)*(byte *)((int)&worldMenuLabels[8].ofs + 1 + (uint)bStack_3 * 0x95) +
            (uint)*(byte *)((int)&worldMenuLabels[8].seg + 1 + (uint)bStack_3 * 0x95);
    if (((uVar4 < PlayerCount) &&
        ((*(byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x5d) & 1) == 0)) &&
       (uVar2 = ovr_randBelow(), (int)(uVar2 & 0xff) < (int)(PlayerCount - uVar4))) {
      *(undefined2 *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x5e) = 0x19;
      ovr_play_sfx();
      arg1 = (char *)"halfling castle" + 0xc;
      puVar3 = ovr_ovc15_usesStshRealloc();
      ovr_stsprintf((char *)CONCAT22(0x58f5,unaff_SS),
                    (char *)CONCAT22(puVar3,(char *)"puppetmaker" + 3),arg1,&text);
      ovr_uiNotify();
      pbVar1 = (byte *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x5d);
      *pbVar1 = *pbVar1 | 1;
    }
  }
  return;
}



/* 5b66:18cc */

/* [R7] body shape: compute */

int __cdecl16far ovc25_compute1(byte gindex,...)

{
  byte in_stack_00000004;
  
  return (uint)*(byte *)((int)&worldMenuLabels[8].seg + (uint)in_stack_00000004 * 0x95) +
         (uint)*(byte *)((int)&worldMenuLabels[8].ofs + 1 + (uint)in_stack_00000004 * 0x95) +
         (uint)*(byte *)((int)&worldMenuLabels[8].seg + 1 + (uint)in_stack_00000004 * 0x95);
}



/* 5b66:1929 */

/* WARNING: Variable defined which should be unmapped: text */
/* Emits the "Intelligence reports %s attacking." notice for a party. */

void __cdecl16far ovc25_intelAttackingNotice(byte partyIndex)

{
  byte *pbVar1;
  char cVar2;
  uint16_t uVar3;
  uint8_t *puVar4;
  char *arg1;
  char *unaff_SS;
  uint8_t text;
  byte bStack_5;
  int iStack_4;
  
  iStack_4 = ovc25_compute1();
  if ((((((iStack_4 < (int)(uint)PlayerCount) &&
         (*(int *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5e) == 0)) &&
        (*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x40) != '\0')) &&
       (((*(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5d) & 1) == 0 &&
        (9 < *(uint *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x45))))) &&
      ((*(char *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x49) != -1 &&
       ((bStack_5 = *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x49),
        *(uint *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x45) < 0x50 ||
        (uVar3 = ovr_randBelow(), (char)uVar3 == '\0')))))) &&
     (8 < *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x2a))) {
    if (*(uint *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x45) < 0x28) {
      if (*(uint *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x45) < 0x14) {
        return;
      }
      uVar3 = ovr_randBelow();
      cVar2 = (char)uVar3;
    }
    else {
      uVar3 = ovr_randBelow();
      cVar2 = (char)uVar3;
    }
    if (cVar2 == '\0') {
      ovr_play_sfx();
      *(undefined2 *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x5e) = 0x19;
      arg1 = (char *)"halfling castle" + 0xc;
      puVar4 = ovr_ovc15_usesStshRealloc();
      ovr_stsprintf((char *)CONCAT22(0x5906,unaff_SS),
                    (char *)CONCAT22(puVar4,(char *)"puppetmaker" + 3),arg1,&text);
      ovr_uiNotify();
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
  int in_stack_00000004;
  
  if ((((*(char *)((int)*(undefined4 *)(in_stack_00000004 << 2) + 0x3f) != '\0') &&
       (*(int *)((int)*(undefined4 *)(in_stack_00000004 << 2) + 0x5e) != 0)) &&
      (piVar1 = (int *)((int)*(undefined4 *)(in_stack_00000004 << 2) + 0x5e), *piVar1 = *piVar1 + -1
      , (*(byte *)((int)*(undefined4 *)(in_stack_00000004 << 2) + 0x5d) & 1) != 0)) &&
     (*(int *)((int)*(undefined4 *)(in_stack_00000004 << 2) + 0x5e) == 0)) {
    *(undefined2 *)((int)*(undefined4 *)(in_stack_00000004 << 2) + 0x5e) = 10;
    pbVar2 = (byte *)((int)*(undefined4 *)(in_stack_00000004 << 2) + 0x5d);
    *pbVar2 = *pbVar2 & 0xfe;
  }
  return;
}


