/*
 * ovc18.c - recovered from STRONG.EXE
 * memory block: OVC18
 * range: 48ac:0000 - 48ac:150f
 * functions: 9
 */
#include "recovered.h"


/* 48ac:0000 */

void __cdecl16far OVC18_48ac_0000(void)

{
  far_t gfx;
  
  gfx.seg = DAT_2000_cac7;
  gfx.ofs = DAT_2000_cac5;
  ovr_blitLoadRleGfx(gfx,(far_t)0xa000c306);
  DAT_2000_d1ae = 1;
  return;
}



/* 48ac:0027 */

void __cdecl16far OVC18_48ac_0027(void)

{
  far_t gfx;
  
  if (!GameRunning) {
    gfx.seg = DAT_2000_d1aa;
    gfx.ofs = DAT_2000_d1a8;
    ovr_blitLoadRleGfx(gfx,(far_t)0xa000c306);
  }
  return;
}



/* 48ac:0051 */

void __cdecl16far OVC18_48ac_0051(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined2 unaff_SS;
  char local_8 [2];
  char *pcStack_6;
  undefined2 uStack_4;
  
  DAT_2000_d1ae = 0;
  if ((DAT_2410_45b8 != '\0') || (GameRunning)) {
    DAT_2410_45b8 = '\0';
  }
  else {
    _fmemset((char *)CONCAT22(unaff_SS,local_8),0,2);
    for (iVar4 = 0; iVar4 < (int)(uint)DAT_2000_d1e6; iVar4 = iVar4 + 1) {
      if (((*(char *)((int)*(undefined4 *)(iVar4 << 2) + 0x3d) != '\0') &&
          (local_8[*(byte *)((int)*(undefined4 *)(iVar4 << 2) + 0x3f)] =
                local_8[*(byte *)((int)*(undefined4 *)(iVar4 << 2) + 0x3f)] + '\x01',
          *(int *)((int)*(undefined4 *)(iVar4 << 2) + 0x39) == GfxRndSeed)) &&
         (*(int *)((int)*(undefined4 *)(iVar4 << 2) + 0x3b) == GfxRndSeed2)) {
        cVar1 = ovr_draw_2e25_15d6();
        if (cVar1 == '\0') {
          return;
        }
        uStack_4 = ((undefined2 *)(iVar4 * 4))[1];
        pcVar3 = (char *)*(undefined2 *)(iVar4 * 4);
        pcStack_6 = pcVar3;
        if (GameRunning == false) {
          pcVar2 = ovr_fmVsprintf((char *)"View %s.",pcVar3);
          ovr_say((char *)CONCAT22(pcVar3,pcVar2));
        }
        OVC18_48ac_0000();
        return;
      }
    }
    if (DAT_2000_d1e4 != 0) {
      uStack_4 = *(undefined2 *)((uint)DAT_2000_d1e4 * 4 + -2);
      pcVar3 = (char *)*(undefined2 *)((uint)DAT_2000_d1e4 * 4 + -4);
      pcStack_6 = pcVar3;
      cVar1 = OVC18_48ac_1092();
      if (cVar1 == '\0') {
        pcVar2 = ovr_fmVsprintf((char *)"View %s. (Cannot place)",pcStack_6);
        ovr_say((char *)CONCAT22(pcVar3,pcVar2));
      }
      else {
        pcVar2 = ovr_fmVsprintf((char *)"Place %s.",pcStack_6);
        ovr_say((char *)CONCAT22(pcVar3,pcVar2));
      }
      DAT_2000_d1ae = 1;
      OVC18_48ac_0000();
      return;
    }
    if (DAT_2000_d1e5 < DAT_2000_d1e3) {
      if (GameRunning == false) {
        if (DAT_2000_d1e5 == 0) {
          ovr_say("Create baron or baroness.");
        }
        else {
          ovr_say("Create party member.");
        }
      }
      DAT_2000_d1ae = 1;
      OVC18_48ac_0000();
      return;
    }
  }
  OVC18_48ac_0027();
  return;
}



