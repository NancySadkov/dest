/*
 * ovc15.c - recovered from STRONG.EXE
 * memory block: OVC15
 * range: 4207:0000 - 4207:320f
 * functions: 29
 */
#include "recovered.h"


/* 4207:0000 */

spr_t * __cdecl16far stshRleAnims(uint8_t *src,anm_t *anms,uint16_t nanims)

{
  byte bVar1;
  int anim_height;
  int row;
  spr_t *ofs;
  anm_t *panms;
  uint i;
  uint count;
  uint16_t uVar2;
  spr_t *dst;
  frm_t *frm;
  spr_t *pdst;
  undefined2 sdst;
  undefined4 prev_next;
  undefined2 frm_seg;
  uint xx;
  uint exx;
  uint sxx;
  uint j;
  undefined4 p_ow;
  uint ey;
  uint16_t ex;
  uint16_t sy;
  uint16_t sx;
  
  if (0x4e < StshSprIndex) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x36);
  }
  ofs = (spr_t *)StshSprites + StshSprIndex;
  StshSprIndex = StshSprIndex + 1;
  dst = (spr_t *)ovr_mkp((uint16_t)ofs,StshSprites._2_2_);
  _fsetmem(dst,0xb0,0);
  i = 0;
  while( true ) {
    sdst = (undefined2)((ulong)dst >> 0x10);
    pdst = (spr_t *)dst;
    if (nanims <= i) {
      return dst;
    }
    uVar2 = (uint16_t)((ulong)anms >> 0x10);
    panms = (anm_t *)anms;
    if (panms[i].nframes == 0x0) break;
    bVar1 = (panms + i)->frmid;
    prev_next = (far_t *)CONCAT22(sdst,pdst->frames + bVar1);
    pdst->frames[bVar1 - 0x16].seg = uVar2;
    (pdst->frames + (bVar1 - 0x16))->ofs = (uint16_t)(panms + i);
    sx = panms[i].sx;
    sy = panms[i].sy;
    ex = panms[i].ex;
    ey = panms[i].ey;
    anim_height = ey - sy;
    if (anim_height < 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x33);
    }
    p_ow = (uint8_t *)0x0;
    for (j = 0; j < panms[i].nframes; j = j + 1) {
      frm = (frm_t *)ovr_stshRleSub(src,sx,sy,ex,ey,21);
      frm._0_2_ = (frm_t *)frm;
      frm_seg = (undefined2)((ulong)frm >> 0x10);
      ((frm_t *)frm)->type2 = 2;
      ((frm_t *)frm)->x = panms[i].x;
      ((frm_t *)frm)->y = panms[i].y;
      *(undefined2 *)((int)prev_next + 2) = frm_seg;
      prev_next->ofs = (uint16_t)(frm_t *)frm;
      prev_next = (far_t *)CONCAT22(frm_seg,&((frm_t *)frm)->next);
      if ((panms[i].flags & 1) == 0) {
        ((frm_t *)frm)->ow = panms[i].ow;
      }
      else {
        row = ey * 0x140 + 0x140;
        if (j == 0) {
          count = 0;
          xx = sx;
          while (count < 2) {
            if (ex + row < xx) {
                    /* WARNING: Subroutine does not return */
              ovr_stExit(9);
            }
            if (((uint8_t *)src)[xx + row] == 0xfe) {
              if (count == 0) {
                sxx = xx;
              }
              else {
                exx = xx;
              }
              count = count + 1;
            }
            xx = xx + 1;
          }
          p_ow = (uint8_t *)CONCAT22(frm_seg,&((frm_t *)frm)->ow);
        }
        else {
          xx = sx;
          while (((uint8_t *)src)[xx + row] != 0xfe) {
            if (ex + row < xx) {
                    /* WARNING: Subroutine does not return */
              ovr_stExit(9);
            }
            xx = xx + 1;
          }
          ((frm_t *)frm)->ow = (char)exx - (char)xx;
          exx = xx;
        }
      }
      frm->type4 = 4;
      *(undefined2 *)((int)&((frm_t *)frm)->next + 2) = 0;
      *(undefined2 *)&((frm_t *)frm)->next = 0;
      sy = sy + panms[i].fh;
      ey = ey + panms[i].fh;
      if (199 < ey) {
        sy = panms[i].sy % (int)(uint)panms[i].fh;
        ey = sy + anim_height;
        sx = sx + panms[i].fw;
        ex = ex + panms[i].fw;
        sxx = sxx + panms[i].fw;
        exx = exx + panms[i].fw;
      }
    }
    if ((uint8_t *)p_ow != (uint8_t *)0x0 || p_ow._2_2_ != 0) {
      *p_ow = (char)exx - (char)sxx;
    }
    i = i + 1;
  }
  return dst;
}



/* 4207:03ac */

far_t __cdecl16far stshSprite(int16_t file_id,anm_t *anms,uint16_t nanims,bool grab)

{
  uint16_t uVar1;
  far_t pixels;
  far_t handle;
  undefined2 uVar2;
  spr_t *spr;
  stg_tmp_t *fVar6;
  
  if (grab) {
    fVar6 = ovr_grabLbm(file_id,0,0);
    fVar6._0_2_ = (stg_tmp_t *)fVar6;
    uVar2 = (undefined2)((ulong)fVar6 >> 0x10);
    pixels.seg = (((stg_tmp_t *)fVar6)->aptr).seg;
    pixels.ofs = (&((stg_tmp_t *)fVar6)->aptr)->ofs;
    ovr_grabRemap(pixels,0xff,0x0);
    spr = stshRleAnims((uint8_t *)
                       CONCAT22((((stg_tmp_t *)fVar6)->aptr).seg,
                                (uint8_t *)(&((stg_tmp_t *)fVar6)->aptr)->ofs),anms,nanims);
    uVar1 = (((stg_tmp_t *)fVar6)->bptr).seg;
    handle.seg._0_1_ = (char)uVar1;
    handle.ofs = (&((stg_tmp_t *)fVar6)->bptr)->ofs;
    handle.seg._1_1_ = (char)(uVar1 >> 8);
    ovr_stshFree(handle);
    ovr_stshFree((far_t)fVar6);
    stshStoreSprite(spr,anms,nanims);
  }
  else {
    spr = ovr_stshSpriteStub(anms,nanims);
  }
  return (far_t)spr;
}



/* 4207:0462 */

void __cdecl16far allocSprSeqs(void)

{
  StshSprites = ovr_stshAlloc(0x3650);
  return;
}



/* 4207:047b */

void __cdecl16far stshInitSprites(bool grab)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  stg_tmp_t *data;
  int i;
  int j;
  far_t fVar4;
  stg_tmp_t *gfx;
  uint8_t *data_00;
  cte_t *pcVar5;
  uint32_t uVar6;
  undefined2 uStack_4;
  
  StshSprIndex = 0;
  SprProjectiles = stshSprite(37,EntityTypeSeg,9,grab);
  i = 0;
  while( true ) {
    if (0x29 < i) break;
    fVar4 = stshSprite(*(int16_t *)((int)AgntGs[0].sprfls + i * 0x95),
                       (anm_t *)CONCAT22(*(undefined2 *)((int)&AgntGs[0].anms + 2 + i * 0x95),
                                         (anm_t *)*(undefined2 *)((int)&AgntGs[0].anms + i * 0x95)),
                       (uint)*(byte *)((int)&AgntGs[0].nanims + i * 0x95),grab);
    *(uint16_t *)((int)AgntGs[0].sprs + 2 + i * 0x95) = fVar4.seg;
    *(uint16_t *)((int)AgntGs[0].sprs + i * 0x95) = fVar4.ofs;
    if (*(int *)((int)AgntGs[0].sprfls + 2 + i * 0x95) == 0) {
      uVar1 = *(undefined2 *)((int)AgntGs[0].sprs + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].sprs + 6 + i * 0x95) =
           *(undefined2 *)((int)AgntGs[0].sprs + 2 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].sprs + 4 + i * 0x95) = uVar1;
    }
    else {
      fVar4 = stshSprite(*(int16_t *)((int)AgntGs[0].sprfls + 2 + i * 0x95),
                         (anm_t *)CONCAT22(*(undefined2 *)((int)&AgntGs[0].anms + 2 + i * 0x95),
                                           (anm_t *)*(undefined2 *)((int)&AgntGs[0].anms + i * 0x95)
                                          ),(uint)*(byte *)((int)&AgntGs[0].nanims + i * 0x95),grab)
      ;
      *(uint16_t *)((int)AgntGs[0].sprs + 6 + i * 0x95) = fVar4.seg;
      *(uint16_t *)((int)AgntGs[0].sprs + 4 + i * 0x95) = fVar4.ofs;
    }
    if (*(int *)((int)AgntGs[0].sprfls + 4 + i * 0x95) == 0) {
      uVar1 = *(undefined2 *)((int)AgntGs[0].sprs + 4 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].sprs + 10 + i * 0x95) =
           *(undefined2 *)((int)AgntGs[0].sprs + 6 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].sprs + 8 + i * 0x95) = uVar1;
    }
    else {
      fVar4 = stshSprite(*(int16_t *)((int)AgntGs[0].sprfls + 4 + i * 0x95),
                         (anm_t *)CONCAT22(*(undefined2 *)((int)&AgntGs[0].anms + 2 + i * 0x95),
                                           (anm_t *)*(undefined2 *)((int)&AgntGs[0].anms + i * 0x95)
                                          ),(uint)*(byte *)((int)&AgntGs[0].nanims + i * 0x95),grab)
      ;
      *(uint16_t *)((int)AgntGs[0].sprs + 10 + i * 0x95) = fVar4.seg;
      *(uint16_t *)((int)AgntGs[0].sprs + 8 + i * 0x95) = fVar4.ofs;
    }
    for (j = 0; j < 3; j = j + 1) {
      if (*(int *)((int)AgntGs[0].sprfls + 6 + i * 0x95 + j * 2) == 0) {
        iVar2 = i * 0x95 + j * 4;
        uVar1 = *(undefined2 *)((int)AgntGs[0].sprs + iVar2);
        iVar3 = i * 0x95 + j * 4;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar3) =
             *(undefined2 *)((int)AgntGs[0].sprs + 2 + iVar2);
        *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar3) = uVar1;
      }
      else {
        fVar4 = stshSprite(*(int16_t *)((int)AgntGs[0].sprfls + 6 + i * 0x95 + j * 2),
                           (anm_t *)CONCAT22(*(undefined2 *)((int)&AgntGs[0].anms + 2 + i * 0x95),
                                             (anm_t *)*(undefined2 *)
                                                       ((int)&AgntGs[0].anms + i * 0x95)),
                           (uint)*(byte *)((int)&AgntGs[0].nanims + i * 0x95),grab);
        iVar2 = i * 0x95 + j * 4;
        *(uint16_t *)((int)AgntGs[0].sprs + 0xe + iVar2) = fVar4.seg;
        *(uint16_t *)((int)AgntGs[0].sprs + 0xc + iVar2) = fVar4.ofs;
      }
    }
    for (j = 0; j < 6; j = j + 1) {
      if (*(int *)((int)AgntGs[0].prtfls + i * 0x95 + j * 2) != 0) {
        if (grab) {
          gfx = ovr_grabLbm(*(int16_t *)((int)AgntGs[0].prtfls + i * 0x95 + j * 2),0,0);
          data = (stg_tmp_t *)gfx;
          uStack_4 = (undefined2)((ulong)gfx >> 0x10);
          ovr_stshUniqueColorsRemap(gfx);
          fVar4.seg = (data->aptr).seg;
          fVar4.ofs = (&data->aptr)->ofs;
          data_00 = (uint8_t *)ovr_stshRleType2(fVar4,0,0,114,103,0,0);
          pcVar5 = ovr_stshStoreFile(data_00);
          iVar2 = i * 0x95 + j * 4;
          *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar2) = (int)((ulong)pcVar5 >> 0x10);
          *(undefined2 *)((int)AgntGs[0].prts + iVar2) = (cte_t *)pcVar5;
          uVar6 = ovr_stshWrite(data->cmap,0x300);
          iVar2 = i * 0x95 + j * 4;
          *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar2) = (int)(uVar6 >> 0x10);
          *(undefined2 *)((int)AgntGs[0].prtpals + iVar2) = (int)uVar6;
          ovr_stgFreeTmp(gfx);
        }
        else {
          fVar4 = ovr_stshAllocStub();
          iVar2 = i * 0x95 + j * 4;
          *(uint16_t *)((int)AgntGs[0].prts + 2 + iVar2) = fVar4.seg;
          *(uint16_t *)((int)AgntGs[0].prts + iVar2) = fVar4.ofs;
          fVar4 = ovr_stshAllocStub();
          iVar2 = i * 0x95 + j * 4;
          *(uint16_t *)((int)AgntGs[0].prtpals + 2 + iVar2) = fVar4.seg;
          *(uint16_t *)((int)AgntGs[0].prtpals + iVar2) = fVar4.ofs;
        }
      }
    }
    if ((*(int *)((int)AgntGs[0].prts + 4 + i * 0x95) == 0 &&
         *(int *)((int)AgntGs[0].prts + 6 + i * 0x95) == 0) &&
       (*(int *)((int)AgntGs[0].prts + i * 0x95) != 0 ||
        *(int *)((int)AgntGs[0].prts + 2 + i * 0x95) != 0)) {
      uVar1 = *(undefined2 *)((int)AgntGs[0].prts + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].prts + 6 + i * 0x95) =
           *(undefined2 *)((int)AgntGs[0].prts + 2 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].prts + 4 + i * 0x95) = uVar1;
      uVar1 = *(undefined2 *)((int)AgntGs[0].prtpals + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].prtpals + 6 + i * 0x95) =
           *(undefined2 *)((int)AgntGs[0].prtpals + 2 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].prtpals + 4 + i * 0x95) = uVar1;
    }
    for (j = 2; j < 6; j = j + 2) {
      iVar2 = i * 0x95 + j * 4;
      if ((*(int *)((int)AgntGs[0].prts + 4 + iVar2) == 0 &&
           *(int *)((int)AgntGs[0].prts + 6 + iVar2) == 0) &&
         (iVar2 = i * 0x95 + j * 4,
         *(int *)((int)AgntGs[0].prtfls + 8 + iVar2) != 0 ||
         *(int *)((int)AgntGs[0].prtfls + 10 + iVar2) != 0)) {
        iVar2 = i * 0x95 + j * 4;
        uVar1 = *(undefined2 *)((int)AgntGs[0].prtfls + 8 + iVar2);
        iVar3 = i * 0x95 + j * 4;
        *(undefined2 *)((int)AgntGs[0].prts + 6 + iVar3) =
             *(undefined2 *)((int)AgntGs[0].prtfls + 10 + iVar2);
        *(undefined2 *)((int)AgntGs[0].prts + 4 + iVar3) = uVar1;
        iVar2 = i * 0x95 + j * 4;
        uVar1 = *(undefined2 *)((int)AgntGs[0].prts + 0x14 + iVar2);
        iVar3 = i * 0x95 + j * 4;
        *(undefined2 *)((int)AgntGs[0].prtpals + 6 + iVar3) =
             *(undefined2 *)((int)AgntGs[0].prts + 0x16 + iVar2);
        *(undefined2 *)((int)AgntGs[0].prtpals + 4 + iVar3) = uVar1;
      }
      iVar2 = i * 0x95 + j * 4;
      if ((*(int *)((int)AgntGs[0].prts + iVar2) == 0 &&
           *(int *)((int)AgntGs[0].prts + 2 + iVar2) == 0) &&
         (iVar2 = i * 0x95 + j * 4,
         *(int *)((int)AgntGs[0].prtfls + 4 + iVar2) != 0 ||
         *(int *)((int)AgntGs[0].prtfls + 6 + iVar2) != 0)) {
        iVar2 = i * 0x95 + j * 4;
        uVar1 = *(undefined2 *)((int)AgntGs[0].prtfls + 4 + iVar2);
        iVar3 = i * 0x95 + j * 4;
        *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar3) =
             *(undefined2 *)((int)AgntGs[0].prtfls + 6 + iVar2);
        *(undefined2 *)((int)AgntGs[0].prts + iVar3) = uVar1;
        iVar2 = i * 0x95 + j * 4;
        uVar1 = *(undefined2 *)((int)AgntGs[0].prts + 0x10 + iVar2);
        iVar3 = i * 0x95 + j * 4;
        *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar3) =
             *(undefined2 *)((int)AgntGs[0].prts + 0x12 + iVar2);
        *(undefined2 *)((int)AgntGs[0].prtpals + iVar3) = uVar1;
      }
    }
    i = i + 1;
  }
  return;
}



/* 4207:0b05 */

void __cdecl16far agnt_clear(void)

{
  if (!AgntFlag1) {
    AgntCount = 0;
    _fsetmem(AgntArrayA,0x41a,0);
    _fsetmem(AgntArrayB,0x41a,0);
  }
  AgntFlag2 = true;
  return;
}



/* 4207:0b55 */

void __cdecl16far OVC15_4207_0b55(uint param_1)

