/*
 * ovc50.c - recovered from STRONG.EXE
 * memory block: OVC50
 * range: 8adb:0000 - 8adb:017f
 * functions: 3
 */
#include "recovered.h"


/* 8adb:0000 */

void __cdecl16far OVC50_8adb_0000(char *param_1,undefined2 param_2)

{
  uint uVar1;
  size_t sVar2;
  
  TextBlitY = 0xc;
  while( true ) {
    TextBlitX = 0x13;
    if (199 < TextBlitY + 9) {
      TextBlitX = 0x13;
      return;
    }
    uVar1 = ovr_blitText((char *)CONCAT22(param_2,param_1),(byte *)Font03.ofs,0xd7,0xed);
    sVar2 = strlen(param_1);
    if (sVar2 <= uVar1) break;
    param_1 = param_1 + uVar1;
    TextBlitY = TextBlitY + 0xb;
  }
  return;
}



/* 8adb:0083 */

void __cdecl16far OVC50_8adb_0083(byte param_1)

{
  int iVar1;
  undefined4 uVar2;
  stg_tmp_t *psVar3;
  far_t handle;
  undefined2 uStack_4;
  
  handle.seg = *(uint16_t *)((uint)param_1 * 4 + -0x6c6e);
  handle.ofs = *(uint16_t *)((uint)param_1 * 4 + -0x6c70);
  psVar3 = ovr_stshLoadGfx(handle);
  uVar2 = *(undefined4 *)((uint)param_1 * 4 + -0x6c70);
  iVar1 = *(int *)((int)uVar2 + 5);
  uStack_4 = (undefined2)((ulong)psVar3 >> 0x10);
  if (iVar1 != 0) {
    ((stg_tmp_t *)psVar3)->cmap[iVar1 + -1] = 0x0;
    OVC50_8adb_0000((stg_tmp_t *)psVar3,uStack_4);
  }
  return;
}



/* 8adb:00f1 */

void __cdecl16far OVC50_8adb_00f1(void)

{
  undefined1 extraout_AH;
  uint8_t local_2a [37];
  char cStack_5;
  char cStack_4;
  char cStack_3;
  
  F_SCOPY(local_2a,(uint8_t *)(far_t *)far_t_ARRAY_2410_84a8,0x24);
  cStack_5 = '\0';
  do {
    ovr_manage_4d05_0081();
    OVC50_8adb_0083(CONCAT11(extraout_AH,cStack_5));
    cStack_3 = ovr_uiInputText(local_2a);
    if ((cStack_3 == '\t') || (cStack_3 == '\0')) {
      cStack_4 = '\x01';
    }
    else {
      cStack_4 = '\0';
      cStack_5 = cStack_3 + -1;
    }
  } while (cStack_4 == '\0');
  return;
}


