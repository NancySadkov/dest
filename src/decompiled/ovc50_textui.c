/*
 * ovc50_textui.c - recovered from STRONG.EXE
 * memory block: OVC50_textui.c
 * range: 8adb:0000 - 8adb:017f
 * functions: 3
 */
#include "recovered.h"


/* 8adb:0000 */

/* [R4] calls ovr_blitText */

void __cdecl16far ovc50_usesBlitText(char *text,uint16_t widths)

{
  uint uVar1;
  size_t sVar2;
  undefined2 unaff_SI;
  char *in_stack_00000004;
  
  TextBlitY = 0xc;
  while( true ) {
    TextBlitX = 0x13;
    if (199 < TextBlitY + 9) {
      TextBlitX = 0x13;
      return;
    }
    uVar1 = ovr_blitText((char *)CONCAT22(Font03.ofs,(char *)text),(byte *)CONCAT22(0xd7,Font03.seg)
                         ,0xed,(uint8_t)unaff_SI,in_stack_00000004);
    sVar2 = strlen((char *)CONCAT22((char *)text,in_stack_00000004));
    if (sVar2 <= uVar1) break;
    in_stack_00000004 = in_stack_00000004 + uVar1;
    TextBlitY = TextBlitY + 0xb;
  }
  return;
}



/* 8adb:0083 */

/* [R4] calls ovr_stshLoadGfx */

void __cdecl16far ovc50_usesStshLoadGfx(byte gfxIndex)

{
  int iVar1;
  undefined4 uVar2;
  stg_tmp_t *widths;
  char *pcVar3;
  uint16_t unaff_SI;
  far_t handle;
  
  pcVar3 = (char *)"puppetmaker" + 3;
  handle.seg = unaff_SI;
  handle.ofs = *(uint16_t *)((uint)gfxIndex * 4 + -0x6c6e);
  widths = ovr_stshLoadGfx(handle,*(undefined2 *)((uint)gfxIndex * 4 + -0x6c70));
  uVar2 = *(undefined4 *)((uint)gfxIndex * 4 + -0x6c70);
  iVar1 = *(int *)((int)uVar2 + 5);
  if (iVar1 != 0) {
    widths->cmap[iVar1 + -1] = 0x0;
    ovc50_usesBlitText((char *)CONCAT22(handle.seg,pcVar3),(uint16_t)widths);
  }
  return;
}



/* 8adb:00f1 */

/* WARNING: Variable defined which should be unmapped: tabPtrs */
/* [R4] calls ovr_uiInputText */

void __cdecl16far ovc50_usesUiInputText(void)

{
  far_t entries;
  char *pcVar1;
  uint16_t unaff_SS;
  far_t dst;
  uint8_t tabPtrs;
  byte bStack_5;
  char cStack_4;
  char cStack_3;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&tabPtrs;
  F_SCOPY(far_from_u32((uint32_t)(0x241084a8)),dst);
  bStack_5 = 0;
  do {
    ovr_manage_openTalkWindow();
    ovc50_usesStshLoadGfx(bStack_5);
    entries.seg = 9;
    entries.ofs = unaff_SS;
    pcVar1 = ovr_uiInputText(entries,0,far_from_u32((uint32_t)(0x0)),tabPtrs,&tabPtrs);
    cStack_3 = (char)pcVar1;
    if ((cStack_3 == '\t') || (cStack_3 == '\0')) {
      cStack_4 = '\x01';
    }
    else {
      cStack_4 = '\0';
      bStack_5 = cStack_3 - 1;
    }
  } while (cStack_4 == '\0');
  return;
}


