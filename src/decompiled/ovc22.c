/*
 * ovc22.c - recovered from STRONG.EXE
 * memory block: OVC22
 * range: 5087:0000 - 5087:576f
 * functions: 31
 */
#include "recovered.h"


/* 5087:0000 */

char * __cdecl16far OVC22_5087_0000(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined2 uVar4;
  int iStack_4;
  
  if ((((param_1 < 0) || (param_2 < 0)) || (0x93 < param_1 + 1)) || (0x3b < param_2 + 1)) {
    DAT_2000_d090 = 2;
    pcVar2 = (char *)"arena" + 4;
  }
  else {
    uVar4 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
    if (((*(uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2) & 3) == 0) &&
       ((*(uint *)(param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2 + 0x128) & 3) == 0)) {
      iStack_4 = (int)*(char *)(param_2 * 0x94 + DAT_2000_cb05 + param_1 + 0x94);
      iVar1 = (int)*(char *)(param_2 * 0x94 + DAT_2000_cb05 + param_1 + 0x95);
      iVar3 = iStack_4;
      if (iVar1 < iStack_4) {
        iVar3 = iVar1;
      }
      if (iStack_4 < iVar1) {
        iStack_4 = iVar1;
      }
      if (iStack_4 - iVar3 < 9) {
        DAT_2000_d090 = 3;
        pcVar2 = (char *)"arena" + 5;
      }
      else {
        pcVar2 = (char *)(iStack_4 - iVar3 & 0xff00);
      }
    }
    else {
      DAT_2000_d090 = 1;
      pcVar2 = (char *)"arena" + 4;
    }
  }
  return pcVar2;
}



/* 5087:0119 */

char * __cdecl16far OVC22_5087_0119(byte param_1)

{
  byte bVar1;
  char *pcVar2;
  
  bVar1 = *(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x2f);
  if (bVar1 < 7) {
    pcVar2 = (char *)*(undefined2 *)((uint)bVar1 * 4 + 0x123);
  }
  else {
    pcVar2 = (char *)"monster";
  }
  return pcVar2;
}



/* 5087:015c */

uint __cdecl16far OVC22_5087_015c(byte param_1,uint param_2)

{
  if (*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x2f) == '\x04') {
    param_2 = param_2 >> 1;
  }
  return param_2;
}



/* 5087:018f */

int __cdecl16far OVC22_5087_018f(byte param_1,int param_2)

{
  if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x87) < 10) {
    if (*(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x87) != 0) {
      param_2 = (int)(((long)param_2 *
                       (long)(*(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x87) + 10) &
                      0xffffU) / 10);
    }
  }
  else {
    param_2 = param_2 << 1;
  }
  if (*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x2f) == '\x06') {
    param_2 = (int)(((long)param_2 * 0x96 & 0xffffU) / 100);
  }
  return param_2;
}



/* 5087:0234 */

/* WARNING: Instruction at (ram,0x0005ff51) overlaps instruction at (ram,0x0005ff50)
    */

char * __cdecl16far OVC22_5087_0234(byte param_1,byte param_2,undefined4 param_3)

{
  byte *pbVar1;
  code *pcVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char in_CL;
  uint16_t uVar9;
  char *pcVar10;
  undefined2 unaff_SI;
  int unaff_DI;
  uint8_t *unaff_SS;
  char local_13e [36];
  undefined2 auStack_11a [66];
  undefined2 local_96 [64];
  char *local_16;
  char *local_14;
  byte bVar11;
  uint8_t *widths;
  
  if (*(char *)((uint)param_1 * 0x27 + 0x133) == '\x16') {
    pcVar7 = (char *)0x0;
  }
  else if (*(char *)((uint)param_1 * 0x27 + 0x128) == '\0') {
    pcVar7 = (char *)0x0;
  }
  else {
    if ((*(uint *)((uint)param_1 * 0x27 + 0x121) & 0x20) == 0) {
      if ((*(uint *)((uint)param_1 * 0x27 + 0x121) & 0x80) == 0) {
        pcVar7 = (char *)(uint)*(byte *)((uint)param_1 * 0x27 + 0x128);
      }
      else {
        pcVar7 = (char *)OVC22_5087_018f();
      }
    }
    else {
      pcVar7 = (char *)OVC22_5087_015c();
    }
    if (pcVar7 == (char *)0x0) {
      pcVar7 = (char *)0x0;
    }
    else if (*(char *)((uint)param_1 * 0x27 + 0x133) == '\x19') {
      if (GSeason == '\0') {
        if (GTimeLo < 0xf) {
          pcVar7 = (char *)((uint)pcVar7 >> 2);
        }
        else {
          pcVar7 = (char *)((uint)pcVar7 >> 1);
        }
      }
      else if (GSeason == '\x02') {
        pcVar7 = pcVar7 + ((uint)pcVar7 >> 2);
      }
    }
    else {
      if ((*(uint *)((uint)param_1 * 0x27 + 0x121) & 0x80) != 0) {
        iVar5 = (*(uint16_t *)((uint8_t *)&(param_3) + 2));
        uVar4 = ovr_constr_36ce_3172();
        switch(uVar4) {
        case 1:
          *(char *)(unaff_DI + 0x34) = *(char *)(unaff_DI + 0x34) << 1;
code_r0x0005b805:
          if (*(int *)(Entities.ofs + (int)pcVar7 * 0x37 + 10) != (*(uint16_t *)((uint8_t *)&(param_3) + 2))) goto LAB_5b66_01d9;
          do {
            pbVar1 = (byte *)(Entities.ofs + (int)pcVar7 * 0x37 + 0x33);
            *pbVar1 = *pbVar1 | 8;
LAB_5b66_01d9:
            while( true ) {
              do {
                pcVar7 = pcVar7 + 1;
                if (EntityCount <= pcVar7) {
                  if (param_2 != 0) {
                    iVar5 = 0;
                    while ((iVar5 < (int)(uint)param_2 && (iVar8 = OVC25_5b66_0000(), -1 < iVar8)))
                    {
                      *(undefined1 *)(Entities.ofs + iVar8 * 0x37 + 0x30) = 0;
                      *(int *)(Entities.ofs + iVar8 * 0x37 + 8) = unaff_DI;
                      *(int *)(Entities.ofs + iVar8 * 0x37 + 10) = (*(uint16_t *)((uint8_t *)&(param_3) + 2));
                      pbVar1 = (byte *)(Entities.ofs + iVar8 * 0x37 + 0x33);
                      *pbVar1 = *pbVar1 | 8;
                      iVar5 = iVar5 + 1;
                    }
                  }
                  return (char *)0xffff;
                }
              } while (*(byte *)(Entities.ofs + (int)pcVar7 * 0x37 + 0x1a) != param_1);
              iVar5 = ovr_OVC23_55fe_3450();
              iVar8 = ovr_OVC23_55fe_3450();
              if ((iVar5 == iVar8) &&
                 (*(int *)(Entities.ofs + (int)pcVar7 * 0x37 + 2) == (*(uint16_t *)((uint8_t *)&(param_3) + 2)))) break;
              iVar5 = ovr_OVC23_55fe_3450();
              iVar8 = ovr_OVC23_55fe_3450();
              if (iVar5 == iVar8) goto code_r0x0005b805;
            }
          } while( true );
        case 2:
          pcVar2 = (code *)swi(1);
          pcVar7 = (char *)(*pcVar2)();
          return pcVar7;
        case 3:
          do {
            if (*(byte *)(iVar5 + 0x32) < *(byte *)((int)pcVar7 * 0x34 + 0x22)) {
              *(undefined1 *)((int)pcVar7 * 0x34 + 0x22) = *(undefined1 *)(iVar5 + 0x32);
            }
            uVar9 = 0x34;
            pcVar10 = pcVar7;
code_r0x0005ff56:
            bVar11 = *(byte *)((int)pcVar7 * uVar9 + 0x21);
            iVar5 = CONCAT11((char)((int)pcVar7 * uVar9 >> 8),bVar11);
            pcVar7 = pcVar10;
            if (*(byte *)((int)pcVar10 * 0x34 + 0x22) < bVar11) {
              uVar4 = *(undefined1 *)((int)pcVar10 * 0x34 + 0x22);
              iVar5 = CONCAT11((char)((uint)((int)pcVar10 * 0x34) >> 8),uVar4);
              *(undefined1 *)((int)pcVar10 * 0x34 + 0x21) = uVar4;
            }
            do {
              pcVar7 = pcVar7 + 1;
              if ((int)(uint)AgntCount <= (int)pcVar7) {
                uVar9 = ovr_audio_3a5b_0afd();
                ovr_play_sfxU(0x1c,0,uVar9);
                return (char *)0x1;
              }
            } while (*(int *)((int)pcVar7 * 0x34 + 0x1b) != *(int *)((int)param_3 + 0x1b));
          } while( true );
        case 4:
          iVar5 = ovr_font_302d_06ea();
          uVar9 = 0xd4 - iVar5;
          widths = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
          cVar3 = -0x3c;
          bVar11 = 0x22;
          TextBlitX = uVar9;
          ovr_blitLabel("POPULATION",widths,222,0xe0);
          pcVar10 = (char *)0x0;
          while( true ) {
            TextBlitY = TextBlitY + 0xc;
            unaff_SI = (undefined2)((ulong)widths >> 0x10);
            if ((int)(uint)bVar11 <= (int)pcVar10) break;
            TextBlitX = 0x11;
            uVar4 = (undefined1)(Font02.seg >> 8);
            if (((int)pcVar10 < 5) || (cVar3 == '\0')) {
              local_14 = "ghters";
              ovr_blitLabel((char *)CONCAT13((char)((uint)local_96[(int)pcVar10 * 2 + 1] >> 8),
                                             CONCAT12((char)local_96[(int)pcVar10 * 2 + 1],
                                                      local_96[(int)pcVar10 * 2])),
                            (uint8_t *)CONCAT13(uVar4,CONCAT12((char)Font02.seg,Font02.ofs)),319,
                            0xe0);
            }
            else {
              uVar6 = (uint)*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x2f);
              local_14 = (char *)0x167;
              ovr_blitLabel((char *)CONCAT13((char)((uint)auStack_11a
                                                          [(int)pcVar10 * 2 + uVar6 * 8 + 1] >> 8),
                                             CONCAT12((char)auStack_11a
                                                            [(int)pcVar10 * 2 + uVar6 * 8 + 1],
                                                      auStack_11a[(int)pcVar10 * 2 + uVar6 * 8])),
                            (uint8_t *)CONCAT13(uVar4,CONCAT12((char)Font02.seg,Font02.ofs)),319,
                            0xe0);
            }
            widths = (uint8_t *)CONCAT22(unaff_SI,unaff_SS);
            local_14 = (char *)"steam bath" + 6;
            local_16 = "arves";
            OVC27_5ded_1433();
            pcVar7 = local_14;
            local_14 = "";
            ovr_stsprintf(local_13e,"%d",pcVar7);
            iVar5 = ovr_font_302d_06ea();
            TextBlitX = 0x89 - iVar5;
            local_14 = (char *)"steam bath" + 6;
            local_16 = (char *)"clerical unit" + 9;
            ovr_blitLabel((char *)CONCAT22(unaff_SS,local_13e),
                          (uint8_t *)
                          CONCAT13((char)(Font02.seg >> 8),CONCAT12((char)Font02.seg,Font02.ofs)),
                          222,0x50);
            local_14 = " unit";
            ovr_stsprintf(local_13e,"%d",local_16);
            iVar5 = ovr_font_302d_06ea();
            uVar9 = 0xd4 - iVar5;
            cVar3 = (char)Font02.seg;
            bVar11 = (byte)(Font02.seg >> 8);
            local_14 = (char *)"steam bath" + 6;
            local_16 = "hduchess";
            TextBlitX = uVar9;
            ovr_blitLabel((char *)CONCAT22(unaff_SS,local_13e),
                          (uint8_t *)CONCAT13(bVar11,CONCAT12(cVar3,Font02.ofs)),222,0x50);
            pcVar10 = pcVar10 + 1;
          }
          CurSfxType3 = 0x3c;
          local_14 = (char *)"steam bath" + 6;
          local_16 = "u \r";
          cVar3 = ovr_OVC28_6018_1398();
          DAT_2410_5cf0 = 0;
          if (((cVar3 != '\0') && (cVar3 != '\x01')) && (cVar3 != -2)) {
            (&stack0xbac4)[unaff_DI] = (&stack0xbac4)[unaff_DI] + in_CL;
            pcVar7 = (char *)"puppetmaker" + 3;
            goto code_r0x0005ff56;
          }
          if (cVar3 == -2) {
            DAT_2410_4926 = 1;
          }
          return (char *)"puppetmaker" + 3;
        }
      }
      if (GSeason == '\x01') {
        pcVar7 = pcVar7 + ((uint)pcVar7 >> 2);
      }
      else if (GSeason == '\x02') {
        pcVar7 = (char *)((uint)pcVar7 >> 2);
      }
    }
  }
  return pcVar7;
}



/* 5087:0411 */

uint __cdecl16far OVC22_5087_0411(byte param_1,undefined1 param_2)

{
  uint uVar1;
  
  if (*(int *)((uint)param_1 * 0x27 + 0x123) == 0) {
    uVar1 = 0;
  }
  else if (*(char *)((uint)param_1 * 0x27 + 0x133) == '\x19') {
    uVar1 = *(uint *)((uint)param_1 * 0x27 + 0x123);
    if (GSeason == '\0') {
      if (GTimeLo < 0xf) {
        uVar1 = uVar1 >> 2;
      }
      else {
        uVar1 = uVar1 >> 1;
      }
    }
    else if (GSeason == '\x02') {
      uVar1 = uVar1 + (uVar1 >> 2);
    }
  }
  else if ((*(uint *)((uint)param_1 * 0x27 + 0x121) & 0x20) == 0) {
    if ((*(uint *)((uint)param_1 * 0x27 + 0x121) & 0x80) == 0) {
      uVar1 = *(uint *)((uint)param_1 * 0x27 + 0x123);
    }
    else {
      uVar1 = OVC22_5087_018f(CONCAT11((char)((uint)param_1 * 0x27 >> 8),param_2),
                              *(undefined2 *)((uint)param_1 * 0x27 + 0x123));
      if (GSeason == '\x01') {
        uVar1 = uVar1 + ((int)uVar1 >> 2);
      }
      else if (GSeason == '\x02') {
        uVar1 = (int)uVar1 >> 2;
      }
    }
  }
  else {
    uVar1 = OVC22_5087_015c(CONCAT11((char)((uint)param_1 * 0x27 >> 8),param_2),
                            *(undefined2 *)((uint)param_1 * 0x27 + 0x123));
  }
  return uVar1;
}



/* 5087:056e */

/* WARNING: Instruction at (ram,0x0005ff51) overlaps instruction at (ram,0x0005ff50)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Type propagation algorithm not settling */

far_t * __cdecl16far
OVC22_5087_056e(byte param_1,far_t *param_2,undefined2 param_3,undefined1 *param_4,
               undefined2 param_5,undefined1 param_6,char param_7)

