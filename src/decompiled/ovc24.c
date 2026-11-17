/*
 * ovc24.c - recovered from STRONG.EXE
 * memory block: OVC24
 * range: 5943:000e - 5943:222f
 * functions: 10
 */
#include "recovered.h"


/* 5943:000e */

void __cdecl16far OVC24_5943_000e(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint16_t uVar5;
  uint uVar6;
  uint uVar7;
  uint16_t uVar8;
  
  for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
    *(undefined1 *)(Entities.ofs + uVar7 * 0x37 + 0x18) = 0;
  }
  uVar7 = 0;
  do {
    if (EntityCount <= uVar7) {
      return;
    }
    uVar8 = Entities.seg;
    uVar5 = Entities.ofs;
    if (*(char *)(uVar5 + uVar7 * 0x37 + 0x18) == '\0') {
      cVar1 = *(char *)((int)(char **)GMenuStrings +
                       (uint)*(byte *)(uVar5 + uVar7 * 0x37 + 0xd) * 0x95 + 0x1f);
      iVar3 = OVC23_55fe_3450(*(undefined2 *)(uVar5 + uVar7 * 0x37));
      iVar2 = *(int *)(Entities.ofs + uVar7 * 0x37 + 2);
      for (uVar6 = 0; uVar6 < EntityCount; uVar6 = uVar6 + 1) {
        uVar8 = Entities.seg;
        uVar5 = Entities.ofs;
        if (((*(int *)(uVar5 + uVar6 * 0x37 + 2) == iVar2) &&
            (*(char *)((int)(char **)GMenuStrings +
                      (uint)*(byte *)(uVar5 + uVar6 * 0x37 + 0xd) * 0x95 + 0x1f) != cVar1)) &&
           (iVar4 = OVC23_55fe_3450(*(undefined2 *)(uVar5 + uVar6 * 0x37)), iVar4 == iVar3)) {
          *(undefined1 *)(Entities.ofs + uVar7 * 0x37 + 0x18) = 1;
          *(undefined1 *)(Entities.ofs + uVar6 * 0x37 + 0x18) = 1;
          break;
        }
      }
    }
    uVar7 = uVar7 + 1;
  } while( true );
}



/* 5943:0196 */

char __cdecl16far OVC24_5943_0196(int param_1)

{
  char cVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  char cStack_3;
  
  cVar1 = ovr_agnt_3b1d_0c7c(Entities.ofs + param_1 * 0x37,Entities.seg);
  uVar3 = Entities.seg;
  uVar2 = Entities.ofs;
  cStack_3 = *(char *)(uVar2 + param_1 * 0x37 + 0xf) + cVar1 +
             *(char *)((int)&far_t_ARRAY_2410_26f7[8].ofs + 1 +
                      (uint)*(byte *)(uVar2 + param_1 * 0x37 + 0xd) * 0x95) +
             *(char *)((int)&far_t_ARRAY_2410_26f7[8].seg + 1 +
                      (uint)*(byte *)(uVar2 + param_1 * 0x37 + 0xd) * 0x95) + '\t';
  cVar1 = ovr_stats_6386_05d3(uVar2 + param_1 * 0x37,uVar3);
  cStack_3 = cStack_3 - cVar1;
  if (cStack_3 < '\0') {
    cStack_3 = '\0';
  }
  return cStack_3;
}



/* 5943:026e */

void __cdecl16far OVC24_5943_026e(uint param_1)

