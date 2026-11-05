/*
 * ovc41.c - recovered from STRONG.EXE
 * memory block: OVC41
 * range: 6a8f:0000 - 6a8f:2eaf
 * functions: 37
 */
#include "recovered.h"


/* 6a8f:0000 */

undefined2 __cdecl16far OVC41_6a8f_0000(int param_1)

{
  undefined2 uVar1;
  
  if (param_1 == 1) {
    uVar1 = 0x6e74;
  }
  else {
    uVar1 = 0x6e75;
  }
  return uVar1;
}



/* 6a8f:0017 */

undefined2 __cdecl16far OVC41_6a8f_0017(int param_1)

{
  undefined2 uVar1;
  
  if (param_1 == 1) {
    uVar1 = 0x6e74;
  }
  else {
    uVar1 = 0x6e75;
  }
  return uVar1;
}



/* 6a8f:002e */

void __cdecl16far OVC41_6a8f_002e(undefined4 param_1)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  undefined2 uVar7;
  byte bStack_7;
  
  uVar7 = (undefined2)((ulong)param_1 >> 0x10);
  iVar6 = (int)param_1;
  bStack_7 = *(byte *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)*(byte *)(iVar6 + 0xd) * 0x95)
  ;
  if (bStack_7 == 0xff) {
    bStack_7 = 0;
  }
  piVar3 = (int *)((uint)bStack_7 * 0x94 + (uint)*(byte *)(iVar6 + 0xf) * 4);
  if (*piVar3 == 0 && piVar3[1] == 0) {
    iVar4 = (uint)bStack_7 * 0x94 + (uint)*(byte *)(iVar6 + 0xf) * 4;
    uVar1 = *(uint *)(iVar4 + -4);
    *(int *)(iVar6 + 0x12) = *(int *)(iVar4 + -2) + (uint)(0xfffe < uVar1);
    *(int *)(iVar6 + 0x10) = uVar1 + 1;
  }
  else {
    puVar5 = (uint *)((uint)bStack_7 * 0x94 + (uint)*(byte *)(iVar6 + 0xf) * 4);
    uVar1 = puVar5[1];
    if ((uVar1 <= *(uint *)(iVar6 + 0x12)) &&
       ((uVar1 != *(uint *)(iVar6 + 0x12) || (*puVar5 <= *(uint *)(iVar6 + 0x10))))) {
      puVar5 = (uint *)((uint)bStack_7 * 0x94 + (uint)*(byte *)(iVar6 + 0xf) * 4);
      uVar1 = *puVar5;
      *(int *)(iVar6 + 0x12) = puVar5[1] + (uint)(0xfffe < uVar1);
      *(int *)(iVar6 + 0x10) = uVar1 + 1;
      *(char *)(iVar6 + 0xf) = *(char *)(iVar6 + 0xf) + '\x01';
      cVar2 = ovr_OVC15_4207_25dd(iVar6,uVar7);
      *(char *)(iVar6 + 0x31) = *(char *)(iVar6 + 0x31) + cVar2;
      *(char *)(iVar6 + 0x32) = *(char *)(iVar6 + 0x32) + cVar2;
    }
  }
  return;
}



/* 6a8f:016b */

void __cdecl16far
OVC41_6a8f_016b(undefined2 param_1,undefined2 param_2,byte param_3,undefined4 param_4)

{
  uint *puVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  long lVar9;
  
  if (param_3 != 0) {
    uVar8 = (undefined2)((ulong)param_4 >> 0x10);
    iVar7 = (int)param_4;
    uVar5 = 0x195d;
    if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)*(byte *)(iVar7 + 0xd) * 0x95) !=
        -1) {
      uVar3 = OVC41_6a8f_29ea(param_1,param_2);
      lVar9 = LXMUL_at_((ulong)param_3,CONCAT22(uVar5,uVar3));
      iVar6 = (int)((ulong)lVar9 >> 0x10);
      uVar4 = ovr_OVC15_4207_26bc(iVar7,uVar8,lVar9);
      puVar1 = (uint *)(iVar7 + 0x10);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + uVar4;
      *(int *)(iVar7 + 0x12) = *(int *)(iVar7 + 0x12) + iVar6 + (uint)CARRY2(uVar2,uVar4);
      OVC41_6a8f_002e(iVar7,uVar8);
    }
  }
  return;
}



/* 6a8f:01e7 */

void __cdecl16far OVC41_6a8f_01e7(undefined4 param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined2 unaff_BP;
  undefined2 uVar3;
  
  if (DebugVerbose) {
    printf("kill 4\r",unaff_BP);
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  uVar2 = *(undefined4 *)((int)param_1 + 0x17);
  if (*(char *)((int)uVar2 + 0xe) != '\0') {
    uVar2 = *(undefined4 *)((int)param_1 + 0x17);
    pcVar1 = (char *)((int)uVar2 + 0xe);
    *pcVar1 = *pcVar1 + -1;
  }
  DAT_2000_d0f5 = 1;
  return;
}



/* 6a8f:0229 */

void __cdecl16far OVC41_6a8f_0229(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  if ((*(uint *)((int)param_1 + 0x2b) & 0xae4) == 0) {
    OVC41_6a8f_01e7((int)param_1,uVar1);
  }
  return;
}



/* 6a8f:0246 */

void __cdecl16far OVC41_6a8f_0246(undefined4 param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)((int)param_1 + 0x17);
  pcVar1 = (char *)((int)uVar2 + 0xe);
  *pcVar1 = *pcVar1 + '\x01';
  return;
}



/* 6a8f:0256 */

void __cdecl16far OVC41_6a8f_0256(uint param_1,int param_2)

{
  char *pcVar1;
  undefined2 uVar2;
  uint *puVar3;
  int iVar4;
  bool bVar5;
  uint uVar6;
  undefined4 uStack_8;
  
  uVar2 = *(undefined2 *)(param_1 * 0x34 + 0x19);
  puVar3 = (uint *)*(int *)(param_1 * 0x34 + 0x17);
  uStack_8 = (uint *)CONCAT22(uVar2,puVar3);
  iVar4 = *(int *)(param_1 * 0x34 + 0x1b);
  ovr_agnt_3b1d_15bd(param_1 + 1);
  bVar5 = false;
  for (uVar6 = 0; (int)uVar6 < (int)(uint)AgntCount; uVar6 = uVar6 + 1) {
    if ((uVar6 != param_1) && (*(int *)(uVar6 * 0x34 + 0x1b) == iVar4)) {
      bVar5 = true;
    }
    if (*(char *)(uVar6 * 0x34 + 0xc) != -1) {
      if ((int)param_1 < (int)(uint)*(byte *)(uVar6 * 0x34 + 0xc)) {
        pcVar1 = (char *)(uVar6 * 0x34 + 0xc);
        *pcVar1 = *pcVar1 + -1;
      }
      else if (*(byte *)(uVar6 * 0x34 + 0xc) == param_1) {
        *(undefined1 *)(uVar6 * 0x34 + 0xc) = 0xff;
      }
    }
  }
  if ((int)(param_1 + 1) < (int)(uint)AgntCount) {
    _fmemmove((uint8_t *)(param_1 * 0x34),(uint8_t *)(param_1 * 0x34 + 0x34),
              ((AgntCount - param_1) + -1) * 0x34);
  }
  AgntCount = AgntCount - 1;
  if ((((param_2 != 0) && (!bVar5)) && (puVar3[1] == GfxRndSeed2)) &&
     ((GfxRndSeed - 2U <= *uStack_8 && (GfxRndSeed - 2U <= *uStack_8)))) {
    puVar3[4] = puVar3[2];
    uVar6 = puVar3[3];
    puVar3[5] = uVar6;
    ovr_attact_3f0b_2430(puVar3,uVar2,CONCAT11((char)(uVar6 >> 8),(char)puVar3[6]));
  }
  return;
}



/* 6a8f:0422 */

undefined2 __cdecl16far OVC41_6a8f_0422(byte param_1,int param_2)

{
  byte bVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  
  if (((undefined1 *)&DAT_2000_d1de)[param_1] == -1) {
    uVar3 = 0x6e74;
  }
  else {
    uVar2 = *(undefined4 *)((uint)(byte)((undefined1 *)&DAT_2000_d1de)[param_1] << 2);
    bVar1 = *(byte *)((int)uVar2 + 0x2f);
    if (param_2 == 1) {
      uVar3 = *(undefined2 *)((uint)bVar1 * 4 + 0x123);
    }
    else {
      uVar3 = *(undefined2 *)((uint)bVar1 * 4 + 0x107);
    }
  }
  return uVar3;
}



/* 6a8f:04a9 */

char * __cdecl16far OVC41_6a8f_04a9(int param_1)

{
  char *pcVar1;
  
  if (param_1 == 1) {
    pcVar1 = (char *)"is";
  }
  else {
    pcVar1 = (char *)"are";
  }
  return pcVar1;
}



/* 6a8f:04c0 */

void __cdecl16far OVC41_6a8f_04c0(byte param_1)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  char *pcVar4;
  uint uVar5;
  char *arg1;
  char *txt;
  undefined2 dst;
  char local_7e [121];
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  pcVar4 = (char *)"puppetmaker" + 3;
  if (((undefined1 *)&DAT_2000_d1de)[param_1] != -1) {
    arg1 = (char *)0x0;
    for (uVar5 = 0; uVar5 < AgntCount; uVar5 = uVar5 + 1) {
      pcVar4 = (char *)0x1726;
      uVar1 = *(undefined4 *)(uVar5 * 0x34 + 0x17);
      if (((undefined1 *)&DAT_2000_d1de)[param_1] == *(char *)((int)uVar1 + 0x1a)) {
        arg1 = arg1 + 1;
      }
    }
    ovr_attact_3f0b_2252(CONCAT11((char)((uint)&local_3 >> 8),param_1),&local_3);
    dst = 0xa000;
    uVar2 = OVC41_6a8f_04a9(arg1,local_5,local_4);
    puVar3 = (undefined2 *)((uint)(byte)((undefined1 *)&DAT_2000_d1de)[param_1] * 4);
    OVC41_6a8f_0000(arg1,*puVar3,puVar3[1],uVar2,pcVar4);
    txt = ovr_stsprintf(local_7e,
                        "The %d unit%s loyal to %s %s %d%% recruiting, %d%% training, and %d%% building."
                        ,arg1);
    ovr_drawTextAt(txt,dst);
  }
  return;
}



/* 6a8f:05ad */

void __cdecl16far OVC41_6a8f_05ad(void)

{
  int iVar1;
  int iVar2;
  
  if (DebugVerbose) {
    for (iVar2 = 0; iVar2 < 10; iVar2 = iVar2 + 1) {
      for (iVar1 = 0; iVar1 < 0x69; iVar1 = iVar1 + 1) {
        *(char *)(iVar2 * 0x140 + iVar1 + -0x1280) = *(char *)(iVar2 * 0x69 + iVar1 + 0x8fa) + '@';
      }
    }
    for (iVar2 = 0; iVar2 < 10; iVar2 = iVar2 + 1) {
      for (iVar1 = 0; iVar1 < 0x69; iVar1 = iVar1 + 1) {
        *(char *)(iVar2 * 0x140 + iVar1 + -0x120d) = *(char *)(iVar2 * 0x69 + iVar1 + 0x4e0) + '@';
      }
    }
  }
  return;
}



/* 6a8f:063f */