{
  far_t *pfVar1;
  byte *pbVar2;
  uint *puVar3;
  int *piVar4;
  uint8_t uVar5;
  undefined1 *puVar6;
  byte bVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  far_t gfx_08;
  far_t gfx_09;
  far_t gfx_10;
  far_t gfx_11;
  uint32_t uVar10;
  far_t *pfVar11;
  char cVar12;
  byte bVar13;
  byte bVar14;
  undefined1 uVar15;
  byte bVar16;
  char cVar17;
  far_t *in_AX;
  far_t *pfVar18;
  uint uVar19;
  uint16_t uVar20;
  uint8_t *puVar21;
  far_t *pfVar22;
  undefined2 in_CX;
  byte bVar23;
  byte bVar24;
  byte bVar29;
  uint16_t *x;
  char *pcVar25;
  char *pcVar26;
  uint uVar27;
  uint uVar28;
  byte bVar30;
  byte bVar35;
  uint *puVar31;
  int iVar32;
  byte *pbVar33;
  int iVar34;
  uint *puVar37;
  uint uVar38;
  uint *puVar39;
  uint *puVar40;
  uint uVar41;
  undefined1 *unaff_SI;
  far_t *pfVar42;
  uint uVar43;
  undefined2 *puVar44;
  far_t *unaff_DI;
  int iVar45;
  undefined2 uVar46;
  undefined2 uVar47;
  uint16_t uVar48;
  undefined2 uVar49;
  undefined2 unaff_SS;
  bool bVar50;
  bool bVar51;
  bool bVar52;
  bool bVar53;
  byte in_AF;
  bool bVar54;
  bool bVar55;
  bool bVar56;
  char *pcVar57;
  char acStackY_13e [36];
  undefined2 auStackY_11a [66];
  undefined2 auStackY_96 [22];
  char local_6a [2];
  char acStackY_68 [6];
  char *pcStackY_62;
  char *pcStackY_60;
  undefined1 uVar58;
  undefined1 uVar59;
  undefined1 in_stack_0000ffb8;
  undefined1 in_stack_0000ffb9;
  int iVar60;
  undefined2 in_stack_0000ffbc;
  uint uStack_42;
  int iStack_40;
  int iStack_3e;
  int iStack_3c;
  uint uStack_38;
  int iStack_36;
  uint uStack_34;
  int local_32 [4];
  int local_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  char cStack_1c;
  byte bStack_1b;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  far_t *pfStack_12;
  far_t *pfStack_10;
  undefined2 uStack_e;
  far_t *local_c;
  far_t *pfStack_a;
  uint16_t uStack_8;
  undefined4 uStack_6;
  byte bVar36;
  
  uVar15 = (undefined1)((uint)in_CX >> 8);
  if (param_1 != 0xff) {
    uStack_1e = 0;
    iVar60 = 0;
    uStack_22 = 0;
    uStack_24 = 0;
    uStack_20 = "d C++ - Copyright 1991 Borland Intl.";
    uVar58 = (undefined1)unaff_SS;
    uVar59 = (undefined1)((uint)unaff_SS >> 8);
    pfVar22 = unaff_DI;
    _fmemset((void *)CONCAT13(uVar59,CONCAT12(uVar58,&local_2a)),0,6);
    _fmemset((void *)CONCAT13(uVar59,CONCAT12(uVar58,local_32 + 1)),0,6);
    iVar32 = ((int *)((uint)param_1 * 4))[1];
    _fmemset((void *)CONCAT13((char)((uint)iVar32 >> 8),
                              CONCAT12((char)iVar32,*(int *)((uint)param_1 * 4) + 0x9a)),0,3);
    _fmemset((void *)CONCAT13(uVar59,CONCAT12(uVar58,&local_c)),0,6);
    if (DAT_2000_d19d == '\x01') {
      uStack_38 = 4000;
    }
    else if (DAT_2000_d19d == '\x02') {
      uStack_38 = 3000;
    }
    else {
      uStack_38 = 2000;
    }
    iStack_36 = 0;
    local_32[0] = 0;
    uStack_34 = 0;
    iStack_3c = 0;
    _fmemset((void *)CONCAT13(uVar59,CONCAT12(uVar58,&stack0xffbc)),0,8);
    uStack_14 = (far_t *)&GUnitDescriptions[3].ofs;
    while (uStack_14 = (far_t *)((int)&uStack_14->ofs + 1), uStack_14 < DAT_2000_ca99) {
      pbVar2 = (byte *)((int)DAT_2000_ca95 + (int)uStack_14 * 9 + 3);
      *pbVar2 = *pbVar2 & 0xfd;
    }
    bVar16 = *(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3f);
    uVar43 = CONCAT11(uVar15,bVar16);
    uStack_e = (far_t *)(0x1000 << (bVar16 & 0x1f));
    *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0xad) = 0;
    iVar32 = ((int *)((uint)param_1 * 4))[1];
    _fmemset((void *)CONCAT13((char)((uint)iVar32 >> 8),
                              CONCAT12((char)iVar32,*(int *)((uint)param_1 * 4) + 0xaa)),0,3);
    if (*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3f) == '\0') {
      pbVar2 = (byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5d);
      *pbVar2 = *pbVar2 | 4;
    }
    else {
      pbVar2 = (byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5d);
      *pbVar2 = *pbVar2 & 0xf9;
    }
    pbVar2 = (byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5d);
    *pbVar2 = *pbVar2 & 0xf7;
    *(undefined2 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0xa0) = 0;
    *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0xa6) = 0;
    *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0xa5) = 0;
    *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0xa9) = 0;
    bVar16 = *(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3e);
    (*(uint16_t *)((uint8_t *)&(uStack_6))) = (far_t *)CONCAT11(bVar16,(byte)uStack_6);
    if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bVar16 * 0x95) == '\x01') {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(far_t *)uStack_6);
      uVar10 = (uint32_t)uStack_6;
    }
    else {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((far_t *)uStack_6);
      uVar10 = (uint32_t)uStack_6;
    }
    (*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) = (byte)(uVar10 >> 8);
    if ((*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) * 0x95) == '\0') ||
       (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) * 0x95) == '\x05'))
    {
      uStack_6 = (far_t *)CONCAT13(1,uVar10);
    }
    else {
      uStack_6 = (far_t *)(ulong)uVar10;
    }
    *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0xa8) = 0;
    DAT_2000_d1e8 = '\0';
    pfVar42 = (far_t *)&GUnitDescriptions[3].ofs;
    while (pfVar11 = pfVar42, pfVar42 = (far_t *)((int)&pfVar11->ofs + 1), pfVar42 < DAT_2000_ca99)
    {
      uVar46 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
      iVar32 = (int)DAT_2000_ca95;
      if (*(byte *)(iVar32 + (int)pfVar42 * 9 + 2) == param_1) {
        uVar47 = *(undefined2 *)(iVar32 + (int)pfVar42 * 9 + 4);
        uVar15 = (undefined1)uVar47;
        uVar58 = (undefined1)((uint)uVar47 >> 8);
        (*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) = *(byte *)(iVar32 + (int)pfVar42 * 9);
        uStack_16 = (far_t *)ovr_OVC23_55fe_3450();
        x = (uint16_t *)CONCAT11(uVar58,uVar15);
        uVar46 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
        uStack_18 = *(int *)((int)DAT_2000_ca95 + (int)pfVar42 * 9 + 6);
        pfStack_10 = (far_t *)0x0;
        uStack_1a = (uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) << 8;
        while( true ) {
          if (3 < (byte)uStack_1a) break;
          x = (uint16_t *)((int)((int)uStack_16 + (uStack_1a & 0xff)) * 2);
          pfStack_10 = (far_t *)((uint)pfStack_10 |
                                *(uint *)((int)x + (int)DAT_2000_cb09 + uStack_18 * 0x128 + -4) &
                                0x3000);
          uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(byte)uStack_1a + 1);
        }
        pfStack_12 = (far_t *)0x0;
        if ((*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x11e) & 3) == 1) {
          uStack_1a = (uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) << 8;
          while ((byte)uStack_1a < 4) {
            x = (uint16_t *)((int)((int)uStack_16 + (uStack_1a & 0xff)) * 2);
            pfStack_12 = (far_t *)((uint)pfStack_12 |
                                  *(uint *)((int)x + uStack_18 * 0x128 + (int)DAT_2000_cb09 + 0x124)
                                  & 0x3000);
            uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(byte)uStack_1a + 1);
          }
        }
        if ((((uint)uStack_e & (uint)pfStack_10) != 0) || (((uint)uStack_e & (uint)pfStack_12) != 0)
           ) {
          pbVar2 = (byte *)((int)DAT_2000_ca95 + (int)pfVar42 * 9 + 3);
          *pbVar2 = *pbVar2 | 3;
          pcVar25 = (char *)0x195d;
          uVar47 = 0x195d;
          pfVar18 = (far_t *)(*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) - 7);
          iVar32 = (int)DAT_2000_ca95;
          uVar46 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
          if (pfVar18 < (far_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x12)) {
            pbVar33 = (byte *)((int)pfVar18 * 2);
            bVar14 = (byte)pfVar18;
            uVar15 = (undefined1)((uint)pfVar18 >> 8);
            bVar16 = (byte)uVar43;
            bVar13 = (byte)(uVar43 >> 8);
            switch(pfVar18) {
            case (far_t *)0x0:
              AgntAnms[0x68].ey = AgntAnms[0x68].ey | 0x195d;
              pfVar1 = unaff_DI;
              iVar32 = 1 - (pfVar1->ofs & 3);
              pfVar1->ofs = pfVar1->ofs + (uint)(0 < iVar32) * iVar32;
              *(uint8_t *)&pfVar42->ofs = (uint8_t)pfVar42->ofs + 0x1;
              uVar28 = CONCAT11(uVar15,0xf1);
              iVar32 = -*(uint *)(pbVar33 + (int)unaff_DI + -0x79e5);
              puVar6 = (undefined1 *)
                       (uint)(&stack0xffaf < *(undefined1 **)(pbVar33 + (int)unaff_DI + -0x79e5));
              puVar8 = &stack0xfffe + -pfVar42->ofs;
              uVar19 = (uint)(&stack0xfffe < (undefined1 *)pfVar42->ofs || puVar8 < puVar6);
              uVar27 = (int)pbVar33 - *(int *)(pbVar33 + (int)unaff_DI);
              iVar34 = uVar27 - uVar19;
              uVar19 = (uint)(pbVar33 < *(byte **)(pbVar33 + (int)unaff_DI) || uVar27 < uVar19);
              uVar27 = 0x145d - *(uint *)(iVar34 + (int)unaff_DI);
              iVar45 = uVar27 - uVar19;
              uVar19 = (uint)(0x145d < *(uint *)(iVar34 + (int)unaff_DI) || uVar27 < uVar19);
              uVar27 = uVar28 - unaff_DI->ofs;
              iVar60 = uVar27 - uVar19;
              uVar19 = (uint)(uVar28 < unaff_DI->ofs || uVar27 < uVar19);
              uVar27 = (int)(puVar8 + -(int)puVar6) - (int)(&stack0xffaf + iVar32);
              bVar53 = puVar8 + -(int)puVar6 < &stack0xffaf + iVar32 || uVar27 < uVar19;
              uVar27 = uVar27 - uVar19;
              bVar23 = (byte)((uint)iVar60 >> 8);
              bVar24 = (byte)((uint)iVar34 >> 8);
              bVar14 = bVar23 - bVar24;
              bVar50 = bVar23 < bVar24 || bVar14 < bVar53;
              bVar30 = (byte)iVar60;
              bVar14 = bVar14 - bVar53;
              bVar35 = (byte)iVar45;
              bVar23 = bVar35 - bVar14;
              bVar53 = bVar35 < bVar14 || bVar23 < bVar50;
              bVar29 = (byte)((uint)iVar45 >> 8);
              bVar23 = bVar23 - bVar50;
              bVar35 = bVar24 - *(byte *)(iVar34 + -0x4ae6);
              bVar50 = bVar24 < *(byte *)(iVar34 + -0x4ae6) || bVar35 < bVar53;
              bVar35 = bVar35 - bVar53;
              bVar24 = bVar30 - (byte)unaff_DI[0x1286].seg;
              bVar53 = bVar30 < (byte)unaff_DI[0x1286].seg || bVar24 < bVar50;
              bVar24 = bVar24 - bVar50;
              bVar30 = (byte)iVar34 - AgntAnms[0xf].frmid;
              bVar50 = (byte)iVar34 < AgntAnms[0xf].frmid || bVar30 < bVar53;
              bVar30 = bVar30 - bVar53;
              bVar7 = bVar35 - bVar24;
              bVar36 = bVar7 - bVar50;
              puVar31 = (uint *)CONCAT11(bVar36,bVar30);
              uVar19 = (uint)(bVar35 < bVar24 || bVar7 < bVar50);
              uVar28 = uVar27 - uVar43;
              puVar39 = (uint *)(uVar28 - uVar19);
              puVar3 = (uint *)((int)&unaff_DI[-0x15fa].ofs + 1);
              uVar28 = (uint)(uVar27 < uVar43 || uVar28 < uVar19);
              uVar19 = *puVar3;
              uVar27 = *puVar3;
              *puVar3 = (uVar27 - (int)puVar39) - uVar28;
              puVar3 = (uint *)((int)puVar39 + 0x7419);
              uVar28 = (uint)(uVar19 < puVar39 || uVar27 - (int)puVar39 < uVar28);
              uVar27 = *puVar3;
              uVar19 = *puVar3;
              *puVar3 = (uVar19 - uVar43) - uVar28;
              puVar3 = &pfVar11[6].seg;
              uVar19 = (uint)(uVar27 < uVar43 || uVar19 - uVar43 < uVar28);
              puVar40 = (uint *)*puVar3;
              uVar43 = *puVar3;
              *puVar3 = (uVar43 - (int)puVar31) - uVar19;
              *(far_t **)(&stack0xffad + iVar32) = unaff_DI;
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
              uVar43 = (uint)(puVar40 < puVar31 || uVar43 - (int)puVar31 < uVar19);
              (*(uint16_t *)((uint8_t *)&(s_Peaceful_2410_2915) + 4)) = (0x6665U - (int)unaff_DI) - uVar43;
              uVar43 = (uint)((uint)0x6665 < unaff_DI || (uint)(0x6665U - (int)unaff_DI) < uVar43);
              bVar53 = (uint)AgntAnms[6].y < CONCAT11(bVar29,bVar23);
              uVar19 = AgntAnms[6].y - CONCAT11(bVar29,bVar23);
              AgntAnms[6].y = uVar19 - uVar43;
              puVar6 = (undefined1 *)(uint)(bVar53 || uVar19 < uVar43);
              puVar8 = &stack0xffad + (iVar32 - (int)unaff_DI);
              bVar53 = (far_t *)(&stack0xffad + iVar32) < unaff_DI || puVar8 < puVar6;
              iVar32 = -(int)puVar6;
              puVar37 = (uint *)(puVar8 + iVar32);
              bVar50 = bVar23 < bVar13 || (byte)(bVar23 - bVar13) < bVar53;
              bVar35 = (bVar23 - bVar13) - bVar53;
              bVar53 = bVar14 < bVar30 || (byte)(bVar14 - bVar30) < bVar50;
              bVar23 = (bVar14 - bVar30) - bVar50;
              bVar14 = bVar35 - bVar24;
              bVar50 = bVar35 < bVar24 || bVar14 < bVar53;
              bVar14 = bVar14 - bVar53;
              pbVar2 = (uint8_t *)((int)puVar31 + (int)pfVar42) + -0x60e8;
              bVar53 = *pbVar2 < bVar13 || (byte)(*pbVar2 - bVar13) < bVar50;
              *pbVar2 = (*pbVar2 - bVar13) - bVar50;
              puVar3 = puVar39 + -0x3974;
              bVar13 = (byte)*puVar3 - bVar14;
              bVar50 = (byte)*puVar3 < bVar14 || bVar13 < bVar53;
              *(byte *)puVar3 = bVar13 - bVar53;
              pbVar2 = (byte *)((char *)"%s (%u/%u): Held by %s." + 0xc + (int)pfVar11);
              bVar51 = *pbVar2 < bVar24 || (byte)(*pbVar2 - bVar24) < bVar50;
              *pbVar2 = (*pbVar2 - bVar24) - bVar50;
              puVar3 = puVar39 + 0xc;
              bVar50 = (byte)*puVar3 < bVar29;
              bVar13 = (byte)*puVar3 - bVar29;
              bVar52 = bVar50 || bVar13 < bVar51;
              bVar56 = SBORROW1((byte)*puVar3,bVar29) != SBORROW1(bVar13,bVar51);
              *(byte *)puVar3 = bVar13 - bVar51;
              bVar55 = (char)(byte)*puVar3 < '\0';
              bVar54 = (byte)*puVar3 == 0;
              bVar53 = !bVar56;
              puVar40 = puVar39;
              if (!bVar53) {
                pfVar1 = unaff_DI;
                unaff_DI = (far_t *)((int)&unaff_DI->ofs + 1);
                uVar5 = in(CONCAT11(bVar29,bVar14));
                *(uint8_t *)&pfVar1->ofs = uVar5;
                pbVar2 = (byte *)((int)&pfVar11[6].ofs + 1);
                bVar7 = *pbVar2;
                bVar35 = *pbVar2;
                *pbVar2 = (bVar35 - bVar23) - bVar52;
                *(uint **)(puVar8 + iVar32 + -2) = puVar31;
                ((uint8_t *)((int)puVar39 + (int)pfVar42))[0x18] =
                     (((uint8_t *)((int)puVar39 + (int)pfVar42))[0x18] - bVar16) -
                     (bVar7 < bVar23 || (byte)(bVar35 - bVar23) < bVar52);
                *(uint *)((int)puVar31 + (int)pfVar42) =
                     *(uint *)((int)puVar31 + (int)pfVar42) ^ (uint)puVar31;
                *(uint *)((int)puVar31 + (int)pfVar42) =
                     *(uint *)((int)puVar31 + (int)pfVar42) | (uint)puVar31;
                *(uint8_t *)((int)puVar31 + (int)pfVar42) =
                     *(uint8_t *)((int)puVar31 + (int)pfVar42) + bVar30;
                *puVar31 = ~*puVar31;
                puVar40 = (uint *)*puVar39;
                uVar43 = CONCAT11(bVar23,bVar24 - 0x18) & 0x9e1f;
                bVar55 = (int)uVar43 < 0;
                bVar54 = uVar43 == 0;
                puVar37 = puVar39 + 3;
              }
              bVar52 = bVar53 && bVar52;
              uVar46 = *puVar37;
              if (bVar54 || (bVar53 && bVar56) != bVar55) {
                bVar55 = bVar52;
                if ((!bVar53 || !bVar50 && bVar13 >= bVar51) && !bVar54) {
                  *puVar37 = (uint)puVar40;
                  uVar46 = *puVar37;
                  pcVar25 = (char *)(int)(char)bVar16 + -0x1d67;
                  iVar32 = (int)pcVar25 - (int)(uint)bVar52;
                  *puVar37 = iVar32;
                  *(uint8_t *)&pfVar42->ofs = -(uint8_t)pfVar42->ofs;
                  return (far_t *)((iVar32 + -0x1d32) -
                                  (uint)((char *)(int)(char)bVar16 <
                                         (char *)"magicians\' cottage" + 9 ||
                                        pcVar25 < (char *)(uint)bVar52));
                }
              }
              else {
                bVar55 = bVar16 < 0x74 || (byte)(bVar16 + 0x8c) < bVar52;
                bVar16 = (bVar16 + 0x8c) - bVar52;
              }
              bVar53 = bVar16 < 100 || (byte)(bVar16 + 0x9c) < bVar55;
              bVar13 = (bVar16 + 0x9c) - bVar55;
              bVar16 = bVar13 - 0x39;
              bVar50 = bVar13 < 0x39 || bVar16 < bVar53;
              bVar16 = bVar16 - bVar53;
              bVar13 = bVar16 - 0x14;
              bVar53 = bVar16 < 0x14 || bVar13 < bVar50;
              bVar13 = bVar13 - bVar50;
              bVar16 = bVar13 - 8;
              bVar50 = bVar13 < 8 || bVar16 < bVar53;
              bVar16 = bVar16 - bVar53;
              bVar13 = bVar16 - 5;
              bVar23 = bVar13 - bVar50;
              iVar32 = ((int)puVar40 - (int)puVar31) -
                       (uint)(bVar23 < 0xfa || (byte)(bVar23 + 6) < (bVar16 < 5 || bVar13 < bVar50))
              ;
              uVar19 = (uint)pfVar42 & *(uint *)((uint8_t *)((int)puVar31 + (int)pfVar42) + -0x6bdd)
              ;
              uVar27 = (uint)unaff_DI & *(uint *)((uint8_t *)((int)puVar31 + (int)unaff_DI) + 0x23);
              *puVar37 = uVar19;
              uVar19 = uVar19 & *(uint *)((int)puVar31 + uVar27);
              uVar43 = CONCAT11(bVar29,bVar14) & *(uint *)(iVar32 + uVar19);
              puVar40 = (uint *)CONCAT11(bVar36,bVar30 & bVar36 &
                                                *(byte *)((int)&_streams[0xc].curp +
                                                         CONCAT11(bVar36,bVar30 & bVar36)));
              uVar47 = *puVar37;
              *(uint *)(iVar32 + uVar19) = *(uint *)(iVar32 + uVar19) ^ (uint)(puVar37 + 1);
              *(int *)(iVar32 + uVar19) = *(int *)(iVar32 + uVar19) - (int)(puVar37 + 1);
              bVar16 = in(uVar43);
              uVar19 = uVar19 & uVar43;
              puVar3 = (uint *)((int)puVar40 + (int)((char *)"+%d ring of prot." + 1 + uVar19));
              *puVar3 = *puVar3 & uVar27;
              *(uint *)(uVar27 + 0x21) = *(uint *)(uVar27 + 0x21) & (uint)puVar40;
              *puVar40 = *puVar40 & uVar27;
              puVar3 = (uint *)&AgntAnms[0x5c].sx;
              *puVar3 = *puVar3 & (uint)(puVar37 + 1);
              puVar3 = (uint *)((int)puVar40 + uVar19);
              *puVar3 = *puVar3 & CONCAT11((char)((uint)uVar47 >> 8),bVar16);
              bVar14 = -(0x99 < bVar16);
              return (far_t *)(uint)(byte)(bVar14 + (9 < (bVar14 & 0xf) | 9 < (bVar16 & 0xf) | in_AF
                                                    ) * '\x06' +
                                          (0x99 < bVar14 || 0x99 < bVar16) * '`');
            case (far_t *)0x1:
              *(uint *)(&stack0x8ed6 + (int)unaff_DI) =
                   *(uint *)(&stack0x8ed6 + (int)unaff_DI) & uVar43;
              return pfVar18;
            default:
              goto switchD_5000_123d_caseD_2;
            case (far_t *)0x3:
            case (far_t *)0x14:
              goto switchD_5000_123d_caseD_3;
            case (far_t *)0x4:
              if (uVar43 != 1) {
                x = *(uint16_t **)(pbVar33 + -0x6edc);
              }
              break;
            case (far_t *)0x5:
              do {
                uVar9 = *(undefined4 *)(((uint)pfVar18 & 0xff) << 2);
                uVar19 = (uint)*(byte *)((int)uVar9 + 0x2f);
                ovr_blitLabel((char *)CONCAT13((char)((uint)auStackY_11a
                                                            [(int)pfVar42 * 2 + uVar19 * 8 + 1] >> 8
                                                     ),CONCAT12((char)auStackY_11a
                                                                      [(int)pfVar42 * 2 +
                                                                       uVar19 * 8 + 1],
                                                                auStackY_11a
                                                                [(int)pfVar42 * 2 + uVar19 * 8])),
                              (uint8_t *)CONCAT22(unaff_SI,pfVar22),
                              CONCAT11(in_stack_0000ffb9,in_stack_0000ffb8),(uint8_t)iVar60);
                while( true ) {
                  OVC27_5ded_1433();
                  ovr_stsprintf(acStackY_13e,"%d",(char *)uStack_14);
                  iVar32 = ovr_font_302d_06ea();
                  TextBlitX = 0x89 - iVar32;
                  ovr_blitLabel((char *)CONCAT22(unaff_SS,acStackY_13e),
                                (uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0x50);
                  ovr_stsprintf(acStackY_13e,"%d",(char *)uStack_16);
                  iVar32 = ovr_font_302d_06ea();
                  pcVar25 = (char *)(0xd4 - iVar32);
                  TextBlitX = (uint16_t)pcVar25;
                  ovr_blitLabel((char *)CONCAT22(unaff_SS,acStackY_13e),
                                (uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0x50);
                  pfVar42 = (far_t *)((int)&pfVar42->ofs + 1);
LAB_4d05_323c:
                  TextBlitY = TextBlitY + 0xc;
                  cVar17 = (char)uVar43;
                  if ((int)((uint)local_c >> 8) <= (int)pfVar42) goto LAB_4d05_32b8;
                  TextBlitX = 0x11;
                  if ((4 < (int)pfVar42) && ((char)local_c != '\0')) break;
                  ovr_blitLabel((char *)CONCAT22(auStackY_96[(int)pfVar42 * 2 + 1],
                                                 (char *)auStackY_96[(int)pfVar42 * 2]),
                                (uint8_t *)
                                CONCAT13((char)(Font02.seg >> 8),
                                         CONCAT12((char)Font02.seg,Font02.ofs)),319,0xe0);
                }
                pfVar18 = (far_t *)(uint)param_1;
              } while( true );
            case (far_t *)0x6:
              *(uint *)(&stack0x681c + (int)pfVar42) =
                   *(uint *)(&stack0x681c + (int)pfVar42) & uVar43;
            case (far_t *)0xb:
              *(uint *)(&stack0x681c + (int)pfVar42) =
                   *(uint *)(&stack0x681c + (int)pfVar42) & uVar43;
              ovr_blitLabel((char *)CONCAT22(pfVar22,&stack0xfffe),
                            (uint8_t *)
                            CONCAT13(in_stack_0000ffb9,CONCAT12(in_stack_0000ffb8,unaff_SI)),iVar60,
                            (uint8_t)in_stack_0000ffbc);
              iVar32 = ovr_font_302d_06ea();
              pcVar25 = (char *)(0xd4 - iVar32);
              iVar60 = 222;
              in_stack_0000ffb8 = (undefined1)Font02.seg;
              in_stack_0000ffb9 = (undefined1)(Font02.seg >> 8);
              pfVar22 = (far_t *)((char *)"puppetmaker" + 3);
              TextBlitX = (uint16_t)pcVar25;
              unaff_SI = (undefined1 *)Font02.ofs;
              ovr_blitLabel("POPULATION",
                            (uint8_t *)
                            CONCAT13(in_stack_0000ffb9,CONCAT12(in_stack_0000ffb8,Font02.ofs)),222,
                            0xe0);
              pfVar42 = (far_t *)0x0;
              goto LAB_4d05_323c;
            case (far_t *)0x7:
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
              return pfVar18;
            case (far_t *)0x8:
              bVar23 = (&stack0xfffe)[(int)unaff_DI];
              in_AF = 9 < (bVar14 & 0xf) | in_AF;
              uVar38 = (uint)&stack0xffb4 ^ *(uint *)(pbVar33 + (int)pfVar42);
              uVar19 = (uint)pbVar33 ^ (uint)pfVar42;
              uVar27 = CONCAT11((byte)(uVar19 >> 8) ^ *(byte *)((int)unaff_DI + uVar19 + 0x8332),
                                (char)uVar19);
              bVar24 = bVar13 ^ 0x5d ^ *(byte *)((int)&unaff_DI[0xc].seg + uVar27);
              uVar19 = CONCAT11(bVar23,bVar24) ^ 0x1900;
              *(uint *)(&stack0xfffe + (int)pfVar42) =
                   *(uint *)(&stack0xfffe + (int)pfVar42) ^ (uint)pfVar42;
              uVar41 = (int)pfVar42 - *(uint *)(&stack0xfffe + (int)pfVar42);
              uVar27 = uVar27 ^ uVar38;
              uVar28 = (uint)&stack0xfffe ^ uVar27;
              uVar43 = CONCAT11(uVar15,bVar14 + in_AF * -6 + (0x99 < bVar14) * -0x60 + '2' +
                                       (pfVar42 < *(far_t **)(&stack0xfffe + (int)pfVar42))) -
                       0x5ceU ^ uVar43;
              puVar3 = (uint *)((int)unaff_DI + uVar27 + 0xa231);
              *puVar3 = *puVar3 ^ uVar41;
              *(uint *)((char *)"%s: %s %d gold. Provides housing for %d %s." + 3 + uVar27) =
                   *(uint *)((char *)"%s: %s %d gold. Provides housing for %d %s." + 3 + uVar27) ^
                   uVar19;
              puVar3 = (uint *)(uVar28 + uVar41 + 0x31);
              *puVar3 = *puVar3 ^ (uint)unaff_DI;
              iVar60 = uVar41 + 1;
              puVar3 = (uint *)((int)&unaff_DI->ofs + uVar28);
              *puVar3 = *puVar3 ^ uVar38;
              unaff_DI->ofs = unaff_DI->ofs ^ uVar19;
              puVar44 = (undefined2 *)((uint)unaff_DI ^ uVar38);
              bVar35 = (byte)(uVar43 >> 8);
              bVar14 = (byte)uVar43 ^ bVar24;
              pbVar2 = (byte *)((int)puVar44 + uVar28 + 0xa330);
              *pbVar2 = *pbVar2 ^ bVar23 ^ 0x19;
              *(byte *)(puVar44 + -0x3be8) = *(byte *)(puVar44 + -0x3be8) ^ (byte)uVar27;
              pbVar2 = (byte *)(uVar27 + iVar60 + 0x30);
              bVar23 = (byte)(uVar27 >> 8);
              *pbVar2 = *pbVar2 ^ bVar23;
              pbVar33 = (byte *)(puVar44 + 1);
              uVar46 = in(uVar19);
              *puVar44 = uVar46;
              pbVar2 = (byte *)(uVar27 + iVar60 + 0x30);
              *pbVar2 = *pbVar2 ^ (byte)uVar27;
              *(uint *)(uVar38 - 2) = uVar19;
              *pbVar33 = *pbVar33 ^ bVar23;
              *pbVar33 = *pbVar33 ^ bVar13;
              *(byte *)(uVar28 + iVar60) = *(byte *)(uVar28 + iVar60) ^ bVar35;
              *pbVar33 = *pbVar33 ^ bVar16;
              *(byte *)(uVar28 + iVar60) = *(byte *)(uVar28 + iVar60) ^ bVar14;
              in_AF = 9 < (bVar14 & 0xf) | in_AF;
              bVar16 = bVar14 + in_AF * -6 + (0x99 < bVar14) * -0x60;
              iVar32 = *(int *)(uVar38 - 2);
              uVar43 = CONCAT11(bVar35 ^ bVar23,
                                bVar16 + (9 < (bVar16 & 0xf) | in_AF) * -6 +
                                (0x99 < bVar16 || 0x99 < bVar14) * -0x60) ^ 0xaf;
              uVar28 = uVar28 ^ uVar43;
              bVar16 = (byte)uVar43 ^ (byte)*(undefined2 *)(uVar27 + iVar60);
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              *(char *)(uVar27 + iVar60) = *(char *)(uVar27 + iVar60) + bVar16;
              pcVar57 = (char *)(iVar32 + -0x75);
              *pcVar57 = *pcVar57 + bVar24;
              in(uVar19);
              *(int *)(uVar38 - 0x10) = iVar60;
              *(int *)(uVar38 - 0x12) = iVar32;
              iVar32 = *(int *)(uVar28 + 6);
              iVar60 = *(int *)(uVar28 + 8);
              if ((((iVar32 < 0) || (iVar60 < 0)) || (0x93 < iVar32 + 1)) || (0x3b < iVar60 + 1)) {
                DAT_2000_d090 = 2;
                pfVar22 = (far_t *)0x0;
              }
              else {
                uVar46 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
                if (((*(uint *)((int)DAT_2000_cb09 + iVar60 * 0x128 + iVar32 * 2) & 3) == 0) &&
                   ((*(uint *)(iVar60 * 0x128 + (int)DAT_2000_cb09 + iVar32 * 2 + 0x128) & 3) == 0))
                {
                  *(int *)(uVar28 - 10) =
                       (int)*(char *)(iVar60 * 0x94 + DAT_2000_cb05 + iVar32 + 0x94);
                  *(int *)(uVar28 - 8) =
                       (int)*(char *)(iVar60 * 0x94 + DAT_2000_cb05 + iVar32 + 0x95);
                  iVar32 = *(int *)(uVar28 - 10);
                  *(undefined2 *)(uVar28 - 2) = *(undefined2 *)(uVar28 - 10);
                  if (*(int *)(uVar28 - 8) < iVar32) {
                    iVar32 = *(int *)(uVar28 - 8);
                  }
                  if (*(int *)(uVar28 - 2) < *(int *)(uVar28 - 8)) {
                    *(undefined2 *)(uVar28 - 2) = *(undefined2 *)(uVar28 - 8);
                  }
                  if (*(int *)(uVar28 - 2) - iVar32 < 9) {
                    DAT_2000_d090 = 3;
                    pfVar22 = (far_t *)((char *)"arena" + 5);
                  }
                  else {
                    pfVar22 = (far_t *)0x0;
                  }
                }
                else {
                  DAT_2000_d090 = 1;
                  pfVar22 = (far_t *)0x0;
                }
              }
              return pfVar22;
            case (far_t *)0x9:
              do {
                OVC22_5087_056e();
                do {
                  uStack_16 = (far_t *)((int)uStack_16 + 1);
                  if ((int)(uint)DAT_2000_d1e6 <= (int)uStack_16) {
                    GGameState = 0x3e;
                    if (DebugVerbose != false) {
                      printf("%d \r",0x3e);
                    }
                    unaff_DI = (far_t *)&GUnitDescriptions[3].ofs;
                    goto LAB_5087_202c;
                  }
                } while (*(char *)((int)*(undefined4 *)((int)uStack_16 * 4) + 0x3d) == '\0');
              } while( true );
            case (far_t *)0xa:
              pcVar25 = (char *)"%d %s%s homed." + 0xc;
              break;
            case (far_t *)0xc:
              iVar60 = *(int *)(pbVar33 + -0x6d44);
              do {
                pfVar22 = (far_t *)uStack_6;
                if (*(byte *)(iVar32 + iVar60 * 9 + 2) == param_1) {
                  if ((byte)uStack_6 == (*(uint8_t *)((uint8_t *)&(uStack_6) + 1))) {
LAB_5087_4abe:
                    (*(uint16_t *)((uint8_t *)&(uStack_6))) = pfVar22;
                    if ((byte)uStack_8 < DAT_2000_d3c6) {
                      pfStack_a = (far_t *)*(undefined2 *)
                                            (iVar32 + *(int *)((uStack_8 & 0xff) * 2 + -0x6d44) * 9
                                            + 4);
                      local_c = (far_t *)*(undefined2 *)
                                          (iVar32 + *(int *)((uStack_8 & 0xff) * 2 + -0x6d44) * 9 +
                                          6);
                    }
                    else {
                      pfStack_a = (far_t *)*(undefined2 *)
                                            ((int)*(undefined4 *)((uint)param_1 << 2) + 0x39);
                      local_c = (far_t *)*(undefined2 *)
                                          ((int)*(undefined4 *)((uint)param_1 << 2) + 0x3b);
                    }
                    uVar46 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
                    iVar60 = (int)*(undefined4 *)((uint)param_1 << 2);
                    iVar32 = *(int *)(iVar60 + 0x58);
                    if ((iVar32 < 1) && ((iVar32 < 0 || (*(uint *)(iVar60 + 0x56) < 10)))) {
                      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(far_t *)uStack_6);
                    }
                    else {
                      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((far_t *)uStack_6);
                    }
                    if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 +
                                  (uint)*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3e) *
                                  0x95) & 0x80) == 0) {
                      uStack_6 = (far_t *)(ulong)(uint32_t)uStack_6;
                    }
                    else {
                      uStack_6 = (far_t *)CONCAT13(3,(uint32_t)uStack_6);
                    }
                    if ((*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5d) & 2) != 0) {
                      uStack_6 = (far_t *)((ulong)uStack_6 | 0x1000000);
                    }
                    if ((*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5d) & 4) != 0) {
                      uStack_6 = (far_t *)((ulong)uStack_6 | 0x2000000);
                    }
                    bVar16 = OVC22_5087_416e();
                    pfVar22 = (far_t *)(uint)bVar16;
                    if (pfVar22 != (far_t *)0x0) {
                      if (pfVar22 != (far_t *)((int)(undefined4 *)&_DATA + 1U)) {
                        return pfVar22;
                      }
                      uStack_e = (far_t *)OVC22_5087_4576();
                      if (uStack_e == (far_t *)0x0) {
                        pfStack_a = (far_t *)*(undefined2 *)
                                              ((int)*(undefined4 *)((uint)param_1 << 2) + 0x39);
                        local_c = (far_t *)*(undefined2 *)
                                            ((int)*(undefined4 *)((uint)param_1 << 2) + 0x3b);
                      }
                      else {
                        if ((*(uint *)((int)uStack_e * 0x27 + 0x121) & 0x60) == 0) {
                          uVar46 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
                          iVar60 = (int)*(undefined4 *)((uint)param_1 << 2);
                          iVar32 = *(int *)(iVar60 + 0x58);
                          if ((iVar32 < 0) ||
                             ((iVar32 == 0 &&
                              (*(uint *)(iVar60 + 0x56) < *(uint *)((int)uStack_e * 0x27 + 0x125))))
                             ) {
                            uVar46 = (undefined2)
                                     ((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
                            iVar32 = (int)*(undefined4 *)((uint)param_1 << 2);
                            *(undefined2 *)(iVar32 + 0x58) = 0;
                            *(undefined2 *)(iVar32 + 0x56) = 0;
                          }
                          else {
                            uVar19 = *(uint *)((int)uStack_e * 0x27 + 0x125);
                            uVar46 = (undefined2)
                                     ((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
                            iVar32 = (int)*(undefined4 *)((uint)param_1 << 2);
                            puVar3 = (uint *)(iVar32 + 0x56);
                            uVar43 = *puVar3;
                            *puVar3 = *puVar3 - uVar19;
                            piVar4 = (int *)(iVar32 + 0x58);
                            *piVar4 = *piVar4 - (uint)(uVar43 < uVar19);
                          }
                        }
                        ovr_OVC23_55fe_1e87();
                      }
                    }
                    if (*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3f) == '\0') {
                      if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5b) <
                          *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d)) {
                        pfVar22 = (far_t *)ovr_OVC18_48ac_0382();
                      }
                      else {
                        pfVar22 = (far_t *)ovr_OVC18_48ac_0382();
                      }
                    }
                    else {
                      pfVar22 = (far_t *)ovr_OVC18_48ac_0382();
                    }
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
                    return pfVar22;
                  }
                  uStack_6 = (far_t *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),(byte)uStack_6 + '\x01');
                }
                do {
                  bVar16 = (byte)uStack_8 + 1;
                  uStack_8 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_8) + 1)),bVar16);
                  pfVar22 = (far_t *)uStack_6;
                  if (DAT_2000_d3c6 <= bVar16) goto LAB_5087_4abe;
                } while (*(char *)((uint)*(byte *)(iVar32 + *(int *)((uint)bVar16 * 2 + -0x6d44) * 9
                                                  ) * 0x27 + 0x133) != '\x12');
                iVar60 = *(int *)((uint)bVar16 * 2 + -0x6d44);
              } while( true );
            case (far_t *)0xd:
              bVar16 = (byte)((uint)pbVar33 >> 8);
              if (!CARRY1(bVar16,bVar16) && ((uint)pbVar33 & 0x7f00) != 0) {
                iVar32 = ovr_OVC23_55fe_2937();
                if (iVar32 == -1) {
                  pfVar22 = (far_t *)(uint)*(byte *)((int)DAT_2000_ca95 + (*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) * 9);
                  if ((*(uint *)((int)pfVar22 * 0x27 + 0x121) & 0x20) == 0) {
                    pfVar22 = (far_t *)0x0;
                  }
                  else if (*(char *)((int)pfVar22 * 0x27 + 0x131) == '\0') {
                    if (*(char *)((int)*(undefined4 *)((uint)(byte)param_3 << 2) + 0x2f) == '\x05')
                    {
                      pfVar22 = pfVar22 + 6;
                    }
                    else {
                      pfVar22 = (far_t *)&pfVar22[1].seg;
                    }
                  }
                }
                else {
                  pfVar22 = (far_t *)0x0;
                }
                return pfVar22;
              }
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            case (far_t *)0xe:
              *pbVar33 = *pbVar33 | bVar14;
              if (uVar43 != 0) {
                pfVar18 = (far_t *)*(far_t **)((char *)"sage" + 3);
              }
              *(uint *)((char *)"squares" + 3) = *(uint *)((char *)"squares" + 3) ^ (uint)pfVar18;
              uVar15 = in(5);
              if (((uint)pfVar18 | 0x606) == 0) {
                unaff_DI->ofs =
                     unaff_DI->ofs +
                     ((CONCAT11((char)(((uint)pfVar18 | 0x606) >> 8),uVar15) + 0x53e) -
                     unaff_DI->ofs);
              }
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            case (far_t *)0xf:
              do {
                uVar43 = (int)pfVar22 -
                         *(int *)(Entities.ofs +
                                 CONCAT11((char)((int)pfVar18 %
                                                (int)(char)(&stack0x0035)[(int)pfVar42]),
                                          (char)((int)pfVar18 /
                                                (int)(char)(&stack0x0035)[(int)pfVar42])) *
                                 (int)pcVar25);
                uVar27 = (int)uVar43 >> 0xf;
                uVar19 = *(int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x3b) -
                         *(int *)(Entities.ofs + (int)local_c * 0x37 + 2);
                uVar28 = (int)uVar19 >> 0xf;
                pfVar42 = (far_t *)((int)((uVar43 ^ uVar27) - uVar27) / 2 +
                                   ((uVar19 ^ uVar28) - uVar28));
                if (pfVar42 < uStack_e) {
                  uStack_e = pfVar42;
                  unaff_DI = local_c;
                }
                if (pfVar42 < (far_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 6)) {
                  piVar4 = (int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x43);
                  *piVar4 = *piVar4 + 1;
                }
                do {
                  while( true ) {
                    local_c = (far_t *)((int)&local_c->ofs + 1);
                    while (EntityCount <= local_c) {
                      *(undefined2 *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x4b) = unaff_DI;
                      uStack_16 = (far_t *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_16) + 1)),0xff);
                      if (*(char *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x40) != '\0') {
                        pfStack_10 = (far_t *)0xffff;
                        for (local_c = (far_t *)0x0; (int)local_c < (int)(uint)DAT_2000_d1e6;
                            local_c = (far_t *)((int)&local_c->ofs + 1)) {
                          if ((*(char *)((int)*(undefined4 *)((int)local_c << 2) + 0x3f) !=
                               *(char *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x3f)) &&
                             (uVar43 = *(int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x39) -
                                       *(int *)((int)*(undefined4 *)((int)local_c << 2) + 0x39),
                             uVar27 = (int)uVar43 >> 0xf,
                             uVar19 = *(int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x3b) -
                                      *(int *)((int)*(undefined4 *)((int)local_c << 2) + 0x3b),
                             uVar28 = (int)uVar19 >> 0xf,
                             pfVar42 = (far_t *)((int)((uVar43 ^ uVar27) - uVar27) / 2 +
                                                ((uVar19 ^ uVar28) - uVar28)), pfVar42 < pfStack_10)
                             ) {
                            uStack_16 = (far_t *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_16) + 1)),(char)local_c);
                            pfStack_10 = pfVar42;
                          }
                        }
                      }
                      *(undefined1 *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x49) =
                           (undefined1)uStack_16;
                      do {
                        pfStack_a = (far_t *)((int)&pfStack_a->ofs + 1);
                        if ((int)(uint)DAT_2000_d1e6 <= (int)pfStack_a) {
                          for (pfStack_a = (far_t *)0x0; (int)pfStack_a < (int)(uint)DAT_2000_d1e6;
                              pfStack_a = (far_t *)((int)pfStack_a + 1)) {
                            if ((*(char *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x40) != '\0'
                                ) && (*(char *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x3d) !=
                                      '\0')) {
                              OVC25_5b66_1929();
                              if (*(int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x4b) == -1)
                              {
                                uStack_14 = (far_t *)0xffff;
                              }
                              else {
                                iVar32 = *(int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x4b);
                                uVar43 = *(int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x39)
                                         - *(int *)(Entities.ofs + iVar32 * 0x37);
                                uVar27 = (int)uVar43 >> 0xf;
                                uVar19 = *(int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x3b)
                                         - *(int *)(Entities.ofs + iVar32 * 0x37 + 2);
                                uVar28 = (int)uVar19 >> 0xf;
                                uStack_14 = (far_t *)((int)((uVar43 ^ uVar27) - uVar27) / 2 +
                                                     ((uVar19 ^ uVar28) - uVar28));
                              }
                              if ((*(int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x43) == 0)
                                 || ((far_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl."
                                              + 6) <= uStack_14)) {
                                if ((*(char *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x49) ==
                                     -1) || ((*(byte *)((int)*(undefined4 *)((int)pfStack_a << 2) +
                                                       0x5d) & 1) == 0)) {
                                  if (*(uint *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x47) <
                                      10) {
                                    OVC25_5b66_038d();
                                    *(undefined1 *)
                                     ((int)*(undefined4 *)((int)pfStack_a << 2) + 0x4a) = 0;
                                  }
                                  else {
                                    *(undefined1 *)
                                     ((int)*(undefined4 *)((int)pfStack_a << 2) + 0x4a) = 0;
                                    uStack_18 = CONCAT11(*(undefined1 *)
                                                          ((int)*(undefined4 *)((int)pfStack_a << 2)
                                                          + 0x3e),(undefined1)uStack_18);
                                    iVar32 = OVC25_5b66_18cc();
                                    uStack_6 = (far_t *)CONCAT22(iVar32,(far_t *)uStack_6);
                                    if ((int)(uint)DAT_2000_d2e6 < iVar32) {
                                      uVar20 = ovr_randBelow(0x28);
                                      (*(uint16_t *)((uint8_t *)&(uStack_6))) =
                                           (far_t *)((code *)init_3381_08dc +
                                                    (uVar20 & 0xff) +
                                                    *(int *)((int)*(undefined4 *)
                                                                   ((int)pfStack_a << 2) + 0x39));
                                      if ((int)((code *)init_3381_08dc +
                                               (uVar20 & 0xff) +
                                               *(int *)((int)*(undefined4 *)((int)pfStack_a << 2) +
                                                       0x39)) < 4) {
                                        (*(uint16_t *)((uint8_t *)&(uStack_6))) =
                                             (far_t *)"Borland C++ - Copyright 1991 Borland Intl.";
                                      }
                                      if (0x8c < (int)(far_t *)uStack_6) {
                                        (*(uint16_t *)((uint8_t *)&(uStack_6))) = (far_t *)&_brklvl;
                                      }
                                      uVar20 = ovr_randBelow(0x14);
                                      uStack_8 = *(int *)((int)*(undefined4 *)((int)pfStack_a << 2)
                                                         + 0x3b) + -10 + (uVar20 & 0xff);
                                      if ((int)uStack_8 < 1) {
                                        uStack_8 = 1;
                                      }
                                      if (0x3a < (int)uStack_8) {
                                        uStack_8 = 0x3a;
                                      }
                                      OVC25_5b66_0530();
                                    }
                                  }
                                }
                                else {
                                  OVC25_5b66_080f();
                                  uStack_16 = (far_t *)CONCAT11(*(undefined1 *)
                                                                 ((int)*(undefined4 *)
                                                                        ((int)pfStack_a << 2) + 0x49
                                                                 ),(undefined1)uStack_16);
                                  if ((0xe < *(uint *)((int)*(undefined4 *)((int)pfStack_a << 2) +
                                                      0x47)) &&
                                     (OVC25_5b66_00ff(),
                                     *(char *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x4a) !=
                                     '\x02')) {
                                    uVar20 = 0xa000;
                                    ovr_OVC23_55fe_3450();
                                    pcStackY_60 = (char *)0xc5d4;
                                    pcVar57 = ovr_stsprintf(acStackY_68,
                                                                                                                        
                                                  "Spies report %s heading towards stronghold. (%d, %d)"
                                                  ,(char *)*(undefined2 *)
                                                            ((int)&far_t_ARRAY_2410_26f7[0].seg + 1
                                                            + (uint)*(byte *)((int)*(undefined4 *)
                                                                                    ((int)pfStack_a
                                                                                    << 2) + 0x3e) *
                                                              0x95));
                                    ovr_uiNotify(pcVar57,uVar20);
                                  }
                                  OVC25_5b66_038d();
                                  *(undefined1 *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x4a)
                                       = 2;
                                }
                              }
                              else {
                                OVC25_5b66_080f();
                                if (9 < *(uint *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x47))
                                {
                                  OVC25_5b66_038d();
                                }
                                OVC25_5b66_038d();
                                *(undefined1 *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x4a) =
                                     1;
                              }
                            }
                          }
                          pfVar22 = (far_t *)OVC25_5b66_12de();
                          return pfVar22;
                        }
                      } while (*(char *)((int)*(undefined4 *)((int)pfStack_a * 4) + 0x3d) == '\0');
                      *(undefined2 *)((int)*(undefined4 *)((int)pfStack_a * 4) + 0x47) = 0;
                      *(undefined2 *)((int)*(undefined4 *)((int)pfStack_a * 4) + 0x41) = 0;
                      *(undefined2 *)((int)*(undefined4 *)((int)pfStack_a * 4) + 0x43) = 0;
                      *(undefined2 *)((int)*(undefined4 *)((int)pfStack_a * 4) + 0x45) = 0;
                      uStack_e = (far_t *)0xffff;
                      unaff_DI = (far_t *)0xffff;
                      pfStack_12 = (far_t *)ovr_OVC23_55fe_3450();
                      local_c = (far_t *)0x0;
                    }
                    uVar48 = Entities.seg;
                    uVar20 = Entities.ofs;
                    if ((far_t *)(uint)*(byte *)(uVar20 + (int)local_c * 0x37 + 0x1a) != pfStack_a)
                    break;
                    uVar43 = *(int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x39) -
                             *(int *)(uVar20 + (int)local_c * 0x37);
                    uVar27 = (int)uVar43 >> 0xf;
                    uVar19 = *(int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x3b) -
                             *(int *)(uVar20 + (int)local_c * 0x37 + 2);
                    uVar28 = (int)uVar19 >> 0xf;
                    pfVar42 = (far_t *)((int)((uVar43 ^ uVar27) - uVar27) / 2 +
                                       ((uVar19 ^ uVar28) - uVar28));
                    piVar4 = (int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x45);
                    *piVar4 = *piVar4 + 1;
                    if (((pfVar42 < (far_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." +
                                             6)) &&
                        (piVar4 = (int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x41),
                        *piVar4 = *piVar4 + 1,
                        *(int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x3b) ==
                        *(int *)(Entities.ofs + (int)local_c * 0x37 + 2))) &&
                       (pfVar22 = (far_t *)ovr_OVC23_55fe_3450(), pfVar22 == pfStack_12)) {
                      piVar4 = (int *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x47);
                      *piVar4 = *piVar4 + 1;
                    }
                  }
                } while (*(char *)((int)(char **)GMenuStrings +
                                  (uint)*(byte *)(uVar20 + (int)local_c * 0x37 + 0xd) * 0x95 + 0x1f)
                         == *(char *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x3f));
                pfVar22 = (far_t *)*(undefined2 *)((int)*(undefined4 *)((int)pfStack_a << 2) + 0x39)
                ;
                pcVar25 = "rror\r\n";
                pfVar18 = local_c;
              } while( true );
            case (far_t *)0x10:
              pcVar25 = local_6a;
              manage_4d05_330c();
              cVar17 = (char)uVar43;
