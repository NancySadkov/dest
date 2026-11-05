/*
 * ovc16_saveui.c - recovered from STRONG.EXE
 * memory block: OVC16_saveui.c
 * range: 4528:0000 - 4528:221f
 * functions: 22
 */
#include "recovered.h"


/* 4528:0000 */

uint16_t __cdecl16far uiReadKey2(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint16_t uVar4;
  int iVar5;
  int iStack_8;
  int iStack_6;
  
  MiceUnkState = 0;
  ovr_init2_3338_0401();
  MiceProcessed = 0;
  ovr_miceBlitRect(BlitRects + 1);
  iVar3 = DAT_2410_00e6;
  iVar2 = DAT_2410_00e4;
  bVar1 = false;
  DAT_2410_00e8 = 0;
  while( true ) {
    if ((*(int *)(BDA_DailyTimeCounter.ofs + 2) != iStack_6) ||
       (*(int *)BDA_DailyTimeCounter != iStack_8)) {
      iStack_6 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
      iStack_8 = *(int *)BDA_DailyTimeCounter;
      ovr_draw_2e25_046b();
      ovr_OVC13_3d16_005b();
    }
    uVar4 = ovr_biosKeyAvail();
    if ((char)uVar4 != '\0') break;
    iVar5 = ovr_init2_3338_0388(0xe4,(char *)"puppetmaker" + 3,0xe6);
    if (iVar5 == 0) {
      bVar1 = true;
    }
    else if (((bVar1) || (DAT_2410_00e4 != iVar2)) || (DAT_2410_00e6 != iVar3)) {
      if (!bVar1) {
        DAT_2410_00e8 = 1;
      }
      ovr_miceRestoreArea(BlitRects + 1);
      DAT_2410_00ea = *(undefined1 *)(DAT_2410_00e6 * 0x140 + DAT_2410_00e4);
      ovr_draw_2e25_0573();
      ovr_font_302d_0a30();
      return 0xffff;
    }
    if (DAT_2000_ccaf != '\0') {
      ovr_miceRestoreArea(BlitRects + 1);
      DAT_2410_00ea = *(undefined1 *)(DAT_2410_00e6 * 0x140 + DAT_2410_00e4);
      ovr_draw_2e25_0573();
      ovr_font_302d_0a30();
      return 0xfffe;
    }
  }
  ovr_miceRestoreArea(BlitRects + 1);
  ovr_draw_2e25_0573();
  ovr_font_302d_0a30();
  uVar4 = ovr_gameProcessKey();
  return uVar4;
}



/* 4528:01b2 */

void __cdecl16far saveui_4528_01b2(void)

{
  uint16_t unk;
  far_t gfx;
  far_t handle;
  far_t dst;
  
  CrossBlitFlag = 0;
  CrossBlitCount2 = 0;
  CrossBlitCount = 1;
  if (GMenuItem == 0) {
    CrossBlitX = 3;
    CrossBlitY = 0xb0;
  }
  else {
    CrossBlitX = 0x16;
    CrossBlitY = (uint)GMenuItem * 0xf + 0xb;
  }
  if (CrossBlitPtr.ofs != 0 || CrossBlitPtr.seg != 0) {
    handle.seg = CrossBlitPtr.seg;
    handle.ofs = CrossBlitPtr.ofs;
    ovr_stshFree(handle);
  }
  CrossBlitPtr = ovr_stshRleCut(far_from_u32((uint32_t)(0xa0000000)),CrossBlitX,CrossBlitY,CrossBlitX + 0xd,
                                CrossBlitY + 9);
  dst.seg = 0xa000;
  dst.ofs = CrossBlitX + CrossBlitY * 0x140;
  gfx.seg = CrossBlitGfx.seg;
  gfx.ofs = CrossBlitGfx.ofs;
  ovr_blitLoadRleGfx(gfx,dst);
  if (DAT_2410_00e8 == 0) {
    unk = ovr_draw_2e25_0245();
    ovr_play_sfxU(0,1,unk);
  }
  return;
}



/* 4528:02fb */

void __cdecl16far saveui_4528_02fb(undefined4 param_1,int param_2,int param_3)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  far_t gfx;
  far_t gfx_00;
  far_t dst;
  far_t dst_00;
  
  dst.seg = 0xa000;
  dst.ofs = (uint16_t)((char *)"cleric fortress" + 4 + param_2 * 0x12c0);
  gfx.seg = DAT_2000_cacb;
  gfx.ofs = DAT_2000_cac9;
  ovr_blitLoadRleGfx(gfx,dst);
  TextBlitX = 0x2a;
  TextBlitY = param_2 * 0xf + 0x1d;
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  puVar1 = (undefined2 *)((int)param_1 + (param_2 + param_3) * 4);
  ovr_blitText((char *)CONCAT22(puVar1[1],(char *)*puVar1),(byte *)Font03.ofs,0xde,0x8);
  ovr_OVC28_6018_0000();
  dst_00.seg = 0xa000;
  dst_00.ofs = (uint16_t)((char *)"cleric fortress" + 4 + param_2 * 0x12c0);
  gfx_00.seg = DAT_2000_cac7;
  gfx_00.ofs = DAT_2000_cac5;
  ovr_blitLoadRleGfx(gfx_00,dst_00);
  TextBlitX = 0x2a;
  TextBlitY = param_2 * 0xf + 0x1d;
  puVar1 = (undefined2 *)((int)param_1 + (param_2 + param_3) * 4);
  ovr_blitText((char *)CONCAT22(puVar1[1],(char *)*puVar1),(byte *)Font03.ofs,0xde,0xf);
  return;
}



/* 4528:0404 */

/* WARNING: Type propagation algorithm not settling */

undefined2 __cdecl16far saveui_4528_0404(undefined4 param_1,int param_2,int param_3)

{
  char *pcVar1;
  uint uVar2;
  int *piVar3;
  undefined2 uVar4;
  char cStack_4;
  
  if ((((DAT_2410_00e8 == 0) && (8 < DAT_2410_00e4)) && (DAT_2410_00e4 < 0x19)) &&
     (((char *)"Sorry, you may not pass time during a battle." + 0x1b <= DAT_2410_00e6 &&
      ((DAT_2410_00e6 < (char *)"Sorry, you may not pass time during a battle." + 0x1c | 0xeU) != 0)
      ))) {
    uVar4 = 0;
  }
  else {
    pcVar1 = (char *)"puppetmaker" + 3;
    if ((((DAT_2410_00e8 == 0) &&
         ((pcVar1 = (char *)"puppetmaker" + 3, 0x15 < DAT_2410_00e4 &&
          (pcVar1 = (char *)"puppetmaker" + 3, DAT_2410_00e4 < 0x26)))) &&
        (pcVar1 = (char *)"puppetmaker" + 3, "ht 1991 Borland Intl." < DAT_2410_00e6)) &&
       (pcVar1 = (char *)(param_2 * 0xf + 0x19), DAT_2410_00e6 <= pcVar1)) {
      uVar2 = (uint)(DAT_2410_00e6 + -0x1a) / 0xf;
      pcVar1 = (char *)(uVar2 * 0xf + 0x1a);
      if ((uint)((int)DAT_2410_00e6 - (int)pcVar1) < 0xf) {
        uVar4 = (undefined2)((ulong)param_1 >> 0x10);
        piVar3 = (int *)((int)param_1 + (uVar2 + param_3) * 4);
        pcVar1 = (char *)0x0;
        if (*piVar3 != 0 || piVar3[1] != 0) {
          saveui_4528_02fb((int)param_1,uVar4,uVar2,param_3);
          cStack_4 = (char)uVar2;
          GMenuItem = cStack_4 + '\x01';
          return CONCAT11(0x24,cStack_4 + '\x01');
        }
      }
    }
    uVar4 = CONCAT11((char)((uint)pcVar1 >> 8),0xff);
  }
  return uVar4;
}



/* 4528:0533 */

void __cdecl16far saveui_4528_0533(void)

{
  far_t gfx;
  
  ovr_OVC18_48ac_0027();
  gfx.seg = DAT_2000_d1a5;
  gfx.ofs = DAT_2000_d1a3;
  ovr_blitGfxRect(gfx,0,0,BlitRects + 1,0x10,false);
  return;
}