undefined2 __cdecl16far OVC41_6a8f_063f(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_2 >> 0x10);
  iVar2 = (int)param_2;
  if (*(char *)(iVar2 + 0x24) == '\x02') {
    uVar3 = 0;
  }
  else {
    if (((int)param_1 != 0 || (*(uint16_t *)((uint8_t *)&(param_1) + 2)) != 0) &&
       (*(char *)*(undefined4 *)((int)param_1 + 0x1d) == *(char *)((int)param_1 + 0x2f))) {
      OVC41_6a8f_016b(*(undefined2 *)(iVar2 + 0x17),*(undefined2 *)(iVar2 + 0x19),1,
                      *(undefined2 *)((int)param_1 + 0x17),*(undefined2 *)((int)param_1 + 0x19));
    }
    if ((((*(char *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xe) == '\0') ||
         ((uint)*(byte *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xe) % 0x10 == 1)) ||
        ((*(uint *)(iVar2 + 0x2b) & 0xae4) != 0)) ||
       ((*(uint *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x3e) & 4) != 0)) {
      *(undefined1 *)(iVar2 + 0x21) = 0;
      *(undefined1 *)(iVar2 + 0x23) = 10;
      *(undefined1 *)(iVar2 + 0x24) = 2;
      *(undefined2 *)(iVar2 + 6) = 0;
    }
    else {
      *(undefined1 *)(iVar2 + 0x21) = *(undefined1 *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x3b);
      *(undefined1 *)(iVar2 + 0x23) = 6;
      *(undefined1 *)(iVar2 + 0x24) = 1;
      *(undefined2 *)(iVar2 + 6) = 0;
    }
    ovr_agnt_3b1d_0a53(iVar2,uVar3);
    iVar1 = *(int *)(iVar2 + 0x1b) * 0x37;
    ovr_OVC25_5b66_173b(CONCAT11((char)((uint)iVar1 >> 8),
                                 *(undefined1 *)(Entities.ofs + iVar1 + 0x1a)));
    if ((*(uint *)(iVar2 + 0x2b) & 0xae4) == 0) {
      OVC41_6a8f_01e7(iVar2,uVar3);
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}



/* 6a8f:076f */

void __cdecl16far OVC41_6a8f_076f(void)

{
  uint *puVar1;
  uint16_t unk;
  int iVar2;
  
  if (AgntFlag1) {
    for (iVar2 = 0; iVar2 < (int)(uint)AgntCount; iVar2 = iVar2 + 1) {
      if ((*(uint *)(iVar2 * 0x34 + 0x2b) & 0x800) == 0) {
        OVC41_6a8f_0229(iVar2 * 0x34,0x1726);
        puVar1 = (uint *)(iVar2 * 0x34 + 0x2b);
        *puVar1 = *puVar1 | 0x800;
        unk = ovr_audio_3a5b_0afd(iVar2 * 0x34,0x1726);
        ovr_play_sfxU(0x1b,0,unk);
        ovr_attact_3f0b_26bd();
        return;
      }
    }
  }
  return;
}



/* 6a8f:0807 */

void __cdecl16far OVC41_6a8f_0807(int param_1)

{
  byte bVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uStack_6;
  
  piVar3 = (int *)(param_1 * 0x34);
  uStack_6 = (int *)CONCAT22(0x1726,piVar3);
  if ((*(uint *)((int)*(undefined4 *)((int)piVar3 + 0x1d) + 0x3e) & 4) != 0) {
    for (iVar6 = 0; iVar6 < (int)(uint)AgntCount; iVar6 = iVar6 + 1) {
      if ((iVar6 != param_1) &&
         (uVar4 = *uStack_6 - *(int *)(iVar6 * 0x34), uVar5 = (int)uVar4 >> 0xf,
         (int)((uVar4 ^ uVar5) - uVar5) < 0x32)) {
        bVar1 = ovr_manage_4d05_01a3(6,6);
        uVar4 = (uint)bVar1;
        cVar2 = ovr_OVC27_5ded_1c94(iVar6 * 0x34,0x1726,1);
        if (cVar2 != '\0') {
          uVar4 = (int)uVar4 >> 1;
        }
        OVC41_6a8f_1c74(piVar3,0x1726,iVar6 * 0x34,0x1726,uVar4);
      }
    }
  }
  return;
}



/* 6a8f:08c2 */

void __cdecl16far OVC41_6a8f_08c2(int param_1)

{
  uint uVar1;
  undefined2 unaff_SS;
  int iStack_c;
  int local_a [4];
  
  F_SCOPY((uint8_t *)local_a,(uint8_t *)0x6e00,8);
  uVar1 = (uint)*(byte *)(param_1 * 0x34 + 0xc);
  iStack_c = *(int *)(param_1 * 0x34 + 6);
  if (2 < iStack_c) {
    iStack_c = 3;
  }
  if (*(char *)(param_1 * 0x34 + 0xf) == '\0') {
    *(int *)(uVar1 * 0x34) = *(int *)(param_1 * 0x34) + local_a[iStack_c];
  }
  else {
    *(int *)(uVar1 * 0x34) = *(int *)(param_1 * 0x34) - local_a[iStack_c];
  }
  if (0xd2 < *(int *)(uVar1 * 0x34)) {
    *(undefined2 *)(uVar1 * 0x34) = 0xd2;
  }
  if (*(int *)(uVar1 * 0x34) < 0) {
    *(undefined2 *)(uVar1 * 0x34) = 0;
  }
  *(undefined2 *)(uVar1 * 0x34 + 2) = *(undefined2 *)(param_1 * 0x34 + 2);
  *(undefined1 *)(uVar1 * 0x34 + 5) = 0;
  *(undefined1 *)(uVar1 * 0x34 + 4) = 0;
  return;
}



/* 6a8f:0a45 */

undefined2 __cdecl16far OVC41_6a8f_0a45(byte param_1,undefined1 param_2)

{
  byte bVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  
  bVar1 = ovr_agnt_3b1d_1bc1(param_2);
  if (bVar1 + 2 < (uint)param_1) {
    uVar2 = CONCAT11((char)(bVar1 + 2 >> 8),0xd);
  }
  else if (bVar1 + 2 == (uint)param_1) {
    uVar2 = CONCAT11((char)(bVar1 + 2 >> 8),0xb);
  }
  else {
    uVar3 = (undefined1)(bVar1 + 1 >> 8);
    if (bVar1 + 1 == (uint)param_1) {
      uVar2 = CONCAT11(uVar3,9);
    }
    else if (bVar1 == param_1) {
      uVar2 = CONCAT11(uVar3,7);
    }
    else {
      uVar2 = CONCAT11(uVar3,2);
    }
  }
  return uVar2;
}



/* 6a8f:0aa7 */

void __cdecl16far OVC41_6a8f_0aa7(byte param_1,undefined1 param_2)

{
  byte bVar1;
  
  bVar1 = ovr_agnt_3b1d_1bc1(param_2);
  if (bVar1 + 1 < param_1 + 0xf) {
    if (bVar1 + 1 < param_1 + 10) {
      ovr_manage_4d05_01a3(2,6);
    }
    else {
      ovr_manage_4d05_01a3(3,6);
    }
  }
  else {
    ovr_manage_4d05_01a3(4,6);
  }
  return;
}



/* 6a8f:0b0a */

int __cdecl16far OVC41_6a8f_0b0a(byte param_1,undefined1 param_2)

{
  byte bVar1;
  byte bVar3;
  int iVar2;
  
  bVar1 = ovr_agnt_3b1d_1bc1(param_2);
  bVar3 = (byte)(param_1 + 4 >> 8);
  if (bVar1 + 1 < param_1 + 4) {
    iVar2 = (uint)bVar3 << 8;
  }
  else {
    iVar2 = CONCAT11(bVar3,1);
  }
  return iVar2;
}



/* 6a8f:0b39 */

undefined2 __cdecl16far OVC41_6a8f_0b39(undefined4 param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined2 uVar4;
  char *pcVar5;
  uint16_t uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined2 uVar10;
  char *pcVar11;
  undefined1 local_aa [80];
  char local_5a [80];
  int iStack_a;
  undefined2 uStack_8;
  byte bStack_6;
  char cStack_5;
  char cStack_4;
  char cStack_3;
  
  uVar10 = (undefined2)((ulong)param_1 >> 0x10);
  iVar7 = (int)param_1;
  if ((*(uint *)(iVar7 + 0x2b) & 2) == 0) {
    uVar10 = 0;
  }
  else {
    *(undefined1 *)(iVar7 + 0x10) = 0;
    *(uint *)(iVar7 + 0x2b) = *(uint *)(iVar7 + 0x2b) & 0xfffd;
    if (*(char *)(iVar7 + 0xc) == -1) {
      uVar10 = 0;
    }
    else {
      iStack_a = (uint)*(byte *)(iVar7 + 0xc) * 0x34;
      uStack_8 = 0x1726;
      bStack_6 = *(byte *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x42);
      if (bStack_6 == 0) {
        uVar10 = 0;
      }
      else {
        uVar4 = ovr_manage_4d05_01a3();
        bVar3 = OVC41_6a8f_0a45(*(undefined1 *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x42));
        if ((byte)uVar4 < bVar3) {
          uVar6 = DAT_2000_d0f7;
          uVar10 = ovr_agnt_3b1d_0ac0(iVar7,uVar10,local_aa);
          pcVar5 = (char *)ovr_OVC15_4207_1c16(uVar10);
          pcVar11 = ovr_stsprintf(local_5a,"%s fails to turn.",pcVar5);
          ovr_uiNotify(pcVar11,uVar6);
          ovr_agnt_3b1d_0a53();
          uVar10 = 1;
        }
        else {
          bVar3 = OVC41_6a8f_0aa7();
          uVar9 = (uint)bVar3;
          cStack_4 = OVC41_6a8f_0b0a();
          cStack_5 = '\0';
          iVar8 = 0;
          while ((iVar8 < (int)(uint)AgntCount && (uVar9 != 0))) {
            uVar2 = *(undefined4 *)(iVar8 * 0x34 + 0x1d);
            if (((*(char *)((int)uVar2 + 0x42) != '\0') &&
                ((((*(char *)(iVar8 * 0x34 + 0x2f) != *(char *)(iVar7 + 0x2f) &&
                   ((*(uint *)(iVar8 * 0x34 + 0x2b) & 4) == 0)) &&
                  (*(char *)(iVar8 * 0x34 + 0x24) == '\0')) &&
                 ((cStack_5 == '\0' ||
                  (uVar2 = *(undefined4 *)(iVar8 * 0x34 + 0x17),
                  (int)(uint)*(byte *)((int)uVar2 + 0xf) <= (int)uVar9)))))) &&
               (uVar2 = *(undefined4 *)(iVar8 * 0x34 + 0x1d),
               *(byte *)((int)uVar2 + 0x42) <= bStack_6)) {
              if ((*(uint *)(iVar8 * 0x34 + 0x2b) & 0xae4) == 0) {
                uVar2 = *(undefined4 *)(iVar8 * 0x34 + 0x17);
                cStack_3 = *(char *)((int)uVar2 + 0xe);
              }
              else {
                cStack_3 = '\x01';
              }
              while ((cStack_3 != '\0' && (uVar9 != 0))) {
                if (cStack_4 == '\0') {
                  OVC41_6a8f_0229();
                  *(undefined1 *)(iVar8 * 0x34 + 4) = 0;
                  *(undefined1 *)(iVar8 * 0x34 + 5) = 0;
                  puVar1 = (uint *)(iVar8 * 0x34 + 0x2b);
                  *puVar1 = *puVar1 | 4;
                  *(undefined1 *)(iVar8 * 0x34 + 0x24) = 1;
                  *(undefined2 *)(iVar8 * 0x34 + 6) = 0;
                  *(undefined1 *)(iVar8 * 0x34 + 0x23) = 5;
                  ovr_agnt_3b1d_0a53();
                }
                else {
                  OVC41_6a8f_063f(iVar7,uVar10,iVar8 * 0x34,0x1726);
                }
                cStack_5 = cStack_5 + '\x01';
                uVar2 = *(undefined4 *)(iVar8 * 0x34 + 0x17);
                if ((int)uVar9 < (int)(uint)*(byte *)((int)uVar2 + 0xf)) {
                  uVar9 = 0;
                }
                else {
                  uVar2 = *(undefined4 *)(iVar8 * 0x34 + 0x17);
                  uVar9 = uVar9 - *(byte *)((int)uVar2 + 0xf);
                }
                cStack_3 = cStack_3 + -1;
              }
            }
            uVar4 = 0x1726;
            iVar8 = iVar8 + 1;
          }
          if (cStack_5 == '\0') {
            uVar6 = DAT_2000_d0f7;
            uVar10 = ovr_agnt_3b1d_0ac0(iVar7,uVar10,local_aa);
            pcVar5 = (char *)ovr_OVC15_4207_1c16(uVar10);
            pcVar11 = ovr_stsprintf(local_5a,"%s cannot turn.",pcVar5);
            ovr_uiNotify(pcVar11,uVar6);
          }
          else {
            if (cStack_4 == '\0') {
              uVar6 = DAT_2000_d0f7;
              uVar10 = ovr_agnt_3b1d_0ac0(iVar7,uVar10,local_aa);
              pcVar5 = (char *)ovr_OVC15_4207_1c16(uVar10,uVar4);
              pcVar11 = ovr_stsprintf(local_5a,"%s turns %d undead.",pcVar5);
              ovr_uiNotify(pcVar11,uVar6);
            }
            else {
              uVar6 = DAT_2000_d0f7;
              uVar10 = ovr_agnt_3b1d_0ac0(iVar7,uVar10,local_aa);
              pcVar5 = (char *)ovr_OVC15_4207_1c16(uVar10,uVar4);
              pcVar11 = ovr_stsprintf(local_5a,"%s destroys %d undead.",pcVar5);
              ovr_uiNotify(pcVar11,uVar6);
            }
            uVar6 = ovr_audio_3a5b_0afd();
            ovr_play_sfxU(0x3b,0,uVar6);
          }
          ovr_agnt_3b1d_0a53();
          uVar10 = 1;
        }
      }
    }
  }
  return uVar10;
}



/* 6a8f:0fc1 */

void __cdecl16far OVC41_6a8f_0fc1(char param_1)

{
  int iVar1;
  undefined2 uVar2;
  char *msg;
  char local_54 [81];
  byte bStack_3;
  
  iVar1 = *(int *)(GfxRndSeed * 0x78 + (int)DAT_2000_cb0d + GfxRndSeed2 * 2 + -0x78);
  if (0xf7 < iVar1) {
    uVar2 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
    bStack_3 = *(char *)((int)DAT_2000_ca95 + iVar1 * 9) + param_1;
    if (0xf7 < bStack_3) {
      bStack_3 = 0;
    }
    *(byte *)((int)DAT_2000_ca95 + iVar1 * 9) = bStack_3;
    ovr_constr_36ce_1db4();
    msg = ovr_stsprintf(local_54,"Building %d %s.",(char *)(uint)bStack_3);
    ovr_say(msg);
  }
  return;
}



/* 6a8f:108a */

void __cdecl16far dbgPromoteEnemy(void)

{
  uint16_t uVar1;
  uint i;
  uint16_t uVar2;
  char *pcVar3;
  char buf [80];
  
  for (i = 0; i < EntityCount; i = i + 1) {
    uVar2 = Entities.seg;
    uVar1 = Entities.ofs;
    if (((GfxRndSeed - 2U <= *(uint *)(uVar1 + i * 0x37)) &&
        (*(uint *)(uVar1 + i * 0x37) <= GfxRndSeed + 1U)) &&
       (*(int *)(uVar1 + i * 0x37 + 2) == GfxRndSeed2)) {
      pcVar3 = (char *)(uVar1 + i * 0x37 + 0xd);
      *pcVar3 = *pcVar3 + '\x01';
      if (0x29 < *(byte *)(Entities.ofs + i * 0x37 + 0xd)) {
        *(undefined1 *)(Entities.ofs + i * 0x37 + 0xd) = 0;
      }
      pcVar3 = ovr_stsprintf(buf,"Enemy %s.",
                             (char *)*(undefined2 *)
                                      ((int)&AgntGs[0].name +
                                      (uint)*(byte *)(Entities.ofs + i * 0x37 + 0xd) * 0x95));
      ovr_say(pcVar3);
    }
  }
  TextBlitFlag = 0;
  AgntFlag1 = false;
  OVC41_6a8f_11d2();
  return;
}



/* 6a8f:11d2 */

void __cdecl16far OVC41_6a8f_11d2(char param_1)

{
  char cVar1;
  int iVar2;
  
  ovr_draw_2e25_1662();
  ovr_stop_audio();
  if (((param_1 != '\0') && (CFG_Sfx != '1')) && (CFG_Sfx != '4')) {
    ovr_play_sfx(6,0);
  }
  ovr_unit_6616_00d8();
  GOngoingBattle = DAT_2000_ca9b;
  if (DAT_2000_ca9b == '\0') {
    cVar1 = ovr_draw_2e25_15d6();
    if (cVar1 == '\0') {
      GOngoingBattle = '\x01';
    }
  }
  ovr_OVC28_6018_01af();
  ovr_gfxInitRand();
  GGameState = 9;
  if (DebugVerbose != false) {
    printf("%d \r",9);
  }
  ovr_font_302d_0a30();
  GGameState = 10;
  if (DebugVerbose != false) {
    printf("%d \r",10);
  }
  ovr_agnt_clear();
  GGameState = 0xb;
  if (DebugVerbose != false) {
    printf("%d \r",0xb);
  }
  ovr_constr_36ce_1efc();
  GGameState = 0xc;
  if (DebugVerbose != false) {
    printf("%d \r",0xc);
  }
  ovr_attact_3f0b_05df();
  GGameState = 0xd;
  if (DebugVerbose != false) {
    printf("%d \r",0xd);
  }
  TextBlitDstSeg = 0xa000;
  if (GameRunning == false) {
    for (iVar2 = 0; iVar2 < 5; iVar2 = iVar2 + 1) {
      ovr_draw_2e25_0efd(iVar2);
      ovr_draw_2e25_0000();
    }
    GGameState = 0xe;
    if (DebugVerbose != false) {
      printf("%d \r",0xe);
    }
  }
  GGameState = 0xf;
  if (DebugVerbose != false) {
    printf("%d \r",0xf);
  }
  ovr_OVC18_48ac_0051();
  GGameState = 0x10;
  if (DebugVerbose != false) {
    printf("%d \r",0x10);
  }
  OVC41_6a8f_1a4c();
  GGameState = 0x11;
  if (DebugVerbose != false) {
    printf("%d \r",0x11);
  }
  if (DAT_2000_d1ae == '\0') {
    OVC41_6a8f_1aa1(8);
  }
  GGameState = 0x12;
  if (DebugVerbose != false) {
    printf("%d \r",0x12);
  }
  GGameState = 0x13;
  if (DebugVerbose != false) {
    printf("%d \r",0x13);
  }
  ovr_draw_2e25_130a();
  GGameState = 0x14;
  if (DebugVerbose != false) {
    printf("%d \r",0x14);
  }
  if ((GPaused != '\0') && (GOngoingBattle == '\0')) {
    ovr_update_pause_button();
  }
  return;
}



/* 6a8f:1520 */

void __cdecl16far OVC41_6a8f_1520(void)

{
  int iVar1;
  
  ovr_gfxInitRand();
  ovr_font_302d_0a30();
  ovr_agnt_clear();
  ovr_attact_3f0b_05df();
  TextBlitDstSeg = 0xa000;
  for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
    ovr_draw_2e25_0efd(iVar1);
    ovr_draw_2e25_0000(iVar1,0xa000);
  }
  ovr_OVC18_48ac_0051();
  OVC41_6a8f_1a4c();
  if (DAT_2000_d1ae == '\0') {
    OVC41_6a8f_1aa1(8);
  }
  GMenuItem = DAT_2000_ca71;
  ovr_draw_2e25_130a();
  return;
}