LAB_4d05_32b8:
              CurSfxType3 = 0x3c;
              cVar12 = ovr_OVC28_6018_1398();
              uStack_e = (far_t *)CONCAT11(cVar12,(undefined1)uStack_e);
              DAT_2410_5cf0 = 0;
              if (((cVar12 != '\0') && (cVar12 != '\x01')) && (cVar12 != -2)) {
                (&stack0xbac4)[(int)unaff_DI] = (&stack0xbac4)[(int)unaff_DI] + cVar17;
                pfVar22 = (far_t *)((char *)"puppetmaker" + 3);
                do {
                  iVar32 = (int)pfVar22 * (int)pcVar25;
                  pfVar22 = pfVar42;
                  if (*(byte *)((int)pfVar42 * 0x34 + 0x22) < *(byte *)(iVar32 + 0x21)) {
                    *(undefined1 *)((int)pfVar42 * 0x34 + 0x21) =
                         *(undefined1 *)((int)pfVar42 * 0x34 + 0x22);
                  }
                  do {
                    pfVar22 = (far_t *)((int)&pfVar22->ofs + 1);
                    if ((int)(uint)AgntCount <= (int)pfVar22) {
                      uVar20 = ovr_audio_3a5b_0afd();
                      ovr_play_sfxU(0x1c,0,uVar20);
                      return (far_t *)((int)(undefined4 *)&_DATA + 1);
                    }
                  } while (*(int *)((int)pfVar22 * 0x34 + 0x1b) !=
                           *(int *)(CONCAT11((*(uint8_t *)((uint8_t *)&(param_3) + 1)),(byte)param_3) + 0x1b));
                  uVar46 = (undefined2)((ulong)uStack_6 >> 0x10);
                  if ((byte)((far_t *)uStack_6)[0xc].seg < *(byte *)((int)pfVar22 * 0x34 + 0x22)) {
                    *(undefined1 *)((int)pfVar22 * 0x34 + 0x22) = (char)((far_t *)uStack_6)[0xc].seg
                    ;
                  }
                  pcVar25 = (char *)"Divide error\r\n" + 5;
                  pfVar42 = pfVar22;
                } while( true );
              }
              if (cVar12 != -2) {
                DAT_2410_5cf0 = 0;
                return (far_t *)((char *)"puppetmaker" + 3);
              }
              DAT_2410_4926 = 1;
              DAT_2410_5cf0 = 0;
              return (far_t *)((char *)"puppetmaker" + 3);
            case (far_t *)0x11:
              DAT_2000_d2df = DAT_2000_d2df + -1;
              _fmemset((void *)CONCAT13(0x21,CONCAT12(0xf2,DAT_2000_d2df * 0x12)),0,0x12);
              *(byte *)(DAT_2000_d2df * 0x12 + 8) = param_1;
              *(undefined2 *)(DAT_2000_d2df * 0x12 + 2) = param_2;
              *(undefined2 *)(DAT_2000_d2df * 0x12 + 4) = CONCAT11((*(uint8_t *)((uint8_t *)&(param_3) + 1)),(byte)param_3);
              *(undefined1 *)(DAT_2000_d2df * 0x12 + 9) = param_6;
              cVar17 = OVC23_55fe_0a56();
              uVar47 = (undefined2)((ulong)DAT_2000_cb0d >> 0x10);
              uVar46 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
              if (cVar17 == '\0') {
                bVar16 = *(byte *)((int)DAT_2000_ca95 +
                                  *(int *)((int)DAT_2000_cb0d + (int)param_2 * 0x78 +
                                          CONCAT11((*(uint8_t *)((uint8_t *)&(param_3) + 1)),(byte)param_3) * 2) * 9);
              }
              else {
                bVar16 = *(byte *)((int)DAT_2000_ca95 +
                                  *(int *)((int)DAT_2000_cb0d +
                                           (int)((int)&param_2[-1].seg + 1) * 0x78 +
                                          CONCAT11((*(uint8_t *)((uint8_t *)&(param_3) + 1)),(byte)param_3) * 2) * 9);
              }
              cVar17 = *(char *)((uint)bVar16 * 0x27 + 0x11d);
              (*(uint32_t *)((uint8_t *)&(uStack_6))) =
                   CONCAT12(*(undefined1 *)((uint)bVar16 * 0x27 + 0x11b),
                            CONCAT11(bVar16,(byte)uStack_6));
              uStack_6 = (far_t *)CONCAT13(cVar17,(uint32_t)uStack_6);
              if (cVar17 == '\0') {
                uStack_6 = (far_t *)CONCAT13(1,(uint32_t)uStack_6);
              }
              if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) < *(byte *)((uint)param_1 * 0x27 + 0x11c)) {
                *(undefined1 *)(DAT_2000_d2df * 0x12 + 6) =
                     *(undefined1 *)((uint)param_1 * 0x27 + 0x11c);
              }
              else {
                *(byte *)(DAT_2000_d2df * 0x12 + 6) = (*(uint8_t *)((uint8_t *)&(uStack_6) + 3));
              }
              *(undefined2 *)(DAT_2000_d2df * 0x12 + 0xf) = DAT_2000_d167;
              *(undefined2 *)(DAT_2000_d2df * 0x12) = 0;
              uVar15 = OVC23_55fe_2f90();
              *(undefined1 *)(DAT_2000_d2df * 0x12 + 0xc) = uVar15;
              if (*(char *)(DAT_2000_d2df * 0x12 + 0xc) == '\0') {
                *(undefined1 *)(DAT_2000_d2df * 0x12 + 0xc) = 1;
              }
              if (param_1 == 0) {
                cVar17 = OVC23_55fe_0a56();
                if (cVar17 != '\0') {
                  piVar4 = (int *)(DAT_2000_d2df * 0x12 + 2);
                  *piVar4 = *piVar4 + -1;
                }
                *(undefined1 *)(DAT_2000_d2df * 0x12 + 7) = (*(uint8_t *)((uint8_t *)&(uStack_6) + 2));
                if (param_7 == '\x01') {
                  *(undefined1 *)(DAT_2000_d2df * 0x12 + 0xe) = 1;
                }
                else {
                  *(char *)(DAT_2000_d2df * 0x12 + 0xc) = param_7;
                  *(undefined1 *)(DAT_2000_d2df * 0x12 + 0xe) = 0;
                }
                pbVar2 = (byte *)(DAT_2000_d2df * 0x12 + 0xd);
                *pbVar2 = *pbVar2 | 3;
              }
              else {
                *(undefined1 *)(DAT_2000_d2df * 0x12 + 7) =
                     *(undefined1 *)((uint)param_1 * 0x27 + 0x11b);
                if (param_7 != '\0') {
                  OVC23_55fe_1005();
                  cVar17 = ovr_OVC22_5087_503d();
                  if (cVar17 != '\0') {
                    *(undefined1 *)CONCAT22(param_5,param_4) = 1;
                  }
                }
                *(undefined1 *)(DAT_2000_d2df * 0x12 + 0xe) = 0;
              }
              *(undefined1 *)(DAT_2000_d2df * 0x12 + 0x11) = 0;
              *(undefined1 *)(DAT_2000_d2df * 0x12 + 0xb) =
                   *(undefined1 *)(DAT_2000_d2df * 0x12 + 0xc);
              DAT_2000_d2df = DAT_2000_d2df + 1;
              OVC23_55fe_29a2();
              pfVar22 = (far_t *)OVC23_55fe_0000();
              return pfVar22;
            case (far_t *)0x12:
              DAT_2000_d2df = DAT_2000_d2df + -1;
              pfVar22 = (far_t *)OVC23_55fe_0000();
              return pfVar22;
            case (far_t *)0x15:
              uVar46 = 0x195d;
              pcVar25 = ovr_fmVsprintf((char *)
                                       "Intelligence reports %s unit infected with disease. (%d, %d)"
                                       ,(char *)*(undefined2 *)
                                                 ((int)&far_t_ARRAY_2410_26f7[0].seg + 1 +
                                                 (uint)*(byte *)((int)&pfVar18[3].ofs +
                                                                (int)uRam0002265e + 1) * 0x95));
              ovr_uiNotify((char *)CONCAT22(uVar46,pcVar25),
                           CONCAT11(in_stack_0000ffb9,in_stack_0000ffb8));
              pfVar22 = (far_t *)((uint)*(byte *)(Entities.ofs + (int)pfStack_a * 0x37 + 0xd) * 0x95
                                 );
              if (((pfVar22 + 0x9c5)->ofs & 0xc00) != 0) {
                bVar16 = ovr_OVC27_5ded_1d8e();
                pfVar22 = (far_t *)(uint)bVar16;
                if (pfVar22 == (far_t *)0x0) {
                  if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].ofs + 1 +
                                (uint)*(byte *)(Entities.ofs + (int)pfStack_a * 0x37 + 0xd) * 0x95)
                      & 0x800) == 0) {
                    pfStack_12 = (far_t *)CONCAT11((*(uint8_t *)((uint8_t *)&(pfStack_12) + 1)),1);
                  }
                  else {
                    pfStack_12 = (far_t *)CONCAT11((*(uint8_t *)((uint8_t *)&(pfStack_12) + 1)),2);
                  }
                  cVar17 = ovr_OVC27_5ded_1eb7();
                  if (cVar17 != '\0') {
                    if (DebugVerbose != false) {
                      printf("kill 3\r",iVar60);
                    }
                    if (*(char *)(Entities.ofs + (int)unaff_DI * 0x37 + 0xe) != '\0') {
                      pcVar57 = (char *)(Entities.ofs + (int)unaff_DI * 0x37 + 0xe);
                      *pcVar57 = *pcVar57 + -1;
                    }
                  }
                  uVar15 = 0;
                  uVar58 = 0xa0;
                  OVC23_55fe_3450();
                  uVar46 = 0x195d;
                  pfVar22 = (far_t *)ovr_fmVsprintf((char *)
                                                  "Intelligence reports %s unit drained of energy. (%d, %d)"
                                                  ,(char *)*(undefined2 *)
                                                            ((int)&far_t_ARRAY_2410_26f7[0].seg + 1
                                                            + (uint)*(byte *)(Entities.ofs +
                                                                              (int)unaff_DI * 0x37 +
                                                                             0xd) * 0x95));
                  ovr_uiNotify((char *)CONCAT22(uVar46,pfVar22),CONCAT11(uVar58,uVar15));
                }
              }
              return pfVar22;
            }
            do {
              uVar46 = *(undefined2 *)(char *)((int)(undefined2 *)&DAT_2000_d224 + (int)pcVar25);
              (*(uint8_t *)((uint8_t *)&(gfx_05.seg))) = (char)uVar46;
              gfx_05.ofs = *(undefined2 *)(char *)((int)(undefined2 *)&DAT_2000_d222 + (int)pcVar25)
              ;
              (*(uint8_t *)((uint8_t *)&(gfx_05.seg) + 1)) = (char)((uint)uVar46 >> 8);
              ovr_blitGfxRect(gfx_05,(int16_t)x,(int16_t)pfVar22,
                              (brect_t *)
                              CONCAT13(in_stack_0000ffb9,CONCAT12(in_stack_0000ffb8,unaff_SI)),
                              (uint8_t)iVar60,SUB21(in_stack_0000ffbc,0));
              (*(uint8_t *)((uint8_t *)&(gfx_06.seg))) = (char)((undefined2 *)&DAT_2000_d224)[((uint)unaff_DI % 7) * 2];
              gfx_06.ofs = ((undefined2 *)&DAT_2000_d222)[((uint)unaff_DI % 7) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_06.seg) + 1)) =
                   (char)((uint)((undefined2 *)&DAT_2000_d224)[((uint)unaff_DI % 7) * 2] >> 8);
              ovr_blitGfxRect(gfx_06,(int16_t)(pfVar11 + 2),(int16_t)&pfStack_a[-2].seg,
                              (brect_t *)
                              CONCAT13((char)((uint)param_5 >> 8),CONCAT12((char)param_5,param_4)),
                              0x10,false);
              uVar43 = (uint)&unaff_DI->seg % 7;
              (*(uint8_t *)((uint8_t *)&(gfx_07.seg))) = (char)((undefined2 *)&DAT_2000_d224)[uVar43 * 2];
              gfx_07.ofs = ((undefined2 *)&DAT_2000_d222)[uVar43 * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_07.seg) + 1)) = (char)((uint)((undefined2 *)&DAT_2000_d224)[uVar43 * 2] >> 8);
              ovr_blitGfxRect(gfx_07,(int16_t)&pfVar11[6].seg,(int16_t)&pfStack_a[-2].seg,
                              (brect_t *)
                              CONCAT13((char)((uint)param_5 >> 8),CONCAT12((char)param_5,param_4)),
                              0x10,false);
              uVar43 = (uint)((int)&unaff_DI->seg + 1U) & 7;
              (*(uint8_t *)((uint8_t *)&(gfx_08.seg))) = (char)((undefined2 *)&DAT_2000_d204)[uVar43 * 2];
              gfx_08.ofs = ((undefined2 *)&DAT_2000_d202)[uVar43 * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_08.seg) + 1)) = (char)((uint)((undefined2 *)&DAT_2000_d204)[uVar43 * 2] >> 8);
              ovr_blitGfxRect(gfx_08,(int16_t)(pfVar11 + 9),(int16_t)&pfStack_a[-2].seg,
                              (brect_t *)
                              CONCAT13((char)((uint)param_5 >> 8),CONCAT12((char)param_5,param_4)),
                              0x10,false);
              (*(uint8_t *)((uint8_t *)&(gfx_09.seg))) = (char)((undefined2 *)&DAT_2000_d204)[((uint)unaff_DI & 7) * 2];
              gfx_09.ofs = ((undefined2 *)&DAT_2000_d202)[((uint)unaff_DI & 7) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_09.seg) + 1)) =
                   (char)((uint)((undefined2 *)&DAT_2000_d204)[((uint)unaff_DI & 7) * 2] >> 8);
              ovr_blitGfxRect(gfx_09,(int16_t)((int)&pfVar11[7].seg + 1),(int16_t)&pfStack_a[-2].seg
                              ,(brect_t *)
                               CONCAT13((char)((uint)param_5 >> 8),CONCAT12((char)param_5,param_4)),
                              0x10,false);
              (*(uint8_t *)((uint8_t *)&(gfx_10.seg))) = (char)((undefined2 *)&DAT_2000_d1f0)[((uint)unaff_DI % 5) * 2];
              gfx_10.ofs = ((undefined2 *)&DAT_2000_d1ee)[((uint)unaff_DI % 5) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_10.seg) + 1)) =
                   (char)((uint)((undefined2 *)&DAT_2000_d1f0)[((uint)unaff_DI % 5) * 2] >> 8);
              ovr_blitGfxRect(gfx_10,(int16_t)((int)&pfVar11[5].ofs + 1),(int16_t)&pfStack_a[-2].seg
                              ,(brect_t *)
                               CONCAT13((char)((uint)param_5 >> 8),CONCAT12((char)param_5,param_4)),
                              0x10,false);
              (*(uint8_t *)((uint8_t *)&(gfx_11.seg))) = (char)((undefined2 *)&DAT_2000_d1f0)[((uint)unaff_DI % 5) * 2];
              gfx_11.ofs = ((undefined2 *)&DAT_2000_d1ee)[((uint)unaff_DI % 5) * 2];
              (*(uint8_t *)((uint8_t *)&(gfx_11.seg) + 1)) =
                   (char)((uint)((undefined2 *)&DAT_2000_d1f0)[((uint)unaff_DI % 5) * 2] >> 8);
              pfVar22 = (far_t *)ovr_blitGfxRect(gfx_11,(int16_t)((int)&pfVar11[8].ofs + 1),
                                                 (int16_t)&pfStack_a[-2].seg,
                                                 (brect_t *)
                                                 CONCAT13((char)((uint)param_5 >> 8),
                                                          CONCAT12((char)param_5,param_4)),0x10,
                                                 false);
              while( true ) {
                while( true ) {
                  local_c = (far_t *)((int)&local_c[-1].seg + 1);
                  if ((int)local_c < 0) {
                    return pfVar22;
                  }
                  puVar21 = (uint8_t *)((int)&local_c->ofs + GfxRndSeed2 + ((uint)unaff_DI >> 5));
                  pfVar22 = (far_t *)((int)&pfStack_a[4].seg + 1);
                  uVar15 = (undefined1)param_5;
                  uVar58 = (undefined1)((uint)param_5 >> 8);
                  if (((*(uint8_t *)((uint8_t *)&(uStack_14) + 1)) == 2) ||
                     ((far_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xf) <
                      unaff_DI)) break;
                  if (((far_t *)((int)&pfStack_12[-1].seg + 1) == local_c) &&
                     (unaff_DI <=
                      (far_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 8))) {
                    uStack_8 = ((undefined2 *)&DAT_2000_cc09)[(int)unaff_DI * 2];
                    pfVar18 = (far_t *)((undefined2 *)&DAT_2000_cc0b)[(int)unaff_DI * 2];
                  }
                  else {
                    uStack_8 = DAT_2000_cc39;
                    pfVar18 = DAT_2000_cc3b;
                  }
                  uStack_6 = (far_t *)CONCAT22(puVar21,pfVar18);
                  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)pfVar18;
                  gfx.ofs = uStack_8;
                  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)pfVar18 >> 8);
                  pfStack_a = pfVar22;
                  pfVar22 = (far_t *)ovr_blitGfxRect(gfx,(int16_t)pfVar42,(int16_t)pfVar22,
                                                     (brect_t *)
                                                     CONCAT13(uVar58,CONCAT12(uVar15,param_4)),0x10,
                                                     false);
                }
                if ((*(uint8_t *)((uint8_t *)&(uStack_14) + 1)) < 2) break;
                if ((far_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 5) < unaff_DI)
                {
                  uStack_8 = DAT_2000_cc61;
                  uVar46 = DAT_2000_cc63;
                }
                else {
                  uStack_8 = ((undefined2 *)&DAT_2000_cc09)[(int)(unaff_DI + 3) * 2];
                  uVar46 = ((undefined2 *)&DAT_2000_cc0b)[(int)(unaff_DI + 3) * 2];
                }
                uStack_6 = (far_t *)CONCAT22(puVar21,uVar46);
                (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)uVar46;
                gfx_00.ofs = uStack_8;
                (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)uVar46 >> 8);
                pfStack_a = pfVar22;
                pfVar22 = (far_t *)ovr_blitGfxRect(gfx_00,(int16_t)pfVar42,(int16_t)pfVar22,
                                                   (brect_t *)
                                                   CONCAT13(uVar58,CONCAT12(uVar15,param_4)),0x10,
                                                   false);
              }
              uStack_6 = (far_t *)CONCAT22(puVar21,DAT_2000_cc3b);
              uStack_8 = DAT_2000_cc39;
              if (local_c == (far_t *)0x0) {
                pfVar18 = pfStack_a + 8;
                uVar43 = (uint)((int)&unaff_DI->ofs + GfxRndSeed2) % 0xe;
                (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = (char)((undefined2 *)&DAT_2000_d2a0)[uVar43 * 2];
                gfx_01.ofs = ((undefined2 *)&DAT_2000_d29e)[uVar43 * 2];
                (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = (char)((uint)((undefined2 *)&DAT_2000_d2a0)[uVar43 * 2] >> 8);
                pfStack_a = pfVar22;
                ovr_blitGfxRect(gfx_01,(int16_t)(pfVar11 + 4),(int16_t)&pfVar18->seg,
                                (brect_t *)CONCAT13(uVar58,CONCAT12(uVar15,param_4)),0x10,true);
                pfVar22 = pfStack_a;
              }
              pfStack_a = pfVar22;
              (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)uStack_6;
              gfx_02.ofs = uStack_8;
              (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = (char)((ulong)uStack_6 >> 8);
              ovr_blitGfxRect(gfx_02,(int16_t)pfVar42,(int16_t)pfStack_a,
                              (brect_t *)
                              CONCAT13((char)((uint)param_5 >> 8),CONCAT12((char)param_5,param_4)),
                              0x10,false);
              if (((uint)((uint8_t *)((int)&local_c->ofs + (int)&unaff_DI->ofs) + GfxRndSeed2 +
                         (int)pfVar42) & 0x1f) < 0x11) {
                puVar21 = (uint8_t *)
                          ((int)&local_c->ofs +
                          GfxRndSeed2 +
                          ((uint)((uint8_t *)((int)&local_c->ofs + (int)&unaff_DI->ofs) +
                                  GfxRndSeed2 + (int)pfVar42) >> 5));
                uStack_6 = (far_t *)CONCAT22(puVar21,(far_t *)uStack_6);
                uStack_e = (far_t *)((int)((uint)*(byte *)((uint)puVar21 & 0xff) * 0x25) >> 8);
                uVar43 = (uint)((uint8_t *)((int)&local_c->ofs + (int)&unaff_DI->ofs) + GfxRndSeed2
                               + (int)pfVar42) & 0x1f;
                (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = (char)((undefined2 *)&DAT_2000_d25c)[uVar43 * 2];
                gfx_03.ofs = ((undefined2 *)&DAT_2000_d25a)[uVar43 * 2];
                (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) = (char)((uint)((undefined2 *)&DAT_2000_d25c)[uVar43 * 2] >> 8);
                ovr_blitGfxRect(gfx_03,(int16_t)((int)&pfVar11->ofs + (int)&uStack_e[1].ofs),
                                (int16_t)((int)&pfStack_a[-1].ofs + 1),
                                (brect_t *)
                                CONCAT13((char)((uint)param_5 >> 8),CONCAT12((char)param_5,param_4))
                                ,0x10,false);
              }
              if (((uint)((int)local_c + (int)((-(int)pfVar42 - GfxRndSeed2) + (int)unaff_DI)) & 0xf
                  ) < 7) {
                puVar21 = (uint8_t *)
                          ((int)local_c +
                          (((uint)((int)local_c +
                                  (int)((-(int)pfVar42 - GfxRndSeed2) + (int)unaff_DI)) >> 4) -
                          GfxRndSeed2));
                uStack_6 = (far_t *)CONCAT22(puVar21,(far_t *)uStack_6);
                uStack_e = (far_t *)((int)((uint)*(byte *)((uint)(puVar21 + 0xe) & 0xff) * 0x25) >>
                                    8);
                uVar43 = (uint)((int)local_c + (int)((-(int)pfVar42 - GfxRndSeed2) + (int)unaff_DI))
                         & 0xf;
                (*(uint8_t *)((uint8_t *)&(gfx_04.seg))) = (char)((undefined2 *)&DAT_2000_d240)[uVar43 * 2];
                gfx_04.ofs = ((undefined2 *)&DAT_2000_d23e)[uVar43 * 2];
                (*(uint8_t *)((uint8_t *)&(gfx_04.seg) + 1)) = (char)((uint)((undefined2 *)&DAT_2000_d240)[uVar43 * 2] >> 8);
                ovr_blitGfxRect(gfx_04,(int16_t)((int)&pfVar11->ofs + (int)&uStack_e[1].ofs),
                                (int16_t)((int)&pfStack_a[-1].ofs + 1),
                                (brect_t *)
                                CONCAT13((char)((uint)param_5 >> 8),CONCAT12((char)param_5,param_4))
                                ,0x10,false);
              }
              in_stack_0000ffbc = 0;
              iVar60 = 16;
              in_stack_0000ffb8 = (undefined1)param_5;
              in_stack_0000ffb9 = (undefined1)((uint)param_5 >> 8);
              pfVar22 = (far_t *)&pfStack_a[-2].seg;
              x = &pfVar11[1].seg;
              pcVar25 = (char *)((uint)((int)&unaff_DI[1].ofs + 1) % 7 << 2);
              unaff_SI = param_4;
            } while( true );
          }
          if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) == '\x13') {
            uVar19 = *(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x12a);
            bVar53 = CARRY2(uStack_38,uVar19);
            uStack_38 = uStack_38 + uVar19;
            iStack_36 = iStack_36 + (uint)bVar53;
          }
          else {
            uVar19 = *(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x12a);
            bVar53 = CARRY2(uStack_34,uVar19);
            uStack_34 = uStack_34 + uVar19;
            local_32[0] = local_32[0] + (uint)bVar53;
          }
          if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) == '\x1d') {
            if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 2)) == '\0') {
              local_32[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131)] =
                   local_32[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131)] +
                   (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129);
            }
          }
          else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) == '\x10') {
            if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 2)) != '\0') {
              local_32[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131)] =
                   local_32[*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131)] +
                   (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129);
            }
          }
          else if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129) != '\0') {
            if (*(char *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x133) == '\r') {
              if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) != '\0') {
                local_32[(uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) + 3] =
                     local_32[(uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) + 3] +
                     (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129);
              }
            }
            else {
              local_32[(uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) + 3] =
                   local_32[(uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) + 3] +
                   (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x129);
            }
          }
          uStack_22 = uStack_22 + (uint)*(byte *)((uStack_1a >> 8) * 0x27 + 0x127);
          if (0xf7 < (int)pfVar42) {
            iVar32 = OVC22_5087_0234();
            uStack_20 = uStack_20 + iVar32;
            iVar32 = OVC22_5087_0411();
            iVar60 = iVar60 + iVar32;
          }
          if (((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x121) & 1) != 0) &&
             (((*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x2f) == -1 ||
               (bVar16 = *(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x2f),
               uVar43 = CONCAT11((char)(uVar43 >> 8),bVar16),
               (1 << (bVar16 & 0x1f) & (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x11f)) != 0))
              && (*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) < 4)))) {
            *(int *)(&stack0xffbc + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) * 2) =
                 *(int *)(&stack0xffbc + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131) * 2)
                 + 1;
          }
          if ((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x121) & 0x200) != 0) {
            iStack_3c = iStack_3c + (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) * 0x27 + 0x131);
          }
        }
      }
    }
    for (uStack_14 = (far_t *)0x0; uStack_14 < EntityCount;
        uStack_14 = (far_t *)((int)&uStack_14->ofs + 1)) {
      if (*(byte *)(Entities.ofs + (int)uStack_14 * 0x37 + 0x1a) == param_1) {
        uStack_1e = uStack_1e + *(byte *)(Entities.ofs + (int)uStack_14 * 0x37 + 0xe);
      }
    }
    bStack_1b = *(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0xad);
    for (iVar32 = 2; -1 < iVar32; iVar32 = iVar32 + -1) {
      if (bStack_1b < *(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + iVar32 + 0xaa)) {
        *(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + iVar32 + 0xaa) = bStack_1b;
        bStack_1b = 0;
      }
      else {
        bStack_1b = bStack_1b - *(char *)((int)*(undefined4 *)((uint)param_1 << 2) + iVar32 + 0xaa);
      }
    }
    iVar32 = 0;
    for (iVar45 = 0; iVar45 < 3; iVar45 = iVar45 + 1) {
      iVar32 = iVar32 + (uint)*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + iVar45 + 0xaa) *
                        (iVar45 + 1) * 3;
    }
    if (iVar32 < 0x32) {
      *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0xaa) = (char)iVar32;
    }
    else {
      *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0xaa) = 0x32;
    }
    *(undefined2 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x94) = local_c;
    *(undefined2 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x96) = pfStack_a;
    *(uint16_t *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x98) = uStack_8;
    if (uStack_42 < 6) {
      uStack_24 = uStack_42;
    }
    else {
      uStack_24 = 5;
    }
    if (iStack_40 + uStack_24 < 0xb) {
      uStack_24 = uStack_24 + iStack_40;
    }
    else {
      uStack_24 = 10;
    }
    uStack_24 = uStack_24 + iStack_3e;
    if (iStack_3e == 0) {
      if (iStack_40 == 0) {
        if (uStack_42 == 0) {
          *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x53) = 4;
        }
        else {
          *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x53) = 8;
        }
      }
      else {
        *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x53) = 0xc;
      }
    }
    else {
      *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x53) = 0xff;
    }
    *(undefined2 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x82) = 0;
    if ((local_32[0] < 0) || (local_32[0] < 1)) {
      uVar46 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
      iVar32 = (int)*(undefined4 *)((uint)param_1 << 2);
      *(int *)(iVar32 + 0x80) = local_32[0];
      *(uint *)(iVar32 + 0x7e) = uStack_34;
    }
    else {
      uVar46 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
      iVar32 = (int)*(undefined4 *)((uint)param_1 << 2);
      *(undefined2 *)(iVar32 + 0x80) = 0;
      *(undefined2 *)(iVar32 + 0x7e) = 0xffff;
    }
    *(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5b) = uStack_22;
    *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d) = uStack_1e;
    *(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4f) = (int)uStack_20;
    *(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x54) = iVar60;
    uVar46 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
    iVar32 = (int)*(undefined4 *)((uint)param_1 << 2);
    *(int *)(iVar32 + 0x8c) = iStack_36;
    *(uint *)(iVar32 + 0x8a) = uStack_38;
    *(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 100) = local_2a;
    *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x66) = uStack_28;
    *(undefined2 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x68) = uStack_26;
    *(undefined2 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x70) = local_32[1];
    *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x72) = local_32[2];
    *(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x74) = local_32[3];
    *(int *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x87) = iStack_3c;
    if (uStack_24 < 0x100) {
      *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x52) = (char)uStack_24;
    }
    else {
      *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x52) = 0xff;
    }
    uVar15 = ovr_OVC36_67d1_0000();
    *(undefined1 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x84) = uVar15;
    in_AX = (far_t *)OVC22_5087_1470();
  }
  return in_AX;
