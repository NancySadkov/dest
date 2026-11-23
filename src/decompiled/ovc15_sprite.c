/*
 * ovc15_sprite.c - recovered from STRONG.EXE
 * memory block: OVC15_sprite.c
 * range: 4207:0000 - 4207:320f
 * functions: 29
 */
#include "recovered.h"


/* 4207:0000 */
spr_t * __cdecl16far stshRleAnims(uint8_t *src,anm_t *anms,uint16_t nanims)

{
  uint uVar1;
  uint16_t anim_height;
  uint16_t row;
  uint16_t panms;
  int *piVar2;
  uint16_t i;
  uint16_t unaff_DI;
  uint16_t count;
  far_t dst;
  frm_t *frm;
  far_t far *in_stack_00000004;
  uint16_t pdst;
  uint16_t sdst;
  uint32_t prev_next;
  frm_t *pfStack_20;
  uint16_t frm_seg;
  uint16_t xx;
  uint16_t exx;
  uint16_t sxx;
  uint16_t j;
  uint32_t p_ow;
  uint16_t ey;
  uint16_t ex;
  uint16_t sy;
  uint16_t sx;
  uint8_t index;
  
  if (0x4e < StshSprIndex) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x36);
  }
  dst.seg = (uint16_t)((spr_t *)StshSprites + StshSprIndex);
  StshSprIndex = StshSprIndex + 1;
  dst.ofs = (uint16_t)ovr_mkp((uint32_t *)dst.seg,(*(uint16_t *)((uint8_t *)&(StshSprites) + 2)),unaff_DI);
  _fsetmem((void *)CONCAT22(dst.seg,dst.ofs),0xb0,0);
  i = 0;
  while ((i < (*(uint16_t *)((uint8_t *)&(anms) + 2)) && (*(char *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0x1b) != '\0'))) {
    uVar1 = (uint)*(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e);
    prev_next = CONCAT22(dst.seg,dst.ofs + uVar1 * 4 + 0x58);
    piVar2 = (int *)(dst.ofs + uVar1 * 4);
    piVar2[1] = (int)(anm_t *)anms;
    *piVar2 = (*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e;
    sx = *(uint16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 1);
    sy = *(uint16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 3);
    ex = *(uint16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 5);
    ey = *(uint16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 7);
    anim_height = ey - sy;
    if ((int)anim_height < 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x33);
    }
    p_ow = 0;
    j = 0;
    while( true ) {
      (*(uint16_t *)((uint8_t *)&(frm) + 2)) = (uint16_t)((ulong)((long)(int)i * 0x1e) >> 0x10);
      if (*(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + (int)((long)(int)i * 0x1e) + 0x1b) <= j) break;
      (*(uint16_t *)((uint8_t *)&(frm))) =(uint16_t)( (frm_t *)ovr_stshRleSub(in_stack_00000004,(uint8_t *)src,sx,sy,ex,ey,21));
      pfStack_20 = (frm_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(frm) + 2)),(frm_t *)frm);
      ((frm_t *)frm)->type2 = 2;
      ((frm_t *)frm)->x = *(int16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0xb);
      ((frm_t *)frm)->y = *(int16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0xd);
      *(uint16_t *)((int)prev_next + 2) = (*(uint16_t *)((uint8_t *)&(frm) + 2));
      *(frm_t **)prev_next = (frm_t *)frm;
      prev_next = CONCAT22((*(uint16_t *)((uint8_t *)&(frm) + 2)),&((frm_t *)frm)->next);
      if ((*(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0x1c) & 1) == 0) {
        ((frm_t *)frm)->ow = *(uint8_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0xf);
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
            if (*(char *)((int)&in_stack_00000004[ey * 0x50 + 0x50].ofs + xx) == -2) {
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
          p_ow = CONCAT22((*(uint16_t *)((uint8_t *)&(frm) + 2)),&((frm_t *)frm)->ow);
        }
        else {
          for (xx = sx; *(char *)((int)&in_stack_00000004[ey * 0x50 + 0x50].ofs + xx) != -2;
              xx = xx + 1) {
            if (ex + row < xx) {
                    /* WARNING: Subroutine does not return */
              ovr_stExit(9);
            }
          }
          ((frm_t *)frm)->ow = (char)exx - (char)xx;
          exx = xx;
        }
      }
      pfStack_20->type4 = 4;
      *(uint16_t *)((int)&((frm_t *)frm)->next + 2) = 0;
      *(uint16_t *)&((frm_t *)frm)->next = 0;
      sy = sy + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 10);
      ey = ey + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 10);
      if (199 < ey) {
        sy = *(int *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 3) % (int)(uint)*(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 10);
        ey = sy + anim_height;
        sx = sx + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 9);
        ex = ex + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 9);
        sxx = sxx + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 9);
        exx = exx + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 9);
      }
      j = j + 1;
    }
    if ((int)p_ow != 0 || (*(uint16_t *)((uint8_t *)&(p_ow) + 2)) != 0) {
      *(char *)p_ow = (char)exx - (char)sxx;
    }
    i = i + 1;
  }
  return (spr_t *)dst.ofs;
}


/* 4207:03ac */
far_t * __cdecl16far
stshSprite(far_t *retStorage,int16_t file_id,anm_t *anms,uint16_t nanims,bool grab)

{
  far_t handle;
  uint16_t ofs;
  uint16_t seg;
  uint16_t unaff_SI;
  spr_t *spr;
  stg_tmp_t *fVar6;
  far_t pixels;
  far_t handle_00;
  
  if ((char)nanims == '\0') {
    (*(uint16_t *)((uint8_t *)&(spr))) = ovr_stshSpriteStub((anm_t *)file_id,(uint16_t)(anm_t *)anms);
  }
  else {
    (*(uint16_t *)((uint8_t *)&(fVar6))) = ovr_grabLbm((int16_t)retStorage,0,0,0,0);
    pixels.seg = (((stg_tmp_t *)fVar6)->aptr).seg;
    pixels.ofs = (&((stg_tmp_t *)fVar6)->aptr)->ofs;
    seg = (*(uint16_t *)((uint8_t *)&(fVar6) + 2));
    ovr_grabRemap(pixels,0xff,0x0,0);
    ofs = (uint16_t)
          stshRleAnims((uint8_t *)CONCAT22(file_id,(uint8_t *)(((stg_tmp_t *)fVar6)->aptr).seg),anms
                       ,unaff_SI);
    handle_00.seg = (((stg_tmp_t *)fVar6)->bptr).seg;
    handle_00.ofs = (&((stg_tmp_t *)fVar6)->bptr)->ofs;
    ovr_stshFree(handle_00);
    handle.seg = (*(uint16_t *)((uint8_t *)&(fVar6) + 2));
    handle.ofs = (uint16_t)(stg_tmp_t *)fVar6;
    ovr_stshFree(handle);
    stshStoreSprite((spr_t *)CONCAT22(file_id,seg),anms,unaff_SI);
    (*(uint16_t *)((uint8_t *)&(spr))) =(uint16_t)( (spr_t *)ofs);
  }
  return (far_t far *)(spr_t *)spr;
}


/* 4207:0462 */

void __cdecl16far allocSprSeqs(void)

{
  uint16_t in_DX;
  
  StshSprites = ovr_stshAlloc(0x3650);
  return;
}



/* 4207:047b */
void __cdecl16far stshInitSprites(bool grab)

{
  uint16_t in_AX;
  far_t far *pfVar1;
  int labelOfs;
  int iVar3;
  stg_tmp_t *gfx;
  cte_t *pcVar4;
  uint32_t *puVar5;
  uint16_t in_DX;
  uint16_t uVar6;
  uint8_t *puVar7;
  uint8_t *puVar8;
  uint16_t uVar9;
  uint16_t i;
  far_t far *unaff_DI;
  int iVar10;
  uint16_t j;
  far_t pixels;
  long sz;
  
  StshSprIndex = 0;
  pfVar1 = stshSprite((far_t *)((byte *)__C0_ASM_CopyRight + 0x21),0,(anm_t *)0x9195d,
                      CONCAT11((char)((uint)in_AX >> 8),grab),SUB21(unaff_DI,0));
  SprProjectiles.ofs = (uint16_t)pfVar1;
  SprProjectiles.seg = in_DX;
  for (i = 0; (int)i < 0x2a; i = i + 1) {
    uVar6 = 0x195d;
    pfVar1 = stshSprite((far_t *)*(uint16_t *)((int)AgntGs[0].sprfls + i * 0x95),
                        *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                        (anm_t *)(ulong)CONCAT12(*(undefined1 *)((int)&AgntGs[0].nanims + i * 0x95),
                                                 *(uint16_t *)
                                                  ((int)&AgntGs[0].anms + 2 + i * 0x95)),
                        CONCAT11((char)((uint)pfVar1 >> 8),grab),SUB21(unaff_DI,0));
    *(uint16_t *)((int)AgntGs[0].sprs + 2 + i * 0x95) = uVar6;
    *(uint16_t *)((int)AgntGs[0].sprs + i * 0x95) =(uint16_t)( pfVar1);
    if (*(int *)((int)AgntGs[0].sprfls + 2 + i * 0x95) == 0) {
      uVar6 = *(uint16_t *)((int)AgntGs[0].sprs + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].sprs + 6 + i * 0x95) =
           *(uint16_t *)((int)AgntGs[0].sprs + 2 + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].sprs + 4 + i * 0x95) = uVar6;
    }
    else {
      uVar6 = 0x195d;
      pfVar1 = stshSprite((far_t *)*(uint16_t *)((int)AgntGs[0].sprfls + 2 + i * 0x95),
                          *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                          (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                    ((int)&AgntGs[0].nanims + i * 0x95),
                                                   *(uint16_t *)
                                                    ((int)&AgntGs[0].anms + 2 + i * 0x95)),
                          CONCAT11((char)(i * 0x95 >> 8),grab),SUB21(unaff_DI,0));
      *(uint16_t *)((int)AgntGs[0].sprs + 6 + i * 0x95) = uVar6;
      *(uint16_t *)((int)AgntGs[0].sprs + 4 + i * 0x95) =(uint16_t)( pfVar1);
    }
    if (*(int *)((int)AgntGs[0].sprfls + 4 + i * 0x95) == 0) {
      uVar6 = *(uint16_t *)((int)AgntGs[0].sprs + 4 + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].sprs + 10 + i * 0x95) =
           *(uint16_t *)((int)AgntGs[0].sprs + 6 + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].sprs + 8 + i * 0x95) = uVar6;
    }
    else {
      uVar6 = 0x195d;
      pfVar1 = stshSprite((far_t *)*(uint16_t *)((int)AgntGs[0].sprfls + 4 + i * 0x95),
                          *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                          (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                    ((int)&AgntGs[0].nanims + i * 0x95),
                                                   *(uint16_t *)
                                                    ((int)&AgntGs[0].anms + 2 + i * 0x95)),
                          CONCAT11((char)(i * 0x95 >> 8),grab),SUB21(unaff_DI,0));
      *(uint16_t *)((int)AgntGs[0].sprs + 10 + i * 0x95) = uVar6;
      *(uint16_t *)((int)AgntGs[0].sprs + 8 + i * 0x95) =(uint16_t)( pfVar1);
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      labelOfs = i * 0x95 + iVar10 * 2;
      if (*(int *)((int)AgntGs[0].sprfls + 6 + labelOfs) == 0) {
        labelOfs = i * 0x95 + iVar10 * 4;
        uVar6 = *(uint16_t *)((int)AgntGs[0].sprs + labelOfs);
        iVar3 = i * 0x95 + iVar10 * 4;
        *(uint16_t *)((int)AgntGs[0].sprs + 0xe + iVar3) =
             *(uint16_t *)((int)AgntGs[0].sprs + 2 + labelOfs);
        *(uint16_t *)((int)AgntGs[0].sprs + 0xc + iVar3) = uVar6;
      }
      else {
        uVar6 = 0x195d;
        pfVar1 = stshSprite((far_t *)*(uint16_t *)
                                      ((int)AgntGs[0].sprfls + 6 + i * 0x95 + iVar10 * 2),
                            *(int16_t *)((int)&AgntGs[0].anms + i * 0x95),
                            (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                      ((int)&AgntGs[0].nanims + i * 0x95),
                                                     *(uint16_t *)
                                                      ((int)&AgntGs[0].anms + 2 + i * 0x95)),
                            CONCAT11((char)((uint)labelOfs >> 8),grab),SUB21(unaff_DI,0));
        labelOfs = i * 0x95 + iVar10 * 4;
        *(uint16_t *)((int)AgntGs[0].sprs + 0xe + labelOfs) = uVar6;
        *(uint16_t *)((int)AgntGs[0].sprs + 0xc + labelOfs) =(uint16_t)( pfVar1);
      }
    }
    for (j = 0; (int)j < 6; j = j + 1) {
      uVar6 = 0x195d;
      if (*(int *)((int)AgntGs[0].prtfls + i * 0x95 + j * 2) != 0) {
        if (grab) {
          puVar7 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
          gfx = ovr_grabLbm(*(int16_t *)((int)AgntGs[0].prtfls + i * 0x95 + j * 2),0,0,0,0);
          puVar8 = puVar7;
          ovr_stshUniqueColorsRemap(gfx,puVar7);
          pixels.seg = 0;
          pixels.ofs = (gfx->aptr).seg;
          pfVar1 = ovr_stshRleType2((far_t far *)(&gfx->aptr)->ofs,pixels,0,114,103,0,0,(int16_t)unaff_DI,0,0);
          pcVar4 = (char *)stsh_store((uint8_t *)pfVar1, (uint16_t)puVar8, &uVar6);
          iVar10 = i * 0x95 + j * 4;

          *(int *)((int)AgntGs[0].prts + 2 + iVar10) = (int)puVar8;
          *(uint16_t *)((int)AgntGs[0].prts + iVar10) =(uint16_t)( pcVar4);
          sz = ZEXT24(unaff_DI) << 0x10;
          puVar5 = ovr_stshWrite((uint32_t *)gfx,(uint8_t *)CONCAT22(0x300,puVar7),sz,0);
          unaff_DI = (far_t far *)((ulong)sz >> 0x10);
          iVar10 = i * 0x95 + j * 4;
          *(uint16_t *)((int)AgntGs[0].prtpals + 2 + iVar10) = uVar6;
          *(uint16_t *)((int)AgntGs[0].prtpals + iVar10) =(uint16_t)( puVar5);
          ovr_stgFreeTmp(gfx,puVar7);
        }
        else {
          pfVar1 = ovr_stshAllocStub(unaff_DI);
          iVar10 = i * 0x95 + j * 4;
          uVar9 = 0x195d;
          *(uint16_t *)((int)AgntGs[0].prts + 2 + iVar10) = uVar6;
          *(uint16_t *)((int)AgntGs[0].prts + iVar10) =(uint16_t)( pfVar1);
          pfVar1 = ovr_stshAllocStub(unaff_DI);
          iVar10 = i * 0x95 + j * 4;
          *(uint16_t *)((int)AgntGs[0].prtpals + 2 + iVar10) = uVar9;
          *(uint16_t *)((int)AgntGs[0].prtpals + iVar10) =(uint16_t)( pfVar1);
        }
      }
    }
    pfVar1 = (far_t far *)(*(uint *)((int)AgntGs[0].prts + 4 + i * 0x95) |
                      *(uint *)((int)AgntGs[0].prts + 6 + i * 0x95));
    if ((pfVar1 == (far_t far *)0x0) &&
       (pfVar1 = (far_t far *)0x0,
       *(int *)((int)AgntGs[0].prts + i * 0x95) != 0 ||
       *(int *)((int)AgntGs[0].prts + 2 + i * 0x95) != 0)) {
      uVar6 = *(uint16_t *)((int)AgntGs[0].prts + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].prts + 6 + i * 0x95) =
           *(uint16_t *)((int)AgntGs[0].prts + 2 + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].prts + 4 + i * 0x95) = uVar6;
      pfVar1 = (far_t far *)*(uint16_t *)((int)AgntGs[0].prtpals + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].prtpals + 6 + i * 0x95) =
           *(uint16_t *)((int)AgntGs[0].prtpals + 2 + i * 0x95);
      *(uint16_t *)((int)AgntGs[0].prtpals + 4 + i * 0x95) =(uint16_t)( pfVar1);
    }
    for (iVar10 = 2; iVar10 < 6; iVar10 = iVar10 + 2) {
      labelOfs = i * 0x95 + iVar10 * 4;
      if ((*(int *)((int)AgntGs[0].prts + 4 + labelOfs) == 0 &&
           *(int *)((int)AgntGs[0].prts + 6 + labelOfs) == 0) &&
         (labelOfs = i * 0x95 + iVar10 * 4,
         *(int *)((int)AgntGs[0].prtfls + 8 + labelOfs) != 0 ||
         *(int *)((int)AgntGs[0].prtfls + 10 + labelOfs) != 0)) {
        labelOfs = i * 0x95 + iVar10 * 4;
        uVar6 = *(uint16_t *)((int)AgntGs[0].prtfls + 8 + labelOfs);
        iVar3 = i * 0x95 + iVar10 * 4;
        *(uint16_t *)((int)AgntGs[0].prts + 6 + iVar3) =
             *(uint16_t *)((int)AgntGs[0].prtfls + 10 + labelOfs);
        *(uint16_t *)((int)AgntGs[0].prts + 4 + iVar3) = uVar6;
        labelOfs = i * 0x95 + iVar10 * 4;
        uVar6 = *(uint16_t *)((int)AgntGs[0].prts + 0x14 + labelOfs);
        iVar3 = i * 0x95 + iVar10 * 4;
        *(uint16_t *)((int)AgntGs[0].prtpals + 6 + iVar3) =
             *(uint16_t *)((int)AgntGs[0].prts + 0x16 + labelOfs);
        *(uint16_t *)((int)AgntGs[0].prtpals + 4 + iVar3) = uVar6;
      }
      labelOfs = i * 0x95 + iVar10 * 4;
      pfVar1 = (far_t far *)(*(uint *)((int)AgntGs[0].prts + labelOfs) |
                        *(uint *)((int)AgntGs[0].prts + 2 + labelOfs));
      if (pfVar1 == (far_t far *)0x0) {
        labelOfs = i * 0x95 + iVar10 * 4;
        if (*(int *)((int)AgntGs[0].prtfls + 4 + labelOfs) == 0 &&
            *(int *)((int)AgntGs[0].prtfls + 6 + labelOfs) == 0) {
          pfVar1 = (far_t far *)0x0;
        }
        else {
          labelOfs = i * 0x95 + iVar10 * 4;
          uVar6 = *(uint16_t *)((int)AgntGs[0].prtfls + 4 + labelOfs);
          iVar3 = i * 0x95 + iVar10 * 4;
          *(uint16_t *)((int)AgntGs[0].prts + 2 + iVar3) =
               *(uint16_t *)((int)AgntGs[0].prtfls + 6 + labelOfs);
          *(uint16_t *)((int)AgntGs[0].prts + iVar3) = uVar6;
          labelOfs = i * 0x95 + iVar10 * 4;
          pfVar1 = (far_t far *)*(uint16_t *)((int)AgntGs[0].prts + 0x10 + labelOfs);
          iVar3 = i * 0x95 + iVar10 * 4;
          *(uint16_t *)((int)AgntGs[0].prtpals + 2 + iVar3) =
               *(uint16_t *)((int)AgntGs[0].prts + 0x12 + labelOfs);
          *(uint16_t *)((int)AgntGs[0].prtpals + iVar3) =(uint16_t)( pfVar1);
        }
      }
    }
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