/* 6a8f:15a0 */

/* WARNING: Instruction at (ram,0x00068912) overlaps instruction at (ram,0x0006890f)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00068915) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * __cdecl16far OVC41_6a8f_15a0(char param_1)

{
  undefined4 uVar1;
  bool bVar2;
  far_t gfx;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  far_t handle_03;
  far_t handle_04;
  far_t handle_05;
  far_t handle_06;
  char cVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  uint16_t uVar7;
  char *pcVar8;
  undefined2 uVar9;
  char *in_DX;
  char *unaff_BP;
  uint uVar10;
  undefined2 *unaff_SI;
  int iVar11;
  int unaff_DI;
  undefined2 uVar12;
  undefined2 unaff_SS;
  char *pcVar13;
  undefined2 in_stack_00000000;
  far_t gfx_00;
  far_t gfx_01;
  char *in_stack_00000002;
  far_t fStack0006;
  char in_stack_0000000e;
  char acStack_2cc [214];
  byte abStack_1f6 [374];
  undefined1 auStack_80 [58];
  char cStack_46;
  char cStack_1f;
  char cStack_1e;
  byte bStack_1d;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  uint16_t uStack_18;
  uint16_t uStack_16;
  undefined2 uStack_12;
  undefined2 uStack_10;
  byte bVar14;
  byte bVar15;
  undefined1 uVar16;
  byte bVar17;
  undefined1 uVar18;
  undefined1 uVar19;
  byte bVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  undefined1 uVar23;
  
  bVar20 = 0x6a;
  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)FontHandle.seg;
  gfx.ofs = FontHandle.ofs;
  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)(FontHandle.seg >> 8);
  uVar10 = FontHandle.ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)));
  bVar17 = (byte)((ulong)in_stack_00000002 >> 0x10);
  if (param_1 != '\0') {
    pcVar8 = (char *)(uint)bVar17;
    switch(bVar17) {
    case 0:
      return (char *)((int)(undefined4 *)&_DATA + 1);
    case 1:
      pcVar8 = (char *)ovr_OVC15_4207_1aae();
      return pcVar8;
    case 2:
      return (char *)((ulong)in_stack_00000002 >> 0x10);
    case 3:
      if (((ulong)in_stack_00000002 & 0x20000) == 0) {
        pcVar8 = (char *)ovr_constr_36ce_03a6();
      }
      return pcVar8;
    }
  }
  pcVar8 = (char *)(uint)bVar17;
  if ((char *)((int)(undefined4 *)&_DATA + 3U) < pcVar8) {
    if (TextBlitFlag != '\0') {
      ovr_say((char *)0x24106e74);
    }
    TextBlitFlag = 0;
    AgntFlag1 = false;
    GGameState = 0x33;
    if (DebugVerbose != false) {
      printf("%d \r",0x33);
    }
    OVC41_6a8f_11d2();
    GGameState = 0x35;
    pcVar8 = (char *)"puppetmaker" + 3;
    if (DebugVerbose != false) {
      pcVar8 = (char *)printf("%d \r",0x35);
    }
    return pcVar8;
  }
  pcVar5 = "Sound Effects (1. PC Speaker  2. Sound Blaster  3. Pro Audio Spectrum\n";
  switch(pcVar8) {
  case (char *)0x1:
    cVar3 = *(char *)((int)pcVar8 * 2 + 0x3f);
    do {
      if (((cVar3 == '\0') && (0xf7 < (int)unaff_SI)) &&
         (in_DX = (char *)"puppetmaker" + 3,
         *(byte *)((int)DAT_2000_ca95 + (int)unaff_SI * 9 + 1) < 8)) {
        uVar12 = 0x195d;
        if ((*(uint *)((uVar10 >> 8) * 0x27 + 0x121) & 0x80) == 0) {
          OVC39_690b_0000();
        }
        else {
          OVC39_690b_0000();
        }
        pcVar8 = (char *)OVC39_690b_00d1();
        uStack_12 = 0x938f;
        uStack_10 = pcVar5;
        pcVar13 = ovr_stsprintf(acStack_2cc,
                                (char *)CONCAT13((char)((uint)uVar12 >> 8),
                                                 CONCAT12((char)uVar12,pcVar8)),pcVar8);
        pcVar8 = (char *)pcVar13;
        uVar16 = (undefined1)((ulong)pcVar13 >> 0x10);
        uVar18 = (undefined1)((ulong)pcVar13 >> 0x18);
        pcVar5 = (char *)ovr_drawString();
        (*(uint8_t *)((uint8_t *)&(handle.seg))) = uVar16;
        handle.ofs = (uint16_t)pcVar8;
        (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uVar18;
        ovr_stshFree(handle);
        return pcVar5;
      }
      do {
        bVar17 = (byte)(uVar10 >> 8);
        if (((bVar20 == 1) && ((int)unaff_SI < 0xf8)) &&
           (in_DX = (char *)0x195d, (*(uint *)((uint)bVar17 * 0x27 + 0x121) & 2) != 0)) {
          OVC39_690b_0000();
          pcVar8 = (char *)OVC39_690b_00d1();
          uStack_12 = 0x93f9;
          uStack_10 = pcVar5;
          pcVar13 = ovr_stsprintf(acStack_2cc,
                                  (char *)CONCAT13((char)((uint)in_DX >> 8),
                                                   CONCAT12((char)in_DX,pcVar8)),pcVar8);
          pcVar8 = (char *)pcVar13;
          uVar16 = (undefined1)((ulong)pcVar13 >> 0x10);
          uVar18 = (undefined1)((ulong)pcVar13 >> 0x18);
          pcVar5 = (char *)ovr_drawString();
          (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = uVar16;
          handle_00.ofs = (uint16_t)pcVar8;
          (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = uVar18;
          ovr_stshFree(handle_00);
          return pcVar5;
        }
        if (((bVar20 == 2) && ((int)unaff_SI < 0xf8)) &&
           (in_DX = (char *)0x195d, (*(uint *)((uint)bVar17 * 0x27 + 0x121) & 0x20) != 0)) {
          OVC39_690b_0000();
          pcVar8 = (char *)OVC39_690b_00d1();
          uStack_12 = 0x9463;
          uStack_10 = pcVar5;
          pcVar13 = ovr_stsprintf(acStack_2cc,
                                  (char *)CONCAT13((char)((uint)in_DX >> 8),
                                                   CONCAT12((char)in_DX,pcVar8)),pcVar8);
          pcVar8 = (char *)pcVar13;
          uVar16 = (undefined1)((ulong)pcVar13 >> 0x10);
          uVar18 = (undefined1)((ulong)pcVar13 >> 0x18);
          pcVar5 = (char *)ovr_drawString();
          (*(uint8_t *)((uint8_t *)&(handle_01.seg))) = uVar16;
          handle_01.ofs = (uint16_t)pcVar8;
          (*(uint8_t *)((uint8_t *)&(handle_01.seg) + 1)) = uVar18;
          ovr_stshFree(handle_01);
          return pcVar5;
        }
        if (bVar20 == 3) {
          pcVar5 = (char *)"trade faire" + 8;
          bVar17 = 0x94;
          cVar3 = ovr_OVC45_77eb_0aea();
          if (cVar3 != '\0') {
            OVC39_690b_0000();
            pcVar8 = (char *)OVC39_690b_00d1();
            uStack_10 = (char *)"trade faire" + 8;
            uStack_12 = 0x94c9;
            pcVar13 = ovr_stsprintf(acStack_2cc,
                                    (char *)CONCAT13((char)((uint)in_DX >> 8),
                                                     CONCAT12((char)in_DX,pcVar8)),pcVar8);
            pcVar8 = (char *)pcVar13;
            uVar16 = (undefined1)((ulong)pcVar13 >> 0x10);
            uVar18 = (undefined1)((ulong)pcVar13 >> 0x18);
            pcVar5 = (char *)ovr_drawString();
            (*(uint8_t *)((uint8_t *)&(handle_02.seg))) = uVar16;
            handle_02.ofs = (uint16_t)pcVar8;
            (*(uint8_t *)((uint8_t *)&(handle_02.seg) + 1)) = uVar18;
            ovr_stshFree(handle_02);
            return pcVar5;
          }
        }
        if (((bVar20 == 4) && ((int)unaff_SI < 0xf8)) &&
           (uVar12 = 0x195d, (*(uint *)((uint)bVar17 * 0x27 + 0x121) & 0x400) != 0)) {
          OVC39_690b_0000();
          pcVar8 = (char *)OVC39_690b_00d1();
          uStack_12 = 0x9533;
          uStack_10 = pcVar5;
          pcVar13 = ovr_stsprintf(acStack_2cc,
                                  (char *)CONCAT13((char)((uint)uVar12 >> 8),
                                                   CONCAT12((char)uVar12,pcVar8)),pcVar8);
          pcVar8 = (char *)pcVar13;
          uVar16 = (undefined1)((ulong)pcVar13 >> 0x10);
          uVar18 = (undefined1)((ulong)pcVar13 >> 0x18);
          pcVar5 = (char *)ovr_drawString();
          (*(uint8_t *)((uint8_t *)&(handle_03.seg))) = uVar16;
          handle_03.ofs = (uint16_t)pcVar8;
          (*(uint8_t *)((uint8_t *)&(handle_03.seg) + 1)) = uVar18;
          ovr_stshFree(handle_03);
          return pcVar5;
        }
        do {
          unaff_DI = unaff_DI + 1;
          while (1 < unaff_DI) {
            bVar20 = bVar20 + 1;
            if (3 < bVar20) {
              bVar20 = (byte)((ulong)in_stack_00000002 >> 0x10);
              uVar12 = (undefined2)((ulong)*(undefined4 *)((uint)bVar20 << 2) >> 0x10);
              iVar4 = (int)*(undefined4 *)((uint)bVar20 << 2);
              if (*(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4f) <
                  (uint)(*(int *)(iVar4 + 0x4d) * 2 + *(int *)(iVar4 + 0x4d)) >> 1) {
                if (*(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4f) <
                    *(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4d)) {
                  uVar12 = (undefined2)((ulong)*(undefined4 *)((uint)bVar20 << 2) >> 0x10);
                  iVar4 = (int)*(undefined4 *)((uint)bVar20 << 2);
                  if (*(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4f) <
                      (uint)(*(int *)(iVar4 + 0x4d) * 2 + *(int *)(iVar4 + 0x4d)) >> 2) {
                    if (*(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4f) <
                        *(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4d) >> 1) {
                      if (*(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4f) <
                          *(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4d) >> 2) {
                        bVar17 = 5;
                      }
                      else {
                        bVar17 = 4;
                      }
                    }
                    else {
                      bVar17 = 3;
                    }
                  }
                  else {
                    bVar17 = 2;
                  }
                }
                else {
                  bVar17 = 1;
                }
              }
              else {
                bVar17 = 0;
              }
              uVar12 = (undefined2)((ulong)*(undefined4 *)((uint)bVar20 << 2) >> 0x10);
              iVar11 = (int)*(undefined4 *)((uint)bVar20 << 2);
              iVar4 = *(int *)(iVar11 + 0x62);
              if ((iVar4 < 0) ||
                 ((iVar4 == 0 &&
                  (*(uint *)(iVar11 + 0x60) <
                   (uint)(*(int *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4d) * 0x28))))) {
                uVar12 = (undefined2)((ulong)*(undefined4 *)((uint)bVar20 << 2) >> 0x10);
                iVar11 = (int)*(undefined4 *)((uint)bVar20 << 2);
                iVar4 = *(int *)(iVar11 + 0x62);
                if ((iVar4 < 0) ||
                   ((iVar4 == 0 &&
                    (*(uint *)(iVar11 + 0x60) <
                     (uint)(*(int *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4d) * 0x14))))) {
                  uVar12 = (undefined2)((ulong)*(undefined4 *)((uint)bVar20 << 2) >> 0x10);
                  iVar11 = (int)*(undefined4 *)((uint)bVar20 << 2);
                  iVar4 = *(int *)(iVar11 + 0x62);
                  if ((iVar4 < 0) ||
                     ((iVar4 == 0 &&
                      (*(uint *)(iVar11 + 0x60) <
                       (uint)(*(int *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4d) * 0x3c) >> 2)
                      ))) {
                    uVar12 = (undefined2)((ulong)*(undefined4 *)((uint)bVar20 << 2) >> 0x10);
                    iVar11 = (int)*(undefined4 *)((uint)bVar20 << 2);
                    iVar4 = *(int *)(iVar11 + 0x62);
                    if ((iVar4 < 0) ||
                       ((iVar4 == 0 &&
                        (*(uint *)(iVar11 + 0x60) <
                         (uint)(*(int *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4d) * 0x14) >>
                         1)))) {
                      uVar12 = (undefined2)((ulong)*(undefined4 *)((uint)bVar20 << 2) >> 0x10);
                      iVar11 = (int)*(undefined4 *)((uint)bVar20 << 2);
                      iVar4 = *(int *)(iVar11 + 0x62);
                      if ((iVar4 < 0) ||
                         ((iVar4 == 0 &&
                          (*(uint *)(iVar11 + 0x60) <
                           (uint)(*(int *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4d) * 0x14)
                           >> 2)))) {
                        uStack_10 = (char *)CONCAT11(5,(undefined1)uStack_10);
                      }
                      else {
                        uStack_10 = (char *)CONCAT11(4,(undefined1)uStack_10);
                      }
                    }
                    else {
                      uStack_10 = (char *)CONCAT11(3,(undefined1)uStack_10);
                    }
                  }
                  else {
                    uStack_10 = (char *)CONCAT11(2,(undefined1)uStack_10);
                  }
                }
                else {
                  uStack_10 = (char *)CONCAT11(1,(undefined1)uStack_10);
                }
              }
              else {
                uStack_10 = (char *)((uint)uStack_10 & 0xff);
              }
              if ((*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) < bVar17) {
                bVar17 = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
              }
              uVar12 = (undefined2)((ulong)*(undefined4 *)((uint)bVar20 << 2) >> 0x10);
              iVar4 = (int)*(undefined4 *)((uint)bVar20 << 2);
              if (*(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x5b) <
                  (uint)(*(int *)(iVar4 + 0x4d) * 2 + *(int *)(iVar4 + 0x4d)) >> 1) {
                if (*(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x5b) <
                    *(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4d)) {
                  uVar12 = (undefined2)((ulong)*(undefined4 *)((uint)bVar20 << 2) >> 0x10);
                  iVar4 = (int)*(undefined4 *)((uint)bVar20 << 2);
                  if (*(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x5b) <
                      (uint)(*(int *)(iVar4 + 0x4d) * 2 + *(int *)(iVar4 + 0x4d)) >> 2) {
                    if (*(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x5b) <
                        *(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4d) >> 1) {
                      if (*(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x5b) <
                          *(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4d) >> 2) {
                        bVar14 = 5;
                      }
                      else {
                        bVar14 = 4;
                      }
                    }
                    else {
                      bVar14 = 3;
                    }
                  }
                  else {
                    bVar14 = 2;
                  }
                }
                else {
                  bVar14 = 1;
                }
              }
              else {
                bVar14 = 0;
              }
              bVar15 = 0;
              pcVar8 = (char *)"halfling castle" + 0xc;
              if (*(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x54) <
                  (uint)(*(int *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4d) << 1)) {
                pcVar8 = (char *)((uint)bVar20 << 2);
                if (*(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x54) <
                    *(uint *)((int)*(undefined4 *)pcVar8 + 0x4d)) {
                  pcVar8 = (char *)"halfling castle" + 0xc;
                  if (*(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x54) <
                      *(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4d) >> 1) {
                    pcVar8 = (char *)"halfling castle" + 0xc;
                    if (*(int *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x54) < 0) {
                      pcVar8 = (char *)"halfling castle" + 0xc;
                      if (*(uint *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x54) <
                          (uint)-*(int *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x4d)) {
                        bVar15 = 5;
                      }
                      else {
                        bVar15 = 4;
                      }
                    }
                    else {
                      bVar15 = 3;
                    }
                  }
                  else {
                    bVar15 = 2;
                  }
                }
                else {
                  bVar15 = 1;
                }
              }
              if (((bVar17 != 0) && (bVar14 <= bVar17)) && (bVar15 <= bVar17)) {
                OVC39_690b_0000();
                pcVar6 = (char *)OVC39_690b_00d1();
                uStack_12 = 0x9ad8;
                uStack_10 = pcVar5;
                pcVar13 = ovr_stsprintf(acStack_2cc,
                                        (char *)CONCAT13((char)((uint)pcVar8 >> 8),
                                                         CONCAT12((char)pcVar8,pcVar6)),pcVar6);
                pcVar8 = (char *)pcVar13;
                uVar16 = (undefined1)((ulong)pcVar13 >> 0x10);
                uVar18 = (undefined1)((ulong)pcVar13 >> 0x18);
                pcVar5 = (char *)ovr_drawString();
                (*(uint8_t *)((uint8_t *)&(handle_04.seg))) = uVar16;
                handle_04.ofs = (uint16_t)pcVar8;
                (*(uint8_t *)((uint8_t *)&(handle_04.seg) + 1)) = uVar18;
                ovr_stshFree(handle_04);
                return pcVar5;
              }
              if ((bVar14 != 0) && (bVar15 <= bVar14)) {
                OVC39_690b_0000();
                pcVar6 = (char *)OVC39_690b_00d1();
                uStack_12 = 0x9b2e;
                uStack_10 = pcVar5;
                pcVar13 = ovr_stsprintf(acStack_2cc,
                                        (char *)CONCAT13((char)((uint)pcVar8 >> 8),
                                                         CONCAT12((char)pcVar8,pcVar6)),pcVar6);
                pcVar8 = (char *)pcVar13;
                uVar16 = (undefined1)((ulong)pcVar13 >> 0x10);
                uVar18 = (undefined1)((ulong)pcVar13 >> 0x18);
                pcVar5 = (char *)ovr_drawString();
                (*(uint8_t *)((uint8_t *)&(handle_05.seg))) = uVar16;
                handle_05.ofs = (uint16_t)pcVar8;
                (*(uint8_t *)((uint8_t *)&(handle_05.seg) + 1)) = uVar18;
                ovr_stshFree(handle_05);
                return pcVar5;
              }
              if (bVar15 != 0) {
                OVC39_690b_0000();
                pcVar6 = (char *)OVC39_690b_00d1();
                uStack_12 = 0x9b7b;
                uStack_10 = pcVar5;
                pcVar13 = ovr_stsprintf(acStack_2cc,
                                        (char *)CONCAT13((char)((uint)pcVar8 >> 8),
                                                         CONCAT12((char)pcVar8,pcVar6)),pcVar6);
                pcVar8 = (char *)pcVar13;
                uVar16 = (undefined1)((ulong)pcVar13 >> 0x10);
                uVar18 = (undefined1)((ulong)pcVar13 >> 0x18);
                pcVar5 = (char *)ovr_drawString();
                (*(uint8_t *)((uint8_t *)&(handle_06.seg))) = uVar16;
                handle_06.ofs = (uint16_t)pcVar8;
                (*(uint8_t *)((uint8_t *)&(handle_06.seg) + 1)) = uVar18;
                ovr_stshFree(handle_06);
                return pcVar5;
              }
              pcVar8 = (char *)OVC39_690b_00d1();
              uStack_12 = 0x9bb1;
              uStack_10 = pcVar5;
              ovr_stsprintf(acStack_2cc,
                            (char *)CONCAT13((char)((uint)DAT_2410_6ac6 >> 8),
                                             CONCAT12((char)DAT_2410_6ac6,DAT_2410_6ac4)),pcVar8);
              pcVar8 = (char *)ovr_drawString();
              return pcVar8;
            }
            unaff_DI = -2;
          }
          pcVar5 = (char *)"thief outpost" + 10;
          iVar4 = ovr_OVC23_55fe_2937();
        } while (iVar4 != -1);
        unaff_SI = (undefined2 *)OVC39_690b_0111();
        uVar12 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
        in_DX = (char *)"puppetmaker" + 3;
        bVar17 = *(byte *)((int)DAT_2000_ca95 + (int)unaff_SI * 9 + 2);
        uVar10 = CONCAT11(*(undefined1 *)((int)DAT_2000_ca95 + (int)unaff_SI * 9),bVar17);
      } while (bVar20 != 0);
      in_DX = (char *)"halfling castle" + 0xc;
      uVar1 = *(undefined4 *)((uint)bVar17 << 2);
      cVar3 = *(char *)((int)uVar1 + 0x3f);
    } while( true );
  case (char *)0x2:
    LOCK();
    iVar4 = *(int *)((char *)"Too many construction sites." + 0x17 + unaff_DI);
    *(undefined1 **)((char *)"Too many construction sites." + 0x17 + unaff_DI) = &stack0xfffe;
    UNLOCK();
    *(int *)(iVar4 + -2) = unaff_DI;
    iVar11 = 0;
    pcVar8 = DAT_2410_69d7;
    for (bVar20 = 0; pcVar5 = (char *)CONCAT11(0x24,DAT_2000_d1e6), bVar20 < DAT_2000_d1e6;
        bVar20 = bVar20 + 1) {
      pcVar8 = (char *)((uint)bVar20 << 2);
      if ((byte)(&stack0xfffa)[(byte)((ulong)in_stack_00000002 >> 0x10)] <=
          *(byte *)((int)*(undefined4 *)pcVar8 + 0xa5)) {
        for (uVar10 = 0xf8; uVar10 < DAT_2000_ca99; uVar10 = uVar10 + 1) {
          pcVar8 = (char *)"puppetmaker" + 3;
          uVar12 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
          if (*(byte *)((int)DAT_2000_ca95 + uVar10 * 9 + 2) == bVar20) {
            pcVar8 = (char *)"puppetmaker" + 3;
            if (*(byte *)((int)DAT_2000_ca95 + uVar10 * 9 + 1) < 8) {
              *(undefined2 *)(iVar4 + -4) = CONCAT11((char)(uVar10 * 9 >> 8),bVar20);
              *(uint *)(iVar4 + -6) = uVar10;
              *(undefined2 *)(iVar4 + -8) = 0x6000;
              *(undefined2 *)(iVar4 + -10) = 0x8958;
              cVar3 = season_67e7_09b9();
              if (cVar3 != '\0') {
                pcVar8 = (char *)"puppetmaker" + 3;
                *(undefined1 *)((int)DAT_2000_ca95 + uVar10 * 9 + 1) = 8;
                iVar11 = iVar11 + 1;
              }
            }
          }
        }
      }
    }
    if (iVar11 != 0) {
      *(undefined2 *)(iVar4 + -4) = 0;
      *(undefined2 *)(iVar4 + -6) = 0x24;
      *(undefined2 *)(iVar4 + -8) = 0x6000;
      *(undefined2 *)(iVar4 + -10) = (uint8_t *)SpecialColors + 5;
      ovr_inputUpdate(*(ulong *)(iVar4 + -6));
      *(undefined2 *)(iVar4 + -4) = 0xa000;
      *(int *)(iVar4 + -6) = iVar11;
      *(undefined2 *)(iVar4 + -8) = (char *)"steam bath" + 6;
      *(undefined2 *)(iVar4 + -10) = 0x89b2;
      uVar12 = ovr_OVC41_6a8f_0000();
      *(undefined2 *)(iVar4 + -6) = pcVar8;
      *(undefined2 *)(iVar4 + -8) = uVar12;
      *(int *)(iVar4 + -10) = iVar11;
      *(undefined2 *)(iVar4 + -0xc) = (char *)"puppetmaker" + 3;
      *(undefined2 *)(iVar4 + -0xe) = (char *)"%d building%s repaired.";
      *(undefined2 *)(iVar4 + -0x10) = unaff_SS;
      *(int *)(iVar4 + -0x12) = (int)auStack_80;
      *(char **)((code *)init_3381_08dc + iVar4) = (char *)"builder\'s hall" + 8;
      *(undefined2 *)(iVar4 + -0x16) = 0x89c6;
      pcVar13 = ovr_stsprintf((char *)*(undefined2 *)(iVar4 + -0x12),
                              (char *)*(undefined4 *)(iVar4 + -0xe),
                              (char *)*(undefined2 *)(iVar4 + -10));
      pcVar5 = (char *)pcVar13;
      *(undefined2 *)(iVar4 + -6) = (int)((ulong)pcVar13 >> 0x10);
      *(undefined2 *)(iVar4 + -8) = pcVar5;
      *(undefined2 *)(iVar4 + -10) = (char *)"glassworks" + 9;
      *(undefined2 *)(iVar4 + -0xc) = 0x89d0;
      ovr_uiNotify((char *)*(undefined4 *)(iVar4 + -8),*(uint16_t *)(iVar4 + -4));
    }
    return pcVar5;
  case (char *)0x3:
    (*(uint16_t *)((uint8_t *)&(AgntAnms[0x11]) + 18)) = (*(uint16_t *)((uint8_t *)&(AgntAnms[0x11]) + 18)) + (int)pcVar8 * 2;
    pcVar13 = ovr_stsprintf(pcVar8,(char *)CONCAT22(in_stack_00000000,unaff_BP),
                            (char *)in_stack_00000002);
    bVar20 = (byte)((ulong)pcVar13 >> 0x10);
    pcVar8 = (char *)ovr_OVC28_6018_1527();
    if ((char)pcVar8 != '\0') {
      uVar10 = (uint)pcVar8 & 0xff;
      pcVar8 = (char *)(uint)abStack_1f6[uVar10 * 2];
      *(byte *)((int)*(undefined4 *)((uint)bVar20 << 2) + 0x85) = abStack_1f6[uVar10 * 2];
    }
    return pcVar8;
  }
  out(*unaff_SI,in_DX);
  uVar22 = 0;
  uVar23 = 0x60;
  uVar10 = 0xa329;
  cVar3 = cStack_46;
  OVC40_69c8_0000();
  OVC40_69c8_047f();
  ovr_init2_3338_0401();
  uVar12 = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  uVar9 = *(undefined2 *)BDA_DailyTimeCounter;
  uVar19 = (undefined1)uVar12;
  uVar21 = (undefined1)((uint)uVar12 >> 8);
  uVar16 = (undefined1)uVar9;
  uVar18 = (undefined1)((uint)uVar9 >> 8);
  if (cVar3 == '\x04') {
    uVar7 = ovr_inputUpdate(0xb4);
    if (1 < (byte)uVar7) {
      bStack_1d = 2;
    }
  }
  else {
    if (cStack_1f < '\0') {
      iVar4 = 0xee;
    }
    else {
      iVar4 = 1;
    }
    cStack_1e = 'w';
    while (cVar3 = cStack_1e + -1, bVar2 = cStack_1e != '\0', cStack_1e = cVar3, bVar2) {
      if ((iVar4 == 100) && (in_stack_0000000e == '\x02')) {
        gfx_00.seg = DAT_2000_d3ea;
        gfx_00.ofs = DAT_2000_d3e8;
        ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa000b400)));
        OVC40_69c8_0000();
        OVC40_69c8_0000();
        uVar22 = 0xd3;
        uVar23 = 0x22;
        uVar10 = 0xa5ad;
        OVC40_69c8_0000();
      }
      OVC40_69c8_0373();
      uVar7 = ovr_biosKeyAvail();
      if ((char)uVar7 != '\0') {
        pcVar8 = (char *)ovr_gameProcessKey();
        if (pcVar8 == (char *)0x11b) {
          bStack_1d = 2;
          break;
        }
        if (pcVar8 == (char *)"%s: provides housing and income." + 8) break;
      }
      iVar11 = ovr_init2_3338_0415();
      if (iVar11 != 0) break;
      if (DAT_2000_ccaf != '\0') {
        bStack_1d = 2;
        break;
      }
      do {
        ovr_audio_3a5b_0000();
        if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != CONCAT11(uVar21,uVar19)) break;
      } while (*(int *)BDA_DailyTimeCounter == CONCAT11(uVar18,uVar16));
      uVar12 = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
      uVar9 = *(undefined2 *)BDA_DailyTimeCounter;
      uVar19 = (undefined1)uVar12;
      uVar21 = (undefined1)((uint)uVar12 >> 8);
      uVar16 = (undefined1)uVar9;
      uVar18 = (undefined1)((uint)uVar9 >> 8);
      iVar4 = iVar4 + cStack_1f;
    }
    if (cStack_1f < '\x01') {
      OVC40_69c8_0373();
    }
    else {
      OVC40_69c8_0373();
    }
    OVC40_69c8_047f();
    DAT_2000_ccaf = '\0';
    if ((in_stack_0000000e == '\x02') || (in_stack_0000000e == '\x03')) {
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
      uVar9 = *(undefined2 *)BDA_DailyTimeCounter;
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = uVar9;
      if (bStack_1d == 0) {
        uVar7 = ovr_inputUpdate(0x48);
        bStack_1d = (byte)uVar7;
      }
    }
    else {
      gfx_01.seg = far_t_2000_d3e4.seg;
      gfx_01.ofs = far_t_2000_d3e4.ofs;
      ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa000e908)));
      MiceProcessed = 0;
      ovr_miceBlitRect(BlitRects + 1);
      do {
        do {
          ovr_audio_3a5b_0000();
          iVar4 = ovr_init2_3338_0388();
          if ((((iVar4 != 0) && (0x87 < CONCAT11(uVar23,uVar22))) && (0xb9 < uVar10)) &&
             ((CONCAT11(uVar23,uVar22) < 0xd6 && (uVar10 < 0xc6)))) goto LAB_69c8_0af0;
          if (DAT_2000_ccaf != '\0') {
            bStack_1d = 2;
            goto LAB_69c8_0af0;
          }
          uVar7 = ovr_biosKeyAvail();
        } while ((char)uVar7 == '\0');
        pcVar8 = (char *)ovr_gameProcessKey();
        if (pcVar8 == (char *)0x11b) {
          bStack_1d = 2;
          break;
        }
      } while (pcVar8 != (char *)"%s: provides housing and income." + 8);
    }
  }
LAB_69c8_0af0:
  ovr_miceRestoreArea(BlitRects + 1);
  ovr_init2_3338_043e();
  fStack0006.seg = uStack_16;
  fStack0006.ofs = uStack_18;
  ovr_stshFree(fStack0006);
  uStack_1c = OVC40_69c8_023a();
  uStack_1a = uVar9;
  OVC40_69c8_011e();
  ovr_stop_audio();
  DAT_2410_07a6 = 0xff;
  ovr_init_3381_0000();
  if (GameRunning == false) {
    OVC40_69c8_0317();
  }
  ovr_OVC28_6018_0251();
  ovr_OVC41_6a8f_18c6();
  ovr_miceBlitRect(BlitRects + 1);
  return (char *)(uint)bStack_1d;
}



/* 6a8f:1847 */