switchD_5000_123d_caseD_2:
  do {
    bVar16 = *(byte *)(Entities.ofs + (int)pfVar42 * 0x37 + 0xd);
    uStack_6 = (far_t *)CONCAT13(bVar16,(uint32_t)uStack_6);
    if (*(char *)((int)(char **)GMenuStrings + (uint)bVar16 * 0x95 + 0x1f) == '\0') {
      uVar15 = 0;
      uVar58 = 0xa0;
      pcVar25 = (char *)ovr_OVC15_4207_1c79();
      pcStackY_60 = (char *)"jeweler\'s shop" + 3;
      pcStackY_62 = (char *)&DAT_2000_d04e;
      pcVar57 = ovr_stsprintf(&stack0xffaa,"%s unit drowns.  (%d, %d)",pcVar25);
      ovr_uiNotify(pcVar57,CONCAT11(uVar58,uVar15));
    }
    pfVar22 = (far_t *)ovr_OVC15_4207_0e17();
    while( true ) {
      do {
        pfVar42 = (far_t *)((int)&pfVar42[-1].seg + 1);
        if ((int)pfVar42 < 0) {
          return pfVar22;
        }
        pfVar22 = (far_t *)((int)pfVar42 * 0x37);
      } while (((far_t *)*(int *)((int)&pfVar22->ofs + Entities.ofs) != unaff_DI) ||
              (pfVar22 = (far_t *)*(int *)(Entities.ofs + (int)pfVar42 * 0x37 + 2),
              pfVar22 != param_2));
      pfVar22 = (far_t *)OVC23_55fe_2da3();
      uStack_6 = (far_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),pfVar22);
      if ((int)pfVar22 < 0) break;
      *(undefined2 *)(Entities.ofs + (int)pfVar42 * 0x37) = pfVar22;
    }
  } while( true );
switchD_5000_123d_caseD_3:
  while( true ) {
    if ((pbVar33[3] & 3) == 0) {
      uVar46 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
      bVar16 = *(byte *)((int)DAT_2000_ca95 + (int)unaff_DI * 9 + 2);
      uStack_24 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_24) + 1)),bVar16);
      if ((bVar16 == 0xff) || (*(char *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0x3f) == '\0')) {
        uStack_8 = 0x96;
      }
      else {
        uStack_8 = 0x5dc;
      }
      if (*(char *)((int)DAT_2000_ca95 + (int)unaff_DI * 9 + 1) != '\0') {
        uVar20 = ovr_randBelow(uStack_8);
        uVar46 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
        iVar32 = (int)DAT_2000_ca95;
        if ((int)(uVar20 & 0xff) <
            (int)(100 - (uint)*(byte *)((uint)*(byte *)(iVar32 + (int)unaff_DI * 9) * 0x27 + 0x130))
           ) {
          bVar16 = *(byte *)(iVar32 + (int)unaff_DI * 9);
          uStack_20 = (char *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)),bVar16);
          pcVar57 = (char *)(iVar32 + (int)unaff_DI * 9 + 1);
          *pcVar57 = *pcVar57 + -1;
          if (((*(uint *)((uint)bVar16 * 0x27 + 0x121) & 4) == 0) &&
             ((*(char *)((int)DAT_2000_ca95 + (int)unaff_DI * 9 + 1) == '\0' ||
              ((*(uint *)((uint)bVar16 * 0x27 + 0x121) & 0x200) != 0)))) {
            OVC22_5087_1674();
          }
          else if (((*(int *)((char *)"build\\clebath2.lbm" + 0xc + (uint)bVar16 * 0xc) != 0 ||
                     *(int *)((char *)"build\\clebath2.lbm" + 0xe + (uint)bVar16 * 0xc) != 0) ||
                   (*(char *)((uint)bVar16 * 0x27 + 0x11e) == '\x10')) &&
                  (cVar17 = OVC22_5087_510e(), cVar17 != '\0')) {
            cStack_1c = '\x01';
          }
        }
      }
    }
