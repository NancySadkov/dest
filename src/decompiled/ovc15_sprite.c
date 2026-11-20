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
  uint16_t unaff_SI;
  uint16_t i;
  uint16_t unaff_DI;
  uint16_t count;
  far_t dst;
  frm_t *frm;
  int in_stack_00000004;
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
    ovr_stExit(unaff_DI,0x36);
  }
  dst.seg = (uint16_t)((spr_t *)StshSprites + StshSprIndex);
  StshSprIndex = StshSprIndex + 1;
  dst.ofs = (uint16_t)ovr_mkp((*(uint16_t *)((uint8_t *)&(StshSprites) + 2)),unaff_DI,unaff_SI,dst.seg);
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
      ovr_stExit(unaff_DI,0x33);
    }
    p_ow = 0;
    j = 0;
    while( true ) {
      (*(uint16_t *)((uint8_t *)&(frm) + 2)) = (undefined2)((ulong)((long)(int)i * 0x1e) >> 0x10);
      if (*(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + (int)((long)(int)i * 0x1e) + 0x1b) <= j) break;
      (*(uint16_t *)((uint8_t *)&(frm))) = (frm_t *)ovr_stshRleSub((far_t *)(uint8_t *)src,(uint8_t *)sx,sy,ex,ey,0x15,
                                          unaff_DI,in_stack_00000004);
      pfStack_20 = (frm_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(frm) + 2)),(frm_t *)frm);
      ((frm_t *)frm)->type2 = 2;
      ((frm_t *)frm)->x = *(int16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0xb);
      ((frm_t *)frm)->y = *(int16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0xd);
      *(undefined2 *)((int)prev_next + 2) = (*(uint16_t *)((uint8_t *)&(frm) + 2));
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
              ovr_stExit(unaff_DI,9);
            }
            if (*(char *)(in_stack_00000004 + xx + row) == -2) {
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
          xx = sx;
          while (*(char *)(in_stack_00000004 + xx + row) != -2) {
            if (ex + row < xx) {
                    /* WARNING: Subroutine does not return */
              ovr_stExit(unaff_DI,9);
            }
            xx = xx + 1;
          }
          ((frm_t *)frm)->ow = (char)exx - (char)xx;
          exx = xx;
        }
      }
      pfStack_20->type4 = 4;
      *(undefined2 *)((int)&((frm_t *)frm)->next + 2) = 0;
      *(undefined2 *)&((frm_t *)frm)->next = 0;
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
stshSprite(far_t *__return_storage_ptr__,int16_t file_id,anm_t *anms,uint16_t nanims,bool grab)

{
  far_t pixels;
  far_t handle;
  far_t handle_00;
  uint16_t ofs;
  uint16_t seg;
  undefined2 unaff_SI;
  spr_t *spr;
  stg_tmp_t *fVar6;
  undefined1 uVar1;
  undefined1 uVar2;
  uint8_t dcolor;
  undefined1 uVar3;
  
  dcolor = (uint8_t)unaff_SI;
  uVar3 = (undefined1)((uint)unaff_SI >> 8);
  uVar1 = SUB21(anms,0);
  uVar2 = (undefined1)((uint)anms >> 8);
  if ((char)nanims == '\0') {
    (*(uint16_t *)((uint8_t *)&(spr))) = ovr_stshSpriteStub((anm_t *)CONCAT13(uVar2,CONCAT12(uVar1,file_id)),
                                   (uint16_t)__return_storage_ptr__);
  }
  else {
    (*(uint16_t *)((uint8_t *)&(fVar6))) = ovr_grabLbm();
    pixels.seg = 0xff;
    pixels.ofs = (((stg_tmp_t *)fVar6)->aptr).seg;
    seg = (*(uint16_t *)((uint8_t *)&(fVar6) + 2));
    ovr_grabRemap(pixels,0x0,dcolor,(&((stg_tmp_t *)fVar6)->aptr)->ofs,0);
    ofs = (uint16_t)
          stshRleAnims((uint8_t *)
                       CONCAT22(__return_storage_ptr__,(uint8_t *)(((stg_tmp_t *)fVar6)->aptr).seg),
                       (anm_t *)CONCAT13(uVar2,CONCAT12(uVar1,file_id)),CONCAT11(uVar3,dcolor));
    (*(uint8_t *)((uint8_t *)&(handle.seg))) = dcolor;
    handle.ofs = (((stg_tmp_t *)fVar6)->bptr).seg;
    (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uVar3;
    ovr_stshFree(handle,(&((stg_tmp_t *)fVar6)->bptr)->ofs);
    (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = dcolor;
    handle_00.ofs = (*(uint16_t *)((uint8_t *)&(fVar6) + 2));
    (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = uVar3;
    ovr_stshFree(handle_00,(stg_tmp_t *)fVar6);
    stshStoreSprite((spr_t *)CONCAT22(__return_storage_ptr__,seg),
                    (anm_t *)CONCAT13(uVar2,CONCAT12(uVar1,file_id)),CONCAT11(uVar3,dcolor));
    (*(uint16_t *)((uint8_t *)&(spr))) = (spr_t *)ofs;
  }
  return (far_t *)(spr_t *)spr;
}



/* 4207:0462 */

void __cdecl16far allocSprSeqs(void...)

{
  undefined2 in_DX;
  uint unaff_BP;
  
  (*(uint16_t *)((uint8_t *)&(StshSprites))) = ovr_stshAlloc((ulong)unaff_BP << 0x10,0x3650);
  (*(uint16_t *)((uint8_t *)&(StshSprites) + 2)) = in_DX;
  return;
}



/* 4207:047b */

void __cdecl16far stshInitSprites(bool grab,...)

{
  undefined2 in_AX;
  far_t *pfVar1;
  stg_tmp_t *psVar2;
  int iVar3;
  stg_tmp_t *psVar4;
  cte_t *pcVar5;
  uint32_t *puVar6;
  int iVar7;
  uint16_t in_DX;
  undefined2 uVar8;
  undefined2 uVar9;
  stg_tmp_t *__return_storage_ptr__;
  int16_t unaff_SI;
  uint16_t i;
  undefined2 unaff_DI;
  int iVar10;
  uint16_t j;
  char in_stack_00000004;
  stg_tmp_t *psVar11;
  ulong sz;
  int16_t iVar12;
  
  StshSprIndex = 0;
  psVar2 = (stg_tmp_t *)CONCAT11((char)((uint)in_AX >> 8),in_stack_00000004);
  psVar11 = (stg_tmp_t *)CONCAT22(unaff_DI,psVar2);
  pfVar1 = stshSprite((far_t *)0x0,6493,(anm_t *)((byte *)__C0_ASM_CopyRight + 5),(uint16_t)psVar2,
                      SUB21(unaff_DI,0));
  SprProjectiles.ofs = (uint16_t)pfVar1;
  SprProjectiles.seg = in_DX;
  for (i = 0; (int)i < 0x2a; i = i + 1) {
    uVar9 = (undefined2)((ulong)psVar11 >> 0x10);
    uVar8 = 0x195d;
    pfVar1 = stshSprite((far_t *)*(undefined2 *)((int)&AgntGs[0].anms + i * 0x95),
                        *(int16_t *)((int)&AgntGs[0].anms + 2 + i * 0x95),
                        (anm_t *)(uint)*(byte *)((int)&AgntGs[0].nanims + i * 0x95),
                        CONCAT11((char)((uint)pfVar1 >> 8),in_stack_00000004),
                        SUB41((ulong)psVar11 >> 0x10,0));
    *(undefined2 *)((int)AgntGs[0].sprs + 2 + i * 0x95) = uVar8;
    *(undefined2 *)((int)AgntGs[0].sprs + i * 0x95) = pfVar1;
    if (*(int *)((int)AgntGs[0].sprfls + 2 + i * 0x95) == 0) {
      uVar8 = *(undefined2 *)((int)AgntGs[0].sprs + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].sprs + 6 + i * 0x95) =
           *(undefined2 *)((int)AgntGs[0].sprs + 2 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].sprs + 4 + i * 0x95) = uVar8;
    }
    else {
      uVar8 = 0x195d;
      pfVar1 = stshSprite((far_t *)*(undefined2 *)((int)&AgntGs[0].anms + i * 0x95),
                          *(int16_t *)((int)&AgntGs[0].anms + 2 + i * 0x95),
                          (anm_t *)(uint)*(byte *)((int)&AgntGs[0].nanims + i * 0x95),
                          CONCAT11((char)(i * 0x95 >> 8),in_stack_00000004),SUB21(uVar9,0));
      *(undefined2 *)((int)AgntGs[0].sprs + 6 + i * 0x95) = uVar8;
      *(undefined2 *)((int)AgntGs[0].sprs + 4 + i * 0x95) = pfVar1;
    }
    if (*(int *)((int)AgntGs[0].sprfls + 4 + i * 0x95) == 0) {
      psVar2 = (stg_tmp_t *)*(undefined2 *)((int)AgntGs[0].sprs + 6 + i * 0x95);
      uVar8 = *(undefined2 *)((int)AgntGs[0].sprs + 4 + i * 0x95);
      psVar11 = (stg_tmp_t *)CONCAT22(uVar9,psVar2);
      *(undefined2 *)((int)AgntGs[0].sprs + 10 + i * 0x95) = psVar2;
      *(undefined2 *)((int)AgntGs[0].sprs + 8 + i * 0x95) = uVar8;
    }
    else {
      uVar8 = 0x195d;
      psVar2 = (stg_tmp_t *)
               stshSprite((far_t *)*(undefined2 *)((int)&AgntGs[0].anms + i * 0x95),
                          *(int16_t *)((int)&AgntGs[0].anms + 2 + i * 0x95),
                          (anm_t *)(uint)*(byte *)((int)&AgntGs[0].nanims + i * 0x95),
                          CONCAT11((char)(i * 0x95 >> 8),in_stack_00000004),SUB21(uVar9,0));
      psVar11 = (stg_tmp_t *)CONCAT22(uVar9,psVar2);
      *(undefined2 *)((int)AgntGs[0].sprs + 10 + i * 0x95) = uVar8;
      *(undefined2 *)((int)AgntGs[0].sprs + 8 + i * 0x95) = psVar2;
    }
    for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {
      iVar3 = i * 0x95 + iVar10 * 2;
      uVar8 = (undefined2)((ulong)psVar11 >> 0x10);
      if (*(int *)((int)AgntGs[0].sprfls + 6 + iVar3) == 0) {
        iVar3 = i * 0x95 + iVar10 * 4;
        psVar2 = (stg_tmp_t *)*(undefined2 *)((int)AgntGs[0].sprs + 2 + iVar3);
        uVar9 = *(undefined2 *)((int)AgntGs[0].sprs + iVar3);
        psVar11 = (stg_tmp_t *)CONCAT22(uVar8,psVar2);
        iVar3 = i * 0x95 + iVar10 * 4;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar3) = psVar2;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar3) = uVar9;
      }
      else {
        uVar9 = 0x195d;
        psVar2 = (stg_tmp_t *)
                 stshSprite((far_t *)*(undefined2 *)((int)&AgntGs[0].anms + i * 0x95),
                            *(int16_t *)((int)&AgntGs[0].anms + 2 + i * 0x95),
                            (anm_t *)(uint)*(byte *)((int)&AgntGs[0].nanims + i * 0x95),
                            CONCAT11((char)((uint)iVar3 >> 8),in_stack_00000004),
                            SUB41((ulong)psVar11 >> 0x10,0));
        psVar11 = (stg_tmp_t *)CONCAT22(uVar8,psVar2);
        iVar3 = i * 0x95 + iVar10 * 4;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar3) = uVar9;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar3) = psVar2;
      }
    }
    for (j = 0; iVar12 = (int16_t)((ulong)psVar11 >> 0x10), (int)j < 6; j = j + 1) {
      uVar8 = 0x195d;
      if (*(int *)((int)AgntGs[0].prtfls + i * 0x95 + j * 2) != 0) {
        if (in_stack_00000004 == '\0') {
          pfVar1 = ovr_stshAllocStub();
          iVar10 = i * 0x95 + j * 4;
          uVar9 = 0x195d;
          *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar10) = uVar8;
          *(undefined2 *)((int)AgntGs[0].prts + iVar10) = pfVar1;
          psVar2 = (stg_tmp_t *)ovr_stshAllocStub();
          psVar11 = (stg_tmp_t *)CONCAT22(iVar12,psVar2);
          iVar10 = i * 0x95 + j * 4;
          *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar10) = uVar9;
          *(undefined2 *)((int)AgntGs[0].prtpals + iVar10) = psVar2;
        }
        else {
          __return_storage_ptr__ = (stg_tmp_t *)((int)&BuildingTypes[0x9f].income + 1);
          psVar4 = ovr_grabLbm(0,0,iVar12,*(undefined2 *)((int)AgntGs[0].prtfls + i * 0x95 + j * 2))
          ;
          psVar11 = (stg_tmp_t *)CONCAT22(iVar12,__return_storage_ptr__);
          psVar2 = __return_storage_ptr__;
          ovr_stshUniqueColorsRemap(psVar11,psVar4);
          iVar12 = (int16_t)((ulong)psVar11 >> 0x10);
          pfVar1 = ovr_stshRleType2((far_t *)(psVar4->aptr).seg,far_from_u32((uint32_t)(0x0)),114,103,0,0,iVar12,
                                    unaff_SI,(&psVar4->aptr)->ofs);
          psVar11 = (stg_tmp_t *)CONCAT22(iVar12,psVar2);
          pcVar5 = ovr_stshStoreFile((uint8_t *)psVar11,pfVar1);
          iVar10 = i * 0x95 + j * 4;
          uVar8 = 0x195d;
          *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar10) = psVar2;
          *(undefined2 *)((int)AgntGs[0].prts + iVar10) = pcVar5;
          sz = (ulong)psVar11 & 0xffff0000;
          puVar6 = ovr_stshWrite((uint32_t *)__return_storage_ptr__,
                                 (uint8_t *)((char *)"Error 4 %d \r" + 0xb),sz,psVar4);
          iVar10 = i * 0x95 + j * 4;
          *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar10) = uVar8;
          *(undefined2 *)((int)AgntGs[0].prtpals + iVar10) = puVar6;
          psVar11 = (stg_tmp_t *)CONCAT22((int)(sz >> 0x10),__return_storage_ptr__);
          ovr_stgFreeTmp(psVar11,psVar4);
        }
      }
    }
    pfVar1 = (far_t *)(*(uint *)((int)AgntGs[0].prts + 4 + i * 0x95) |
                      *(uint *)((int)AgntGs[0].prts + 6 + i * 0x95));
    if ((pfVar1 == (far_t *)0x0) &&
       (pfVar1 = (far_t *)0x0,
       *(int *)((int)AgntGs[0].prts + i * 0x95) != 0 ||
       *(int *)((int)AgntGs[0].prts + 2 + i * 0x95) != 0)) {
      uVar8 = *(undefined2 *)((int)AgntGs[0].prts + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].prts + 6 + i * 0x95) =
           *(undefined2 *)((int)AgntGs[0].prts + 2 + i * 0x95);
      *(undefined2 *)((int)AgntGs[0].prts + 4 + i * 0x95) = uVar8;
      psVar2 = (stg_tmp_t *)*(undefined2 *)((int)AgntGs[0].prtpals + 2 + i * 0x95);
      pfVar1 = (far_t *)*(undefined2 *)((int)AgntGs[0].prtpals + i * 0x95);
      psVar11 = (stg_tmp_t *)CONCAT22(iVar12,psVar2);
      *(undefined2 *)((int)AgntGs[0].prtpals + 6 + i * 0x95) = psVar2;
      *(undefined2 *)((int)AgntGs[0].prtpals + 4 + i * 0x95) = pfVar1;
    }
    for (iVar10 = 2; iVar10 < 6; iVar10 = iVar10 + 2) {
      iVar3 = i * 0x95 + iVar10 * 4;
      if ((*(int *)((int)AgntGs[0].prts + 4 + iVar3) == 0 &&
           *(int *)((int)AgntGs[0].prts + 6 + iVar3) == 0) &&
         (iVar3 = i * 0x95 + iVar10 * 4,
         *(int *)((int)AgntGs[0].prtfls + 8 + iVar3) != 0 ||
         *(int *)((int)AgntGs[0].prtfls + 10 + iVar3) != 0)) {
        iVar3 = i * 0x95 + iVar10 * 4;
        uVar8 = *(undefined2 *)((int)AgntGs[0].prtfls + 8 + iVar3);
        iVar7 = i * 0x95 + iVar10 * 4;
        *(undefined2 *)((int)AgntGs[0].prts + 6 + iVar7) =
             *(undefined2 *)((int)AgntGs[0].prtfls + 10 + iVar3);
        *(undefined2 *)((int)AgntGs[0].prts + 4 + iVar7) = uVar8;
        iVar3 = i * 0x95 + iVar10 * 4;
        psVar2 = (stg_tmp_t *)*(undefined2 *)((int)AgntGs[0].prts + 0x16 + iVar3);
        uVar8 = *(undefined2 *)((int)AgntGs[0].prts + 0x14 + iVar3);
        psVar11 = (stg_tmp_t *)CONCAT22((int)((ulong)psVar11 >> 0x10),psVar2);
        iVar3 = i * 0x95 + iVar10 * 4;
        *(undefined2 *)((int)AgntGs[0].prtpals + 6 + iVar3) = psVar2;
        *(undefined2 *)((int)AgntGs[0].prtpals + 4 + iVar3) = uVar8;
      }
      iVar3 = i * 0x95 + iVar10 * 4;
      pfVar1 = (far_t *)(*(uint *)((int)AgntGs[0].prts + iVar3) |
                        *(uint *)((int)AgntGs[0].prts + 2 + iVar3));
      if (pfVar1 == (far_t *)0x0) {
        iVar3 = i * 0x95 + iVar10 * 4;
        if (*(int *)((int)AgntGs[0].prtfls + 4 + iVar3) == 0 &&
            *(int *)((int)AgntGs[0].prtfls + 6 + iVar3) == 0) {
          pfVar1 = (far_t *)0x0;
        }
        else {
          iVar3 = i * 0x95 + iVar10 * 4;
          uVar8 = *(undefined2 *)((int)AgntGs[0].prtfls + 4 + iVar3);
          iVar7 = i * 0x95 + iVar10 * 4;
          *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar7) =
               *(undefined2 *)((int)AgntGs[0].prtfls + 6 + iVar3);
          *(undefined2 *)((int)AgntGs[0].prts + iVar7) = uVar8;
          iVar3 = i * 0x95 + iVar10 * 4;
          psVar2 = (stg_tmp_t *)*(undefined2 *)((int)AgntGs[0].prts + 0x12 + iVar3);
          pfVar1 = (far_t *)*(undefined2 *)((int)AgntGs[0].prts + 0x10 + iVar3);
          psVar11 = (stg_tmp_t *)CONCAT22((int)((ulong)psVar11 >> 0x10),psVar2);
          iVar3 = i * 0x95 + iVar10 * 4;
          *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar3) = psVar2;
          *(undefined2 *)((int)AgntGs[0].prtpals + iVar3) = pfVar1;
        }
      }
    }
  }
  return;
}



