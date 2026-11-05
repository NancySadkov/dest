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
  brect_t *pbr;
  undefined2 uVar1;
  
  if (CFG_Mice != 0) {
    uVar1 = (undefined2)((ulong)br >> 0x10);
    pbr = (brect_t *)br;
    if ((((pbr->seg == 0xa000) &&
         (MiceNeedsUpdate = 1,
         br->x <= (int)((MiceX + *(int *)(MiceIndex * 2 + 0x4be)) - *(int *)(MiceIndex * 2 + 0x4ce))
         )) && (pbr->y <= (int)((MiceY + *(int *)(MiceIndex * 2 + 0x4c6)) -
                               *(int *)(MiceIndex * 2 + 0x4d6)))) &&
       ((((int)(MiceX - *(int *)(MiceIndex * 2 + 0x4ce)) <= pbr->w &&
         ((int)(MiceY - *(int *)(MiceIndex * 2 + 0x4d6)) <= pbr->h)) &&
        (MiceFlag = 0, MiceProcessed != '\0')))) {
      dst_x = MiceX - *(int *)(MiceIndex * 2 + 0x4ce);
      dst_y = MiceY - *(int *)(MiceIndex * 2 + 0x4d6);
      if (dst_x < 0) {
        dst_x = 0;
      }
      if (dst_y < 0) {
        dst_y = 0;
      }
      miceBlitAtSeg(0xa000,(far_t)0x224a0000,dst_x,dst_y);
      MiceProcessed = '\0';
    }
  }
  return;
}



/* 3338:00fe */

/* Saves the area covered by mice */

void __cdecl16far miceSaveArea(uint x,uint y,brect_t *br)

{
  uint8_t *dst;
  brect_t *pbr;
  uint j;
  undefined2 uVar1;
  uint8_t *src;
  uint h;
  uint16_t w;
  int iStack_a;
  int iStack_8;
  uint sy;
  uint sx;
  
  if ((uint)br->x < x) {
    sx = x;
  }
  else {
    sx = br->x;
  }
  uVar1 = (undefined2)((ulong)br >> 0x10);
  pbr = (brect_t *)br;
  if ((uint)pbr->y < y) {
    sy = y;
  }
  else {
    sy = pbr->y;
  }
  if (x + 0x10 < (uint)pbr->w) {
    iStack_8 = x + 0x10;
  }
  else {
    iStack_8 = pbr->w;
  }
  if (y + 0x10 < (uint)pbr->h) {
    iStack_a = y + 0x10;
  }
  else {
    iStack_a = pbr->h;
  }
  if (((int)sx <= iStack_8) && ((int)sy <= iStack_a)) {
    src = (uint8_t *)(sx + sy * 0x140);
    dst = (uint8_t *)(((sy - y) * 0x11 + sx) - x);
    w = (iStack_8 - sx) + 1;
    h = (iStack_a - sy) + 1;
    if (0x11 < w) {
      w = 0x11;
    }
    if (0x11 < h) {
      h = 0x11;
    }
    for (j = 0; j < h; j = j + 1) {
      memcpy(dst,src,w);
      src = src + 0x140;
      dst = dst + 0x11;
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
  int dst_x;
  int dst_y;
  brect_t *pbr;
  undefined2 uVar1;
  far_t src;
  
  if (CFG_Mice != 0) {
    uVar1 = (undefined2)((ulong)br >> 0x10);
    pbr = (brect_t *)br;
    if (pbr->seg == 0xa000) {
      miceUpdate();
      if (MiceProcessed == '\0') {
        videoMiceEvent(MiceX << 1,MiceY,0);
      }
    }
    else {
      MiceNeedsUpdate = 1;
      dst_x = MiceX - *(int *)(MiceIndex * 2 + 0x4ce);
      dst_y = MiceY - *(int *)(MiceIndex * 2 + 0x4d6);
      if (dst_x < 0) {
        dst_x = 0;
      }
      if (dst_y < 0) {
        dst_y = 0;
      }
      if ((((br->x <= dst_x + 0x10) && (pbr->y <= dst_y + 0x10)) && (dst_x <= pbr->w)) &&
         ((dst_y <= pbr->h && (MiceProcessed != '\0')))) {
        miceSaveArea(dst_x,dst_y,br);
        src.seg = *(uint16_t *)((int)&MicePtrs.seg + MiceIndex * 4);
        src.ofs = ((far_t *)&MicePtrs + MiceIndex)->ofs;
        miceBlitAtSeg(pbr->seg,src,dst_x,dst_y);
      }
    }
  }
  return;
}



/* 3338:034a */

void __cdecl16far miceInit(void)

{
  bool error;
  undefined2 unaff_BP;
  
  printf("\r",unaff_BP);
  if (CFG_Mice != 0) {
    error = miceInitDriver();
    if (error) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x84);
    }
    MiceX = 0;
    MiceY = 0;
  }
  return;
}



/* 3338:0388 */

byte __cdecl16far init2_3338_0388(uint16_t *param_1,uint16_t *param_2)

{
  byte bVar1;
  
  ovr_audio_3a5b_0000();
  if (CFG_Mice == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = init2_3338_0415();
    if (MiceClick == '\0') {
      *param_1 = MiceX;
      *param_2 = MiceY;
    }
    else {
      *param_1 = MiceClickX;
      *param_2 = MiceClickY;
      bVar1 = bVar1 | 1;
      MiceClick = '\0';
    }
  }
  return bVar1;
}



/* 3338:0401 */

void __cdecl16far init2_3338_0401(void)

{
  DAT_2000_ccaf = 0;
  DAT_2000_ccae = 0;
  ovr_miceButton0PressStates();
  return;
}



/* 3338:0415 */

uint __cdecl16far init2_3338_0415(void)

{
  uint16_t uVar1;
  
  uVar1 = ovr_miceButton0PressStates();
  if ((uVar1 & 2) != 0) {
    DAT_2000_ccaf = 1;
  }
  if ((uVar1 & 4) != 0) {
    DAT_2000_ccae = 1;
  }
  return uVar1 & 1;
}



/* 3338:043e */

void __cdecl16far init2_3338_043e(void)

{
  MiceProcessed = 0;
  return;
}