{
  uint *puVar1;
  int *piVar2;
  char *pcVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint16_t uVar7;
  char *pcVar8;
  undefined2 uVar9;
  uint uVar10;
  uint uVar11;
  undefined2 unaff_DI;
  uint16_t uVar12;
  undefined2 unaff_SS;
  long lVar13;
  uint16_t dst;
  byte bStack_2e;
  byte bStack_2d;
  undefined4 local_2c;
  undefined4 uStack_28;
  char local_24 [4];
  int iStack_20;
  int iStack_1e;
  uint uStack_1c;
  uint uStack_1a;
  uint uStack_18;
  int iStack_16;
  byte bStack_13;
  undefined1 uStack_12;
  byte bStack_11;
  byte bStack_10;
  byte bStack_f;
  uint uStack_e;
  uint uStack_c;
  uint uStack_a;
  uint uStack_8;
  uint uStack_6;
  uint uStack_4;
  
  iStack_20 = *(int *)(Entities.ofs + param_1 * 0x37 + 2);
  iStack_1e = OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + param_1 * 0x37));
  _fmemset((undefined4 *)CONCAT22(unaff_SS,&local_2c),0,8);
  uStack_1a = param_1;
  _fmemset((char *)CONCAT22(unaff_SS,local_24 + 2),0xff81,2);
  _fmemset((char *)CONCAT22(unaff_SS,local_24),0xff81,2);
  do {
    bStack_13 = *(byte *)(Entities.ofs + param_1 * 0x37 + 0xd);
    *(undefined1 *)(Entities.ofs + param_1 * 0x37 + 0x19) = 1;
    bStack_f = *(byte *)((int)(char **)GMenuStrings + (uint)bStack_13 * 0x95 + 0x1f);
    bStack_11 = OVC24_5943_0196(param_1);
    uVar5 = (uint)bStack_11 * (uint)bStack_11 * (uint)*(byte *)(Entities.ofs + param_1 * 0x37 + 0xe)
    ;
    uVar10 = (uint)bStack_f;
    puVar1 = (uint *)(&local_2c + uVar10);
    uVar11 = *puVar1;
    *puVar1 = *puVar1 + uVar5;
    piVar2 = (int *)((int)&local_2c + uVar10 * 4 + 2);
    *piVar2 = *piVar2 + ((int)uVar5 >> 0xf) + (uint)CARRY2(uVar11,uVar5);
    if (((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 + (uint)bStack_13 * 0x95) & 8) == 0) &&
       ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].ofs + 1 + (uint)bStack_13 * 0x95) & 0x20) == 0)) {
      pcVar8 = local_24 + bStack_f;
      cVar4 = ovr_agnt_3b1d_0c7c(Entities.ofs + param_1 * 0x37,Entities.seg);
      if (*pcVar8 < cVar4) {
        pcVar8 = local_24 + bStack_f;
        cVar4 = ovr_agnt_3b1d_0c7c(Entities.ofs + param_1 * 0x37,Entities.seg);
        *pcVar8 = cVar4;
      }
    }
    if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 + (uint)bStack_13 * 0x95) & 8) == 0) {
      pcVar8 = local_24 + bStack_f + 2;
      cVar4 = ovr_agnt_3b1d_0c7c(Entities.ofs + param_1 * 0x37,Entities.seg);
      if (*pcVar8 < cVar4) {
        pcVar8 = local_24 + bStack_f + 2;
        cVar4 = ovr_agnt_3b1d_0c7c(Entities.ofs + param_1 * 0x37,Entities.seg);
        *pcVar8 = cVar4;
      }
    }
    if ((local_24[bStack_f + 2] < '\x02') &&
       ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 + (uint)bStack_13 * 0x95) & 2) != 0)) {
      local_24[bStack_f + 2] = '\x02';
    }
    uStack_1c = param_1;
    if (((local_24[bStack_f] < '\x02') &&
        ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 + (uint)bStack_13 * 0x95) & 2) != 0)) &&
       (4 < *(byte *)(Entities.ofs + param_1 * 0x37 + 0xf))) {
      local_24[bStack_f] = '\x02';
    }
    do {
      param_1 = param_1 + 1;
      if (EntityCount <= param_1) break;
    } while ((*(int *)(Entities.ofs + param_1 * 0x37 + 2) != iStack_20) ||
            (iVar6 = OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + param_1 * 0x37)),
            iVar6 != iStack_1e));
  } while (param_1 < EntityCount);
  iStack_16 = 0;
  uStack_18 = 200;
  if ((-1 < (*(uint16_t *)((uint8_t *)&(local_2c) + 2))) && ((0 < (*(uint16_t *)((uint8_t *)&(local_2c) + 2)) || (200 < (uint)local_2c)))) {
    iStack_16 = (*(uint16_t *)((uint8_t *)&(local_2c) + 2));
    uStack_18 = (uint)local_2c;
  }
  if ((iStack_16 <= (*(uint16_t *)((uint8_t *)&(uStack_28) + 2))) &&
     ((iStack_16 < (*(uint16_t *)((uint8_t *)&(uStack_28) + 2)) || (uStack_18 < (uint)uStack_28)))) {
    iStack_16 = (*(uint16_t *)((uint8_t *)&(uStack_28) + 2));
    uStack_18 = (uint)uStack_28;
  }
  uVar11 = uStack_18;
  iVar6 = iStack_16;
  lVar13 = LXMUL_at_(200,CONCAT22((*(uint16_t *)((uint8_t *)&(local_2c) + 2)),(uint)local_2c));
  local_2c = LDIV_at_(lVar13,CONCAT22(iVar6,uVar11));
  local_2c = local_2c + 0x14;
  uVar11 = uStack_18;
  iVar6 = iStack_16;
  lVar13 = LXMUL_at_(200,CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_28) + 2)),(uint)uStack_28));
  uStack_28 = LDIV_at_(lVar13,CONCAT22(iVar6,uVar11));
  uStack_28 = uStack_28 + 0x14;
  uVar7 = ovr_randBelow((uint)local_2c);
  uStack_c = uVar7 & 0xff;
  uVar7 = ovr_randBelow((uint)uStack_28);
  uStack_e = uVar7 & 0xff;
  uVar7 = ovr_randBelow((uint)local_2c);
  uStack_4 = uVar7 & 0xff;
  uVar7 = ovr_randBelow((uint)uStack_28);
  uStack_6 = uVar7 & 0xff;
  if (uStack_e < uStack_c) {
    uStack_8 = uStack_4 / (uStack_6 + 1);
    bStack_10 = 1;
  }
  else {
    if (uStack_6 <= uStack_4) {
      return;
    }
    uStack_8 = uStack_6 / (uStack_4 + 1);
    bStack_10 = 0;
  }
  uStack_8 = uStack_8 + 1;
  if (2 < uStack_8) {
    uStack_8 = 2;
  }
  bStack_2d = 0xff;
  bStack_2e = 0;
  uVar5 = 0xffff;
  uStack_a = 0xffff;
  uVar11 = uStack_1a;
  do {
    if ((int)uStack_1c < (int)uVar11) {
      if (uStack_a != 0xffff) {
        if (uVar5 == 0xffff) {
          ovr_attact_3f0b_2430
                    (Entities.ofs + uStack_a * 0x37,Entities.seg,
                     CONCAT11((char)(uStack_a * 0x37 >> 8),
                              *(undefined1 *)(Entities.ofs + uStack_a * 0x37 + 0xc)));
          ovr_attact_3f0b_0ade(uStack_a,0,0,0,0);
          uVar12 = Entities.seg;
          uVar7 = Entities.ofs;
          bStack_13 = *(byte *)(uVar7 + uStack_a * 0x37 + 0xd);
          bStack_f = *(char *)((int)(char **)GMenuStrings + (uint)bStack_13 * 0x95 + 0x1f);
          if (bStack_f == '\0') {
            dst = 0xa000;
            OVC23_55fe_3450(*(undefined2 *)(uVar7 + uVar11 * 0x37));
            uVar9 = 0x195d;
            pcVar8 = ovr_fmVsprintf((char *)
                                    "Intelligence reports %s unit fleeing from battle. (%d, %d)",
                                    (char *)*(undefined2 *)
                                             ((int)&far_t_ARRAY_2410_26f7[0].seg + 1 +
                                             (uint)bStack_13 * 0x95));
            ovr_uiNotify((char *)CONCAT22(uVar9,pcVar8),dst);
          }
        }
        else {
          if (*(byte *)(Entities.ofs + uVar5 * 0x37 + 0xe) <= uStack_8) {
            uStack_8 = (uint)*(byte *)(Entities.ofs + uVar5 * 0x37 + 0xe);
          }
          *(char *)(Entities.ofs + uVar5 * 0x37 + 0xe) =
               *(char *)(Entities.ofs + uVar5 * 0x37 + 0xe) - (char)uStack_8;
          ovr_OVC41_6a8f_016b(Entities.ofs + uVar5 * 0x37,Entities.seg,
                              CONCAT11((char)(uStack_a * 0x37 >> 8),(char)uStack_8),
                              Entities.ofs + uStack_a * 0x37,Entities.seg);
          ovr_OVC25_5b66_173b(CONCAT11((char)(uVar5 * 0x37 >> 8),
                                       *(undefined1 *)(Entities.ofs + uVar5 * 0x37 + 0x1a)));
          if (*(char *)(Entities.ofs + uVar5 * 0x37 + 0xe) != '\0') {
            OVC24_5943_181d(uVar5);
            uVar12 = Entities.seg;
            uVar7 = Entities.ofs;
            if (((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].ofs + 1 +
                           (uint)*(byte *)(uVar7 + uStack_a * 0x37 + 0xd) * 0x95) & 4) != 0) &&
               ((*(uint *)(uVar7 + uVar5 * 0x37 + 0x14) & 1) == 0)) {
              cVar4 = ovr_OVC27_5ded_1d8e(uVar7 + uVar5 * 0x37,uVar12,0);
              if (cVar4 == '\0') {
                puVar1 = (uint *)(Entities.ofs + uVar5 * 0x37 + 0x14);
                *puVar1 = *puVar1 | 1;
                uVar7 = 0xa000;
                OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar11 * 0x37));
                uVar9 = 0x195d;
                pcVar8 = ovr_fmVsprintf((char *)
                                        "Intelligence reports %s unit infected with disease. (%d, %d)"
                                        ,(char *)*(undefined2 *)
                                                  ((int)&far_t_ARRAY_2410_26f7[0].seg + 1 +
                                                  (uint)*(byte *)(Entities.ofs + uVar5 * 0x37 + 0xd)
                                                  * 0x95));
                ovr_uiNotify((char *)CONCAT22(uVar9,pcVar8),uVar7);
              }
            }
            if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].ofs + 1 +
                          (uint)*(byte *)(Entities.ofs + uStack_a * 0x37 + 0xd) * 0x95) & 0xc00) !=
                0) {
              cVar4 = ovr_OVC27_5ded_1d8e(Entities.ofs + uVar5 * 0x37,Entities.seg,3);
              if (cVar4 == '\0') {
                iVar6 = (uint)*(byte *)(Entities.ofs + uStack_a * 0x37 + 0xd) * 0x95;
                if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].ofs + 1 + iVar6) & 0x800) == 0) {
                  uStack_12 = 1;
                }
                else {
                  uStack_12 = 2;
                }
                cVar4 = ovr_OVC27_5ded_1eb7(Entities.ofs + uVar5 * 0x37,Entities.seg,
                                            CONCAT11((char)((uint)iVar6 >> 8),uStack_12));
                if (cVar4 != '\0') {
                  if (DebugVerbose != false) {
                    printf("kill 3\r",unaff_DI);
                  }
                  if (*(char *)(Entities.ofs + uVar5 * 0x37 + 0xe) != '\0') {
                    pcVar3 = (char *)(Entities.ofs + uVar5 * 0x37 + 0xe);
                    *pcVar3 = *pcVar3 + -1;
                  }
                }
                uVar7 = 0xa000;
                OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar11 * 0x37));
                uVar9 = 0x195d;
                pcVar8 = ovr_fmVsprintf((char *)
                                        "Intelligence reports %s unit drained of energy. (%d, %d)",
                                        (char *)*(undefined2 *)
                                                 ((int)&far_t_ARRAY_2410_26f7[0].seg + 1 +
                                                 (uint)*(byte *)(Entities.ofs + uVar5 * 0x37 + 0xd)
                                                 * 0x95));
                ovr_uiNotify((char *)CONCAT22(uVar9,pcVar8),uVar7);
              }
            }
          }
        }
      }
      return;
    }
    if (*(int *)(Entities.ofs + uVar11 * 0x37 + 2) == iStack_20) {
      iVar6 = OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar11 * 0x37));
      if (iVar6 == iStack_1e) {
        uVar12 = Entities.seg;
        uVar7 = Entities.ofs;
        if (*(byte *)((int)(char **)GMenuStrings +
                     (uint)*(byte *)(uVar7 + uVar11 * 0x37 + 0xd) * 0x95 + 0x1f) == bStack_10) {
          if (*(byte *)(uVar7 + uVar11 * 0x37 + 0xf) < bStack_2d) {
LAB_5943_0780:
            bStack_13 = *(byte *)(Entities.ofs + uVar11 * 0x37 + 0xd);
            if (((((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].seg + 1 + (uint)bStack_13 * 0x95) &
                   0x40) == 0) || ('\x01' < local_24[(bStack_10 ^ 1) + 2])) &&
                (((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].ofs + 1 + (uint)bStack_13 * 0x95) & 8)
                  == 0 || ('\0' < local_24[(bStack_10 ^ 1) + 2])))) &&
               (((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].ofs + 1 + (uint)bStack_13 * 0x95) & 0x10)
                 == 0 || (-1 < local_24[bStack_10 ^ 1])))) {
              bStack_2d = *(byte *)(Entities.ofs + uVar11 * 0x37 + 0xf);
              uVar5 = uVar11;
            }
          }
          else if (*(byte *)(uVar7 + uVar11 * 0x37 + 0xf) == bStack_2d) {
            uVar7 = ovr_randBelow(3);
            if ((uVar7 & 0xff) == 0) goto LAB_5943_0780;
          }
        }
        else if (bStack_2e < *(byte *)(uVar7 + uVar11 * 0x37 + 0xf)) {
LAB_5943_0898:
          bStack_2e = *(byte *)(Entities.ofs + uVar11 * 0x37 + 0xf);
          uStack_a = uVar11;
        }
        else if (*(byte *)(uVar7 + uVar11 * 0x37 + 0xf) == bStack_2e) {
          uVar7 = ovr_randBelow(3);
          if ((uVar7 & 0xff) == 0) goto LAB_5943_0898;
        }
      }
    }
    uVar11 = uVar11 + 1;
  } while( true );
}