void __cdecl16far OVC41_6a8f_1847(void)

{
  char cVar1;
  
  DAT_2000_ca9b = '\x01' - (DAT_2000_ca9b != '\0');
  GOngoingBattle = DAT_2000_ca9b;
  ovr_OVC28_6018_0176();
  cVar1 = ovr_draw_2e25_15d6();
  if (cVar1 == '\0') {
    GOngoingBattle = '\x01';
    ovr_say("You cannot see the terrain here.");
    ovr_stop_audio();
  }
  else {
    ovr_agnt_clear();
    ovr_constr_36ce_1efc();
    if (GOngoingBattle != '\0') {
      ovr_stop_audio();
    }
    ovr_update_pause_button();
  }
  return;
}



/* 6a8f:18c6 */

void __cdecl16far OVC41_6a8f_18c6(void)

{
  ovr_draw_2e25_0573();
  GMenuItem = DAT_2000_ca71;
  DAT_2000_ca6f = DAT_2000_ca70;
  OVC41_6a8f_11d2(0);
  if (5 < GMenuItem) {
    GMenuItem = 5;
  }
  while ((GMenuItem != 5 && (((undefined1 *)&DAT_2000_d1de)[GMenuItem] == -1))) {
    if (GMenuItem == 0) {
      GMenuItem = 5;
    }
    else {
      GMenuItem = GMenuItem - 1;
    }
  }
  if (GameRunning == false) {
    ovr_draw_2e25_130a();
  }
  ovr_draw_2e25_025a();
  (*(uint16_t *)((uint8_t *)&(GDailyTimeCounter) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  (*(uint16_t *)((uint8_t *)&(GDailyTimeCounter))) = *(undefined2 *)BDA_DailyTimeCounter;
  return;
}



/* 6a8f:199c */

void __cdecl16far uiMainMenu(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  
  ovr_draw_2e25_1662();
  ovr_stop_audio();
  DAT_2000_ca71 = GMenuItem;
  DAT_2000_ca70 = DAT_2000_ca6f;
  gfx.seg = DAT_2000_cabb;
  gfx.ofs = DAT_2000_cab9;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000e249)));
  gfx_00.seg = DAT_2000_cabf;
  gfx_00.ofs = DAT_2000_cabd;
  ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa000e249)));
  ovr_uiMainMenuLoop();
  gfx_01.seg = DAT_2000_cabb;
  gfx_01.ofs = DAT_2000_cab9;
  ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa000e249)));
  gfx_02.seg = DAT_2000_cac3;
  gfx_02.ofs = DAT_2000_cac1;
  ovr_blitLoadRleGfx(gfx_02,far_from_u32((uint32_t)(0xa000e249)));
  OVC41_6a8f_18c6();
  return;
}



