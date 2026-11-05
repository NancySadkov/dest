/*
 * crtl.c - recovered from STRONG.EXE
 * memory block: 1000_TEXT_crtl
 * range: 1000:0000 - 1000:301b
 * functions: 175
 */
#include "recovered.h"


/* 1000:0000 */

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void startx(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  code *pcVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  undefined2 uVar10;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  undefined1 *puVar11;
  int *piVar12;
  char *pcVar13;
  char *pcVar14;
  uint uVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined2 unaff_ES;
  undefined2 uVar18;
  bool bVar19;
  undefined4 uVar20;
  
  puVar11 = (undefined1 *)((int)(int *)&errno + 1);
  DGROUP_at__at_ = (char *)"puppetmaker" + 3;
  pcVar3 = (code *)swi(0x21);
  uVar20 = (*pcVar3)();
  iVar9 = _DATA._2_2_;
  uVar10 = (undefined2)((ulong)uVar20 >> 0x10);
  *(dosver_t *)&DosVersion = SUB42(uVar20,0);
  *(undefined2 *)&_psp = unaff_ES;
  ((char *)&_envseg_at_)[0] = 'l';
  ((char *)&_envseg_at_)[1] = '.';
  *(int *)&_heaptop.seg = iVar9;
  *(undefined2 *)(puVar11 + -2) = 0x28;
  SaveVectors();
  pcVar4 = (char *)*(undefined4 *)&_env;
  uVar18 = (undefined2)((ulong)pcVar4 >> 0x10);
  pcVar13 = (char *)pcVar4;
  uVar8 = 0x7fff;
  pcVar14 = pcVar13;
LAB_1000_0034:
  do {
    if (uVar8 != 0) {
      uVar8 = uVar8 - 1;
      pcVar1 = pcVar14;
      pcVar14 = pcVar14 + 1;
      if ((char)pcVar4 != *pcVar1) goto LAB_1000_0034;
    }
    if (uVar8 == 0) goto LAB_1000_007b;
    pcVar13 = pcVar13 + 1;
  } while (*pcVar14 != (char)pcVar4);
  *(int *)&_env = -(uVar8 | 0x8000);
  *(uint *)&_envSize_at_ = (int)pcVar13 * 4 + 0x10U & 0xfff0;
  if (__stklen < 0x200) {
    __stklen = 0x200;
  }
  bVar7 = 4;
  uVar8 = __stklen >> 4;
  uVar15 = uVar8 + 1;
  if (iVar9 + 0xd2a6U < uVar15) {
LAB_1000_007b:
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  *(undefined2 *)&_heapbase.seg = (char *)"blasts.lbm" + 2 + uVar8;
  *(undefined2 *)&_brklvl.seg = (char *)"blasts.lbm" + 2 + uVar8;
  piVar12 = (int *)(puVar11 + -2);
  *(uint *)(puVar11 + -2) = uVar15;
  pcVar3 = (code *)swi(0x21);
  (*pcVar3)();
  pcVar14 = DGROUP_at__at_;
  puVar16 = (undefined1 *)(*piVar12 << (bVar7 & 0x1f));
  puVar17 = (undefined1 *)&bdata_at_;
  __stklen = (uint16_t)puVar16;
  for (iVar9 = 0xb66; iVar9 != 0; iVar9 = iVar9 + -1) {
    puVar2 = puVar17;
    puVar17 = puVar17 + 1;
    *puVar2 = 0;
  }
  if (0x14 < *(uint *)&_nfile) {
    bVar7 = ((dosver_t *)&DosVersion)->major;
    bVar19 = bVar7 < 3;
    if ((!bVar19) && ((3 < bVar7 || (bVar19 = *(byte *)&DosVersion.minor < 0x1e, !bVar19)))) {
      pcVar3 = (code *)swi(0x21);
      (*pcVar3)();
      if (!bVar19) {
        pcVar3 = (code *)swi(0x21);
        (*pcVar3)();
        if (!bVar19) {
          pcVar3 = (code *)swi(0x21);
          iVar6 = (*pcVar3)();
          if (!bVar19) {
            *(int *)&_heaptop.seg = iVar6 + 1;
            pcVar3 = (code *)swi(0x21);
            (*pcVar3)();
            if (!bVar19) {
              pcVar3 = (code *)swi(0x21);
              (*pcVar3)();
              if (!bVar19) goto LAB_1000_0109;
            }
          }
        }
      }
                    /* WARNING: Subroutine does not return */
      _abort();
    }
  }
LAB_1000_0109:
  pcVar3 = (code *)swi(0x1a);
  cVar5 = (*pcVar3)();
  *(undefined2 *)(uint32_t *)&_StartTime = extraout_DX_00;
  *(int *)((int)(uint32_t *)&_StartTime + 2) = iVar9;
  if (cVar5 != '\0') {
    bda_midnight = 1;
  }
  *(undefined2 *)(puVar16 + -2) = 0x135;
  StartExit();
  *(undefined2 *)(puVar16 + -2) = *(undefined2 *)&__C0environ_2;
  *(undefined2 *)(puVar16 + -4) = *(undefined2 *)&__C0environ;
  *(undefined2 *)(puVar16 + -6) = *(undefined2 *)&__C0argv_2;
  *(undefined2 *)(puVar16 + -8) = *(undefined2 *)&__C0argv;
  *(undefined2 *)(puVar16 + -10) = *(undefined2 *)&__C0argc;
  *(undefined2 *)(puVar16 + -0xc) = 0x1000;
  *(undefined2 *)(puVar16 + -0xe) = 0x14e;
  iVar9 = main(*(int *)(puVar16 + -10),*(str_t **)(puVar16 + -8),*(str_t **)(puVar16 + -4));
  *(int *)(puVar16 + -4) = iVar9;
  *(undefined2 *)(puVar16 + -6) = 0x1301;
                    /* WARNING: Subroutine does not return */
  *(undefined2 *)(puVar16 + -8) = 0x154;
  exit(*(int *)(puVar16 + -4));
}



/* 1000:0154 */

void __cdecl16far __cleanup(void)

{
  StartExit();
  return;
}



/* 1000:0167 */

void __cdecl16far __checknull(void)

{
  return;
}



/* 1000:0168 */

void __cdecl16far _terminate(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  ErrorDisplay();
                    /* WARNING: Subroutine does not return */
  __exit();
}



/* 1000:0171 */

void __cdecl16far ZeroDivision(void)

{
  ErrorDisplay();
                    /* WARNING: Subroutine does not return */
  __exit(3);
}



/* 1000:017a */

void __cdecl16near SaveVectors(void)

{
  code *pcVar1;
  uint16_t in_BX;
  uint16_t unaff_ES;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  GSTARTX_SavedVectors[0].ofs = in_BX;
  GSTARTX_SavedVectors[0].seg = unaff_ES;
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  GSTARTX_SavedVectors[1].ofs = in_BX;
  GSTARTX_SavedVectors[1].seg = unaff_ES;
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  GSTARTX_SavedVectors[2].ofs = in_BX;
  GSTARTX_SavedVectors[2].seg = unaff_ES;
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  GSTARTX_SavedVectors[3].ofs = in_BX;
  GSTARTX_SavedVectors[3].seg = unaff_ES;
  (*pcVar1)();
  return;
}



/* 1000:01bd */

void __cdecl16far __restorezero(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return;
}



/* 1000:01ea */

void __cdecl16near StartExit(void)

{
  byte bVar1;
  uint8_t uVar2;
  byte bVar3;
  boinit_t *pbVar4;
  boinit_t *pbVar5;
  boinit_t *unaff_SI;
  boinit_t *unaff_DI;
  undefined2 unaff_ES;
  bool bVar6;
  
  while( true ) {
    pbVar4 = unaff_DI;
    pbVar5 = unaff_SI;
    if (unaff_SI == (boinit_t *)InitStart) {
      bVar3 = 0xff;
    }
    else {
      bVar3 = 0;
    }
    for (; pbVar5 != unaff_DI; pbVar5 = pbVar5 + 1) {
      if (pbVar5->calltype != 0xff) {
        if (unaff_SI == (boinit_t *)InitStart) {
          bVar1 = pbVar5->priority;
          bVar6 = bVar1 < bVar3;
        }
        else {
          bVar1 = pbVar5->priority;
          bVar6 = bVar3 < bVar1;
        }
        if (bVar6 || bVar3 == bVar1) {
          bVar3 = pbVar5->priority;
          pbVar4 = pbVar5;
        }
      }
    }
    if (pbVar4 == unaff_DI) break;
    uVar2 = pbVar4->calltype;
    pbVar4->calltype = 0xff;
    if (uVar2 == 0x0) {
      (*(code *)(&pbVar4->addr)->ofs)();
    }
    else {
      (*(code *)(&pbVar4->addr)->ofs)(0x1000);
    }
  }
  return;
}



/* 1000:0241 */

void __cdecl16near ErrorDisplay(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return;
}



/* 1000:0249 */

void __cdecl16far _abort(void)

{
  ErrorDisplay();
                    /* WARNING: Subroutine does not return */
  __exit(3);
}



/* 1000:026c */

bool __cdecl16far audio_init(uint16_t seg)

{
  int iVar1;
  
  audio_init_data.seg = seg - 0x10;
  iVar1 = func_0x00010264(0x1000);
  return iVar1 == 0;
}



/* 1000:0295 */

void __cdecl16far audio_done(uint16_t seg)

{
  fp_audio_done.seg = seg - 0x10;
  func_0x00010268(0x1000);
  return;
}



/* 1000:02c9 */

uint32_t __cdecl16far xms_init(void)

{
  code *pcVar1;
  char cVar2;
  code *in_BX;
  uint16_t unaff_ES;
  undefined4 uVar3;
  
  pcVar1 = (code *)swi(0x2f);
  cVar2 = (*pcVar1)();
  if (cVar2 == -0x80) {
    pcVar1 = (code *)swi(0x2f);
    (*pcVar1)();
    xms_driver.ofs = (uint16_t)in_BX;
    xms_driver.seg = unaff_ES;
    xms_handle = (*in_BX)(0x1000);
    if (xms_handle != 0) {
      uVar3 = (*(code *)xms_driver.ofs)(0x1000);
      if ((int)uVar3 != 0) {
        xms_data2 = (int)((ulong)uVar3 >> 0x10);
        return CONCAT22(xms_handle >> 6,xms_handle << 10);
      }
    }
  }
  xms_handle = 0;
  return 0;
}



/* 1000:032f */

void __cdecl16far
xms_1000_032f(int param_1,undefined2 param_2,uint param_3,int param_4,uint param_5,int param_6)

{
  bool bVar1;
  
  DAT_1000_02bd = xms_data2;
  DAT_1000_02bf = param_3;
  DAT_1000_02c1 = param_4;
  DAT_1000_02c3 = 0;
  DAT_1000_02c5 = param_1;
  DAT_1000_02c7 = param_2;
  if ((param_5 & 1) != 0) {
    DAT_1000_02b9 = 2;
    DAT_1000_02bb = 0;
    (*(code *)xms_driver.ofs)(0x1000);
    bVar1 = 0xfffe < DAT_1000_02bf;
    DAT_1000_02bf = DAT_1000_02bf + 1;
    DAT_1000_02c1 = DAT_1000_02c1 + (uint)bVar1;
    DAT_1000_02c5 = DAT_1000_02c5 + 1;
    bVar1 = param_5 == 0;
    param_5 = param_5 - 1;
    param_6 = param_6 - (uint)bVar1;
    if ((param_6 == 0) && (param_5 == 0)) {
      return;
    }
  }
  DAT_1000_02b9 = param_5;
  DAT_1000_02bb = param_6;
  (*(code *)xms_driver.ofs)(0x1000);
  return;
}



/* 1000:03c2 */

void __cdecl16far
xms_1000_03c2(uint param_1,int param_2,int param_3,undefined2 param_4,uint param_5,int param_6)

{
  bool bVar1;
  
  DAT_1000_02bd = 0;
  DAT_1000_02bf = param_3;
  DAT_1000_02c1 = param_4;
  DAT_1000_02c3 = xms_data2;
  DAT_1000_02c5 = param_1;
  DAT_1000_02c7 = param_2;
  if ((param_5 & 1) != 0) {
    DAT_1000_02b9 = 2;
    DAT_1000_02bb = 0;
    (*(code *)xms_driver.ofs)(0x1000);
    DAT_1000_02bf = DAT_1000_02bf + 1;
    bVar1 = 0xfffe < DAT_1000_02c5;
    DAT_1000_02c5 = DAT_1000_02c5 + 1;
    DAT_1000_02c7 = DAT_1000_02c7 + (uint)bVar1;
    bVar1 = param_5 == 0;
    param_5 = param_5 - 1;
    param_6 = param_6 - (uint)bVar1;
  }
  DAT_1000_02b9 = param_5;
  DAT_1000_02bb = param_6;
  (*(code *)xms_driver.ofs)(0x1000);
  return;
}



/* 1000:044f */

void __cdecl16far xmsFree(void)

{
  if (xms_handle != 0) {
    (*(code *)xms_driver.ofs)(0x1000);
  }
  return;
}



/* 1000:0472 */

void __cdecl16far xms_1000_0472(uint32_t handle)

{
  ulong uVar1;
  int iVar2;
  
  uVar1 = handle + 0x3ff;
  iVar2 = 10;
  do {
    xms_handle = (undefined2)(CONCAT12((uVar1 & 0x10000) != 0,(int)uVar1) >> 1);
    uVar1 = CONCAT22((uint)(uVar1 >> 0x11),xms_handle);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  (*(code *)xms_driver.ofs)(0x1000);
  return;
}



/* 1000:04b3 */

uint32_t __cdecl16far ems_init(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  char extraout_AH;
  undefined2 uVar4;
  char extraout_AH_00;
  char extraout_AH_01;
  int iVar5;
  uint extraout_DX;
  undefined2 extraout_DX_00;
  uint uVar6;
  undefined1 in_CF;
  bool bVar7;
  
  pcVar1 = (code *)swi(0x21);
  iVar3 = (*pcVar1)();
  if (!(bool)in_CF) {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    if ((!(bool)in_CF) && (bVar7 = false, (extraout_DX & 0x80) != 0)) {
      pcVar1 = (code *)swi(0x21);
      cVar2 = (*pcVar1)();
      if ((!bVar7) && (bVar7 = false, cVar2 != '\0')) {
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)();
        if (!bVar7) {
          pcVar1 = (code *)swi(0x67);
          (*pcVar1)();
          if (extraout_AH == '\0') {
            pcVar1 = (code *)swi(0x67);
            uVar4 = (*pcVar1)();
            if (((char)((uint)uVar4 >> 8) == '\0') && (0x3f < (byte)uVar4)) {
              pcVar1 = (code *)swi(0x67);
              (*pcVar1)();
              if ((extraout_AH_00 == '\0') && (iVar3 != 0)) {
                pcVar1 = (code *)swi(0x67);
                (*pcVar1)();
                if (extraout_AH_01 == '\0') {
                  uVar6 = 0;
                  iVar5 = 0xe;
                  do {
                    bVar7 = iVar3 < 0;
                    iVar3 = iVar3 << 1;
                    uVar6 = uVar6 << 1 | (uint)bVar7;
                    iVar5 = iVar5 + -1;
                    EMS_Handle = extraout_DX_00;
                  } while (iVar5 != 0);
                  goto LAB_1000_052b;
                }
              }
            }
          }
        }
        goto exit_error;
      }
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
  }
exit_error:
  iVar3 = 0;
  uVar6 = 0;
LAB_1000_052b:
  return CONCAT22(uVar6,iVar3);
}



/* 1000:0532 */

int __cdecl16far ems_init2(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  char extraout_AH;
  undefined2 uVar4;
  char extraout_AH_00;
  char extraout_AH_01;
  uint extraout_DX;
  undefined2 extraout_DX_00;
  undefined1 in_CF;
  bool bVar5;
  int in_stack_00000012;
  
  pcVar1 = (code *)swi(0x21);
  iVar3 = (*pcVar1)();
  if (!(bool)in_CF) {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    if ((!(bool)in_CF) && (bVar5 = false, (extraout_DX & 0x80) != 0)) {
      pcVar1 = (code *)swi(0x21);
      cVar2 = (*pcVar1)();
      if ((!bVar5) && (bVar5 = false, cVar2 != '\0')) {
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)();
        if (bVar5) {
          return 0;
        }
        pcVar1 = (code *)swi(0x67);
        (*pcVar1)();
        if (extraout_AH != '\0') {
          return 0;
        }
        pcVar1 = (code *)swi(0x67);
        uVar4 = (*pcVar1)();
        if ((char)((uint)uVar4 >> 8) != '\0') {
          return 0;
        }
        if ((byte)uVar4 < 0x40) {
          return 0;
        }
        pcVar1 = (code *)swi(0x67);
        (*pcVar1)();
        if (extraout_AH_00 != '\0') {
          return 0;
        }
        if (iVar3 == 0) {
          return 0;
        }
        pcVar1 = (code *)swi(0x67);
        (*pcVar1)();
        if (extraout_AH_01 != '\0') {
          return 0;
        }
        iVar3 = 0xe;
        do {
          in_stack_00000012 = in_stack_00000012 << 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        EMS_Handle = extraout_DX_00;
        return in_stack_00000012;
      }
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
  }
  return 0;
}



/* 1000:05c5 */

void __cdecl16far
ems_memmove1(undefined2 param_1,undefined2 param_2,uint param_3,int param_4,undefined2 param_5,
            undefined2 param_6)

{
  code *pcVar1;
  
  emms_var05b7 = 1;
  emms_var05b8 = EMS_Handle;
  emms_var05bc = (param_4 << 1 | (uint)((int)param_3 < 0)) << 1 | (uint)((int)(param_3 << 1) < 0);
  emms_var05ba = param_3 & 0x3fff;
  emms_var05be = 0;
  emms_var05bf = 0;
  emms_var05c1 = param_1;
  emms_var05c3 = param_2;
  emms_var05b3 = param_5;
  emms_var05b5 = param_6;
  pcVar1 = (code *)swi(0x67);
  (*pcVar1)();
  return;
}



/* 1000:0632 */

void __cdecl16far
ems_memmove2(uint param_1,int param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,
            undefined2 param_6)

{
  code *pcVar1;
  
  emms_var05b7 = 0;
  emms_var05b8 = 0;
  emms_var05ba = param_3;
  emms_var05bc = param_4;
  emms_var05be = 1;
  emms_var05bf = EMS_Handle;
  emms_var05c3 = (param_2 << 1 | (uint)((int)param_1 < 0)) << 1 | (uint)((int)(param_1 << 1) < 0);
  emms_var05c1 = param_1 & 0x3fff;
  emms_var05b3 = param_5;
  emms_var05b5 = param_6;
  pcVar1 = (code *)swi(0x67);
  (*pcVar1)();
  return;
}



/* 1000:069f */

void __cdecl16far emsFree(void)

{
  code *pcVar1;
  
  if (EMS_Handle != 0) {
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    EMS_Handle = 0;
  }
  return;
}



/* 1000:06c4 */

void __cdecl16far ems_realloc(uint32_t handle)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x67);
  (*pcVar1)();
  return;
}



/* 1000:06f8 */

uint8_t __cdecl16far rand8(void)

{
  uint8_t *puVar1;
  uint8_t *puVar2;
  int iVar3;
  uint8_t *src;
  uint8_t *dst;
  
  r8s[0] = r8s[1] + r8s[4] + 1 + r8s[5] + (CARRY1(r8s[1],r8s[4]) || 0xfe < (byte)(r8s[1] + r8s[4]));
  src = (uint8_t *)r8s + 4;
  dst = (uint8_t *)r8s + 5;
  for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = dst;
    dst = dst + -1;
    puVar1 = src;
    src = src + -1;
    *puVar2 = *puVar1;
  }
  return r8s[0];
}