{
  uint uVar1;
  
  if (param_1 >> 1 < 0x69) {
    for (uVar1 = 0; uVar1 < 10; uVar1 = uVar1 + 1) {
      *(undefined1 *)(uVar1 * 0x69 + (param_1 >> 1) + 0x8fa) = 0xff;
    }
  }
  return;
}



/* 4207:0b88 */

void __cdecl16far OVC15_4207_0b88(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    *(undefined1 *)(iVar1 * 0x34 + 0x2d) = 0;
  }
  return;
}



/* 4207:0bb7 */

void __cdecl16far OVC15_4207_0bb7(void)

{
  uint uVar1;
  uint16_t uVar2;
  int iVar3;
  int iVar4;
  uint16_t uVar5;
  undefined2 unaff_SS;
  uint local_4ba [600];
  uint uStack_a;
  uint uStack_8;
  int iStack_6;
  uint uStack_4;
  
  OVC15_4207_0b88();
  iStack_6 = 0;
  for (uStack_4 = 0; uStack_4 < EntityCount; uStack_4 = uStack_4 + 1) {
    uVar5 = Entities.seg;
    uVar2 = Entities.ofs;
    if (((GfxRndSeed - 2U <= *(uint *)(uVar2 + uStack_4 * 0x37)) &&
        (*(uint *)(uVar2 + uStack_4 * 0x37) <= GfxRndSeed + 1U)) &&
       (*(int *)(uVar2 + uStack_4 * 0x37 + 2) == GfxRndSeed2)) {
      local_4ba[iStack_6] = uStack_4;
      iStack_6 = iStack_6 + 1;
    }
  }
  iVar4 = 0;
  iVar3 = 0;
  while ((iVar3 < iStack_6 || (iVar4 < iStack_6))) {
    while( true ) {
      uVar2 = Entities.ofs;
      uVar5 = Entities.seg;
      if ((iStack_6 <= iVar4) ||
         (*(char *)((int)(char **)GMenuStrings +
                   (uint)*(byte *)(uVar2 + local_4ba[iVar4] * 0x37 + 0xd) * 0x95 + 0x1f) == '\x01'))
      break;
      iVar4 = iVar4 + 1;
    }
    while ((iVar3 < iStack_6 &&
           (*(char *)((int)(char **)GMenuStrings +
                     (uint)*(byte *)(uVar2 + local_4ba[iVar3] * 0x37 + 0xd) * 0x95 + 0x1f) != '\0'))
          ) {
      iVar3 = iVar3 + 1;
    }
    if (iVar4 < iStack_6) {
      uStack_8 = (*(byte *)(uVar2 + local_4ba[iVar4] * 0x37 + 0xe) + 0xf) / 0x10;
    }
    else {
      uStack_8 = 0;
    }
    if (iVar3 < iStack_6) {
      uStack_a = (*(byte *)(uVar2 + local_4ba[iVar3] * 0x37 + 0xe) + 0xf) / 0x10;
    }
    else {
      uStack_a = 0;
    }
    while ((uStack_8 != 0 || (uStack_a != 0))) {
      if (uStack_8 != 0) {
        OVC15_4207_2301(local_4ba[iVar4],0,AgntFlag1 == false);
        uStack_8 = uStack_8 - 1;
      }
      if (uStack_a != 0) {
        OVC15_4207_2301(local_4ba[iVar3],0,AgntFlag1 == false);
        uStack_a = uStack_a - 1;
      }
    }
    if (iVar4 < iStack_6) {
      iVar4 = iVar4 + 1;
    }
    if (iVar3 < iStack_6) {
      iVar3 = iVar3 + 1;
    }
  }
  for (uStack_4 = 0; uVar1 = uStack_4, (int)uStack_4 < (int)(uint)AgntCount; uStack_4 = uStack_4 + 1
      ) {
    if (*(char *)(uStack_4 * 0x34 + 0x2d) == '\0') {
      uStack_4 = uStack_4 + -1;
      ovr_OVC41_6a8f_0256(uVar1,0);
    }
  }
  AgntFlag1 = true;
  return;
}



/* 4207:0e17 */

void __cdecl16far OVC15_4207_0e17(uint param_1)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint16_t uVar6;
  int iVar7;
  uint uVar8;
  uint16_t uVar9;
  
  if (AgntFlag1) {
    for (uVar8 = 0; uVar8 < AgntCount; uVar8 = uVar8 + 1) {
      if ((*(uint *)(uVar8 * 0x34 + 0x1b) == param_1) && (*(char *)(uVar8 * 0x34 + 0x24) != '\x02'))
      {
        *(undefined1 *)(uVar8 * 0x34 + 0x24) = 2;
        *(undefined2 *)(uVar8 * 0x34 + 6) = 0;
      }
    }
  }
  uVar9 = Entities.seg;
  uVar6 = Entities.ofs;
  iVar4 = *(int *)(uVar6 + param_1 * 0x37 + 8);
  iVar5 = *(int *)(uVar6 + param_1 * 0x37 + 10);
  cVar2 = *(char *)((int)(char **)GMenuStrings +
                   (uint)*(byte *)(uVar6 + param_1 * 0x37 + 0xd) * 0x95 + 0x1f);
  uVar3 = *(undefined1 *)(uVar6 + param_1 * 0x37 + 0x1a);
  if (param_1 < EntityCount - 1U) {
    _fmemmove((uint8_t *)(uVar6 + param_1 * 0x37),(uint8_t *)(uVar6 + (param_1 + 1) * 0x37),
              ((EntityCount + -1) - param_1) * 0x37);
  }
  if (AgntFlag1 != false) {
    for (uVar8 = 0; uVar8 < AgntCount; uVar8 = uVar8 + 1) {
      if (param_1 < *(uint *)(uVar8 * 0x34 + 0x1b)) {
        piVar1 = (int *)(uVar8 * 0x34 + 0x1b);
        *piVar1 = *piVar1 + -1;
        iVar7 = Entities.ofs + *(int *)(uVar8 * 0x34 + 0x1b) * 0x37;
        *(uint16_t *)(uVar8 * 0x34 + 0x19) = Entities.seg;
        *(int *)(uVar8 * 0x34 + 0x17) = iVar7;
      }
    }
  }
  EntityCount = EntityCount + -1;
  if ((cVar2 == '\0') && ((iVar4 != 0 || (iVar5 != 0)))) {
    ovr_attact_3f0b_0941(iVar4,iVar5,uVar3,0,0);
  }
  ovr_attact_3f0b_0c2a();
  return;
}



/* 4207:0ff0 */

uint __cdecl16far OVC15_4207_0ff0(undefined2 param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint16_t uVar4;
  uint uVar5;
  uint16_t uVar6;
  
  uVar2 = ovr_OVC23_55fe_3450(param_1);
  uVar5 = 0;
  uVar3 = uVar2;
  do {
    if (EntityCount <= uVar5) {
      return uVar3 & 0xff00;
    }
    uVar3 = uVar5 * 0x37;
    uVar6 = Entities.seg;
    uVar4 = Entities.ofs;
    if ((((*(byte *)(uVar4 + uVar3 + 0x33) & 2) != 0) &&
        (uVar3 = *(uint *)(uVar4 + uVar5 * 0x37 + 6), uVar3 == param_2)) &&
       (uVar3 = ovr_OVC23_55fe_3450(*(undefined2 *)(uVar4 + uVar5 * 0x37 + 4)), uVar3 == uVar2)) {
      uVar3 = uVar5 * 0x37;
      if ((*(char *)(Entities.ofs + uVar3 + 0x1a) != -1) &&
         (uVar1 = *(undefined4 *)((uint)*(byte *)(Entities.ofs + uVar5 * 0x37 + 0x1a) << 2),
         uVar3 = (uint)*(byte *)((int)uVar1 + 0x3f), uVar3 == 0)) {
        return 1;
      }
    }
    uVar5 = uVar5 + 1;
  } while( true );
}



/* 4207:10a3 */

int __cdecl16far
OVC15_4207_10a3(int param_1,int param_2,int param_3,int param_4,byte param_5,undefined1 param_6,
               byte param_7)

{
  uint *puVar1;
  char *pcVar2;
  undefined2 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint16_t uVar7;
  uint16_t uVar8;
  long lVar9;
  uint uVar10;
  int iStack_6;
  
  if (EntityCount < 0x259) {
    DAT_2410_648e = 1;
    if (DAT_2000_d310 < 2) {
      if (0x21b < EntityCount) {
        OVC15_4207_2d75();
        OVC15_4207_0e17();
        EntityCount = EntityCount - 1;
      }
    }
    else if (599 < EntityCount) {
      OVC15_4207_2d75();
      OVC15_4207_0e17();
      EntityCount = EntityCount - 1;
    }
    _fsetmem((void *)CONCAT22(Entities.seg,(void *)(Entities.ofs + EntityCount * 0x37)),0x37,0);
    *(int *)(Entities.ofs + EntityCount * 0x37 + 4) = param_3;
    *(int *)(Entities.ofs + EntityCount * 0x37 + 6) = param_4;
    if ((param_3 == param_1) && (param_4 == param_2)) {
      *(undefined2 *)(Entities.ofs + EntityCount * 0x37 + 8) = 0;
      *(undefined2 *)(Entities.ofs + EntityCount * 0x37 + 10) = 0;
    }
    else {
      *(int *)(Entities.ofs + EntityCount * 0x37 + 8) = param_3;
      *(int *)(Entities.ofs + EntityCount * 0x37 + 10) = param_4;
    }
    *(int *)(Entities.ofs + EntityCount * 0x37) = param_1;
    *(int *)(Entities.ofs + EntityCount * 0x37 + 2) = param_2;
    *(undefined1 *)(Entities.ofs + EntityCount * 0x37 + 0xc) = 0xff;
    *(byte *)(Entities.ofs + EntityCount * 0x37 + 0xd) = param_5;
    uVar7 = Entities.seg;
    iVar5 = Entities.ofs + EntityCount * 0x37;
    *(undefined2 *)(iVar5 + 0x12) = 0;
    *(undefined2 *)(iVar5 + 0x10) = 100;
    *(undefined2 *)(Entities.ofs + EntityCount * 0x37 + 0x14) = 0;
    *(undefined1 *)(Entities.ofs + EntityCount * 0x37 + 0xe) = param_6;
    *(byte *)(Entities.ofs + EntityCount * 0x37 + 0x1a) = param_7;
    *(undefined1 *)(Entities.ofs + EntityCount * 0x37 + 0x31) =
         *(undefined1 *)((int)&far_t_ARRAY_2410_26f7[6].seg + (uint)param_5 * 0x95);
    *(undefined1 *)(Entities.ofs + EntityCount * 0x37 + 0x32) =
         *(undefined1 *)((int)&far_t_ARRAY_2410_26f7[6].seg + (uint)param_5 * 0x95);
    if (*(char *)((int)*(undefined4 *)((uint)param_7 << 2) + 0x2f) != -1) {
      uVar10 = (uint)*(byte *)((int)&far_t_ARRAY_2410_26f7[6].seg + (uint)param_5 * 0x95);
      cVar4 = ovr_agnt_3b1d_0c1e();
      iStack_6 = uVar10 + (int)cVar4;
      if (iStack_6 < 1) {
        iStack_6 = 1;
      }
      *(undefined1 *)(Entities.ofs + EntityCount * 0x37 + 0x31) = (undefined1)iStack_6;
      *(undefined1 *)(Entities.ofs + EntityCount * 0x37 + 0x32) = (undefined1)iStack_6;
    }
    if (*(char *)((int)(char **)GMenuStrings + (uint)param_5 * 0x95 + 0x1f) == '\0') {
      cVar4 = OVC15_4207_0ff0();
      if (cVar4 == '\0') {
        *(undefined1 *)(Entities.ofs + EntityCount * 0x37 + 0x33) = 2;
      }
    }
    else if ((param_3 == param_1) && (param_4 == param_2)) {
      *(undefined1 *)(Entities.ofs + EntityCount * 0x37 + 0x33) = 2;
    }
    if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].ofs + 1 + (uint)param_5 * 0x95) & 0x1000) == 0) {
      if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].ofs + 1 + (uint)param_5 * 0x95) & 0x2000) == 0)
      {
        lVar9 = 0x8000;
        iVar5 = rand();
        lVar9 = LDIV_at_(CONCAT22((iVar5 >> 0xf) << 1 | (uint)(iVar5 < 0),iVar5 << 1),lVar9);
        if ((int)lVar9 == 0) {
          puVar1 = (uint *)(Entities.ofs + EntityCount * 0x37 + 0x16);
          *puVar1 = *puVar1 | 1;
        }
      }
      else {
        puVar1 = (uint *)(Entities.ofs + EntityCount * 0x37 + 0x16);
        *puVar1 = *puVar1 | 1;
      }
    }
    *(undefined1 *)(Entities.ofs + EntityCount * 0x37 + 0xf) =
         *(undefined1 *)((int)&far_t_ARRAY_2410_26f7[8].seg + (uint)param_5 * 0x95);
    if ((((*(byte *)((int)*(undefined4 *)((uint)param_7 << 2) + 0x5d) & 0x10) != 0) &&
        (*(byte *)((int)&far_t_ARRAY_2410_26f7[8].seg + (uint)param_5 * 0x95) < 5)) &&
       (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)param_5 * 0x95) != -1)) {
      while (*(byte *)(Entities.ofs + EntityCount * 0x37 + 0xf) < 5) {
        cVar4 = OVC15_4207_25dd();
        *(char *)(Entities.ofs + EntityCount * 0x37 + 0x31) =
             *(char *)(Entities.ofs + EntityCount * 0x37 + 0x31) + cVar4;
        *(char *)(Entities.ofs + EntityCount * 0x37 + 0x32) =
             *(char *)(Entities.ofs + EntityCount * 0x37 + 0x32) + cVar4;
        pcVar2 = (char *)(Entities.ofs + EntityCount * 0x37 + 0xf);
        *pcVar2 = *pcVar2 + '\x01';
      }
    }
    uVar7 = Entities.ofs;
    uVar8 = Entities.seg;
    if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)param_5 * 0x95) == -1) {
      iVar5 = (uint)*(byte *)(uVar7 + EntityCount * 0x37 + 0xf) * 4;
      uVar3 = *(undefined2 *)(iVar5 + -4);
      iVar6 = uVar7 + EntityCount * 0x37;
      *(undefined2 *)(iVar6 + 0x12) = *(undefined2 *)(iVar5 + -2);
      *(undefined2 *)(iVar6 + 0x10) = uVar3;
    }
    else {
      iVar5 = (uint)*(byte *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)param_5 * 0x95) * 0x94
              + (uint)*(byte *)(uVar7 + EntityCount * 0x37 + 0xf) * 4;
      uVar3 = *(undefined2 *)(iVar5 + -4);
      iVar6 = uVar7 + EntityCount * 0x37;
      *(undefined2 *)(iVar6 + 0x12) = *(undefined2 *)(iVar5 + -2);
      *(undefined2 *)(iVar6 + 0x10) = uVar3;
    }
    uVar7 = Entities.seg;
    iVar5 = Entities.ofs + EntityCount * 0x37;
    if (*(int *)(iVar5 + 0x10) == 0 && *(int *)(iVar5 + 0x12) == 0) {
      iVar5 = Entities.ofs + EntityCount * 0x37;
      *(undefined2 *)(iVar5 + 0x12) = 0;
      *(undefined2 *)(iVar5 + 0x10) = 100;
    }
    uVar10 = EntityCount;
    EntityCount = EntityCount + 1;
    ovr_attact_3f0b_0c2a();
    if (AgntFlag1 != false) {
      uVar8 = Entities.seg;
      uVar7 = Entities.ofs;
      if (((GfxRndSeed - 2U <= *(uint *)(uVar7 + uVar10 * 0x37)) &&
          (*(uint *)(uVar7 + uVar10 * 0x37) <= GfxRndSeed + 1U)) &&
         (*(int *)(uVar7 + uVar10 * 0x37 + 2) == GfxRndSeed2)) {
        OVC15_4207_2301();
      }
    }
    iVar5 = Entities.ofs + uVar10 * 0x37;
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x26);
}



/* 4207:16a5 */