/* 48ac:0251 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint8_t * __cdecl16far
OVC18_48ac_0251(uint8_t *param_1,undefined4 param_2,uint8_t *param_3,byte param_4,char param_5)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  uint16_t uVar6;
  uint8_t *puVar7;
  int iVar8;
  uint8_t *puVar9;
  uint8_t *puVar10;
  char *unaff_SI;
  uint uVar11;
  char *unaff_DI;
  char *txt;
  far_t fVar12;
  char acStackY_56 [46];
  uint8_t *puStackY_28;
  undefined2 uStackY_26;
  undefined4 uStackY_24;
  char *pcStackY_20;
  uint16_t uVar13;
  char cVar15;
  uint8_t *puVar14;
  uint8_t *in_stack_0000ffe6;
  uint8_t *in_stack_0000ffea;
  uint8_t *in_stack_0000ffee;
  undefined2 uVar16;
  int iVar17;
  undefined2 in_stack_0000fffc;
  
  bVar2 = *(byte *)((int)*(undefined4 *)((uint)param_4 << 2) + 0x3e);
  puVar7 = (uint8_t *)CONCAT11((char)((uint)in_stack_0000fffc >> 8),bVar2);
  iVar8 = 0x195d;
  if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].seg + 1 + (uint)bVar2 * 0x95) & 0x800) == 0) {
    puVar7 = (uint8_t *)ovr_OVC15_4207_10a3();
  }
  else {
    iVar17 = 5;
    uVar6 = ovr_randBelow(5);
    puVar10 = (uint8_t *)(uVar6 & 0xff);
    puVar9 = (uint8_t *)param_1;
    pcVar4 = (char *)0x0;
    switch(puVar10) {
    case (uint8_t *)0x0:
      do {
        cVar15 = (char)((ulong)in_stack_0000ffe6 >> 0x10);
        if (199 < iVar17 + (uint)*(byte *)((int)param_2 + (int)puVar10 * iVar8 + 10)) {
          unaff_SI = (char *)(*(int *)((int)param_2 + (int)puVar9 * 0x1e + 3) %
                             (int)(uint)*(byte *)((int)param_2 + (int)puVar9 * 0x1e + 10));
          puVar7 = puVar7 + *(byte *)((int)param_2 + (int)puVar9 * 0x1e + 9);
          unaff_DI = unaff_DI + *(byte *)((int)param_2 + (int)puVar9 * 0x1e + 9);
          in_stack_0000ffea =
               (uint8_t *)
               CONCAT22((int)((ulong)in_stack_0000ffea >> 0x10),
                        (uint8_t *)in_stack_0000ffea +
                        *(byte *)((int)param_2 + (int)puVar9 * 0x1e + 9));
          cVar15 = cVar15 + *(char *)((int)param_2 + (int)puVar9 * 0x1e + 9);
        }
        puVar10 = puVar9;
        for (puVar14 = (uint8_t *)
                       CONCAT22((int)((ulong)in_stack_0000ffea >> 0x10) + 1,
                                (uint8_t *)in_stack_0000ffea);
            (uint)*(byte *)((int)param_2 + (int)puVar10 * 0x1e + 0x1b) <=
            (uint)((ulong)puVar14 >> 0x10); puVar14 = (uint8_t *)((ulong)puVar14 & 0xffff)) {
          if ((uint8_t *)in_stack_0000ffee != (uint8_t *)0x0 ||
              (int)((ulong)in_stack_0000ffee >> 0x10) != 0) {
            *in_stack_0000ffee = cVar15 - (char)puVar14;
          }
          puVar10 = puVar10 + 1;
          if ((param_3 <= puVar10) || (*(char *)((int)param_2 + (int)puVar10 * 0x1e + 0x1b) == '\0')
             ) {
            return puStackY_28;
          }
          uVar11 = (uint)*(byte *)((int)param_2 + (int)puVar10 * 0x1e);
          uStackY_24 = (uint16_t *)CONCAT22(uStackY_26,puStackY_28 + uVar11 * 4 + 0x58);
          *(int *)((int)(puStackY_28 + uVar11 * 4) + 2) = param_2._2_2_;
          *(int *)(puStackY_28 + uVar11 * 4) = (int)param_2 + (int)puVar10 * 0x1e;
          puVar7 = (uint8_t *)*(undefined2 *)((int)param_2 + (int)puVar10 * 0x1e + 1);
          unaff_SI = (char *)*(int *)((int)param_2 + (int)puVar10 * 0x1e + 3);
          unaff_DI = (char *)*(uint16_t *)((int)param_2 + (int)puVar10 * 0x1e + 5);
          if (*(int *)((int)param_2 + (int)puVar10 * 0x1e + 7) - (int)unaff_SI < 0) {
                    /* WARNING: Subroutine does not return */
            ovr_stExit(0x33);
          }
          in_stack_0000ffee = (uint8_t *)0x0;
        }
        iVar17 = 0x15;
        in_stack_0000ffee = (uint8_t *)CONCAT22(unaff_SI,puVar7);
        in_stack_0000ffe6 = (uint8_t *)(ZEXT24(pcVar4) << 0x10);
        in_stack_0000ffea = param_1;
        _pcStackY_20 = ovr_stshRleSub(param_1,(uint16_t)puVar7,(uint16_t)unaff_SI,(uint16_t)unaff_DI
                                      ,0x15,21);
        uVar6 = pcStackY_20;
        *(undefined1 *)(uVar6 + 6) = 2;
        *(undefined2 *)(uVar6 + 7) = *(undefined2 *)((int)param_2 + (int)puVar10 * 0x1e + 0xb);
        *(undefined2 *)(uVar6 + 9) = *(undefined2 *)((int)param_2 + (int)puVar10 * 0x1e + 0xd);
        ((uint16_t *)uStackY_24)[1] = uVar13;
        *uStackY_24 = uVar6;
        uStackY_24 = (uint16_t *)CONCAT22(uVar13,(uint16_t *)(uVar6 + 1));
        if ((*(byte *)((int)param_2 + (int)puVar10 * 0x1e + 0x1c) & 1) == 0) {
          *(undefined1 *)(uVar6 + 5) = *(undefined1 *)((int)param_2 + (int)puVar10 * 0x1e + 0xf);
        }
        else {
          iVar8 = iVar17 * 0x140 + 0x140;
          uVar16 = (undefined2)((ulong)in_stack_0000ffe6 >> 0x10);
          if ((int)((ulong)in_stack_0000ffea >> 0x10) == 0) {
            uVar11 = 0;
            in_stack_0000ffe6 = (uint8_t *)CONCAT22(uVar16,puVar7);
            while (uVar11 < 2) {
              puVar9 = (uint8_t *)in_stack_0000ffe6;
              if (unaff_DI + iVar8 < puVar9) {
                    /* WARNING: Subroutine does not return */
                ovr_stExit(9);
              }
              if (((uint8_t *)param_1)[(int)(puVar9 + iVar8)] == 0xfe) {
                if (uVar11 == 0) {
                  in_stack_0000ffea =
                       (uint8_t *)CONCAT22((int)((ulong)in_stack_0000ffea >> 0x10),puVar9);
                }
                else {
                  in_stack_0000ffe6 = (uint8_t *)CONCAT22(puVar9,puVar9);
                }
                uVar11 = uVar11 + 1;
              }
              in_stack_0000ffe6 =
                   (uint8_t *)
                   CONCAT22((int)((ulong)in_stack_0000ffe6 >> 0x10),(uint8_t *)in_stack_0000ffe6 + 1
                           );
            }
            in_stack_0000ffee = (uint8_t *)CONCAT22(uVar13,(uint8_t *)(uVar6 + 5));
          }
          else {
            puVar14 = (uint8_t *)CONCAT22(uVar16,puVar7);
            while (puVar9 = (uint8_t *)puVar14, ((uint8_t *)param_1)[(int)(puVar9 + iVar8)] != 0xfe)
            {
              if (unaff_DI + iVar8 < puVar9) {
                    /* WARNING: Subroutine does not return */
                ovr_stExit(9);
              }
              puVar14 = (uint8_t *)CONCAT22((int)((ulong)puVar14 >> 0x10),puVar9 + 1);
            }
            *(char *)(uVar6 + 5) = (char)((ulong)puVar14 >> 0x10) - (char)puVar14;
            in_stack_0000ffe6 = (uint8_t *)CONCAT22(puVar9,puVar9);
          }
        }
        *(undefined1 *)_pcStackY_20 = 4;
        *(undefined2 *)(uVar6 + 3) = 0;
        *(undefined2 *)(uVar6 + 1) = 0;
        unaff_SI = unaff_SI + *(byte *)((int)param_2 + (int)puVar10 * 0x1e + 10);
        iVar8 = 0x1e;
        puVar9 = puVar10;
        pcVar4 = (char *)"bath house" + 10;
      } while( true );
    case (uint8_t *)0x1:
      uVar1 = in(iVar8);
      *param_1._2_2_ = uVar1;
      far_t_2000_d098 = stshStoreFile(unaff_DI,(uint16_t)puVar7);
      fVar12 = stshStoreFile((char *)"cmidpak.com",1);
      _DAT_2000_d096 = fVar12.seg;
      DAT_2000_d094 = fVar12.ofs;
      fVar12 = stshStoreFile((char *)"ibmsnd.com",1);
      DAT_2000_d0ca = fVar12.seg;
      DAT_2000_d0c8 = fVar12.ofs;
      fVar12 = stshStoreFile((char *)"sblaster.com",1);
      DAT_2000_d0ce = fVar12.seg;
      DAT_2000_d0cc = fVar12.ofs;
      DAT_2000_d0d2 = 0;
      DAT_2000_d0d0 = 0;
      fVar12 = stshStoreFile((char *)"fibmbak.com",1);
      DAT_2000_d0d6 = fVar12.seg;
      DAT_2000_d0d4 = fVar12.ofs;
      fVar12 = stshStoreFile((char *)"sbpro.com",1);
      DAT_2000_d0da = fVar12.seg;
      DAT_2000_d0d8 = fVar12.ofs;
      DAT_2000_d0dc = DAT_2000_d0d8;
      DAT_2000_d0de = DAT_2000_d0da;
      fVar12 = stshStoreFile((char *)"paudio.com",1);
      DAT_2000_d0e2 = fVar12.seg;
      DAT_2000_d0e0 = fVar12.ofs;
      DAT_2000_d0e6 = DAT_2000_d0ce;
      DAT_2000_d0e4 = DAT_2000_d0cc;
      fVar12 = stshStoreFile((char *)"adlib.com",1);
      DAT_2000_d0ea = fVar12.seg;
      DAT_2000_d0e8 = fVar12.ofs;
      fVar12 = stshStoreFile((char *)"adlibg.com",1);
      DAT_2000_d0ee = fVar12.seg;
      DAT_2000_d0ec = fVar12.ofs;
      DAT_2000_d0f2 = 0;
      DAT_2000_d0f0 = 0;
      DAT_2000_d09e = 0;
      DAT_2000_d09c = 0;
      fVar12 = stshStoreFile((char *)"sbfm.adv",1);
      DAT_2000_d0a2 = fVar12.seg;
      DAT_2000_d0a0 = fVar12.ofs;
      DAT_2000_d0a6 = 0;
      DAT_2000_d0a4 = 0;
      DAT_2000_d0aa = 0;
      DAT_2000_d0a8 = 0;
      fVar12 = stshStoreFile((char *)"sbp2fm.adv",1);
      DAT_2000_d0ae = fVar12.seg;
      DAT_2000_d0ac = fVar12.ofs;
      fVar12 = stshStoreFile((char *)"sbp1fm.adv",1);
      DAT_2000_d0b2 = fVar12.seg;
      DAT_2000_d0b0 = fVar12.ofs;
      fVar12 = stshStoreFile((char *)"pasfm.adv",1);
      DAT_2000_d0b6 = fVar12.seg;
      DAT_2000_d0b4 = fVar12.ofs;
      fVar12 = stshStoreFile((char *)"pasopl.adv",1);
      DAT_2000_d0ba = fVar12.seg;
      DAT_2000_d0b8 = fVar12.ofs;
      fVar12 = stshStoreFile((char *)"adlib.adv",1);
      DAT_2000_d0be = fVar12.seg;
      DAT_2000_d0bc = fVar12.ofs;
      fVar12 = stshStoreFile((char *)"adlibg.adv",1);
      DAT_2000_d0c2 = fVar12.seg;
      DAT_2000_d0c0 = fVar12.ofs;
      fVar12 = stshStoreFile((char *)"mt32mpu.adv",1);
      DAT_2000_d0c6 = fVar12.seg;
      DAT_2000_d0c4 = (uint8_t *)fVar12.ofs;
      return (uint8_t *)fVar12.ofs;
    case (uint8_t *)0x2:
      iVar8 = ovr_OVC23_55fe_2da3();
      if (iVar8 < 0) {
        ovr_drawTextAt("You cannot attract units to this location.",0xa000);
        puVar7 = (uint8_t *)((char *)"puppetmaker" + 3);
        ((uint8_t *)param_1)[-0x6f7e] = 0x0;
      }
      else {
        pcVar4 = (char *)func_0x0004f501();
        DAT_2000_d114 = pcVar4;
        if (pcVar4 < unaff_SI) {
          ((uint8_t *)param_1)[-0x6f7e] = (uint8_t)pcVar4;
          unaff_SI = pcVar4;
        }
        puVar5 = (undefined4 *)(((uint)puVar7 & 0xff) << 2);
        uVar3 = *puVar5;
        cVar15 = *(char *)((int)uVar3 + 0x2f);
        puVar7 = (uint8_t *)CONCAT11((char)((uint)puVar5 >> 8),cVar15);
        if (cVar15 != -1) {
          uVar16 = 0xa000;
          ovr_OVC41_6a8f_0000();
          _pcStackY_20 = (far_t)CONCAT22(acStackY_56,(char *)"builder\'s hall" + 8);
          uStackY_24 = (uint16_t *)CONCAT22(0xad0,(uint16_t *)uStackY_24);
          txt = ovr_stsprintf(acStackY_56,"Attracting %d of a possible %d %s%s to this location.",
                              unaff_SI);
          puVar7 = (uint8_t *)ovr_drawTextAt(txt,uVar16);
        }
      }
      return puVar7;
    case (uint8_t *)0x3:
      ((int *)StshHandles)[(int)(uint8_t *)param_1] = (int)puVar10;
      *(undefined2 *)((int)(long *)StshPtrs + (int)(uint8_t *)param_1 * 4 + 2) = 0;
      *(undefined2 *)((long *)StshPtrs + (int)(uint8_t *)param_1) = 0;
      return (uint8_t *)param_1;
    case "Borland C++ - Copyright 1991 Borland Intl.":
      smm_restore_state();
      return puVar10;
    default:
      if (param_5 == '\x02') {
        puVar7 = (uint8_t *)ovr_OVC15_4207_10a3();
      }
      else {
        puVar7 = (uint8_t *)ovr_OVC15_4207_10a3();
      }
    }
  }
  return puVar7;
}



