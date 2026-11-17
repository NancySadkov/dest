/*
 * ovc19_save.c - recovered from STRONG.EXE
 * memory block: OVC19_save.c
 * range: 49fd:0000 - 49fd:10cf
 * functions: 8
 */
#include "recovered.h"


/* 49fd:0000 */

undefined2 __cdecl16far save_49fd_0000(int param_1,void *param_2,undefined2 param_3,uint param_4)

{
  undefined2 uVar1;
  uint uVar2;
  
  if (param_4 == 0) {
    uVar1 = 1;
  }
  else {
    uVar2 = read(param_1,param_2,param_4);
    if (uVar2 == param_4) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 49fd:0035 */

void __cdecl16far save_49fd_0035(void)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  far_t handle;
  
  iVar2 = 0;
  for (uVar1 = 0; uVar1 < EntityCount; uVar1 = uVar1 + 1) {
    if (100 < *(byte *)(Entities.ofs + uVar1 * 0x37 + 0xe)) {
      *(undefined1 *)(Entities.ofs + uVar1 * 0x37 + 0xe) = 0xf;
      iVar2 = iVar2 + 1;
    }
  }
  if (iVar2 == 0) {
    for (uVar1 = 0xf8; uVar1 < DAT_2000_ca99; uVar1 = uVar1 + 1) {
      uVar3 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
      iVar2 = (int)DAT_2000_ca95;
      if ((*(byte *)((uint)*(byte *)(iVar2 + uVar1 * 9) * 0x27 + 0x11e) & 3) != 0) {
        ovr_OVC23_55fe_0f39(*(undefined2 *)(iVar2 + uVar1 * 9 + 4),
                            *(undefined2 *)(iVar2 + uVar1 * 9 + 6));
        uVar3 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
        ovr_OVC23_55fe_0f39(*(int *)((int)DAT_2000_ca95 + uVar1 * 9 + 4) + -1,
                            *(undefined2 *)((int)DAT_2000_ca95 + uVar1 * 9 + 6));
        uVar3 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
        ovr_OVC23_55fe_0f39(*(undefined2 *)((int)DAT_2000_ca95 + uVar1 * 9 + 4),
                            *(int *)((int)DAT_2000_ca95 + uVar1 * 9 + 6) + 1);
      }
    }
    ovr_attact_3f0b_0c2a();
    ovr_season_67e7_030a();
    handle.seg = Lbm_nwpanel1.seg;
    handle.ofs = Lbm_nwpanel1.ofs;
    ovr_stshLoadGfx(handle);
    ovr_calcSeasonPalette();
    ovr_vgaSetPalette8bit();
    ovr_manage_4d05_0000();
    DAT_2000_d2e2 = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x4d);
}



/* 49fd:01da */

undefined2 __cdecl16far save_49fd_01da(int param_1)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  char local_2a [40];
  
  ovr_stop_audio();
  ovr_drawTextAt("Loading...",0xa000);
  if (-1 < param_1) {
    SaveAuto = 0;
    AgntFlag1 = false;
    ovr_init_3381_20ee();
    cVar1 = save_49fd_0000(param_1,local_2a);
    if ((((((cVar1 != '\0') && (iVar2 = strcmp(local_2a,(char *)SaveHeader.ofs), iVar2 == 0)) &&
          (cVar1 = save_49fd_0000(param_1,(undefined2)DAT_2000_cb0d,(*(uint16_t *)((uint8_t *)&(DAT_2000_cb0d) + 2)),
                                  (char *)"sky07.lbm" + 1), cVar1 != '\0')) &&
         (((cVar1 = save_49fd_0000(param_1,(undefined2)DAT_2000_cb09,(*(uint16_t *)((uint8_t *)&(DAT_2000_cb09) + 2)),
                                   (char *)"sky07.lbm" + 1), cVar1 != '\0' &&
           (cVar1 = save_49fd_0000(param_1,DAT_2000_cb05,DAT_2000_cb07,
                                   (char *)"fletcher\'s shop" + 2), cVar1 != '\0')) &&
          ((cVar1 = save_49fd_0000(param_1,(undefined2 *)&GfxRndSeed,(char *)"puppetmaker" + 3,2),
           cVar1 != '\0' &&
           ((cVar1 = save_49fd_0000(param_1,(undefined2 *)&GfxRndSeed2,(char *)"puppetmaker" + 3,2),
            cVar1 != '\0' &&
            (cVar1 = save_49fd_0000(param_1,(undefined2 *)&EntityCount,(char *)"puppetmaker" + 3,2),
            cVar1 != '\0')))))))) &&
        (cVar1 = save_49fd_0000(param_1,Entities.ofs,Entities.seg,EntityCount * 0x37), cVar1 != '\0'
        )) && (((cVar1 = save_49fd_0000(param_1,0x881,(char *)"puppetmaker" + 3,2), cVar1 != '\0' &&
                (cVar1 = save_49fd_0000(param_1,0,0x17f8,DAT_2410_0881 * 0x13), cVar1 != '\0')) &&
               (cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2000_d1e6,
                                       (char *)"puppetmaker" + 3,1), cVar1 != '\0')))) {
      for (iVar2 = 0; iVar2 < (int)(uint)DAT_2000_d1e6; iVar2 = iVar2 + 1) {
        pvVar3 = ovr_stshAlloc(0xae);
        ((undefined2 *)(iVar2 * 4))[1] = (int)((ulong)pvVar3 >> 0x10);
        *(undefined2 *)(iVar2 * 4) = (void *)pvVar3;
        cVar1 = save_49fd_0000(param_1,*(undefined2 *)(iVar2 * 4),((undefined2 *)(iVar2 * 4))[1],
                               0xae);
        if (cVar1 == '\0') goto LAB_49fd_0800;
      }
      cVar1 = save_49fd_0000(param_1,(DW *)&TimerSeed,(char *)"puppetmaker" + 3,4);
      if (((((((cVar1 != '\0') &&
              (cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2000_d1e5,(char *)"puppetmaker" + 3
                                      ,1), cVar1 != '\0')) &&
             ((((cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2000_d1e4,
                                        (char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                ((cVar1 = save_49fd_0000(param_1,(undefined2 *)&DAT_2000_d2df,
                                         (char *)"puppetmaker" + 3,2), cVar1 != '\0' &&
                 (cVar1 = save_49fd_0000(param_1,0,(char *)"manned n/s wall" + 0xd,
                                         DAT_2000_d2df * 0x12), cVar1 != '\0')))) &&
               (cVar1 = save_49fd_0000(param_1,(undefined2 *)&DAT_2000_ca99,
                                       (char *)"puppetmaker" + 3,2), cVar1 != '\0')) &&
              (((((cVar1 = save_49fd_0000(param_1,(undefined2)DAT_2000_ca95,(*(uint16_t *)((uint8_t *)&(DAT_2000_ca95) + 2)),
                                          DAT_2000_ca99 * 9), cVar1 != '\0' &&
                  (cVar1 = save_49fd_0000(param_1,0x2f3,(char *)"puppetmaker" + 3,1), cVar1 != '\0')
                  ) && (cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2000_d19e,
                                               (char *)"puppetmaker" + 3,1), cVar1 != '\0')) &&
                ((cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2000_d16f,
                                         (char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                 (cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2000_d16e,
                                         (char *)"puppetmaker" + 3,1), cVar1 != '\0')))) &&
               ((cVar1 = save_49fd_0000(param_1,(undefined2 *)&DAT_2000_d169,
                                        (char *)"puppetmaker" + 3,4), cVar1 != '\0' &&
                ((cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2000_d310,
                                         (char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                 (cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2000_d1e3,
                                         (char *)"puppetmaker" + 3,1), cVar1 != '\0')))))))))) &&
            ((cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2000_d16d,(char *)"puppetmaker" + 3,
                                     1), cVar1 != '\0' &&
             ((((cVar1 = save_49fd_0000(param_1,0x2f4,(char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                (cVar1 = save_49fd_0000(param_1,(undefined2 *)&DAT_2000_d167,
                                        (char *)"puppetmaker" + 3,2), cVar1 != '\0')) &&
               (cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2000_d19d,
                                       (char *)"puppetmaker" + 3,1), cVar1 != '\0')) &&
              (((cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2410_5dcf,
                                        (char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                (cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2410_5dd7,
                                        (char *)"puppetmaker" + 3,1), cVar1 != '\0')) &&
               ((cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2410_5ddf,
                                        (char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                ((cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2410_5de7,
                                         (char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                 (cVar1 = save_49fd_0000(param_1,(undefined *)&DAT_2000_d3cd,
                                         (char *)"puppetmaker" + 3,2), cVar1 != '\0')))))))))))) &&
           (cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2000_d3cc,(char *)"puppetmaker" + 3,1)
           , cVar1 != '\0')) &&
          (((((cVar1 = save_49fd_0000(param_1,(undefined2 *)&DAT_2410_6a86,(char *)"puppetmaker" + 3
                                      ,2), cVar1 != '\0' &&
              (cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2410_6a88,(char *)"puppetmaker" + 3
                                      ,1), cVar1 != '\0')) &&
             (cVar1 = save_49fd_0000(param_1,0x439,(char *)"puppetmaker" + 3,1), cVar1 != '\0')) &&
            ((cVar1 = save_49fd_0000(param_1,(undefined2 *)&DAT_2000_ca91,(char *)"puppetmaker" + 3,
                                     4), cVar1 != '\0' &&
             (cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2000_ca90,(char *)"puppetmaker" + 3,
                                     1), cVar1 != '\0')))) &&
           (((cVar1 = save_49fd_0000(param_1,(undefined1 *)&GSeason,(char *)"puppetmaker" + 3,1),
             cVar1 != '\0' &&
             ((cVar1 = save_49fd_0000(param_1,(undefined2 *)&GTimeLo,(char *)"puppetmaker" + 3,2),
              cVar1 != '\0' &&
              (cVar1 = save_49fd_0000(param_1,0x744,(char *)"puppetmaker" + 3,1), cVar1 != '\0'))))
            && ((cVar1 = save_49fd_0000(param_1,(undefined1 *)&GWantsExit2,(char *)"puppetmaker" + 3
                                        ,1), cVar1 != '\0' &&
                ((((cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2000_d2e6,
                                           (char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                   (cVar1 = save_49fd_0000(param_1,(undefined2 *)&DAT_2000_d2e4,
                                           (char *)"puppetmaker" + 3,2), cVar1 != '\0')) &&
                  (cVar1 = save_49fd_0000(param_1,(undefined2 *)&GSeed,(char *)"puppetmaker" + 3,4),
                  cVar1 != '\0')) &&
                 ((cVar1 = save_49fd_0000(param_1,(undefined1 *)&DAT_2000_d3c6,
                                          (char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                  (cVar1 = save_49fd_0000(param_1,0x92bc,(char *)"puppetmaker" + 3,10),
                  cVar1 != '\0')))))))))))) &&
         ((cVar1 = save_49fd_0000(param_1,local_2a), cVar1 != '\0' &&
          (iVar2 = strcmp(local_2a,(char *)SaveHeader.ofs), iVar2 == 0)))) {
        ovr_drawTextAt("Load complete.",0xa000);
        SaveAuto = 1;
        ovr_OVC24_5943_000e();
        save_49fd_0035();
        return 1;
      }
    }
  }
LAB_49fd_0800:
  if (DAT_2410_4757 == '\0') {
    ovr_drawTextAt("Load Error",0xa000);
  }
  return 0;
}



