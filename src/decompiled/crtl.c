/*
 * crtl.c - recovered from STRONG.EXE
 * memory block: 1000_TEXT_crtl
 * range: 1000:0000 - 1000:301b
 * functions: 175
 */
#include "recovered.h"


/* 1000:0000 */
void startx(void)

{
  char *pcVar1;
  uint32_t *puVar2;
  code *pcVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  undefined2 uVar9;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  int iVar10;
  undefined1 *puVar11;
  int *piVar12;
  char *pcVar13;
  char *pcVar14;
  undefined1 *puVar15;
  uint32_t *puVar16;
  undefined2 unaff_ES;
  undefined2 uVar17;
  bool bVar18;
  undefined4 uVar19;
  
  puVar11 = (undefined1 *)((int)(int *)&errno + 1);
  DGROUP_at__at_ = 0x2410;
  pcVar3 = (code *)swi(0x21);
  uVar19 = (*pcVar3)();
  uVar17 = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 40));
  iVar10 = (*(uint16_t *)((uint8_t *)&(_DATA) + 2));
  uVar9 = (undefined2)((ulong)uVar19 >> 0x10);
  *(uint16_t *)&DosVersion = SUB42(uVar19,0);   /* hand fix: write the 2 bytes of the struct */
  *(undefined2 *)&_psp = unaff_ES;
  *(undefined2 *)(byte *)&_envseg_at_ = uVar17;
  *(int *)&_heaptop.seg = iVar10;
  *(undefined2 *)(puVar11 + -2) = 0x28;
  SaveVectors();
  pcVar4 = (char *)*(undefined4 *)&_env;
  uVar17 = (undefined2)((ulong)pcVar4 >> 0x10);
  pcVar13 = (char *)pcVar4;
  uVar8 = 0x7fff;
  pcVar14 = pcVar13;