/* 6a8f:1a4c */

void __cdecl16far OVC41_6a8f_1a4c(void)

{
  memcpy((uint8_t *)&DAT_2000_ca60,(uint8_t *)0x6e08,0xc);
  memcpy((uint8_t *)&DAT_2000_ca54,(uint8_t *)0x6e14,0xc);
  memcpy((uint8_t *)&DAT_2000_ca48,(uint8_t *)0x6e20,0xc);
  memcpy((uint8_t *)&DAT_2000_ca3c,(uint8_t *)0x6e2c,0xc);
  return;
}



/* 6a8f:1aa1 */

void __cdecl16far OVC41_6a8f_1aa1(uint param_1)

{
  undefined1 uVar1;
  uint uVar2;
  
  for (uVar2 = 0; (int)uVar2 < 0xc; uVar2 = uVar2 + 1) {
    if (uVar2 != param_1) {
      uVar1 = (undefined1)uVar2;
      if ((byte)((undefined1 *)&DAT_2000_ca60)[uVar2] == param_1) {
        if ((byte)((undefined1 *)&DAT_2000_ca60)[param_1] == param_1) {
          ((undefined1 *)&DAT_2000_ca60)[uVar2] = uVar1;
        }
        else {
          ((undefined1 *)&DAT_2000_ca60)[uVar2] = ((undefined1 *)&DAT_2000_ca60)[param_1];
        }
      }
      if ((byte)((undefined1 *)&DAT_2000_ca54)[uVar2] == param_1) {
        if ((byte)((undefined1 *)&DAT_2000_ca54)[param_1] == param_1) {
          ((undefined1 *)&DAT_2000_ca54)[uVar2] = uVar1;
        }
        else {
          ((undefined1 *)&DAT_2000_ca54)[uVar2] = ((undefined1 *)&DAT_2000_ca54)[param_1];
        }
      }
      if ((byte)((undefined1 *)&DAT_2000_ca48)[uVar2] == param_1) {
        if ((byte)((undefined1 *)&DAT_2000_ca48)[param_1] == param_1) {
          ((undefined1 *)&DAT_2000_ca48)[uVar2] = uVar1;
        }
        else {
          ((undefined1 *)&DAT_2000_ca48)[uVar2] = ((undefined1 *)&DAT_2000_ca48)[param_1];
        }
      }
      if ((byte)((undefined1 *)&DAT_2000_ca3c)[uVar2] == param_1) {
        if ((byte)((undefined1 *)&DAT_2000_ca3c)[param_1] == param_1) {
          ((undefined1 *)&DAT_2000_ca3c)[uVar2] = uVar1;
        }
        else {
          ((undefined1 *)&DAT_2000_ca3c)[uVar2] = ((undefined1 *)&DAT_2000_ca3c)[param_1];
        }
      }
    }
  }
  return;
}



/* 6a8f:1be0 */

void __cdecl16far OVC41_6a8f_1be0(uint param_1)

{
  bool bVar1;
  
  bVar1 = MiceNeedsUpdate == '\0';
  if (bVar1) {
    ovr_miceRestoreArea(BlitRects + 1);
  }
  TextBlitDstSeg = 0xa000;
  if (GMenuItem == param_1) {
    ovr_draw_2e25_0098(*(undefined1 *)(GMenuItem + 0x9082));
  }
  ovr_draw_2e25_0000(param_1);
  if (bVar1) {
    ovr_miceBlitRect(BlitRects + 1);
  }
  return;
}



/* 6a8f:1c74 */