/* 1000:0730 */

void __cdecl16far srand8(uint32_t seed)

{
  int i;
  
  r8s[1] = (byte)seed ^ 0x55;
  r8s[2] = seed._1_1_ ^ 0x55;
  r8s[3] = seed._2_1_ ^ 0x55;
  r8s[4] = seed._3_1_ ^ 0x55;
  r8s[0] = 0x0;
  r8s[5] = 0x0;
  i = 200;
  do {
    rand8();
    i = i + -1;
  } while (i != 0);
  return;
}



/* 1000:0776 */

void __cdecl16far ioErrorHndlrInstall(void)

{
  uint16_t in_BX;
  uint16_t unaff_ES;
  
  swi(0x21);
  DOS_GetInterruptHandler((char *)"puppetmaker" + 3);
  swi(0x21);
  GSavedErrorHandler.ofs = in_BX;
  GSavedErrorHandler.seg = unaff_ES;
  DOS_SetInterruptHandler(0x24,0x7a7);
  GIOErrorCode = 0;
  GIOErrorRetryCount = 5;
  return;
}



/* 1000:07a7 */

undefined2 __cdecl16far ioErrorHndlr(void)

{
  code *pcVar1;
  undefined2 uVar2;
  
  pcVar1 = (code *)swi(0x21);
  GIOErrorCode = (*pcVar1)((char *)"puppetmaker" + 3);
  if (GIOErrorCode == 0x20) {
    return 3;
  }
  if ((GIOErrorRetryCount != '\0') && (GIOErrorCode == 0x37)) {
    GIOErrorRetryCount = GIOErrorRetryCount + -1;
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x000107e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)(ulong)GSavedErrorHandler.ofs)();
  return uVar2;
}



/* 1000:07e7 */

/* Unintalls hardware error handler and returns an error if any */

uint16_t __cdecl16far ioErrorHndlrUninstall(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)((char *)"puppetmaker" + 3);
  return GIOErrorCode;
}



/* 1000:081a */

void __cdecl16far __OverlayHalt(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
                    /* WARNING: Subroutine does not return */
  __exit();
}



/* 1000:0837 */

void __cdecl16far __FAR_RETURN(void)

{
  return;
}



/* 1000:0838 */

bool __cdecl16far _atexit(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = _atexitcnt != 0x20;
  if (bVar2) {
    iVar1 = _atexitcnt * 4;
    *(undefined2 *)(iVar1 + -0x6be6) = param_2;
    *(undefined2 *)((undefined *)&_atexittbl + iVar1) = param_1;
    _atexitcnt = _atexitcnt + 1;
  }
  return !bVar2;
}



/* 1000:0865 */

int __cdecl16far chdir(char *__path)