/* 48ac:0382 */

char * __cdecl16far
OVC18_48ac_0382(far_t param_1,int *param_2,int *param_3,undefined2 param_4,undefined2 param_5,
               int *param_6,int *param_7,int *param_8,int *param_9)

{
  int *piVar1;
  byte bVar2;
  undefined2 uVar3;
  DW sz;
  uint16_t uVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  undefined2 uVar10;
  char *pcVar11;
  uint in_CX;
  uint uVar12;
  int iVar13;
  uint uVar14;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  int *piVar15;
  undefined2 uVar16;
  undefined2 unaff_SS;
  bool bVar17;
  far_t fVar18;
  far_t ptr_base;
  char *pcVar19;
  ulong b;
  char acStackY_f6 [120];
  char acStackY_7e [92];
  undefined2 *puStackY_22;
  char *pcStackY_20;
  char *pcStackY_1e;
  undefined1 in_stack_0000ffef;
  undefined1 uVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  undefined1 uVar23;
  undefined1 uStack_4;
  undefined1 uStack_3;
  
  pcVar11 = (char *)"sbpro.com" + 6;
  uVar4 = param_1.seg;
  bVar6 = (byte)param_1.ofs;
  iVar9 = ((int *)((uint)(byte)param_1.ofs * 4))[1];
  iVar13 = *(int *)((uint)(byte)param_1.ofs * 4);
  uVar22 = (undefined1)iVar9;
  uVar23 = (undefined1)((uint)iVar9 >> 8);
  uVar20 = (undefined1)iVar13;
  uVar21 = (undefined1)((uint)iVar13 >> 8);
  uVar10 = *(undefined2 *)(iVar13 + 0x39);
  uVar3 = *(undefined2 *)(iVar13 + 0x3b);
  uVar16 = (undefined2)(CONCAT13(uVar23,CONCAT12(uVar22,iVar13)) >> 0x10);
  uVar7 = (uint)*(byte *)(iVar13 + 0x2f);
  pcStackY_1e = (char *)uVar10;
  if (uVar7 == 4) {
    pcStackY_20 = (char *)"sbpro.com" + 6;
    pcVar11 = (char *)"jeweler\'s shop" + 3;
    puStackY_22 = (undefined2 *)&DAT_2000_d0ca;
    ovr_OVC15_4207_10a3();
  }
  else if (uVar7 < 5) {
    if (uVar7 < 4) {
      bVar17 = uVar7 == 0;
      piVar15 = (int *)param_2;
      switch(uVar7) {
      case 1:
        uVar14 = *(uint *)(uVar7 * 2 + 0xc);
        uVar12 = uVar14 + 0x14;
        iVar9 = uVar7 + (0xffeb < uVar14);
        if (StshCount < 0xd93) {
          b = (ulong)StshCount;
          StshCount = StshCount + 1;
          fVar18 = (far_t)LXMUL_at_(0x15,b);
          ptr_base.seg = StshCtPtr.seg;
          ptr_base.ofs = StshCtPtr.ofs;
          fVar18 = PADD_at_(ptr_base,fVar18);
          pcVar19 = (char *)ovr_mkp(fVar18.ofs,fVar18.seg);
          pcVar11 = (char *)pcVar19;
          uVar10 = (undefined2)((ulong)pcVar19 >> 0x10);
          *(int *)(pcVar11 + 7) = iVar9;
          *(uint *)(pcVar11 + 5) = uVar12;
          *pcVar19 = '\0';
          uVar4 = StshCtOfs.lo;
          *(uint16_t *)(pcVar11 + 3) = StshCtOfs.hi;
          *(uint16_t *)(pcVar11 + 1) = uVar4;
          (pcVar11 + 0x13)[0] = '\0';
          (pcVar11 + 0x13)[1] = '\0';
          (pcVar11 + 0x11)[0] = '\0';
          (pcVar11 + 0x11)[1] = '\0';
          bVar17 = CARRY2(StshCtOfs.lo,uVar12);
          StshCtOfs.lo = StshCtOfs.lo + uVar12;
          StshCtOfs.hi = StshCtOfs.hi + iVar9 + (uint)bVar17;
          (pcVar11 + 0xb)[0] = '\0';
          (pcVar11 + 0xb)[1] = '\0';
          (pcVar11 + 9)[0] = '\0';
          (pcVar11 + 9)[1] = '\0';
          (pcVar11 + 0xf)[0] = '\0';
          (pcVar11 + 0xf)[1] = '\0';
          (pcVar11 + 0xd)[0] = '\0';
          (pcVar11 + 0xd)[1] = '\0';
          if (DebugVerbose != false) {
            pcStackY_1e = (char *)"arrowsmith" + 3;
            pcStackY_20 = (char *)0xbbd4;
            printf("type %d len %ld \r",(uint)*(byte *)param_1);
            ovr_biosReadKey();
          }
          pcStackY_1e = (char *)"arrowsmith" + 3;
          pcStackY_20 = "";
          sz.hi._0_1_ = (char)iVar9;
          sz.lo = uVar12;
          sz.hi._1_1_ = (char)((uint)iVar9 >> 8);
          stshWriteFile(StshFile,param_1,sz);
          ovr_stshFree(param_1);
          return pcVar11;
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x24);
      case 2:
        uVar14 = uVar4 + 1;
        piVar1 = (int *)(uVar7 * 2 + uVar14);
        *piVar1 = *piVar1 + 1;
        do {
          cVar5 = ovr_OVC15_4207_2301();
          if (cVar5 == '\0') goto LAB_3f0b_2767;
          param_2._0_2_ = (int *)((int)(int *)param_2 + -1);
          while ((int *)param_2 == (int *)0x0) {
LAB_3f0b_2767:
            do {
              uVar14 = uVar14 + 1;
              if (EntityCount <= uVar14) {
                return (char *)"puppetmaker" + 3;
              }
              cVar5 = ovr_OVC23_55fe_05db();
            } while (cVar5 == '\0');
            param_2._0_2_ = (int *)manage_4d05_28f4();
          }
        } while( true );
      case 3:
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
        s_cue9a_xmi_2410_36fe[1] = -0x58;
        *(uint *)(&stack0x681c + uVar4) = *(uint *)(&stack0x681c + uVar4) & in_CX;
        ovr_blitLabel((char *)CONCAT13((char)unaff_SI,
                                       CONCAT12((char)((uint)unaff_DI >> 8),
                                                CONCAT11((char)unaff_DI,in_stack_0000ffef))),
                      (uint8_t *)
                      CONCAT13(uVar22,CONCAT12(uVar21,CONCAT11(uVar20,(char)((uint)unaff_SI >> 8))))
                      ,CONCAT11((char)uVar3,uVar23),(uint8_t)((uint)uVar3 >> 8));
        litoa10(acStackY_f6,
                CONCAT13((char)((uint)*(undefined2 *)(param_1.ofs + 0x62) >> 8),
                         CONCAT12((char)*(undefined2 *)(param_1.ofs + 0x62),
                                  *(undefined2 *)(param_1.ofs + 0x60))));
        manage_4d05_04c6();
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel("Housing",
                      (uint8_t *)
                      CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs)),222,
                      0xe0);
        ovr_stsprintf(acStackY_7e,"%d",(char *)*(undefined2 *)(param_1.ofs + 0x5b));
        manage_4d05_04c6();
        TextBlitX = 0x82;
        ovr_blitLabel("Food storage",
                      (uint8_t *)
                      CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs)),222,
                      0xe0);
        litoa10(acStackY_f6,
                CONCAT13((char)((uint)*(undefined2 *)(param_1.ofs + 0x80) >> 8),
                         CONCAT12((char)*(undefined2 *)(param_1.ofs + 0x80),
                                  *(undefined2 *)(param_1.ofs + 0x7e))));
        manage_4d05_04c6();
        TextBlitY = TextBlitY + 0xf;
        if (*(int *)(param_1.ofs + 0xa0) != 0) {
          TextBlitX = 0x37;
          uVar20 = (undefined1)(Font02.seg >> 8);
          if (*(int *)(param_1.ofs + 0xa2) < 0) {
            ovr_blitLabel("Food sold",
                          (uint8_t *)CONCAT13(uVar20,CONCAT12((char)Font02.seg,Font02.ofs)),222,0xe0
                         );
            cVar5 = (char)(-*(int *)(param_1.ofs + 0xa2) >> 0xf);
            litoa10(acStackY_f6,CONCAT13(cVar5,CONCAT12(cVar5,-*(int *)(param_1.ofs + 0xa2))));
            manage_4d05_04c6();
          }
          else {
            ovr_blitLabel("Food bought",
                          (uint8_t *)CONCAT13(uVar20,CONCAT12((char)Font02.seg,Font02.ofs)),222,0xe0
                         );
            cVar5 = (char)((int)*(undefined2 *)(param_1.ofs + 0xa2) >> 0xf);
            litoa10(acStackY_f6,CONCAT13(cVar5,CONCAT12(cVar5,*(undefined2 *)(param_1.ofs + 0xa2))))
            ;
            manage_4d05_04c6();
          }
          TextBlitX = 0x82;
          ovr_blitLabel("Max. trade",
                        (uint8_t *)
                        CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs)),222,
                        0xe0);
          litoa10(acStackY_f6,(ulong)*(uint *)(param_1.ofs + 0xa0));
          manage_4d05_04c6();
        }
        TextBlitY = TextBlitY + 0xf;
        TextBlitX = 0x37;
        ovr_blitLabel("Income",(uint8_t *)
                               CONCAT13((char)(Font02.seg >> 8),
                                        CONCAT12((char)Font02.seg,Font02.ofs)),222,0xe0);
        iVar9 = *(int *)(param_1.ofs + 0x54);
        iVar13 = iVar9 >> 0xf;
        cVar5 = (char)(iVar9 >> 0xf);
        litoa10(acStackY_7e,CONCAT13(cVar5,CONCAT12(cVar5,iVar9)));
        manage_4d05_04c6();
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel("Gold",(uint8_t *)
                             CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs))
                      ,222,0xe0);
        litoa10(acStackY_7e,
                CONCAT13((char)((uint)*(undefined2 *)(param_1.ofs + 0x58) >> 8),
                         CONCAT12((char)*(undefined2 *)(param_1.ofs + 0x58),
                                  *(undefined2 *)(param_1.ofs + 0x56))));
        manage_4d05_04c6();
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel("Vault storage",
                      (uint8_t *)
                      CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs)),222,
                      0xe0);
        litoa10(acStackY_7e,
                CONCAT13((char)((uint)*(undefined2 *)(param_1.ofs + 0x8c) >> 8),
                         CONCAT12((char)*(undefined2 *)(param_1.ofs + 0x8c),
                                  *(undefined2 *)(param_1.ofs + 0x8a))));
        manage_4d05_04c6();
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel("Fund Access",
                      (uint8_t *)
                      CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs)),222,
                      0xe0);
        uVar10 = ovr_OVC45_77eb_0904();
        litoa10(acStackY_f6,CONCAT13((char)((uint)iVar13 >> 8),CONCAT12((char)iVar13,uVar10)));
        manage_4d05_04c6();
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel("Common fund",
                      (uint8_t *)
                      CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs)),222,
                      0xe0);
        litoa10(acStackY_f6,
                CONCAT13((char)((uint)DAT_2000_ca93 >> 8),
                         CONCAT12((char)DAT_2000_ca93,DAT_2000_ca91)));
        manage_4d05_04c6();
        bVar6 = manage_4d05_1b1d();
        pcVar11 = (char *)"puppetmaker" + 3;
        TextBlitY = TextBlitY + 0xf;
        if (((*(char *)(param_1.ofs + 0x86) != '\0') && (bVar6 != 0xff)) &&
           (pcVar11 = (char *)((uint)bVar6 << 2), *(byte *)((int)*(undefined4 *)pcVar11 + 0x86) < 9)
           ) {
          manage_4d05_0519();
          manage_4d05_0519();
          TextBlitY = TextBlitY + 10;
          TextBlitX = 0x11;
          ovr_blitLabel("Current",
                        (uint8_t *)
                        CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs)),222,
                        0xe0);
          pcVar11 = (char *)manage_4d05_044e();
          ovr_stsprintf(acStackY_7e,"%d%%",pcVar11);
          manage_4d05_04c6();
          ovr_stsprintf(acStackY_7e,"%d",DAT_2000_d3ca);
          manage_4d05_04c6();
          TextBlitY = TextBlitY + 10;
          TextBlitX = 0x11;
          ovr_blitLabel("to promote",
                        (uint8_t *)
                        CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs)),222,
                        0xe0);
          bVar6 = ovr_season_67e7_04e5();
          ovr_stsprintf(acStackY_7e,"%d%%",(char *)(uint)bVar6);
          manage_4d05_04c6();
          pcVar11 = (char *)ovr_season_67e7_048f();
          ovr_stsprintf(acStackY_7e,"%d",pcVar11);
          pcVar11 = (char *)manage_4d05_04c6();
        }
        return pcVar11;
      }
      do {
        if (bVar17) {
          *param_9 = *param_9 + 1;
        }
        while( true ) {
          while( true ) {
            do {
              piVar15 = (int *)((int)piVar15 + 1);
              if (DAT_2000_d2df <= piVar15) {
                iVar9 = *param_8;
                iVar13 = *param_9;
                *param_2 = *param_2 - *param_8;
                *param_3 = *param_3 - *param_9;
                return (char *)(CONCAT11(uStack_3,uStack_4) - (iVar9 + iVar13));
              }
            } while ((*(byte *)((int)piVar15 * 0x12 + 9) != bVar6) ||
                    (bVar2 = *(byte *)((int)piVar15 * 0x12 + 8),
                    *(char *)((uint)bVar2 * 0x27 + 0x133) != (char)param_1.seg));
            *param_6 = *param_6 + 1;
            if (*(char *)((uint)bVar2 * 0x27 + 0x131) != '\x01') break;
            *param_7 = *param_7 + 1;
          }
          if (*(char *)((uint)bVar2 * 0x27 + 0x131) != '\x02') break;
          *param_8 = *param_8 + 1;
        }
        bVar17 = *(char *)((uint)bVar2 * 0x27 + 0x131) == '\x03';
      } while( true );
    }
  }
  else if (uVar7 == 5) {
    pcStackY_20 = (char *)"sbpro.com" + 6;
    pcVar11 = (char *)"jeweler\'s shop" + 3;
    puStackY_22 = (undefined2 *)0x8fe5;
    ovr_OVC15_4207_10a3();
  }
  else if (uVar7 == 6) {
    pcStackY_20 = (char *)"sbpro.com" + 6;
    pcVar11 = (char *)"jeweler\'s shop" + 3;
    puStackY_22 = (undefined2 *)&DAT_2000_d100;
    ovr_OVC15_4207_10a3();
  }
  else if ((uVar7 == 0xff) &&
          ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].seg + 1 + (uint)*(byte *)(iVar13 + 0x3e) * 0x95
                     ) & 0x800) == 0)) {
    if (param_2._2_1_ == '\0') {
      pcStackY_20 = (char *)"sbpro.com" + 6;
      pcVar11 = (char *)"jeweler\'s shop" + 3;
      puStackY_22 = (undefined2 *)0x906a;
      ovr_OVC15_4207_10a3();
    }
    else {
      pcStackY_20 = (char *)"sbpro.com" + 6;
      pcVar11 = (char *)"jeweler\'s shop" + 3;
      puStackY_22 = (undefined2 *)0x904a;
      ovr_OVC15_4207_10a3();
    }
  }
  pcVar8 = (char *)((uint)*(byte *)(CONCAT11(uVar21,uVar20) + 0x3e) * 0x95);
  if ((*(uint *)(pcVar8 + 0x2714) & 0x8000) != 0) {
    puStackY_22 = (undefined2 *)&DAT_2000_d1a3;
    pcStackY_20 = pcVar11;
    pcStackY_1e = (char *)uVar10;
    pcVar8 = (char *)OVC18_48ac_0251();
  }
  return pcVar8;
}



