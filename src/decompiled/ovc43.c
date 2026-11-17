/*
 * ovc43.c - recovered from STRONG.EXE
 * memory block: OVC43
 * range: 6fbe:0000 - 6fbe:03ff
 * functions: 5
 */
#include "recovered.h"


/* 6fbe:0000 */

/* WARNING: Instruction at (ram,0x00061dad) overlaps instruction at (ram,0x00061dac)
    */

int * __cdecl16far OVC43_6fbe_0000(undefined4 param_1,int *param_2,int *param_3)

{
  char *pcVar1;
  uint16_t uVar2;
  int *piVar3;
  undefined2 in_CX;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int unaff_DI;
  undefined2 uVar7;
  int *piStack_8;
  int *uStack_6;
  
  piVar3 = (int *)((char *)"puppetmaker" + 3);
  TextBlitDstSeg = 0xa000;
  iVar6 = 0;
  while( true ) {
    uVar7 = (undefined2)((ulong)param_1 >> 0x10);
    if (*(int *)((int)param_1 + 6) <= iVar6) {
      return piVar3;
    }
    uStack_6 = (int *)CONCAT22(param_3,param_2);
    piStack_8 = param_3;
    piVar4 = param_2 + 3;
    uVar5 = param_2[2] - 0xb;
    if (uVar5 < 6) break;
    piVar3 = (int *)ovr_driver_2d63_0b94((int)param_2 + *uStack_6);
    iVar6 = iVar6 + 1;
    param_2 = piVar3;
    param_3 = piVar4;
  }
  switch(uVar5) {
  case 0:
    do {
    } while ((char)param_3 == -1);
    goto code_r0x00061e64;
  case 1:
    pcVar1 = (char *)(uVar5 * 2 + iVar6);
    *pcVar1 = *pcVar1 + (char)piVar4;
    break;
  case 2:
    goto LAB_619c_03ce;
  case 3:
    goto code_r0x00061d78;
  case 4:
    if (-1 < (int)uVar5) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x21);
    }
    param_3 = (int *)((char *)"puppetmaker" + 3);
code_r0x00061d78:
    if (*(bool *)&GameRunning == false) {
      ovr_fmFreeAudio(1);
    }
LAB_619c_03ce:
    uStack_6 = (int *)ovr_stshAlloc(0xae);
    piStack_8 = (int *)(uint)DAT_2000_d1e6;
    uVar5 = (uint)DAT_2000_d1e6;
    ((undefined2 *)(uVar5 * 4))[1] = (int)((ulong)uStack_6 >> 0x10);
    *(undefined2 *)(uVar5 * 4) = (uint16_t)uStack_6;
    DAT_2000_d1e6 = DAT_2000_d1e6 + 1;
    break;
  case 5:
    pcVar1 = (char *)(uVar5 * 2 + unaff_DI + -0x1ba);
    *pcVar1 = *pcVar1 + (char)in_CX;
    uStack_6 = (int *)CONCAT22(param_3,piVar4);
  }
  _fmemset((void far *)uStack_6,0,0xae);
  strcpy((char *)uStack_6,
         (char *)*(undefined2 *)
                  ((int)&far_t_ARRAY_2410_26f7[0].seg + 1 + (uint)(byte)param_1 * 0x95));
  *(undefined1 *)((int)(int *)uStack_6 + 0x3d) = 1;
  *(undefined2 *)((int)(int *)uStack_6 + 0x39) = uVar7;
  *(undefined2 *)((int)uStack_6 + 0x3b) = (uint16_t)param_2;
  *(byte *)((int *)uStack_6 + 0x1f) = (byte)param_1;
  *(undefined1 *)((int)(int *)uStack_6 + 0x2f) = 0xff;
  *(undefined1 *)((int *)uStack_6 + 0x18) = 3;
  uVar2 = ovr_randBelow(1);
  *(char *)((int *)uStack_6 + 0x1a) = (char)uVar2;
code_r0x00061e64:
  ovr_manage_4d05_01d4();
  piVar3 = (int *)uStack_6;
  uVar7 = (undefined2)((ulong)uStack_6 >> 0x10);
  if (*(char *)((int)&far_t_ARRAY_2410_26f7[0xc].seg + (uint)(byte)param_1 * 0x95) != -1) {
    *(undefined1 *)(piVar3 + 0x15) =
         *(undefined1 *)((int)&far_t_ARRAY_2410_26f7[0xc].seg + (uint)(byte)param_1 * 0x95);
  }
  if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].seg + 1 + (uint)(byte)param_1 * 0x95) & 0x800) != 0)
  {
    *(undefined1 *)((int)piVar3 + 0x2d) = 0x12;
  }
  *(undefined1 *)((int)piVar3 + 0x3f) =
       *(undefined1 *)((int)(char **)GMenuStrings + (uint)(byte)param_1 * 0x95 + 0x1f);
  *(undefined1 *)((int)piVar3 + 0x33) =
       *(undefined1 *)((int)(far_t *)(far_t_ARRAY_2410_26f7 + 9) + (uint)(byte)param_1 * 0x95);
  *(undefined1 *)((int)piVar3 + 0x31) =
       *(undefined1 *)((int)&far_t_ARRAY_2410_26f7[6].seg + (uint)(byte)param_1 * 0x95);
  *(undefined1 *)(piVar3 + 0x19) = *(undefined1 *)((int)piVar3 + 0x31);
  *(byte *)(piVar3 + 0x14) = *(byte *)(piVar3 + 0x14) | 0x16;
  *(undefined1 *)(piVar3 + 0x20) = 1;
  piVar3[0x2c] = 0;
  piVar3[0x2b] = 100;
  *(undefined1 *)((int)piVar3 + 0x89) = 0xff;
  ovr_OVC22_5087_056e(CONCAT11((char)((uint)(byte)param_1 * 0x95 >> 8),(*(uint8_t *)((uint8_t *)&(piStack_8)))));
  return (int *)((uint)piStack_8 & 0xff);
}