void __cdecl16far OVC15_4207_16a5(int param_1,byte param_2,char param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint16_t uVar3;
  int iVar4;
  int iVar5;
  uint16_t uVar6;
  int iVar7;
  uint16_t uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  bool bVar11;
  long lVar12;
  
  if (param_3 != -1) {
    DAT_2410_648e = 1;
    iVar5 = Entities.ofs + param_1 * 0x37;
    uVar3 = Entities.seg;
    *(undefined1 *)(iVar5 + 0xc) = 0xff;
    *(byte *)(iVar5 + 0xd) = param_2;
    *(undefined1 *)(iVar5 + 0xf) =
         *(undefined1 *)((int)&far_t_ARRAY_2410_26f7[8].seg + (uint)param_2 * 0x95);
    *(undefined2 *)(iVar5 + 0x12) = 0;
    *(undefined2 *)(iVar5 + 0x10) = 100;
    *(undefined2 *)(iVar5 + 0x14) = 0;
    *(undefined2 *)(iVar5 + 0x16) = 0;
    *(char *)(iVar5 + 0x1a) = param_3;
    *(undefined1 *)(iVar5 + 0x31) =
         *(undefined1 *)((int)&far_t_ARRAY_2410_26f7[6].seg + (uint)param_2 * 0x95);
    *(undefined1 *)(iVar5 + 0x32) =
         *(undefined1 *)((int)&far_t_ARRAY_2410_26f7[6].seg + (uint)param_2 * 0x95);
    lVar12 = 0x8000;
    iVar4 = rand();
    lVar12 = LDIV_at_(CONCAT22((iVar4 >> 0xf) << 1 | (uint)(iVar4 < 0),iVar4 << 1),lVar12);
    if ((int)lVar12 == 0) {
      *(uint *)(iVar5 + 0x16) = *(uint *)(iVar5 + 0x16) | 1;
    }
    ovr_attact_3f0b_0c2a();
    if (AgntFlag1 != false) {
      uVar8 = Entities.seg;
      uVar6 = Entities.ofs;
      if (((GfxRndSeed - 2U <= *(uint *)(uVar6 + param_1 * 0x37)) &&
          (*(uint *)(uVar6 + param_1 * 0x37) <= GfxRndSeed + 1U)) &&
         (*(int *)(uVar6 + param_1 * 0x37 + 2) == GfxRndSeed2)) {
        for (iVar4 = 0; iVar4 < (int)(uint)AgntCount; iVar4 = iVar4 + 1) {
          if (*(int *)(iVar4 * 0x34 + 0x1b) == param_1) {
            *(undefined1 *)(iVar4 * 0x34 + 0xc) = 0xff;
            bVar1 = *(byte *)(iVar5 + 0xd);
            *(undefined2 *)(iVar4 * 0x34 + 0x1f) = 0x195d;
            *(int *)(iVar4 * 0x34 + 0x1d) = (uint)bVar1 * 0x95 + 0x26d6;
            *(undefined1 *)(iVar4 * 0x34 + 0x21) = *(undefined1 *)(iVar5 + 0x31);
            *(undefined1 *)(iVar4 * 0x34 + 0x22) = *(undefined1 *)(iVar5 + 0x32);
            bVar11 = (*(uint *)(iVar5 + 0x16) & 1) != 0;
            if (*(byte *)(iVar5 + 0xf) < 10) {
              if (*(byte *)(iVar5 + 0xf) < 4) {
                uVar2 = *(undefined4 *)(iVar4 * 0x34 + 0x1d);
                uVar9 = (undefined2)((ulong)uVar2 >> 0x10);
                iVar7 = (int)uVar2 + (uint)bVar11 * 0xc;
                uVar10 = *(undefined2 *)(iVar7 + 3);
                *(undefined2 *)(iVar4 * 0x34 + 0x15) = *(undefined2 *)(iVar7 + 5);
                *(undefined2 *)(iVar4 * 0x34 + 0x13) = uVar10;
              }
              else {
                uVar2 = *(undefined4 *)(iVar4 * 0x34 + 0x1d);
                uVar9 = (undefined2)((ulong)uVar2 >> 0x10);
                iVar7 = (int)uVar2 + (uint)bVar11 * 0xc;
                uVar10 = *(undefined2 *)(iVar7 + 7);
                *(undefined2 *)(iVar4 * 0x34 + 0x15) = *(undefined2 *)(iVar7 + 9);
                *(undefined2 *)(iVar4 * 0x34 + 0x13) = uVar10;
              }
            }
            else {
              uVar2 = *(undefined4 *)(iVar4 * 0x34 + 0x1d);
              uVar9 = (undefined2)((ulong)uVar2 >> 0x10);
              iVar7 = (int)uVar2 + (uint)bVar11 * 0xc;
              uVar10 = *(undefined2 *)(iVar7 + 0xb);
              *(undefined2 *)(iVar4 * 0x34 + 0x15) = *(undefined2 *)(iVar7 + 0xd);
              *(undefined2 *)(iVar4 * 0x34 + 0x13) = uVar10;
            }
            *(undefined1 *)(iVar4 * 0x34 + 0xe) = 0xff;
            *(undefined1 *)(iVar4 * 0x34 + 0x2f) =
                 *(undefined1 *)*(undefined4 *)(iVar4 * 0x34 + 0x1d);
            uVar2 = *(undefined4 *)(iVar4 * 0x34 + 0x13);
            uVar10 = (undefined2)((ulong)uVar2 >> 0x10);
            iVar7 = (int)uVar2;
            if ((*(int *)(iVar7 + 0x68) == 0 && *(int *)(iVar7 + 0x6a) == 0) ||
               (uVar2 = *(undefined4 *)(iVar4 * 0x34 + 0x13),
               uVar10 = (undefined2)((ulong)uVar2 >> 0x10), iVar7 = (int)uVar2,
               *(int *)(iVar7 + 0x58) == 0 && *(int *)(iVar7 + 0x5a) == 0)) {
              uVar2 = *(undefined4 *)(iVar4 * 0x34 + 0x13);
              uVar10 = (undefined2)((ulong)uVar2 >> 0x10);
              iVar7 = (int)uVar2;
              if (*(int *)(iVar7 + 0x68) == 0 && *(int *)(iVar7 + 0x6a) == 0) {
                *(undefined1 *)(iVar4 * 0x34 + 0x11) = 0;
              }
              else {
                *(undefined1 *)(iVar4 * 0x34 + 0x11) = 1;
              }
            }
            else {
              uVar6 = ovr_randBelow(2);
              *(undefined1 *)(iVar4 * 0x34 + 0x11) = (char)uVar6;
            }
            uVar6 = ovr_audio_3a5b_0afd();
            ovr_play_sfxU(0x1b,0,uVar6);
          }
        }
      }
    }
  }
  return;
}



/* 4207:1aae */

void __cdecl16far OVC15_4207_1aae(int param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char cStack_5;
  
  if (EntityCount < 0x259) {
    if (EntityCount != 600) {
      memcpy((uint8_t *)(Entities.ofs + EntityCount * 0x37),
             (uint8_t *)(Entities.ofs + param_1 * 0x37),0x37);
      *(undefined1 *)(Entities.ofs + EntityCount * 0x37 + 0xe) =
           (char)((int)(uint)*(byte *)(Entities.ofs + param_1 * 0x37 + 0xe) >> 1);
      pcVar1 = (char *)(Entities.ofs + param_1 * 0x37 + 0xe);
      *pcVar1 = *pcVar1 - *(char *)(Entities.ofs + EntityCount * 0x37 + 0xe);
      uVar2 = EntityCount;
      uVar5 = (uint)*(byte *)(Entities.ofs + EntityCount * 0x37 + 0xe);
      EntityCount = EntityCount + 1;
      ovr_attact_3f0b_0c2a();
      if (AgntFlag1 != false) {
        cStack_5 = '\0';
        iVar4 = 0;
        while ((iVar4 < (int)(uint)AgntCount && (uVar5 != 0))) {
          if (*(int *)(iVar4 * 0x34 + 0x1b) == param_1) {
            if (cStack_5 == '\0') {
              *(uint *)(iVar4 * 0x34 + 0x1b) = uVar2;
              iVar3 = Entities.ofs + uVar2 * 0x37;
              *(uint16_t *)(iVar4 * 0x34 + 0x19) = Entities.seg;
              *(int *)(iVar4 * 0x34 + 0x17) = iVar3;
              uVar5 = uVar5 - 1;
            }
            cStack_5 = '\x01' - (cStack_5 != '\0');
          }
          iVar4 = iVar4 + 1;
        }
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x26);
}



/* 4207:1c16 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint8_t * __cdecl16far OVC15_4207_1c16(char *param_1)

{
  uint8_t uVar1;
  size_t sVar2;
  uint8_t *puVar3;
  
  sVar2 = strlen(param_1);
  _DAT_2410_1d05 = ovr_stshRealloc((uint32_t)_DAT_2410_1d05,(ulong)(sVar2 + 1));
  strcpy((char *)(uint8_t *)_DAT_2410_1d05,param_1);
  uVar1 = toupper(*_DAT_2410_1d05);
  *_DAT_2410_1d05 = uVar1;
  puVar3 = DAT_2410_1d05;
  return puVar3;
}



/* 4207:1c79 */

char * __cdecl16far OVC15_4207_1c79(char *param_1,char *param_2)

{
  char cVar1;
  
  strcpy((char *)param_1,param_2);
  cVar1 = toupper(*param_1);
  *param_1 = cVar1;
  return (char *)param_1;
}



/* 4207:1cae */

void __cdecl16far stshStoreSprite(spr_t *spr,anm_t *anms,int16_t nanims)

{
  byte bVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  bool bVar4;
  spr_t *pofs;
  int i;
  undefined2 pseg;
  cte_t *cte;
  far_t pframe;
  
  for (i = 0; i < nanims; i = i + 1) {
    bVar1 = ((anm_t *)anms + i)->frmid;
    pseg = (undefined2)((ulong)spr >> 0x10);
    pofs = (spr_t *)spr;
    if ((pofs->frames + bVar1)->ofs != 0 || pofs->frames[bVar1].seg != 0) {
      pframe.seg = pofs->frames[bVar1].seg;
      pframe.ofs = (pofs->frames + bVar1)->ofs;
      bVar4 = true;
      while( true ) {
        if (pframe.ofs == 0 && pframe.seg == 0) break;
        uVar2 = *(uint16_t *)(pframe.ofs + 3);
        uVar3 = *(uint16_t *)(pframe.ofs + 1);
        *(undefined2 *)(pframe.ofs + 3) = 0;
        *(undefined2 *)(pframe.ofs + 1) = 0;
        if (bVar4) {
          cte = ovr_stshStoreFile((uint8_t *)pframe);
          pofs->frames[bVar1].seg = (uint16_t)((ulong)cte >> 0x10);
          (pofs->frames + bVar1)->ofs = (uint16_t)(cte_t *)cte;
        }
        else {
          ovr_stshStoreFile((uint8_t *)pframe);
        }
        bVar4 = false;
        pframe.seg = uVar2;
        pframe.ofs = uVar3;
      }
    }
  }
  return;
}



/* 4207:1d87 */

undefined2 __cdecl16far OVC15_4207_1d87(byte param_1)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uStack_12;
  int iStack_6;
  int iStack_4;
  
  piVar1 = (int *)((uint)param_1 * 0x34);
  uStack_12 = (int *)CONCAT22(0x1726,piVar1);
  if ((((piVar1[1] < 0x14) || (*(char *)((int)piVar1 + 0x25) == '\x01')) && (*uStack_12 < 0xd3)) &&
     (-1 < *uStack_12)) {
    piVar4 = (int *)(*(int *)((int)piVar1 + 0x13) + (uint)*(byte *)(piVar1 + 9) * 4);
    iVar3 = piVar4[1];
    iVar5 = *piVar4;
    iStack_4 = piVar1[1] >> 1;
    if (iStack_4 < 0) {
      iStack_4 = 0;
    }
    if (8 < iStack_4) {
      iStack_4 = 8;
    }
    iStack_6 = *piVar1 - *(int *)(iVar5 + 0x17) >> 1;
    iVar3 = *piVar1 + *(int *)(iVar5 + 0x17) >> 1;
    if (iStack_6 < 0) {
      iStack_6 = 0;
    }
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    if (0x68 < iStack_6) {
      iStack_6 = 0x68;
    }
    if (0x68 < iVar3) {
      iVar3 = 0x68;
    }
    if (iVar3 < iStack_6) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x25);
    }
    iVar5 = iStack_6;
    if (*(char *)((int)piVar1 + 0x11) == '\0') {
      for (; iVar5 <= iVar3; iVar5 = iVar5 + 1) {
        if (param_1 + 1 != (uint)*(byte *)(iStack_4 * 0x69 + iVar5 + 0x8fa)) {
          return 0;
        }
      }
      for (; iStack_6 <= iVar3; iStack_6 = iStack_6 + 1) {
        if (param_1 + 1 != (uint)*(byte *)(iStack_4 * 0x69 + iStack_6 + 0x963)) {
          return 0;
        }
      }
    }
    else {
      for (; iVar5 <= iVar3; iVar5 = iVar5 + 1) {
        if (param_1 + 1 != (uint)*(byte *)(iStack_4 * 0x69 + iVar5 + 0x4e0)) {
          return 0;
        }
      }
      for (; iStack_6 <= iVar3; iStack_6 = iStack_6 + 1) {
        if (param_1 + 1 != (uint)*(byte *)(iStack_4 * 0x69 + iStack_6 + 0x549)) {
          return 0;
        }
      }
    }
    uVar2 = 1;
  }
  else {
    uVar2 = CONCAT11((char)((uint)piVar1 >> 8),1);
  }
  return uVar2;
}



/* 4207:1f5b */

undefined2 __cdecl16far OVC15_4207_1f5b(undefined2 *param_1)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined2 uVar7;
  undefined1 uStack_c;
  undefined4 uStack_6;
  
  uVar7 = (undefined2)((ulong)param_1 >> 0x10);
  puVar6 = (undefined2 *)param_1;
  uVar1 = *(undefined2 *)((int)puVar6 + 0x15);
  piVar2 = (int *)*(int *)((int)puVar6 + 0x13);
  uStack_6 = (int *)CONCAT22(uVar1,piVar2);
  if (*(char *)((int)puVar6 + 0x11) == '\0') {
    iVar5 = piVar2[1];
    iVar3 = *uStack_6;
    iVar4 = ovr_agnt_3b1d_005e(*param_1);
    iVar5 = (*(int *)(iVar3 + 0xd) - *(int *)(iVar4 * 2 + 0x34c)) + 0x93;
    uStack_c = (undefined1)iVar5;
  }
  else {
    iVar5 = piVar2[9];
    iVar3 = piVar2[8];
    iVar4 = ovr_agnt_3b1d_005e(*param_1);
    iVar5 = (*(int *)(iVar3 + 0xd) - *(int *)(iVar4 * 2 + 0x34c)) + 0xac;
    uStack_c = (undefined1)iVar5;
  }
  return CONCAT11((char)((uint)iVar5 >> 8),uStack_c);
}



/* 4207:1ffe */

int __cdecl16far OVC15_4207_1ffe(int *param_1,int param_2,char param_3,char param_4)

{
  char *pcVar1;
  byte bVar2;
  uint16_t uVar3;
  undefined2 uVar4;
  int *src;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  int local_e [4];
  int iStack_6;
  int iStack_4;
  
  F_SCOPY((uint8_t *)local_e,(uint8_t *)0x1d09,8);
  src = (int *)param_1;
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  if (param_3 == '\0') {
    if (param_2 < 0) {
      *param_1 = 0;
      uVar3 = ovr_randBelow(0x14);
      src[1] = uVar3 & 0xff;
    }
    else if (param_2 < 1) {
      iVar5 = (*(int *)*(undefined4 *)((int)src + 0x17) - GfxRndSeed) + 2;
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      if (3 < iVar5) {
        iVar5 = 3;
      }
      *param_1 = local_e[iVar5];
      if (param_4 == '\0') {
        src[1] = 0x20;
      }
      else {
        uVar3 = ovr_randBelow(0x14);
        src[1] = uVar3 & 0xff;
      }
    }
    else {
      *param_1 = 0xd2;
      uVar3 = ovr_randBelow(0x14);
      src[1] = uVar3 & 0xff;
    }
  }
  iVar5 = *param_1;
  if (iVar5 < 0x6a) {
    iStack_6 = 1;
  }
  else {
    iStack_6 = -1;
  }
  ovr_OVC49_8699_18c4(src,uVar6);
  do {
    if (*(char *)((int)src + 0x11) == '\0') {
      uVar4 = ovr_OVC49_8699_0849(*param_1);
      bVar2 = (byte)((uint)uVar4 >> 8);
      if ((char)uVar4 == '\0') goto LAB_4207_2193;
    }
    else {
LAB_4207_2193:
      uVar4 = ovr_OVC49_8699_06dc(src,uVar6);
      bVar2 = (byte)((uint)uVar4 >> 8);
      if ((char)uVar4 == '\0') {
        if (src[1] == 0x20) {
          bVar2 = OVC15_4207_1f5b(src,uVar6);
          src[1] = (uint)bVar2;
        }
        iStack_4 = 0;
        while ((iStack_4 < (int)(uint)AgntCount && (*(int *)(iStack_4 * 0x34 + 2) < src[1]))) {
          iStack_4 = iStack_4 + 1;
        }
        if (iStack_4 < (int)(uint)AgntCount) {
          _fmemmove((uint8_t *)(iStack_4 * 0x34 + 0x34),(uint8_t *)(iStack_4 * 0x34),
                    ((uint)AgntCount - iStack_4) * 0x34);
        }
        *(undefined1 *)((int)src + 0x2d) = 1;
        memcpy((uint8_t *)(iStack_4 * 0x34),(uint8_t *)src,0x34);
        ovr_agnt_3b1d_16cd(iStack_4 + 1);
        ovr_OVC49_8699_1753(CONCAT11((char)((uint)(iStack_4 * 0x34) >> 8),(char)iStack_4 + '\x01'),
                            iStack_4 * 0x34,0x1726);
        AgntCount = AgntCount + 1;
        for (iVar5 = 0; iVar5 < (int)(uint)AgntCount; iVar5 = iVar5 + 1) {
          if ((*(char *)(iVar5 * 0x34 + 0xc) != -1) &&
             (iStack_4 <= (int)(uint)*(byte *)(iVar5 * 0x34 + 0xc))) {
            pcVar1 = (char *)(iVar5 * 0x34 + 0xc);
            *pcVar1 = *pcVar1 + '\x01';
          }
        }
        return 1;
      }
    }
    if (iStack_6 < 0) {
      if (*param_1 == 0) {
        *param_1 = 0xd2;
      }
      else {
        *param_1 = *param_1 + -1;
      }
    }
    else if (*param_1 == 0xd2) {
      *param_1 = 0;
    }
    else {
      *param_1 = *param_1 + 1;
    }
    if (*param_1 == iVar5) {
      return (uint)bVar2 << 8;
    }
    if ((param_2 == 0) && (param_4 == '\0')) {
      src[1] = 0x20;
    }
    else {
      uVar3 = ovr_randBelow(0x14);
      src[1] = uVar3 & 0xff;
    }
    ovr_OVC49_8699_18c4(src,uVar6);
  } while( true );
}