/* 48ac:05f2 */

void __cdecl16far OVC18_48ac_05f2(char param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  undefined1 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined2 unaff_SS;
  uint8_t local_12 [13];
  undefined1 local_5;
  uint uStack_4;
  
  F_SCOPY(local_12,(uint8_t *)(far_t *)far_t_ARRAY_2410_45b9,0xc);
  for (uVar10 = 0; uVar10 < EntityCount; uVar10 = uVar10 + 1) {
    if (*(char *)((int)(char **)GMenuStrings +
                 (uint)*(byte *)(Entities.ofs + uVar10 * 0x37 + 0xd) * 0x95 + 0x1f) != '\0') {
      iVar3 = ovr_OVC23_55fe_3450();
      iVar4 = ovr_OVC23_55fe_3450();
      if ((iVar3 == iVar4) && (*(int *)(Entities.ofs + uVar10 * 0x37 + 2) == GfxRndSeed2)) {
        ovr_stats_6386_232d();
        ovr_say("A fortress cannot be placed among enemy units.");
        DAT_2410_45b8 = 1;
        return;
      }
    }
  }
  for (iVar3 = 0; iVar3 < (int)(uint)DAT_2000_d1e6; iVar3 = iVar3 + 1) {
    if (((*(char *)((int)*(undefined4 *)(iVar3 << 2) + 0x3d) != '\0') &&
        (*(int *)((int)*(undefined4 *)(iVar3 << 2) + 0x39) == GfxRndSeed)) &&
       (*(int *)((int)*(undefined4 *)(iVar3 << 2) + 0x3b) == GfxRndSeed2)) {
      ovr_stats_6386_232d();
      ovr_say("Cannot place another fortress here.");
      DAT_2410_45b8 = 1;
      return;
    }
  }
  if (param_1 == '\x02') {
    cVar2 = ovr_constr_36ce_306b(GfxRndSeed + -2);
    if (((cVar2 == '\0') || (cVar2 = ovr_constr_36ce_306b(GfxRndSeed + -1), cVar2 == '\0')) ||
       ((cVar2 = ovr_constr_36ce_306b(GfxRndSeed), cVar2 == '\0' ||
        (cVar2 = ovr_constr_36ce_306b(GfxRndSeed + 1), cVar2 == '\0')))) {
      ovr_stats_6386_232d();
      puVar7 = &stack0xffea;
      pcVar5 = ovr_fmVsprintf((char *)"This location is unsuitable for a main stronghold.  %s",
                              *(char **)(puVar7 + (uint)DAT_2000_d090 * 4));
      ovr_say((char *)CONCAT22(puVar7,pcVar5));
      DAT_2410_45b8 = 1;
      return;
    }
  }
  else {
    cVar2 = ovr_constr_36ce_306b(GfxRndSeed + -1);
    if ((cVar2 == '\0') || (cVar2 = ovr_constr_36ce_306b(GfxRndSeed), cVar2 == '\0')) {
      ovr_stats_6386_232d();
      puVar7 = &stack0xffea;
      pcVar5 = ovr_fmVsprintf((char *)"This location is unsuitable.  %s",
                              *(char **)(puVar7 + (uint)DAT_2000_d090 * 4));
      ovr_say((char *)CONCAT22(puVar7,pcVar5));
      DAT_2410_45b8 = 1;
      return;
    }
  }
  cVar2 = ovr_draw_2e25_15d6();
  if (cVar2 == '\0') {
    ovr_stats_6386_232d();
    ovr_say("Your stronghold is too far away.");
    DAT_2410_45b8 = 1;
  }
  else {
    if (1 < DAT_2000_d1e5) {
      uStack_4 = 0xffff;
      for (iVar3 = 0; iVar3 < (int)(uint)DAT_2000_d1e6; iVar3 = iVar3 + 1) {
        if (((*(char *)((int)*(undefined4 *)(iVar3 << 2) + 0x3d) != '\0') &&
            (*(char *)((int)*(undefined4 *)(iVar3 << 2) + 0x3f) == '\0')) &&
           (uVar10 = *(int *)((int)*(undefined4 *)(iVar3 << 2) + 0x39) - GfxRndSeed,
           uVar8 = (int)uVar10 >> 0xf,
           uVar6 = *(int *)((int)*(undefined4 *)(iVar3 << 2) + 0x3b) - GfxRndSeed2,
           uVar9 = (int)uVar6 >> 0xf,
           uVar10 = ((uVar10 ^ uVar8) - uVar8) + ((uVar6 ^ uVar9) - uVar9), uVar10 < uStack_4)) {
          uStack_4 = uVar10;
        }
      }
      if (0x1e < uStack_4) {
        ovr_stats_6386_232d();
        ovr_say("Your stronghold is too far away.");
        DAT_2410_45b8 = 1;
        return;
      }
    }
    uVar1 = *(undefined4 *)((uint)DAT_2000_d1e4 * 4 + -4);
    *(int *)((int)uVar1 + 0x39) = GfxRndSeed;
    uVar1 = *(undefined4 *)((uint)DAT_2000_d1e4 * 4 + -4);
    *(int *)((int)uVar1 + 0x3b) = GfxRndSeed2;
    uVar1 = *(undefined4 *)((uint)DAT_2000_d1e4 * 4 + -4);
    *(undefined1 *)((int)uVar1 + 0x3d) = 1;
    uVar1 = *(undefined4 *)((uint)DAT_2000_d1e4 * 4 + -4);
    *(char *)((int)uVar1 + 0x89) = DAT_2000_d1e5 - 1;
    if (param_1 == '\x02') {
      uVar1 = *(undefined4 *)((uint)DAT_2000_d1e4 * 4 + -4);
      *(undefined1 *)((int)uVar1 + 0x5a) = 1;
      ovr_OVC23_55fe_1e87(0x89,GfxRndSeed + -2,GfxRndSeed2,&local_5);
      OVC18_48ac_0382(CONCAT11(0x24,DAT_2000_d1e4 - 1),GfxRndSeed,GfxRndSeed2);
      ovr_OVC22_5087_4975(CONCAT11(0x24,DAT_2000_d1e4 - 1),&local_5);
    }
    else {
      uVar1 = *(undefined4 *)((uint)DAT_2000_d1e4 * 4 + -4);
      *(char *)((int)uVar1 + 0x5a) = param_1;
      uVar1 = *(undefined4 *)((uint)DAT_2000_d1e4 * 4 + -4);
      iVar3 = (uint)*(byte *)((int)uVar1 + 0x3e) * 0x95;
      ovr_OVC23_55fe_1e87(CONCAT11((char)((uint)iVar3 >> 8),
                                   *(undefined1 *)
                                    ((int)(far_t *)(far_t_ARRAY_2410_26f7 + 0xb) + iVar3)),
                          GfxRndSeed + -1,GfxRndSeed2,&local_5);
      OVC18_48ac_0382(CONCAT11(0x24,DAT_2000_d1e4 - 1),GfxRndSeed,GfxRndSeed2);
    }
    if (2 < DAT_2000_d19d) {
      ovr_OVC22_5087_4975(CONCAT11(0x24,DAT_2000_d1e4 - 1),&local_5);
    }
    ovr_OVC22_5087_056e();
    DAT_2000_d1e4 = 0;
    ovr_manage_4d05_0000();
    ovr_stats_6386_232d();
    ovr_unit_6616_00d8();
    ovr_say("");
    if (DAT_2000_d310 == '\0') {
      ovr_OVC30_619c_004e();
    }
  }
  return;
}