/* 5943:0d5a */

void __cdecl16far OVC24_5943_0d5a(undefined1 *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined2 uVar5;
  uint16_t uVar6;
  uint uVar7;
  uint uVar8;
  uint16_t uVar9;
  
  if (!GameRunning) {
    for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
      *(undefined1 *)(Entities.ofs + uVar7 * 0x37 + 0x19) = 0;
    }
    for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
      uVar9 = Entities.seg;
      uVar6 = Entities.ofs;
      if ((*(char *)(uVar6 + uVar7 * 0x37 + 0x18) != '\0') &&
         (*(char *)(uVar6 + uVar7 * 0x37 + 0x19) == '\0')) {
        if ((GOngoingBattle == '\0') && (*(int *)(uVar6 + uVar7 * 0x37 + 2) == GfxRndSeed2)) {
          iVar2 = OVC23_55fe_3450(*(undefined2 *)(uVar6 + uVar7 * 0x37));
          iVar3 = OVC23_55fe_3450(0);
          if (iVar2 == iVar3) goto LAB_5943_0e45;
        }
        OVC24_5943_026e(uVar7);
      }
LAB_5943_0e45:
      OVC24_5943_1bff(uVar7);
    }
    GGameState = 0x20;
    uVar7 = EntityCount;
    while (uVar7 = uVar7 - 1, -1 < (int)uVar7) {
      if (*(char *)(Entities.ofs + uVar7 * 0x37 + 0xe) == '\0') {
        if ((GOngoingBattle == '\0') && (cVar1 = ovr_OVC23_55fe_05db(), cVar1 != '\0')) {
          uVar8 = (uint)AgntCount;
          do {
            uVar8 = uVar8 - 1;
            if ((int)uVar8 < 0) break;
          } while (*(uint *)(uVar8 * 0x34 + 0x1b) != uVar7);
          if ((int)uVar8 < 0) {
            if (*(char *)((int)(char **)GMenuStrings +
                         (uint)*(byte *)(Entities.ofs + uVar7 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0')
            {
              ovr_play_sfx(8,0);
            }
            else {
              ovr_play_sfx(11,0);
            }
            ovr_OVC15_4207_0e17(uVar7);
          }
        }
        else {
          uVar6 = 0xa000;
          OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar7 * 0x37));
          uVar5 = 0x195d;
          pcVar4 = ovr_fmVsprintf((char *)"Intelligence reports %s unit destroyed. (%d, %d)",
                                  (char *)*(undefined2 *)
                                           ((int)&far_t_ARRAY_2410_26f7[0].seg + 1 +
                                           (uint)*(byte *)(Entities.ofs + uVar7 * 0x37 + 0xd) * 0x95
                                           ));
          ovr_uiNotify((char *)CONCAT22(uVar5,pcVar4),uVar6);
          ovr_OVC15_4207_0e17(uVar7);
        }
        *param_1 = 1;
      }
    }
  }
  return;
}



