/*
 * ovc25.c - recovered from STRONG.EXE
 * memory block: OVC25
 * range: 5b66:0000 - 5b66:1def
 * functions: 19
 */
#include "recovered.h"


/* 5b66:0000 */

uint __cdecl16far
OVC25_5b66_0000(char param_1,undefined2 param_2,int param_3,undefined2 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint16_t uVar4;
  uint uVar5;
  uint16_t uVar6;
  
  iVar1 = ovr_OVC23_55fe_3450(param_4);
  iVar2 = ovr_OVC23_55fe_3450(param_2);
  uVar5 = 0;
  do {
    if (EntityCount <= uVar5) {
      return 0xffff;
    }
    uVar6 = Entities.seg;
    uVar4 = Entities.ofs;
    if ((*(char *)(uVar4 + uVar5 * 0x37 + 0x1a) == param_1) &&
       ((*(byte *)(uVar4 + uVar5 * 0x37 + 0x33) & 2) == 0)) {
      iVar3 = ovr_OVC23_55fe_3450(*(undefined2 *)(uVar4 + uVar5 * 0x37));
      if ((iVar3 == iVar2) && (*(int *)(Entities.ofs + uVar5 * 0x37 + 2) == param_3)) {
        return uVar5;
      }
      iVar3 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar5 * 0x37 + 8));
      if (iVar3 != iVar1) {
        return uVar5;
      }
      if (*(int *)(Entities.ofs + uVar5 * 0x37 + 10) != param_5) {
        return uVar5;
      }
    }
    uVar5 = uVar5 + 1;
  } while( true );
}



/* 5b66:00ff */

undefined2 __cdecl16far
OVC25_5b66_00ff(char param_1,byte param_2,undefined2 param_3,int param_4,undefined2 param_5,
               undefined2 param_6)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iStack_4;
  
  uVar4 = 0;
  do {
    if (EntityCount <= uVar4) {
      if (param_2 != 0) {
        iStack_4 = 0;
        while ((iStack_4 < (int)(uint)param_2 &&
               (iVar2 = OVC25_5b66_0000(param_1,param_5,param_6,param_3,param_4), -1 < iVar2))) {
          *(undefined1 *)(Entities.ofs + iVar2 * 0x37 + 0x30) = 0;
          *(undefined2 *)(Entities.ofs + iVar2 * 0x37 + 8) = param_3;
          *(int *)(Entities.ofs + iVar2 * 0x37 + 10) = param_4;
          pbVar1 = (byte *)(Entities.ofs + iVar2 * 0x37 + 0x33);
          *pbVar1 = *pbVar1 | 8;
          iStack_4 = iStack_4 + 1;
        }
      }
      return 0xffff;
    }
    if (*(char *)(Entities.ofs + uVar4 * 0x37 + 0x1a) == param_1) {
      iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar4 * 0x37));
      iVar3 = ovr_OVC23_55fe_3450(param_3);
      if ((iVar2 != iVar3) || (*(int *)(Entities.ofs + uVar4 * 0x37 + 2) != param_4)) {
        iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar4 * 0x37 + 8));
        iVar3 = ovr_OVC23_55fe_3450(param_3);
        if ((iVar2 != iVar3) || (*(int *)(Entities.ofs + uVar4 * 0x37 + 10) != param_4))
        goto LAB_5b66_01d9;
      }
      pbVar1 = (byte *)(Entities.ofs + uVar4 * 0x37 + 0x33);
      *pbVar1 = *pbVar1 | 8;
    }
LAB_5b66_01d9:
    uVar4 = uVar4 + 1;
  } while( true );
}



/* 5b66:028d */

char * __cdecl16far
OVC25_5b66_028d(uint *param_1,char param_2,char param_3,undefined2 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint16_t uVar7;
  uint uVar8;
  uint16_t uVar9;
  uint uStack_4;
  
  uStack_4 = 0xffff;
  iVar1 = ovr_OVC23_55fe_3450(param_4);
  for (uVar8 = 0; uVar8 < EntityCount; uVar8 = uVar8 + 1) {
    if (*(char *)(Entities.ofs + uVar8 * 0x37 + 0x1a) == param_3) {
      iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar8 * 0x37));
      uVar5 = iVar2 - iVar1 >> 0xf;
      uVar9 = Entities.seg;
      uVar7 = Entities.ofs;
      uVar3 = *(int *)(uVar7 + uVar8 * 0x37 + 2) - param_5;
      uVar6 = (int)uVar3 >> 0xf;
      uVar3 = ((iVar2 - iVar1 ^ uVar5) - uVar5) + ((uVar3 ^ uVar6) - uVar6) * 2;
      if ((((uVar3 != 0) && (uVar3 < uStack_4)) &&
          ((*(byte *)(uVar7 + uVar8 * 0x37 + 0x33) & 2) == 0)) &&
         ((param_2 != '\0' || ((*(byte *)(uVar7 + uVar8 * 0x37 + 0x33) & 8) == 0)))) {
        *param_1 = uVar8;
        uStack_4 = uVar3;
      }
    }
  }
  if (uStack_4 == 0xffff) {
    pcVar4 = (char *)"arena" + 4;
  }
  else {
    pcVar4 = (char *)"arena" + 5;
  }
  return pcVar4;
}