LAB_5087_202c:
    unaff_DI = (far_t *)((int)&unaff_DI->ofs + 1);
    if (DAT_2000_ca99 <= unaff_DI) break;
    uVar47 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
    pbVar33 = (byte *)((int)DAT_2000_ca95 + (int)unaff_DI * 9);
  }
  GGameState = 0x43;
  if (DebugVerbose != false) {
    printf("%d \r",0x43);
  }
  for (uStack_16 = (far_t *)0x0; (int)uStack_16 < (int)(uint)DAT_2000_d1e6;
      uStack_16 = (far_t *)((int)uStack_16 + 1)) {
    if (*(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3d) != '\0') {
      *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa2) = 0;
      cVar17 = *(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3f);
      uStack_22 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_22) + 1)),cVar17);
      if ((cVar17 == '\0') &&
         (*(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f) <
          *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d) >> 1)) {
        uStack_24 = CONCAT11(1,(char)uStack_24);
      }
      else {
        uStack_24 = uStack_24 & 0xff;
      }
      uVar43 = *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54);
      uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar32 = *(int *)(iVar32 + 0x58) + ((int)uVar43 >> 0xf) +
               (uint)CARRY2(*(uint *)(iVar32 + 0x56),uVar43);
      if ((iVar32 < 1) && (iVar32 < 0)) {
        pfVar42 = (far_t *)&GUnitDescriptions[3].ofs;
        while (pfVar42 = (far_t *)((int)&pfVar42->ofs + 1), pfVar42 < DAT_2000_ca99) {
          uVar46 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
          iVar32 = (int)DAT_2000_ca95;
          bVar16 = *(byte *)(iVar32 + (int)pfVar42 * 9);
          uStack_20 = (char *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)),bVar16);
          if (((far_t *)(uint)*(byte *)(iVar32 + (int)pfVar42 * 9 + 2) == uStack_16) &&
             (*(int *)((uint)bVar16 * 0x27 + 0x123) < 0)) {
            uVar43 = *(uint *)((uint)bVar16 * 0x27 + 0x123);
            uVar47 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar60 = (int)*(undefined4 *)((int)uStack_16 << 2);
            iVar60 = *(int *)(iVar60 + 0x58) + ((int)uVar43 >> 0xf) +
                     (uint)CARRY2(*(uint *)(iVar60 + 0x56),uVar43);
            if ((iVar60 < 1) && (iVar60 < 0)) {
              if (((char)uStack_22 == '\0') && (*(char *)(iVar32 + (int)pfVar42 * 9 + 1) != '\0')) {
                uVar20 = ovr_randBelow(100);
                uVar46 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
                iVar32 = (int)DAT_2000_ca95;
                if (*(byte *)((uint)*(byte *)(iVar32 + (int)pfVar42 * 9) * 0x27 + 0x130) <=
                    (byte)uVar20) {
                  if (*(char *)(iVar32 + (int)pfVar42 * 9 + 1) != '\0') {
                    pcVar57 = (char *)(iVar32 + (int)pfVar42 * 9 + 1);
                    *pcVar57 = *pcVar57 + -1;
                  }
                  if (((*(uint *)(((uint)uStack_20 & 0xff) * 0x27 + 0x121) & 4) == 0) &&
                     ((*(char *)((int)DAT_2000_ca95 + (int)pfVar42 * 9 + 1) == '\0' ||
                      ((*(uint *)(((uint)uStack_20 & 0xff) * 0x27 + 0x121) & 0x200) != 0)))) {
                    OVC22_5087_1674();
                  }
                  else {
                    iVar32 = ((uint)uStack_20 & 0xff) * 0xc;
                    if (((*(int *)((char *)"build\\clebath2.lbm" + 0xc + iVar32) != 0 ||
                          *(int *)((char *)"build\\clebath2.lbm" + 0xe + iVar32) != 0) ||
                        (*(char *)(((uint)uStack_20 & 0xff) * 0x27 + 0x11e) == '\x10')) &&
                       (cVar17 = OVC22_5087_510e(), cVar17 != '\0')) {
                      cStack_1c = '\x01';
                    }
                  }
                }
              }
            }
            else {
              uVar19 = *(uint *)((uint)bVar16 * 0x27 + 0x123);
              uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
              iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
              puVar3 = (uint *)(iVar32 + 0x56);
              uVar43 = *puVar3;
              *puVar3 = *puVar3 + uVar19;
              piVar4 = (int *)(iVar32 + 0x58);
              *piVar4 = *piVar4 + ((int)uVar19 >> 0xf) + (uint)CARRY2(uVar43,uVar19);
            }
          }
        }
        uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar32 + 0x58) = 0;
        *(undefined2 *)(iVar32 + 0x56) = 0;
      }
      else {
        if ((cVar17 == '\0') && (0 < *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54))) {
          pfStack_10 = (far_t *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54) / 10);
        }
        else {
          pfStack_10 = (far_t *)0x0;
        }
        bVar53 = CARRY2((uint)DAT_2000_ca91,(uint)pfStack_10);
        DAT_2000_ca91 = (uint16_t)(((int)&pfStack_10->ofs + (int)DAT_2000_ca91));
        DAT_2000_ca93 = DAT_2000_ca93 + ((int)pfStack_10 >> 0xf) + (uint)bVar53;
        uVar19 = *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x54) - (int)pfStack_10;
        uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar32 + 0x56);
        uVar43 = *puVar3;
        *puVar3 = *puVar3 + uVar19;
        piVar4 = (int *)(iVar32 + 0x58);
        *piVar4 = *piVar4 + ((int)uVar19 >> 0xf) + (uint)CARRY2(uVar43,uVar19);
      }
      if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 +
                    (uint)*(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3e) * 0x95) &
          0x100) == 0) {
        if (*(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f) <
            *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d)) {
          pfStack_12 = (far_t *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d) -
                                *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f));
          uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar60 = (int)*(undefined4 *)((int)uStack_16 << 2);
          iVar32 = *(int *)(iVar60 + 0x62);
          if ((-1 < iVar32) && ((0 < iVar32 || (*(int *)(iVar60 + 0x60) != 0)))) {
            uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
            uVar43 = *(uint *)(iVar32 + 0x62);
            if ((0x7fff < uVar43) ||
               ((uStack_14 = pfStack_12, (int)uVar43 < 1 &&
                ((far_t *)*(uint *)(iVar32 + 0x60) <= pfStack_12)))) {
              uStack_14 = (far_t *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x60)
              ;
            }
            pfStack_12 = (far_t *)((int)pfStack_12 - (int)uStack_14);
            uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
            puVar3 = (uint *)(iVar32 + 0x60);
            pfVar42 = (far_t *)*puVar3;
            *puVar3 = *puVar3 - (int)uStack_14;
            piVar4 = (int *)(iVar32 + 0x62);
            *piVar4 = *piVar4 - (uint)(pfVar42 < uStack_14);
          }
          if (pfStack_12 != (far_t *)0x0) {
            pfStack_a = pfStack_12;
            if ((far_t *)*(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0) < pfStack_12) {
              pfStack_a = (far_t *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0)
              ;
            }
            uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
            uVar43 = *(uint *)(iVar32 + 0x58);
            if (((int)uVar43 < 1) &&
               ((0x7fff < uVar43 || ((far_t *)*(uint *)(iVar32 + 0x56) < pfStack_a)))) {
              pfStack_a = (far_t *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x56)
              ;
            }
            uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
            puVar3 = (uint *)(iVar32 + 0x56);
            pfVar42 = (far_t *)*puVar3;
            *puVar3 = *puVar3 - (int)pfStack_a;
            piVar4 = (int *)(iVar32 + 0x58);
            *piVar4 = *piVar4 - (uint)(pfVar42 < pfStack_a);
            pfStack_12 = (far_t *)((int)pfStack_12 - (int)pfStack_a);
            *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa2) = pfStack_a;
          }
          if ((char)uStack_22 == '\0') {
            for (iVar32 = 0; (pfStack_12 != (far_t *)0x0 && (iVar32 < (int)(uint)DAT_2000_d1e6));
                iVar32 = iVar32 + 1) {
              if ((*(char *)((int)*(undefined4 *)(iVar32 << 2) + 0x3d) != '\0') &&
                 ((*(char *)((int)*(undefined4 *)(iVar32 << 2) + 0x3f) == '\0' &&
                  (uVar46 = (undefined2)((ulong)*(undefined4 *)(iVar32 << 2) >> 0x10),
                  iVar60 = (int)*(undefined4 *)(iVar32 << 2),
                  *(int *)(iVar60 + 0x60) != 0 || *(int *)(iVar60 + 0x62) != 0)))) {
                uVar46 = (undefined2)((ulong)*(undefined4 *)(iVar32 << 2) >> 0x10);
                iVar60 = (int)*(undefined4 *)(iVar32 << 2);
                uVar43 = *(uint *)(iVar60 + 0x62);
                if ((uVar43 < 0x8000) &&
                   ((0 < (int)uVar43 || (pfStack_12 < (far_t *)*(uint *)(iVar60 + 0x60))))) {
                  uStack_14 = pfStack_12;
                }
                else {
                  uStack_14 = (far_t *)*(undefined2 *)((int)*(undefined4 *)(iVar32 << 2) + 0x60);
                }
                pfStack_12 = (far_t *)((int)pfStack_12 - (int)uStack_14);
                uVar46 = (undefined2)((ulong)*(undefined4 *)(iVar32 << 2) >> 0x10);
                iVar60 = (int)*(undefined4 *)(iVar32 << 2);
                puVar3 = (uint *)(iVar60 + 0x60);
                pfVar42 = (far_t *)*puVar3;
                *puVar3 = *puVar3 - (int)uStack_14;
                piVar4 = (int *)(iVar60 + 0x62);
                *piVar4 = *piVar4 - (uint)(pfVar42 < uStack_14);
              }
            }
          }
          pfVar42 = (far_t *)0x0;
          while ((pfVar42 < EntityCount && (pfStack_12 != (far_t *)0x0))) {
            uVar48 = Entities.seg;
            uVar20 = Entities.ofs;
            if (((*(char *)(uVar20 + (int)pfVar42 * 0x37 + 0x18) == '\0') &&
                ((far_t *)(uint)*(byte *)(uVar20 + (int)pfVar42 * 0x37 + 0x1a) == uStack_16)) &&
               (((*(uint8_t *)((uint8_t *)&(uStack_24) + 1)) != '\0' || (1 < *(byte *)(uVar20 + (int)pfVar42 * 0x37 + 0xe))))) {
              if (*(char *)(uVar20 + (int)pfVar42 * 0x37 + 0xe) != '\0') {
                if (DebugVerbose != false) {
                  printf("kill 3\r",pfVar22);
                }
                pcVar57 = (char *)(Entities.ofs + (int)pfVar42 * 0x37 + 0xe);
                *pcVar57 = *pcVar57 + -1;
                if (*(char *)(Entities.ofs + (int)pfVar42 * 0x37 + 0xe) == '\0') {
                  uStack_1e = CONCAT11(1,(byte)uStack_1e);
                }
              }
              pfStack_12 = (far_t *)((int)&pfStack_12[-1].seg + 1);
            }
            pfVar42 = (far_t *)((int)&pfVar42->ofs + 1);
          }
        }
        else {
          uVar19 = *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4f) -
                   *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d);
          uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
          puVar3 = (uint *)(iVar32 + 0x60);
          uVar43 = *puVar3;
          *puVar3 = *puVar3 + uVar19;
          piVar4 = (int *)(iVar32 + 0x62);
          *piVar4 = *piVar4 + (uint)CARRY2(uVar43,uVar19);
        }
      }
      uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar45 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar32 = *(int *)(iVar45 + 0x62);
      uVar47 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar34 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar60 = *(int *)(iVar34 + 0x80);
      if ((iVar60 <= iVar32) &&
         ((iVar60 < iVar32 || (*(uint *)(iVar34 + 0x7e) < *(uint *)(iVar45 + 0x60))))) {
        uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
        uVar43 = *(uint *)(iVar32 + 0x60);
        uVar47 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar60 = (int)*(undefined4 *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar60 + 0x7e);
        uVar19 = (uint)(uVar43 < *puVar3);
        uVar27 = *(int *)(iVar32 + 0x62) - *(int *)(iVar60 + 0x80);
        if (((int)(uVar27 - uVar19) < 0) ||
           ((uVar27 == uVar19 &&
            (uVar43 - *puVar3 <= *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0))))) {
          pfStack_a = (far_t *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x60) -
                               *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x7e));
        }
        else {
          pfStack_a = (far_t *)*(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa0);
        }
        *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa2) = -(int)pfStack_a;
        uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
        puVar3 = (uint *)(iVar32 + 0x56);
        uVar43 = *puVar3;
        *puVar3 = (uint)((int)&pfStack_a->ofs + *puVar3);
        piVar4 = (int *)(iVar32 + 0x58);
        *piVar4 = *piVar4 + (uint)CARRY2(uVar43,(uint)pfStack_a);
        uVar47 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
        uVar46 = *(undefined2 *)(iVar32 + 0x7e);
        uVar49 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar60 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar60 + 0x62) = *(undefined2 *)(iVar32 + 0x80);
        *(undefined2 *)(iVar60 + 0x60) = uVar46;
      }
      if ((*(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x5b) <
           *(uint *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d)) &&
         ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 +
                    (uint)*(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3e) * 0x95) & 0x80
          ) == 0)) {
        pfStack_12 = (far_t *)(*(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x4d) -
                              *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x5b));
        pfVar42 = (far_t *)0x0;
        while ((pfVar42 < EntityCount && (pfStack_12 != (far_t *)0x0))) {
          uVar48 = Entities.seg;
          uVar20 = Entities.ofs;
          if ((((far_t *)(uint)*(byte *)(uVar20 + (int)pfVar42 * 0x37 + 0x1a) == uStack_16) &&
              (((*(char *)(uVar20 + (int)pfVar42 * 0x37 + 0x18) == '\0' &&
                (*(int *)(uVar20 + (int)pfVar42 * 0x37 + 8) == 0)) &&
               (*(int *)(uVar20 + (int)pfVar42 * 0x37 + 10) == 0)))) &&
             (3 < *(byte *)(uVar20 + (int)pfVar42 * 0x37 + 0xe))) {
            if (DebugVerbose != false) {
              printf("kill 2 \r",pfVar22);
            }
            pcVar57 = (char *)(Entities.ofs + (int)pfVar42 * 0x37 + 0xe);
            *pcVar57 = *pcVar57 + -1;
            pfStack_12 = (far_t *)((int)&pfStack_12[-1].seg + 1);
          }
          pfVar42 = (far_t *)((int)&pfVar42->ofs + 1);
        }
      }
      ovr_OVC25_5b66_1b48();
      iVar32 = ((int *)((int)uStack_16 * 4))[1];
      _fmemset((void *)CONCAT13((char)((uint)iVar32 >> 8),
                                CONCAT12((char)iVar32,*(int *)((int)uStack_16 * 4) + 0x6a)),0,6);
      iVar32 = ((int *)((int)uStack_16 * 4))[1];
      _fmemset((void *)CONCAT13((char)((uint)iVar32 >> 8),
                                CONCAT12((char)iVar32,*(int *)((int)uStack_16 * 4) + 0x76)),0,6);
      uVar20 = ovr_randBelow(100);
      if ((byte)uVar20 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6c) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 100);
      }
      else {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6a) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 100);
      }
      uVar20 = ovr_randBelow(100);
      if ((byte)uVar20 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6e) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x66);
      }
      else {
        piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6c);
        *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x66);
      }
      piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x6e);
      *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x68);
      uVar20 = ovr_randBelow(100);
      if ((byte)uVar20 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x78) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x70);
      }
      else {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x76) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x70);
      }
      uVar20 = ovr_randBelow(100);
      if ((byte)uVar20 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x7a) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x72);
      }
      else {
        piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x78);
        *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x72);
      }
      uVar20 = ovr_randBelow(100);
      if ((byte)uVar20 < *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa9)) {
        *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x7c) =
             *(undefined2 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x74);
      }
      else {
        piVar4 = (int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x7a);
        *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x74);
      }
      *(undefined1 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa7) =
           *(undefined1 *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xa6);
      if (*(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3f) != '\0') {
        uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar60 = (int)*(undefined4 *)((int)uStack_16 << 2);
        iVar32 = *(int *)(iVar60 + 0x58);
        if ((iVar32 < 1) && ((iVar32 != 0 || (*(int *)(iVar60 + 0x56) == 0)))) {
          uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
          *(undefined2 *)(iVar32 + 0x58) = 0;
          *(undefined2 *)(iVar32 + 0x56) = 0x32;
        }
      }
      if (*(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xaa) != '\0') {
        bVar16 = *(byte *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0xaa);
        uStack_6 = (far_t *)(ulong)CONCAT12(bVar16,(far_t *)uStack_6);
        pfVar1 = uStack_6;
        for (uVar43 = 0; uStack_6 = pfVar1, (int)uVar43 < (int)(uint)DAT_2000_d1e6;
            uVar43 = uVar43 + 1) {
          uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar45 = (int)*(undefined4 *)((int)uStack_16 << 2);
          iVar32 = *(int *)(iVar45 + 0x58);
          uVar47 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
          iVar34 = (int)*(undefined4 *)((int)uStack_16 << 2);
          iVar60 = *(int *)(iVar34 + 0x8c);
          if ((iVar60 <= iVar32) &&
             ((iVar32 != iVar60 || (*(uint *)(iVar34 + 0x8a) <= *(uint *)(iVar45 + 0x56))))) break;
          if ((*(char *)((int)*(undefined4 *)(uVar43 << 2) + 0x3d) != '\0') &&
             (((0 < *(int *)((int)*(undefined4 *)(uVar43 << 2) + 0x54) &&
               (*(char *)((int)*(undefined4 *)(uVar43 << 2) + 0x3f) == '\0')) &&
              ((far_t *)uVar43 != uStack_16)))) {
            (*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) = (uint)bVar16;
            local_32[2] = (int)(((long)*(int *)((int)*(undefined4 *)(uVar43 << 2) + 0x54) *
                                 (long)(int)(*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) & 0xffffU) / 100);
            local_32[3] = 0;
            uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
            uVar19 = *(uint *)(iVar32 + 0x8a);
            uVar47 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar60 = (int)*(undefined4 *)((int)uStack_16 << 2);
            puVar3 = (uint *)(iVar60 + 0x56);
            iVar32 = (*(int *)(iVar32 + 0x8c) - *(int *)(iVar60 + 0x58)) - (uint)(uVar19 < *puVar3);
            if ((iVar32 < 1) && ((iVar32 < 0 || (uVar19 - *puVar3 < (uint)local_32[2])))) {
              uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
              iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
              uVar19 = *(uint *)(iVar32 + 0x8a);
              uVar47 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
              iVar60 = (int)*(undefined4 *)((int)uStack_16 << 2);
              puVar3 = (uint *)(iVar60 + 0x56);
              local_32[2] = uVar19 - *puVar3;
              local_32[3] = (*(int *)(iVar32 + 0x8c) - *(int *)(iVar60 + 0x58)) -
                            (uint)(uVar19 < *puVar3);
            }
            uVar46 = (undefined2)((ulong)*(undefined4 *)(uVar43 << 2) >> 0x10);
            iVar60 = (int)*(undefined4 *)(uVar43 << 2);
            iVar32 = *(int *)(iVar60 + 0x58);
            if ((iVar32 <= local_32[3]) &&
               ((iVar32 < local_32[3] || (*(uint *)(iVar60 + 0x56) < (uint)local_32[2])))) {
              uVar46 = (undefined2)((ulong)*(undefined4 *)(uVar43 << 2) >> 0x10);
              iVar32 = (int)*(undefined4 *)(uVar43 << 2);
              local_32[3] = *(int *)(iVar32 + 0x58);
              local_32[2] = *(uint *)(iVar32 + 0x56);
            }
            uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
            iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
            puVar3 = (uint *)(iVar32 + 0x56);
            uVar19 = *puVar3;
            *puVar3 = *puVar3 + local_32[2];
            piVar4 = (int *)(iVar32 + 0x58);
            *piVar4 = *piVar4 + local_32[3] + (uint)CARRY2(uVar19,local_32[2]);
            uVar46 = (undefined2)((ulong)*(undefined4 *)(uVar43 << 2) >> 0x10);
            iVar32 = (int)*(undefined4 *)(uVar43 << 2);
            puVar3 = (uint *)(iVar32 + 0x56);
            uVar19 = *puVar3;
            *puVar3 = *puVar3 - local_32[2];
            piVar4 = (int *)(iVar32 + 0x58);
            *piVar4 = (*piVar4 - local_32[3]) - (uint)(uVar19 < (uint)local_32[2]);
          }
        }
      }
      iVar32 = *(int *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x58);
      if ((iVar32 < 1) && (iVar32 < 0)) {
        uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar32 + 0x58) = 0;
        *(undefined2 *)(iVar32 + 0x56) = 0;
      }
      uVar46 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar45 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar32 = *(int *)(iVar45 + 0x58);
      uVar47 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
      iVar34 = (int)*(undefined4 *)((int)uStack_16 << 2);
      iVar60 = *(int *)(iVar34 + 0x8c);
      if ((iVar60 <= iVar32) &&
         ((iVar60 < iVar32 || (*(uint *)(iVar34 + 0x8a) < *(uint *)(iVar45 + 0x56))))) {
        uVar47 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar32 = (int)*(undefined4 *)((int)uStack_16 << 2);
        uVar46 = *(undefined2 *)(iVar32 + 0x8a);
        uVar49 = (undefined2)((ulong)*(undefined4 *)((int)uStack_16 << 2) >> 0x10);
        iVar60 = (int)*(undefined4 *)((int)uStack_16 << 2);
        *(undefined2 *)(iVar60 + 0x58) = *(undefined2 *)(iVar32 + 0x8c);
        *(undefined2 *)(iVar60 + 0x56) = uVar46;
      }
    }
  }
  GGameState = 0x40;
  if (DebugVerbose != false) {
    printf("%d \r",0x40);
  }
  pfVar22 = (far_t *)&GUnitDescriptions[3].ofs;
  while (pfVar22 = (far_t *)((int)&pfVar22->ofs + 1), pfVar22 < DAT_2000_ca99) {
    uVar46 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
    iVar32 = (int)DAT_2000_ca95;
    if ((*(uint *)((uint)*(byte *)(iVar32 + (int)pfVar22 * 9) * 0x27 + 0x121) & 0x40) != 0) {
      if (*(char *)(iVar32 + (int)pfVar22 * 9 + 8) != '\0') {
        pcVar57 = (char *)(iVar32 + (int)pfVar22 * 9 + 8);
        *pcVar57 = *pcVar57 + -1;
      }
      uVar46 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
      if (*(char *)((int)DAT_2000_ca95 + (int)pfVar22 * 9 + 8) == '\0') {
        uVar9 = *(undefined4 *)((uint)*(byte *)((int)DAT_2000_ca95 + (int)pfVar22 * 9 + 2) << 2);
        if (*(char *)((int)uVar9 + 0x3f) == '\0') {
          ovr_play_sfx(81,0);
          pcVar26 = (char *)"puppetmaker" + 3;
          pcVar25 = (char *)ovr_OVC23_55fe_3450();
          pcVar25 = ovr_fmVsprintf((char *)"Mine exhausted at (%d, %d).",pcVar25);
          ovr_say((char *)CONCAT13((char)((uint)pcVar26 >> 8),CONCAT12((char)pcVar26,pcVar25)));
          ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
        }
        OVC22_5087_1674();
      }
    }
  }
  GGameState = 0x42;
  if (DebugVerbose != false) {
    printf("%d \r",0x42);
  }
  ovr_driver_2d63_0a67();
  for (uStack_16 = (far_t *)0x0; uStack_16 < DAT_2410_0881;
      uStack_16 = (far_t *)((int)uStack_16 + 1)) {
    puVar3 = (uint *)((int)DAT_2000_cb09 + *(int *)((int)uStack_16 * 0x13 + 2) * 0x128 +
                     *(int *)((int)uStack_16 * 0x13) * 2);
    *puVar3 = *puVar3 | 8;
  }
  if (EntityCount <= DAT_2410_55d6) {
    DAT_2410_55d6 = (uint16_t)(0x0);
    for (uStack_16 = (far_t *)0x0; (int)uStack_16 < (int)(uint)DAT_2000_d1e6;
        uStack_16 = (far_t *)((int)uStack_16 + 1)) {
      if (*(char *)((int)*(undefined4 *)((int)uStack_16 << 2) + 0x3d) != '\0') {
        memcpy((uint8_t *)(*(int *)((int)uStack_16 * 4) + 0x8e),
               (uint8_t *)(*(int *)((int)uStack_16 * 4) + 0x94),3);
      }
    }
  }
  uStack_e = (far_t *)0x0;
  bVar16 = ovr_manage_4d05_1b1d();
  (*(uint16_t *)((uint8_t *)&(uStack_6))) = (far_t *)CONCAT11(bVar16,(byte)uStack_6);
  if ((bVar16 == 0xff) || (DAT_2000_d1e8 == '\0')) {
    local_c = (far_t *)0x0;
  }
  else if (*(byte *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0x86) < 5) {
    local_c = (far_t *)0x28;
  }
  else {
    local_c = (far_t *)((uint)*(byte *)((int)*(undefined4 *)((uint)bVar16 << 2) + 0x86) * 4 + 0x14);
  }
  for (uStack_16 = DAT_2410_55d6; uStack_16 < EntityCount;
      uStack_16 = (far_t *)((int)&uStack_16->ofs + 1)) {
    uVar48 = Entities.seg;
    uVar20 = Entities.ofs;
    if (((*(char *)(uVar20 + (int)uStack_16 * 0x37 + 0x18) == '\0') &&
        (*(int *)(uVar20 + (int)uStack_16 * 0x37 + 8) == 0)) &&
       (*(int *)(uVar20 + (int)uStack_16 * 0x37 + 10) == 0)) {
      bVar16 = *(byte *)(uVar20 + (int)uStack_16 * 0x37 + 0xd);
      uStack_6 = (far_t *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),bVar16);
      uStack_22 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_22) + 1)),
                           *(undefined1 *)((int)(char **)GMenuStrings + (uint)bVar16 * 0x95 + 0x1f))
      ;
      bVar14 = *(byte *)(uVar20 + (int)uStack_16 * 0x37 + 0x1a);
      uStack_24 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_24) + 1)),bVar14);
      uStack_26 = 0;
      uStack_28 = uStack_28 & 0xff;
      if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bVar16 * 0x95) == -1) {
        uStack_26 = 0x100;
      }
      else {
        uVar9 = *(undefined4 *)((uint)bVar14 << 2);
        bStack_1b = *(byte *)((int)uVar9 + 0x89);
        if (bStack_1b < 5) {
          uStack_1a = *(uint *)(uVar20 + (int)uStack_16 * 0x37 + 2);
          uStack_18 = ovr_OVC23_55fe_3450();
          if ((*(uint *)((int)DAT_2000_cb09 + uStack_1a * 0x128 + uStack_18 * 2) & 8) == 0) {
            uStack_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)),0x22);
            uStack_20 = (char *)"stronghold" + 6;
          }
          else {
            pcStackY_60 = (char *)"dwarf outpost" + 6;
            pcStackY_62 = (char *)"portrait\\sp23.lbm" + 0x11;
            ovr_attact_3f0b_0585();
            pcStackY_60 = (char *)"ringmaker\'s shop" + 7;
            pcStackY_62 = (char *)"portrait\\sp24.lbm" + 9;
            ovr_attact_3f0b_2303();
          }
        }
        else {
          uStack_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)),0x22);
          uStack_20 = (char *)"stronghold" + 6;
        }
        uVar20 = ovr_randBelow(100);
        uStack_22 = CONCAT11((byte)uVar20,(char)uStack_22);
        if ((byte)uVar20 < (byte)uStack_1e) {
          uStack_26 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_26) + 1)) + '\x01',(char)uStack_26);
        }
        else if ((uVar20 & 0xff) < ((uint)uStack_20 >> 8) + (uStack_1e & 0xff)) {
          uStack_26 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_26) + 1)),(char)uStack_26 + '\x01');
        }
        else {
          uStack_28 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_28) + 1)) + '\x01',(undefined1)uStack_28);
        }
      }
      if (((*(uint8_t *)((uint8_t *)&(uStack_28) + 1)) != '\0') && (cVar17 = ovr_OVC23_55fe_0487(), cVar17 == '\0')) {
        if (((*(uint8_t *)((uint8_t *)&(uStack_20) + 1)) == 0) && ((byte)uStack_1e == '\0')) {
          uVar20 = ovr_randBelow(2);
          if ((uVar20 & 0xff) == 0) {
            uStack_26 = CONCAT11(1,(char)uStack_26);
          }
          else {
            uStack_26 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_26) + 1)),1);
          }
        }
        else {
          uVar20 = ovr_randBelow((uint)(*(uint8_t *)((uint8_t *)&(uStack_20) + 1)) + (uStack_1e & 0xff));
          if ((byte)uVar20 < (byte)uStack_1e) {
            uStack_26 = CONCAT11(1,(char)uStack_26);
          }
          else {
            uStack_26 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_26) + 1)),1);
          }
        }
      }
      if (((*(uint8_t *)((uint8_t *)&(uStack_26) + 1)) != '\0') && (cVar17 = OVC22_5087_1532(), cVar17 == '\0')) {
        uStack_26 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_26) + 1)),1);
      }
      if ((char)uStack_26 != '\0') {
        if ((*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)(byte)uStack_6 * 0x95) != -1)
           && ((char)uStack_24 != -1)) {
          uVar9 = *(undefined4 *)((uStack_24 & 0xff) << 2);
          if ((*(char *)((int)uVar9 + 0x3f) != '\0') ||
             (uVar9 = *(undefined4 *)((uStack_24 & 0xff) << 2),
             *(byte *)(Entities.ofs + (int)uStack_16 * 0x37 + 0xf) < *(byte *)((int)uVar9 + 0x53)))
          {
            iVar32 = Entities.ofs + (int)uStack_16 * 0x37;
            uVar46 = OVC22_5087_18b6();
            LXMUL_at_(3,CONCAT22(iVar32,uVar46));
            iVar32 = Entities.ofs + (int)uStack_16 * 0x37;
            ovr_OVC15_4207_26bc();
            uVar19 = OVC22_5087_1d4a();
            uVar20 = Entities.seg;
            iVar60 = Entities.ofs + (int)uStack_16 * 0x37;
            uVar43 = *(uint *)(iVar60 + 0x10);
            iVar45 = Entities.ofs + (int)uStack_16 * 0x37;
            *(int *)(iVar45 + 0x12) = *(int *)(iVar60 + 0x12) + iVar32 + (uint)CARRY2(uVar43,uVar19)
            ;
            *(int *)(iVar45 + 0x10) = uVar43 + uVar19;
            ovr_OVC41_6a8f_002e();
          }
        }
        OVC22_5087_1991();
        OVC22_5087_1ac1();
        OVC22_5087_1ca4();
      }
      uVar9 = *(undefined4 *)((uStack_24 & 0xff) << 2);
      local_2a = (uint)*(byte *)(Entities.ofs + (int)uStack_16 * 0x37 + 0xe) -
                 (uint)*(byte *)((int)uVar9 + 0xa4);
      if (0 < local_2a) {
        if (3 < local_2a) {
          local_2a = 3;
        }
        if (local_2a == 3) {
          uVar9 = *(undefined4 *)((uStack_24 & 0xff) << 2);
          if (*(int *)((int)uVar9 + 0x92) == 0) {
            local_2a = 2;
          }
          else {
            uVar9 = *(undefined4 *)((uStack_24 & 0xff) << 2);
            piVar4 = (int *)((int)uVar9 + 0x92);
            *piVar4 = *piVar4 + -1;
          }
        }
        if (local_2a == 2) {
          uVar9 = *(undefined4 *)((uStack_24 & 0xff) << 2);
          if (*(int *)((int)uVar9 + 0x90) == 0) {
            local_2a = 1;
          }
          else {
            uVar9 = *(undefined4 *)((uStack_24 & 0xff) << 2);
            piVar4 = (int *)((int)uVar9 + 0x90);
            *piVar4 = *piVar4 + -1;
          }
        }
        if (local_2a == 1) {
          uVar9 = *(undefined4 *)((uStack_24 & 0xff) << 2);
          if (*(int *)((int)uVar9 + 0x8e) == 0) {
            local_2a = 0;
          }
          else {
            uVar9 = *(undefined4 *)((uStack_24 & 0xff) << 2);
            piVar4 = (int *)((int)uVar9 + 0x8e);
            *piVar4 = *piVar4 + -1;
          }
        }
        uVar9 = *(undefined4 *)((uStack_24 & 0xff) << 2);
        *(char *)(Entities.ofs + (int)uStack_16 * 0x37 + 0xe) =
             *(char *)((int)uVar9 + 0xa4) + (char)local_2a;
      }
      uStack_e = (far_t *)((int)uStack_e + 1);
      if (199 < (int)uStack_e) break;
    }
  }
  DAT_2410_55d6 = uStack_16;
  DAT_2410_648e = 1;
  ovr_unit_6616_00d8();
  GGameState = 0x44;
  pfVar22 = (far_t *)((char *)"puppetmaker" + 3);
  if (DebugVerbose != false) {
    pfVar22 = (far_t *)printf("%d \r",0x44);
  }
  if ((*(uint8_t *)((uint8_t *)&(uStack_1e) + 1)) != '\0') {
    pfVar22 = (far_t *)((int)&EntityCount[-1].seg + 1);
    for (uStack_16 = pfVar22; -1 < (int)uStack_16;
        uStack_16 = (far_t *)((int)&uStack_16[-1].seg + 1)) {
      pfVar22 = (far_t *)(uint)*(byte *)(Entities.ofs + (int)uStack_16 * 0x37 + 0xe);
      if (pfVar22 == (far_t *)0x0) {
        if (*(char *)((int)(char **)GMenuStrings +
                     (uint)*(byte *)(Entities.ofs + (int)uStack_16 * 0x37 + 0xd) * 0x95 + 0x1f) ==
            '\0') {
          uVar15 = 0;
          uVar58 = 0xa0;
          ovr_OVC23_55fe_3450();
          uVar46 = 0x195d;
          pcVar25 = ovr_fmVsprintf((char *)
                                   "Intelligence reports %s unit died of starvation. (%d, %d)",
                                   (char *)*(undefined2 *)
                                            ((int)&far_t_ARRAY_2410_26f7[0].seg + 1 +
                                            (uint)*(byte *)(Entities.ofs + (int)uStack_16 * 0x37 +
                                                           0xd) * 0x95));
          ovr_uiNotify((char *)CONCAT13((char)((uint)uVar46 >> 8),CONCAT12((char)uVar46,pcVar25)),
                       CONCAT11(uVar58,uVar15));
        }
        pfVar22 = (far_t *)ovr_OVC15_4207_0e17();
      }
    }
  }
  if (cStack_1c != '\0') {
    pfVar22 = (far_t *)ovr_constr_36ce_1db4();
  }
  return pfVar22;
}