/* 5943:1007 */

undefined2 __cdecl16far OVC24_5943_1007(byte param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  iVar4 = *(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x39);
  iVar3 = *(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3b);
  bVar1 = ovr_manage_4d05_1b1d();
  uVar5 = (undefined2)((ulong)DAT_2000_cb0d >> 0x10);
  if (param_1 == bVar1) {
    iVar4 = *(int *)((int)DAT_2000_cb0d + (iVar4 + -2) * 0x78 + iVar3 * 2);
  }
  else {
    iVar4 = *(int *)((int)DAT_2000_cb0d + (iVar4 + -1) * 0x78 + iVar3 * 2);
  }
  uVar5 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
  iVar3 = (int)DAT_2000_ca95;
  if (*(byte *)(iVar3 + iVar4 * 9 + 2) == param_1) {
    iVar2 = (uint)*(byte *)(iVar3 + iVar4 * 9) * 0x27;
    if ((*(uint *)(iVar2 + 0x121) & 4) == 0) {
      uVar5 = CONCAT11((char)((uint)iVar2 >> 8),1);
    }
    else if ((*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3f) == '\0') &&
            (*(char *)(iVar3 + iVar4 * 9 + 1) == '\0')) {
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = CONCAT11((char)((uint)(iVar4 * 9) >> 8),1);
  }
  return uVar5;
}