/* 5b66:038d */

void __cdecl16far
OVC25_5b66_038d(char param_1,byte param_2,undefined2 param_3,int param_4,char param_5)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_4;
  
  if (param_2 != 0) {
    iVar5 = 0;
    for (local_4 = 0; local_4 < EntityCount; local_4 = local_4 + 1) {
      if (*(char *)(Entities.ofs + local_4 * 0x37 + 0x1a) == param_1) {
        iVar3 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + local_4 * 0x37));
        iVar4 = ovr_OVC23_55fe_3450(param_3);
        if ((iVar3 != iVar4) || (*(int *)(Entities.ofs + local_4 * 0x37 + 2) != param_4)) {
          iVar3 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + local_4 * 0x37 + 8));
          iVar4 = ovr_OVC23_55fe_3450(param_3);
          if ((iVar3 != iVar4) || (*(int *)(Entities.ofs + local_4 * 0x37 + 10) != param_4))
          goto LAB_5b66_0482;
        }
        iVar5 = iVar5 + 1;
        if (param_5 != '\0') {
          pbVar1 = (byte *)(Entities.ofs + local_4 * 0x37 + 0x33);
          *pbVar1 = *pbVar1 | 8;
        }
      }
LAB_5b66_0482:
    }
    while ((iVar5 < (int)(uint)param_2 && (cVar2 = OVC25_5b66_028d(&local_4), cVar2 != '\0'))) {
      *(undefined1 *)(Entities.ofs + local_4 * 0x37 + 0x30) = 0;
      *(undefined2 *)(Entities.ofs + local_4 * 0x37 + 8) = param_3;
      *(int *)(Entities.ofs + local_4 * 0x37 + 10) = param_4;
      if (param_5 != '\0') {
        pbVar1 = (byte *)(Entities.ofs + local_4 * 0x37 + 0x33);
        *pbVar1 = *pbVar1 | 8;
      }
      iVar5 = iVar5 + 1;
    }
  }
  return;
}



/* 5b66:0530 */

void __cdecl16far OVC25_5b66_0530(char param_1,byte param_2,undefined2 param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_4;
  
  if (param_2 != 0) {
    iVar4 = 0;
    for (local_4 = 0; local_4 < EntityCount; local_4 = local_4 + 1) {
      if (*(char *)(Entities.ofs + local_4 * 0x37 + 0x1a) == param_1) {
        iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + local_4 * 0x37 + 8));
        iVar3 = ovr_OVC23_55fe_3450(param_3);
        if ((iVar2 == iVar3) && (*(int *)(Entities.ofs + local_4 * 0x37 + 10) == param_4)) {
          iVar4 = iVar4 + 1;
        }
      }
    }
    while ((iVar4 < (int)(uint)param_2 && (cVar1 = OVC25_5b66_028d(&local_4), cVar1 != '\0'))) {
      *(undefined1 *)(Entities.ofs + local_4 * 0x37 + 0x30) = 0;
      *(undefined2 *)(Entities.ofs + local_4 * 0x37 + 8) = param_3;
      *(int *)(Entities.ofs + local_4 * 0x37 + 10) = param_4;
      iVar4 = iVar4 + 1;
    }
    while ((iVar4 < (int)(uint)param_2 && (cVar1 = OVC25_5b66_028d(&local_4), cVar1 != '\0'))) {
      *(undefined1 *)(Entities.ofs + local_4 * 0x37 + 0x30) = 0;
      *(undefined2 *)(Entities.ofs + local_4 * 0x37 + 8) = param_3;
      *(int *)(Entities.ofs + local_4 * 0x37 + 10) = param_4;
      iVar4 = iVar4 + 1;
    }
    while ((iVar4 < (int)(uint)param_2 && (cVar1 = OVC25_5b66_028d(&local_4), cVar1 != '\0'))) {
      *(undefined1 *)(Entities.ofs + local_4 * 0x37 + 0x30) = 0;
      *(undefined2 *)(Entities.ofs + local_4 * 0x37 + 8) = param_3;
      *(int *)(Entities.ofs + local_4 * 0x37 + 10) = param_4;
      iVar4 = iVar4 + 1;
    }
  }
  return;
}