/* 5087:1470 */

undefined2 __cdecl16far OVC22_5087_1470(byte param_1)

{
  undefined4 uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  undefined2 uVar5;
  
  if (*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3f) == '\0') {
    cVar3 = (char)((ulong)*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x45) / 10);
    bVar2 = cVar3 + 2;
    uVar5 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
    iVar4 = (int)*(undefined4 *)((uint)param_1 << 2);
    if ((uint)(*(int *)(iVar4 + 0x4d) * 2 + *(int *)(iVar4 + 0x4d)) >> 1 <=
        *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4f)) {
      bVar2 = cVar3 + 4;
    }
  }
  else {
    bVar2 = DAT_2000_d2e6 / 2 + 1;
  }
  if (10 < bVar2) {
    bVar2 = 10;
  }
  uVar1 = *(undefined4 *)((uint)param_1 << 2);
  *(byte *)((int)uVar1 + 0xa4) = bVar2;
  return CONCAT11((char)(((uint)param_1 << 2) >> 8),bVar2);
}



/* 5087:1532 */

uint __cdecl16far OVC22_5087_1532(int param_1)

{
  char *pcVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  
  uVar6 = Entities.seg;
  uVar5 = Entities.ofs;
  bVar2 = *(byte *)(uVar5 + param_1 * 0x37 + 0x1a);
  if (bVar2 == 0xff) {
    uVar3 = param_1 * 0x37 & 0xff00;
  }
  else {
    uVar3 = (uint)*(byte *)(uVar5 + param_1 * 0x37 + 0xd) * 0x95;
    if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].seg + 1 + uVar3) & 0x800) == 0) {
      if ((*(char *)((int)*(undefined4 *)((uint)bVar2 << 2) + 0x3f) == '\0') &&
         (uVar3 = *(uint *)((int)*(undefined4 *)((uint)bVar2 << 2) + 0x5b),
         uVar3 < *(uint *)((int)*(undefined4 *)((uint)bVar2 << 2) + 0x4d))) {
        uVar3 = uVar3 & 0xff00;
      }
      else {
        bVar4 = 3;
        while ((bVar4 != 0 &&
               (*(int *)((int)*(undefined4 *)((uint)bVar2 << 2) + (uint)bVar4 * 2 + 0x8c) == 0))) {
          bVar4 = bVar4 - 1;
        }
        if (*(byte *)(uVar5 + param_1 * 0x37 + 0xe) <
            (byte)(*(char *)((int)*(undefined4 *)((uint)bVar2 << 2) + 0xa4) + bVar4)) {
          pcVar1 = (char *)(uVar5 + param_1 * 0x37 + 0xe);
          *pcVar1 = *pcVar1 + '\x01';
          uVar3 = CONCAT11((char)((uint)(param_1 * 0x37) >> 8),1);
        }
        else {
          uVar3 = param_1 * 0x37 & 0xff00;
        }
      }
    }
    else {
      uVar3 = uVar3 & 0xff00;
    }
  }
  return uVar3;
}



/* 5087:1674 */

void __cdecl16far OVC22_5087_1674(int param_1,undefined1 *param_2,undefined1 param_3)

{
  byte bVar1;
  char cVar2;
  undefined1 extraout_AH;
  int iVar3;
  uint uVar4;
  undefined2 uVar5;
  
  uVar4 = 0;
  while( true ) {
    iVar3 = (int)DAT_2000_ca95;
    uVar5 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
    if (DAT_2000_d2df <= uVar4) {
      bVar1 = *(byte *)(iVar3 + param_1 * 9);
      if ((*(uint *)((uint)bVar1 * 0x27 + 0x121) & 4) == 0) {
        cVar2 = OVC22_5087_503d(CONCAT11((char)((uint)(param_1 * 9) >> 8),
                                         *(undefined1 *)(iVar3 + param_1 * 9 + 4)),
                                CONCAT11((char)((uint)(param_1 * 9) >> 8),
                                         *(undefined1 *)(iVar3 + param_1 * 9 + 6)));
        if (cVar2 != '\0') {
          *param_2 = 1;
        }
        uVar5 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
        ovr_OVC23_55fe_1e87(0,*(undefined2 *)((int)DAT_2000_ca95 + param_1 * 9 + 4),
                            *(undefined2 *)((int)DAT_2000_ca95 + param_1 * 9 + 6),
                            (undefined1 *)param_2,(*(uint16_t *)((uint8_t *)&(param_2) + 2)),param_3);
        if (1 < *(byte *)((uint)bVar1 * 0x27 + 0x11b)) {
          uVar5 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
          ovr_OVC23_55fe_1e87(0,*(int *)((int)DAT_2000_ca95 + param_1 * 9 + 4) + 1,
                              *(undefined2 *)((int)DAT_2000_ca95 + param_1 * 9 + 6),
                              (undefined1 *)param_2,(*(uint16_t *)((uint8_t *)&(param_2) + 2)),
                              CONCAT11((char)((uint)bVar1 * 0x27 >> 8),param_3));
          if (3 < *(byte *)((uint)bVar1 * 0x27 + 0x11b)) {
            uVar5 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
            ovr_OVC23_55fe_1e87(0,*(int *)((int)DAT_2000_ca95 + param_1 * 9 + 4) + 2,
                                *(undefined2 *)((int)DAT_2000_ca95 + param_1 * 9 + 6),
                                (undefined1 *)param_2,(*(uint16_t *)((uint8_t *)&(param_2) + 2)),
                                CONCAT11((char)((uint)bVar1 * 0x27 >> 8),param_3));
            uVar5 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
            ovr_OVC23_55fe_1e87(0,*(int *)((int)DAT_2000_ca95 + param_1 * 9 + 4) + 3,
                                *(undefined2 *)((int)DAT_2000_ca95 + param_1 * 9 + 6),
                                (undefined1 *)param_2,(*(uint16_t *)((uint8_t *)&(param_2) + 2)),CONCAT11(extraout_AH,param_3));
          }
        }
      }
      return;
    }
    if ((*(int *)(uVar4 * 0x12 + 2) == *(int *)(iVar3 + param_1 * 9 + 4)) &&
       (*(int *)(uVar4 * 0x12 + 4) == *(int *)(iVar3 + param_1 * 9 + 6))) break;
    uVar4 = uVar4 + 1;
  }
  return;
}



/* 5087:18b6 */

void __cdecl16far OVC22_5087_18b6(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 uVar6;
  byte bStack_3;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  uVar1 = *(undefined4 *)((uint)*(byte *)(iVar5 + 0x1a) << 2);
  uVar2 = *(byte *)((int)uVar1 + 0x52) + 1;
  if (*(byte *)(iVar5 + 0xf) < uVar2) {
    uVar2 = (uint)*(byte *)(iVar5 + 0xf);
  }
  if (0x24 < uVar2) {
    uVar2 = 0x24;
  }
  uVar1 = *(undefined4 *)((uint)*(byte *)(iVar5 + 0x1a) << 2);
  bStack_3 = *(byte *)((int)uVar1 + 0x2f);
  if (bStack_3 == 0xff) {
    bStack_3 = 0;
  }
  for (; (piVar3 = (int *)((uint)bStack_3 * 0x94 + uVar2 * 4), *piVar3 == 0 && piVar3[1] == 0 &&
         (uVar2 != 0)); uVar2 = uVar2 - 1) {
  }
  puVar4 = (undefined2 *)((uint)bStack_3 * 0x94 + uVar2 * 4);
  LUDIV_at_(*puVar4,puVar4[1],0x1e,0);
  return;
}



/* 5087:197d */

char __cdecl16far OVC22_5087_197d(char param_1)

{
  if (param_1 < '\0') {
    param_1 = param_1 + '\x06';
  }
  return param_1;
}



/* 5087:1991 */

void __cdecl16far OVC22_5087_1991(int param_1)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  char cVar4;
  char cVar5;
  char cStack_5;
  
  if (*(char *)(Entities.ofs + param_1 * 0x37 + 0x1a) != -1) {
    cVar4 = ovr_agnt_3b1d_0c7c(Entities.ofs + param_1 * 0x37,Entities.seg);
    bVar2 = *(byte *)(Entities.ofs + param_1 * 0x37 + 0x1a);
    for (cStack_5 = '\0'; cStack_5 < '\x03'; cStack_5 = cStack_5 + '\x01') {
      uVar3 = *(undefined4 *)((uint)bVar2 << 2);
      if ((*(int *)((int)uVar3 + cStack_5 * 2 + 0x6a) != 0) && (cVar4 < cStack_5)) {
        uVar3 = *(undefined4 *)((uint)bVar2 << 2);
        piVar1 = (int *)((int)uVar3 + cStack_5 * 2 + 0x6a);
        *piVar1 = *piVar1 + -1;
        cVar4 = *(char *)(Entities.ofs + param_1 * 0x37 + 0x36) -
                *(byte *)(Entities.ofs + param_1 * 0x37 + 0x36) % 6;
        cVar5 = OVC22_5087_197d(CONCAT11((char)((uint)(param_1 * 0x37) >> 8),cStack_5));
        *(char *)(Entities.ofs + param_1 * 0x37 + 0x36) = cVar4 + cVar5;
        return;
      }
    }
  }
  return;
}



/* 5087:1ac1 */

void __cdecl16far OVC22_5087_1ac1(int param_1)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  uint16_t uVar6;
  uint16_t uVar7;
  char cStack_7;
  char cStack_6;
  
  if (*(char *)(Entities.ofs + param_1 * 0x37 + 0x1a) != -1) {
    cVar4 = ovr_agnt_3b1d_0cc6(Entities.ofs + param_1 * 0x37,Entities.seg);
    bVar2 = *(byte *)(Entities.ofs + param_1 * 0x37 + 0x1a);
    for (cStack_6 = '\0'; cStack_6 < '\x04'; cStack_6 = cStack_6 + '\x01') {
      uVar3 = *(undefined4 *)((uint)bVar2 << 2);
      if ((*(int *)((int)uVar3 + cStack_6 * 2 + 0x76) != 0) && ((int)cVar4 < cStack_6 + 1)) {
        cStack_7 = cStack_6;
        uVar3 = *(undefined4 *)((uint)bVar2 << 2);
        piVar1 = (int *)((int)uVar3 + cStack_6 * 2 + 0x76);
        *piVar1 = *piVar1 + -1;
        uVar7 = Entities.seg;
        uVar6 = Entities.ofs;
        *(char *)(uVar6 + param_1 * 0x37 + 0x36) =
             *(char *)(uVar6 + param_1 * 0x37 + 0x36) +
             (char)(((ulong)*(byte *)(uVar6 + param_1 * 0x37 + 0x36) / 6) % 6) * -6;
        bVar2 = *(byte *)(Entities.ofs + param_1 * 0x37 + 0xd);
        if ((*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bVar2 * 0x95) == '\x03') &&
           ('\x01' < cStack_6)) {
          cStack_7 = '\x01';
        }
        iVar5 = (uint)bVar2 * 0x95;
        if ((*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + iVar5) == '\x01') &&
           ('\x02' < cStack_7)) {
          cStack_7 = '\x02';
        }
        cVar4 = OVC22_5087_197d(CONCAT11((char)((uint)iVar5 >> 8),cStack_7 + '\x01'));
        *(char *)(Entities.ofs + param_1 * 0x37 + 0x36) =
             *(char *)(Entities.ofs + param_1 * 0x37 + 0x36) + cVar4 * '\x06';
        return;
      }
    }
  }
  return;
}



/* 5087:1ca4 */

void __cdecl16far OVC22_5087_1ca4(int param_1)

{
  char *pcVar1;
  uint *puVar2;
  byte bVar3;
  undefined4 uVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  
  uVar6 = Entities.seg;
  uVar5 = Entities.ofs;
  if (((*(char *)(uVar5 + param_1 * 0x37 + 0x1a) != -1) &&
      ((*(uint *)(uVar5 + param_1 * 0x37 + 0x14) & 2) == 0)) &&
     (bVar3 = *(byte *)(uVar5 + param_1 * 0x37 + 0x1a), uVar4 = *(undefined4 *)((uint)bVar3 << 2),
     *(char *)((int)uVar4 + 0xa7) != '\0')) {
    uVar4 = *(undefined4 *)((uint)bVar3 << 2);
    pcVar1 = (char *)((int)uVar4 + 0xa7);
    *pcVar1 = *pcVar1 + -1;
    puVar2 = (uint *)(Entities.ofs + param_1 * 0x37 + 0x14);
    *puVar2 = *puVar2 | 2;
  }
  return;
}



/* 5087:1d4a */

undefined2 __cdecl16far OVC22_5087_1d4a(undefined2 param_1,undefined2 param_2,int param_3)

{
  long lVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  if (param_3 != 0) {
    uVar3 = 0;
    uVar2 = 100;
    lVar1 = LXMUL_at_(CONCAT22(param_2,param_1),(ulong)(param_3 + 100));
    param_1 = LUDIV_at_(lVar1,uVar2,uVar3);
  }
  return param_1;
}



/* 5087:1d7d */

void __cdecl16far upd_units_5087_1d7d(void)