/* 49fd:081e */

undefined1 __cdecl16far save_49fd_081e(void)

{
  undefined1 uVar1;
  char *filename;
  int handle;
  
  filename = ovr_fmVsprintf((char *)"%ssave.%03d",(char *)&GWorkDir);
  handle = ovr_open_wait_unlock_and_disk(filename);
  uVar1 = save_49fd_01da(handle);
  close(handle);
  return uVar1;
}



/* 49fd:0863 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __cdecl16far save_49fd_0863(void)

{
  undefined1 uVar1;
  int handle;
  undefined2 uVar2;
  
  handle = StshHandles[0];
  if (StshHandles[0] < 0) {
    handle = ovr_open_wait_unlock_and_disk((char *)StshNames[0]);
  }
  uVar2 = (undefined2)((ulong)DAT_2000_d1b0 >> 0x10);
  lseek(handle,CONCAT22(*(undefined2 *)((int)DAT_2000_d1b0 + 3),
                        *(undefined2 *)((int)DAT_2000_d1b0 + 1)),0);
  uVar1 = save_49fd_01da(handle);
  if (StshHandles[0] < 0) {
    close(handle);
  }
  return uVar1;
}



/* 49fd:08da */

undefined2 __cdecl16far
save_49fd_08da(int param_1,void *param_2,undefined2 param_3,uint16_t param_4)