/* Fills all ten rows of one column of the agent grid at Agnts+0x8fa with 0xff. */

void __cdecl16far ovc15_fillGridColumn(uint vramOfs)

{
  uint uVar1;
  
  if (vramOfs >> 1 < 0x69) {
    for (uVar1 = 0; uVar1 < 10; uVar1 = uVar1 + 1) {
      AgntArrayA[uVar1][(vramOfs >> 1)] = 0xff;
    }
  }
  return;
}



/* 4207:0b88 */

/* Clears the visited byte (agnt_t+0x2d) on every agent. */

void __cdecl16far ovc15_clearVisited(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    Agnts[iVar1].visited = 0;
  }
  return;
}



/* 4207:0bb7 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches agntIndex, EntityCount */

void __cdecl16far ovc15_usesAgntIndex(void)

{
  uint agntIndex;
  int entitiesOfs;
  int bottomIdx;
  int topIdx;
  uint16_t entitiesSeg;
  uint8_t agentIndices;
  uint linesBottom;
  uint linesTop;
  int count;
  uint i;
  
  ovc15_clearVisited();
  count = 0;
  for (i = 0; i < EntityCount; i = i + 1) {
    entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
    bottomIdx = (int)Entities;
    if (((GfxRndSeed - 2U <= *(uint *)((entity_t *)bottomIdx + i)) &&
        (*(uint *)((entity_t *)bottomIdx + i) <= GfxRndSeed + 1U)) &&
       (((entity_t *)bottomIdx)[i].base.y == GfxRndSeed2)) {
      *(uint *)(&agentIndices + count * 2) = i;
      count = count + 1;
    }
  }
  topIdx = 0;
  bottomIdx = 0;
  while ((bottomIdx < count || (topIdx < count))) {
    while( true ) {
      entitiesOfs = (int)Entities;
      entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
      if ((count <= topIdx) ||
         (*(char *)((int)(char **)GMenuStrings +
                   (uint)*(byte *)(entitiesOfs + *(int *)(&agentIndices + topIdx * 2) * 0x37 + 0xd) * 0x95
                   + 0x1f) == '\x01')) break;
      topIdx = topIdx + 1;
    }
    while ((bottomIdx < count &&
           (*(char *)((int)(char **)GMenuStrings +
                     (uint)*(byte *)(entitiesOfs + *(int *)(&agentIndices + bottomIdx * 2) * 0x37 + 0xd) *
                     0x95 + 0x1f) != '\0'))) {
      bottomIdx = bottomIdx + 1;
    }
    if (topIdx < count) {
      linesTop = (*(byte *)(entitiesOfs + *(int *)(&agentIndices + topIdx * 2) * 0x37 + 0xe) + 0xf) / 0x10;
    }
    else {
      linesTop = 0;
    }
    if (bottomIdx < count) {
      linesBottom = (*(byte *)(entitiesOfs + *(int *)(&agentIndices + bottomIdx * 2) * 0x37 + 0xe) + 0xf) / 0x10;
    }
    else {
      linesBottom = 0;
    }
    while ((linesTop != 0 || (linesBottom != 0))) {
      if (linesTop != 0) {
        ovc15_textArena(*(int *)(&agentIndices + topIdx * 2),0,(uint)(AgntFlag1 == false));
        linesTop = linesTop - 1;
      }
      if (linesBottom != 0) {
        ovc15_textArena(*(int *)(&agentIndices + bottomIdx * 2),0,(uint)(AgntFlag1 == false));
        linesBottom = linesBottom - 1;
      }
    }
    if (topIdx < count) {
      topIdx = topIdx + 1;
    }
    if (bottomIdx < count) {
      bottomIdx = bottomIdx + 1;
    }
  }
  for (i = 0; agntIndex = i, (int)i < (int)(uint)AgntCount;
      i = i + 1) {
    if (Agnts[i].visited == '\0') {
      i = i - 1;
      ovr_ovc41_removeAgent(agntIndex,0,0);
    }
  }
  AgntFlag1 = true;
  return;
}



/* 4207:0e17 */
void __cdecl16far ovc15_removeEntity(uint entityIndex)

{
  int *piVar1;
  char cVar2;
  char partyIndex;
  uint16_t x;
  uint16_t y;
  entity_t *peVar3;
  uint uVar4;
  uint16_t uVar5;
  
  if (AgntFlag1) {
    for (uVar4 = 0; uVar4 < AgntCount; uVar4 = uVar4 + 1) {
      if ((Agnts[uVar4].owner == entityIndex) &&
         (Agnts[uVar4].combatState != '\x02')) {
        Agnts[uVar4].combatState = 2;
        Agnts[uVar4].targetY = 0;
      }
    }
  }
  uVar5 = (uint16_t)((ulong)Entities >> 0x10);
  peVar3 = (entity_t *)Entities;
  x = peVar3[entityIndex].base.destX;
  y = peVar3[entityIndex].base.destY;
  cVar2 = *(char *)((int)(char **)GMenuStrings + (uint)peVar3[entityIndex].base.gindex * 0x95 + 0x1f
                   );
  partyIndex = *(char *)((int)&peVar3[entityIndex].base.entity + 3);
  if (entityIndex < EntityCount - 1U) {
    _fmemmove((char *)CONCAT22(uVar5,peVar3 + entityIndex),
              (char *)CONCAT22(uVar5,peVar3 + entityIndex + 1),
              ((EntityCount + -1) - entityIndex) * 0x37);
  }
  if (AgntFlag1 != false) {
    for (uVar4 = 0; uVar4 < AgntCount; uVar4 = uVar4 + 1) {
      if (entityIndex < Agnts[uVar4].owner) {
        piVar1 = (int *)(uVar4 * 0x34 + 0x1b);
        *piVar1 = *piVar1 + -1;
        peVar3 = Entities + Agnts[uVar4].owner;
        AGNT_WORD(&Agnts[uVar4], entity, 2) = DAT_2000_d190;
        AGNT_WORD(&Agnts[uVar4], entity, 0) =(uint16_t)( peVar3);
      }
    }
  }
  EntityCount = EntityCount + -1;
  if ((cVar2 == '\0') && ((x != 0 || (y != 0)))) {
    ovr_attact_usesAlignUp4(x,y,partyIndex,0,partyIndex);
  }
  ovr_attact_usesGMapFlags3();
  return;
}


/* 4207:0ff0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

uint __cdecl16far ovc15_usesAlignUp4(uint16_t x,uint16_t y)

{
  uint32_t uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint16_t uVar6;
  
  uVar2 = ovr_alignUp4(x,0,0);
  uVar5 = 0;
  uVar3 = uVar2;
  do {
    if (EntityCount <= uVar5) {
      return uVar3 & 0xff00;
    }
    uVar3 = uVar5 * 0x37;
    uVar6 = (uint16_t)((ulong)Entities >> 0x10);
    iVar4 = (int)Entities;
    if ((((*(byte *)(iVar4 + uVar3 + 0x33) & 2) != 0) &&
        (uVar3 = ((entity_t *)iVar4)[uVar5].base.targetY, uVar3 == y)) &&
       (uVar3 = ovr_alignUp4(((entity_t *)iVar4)[uVar5].base.targetX,0,0), uVar3 == uVar2)) {
      uVar3 = uVar5 * 0x37;
      uVar6 = (uint16_t)((ulong)Entities >> 0x10);
      if ((*(char *)((int)Entities + uVar3 + 0x1a) != -1) &&
         (uVar1 = *(uint32_t *)((uint)AGNT_FIELD(&((entity_t *)Entities)[uVar5], base.entity, 3) << 2),
         uVar3 = (uint)*(byte *)((int)uVar1 + 0x3f), uVar3 == 0)) {
        return 1;
      }
    }
    uVar5 = uVar5 + 1;
  } while( true );
}



/* 4207:10a3 */
entity_t * __cdecl16far
ovc15_usesLDIV_at_(uint16_t x,uint16_t y,uint16_t destX,uint16_t destY,byte gindex,uint8_t animFrame,byte partyIndex,uint16_t arg8,uint16_t arg9,uint16_t arg10,uint16_t arg11)

{
  uint8_t *puVar1;
  uint *puVar2;
  uint16_t uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  entity_t *peVar7;
  uint16_t uVar8;
  long lVar9;
  int iStack_6;
  
  if (EntityCount < 0x259) {
    mapDirty = 1;
    if (PlayerIndex < 2) {
      if (0x21b < EntityCount) {
        uVar5 = ovc15_usesRandBelow2();
        ovc15_removeEntity(uVar5);
        EntityCount = EntityCount - 1;
      }
    }
    else if (599 < EntityCount) {
      uVar5 = ovc15_usesRandBelow2();
      ovc15_removeEntity(uVar5);
      EntityCount = EntityCount - 1;
    }
    _fsetmem((entity_t *)CONCAT22((int)((ulong)Entities >> 0x10),Entities + EntityCount),0x37,0);
    ((entity_t *)Entities)[EntityCount].base.targetX = destX;
    ((entity_t *)Entities)[EntityCount].base.targetY = destY;
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    if ((destX == x) && (destY == y)) {
      ((entity_t *)Entities)[EntityCount].base.destX = 0;
      ((entity_t *)Entities)[EntityCount].base.destY = 0;
    }
    else {
      ((entity_t *)Entities)[EntityCount].base.destX = destX;
      ((entity_t *)Entities)[EntityCount].base.destY = destY;
    }
    (((entity_t *)Entities + EntityCount)->base).x = x;
    ((entity_t *)Entities)[EntityCount].base.y = y;
    ((entity_t *)Entities)[EntityCount].base.target = 0xff;
    ((entity_t *)Entities)[EntityCount].base.gindex = gindex;
    uVar5 = EntityCount;
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    peVar7 = (entity_t *)Entities;
    puVar1 = &peVar7[EntityCount].base.frameIndex;
    puVar1[0] = 0x0;
    puVar1[1] = 0x0;
    puVar1 = &peVar7[uVar5].base.health;
    puVar1[0] = 0x64;
    puVar1[1] = 0x0;
    *(uint16_t *)((int)&((entity_t *)Entities)[EntityCount].base.frames + 1) = 0;
    ((entity_t *)Entities)[EntityCount].base.animFrame = animFrame;
    *(byte *)((int)&((entity_t *)Entities)[EntityCount].base.entity + 3) = partyIndex;
    *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
         *(undefined1 *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
    *(undefined1 *)&((entity_t *)Entities)[EntityCount].base.flags32 =
         *(undefined1 *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
    if (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x2f) != -1) {
      uVar5 = (uint)*(byte *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
      uVar8 = ovr_agnt_abilityModifier(partyIndex,4);
      iStack_6 = uVar5 + (int)(char)uVar8;
      if (iStack_6 < 1) {
        iStack_6 = 1;
      }
      *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
           (undefined1)iStack_6;
      *(undefined1 *)&((entity_t *)Entities)[EntityCount].base.flags32 = (undefined1)iStack_6;
    }
    if (*(char *)((int)(char **)GMenuStrings + (uint)gindex * 0x95 + 0x1f) == '\0') {
      uVar5 = ovc15_usesAlignUp4(destX,destY);
      if ((uVar5 & 0xff) == 0) {
        *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.flags32 + 1) = 2;
      }
    }
    else if ((destX == x) && (destY == y)) {
      *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.flags32 + 1) = 2;
    }
    if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)gindex * 0x95) & 0x1000) == 0) {
      if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)gindex * 0x95) & 0x2000) == 0) {
        lVar9 = 0x8000;
        uVar5 = rand();
        lVar9 = LDIV_at_(CONCAT22(((int)uVar5 >> 0xf) << 1 | (uint)((int)uVar5 < 0),uVar5 << 1),
                         lVar9);
        if ((int)lVar9 == 0) {
          puVar2 = (uint *)((int)&((entity_t *)Entities)[EntityCount].base.frames + 3);
          *puVar2 = *puVar2 | 1;
        }
      }
      else {
        puVar2 = (uint *)((int)&((entity_t *)Entities)[EntityCount].base.frames + 3);
        *puVar2 = *puVar2 | 1;
      }
    }
    ((entity_t *)Entities)[EntityCount].base.level =
         *(uint8_t *)((int)&worldMenuLabels[8].seg + (uint)gindex * 0x95);
    if ((((((char_sheet_t *)(((uint)partyIndex << 2)))->flags5d & 0x10) != 0) &&
        (*(byte *)((int)&worldMenuLabels[8].seg + (uint)gindex * 0x95) < 5)) &&
       (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)gindex * 0x95) != -1)) {
      while (((entity_t *)Entities)[EntityCount].base.level < 5) {
        cVar4 =(uint16_t)( ovr_ovc15_textView()   /* hand fix: args lost by the decompiler */);
        uVar8 = (uint16_t)((ulong)Entities >> 0x10);
        *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
             *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) + cVar4;
        uVar8 = (uint16_t)((ulong)Entities >> 0x10);
        *(char *)&((entity_t *)Entities)[EntityCount].base.flags32 =
             (char)((entity_t *)Entities)[EntityCount].base.flags32 + cVar4;
        puVar1 = &((entity_t *)Entities)[EntityCount].base.level;
        *puVar1 = *puVar1 + 0x1;
      }
    }
    uVar5 = EntityCount;
    peVar7 = (entity_t *)Entities;
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)gindex * 0x95) == -1) {
      iVar6 = (uint)peVar7[EntityCount].base.level * 4;
      uVar3 = *(uint16_t *)(iVar6 + -4);
      *(uint16_t *)&peVar7[EntityCount].base.frameIndex = *(uint16_t *)(iVar6 + -2);
      *(uint16_t *)&peVar7[uVar5].base.health = uVar3;
    }
    else {
      iVar6 = (uint)*(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)gindex * 0x95) * 0x94 +
              (uint)peVar7[EntityCount].base.level * 4;
      uVar3 = *(uint16_t *)(iVar6 + -4);
      *(uint16_t *)&peVar7[EntityCount].base.frameIndex = *(uint16_t *)(iVar6 + -2);
      *(uint16_t *)&peVar7[uVar5].base.health = uVar3;
    }
    uVar5 = EntityCount;
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    peVar7 = (entity_t *)Entities;
    if (*(int *)&peVar7[EntityCount].base.health == 0 &&
        *(int *)&peVar7[EntityCount].base.frameIndex == 0) {
      puVar1 = &peVar7[EntityCount].base.frameIndex;
      puVar1[0] = 0x0;
      puVar1[1] = 0x0;
      puVar1 = &peVar7[uVar5].base.health;
      puVar1[0] = 0x64;
      puVar1[1] = 0x0;
    }
    uVar5 = EntityCount;
    EntityCount = EntityCount + 1;
    ovr_attact_usesGMapFlags3();
    if (AgntFlag1 != false) {
      uVar8 = (uint16_t)((ulong)Entities >> 0x10);
      peVar7 = (entity_t *)Entities;
      if (((GfxRndSeed - 2U <= ((peVar7 + uVar5)->base).x) &&
          (((peVar7 + uVar5)->base).x <= GfxRndSeed + 1U)) && (peVar7[uVar5].base.y == GfxRndSeed2))
      {
        ovc15_textArena(uVar5,0,0);
      }
    }
    peVar7 = Entities + uVar5;
    return peVar7;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x26);
}


/* 4207:16a5 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls LDIV_at_ */

void __cdecl16far ovc15_usesLDIV_at_2(int entityIndex,byte gindex,char partySlot)