{
  byte *pbVar1;
  char *pcVar2;
  uint *puVar3;
  int *piVar4;
  byte bVar5;
  undefined1 uVar6;
  uint uVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  char cVar11;
  char cVar12;
  uint16_t uVar13;
  uint uVar14;
  char *pcVar15;
  char *pcVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  undefined2 unaff_DI;
  uint uVar21;
  undefined2 uVar22;
  undefined2 uVar23;
  uint16_t uVar24;
  undefined2 uVar25;
  bool bVar26;
  ulong uVar27;
  uint16_t dst;
  uint uStack_2e;
  int iStack_2c;
  int iStack_2a;
  byte local_20;
  byte local_1f;
  byte local_1e;
  char cStack_1d;
  char local_1c;
  byte bStack_1b;
  int iStack_1a;
  int iStack_18;
  uint uStack_16;
  uint uStack_14;
  uint uStack_12;
  uint uStack_10;
  int iStack_e;
  int iStack_c;
  uint uStack_a;
  uint16_t uStack_8;
  byte bStack_6;
  byte bStack_5;
  uint uStack_4;
  
  if (!GameRunning) {
    cStack_1d = '\0';
    local_1c = '\0';
    for (uStack_16 = 0xf8; uStack_16 < DAT_2000_ca99; uStack_16 = uStack_16 + 1) {
      pbVar1 = (byte *)((int)DAT_2000_ca95 + uStack_16 * 9 + 3);
      *pbVar1 = *pbVar1 & 0xfc;
    }
    for (uStack_16 = 0; (int)uStack_16 < (int)(uint)DAT_2000_d1e6; uStack_16 = uStack_16 + 1) {
      if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3d) != '\0') {
        OVC22_5087_056e(CONCAT11(0x21,(undefined1)uStack_16));
      }
    }
    GGameState = 0x3e;
    if (DebugVerbose != false) {
      printf("%d \r",0x3e);
    }
    for (uVar21 = 0xf8; uVar21 < DAT_2000_ca99; uVar21 = uVar21 + 1) {
      uVar22 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
      iVar17 = (int)DAT_2000_ca95;
      if ((*(byte *)(iVar17 + uVar21 * 9 + 3) & 3) == 0) {
        bVar5 = *(byte *)(iVar17 + uVar21 * 9 + 2);
        if ((bVar5 == 0xff) ||
           (uVar8 = *(undefined4 *)((uint)bVar5 << 2), *(char *)((int)uVar8 + 0x3f) == '\0')) {
          uStack_8 = 0x96;
        }
        else {
          uStack_8 = 0x5dc;
        }
        if (*(char *)(iVar17 + uVar21 * 9 + 1) != '\0') {
          uVar13 = ovr_randBelow(uStack_8);
          uVar22 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
          iVar17 = (int)DAT_2000_ca95;
          if ((int)(uVar13 & 0xff) <
              (int)(100 - (uint)*(byte *)((uint)*(byte *)(iVar17 + uVar21 * 9) * 0x27 + 0x130))) {
            local_20 = *(byte *)(iVar17 + uVar21 * 9);
            pcVar2 = (char *)(iVar17 + uVar21 * 9 + 1);
            *pcVar2 = *pcVar2 + -1;
            iVar17 = (int)DAT_2000_ca95;
            uVar22 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
            if (((*(uint *)((uint)local_20 * 0x27 + 0x121) & 4) == 0) &&
               ((*(char *)(iVar17 + uVar21 * 9 + 1) == '\0' ||
                ((*(uint *)((uint)local_20 * 0x27 + 0x121) & 0x200) != 0)))) {
              OVC22_5087_1674(uVar21,&local_1c);
            }
            else if (((*(int *)((char *)"build\\clebath2.lbm" + 0xc + (uint)local_20 * 0xc) != 0 ||
                       *(int *)((char *)"build\\clebath2.lbm" + 0xe + (uint)local_20 * 0xc) != 0) ||
                     (*(char *)((uint)local_20 * 0x27 + 0x11e) == '\x10')) &&
                    (cVar11 = OVC22_5087_510e(CONCAT11((char)(uVar21 * 9 >> 8),
                                                       *(undefined1 *)(iVar17 + uVar21 * 9 + 4)),
                                              CONCAT11((char)(uVar21 * 9 >> 8),
                                                       *(undefined1 *)(iVar17 + uVar21 * 9 + 6))),
                    cVar11 != '\0')) {
              local_1c = '\x01';
            }
          }
        }
      }
    }
    GGameState = 0x43;
    if (DebugVerbose != false) {
      printf("%d \r",0x43);
    }
    for (uStack_16 = 0; (int)uStack_16 < (int)(uint)DAT_2000_d1e6; uStack_16 = uStack_16 + 1) {
      if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3d) != '\0') {
        *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa2) = 0;
        cVar11 = *(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3f);
        if ((cVar11 == '\0') &&
           (*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f) <
            *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d) >> 1)) {
          bVar9 = true;
        }
        else {
          bVar9 = false;
        }
        uVar21 = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54);
        uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar17 = *(int *)(iVar17 + 0x58) + ((int)uVar21 >> 0xf) +
                 (uint)CARRY2(*(uint *)(iVar17 + 0x56),uVar21);
        if ((iVar17 < 1) && (iVar17 < 0)) {
          for (uVar21 = 0xf8; uVar21 < DAT_2000_ca99; uVar21 = uVar21 + 1) {
            uVar22 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
            iVar17 = (int)DAT_2000_ca95;
            local_20 = *(byte *)(iVar17 + uVar21 * 9);
            if ((*(byte *)(iVar17 + uVar21 * 9 + 2) == uStack_16) &&
               (*(int *)((uint)local_20 * 0x27 + 0x123) < 0)) {
              uVar14 = *(uint *)((uint)local_20 * 0x27 + 0x123);
              uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
              iVar20 = *(int *)(iVar20 + 0x58) + ((int)uVar14 >> 0xf) +
                       (uint)CARRY2(*(uint *)(iVar20 + 0x56),uVar14);
              if ((iVar20 < 1) && (iVar20 < 0)) {
                if ((cVar11 == '\0') && (*(char *)(iVar17 + uVar21 * 9 + 1) != '\0')) {
                  uVar13 = ovr_randBelow(100);
                  uVar22 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
                  iVar17 = (int)DAT_2000_ca95;
                  if (*(byte *)((uint)*(byte *)(iVar17 + uVar21 * 9) * 0x27 + 0x130) <= (byte)uVar13
                     ) {
                    if (*(char *)(iVar17 + uVar21 * 9 + 1) != '\0') {
                      pcVar2 = (char *)(iVar17 + uVar21 * 9 + 1);
                      *pcVar2 = *pcVar2 + -1;
                    }
                    iVar17 = (int)DAT_2000_ca95;
                    uVar22 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
                    if (((*(uint *)((uint)local_20 * 0x27 + 0x121) & 4) == 0) &&
                       ((*(char *)(iVar17 + uVar21 * 9 + 1) == '\0' ||
                        ((*(uint *)((uint)local_20 * 0x27 + 0x121) & 0x200) != 0)))) {
                      OVC22_5087_1674(uVar21,&local_1c);
                    }
                    else if (((*(int *)((char *)"build\\clebath2.lbm" + 0xc + (uint)local_20 * 0xc)
                               != 0 || *(int *)((char *)"build\\clebath2.lbm" + 0xe +
                                               (uint)local_20 * 0xc) != 0) ||
                             (*(char *)((uint)local_20 * 0x27 + 0x11e) == '\x10')) &&
                            (cVar12 = OVC22_5087_510e(CONCAT11((char)(uVar21 * 9 >> 8),
                                                               *(undefined1 *)
                                                                (iVar17 + uVar21 * 9 + 4)),
                                                      CONCAT11((char)(uVar21 * 9 >> 8),
                                                               *(undefined1 *)
                                                                (iVar17 + uVar21 * 9 + 6))),
                            cVar12 != '\0')) {
                      local_1c = '\x01';
                    }
                  }
                }
              }
              else {
                uVar7 = *(uint *)((uint)local_20 * 0x27 + 0x123);
                uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
                iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
                puVar3 = (uint *)(iVar17 + 0x56);
                uVar14 = *puVar3;
                *puVar3 = *puVar3 + uVar7;
                piVar4 = (int *)(iVar17 + 0x58);
                *piVar4 = *piVar4 + ((int)uVar7 >> 0xf) + (uint)CARRY2(uVar14,uVar7);
              }
            }
          }
          uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar17 + 0x58) = 0;
          *(undefined2 *)(iVar17 + 0x56) = 0;
        }
        else {
          if ((cVar11 == '\0') && (0 < *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54))) {
            uStack_10 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54) / 10;
          }
          else {
            uStack_10 = 0;
          }
          bVar26 = CARRY2(DAT_2000_ca91,uStack_10);
          DAT_2000_ca91 = DAT_2000_ca91 + uStack_10;
          DAT_2000_ca93 = DAT_2000_ca93 + ((int)uStack_10 >> 0xf) + (uint)bVar26;
          uVar14 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x54) - uStack_10;
          uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
          puVar3 = (uint *)(iVar17 + 0x56);
          uVar21 = *puVar3;
          *puVar3 = *puVar3 + uVar14;
          piVar4 = (int *)(iVar17 + 0x58);
          *piVar4 = *piVar4 + ((int)uVar14 >> 0xf) + (uint)CARRY2(uVar21,uVar14);
        }
        if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3e) * 0x95) & 0x100)
            == 0) {
          if (*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f) <
              *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d)) {
            uStack_12 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d) -
                        *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f);
            uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
            iVar17 = *(int *)(iVar20 + 0x62);
            if ((-1 < iVar17) && ((0 < iVar17 || (*(int *)(iVar20 + 0x60) != 0)))) {
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
              uVar21 = *(uint *)(iVar17 + 0x62);
              if ((0x7fff < uVar21) ||
                 ((uStack_14 = uStack_12, (int)uVar21 < 1 && (*(uint *)(iVar17 + 0x60) <= uStack_12)
                  ))) {
                uStack_14 = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x60);
              }
              uStack_12 = uStack_12 - uStack_14;
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
              puVar3 = (uint *)(iVar17 + 0x60);
              uVar21 = *puVar3;
              *puVar3 = *puVar3 - uStack_14;
              piVar4 = (int *)(iVar17 + 0x62);
              *piVar4 = *piVar4 - (uint)(uVar21 < uStack_14);
            }
            if (uStack_12 != 0) {
              uStack_a = uStack_12;
              if (*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0) < uStack_12) {
                uStack_a = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0);
              }
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
              uVar21 = *(uint *)(iVar17 + 0x58);
              if (((int)uVar21 < 1) && ((0x7fff < uVar21 || (*(uint *)(iVar17 + 0x56) < uStack_a))))
              {
                uStack_a = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x56);
              }
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
              puVar3 = (uint *)(iVar17 + 0x56);
              uVar21 = *puVar3;
              *puVar3 = *puVar3 - uStack_a;
              piVar4 = (int *)(iVar17 + 0x58);
              *piVar4 = *piVar4 - (uint)(uVar21 < uStack_a);
              uStack_12 = uStack_12 - uStack_a;
              *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa2) = uStack_a;
            }
            if (cVar11 == '\0') {
              for (iVar17 = 0; (uStack_12 != 0 && (iVar17 < (int)(uint)DAT_2000_d1e6));
                  iVar17 = iVar17 + 1) {
                if ((*(char *)((int)*(undefined4 *)(iVar17 << 2) + 0x3d) != '\0') &&
                   ((*(char *)((int)*(undefined4 *)(iVar17 << 2) + 0x3f) == '\0' &&
                    (uVar22 = (undefined2)((ulong)*(undefined4 *)(iVar17 << 2) >> 0x10),
                    iVar20 = (int)*(undefined4 *)(iVar17 << 2),
                    *(int *)(iVar20 + 0x60) != 0 || *(int *)(iVar20 + 0x62) != 0)))) {
                  uVar22 = (undefined2)((ulong)*(undefined4 *)(iVar17 << 2) >> 0x10);
                  iVar20 = (int)*(undefined4 *)(iVar17 << 2);
                  uVar21 = *(uint *)(iVar20 + 0x62);
                  if ((uVar21 < 0x8000) &&
                     ((0 < (int)uVar21 || (uStack_12 < *(uint *)(iVar20 + 0x60))))) {
                    uStack_14 = uStack_12;
                  }
                  else {
                    uStack_14 = *(uint *)((int)*(undefined4 *)(iVar17 << 2) + 0x60);
                  }
                  uStack_12 = uStack_12 - uStack_14;
                  uVar22 = (undefined2)((ulong)*(undefined4 *)(iVar17 << 2) >> 0x10);
                  iVar20 = (int)*(undefined4 *)(iVar17 << 2);
                  puVar3 = (uint *)(iVar20 + 0x60);
                  uVar21 = *puVar3;
                  *puVar3 = *puVar3 - uStack_14;
                  piVar4 = (int *)(iVar20 + 0x62);
                  *piVar4 = *piVar4 - (uint)(uVar21 < uStack_14);
                }
              }
            }
            uVar21 = 0;
            while ((uVar21 < EntityCount && (uStack_12 != 0))) {
              uVar24 = Entities.seg;
              uVar13 = Entities.ofs;
              if (((*(char *)(uVar13 + uVar21 * 0x37 + 0x18) == '\0') &&
                  (*(byte *)(uVar13 + uVar21 * 0x37 + 0x1a) == uStack_16)) &&
                 ((bVar9 || (1 < *(byte *)(uVar13 + uVar21 * 0x37 + 0xe))))) {
                if (*(char *)(uVar13 + uVar21 * 0x37 + 0xe) != '\0') {
                  if (DebugVerbose != false) {
                    printf("kill 3\r",unaff_DI);
                  }
                  pcVar2 = (char *)(Entities.ofs + uVar21 * 0x37 + 0xe);
                  *pcVar2 = *pcVar2 + -1;
                  if (*(char *)(Entities.ofs + uVar21 * 0x37 + 0xe) == '\0') {
                    cStack_1d = '\x01';
                  }
                }
                uStack_12 = uStack_12 - 1;
              }
              uVar21 = uVar21 + 1;
            }
          }
          else {
            uVar14 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4f) -
                     *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d);
            uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
            puVar3 = (uint *)(iVar17 + 0x60);
            uVar21 = *puVar3;
            *puVar3 = *puVar3 + uVar14;
            piVar4 = (int *)(iVar17 + 0x62);
            *piVar4 = *piVar4 + (uint)CARRY2(uVar21,uVar14);
          }
        }
        uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar17 = *(int *)(iVar18 + 0x62);
        uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar20 = *(int *)(iVar19 + 0x80);
        if ((iVar20 <= iVar17) &&
           ((iVar20 < iVar17 || (*(uint *)(iVar19 + 0x7e) < *(uint *)(iVar18 + 0x60))))) {
          uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
          uVar21 = *(uint *)(iVar17 + 0x60);
          uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
          puVar3 = (uint *)(iVar20 + 0x7e);
          uVar14 = (uint)(uVar21 < *puVar3);
          uVar7 = *(int *)(iVar17 + 0x62) - *(int *)(iVar20 + 0x80);
          if (((int)(uVar7 - uVar14) < 0) ||
             ((uVar7 == uVar14 &&
              (uVar21 - *puVar3 <= *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0))))) {
            uStack_a = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x60) -
                       *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x7e);
          }
          else {
            uStack_a = *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa0);
          }
          *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa2) = -uStack_a;
          uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
          puVar3 = (uint *)(iVar17 + 0x56);
          uVar21 = *puVar3;
          *puVar3 = *puVar3 + uStack_a;
          piVar4 = (int *)(iVar17 + 0x58);
          *piVar4 = *piVar4 + (uint)CARRY2(uVar21,uStack_a);
          uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
          uVar22 = *(undefined2 *)(iVar17 + 0x7e);
          uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar20 + 0x62) = *(undefined2 *)(iVar17 + 0x80);
          *(undefined2 *)(iVar20 + 0x60) = uVar22;
        }
        if ((*(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x5b) <
             *(uint *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d)) &&
           ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3e) * 0x95) & 0x80)
            == 0)) {
          uStack_12 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x4d) -
                      *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x5b);
          uVar21 = 0;
          while ((uVar21 < EntityCount && (uStack_12 != 0))) {
            uVar24 = Entities.seg;
            uVar13 = Entities.ofs;
            if ((*(byte *)(uVar13 + uVar21 * 0x37 + 0x1a) == uStack_16) &&
               ((((*(char *)(uVar13 + uVar21 * 0x37 + 0x18) == '\0' &&
                  (*(int *)(uVar13 + uVar21 * 0x37 + 8) == 0)) &&
                 (*(int *)(uVar13 + uVar21 * 0x37 + 10) == 0)) &&
                (3 < *(byte *)(uVar13 + uVar21 * 0x37 + 0xe))))) {
              if (DebugVerbose != false) {
                printf("kill 2 \r",unaff_DI);
              }
              pcVar2 = (char *)(Entities.ofs + uVar21 * 0x37 + 0xe);
              *pcVar2 = *pcVar2 + -1;
              uStack_12 = uStack_12 - 1;
            }
            uVar21 = uVar21 + 1;
          }
        }
        ovr_OVC25_5b66_1b48(uStack_16);
        _fmemset((void *)CONCAT22(((int *)(uStack_16 * 4))[1],
                                  (void *)(*(int *)(uStack_16 * 4) + 0x6a)),0,6);
        _fmemset((void *)CONCAT22(((int *)(uStack_16 * 4))[1],
                                  (void *)(*(int *)(uStack_16 * 4) + 0x76)),0,6);
        uVar13 = ovr_randBelow(100);
        if ((byte)uVar13 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6c) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 100);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6a) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 100);
        }
        uVar13 = ovr_randBelow(100);
        if ((byte)uVar13 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6e) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x66);
        }
        else {
          piVar4 = (int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6c);
          *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x66);
        }
        piVar4 = (int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x6e);
        *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x68);
        uVar13 = ovr_randBelow(100);
        if ((byte)uVar13 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x78) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x70);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x76) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x70);
        }
        uVar13 = ovr_randBelow(100);
        if ((byte)uVar13 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x7a) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x72);
        }
        else {
          piVar4 = (int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x78);
          *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x72);
        }
        uVar13 = ovr_randBelow(100);
        if ((byte)uVar13 < *(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x7c) =
               *(undefined2 *)((int)*(undefined4 *)(uStack_16 << 2) + 0x74);
        }
        else {
          piVar4 = (int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x7a);
          *piVar4 = *piVar4 + *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x74);
        }
        *(undefined1 *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa7) =
             *(undefined1 *)((int)*(undefined4 *)(uStack_16 << 2) + 0xa6);
        if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3f) != '\0') {
          uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
          iVar17 = *(int *)(iVar20 + 0x58);
          if ((iVar17 < 1) && ((iVar17 != 0 || (*(int *)(iVar20 + 0x56) == 0)))) {
            uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
            *(undefined2 *)(iVar17 + 0x58) = 0;
            *(undefined2 *)(iVar17 + 0x56) = 0x32;
          }
        }
        if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0xaa) != '\0') {
          uStack_4 = (uint)*(byte *)((int)*(undefined4 *)(uStack_16 << 2) + 0xaa);
          for (uVar21 = 0; (int)uVar21 < (int)(uint)DAT_2000_d1e6; uVar21 = uVar21 + 1) {
            uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
            iVar17 = *(int *)(iVar18 + 0x58);
            uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
            iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
            iVar20 = *(int *)(iVar19 + 0x8c);
            if ((iVar20 <= iVar17) &&
               ((iVar17 != iVar20 || (*(uint *)(iVar19 + 0x8a) <= *(uint *)(iVar18 + 0x56)))))
            break;
            if ((*(char *)((int)*(undefined4 *)(uVar21 << 2) + 0x3d) != '\0') &&
               (((0 < *(int *)((int)*(undefined4 *)(uVar21 << 2) + 0x54) &&
                 (*(char *)((int)*(undefined4 *)(uVar21 << 2) + 0x3f) == '\0')) &&
                (uVar21 != uStack_16)))) {
              uStack_2e = (uint)(((long)*(int *)((int)*(undefined4 *)(uVar21 << 2) + 0x54) *
                                  (long)(int)uStack_4 & 0xffffU) / 100);
              iStack_2c = 0;
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
              uVar14 = *(uint *)(iVar17 + 0x8a);
              uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
              puVar3 = (uint *)(iVar20 + 0x56);
              iVar17 = (*(int *)(iVar17 + 0x8c) - *(int *)(iVar20 + 0x58)) -
                       (uint)(uVar14 < *puVar3);
              if ((iVar17 < 1) && ((iVar17 < 0 || (uVar14 - *puVar3 < uStack_2e)))) {
                uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
                iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
                uVar14 = *(uint *)(iVar17 + 0x8a);
                uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
                iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
                puVar3 = (uint *)(iVar20 + 0x56);
                uStack_2e = uVar14 - *puVar3;
                iStack_2c = (*(int *)(iVar17 + 0x8c) - *(int *)(iVar20 + 0x58)) -
                            (uint)(uVar14 < *puVar3);
              }
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uVar21 << 2) >> 0x10);
              iVar20 = (int)*(undefined4 *)(uVar21 << 2);
              iVar17 = *(int *)(iVar20 + 0x58);
              if ((iVar17 <= iStack_2c) &&
                 ((iVar17 < iStack_2c || (*(uint *)(iVar20 + 0x56) < uStack_2e)))) {
                uVar22 = (undefined2)((ulong)*(undefined4 *)(uVar21 << 2) >> 0x10);
                iVar17 = (int)*(undefined4 *)(uVar21 << 2);
                iStack_2c = *(int *)(iVar17 + 0x58);
                uStack_2e = *(uint *)(iVar17 + 0x56);
              }
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
              puVar3 = (uint *)(iVar17 + 0x56);
              uVar14 = *puVar3;
              *puVar3 = *puVar3 + uStack_2e;
              piVar4 = (int *)(iVar17 + 0x58);
              *piVar4 = *piVar4 + iStack_2c + (uint)CARRY2(uVar14,uStack_2e);
              uVar22 = (undefined2)((ulong)*(undefined4 *)(uVar21 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uVar21 << 2);
              puVar3 = (uint *)(iVar17 + 0x56);
              uVar14 = *puVar3;
              *puVar3 = *puVar3 - uStack_2e;
              piVar4 = (int *)(iVar17 + 0x58);
              *piVar4 = (*piVar4 - iStack_2c) - (uint)(uVar14 < uStack_2e);
            }
          }
        }
        iVar17 = *(int *)((int)*(undefined4 *)(uStack_16 << 2) + 0x58);
        if ((iVar17 < 1) && (iVar17 < 0)) {
          uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar17 + 0x58) = 0;
          *(undefined2 *)(iVar17 + 0x56) = 0;
        }
        uVar22 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar18 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar17 = *(int *)(iVar18 + 0x58);
        uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
        iVar19 = (int)*(undefined4 *)(uStack_16 << 2);
        iVar20 = *(int *)(iVar19 + 0x8c);
        if ((iVar20 <= iVar17) &&
           ((iVar20 < iVar17 || (*(uint *)(iVar19 + 0x8a) < *(uint *)(iVar18 + 0x56))))) {
          uVar23 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uStack_16 << 2);
          uVar22 = *(undefined2 *)(iVar17 + 0x8a);
          uVar25 = (undefined2)((ulong)*(undefined4 *)(uStack_16 << 2) >> 0x10);
          iVar20 = (int)*(undefined4 *)(uStack_16 << 2);
          *(undefined2 *)(iVar20 + 0x58) = *(undefined2 *)(iVar17 + 0x8c);
          *(undefined2 *)(iVar20 + 0x56) = uVar22;
        }
      }
    }
    GGameState = 0x40;
    if (DebugVerbose != false) {
      printf("%d \r",0x40);
    }
    for (uVar21 = 0xf8; uVar21 < DAT_2000_ca99; uVar21 = uVar21 + 1) {
      uVar22 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
      iVar17 = (int)DAT_2000_ca95;
      if ((*(uint *)((uint)*(byte *)(iVar17 + uVar21 * 9) * 0x27 + 0x121) & 0x40) != 0) {
        if (*(char *)(iVar17 + uVar21 * 9 + 8) != '\0') {
          pcVar2 = (char *)(iVar17 + uVar21 * 9 + 8);
          *pcVar2 = *pcVar2 + -1;
        }
        uVar22 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
        if (*(char *)((int)DAT_2000_ca95 + uVar21 * 9 + 8) == '\0') {
          uVar8 = *(undefined4 *)((uint)*(byte *)((int)DAT_2000_ca95 + uVar21 * 9 + 2) << 2);
          if (*(char *)((int)uVar8 + 0x3f) == '\0') {
            ovr_play_sfx(81,0);
            uVar22 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
            pcVar16 = (char *)"puppetmaker" + 3;
            pcVar15 = (char *)ovr_OVC23_55fe_3450(*(undefined2 *)
                                                   ((int)DAT_2000_ca95 + uVar21 * 9 + 4),
                                                  *(undefined2 *)
                                                   ((int)DAT_2000_ca95 + uVar21 * 9 + 6));
            pcVar15 = ovr_fmVsprintf((char *)"Mine exhausted at (%d, %d).",pcVar15);
            ovr_say((char *)CONCAT22(pcVar16,pcVar15));
            ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
          }
          OVC22_5087_1674(uVar21,&local_1c);
        }
      }
    }
    GGameState = 0x42;
    if (DebugVerbose != false) {
      printf("%d \r",0x42);
    }
    ovr_driver_2d63_0a67((undefined2)DAT_2000_cb09,(*(uint16_t *)((uint8_t *)&(DAT_2000_cb09) + 2)),0,0,0x93,0x3b,0xfff7);
    for (uStack_16 = 0; uStack_16 < DAT_2410_0881; uStack_16 = uStack_16 + 1) {
      puVar3 = (uint *)((int)DAT_2000_cb09 + *(int *)(uStack_16 * 0x13 + 2) * 0x128 +
                       *(int *)(uStack_16 * 0x13) * 2);
      *puVar3 = *puVar3 | 8;
    }
    if (EntityCount <= DAT_2410_55d6) {
      DAT_2410_55d6 = 0;
      for (uStack_16 = 0; (int)uStack_16 < (int)(uint)DAT_2000_d1e6; uStack_16 = uStack_16 + 1) {
        if (*(char *)((int)*(undefined4 *)(uStack_16 << 2) + 0x3d) != '\0') {
          memcpy((uint8_t *)(*(int *)(uStack_16 * 4) + 0x8e),
                 (uint8_t *)(*(int *)(uStack_16 * 4) + 0x94),3);
        }
      }
    }
    iStack_e = 0;
    bStack_5 = ovr_manage_4d05_1b1d();
    if ((bStack_5 == 0xff) || (DAT_2000_d1e8 == '\0')) {
      iStack_c = 0;
    }
    else if (*(byte *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x86) < 5) {
      iStack_c = 0x28;
    }
    else {
      iStack_c = (uint)*(byte *)((int)*(undefined4 *)((uint)bStack_5 << 2) + 0x86) * 4 + 0x14;
    }
    for (uStack_16 = DAT_2410_55d6; uStack_16 < EntityCount; uStack_16 = uStack_16 + 1) {
      uVar24 = Entities.seg;
      uVar13 = Entities.ofs;
      if (((*(char *)(uVar13 + uStack_16 * 0x37 + 0x18) == '\0') &&
          (*(int *)(uVar13 + uStack_16 * 0x37 + 8) == 0)) &&
         (*(int *)(uVar13 + uStack_16 * 0x37 + 10) == 0)) {
        bStack_6 = *(byte *)(uVar13 + uStack_16 * 0x37 + 0xd);
        uVar6 = *(undefined1 *)((int)(char **)GMenuStrings + (uint)bStack_6 * 0x95 + 0x1f);
        bVar5 = *(byte *)(uVar13 + uStack_16 * 0x37 + 0x1a);
        bVar26 = false;
        bVar10 = false;
        bVar9 = false;
        if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bStack_6 * 0x95) == -1) {
          bVar26 = true;
        }
        else {
          bStack_1b = *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x89);
          if (bStack_1b < 5) {
            iStack_1a = *(int *)(uVar13 + uStack_16 * 0x37 + 2);
            iStack_18 = ovr_OVC23_55fe_3450(*(undefined2 *)(uVar13 + uStack_16 * 0x37));
            pcVar15 = (char *)"puppetmaker" + 3;
            if ((*(uint *)((int)DAT_2000_cb09 + iStack_1a * 0x128 + iStack_18 * 2) & 8) == 0) {
              local_1e = 0x22;
              local_1f = 0x21;
              local_20 = 0x22;
            }
            else {
              uVar22 = ovr_attact_3f0b_0585
                                 (iStack_18,iStack_1a,
                                  CONCAT11((char)((uint)&local_20 >> 8),bStack_1b),&local_20);
              ovr_attact_3f0b_2303(uVar22,pcVar15);
            }
          }
          else {
            local_1e = 0x22;
            local_1f = 0x21;
            local_20 = 0x22;
          }
          uVar13 = ovr_randBelow(100);
          if ((byte)uVar13 < local_1e) {
            bVar26 = true;
          }
          else if ((uVar13 & 0xff) < (uint)local_1f + (uint)local_1e) {
            bVar10 = true;
          }
          else {
            bVar9 = true;
          }
        }
        if ((bVar9) &&
           (cVar11 = ovr_OVC23_55fe_0487(*(undefined2 *)(Entities.ofs + uStack_16 * 0x37),
                                         *(undefined2 *)(Entities.ofs + uStack_16 * 0x37 + 2),uVar6)
           , cVar11 == '\0')) {
          if ((local_1f == 0) && (local_1e == 0)) {
            uVar13 = ovr_randBelow(2);
            if ((uVar13 & 0xff) == 0) {
              bVar26 = true;
            }
            else {
              bVar10 = true;
            }
          }
          else {
            uVar13 = ovr_randBelow((uint)local_1f + (uint)local_1e);
            if ((byte)uVar13 < local_1e) {
              bVar26 = true;
            }
            else {
              bVar10 = true;
            }
          }
        }
        if ((bVar26) && (cVar11 = OVC22_5087_1532(uStack_16), cVar11 == '\0')) {
          bVar10 = true;
        }
        if (bVar10) {
          if ((*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bStack_6 * 0x95) != -1) &&
             (bVar5 != 0xff)) {
            if ((*(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x3f) != '\0') ||
               (*(byte *)(Entities.ofs + uStack_16 * 0x37 + 0xf) <
                *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x53))) {
              iVar17 = Entities.ofs + uStack_16 * 0x37;
              uVar22 = OVC22_5087_18b6(iVar17,Entities.seg,iStack_c);
              uVar27 = LXMUL_at_(3,CONCAT22(iVar17,uVar22));
              iVar17 = Entities.ofs + uStack_16 * 0x37;
              uVar22 = ovr_OVC15_4207_26bc(iVar17,Entities.seg,
                                           (int)(((ulong)((uVar27 & 0x10000) != 0) << 0x10 |
                                                 uVar27 & 0xffff) >> 1),(int)((long)uVar27 >> 0x11))
              ;
              uVar14 = OVC22_5087_1d4a(uVar22,iVar17);
              uVar13 = Entities.seg;
              iVar20 = Entities.ofs + uStack_16 * 0x37;
              uVar21 = *(uint *)(iVar20 + 0x10);
              iVar18 = Entities.ofs + uStack_16 * 0x37;
              *(int *)(iVar18 + 0x12) =
                   *(int *)(iVar20 + 0x12) + iVar17 + (uint)CARRY2(uVar21,uVar14);
              *(int *)(iVar18 + 0x10) = uVar21 + uVar14;
              ovr_OVC41_6a8f_002e(Entities.ofs + uStack_16 * 0x37,Entities.seg);
            }
          }
          OVC22_5087_1991(uStack_16);
          OVC22_5087_1ac1(uStack_16);
          OVC22_5087_1ca4(uStack_16);
        }
        iStack_2a = (uint)*(byte *)(Entities.ofs + uStack_16 * 0x37 + 0xe) -
                    (uint)*(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0xa4);
        if (0 < iStack_2a) {
          if (3 < iStack_2a) {
            iStack_2a = 3;
          }
          if (iStack_2a == 3) {
            if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x92) == 0) {
              iStack_2a = 2;
            }
            else {
              piVar4 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x92);
              *piVar4 = *piVar4 + -1;
            }
          }
          if (iStack_2a == 2) {
            if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x90) == 0) {
              iStack_2a = 1;
            }
            else {
              piVar4 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x90);
              *piVar4 = *piVar4 + -1;
            }
          }
          if (iStack_2a == 1) {
            if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x8e) == 0) {
              iStack_2a = 0;
            }
            else {
              piVar4 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x8e);
              *piVar4 = *piVar4 + -1;
            }
          }
          *(char *)(Entities.ofs + uStack_16 * 0x37 + 0xe) =
               *(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0xa4) + (char)iStack_2a;
        }
        iStack_e = iStack_e + 1;
        if (199 < iStack_e) break;
      }
    }
    DAT_2410_55d6 = uStack_16;
    DAT_2410_648e = 1;
    ovr_unit_6616_00d8();
    GGameState = 0x44;
    if (DebugVerbose != false) {
      printf("%d \r",0x44);
    }
    uVar21 = EntityCount;
    if (cStack_1d != '\0') {
      while (uStack_16 = uVar21 - 1, -1 < (int)uStack_16) {
        uVar24 = Entities.seg;
        uVar13 = Entities.ofs;
        uVar21 = uStack_16;
        if (*(char *)(uVar13 + uStack_16 * 0x37 + 0xe) == '\0') {
          if (*(char *)((int)(char **)GMenuStrings +
                       (uint)*(byte *)(uVar13 + uStack_16 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0') {
            dst = 0xa000;
            ovr_OVC23_55fe_3450(*(undefined2 *)(uVar13 + uStack_16 * 0x37),
                                *(undefined2 *)(uVar13 + uStack_16 * 0x37 + 2));
            uVar22 = 0x195d;
            pcVar15 = ovr_fmVsprintf((char *)
                                     "Intelligence reports %s unit died of starvation. (%d, %d)",
                                     (char *)*(undefined2 *)
                                              ((int)&far_t_ARRAY_2410_26f7[0].seg + 1 +
                                              (uint)*(byte *)(Entities.ofs + uStack_16 * 0x37 + 0xd)
                                              * 0x95));
            ovr_uiNotify((char *)CONCAT22(uVar22,pcVar15),dst);
          }
          ovr_OVC15_4207_0e17(uStack_16);
          uVar21 = uStack_16;
        }
      }
    }
    if (local_1c != '\0') {
      ovr_constr_36ce_1db4();
    }
  }
  return;
}



/* 5087:3a6b */

char * __cdecl16far OVC22_5087_3a6b(uint param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  
  cVar2 = OVC22_5087_0000(param_1,param_2);
  if (cVar2 == '\0') {
    pcVar3 = (char *)0x0;
  }
  else {
    uVar9 = (undefined2)((ulong)DAT_2000_cb0d >> 0x10);
    iVar7 = (int)DAT_2000_cb0d;
    iVar4 = *(int *)(iVar7 + param_1 * 0x78 + param_2 * 2) * 9;
    uVar10 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
    iVar8 = (int)DAT_2000_ca95;
    bVar1 = *(byte *)(iVar8 + iVar4);
    uVar5 = CONCAT11((char)((uint)iVar4 >> 8),bVar1);
    if ((bVar1 == 0) || (uVar5 = (uint)bVar1 * 0x27, (*(uint *)(uVar5 + 0x121) & 0x1000) != 0)) {
      if ((int)param_1 < 4) {
        pcVar3 = (char *)(uVar5 & 0xff00);
      }
      else {
        uVar5 = (uint)*(byte *)(iVar8 + *(int *)(param_1 * 0x78 + iVar7 + param_2 * 2 + -0x78) * 9)
                * 0x27;
        if (*(byte *)(uVar5 + 0x11b) < 2) {
          uVar5 = (uint)*(byte *)(iVar8 + *(int *)(param_1 * 0x78 + iVar7 + param_2 * 2 + -0xf0) * 9
                                 ) * 0x27;
          if (*(byte *)(uVar5 + 0x11b) < 3) {
            uVar5 = (uint)*(byte *)(iVar8 + *(int *)(param_1 * 0x78 + iVar7 + param_2 * 2 + -0x168)
                                            * 9) * 0x27;
            if (*(byte *)(uVar5 + 0x11b) < 4) {
              for (uVar5 = 0; uVar5 < DAT_2000_d2df; uVar5 = uVar5 + 1) {
                if (((*(int *)(uVar5 * 0x12 + 4) == param_2) &&
                    (*(uint *)(uVar5 * 0x12 + 2) <= param_1)) &&
                   (uVar6 = *(int *)(uVar5 * 0x12 + 2) +
                            (uint)*(byte *)((uint)*(byte *)(uVar5 * 0x12 + 8) * 0x27 + 0x11b),
                   param_1 < uVar6)) {
                  return (char *)(uVar6 & 0xff00);
                }
              }
              pcVar3 = (char *)"arena" + 5;
            }
            else {
              pcVar3 = (char *)(uVar5 & 0xff00);
            }
          }
          else {
            pcVar3 = (char *)(uVar5 & 0xff00);
          }
        }
        else {
          pcVar3 = (char *)(uVar5 & 0xff00);
        }
      }
    }
    else {
      pcVar3 = (char *)(uVar5 & 0xff00);
    }
  }
  return pcVar3;
}



/* 5087:3c93 */

undefined2 __cdecl16far OVC22_5087_3c93(int param_1,int param_2,char param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (*(char *)((int)DAT_2000_ca95 + *(int *)((int)DAT_2000_cb0d + param_1 * 0x78 + param_2 * 2) * 9
               + 2) == param_3) {
    iVar1 = ovr_OVC23_55fe_3450(param_1);
    uVar3 = 0;
    for (iVar2 = -2; iVar2 < 2; iVar2 = iVar2 + 1) {
      uVar3 = uVar3 | *(uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + (iVar1 + iVar2) * 2);
    }
    if ((param_4 & uVar3) == 0) {
      return 1;
    }
  }
  return 0;
}