/* 4207:0b05 */

void __cdecl16far agnt_clear(void...)

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

void __cdecl16far ovc15_fillGridColumn(uint vramOfs,...)

{
  uint uVar1;
  uint in_stack_00000004;
  
  if (in_stack_00000004 >> 1 < 0x69) {
    for (uVar1 = 0; uVar1 < 10; uVar1 = uVar1 + 1) {
      *(undefined1 *)(uVar1 * 0x69 + (in_stack_00000004 >> 1) + 0x8fa) = 0xff;
    }
  }
  return;
}



/* 4207:0b88 */

/* Clears the visited byte (agnt_t+0x2d) on every agent. */

void __cdecl16far ovc15_clearVisited(void...)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    *(undefined1 *)(iVar1 * 0x34 + 0x2d) = 0;
  }
  return;
}



/* 4207:0bb7 */

/* [R6] touches agntIndex, EntityCount */

void __cdecl16far ovc15_usesAgntIndex(void...)

{
  uint uVar1;
  entity_t *peVar2;
  int iVar3;
  int unaff_DI;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  uint8_t agentIndices;
  uint uStack_a;
  uint uStack_8;
  int iStack_6;
  uint uStack_4;
  
  ovc15_clearVisited();
  iStack_6 = 0;
  for (uStack_4 = 0; uStack_4 < EntityCount; uStack_4 = uStack_4 + 1) {
    uVar5 = (undefined2)((ulong)Entities >> 0x10);
    peVar2 = (entity_t *)Entities;
    if (((GfxRndSeed - 2U <= ((peVar2 + uStack_4)->base).x) &&
        (((peVar2 + uStack_4)->base).x <= GfxRndSeed + 1U)) &&
       (peVar2[uStack_4].base.y == GfxRndSeed2)) {
      *(uint *)(&agentIndices + iStack_6 * 2) = uStack_4;
      iStack_6 = iStack_6 + 1;
    }
  }
  iVar4 = 0;
  iVar3 = 0;
  while ((iVar3 < iStack_6 || (iVar4 < iStack_6))) {
    while( true ) {
      peVar2 = (entity_t *)Entities;
      uVar5 = (undefined2)((ulong)Entities >> 0x10);
      if ((iStack_6 <= iVar4) ||
         (*(char *)((int)(char **)GMenuStrings +
                   (uint)peVar2[*(int *)(&agentIndices + iVar4 * 2)].base.gindex * 0x95 + 0x1f) ==
          '\x01')) break;
      iVar4 = iVar4 + 1;
    }
    while ((iVar3 < iStack_6 &&
           (*(char *)((int)(char **)GMenuStrings +
                     (uint)peVar2[*(int *)(&agentIndices + iVar3 * 2)].base.gindex * 0x95 + 0x1f) !=
            '\0'))) {
      iVar3 = iVar3 + 1;
    }
    if (iVar4 < iStack_6) {
      uStack_8 = (peVar2[*(int *)(&agentIndices + iVar4 * 2)].base.animFrame + 0xf) / 0x10;
    }
    else {
      uStack_8 = 0;
    }
    if (iVar3 < iStack_6) {
      uStack_a = (peVar2[*(int *)(&agentIndices + iVar3 * 2)].base.animFrame + 0xf) / 0x10;
    }
    else {
      uStack_a = 0;
    }
    while ((uStack_8 != 0 || (uStack_a != 0))) {
      if (uStack_8 != 0) {
        ovc15_textArena(0,*(undefined2 *)(&agentIndices + iVar4 * 2),(uint)(AgntFlag1 == false));
        uStack_8 = uStack_8 - 1;
      }
      if (uStack_a != 0) {
        ovc15_textArena(0,*(undefined2 *)(&agentIndices + iVar3 * 2),(uint)(AgntFlag1 == false));
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
      ovr_ovc41_removeAgent(0,unaff_DI,uVar1);
    }
  }
  AgntFlag1 = true;
  return;
}



/* 4207:0e17 */

/* Removes an entity record: kills its agents when AgntFlag1 is set, compacts the Entities array,
   fixes every agent's owner index/entity pointer, and decrements EntityCount. */

void __cdecl16far ovc15_removeEntity(uint entityIndex,...)

{
  int *piVar1;
  char cVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  uint uVar5;
  entity_t *peVar6;
  uint uVar7;
  undefined2 uVar8;
  uint in_stack_00000004;
  
  uVar5 = in_stack_00000004;
  if (AgntFlag1) {
    for (uVar7 = 0; uVar7 < AgntCount; uVar7 = uVar7 + 1) {
      if ((*(uint *)(uVar7 * 0x34 + 0x1b) == in_stack_00000004) &&
         (*(char *)(uVar7 * 0x34 + 0x24) != '\x02')) {
        *(undefined1 *)(uVar7 * 0x34 + 0x24) = 2;
        *(undefined2 *)(uVar7 * 0x34 + 6) = 0;
      }
    }
  }
  uVar8 = (undefined2)((ulong)Entities >> 0x10);
  peVar6 = (entity_t *)Entities;
  uVar3 = peVar6[in_stack_00000004].base.destX;
  uVar4 = peVar6[in_stack_00000004].base.destY;
  cVar2 = *(char *)((int)(char **)GMenuStrings +
                   (uint)peVar6[in_stack_00000004].base.gindex * 0x95 + 0x1f);
  if (in_stack_00000004 < EntityCount - 1U) {
    _fmemmove((char *)CONCAT22(uVar8,peVar6 + in_stack_00000004),
              (char *)CONCAT22(uVar8,peVar6 + in_stack_00000004 + 1),
              ((EntityCount + -1) - in_stack_00000004) * 0x37);
  }
  if (AgntFlag1 != false) {
    for (uVar7 = 0; uVar7 < AgntCount; uVar7 = uVar7 + 1) {
      if (uVar5 < *(uint *)(uVar7 * 0x34 + 0x1b)) {
        piVar1 = (int *)(uVar7 * 0x34 + 0x1b);
        *piVar1 = *piVar1 + -1;
        peVar6 = (entity_t *)Entities + *(int *)(uVar7 * 0x34 + 0x1b);
        *(undefined2 *)(uVar7 * 0x34 + 0x19) = (*(uint16_t *)((uint8_t *)&(Entities) + 2));
        *(undefined2 *)(uVar7 * 0x34 + 0x17) = peVar6;
      }
    }
  }
  EntityCount = EntityCount + -1;
  if ((cVar2 == '\0') && ((uVar3 != 0 || (uVar4 != 0)))) {
    ovr_attact_usesAlignUp4();
  }
  ovr_attact_usesGMapFlags3();
  return;
}



/* 4207:0ff0 */

/* [R4] calls ovr_alignUp4 */

uint __cdecl16far ovc15_usesAlignUp4(uint16_t x,uint16_t y)

{
  undefined4 uVar1;
  uint uVar2;
  uint16_t uVar3;
  entity_t *peVar4;
  uint uVar5;
  int unaff_DI;
  undefined2 uVar6;
  
  uVar2 = ovr_alignUp4(unaff_DI,x);
  uVar5 = 0;
  uVar3 = uVar2;
  do {
    if (EntityCount <= uVar5) {
      return uVar3 & 0xff00;
    }
    uVar3 = uVar5 * 0x37;
    uVar6 = (undefined2)((ulong)Entities >> 0x10);
    peVar4 = (entity_t *)Entities;
    if ((((*(byte *)((int)&peVar4[uVar5].base.flags32 + 1) & 2) != 0) &&
        (uVar3 = peVar4[uVar5].base.targetY, uVar3 == y)) &&
       (uVar3 = ovr_alignUp4(unaff_DI,peVar4[uVar5].base.targetX), uVar3 == uVar2)) {
      uVar3 = uVar5 * 0x37;
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      if ((*(char *)((int)&((entity_t *)Entities)[uVar5].base.entity + 3) != -1) &&
         (uVar1 = *(undefined4 *)
                   ((uint)*(byte *)((int)&((entity_t *)Entities)[uVar5].base.entity + 3) << 2),
         uVar3 = (uint16_t)*(byte *)((int)uVar1 + 0x3f), uVar3 == 0)) {
        return 1;
      }
    }
    uVar5 = uVar5 + 1;
  } while( true );
}



/* 4207:10a3 */

/* [R4] calls LDIV_at_ */

entity_t * __cdecl16far
ovc15_usesLDIV_at_(uint16_t x,uint16_t y,uint16_t destX,uint16_t destY,byte gindex,uint8_t animFrame
                  ,byte partyIndex,...)

{
  uint8_t *puVar1;
  uint *puVar2;
  undefined2 uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  entity_t *peVar7;
  undefined2 uVar8;
  long lVar9;
  uint16_t in_stack_00000004;
  int iStack_6;
  
  if (EntityCount < 0x259) {
    mapDirty = 1;
    if (PlayerIndex < 2) {
      if (0x21b < EntityCount) {
        ovc15_usesRandBelow2();
        ovc15_removeEntity();
        EntityCount = EntityCount - 1;
      }
    }
    else if (599 < EntityCount) {
      ovc15_usesRandBelow2();
      ovc15_removeEntity();
      EntityCount = EntityCount - 1;
    }
    _fsetmem((entity_t *)CONCAT22((int)((ulong)Entities >> 0x10),(entity_t *)Entities + EntityCount)
             ,0x37,0);
    ((entity_t *)Entities)[EntityCount].base.targetX = y;
    ((entity_t *)Entities)[EntityCount].base.targetY = destX;
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    if ((y == in_stack_00000004) && (destX == x)) {
      ((entity_t *)Entities)[EntityCount].base.destX = 0;
      ((entity_t *)Entities)[EntityCount].base.destY = 0;
    }
    else {
      ((entity_t *)Entities)[EntityCount].base.destX = y;
      ((entity_t *)Entities)[EntityCount].base.destY = destX;
    }
    (((entity_t *)Entities + EntityCount)->base).x = in_stack_00000004;
    ((entity_t *)Entities)[EntityCount].base.y = x;
    ((entity_t *)Entities)[EntityCount].base.target = 0xff;
    ((entity_t *)Entities)[EntityCount].base.gindex = (uint8_t)destY;
    uVar5 = EntityCount;
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    peVar7 = (entity_t *)Entities;
    puVar1 = &peVar7[EntityCount].base.frameIndex;
    puVar1[0] = 0x0;
    puVar1[1] = 0x0;
    puVar1 = &peVar7[uVar5].base.health;
    puVar1[0] = 0x64;
    puVar1[1] = 0x0;
    *(undefined2 *)((int)&((entity_t *)Entities)[EntityCount].base.frames + 1) = 0;
    ((entity_t *)Entities)[EntityCount].base.animFrame = gindex;
    *(uint8_t *)((int)&((entity_t *)Entities)[EntityCount].base.entity + 3) = animFrame;
    *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
         *(undefined1 *)((int)&worldMenuLabels[6].seg + (destY & 0xff) * 0x95);
    *(undefined1 *)&((entity_t *)Entities)[EntityCount].base.flags32 =
         *(undefined1 *)((int)&worldMenuLabels[6].seg + (destY & 0xff) * 0x95);
    if (*(char *)((int)*(undefined4 *)((uint)animFrame << 2) + 0x2f) != -1) {
      uVar5 = (uint)*(byte *)((int)&worldMenuLabels[6].seg + (destY & 0xff) * 0x95);
      uVar8 = ovr_agnt_abilityModifier();
      iStack_6 = uVar5 + (int)(char)uVar8;
      if (iStack_6 < 1) {
        iStack_6 = 1;
      }
      *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
           (undefined1)iStack_6;
      *(undefined1 *)&((entity_t *)Entities)[EntityCount].base.flags32 = (undefined1)iStack_6;
    }
    if (*(char *)((int)(char **)GMenuStrings + (destY & 0xff) * 0x95 + 0x1f) == '\0') {
      uVar5 = ovc15_usesAlignUp4(y,destX);
      if ((uVar5 & 0xff) == 0) {
        *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.flags32 + 1) = 2;
      }
    }
    else if ((y == in_stack_00000004) && (destX == x)) {
      *(undefined1 *)((int)&((entity_t *)Entities)[EntityCount].base.flags32 + 1) = 2;
    }
    if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (destY & 0xff) * 0x95) & 0x1000) == 0) {
      if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (destY & 0xff) * 0x95) & 0x2000) == 0) {
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
         *(uint8_t *)((int)&worldMenuLabels[8].seg + (destY & 0xff) * 0x95);
    if ((((*(byte *)((int)*(undefined4 *)((uint)animFrame << 2) + 0x5d) & 0x10) != 0) &&
        (*(byte *)((int)&worldMenuLabels[8].seg + (destY & 0xff) * 0x95) < 5)) &&
       (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (destY & 0xff) * 0x95) != -1)) {
      while (((entity_t *)Entities)[EntityCount].base.level < 5) {
        cVar4 = ovc15_textView();
        uVar8 = (undefined2)((ulong)Entities >> 0x10);
        *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
             *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) + cVar4;
        uVar8 = (undefined2)((ulong)Entities >> 0x10);
        *(char *)&((entity_t *)Entities)[EntityCount].base.flags32 =
             (char)((entity_t *)Entities)[EntityCount].base.flags32 + cVar4;
        puVar1 = &((entity_t *)Entities)[EntityCount].base.level;
        *puVar1 = *puVar1 + 0x1;
      }
    }
    uVar5 = EntityCount;
    peVar7 = (entity_t *)Entities;
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (destY & 0xff) * 0x95) == -1) {
      iVar6 = (uint)peVar7[EntityCount].base.level * 4;
      uVar3 = *(undefined2 *)(iVar6 + -4);
      *(undefined2 *)&peVar7[EntityCount].base.frameIndex = *(undefined2 *)(iVar6 + -2);
      *(undefined2 *)&peVar7[uVar5].base.health = uVar3;
    }
    else {
      iVar6 = (uint)*(byte *)((int)&worldMenuLabels[9].ofs + 1 + (destY & 0xff) * 0x95) * 0x94 +
              (uint)peVar7[EntityCount].base.level * 4;
      uVar3 = *(undefined2 *)(iVar6 + -4);
      *(undefined2 *)&peVar7[EntityCount].base.frameIndex = *(undefined2 *)(iVar6 + -2);
      *(undefined2 *)&peVar7[uVar5].base.health = uVar3;
    }
    uVar5 = EntityCount;
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
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
      uVar8 = (undefined2)((ulong)Entities >> 0x10);
      peVar7 = (entity_t *)Entities;
      if (((GfxRndSeed - 2U <= ((peVar7 + uVar5)->base).x) &&
          (((peVar7 + uVar5)->base).x <= GfxRndSeed + 1U)) && (peVar7[uVar5].base.y == GfxRndSeed2))
      {
        ovc15_textArena();
      }
    }
    peVar7 = (entity_t *)Entities + uVar5;
    return peVar7;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit();
}