/* 4528:055b */

void __cdecl16far
saveui_4528_055b(uint16_t param_1,uint16_t param_2,char *param_3,undefined2 param_4,uint *param_5,
                int param_6)

{
  far_t gfx;
  far_t gfx_00;
  undefined2 unaff_SS;
  brect_t local_c;
  
  F_SCOPY((uint8_t *)&local_c,(uint8_t *)0x26ad,10);
  local_c.x = *param_5;
  local_c.y = param_6 * 0xf + 0x1d;
  local_c.h = param_6 * 0xf + 0x28;
  gfx.seg = param_2;
  gfx.ofs = param_1;
  ovr_blitGfx10(gfx,0x16,param_6 * 0xf + 0x1d,(brect_t *)CONCAT22(unaff_SS,&local_c),0);
  TextBlitX = 0x2a;
  TextBlitY = param_6 * 0xf + 0x1d;
  ovr_blitText((char *)CONCAT22(param_4,param_3),(byte *)Font03.ofs,0xde,0xf);
  if (TextBlitX < *param_5) {
    local_c.x = TextBlitX;
    gfx_00.seg = param_2;
    gfx_00.ofs = param_1;
    ovr_blitGfx10(gfx_00,0x16,param_6 * 0xf + 0x1d,(brect_t *)CONCAT22(unaff_SS,&local_c),0);
  }
  *param_5 = TextBlitX;
  ovr_blitLetter('_',(byte *)CONCAT22(Font03.seg,Font03.ofs),0xf);
  return;
}



/* 4528:0664 */

void __cdecl16far saveui_4528_0664(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 uVar4;
  far_t gfx;
  far_t dst;
  
  for (iVar3 = 0; iVar3 < param_2; iVar3 = iVar3 + 1) {
    uVar4 = (undefined2)((ulong)param_1 >> 0x10);
    piVar1 = (int *)((int)param_1 + iVar3 * 4);
    if (*piVar1 != 0 || piVar1[1] != 0) {
      dst.seg = 0xa000;
      dst.ofs = (uint16_t)((char *)"cleric fortress" + 4 + iVar3 * 0x12c0);
      gfx.seg = DAT_2000_cac7;
      gfx.ofs = DAT_2000_cac5;
      ovr_blitLoadRleGfx(gfx,dst);
      TextBlitX = 0x2a;
      TextBlitY = iVar3 * 0xf + 0x1d;
      puVar2 = (undefined2 *)((int)param_1 + iVar3 * 4);
      ovr_blitText((char *)CONCAT22(puVar2[1],(char *)*puVar2),(byte *)Font03.ofs,0xde,0xf);
    }
  }
  return;
}



/* 4528:0706 */

void __cdecl16far uiMenuSub(char *title,far_t items,uint16_t nitems,uint16_t defopt)

{
  undefined2 uVar1;
  byte bVar2;
  char *pcVar3;
  uint uVar4;
  uint16_t uVar5;
  undefined2 *puVar6;
  uint16_t uVar7;
  undefined2 unaff_SS;
  undefined2 local_28 [14];
  char *pcStack_c;
  char *pcStack_a;
  uint16_t sz;
  int iStack_6;
  byte readed;
  byte bStack_3;
  
  TextBlitDstSeg = 0xa000;
  if (title != (char *)0x0) {
    TextBlitX = 0x16;
    TextBlitY = 0xb;
    ovr_blitText(title,(byte *)Font03.ofs,0xde,0x7);
  }
  iStack_6 = 0;
  if ((int)nitems < 9) {
    sz = nitems;
  }
  else {
    sz = 8;
  }
  readed = 0;
  while( true ) {
    uVar5 = items.ofs;
    uVar7 = items.seg;
    if ((int)sz <= (int)(uint)readed) break;
    puVar6 = (undefined2 *)(uVar5 + (uint)readed * 4);
    uVar1 = *puVar6;
    uVar4 = (uint)readed;
    local_28[uVar4 * 2 + 1] = puVar6[1];
    local_28[uVar4 * 2] = uVar1;
    readed = readed + 1;
  }
  if (8 < (int)nitems) {
    pcStack_a = (char *)"puppetmaker" + 3;
    pcStack_c = (char *)"More";
  }
  saveui_4528_0664();
  GMenuItem = (byte)defopt;
  while (((int)(uint)GMenuItem <= (int)sz &&
         (*(int *)(&stack0xffd4 + (uint)GMenuItem * 4) == 0 &&
          *(int *)(&stack0xffd6 + (uint)GMenuItem * 4) == 0))) {
    GMenuItem = GMenuItem + 1;
  }
  if ((int)sz < (int)(uint)GMenuItem) {
    GMenuItem = 0;
  }
  saveui_4528_01b2();
  ovr_OVC40_69c8_047f();
  GMenuFlag = 1;
LAB_4528_0840:
  do {
    while (pcVar3 = (char *)uiReadKey2(),
          pcVar3 == (char *)"Reroll ability scores, or select the character\'s class." + 0x2b) {
LAB_4528_0903:
      do {
        GMenuItem = GMenuItem + 1;
        if ((int)sz < (int)(uint)GMenuItem) {
          GMenuItem = 0;
        }
      } while ((GMenuItem != 0) &&
              (*(int *)(&stack0xffd4 + (uint)GMenuItem * 4) == 0 &&
               *(int *)(&stack0xffd6 + (uint)GMenuItem * 4) == 0));
      saveui_4528_01b2();
    }
    if ((char *)"Reroll ability scores, or select the character\'s class." + 0x2c <= pcVar3) {
      if (pcVar3 != (char *)"%s will no longer build houses automatically." + 0xc) {
        if ((char *)"%s will no longer build houses automatically." + 0xc < pcVar3) {
          if (pcVar3 == (char *)0xfffe) {
            GMenuFlag = 0;
            return;
          }
          if ((pcVar3 == (char *)0xffff) &&
             (bStack_3 = saveui_4528_0404(local_28), bVar2 = bStack_3, bStack_3 != 0xff)) {
LAB_4528_0b46:
            GMenuItem = bVar2;
            if (GMenuItem != 0) {
              saveui_4528_02fb(local_28);
            }
            if (((int)nitems < 9) || (GMenuItem != 8)) {
              GMenuFlag = 0;
              return;
            }
            if (iStack_6 + 7 < (int)nitems) {
              iStack_6 = iStack_6 + 7;
            }
            else {
              iStack_6 = 0;
            }
            _fsetmem((undefined2 *)CONCAT22(unaff_SS,local_28),0x1c,0);
            for (readed = 0; (readed < 7 && ((int)((uint)readed + iStack_6) < (int)nitems));
                readed = readed + 1) {
              puVar6 = (undefined2 *)(uVar5 + ((uint)readed + iStack_6) * 4);
              uVar1 = *puVar6;
              uVar4 = (uint)readed;
              local_28[uVar4 * 2 + 1] = puVar6[1];
              local_28[uVar4 * 2] = uVar1;
            }
            saveui_4528_0533();
            if (title != (char *)0x0) {
              TextBlitX = 0x16;
              TextBlitY = 0xb;
              ovr_blitText(title,(byte *)Font03.ofs,0xde,0x7);
            }
            saveui_4528_0664();
            saveui_4528_01b2();
          }
          goto LAB_4528_0840;
        }
        if (pcVar3 == (char *)"Please type your character\'s name. Esc go back." + 8)
        goto LAB_4528_0903;
        if (pcVar3 != (char *)"%s will now build homes automatically.") goto LAB_4528_0840;
      }
      if (8 < (int)nitems) {
        if (iStack_6 + 7 < (int)nitems) {
          iStack_6 = iStack_6 + 7;
        }
        else {
          iStack_6 = 0;
        }
        _fsetmem((undefined2 *)CONCAT22(unaff_SS,local_28),0x1c,0);
        for (readed = 0; (readed < 7 && ((int)((uint)readed + iStack_6) < (int)nitems));
            readed = readed + 1) {
          puVar6 = (undefined2 *)(uVar5 + ((uint)readed + iStack_6) * 4);
          uVar1 = *puVar6;
          uVar4 = (uint)readed;
          local_28[uVar4 * 2 + 1] = puVar6[1];
          local_28[uVar4 * 2] = uVar1;
        }
        saveui_4528_0533();
        if (title != (char *)0x0) {
          TextBlitX = 0x16;
          TextBlitY = 0xb;
          ovr_blitText(title,(byte *)Font03.ofs,0xde,0x7);
        }
        saveui_4528_0664();
        GMenuItem = 8;
        saveui_4528_01b2();
      }
      goto LAB_4528_0840;
    }
    if (pcVar3 == (char *)"dc%lx %d ln %ld lc %ld @%lx \r" + 0xf) {
LAB_4528_08ad:
      do {
        GMenuItem = GMenuItem - 1;
        if (GMenuItem == 0xff) {
          GMenuItem = (byte)sz;
        }
      } while ((GMenuItem != 0) &&
              (*(int *)(&stack0xffd4 + (uint)GMenuItem * 4) == 0 &&
               *(int *)(&stack0xffd6 + (uint)GMenuItem * 4) == 0));
      saveui_4528_01b2();
    }
    else if ((char *)"dc%lx %d ln %ld lc %ld @%lx \r" + 0xf < pcVar3) {
      if (((pcVar3 == (char *)"pasopl.adv" + 7) || (pcVar3 == (char *)0x4939)) && (8 < (int)nitems))
      {
        if (iStack_6 == 0) {
          iStack_6 = ((int)(nitems - 1) / 7) * 7;
        }
        else {
          iStack_6 = iStack_6 + -7;
        }
        _fsetmem((undefined2 *)CONCAT22(unaff_SS,local_28),0x1c,0);
        for (readed = 0; (readed < 7 && ((int)((uint)readed + iStack_6) < (int)nitems));
            readed = readed + 1) {
          puVar6 = (undefined2 *)(uVar5 + ((uint)readed + iStack_6) * 4);
          uVar1 = *puVar6;
          uVar4 = (uint)readed;
          local_28[uVar4 * 2 + 1] = puVar6[1];
          local_28[uVar4 * 2] = uVar1;
        }
        saveui_4528_0533();
        if (title != (char *)0x0) {
          TextBlitX = 0x16;
          TextBlitY = 0xb;
          ovr_blitText(title,(byte *)Font03.ofs,0xde,0x7);
        }
        saveui_4528_0664();
        GMenuItem = 8;
        saveui_4528_01b2();
      }
    }
    else {
      if (pcVar3 == (char *)0x11b) {
        GMenuFlag = 0;
        return;
      }
      bVar2 = GMenuItem;
      if (pcVar3 == (char *)"%s: provides housing and income." + 8) goto LAB_4528_0b46;
      if (pcVar3 == (char *)0x4800) goto LAB_4528_08ad;
    }
  } while( true );
}