/* 6fbe:013a */

void __cdecl16far
OVC43_6fbe_013a(undefined2 param_1,undefined2 param_2,uint16_t param_3,uint16_t param_4,
               uint16_t param_5)

{
  uint16_t unaff_SS;
  bool bVar1;
  far_t buf;
  far_t buf_00;
  uint local_12;
  int iStack_10;
  int iStack_e;
  
  buf.seg = unaff_SS;
  buf.ofs = (uint16_t)&local_12;
  ovr_stshRead(param_3,buf,0x10);
  if (iStack_e != -0xe06) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x46);
  }
  bVar1 = local_12 < 0x10;
  local_12 = local_12 - 0x10;
  iStack_10 = iStack_10 - (uint)bVar1;
  if (local_12 != 0 || iStack_10 != 0) {
    buf_00.seg = param_5;
    buf_00.ofs = param_4;
    ovr_stshRead(param_3,buf_00,CONCAT22(iStack_10,local_12));
    OVC43_6fbe_0000((undefined4)(void far *)MK_FP(unaff_SS,(uint16_t)&local_12),
                  (int *)(void far *)MK_FP(param_4,param_3),
                  (int *)(void far *)MK_FP(param_2,param_1));
  }
  return;
}



/* 6fbe:01a9 */

char __cdecl16far
OVC43_6fbe_01a9(uint16_t param_1,undefined2 param_2,undefined2 param_3,byte param_4)

{
  uint16_t uVar1;
  uint16_t pcVar2;
  int iVar3;
  uint uVar4;
  uint16_t unaff_SS;
  void *pvVar5;
  ulong uVar6;
  far_t buf;
  far_t handle;
  undefined1 local_88 [4];
  int iStack_84;
  int iStack_82;
  char cStack_7;
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  buf.seg = unaff_SS;
  buf.ofs = (uint16_t)local_88;
  ovr_stshRead(param_1,buf,0x80);
  if (iStack_84 != -0x50ef) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x47);
  }
  pvVar5 = ovr_stshAlloc(0xfa0f);
  DAT_2000_d0fb = (uint16_t)((ulong)pvVar5 >> 0x10);
  DAT_2000_d0f9 = (uint16_t)(pvVar5);
  OVC43_6fbe_013a(param_2,param_3,param_1,DAT_2000_d0f9,DAT_2000_d0fb);
  ovr_init2_3338_0401();
  uStack_4 = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
  uStack_6 = *(undefined2 *)(BDA_DailyTimeCounter.ofs);
  cStack_7 = '\0';
  for (uVar4 = 0; uVar4 < iStack_82 - 1U; uVar4 = uVar4 + 1) {
    do {
      uVar1 = ovr_biosKeyAvail();
      if ((char)uVar1 != '\0') {
        pcVar2 = ovr_gameProcessKey();
        if (pcVar2 == 0x11b) {
          cStack_7 = '\x02';
        }
        if (pcVar2 == 0x1c0d) {
          cStack_7 = '\x01';
        }
      }
      iVar3 = ovr_init2_3338_0415();
      if (((iVar3 != 0) || (DAT_2000_ccaf != '\0')) && (cStack_7 = '\x01', DAT_2000_ccaf != '\0')) {
        cStack_7 = '\x02';
      }
      if (cStack_7 != '\0') goto LAB_6fbe_02c7;
      uVar6 = ovr_attact_3f0b_082f(CONCAT22(uStack_4,uStack_6));
    } while (((int)(uVar6 >> 0x10) == 0) && ((uint)uVar6 < (uint)param_4));
    uStack_4 = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
    uStack_6 = *(undefined2 *)(BDA_DailyTimeCounter.ofs);
LAB_6fbe_02c7:
    if (cStack_7 != '\0') break;
    OVC43_6fbe_013a(param_2,param_3,param_1,DAT_2000_d0f9,DAT_2000_d0fb);
  }
  TextBlitDstSeg = 0xa000;
  handle.seg = DAT_2000_d0fb;
  handle.ofs = (uint16_t)DAT_2000_d0f9;
  ovr_stshFree(handle);
  return cStack_7;
}



/* 6fbe:0322 */

void __cdecl16far
OVC43_6fbe_0322(undefined4 param_1,undefined2 param_2,undefined2 param_3,undefined1 param_4)

{
  undefined1 extraout_AH;
  undefined2 unaff_BP;
  
  ovr_stshSeek(StshStrongDatHnd,CONCAT22(unaff_BP,*(undefined2 *)((int)param_1 + 3)));
  OVC43_6fbe_01a9(StshStrongDatHnd,param_2,param_3,CONCAT11(extraout_AH,param_4));
  return;
}



/* 6fbe:035f */

undefined1 __cdecl16far OVC43_6fbe_035f(uint16_t param_1,undefined2 param_2,undefined2 param_3)

{
  undefined1 uVar1;
  uint16_t file_id;
  
  file_id = ovr_stshOpen(param_1);
  if (*(int *)((char *)"toymaker" + 7 + file_id * 2) < 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = OVC43_6fbe_01a9(file_id,param_2,param_3,4);
    ovr_stshClose(file_id);
  }
  return uVar1;
}