/* 4207:16a5 */

/* [R4] calls LDIV_at_ */

void __cdecl16far ovc15_usesLDIV_at_2(int entityIndex,byte gindex,char partySlot,...)

{
  uint8_t *puVar1;
  uint *puVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  entity_t *peVar6;
  int iVar7;
  uint uVar8;
  uint16_t uVar9;
  entity_t *peVar10;
  int iVar11;
  int iVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  bool bVar15;
  long lVar16;
  int in_stack_00000004;
  
  iVar7 = in_stack_00000004;
  if (gindex != 0xff) {
    mapDirty = 1;
    peVar6 = (entity_t *)Entities;
    uVar5 = (undefined2)((ulong)Entities >> 0x10);
    ((entity_t *)Entities)[in_stack_00000004].base.target = 0xff;
    peVar6[in_stack_00000004].base.gindex = (uint8_t)entityIndex;
    peVar6[in_stack_00000004].base.level =
         *(uint8_t *)((int)&worldMenuLabels[8].seg + (entityIndex & 0xffU) * 0x95);
    puVar1 = &peVar6[in_stack_00000004].base.frameIndex;
    puVar1[0] = 0x0;
    puVar1[1] = 0x0;
    puVar1 = &peVar6[in_stack_00000004].base.health;
    puVar1[0] = 0x64;
    puVar1[1] = 0x0;
    *(undefined2 *)((int)&peVar6[in_stack_00000004].base.frames + 1) = 0;
    *(undefined2 *)((int)&peVar6[in_stack_00000004].base.frames + 3) = 0;
    *(byte *)((int)&peVar6[in_stack_00000004].base.entity + 3) = gindex;
    *(undefined1 *)((int)&peVar6[in_stack_00000004].base.state + 1) =
         *(undefined1 *)((int)&worldMenuLabels[6].seg + (entityIndex & 0xffU) * 0x95);
    *(undefined1 *)&peVar6[in_stack_00000004].base.flags32 =
         *(undefined1 *)((int)&worldMenuLabels[6].seg + (entityIndex & 0xffU) * 0x95);
    lVar16 = 0x8000;
    uVar8 = rand();
    lVar16 = LDIV_at_(CONCAT22(((int)uVar8 >> 0xf) << 1 | (uint)((int)uVar8 < 0),uVar8 << 1),lVar16)
    ;
    if ((int)lVar16 == 0) {
      puVar2 = (uint *)((int)&peVar6[iVar7].base.frames + 3);
      *puVar2 = *puVar2 | 1;
    }
    ovr_attact_usesGMapFlags3();
    if (AgntFlag1 != false) {
      uVar13 = (undefined2)((ulong)Entities >> 0x10);
      peVar10 = (entity_t *)Entities;
      if (((GfxRndSeed - 2U <= ((peVar10 + iVar7)->base).x) &&
          (((peVar10 + iVar7)->base).x <= GfxRndSeed + 1U)) &&
         (peVar10[iVar7].base.y == GfxRndSeed2)) {
        for (iVar12 = 0; iVar12 < (int)(uint)AgntCount; iVar12 = iVar12 + 1) {
          if (*(int *)(iVar12 * 0x34 + 0x1b) == iVar7) {
            *(undefined1 *)(iVar12 * 0x34 + 0xc) = 0xff;
            bVar3 = peVar6[iVar7].base.gindex;
            *(undefined2 *)(iVar12 * 0x34 + 0x1f) = 0x195d;
            *(int *)(iVar12 * 0x34 + 0x1d) = (uint)bVar3 * 0x95 + 0x26d6;
            *(undefined1 *)(iVar12 * 0x34 + 0x21) =
                 *(undefined1 *)((int)&peVar6[iVar7].base.state + 1);
            *(undefined1 *)(iVar12 * 0x34 + 0x22) = (char)peVar6[iVar7].base.flags32;
            bVar15 = (*(uint *)((int)&peVar6[iVar7].base.frames + 3) & 1) != 0;
            if (peVar6[iVar7].base.level < 10) {
              if (peVar6[iVar7].base.level < 4) {
                uVar4 = *(undefined4 *)(iVar12 * 0x34 + 0x1d);
                uVar14 = (undefined2)((ulong)uVar4 >> 0x10);
                iVar11 = (int)uVar4 + (uint)bVar15 * 0xc;
                uVar13 = *(undefined2 *)(iVar11 + 3);
                *(undefined2 *)(iVar12 * 0x34 + 0x15) = *(undefined2 *)(iVar11 + 5);
                *(undefined2 *)(iVar12 * 0x34 + 0x13) = uVar13;
              }
              else {
                uVar4 = *(undefined4 *)(iVar12 * 0x34 + 0x1d);
                uVar14 = (undefined2)((ulong)uVar4 >> 0x10);
                iVar11 = (int)uVar4 + (uint)bVar15 * 0xc;
                uVar13 = *(undefined2 *)(iVar11 + 7);
                *(undefined2 *)(iVar12 * 0x34 + 0x15) = *(undefined2 *)(iVar11 + 9);
                *(undefined2 *)(iVar12 * 0x34 + 0x13) = uVar13;
              }
            }
            else {
              uVar4 = *(undefined4 *)(iVar12 * 0x34 + 0x1d);
              uVar14 = (undefined2)((ulong)uVar4 >> 0x10);
              iVar11 = (int)uVar4 + (uint)bVar15 * 0xc;
              uVar13 = *(undefined2 *)(iVar11 + 0xb);
              *(undefined2 *)(iVar12 * 0x34 + 0x15) = *(undefined2 *)(iVar11 + 0xd);
              *(undefined2 *)(iVar12 * 0x34 + 0x13) = uVar13;
            }
            *(undefined1 *)(iVar12 * 0x34 + 0xe) = 0xff;
            *(undefined1 *)(iVar12 * 0x34 + 0x2f) =
                 *(undefined1 *)*(undefined4 *)(iVar12 * 0x34 + 0x1d);
            uVar4 = *(undefined4 *)(iVar12 * 0x34 + 0x13);
            uVar13 = (undefined2)((ulong)uVar4 >> 0x10);
            iVar11 = (int)uVar4;
            if ((*(int *)(iVar11 + 0x68) == 0 && *(int *)(iVar11 + 0x6a) == 0) ||
               (uVar4 = *(undefined4 *)(iVar12 * 0x34 + 0x13),
               uVar13 = (undefined2)((ulong)uVar4 >> 0x10), iVar11 = (int)uVar4,
               *(int *)(iVar11 + 0x58) == 0 && *(int *)(iVar11 + 0x5a) == 0)) {
              uVar4 = *(undefined4 *)(iVar12 * 0x34 + 0x13);
              uVar13 = (undefined2)((ulong)uVar4 >> 0x10);
              iVar11 = (int)uVar4;
              if (*(int *)(iVar11 + 0x68) == 0 && *(int *)(iVar11 + 0x6a) == 0) {
                *(undefined1 *)(iVar12 * 0x34 + 0x11) = 0;
              }
              else {
                *(undefined1 *)(iVar12 * 0x34 + 0x11) = 1;
              }
            }
            else {
              uVar9 = ovr_randBelow();
              *(undefined1 *)(iVar12 * 0x34 + 0x11) = (char)uVar9;
            }
            ovr_audio_panFromX();
            ovr_play_sfxU();
          }
        }
      }
    }
  }
  return;
}



/* 4207:1aae */

/* [R4] calls ovr_stExit */

void __cdecl16far ovc15_usesStExit(int entityIndex,...)