/* 4528:0c98 */

undefined2 __cdecl16far
uiReadString(char *param_1,int param_2,int param_3,char *param_4,uint16_t param_5)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  uint8_t *puVar5;
  far_t gfx;
  char *src;
  far_t dst;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  char local_5c [80];
  far_t fStack_c;
  undefined2 local_8;
  byte bStack_5;
  char *pcStack_4;
  
  UserWantsExit = 0;
  DAT_2000_d19c = 0;
  if (param_1 != (char *)0x0 || param_2 != 0) {
    TextBlitX = 0x16;
    TextBlitY = 0xb;
    ovr_blitText((char *)CONCAT22(param_2,param_1),(byte *)Font03.ofs,0xde,0x7);
  }
  if (param_4 == (char *)0x0 && param_5 == 0) {
    local_5c[0] = '\0';
  }
  else {
    strcpy(local_5c,param_4);
  }
  sVar1 = strlen(local_5c);
  bStack_5 = (byte)sVar1;
  fStack_c = ovr_stshRleCut(far_from_u32((uint32_t)(0xa0000000)),22,param_3 * 0xf + 0x1d,222,param_3 * 0xf + 0x29);
  TextBlitX = 0x2a;
  TextBlitY = param_3 * 0xf + 0x1d;
  local_8 = 0;
  saveui_4528_055b(fStack_c);
  dst.seg = 0xa000;
  dst.ofs = (uint16_t)((char *)"cleric fortress" + 4 + param_3 * 0x12c0);
  gfx.seg = DAT_2000_cac7;
  gfx.ofs = DAT_2000_cac5;
  ovr_blitLoadRleGfx(gfx,dst);
  ovr_OVC40_69c8_047f();
  GMenuFlag = 1;
LAB_4528_0dc9:
  do {
    while( true ) {
      while( true ) {
        pcStack_4 = (char *)uiReadKey2();
        if ((((((uint)pcStack_4 & 0xff) < 0x20) || (0x7e < ((uint)pcStack_4 & 0xff))) ||
            (0x4e < bStack_5)) || (((uint)pcStack_4 & 0xff) == 0x40)) break;
        local_5c[bStack_5] = (char)pcStack_4;
        local_5c[bStack_5 + 1] = '\0';
        iVar2 = ovr_font_302d_06ea(local_5c);
        iVar3 = ovr_font_302d_06ea();
        if (iVar2 + iVar3 + 0x2aU < 0xe0) {
          bStack_5 = bStack_5 + 1;
        }
        local_5c[bStack_5] = '\0';
        saveui_4528_055b(fStack_c);
      }
      if (pcStack_4 != (char *)0x4b00) break;
LAB_4528_0ece:
      if (bStack_5 != 0) {
        bStack_5 = bStack_5 - 1;
        local_5c[bStack_5] = '\0';
        saveui_4528_055b(fStack_c);
      }
    }
    if (pcStack_4 < (char *)0x4b01) {
      if (pcStack_4 == (char *)0x11b) {
        UserWantsExit = 1;
LAB_4528_1068:
        DAT_2000_d19c = 1;
        ovr_stshFree(fStack_c);
        if (param_4 != (char *)0x0 || param_5 != 0) {
          handle_01.seg = param_5;
          handle_01.ofs = (uint16_t)param_4;
          ovr_stshFree(handle_01);
        }
        GMenuFlag = 0;
        return 0;
      }
      if (pcStack_4 == (char *)0xe08) goto LAB_4528_0ece;
      if (pcStack_4 == (char *)"%s: provides housing and income." + 8) goto LAB_4528_0ff7;
      goto LAB_4528_0dc9;
    }
    if (pcStack_4 == (char *)0x4b34) goto LAB_4528_0ece;
    if (pcStack_4 == (char *)0xfffe) goto LAB_4528_1068;
    if (pcStack_4 == (char *)0xffff) {
      if (((DAT_2410_00e8 == 0) && (8 < DAT_2410_00e4)) &&
         ((DAT_2410_00e4 < 0x19 && ((0xb4 < DAT_2410_00e6 && ((DAT_2410_00e6 < 0xb6 | 0xeU) != 0))))
         )) {
        DAT_2000_d19c = 1;
        ovr_stshFree(fStack_c);
        if (param_4 != (char *)0x0 || param_5 != 0) {
          handle.seg = param_5;
          handle.ofs = (uint16_t)param_4;
          ovr_stshFree(handle);
        }
        GMenuFlag = 0;
        return 0;
      }
      if ((((DAT_2410_00e8 == 0) && (0x15 < DAT_2410_00e4)) && (DAT_2410_00e4 < 0x26)) &&
         ((param_3 * 0xf + 0x1aU <= DAT_2410_00e6 && (DAT_2410_00e6 <= param_3 * 0xf + 0x28U)))) {
LAB_4528_0ff7:
        ovr_stshFree(fStack_c);
        GMenuFlag = 0;
        if (bStack_5 == 0) {
          if (param_4 != (char *)0x0 || param_5 != 0) {
            handle_00.seg = param_5;
            handle_00.ofs = (uint16_t)param_4;
            ovr_stshFree(handle_00);
          }
          uVar4 = 0;
        }
        else {
          src = local_5c;
          puVar5 = ovr_stshRealloc((uint32_t)CONCAT22(param_5,param_4),(ulong)(bStack_5 + 1));
          uVar4 = strcpy((char *)(uint8_t *)puVar5,src);
        }
        return uVar4;
      }
    }
  } while( true );
}