L_startx_0034:
  do {
    if (uVar8 != 0) {
      uVar8 = uVar8 - 1;
      pcVar1 = pcVar14;
      pcVar14 = pcVar14 + 1;
      if ((char)pcVar4 != *pcVar1) goto L_startx_0034;
    }
    if (uVar8 == 0) goto L_startx_007B;
    pcVar13 = pcVar13 + 1;
  } while (*pcVar14 != (char)pcVar4);
  *(int *)&_env = -(uVar8 | 0x8000);
  *(uint *)&_envSize_at_ = (int)pcVar13 * 4 + 0x10U & 0xfff0;
  if (__stklen < 0x200) {
    __stklen = 0x200;
  }
  bVar7 = 4;
  uVar8 = (__stklen >> 4) + 1;
  if (iVar10 + 0xd2a6U < uVar8) {
L_startx_007B:
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  iVar10 = (__stklen >> 4) + 0x2d5b;
  *(int *)&_heapbase.seg = iVar10;
  *(int *)&_brklvl.seg = iVar10;
  piVar12 = (int *)(puVar11 + -2);
  *(uint *)(puVar11 + -2) = uVar8;
  pcVar3 = (code *)swi(0x21);
  (*pcVar3)();
  uVar17 = DGROUP_at__at_;
  puVar15 = (undefined1 *)(*piVar12 << (bVar7 & 0x1f));
  puVar16 = (uint32_t *)&recordUpdateTick;
  __stklen = (uint16_t)puVar15;
  for (iVar10 = 0xb66; iVar10 != 0; iVar10 = iVar10 + -1) {
    puVar2 = puVar16;
    puVar16 = (uint32_t *)((int)puVar16 + 1);
    *(undefined1 *)puVar2 = 0;
  }
  if (0x14 < *(uint *)&_nfile) {
    bVar7 = ((dosver_t *)&DosVersion)->major;
    bVar18 = bVar7 < 3;
    if ((!bVar18) && ((3 < bVar7 || (bVar18 = *(byte *)&DosVersion.minor < 0x1e, !bVar18)))) {
      pcVar3 = (code *)swi(0x21);
      (*pcVar3)();
      if (!bVar18) {
        pcVar3 = (code *)swi(0x21);
        (*pcVar3)();
        if (!bVar18) {
          pcVar3 = (code *)swi(0x21);
          iVar6 = (*pcVar3)();
          if (!bVar18) {
            *(int *)&_heaptop.seg = iVar6 + 1;
            pcVar3 = (code *)swi(0x21);
            (*pcVar3)();
            if (!bVar18) {
              pcVar3 = (code *)swi(0x21);
              (*pcVar3)();
              if (!bVar18) goto L_startx_0109;
            }
          }
        }
      }
                    /* WARNING: Subroutine does not return */
      _abort();
    }
  }
L_startx_0109:
  pcVar3 = (code *)swi(0x1a);
  cVar5 = (*pcVar3)();
  *(undefined2 *)(uint32_t *)&_StartTime = extraout_DX_00;
  *(int *)((int)(uint32_t *)&_StartTime + 2) = iVar10;
  if (cVar5 != '\0') {
    bda_midnight = 1;
  }
  *(undefined2 *)(puVar15 + -2) = 0x135;
  StartExit();
  *(undefined2 *)(puVar15 + -2) = *(undefined2 *)&__C0environ_2;
  *(undefined2 *)(puVar15 + -4) = *(undefined2 *)&__C0environ;
  *(undefined2 *)(puVar15 + -6) = *(undefined2 *)&__C0argv_2;
  *(undefined2 *)(puVar15 + -8) = *(undefined2 *)&__C0argv;
  *(undefined2 *)(puVar15 + -10) = *(undefined2 *)&__C0argc;
  *(undefined2 *)(puVar15 + -0xc) = 0x1000;
  *(undefined2 *)(puVar15 + -0xe) = 0x14e;
  iVar10 = main(*(int *)(puVar15 + -0xc),*(str_t **)(puVar15 + -10),*(str_t **)(puVar15 + -8));
  *(int *)(puVar15 + -8) = iVar10;
  *(undefined2 *)(puVar15 + -10) = 0x1301;
                    /* WARNING: Subroutine does not return */
  *(undefined2 *)(puVar15 + -0xc) = 0x154;
  exit(*(int *)(puVar15 + -8));
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

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _terminate(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  ErrorDisplay();
                    /* WARNING: Subroutine does not return */
  __exit(3);
}



/* 1000:0171 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ZeroDivision(void)

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

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _abort(void)

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

uint32_t * __cdecl16far xms_init(uint32_t *__return_storage_ptr__)

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
        return (uint32_t *)(xms_handle << 10);
      }
    }
  }
  xms_handle = 0;
  return (uint32_t *)0x0;
}



/* 1000:032f */

/* [R6] touches XmsHandle, XmsSrcLo */

void __cdecl16far
xms_usesXmsHandle(int dstLo,uint16_t dstHi,uint srcLo,int srcHi,uint countLo,int countHi)

{
  bool bVar1;
  
  XmsHandle = xms_data2;
  XmsSrcLo = srcLo;
  XmsSrcHi = srcHi;
  XmsPad = 0;
  XmsDstLo = dstLo;
  XmsDstHi = dstHi;
  if ((countLo & 1) != 0) {
    XmsCmdLo = 2;
    XmsCmdHi = 0;
    (*(code *)xms_driver.ofs)(0x1000);
    bVar1 = 0xfffe < XmsSrcLo;
    XmsSrcLo = XmsSrcLo + 1;
    XmsSrcHi = XmsSrcHi + (uint)bVar1;
    XmsDstLo = XmsDstLo + 1;
    bVar1 = countLo == 0;
    countLo = countLo - 1;
    countHi = countHi - (uint)bVar1;
    if ((countHi == 0) && (countLo == 0)) {
      return;
    }
  }
  XmsCmdLo = countLo;
  XmsCmdHi = countHi;
  (*(code *)xms_driver.ofs)(0x1000);
  return;
}



/* 1000:03c2 */

/* [R6] touches XmsHandle, XmsSrcLo */

void __cdecl16far
xms_usesXmsHandle2(uint dstLo,int dstHi,int srcLo,uint16_t srcHi,uint countLo,int countHi)

{
  bool bVar1;
  
  XmsHandle = 0;
  XmsSrcLo = srcLo;
  XmsSrcHi = srcHi;
  XmsPad = xms_data2;
  XmsDstLo = dstLo;
  XmsDstHi = dstHi;
  if ((countLo & 1) != 0) {
    XmsCmdLo = 2;
    XmsCmdHi = 0;
    (*(code *)xms_driver.ofs)(0x1000);
    XmsSrcLo = XmsSrcLo + 1;
    bVar1 = 0xfffe < XmsDstLo;
    XmsDstLo = XmsDstLo + 1;
    XmsDstHi = XmsDstHi + (uint)bVar1;
    bVar1 = countLo == 0;
    countLo = countLo - 1;
    countHi = countHi - (uint)bVar1;
  }
  XmsCmdLo = countLo;
  XmsCmdHi = countHi;
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

/* [R5] only caller stshInit */

void __cdecl16far stshInit_scan(uint32_t handle)

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

uint32_t * __cdecl16far ems_init(uint32_t *__return_storage_ptr__)

{
  code *pcVar1;
  char cVar2;
  uint32_t *puVar3;
  char extraout_AH;
  undefined2 uVar4;
  char extraout_AH_00;
  char extraout_AH_01;
  int iVar5;
  uint extraout_DX;
  undefined2 extraout_DX_00;
  undefined1 in_CF;
  bool bVar6;
  
  pcVar1 = (code *)swi(0x21);
  puVar3 = (uint32_t *)(*pcVar1)();
  if (!(bool)in_CF) {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    if ((!(bool)in_CF) && (bVar6 = false, (extraout_DX & 0x80) != 0)) {
      pcVar1 = (code *)swi(0x21);
      cVar2 = (*pcVar1)();
      if ((!bVar6) && (bVar6 = false, cVar2 != '\0')) {
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)();
        if (bVar6) {
          return (uint32_t *)0x0;
        }
        pcVar1 = (code *)swi(0x67);
        (*pcVar1)();
        if (extraout_AH != '\0') {
          return (uint32_t *)0x0;
        }
        pcVar1 = (code *)swi(0x67);
        uVar4 = (*pcVar1)();
        if ((char)((uint)uVar4 >> 8) != '\0') {
          return (uint32_t *)0x0;
        }
        if ((byte)uVar4 < 0x40) {
          return (uint32_t *)0x0;
        }
        pcVar1 = (code *)swi(0x67);
        (*pcVar1)();
        if (extraout_AH_00 != '\0') {
          return (uint32_t *)0x0;
        }
        if (puVar3 == (uint32_t *)0x0) {
          return (uint32_t *)0x0;
        }
        pcVar1 = (code *)swi(0x67);
        (*pcVar1)();
        if (extraout_AH_01 != '\0') {
          return (uint32_t *)0x0;
        }
        iVar5 = 0xe;
        do {
          puVar3 = (uint32_t *)((int)puVar3 << 1);
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        EMS_Handle = extraout_DX_00;
        return puVar3;
      }
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
  }
  return (uint32_t *)0x0;
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
  int iStack000e;
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
        iStack000e = iVar3;
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
ems_memmove1(uint16_t dstOfs,uint16_t dstSeg,uint16_t srcEmsOfs,uint16_t srcEmsOfsHi,uint16_t lenLo,
            uint16_t lenHi)

{
  code *pcVar1;
  
  emms_var05b7 = 1;
  emms_var05b8 = EMS_Handle;
  emms_var05bc = (srcEmsOfsHi << 1 | (uint)((int)srcEmsOfs < 0)) << 1 |
                 (uint)((int)(srcEmsOfs << 1) < 0);
  emms_var05ba = srcEmsOfs & 0x3fff;
  emms_var05be = 0;
  emms_var05bf = 0;
  emms_var05c1 = dstOfs;
  emms_var05c3 = dstSeg;
  emms_var05b3 = lenLo;
  emms_var05b5 = lenHi;
  pcVar1 = (code *)swi(0x67);
  (*pcVar1)();
  return;
}



/* 1000:0632 */

void __cdecl16far
ems_memmove2(uint16_t dstEmsOfs,uint16_t dstEmsOfsHi,uint16_t srcOfs,uint16_t srcSeg,uint16_t lenLo,
            uint16_t lenHi)

{
  code *pcVar1;
  
  emms_var05b7 = 0;
  emms_var05b8 = 0;
  emms_var05ba = srcOfs;
  emms_var05bc = srcSeg;
  emms_var05be = 1;
  emms_var05bf = EMS_Handle;
  emms_var05c3 = (dstEmsOfsHi << 1 | (uint)((int)dstEmsOfs < 0)) << 1 |
                 (uint)((int)(dstEmsOfs << 1) < 0);
  emms_var05c1 = dstEmsOfs & 0x3fff;
  emms_var05b3 = lenLo;
  emms_var05b5 = lenHi;
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
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  uint16_t src;
  uint16_t dst;
  uint32_t dst_c;
  uint32_t src_c;
  
  r8s[0] = r8s[1] + r8s[4] + 1 + r8s[5] + (CARRY1(r8s[1],r8s[4]) || 0xfe < (byte)(r8s[1] + r8s[4]));
  src = 0x6f6;
  dst = 0x6f7;
  for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = (undefined1 *)dst;
    dst = dst - 1;
    puVar1 = (undefined1 *)src;
    src = src - 1;
    *puVar2 = *puVar1;
  }
  return r8s[0];
}



/* 1000:0730 */

void __cdecl16far srand8(uint32_t seed)

{
  uint16_t i;
  
  r8s[1] = (byte)seed ^ 0x55;
  r8s[2] = (*(uint8_t *)((uint8_t *)&(seed) + 1)) ^ 0x55;
  r8s[3] = (*(uint8_t *)((uint8_t *)&(seed) + 2)) ^ 0x55;
  r8s[4] = (*(uint8_t *)((uint8_t *)&(seed) + 3)) ^ 0x55;
  r8s[0] = 0x0;
  r8s[5] = 0x0;
  i = 200;
  do {
    rand8();
    i = i - 1;
  } while (i != 0);
  return;
}



/* 1000:0776 */

void __cdecl16far ioErrorHndlrInstall(void)

{
  uint16_t in_BX;
  uint16_t unaff_ES;
  
  swi(0x21);
  DOS_GetInterruptHandler(0x2410);
  swi(0x21);
  GSavedErrorHandler.ofs = in_BX;
  GSavedErrorHandler.seg = unaff_ES;
  DOS_SetInterruptHandler(0x24,0x7a7);
  GIOErrorCode = 0;
  GIOErrorRetryCount = 5;
  return;
}



/* 1000:07a7 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

undefined2 ioErrorHndlr(void)

{
  code *pcVar1;
  undefined1 uVar3;
  undefined2 uVar2;
  undefined2 in_stack_00000002;
  
  pcVar1 = (code *)swi(0x21);
  GIOErrorCode = (*pcVar1)(0x2410);
  uVar3 = (undefined1)((uint)in_stack_00000002 >> 8);
  if (GIOErrorCode == 0x20) {
    return CONCAT11(uVar3,3);
  }
  if ((GIOErrorRetryCount != '\0') && (GIOErrorCode == 0x37)) {
    GIOErrorRetryCount = GIOErrorRetryCount + -1;
    return CONCAT11(uVar3,1);
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
  (*pcVar1)(0x2410);
  return GIOErrorCode;
}



/* 1000:081a */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __OverlayHalt(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
                    /* WARNING: Subroutine does not return */
  __exit(4);
}



/* 1000:0837 */

void __cdecl16far __FAR_RETURN(void)

{
  return;
}



/* 1000:0838 */

bool __cdecl16far _atexit(uint16_t funcOfs,uint16_t funcSeg)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = _atexitcnt != 0x20;
  if (bVar2) {
    iVar1 = _atexitcnt * 4;
    *(uint16_t *)(iVar1 + -0x6be6) = funcSeg;
    *(uint16_t *)((undefined *)&_atexittbl + iVar1) = funcOfs;
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
  iVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    iVar2 = __IOerror(iVar2);
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
  
  pcVar1 = (code *)swi(0x21);
  bVar2 = (*pcVar1)();
  *drive = bVar2 + 1;
  return;
}



/* 1000:088f */

void __cdecl16far _dos_setdrive(uint drive,uint *ndrives)

{
  code *pcVar1;
  byte bVar2;
  uint *in_stack_00000006;
  
  pcVar1 = (code *)swi(0x21);
  bVar2 = (*pcVar1)();
  *(uint *)CONCAT22((uint *)ndrives,in_stack_00000006) = (uint)bVar2;
  return;
}



/* 1000:08a5 */

void __cdecl16far ___exit_dummy(void)

{
  return;
}



/* 1000:08a6 */

void ___exit(uint16_t status,uint16_t noTerminate,uint16_t skipCleanup)

{
  if (skipCleanup == 0) {
    while (_atexitcnt != 0) {
      _atexitcnt = _atexitcnt + -1;
      (**(code **)((undefined *)&_atexittbl + _atexitcnt * 4))(0x1000);
    }
    __cleanup();
    (*(code *)_exitbuf.ofs)(0x1000);
  }
  __restorezero();
  __checknull();
  if (noTerminate == 0) {
    if (skipCleanup == 0) {
      (*(code *)_exitfopen.ofs)(0x1000);
      (*(code *)_exitopen.ofs)(0x1000);
    }
    _terminate();
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

void __cdecl16far __exit(uint16_t status)

{
                    /* WARNING: Subroutine does not return */
  ___exit(status,0,1);
}



/* 1000:091e */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _cexit(void)

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

long * __cdecl16far LXMUL_at_(long *__return_storage_ptr__,long a,long b)

{
  int in_AX;
  int in_BX;
  
  return (long *)(in_AX * in_BX);
}



/* 1000:094f */

/* ; calls to this routine are generated by the compiler to copy
   ; one "struct" value to another */

void __cdecl16far F_SCOPY(far_t src,far_t dst)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  uint in_CX;
  uint uVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  puVar4 = (undefined2 *)src.ofs;
  puVar5 = (undefined2 *)dst.ofs;
  for (uVar3 = in_CX >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar2 = *puVar1;
  }
  for (uVar3 = (uint)((in_CX & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2 = puVar5;
    puVar5 = (undefined2 *)((int)puVar5 + 1);
    puVar1 = puVar4;
    puVar4 = (undefined2 *)((int)puVar4 + 1);
    *(undefined1 *)puVar2 = *(undefined1 *)puVar1;
  }
  return;
}



/* 1000:096b */

int __cdecl16far getcurdir(int drive,char *direc)

{
  code *pcVar1;
  int iVar2;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  iVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    iVar2 = __IOerror(iVar2);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* 1000:0988 */

int __cdecl16far getdisk(void)

{
  undefined2 unaff_SS;
  uint8_t drive;
  
  _dos_getdrive((uint *)CONCAT22(unaff_SS,&drive));
  return drive - 1;
}



/* 1000:09a2 */
int __cdecl16far setdisk(int drive)

{
  extern undefined1 _driveCount;   /* hand fix: no symbol exists for it; the value is used as a segment */
  uint *unaff_SS;
  uint8_t driveCount;
  uint *puStack_6;
  
  puStack_6 = (uint *)CONCAT22(_driveCount,unaff_SS);
  _dos_setdrive(drive + 1,puStack_6);
  return _driveCount;
}


/* 1000:09c1 */

/* WARNING: Removing unreachable block (ram,0x00010a6a) */
/* WARNING: Removing unreachable block (ram,0x00010a49) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int N_LDIV_at_(uint dividendLo,uint dividendHi,uint divisorLo)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  uint in_stack_00000008;
  
  if ((in_stack_00000008 == 0) && ((dividendHi == 0 || (divisorLo == 0)))) {
    dividendLo = (uint)(CONCAT22(dividendHi,dividendLo) / (ulong)divisorLo);
  }
  else {
    bVar6 = (int)dividendHi < 0;
    if (bVar6) {
      bVar5 = dividendLo != 0;
      dividendLo = -dividendLo;
      dividendHi = -(uint)bVar5 - dividendHi;
    }
    if ((int)in_stack_00000008 < 0) {
      bVar5 = divisorLo != 0;
      divisorLo = -divisorLo;
      in_stack_00000008 = -(uint)bVar5 - in_stack_00000008;
      bVar6 = !bVar6;
    }
    iVar2 = 0x20;
    uVar4 = 0;
    uVar3 = 0;
    do {
      bVar5 = (int)dividendLo < 0;
      dividendLo = dividendLo * 2;
      uVar1 = (ulong)CONCAT12(bVar5,dividendHi) << 1;
      dividendHi = (uint)uVar1 | (uint)bVar5;
      bVar5 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar5,uVar3) << 1;
      uVar3 = (uint)uVar1 | (uint)bVar5;
      uVar4 = uVar4 << 1 | (uint)((uVar1 & 0x10000) != 0);
      if ((in_stack_00000008 <= uVar4) && ((in_stack_00000008 < uVar4 || (divisorLo <= uVar3)))) {
        bVar5 = uVar3 < divisorLo;
        uVar3 = uVar3 - divisorLo;
        uVar4 = (uVar4 - in_stack_00000008) - (uint)bVar5;
        dividendLo = dividendLo + 1;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (bVar6) {
      dividendLo = -dividendLo;
    }
  }
  return dividendLo;
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
  
  if (((*(uint16_t *)((uint8_t *)&(b) + 2)) == 0) && (((*(uint16_t *)((uint8_t *)&(a) + 2)) == 0 || ((int)b == 0)))) {
    iVar2 = (int)((ulong)a / (b & 0xffffU));
    iVar4 = 0;
  }
  else {
    bVar8 = a < 0;
    if (bVar8) {
      a = CONCAT22(-(uint)((int)a != 0) - (*(uint16_t *)((uint8_t *)&(a) + 2)),-(int)a);
    }
    if (b < 0) {
      b = CONCAT22(-(uint)((int)b != 0) - (*(uint16_t *)((uint8_t *)&(b) + 2)),-(int)b);
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
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int N_LUDIV_at_(uint dividendLo,uint dividendHi,uint divisorLo)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint in_stack_00000008;
  
  if ((in_stack_00000008 == 0) && ((dividendHi == 0 || (divisorLo == 0)))) {
    dividendLo = (uint)(CONCAT22(dividendHi,dividendLo) / (ulong)divisorLo);
  }
  else {
    iVar2 = 0x20;
    uVar4 = 0;
    uVar3 = 0;
    do {
      bVar5 = (int)dividendLo < 0;
      dividendLo = dividendLo * 2;
      uVar1 = (ulong)CONCAT12(bVar5,dividendHi) << 1;
      dividendHi = (uint)uVar1 | (uint)bVar5;
      bVar5 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar5,uVar3) << 1;
      uVar3 = (uint)uVar1 | (uint)bVar5;
      uVar4 = uVar4 << 1 | (uint)((uVar1 & 0x10000) != 0);
      if ((in_stack_00000008 <= uVar4) && ((in_stack_00000008 < uVar4 || (divisorLo <= uVar3)))) {
        bVar5 = uVar3 < divisorLo;
        uVar3 = uVar3 - divisorLo;
        uVar4 = (uVar4 - in_stack_00000008) - (uint)bVar5;
        dividendLo = dividendLo + 1;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return dividendLo;
}



/* 1000:09cb */

/* WARNING: Removing unreachable block (ram,0x00010a6a) */
/* WARNING: Removing unreachable block (ram,0x00010a03) */
/* WARNING: Removing unreachable block (ram,0x00010a07) */
/* WARNING: Removing unreachable block (ram,0x00010a11) */
/* WARNING: Removing unreachable block (ram,0x00010a15) */
/* WARNING: Removing unreachable block (ram,0x00010a49) */
/* WARNING: Removing unreachable block (ram,0x00010a55) */

undefined4 __stdcall16far LUDIV_at_(int dividendLo,uint dividendHi,uint divisorLo,uint divisorHi)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  if ((divisorHi == 0) && ((dividendHi == 0 || (divisorLo == 0)))) {
    dividendLo = (int)(CONCAT22(dividendHi,dividendLo) / (ulong)divisorLo);
    dividendHi = 0;
  }
  else {
    iVar2 = 0x20;
    uVar4 = 0;
    uVar3 = 0;
    do {
      bVar5 = dividendLo < 0;
      dividendLo = dividendLo * 2;
      uVar1 = (ulong)CONCAT12(bVar5,dividendHi) << 1;
      dividendHi = (uint)uVar1 | (uint)bVar5;
      bVar5 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar5,uVar3) << 1;
      uVar3 = (uint)uVar1 | (uint)bVar5;
      uVar4 = uVar4 << 1 | (uint)((uVar1 & 0x10000) != 0);
      if ((divisorHi <= uVar4) && ((divisorHi < uVar4 || (divisorLo <= uVar3)))) {
        bVar5 = uVar3 < divisorLo;
        uVar3 = uVar3 - divisorLo;
        uVar4 = (uVar4 - divisorHi) - (uint)bVar5;
        dividendLo = dividendLo + 1;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return CONCAT22(dividendHi,dividendLo);
}



/* 1000:09d0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint N_LMOD_at_(uint dividendLo,uint dividendHi,uint divisorLo)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint in_stack_00000008;
  
  uVar4 = 2;
  if ((in_stack_00000008 == 0) && ((dividendHi == 0 || (divisorLo == 0)))) {
    dividendLo = (uint)(CONCAT22(dividendHi,dividendLo) % (ulong)divisorLo);
  }
  else {
    if ((int)dividendHi < 0) {
      bVar6 = dividendLo != 0;
      dividendLo = -dividendLo;
      dividendHi = -(uint)bVar6 - dividendHi;
      uVar4 = 0xe;
    }
    if ((int)in_stack_00000008 < 0) {
      bVar6 = divisorLo != 0;
      divisorLo = -divisorLo;
      in_stack_00000008 = -(uint)bVar6 - in_stack_00000008;
      uVar4 = uVar4 ^ 4;
    }
    iVar2 = 0x20;
    uVar5 = 0;
    uVar3 = 0;
    do {
      bVar6 = (int)dividendLo < 0;
      dividendLo = dividendLo * 2;
      uVar1 = (ulong)CONCAT12(bVar6,dividendHi) << 1;
      dividendHi = (uint)uVar1 | (uint)bVar6;
      bVar6 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar6,uVar3) << 1;
      uVar3 = (uint)uVar1 | (uint)bVar6;
      uVar5 = uVar5 << 1 | (uint)((uVar1 & 0x10000) != 0);
      if ((in_stack_00000008 <= uVar5) && ((in_stack_00000008 < uVar5 || (divisorLo <= uVar3)))) {
        bVar6 = uVar3 < divisorLo;
        uVar3 = uVar3 - divisorLo;
        uVar5 = (uVar5 - in_stack_00000008) - (uint)bVar6;
        dividendLo = dividendLo + 1;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if ((uVar4 & 2) != 0) {
      uVar4 = uVar4 >> 1;
      dividendLo = uVar3;
    }
    if ((uVar4 & 4) != 0) {
      dividendLo = -dividendLo;
    }
  }
  return dividendLo;
}



/* 1000:09d3 */

/* WARNING: Removing unreachable block (ram,0x00010a37) */

long __stdcall16far LMOD_at_(long dividend,long divisor)

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
  if (((*(uint16_t *)((uint8_t *)&(divisor) + 2)) == 0) && (((*(uint16_t *)((uint8_t *)&(dividend) + 2)) == 0 || ((int)divisor == 0)))) {
    uVar2 = (uint)((ulong)dividend % (divisor & 0xffffU));
    uVar5 = 0;
  }
  else {
    if (dividend < 0) {
      dividend = CONCAT22(-(uint)((int)dividend != 0) - (*(uint16_t *)((uint8_t *)&(dividend) + 2)),-(int)dividend);
      uVar7 = 0xe;
    }
    if (divisor < 0) {
      divisor = CONCAT22(-(uint)((int)divisor != 0) - (*(uint16_t *)((uint8_t *)&(divisor) + 2)),-(int)divisor);
      uVar7 = uVar7 ^ 4;
    }
    iVar4 = 0x20;
    uVar8 = 0;
    uVar6 = 0;
    do {
      iVar3 = (int)dividend;
      uVar2 = iVar3 * 2;
      uVar1 = (ulong)CONCAT12(iVar3 < 0,(int)((ulong)dividend >> 0x10)) << 1;
      uVar5 = (uint)(uVar1 | iVar3 < 0);
      bVar9 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar9,uVar6) << 1;
      uVar6 = (uint)uVar1 | (uint)bVar9;
      uVar8 = uVar8 << 1 | (uint)((uVar1 & 0x10000) != 0);
      if ((ulong)divisor <= CONCAT22(uVar8,uVar6)) {
        bVar9 = uVar6 < (uint)divisor;
        uVar6 = uVar6 - (uint)divisor;
        uVar8 = (uVar8 - (int)((ulong)divisor >> 0x10)) - (uint)bVar9;
        uVar2 = uVar2 + 1;
      }
      dividend = CONCAT22(uVar5,uVar2);
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

undefined4 __cdecl16far N_LUMOD_at_(void)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  long dividendValue;
  long divisorValue;
  
  if (((*(uint16_t *)((uint8_t *)&(divisorValue) + 2)) == 0) && (((*(uint16_t *)((uint8_t *)&(dividendValue) + 2)) == 0 || ((uint)divisorValue == 0)))) {
    uVar3 = (uint)(CONCAT22((*(uint16_t *)((uint8_t *)&(dividendValue) + 2)),(int)dividendValue) % (ulong)(uint)divisorValue);
    uVar4 = 0;
  }
  else {
    iVar2 = 0x20;
    uVar4 = 0;
    uVar3 = 0;
    do {
      bVar5 = (int)dividendValue < 0;
      (*(uint16_t *)((uint8_t *)&(dividendValue))) = (int)dividendValue * 2;
      uVar1 = (ulong)CONCAT12(bVar5,(*(uint16_t *)((uint8_t *)&(dividendValue) + 2))) << 1;
      (*(uint16_t *)((uint8_t *)&(dividendValue) + 2)) = (uint)uVar1 | (uint)bVar5;
      bVar5 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar5,uVar3) << 1;
      uVar3 = (uint)uVar1 | (uint)bVar5;
      uVar4 = uVar4 << 1 | (uint)((uVar1 & 0x10000) != 0);
      if (((*(uint16_t *)((uint8_t *)&(divisorValue) + 2)) <= uVar4) &&
         (((*(uint16_t *)((uint8_t *)&(divisorValue) + 2)) < uVar4 || ((uint)divisorValue <= uVar3)))) {
        bVar5 = uVar3 < (uint)divisorValue;
        uVar3 = uVar3 - (uint)divisorValue;
        uVar4 = (uVar4 - (*(uint16_t *)((uint8_t *)&(divisorValue) + 2))) - (uint)bVar5;
        (*(uint16_t *)((uint8_t *)&(dividendValue))) = (int)dividendValue + 1;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return CONCAT22(uVar4,uVar3);
}



/* 1000:0a6f */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* long shift left */

int N_LXLSH_at_(void)

{
  int in_AX;
  byte in_CL;
  
  if (in_CL < 0x10) {
    return in_AX << (in_CL & 0x1f);
  }
  return 0;
}



/* 1000:0a72 */

long * __cdecl16far LXLSH_at_(long *__return_storage_ptr__,long i,byte s)

{
  int in_AX;
  byte in_CL;
  
  if (in_CL < 0x10) {
    return (long *)(in_AX << (in_CL & 0x1f));
  }
  return (long *)0x0;
}



/* 1000:0a90 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* long shift right */

uint N_LXRSH_at_(void)

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

long * __cdecl16far LXRSH_at_(long *__return_storage_ptr__,long n,uint8_t cx)

{
  uint in_AX;
  byte in_CL;
  int in_DX;
  
  if (in_CL < 0x10) {
    return (long *)(in_AX >> (in_CL & 0x1f) | in_DX << (0x10 - in_CL & 0x1f));
  }
  return (long *)(in_DX >> (in_CL - 0x10 & 0x1f));
}



/* 1000:0ab0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* long shift right  */

uint N_LXURSH_at_(void)

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

uint32_t * __cdecl16far LXURSH_at_(uint32_t *__return_storage_ptr__,uint32_t val,uint8_t sh)

{
  uint in_AX;
  byte in_CL;
  uint in_DX;
  
  if (in_CL < 0x10) {
    return (uint32_t *)(in_AX >> (in_CL & 0x1f) | in_DX << (0x10 - in_CL & 0x1f));
  }
  return (uint32_t *)(in_DX >> (in_CL - 0x10 & 0x1f));
}



/* 1000:0ad1 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint N_PADD_at_(void)

{
  char in_AL;
  byte bVar1;
  undefined1 extraout_AH;
  int in_CX;
  char in_BL;
  
  if (in_CX < 0) {
    bVar1 = sub1_at__at_();
    return CONCAT11(extraout_AH,bVar1);
  }
  return (byte)(in_AL + in_BL) & 0xf;
}



/* 1000:0ad4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

far_t PADD_at_(far_t ptr_base,far_t ptr_ofs)

{
  uint in_AX;
  int in_CX;
  uint16_t in_DX;
  uint in_BX;
  far_t fVar1;
  undefined1 extraout_AH;
  
  if (in_CX < 0) {
    (*(uint8_t *)((uint8_t *)&(fVar1.ofs))) = sub1_at__at_();
    (*(uint8_t *)((uint8_t *)&(fVar1.ofs) + 1)) = extraout_AH;
    fVar1.seg = in_DX;
    return fVar1;
  }
  if (CARRY2(in_AX,in_BX)) {
    in_DX = in_DX + 0x1000;
  }
  return far_from_u32((uint32_t)(CONCAT22(CONCAT11((char)(in_DX >> 8) + (char)in_CX * '\x10',(char)in_DX) +
                          (in_AX + in_BX >> 4),in_AX + in_BX) & 0xffff000f));
}



/* 1000:0ae4 */

byte __cdecl16far add1_at__at_(void)

{
  char in_AL;
  char in_BL;
  
  return in_AL + in_BL & 0xf;
}



/* 1000:0b00 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint N_PSUB_at_(void)

{
  char in_AL;
  byte bVar1;
  undefined1 extraout_AH;
  int in_CX;
  char in_BL;
  
  if (in_CX < 0) {
    bVar1 = add1_at__at_();
    return CONCAT11(extraout_AH,bVar1);
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

undefined2 __IOerror(int dosErr)

{
  if (dosErr < 0) {
    if (dosErr == -0x23 || -dosErr < 0x23) {
      errno = -dosErr;
      _doserrno = 0xffff;
      return 0xffff;
    }
  }
  else if (dosErr < 0x59) goto ser_end;
  dosErr = 0x57;
ser_end:
  _doserrno = dosErr;
  errno = (int)((char *)_dosErrorToSV)[dosErr];
  return 0xffff;
}



/* 1000:0b92 */

uint16_t __DOSerror(uint16_t dosErr)

{
  __IOerror(dosErr);
  return dosErr;
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

char * __cdecl16near __LONGTOA(char alphaBase,char signFlag,uint16_t radix,char *buf,long value)

{
  char *pcVar1;
  byte bVar2;
  ulong uVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  char *pcVar9;
  char *pcVar10;
  undefined2 uVar11;
  undefined2 unaff_SS;
  uint8_t digits [34];
  
  uVar11 = (undefined2)((ulong)buf >> 0x10);
  pcVar9 = (char *)buf;
  pcVar10 = pcVar9;
  if ((radix < 0x25) && (1 < (byte)radix)) {
    if ((value < 0) && (signFlag != '\0')) {
      *buf = '-';
      pcVar10 = pcVar9 + 1;
      value = CONCAT22(-(uint)((int)value != 0) - (*(uint16_t *)((uint8_t *)&(value) + 2)),-(int)value);
    }
    uVar6 = (uint)value;
    pbVar8 = digits;
    if ((int)((ulong)value >> 0x10) == 0) goto L__LONGTOA_0BFF;
    do {
      uVar6 = (uint)((ulong)value >> 0x10);
      uVar5 = uVar6 / radix;
      uVar3 = (ulong)uVar6 % (ulong)radix << 0x10 | value & 0xffffU;
      uVar6 = (uint)(uVar3 / radix);
      value = CONCAT22(uVar5,uVar6);
      *pbVar8 = (byte)(uVar3 % (ulong)radix);
      pbVar8 = pbVar8 + 1;
    } while (uVar5 != 0);
    while (uVar6 != 0) {
L__LONGTOA_0BFF:
      *pbVar8 = (byte)(uVar6 % radix);
      pbVar8 = pbVar8 + 1;
      uVar6 = uVar6 / radix;
    }
    iVar7 = (int)pbVar8 - (int)digits;
    do {
      pbVar8 = pbVar8 + -1;
      bVar2 = *pbVar8;
      if (bVar2 < 10) {
        cVar4 = bVar2 + 0x30;
      }
      else {
        cVar4 = (bVar2 - 10) + alphaBase;
      }
      pcVar1 = pcVar10;
      pcVar10 = pcVar10 + 1;
      *pcVar1 = cVar4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  *pcVar10 = '\0';
  return pcVar9;
}



/* 1000:0c37 */

void __UTOA(uint16_t buf,uint16_t valueHi,uint16_t valueLo)

{
  __LONGTOA('a','\0',10,(char *)CONCAT22(valueHi,buf),(ulong)valueLo);
  return;
}



/* 1000:0c57 */

void __cdecl16far lseek(int handle,long offset,int whence)

{
  code *pcVar1;
  int dosErr;
  bool bVar2;
  
  bVar2 = false;
  ((uint16_t *)_openfd)[handle] = ((uint16_t *)_openfd)[handle] & 0xfdff;
  pcVar1 = (code *)swi(0x21);
  dosErr = (*pcVar1)();
  if (bVar2) {
    __IOerror(dosErr);
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
  iVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    iVar2 = __IOerror(iVar2);
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
  (*(uint16_t *)((uint8_t *)&(rand_Seed) + 2)) = 0;
  (*(uint16_t *)((uint8_t *)&(rand_Seed))) = s;
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
  uint uVar1;
  uint16_t i;
  
  i = 5;
  if (5 < _nfile) {
    do {
      ((uint16_t *)_openfd)[i] = 0;
      *(undefined1 *)((int)&_streams[0].fd + i * 0x14) = 0xff;
      *(int *)((int)&_streams[0].token + i * 0x14) = i * 0x14 + -0x79da;
      i = i + 1;
    } while (i < _nfile);
  }
  uVar1 = _isatty();
  if (uVar1 == 0) {
    _streams[0].flags = _streams[0].flags & 0xfdff;
  }
  setvbuf(_streams,(uint8_t *)0x0,(uint)((_streams[0].flags & 0x200) != 0));
  uVar1 = _isatty();
  if (uVar1 == 0) {
    _streams[1].flags = _streams[1].flags & 0xfdff;
  }
  if ((_streams[1].flags & 0x200) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 2;
  }
  setvbuf(_streams + 1,(uint8_t *)0x0,uVar1);
  return;
}



/* 1000:0dec */

void __cdecl16far _tell(int fd)

{
  int unaff_BP;
  
  lseek(fd,0x10000,unaff_BP);
  return;
}



/* 1000:0e04 */

uint __cdecl16far tolower(uint c)

{
  uint uVar1;
  
  if (c == 0xffff) {
    uVar1 = 0xffff;
  }
  else if ((((byte *)_ctype + 1)[c & 0xff] & 4) == 0) {
    uVar1 = c & 0xff;
  }
  else {
    uVar1 = (c & 0xff) + 0x20;
  }
  return uVar1;
}



/* 1000:0e30 */

char __cdecl16far toupper(int c)

{
  char cVar1;
  
  if (c == -1) {
    cVar1 = -1;
  }
  else {
    cVar1 = (char)c;
    if ((((byte *)_ctype + 1)[c & 0xff] & 8) != 0) {
      cVar1 = cVar1 + -0x20;
    }
  }
  return cVar1;
}



/* 1000:0e5c */

int __cdecl16far unlink(char *file)

{
  code *pcVar1;
  int iVar2;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  iVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    iVar2 = __IOerror(iVar2);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* 1000:0e74 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __vprinter_1000_0e74(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte in_DL;
  char *unaff_DI;
  undefined2 unaff_ES;
  byte in_AF;
  
  __vprinter_1000_0e7b();
  in_DL = in_DL % 0x10;
  __vprinter_1000_0e84();
  bVar2 = in_DL + 0x90;
  in_AF = 9 < (bVar2 & 0xf) | in_AF;
  bVar1 = 0x99 < bVar2 || 0x6f < in_DL;
  bVar3 = bVar2 + in_AF * '\x06' + bVar1 * '`';
  bVar2 = bVar3 + 0x40;
  bVar4 = bVar2 + bVar1;
  *unaff_DI = bVar4 + (9 < (bVar4 & 0xf) | in_AF) * '\x06' +
              (0x99 < bVar4 || (0xbf < bVar3 || CARRY1(bVar2,bVar1))) * '`';
  return;
}



/* 1000:0e7b */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __vprinter_1000_0e7b(void)

{
  bool bVar1;
  byte in_AL;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  char *unaff_DI;
  undefined2 unaff_ES;
  byte in_AF;
  
  bVar2 = in_AL % 0x10;
  __vprinter_1000_0e84();
  bVar3 = bVar2 + 0x90;
  in_AF = 9 < (bVar3 & 0xf) | in_AF;
  bVar1 = 0x99 < bVar3 || 0x6f < bVar2;
  bVar3 = bVar3 + in_AF * '\x06' + bVar1 * '`';
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

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __vprinter(void)

{
  __vprinter_func_start();
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
  char *pcVar1;   /* hand fix: the bytes are read as chars */
  undefined1 in_AL;
  int iVar2;
  int unaff_BP;
  undefined1 *unaff_DI;
  undefined2 unaff_SS;
  
  *unaff_DI = in_AL;
  pcVar1 = (char *)init_textFilename + unaff_BP;
  *pcVar1 = (unsigned short)((char)*pcVar1 + -1);
  if (*pcVar1 == (unsigned short)0x0) {
    iVar2 = (*(code *)*(undefined2 *)(unaff_BP + 0xe))
                      (*(undefined2 *)(unaff_BP + 10),*(undefined2 *)(unaff_BP + 0xc),
                       unaff_DI + (1 - (unaff_BP + -0x96)),unaff_BP + -0x96);
    if (iVar2 == 0) {
      *(undefined2 *)(unaff_BP + -0x16) = 1;
    }
    *(undefined2 *)((char *)init_textFilename + unaff_BP) = 0x50;
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
  *(undefined2 *)((char *)init_textFilename + unaff_BP) = 0x50;
  *(int *)(unaff_BP + -0x12) = *(int *)(unaff_BP + -0x12) + iVar2;
  return;
}


/* 1000:0ef0 */
undefined2 __vprinter_func_start(void)

{
    char cVar2;   /* hand fix: it holds a character, not code */
  char *pcVar3;
  char *pcVar1;   /* hand fix: the bytes are read as chars */
  uint *puVar4;
  undefined1 *puVar5;
  int *piVar6;
  char cVar7;
  uint uVar8;
  byte bVar11;
  int iVar9;
  int iVar10;
  char alphaBase;
  char cVar13;
  int iVar12;
  int unaff_BP;
  char *pcVar14;
  char *pcVar15;
  char *pcVar16;
  int *piVar17;
  undefined1 *puVar18;
  uint *puVar19;
  int *piVar20;
  undefined2 uVar21;
  int iVar22;
  int unaff_SS;
  bool bVar23;
  
  *(int *)(unaff_BP + -4) = unaff_BP + -0x96;
L__vprinter_func_start_0EF9:
  pcVar16 = (char *)*(undefined2 *)(unaff_BP + -4);
L__vprinter_func_start_0EFC:
  uVar21 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
  pcVar14 = (char *)(char *)*(undefined4 *)(unaff_BP + 6);
L__vprinter_func_start_0EFF:
  pcVar15 = pcVar14 + 1;
  cVar7 = *pcVar14;
  if (cVar7 == '\0') goto L__vprinter_func_start_12FA;
  if (cVar7 == '%') {
    *(int *)(unaff_BP + -0x10) = (int)pcVar15;
    pcVar3 = pcVar15;
    pcVar15 = pcVar14 + 2;
    cVar7 = *pcVar3;
    if (cVar7 != '%') goto code_r0x00010f23;
  }
  *pcVar16 = cVar7;
  pcVar16 = pcVar16 + 1;
  pcVar1 = (char *)init_textFilename + unaff_BP;
  cVar2 = *pcVar1;
  *pcVar1 = (unsigned short)((char)*pcVar1 + -1);
  pcVar14 = pcVar15;
  if (*pcVar1 == (unsigned short)0x0 || SBORROW1((char)cVar2,'\x01') != (char)*pcVar1 < '\0') {
    __vprinter_1000_0ebc();
  }
  goto L__vprinter_func_start_0EFF;
code_r0x00010f23:
  *(undefined2 *)(unaff_BP + -4) = (uint16_t)pcVar16;   /* hand fix: 2-byte slot */
  uVar8 = 0;
  *(undefined2 *)(unaff_BP + -0xe) = (uint16_t)0;   /* hand fix: 2-byte slot */
  *(undefined2 *)(unaff_BP + -2) = (uint16_t)0x20;   /* hand fix: 2-byte slot */
  *(undefined1 *)(unaff_BP + -0xb) = 0;
  *(undefined2 *)(unaff_BP + -8) = (uint16_t)0xffff;   /* hand fix: 2-byte slot */
  *(undefined2 *)(unaff_BP + -10) = (uint16_t)0xffff;   /* hand fix: 2-byte slot */
  do {
    if (0x5f < (byte)(cVar7 - 0x20U)) goto switchD_1000_0f5d_caseD_13;
    alphaBase = ((uint8_t *)vprinter_printCtype)[(byte)(cVar7 - 0x20U)] * '\x02';
    bVar11 = (byte)(uVar8 >> 8);
    iVar22 = unaff_SS;
    switch(((uint8_t *)vprinter_printCtype)[(byte)(cVar7 - 0x20U)]) {
    case '\0':
      if (bVar11 != 0) goto switchD_1000_0f5d_caseD_13;
      if (*(char *)(unaff_BP + -0xb) != '+') {
        *(char *)(unaff_BP + -0xb) = cVar7;
      }
      break;
    case '\x01':
      if (bVar11 != 0) goto switchD_1000_0f5d_caseD_13;
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 1;
      break;
    case '\x02':
      iVar22 = *(int *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
      if (bVar11 < 2) {
        if (iVar22 < 0) {
          iVar22 = -iVar22;
          *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 2;
        }
        *(int *)(unaff_BP + -8) = iVar22;
        uVar8 = 0x300;
      }
      else {
        if (bVar11 != 4) goto switchD_1000_0f5d_caseD_13;
        *(int *)(unaff_BP + -10) = iVar22;
        uVar8 = 0x500;
      }
      break;
    case '\x03':
      if (bVar11 != 0) goto switchD_1000_0f5d_caseD_13;
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 2;
      break;
    case '\x04':
      if (3 < bVar11) goto switchD_1000_0f5d_caseD_13;
      uVar8 = 0x400;
      *(int *)(unaff_BP + -10) = *(int *)(unaff_BP + -10) + 1;
      break;
    case '\x05':
switchD_1000_0f5d_caseD_5:
      if (bVar11 < 3) {
        uVar8 = 0x200;
        LOCK();
        iVar22 = *(int *)(unaff_BP + -8);
        *(int *)(unaff_BP + -8) = (int)(char)(cVar7 + -0x30);
        UNLOCK();
        if (-1 < iVar22) {
          *(int *)(unaff_BP + -8) = *(int *)(unaff_BP + -8) + iVar22 * 10;
        }
      }
      else {
        if (bVar11 != 4) {
switchD_1000_0f5d_caseD_13:
          pcVar16 = (char *)*(undefined2 *)(unaff_BP + -0x10);
          uVar21 = *(undefined2 *)(unaff_BP + 8);
          do {
            __vprinter_1000_0eb3();
            pcVar3 = pcVar16;
            pcVar16 = pcVar16 + 1;
          } while (*pcVar3 != '\0');
L__vprinter_func_start_12FA:
          if ((char)((char *)init_textFilename)[unaff_BP] < 'P') {
            __vprinter_1000_0ebc();
          }
          if (*(int *)(unaff_BP + -0x16) == 0) {
            uVar21 = *(undefined2 *)(unaff_BP + -0x12);
          }
          else {
            uVar21 = 0xffff;
          }
          return uVar21;
        }
        LOCK();
        iVar22 = *(int *)(unaff_BP + -10);
        *(int *)(unaff_BP + -10) = (int)(char)(cVar7 + -0x30);
        UNLOCK();
        if (iVar22 != 0) {
          *(int *)(unaff_BP + -10) = *(int *)(unaff_BP + -10) + iVar22 * 10;
        }
      }
      break;
    case '\x06':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x10;
      goto L__vprinter_func_start_0F95;
    case '\a':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x100;
    case '\b':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) & 0xffef;
      goto L__vprinter_func_start_0F95;
    case '\t':
      if (bVar11 != 0) goto switchD_1000_0f5d_caseD_5;
      if ((*(uint *)(unaff_BP + -2) & 2) == 0) {
        *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 8;
        uVar8 = 0x100;
      }
      break;
    case '\n':
      goto switchD_1000_0f5d_caseD_a;
    case '\v':
      cVar13 = '\b';
      goto L__vprinter_func_start_104A;
    case '\f':
      cVar13 = '\n';
      goto L__vprinter_func_start_104E;
    case '\r':
      alphaBase = cVar7 + -0x17;
      cVar13 = '\x10';
L__vprinter_func_start_104A:
      *(undefined1 *)(unaff_BP + -0xb) = 0;
L__vprinter_func_start_104E:
      *(char *)(unaff_BP + -5) = cVar7;
      iVar9 = 0;
      *(undefined1 *)(unaff_BP + -6) = 0;
      piVar20 = (int *)*(undefined2 *)(unaff_BP + 4);
      iVar12 = *piVar20;
      goto L__vprinter_func_start_106E;
    case '\x0e':
      *(char *)(unaff_BP + -5) = cVar7;
      *(undefined2 *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
      puVar18 = (undefined1 *)(unaff_BP + -0x46);
      iVar12 = *(int *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = iVar12 + 2;
      if ((*(uint *)(unaff_BP + -2) & 0x20) != 0) {
        *(int *)(unaff_BP + 4) = iVar12 + 4;
        __vprinter_1000_0e74();
        puVar5 = puVar18;
        puVar18 = (undefined1 *)(unaff_BP + -0x45);
        *puVar5 = 0x3a;
      }
      __vprinter_1000_0e74();
      *puVar18 = 0;
      *(undefined1 *)(unaff_BP + -6) = 0;
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) & 0xfffb;
      puVar19 = (uint *)(unaff_BP + -0x46);
      uVar8 = (int)puVar18 - (int)puVar19;
      goto L__vprinter_func_start_11AA;
    case '\x0f':
      *(undefined2 *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
      *(char *)(unaff_BP + -5) = cVar7;
      uVar8 = *(uint *)(unaff_BP + -10);
      if ((int)uVar8 < 0) {
        uVar8 = 6;
      }
      if ((*(uint *)(unaff_BP + -2) & 0x100) == 0) {
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 8;
      }
      else {
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 10;
      }
      ovr__FakRealCvt();
      puVar19 = (uint *)(unaff_BP + -0x45);
      goto L__vprinter_func_start_11AA;
    case '\x10':
      *(undefined2 *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
      *(char *)(unaff_BP + -5) = cVar7;
      uVar8 = *(uint *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
      puVar19 = (uint *)(unaff_BP + -0x45);
      *puVar19 = uVar8 & 0xff;
      uVar8 = 1;
      goto L__vprinter_func_start_11ED;
    case '\x11':
      *(undefined2 *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
      *(char *)(unaff_BP + -5) = cVar7;
      if ((*(uint *)(unaff_BP + -2) & 0x20) == 0) {
        puVar19 = *(uint **)(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
        iVar22 = 0x2410;
        bVar23 = puVar19 == (uint *)0x0;
      }
      else {
        puVar4 = (uint *)*(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        iVar22 = (int)((ulong)puVar4 >> 0x10);
        puVar19 = (uint *)puVar4;
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 4;
        bVar23 = iVar22 == 0 && puVar19 == (uint *)0x0;
      }
      if (bVar23) {
        iVar22 = 0x2410;
        puVar19 = (uint *)"(null)";
      }
      __vprinter_1000_0ea6();
      if (*(uint *)(unaff_BP + -10) < uVar8) {
        uVar8 = *(uint *)(unaff_BP + -10);
      }
      goto L__vprinter_func_start_11ED;
    case '\x12':
      *(undefined2 *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
      if ((*(uint *)(unaff_BP + -2) & 0x20) == 0) {
        piVar20 = *(int **)(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
        uVar21 = 0x2410;
      }
      else {
        piVar6 = (int *)*(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        uVar21 = (undefined2)((ulong)piVar6 >> 0x10);
        piVar20 = (int *)piVar6;
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 4;
      }
      *piVar20 = (uint)(byte)(0x50 - (char)((char *)init_textFilename)[unaff_BP]) +
                 *(int *)(unaff_BP + -0x12);
      if ((*(uint *)(unaff_BP + -2) & 0x10) != 0) {
        piVar20[1] = 0;
      }
      goto L__vprinter_func_start_0EF9;
    default:
      goto switchD_1000_0f5d_caseD_13;
    case '\x16':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) & 0xffdf;
      goto L__vprinter_func_start_0F95;
    case '\x17':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x20;
L__vprinter_func_start_0F95:
      uVar8 = 0x500;
    }
    pcVar3 = pcVar15;
    pcVar15 = pcVar15 + 1;
    cVar7 = *pcVar3;
  } while( true );
switchD_1000_0f5d_caseD_a:
  cVar13 = '\n';
  *(undefined1 *)(unaff_BP + -6) = 1;
  *(char *)(unaff_BP + -5) = cVar7;
  piVar20 = (int *)*(undefined2 *)(unaff_BP + 4);
  iVar12 = *piVar20;
  iVar9 = iVar12 >> 0xf;
L__vprinter_func_start_106E:
  piVar17 = piVar20 + 1;
  *(undefined2 *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
  if ((*(uint *)(unaff_BP + -2) & 0x10) != 0) {
    iVar9 = *piVar17;
    piVar17 = piVar20 + 2;
  }
  *(undefined2 *)(unaff_BP + 4) = (uint16_t)piVar17;   /* hand fix: 2-byte slot */
  puVar19 = (uint *)(unaff_BP + -0x45);
  if ((iVar12 == 0) && (iVar9 == 0)) {
    if (*(int *)(unaff_BP + -10) == 0) goto L__vprinter_func_start_0EF9;
  }
  else {
    *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 4;
  }
  __LONGTOA(alphaBase,*(char *)(unaff_BP + -6),(int)cVar13,(char *)CONCAT22(unaff_SS,puVar19),
            CONCAT22(iVar9,iVar12));
  iVar12 = *(int *)(unaff_BP + -10);
  if (iVar12 < 0) {
L__vprinter_func_start_11AA:
    if (((*(uint *)(unaff_BP + -2) & 8) != 0) && (iVar12 = *(int *)(unaff_BP + -8), 0 < iVar12))
    goto L__vprinter_func_start_11B8;
  }
  else {
L__vprinter_func_start_11B8:
    __vprinter_1000_0ea6();
    if ((char)*puVar19 == '-') {
      uVar8 = uVar8 - 1;
    }
    if (iVar12 - uVar8 != 0 && (int)uVar8 <= iVar12) {
      *(int *)(unaff_BP + -0xe) = iVar12 - uVar8;
    }
  }
  if ((char)*puVar19 != '-') {
    if (*(char *)(unaff_BP + -0xb) == '\0') goto L__vprinter_func_start_11EA;
    puVar19 = (uint *)((int)puVar19 + -1);
    *(char *)puVar19 = *(char *)(unaff_BP + -0xb);
  }
  if ((0 < *(int *)(unaff_BP + -0xe)) && (uVar8 = *(uint *)(unaff_BP + -10), (int)uVar8 < 0)) {
    *(int *)(unaff_BP + -0xe) = *(int *)(unaff_BP + -0xe) + -1;
  }
L__vprinter_func_start_11EA:
  __vprinter_1000_0ea6();
L__vprinter_func_start_11ED:
  pcVar16 = (char *)*(undefined2 *)(unaff_BP + -4);
  iVar12 = *(int *)(unaff_BP + -8);
  if ((*(uint *)(unaff_BP + -2) & 5) == 5) {
    cVar7 = *(char *)(unaff_BP + -5);
    if (cVar7 == 'o') {
      if (*(int *)(unaff_BP + -0xe) < 1) {
        *(undefined2 *)(unaff_BP + -0xe) = (uint16_t)1;   /* hand fix: 2-byte slot */
      }
    }
    else if ((cVar7 == 'x') || (cVar7 == 'X')) {
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x40;
      iVar12 = iVar12 + -2;
      piVar6 = (int *)(unaff_BP + -0xe);
      iVar9 = *piVar6;
      *piVar6 = *piVar6 + -2;
      if (SBORROW2(iVar9,2) != *piVar6 < 0) {
        *(undefined2 *)(unaff_BP + -0xe) = (uint16_t)0;   /* hand fix: 2-byte slot */
      }
    }
  }
  iVar9 = uVar8 + *(int *)(unaff_BP + -0xe);
  if ((*(uint *)(unaff_BP + -2) & 2) == 0) {
    for (; iVar9 < iVar12; iVar12 = iVar12 + -1) {
      __vprinter_1000_0eb3();
    }
  }
  if ((*(uint *)(unaff_BP + -2) & 0x40) != 0) {
    __vprinter_1000_0eb3();
    __vprinter_1000_0eb3();
  }
  iVar10 = *(int *)(unaff_BP + -0xe);
  if (0 < iVar10) {
    iVar9 = iVar9 - iVar10;
    iVar12 = iVar12 - iVar10;
    cVar7 = (char)*puVar19;
    if (((cVar7 == '-') || (cVar7 == ' ')) || (cVar7 == '+')) {
      puVar19 = (uint *)((int)puVar19 + 1);
      __vprinter_1000_0eb3();
      iVar9 = iVar9 + -1;
      iVar12 = iVar12 + -1;
    }
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      __vprinter_1000_0eb3();
    }
  }
  if (iVar9 != 0) {
    iVar12 = iVar12 - iVar9;
    do {
      puVar4 = puVar19;
      puVar19 = (uint *)((int)puVar19 + 1);
      *pcVar16 = (char)*puVar4;
      pcVar16 = pcVar16 + 1;
      pcVar1 = (char *)init_textFilename + unaff_BP;
      cVar2 = *pcVar1;
      *pcVar1 = (unsigned short)((char)*pcVar1 + -1);
      if (*pcVar1 == (unsigned short)0x0 || SBORROW1((char)cVar2,'\x01') != (char)*pcVar1 < '\0') {
        __vprinter_1000_0ebc();
      }
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  if (0 < iVar12) {
    do {
      __vprinter_1000_0eb3();
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  goto L__vprinter_func_start_0EFC;
}


/* 1000:134a */

undefined4 __VPTR(int row,int col)

{
  return CONCAT22((*(uint16_t *)((uint8_t *)&(_video.displayptr) + 1)),
                  ((*(uint16_t *)((uint8_t *)&(_video) + 11)) + (uint)_video.screenwidth * (row + -1) + col + -1) * 2);
}



/* 1000:136f */

uint __VRAM(int count,uint *src)

{
  uint *puVar1;
  uint *puVar2;
  byte bVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  bool bVar7;
  uint *in_stack_00000004;
  uint *in_stack_0000000a;
  
  puVar4 = (uint *)(uint)_video.snow;
  puVar6 = puVar4;
  if (count != 0) {
    bVar7 = in_stack_00000004 < (*(uint16_t *)((uint8_t *)&(src) + 2));
    if (bVar7) {
      iVar5 = count + -1;
      puVar6 = (uint *)(iVar5 * 2);
      in_stack_00000004 = in_stack_00000004 + iVar5;
      (*(uint16_t *)((uint8_t *)&(src) + 2)) = (*(uint16_t *)((uint8_t *)&(src) + 2)) + iVar5;
    }
    if (puVar4 == (uint *)0x0) {
      for (; count != 0; count = count + -1) {
        puVar2 = (*(uint16_t *)((uint8_t *)&(src) + 2));
        (*(uint16_t *)((uint8_t *)&(src) + 2)) = (*(uint16_t *)((uint8_t *)&(src) + 2)) + (uint)bVar7 * -2 + 1;
        puVar1 = in_stack_00000004;
        in_stack_00000004 = in_stack_00000004 + (uint)bVar7 * -2 + 1;
        *puVar2 = *puVar1;
      }
    }
    else {
      puVar6 = in_stack_0000000a;
      if (in_stack_0000000a == (uint *)src) {
        do {
          do {
            bVar3 = in(0x3da);
          } while ((bool)(bVar3 & 1));
          do {
            bVar3 = in(0x3da);
          } while (!(bool)(bVar3 & 1));
          puVar1 = in_stack_00000004;
          in_stack_00000004 = in_stack_00000004 + (uint)bVar7 * -2 + 1;
          puVar6 = (uint *)*puVar1;
          do {
            bVar3 = in(0x3da);
          } while ((bool)(bVar3 & 1));
          do {
            bVar3 = in(0x3da);
          } while (!(bool)(bVar3 & 1));
          puVar1 = (*(uint16_t *)((uint8_t *)&(src) + 2));
          (*(uint16_t *)((uint8_t *)&(src) + 2)) = (*(uint16_t *)((uint8_t *)&(src) + 2)) + (uint)bVar7 * -2 + 1;
          *puVar1 = (uint)puVar6;
          count = count + -1;
        } while (count != 0);
      }
      else {
        do {
          do {
            bVar3 = in(0x3da);
            puVar6 = (uint *)((uint)puVar6 & 0xff00);
          } while ((bool)(bVar3 & 1));
          do {
            bVar3 = in(0x3da);
            puVar6 = (uint *)CONCAT11((char)((uint)puVar6 >> 8),bVar3 >> 1 | bVar3 << 7);
          } while (!(bool)(bVar3 & 1));
          puVar2 = (*(uint16_t *)((uint8_t *)&(src) + 2));
          (*(uint16_t *)((uint8_t *)&(src) + 2)) = (*(uint16_t *)((uint8_t *)&(src) + 2)) + (uint)bVar7 * -2 + 1;
          puVar1 = in_stack_00000004;
          in_stack_00000004 = in_stack_00000004 + (uint)bVar7 * -2 + 1;
          *puVar2 = *puVar1;
          count = count + -1;
        } while (count != 0);
      }
    }
  }
  return (uint)puVar6;
}



/* 1000:13e9 */

void __cdecl16far clrscr(void)

{
  __scroll('\0',_video.windowy2,_video.windowx2,_video.windowy1,_video.windowx1,'\x06');
  _VideoInt();
  return;
}



/* 1000:1412 */

long * __cdecl16far coreleft(long *__return_storage_ptr__)

{
  long *plVar1;
  
  plVar1 = (long *)_farcoreleft();
  return plVar1;
}



/* 1000:1418 */

int16_t __cdecl16near _crtinit_system(char *s1,char *s2)

{
  char *pcVar1;
  char *pcVar2;
  
  do {
    pcVar2 = s2;
    pcVar1 = s1;
    if (*s1 == '\0') {
      return 1;
    }
    s1 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(s1) + 2)),(char *)s1 + 1);
    s2 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(s2) + 2)),(char *)s2 + 1);
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
  
  cVar2 = (char)((uint)in_AX >> 8);
  if (cVar2 == '\0') {
    if ((char)in_AX == '\x03') {
      pcVar1 = (code *)swi(0x10);
      cVar2 = (*pcVar1)();
      if (cVar2 != '\x1a') {
        IntFlags = IntFlags & 0xfe;
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
      IntFlags = IntFlags | 1;
      pcVar1 = (code *)swi(0x10);
      (*pcVar1)();
      return;
    }
  }
  else if (cVar2 == '\x0f') {
    pcVar1 = (code *)swi(0x10);
    cVar2 = (*pcVar1)();
    if (cVar2 != '\x03') {
      return;
    }
    egainstalled();
    return;
  }
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  return;
}



/* 1000:14d7 */

void __cdecl16near _c0crtinit(void)

{
  uint8_t in_AL;
  byte bVar1;
  
  _VideoInt();
  __crtinit(in_AL);
  bVar1 = 8;
  _VideoInt();
  _video.normattr = bVar1 & 0x7f;
  _video.attribute = bVar1 & 0x7f;
  return;
}



/* 1000:14f4 */

void __cdecl16near __crtinit(uint8_t videoMode)

{
  uint8_t uVar1;
  char cVar2;
  uint8_t uVar4;
  int16_t iVar3;
  undefined1 extraout_AH;
  
  _video.currmode = videoMode;
  uVar1 = 0xf;
  _VideoInt();
  _video.screenwidth = uVar1;
  if (videoMode != _video.currmode) {
    uVar1 = _video.currmode;
    _VideoInt();
    uVar4 = 0xf;
    _VideoInt();
    _video.currmode = uVar1;
    _video.screenwidth = uVar4;
    if ((uVar1 == 0x3) && ('\x18' < ScreenHeight)) {
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
    _video.screenheight = ScreenHeight + 0x1;
  }
  else {
    _video.screenheight = 0x19;
  }
  if (_video.currmode != 0x7) {
    iVar3 = _crtinit_system("COMPAQ",(char *)0xf000ffea);
    if (iVar3 == 0) {
      cVar2 = egainstalled();
      if (CONCAT11(extraout_AH,cVar2) == 0) {
        _video.snow = 0x1;
        goto L__crtinit_159A;
      }
    }
  }
  _video.snow = 0x0;
L__crtinit_159A:
  if (_video.currmode == 0x7) {
    (*(uint16_t *)((uint8_t *)&(_video.displayptr) + 1)) = 0xb000;
  }
  else {
    (*(uint16_t *)((uint8_t *)&(_video.displayptr) + 1)) = 0xb800;
  }
  (*(uint16_t *)((uint8_t *)&(_video) + 11)) = 0;
  _video.windowy1 = 0x0;
  _video.windowx1 = 0x0;
  _video.windowx2 = _video.screenwidth + 0xff;
  _video.windowy2 = _video.screenheight + 0xff;
  return;
}



/* 1000:15cf */

/* WARNING: Unknown calling convention */

void _FakRealCvt(void)

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

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _FakScanTod(void)

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
  uint16_t in_DX;
  uint16_t brkOfs;
  uint16_t brkSeg;
  
  if (in_DX == __farmalloc_first) {
L_malloc_FreeLastBlock_1638:
    __farmalloc_first = 0;
    malloc__last = 0;
    __farmalloc_rover = 0;
  }
  else {
    brkSeg = *(uint16_t *)((int)(undefined4 *)&_DATA + 2);
    malloc__last = brkSeg;
    if (*(int *)((int)(undefined4 *)&_DATA + 2) == 0) {
      in_DX = __farmalloc_first;
      if (brkSeg != __farmalloc_first) {
        malloc__last = *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4);
        brkOfs = 0;
        malloc_PullFreeBlock();
        goto L_malloc_FreeLastBlock_1656;
      }
      goto L_malloc_FreeLastBlock_1638;
    }
  }
  brkOfs = 0;
  brkSeg = in_DX;
L_malloc_FreeLastBlock_1656:
  __brk(brkOfs,brkSeg);
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
  *(int *)((byte *)__C0_ASM_CopyRight + 4) = iStack_2;
  if ((in_DX == __farmalloc_first) || (*(int *)((int)(undefined4 *)&_DATA + 2) != 0)) {
    malloc_InsertFreeBlock();
    iStack_2 = in_DX;
  }
  else {
    iVar2 = *(int *)0x0;
    *(int *)0x0 = *(int *)0x0 + iVar2;
    iVar2 = in_DX + iVar2;
    if (*(int *)((int)(undefined4 *)&_DATA + 2) == 0) {
      *(int *)((byte *)__C0_ASM_CopyRight + 4) = iStack_2;
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
  if (iVar2 != *(int *)((byte *)__C0_ASM_CopyRight + 2)) {
    uVar1 = *(undefined2 *)((byte *)__C0_ASM_CopyRight + 2);
    __farmalloc_rover = *(undefined2 *)(byte *)__C0_ASM_CopyRight;
    *(undefined2 *)((byte *)__C0_ASM_CopyRight + 2) = uVar1;
    *(undefined2 *)(byte *)__C0_ASM_CopyRight = __farmalloc_rover;
    return;
  }
  __farmalloc_rover = 0;
  return;
}



/* 1000:16b8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void malloc_JoinFreeBlocks(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 unaff_ES;
  
  *(int *)0x0 = *(int *)0x0 + (int)_DATA;
  *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = unaff_ES;
  uVar2 = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 2));
  uVar1 = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight)));
  if ((*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 2)) != 0x2410) {
    *(undefined2 *)((byte *)__C0_ASM_CopyRight + 2) = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 2));
    *(undefined2 *)(byte *)__C0_ASM_CopyRight = uVar1;
    uVar2 = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight)));
    __C0_ASM_CopyRight[0] = (byte)uVar1;
    __C0_ASM_CopyRight[1] = SUB21(uVar1,1);
    (*(uint8_t *)((uint8_t *)&(__farmalloc_rover))) = __C0_ASM_CopyRight[0];
    (*(uint8_t *)((uint8_t *)&(__farmalloc_rover) + 1)) = __C0_ASM_CopyRight[1];
    (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight))) = uVar2;
    return;
  }
  __farmalloc_rover = 0;
  return;
}



/* 1000:16ce */

void __cdecl16far malloc_PullFreeBlock(void)

{
  undefined2 uVar1;
  
  uVar1 = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 2));
  __farmalloc_rover = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight)));
  if ((*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 2)) != 0x2410) {
    *(undefined2 *)((byte *)__C0_ASM_CopyRight + 2) = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 2));
    *(undefined2 *)(byte *)__C0_ASM_CopyRight = __farmalloc_rover;
    return;
  }
  __farmalloc_rover = 0;
  return;
}



/* 1000:16f7 */

void __cdecl16near malloc_InsertFreeBlock(void)

{
  undefined2 uVar1;
  
  (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight))) = __farmalloc_rover;
  if (__farmalloc_rover != 0) {
    uVar1 = *(undefined2 *)((byte *)__C0_ASM_CopyRight + 2);
    *(char **)((byte *)__C0_ASM_CopyRight + 2) = (char *)0x2410;
    *(char **)(byte *)__C0_ASM_CopyRight = (char *)0x2410;
    __C0_ASM_CopyRight[2] = (byte)uVar1;
    __C0_ASM_CopyRight[3] = SUB21(uVar1,1);
    return;
  }
  __farmalloc_rover = 0x2410;
  __C0_ASM_CopyRight[0] = 0x10;
  __C0_ASM_CopyRight[1] = 0x24;
  __C0_ASM_CopyRight[2] = 0x10;
  __C0_ASM_CopyRight[3] = 0x24;
  return;
}



/* 1000:172e */

void __cdecl16far farfree(uint16_t ofs,uint16_t seg)

{
  __farmalloc_data_seg = 0x2410;
  if (seg != 0) {
    if (seg == malloc__last) {
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
  undefined2 uVar1;
  ulong uVar2;
  undefined4 uVar3;
  
  uVar2 = __sbrk(0,0);
  if ((uVar2 & 0xf) != 0) {
    __sbrk(0x10 - ((uint)uVar2 & 0xf),0);
  }
  uVar3 = __sbrk(in_AX << 4,in_AX >> 0xc);
  uVar1 = (undefined2)((ulong)uVar3 >> 0x10);
  if ((int)uVar3 != -1) {
    __farmalloc_first = uVar1;
    malloc__last = uVar1;
    *(uint *)0x0 = in_AX;
    *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = uVar1;
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
  ulong uVar3;
  undefined4 uVar4;
  
  uVar3 = __sbrk(in_AX << 4,in_AX >> 0xc);
  iVar2 = (int)(uVar3 >> 0x10);
  if ((uint)uVar3 == 0xffff) {
    return 0;
  }
  if ((uVar3 & 0xf) != 0) {
    uVar4 = __sbrk(0x10 - ((uint)uVar3 & 0xf),0);
    if ((int)uVar4 == -1) {
      return 0;
    }
    iVar2 = iVar2 + 1;
  }
  uVar1 = malloc__last;
  malloc__last = iVar2;
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
  
  (*(uint16_t *)((uint8_t *)&(_DATA))) = (int)_DATA - in_AX;
  iVar1 = in_DX + (int)_DATA;
  *(int *)0x0 = in_AX;
  *(int *)((int)(undefined4 *)&_DATA + 2) = in_DX;
  *(int *)((int)(undefined4 *)&_DATA + 2) = iVar1;
  return 4;
}



/* 1000:1838 */

/* WARNING: Removing unreachable block (ram,0x000118a1) */

undefined2 __cdecl16far malloc(uint param_1)

{
  byte *pbVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  
  __farmalloc_data_seg = 0x2410;
  uVar3 = 0;
  if (param_1 != 0) {
    uVar2 = CONCAT11((byte)(param_1 + 0x13 >> 0xc) | (0xffec < param_1) << 4,
                     (char)(param_1 + 0x13 >> 4));
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
                   *(undefined2 *)((byte *)__C0_ASM_CopyRight + 4);
              return 4;
            }
            uVar3 = malloc_AllocatePartialBlock();
            return uVar3;
          }
          pbVar1 = (byte *)__C0_ASM_CopyRight + 2;
          iVar4 = *(int *)pbVar1;
        } while (*(int *)pbVar1 != __farmalloc_rover);
      }
      uVar3 = malloc_ExtendHeap();
    }
  }
  return uVar3;
}



/* 1000:1842 */

far_t * __cdecl16far farmalloc(far_t *__return_storage_ptr__,uint32_t nbytes)

{
  byte *pbVar1;
  undefined1 *puVar2;
  uint uVar3;
  far_t *pfVar4;
  uint uVar5;
  int iVar6;
  
  __farmalloc_data_seg = 0x2410;
  if (__return_storage_ptr__ != (far_t *)0x0 || (uint)nbytes != 0) {
    puVar2 = (undefined1 *)((int)&__return_storage_ptr__[4].seg + 1);
    uVar3 = (uint)((far_t *)init_textFilename < __return_storage_ptr__);
    uVar5 = (uint)nbytes + uVar3;
    if ((CARRY2((uint)nbytes,uVar3)) || ((uVar5 & 0xfff0) != 0)) {
      __return_storage_ptr__ = (far_t *)0x0;
    }
    else {
      uVar3 = CONCAT11((byte)((uint)puVar2 >> 0xc) | (char)uVar5 * '\x10',(char)((uint)puVar2 >> 4))
      ;
      if (__farmalloc_first == 0) {
        __return_storage_ptr__ = (far_t *)malloc_CreateHeap();
      }
      else {
        iVar6 = __farmalloc_rover;
        if (__farmalloc_rover != 0) {
          do {
            if (uVar3 <= *(uint *)0x0) {
              if (*(uint *)0x0 <= uVar3) {
                malloc_PullFreeBlock();
                *(undefined2 *)((int)(undefined4 *)&_DATA + 2) =
                     *(undefined2 *)((byte *)__C0_ASM_CopyRight + 4);
                return (far_t *)__C0_ASM_CopyRight;
              }
              pfVar4 = (far_t *)malloc_AllocatePartialBlock();
              return pfVar4;
            }
            pbVar1 = (byte *)__C0_ASM_CopyRight + 2;
            iVar6 = *(int *)pbVar1;
          } while (*(int *)pbVar1 != __farmalloc_rover);
        }
        __return_storage_ptr__ = (far_t *)malloc_ExtendHeap();
      }
    }
  }
  return __return_storage_ptr__;
}



/* 1000:18bf */
far_t __cdecl16near malloc_ExpandBlock(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  byte *pbVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint16_t in_DX;
  uint uVar9;
  uint16_t in_BX;
  byte *pbVar10;
  undefined2 *puVar11;
  byte *pbVar12;
  undefined2 *puVar13;
  bool bVar14;
  far_t fVar15;
  far_t fVar16;
  uint32_t nbytes;
  uint16_t seg;
  
  nbytes = CONCAT22(in_BX,malloc_save_hi);
  fVar15.ofs = (uint16_t)farmalloc((far_t *)malloc_save_lo,nbytes);   /* hand fix: first argument is the hidden return pointer; result is the offset half */
  if (in_DX == 0) {
    fVar15.seg = 0;
    return fVar15;
  }
  seg = (uint16_t)(nbytes >> 0x10);
  uVar9 = *(int *)0x0 - 1;
  pbVar12 = (byte *)__C0_ASM_CopyRight;
  pbVar10 = (byte *)__C0_ASM_CopyRight;
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    pbVar3 = pbVar12;
    pbVar12 = pbVar12 + 2;
    pbVar1 = pbVar10;
    pbVar10 = pbVar10 + 2;
    *(undefined2 *)pbVar3 = *(undefined2 *)pbVar1;
  }
  if (uVar9 != 0) {
    iVar6 = in_DX + 1;
    iVar5 = seg + 1;
    while( true ) {
      puVar13 = (undefined2 *)0x0;
      puVar11 = (undefined2 *)0x0;
      uVar7 = uVar9;
      if (0x1000 < uVar9) {
        uVar7 = 0x1000;
      }
      for (iVar8 = uVar7 << 3; iVar8 != 0; iVar8 = iVar8 + -1) {
        puVar4 = puVar13;
        puVar13 = puVar13 + 1;
        puVar2 = puVar11;
        puVar11 = puVar11 + 1;
        *puVar4 = *puVar2;
      }
      bVar14 = uVar9 < 0x1000;
      uVar9 = uVar9 - 0x1000;
      if (bVar14 || uVar9 == 0) break;
      iVar6 = iVar6 + 0x1000;
      iVar5 = iVar5 + 0x1000;
    }
  }
  farfree(in_BX,seg);
  fVar16.seg = in_DX;
  fVar16.ofs = 4;
  return fVar16;
}


/* 1000:193b */

undefined4 __cdecl16near malloc_ShrinkBlock(void)

{
  uint16_t in_AX;
  int in_CX;
  int iVar1;
  int in_BX;
  uint16_t seg;
  
  if (in_BX != malloc__last) {
    seg = in_BX + in_AX;
    *(int *)0x0 = in_CX - in_AX;
    *(int *)((int)(undefined4 *)&_DATA + 2) = in_BX;
    *(uint16_t *)0x0 = in_AX;
    iVar1 = in_BX + in_CX;
    if (*(int *)((int)(undefined4 *)&_DATA + 2) == 0) {
      *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4) = seg;
    }
    else {
      *(uint16_t *)((int)(undefined4 *)&_DATA + 2) = seg;
    }
    farfree(in_AX,seg);
    return CONCAT22(in_BX,4);
  }
  *(uint16_t *)0x0 = in_AX;
  __brk(0,in_BX + in_AX);
  return CONCAT22(in_BX,4);
}



/* 1000:199f */
far_t * __cdecl16far _realloc(undefined2 param_1,uint16_t param_2,far_t *param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  far_t *pfVar3;
  uint unaff_DI;
  far_t *pfVar4;
  far_t fVar5;
  
  __farmalloc_data_seg = 0x2410;
  malloc_save_hi = 0;
  malloc_save_lo = (uint16_t)param_3;   /* hand fix: 2-byte slot */
  if (param_2 == 0) {
    pfVar3 = farmalloc(param_3,(ulong)unaff_DI << 0x10);
  }
  else if (param_3 == (far_t *)0x0) {
    farfree(0,param_2);
    pfVar3 = (far_t *)0x0;
  }
  else {
    puVar1 = (undefined1 *)((int)&param_3[4].seg + 1);
    uVar2 = CONCAT11((byte)((uint)puVar1 >> 0xc) | ((far_t *)init_textFilename < param_3) << 4,
                     (char)((uint)puVar1 >> 4));
    if (*(uint *)0x0 < uVar2) {
      fVar5 = malloc_ExpandBlock();
      pfVar3 = (far_t *)fVar5.ofs;
    }
    else if (*(uint *)0x0 == uVar2) {
      pfVar3 = (far_t *)__C0_ASM_CopyRight;
    }
    else {
      pfVar4 = (far_t *)malloc_ShrinkBlock();
      pfVar3 = (far_t *)pfVar4;
    }
  }
  return pfVar3;
}


/* 1000:19a6 */

uint8_t __cdecl16far farrealloc(long oldblock,long nbytes)

{
  ulong uVar1;
  uint8_t uVar2;
  uint uVar3;
  far_t *pfVar4;
  undefined2 unaff_DI;
  undefined4 uVar5;
  far_t fVar6;
  
  __farmalloc_data_seg = 0x2410;
  malloc_save_hi = (*(uint16_t *)((uint8_t *)&(nbytes) + 2));
  malloc_save_lo = (uint16_t)(nbytes);
  if ((*(uint16_t *)((uint8_t *)&(oldblock) + 2)) == 0) {
    pfVar4 = farmalloc((far_t *)nbytes,CONCAT22(unaff_DI,(*(uint16_t *)((uint8_t *)&(nbytes) + 2))));
    uVar2 = (uint8_t)pfVar4;
  }
  else {
    if (nbytes == 0) {
      farfree(0,(*(uint16_t *)((uint8_t *)&(oldblock) + 2)));
    }
    else {
      uVar1 = nbytes + 0x13;
      if ((!CARRY2((*(uint16_t *)((uint8_t *)&(nbytes) + 2)),(uint)((far_t *)init_textFilename < (far_t *)nbytes))) &&
         ((uVar1 & 0xfff00000) == 0)) {
        uVar3 = CONCAT11((byte)(uVar1 >> 8) >> 4 | (char)(uVar1 >> 0x10) * '\x10',
                         (char)((uint)uVar1 >> 4));
        if (*(uint *)0x0 < uVar3) {
          fVar6 = malloc_ExpandBlock();
          return (uint8_t)fVar6.ofs;
        }
        if (*(uint *)0x0 == uVar3) {
          __farmalloc_data_seg = 0x2410;
          return 0x4;
        }
        uVar5 = malloc_ShrinkBlock();
        return (uint8_t)uVar5;
      }
    }
    uVar2 = 0x0;
  }
  return uVar2;
}



/* 1000:1a20 */

undefined2 _brk_normalize(uint16_t brkOfs,uint16_t brkSeg)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (brkSeg - _psp) + 0x40 >> 6;
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
  _brklvl.seg = brkSeg;
  _brklvl.ofs = brkOfs;
  return 1;
}



/* 1000:1a96 */

undefined2 __cdecl16near __brk(uint16_t brkOfs,uint16_t brkSeg)

{
  int iVar1;
  undefined1 in_CF;
  undefined1 in_ZF;
  
  N_PCMP_at_();
  if (((!(bool)in_CF) && (N_PCMP_at_(), (bool)in_CF || (bool)in_ZF)) &&
     (iVar1 = _brk_normalize(brkOfs,brkSeg), iVar1 != 0)) {
    return 0;
  }
  return 0xffff;
}



/* 1000:1ad5 */

undefined4 __cdecl16near __sbrk(uint incrLo,int incrHi)

{
  uint uVar1;
  int iVar2;
  uint16_t uVar3;
  int iVar4;
  uint16_t uVar5;
  uint16_t brkSeg;
  undefined1 uVar6;
  undefined1 uVar7;
  
  iVar4 = 0;
  uVar1 = N_LXLSH_at_();
  iVar2 = uVar1 + _brklvl.ofs + incrLo;
  uVar1 = iVar4 + (uint)CARRY2(uVar1,_brklvl.ofs) + incrHi +
          (uint)CARRY2(uVar1 + _brklvl.ofs,incrLo);
  uVar6 = uVar1 < 0xf;
  uVar7 = uVar1 == 0xf;
  if ((int)uVar1 < 0xf) {
L__sbrk_1B06:
    brkSeg = _brklvl.seg;
    uVar1 = N_PADD_at_();
    N_PCMP_at_();
    if (((!(bool)uVar6) &&
        (N_PCMP_at_(), uVar5 = _brklvl.seg, uVar3 = _brklvl.ofs, (bool)uVar6 || (bool)uVar7)) &&
       (iVar2 = _brk_normalize(uVar1,brkSeg), iVar2 != 0)) goto L__sbrk_1B5F;
  }
  else if ((int)uVar1 < 0x10) {
    uVar6 = iVar2 != -1;
    uVar7 = iVar2 == -1;
    goto L__sbrk_1B06;
  }
  uVar5 = 0xffff;
  uVar3 = 0xffff;
L__sbrk_1B5F:
  return CONCAT22(uVar5,uVar3);
}



/* 1000:1b63 */

uint __cdecl16far _farcoreleft(void)

{
  uint16_t uVar1;
  undefined2 uStack_6;
  
  uVar1 = _heaptop.seg;
  uStack_6 = N_PSBP_at_();
  if ((uVar1 != 0) || (0x10 < uStack_6)) {
    uStack_6 = uStack_6 - 0x10;
  }
  return uStack_6 & 0xfff0;
}



/* 1000:1bb3 */

undefined2 __cdecl16far _gettext(int x1,int y1,int x2,int y2,int buf,uint16_t bufSeg)

{
  int iVar1;
  undefined2 uVar2;
  uint16_t width;
  undefined4 uVar3;
  uint16_t dstOfs;
  uint16_t dstSeg;
  
  iVar1 = __VALIDATEXY(y2,x2,y1,x1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    width = (x2 - x1) + 1;
    for (; y1 <= y2; y1 = y1 + 1) {
      dstOfs = buf;
      dstSeg = bufSeg;
      uVar3 = __VPTR(y1,x1);
      __SCREENIO(width,(uint16_t)uVar3,(uint16_t)((ulong)uVar3 >> 0x10),dstOfs,dstSeg);
      buf = buf + width * 2;
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 1000:1c09 */

undefined2 __cdecl16far _puttext(int x1,int y1,int x2,int y2,int buf,uint16_t bufSeg)

{
  uint16_t width;
  undefined4 uVar1;
  
  width = (x2 - x1) + 1;
  for (; y1 <= y2; y1 = y1 + 1) {
    uVar1 = __VPTR(y1,x1);
    __SCREENIO(width,buf,bufSeg,(uint16_t)uVar1,(uint16_t)((ulong)uVar1 >> 0x10));
    buf = buf + width * 2;
  }
  return 1;
}



/* 1000:1c4c */

undefined2 __cdecl16far _movetext(int x1,int y1,int x2,int y2,int dstX,int dstY)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iStack_6;
  int iStack_4;
  
  iVar1 = __VALIDATEXY(y2,x2,y1,x1);
  if ((iVar1 == 0) ||
     (iVar1 = __VALIDATEXY(dstY + (y2 - y1),dstX + (x2 - x1),dstY,dstX), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    iStack_4 = y2;
    iStack_6 = 1;
    iVar1 = y1;
    if (y1 < dstY) {
      iStack_4 = y1;
      iStack_6 = -1;
      iVar1 = y2;
    }
    for (; iStack_4 + iStack_6 != iVar1; iVar1 = iVar1 + iStack_6) {
      uVar3 = __VPTR(dstY + (iVar1 - y1),dstX);
      uVar4 = __VPTR(iVar1,x1);
      __SCREENIO((x2 - x1) + 1,(uint16_t)uVar4,(uint16_t)((ulong)uVar4 >> 0x10),(uint16_t)uVar3,
                 (uint16_t)((ulong)uVar3 >> 0x10));
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 1000:1ced */

undefined2 screenpos(uint vramOfs)

{
  char cVar1;
  
  cVar1 = (char)((vramOfs >> 1) / (uint)_video.screenwidth);
  return CONCAT11(cVar1,(char)(vramOfs >> 1) - cVar1 * _video.screenwidth);
}



/* 1000:1d25 */

void __cdecl16near moveto(uint16_t *curPos,uint16_t *nextPos)

{
  byte bVar1;
  char cVar3;
  uint16_t uVar2;
  
  uVar2 = *nextPos;
  if (uVar2 != *curPos) {
    _VideoInt();
    *curPos = uVar2;
  }
  cVar3 = (char)(uVar2 >> 8);
  bVar1 = (char)uVar2 + 1;
  uVar2 = CONCAT11(cVar3,bVar1);
  if (_video.screenwidth <= bVar1) {
    uVar2 = (uint)(byte)(cVar3 + 1) << 8;
  }
  *nextPos = uVar2;
  return;
}



/* 1000:1d59 */
void bios(int width,uint16_t *vramOfs)

{
  uint16_t *puVar1;
  uint16_t *puVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  bool bVar4;
  bool bVar5;
  undefined2 *in_stack_00000004;
  int in_stack_0000000a;
  uint8_t cursorPos;
  uint8_t vramScreenOfs;
  uint8_t srcScreenOfs;
  
  cursorPos = _wherexy();
  bVar4 = in_stack_0000000a == (*(uint16_t *)((uint8_t *)&(_video.displayptr) + 1));
  if (bVar4) {
    srcScreenOfs = screenpos((uint)(*(uint16_t *)((uint8_t *)&(vramOfs) + 2)));
  }
  bVar5 = (uint16_t *)vramOfs == (uint16_t *)(*(uint16_t *)((uint8_t *)&(_video.displayptr) + 1));
  puVar1 = vramOfs;
  if (bVar5) {
    vramScreenOfs = screenpos((uint)in_stack_00000004);
  }
  while( true ) {
    (*(uint16_t *)((uint8_t *)&(vramOfs) + 2)) = (uint16_t)(undefined2 *)((ulong)puVar1 >> 0x10);
    (*(uint16_t *)((uint8_t *)&(vramOfs))) = (uint16_t)(uint16_t *)puVar1;
    if (width == 0) break;
    if (bVar5) {
      puVar2 = (uint16_t *)&cursorPos;
      moveto((uint16_t *)CONCAT22(unaff_SS,puVar2),(uint16_t *)CONCAT22(unaff_SS,&vramScreenOfs));
      uVar3 = CONCAT11(8,(char)puVar2);
      _VideoInt();
    }
    else {
      uVar3 = *(undefined2 *)CONCAT22((uint16_t *)vramOfs,in_stack_00000004);
      in_stack_00000004 = in_stack_00000004 + 1;
    }
    if (bVar4) {
      moveto((uint16_t *)CONCAT22(unaff_SS,&cursorPos),(uint16_t *)CONCAT22(unaff_SS,&srcScreenOfs))
      ;
      _VideoInt();
      width = width + -1;
    }
    else {
      *(undefined2 *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(vramOfs) + 2))) = uVar3;
      puVar1 = (uint16_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(vramOfs) + 2)) + 1,(uint16_t *)vramOfs);
      width = width + -1;
    }
  }
  _VideoInt();
  return;
}


/* 1000:1e23 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __SCREENIO(uint16_t width,uint16_t srcOfs,uint16_t srcSeg,uint16_t dstOfs,uint16_t dstSeg)

{
  if ((_video.graphicsmode == 0x0) && (ram0x0002c9bb != 0)) {
    __VRAM(width,(uint *)CONCAT22(dstOfs,srcSeg));
  }
  else {
    bios(width,(uint16_t *)CONCAT22(dstOfs,srcSeg));
  }
  return;
}



/* 1000:1e5f */

undefined2 __VALIDATEXY(uint y2,uint x2,uint y1,uint x1)

{
  undefined2 uVar1;
  
  if ((((_video.screenwidth < x1) || (_video.screenwidth < x2)) || ((int)x2 < (int)x1)) ||
     (((_video.screenheight < y1 || (_video.screenheight < y2)) || ((int)y2 < (int)y1)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 1000:1ea2 */

void _zapline(int endCol,int startCol,uint16_t *dst)

{
  uint16_t uVar1;
  
  uVar1 = CONCAT11(_video.attribute,0x20);
  for (; startCol <= endCol; startCol = startCol + 1) {
    *dst = uVar1;
    dst = (uint16_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(dst) + 2)),(uint16_t *)dst + 1);
  }
  return;
}



/* 1000:1ec4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __scroll(uchar dir,uchar x1,uchar y1,uchar x2,uchar y2,uchar lines)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint16_t unaff_SS;
  uint16_t rowBuf [80];
  
  if (((_video.graphicsmode == 0x0) && (ram0x0002c9bb != 0)) && (dir == '\x01')) {
    bVar1 = y2 + 1;
    bVar2 = x2 + 1;
    bVar3 = y1 + 1;
    bVar4 = x1 + 1;
    if (lines == '\x06') {
      _movetext((uint)bVar1,bVar2 + 1,(uint)bVar3,(uint)bVar4,(uint)bVar1,(uint)bVar2);
      _gettext((uint)bVar1,(uint)bVar4,(uint)bVar1,(uint)bVar4,(int)rowBuf,unaff_SS);
      _zapline((uint)bVar3,(uint)bVar1,(uint16_t *)CONCAT22(unaff_SS,rowBuf));
    }
    else {
      _movetext((uint)bVar1,(uint)bVar2,(uint)bVar3,bVar4 - 1,(uint)bVar1,bVar2 + 1);
      _gettext((uint)bVar1,(uint)bVar2,(uint)bVar1,(uint)bVar2,(int)rowBuf,unaff_SS);
      _zapline((uint)bVar3,(uint)bVar1,(uint16_t *)CONCAT22(unaff_SS,rowBuf));
      bVar4 = bVar2;
    }
    _puttext((uint)bVar1,(uint)bVar4,(uint)bVar3,(uint)bVar4,(int)rowBuf,unaff_SS);
  }
  else {
    _VideoInt();
  }
  return;
}



/* 1000:2032 */
void __setargv(uint savedES)

{
  char *pcVar1;
  char *pcVar2;
  byte bVar3;
  undefined1 *puVar4;
  uint uVar6;
  int iVar7;
  uint in_BX;
  int iVar8;
  int *piVar9;
  undefined2 unaff_SI;
  char *pcVar10;
  undefined2 unaff_DI;
  char *pcVar11;
  undefined2 uVar12;
  int unaff_SS;
  undefined2 uVar13;
  bool bVar14;
  undefined1 uVar15;
  undefined2 in_stack_00000000;
  uint in_stack_00000004;
  int iVar5;
  
  __setargv_SavedES = savedES;
  __setargv_SavedReturn2 = in_stack_00000004;
  __setargv_SavedDS = 0x2410;
  pcVar10 = (char *)(_env + 2);
  uVar6 = 1;
  uVar12 = _psp;
  __setargv_SavedReturn = in_stack_00000000;
  __setargv_SavedSI = unaff_SI;
  __setargv_SavedDI = unaff_DI;
  if (2 < DosVersion.major) {
    uVar6 = 0x7f;
    in_BX = in_BX & 0xff00;
    pcVar11 = pcVar10;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar1 = pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (*pcVar1 != '\0');
    if (uVar6 == 0) goto code_r0x000120eb;
    uVar6 = uVar6 ^ 0x7f;
    uVar12 = _envseg_at_;
  }
  in_stack_00000004 = in_BX;
  puVar4 = (undefined1 *)(uVar6 + *(byte *)((int)(int *)&errno + 1) + 2 & 0xfffe);
  iVar8 = -(int)puVar4;
  pcVar11 = (char *)((int)&stack0x0004 + iVar8);
  if (puVar4 <= &stack0x0004) {
    *(undefined2 *)((int)&savedES + iVar8) = uVar12;
    uVar13 = *(undefined2 *)((int)&savedES + iVar8);
    *(int *)((int)&savedES + iVar8) = unaff_SS;
    uVar12 = *(undefined2 *)((int)&savedES + iVar8);
    *(uint *)((int)&savedES + iVar8) = uVar6;
    while (uVar6 - 1 != 0) {
      pcVar2 = pcVar11;
      pcVar11 = pcVar11 + 1;
      pcVar1 = pcVar10;
      pcVar10 = pcVar10 + 1;
      *pcVar2 = *pcVar1;
      uVar6 = uVar6 - 1;
    }
    bVar14 = false;
    *pcVar11 = '\0';
    uVar15 = uVar6 == 0;
    iVar7 = 0;
Processing:
    *(char **)(&stack0x0000 + iVar8) = (char *)0x20a8;
    iVar5 = NextChar();
    bVar3 = (byte)iVar5;
    if (bVar14 || (bool)uVar15) {
      do {
        uVar12 = __setargv_SavedDS;
        if (bVar14) {
          pcVar10 = (char *)&stack0x0004;
          iVar7 = *(int *)((int)&savedES + iVar8) + iVar7;
          *(uint *)&_argc_at_ = uVar6;
          iVar8 = uVar6 + 1;
          piVar9 = (int *)(&stack0x0004 + iVar8 * -2);
          if (&stack0x0004 < (undefined1 *)(iVar8 * 4)) goto code_r0x000120eb;
          *(undefined2 *)&_argv_at_ = (uint16_t)piVar9;   /* hand fix: 2-byte slot */
          *(int *)&_argv_at__2 = unaff_SS;
          uVar12 = __setargv_SavedDS;
          goto SetArgvX;
        }
        *(char **)(&stack0x0000 + iVar8) = (char *)0x20af;
        iVar5 = NextChar();
        bVar3 = (byte)iVar5;
      } while (!bVar14 && !(bool)uVar15);
    }
    if ((bVar3 != 0x20) && (bVar3 != 0xd)) goto code_r0x000120b9;
    goto EndArgument;
  }
code_r0x000120eb:
                    /* WARNING: Subroutine does not return */
  _abort();
code_r0x000120b9:
  bVar14 = bVar3 < 9;
  uVar15 = false;
  if (bVar3 == 9) {
EndArgument:
    bVar14 = false;
    uVar15 = true;
  }
  goto Processing;
  while( true ) {
    *piVar9 = (int)pcVar10;
    piVar9[1] = unaff_SS;
    piVar9 = piVar9 + 2;
    do {
      pcVar1 = pcVar10;
      pcVar10 = pcVar10 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0 && *pcVar1 != '\0');
    if (*pcVar1 != '\0') break;
SetArgvX:
    if (iVar7 == 0) break;
  }
  *piVar9 = 0;
  piVar9[1] = 0;
  (&savedES)[iVar8 * -2] = *(undefined2 *)&__setargv_SavedReturn2;
  *(undefined2 *)(&stack0x0000 + iVar8 * -4) = *(undefined2 *)&__setargv_SavedES;
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

uint16_t __cdecl16far _setblock(uint16_t seg,uint16_t size)

{
  code *pcVar1;
  int dosErr;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  dosErr = (*pcVar1)();
  if ((bool)in_CF) {
    __IOerror(dosErr);
  }
  else {
    size = 0xffff;
  }
  return size;
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
  uint uVar1;
  
  uVar1 = _wherexy();
  return ((uVar1 & 0xff) - (uint)_video.windowx1) + 1;
}



/* 1000:218c */

int __cdecl16far _wherey(void)

{
  uint uVar1;
  
  uVar1 = _wherexy();
  return ((uVar1 >> 8) - (uint)_video.windowy1) + 1;
}



/* 1000:219f */

uint16_t __cdecl16far _atol(char *s)

{
  ulong uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  byte *pbVar6;
  undefined2 uVar7;
  
  uVar7 = (undefined2)((ulong)s >> 0x10);
  pbVar6 = (byte *)s;
  uVar3 = 0;
  do {
    bVar5 = *pbVar6;
    pbVar6 = pbVar6 + 1;
  } while ((((byte *)_ctype + 1)[bVar5] & 1) != 0);
  bVar2 = false;
  if (bVar5 != 0x2b) {
    if (bVar5 != 0x2d) goto L__atol_21D0;
    bVar2 = true;
  }
  do {
    bVar5 = *pbVar6;
    pbVar6 = pbVar6 + 1;
L__atol_21D0:
    if ((0x39 < bVar5) || (bVar5 < 0x30)) goto L__atol_2204;
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
L__atol_2204:
  if (bVar2) {
    uVar3 = -uVar3;
  }
  return uVar3;
}



/* 1000:2214 */

int16_t __cdecl16far _atoi(char *s)

{
  uint16_t uVar1;
  
  uVar1 = _atol(s);
  return uVar1;
}



/* 1000:2225 */

int __cdecl16far close(int handle)

{
  code *pcVar1;
  int iVar2;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  iVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    iVar2 = __IOerror(iVar2);
  }
  else {
    ((uint16_t *)_openfd)[handle] = 0;
    iVar2 = 0;
  }
  return iVar2;
}



/* 1000:2243 */

int CreateFile(uint16_t mode)

{
  code *pcVar1;
  int dosErr;
  undefined2 unaff_BP;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  dosErr = (*pcVar1)();
  if ((bool)in_CF) {
    dosErr = __IOerror(dosErr);
  }
  else {
    ((uint16_t *)_openfd)[dosErr] = mode;
  }
  return dosErr;
}



/* 1000:2270 */

int __cdecl16far _creat(char *path,int mode)

{
  int iVar1;
  
  iVar1 = CreateFile(0x8004);
  return iVar1;
}



/* 1000:2288 */

int16_t __cdecl16far _creattemp(char *path,uint16_t attrib)

{
  int iVar1;
  
  iVar1 = CreateFile(_fmode | 4);
  return iVar1;
}



/* 1000:22a3 */

int16_t __cdecl16far _creatnew(char *path,uint16_t attrib)

{
  int iVar1;
  
  iVar1 = CreateFile(_fmode | 4);
  return iVar1;
}



/* 1000:22be */

undefined2 __cdecl16far fflush(int *stream)

{
  int iVar1;
  char *pcVar2;
  uint fd;
  uint16_t uVar3;
  uint16_t uVar4;
  uint16_t unaff_BP;
  uint16_t unaff_SI;
  
  if (stream == (int *)0x0) {
    flushall();
  }
  else {
    if ((int *)((int *)stream)[9] != (int *)stream) {
      return 0xffff;
    }
    if (*stream < 0) {
      uVar3 = ((int *)stream)[3] + *stream + 1;
      *stream = *stream - uVar3;
      pcVar2 = (char *)((int *)stream)[5];
      fd = ((int *)stream)[4];
      ((int *)stream)[7] = (int)pcVar2;
      ((int *)stream)[6] = fd;
      uVar4 = __write(fd,(char *)CONCAT22(uVar3,pcVar2),unaff_SI,unaff_BP);
      if ((uVar4 != uVar3) && ((((int *)stream)[1] & 0x200U) == 0)) {
        ((int *)stream)[1] = ((int *)stream)[1] | 0x10;
        return 0xffff;
      }
    }
    else if (((((int *)stream)[1] & 8U) != 0) ||
            ((((int *)stream)[7] == (*(uint16_t *)((uint8_t *)&(stream) + 2)) && (((int *)stream)[6] == (int)(int *)stream + 5)))
            ) {
      *stream = 0;
      if ((((int *)stream)[7] == (*(uint16_t *)((uint8_t *)&(stream) + 2))) && (((int *)stream)[6] == (int)(int *)stream + 5)) {
        iVar1 = ((int *)stream)[4];
        ((int *)stream)[7] = ((int *)stream)[5];
        ((int *)stream)[6] = iVar1;
      }
    }
  }
  return 0;
}



/* 1000:238b */

long * __cdecl16far filelength(long *__return_storage_ptr__,int hande)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  bool bVar4;
  long *plVar5;
  
  bVar4 = false;
  pcVar1 = (code *)swi(0x21);
  plVar5 = (long *)(*pcVar1)();
  plVar3 = (long *)plVar5;
  if (!bVar4) {
    bVar4 = false;
    pcVar1 = (code *)swi(0x21);
    plVar2 = (long *)(*pcVar1)((int)((ulong)plVar5 >> 0x10));
    plVar3 = plVar2;
    if (!bVar4) {
      pcVar1 = (code *)swi(0x21);
      plVar3 = (long *)(*pcVar1)();
      if (!bVar4) {
        return plVar2;
      }
    }
  }
  plVar3 = (long *)__IOerror((int)plVar3);
  return plVar3;
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
      fflush((int *)CONCAT22(0x2410,pFStack_6));
      iVar2 = iVar2 + 1;
    }
    pFStack_6 = pFStack_6 + 1;
    uVar1 = uVar1 - 1;
  }
  return iVar2;
}



/* 1000:240e */
int fseek_Displacement(uint *stream)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  undefined2 uVar8;
  undefined1 *uStack_6;   /* hand fix: dereferenced as *uStack_6 */
  
  uVar8 = (undefined2)((ulong)stream >> 0x10);
  puVar6 = (uint *)stream;
  if ((int)*stream < 0) {
    iVar2 = puVar6[3] + *stream + 1;
  }
  else {
    uVar5 = (int)*stream >> 0xf;
    iVar2 = (*stream ^ uVar5) - uVar5;
  }
  iVar7 = iVar2;
  if ((puVar6[1] & 0x40) == 0) {
    uStack_6 = (char *)CONCAT22(puVar6[7],(char *)puVar6[6]);
    iVar3 = iVar2;
    if ((int)*stream < 0) {
      while (iVar3 = iVar2 + -1, iVar2 != 0) {
        uStack_6 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(char *)uStack_6 + -1);
        iVar2 = iVar3;
        if (*uStack_6 == '\n') {
          iVar7 = iVar7 + 1;
        }
      }
    }
    else {
      while (pcVar1 = uStack_6, iVar4 = iVar3 + -1, iVar7 = iVar2, iVar3 != 0) {
        uStack_6 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(char *)uStack_6 + 1);
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

int16_t __cdecl16far fseek(uint16_t *stream,uint16_t offsetLo,uint16_t offsetHi,uint16_t whence)

{
  int iVar1;
  int16_t iVar2;
  uint uVar3;
  uint16_t uVar4;
  int unaff_SI;
  
  iVar1 = fflush((int *)stream);
  if (iVar1 == 0) {
    if ((whence == 1) && (0 < (int)*stream)) {
      uVar3 = fseek_Displacement(stream);
      offsetHi = (offsetHi - ((int)uVar3 >> 0xf)) - (uint)(offsetLo < uVar3);
    }
    ((uint16_t *)stream)[1] = ((uint16_t *)stream)[1] & 0xfe5f;
    *stream = 0;
    uVar4 = ((uint16_t *)stream)[4];
    ((uint16_t *)stream)[7] = ((uint16_t *)stream)[5];
    ((uint16_t *)stream)[6] = uVar4;
    iVar1 = (int)(char)((uint16_t *)stream)[2];
    lseek(iVar1,CONCAT22(whence,offsetHi),unaff_SI);
    if ((uVar4 == 0xffff) && (iVar1 == -1)) {
      iVar2 = -1;
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}



/* 1000:2510 */

int __cdecl16far ftell(int *stream)

{
  int iVar1;
  int in_DX;
  int iStack_6;
  
  iStack_6 = (int)(char)((int *)stream)[2];
  _tell(iStack_6);
  if ((in_DX != -1) || (iStack_6 != -1)) {
    if (*stream < 0) {
      iVar1 = fseek_Displacement((uint *)stream);
      iStack_6 = iStack_6 + iVar1;
    }
    else {
      iVar1 = fseek_Displacement((uint *)stream);
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
  char *in_DX;
  undefined2 unaff_SI;
  char *unaff_SS;
  char *in_stack_00000004;
  char cwd [68];
  
  iVar1 = getdisk();
  cwd[0] = (char)iVar1 + 'A';
  cwd[1] = ':';
  cwd[2] = '\\';
  iVar1 = getcurdir(0,(char *)CONCAT22(unaff_SI,unaff_SS));
  if (iVar1 != -1) {
    sVar2 = strlen((char *)CONCAT22(unaff_SS,cwd));
    if (sVar2 < (*(uint16_t *)((uint8_t *)&(__buf) + 2))) {
      if (in_stack_00000004 == (char *)0x0 && (char *)__buf == (char *)0x0) {
        in_stack_00000004 = (char *)malloc((*(uint16_t *)((uint8_t *)&(__buf) + 2)));
        __buf = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(__buf) + 2)),in_DX);
        if (in_stack_00000004 == (char *)0x0 && in_DX == (char *)0x0) {
          errno = 8;
          return (char *)0x0;
        }
      }
      strcpy((char *)CONCAT22((char *)__buf,in_stack_00000004),(char *)CONCAT22(unaff_SS,cwd));
      return in_stack_00000004;
    }
    errno = 0x22;
  }
  return (char *)0x0;
}



/* 1000:25f6 */

int16_t __cdecl16far memcmp(char *s1,char *s2,uint16_t n)

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
  if (n != 0) {
    uVar8 = (undefined2)((ulong)s1 >> 0x10);
    pcVar5 = (char *)s1;
    uVar7 = (undefined2)((ulong)s2 >> 0x10);
    pcVar6 = (char *)s2;
    do {
      if (n == 0) break;
      n = n - 1;
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

void * __cdecl16far memcpy(char *dst,char *src,word size)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  
  uVar6 = (undefined2)((ulong)dst >> 0x10);
  uVar7 = (undefined2)((ulong)src >> 0x10);
  pcVar4 = (char *)src;
  pcVar5 = (char *)dst;
  for (uVar3 = size >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
    pcVar2 = pcVar5;
    pcVar5 = pcVar5 + 2;
    pcVar1 = pcVar4;
    pcVar4 = pcVar4 + 2;
    *(undefined2 *)pcVar2 = *(undefined2 *)pcVar1;
  }
  if ((size & 1) != 0) {
    *pcVar5 = *pcVar4;
  }
  return (char *)dst;
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
  void *in_stack_00000004;
  
  _fsetmem((void *)CONCAT22((void *)ptr,in_stack_00000004),v,
           CONCAT11((char)((uint)in_AX >> 8),(*(uint8_t *)((uint8_t *)&(ptr) + 2))));
  return in_stack_00000004;
}



/* 1000:2685 */

void * __cdecl16far __fmovmem(char *src,char *dst,word count)

{
  char *pcVar1;
  char *pcVar2;
  void *pvVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  byte in_CF;
  
  N_PCMP_at_();
  pvVar3 = (void *)(uint)in_CF;
  uVar8 = (undefined2)((ulong)src >> 0x10);
  pcVar5 = (char *)src;
  uVar7 = (undefined2)((ulong)dst >> 0x10);
  pcVar6 = (char *)dst;
  if (pvVar3 != (void *)0x0) {
    pcVar5 = pcVar5 + (count - 1);
    pcVar6 = pcVar6 + (count - 1);
  }
  if (((uint)pcVar6 & 1) != 0) {
    if (count == 0) {
      return pvVar3;
    }
    pcVar2 = pcVar6;
    pcVar6 = pcVar6 + (uint)in_CF * -2 + 1;
    pcVar1 = pcVar5;
    pcVar5 = pcVar5 + (uint)in_CF * -2 + 1;
    *pcVar2 = *pcVar1;
    count = count - 1;
  }
  pcVar5 = pcVar5 + -(int)pvVar3;
  pcVar6 = pcVar6 + -(int)pvVar3;
  for (uVar4 = count >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
    pcVar2 = pcVar6;
    pcVar6 = pcVar6 + ((uint)in_CF * -2 + 1) * 2;
    pcVar1 = pcVar5;
    pcVar5 = pcVar5 + ((uint)in_CF * -2 + 1) * 2;
    *(undefined2 *)pcVar2 = *(undefined2 *)pcVar1;
  }
  if ((count & 1) != 0) {
    pcVar6[(int)pvVar3] = pcVar5[(int)pvVar3];
  }
  return pvVar3;
}



/* 1000:26d7 */

void * __cdecl16far _fmemmove(char *dst,char *src,word count)

{
  __fmovmem(src,dst,count);
  return (char *)dst;
}



/* 1000:26f8 */

int __cdecl16far _open(char *pathname,int access)

{
  code *pcVar1;
  int dosErr;
  undefined2 unaff_BP;
  bool bVar2;
  
  bVar2 = false;
  pcVar1 = (code *)swi(0x21);
  dosErr = (*pcVar1)();
  if (bVar2) {
    dosErr = __IOerror(dosErr);
  }
  else {
    ((uint16_t *)_openfd)[dosErr] = access & 0xb8ffU | 0x8000;
  }
  return dosErr;
}



/* 1000:2747 */

void __cdecl16far printf(char *fmt)

{
  __vprinter();
  return;
}



/* 1000:2762 */

void __cdecl16far _fputc(char c,int *stream)

{
  undefined2 unaff_BP;
  int *in_stack_00000006;
  
  *(int *)CONCAT22((int *)stream,in_stack_00000006) =
       *(int *)CONCAT22((int *)stream,in_stack_00000006) + -1;
  fputc(c,(int *)CONCAT22(unaff_BP,(int *)stream));
  return;
}



/* 1000:277e */

/* WARNING: Type propagation algorithm not settling */

uint __cdecl16far fputc(byte ch,int *stream)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  int unaff_SI;
  int *in_stack_00000006;
  
  _fputc_c = ch;
  piVar2 = (int *)CONCAT22((int *)stream,in_stack_00000006);
  if (*piVar2 < -1) {
    *piVar2 = *piVar2 + 1;
    iVar3 = in_stack_00000006[7];
    pbVar1 = (byte *)in_stack_00000006[6];
    in_stack_00000006[6] = in_stack_00000006[6] + 1;
    *pbVar1 = _fputc_c;
    if (((in_stack_00000006[1] & 8U) == 0) || ((_fputc_c != 10 && (_fputc_c != 0xd))))
    goto L_fputc_2909;
    iVar3 = fflush((int *)CONCAT22((int *)stream,in_stack_00000006));
joined_r0x000127d7:
    if (iVar3 == 0) {
L_fputc_2909:
      return (uint)_fputc_c;
    }
  }
  else {
    if (((in_stack_00000006[1] & 0x90U) == 0) && ((in_stack_00000006[1] & 2U) != 0)) {
      in_stack_00000006[1] = in_stack_00000006[1] | 0x100;
      if (in_stack_00000006[3] != 0) {
        if ((*(int *)CONCAT22((int *)stream,in_stack_00000006) != 0) &&
           (iVar3 = fflush((int *)CONCAT22((int *)stream,in_stack_00000006)), iVar3 != 0)) {
          return 0xffff;
        }
        *(int *)CONCAT22((int *)stream,in_stack_00000006) = -in_stack_00000006[3];
        iVar3 = in_stack_00000006[7];
        pbVar1 = (byte *)in_stack_00000006[6];
        in_stack_00000006[6] = in_stack_00000006[6] + 1;
        *pbVar1 = _fputc_c;
        if (((in_stack_00000006[1] & 8U) == 0) || ((_fputc_c != 10 && (_fputc_c != 0xd))))
        goto L_fputc_2909;
        iVar3 = fflush((int *)CONCAT22((int *)stream,in_stack_00000006));
        goto joined_r0x000127d7;
      }
      if ((((uint16_t *)_openfd)[(char)in_stack_00000006[2]] & 0x800) != 0) {
        lseek((int)(char)in_stack_00000006[2],0x20000,unaff_SI);
      }
      if (((((_fputc_c != 10) || ((in_stack_00000006[1] & 0x40U) != 0)) ||
           (iVar3 = write((int)(char)in_stack_00000006[2],&_fputc_cr,1), iVar3 == 1)) &&
          (iVar3 = write((int)(char)in_stack_00000006[2],&_fputc_c,1), iVar3 == 1)) ||
         ((in_stack_00000006[1] & 0x200U) != 0)) goto L_fputc_2909;
    }
    in_stack_00000006[1] = in_stack_00000006[1] | 0x10;
  }
  return 0xffff;
}



/* 1000:2911 */

void __cdecl16far fputchar(uint16_t c)

{
  undefined2 unaff_BP;
  
  fputc((byte)c,(int *)CONCAT22(unaff_BP,(char *)0x2410));
  return;
}



/* 1000:2925 */

/* WARNING: Type propagation algorithm not settling */

uint16_t __cdecl16near __fputn(far_t stream,uint16_t count,far_t buf)

{
  byte bVar1;
  undefined2 uVar2;
  byte *pbVar3;
  far_t fVar4;
  uint uVar5;
  int iVar6;
  uint16_t uVar7;
  uint16_t unaff_SI;
  uint16_t unaff_DI;
  uint16_t uVar8;
  int *piVar9;
  
  piVar9 = (int *)stream.seg;
  uVar7 = stream.ofs;
  uVar8 = count;
  if ((*(uint *)(uVar7 + 2) & 8) == 0) {
    if ((*(uint *)(uVar7 + 2) & 0x40) == 0) {
      if (*(int *)(uVar7 + 6) != 0) {
        do {
          if (uVar8 == 0) {
            return count;
          }
          iVar6 = *(int *)MK_FP(stream.seg, stream.ofs);
          *(int *)MK_FP(stream.seg, stream.ofs) = *(int *)MK_FP(stream.seg, stream.ofs) + 1;
          if (SCARRY2(iVar6,1) == *(int *)MK_FP(stream.seg, stream.ofs) < 0) {
            uVar5 = CONCAT11((char)(uVar8 >> 8),*(char *)MK_FP(buf.seg, buf.ofs));
            _fputc(*(char *)MK_FP(buf.seg, buf.ofs),(int *)CONCAT22(unaff_DI,piVar9));
          }
          else {
            uVar2 = *(undefined2 *)(uVar7 + 0xe);
            pbVar3 = (byte *)*(undefined2 *)(uVar7 + 0xc);
            *(int *)(uVar7 + 0xc) = *(int *)(uVar7 + 0xc) + 1;
            bVar1 = *(byte *)MK_FP(buf.seg, buf.ofs);
            *pbVar3 = bVar1;
            uVar5 = (uint)bVar1;
          }
          buf.ofs = buf.ofs + 1;
          uVar8 = uVar8 - 1;
        } while (uVar5 != 0xffff);
        return 0;
      }
      uVar5 = __write(buf.ofs,(char *)CONCAT22(count,buf.seg),unaff_DI,unaff_SI);
    }
    else if (*(int *)(uVar7 + 6) == 0) {
      if ((((uint16_t *)_openfd)[*(char *)(uVar7 + 4)] & 0x800) != 0) {
        lseek((int)*(char *)(uVar7 + 4),0x20000,unaff_DI);
      }
      uVar5 = write((int)*(char *)(uVar7 + 4),(void *)MK_FP(buf.seg, buf.ofs),count);
    }
    else {
      if (count <= *(uint *)(uVar7 + 6)) {
        if (SCARRY2(*(int *)MK_FP(stream.seg, stream.ofs),count) == (int)(*(int *)MK_FP(stream.seg, stream.ofs) + count) < 0) {
          if (*(int *)MK_FP(stream.seg, stream.ofs) == 0) {
            *(int *)MK_FP(stream.seg, stream.ofs) = -1 - *(int *)(uVar7 + 6);
          }
          else {
            iVar6 = fflush((int *)MK_FP(stream.seg, stream.ofs));
            if (iVar6 != 0) {
              return 0;
            }
          }
        }
        memcpy((char *)CONCAT22(*(undefined2 *)(uVar7 + 0xe),(char *)*(undefined2 *)(uVar7 + 0xc)),
               (char *)MK_FP(buf.seg, buf.ofs),count);
        *(uint16_t *)MK_FP(stream.seg, stream.ofs) = *(int *)MK_FP(stream.seg, stream.ofs) + count;
        *(int *)(uVar7 + 0xc) = *(int *)(uVar7 + 0xc) + count;
        return count;
      }
      if ((*(int *)MK_FP(stream.seg, stream.ofs) != 0) && (iVar6 = fflush((int *)MK_FP(stream.seg, stream.ofs)), iVar6 != 0)) {
        return 0;
      }
      if ((((uint16_t *)_openfd)[*(char *)(uVar7 + 4)] & 0x800) != 0) {
        lseek((int)*(char *)(uVar7 + 4),0x20000,unaff_DI);
      }
      uVar5 = write((int)*(char *)(uVar7 + 4),(void *)MK_FP(buf.seg, buf.ofs),count);
    }
    if (count <= uVar5) {
      return count;
    }
  }
  else {
    do {
      fVar4 = buf;
      if (uVar8 == 0) {
        return count;
      }
      buf.ofs = buf.ofs + 1;
      uVar5 = fputc(*(byte *)MK_FP(fVar4.seg, fVar4.ofs),(int *)CONCAT22(unaff_DI,piVar9));
      uVar8 = uVar8 - 1;
    } while (uVar5 != 0xffff);
  }
  return 0;
}



/* 1000:2b24 */
undefined2 __cdecl16far setvbuf(FILE *stream,uint8_t *bufOfs,uint mode)

{
  uint8_t *puVar1;
  uint8_t *puVar2;
  FILE *pFVar3;
  undefined2 uVar4;
  uint in_stack_0000000e;
  
  uVar4 = (undefined2)((ulong)stream >> 0x10);
  pFVar3 = (FILE *)stream;
  if ((((FILE *)pFVar3->token == pFVar3) && ((int)mode < 3)) && (in_stack_0000000e < 0x8000)) {
    if ((_stdoutStarted == 0) && (pFVar3 == (FILE *)(_streams + 1))) {
      _stdoutStarted = 1;
    }
    else if ((_stdinStarted == 0) && (pFVar3 == (FILE *)_streams)) {
      _stdinStarted = 1;
    }
    if (stream->level != 0) {
      fseek((uint16_t *)stream,0,0,1);
    }
    if ((pFVar3->flags & 4) != 0) {
      farfree((uint16_t)pFVar3->buffer,*(uint16_t *)((int)&pFVar3->buffer + 2));
    }
    pFVar3->flags = pFVar3->flags & 0xfff3;
    pFVar3->bsize = 0;
    puVar2 = &pFVar3->hold;
    *(undefined2 *)((int)&pFVar3->buffer + 2) = uVar4;
    *(uint8_t **)&pFVar3->buffer = puVar2;
    *(undefined2 *)((int)&pFVar3->curp + 2) = uVar4;
    *(uint8_t **)&pFVar3->curp = puVar2;
    if ((mode != 2) && (in_stack_0000000e != 0)) {
      _exitbuf.seg = 0x1000;
      _exitbuf.ofs = 0x2fe4;
      if (bufOfs == (uint8_t *)0x0) {
        puVar1 = (uint8_t *)malloc(0);   /* hand fix: size argument was lost by the decompiler */
        bufOfs = (uint8_t *)CONCAT22(puVar2,puVar1);
        if (puVar1 == (uint8_t *)0x0 && puVar2 == (uint8_t *)0x0) goto L_setvbuf_2B46;
        pFVar3->flags = pFVar3->flags | 4;
      }
      *(undefined2 *)((int)&pFVar3->curp + 2) = (*(uint16_t *)((uint8_t *)&(bufOfs) + 2));
      *(uint8_t **)&pFVar3->curp = (uint8_t *)bufOfs;
      *(undefined2 *)((int)&pFVar3->buffer + 2) = (*(uint16_t *)((uint8_t *)&(bufOfs) + 2));
      *(uint8_t **)&pFVar3->buffer = (uint8_t *)bufOfs;
      pFVar3->bsize = in_stack_0000000e;
      if (mode == 1) {
        pFVar3->flags = pFVar3->flags | 8;
      }
    }
    uVar4 = 0;
  }
  else {
L_setvbuf_2B46:
    uVar4 = 0xffff;
  }
  return uVar4;
}


/* 1000:2c3f */

uint16_t __cdecl16near sprintf_strputn(char *dest,char *src,uint16_t n)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)dest >> 0x10);
  memcpy((char *)CONCAT22(*(undefined2 *)((char *)dest + 2),*(char **)dest),
         (char *)CONCAT22(n,(*(uint16_t *)((uint8_t *)&(src) + 2))),(word)(char *)src);
  *(char **)dest = (char *)src + *(int *)dest;
  **(undefined1 **)dest = 0;
  return (uint16_t)(char *)src;
}



/* 1000:2c7f */

void __cdecl16far _sprintf(char *buf,char *fmt)

{
  *buf = '\0';
  __vprinter();
  return;
}



/* 1000:2ca1 */

int16_t __cdecl16far vsprintf(char *buf,char *fmt,uint16_t ap)

{
  char **ppcVar1;
  
  *buf = '\0';
  ppcVar1 = &buf;
  __vprinter();
  return (int16_t)ppcVar1;
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
  uint16_t d;
  char *pcVar6;
  uint16_t s;
  char *pcVar7;
  char *pcVar8;
  uint16_t dseg;
  uint16_t sseg;
  
  dseg = (uint16_t)((ulong)dst >> 0x10);
  d = (uint16_t)dst;
  iVar3 = -1;
  pcVar6 = (char *)d;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar1 = pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar1 != '\0');
  sseg = (uint16_t)((ulong)src >> 0x10);
  s = (uint16_t)src;
  uVar4 = 0xffff;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar1 = (char *)s;
    s = s + 1;
  } while (*pcVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = (char *)(s + -uVar4);
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
  return (char *)d;
}



/* 1000:2d01 */

int __cdecl16far strcmp(char *a,char *b)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  
  uVar6 = (undefined2)((ulong)b >> 0x10);
  pcVar5 = (char *)b;
  uVar3 = 0xffff;
  pcVar4 = pcVar5;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar1 = pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  uVar3 = ~uVar3;
  uVar7 = (undefined2)((ulong)a >> 0x10);
  pcVar4 = (char *)a;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar2 = pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar1 = pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 == *pcVar2);
  return (uint)(byte)pcVar4[-1] - (uint)(byte)pcVar5[-1];
}



/* 1000:2d31 */

char * __cdecl16far strcpy(char *dst,char *src)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined2 uVar6;
  
  uVar6 = (undefined2)((ulong)src >> 0x10);
  pcVar4 = (char *)src;
  uVar3 = 0xffff;
  pcVar5 = pcVar4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar1 = pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (*pcVar1 != '\0');
  pcVar5 = (char *)dst;
  for (uVar3 = ~uVar3; uVar3 != 0; uVar3 = uVar3 - 1) {
    pcVar2 = pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar1 = pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar2 = *pcVar1;
  }
  return (char *)dst;
}



/* 1000:2d5a */

int __cdecl16far _fstricmp(char *str1,char *str2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined2 uVar8;
  
  pbVar6 = (byte *)str1;
  uVar8 = (undefined2)((ulong)str2 >> 0x10);
  pbVar7 = (byte *)str2;
  do {
    do {
      pbVar1 = pbVar6;
      pbVar6 = pbVar6 + 1;
      bVar2 = *pbVar1;
      bVar3 = *pbVar7;
      uVar5 = (uint)bVar3;
      uVar4 = (uint)bVar2;
      if (bVar2 == 0) goto L__fstricmp_2D93;
      pbVar1 = pbVar7;
      pbVar7 = pbVar7 + 1;
    } while (bVar2 == *pbVar1);
    if ((0x60 < bVar2) && (bVar2 < 0x7b)) {
      uVar4 = (uint)(byte)(bVar2 - 0x20);
    }
    if ((0x60 < bVar3) && (bVar3 < 0x7b)) {
      uVar5 = (uint)(byte)(bVar3 - 0x20);
    }
  } while ((char)uVar4 == (char)uVar5);
L__fstricmp_2D93:
  return uVar4 - uVar5;
}



/* 1000:2d9b */

size_t __cdecl16far strlen(char *str)

{
  char *pcVar1;
  size_t sVar2;
  uint uVar3;
  char *pcVar4;
  
  pcVar4 = (char *)str;
  sVar2 = 0;
  if (str != (char *)0x0) {
    uVar3 = 0xffff;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar1 = pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (*pcVar1 != '\0');
    sVar2 = ~uVar3 - 1;
  }
  return sVar2;
}



/* 1000:2dba */

char * __cdecl16far __fstrncpy(char *dst,char *src,uint16_t n)

{
  char *pcVar1;
  char *pcVar2;
  uint16_t uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  
  uVar7 = (undefined2)((ulong)src >> 0x10);
  pcVar5 = (char *)src;
  uVar3 = n;
  pcVar6 = pcVar5;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar1 = pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar1 != '\0');
  uVar8 = (undefined2)((ulong)dst >> 0x10);
  pcVar6 = (char *)dst;
  for (iVar4 = n - uVar3; iVar4 != 0; iVar4 = iVar4 + -1) {
    pcVar2 = pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar1 = pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar2 = *pcVar1;
  }
  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
    pcVar1 = pcVar6;
    pcVar6 = pcVar6 + 1;
    *pcVar1 = '\0';
  }
  return (char *)dst;
}



/* 1000:2deb */
char * __cdecl16far _fstrstr(char *haystack,char *needle)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  bool bVar9;
  
  if (*needle != '\0') {
    uVar7 = (undefined2)((ulong)haystack >> 0x10);
    uVar2 = 0xffff;
    pcVar5 = (char *)haystack;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar1 = pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar1 != '\0');
    uVar2 = ~uVar2;
    uVar8 = (undefined2)((ulong)needle >> 0x10);
    iVar3 = -1;
    pcVar5 = (char *)needle;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar1 = pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar1 != '\0');
    bVar9 = iVar3 + 1U == 0;
    uVar4 = ~(iVar3 + 1U);
    do {
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar1 = (char *)haystack;
        (*(uint16_t *)((uint8_t *)&(haystack))) = (uint16_t)(char *)haystack + 1;
        bVar9 = *needle == *pcVar1;
      } while (!bVar9);
      if ((!bVar9) || (uVar2 < uVar4)) {
        (*(uint16_t *)((uint8_t *)&(haystack))) = (uint16_t)(char *)((int)(undefined4 *)&_DATA + 1);
        break;
      }
      if (uVar4 == 0) break;
      iVar3 = uVar4 - 1;
      bVar9 = iVar3 == 0;
      pcVar6 = (char *)haystack;
      pcVar5 = (char *)needle;
      do {
        pcVar5 = pcVar5 + 1;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar1 = pcVar6;
        pcVar6 = pcVar6 + 1;
        bVar9 = *pcVar5 == *pcVar1;
      } while (bVar9);
    } while (!bVar9);
    (*(uint16_t *)((uint8_t *)&(haystack))) = (uint16_t)(char *)haystack + -1;
  }
  return (char *)haystack;
}


/* 1000:2e59 */

uint16_t __cdecl16far __write(uint fd,char *bufOfs,uint16_t bufSeg,uint16_t count)

{
  uint8_t *puVar1;
  uint uVar2;
  uint8_t *puVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  int unaff_DI;
  undefined2 unaff_SS;
  uint in_stack_00000004;
  uint8_t buf;
  uint8_t *puStack_e;
  uint8_t uStack_9;
  uint16_t uStack_8;
  uint8_t *puStack_6;
  undefined2 uVar6;
  
  if (in_stack_00000004 < _nfile) {
    if ((*(uint16_t *)((uint8_t *)&(bufOfs) + 2)) + 1 < 2) {
      uVar4 = 0;
    }
    else {
      if ((((uint16_t *)_openfd)[in_stack_00000004] & 0x800) != 0) {
        lseek(in_stack_00000004,0x20000,unaff_DI);
      }
      if ((((uint16_t *)_openfd)[in_stack_00000004] & 0x4000) == 0) {
        uVar4 = write(in_stack_00000004,(void *)CONCAT22((char *)bufOfs,fd),(*(uint16_t *)((uint8_t *)&(bufOfs) + 2)));
      }
      else {
        ((uint16_t *)_openfd)[in_stack_00000004] = ((uint16_t *)_openfd)[in_stack_00000004] & 0xfdff
        ;
        puStack_e = (uint8_t *)CONCAT22((char *)bufOfs,fd);
        uStack_8 = (*(uint16_t *)((uint8_t *)&(bufOfs) + 2));
        do {
          puStack_6 = (uint8_t *)CONCAT22(unaff_SS,&buf);
          do {
            puVar3 = puStack_e;
            if (uStack_8 == 0) {
              uVar4 = (int)puStack_6 - (int)&buf;
              if (uVar4 == 0) {
                return (*(uint16_t *)((uint8_t *)&(bufOfs) + 2));
              }
              uVar5 = write(in_stack_00000004,(uint8_t *)CONCAT22(unaff_SS,&buf),uVar4);
              if (uVar5 == uVar4) {
                return (*(uint16_t *)((uint8_t *)&(bufOfs) + 2));
              }
              if (uVar5 == 0xffff) goto L__write_2F47;
              goto L__write_2F99;
            }
            uStack_8 = uStack_8 - 1;
            puStack_e = (uint8_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(puStack_e) + 2)),(uint8_t *)puStack_e + 1);
            uStack_9 = *puVar3;
            if (uStack_9 == 0xa) {
              *puStack_6 = 0xd;
              uVar6 = (undefined2)((ulong)puStack_6 >> 0x10);
              puStack_6 = (uint8_t *)CONCAT22(uVar6,puStack_6 + 1);
            }
            *puStack_6 = uStack_9;
            puVar1 = puStack_6 + 1;
            uVar6 = (undefined2)((ulong)puStack_6 >> 0x10);
            puStack_6 = (uint8_t *)CONCAT22(uVar6,puVar1);
            uVar2 = (uint)(puVar1 < &buf);
          } while (((int)-uVar2 < 0) || ((uVar2 == 0 && ((uint)((int)puVar1 - (int)&buf) < 0x80))));
          uVar4 = (int)puVar1 - (int)&buf;
          uVar5 = write(in_stack_00000004,(uint8_t *)CONCAT22(unaff_SS,&buf),uVar4);
        } while (uVar5 == uVar4);
        if (uVar5 == 0xffff) {
L__write_2F47:
          uVar4 = 0xffff;
        }
        else {
          (*(uint16_t *)((uint8_t *)&(bufOfs) + 2)) = (*(uint16_t *)((uint8_t *)&(bufOfs) + 2)) - uStack_8;
L__write_2F99:
          uVar4 = ((*(uint16_t *)((uint8_t *)&(bufOfs) + 2)) + uVar5) - uVar4;
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
  undefined2 uVar4;
  
  bVar2 = false;
  if ((((uint16_t *)_openfd)[handle] & 1) == 0) {
    uVar4 = 0x2410;
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
      fflush((int *)CONCAT22(0x2410,pFStack_6));
    }
    pFStack_6 = pFStack_6 + 1;
  }
  return;
}