{
  uint8_t *puVar1;
  uint uVar2;
  entity_t *peVar3;
  int iVar4;
  int unaff_DI;
  uint uVar5;
  undefined2 uVar6;
  int in_stack_00000004;
  char cStack_5;
  
  if (EntityCount < 0x259) {
    if (EntityCount != 600) {
      memcpy((char *)CONCAT22((*(uint16_t *)((uint8_t *)&(Entities) + 2)),(entity_t *)Entities + EntityCount),
             (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(Entities) + 2)),(entity_t *)Entities + in_stack_00000004),0x37);
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      ((entity_t *)Entities)[EntityCount].base.animFrame =
           (uint8_t)((int)(uint)((entity_t *)Entities)[in_stack_00000004].base.animFrame >> 1);
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      puVar1 = &((entity_t *)Entities)[in_stack_00000004].base.animFrame;
      *puVar1 = *puVar1 - ((entity_t *)Entities)[EntityCount].base.animFrame;
      uVar2 = EntityCount;
      uVar5 = (uint)((entity_t *)Entities)[EntityCount].base.animFrame;
      EntityCount = EntityCount + 1;
      ovr_attact_usesGMapFlags3();
      if (AgntFlag1 != false) {
        cStack_5 = '\0';
        iVar4 = 0;
        while ((iVar4 < (int)(uint)AgntCount && (uVar5 != 0))) {
          if (*(int *)(iVar4 * 0x34 + 0x1b) == in_stack_00000004) {
            if (cStack_5 == '\0') {
              *(uint *)(iVar4 * 0x34 + 0x1b) = uVar2;
              peVar3 = (entity_t *)Entities + uVar2;
              *(undefined2 *)(iVar4 * 0x34 + 0x19) = (*(uint16_t *)((uint8_t *)&(Entities) + 2));
              *(undefined2 *)(iVar4 * 0x34 + 0x17) = peVar3;
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
  ovr_stExit(unaff_DI,0x26);
}



/* 4207:1c16 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_stshRealloc */

uint8_t * __cdecl16far ovc15_usesStshRealloc(char *text,...)

{
  uint8_t uVar1;
  size_t sVar2;
  uint8_t *puVar3;
  undefined2 in_DX;
  uint unaff_BP;
  undefined2 in_stack_00000004;
  undefined1 uVar4;
  
  uVar4 = (undefined1)((ulong)text >> 8);
  sVar2 = strlen((char *)CONCAT13(uVar4,CONCAT12((char)text,in_stack_00000004)));
  puVar3 = ovr_stshRealloc(CONCAT22(sVar2 + 1,upperTextSeg),(ulong)unaff_BP << 0x10,upperTextOfs,0);
  _upperTextOfs = (uint8_t *)CONCAT22(in_DX,puVar3);
  strcpy((char *)CONCAT22(in_DX,puVar3),
         (char *)CONCAT13(uVar4,CONCAT12((char)text,in_stack_00000004)));
  uVar1 = toupper(*_upperTextOfs);
  *_upperTextOfs = uVar1;
  puVar3 = upperTextOfs;
  return puVar3;
}



/* 4207:1c79 */

/* Copies a string and capitalises its first character. */

char * __cdecl16far ovc15_capitalize(char *text,...)

{
  char cVar1;
  char *in_stack_00000004;
  undefined2 in_stack_0000000a;
  
  strcpy((char *)CONCAT22((char *)text,in_stack_00000004),
         (char *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(text) + 2))));
  cVar1 = toupper(*(char *)CONCAT22((char *)text,in_stack_00000004));
  *(char *)CONCAT22((char *)text,in_stack_00000004) = cVar1;
  return in_stack_00000004;
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
  uint unaff_DI;
  uint16_t i;
  uint16_t pseg;
  uint32_t cte;
  int in_stack_00000004;
  undefined2 uVar5;
  uint8_t *data;
  cte_t *data_00;
  far_t pframe;
  uint8_t frmid;
  uint8_t first_frame;
  uint16_t next_ofs;
  uint16_t next_seg;
  
  data_00 = (cte_t *)((ulong)unaff_DI << 0x10);
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
        *(undefined2 *)(pframe.ofs + 3) = 0;
        *(undefined2 *)(pframe.ofs + 1) = 0;
        uVar5 = (undefined2)((ulong)data_00 >> 0x10);
        if (bVar3) {
          data = (uint8_t *)CONCAT22(uVar5,pframe.seg);
          (*(uint16_t *)((uint8_t *)&(cte) + 2)) = uVar2;
          (*(uint16_t *)((uint8_t *)&(cte))) = ovr_stshStoreFile(data,pframe.ofs);
          data_00 = (cte_t *)CONCAT22((int)((ulong)data >> 0x10),(cte_t *)cte);
          iVar4 = in_stack_00000004 + index * 4;
          *(uint16_t *)(iVar4 + 0x5a) = (*(uint16_t *)((uint8_t *)&(cte) + 2));
          *(undefined2 *)(iVar4 + 0x58) = (cte_t *)cte;
        }
        else {
          data_00 = (cte_t *)CONCAT22(uVar5,pframe.seg);
          ovr_stshStoreFile((uint8_t *)data_00,pframe.ofs);
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

undefined2 __cdecl16far ovc15_usesStExit2(byte agntIndex)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int unaff_DI;
  undefined4 uStack_12;
  int iStack_6;
  int iStack_4;
  
  piVar1 = (int *)((uint)agntIndex * 0x34);
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
      ovr_stExit(unaff_DI,0x25);
    }
    iVar5 = iStack_6;
    if (*(char *)((int)piVar1 + 0x11) == '\0') {
      for (; iVar5 <= iVar3; iVar5 = iVar5 + 1) {
        if (agntIndex + 1 != (uint)*(byte *)(iStack_4 * 0x69 + iVar5 + 0x8fa)) {
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
        if (agntIndex + 1 != (uint)*(byte *)(iStack_4 * 0x69 + iVar5 + 0x4e0)) {
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

undefined2 __cdecl16far ovc15_compute1(uint16_t *agnt)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint16_t *puVar6;
  undefined2 uVar7;
  undefined1 uVar8;
  int in_stack_0000fff4;
  undefined4 uStack_6;
  
  uVar7 = (undefined2)((ulong)agnt >> 0x10);
  puVar6 = (uint16_t *)agnt;
  uVar1 = *(undefined2 *)((int)puVar6 + 0x15);
  piVar2 = (int *)*(int *)((int)puVar6 + 0x13);
  uStack_6 = (int *)CONCAT22(uVar1,piVar2);
  if (*(char *)((int)puVar6 + 0x11) == '\0') {
    iVar5 = piVar2[1];
    iVar3 = *uStack_6;
    iVar4 = ovr_agnt_clampX(in_stack_0000fff4,*agnt);
    iVar5 = (*(int *)(iVar3 + 0xd) - *(int *)(iVar4 * 2 + 0x34c)) + 0x93;
    uVar8 = (undefined1)iVar5;
  }
  else {
    iVar5 = piVar2[9];
    iVar3 = piVar2[8];
    iVar4 = ovr_agnt_clampX(in_stack_0000fff4,*agnt);
    iVar5 = (*(int *)(iVar3 + 0xd) - *(int *)(iVar4 * 2 + 0x34c)) + 0xac;
    uVar8 = (undefined1)iVar5;
  }
  return CONCAT11((char)((uint)iVar5 >> 8),uVar8);
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
  agnt_t *paVar7;
  uint16_t unaff_DI;
  agnt_t *paVar8;
  uint16_t unaff_SS;
  undefined1 uVar9;
  uint16_t xOffsets [4];
  int iStack_6;
  int iStack_4;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)xOffsets;
  F_SCOPY(far_from_u32((uint32_t)(0x24101d09)),dst);
  paVar7 = (agnt_t *)agnt;
  paVar8 = (agnt_t *)((ulong)agnt >> 0x10);
  if (keepPos == '\0') {
    if (xSide < 0) {
      agnt->x = 0;
      uVar2 = ovr_randBelow(unaff_DI,0x14);
      paVar7->y = uVar2 & 0xff;
    }
    else if (xSide < 1) {
      iVar5 = ((paVar7->entity->base).x - GfxRndSeed) + 2;
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      if (3 < iVar5) {
        iVar5 = 3;
      }
      agnt->x = xOffsets[iVar5];
      if (randomY == '\0') {
        paVar7->y = 0x20;
      }
      else {
        uVar2 = ovr_randBelow(unaff_DI,0x14);
        paVar7->y = uVar2 & 0xff;
      }
    }
    else {
      agnt->x = 0xd2;
      uVar2 = ovr_randBelow(unaff_DI,0x14);
      paVar7->y = uVar2 & 0xff;
    }
  }
  uVar2 = agnt->x;
  if ((int)uVar2 < 0x6a) {
    iStack_6 = 1;
  }
  else {
    iStack_6 = -1;
  }
  uVar9 = SUB41(agnt,0);
  ovr_ovc49_body1((agnt_t *)CONCAT22(unaff_DI,paVar8),uVar9);
  do {
    if (paVar7->animVariant == 0x0) {
      uVar4 = ovr_ovc49_compute1(unaff_DI,agnt->x);
      bVar6 = (byte)(uVar4 >> 8);
      if ((char)uVar4 == '\0') goto L_OVC15_4207_1ffe_2193;
    }
    else {
L_OVC15_4207_1ffe_2193:
      iVar5 = ovr_ovc49_usesStExit((agnt_t *)CONCAT22(unaff_DI,paVar8),uVar9);
      bVar6 = (byte)((uint)iVar5 >> 8);
      if ((char)iVar5 == '\0') {
        if (paVar7->y == 0x20) {
          uVar4 = ovc15_compute1(&agnt->x);
          paVar7->y = uVar4 & 0xff;
        }
        iStack_4 = 0;
        while ((iStack_4 < (int)(uint)AgntCount && (*(int *)(iStack_4 * 0x34 + 2) < (int)paVar7->y))
              ) {
          iStack_4 = iStack_4 + 1;
        }
        if (iStack_4 < (int)(uint)AgntCount) {
          _fmemmove((char *)CONCAT22(0x1726,(char *)(iStack_4 * 0x34 + 0x34)),
                    (char *)CONCAT13(0x17,CONCAT12(0x26,iStack_4 * 0x34)),
                    ((uint)AgntCount - iStack_4) * 0x34);
        }
        paVar7->visited = 0x1;
        memcpy((char *)CONCAT22(0x1726,(char *)(iStack_4 * 0x34)),(char *)agnt,0x34);
        ovr_agnt_usesAgntCount5(unaff_DI,iStack_4 + 1);
        ovr_ovc49_fillGridCells
                  ((byte)(iStack_4 * 0x34),
                   (agnt_t *)CONCAT22(unaff_DI,(agnt_t *)((int)&AgntAnms[0x75].halfWidth + 1)),
                   CONCAT11((char)((uint)(iStack_4 * 0x34) >> 8),(char)iStack_4 + '\x01'));
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
      paVar7->y = 0x20;
    }
    else {
      uVar3 = ovr_randBelow(unaff_DI,0x14);
      paVar7->y = uVar3 & 0xff;
    }
    ovr_ovc49_body1((agnt_t *)CONCAT22(unaff_DI,paVar8),uVar9);
  } while( true );
}



/* 4207:2301 */

/* [R2] string "arena" */

char * __cdecl16far ovc15_textArena(int owner,...)

{
  bool bVar1;
  uint uVar2;
  uint16_t uVar3;
  char *pcVar4;
  entity_t *peVar5;
  agntG_t *paVar6;
  far_t *pfVar7;
  uint16_t unaff_DI;
  undefined2 uVar8;
  undefined2 uVar9;
  uint unaff_SS;
  uint16_t in_stack_00000004;
  char in_stack_00000008;
  agnt_t agntCopy;
  int iStack_8;
  
  uVar3 = in_stack_00000004;
  uVar9 = (*(uint16_t *)((uint8_t *)&(Entities) + 2));
  if (AgntFlag1) {
    for (iStack_8 = 0; iStack_8 < (int)(uint)AgntCount; iStack_8 = iStack_8 + 1) {
      if (((*(char *)(iStack_8 * 0x34 + 0x2d) == '\0') &&
          (*(uint16_t *)(iStack_8 * 0x34 + 0x1b) == in_stack_00000004)) &&
         ((*(uint *)(iStack_8 * 0x34 + 0x2b) & 0xae4) == 0)) {
        *(undefined1 *)(iStack_8 * 0x34 + 0x2d) = 1;
        if ((*(char *)(iStack_8 * 0x34 + 0x11) != '\0') ||
           (uVar2 = ovr_ovc49_compute1(unaff_DI,*(undefined2 *)(iStack_8 * 0x34)),
           (char)uVar2 == '\0')) {
          uVar2 = ovc15_usesStExit2((byte)iStack_8);
          if ((uVar2 & 0xff) != 0) {
            return (char *)((int)(undefined4 *)&_DATA + 1);
          }
        }
        _fmemmove((char *)CONCAT22(unaff_SS,&agntCopy),
                  (char *)CONCAT22(0x1726,(char *)(iStack_8 * 0x34)),0x34);
        agntCopy.target = 0xff;
        ovr_ovc41_removeAgent();
        pcVar4 = (char *)ovc15_usesRandBelow((agnt_t *)CONCAT22(unaff_SS,&agntCopy),owner,'\x01',
                                             in_stack_00000008);
        return pcVar4;
      }
    }
  }
  if (AgntCount < 0x18) {
    peVar5 = (entity_t *)Entities + in_stack_00000004;
    _fmemset((void *)(ulong)unaff_SS,0x34,unaff_DI);
    agntCopy.target = 0xff;
    (*(uint16_t *)((uint8_t *)&(agntCopy.entity) + 2)) = uVar9;
    agntCopy.owner = uVar3;
    agntCopy.gdata =
         (agntG_t *)
         CONCAT22(0x195d,(agntG_t *)
                         ((int)(char **)GMenuStrings + (uint)(peVar5->base).gindex * 0x95 + 0x1f));
    (*(uint16_t *)((uint8_t *)&(agntCopy.entity))) = peVar5;
    bVar1 = ovc15_usesAlignUp42();
    if (!bVar1) {
      *(undefined1 *)((int)&(peVar5->base).state + 1) = (char)(peVar5->base).flags32;
    }
    agntCopy.strengthMax = (uint8_t)(peVar5->base).flags32;
    agntCopy.strength = *(uint8_t *)((int)&(peVar5->base).state + 1);
    bVar1 = (*(uint *)((int)&(peVar5->base).frames + 3) & 1) != 0;
    paVar6 = (agntG_t *)agntCopy.gdata;
    uVar8 = (undefined2)((ulong)agntCopy.gdata >> 0x10);
    if ((peVar5->base).level < 10) {
      if ((peVar5->base).level < 4) {
        agntCopy.frames =
             (far_t *)CONCAT22(*(undefined2 *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 2),
                               *(far_t **)(paVar6->sprs + (uint)bVar1 * 3));
      }
      else {
        agntCopy.frames =
             (far_t *)CONCAT22(*(undefined2 *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 6),
                               *(far_t **)(paVar6->sprs + (uint)bVar1 * 3 + 1));
      }
    }
    else {
      agntCopy.frames =
           (far_t *)CONCAT22(*(undefined2 *)((int)paVar6->sprs + (uint)bVar1 * 0xc + 10),
                             *(far_t **)(paVar6->sprs + (uint)bVar1 * 3 + 2));
    }
    agntCopy.animFrame = 0xff;
    agntCopy.faction = (agntCopy.gdata)->ai;
    uVar9 = (undefined2)((ulong)agntCopy.frames >> 0x10);
    pfVar7 = (far_t *)agntCopy.frames;
    if (((pfVar7 + 0x1a)->ofs == 0 && pfVar7[0x1a].seg == 0) ||
       ((pfVar7 + 0x16)->ofs == 0 && pfVar7[0x16].seg == 0)) {
      if ((pfVar7 + 0x1a)->ofs != 0 || pfVar7[0x1a].seg != 0) {
        agntCopy.animVariant = 0x1;
      }
    }
    else {
      uVar3 = ovr_randBelow(unaff_DI,2);
      agntCopy.animVariant = (uint8_t)uVar3;
    }
    uVar3 = ovr_randBelow(unaff_DI,2);
    (*(uint8_t *)((uint8_t *)&(agntCopy.targetX))) = (char)uVar3 * '\x02' + -1;
    if ((char)agntCopy.targetX < '\x01') {
      if ((char)agntCopy.targetX < '\0') {
        agntCopy.level = 0x1;
      }
      else {
        uVar3 = ovr_randBelow(unaff_DI,2);
        agntCopy.level = (uint8_t)uVar3;
      }
    }
    else {
      agntCopy.level = 0x0;
    }
    pcVar4 = (char *)ovc15_usesRandBelow((agnt_t *)CONCAT22(unaff_SS,&agntCopy),owner,'\0',
                                         in_stack_00000008);
  }
  else {
    pcVar4 = (char *)"arena" + 4;
  }
  return pcVar4;
}



/* 4207:25dd */

/* WARNING: Control flow encountered bad instruction data */
/* [R2] string "View %s." */

entity_t * __cdecl16far
ovc15_textView(undefined4 param_1,int *param_2,int *param_3,undefined2 param_4,undefined2 param_5,
              int *param_6,int *param_7,int *param_8,int *param_9,...)

{
  uint8_t *puVar1;
  undefined4 *puVar2;
  char cVar3;
  far_t *pfVar4;
  int iVar5;
  cte_t *pcVar6;
  uint32_t *puVar7;
  uint uVar8;
  undefined2 uVar9;
  long *plVar10;
  undefined2 uVar11;
  entity_t *peVar12;
  uint uVar13;
  int iVar14;
  undefined2 unaff_BP;
  int unaff_SI;
  uint unaff_DI;
  int iVar15;
  undefined2 unaff_SS;
  bool bVar16;
  uint8_t in_stack_00000000;
  int in_stack_0000ffee;
  undefined1 in_stack_0000fff0;
  undefined1 uVar17;
  undefined1 in_stack_0000fff1;
  undefined1 uVar18;
  undefined1 uVar19;
  undefined1 uVar20;
  undefined1 in_stack_0000fff8;
  undefined1 in_stack_0000fffa;
  byte bVar21;
  byte in_stack_0000fffc;
  undefined1 in_stack_0000fffd;
  
  iVar15 = (int)((ulong)param_1 >> 0x10);
  uVar13 = (uint)param_1;
  bVar21 = *(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)*(byte *)(uVar13 + 0xd) * 0x95);
  if (bVar21 == 0xff) {
    bVar21 = 0;
  }
  uVar8 = bVar21 - 1;
  if (5 < uVar8) {
    if (*(byte *)(uVar13 + 0xf) < 10) {
      cVar3 = ovr_manage_rollDice();
      uVar17 = 0;
      uVar9 = ovr_agnt_abilityModifier();
      iVar15 = CONCAT11(uVar17,cVar3) + (int)(char)uVar9;
    }
    else {
      iVar15 = 2;
    }
    bVar21 = (byte)iVar15;
    if (iVar15 < 1) {
      bVar21 = 1;
    }
    return (entity_t *)(uint)bVar21;
  }
  iVar14 = uVar8 * 2;
  bVar16 = iVar14 == 0;
  switch(uVar8) {
  case 1:
    *(undefined2 *)((int)AgntGs[0].sprs + 10 + iVar14) = 0x195d;
    do {
      *(uint *)((int)AgntGs[0].sprs + 8 + iVar14) = uVar8;
      while( true ) {
        for (iVar15 = 0; iVar15 < 3; iVar15 = iVar15 + 1) {
          iVar14 = unaff_SI * 0x95 + iVar15 * 2;
          if (*(int *)((int)AgntGs[0].sprfls + 6 + iVar14) == 0) {
            iVar14 = unaff_SI * 0x95 + iVar15 * 4;
            uVar9 = *(undefined2 *)((int)AgntGs[0].sprs + iVar14);
            iVar5 = unaff_SI * 0x95 + iVar15 * 4;
            *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar5) =
                 *(undefined2 *)((int)AgntGs[0].sprs + 2 + iVar14);
            *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar5) = uVar9;
          }
          else {
            uVar9 = 0x195d;
            pfVar4 = stshSprite((far_t *)*(undefined2 *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                                *(int16_t *)((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95),
                                (anm_t *)(uint)*(byte *)((int)&AgntGs[0].nanims + unaff_SI * 0x95),
                                CONCAT11((char)((uint)iVar14 >> 8),(char)param_1),
                                (bool)in_stack_0000fff8);
            iVar14 = unaff_SI * 0x95 + iVar15 * 4;
            *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar14) = uVar9;
            *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar14) = pfVar4;
          }
        }
        for (iVar15 = 0; iVar15 < 6; iVar15 = iVar15 + 1) {
          uVar9 = 0x195d;
          if (*(int *)((int)AgntGs[0].prtfls + unaff_SI * 0x95 + iVar15 * 2) != 0) {
            if ((char)param_1 == '\0') {
              pfVar4 = ovr_stshAllocStub();
              iVar14 = unaff_SI * 0x95 + iVar15 * 4;
              uVar11 = 0x195d;
              *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar14) = uVar9;
              *(undefined2 *)((int)AgntGs[0].prts + iVar14) = pfVar4;
              pfVar4 = ovr_stshAllocStub();
              iVar14 = unaff_SI * 0x95 + iVar15 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar14) = uVar11;
              *(undefined2 *)((int)AgntGs[0].prtpals + iVar14) = pfVar4;
            }
            else {
              uVar9 = 0x195d;
              ovr_grabLbm();
              ovr_stshUniqueColorsRemap();
              ovr_stshRleType2();
              pcVar6 = ovr_stshStoreFile();
              iVar14 = unaff_SI * 0x95 + iVar15 * 4;
              uVar11 = 0x195d;
              *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar14) = uVar9;
              *(undefined2 *)((int)AgntGs[0].prts + iVar14) = pcVar6;
              puVar7 = ovr_stshWrite();
              iVar14 = unaff_SI * 0x95 + iVar15 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar14) = uVar11;
              *(undefined2 *)((int)AgntGs[0].prtpals + iVar14) = puVar7;
              ovr_stgFreeTmp();
            }
          }
        }
        peVar12 = (entity_t *)
                  (*(uint *)((int)AgntGs[0].prts + 4 + unaff_SI * 0x95) |
                  *(uint *)((int)AgntGs[0].prts + 6 + unaff_SI * 0x95));
        if ((peVar12 == (entity_t *)0x0) &&
           (peVar12 = (entity_t *)0x0,
           *(int *)((int)AgntGs[0].prts + unaff_SI * 0x95) != 0 ||
           *(int *)((int)AgntGs[0].prts + 2 + unaff_SI * 0x95) != 0)) {
          uVar9 = *(undefined2 *)((int)AgntGs[0].prts + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].prts + 6 + unaff_SI * 0x95) =
               *(undefined2 *)((int)AgntGs[0].prts + 2 + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].prts + 4 + unaff_SI * 0x95) = uVar9;
          peVar12 = (entity_t *)*(uint *)((int)AgntGs[0].prtpals + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].prtpals + 6 + unaff_SI * 0x95) =
               *(undefined2 *)((int)AgntGs[0].prtpals + 2 + unaff_SI * 0x95);
          *(uint *)((int)AgntGs[0].prtpals + 4 + unaff_SI * 0x95) = (uint)peVar12;
        }
        for (iVar15 = 2; iVar15 < 6; iVar15 = iVar15 + 2) {
          iVar14 = unaff_SI * 0x95 + iVar15 * 4;
          if ((*(int *)((int)AgntGs[0].prts + 4 + iVar14) == 0 &&
               *(int *)((int)AgntGs[0].prts + 6 + iVar14) == 0) &&
             (iVar14 = unaff_SI * 0x95 + iVar15 * 4,
             *(int *)((int)AgntGs[0].prtfls + 8 + iVar14) != 0 ||
             *(int *)((int)AgntGs[0].prtfls + 10 + iVar14) != 0)) {
            iVar14 = unaff_SI * 0x95 + iVar15 * 4;
            uVar9 = *(undefined2 *)((int)AgntGs[0].prtfls + 8 + iVar14);
            iVar5 = unaff_SI * 0x95 + iVar15 * 4;
            *(undefined2 *)((int)AgntGs[0].prts + 6 + iVar5) =
                 *(undefined2 *)((int)AgntGs[0].prtfls + 10 + iVar14);
            *(undefined2 *)((int)AgntGs[0].prts + 4 + iVar5) = uVar9;
            iVar14 = unaff_SI * 0x95 + iVar15 * 4;
            uVar9 = *(undefined2 *)((int)AgntGs[0].prts + 0x14 + iVar14);
            iVar5 = unaff_SI * 0x95 + iVar15 * 4;
            *(undefined2 *)((int)AgntGs[0].prtpals + 6 + iVar5) =
                 *(undefined2 *)((int)AgntGs[0].prts + 0x16 + iVar14);
            *(undefined2 *)((int)AgntGs[0].prtpals + 4 + iVar5) = uVar9;
          }
          iVar14 = unaff_SI * 0x95 + iVar15 * 4;
          peVar12 = (entity_t *)
                    (*(uint *)((int)AgntGs[0].prts + iVar14) |
                    *(uint *)((int)AgntGs[0].prts + 2 + iVar14));
          if (peVar12 == (entity_t *)0x0) {
            iVar14 = unaff_SI * 0x95 + iVar15 * 4;
            if (*(int *)((int)AgntGs[0].prtfls + 4 + iVar14) == 0 &&
                *(int *)((int)AgntGs[0].prtfls + 6 + iVar14) == 0) {
              peVar12 = (entity_t *)0x0;
            }
            else {
              iVar14 = unaff_SI * 0x95 + iVar15 * 4;
              uVar9 = *(undefined2 *)((int)AgntGs[0].prtfls + 4 + iVar14);
              iVar5 = unaff_SI * 0x95 + iVar15 * 4;
              *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar5) =
                   *(undefined2 *)((int)AgntGs[0].prtfls + 6 + iVar14);
              *(undefined2 *)((int)AgntGs[0].prts + iVar5) = uVar9;
              iVar14 = unaff_SI * 0x95 + iVar15 * 4;
              peVar12 = (entity_t *)*(uint *)((int)AgntGs[0].prts + 0x10 + iVar14);
              iVar5 = unaff_SI * 0x95 + iVar15 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar5) =
                   *(undefined2 *)((int)AgntGs[0].prts + 0x12 + iVar14);
              *(uint *)((int)AgntGs[0].prtpals + iVar5) = (uint)peVar12;
            }
          }
        }
        unaff_SI = unaff_SI + 1;
        if (0x29 < unaff_SI) {
          return peVar12;
        }
        uVar9 = 0x195d;
        pfVar4 = stshSprite((far_t *)*(undefined2 *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                            *(int16_t *)((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95),
                            (anm_t *)(uint)*(byte *)((int)&AgntGs[0].nanims + unaff_SI * 0x95),
                            CONCAT11((char)((uint)peVar12 >> 8),(char)param_1),
                            (bool)in_stack_0000fff8);
        *(undefined2 *)((int)AgntGs[0].sprs + 2 + unaff_SI * 0x95) = uVar9;
        *(undefined2 *)((int)AgntGs[0].sprs + unaff_SI * 0x95) = pfVar4;
        if (*(int *)((int)AgntGs[0].sprfls + 2 + unaff_SI * 0x95) == 0) {
          uVar9 = *(undefined2 *)((int)AgntGs[0].sprs + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95) =
               *(undefined2 *)((int)AgntGs[0].sprs + 2 + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95) = uVar9;
        }
        else {
          uVar9 = 0x195d;
          pfVar4 = stshSprite((far_t *)*(undefined2 *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                              *(int16_t *)((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95),
                              (anm_t *)(uint)*(byte *)((int)&AgntGs[0].nanims + unaff_SI * 0x95),
                              CONCAT11((char)((uint)(unaff_SI * 0x95) >> 8),(char)param_1),
                              (bool)in_stack_0000fff8);
          *(undefined2 *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95) = uVar9;
          *(undefined2 *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95) = pfVar4;
        }
        if (*(int *)((int)AgntGs[0].sprfls + 4 + unaff_SI * 0x95) == 0) break;
        uVar9 = 0x195d;
        pfVar4 = stshSprite((far_t *)*(undefined2 *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                            *(int16_t *)((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95),
                            (anm_t *)(uint)*(byte *)((int)&AgntGs[0].nanims + unaff_SI * 0x95),
                            CONCAT11((char)((uint)(unaff_SI * 0x95) >> 8),(char)param_1),
                            (bool)in_stack_0000fff8);
        *(undefined2 *)((int)AgntGs[0].sprs + 10 + unaff_SI * 0x95) = uVar9;
        *(undefined2 *)((int)AgntGs[0].sprs + 8 + unaff_SI * 0x95) = pfVar4;
      }
      uVar8 = *(uint *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95);
      iVar14 = unaff_SI * 0x95;
      *(undefined2 *)((int)AgntGs[0].sprs + 10 + iVar14) =
           *(undefined2 *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95);
    } while( true );
  case 2:
    do {
      cVar3 = ovc15_textView();
      uVar9 = (undefined2)((ulong)Entities >> 0x10);
      *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
           *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) + cVar3;
      uVar9 = (undefined2)((ulong)Entities >> 0x10);
      *(char *)&((entity_t *)Entities)[EntityCount].base.flags32 =
           (char)((entity_t *)Entities)[EntityCount].base.flags32 + cVar3;
      puVar1 = &((entity_t *)Entities)[EntityCount].base.level;
      *puVar1 = *puVar1 + 0x1;
      iVar15 = EntityCount;
      uVar9 = (undefined2)((ulong)Entities >> 0x10);
      peVar12 = (entity_t *)Entities;
    } while (peVar12[EntityCount].base.level < 5);
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(byte)param_3 * 0x95) == -1) {
      iVar14 = (uint)peVar12[EntityCount].base.level * 4;
      uVar11 = *(undefined2 *)(iVar14 + -4);
      *(undefined2 *)&peVar12[EntityCount].base.frameIndex = *(undefined2 *)(iVar14 + -2);
      *(undefined2 *)&peVar12[iVar15].base.health = uVar11;
    }
    else {
      iVar14 = (uint)*(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(byte)param_3 * 0x95) * 0x94
               + (uint)peVar12[EntityCount].base.level * 4;
      uVar11 = *(undefined2 *)(iVar14 + -4);
      *(undefined2 *)&peVar12[EntityCount].base.frameIndex = *(undefined2 *)(iVar14 + -2);
      *(undefined2 *)&peVar12[iVar15].base.health = uVar11;
    }
    iVar15 = EntityCount;
    uVar9 = (undefined2)((ulong)Entities >> 0x10);
    peVar12 = (entity_t *)Entities;
    if (*(int *)&peVar12[EntityCount].base.health == 0 &&
        *(int *)&peVar12[EntityCount].base.frameIndex == 0) {
      puVar1 = &peVar12[EntityCount].base.frameIndex;
      puVar1[0] = 0x0;
      puVar1[1] = 0x0;
      puVar1 = &peVar12[iVar15].base.health;
      puVar1[0] = 0x64;
      puVar1[1] = 0x0;
    }
    bVar21 = (byte)EntityCount;
    uVar17 = (undefined1)((uint)EntityCount >> 8);
    EntityCount = EntityCount + 1;
    ovr_attact_usesGMapFlags3();
    if (AgntFlag1 != false) {
      uVar9 = (undefined2)((ulong)Entities >> 0x10);
      peVar12 = (entity_t *)Entities;
      if (((GfxRndSeed - 2U <= ((peVar12 + CONCAT11(uVar17,bVar21))->base).x) &&
          (((peVar12 + CONCAT11(uVar17,bVar21))->base).x <= GfxRndSeed + 1U)) &&
         (peVar12[CONCAT11(uVar17,bVar21)].base.y == GfxRndSeed2)) {
        ovc15_textArena();
      }
    }
    peVar12 = (entity_t *)Entities + bVar21;
    return peVar12;
  case 3:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 4:
    ovr_createConstructionRecordFar();
    ovc18_textTypeLen();
    if (2 < Difficulty) {
      ovr_ovc22_usesRandBelow2();
    }
    ovr_ovc22_textRingProt();
    PartyCount = 0;
    ovr_manage_mapPartySlots();
    ovr_stats_openCastlePanel();
    ovr_unit_usesAlignUp4();
    ovr_say();
    peVar12 = (entity_t *)(uint)PlayerIndex;
    if (peVar12 == (entity_t *)0x0) {
      ovr_ovc30_nextWave();
    }
    return peVar12;
  case 5:
    do {
      if (bVar16) {
        *param_9 = *param_9 + 1;
      }
      while( true ) {
        while( true ) {
          do {
            do {
              unaff_DI = unaff_DI + 1;
              if (GRecordCount <= unaff_DI) {
                iVar15 = *param_8;
                iVar14 = *param_9;
                *param_2 = *param_2 - *param_8;
                *param_3 = *param_3 - *param_9;
                return (entity_t *)((uint)in_stack_0000fffc - (iVar15 + iVar14) & 0xff);
              }
            } while (*(char *)(unaff_DI * 0x12 + 9) != (char)param_1);
            bVar21 = *(byte *)(unaff_DI * 0x12 + 8);
          } while (*(char *)((uint)bVar21 * 0x27 + 0x133) != (*(uint8_t *)((uint8_t *)&(param_1) + 2)));
          *param_6 = *param_6 + 1;
          if (*(char *)((uint)bVar21 * 0x27 + 0x131) != '\x01') break;
          *param_7 = *param_7 + 1;
        }
        if (*(char *)((uint)bVar21 * 0x27 + 0x131) != '\x02') break;
        *param_8 = *param_8 + 1;
      }
      bVar16 = *(char *)((uint)bVar21 * 0x27 + 0x131) == '\x03';
    } while( true );
  }
  if (((byte)uVar8 & (&stack0x02c2)[unaff_DI]) == 0) {
    iVar15 = iVar15 + (uint)(0xffec < uVar13);
    plVar10 = LXRSH_at_((long *)CONCAT11(bVar21,in_stack_0000fffa),
                        CONCAT22(unaff_BP,CONCAT11(in_stack_0000fffd,in_stack_0000fffc)),
                        in_stack_00000000);
    uVar8 = (int)plVar10 + HeapPtr;
    iVar15 = iVar15 + (uint)CARRY2((uint)plVar10,HeapPtr);
    uVar13 = uVar8;
    if (iVar15 != 0) {
      uVar13 = 0xffff;
    }
    if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) && ((iVar15 != 0 || (MUSHandle.seg < uVar8))))
       || ((DIGHandle.ofs != 0 || DIGHandle.seg != 0 && ((iVar15 != 0 || (MUSHandle.seg < uVar8)))))
       ) {
      ovr_fmFreeAudio();
    }
    HeapPtr = 0xffff;
    uVar8 = 0xffff;
    bVar16 = false;
    uVar19 = (undefined1)StshCtPtr2.seg;
    uVar20 = (undefined1)(StshCtPtr2.seg >> 8);
    uVar17 = (undefined1)StshCtPtr2.ofs;
    uVar18 = (undefined1)(StshCtPtr2.ofs >> 8);
    while (CONCAT11(uVar18,uVar17) != 0 || CONCAT11(uVar20,uVar19) != 0) {
      iVar15 = CONCAT11(uVar18,uVar17);
      uVar9 = (undefined2)(CONCAT13(uVar20,CONCAT12(uVar19,iVar15)) >> 0x10);
      if (*(int *)(iVar15 + 0x11) != 0 || *(int *)(iVar15 + 0x13) != 0) {
        if (*(uint *)(CONCAT11(uVar18,uVar17) + 0x13) < uVar13) {
          in_stack_0000fff0 = 0x7f;
          in_stack_0000fff1 = 0x88;
          stshFree();
          iVar15 = CONCAT11(uVar18,uVar17);
          uVar9 = (undefined2)(CONCAT13(uVar20,CONCAT12(uVar19,iVar15)) >> 0x10);
          *(undefined2 *)(iVar15 + 0x13) = 0;
          *(undefined2 *)(iVar15 + 0x11) = 0;
          bVar16 = true;
        }
        else {
          if (*(uint *)(CONCAT11(uVar18,uVar17) + 0x13) < uVar8) {
            uVar8 = *(uint *)(CONCAT11(uVar18,uVar17) + 0x13);
            in_stack_0000ffee = CONCAT11(uVar18,uVar17);
            in_stack_0000fff0 = uVar19;
            in_stack_0000fff1 = uVar20;
          }
          if (*(uint *)(CONCAT11(uVar18,uVar17) + 0x13) < HeapPtr) {
            HeapPtr = *(uint *)(CONCAT11(uVar18,uVar17) + 0x13);
          }
        }
      }
      iVar15 = CONCAT11(uVar18,uVar17);
      uVar9 = (undefined2)(CONCAT13(uVar20,CONCAT12(uVar19,iVar15)) >> 0x10);
      uVar19 = (undefined1)*(undefined2 *)(iVar15 + 0xb);
      uVar20 = (undefined1)((uint)*(undefined2 *)(iVar15 + 0xb) >> 8);
      uVar17 = (undefined1)*(undefined2 *)(iVar15 + 9);
      uVar18 = (undefined1)((uint)*(undefined2 *)(iVar15 + 9) >> 8);
    }
    if (!bVar16) {
      if (uVar8 == 0xffff) {
        bVar16 = ovr_fmFreeAudio();
        if (bVar16) {
          return (entity_t *)((int)(undefined4 *)&_DATA + 1);
        }
        if (audioBusy != '\0') {
          return (entity_t *)0x0;
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit();
      }
      uVar19 = (undefined1)*(undefined2 *)(in_stack_0000ffee + 0x13);
      uVar20 = (undefined1)((uint)*(undefined2 *)(in_stack_0000ffee + 0x13) >> 8);
      uVar17 = 0x39;
      uVar18 = 0x89;
      stshFree();
      uVar9 = (undefined2)(CONCAT13(uVar18,CONCAT12(uVar17,in_stack_0000ffee)) >> 0x10);
      *(undefined2 *)(in_stack_0000ffee + 0x13) = 0;
      *(undefined2 *)(in_stack_0000ffee + 0x11) = 0;
      HeapPtr = CONCAT11(uVar20,uVar19);
    }
    puVar2 = (undefined4 *)&_DATA;
  }
  else {
    puVar2 = (undefined4 *)&_DATA;
  }
  return (entity_t *)((int)puVar2 + 1);
}