/* 5b66:0722 */

uint __cdecl16far OVC25_5b66_0722(int *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char cStack_a;
  byte bStack_9;
  uint uStack_8;
  
  iVar1 = *param_1;
  uVar2 = *param_2;
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
            uVar3 = ovr_attact_3f0b_01ec
                              (iVar1 + uVar6 * (int)cStack_a,uVar2 + uVar5 * (int)cStack_a);
            if ((char)uVar3 != '\0') {
              *param_1 = iVar1 + uVar6 * (int)cStack_a;
              *param_2 = uVar2 + uVar5 * (int)cStack_a;
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

void __cdecl16far OVC25_5b66_080f(char param_1)

{
  byte *pbVar1;
  uint uVar2;
  
  for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
    if (*(char *)(Entities.ofs + uVar2 * 0x37 + 0x1a) == param_1) {
      pbVar1 = (byte *)(Entities.ofs + uVar2 * 0x37 + 0x33);
      *pbVar1 = *pbVar1 & 0xf7;
    }
  }
  return;
}



/* 5b66:085d */

void __cdecl16far OVC25_5b66_085d(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint16_t uVar7;
  uint unaff_DI;
  uint16_t uVar8;
  char *msg;
  char local_68 [81];
  undefined1 uStack_17;
  undefined1 uStack_16;
  byte bStack_15;
  uint uStack_14;
  int iStack_12;
  uint uStack_10;
  uint uStack_e;
  uint uStack_c;
  uint uStack_a;
  int iStack_8;
  code *pcStack_6;
  int iStack_4;
  
  for (uStack_a = 0; (int)uStack_a < (int)(uint)DAT_2000_d1e6; uStack_a = uStack_a + 1) {
    if (*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x3d) != '\0') {
      *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x47) = 0;
      *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x41) = 0;
      *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x43) = 0;
      *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x45) = 0;
      uStack_e = 0xffff;
      unaff_DI = 0xffff;
      iStack_12 = ovr_OVC23_55fe_3450(*(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x39));
      for (uStack_c = 0; uStack_c < EntityCount; uStack_c = uStack_c + 1) {
        uVar8 = Entities.seg;
        uVar7 = Entities.ofs;
        if (*(byte *)(uVar7 + uStack_c * 0x37 + 0x1a) == uStack_a) {
          uVar3 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                  *(int *)(uVar7 + uStack_c * 0x37);
          uVar5 = (int)uVar3 >> 0xf;
          uVar4 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) -
                  *(int *)(uVar7 + uStack_c * 0x37 + 2);
          uVar6 = (int)uVar4 >> 0xf;
          piVar1 = (int *)((int)*(undefined4 *)(uStack_a << 2) + 0x45);
          *piVar1 = *piVar1 + 1;
          if ((int)((uVar3 ^ uVar5) - uVar5) / 2 + ((uVar4 ^ uVar6) - uVar6) < 10) {
            piVar1 = (int *)((int)*(undefined4 *)(uStack_a << 2) + 0x41);
            *piVar1 = *piVar1 + 1;
            if ((*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) ==
                 *(int *)(Entities.ofs + uStack_c * 0x37 + 2)) &&
               (iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uStack_c * 0x37)),
               iVar2 == iStack_12)) {
              piVar1 = (int *)((int)*(undefined4 *)(uStack_a << 2) + 0x47);
              *piVar1 = *piVar1 + 1;
            }
          }
        }
        else if (*(char *)((int)(char **)GMenuStrings +
                          (uint)*(byte *)(uVar7 + uStack_c * 0x37 + 0xd) * 0x95 + 0x1f) !=
                 *(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x3f)) {
          uVar3 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                  *(int *)(uVar7 + uStack_c * 0x37);
          uVar5 = (int)uVar3 >> 0xf;
          uVar4 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) -
                  *(int *)(uVar7 + uStack_c * 0x37 + 2);
          uVar6 = (int)uVar4 >> 0xf;
          uVar3 = (int)((uVar3 ^ uVar5) - uVar5) / 2 + ((uVar4 ^ uVar6) - uVar6);
          if (uVar3 < uStack_e) {
            unaff_DI = uStack_c;
            uStack_e = uVar3;
          }
          if (uVar3 < 10) {
            piVar1 = (int *)((int)*(undefined4 *)(uStack_a << 2) + 0x43);
            *piVar1 = *piVar1 + 1;
          }
        }
      }
      *(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x4b) = unaff_DI;
      uStack_16 = 0xff;
      if (*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x40) != '\0') {
        uStack_10 = 0xffff;
        for (uStack_c = 0; (int)uStack_c < (int)(uint)DAT_2000_d1e6; uStack_c = uStack_c + 1) {
          if ((*(char *)((int)*(undefined4 *)(uStack_c << 2) + 0x3f) !=
               *(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x3f)) &&
             (uVar3 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                      *(int *)((int)*(undefined4 *)(uStack_c << 2) + 0x39),
             uVar5 = (int)uVar3 >> 0xf,
             uVar4 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) -
                     *(int *)((int)*(undefined4 *)(uStack_c << 2) + 0x3b), uVar6 = (int)uVar4 >> 0xf
             , uVar3 = (int)((uVar3 ^ uVar5) - uVar5) / 2 + ((uVar4 ^ uVar6) - uVar6),
             uVar3 < uStack_10)) {
            uStack_16 = (undefined1)uStack_c;
            uStack_10 = uVar3;
          }
        }
      }
      *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x49) = uStack_16;
    }
  }
  for (uStack_a = 0; (int)uStack_a < (int)(uint)DAT_2000_d1e6; uStack_a = uStack_a + 1) {
    if ((*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x40) != '\0') &&
       (*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x3d) != '\0')) {
      OVC25_5b66_1929(CONCAT11(0x21,(undefined1)uStack_a));
      if (*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x4b) == -1) {
        uStack_14 = 0xffff;
      }
      else {
        unaff_DI = *(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x4b);
        uVar3 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                *(int *)(Entities.ofs + unaff_DI * 0x37);
        uVar5 = (int)uVar3 >> 0xf;
        uVar4 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) -
                *(int *)(Entities.ofs + unaff_DI * 0x37 + 2);
        uVar6 = (int)uVar4 >> 0xf;
        uStack_14 = (int)((uVar3 ^ uVar5) - uVar5) / 2 + ((uVar4 ^ uVar6) - uVar6);
      }
      if ((*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x43) == 0) || (9 < uStack_14)) {
        if ((*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x49) == -1) ||
           ((*(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x5d) & 1) == 0)) {
          if (*(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x47) < 10) {
            OVC25_5b66_038d(CONCAT11(0x21,(undefined1)uStack_a),10,
                            *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                            *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b),0);
            *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 0;
          }
          else {
            *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 0;
            uStack_17 = *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x3e);
            iStack_4 = OVC25_5b66_18cc(CONCAT11(0x21,uStack_17));
            if ((int)(uint)DAT_2000_d2e6 < iStack_4) {
              uVar7 = ovr_randBelow(0x28);
              pcStack_6 = (code *)init_3381_08dc +
                          (uVar7 & 0xff) + *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39);
              if ((int)pcStack_6 < 4) {
                pcStack_6 = (code *)0x4;
              }
              if (0x8c < (int)pcStack_6) {
                pcStack_6 = (code *)0x8b;
              }
              uVar7 = ovr_randBelow(0x14);
              iStack_8 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) + -10 + (uVar7 & 0xff)
              ;
              if (iStack_8 < 1) {
                iStack_8 = 1;
              }
              if (0x3a < iStack_8) {
                iStack_8 = 0x3a;
              }
              OVC25_5b66_0530(uStack_a & 0xff,1,pcStack_6,iStack_8);
            }
          }
        }
        else {
          OVC25_5b66_080f(CONCAT11(0x21,(undefined1)uStack_a));
          bStack_15 = *(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x49);
          if ((0xe < *(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x47)) &&
             (OVC25_5b66_00ff(), *(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) != '\x02')) {
            uVar7 = 0xa000;
            ovr_OVC23_55fe_3450(*(undefined2 *)((int)*(undefined4 *)((uint)bStack_15 << 2) + 0x39));
            msg = ovr_stsprintf(local_68,"Spies report %s heading towards stronghold. (%d, %d)",
                                (char *)*(undefined2 *)
                                         ((int)&far_t_ARRAY_2410_26f7[0].seg + 1 +
                                         (uint)*(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x3e)
                                         * 0x95));
            ovr_uiNotify(msg,uVar7);
          }
          OVC25_5b66_038d(CONCAT11(0x21,(undefined1)uStack_a),0xf,
                          *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                          *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b),0);
          *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 2;
        }
      }
      else {
        OVC25_5b66_080f(CONCAT11(0x21,(undefined1)uStack_a));
        if (9 < *(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x47)) {
          OVC25_5b66_038d(CONCAT11((char)(unaff_DI * 0x37 >> 8),(undefined1)uStack_a),5,
                          *(undefined2 *)(Entities.ofs + unaff_DI * 0x37),
                          *(undefined2 *)(Entities.ofs + unaff_DI * 0x37 + 2),1);
        }
        OVC25_5b66_038d(CONCAT11(0x21,(undefined1)uStack_a),10,
                        *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                        *(undefined2 *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b),0);
        *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 1;
      }
    }
  }
  OVC25_5b66_12de();
  return;
}