/* 4528:10a8 */

void __cdecl16far uiMenu(char *title,far_t items,int nitems)

{
  uiMenuSub(title,items,nitems,1);
  return;
}



/* 4528:10c5 */

void __cdecl16far saveui_4528_10c5(int param_1,char *param_2,int param_3)

{
  size_t len;
  
  if (param_2 != (char *)0x0 || param_3 != 0) {
    len = strlen(param_2);
    write(param_1,param_2,len);
  }
  write(param_1,(char *)"\r\n",2);
  return;
}



/* 4528:1104 */

undefined2 __cdecl16far saveui_4528_1104(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 unaff_SS;
  char *pcVar4;
  char *src;
  char local_52 [80];
  
  iVar3 = 0;
  while (iVar3 < 0x4f) {
    iVar1 = read(param_1,local_52 + iVar3,1);
    if ((iVar1 != 1) || (local_52[iVar3] == '\n')) break;
    if (local_52[iVar3] != '\r') {
      iVar3 = iVar3 + 1;
    }
  }
  if (local_52[0] == '\x1a') {
    iVar3 = 0;
  }
  local_52[iVar3] = '\0';
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    src = local_52;
    pcVar4 = ovr_stshAlloc((long)(iVar3 + 1));
    uVar2 = strcpy((char *)pcVar4,src);
  }
  return uVar2;
}



/* 4528:1175 */

uint __cdecl16far saveui_4528_1175(int param_1,undefined2 param_2)

{
  char *filename;
  int handle;
  uint16_t uVar1;
  undefined2 uVar2;
  uint16_t in_DX;
  uint16_t uVar3;
  undefined2 *puVar4;
  uint uVar5;
  far_t handle_00;
  uint uStack_4;
  
  uStack_4 = 0;
  filename = ovr_fmVsprintf((char *)"%ssaves.txt",(char *)&GWorkDir);
  handle = ovr_open_wait_unlock_and_disk(filename);
  if (-1 < handle) {
    uVar1 = saveui_4528_1104();
    uVar3 = in_DX;
    uStack_4 = _atol(uVar1);
    handle_00.seg = in_DX;
    handle_00.ofs = uVar1;
    ovr_stshFree(handle_00);
    for (uVar5 = 0; uVar5 < uStack_4; uVar5 = uVar5 + 1) {
      uVar2 = saveui_4528_1104();
      puVar4 = (undefined2 *)(param_1 + uVar5 * 4);
      puVar4[1] = uVar3;
      *puVar4 = uVar2;
    }
    close(handle);
  }
  return uStack_4;
}



/* 4528:120d */

void __cdecl16far saveui_4528_120d(undefined4 param_1,uint param_2)

{
  char *path;
  int handle;
  undefined2 *puVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined1 local_16 [20];
  
  path = ovr_fmVsprintf((char *)"%ssaves.txt",(char *)&GWorkDir);
  handle = ovr_creat_wait_unlock_and_disk(path);
  if (-1 < handle) {
    _sprintf(local_16);
    saveui_4528_10c5(handle,local_16);
    for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1) {
      uVar3 = (undefined2)((ulong)param_1 >> 0x10);
      puVar1 = (undefined2 *)((int)param_1 + uVar2 * 4);
      saveui_4528_10c5(handle,*puVar1,puVar1[1]);
    }
    close(handle);
  }
  return;
}



/* 4528:1288 */

void __cdecl16far saveui_4528_1288(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint16_t *puVar4;
  undefined2 *puVar5;
  uint uVar6;
  undefined2 uVar7;
  far_t handle;
  
  for (uVar6 = 0; uVar6 < param_2; uVar6 = uVar6 + 1) {
    uVar7 = (undefined2)((ulong)param_1 >> 0x10);
    iVar2 = (int)param_1;
    piVar3 = (int *)(iVar2 + uVar6 * 4);
    if (*piVar3 != 0 || piVar3[1] != 0) {
      iVar1 = strcmp((char *)*(undefined2 *)(iVar2 + uVar6 * 4),(char *)GSPEmpty.ofs);
      if (iVar1 != 0) {
        puVar4 = (uint16_t *)(iVar2 + uVar6 * 4);
        handle.seg = puVar4[1];
        handle.ofs = *puVar4;
        ovr_stshFree(handle);
      }
    }
    puVar5 = (undefined2 *)(iVar2 + uVar6 * 4);
    puVar5[1] = 0;
    *puVar5 = 0;
  }
  return;
}



/* 4528:1303 */

/* WARNING: Instruction at (ram,0x0004072b) overlaps instruction at (ram,0x0004072a)
    */
/* WARNING: Control flow encountered bad instruction data */

char * __cdecl16far saveui_4528_1303(void)