undefined1 __cdecl16far OVC41_6a8f_1c74(undefined4 param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  undefined2 uVar2;
  uint16_t uVar3;
  char *pcVar4;
  uint16_t uVar5;
  undefined2 in_DX;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  char *pcVar9;
  undefined4 uVar10;
  int iVar11;
  undefined1 local_11c [80];
  undefined1 local_cc [80];
  char local_7c [121];
  undefined1 uStack_3;
  
  uStack_3 = 0;
  uVar8 = (undefined2)((ulong)param_2 >> 0x10);
  iVar6 = (int)param_2;
  if ((*(uint *)(iVar6 + 0x2b) & 0x80) != 0) {
    param_3 = (uint)*(byte *)(iVar6 + 0x21);
  }
  iVar7 = (int)param_1;
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  if ((int)param_3 < (int)(uint)*(byte *)(iVar6 + 0x21)) {
    *(undefined1 *)(iVar6 + 0x23) = 6;
    *(undefined1 *)(iVar6 + 0x24) = 1;
    *(undefined2 *)(iVar6 + 6) = 0;
    ovr_agnt_3b1d_0a53();
    if (((*(char *)(iVar6 + 0x11) == '\0') && ((*(uint *)(iVar6 + 0x2b) & 0x200) == 0)) &&
       ((*(uint *)((int)*(undefined4 *)(iVar7 + 0x1d) + 0x3c) & 0x40) != 0)) {
      uVar5 = DAT_2000_d0f7;
      uVar2 = ovr_agnt_3b1d_0ac0(iVar7,uVar2,local_11c);
      uVar10 = CONCAT22(in_DX,uVar2);
      uVar2 = ovr_agnt_3b1d_0ac0(iVar6,uVar8,local_cc);
      pcVar4 = (char *)ovr_OVC15_4207_1c16(uVar2,in_DX,uVar10);
      pcVar9 = ovr_stsprintf(local_7c,"%s is paralyzed by %s.",pcVar4);
      ovr_uiNotify(pcVar9,uVar5);
      uVar5 = ovr_audio_3a5b_0afd();
      ovr_play_sfxU(3,0,uVar5);
      OVC41_6a8f_0229();
      *(uint *)(iVar6 + 0x2b) = *(uint *)(iVar6 + 0x2b) | 0x200;
      ovr_attact_3f0b_2a09();
      return uStack_3;
    }
    if (((*(char *)(iVar6 + 0x11) == '\0') && ((*(uint *)(iVar6 + 0x2b) & 0x800) == 0)) &&
       (((*(uint *)((int)*(undefined4 *)(iVar7 + 0x1d) + 0x40) & 0x100) != 0 &&
        (cVar1 = ovr_OVC27_5ded_1c94(iVar6,uVar8,2), cVar1 == '\0')))) {
      uVar5 = DAT_2000_d0f7;
      uVar2 = ovr_agnt_3b1d_0ac0(iVar7,uVar2,local_11c);
      uVar10 = CONCAT22(in_DX,uVar2);
      uVar2 = ovr_agnt_3b1d_0ac0(iVar6,uVar8,local_cc);
      pcVar4 = (char *)ovr_OVC15_4207_1c16(uVar2,in_DX,uVar10);
      pcVar9 = ovr_stsprintf(local_7c,"%s is stoned by %s.",pcVar4);
      ovr_uiNotify(pcVar9,uVar5);
      *(uint *)(iVar6 + 0x2b) = *(uint *)(iVar6 + 0x2b) | 0x800;
      uVar5 = ovr_audio_3a5b_0afd();
      ovr_play_sfxU(0x1b,0,uVar5);
      OVC41_6a8f_0229();
      ovr_attact_3f0b_2a09();
      return uStack_3;
    }
    *(char *)(iVar6 + 0x21) = *(char *)(iVar6 + 0x21) - (char)param_3;
    if (((*(uint *)((int)*(undefined4 *)(iVar7 + 0x1d) + 0x3c) & 0x8000) == 0) ||
       ((*(uint *)((int)*(undefined4 *)(iVar6 + 0x1d) + 0x3c) & 0x8000) == 0)) {
      if (*(char *)((int)*(undefined4 *)(iVar7 + 0x1d) + 0x50) == '\0') {
        uVar5 = ovr_audio_3a5b_0afd();
        iVar11 = 0;
        uVar3 = ovr_randBelow(2);
        ovr_play_sfxU((char)uVar3 + 0x3d,iVar11,uVar5);
      }
      else if (*(char *)((int)*(undefined4 *)(iVar7 + 0x1d) + 0x50) == '\x15') {
        uVar5 = ovr_randBelow(2);
        if ((uVar5 & 0xff) == 0) {
          ovr_play_sfx(21,0);
        }
        else {
          ovr_play_sfx(71,0);
        }
      }
      else if (*(char *)((int)*(undefined4 *)(iVar7 + 0x1d) + 0x50) == '\x03') {
        uVar5 = ovr_audio_3a5b_0afd();
        iVar11 = 0;
        uVar3 = ovr_randBelow(2);
        ovr_play_sfxU((char)uVar3 + 0x14,iVar11,uVar5);
      }
      else {
        ovr_play_sfx((uint)*(byte *)((int)*(undefined4 *)(iVar7 + 0x1d) + 0x50),0);
      }
    }
    else {
      uVar5 = ovr_audio_3a5b_0afd();
      iVar11 = 0;
      uVar3 = ovr_randBelow(2);
      ovr_play_sfxU((char)uVar3 + 0x14,iVar11,uVar5);
    }
    if ((*(uint *)(iVar7 + 0x2b) & 0x20) != 0) {
      *(uint *)(iVar7 + 0x2b) = *(uint *)(iVar7 + 0x2b) & 0xffdf;
      uVar5 = DAT_2000_d0f7;
      uVar8 = ovr_agnt_3b1d_0ac0(iVar6,uVar8,local_cc);
      pcVar4 = (char *)ovr_OVC15_4207_1c16(uVar8);
      pcVar9 = ovr_stsprintf(local_7c,"%s is no longer charmed.",pcVar4);
      ovr_uiNotify(pcVar9,uVar5);
      *(undefined1 *)(iVar7 + 0x2f) = *(undefined1 *)*(undefined4 *)(iVar7 + 0x1d);
      OVC41_6a8f_0246();
      ovr_attact_3f0b_2a09();
    }
  }
  else {
    if (*(char *)((int)*(undefined4 *)(iVar6 + 0x1d) + 0x51) == -1) {
      uVar5 = ovr_audio_3a5b_0afd();
      ovr_play_sfxU(4,0,uVar5);
    }
    else {
      uVar5 = ovr_audio_3a5b_0afd();
      ovr_play_sfxU(*(byte *)((int)*(undefined4 *)(iVar6 + 0x1d) + 0x51),0,uVar5);
    }
    OVC41_6a8f_063f();
    uStack_3 = 1;
  }
  ovr_attact_3f0b_2a09();
  return uStack_3;
}



/* 6a8f:2084 */

/* WARNING: Instruction at (ram,0x00066a51) overlaps instruction at (ram,0x00066a50)
    */
/* WARNING: Unable to track spacebase fully for stack */