/* 5b66:112d */

uint __cdecl16far OVC25_5b66_112d(undefined2 param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = ovr_OVC23_55fe_3450(param_1);
  uVar3 = iVar2 + 3;
  if (((((int)uVar3 < 0x94) && (-1 < iVar2)) && (param_2 < 0x3c)) && (-1 < param_2)) {
    for (iVar5 = -2; iVar5 < 2; iVar5 = iVar5 + 1) {
      iVar4 = *(int *)((int)DAT_2000_cb0d + (iVar2 + iVar5) * 0x78 + param_2 * 2) * 9;
      bVar1 = *(byte *)((int)DAT_2000_ca95 + iVar4);
      uVar3 = CONCAT11((char)((uint)iVar4 >> 8),bVar1);
      if ((bVar1 < 0xf8) && (uVar3 = (uint)bVar1 * 0x27, *(char *)(uVar3 + 0x11a) != '\0')) {
        return CONCAT11((char)(uVar3 >> 8),1);
      }
    }
  }
  return uVar3 & 0xff00;
}



/* 5b66:11cb */

int __cdecl16far OVC25_5b66_11cb(undefined2 param_1,int param_2,char param_3,undefined1 *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iStack_4;
  
  iVar1 = ovr_OVC23_55fe_3450(param_1);
  iStack_4 = 0;
  *param_4 = 0;
  uVar3 = 0;
  do {
    if (EntityCount <= uVar3) {
      return iStack_4;
    }
    if ((((*(byte *)(Entities.ofs + uVar3 * 0x37 + 0x33) & 2) != 0) &&
        (iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar3 * 0x37 + 4)),
        iVar2 == iVar1)) && (*(int *)(Entities.ofs + uVar3 * 0x37 + 6) == param_2)) {
      *param_4 = 1;
    }
    iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar3 * 0x37));
    if (iVar2 == iVar1) {
      if (*(int *)(Entities.ofs + uVar3 * 0x37 + 2) == param_2) {
        if (*(char *)((int)(char **)GMenuStrings +
                     (uint)*(byte *)(Entities.ofs + uVar3 * 0x37 + 0xd) * 0x95 + 0x1f) != param_3) {
          return 0xff;
        }
        iStack_4 = iStack_4 + 1;
      }
    }
    uVar3 = uVar3 + 1;
  } while( true );
}