/* 4207:26bc */

/* WARNING: Instruction at (ram,0x0005ff51) overlaps instruction at (ram,0x0005ff50)
    */
/* [R2] string "Error 4 %d \r" */

uint __cdecl16far ovc15_textError(undefined4 param_1,ulong param_2,...)

{
  uint *puVar1;
  uint16_t *puVar2;
  uint8_t *puVar3;
  undefined4 uVar4;
  char cVar5;
  byte bVar6;
  char cVar7;
  bool bVar8;
  char cVar9;
  undefined1 uVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  far_t *pfVar10;
  cte_t *pcVar11;
  undefined2 *puVar12;
  long *plVar13;
  uint16_t uVar14;
  uint32_t *puVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  entity_t *in_CX;
  undefined2 uVar22;
  uint16_t uVar23;
  uint16_t uVar24;
  entity_t *peVar25;
  uint uVar26;
  undefined1 *puVar27;
  entity_t *peVar28;
  uint8_t unaff_BP;
  uint unaff_SI;
  char *pcVar29;
  uint uVar30;
  char *unaff_DI;
  undefined2 uVar31;
  int iVar32;
  undefined2 uVar33;
  undefined2 unaff_SS;
  bool bVar34;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  undefined1 auStackY_13e [36];
  uint16_t auStackY_11a [66];
  uint16_t auStackY_96 [24];
  entity_t eStackY_66;
  undefined2 uStackY_2c;
  undefined2 uStackY_2a;
  undefined1 *puStackY_28;
  entity_t *in_stack_0000ffe2;
  char cVar35;
  undefined1 uVar36;
  undefined1 uVar37;
  undefined1 in_stack_0000fff0;
  undefined1 in_stack_0000fff1;
  undefined1 in_stack_0000fff2;
  undefined1 in_stack_0000fff3;
  byte in_stack_0000fff4;
  byte bVar38;
  byte in_stack_0000fff5;
  uint uVar39;
  byte bVar40;
  uint3 uVar41;
  ulong val;
  undefined4 in_stack_0000fffa;
  ulong uVar42;
  
  uVar16 = CONCAT11(in_stack_0000fff1,in_stack_0000fff0);
  iVar32 = (int)((ulong)param_1 >> 0x10);
  uVar26 = (uint)param_1;
  puVar12 = (undefined2 *)((uint)*(byte *)(uVar26 + 0x1a) * 4);
  plVar13 = (long *)*puVar12;
  uVar42 = CONCAT22((int)((ulong)in_stack_0000fffa >> 0x10),puVar12[1]);
  bVar40 = (byte)plVar13;
  uVar36 = (undefined1)((uint)plVar13 >> 8);
  uVar23 = 0x195d;
  uVar33 = 0x195d;
  cVar5 = *(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)*(byte *)(uVar26 + 0xd) * 0x95);
  val = CONCAT13(cVar5,(int3)uVar42);
  if (cVar5 == -1) {
    val = uVar42 & 0xffffff;
  }
  pcVar29 = (char *)0x0;
  bVar38 = (byte)(val >> 0x18);
  uVar14 = (uint16_t)bVar38;
  if (6 < uVar14) {
    if ((uint)param_2 != 0 || (*(uint16_t *)((uint8_t *)&(param_2) + 2)) != 0) {
      uVar20 = 0;
      uVar19 = 0;
      uVar21 = 100;
      uVar37 = 0;
      plVar13 = LXMUL_at_((long *)0x0,CONCAT13(uVar36,CONCAT12(bVar40,unaff_SI)),val);
      param_2 = LDIV_at_(CONCAT13((char)((uint)(*(uint16_t *)((uint8_t *)&(param_2) + 2)) >> 8),
                                  CONCAT12((char)(*(uint16_t *)((uint8_t *)&(param_2) + 2)),plVar13)),
                         CONCAT13(uVar19,CONCAT12(uVar20,CONCAT11(uVar37,uVar21))));
      param_2 = param_2 & 0xffff;
    }
    return (uint)param_2;
  }
  puVar27 = (undefined1 *)(uVar14 * 2);
  switch(uVar14) {
  case 0:
    if ((bVar38 & (&stack0x02c2)[(int)unaff_DI]) == 0) {
      iVar32 = iVar32 + (uint)(0xffec < uVar26);
      uVar33 = 0x1000;
      plVar13 = LXRSH_at_(plVar13,val,unaff_BP);
      uVar26 = (int)plVar13 + HeapPtr;
      iVar32 = iVar32 + (uint)CARRY2((uint)plVar13,HeapPtr);
      uVar16 = uVar26;
      if (iVar32 != 0) {
        uVar16 = 0xffff;
      }
      if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) && ((iVar32 != 0 || (MUSHandle.seg < uVar26)))
          ) || ((DIGHandle.ofs != 0 || DIGHandle.seg != 0 &&
                ((iVar32 != 0 || (MUSHandle.seg < uVar26)))))) {
        uVar33 = 0x22f8;
        ovr_fmFreeAudio();
      }
      uVar39 = 0xffff;
      HeapPtr = 0xffff;
      bVar34 = false;
      uVar26 = 0xffff;
      uVar14 = StshCtPtr2.ofs;
      uVar23 = StshCtPtr2.seg;
      while( true ) {
        uVar36 = (undefined1)uVar33;
        uVar21 = (undefined1)((uint)uVar33 >> 8);
        if (uVar14 == 0 && uVar23 == 0) break;
        uVar30 = uVar26;
        uVar24 = uVar23;
        if (*(int *)(uVar14 + 0x11) != 0 || *(int *)(uVar14 + 0x13) != 0) {
          if (*(uint *)(uVar14 + 0x13) < uVar16) {
            stshFree();
            *(undefined2 *)(uVar14 + 0x13) = 0;
            *(undefined2 *)(uVar14 + 0x11) = 0;
            bVar34 = true;
            uVar24 = uVar23;
          }
          else {
            if (*(uint *)(uVar14 + 0x13) < uVar26) {
              uVar30 = *(uint *)(uVar14 + 0x13);
              uVar39 = uVar26;
            }
            if (*(uint *)(uVar14 + 0x13) < HeapPtr) {
              HeapPtr = *(uint *)(uVar14 + 0x13);
            }
          }
        }
        uVar23 = *(uint16_t *)(uVar14 + 0xb);
        uVar14 = *(uint16_t *)(uVar14 + 9);
        uVar26 = uVar30;
      }
      if (!bVar34) {
        if (uVar26 == 0xffff) {
          bVar34 = ovr_fmFreeAudio();
          if (bVar34) {
            return 1;
          }
          if (audioBusy == '\0') {
                    /* WARNING: Subroutine does not return */
            ovr_stExit();
          }
          return 0;
        }
        uVar37 = 0x39;
        uVar20 = 0x89;
        stshFree();
        HeapPtr = uVar39;
        iVar32 = CONCAT11(uVar20,uVar37);
        uVar33 = (undefined2)(CONCAT13(uVar21,CONCAT12(uVar36,iVar32)) >> 0x10);
        *(undefined2 *)(iVar32 + 0x13) = 0;
        *(undefined2 *)(iVar32 + 0x11) = 0;
      }
    }
    return 1;
  case 1:
    *puVar27 = *puVar27;
    do {
      uVar31 = 0x195d;
      pfVar10 = stshSprite(*(far_t **)(puVar27 + 0x26fe),unaff_SI,(anm_t *)CONCAT11(uVar36,bVar40),
                           (uint16_t)val,SUB41(val >> 0x10,0));
      uVar33 = (undefined2)(val >> 0x10);
      iVar32 = (int)pcVar29 * 0x95 + (int)unaff_DI * 4;
      *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar32) = uVar31;
      *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar32) = pfVar10;
      while( true ) {
        unaff_DI = unaff_DI + 1;
        while (2 < (int)unaff_DI) {
          for (iVar32 = 0; iVar32 < 6; iVar32 = iVar32 + 1) {
            uVar31 = 0x195d;
            if (*(int *)((int)AgntGs[0].prtfls + (int)pcVar29 * 0x95 + iVar32 * 2) != 0) {
              if ((byte)param_1 == 0) {
                pfVar10 = ovr_stshAllocStub();
                iVar17 = (int)pcVar29 * 0x95 + iVar32 * 4;
                uVar22 = 0x195d;
                *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar17) = uVar31;
                *(undefined2 *)((int)AgntGs[0].prts + iVar17) = pfVar10;
                pfVar10 = ovr_stshAllocStub();
                iVar17 = (int)pcVar29 * 0x95 + iVar32 * 4;
                *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar17) = uVar22;
                *(undefined2 *)((int)AgntGs[0].prtpals + iVar17) = pfVar10;
              }
              else {
                uVar31 = 0x195d;
                ovr_grabLbm();
                uVar33 = uVar31;
                ovr_stshUniqueColorsRemap();
                ovr_stshRleType2();
                pcVar11 = ovr_stshStoreFile();
                iVar17 = (int)pcVar29 * 0x95 + iVar32 * 4;
                uVar22 = 0x195d;
                *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar17) = uVar31;
                *(undefined2 *)((int)AgntGs[0].prts + iVar17) = pcVar11;
                puVar15 = ovr_stshWrite();
                iVar17 = (int)pcVar29 * 0x95 + iVar32 * 4;
                *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar17) = uVar22;
                *(undefined2 *)((int)AgntGs[0].prtpals + iVar17) = puVar15;
                ovr_stgFreeTmp();
              }
            }
          }
          uVar16 = *(uint *)((int)AgntGs[0].prts + 4 + (int)pcVar29 * 0x95) |
                   *(uint *)((int)AgntGs[0].prts + 6 + (int)pcVar29 * 0x95);
          if ((uVar16 == 0) &&
             (uVar16 = 0,
             *(int *)((int)AgntGs[0].prts + (int)pcVar29 * 0x95) != 0 ||
             *(int *)((int)AgntGs[0].prts + 2 + (int)pcVar29 * 0x95) != 0)) {
            uVar31 = *(undefined2 *)((int)AgntGs[0].prts + (int)pcVar29 * 0x95);
            *(undefined2 *)((int)AgntGs[0].prts + 6 + (int)pcVar29 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].prts + 2 + (int)pcVar29 * 0x95);
            *(undefined2 *)((int)AgntGs[0].prts + 4 + (int)pcVar29 * 0x95) = uVar31;
            uVar16 = *(uint *)((int)AgntGs[0].prtpals + (int)pcVar29 * 0x95);
            *(undefined2 *)((int)AgntGs[0].prtpals + 6 + (int)pcVar29 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].prtpals + 2 + (int)pcVar29 * 0x95);
            *(uint *)((int)AgntGs[0].prtpals + 4 + (int)pcVar29 * 0x95) = uVar16;
          }
          for (iVar32 = 2; iVar32 < 6; iVar32 = iVar32 + 2) {
            iVar17 = (int)pcVar29 * 0x95 + iVar32 * 4;
            if ((*(int *)((int)AgntGs[0].prts + 4 + iVar17) == 0 &&
                 *(int *)((int)AgntGs[0].prts + 6 + iVar17) == 0) &&
               (iVar17 = (int)pcVar29 * 0x95 + iVar32 * 4,
               *(int *)((int)AgntGs[0].prtfls + 8 + iVar17) != 0 ||
               *(int *)((int)AgntGs[0].prtfls + 10 + iVar17) != 0)) {
              iVar17 = (int)pcVar29 * 0x95 + iVar32 * 4;
              uVar31 = *(undefined2 *)((int)AgntGs[0].prtfls + 8 + iVar17);
              iVar18 = (int)pcVar29 * 0x95 + iVar32 * 4;
              *(undefined2 *)((int)AgntGs[0].prts + 6 + iVar18) =
                   *(undefined2 *)((int)AgntGs[0].prtfls + 10 + iVar17);
              *(undefined2 *)((int)AgntGs[0].prts + 4 + iVar18) = uVar31;
              iVar17 = (int)pcVar29 * 0x95 + iVar32 * 4;
              uVar31 = *(undefined2 *)((int)AgntGs[0].prts + 0x14 + iVar17);
              iVar18 = (int)pcVar29 * 0x95 + iVar32 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 6 + iVar18) =
                   *(undefined2 *)((int)AgntGs[0].prts + 0x16 + iVar17);
              *(undefined2 *)((int)AgntGs[0].prtpals + 4 + iVar18) = uVar31;
            }
            iVar17 = (int)pcVar29 * 0x95 + iVar32 * 4;
            uVar16 = *(uint *)((int)AgntGs[0].prts + iVar17) |
                     *(uint *)((int)AgntGs[0].prts + 2 + iVar17);
            if (uVar16 == 0) {
              iVar17 = (int)pcVar29 * 0x95 + iVar32 * 4;
              if (*(int *)((int)AgntGs[0].prtfls + 4 + iVar17) == 0 &&
                  *(int *)((int)AgntGs[0].prtfls + 6 + iVar17) == 0) {
                uVar16 = 0;
              }
              else {
                iVar17 = (int)pcVar29 * 0x95 + iVar32 * 4;
                uVar31 = *(undefined2 *)((int)AgntGs[0].prtfls + 4 + iVar17);
                iVar18 = (int)pcVar29 * 0x95 + iVar32 * 4;
                *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar18) =
                     *(undefined2 *)((int)AgntGs[0].prtfls + 6 + iVar17);
                *(undefined2 *)((int)AgntGs[0].prts + iVar18) = uVar31;
                iVar17 = (int)pcVar29 * 0x95 + iVar32 * 4;
                uVar16 = *(uint *)((int)AgntGs[0].prts + 0x10 + iVar17);
                iVar18 = (int)pcVar29 * 0x95 + iVar32 * 4;
                *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar18) =
                     *(undefined2 *)((int)AgntGs[0].prts + 0x12 + iVar17);
                *(uint *)((int)AgntGs[0].prtpals + iVar18) = uVar16;
              }
            }
          }
          pcVar29 = pcVar29 + 1;
          if (0x29 < (int)pcVar29) {
            return uVar16;
          }
          uVar31 = 0x195d;
          pfVar10 = stshSprite((far_t *)*(undefined2 *)((int)&AgntGs[0].anms + (int)pcVar29 * 0x95),
                               *(int16_t *)((int)&AgntGs[0].anms + 2 + (int)pcVar29 * 0x95),
                               (anm_t *)(uint)*(byte *)((int)&AgntGs[0].nanims + (int)pcVar29 * 0x95
                                                       ),CONCAT11((char)(uVar16 >> 8),(byte)param_1)
                               ,SUB21(uVar33,0));
          *(undefined2 *)((int)AgntGs[0].sprs + 2 + (int)pcVar29 * 0x95) = uVar31;
          *(undefined2 *)((int)AgntGs[0].sprs + (int)pcVar29 * 0x95) = pfVar10;
          if (*(int *)((int)AgntGs[0].sprfls + 2 + (int)pcVar29 * 0x95) == 0) {
            uVar31 = *(undefined2 *)((int)AgntGs[0].sprs + (int)pcVar29 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 6 + (int)pcVar29 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].sprs + 2 + (int)pcVar29 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 4 + (int)pcVar29 * 0x95) = uVar31;
          }
          else {
            uVar31 = 0x195d;
            pfVar10 = stshSprite((far_t *)*(undefined2 *)
                                           ((int)&AgntGs[0].anms + (int)pcVar29 * 0x95),
                                 *(int16_t *)((int)&AgntGs[0].anms + 2 + (int)pcVar29 * 0x95),
                                 (anm_t *)(uint)*(byte *)((int)&AgntGs[0].nanims +
                                                         (int)pcVar29 * 0x95),
                                 CONCAT11((char)((uint)((int)pcVar29 * 0x95) >> 8),(byte)param_1),
                                 SUB21(uVar33,0));
            *(undefined2 *)((int)AgntGs[0].sprs + 6 + (int)pcVar29 * 0x95) = uVar31;
            *(undefined2 *)((int)AgntGs[0].sprs + 4 + (int)pcVar29 * 0x95) = pfVar10;
          }
          if (*(int *)((int)AgntGs[0].sprfls + 4 + (int)pcVar29 * 0x95) == 0) {
            uVar31 = *(undefined2 *)((int)AgntGs[0].sprs + 4 + (int)pcVar29 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 10 + (int)pcVar29 * 0x95) =
                 *(undefined2 *)((int)AgntGs[0].sprs + 6 + (int)pcVar29 * 0x95);
            *(undefined2 *)((int)AgntGs[0].sprs + 8 + (int)pcVar29 * 0x95) = uVar31;
          }
          else {
            uVar31 = 0x195d;
            pfVar10 = stshSprite((far_t *)*(undefined2 *)
                                           ((int)&AgntGs[0].anms + (int)pcVar29 * 0x95),
                                 *(int16_t *)((int)&AgntGs[0].anms + 2 + (int)pcVar29 * 0x95),
                                 (anm_t *)(uint)*(byte *)((int)&AgntGs[0].nanims +
                                                         (int)pcVar29 * 0x95),
                                 CONCAT11((char)((uint)((int)pcVar29 * 0x95) >> 8),(byte)param_1),
                                 SUB21(uVar33,0));
            *(undefined2 *)((int)AgntGs[0].sprs + 10 + (int)pcVar29 * 0x95) = uVar31;
            *(undefined2 *)((int)AgntGs[0].sprs + 8 + (int)pcVar29 * 0x95) = pfVar10;
          }
          unaff_DI = (char *)0x0;
        }
        iVar32 = (int)pcVar29 * 0x95 + (int)unaff_DI * 2;
        if (*(int *)((int)AgntGs[0].sprfls + 6 + iVar32) != 0) break;
        iVar32 = (int)pcVar29 * 0x95 + (int)unaff_DI * 4;
        uVar31 = *(undefined2 *)((int)AgntGs[0].sprs + iVar32);
        iVar17 = (int)pcVar29 * 0x95 + (int)unaff_DI * 4;
        *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar17) =
             *(undefined2 *)((int)AgntGs[0].sprs + 2 + iVar32);
        *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar17) = uVar31;
      }
      val = CONCAT22(uVar33,CONCAT11((char)((uint)iVar32 >> 8),(byte)param_1));
      bVar40 = *(byte *)((int)&AgntGs[0].nanims + (int)pcVar29 * 0x95);
      uVar36 = 0;
      puVar27 = (undefined1 *)((int)pcVar29 * 0x95);
      unaff_SI = *(uint *)(puVar27 + 0x2700);
    } while( true );
  case 2:
    return uVar14 & 0xff8e;
  case 3:
switchD_4000_4790_caseD_3:
    uVar33 = (undefined2)((ulong)Entities >> 0x10);
    cVar5 = *(char *)((int)&(((entity_t *)Entities)->base).flags32 + uVar14);
    cVar7 = (char)(uVar14 >> 8);
    *(char *)((int)&((entity_t *)Entities)[(int)pcVar29].base.state + 1) = cVar5;
    if (EntityCount <= pcVar29 + 1) {
      if ((cVar5 != '\0') || (cVar7 != '\0')) {
        if ((char)(val >> 0x18) == '\0') {
          ovr_stop_audio();
          CurSfxType3 = 0xff;
          ovr_play_sfx();
        }
        else if (cVar7 == '\0') {
          if (cVar5 != '\0') {
            ovr_play_sfx();
          }
        }
        else {
          ovr_play_sfx();
        }
      }
      GGameState = 0x3d;
      uVar16 = 0x2410;
      if (DebugVerbose != false) {
        uVar16 = 0x2410;
        printf("%d \r");
      }
      ovr_OVC23_55fe_29a2_entry();
      return uVar16;
    }
    uVar16 = 0x24ff;
    ovr_say();
    return uVar16;
  case 4:
    in_CX = (entity_t *)CONCAT11((char)((uint)in_CX >> 8),(char)in_CX + unaff_DI[-0x63b2]);
    do {
      peVar28 = (entity_t *)(puVar27 + (int)in_CX);
      (peVar28->base).y = uVar14;
      (peVar28->base).x = uVar23;
      while( true ) {
        unaff_DI = unaff_DI + 1;
        pcVar29 = pcVar29 + 1;
L_manage_4d05_2d79_2EE8:
        if ((int)(uint)in_stack_0000fff5 <= (int)pcVar29) {
          cVar5 = '@';
          manage_openTalkWindow();
          if (cVar5 != '\x02') goto L_attact_3f0b_1082_11EA;
          if (ScreenMode == '\0') {
            manage_openTalkWindow();
          }
          TextBlitY = 0xc;
          TextBlitX = 0x11;
          if ((byte)param_1 != 0xff) {
            puStackY_28 = (undefined1 *)0x4;
            ovr_ovc45_compute9();
            func_0x0005d3f4();
            puStackY_28 = auStackY_13e;
            uStackY_2a = 0x23f1;
            uStackY_2c = 0x44;
            ovr_stsprintf();
            ovr_blitLabel();
            TextBlitY = TextBlitY + 0xc;
            iVar32 = ovr_font_textWidth();
            TextBlitX = 0x89 - iVar32;
            ovr_blitLabel();
            iVar32 = ovr_font_textWidth();
            uVar23 = 0xd4 - iVar32;
            TextBlitX = uVar23;
            ovr_blitLabel();
            iVar32 = 0;
            while( true ) {
              TextBlitY = TextBlitY + 0xc;
              cVar5 = (char)in_CX;
              if ((int)(uint)in_stack_0000fff5 <= iVar32) break;
              TextBlitX = 0x11;
              if ((iVar32 < 5) || (in_stack_0000fff4 == 0)) {
                ovr_blitLabel();
              }
              else {
                ovr_blitLabel();
              }
              func_0x0005f303();
              ovr_stsprintf();
              iVar17 = ovr_font_textWidth();
              TextBlitX = 0x89 - iVar17;
              ovr_blitLabel();
              ovr_stsprintf();
              iVar17 = ovr_font_textWidth();
              uVar23 = 0xd4 - iVar17;
              TextBlitX = uVar23;
              ovr_blitLabel();
              iVar32 = iVar32 + 1;
            }
            CurSfxType3 = 0x3c;
            uVar33 = ovr_ovc28_usesUiInputText();
            cVar7 = (char)uVar33;
            keyboardInputMode = 0;
            if (((cVar7 != '\0') && (cVar7 != '\x01')) && (cVar7 != -2)) {
              (&stack0xbac4)[(int)unaff_DI] = (&stack0xbac4)[(int)unaff_DI] + cVar5;
              iVar17 = 0x2410;
              do {
                iVar18 = iVar17 * uVar23;
                iVar17 = iVar32;
                if (*(byte *)(iVar32 * 0x34 + 0x22) < *(byte *)(iVar18 + 0x21)) {
                  *(undefined1 *)(iVar32 * 0x34 + 0x21) = *(undefined1 *)(iVar32 * 0x34 + 0x22);
                }
                do {
                  iVar17 = iVar17 + 1;
                  if ((int)(uint)AgntCount <= iVar17) {
                    ovr_audio_panFromX();
                    ovr_play_sfxU();
                    return 1;
                  }
                } while (*(int *)(iVar17 * 0x34 + 0x1b) != *(int *)((uint)param_2 + 0x1b));
                uVar33 = (undefined2)(val >> 0x10);
                if (*(byte *)((int)val + 0x32) < *(byte *)(iVar17 * 0x34 + 0x22)) {
                  *(undefined1 *)(iVar17 * 0x34 + 0x22) = *(undefined1 *)((int)val + 0x32);
                }
                uVar23 = 0x34;
                iVar32 = iVar17;
              } while( true );
            }
            if (cVar7 == -2) {
              Cancelled = 1;
            }
            return 0x2410;
          }
          uVar16 = ovr_blitLabel();
          *pcVar29 = *pcVar29 + (char)(uVar16 >> 8) + ((undefined1 *)0xfff3 < &stack0xffe8);
          *(undefined1 *)((int)&(((entity_t *)*(entity_t **)&Entities)->base).entity + uVar16 + 1) =
               0;
          uVar14 = (int)pcVar29 * 0x37;
          goto switchD_4000_4790_caseD_3;
        }
        if ((4 < (int)pcVar29) && (in_stack_0000fff4 != 0)) break;
        uVar23 = auStackY_96[(int)pcVar29 * 2];
        in_CX = &eStackY_66;
        peVar28 = (entity_t *)(&(in_CX->base).x + (int)unaff_DI * 2);
        (&eStackY_66.base.y)[(int)unaff_DI * 2] = auStackY_96[(int)pcVar29 * 2 + 1];
        (peVar28->base).x = uVar23;
      }
      uVar33 = (undefined2)((ulong)*(undefined4 *)((uint)(byte)param_1 << 2) >> 0x10);
      uVar16 = (uint)*(byte *)((int)*(undefined4 *)((uint)(byte)param_1 << 2) + 0x2f);
      uVar14 = auStackY_11a[(int)pcVar29 * 2 + uVar16 * 8 + 1];
      uVar23 = auStackY_11a[(int)pcVar29 * 2 + uVar16 * 8];
      puVar27 = (undefined1 *)((int)unaff_DI << 2);
      in_CX = &eStackY_66;
    } while( true );
  case 5:
    puVar1 = (uint *)(&stack0xc1dd + (int)unaff_DI);
    uVar16 = *puVar1;
    *puVar1 = *puVar1 - 1;
    if (in_CX == (entity_t *)0x0) {
      in_stack_0000fff5 =
           (in_NT & 1) * '@' | SBORROW2(uVar16,1) * '\b' | (in_IF & 1) * '\x02' | in_TF & 1;
      in_stack_0000fff4 =
           ((int)*puVar1 < 0) * -0x80 | (*puVar1 == 0) * '@' |
           (9 < (bVar38 & 0xf) | in_AF & 1) * '\x10' |
           ((POPCOUNT(*puVar1 & 0xff) & 1U) == 0) * '\x04';
    }
    (&eStackY_66.base.y)[uVar14] = (uint16_t)((char *)"puppetmaker" + 3);
    *(char **)(puVar27 + (int)&eStackY_66) = (char *)"Done";
    (&eStackY_66.base.y)[(int)(unaff_DI + 1) * 2] = (uint16_t)((char *)"puppetmaker" + 3);
    (&eStackY_66.base.x)[(int)(unaff_DI + 1) * 2] = (uint16_t)(char *)"Summary";
    peVar28 = (entity_t *)(&eStackY_66.base.x + (int)(unaff_DI + 2) * 2);
    (&eStackY_66.base.y)[(int)(unaff_DI + 2) * 2] = (uint16_t)((char *)"puppetmaker" + 3);
    (peVar28->base).x = (uint16_t)(char *)"All levels";
    unaff_DI = unaff_DI + 3;
    pcVar29 = (char *)0x0;
    goto L_manage_4d05_2d79_2EE8;
  }
  if ((uVar14 != 0) || ((uint)(*(uint16_t *)((uint8_t *)&(BuildingTypes[0x76]) + 24)) < 0x195d)) {
    uVar16 = (((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
              (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
             (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
    if ((uVar16 < CONCAT11(in_stack_0000fff3,in_stack_0000fff2)) ||
       ((uVar16 <= CONCAT11(in_stack_0000fff3,in_stack_0000fff2) &&
        (((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0] <=
         CONCAT11(in_stack_0000fff1,in_stack_0000fff0))))) {
      unaff_SI = (((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
                  (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                 (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
    }
    else {
      unaff_SI = CONCAT11(in_stack_0000fff3,in_stack_0000fff2);
    }
    uVar20 = (undefined1)unaff_SI;
    uVar19 = (undefined1)(unaff_SI >> 8);
    uVar24 = (uint)StshPtrs[0] - (uint)FMXmsHandle;
    uVar14 = ((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) - (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) - (uint)((uint)StshPtrs[0] < (uint)FMXmsHandle)
    ;
    uVar21 = uVar20;
    uVar37 = uVar19;
    uVar23 = uVar24;
    puVar15 = ovr_mkp();
    ems_memmove1((uint16_t)puVar15,uVar24,uVar23,uVar14,CONCAT11(uVar19,uVar20),
                 CONCAT11(uVar37,uVar21));
    bVar34 = CARRY2((uint)StshPtrs[0],CONCAT11(uVar37,uVar21));
    (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + CONCAT11(uVar37,uVar21);
    (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + unaff_SI + (uint)bVar34;
    uVar16 = uVar14 - CONCAT11(uVar37,uVar21);
    bVar38 = 0;
    in_stack_0000fff2 = 0xcb;
    in_stack_0000fff3 = 0x77;
    puVar15 = LXURSH_at_((uint32_t *)CONCAT11(uVar36,bVar40),val,unaff_BP);
    param_2 = CONCAT22((*(uint16_t *)((uint8_t *)&(param_2) + 2)),(int)puVar15 + (uint)param_2);
    param_1 = CONCAT22(iVar32 + (bVar38 & 0xf),uVar26);
  }
  uVar26 = (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) + (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)
  ;
  if ((uVar26 <= (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) &&
     ((uVar26 != (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) || ((uint)FMXmsHandle + (uint)FMEmsHandle <= (uint)StshPtrs[0])))
     ) {
    in_stack_0000fff2 = (undefined1)(*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2));
    in_stack_0000fff3 = (undefined1)((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) >> 8);
    uVar36 = (undefined1)(uint)StshPtrs[0];
    uVar21 = (undefined1)((uint)StshPtrs[0] >> 8);
    lseek(StshHandles[0],(ulong)(*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)),unaff_SI);
    uVar16 = CONCAT11(uVar21,uVar36);
  }
  iVar32 = CONCAT11(in_stack_0000fff3,in_stack_0000fff2);
  if (uVar16 == 0 && iVar32 == 0) {
    uVar16 = (uint)bVar40 - (*(uint16_t *)((uint8_t *)&(param_2) + 2));
  }
  else {
    uVar36 = (undefined1)param_2;
    uVar21 = (undefined1)(param_2 >> 8);
    iVar17 = StshHandles[0];
    while( true ) {
      if ((iVar32 == 0) && (uVar16 == 0)) goto next_iteration;
      if ((iVar32 != 0) || (0xc000 < uVar16)) {
        uVar16 = 0xc000;
      }
      uVar37 = (undefined1)iVar17;
      uVar20 = (undefined1)((uint)iVar17 >> 8);
      iVar32 = 0x7888;
      uVar26 = read(iVar17,(void *)CONCAT13((char)(uVar16 >> 8),
                                            CONCAT12((char)uVar16,CONCAT11(uVar21,uVar36))),unaff_SI
                   );
      if (uVar26 != CONCAT11(uVar20,uVar37)) break;
      iVar32 = iVar32 + uVar26;
      uVar36 = 0;
      uVar21 = 0x10;
      ovr_mkp();
      uVar16 = CONCAT11(uVar21,uVar36);
      uVar36 = (undefined1)(*(uint16_t *)((uint8_t *)&(param_1) + 2));
      uVar21 = (undefined1)((uint)(*(uint16_t *)((uint8_t *)&(param_1) + 2)) >> 8);
      bVar34 = CARRY2((uint)StshPtrs[0],uVar26);
      (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + uVar26;
      (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + bVar34;
    }
    printf((char *)((long)&BldInstances[0x49].seg + 1));
    ovr_biosReadKey();
next_iteration:
    uVar16 = (uint)bVar40 - (*(uint16_t *)((uint8_t *)&(param_2) + 2));
  }
  return uVar16;
L_attact_3f0b_1082_11EA:
  uVar31 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
  peVar25 = (entity_t *)in_stack_0000ffe2;
  (peVar25->base).target =
       (byte)((int)(uint)*(byte *)((int)&(peVar25->base).owner +
                                  ((int)(uint)(peVar28->base).faction >> 2)) >>
             (((peVar25->base).faction & 3) << 1)) & 3;
  cVar5 = func_0x0004f32d();
  peVar28 = (entity_t *)in_stack_0000ffe2;
  uVar33 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
  if (cVar5 == '\0') {
    (in_stack_0000ffe2->base).x =
         (in_stack_0000ffe2->base).x + (int)*(char *)((peVar28->base).target + 0x885);
    puVar2 = &(peVar28->base).y;
    *puVar2 = *puVar2 + (int)*(char *)((peVar28->base).target + 0x889);
    puVar3 = &(peVar28->base).faction;
    *puVar3 = *puVar3 + 0x1;
  }
  else {
    (peVar28->base).faction = 0x0;
    *(undefined1 *)&(peVar28->base).state = 0;
  }
L_attact_3f0b_1082_1477:
  do {
    cVar5 = '\x01';
    uVar16 = ovr_alignUp4();
    uVar21 = (undefined1)uVar16;
    uVar37 = (undefined1)(uVar16 >> 8);
    uVar16 = ovr_alignUp4();
    if (CONCAT11(uVar37,uVar21) == uVar16) {
      uVar33 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
      peVar28 = (entity_t *)in_stack_0000ffe2;
      if ((peVar28->base).destY == (peVar28->base).y) {
        (peVar28->base).destX = 0;
        (peVar28->base).destY = 0;
        if (*(char *)((int)&(peVar28->base).entity + 3) == -1) {
          uVar41 = CONCAT12(0xff,(int)val);
        }
        else {
          uVar4 = *(undefined4 *)((uint)*(byte *)((int)&(peVar28->base).entity + 3) << 2);
          uVar41 = CONCAT12(*(undefined1 *)((int)uVar4 + 0x89),(int)val);
        }
        val = (ulong)uVar41;
        if ((char)(uVar41 >> 0x10) != -1) {
          for (uVar16 = 0; uVar16 < SquareRecCount; uVar16 = uVar16 + 1) {
            uVar26 = ovr_alignUp4();
            uVar21 = (undefined1)uVar26;
            uVar37 = (undefined1)(uVar26 >> 8);
            uVar26 = ovr_alignUp4();
            if ((CONCAT11(uVar37,uVar21) == uVar26) &&
               (*(uint16_t *)(uVar16 * 0x13 + 2) == (((entity_t *)in_stack_0000ffe2)->base).y)) {
              func_0x0004f930();
              if (*(uint16_t *)(uVar16 * 0x13 + 2) == GfxRndSeed2) {
                uVar16 = ovr_alignUp4();
                uVar21 = (undefined1)uVar16;
                uVar37 = (undefined1)(uVar16 >> 8);
                uVar16 = ovr_alignUp4();
                if (CONCAT11(uVar37,uVar21) == uVar16) {
                  (&stack0xfff2)[(byte)(val >> 0x10)] = 1;
                }
              }
              break;
            }
          }
        }
      }
    }
    cVar7 = '#';
    if (AgntFlag1 != false) {
      uVar33 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
      if ((((in_stack_0000ffe2->base).x < GfxRndSeed - 2U) ||
          (GfxRndSeed + 1U < (in_stack_0000ffe2->base).x)) ||
         ((((entity_t *)in_stack_0000ffe2)->base).y != GfxRndSeed2)) {
        bVar34 = false;
      }
      else {
        bVar34 = true;
      }
      if ((((uint)val < GfxRndSeed - 2U) || (GfxRndSeed + 1U < (uint)val)) ||
         (GfxRndSeed2 != CONCAT11(uVar36,bVar40))) {
        bVar8 = false;
      }
      else {
        bVar8 = true;
      }
      if (bVar8 || bVar34) {
        if (bVar8) {
          if (bVar34) {
            for (cVar9 = func_0x0004f944(); cVar7 = '#', cVar9 != '\0'; cVar9 = cVar9 + -1) {
              cVar7 = '#';
              pcVar29 = ovr_ovc15_textArena();
              if (((uint)pcVar29 & 0xff) == 0) break;
            }
          }
          else {
            cVar9 = (char)((ulong)((((entity_t *)in_stack_0000ffe2)->base).animFrame + 0xf) / 0x10);
            while (cVar35 = cVar9 + -1, cVar9 != '\0') {
              cVar7 = '\"';
              ovr_agnt_usesAgntCount6();
              cVar9 = cVar35;
            }
          }
        }
        else {
          ovr_ovc15_clearVisited();
          cVar9 = (char)((ulong)((((entity_t *)in_stack_0000ffe2)->base).animFrame + 0xf) / 0x10);
          while( true ) {
            cVar7 = '#';
            cVar35 = cVar9 + -1;
            if (cVar9 == '\0') break;
            ovr_ovc15_textArena();
            cVar9 = cVar35;
          }
        }
      }
    }
    do {
      unaff_DI = unaff_DI + 1;
      if (EntityCount <= unaff_DI) {
        GGameState = 0x3c;
        cVar9 = cVar7;
        if (DebugVerbose != false) {
          cVar9 = '\x10';
          printf("%d %d %d  \r");
          cVar5 = cVar7;
        }
        func_0x0004fcda();
        GGameState = 0x3d;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
          cVar5 = cVar9;
        }
        ovr_OVC23_55fe_29a2_entry();
        GGameState = 0xc;
        if (DebugVerbose != false) {
          cVar5 = '#';
          printf("%d %d %d  \r");
        }
        ovr_ovc24_removeOtherEntities();
        GGameState = 0x1f;
        if (cVar5 != '\0') {
          ovr_constr_usesBlitRect();
          GGameState = 0x13;
        }
        func_0x0004f68f();
        GGameState = 0x1d;
        for (iVar32 = 0; iVar32 < 5; iVar32 = iVar32 + 1) {
          if ((&stack0xfff2)[iVar32] != '\0') {
            ovr_ovc41_usesMiceBlitRect();
          }
        }
        GGameState = 0xd;
        if (DebugVerbose != false) {
          printf("%d %d %d  \r");
        }
        ovr_ovc24_checkStrongholds();
        GGameState = 0xe;
        mapDirty = 1;
        return 0x2410;
      }
      in_stack_0000ffe2 =
           (entity_t *)CONCAT22((int)((ulong)Entities >> 0x10),(entity_t *)Entities + (int)unaff_DI)
      ;
      uVar16 = ovr_alignUp4();
      uVar36 = (undefined1)uVar16;
      uVar21 = (undefined1)(uVar16 >> 8);
      cVar7 = '#';
      uVar16 = ovr_alignUp4();
      if ((CONCAT11(uVar21,uVar36) == uVar16) &&
         (uVar33 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10),
         (((entity_t *)in_stack_0000ffe2)->base).destY == (((entity_t *)in_stack_0000ffe2)->base).y)
         ) {
        cVar5 = '#';
        func_0x0004fb8e();
      }
      uVar33 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
      peVar28 = (entity_t *)in_stack_0000ffe2;
    } while (((peVar28->base).destX == 0 && (peVar28->base).destY == 0) ||
            (*(char *)((int)&(peVar28->base).entity + 1) != '\0'));
    val = (ulong)(in_stack_0000ffe2->base).x;
    uVar23 = (peVar28->base).y;
    bVar38 = (byte)uVar23;
    uVar21 = (undefined1)(uVar23 >> 8);
    bVar40 = bVar38;
    uVar36 = uVar21;
    if ((peVar28->base).faction < (byte)(peVar28->base).state) goto L_attact_3f0b_1082_11EA;
    ovr_ovc07_signum();
    cVar5 = 'g';
    uVar20 = 3;
    uVar23 = ovr_ovc07_signum();
    bVar6 = (byte)uVar23;
    uVar37 = (undefined1)(uVar23 >> 8);
    if (CONCAT11(uVar20,cVar5) == 0) {
L_attact_3f0b_1082_130A:
      bVar40 = bVar38;
      uVar36 = uVar21;
      if (CONCAT11(uVar37,bVar6) != 0) {
        uVar20 = (undefined1)(uVar23 >> 8);
        cVar5 = bVar6 + 1;
        bVar6 = func_0x0004f412();
        uVar23 = (uint16_t)bVar6;
        if (uVar23 == 0) {
          uVar33 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
          puVar2 = &(((entity_t *)in_stack_0000ffe2)->base).y;
          *puVar2 = *puVar2 + CONCAT11(uVar21,bVar38);
          (((entity_t *)in_stack_0000ffe2)->base).target = bVar38 + 1;
          goto L_attact_3f0b_1082_1477;
        }
      }
      if (CONCAT11(uVar20,cVar5) != 0) {
        uVar21 = (undefined1)(uVar23 >> 8);
        cVar5 = '\x02' - cVar5;
        cVar7 = func_0x0004f412();
        if (cVar7 == '\0') {
          (in_stack_0000ffe2->base).x = (in_stack_0000ffe2->base).x + CONCAT11(uVar21,cVar5);
          (((entity_t *)in_stack_0000ffe2)->base).target = 0x2 - cVar5;
          goto L_attact_3f0b_1082_1477;
        }
      }
      uVar16 = ovr_ovc26_usesStExit();
      if ((char)uVar16 == '\0') {
        uVar16 = ovr_ovc26_usesRandBelow();
        if (((uVar16 & 0xff) == 0) &&
           (*(char *)((int)(char **)GMenuStrings +
                     (uint)(((entity_t *)in_stack_0000ffe2)->base).gindex * 0x95 + 0x1f) == '\0')) {
          func_0x0004fb8e();
        }
      }
      else {
        uVar33 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
        peVar28 = (entity_t *)in_stack_0000ffe2;
        (peVar28->base).target =
             (byte)((int)(uint)*(byte *)((int)&(peVar28->base).owner +
                                        ((int)(uint)(peVar28->base).faction >> 2)) >>
                   (((peVar28->base).faction & 3) << 1)) & 3;
        cVar5 = func_0x0004f32d();
        if (cVar5 == '\0') {
          uVar33 = (undefined2)((ulong)in_stack_0000ffe2 >> 0x10);
          peVar28 = (entity_t *)in_stack_0000ffe2;
          (in_stack_0000ffe2->base).x =
               (in_stack_0000ffe2->base).x + (int)*(char *)((peVar28->base).target + 0x885);
          puVar2 = &(peVar28->base).y;
          *puVar2 = *puVar2 + (int)*(char *)((peVar28->base).target + 0x889);
          puVar3 = &(peVar28->base).faction;
          *puVar3 = *puVar3 + 0x1;
        }
      }
      goto L_attact_3f0b_1082_1477;
    }
    cVar5 = 'z';
    uVar20 = 3;
    uVar23 = ovr_randBelow();
    uVar19 = (undefined1)(uVar23 >> 8);
    if ((char)uVar23 == '\0') goto L_attact_3f0b_1082_130A;
    cVar5 = '\x02' - cVar5;
    bVar40 = bVar38;
    uVar36 = uVar21;
    bVar6 = func_0x0004f412();
    uVar23 = (uint16_t)bVar6;
    bVar6 = bVar38;
    uVar37 = uVar21;
    uVar20 = uVar19;
    bVar38 = bVar40;
    uVar21 = uVar36;
    if (uVar23 != 0) goto L_attact_3f0b_1082_130A;
    (in_stack_0000ffe2->base).x = (in_stack_0000ffe2->base).x + CONCAT11(uVar19,cVar5);
    (((entity_t *)in_stack_0000ffe2)->base).target = 0x2 - cVar5;
  } while( true );
}



/* 4207:288b */

/* [R4] calls ovr_alignUp4 */

bool __cdecl16far ovc15_usesAlignUp42(void...)

{
  uint uVar1;
  uint uVar2;
  int unaff_DI;
  byte bStack_3;
  
  uVar2 = 0;
  uVar1 = ovr_alignUp4(unaff_DI,GfxRndSeed);
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
    CrossBlitX = *(undefined2 *)((uint)SelectedAgent * 0x34 + 0x26);
    CrossBlitY = *(int *)((uint)SelectedAgent * 0x34 + 0x28) + -0x10;
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
    if ((*(uint *)(iVar1 * 0x34 + 0x26) < uVar2) ||
       ((*(uint *)(iVar1 * 0x34 + 0x26) == uVar2 && (*(uint *)(iVar1 * 0x34 + 0x28) < uVar3)))) {
      cStack_3 = (char)iVar1;
      uVar2 = *(uint *)(iVar1 * 0x34 + 0x26);
      uVar3 = *(uint *)(iVar1 * 0x34 + 0x28);
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
    if ((uVar2 < *(uint *)(iVar1 * 0x34 + 0x26)) ||
       ((*(uint *)(iVar1 * 0x34 + 0x26) == uVar2 && (uVar3 < *(uint *)(iVar1 * 0x34 + 0x28))))) {
      cStack_3 = (char)iVar1;
      uVar2 = *(uint *)(iVar1 * 0x34 + 0x26);
      uVar3 = *(uint *)(iVar1 * 0x34 + 0x28);
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
        ((*(uint *)((uint)SelectedAgent * 0x34 + 0x26) < *(uint *)(uVar1 * 0x34 + 0x26) ||
         ((*(int *)((uint)SelectedAgent * 0x34 + 0x26) == *(int *)(uVar1 * 0x34 + 0x26) &&
          (*(uint *)((uint)SelectedAgent * 0x34 + 0x28) < *(uint *)(uVar1 * 0x34 + 0x28))))))) &&
       ((*(uint *)(uVar1 * 0x34 + 0x26) < uVar2 ||
        ((*(uint *)(uVar1 * 0x34 + 0x26) == uVar2 && (*(uint *)(uVar1 * 0x34 + 0x28) < uVar3)))))) {
      bStack_3 = (byte)uVar1;
      uVar2 = *(uint *)(uVar1 * 0x34 + 0x26);
      uVar3 = *(uint *)(uVar1 * 0x34 + 0x28);
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
        ((*(uint *)(uVar1 * 0x34 + 0x26) < *(uint *)((uint)SelectedAgent * 0x34 + 0x26) ||
         ((*(int *)((uint)SelectedAgent * 0x34 + 0x26) == *(int *)(uVar1 * 0x34 + 0x26) &&
          (*(uint *)(uVar1 * 0x34 + 0x28) < *(uint *)((uint)SelectedAgent * 0x34 + 0x28))))))) &&
       ((uVar2 < *(uint *)(uVar1 * 0x34 + 0x26) ||
        ((*(uint *)(uVar1 * 0x34 + 0x26) == uVar2 && (uVar3 < *(uint *)(uVar1 * 0x34 + 0x28))))))) {
      bStack_3 = (byte)uVar1;
      uVar2 = *(uint *)(uVar1 * 0x34 + 0x26);
      uVar3 = *(uint *)(uVar1 * 0x34 + 0x28);
    }
  }
  if (bStack_3 != 0xff) {
    SelectedAgent = bStack_3;
  }
  return bStack_3 != 0xff;
}



/* 4207:2d75 */

/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc15_usesRandBelow2(void)

{
  uint16_t uVar1;
  uint uVar2;
  entity_t *peVar3;
  uint uVar4;
  uint16_t unaff_DI;
  undefined2 uVar5;
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
    uVar1 = ovr_randBelow(unaff_DI,EntityCount);
    uVar4 = uVar1 & 0xff;
    do {
      uVar5 = (undefined2)((ulong)Entities >> 0x10);
      peVar3 = (entity_t *)Entities;
      if ((*(byte *)((int)&peVar3[uVar4].base.entity + 3) == bStack_9) &&
         (uVar2 = ovr_ovc23_isCursorAt(peVar3[uVar4].base.y,unaff_DI,((peVar3 + uVar4)->base).x),
         (uVar2 & 0xff) == 0)) {
        return uVar4;
      }
      uVar4 = uVar4 + 1;
      if (EntityCount <= uVar4) {
        uVar4 = 0;
      }
    } while (uVar4 != (uVar1 & 0xff));
  }
  if ((bStack_8 != 0xff) && (0x1d < uStack_4)) {
    uVar1 = ovr_randBelow(unaff_DI,EntityCount);
    uVar4 = uVar1 & 0xff;
    do {
      uVar5 = (undefined2)((ulong)Entities >> 0x10);
      peVar3 = (entity_t *)Entities;
      if (((*(byte *)((int)&peVar3[uVar4].base.entity + 3) == bStack_8) &&
          (uVar2 = ovr_ovc23_isCursorAt(peVar3[uVar4].base.y,unaff_DI,((peVar3 + uVar4)->base).x),
          (uVar2 & 0xff) == 0)) &&
         ((*(byte *)((int)&((entity_t *)Entities)[uVar4].base.flags32 + 1) & 3) == 0)) {
        return uVar4;
      }
      uVar4 = uVar4 + 1;
      if (EntityCount <= uVar4) {
        uVar4 = 0;
      }
    } while (uVar4 != (uVar1 & 0xff));
  }
  uVar1 = ovr_randBelow(unaff_DI,EntityCount);
  return uVar1 & 0xff;
}