/* 5943:112e */

void __cdecl16far OVC24_5943_112e(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_SS;
  char *pcVar5;
  uint16_t uVar6;
  undefined1 local_dc [80];
  char sbuf [120];
  char cStack_14;
  char local_12 [2];
  uint uStack_10;
  int iStack_e;
  uint uStack_c;
  char cStack_a;
  byte bStack_9;
  byte bStack_8;
  byte bStack_7;
  uint uStack_6;
  char cStack_4;
  byte bStack_3;
  
  DAT_2000_d2e2 = 0;
  cStack_4 = '\0';
  if (!GameRunning) {
    cStack_a = '\0';
    cStack_14 = '\0';
    for (uStack_6 = 0; (int)uStack_6 < (int)(uint)DAT_2000_d1e6; uStack_6 = uStack_6 + 1) {
      if (*(char *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3d) != '\0') {
        bStack_9 = *(byte *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3e);
        bStack_7 = *(byte *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3f);
        uStack_c = 0x1000 << (1U - (bStack_7 != 0) & 0x1f);
        bStack_8 = '\0' << (bStack_7 & 0x1f);
        iStack_e = OVC23_55fe_3450(*(undefined2 *)((int)*(undefined4 *)(uStack_6 << 2) + 0x39));
        iVar4 = *(int *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3b);
        uStack_10 = 0;
        for (iVar3 = -2; iVar3 < 2; iVar3 = iVar3 + 1) {
          uStack_10 = uStack_10 |
                      *(uint *)((int)DAT_2000_cb09 + iVar4 * 0x128 + (iStack_e + iVar3) * 2);
        }
        if (((uStack_10 & bStack_8) == 0) && ((uStack_10 & uStack_c) != 0)) {
          cVar1 = OVC24_5943_1007(uStack_6 & 0xff);
          if ((cVar1 == '\0') || (cVar1 = (char)(ulong)OVC24_5943_1eeb(iStack_e,iVar4,bStack_7), cVar1 != '\0'))
          goto LAB_5943_1263;
        }
        else {
LAB_5943_1263:
          if (((DAT_2410_0164 == '\0') || (bStack_7 == 0)) &&
             ((DAT_2410_0165 == '\0' || (bStack_7 != 0)))) goto LAB_5943_15f5;
        }
        ovr_stop_audio();
        DAT_2410_0164 = '\0';
        DAT_2410_0165 = '\0';
        bStack_3 = ovr_manage_4d05_1b1d();
        if (bStack_7 == 0) {
          ovr_play_sfx(68,0);
        }
        else {
          ovr_play_sfx(44,0);
          DAT_2410_6a86 = DAT_2410_6a86 + 1;
          cStack_a = '\x01';
        }
        if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].seg + 1 + (uint)bStack_9 * 0x95) & 0x800) == 0
           ) {
          uVar6 = 0xa000;
          OVC23_55fe_3450(*(undefined2 *)((int)*(undefined4 *)(uStack_6 << 2) + 0x39));
          pcVar2 = (char *)ovr_OVC15_4207_1c79(local_dc);
          pcVar5 = ovr_stsprintf(sbuf,"%s stronghold destroyed. (%d, %d)",pcVar2);
          ovr_uiNotify(pcVar5,uVar6);
        }
        else {
          uVar6 = 0xa000;
          pcVar2 = (char *)OVC23_55fe_3450(*(undefined2 *)
                                            ((int)*(undefined4 *)(uStack_6 << 2) + 0x39));
          pcVar5 = ovr_stsprintf(sbuf,"Mindark\'s keep destroyed. (%d, %d)",pcVar2);
          ovr_uiNotify(pcVar5,uVar6);
        }
        if (bStack_3 == uStack_6) {
          ovr_OVC23_55fe_1e87();
        }
        else {
          ovr_OVC23_55fe_1e87();
        }
        CurSfxType3 = 0xff;
        *(undefined1 *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3d) = 0;
        cStack_14 = '\x01';
        ovr_manage_4d05_0000();
        ovr_font_302d_080b(0x5a);
        _fmemset((char *)CONCAT22(unaff_SS,local_12),0,2);
        if (bStack_7 == 0) {
          ovr_OVC40_69c8_04c6();
        }
        else {
          cVar1 = ovr_season_67e7_026a(uStack_6 & 0xff);
          if (cVar1 == '\0') {
            for (iVar4 = 0; iVar4 < (int)(uint)DAT_2000_d1e6; iVar4 = iVar4 + 1) {
              if (*(char *)((int)*(undefined4 *)(iVar4 << 2) + 0x3d) != '\0') {
                local_12[*(byte *)((int)*(undefined4 *)(iVar4 << 2) + 0x3f)] = '\x01';
              }
            }
            if ((((local_12[1] == '\0') && (1 < DAT_2000_d310)) && (DAT_2410_6a88 == '\0')) &&
               ((*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x33) == '\x02' ||
                ((*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x33) == '\x01' &&
                 (8 < *(byte *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x86))))))) {
              cStack_4 = '\x01';
            }
            if (cStack_4 == '\0') {
              ovr_OVC40_69c8_04c6();
            }
            else {
              ovr_OVC40_69c8_04c6();
            }
          }
        }
        OVC24_5943_190b(uStack_6 & 0xff);
      }