{
  undefined2 uVar1;
  uint16_t uVar2;
  
  if (param_4 == 0) {
    uVar1 = 1;
  }
  else {
    uVar2 = write(param_1,param_2,param_4);
    if (uVar2 == param_4) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 49fd:090f */

undefined2 __cdecl16far stSave(void)

{
  char cVar1;
  char *pcVar2;
  int handle;
  int iVar3;
  
  ovr_drawTextAt("Saving...",0xa000);
  ovr_stop_audio();
  pcVar2 = ovr_fmVsprintf((char *)"%ssave.%03d",(char *)&GWorkDir);
  handle = ovr_creat_wait_unlock_and_disk(pcVar2);
  if (-1 < handle) {
    cVar1 = save_49fd_08da(handle,SaveHeader.ofs,SaveHeader.seg,0x28);
    if (((((cVar1 != '\0') &&
          (cVar1 = save_49fd_08da(handle,(undefined2)DAT_2000_cb0d,(*(uint16_t *)((uint8_t *)&(DAT_2000_cb0d) + 2)),
                                  (char *)"sky07.lbm" + 1), cVar1 != '\0')) &&
         (cVar1 = save_49fd_08da(handle,(undefined2)DAT_2000_cb09,(*(uint16_t *)((uint8_t *)&(DAT_2000_cb09) + 2)),
                                 (char *)"sky07.lbm" + 1), cVar1 != '\0')) &&
        ((((cVar1 = save_49fd_08da(handle,DAT_2000_cb05,DAT_2000_cb07,(char *)"fletcher\'s shop" + 2
                                  ), cVar1 != '\0' &&
           (cVar1 = save_49fd_08da(handle,(undefined2 *)&GfxRndSeed,(char *)"puppetmaker" + 3,2),
           cVar1 != '\0')) &&
          ((cVar1 = save_49fd_08da(handle,(undefined2 *)&GfxRndSeed2,(char *)"puppetmaker" + 3,2),
           cVar1 != '\0' &&
           ((cVar1 = save_49fd_08da(handle,(undefined2 *)&EntityCount,(char *)"puppetmaker" + 3,2),
            cVar1 != '\0' &&
            (cVar1 = save_49fd_08da(handle,Entities.ofs,Entities.seg,EntityCount * 0x37),
            cVar1 != '\0')))))) &&
         (cVar1 = save_49fd_08da(handle,0x881,(char *)"puppetmaker" + 3,2), cVar1 != '\0')))) &&
       ((cVar1 = save_49fd_08da(handle,0,0x17f8,DAT_2410_0881 * 0x13), cVar1 != '\0' &&
        (cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2000_d1e6,(char *)"puppetmaker" + 3,1),
        cVar1 != '\0')))) {
      for (iVar3 = 0; iVar3 < (int)(uint)DAT_2000_d1e6; iVar3 = iVar3 + 1) {
        cVar1 = save_49fd_08da(handle,*(undefined2 *)(iVar3 * 4),((undefined2 *)(iVar3 * 4))[1],0xae
                              );
        if (cVar1 == '\0') goto LAB_49fd_0ee6;
      }
      cVar1 = save_49fd_08da(handle,(DW *)&TimerSeed,(char *)"puppetmaker" + 3,4);
      if ((((((cVar1 != '\0') &&
             (cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2000_d1e5,(char *)"puppetmaker" + 3,1
                                    ), cVar1 != '\0')) &&
            (cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2000_d1e4,(char *)"puppetmaker" + 3,1)
            , cVar1 != '\0')) &&
           (((cVar1 = save_49fd_08da(handle,(undefined2 *)&DAT_2000_d2df,(char *)"puppetmaker" + 3,2
                                    ), cVar1 != '\0' &&
             (cVar1 = save_49fd_08da(handle,0,(char *)"manned n/s wall" + 0xd,DAT_2000_d2df * 0x12),
             cVar1 != '\0')) &&
            ((cVar1 = save_49fd_08da(handle,(undefined2 *)&DAT_2000_ca99,(char *)"puppetmaker" + 3,2
                                    ), cVar1 != '\0' &&
             ((cVar1 = save_49fd_08da(handle,(undefined2)DAT_2000_ca95,(*(uint16_t *)((uint8_t *)&(DAT_2000_ca95) + 2)),
                                      DAT_2000_ca99 * 9), cVar1 != '\0' &&
              (cVar1 = save_49fd_08da(handle,0x2f3,(char *)"puppetmaker" + 3,1), cVar1 != '\0'))))))
           )) && ((cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2000_d19e,
                                          (char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                  (((((cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2000_d16f,
                                              (char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                      (cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2000_d16e,
                                              (char *)"puppetmaker" + 3,1), cVar1 != '\0')) &&
                     (cVar1 = save_49fd_08da(handle,(undefined2 *)&DAT_2000_d169,
                                             (char *)"puppetmaker" + 3,4), cVar1 != '\0')) &&
                    ((cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2000_d310,
                                             (char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                     (cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2000_d1e3,
                                             (char *)"puppetmaker" + 3,1), cVar1 != '\0')))) &&
                   (cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2000_d16d,
                                           (char *)"puppetmaker" + 3,1), cVar1 != '\0')))))) &&
         (((((cVar1 = save_49fd_08da(handle,0x2f4,(char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
             (cVar1 = save_49fd_08da(handle,(undefined2 *)&DAT_2000_d167,(char *)"puppetmaker" + 3,2
                                    ), cVar1 != '\0')) &&
            ((((cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2000_d19d,(char *)"puppetmaker" + 3
                                       ,1), cVar1 != '\0' &&
               (((cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2410_5dcf,
                                         (char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                 (cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2410_5dd7,
                                         (char *)"puppetmaker" + 3,1), cVar1 != '\0')) &&
                (cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2410_5ddf,
                                        (char *)"puppetmaker" + 3,1), cVar1 != '\0')))) &&
              (((cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2410_5de7,
                                        (char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                (cVar1 = save_49fd_08da(handle,(undefined *)&DAT_2000_d3cd,(char *)"puppetmaker" + 3
                                        ,2), cVar1 != '\0')) &&
               (cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2000_d3cc,(char *)"puppetmaker" + 3
                                       ,1), cVar1 != '\0')))) &&
             ((cVar1 = save_49fd_08da(handle,(undefined2 *)&DAT_2410_6a86,(char *)"puppetmaker" + 3,
                                      2), cVar1 != '\0' &&
              (cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2410_6a88,(char *)"puppetmaker" + 3,
                                      1), cVar1 != '\0')))))) &&
           ((cVar1 = save_49fd_08da(handle,0x439,(char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
            (((cVar1 = save_49fd_08da(handle,(undefined2 *)&DAT_2000_ca91,(char *)"puppetmaker" + 3,
                                      4), cVar1 != '\0' &&
              (cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2000_ca90,(char *)"puppetmaker" + 3,
                                      1), cVar1 != '\0')) &&
             (cVar1 = save_49fd_08da(handle,(undefined1 *)&GSeason,(char *)"puppetmaker" + 3,1),
             cVar1 != '\0')))))) &&
          (((cVar1 = save_49fd_08da(handle,(undefined2 *)&GTimeLo,(char *)"puppetmaker" + 3,2),
            cVar1 != '\0' &&
            (cVar1 = save_49fd_08da(handle,0x744,(char *)"puppetmaker" + 3,1), cVar1 != '\0')) &&
           ((cVar1 = save_49fd_08da(handle,(undefined1 *)&GWantsExit2,(char *)"puppetmaker" + 3,1),
            cVar1 != '\0' &&
            (((cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2000_d2e6,(char *)"puppetmaker" + 3,
                                      1), cVar1 != '\0' &&
              (cVar1 = save_49fd_08da(handle,(undefined2 *)&DAT_2000_d2e4,(char *)"puppetmaker" + 3,
                                      2), cVar1 != '\0')) &&
             ((cVar1 = save_49fd_08da(handle,(undefined2 *)&GSeed,(char *)"puppetmaker" + 3,4),
              cVar1 != '\0' &&
              (((cVar1 = save_49fd_08da(handle,(undefined1 *)&DAT_2000_d3c6,
                                        (char *)"puppetmaker" + 3,1), cVar1 != '\0' &&
                (cVar1 = save_49fd_08da(handle,0x92bc,(char *)"puppetmaker" + 3,10), cVar1 != '\0'))
               && (cVar1 = save_49fd_08da(handle,SaveHeader.ofs,SaveHeader.seg,0x28), cVar1 != '\0')
               ))))))))))))) {
        close(handle);
        ovr_drawTextAt("Save complete.",0xa000);
        return 1;
      }
    }
LAB_49fd_0ee6:
    close(handle);
    pcVar2 = ovr_fmVsprintf((char *)"%ssave.%03d",(char *)&GWorkDir);
    unlink(pcVar2);
  }
  ovr_drawTextAt("Save Error",0xa000);
  return 0;
}



/* 49fd:0f26 */

void __cdecl16far save_49fd_0f26(void)

{
  char *file;
  
  ovr_drawTextAt("Deleting...",0xa000);
  file = ovr_fmVsprintf((char *)"%ssave.%03d",(char *)&GWorkDir);
  unlink(file);
  ovr_drawTextAt("Delete complete.",0xa000);
  return;
}