/* 4207:2301 */

char * __cdecl16far OVC15_4207_2301(int param_1)

{
  char cVar1;
  uint16_t uVar2;
  char *pcVar3;
  undefined1 *puVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  uint8_t local_3e [4];
  char cStack_3a;
  undefined1 uStack_32;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_2d;
  int iStack_2b;
  undefined2 uStack_29;
  int iStack_27;
  uint16_t uStack_25;
  int iStack_23;
  undefined4 uStack_21;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_f;
  undefined1 uStack_9;
  uint uStack_8;
  int iStack_6;
  uint16_t uStack_4;
  
  if (AgntFlag1) {
    for (uStack_8 = 0; (int)uStack_8 < (int)(uint)AgntCount; uStack_8 = uStack_8 + 1) {
      if (((*(char *)(uStack_8 * 0x34 + 0x2d) == '\0') &&
          (*(int *)(uStack_8 * 0x34 + 0x1b) == param_1)) &&
         ((*(uint *)(uStack_8 * 0x34 + 0x2b) & 0xae4) == 0)) {
        *(undefined1 *)(uStack_8 * 0x34 + 0x2d) = 1;
        if (((*(char *)(uStack_8 * 0x34 + 0x11) != '\0') ||
            (cVar1 = ovr_OVC49_8699_0849(*(undefined2 *)(uStack_8 * 0x34)), cVar1 == '\0')) &&
           (cVar1 = OVC15_4207_1d87(uStack_8 & 0xff), cVar1 != '\0')) {
          return (char *)0x1;
        }
        _fmemmove(local_3e,(uint8_t *)(uStack_8 * 0x34),0x34);
        uStack_32 = 0xff;
        ovr_OVC41_6a8f_0256(uStack_8,0);
        pcVar3 = (char *)OVC15_4207_1ffe(local_3e);
        return pcVar3;
      }
    }
  }
  if (AgntCount < 0x18) {
    iStack_6 = Entities.ofs + param_1 * 0x37;
    uStack_4 = Entities.seg;
    _fmemset((uint8_t *)CONCAT22(unaff_SS,local_3e),0,0x34);
    uStack_32 = 0xff;
    uStack_25 = uStack_4;
    iStack_27 = iStack_6;
    iStack_23 = param_1;
    uStack_21 = (undefined1 *)
                CONCAT22(0x195d,(undefined1 *)
                                ((int)(char **)GMenuStrings +
                                (uint)*(byte *)(iStack_6 + 0xd) * 0x95 + 0x1f));
    cVar1 = OVC15_4207_288b();
    if (cVar1 == '\0') {
      *(undefined1 *)(iStack_6 + 0x31) = *(undefined1 *)(iStack_6 + 0x32);
    }
    uStack_1c = *(undefined1 *)(iStack_6 + 0x32);
    uStack_1d = *(undefined1 *)(iStack_6 + 0x31);
    uStack_9 = (*(uint *)(iStack_6 + 0x16) & 1) != 0;
    puVar4 = (undefined1 *)uStack_21;
    uVar5 = (undefined2)((ulong)uStack_21 >> 0x10);
    if (*(byte *)(iStack_6 + 0xf) < 10) {
      if (*(byte *)(iStack_6 + 0xf) < 4) {
        uStack_29 = *(undefined2 *)(puVar4 + (uint)(byte)uStack_9 * 0xc + 5);
        iStack_2b = *(int *)(puVar4 + (uint)(byte)uStack_9 * 0xc + 3);
      }
      else {
        uStack_29 = *(undefined2 *)(puVar4 + (uint)(byte)uStack_9 * 0xc + 9);
        iStack_2b = *(int *)(puVar4 + (uint)(byte)uStack_9 * 0xc + 7);
      }
    }
    else {
      uStack_29 = *(undefined2 *)(puVar4 + (uint)(byte)uStack_9 * 0xc + 0xd);
      iStack_2b = *(int *)(puVar4 + (uint)(byte)uStack_9 * 0xc + 0xb);
    }
    uStack_30 = 0xff;
    uStack_f = *uStack_21;
    if ((*(int *)(iStack_2b + 0x68) == 0 && *(int *)(iStack_2b + 0x6a) == 0) ||
       (*(int *)(iStack_2b + 0x58) == 0 && *(int *)(iStack_2b + 0x5a) == 0)) {
      if (*(int *)(iStack_2b + 0x68) != 0 || *(int *)(iStack_2b + 0x6a) != 0) {
        uStack_2d = 1;
      }
    }
    else {
      uVar2 = ovr_randBelow(2);
      uStack_2d = (undefined1)uVar2;
    }
    uVar2 = ovr_randBelow(2);
    cStack_3a = (char)uVar2 * '\x02' + -1;
    if (cStack_3a < '\x01') {
      if (cStack_3a < '\0') {
        uStack_2f = 1;
      }
      else {
        uVar2 = ovr_randBelow(2);
        uStack_2f = (undefined1)uVar2;
      }
    }
    else {
      uStack_2f = 0;
    }
    pcVar3 = (char *)OVC15_4207_1ffe(local_3e);
  }
  else {
    pcVar3 = (char *)"arena" + 4;
  }
  return pcVar3;
}



/* 4207:25dd */

/* WARNING: Control flow encountered bad instruction data */

uint __cdecl16far
OVC15_4207_25dd(code *param_1,int *param_2,int *param_3,undefined2 param_4,undefined2 param_5,
               int *param_6,int *param_7,int *param_8,int *param_9)

{
  undefined2 *puVar1;
  char *pcVar2;
  byte bVar3;
  far_t handle;
  far_t handle_00;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  stg_tmp_t *data;
  uint uVar7;
  uint uVar8;
  uint16_t uVar9;
  code *pcVar10;
  int iVar11;
  int unaff_SI;
  uint unaff_DI;
  uint16_t uVar12;
  int iVar13;
  undefined2 unaff_SS;
  bool bVar14;
  far_t fVar15;
  stg_tmp_t *gfx;
  uint8_t *data_00;
  cte_t *pcVar16;
  uint32_t uVar17;
  long lVar18;
  uint16_t in_stack_0000ffee;
  uint8_t *in_stack_0000fff0;
  undefined2 uVar19;
  undefined1 uVar20;
  uint uStack_6;
  uint8_t *puStack_4;
  
  iVar13 = (int)((ulong)param_1 >> 0x10);
  pcVar10 = (code *)param_1;
  bVar3 = *(byte *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)(byte)pcVar10[0xd] * 0x95);
  uStack_6 = (uint)bVar3 << 8;
  if (bVar3 == 0xff) {
    uStack_6 = 0;
  }
  uVar7 = (uStack_6 >> 8) - 1;
  if (5 < uVar7) {
    if ((byte)pcVar10[0xf] < 10) {
      uVar4 = ovr_manage_4d05_01a3();
      uVar20 = 0;
      cVar5 = ovr_agnt_3b1d_0c1e();
      iVar13 = CONCAT11(uVar20,uVar4) + (int)cVar5;
    }
    else {
      iVar13 = 2;
    }
    puStack_4._0_1_ = (byte)iVar13;
    if (iVar13 < 1) {
      puStack_4._0_1_ = 1;
    }
    return (uint)(byte)puStack_4;
  }
  iVar11 = uVar7 * 2;
  bVar14 = iVar11 == 0;
  switch(uVar7) {
  case 1:
    *(undefined2 *)((int)AgntGs[0].sprs + 10 + iVar11) = 0x195d;
    do {
      *(uint *)((int)AgntGs[0].sprs + 8 + iVar11) = uVar7;
      while( true ) {
        for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
          if (*(int *)((int)AgntGs[0].sprfls + 6 + unaff_SI * 0x95 + iVar13 * 2) == 0) {
            iVar11 = unaff_SI * 0x95 + iVar13 * 4;
            uVar19 = *(undefined2 *)((int)AgntGs[0].sprs + iVar11);
            iVar6 = unaff_SI * 0x95 + iVar13 * 4;
            *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar6) =
                 *(undefined2 *)((int)AgntGs[0].sprs + 2 + iVar11);
            *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar6) = uVar19;
          }
          else {
            fVar15 = stshSprite(*(int16_t *)
                                 ((int)AgntGs[0].sprfls + 6 + unaff_SI * 0x95 + iVar13 * 2),
                                (anm_t *)CONCAT22(*(undefined2 *)
                                                   ((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95),
                                                  (anm_t *)*(undefined2 *)
                                                            ((int)&AgntGs[0].anms + unaff_SI * 0x95)
                                                 ),
                                (uint)*(byte *)((int)&AgntGs[0].nanims + unaff_SI * 0x95),
                                param_1._0_1_);
            iVar11 = unaff_SI * 0x95 + iVar13 * 4;
            *(uint16_t *)((int)AgntGs[0].sprs + 0xe + iVar11) = fVar15.seg;
            *(uint16_t *)((int)AgntGs[0].sprs + 0xc + iVar11) = fVar15.ofs;
          }
        }
        for (iVar13 = 0; iVar13 < 6; iVar13 = iVar13 + 1) {
          if (*(int *)((int)AgntGs[0].prtfls + unaff_SI * 0x95 + iVar13 * 2) != 0) {
            if (param_1._0_1_ == false) {
              fVar15 = ovr_stshAllocStub();
              iVar11 = unaff_SI * 0x95 + iVar13 * 4;
              *(uint16_t *)((int)AgntGs[0].prts + 2 + iVar11) = fVar15.seg;
              *(uint16_t *)((int)AgntGs[0].prts + iVar11) = fVar15.ofs;
              fVar15 = ovr_stshAllocStub();
              iVar11 = unaff_SI * 0x95 + iVar13 * 4;
              *(uint16_t *)((int)AgntGs[0].prtpals + 2 + iVar11) = fVar15.seg;
              *(uint16_t *)((int)AgntGs[0].prtpals + iVar11) = fVar15.ofs;
            }
            else {
              gfx = ovr_grabLbm(*(int16_t *)((int)AgntGs[0].prtfls + unaff_SI * 0x95 + iVar13 * 2),0
                                ,0);
              data = (stg_tmp_t *)gfx;
              uVar19 = (undefined2)((ulong)gfx >> 0x10);
              ovr_stshUniqueColorsRemap(gfx);
              fVar15.seg = (data->aptr).seg;
              fVar15.ofs = (&data->aptr)->ofs;
              data_00 = (uint8_t *)ovr_stshRleType2(fVar15,0,0,114,103,0,0);
              pcVar16 = ovr_stshStoreFile(data_00);
              iVar11 = unaff_SI * 0x95 + iVar13 * 4;
              *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar11) = (int)((ulong)pcVar16 >> 0x10);
              *(undefined2 *)((int)AgntGs[0].prts + iVar11) = (cte_t *)pcVar16;
              uVar17 = ovr_stshWrite(data->cmap,0x300);
              iVar11 = unaff_SI * 0x95 + iVar13 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar11) = (int)(uVar17 >> 0x10);
              *(undefined2 *)((int)AgntGs[0].prtpals + iVar11) = (int)uVar17;
              ovr_stgFreeTmp(gfx);
            }
          }
        }
        uVar7 = *(uint *)((int)AgntGs[0].prts + 4 + unaff_SI * 0x95) |
                *(uint *)((int)AgntGs[0].prts + 6 + unaff_SI * 0x95);
        if ((uVar7 == 0) &&
           (uVar7 = 0,
           *(int *)((int)AgntGs[0].prts + unaff_SI * 0x95) != 0 ||
           *(int *)((int)AgntGs[0].prts + 2 + unaff_SI * 0x95) != 0)) {
          uVar19 = *(undefined2 *)((int)AgntGs[0].prts + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].prts + 6 + unaff_SI * 0x95) =
               *(undefined2 *)((int)AgntGs[0].prts + 2 + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].prts + 4 + unaff_SI * 0x95) = uVar19;
          uVar7 = *(uint *)((int)AgntGs[0].prtpals + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].prtpals + 6 + unaff_SI * 0x95) =
               *(undefined2 *)((int)AgntGs[0].prtpals + 2 + unaff_SI * 0x95);
          *(uint *)((int)AgntGs[0].prtpals + 4 + unaff_SI * 0x95) = uVar7;
        }
        for (iVar13 = 2; iVar13 < 6; iVar13 = iVar13 + 2) {
          iVar11 = unaff_SI * 0x95 + iVar13 * 4;
          if ((*(int *)((int)AgntGs[0].prts + 4 + iVar11) == 0 &&
               *(int *)((int)AgntGs[0].prts + 6 + iVar11) == 0) &&
             (iVar11 = unaff_SI * 0x95 + iVar13 * 4,
             *(int *)((int)AgntGs[0].prtfls + 8 + iVar11) != 0 ||
             *(int *)((int)AgntGs[0].prtfls + 10 + iVar11) != 0)) {
            iVar11 = unaff_SI * 0x95 + iVar13 * 4;
            uVar19 = *(undefined2 *)((int)AgntGs[0].prtfls + 8 + iVar11);
            iVar6 = unaff_SI * 0x95 + iVar13 * 4;
            *(undefined2 *)((int)AgntGs[0].prts + 6 + iVar6) =
                 *(undefined2 *)((int)AgntGs[0].prtfls + 10 + iVar11);
            *(undefined2 *)((int)AgntGs[0].prts + 4 + iVar6) = uVar19;
            iVar11 = unaff_SI * 0x95 + iVar13 * 4;
            uVar19 = *(undefined2 *)((int)AgntGs[0].prts + 0x14 + iVar11);
            iVar6 = unaff_SI * 0x95 + iVar13 * 4;
            *(undefined2 *)((int)AgntGs[0].prtpals + 6 + iVar6) =
                 *(undefined2 *)((int)AgntGs[0].prts + 0x16 + iVar11);
            *(undefined2 *)((int)AgntGs[0].prtpals + 4 + iVar6) = uVar19;
          }
          iVar11 = unaff_SI * 0x95 + iVar13 * 4;
          uVar7 = *(uint *)((int)AgntGs[0].prts + iVar11) |
                  *(uint *)((int)AgntGs[0].prts + 2 + iVar11);
          if (uVar7 == 0) {
            iVar11 = unaff_SI * 0x95 + iVar13 * 4;
            if (*(int *)((int)AgntGs[0].prtfls + 4 + iVar11) == 0 &&
                *(int *)((int)AgntGs[0].prtfls + 6 + iVar11) == 0) {
              uVar7 = 0;
            }
            else {
              iVar11 = unaff_SI * 0x95 + iVar13 * 4;
              uVar19 = *(undefined2 *)((int)AgntGs[0].prtfls + 4 + iVar11);
              iVar6 = unaff_SI * 0x95 + iVar13 * 4;
              *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar6) =
                   *(undefined2 *)((int)AgntGs[0].prtfls + 6 + iVar11);
              *(undefined2 *)((int)AgntGs[0].prts + iVar6) = uVar19;
              iVar11 = unaff_SI * 0x95 + iVar13 * 4;
              uVar7 = *(uint *)((int)AgntGs[0].prts + 0x10 + iVar11);
              iVar6 = unaff_SI * 0x95 + iVar13 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar6) =
                   *(undefined2 *)((int)AgntGs[0].prts + 0x12 + iVar11);
              *(uint *)((int)AgntGs[0].prtpals + iVar6) = uVar7;
            }
          }
        }
        unaff_SI = unaff_SI + 1;
        if (0x29 < unaff_SI) {
          return uVar7;
        }
        fVar15 = stshSprite(*(int16_t *)((int)AgntGs[0].sprfls + unaff_SI * 0x95),
                            (anm_t *)CONCAT22(*(undefined2 *)
                                               ((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95),
                                              (anm_t *)*(undefined2 *)
                                                        ((int)&AgntGs[0].anms + unaff_SI * 0x95)),
                            (uint)*(byte *)((int)&AgntGs[0].nanims + unaff_SI * 0x95),param_1._0_1_)
        ;
        *(uint16_t *)((int)AgntGs[0].sprs + 2 + unaff_SI * 0x95) = fVar15.seg;
        *(uint16_t *)((int)AgntGs[0].sprs + unaff_SI * 0x95) = fVar15.ofs;
        if (*(int *)((int)AgntGs[0].sprfls + 2 + unaff_SI * 0x95) == 0) {
          uVar19 = *(undefined2 *)((int)AgntGs[0].sprs + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95) =
               *(undefined2 *)((int)AgntGs[0].sprs + 2 + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95) = uVar19;
        }
        else {
          fVar15 = stshSprite(*(int16_t *)((int)AgntGs[0].sprfls + 2 + unaff_SI * 0x95),
                              (anm_t *)CONCAT22(*(undefined2 *)
                                                 ((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95),
                                                (anm_t *)*(undefined2 *)
                                                          ((int)&AgntGs[0].anms + unaff_SI * 0x95)),
                              (uint)*(byte *)((int)&AgntGs[0].nanims + unaff_SI * 0x95),
                              param_1._0_1_);
          *(uint16_t *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95) = fVar15.seg;
          *(uint16_t *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95) = fVar15.ofs;
        }
        if (*(int *)((int)AgntGs[0].sprfls + 4 + unaff_SI * 0x95) == 0) break;
        fVar15 = stshSprite(*(int16_t *)((int)AgntGs[0].sprfls + 4 + unaff_SI * 0x95),
                            (anm_t *)CONCAT22(*(undefined2 *)
                                               ((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95),
                                              (anm_t *)*(undefined2 *)
                                                        ((int)&AgntGs[0].anms + unaff_SI * 0x95)),
                            (uint)*(byte *)((int)&AgntGs[0].nanims + unaff_SI * 0x95),param_1._0_1_)
        ;
        *(uint16_t *)((int)AgntGs[0].sprs + 10 + unaff_SI * 0x95) = fVar15.seg;
        *(uint16_t *)((int)AgntGs[0].sprs + 8 + unaff_SI * 0x95) = fVar15.ofs;
      }
      uVar7 = *(uint *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95);
      iVar11 = unaff_SI * 0x95;
      *(undefined2 *)((int)AgntGs[0].sprs + 10 + iVar11) =
           *(undefined2 *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95);
    } while( true );
  case 2:
    do {
      cVar5 = OVC15_4207_25dd();
      *(char *)(Entities.ofs + EntityCount * 0x37 + 0x31) =
           *(char *)(Entities.ofs + EntityCount * 0x37 + 0x31) + cVar5;
      *(char *)(Entities.ofs + EntityCount * 0x37 + 0x32) =
           *(char *)(Entities.ofs + EntityCount * 0x37 + 0x32) + cVar5;
      pcVar2 = (char *)(Entities.ofs + EntityCount * 0x37 + 0xf);
      *pcVar2 = *pcVar2 + '\x01';
      uVar12 = Entities.seg;
      uVar9 = Entities.ofs;
    } while (*(byte *)(uVar9 + EntityCount * 0x37 + 0xf) < 5);
    if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)(byte)param_3 * 0x95) == -1) {
      iVar13 = (uint)*(byte *)(uVar9 + EntityCount * 0x37 + 0xf) * 4;
      uVar19 = *(undefined2 *)(iVar13 + -4);
      iVar11 = uVar9 + EntityCount * 0x37;
      *(undefined2 *)(iVar11 + 0x12) = *(undefined2 *)(iVar13 + -2);
      *(undefined2 *)(iVar11 + 0x10) = uVar19;
    }
    else {
      iVar13 = (uint)*(byte *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)(byte)param_3 * 0x95)
               * 0x94 + (uint)*(byte *)(uVar9 + EntityCount * 0x37 + 0xf) * 4;
      uVar19 = *(undefined2 *)(iVar13 + -4);
      iVar11 = uVar9 + EntityCount * 0x37;
      *(undefined2 *)(iVar11 + 0x12) = *(undefined2 *)(iVar13 + -2);
      *(undefined2 *)(iVar11 + 0x10) = uVar19;
    }
    uVar9 = Entities.seg;
    iVar13 = Entities.ofs + EntityCount * 0x37;
    if (*(int *)(iVar13 + 0x10) == 0 && *(int *)(iVar13 + 0x12) == 0) {
      iVar13 = Entities.ofs + EntityCount * 0x37;
      *(undefined2 *)(iVar13 + 0x12) = 0;
      *(undefined2 *)(iVar13 + 0x10) = 100;
    }
    iVar13 = EntityCount;
    EntityCount = EntityCount + 1;
    ovr_attact_3f0b_0c2a();
    if (AgntFlag1 != false) {
      uVar12 = Entities.seg;
      uVar9 = Entities.ofs;
      if (((GfxRndSeed - 2U <= *(uint *)(uVar9 + iVar13 * 0x37)) &&
          (*(uint *)(uVar9 + iVar13 * 0x37) <= GfxRndSeed + 1U)) &&
         (*(int *)(uVar9 + iVar13 * 0x37 + 2) == GfxRndSeed2)) {
        OVC15_4207_2301();
      }
    }
    uVar7 = Entities.ofs + iVar13 * 0x37;
    return uVar7;
  case 3:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 4:
    ovr_OVC23_55fe_1e87();
    OVC18_48ac_0382();
    if (2 < DAT_2000_d19d) {
      ovr_OVC22_5087_4975();
    }
    ovr_OVC22_5087_056e();
    DAT_2000_d1e4 = 0;
    ovr_manage_4d05_0000();
    ovr_stats_6386_232d();
    ovr_unit_6616_00d8();
    ovr_say("");
    uVar7 = (uint)DAT_2000_d310;
    if (uVar7 == 0) {
      uVar7 = ovr_OVC30_619c_004e();
    }
    return uVar7;
  case 5:
    do {
      if (bVar14) {
        *param_9 = *param_9 + 1;
      }
      while( true ) {
        while( true ) {
          do {
            do {
              unaff_DI = unaff_DI + 1;
              if (DAT_2000_d2df <= unaff_DI) {
                iVar13 = *param_8;
                iVar11 = *param_9;
                *param_2 = *param_2 - *param_8;
                *param_3 = *param_3 - *param_9;
                return (int)puStack_4 - (iVar13 + iVar11);
              }
            } while ((bool)*(char *)(unaff_DI * 0x12 + 9) != param_1._0_1_);
            bVar3 = *(byte *)(unaff_DI * 0x12 + 8);
          } while (*(char *)((uint)bVar3 * 0x27 + 0x133) != param_1._2_1_);
          *param_6 = *param_6 + 1;
          if (*(char *)((uint)bVar3 * 0x27 + 0x131) != '\x01') break;
          *param_7 = *param_7 + 1;
        }
        if (*(char *)((uint)bVar3 * 0x27 + 0x131) != '\x02') break;
        *param_8 = *param_8 + 1;
      }
      bVar14 = *(char *)((uint)bVar3 * 0x27 + 0x131) == '\x03';
    } while( true );
  }
  if (((byte)uVar7 & (&stack0x02c2)[unaff_DI]) == 0) {
    lVar18 = LXRSH_at_((long)CONCAT22(iVar13 + (uint)((code *)init_3381_08dc < pcVar10),
                                      pcVar10 + 0x13),0x4);
    uVar8 = (uint)(lVar18 + (ulong)HeapPtr);
    iVar13 = (int)(lVar18 + (ulong)HeapPtr >> 0x10);
    uVar7 = uVar8;
    if (iVar13 != 0) {
      uVar7 = 0xffff;
    }
    if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) && ((iVar13 != 0 || (MUSHandle.seg < uVar8))))
       || ((DIGHandle.ofs != 0 || DIGHandle.seg != 0 && ((iVar13 != 0 || (MUSHandle.seg < uVar8)))))
       ) {
      ovr_fmFreeAudio(1);
    }
    HeapPtr = 0xffff;
    uVar8 = 0xffff;
    bVar14 = false;
    puStack_4 = (uint8_t *)StshCtPtr2.seg;
    uStack_6 = StshCtPtr2.ofs;
    while (uStack_6 != 0 || puStack_4 != (uint8_t *)0x0) {
      if (*(int *)(uStack_6 + 0x11) != 0 || *(int *)(uStack_6 + 0x13) != 0) {
        if (*(uint *)(uStack_6 + 0x13) < uVar7) {
          in_stack_0000fff0 = (uint8_t *)vprinter_printCtype + 0x34;
          handle.seg._0_1_ = (char)*(undefined2 *)(uStack_6 + 0x13);
          handle.ofs = *(undefined2 *)(uStack_6 + 0x11);
          handle.seg._1_1_ = (char)((uint)*(undefined2 *)(uStack_6 + 0x13) >> 8);
          stshFree(handle);
          *(undefined2 *)(uStack_6 + 0x13) = 0;
          *(undefined2 *)(uStack_6 + 0x11) = 0;
          bVar14 = true;
        }
        else {
          if (*(uint *)(uStack_6 + 0x13) < uVar8) {
            uVar8 = *(uint *)(uStack_6 + 0x13);
            in_stack_0000ffee = uStack_6;
            in_stack_0000fff0 = puStack_4;
          }
          if (*(uint *)(uStack_6 + 0x13) < HeapPtr) {
            HeapPtr = *(uint *)(uStack_6 + 0x13);
          }
        }
      }
      puVar1 = (undefined2 *)(uStack_6 + 0xb);
      uStack_6 = *(uint16_t *)(uStack_6 + 9);
      puStack_4 = (uint8_t *)*puVar1;
    }
    if (!bVar14) {
      if (uVar8 == 0xffff) {
        bVar14 = ovr_fmFreeAudio(1);
        if (bVar14) {
          return 1;
        }
        if (DAT_2410_2a4e == '\0') {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x14);
        }
        return 0;
      }
      uVar4 = (undefined1)*(undefined2 *)(in_stack_0000ffee + 0x13);
      uVar20 = (undefined1)((uint)*(undefined2 *)(in_stack_0000ffee + 0x13) >> 8);
      uVar19 = 0x8939;
      handle_00.seg._0_1_ = uVar4;
      handle_00.ofs = *(undefined2 *)(in_stack_0000ffee + 0x11);
      handle_00.seg._1_1_ = uVar20;
      stshFree(handle_00);
      *(undefined2 *)(in_stack_0000ffee + 0x13) = 0;
      *(undefined2 *)(in_stack_0000ffee + 0x11) = 0;
      HeapPtr = CONCAT11(uVar20,uVar4);
    }
  }
  return 1;
}