{
  code *pcVar1;
  int iVar2;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if ((bool)in_CF) {
    iVar2 = __IOerror();
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* 1000:087d */

void __cdecl16far _dos_getdrive(uint *drive)

{
  code *pcVar1;
  byte bVar2;
  undefined2 in_stack_00000006;
  
  pcVar1 = (code *)swi(0x21);
  bVar2 = (*pcVar1)();
  *_drive = bVar2 + 1;
  return;
}



/* 1000:088f */

void __cdecl16far _dos_setdrive(uint drive,uint *ndrives)

{
  code *pcVar1;
  byte bVar2;
  undefined2 in_stack_00000008;
  
  pcVar1 = (code *)swi(0x21);
  bVar2 = (*pcVar1)();
  *_ndrives = (uint)bVar2;
  return;
}



/* 1000:08a5 */

void __cdecl16far ___exit_dummy(void)

{
  return;
}



/* 1000:08a6 */

void ___exit(undefined2 param_1,int param_2,int param_3)

{
  if (param_3 == 0) {
    while (_atexitcnt != 0) {
      _atexitcnt = _atexitcnt + -1;
      (**(code **)((undefined *)&_atexittbl + _atexitcnt * 4))(0x1000);
    }
    __cleanup();
    (*(code *)_exitbuf.ofs)(0x1000);
  }
  __restorezero();
  __checknull();
  if (param_2 == 0) {
    if (param_3 == 0) {
      (*(code *)_exitfopen.ofs)(0x1000);
      (*(code *)_exitopen.ofs)(0x1000);
    }
    _terminate(0x1000,param_1);
  }
  return;
}



/* 1000:08fd */

void __cdecl16far exit(int status)

{
                    /* WARNING: Subroutine does not return */
  ___exit(status,0,0);
}



/* 1000:090c */

void __cdecl16far __exit(undefined2 param_1)

{
                    /* WARNING: Subroutine does not return */
  ___exit(param_1,0,1);
}



/* 1000:091e */

void __cdecl16far _cexit(void)

{
                    /* WARNING: Subroutine does not return */
  ___exit(0,1,0);
}



/* 1000:092b */

void __cdecl16far _c_exit(void)

{
  return;
}



/* 1000:0938 */

/* long multiply routine  */

long __cdecl16far LXMUL_at_(long a,long b)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (int)((ulong)b >> 0x10);
  iVar4 = (int)((ulong)a >> 0x10);
  iVar2 = 0;
  if (iVar4 != 0) {
    iVar2 = iVar4 * (int)b;
  }
  if (iVar3 != 0) {
    iVar2 = iVar3 * (int)a + iVar2;
  }
  lVar1 = (a & 0xffffU) * (b & 0xffffU);
  return CONCAT22((int)((ulong)lVar1 >> 0x10) + iVar2,(int)lVar1);
}



/* 1000:094f */

/* ; calls to this routine are generated by the compiler to copy
   ; one "struct" value to another */

void __stdcall16far F_SCOPY(uint8_t *dst,uint8_t *src,uint16_t nbytes)

{
  uint8_t *puVar1;
  uint8_t *puVar2;
  uint uVar3;
  undefined2 in_stack_00000006;
  undefined2 in_stack_0000000a;
  
  for (uVar3 = nbytes >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2 = dst;
    dst = dst + 2;
    puVar1 = src;
    src = src + 2;
    *(undefined2 *)puVar2 = *(undefined2 *)puVar1;
  }
  for (uVar3 = (uint)((nbytes & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2 = dst;
    dst = dst + 1;
    puVar1 = src;
    src = src + 1;
    *puVar2 = *puVar1;
  }
  return;
}



/* 1000:096b */

int __cdecl16far getcurdir(int drive,char *direc)

{
  code *pcVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    iVar3 = __IOerror(uVar2);
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}



/* 1000:0988 */

int __cdecl16far getdisk(void)

{
  uint local_4;
  
  _dos_getdrive(&local_4);
  return local_4 - 1;
}



/* 1000:09a2 */

int __cdecl16far setdisk(int drive)

{
  uint local_4;
  
  _dos_setdrive(drive + 1,&local_4);
  return local_4;
}



/* 1000:09c1 */

/* WARNING: Removing unreachable block (ram,0x00010a6a) */
/* WARNING: Removing unreachable block (ram,0x00010a49) */

int __cdecl16far N_LDIV_at_(uint param_1,uint param_2,uint param_3)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  undefined2 in_stack_00000002;
  
  if ((param_3 == 0) && ((param_1 == 0 || (param_2 == 0)))) {
    in_stack_00000002 = (int)(CONCAT22(param_1,in_stack_00000002) / (ulong)param_2);
  }
  else {
    bVar6 = (int)param_1 < 0;
    if (bVar6) {
      bVar5 = in_stack_00000002 != 0;
      in_stack_00000002 = -in_stack_00000002;
      param_1 = -(uint)bVar5 - param_1;
    }
    if ((int)param_3 < 0) {
      bVar5 = param_2 != 0;
      param_2 = -param_2;
      param_3 = -(uint)bVar5 - param_3;
      bVar6 = !bVar6;
    }
    iVar2 = 0x20;
    uVar4 = 0;
    uVar3 = 0;
    do {
      bVar5 = in_stack_00000002 < 0;
      in_stack_00000002 = in_stack_00000002 * 2;
      uVar1 = (ulong)CONCAT12(bVar5,param_1) << 1;
      param_1 = (uint)uVar1 | (uint)bVar5;
      bVar5 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar5,uVar3) << 1;
      uVar3 = (uint)uVar1 | (uint)bVar5;
      uVar4 = uVar4 << 1 | (uint)((uVar1 & 0x10000) != 0);
      if ((param_3 <= uVar4) && ((param_3 < uVar4 || (param_2 <= uVar3)))) {
        bVar5 = uVar3 < param_2;
        uVar3 = uVar3 - param_2;
        uVar4 = (uVar4 - param_3) - (uint)bVar5;
        in_stack_00000002 = in_stack_00000002 + 1;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (bVar6) {
      in_stack_00000002 = -in_stack_00000002;
    }
  }
  return in_stack_00000002;
}



/* 1000:09c4 */

/* WARNING: Removing unreachable block (ram,0x00010a6a) */
/* WARNING: Removing unreachable block (ram,0x00010a37) */
/* WARNING: Removing unreachable block (ram,0x00010a49) */

long __stdcall16far LDIV_at_(long a,long b)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  
  if ((b._2_2_ == 0) && ((a._2_2_ == 0 || ((int)b == 0)))) {
    iVar2 = (int)((ulong)a / (b & 0xffffU));
    iVar4 = 0;
  }
  else {
    bVar8 = a < 0;
    if (bVar8) {
      a = CONCAT22(-(uint)((int)a != 0) - a._2_2_,-(int)a);
    }
    if (b < 0) {
      b = CONCAT22(-(uint)((int)b != 0) - b._2_2_,-(int)b);
      bVar8 = !bVar8;
    }
    iVar3 = 0x20;
    uVar6 = 0;
    uVar5 = 0;
    do {
      iVar4 = (int)a;
      iVar2 = iVar4 * 2;
      uVar1 = (ulong)CONCAT12(iVar4 < 0,(int)((ulong)a >> 0x10)) << 1;
      iVar4 = (int)(uVar1 | iVar4 < 0);
      bVar7 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar7,uVar5) << 1;
      uVar5 = (uint)uVar1 | (uint)bVar7;
      uVar6 = uVar6 << 1 | (uint)((uVar1 & 0x10000) != 0);
      if ((ulong)b <= CONCAT22(uVar6,uVar5)) {
        bVar7 = uVar5 < (uint)b;
        uVar5 = uVar5 - (uint)b;
        uVar6 = (uVar6 - (int)((ulong)b >> 0x10)) - (uint)bVar7;
        iVar2 = iVar2 + 1;
      }
      a = CONCAT22(iVar4,iVar2);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (bVar8) {
      bVar8 = iVar2 != 0;
      iVar2 = -iVar2;
      iVar4 = -(uint)bVar8 - iVar4;
    }
  }
  return CONCAT22(iVar4,iVar2);
}



/* 1000:09c8 */

/* WARNING: Removing unreachable block (ram,0x00010a6a) */
/* WARNING: Removing unreachable block (ram,0x00010a03) */
/* WARNING: Removing unreachable block (ram,0x00010a07) */
/* WARNING: Removing unreachable block (ram,0x00010a11) */
/* WARNING: Removing unreachable block (ram,0x00010a15) */
/* WARNING: Removing unreachable block (ram,0x00010a49) */
/* WARNING: Removing unreachable block (ram,0x00010a55) */

int __cdecl16far N_LUDIV_at_(uint param_1,uint param_2,uint param_3)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  int in_stack_00000002;
  
  if ((param_3 == 0) && ((param_1 == 0 || (param_2 == 0)))) {
    in_stack_00000002 = (int)(CONCAT22(param_1,in_stack_00000002) / (ulong)param_2);
  }
  else {
    iVar2 = 0x20;
    uVar4 = 0;
    uVar3 = 0;
    do {
      bVar5 = in_stack_00000002 < 0;
      in_stack_00000002 = in_stack_00000002 * 2;
      uVar1 = (ulong)CONCAT12(bVar5,param_1) << 1;
      param_1 = (uint)uVar1 | (uint)bVar5;
      bVar5 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar5,uVar3) << 1;
      uVar3 = (uint)uVar1 | (uint)bVar5;
      uVar4 = uVar4 << 1 | (uint)((uVar1 & 0x10000) != 0);
      if ((param_3 <= uVar4) && ((param_3 < uVar4 || (param_2 <= uVar3)))) {
        bVar5 = uVar3 < param_2;
        uVar3 = uVar3 - param_2;
        uVar4 = (uVar4 - param_3) - (uint)bVar5;
        in_stack_00000002 = in_stack_00000002 + 1;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return in_stack_00000002;
}



/* 1000:09cb */

/* WARNING: Removing unreachable block (ram,0x00010a6a) */
/* WARNING: Removing unreachable block (ram,0x00010a03) */
/* WARNING: Removing unreachable block (ram,0x00010a07) */
/* WARNING: Removing unreachable block (ram,0x00010a11) */
/* WARNING: Removing unreachable block (ram,0x00010a15) */
/* WARNING: Removing unreachable block (ram,0x00010a49) */
/* WARNING: Removing unreachable block (ram,0x00010a55) */

undefined4 __stdcall16far LUDIV_at_(int param_1,uint param_2,uint param_3,uint param_4)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  if ((param_4 == 0) && ((param_2 == 0 || (param_3 == 0)))) {
    param_1 = (int)(CONCAT22(param_2,param_1) / (ulong)param_3);
    param_2 = 0;
  }
  else {
    iVar2 = 0x20;
    uVar4 = 0;
    uVar3 = 0;
    do {
      bVar5 = param_1 < 0;
      param_1 = param_1 * 2;
      uVar1 = (ulong)CONCAT12(bVar5,param_2) << 1;
      param_2 = (uint)uVar1 | (uint)bVar5;
      bVar5 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar5,uVar3) << 1;
      uVar3 = (uint)uVar1 | (uint)bVar5;
      uVar4 = uVar4 << 1 | (uint)((uVar1 & 0x10000) != 0);
      if ((param_4 <= uVar4) && ((param_4 < uVar4 || (param_3 <= uVar3)))) {
        bVar5 = uVar3 < param_3;
        uVar3 = uVar3 - param_3;
        uVar4 = (uVar4 - param_4) - (uint)bVar5;
        param_1 = param_1 + 1;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return CONCAT22(param_2,param_1);
}



/* 1000:09d0 */

uint __cdecl16far N_LMOD_at_(uint param_1,uint param_2,uint param_3)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  undefined2 in_stack_00000002;
  
  uVar4 = 2;
  if ((param_3 == 0) && ((param_1 == 0 || (param_2 == 0)))) {
    in_stack_00000002 = (uint)(CONCAT22(param_1,in_stack_00000002) % (ulong)param_2);
  }
  else {
    if ((int)param_1 < 0) {
      bVar6 = in_stack_00000002 != 0;
      in_stack_00000002 = -in_stack_00000002;
      param_1 = -(uint)bVar6 - param_1;
      uVar4 = 0xe;
    }
    if ((int)param_3 < 0) {
      bVar6 = param_2 != 0;
      param_2 = -param_2;
      param_3 = -(uint)bVar6 - param_3;
      uVar4 = uVar4 ^ 4;
    }
    iVar2 = 0x20;
    uVar5 = 0;
    uVar3 = 0;
    do {
      bVar6 = (int)in_stack_00000002 < 0;
      in_stack_00000002 = in_stack_00000002 * 2;
      uVar1 = (ulong)CONCAT12(bVar6,param_1) << 1;
      param_1 = (uint)uVar1 | (uint)bVar6;
      bVar6 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar6,uVar3) << 1;
      uVar3 = (uint)uVar1 | (uint)bVar6;
      uVar5 = uVar5 << 1 | (uint)((uVar1 & 0x10000) != 0);
      if ((param_3 <= uVar5) && ((param_3 < uVar5 || (param_2 <= uVar3)))) {
        bVar6 = uVar3 < param_2;
        uVar3 = uVar3 - param_2;
        uVar5 = (uVar5 - param_3) - (uint)bVar6;
        in_stack_00000002 = in_stack_00000002 + 1;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if ((uVar4 & 2) != 0) {
      uVar4 = uVar4 >> 1;
      in_stack_00000002 = uVar3;
    }
    if ((uVar4 & 4) != 0) {
      in_stack_00000002 = -in_stack_00000002;
    }
  }
  return in_stack_00000002;
}



/* 1000:09d3 */

/* WARNING: Removing unreachable block (ram,0x00010a37) */

long __stdcall16far LMOD_at_(long param_1,long param_2)

{
  ulong uVar1;
  uint uVar2;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  int iVar3;
  
  uVar7 = 2;
  if ((param_2._2_2_ == 0) && ((param_1._2_2_ == 0 || ((int)param_2 == 0)))) {
    uVar2 = (uint)((ulong)param_1 % (param_2 & 0xffffU));
    uVar5 = 0;
  }
  else {
    if (param_1 < 0) {
      param_1 = CONCAT22(-(uint)((int)param_1 != 0) - param_1._2_2_,-(int)param_1);
      uVar7 = 0xe;
    }
    if (param_2 < 0) {
      param_2 = CONCAT22(-(uint)((int)param_2 != 0) - param_2._2_2_,-(int)param_2);
      uVar7 = uVar7 ^ 4;
    }
    iVar4 = 0x20;
    uVar8 = 0;
    uVar6 = 0;
    do {
      iVar3 = (int)param_1;
      uVar2 = iVar3 * 2;
      uVar1 = (ulong)CONCAT12(iVar3 < 0,(int)((ulong)param_1 >> 0x10)) << 1;
      uVar5 = (uint)(uVar1 | iVar3 < 0);
      bVar9 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar9,uVar6) << 1;
      uVar6 = (uint)uVar1 | (uint)bVar9;
      uVar8 = uVar8 << 1 | (uint)((uVar1 & 0x10000) != 0);
      if ((ulong)param_2 <= CONCAT22(uVar8,uVar6)) {
        bVar9 = uVar6 < (uint)param_2;
        uVar6 = uVar6 - (uint)param_2;
        uVar8 = (uVar8 - (int)((ulong)param_2 >> 0x10)) - (uint)bVar9;
        uVar2 = uVar2 + 1;
      }
      param_1 = CONCAT22(uVar5,uVar2);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if ((uVar7 & 2) != 0) {
      uVar7 = uVar7 >> 1;
      uVar2 = uVar6;
      uVar5 = uVar8;
    }
    if ((uVar7 & 4) != 0) {
      bVar9 = uVar2 != 0;
      uVar2 = -uVar2;
      uVar5 = -(uint)bVar9 - uVar5;
    }
  }
  return CONCAT22(uVar5,uVar2);
}



/* 1000:09d8 */

/* WARNING: Removing unreachable block (ram,0x00010a03) */
/* WARNING: Removing unreachable block (ram,0x00010a07) */
/* WARNING: Removing unreachable block (ram,0x00010a11) */
/* WARNING: Removing unreachable block (ram,0x00010a15) */
/* WARNING: Removing unreachable block (ram,0x00010a55) */

undefined4 __stdcall16far N_LUMOD_at_(uint param_1,uint param_2,uint param_3)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  int in_stack_00000002;
  
  if ((param_3 == 0) && ((param_1 == 0 || (param_2 == 0)))) {
    uVar3 = (uint)(CONCAT22(param_1,in_stack_00000002) % (ulong)param_2);
    uVar4 = 0;
  }
  else {
    iVar2 = 0x20;
    uVar4 = 0;
    uVar3 = 0;
    do {
      bVar5 = in_stack_00000002 < 0;
      in_stack_00000002 = in_stack_00000002 * 2;
      uVar1 = (ulong)CONCAT12(bVar5,param_1) << 1;
      param_1 = (uint)uVar1 | (uint)bVar5;
      bVar5 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar5,uVar3) << 1;
      uVar3 = (uint)uVar1 | (uint)bVar5;
      uVar4 = uVar4 << 1 | (uint)((uVar1 & 0x10000) != 0);
      if ((param_3 <= uVar4) && ((param_3 < uVar4 || (param_2 <= uVar3)))) {
        bVar5 = uVar3 < param_2;
        uVar3 = uVar3 - param_2;
        uVar4 = (uVar4 - param_3) - (uint)bVar5;
        in_stack_00000002 = in_stack_00000002 + 1;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return CONCAT22(uVar4,uVar3);
}



/* 1000:0a6f */

/* long shift left */

int __cdecl16far N_LXLSH_at_(void)

{
  int in_AX;
  byte in_CL;
  
  if (in_CL < 0x10) {
    return in_AX << (in_CL & 0x1f);
  }
  return 0;
}



/* 1000:0a72 */

long __cdecl16far LXLSH_at_(long i,byte s)

{
  uint uVar1;
  
  uVar1 = (uint)i;
  if (s < 0x10) {
    return CONCAT22((int)((ulong)i >> 0x10) << (s & 0x1f) | uVar1 >> (0x10 - s & 0x1f),
                    uVar1 << (s & 0x1f));
  }
  return (ulong)(uVar1 << (s - 0x10 & 0x1f)) << 0x10;
}



/* 1000:0a90 */

/* long shift right */

uint __cdecl16far N_LXRSH_at_(void)

{
  uint in_AX;
  byte in_CL;
  int in_DX;
  
  if (in_CL < 0x10) {
    return in_AX >> (in_CL & 0x1f) | in_DX << (0x10 - in_CL & 0x1f);
  }
  return in_DX >> (in_CL - 0x10 & 0x1f);
}



/* 1000:0a93 */

/* long shift right (unsigned) */

long __cdecl16far LXRSH_at_(long n,uint8_t cx)

{
  int iVar1;
  
  iVar1 = (int)((ulong)n >> 0x10);
  if (cx < 0x10) {
    return CONCAT22(iVar1 >> (cx & 0x1f),(uint)n >> (cx & 0x1f) | iVar1 << (0x10 - cx & 0x1f));
  }
  return CONCAT22(iVar1 >> 0xf,iVar1 >> (cx - 0x10 & 0x1f));
}



/* 1000:0ab0 */

/* long shift right  */

uint __cdecl16far N_LXURSH_at_(void)

{
  uint in_AX;
  byte in_CL;
  uint in_DX;
  
  if (in_CL < 0x10) {
    return in_AX >> (in_CL & 0x1f) | in_DX << (0x10 - in_CL & 0x1f);
  }
  return in_DX >> (in_CL - 0x10 & 0x1f);
}



/* 1000:0ab3 */

uint32_t __cdecl16far LXURSH_at_(uint32_t val,uint8_t sh)

{
  uint uVar1;
  
  uVar1 = (uint)(val >> 0x10);
  if (sh < 0x10) {
    return CONCAT22(uVar1 >> (sh & 0x1f),(uint)val >> (sh & 0x1f) | uVar1 << (0x10 - sh & 0x1f));
  }
  return (uint32_t)(uVar1 >> (sh - 0x10 & 0x1f));
}



/* 1000:0ad1 */

uint __cdecl16far N_PADD_at_(void)

{
  char in_AL;
  uint uVar1;
  int in_CX;
  char in_BL;
  
  if (in_CX < 0) {
    uVar1 = sub1_at__at_();
    return uVar1;
  }
  return (byte)(in_AL + in_BL) & 0xf;
}



/* 1000:0ad4 */

/* WARNING: Unknown calling convention */

far_t PADD_at_(far_t ptr_base,far_t ptr_ofs)

{
  uint uVar1;
  uint16_t uVar2;
  far_t fVar3;
  
  uVar2 = ptr_base.seg;
  if ((long)ptr_ofs < 0) {
    fVar3.ofs = sub1_at__at_();
    fVar3.seg = uVar2;
    return fVar3;
  }
  uVar1 = ptr_base.ofs + ptr_ofs.ofs;
  if (CARRY2(ptr_base.ofs,ptr_ofs.ofs)) {
    uVar2 = uVar2 + 0x1000;
  }
  return (far_t)(CONCAT22(CONCAT11((char)(uVar2 >> 8) + (char)ptr_ofs.seg * '\x10',(char)uVar2) +
                          (uVar1 >> 4),uVar1) & 0xffff000f);
}



/* 1000:0ae4 */

byte __cdecl16far add1_at__at_(void)

{
  char in_AL;
  char in_BL;
  
  return in_AL + in_BL & 0xf;
}



/* 1000:0b00 */

uint __cdecl16far N_PSUB_at_(void)

{
  char in_AL;
  uint uVar1;
  int in_CX;
  char in_BL;
  
  if (in_CX < 0) {
    uVar1 = add1_at__at_();
    return uVar1;
  }
  return (byte)(in_AL - in_BL) & 0xf;
}



/* 1000:0b13 */

byte __cdecl16far sub1_at__at_(void)

{
  char in_AL;
  char in_BL;
  
  return in_AL - in_BL & 0xf;
}



/* 1000:0b31 */

int __cdecl16far N_PSBP_at_(void)

{
  int in_AX;
  int in_CX;
  int in_DX;
  int in_BX;
  
  return (in_DX * 0x10 + in_AX) - (in_BX + in_CX * 0x10);
}



/* 1000:0b59 */

undefined2 __IOerror(int param_1)

{
  if (param_1 < 0) {
    if (param_1 == -0x23 || -param_1 < 0x23) {
      errno = -param_1;
      _doserrno = 0xffff;
      return 0xffff;
    }
  }
  else if (param_1 < 0x59) goto ser_end;
  param_1 = 0x57;
ser_end:
  _doserrno = param_1;
  errno = (int)((char *)_dosErrorToSV)[param_1];
  return 0xffff;
}



/* 1000:0b92 */

undefined2 __DOSerror(undefined2 param_1)

{
  __IOerror(param_1);
  return param_1;
}



/* 1000:0ba4 */

uint __cdecl16far _isatty(void)

{
  code *pcVar1;
  uint extraout_DX;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return extraout_DX & 0x80;
}



/* 1000:0bb5 */

char * __LONGTOA(char param_1,char param_2,uint param_3,char *param_4,uint param_5,uint param_6)

{
  char *pcVar1;
  byte bVar2;
  ulong uVar3;
  char cVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  undefined2 uVar8;
  undefined2 unaff_SS;
  bool bVar9;
  byte local_24 [34];
  
  uVar8 = (undefined2)((ulong)param_4 >> 0x10);
  pcVar7 = (char *)param_4;
  if ((param_3 < 0x25) && (1 < (byte)param_3)) {
    if (((int)param_6 < 0) && (param_2 != '\0')) {
      *param_4 = '-';
      pcVar7 = pcVar7 + 1;
      bVar9 = param_5 != 0;
      param_5 = -param_5;
      param_6 = -(uint)bVar9 - param_6;
    }
    pbVar6 = local_24;
    if (param_6 == 0) goto LAB_1000_0bff;
    do {
      uVar3 = (ulong)param_6;
      param_6 = param_6 / param_3;
      uVar3 = uVar3 % (ulong)param_3 << 0x10 | (ulong)param_5;
      param_5 = (uint)(uVar3 / param_3);
      *pbVar6 = (byte)(uVar3 % (ulong)param_3);
      pbVar6 = pbVar6 + 1;
    } while (param_6 != 0);
    while (param_5 != 0) {
LAB_1000_0bff:
      *pbVar6 = (byte)(param_5 % param_3);
      pbVar6 = pbVar6 + 1;
      param_5 = param_5 / param_3;
    }
    iVar5 = (int)pbVar6 - (int)local_24;
    do {
      pbVar6 = pbVar6 + -1;
      bVar2 = *pbVar6;
      if (bVar2 < 10) {
        cVar4 = bVar2 + 0x30;
      }
      else {
        cVar4 = (bVar2 - 10) + param_1;
      }
      pcVar1 = pcVar7;
      pcVar7 = pcVar7 + 1;
      *pcVar1 = cVar4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  *pcVar7 = '\0';
  return param_4;
}



/* 1000:0c37 */

void __UTOA(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  __LONGTOA(0x61,0,10,param_1,param_2,param_3,0);
  return;
}



/* 1000:0c57 */

void __cdecl16far lseek(int handle,long offset,int whence)

{
  code *pcVar1;
  bool bVar2;
  
  bVar2 = false;
  ((uint16_t *)_openfd)[handle] = ((uint16_t *)_openfd)[handle] & 0xfdff;
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if (bVar2) {
    __IOerror();
  }
  return;
}



/* 1000:0c80 */

int __cdecl16far mkdir(char *path)

{
  code *pcVar1;
  int iVar2;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if ((bool)in_CF) {
    iVar2 = __IOerror();
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* 1000:0c98 */

undefined4 __cdecl16near N_LXMUL_at_(void)

{
  uint in_AX;
  int iVar1;
  int in_CX;
  int in_DX;
  uint in_BX;
  
  iVar1 = 0;
  if (in_DX != 0) {
    iVar1 = in_DX * in_BX;
  }
  if (in_CX != 0) {
    iVar1 = in_CX * in_AX + iVar1;
  }
  return CONCAT22((int)((ulong)in_AX * (ulong)in_BX >> 0x10) + iVar1,
                  (int)((ulong)in_AX * (ulong)in_BX));
}



/* 1000:0caf */

uint __cdecl16near N_PCMP_at_(void)

{
  uint in_AX;
  
  return in_AX & 0xf;
}



/* 1000:0cd0 */

void __cdecl16far _srand(uint16_t s)

{
  rand_Seed._2_2_ = 0;
  rand_Seed._0_2_ = s;
  return;
}



/* 1000:0ce1 */

uint __cdecl16far rand(void)

{
  long lVar1;
  
  lVar1 = N_LXMUL_at_();
  rand_Seed = lVar1 + 1;
  return (uint)((ulong)(lVar1 + 1) >> 0x10) & 0x7fff;
}



/* 1000:0d07 */

int __cdecl16far read(int fd,void *buf,uint len)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  
  bVar2 = false;
  if ((((uint16_t *)_openfd)[fd] & 2) == 0) {
    pcVar1 = (code *)swi(0x21);
    iVar3 = (*pcVar1)();
    if (!bVar2) {
      return iVar3;
    }
  }
  else {
    iVar3 = 5;
  }
  iVar3 = __IOerror(iVar3);
  return iVar3;
}



/* 1000:0d36 */

void __cdecl16near _setupio(void)

{
  int iVar1;
  undefined2 uVar2;
  uint i;
  
  i = 5;
  if (5 < _nfile) {
    do {
      ((uint16_t *)_openfd)[i] = 0;
      *(undefined1 *)((int)&_streams[0].fd + i * 0x14) = 0xff;
      *(undefined2 *)((int)&_streams[0].token + i * 0x14) = (FILE *)_streams + i;
      i = i + 1;
    } while (i < _nfile);
  }
  iVar1 = _isatty((int)_streams[0].fd);
  if (iVar1 == 0) {
    _streams[0].flags = _streams[0].flags & 0xfdff;
  }
  setvbuf((FILE *)_streams,(char *)"puppetmaker" + 3,0,0,(_streams[0].flags & 0x200) != 0,0x200);
  iVar1 = _isatty((int)_streams[1].fd);
  if (iVar1 == 0) {
    _streams[1].flags = _streams[1].flags & 0xfdff;
  }
  if ((_streams[1].flags & 0x200) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
  }
  setvbuf(0x863a,(char *)"puppetmaker" + 3,0,0,uVar2,0x200);
  return;
}



/* 1000:0dec */

void __cdecl16far _tell(int param_1)

{
  lseek(param_1,0,1);
  return;
}



/* 1000:0e04 */

uint __cdecl16far tolower(uint param_1)

{
  if (param_1 == 0xffff) {
    param_1 = 0xffff;
  }
  else if ((((byte *)_ctype + 1)[param_1 & 0xff] & 4) == 0) {
    param_1 = param_1 & 0xff;
  }
  else {
    param_1 = (param_1 & 0xff) + 0x20;
  }
  return param_1;
}



/* 1000:0e30 */

char __cdecl16far toupper(char c)

{
  undefined1 in_stack_00000005;
  
  if (_c == -1) {
    c = -1;
  }
  else if ((((byte *)_ctype + 1)[(byte)c] & 8) != 0) {
    c = c + -0x20;
  }
  return c;
}



/* 1000:0e5c */

int __cdecl16far unlink(char *file)

{
  code *pcVar1;
  int iVar2;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if ((bool)in_CF) {
    iVar2 = __IOerror();
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* 1000:0e74 */

void __cdecl16far __vprinter_1000_0e74(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte extraout_AH;
  char *unaff_DI;
  undefined2 unaff_ES;
  byte in_AF;
  
  __vprinter_1000_0e7b();
  __vprinter_1000_0e84();
  bVar2 = extraout_AH + 0x90;
  in_AF = 9 < (bVar2 & 0xf) | in_AF;
  bVar1 = 0x99 < bVar2 || 0x6f < extraout_AH;
  bVar3 = bVar2 + in_AF * '\x06' + bVar1 * '`';
  bVar2 = bVar3 + 0x40;
  bVar4 = bVar2 + bVar1;
  *unaff_DI = bVar4 + (9 < (bVar4 & 0xf) | in_AF) * '\x06' +
              (0x99 < bVar4 || (0xbf < bVar3 || CARRY1(bVar2,bVar1))) * '`';
  return;
}



/* 1000:0e7b */

void __cdecl16far __vprinter_1000_0e7b(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte extraout_AH;
  char *unaff_DI;
  undefined2 unaff_ES;
  byte in_AF;
  
  __vprinter_1000_0e84();
  bVar2 = extraout_AH + 0x90;
  in_AF = 9 < (bVar2 & 0xf) | in_AF;
  bVar1 = 0x99 < bVar2 || 0x6f < extraout_AH;
  bVar3 = bVar2 + in_AF * '\x06' + bVar1 * '`';
  bVar2 = bVar3 + 0x40;
  bVar4 = bVar2 + bVar1;
  *unaff_DI = bVar4 + (9 < (bVar4 & 0xf) | in_AF) * '\x06' +
              (0x99 < bVar4 || (0xbf < bVar3 || CARRY1(bVar2,bVar1))) * '`';
  return;
}



/* 1000:0e84 */

void __cdecl16near __vprinter_1000_0e84(void)

{
  byte bVar1;
  byte in_AL;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char *unaff_DI;
  undefined2 unaff_ES;
  byte in_AF;
  bool bVar2;
  
  bVar3 = in_AL + 0x90;
  bVar1 = 9 < (bVar3 & 0xf) | in_AF;
  bVar2 = 0x99 < bVar3 || 0x6f < in_AL;
  bVar4 = bVar3 + bVar1 * '\x06' + bVar2 * '`';
  bVar3 = bVar4 + 0x40;
  bVar5 = bVar3 + bVar2;
  *unaff_DI = bVar5 + (9 < (bVar5 & 0xf) | bVar1) * '\x06' +
              (0x99 < bVar5 || (0xbf < bVar4 || CARRY1(bVar3,bVar2))) * '`';
  return;
}



/* 1000:0e8c */

void __cdecl16far __vprinter(void)

{
  undefined2 unaff_SI;
  
  __vprinter_func_start(unaff_SI);
  return;
}



/* 1000:0ea6 */

void __cdecl16near __vprinter_1000_0ea6(void)

{
  char *pcVar1;
  int iVar2;
  char *unaff_DI;
  undefined2 unaff_ES;
  
  iVar2 = -1;
  do {
    if (iVar2 == 0) {
      return;
    }
    iVar2 = iVar2 + -1;
    pcVar1 = unaff_DI;
    unaff_DI = unaff_DI + 1;
  } while (*pcVar1 != '\0');
  return;
}



/* 1000:0eb3 */

void __cdecl16near __vprinter_1000_0eb3(void)

{
  code *pcVar1;
  undefined1 in_AL;
  int iVar2;
  int unaff_BP;
  undefined1 *unaff_DI;
  undefined2 unaff_SS;
  
  *unaff_DI = in_AL;
  pcVar1 = (code *)init_3381_08dc + unaff_BP;
  *pcVar1 = (code)((char)*pcVar1 + -1);
  if (*pcVar1 == (code)0x0) {
    iVar2 = (*(code *)*(undefined2 *)(unaff_BP + 0xe))
                      (*(undefined2 *)(unaff_BP + 10),*(undefined2 *)(unaff_BP + 0xc),
                       unaff_DI + (1 - (unaff_BP + -0x96)),unaff_BP + -0x96);
    if (iVar2 == 0) {
      *(undefined2 *)(unaff_BP + -0x16) = 1;
    }
    *(undefined2 *)((code *)init_3381_08dc + unaff_BP) = 0x50;
    *(int *)(unaff_BP + -0x12) =
         (int)(unaff_DI + (1 - (unaff_BP + -0x96)) + *(int *)(unaff_BP + -0x12));
  }
  return;
}



/* 1000:0ebc */

void __cdecl16near __vprinter_1000_0ebc(void)

{
  int iVar1;
  int unaff_BP;
  int unaff_DI;
  int iVar2;
  undefined2 unaff_SS;
  
  iVar2 = unaff_DI - (unaff_BP + -0x96);
  iVar1 = (*(code *)*(undefined2 *)(unaff_BP + 0xe))
                    (*(undefined2 *)(unaff_BP + 10),*(undefined2 *)(unaff_BP + 0xc),iVar2,
                     unaff_BP + -0x96);
  if (iVar1 == 0) {
    *(undefined2 *)(unaff_BP + -0x16) = 1;
  }
  *(undefined2 *)((code *)init_3381_08dc + unaff_BP) = 0x50;
  *(int *)(unaff_BP + -0x12) = *(int *)(unaff_BP + -0x12) + iVar2;
  return;
}



/* 1000:0ef0 */

/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined2 __vprinter_func_start(void)

{
  code *pcVar1;
  code cVar2;
  char *pcVar3;
  uint *puVar4;
  undefined1 *puVar5;
  undefined2 *puVar6;
  uint uVar7;
  int *piVar8;
  char cVar9;
  uint uVar10;
  byte bVar13;
  int iVar11;
  int iVar12;
  int extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  char cVar14;
  int iVar15;
  int unaff_BP;
  char *pcVar16;
  char *pcVar17;
  int *piVar18;
  undefined1 *puVar19;
  uint *puVar20;
  int *piVar21;
  undefined2 uVar22;
  char *pcVar23;
  char *unaff_SS;
  bool bVar24;
  
  *(int *)(unaff_BP + -4) = unaff_BP + -0x96;
LAB_1000_0ef9:
  pcVar17 = (char *)*(undefined2 *)(unaff_BP + -4);
LAB_1000_0efc:
  uVar22 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
  pcVar23 = (char *)(char *)*(undefined4 *)(unaff_BP + 6);
LAB_1000_0eff:
  pcVar16 = pcVar23 + 1;
  cVar9 = *pcVar23;
  if (cVar9 == '\0') goto LAB_1000_12fa;
  if (cVar9 == '%') {
    *(int *)(unaff_BP + -0x10) = (int)pcVar16;
    pcVar3 = pcVar16;
    pcVar16 = pcVar23 + 2;
    cVar9 = *pcVar3;
    if (cVar9 != '%') goto code_r0x00010f23;
  }
  *pcVar17 = cVar9;
  pcVar17 = pcVar17 + 1;
  pcVar1 = (code *)init_3381_08dc + unaff_BP;
  cVar2 = *pcVar1;
  *pcVar1 = (code)((char)*pcVar1 + -1);
  pcVar23 = pcVar16;
  if (*pcVar1 == (code)0x0 || SBORROW1((char)cVar2,'\x01') != (char)*pcVar1 < '\0') {
    __vprinter_1000_0ebc();
  }
  goto LAB_1000_0eff;
code_r0x00010f23:
  *(undefined2 *)(unaff_BP + -4) = pcVar17;
  uVar10 = 0;
  *(undefined2 *)(unaff_BP + -0xe) = 0;
  *(undefined2 *)(unaff_BP + -2) = 0x20;
  *(undefined1 *)(unaff_BP + -0xb) = 0;
  *(undefined2 *)(unaff_BP + -8) = 0xffff;
  *(undefined2 *)(unaff_BP + -10) = 0xffff;
  do {
    if (0x5f < (byte)(cVar9 - 0x20U)) goto switchD_1000_0f5d_caseD_13;
    cVar14 = ((uint8_t *)vprinter_printCtype)[(byte)(cVar9 - 0x20U)] * '\x02';
    bVar13 = (byte)(uVar10 >> 8);
    pcVar23 = unaff_SS;
    switch(((uint8_t *)vprinter_printCtype)[(byte)(cVar9 - 0x20U)]) {
    case '\0':
      if (bVar13 != 0) goto switchD_1000_0f5d_caseD_13;
      if (*(char *)(unaff_BP + -0xb) != '+') {
        *(char *)(unaff_BP + -0xb) = cVar9;
      }
      break;
    case '\x01':
      if (bVar13 != 0) goto switchD_1000_0f5d_caseD_13;
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 1;
      break;
    case '\x02':
      iVar15 = *(int *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
      if (bVar13 < 2) {
        if (iVar15 < 0) {
          iVar15 = -iVar15;
          *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 2;
        }
        *(int *)(unaff_BP + -8) = iVar15;
        uVar10 = 0x300;
      }
      else {
        if (bVar13 != 4) goto switchD_1000_0f5d_caseD_13;
        *(int *)(unaff_BP + -10) = iVar15;
        uVar10 = 0x500;
      }
      break;
    case '\x03':
      if (bVar13 != 0) goto switchD_1000_0f5d_caseD_13;
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 2;
      break;
    case '\x04':
      if (3 < bVar13) goto switchD_1000_0f5d_caseD_13;
      uVar10 = 0x400;
      *(int *)(unaff_BP + -10) = *(int *)(unaff_BP + -10) + 1;
      break;
    case '\x05':
switchD_1000_0f5d_caseD_5:
      if (bVar13 < 3) {
        uVar10 = 0x200;
        LOCK();
        iVar15 = *(int *)(unaff_BP + -8);
        *(int *)(unaff_BP + -8) = (int)(char)(cVar9 + -0x30);
        UNLOCK();
        if (-1 < iVar15) {
          *(int *)(unaff_BP + -8) = *(int *)(unaff_BP + -8) + iVar15 * 10;
        }
      }
      else {
        if (bVar13 != 4) {
switchD_1000_0f5d_caseD_13:
          pcVar17 = (char *)*(undefined2 *)(unaff_BP + -0x10);
          uVar22 = *(undefined2 *)(unaff_BP + 8);
          do {
            __vprinter_1000_0eb3();
            pcVar3 = pcVar17;
            pcVar17 = pcVar17 + 1;
          } while (*pcVar3 != '\0');
LAB_1000_12fa:
          if ((char)((code *)init_3381_08dc)[unaff_BP] < 'P') {
            __vprinter_1000_0ebc();
          }
          if (*(int *)(unaff_BP + -0x16) == 0) {
            uVar22 = *(undefined2 *)(unaff_BP + -0x12);
          }
          else {
            uVar22 = 0xffff;
          }
          return uVar22;
        }
        LOCK();
        iVar15 = *(int *)(unaff_BP + -10);
        *(int *)(unaff_BP + -10) = (int)(char)(cVar9 + -0x30);
        UNLOCK();
        if (iVar15 != 0) {
          *(int *)(unaff_BP + -10) = *(int *)(unaff_BP + -10) + iVar15 * 10;
        }
      }
      break;
    case '\x06':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x10;
      goto LAB_1000_0f95;
    case '\a':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x100;
    case '\b':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) & 0xffef;
      goto LAB_1000_0f95;
    case '\t':
      if (bVar13 != 0) goto switchD_1000_0f5d_caseD_5;
      if ((*(uint *)(unaff_BP + -2) & 2) == 0) {
        *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 8;
        uVar10 = 0x100;
      }
      break;
    case '\n':
      goto switchD_1000_0f5d_caseD_a;
    case '\v':
      uVar22 = CONCAT11(8,cVar14);
      goto LAB_1000_104a;
    case '\f':
      uVar22 = CONCAT11(10,cVar14);
      goto LAB_1000_104e;
    case '\r':
      uVar22 = CONCAT11(0x10,cVar9 + -0x17);
LAB_1000_104a:
      *(undefined1 *)(unaff_BP + -0xb) = 0;
LAB_1000_104e:
      *(char *)(unaff_BP + -5) = cVar9;
      iVar11 = 0;
      *(undefined1 *)(unaff_BP + -6) = 0;
      piVar21 = (int *)*(undefined2 *)(unaff_BP + 4);
      iVar15 = *piVar21;
      goto LAB_1000_106e;
    case '\x0e':
      *(char *)(unaff_BP + -5) = cVar9;
      *(undefined2 *)(unaff_BP + 6) = pcVar16;
      puVar19 = (undefined1 *)(unaff_BP + -0x46);
      puVar6 = (undefined2 *)*(int *)(unaff_BP + 4);
      uVar22 = *puVar6;
      *(undefined2 *)(unaff_BP + 4) = puVar6 + 1;
      if ((*(uint *)(unaff_BP + -2) & 0x20) != 0) {
        *(undefined2 *)(unaff_BP + 4) = puVar6 + 2;
        __vprinter_1000_0e74(uVar22);
        puVar5 = puVar19;
        puVar19 = (undefined1 *)(unaff_BP + -0x45);
        *puVar5 = 0x3a;
      }
      __vprinter_1000_0e74();
      *puVar19 = 0;
      *(undefined1 *)(unaff_BP + -6) = 0;
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) & 0xfffb;
      puVar20 = (uint *)(unaff_BP + -0x46);
      uVar10 = (int)puVar19 - (int)puVar20;
      goto LAB_1000_11aa;
    case '\x0f':
      *(undefined2 *)(unaff_BP + 6) = pcVar16;
      *(char *)(unaff_BP + -5) = cVar9;
      uVar10 = *(uint *)(unaff_BP + -10);
      if ((int)uVar10 < 0) {
        uVar10 = 6;
      }
      uVar7 = *(uint *)(unaff_BP + -2);
      if ((*(uint *)(unaff_BP + -2) & 0x100) == 0) {
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 8;
        uVar22 = 6;
      }
      else {
        uVar22 = 8;
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 10;
      }
      ovr__FakRealCvt(uVar22,uVar7 & 1,cVar9,unaff_BP + -0x45);
      puVar20 = (uint *)(unaff_BP + -0x45);
      goto LAB_1000_11aa;
    case '\x10':
      *(undefined2 *)(unaff_BP + 6) = pcVar16;
      *(char *)(unaff_BP + -5) = cVar9;
      uVar10 = *(uint *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
      puVar20 = (uint *)(unaff_BP + -0x45);
      *puVar20 = uVar10 & 0xff;
      uVar10 = 1;
      goto LAB_1000_11ed;
    case '\x11':
      *(undefined2 *)(unaff_BP + 6) = pcVar16;
      *(char *)(unaff_BP + -5) = cVar9;
      if ((*(uint *)(unaff_BP + -2) & 0x20) == 0) {
        puVar20 = *(uint **)(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
        pcVar23 = (char *)"puppetmaker" + 3;
        bVar24 = puVar20 == (uint *)0x0;
      }
      else {
        puVar4 = (uint *)*(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        pcVar23 = (char *)((ulong)puVar4 >> 0x10);
        puVar20 = (uint *)puVar4;
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 4;
        bVar24 = pcVar23 == (char *)0x0 && puVar20 == (uint *)0x0;
      }
      if (bVar24) {
        pcVar23 = (char *)"puppetmaker" + 3;
        puVar20 = (uint *)"(null)";
      }
      __vprinter_1000_0ea6();
      if (*(uint *)(unaff_BP + -10) < uVar10) {
        uVar10 = *(uint *)(unaff_BP + -10);
      }
      goto LAB_1000_11ed;
    case '\x12':
      *(undefined2 *)(unaff_BP + 6) = pcVar16;
      if ((*(uint *)(unaff_BP + -2) & 0x20) == 0) {
        piVar21 = *(int **)(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
        pcVar17 = (char *)"puppetmaker" + 3;
      }
      else {
        piVar8 = (int *)*(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        pcVar17 = (char *)((ulong)piVar8 >> 0x10);
        piVar21 = (int *)piVar8;
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 4;
      }
      *piVar21 = (uint)(byte)(0x50 - (char)((code *)init_3381_08dc)[unaff_BP]) +
                 *(int *)(unaff_BP + -0x12);
      if ((*(uint *)(unaff_BP + -2) & 0x10) != 0) {
        piVar21[1] = 0;
      }
      goto LAB_1000_0ef9;
    default:
      goto switchD_1000_0f5d_caseD_13;
    case '\x16':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) & 0xffdf;
      goto LAB_1000_0f95;
    case '\x17':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x20;
LAB_1000_0f95:
      uVar10 = 0x500;
    }
    pcVar3 = pcVar16;
    pcVar16 = pcVar16 + 1;
    cVar9 = *pcVar3;
  } while( true );
switchD_1000_0f5d_caseD_a:
  uVar22 = CONCAT11(10,cVar14);
  *(undefined1 *)(unaff_BP + -6) = 1;
  *(char *)(unaff_BP + -5) = cVar9;
  piVar21 = (int *)*(undefined2 *)(unaff_BP + 4);
  iVar15 = *piVar21;
  iVar11 = iVar15 >> 0xf;
LAB_1000_106e:
  piVar18 = piVar21 + 1;
  *(undefined2 *)(unaff_BP + 6) = pcVar16;
  if ((*(uint *)(unaff_BP + -2) & 0x10) != 0) {
    iVar11 = *piVar18;
    piVar18 = piVar21 + 2;
  }
  *(undefined2 *)(unaff_BP + 4) = piVar18;
  puVar20 = (uint *)(unaff_BP + -0x45);
  if ((iVar15 == 0) && (iVar11 == 0)) {
    if (*(int *)(unaff_BP + -10) == 0) goto LAB_1000_0ef9;
  }
  else {
    *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 4;
  }
  __LONGTOA(uVar22,*(undefined1 *)(unaff_BP + -6),(char)((uint)uVar22 >> 8),puVar20,unaff_SS,iVar15,
            iVar11);
  if (*(int *)(unaff_BP + -10) < 0) {
LAB_1000_11aa:
    if (((*(uint *)(unaff_BP + -2) & 8) != 0) && (0 < *(int *)(unaff_BP + -8))) goto LAB_1000_11b8;
  }
  else {
LAB_1000_11b8:
    __vprinter_1000_0ea6();
    if ((char)*puVar20 == '-') {
      uVar10 = uVar10 - 1;
    }
    if (extraout_DX - uVar10 != 0 && (int)uVar10 <= extraout_DX) {
      *(int *)(unaff_BP + -0xe) = extraout_DX - uVar10;
    }
  }
  if ((char)*puVar20 != '-') {
    if (*(char *)(unaff_BP + -0xb) == '\0') goto LAB_1000_11ea;
    puVar20 = (uint *)((int)puVar20 + -1);
    *(char *)puVar20 = *(char *)(unaff_BP + -0xb);
  }
  if ((0 < *(int *)(unaff_BP + -0xe)) && (uVar10 = *(uint *)(unaff_BP + -10), (int)uVar10 < 0)) {
    *(int *)(unaff_BP + -0xe) = *(int *)(unaff_BP + -0xe) + -1;
  }
LAB_1000_11ea:
  __vprinter_1000_0ea6();
LAB_1000_11ed:
  pcVar17 = (char *)*(undefined2 *)(unaff_BP + -4);
  iVar15 = *(int *)(unaff_BP + -8);
  if ((*(uint *)(unaff_BP + -2) & 5) == 5) {
    cVar9 = *(char *)(unaff_BP + -5);
    if (cVar9 == 'o') {
      if (*(int *)(unaff_BP + -0xe) < 1) {
        *(undefined2 *)(unaff_BP + -0xe) = 1;
      }
    }
    else if ((cVar9 == 'x') || (cVar9 == 'X')) {
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x40;
      iVar15 = iVar15 + -2;
      piVar8 = (int *)(unaff_BP + -0xe);
      iVar11 = *piVar8;
      *piVar8 = *piVar8 + -2;
      if (SBORROW2(iVar11,2) != *piVar8 < 0) {
        *(undefined2 *)(unaff_BP + -0xe) = 0;
      }
    }
  }
  iVar11 = uVar10 + *(int *)(unaff_BP + -0xe);
  if ((*(uint *)(unaff_BP + -2) & 2) == 0) {
    for (; iVar11 < iVar15; iVar15 = iVar15 + -1) {
      __vprinter_1000_0eb3();
    }
  }
  if ((*(uint *)(unaff_BP + -2) & 0x40) != 0) {
    __vprinter_1000_0eb3();
    __vprinter_1000_0eb3();
  }
  iVar12 = *(int *)(unaff_BP + -0xe);
  if (0 < iVar12) {
    iVar11 = iVar11 - iVar12;
    iVar15 = iVar15 - iVar12;
    cVar9 = (char)*puVar20;
    if (((cVar9 == '-') || (cVar9 == ' ')) || (cVar9 == '+')) {
      puVar20 = (uint *)((int)puVar20 + 1);
      __vprinter_1000_0eb3();
      iVar11 = iVar11 + -1;
      iVar15 = iVar15 + -1;
      iVar12 = extraout_DX_00;
    }
    for (; iVar12 != 0; iVar12 = iVar12 + -1) {
      __vprinter_1000_0eb3();
      iVar11 = extraout_DX_01;
    }
  }
  if (iVar11 != 0) {
    iVar15 = iVar15 - iVar11;
    do {
      puVar4 = puVar20;
      puVar20 = (uint *)((int)puVar20 + 1);
      *pcVar17 = (char)*puVar4;
      pcVar17 = pcVar17 + 1;
      pcVar1 = (code *)init_3381_08dc + unaff_BP;
      cVar2 = *pcVar1;
      *pcVar1 = (code)((char)*pcVar1 + -1);
      if (*pcVar1 == (code)0x0 || SBORROW1((char)cVar2,'\x01') != (char)*pcVar1 < '\0') {
        __vprinter_1000_0ebc();
      }
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  if (0 < iVar15) {
    do {
      __vprinter_1000_0eb3();
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
  }
  goto LAB_1000_0efc;
}



/* 1000:134a */

undefined4 __VPTR(int param_1,int param_2)

{
  return CONCAT22(_video.displayptr._1_2_,
                  (_video._11_2_ + (uint)_video.screenwidth * (param_1 + -1) + param_2 + -1) * 2);
}



/* 1000:136f */

uint __VRAM(int param_1,uint *param_2,uint *param_3)

{
  uint *puVar1;
  uint *puVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar4 = (uint)_video.snow;
  uVar6 = uVar4;
  if (param_1 != 0) {
    uVar9 = (uint)((ulong)param_3 >> 0x10);
    puVar8 = (uint *)param_3;
    uVar10 = (uint)((ulong)param_2 >> 0x10);
    puVar7 = (uint *)param_2;
    bVar11 = puVar7 < puVar8;
    if (bVar11) {
      iVar5 = param_1 + -1;
      uVar6 = iVar5 * 2;
      puVar7 = puVar7 + iVar5;
      puVar8 = puVar8 + iVar5;
    }
    if (uVar4 == 0) {
      for (; param_1 != 0; param_1 = param_1 + -1) {
        puVar2 = puVar8;
        puVar8 = puVar8 + (uint)bVar11 * -2 + 1;
        puVar1 = puVar7;
        puVar7 = puVar7 + (uint)bVar11 * -2 + 1;
        *puVar2 = *puVar1;
      }
    }
    else {
      uVar6 = uVar9;
      if (uVar9 == uVar10) {
        do {
          do {
            bVar3 = in(0x3da);
          } while ((bool)(bVar3 & 1));
          do {
            bVar3 = in(0x3da);
          } while (!(bool)(bVar3 & 1));
          puVar1 = puVar7;
          puVar7 = puVar7 + (uint)bVar11 * -2 + 1;
          uVar6 = *puVar1;
          do {
            bVar3 = in(0x3da);
          } while ((bool)(bVar3 & 1));
          do {
            bVar3 = in(0x3da);
          } while (!(bool)(bVar3 & 1));
          puVar1 = puVar8;
          puVar8 = puVar8 + (uint)bVar11 * -2 + 1;
          *puVar1 = uVar6;
          param_1 = param_1 + -1;
        } while (param_1 != 0);
      }
      else {
        do {
          do {
            bVar3 = in(0x3da);
            uVar6 = uVar6 & 0xff00;
          } while ((bool)(bVar3 & 1));
          do {
            bVar3 = in(0x3da);
            uVar6 = CONCAT11((char)(uVar6 >> 8),bVar3 >> 1 | bVar3 << 7);
          } while (!(bool)(bVar3 & 1));
          puVar2 = puVar8;
          puVar8 = puVar8 + (uint)bVar11 * -2 + 1;
          puVar1 = puVar7;
          puVar7 = puVar7 + (uint)bVar11 * -2 + 1;
          *puVar2 = *puVar1;
          param_1 = param_1 + -1;
        } while (param_1 != 0);
      }
    }
  }
  return uVar6;
}



/* 1000:13e9 */

void __cdecl16far clrscr(void)

{
  __scroll('\x06',_video.windowx1,_video.windowy1,_video.windowx2,_video.windowy2,'\0');
  _VideoInt();
  return;
}



/* 1000:1412 */

long __cdecl16far coreleft(void)

{
  undefined2 uVar1;
  undefined2 in_DX;
  
  uVar1 = _farcoreleft();
  return CONCAT22(in_DX,uVar1);
}



/* 1000:1418 */

undefined2 _crtinit_system(char *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  do {
    pcVar2 = param_2;
    pcVar1 = param_1;
    if (*param_1 == '\0') {
      return 1;
    }
    param_1 = (char *)CONCAT22(param_1._2_2_,(char *)param_1 + 1);
    param_2 = (char *)CONCAT22(param_2._2_2_,(char *)param_2 + 1);
  } while (*pcVar1 == *pcVar2);
  return 0;
}



/* 1000:1445 */

char __cdecl16near egainstalled(void)

{
  char cVar1;
  
  cVar1 = '\x10';
  _VideoInt();
  return cVar1 + -0x10;
}



/* 1000:1453 */

void __cdecl16near _VideoInt(void)

{
  code *pcVar1;
  char cVar2;
  undefined2 in_AX;
  undefined2 uVar3;
  
  cVar2 = (char)((uint)in_AX >> 8);
  if (cVar2 == '\0') {
    if ((char)in_AX == '\x03') {
      pcVar1 = (code *)swi(0x10);
      cVar2 = (*pcVar1)();
      if (cVar2 != '\x1a') {
        UNK_0000_0487 = UNK_0000_0487 & 0xfe;
      }
      pcVar1 = (code *)swi(0x10);
      (*pcVar1)();
    }
    else if ((char)in_AX == '@') {
      cVar2 = '\x10';
      pcVar1 = (code *)swi(0x10);
      (*pcVar1)();
      if (cVar2 == '\x10') {
        return;
      }
      pcVar1 = (code *)swi(0x10);
      (*pcVar1)();
      pcVar1 = (code *)swi(0x10);
      (*pcVar1)();
      pcVar1 = (code *)swi(0x10);
      cVar2 = (*pcVar1)();
      if (cVar2 == '\x1a') {
        return;
      }
      UNK_0000_0487 = UNK_0000_0487 | 1;
      pcVar1 = (code *)swi(0x10);
      (*pcVar1)();
      return;
    }
  }
  else if (cVar2 == '\x0f') {
    pcVar1 = (code *)swi(0x10);
    uVar3 = (*pcVar1)();
    if ((char)uVar3 != '\x03') {
      return;
    }
    egainstalled(uVar3);
    return;
  }
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  return;
}



/* 1000:14d7 */

void __cdecl16near _c0crtinit(void)

{
  undefined1 in_AL;
  undefined2 uVar1;
  byte bVar2;
  
  uVar1 = CONCAT11(0xf,in_AL);
  _VideoInt();
  __crtinit(uVar1);
  bVar2 = 8;
  _VideoInt();
  _video.normattr = bVar2 & 0x7f;
  _video.attribute = bVar2 & 0x7f;
  return;
}



/* 1000:14f4 */

void __cdecl16near __crtinit(uint8_t param_1)

{
  uint8_t uVar1;
  uint8_t uVar3;
  int iVar2;
  
  _video.currmode = param_1;
  uVar1 = 0xf;
  _VideoInt();
  _video.screenwidth = uVar1;
  if (param_1 != _video.currmode) {
    uVar1 = _video.currmode;
    _VideoInt();
    uVar3 = 0xf;
    _VideoInt();
    _video.currmode = uVar1;
    _video.screenwidth = uVar3;
    if ((uVar1 == 0x3) && ('\x18' < UNK_0000_0484)) {
      _video.currmode = 0x40;
    }
  }
  if (((_video.currmode < 4) || (0x3f < _video.currmode)) || (_video.currmode == 0x7)) {
    _video.graphicsmode = 0x0;
  }
  else {
    _video.graphicsmode = 0x1;
  }
  if (_video.currmode == 0x40) {
    _video.screenheight = UNK_0000_0484 + 0x1;
  }
  else {
    _video.screenheight = 0x19;
  }
  if (_video.currmode != 0x7) {
    iVar2 = _crtinit_system((char *)"COMPAQ",(char *)"puppetmaker" + 3,0xffea,0xf000);
    if (iVar2 == 0) {
      iVar2 = egainstalled();
      if (iVar2 == 0) {
        _video.snow = 0x1;
        goto LAB_1000_159a;
      }
    }
  }
  _video.snow = 0x0;
LAB_1000_159a:
  if (_video.currmode == 0x7) {
    _video.displayptr._1_2_ = 0xb000;
  }
  else {
    _video.displayptr._1_2_ = 0xb800;
  }
  _video._11_2_ = 0;
  _video.windowy1 = 0x0;
  _video.windowx1 = 0x0;
  _video.windowx2 = _video.screenwidth + 0xff;
  _video.windowy2 = _video.screenheight + 0xff;
  return;
}



/* 1000:15cf */

void __cdecl16far _FakRealCvt(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* 1000:15d4 */

void __cdecl16far _FakScanTod(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* 1000:15fa */

void __cdecl16near malloc_FreeLastBlock(void)

{
  int in_DX;
  undefined2 uVar1;
  int iVar2;
  
  if (in_DX == __farmalloc_first) {
LAB_1000_1638:
    __farmalloc_first = 0;
    malloc__last = 0;
    __farmalloc_rover = 0;
  }
  else {
    iVar2 = *(int *)((int)(undefined4 *)&_DATA + 2);
    malloc__last = iVar2;
    if (*(int *)((int)(undefined4 *)&_DATA + 2) == 0) {
      in_DX = __farmalloc_first;
      if (iVar2 != __farmalloc_first) {
        malloc__last = *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4);
        uVar1 = 0;
        malloc_PullFreeBlock(0,iVar2);
        goto LAB_1000_1656;
      }
      goto LAB_1000_1638;
    }
  }
  uVar1 = 0;
  iVar2 = in_DX;
LAB_1000_1656:
  __brk(uVar1,iVar2);
  return;
}



/* 1000:165d */

void __cdecl16near malloc_FreeInnerBlock(void)

{
  undefined2 uVar1;
  int in_DX;
  int iVar2;
  int iStack_2;
  
  iStack_2 = *(int *)((int)(undefined4 *)&_DATA + 2);
  *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
  *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) = iStack_2;
  if ((in_DX == __farmalloc_first) || (*(int *)((int)(undefined4 *)&_DATA + 2) != 0)) {
    malloc_InsertFreeBlock();
    iStack_2 = in_DX;
  }
  else {
    iVar2 = *(int *)0x0;
    *(int *)0x0 = *(int *)0x0 + iVar2;
    iVar2 = in_DX + iVar2;
    if (*(int *)((int)(undefined4 *)&_DATA + 2) == 0) {
      *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) = iStack_2;
    }
    else {
      *(int *)((int)(undefined4 *)&_DATA + 2) = iStack_2;
    }
  }
  iVar2 = iStack_2 + *(int *)0x0;
  if (*(int *)((int)(undefined4 *)&_DATA + 2) != 0) {
    return;
  }
  *(int *)0x0 = *(int *)0x0 + *(int *)0x0;
  *(int *)((int)(undefined4 *)&_DATA + 2) = iStack_2;
  if (iVar2 != *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 2)) {
    uVar1 = *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 2);
    __farmalloc_rover = *(undefined2 *)(char *)"Borland C++ - Copyright 1991 Borland Intl.";
    *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 2) = uVar1;
    *(undefined2 *)(char *)"Borland C++ - Copyright 1991 Borland Intl." = __farmalloc_rover;
    return;
  }
  __farmalloc_rover = 0;
  return;
}



/* 1000:16b8 */

/* WARNING: Removing unreachable block (ram,0x000116ef) */

void __cdecl16far malloc_JoinFreeBlocks(void)

{
  undefined2 unaff_ES;
  
  *(int *)0x0 = *(int *)0x0 + (int)_DATA;
  *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = unaff_ES;
  uRam0006f426._0_1_ = 'r';
  uRam0006f426._1_1_ = 'l';
                    /* WARNING: Read-only address (ram,0x0006f426) is written */
  uRam0006c724._0_1_ = 'B';
  uRam0006c724._1_1_ = 'o';
                    /* WARNING: Read-only address (ram,0x0006c724) is written */
  __farmalloc_rover._0_1_ = 'B';
  __farmalloc_rover._1_1_ = 'o';
  return;
}



/* 1000:16ce */

/* WARNING: Removing unreachable block (ram,0x000116ef) */

void __cdecl16near malloc_PullFreeBlock(void)

{
  uRam0006f426._0_1_ = 'r';
  uRam0006f426._1_1_ = 'l';
                    /* WARNING: Read-only address (ram,0x0006f426) is written */
  uRam0006c724._0_1_ = 'B';
  uRam0006c724._1_1_ = 'o';
                    /* WARNING: Read-only address (ram,0x0006c724) is written */
  __farmalloc_rover._0_1_ = 'B';
  __farmalloc_rover._1_1_ = 'o';
  return;
}



/* 1000:16f7 */

void __cdecl16near malloc_InsertFreeBlock(void)

{
  undefined2 uVar1;
  
  __C0_ASM_CopyRight._0_2_ = __farmalloc_rover;
  if (__farmalloc_rover != (char *)0x0) {
    uVar1 = *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 2);
    *(char **)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 2) = (char *)"puppetmaker" + 3
    ;
                    /* WARNING: Read-only address (ram,0x00024104) is written */
    *(char **)(char *)"Borland C++ - Copyright 1991 Borland Intl." = (char *)"puppetmaker" + 3;
                    /* WARNING: Read-only address (ram,0x00024106) is written */
    __C0_ASM_CopyRight[2] = (char)uVar1;
    __C0_ASM_CopyRight[3] = SUB21(uVar1,1);
    return;
  }
  __farmalloc_rover = (char *)"puppetmaker" + 3;
                    /* WARNING: Read-only address (ram,0x00024104) is written */
  __C0_ASM_CopyRight._0_2_ = (int)(char *)"puppetmaker" + 3;
                    /* WARNING: Read-only address (ram,0x00024106) is written */
  __C0_ASM_CopyRight._2_2_ = (int)(char *)"puppetmaker" + 3;
  return;
}



/* 1000:172e */

void __cdecl16far farfree(undefined2 param_1,int param_2)

{
  __farmalloc_data_seg = (char *)"puppetmaker" + 3;
  if (param_2 != 0) {
    if (param_2 == malloc__last) {
      malloc_FreeLastBlock();
    }
    else {
      malloc_FreeInnerBlock();
    }
  }
  return;
}



/* 1000:1757 */

undefined2 __cdecl16near malloc_CreateHeap(void)

{
  uint in_AX;
  uint uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  uVar1 = __sbrk(0,0);
  if ((uVar1 & 0xf) != 0) {
    __sbrk(0x10 - (uVar1 & 0xf),0);
  }
  uVar3 = __sbrk(in_AX << 4,in_AX >> 0xc);
  uVar2 = (undefined2)((ulong)uVar3 >> 0x10);
  if ((int)uVar3 != -1) {
    __farmalloc_first = uVar2;
    malloc__last = uVar2;
    *(uint *)0x0 = in_AX;
    *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = uVar2;
    return 4;
  }
  return 0;
}



/* 1000:17bb */

undefined2 __cdecl16near malloc_ExtendHeap(void)

{
  undefined2 uVar1;
  uint in_AX;
  int iVar2;
  int iVar3;
  ulong uVar4;
  
  uVar4 = __sbrk(in_AX << 4,in_AX >> 0xc);
  iVar3 = (int)(uVar4 >> 0x10);
  if ((uint)uVar4 == 0xffff) {
    return 0;
  }
  if ((uVar4 & 0xf) != 0) {
    iVar2 = __sbrk(0x10 - ((uint)uVar4 & 0xf),0);
    if (iVar2 == -1) {
      return 0;
    }
    iVar3 = iVar3 + 1;
  }
  uVar1 = malloc__last;
  malloc__last = iVar3;
  *(uint *)0x0 = in_AX;
  *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = uVar1;
  return 4;
}



/* 1000:1815 */

undefined2 __cdecl16near malloc_AllocatePartialBlock(void)

{
  int in_AX;
  int in_DX;
  int iVar1;
  
  _DATA._0_2_ = (int)_DATA - in_AX;
  iVar1 = in_DX + (int)_DATA;
  *(int *)0x0 = in_AX;
  *(int *)((int)(undefined4 *)&_DATA + 2) = in_DX;
  *(int *)((int)(undefined4 *)&_DATA + 2) = iVar1;
  return 4;
}



/* 1000:1838 */

/* WARNING: Removing unreachable block (ram,0x000118a1) */

undefined2 __cdecl16far malloc(code *param_1)

{
  int *piVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  
  __farmalloc_data_seg = (char *)"puppetmaker" + 3;
  uVar3 = 0;
  if (param_1 != (code *)0x0) {
    uVar2 = CONCAT11((byte)((uint)(param_1 + 0x13) >> 0xc) | ((code *)init_3381_08dc < param_1) << 4
                     ,(char)((uint)(param_1 + 0x13) >> 4));
    if (__farmalloc_first == 0) {
      uVar3 = malloc_CreateHeap();
    }
    else {
      iVar4 = __farmalloc_rover;
      if (__farmalloc_rover != 0) {
        do {
          if (uVar2 <= *(uint *)0x0) {
            if (*(uint *)0x0 <= uVar2) {
              malloc_PullFreeBlock();
              *(undefined2 *)((int)(undefined4 *)&_DATA + 2) =
                   *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4);
              return 4;
            }
            uVar3 = malloc_AllocatePartialBlock();
            return uVar3;
          }
          piVar1 = (int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 2);
          iVar4 = *piVar1;
        } while (*piVar1 != __farmalloc_rover);
      }
      uVar3 = malloc_ExtendHeap();
    }
  }
  return uVar3;
}



/* 1000:1842 */

far_t __cdecl16far farmalloc(uint32_t nbytes)

{
  int *piVar1;
  ulong uVar2;
  far_t fVar3;
  far_t fVar4;
  uint uVar5;
  int iVar6;
  uint16_t extraout_DX;
  
  __farmalloc_data_seg = (char *)"puppetmaker" + 3;
  fVar3.ofs = 0;
  fVar3.seg = 0;
  if (nbytes != 0) {
    uVar2 = nbytes + 0x13;
    if ((CARRY2(nbytes._2_2_,(uint)((code *)init_3381_08dc < (code *)nbytes))) ||
       ((uVar2 & 0xfff00000) != 0)) {
      fVar3.ofs = 0;
      fVar3.seg = 0;
    }
    else {
      uVar5 = CONCAT11((byte)(uVar2 >> 8) >> 4 | (char)(uVar2 >> 0x10) * '\x10',
                       (char)((uint)uVar2 >> 4));
      if (__farmalloc_first == 0) {
        fVar3 = (far_t)malloc_CreateHeap();
      }
      else {
        iVar6 = __farmalloc_rover;
        if (__farmalloc_rover != 0) {
          do {
            if (uVar5 <= *(uint *)0x0) {
              if (*(uint *)0x0 <= uVar5) {
                malloc_PullFreeBlock();
                *(undefined2 *)((int)(undefined4 *)&_DATA + 2) =
                     *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4);
                fVar4.seg = extraout_DX;
                fVar4.ofs = 4;
                return fVar4;
              }
              fVar3 = (far_t)malloc_AllocatePartialBlock();
              return fVar3;
            }
            piVar1 = (int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 2);
            iVar6 = *piVar1;
          } while (*piVar1 != __farmalloc_rover);
        }
        fVar3 = (far_t)malloc_ExtendHeap();
      }
    }
  }
  return fVar3;
}



/* 1000:18bf */

far_t __cdecl16near malloc_ExpandBlock(void)

{
  char *pcVar1;
  undefined2 *puVar2;
  char *pcVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int in_BX;
  int iVar10;
  char *pcVar11;
  undefined2 *puVar12;
  char *pcVar13;
  undefined2 *puVar14;
  bool bVar15;
  far_t fVar16;
  
  iVar10 = in_BX;
  fVar16 = farmalloc(CONCAT22(malloc_save_hi,malloc_save_lo));
  if (fVar16.seg == 0) {
    return fVar16;
  }
  uVar9 = *(int *)0x0 - 1;
  pcVar13 = (char *)"Borland C++ - Copyright 1991 Borland Intl.";
  pcVar11 = (char *)"Borland C++ - Copyright 1991 Borland Intl.";
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    pcVar3 = pcVar13;
    pcVar13 = pcVar13 + 2;
    pcVar1 = pcVar11;
    pcVar11 = pcVar11 + 2;
    *(undefined2 *)pcVar3 = *(undefined2 *)pcVar1;
  }
  if (uVar9 != 0) {
    iVar6 = fVar16.seg + 1;
    iVar5 = in_BX + 1;
    while( true ) {
      puVar14 = (undefined2 *)0x0;
      puVar12 = (undefined2 *)0x0;
      uVar7 = uVar9;
      if (0x1000 < uVar9) {
        uVar7 = 0x1000;
      }
      for (iVar8 = uVar7 << 3; iVar8 != 0; iVar8 = iVar8 + -1) {
        puVar4 = puVar14;
        puVar14 = puVar14 + 1;
        puVar2 = puVar12;
        puVar12 = puVar12 + 1;
        *puVar4 = *puVar2;
      }
      bVar15 = uVar9 < 0x1000;
      uVar9 = uVar9 - 0x1000;
      if (bVar15 || uVar9 == 0) break;
      iVar6 = iVar6 + 0x1000;
      iVar5 = iVar5 + 0x1000;
    }
  }
  farfree(iVar10,in_BX);
  fVar16.ofs = 4;
  return fVar16;
}



/* 1000:193b */

undefined4 __cdecl16near malloc_ShrinkBlock(void)

{
  int in_AX;
  int in_CX;
  int iVar1;
  int in_BX;
  int iVar2;
  
  if (in_BX != malloc__last) {
    iVar2 = in_BX + in_AX;
    *(int *)0x0 = in_CX - in_AX;
    *(int *)((int)(undefined4 *)&_DATA + 2) = in_BX;
    *(int *)0x0 = in_AX;
    iVar1 = in_BX + in_CX;
    if (*(int *)((int)(undefined4 *)&_DATA + 2) == 0) {
      *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) = iVar2;
    }
    else {
      *(int *)((int)(undefined4 *)&_DATA + 2) = iVar2;
    }
    farfree();
    return CONCAT22(in_BX,4);
  }
  *(int *)0x0 = in_AX;
  __brk(0,in_BX + in_AX);
  return CONCAT22(in_BX,4);
}



/* 1000:199f */

uint16_t __cdecl16far _realloc(undefined2 param_1,int param_2,code *param_3)

{
  uint uVar1;
  uint16_t uVar2;
  far_t fVar3;
  
  __farmalloc_data_seg = (char *)"puppetmaker" + 3;
  malloc_save_hi = 0;
  malloc_save_lo = param_3;
  if (param_2 == 0) {
    fVar3 = farmalloc(ZEXT24(param_3));
    uVar2 = fVar3.ofs;
  }
  else if (param_3 == (code *)0x0) {
    farfree(0,param_2);
    uVar2 = 0;
  }
  else {
    uVar1 = CONCAT11((byte)((uint)(param_3 + 0x13) >> 0xc) | ((code *)init_3381_08dc < param_3) << 4
                     ,(char)((uint)(param_3 + 0x13) >> 4));
    if (*(uint *)0x0 < uVar1) {
      uVar2 = malloc_ExpandBlock();
    }
    else if (*(uint *)0x0 == uVar1) {
      uVar2 = 4;
    }
    else {
      uVar2 = malloc_ShrinkBlock();
    }
  }
  return uVar2;
}



/* 1000:19a6 */

uint8_t __cdecl16far farrealloc(long oldblock,long nbytes)

{
  ulong uVar1;
  uint8_t uVar2;
  uint uVar3;
  far_t fVar4;
  
  __farmalloc_data_seg = (char *)"puppetmaker" + 3;
  malloc_save_hi = nbytes._2_2_;
  malloc_save_lo = (code *)nbytes;
  if (oldblock._2_2_ == 0) {
    fVar4 = farmalloc(nbytes);
    uVar2 = (uint8_t)fVar4.ofs;
  }
  else {
    if (nbytes == 0) {
      farfree(0,oldblock._2_2_);
    }
    else {
      uVar1 = nbytes + 0x13;
      if ((!CARRY2(nbytes._2_2_,(uint)((code *)init_3381_08dc < (code *)nbytes))) &&
         ((uVar1 & 0xfff00000) == 0)) {
        uVar3 = CONCAT11((byte)(uVar1 >> 8) >> 4 | (char)(uVar1 >> 0x10) * '\x10',
                         (char)((uint)uVar1 >> 4));
        if (*(uint *)0x0 < uVar3) {
          uVar2 = malloc_ExpandBlock();
          return uVar2;
        }
        if (*(uint *)0x0 == uVar3) {
          __farmalloc_data_seg = (char *)((int)(char *)"puppetmaker" + 3);
          return 0x4;
        }
        uVar2 = malloc_ShrinkBlock();
        return uVar2;
      }
    }
    uVar2 = 0x0;
  }
  return uVar2;
}



/* 1000:1a20 */

undefined2 _brk_normalize(uint16_t param_1,uint16_t param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (param_2 - _psp) + 0x40 >> 6;
  if (uVar2 != brk_normalize_xsize) {
    uVar2 = uVar2 * 0x40;
    if (_heaptop.seg < uVar2 + _psp) {
      uVar2 = _heaptop.seg - _psp;
    }
    iVar1 = _setblock(_psp,uVar2);
    if (iVar1 != -1) {
      _heaptop.ofs = 0;
      _heaptop.seg = _psp + iVar1;
      return 0;
    }
    brk_normalize_xsize = uVar2 >> 6;
  }
  _brklvl.seg = param_2;
  _brklvl.ofs = param_1;
  return 1;
}



/* 1000:1a96 */

undefined2 __cdecl16near __brk(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  undefined1 in_CF;
  undefined1 in_ZF;
  
  N_PCMP_at_();
  if (((!(bool)in_CF) && (N_PCMP_at_(), (bool)in_CF || (bool)in_ZF)) &&
     (iVar1 = _brk_normalize(param_1,param_2), iVar1 != 0)) {
    return 0;
  }
  return 0xffff;
}



/* 1000:1ad5 */

undefined4 __cdecl16near __sbrk(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  
  uVar5 = N_LXLSH_at_();
  uVar1 = (uint)uVar5 + _brklvl.ofs;
  iVar2 = uVar1 + param_1;
  uVar1 = (int)((ulong)uVar5 >> 0x10) + (uint)CARRY2((uint)uVar5,_brklvl.ofs) + param_2 +
          (uint)CARRY2(uVar1,param_1);
  uVar3 = uVar1 < 0xf;
  uVar4 = uVar1 == 0xf;
  if (0xe < (int)uVar1) {
    if (0xf < (int)uVar1) {
      return 0xffffffff;
    }
    uVar3 = iVar2 != -1;
    uVar4 = iVar2 == -1;
  }
  uVar5 = N_PADD_at_();
  N_PCMP_at_();
  if (((!(bool)uVar3) && (N_PCMP_at_(), (bool)uVar3 || (bool)uVar4)) &&
     (iVar2 = _brk_normalize(uVar5), iVar2 != 0)) {
    return uVar5;
  }
  return 0xffffffff;
}



/* 1000:1b63 */

uint __cdecl16far _farcoreleft(void)

{
  uint16_t uVar1;
  undefined2 uStackY_6;
  
  uVar1 = _heaptop.seg;
  uStackY_6 = N_PSBP_at_(0);
  if ((uVar1 != 0) || (0x10 < uStackY_6)) {
    uStackY_6 = uStackY_6 - 0x10;
  }
  return uStackY_6 & 0xfff0;
}



/* 1000:1bb3 */

undefined2 __cdecl16far
_gettext(int param_1,int param_2,int param_3,int param_4,int param_5,undefined2 param_6)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = __VALIDATEXY(param_4,param_3,param_2,param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = (param_3 - param_1) + 1;
    for (; param_2 <= param_4; param_2 = param_2 + 1) {
      iVar4 = param_5;
      uVar2 = param_6;
      uVar3 = __VPTR(param_2,param_1);
      __SCREENIO(iVar1,uVar3,iVar4,uVar2);
      param_5 = param_5 + iVar1 * 2;
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 1000:1c09 */

undefined2 __cdecl16far
_puttext(int param_1,int param_2,int param_3,int param_4,int param_5,undefined2 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (param_3 - param_1) + 1;
  for (; param_2 <= param_4; param_2 = param_2 + 1) {
    uVar2 = __VPTR(param_2,param_1);
    __SCREENIO(iVar1,param_5,param_6,uVar2);
    param_5 = param_5 + iVar1 * 2;
  }
  return 1;
}



/* 1000:1c4c */

undefined2 __cdecl16far
_movetext(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iStack_6;
  int iStack_4;
  
  iVar1 = __VALIDATEXY(param_4,param_3,param_2,param_1);
  if ((iVar1 == 0) ||
     (iVar1 = __VALIDATEXY(param_6 + (param_4 - param_2),param_5 + (param_3 - param_1),param_6,
                           param_5), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    iStack_4 = param_4;
    iStack_6 = 1;
    iVar1 = param_2;
    if (param_2 < param_6) {
      iStack_4 = param_2;
      iStack_6 = -1;
      iVar1 = param_4;
    }
    for (; iStack_4 + iStack_6 != iVar1; iVar1 = iVar1 + iStack_6) {
      uVar3 = __VPTR(param_6 + (iVar1 - param_2),param_5);
      uVar4 = __VPTR(iVar1,param_1);
      __SCREENIO((param_3 - param_1) + 1,uVar4,uVar3);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 1000:1ced */

undefined2 screenpos(uint param_1)

{
  char cVar1;
  
  cVar1 = (char)((param_1 >> 1) / (uint)_video.screenwidth);
  return CONCAT11(cVar1,(char)(param_1 >> 1) - cVar1 * _video.screenwidth);
}



/* 1000:1d25 */

void moveto(int *param_1,int *param_2)

{
  byte bVar1;
  char cVar3;
  int iVar2;
  
  iVar2 = *param_2;
  if (iVar2 != *param_1) {
    _VideoInt();
    *param_1 = iVar2;
  }
  cVar3 = (char)((uint)iVar2 >> 8);
  bVar1 = (char)iVar2 + 1;
  iVar2 = CONCAT11(cVar3,bVar1);
  if (_video.screenwidth <= bVar1) {
    iVar2 = (uint)(byte)(cVar3 + 1) << 8;
  }
  *param_2 = iVar2;
  return;
}



/* 1000:1d59 */

void bios(int param_1,undefined2 *param_2,undefined2 *param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  bool bVar3;
  bool bVar4;
  undefined2 local_8;
  undefined2 local_6;
  undefined2 local_4;
  
  local_8 = _wherexy();
  bVar3 = param_3._2_2_ == _video.displayptr._1_2_;
  if (bVar3) {
    local_4 = screenpos((undefined2 *)param_3,param_3._2_2_);
  }
  bVar4 = param_2._2_2_ == _video.displayptr._1_2_;
  if (bVar4) {
    local_6 = screenpos((undefined2 *)param_2,param_2._2_2_);
  }
  while (param_1 != 0) {
    if (bVar4) {
      uVar1 = moveto(&local_8,unaff_SS,&local_6,unaff_SS);
      uVar2 = CONCAT11(8,uVar1);
      _VideoInt();
    }
    else {
      uVar2 = *param_2;
      param_2 = (undefined2 *)CONCAT22(param_2._2_2_,(undefined2 *)param_2 + 1);
    }
    if (bVar3) {
      moveto(&local_8,unaff_SS,&local_4,unaff_SS);
      _VideoInt();
      param_1 = param_1 + -1;
    }
    else {
      *param_3 = uVar2;
      param_3 = (undefined2 *)CONCAT22(param_3._2_2_,(undefined2 *)param_3 + 1);
      param_1 = param_1 + -1;
    }
  }
  _VideoInt();
  return;
}



/* 1000:1e23 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __SCREENIO(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 param_5)

{
  if ((_video.graphicsmode == 0x0) && (ram0x0002c9bb != 0)) {
    __VRAM(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    bios(param_1,param_2,param_3,param_4,param_5);
  }
  return;
}



/* 1000:1e5f */

undefined2 __VALIDATEXY(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined2 uVar1;
  
  if ((((_video.screenwidth < param_4) || (_video.screenwidth < param_2)) ||
      ((int)param_2 < (int)param_4)) ||
     (((_video.screenheight < param_3 || (_video.screenheight < param_1)) ||
      ((int)param_1 < (int)param_3)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 1000:1ea2 */

void _zapline(int param_1,int param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  
  uVar1 = CONCAT11(_video.attribute,0x20);
  for (; param_2 <= param_1; param_2 = param_2 + 1) {
    *param_3 = uVar1;
    param_3 = (undefined2 *)CONCAT22(param_3._2_2_,(undefined2 *)param_3 + 1);
  }
  return;
}



/* 1000:1ec4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __scroll(uchar dir,uchar x1,uchar y1,uchar x2,uchar y2,uchar lines)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  undefined2 unaff_SS;
  undefined1 local_a2 [160];
  
  if (((_video.graphicsmode == 0x0) && (ram0x0002c9bb != 0)) && (lines == '\x01')) {
    cVar1 = x1 + '\x01';
    bVar2 = y1 + 1;
    cVar3 = x2 + '\x01';
    bVar4 = y2 + 1;
    if (dir == '\x06') {
      _movetext(cVar1,bVar2 + 1,cVar3,bVar4,cVar1,bVar2);
      _gettext(cVar1,bVar4,cVar1,bVar4,local_a2);
      _zapline(cVar3,cVar1,local_a2,unaff_SS);
    }
    else {
      _movetext(cVar1,bVar2,cVar3,bVar4 - 1,cVar1,bVar2 + 1);
      _gettext(cVar1,bVar2,cVar1,bVar2,local_a2);
      _zapline(cVar3,cVar1,local_a2,unaff_SS);
      bVar4 = bVar2;
    }
    _puttext(cVar1,bVar4,cVar3,bVar4,local_a2);
  }
  else {
    _VideoInt();
  }
  return;
}



/* 1000:2032 */

/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl16far __setargv(uint param_1)

{
  char *pcVar1;
  char *pcVar2;
  byte bVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  int extraout_DX;
  int extraout_DX_00;
  uint in_BX;
  int iVar7;
  int *piVar8;
  undefined2 unaff_SI;
  char *pcVar9;
  char *pcVar10;
  undefined2 unaff_DI;
  undefined2 uVar11;
  int unaff_SS;
  undefined2 uVar12;
  bool bVar13;
  undefined1 uVar14;
  undefined2 in_stack_00000000;
  uint uStack0002;
  
  __setargv_SavedES = uStack0002;
  __setargv_SavedReturn2 = param_1;
  __setargv_SavedDS = (char *)"puppetmaker" + 3;
  pcVar9 = (char *)(_env + 2);
  uVar5 = 1;
  uVar11 = _psp;
  __setargv_SavedReturn = in_stack_00000000;
  __setargv_SavedSI = unaff_SI;
  __setargv_SavedDI = unaff_DI;
  if (2 < DosVersion.major) {
    uVar5 = 0x7f;
    in_BX = in_BX & 0xff00;
    pcVar10 = pcVar9;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar1 = pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (*pcVar1 != '\0');
    if (uVar5 == 0) goto code_r0x000120eb;
    uVar5 = uVar5 ^ 0x7f;
    uVar11 = _envseg_at_;
  }
  param_1 = in_BX;
  puVar4 = (undefined1 *)(uVar5 + *(byte *)((int)(int *)&errno + 1) + 2 & 0xfffe);
  iVar7 = -(int)puVar4;
  pcVar10 = (char *)((int)&param_1 + iVar7);
  if (puVar4 <= &param_1) {
    *(undefined2 *)((int)&uStack0002 + iVar7) = uVar11;
    uVar12 = *(undefined2 *)((int)&uStack0002 + iVar7);
    *(int *)((int)&uStack0002 + iVar7) = unaff_SS;
    uVar11 = *(undefined2 *)((int)&uStack0002 + iVar7);
    *(uint *)((int)&uStack0002 + iVar7) = uVar5;
    while (uVar5 - 1 != 0) {
      pcVar2 = pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar1 = pcVar9;
      pcVar9 = pcVar9 + 1;
      *pcVar2 = *pcVar1;
      uVar5 = uVar5 - 1;
    }
    bVar13 = false;
    *pcVar10 = '\0';
    uVar14 = uVar5 == 0;
Processing:
    *(char **)(&stack0x0000 + iVar7) = (char *)"cleric castle" + 6;
    bVar3 = NextChar();
    iVar6 = extraout_DX;
    if (bVar13 || (bool)uVar14) {
      do {
        pcVar9 = __setargv_SavedDS;
        if (bVar13) {
          pcVar10 = (char *)&param_1;
          iVar6 = *(int *)((int)&uStack0002 + iVar7) + iVar6;
          *(uint *)&_argc_at_ = uVar5;
          iVar7 = uVar5 + 1;
          piVar8 = (int *)(&param_1 + iVar7 * -2);
          if (&param_1 < (undefined1 *)(iVar7 * 4)) goto code_r0x000120eb;
          *(undefined2 *)&_argv_at_ = piVar8;
          *(int *)&_argv_at__2 = unaff_SS;
          pcVar9 = __setargv_SavedDS;
          goto SetArgvX;
        }
        *(char **)(&stack0x0000 + iVar7) = (char *)"cleric castle" + 0xd;
        bVar3 = NextChar();
        iVar6 = extraout_DX_00;
      } while (!bVar13 && !(bool)uVar14);
    }
    if ((bVar3 != 0x20) && (bVar3 != 0xd)) goto code_r0x000120b9;
    goto EndArgument;
  }
code_r0x000120eb:
                    /* WARNING: Subroutine does not return */
  _abort();
code_r0x000120b9:
  bVar13 = bVar3 < 9;
  uVar14 = false;
  if (bVar3 == 9) {
EndArgument:
    bVar13 = false;
    uVar14 = true;
  }
  goto Processing;
  while( true ) {
    *piVar8 = (int)pcVar10;
    piVar8[1] = unaff_SS;
    piVar8 = piVar8 + 2;
    do {
      pcVar1 = pcVar10;
      pcVar10 = pcVar10 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0 && *pcVar1 != '\0');
    if (*pcVar1 != '\0') break;
SetArgvX:
    if (iVar6 == 0) break;
  }
  *piVar8 = 0;
  piVar8[1] = 0;
  (&uStack0002)[iVar7 * -2] = *(undefined2 *)&__setargv_SavedReturn2;
  *(undefined2 *)(&stack0x0000 + iVar7 * -4) = *(undefined2 *)&__setargv_SavedES;
  *(undefined2 *)&__C0argc = *(undefined2 *)&_argc_at_;
  *(undefined2 *)&__C0argv_2 = *(undefined2 *)&_argv_at__2;
  *(undefined2 *)&__C0argv = *(undefined2 *)&_argv_at_;
                    /* WARNING: Could not recover jumptable at 0x00012153. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*(undefined2 *)&__setargv_SavedReturn)();
  return;
}



/* 1000:20c1 */

int __cdecl16near NextChar(void)

{
  char cVar1;
  undefined1 uVar2;
  int in_AX;
  int iVar3;
  int in_CX;
  char *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  
  uVar2 = (undefined1)in_AX;
  if (in_AX != 0) {
    *unaff_DI = uVar2;
  }
  iVar3 = in_AX << 8;
  if (in_CX != 0) {
    cVar1 = *unaff_SI;
    iVar3 = CONCAT11(uVar2,cVar1 + -0x22);
    if ((((char)(cVar1 + -0x22) != '\0') && (iVar3 = CONCAT11(uVar2,cVar1), cVar1 == '\\')) &&
       (unaff_SI[1] == '\"')) {
      iVar3 = CONCAT11(uVar2,unaff_SI[1]);
    }
  }
  return iVar3;
}



/* 1000:2157 */

undefined2 __cdecl16far _setblock(undefined2 param_1,undefined2 param_2)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    __IOerror(uVar2);
  }
  else {
    param_2 = 0xffff;
  }
  return param_2;
}



/* 1000:2173 */

undefined2 __cdecl16near _wherexy(void)

{
  undefined2 in_DX;
  
  _VideoInt();
  return in_DX;
}



/* 1000:217d */

int __cdecl16far _wherex(void)

{
  byte bVar1;
  
  bVar1 = _wherexy();
  return ((uint)bVar1 - (uint)_video.windowx1) + 1;
}



/* 1000:218c */

int __cdecl16far _wherey(void)

{
  uint uVar1;
  
  uVar1 = _wherexy();
  return ((uVar1 >> 8) - (uint)_video.windowy1) + 1;
}



/* 1000:219f */

uint __cdecl16far _atol(byte *param_1)

{
  ulong uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  byte *pbVar6;
  undefined2 uVar7;
  
  uVar7 = (undefined2)((ulong)param_1 >> 0x10);
  pbVar6 = (byte *)param_1;
  uVar3 = 0;
  do {
    bVar5 = *pbVar6;
    pbVar6 = pbVar6 + 1;
  } while ((((byte *)_ctype + 1)[bVar5] & 1) != 0);
  bVar2 = false;
  if (bVar5 != 0x2b) {
    if (bVar5 != 0x2d) goto LAB_1000_21d0;
    bVar2 = true;
  }
  do {
    bVar5 = *pbVar6;
    pbVar6 = pbVar6 + 1;
LAB_1000_21d0:
    if ((0x39 < bVar5) || (bVar5 < 0x30)) goto LAB_1000_2204;
    uVar1 = (ulong)uVar3;
    uVar4 = (uint)(uVar1 * 10);
    uVar3 = uVar4 + (byte)(bVar5 - 0x30);
  } while ((char)((char)(uVar1 * 10 >> 0x10) + CARRY2(uVar4,(uint)(byte)(bVar5 - 0x30))) == '\0');
  while( true ) {
    bVar5 = *pbVar6;
    pbVar6 = pbVar6 + 1;
    if ((0x39 < bVar5) || (bVar5 < 0x30)) break;
    uVar3 = uVar3 * 10 + (uint)(byte)(bVar5 - 0x30);
  }
LAB_1000_2204:
  if (bVar2) {
    uVar3 = -uVar3;
  }
  return uVar3;
}



/* 1000:2214 */

void __cdecl16far _atoi(undefined2 param_1,undefined2 param_2)

{
  _atol(param_1,param_2);
  return;
}



/* 1000:2225 */

int __cdecl16far close(int handle)

{
  code *pcVar1;
  int iVar2;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if ((bool)in_CF) {
    iVar2 = __IOerror();
  }
  else {
    ((uint16_t *)_openfd)[handle] = 0;
    iVar2 = 0;
  }
  return iVar2;
}



/* 1000:2243 */

int CreateFile(uint16_t param_1)

{
  code *pcVar1;
  int iVar2;
  undefined2 unaff_BP;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  iVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    iVar2 = __IOerror(iVar2);
  }
  else {
    ((uint16_t *)_openfd)[iVar2] = param_1;
  }
  return iVar2;
}



/* 1000:2270 */

int __cdecl16far _creat(char *path,int mode)

{
  int iVar1;
  undefined2 in_stack_00000006;
  
  iVar1 = CreateFile((char *)"%s: %s %d gold. provides housing for %d %s and feeds %d %s." + 0x12,
                     0x3c,mode,path,in_stack_00000006);
  return iVar1;
}



/* 1000:2288 */

void __cdecl16far _creattemp(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  CreateFile(_fmode | 4,0x5a,param_3,param_1,param_2);
  return;
}



/* 1000:22a3 */

void __cdecl16far _creatnew(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  CreateFile(_fmode | 4,0x5b,param_3,param_1,param_2);
  return;
}



/* 1000:22be */

undefined2 __cdecl16far fflush(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((int *)param_1 == (int *)0x0 && param_1._2_2_ == 0) {
    flushall();
  }
  else {
    if ((int *)((int *)param_1)[9] != (int *)param_1) {
      return 0xffff;
    }
    if (*param_1 < 0) {
      iVar2 = ((int *)param_1)[3] + *param_1 + 1;
      *param_1 = *param_1 - iVar2;
      iVar3 = ((int *)param_1)[5];
      iVar1 = ((int *)param_1)[4];
      ((int *)param_1)[7] = iVar3;
      ((int *)param_1)[6] = iVar1;
      iVar3 = __write((int)(char)((int *)param_1)[2],iVar1,iVar3,iVar2);
      if ((iVar3 != iVar2) && ((((int *)param_1)[1] & 0x200U) == 0)) {
        ((int *)param_1)[1] = ((int *)param_1)[1] | 0x10;
        return 0xffff;
      }
    }
    else if (((((int *)param_1)[1] & 8U) != 0) ||
            ((((int *)param_1)[7] == param_1._2_2_ &&
             (((int *)param_1)[6] == (int)(int *)param_1 + 5)))) {
      *param_1 = 0;
      if ((((int *)param_1)[7] == param_1._2_2_) && (((int *)param_1)[6] == (int)(int *)param_1 + 5)
         ) {
        iVar3 = ((int *)param_1)[4];
        ((int *)param_1)[7] = ((int *)param_1)[5];
        ((int *)param_1)[6] = iVar3;
      }
    }
  }
  return 0;
}



/* 1000:238b */

long __cdecl16far filelength(int hande)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  
  bVar5 = false;
  pcVar1 = (code *)swi(0x21);
  uVar6 = (*pcVar1)();
  iVar2 = (int)uVar6;
  if (!bVar5) {
    bVar5 = false;
    pcVar1 = (code *)swi(0x21);
    uVar6 = (*pcVar1)((int)((ulong)uVar6 >> 0x10));
    iVar4 = (int)((ulong)uVar6 >> 0x10);
    iVar3 = (int)uVar6;
    iVar2 = iVar3;
    if (!bVar5) {
      pcVar1 = (code *)swi(0x21);
      iVar2 = (*pcVar1)();
      if (!bVar5) goto LAB_1000_23c8;
    }
  }
  iVar3 = __IOerror(iVar2);
  iVar4 = iVar3 >> 0xf;
LAB_1000_23c8:
  return CONCAT22(iVar4,iVar3);
}



/* 1000:23cc */

int __cdecl16far flushall(void)

{
  uint16_t uVar1;
  int iVar2;
  FILE *pFStack_6;
  
  iVar2 = 0;
  pFStack_6 = (FILE *)_streams;
  uVar1 = _nfile;
  while (uVar1 != 0) {
    if ((pFStack_6->flags & 3) != 0) {
      fflush(pFStack_6,(char *)"puppetmaker" + 3);
      iVar2 = iVar2 + 1;
    }
    pFStack_6 = pFStack_6 + 1;
    uVar1 = uVar1 - 1;
  }
  return iVar2;
}



/* 1000:240e */

int fseek_Displacement(uint *param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  undefined2 uVar8;
  undefined4 uStack_6;
  
  uVar8 = (undefined2)((ulong)param_1 >> 0x10);
  puVar6 = (uint *)param_1;
  if ((int)*param_1 < 0) {
    iVar2 = puVar6[3] + *param_1 + 1;
  }
  else {
    uVar5 = (int)*param_1 >> 0xf;
    iVar2 = (*param_1 ^ uVar5) - uVar5;
  }
  iVar7 = iVar2;
  if ((puVar6[1] & 0x40) == 0) {
    uStack_6 = (char *)CONCAT22(puVar6[7],(char *)puVar6[6]);
    iVar3 = iVar2;
    if ((int)*param_1 < 0) {
      while (iVar3 = iVar2 + -1, iVar2 != 0) {
        uStack_6 = (char *)CONCAT22(uStack_6._2_2_,(char *)uStack_6 + -1);
        iVar2 = iVar3;
        if (*uStack_6 == '\n') {
          iVar7 = iVar7 + 1;
        }
      }
    }
    else {
      while (pcVar1 = uStack_6, iVar4 = iVar3 + -1, iVar7 = iVar2, iVar3 != 0) {
        uStack_6 = (char *)CONCAT22(uStack_6._2_2_,(char *)uStack_6 + 1);
        iVar3 = iVar4;
        if (*pcVar1 == '\n') {
          iVar2 = iVar2 + 1;
        }
      }
    }
  }
  return iVar7;
}



/* 1000:2490 */

undefined2 __cdecl16far fseek(int *param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  iVar1 = fflush();
  if (iVar1 == 0) {
    if ((param_4 == 1) && (0 < *param_1)) {
      uVar3 = fseek_Displacement();
      bVar5 = param_2 < uVar3;
      param_2 = param_2 - uVar3;
      param_3 = (param_3 - ((int)uVar3 >> 0xf)) - (uint)bVar5;
    }
    ((int *)param_1)[1] = ((int *)param_1)[1] & 0xfe5f;
    *param_1 = 0;
    iVar1 = ((int *)param_1)[4];
    ((int *)param_1)[7] = ((int *)param_1)[5];
    ((int *)param_1)[6] = iVar1;
    iVar4 = lseek((int)(char)((int *)param_1)[2],CONCAT22(param_3,param_2),param_4);
    if ((iVar1 == -1) && (iVar4 == -1)) {
      uVar2 = 0xffff;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffff;
  }
  return uVar2;
}



/* 1000:2510 */

int __cdecl16far ftell(int *param_1)

{
  int iVar1;
  int in_DX;
  int *piVar2;
  undefined2 uVar3;
  int iStack_6;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  piVar2 = (int *)param_1;
  iStack_6 = _tell((int)(char)piVar2[2]);
  if ((in_DX != -1) || (iStack_6 != -1)) {
    if (*param_1 < 0) {
      iVar1 = fseek_Displacement(piVar2,uVar3);
      iStack_6 = iStack_6 + iVar1;
    }
    else {
      iVar1 = fseek_Displacement(piVar2,uVar3);
      iStack_6 = iStack_6 - iVar1;
    }
  }
  return iStack_6;
}



/* 1000:2568 */

/* Borland C++ 3.0 has no getcwd(), so we have to provide one  */

char * __cdecl16far getcwd(char *__buf,size_t __size)

{
  int iVar1;
  size_t sVar2;
  int in_DX;
  int in_stack_00000006;
  char cwd [68];
  
  iVar1 = getdisk();
  cwd[0] = (char)iVar1 + 'A';
  cwd[1] = ':';
  cwd[2] = '\\';
  iVar1 = getcurdir(0,cwd + 3);
  if (iVar1 != -1) {
    sVar2 = strlen(cwd);
    if (sVar2 < __size) {
      if ((__buf != (char *)0x0 || in_stack_00000006 != 0) ||
         (__buf = (char *)malloc(__size), __buf != (char *)0x0 || in_DX != 0)) {
        strcpy(__buf,cwd);
        return __buf;
      }
      errno = 8;
    }
    else {
      errno = 0x22;
    }
  }
  return (char *)0x0;
}



/* 1000:25f6 */

int __cdecl16far memcmp(char *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  
  uVar3 = 0;
  uVar4 = 0;
  if (param_3 != 0) {
    uVar8 = (undefined2)((ulong)param_1 >> 0x10);
    pcVar5 = (char *)param_1;
    uVar7 = (undefined2)((ulong)param_2 >> 0x10);
    pcVar6 = (char *)param_2;
    do {
      if (param_3 == 0) break;
      param_3 = param_3 + -1;
      pcVar2 = pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar1 = pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar1 == *pcVar2);
    uVar3 = (uint)(byte)pcVar5[-1];
    uVar4 = (uint)(byte)pcVar6[-1];
  }
  return uVar3 - uVar4;
}



/* 1000:261e */

void __cdecl16far memcpy(uint8_t *dst,uint8_t *src,uint16_t size)

{
  uint8_t *puVar1;
  uint8_t *puVar2;
  uint uVar3;
  undefined2 in_stack_00000006;
  undefined2 in_stack_0000000a;
  
  for (uVar3 = size >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2 = dst;
    dst = dst + 2;
    puVar1 = src;
    src = src + 2;
    *(undefined2 *)puVar2 = *(undefined2 *)puVar1;
  }
  if ((size & 1) != 0) {
    *dst = *src;
  }
  return;
}



/* 1000:2642 */

void __cdecl16far _fsetmem(void *dest,uint16_t len,uint16_t val)

{
  undefined2 *puVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)dest >> 0x10);
  puVar3 = (undefined2 *)dest;
  if (((ulong)dest & 1) != 0) {
    if (len == 0) {
      return;
    }
    puVar3 = (undefined2 *)((int)puVar3 + 1);
    *(undefined1 *)dest = (undefined1)val;
    len = len - 1;
  }
  for (uVar2 = len >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = CONCAT11((undefined1)val,(undefined1)val);
  }
  if ((len & 1) != 0) {
    *(undefined1 *)puVar3 = (undefined1)val;
  }
  return;
}



/* 1000:2666 */

void * __cdecl16far _fmemset(void *ptr,uint16_t v,uint16_t count)

{
  undefined2 in_AX;
  
  _fsetmem(ptr,count,CONCAT11((char)((uint)in_AX >> 8),(undefined1)v));
  return ptr;
}



/* 1000:2685 */

void __cdecl16far __fmovmem(uint8_t *param_1,uint8_t *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  byte in_CF;
  undefined1 *in_stack_00000004;
  undefined1 *in_stack_00000008;
  
  N_PCMP_at_((char *)"puppetmaker" + 3);
  uVar5 = (uint)in_CF;
  if (uVar5 != 0) {
    in_stack_00000004 = in_stack_00000004 + param_3 + -1;
    in_stack_00000008 = in_stack_00000008 + param_3 + -1;
  }
  if (((uint)in_stack_00000008 & 1) != 0) {
    if (param_3 == 0) {
      return;
    }
    puVar3 = in_stack_00000008;
    in_stack_00000008 = in_stack_00000008 + (uint)in_CF * -2 + 1;
    puVar1 = in_stack_00000004;
    in_stack_00000004 = in_stack_00000004 + (uint)in_CF * -2 + 1;
    *puVar3 = *puVar1;
    param_3 = param_3 - 1;
  }
  puVar7 = (undefined2 *)(in_stack_00000004 + -uVar5);
  puVar8 = (undefined2 *)(in_stack_00000008 + -uVar5);
  for (uVar6 = (uint)param_3 >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
    puVar4 = puVar8;
    puVar8 = puVar8 + (uint)in_CF * -2 + 1;
    puVar2 = puVar7;
    puVar7 = puVar7 + (uint)in_CF * -2 + 1;
    *puVar4 = *puVar2;
  }
  if ((param_3 & 1U) != 0) {
    *(undefined1 *)((int)puVar8 + uVar5) = *(undefined1 *)((int)puVar7 + uVar5);
  }
  return;
}



/* 1000:26d7 */

uint8_t * __cdecl16far _fmemmove(uint8_t *dst,uint8_t *src,int count)

{
  uint8_t *in_stack_00000006;
  uint8_t *in_stack_0000000a;
  
  __fmovmem(in_stack_0000000a,in_stack_00000006,count);
  return dst;
}



/* 1000:26f8 */

int __cdecl16far _open(char *pathname,int access)

{
  code *pcVar1;
  int iVar2;
  undefined2 unaff_BP;
  bool bVar3;
  
  bVar3 = false;
  pcVar1 = (code *)swi(0x21);
  iVar2 = (*pcVar1)();
  if (bVar3) {
    iVar2 = __IOerror(iVar2);
  }
  else {
    ((uint16_t *)_openfd)[iVar2] = access & 0xb8ffU | 0x8000;
  }
  return iVar2;
}



/* 1000:2747 */

void __cdecl16far printf(char *fmt,undefined2 param_2)

{
  __vprinter(&param_2,fmt,0x863a,(char *)"puppetmaker" + 3,(char *)"Aggressive" + 7);
  return;
}



/* 1000:2762 */

void __cdecl16far _fputc(char param_1,int *param_2)

{
  *param_2 = *param_2 + -1;
  fputc((int)param_1,(int *)param_2,param_2._2_2_);
  return;
}



/* 1000:277e */

/* WARNING: Type propagation algorithm not settling */

uint __cdecl16far fputc(byte param_1,int *param_2)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  undefined2 uVar4;
  
  _fputc_c = param_1;
  uVar4 = (undefined2)((ulong)param_2 >> 0x10);
  piVar3 = (int *)param_2;
  if (*param_2 < -1) {
    *param_2 = *param_2 + 1;
    iVar2 = piVar3[7];
    pbVar1 = (byte *)piVar3[6];
    piVar3[6] = piVar3[6] + 1;
    *pbVar1 = _fputc_c;
    if (((piVar3[1] & 8U) == 0) || ((_fputc_c != 10 && (_fputc_c != 0xd)))) goto LAB_1000_2909;
    iVar2 = fflush();
joined_r0x000127d7:
    if (iVar2 == 0) {
LAB_1000_2909:
      return (uint)_fputc_c;
    }
  }
  else {
    if (((piVar3[1] & 0x90U) == 0) && ((piVar3[1] & 2U) != 0)) {
      piVar3[1] = piVar3[1] | 0x100;
      if (piVar3[3] != 0) {
        if ((*param_2 != 0) && (iVar2 = fflush(), iVar2 != 0)) {
          return 0xffff;
        }
        *param_2 = -piVar3[3];
        iVar2 = piVar3[7];
        pbVar1 = (byte *)piVar3[6];
        piVar3[6] = piVar3[6] + 1;
        *pbVar1 = _fputc_c;
        if (((piVar3[1] & 8U) == 0) || ((_fputc_c != 10 && (_fputc_c != 0xd)))) goto LAB_1000_2909;
        iVar2 = fflush();
        goto joined_r0x000127d7;
      }
      if ((((uint16_t *)_openfd)[(char)piVar3[2]] & 0x800) != 0) {
        lseek((int)(char)piVar3[2],0,2);
      }
      if (((((_fputc_c != 10) || ((piVar3[1] & 0x40U) != 0)) ||
           (iVar2 = write((int)(char)piVar3[2],(undefined *)&_fputc_cr,1), iVar2 == 1)) &&
          (iVar2 = write((int)(char)piVar3[2],(undefined1 *)&_fputc_c,1), iVar2 == 1)) ||
         ((piVar3[1] & 0x200U) != 0)) goto LAB_1000_2909;
    }
    piVar3[1] = piVar3[1] | 0x10;
  }
  return 0xffff;
}



/* 1000:2911 */

void __cdecl16far fputchar(undefined2 param_1)

{
  fputc(param_1,0x863a,(char *)"puppetmaker" + 3);
  return;
}



/* 1000:2925 */

/* WARNING: Type propagation algorithm not settling */

uint __fputn(int *param_1,uint param_2,byte *param_3)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  undefined2 uVar8;
  
  uVar8 = (undefined2)((ulong)param_1 >> 0x10);
  piVar7 = (int *)param_1;
  uVar6 = param_2;
  if ((piVar7[1] & 8U) == 0) {
    if ((piVar7[1] & 0x40U) == 0) {
      if (piVar7[3] != 0) {
        do {
          if (uVar6 == 0) {
            return param_2;
          }
          iVar4 = *param_1;
          *param_1 = *param_1 + 1;
          if (SCARRY2(iVar4,1) == *param_1 < 0) {
            uVar5 = _fputc(*param_3,piVar7,uVar8);
          }
          else {
            iVar4 = piVar7[7];
            pbVar2 = (byte *)piVar7[6];
            piVar7[6] = piVar7[6] + 1;
            bVar1 = *param_3;
            *pbVar2 = bVar1;
            uVar5 = (uint)bVar1;
          }
          param_3 = (byte *)CONCAT22(param_3._2_2_,(byte *)param_3 + 1);
          uVar6 = uVar6 - 1;
        } while (uVar5 != 0xffff);
        return 0;
      }
      uVar6 = __write((int)(char)piVar7[2],(byte *)param_3,param_3._2_2_,param_2);
    }
    else if (piVar7[3] == 0) {
      if ((((uint16_t *)_openfd)[(char)piVar7[2]] & 0x800) != 0) {
        lseek((int)(char)piVar7[2],0,2);
      }
      uVar6 = write((int)(char)piVar7[2],(byte *)param_3,param_2);
    }
    else {
      if (param_2 <= (uint)piVar7[3]) {
        if (SCARRY2(*param_1,param_2) == (int)(*param_1 + param_2) < 0) {
          if (*param_1 == 0) {
            *param_1 = -1 - piVar7[3];
          }
          else {
            iVar4 = fflush();
            if (iVar4 != 0) {
              return 0;
            }
          }
        }
        memcpy((uint8_t *)piVar7[6],(byte *)param_3,param_2);
        *param_1 = *param_1 + param_2;
        piVar7[6] = piVar7[6] + param_2;
        return param_2;
      }
      if ((*param_1 != 0) && (iVar4 = fflush(), iVar4 != 0)) {
        return 0;
      }
      if ((((uint16_t *)_openfd)[(char)piVar7[2]] & 0x800) != 0) {
        lseek((int)(char)piVar7[2],0,2);
      }
      uVar6 = write((int)(char)piVar7[2],(byte *)param_3,param_2);
    }
    if (param_2 <= uVar6) {
      return param_2;
    }
  }
  else {
    do {
      pbVar3 = param_3;
      if (uVar6 == 0) {
        return param_2;
      }
      param_3 = (byte *)CONCAT22(param_3._2_2_,(byte *)param_3 + 1);
      iVar4 = fputc((int)(char)*pbVar3,piVar7,uVar8);
      uVar6 = uVar6 - 1;
    } while (iVar4 != -1);
  }
  return 0;
}



/* 1000:2b24 */

undefined2 __cdecl16far setvbuf(FILE *param_1,int param_2,uint8_t *param_3,int param_4,uint param_5)

{
  uint8_t *puVar1;
  FILE *pFVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  pFVar2 = (FILE *)param_1;
  if ((((FILE *)pFVar2->token == pFVar2) && (param_4 < 3)) && (param_5 < 0x8000)) {
    if ((_stdoutStarted == 0) && (pFVar2 == (FILE *)(_streams + 1))) {
      _stdoutStarted = 1;
    }
    else if ((_stdinStarted == 0) && (pFVar2 == (FILE *)_streams)) {
      _stdinStarted = 1;
    }
    if (param_1->level != 0) {
      fseek(pFVar2,uVar3,0,0,1);
    }
    if ((pFVar2->flags & 4) != 0) {
      farfree((int)pFVar2->buffer,*(undefined2 *)((int)&pFVar2->buffer + 2));
    }
    pFVar2->flags = pFVar2->flags & 0xfff3;
    pFVar2->bsize = 0;
    puVar1 = &pFVar2->hold;
    *(undefined2 *)((int)&pFVar2->buffer + 2) = uVar3;
    *(uint8_t **)&pFVar2->buffer = puVar1;
    *(undefined2 *)((int)&pFVar2->curp + 2) = uVar3;
    *(uint8_t **)&pFVar2->curp = puVar1;
    if ((param_4 != 2) && (param_5 != 0)) {
      _exitbuf.seg = 0x1000;
      _exitbuf.ofs = (int)(char *)"castle04.lbm" + 0xc;
      if (param_2 == 0 && param_3 == (uint8_t *)0x0) {
        param_2 = malloc(param_5);
        if (param_2 == 0 && puVar1 == (uint8_t *)0x0) goto LAB_1000_2b46;
        pFVar2->flags = pFVar2->flags | 4;
        param_3 = puVar1;
      }
      *(undefined2 *)((int)&pFVar2->curp + 2) = param_3;
      *(int *)&pFVar2->curp = param_2;
      *(undefined2 *)((int)&pFVar2->buffer + 2) = param_3;
      *(int *)&pFVar2->buffer = param_2;
      pFVar2->bsize = param_5;
      if (param_4 == 1) {
        pFVar2->flags = pFVar2->flags | 8;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_1000_2b46:
    uVar3 = 0xffff;
  }
  return uVar3;
}



/* 1000:2c3f */

uint16_t sprintf_strputn(int *param_1,uint16_t param_2,uint8_t *param_3)

{
  memcpy((uint8_t *)*param_1,param_3,param_2);
  *param_1 = *param_1 + param_2;
  *(undefined1 *)*param_1 = 0;
  return param_2;
}



/* 1000:2c7f */

void __cdecl16far _sprintf(undefined1 *param_1,undefined2 param_2,undefined2 param_3)

{
  undefined2 unaff_SS;
  
  *param_1 = 0;
  __vprinter(&stack0x000c,param_2,param_3,&param_1,unaff_SS,(char *)"anim\\2fi1m.lbm" + 0xe);
  return;
}



/* 1000:2ca1 */

int __cdecl16far vsprintf(char *buf,char *fmt,undefined2 param_3)

{
  int iVar1;
  undefined2 unaff_SS;
  undefined2 in_stack_00000006;
  undefined2 in_stack_0000000a;
  
  *_buf = '\0';
  iVar1 = __vprinter(param_3,fmt,in_stack_0000000a,&buf,unaff_SS,(char *)"anim\\2fi1m.lbm" + 0xe);
  return iVar1;
}



/* 1000:2cc2 */

/* Basically strcat with far operands */

char * __cdecl16far strcat(char *dst,char *src)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined2 in_stack_00000006;
  undefined2 in_stack_0000000a;
  
  iVar3 = -1;
  pcVar6 = dst;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar1 = pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar1 != '\0');
  uVar4 = 0xffff;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar1 = src;
    src = src + 1;
  } while (*pcVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = src + -uVar4;
  pcVar8 = pcVar6 + -1;
  if (((uint)pcVar7 & 1) != 0) {
    pcVar1 = pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar6[-1] = *pcVar1;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar6;
  }
  for (uVar5 = uVar4 >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
    pcVar2 = pcVar8;
    pcVar8 = pcVar8 + 2;
    pcVar1 = pcVar7;
    pcVar7 = pcVar7 + 2;
    *(undefined2 *)pcVar2 = *(undefined2 *)pcVar1;
  }
  if ((uVar4 & 1) != 0) {
    *pcVar8 = *pcVar7;
  }
  return (char *)CONCAT22(in_stack_00000006,dst);
}



/* 1000:2d01 */

int __cdecl16far strcmp(char *a,char *b)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  undefined2 in_stack_00000006;
  undefined2 in_stack_0000000a;
  
  uVar3 = 0xffff;
  pcVar4 = b;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar1 = pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  uVar3 = ~uVar3;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar2 = b;
    b = b + 1;
    pcVar1 = a;
    a = a + 1;
  } while (*pcVar1 == *pcVar2);
  return (uint)(byte)a[-1] - (uint)(byte)b[-1];
}



/* 1000:2d31 */

char * __cdecl16far strcpy(char *dst,char *src)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  undefined2 in_stack_00000006;
  undefined2 in_stack_0000000a;
  
  uVar3 = 0xffff;
  pcVar4 = src;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar1 = pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  pcVar4 = dst;
  for (uVar3 = ~uVar3; uVar3 != 0; uVar3 = uVar3 - 1) {
    pcVar2 = pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar1 = src;
    src = src + 1;
    *pcVar2 = *pcVar1;
  }
  return dst;
}



/* 1000:2d5a */

int __cdecl16far _fstricmp(char *str1,char *str2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  undefined2 in_stack_00000006;
  undefined2 in_stack_0000000a;
  
  do {
    do {
      pbVar1 = (byte *)str1;
      str1 = str1 + 1;
      bVar2 = *pbVar1;
      bVar3 = *str2;
      uVar5 = (uint)bVar3;
      uVar4 = (uint)bVar2;
      if (bVar2 == 0) goto LAB_1000_2d93;
      pbVar1 = (byte *)str2;
      str2 = str2 + 1;
    } while (bVar2 == *pbVar1);
    if ((0x60 < bVar2) && (bVar2 < 0x7b)) {
      uVar4 = (uint)(byte)(bVar2 - 0x20);
    }
    if ((0x60 < bVar3) && (bVar3 < 0x7b)) {
      uVar5 = (uint)(byte)(bVar3 - 0x20);
    }
  } while ((char)uVar4 == (char)uVar5);
LAB_1000_2d93:
  return uVar4 - uVar5;
}



/* 1000:2d9b */

size_t __cdecl16far strlen(char *str)

{
  char *pcVar1;
  size_t sVar2;
  uint uVar3;
  int in_stack_00000006;
  
  sVar2 = 0;
  if ((in_stack_00000006 != 0) || (str != (char *)0x0)) {
    uVar3 = 0xffff;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar1 = str;
      str = str + 1;
    } while (*pcVar1 != '\0');
    sVar2 = ~uVar3 - 1;
  }
  return sVar2;
}



/* 1000:2dba */

char * __cdecl16far __fstrncpy(char *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  
  uVar6 = (undefined2)((ulong)param_2 >> 0x10);
  pcVar4 = (char *)param_2;
  iVar3 = param_3;
  pcVar5 = pcVar4;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar1 = pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (*pcVar1 != '\0');
  uVar7 = (undefined2)((ulong)param_1 >> 0x10);
  pcVar5 = (char *)param_1;
  for (param_3 = param_3 - iVar3; param_3 != 0; param_3 = param_3 + -1) {
    pcVar2 = pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar1 = pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar2 = *pcVar1;
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar1 = pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar1 = '\0';
  }
  return (char *)param_1;
}



/* 1000:2deb */

char * __cdecl16far _fstrstr(char *param_1,char *param_2)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  undefined2 in_stack_00000006;
  undefined2 in_stack_0000000a;
  
  if (*_param_2 != '\0') {
    uVar2 = 0xffff;
    pcVar5 = param_1;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar1 = pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar1 != '\0');
    uVar2 = ~uVar2;
    iVar3 = -1;
    pcVar5 = param_2;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar1 = pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar1 != '\0');
    bVar7 = iVar3 + 1U == 0;
    uVar4 = ~(iVar3 + 1U);
    do {
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar1 = param_1;
        param_1 = param_1 + 1;
        bVar7 = *param_2 == *pcVar1;
      } while (!bVar7);
      if ((!bVar7) || (uVar2 < uVar4)) {
        param_1 = (char *)((int)(undefined4 *)&_DATA + 1);
        break;
      }
      if (uVar4 == 0) break;
      iVar3 = uVar4 - 1;
      bVar7 = iVar3 == 0;
      pcVar6 = param_1;
      pcVar5 = param_2;
      do {
        pcVar5 = pcVar5 + 1;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar1 = pcVar6;
        pcVar6 = pcVar6 + 1;
        bVar7 = *pcVar5 == *pcVar1;
      } while (bVar7);
    } while (!bVar7);
    param_1 = param_1 + -1;
  }
  return param_1;
}



/* 1000:2e59 */

uint16_t __cdecl16far __write(uint param_1,char *param_2,undefined2 param_3,uint16_t param_4)

{
  char *pcVar1;
  uint uVar2;
  char *pcVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  undefined2 unaff_SS;
  char local_90 [130];
  undefined4 uStack_e;
  char cStack_9;
  uint16_t uStack_8;
  char *pcStack_6;
  undefined2 uVar6;
  
  if (param_1 < _nfile) {
    if (param_4 + 1 < 2) {
      uVar4 = 0;
    }
    else {
      if ((((uint16_t *)_openfd)[param_1] & 0x800) != 0) {
        lseek(param_1,0,2);
      }
      if ((((uint16_t *)_openfd)[param_1] & 0x4000) == 0) {
        uVar4 = write(param_1,param_2,param_4);
      }
      else {
        ((uint16_t *)_openfd)[param_1] = ((uint16_t *)_openfd)[param_1] & 0xfdff;
        uStack_e = (char *)CONCAT22(param_3,param_2);
        uStack_8 = param_4;
        do {
          _pcStack_6 = (char *)CONCAT22(unaff_SS,local_90);
          do {
            pcVar3 = uStack_e;
            if (uStack_8 == 0) {
              uVar4 = (int)pcStack_6 - (int)local_90;
              if (uVar4 == 0) {
                return param_4;
              }
              uVar5 = write(param_1,local_90,uVar4);
              if (uVar5 == uVar4) {
                return param_4;
              }
              if (uVar5 == 0xffff) goto LAB_1000_2f47;
              goto LAB_1000_2f99;
            }
            uStack_8 = uStack_8 - 1;
            uStack_e = (char *)CONCAT22(uStack_e._2_2_,(char *)uStack_e + 1);
            cStack_9 = *pcVar3;
            if (cStack_9 == '\n') {
              *_pcStack_6 = '\r';
              uVar6 = (undefined2)((ulong)_pcStack_6 >> 0x10);
              _pcStack_6 = (char *)CONCAT22(uVar6,pcStack_6 + 1);
            }
            *_pcStack_6 = cStack_9;
            pcVar1 = pcStack_6 + 1;
            uVar6 = (undefined2)((ulong)_pcStack_6 >> 0x10);
            _pcStack_6 = (char *)CONCAT22(uVar6,pcVar1);
            uVar2 = (uint)(pcVar1 < local_90);
          } while (((int)-uVar2 < 0) ||
                  ((uVar2 == 0 && ((uint)((int)pcVar1 - (int)local_90) < 0x80))));
          uVar4 = (int)pcVar1 - (int)local_90;
          uVar5 = write(param_1,local_90,uVar4);
        } while (uVar5 == uVar4);
        if (uVar5 == 0xffff) {
LAB_1000_2f47:
          uVar4 = 0xffff;
        }
        else {
          param_4 = param_4 - uStack_8;
LAB_1000_2f99:
          uVar4 = (param_4 + uVar5) - uVar4;
        }
      }
    }
  }
  else {
    uVar4 = __IOerror(6);
  }
  return uVar4;
}



/* 1000:2fa8 */

int __cdecl16far write(int handle,void *buf,uint16_t len)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  
  bVar2 = false;
  if ((((uint16_t *)_openfd)[handle] & 1) == 0) {
    pcVar4 = (char *)"puppetmaker" + 3;
    pcVar1 = (code *)swi(0x21);
    iVar3 = (*pcVar1)();
    if (!bVar2) {
      ((uint16_t *)_openfd)[handle] = ((uint16_t *)_openfd)[handle] | 0x1000;
      return iVar3;
    }
  }
  else {
    iVar3 = 5;
  }
  iVar3 = __IOerror(iVar3);
  return iVar3;
}



/* 1000:2fe4 */

void __cdecl16far _xfflush(void)

{
  int iVar1;
  FILE *pFStack_6;
  
  pFStack_6 = (FILE *)_streams;
  for (iVar1 = 4; iVar1 != 0; iVar1 = iVar1 + -1) {
    if ((pFStack_6->flags & 3) != 0) {
      fflush(pFStack_6,(char *)"puppetmaker" + 3);
    }
    pFStack_6 = pFStack_6 + 1;
  }
  return;
}