/* 5b66:12de */

void __cdecl16far OVC25_5b66_12de(void)

{
  undefined2 uStack_6;
  
  for (uStack_6 = 0; uStack_6 < EntityCount; uStack_6 = uStack_6 + 1) {
    *(undefined1 *)(Entities.ofs + uStack_6 * 0x37 + 0x19) = 0;
  }
  if (EntityCount != 0) {
    OVC25_5b66_131f();
    return;
  }
  return;
}



/* 5b66:131f */

void __cdecl16far OVC25_5b66_131f(void)

{
  undefined4 uVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  uint16_t uVar5;
  int unaff_BP;
  uint uVar6;
  uint uVar7;
  uint16_t uVar8;
  undefined2 unaff_SS;
  
  if (*(char *)(Entities.ofs + *(int *)(unaff_BP + -4) * 0x37 + 0x19) != '\0') {
    OVC25_5b66_1723();
    return;
  }
  *(undefined1 *)(Entities.ofs + *(int *)(unaff_BP + -4) * 0x37 + 0x19) = 1;
  *(undefined1 *)(unaff_BP + -0xc) =
       *(undefined1 *)(Entities.ofs + *(int *)(unaff_BP + -4) * 0x37 + 0x1a);
  *(undefined1 *)(unaff_BP + -0xb) =
       *(undefined1 *)(Entities.ofs + *(int *)(unaff_BP + -4) * 0x37 + 0xd);
  *(undefined1 *)(unaff_BP + -0xd) =
       *(undefined1 *)((int)(char **)GMenuStrings + (uint)*(byte *)(unaff_BP + -0xb) * 0x95 + 0x1f);
  if ((*(char *)(Entities.ofs + *(int *)(unaff_BP + -4) * 0x37 + 0x18) != '\0') ||
     (*(char *)(unaff_BP + -0xd) != '\0')) {
    if (*(char *)(unaff_BP + -0xd) == '\0') {
      OVC25_5b66_1723();
      return;
    }
    uVar1 = *(undefined4 *)((uint)*(byte *)(unaff_BP + -0xc) << 2);
    if (*(char *)((int)uVar1 + 0x4a) != '\0') {
      OVC25_5b66_1723();
      return;
    }
  }
  uVar3 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + *(int *)(unaff_BP + -4) * 0x37));
  *(undefined2 *)(unaff_BP + -6) = uVar3;
  uVar8 = Entities.seg;
  uVar5 = Entities.ofs;
  if (((*(int *)(uVar5 + *(int *)(unaff_BP + -4) * 0x37 + 8) == 0) &&
      (*(int *)(uVar5 + *(int *)(unaff_BP + -4) * 0x37 + 10) == 0)) &&
     ((*(byte *)(uVar5 + *(int *)(unaff_BP + -4) * 0x37 + 0x33) & 3) == 0)) {
    uVar7 = *(uint *)(unaff_BP + -4);
  }
  else {
    uVar7 = 0xffff;
  }
  *(undefined2 *)(unaff_BP + -0x10) = 1;
  uVar6 = *(uint *)(unaff_BP + -4);
  while (uVar6 = uVar6 + 1, uVar6 < EntityCount) {
    iVar4 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar6 * 0x37));
    if (iVar4 == *(int *)(unaff_BP + -6)) {
      uVar8 = Entities.seg;
      uVar5 = Entities.ofs;
      if (*(int *)(uVar5 + uVar6 * 0x37 + 2) == *(int *)(uVar5 + *(int *)(unaff_BP + -4) * 0x37 + 2)
         ) {
        *(undefined1 *)(uVar5 + uVar6 * 0x37 + 0x19) = 1;
        uVar8 = Entities.seg;
        uVar5 = Entities.ofs;
        if (((*(int *)(uVar5 + uVar6 * 0x37 + 8) == 0) && (*(int *)(uVar5 + uVar6 * 0x37 + 10) == 0)
            ) && ((*(char *)(uVar5 + uVar6 * 0x37 + 0x18) == '\0' &&
                  ((*(char *)((int)(char **)GMenuStrings +
                             (uint)*(byte *)(uVar5 + uVar6 * 0x37 + 0xd) * 0x95 + 0x1f) ==
                    *(char *)(unaff_BP + -0xd) &&
                   (*(int *)(unaff_BP + -0x10) = *(int *)(unaff_BP + -0x10) + 1,
                   (*(byte *)(Entities.ofs + uVar6 * 0x37 + 0x33) & 3) == 0)))))) {
          uVar7 = uVar6;
        }
      }
    }
  }
  if (uVar7 == 0xffff) {
    OVC25_5b66_1723();
    return;
  }
  if (*(uint *)(unaff_BP + -0x10) < 2) {
    OVC25_5b66_1723();
    return;
  }
  uVar5 = ovr_randBelow(4);
  *(undefined1 *)(unaff_BP + -9) = (char)uVar5;
  *(undefined1 *)(unaff_BP + -10) = *(undefined1 *)(unaff_BP + -9);
  uVar3 = ovr_OVC23_55fe_3450(*(int *)(Entities.ofs + uVar7 * 0x37) +
                              *(char *)(*(byte *)(unaff_BP + -9) + 0x885) * 4);
  *(undefined2 *)(unaff_BP + -6) = uVar3;
  *(int *)(unaff_BP + -8) =
       *(int *)(Entities.ofs + uVar7 * 0x37 + 2) + (int)*(char *)(*(byte *)(unaff_BP + -9) + 0x889);
  cVar2 = ovr_attact_3f0b_01ec(*(undefined2 *)(unaff_BP + -6),*(undefined2 *)(unaff_BP + -8));
  if (cVar2 != '\0') {
    uVar3 = OVC25_5b66_11cb(*(undefined2 *)(unaff_BP + -6),*(undefined2 *)(unaff_BP + -8),
                            CONCAT11((char)((uint)(unaff_BP + -0xe) >> 8),
                                     *(undefined1 *)(unaff_BP + -0xd)),unaff_BP + -0xe);
    *(undefined2 *)(unaff_BP + -2) = uVar3;
    if (*(uint *)(unaff_BP + -0x10) <= *(uint *)(unaff_BP + -2)) {
      OVC25_5b66_1723();
      return;
    }
    *(undefined2 *)(Entities.ofs + uVar7 * 0x37 + 8) = *(undefined2 *)(unaff_BP + -6);
    *(undefined2 *)(Entities.ofs + uVar7 * 0x37 + 10) = *(undefined2 *)(unaff_BP + -8);
    if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
      *(undefined2 *)(Entities.ofs + uVar7 * 0x37 + 4) = *(undefined2 *)(unaff_BP + -6);
      *(undefined2 *)(Entities.ofs + uVar7 * 0x37 + 6) = *(undefined2 *)(unaff_BP + -8);
      *(undefined1 *)(Entities.ofs + uVar7 * 0x37 + 0x33) = 2;
      OVC25_5b66_1723();
      return;
    }
    *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
    if (EntityCount <= *(uint *)(unaff_BP + -4)) {
      return;
    }
    OVC25_5b66_131f();
    return;
  }
  OVC25_5b66_170e();
  return;
}



