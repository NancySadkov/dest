/*
 * ovc38_scores.c - recovered from STRONG.EXE
 * memory block: OVC38_scores.c
 * range: 68ac:0000 - 68ac:05ef
 * functions: 6
 */
#include "recovered.h"


/* 68ac:0000 */

/* Loads the six high-score entries from high.txt (zeroing the table when the file is absent). */

void __cdecl16far ovc38_loadHighScores(far_t entries)

{
  char *filename;
  int iVar1;
  uint16_t uVar2;
  uint16_t in_DX;
  uint16_t *puVar3;
  int iVar4;
  uint8_t msg;
  
  filename = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6a89,_SS),(char *)MK_FP(0x2410, 0x8c6c),0x2410)
  ;
  iVar1 = ovr_open_wait_unlock_and_disk(filename,in_DX);
  if (iVar1 < 0) {
    for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
      puVar3 = (uint16_t *)(entries.ofs + iVar1 * 4);
      puVar3[1] = 0;
      *puVar3 = 0;
    }
  }
  else {
    for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
      uVar2 = ovr_saveui_readLine(iVar1);
      puVar3 = (uint16_t *)(entries.ofs + iVar4 * 4);
      puVar3[1] = in_DX;
      *puVar3 = uVar2;
    }
    close(iVar1);
  }
  return;
}



/* 68ac:008a */

/* Writes the six high-score entries to high.txt. */

void __cdecl16far ovc38_saveHighScores(far_t entries)

{
  char *path;
  int handle;
  uint16_t in_DX;
  int *piVar1;
  uint16_t *puVar2;
  int iVar3;
  uint16_t uVar4;
  uint8_t msg;
  
  path = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6a89,_SS),(char *)MK_FP(0x2410, 0x8c6c),0x2410);
  handle = ovr_creat_wait_unlock_and_disk(path,in_DX);
  if (-1 < handle) {
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      uVar4 = entries.seg;
      piVar1 = (int *)(entries.ofs + iVar3 * 4);
      if (*piVar1 != 0 || piVar1[1] != 0) {
        puVar2 = (uint16_t *)(entries.ofs + iVar3 * 4);
        ovr_saveui_writeLine(handle,(char *)*puVar2,puVar2[1]);
      }
    }
    close(handle);
  }
  return;
}



/* 68ac:00fd */

/* [R4] calls ovr_stshFree */

void __cdecl16far ovc38_usesStshFree(far_t handle)

{
  int *piVar1;
  uint16_t *puVar2;
  int iVar3;
  far_t handle_00;
  
  for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
    piVar1 = (int *)(handle.ofs + iVar3 * 4);
    if (*piVar1 != 0 || piVar1[1] != 0) {
      puVar2 = (uint16_t *)(handle.ofs + iVar3 * 4);
      handle_00.seg = puVar2[1];
      handle_00.ofs = *puVar2;
      ovr_stshFree(handle_00);
    }
  }
  ovr_stshFree(handle);
  return;
}



/* 68ac:0148 */
void __cdecl16far ovc38_showAchievements(void)