LAB_5943_15f5:
    }
    if (cStack_14 != '\0') {
      bStack_3 = ovr_manage_4d05_1b1d();
      _fmemset((char *)CONCAT22(unaff_SS,local_12),0,2);
      for (uStack_6 = 0; (int)uStack_6 < (int)(uint)DAT_2000_d1e6; uStack_6 = uStack_6 + 1) {
        if (*(char *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3d) != '\0') {
          local_12[*(byte *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3f)] = '\x01';
        }
      }
      if ((bStack_3 == 0xff) ||
         (*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3d) == '\0')) {
        ovr_play_sfx(68,0);
        DAT_2410_07a6 = 0x44;
        ovr_uiNotify("Your main stronghold has been destroyed. Game over.",0xa000);
        DAT_2000_ca90 = 1;
        ovr_OVC38_68ac_03fc();
        ovr_miceRestoreArea(BlitRects + 1);
        ovr_stats_6386_00f8();
        ovr_OVC38_68ac_0148();
        ovr_init2_3338_043e();
        ovr_miceBlitRect(BlitRects + 1);
        ovr_stop_audio();
        DAT_2410_07a6 = 0xff;
      }
      else if ((local_12[1] == '\0') && (DAT_2000_d310 == 1)) {
        ovr_OVC30_619c_004e(1);
      }
      else if ((cStack_a != '\0') && ((local_12[1] == '\0' && (1 < DAT_2000_d310)))) {
        ovr_stop_audio();
        DAT_2410_07a6 = 0x54;
        ovr_play_sfx(84,0);
        ovr_uiNotify("You have defeated all enemies.",0xa000);
        ovr_font_302d_080b(CONCAT11(0x24,DAT_2410_02f4 << 4));
        if (cStack_4 == '\0') {
          ovr_inputUpdate((long)(int)((uint)DAT_2410_02f4 << 4));
        }
        else {
          ovr_OVC38_68ac_03fc();
          ovr_miceRestoreArea(BlitRects + 1);
          ovr_stats_6386_00f8();
          ovr_uiNotify("You may continue playing, but your score will not be recorded.",0xa000);
          ovr_OVC38_68ac_0148();
          ovr_init2_3338_043e();
          ovr_OVC28_6018_0251();
          ovr_OVC41_6a8f_18c6();
          ovr_miceBlitRect(BlitRects + 1);
        }
        DAT_2410_07a6 = 0xff;
        ovr_stop_audio();
      }
    }
  }
  return;
}