{
  uint *puVar1;
  byte *pbVar2;
  undefined4 uVar3;
  far_t items;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  uint16_t uVar8;
  uint uVar9;
  char *pcVar10;
  char **ppcVar11;
  int in_CX;
  sbyte sVar12;
  undefined2 in_DX;
  uint *puVar13;
  byte bVar14;
  byte *unaff_SI;
  uint unaff_DI;
  undefined2 uVar15;
  uint16_t unaff_SS;
  byte abStackY_15bc [5516];
  undefined2 uStackY_30;
  char *pcStackY_2e;
  far_t ptr;
  char *local_20;
  undefined4 uStack_1e;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  char *pcStack_16;
  char *pcStack_14;
  char *pcStack_12;
  undefined1 uStack_f;
  char acStack_e [6];
  uint uStack_8;
  uint uStack_6;
  byte bStack_4;
  byte bStack_3;
  
  bStack_3 = 0;
  GMenuItem = '\x01';
  while( true ) {
    ovr_font_302d_0a30();
    saveui_4528_0533();
    pcVar10 = ovr_fmVsprintf((char *)"Message delay is now %d.",(char *)(uint)MessageDelay);
    ovr_say((char *)CONCAT22(in_DX,pcVar10));
    if (MessageDelay == 0) {
      uStack_1e = (uint *)0x0;
      local_20 = (char *)0x0;
    }
    else {
      uStack_1e = (uint *)0x2410;
      local_20 = (char *)"Decrease message delay";
    }
    if (MessageDelay < 0x28) {
      uStack_1a = (char *)"puppetmaker" + 3;
      uStack_1e = (uint *)CONCAT22((char *)"Increase message delay",(uint *)uStack_1e);
    }
    else {
      uStack_1a = (char *)0x0;
    }
    pcStack_16 = (char *)"puppetmaker" + 3;
    uStack_18 = (char *)"Test";
    pcStack_12 = (char *)"puppetmaker" + 3;
    pcStack_14 = (char *)"Done";
    ppcVar11 = &local_20;
    pcStackY_2e = (char *)"steam bath" + 6;
    uStackY_30 = 0x662e;
    items.seg = unaff_SS;
    items.ofs = (uint16_t)ppcVar11;
    uiMenuSub("Change message delay:",items,4,CONCAT11(0x24,GMenuItem));
    bStack_4 = (byte)ppcVar11;
    uVar9 = (uint)ppcVar11 & 0xff;
    if (uVar9 < 5) break;
    if ((char *)(uint)bStack_3 != (char *)0x0) {
      return (char *)(uint)bStack_3;
    }
  }
  puVar13 = (uint *)(uVar9 * 2);
  switch(uVar9) {
  default:
    if (GMenuItem == '\0') {
      pcVar10 = (char *)"arena" + 4;
    }
    else {
      pcVar10 = (char *)CONCAT11(0x24,GMenuItem + (char)uStack_6);
    }
    GMenuFlag = 0;
    return pcVar10;
  case 1:
    bVar14 = *unaff_SI;
    *(uint *)((byte *)((int)puVar13 + (int)unaff_SI) + -0x6af7) =
         *(uint *)((byte *)((int)puVar13 + (int)unaff_SI) + -0x6af7) | unaff_DI;
    *(uint *)(&stack0x0007 + (int)unaff_SI) =
         *(uint *)(&stack0x0007 + (int)unaff_SI) | (uint)unaff_SI;
    puVar1 = (uint *)(&stack0xffff + unaff_DI);
    *puVar1 = *puVar1 | unaff_DI;
    *puVar13 = *puVar13 | (uint)&stack0xffff;
                    /* WARNING: Read-only address (ram,0x00025f09) is written */
    (*(uint16_t *)((uint8_t *)&(s_fighters__residence_2410_1e09))) = (uint)&stack0xffde | 0x6966;
    bVar14 = (byte)((uint)puVar13 >> 8) | (byte)in_CX | bVar14 | (byte)unaff_DI;
    iVar6 = CONCAT11(bVar14,(byte)puVar13);
    pbVar2 = (byte *)(iVar6 + -0x51f8);
    *pbVar2 = *pbVar2 | bVar14;
    ((char *)"cflow4.txt" + 7)[unaff_DI] =
         ((char *)"cflow4.txt" + 7)[unaff_DI] | (byte)in_DX | (byte)puVar13;
    unaff_SI[iVar6 + 8] = unaff_SI[iVar6 + 8] | bVar14;
    (&stack0x0007)[(int)unaff_SI] = (&stack0x0007)[(int)unaff_SI] | (byte)ppcVar11;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 2:
    ((byte *)((int)puVar13 + (int)unaff_SI))[-0x75] =
         ((byte *)((int)puVar13 + (int)unaff_SI))[-0x75] + (byte)in_DX;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 3:
    break;
  }
switchD_4000_6642_caseD_3:
  *(int *)(abStackY_15bc + (int)unaff_SI) = *(int *)(abStackY_15bc + (int)unaff_SI) + in_CX;
  if (uVar9 == 0) {
    ovr_OVC15_4207_0b88();
    uVar15 = (undefined2)((ulong)uStack_1e >> 0x10);
    puVar13 = (uint *)uStack_1e;
    uStack_1a = (char *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)((ulong)((byte)puVar13[7] + 0xf) / 0x10));
    if ((puVar13[6] & 1) == 0) {
      pcStack_16 = (char *)0x0;
    }
    else {
      pcStack_16 = (char *)((byte)puVar13[6] - 2);
    }
    while( true ) {
      cVar4 = (char)uStack_1a;
      uStack_1a = (char *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)uStack_1a + -1);
      if (cVar4 == '\0') break;
      ovr_OVC15_4207_2301();
    }
  }
  else if ((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) == '\0') {
    uStack_1a = (char *)(uint)(byte)((ulong)((byte)((uint *)uStack_1e)[7] + 0xf) / 0x10);
    while( true ) {
      cVar4 = (char)uStack_1a;
      uStack_1a = (char *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)uStack_1a + -1);
      if (cVar4 == '\0') break;
      ptr.seg = Entities.seg;
      ptr.ofs = Entities.ofs + unaff_DI * 0x37;
      ovr_agnt_3b1d_196b(ptr);
    }
  }
  else if (((char)uStack_18 != '\0') && ((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) != '\0')) {
    uVar5 = manage_4d05_28f4();
    uStack_1a = (char *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),uVar5);
    while ((char)uStack_1a != '\0') {
      uVar15 = (undefined2)((ulong)uStack_1e >> 0x10);
      if ((((uint *)uStack_1e)[6] & 1) == 0) {
        pcStack_16 = (char *)0x0;
      }
      else {
        pcStack_16 = (char *)((byte)((uint *)uStack_1e)[6] - 2);
      }
      cVar4 = ovr_OVC15_4207_2301();
      if (cVar4 == '\0') break;
      uStack_1a = (char *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)uStack_1a + -1);
    }
  }
  do {
    do {
      do {
        unaff_DI = unaff_DI + 1;
        if (EntityCount <= unaff_DI) {
          GGameState = 0x3c;
          if (DebugVerbose != false) {
            pcStackY_2e = (char *)0x878;
            printf("%d %d %d  \r",0x3c);
          }
          func_0x0004fcda();
          GGameState = 0x3d;
          if (DebugVerbose != false) {
            pcStackY_2e = "ts %s unit engaged in combat. (%d, %d)";
            printf("%d %d %d  \r",0x3d);
          }
          ovr_OVC23_55fe_2b82();
          GGameState = 0xc;
          if (DebugVerbose != false) {
            pcStackY_2e = " %d  \r";
            printf("%d %d %d  \r",0xc);
          }
          ovr_OVC24_5943_0d5a();
          GGameState = 0x1f;
          if ((*(uint8_t *)((uint8_t *)&(uStack_18) + 1)) != '\0') {
            ovr_constr_36ce_03a6();
            GGameState = 0x13;
          }
          func_0x0004f68f();
          GGameState = 0x1d;
          for (iVar6 = 0; iVar6 < 5; iVar6 = iVar6 + 1) {
            if (acStack_e[iVar6] != '\0') {
              ovr_OVC41_6a8f_1be0();
            }
          }
          GGameState = 0xd;
          if (DebugVerbose != false) {
            pcStackY_2e = (char *)0x98b;
            printf("%d %d %d  \r",0xd);
          }
          ovr_OVC24_5943_112e();
          GGameState = 0xe;
          DAT_2410_648e = 1;
          return (char *)"puppetmaker" + 3;
        }
        uStack_1e = (uint *)CONCAT22(Entities.seg,(uint *)(Entities.ofs + unaff_DI * 0x37));
        iVar6 = ovr_OVC23_55fe_3450();
        iVar7 = ovr_OVC23_55fe_3450();
        if ((iVar6 == iVar7) &&
           (uVar15 = (undefined2)((ulong)uStack_1e >> 0x10),
           ((uint *)uStack_1e)[5] == ((uint *)uStack_1e)[1])) {
          pcStackY_2e = "it";
          manage_4d05_2b3e();
        }
        uVar15 = (undefined2)((ulong)uStack_1e >> 0x10);
        puVar13 = (uint *)uStack_1e;
      } while ((puVar13[4] == 0 && puVar13[5] == 0) || ((char)puVar13[0xc] != '\0'));
      bStack_3 = (*(uint *)((int)&far_t_ARRAY_2410_26f7[7].ofs + 1 +
                           (uint)*(byte *)((int)puVar13 + 0xd) * 0x95) & 0x4000) != 0;
      uStack_6 = *uStack_1e;
      uStack_8 = puVar13[1];
      uStack_f = *(undefined1 *)
                  ((int)(char **)GMenuStrings + (uint)*(byte *)((int)puVar13 + 0xd) * 0x95 + 0x1f);
      if (*(byte *)((int)puVar13 + 0x2f) < (byte)puVar13[0x18]) {
        sVar12 = (*(byte *)((int)puVar13 + 0x2f) & 3) << 1;
        in_CX = CONCAT11((char)((uint)in_CX >> 8),sVar12);
        *(byte *)(puVar13 + 6) =
             (byte)((int)(uint)*(byte *)((int)puVar13 +
                                        ((int)(uint)*(byte *)((int)puVar13 + 0x2f) >> 2) + 0x1b) >>
                   sVar12) & 3;
        cVar4 = func_0x0004f32d();
        puVar13 = (uint *)uStack_1e;
        uVar15 = (undefined2)((ulong)uStack_1e >> 0x10);
        if (cVar4 == '\0') {
          *uStack_1e = *uStack_1e + (int)*(char *)((byte)puVar13[6] + 0x885);
          puVar13[1] = puVar13[1] + (int)*(char *)((byte)puVar13[6] + 0x889);
          *(char *)((int)puVar13 + 0x2f) = *(char *)((int)puVar13 + 0x2f) + '\x01';
        }
        else {
          *(undefined1 *)((int)puVar13 + 0x2f) = 0;
          *(undefined1 *)(puVar13 + 0x18) = 0;
        }
      }
      else {
        pcStack_12 = (char *)ovr_OVC07_32c9_0026();
        pcStack_14 = (char *)ovr_OVC07_32c9_0026();
        if ((pcStack_12 != (char *)0x0) && (uVar8 = ovr_randBelow(2), (char)uVar8 != '\0')) {
          pcStackY_2e = " find music card.";
          cVar4 = func_0x0004f412();
          if (cVar4 == '\0') {
            *uStack_1e = (uint)(pcStack_12 + *uStack_1e);
            *(char *)((uint *)uStack_1e + 6) = '\x02' - (char)pcStack_12;
            goto LAB_3f0b_1477;
          }
        }
        if (pcStack_14 != (char *)0x0) {
          pcStackY_2e = " aborted.";
          cVar4 = func_0x0004f412();
          if (cVar4 == '\0') {
            uVar15 = (undefined2)((ulong)uStack_1e >> 0x10);
            puVar1 = (uint *)uStack_1e + 1;
            *puVar1 = (uint)(pcStack_14 + *puVar1);
            *(char *)((uint *)uStack_1e + 6) = (char)pcStack_14 + '\x01';
            goto LAB_3f0b_1477;
          }
        }
        if (pcStack_12 != (char *)0x0) {
          pcStackY_2e = "yn BOTH numbers.)\n";
          cVar4 = func_0x0004f412();
          if (cVar4 == '\0') {
            *uStack_1e = (uint)(pcStack_12 + *uStack_1e);
            *(char *)((uint *)uStack_1e + 6) = '\x02' - (char)pcStack_12;
            goto LAB_3f0b_1477;
          }
        }
        cVar4 = ovr_OVC26_5d45_031f();
        if (cVar4 == '\0') {
          pcStackY_2e = (char *)0x4e3;
          cVar4 = ovr_OVC26_5d45_06f0();
          if ((cVar4 == '\0') &&
             (*(char *)((int)(char **)GMenuStrings +
                       (uint)*(byte *)((int)(uint *)uStack_1e + 0xd) * 0x95 + 0x1f) == '\0')) {
            pcStackY_2e = (char *)0x524;
            manage_4d05_2b3e();
          }
        }
        else {
          uVar15 = (undefined2)((ulong)uStack_1e >> 0x10);
          puVar13 = (uint *)uStack_1e;
          sVar12 = (*(byte *)((int)puVar13 + 0x2f) & 3) << 1;
          in_CX = CONCAT11((char)((uint)in_CX >> 8),sVar12);
          *(byte *)(puVar13 + 6) =
               (byte)((int)(uint)*(byte *)((int)puVar13 +
                                          ((int)(uint)*(byte *)((int)puVar13 + 0x2f) >> 2) + 0x1b)
                     >> sVar12) & 3;
          cVar4 = func_0x0004f32d();
          if (cVar4 == '\0') {
            uVar15 = (undefined2)((ulong)uStack_1e >> 0x10);
            puVar13 = (uint *)uStack_1e;
            *uStack_1e = *uStack_1e + (int)*(char *)((byte)puVar13[6] + 0x885);
            puVar13[1] = puVar13[1] + (int)*(char *)((byte)puVar13[6] + 0x889);
            *(char *)((int)puVar13 + 0x2f) = *(char *)((int)puVar13 + 0x2f) + '\x01';
          }
        }
      }
LAB_3f0b_1477:
      uStack_18 = (char *)CONCAT11(1,(char)uStack_18);
      iVar6 = ovr_OVC23_55fe_3450();
      iVar7 = ovr_OVC23_55fe_3450();
      if (iVar6 == iVar7) {
        uVar15 = (undefined2)((ulong)uStack_1e >> 0x10);
        puVar13 = (uint *)uStack_1e;
        if (puVar13[5] == puVar13[1]) {
          puVar13[4] = 0;
          puVar13[5] = 0;
          if ((char)puVar13[0xd] == -1) {
            bStack_4 = 0xff;
          }
          else {
            uVar3 = *(undefined4 *)((uint)(byte)puVar13[0xd] << 2);
            bStack_4 = *(byte *)((int)uVar3 + 0x89);
          }
          if (bStack_4 != 0xff) {
            for (unaff_SI = (byte *)0x0; unaff_SI < DAT_2410_0881; unaff_SI = unaff_SI + 1) {
              iVar6 = ovr_OVC23_55fe_3450();
              iVar7 = ovr_OVC23_55fe_3450();
              if ((iVar6 == iVar7) &&
                 (*(uint *)((int)unaff_SI * 0x13 + 2) == ((uint *)uStack_1e)[1])) {
                manage_4d05_28e0();
                if (*(uint *)((int)unaff_SI * 0x13 + 2) == GfxRndSeed2) {
                  iVar6 = ovr_OVC23_55fe_3450();
                  iVar7 = ovr_OVC23_55fe_3450();
                  if (iVar6 == iVar7) {
                    acStack_e[bStack_4] = '\x01';
                  }
                }
                break;
              }
            }
          }
        }
      }
    } while (AgntFlag1 == false);
    if (((*uStack_1e < GfxRndSeed - 2U) || (GfxRndSeed + 1U < *uStack_1e)) ||
       (((uint *)uStack_1e)[1] != GfxRndSeed2)) {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    uStack_1a = (char *)CONCAT11(cVar4,(char)uStack_1a);
    if (((uStack_6 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uStack_6)) || (GfxRndSeed2 != uStack_8))
    {
      bVar14 = 0;
    }
    else {
      bVar14 = 1;
    }
    uStack_18 = (char *)CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_18) + 1)),bVar14);
  } while (bVar14 == 0 && cVar4 == '\0');
  uVar9 = (uint)bVar14;
  goto switchD_4000_6642_caseD_3;
}