{
  uint8_t *puVar1;
  uint *puVar2;
  byte bVar3;
  uint32_t uVar4;
  uint16_t uVar5;
  entity_t *peVar6;
  uint uVar7;
  uint16_t uVar8;
  entity_t *peVar9;
  int iVar10;
  int agnt;
  uint16_t uVar12;
  uint16_t uVar13;
  bool bVar14;
  long lVar15;
  
  if (partySlot != -1) {
    mapDirty = 1;
    peVar6 = Entities;
    uVar5 = (uint16_t)((ulong)Entities >> 0x10);
    Entities[entityIndex].base.target = 0xff;
    peVar6[entityIndex].base.gindex = gindex;
    peVar6[entityIndex].base.level =
         *(uint8_t *)((int)&worldMenuLabels[8].seg + (uint)gindex * 0x95);
    puVar1 = &peVar6[entityIndex].base.frameIndex;
    puVar1[0] = 0x0;
    puVar1[1] = 0x0;
    puVar1 = &peVar6[entityIndex].base.health;
    puVar1[0] = 0x64;
    puVar1[1] = 0x0;
    *(uint16_t *)((int)&peVar6[entityIndex].base.frames + 1) = 0;
    *(uint16_t *)((int)&peVar6[entityIndex].base.frames + 3) = 0;
    *(char *)((int)&peVar6[entityIndex].base.entity + 3) = partySlot;
    *(undefined1 *)((int)&peVar6[entityIndex].base.state + 1) =
         *(undefined1 *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
    *(undefined1 *)&peVar6[entityIndex].base.flags32 =
         *(undefined1 *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
    lVar15 = 0x8000;
    uVar7 = rand();
    lVar15 = LDIV_at_(CONCAT22(((int)uVar7 >> 0xf) << 1 | (uint)((int)uVar7 < 0),uVar7 << 1),lVar15)
    ;
    if ((int)lVar15 == 0) {
      puVar2 = (uint *)((int)&peVar6[entityIndex].base.frames + 3);
      *puVar2 = *puVar2 | 1;
    }
    ovr_attact_usesGMapFlags3();
    if (AgntFlag1 != false) {
      uVar12 = (uint16_t)((ulong)Entities >> 0x10);
      peVar9 = (entity_t *)Entities;
      if (((GfxRndSeed - 2U <= ((peVar9 + entityIndex)->base).x) &&
          (((peVar9 + entityIndex)->base).x <= GfxRndSeed + 1U)) &&
         (peVar9[entityIndex].base.y == GfxRndSeed2)) {
        for (agnt = 0; agnt < (int)(uint)AgntCount; agnt = agnt + 1) {
          if (Agnts[agnt].owner == entityIndex) {
            Agnts[agnt].target = 0xff;
            bVar3 = peVar6[entityIndex].base.gindex;
            AGNT_WORD(&Agnts[agnt], gdata, 2) = 0x195d;
            AGNT_WORD(&Agnts[agnt], gdata, 0) = (uint)bVar3 * 0x95 + 0x26d6;
            Agnts[agnt].strength =
                 *(undefined1 *)((int)&peVar6[entityIndex].base.state + 1);
            Agnts[agnt].strengthMax = (char)peVar6[entityIndex].base.flags32;
            bVar14 = (*(uint *)((int)&peVar6[entityIndex].base.frames + 3) & 1) != 0;
            if (peVar6[entityIndex].base.level < 10) {
              if (peVar6[entityIndex].base.level < 4) {
                uVar4 = *(uint32_t far *)&Agnts[agnt].gdata;
                uVar13 = (uint16_t)((ulong)uVar4 >> 0x10);
                iVar10 = (int)uVar4 + (uint)bVar14 * 0xc;
                uVar12 = *(uint16_t *)(iVar10 + 3);
                AGNT_WORD(&Agnts[agnt], frames, 2) = *(uint16_t *)(iVar10 + 5);
                AGNT_WORD(&Agnts[agnt], frames, 0) = uVar12;
              }
              else {
                uVar4 = *(uint32_t far *)&Agnts[agnt].gdata;
                uVar13 = (uint16_t)((ulong)uVar4 >> 0x10);
                iVar10 = (int)uVar4 + (uint)bVar14 * 0xc;
                uVar12 = *(uint16_t *)(iVar10 + 7);
                AGNT_WORD(&Agnts[agnt], frames, 2) = *(uint16_t *)(iVar10 + 9);
                AGNT_WORD(&Agnts[agnt], frames, 0) = uVar12;
              }
            }
            else {
              uVar4 = *(uint32_t far *)&Agnts[agnt].gdata;
              uVar13 = (uint16_t)((ulong)uVar4 >> 0x10);
              iVar10 = (int)uVar4 + (uint)bVar14 * 0xc;
              uVar12 = *(uint16_t *)(iVar10 + 0xb);
              AGNT_WORD(&Agnts[agnt], frames, 2) = *(uint16_t *)(iVar10 + 0xd);
              AGNT_WORD(&Agnts[agnt], frames, 0) = uVar12;
            }
            Agnts[agnt].animFrame = 0xff;
            Agnts[agnt].faction =
                 *(undefined1 *)*(uint32_t far *)&Agnts[agnt].gdata;
            uVar4 = *(uint32_t far *)&Agnts[agnt].frames;
            uVar12 = (uint16_t)((ulong)uVar4 >> 0x10);
            iVar10 = (int)uVar4;
            if ((*(int *)(iVar10 + 0x68) == 0 && *(int *)(iVar10 + 0x6a) == 0) ||
               (uVar4 = *(uint32_t far *)&Agnts[agnt].frames,
               uVar12 = (uint16_t)((ulong)uVar4 >> 0x10), iVar10 = (int)uVar4,
               *(int *)(iVar10 + 0x58) == 0 && *(int *)(iVar10 + 0x5a) == 0)) {
              uVar4 = *(uint32_t far *)&Agnts[agnt].frames;
              uVar12 = (uint16_t)((ulong)uVar4 >> 0x10);
              iVar10 = (int)uVar4;
              if (*(int *)(iVar10 + 0x68) == 0 && *(int *)(iVar10 + 0x6a) == 0) {
                Agnts[agnt].animVariant = 0;
              }
              else {
                Agnts[agnt].animVariant = 1;
              }
            }
            else {
              uVar8 = ovr_randBelow(2,0);
              Agnts[agnt].animVariant = (char)uVar8;
            }
            uVar8 = ovr_audio_panFromX((agnt_t *)(agnt * 0x34),0);
            ovr_play_sfxU(0x1b,0,uVar8,0,0);
          }
        }
      }
    }
  }
  return;
}



/* 4207:1aae */
void __cdecl16far ovc15_usesStExit(int entityIndex)

{
  uint8_t *puVar1;
  uint uVar2;
  entity_t *peVar3;
  int iVar4;
  uint uVar5;
  uint16_t uVar6;
  char cStack_5;
  
  if (EntityCount < 0x259) {
    if (EntityCount != 600) {
      memcpy((char *)CONCAT22(DAT_2000_d190,Entities + EntityCount),
             (char *)CONCAT22(DAT_2000_d190,Entities + entityIndex),0x37);
      uVar6 = (uint16_t)((ulong)Entities >> 0x10);
      ((entity_t *)Entities)[EntityCount].base.animFrame =
           (uint8_t)((int)(uint)((entity_t *)Entities)[entityIndex].base.animFrame >> 1);
      uVar6 = (uint16_t)((ulong)Entities >> 0x10);
      puVar1 = &((entity_t *)Entities)[entityIndex].base.animFrame;
      *puVar1 = *puVar1 - ((entity_t *)Entities)[EntityCount].base.animFrame;
      uVar2 = EntityCount;
      uVar5 = (uint)((entity_t *)Entities)[EntityCount].base.animFrame;
      EntityCount = EntityCount + 1;
      ovr_attact_usesGMapFlags3();
      if (AgntFlag1 != false) {
        cStack_5 = '\0';
        iVar4 = 0;
        while ((iVar4 < (int)(uint)AgntCount && (uVar5 != 0))) {
          if (Agnts[iVar4].owner == entityIndex) {
            if (cStack_5 == '\0') {
              Agnts[iVar4].owner = uVar2;
              peVar3 = Entities + uVar2;
              AGNT_WORD(&Agnts[iVar4], entity, 2) = DAT_2000_d190;
              AGNT_WORD(&Agnts[iVar4], entity, 0) =(uint16_t)( peVar3);
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
/* [R4] calls ovr_stshRealloc */

uint8_t * __cdecl16far ovc15_usesStshRealloc(char *text,uint16_t arg2,uint16_t arg3,uint16_t arg4,uint16_t arg5,uint16_t arg6,uint16_t arg7,uint16_t arg8)

{
  byte bVar1;
  size_t sVar2;
  byte *pbVar3;
  uint16_t in_DX;
  uint16_t in_stack_00000006;
  
  sVar2 = strlen((char *)CONCAT22(in_stack_00000006,text));
  pbVar3 = ovr_stshRealloc((uint32_t)upperTextOfs,(ulong)(sVar2 + 1));
  upperTextOfs = (byte *)CONCAT22(in_DX,pbVar3);
  strcpy((char *)CONCAT22(in_DX,pbVar3),(char *)CONCAT22(in_stack_00000006,text));
  bVar1 = toupper((int)(char)*upperTextOfs);
  *upperTextOfs = bVar1;
  pbVar3 = upperTextOfs;
  return pbVar3;
}



/* 4207:1c79 */

/* Copies a string and capitalises its first character. */

char * __cdecl16far ovc15_capitalize(char *text)

{
  char cVar1;
  uint16_t in_stack_00000006;
  char *in_stack_00000008;
  uint16_t in_stack_0000000a;
  
  strcpy((char *)CONCAT22(in_stack_00000006,text),
         (char *)CONCAT22(in_stack_0000000a,in_stack_00000008));
  cVar1 = toupper((int)*text);
  *text = cVar1;
  return text;
}



/* 4207:1cae */
void __cdecl16far stshStoreSprite(spr_t *spr,anm_t *anms,int16_t nanims)

{
  uint16_t uVar1;
  uint16_t uVar2;
  bool bVar3;
  uint16_t index;
  uint16_t pofs;
  uint16_t o;
  int iVar4;
  uint16_t i;
  uint16_t pseg;
  uint32_t cte;
  int in_stack_00000004;
  far_t pframe;
  uint8_t frmid;
  uint8_t first_frame;
  uint16_t next_ofs;
  uint16_t next_seg;
  
  i = 0;
  while( true ) {
    if ((*(uint16_t *)((uint8_t *)&(anms) + 2)) <= (int)i) break;
    index = (uint16_t)*(byte *)((*(uint16_t *)((uint8_t *)&(spr) + 2)) + i * 0x1e);
    o = in_stack_00000004 + index * 4;
    if (*(int *)(o + 0x58) != 0 || *(int *)(o + 0x5a) != 0) {
      iVar4 = in_stack_00000004 + index * 4;
      pframe.seg = *(uint16_t *)(iVar4 + 0x5a);
      pframe.ofs = *(uint16_t *)(iVar4 + 0x58);
      bVar3 = true;
      while( true ) {
        if (pframe.ofs == 0 && pframe.seg == 0) break;
        uVar1 = *(uint16_t *)(pframe.ofs + 3);
        uVar2 = *(uint16_t *)(pframe.ofs + 1);
        *(uint16_t *)(pframe.ofs + 3) = 0;
        *(uint16_t *)(pframe.ofs + 1) = 0;
        if (bVar3) {
          (*(uint16_t *)((uint8_t *)&(cte) + 2)) = uVar2;
          (*(uint16_t *)((uint8_t *)&(cte))) = ovr_stshStoreFile((uint8_t *)pframe.ofs,pframe.seg);
          iVar4 = in_stack_00000004 + index * 4;
          *(uint16_t *)(iVar4 + 0x5a) = (*(uint16_t *)((uint8_t *)&(cte) + 2));
          *(uint16_t *)(iVar4 + 0x58) =(uint16_t)( (cte_t *)cte);
        }
        else {
          ovr_stshStoreFile((uint8_t *)pframe.ofs,pframe.seg);
        }
        bVar3 = false;
        pframe.seg = uVar1;
        pframe.ofs = uVar2;
      }
    }
    i = i + 1;
  }
  return;
}


/* 4207:1d87 */

/* [R4] calls ovr_stExit */

uint16_t __cdecl16far ovc15_usesStExit2(byte agntIndex)

{
  int *piVar1;
  uint16_t uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *uStack_12;
  uint16_t uStack_10;
  int iStack_6;
  int iStack_4;
  
  piVar1 = (int *)((uint)agntIndex * 0x34);
  uStack_12 = (int *)CONCAT22(SEG_OF(Agnts),piVar1);
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
        if (agntIndex + 1 != (uint)AgntArrayA[iStack_4][iVar5]) {
          return 0;
        }
      }
      for (; iStack_6 <= iVar3; iStack_6 = iStack_6 + 1) {
        if (agntIndex + 1 != (uint)*(byte *)(iStack_4 * 0x69 + iStack_6 + 0x963)) {
          return 0;
        }
      }
    }
    else {
      for (; iVar5 <= iVar3; iVar5 = iVar5 + 1) {
        if (agntIndex + 1 != (uint)AgntArrayB[iStack_4][iVar5]) {
          return 0;
        }
      }
      for (; iStack_6 <= iVar3; iStack_6 = iStack_6 + 1) {
        if (agntIndex + 1 != (uint)*(byte *)(iStack_4 * 0x69 + iStack_6 + 0x549)) {
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

/* [R7] body shape: compute */

uint16_t __cdecl16far ovc15_compute1(uint16_t *agnt)

{
  uint16_t uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint16_t *puVar6;
  uint16_t uVar7;
  undefined1 uStack_c;
  int *uStack_6;
  uint16_t uStack_4;
  
  uVar7 = (uint16_t)((ulong)agnt >> 0x10);
  puVar6 = (uint16_t *)agnt;
  uVar1 = *(uint16_t *)((int)puVar6 + 0x15);
  piVar2 = (int *)*(int *)((int)puVar6 + 0x13);
  uStack_6 = (int *)CONCAT22(uVar1,piVar2);
  if (*(char *)((int)puVar6 + 0x11) == '\0') {
    iVar5 = piVar2[1];
    iVar3 = *uStack_6;
    iVar4 = ovr_agnt_clampX(*agnt);
    iVar5 = (*(int *)(iVar3 + 0xd) - *(int *)(&columnScreenY[iVar4])) + 0x93;
    uStack_c = (undefined1)iVar5;
  }
  else {
    iVar5 = piVar2[9];
    iVar3 = piVar2[8];
    iVar4 = ovr_agnt_clampX(*agnt);
    iVar5 = (*(int *)(iVar3 + 0xd) - *(int *)(&columnScreenY[iVar4])) + 0xac;
    uStack_c = (undefined1)iVar5;
  }
  return CONCAT11((char)((uint)iVar5 >> 8),uStack_c);
}



/* 4207:1ffe */

/* [R4] calls ovr_randBelow */

int __cdecl16far ovc15_usesRandBelow(agnt_t *agnt,int xSide,char keepPos,char randomY)

{
  char *pcVar1;
  far_t dst;
  uint16_t uVar2;
  uint16_t uVar3;
  uint uVar4;
  byte bVar6;
  int iVar5;
  agnt_t *agnt_00;
  uint16_t uVar7;
  uint16_t xOffsets [4];
  int iStack_6;
  int iStack_4;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)xOffsets;
  F_SCOPY(far_from_u32((uint32_t)(0x24101d09)),dst);
  agnt_00 = (agnt_t *)agnt;
  uVar7 = (uint16_t)((ulong)agnt >> 0x10);
  if (keepPos == '\0') {
    if (xSide < 0) {
      agnt->x = 0;
      uVar2 = ovr_randBelow(0x14,0);
      agnt_00->y = uVar2 & 0xff;
    }
    else if (xSide < 1) {
      iVar5 = ((agnt_00->entity->base).x - GfxRndSeed) + 2;
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      if (3 < iVar5) {
        iVar5 = 3;
      }
      agnt->x = xOffsets[iVar5];
      if (randomY == '\0') {
        agnt_00->y = 0x20;
      }
      else {
        uVar2 = ovr_randBelow(0x14,0);
        agnt_00->y = uVar2 & 0xff;
      }
    }
    else {
      agnt->x = 0xd2;
      uVar2 = ovr_randBelow(0x14,0);
      agnt_00->y = uVar2 & 0xff;
    }
  }
  uVar2 = agnt->x;
  if ((int)uVar2 < 0x6a) {
    iStack_6 = 1;
  }
  else {
    iStack_6 = -1;
  }
  ovr_ovc49_body1(agnt_00,uVar7);
  do {
    if (agnt_00->animVariant == 0x0) {
      uVar4 = ovr_ovc49_compute1(agnt->x);
      bVar6 = (byte)(uVar4 >> 8);
      if ((char)uVar4 == '\0') goto L_OVC15_4207_1ffe_2193;
    }
    else {
L_OVC15_4207_1ffe_2193:
      iVar5 = ovr_ovc49_usesStExit(agnt_00,uVar7);
      bVar6 = (byte)((uint)iVar5 >> 8);
      if ((char)iVar5 == '\0') {
        if (agnt_00->y == 0x20) {
          uVar4 = ovc15_compute1(&agnt->x);
          agnt_00->y = uVar4 & 0xff;
        }
        iStack_4 = 0;
        while ((iStack_4 < (int)(uint)AgntCount && (Agnts[iStack_4].y < (int)agnt_00->y)
               )) {
          iStack_4 = iStack_4 + 1;
        }
        if (iStack_4 < (int)(uint)AgntCount) {
          _fmemmove((char *)CONCAT22(SEG_OF(Agnts),(char *)(iStack_4 * 0x34 + 0x34)),
                    (char *)CONCAT22(SEG_OF(Agnts),(char *)(iStack_4 * 0x34)),
                    ((uint)AgntCount - iStack_4) * 0x34);
        }
        agnt_00->visited = 0x1;
        memcpy((char *)CONCAT22(SEG_OF(Agnts),(char *)(iStack_4 * 0x34)),(char *)agnt,0x34);
        ovr_agnt_usesAgntCount5(iStack_4 + 1);
        ovr_ovc49_fillGridCells((char)iStack_4 + 1,(agnt_t *)(iStack_4 * 0x34),SEG_OF(Agnts),0);
        AgntCount = AgntCount + 1;
        for (iVar5 = 0; iVar5 < (int)(uint)AgntCount; iVar5 = iVar5 + 1) {
          if ((Agnts[iVar5].target != -1) &&
             (iStack_4 <= (int)(uint)Agnts[iVar5].target)) {
            pcVar1 = (char *)(iVar5 * 0x34 + 0xc);
            *pcVar1 = *pcVar1 + '\x01';
          }
        }
        return 1;
      }
    }
    if (iStack_6 < 0) {
      if (agnt->x == 0) {
        agnt->x = 0xd2;
      }
      else {
        agnt->x = agnt->x - 1;
      }
    }
    else if (agnt->x == 0xd2) {
      agnt->x = 0;
    }
    else {
      agnt->x = agnt->x + 1;
    }
    if (agnt->x == uVar2) {
      return (uint)bVar6 << 8;
    }
    if ((xSide == 0) && (randomY == '\0')) {
      agnt_00->y = 0x20;
    }
    else {
      uVar3 = ovr_randBelow(0x14,0);
      agnt_00->y = uVar3 & 0xff;
    }
    ovr_ovc49_body1(agnt_00,uVar7);
  } while( true );
}



/* 4207:2301 */
char * __cdecl16far ovc15_textArena(int owner,uint16_t arg2,uint16_t arg3)

{
  bool bVar1;
  uint uVar2;
  uint16_t uVar3;
  char *pcVar4;
  entity_t *peVar5;
  agntG_t *paVar6;
  far_t far *pfVar7;
  uint16_t unaff_DI;
  uint16_t uVar8;
  uint16_t uVar9;
  int in_stack_00000006;
  char in_stack_00000008;
  agnt_t agntCopy;
  uint uStack_8;
  
  uVar9 = DAT_2000_d190;
  if (AgntFlag1) {
    for (uStack_8 = 0; (int)uStack_8 < (int)(uint)AgntCount; uStack_8 = uStack_8 + 1) {
      if (((Agnts[uStack_8].visited == '\0') &&
          (Agnts[uStack_8].owner == owner)) &&
         ((Agnts[uStack_8].flags & 0xae4) == 0)) {
        Agnts[uStack_8].visited = 1;
        if ((Agnts[uStack_8].animVariant != '\0') ||
           (uVar2 = ovr_ovc49_compute1(Agnts[uStack_8].x), (char)uVar2 == '\0')) {
          uVar2 = ovc15_usesStExit2((byte)uStack_8);
          if ((uVar2 & 0xff) != 0) {
            return (char *)((int)(uint32_t *)&_DATA + 1);
          }
        }
        _fmemmove((char *)CONCAT22(_SS,&agntCopy),
                  (char *)CONCAT22(SEG_OF(Agnts),(char *)(uStack_8 * 0x34)),0x34);
        agntCopy.target = 0xff;
        ovr_ovc41_removeAgent(uStack_8,0,0);
        pcVar4 = (char *)ovc15_usesRandBelow((agnt_t *)CONCAT22(_SS,&agntCopy),
                                             in_stack_00000006,'\x01',in_stack_00000008);
        return pcVar4;
      }
    }
  }
  if (AgntCount < 0x18) {
    peVar5 = Entities + owner;
    _fmemset(MK_FP(_SS, &agntCopy), 0, 0x34);
    agntCopy.target = 0xff;
    (*(uint16_t *)((uint8_t *)&(agntCopy.entity) + 2)) = uVar9;
    agntCopy.owner = owner;
    agntCopy.gdata =
         (agntG_t *)
         CONCAT22(0x195d,(agntG_t *)
                         ((int)(char **)GMenuStrings + (uint)(peVar5->base).gindex * 0x95 + 0x1f));
    (*(uint16_t *)((uint8_t *)&(agntCopy.entity))) =(uint16_t)( peVar5);
    bVar1 = ovc15_usesAlignUp42();
    if (!bVar1) {
      *(undefined1 *)((int)&(peVar5->base).state + 1) = (char)(peVar5->base).flags32;
    }
    agntCopy.strengthMax = (uint8_t)(peVar5->base).flags32;
    agntCopy.strength = *(uint8_t *)((int)&(peVar5->base).state + 1);
    bVar1 = (*(uint *)((int)&(peVar5->base).frames + 3) & 1) != 0;
    paVar6 = (agntG_t *)agntCopy.gdata;
    uVar8 = (uint16_t)((ulong)agntCopy.gdata >> 0x10);
    if ((peVar5->base).level < 10) {
      if ((peVar5->base).level < 4) {
        agntCopy.frames =
             (far_t far *)CONCAT22(*(uint16_t *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 2),
                               *(far_t far **)(paVar6->sprs + (uint)bVar1 * 3));
      }
      else {
        agntCopy.frames =
             (far_t far *)CONCAT22(*(uint16_t *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 6),
                               *(far_t far **)(paVar6->sprs + (uint)bVar1 * 3 + 1));
      }
    }
    else {
      agntCopy.frames =
           (far_t far *)CONCAT22(*(uint16_t *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 10),
                             *(far_t far **)(paVar6->sprs + (uint)bVar1 * 3 + 2));
    }
    agntCopy.animFrame = 0xff;
    agntCopy.faction = (agntCopy.gdata)->ai;
    uVar9 = (uint16_t)((ulong)agntCopy.frames >> 0x10);
    pfVar7 = (far_t far *)agntCopy.frames;
    if (((pfVar7 + 0x1a)->ofs == 0 && pfVar7[0x1a].seg == 0) ||
       ((pfVar7 + 0x16)->ofs == 0 && pfVar7[0x16].seg == 0)) {
      if ((pfVar7 + 0x1a)->ofs != 0 || pfVar7[0x1a].seg != 0) {
        agntCopy.animVariant = 0x1;
      }
    }
    else {
      uVar3 = ovr_randBelow(2,0);
      agntCopy.animVariant = (uint8_t)uVar3;
    }
    uVar3 = ovr_randBelow(2,0);
    (*(uint8_t *)((uint8_t *)&(agntCopy.targetX))) = (char)uVar3 * '\x02' + -1;
    if ((char)agntCopy.targetX < '\x01') {
      if ((char)agntCopy.targetX < '\0') {
        agntCopy.level = 0x1;
      }
      else {
        uVar3 = ovr_randBelow(2,0);
        agntCopy.level = (uint8_t)uVar3;
      }
    }
    else {
      agntCopy.level = 0x0;
    }
    pcVar4 = (char *)ovc15_usesRandBelow((agnt_t *)CONCAT22(_SS,&agntCopy),in_stack_00000006,
                                         '\0',in_stack_00000008);
  }
  else {
    pcVar4 = (char *)0x2400;
  }
  return pcVar4;
}


/* 4207:25dd */
entity_t * __cdecl16far
ovc15_textView(uint32_t param_1,int *param_2,int *param_3,uint16_t param_4,uint16_t param_5,
              int *param_6,int *param_7,int *param_8,int *param_9)

{
  undefined1 stk_02c2;   /* stack slot 02c2 */
  uint8_t *puVar1;
  uint32_t uVar2;
  far_t handle;
  far_t handle_00;
  uint32_t *puVar3;
  char cVar4;
  far_t far *pfVar5;
  stg_tmp_t *gfx;
  cte_t *pcVar6;
  uint32_t *puVar7;
  int iVar8;
  uint uVar9;
  uint16_t uVar10;
  long *plVar11;
  uint16_t uVar12;
  entity_t *peVar13;
  uint uVar14;
  int iVar15;
  uint8_t unaff_BP;
  int unaff_SI;
  uint unaff_DI;
  uint uVar16;
  int iVar17;
  bool bVar18;
  far_t pixels;
  uint32_t in_stack_0000ffee;
  undefined1 uVar19;
  undefined1 uVar20;
  undefined1 in_stack_0000fff8;
  undefined1 in_stack_0000fff9;
  uint16_t uVar21;
  byte bVar22;
  uint32_t in_stack_0000fffa;
  uint16_t uVar23;
  uint16_t uVar24;
  
  iVar17 = (int)((ulong)param_1 >> 0x10);
  uVar14 = (uint)param_1;
  cVar4 = *(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)*(byte *)(uVar14 + 0xd) * 0x95);
  iVar8 = (int)((ulong)in_stack_0000fffa >> 0x10);
  uVar16 = CONCAT11(cVar4,(byte)in_stack_0000fffa);
  if (cVar4 == -1) {
    uVar16 = (uint)(byte)in_stack_0000fffa;
  }
  uVar9 = (uVar16 >> 8) - 1;
  if (5 < uVar9) {
    if (*(byte *)(uVar14 + 0xf) < 10) {
      cVar4 = ovr_manage_rollDice('\x01','\b');
      uVar19 = 0;
      uVar10 = ovr_agnt_abilityModifier(*(byte *)(uVar14 + 0x1a),4);
      iVar17 = CONCAT11(uVar19,cVar4) + (int)(char)uVar10;
    }
    else {
      iVar17 = 2;
    }
    bVar22 = (byte)iVar17;
    if (iVar17 < 1) {
      bVar22 = 1;
    }
    return (entity_t *)(uint)bVar22;
  }
  iVar15 = uVar9 * 2;
  bVar18 = iVar15 == 0;
  switch(uVar9) {
  case 1:
    *(uint16_t *)((int)AgntGs[0].sprs + 10 + iVar15) = 0x195d;
    do {
      *(uint *)((int)AgntGs[0].sprs + 8 + iVar15) = uVar9;
      while( true ) {
        for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
          iVar8 = unaff_SI * 0x95 + iVar17 * 2;
          if (*(int *)((int)AgntGs[0].sprfls + 6 + iVar8) == 0) {
            iVar8 = unaff_SI * 0x95 + iVar17 * 4;
            uVar10 = *(uint16_t *)((int)AgntGs[0].sprs + iVar8);
            iVar15 = unaff_SI * 0x95 + iVar17 * 4;
            *(uint16_t *)((int)AgntGs[0].sprs + 0xe + iVar15) =
                 *(uint16_t *)((int)AgntGs[0].sprs + 2 + iVar8);
            *(uint16_t *)((int)AgntGs[0].sprs + 0xc + iVar15) = uVar10;
          }
          else {
            uVar10 = 0x195d;
            pfVar5 = stshSprite((far_t *)*(uint16_t *)
                                          ((int)AgntGs[0].sprfls + 6 + unaff_SI * 0x95 + iVar17 * 2)
                                ,*(int16_t *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                                (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                          ((int)&AgntGs[0].nanims + unaff_SI * 0x95)
                                                         ,*(uint16_t *)
                                                           ((int)&AgntGs[0].anms + 2 +
                                                           unaff_SI * 0x95)),
                                CONCAT11((char)((uint)iVar8 >> 8),(char)param_1),
                                (bool)in_stack_0000fff8);
            iVar8 = unaff_SI * 0x95 + iVar17 * 4;
            *(uint16_t *)((int)AgntGs[0].sprs + 0xe + iVar8) = uVar10;
            *(uint16_t *)((int)AgntGs[0].sprs + 0xc + iVar8) =(uint16_t)( pfVar5);
          }
        }
        for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
          uVar10 = 0x195d;
          if (*(int *)((int)AgntGs[0].prtfls + unaff_SI * 0x95 + iVar17 * 2) != 0) {
            if ((char)param_1 == '\0') {
              pfVar5 = ovr_stshAllocStub((far_t far *)CONCAT11(in_stack_0000fff9,in_stack_0000fff8));
              iVar8 = unaff_SI * 0x95 + iVar17 * 4;
              uVar12 = 0x195d;
              *(uint16_t *)((int)AgntGs[0].prts + 2 + iVar8) = uVar10;
              *(uint16_t *)((int)AgntGs[0].prts + iVar8) =(uint16_t)( pfVar5);
              pfVar5 = ovr_stshAllocStub((far_t far *)CONCAT11(in_stack_0000fff9,in_stack_0000fff8));
              iVar8 = unaff_SI * 0x95 + iVar17 * 4;
              *(uint16_t *)((int)AgntGs[0].prtpals + 2 + iVar8) = uVar12;
              *(uint16_t *)((int)AgntGs[0].prtpals + iVar8) =(uint16_t)( pfVar5);
            }
            else {
              uVar12 = 0x195d;
              gfx = ovr_grabLbm(*(int16_t *)((int)AgntGs[0].prtfls + unaff_SI * 0x95 + iVar17 * 2),0,0,0,0);
              uVar10 = uVar12;
              ovr_stshUniqueColorsRemap(gfx,0);
              pixels.seg = 0;
              pixels.ofs = (gfx->aptr).seg;
              pfVar5 = ovr_stshRleType2((far_t far *)(&gfx->aptr)->ofs,pixels,0,114,0,0,0,0,0,0);
              pcVar6 = (char *)stsh_store((uint8_t *)pfVar5, 0, &uVar10);
              iVar8 = unaff_SI * 0x95 + iVar17 * 4;

              *(uint16_t *)((int)AgntGs[0].prts + 2 + iVar8) = uVar12;
              *(uint16_t *)((int)AgntGs[0].prts + iVar8) =(uint16_t)( pcVar6);
              puVar7 = ovr_stshWrite((uint32_t *)gfx,0,0,0);
              iVar8 = unaff_SI * 0x95 + iVar17 * 4;
              *(uint16_t *)((int)AgntGs[0].prtpals + 2 + iVar8) = uVar10;
              *(uint16_t *)((int)AgntGs[0].prtpals + iVar8) =(uint16_t)( puVar7);
              ovr_stgFreeTmp(gfx,0);
            }
          }
        }
        peVar13 = (entity_t *)
                  (*(uint *)((int)AgntGs[0].prts + 4 + unaff_SI * 0x95) |
                  *(uint *)((int)AgntGs[0].prts + 6 + unaff_SI * 0x95));
        if ((peVar13 == (entity_t *)0x0) &&
           (peVar13 = (entity_t *)0x0,
           *(int *)((int)AgntGs[0].prts + unaff_SI * 0x95) != 0 ||
           *(int *)((int)AgntGs[0].prts + 2 + unaff_SI * 0x95) != 0)) {
          uVar10 = *(uint16_t *)((int)AgntGs[0].prts + unaff_SI * 0x95);
          *(uint16_t *)((int)AgntGs[0].prts + 6 + unaff_SI * 0x95) =
               *(uint16_t *)((int)AgntGs[0].prts + 2 + unaff_SI * 0x95);
          *(uint16_t *)((int)AgntGs[0].prts + 4 + unaff_SI * 0x95) = uVar10;
          peVar13 = (entity_t *)*(uint *)((int)AgntGs[0].prtpals + unaff_SI * 0x95);
          *(uint16_t *)((int)AgntGs[0].prtpals + 6 + unaff_SI * 0x95) =
               *(uint16_t *)((int)AgntGs[0].prtpals + 2 + unaff_SI * 0x95);
          *(uint *)((int)AgntGs[0].prtpals + 4 + unaff_SI * 0x95) = (uint)peVar13;
        }
        for (iVar17 = 2; iVar17 < 6; iVar17 = iVar17 + 2) {
          iVar8 = unaff_SI * 0x95 + iVar17 * 4;
          if ((*(int *)((int)AgntGs[0].prts + 4 + iVar8) == 0 &&
               *(int *)((int)AgntGs[0].prts + 6 + iVar8) == 0) &&
             (iVar8 = unaff_SI * 0x95 + iVar17 * 4,
             *(int *)((int)AgntGs[0].prtfls + 8 + iVar8) != 0 ||
             *(int *)((int)AgntGs[0].prtfls + 10 + iVar8) != 0)) {
            iVar8 = unaff_SI * 0x95 + iVar17 * 4;
            uVar10 = *(uint16_t *)((int)AgntGs[0].prtfls + 8 + iVar8);
            iVar15 = unaff_SI * 0x95 + iVar17 * 4;
            *(uint16_t *)((int)AgntGs[0].prts + 6 + iVar15) =
                 *(uint16_t *)((int)AgntGs[0].prtfls + 10 + iVar8);
            *(uint16_t *)((int)AgntGs[0].prts + 4 + iVar15) = uVar10;
            iVar8 = unaff_SI * 0x95 + iVar17 * 4;
            uVar10 = *(uint16_t *)((int)AgntGs[0].prts + 0x14 + iVar8);
            iVar15 = unaff_SI * 0x95 + iVar17 * 4;
            *(uint16_t *)((int)AgntGs[0].prtpals + 6 + iVar15) =
                 *(uint16_t *)((int)AgntGs[0].prts + 0x16 + iVar8);
            *(uint16_t *)((int)AgntGs[0].prtpals + 4 + iVar15) = uVar10;
          }
          iVar8 = unaff_SI * 0x95 + iVar17 * 4;
          peVar13 = (entity_t *)
                    (*(uint *)((int)AgntGs[0].prts + iVar8) |
                    *(uint *)((int)AgntGs[0].prts + 2 + iVar8));
          if (peVar13 == (entity_t *)0x0) {
            iVar8 = unaff_SI * 0x95 + iVar17 * 4;
            if (*(int *)((int)AgntGs[0].prtfls + 4 + iVar8) == 0 &&
                *(int *)((int)AgntGs[0].prtfls + 6 + iVar8) == 0) {
              peVar13 = (entity_t *)0x0;
            }
            else {
              iVar8 = unaff_SI * 0x95 + iVar17 * 4;
              uVar10 = *(uint16_t *)((int)AgntGs[0].prtfls + 4 + iVar8);
              iVar15 = unaff_SI * 0x95 + iVar17 * 4;
              *(uint16_t *)((int)AgntGs[0].prts + 2 + iVar15) =
                   *(uint16_t *)((int)AgntGs[0].prtfls + 6 + iVar8);
              *(uint16_t *)((int)AgntGs[0].prts + iVar15) = uVar10;
              iVar8 = unaff_SI * 0x95 + iVar17 * 4;
              peVar13 = (entity_t *)*(uint *)((int)AgntGs[0].prts + 0x10 + iVar8);
              iVar15 = unaff_SI * 0x95 + iVar17 * 4;
              *(uint16_t *)((int)AgntGs[0].prtpals + 2 + iVar15) =
                   *(uint16_t *)((int)AgntGs[0].prts + 0x12 + iVar8);
              *(uint *)((int)AgntGs[0].prtpals + iVar15) = (uint)peVar13;
            }
          }
        }
        unaff_SI = unaff_SI + 1;
        if (0x29 < unaff_SI) {
          return peVar13;
        }
        uVar10 = 0x195d;
        pfVar5 = stshSprite((far_t *)*(uint16_t *)((int)AgntGs[0].sprfls + unaff_SI * 0x95),
                            *(int16_t *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                            (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                      ((int)&AgntGs[0].nanims + unaff_SI * 0x95),
                                                     *(uint16_t *)
                                                      ((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95)),
                            CONCAT11((char)((uint)peVar13 >> 8),(char)param_1),
                            (bool)in_stack_0000fff8);
        *(uint16_t *)((int)AgntGs[0].sprs + 2 + unaff_SI * 0x95) = uVar10;
        *(uint16_t *)((int)AgntGs[0].sprs + unaff_SI * 0x95) =(uint16_t)( pfVar5);
        if (*(int *)((int)AgntGs[0].sprfls + 2 + unaff_SI * 0x95) == 0) {
          uVar10 = *(uint16_t *)((int)AgntGs[0].sprs + unaff_SI * 0x95);
          *(uint16_t *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95) =
               *(uint16_t *)((int)AgntGs[0].sprs + 2 + unaff_SI * 0x95);
          *(uint16_t *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95) = uVar10;
        }
        else {
          uVar10 = 0x195d;
          pfVar5 = stshSprite((far_t *)*(uint16_t *)((int)AgntGs[0].sprfls + 2 + unaff_SI * 0x95),
                              *(int16_t *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                              (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                        ((int)&AgntGs[0].nanims + unaff_SI * 0x95),
                                                       *(uint16_t *)
                                                        ((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95)
                                                      ),
                              CONCAT11((char)((uint)(unaff_SI * 0x95) >> 8),(char)param_1),
                              (bool)in_stack_0000fff8);
          *(uint16_t *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95) = uVar10;
          *(uint16_t *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95) =(uint16_t)( pfVar5);
        }
        if (*(int *)((int)AgntGs[0].sprfls + 4 + unaff_SI * 0x95) == 0) break;
        uVar10 = 0x195d;
        pfVar5 = stshSprite((far_t *)*(uint16_t *)((int)AgntGs[0].sprfls + 4 + unaff_SI * 0x95),
                            *(int16_t *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                            (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                      ((int)&AgntGs[0].nanims + unaff_SI * 0x95),
                                                     *(uint16_t *)
                                                      ((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95)),
                            CONCAT11((char)((uint)(unaff_SI * 0x95) >> 8),(char)param_1),
                            (bool)in_stack_0000fff8);
        *(uint16_t *)((int)AgntGs[0].sprs + 10 + unaff_SI * 0x95) = uVar10;
        *(uint16_t *)((int)AgntGs[0].sprs + 8 + unaff_SI * 0x95) =(uint16_t)( pfVar5);
      }
      uVar9 = *(uint *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95);
      iVar15 = unaff_SI * 0x95;
      *(uint16_t *)((int)AgntGs[0].sprs + 10 + iVar15) =
           *(uint16_t *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95);
    } while( true );
  case 2:
    do {
      cVar4 =(uint16_t)( ovr_ovc15_textView())   /* hand fix: self-call, args lost */;
      uVar10 = (uint16_t)((ulong)Entities >> 0x10);
      *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
           *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) + cVar4;
      uVar10 = (uint16_t)((ulong)Entities >> 0x10);
      *(char *)&((entity_t *)Entities)[EntityCount].base.flags32 =
           (char)((entity_t *)Entities)[EntityCount].base.flags32 + cVar4;
      puVar1 = &((entity_t *)Entities)[EntityCount].base.level;
      *puVar1 = *puVar1 + 0x1;
      iVar17 = EntityCount;
      uVar10 = (uint16_t)((ulong)Entities >> 0x10);
      peVar13 = (entity_t *)Entities;
    } while (peVar13[EntityCount].base.level < 5);
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(byte)param_3 * 0x95) == -1) {
      iVar8 = (uint)peVar13[EntityCount].base.level * 4;
      uVar12 = *(uint16_t *)(iVar8 + -4);
      *(uint16_t *)&peVar13[EntityCount].base.frameIndex = *(uint16_t *)(iVar8 + -2);
      *(uint16_t *)&peVar13[iVar17].base.health = uVar12;
    }
    else {
      iVar8 = (uint)*(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(byte)param_3 * 0x95) * 0x94
              + (uint)peVar13[EntityCount].base.level * 4;
      uVar12 = *(uint16_t *)(iVar8 + -4);
      *(uint16_t *)&peVar13[EntityCount].base.frameIndex = *(uint16_t *)(iVar8 + -2);
      *(uint16_t *)&peVar13[iVar17].base.health = uVar12;
    }
    iVar17 = EntityCount;
    uVar10 = (uint16_t)((ulong)Entities >> 0x10);
    peVar13 = (entity_t *)Entities;
    if (*(int *)&peVar13[EntityCount].base.health == 0 &&
        *(int *)&peVar13[EntityCount].base.frameIndex == 0) {
      puVar1 = &peVar13[EntityCount].base.frameIndex;
      puVar1[0] = 0x0;
      puVar1[1] = 0x0;
      puVar1 = &peVar13[iVar17].base.health;
      puVar1[0] = 0x64;
      puVar1[1] = 0x0;
    }
    iVar17 = EntityCount;
    EntityCount = EntityCount + 1;
    ovr_attact_usesGMapFlags3();
    if (AgntFlag1 != false) {
      uVar10 = (uint16_t)((ulong)Entities >> 0x10);
      peVar13 = (entity_t *)Entities;
      if (((GfxRndSeed - 2U <= ((peVar13 + iVar17)->base).x) &&
          (((peVar13 + iVar17)->base).x <= GfxRndSeed + 1U)) &&
         (peVar13[iVar17].base.y == GfxRndSeed2)) {
        ovc15_textArena(iVar17,0,0);
      }
    }
    peVar13 = Entities + iVar17;
    return peVar13;
  case 3:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 4:
    uVar2 = *(uint32_t *)((uint)PartyCount * 4 + -4);
    ovr_createConstructionRecordFar
              (*(byte *)((int)(far_t far *)(worldMenuLabels + 0xb) +
                        (uint)*(byte *)((int)uVar2 + 0x3e) * 0x95),GfxRndSeed + -1,0,0,0,0,0,0,0);
    ovr_ovc18_textTypeLen(PartyCount - 1,0,0,0,0,0)   /* hand fix: prototype has 4 params */;
    if (2 < Difficulty) {
      ovr_ovc22_usesRandBelow2(PartyCount - 1);
    }
    ovr_ovc22_textRingProt(PartyCount - 1);
    PartyCount = 0;
    ovr_manage_mapPartySlots();
    ovr_stats_openCastlePanel();
    ovr_unit_usesAlignUp4();
    ovr_say((char *)0x45cd,0);
    peVar13 = (entity_t *)(uint)PlayerIndex;
    if (peVar13 == (entity_t *)0x0) {
      ovr_ovc30_nextWave(2);
    }
    return peVar13;
  case 5:
    do {
      if (bVar18) {
        *param_9 = *param_9 + 1;
      }
      while( true ) {
        while( true ) {
          do {
            do {
              unaff_DI = unaff_DI + 1;
              if (GRecordCount <= unaff_DI) {
                iVar17 = *param_8;
                iVar15 = *param_9;
                *param_2 = *param_2 - *param_8;
                *param_3 = *param_3 - *param_9;
                return (entity_t *)(iVar8 - (iVar17 + iVar15));
              }
            } while (GRecords[unaff_DI].party != (char)param_1);
            bVar22 = GRecords[unaff_DI].reserved08;
          } while (BuildingTypes[bVar22].unitType != (*(uint8_t *)((uint8_t *)&(param_1) + 2)));
          *param_6 = *param_6 + 1;
          if (BuildingTypes[bVar22].resource != '\x01') break;
          *param_7 = *param_7 + 1;
        }
        if (BuildingTypes[bVar22].resource != '\x02') break;
        *param_8 = *param_8 + 1;
      }
      bVar18 = BuildingTypes[bVar22].resource == '\x03';
    } while( true );
  }
  if (((byte)uVar9 & (&stk_02c2)[unaff_DI]) == 0) {
    iVar17 = iVar17 + (uint)(0xffec < uVar14);
    plVar11 = LXRSH_at_((long *)CONCAT11(in_stack_0000fff9,in_stack_0000fff8),CONCAT22(iVar8,uVar16)
                        ,unaff_BP);
    uVar14 = (int)plVar11 + HeapPtr;
    iVar17 = iVar17 + (uint)CARRY2((uint)plVar11,HeapPtr);
    uVar16 = uVar14;
    if (iVar17 != 0) {
      uVar16 = 0xffff;
    }
    if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) && ((iVar17 != 0 || (MUSHandle.seg < uVar14))))
       || ((DIGHandle.ofs != 0 || DIGHandle.seg != 0 && ((iVar17 != 0 || (MUSHandle.seg < uVar14))))
          )) {
      ovr_fmFreeAudio(1);
    }
    HeapPtr = 0xffff;
    uVar14 = 0xffff;
    bVar18 = false;
    uVar24 = StshCtPtr2.seg;
    for (uVar21 = StshCtPtr2.ofs; iVar17 = (int)in_stack_0000ffee, uVar21 != 0 || uVar24 != 0;
        uVar21 = *(uint16_t *)(uVar21 + 9)) {
      uVar23 = uVar24;
      if (*(int *)(uVar21 + 0x11) != 0 || *(int *)(uVar21 + 0x13) != 0) {
        if (*(uint *)(uVar21 + 0x13) < uVar16) {
          in_stack_0000ffee = CONCAT22(0x887f,iVar17);
          (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)*(uint16_t *)(uVar21 + 0x13);
          handle.ofs = *(uint16_t *)(uVar21 + 0x11);
          (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)*(uint16_t *)(uVar21 + 0x13) >> 8);
          stshFree(handle);
          *(uint16_t *)(uVar21 + 0x13) = 0;
          *(uint16_t *)(uVar21 + 0x11) = 0;
          bVar18 = true;
          uVar23 = uVar24;
        }
        else {
          if (*(uint *)(uVar21 + 0x13) < uVar14) {
            uVar14 = *(uint *)(uVar21 + 0x13);
            in_stack_0000ffee = CONCAT22(uVar24,uVar21);
          }
          if (*(uint *)(uVar21 + 0x13) < HeapPtr) {
            HeapPtr = *(uint *)(uVar21 + 0x13);
          }
        }
      }
      uVar24 = *(uint16_t *)(uVar21 + 0xb);
    }
    if (!bVar18) {
      if (uVar14 == 0xffff) {
        bVar18 = ovr_fmFreeAudio(1);
        if (bVar18) {
          return (entity_t *)((int)(uint32_t *)&_DATA + 1);
        }
        if (audioBusy != '\0') {
          return (entity_t *)0x0;
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x14);
      }
      uVar10 = (uint16_t)((ulong)in_stack_0000ffee >> 0x10);
      uVar19 = (undefined1)*(uint16_t *)(iVar17 + 0x13);
      uVar20 = (undefined1)((uint)*(uint16_t *)(iVar17 + 0x13) >> 8);
      uVar12 = 0x8939;
      (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = uVar19;
      handle_00.ofs = *(uint16_t *)(iVar17 + 0x11);
      (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = uVar20;
      stshFree(handle_00);
      *(uint16_t *)(iVar17 + 0x13) = 0;
      *(uint16_t *)(iVar17 + 0x11) = 0;
      HeapPtr = CONCAT11(uVar20,uVar19);
    }
    puVar3 = (uint32_t *)&_DATA;
  }
  else {
    puVar3 = (uint32_t *)&_DATA;
  }
  return (entity_t *)((int)puVar3 + 1);
}


/* 4207:26bc */
agnt_t * __cdecl16far ovc15_textError(uint32_t partyIndex,agnt_t *agnt)

{
  undefined1 stk_02c2;   /* stack slot 02c2 */
  undefined1 stk_bac4;   /* stack slot bac4 */
  undefined1 stk_c1dd;   /* stack slot c1dd */
  undefined1 stk_ffe8;   /* stack slot ffe8 */
  undefined1 stk_ffe9;   /* stack slot ffe9 */
  undefined1 stk_fff2;   /* stack slot fff2 */
  uint *puVar1;
  uint16_t *puVar2;
  uint8_t *puVar3;
  uint32_t uVar4;
  far_t handle;
  far_t handle_00;
  uint8_t uVar5;
  char cVar6;
  byte bVar7;
  char cVar8;
  bool bVar9;
  undefined1 uVar10;
  undefined1 uVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  uint16_t uVar11;
  far_t far *pfVar12;
  cte_t *pcVar13;
  uint16_t *puVar14;
  long *plVar15;
  uint uVar16;
  uint16_t uVar17;
  uint32_t *puVar18;
  agnt_t *paVar19;
  int iVar20;
  int iVar21;
  entity_t *in_CX;
  stg_tmp_t *gfx;
  uint16_t uVar25;
  uint16_t dstSeg;
  entity_t *peVar26;
  uint uVar27;
  undefined1 *puVar28;
  entity_t *peVar29;
  uint32_t *unaff_SI;
  char *pcVar30;
  uint uVar31;
  char *unaff_DI;
  uint16_t uVar32;
  uint32_t *puVar33;
  uint16_t uVar34;
  uint8_t uVar35;
  bool bVar36;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  ulong uVar37;
  char acStackY_1b6 [120];
  char acStackY_13e [36];
  uint16_t auStackY_11a [66];
  uint16_t auStackY_96 [24];
  entity_t eStackY_66;
  uint16_t uStackY_2c;
  uint16_t uStackY_2a;
  entity_t *in_stack_0000ffe2;
  uint8_t uVar38;
  far_t entries;
  int iVar39;
  undefined1 uVar40;
  undefined1 in_stack_0000ffee;
  undefined1 in_stack_0000ffef;
  undefined1 in_stack_0000fff0;
  undefined1 in_stack_0000fff1;
  undefined1 uVar41;
  undefined1 in_stack_0000fff2;
  undefined1 in_stack_0000fff3;
  byte in_stack_0000fff4;
  byte in_stack_0000fff5;
  uint uVar42;
  byte bVar43;
  uint8_t in_stack_0000fffc;
  byte bVar44;
  
  uVar16 = CONCAT11(in_stack_0000fff1,in_stack_0000fff0);
  puVar33 = (uint32_t *)((ulong)partyIndex >> 0x10);
  uVar27 = (uint)partyIndex;
  puVar14 = (uint16_t *)((uint)*(byte *)(uVar27 + 0x1a) * 4);
  uVar11 = puVar14[1];
  uVar32 = *puVar14;
  bVar43 = (byte)uVar32;
  uVar10 = (undefined1)((uint)uVar32 >> 8);
  uVar25 = 0x195d;
  uVar34 = 0x195d;
  bVar44 = *(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)*(byte *)(uVar27 + 0xd) * 0x95);
  if (bVar44 == 0xff) {
    bVar44 = 0;
  }
  pcVar30 = (char *)0x0;
  uVar17 = (uint16_t)bVar44;
  if (6 < uVar17) {
    if ((agnt_t *)agnt != (agnt_t *)0x0 || (*(uint16_t *)((uint8_t *)&(agnt) + 2)) != 0) {
      uVar40 = 0;
      uVar23 = 0;
      uVar10 = 100;
      uVar24 = 0;
      plVar15 = LXMUL_at_((long *)((int)&GSTARTX_SavedVectors[2].ofs + 1),ZEXT24(unaff_SI) << 0x10,
                          CONCAT22(uVar11,uVar32));
      uVar37 = LDIV_at_(CONCAT13((char)((uint)(*(uint16_t *)((uint8_t *)&(agnt) + 2)) >> 8),
                                 CONCAT12((char)(*(uint16_t *)((uint8_t *)&(agnt) + 2)),plVar15)),
                        CONCAT13(uVar23,CONCAT12(uVar40,CONCAT11(uVar24,uVar10))));
      agnt = (agnt_t *)(uVar37 & 0xffff);
    }
    return (agnt_t *)agnt;
  }
  puVar28 = (undefined1 *)(uVar17 * 2);
  switch(uVar17) {
  case 0:
    if ((bVar44 & (&stk_02c2)[(int)unaff_DI]) == 0) {
      iVar39 = (int)puVar33 + (uint)(0xffec < uVar27);
      uVar34 = 0x1000;
      plVar15 = LXRSH_at_((long *)unaff_SI,CONCAT22(uVar11,uVar32),in_stack_0000fffc);
      uVar27 = (int)plVar15 + HeapPtr;
      iVar39 = iVar39 + (uint)CARRY2((uint)plVar15,HeapPtr);
      uVar16 = uVar27;
      if (iVar39 != 0) {
        uVar16 = 0xffff;
      }
      if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) && ((iVar39 != 0 || (MUSHandle.seg < uVar27)))
          ) || ((DIGHandle.ofs != 0 || DIGHandle.seg != 0 &&
                ((iVar39 != 0 || (MUSHandle.seg < uVar27)))))) {
        uVar34 = 0x22f8;
        in_stack_0000fff0 = 0x28;
        in_stack_0000fff1 = 0x88;
        ovr_fmFreeAudio(1);
      }
      uVar42 = 0xffff;
      HeapPtr = 0xffff;
      bVar36 = false;
      uVar10 = (undefined1)StshCtPtr2.seg;
      uVar24 = (undefined1)(StshCtPtr2.seg >> 8);
      uVar27 = 0xffff;
      uVar11 = StshCtPtr2.ofs;
      while( true ) {
        uVar40 = (undefined1)uVar34;
        uVar23 = (undefined1)((uint)uVar34 >> 8);
        if (uVar11 == 0 && CONCAT11(uVar24,uVar10) == 0) break;
        uVar32 = (uint16_t)(CONCAT13(uVar24,CONCAT12(uVar10,uVar11)) >> 0x10);
        uVar31 = uVar27;
        if (*(int *)(uVar11 + 0x11) != 0 || *(int *)(uVar11 + 0x13) != 0) {
          if (*(uint *)(uVar11 + 0x13) < uVar16) {
            uVar32 = (uint16_t)(CONCAT13(uVar24,CONCAT12(uVar10,uVar11)) >> 0x10);
            in_stack_0000ffee = 0x7f;
            in_stack_0000ffef = 0x88;
            (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)*(uint16_t *)(uVar11 + 0x13);
            handle.ofs = *(uint16_t *)(uVar11 + 0x11);
            (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)*(uint16_t *)(uVar11 + 0x13) >> 8);
            stshFree(handle);
            uVar32 = (uint16_t)(CONCAT13(uVar24,CONCAT12(uVar10,uVar11)) >> 0x10);
            *(uint16_t *)(uVar11 + 0x13) = 0;
            *(uint16_t *)(uVar11 + 0x11) = 0;
            bVar36 = true;
            in_stack_0000fff0 = uVar40;
            in_stack_0000fff1 = uVar23;
          }
          else {
            if (*(uint *)(uVar11 + 0x13) < uVar27) {
              uVar31 = *(uint *)(uVar11 + 0x13);
              in_stack_0000ffee = (undefined1)uVar11;
              in_stack_0000ffef = (undefined1)(uVar11 >> 8);
              in_stack_0000fff0 = uVar10;
              in_stack_0000fff1 = uVar24;
              uVar42 = uVar27;
            }
            if (*(uint *)(uVar11 + 0x13) < HeapPtr) {
              HeapPtr = *(uint *)(uVar11 + 0x13);
            }
          }
        }
        uVar32 = (uint16_t)(CONCAT13(uVar24,CONCAT12(uVar10,uVar11)) >> 0x10);
        puVar14 = (uint16_t *)(uVar11 + 0xb);
        uVar11 = *(uint16_t *)(uVar11 + 9);
        uVar10 = (undefined1)*puVar14;
        uVar24 = (undefined1)((uint)*puVar14 >> 8);
        uVar27 = uVar31;
      }
      if (!bVar36) {
        if (uVar27 == 0xffff) {
          bVar36 = ovr_fmFreeAudio(1);
          if (bVar36) {
            return (agnt_t *)0x1;
          }
          if (audioBusy == '\0') {
                    /* WARNING: Subroutine does not return */
            ovr_stExit(0x14);
          }
          return (agnt_t *)0x0;
        }
        iVar39 = CONCAT11(in_stack_0000ffef,in_stack_0000ffee);
        uVar32 = (uint16_t)
                 (CONCAT13(in_stack_0000fff1,CONCAT12(in_stack_0000fff0,iVar39)) >> 0x10);
        uVar10 = 0x39;
        uVar24 = 0x89;
        (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = (char)*(uint16_t *)(iVar39 + 0x13);
        handle_00.ofs = *(uint16_t *)(iVar39 + 0x11);
        (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = (char)((uint)*(uint16_t *)(iVar39 + 0x13) >> 8);
        stshFree(handle_00);
        HeapPtr = uVar42;
        iVar39 = CONCAT11(uVar24,uVar10);
        uVar32 = (uint16_t)(CONCAT13(uVar23,CONCAT12(uVar40,iVar39)) >> 0x10);
        *(uint16_t *)(iVar39 + 0x13) = 0;
        *(uint16_t *)(iVar39 + 0x11) = 0;
      }
    }
    return (agnt_t *)0x1;
  case 1:
    *puVar28 = *puVar28;
    do {
      uVar32 = 0x195d;
      pfVar12 = stshSprite((far_t *)*(uint16_t *)
                                     ((int)AgntGs[0].sprfls + 6 +
                                     (int)pcVar30 * 0x95 + (int)unaff_DI * 2),
                           *(int16_t *)(puVar28 + 0x26fe),
                           (anm_t *)CONCAT13(uVar10,CONCAT12(bVar43,unaff_SI)),uVar11,
                           (bool)in_stack_0000fffc);
      iVar39 = (int)pcVar30 * 0x95 + (int)unaff_DI * 4;
      *(uint16_t *)((int)AgntGs[0].sprs + 0xe + iVar39) = uVar32;
      *(uint16_t *)((int)AgntGs[0].sprs + 0xc + iVar39) =(uint16_t)( pfVar12);
      while( true ) {
        unaff_DI = unaff_DI + 1;
        while (2 < (int)unaff_DI) {
          for (iVar39 = 0; iVar39 < 6; iVar39 = iVar39 + 1) {
            uVar32 = 0x195d;
            if (*(int *)((int)AgntGs[0].prtfls + (int)pcVar30 * 0x95 + iVar39 * 2) != 0) {
              if ((byte)partyIndex == 0) {
                pfVar12 = ovr_stshAllocStub((far_t far *)CONCAT11(bVar44,in_stack_0000fffc));
                iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
                uVar34 = 0x195d;
                *(uint16_t *)((int)AgntGs[0].prts + 2 + iVar20) = uVar32;
                *(uint16_t *)((int)AgntGs[0].prts + iVar20) =(uint16_t)( pfVar12);
                pfVar12 = ovr_stshAllocStub((far_t far *)CONCAT11(bVar44,in_stack_0000fffc));
                iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
                *(uint16_t *)((int)AgntGs[0].prtpals + 2 + iVar20) = uVar34;
                *(uint16_t *)((int)AgntGs[0].prtpals + iVar20) =(uint16_t)( pfVar12);
              }
              else {
                gfx = (stg_tmp_t *)((int)&BuildingTypes[0x9f].income + 1);
                ovr_grabLbm(*(int16_t *)((int)AgntGs[0].prtfls + (int)pcVar30 * 0x95 + iVar39 * 2),0,0,0,0);
                in_stack_0000fffc = (uint8_t)gfx;
                bVar44 = (byte)((uint)gfx >> 8);
                ovr_stshUniqueColorsRemap(gfx,0);
                pfVar12 = ovr_stshRleType2(*(far_t far **)((char *)0x300),0,0,0,0,0,0,0,0,0);
                pcVar13 = (char *)stsh_store((uint8_t *)pfVar12, 0, &uVar32);
                iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;

                *(uint16_t *)((int)AgntGs[0].prts + 2 + iVar20) =(uint16_t)( gfx);
                *(uint16_t *)((int)AgntGs[0].prts + iVar20) =(uint16_t)( pcVar13);
                puVar33 = ovr_stshWrite((uint32_t *)0x0,(uint8_t *)
                                        CONCAT13(3,(uint3)CONCAT11(bVar44,in_stack_0000fffc)),0,0);
                iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
                *(uint16_t *)((int)AgntGs[0].prtpals + 2 + iVar20) = uVar32;
                *(uint16_t *)((int)AgntGs[0].prtpals + iVar20) =(uint16_t)( puVar33);
                ovr_stgFreeTmp((stg_tmp_t *)CONCAT11(bVar44,in_stack_0000fffc),0);
              }
            }
          }
          paVar19 = (agnt_t *)
                    (*(uint *)((int)AgntGs[0].prts + 4 + (int)pcVar30 * 0x95) |
                    *(uint *)((int)AgntGs[0].prts + 6 + (int)pcVar30 * 0x95));
          if ((paVar19 == (agnt_t *)0x0) &&
             (paVar19 = (agnt_t *)0x0,
             *(int *)((int)AgntGs[0].prts + (int)pcVar30 * 0x95) != 0 ||
             *(int *)((int)AgntGs[0].prts + 2 + (int)pcVar30 * 0x95) != 0)) {
            uVar32 = *(uint16_t *)((int)AgntGs[0].prts + (int)pcVar30 * 0x95);
            *(uint16_t *)((int)AgntGs[0].prts + 6 + (int)pcVar30 * 0x95) =
                 *(uint16_t *)((int)AgntGs[0].prts + 2 + (int)pcVar30 * 0x95);
            *(uint16_t *)((int)AgntGs[0].prts + 4 + (int)pcVar30 * 0x95) = uVar32;
            paVar19 = (agnt_t *)*(uint *)((int)AgntGs[0].prtpals + (int)pcVar30 * 0x95);
            *(uint16_t *)((int)AgntGs[0].prtpals + 6 + (int)pcVar30 * 0x95) =
                 *(uint16_t *)((int)AgntGs[0].prtpals + 2 + (int)pcVar30 * 0x95);
            *(uint *)((int)AgntGs[0].prtpals + 4 + (int)pcVar30 * 0x95) = (uint)paVar19;
          }
          for (iVar39 = 2; iVar39 < 6; iVar39 = iVar39 + 2) {
            iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
            if ((*(int *)((int)AgntGs[0].prts + 4 + iVar20) == 0 &&
                 *(int *)((int)AgntGs[0].prts + 6 + iVar20) == 0) &&
               (iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4,
               *(int *)((int)AgntGs[0].prtfls + 8 + iVar20) != 0 ||
               *(int *)((int)AgntGs[0].prtfls + 10 + iVar20) != 0)) {
              iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
              uVar32 = *(uint16_t *)((int)AgntGs[0].prtfls + 8 + iVar20);
              iVar21 = (int)pcVar30 * 0x95 + iVar39 * 4;
              *(uint16_t *)((int)AgntGs[0].prts + 6 + iVar21) =
                   *(uint16_t *)((int)AgntGs[0].prtfls + 10 + iVar20);
              *(uint16_t *)((int)AgntGs[0].prts + 4 + iVar21) = uVar32;
              iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
              uVar32 = *(uint16_t *)((int)AgntGs[0].prts + 0x14 + iVar20);
              iVar21 = (int)pcVar30 * 0x95 + iVar39 * 4;
              *(uint16_t *)((int)AgntGs[0].prtpals + 6 + iVar21) =
                   *(uint16_t *)((int)AgntGs[0].prts + 0x16 + iVar20);
              *(uint16_t *)((int)AgntGs[0].prtpals + 4 + iVar21) = uVar32;
            }
            iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
            paVar19 = (agnt_t *)
                      (*(uint *)((int)AgntGs[0].prts + iVar20) |
                      *(uint *)((int)AgntGs[0].prts + 2 + iVar20));
            if (paVar19 == (agnt_t *)0x0) {
              iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
              if (*(int *)((int)AgntGs[0].prtfls + 4 + iVar20) == 0 &&
                  *(int *)((int)AgntGs[0].prtfls + 6 + iVar20) == 0) {
                paVar19 = (agnt_t *)0x0;
              }
              else {
                iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
                uVar32 = *(uint16_t *)((int)AgntGs[0].prtfls + 4 + iVar20);
                iVar21 = (int)pcVar30 * 0x95 + iVar39 * 4;
                *(uint16_t *)((int)AgntGs[0].prts + 2 + iVar21) =
                     *(uint16_t *)((int)AgntGs[0].prtfls + 6 + iVar20);
                *(uint16_t *)((int)AgntGs[0].prts + iVar21) = uVar32;
                iVar20 = (int)pcVar30 * 0x95 + iVar39 * 4;
                paVar19 = (agnt_t *)*(uint *)((int)AgntGs[0].prts + 0x10 + iVar20);
                iVar21 = (int)pcVar30 * 0x95 + iVar39 * 4;
                *(uint16_t *)((int)AgntGs[0].prtpals + 2 + iVar21) =
                     *(uint16_t *)((int)AgntGs[0].prts + 0x12 + iVar20);
                *(uint *)((int)AgntGs[0].prtpals + iVar21) = (uint)paVar19;
              }
            }
          }
          pcVar30 = pcVar30 + 1;
          if (0x29 < (int)pcVar30) {
            return paVar19;
          }
          uVar32 = 0x195d;
          pfVar12 = stshSprite((far_t *)*(uint16_t *)((int)AgntGs[0].sprfls + (int)pcVar30 * 0x95)
                               ,*(int16_t *)((int)&AgntGs[0].anms + (int)pcVar30 * 0x95),
                               (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                         ((int)&AgntGs[0].nanims +
                                                         (int)pcVar30 * 0x95),
                                                        *(uint16_t *)
                                                         ((int)&AgntGs[0].anms + 2 +
                                                         (int)pcVar30 * 0x95)),
                               CONCAT11((char)((uint)paVar19 >> 8),(byte)partyIndex),
                               (bool)in_stack_0000fffc);
          *(uint16_t *)((int)AgntGs[0].sprs + 2 + (int)pcVar30 * 0x95) = uVar32;
          *(uint16_t *)((int)AgntGs[0].sprs + (int)pcVar30 * 0x95) =(uint16_t)( pfVar12);
          if (*(int *)((int)AgntGs[0].sprfls + 2 + (int)pcVar30 * 0x95) == 0) {
            uVar32 = *(uint16_t *)((int)AgntGs[0].sprs + (int)pcVar30 * 0x95);
            *(uint16_t *)((int)AgntGs[0].sprs + 6 + (int)pcVar30 * 0x95) =
                 *(uint16_t *)((int)AgntGs[0].sprs + 2 + (int)pcVar30 * 0x95);
            *(uint16_t *)((int)AgntGs[0].sprs + 4 + (int)pcVar30 * 0x95) = uVar32;
          }
          else {
            uVar32 = 0x195d;
            pfVar12 = stshSprite((far_t *)*(uint16_t *)
                                           ((int)AgntGs[0].sprfls + 2 + (int)pcVar30 * 0x95),
                                 *(int16_t *)((int)&AgntGs[0].anms + (int)pcVar30 * 0x95),
                                 (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                           ((int)&AgntGs[0].nanims +
                                                           (int)pcVar30 * 0x95),
                                                          *(uint16_t *)
                                                           ((int)&AgntGs[0].anms + 2 +
                                                           (int)pcVar30 * 0x95)),
                                 CONCAT11((char)((uint)((int)pcVar30 * 0x95) >> 8),(byte)partyIndex),
                                 (bool)in_stack_0000fffc);
            *(uint16_t *)((int)AgntGs[0].sprs + 6 + (int)pcVar30 * 0x95) = uVar32;
            *(uint16_t *)((int)AgntGs[0].sprs + 4 + (int)pcVar30 * 0x95) =(uint16_t)( pfVar12);
          }
          if (*(int *)((int)AgntGs[0].sprfls + 4 + (int)pcVar30 * 0x95) == 0) {
            uVar32 = *(uint16_t *)((int)AgntGs[0].sprs + 4 + (int)pcVar30 * 0x95);
            *(uint16_t *)((int)AgntGs[0].sprs + 10 + (int)pcVar30 * 0x95) =
                 *(uint16_t *)((int)AgntGs[0].sprs + 6 + (int)pcVar30 * 0x95);
            *(uint16_t *)((int)AgntGs[0].sprs + 8 + (int)pcVar30 * 0x95) = uVar32;
          }
          else {
            uVar32 = 0x195d;
            pfVar12 = stshSprite((far_t *)*(uint16_t *)
                                           ((int)AgntGs[0].sprfls + 4 + (int)pcVar30 * 0x95),
                                 *(int16_t *)((int)&AgntGs[0].anms + (int)pcVar30 * 0x95),
                                 (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                           ((int)&AgntGs[0].nanims +
                                                           (int)pcVar30 * 0x95),
                                                          *(uint16_t *)
                                                           ((int)&AgntGs[0].anms + 2 +
                                                           (int)pcVar30 * 0x95)),
                                 CONCAT11((char)((uint)((int)pcVar30 * 0x95) >> 8),(byte)partyIndex),
                                 (bool)in_stack_0000fffc);
            *(uint16_t *)((int)AgntGs[0].sprs + 10 + (int)pcVar30 * 0x95) = uVar32;
            *(uint16_t *)((int)AgntGs[0].sprs + 8 + (int)pcVar30 * 0x95) =(uint16_t)( pfVar12);
          }
          unaff_DI = (char *)0x0;
        }
        iVar39 = (int)pcVar30 * 0x95 + (int)unaff_DI * 2;
        if (*(int *)((int)AgntGs[0].sprfls + 6 + iVar39) != 0) break;
        iVar39 = (int)pcVar30 * 0x95 + (int)unaff_DI * 4;
        uVar32 = *(uint16_t *)((int)AgntGs[0].sprs + iVar39);
        iVar20 = (int)pcVar30 * 0x95 + (int)unaff_DI * 4;
        *(uint16_t *)((int)AgntGs[0].sprs + 0xe + iVar20) =
             *(uint16_t *)((int)AgntGs[0].sprs + 2 + iVar39);
        *(uint16_t *)((int)AgntGs[0].sprs + 0xc + iVar20) = uVar32;
      }
      uVar11 = CONCAT11((char)((uint)iVar39 >> 8),(byte)partyIndex);
      bVar43 = *(byte *)((int)&AgntGs[0].nanims + (int)pcVar30 * 0x95);
      uVar10 = 0;
      puVar28 = (undefined1 *)((int)pcVar30 * 0x95);
      unaff_SI = *(uint32_t **)(puVar28 + 0x2700);
    } while( true );
  case 2:
    return (agnt_t *)(uVar17 & 0xff8e);
  case 3:
switchD_4000_4790_caseD_3:
    uVar32 = (uint16_t)((ulong)Entities >> 0x10);
    cVar6 = *(char *)((int)&(((entity_t *)Entities)->base).flags32 + uVar17);
    cVar8 = (char)(uVar17 >> 8);
    *(char *)((int)&((entity_t *)Entities)[(int)pcVar30].base.state + 1) = cVar6;
    if (EntityCount <= pcVar30 + 1) {
      if ((cVar6 != '\0') || (cVar8 != '\0')) {
        if (bVar44 == 0) {
          ovr_stop_audio();
          CurSfxType3 = 0xff;
          ovr_play_sfx(90,0,0);
        }
        else if (cVar8 == '\0') {
          if (cVar6 != '\0') {
            ovr_play_sfx(37,0,0);
          }
        }
        else {
          ovr_play_sfx(35,0,0);
        }
      }
      GGameState = 0x3d;
      paVar19 = (agnt_t *)0x2410;
      if (DebugVerbose != false) {
        paVar19 = (agnt_t *)0x2410;
        printf("%d \r");
      }
      ovr_OVC23_55fe_29a2_entry();
      return paVar19;
    }
    paVar19 = (agnt_t *)0x24ff;
    ovr_say((char *)"The damaged structures belonging to all leaders are highlighted in red.",0);
    return paVar19;
  case 4:
    in_CX = (entity_t *)CONCAT11((char)((uint)in_CX >> 8),(char)in_CX + unaff_DI[-0x63b2]);
    do {
      peVar29 = (entity_t *)(puVar28 + (int)in_CX);
      (peVar29->base).y = uVar17;
      (peVar29->base).x = uVar25;
      while( true ) {
        unaff_DI = unaff_DI + 1;
        pcVar30 = pcVar30 + 1;
L_manage_4d05_2d79_2EE8:
        if ((int)(uint)in_stack_0000fff5 <= (int)pcVar30) {
          cVar6 = '@';
          manage_openTalkWindow();
          if (cVar6 != '\x02') goto L_attact_3f0b_1082_11EA;
          if (ScreenMode == '\0') {
            manage_openTalkWindow();
          }
          TextBlitY = 0xc;
          TextBlitX = 0x11;
          uVar40 = (undefined1)Font02.seg;
          uVar23 = (undefined1)(Font02.seg >> 8);
          uVar10 = (undefined1)Font02.ofs;
          uVar24 = (undefined1)(Font02.ofs >> 8);
          if ((byte)partyIndex != 0xff) {
            uVar22 = 0xde;
            uVar41 = 0;
            ovr_ovc45_compute9(acStackY_1b6,(char *)CONCAT22(Font02.seg,_SS),
                               (char *)CONCAT22(Font02.ofs,(char *)0xde),Font02.seg,'K');
            SUB_5b66_1d94();
            uVar32 = 0x2410;
            uStackY_2a = 0x23f1;
            uStackY_2c = 0x44;
            pcVar30 = ovr_stsprintf(acStackY_13e,(char *)CONCAT22(0x550a,_SS),
                                    (char *)CONCAT22(*(uint16_t *)
                                                      ((uint)*(byte *)(CONCAT11(uVar23,uVar40) +
                                                                      0x2f) * 4 + 0xeb),
                                                     (char *)0x2410));
            ovr_blitLabel(pcVar30,(uint8_t *)CONCAT13(uVar24,CONCAT12(uVar10,uVar32)));
            TextBlitY = TextBlitY + 0xc;
            iVar39 = ovr_font_textWidth((char *)"UNITS",0,0,0,0);
            TextBlitX = 0x89 - iVar39;
            ovr_blitLabel((char *)"UNITS",
                          (uint8_t *)
                          CONCAT13((char)(Font02.ofs >> 8),CONCAT12((char)Font02.ofs,0x2410)));
            iVar39 = ovr_font_textWidth((char *)"POPULATION",0,0,0,0);
            uVar25 = 0xd4 - iVar39;
            TextBlitX = uVar25;
            ovr_blitLabel((char *)"POPULATION",
                          (uint8_t *)
                          CONCAT13((char)(Font02.ofs >> 8),CONCAT12((char)Font02.ofs,0x2410)));
            iVar39 = 0;
            while( true ) {
              TextBlitY = TextBlitY + 0xc;
              cVar6 = (char)in_CX;
              if ((int)(uint)in_stack_0000fff5 <= iVar39) break;
              TextBlitX = 0x11;
              uVar10 = (undefined1)(Font02.ofs >> 8);
              if ((iVar39 < 5) || (in_stack_0000fff4 == 0)) {
                ovr_blitLabel((char *)auStackY_96[iVar39 * 2],
                              (uint8_t *)
                              CONCAT13(uVar10,CONCAT12((char)Font02.ofs,auStackY_96[iVar39 * 2 + 1])
                                      ));
              }
              else {
                uVar16 = (uint)*(byte *)((int)*(uint32_t *)((uint)(byte)partyIndex << 2) + 0x2f);
                ovr_blitLabel((char *)auStackY_11a[iVar39 * 2 + uVar16 * 8],
                              (uint8_t *)
                              CONCAT13(uVar10,CONCAT12((char)Font02.ofs,
                                                       auStackY_11a[iVar39 * 2 + uVar16 * 8 + 1])));
              }
              ovc27_textCharmed();
              ovr_stsprintf(acStackY_13e);
              iVar20 = ovr_font_textWidth(acStackY_13e,0,0,0,0);
              TextBlitX = 0x89 - iVar20;
              ovr_blitLabel(acStackY_13e,
                            (uint8_t *)
                            CONCAT13((char)(Font02.ofs >> 8),CONCAT12((char)Font02.ofs,_SS)));
              ovr_stsprintf(acStackY_13e);
              iVar20 = ovr_font_textWidth(acStackY_13e,0,0,0,0);
              uVar25 = 0xd4 - iVar20;
              TextBlitX = uVar25;
              ovr_blitLabel(acStackY_13e,
                            (uint8_t *)
                            CONCAT13((char)(Font02.ofs >> 8),CONCAT12((char)Font02.ofs,_SS)));
              iVar39 = iVar39 + 1;
            }
            CurSfxType3 = 0x3c;
            entries.seg = (uint16_t)_SS;
            entries.ofs = (uint16_t)&eStackY_66;
            uVar32 = ovr_ovc28_usesUiInputText(entries,(uint16_t)unaff_DI,0,0,0,0);
            cVar8 = (char)uVar32;
            keyboardInputMode = 0;
            if (((cVar8 != '\0') && (cVar8 != '\x01')) && (cVar8 != -2)) {
              (&stk_bac4)[(int)unaff_DI] = (&stk_bac4)[(int)unaff_DI] + cVar6;
              iVar20 = 0x2410;
              do {
                iVar21 = iVar20 * uVar25;
                iVar20 = iVar39;
                if (Agnts[iVar39].strengthMax < *(byte *)(iVar21 + 0x21)) {
                  Agnts[iVar39].strength = Agnts[iVar39].strengthMax;
                }
                do {
                  iVar20 = iVar20 + 1;
                  if ((int)(uint)AgntCount <= iVar20) {
                    ovr_audio_panFromX((agnt_t *)agnt,0);
                    ovr_play_sfxU(0x1c,0,0,0,0);
                    return (agnt_t *)0x1;
                  }
                } while (Agnts[iVar20].owner != ((agnt_t *)agnt)->owner);
                if (*(byte *)(uVar11 + 0x32) < Agnts[iVar20].strengthMax) {
                  Agnts[iVar20].strengthMax = *(undefined1 *)(uVar11 + 0x32);
                }
                uVar25 = 0x34;
                iVar39 = iVar20;
              } while( true );
            }
            if (cVar8 == -2) {
              Cancelled = 1;
            }
            return (agnt_t *)0x2410;
          }
          uVar16 = ovr_blitLabel((char *)"Total population.",
                                 (uint8_t *)CONCAT13(uVar24,CONCAT12(uVar10,0x2410)));
          *pcVar30 = *pcVar30 + (char)(uVar16 >> 8) + ((undefined1 *)0xfff3 < &stk_ffe8);
          ((dos_psp_t *)((entity_t **)&Entities + uVar16))->jft[0] = 0;
          uVar17 = (int)pcVar30 * 0x37;
          goto switchD_4000_4790_caseD_3;
        }
        if ((4 < (int)pcVar30) && (in_stack_0000fff4 != 0)) break;
        uVar25 = auStackY_96[(int)pcVar30 * 2];
        in_CX = &eStackY_66;
        peVar29 = (entity_t *)(&(in_CX->base).x + (int)unaff_DI * 2);
        (&eStackY_66.base.y)[(int)unaff_DI * 2] = auStackY_96[(int)pcVar30 * 2 + 1];
        (peVar29->base).x = uVar25;
      }
      uVar34 = (uint16_t)((ulong)*(uint32_t *)((uint)(byte)partyIndex << 2) >> 0x10);
      uVar16 = (uint)*(byte *)((int)*(uint32_t *)((uint)(byte)partyIndex << 2) + 0x2f);
      uVar17 = auStackY_11a[(int)pcVar30 * 2 + uVar16 * 8 + 1];
      uVar25 = auStackY_11a[(int)pcVar30 * 2 + uVar16 * 8];
      puVar28 = (undefined1 *)((int)unaff_DI << 2);
      in_CX = &eStackY_66;
    } while( true );
  case 5:
    puVar1 = (uint *)(&stk_c1dd + (int)unaff_DI);
    uVar16 = *puVar1;
    *puVar1 = *puVar1 - 1;
    if (in_CX == (entity_t *)0x0) {
      in_stack_0000fff5 =
           (in_NT & 1) * '@' | SBORROW2(uVar16,1) * '\b' | (in_IF & 1) * '\x02' | in_TF & 1;
      in_stack_0000fff4 =
           ((int)*puVar1 < 0) * -0x80 | (*puVar1 == 0) * '@' |
           (9 < (bVar44 & 0xf) | in_AF & 1) * '\x10' |
           ((POPCOUNT(*puVar1 & 0xff) & 1U) == 0) * '\x04';
    }
    (&eStackY_66.base.y)[uVar17] = (uint16_t)((char *)0x2410);
    *(char **)(puVar28 + (int)&eStackY_66) = (char *)"Done";
    (&eStackY_66.base.y)[(int)(unaff_DI + 1) * 2] = (uint16_t)((char *)0x2410);
    (&eStackY_66.base.x)[(int)(unaff_DI + 1) * 2] = (uint16_t)(char *)"Summary";
    peVar29 = (entity_t *)(&eStackY_66.base.x + (int)(unaff_DI + 2) * 2);
    (&eStackY_66.base.y)[(int)(unaff_DI + 2) * 2] = (uint16_t)((char *)0x2410);
    (peVar29->base).x = (uint16_t)(char *)"All levels";
    unaff_DI = unaff_DI + 3;
    pcVar30 = (char *)0x0;
    goto L_manage_4d05_2d79_2EE8;
  }
  if ((uVar17 != 0) || ((uint)(*(uint16_t *)((uint8_t *)&(BuildingTypes[0x76]) + 24)) < 0x195d)) {
    uVar16 = (((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
              (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
             (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
    if ((uVar16 < CONCAT11(in_stack_0000fff3,in_stack_0000fff2)) ||
       ((uVar16 <= CONCAT11(in_stack_0000fff3,in_stack_0000fff2) &&
        (((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0] <=
         CONCAT11(in_stack_0000fff1,in_stack_0000fff0))))) {
      unaff_SI = (uint32_t *)
                 ((((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
                   (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                 (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]));
    }
    else {
      unaff_SI = (uint32_t *)CONCAT11(in_stack_0000fff3,in_stack_0000fff2);
    }
    uVar23 = SUB21(unaff_SI,0);
    uVar22 = (undefined1)((uint)unaff_SI >> 8);
    dstSeg = (uint)StshPtrs[0] - (uint)FMXmsHandle;
    uVar17 = ((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) - (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) - (uint)((uint)StshPtrs[0] < (uint)FMXmsHandle)
    ;
    uVar24 = uVar23;
    uVar40 = uVar22;
    uVar25 = dstSeg;
    puVar18 = ovr_mkp(puVar33);
    ems_memmove1((uint16_t)puVar18,dstSeg,uVar25,uVar17,CONCAT11(uVar22,uVar23),
                 CONCAT11(uVar40,uVar24));
    bVar36 = CARRY2((uint)StshPtrs[0],CONCAT11(uVar40,uVar24));
    (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + CONCAT11(uVar40,uVar24);
    (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (int)unaff_SI + bVar36 + (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2));
    uVar16 = uVar17 - CONCAT11(uVar40,uVar24);
    bVar44 = 0;
    in_stack_0000fff2 = 0xcb;
    in_stack_0000fff3 = 0x77;
    puVar18 = LXURSH_at_(unaff_SI,CONCAT22(uVar11,CONCAT11(uVar10,bVar43)),in_stack_0000fffc);
    agnt = (agnt_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(agnt) + 2)),(agnt_t *)((int)puVar18 + (int)(agnt_t *)agnt));
    partyIndex = CONCAT22((int)puVar33 + (bVar44 & 0xf),uVar27);
  }
  uVar27 = (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) + (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)
  ;
  if ((uVar27 <= (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) &&
     ((uVar27 != (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) || ((uint)FMXmsHandle + (uint)FMEmsHandle <= (uint)StshPtrs[0])))
     ) {
    in_stack_0000fff2 = (undefined1)(*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2));
    in_stack_0000fff3 = (undefined1)((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) >> 8);
    uVar10 = (undefined1)(uint)StshPtrs[0];
    uVar24 = (undefined1)((uint)StshPtrs[0] >> 8);
    lseek(StshHandles[0],(ulong)(*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)),(int)unaff_SI);
    uVar16 = CONCAT11(uVar24,uVar10);
  }
  puVar33 = (uint32_t *)CONCAT11(in_stack_0000fff3,in_stack_0000fff2);
  if (uVar16 == 0 && puVar33 == (uint32_t *)0x0) {
    paVar19 = (agnt_t *)((uint)bVar43 - (*(uint16_t *)((uint8_t *)&(agnt) + 2)));
  }
  else {
    uVar40 = SUB41(agnt,0);
    uVar23 = (undefined1)((ulong)agnt >> 8);
    uVar10 = (char)StshHandles[0];
    uVar24 = (char)((uint)StshHandles[0] >> 8);
    while( true ) {
      if ((puVar33 == (uint32_t *)0x0) && (uVar16 == 0)) goto next_iteration;
      if ((puVar33 != (uint32_t *)0x0) || (0xc000 < uVar16)) {
        uVar16 = 0xc000;
      }
      iVar39 = 0x7888;
      uVar22 = uVar10;
      uVar41 = uVar24;
      uVar27 = read(CONCAT11(uVar24,uVar10),
                    (void *)CONCAT13((char)(uVar16 >> 8),
                                     CONCAT12((char)uVar16,CONCAT11(uVar23,uVar40))),(uint)unaff_SI)
      ;
      if (uVar27 != CONCAT11(uVar24,uVar10)) break;
      puVar33 = (uint32_t *)(iVar39 + uVar27);
      uVar10 = 0;
      uVar24 = 0x10;
      ovr_mkp(puVar33);
      uVar16 = CONCAT11(uVar24,uVar10);
      uVar40 = (undefined1)(*(uint16_t *)((uint8_t *)&(partyIndex) + 2));
      uVar23 = (undefined1)((uint)(*(uint16_t *)((uint8_t *)&(partyIndex) + 2)) >> 8);
      bVar36 = CARRY2((uint)StshPtrs[0],uVar27);
      (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + uVar27;
      (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + bVar36;
      uVar10 = uVar22;
      uVar24 = uVar41;
    }
    printf((char *)((long)&BldInstances[0x49].seg + 1));
    ovr_biosReadKey();
next_iteration:
    paVar19 = (agnt_t *)((uint)bVar43 - (*(uint16_t *)((uint8_t *)&(agnt) + 2)));
  }
  return paVar19;
L_attact_3f0b_1082_11EA:
  uVar32 = (uint16_t)((ulong)in_stack_0000ffe2 >> 0x10);
  peVar26 = (entity_t *)in_stack_0000ffe2;
  (peVar26->base).target =
       (byte)((int)(uint)*(byte *)((int)&(peVar26->base).owner +
                                  ((int)(uint)(peVar29->base).faction >> 2)) >>
             (((peVar26->base).faction & 3) << 1)) & 3;
  cVar6 = func_0x0004f32d();
  peVar29 = (entity_t *)in_stack_0000ffe2;
  uVar32 = (uint16_t)((ulong)in_stack_0000ffe2 >> 0x10);
  if (cVar6 == '\0') {
    (in_stack_0000ffe2->base).x =
         (in_stack_0000ffe2->base).x + (int)*(char *)((peVar29->base).target + 0x885);
    puVar2 = &(peVar29->base).y;
    *puVar2 = *puVar2 + (int)*(char *)((peVar29->base).target + 0x889);
    puVar3 = &(peVar29->base).faction;
    *puVar3 = *puVar3 + 0x1;
  }
  else {
    (peVar29->base).faction = 0x0;
    *(undefined1 *)&(peVar29->base).state = 0;
  }
L_attact_3f0b_1082_1477:
  do {
    uVar37 = 0x1000000;
    uVar16 = ovr_alignUp4((((entity_t *)in_stack_0000ffe2)->base).destX,0,0);
    uVar24 = (undefined1)uVar16;
    uVar40 = (undefined1)(uVar16 >> 8);
    uVar16 = ovr_alignUp4((in_stack_0000ffe2->base).x,0,0);
    if (CONCAT11(uVar40,uVar24) == uVar16) {
      uVar32 = (uint16_t)((ulong)in_stack_0000ffe2 >> 0x10);
      peVar29 = (entity_t *)in_stack_0000ffe2;
      if ((peVar29->base).destY == (peVar29->base).y) {
        (peVar29->base).destX = 0;
        (peVar29->base).destY = 0;
        if (*(char *)((int)&(peVar29->base).entity + 3) == -1) {
          bVar44 = 0xff;
        }
        else {
          uVar4 = *(uint32_t *)((uint)*(byte *)((int)&(peVar29->base).entity + 3) << 2);
          bVar44 = *(byte *)((int)uVar4 + 0x89);
        }
        if (bVar44 != 0xff) {
          for (uVar16 = 0; uVar16 < SquareRecCount; uVar16 = uVar16 + 1) {
            uVar27 = ovr_alignUp4(*(int *)(uVar16 * 0x13),0,0);
            uVar24 = (undefined1)uVar27;
            uVar40 = (undefined1)(uVar27 >> 8);
            uVar27 = ovr_alignUp4((in_stack_0000ffe2->base).x,0,0);
            if ((CONCAT11(uVar40,uVar24) == uVar27) &&
               (*(uint16_t *)((uint8_t *)&SquareRecs[uVar16] + 2) == (((entity_t *)in_stack_0000ffe2)->base).y)) {
              func_0x0004f930();
              if (*(uint16_t *)((uint8_t *)&SquareRecs[uVar16] + 2) == GfxRndSeed2) {
                uVar16 = ovr_alignUp4(*(int *)(uVar16 * 0x13),0,0);
                uVar24 = (undefined1)uVar16;
                uVar40 = (undefined1)(uVar16 >> 8);
                uVar16 = ovr_alignUp4(GfxRndSeed,0,0);
                if (CONCAT11(uVar40,uVar24) == uVar16) {
                  (&stk_fff2)[bVar44] = 1;
                }
              }
              break;
            }
          }
        }
      }
    }
    uVar5 = 0x23;
    if (AgntFlag1 != false) {
      uVar32 = (uint16_t)((ulong)in_stack_0000ffe2 >> 0x10);
      if ((((in_stack_0000ffe2->base).x < GfxRndSeed - 2U) ||
          (GfxRndSeed + 1U < (in_stack_0000ffe2->base).x)) ||
         ((((entity_t *)in_stack_0000ffe2)->base).y != GfxRndSeed2)) {
        bVar36 = false;
      }
      else {
        bVar36 = true;
      }
      if (((uVar11 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uVar11)) ||
         (GfxRndSeed2 != CONCAT11(uVar10,bVar43))) {
        bVar9 = false;
      }
      else {
        bVar9 = true;
      }
      uVar37 = uVar37 & 0xff000000;
      if (bVar9 || bVar36) {
        if (bVar9) {
          if (bVar36) {
            uVar10 = manage_usesLitoa103();
            for (uVar37 = CONCAT31((int3)(uVar37 >> 8),uVar10); uVar5 = 0x23, (char)uVar37 != '\0';
                uVar37 = CONCAT31((int3)(uVar37 >> 8),(char)uVar37 + -1)) {
              uVar5 = 0x23;
              pcVar30 = ovr_ovc15_textArena((int)unaff_DI,0,0);
              if (((uint)pcVar30 & 0xff) == 0) break;
            }
          }
          else {
            uVar37 = CONCAT31((int3)(uVar37 >> 8),
                              (char)((ulong)((((entity_t *)in_stack_0000ffe2)->base).animFrame + 0xf
                                            ) / 0x10));
            while (cVar6 = (char)uVar37, uVar37 = CONCAT31((int3)(uVar37 >> 8),cVar6 + -1),
                  cVar6 != '\0') {
              uVar5 = 0x22;
              ovr_agnt_usesAgntCount6(Entities + (int)unaff_DI,0);
            }
          }
        }
        else {
          ovr_ovc15_clearVisited();
          uVar37 = CONCAT31((int3)(uVar37 >> 8),
                            (char)((ulong)((((entity_t *)in_stack_0000ffe2)->base).animFrame + 0xf)
                                  / 0x10));
          while( true ) {
            uVar5 = 0x23;
            cVar6 = (char)uVar37;
            uVar37 = CONCAT31((int3)(uVar37 >> 8),cVar6 + -1);
            if (cVar6 == '\0') break;
            ovr_ovc15_textArena((int)unaff_DI,0,0);
          }
        }
      }
    }
    do {
      uVar38 = (uint8_t)(uVar37 >> 0x18);
      unaff_DI = unaff_DI + 1;
      if (EntityCount <= unaff_DI) {
        GGameState = 0x3c;
        uVar35 = uVar5;
        if (DebugVerbose != false) {
          uVar35 = 0x10;
          uVar38 = uVar5;
          printf("%d %d %d  \r");
        }
        func_0x0004fcda();
        GGameState = 0x3d;
        if (DebugVerbose != false) {
          uVar38 = uVar35;
          printf("%d %d %d  \r");
        }
        ovr_OVC23_55fe_29a2_entry();
        GGameState = 0xc;
        if (DebugVerbose != false) {
          uVar38 = 0x23;
          printf("%d %d %d  \r");
        }
        ovr_ovc24_removeOtherEntities(&stk_ffe9);
        GGameState = 0x1f;
        if (uVar38 != 0x0) {
          ovr_constr_usesBlitRect();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (uVar16 = 0; (int)uVar16 < 5; uVar16 = uVar16 + 1) {
          if ((&stk_fff2)[uVar16] != '\0') {
            ovr_ovc41_usesMiceBlitRect(uVar16);
          }
        }
        GGameState = 0xd;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        ovr_ovc24_checkStrongholds();
        GGameState = 0xe;
        mapDirty = 1;
        return (agnt_t *)0x2410;
      }
      uVar32 = (uint16_t)((ulong)Entities >> 0x10);
      in_stack_0000ffe2 = (entity_t *)CONCAT22(uVar32,Entities + (int)unaff_DI);
      uVar16 = ovr_alignUp4(Entities[(int)unaff_DI].base.destX,0,0);
      uVar10 = (undefined1)uVar16;
      uVar24 = (undefined1)(uVar16 >> 8);
      uVar5 = 0x23;
      uVar16 = ovr_alignUp4((in_stack_0000ffe2->base).x,0,0);
      if ((CONCAT11(uVar24,uVar10) == uVar16) &&
         (uVar32 = (uint16_t)((ulong)in_stack_0000ffe2 >> 0x10),
         (((entity_t *)in_stack_0000ffe2)->base).destY == (((entity_t *)in_stack_0000ffe2)->base).y)
         ) {
        uVar37 = 0x23790204;
        manage_usesCurSfxType32();
      }
      uVar34 = (uint16_t)((ulong)in_stack_0000ffe2 >> 0x10);
      peVar29 = (entity_t *)in_stack_0000ffe2;
    } while (((peVar29->base).destX == 0 && (peVar29->base).destY == 0) ||
            (*(char *)((int)&(peVar29->base).entity + 1) != '\0'));
    uVar11 = (in_stack_0000ffe2->base).x;
    uVar25 = (peVar29->base).y;
    bVar44 = (byte)uVar25;
    uVar24 = (undefined1)(uVar25 >> 8);
    bVar43 = bVar44;
    uVar10 = uVar24;
    if ((peVar29->base).faction < (byte)(peVar29->base).state) goto L_attact_3f0b_1082_11EA;
    ovr_ovc07_signum((peVar29->base).destX - (in_stack_0000ffe2->base).x);
    uVar32 = (uint16_t)((ulong)in_stack_0000ffe2 >> 0x10);
    cVar6 = 'g';
    uVar23 = 3;
    uVar25 = ovr_ovc07_signum((((entity_t *)in_stack_0000ffe2)->base).destY -
                              (((entity_t *)in_stack_0000ffe2)->base).y);
    bVar7 = (byte)uVar25;
    uVar40 = (undefined1)(uVar25 >> 8);
    if (CONCAT11(uVar23,cVar6) == 0) {
L_attact_3f0b_1082_130A:
      bVar43 = bVar44;
      uVar10 = uVar24;
      if (CONCAT11(uVar40,bVar7) != 0) {
        uVar23 = (undefined1)(uVar25 >> 8);
        cVar6 = bVar7 + 1;
        bVar7 = sub_OVC21_manage_c_23C2();
        uVar25 = (uint16_t)bVar7;
        if (uVar25 == 0) {
          uVar32 = (uint16_t)((ulong)in_stack_0000ffe2 >> 0x10);
          puVar2 = &(((entity_t *)in_stack_0000ffe2)->base).y;
          *puVar2 = *puVar2 + CONCAT11(uVar24,bVar44);
          (((entity_t *)in_stack_0000ffe2)->base).target = bVar44 + 1;
          goto L_attact_3f0b_1082_1477;
        }
      }
      if (CONCAT11(uVar23,cVar6) != 0) {
        uVar24 = (undefined1)(uVar25 >> 8);
        cVar6 = '\x02' - cVar6;
        cVar8 = sub_OVC21_manage_c_23C2();
        if (cVar8 == '\0') {
          (in_stack_0000ffe2->base).x = (in_stack_0000ffe2->base).x + CONCAT11(uVar24,cVar6);
          (((entity_t *)in_stack_0000ffe2)->base).target = 0x2 - cVar6;
          goto L_attact_3f0b_1082_1477;
        }
      }
      uVar16 = ovr_ovc26_usesStExit((int)unaff_DI);
      if ((char)uVar16 == '\0') {
        uVar16 = ovr_ovc26_usesRandBelow((int)unaff_DI);
        if (((uVar16 & 0xff) == 0) &&
           (*(char *)((int)(char **)GMenuStrings +
                     (uint)(((entity_t *)in_stack_0000ffe2)->base).gindex * 0x95 + 0x1f) == '\0')) {
          manage_usesCurSfxType32();
        }
      }
      else {
        uVar32 = (uint16_t)((ulong)in_stack_0000ffe2 >> 0x10);
        peVar29 = (entity_t *)in_stack_0000ffe2;
        (peVar29->base).target =
             (byte)((int)(uint)*(byte *)((int)&(peVar29->base).owner +
                                        ((int)(uint)(peVar29->base).faction >> 2)) >>
                   (((peVar29->base).faction & 3) << 1)) & 3;
        cVar6 = func_0x0004f32d();
        if (cVar6 == '\0') {
          uVar32 = (uint16_t)((ulong)in_stack_0000ffe2 >> 0x10);
          peVar29 = (entity_t *)in_stack_0000ffe2;
          (in_stack_0000ffe2->base).x =
               (in_stack_0000ffe2->base).x + (int)*(char *)((peVar29->base).target + 0x885);
          puVar2 = &(peVar29->base).y;
          *puVar2 = *puVar2 + (int)*(char *)((peVar29->base).target + 0x889);
          puVar3 = &(peVar29->base).faction;
          *puVar3 = *puVar3 + 0x1;
        }
      }
      goto L_attact_3f0b_1082_1477;
    }
    cVar6 = 'z';
    uVar23 = 3;
    uVar25 = ovr_randBelow(2,0);
    uVar22 = (undefined1)(uVar25 >> 8);
    if ((char)uVar25 == '\0') goto L_attact_3f0b_1082_130A;
    cVar6 = '\x02' - cVar6;
    bVar43 = bVar44;
    uVar10 = uVar24;
    bVar7 = sub_OVC21_manage_c_23C2();
    uVar25 = (uint16_t)bVar7;
    bVar7 = bVar44;
    uVar40 = uVar24;
    uVar23 = uVar22;
    bVar44 = bVar43;
    uVar24 = uVar10;
    if (uVar25 != 0) goto L_attact_3f0b_1082_130A;
    (in_stack_0000ffe2->base).x = (in_stack_0000ffe2->base).x + CONCAT11(uVar22,cVar6);
    (((entity_t *)in_stack_0000ffe2)->base).target = 0x2 - cVar6;
  } while( true );
}


/* 4207:288b */

/* [R4] calls ovr_alignUp4 */

bool __cdecl16far ovc15_usesAlignUp42(void)

{
  uint uVar1;
  uint uVar2;
  byte bStack_3;
  
  uVar2 = 0;
  uVar1 = ovr_alignUp4(GfxRndSeed,0,0);
  for (bStack_3 = 0; bStack_3 < 4; bStack_3 = bStack_3 + 1) {
    uVar2 = uVar2 | ((short (*) [60] [148])GMapFlags)[-1][GfxRndSeed2 + 0x3b]
                    [uVar1 + bStack_3 + 0x92] & 0x3000U;
  }
  return uVar2 == 0x3000;
}



/* 4207:28fa */

/* Sets CrossBlitX/CrossBlitY to the selected agent's screen position (y - 0x10). */

void __cdecl16far ovc15_positionCrosshair(void)

{
  if (SelectedAgent < AgntCount) {
    CrossBlitX = Agnts[SelectedAgent].screenX;
    CrossBlitY = Agnts[SelectedAgent].screenY + -0x10;
  }
  return;
}



/* 4207:2961 */

/* Selects the agent with the smallest screen position and stores it in SelectedAgent. */

bool __cdecl16far ovc15_selectLeftmostAgent(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char cStack_3;
  
  cStack_3 = -1;
  uVar2 = 0x7fff;
  uVar3 = 0x7fff;
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    if ((Agnts[iVar1].screenX < uVar2) ||
       ((Agnts[iVar1].screenX == uVar2 && (Agnts[iVar1].screenY < uVar3)))) {
      cStack_3 = (char)iVar1;
      uVar2 = Agnts[iVar1].screenX;
      uVar3 = Agnts[iVar1].screenY;
    }
  }
  if (cStack_3 != -1) {
    SelectedAgent = cStack_3;
  }
  return cStack_3 != -1;
}



/* 4207:2a0e */

/* Selects the agent with the largest screen position and stores it in SelectedAgent. */

bool __cdecl16far ovc15_selectRightmostAgent(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char cStack_3;
  
  cStack_3 = -1;
  uVar2 = 0;
  uVar3 = 0;
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    if ((uVar2 < Agnts[iVar1].screenX) ||
       ((Agnts[iVar1].screenX == uVar2 && (uVar3 < Agnts[iVar1].screenY)))) {
      cStack_3 = (char)iVar1;
      uVar2 = Agnts[iVar1].screenX;
      uVar3 = Agnts[iVar1].screenY;
    }
  }
  if (cStack_3 != -1) {
    SelectedAgent = cStack_3;
  }
  return cStack_3 != -1;
}



/* 4207:2ab9 */

/* [R2] string "arena" */

bool __cdecl16far ovc15_textArena4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bStack_3;
  
  bStack_3 = 0xff;
  uVar2 = 0x7fff;
  uVar3 = 0x7fff;
  for (uVar1 = 0; (int)uVar1 < (int)(uint)AgntCount; uVar1 = uVar1 + 1) {
    if (((SelectedAgent != uVar1) &&
        ((Agnts[SelectedAgent].screenX < Agnts[uVar1].screenX ||
         ((Agnts[SelectedAgent].screenX == Agnts[uVar1].screenX &&
          (Agnts[SelectedAgent].screenY < Agnts[uVar1].screenY)))))) &&
       ((Agnts[uVar1].screenX < uVar2 ||
        ((Agnts[uVar1].screenX == uVar2 && (Agnts[uVar1].screenY < uVar3)))))) {
      bStack_3 = (byte)uVar1;
      uVar2 = Agnts[uVar1].screenX;
      uVar3 = Agnts[uVar1].screenY;
    }
  }
  if (bStack_3 != 0xff) {
    SelectedAgent = bStack_3;
  }
  return bStack_3 != 0xff;
}



/* 4207:2c18 */

/* [R2] string "arena" */

bool __cdecl16far ovc15_textArena5(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bStack_3;
  
  bStack_3 = 0xff;
  uVar2 = 0;
  uVar3 = 0;
  for (uVar1 = 0; (int)uVar1 < (int)(uint)AgntCount; uVar1 = uVar1 + 1) {
    if (((SelectedAgent != uVar1) &&
        ((Agnts[uVar1].screenX < Agnts[SelectedAgent].screenX ||
         ((Agnts[SelectedAgent].screenX == Agnts[uVar1].screenX &&
          (Agnts[uVar1].screenY < Agnts[SelectedAgent].screenY)))))) &&
       ((uVar2 < Agnts[uVar1].screenX ||
        ((Agnts[uVar1].screenX == uVar2 && (uVar3 < Agnts[uVar1].screenY)))))) {
      bStack_3 = (byte)uVar1;
      uVar2 = Agnts[uVar1].screenX;
      uVar3 = Agnts[uVar1].screenY;
    }
  }
  if (bStack_3 != 0xff) {
    SelectedAgent = bStack_3;
  }
  return bStack_3 != 0xff;
}



/* 4207:2d75 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc15_usesRandBelow2(void)

{
  uint16_t uVar1;
  uint uVar2;
  int iVar3;
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
  for (bStack_7 = 0; bStack_7 < GLeaderCount; bStack_7 = bStack_7 + 1) {
    if ((*(char *)((int)*(uint32_t *)((uint)bStack_7 << 2) + 0x3f) == '\0') &&
       (uStack_4 < ((char_sheet_t *)(((uint)bStack_7 << 2)))->unitCount)) {
      bStack_8 = bStack_7;
      uStack_4 = ((char_sheet_t *)(((uint)bStack_7 << 2)))->unitCount;
    }
    if ((*(char *)((int)*(uint32_t *)((uint)bStack_7 << 2) + 0x3f) != '\0') &&
       (uStack_6 < ((char_sheet_t *)(((uint)bStack_7 << 2)))->unitCount)) {
      bStack_9 = bStack_7;
      uStack_6 = ((char_sheet_t *)(((uint)bStack_7 << 2)))->unitCount;
    }
  }
  if ((bStack_9 != 0xff) && (0xe < uStack_6)) {
    uVar1 = ovr_randBelow(EntityCount,0);
    uVar4 = uVar1 & 0xff;
    do {
      uVar5 = (uint16_t)((ulong)Entities >> 0x10);
      iVar3 = (int)Entities;
      if ((AGNT_FIELD(&((entity_t *)Entities)[uVar4], base.entity, 3) == bStack_9) &&
         (uVar2 = ovr_ovc23_isCursorAt
                            (*(uint16_t *)((entity_t *)iVar3 + uVar4),((entity_t *)iVar3)[uVar4].base.y,0)
         , (uVar2 & 0xff) == 0)) {
        return uVar4;
      }
      uVar4 = uVar4 + 1;
      if (EntityCount <= uVar4) {
        uVar4 = 0;
      }
    } while (uVar4 != (uVar1 & 0xff));
  }
  if ((bStack_8 != 0xff) && (0x1d < uStack_4)) {
    uVar1 = ovr_randBelow(EntityCount,0);
    uVar4 = uVar1 & 0xff;
    do {
      uVar5 = (uint16_t)((ulong)Entities >> 0x10);
      iVar3 = (int)Entities;
      if (((AGNT_FIELD(&((entity_t *)Entities)[uVar4], base.entity, 3) == bStack_8) &&
          (uVar2 = ovr_ovc23_isCursorAt
                             (*(uint16_t *)((entity_t *)iVar3 + uVar4),((entity_t *)iVar3)[uVar4].base.y,0), (uVar2 & 0xff) == 0)) &&
         ((*((uint8_t far *)&((entity_t *)Entities)[uVar4].base.flags32 + 1) & 3) == 0)) {
        return uVar4;
      }
      uVar4 = uVar4 + 1;
      if (EntityCount <= uVar4) {
        uVar4 = 0;
      }
    } while (uVar4 != (uVar1 & 0xff));
  }
  uVar1 = ovr_randBelow(EntityCount,0);
  return uVar1 & 0xff;
}