/* 5943:181d */

void __cdecl16far OVC24_5943_181d(int param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  long b;
  
  b = 0x8000;
  iVar3 = rand();
  lVar4 = LXLSH_at_((long)iVar3,3);
  lVar4 = LDIV_at_(lVar4,b);
  if ((((int)lVar4 == 0) &&
      ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 +
                 (uint)*(byte *)(Entities.ofs + param_1 * 0x37 + 0xd) * 0x95) & 0x2000) != 0)) &&
     (cVar1 = ovr_agnt_3b1d_0c7c(Entities.ofs + param_1 * 0x37), -1 < cVar1)) {
    cVar1 = *(char *)(Entities.ofs + param_1 * 0x37 + 0x36) -
            *(byte *)(Entities.ofs + param_1 * 0x37 + 0x36) % 6;
    cVar2 = ovr_OVC22_5087_197d();
    *(char *)(Entities.ofs + param_1 * 0x37 + 0x36) = cVar1 + cVar2;
  }
  return;
}



/* 5943:190b */

void __cdecl16far OVC24_5943_190b(byte param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  uint uStack_a;
  uint uStack_8;
  byte bStack_6;
  byte bStack_5;
  uint uStack_4;
  
  uStack_8 = 0xffff;
  uStack_a = 0xffff;
  bStack_5 = 0xff;
  bStack_6 = 0xff;
  if (*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3f) == '\0') {
    for (bVar3 = 0; bVar3 < DAT_2000_d1e6; bVar3 = bVar3 + 1) {
      if (((*(char *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x3d) != '\0') &&
          (*(char *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x3f) ==
           *(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3f))) &&
         (uVar1 = *(int *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x39) -
                  *(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x39),
         uVar4 = (int)uVar1 >> 0xf,
         uVar2 = *(int *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x3b) -
                 *(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3b),
         uVar5 = (int)uVar2 >> 0xf, uVar1 = ((uVar1 ^ uVar4) - uVar4) + ((uVar2 ^ uVar5) - uVar5),
         uVar1 < uStack_8)) {
        uStack_8 = uVar1;
        bStack_5 = bVar3;
      }
    }
  }
  else {
    for (bVar3 = 0; bVar3 < DAT_2000_d1e6; bVar3 = bVar3 + 1) {
      if (((*(char *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x3d) != '\0') &&
          (*(char *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x3f) == '\0')) &&
         (uVar1 = *(int *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x39) -
                  *(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x39),
         uVar4 = (int)uVar1 >> 0xf,
         uVar2 = *(int *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x3b) -
                 *(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3b),
         uVar5 = (int)uVar2 >> 0xf,
         uVar1 = ((uVar1 ^ uVar4) - uVar4) + ((uVar2 ^ uVar5) - uVar5) * 2, uVar1 < uStack_a)) {
        uStack_a = uVar1;
        bStack_6 = bVar3;
      }
    }
  }
  for (uVar1 = 0; uVar1 < EntityCount; uVar1 = uVar1 + 1) {
    if ((*(byte *)(Entities.ofs + uVar1 * 0x37 + 0x1a) == param_1) &&
       (*(byte *)(Entities.ofs + uVar1 * 0x37 + 0x1a) = bStack_5, bStack_6 != 0xff)) {
      *(undefined2 *)(Entities.ofs + uVar1 * 0x37 + 8) =
           *(undefined2 *)((int)*(undefined4 *)((uint)bStack_6 << 2) + 0x39);
      *(undefined2 *)(Entities.ofs + uVar1 * 0x37 + 10) =
           *(undefined2 *)((int)*(undefined4 *)((uint)bStack_6 << 2) + 0x3b);
    }
  }
  for (uStack_4 = 0xf8; uStack_4 < DAT_2000_ca99; uStack_4 = uStack_4 + 1) {
    uVar6 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
    if (*(byte *)((int)DAT_2000_ca95 + uStack_4 * 9 + 2) == param_1) {
      *(undefined1 *)((int)DAT_2000_ca95 + uStack_4 * 9 + 2) = 0xff;
    }
  }
  return;
}