/* 4528:144e */

void __cdecl16far saveui_4528_144e(void)

{
  far_t gfx;
  
  gfx.seg = FontHandle.seg;
  gfx.ofs = FontHandle.ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c31d)));
  return;
}



/* 4528:1470 */

void __cdecl16far saveui_4528_1470(void)

{
  saveui_4528_144e();
  TextBlitX = 0x1d;
  TextBlitY = 0xb7;
  ovr_blitText("Cancel",(byte *)Font03.ofs,0xcf,0xf);
  return;
}



/* 4528:14b1 */

/* WARNING: Instruction at (ram,0x0004b811) overlaps instruction at (ram,0x0004b810)
    */
/* WARNING: Control flow encountered bad instruction data */

byte * __cdecl16far uiMainMenuLoop(long param_1,byte *param_2,uint param_3,uint param_4)

{
  far_t items;
  char cVar1;
  uint16_t uVar2;
  uint8_t *pmenu;
  byte *pbVar3;
  undefined2 uVar4;
  byte *pbVar5;
  int *piVar6;
  byte *pbVar7;
  uint uVar8;
  byte *unaff_DI;
  uint16_t unaff_SS;
  bool bVar9;
  void *pvVar10;
  far_t fVar11;
  uint8_t menu [4];
  char *pcStack_30;
  char *pcStack_2e;
  byte *pbStack_28;
  char *pcStack_18;
  char *pcStack_16;
  byte bStack_13;
  uint8_t yesno [4];
  char cStack_e;
  char cStack_d;
  far_t fStack_8;
  undefined2 uStack_4;
  
  pbVar3 = unaff_DI;
  F_SCOPY(menu,(uint8_t *)(char **)GMenuStrings,0x20);
  uVar4 = 8;
  F_SCOPY(yesno,(uint8_t *)(char **)GYesNo,8);
  ovr_say("Stronghold V 1.00");
  fVar11.seg = DAT_2000_d1a1;
  fVar11.ofs = DAT_2000_d19f;
  ovr_blitLoadRleGfx(fVar11,far_from_u32((uint32_t)(0xa00009af)));
  ovr_stats_6386_00f8();
  saveui_4528_0533();
  fStack_8 = far_from_u32((uint32_t)(ovr_stshAlloc(400)));
  _fsetmem((void *)MK_FP(fStack_8.seg, fStack_8.ofs),400,0);
  pbVar7 = (byte *)0x0;
  uStack_4 = (byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_4) + 1)) << 8);
  while( true ) {
    if (SaveAuto == '\0') {
      pcStack_2e = (char *)0x0;
      pcStack_30 = (char *)0x0;
    }
    else {
      pcStack_2e = (char *)"puppetmaker" + 3;
      pcStack_30 = (char *)"Save Game";
    }
    if ((DAT_2000_ca90 == '\0') && (SaveAuto != '\0')) {
      pcStack_16 = (char *)"puppetmaker" + 3;
      pcStack_18 = (char *)"Begin Play";
    }
    else {
      pcStack_16 = (char *)0x0;
      pcStack_18 = (char *)0x0;
    }
    pmenu = menu;
    items.seg = unaff_SS;
    items.ofs = (uint16_t)pmenu;
    uiMenu("Select an option:",items,8);
    bStack_13 = (byte)pmenu;
    ovr_say("");
    uVar8 = (uint)bStack_13;
    if (uVar8 < 9) break;
    if ((SaveAuto != '\0') && ((char)uStack_4 != '\0')) {
      saveui_4528_1288();
      ovr_stshFree(fStack_8);
      pbVar3 = (byte *)ovr_OVC28_6018_0251();
      return pbVar3;
    }
  }
  pbVar5 = (byte *)(uVar8 * 2);
  switch(uVar8) {
  case 0:
    *unaff_DI = *unaff_DI & (byte)uVar4;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 1:
    uStack_4 = (byte *)((bStack_13 & (byte)*(undefined2 *)(&stack0x02c2 + (int)unaff_DI)) + 0xf8);
    pbVar3 = uStack_4;
    break;
  case 2:
    while( true ) {
      (pbVar5 + (int)unaff_DI)[-0x1ba] = (pbVar5 + (int)unaff_DI)[-0x1ba] + (char)uVar4;
      piVar6 = (int *)(fStack_8.ofs + (int)uStack_4 * 4);
      piVar6[1] = (*(uint16_t *)((uint8_t *)&(param_1) + 2));
      *piVar6 = (int)param_1 + (int)unaff_DI * 0x1e;
      for (uVar8 = 0; uVar8 < *(byte *)((int)param_1 + (int)unaff_DI * 0x1e + 0x1b);
          uVar8 = uVar8 + 1) {
        if (uVar8 == 0) {
          fVar11 = ovr_stshAllocStub();
          *(uint16_t *)(fStack_8.ofs + (int)uStack_4 * 4 + 0x5a) = fVar11.seg;
          *(uint16_t *)(fStack_8.ofs + (int)uStack_4 * 4 + 0x58) = fVar11.ofs;
        }
        else {
          ovr_stshAllocStub();
        }
      }
      unaff_DI = unaff_DI + 1;
      if ((param_2 <= unaff_DI) || (*(char *)((int)param_1 + (int)unaff_DI * 0x1e + 0x1b) == '\0'))
      break;
      pbVar5 = (byte *)((int)param_1 + (int)unaff_DI * 0x1e);
      uStack_4 = (byte *)(uint)*pbVar5;
    }
    return (byte *)fStack_8.ofs;
  case 3:
  case 5:
    if (*(char *)((int)(char **)GMenuStrings +
                 (uint)*(byte *)(Entities.ofs + uVar8 + 0xd) * 0x95 + 0x1f) == '\0') {
      ovr_play_sfx(38,0);
    }
    else {
      ovr_play_sfx(36,0);
    }
    *(undefined1 *)(Entities.ofs + 0x18) = 0;
    *(undefined1 *)(Entities.ofs + 0x31) = *(undefined1 *)(Entities.ofs + 0x32);
    if ((byte *)((int)(undefined4 *)&_DATA + 1) < EntityCount) {
      pbVar7 = (byte *)((char *)"thief" + 5);
      ovr_say((char *)CONCAT22(pbVar3,(char *)
                                      "The damaged structures belonging to all leaders are highlighted in red."
                              ));
      return pbVar7;
    }
    if ((cStack_e != '\0') || (cStack_d != '\0')) {
      if ((*(uint8_t *)((uint8_t *)&(uStack_4) + 1)) == '\0') {
        ovr_stop_audio();
        CurSfxType3 = 0xff;
        ovr_play_sfx(90,0);
      }
      else if (cStack_d == '\0') {
        if (cStack_e != '\0') {
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
    pbVar3 = (byte *)ovr_OVC23_55fe_2b82();
    return pbVar3;
  case 4:
    do {
      cVar1 = ovr_OVC23_55fe_05db();
      if ((cVar1 == '\0') && ((*(byte *)(Entities.ofs + (int)pbVar7 * 0x37 + 0x33) & 3) == 0)) {
        return pbVar7;
      }
      do {
        pbVar7 = pbVar7 + 1;
        if (EntityCount <= pbVar7) {
          pbVar7 = (byte *)0x0;
        }
        if (pbVar7 == unaff_DI) {
          uVar2 = ovr_randBelow((uint16_t)EntityCount);
          return (byte *)(uVar2 & 0xff);
        }
      } while (*(char *)(Entities.ofs + (int)pbVar7 * 0x37 + 0x1a) != (char)fStack_8.ofs);
    } while( true );
  case 6:
    pbVar3 = (byte *)(uint)(bStack_13 | 0xb);
    bVar9 = false;
    while (!bVar9) {
      if ((0 < (int)param_4) || ((uVar8 = param_3, -1 < (int)param_4 && (0xbfff < param_3)))) {
        uVar8 = 0xc000;
      }
      pvVar10 = (void *)ovr_mkp((*(uint16_t *)((uint8_t *)&(param_1) + 2)),(uint16_t)param_2);
      param_2 = (byte *)((ulong)pvVar10 >> 0x10);
      write((int)unaff_DI,(void *)pvVar10,uVar8);
      param_1 = (ulong)((int)(void *)pvVar10 + uVar8) << 0x10;
      bVar9 = param_3 < uVar8;
      param_3 = param_3 - uVar8;
      param_4 = param_4 - bVar9;
      pbVar3 = (byte *)(param_3 | param_4);
      bVar9 = pbVar3 == (byte *)0x0;
    }
    return pbVar3;
  case 7:
    return pbStack_28;
  case 8:
                    /* WARNING: Subroutine does not return */
    ovr_stExit((int)pbVar3);
  }
  do {
    if ((((*(uint *)((int)pbVar3 * 0x27 + 0x121) & 0xa0) != 0) ||
        (*(char *)((int)pbVar3 * 0x27 + 0x133) == '\0')) ||
       (*(char *)((int)pbVar3 * 0x27 + 0x133) == '\a')) break;
    pbVar3 = pbVar3 + 1;
    if ((char *)"y1 %d yn %d y3 %d yx %d " + 0x11 < pbVar3) {
      pbVar3 = (byte *)((int)&GUnitDescriptions[3].ofs + 1);
    }
  } while (uStack_4 != pbVar3);
  for (fStack_8.seg = 0; fStack_8.seg < 0x94; fStack_8.seg = fStack_8.seg + 1) {
    for (uVar8 = 0; uVar8 < 0x3c; uVar8 = uVar8 + 1) {
      uVar4 = (undefined2)((ulong)DAT_2000_cb0d >> 0x10);
      if ((byte *)*(int *)((int)DAT_2000_cb0d + fStack_8.seg * 0x78 + uVar8 * 2) == pbVar3) {
        *(undefined2 *)((int)DAT_2000_cb0d + fStack_8.seg * 0x78 + uVar8 * 2) = 0;
      }
    }
  }
  *(undefined1 *)((int)DAT_2000_ca95 + (int)pbVar3 * 9) = (*(uint8_t *)((uint8_t *)&(param_2)));
  *(undefined1 *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 1) = 8;
  *(undefined1 *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 2) = (undefined1)param_3;
  *(int *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 4) = (int)param_1;
  *(int *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 6) = (*(uint16_t *)((uint8_t *)&(param_1) + 2));
  *(undefined2 *)((int)DAT_2000_cb0d + (int)param_1 * 0x78 + (*(uint16_t *)((uint8_t *)&(param_1) + 2)) * 2) = pbVar3;
  uVar4 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
  *(uint *)((int)DAT_2000_cb09 + (*(uint16_t *)((uint8_t *)&(param_1) + 2)) * 0x128 + (int)param_1 * 2) =
       *(uint *)((int)DAT_2000_cb09 + (*(uint16_t *)((uint8_t *)&(param_1) + 2)) * 0x128 + (int)param_1 * 2) & 0x3fff |
       (uint)*(byte *)(((uint)param_2 & 0xff) * 0x27 + 0x11e) << 0xe;
  if ((*(uint *)(((uint)param_2 & 0xff) * 0x27 + 0x121) & 0x40) == 0) {
    *(undefined1 *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 8) = 0;
  }
  else {
    cVar1 = ovr_constr_36ce_3172();
    if (cVar1 == '\x03') {
      uVar2 = ovr_randBelow(0x28);
      *(char *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 8) = (char)uVar2 + '\x1e';
    }
    else if (cVar1 == '\x04') {
      uVar2 = ovr_randBelow(0x50);
      *(char *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 8) = (char)uVar2 + '<';
    }
    else {
      uVar2 = ovr_randBelow(0x14);
      *(char *)((int)DAT_2000_ca95 + (int)pbVar3 * 9 + 8) = (char)uVar2 + '\x0f';
    }
  }
  return pbVar3;
}



/* 4528:1ae8 */

void __cdecl16far saveui_4528_1ae8(void)

{
  far_t items;
  far_t items_00;
  uint8_t *puVar1;
  uint16_t unaff_SS;
  uint8_t local_54 [32];
  uint8_t local_34 [12];
  undefined2 local_28 [4];
  uint8_t local_20 [20];
  char cStack_c;
  byte bStack_b;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  F_SCOPY(local_20,(uint8_t *)0x26e3,0x14);
  F_SCOPY(local_34,(uint8_t *)(far_t *)far_t_ARRAY_2410_26f7,0x14);
  F_SCOPY(local_54,(uint8_t *)(far_t *)(far_t_ARRAY_2410_26f7 + 5),0x20);
  puVar1 = local_54;
  items.seg = unaff_SS;
  items.ofs = (uint16_t)puVar1;
  uiMenu("Which new world:",items,7);
  bStack_b = (byte)puVar1;
  saveui_4528_0533();
  if ((bStack_b != 8) && (bStack_b != 0)) {
    if (bStack_b == 7) {
      DAT_2410_26e1 = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
      GSeed = *(undefined2 *)BDA_DailyTimeCounter;
    }
    else {
      if (bStack_b == 1) {
        ovr_save_49fd_0863();
        return;
      }
      DAT_2410_26e1 = local_28[(uint)bStack_b * 2 + 1];
      GSeed = local_28[(uint)bStack_b * 2];
    }
    srand8(CONCAT22(DAT_2410_26e1,GSeed));
    cStack_c = bStack_b - 1;
    puVar1 = local_34;
    items_00.seg = unaff_SS;
    items_00.ofs = (uint16_t)puVar1;
    uiMenu("Hostility level:",items_00,5);
    bStack_b = (byte)puVar1;
    saveui_4528_0533();
    if ((bStack_b != '\x05') && (bStack_b != '\0')) {
      if (bStack_b == '\x04') {
        iStack_a = saveui_4528_1d55((char *)"Low intelligence enemies:",(char *)"puppetmaker" + 3,6)
        ;
        saveui_4528_0533();
        if (iStack_a < 0) {
          if (DAT_2000_d19c != '\0') {
            return;
          }
          iStack_a = 0;
        }
        iStack_8 = saveui_4528_1d55((char *)"Medium intelligence enemies:",(char *)"puppetmaker" + 3
                                    ,6);
        saveui_4528_0533();
        if (iStack_8 < 0) {
          if (DAT_2000_d19c != '\0') {
            return;
          }
          iStack_8 = 0;
        }
        iStack_6 = saveui_4528_1d55((char *)"High intelligence enemies:",(char *)"puppetmaker" + 3,6
                                   );
        saveui_4528_0533();
        if (iStack_6 < 0) {
          if (DAT_2000_d19c != '\0') {
            return;
          }
          iStack_6 = 0;
        }
        iStack_4 = saveui_4528_1d55((char *)"Size of second wave:",(char *)"puppetmaker" + 3,6);
        saveui_4528_0533();
        if (iStack_4 < 0) {
          if (DAT_2000_d19c != '\0') {
            return;
          }
          iStack_4 = 0;
        }
        if (0x3c < iStack_a + iStack_8 + iStack_6 + iStack_4) {
          ovr_say("Too many enemies. 60 enemies maximum.");
          return;
        }
        DAT_2410_5dcf = (undefined1)iStack_a;
        DAT_2410_5dd7 = (undefined1)iStack_8;
        DAT_2410_5ddf = (undefined1)iStack_6;
        DAT_2410_5de7 = (undefined1)iStack_4;
      }
      DAT_2000_d19d = bStack_b;
      DAT_2000_d19e = cStack_c;
      ovr_say("Resetting game...");
      ovr_init_3381_2101();
      ovr_say("New world complete.");
    }
  }
  return;
}



/* 4528:1d0f */

int __cdecl16far saveui_4528_1d0f(char *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while (*param_1 != '\0') {
    if ((((byte *)_ctype + 1)[*param_1] & 2) != 0) {
      iVar1 = (int)*param_1 + iVar1 * 10 + -0x30;
    }
    param_1 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(param_1) + 2)),(char *)param_1 + 1);
  }
  return iVar1;
}



