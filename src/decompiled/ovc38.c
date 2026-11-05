/*
 * ovc38.c - recovered from STRONG.EXE
 * memory block: OVC38
 * range: 68ac:0000 - 68ac:05ef
 * functions: 6
 */
#include "recovered.h"


/* 68ac:0000 */

void __cdecl16far OVC38_68ac_0000(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  int iVar5;
  char *pcVar6;
  char local_52 [80];
  
  pcVar6 = ovr_stsprintf(local_52,"%shigh.txt",(char *)&GWorkDir);
  uVar3 = (undefined2)((ulong)pcVar6 >> 0x10);
  iVar1 = ovr_open_wait_unlock_and_disk((char *)pcVar6);
  if (iVar1 < 0) {
    for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
      puVar4 = (undefined2 *)((int)param_1 + iVar1 * 4);
      puVar4[1] = 0;
      *puVar4 = 0;
    }
  }
  else {
    for (iVar5 = 0; iVar5 < 6; iVar5 = iVar5 + 1) {
      uVar2 = ovr_saveui_4528_1104(iVar1);
      puVar4 = (undefined2 *)((int)param_1 + iVar5 * 4);
      puVar4[1] = uVar3;
      *puVar4 = uVar2;
    }
    close(iVar1);
  }
  return;
}



/* 68ac:008a */

void __cdecl16far OVC38_68ac_008a(undefined4 param_1)

{
  int handle;
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  char *pcVar4;
  char local_52 [80];
  
  pcVar4 = ovr_stsprintf(local_52,"%shigh.txt",(char *)&GWorkDir);
  handle = ovr_creat_wait_unlock_and_disk((char *)pcVar4);
  if (-1 < handle) {
    for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
      uVar3 = (undefined2)(far_to_u32(param_1) >> 0x10);
      piVar1 = (int *)((int)param_1 + iVar2 * 4);
      if (*piVar1 != 0 || piVar1[1] != 0) {
        ovr_saveui_4528_10c5();
      }
    }
    close(handle);
  }
  return;
}



/* 68ac:00fd */

void __cdecl16far OVC38_68ac_00fd(far_t param_1)

{
  int *piVar1;
  uint16_t *puVar2;
  int iVar3;
  far_t handle;
  
  for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
    piVar1 = (int *)(param_1.ofs + iVar3 * 4);
    if (*piVar1 != 0 || piVar1[1] != 0) {
      puVar2 = (uint16_t *)(param_1.ofs + iVar3 * 4);
      handle.seg = puVar2[1];
      handle.ofs = *puVar2;
      ovr_stshFree(handle);
    }
  }
  ovr_stshFree(param_1);
  return;
}



/* 68ac:0148 */

void __cdecl16far OVC38_68ac_0148(void)

{
  far_t items;
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  uint16_t unaff_SS;
  undefined1 local_82 [28];
  char *pcStack_66;
  char *pcStack_64;
  char local_5a [80];
  void *pvStack_a;
  undefined4 uStack_6;
  
  pvStack_a = ovr_stshAlloc(0x18);
  OVC38_68ac_0000((void *)pvStack_a,(char)((ulong)pvStack_a >> 0x10));
  ovr_saveui_4528_0533();
  TextBlitX = 0x16;
  TextBlitY = 0xb;
  ovr_blitText("Great Achievements",(byte *)Font03.ofs,0xde,0x7);
  TextBlitX = 0x16;
  TextBlitY = 0x1a;
  ovr_blitText("Name",(byte *)Font03.ofs,0xde,0x7);
  TextBlitX = 0xae;
  ovr_blitText("Enemies",(byte *)Font03.ofs,0xde,0x7);
  for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
    TextBlitX = 0x16;
    TextBlitY = iVar3 * 0xf + 0x2a;
    uVar4 = (undefined2)((ulong)pvStack_a >> 0x10);
    piVar1 = (int *)((int)(void *)pvStack_a + iVar3 * 4);
    if (*piVar1 != 0 || piVar1[1] != 0) {
      piVar1 = (int *)((int)(void *)pvStack_a + iVar3 * 4);
      iVar2 = 0;
      uStack_6 = (char *)CONCAT22(piVar1[1],(char *)(*piVar1 + 1));
      while (((iVar2 < 0x4f && (*uStack_6 != '@')) && (*uStack_6 != '\0'))) {
        local_5a[iVar2] = *uStack_6;
        iVar2 = iVar2 + 1;
        uStack_6 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(char *)uStack_6 + 1);
      }
      local_5a[iVar2] = '\0';
      ovr_blitText((char *)CONCAT22(unaff_SS,local_5a),(byte *)Font03.ofs,0xde,0x8);
      TextBlitX = 0xc2;
      if (*uStack_6 == '@') {
        uStack_6 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(char *)uStack_6 + 1);
      }
      ovr_blitText(uStack_6,(byte *)Font03.ofs,0xde,0x8);
    }
  }
  _fmemset((undefined1 *)CONCAT22(unaff_SS,local_82),0,0x28);
  pcStack_64 = (char *)"puppetmaker" + 3;
  pcStack_66 = (char *)"Done";
  items.seg = unaff_SS;
  items.ofs = (uint16_t)local_82;
  ovr_uiMenu((char *)0x0,items,8);
  OVC38_68ac_00fd((void *)pvStack_a,(char)((ulong)pvStack_a >> 0x10));
  ovr_saveui_4528_0533();
  return;
}