/* 5b66:1667 */

void __cdecl16far OVC25_5b66_1667(void)

{
  undefined2 in_AX;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  
  *(undefined2 *)(unaff_BP + -2) = in_AX;
  if (*(uint *)(unaff_BP + -0x10) <= *(uint *)(unaff_BP + -2)) {
    OVC25_5b66_1723();
    return;
  }
  *(undefined2 *)(Entities.ofs + unaff_DI * 0x37 + 8) = *(undefined2 *)(unaff_BP + -6);
  *(undefined2 *)(Entities.ofs + unaff_DI * 0x37 + 10) = *(undefined2 *)(unaff_BP + -8);
  if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
    *(undefined2 *)(Entities.ofs + unaff_DI * 0x37 + 4) = *(undefined2 *)(unaff_BP + -6);
    *(undefined2 *)(Entities.ofs + unaff_DI * 0x37 + 6) = *(undefined2 *)(unaff_BP + -8);
    *(undefined1 *)(Entities.ofs + unaff_DI * 0x37 + 0x33) = 2;
    OVC25_5b66_1723();
    return;
  }
  *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
  if (*(uint *)(unaff_BP + -4) < EntityCount) {
    OVC25_5b66_131f();
    return;
  }
  return;
}



/* 5b66:170e */

void __cdecl16far OVC25_5b66_170e(void)

