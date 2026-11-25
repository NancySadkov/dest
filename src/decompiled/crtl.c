/*
 * crtl.c - recovered from STRONG.EXE
 * memory block: 1000_TEXT_crtl
 * range: 1000:0000 - 1000:301b
 * functions: 175
 */
#include "recovered.h"

/* Local prototype: this file no longer defines _setupio, so the C library's own
   stream initialiser is the one C0 registers. */
void st_setupio(void);


uint16_t startxDseg;

/* The far-pointer tables below are declared as far_t with the original image's
   link-time segment (0x2410) in the initialiser: a struct field cannot hold a
   relocatable address, so the linker leaves it literal.  Patch the segment half
   to this run's DGROUP before main uses the tables.  Tables declared as
   `char far *` already carry a real relocation and do not need this. */
static void fixFarTable(far_t *tbl, uint16_t n)
{
  uint16_t i;
  /* The table lives in DGROUP, so a far cast of its own address yields DS.
     This must not depend on startxDseg: that is set by our startx, which does
     not run when the stock C0 startup is the entry. */
  uint16_t ds = (uint16_t)((unsigned long)(char far *)tbl >> 16);
  for (i = 0; i < n; i++) {
    /* null terminators stay null: the original keeps { 0, 0 } entries */
    if (tbl[i].ofs != 0 || tbl[i].seg != 0) {
      tbl[i].seg = ds;
    }
  }
}

/* Far-pointer tables whose initialisers carry the original image's link-time
   DGROUP (0x2410) and its offsets.  The original's loader relocates them; ours
   must be repaired at run time, and the repair has to happen whichever startup
   is the entry point, so it lives here and is called from main(). */
void st_fix_far_tables(void)
{
  uint16_t ds_seg =
      (uint16_t)((unsigned long)(char far *)GUnitDescriptions >> 16);
  fixFarTable(GUnitDescriptions, 28);
  fixFarTable(CPKeys, 25);
  /* The initialiser holds the original image's offsets; address the rebuild's
     own copies of those strings instead.  Verified by running the post-init_cfg
     checkpoint. */
  CPKeys[0].ofs = (uint16_t)&s_choose_2410_05f9;
  CPKeys[1].ofs = (uint16_t)&s_movement_2410_0600;
  CPKeys[2].ofs = (uint16_t)&s_button_2410_0609;
  CPKeys[3].ofs = (uint16_t)&s_gold_2410_0610;
  CPKeys[4].ofs = (uint16_t)&s_plan_2410_0615;
  CPKeys[5].ofs = (uint16_t)&s_hit_2410_061a;
  CPKeys[6].ofs = (uint16_t)&s_squares_2410_061e;
  CPKeys[7].ofs = (uint16_t)&s_swamps_2410_0626;
  CPKeys[8].ofs = (uint16_t)&s_would_2410_062d;
  CPKeys[9].ofs = (uint16_t)&s_repair_2410_0633;
  CPKeys[10].ofs = (uint16_t)&s_controlling_2410_063a;
  CPKeys[11].ofs = (uint16_t)&s_setting_2410_0646;
  CPKeys[12].ofs = (uint16_t)&s_sage_2410_064e;
  CPKeys[13].ofs = (uint16_t)&s_when_2410_0653;
  CPKeys[14].ofs = (uint16_t)&s_home_2410_0658;
  CPKeys[15].ofs = (uint16_t)&s_needed_2410_065d;
  CPKeys[16].ofs = (uint16_t)&s_screen_2410_0664;
  CPKeys[17].ofs = (uint16_t)&s_spellcasting_2410_066b;
  CPKeys[18].ofs = (uint16_t)&s_opponents_2410_0678;
  CPKeys[19].ofs = (uint16_t)&s_expense_2410_0682;
  CPKeys[20].ofs = (uint16_t)&s_after_2410_068a;
  CPKeys[21].ofs = (uint16_t)&s_dots_2410_0690;
  CPKeys[22].ofs = (uint16_t)&s_longbow_2410_0695;
  CPKeys[23].ofs = (uint16_t)&s_spells_2410_069d;
  CPKeys[24].ofs = (uint16_t)&s_constructing_2410_06a4;

  fixFarTable(worldMenuLabels, 13);
  fixFarTable(GStatsLabels, 6);
  fixFarTable(GPlayerTitles, 32);
  fixFarTable(menuHighlightTable, 5);
  fixFarTable(GAlignmentsNames, 3);
  fixFarTable(ManageResultPtrs, 5);
  fixFarTable(LevelBandLabels, 20);
  fixFarTable(LevelRangeLabels, 4);
  /* The initialiser carries the original image's offsets (0x54BF..); the
     rebuild's copies of those strings live elsewhere, so address them by
     symbol.  Entry 3 is { 0, 0 } in the original and stays null. */
  LevelRangeLabels[0].ofs = (uint16_t)&s_levels_6_8c_2410_54bf;
  LevelRangeLabels[1].ofs = (uint16_t)&s_levels_8d_8h_2410_54cb;
  LevelRangeLabels[2].ofs = (uint16_t)&s_levels_8i_8k_2410_54d8;

  fixFarTable(RampTables, 7);
  fixFarTable(GStrangeTable, 98);
  fixFarTable(GSeasonNames, 3);
  fixFarTable(RankMsgPtrs, 19);
  fixFarTable(CureSpellPtrs, 4);
  fixFarTable(PersonWordPtrs, 2);
  fixFarTable(GTxtFiles, 34);
  fixFarTable(StatsTabPtrs, 9);
  {
    uint16_t gi;
    for (gi = 0; gi < 30; gi++) {
      GStructures[gi].name.seg = ds_seg;
    }
  }
  GSPEmpty.seg = ds_seg;
  SaveHeader.seg = ds_seg;
  GDoneStrPtr.seg = ds_seg;
  msgFormat.seg = ds_seg;
  far_t_2410_78e4.seg = ds_seg;
}


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
  uint16_t uVar9;
  uint16_t extraout_DX;
  uint16_t extraout_DX_00;
  int iVar10;
  undefined1 *puVar11;
  int *piVar12;
  char *pcVar13;
  char *pcVar14;
  undefined1 *puVar15;
  uint32_t *puVar16;
  uint16_t unaff_ES;
  uint16_t uVar17;
  bool bVar18;
  uint32_t uVar19;
  uint16_t psp;
  union st_regs r;
  struct st_sregs sr;
  
  puVar11 = (undefined1 *)((int)(int *)&errno + 1);
  asm { mov ah,0x51; int 21h; mov psp,bx }   /* kernel PSP */
  /* DOS enters with DS = ES = PSP; the original startup loads DX with DGROUP
     and does MOV DS,DX before touching any global. */
  asm { mov ax, seg DosVersion; mov ds, ax };
  _psp = psp;
  uVar17 = *(uint16_t far *)MK_FP(psp, 0x2c);  /* environment segment */
  iVar10 = *(uint16_t far *)MK_FP(psp, 0x02);  /* top of memory */
  _envseg_at_ = uVar17;
  _heaptop.seg = iVar10;
  asm { mov ah,0x30; int 21h; mov word ptr DosVersion, ax };
  SaveVectors();




  pcVar4 = (char *)*(uint32_t *)&_env;
  uVar17 = (uint16_t)((ulong)pcVar4 >> 0x10);
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
  {
    uint16_t sseg = _SS;
    uint16_t avail = iVar10;             /* top of memory from PSP:0002 */
    uint16_t paras;

    avail -= sseg;
    if (__stklen < 0x200) {
      __stklen = 0x200;
    }
    paras = (__stklen >> 4) + 1;
    if (avail < paras) {
L_startx_007B:
      _abort();
    }
    _heapbase.seg = sseg + paras;
    _brklvl.seg = sseg + paras;
    {
      uint16_t bxv = sseg + paras - psp;
      /* INT 21h AH=4Ah with ES=PSP, BX=paragraphs.  CM.LIB's int86x hangs in
         this VROOMM link (its internal far calls are not relocated), so the
         interrupt is issued directly. */
      asm {
        mov bx, bxv;
        mov es, psp;
        mov ah,0x4a;
        int 21h;
      }
    }

    /* Switch to the top of the resized block.  SS is unchanged (sseg is the
       current SS), so BP-relative locals stay valid; only SP moves up, above
       the frame, giving the initialisers and main a real stack instead of the
       128 bytes DOS sets in the header. */
    asm {
      mov dx, sseg;
      mov di, paras;
      mov cl, 4;
      shl di, cl;
      cli;
      mov ss, dx;
      mov sp, di;
      sti;
    }
    __stklen = paras << 4;
  }
  if (0x14 < *(uint *)&_nfile) {
    uint16_t cf, axv;
    bVar7 = ((dosver_t *)&DosVersion)->major;
    if (!(bVar7 < 3) && (3 < bVar7 || !(*(byte *)&DosVersion.minor < 0x1e))) {
      asm {                                /* AX=5801 BX=2: get UMB link */
        mov ax,0x5801;
        mov bx,2;
        int 21h;
        mov ax,0;
        adc ax,0;
        mov cf,ax;
      }
      if (!cf) {
        asm {                              /* AH=67: set handle count */
          mov ah,0x67;
          mov bx,_nfile;
          int 21h;
          mov ax,0;
          adc ax,0;
          mov cf,ax;
        }
        if (!cf) {
          asm {                            /* AH=48 BX=1: probe allocation */
            mov ah,0x48;
            mov bx,1;
            int 21h;
            mov axv,ax;
            mov ax,0;
            adc ax,0;
            mov cf,ax;
          }
          if (!cf) {
            _heaptop.seg = axv + 1;
            asm {                          /* AH=49 ES=block: free it */
              mov es,axv;
              mov ah,0x49;
              int 21h;
              mov ax,0;
              adc ax,0;
              mov cf,ax;
            }
            if (!cf) {
              asm {                        /* restore UMB link state */
                mov ax,0x5801;
                mov bx,0;
                int 21h;
                mov ax,0;
                adc ax,0;
                mov cf,ax;
              }
              if (!cf) goto L_startx_0109;
            }
          }
        }
      }
      _abort();
    }
  }