char * __cdecl16far OVC41_6a8f_2084(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  byte bVar4;
  code *pcVar5;
  far_t gfx;
  far_t gfx_00;
  far_t dst;
  far_t gfx_01;
  far_t dst_00;
  far_t gfx_02;
  far_t gfx_03;
  far_t dst_01;
  far_t dst_02;
  char cVar6;
  char *pcVar7;
  char *pcVar8;
  uint16_t uVar9;
  int iVar10;
  char *pcVar11;
  uint uVar12;
  int *piVar13;
  undefined2 *puVar14;
  int iVar15;
  undefined1 *puVar16;
  int unaff_SI;
  undefined2 *unaff_DI;
  uint16_t uVar17;
  undefined2 uVar18;
  undefined2 unaff_SS;
  char *pcVar19;
  far_t *pfVar20;
  undefined2 uVar21;
  undefined1 in_stack_0000fee0;
  undefined1 in_stack_0000fee1;
  uint8_t in_stack_0000fee2;
  far_t handle;
  uint16_t in_stack_0000fef6;
  uint16_t in_stack_0000ff10;
  char local_94 [82];
  char acStack_42 [6];
  char cStack_3c;
  byte bStack_3b;
  int iStack_3a;
  char *pcStack_38;
  char *pcStack_36;
  char *pcStack_34;
  char *pcStack_32;
  char *pcStack_30;
  char *pcStack_2e;
  char *pcStack_2c;
  char *pcStack_2a;
  char *pcStack_28;
  char *pcStack_26;
  char *pcStack_24;
  char *pcStack_22;
  char *pcStack_20;
  char *pcStack_1e;
  char *local_1c;
  uint16_t uStack_1a;
  uint16_t uStack_18;
  brect_t bStack_16;
  char *pcStack_c;
  char *pcStack_a;
  undefined2 uStack_8;
  far_t fStack_6;
  
  iVar10 = 0x10;
  F_SCOPY((uint8_t *)&local_1c,(uint8_t *)(far_t *)far_t_ARRAY_2410_6e38,0x10);
  pcVar19 = (char *)((long)param_2 * 0x34);
  pcVar8 = (char *)pcVar19;
  pcStack_c = pcVar8;
  pcStack_a = (char *)&AgntAnms[0x75].field_0x18;
  if ((*(uint *)(pcVar8 + 0x2b) & 0x820) == 0) {
    uVar18 = (undefined2)((ulong)param_1 >> 0x10);
    iVar15 = (int)param_1;
    *(uint *)(iVar15 + 0x2b) = *(uint *)(iVar15 + 0x2b) & 0xfff7;
    if (*(byte *)((int)*(undefined4 *)(iVar15 + 0x17) + 0xf) < 8) {
      fStack_6 = far_from_u32((uint32_t)(far_to_u32(fStack_6) & 0xffffff));
    }
    else if (*(byte *)((int)*(undefined4 *)(iVar15 + 0x17) + 0xf) < 10) {
      (*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) = 1;
    }
    else if (*(byte *)((int)*(undefined4 *)(iVar15 + 0x17) + 0xf) < 0xc) {
      (*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) = 2;
    }
    else {
      (*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) = 3;
    }
    uVar12 = (uint)(*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1));
    if (uVar12 < 4) {
      switch(uVar12) {
      case 0:
        return (char *)((int)(undefined4 *)&_DATA + 1);
      case 2:
        cVar3 = *(char *)(uVar12 * 2 + unaff_SI);
        puVar16 = &stack0xfffe + unaff_SI;
        iVar15 = uVar12 * 3;
        *(undefined1 **)((char *)" You can only place a single arena." + 0xd + iVar15) =
             puVar16 + *(int *)((char *)" You can only place a single arena." + 0xd + iVar15);
        *(int *)(&stack0xffff + (int)puVar16) = *(int *)(&stack0xffff + (int)puVar16) + iVar15;
        *(int *)(&stack0xfffe + (int)unaff_DI) = *(int *)(&stack0xfffe + (int)unaff_DI) + iVar15;
                    /* WARNING: Read-only address (ram,0x00033501) is written */
        iRam00033501 = uVar12 + 0x8b26;
        cVar6 = (char)(&stack0xfed8 + (int)unaff_DI +
                      CONCAT11((char)((ulong)pcVar19 >> 0x18),(char)((ulong)pcVar19 >> 0x10) + cVar3
                              ));
        pcVar8 = (char *)(uint)(byte)((char)iVar15 + cVar6);
        (&stack0x6ffe)[(int)puVar16] = (&stack0x6ffe)[(int)puVar16];
        pcVar2 = pcVar8;
        *pcVar2 = *pcVar2 + cVar6;
        *(undefined2 *)(&stack0xfed6 + (int)unaff_DI) = 0x6000;
        pcVar2 = pcVar8 + -0x61f9;
        *pcVar2 = *pcVar2;
        cVar6 = *pcVar2;
        *(undefined1 **)(&stack0xfeda + (int)unaff_DI) = &stack0xfedc + (int)unaff_DI;
        uVar18 = *(undefined2 *)(&stack0xfeda + (int)unaff_DI);
        *(undefined2 *)(&stack0xfeda + (int)unaff_DI) = uVar18;
        if (iVar10 == 1 || cVar6 == '\0') {
          s_constructing_2410_06a4[10] = -0x6b;
          s_constructing_2410_06a4[0xb] = '\x06';
                    /* WARNING: Read-only address (ram,0x000247ae) is written */
        }
        uVar21 = in(&stack0xfed8 + (int)unaff_DI +
                    CONCAT11((char)((ulong)pcVar19 >> 0x18),(char)((ulong)pcVar19 >> 0x10) + cVar3))
        ;
        *unaff_DI = uVar21;
        *(undefined2 *)(&stack0xfed8 + (int)unaff_DI) = uVar18;
        *(undefined2 *)(&stack0xfed6 + (int)unaff_DI) = uVar18;
        *(undefined2 *)(&stack0xfed4 + (int)unaff_DI) = uVar18;
        *(undefined2 *)(&stack0xfed4 + (int)unaff_DI) =
             *(undefined2 *)(&stack0xfed4 + (int)unaff_DI);
        pcVar5 = (code *)swi(1);
        pcVar8 = (char *)(*pcVar5)();
        return pcVar8;
      case 3:
        do {
          TextBlitDstSeg = 0xa000;
          TextBlitX = uStack_8 + 6;
          TextBlitY = (uint16_t)(unaff_DI + 1);
          puVar14 = (undefined2 *)(iVar15 + unaff_SI * 4);
          pcVar8 = (char *)*puVar14;
          fStack_6.seg = puVar14[1];
          fStack_6.ofs = (uint16_t)pcVar8;
          if (*(char *)MK_FP(fStack_6.seg, fStack_6.ofs) == '%') {
            BlitLetterType = 2;
            uVar21 = 0xf;
            pfVar20 = (far_t *)(GUnitDescriptions + 0x15);
            pcVar7 = (char *)ovr_OVC45_77eb_226e();
            ovr_blitLabel((char *)CONCAT22(pcVar8,pcVar7),(uint8_t *)CONCAT22(uVar21,pfVar20),
                          CONCAT11(in_stack_0000fee1,in_stack_0000fee0),in_stack_0000fee2);
            pcVar8 = (char *)"puppetmaker" + 3;
            BlitLetterType = 0;
          }
          else if (*(char *)MK_FP(fStack_6.seg, fStack_6.ofs) == '@') {
            uVar21 = 0xf;
            pfVar20 = (far_t *)(GUnitDescriptions + 0x15);
            pcVar7 = (char *)ovr_OVC45_77eb_226e();
            pcVar8 = (char *)ovr_blitLabel((char *)CONCAT22(pcVar8,pcVar7),
                                           (uint8_t *)CONCAT22(uVar21,pfVar20),
                                           CONCAT11(in_stack_0000fee1,in_stack_0000fee0),
                                           in_stack_0000fee2);
          }
          else {
            uVar21 = 0xf;
            pfVar20 = (far_t *)(GUnitDescriptions + 0x15);
            pcVar7 = (char *)ovr_OVC45_77eb_226e();
            pcVar8 = (char *)ovr_blitLabel((char *)CONCAT22(pcVar8,pcVar7),
                                           (uint8_t *)CONCAT22(uVar21,pfVar20),
                                           CONCAT11(in_stack_0000fee1,in_stack_0000fee0),
                                           in_stack_0000fee2);
          }
          while( true ) {
            unaff_DI = unaff_DI + 7;
            unaff_SI = unaff_SI + 1;
            if (param_2 <= unaff_SI) {
              if (DAT_2410_5cef != -1) {
                pcVar8 = (char *)OVC28_6018_0634();
              }
              return pcVar8;
            }
            piVar13 = (int *)(iVar15 + unaff_SI * 4);
            if (*piVar13 != 0 || piVar13[1] != 0) break;
            pcVar8 = (char *)0x0;
          }
          in_stack_0000fee2 = (uint8_t)DAT_2000_d37e;
          in_stack_0000fee0 = (undefined1)DAT_2000_d37c;
          in_stack_0000fee1 = (undefined1)((uint)DAT_2000_d37c >> 8);
          (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = in_stack_0000fee2;
          gfx_03.ofs = DAT_2000_d37c;
          (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) = (char)((uint)DAT_2000_d37e >> 8);
          dst_02.seg = 0xa000;
          dst_02.ofs = uStack_8 + (int)unaff_DI * 0x140;
          ovr_blitLoadRleGfx(gfx_03,dst_02);
        } while( true );
      }
switchD_6000_ca06_caseD_1:
      (&stack0xfffe)[(int)unaff_DI] = (&stack0xfffe)[(int)unaff_DI] + (char)iVar10;
      *(undefined1 *)((int)unaff_DI + 0x15) = 0;
      bStack_3b = ovr_init2_3338_0388();
      while( true ) {
        if (DAT_2000_ccaf != '\0') goto LAB_6616_1054;
        if ((pcStack_2e != pcStack_2a) || (pcStack_30 != pcStack_2c)) {
          pcStack_2a = pcStack_2e;
          local_1c = pcStack_2e;
          pcStack_2c = pcStack_30;
          pcStack_1e = pcStack_30;
        }
        if (bStack_3b != 0) break;
        cVar6 = keyprocessor_6616_03bd();
        if (cVar6 != '\0') goto LAB_6616_1054;
        if ((pcStack_36 != pcStack_32) || (pcStack_38 != pcStack_34)) {
          pcStack_32 = pcStack_36;
          local_1c = pcStack_36;
          pcStack_34 = pcStack_38;
          pcStack_1e = pcStack_38;
          bStack_16.seg = uStack_8;
          gfx_00.seg = uStack_18;
          gfx_00.ofs = uStack_1a;
          dst.seg = uStack_8;
          dst.ofs = 0x8cc;
          ovr_blitLoadRleGfx(gfx_00,dst);
          (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)MiceCursors[3].seg;
          gfx.ofs = MiceCursors[3].ofs;
          (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)(MiceCursors[3].seg >> 8);
          ovr_blitGfx10(gfx,(uint16_t)(pcStack_36 + -6),(uint16_t)(pcStack_38 + -5),
                        (brect_t *)CONCAT22(unaff_SS,&bStack_16),0);
          ovr_miceBlitRect((brect_t *)CONCAT22(unaff_SS,&bStack_16));
          ovr_blitRect((brect_t *)CONCAT22(unaff_SS,&bStack_16));
          ovr_miceUpdate();
        }
        if (bStack_3b == 0) goto switchD_6000_ca06_caseD_1;
      }
      if (((((int)local_1c < 0xc) || (0xde < (int)local_1c)) || ((int)pcStack_1e < 7)) ||
         (0x96 < (int)pcStack_1e)) goto LAB_6616_1054;
      do {
        iVar10 = ovr_init2_3338_0388();
      } while (iVar10 != 0);
      pcStack_26 = (char *)0xffff;
      pcStack_28 = (char *)0xffff;
      pcStack_20 = pcStack_1e;
      bStack_3b = 0;
      pcVar8 = local_1c;
      do {
        cVar6 = keyprocessor_6616_03bd();
        if (cVar6 != '\0') goto LAB_6616_1054;
        if ((pcStack_36 != pcStack_32) || (pcStack_38 != pcStack_34)) {
          pcStack_32 = pcStack_36;
          pcStack_34 = pcStack_38;
          pcStack_20 = pcStack_38;
          pcVar8 = pcStack_36;
        }
        if ((int)pcVar8 < 0xc) {
          pcVar8 = (char *)"Borland C++ - Copyright 1991 Borland Intl." + 8;
        }
        if (0xde < (int)pcVar8) {
          pcVar8 = (char *)0xde;
        }
        if ((int)pcStack_20 < 7) {
          pcStack_20 = (char *)"Borland C++ - Copyright 1991 Borland Intl." + 3;
        }
        if (0x96 < (int)pcStack_20) {
          pcStack_20 = (char *)"%d \r" + 1;
        }
        if ((pcStack_26 != pcVar8) || (pcStack_28 != pcStack_20)) {
          bStack_16.seg = uStack_8;
          gfx_01.seg = uStack_18;
          gfx_01.ofs = uStack_1a;
          (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = (char)uStack_8;
          dst_00.ofs = 0x8cc;
          (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = (char)(uStack_8 >> 8);
          ovr_blitLoadRleGfx(gfx_01,dst_00);
          ovr_vga_2d63_04b7();
          ovr_vga_2d63_04b7();
          ovr_vga_2d63_04b7();
          ovr_vga_2d63_04b7();
          ovr_miceBlitRect((brect_t *)CONCAT22(unaff_SS,&bStack_16));
          ovr_blitRect((brect_t *)CONCAT22(unaff_SS,&bStack_16));
          ovr_miceUpdate();
          pcVar7 = (char *)((int)(pcStack_20 + -9) / 3 + Seed_2000_d10e);
          pcVar11 = (char *)(Seed_2000_d110 + ((uint)(pcVar8 + -0xc) >> 1) + 2 & 0xfffc);
          pcStack_24 = (char *)((int)(pcStack_1e + -9) / 3 + Seed_2000_d10e);
          pcStack_22 = (char *)(Seed_2000_d110 + ((uint)(local_1c + -0xc) >> 1) + 2 & 0xfffc);
          pcStack_26 = pcVar11;
          if ((int)pcVar11 < (int)pcStack_22) {
            pcStack_26 = pcStack_22;
            pcStack_22 = pcVar11;
            pcStack_c = pcVar11;
          }
          pcStack_28 = pcVar7;
          if ((int)pcVar7 < (int)pcStack_24) {
            pcStack_28 = pcStack_24;
            pcStack_24 = pcVar7;
            pcStack_c = pcVar7;
          }
          pcStack_a = (char *)0x0;
          for (uVar12 = 0; uVar12 < EntityCount; uVar12 = uVar12 + 1) {
            uVar17 = Entities.seg;
            uVar9 = Entities.ofs;
            if ((((*(char *)(uVar9 + uVar12 * 0x37 + 0x1a) == cStack_3c) &&
                 (pcStack_22 <= (char *)*(uint *)(uVar9 + uVar12 * 0x37))) &&
                ((char *)*(uint *)(uVar9 + uVar12 * 0x37) <= pcStack_26)) &&
               ((pcStack_24 <= (char *)*(uint *)(uVar9 + uVar12 * 0x37 + 2) &&
                ((char *)*(uint *)(uVar9 + uVar12 * 0x37 + 2) <= pcStack_28)))) {
              pcStack_a = pcStack_a + 1;
            }
          }
          ovr_font_302d_0a30();
          ovr_OVC45_77eb_226e();
          ovr_OVC41_6a8f_0000();
          pcVar19 = ovr_stsprintf(&stack0xfece,
                                  "%d %s%s loyal to %s found. Left click: set triangles. R: ready. U: unassign. H: home. Right click: abort."
                                  ,pcStack_a);
          ovr_uiNotify(pcVar19,in_stack_0000ff10);
        }
        pcStack_28 = pcStack_20;
        pcStack_26 = pcVar8;
        if (bStack_3b == 0) {
          bStack_3b = ovr_init2_3338_0388();
        }
        if (DAT_2000_ccaf != '\0') goto LAB_6616_1054;
        if ((pcStack_2e != pcStack_2a) || (pcStack_30 != pcStack_2c)) {
          pcStack_2a = pcStack_2e;
          pcStack_2c = pcStack_30;
          pcStack_20 = pcStack_30;
          pcVar8 = pcStack_2e;
        }
      } while (bStack_3b == 0);
      ovr_miceRestoreArea(BlitRects + 1);
      if (((((int)pcVar8 < 0xc) || (0xde < (int)pcVar8)) || ((int)pcStack_20 < 7)) ||
         (0x96 < (int)pcStack_20)) {
LAB_6616_1054:
        ovr_miceRestoreArea(BlitRects + 1);
        ovr_say("Region selection aborted.");
      }
      else {
        pcVar7 = (char *)((int)(pcStack_20 + -9) / 3 + Seed_2000_d10e);
        pcVar11 = (char *)(Seed_2000_d110 + ((uint)(pcVar8 + -0xc) >> 1) + 2 & 0xfffc);
        pcVar8 = (char *)((int)(pcStack_1e + -9) / 3 + Seed_2000_d10e);
        uVar12 = Seed_2000_d110 + ((uint)(local_1c + -0xc) >> 1) + 2;
        pcStack_22 = (char *)(uVar12 & 0xfffc);
        pcStack_26 = pcVar11;
        if ((int)pcVar11 < (int)pcStack_22) {
          pcStack_c = (char *)(uVar12 & 0xfffc);
          pcStack_26 = pcStack_c;
          pcStack_22 = pcVar11;
        }
        pcStack_28 = pcVar7;
        pcStack_24 = pcVar8;
        if ((int)pcVar7 < (int)pcVar8) {
          pcStack_28 = pcVar8;
          pcStack_24 = pcVar7;
          pcStack_c = pcVar8;
        }
        _fmemset((char *)CONCAT22(unaff_SS,acStack_42),0,5);
        pcStack_a = (char *)0x0;
        for (uVar12 = 0; uVar12 < EntityCount; uVar12 = uVar12 + 1) {
          uVar17 = Entities.seg;
          uVar9 = Entities.ofs;
          if (((*(char *)(uVar9 + uVar12 * 0x37 + 0x1a) == cStack_3c) &&
              (pcStack_22 <= (char *)*(uint *)(uVar9 + uVar12 * 0x37))) &&
             (((char *)*(uint *)(uVar9 + uVar12 * 0x37) <= pcStack_26 &&
              ((pcStack_24 <= (char *)*(uint *)(uVar9 + uVar12 * 0x37 + 2) &&
               ((char *)*(uint *)(uVar9 + uVar12 * 0x37 + 2) <= pcStack_28)))))) {
            if (bStack_3b < 2) {
              unit_6616_10d5();
            }
            else {
              unit_6616_12ce();
            }
            pcStack_a = pcStack_a + 1;
          }
        }
        for (iStack_3a = 0; iStack_3a < 5; iStack_3a = iStack_3a + 1) {
          if (acStack_42[iStack_3a] != '\0') {
            ovr_OVC41_6a8f_1be0();
          }
        }
        ovr_constr_36ce_1db4();
        ovr_font_302d_0a30();
        if (bStack_3b == 1) {
          ovr_OVC41_6a8f_0000();
          pcVar19 = ovr_stsprintf(&stack0xfece,"Priorities adjusted for %d %s%s.",pcStack_a);
          ovr_say(pcVar19);
        }
        else if (bStack_3b == 2) {
          ovr_OVC41_6a8f_0000();
          pcVar19 = ovr_stsprintf(&stack0xfece,"%d %s%s unassigned.",pcStack_a);
          ovr_say(pcVar19);
        }
        else if (bStack_3b == 3) {
          ovr_OVC41_6a8f_0000();
          pcVar19 = ovr_stsprintf(&stack0xfece,"%d %s%s readied.",pcStack_a);
          ovr_say(pcVar19);
        }
        else if (bStack_3b == 4) {
          ovr_OVC41_6a8f_0000();
          pcVar19 = ovr_stsprintf(&stack0xfece,"%d %s%s homed.",pcStack_a);
          ovr_say(pcVar19);
        }
        ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
      }
      bStack_16.seg = uStack_8;
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)uStack_18;
      gfx_02.ofs = uStack_1a;
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = (char)(uStack_18 >> 8);
      dst_01.seg = uStack_8;
      dst_01.ofs = 0x8cc;
      ovr_blitLoadRleGfx(gfx_02,dst_01);
      ovr_miceBlitRect((brect_t *)CONCAT22(unaff_SS,&bStack_16));
      ovr_blitRect((brect_t *)CONCAT22(unaff_SS,&bStack_16));
      ovr_miceUpdate();
      handle.seg = uStack_18;
      handle.ofs = uStack_1a;
      ovr_stshFree(handle);
      ovr_stshFree(fStack_6);
      pcVar8 = (char *)ovr_miceRestoreArea(BlitRects + 1);
      return pcVar8;
    }
    bVar4 = pcVar8[0x21];
    pcVar8[0x21] = pcVar8[0x21] + (char)fStack_6.ofs;
    if ((byte)pcVar8[0x22] < (byte)pcVar8[0x21]) {
      pcVar8[0x21] = pcVar8[0x22];
    }
    pbVar1 = (byte *)(pcVar8 + 0x21);
    pcVar8 = (char *)(uint)*pbVar1;
    if (*pbVar1 != bVar4) {
      (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = bVar4;
      uVar9 = ovr_audio_3a5b_0afd();
      ovr_play_sfxU(0x3b,0,uVar9);
      OVC41_6a8f_0000();
      OVC41_6a8f_0000();
      ovr_agnt_3b1d_0ac0();
      ovr_agnt_3b1d_0ac0();
      pcVar8 = (char *)ovr_OVC15_4207_1c16();
      pcVar19 = ovr_stsprintf(local_94,
                              "%s casts %s on %s to heal %d hitpoint%s for a total of %d hitpoint%s."
                              ,pcVar8);
      pcVar8 = (char *)pcVar19;
      ovr_uiNotify(pcVar19,in_stack_0000fef6);
    }
  }
  return pcVar8;
}



/* 6a8f:22cb */

void __cdecl16far OVC41_6a8f_22cb(undefined4 param_1,int param_2)

{
  uint *puVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  undefined2 uVar5;
  char *pcVar6;
  uint16_t uVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined1 local_120 [80];
  undefined1 local_d0 [80];
  char local_80 [120];
  int iStack_8;
  undefined2 uStack_6;
  char cStack_3;
  
  cVar2 = OVC41_6a8f_0b39();
  if (((cVar2 == '\0') && (-1 < param_2)) && (param_2 < (int)(uint)AgntCount)) {
    uVar8 = (uint)((ulong)((long)param_2 * 0x34) >> 0x10);
    iVar4 = (int)((long)param_2 * 0x34);
    _iStack_8 = CONCAT22(0x1726,iVar4);
    if (*(char *)(iVar4 + 0x11) == '\0') {
      *(undefined1 *)(iVar4 + 4) = 0;
      *(undefined1 *)(iVar4 + 5) = 0;
    }
    if ((*(uint *)((int)param_1 + 0x2b) & 8) == 0) {
      if (*(char *)((int)param_1 + 0x2e) == '\0') {
        if ((*(char *)((int)param_1 + 0xd) == '\x04') &&
           ((*(uint *)((int)*(undefined4 *)((int)param_1 + 0x1d) + 0x3e) & 0x200) != 0)) {
          bVar3 = *(byte *)((int)param_1 + 0x21);
          cVar2 = ovr_OVC27_5ded_105e();
          uVar9 = (uint)bVar3;
          if (cVar2 != '\0') {
            uVar9 = (int)(uint)bVar3 >> 1;
          }
        }
        else {
          bVar3 = ovr_manage_4d05_01a3();
          iVar4 = (uint)bVar3 + (uint)*(byte *)((int)*(undefined4 *)((int)param_1 + 0x1d) + 0x3a);
          cVar2 = ovr_agnt_3b1d_0c9f((int)param_1);
          uVar8 = iVar4 + cVar2;
          uVar9 = uVar8;
        }
        if ((uVar9 != 0) && ((*(uint *)((int)*(undefined4 *)((int)param_1 + 0x1d) + 0x40) & 8) != 0)
           ) {
          cVar2 = ovr_agnt_3b1d_0c1e();
          uVar9 = uVar9 + (int)cVar2;
          if ((int)uVar9 < 1) {
            uVar9 = 1;
          }
        }
        uVar11 = *(undefined4 *)((int)_iStack_8 + 0x1d);
        if (((*(uint *)((int)uVar11 + 0x3e) & 8) == 0) ||
           (cVar2 = ovr_agnt_3b1d_0c9f(), '\0' < cVar2)) {
          uVar11 = *(undefined4 *)((int)_iStack_8 + 0x1d);
          if (((*(uint *)((int)uVar11 + 0x40) & 0x40) == 0) ||
             (cVar2 = ovr_agnt_3b1d_0c9f(), '\x01' < cVar2)) {
            uVar5 = (undefined2)((ulong)_iStack_8 >> 0x10);
            iVar4 = (int)_iStack_8;
            if (((*(uint *)((int)*(undefined4 *)(iVar4 + 0x1d) + 0x3e) & 0x10) == 0) ||
               (*(char *)((int)param_1 + 0xd) != '\x02')) {
              cStack_3 = OVC41_6a8f_1c74((int)param_1,(*(uint16_t *)((uint8_t *)&(param_1) + 2)),iVar4,uVar5,uVar9);
              if ((cStack_3 == '\0') &&
                 ((*(char *)((int)param_1 + 0xd) == '\0' &&
                  ((*(uint *)((int)*(undefined4 *)((int)param_1 + 0x1d) + 0x3e) & 2) != 0)))) {
                cVar2 = ovr_OVC27_5ded_1c94(iStack_8,(int)((ulong)_iStack_8 >> 0x10),0);
                if (cVar2 == '\0') {
                  uVar7 = DAT_2000_d0f7;
                  uVar5 = ovr_agnt_3b1d_0ac0(iStack_8,(int)((ulong)_iStack_8 >> 0x10),local_120);
                  uVar11 = CONCAT22(uVar8,uVar5);
                  uVar5 = ovr_agnt_3b1d_0ac0((int)param_1,(*(uint16_t *)((uint8_t *)&(param_1) + 2)),local_d0);
                  pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar5,uVar8,uVar11);
                  pcVar10 = ovr_stsprintf(local_80,"%s poisons %s.",pcVar6);
                  uVar8 = (uint)((ulong)pcVar10 >> 0x10);
                  ovr_uiNotify(pcVar10,uVar7);
                  uVar7 = ovr_audio_3a5b_0afd();
                  ovr_play_sfxU(0x55,0,uVar7);
                  OVC41_6a8f_063f();
                  cStack_3 = '\x01';
                }
              }
              if ((cStack_3 == '\0') &&
                 ((*(uint *)((int)*(undefined4 *)((int)param_1 + 0x1d) + 0x3e) & 4) != 0)) {
                cVar2 = ovr_OVC27_5ded_1c94(iStack_8,(int)((ulong)_iStack_8 >> 0x10),0);
                if (cVar2 == '\0') {
                  uVar5 = (undefined2)((ulong)_iStack_8 >> 0x10);
                  uVar11 = *(undefined4 *)((int)_iStack_8 + 0x17);
                  if ((*(uint *)((int)uVar11 + 0x14) & 1) == 0) {
                    uVar7 = DAT_2000_d0f7;
                    uVar5 = ovr_agnt_3b1d_0ac0((int)_iStack_8,uVar5,local_120);
                    uVar11 = CONCAT22(uVar8,uVar5);
                    uVar5 = ovr_agnt_3b1d_0ac0((int)param_1,(*(uint16_t *)((uint8_t *)&(param_1) + 2)),local_d0);
                    pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar5,uVar8,uVar11);
                    pcVar10 = ovr_stsprintf(local_80,"%s infects %s with blast spore disease.",
                                            pcVar6);
                    uVar8 = (uint)((ulong)pcVar10 >> 0x10);
                    ovr_uiNotify(pcVar10,uVar7);
                    uVar7 = ovr_audio_3a5b_0afd();
                    ovr_play_sfxU(5,0,uVar7);
                    uVar11 = *(undefined4 *)((int)_iStack_8 + 0x17);
                    puVar1 = (uint *)((int)uVar11 + 0x14);
                    *puVar1 = *puVar1 | 1;
                  }
                }
              }
              if (((cStack_3 == '\0') &&
                  ((*(uint *)((int)*(undefined4 *)((int)param_1 + 0x1d) + 0x3e) & 0x400) != 0)) &&
                 (uVar7 = ovr_randBelow((uint)*(byte *)((int)*(undefined4 *)((int)param_1 + 0x17) +
                                                       0xe)), (uVar7 & 0xff) == 0)) {
                cVar2 = ovr_OVC27_5ded_1fe1((int)param_1,(*(uint16_t *)((uint8_t *)&(param_1) + 2)),iStack_8,
                                            (int)((ulong)_iStack_8 >> 0x10),1);
                if (cVar2 == '\0') {
                  uVar7 = DAT_2000_d0f7;
                  uVar5 = ovr_agnt_3b1d_0ac0(iStack_8,uStack_6,local_120);
                  uVar11 = CONCAT22(uVar8,uVar5);
                  uVar5 = ovr_agnt_3b1d_0ac0((int)param_1,(*(uint16_t *)((uint8_t *)&(param_1) + 2)),local_d0);
                  pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar5,uVar8,uVar11);
                  pcVar10 = ovr_stsprintf(local_80,"%s drains all energy from %s.",pcVar6);
                  uVar8 = (uint)((ulong)pcVar10 >> 0x10);
                  ovr_uiNotify(pcVar10,uVar7);
                }
                else {
                  uVar7 = DAT_2000_d0f7;
                  uVar5 = ovr_agnt_3b1d_0ac0(iStack_8,uStack_6,local_120);
                  uVar11 = CONCAT22(uVar8,uVar5);
                  uVar5 = ovr_agnt_3b1d_0ac0((int)param_1,(*(uint16_t *)((uint8_t *)&(param_1) + 2)),local_d0);
                  pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar5,uVar8,uVar11);
                  pcVar10 = ovr_stsprintf(local_80,"%s drains a level from %s.",pcVar6);
                  uVar8 = (uint)((ulong)pcVar10 >> 0x10);
                  ovr_uiNotify(pcVar10,uVar7);
                }
              }
              if (((cStack_3 == '\0') &&
                  ((*(uint *)((int)*(undefined4 *)((int)param_1 + 0x1d) + 0x3e) & 0x800) != 0)) &&
                 (uVar7 = ovr_randBelow((uint)*(byte *)((int)*(undefined4 *)((int)param_1 + 0x17) +
                                                       0xe)), (uVar7 & 0xff) == 0)) {
                cVar2 = ovr_OVC27_5ded_1fe1((int)param_1,(*(uint16_t *)((uint8_t *)&(param_1) + 2)),iStack_8,
                                            (int)((ulong)_iStack_8 >> 0x10),2);
                if (cVar2 == '\0') {
                  uVar7 = DAT_2000_d0f7;
                  uVar5 = ovr_agnt_3b1d_0ac0(iStack_8,uStack_6,local_120);
                  uVar11 = CONCAT22(uVar8,uVar5);
                  uVar5 = ovr_agnt_3b1d_0ac0((int)param_1,(*(uint16_t *)((uint8_t *)&(param_1) + 2)),local_d0);
                  pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar5,uVar8,uVar11);
                  pcVar10 = ovr_stsprintf(local_80,"%s drains all energy from %s.",pcVar6);
                  ovr_uiNotify(pcVar10,uVar7);
                }
                else {
                  uVar7 = DAT_2000_d0f7;
                  uVar5 = ovr_agnt_3b1d_0ac0(iStack_8,uStack_6,local_120);
                  uVar11 = CONCAT22(uVar8,uVar5);
                  uVar5 = ovr_agnt_3b1d_0ac0((int)param_1,(*(uint16_t *)((uint8_t *)&(param_1) + 2)),local_d0);
                  pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar5,uVar8,uVar11);
                  pcVar10 = ovr_stsprintf(local_80,"%s drains two levels from %s.",pcVar6);
                  ovr_uiNotify(pcVar10,uVar7);
                }
              }
            }
            else {
              uVar7 = DAT_2000_d0f7;
              uVar5 = ovr_agnt_3b1d_0ac0(iVar4,uVar5,local_d0);
              pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar5);
              pcVar10 = ovr_stsprintf(local_80,"%s takes no damage from missile attacks.",pcVar6);
              ovr_uiNotify(pcVar10,uVar7);
              uVar7 = ovr_audio_3a5b_0afd();
              ovr_play_sfxU(0x16,0,uVar7);
            }
          }
          else {
            uVar7 = DAT_2000_d0f7;
            uVar5 = ovr_agnt_3b1d_0ac0(iStack_8,(int)((ulong)_iStack_8 >> 0x10),local_d0);
            pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar5);
            pcVar10 = ovr_stsprintf(local_80,"%s takes no damage from less than +2 weapons.",pcVar6)
            ;
            ovr_uiNotify(pcVar10,uVar7);
            uVar7 = ovr_audio_3a5b_0afd();
            ovr_play_sfxU(0x16,0,uVar7);
          }
        }
        else {
          uVar7 = DAT_2000_d0f7;
          uVar5 = ovr_agnt_3b1d_0ac0(iStack_8,(int)((ulong)_iStack_8 >> 0x10),local_d0);
          pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar5);
          pcVar10 = ovr_stsprintf(local_80,"%s takes no damage from non-magical weapons.",pcVar6);
          ovr_uiNotify(pcVar10,uVar7);
          uVar7 = ovr_audio_3a5b_0afd();
          ovr_play_sfxU(0x16,0,uVar7);
        }
      }
      else {
        ovr_OVC27_5ded_10ea();
      }
    }
    else {
      OVC41_6a8f_2084((int)param_1,(*(uint16_t *)((uint8_t *)&(param_1) + 2)),param_2);
    }
  }
  return;
}