{
  char cVar1;
  undefined2 uVar2;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  
  *(byte *)(unaff_BP + -9) = *(char *)(unaff_BP + -9) + 1U & 3;
  if (*(char *)(unaff_BP + -9) != *(char *)(unaff_BP + -10)) {
    uVar2 = ovr_OVC23_55fe_3450(*(int *)(Entities.ofs + unaff_DI * 0x37) +
                                *(char *)(*(byte *)(unaff_BP + -9) + 0x885) * 4);
    *(undefined2 *)(unaff_BP + -6) = uVar2;
    *(int *)(unaff_BP + -8) =
         *(int *)(Entities.ofs + unaff_DI * 0x37 + 2) +
         (int)*(char *)(*(byte *)(unaff_BP + -9) + 0x889);
    cVar1 = ovr_attact_3f0b_01ec(*(undefined2 *)(unaff_BP + -6),*(undefined2 *)(unaff_BP + -8));
    if (cVar1 == '\0') {
      OVC25_5b66_170e();
      return;
    }
    uVar2 = OVC25_5b66_11cb(*(undefined2 *)(unaff_BP + -6),*(undefined2 *)(unaff_BP + -8),
                            CONCAT11((char)((uint)(unaff_BP + -0xe) >> 8),
                                     *(undefined1 *)(unaff_BP + -0xd)),unaff_BP + -0xe);
    *(undefined2 *)(unaff_BP + -2) = uVar2;
    if (*(uint *)(unaff_BP + -0x10) <= *(uint *)(unaff_BP + -2)) {
      OVC25_5b66_1723();
      return;
    }
    *(undefined2 *)(Entities.ofs + unaff_DI * 0x37 + 8) = *(undefined2 *)(unaff_BP + -6);
    *(undefined2 *)(Entities.ofs + unaff_DI * 0x37 + 10) = *(undefined2 *)(unaff_BP + -8);
    if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
      *(undefined2 *)(Entities.ofs + unaff_DI * 0x37 + 4) = *(undefined2 *)(unaff_BP + -6);
      *(undefined2 *)(Entities.ofs + unaff_DI * 0x37 + 6) = *(undefined2 *)(unaff_BP + -8);
      *(undefined1 *)(Entities.ofs + unaff_DI * 0x37 + 0x33) = 2;
      OVC25_5b66_1723();
      return;
    }
  }
  *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
  if (*(uint *)(unaff_BP + -4) < EntityCount) {
    OVC25_5b66_131f();
    return;
  }
  return;
}



/* 5b66:1723 */

void __cdecl16far OVC25_5b66_1723(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
  if (*(uint *)(unaff_BP + -4) < EntityCount) {
    OVC25_5b66_131f();
    return;
  }
  return;
}



/* 5b66:173b */

void __cdecl16far OVC25_5b66_173b(byte param_1)