L_startx_0109:
  {
    uint16_t dxv, cxv;
    uint8_t alv;
    asm {                                  /* INT 1Ah: system time */
      mov ah,0;
      int 1ah;
      mov dxv,dx;
      mov cxv,cx;
      mov alv,al;
    }
    *(uint16_t *)&_StartTime = dxv;
    *(uint16_t *)((uint8_t *)&_StartTime + 2) = cxv;
    if (alv != 0) {
      asm {                                /* BDA 0040:0070 = 1 */
        mov ax,0x40;
        mov es,ax;
        mov bx,0x70;
        mov byte ptr es:[bx],1;
      }
    }
  }
  /* The original walks the linker's init table here (InitStart..InitEnd):
   * st_setupio (priority 2), _c0crtinit and __setargv (0x10) plus one far entry
   * (priority 1).  Our recovered table still holds the original image's
   * addresses, so walking it hangs; the two plain initialisers are called
   * directly and __setargv's stack contract is still to be recovered
   * (doc/step6_entry.md).
   */
  st_setupio();




  _c0crtinit();




  /* __setargv is not recovered yet, but main dereferences its argument vector
     immediately (argv[0] is the executable path, argv[1] the optional save
     name), so provide a minimal one in DGROUP. */
  {
    static char arg0[] = "STRONG.EXE";
    static far_t argv[2];
    static char env0[2] = { 0, 0 };

    asm { mov ax, ds; mov word ptr startxDseg, ax }
    argv[0].ofs = (uint16_t)arg0;
    argv[0].seg = startxDseg;
    argv[1].ofs = 0;
    argv[1].seg = 0;
    __C0argc = 1;
    __C0argv = (uint16_t)argv;
    __C0environ = (uint16_t)env0;
  }
  st_fix_far_tables();
  iVar10 = main(__C0argc, (str_t *)__C0argv, (str_t *)__C0environ);
  exit(iVar10);
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

/* _terminate: body supplied by the startup (C0.ASM defines the CRT terminate routine); the recovered copy would duplicate it. */
void _terminate(void);




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
  /* INT 21h AH=35h for vectors 0, 4, 5 and 6; then vector 0 := CS:ZeroDivision
     (AH=25h).  Taken from the disassembly - the decompiled version called the
     interrupt with whatever registers happened to be set. */
  asm {
    push ds;
    mov ax,0x3500;
    int 21h;
    mov word ptr GSTARTX_SavedVectors+0,bx;
    mov word ptr GSTARTX_SavedVectors+2,es;
    mov ax,0x3504;
    int 21h;
    mov word ptr GSTARTX_SavedVectors+4,bx;
    mov word ptr GSTARTX_SavedVectors+6,es;
    mov ax,0x3505;
    int 21h;
    mov word ptr GSTARTX_SavedVectors+8,bx;
    mov word ptr GSTARTX_SavedVectors+10,es;
    mov ax,0x3506;
    int 21h;
    mov word ptr GSTARTX_SavedVectors+12,bx;
    mov word ptr GSTARTX_SavedVectors+14,es;
    mov dx,cs;
    mov ds,dx;
    mov dx,offset ZeroDivision;
    mov ax,0x2500;
    int 21h;
    pop ds;
  }
  return;
}