/* 4207:26bc */

/* WARNING: Instruction at (ram,0x0005ff51) overlaps instruction at (ram,0x0005ff50)
    */

char * __cdecl16far OVC15_4207_26bc(code *param_1,char *param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  far_t pixels;
  far_t handle;
  far_t handle_00;
  char cVar3;
  byte bVar4;
  char cVar5;
  bool bVar6;
  char cVar7;
  char cVar8;
  uint uVar9;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint *in_CX;
  uint uVar17;
  uint *puVar18;
  code *pcVar19;
  undefined1 *puVar20;
  uint *puVar21;
  undefined2 unaff_SI;
  char *pcVar22;
  uint uVar23;
  char *unaff_DI;
  undefined2 uVar24;
  undefined2 uVar25;
  uint16_t uVar26;
  uint16_t uVar27;
  char *pcVar28;
  undefined2 unaff_SS;
  bool bVar29;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  far_t fVar30;
  stg_tmp_t *psVar31;
  uint8_t *data;
  cte_t *pcVar32;
  uint32_t uVar33;
  long lVar34;
  ulong uVar35;
  void *pvVar36;
  char *text;
  char acStackY_13e [36];
  uint auStackY_11a [66];
  uint auStackY_96 [24];
  uint auStackY_66 [29];
  undefined2 uStackY_2c;
  char *pcStackY_2a;
  uint *puStack_1e;
  undefined1 uVar37;
  undefined1 uVar38;
  undefined1 in_stack_0000ffee;
  undefined1 in_stack_0000ffef;
  undefined1 uVar39;
  byte in_stack_0000fff0;
  byte in_stack_0000fff1;
  undefined1 uVar40;
  undefined1 in_stack_0000fff2;
  uint8_t term;
  undefined1 in_stack_0000fff3;
  byte in_stack_0000fff4;
  byte bVar41;
  byte in_stack_0000fff5;
  byte bVar42;
  byte bStack_4;
  byte bStack_3;
  
  uVar11 = CONCAT11(in_stack_0000fff1,in_stack_0000fff0);
  uVar26 = (uint16_t)((ulong)param_1 >> 0x10);
  pcVar19 = (code *)param_1;
  uVar24 = ((undefined2 *)((uint)(byte)pcVar19[0x1a] * 4))[1];
  uVar25 = *(undefined2 *)((uint)(byte)pcVar19[0x1a] * 4);
  uVar39 = (undefined1)uVar24;
  uVar40 = (undefined1)((uint)uVar24 >> 8);
  bVar42 = (byte)uVar25;
  uVar38 = (undefined1)((uint)uVar25 >> 8);
  uVar17 = 0x195d;
  uVar27 = 0x195d;
  bStack_3 = *(byte *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)(byte)pcVar19[0xd] * 0x95);
  if (bStack_3 == 0xff) {
    bStack_3 = 0;
  }
  pcVar22 = (char *)0x0;
  uVar9 = (uint)bStack_3;
  if (6 < uVar9) {
    if ((char *)param_2 != (char *)0x0 || param_2._2_2_ != 0) {
      uVar40 = 0;
      uVar16 = 0;
      uVar38 = 100;
      uVar39 = 0;
      lVar34 = LXMUL_at_((long)param_2,100);
      uVar35 = LDIV_at_(lVar34,CONCAT13(uVar16,CONCAT12(uVar40,CONCAT11(uVar39,uVar38))));
      param_2 = (char *)(uVar35 & 0xffff);
    }
    return (char *)param_2;
  }
  puVar20 = (undefined1 *)(uVar9 * 2);
  pcVar28 = "";
  switch(uVar9) {
  case 0:
    if ((bStack_3 & (&stack0x02c2)[(int)unaff_DI]) == 0) {
      pcVar22 = (char *)0x1000;
      lVar34 = LXRSH_at_((long)CONCAT22(uVar26 + ((code *)init_3381_08dc < pcVar19),pcVar19 + 0x13),
                         0x4);
      uVar17 = (uint)(lVar34 + (ulong)HeapPtr);
      iVar12 = (int)(lVar34 + (ulong)HeapPtr >> 0x10);
      uVar11 = uVar17;
      if (iVar12 != 0) {
        uVar11 = 0xffff;
      }
      if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) && ((iVar12 != 0 || (MUSHandle.seg < uVar17)))
          ) || ((DIGHandle.ofs != 0 || DIGHandle.seg != 0 &&
                ((iVar12 != 0 || (MUSHandle.seg < uVar17)))))) {
        pcVar22 = (char *)"stonemasonry" + 0xc;
        in_stack_0000fff0 = 0x28;
        in_stack_0000fff1 = 0x88;
        ovr_fmFreeAudio(1);
      }
      uVar9 = 0xffff;
      HeapPtr = 0xffff;
      bVar29 = false;
      bStack_4 = (byte)StshCtPtr2.seg;
      bStack_3 = (byte)(StshCtPtr2.seg >> 8);
      uVar38 = (undefined1)StshCtPtr2.ofs;
      uVar39 = (undefined1)(StshCtPtr2.ofs >> 8);
      uVar17 = 0xffff;
      while( true ) {
        uVar40 = SUB21(pcVar22,0);
        uVar16 = (undefined1)((uint)pcVar22 >> 8);
        if (CONCAT11(uVar39,uVar38) == 0 && CONCAT11(bStack_3,bStack_4) == 0) break;
        iVar12 = CONCAT11(uVar39,uVar38);
        uVar24 = (undefined2)(CONCAT13(bStack_3,CONCAT12(bStack_4,iVar12)) >> 0x10);
        uVar23 = uVar17;
        if (*(int *)(iVar12 + 0x11) != 0 || *(int *)(iVar12 + 0x13) != 0) {
          if (*(uint *)(CONCAT11(uVar39,uVar38) + 0x13) < uVar11) {
            iVar12 = CONCAT11(uVar39,uVar38);
            uVar24 = (undefined2)(CONCAT13(bStack_3,CONCAT12(bStack_4,iVar12)) >> 0x10);
            in_stack_0000ffee = 0x7f;
            in_stack_0000ffef = 0x88;
            handle.seg._0_1_ = (char)*(undefined2 *)(iVar12 + 0x13);
            handle.ofs = *(undefined2 *)(iVar12 + 0x11);
            handle.seg._1_1_ = (char)((uint)*(undefined2 *)(iVar12 + 0x13) >> 8);
            stshFree(handle);
            iVar12 = CONCAT11(uVar39,uVar38);
            uVar24 = (undefined2)(CONCAT13(bStack_3,CONCAT12(bStack_4,iVar12)) >> 0x10);
            *(undefined2 *)(iVar12 + 0x13) = 0;
            *(undefined2 *)(iVar12 + 0x11) = 0;
            bVar29 = true;
            in_stack_0000fff0 = uVar40;
            in_stack_0000fff1 = uVar16;
          }
          else {
            if (*(uint *)(CONCAT11(uVar39,uVar38) + 0x13) < uVar17) {
              uVar23 = *(uint *)(CONCAT11(uVar39,uVar38) + 0x13);
              in_stack_0000ffee = uVar38;
              in_stack_0000ffef = uVar39;
              in_stack_0000fff0 = bStack_4;
              in_stack_0000fff1 = bStack_3;
              uVar9 = uVar17;
            }
            if (*(uint *)(CONCAT11(uVar39,uVar38) + 0x13) < HeapPtr) {
              HeapPtr = *(uint *)(CONCAT11(uVar39,uVar38) + 0x13);
            }
          }
        }
        iVar12 = CONCAT11(uVar39,uVar38);
        uVar24 = (undefined2)(CONCAT13(bStack_3,CONCAT12(bStack_4,iVar12)) >> 0x10);
        bStack_4 = (byte)*(undefined2 *)(iVar12 + 0xb);
        bStack_3 = (byte)((uint)*(undefined2 *)(iVar12 + 0xb) >> 8);
        uVar38 = (undefined1)*(undefined2 *)(iVar12 + 9);
        uVar39 = (undefined1)((uint)*(undefined2 *)(iVar12 + 9) >> 8);
        uVar17 = uVar23;
      }
      if (!bVar29) {
        if (uVar17 == 0xffff) {
          bVar29 = ovr_fmFreeAudio(1);
          if (bVar29) {
            return (char *)0x1;
          }
          if (DAT_2410_2a4e == '\0') {
                    /* WARNING: Subroutine does not return */
            ovr_stExit(0x14);
          }
          return (char *)0x0;
        }
        iVar12 = CONCAT11(in_stack_0000ffef,in_stack_0000ffee);
        uVar24 = (undefined2)
                 (CONCAT13(in_stack_0000fff1,CONCAT12(in_stack_0000fff0,iVar12)) >> 0x10);
        uVar38 = 0x39;
        uVar39 = 0x89;
        handle_00.seg._0_1_ = (char)*(undefined2 *)(iVar12 + 0x13);
        handle_00.ofs = *(undefined2 *)(iVar12 + 0x11);
        handle_00.seg._1_1_ = (char)((uint)*(undefined2 *)(iVar12 + 0x13) >> 8);
        stshFree(handle_00);
        HeapPtr = uVar9;
        iVar12 = CONCAT11(uVar39,uVar38);
        uVar24 = (undefined2)(CONCAT13(uVar16,CONCAT12(uVar40,iVar12)) >> 0x10);
        *(undefined2 *)(iVar12 + 0x13) = 0;
        *(undefined2 *)(iVar12 + 0x11) = 0;
      }
    }
    return (char *)0x1;
  case 1:
    *puVar20 = *puVar20;
    do {
      fVar30 = stshSprite(*(int16_t *)
                           ((int)AgntGs[0].sprfls + 6 + (int)pcVar22 * 0x95 + (int)unaff_DI * 2),
                          (anm_t *)CONCAT22(unaff_SI,*(anm_t **)(puVar20 + 0x26fe)),
                          CONCAT11(uVar38,bVar42),(bool)uVar39);
      iVar12 = (int)pcVar22 * 0x95 + (int)unaff_DI * 4;
      *(uint16_t *)((int)AgntGs[0].sprs + 0xe + iVar12) = fVar30.seg;
      *(uint16_t *)((int)AgntGs[0].sprs + 0xc + iVar12) = fVar30.ofs;
      while( true ) {
        unaff_DI = unaff_DI + 1;
        while (2 < (int)unaff_DI) {
          for (iVar12 = 0; iVar12 < 6; iVar12 = iVar12 + 1) {
            if (*(int *)((int)AgntGs[0].prtfls + (int)pcVar22 * 0x95 + iVar12 * 2) != 0) {
              if (param_1._0_1_ == false) {
                fVar30 = ovr_stshAllocStub();
                iVar13 = (int)pcVar22 * 0x95 + iVar12 * 4;
                *(uint16_t *)((int)AgntGs[0].prts + 2 + iVar13) = fVar30.seg;
                *(uint16_t *)((int)AgntGs[0].prts + iVar13) = fVar30.ofs;
                fVar30 = ovr_stshAllocStub();
                iVar13 = (int)pcVar22 * 0x95 + iVar12 * 4;
                *(uint16_t *)((int)AgntGs[0].prtpals + 2 + iVar13) = fVar30.seg;
                *(uint16_t *)((int)AgntGs[0].prtpals + iVar13) = fVar30.ofs;
              }
              else {
                psVar31 = ovr_grabLbm(*(int16_t *)
                                       ((int)AgntGs[0].prtfls + (int)pcVar22 * 0x95 + iVar12 * 2),0,
                                      0);
                uVar24 = (undefined2)((ulong)psVar31 >> 0x10);
                bStack_4 = (byte)((ulong)psVar31 >> 0x10);
                bStack_3 = (byte)((ulong)psVar31 >> 0x18);
                ovr_stshUniqueColorsRemap((stg_tmp_t *)CONCAT13(bStack_3,CONCAT12(bStack_4,uVar24)))
                ;
                uVar27 = ((DW *)&IdFORM)->lo;
                pixels.seg._0_1_ = (char)uVar27;
                pixels.ofs = *(undefined2 *)((char *)"Error 4 %d \r" + 0xb);
                pixels.seg._1_1_ = (char)(uVar27 >> 8);
                data = (uint8_t *)ovr_stshRleType2(pixels,0,0,114,103,0,0);
                pcVar32 = ovr_stshStoreFile(data);
                iVar13 = (int)pcVar22 * 0x95 + iVar12 * 4;
                *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar13) = (int)((ulong)pcVar32 >> 0x10);
                *(undefined2 *)((int)AgntGs[0].prts + iVar13) = (cte_t *)pcVar32;
                uVar33 = ovr_stshWrite((uint8_t *)0x0,0x300);
                iVar13 = (int)pcVar22 * 0x95 + iVar12 * 4;
                *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar13) = (int)(uVar33 >> 0x10);
                *(undefined2 *)((int)AgntGs[0].prtpals + iVar13) = (int)uVar33;
                ovr_stgFreeTmp((stg_tmp_t *)CONCAT13(bStack_3,CONCAT12(bStack_4,uVar24)));
              }
            }
          }
          pcVar28 = (char *)(*(uint *)((int)AgntGs[0].prts + 4 + (int)pcVar22 * 0x95) |
                            *(uint *)((int)AgntGs[0].prts + 6 + (int)pcVar22 * 0x95));
          if ((pcVar28 == (char *)0x0) &&
             (pcVar28 = (char *)0x0,
             *(int *)((int)AgntGs[0].prts + (int)pcVar22 * 0x95) != 0 ||
             *(int *)((int)AgntGs[0].prts + 2 + (int)pcVar22 * 0x95) != 0)) {
            uVar24 = *(undefined2 *)((int)AgntGs[0].prts + (int)pcVar22 * 0x95);
            *(undefined2 *)((int)AgntGs[0].prts + 6 + (int)pcVar22 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].prts + 2 + (int)pcVar22 * 0x95);
            *(undefined2 *)((int)AgntGs[0].prts + 4 + (int)pcVar22 * 0x95) = uVar24;
            pcVar28 = (char *)*(uint *)((int)AgntGs[0].prtpals + (int)pcVar22 * 0x95);
            *(undefined2 *)((int)AgntGs[0].prtpals + 6 + (int)pcVar22 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].prtpals + 2 + (int)pcVar22 * 0x95);
            *(uint *)((int)AgntGs[0].prtpals + 4 + (int)pcVar22 * 0x95) = (uint)pcVar28;
          }
          for (iVar12 = 2; iVar12 < 6; iVar12 = iVar12 + 2) {
            iVar13 = (int)pcVar22 * 0x95 + iVar12 * 4;
            if ((*(int *)((int)AgntGs[0].prts + 4 + iVar13) == 0 &&
                 *(int *)((int)AgntGs[0].prts + 6 + iVar13) == 0) &&
               (iVar13 = (int)pcVar22 * 0x95 + iVar12 * 4,
               *(int *)((int)AgntGs[0].prtfls + 8 + iVar13) != 0 ||
               *(int *)((int)AgntGs[0].prtfls + 10 + iVar13) != 0)) {
              iVar13 = (int)pcVar22 * 0x95 + iVar12 * 4;
              uVar24 = *(undefined2 *)((int)AgntGs[0].prtfls + 8 + iVar13);
              iVar10 = (int)pcVar22 * 0x95 + iVar12 * 4;
              *(undefined2 *)((int)AgntGs[0].prts + 6 + iVar10) =
                   *(undefined2 *)((int)AgntGs[0].prtfls + 10 + iVar13);
              *(undefined2 *)((int)AgntGs[0].prts + 4 + iVar10) = uVar24;
              iVar13 = (int)pcVar22 * 0x95 + iVar12 * 4;
              uVar24 = *(undefined2 *)((int)AgntGs[0].prts + 0x14 + iVar13);
              iVar10 = (int)pcVar22 * 0x95 + iVar12 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 6 + iVar10) =
                   *(undefined2 *)((int)AgntGs[0].prts + 0x16 + iVar13);
              *(undefined2 *)((int)AgntGs[0].prtpals + 4 + iVar10) = uVar24;
            }
            iVar13 = (int)pcVar22 * 0x95 + iVar12 * 4;
            pcVar28 = (char *)(*(uint *)((int)AgntGs[0].prts + iVar13) |
                              *(uint *)((int)AgntGs[0].prts + 2 + iVar13));
            if (pcVar28 == (char *)0x0) {
              iVar13 = (int)pcVar22 * 0x95 + iVar12 * 4;
              if (*(int *)((int)AgntGs[0].prtfls + 4 + iVar13) == 0 &&
                  *(int *)((int)AgntGs[0].prtfls + 6 + iVar13) == 0) {
                pcVar28 = (char *)0x0;
              }
              else {
                iVar13 = (int)pcVar22 * 0x95 + iVar12 * 4;
                uVar24 = *(undefined2 *)((int)AgntGs[0].prtfls + 4 + iVar13);
                iVar10 = (int)pcVar22 * 0x95 + iVar12 * 4;
                *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar10) =
                     *(undefined2 *)((int)AgntGs[0].prtfls + 6 + iVar13);
                *(undefined2 *)((int)AgntGs[0].prts + iVar10) = uVar24;
                iVar13 = (int)pcVar22 * 0x95 + iVar12 * 4;
                pcVar28 = (char *)*(uint *)((int)AgntGs[0].prts + 0x10 + iVar13);
                iVar10 = (int)pcVar22 * 0x95 + iVar12 * 4;
                *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar10) =
                     *(undefined2 *)((int)AgntGs[0].prts + 0x12 + iVar13);
                *(uint *)((int)AgntGs[0].prtpals + iVar10) = (uint)pcVar28;
              }
            }
          }
          pcVar22 = pcVar22 + 1;
          if (0x29 < (int)pcVar22) {
            return pcVar28;
          }
          fVar30 = stshSprite(*(int16_t *)((int)AgntGs[0].sprfls + (int)pcVar22 * 0x95),
                              (anm_t *)CONCAT22(*(undefined2 *)
                                                 ((int)&AgntGs[0].anms + 2 + (int)pcVar22 * 0x95),
                                                (anm_t *)*(undefined2 *)
                                                          ((int)&AgntGs[0].anms +
                                                          (int)pcVar22 * 0x95)),
                              (uint)*(byte *)((int)&AgntGs[0].nanims + (int)pcVar22 * 0x95),
                              param_1._0_1_);
          *(uint16_t *)((int)AgntGs[0].sprs + 2 + (int)pcVar22 * 0x95) = fVar30.seg;
          *(uint16_t *)((int)AgntGs[0].sprs + (int)pcVar22 * 0x95) = fVar30.ofs;
          if (*(int *)((int)AgntGs[0].sprfls + 2 + (int)pcVar22 * 0x95) == 0) {
            uVar24 = *(undefined2 *)((int)AgntGs[0].sprs + (int)pcVar22 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 6 + (int)pcVar22 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].sprs + 2 + (int)pcVar22 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 4 + (int)pcVar22 * 0x95) = uVar24;
          }
          else {
            fVar30 = stshSprite(*(int16_t *)((int)AgntGs[0].sprfls + 2 + (int)pcVar22 * 0x95),
                                (anm_t *)CONCAT22(*(undefined2 *)
                                                   ((int)&AgntGs[0].anms + 2 + (int)pcVar22 * 0x95),
                                                  (anm_t *)*(undefined2 *)
                                                            ((int)&AgntGs[0].anms +
                                                            (int)pcVar22 * 0x95)),
                                (uint)*(byte *)((int)&AgntGs[0].nanims + (int)pcVar22 * 0x95),
                                param_1._0_1_);
            *(uint16_t *)((int)AgntGs[0].sprs + 6 + (int)pcVar22 * 0x95) = fVar30.seg;
            *(uint16_t *)((int)AgntGs[0].sprs + 4 + (int)pcVar22 * 0x95) = fVar30.ofs;
          }
          if (*(int *)((int)AgntGs[0].sprfls + 4 + (int)pcVar22 * 0x95) == 0) {
            uVar24 = *(undefined2 *)((int)AgntGs[0].sprs + 4 + (int)pcVar22 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 10 + (int)pcVar22 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].sprs + 6 + (int)pcVar22 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 8 + (int)pcVar22 * 0x95) = uVar24;
          }
          else {
            fVar30 = stshSprite(*(int16_t *)((int)AgntGs[0].sprfls + 4 + (int)pcVar22 * 0x95),
                                (anm_t *)CONCAT22(*(undefined2 *)
                                                   ((int)&AgntGs[0].anms + 2 + (int)pcVar22 * 0x95),
                                                  (anm_t *)*(undefined2 *)
                                                            ((int)&AgntGs[0].anms +
                                                            (int)pcVar22 * 0x95)),
                                (uint)*(byte *)((int)&AgntGs[0].nanims + (int)pcVar22 * 0x95),
                                param_1._0_1_);
            *(uint16_t *)((int)AgntGs[0].sprs + 10 + (int)pcVar22 * 0x95) = fVar30.seg;
            *(uint16_t *)((int)AgntGs[0].sprs + 8 + (int)pcVar22 * 0x95) = fVar30.ofs;
          }
          unaff_DI = (char *)0x0;
        }
        if (*(int *)((int)AgntGs[0].sprfls + 6 + (int)pcVar22 * 0x95 + (int)unaff_DI * 2) != 0)
        break;
        iVar12 = (int)pcVar22 * 0x95 + (int)unaff_DI * 4;
        uVar24 = *(undefined2 *)((int)AgntGs[0].sprs + iVar12);
        iVar13 = (int)pcVar22 * 0x95 + (int)unaff_DI * 4;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar13) =
             *(undefined2 *)((int)AgntGs[0].sprs + 2 + iVar12);
        *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar13) = uVar24;
      }
      bVar42 = *(byte *)((int)&AgntGs[0].nanims + (int)pcVar22 * 0x95);
      uVar38 = 0;
      puVar20 = (undefined1 *)((int)pcVar22 * 0x95);
      unaff_SI = *(undefined2 *)(puVar20 + 0x2700);
      uVar39 = param_1._0_1_;
    } while( true );
  case 2:
    return (char *)(uVar9 & 0xff8e);
  case 3:
switchD_4000_4790_caseD_3:
    cVar3 = *(char *)(Entities.ofs + uVar9 + 0x32);
    cVar5 = (char)(uVar9 >> 8);
    *(char *)(Entities.ofs + (int)pcVar22 * 0x37 + 0x31) = cVar3;
    if (EntityCount <= pcVar22 + 1) {
      if ((cVar3 != '\0') || (cVar5 != '\0')) {
        if (bStack_3 == 0) {
          ovr_stop_audio();
          CurSfxType3 = 0xff;
          ovr_play_sfx(90,0);
        }
        else if (cVar5 == '\0') {
          if (cVar3 != '\0') {
            ovr_play_sfx(37,0);
          }
        }
        else {
          ovr_play_sfx(35,0);
        }
      }
      GGameState = 0x3d;
      if (DebugVerbose != false) {
        printf("%d \r",0x3d);
      }
      pcVar22 = (char *)ovr_OVC23_55fe_2b82();
      return pcVar22;
    }
    pcVar22 = (char *)"thief" + 5;
    ovr_say((char *)CONCAT13(in_stack_0000fff5,
                             CONCAT12(in_stack_0000fff4,
                                      (char *)
                                      "The damaged structures belonging to all leaders are highlighted in red."
                                     )));
    return pcVar22;
  case 4:
    in_CX = (uint *)CONCAT11((char)((uint)in_CX >> 8),(char)in_CX + unaff_DI[-0x63b2]);
    do {
      puVar21 = (uint *)(puVar20 + (int)in_CX);
      puVar21[1] = uVar9;
      *puVar21 = uVar17;
      while( true ) {
        unaff_DI = unaff_DI + 1;
        pcVar22 = pcVar22 + 1;
LAB_4d05_2ee8:
        if ((int)(uint)in_stack_0000fff5 <= (int)pcVar22) {
          cVar3 = '@';
          manage_4d05_0081();
          if (cVar3 != '\x02') goto LAB_3f0b_11ea;
          if (DAT_2410_26a8 == '\0') {
            manage_4d05_0081();
          }
          TextBlitY = 0xc;
          TextBlitX = 0x11;
          uVar16 = (undefined1)Font02.seg;
          uVar37 = (undefined1)(Font02.seg >> 8);
          cVar3 = (char)Font02.ofs;
          uVar38 = (undefined1)(Font02.ofs >> 8);
          if (param_1._0_1_ != true) {
            term = 0x50;
            uVar15 = 0xde;
            uVar14 = 0;
            ovr_OVC45_77eb_226e();
            func_0x0005d3f4();
            pcStackY_2a = (char *)"trade faire" + 8;
            uStackY_2c = 0x44;
            text = ovr_stsprintf(acStackY_13e,"%s population, loyal to %s%s",
                                 (char *)*(undefined2 *)
                                          ((uint)*(byte *)(CONCAT11(uVar37,uVar16) + 0x2f) * 4 +
                                          0xeb));
            ovr_blitLabel(text,(uint8_t *)CONCAT13(uVar37,CONCAT12(uVar16,CONCAT11(uVar38,cVar3))),
                          CONCAT11(uVar14,uVar15),term);
            TextBlitY = TextBlitY + 0xc;
            iVar12 = ovr_font_302d_06ea();
            TextBlitX = 0x89 - iVar12;
            ovr_blitLabel("UNITS",(uint8_t *)
                                  CONCAT13((char)(Font02.seg >> 8),
                                           CONCAT12((char)Font02.seg,Font02.ofs)),222,0xe0);
            iVar12 = ovr_font_302d_06ea();
            uVar27 = 0xd4 - iVar12;
            TextBlitX = uVar27;
            ovr_blitLabel("POPULATION",
                          (uint8_t *)
                          CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs)),
                          222,0xe0);
            pcVar22 = (char *)0x0;
            while( true ) {
              TextBlitY = TextBlitY + 0xc;
              cVar3 = (char)in_CX;
              uVar38 = (undefined1)((uint)unaff_SS >> 8);
              if ((int)(uint)in_stack_0000fff5 <= (int)pcVar22) break;
              TextBlitX = 0x11;
              uVar16 = (undefined1)(Font02.seg >> 8);
              if (((int)pcVar22 < 5) || (in_stack_0000fff4 == 0)) {
                ovr_blitLabel((char *)CONCAT22(auStackY_96[(int)pcVar22 * 2 + 1],
                                               (char *)auStackY_96[(int)pcVar22 * 2]),
                              (uint8_t *)CONCAT13(uVar16,CONCAT12((char)Font02.seg,Font02.ofs)),319,
                              0xe0);
              }
              else {
                uVar11 = (uint)*(byte *)((int)*(undefined4 *)((uint)param_1._0_1_ << 2) + 0x2f);
                ovr_blitLabel((char *)CONCAT22(auStackY_11a[(int)pcVar22 * 2 + uVar11 * 8 + 1],
                                               (char *)auStackY_11a[(int)pcVar22 * 2 + uVar11 * 8]),
                              (uint8_t *)CONCAT13(uVar16,CONCAT12((char)Font02.seg,Font02.ofs)),319,
                              0xe0);
              }
              pcVar28 = &stack0xffec;
              OVC27_5ded_1433();
              ovr_stsprintf(acStackY_13e,"%d",pcVar28);
              iVar12 = ovr_font_302d_06ea();
              TextBlitX = 0x89 - iVar12;
              pcVar28 = (char *)Font02.ofs;
              ovr_blitLabel((char *)CONCAT13(uVar38,CONCAT12((char)unaff_SS,acStackY_13e)),
                            (uint8_t *)
                            CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs)),
                            222,0x50);
              ovr_stsprintf(acStackY_13e,"%d",pcVar28);
              iVar12 = ovr_font_302d_06ea();
              uVar27 = 0xd4 - iVar12;
              TextBlitX = uVar27;
              ovr_blitLabel((char *)CONCAT13(uVar38,CONCAT12((char)unaff_SS,acStackY_13e)),
                            (uint8_t *)
                            CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs)),
                            222,0x50);
              pcVar22 = pcVar22 + 1;
            }
            CurSfxType3 = 0x3c;
            cVar5 = ovr_OVC28_6018_1398();
            DAT_2410_5cf0 = 0;
            if (((cVar5 != '\0') && (cVar5 != '\x01')) && (cVar5 != -2)) {
              (&stack0xbac4)[(int)unaff_DI] = (&stack0xbac4)[(int)unaff_DI] + cVar3;
              pcVar28 = (char *)"puppetmaker" + 3;
              do {
                iVar12 = (int)pcVar28 * uVar27;
                pcVar28 = pcVar22;
                if (*(byte *)((int)pcVar22 * 0x34 + 0x22) < *(byte *)(iVar12 + 0x21)) {
                  *(undefined1 *)((int)pcVar22 * 0x34 + 0x21) =
                       *(undefined1 *)((int)pcVar22 * 0x34 + 0x22);
                }
                do {
                  pcVar28 = pcVar28 + 1;
                  if ((int)(uint)AgntCount <= (int)pcVar28) {
                    uVar27 = ovr_audio_3a5b_0afd();
                    ovr_play_sfxU(0x1c,0,uVar27);
                    return (char *)0x1;
                  }
                } while (*(int *)((int)pcVar28 * 0x34 + 0x1b) != *(int *)((char *)param_2 + 0x1b));
                if (*(byte *)(CONCAT11(uVar40,uVar39) + 0x32) <
                    *(byte *)((int)pcVar28 * 0x34 + 0x22)) {
                  *(undefined1 *)((int)pcVar28 * 0x34 + 0x22) =
                       *(undefined1 *)(CONCAT11(uVar40,uVar39) + 0x32);
                }
                uVar27 = 0x34;
                pcVar22 = pcVar28;
              } while( true );
            }
            if (cVar5 == -2) {
              DAT_2410_4926 = 1;
            }
            return (char *)"puppetmaker" + 3;
          }
          iVar12 = ovr_blitLabel("Total population.",
                                 (uint8_t *)CONCAT13(uVar37,CONCAT12(uVar16,Font02.ofs)),222,0x50);
          *pcVar22 = *pcVar22 + (char)((uint)iVar12 >> 8) + ((undefined1 *)0xfff3 < &stack0xffe8);
          *(undefined1 *)((*(far_t *)&Entities).ofs + iVar12 + 0x18) = 0;
          uVar9 = (int)pcVar22 * 0x37;
          goto switchD_4000_4790_caseD_3;
        }
        if ((4 < (int)pcVar22) && (in_stack_0000fff4 != 0)) break;
        uVar17 = auStackY_96[(int)pcVar22 * 2];
        in_CX = auStackY_66;
        puVar21 = in_CX + (int)unaff_DI * 2;
        auStackY_66[(int)unaff_DI * 2 + 1] = auStackY_96[(int)pcVar22 * 2 + 1];
        *puVar21 = uVar17;
      }
      uVar27 = (uint16_t)((ulong)*(undefined4 *)((uint)param_1._0_1_ << 2) >> 0x10);
      uVar11 = (uint)*(byte *)((int)*(undefined4 *)((uint)param_1._0_1_ << 2) + 0x2f);
      uVar9 = auStackY_11a[(int)pcVar22 * 2 + uVar11 * 8 + 1];
      uVar17 = auStackY_11a[(int)pcVar22 * 2 + uVar11 * 8];
      puVar20 = (undefined1 *)((int)unaff_DI << 2);
      in_CX = auStackY_66;
    } while( true );
  case 5:
    puVar1 = (uint *)(&stack0xc1dd + (int)unaff_DI);
    uVar11 = *puVar1;
    *puVar1 = *puVar1 - 1;
    if (in_CX == (uint *)0x0) {
      in_stack_0000fff5 =
           (in_NT & 1) * '@' | SBORROW2(uVar11,1) * '\b' | (in_IF & 1) * '\x02' | in_TF & 1;
      in_stack_0000fff4 =
           ((int)*puVar1 < 0) * -0x80 | (*puVar1 == 0) * '@' |
           (9 < (bStack_3 & 0xf) | in_AF & 1) * '\x10' |
           ((POPCOUNT(*puVar1 & 0xff) & 1U) == 0) * '\x04';
    }
    (auStackY_66 + 1)[uVar9] = (uint)((char *)"puppetmaker" + 3);
    *(char **)(puVar20 + (int)auStackY_66) = (char *)"Done";
    auStackY_66[(int)(unaff_DI + 1) * 2 + 1] = (uint)((char *)"puppetmaker" + 3);
    auStackY_66[(int)(unaff_DI + 1) * 2] = (uint)(char *)"Summary";
    puVar21 = auStackY_66 + (int)(unaff_DI + 2) * 2;
    auStackY_66[(int)(unaff_DI + 2) * 2 + 1] = (uint)((char *)"puppetmaker" + 3);
    *puVar21 = (uint)(char *)"All levels";
    unaff_DI = unaff_DI + 3;
    pcVar22 = (char *)0x0;
    goto LAB_4d05_2ee8;
  }
  if ((uVar9 != 0) || ((uint)BuildingTypes[0x76]._24_2_ < 0x195d)) {
    uVar11 = ((FMXmsHandle._2_2_ + FMEmsHandle._2_2_ +
              (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - StshPtrs[0]._2_2_) -
             (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
    if ((uVar11 < CONCAT11(in_stack_0000fff3,in_stack_0000fff2)) ||
       ((uVar11 <= CONCAT11(in_stack_0000fff3,in_stack_0000fff2) &&
        (((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0] <=
         CONCAT11(in_stack_0000fff1,in_stack_0000fff0))))) {
      iVar12 = ((FMXmsHandle._2_2_ + FMEmsHandle._2_2_ +
                (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - StshPtrs[0]._2_2_) -
               (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
    }
    else {
      iVar12 = CONCAT11(in_stack_0000fff3,in_stack_0000fff2);
    }
    uVar38 = (undefined1)iVar12;
    uVar39 = (undefined1)((uint)iVar12 >> 8);
    iVar13 = (StshPtrs[0]._2_2_ - FMXmsHandle._2_2_) - (uint)((uint)StshPtrs[0] < (uint)FMXmsHandle)
    ;
    ovr_mkp(uVar26,(uint16_t)(char *)param_2);
    ems_memmove1();
    bVar29 = CARRY2((uint)StshPtrs[0],CONCAT11(uVar39,uVar38));
    StshPtrs[0]._0_2_ = (uint)StshPtrs[0] + CONCAT11(uVar39,uVar38);
    StshPtrs[0]._2_2_ = StshPtrs[0]._2_2_ + iVar12 + (uint)bVar29;
    uVar11 = iVar13 - CONCAT11(uVar39,uVar38);
    bVar41 = 0;
    pcVar28 = (char *)0x1000;
    in_stack_0000fff2 = 0xcb;
    in_stack_0000fff3 = 0x77;
    LXURSH_at_(CONCAT22(iVar12,CONCAT11(uVar39,uVar38)),0x4);
    param_2 = (char *)((ulong)param_2._2_2_ << 0x10);
    param_1 = (code *)CONCAT22(uVar26 + (bVar41 & 0xf),pcVar19);
  }
  uVar17 = FMXmsHandle._2_2_ + FMEmsHandle._2_2_ + (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)
  ;
  if ((uVar17 <= StshPtrs[0]._2_2_) &&
     ((uVar17 != StshPtrs[0]._2_2_ || ((uint)FMXmsHandle + (uint)FMEmsHandle <= (uint)StshPtrs[0])))
     ) {
    in_stack_0000fff2 = (undefined1)StshPtrs[0]._2_2_;
    in_stack_0000fff3 = (undefined1)(StshPtrs[0]._2_2_ >> 8);
    uVar38 = (undefined1)(uint)StshPtrs[0];
    uVar39 = (undefined1)((uint)StshPtrs[0] >> 8);
    pcVar28 = (char *)0x1000;
    lseek(StshHandles[0],CONCAT13(in_stack_0000fff3,CONCAT12(in_stack_0000fff2,(uint)StshPtrs[0])),0
         );
    uVar11 = CONCAT11(uVar39,uVar38);
  }
  iVar12 = StshHandles[0];
  pcVar22 = (char *)CONCAT11(in_stack_0000fff3,in_stack_0000fff2);
  if (uVar11 == 0 && pcVar22 == (char *)0x0) {
    pcVar22 = (char *)(bVar42 - param_2._2_2_);
  }
  else {
    bStack_4 = (byte)StshHandles[0];
    bStack_3 = (byte)((uint)StshHandles[0] >> 8);
    while( true ) {
      if ((pcVar22 == (char *)0x0) && (uVar11 == 0)) goto next_iteration;
      if ((pcVar22 != (char *)0x0) || (0xc000 < uVar11)) {
        uVar11 = 0xc000;
      }
      cVar3 = (char)pcVar28;
      uVar38 = (undefined1)((uint)pcVar28 >> 8);
      pcVar22 = (char *)"Forest claimed. This forest creates %d gold of income and feeds %d %s." +
                0x3e;
      bVar41 = bStack_4;
      bVar4 = bStack_3;
      uVar17 = read(iVar12,param_1._2_2_,uVar11);
      if (uVar17 != CONCAT11(bVar4,bVar41)) break;
      pcVar22 = pcVar22 + uVar17;
      uVar39 = 0;
      uVar40 = 0x10;
      pcVar28 = (char *)"arrowsmith" + 3;
      pvVar36 = (void *)ovr_mkp((uint16_t)pcVar22,CONCAT11(uVar38,cVar3));
      uVar11 = CONCAT11(uVar40,uVar39);
      param_1._2_2_ = (void *)pvVar36;
      bVar29 = CARRY2((uint)StshPtrs[0],uVar17);
      StshPtrs[0]._0_2_ = (uint)StshPtrs[0] + uVar17;
      StshPtrs[0]._2_2_ = StshPtrs[0]._2_2_ + bVar29;
    }
    printf("File read error %s \r",(char *)StshNames[0]);
    ovr_biosReadKey();
next_iteration:
    pcVar22 = (char *)(bVar42 - param_2._2_2_);
  }
  return pcVar22;
LAB_3f0b_11ea:
  uVar24 = (undefined2)((ulong)puStack_1e >> 0x10);
  puVar18 = (uint *)puStack_1e;
  *(byte *)(puVar18 + 6) =
       (byte)((int)(uint)*(byte *)((int)puVar18 +
                                  ((int)(uint)*(byte *)((int)puVar21 + 0x2f) >> 2) + 0x1b) >>
             ((*(byte *)((int)puVar18 + 0x2f) & 3) << 1)) & 3;
  cVar3 = func_0x0004f32d();
  if (cVar3 == '\0') {
    *puStack_1e = *puStack_1e + (int)*(char *)((byte)puVar18[6] + 0x885);
    puVar18[1] = puVar18[1] + (int)*(char *)((byte)puVar18[6] + 0x889);
    *(char *)((int)puVar18 + 0x2f) = *(char *)((int)puVar18 + 0x2f) + '\x01';
  }
  else {
    *(undefined1 *)((int)puVar18 + 0x2f) = 0;
    *(undefined1 *)(puVar18 + 0x18) = 0;
  }
LAB_3f0b_1477:
  do {
    cVar3 = '\x01';
    uVar25 = (undefined2)((ulong)puStack_1e >> 0x10);
    puVar21 = (uint *)puStack_1e;
    uVar24 = ovr_OVC23_55fe_3450();
    uVar16 = (undefined1)uVar24;
    uVar37 = (undefined1)((uint)uVar24 >> 8);
    iVar12 = ovr_OVC23_55fe_3450();
    if ((CONCAT11(uVar37,uVar16) == iVar12) && (puVar21[5] == puVar21[1])) {
      puVar21[4] = 0;
      puVar21[5] = 0;
      if ((char)puVar21[0xd] == -1) {
        bStack_4 = 0xff;
      }
      else {
        uVar2 = *(undefined4 *)((uint)(byte)puVar21[0xd] << 2);
        bStack_4 = *(byte *)((int)uVar2 + 0x89);
      }
      if (bStack_4 != 0xff) {
        for (uVar11 = 0; uVar11 < DAT_2410_0881; uVar11 = uVar11 + 1) {
          uVar24 = ovr_OVC23_55fe_3450();
          uVar16 = (undefined1)uVar24;
          uVar37 = (undefined1)((uint)uVar24 >> 8);
          iVar12 = ovr_OVC23_55fe_3450();
          if ((CONCAT11(uVar37,uVar16) == iVar12) && (*(uint *)(uVar11 * 0x13 + 2) == puVar21[1])) {
            manage_4d05_28e0();
            if (*(uint *)(uVar11 * 0x13 + 2) == GfxRndSeed2) {
              uVar24 = ovr_OVC23_55fe_3450();
              uVar16 = (undefined1)uVar24;
              uVar37 = (undefined1)((uint)uVar24 >> 8);
              iVar12 = ovr_OVC23_55fe_3450();
              if (CONCAT11(uVar37,uVar16) == iVar12) {
                (&stack0xfff2)[bStack_4] = 1;
              }
            }
            break;
          }
        }
      }
    }
    cVar5 = '#';
    if (AgntFlag1 != false) {
      if (((*puStack_1e < GfxRndSeed - 2U) || (GfxRndSeed + 1U < *puStack_1e)) ||
         (puVar21[1] != GfxRndSeed2)) {
        bVar29 = false;
      }
      else {
        bVar29 = true;
      }
      if (((CONCAT11(uVar40,uVar39) < GfxRndSeed - 2U) ||
          (GfxRndSeed + 1U < CONCAT11(uVar40,uVar39))) || (GfxRndSeed2 != CONCAT11(uVar38,bVar42)))
      {
        bVar6 = false;
      }
      else {
        bVar6 = true;
      }
      if (bVar6 || bVar29) {
        if (bVar6) {
          if (bVar29) {
            for (cVar7 = manage_4d05_28f4(); cVar5 = '#', cVar7 != '\0'; cVar7 = cVar7 + -1) {
              cVar5 = '#';
              cVar8 = ovr_OVC15_4207_2301();
              if (cVar8 == '\0') break;
            }
          }
          else {
            cVar7 = (char)((ulong)((byte)puVar21[7] + 0xf) / 0x10);
            while (cVar8 = cVar7 + -1, cVar7 != '\0') {
              cVar5 = '\"';
              fVar30.seg._0_1_ = (char)Entities.seg;
              fVar30.ofs = Entities.ofs + (int)unaff_DI * 0x37;
              fVar30.seg._1_1_ = Entities.seg._1_1_;
              ovr_agnt_3b1d_196b(fVar30);
              cVar7 = cVar8;
            }
          }
        }
        else {
          ovr_OVC15_4207_0b88();
          cVar7 = (char)((ulong)((byte)puVar21[7] + 0xf) / 0x10);
          while( true ) {
            cVar5 = '#';
            cVar8 = cVar7 + -1;
            if (cVar7 == '\0') break;
            ovr_OVC15_4207_2301();
            cVar7 = cVar8;
          }
        }
      }
    }
    do {
      unaff_DI = unaff_DI + 1;
      if (EntityCount <= unaff_DI) {
        GGameState = 0x3c;
        cVar7 = cVar5;
        if (DebugVerbose != false) {
          cVar7 = '\x10';
          printf("%d %d %d  \r",0x3c);
          cVar3 = cVar5;
        }
        func_0x0004fcda();
        GGameState = 0x3d;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r",0x3d);
          cVar3 = cVar7;
        }
        ovr_OVC23_55fe_2b82();
        GGameState = 0xc;
        if (DebugVerbose != false) {
          cVar3 = '#';
          printf("%d %d %d  \r",0xc);
        }
        ovr_OVC24_5943_0d5a();
        GGameState = 0x1f;
        if (cVar3 != '\0') {
          ovr_constr_36ce_03a6();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (iVar12 = 0; iVar12 < 5; iVar12 = iVar12 + 1) {
          if ((&stack0xfff2)[iVar12] != '\0') {
            ovr_OVC41_6a8f_1be0();
          }
        }
        GGameState = 0xd;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r",0xd);
        }
        ovr_OVC24_5943_112e();
        GGameState = 0xe;
        DAT_2410_648e = 1;
        return (char *)"puppetmaker" + 3;
      }
      puVar21 = (uint *)(Entities.ofs + (int)unaff_DI * 0x37);
      uVar27 = Entities.seg;
      puStack_1e = (uint *)CONCAT22(uVar27,puVar21);
      uVar24 = ovr_OVC23_55fe_3450();
      uVar38 = (undefined1)uVar24;
      uVar39 = (undefined1)((uint)uVar24 >> 8);
      cVar5 = '#';
      iVar12 = ovr_OVC23_55fe_3450();
      if ((CONCAT11(uVar39,uVar38) == iVar12) && (puVar21[5] == puVar21[1])) {
        cVar3 = '#';
        manage_4d05_2b3e();
      }
    } while ((puVar21[4] == 0 && puVar21[5] == 0) || ((char)puVar21[0xc] != '\0'));
    uVar39 = (undefined1)*puStack_1e;
    uVar40 = (undefined1)(*puStack_1e >> 8);
    bVar41 = (byte)puVar21[1];
    uVar16 = (undefined1)(puVar21[1] >> 8);
    bVar42 = bVar41;
    uVar38 = uVar16;
    if (*(byte *)((int)puVar21 + 0x2f) < (byte)puVar21[0x18]) goto LAB_3f0b_11ea;
    ovr_OVC07_32c9_0026();
    cVar3 = 'g';
    uVar15 = 3;
    uVar26 = ovr_OVC07_32c9_0026();
    bVar4 = (byte)uVar26;
    uVar37 = (undefined1)(uVar26 >> 8);
    if (CONCAT11(uVar15,cVar3) == 0) {
LAB_3f0b_130a:
      bVar42 = bVar41;
      uVar38 = uVar16;
      if (CONCAT11(uVar37,bVar4) != 0) {
        uVar15 = (undefined1)(uVar26 >> 8);
        cVar3 = bVar4 + 1;
        bVar4 = func_0x0004f412();
        uVar26 = (uint16_t)bVar4;
        if (uVar26 == 0) {
          puVar21[1] = puVar21[1] + CONCAT11(uVar16,bVar41);
          *(byte *)(puVar21 + 6) = bVar41 + 1;
          goto LAB_3f0b_1477;
        }
      }
      if (CONCAT11(uVar15,cVar3) != 0) {
        uVar16 = (undefined1)(uVar26 >> 8);
        cVar3 = '\x02' - cVar3;
        cVar5 = func_0x0004f412();
        if (cVar5 == '\0') {
          *puStack_1e = *puStack_1e + CONCAT11(uVar16,cVar3);
          *(char *)(puVar21 + 6) = '\x02' - cVar3;
          goto LAB_3f0b_1477;
        }
      }
      cVar3 = ovr_OVC26_5d45_031f();
      if (cVar3 == '\0') {
        cVar3 = ovr_OVC26_5d45_06f0();
        if ((cVar3 == '\0') &&
           (*(char *)((int)(char **)GMenuStrings + (uint)*(byte *)((int)puVar21 + 0xd) * 0x95 + 0x1f
                     ) == '\0')) {
          manage_4d05_2b3e();
        }
      }
      else {
        *(byte *)(puVar21 + 6) =
             (byte)((int)(uint)*(byte *)((int)puVar21 +
                                        ((int)(uint)*(byte *)((int)puVar21 + 0x2f) >> 2) + 0x1b) >>
                   ((*(byte *)((int)puVar21 + 0x2f) & 3) << 1)) & 3;
        cVar3 = func_0x0004f32d();
        if (cVar3 == '\0') {
          *puStack_1e = *puStack_1e + (int)*(char *)((byte)puVar21[6] + 0x885);
          puVar21[1] = puVar21[1] + (int)*(char *)((byte)puVar21[6] + 0x889);
          *(char *)((int)puVar21 + 0x2f) = *(char *)((int)puVar21 + 0x2f) + '\x01';
        }
      }
      goto LAB_3f0b_1477;
    }
    cVar3 = 'z';
    uVar15 = 3;
    uVar26 = ovr_randBelow(2);
    uVar14 = (undefined1)(uVar26 >> 8);
    if ((char)uVar26 == '\0') goto LAB_3f0b_130a;
    cVar3 = '\x02' - cVar3;
    bVar42 = bVar41;
    uVar38 = uVar16;
    bVar4 = func_0x0004f412();
    uVar26 = (uint16_t)bVar4;
    bVar4 = bVar41;
    uVar37 = uVar16;
    uVar15 = uVar14;
    bVar41 = bVar42;
    uVar16 = uVar38;
    if (uVar26 != 0) goto LAB_3f0b_130a;
    *puStack_1e = *puStack_1e + CONCAT11(uVar14,cVar3);
    *(char *)(puVar21 + 6) = '\x02' - cVar3;
  } while( true );
}



/* 4207:288b */

bool __cdecl16far OVC15_4207_288b(void)

{
  int iVar1;
  uint uVar2;
  byte bStack_3;
  
  uVar2 = 0;
  iVar1 = ovr_OVC23_55fe_3450(GfxRndSeed);
  for (bStack_3 = 0; bStack_3 < 4; bStack_3 = bStack_3 + 1) {
    uVar2 = uVar2 | *(uint *)((int)DAT_2000_cb09 + GfxRndSeed2 * 0x128 +
                              (iVar1 + (uint)bStack_3) * 2 + -4) & 0x3000;
  }
  return uVar2 == 0x3000;
}



/* 4207:28fa */

void __cdecl16far OVC15_4207_28fa(void)

{
  if (DAT_2000_ca6e < AgntCount) {
    CrossBlitX = *(undefined2 *)((uint)DAT_2000_ca6e * 0x34 + 0x26);
    CrossBlitY = *(int *)((uint)DAT_2000_ca6e * 0x34 + 0x28) + -0x10;
  }
  return;
}



/* 4207:2961 */

char * __cdecl16far OVC15_4207_2961(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cStack_3;
  
  cStack_3 = -1;
  uVar3 = 0x7fff;
  uVar4 = 0x7fff;
  for (iVar2 = 0; iVar2 < (int)(uint)AgntCount; iVar2 = iVar2 + 1) {
    if ((*(uint *)(iVar2 * 0x34 + 0x26) < uVar3) ||
       ((*(uint *)(iVar2 * 0x34 + 0x26) == uVar3 && (*(uint *)(iVar2 * 0x34 + 0x28) < uVar4)))) {
      cStack_3 = (char)iVar2;
      uVar3 = *(uint *)(iVar2 * 0x34 + 0x26);
      uVar4 = *(uint *)(iVar2 * 0x34 + 0x28);
    }
  }
  if (cStack_3 == -1) {
    pcVar1 = (char *)0x0;
  }
  else {
    DAT_2000_ca6e = cStack_3;
    pcVar1 = (char *)"arena" + 5;
  }
  return pcVar1;
}



/* 4207:2a0e */

char * __cdecl16far OVC15_4207_2a0e(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cStack_3;
  
  cStack_3 = -1;
  uVar3 = 0;
  uVar4 = 0;
  for (iVar2 = 0; iVar2 < (int)(uint)AgntCount; iVar2 = iVar2 + 1) {
    if ((uVar3 < *(uint *)(iVar2 * 0x34 + 0x26)) ||
       ((*(uint *)(iVar2 * 0x34 + 0x26) == uVar3 && (uVar4 < *(uint *)(iVar2 * 0x34 + 0x28))))) {
      cStack_3 = (char)iVar2;
      uVar3 = *(uint *)(iVar2 * 0x34 + 0x26);
      uVar4 = *(uint *)(iVar2 * 0x34 + 0x28);
    }
  }
  if (cStack_3 == -1) {
    pcVar1 = (char *)0x0;
  }
  else {
    DAT_2000_ca6e = cStack_3;
    pcVar1 = (char *)"arena" + 5;
  }
  return pcVar1;
}



/* 4207:2ab9 */

char * __cdecl16far OVC15_4207_2ab9(void)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bStack_3;
  
  bStack_3 = 0xff;
  uVar3 = 0x7fff;
  uVar4 = 0x7fff;
  for (uVar2 = 0; (int)uVar2 < (int)(uint)AgntCount; uVar2 = uVar2 + 1) {
    if (((DAT_2000_ca6e != uVar2) &&
        ((*(uint *)((uint)DAT_2000_ca6e * 0x34 + 0x26) < *(uint *)(uVar2 * 0x34 + 0x26) ||
         ((*(int *)((uint)DAT_2000_ca6e * 0x34 + 0x26) == *(int *)(uVar2 * 0x34 + 0x26) &&
          (*(uint *)((uint)DAT_2000_ca6e * 0x34 + 0x28) < *(uint *)(uVar2 * 0x34 + 0x28))))))) &&
       ((*(uint *)(uVar2 * 0x34 + 0x26) < uVar3 ||
        ((*(uint *)(uVar2 * 0x34 + 0x26) == uVar3 && (*(uint *)(uVar2 * 0x34 + 0x28) < uVar4)))))) {
      bStack_3 = (byte)uVar2;
      uVar3 = *(uint *)(uVar2 * 0x34 + 0x26);
      uVar4 = *(uint *)(uVar2 * 0x34 + 0x28);
    }
  }
  if (bStack_3 == 0xff) {
    pcVar1 = (char *)0x0;
  }
  else {
    DAT_2000_ca6e = bStack_3;
    pcVar1 = (char *)"arena" + 5;
  }
  return pcVar1;
}



/* 4207:2c18 */

char * __cdecl16far OVC15_4207_2c18(void)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bStack_3;
  
  bStack_3 = 0xff;
  uVar3 = 0;
  uVar4 = 0;
  for (uVar2 = 0; (int)uVar2 < (int)(uint)AgntCount; uVar2 = uVar2 + 1) {
    if (((DAT_2000_ca6e != uVar2) &&
        ((*(uint *)(uVar2 * 0x34 + 0x26) < *(uint *)((uint)DAT_2000_ca6e * 0x34 + 0x26) ||
         ((*(int *)((uint)DAT_2000_ca6e * 0x34 + 0x26) == *(int *)(uVar2 * 0x34 + 0x26) &&
          (*(uint *)(uVar2 * 0x34 + 0x28) < *(uint *)((uint)DAT_2000_ca6e * 0x34 + 0x28))))))) &&
       ((uVar3 < *(uint *)(uVar2 * 0x34 + 0x26) ||
        ((*(uint *)(uVar2 * 0x34 + 0x26) == uVar3 && (uVar4 < *(uint *)(uVar2 * 0x34 + 0x28))))))) {
      bStack_3 = (byte)uVar2;
      uVar3 = *(uint *)(uVar2 * 0x34 + 0x26);
      uVar4 = *(uint *)(uVar2 * 0x34 + 0x28);
    }
  }
  if (bStack_3 == 0xff) {
    pcVar1 = (char *)0x0;
  }
  else {
    DAT_2000_ca6e = bStack_3;
    pcVar1 = (char *)"arena" + 5;
  }
  return pcVar1;
}



/* 4207:2d75 */

uint __cdecl16far OVC15_4207_2d75(void)

{
  char cVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  uint uVar4;
  uint16_t uVar5;
  byte bStack_9;
  byte bStack_8;
  byte bStack_7;
  uint uStack_6;
  uint uStack_4;
  
  uStack_4 = 0;
  bStack_8 = 0xff;
  uStack_6 = 0;
  bStack_9 = 0xff;
  for (bStack_7 = 0; bStack_7 < DAT_2000_d1e6; bStack_7 = bStack_7 + 1) {
    if ((*(char *)((int)*(undefined4 *)((uint)bStack_7 << 2) + 0x3f) == '\0') &&
       (uStack_4 < *(uint *)((int)*(undefined4 *)((uint)bStack_7 << 2) + 0x45))) {
      bStack_8 = bStack_7;
      uStack_4 = *(uint *)((int)*(undefined4 *)((uint)bStack_7 << 2) + 0x45);
    }
    if ((*(char *)((int)*(undefined4 *)((uint)bStack_7 << 2) + 0x3f) != '\0') &&
       (uStack_6 < *(uint *)((int)*(undefined4 *)((uint)bStack_7 << 2) + 0x45))) {
      bStack_9 = bStack_7;
      uStack_6 = *(uint *)((int)*(undefined4 *)((uint)bStack_7 << 2) + 0x45);
    }
  }
  if ((bStack_9 != 0xff) && (0xe < uStack_6)) {
    uVar2 = ovr_randBelow(EntityCount);
    uVar4 = uVar2 & 0xff;
    do {
      uVar5 = Entities.seg;
      uVar3 = Entities.ofs;
      if ((*(byte *)(uVar3 + uVar4 * 0x37 + 0x1a) == bStack_9) &&
         (cVar1 = ovr_OVC23_55fe_05db(*(undefined2 *)(uVar3 + uVar4 * 0x37),
                                      *(undefined2 *)(uVar3 + uVar4 * 0x37 + 2)), cVar1 == '\0')) {
        return uVar4;
      }
      uVar4 = uVar4 + 1;
      if (EntityCount <= uVar4) {
        uVar4 = 0;
      }
    } while (uVar4 != (uVar2 & 0xff));
  }
  if ((bStack_8 != 0xff) && (0x1d < uStack_4)) {
    uVar2 = ovr_randBelow(EntityCount);
    uVar4 = uVar2 & 0xff;
    do {
      uVar5 = Entities.seg;
      uVar3 = Entities.ofs;
      if (((*(byte *)(uVar3 + uVar4 * 0x37 + 0x1a) == bStack_8) &&
          (cVar1 = ovr_OVC23_55fe_05db(*(undefined2 *)(uVar3 + uVar4 * 0x37),
                                       *(undefined2 *)(uVar3 + uVar4 * 0x37 + 2)), cVar1 == '\0'))
         && ((*(byte *)(Entities.ofs + uVar4 * 0x37 + 0x33) & 3) == 0)) {
        return uVar4;
      }
      uVar4 = uVar4 + 1;
      if (EntityCount <= uVar4) {
        uVar4 = 0;
      }
    } while (uVar4 != (uVar2 & 0xff));
  }
  uVar2 = ovr_randBelow(EntityCount);
  return uVar2 & 0xff;
}