{
  /* Re-derived: loads and displays the high-score table.  The allocated block's segment came
     from an `in_DX` pseudo-register; it is the ST_SEG of the stshAlloc result, the same idiom
     used elsewhere in the tree.  unaff_DI and uVar4 were declared/assigned but never read. */
  far_t entries;
  int *itemPtr;
  int nameLen;
  int row;
  uint8_t nameBuf;
  far_t menuItems[10];   /* the SS:[BP-0x80] menu array */
  uint8_t *namePtr;
  far_t block;

  {
    void far *p = ovr_stshAlloc(0x18);
    block.ofs = ST_OFF(p);
    block.seg = ST_SEG(p);
  }
  entries.seg = block.seg;
  entries.ofs = block.ofs;
  ovc38_loadHighScores(entries);
  ovr_saveui_blitPanel();
  TextBlitX = 0x16;
  TextBlitY = 0xb;
  ovr_blitText((char *)"Great Achievements",(byte *)CONCAT22(Font03.ofs,(char *)0x2410),
               Font03.seg,0xde,0xde,7);
  TextBlitX = 0x16;
  TextBlitY = 0x1a;
  ovr_blitText((char *)"Name",(byte *)CONCAT22(Font03.ofs,(char *)0x2410),Font03.seg,0xde
               ,0xde,7);
  TextBlitX = 0xae;
  ovr_blitText((char *)"Enemies",(byte *)CONCAT22(Font03.ofs,(char *)0x2410),Font03.seg,
               0xde,0xde,7);
  for (row = 0; row < 6; row = row + 1) {
    TextBlitX = 0x16;
    TextBlitY = row * 0xf + 0x2a;
    itemPtr = (int *)((int)block.ofs + row * 4);
    if (*itemPtr != 0 || itemPtr[1] != 0) {
      itemPtr = (int *)((int)block.ofs + row * 4);
      nameLen = 0;
      namePtr = (uint8_t *)CONCAT22(itemPtr[1],(uint8_t *)(*itemPtr + 1));
      while (((nameLen < 0x4f && (*namePtr != 0x40)) && (*namePtr != 0x0))) {
        (&nameBuf)[nameLen] = *namePtr;
        nameLen = nameLen + 1;
        namePtr = (uint8_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(namePtr) + 2)),
                                      (uint8_t *)namePtr + 1);
      }
      (&nameBuf)[nameLen] = 0x0;
      ovr_blitText((char *)&nameBuf,(byte *)CONCAT22(Font03.ofs,_SS),Font03.seg,0xde,0xde,8);
      TextBlitX = 0xc2;
      if (*namePtr == 0x40) {
        namePtr = (uint8_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(namePtr) + 2)),
                                      (uint8_t *)namePtr + 1);
      }
      ovr_blitText((char *)(uint8_t *)namePtr,
                   (byte *)CONCAT22(Font03.ofs,
                                    (*(uint16_t *)((uint8_t *)&(namePtr) + 2))),
                   Font03.seg,0xde,0xde,8);
    }
  }
  _fmemset(MK_FP(_SS, menuItems), 0, 0x28);
  menuItems[7].ofs = (uint16_t)s_done;        /* 0x6AB4 */
  menuItems[7].seg = (uint16_t)_DS;
  ovr_uiMenu(0, 0, (uint16_t)menuItems, (uint16_t)_SS, 8);
  ovc38_usesStshFree(block);
  ovr_saveui_blitPanel();
  return;
}


/* 68ac:0339 */

/* [R7] body shape: scan */

int16_t __cdecl16far ovc38_scan1(char *s1,char *s2)

{
  char cVar1;
  byte bVar4;
  int16_t iVar2;
  uint uVar3;
  uint uVar5;
  
  bVar4 = (byte)(((uint)(char *)s2 | (*(uint16_t *)((uint8_t *)&(s2) + 2))) >> 8);
  if (((uint)(char *)s2 | (*(uint16_t *)((uint8_t *)&(s2) + 2))) == 0) {
    iVar2 = 0;
  }
  else if ((byte)*s1 < (byte)*s2) {
    iVar2 = CONCAT11(bVar4,1);
  }
  else if ((byte)*s2 < (byte)*s1) {
    iVar2 = (uint)bVar4 << 8;
  }
  else {
    while ((*s2 != '\0' && (*s2 != '@'))) {
      s2 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(s2) + 2)),(char *)s2 + 1);
    }
    if (*s2 == '@') {
      s2 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(s2) + 2)),(char *)s2 + 1);
    }
    uVar3 = (uint)*s2;
    uVar5 = 0;
    if ((((byte *)_ctype + 1)[uVar3] & 2) != 0) {
      cVar1 = *s2;
      s2 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(s2) + 2)),(char *)s2 + 1);
      uVar3 = (uint)*s2;
      uVar5 = (int)cVar1 - 0x30U;
      if ((((byte *)_ctype + 1)[uVar3] & 2) != 0) {
        uVar3 = (((int)cVar1 - 0x30U) * 10 + (int)*s2) - 0x30;
        uVar5 = uVar3;
      }
    }
    bVar4 = (byte)(uVar3 >> 8);
    if (strongholdsDestroyed < uVar5) {
      iVar2 = CONCAT11(bVar4,1);
    }
    else {
      iVar2 = (uint)bVar4 << 8;
    }
  }
  return iVar2;
}