/* 68ac:0339 */

int __cdecl16far OVC38_68ac_0339(byte *param_1,byte *param_2)

{
  byte bVar3;
  int iVar1;
  uint uVar2;
  uint uVar4;
  
  bVar3 = (byte)(((uint)(byte *)param_2 | (*(uint16_t *)((uint8_t *)&(param_2) + 2))) >> 8);
  if (((uint)(byte *)param_2 | (*(uint16_t *)((uint8_t *)&(param_2) + 2))) == 0) {
    iVar1 = 0;
  }
  else if (*param_1 < *param_2) {
    iVar1 = CONCAT11(bVar3,1);
  }
  else if (*param_2 < *param_1) {
    iVar1 = (uint)bVar3 << 8;
  }
  else {
    while ((*param_2 != 0 && (*param_2 != 0x40))) {
      param_2 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(param_2) + 2)),(byte *)param_2 + 1);
    }
    if (*param_2 == 0x40) {
      param_2 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(param_2) + 2)),(byte *)param_2 + 1);
    }
    uVar2 = (uint)(char)*param_2;
    uVar4 = 0;
    if ((((byte *)_ctype + 1)[uVar2] & 2) != 0) {
      bVar3 = *param_2;
      param_2 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(param_2) + 2)),(byte *)param_2 + 1);
      uVar2 = (uint)(char)*param_2;
      uVar4 = (int)(char)bVar3 - 0x30U;
      if ((((byte *)_ctype + 1)[uVar2] & 2) != 0) {
        uVar2 = (((int)(char)bVar3 - 0x30U) * 10 + (int)(char)*param_2) - 0x30;
        uVar4 = uVar2;
      }
    }
    bVar3 = (byte)(uVar2 >> 8);
    if (DAT_2410_6a86 < uVar4) {
      iVar1 = CONCAT11(bVar3,1);
    }
    else {
      iVar1 = (uint)bVar3 << 8;
    }
  }
  return iVar1;
}



/* 68ac:03fc */

void __cdecl16far OVC38_68ac_03fc(void)

{
  undefined2 uVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  undefined2 *puVar5;
  void *pvVar6;
  far_t handle;
  char local_d0 [200];
  void *pvStack_8;
  undefined2 uStack_6;
  byte bStack_3;
  
  if ((DAT_2410_6a88 == '\0') && (bStack_3 = ovr_manage_4d05_1b1d(), bStack_3 != 0xff)) {
    pvVar6 = ovr_stshAlloc(0x18);
    pvStack_8 = (void *)pvVar6;
    uStack_6 = (undefined2)((ulong)pvVar6 >> 0x10);
    OVC38_68ac_0000(pvStack_8);
    if (*(int *)((int)pvStack_8 + 0x14) != 0 || *(int *)((int)pvStack_8 + 0x16) != 0) {
      handle.seg = *(uint16_t *)((int)pvStack_8 + 0x16);
      handle.ofs = *(uint16_t *)((int)pvStack_8 + 0x14);
      ovr_stshFree(handle);
    }
    ovr_manage_4d05_03a4
              (*(undefined2 *)((uint)bStack_3 * 4),((undefined2 *)((uint)bStack_3 * 4))[1],
               *(undefined2 *)((uint)bStack_3 * 4),((undefined2 *)((uint)bStack_3 * 4))[1]);
    _sprintf(local_d0);
    iVar4 = 5;
    while ((0 < iVar4 && (cVar2 = OVC38_68ac_0339(local_d0), cVar2 == '\0'))) {
      uVar1 = *(undefined2 *)((int)pvStack_8 + iVar4 * 4 + -4);
      puVar5 = (undefined2 *)((int)pvStack_8 + iVar4 * 4);
      puVar5[1] = *(undefined2 *)((int)pvStack_8 + iVar4 * 4 + -2);
      *puVar5 = uVar1;
      iVar4 = iVar4 + -1;
    }
    sVar3 = strlen(local_d0);
    pvVar6 = ovr_stshAlloc((ulong)(sVar3 + 1));
    puVar5 = (undefined2 *)((int)pvStack_8 + iVar4 * 4);
    puVar5[1] = (int)((ulong)pvVar6 >> 0x10);
    *puVar5 = (void *)pvVar6;
    strcpy((char *)*(undefined2 *)((int)pvStack_8 + iVar4 * 4),local_d0);
    OVC38_68ac_008a(pvStack_8,uStack_6);
    OVC38_68ac_00fd(pvStack_8,uStack_6);
    DAT_2410_6a88 = '\x01';
  }
  return;
}