/* 6a8f:297d */

void __cdecl16far OVC41_6a8f_297d(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  OVC41_6a8f_22cb(param_1,param_2,param_3);
  ovr_agnt_3b1d_0a9f(param_1,param_2);
  return;
}



/* 6a8f:29a0 */

void __cdecl16far OVC41_6a8f_29a0(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    if (*(char *)(iVar1 * 0x34 + 0x2f) != '\0') {
      OVC41_6a8f_063f(0,0,iVar1 * 0x34,0x1726);
    }
  }
  return;
}



/* 6a8f:29ea */

int __cdecl16far OVC41_6a8f_29ea(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  int local_30 [22];
  byte bStack_4;
  byte bStack_3;
  
  F_SCOPY((uint8_t *)local_30,(uint8_t *)0x6e48,0x2c);
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  bStack_3 = *(byte *)((int)param_1 + 0xd);
  if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bStack_3 * 0x95) == -1) {
    iVar1 = *(int *)((int)&far_t_ARRAY_2410_26f7[9].seg + 1 + (uint)bStack_3 * 0x95);
  }
  else {
    bStack_4 = *(byte *)((int)param_1 + 0xf);
    if (bStack_4 < 0x16) {
      iVar1 = local_30[bStack_4];
    }
    else {
      iVar1 = (uint)bStack_4 * 0xfa + -0xabe;
    }
  }
  return iVar1;
}