/* 68ac:03fc */
void __cdecl16far ovc38_usesStshAlloc(void)

{
  far_t entries;
  int16_t iVar1;
  size_t sVar2;
  void *pvVar3;
  uint16_t in_DX;
  uint16_t uVar4;
  int iVar5;
  uint16_t *puVar6;
  far_t handle;
  far_t entries_00;
  far_t handle_00;
  uint8_t msg;
  void *pvStack_8;
  uint16_t blkSeg;
  byte leaderIdx;
  
  if ((GHighScoreSaved == '\0') && (leaderIdx = ovr_manage_findFirstLeader(), leaderIdx != 0xff)) {
    pvStack_8 = ovr_stshAlloc(0x18);
    entries.seg = in_DX;
    entries.ofs = (uint16_t)pvStack_8;
    blkSeg = in_DX;
    ovc38_loadHighScores(entries);
    if (*(int *)((int)pvStack_8 + 0x14) != 0 || *(int *)((int)pvStack_8 + 0x16) != 0) {
      handle.seg = *(uint16_t *)((int)pvStack_8 + 0x16);
      handle.ofs = *(uint16_t *)((int)pvStack_8 + 0x14);
      ovr_stshFree(handle);
    }
    ovr_manage_playerTitle
              ((char_sheet_t *)*(uint16_t *)((uint)leaderIdx * 4),
               ((uint16_t *)((uint)leaderIdx * 4))[1],*(uint16_t *)((uint)leaderIdx * 4),
               ((uint16_t *)((uint)leaderIdx * 4))[1]);
    uVar4 = _DS;
    sprintf((char *)CONCAT22(_SS,&msg),"%c%s%s@%d");
    iVar5 = 5;
    while ((0 < iVar5 &&
           (iVar1 = ovc38_scan1((char *)CONCAT22(_SS,&msg),
                                (char *)CONCAT22(*(uint16_t *)((int)pvStack_8 + iVar5 * 4 + -2),
                                                 (char *)*(uint16_t *)
                                                          ((int)pvStack_8 + iVar5 * 4 + -4))),
           (char)iVar1 == '\0'))) {
      uVar4 = *(uint16_t *)((int)pvStack_8 + iVar5 * 4 + -4);
      puVar6 = (uint16_t *)((int)pvStack_8 + iVar5 * 4);
      puVar6[1] = *(uint16_t *)((int)pvStack_8 + iVar5 * 4 + -2);
      *puVar6 = uVar4;
      iVar5 = iVar5 + -1;
    }
    sVar2 = strlen((char *)CONCAT22(_SS,&msg));
    pvVar3 = ovr_stshAlloc((ulong)(sVar2 + 1));
    puVar6 = (uint16_t *)((int)pvStack_8 + iVar5 * 4);
    puVar6[1] = uVar4;
    *puVar6 = (uint16_t)pvVar3;   /* hand fix: 2-byte slot */
    puVar6 = (uint16_t *)((int)pvStack_8 + iVar5 * 4);
    strcpy((char *)CONCAT22(puVar6[1],(char *)*puVar6),(char *)CONCAT22(_SS,&msg));
    entries_00.seg = blkSeg;
    entries_00.ofs = (uint16_t)pvStack_8;
    ovc38_saveHighScores(entries_00);
    handle_00.seg = blkSeg;
    handle_00.ofs = (uint16_t)pvStack_8;
    ovc38_usesStshFree(handle_00);
    GHighScoreSaved = '\x01';
  }
  return;
}