/* 48ac:0bf4 */

uint __cdecl16far OVC18_48ac_0bf4(int param_1,int param_2,byte param_3,undefined1 param_4)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  uint16_t uVar4;
  int iVar5;
  uint unaff_SI;
  undefined2 uVar6;
  undefined2 uVar7;
  uint uStack_6;
  
  iVar5 = (int)DAT_2000_cb0d;
  uVar7 = (undefined2)((ulong)DAT_2000_cb0d >> 0x10);
  uVar6 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
  if (param_3 == 0) {
    if (*(uint *)(iVar5 + param_1 * 0x78 + param_2 * 2) < 0xf8) {
      *(undefined2 *)(iVar5 + param_1 * 0x78 + param_2 * 2) = 0;
    }
    else {
      unaff_SI = *(uint *)(iVar5 + param_1 * 0x78 + param_2 * 2);
      *(undefined1 *)((int)DAT_2000_ca95 + unaff_SI * 9) = 0;
      *(undefined1 *)((int)DAT_2000_ca95 + unaff_SI * 9 + 1) = 8;
      *(undefined1 *)((int)DAT_2000_ca95 + unaff_SI * 9 + 2) = 0xff;
      *(undefined2 *)((int)DAT_2000_cb0d + param_1 * 0x78 + param_2 * 2) = 0;
    }
    puVar1 = (uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2);
    *puVar1 = *puVar1 & 0x3fff;
  }
  else {
    if (*(uint *)(iVar5 + param_1 * 0x78 + param_2 * 2) < 0xf8) {
      unaff_SI = 0xf8;
      while ((unaff_SI < DAT_2000_ca99 && (*(char *)((int)DAT_2000_ca95 + unaff_SI * 9) != '\0'))) {
        unaff_SI = unaff_SI + 1;
      }
      if (DAT_2000_ca99 <= unaff_SI) {
        if (DAT_2000_ca99 + 1 < 0x4b0) {
          DAT_2000_ca99 = DAT_2000_ca99 + 1;
        }
        else {
          uVar4 = ovr_randBelow(0x3b8);
          uVar3 = (uVar4 & 0xff) + 0xf8;
          unaff_SI = uVar3;
          do {
            if ((((*(uint *)(unaff_SI * 0x27 + 0x121) & 0xa0) != 0) ||
                (*(char *)(unaff_SI * 0x27 + 0x133) == '\0')) ||
               (*(char *)(unaff_SI * 0x27 + 0x133) == '\a')) break;
            unaff_SI = unaff_SI + 1;
            if (0x4af < unaff_SI) {
              unaff_SI = 0xf8;
            }
          } while (uVar3 != unaff_SI);
          for (uStack_6 = 0; uStack_6 < 0x94; uStack_6 = uStack_6 + 1) {
            for (uVar3 = 0; uVar3 < 0x3c; uVar3 = uVar3 + 1) {
              uVar7 = (undefined2)((ulong)DAT_2000_cb0d >> 0x10);
              if (*(uint *)((int)DAT_2000_cb0d + uStack_6 * 0x78 + uVar3 * 2) == unaff_SI) {
                *(undefined2 *)((int)DAT_2000_cb0d + uStack_6 * 0x78 + uVar3 * 2) = 0;
              }
            }
          }
        }
      }
    }
    else {
      unaff_SI = *(uint *)(iVar5 + param_1 * 0x78 + param_2 * 2);
    }
    *(byte *)((int)DAT_2000_ca95 + unaff_SI * 9) = param_3;
    *(undefined1 *)((int)DAT_2000_ca95 + unaff_SI * 9 + 1) = 8;
    *(undefined1 *)((int)DAT_2000_ca95 + unaff_SI * 9 + 2) = param_4;
    *(int *)((int)DAT_2000_ca95 + unaff_SI * 9 + 4) = param_1;
    *(int *)((int)DAT_2000_ca95 + unaff_SI * 9 + 6) = param_2;
    *(uint *)((int)DAT_2000_cb0d + param_1 * 0x78 + param_2 * 2) = unaff_SI;
    uVar7 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
    *(uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2) =
         *(uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2) & 0x3fff |
         (uint)*(byte *)((uint)param_3 * 0x27 + 0x11e) << 0xe;
    if ((*(uint *)((uint)param_3 * 0x27 + 0x121) & 0x40) == 0) {
      *(undefined1 *)((int)DAT_2000_ca95 + unaff_SI * 9 + 8) = 0;
    }
    else {
      cVar2 = ovr_constr_36ce_3172(param_1,param_2);
      if (cVar2 == '\x03') {
        uVar4 = ovr_randBelow(0x28);
        *(char *)((int)DAT_2000_ca95 + unaff_SI * 9 + 8) = (char)uVar4 + '\x1e';
      }
      else if (cVar2 == '\x04') {
        uVar4 = ovr_randBelow(0x50);
        *(char *)((int)DAT_2000_ca95 + unaff_SI * 9 + 8) = (char)uVar4 + '<';
      }
      else {
        uVar4 = ovr_randBelow(0x14);
        *(char *)((int)DAT_2000_ca95 + unaff_SI * 9 + 8) = (char)uVar4 + '\x0f';
      }
    }
  }
  return unaff_SI;
}