/* 5087:3d25 */

uint __cdecl16far OVC22_5087_3d25(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)((int)DAT_2000_cb0d + param_1 * 0x78 + param_2 * 2);
  if (uVar1 < 0xf8) {
    iVar2 = ovr_OVC23_55fe_2937(param_1,param_2);
    if (iVar2 == -1) {
      uVar1 = (uint)*(byte *)((int)DAT_2000_ca95 + uVar1 * 9);
      if (((*(uint *)(uVar1 * 0x27 + 0x121) & 2) == 0) &&
         ((*(uint *)(uVar1 * 0x27 + 0x121) & 0x20) == 0)) {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 5087:3dc7 */

uint __cdecl16far OVC22_5087_3dc7(int param_1,int param_2,byte param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((*(byte *)((int)*(undefined4 *)((uint)param_3 << 2) + 0x5d) & 4) == 0) {
    uVar1 = *(uint *)((int)DAT_2000_cb0d + param_1 * 0x78 + param_2 * 2);
    if (uVar1 < 0xf8) {
      iVar2 = ovr_OVC23_55fe_2937(param_1,param_2);
      if (iVar2 == -1) {
        uVar1 = (uint)*(byte *)((int)DAT_2000_ca95 + uVar1 * 9);
        if ((*(uint *)(uVar1 * 0x27 + 0x121) & 0x20) == 0) {
          uVar1 = 0;
        }
        else if (*(char *)(uVar1 * 0x27 + 0x131) == '\0') {
          if (*(char *)((int)*(undefined4 *)((uint)param_3 << 2) + 0x2f) == '\x05') {
            uVar1 = uVar1 + 0x18;
          }
          else {
            uVar1 = uVar1 + 6;
          }
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 5087:3eb1 */

uint __cdecl16far OVC22_5087_3eb1(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)((int)DAT_2000_cb0d + param_1 * 0x78 + param_2 * 2);
  if (uVar1 < 0xf8) {
    iVar2 = ovr_OVC23_55fe_2937(param_1,param_2);
    if (iVar2 == -1) {
      uVar1 = (uint)*(byte *)((int)DAT_2000_ca95 + uVar1 * 9);
      if ((*(uint *)(uVar1 * 0x27 + 0x121) & 0x20) == 0) {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 5087:3f3b */

undefined2 __cdecl16far OVC22_5087_3f3b(int param_1,int param_2,uint param_3)

{
  char cVar1;
  undefined2 uVar2;
  
  cVar1 = OVC22_5087_0000(param_1,param_2);
  if (cVar1 == '\0') {
    uVar2 = 0;
  }
  else if ((*(uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2) & param_3) == 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 5087:3f8d */

undefined2 __cdecl16far
OVC22_5087_3f8d(char param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined2 uVar1;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  char cStack_3;
  
  if (param_1 == '\0') {
    iStack_6 = ovr_OVC07_32c9_0026(param_4 - param_2);
    iStack_8 = ovr_OVC07_32c9_0026(param_5 - param_3);
    if ((iStack_6 != 0) || (iStack_8 != 0)) {
      cStack_3 = '\0';
      while( true ) {
        iStack_a = iStack_6;
        iStack_c = iStack_8;
        uVar1 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
        if ((iStack_6 != 0) &&
           ((*(uint *)((int)DAT_2000_cb09 + param_3 * 0x128 + (param_2 + iStack_6) * 2) & 3) != 0))
        {
          iStack_a = 0;
        }
        if ((iStack_8 != 0) &&
           ((*(uint *)((int)DAT_2000_cb09 + (param_3 + iStack_8) * 0x128 + param_2 * 2) & 3) != 0))
        {
          iStack_c = 0;
        }
        if ((iStack_a == 0) && (iStack_c == 0)) break;
        if ((iStack_c == 0) || ((iStack_a != 0 && (cStack_3 != '\0')))) {
          param_2 = param_2 + iStack_a;
          if (param_2 == param_4) {
            if (param_3 == param_5) {
              return 1;
            }
            iStack_6 = 0;
          }
        }
        else {
          param_3 = param_3 + iStack_c;
          if (param_3 == param_5) {
            if (param_2 == param_4) {
              return 1;
            }
            iStack_8 = 0;
          }
        }
        cStack_3 = '\x01' - (cStack_3 != '\0');
      }
      return 0;
    }
  }
  return 1;
}



/* 5087:40ad */

uint __cdecl16far OVC22_5087_40ad(int *param_1,int *param_2,char param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uStack_4;
  
  uStack_4 = 0;
  do {
    if (DAT_2000_d2df <= uStack_4) {
      return DAT_2000_d2df & 0xff00;
    }
    if (*(char *)(uStack_4 * 0x12 + 9) == param_3) {
      iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(uStack_4 * 0x12 + 2));
      iVar1 = *(int *)(uStack_4 * 0x12 + 4);
      uVar4 = 0;
      for (iVar3 = -2; iVar3 < 2; iVar3 = iVar3 + 1) {
        uVar4 = uVar4 | *(uint *)((int)DAT_2000_cb09 + iVar1 * 0x128 + (iVar2 + iVar3) * 2);
      }
      if ((param_4 & uVar4) == 0) {
        *param_1 = iVar2;
        *param_2 = iVar1;
        return CONCAT11((char)((uint)iVar1 >> 8),1);
      }
    }
    uStack_4 = uStack_4 + 1;
  } while( true );
}



/* 5087:416e */

undefined2 __cdecl16far
OVC22_5087_416e(uint *param_1,uint *param_2,byte param_3,byte param_4,char param_5)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  char cStack_8;
  char cStack_7;
  int iStack_6;
  int iStack_4;
  
  uVar3 = *param_1;
  uVar4 = *param_2;
  bVar2 = *(byte *)((int)*(undefined4 *)((uint)param_3 << 2) + 0x3f);
  iVar6 = 0x1000 << (bVar2 & 0x1f);
  cVar5 = OVC22_5087_3c93(*param_1,*param_2,CONCAT11((char)((uint)iVar6 >> 8),param_3),iVar6);
  if (cVar5 == '\0') {
    cVar5 = OVC22_5087_40ad((uint *)param_1,(*(uint16_t *)((uint8_t *)&(param_1) + 2)),(uint *)param_2,(*(uint16_t *)((uint8_t *)&(param_2) + 2)),param_3,
                            iVar6);
    if (cVar5 == '\0') {
      for (iStack_4 = 1; iStack_4 < 0x94; iStack_4 = iStack_4 + 1) {
        for (iStack_6 = 0; iStack_6 <= iStack_4; iStack_6 = iStack_6 + 1) {
          for (cStack_7 = -1; cStack_7 < '\x02'; cStack_7 = cStack_7 + '\x02') {
            for (cStack_8 = -1; cStack_8 < '\x02'; cStack_8 = cStack_8 + '\x02') {
              *param_1 = uVar3 + cStack_7 * iStack_6;
              if (cStack_7 < '\0') {
                *param_1 = *param_1 - 1;
              }
              *param_2 = uVar4 + cStack_8 * iStack_4;
              if ((((3 < *param_1) && (*param_1 < 0x90)) && (*param_2 != 0)) && (*param_2 < 0x3b)) {
                cVar5 = OVC22_5087_3c93(*param_1,*param_2,
                                        CONCAT11((char)((uint)(cStack_8 * iStack_4) >> 8),param_3),
                                        iVar6);
                if (cVar5 != '\0') {
                  return 0;
                }
                if ((bVar2 != 0) && (iVar7 = OVC22_5087_3d25(*param_1,*param_2), iVar7 != 0)) {
                  return 1;
                }
                if (((param_4 == 3) &&
                    (cVar5 = OVC22_5087_3f3b(*param_1,*param_2,iVar6), cVar5 != '\0')) &&
                   (cVar5 = OVC22_5087_3f8d(bVar2,uVar3,uVar4,*param_1,*param_2), cVar5 != '\0')) {
                  return 0;
                }
                if (((((param_4 & 1) == 0) && (param_5 == '\0')) &&
                    (cVar5 = OVC22_5087_3a6b(*param_1,*param_2), cVar5 != '\0')) &&
                   (cVar5 = OVC22_5087_3f8d(bVar2,uVar3,uVar4,*param_1,*param_2), cVar5 != '\0')) {
                  return 1;
                }
                if ((((param_4 & 2) == 0) &&
                    (iVar7 = OVC22_5087_3dc7(*param_1,*param_2,param_3), iVar7 != 0)) &&
                   (cVar5 = OVC22_5087_3f8d(bVar2,uVar3,uVar4,*param_1,*param_2), cVar5 != '\0')) {
                  return 1;
                }
              }
              *param_1 = uVar3 + cStack_7 * iStack_4;
              if (cStack_7 < '\0') {
                *param_1 = *param_1 - 1;
              }
              *param_2 = uVar4 + cStack_8 * iStack_6;
              if (((3 < *param_1) && (*param_1 < 0x90)) && ((*param_2 != 0 && (*param_2 < 0x3b)))) {
                cVar5 = OVC22_5087_3c93(*param_1,*param_2,
                                        CONCAT11((char)((uint)(cStack_8 * iStack_6) >> 8),param_3),
                                        iVar6);
                if (cVar5 != '\0') {
                  return 0;
                }
                if ((bVar2 != 0) && (iVar7 = OVC22_5087_3d25(*param_1,*param_2), iVar7 != 0)) {
                  return 1;
                }
                if ((((param_4 & 3) == 3) &&
                    (cVar5 = OVC22_5087_3f3b(*param_1,*param_2,iVar6), cVar5 != '\0')) &&
                   (cVar5 = OVC22_5087_3f8d(bVar2,uVar3,uVar4,*param_1,*param_2), cVar5 != '\0')) {
                  return 0;
                }
                if ((((param_4 & 1) == 0) && (param_5 == '\0')) &&
                   ((cVar5 = OVC22_5087_3a6b(*param_1,*param_2), cVar5 != '\0' &&
                    (cVar5 = OVC22_5087_3f8d(bVar2,uVar3,uVar4,*param_1,*param_2), cVar5 != '\0'))))
                {
                  return 1;
                }
                if ((((param_4 & 2) == 0) &&
                    (iVar7 = OVC22_5087_3dc7(*param_1,*param_2,param_3), iVar7 != 0)) &&
                   (cVar5 = OVC22_5087_3f8d(bVar2,uVar3,uVar4,*param_1,*param_2), cVar5 != '\0')) {
                  return 1;
                }
              }
            }
          }
        }
      }
      if ((param_4 & 1) == 0) {
        pbVar1 = (byte *)((int)*(undefined4 *)((uint)param_3 << 2) + 0x5d);
        *pbVar1 = *pbVar1 | 2;
      }
      *param_1 = uVar3;
      *param_2 = uVar4;
    }
  }
  return 0;
}



/* 5087:4576 */

uint __cdecl16far OVC22_5087_4576(byte param_1,undefined2 param_2,undefined2 param_3)

{
  undefined4 uVar1;
  undefined1 uVar2;
  byte bVar3;
  uint uVar4;
  uint16_t uVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  
  if (((*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5d) & 2) == 0) ||
     ((*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5d) & 4) == 0)) {
    uVar1 = *(undefined4 *)((uint)param_1 << 2);
    if (*(char *)((int)uVar1 + 0x3f) == '\0') {
      uVar4 = OVC22_5087_3dc7(param_2,param_3,CONCAT11((char)(((uint)param_1 << 2) >> 8),param_1));
      if ((*(uint *)(uVar4 * 0x27 + 0x121) & 0x20) == 0) {
        if ((*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5d) & 2) == 0) {
          uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
          iVar6 = (int)*(undefined4 *)((uint)param_1 << 2);
          if (*(int *)(iVar6 + 0x56) == 0 && *(int *)(iVar6 + 0x58) == 0) {
            uVar4 = 0;
          }
          else {
            uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
            iVar6 = (int)*(undefined4 *)((uint)param_1 << 2);
            uVar4 = *(int *)(iVar6 + 0x4d) * 2 + *(int *)(iVar6 + 0x4d);
            if (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4f) < uVar4 >> 2) {
              uVar4 = 0;
            }
            else {
              uVar2 = ovr_bldng_676c_0000(CONCAT11((byte)(uVar4 >> 10),param_1));
              bVar3 = ovr_bldng_676c_05c3(uVar2);
              uVar4 = (uint)bVar3;
              uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
              iVar7 = (int)*(undefined4 *)((uint)param_1 << 2);
              iVar6 = *(int *)(iVar7 + 0x58);
              if ((iVar6 < 0) ||
                 ((iVar6 == 0 && (*(uint *)(iVar7 + 0x56) < *(uint *)(uVar4 * 0x27 + 0x125))))) {
                uVar4 = 0;
              }
            }
          }
        }
        else {
          uVar4 = 0;
        }
      }
    }
    else {
      uVar4 = OVC22_5087_3d25(param_2,param_3);
      if ((*(uint *)(uVar4 * 0x27 + 0x121) & 2) == 0) {
        uVar5 = ovr_randBelow(2);
        if (((uVar5 & 0xff) == 0) && ((*(uint *)(uVar4 * 0x27 + 0x121) & 0x20) != 0)) {
          if (*(char *)(uVar4 * 0x27 + 0x131) == '\0') {
            uVar4 = uVar4 + 6;
          }
        }
        else {
          uVar5 = ovr_randBelow(8);
          if (((uVar5 & 0xff) == 0) ||
             ((uVar5 = ovr_randBelow(3), (uVar5 & 0xff) == 0 &&
              (*(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4f) <
               *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d))))) {
            uVar5 = ovr_randBelow(3);
            uVar4 = (uVar5 & 0xff) + 1;
          }
          else {
            uVar5 = ovr_randBelow(0xc);
            if ((uVar5 & 0xff) == 0) {
              uVar5 = ovr_randBelow(3);
              uVar4 = (uVar5 & 0xff) + 0x2b;
              uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
              iVar7 = (int)*(undefined4 *)((uint)param_1 << 2);
              iVar6 = *(int *)(iVar7 + 0x58);
              if (-1 < iVar6) {
                if (iVar6 != 0) {
                  return uVar4;
                }
                if (*(uint *)(uVar4 * 0x27 + 0x125) <= *(uint *)(iVar7 + 0x56)) {
                  return uVar4;
                }
              }
            }
            uVar5 = ovr_randBelow(0xc);
            if ((uVar5 & 0xff) == 0) {
              uVar5 = ovr_randBelow(3);
              uVar4 = (uVar5 & 0xff) + 0xec;
              uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
              iVar7 = (int)*(undefined4 *)((uint)param_1 << 2);
              iVar6 = *(int *)(iVar7 + 0x58);
              if (-1 < iVar6) {
                if (iVar6 != 0) {
                  return uVar4;
                }
                if (*(uint *)(uVar4 * 0x27 + 0x125) <= *(uint *)(iVar7 + 0x56)) {
                  return uVar4;
                }
              }
            }
            bVar3 = *(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3e);
            uVar5 = ovr_randBelow(3);
            uVar4 = (uVar5 & 0xff) +
                    (uint)*(byte *)((int)&far_t_ARRAY_2410_26f7[0xb].ofs + 1 + (uint)bVar3 * 0x95);
            uVar8 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
            iVar7 = (int)*(undefined4 *)((uint)param_1 << 2);
            iVar6 = *(int *)(iVar7 + 0x58);
            if ((iVar6 < 0) ||
               ((iVar6 == 0 && (*(uint *)(iVar7 + 0x56) < *(uint *)(uVar4 * 0x27 + 0x125))))) {
              uVar4 = (uint)*(byte *)((int)&far_t_ARRAY_2410_26f7[0xb].ofs + 1 + (uint)bVar3 * 0x95)
              ;
            }
          }
        }
      }
      else {
        uVar5 = ovr_randBelow(0x14);
        if ((uVar5 & 0xff) == 0) {
          uVar4 = 0x72;
        }
        else {
          uVar5 = ovr_randBelow(4);
          if ((uVar5 & 0xff) == 0) {
            uVar4 = 0x71;
          }
          else {
            uVar4 = 0x70;
          }
        }
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}



/* 5087:4975 */

void __cdecl16far OVC22_5087_4975(byte param_1,undefined2 param_2,undefined2 param_3)

{
  uint *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  char cVar6;
  uint16_t uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined1 uVar10;
  int iVar11;
  int iVar12;
  undefined2 uVar13;
  undefined1 uStack_e;
  undefined2 local_c;
  undefined2 local_a;
  byte bStack_8;
  undefined1 uStack_7;
  char cStack_6;
  char cStack_5;
  undefined1 uStack_4;
  byte bStack_3;
  
  bStack_8 = DAT_2000_d3c6;
  if (*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0xa8) != '\0') {
    uVar7 = ovr_randBelow(100);
    uStack_7 = (undefined1)uVar7;
    if ((uVar7 & 0xff) <
        ((uint)*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0xa8) * 100) /
        (*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0xa8) + 1)) {
      uVar7 = ovr_randBelow((uint)*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0xa8));
      cStack_5 = (char)uVar7;
      cStack_6 = '\0';
      for (bStack_8 = 0; bStack_8 < DAT_2000_d3c6; bStack_8 = bStack_8 + 1) {
        uVar13 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
        if ((*(char *)((uint)*(byte *)((int)DAT_2000_ca95 +
                                      *(int *)((uint)bStack_8 * 2 + -0x6d44) * 9) * 0x27 + 0x133) ==
             '\x12') &&
           (*(byte *)((int)DAT_2000_ca95 + *(int *)((uint)bStack_8 * 2 + -0x6d44) * 9 + 2) ==
            param_1)) {
          if (cStack_6 == cStack_5) break;
          cStack_6 = cStack_6 + '\x01';
        }
      }
    }
  }
  if (bStack_8 < DAT_2000_d3c6) {
    uVar13 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
    local_a = *(undefined2 *)((int)DAT_2000_ca95 + *(int *)((uint)bStack_8 * 2 + -0x6d44) * 9 + 4);
    local_c = *(undefined2 *)((int)DAT_2000_ca95 + *(int *)((uint)bStack_8 * 2 + -0x6d44) * 9 + 6);
  }
  else {
    local_a = *(undefined2 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x39);
    local_c = *(undefined2 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3b);
  }
  uVar13 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
  iVar11 = (int)*(undefined4 *)((uint)param_1 << 2);
  iVar8 = *(int *)(iVar11 + 0x58);
  if ((iVar8 < 1) && ((iVar8 < 0 || (*(uint *)(iVar11 + 0x56) < 10)))) {
    uStack_4 = 1;
  }
  else {
    uStack_4 = 0;
  }
  if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[6].seg + 1 +
                (uint)*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3e) * 0x95) & 0x80) ==
      0) {
    bStack_3 = 0;
  }
  else {
    bStack_3 = 3;
  }
  if ((*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5d) & 2) != 0) {
    bStack_3 = bStack_3 | 1;
  }
  if ((*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5d) & 4) != 0) {
    bStack_3 = bStack_3 | 2;
  }
  cVar6 = OVC22_5087_416e(&local_a);
  if (cVar6 != '\0') {
    if (cVar6 != '\x01') {
      return;
    }
    iVar8 = OVC22_5087_4576(param_1,local_a,local_c);
    if (iVar8 == 0) {
      local_a = *(undefined2 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x39);
      local_c = *(undefined2 *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3b);
    }
    else {
      puVar9 = (undefined4 *)(iVar8 * 0x27);
      if ((*(uint *)((int)puVar9 + 0x121) & 0x60) == 0) {
        uVar13 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
        iVar12 = (int)*(undefined4 *)((uint)param_1 << 2);
        iVar11 = *(int *)(iVar12 + 0x58);
        if ((iVar11 < 0) ||
           ((iVar11 == 0 && (*(uint *)(iVar12 + 0x56) < *(uint *)(iVar8 * 0x27 + 0x125))))) {
          puVar9 = (undefined4 *)((uint)param_1 << 2);
          uVar13 = (undefined2)((ulong)*puVar9 >> 0x10);
          iVar11 = (int)*puVar9;
          *(undefined2 *)(iVar11 + 0x58) = 0;
          *(undefined2 *)(iVar11 + 0x56) = 0;
        }
        else {
          puVar9 = (undefined4 *)*(uint *)(iVar8 * 0x27 + 0x125);
          uVar13 = (undefined2)((ulong)*(undefined4 *)((uint)param_1 << 2) >> 0x10);
          iVar11 = (int)*(undefined4 *)((uint)param_1 << 2);
          puVar1 = (uint *)(iVar11 + 0x56);
          puVar3 = (undefined4 *)*puVar1;
          *puVar1 = *puVar1 - (int)puVar9;
          piVar2 = (int *)(iVar11 + 0x58);
          *piVar2 = *piVar2 - (uint)(puVar3 < puVar9);
        }
      }
      uVar10 = (undefined1)((uint)puVar9 >> 8);
      uStack_e = (undefined1)iVar8;
      ovr_OVC23_55fe_1e87(CONCAT11(uVar10,uStack_e),local_a,local_c,param_2,param_3,
                          CONCAT11(uVar10,param_1));
    }
  }
  uVar5 = *(undefined4 *)((uint)param_1 << 2);
  if (*(char *)((int)uVar5 + 0x3f) == '\0') {
    uVar4 = *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x5b);
    uVar10 = (undefined1)(uVar4 >> 8);
    if (uVar4 < *(uint *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x4d)) {
      ovr_OVC18_48ac_0382(CONCAT11(uVar10,param_1),local_a,local_c,1);
    }
    else {
      ovr_OVC18_48ac_0382(CONCAT11(uVar10,param_1),local_a,local_c,0);
    }
  }
  else {
    ovr_OVC18_48ac_0382(CONCAT11((char)(((uint)param_1 << 2) >> 8),param_1),0,0,0);
  }
  return;
}



/* 5087:4dd9 */

void __cdecl16far OVC22_5087_4dd9(void)

{
  uint16_t uVar1;
  char local_5;
  int iStack_4;
  
  local_5 = '\0';
  for (iStack_4 = 0; iStack_4 < (int)(uint)DAT_2000_d1e6; iStack_4 = iStack_4 + 1) {
    if (((*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3d) != '\0') &&
        (uVar1 = ovr_randBelow((uint)(byte)((char *)"Decrease message delay" + 5)
                                           [(uint)*(byte *)((int)*(undefined4 *)(iStack_4 << 2) +
                                                           0x3e) * 0x95]),
        (byte)uVar1 < *(byte *)((int)*(undefined4 *)(iStack_4 << 2) + 0x2e))) &&
       ((*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3f) != '\0' ||
        (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x4d) <=
         *(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x5b))))) {
      if (EntityCount < 0x21c) {
        OVC22_5087_4975(CONCAT11((char)((uint)&local_5 >> 8),(undefined1)iStack_4),&local_5);
      }
      else if (*(char *)((int)*(undefined4 *)(iStack_4 << 2) + 0x3f) == '\0') {
        if (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x45) < 0x23) {
          OVC22_5087_4975(CONCAT11((char)((uint)&local_5 >> 8),(undefined1)iStack_4),&local_5);
        }
        else if (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x45) < 0x4b) {
          uVar1 = ovr_randBelow(8);
          if ((uVar1 & 0xff) == 0) {
            OVC22_5087_4975(CONCAT11((char)((uint)&local_5 >> 8),(undefined1)iStack_4),&local_5);
          }
        }
        else {
          uVar1 = ovr_randBelow(0x10);
          if ((uVar1 & 0xff) == 0) {
            OVC22_5087_4975(CONCAT11((char)((uint)&local_5 >> 8),(undefined1)iStack_4),&local_5);
          }
        }
      }
      else if (*(int *)((int)*(undefined4 *)(iStack_4 << 2) + 0x47) == 0) {
        OVC22_5087_4975(CONCAT11((char)((uint)&local_5 >> 8),(undefined1)iStack_4),&local_5);
      }
      else if (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x45) < 0x19) {
        OVC22_5087_4975(CONCAT11((char)((uint)&local_5 >> 8),(undefined1)iStack_4),&local_5);
      }
      else if (*(uint *)((int)*(undefined4 *)(iStack_4 << 2) + 0x45) < 0x32) {
        uVar1 = ovr_randBelow(8);
        if ((uVar1 & 0xff) == 0) {
          OVC22_5087_4975(CONCAT11((char)((uint)&local_5 >> 8),(undefined1)iStack_4),&local_5);
        }
      }
      else {
        uVar1 = ovr_randBelow(0x10);
        if ((uVar1 & 0xff) == 0) {
          OVC22_5087_4975(CONCAT11((char)((uint)&local_5 >> 8),(undefined1)iStack_4),&local_5);
        }
      }
    }
  }
  if (local_5 == '\0') {
    ovr_constr_36ce_03a6();
  }
  else {
    ovr_constr_36ce_1db4();
  }
  return;
}



/* 5087:503d */

undefined2 __cdecl16far OVC22_5087_503d(byte param_1,byte param_2)

{
  undefined2 uVar1;
  
  if (GOngoingBattle == '\0') {
    if (((int)(uint)param_2 < GfxRndSeed2 + -4) || (GfxRndSeed2 < (int)(uint)param_2)) {
      return 0;
    }
  }
  else if (((int)(uint)param_2 < GfxRndSeed2 + -2) || (GfxRndSeed2 < (int)(uint)param_2)) {
    return 0;
  }
  if (((int)(uint)param_1 < GfxRndSeed + *(int *)((GfxRndSeed2 - (uint)param_2) * 2 + -0x73ed)) ||
     (GfxRndSeed + *(int *)((GfxRndSeed2 - (uint)param_2) * 2 + -0x73ff) < (int)(uint)param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 5087:510e */

undefined2 __cdecl16far OVC22_5087_510e(byte param_1,byte param_2)

{
  undefined2 uVar1;
  
  if (GOngoingBattle == '\0') {
    if (((int)(uint)param_2 < GfxRndSeed2 + -2) || (GfxRndSeed2 < (int)(uint)param_2)) {
      return 0;
    }
  }
  else if (((int)(uint)param_2 < GfxRndSeed2 + -1) || (GfxRndSeed2 < (int)(uint)param_2)) {
    return 0;
  }
  if (((int)(uint)param_1 < GfxRndSeed + *(int *)((GfxRndSeed2 - (uint)param_2) * 2 + -0x73ed)) ||
     (GfxRndSeed + *(int *)((GfxRndSeed2 - (uint)param_2) * 2 + -0x73ff) < (int)(uint)param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


