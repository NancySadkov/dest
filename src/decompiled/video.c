/*
 * video.c - recovered from STRONG.EXE
 * memory block: 138e_TEXT_video
 * range: 13aa:000b - 13aa:0591
 * functions: 6
 */
#include "recovered.h"


/* 13aa:000b */

undefined2 __cdecl16far video_13aa_000b(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if ((((param_2 + 7U < *(uint *)((param_1 + -0xc) * 2 + 0x34c)) &&
       (*(uint *)((param_1 + -0xc) * 2 + 0x34c) <= param_2 + 0x39U)) && (8 < param_1)) &&
     (param_1 < 0xc9)) {
    uVar1 = 0x1601;
  }
  else {
    uVar1 = 0x1600;
  }
  return uVar1;
}



/* 13aa:005b */

int __cdecl16far video_13aa_005b(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  while( true ) {
    if ((int)(uint)AgntCount <= iVar5) {
      return -1;
    }
    uVar1 = *(undefined2 *)(iVar5 * 0x34 + 0x15);
    piVar4 = (int *)(*(int *)(iVar5 * 0x34 + 0x13) + (uint)*(byte *)(iVar5 * 0x34 + 0x12) * 4);
    iVar2 = piVar4[1];
    iVar3 = *piVar4;
    if (((((*(int *)(iVar5 * 0x34 + 0x26) - *(int *)(iVar3 + 0x17)) + -0xc <= param_1) &&
         (param_1 <= *(int *)(iVar5 * 0x34 + 0x26) + *(int *)(iVar3 + 0x17) + -0xc)) &&
        ((*(int *)(iVar5 * 0x34 + 0x28) - *(int *)(iVar3 + 0xd)) + -7 <= param_2)) &&
       (param_2 <= *(int *)(iVar5 * 0x34 + 0x28) + -7)) break;
    iVar5 = iVar5 + 1;
  }
  return iVar5;
}



/* 13aa:0165 */

uint8_t __cdecl16far video_13aa_0165(void)

{
  uint8_t uVar1;
  char cVar2;
  int iVar3;
  
  if (MiceUnkState == '\0') {
    uVar1 = 0x0;
  }
  else if ((((DAT_2410_00e4 < 0xc) || (0xde < DAT_2410_00e4)) || (DAT_2410_00e6 < 7)) ||
          (0x96 < DAT_2410_00e6)) {
    if (((DAT_2410_00e4 < 0xef) || (0x134 < DAT_2410_00e4)) ||
       ((DAT_2410_00e6 < 7 || (0x36 < DAT_2410_00e6)))) {
      uVar1 = 0x0;
    }
    else {
      uVar1 = 0x3;
    }
  }
  else if (GOngoingBattle == '\0') {
    iVar3 = video_13aa_005b(DAT_2410_00e4 - 0xc,DAT_2410_00e6 - 7);
    if (iVar3 == -1) {
      cVar2 = video_13aa_000b(DAT_2410_00e4 - 0xc,DAT_2410_00e6 - 7);
      if (cVar2 == '\0') {
        uVar1 = 0x3;
      }
      else {
        uVar1 = 0x1;
      }
    }
    else {
      uVar1 = 0x2;
    }
  }
  else {
    uVar1 = 0x3;
  }
  return uVar1;
}



/* 13aa:0266 */

void __cdecl16far video_13aa_0266(undefined2 param_1,int param_2,int param_3)

{
  int iVar1;
  uint8_t *dst;
  uint uStack_8;
  uint uStack_6;
  uint16_t uStack_4;
  
  iVar1 = 0;
  dst = (uint8_t *)0x0;
  uStack_4 = 0x140 - param_2;
  uStack_6 = 200 - param_3;
  if (0x11 < uStack_4) {
    uStack_4 = 0x11;
  }
  if (0x11 < uStack_6) {
    uStack_6 = 0x11;
  }
  for (uStack_8 = 0; uStack_8 < uStack_6; uStack_8 = uStack_8 + 1) {
    memcpy(dst,(uint8_t *)(param_2 + param_3 * 0x140 + iVar1),uStack_4);
    iVar1 = iVar1 + 0x140;
    dst = dst + 0x11;
  }
  return;
}



/* 13aa:02ec */

void __cdecl16far miceBlitAtSeg(uint16_t dst_seg,far_t src,int16_t dst_x,int16_t dst_y)

{
  far_t src_00;
  int dofs;
  int sofs;
  far_t dst;
  undefined2 y;
  undefined2 h;
  undefined2 w;
  
  dofs = 0;
  sofs = 0;
  w = 0x140 - dst_x;
  h = 200 - dst_y;
  if (0x11 < w) {
    w = 0x11;
  }
  if (0x11 < h) {
    h = 0x11;
  }
  for (y = 0; y < h; y = y + 1) {
    src_00.seg = src.seg;
    src_00.ofs = src.ofs + sofs;
    dst.seg = dst_seg;
    dst.ofs = dst_x + dst_y * 0x140 + dofs;
    blitTillAlpha(dst,src_00,w);
    dofs = dofs + 0x140;
    sofs = sofs + 0x11;
  }
  return;
}



/* 13aa:0372 */

void __cdecl16far videoMiceEvent(uint16_t x,uint16_t y,uint16_t mask)

{
  uint16_t uVar1;
  uint16_t uVar2;
  byte bVar3;
  int dx;
  int dy;
  far_t src;
  
  uVar2 = MiceX;
  uVar1 = MiceY;
  if ((mask & 2) == 0) {
    if (MiceNeedsUpdate == '\0') {
      MiceNeedsUpdate = 1;
      MiceX = (int)x >> 1;
      MiceY = y;
      if ((int)MiceX < 0) {
        MiceX = 0;
      }
      if (0x13f < (int)MiceX) {
        MiceX = 0x13f;
      }
      if ((int)y < 0) {
        MiceY = 0;
      }
      if (199 < (int)MiceY) {
        MiceY = 199;
      }
      bVar3 = video_13aa_0165();
      if ((((MiceProcessed == '\0') || (MiceX != uVar2)) || (MiceY != uVar1)) ||
         (bVar3 != MiceIndex)) {
        MiceFlag = 1;
        if (MiceProcessed != '\0') {
          dx = uVar2 - *(int *)(MiceIndex * 2 + 0x4ce);
          dy = uVar1 - *(int *)(MiceIndex * 2 + 0x4d6);
          if (dx < 0) {
            dx = 0;
          }
          if (dy < 0) {
            dy = 0;
          }
          miceBlitAtSeg(0xa000,(far_t)0x224a0000,dx,dy);
        }
        MiceIndex = (uint)bVar3;
        dx = MiceX - *(int *)(MiceIndex * 2 + 0x4ce);
        dy = MiceY - *(int *)(MiceIndex * 2 + 0x4d6);
        if (dx < 0) {
          dx = 0;
        }
        if (dy < 0) {
          dy = 0;
        }
        video_13aa_0266();
        src.seg = *(uint16_t *)((int)&MicePtrs.seg + MiceIndex * 4);
        src.ofs = ((far_t *)&MicePtrs + MiceIndex)->ofs;
        miceBlitAtSeg(0xa000,src,dx,dy);
        MiceProcessed = '\x01';
        MiceNeedsUpdate = '\0';
      }
      else {
        MiceNeedsUpdate = '\0';
      }
    }
  }
  else {
    MiceClickX = MiceX;
    MiceClickY = MiceY;
    MiceClick = 1;
  }
  return;
}