/* 48ac:1022 */

char * __cdecl16far OVC18_48ac_1022(undefined2 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = ovr_OVC23_55fe_3450(param_1);
  uVar3 = 0;
  while( true ) {
    if (EntityCount <= uVar3) {
      return (char *)"arena" + 4;
    }
    iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar3 * 0x37));
    if ((iVar2 == iVar1) && (*(int *)(Entities.ofs + uVar3 * 0x37 + 2) == param_2)) break;
    uVar3 = uVar3 + 1;
  }
  return (char *)CONCAT11((char)(uVar3 * 0x37 >> 8),1);
}



/* 48ac:1092 */

uint __cdecl16far OVC18_48ac_1092(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uStack_4;
  
  cVar1 = ovr_draw_2e25_15d6();
  if (cVar1 == '\0') {
    uVar8 = 0;
  }
  else {
    for (uVar8 = 0; uVar8 < EntityCount; uVar8 = uVar8 + 1) {
      if (*(char *)((int)(char **)GMenuStrings +
                   (uint)*(byte *)(Entities.ofs + uVar8 * 0x37 + 0xd) * 0x95 + 0x1f) != '\0') {
        iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar8 * 0x37));
        iVar3 = ovr_OVC23_55fe_3450(GfxRndSeed);
        if ((iVar2 == iVar3) &&
           (uVar4 = *(uint *)(Entities.ofs + uVar8 * 0x37 + 2), uVar4 == GfxRndSeed2)) {
          return uVar4 & 0xff00;
        }
      }
    }
    for (iVar2 = 0; iVar2 < (int)(uint)DAT_2000_d1e6; iVar2 = iVar2 + 1) {
      if (((*(char *)((int)*(undefined4 *)(iVar2 << 2) + 0x3d) != '\0') &&
          (*(int *)((int)*(undefined4 *)(iVar2 << 2) + 0x39) == GfxRndSeed)) &&
         (uVar8 = *(uint *)((int)*(undefined4 *)(iVar2 << 2) + 0x3b), uVar8 == GfxRndSeed2)) {
        return uVar8 & 0xff00;
      }
    }
    cVar1 = ovr_constr_36ce_306b(GfxRndSeed + -1,GfxRndSeed2);
    if ((cVar1 == '\0') || (cVar1 = ovr_constr_36ce_306b(GfxRndSeed,GfxRndSeed2), cVar1 == '\0')) {
      uVar8 = 0;
    }
    else if ((DAT_2000_d1e5 == 1) &&
            ((cVar1 = ovr_constr_36ce_306b(GfxRndSeed + -2,GfxRndSeed2), cVar1 == '\0' ||
             (cVar1 = ovr_constr_36ce_306b(GfxRndSeed + 1,GfxRndSeed2), cVar1 == '\0')))) {
      uVar8 = 0;
    }
    else {
      pcVar5 = (char *)"puppetmaker" + 3;
      if (1 < DAT_2000_d1e5) {
        uStack_4 = 0xffff;
        for (iVar2 = 0; pcVar5 = (char *)(uint)DAT_2000_d1e6, iVar2 < (int)pcVar5; iVar2 = iVar2 + 1
            ) {
          if (((*(char *)((int)*(undefined4 *)(iVar2 << 2) + 0x3d) != '\0') &&
              (*(char *)((int)*(undefined4 *)(iVar2 << 2) + 0x3f) == '\0')) &&
             (uVar8 = *(int *)((int)*(undefined4 *)(iVar2 << 2) + 0x39) - GfxRndSeed,
             uVar6 = (int)uVar8 >> 0xf,
             uVar4 = *(int *)((int)*(undefined4 *)(iVar2 << 2) + 0x3b) - GfxRndSeed2,
             uVar7 = (int)uVar4 >> 0xf,
             uVar8 = ((uVar8 ^ uVar6) - uVar6) + ((uVar4 ^ uVar7) - uVar7), uVar8 < uStack_4)) {
            uStack_4 = uVar8;
          }
        }
        if (0x1e < uStack_4) {
          return 0;
        }
      }
      uVar8 = CONCAT11((char)((uint)pcVar5 >> 8),1);
    }
  }
  return uVar8;
}