/* 5943:1bff */

void __cdecl16far OVC24_5943_1bff(int param_1)

{
  uint *puVar1;
  bool bVar2;
  byte bVar3;
  char *pcVar4;
  undefined2 uVar5;
  uint16_t uVar6;
  int iVar7;
  uint uVar8;
  uint16_t uVar9;
  
  if ((*(uint *)(Entities.ofs + param_1 * 0x37 + 0x14) & 1) != 0) {
    OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + param_1 * 0x37));
    uVar9 = Entities.seg;
    uVar6 = Entities.ofs;
    if (*(char *)(uVar6 + param_1 * 0x37 + 0x18) == '\0') {
      bVar2 = false;
      for (uVar8 = 0; uVar8 < EntityCount; uVar8 = uVar8 + 1) {
        if (((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 +
                       (uint)*(byte *)(uVar6 + uVar8 * 0x37 + 0xd) * 0x95) & 1) != 0) &&
           (5 < *(byte *)(uVar6 + uVar8 * 0x37 + 0xf))) {
          bVar2 = true;
          break;
        }
      }
      if (!bVar2) {
        for (iVar7 = 0; iVar7 < 4; iVar7 = iVar7 + 1) {
          bVar3 = ovr_OVC45_77eb_0121();
          if ((*(uint *)((uint)bVar3 * 0x27 + 0x121) & 0x100) != 0) {
            bVar2 = true;
            break;
          }
        }
      }
      if (bVar2) {
        puVar1 = (uint *)(Entities.ofs + param_1 * 0x37 + 0x14);
        *puVar1 = *puVar1 & 0xfffe;
        uVar6 = 0xa000;
        OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + param_1 * 0x37));
        uVar5 = 0x195d;
        pcVar4 = ovr_fmVsprintf((char *)"Intelligence reports %s unit cured of disease. (%d, %d)",
                                (char *)*(undefined2 *)
                                         ((int)&far_t_ARRAY_2410_26f7[0].seg + 1 +
                                         (uint)*(byte *)(Entities.ofs + param_1 * 0x37 + 0xd) * 0x95
                                         ));
        ovr_uiNotify((char *)CONCAT22(uVar5,pcVar4),uVar6);
        return;
      }
    }
    uVar6 = ovr_randBelow(0x28);
    if ((uVar6 & 0xff) == 0) {
      uVar8 = 0;
      while( true ) {
        if ((EntityCount <= uVar8) ||
           ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].ofs + 1 +
                      (uint)*(byte *)(Entities.ofs + uVar8 * 0x37 + 0xd) * 0x95) & 4) != 0)) break;
        uVar8 = uVar8 + 1;
      }
      if (uVar8 < EntityCount) {
        uVar6 = 0xa000;
        OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + param_1 * 0x37));
        uVar5 = 0x195d;
        pcVar4 = ovr_fmVsprintf((char *)
                                "Intelligence reports %s unit succombs to blast spore disease. (%d, %d)"
                                ,(char *)*(undefined2 *)
                                          ((int)&far_t_ARRAY_2410_26f7[0].seg + 1 +
                                          (uint)*(byte *)(Entities.ofs + param_1 * 0x37 + 0xd) *
                                          0x95));
        ovr_uiNotify((char *)CONCAT22(uVar5,pcVar4),uVar6);
        ovr_OVC15_4207_16a5(param_1,CONCAT11((char)(uVar8 * 0x37 >> 8),
                                             *(undefined1 *)(Entities.ofs + uVar8 * 0x37 + 0xd)),
                            CONCAT11((char)(uVar8 * 0x37 >> 8),
                                     *(undefined1 *)(Entities.ofs + uVar8 * 0x37 + 0x1a)));
      }
    }
  }
  return;
}



/* 5943:1eeb */

char * __cdecl16far OVC24_5943_1eeb(undefined2 param_1,uint param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  
  if (GOngoingBattle == '\0') {
    uVar2 = GfxRndSeed2;
    if (GfxRndSeed2 == param_2) {
      uVar1 = OVC23_55fe_3450(param_1);
      uVar2 = OVC23_55fe_3450(GfxRndSeed);
      if (uVar1 == uVar2) {
        iVar4 = 0;
        while( true ) {
          if ((int)(uint)AgntCount <= iVar4) {
            return (char *)0x0;
          }
          if (((*(uint *)(iVar4 * 0x34 + 0x2b) & 0xae4) == 0) &&
             (*(char *)(iVar4 * 0x34 + 0x2f) == param_3)) break;
          iVar4 = iVar4 + 1;
        }
        return (char *)CONCAT11((char)((uint)(iVar4 * 0x34) >> 8),1);
      }
    }
    pcVar3 = (char *)(uVar2 & 0xff00);
  }
  else {
    pcVar3 = (char *)"arena" + 4;
  }
  return pcVar3;
}