/* 1000:01bd */

void __cdecl16far __restorezero(void)

{
  /* INT 21h AH=25h with DS:DX from the saved vectors (0, 4, 5, 6). */
  asm {
    push ds;
    mov ax,0x2500;
    lds dx,dword ptr GSTARTX_SavedVectors+0;
    int 21h;
    pop ds;
    push ds;
    mov ax,0x2504;
    lds dx,dword ptr GSTARTX_SavedVectors+4;
    int 21h;
    pop ds;
    push ds;
    mov ax,0x2505;
    lds dx,dword ptr GSTARTX_SavedVectors+8;
    int 21h;
    pop ds;
    push ds;
    mov ax,0x2506;
    lds dx,dword ptr GSTARTX_SavedVectors+12;
    int 21h;
    pop ds;
  }
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
  uint16_t unaff_ES;
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
  /* INT 21h AH=40h, BX=2: write the message the caller set up in DS:DX/CX. */
  asm {
    mov ah,0x40;
    mov bx,2;
    int 21h;
  }
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

uint32_t * __cdecl16far xms_init(uint32_t *retStorage)

{
  code *pcVar1;
  char cVar2;
  code *in_BX;
  uint16_t unaff_ES;
  uint32_t uVar3;
  
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
    xms_handle = (uint16_t)(CONCAT12((uVar1 & 0x10000) != 0,(int)uVar1) >> 1);
    uVar1 = CONCAT22((uint)(uVar1 >> 0x11),xms_handle);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  (*(code *)xms_driver.ofs)(0x1000);
  return;
}



/* 1000:04b3 */

uint32_t * __cdecl16far ems_init(uint32_t *retStorage)

{
  code *pcVar1;
  char cVar2;
  uint32_t *puVar3;
  char extraout_AH;
  uint16_t uVar4;
  char extraout_AH_00;
  char extraout_AH_01;
  int iVar5;
  uint extraout_DX;
  uint16_t extraout_DX_00;
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
  uint16_t uVar4;
  char extraout_AH_00;
  char extraout_AH_01;
  uint extraout_DX;
  uint16_t extraout_DX_00;
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
  uint16_t hofs = 0;
  uint16_t hseg = 0;

  /* 077b: DOS "get interrupt vector" for INT 24h -> ES:BX */
  asm {
    mov ax,3524h;
    int 21h;
    mov hofs,bx;
    mov hseg,es;
  }
  GSavedErrorHandler.ofs = hofs;
  GSavedErrorHandler.seg = hseg;

  /* 078a: DS = CS, DX = offset of ioErrorHndlr (1000:07A7), AX = 0x2524 */
  asm {
    push ds;
    mov ax,cs;
    mov ds,ax;
    mov dx,offset ioErrorHndlr;
    mov ax,2524h;
    int 21h;
    pop ds;
  }
  GIOErrorCode = 0;
  GIOErrorRetryCount = 5;
  return;
}




/* 1000:07a7 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint16_t ioErrorHndlr(void)

{
  code *pcVar1;
  undefined1 uVar3;
  uint16_t uVar2;
  uint16_t in_stack_00000002;
  
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
  uint16_t hofs = GSavedErrorHandler.ofs;
  uint16_t hseg = GSavedErrorHandler.seg;

  asm {
    push ds;
    mov ax,hseg;
    mov ds,ax;
    mov dx,hofs;
    mov ax,2524h;
    int 21h;
    pop ds;
  }
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



/* 1000:0938 */

/* long multiply routine  */

long * __cdecl16far LXMUL_at_(long *retStorage,long a,long b)

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
  uint16_t *puVar1;
  uint16_t *puVar2;
  uint in_CX;
  uint uVar3;
  uint16_t *puVar4;
  uint16_t *puVar5;
  
  puVar4 = (uint16_t *)src.ofs;
  puVar5 = (uint16_t *)dst.ofs;
  for (uVar3 = in_CX >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar2 = *puVar1;
  }
  for (uVar3 = (uint)((in_CX & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2 = puVar5;
    puVar5 = (uint16_t *)((int)puVar5 + 1);
    puVar1 = puVar4;
    puVar4 = (uint16_t *)((int)puVar4 + 1);
    *(undefined1 *)puVar2 = *(undefined1 *)puVar1;
  }
  return;
}



/* 1000:09a2 */
/* setdisk - recovered from STRONG.EXE (1000:09a4).

   The decompiled body was

       uint8_t driveCount;
       uint *puStack_6;

       puStack_6 = (uint *)CONCAT22(_driveCount,_SS);
       _dos_setdrive(drive + 1,puStack_6);
       return _driveCount;

   which is a far pointer built out of two pseudo-variables.  _dos_setdrive takes a
   *near* `uint *` as its out parameter (see the recovered prototype), the function
   already declares the local `driveCount`, and the "global" `_driveCount` is only
   ever written through that pointer and then returned.  So it is the count
   variable itself: Borland's setdisk returns the number of drives. */
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

uint32_t __stdcall16far LUDIV_at_(int dividendLo,uint dividendHi,uint divisorLo,uint divisorHi)

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

uint32_t __cdecl16far N_LUMOD_at_(void)

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

long * __cdecl16far LXLSH_at_(long *retStorage,long i,byte s)

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

long * __cdecl16far LXRSH_at_(long *retStorage,long n,uint8_t cx)

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

uint32_t * __cdecl16far LXURSH_at_(uint32_t *retStorage,uint32_t val,uint8_t sh)

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

far_t PADD_at_(far_t padBase,far_t padOfs)

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

uint16_t __IOerror(int dosErr)

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

int __cdecl16far _isatty(int fd)

{
  uint16_t dxv, cf;

  /* INT 21h AX=4400h: DX bit 7 says the handle is a character device. */
  asm {
    mov ax,0x4400;
    mov bx,fd;
    int 21h;
    mov dxv,dx;
    mov ax,0;
    adc ax,0;
    mov cf,ax;
  }
  if (cf) {
    return 0;
  }
  return dxv & 0x80;
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
  uint16_t uVar11;
  uint8_t digits [34];
  
  uVar11 = (uint16_t)((ulong)buf >> 0x10);
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



/* 1000:0c98 */

uint32_t __cdecl16near N_LXMUL_at_(void)

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



/* 1000:0d36 */

void __cdecl16near st_setupio(void)

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
  uVar1 = _isatty(0);
  if (uVar1 == 0) {
    _streams[0].flags = _streams[0].flags & 0xfdff;
  }
  setvbuf(_streams, (uint8_t *)0, (uint)((_streams[0].flags & 0x200) != 0), 0x200);
  uVar1 = _isatty(1);
  if (uVar1 == 0) {
    _streams[1].flags = _streams[1].flags & 0xfdff;
  }
  if ((_streams[1].flags & 0x200) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 2;
  }
  setvbuf(_streams + 1, (uint8_t *)0, uVar1, 0x200);
  return;
}



/* 1000:0dec */

void __cdecl16far _tell(int fd)

{
  int unaff_BP;
  
  lseek(fd,0x10000,unaff_BP);
  return;
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
  uint16_t unaff_ES;
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
  uint16_t unaff_ES;
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
  uint16_t unaff_ES;
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
  uint16_t unaff_ES;
  
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
  
  *unaff_DI = in_AL;
  pcVar1 = (char *)init_textFilename + unaff_BP;
  *pcVar1 = (unsigned short)((char)*pcVar1 + -1);
  if (*pcVar1 == (unsigned short)0x0) {
    iVar2 = (*(code *)*(uint16_t *)(unaff_BP + 0xe))
                      (*(uint16_t *)(unaff_BP + 10),*(uint16_t *)(unaff_BP + 0xc),
                       unaff_DI + (1 - (unaff_BP + -0x96)),unaff_BP + -0x96);
    if (iVar2 == 0) {
      *(uint16_t *)(unaff_BP + -0x16) = 1;
    }
    *(uint16_t *)((char *)init_textFilename + unaff_BP) = 0x50;
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
  
  iVar2 = unaff_DI - (unaff_BP + -0x96);
  iVar1 = (*(code *)*(uint16_t *)(unaff_BP + 0xe))
                    (*(uint16_t *)(unaff_BP + 10),*(uint16_t *)(unaff_BP + 0xc),iVar2,
                     unaff_BP + -0x96);
  if (iVar1 == 0) {
    *(uint16_t *)(unaff_BP + -0x16) = 1;
  }
  *(uint16_t *)((char *)init_textFilename + unaff_BP) = 0x50;
  *(int *)(unaff_BP + -0x12) = *(int *)(unaff_BP + -0x12) + iVar2;
  return;
}


/* 1000:0ef0 */
uint16_t __vprinter_func_start(void)

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
  uint16_t uVar21;
  int iVar22;
  bool bVar23;
  
  *(int *)(unaff_BP + -4) = unaff_BP + -0x96;
L__vprinter_func_start_0EF9:
  pcVar16 = (char *)*(uint16_t *)(unaff_BP + -4);
L__vprinter_func_start_0EFC:
  uVar21 = (uint16_t)((ulong)*(uint32_t *)(unaff_BP + 6) >> 0x10);
  pcVar14 = (char *)(char *)*(uint32_t *)(unaff_BP + 6);
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
  *(uint16_t *)(unaff_BP + -4) = (uint16_t)pcVar16;   /* hand fix: 2-byte slot */
  uVar8 = 0;
  *(uint16_t *)(unaff_BP + -0xe) = (uint16_t)0;   /* hand fix: 2-byte slot */
  *(uint16_t *)(unaff_BP + -2) = (uint16_t)0x20;   /* hand fix: 2-byte slot */
  *(undefined1 *)(unaff_BP + -0xb) = 0;
  *(uint16_t *)(unaff_BP + -8) = (uint16_t)0xffff;   /* hand fix: 2-byte slot */
  *(uint16_t *)(unaff_BP + -10) = (uint16_t)0xffff;   /* hand fix: 2-byte slot */
  do {
    if (0x5f < (byte)(cVar7 - 0x20U)) goto switchD_1000_0f5d_caseD_13;
    alphaBase = ((uint8_t *)vprinter_printCtype)[(byte)(cVar7 - 0x20U)] * '\x02';
    bVar11 = (byte)(uVar8 >> 8);
    iVar22 = _SS;
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
      iVar22 = *(int *)*(uint16_t *)(unaff_BP + 4);
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
          pcVar16 = (char *)*(uint16_t *)(unaff_BP + -0x10);
          uVar21 = *(uint16_t *)(unaff_BP + 8);
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
            uVar21 = *(uint16_t *)(unaff_BP + -0x12);
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
      piVar20 = (int *)*(uint16_t *)(unaff_BP + 4);
      iVar12 = *piVar20;
      goto L__vprinter_func_start_106E;
    case '\x0e':
      *(char *)(unaff_BP + -5) = cVar7;
      *(uint16_t *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
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
      *(uint16_t *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
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
      *(uint16_t *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
      *(char *)(unaff_BP + -5) = cVar7;
      uVar8 = *(uint *)*(uint16_t *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
      puVar19 = (uint *)(unaff_BP + -0x45);
      *puVar19 = uVar8 & 0xff;
      uVar8 = 1;
      goto L__vprinter_func_start_11ED;
    case '\x11':
      *(uint16_t *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
      *(char *)(unaff_BP + -5) = cVar7;
      if ((*(uint *)(unaff_BP + -2) & 0x20) == 0) {
        puVar19 = *(uint **)(uint32_t *)*(uint16_t *)(unaff_BP + 4);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
        iVar22 = 0x2410;
        bVar23 = puVar19 == (uint *)0x0;
      }
      else {
        puVar4 = (uint *)*(uint32_t *)*(uint16_t *)(unaff_BP + 4);
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
      *(uint16_t *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
      if ((*(uint *)(unaff_BP + -2) & 0x20) == 0) {
        piVar20 = *(int **)(uint32_t *)*(uint16_t *)(unaff_BP + 4);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
        uVar21 = 0x2410;
      }
      else {
        piVar6 = (int *)*(uint32_t *)*(uint16_t *)(unaff_BP + 4);
        uVar21 = (uint16_t)((ulong)piVar6 >> 0x10);
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
  piVar20 = (int *)*(uint16_t *)(unaff_BP + 4);
  iVar12 = *piVar20;
  iVar9 = iVar12 >> 0xf;
L__vprinter_func_start_106E:
  piVar17 = piVar20 + 1;
  *(uint16_t *)(unaff_BP + 6) = (uint16_t)pcVar15;   /* hand fix: 2-byte slot */
  if ((*(uint *)(unaff_BP + -2) & 0x10) != 0) {
    iVar9 = *piVar17;
    piVar17 = piVar20 + 2;
  }
  *(uint16_t *)(unaff_BP + 4) = (uint16_t)piVar17;   /* hand fix: 2-byte slot */
  puVar19 = (uint *)(unaff_BP + -0x45);
  if ((iVar12 == 0) && (iVar9 == 0)) {
    if (*(int *)(unaff_BP + -10) == 0) goto L__vprinter_func_start_0EF9;
  }
  else {
    *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 4;
  }
  __LONGTOA(alphaBase,*(char *)(unaff_BP + -6),(int)cVar13,(char *)CONCAT22(_SS,puVar19),
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
  pcVar16 = (char *)*(uint16_t *)(unaff_BP + -4);
  iVar12 = *(int *)(unaff_BP + -8);
  if ((*(uint *)(unaff_BP + -2) & 5) == 5) {
    cVar7 = *(char *)(unaff_BP + -5);
    if (cVar7 == 'o') {
      if (*(int *)(unaff_BP + -0xe) < 1) {
        *(uint16_t *)(unaff_BP + -0xe) = (uint16_t)1;   /* hand fix: 2-byte slot */
      }
    }
    else if ((cVar7 == 'x') || (cVar7 == 'X')) {
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x40;
      iVar12 = iVar12 + -2;
      piVar6 = (int *)(unaff_BP + -0xe);
      iVar9 = *piVar6;
      *piVar6 = *piVar6 + -2;
      if (SBORROW2(iVar9,2) != *piVar6 < 0) {
        *(uint16_t *)(unaff_BP + -0xe) = (uint16_t)0;   /* hand fix: 2-byte slot */
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

uint32_t __VPTR(int row,int col)

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
  _VideoInt(0x0200);
  return;
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
  /* AH=12h BL=10h: BL comes back 10h when an EGA is present. */
  return (char)((uint8_t)_VideoInt(0x1200) + 0xf0);
}



/* 1000:1453 */

uint16_t videoIntResult;

uint16_t __cdecl16near _VideoInt(uint16_t axval)

{
  uint16_t out;

  /* The original is a register-convention wrapper around INT 10h: the caller
     puts AH (function) and AL (argument) in AX.  The special EGA paths only
     matter on real EGA hardware, so the interrupt is issued directly. */
  if ((uint8_t)(axval >> 8) == 0x12) {
    asm {
      mov ax, axval;
      mov bl, 0x10;
      int 10h;
      mov al, bl;
      xor ah, ah;
      mov word ptr videoIntResult, ax;
    }
  }
  else {
    asm {
      mov ax, axval;
      int 10h;
      mov word ptr videoIntResult, ax;
    }
  }
  return videoIntResult;
}



/* 1000:14d7 */

void __cdecl16near _c0crtinit(void)

{
  uint16_t ax;

  ax = _VideoInt(0x0f00);            /* AH=0Fh: get video mode */
  __crtinit((uint8_t)ax);
  ax = _VideoInt(0x0800);            /* AH=08h: read char and attribute */
  _video.normattr = (uint8_t)(ax >> 8) & 0x7f;
  _video.attribute = (uint8_t)(ax >> 8) & 0x7f;
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
  uVar4 = (uint8_t)_VideoInt(0x0f00);          /* AL = current mode */
  _video.screenwidth = (uint8_t)(_VideoInt(0x0f00) >> 8);
  if (uVar4 != videoMode) {
    _VideoInt((uint16_t)videoMode);            /* AH=0: set mode */
    {
      uint16_t axm = _VideoInt(0x0f00);
      uVar4 = (uint8_t)axm;
      _video.currmode = uVar4;
      _video.screenwidth = (uint8_t)(axm >> 8);
    }
    if ((uVar4 == 0x3) && ('\x18' < ScreenHeight)) {
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

/* CM.LIB's VPRINTER (pulled in by printf) refers to __REALCVT with a NEAR fixup.
   The emulator library defines it in a segment too far away, which is a "fixup
   overflow"; defining it here, in the same resident code segment as the library's
   printf machinery, keeps the fixup in range.  The game's printf calls use %s, %c
   and %d only, so the floating-point conversion is never entered. */
void _REALCVT(void)
{
}


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
    brkSeg = *(uint16_t *)((int)(uint32_t *)&_DATA + 2);
    malloc__last = brkSeg;
    if (*(int *)((int)(uint32_t *)&_DATA + 2) == 0) {
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
  uint16_t uVar1;
  int in_DX;
  int iVar2;
  int iStack_2;
  
  iStack_2 = *(int *)((int)(uint32_t *)&_DATA + 2);
  *(uint16_t *)((int)(uint32_t *)&_DATA + 2) = 0;
  *(int *)((byte *)__C0_ASM_CopyRight + 4) = iStack_2;
  if ((in_DX == __farmalloc_first) || (*(int *)((int)(uint32_t *)&_DATA + 2) != 0)) {
    malloc_InsertFreeBlock();
    iStack_2 = in_DX;
  }
  else {
    iVar2 = *(int *)0x0;
    *(int *)0x0 = *(int *)0x0 + iVar2;
    iVar2 = in_DX + iVar2;
    if (*(int *)((int)(uint32_t *)&_DATA + 2) == 0) {
      *(int *)((byte *)__C0_ASM_CopyRight + 4) = iStack_2;
    }
    else {
      *(int *)((int)(uint32_t *)&_DATA + 2) = iStack_2;
    }
  }
  iVar2 = iStack_2 + *(int *)0x0;
  if (*(int *)((int)(uint32_t *)&_DATA + 2) != 0) {
    return;
  }
  *(int *)0x0 = *(int *)0x0 + *(int *)0x0;
  *(int *)((int)(uint32_t *)&_DATA + 2) = iStack_2;
  if (iVar2 != *(int *)((byte *)__C0_ASM_CopyRight + 2)) {
    uVar1 = *(uint16_t *)((byte *)__C0_ASM_CopyRight + 2);
    __farmalloc_rover = *(uint16_t *)(byte *)__C0_ASM_CopyRight;
    *(uint16_t *)((byte *)__C0_ASM_CopyRight + 2) = uVar1;
    *(uint16_t *)(byte *)__C0_ASM_CopyRight = __farmalloc_rover;
    return;
  }
  __farmalloc_rover = 0;
  return;
}



/* 1000:16b8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void malloc_JoinFreeBlocks(void)

{
  uint16_t uVar1;
  uint16_t uVar2;
  uint16_t unaff_ES;
  
  *(int *)0x0 = *(int *)0x0 + (int)_DATA;
  *(uint16_t *)((int)(uint32_t *)&_DATA + 2) = unaff_ES;
  uVar2 = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 2));
  uVar1 = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight)));
  if ((*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 2)) != 0x2410) {
    *(uint16_t *)((byte *)__C0_ASM_CopyRight + 2) = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 2));
    *(uint16_t *)(byte *)__C0_ASM_CopyRight = uVar1;
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
  uint16_t uVar1;
  
  uVar1 = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 2));
  __farmalloc_rover = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight)));
  if ((*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 2)) != 0x2410) {
    *(uint16_t *)((byte *)__C0_ASM_CopyRight + 2) = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 2));
    *(uint16_t *)(byte *)__C0_ASM_CopyRight = __farmalloc_rover;
    return;
  }
  __farmalloc_rover = 0;
  return;
}



/* 1000:16f7 */

void __cdecl16near malloc_InsertFreeBlock(void)

{
  uint16_t uVar1;
  
  (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight))) = __farmalloc_rover;
  if (__farmalloc_rover != 0) {
    uVar1 = *(uint16_t *)((byte *)__C0_ASM_CopyRight + 2);
    *(char **)((byte *)__C0_ASM_CopyRight + 2) = (char *)0x26510;
    *(char **)(byte *)__C0_ASM_CopyRight = (char *)0x26510;
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



/* 1000:1757 */

uint16_t __cdecl16near malloc_CreateHeap(void)

{
  uint in_AX;
  uint16_t uVar1;
  ulong uVar2;
  uint32_t uVar3;
  
  uVar2 = __sbrk(0,0);
  if ((uVar2 & 0xf) != 0) {
    __sbrk(0x10 - ((uint)uVar2 & 0xf),0);
  }
  uVar3 = __sbrk(in_AX << 4,in_AX >> 0xc);
  uVar1 = (uint16_t)((ulong)uVar3 >> 0x10);
  if ((int)uVar3 != -1) {
    __farmalloc_first = uVar1;
    malloc__last = uVar1;
    *(uint *)0x0 = in_AX;
    *(uint16_t *)((int)(uint32_t *)&_DATA + 2) = uVar1;
    return 4;
  }
  return 0;
}



/* 1000:17bb */

uint16_t __cdecl16near malloc_ExtendHeap(void)

{
  uint16_t uVar1;
  uint in_AX;
  int iVar2;
  ulong uVar3;
  uint32_t uVar4;
  
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
  *(uint16_t *)((int)(uint32_t *)&_DATA + 2) = uVar1;
  return 4;
}



/* 1000:1815 */

uint16_t __cdecl16near malloc_AllocatePartialBlock(void)

{
  int in_AX;
  int in_DX;
  int iVar1;
  
  (*(uint16_t *)((uint8_t *)&(_DATA))) = (int)_DATA - in_AX;
  iVar1 = in_DX + (int)_DATA;
  *(int *)0x0 = in_AX;
  *(int *)((int)(uint32_t *)&_DATA + 2) = in_DX;
  *(int *)((int)(uint32_t *)&_DATA + 2) = iVar1;
  return 4;
}



/* 1000:18bf */
far_t __cdecl16near malloc_ExpandBlock(void)

{
  byte *pbVar1;
  uint16_t *puVar2;
  byte *pbVar3;
  uint16_t *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint16_t in_DX;
  uint uVar9;
  uint16_t in_BX;
  byte *pbVar10;
  uint16_t *puVar11;
  byte *pbVar12;
  uint16_t *puVar13;
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
    *(uint16_t *)pbVar3 = *(uint16_t *)pbVar1;
  }
  if (uVar9 != 0) {
    iVar6 = in_DX + 1;
    iVar5 = seg + 1;
    while( true ) {
      puVar13 = (uint16_t *)0x0;
      puVar11 = (uint16_t *)0x0;
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

uint32_t __cdecl16near malloc_ShrinkBlock(void)

{
  uint16_t in_AX;
  int in_CX;
  int iVar1;
  int in_BX;
  uint16_t seg;
  
  if (in_BX != malloc__last) {
    seg = in_BX + in_AX;
    *(int *)0x0 = in_CX - in_AX;
    *(int *)((int)(uint32_t *)&_DATA + 2) = in_BX;
    *(uint16_t *)0x0 = in_AX;
    iVar1 = in_BX + in_CX;
    if (*(int *)((int)(uint32_t *)&_DATA + 2) == 0) {
      *(uint16_t *)((byte *)__C0_ASM_CopyRight + 4) = seg;
    }
    else {
      *(uint16_t *)((int)(uint32_t *)&_DATA + 2) = seg;
    }
    farfree(in_AX,seg);
    return CONCAT22(in_BX,4);
  }
  *(uint16_t *)0x0 = in_AX;
  __brk(0,in_BX + in_AX);
  return CONCAT22(in_BX,4);
}



/* 1000:199f */
far_t * __cdecl16far _realloc(uint16_t param_1,uint16_t param_2,far_t *param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  far_t far *pfVar3;
  uint unaff_DI;
  far_t far *pfVar4;
  far_t fVar5;
  
  __farmalloc_data_seg = 0x2410;
  malloc_save_hi = 0;
  malloc_save_lo = (uint16_t)param_3;   /* hand fix: 2-byte slot */
  if (param_2 == 0) {
    pfVar3 = farmalloc(param_3,(ulong)unaff_DI << 0x10);
  }
  else if (param_3 == (far_t far *)0x0) {
    farfree(0,param_2);
    pfVar3 = (far_t far *)0x0;
  }
  else {
    puVar1 = (undefined1 *)((int)&param_3[4].seg + 1);
    uVar2 = CONCAT11((byte)((uint)puVar1 >> 0xc) | ((far_t far *)init_textFilename < param_3) << 4,
                     (char)((uint)puVar1 >> 4));
    if (*(uint *)0x0 < uVar2) {
      fVar5 = malloc_ExpandBlock();
      pfVar3 = (far_t far *)fVar5.ofs;
    }
    else if (*(uint *)0x0 == uVar2) {
      pfVar3 = (far_t far *)__C0_ASM_CopyRight;
    }
    else {
      pfVar4 = (far_t far *)malloc_ShrinkBlock();
      pfVar3 = (far_t far *)pfVar4;
    }
  }
  return pfVar3;
}


/* 1000:1a20 */

uint16_t _brk_normalize(uint16_t brkOfs,uint16_t brkSeg)

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



/* 1000:1b63 */

uint __cdecl16far _farcoreleft(void)

{
  uint16_t uVar1;
  uint16_t uStack_6;
  
  uVar1 = _heaptop.seg;
  uStack_6 = N_PSBP_at_();
  if ((uVar1 != 0) || (0x10 < uStack_6)) {
    uStack_6 = uStack_6 - 0x10;
  }
  return uStack_6 & 0xfff0;
}



/* 1000:1bb3 */

uint16_t __cdecl16far _gettext(int x1,int y1,int x2,int y2,int buf,uint16_t bufSeg)

{
  int iVar1;
  uint16_t uVar2;
  uint16_t width;
  uint32_t uVar3;
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

uint16_t __cdecl16far _puttext(int x1,int y1,int x2,int y2,int buf,uint16_t bufSeg)

{
  uint16_t width;
  uint32_t uVar1;
  
  width = (x2 - x1) + 1;
  for (; y1 <= y2; y1 = y1 + 1) {
    uVar1 = __VPTR(y1,x1);
    __SCREENIO(width,buf,bufSeg,(uint16_t)uVar1,(uint16_t)((ulong)uVar1 >> 0x10));
    buf = buf + width * 2;
  }
  return 1;
}



/* 1000:1c4c */

uint16_t __cdecl16far _movetext(int x1,int y1,int x2,int y2,int dstX,int dstY)

{
  int iVar1;
  uint16_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
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

uint16_t screenpos(uint vramOfs)

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
    _VideoInt(0x0200);
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
  uint16_t uVar3;
  bool bVar4;
  bool bVar5;
  uint16_t *in_stack_00000004;
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
    (*(uint16_t *)((uint8_t *)&(vramOfs) + 2)) = (uint16_t)(uint16_t *)((ulong)puVar1 >> 0x10);
    (*(uint16_t *)((uint8_t *)&(vramOfs))) = (uint16_t)(uint16_t *)puVar1;
    if (width == 0) break;
    if (bVar5) {
      puVar2 = (uint16_t *)&cursorPos;
      moveto((uint16_t *)CONCAT22(_SS,puVar2),(uint16_t *)CONCAT22(_SS,&vramScreenOfs));
      uVar3 = CONCAT11(8,(char)puVar2);
      _VideoInt(0x0200);
    }
    else {
      uVar3 = *(uint16_t *)CONCAT22((uint16_t *)vramOfs,in_stack_00000004);
      in_stack_00000004 = in_stack_00000004 + 1;
    }
    if (bVar4) {
      moveto((uint16_t *)CONCAT22(_SS,&cursorPos),(uint16_t *)CONCAT22(_SS,&srcScreenOfs))
      ;
      _VideoInt(0x0200);
      width = width + -1;
    }
    else {
      *(uint16_t *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(vramOfs) + 2))) = uVar3;
      puVar1 = (uint16_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(vramOfs) + 2)) + 1,(uint16_t *)vramOfs);
      width = width + -1;
    }
  }
  _VideoInt(0x0200);
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

uint16_t __VALIDATEXY(uint y2,uint x2,uint y1,uint x1)

{
  uint16_t uVar1;
  
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
  uint16_t rowBuf [80];
  
  if (((_video.graphicsmode == 0x0) && (ram0x0002c9bb != 0)) && (dir == '\x01')) {
    bVar1 = y2 + 1;
    bVar2 = x2 + 1;
    bVar3 = y1 + 1;
    bVar4 = x1 + 1;
    if (lines == '\x06') {
      _movetext((uint)bVar1,bVar2 + 1,(uint)bVar3,(uint)bVar4,(uint)bVar1,(uint)bVar2);
      _gettext((uint)bVar1,(uint)bVar4,(uint)bVar1,(uint)bVar4,(int)rowBuf,_SS);
      _zapline((uint)bVar3,(uint)bVar1,(uint16_t *)CONCAT22(_SS,rowBuf));
    }
    else {
      _movetext((uint)bVar1,(uint)bVar2,(uint)bVar3,bVar4 - 1,(uint)bVar1,bVar2 + 1);
      _gettext((uint)bVar1,(uint)bVar2,(uint)bVar1,(uint)bVar2,(int)rowBuf,_SS);
      _zapline((uint)bVar3,(uint)bVar1,(uint16_t *)CONCAT22(_SS,rowBuf));
      bVar4 = bVar2;
    }
    _puttext((uint)bVar1,(uint)bVar4,(uint)bVar3,(uint)bVar4,(int)rowBuf,_SS);
  }
  else {
    _VideoInt(0x0200);
  }
  return;
}



/* 1000:2032 */
void __setargv(uint savedES)

{
  undefined1 stk_0000;   /* stack slot 0000 */
  undefined1 stk_0004;   /* stack slot 0004 */
  char *pcVar1;
  char *pcVar2;
  byte bVar3;
  undefined1 *puVar4;
  uint uVar6;
  int iVar7;
  uint in_BX;
  int iVar8;
  int *piVar9;
  uint16_t unaff_SI;
  char *pcVar10;
  uint16_t unaff_DI;
  char *pcVar11;
  uint16_t uVar12;
  uint16_t uVar13;
  bool bVar14;
  undefined1 uVar15;
  uint16_t in_stack_00000000;
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
  pcVar11 = (char *)((int)&stk_0004 + iVar8);
  if (puVar4 <= &stk_0004) {
    *(uint16_t *)((int)&savedES + iVar8) = uVar12;
    uVar13 = *(uint16_t *)((int)&savedES + iVar8);
    *(int *)((int)&savedES + iVar8) = _SS;
    uVar12 = *(uint16_t *)((int)&savedES + iVar8);
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
    *(char **)(&stk_0000 + iVar8) = (char *)0x20a8;
    iVar5 = NextChar();
    bVar3 = (byte)iVar5;
    if (bVar14 || (bool)uVar15) {
      do {
        uVar12 = __setargv_SavedDS;
        if (bVar14) {
          pcVar10 = (char *)&stk_0004;
          iVar7 = *(int *)((int)&savedES + iVar8) + iVar7;
          *(uint *)&_argc_at_ = uVar6;
          iVar8 = uVar6 + 1;
          piVar9 = (int *)(&stk_0004 + iVar8 * -2);
          if (&stk_0004 < (undefined1 *)(iVar8 * 4)) goto code_r0x000120eb;
          *(uint16_t *)&_argv_at_ = (uint16_t)piVar9;   /* hand fix: 2-byte slot */
          *(int *)&_argv_at__2 = _SS;
          uVar12 = __setargv_SavedDS;
          goto SetArgvX;
        }
        *(char **)(&stk_0000 + iVar8) = (char *)0x20af;
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
    piVar9[1] = _SS;
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
  (&savedES)[iVar8 * -2] = *(uint16_t *)&__setargv_SavedReturn2;
  *(uint16_t *)(&stk_0000 + iVar8 * -4) = *(uint16_t *)&__setargv_SavedES;
  *(uint16_t *)&__C0argc = *(uint16_t *)&_argc_at_;
  *(uint16_t *)&__C0argv_2 = *(uint16_t *)&_argv_at__2;
  *(uint16_t *)&__C0argv = *(uint16_t *)&_argv_at_;
                    /* WARNING: Could not recover jumptable at 0x00012153. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*(uint16_t *)&__setargv_SavedReturn)();
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
  uint16_t unaff_ES;
  
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

uint16_t __cdecl16near _wherexy(void)

{
  uint16_t in_DX;
  
  _VideoInt(0x0200);
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
  uint16_t uVar7;
  
  uVar7 = (uint16_t)((ulong)s >> 0x10);
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



/* 1000:2243 */

int CreateFile(uint16_t mode)

{
  code *pcVar1;
  int dosErr;
  uint16_t unaff_BP;
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
  uint16_t uVar8;
  undefined1 *uStack_6;   /* hand fix: dereferenced as *uStack_6 */
  
  uVar8 = (uint16_t)((ulong)stream >> 0x10);
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


/* 1000:2568 */

/* Borland C++ 3.0 has no getcwd(), so we have to provide one  */

/* 1000:2685 */

void * __cdecl16far __fmovmem(char *src,char *dst,word count)

{
  char *pcVar1;
  char *pcVar2;
  void *pvVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  uint16_t uVar7;
  uint16_t uVar8;
  byte in_CF;
  
  N_PCMP_at_();
  pvVar3 = (void *)(uint)in_CF;
  uVar8 = (uint16_t)((ulong)src >> 0x10);
  pcVar5 = (char *)src;
  uVar7 = (uint16_t)((ulong)dst >> 0x10);
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
    *(uint16_t *)pcVar2 = *(uint16_t *)pcVar1;
  }
  if ((count & 1) != 0) {
    pcVar6[(int)pvVar3] = pcVar5[(int)pvVar3];
  }
  return pvVar3;
}



/* 1000:2747 */

void __cdecl16far st_printf(char *fmt,...)

{
  __vprinter();
  return;
}



/* 1000:2762 */

void __cdecl16far _fputc(char c,int *stream)

{
  uint16_t unaff_BP;
  int *in_stack_00000006;
  
  *(int *)CONCAT22((int *)stream,in_stack_00000006) =
       *(int *)CONCAT22((int *)stream,in_stack_00000006) + -1;
  fputc(c,(int *)CONCAT22(unaff_BP,(int *)stream));
  return;
}



/* 1000:2911 */

void __cdecl16far fputchar(uint16_t c)

{
  uint16_t unaff_BP;
  
  fputc((byte)c,(int *)CONCAT22(unaff_BP,(char *)0x26510));
  return;
}



/* 1000:2925 */

/* WARNING: Type propagation algorithm not settling */

uint16_t __cdecl16near __fputn(far_t stream,uint16_t count,far_t buf)

{
  byte bVar1;
  uint16_t uVar2;
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
            uVar2 = *(uint16_t *)(uVar7 + 0xe);
            pbVar3 = (byte *)*(uint16_t *)(uVar7 + 0xc);
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
        memcpy((char *)CONCAT22(*(uint16_t *)(uVar7 + 0xe),(char *)*(uint16_t *)(uVar7 + 0xc)),
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
static char streamBuf0[0x200];
static char streamBuf1[0x200];

uint16_t __cdecl16far setvbuf(FILE *stream, uint8_t *bufOfs, uint mode,
                             uint16_t size)
{
  uint16_t dseg;
  char *buf;

  (void)bufOfs;
  (void)mode;
  if (stream == &_streams[0]) {
    buf = streamBuf0;
  }
  else if (stream == &_streams[1]) {
    buf = streamBuf1;
  }
  else {
    return 0;
  }
  if (size == 0) {
    size = 0x200;
  }
  asm { mov ax, ds; mov dseg, ax }
  stream->level = 0;
  stream->bsize = size;
  stream->flags = (uint16_t)((stream->flags & 0xfff3) | 0x0004);
  if (mode != 0) {
    stream->flags |= 0x0008;
  }
  stream->buffer = ((uint32_t)dseg << 16) | (uint16_t)buf;
  stream->curp = stream->buffer;
  return 0;
}


/* 1000:2c3f */

uint16_t __cdecl16near sst_printf_strputn(char *dest,char *src,uint16_t n)

{
  uint16_t uVar1;
  
  uVar1 = (uint16_t)((ulong)dest >> 0x10);
  memcpy((char *)CONCAT22(*(uint16_t *)((char *)dest + 2),*(char **)dest),
         (char *)CONCAT22(n,(*(uint16_t *)((uint8_t *)&(src) + 2))),(word)(char *)src);
  *(char **)dest = (char *)src + *(int *)dest;
  **(undefined1 **)dest = 0;
  return (uint16_t)(char *)src;
}



/* 1000:2c7f */

void __cdecl16far _sst_printf(char *buf,char *fmt,...)

{
  *buf = '\0';
  __vprinter();
  return;
}



/* 1000:2ca1 */

int16_t __cdecl16far st_vsst_printf(char *buf,char *fmt,uint16_t ap)

{
  char **ppcVar1;
  
  *buf = '\0';
  ppcVar1 = &buf;
  __vprinter();
  return (int16_t)ppcVar1;
}



/* 1000:2cc2 */

/* Basically strcat with far operands */

/* 1000:2dba */

char * __cdecl16far __fstrncpy(char *dst,char *src,uint16_t n)

{
  char *pcVar1;
  char *pcVar2;
  uint16_t uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  uint16_t uVar7;
  uint16_t uVar8;
  
  uVar7 = (uint16_t)((ulong)src >> 0x10);
  pcVar5 = (char *)src;
  uVar3 = n;
  pcVar6 = pcVar5;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar1 = pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar1 != '\0');
  uVar8 = (uint16_t)((ulong)dst >> 0x10);
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


