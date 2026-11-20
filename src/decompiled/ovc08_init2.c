/*
 * ovc08_init2.c - recovered from STRONG.EXE
 * memory block: OVC08_init2.c
 * range: 3338:0000 - 3338:048f
 * functions: 9
 */
#include "recovered.h"


/* 3338:0000 */

void __cdecl16far miceRestoreArea(brect_t *br)

{
  int dst_x;
  int dst_y;
  uint16_t pbr;
  undefined2 in_stack_00000006;
  
  if ((((CFG_Mice != 0) && (br->seg == 0xa000)) &&
      (MiceNeedsUpdate = 1,
      _br->x <= (int)((MiceX + *(int *)(MiceIndex * 2 + 0x4be)) - *(int *)(MiceIndex * 2 + 0x4ce))))
     && (((br->y <= (int)((MiceY + *(int *)(MiceIndex * 2 + 0x4c6)) -
                         *(int *)(MiceIndex * 2 + 0x4d6)) &&
          ((int)(MiceX - *(int *)(MiceIndex * 2 + 0x4ce)) <= br->w)) &&
         (((int)(MiceY - *(int *)(MiceIndex * 2 + 0x4d6)) <= br->h &&
          (MiceFlag = 0, MiceProcessed != '\0')))))) {
    dst_x = MiceX - *(int *)(MiceIndex * 2 + 0x4ce);
    dst_y = MiceY - *(int *)(MiceIndex * 2 + 0x4d6);
    if (dst_x < 0) {
      dst_x = 0;
    }
    if (dst_y < 0) {
      dst_y = 0;
    }
    miceBlitAtSeg(0xa000,far_from_u32((uint32_t)(0x224a0000)),dst_x,dst_y);
    MiceProcessed = '\0';
  }
  return;
}



/* 3338:00fe */

/* Saves the area covered by mice */

void __cdecl16far miceSaveArea(uint x,uint y,brect_t *br)

{
  uint16_t uVar1;
  char *pcVar2;
  uint16_t pbr;
  uint16_t j;
  undefined2 in_stack_0000000a;
  uint16_t src;
  uint16_t h;
  uint16_t w;
  int iStack_a;
  int iStack_8;
  uint16_t sy;
  uint16_t sx;
  
  if ((uint)_br->x < x) {
    sx = x;
  }
  else {
    sx = _br->x;
  }
  if ((uint)br->y < y) {
    sy = y;
  }
  else {
    sy = br->y;
  }
  if (x + 0x10 < (uint)br->w) {
    iStack_8 = x + 0x10;
  }
  else {
    iStack_8 = br->w;
  }
  if (y + 0x10 < (uint)br->h) {
    iStack_a = y + 0x10;
  }
  else {
    iStack_a = br->h;
  }
  if (((int)sx <= iStack_8) && ((int)sy <= iStack_a)) {
    src = sx + sy * 0x140;
    uVar1 = br->seg;
    pcVar2 = (char *)(((sy - y) * 0x11 + sx) - x);
    w = (iStack_8 - sx) + 1;
    h = (iStack_a - sy) + 1;
    if (0x11 < w) {
      w = 0x11;
    }
    if (0x11 < h) {
      h = 0x11;
    }
    for (j = 0; j < h; j = j + 1) {
      memcpy((char *)CONCAT22(0x224a,pcVar2),(char *)CONCAT22(uVar1,src),w);
      src = src + 0x140;
      pcVar2 = pcVar2 + 0x11;
    }
  }
  return;
}



/* 3338:0225 */

void __cdecl16far miceUpdate(void)

{
  if (MiceNeedsUpdate != '\0') {
    ovr_miceSetPosition(MiceX << 1,MiceY);
    MiceNeedsUpdate = '\0';
  }
  return;
}



/* 3338:0256 */

void __cdecl16far miceBlitRect(brect_t *br)

{
  uint16_t dst_x;
  uint16_t dst_y;
  uint16_t pbr;
  undefined2 in_stack_00000006;
  far_t src;
  
  if (CFG_Mice != 0) {
    if (br->seg == 0xa000) {
      miceUpdate();
      if (MiceProcessed == '\0') {
        videoMiceEvent(MiceX << 1,MiceY,0);
      }
    }
    else {
      MiceNeedsUpdate = 1;
      dst_x = MiceX - *(int *)(MiceIndex * 2 + 0x4ce);
      dst_y = MiceY - *(int *)(MiceIndex * 2 + 0x4d6);
      if ((int)dst_x < 0) {
        dst_x = 0;
      }
      if ((int)dst_y < 0) {
        dst_y = 0;
      }
      if ((((_br->x <= (int)(dst_x + 0x10)) && (br->y <= (int)(dst_y + 0x10))) &&
          ((int)dst_x <= br->w)) && (((int)dst_y <= br->h && (MiceProcessed != '\0')))) {
        miceSaveArea(dst_x,dst_y,br);
        src.seg = *(uint16_t *)((int)&MicePtrs.seg + MiceIndex * 4);
        src.ofs = ((far_t *)&MicePtrs + MiceIndex)->ofs;
        miceBlitAtSeg(br->seg,src,dst_x,dst_y);
      }
    }
  }
  return;
}



/* 3338:034a */

void __cdecl16far miceInit(void)

{
  uint8_t error;
  
  printf("\r");
  if (CFG_Mice != 0) {
    error = miceInitDriver();
    if ((bool)error) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x84);
    }
    MiceX = 0;
    MiceY = 0;
  }
  return;
}



/* 3338:0388 */

/* [R6] touches CFG_Mice, MiceClick */

byte __cdecl16far init2_usesCFGMice(uint16_t *mouseX,uint16_t *mouseY)

{
  byte bVar1;
  uint uVar2;
  uint16_t *in_stack_00000008;
  
  ovr_audio_usesLDIV_at_();
  if (CFG_Mice == 0) {
    bVar1 = 0;
  }
  else {
    uVar2 = init2_updateMouseButtons();
    bVar1 = (byte)uVar2;
    if (MiceClick == '\0') {
      *_mouseX = MiceX;
      *in_stack_00000008 = MiceY;
    }
    else {
      *_mouseX = MiceClickX;
      *in_stack_00000008 = MiceClickY;
      bVar1 = bVar1 | 1;
      MiceClick = '\0';
    }
  }
  return bVar1;
}



/* 3338:0401 */

/* [R1] forwards to ovr_miceButton0PressStates */

void __cdecl16far ovr_miceButton0PressStates_entry(void)

{
  rightButtonLatch = 0;
  middleButtonLatch = 0;
  ovr_miceButton0PressStates();
  return;
}



/* 3338:0415 */

/* Latches the secondary mouse buttons into their flags and returns the primary button state. */

uint __cdecl16far init2_updateMouseButtons(void)

{
  uint16_t uVar1;
  
  uVar1 = ovr_miceButton0PressStates();
  if ((uVar1 & 2) != 0) {
    rightButtonLatch = 1;
  }
  if ((uVar1 & 4) != 0) {
    middleButtonLatch = 1;
  }
  return uVar1 & 1;
}



/* 3338:043e */

/* resets MiceProcessed to 0 */

void __cdecl16far clearMiceProcessed(void)

{
  MiceProcessed = 0;
  return;
}