{
  byte *pbVar1;
  uint16_t uVar2;
  char *arg1;
  uint uVar3;
  char *msg;
  char local_54 [81];
  byte bStack_3;
  
  if (((param_1 != 0xff) && (*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3f) != '\0')) &&
     (*(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5e) == 0)) {
    bStack_3 = *(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3e);
    uVar3 = (uint)*(byte *)((int)&far_t_ARRAY_2410_26f7[8].seg + (uint)bStack_3 * 0x95) +
            (uint)*(byte *)((int)&far_t_ARRAY_2410_26f7[8].ofs + 1 + (uint)bStack_3 * 0x95) +
            (uint)*(byte *)((int)&far_t_ARRAY_2410_26f7[8].seg + 1 + (uint)bStack_3 * 0x95);
    if (((uVar3 < DAT_2000_d2e6) &&
        ((*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5d) & 1) == 0)) &&
       (uVar2 = ovr_randBelow(100), (int)(uVar2 & 0xff) < (int)(DAT_2000_d2e6 - uVar3))) {
      *(undefined2 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5e) = 0x19;
      ovr_play_sfx(82,0);
      uVar2 = DAT_2000_d0f7;
      arg1 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)param_1 * 4));
      msg = ovr_stsprintf(local_54,"%s is attacking.",arg1);
      ovr_uiNotify(msg,uVar2);
      pbVar1 = (byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5d);
      *pbVar1 = *pbVar1 | 1;
    }
  }
  return;
}



/* 5b66:18cc */

int __cdecl16far OVC25_5b66_18cc(byte param_1)

{
  return (uint)*(byte *)((int)&far_t_ARRAY_2410_26f7[8].seg + (uint)param_1 * 0x95) +
         (uint)*(byte *)((int)&far_t_ARRAY_2410_26f7[8].ofs + 1 + (uint)param_1 * 0x95) +
         (uint)*(byte *)((int)&far_t_ARRAY_2410_26f7[8].seg + 1 + (uint)param_1 * 0x95);
}



/* 5b66:1929 */

void __cdecl16far OVC25_5b66_1929(byte param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  char cVar3;
  uint16_t uVar4;
  char *arg1;
  char *msg;
  char local_56 [81];
  byte bStack_5;
  int iStack_4;
  
  uVar2 = *(undefined4 *)((uint)param_1 << 2);
  iStack_4 = OVC25_5b66_18cc(CONCAT11((char)(((uint)param_1 << 2) >> 8),
                                      *(undefined1 *)((int)uVar2 + 0x3e)));
  if ((((((iStack_4 < (int)(uint)DAT_2000_d2e6) &&
         (*(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5e) == 0)) &&
        (*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x40) != '\0')) &&
       (((*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5d) & 1) == 0 &&
        (9 < *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x45))))) &&
      ((*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x49) != -1 &&
       ((bStack_5 = *(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x49),
        *(uint *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x45) < 0x50 ||
        (uVar4 = ovr_randBelow(0x28), (char)uVar4 == '\0')))))) &&
     (8 < *(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x2a))) {
    if (*(uint *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x45) < 0x28) {
      if (*(uint *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x45) < 0x14) {
        return;
      }
      uVar4 = ovr_randBelow(0x78);
      cVar3 = (char)uVar4;
    }
    else {
      uVar4 = ovr_randBelow(0x50);
      cVar3 = (char)uVar4;
    }
    if (cVar3 == '\0') {
      ovr_play_sfx(82,0);
      *(undefined2 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5e) = 0x19;
      uVar4 = DAT_2000_d0f7;
      arg1 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((uint)param_1 * 4));
      msg = ovr_stsprintf(local_56,"Intelligence reports %s attacking.",arg1);
      ovr_uiNotify(msg,uVar4);
      pbVar1 = (byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5d);
      *pbVar1 = *pbVar1 | 1;
    }
  }
  return;
}



/* 5b66:1b48 */

void __cdecl16far OVC25_5b66_1b48(int param_1)

{
  int *piVar1;
  byte *pbVar2;
  
  if ((((*(char *)((int)*(undefined4 *)(param_1 << 2) + 0x3f) != '\0') &&
       (*(int *)((int)*(undefined4 *)(param_1 << 2) + 0x5e) != 0)) &&
      (piVar1 = (int *)((int)*(undefined4 *)(param_1 << 2) + 0x5e), *piVar1 = *piVar1 + -1,
      (*(byte *)((int)*(undefined4 *)(param_1 << 2) + 0x5d) & 1) != 0)) &&
     (*(int *)((int)*(undefined4 *)(param_1 << 2) + 0x5e) == 0)) {
    *(undefined2 *)((int)*(undefined4 *)(param_1 << 2) + 0x5e) = 10;
    pbVar2 = (byte *)((int)*(undefined4 *)(param_1 << 2) + 0x5d);
    *pbVar2 = *pbVar2 & 0xfe;
  }
  return;
}