/* 4528:1d55 */

undefined2 __cdecl16far saveui_4528_1d55(char *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  undefined1 local_5c [80];
  far_t fStack_c;
  undefined2 local_8;
  byte bStack_5;
  char *pcStack_4;
  
  DAT_2000_d19c = 0;
  if (param_1 != (char *)0x0 || param_2 != 0) {
    TextBlitX = 0x16;
    TextBlitY = 0xb;
    ovr_blitText((char *)CONCAT22(param_2,param_1),(byte *)Font03.ofs,0xde,0x7);
  }
  bStack_5 = 0;
  local_5c[0] = 0;
  fStack_c = ovr_stshRleCut(far_from_u32((uint32_t)(0xa0000000)),22,param_3 * 0xf + 0x1d,222,param_3 * 0xf + 0x27);
  TextBlitX = 0x2a;
  TextBlitY = param_3 * 0xf + 0x1d;
  local_8 = 0;
  saveui_4528_055b(fStack_c,local_5c);
  ovr_OVC40_69c8_047f();
LAB_4528_1e1d:
  do {
    while( true ) {
      while( true ) {
        pcStack_4 = (char *)uiReadKey2();
        if (((((byte *)_ctype + 1)[(uint)pcStack_4 & 0xff] & 2) == 0) || (1 < bStack_5)) break;
        local_5c[bStack_5] = (*(uint8_t *)((uint8_t *)&(pcStack_4)));
        local_5c[bStack_5 + 1] = 0;
        iVar1 = ovr_font_302d_06ea(local_5c);
        iVar2 = ovr_font_302d_06ea();
        if (iVar1 + iVar2 + 0x2aU < 0xe0) {
          bStack_5 = bStack_5 + 1;
        }
        local_5c[bStack_5] = 0;
        saveui_4528_055b(fStack_c,local_5c);
      }
      if (pcStack_4 != (char *)0x4b00) break;
LAB_4528_1f0c:
      if (bStack_5 != 0) {
        bStack_5 = bStack_5 - 1;
        local_5c[bStack_5] = 0;
        saveui_4528_055b(fStack_c,local_5c);
      }
    }
    if ((char *)0x4b00 < pcStack_4) {
      if (pcStack_4 == (char *)0x4b34) goto LAB_4528_1f0c;
      if (pcStack_4 == (char *)0xfffe) {
LAB_4528_1f83:
        DAT_2000_d19c = 1;
        ovr_stshFree(fStack_c);
        return 0xffff;
      }
      if ((pcStack_4 == (char *)0xffff) && (DAT_2410_00e8 == 0)) goto LAB_4528_1f59;
      goto LAB_4528_1e1d;
    }
    if (pcStack_4 == (char *)0x11b) goto LAB_4528_1f83;
    if (pcStack_4 == (char *)0xe08) goto LAB_4528_1f0c;
    if (pcStack_4 == (char *)"%s: provides housing and income." + 8) {
LAB_4528_1f59:
      ovr_stshFree(fStack_c);
      if (bStack_5 == 0) {
        uVar3 = 0xffff;
      }
      else {
        uVar3 = saveui_4528_1d0f(local_5c);
      }
      return uVar3;
    }
  } while( true );
}


